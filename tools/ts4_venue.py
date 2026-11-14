#!/usr/bin/env python3
"""Top Spin 4 venues, courts and crowd ("TrackSide" engine): parsers and a glTF exporter.

Reads the user's own disc image in place and writes under --out (git-ignored work/ by default).
Formats are documented in docs/port/venues-and-crowd.md; this module is the reference reader.

  python3 tools/ts4_venue.py inventory [--iso ISO]                  # every venue archive + Desc record
  python3 tools/ts4_venue.py crowd Amsterdam.arc                    # crowd placement summary
  python3 tools/ts4_venue.py export Amsterdam.arc --out DIR         # venue + crowd + trackside to glTF/JSON
  python3 tools/ts4_venue.py trackside --out DIR                    # shared crowd skeleton, clips, behaviours

Formats decoded here (all big endian, XBin images with self-relative pointers, docs/assets.md 4):

* ``Crowd<Venue>.bin`` (signature f12cee6b, root type ec2064c3, not in Layoutall.bin): an octree of
  0x20-byte nodes {centre xyz, half size, children {rel,count,cap}, leaf cell (-1 = inner)} rooted at
  0x14, then the spectator array (0x54-byte records) and three {start, count} quality groups.
* ``PackedLights.bin`` (root 5dfe2627): list of 0x34-byte lights {name, type, used, user props,
  colour rgb, AmbientToShadowModulator, 4 floats, Multiplier}; placement is in the Hierarchy.
* ``TrackSideBehaviorList.bin``, ``TrackSideAnimationList.bin``, ``TrackSideSetupList.bin``: walked with
  the generic Layoutall walker (tools/ts4_xbin.py); the semantic layer (setup index -> behaviour list,
  composite In/Loop/Out sequences, HKXPath -> clip) is built by ``build_behaviours``.
* ``<Venue>Desc.bin`` (Global.arc): venue record (surface, indoor, capacity, weather, spectator models).

Coordinate conventions match tools/ts4_assets.py: game data is left handed, Y up, centimetres; glTF/JSON
output is right handed, Y up, metres (z negated, x0.01). Standard library only.
"""
import argparse
import collections
import hashlib
import json
import math
import os
import re
import struct
import sys
import zlib

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
for p in (HERE, os.path.join(HERE, "havok")):
    if p not in sys.path:
        sys.path.insert(0, p)

SCALE = 0.01
CROWD_SIG = (0xF12CEE6B, 0xEC2064C3)
CROWD_NODE = 0x20
CROWD_REC = 0x54
LIGHT_REC = 0x34
TRACKSIDE_HKX = 0x1539C50B           # TrackSide.hkx entry, identical in every venue archive
CORE_TS_SETUP = 0xD87CDC9C           # Core.arc TrackSideSetupList.bin
CORE_TS_ANIMLIST = 0xBE22E5C4        # Core.arc TrackSideAnimationList.bin
TS_BEHAVIOR_LIST = "TrackSideBehaviorList.bin"


def crc(s):
    return zlib.crc32(s.encode("latin-1")) & 0xFFFFFFFF


# Names recovered by hashing (zlib.crc32 of the exact string); see docs/port/venues-and-crowd.md 5.
KNOWN_NAMES = {crc(n): n for n in """
Hard Clay Grass Carpet Wood Indoor Outdoor IndoorHard IndoorClay IndoorCarpet
Idle Idle01 Idle02 Idle03 IdleNet Good Good2 Running Running2 Walk01 Watch1 Watch2 StandLookBack StandWatchBack
SitBase StandBase WalkBase JogBase FaultLeft FaultRight Player01 Player02 HKXPath
ApplauseLow ApplauseLowIn ApplauseLowLoop ApplauseLowOut ApplauseAverage ApplauseAverageIn ApplauseAverageLoop
ApplauseAverageOut ApplauseStrong ApplauseStrongIn ApplauseStrongLoop ApplauseStrongOut ApplauseWild ApplauseWildIn
ApplauseWildLoop ApplauseWildOut DeceptionLow DeceptionLowIn DeceptionAverage DeceptionAverageIn
Huge Medium Tiny Playground Small Big Large Man Woman FaultLeft2 FaultRight2 SitBase2
""".split()}
KNOWN_NAMES.update({crc("Idle%02d" % i): "Idle%02d" % i for i in range(30)})
KNOWN_NAMES.update({crc("Flourish_%02d_%02d" % (i, j)): "Flourish_%02d_%02d" % (i, j) for i in range(30) for j in range(6)})

# Setup index (TrackSideSetupList Animation member 3c330045) -> role.  The behaviour list root has one
# member list per index in this order (V: the member order of root type 5fe433ed matches the setup
# indices: LJ 0, BB 1, NET 2, UC 3, SE00..15 4..19, ST00..03 20..23, STANDARD 24).
SETUP_ROLES = (["line_judge", "ball_boy", "net", "umpire_chair"] + ["spectators"] * 16 + ["standing"] * 4
               + ["standard"])


# --------------------------------------------------------------------------------------------- helpers

def _u32(b, o):
    return struct.unpack_from(">I", b, o)[0]


def _s32(b, o):
    return struct.unpack_from(">i", b, o)[0]


def _f3(b, o):
    return list(struct.unpack_from(">3f", b, o))


def _cstr(b, o):
    e = b.index(b"\0", o)
    return b[o:e].decode("latin-1")


def _relstr(b, o):
    r = _s32(b, o)
    return None if r == -1 else _cstr(b, o + r)


def _desc(b, o):
    r, c, cap = struct.unpack_from(">iII", b, o)
    return (None if r == -1 else o + r), c, cap


SETUP_RE = re.compile(r'Animation\[@Name="([^"]+)"\]')


def setup_name(path):
    """'TrackSideSetupList:/SetupList/Animation[@Name="TS_SE13"]' -> 'TS_SE13' (or the input)."""
    m = SETUP_RE.search(path or "")
    return m.group(1) if m else path


# --------------------------------------------------------------------------------------------- crowd

def parse_crowd(buf):
    """Decode a Crowd<Venue>.bin image.

    Returns {"root": {...}, "nodes": n, "leaves": n, "spectators": [...], "groups": [(start, count)]}.
    Spectator fields (record offsets): +0x00 pos cm, +0x0C rot rad (Euler, only yaw used on disc),
    +0x18 scale, +0x24 -> model name, +0x28 -> hierarchy file, +0x2C/+0x30 atlas UV offset (0 or 0.5),
    +0x34 colour A, +0x40 colour B, +0x4C -> setup XBin path, +0x50 octree leaf cell.
    """
    a, b = struct.unpack_from(">II", buf, 0)
    if (a, b) != CROWD_SIG or buf[0x10:0x14] != b"\xff\xff\xff\xff":
        raise ValueError("not a crowd image (signature %08x %08x)" % (a, b))
    root = 0x14
    nodes = leaves = 0
    max_depth = 0
    stack = [(root, 0)]
    seen = set()
    while stack:
        o, depth = stack.pop()
        if o in seen or o + CROWD_NODE > len(buf):
            continue
        seen.add(o)
        nodes += 1
        max_depth = max(max_depth, depth)
        kids, n, _ = _desc(buf, o + 0x10)
        cell = _s32(buf, o + 0x1C)
        if cell >= 0:
            leaves += 1
        if kids is not None:
            for i in range(n):
                stack.append((kids + CROWD_NODE * i, depth + 1))
    sp, nsp, _ = _desc(buf, root + 0x20)
    gp, ngp, _ = _desc(buf, root + 0x2C)
    out = {
        "root": {"centre": _f3(buf, root), "half_size": struct.unpack_from(">f", buf, root + 0x0C)[0],
                 "leaf_count": _u32(buf, root + 0x38), "count_3c": _u32(buf, root + 0x3C)},
        "nodes": nodes, "leaves": leaves, "depth": max_depth, "spectators": [], "groups": [],
    }
    for i in range(nsp):
        o = sp + CROWD_REC * i
        out["spectators"].append({
            "pos": _f3(buf, o), "rot": _f3(buf, o + 0x0C), "scale": _f3(buf, o + 0x18),
            "model": _relstr(buf, o + 0x24), "file": _relstr(buf, o + 0x28),
            "uv": list(struct.unpack_from(">2f", buf, o + 0x2C)),
            "color_a": _f3(buf, o + 0x34), "color_b": _f3(buf, o + 0x40),
            "setup": setup_name(_relstr(buf, o + 0x4C)), "cell": _u32(buf, o + 0x50),
        })
    for i in range(ngp):
        out["groups"].append(struct.unpack_from(">II", buf, gp + 8 * i))
    return out


def crowd_quality(index, groups):
    """Quality tier of spectator ``index``: 0 = always drawn, 1 = medium and up, 2 = high only (I)."""
    for t, (start, count) in enumerate(groups):
        if start <= index < start + count:
            return t
    return len(groups)


def srp_matrix_gl(pos, rot, scale):
    """Column-major glTF matrix (metres, right handed) of a game SRP (cm, left handed).

    Same convention as tools/ts4_mesh.srp_row_matrix + the z-mirror conjugation of ts4_assets:
    row-vector world = S * Rz * Rx * Ry * T; output = M * world * M with M = diag(1, 1, -1, 1)."""
    import ts4_mesh as M
    w = M.srp_row_matrix(scale, rot, pos)
    mir = [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1]
    g = M.mat4_mul(M.mat4_mul(mir, w), mir)
    g[12], g[13], g[14] = g[12] * SCALE, g[13] * SCALE, g[14] * SCALE
    return g                     # row-major row-vector == column-major column-vector (glTF)


def crowd_instances(crowd, models=None, setups=None):
    """Compact instance table for the viewer (glTF frame).

    Each row: [model index, setup index, x, y, z (m), yaw (rad, glTF), sx, sy, sz, du, dv, rA, gA, bA,
    rB, gB, bB, quality tier].  ``models``/``setups`` lists are extended in first-seen order."""
    models = [] if models is None else models
    setups = [] if setups is None else setups
    rows = []
    for i, s in enumerate(crowd["spectators"]):
        if s["model"] not in models:
            models.append(s["model"])
        if s["setup"] not in setups:
            setups.append(s["setup"])
        p = s["pos"]
        rows.append([models.index(s["model"]), setups.index(s["setup"]),
                     round(p[0] * SCALE, 4), round(p[1] * SCALE, 4), round(-p[2] * SCALE, 4),
                     round(-s["rot"][1], 5)] + [round(v, 4) for v in s["scale"]]
                    + [round(v, 3) for v in s["uv"]] + [round(v, 4) for v in s["color_a"] + s["color_b"]]
                    + [crowd_quality(i, crowd["groups"])])
    return {"models": models, "setups": setups,
            "columns": ["model", "setup", "x", "y", "z", "yaw", "sx", "sy", "sz", "du", "dv",
                        "rA", "gA", "bA", "rB", "gB", "bB", "tier"],
            "rows": rows}


# --------------------------------------------------------------------------------------------- lights

def parse_packed_lights(buf):
    """PackedLights.bin -> [{name, type, used, color, ambient_to_shadow, params[4], multiplier, user[]}]."""
    if buf[0x10:0x14] != b"\xff\xff\xff\xff":
        raise ValueError("not an XBin image")
    lp, n, _ = _desc(buf, 0x14)
    out = []
    for i in range(n):
        o = lp + LIGHT_REC * i
        user = []
        up = _s32(buf, o + 0x0C)
        if up not in (-1, 0):
            # user property block: three floats seen on disc (LightCrowd: 1.4 1.4 1.4); meaning unknown
            user = list(struct.unpack_from(">3f", buf, o + 0x0C + up))
        out.append({
            "name": _relstr(buf, o), "type": _u32(buf, o + 4), "used": buf[o + 8] != 0,
            "color": _f3(buf, o + 0x10),
            "ambient_to_shadow": struct.unpack_from(">f", buf, o + 0x1C)[0],
            "params": list(struct.unpack_from(">4f", buf, o + 0x20)),
            "multiplier": struct.unpack_from(">f", buf, o + 0x30)[0],
            "user": user,
        })
    return out


# --------------------------------------------------------------------------------------------- court lines

ITF_LINES_M = {"baseline_x": 11.885, "service_x": 6.40, "singles_z": 4.115, "doubles_z": 5.485}
GAMEPLAY_BOUNDS_CM = {"rally_xmax": 1194.5, "serve_xmax": 646.0, "singles_zmax": 415.5, "doubles_zmax": 552.5,
                      "tolerance": 8.0, "source": "docs/gameplay/ball-physics.md s7 (fn_8866E318)"}


def court_line_edges(positions_m, tol=0.004):
    """Cluster |x| and |z| of court-line vertices (glTF metres) into edge values.

    Returns {"x": [...], "z": [...]} sorted ascending; a painted line of width w centred on c shows up as the
    two edges c - w/2 and c + w/2."""
    def cluster(vals):
        vals = sorted(vals)
        out, cur = [], []
        for v in vals:
            if cur and v - cur[-1] > tol:
                out.append((sum(cur) / len(cur), len(cur)))
                cur = []
            cur.append(v)
        if cur:
            out.append((sum(cur) / len(cur), len(cur)))
        return [round(c, 4) for c, n in out if n >= 2]
    return {"x": cluster([abs(p[0]) for p in positions_m]), "z": cluster([abs(p[2]) for p in positions_m])}


def court_line_check(edges):
    """Pair each ITF line with the nearest line (edge pair) and compare with the gameplay bounds."""
    res = {}
    for key, axis in (("baseline_x", "x"), ("service_x", "x"), ("singles_z", "z"), ("doubles_z", "z")):
        want = ITF_LINES_M[key]
        e = edges.get(axis, [])
        near = sorted(e, key=lambda v: abs(v - want))[:2]
        if len(near) < 2:
            res[key] = {"itf_m": want, "found": None}
            continue
        lo, hi = sorted(near)
        res[key] = {"itf_m": want, "inner_edge_m": lo, "outer_edge_m": hi, "centre_m": round((lo + hi) / 2, 4),
                    "width_cm": round((hi - lo) * 100, 2)}
    gb = GAMEPLAY_BOUNDS_CM
    if res.get("baseline_x", {}).get("found", 1) is not None and "outer_edge_m" in res.get("baseline_x", {}):
        res["baseline_x"]["gameplay_xmax_m"] = gb["rally_xmax"] / 100
    if "outer_edge_m" in res.get("service_x", {}):
        res["service_x"]["gameplay_xmax_m"] = gb["serve_xmax"] / 100
    if "outer_edge_m" in res.get("singles_z", {}):
        res["singles_z"]["gameplay_zmax_m"] = gb["singles_zmax"] / 100
    if "outer_edge_m" in res.get("doubles_z", {}):
        res["doubles_z"]["gameplay_zmax_m"] = gb["doubles_zmax"] / 100
    return res


# --------------------------------------------------------------------------------------------- behaviours

def build_behaviours(leaves, anim_keys, names=None):
    """Turn walker leaves of TrackSideBehaviorList.bin into a per-setup behaviour graph.

    ``leaves``: iterable of (path, tag, value) with paths such as
    '<list>/<behaviours>[3]/0d5661e8' (HKXPath key), '.../fe11d138' (Name), '.../05ef2079' (AnimID),
    '.../081ddbd2/<b>[i]/fe11d138' (start sequence) and '.../2452c65f/<b>[i]/fe11d138' (stop sequence).
    ``anim_keys``: TrackSideAnimationList keys; the clip index of a behaviour is the index of its HKXPath key.
    Returns [{"list": member hash, "setup_index": i, "role": str, "behaviours": [...]}] in member order."""
    names = names or {}

    def nm(h):
        return names.get(h) or KNOWN_NAMES.get(h) or "%08x" % h

    lists = collections.OrderedDict()
    pat = re.compile(r"^([0-9a-fA-F]{8}|[^/\[]+)/[^/\[]+\[(\d+)\]/(.*)$")
    for path, tag, value in leaves:
        m = pat.match(path)
        if not m:
            continue
        lst, idx, rest = m.group(1), int(m.group(2)), m.group(3)
        beh = lists.setdefault(lst, collections.OrderedDict()).setdefault(idx, {"start": {}, "stop": {}})
        sm = re.match(r"^([0-9a-fA-F]{8})/[^/\[]+\[(\d+)\]/(fe11d138|Name)$", rest)
        if rest in ("0d5661e8", "HKXPath"):
            beh["hkx"] = value
        elif rest in ("fe11d138", "Name"):
            beh["name"] = value
        elif rest in ("05ef2079", "AnimID"):
            beh["anim_id"] = value
        elif sm and sm.group(1).lower() in ("081ddbd2", "2452c65f"):
            seq = beh["start" if sm.group(1).lower() == "081ddbd2" else "stop"]
            seq[int(sm.group(2))] = value
    out = []
    key_index = {k: i for i, k in enumerate(anim_keys)}
    for si, (lst, behs) in enumerate(lists.items()):
        rows = []
        for idx in sorted(behs):
            b = behs[idx]
            h = b.get("hkx", 0)
            rows.append({"name": nm(b.get("name", 0)), "name_hash": "%08x" % b.get("name", 0),
                         "clip": key_index.get(h) if h else None,
                         "start": [nm(b["start"][k]) for k in sorted(b["start"])],
                         "stop": [nm(b["stop"][k]) for k in sorted(b["stop"])]})
        out.append({"list": lst, "setup_index": si,
                    "role": SETUP_ROLES[si] if si < len(SETUP_ROLES) else "other", "behaviours": rows})
    return out


def read_anim_list(buf):
    """TrackSideAnimationList.bin: root list of u32 keys (root descriptor at 0x14)."""
    p, n, _ = _desc(buf, 0x14)
    return list(struct.unpack_from(">%dI" % n, buf, p))


# --------------------------------------------------------------------------------------------- disc access

def iso_path(explicit=None):
    import glob
    for p in (explicit, os.environ.get("TS4_ISO")):
        if p and os.path.exists(p):
            return p
    for p in sorted(glob.glob(os.path.join(ROOT, "orig", "*", "*.iso")) +
                    glob.glob(os.path.join(ROOT, "orig", "*", "disc_archive", "*.iso"))):
        return p
    sys.exit("disc image not found: pass --iso or set TS4_ISO")


_LAYOUT = {}


def layout_and_names(iso):
    """Layoutall.bin (disc root) as a ts4_xbin.Layout plus the committed name table."""
    import ts4_xbin as X
    if iso not in _LAYOUT:
        import xdvdfs
        buf = xdvdfs.XDVDFS(iso).open_slice("Layoutall.bin").read()
        paths = [os.path.join(ROOT, "data", "gameplay", "names.yaml"),
                 os.path.join(ROOT, "work", "disc", "values", "names.json")]
        names = X.load_names(*[p for p in paths if os.path.exists(p)])
        names.update(KNOWN_NAMES)
        _LAYOUT[iso] = (X.Layout(buf), names, hashlib.sha256(buf).hexdigest())
    return _LAYOUT[iso]


def walk_leaves(buf, iso):
    import ts4_xbin as X
    lay, names, _ = layout_and_names(iso)
    w = X.Walker(buf, lay, names)
    return w.walk_file()


def parse_venue_desc(buf, iso):
    """Global.arc <Venue>Desc.bin -> dict of the decoded Venue[0] fields (generic walker)."""
    out = {"spectators": []}
    for lf in walk_leaves(buf, iso):
        m = re.match(r"^Venue\[0\]/(.*)$", lf.path)
        if not m:
            continue
        k = m.group(1)
        v = lf.value
        if isinstance(v, tuple):
            v = v[1]
        if k.startswith("SpectatorList/"):
            out["spectators"].append(v)
            continue
        if lf.tag == "key":
            v = KNOWN_NAMES.get(v, "%08x" % v)
        out[k] = v
    return out


def venue_archives(iso):
    """Names of the venue archives on the disc: every .arc that holds a Crowd*.bin or a TrackSide.hkx."""
    import ts4_arc
    import xdvdfs
    x = xdvdfs.XDVDFS(iso)
    out = []
    for name in sorted(n for n in x.list_names() if n.endswith(".arc")) if hasattr(x, "list_names") else []:
        out.append(name)
    return out, x


# --------------------------------------------------------------------------------------------- trackside export

def load_trackside(ar):
    """(skeletons, clip entries, packfile, registry, binding order) of the venue's TrackSide.hkx."""
    import classes
    import packfile
    import skeleton as SK
    pf = packfile.Packfile(ar.read(ar.by_key[TRACKSIDE_HKX]))
    reg = classes.Registry.from_packfile(pf)
    skels, anims = SK.load(pf, reg)
    # container binding order = TrackSideAnimationList order (I: same count, 384)
    order = []
    for s, o in pf.objects("hkaAnimationContainer"):
        c = reg.read_object(pf, s, o, "hkaAnimationContainer")
        for bref in c["bindings"]:
            b = bref.get() if hasattr(bref, "get") else bref
            loc = (b["animation"].sec, b["animation"].off) if b["animation"] is not None else None
            order.append(loc)
    by_loc = {e[0]: e for e in anims}
    entries = [by_loc.get(loc) for loc in order] if order else anims
    return skels, entries, pf, reg


def _mirror_q(q):
    return [-q[0], -q[1], q[2], q[3]]


class AnimGltf:
    """Thin wrapper over ts4_assets.Gltf that can also write animations."""

    def __init__(self, out, name):
        import ts4_assets as A
        self.g = A.Gltf(out, name)
        self.animations = []

    def save(self, fname, extras=None):
        path = self.g.save(fname, extras)
        if self.animations:
            with open(path) as f:
                doc = json.load(f)
            doc["animations"] = self.animations
            with open(path, "w") as f:
                json.dump(doc, f, indent=1)
        return path


def add_skeleton_nodes(g, sk):
    """Append the skeleton's joints (glTF frame) and a skin; returns (skin index, joint node indices)."""
    import skeleton as SK
    base = len(g.nodes)
    for i, bone in enumerate(sk.bones):
        t, r, s = sk.ref[i]
        node = {"name": bone, "translation": [t[0] * SCALE, t[1] * SCALE, -t[2] * SCALE],
                "rotation": list(SK.quat_normalize(_mirror_q(r))), "scale": list(s)}
        kids = [base + j for j, p in enumerate(sk.parents) if p == i]
        if kids:
            node["children"] = kids
        g.add_node(node)
    pose = [([t[0] * SCALE, t[1] * SCALE, -t[2] * SCALE], SK.quat_normalize(_mirror_q(r)), s)
            for t, r, s in sk.ref]
    ibm = []
    for w in sk.world_matrices(pose):
        ibm += SK.mat_inverse_affine(w)
    acc = g.accessor(ibm, 5126, "MAT4", len(sk.bones))
    roots = [base + i for i, p in enumerate(sk.parents) if p < 0]
    g.skins.append({"name": sk.name or "TrackSide", "joints": list(range(base, base + len(sk.bones))),
                    "skeleton": roots[0], "inverseBindMatrices": acc})
    return len(g.skins) - 1, roots


def add_clip_animation(ag, sk, clip, name, joint_base=0):
    """Write a decoded Havok clip as a glTF animation (z-mirrored, metres) on joints joint_base + bone."""
    import skeleton as SK
    g = ag.g
    n = len(clip.frames)
    times = [round(t, 5) for t in clip.times]
    tacc = g.accessor(times, 5126, "SCALAR", n, None, True)
    channels, samplers = [], []
    for b in range(len(sk.bones)):
        trs, rot = [], []
        for f in range(n):
            pose = clip.bone_pose(sk, f)
            t, r, _s = pose[b]
            trs += [t[0] * SCALE, t[1] * SCALE, -t[2] * SCALE]
            rot += list(SK.quat_normalize(_mirror_q(r)))
        for path, vals, typ in (("translation", trs, "VEC3"), ("rotation", rot, "VEC4")):
            acc = g.accessor(vals, 5126, typ, n)
            samplers.append({"input": tacc, "output": acc, "interpolation": "LINEAR"})
            channels.append({"sampler": len(samplers) - 1, "target": {"node": joint_base + b, "path": path}})
    ag.animations.append({"name": name, "channels": channels, "samplers": samplers})


def export_trackside_shared(ar, core, out, iso, clips="behaviours", log=print):
    """Shared crowd/officials/net skeletons, behaviour graph and clips (TrackSide.hkx is the same file in every
    venue archive; Core.arc holds the animation and setup lists)."""
    os.makedirs(out, exist_ok=True)
    skels, entries, _pf, _reg = load_trackside(ar)
    import skeleton as SK
    anim_buf = core.read(core.find(CORE_TS_ANIMLIST))
    keys = read_anim_list(anim_buf)
    beh_entry = ar.find_name(TS_BEHAVIOR_LIST)
    beh_buf = ar.read(beh_entry)
    leaves = [(lf.path, lf.tag, lf.value) for lf in walk_leaves(beh_buf, iso)]
    graph = build_behaviours(leaves, keys)
    # setups: TS_* name -> setup index (TrackSideSetupList member 3c330045)
    setup_buf = core.read(core.find(CORE_TS_SETUP))
    setups = {}
    cur = {}
    for lf in walk_leaves(setup_buf, iso):
        m = re.match(r"^[^/\[]+\[(\d+)\]/(.*)$", lf.path)
        if not m:
            continue
        i, k = int(m.group(1)), m.group(2)
        if k in ("fe11d138", "Name") and isinstance(lf.value, tuple):
            cur.setdefault(i, {})["name"] = lf.value[1]
        elif k == "3c330045":
            cur.setdefault(i, {})["index"] = lf.value
        elif k.endswith("74f7de1a") and "/" in k and k.split("/")[0] in ("d5f638d8", "BoneList"):
            cur.setdefault(i, {})["matrices"] = lf.value
    for i, v in cur.items():
        if "name" in v:
            setups[v["name"]] = {"index": v.get("index"), "matrices": v.get("matrices")}
    wanted = set()
    for lst in graph:
        for b in lst["behaviours"]:
            if b["clip"] is not None:
                wanted.add(b["clip"])
    if clips == "all":
        wanted = set(range(len(entries)))
    elif clips == "none":
        wanted = set()
    # one glTF per skeleton: humans (skeleton 1) and net (skeleton 0)
    net_clips = {b["clip"] for lst in graph if lst["role"] == "net" for b in lst["behaviours"] if b["clip"] is not None}
    files = {}
    clip_meta = []
    for si, label in ((1, "trackside_human"), (0, "trackside_net")):
        sk = skels[si]
        ag = AnimGltf(out, label)
        skin, roots = add_skeleton_nodes(ag.g, sk)
        ag.g.scene_nodes += roots
        for ci in sorted(wanted):
            if (ci in net_clips) != (si == 0):
                continue
            e = entries[ci]
            if e is None:
                continue
            clip = SK.load_clip(_pf, _reg, e, ci)
            add_clip_animation(ag, sk, clip, "clip%03d" % ci)
            clip_meta.append({"clip": ci, "skeleton": label, "duration": round(clip.duration, 4),
                              "frames": len(clip.frames), "key": "%08x" % keys[ci] if ci < len(keys) else None})
        files[label] = os.path.basename(ag.save(label, {"source": "TrackSide.hkx %08x skeleton %d" % (TRACKSIDE_HKX, si)}))
        log("trackside: wrote %s (%d clips)" % (label, len(ag.animations)))
    names_by_clip = collections.defaultdict(list)
    for lst in graph:
        for b in lst["behaviours"]:
            if b["clip"] is not None:
                names_by_clip[b["clip"]].append("%s:%s" % (lst["role"], b["name"]))
    for c in clip_meta:
        c["used_by"] = sorted(set(names_by_clip.get(c["clip"], [])))
    doc = {"skeletons": {"trackside_human": skels[1].bones, "trackside_net": skels[0].bones},
           "files": files, "setups": setups, "behaviour_lists": graph, "clips": clip_meta,
           "animation_keys": ["%08x" % k for k in keys],
           "source": {"behaviours": "%s %s" % (ar.name, TS_BEHAVIOR_LIST),
                      "behaviours_sha256": hashlib.sha256(beh_buf).hexdigest(),
                      "animation_list_sha256": hashlib.sha256(anim_buf).hexdigest(),
                      "setup_list_sha256": hashlib.sha256(setup_buf).hexdigest()}}
    with open(os.path.join(out, "trackside.json"), "w") as f:
        json.dump(doc, f, indent=1)
    return doc


def export_skinned_model(ar, mesh, out, name, sk, lod=0, material_for=None, texidx=None):
    """One skinned trackside model (spectator, official, ball boy, net) bound to ``sk`` (19 bones).

    The meshes are modelled in the skeleton's reference pose in the skeleton frame (V: mesh joint centroids
    match the reference pose within a few cm), so the inverse bind matrices are the inverse reference-pose
    world matrices.  Bone index bytes are reversed relative to the weights (docs/assets.md 4)."""
    import ts4_assets as A
    ag = AnimGltf(out, name)
    g = ag.g
    skin, roots = add_skeleton_nodes(g, sk)
    skin_map = [sk.bones.index(b) if b in sk.bones else 0 for b in mesh.bones]
    groups = list(enumerate(mesh.groups))
    lod = max(0, min(lod, len(groups) - 1))
    prims = A.mesh_prims(g, mesh, None, texidx, (lambda gi: material_for(g, gi)) if material_for else (lambda gi: g.material(name)),
                         A.mirror_z, [groups[lod]], skin_map=skin_map)
    mi = g.add_mesh(name, prims)
    ni = g.add_node({"name": name, "mesh": mi, "skin": skin})
    g.scene_nodes += roots + [ni]
    return ag.save(name, {"lod": lod, "lods": len(groups), "vertices": mesh.vertex_count})


# --------------------------------------------------------------------------------------------- venue export

SKIP_STATIC = re.compile(r"(Dummy|Volumetric|Shadows_|^Sun|UI\d*$|^Black$)", re.I)


def hierarchy_extras(hier):
    """Lights, light targets, cameras and trackside placements of a scene hierarchy (glTF frame)."""
    import ts4_mesh as M
    lights, targets, trackside = [], [], []
    mir = [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1]
    for node, world in M.hierarchy_world_matrices(hier):
        if node.find("SRP") is None:
            continue
        g = M.mat4_mul(M.mat4_mul(mir, world), mir)
        pos = [g[12] * SCALE, g[13] * SCALE, g[14] * SCALE]
        if node.name in ("Light", "LightTarget"):
            (lights if node.name == "Light" else targets).append({"name": node.attrs.get("Name"), "pos": [round(v, 4) for v in pos],
                                                                  "dir": [round(-g[8], 4), round(-g[9], 4), round(-g[10], 4)]})
        if node.name == "Geometry":
            up = node.find("UserProperties")
            if up is None:
                continue
            path = next((v for v in up.attrs.values() if isinstance(v, str) and "TrackSideSetupList" in v), None)
            if not path:
                continue
            extra = sorted(v for k, v in up.attrs.items() if isinstance(v, str) and re.match(r"^(Idle|Flourish)", v))
            g2 = [round(v, 5) for v in g]
            g2[12], g2[13], g2[14] = [round(v, 4) for v in pos]
            trackside.append({"name": node.attrs.get("Name"), "mesh": node.attrs.get("Mesh"),
                              "material": node.attrs.get("Material"), "setup": setup_name(path),
                              "behaviours": extra, "matrix": g2})
    return lights, targets, trackside


def export_venue(ar, out, iso, dir_hash=None, include_all=False, crowd_lod=2, official_lod=0, log=print):
    """Export one venue archive to ``out``: venue.gltf (static scene, skinned trackside meshes removed),
    trackside/*.gltf (skinned models), crowd.json (instances), venue.json (desc, lights, placements, court check)."""
    import ts4_assets as A
    import ts4_mesh as M
    os.makedirs(out, exist_ok=True)
    dh = A.pick_scene_dir(ar, dir_hash)
    files = ar.dirs[dh]
    hier_e = files.get("Hierarchy.xml") or files.get("Hierarchy.xdt")
    hier = A.parse_hierarchy(ar.read(hier_e))
    meshes_buf = ar.read(files["PackedMeshes.xbin"])
    mats = M.parse_packed_materials(ar.read(files["PackedMaterials.bin"]))
    matmap = {m.name: m for m in mats}
    texidx = A.TextureIndex()
    if "Textures.xpr" in files:
        texidx.add_xpr(ar.read(files["Textures.xpr"]))
    mesh_by_name = {}
    for s in M.mesh_records(meshes_buf):
        m = M.parse_mesh(meshes_buf, s)
        mesh_by_name[m.name] = m
    g = A.Gltf(out, ar.name.replace(".arc", ""))
    stats = collections.Counter()
    mat_cache = {}

    def material_for(gl, mat_name, gi, tex=texidx, mm=matmap, cache=mat_cache):
        m = mm.get(mat_name)
        sm = m.for_group(gi) if m else None
        key = (id(gl), sm.name if sm else mat_name, mat_name, gi if m and m.subs else -1)
        if key in cache:
            return cache[key]
        tex_i, alpha, extras = None, False, {}
        if sm:
            for slot, tname in sm.textures:
                r = tex.resolve(tname) if tname else None
                if r:
                    extras[slot] = r
            diff = extras.get("DiffuseMap")
            if diff:
                rgba, w, h, _fmt = tex.decode(diff)
                tex_i = gl.image(diff, rgba, w, h)
                alpha = A.has_alpha(rgba)
        i = gl.material(sm.name if sm and sm.name else mat_name, tex_i, alpha, extras or None)
        cache[key] = i
        return i

    mirror = [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1]
    gl_mesh = {}
    line_pos = []
    skinned_nodes = []
    for node, world in M.hierarchy_world_matrices(hier):
        if node.name != "Geometry":
            continue
        mname = node.attrs.get("Mesh")
        mesh = mesh_by_name.get(mname)
        if mesh is None:
            stats["geometry_without_mesh"] += 1
            continue
        if "weights" in mesh.attrs:
            skinned_nodes.append(node.attrs.get("Name"))
            stats["skinned_moved_to_trackside"] += 1
            continue
        if not include_all and SKIP_STATIC.search(mname):
            stats["skipped_helper"] += 1
            continue
        a2 = M.mat4_mul(M.mat4_mul(mirror, world), mirror)
        a2[12], a2[13], a2[14] = a2[12] * SCALE, a2[13] * SCALE, a2[14] * SCALE
        if re.match(r"^GroundLines", mname or "", re.I):
            for p in mesh.attrs["position"]:
                q = [p[0] * a2[0] + p[1] * a2[4] + -p[2] * a2[8], p[0] * a2[1] + p[1] * a2[5] + -p[2] * a2[9],
                     p[0] * a2[2] + p[1] * a2[6] + -p[2] * a2[10]]
                line_pos.append((q[0] * SCALE + a2[12], q[1] * SCALE + a2[13], q[2] * SCALE + a2[14]))
        if mname not in gl_mesh:
            matname = node.attrs.get("Material")
            prims = A.mesh_prims(g, mesh, mats, texidx, lambda gi, mn=matname: material_for(g, mn, gi),
                                 A.mirror_z, [(i, gr) for i, gr in enumerate(mesh.groups)])
            gl_mesh[mname] = g.add_mesh(mname, prims) if prims else None
            stats["meshes"] += 1
        if gl_mesh[mname] is None:
            continue
        ni = g.add_node({"name": node.attrs.get("Name", mname), "mesh": gl_mesh[mname], "matrix": a2})
        g.scene_nodes.append(ni)
        stats["nodes"] += 1
    g.save("venue", {"source": ar.name, "directory": "%08x" % dh, "stats": dict(stats)})
    log("venue %s: static scene %s" % (ar.name, dict(stats)))

    # --- trackside: stadium officials / ball boys / judges, the net, and the crowd models
    skels, _entries, _pf, _reg = load_trackside(ar)
    human, net_sk = skels[1], skels[0]
    tdir = os.path.join(out, "trackside")
    os.makedirs(tdir, exist_ok=True)
    lights, targets, placements = hierarchy_extras(hier)
    models = {}
    for p in placements:
        mesh = mesh_by_name.get(p["mesh"])
        if mesh is None or "weights" not in mesh.attrs or p["mesh"] in models:
            continue
        export_skinned_model(ar, mesh, tdir, p["mesh"], human, official_lod,
                             lambda gl, gi, mn=p["material"]: material_for(gl, mn, gi), texidx)
        models[p["mesh"]] = "trackside/%s.gltf" % p["mesh"]
    # other scene directories: net and crowd member models (each its own directory with Hierarchy.xml)
    crowd_models = {}
    net = None
    for d2, f2 in ar.dirs.items():
        if d2 == dh or "PackedMeshes.xbin" not in f2:
            continue
        mb = ar.read(f2["PackedMeshes.xbin"])
        recs = list(M.mesh_records(mb))
        if len(recs) != 1:
            continue
        m = M.parse_mesh(mb, recs[0])
        if "weights" not in m.attrs:
            continue
        mats2 = M.parse_packed_materials(ar.read(f2["PackedMaterials.bin"]))
        mm2 = {x.name: x for x in mats2}
        tx2 = A.TextureIndex()
        if "Textures.xpr" in f2:
            tx2.add_xpr(ar.read(f2["Textures.xpr"]))
        h2 = A.parse_hierarchy(ar.read(f2.get("Hierarchy.xml") or f2.get("Hierarchy.xdt")))
        geo = next((n for n, _w in M.hierarchy_world_matrices(h2) if n.name == "Geometry"), None)
        matname = geo.attrs.get("Material") if geo is not None else m.name
        cache2 = {}
        mf = (lambda gl, gi, mn=matname, t=tx2, mm=mm2, c=cache2: material_for(gl, mn, gi, t, mm, c))
        if all(b in net_sk.bones for b in m.bones) and "Filet_D01" in m.bones:
            # the net renders all of its groups (border + mesh), not a LOD
            import ts4_assets as A2
            ag = AnimGltf(tdir, "Net")
            skin, roots = add_skeleton_nodes(ag.g, net_sk)
            skin_map = [net_sk.bones.index(b) for b in m.bones]
            prims = A2.mesh_prims(ag.g, m, None, tx2, lambda gi: mf(ag.g, gi), A2.mirror_z,
                                  list(enumerate(m.groups)), skin_map=skin_map)
            ni = ag.g.add_node({"name": "Net", "mesh": ag.g.add_mesh("Net", prims), "skin": skin})
            ag.g.scene_nodes += roots + [ni]
            ag.save("Net")
            net = "trackside/Net.gltf"
            continue
        if not all(b in human.bones for b in m.bones):
            continue
        export_skinned_model(ar, m, tdir, m.name, human, crowd_lod, mf, tx2)
        crowd_models[m.name] = "trackside/%s.gltf" % m.name
    log("venue %s: trackside models %d, crowd models %d, net %s" % (ar.name, len(models), len(crowd_models), bool(net)))

    # --- crowd placement
    crowd = None
    cname = next((n for n in (ar.arc.leaf_names.get(e[0], (None, None))[1] for e in ar.arc.entries)
                  if n and n.startswith("Crowd") and n.endswith(".bin")), None)
    if cname:
        cbuf = ar.read(ar.find_name(cname))
        c = parse_crowd(cbuf)
        inst = crowd_instances(c)
        inst.update({"source": cname, "sha256": hashlib.sha256(cbuf).hexdigest(), "groups": c["groups"],
                     "octree": {"nodes": c["nodes"], "leaves": c["leaves"], "depth": c["depth"],
                                "half_size_m": round(c["root"]["half_size"] * SCALE, 3)},
                     "model_files": {k: crowd_models.get(k) for k in inst["models"]}})
        with open(os.path.join(out, "crowd.json"), "w") as f:
            json.dump(inst, f, separators=(",", ":"))
        crowd = {"file": "crowd.json", "count": len(inst["rows"]), "models": inst["models"],
                 "setups": inst["setups"], "groups": c["groups"]}
    # --- lights
    light_defs = []
    for n2, e in files.items():
        if n2 == "PackedLights.bin":
            light_defs = parse_packed_lights(ar.read(e))
    # --- court lines
    court = None
    if line_pos:
        edges = court_line_edges(line_pos)
        court = {"edges": edges, "check": court_line_check(edges), "gameplay_bounds_cm": GAMEPLAY_BOUNDS_CM}
    desc = None
    try:
        import ts4_assets as A3
        gar = A3.Archive("Global.arc", iso)
        de = gar.find_name(ar.name.replace(".arc", "") + "Desc.bin")
        if de is not None:
            desc = parse_venue_desc(gar.read(de), iso)
    except Exception as ex:          # Global.arc missing or Layoutall unreadable: keep going
        desc = {"error": str(ex)}
    venue = {"venue": ar.name.replace(".arc", ""), "scene_directory": "%08x" % dh, "gltf": "venue.gltf",
             "desc": desc, "lights": {"defs": light_defs, "nodes": lights, "targets": targets},
             "trackside": {"placements": placements, "models": models, "net": net, "skinned_nodes": skinned_nodes},
             "crowd": crowd, "court_lines": court,
             "frame": "glTF: right handed, Y up, metres; game x along the court (net at x = 0), z across mirrored"}
    with open(os.path.join(out, "venue.json"), "w") as f:
        json.dump(venue, f, indent=1)
    return venue


# --------------------------------------------------------------------------------------------- CLI

def cmd_inventory(a):
    import ts4_assets as A
    iso = iso_path(a.iso)
    import xdvdfs
    x = xdvdfs.XDVDFS(iso)
    names = [e for e in x.listdir("") if e.lower().endswith(".arc")] if hasattr(x, "listdir") else []
    gar = A.Archive("Global.arc", iso)
    rows = []
    for e in gar.arc.entries:
        ln = gar.leaf(e)
        if not ln or not ln.endswith("Desc.bin"):
            continue
        d = parse_venue_desc(gar.read(e), iso)
        rows.append({"desc": ln, "code": d.get("CodeName"), "surface": d.get("SurfaceKey"),
                     "inout": d.get("e4e9cc69"), "capacity": d.get("CapacityKey"), "weather": d.get("WeatherKey"),
                     "type": d.get("TypeKey"), "spectators": d.get("spectators")})
    rows.sort(key=lambda r: r["desc"])
    print(json.dumps(rows, indent=1) if a.json else "\n".join(
        "%-26s %-14s %-8s %-8s cap=%-10s weather=%-10s spectators=%d" % (
            r["desc"], r["code"], r["surface"], r["inout"], r["capacity"], r["weather"], len(r["spectators"] or []))
        for r in rows))


def cmd_crowd(a):
    import ts4_assets as A
    ar = A.Archive(a.arc, iso_path(a.iso))
    cname = next((ln for ln in (ar.leaf(e) for e in ar.arc.entries) if ln and ln.startswith("Crowd") and ln.endswith(".bin")), None)
    if not cname:
        sys.exit("no Crowd*.bin in %s" % a.arc)
    buf = ar.read(ar.find_name(cname))
    c = parse_crowd(buf)
    sp = c["spectators"]
    print("%s %d bytes sha256 %s" % (cname, len(buf), hashlib.sha256(buf).hexdigest()))
    print("octree nodes %d leaves %d depth %d half %.1f cm; spectators %d; groups %s" % (
        c["nodes"], c["leaves"], c["depth"], c["root"]["half_size"], len(sp), c["groups"]))
    print("models", collections.Counter(s["model"] for s in sp).most_common())
    print("setups", collections.Counter(s["setup"] for s in sp).most_common())
    print("uv offsets", collections.Counter(tuple(s["uv"]) for s in sp).most_common())


def cmd_export(a):
    import ts4_assets as A
    iso = iso_path(a.iso)
    ar = A.Archive(a.arc, iso)
    export_venue(ar, a.out, iso, int(a.dir, 16) if a.dir else None, a.all, a.crowd_lod, a.official_lod)


def cmd_trackside(a):
    import ts4_assets as A
    iso = iso_path(a.iso)
    ar = A.Archive(a.arc, iso)
    core = A.Archive("Core.arc", iso)
    export_trackside_shared(ar, core.arc, a.out, iso, a.clips)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--iso")
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("inventory")
    p.add_argument("--json", action="store_true")
    p = sub.add_parser("crowd")
    p.add_argument("arc")
    p = sub.add_parser("export")
    p.add_argument("arc")
    p.add_argument("--out", required=True)
    p.add_argument("--dir")
    p.add_argument("--all", action="store_true")
    p.add_argument("--crowd-lod", type=int, default=2, help="crowd model LOD group (0 = finest of 8)")
    p.add_argument("--official-lod", type=int, default=0)
    p = sub.add_parser("trackside")
    p.add_argument("--arc", default="Amsterdam.arc")
    p.add_argument("--out", required=True)
    p.add_argument("--clips", default="behaviours", choices=["behaviours", "all", "none"])
    a = ap.parse_args(argv)
    {"inventory": cmd_inventory, "crowd": cmd_crowd, "export": cmd_export, "trackside": cmd_trackside}[a.cmd](a)


if __name__ == "__main__":
    main()
