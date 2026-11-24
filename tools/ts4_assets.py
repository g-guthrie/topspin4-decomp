#!/usr/bin/env python3
"""Asset CLI for Top Spin 4: list archive contents, export venues and players to glTF 2.0 + PNG.

Commands (all read the user's own disc image; nothing is written outside --out):

  python3 tools/ts4_assets.py list    Amsterdam.arc [--iso ISO]
  python3 tools/ts4_assets.py venue   Amsterdam.arc --out work/assets/venue_Amsterdam
  python3 tools/ts4_assets.py player  Baked_Federer0.arc --out work/assets/player_Federer0
  python3 tools/ts4_assets.py textures Baked_Federer0.arc HUM_BODYX_XXXXX_00.xpr --out DIR

Coordinate conventions of the output (documented in docs/assets.md): the game data is left
handed, Y up, centimetres.  glTF output is right handed, Y up, metres: positions and normals have
z negated and are scaled by 0.01, triangle index order is kept (this turns the game's clockwise
front faces into glTF's counter-clockwise ones).  Players are additionally rotated from the mesh
frame into the Havok skeleton frame (x, y, z) -> (z, y, -x) before the z flip.

Standard library only.
"""
import argparse
import collections
import json
import math
import os
import re
import struct
import sys
import xml.etree.ElementTree as ET

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(HERE, "havok"))
import ts4_arc  # noqa: E402
import ts4_mesh as M  # noqa: E402
import ts4_texture as T  # noqa: E402

sys.setrecursionlimit(20000)
ROOT = os.path.dirname(HERE)
DEFAULT_ISO = os.path.join(ROOT, "orig", "54540859", "Top Spin 4 (World) (En,Fr,De,Es,It).iso")
SCALE = 0.01


# --------------------------------------------------------------------------- archive helpers

def iso_path(a):
    for p in (a.iso, os.environ.get("TS4_ISO"), DEFAULT_ISO):
        if p and os.path.exists(p):
            return p
    sys.exit("disc image not found: pass --iso or set TS4_ISO")


class Archive:
    """An .arc with name resolution and a per-directory view."""

    def __init__(self, name, iso):
        self.name = name
        self.arc = ts4_arc.open_arc(name if name.endswith(".arc") else name + ".arc", iso)
        self.by_key = {e[0]: e for e in self.arc.entries}
        self.dirs = collections.OrderedDict()   # dir hash -> {leaf name: entry}
        for dh, names in self.arc.directories:
            d = self.dirs.setdefault(dh, {})
            for n in names:
                k = ts4_arc.child_hash(dh, n)
                if k in self.by_key:
                    d[n] = self.by_key[k]
        self._cache = {}

    def leaf(self, entry):
        ln = self.arc.leaf_names.get(entry[0])
        return ln[1] if ln else None

    def read(self, entry):
        k = entry[0]
        if k not in self._cache:
            self._cache[k] = self.arc.read(entry)
        return self._cache[k]

    def find_name(self, name):
        for e in self.arc.entries:
            ln = self.arc.leaf_names.get(e[0])
            if ln and ln[1] == name:
                return e
        return None


def classify(head):
    sig = head[:8]
    if head[:4] == b"XPR2":
        return "xpr2-textures"
    if sig == b"PAM-XDT\0":
        return "xdt"
    if head[:1] == b"<":
        return "xml"
    if head[:4] == b"\x1bLua":
        return "lua"
    if head[:4] == bytes.fromhex("57e0e057"):
        return "havok"
    if head[:3] == b"FSB" or head[:3] == b"FEV":
        return "fmod"
    if head[:4] == b"BIKi":
        return "bink"
    if len(head) >= 8:
        a, b = struct.unpack_from(">II", head, 0)
        names = {
            (0x3F65F116): "packed-meshes" if a in (0x7D72A97D, 0x6912B1B8) else "xbin",
            (0x330FAC24): "mesh" if a == 0xA4B9371D else "xbin",
            (0x2E4F521C): "packed-materials",
            (0x929C8457): "cloth",
        }
        if b in names:
            return names[b]
        if a == 0xECC4F93B:
            return "packed-materials"
        if a == 0x929C8457:
            return "cloth"
        if a in (0x102A1100, 0x102A1101):
            return "shader"
        if a < 0x1000:
            return "ui-data"              # .anims / .actions / .abc style files starting with small integers
        return "xbin:%08x" % a
    return "?"


def cmd_list(a):
    ar = Archive(a.arc, iso_path(a))
    print("# %s: %d entries" % (a.arc, len(ar.arc.entries)))
    counts = collections.Counter()
    rows = []
    for dh, files in ar.dirs.items():
        pass
    for e in ar.arc.entries:
        try:
            blob = ar.arc.raw(e)
            head = ts4_arc.peek_blob(blob, 16)
        except Exception:
            head = b""
        kind = classify(head)
        ln = ar.leaf(e)
        counts[kind] += 1
        rows.append((ln or "", e[0], e[2], kind))
    if not a.summary:
        for ln, k, size, kind in sorted(rows):
            print("%08x %9d %-16s %s" % (k, size, kind, ln))
    print("# kinds:", dict(counts))
    print("# scene directories (hash: members with Packed*/Textures/Hierarchy):")
    for dh, files in ar.dirs.items():
        if any(n.startswith(("PackedMeshes", "Textures.xpr", "Hierarchy")) for n in files):
            print("  %08x %s" % (dh, ", ".join("%s(%d)" % (n, files[n][2]) for n in sorted(files)
                                              if not n.endswith((".pso", ".vso")))))


# --------------------------------------------------------------------------- hierarchy (XDT or XML)

def parse_hierarchy(data):
    if data[:8] == b"PAM-XDT\0":
        return M.parse_xdt(data)
    root = ET.fromstring(data.decode("latin-1"))

    def conv(e):
        n = M.XdtNode(e.tag)
        for k, v in e.attrib.items():
            try:
                n.attrs[k] = float(v) if k in ("X", "Y", "Z") else v
            except ValueError:
                n.attrs[k] = v
        n.children = [conv(c) for c in e]
        return n
    return conv(root)


# --------------------------------------------------------------------------- glTF writer

class Gltf:
    def __init__(self, out, name):
        self.out = out
        self.name = name
        self.buf = bytearray()
        self.views, self.accessors = [], []
        self.nodes, self.meshes, self.materials = [], [], []
        self.images, self.textures, self.skins = [], [], []
        self.samplers = [{"magFilter": 9729, "minFilter": 9987, "wrapS": 10497, "wrapT": 10497}]
        self.scene_nodes = []
        self._img = {}
        os.makedirs(os.path.join(out, "textures"), exist_ok=True)

    def _view(self, data, target=None):
        while len(self.buf) % 4:
            self.buf.append(0)
        off = len(self.buf)
        self.buf += data
        v = {"buffer": 0, "byteOffset": off, "byteLength": len(data)}
        if target:
            v["target"] = target
        self.views.append(v)
        return len(self.views) - 1

    def accessor(self, values, comp, typ, count, target=None, minmax=False):
        fmt = {5126: "f", 5123: "H", 5125: "I", 5121: "B"}[comp]
        data = struct.pack("<%d%s" % (len(values), fmt), *values)
        acc = {"bufferView": self._view(data, target), "componentType": comp, "count": count, "type": typ}
        if minmax:
            n = len(values) // count
            acc["min"] = [min(values[i::n]) for i in range(n)]
            acc["max"] = [max(values[i::n]) for i in range(n)]
        self.accessors.append(acc)
        return len(self.accessors) - 1

    def image(self, key, rgba, w, h):
        """Register a decoded texture once; returns the glTF texture index."""
        if key in self._img:
            return self._img[key]
        fname = re.sub(r"[^A-Za-z0-9_.-]", "_", key) + ".png"
        T.write_png(os.path.join(self.out, "textures", fname), rgba, w, h)
        self.images.append({"uri": "textures/" + fname, "name": key})
        self.textures.append({"sampler": 0, "source": len(self.images) - 1, "name": key})
        self._img[key] = len(self.textures) - 1
        return self._img[key]

    def material(self, name, tex_index=None, alpha=False, extras=None):
        m = {"name": name, "pbrMetallicRoughness": {"metallicFactor": 0.0, "roughnessFactor": 1.0}}
        if tex_index is not None:
            m["pbrMetallicRoughness"]["baseColorTexture"] = {"index": tex_index}
        else:
            m["pbrMetallicRoughness"]["baseColorFactor"] = [0.6, 0.6, 0.6, 1.0]
        if alpha:
            m["alphaMode"] = "MASK"
            m["alphaCutoff"] = 0.5
        m["doubleSided"] = True
        if extras:
            m["extras"] = extras
        self.materials.append(m)
        return len(self.materials) - 1

    def primitive(self, pos, nrm, uv0, uv1, tris, mat, joints=None, weights=None):
        attrs = {}
        flat = [c for p in pos for c in p]
        attrs["POSITION"] = self.accessor(flat, 5126, "VEC3", len(pos), 34962, True)
        if nrm:
            attrs["NORMAL"] = self.accessor([c for p in nrm for c in p], 5126, "VEC3", len(nrm), 34962)
        if uv0:
            attrs["TEXCOORD_0"] = self.accessor([c for p in uv0 for c in p], 5126, "VEC2", len(uv0), 34962)
        if uv1:
            attrs["TEXCOORD_1"] = self.accessor([c for p in uv1 for c in p], 5126, "VEC2", len(uv1), 34962)
        if joints:
            attrs["JOINTS_0"] = self.accessor([c for p in joints for c in p], 5123, "VEC4", len(joints), 34962)
            attrs["WEIGHTS_0"] = self.accessor([c for p in weights for c in p], 5126, "VEC4", len(weights), 34962)
        idx = [i for t in tris for i in t]
        prim = {"attributes": attrs, "mode": 4, "material": mat}
        prim["indices"] = self.accessor(idx, 5125, "SCALAR", len(idx), 34963)
        return prim

    def add_mesh(self, name, prims):
        self.meshes.append({"name": name, "primitives": prims})
        return len(self.meshes) - 1

    def add_node(self, node):
        self.nodes.append(node)
        return len(self.nodes) - 1

    def save(self, fname, extras=None):
        g = {"asset": {"version": "2.0", "generator": "topspin4 tools/ts4_assets.py"},
             "scene": 0, "scenes": [{"name": self.name, "nodes": self.scene_nodes}],
             "nodes": self.nodes, "meshes": self.meshes, "materials": self.materials,
             "accessors": self.accessors, "bufferViews": self.views,
             "buffers": [{"uri": fname + ".bin", "byteLength": len(self.buf)}]}
        if self.images:
            g["images"], g["textures"], g["samplers"] = self.images, self.textures, self.samplers
        if self.skins:
            g["skins"] = self.skins
        if extras:
            g["extras"] = extras
        with open(os.path.join(self.out, fname + ".bin"), "wb") as f:
            f.write(self.buf)
        with open(os.path.join(self.out, fname + ".gltf"), "w") as f:
            json.dump(g, f, indent=1)
        return os.path.join(self.out, fname + ".gltf")


# --------------------------------------------------------------------------- texture index

class TextureIndex:
    """name -> (xpr bytes, Texture) over several XPR2 files; decodes lazily and caches."""

    def __init__(self):
        self.tex = {}
        self.cache = {}

    def add_xpr(self, buf):
        texs, _ = T.parse_xpr2(buf)
        for t in texs:
            self.tex.setdefault(t.name, (buf, t))

    def resolve(self, name):
        """Exact name, then with ``_PlayerNN`` removed, then unique prefix match."""
        if not name:
            return None
        cands = [name, re.sub(r"_Player\d+$", "", name)]
        for c in cands:
            if c in self.tex:
                return c
        base = cands[-1]
        pre = [n for n in self.tex if n.startswith(base)]
        return sorted(pre)[0] if pre else None

    def decode(self, name):
        if name not in self.cache:
            buf, t = self.tex[name]
            rgba = T.decode_texture(t, buf)
            if t.format == T.K_CTX1 or t.format == T.K_DXN:
                rgba = T.reconstruct_normal_map(rgba, t.width, t.height)
            self.cache[name] = (rgba, t.width, t.height, t.format_name)
        return self.cache[name]


def has_alpha(rgba):
    return any(rgba[i] < 250 for i in range(3, len(rgba), 4 * 17))


def unit(v):
    l = math.sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2])
    return (v[0] / l, v[1] / l, v[2] / l) if l > 1e-9 else (0.0, 1.0, 0.0)


def mirror_z(p):
    return (p[0], p[1], -p[2])


def mesh_prims(g, mesh, mats, texidx, matinfo, xf, groups=None, skin_map=None, mat_cache=None):
    """Build glTF primitives for the groups of ``mesh`` (``xf`` maps a mesh position/normal)."""
    pos = [tuple(c * SCALE for c in xf(p)) for p in mesh.attrs["position"]]
    nrm = [unit(xf(n)) for n in mesh.attrs["normal"]] if "normal" in mesh.attrs else None
    uv0 = [tuple(u) for u in mesh.attrs.get("uv0", [])] or None
    uv1 = [tuple(u) for u in mesh.attrs.get("uv1", [])] or None
    joints = weights = None
    if skin_map is not None and "weights" in mesh.attrs:
        joints, weights = [], []
        for w, ix in zip(mesh.attrs["weights"], mesh.attrs["indices"]):
            pairs = [(w[i], skin_map[ix[3 - i]]) for i in range(4) if w[i] > 0]
            pairs.sort(reverse=True)
            tot = sum(p[0] for p in pairs) or 1.0
            pairs = pairs[:4] + [(0.0, 0)] * (4 - len(pairs))
            joints.append(tuple(p[1] for p in pairs))
            weights.append(tuple(p[0] / tot for p in pairs))
    prims = []
    for gi, grp in (groups or list(enumerate(mesh.groups))):
        tris = grp.triangles()
        if not tris:
            continue
        used = sorted({i for t in tris for i in t})
        remap = {o: n for n, o in enumerate(used)}
        sub = lambda arr: [arr[i] for i in used] if arr else None  # noqa: E731
        mat = matinfo(gi)
        prims.append(g.primitive(sub(pos), sub(nrm), sub(uv0), sub(uv1),
                                 [(remap[a], remap[b], remap[c]) for a, b, c in tris], mat,
                                 sub(joints), sub(weights)))
    return prims


# --------------------------------------------------------------------------- venue export

def pick_scene_dir(ar, want=None):
    best = None
    for dh, files in ar.dirs.items():
        if "PackedMeshes.xbin" not in files:
            continue
        if want is not None and dh == want:
            return dh
        size = files["PackedMeshes.xbin"][2]
        if best is None or size > best[0]:
            best = (size, dh)
    if want is not None:
        sys.exit("directory %08x has no PackedMeshes.xbin" % want)
    return best[1]


SKIP_VENUE = re.compile(r"(Dummy|Volumetric|Shadows_|^Sun|UI\d*$|^Black$)", re.I)


def export_venue(ar, out, dir_hash=None, include_all=False):
    dh = pick_scene_dir(ar, dir_hash)
    files = ar.dirs[dh]
    print("scene directory %08x: %s" % (dh, sorted(n for n in files if not n.endswith((".pso", ".vso")))))
    meshes = ar.read(files["PackedMeshes.xbin"])
    hier = parse_hierarchy(ar.read(files["Hierarchy.xml"] if "Hierarchy.xml" in files else files["Hierarchy.xdt"]))
    mats = M.parse_packed_materials(ar.read(files["PackedMaterials.bin"]))
    matmap = {m.name: m for m in mats}
    texidx = TextureIndex()
    if "Textures.xpr" in files:
        texidx.add_xpr(ar.read(files["Textures.xpr"]))
    g = Gltf(out, ar.name.replace(".arc", ""))
    mesh_by_name = {}
    for s in M.mesh_records(meshes):
        m = M.parse_mesh(meshes, s)
        mesh_by_name[m.name] = m
    gl_mesh = {}
    stats = collections.Counter()
    mat_cache = {}

    def material_for(mat_name, gi):
        m = matmap.get(mat_name)
        sm = m.for_group(gi) if m else None
        key = (sm.name if sm else mat_name, mat_name, gi if m and m.subs else -1)
        if key in mat_cache:
            return mat_cache[key]
        tex_i = None
        alpha = False
        extras = {}
        if sm:
            for slot, tname in sm.textures:
                r = texidx.resolve(tname) if tname else None
                if r:
                    extras[slot] = r
            diff = extras.get("DiffuseMap")
            if diff:
                rgba, w, h, fmt = texidx.decode(diff)
                tex_i = g.image(diff, rgba, w, h)
                alpha = has_alpha(rgba)
                stats["textures_used"] += 1
        i = g.material(sm.name if sm and sm.name else mat_name, tex_i, alpha, extras or None)
        mat_cache[key] = i
        return i

    mirror = [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1]
    for node, world in M.hierarchy_world_matrices(hier):
        if node.name != "Geometry":
            continue
        mname = node.attrs.get("Mesh")
        mesh = mesh_by_name.get(mname)
        if mesh is None:
            stats["geometry_without_mesh"] += 1
            continue
        if not include_all and SKIP_VENUE.search(mname):
            stats["skipped_helper"] += 1
            continue
        if mname not in gl_mesh:
            matname = node.attrs.get("Material")
            prims = mesh_prims(g, mesh, mats, texidx, lambda gi, mn=matname: material_for(mn, gi),
                               mirror_z, [(i, gr) for i, gr in enumerate(mesh.groups)])
            gl_mesh[mname] = g.add_mesh(mname, prims) if prims else None
            stats["meshes"] += 1
        if gl_mesh[mname] is None:
            continue
        a2 = M.mat4_mul(M.mat4_mul(mirror, world), mirror)
        a2[12], a2[13], a2[14] = a2[12] * SCALE, a2[13] * SCALE, a2[14] * SCALE
        ni = g.add_node({"name": node.attrs.get("Name", mname), "mesh": gl_mesh[mname], "matrix": a2})
        g.scene_nodes.append(ni)
        stats["nodes"] += 1
    path = g.save("venue", {"source": ar.name, "directory": "%08x" % dh, "stats": dict(stats)})
    print("wrote", path, dict(stats), "textures", len(g.images))
    return path


# --------------------------------------------------------------------------- player export

def load_skeleton(a, ar_iso):
    """Return the 71-bone player skeleton (Core.arc 6932352f skeleton 0, the gameplay skeleton).

    ``--skeleton-hkx FILE`` overrides; ``--skeleton-source cutscene`` takes the skeleton of
    CutScenes.arc entry 0026b42b instead.  The decompressed Core entry (34 MB) is cached under
    work/assets/cache/.
    """
    import packfile
    import classes
    import skeleton
    import xdvdfs
    import scan_arcs
    if a.skeleton_hkx:
        data = open(a.skeleton_hkx, "rb").read()
    elif a.skeleton_source == "cutscene":
        x = xdvdfs.XDVDFS(ar_iso)
        arc = scan_arcs.NilArc(x.open_slice("CutScenes.arc"))
        data = None
        for e in arc.entries:
            if e[0] == 0x0026B42B:
                arc.f.seek(arc.data_start + e[1])
                data = arc.f.read(e[2])
        if data is None:
            sys.exit("cutscene skeleton entry not found")
    else:
        cache = os.path.join(ROOT, "work", "assets", "cache", "core_6932352f.hkx")
        if os.path.exists(cache):
            data = open(cache, "rb").read()
        else:
            core = ts4_arc.open_arc("Core.arc", ar_iso)
            data = core.read(core.find(0x6932352F))
            os.makedirs(os.path.dirname(cache), exist_ok=True)
            with open(cache, "wb") as f:
                f.write(data)
    pf = packfile.Packfile(data)
    try:
        reg = classes.Registry.from_packfile(pf)
    except classes.MissingClasses as ex:
        sys.exit(str(ex))
    return skeleton.load(pf, reg)[0][getattr(a, 'skeleton_index', 0)]


def export_player(ar, out, a, iso):
    import skeleton as SK
    sk = load_skeleton(a, iso)
    g = Gltf(out, ar.name.replace(".arc", ""))
    # skeleton nodes (right handed: z negated, metres)
    for i, bone in enumerate(sk.bones):
        t, r, s = sk.ref[i]
        node = {"name": bone,
                "translation": [t[0] * SCALE, t[1] * SCALE, -t[2] * SCALE],
                "rotation": list(SK.quat_normalize([-r[0], -r[1], r[2], r[3]])),
                "scale": list(s)}
        kids = [j for j, p in enumerate(sk.parents) if p == i]
        if kids:
            node["children"] = kids
        g.add_node(node)
    roots = [i for i, p in enumerate(sk.parents) if p < 0]
    pose = [([t[0] * SCALE, t[1] * SCALE, -t[2] * SCALE], SK.quat_normalize([-r[0], -r[1], r[2], r[3]]), s)
            for t, r, s in sk.ref]
    world = sk.world_matrices(pose)
    ibm = []
    for w in world:
        ibm += SK.mat_inverse_affine(w)
    ibm_acc = g.accessor(ibm, 5126, "MAT4", len(world))
    g.skins.append({"name": "Skeleton71", "joints": list(range(len(sk.bones))), "skeleton": roots[0],
                    "inverseBindMatrices": ibm_acc})
    g.scene_nodes += roots

    texidx = TextureIndex()
    meshes, mat_files = [], {}
    for e in ar.arc.entries:
        ln = ar.leaf(e)
        if not ln:
            continue
        if ln.endswith(".xpr"):
            texidx.add_xpr(ar.read(e))
        elif ln.endswith("_000.xbin"):
            meshes.append((ln, e))
    # material trees from the xdt files
    xdts = []
    for e in ar.arc.entries:
        ln = ar.leaf(e)
        if ln and ln.endswith(".xdt") and ln != "Hierarchy.xdt":
            try:
                xdts.append(M.xdt_material(M.parse_xdt(ar.read(e))))
            except Exception:
                pass

    def find_material(mesh_name):
        for x in xdts:
            if x.name == mesh_name:
                return x
        for x in xdts:
            if any(s.name == mesh_name for s in x.subs):
                return x
        return None

    def frame(p):                                   # mesh frame -> skeleton frame -> glTF handedness
        return (p[2], p[1], p[0])

    def frame_skel(p):                              # mesh frame -> skeleton frame (centimetres)
        return (p[2], p[1], -p[0])
    world_cm = [(m[12], m[13], m[14]) for m in sk.world_matrices()]
    stats = collections.Counter()
    mat_cache = {}
    for ln, e in sorted(meshes):
        d = ar.read(e)
        if M.u32(d, 4) != 0x330FAC24:
            continue
        mesh = M.parse_mesh(d, 0x14)
        if not mesh.bones:
            continue
        fallback = sk.bones.index("B_Head")
        skin_map = [sk.bones.index(b) if b in sk.bones else fallback for b in mesh.bones]
        missing = [b for b in mesh.bones if b not in sk.bones]
        if missing:
            print("  %s: %d palette bones not in the skeleton (%s...) -> skinned to B_Head"
                  % (mesh.name, len(missing), missing[0]))
            stats["bones_remapped_to_head"] += len(missing)
        mx = find_material(mesh.name)
        lod_groups = pick_lod0(mesh)

        def matinfo(gi, mesh=mesh, mx=mx):
            grp = mesh.groups[gi]
            sm = pick_submaterial(mx, mesh, gi) if mx else None
            key = (mesh.name, sm.name if sm else None)
            if key in mat_cache:
                return mat_cache[key]
            tex_i, alpha, extras = None, False, {}
            if sm:
                for slot, tname in sm.textures:
                    r = texidx.resolve(tname)
                    if r:
                        extras[slot] = r
                diff = extras.get("DiffuseMap")
                if diff:
                    rgba, w, h, fmt = texidx.decode(diff)
                    tex_i = g.image(diff, rgba, w, h)
                    alpha = has_alpha(rgba)
            i = g.material((sm.name if sm else mesh.name) or mesh.name, tex_i, alpha, extras or None)
            mat_cache[key] = i
            return i
        attached = None
        if len(mesh.bones) == 1 and mesh.bones[0] in ("B_Racket_Handle", "B_Prop1", "B_Prop2"):
            attached = sk.bones.index(mesh.bones[0])      # racket / props are modelled bone-local
        if attached is not None:
            prims = mesh_prims(g, mesh, None, texidx, matinfo, mirror_z, lod_groups, None)
            mi = g.add_mesh(mesh.name, prims)
            ni = g.add_node({"name": mesh.name, "mesh": mi})
            g.nodes[attached].setdefault("children", []).append(ni)
            stats["attached_to_bone"] += 1
        else:
            prims = mesh_prims(g, mesh, None, texidx, matinfo, frame, lod_groups, skin_map)
            mi = g.add_mesh(mesh.name, prims)
            ni = g.add_node({"name": mesh.name, "mesh": mi, "skin": 0})
            g.scene_nodes.append(ni)
        stats["meshes"] += 1
        stats["vertices"] += mesh.vertex_count
        stats["groups"] += len(prims)
        print("  %-34s verts %5d groups %2d bones %2d material %s" % (mesh.name, mesh.vertex_count, len(prims),
                                                                     len(mesh.bones), mx.name if mx else None))
    path = g.save("player", {"source": ar.name, "stats": dict(stats)})
    print("wrote", path, dict(stats), "textures", len(g.images))
    return path


def pick_lod0(mesh):
    """Return [(group index, group)] of the highest-detail LOD.

    Groups are stored as N consecutive LOD sets of equal size; the set with the most indices
    is level 0 (the body mesh stores its LODs in the order mid, low, high).
    """
    n = len(mesh.groups)
    for nl in (3, 2, 4):
        if n % nl == 0 and n // nl >= 1 and nl > 1:
            k = n // nl
            sets = [list(range(i * k, (i + 1) * k)) for i in range(nl)]
            best = max(sets, key=lambda s: sum(len(mesh.groups[i].indices) for i in s))
            mesh.lod_size = k
            return [(i, mesh.groups[i]) for i in best]
    mesh.lod_size = n
    return list(enumerate(mesh.groups))


PART_TOKENS = {"CHEST": "CHEST", "ARMSX": "ARMSX", "LEGSX": "LEGSX", "PELVI": "LEGSX", "HANDS": "ARMSX"}


def pick_submaterial(mx, mesh, gi):
    subs = mx.subs
    grp = mesh.groups[gi]
    parts = grp.name.split("_")
    if len(parts) >= 2 and parts[1] in PART_TOKENS:
        want = PART_TOKENS[parts[1]]
        for s in subs:
            if "_" + want + "_" in s.name:
                return s
    n = len(subs)
    return subs[(gi % getattr(mesh, 'lod_size', n)) % n] if n else None


def cmd_textures(a):
    ar = Archive(a.arc, iso_path(a))
    e = ar.find_name(a.name)
    if e is None:
        sys.exit("no member %s" % a.name)
    buf = ar.read(e)
    os.makedirs(a.out, exist_ok=True)
    texs, others = T.parse_xpr2(buf)
    for t in texs:
        rgba = T.decode_texture(t, buf)
        T.write_png(os.path.join(a.out, t.name + ".png"), rgba, t.width, t.height)
        print("%-44s %4dx%-4d %s" % (t.name, t.width, t.height, t.format_name))


# --------------------------------------------------------------------------- structural check

def check_gltf(path, verbose=True):
    """Structural validation of an exported glTF: index ranges, UVs, normals, joints, PNGs, skin fit."""
    doc = json.load(open(path))
    base = os.path.dirname(path)
    binf = open(os.path.join(base, doc["buffers"][0]["uri"]), "rb").read()
    fmt = {5126: ("f", 4), 5123: ("H", 2), 5125: ("I", 4)}
    nc = {"SCALAR": 1, "VEC2": 2, "VEC3": 3, "VEC4": 4, "MAT4": 16}

    def acc(i):
        a = doc["accessors"][i]
        v = doc["bufferViews"][a["bufferView"]]
        f, sz = fmt[a["componentType"]]
        n = a["count"] * nc[a["type"]]
        vals = struct.unpack_from("<%d%s" % (n, f), binf, v["byteOffset"])
        k = nc[a["type"]]
        return [vals[j:j + k] for j in range(0, n, k)] if k > 1 else list(vals)

    rep = collections.OrderedDict()
    bad = collections.Counter()
    uvr = {"TEXCOORD_0": [1e9, -1e9], "TEXCOORD_1": [1e9, -1e9]}
    uv_in = collections.Counter()
    nlen = []
    tris = verts = 0
    njoints = len(doc["skins"][0]["joints"]) if doc.get("skins") else 0
    for m in doc["meshes"]:
        for p in m["primitives"]:
            at = p["attributes"]
            pos = acc(at["POSITION"])
            idx = acc(p["indices"])
            verts += len(pos)
            tris += len(idx) // 3
            if idx and (max(idx) >= len(pos) or min(idx) < 0):
                bad["index_out_of_range"] += 1
            if len(idx) % 3:
                bad["index_count_not_multiple_of_3"] += 1
            for k in ("TEXCOORD_0", "TEXCOORD_1"):
                if k in at:
                    for u in acc(at[k]):
                        uvr[k][0] = min(uvr[k][0], u[0], u[1])
                        uvr[k][1] = max(uvr[k][1], u[0], u[1])
                        uv_in[k + ("_inside" if -0.01 <= min(u) and max(u) <= 1.01 else "_outside")] += 1
            if "NORMAL" in at:
                for n_ in acc(at["NORMAL"])[::7]:
                    nlen.append(math.sqrt(sum(c * c for c in n_)))
            if "JOINTS_0" in at:
                for j, w in zip(acc(at["JOINTS_0"]), acc(at["WEIGHTS_0"])):
                    if max(j) >= njoints:
                        bad["joint_out_of_range"] += 1
                    if abs(sum(w) - 1) > 1e-3:
                        bad["weights_not_normalised"] += 1
    rep["meshes"], rep["vertices"], rep["triangles"] = len(doc["meshes"]), verts, tris
    rep["uv_range"] = {k: [round(v[0], 3), round(v[1], 3)] for k, v in uvr.items() if v[0] <= v[1]}
    rep["uv_vertices_inside_0_1"] = dict(uv_in)
    if nlen:
        rep["normal_length_min_max"] = [round(min(nlen), 4), round(max(nlen), 4)]
    rep["problems"] = dict(bad)
    # textures
    imgs = []
    for im in doc.get("images", []):
        w, h, ch, rows = T.read_png(open(os.path.join(base, im["uri"]), "rb").read())
        flat = b"".join(rows)
        step = max(1, len(flat) // 8192)
        sample = flat[::step]
        mean = sum(sample) / len(sample)
        var = sum((x - mean) ** 2 for x in sample) / len(sample)
        imgs.append((im["name"], w, h, ch, round(mean, 1), round(math.sqrt(var), 1)))
    rep["images"] = len(imgs)
    rep["images_flat"] = [i[0] for i in imgs if i[5] < 2.0]
    rep["image_dims"] = dict(collections.Counter("%dx%d" % (i[1], i[2]) for i in imgs))
    # skin fit: distance of each vertex to its dominant bone segment (metres)
    if njoints:
        import skeleton as SK
        nodes = doc["nodes"]
        local = [(n["translation"], n["rotation"], n["scale"]) for n in nodes[:njoints]]
        parents = [-1] * njoints
        for i, n in enumerate(nodes[:njoints]):
            for c in n.get("children", []):
                if c < njoints:
                    parents[c] = i
        wm = []
        for i, (t, r, s) in enumerate(local):
            mm = SK.trs_matrix(t, r, s)
            wm.append(SK.mat_mul(wm[parents[i]], mm) if parents[i] >= 0 else mm)
        org = [(m[12], m[13], m[14]) for m in wm]
        kid = {}
        for i, p in enumerate(parents):
            if p >= 0:
                kid.setdefault(p, i)
        ds = collections.defaultdict(list)
        for m in doc["meshes"]:
            for p in m["primitives"]:
                at = p["attributes"]
                if "JOINTS_0" not in at:
                    continue
                for v, j, w in zip(acc(at["POSITION"]), acc(at["JOINTS_0"]), acc(at["WEIGHTS_0"])):
                    b = j[max(range(4), key=lambda i: w[i])]
                    a0 = org[b]
                    a1 = org[kid[b]] if b in kid else a0
                    ab = [a1[i] - a0[i] for i in range(3)]
                    ap_ = [v[i] - a0[i] for i in range(3)]
                    den = sum(c * c for c in ab) or 1e-12
                    t = max(0.0, min(1.0, sum(ap_[i] * ab[i] for i in range(3)) / den))
                    d = math.sqrt(sum((ap_[i] - t * ab[i]) ** 2 for i in range(3)))
                    ds[m["name"]].append(d)
        allv = sorted(x for l in ds.values() for x in l)
        if allv:
            rep["skin_distance_to_bone_segment_m"] = {"median": round(allv[len(allv) // 2], 3),
                                                      "p95": round(allv[int(len(allv) * .95)], 3)}
            rep["skin_distance_by_mesh_median"] = {k: round(sorted(v)[len(v) // 2], 3) for k, v in ds.items()}
    if verbose:
        print(json.dumps(rep, indent=1))
    return rep, imgs



def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--iso", help="disc image (default $TS4_ISO or orig/54540859/*.iso)")
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("list")
    p.add_argument("arc")
    p.add_argument("--summary", action="store_true")
    p = sub.add_parser("venue")
    p.add_argument("arc")
    p.add_argument("--out", required=True)
    p.add_argument("--dir", help="scene directory hash (hex); default: the largest PackedMeshes directory")
    p.add_argument("--all", action="store_true", help="include helper meshes (shadows, dummies, UI)")
    p = sub.add_parser("player")
    p.add_argument("arc")
    p.add_argument("--out", required=True)
    p.add_argument("--skeleton-hkx", help="Havok packfile with the 71-bone skeleton")
    p.add_argument("--skeleton-source", choices=["core", "cutscene"], default="core")
    p.add_argument("--skeleton-index", type=int, default=0, help="which of the two Core skeletons (0 or 1)")
    p = sub.add_parser("check")
    p.add_argument("gltf")
    p = sub.add_parser("textures")
    p.add_argument("arc")
    p.add_argument("name")
    p.add_argument("--out", required=True)
    a = ap.parse_args(argv)
    if a.cmd == "check":
        check_gltf(a.gltf)
        return
    iso = iso_path(a)
    if a.cmd == "list":
        cmd_list(a)
    elif a.cmd == "venue":
        export_venue(Archive(a.arc, iso), a.out, int(a.dir, 16) if a.dir else None, a.all)
    elif a.cmd == "player":
        export_player(Archive(a.arc, iso), a.out, a, iso)
    elif a.cmd == "textures":
        cmd_textures(a)
    elif a.cmd == "check":
        check_gltf(a.gltf)


if __name__ == "__main__":
    main()
