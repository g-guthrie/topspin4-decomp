#!/usr/bin/env python3
"""Player characters of Top Spin 4: pro roster appearance, creator option lists, glTF export.

Commands (read the user's own disc image / extracted Core.arc members; nothing is written outside --out):

  python3 tools/ts4_players.py roster   --out data/gameplay/pro_roster.yaml
  python3 tools/ts4_players.py creator  --out data/gameplay/creator_options.yaml
  python3 tools/ts4_players.py export   Baked_Federer0.arc [more arcs | --all] --out work/port/assets/players
  python3 tools/ts4_players.py animrules --out work/port/assets/players/anim_rules.json

`roster` reads every `Baked_<Player><n>.arc` (member names and `Hierarchy.xdt` only, about 1 s per archive) and
`PlayerList.bin` (Core `de208ac7`); `creator` reads `PlayerCreatorDB.bin` (Core `365f5d5a`) through the Layoutall
walker (`tools/ts4_xbin.py`); `export` writes one skinned glTF per archive (all LODs, visible parts only, body
groups hidden under clothing removed, DMorph targets, sweat / dirt texture variants); `animrules` converts the
AnimationsDB / swinganimation tables (via `tools/ts4data/anim_rules.py`) into the JSON the browser animator reads.

Formats, addresses and confidence are in docs/port/players.md.  Standard library only.
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
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(HERE, "havok"))
sys.path.insert(0, os.path.join(HERE, "ts4data"))

SCALE = 0.01


def crc(s):
    return zlib.crc32(s.encode("latin-1")) & 0xFFFFFFFF


def sha256(b):
    return hashlib.sha256(b).hexdigest()


# =========================================================================== names (pure, unit tested)

# Part tokens of the asset names (M_<PART>_<STYLE>_<PLAYER>_<BRAND>_<nn>...), from the 81 Baked archives and the
# creator database (Geometry/Material names).  Roles are read from the names and the Hierarchy (V for the set of
# tokens, I for the English role).
PART_ROLES = {
    "HUM": "human (body, head, eyes, mouth, lashes)", "TOP": "shirt / top", "BTM": "shorts / skirt",
    "SOC": "socks", "SHO": "shoes", "LAC": "laces", "HCX": "hair / headwear", "WBL": "wristband left",
    "WBR": "wristband right", "RAC": "racket", "CAP": "cap", "VIS": "visor", "BDA": "bandana",
    "HBD": "headband", "DRS": "dress", "GLS": "glasses", "ACC": "accessory", "FHR": "facial hair",
    "NCK": "necklace", "EAR": "earrings", "BRA": "bracelet",
}

PART_RE = re.compile(r"^(?P<cls>[MC])_(?P<part>[A-Z0-9]{3})_(?P<style>[A-Z0-9]{5})_(?P<player>[A-Z0-9]{5})"
                     r"(?:_(?P<brand>[A-Z0-9]{3}))?_(?P<num>\d\d)(?:_(?P<lod>\d{3}))?(?:_(?P<tail>.*))?$")


def parse_part_name(name):
    """Split an asset name such as ``M_TOP_PFEDX_XXXXX_00_100`` or ``M_BTM_SHORT_FEDER_NIK_00_DST``.

    Returns {cls, part, style, player, brand, num, lod, tail} (None for absent fields) or None when the name does
    not follow the grammar.  ``lod`` is the three-digit mesh suffix: 000 / 100 / 200 are the LOD files, 001..0NN
    DMorph targets (see docs/port/players.md s3).
    """
    stem = re.sub(r"\.(xbin|xdt|xpr|xml)$", "", name)
    m = PART_RE.match(stem)
    if not m:
        return None
    d = m.groupdict()
    d["role"] = PART_ROLES.get(d["part"])
    return d


TEX_RE = re.compile(r"^(?P<base>.*?)_2D_(?P<slot>DI|SP|BU|OC|SH)_(?P<kind>[RF])(?:_PASTTIME)?"
                    r"(?:_SWEAT(?P<sweat>\d))?(?:_DIRTY(?P<dirty>\d))?$")
SLOT_NAMES = {"DI": "diffuse", "SP": "specular", "BU": "bump", "OC": "occlusion", "SH": "shadow"}


def parse_texture_name(name):
    """``M_TOP_PFEDB_FEDER_NIK_00_2D_DI_F_PASTTIME_SWEAT1_DIRTY1`` ->
    {base, slot: diffuse, kind: F, sweat: 1, dirty: 1}.  ``_R`` names are the clean, neutral or reference map; ``_F``
    the per-player final variants (sweat level 1..3, dirt 0/1)."""
    m = TEX_RE.match(name)
    if not m:
        return None
    return {"base": m.group("base"), "slot": SLOT_NAMES[m.group("slot")], "kind": m.group("kind"),
            "sweat": int(m.group("sweat") or 0), "dirty": int(m.group("dirty") or 0)}


def variant_pack(member_name):
    """Texture pack kind from the archive member name: DST (clay dust), GRA (grass stains), SWE (sweat),
    ``_<n>_0`` (skin sweat level n) or None for the default pack (I for the surface meaning of DST / GRA)."""
    stem = re.sub(r"\.xpr$", "", member_name)
    m = re.search(r"_(DST|GRA|SWE)$", stem)
    if m:
        return {"DST": "clay", "GRA": "grass", "SWE": "sweat"}[m.group(1)]
    m = re.search(r"_(\d)_0$", stem)
    if m:
        return "sweat%s" % m.group(1)
    return None


def variant_key(tex, pack):
    """Key under which a texture variant is published: sweat<N>[_<surface>] (surface from the pack)."""
    s = "sweat%d" % tex["sweat"]
    if tex["dirty"]:
        s += "_" + (pack if pack in ("clay", "grass") else "dirty")
    return s


def arc_player(arc_name):
    """``Baked_Federer0.arc`` -> (``Federer``, 0); ``Baked_PlayerAcademy10.arc`` -> (``PlayerAcademy1``, 0)."""
    m = re.match(r"^Baked_(.+?)(\d)\.arc$", os.path.basename(arc_name))
    return (m.group(1), int(m.group(2))) if m else (None, None)


# =========================================================================== Hierarchy (pure on parsed XDT trees)

ATTR_LIFETIME = "0x64a3fde0"        # crc32("LifeTime"); -1 = shown, 0 = not shown (I: Hierarchy flags of absent parts are 0)
HASH_VISIBLE_GROUPS = "0xebd4a36e"  # list of 0xabca359e {Name}: body groups that stay drawn (I, s4 of the doc)
HASH_GROUP = "0xabca359e"
HASH_ALT = "0x58e4a0f3"             # '1' on the *_99 geometries (alternative version of a part, U)
HASH_2DPASS = "0x87925690"          # 'True' on the child geometry drawn with the *_2dPass material (hair cards)


def _attr(node, key, default=None):
    v = node.attrs.get(key, default)
    if isinstance(v, (bytes, bytearray)) and len(v) == 4:
        return struct.unpack(">i", v)[0]
    return v


def _find(node, name):
    for c in node.children:
        if str(c.name) == name:
            return c
    return None


def hierarchy_geometries(root):
    """Every Geometry node of a player Hierarchy.xdt as a dict (document order, nested 2d-pass children kept)."""
    out = []

    def rec(n, parent_geom):
        if str(n.name) == "Geometry":
            g = {"name": _attr(n, "Name"), "mesh": _attr(n, "Mesh"), "material": _attr(n, "Material"),
                 "shown": _attr(n, ATTR_LIFETIME, -1) == -1, "alt": _attr(n, HASH_ALT) == "1",
                 "second_pass": _attr(n, HASH_2DPASS) == "True", "parent": parent_geom}
            up = _find(n, "UserProperties")
            if up is not None:
                g["lod_distance_cm"] = [float(_attr(up, "Distance1", 0) or 0), float(_attr(up, "Distance2", 0) or 0)]
                g["shader_lod"] = _attr(up, "ShaderLOD")
                g["user"] = {k: v for k, v in up.attrs.items() if k not in ("Distance1", "Distance2", "ShaderLOD")
                             and isinstance(v, str)}
            ml = _find(n, "DMorphList")
            if ml is not None:
                g["morphs"] = [{"name": _attr(c, "Name"), "weight": float(_attr(c, "Weight", 0.0) or 0.0)}
                               for c in ml.children]
            vg = _find(n, HASH_VISIBLE_GROUPS)
            if vg is not None:
                g["visible_groups"] = [_attr(c, "Name") for c in vg.children]
            out.append(g)
            parent_geom = g["name"]
        for c in n.children:
            rec(c, parent_geom)
    rec(root, None)
    return out


def body_group_visible(group_name, visible_groups):
    """Body group filter: with a visible-group list only the listed group names are drawn (I)."""
    return visible_groups is None or group_name in visible_groups


# =========================================================================== mesh helpers

def lod_sets(mesh):
    """Split a mesh's groups into its LOD sets, highest detail first: [[(index, group), ...], ...].

    A player mesh stores N equal sets of groups (3 for the body, head, mouth and hair, 1 for most clothes); the set
    with more indices is the finer one (the body stores them mid, low, high, so the order is not fixed)."""
    n = len(mesh.groups)
    for nl in (3, 2, 4):
        if n % nl == 0 and n // nl >= 1 and n > 1:
            k = n // nl
            names = [g.name for g in mesh.groups]
            sets = [list(range(i * k, (i + 1) * k)) for i in range(nl)]
            if all(names[s[0]:s[0] + k] == names[0:k] for s in sets):
                sets.sort(key=lambda s: -sum(len(mesh.groups[i].indices) for i in s))
                return [[(i, mesh.groups[i]) for i in s] for s in sets]
    return [list(enumerate(mesh.groups))]


def parse_morph(d, s=0x14):
    """A DMorph target file (signature 7d72a97d a12b5eb9): a mesh record without groups and bones whose vertex
    array holds the target shape: position Float16_4, normal Dec3N, tangent Dec3N (V for the layout, I that the
    position is a delta: most vertices are (0, 0, 0, 1)).  Returns (name, {usage: [tuples]})."""
    import ts4_mesh as M
    layout, off = [], 0
    for i, usage in enumerate(M.SLOT_USAGES):
        p = M.ptr(d, s + 0x28 + 4 * i)
        if p is None:
            continue
        fmt = M.cstr(d, M.ptr(d, p))
        layout.append((usage, fmt, off))
        off += M.FORMAT_SIZES[fmt]
    vdata, vcount = M.array(d, M.ptr(d, s + 0x50))
    attrs = {}
    for usage, fmt, o in layout:
        n = M.FORMAT_SIZES[fmt]
        attrs[usage] = [M.decode_attr(fmt, d[vdata + i * off + o: vdata + i * off + o + n]) for i in range(vcount)]
    np_ = M.ptr(d, s + 0x58)
    return (M.cstr(d, np_) if np_ is not None else None), attrs


# =========================================================================== disc access

def iso_path(a):
    cands = [getattr(a, "iso", None), os.environ.get("TS4_ISO"),
             os.path.join(ROOT, "orig", "54540859", "Top Spin 4 (World) (En,Fr,De,Es,It).iso"),
             os.path.join(ROOT, "orig", "54540859", "disc_archive", "Top Spin 4 (World) (En,Fr,De,Es,It).iso")]
    for p in cands:
        if p and os.path.exists(p):
            return p
    sys.exit("disc image not found: pass --iso or set TS4_ISO")


def list_baked(iso):
    """Every Baked_<Player><n>.arc on the disc (names from tools/xiso.py list)."""
    import subprocess
    out = subprocess.run([sys.executable, os.path.join(HERE, "xiso.py"), "list", iso], capture_output=True,
                         text=True).stdout
    return sorted(set(re.findall(r"(Baked_\w+\.arc)", out)))


def player_list(core_dir):
    """PlayerList.bin (Core de208ac7) rows: the appearance-relevant fields of every player entry."""
    import ts4_xbin as X
    p = os.path.join(core_dir, "de208ac7.bin")
    buf = open(p, "rb").read()
    lay = X.Layout(open(os.path.join(core_dir, "..", "root", "Layoutall.bin"), "rb").read())
    names = load_names(core_dir)
    w = X.Walker(buf, lay, names)
    w.walk_file()
    rows = collections.defaultdict(dict)
    for lf in w.leaves:
        m = re.match(r"Player\[(\d+)\]/(?:MainInfo/)?(\w+)$", lf.path)
        if not m:
            continue
        v = lf.value
        if lf.tag == "key":
            v = names.get(v, "%08x" % v)
        if isinstance(v, tuple):
            v = v[1]
        rows[int(m.group(1))][m.group(2)] = v
    return [rows[i] for i in sorted(rows)], sha256(buf), len(buf)


def load_names(core_dir):
    import ts4_xbin as X
    cands = [os.path.join(core_dir, "..", "values", "names.json"), os.path.join(ROOT, "data", "gameplay", "names.yaml")]
    names = X.load_names(*[c for c in cands if os.path.exists(c)])
    for extra in ("RightHanded", "LeftHanded", "Male", "Female", "CreatedPlayer", "DMorph", "DMorphList", "Pro",
                  "Legend", "Generic"):
        names.setdefault(crc(extra), extra)
    return names


# =========================================================================== YAML writer (minimal, stdlib)

def yq(v):
    if v is None:
        return "null"
    if isinstance(v, bool):
        return "true" if v else "false"
    if isinstance(v, (int,)):
        return str(v)
    if isinstance(v, float):
        return repr(round(v, 6))
    s = str(v)
    if re.fullmatch(r"[A-Za-z_][A-Za-z0-9_.\-/]*", s) and s.lower() not in ("null", "true", "false", "yes", "no", "on",
                                                                            "off", "y", "n"):
        return s
    return json.dumps(s)


def yflow(v):
    if isinstance(v, dict):
        return "{" + ", ".join("%s: %s" % (yq(k), yflow(x)) for k, x in v.items()) + "}"
    if isinstance(v, (list, tuple)):
        return "[" + ", ".join(yflow(x) for x in v) + "]"
    return yq(v)


def ywrite(o, data, indent=0, flow_depth=2):
    """Block YAML for the top levels, flow style below ``flow_depth``."""
    pad = "  " * indent
    if isinstance(data, dict):
        for k, v in data.items():
            if isinstance(v, (dict, list)) and v and indent < flow_depth:
                o.write("%s%s:\n" % (pad, yq(k)))
                ywrite(o, v, indent + 1, flow_depth)
            else:
                o.write("%s%s: %s\n" % (pad, yq(k), yflow(v)))
    elif isinstance(data, list):
        for v in data:
            if isinstance(v, dict) and v and indent < flow_depth:
                first = True
                for k, x in v.items():
                    lead = pad + ("- " if first else "  ")
                    if isinstance(x, (dict, list)) and x and indent + 1 < flow_depth:
                        o.write("%s%s:\n" % (lead, yq(k)))
                        ywrite(o, x, indent + 2, flow_depth)
                    else:
                        o.write("%s%s: %s\n" % (lead, yq(k), yflow(x)))
                    first = False
            else:
                o.write("%s- %s\n" % (pad, yflow(v)))


# =========================================================================== roster

def roster_entry(arc_name, member_names, geoms):
    """One roster row from an archive's member names and its Hierarchy geometries (pure)."""
    player, outfit = arc_player(arc_name)
    parts = collections.OrderedDict()
    for g in geoms:
        if g["parent"] or not g["name"]:
            continue
        pn = parse_part_name(g["name"])
        mesh_file = (g["mesh"] or "").replace("_Player00", "") + ".xbin"
        present = mesh_file in member_names
        if not present:
            continue
        key = g["name"]
        e = {"part": pn["part"] if pn else None, "style": pn["style"] if pn else None,
             "lod": pn["lod"] if pn else None, "shown": g["shown"], "material": (g["material"] or "").replace("_Player00", "")}
        if g.get("alt"):
            e["alt"] = True
        if g.get("visible_groups"):
            e["visible_groups"] = g["visible_groups"]
        if g.get("morphs"):
            e["morphs"] = [m["name"] for m in g["morphs"] if m["name"] + ".xbin" in member_names] or None
        if g.get("lod_distance_cm"):
            e["lod_distance_cm"] = g["lod_distance_cm"]
        parts[key] = e
    variants = collections.defaultdict(list)
    for n in member_names:
        if n.endswith(".xpr"):
            k = variant_pack(n)
            if k:
                variants[k].append(n[:-4])
    brands = sorted({p["brand"] for p in (parse_part_name(n) for n in member_names) if p and p.get("brand")})
    styles = sorted({(p["part"], p["style"], p["player"]) for p in (parse_part_name(n) for n in member_names)
                     if p and p["player"] != "XXXXX"})
    return {"arc": arc_name, "player": player, "outfit": outfit, "parts": parts,
            "brands": brands, "signature_items": ["%s_%s_%s" % s for s in styles],
            "texture_variants": {k: sorted(set(v)) for k, v in sorted(variants.items())},
            "cloth": sorted(n for n in member_names if n.startswith(("CLTH_", "CLMT_"))),
            "ragdoll": "Physics.hkx" in member_names}


def cmd_roster(a):
    import ts4_assets as A
    import ts4_mesh as M
    iso = iso_path(a)
    arcs = a.arcs or list_baked(iso)
    rows, plist_sha, plist_size = (player_list(a.core) if os.path.exists(os.path.join(a.core, "de208ac7.bin"))
                                   else ([], None, 0))
    by_asset = {}
    for i, r in enumerate(rows):
        if r.get("AssetName"):
            by_asset.setdefault(str(r["AssetName"]).lower(), (i, r))
    out = []
    sources = {}
    for arc in arcs:
        ar = A.Archive(arc, iso)
        names = sorted({ar.leaf(e) for e in ar.arc.entries if ar.leaf(e)})
        he = ar.find_name("Hierarchy.xdt")
        geoms = []
        if he is not None:
            hb = ar.read(he)
            sources[arc + ":Hierarchy.xdt"] = (len(hb), sha256(hb))
            geoms = hierarchy_geometries(M.parse_xdt(hb))
        e = roster_entry(arc, set(names), geoms)
        hit = by_asset.get((e["player"] or "").lower()) or by_asset.get((e["player"] or "").lower() + str(e["outfit"]))
        if hit:
            i, r = hit
            e["player_list"] = {"index": i, "code": r.get("Code"), "gender": r.get("Gender"), "height_cm": r.get("Height"),
                                "weight_kg": r.get("Weight"), "plays": r.get("Plays"), "hand_mode": r.get("HandMode"),
                                "sponsors": [r.get("Sponsor00"), r.get("Sponsor01")], "type": r.get("Type")}
        out.append(e)
        print("%-28s %2d parts, variants %s" % (arc, len(e["parts"]), ",".join(e["texture_variants"])), file=sys.stderr)
    # the 700+ non-licensed players have no Baked archive: list their appearance-relevant PlayerList fields
    others = [{"index": i, "code": r.get("Code"), "asset": r.get("AssetName"), "type": r.get("Type"),
               "gender": r.get("Gender"), "height_cm": r.get("Height"), "weight_kg": r.get("Weight"),
               "plays": r.get("Plays")} for i, r in enumerate(rows)]
    doc = collections.OrderedDict()
    doc["generated_by"] = "python3 tools/ts4_players.py roster --out %s" % a.out
    doc["sources"] = {"disc image": os.path.basename(iso), "PlayerList.bin (Core de208ac7)": [plist_size, plist_sha]}
    doc["sources"].update({k: list(v) for k, v in sorted(sources.items())})
    doc["notes"] = ("Pros with a Baked archive (outfit = archive digit). parts: Hierarchy Geometry nodes whose mesh is in "
                    "the archive; shown = LifeTime -1; visible_groups = body groups left drawn under the clothes; "
                    "texture_variants: sweat / clay / grass texture packs. See docs/port/players.md.")
    doc["pros"] = out
    doc["player_list"] = others
    os.makedirs(os.path.dirname(a.out) or ".", exist_ok=True)
    with open(a.out, "w") as o:
        ywrite(o, doc, 0, flow_depth=3)
    print("wrote %s: %d archives, %d PlayerList rows, %d bytes" % (a.out, len(out), len(others), os.path.getsize(a.out)))


# =========================================================================== creator database

def tree_from_leaves(leaves, prefix):
    """Nest walker leaves under ``prefix`` into dicts / lists: 'A[0]/B' -> {'A': [{'B': v}]} (pure)."""
    root = {}
    for path, value in leaves:
        if not path.startswith(prefix):
            continue
        rest = path[len(prefix):].lstrip("/")
        cur = root
        toks = [t for t in re.split(r"/(?![^<]*>)", rest) if t]
        for ti, tok in enumerate(toks):
            m = re.match(r"^(.*?)(?:\[(\d+)\])?(?:<[^>]*>)?$", tok)
            key, idx = m.group(1), m.group(2)
            last = ti == len(toks) - 1
            if idx is None:
                if last:
                    cur[key] = value
                else:
                    cur = cur.setdefault(key, {})
                    if not isinstance(cur, dict):
                        break
            else:
                lst = cur.setdefault(key, [])
                if not isinstance(lst, list):
                    break
                i = int(idx)
                while len(lst) <= i:
                    lst.append({})
                if last:
                    lst[i] = value
                else:
                    cur = lst[i]
                    if not isinstance(cur, dict):
                        break
    return root


def _leafval(lf, names):
    v = lf.value
    if isinstance(v, tuple):
        v = v[1]
    if lf.tag == "key":
        v = names.get(v, "%08x" % v) if v else None
    if isinstance(v, float):
        v = round(v, 5)
    if isinstance(v, (bytes, bytearray)):
        v = v.split(b"\0")[0].decode("latin-1")
    return v


def creator_summary(tree):
    """Compact option lists from the PlayerCreatorDB tree (pure, works on synthetic trees)."""
    db = tree.get("RunTimeDB", {}).get("CharacterCreator", {})
    data = db.get("Data", {})
    out = collections.OrderedDict()

    def ids(lst, *keys):
        return [{k: e.get(k) for k in keys if k in e} for e in (lst or []) if isinstance(e, dict)]
    geos = data.get("Geometries", {}).get("Geometry", [])
    out["geometries"] = [{"name": g.get("Name"), "id": g.get("ID"), "lod": g.get("Lod"), "facegen": g.get("IsFaceGen"),
                          "physic": g.get("IsPhysic"),
                          "materials": [r.get("XPath") for r in g.get("MaterialList", {}).get("MaterialRef", [])],
                          "morphs": len(g.get("MorphList", {}).get("MorphRef", [])),
                          "lods": [r.get("XPath") for r in g.get("LODList", {}).get("GeometryRef", [])]}
                         for g in geos if isinstance(g, dict)]
    mats = data.get("Materials", {}).get("Material", [])
    out["materials"] = [{"name": m.get("Name"), "id": m.get("ID"),
                         "textures": [r.get("XPath") for r in m.get("TextureList", {}).get("TextureRef", [])]}
                        for m in mats if isinstance(m, dict)]
    morph_key = [k for k, v in data.items() if isinstance(v, dict) and "Morph" in v]
    morphs = data.get(morph_key[0], {}).get("Morph", []) if morph_key else []
    out["morphs"] = ids(morphs, "Name", "ID", "MorphID", "Min", "Max", "Weight")
    texs = data.get("Textures", {}).get("Texture", [])
    out["texture_count"] = len(texs)
    out["textures_sample"] = ids(texs[:40], "Name", "FileName", "Path", "SizeX", "SizeY", "Format", "IsDynamic")
    fg = data.get("FaceGen", {})
    out["facegen_local_controls"] = {k: ids(v.get("67737984", []), "Name", "Min", "Max", "Value")
                                     for k, v in fg.get("Local", {}).items() if isinstance(v, dict)}
    for sex in ("Male", "Female"):
        s = db.get(sex, {})
        o = collections.OrderedDict()
        outfits = s.get("OutfitList", {}).get("Outfit", [])
        o["outfits"] = []
        for of in outfits:
            if not isinstance(of, dict):
                continue
            geo = []
            for gr in of.get("GeometryList", {}).get("GeometryRef", []):
                brands = [b.get("Name") for b in gr.get("BrandList", {}).get("Brand", []) if isinstance(b, dict)]
                geo.append({"geometry": gr.get("XPath"), "brands": brands})
            o["outfits"].append({k: of.get(k) for k in ("Name", "ID") if k in of} | {"geometries": geo})
        o["geometries"] = [r.get("XPath") for r in s.get("GeometryList", {}).get("GeometryRef", [])]
        o["hierarchies"] = [r.get("XPath") for r in s.get("HierarchyList", {}).get("HierarchyRef", [])]
        o["morph_groups"] = [{"name": g.get("Name"), "morphs": [r.get("XPath") for r in g.get("MorphList", {}).get("MorphRef", [])]}
                             for g in s.get("b766c13b", {}).get("5b56094b", []) if isinstance(g, dict)]
        o["facegen_meshes"] = [r.get("XPath") for r in s.get("FaceGenList", {}).get("GeometryRef", [])]
        o["facegen_hotspots"] = [{"name": h.get("Name"), "category": h.get("PresetCategory"), "vertex": h.get("VertexID")}
                                 for hs in s.get("FaceGen_HotSpotList", {}).get("FaceGen_HotSpot", []) if isinstance(hs, dict)
                                 for h in hs.get("HotSpot", []) if isinstance(h, dict)]
        layers = []
        for cs in s.get("Layers", {}).get("CommandSet", []):
            if not isinstance(cs, dict):
                continue
            row = {"name": cs.get("Name")}
            for ch in ("DIFFUSE", "SPECULAR", "BUMP"):
                c = cs.get(ch, {})
                lay = c.get("478c88ad", {}).get("393aad1f", [])
                zones = c.get("4db593c6", {}).get("Zone", [])
                if lay:
                    row[ch.lower()] = [{"name": l.get("Name"), "textures": len(l.get("TextureList", {}).get("TextureRef", [])),
                                        "opacity": l.get("Opacity")} for l in lay if isinstance(l, dict)]
                if zones:
                    row[ch.lower() + "_zones"] = [z.get("Name") for z in zones if isinstance(z, dict)]
            layers.append(row)
        o["texture_layers"] = layers
        ui = tree.get("RunTimeUI", {}).get("CharacterCreator", {}).get(sex, {})
        o["presets"] = [{"name": p.get("Name"),
                         "choices": [len(c.get("PresetChoice", [])) for c in p.get("cfa4a5b6", []) if isinstance(c, dict)]}
                        for p in ui.get("RunTime", {}).get("PresetList", {}).get("Preset", []) if isinstance(p, dict)]
        out[sex.lower()] = o
    return out


def cmd_creator(a):
    import ts4_xbin as X
    p = os.path.join(a.core, "365f5d5a.bin")
    buf = open(p, "rb").read()
    lay_path = os.path.join(a.core, "..", "root", "Layoutall.bin")
    lay = X.Layout(open(lay_path, "rb").read())
    names = load_names(a.core)
    w = X.Walker(buf, lay, names)
    w.walk_file()
    leaves = [(lf.path, _leafval(lf, names)) for lf in w.leaves if not lf.path.startswith(("AgentsSettings", "AgentsState"))]
    tree = tree_from_leaves(leaves, "")
    summ = creator_summary(tree)
    doc = collections.OrderedDict()
    doc["generated_by"] = "python3 tools/ts4_players.py creator --out %s" % a.out
    doc["sources"] = {"PlayerCreatorDB.bin (Core 365f5d5a)": [len(buf), sha256(buf)],
                      "Layoutall.bin": [os.path.getsize(lay_path), sha256(open(lay_path, "rb").read())]}
    agents = sum(1 for lf in w.leaves if lf.path.startswith("AgentsSettings"))
    doc["notes"] = ("Creator option lists decoded with the Layoutall walker. The DNA -> morph / texture analyser agents "
                    "(AgentsSettings, %d leaves) are counted, not listed. XPath values name the referenced entry." % agents)
    doc.update(summ)
    os.makedirs(os.path.dirname(a.out) or ".", exist_ok=True)
    with open(a.out, "w") as o:
        ywrite(o, doc, 0, flow_depth=3)
    print("wrote %s: %d geometries, %d materials, %d morphs, %d bytes" % (
        a.out, len(summ["geometries"]), len(summ["materials"]), len(summ["morphs"]), os.path.getsize(a.out)))


# =========================================================================== glTF export

def _unit(v):
    l = math.sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2])
    return (v[0] / l, v[1] / l, v[2] / l) if l > 1e-9 else (0.0, 1.0, 0.0)


def skin_pairs(weights, indices, skin_map):
    """Four (joint, weight) pairs for one vertex; weight i pairs with index byte 3 - i (docs/assets.md s4)."""
    pairs = sorted(((weights[i], skin_map[indices[3 - i]]) for i in range(4) if weights[i] > 0), reverse=True)
    tot = sum(p[0] for p in pairs) or 1.0
    pairs = pairs[:4] + [(0.0, 0)] * (4 - len(pairs))
    return tuple(p[1] for p in pairs), tuple(p[0] / tot for p in pairs)


def build_prims(g, mesh, groups, xf, matinfo, skin_map=None, morphs=None):
    """glTF primitives for ``groups`` of ``mesh``; ``morphs`` = [(name, attrs)] become morph targets."""
    pos = [tuple(c * SCALE for c in xf(p)) for p in mesh.attrs["position"]]
    nrm = [_unit(xf(n)) for n in mesh.attrs["normal"]] if "normal" in mesh.attrs else None
    uv0 = [tuple(u) for u in mesh.attrs.get("uv0", [])] or None
    joints = weights = None
    if skin_map is not None and "weights" in mesh.attrs:
        joints, weights = [], []
        for w, ix in zip(mesh.attrs["weights"], mesh.attrs["indices"]):
            j, ww = skin_pairs(w, ix, skin_map)
            joints.append(j)
            weights.append(ww)
    tdeltas = []
    for name, attrs in morphs or []:
        p = attrs.get("position")
        if not p or len(p) != len(pos):
            continue
        tdeltas.append((name, [tuple(c * SCALE for c in xf(v[:3])) for v in p]))
    prims = []
    for gi, grp in groups:
        tris = grp.triangles()
        if not tris:
            continue
        used = sorted({i for t in tris for i in t})
        remap = {o: n for n, o in enumerate(used)}
        sub = lambda arr: [arr[i] for i in used] if arr else None  # noqa: E731
        prim = g.primitive(sub(pos), sub(nrm), sub(uv0), None,
                           [(remap[a], remap[b], remap[c]) for a, b, c in tris], matinfo(gi), sub(joints), sub(weights))
        if tdeltas:
            prim["targets"] = []
            for _n, dl in tdeltas:
                vals = [c for v in sub(dl) for c in v]
                prim["targets"].append({"POSITION": g.accessor(vals, 5126, "VEC3", len(used), 34962, True)})
        prims.append(prim)
    return prims


def export_player(arc, out_root, a, iso, skel_cache=None):
    import ts4_assets as A
    import ts4_mesh as M
    import skeleton as SK
    ar = A.Archive(arc, iso)
    stem = arc.replace(".arc", "")
    out = os.path.join(out_root, stem)
    names = {ar.leaf(e): e for e in ar.arc.entries if ar.leaf(e)}
    he = names.get("Hierarchy.xdt")
    geoms = hierarchy_geometries(M.parse_xdt(ar.read(he))) if he else []
    geo_by_mesh = {}
    for gm in geoms:
        if gm["mesh"] and not gm["parent"]:
            geo_by_mesh.setdefault(gm["mesh"].replace("_Player00", ""), gm)
    sk = skel_cache if skel_cache is not None else A.load_skeleton(a, iso)
    g = A.Gltf(out, stem)
    for i, bone in enumerate(sk.bones):
        t, r, s = sk.ref[i]
        node = {"name": bone, "translation": [t[0] * SCALE, t[1] * SCALE, -t[2] * SCALE],
                "rotation": list(SK.quat_normalize([-r[0], -r[1], r[2], r[3]])), "scale": list(s)}
        kids = [j for j, p in enumerate(sk.parents) if p == i]
        if kids:
            node["children"] = kids
        g.add_node(node)
    roots = [i for i, p in enumerate(sk.parents) if p < 0]
    pose = [([t[0] * SCALE, t[1] * SCALE, -t[2] * SCALE], SK.quat_normalize([-r[0], -r[1], r[2], r[3]]), s)
            for t, r, s in sk.ref]
    ibm = []
    for wm in sk.world_matrices(pose):
        ibm += SK.mat_inverse_affine(wm)
    g.skins.append({"name": "Skeleton71", "joints": list(range(len(sk.bones))), "skeleton": roots[0],
                    "inverseBindMatrices": g.accessor(ibm, 5126, "MAT4", len(sk.bones))})
    g.scene_nodes += roots

    texidx = A.TextureIndex()
    pack_of = {}
    for n, e in names.items():
        if n.endswith(".xpr"):
            buf = ar.read(e)
            texidx.add_xpr(buf)
            import ts4_texture as T
            for t in T.parse_xpr2(buf)[0]:
                pack_of.setdefault(t.name, variant_pack(n))
    xdts = []
    for n, e in names.items():
        if n.endswith((".xdt", ".xml")) and not n.startswith("Hierarchy"):
            try:
                xdts.append(M.xdt_material(M.parse_xdt(ar.read(e))))
            except Exception:  # noqa: BLE001 - plain XML members are skipped
                pass
    mat_by_name = {}
    for x in xdts:
        mat_by_name.setdefault(x.name, x)
        for s_ in x.subs:
            mat_by_name.setdefault(s_.name, x)

    variants_by_base = collections.defaultdict(dict)    # (base, slot) -> {key: texture name}
    for tname in texidx.tex:
        tp = parse_texture_name(tname)
        if tp and tp["kind"] == "F" or (tp and (tp["sweat"] or tp["dirty"])):
            base = re.sub(r"_[A-Z0-9]{5}_[A-Z0-9]{3}_(\d\d)$", r"_XXXXX_XXX_\1", tp["base"])   # player/brand -> neutral
            variants_by_base[(base, tp["slot"])][variant_key(tp, pack_of.get(tname))] = tname
            variants_by_base[(tp["base"], tp["slot"])][variant_key(tp, pack_of.get(tname))] = tname

    def tex(name, normal=False):
        rgba, w, h, _fmt = texidx.decode(name)
        return g.image(name, rgba, w, h), rgba

    def frame(p):
        return (p[2], p[1], p[0])
    mat_cache = {}
    stats = collections.Counter()
    parts = []
    mesh_files = sorted(n for n in names if re.search(r"_(000|100|200)\.xbin$", n))
    for fname in mesh_files:
        d = ar.read(names[fname])
        if M.u32(d, 4) != 0x330FAC24:
            continue
        mesh = M.parse_mesh(d, 0x14)
        if not mesh.bones:
            continue
        key = fname[:-5]
        gm = geo_by_mesh.get(key) or {}
        if gm and not gm.get("shown", True) and key.endswith("_000"):
            stats["hidden_by_hierarchy"] += 1
            continue
        fb = sk.bones.index("B_Head")
        skin_map = [sk.bones.index(b) if b in sk.bones else fb for b in mesh.bones]
        mx = mat_by_name.get(mesh.name) or mat_by_name.get(re.sub(r"_(\d\d)$", r"_\1", mesh.name))
        sets = lod_sets(mesh)
        lod_file = int(fname[-8])                         # _000 / _100 / _200 -> 0 / 1 / 2
        visible = gm.get("visible_groups")
        morphs = []
        for mo in gm.get("morphs") or []:
            mf = (mo["name"] or "") + ".xbin"
            if mf in names:
                try:
                    morphs.append(parse_morph(ar.read(names[mf])))
                    stats["morph_targets"] += 1
                except Exception as ex:  # noqa: BLE001
                    print("  morph %s: %s" % (mf, ex), file=sys.stderr)

        def matinfo(gi, mesh=mesh, mx=mx):
            sm = A.pick_submaterial(mx, mesh, gi) if mx else None
            mkey = (mesh.name, sm.name if sm else None)
            if mkey in mat_cache:
                return mat_cache[mkey]
            slots, extras = {}, {}
            if sm:
                for slot, tname in sm.textures:
                    r = texidx.resolve(tname)
                    if r:
                        slots[slot] = r
            diff = slots.get("DiffuseMap")
            ti, alpha = None, False
            if diff:
                ti, rgba = tex(diff)
                alpha = A.has_alpha(rgba)
            extras["slots"] = slots
            m = g.material((sm.name if sm else mesh.name) or mesh.name, ti, alpha, None)
            mat = g.materials[m]
            bump = slots.get("BumpMap")
            if bump and not a.no_normal:
                mat["normalTexture"] = {"index": tex(bump)[0]}
            spec = slots.get("SpecularMap") or slots.get("SpecMap")
            if spec and a.variants:
                extras["specularTexture"] = g.images[tex(spec)[0]]["uri"]
            if a.variants:
                var = {}
                for slotname, tname in slots.items():
                    tp = parse_texture_name(tname)
                    if not tp:
                        continue
                    for k, vname in sorted(variants_by_base.get((tp["base"], tp["slot"]), {}).items()):
                        var.setdefault(tp["slot"], {})[k] = g.images[tex(vname)[0]]["uri"]
                        stats["variant_textures"] += 1
                if var:
                    extras["variants"] = var
            mat["extras"] = extras
            mat_cache[mkey] = m
            return m
        attached = len(mesh.bones) == 1 and mesh.bones[0] in ("B_Racket_Handle", "B_Prop1", "B_Prop2")
        lod_list = sets if lod_file == 0 else sets[:1]
        for lvl, grp in enumerate(lod_list):
            level = lod_file if lod_file else lvl
            groups = [(gi, gr) for gi, gr in grp if gr.name == "KeyNull" or body_group_visible(gr.name, visible)]
            stats["groups_hidden"] += len(grp) - len(groups)
            if attached:
                prims = build_prims(g, mesh, groups, A.mirror_z, matinfo, None, None)
            else:
                prims = build_prims(g, mesh, groups, frame, matinfo, skin_map, morphs if level == 0 else None)
            if not prims:
                continue
            nm = mesh.name + ("" if level == 0 else "_LOD%d" % level)
            mi = g.add_mesh(nm, prims)
            if morphs and level == 0 and not attached:
                g.meshes[mi]["weights"] = [mo.get("weight", 0.0) for mo in gm.get("morphs") if (mo["name"] or "") + ".xbin" in names][:len(prims[0].get("targets", []))]
                g.meshes[mi]["extras"] = {"targetNames": [n for n, _ in morphs]}
            node = {"name": nm, "mesh": mi, "extras": {"lod": level, "part": key, "lod_distance_cm": gm.get("lod_distance_cm")}}
            if level:
                node["extras"]["hidden_by_default"] = True
            if attached:
                ni = g.add_node(node)
                g.nodes[sk.bones.index(mesh.bones[0])].setdefault("children", []).append(ni)
            else:
                node["skin"] = 0
                ni = g.add_node(node)
                g.scene_nodes.append(ni)
            stats["nodes_lod%d" % level] += 1
        parts.append({"file": fname, "mesh": mesh.name, "lods": len(lod_list), "visible_groups": visible,
                      "morphs": [n for n, _ in morphs] or None})
        print("  %-30s lods %d groups %d%s" % (fname, len(lod_list), len(mesh.groups),
                                               " visible %s" % visible if visible else ""), file=sys.stderr)
    player, outfit = arc_player(arc)
    extras = {"source": arc, "player": player, "outfit": outfit, "stats": dict(stats), "parts": parts,
              "conventions": "metres, Y up, right handed (z negated); skeleton = Core.arc 6932352f skeleton %d"
                             % getattr(a, "skeleton_index", 0)}
    path = g.save("player", extras)
    print("wrote", path, dict(stats), "textures", len(g.images), file=sys.stderr)
    return path, extras


def cmd_export(a):
    import ts4_assets as A
    iso = iso_path(a)
    arcs = list_baked(iso) if a.all else a.arcs
    sk = A.load_skeleton(a, iso)
    index = []
    idx_path = os.path.join(a.out, "index.json")
    if os.path.exists(idx_path):
        index = json.load(open(idx_path)).get("players", [])
    for arc in arcs:
        if a.skip_existing and os.path.exists(os.path.join(a.out, arc.replace(".arc", ""), "player.gltf")):
            continue
        path, ex = export_player(arc, a.out, a, iso, sk)
        index = [e for e in index if e["arc"] != arc]
        index.append({"arc": arc, "player": ex["player"], "outfit": ex["outfit"],
                      "file": os.path.relpath(path, a.out).replace(os.sep, "/")})
    os.makedirs(a.out, exist_ok=True)
    roster = {}
    if a.roster and os.path.exists(a.roster):
        roster = parse_roster_handedness(open(a.roster).read())
    for e in index:
        if e["arc"] in roster:
            e.update(roster[e["arc"]])
    with open(idx_path, "w") as f:
        json.dump({"players": sorted(index, key=lambda e: e["arc"]), "generated_by": "tools/ts4_players.py export"}, f, indent=1)
    print("wrote", idx_path)


def parse_roster_handedness(text):
    """Read arc -> {plays, height_cm, gender} back from pro_roster.yaml (flow or block player_list, pure)."""
    out, cur, inblock = {}, None, False
    for line in text.splitlines():
        m = re.match(r"^\s*- arc: (\S+)", line)
        if m:
            cur, inblock = m.group(1), False
            out[cur] = {}
            continue
        if cur is None:
            continue
        m = re.match(r"^\s+player_list:\s*(\{.*\})?\s*$", line)
        if m:
            inblock = not m.group(1)
            pairs = re.findall(r"(\w+): ([^,{}\[\]]+)", m.group(1) or "")
        elif inblock and re.match(r"^\s{6,}\w+: ", line):
            pairs = [re.match(r"^\s+(\w+): (.*)$", line).groups()]
        else:
            inblock = inblock and line.startswith("      ")
            continue
        for k, v in pairs:
            v = v.strip().strip('"')
            if k in ("plays", "height_cm", "gender"):
                out[cur][k] = int(v) if v.isdigit() else v
    return out


# =========================================================================== animation rules for the browser

def cmd_animrules(a):
    import anim_rules as R
    import ts4_xbin as X
    lay_buf = open(a.layout, "rb").read()
    layout = X.Layout(lay_buf)
    names = R.load_names(a.core, a.names)
    n = R.Namer(names)
    db_buf = open(os.path.join(a.core, R.ANIMDB + ".bin"), "rb").read()
    sa_buf = open(os.path.join(a.core, R.SWINGANIM + ".bin"), "rb").read()
    db = R.animdb_blocks(db_buf, R.Leaves(db_buf, layout, names), n)
    sa = R.swinganim_blocks(sa_buf, R.Leaves(sa_buf, layout, names), n)
    out = anim_rules_json(db, sa)
    out["sources"] = {"AnimationsDB.bin": [len(db_buf), sha256(db_buf)], "swinganimation.bin": [len(sa_buf), sha256(sa_buf)]}
    os.makedirs(os.path.dirname(a.out) or ".", exist_ok=True)
    with open(a.out, "w") as f:
        json.dump(out, f, separators=(",", ":"))
    print("wrote %s: %d clips, %d groups, %d move sets, %d bytes" % (a.out, len(out["clips"]), len(out["groups"]),
                                                                      len(out["movesets"]), os.path.getsize(a.out)))


def anim_rules_json(db, sa):
    """The subset of the animation tables the browser animator needs (pure; db/sa as anim_rules.py builds them).

    clips[i] is AnimationsDB record i: frames, group / subgroup, SpeedCoef, IgnoreSpeedCoef, NoMirror, AnimEvents
    [id, pos, duration, orientation], TransitionEvents [direction mask, pace mask, position, duration, reactivity,
    start blend, in, out], RotY behaviour and the gameplay qualifiers."""
    clips = []
    for r in db["animations"]:
        c = {"i": r.get("i"), "name": r.get("name"), "frames": r.get("frames"), "group": r.get("group"),
             "sub": r.get("subgroup"), "setup": r.get("setup"), "speed_coef": r.get("speed_coef"),
             "ignore_speed_coef": bool(r.get("ignore_speed_coef")), "no_mirror": bool(r.get("no_mirror"))}
        if r.get("serve_drop_time"):
            c["serve_drop_time"] = r["serve_drop_time"]
        if r.get("events"):
            c["ev"] = [list(e) for e in r["events"]]
        if r.get("transitions"):
            c["tr"] = r["transitions"]
        if r.get("roty"):
            c["roty"] = r["roty"]
        q = r.get("q") or {}
        keep = {k: q[k] for k in ("Category", "SwingType", "SwingCategory", "PositionOnCourt", "Properties", "Timing",
                                  "SwingEffect", "Surface", "TransitionQuality", "SplitSteps") if k in q}
        if keep:
            c["q"] = keep
        clips.append(c)
    groups = []
    for gr in db.get("groups", []):
        groups.append({k: gr.get(k) for k in ("setup", "index", "id", "first", "count", "allow_speed_coef")} |
                      {"subgroups": [{k: s_.get(k) for k in ("id", "first", "count", "abs")} for s_ in gr.get("subgroups", [])]})

    def sectors(lst):
        return [{"group": row[0], "sub": row[1]} | ({"alt": sectors(extra["sub"])} if extra.get("sub") else {})
                for row, extra in lst]
    movesets = [{"id": m.get("id"), "kind": m.get("kind"), "sectors": sectors(m.get("sectors") or [])}
                for m in sa.get("movesets", [])]
    size, sparse = db.get("matrix") or (0, {})
    return {"parameters": db.get("parameters"), "clips": clips, "groups": groups, "movesets": movesets,
            "transition_rules": db.get("transition_rules") or [],
            "transition_matrix": {"size": size, "rows": {str(k): v for k, v in sparse.items()}},
            "height_steps": sa.get("height_steps"),
            "notes": "AnimationsDB records (index = record index) and move sets; docs/gameplay/movement-and-animation.md"}



# =========================================================================== AOD clips (CutScenes.arc) for the browser

def record_chains(clip_map, records):
    """clip_map.json (tools/port/clip_map.py, with cutscenes) -> {record: {"core": n | None, "aod": key | None}}
    for the single-chain records: Core only, AOD only, or Core lead-in then AOD (pure)."""
    out = {}
    rows = {r.get("index"): r for r in clip_map.get("records", []) if isinstance(r, dict)}
    for rec in records:
        r = rows.get(rec)
        if r and r.get("variants"):
            v = r["variants"][0]
            core = v.get("core_index") if v.get("kind") in ("core", "core+aod") else None
            aod = v.get("aod_key") if v.get("kind") in ("aod", "core+aod") else None
            if core is not None or aod:
                out[rec] = {"core": core, "aod": aod, "kind": v.get("kind")}
            continue
        m = clip_map.get("map", {}).get("#%d" % rec)
        if isinstance(m, str) and m.startswith("core:"):
            out[rec] = {"core": int(m[5:]), "aod": None, "kind": "core"}
    return out


def cmd_aodclips(a):
    import classes
    import gltf_export
    import packfile
    import scan_arcs
    import skeleton
    import xdvdfs
    cm = json.load(open(a.clip_map))
    recs = [int(x) for x in re.split(r"[,\s]+", open(a.records).read().strip()) if x] if a.records else []
    chains = record_chains(cm, recs)
    want = sorted({c["aod"] for c in chains.values() if c["aod"]})
    x = xdvdfs.XDVDFS(iso_path(a))
    arc = scan_arcs.NilArc(x.open_slice("CutScenes.arc"))
    by_key = {e[0]: e for e in arc.entries}
    files = {}
    for key in want:
        k = int(key, 16) if isinstance(key, str) else int(key)
        out = os.path.join(a.out, "clips", "aod_%08x.gltf" % k)
        if not os.path.exists(out):
            e = by_key.get(k)
            if not e:
                continue
            arc.f.seek(arc.data_start + e[1])
            data = arc.f.read(e[2])
            pf = packfile.Packfile(data)
            reg = classes.Registry.from_packfile(pf)
            skels, anims = skeleton.load(pf, reg)
            clips = [skeleton.load_clip(pf, reg, anims[0], 0)]
            gltf_export.export(out, skels[0], clips, 0.01, True, name="aod_%08x" % k)
        files["%08x" % k] = "clips/aod_%08x.gltf" % k
    lead = sorted({c["core"] for c in chains.values() if c["core"] is not None})
    idx = {"chains": {str(r): c for r, c in sorted(chains.items())}, "aod_files": files, "core_needed": lead,
           "generated_by": "python3 tools/ts4_players.py aodclips --records FILE"}
    os.makedirs(os.path.join(a.out, "players"), exist_ok=True)
    with open(os.path.join(a.out, "players", "clip_chains.json"), "w") as f:
        json.dump(idx, f, indent=1)
    print("%d records: %d AOD clips exported, %d Core clips needed (export them with tools/port/export_assets.py "
          "--only havok animdb --core-clips %s)" % (len(chains), len(files), len(lead), ",".join(map(str, lead))))

# =========================================================================== CLI

def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--iso", help="disc image (default $TS4_ISO or orig/54540859/[disc_archive/]*.iso)")
    ap.add_argument("--core", default=os.path.join(ROOT, "work", "disc", "core_all"),
                    help="folder of extracted Core.arc members (<hash>.bin)")
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("roster")
    p.add_argument("arcs", nargs="*")
    p.add_argument("--out", default="data/gameplay/pro_roster.yaml")
    p = sub.add_parser("creator")
    p.add_argument("--out", default="data/gameplay/creator_options.yaml")
    p = sub.add_parser("export")
    p.add_argument("arcs", nargs="*")
    p.add_argument("--all", action="store_true")
    p.add_argument("--out", default="work/port/assets/players")
    p.add_argument("--roster", default="data/gameplay/pro_roster.yaml", help="handedness / height for index.json")
    p.add_argument("--variants", action="store_true", help="also decode sweat / clay / grass texture variants (slow)")
    p.add_argument("--no-normal", action="store_true", help="skip the bump (normal) maps")
    p.add_argument("--skip-existing", action="store_true")
    p.add_argument("--skeleton-hkx")
    p.add_argument("--skeleton-source", choices=["core", "cutscene"], default="core")
    p.add_argument("--skeleton-index", type=int, default=0)
    p = sub.add_parser("animrules")
    p.add_argument("--out", default="work/port/assets/players/anim_rules.json")
    p.add_argument("--layout", default=os.path.join(ROOT, "work", "disc", "root", "Layoutall.bin"))
    p.add_argument("--names", default=os.path.join(ROOT, "work", "disc", "values", "names.json"))
    p = sub.add_parser("aodclips")
    p.add_argument("--records", help="file with record indexes (comma / space separated)")
    p.add_argument("--clip-map", default=os.path.join(ROOT, "work", "port", "assets", "clip_map.json"))
    p.add_argument("--out", default=os.path.join(ROOT, "work", "port", "assets"))
    a = ap.parse_args(argv)
    if a.cmd == "export" and not a.arcs and not a.all:
        ap.error("export: name archives or pass --all")
    {"roster": cmd_roster, "creator": cmd_creator, "export": cmd_export, "animrules": cmd_animrules,
     "aodclips": cmd_aodclips}[a.cmd](a)


if __name__ == "__main__":
    main()
