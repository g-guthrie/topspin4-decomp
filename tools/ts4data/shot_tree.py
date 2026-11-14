#!/usr/bin/env python3
"""Controller-to-shot extractor for Top Spin 4 (Xbox 360), standard library only.

Writes everything the shot-selection path reads from data into one YAML file:

* the shot-selection decision tree of ``Settings.bin`` (every node, its condition, the PlayerState
  byte it tests, every leaf with its shot id and template row),
* the template row id table (row index <-> unique id ``row+0x88`` <-> template name),
* the InputMapper config (pad buttons and stick channels -> XData outputs, dead zones, scales),
* the charge / power curves (``cfg+0x8FC..0x920``) and the 0.4 / 0.7 tier constants,
* the tier rule graphs of ``Expressions.bin`` (Finesse / Medium / Powerful / PowerfulBall /
  GoodTiming / Wood) and the tier intervals they imply,
* with ``--layout Layoutall.bin``: the PlayerState byte offset of every XData path used above,
  resolved through the reflected type layouts (PlayerState = the 0x1070-byte type that holds
  ``ShotSelection`` at 0x400).

Format notes (big-endian; ``rel`` = signed 32-bit offset from the field that holds it, -1 = null):

  Settings.bin root typed struct ``cfg`` = file 0x24 (docs/gameplay/shot-to-template.md s1)
    cfg+0x00 {rel, 0x48BFC8B8}     tree root node
    cfg+0x08 {rel, count, cap}     template rows, 0x8C bytes each, row id at row+0x88
    cfg+0x8E0 {rel, count, cap}    InputMapper configs (0x40 bytes each)
    cfg+0x8FC/0x908/0x914/0x920    curve16 {rel,count,cap} -> keys {x0, x1, y0, y1}
    cfg+0xC70/0xC74                f32 0.4 / 0.7
  tree node  {rel children, 2, 2, condition crc32, rel path string, pre-order index}
             child = {rel, type}: type 0x48BFC8B8 = node, 0x2C3F7780 = leaf {shot id, row index}
             child 0 is taken when the condition byte is 1, child 1 otherwise (fn_8865A938)

Usage:
  shot_tree.py --settings 334e7e0d.bin --expressions fa94f637.bin [--layout Layoutall.bin] \
               [--out data/gameplay/shot_tree.yaml]
  shot_tree.py --selftest
"""
from __future__ import annotations

import argparse
import hashlib
import os
import struct
import sys
import zlib

NODE_TYPE = 0x48BFC8B8
LEAF_TYPE = 0x2C3F7780
CFG = 0x24
ROW_SIZE = 0x8C

BUTTON_ITEM = {0x992C138B: "level", 0x32B69F1A: "press", 0xEA646810: "release"}
STICK_ITEM = {0x8312E402: "cartesian", 0xB8ED75CD: "polar", 0xA31497B5: "direction"}

# Pad slot ids of fn_888854B0 / key table lbl_88C6B760 (docs/gameplay/input-to-shot.md s1, s2.2).
BUTTON_KEYS = {0x31DFDD4F: "A", 0xA8D68CF5: "B", 0xDFD1BC63: "X", 0x41B529C0: "Y", 0xEA3CEC17: "LB",
               0xFC84626D: "RB", 0x7335BDAD: "LT", 0x658D33D7: "RT", 0x17E7A91F: "LeftStickClick",
               0x60E09989: "RightStickClick", 0x5EB87A8B: "Start", 0xCDFC6E09: "Back"}
AXIS_KEYS = {0xF113E7BB: "DPadX", 0xF0D18D8C: "DPadY", 0x681AB601: "LeftX", 0x69D8DC36: "LeftY",
             0x1F1D8697: "RightX", 0x1EDFECA0: "RightY", 0xD47EB74D: "AnyX", 0x4971563B: "AnyY"}

# The InputMapper paths are relative to PlayerState.InputState (S+0x40C); the tree paths to PlayerState.
INPUT_BASE = "InputState"

# Graphs of Expressions.bin that decide the power tier and the related rule outputs.
TIER_GRAPHS = ["Finesse", "Medium", "Powerful", "PowerfulBall", "GoodTiming", "Wood"]


def crc(s: str) -> int:
    return zlib.crc32(s.encode("latin1")) & 0xFFFFFFFF


def _names():
    """Names for every hash this extractor prints (each verified by crc32 at import)."""
    words = []
    for stroke in ("Flat", "TopSpin", "Slice", "Lob"):
        for tier in ("Finesse", "Medium", "Powerful", "Risky", "RiskyFinesse", "Normal"):
            words.append(stroke + tier)
    words += ["TopSpinVolley", "SliceVolley", "FlatVolley", "DropVolley", "PowerVolley", "DropShotNormal",
              "SmashNormal", "DefensiveShot", "Wood", "WoodDown", "LobNormal", "ServeNormal", "ServeSlice",
              "ServeAdvanced", "FlatReturn", "Flat", "TopSpin", "Slice", "Lob", "Smash", "DropShot",
              "Up", "Down", "Left", "Right"]
    for c in ("IsWoodDown", "IsWood", "IsClassicServe", "IsAdvancedServe", "IsSmash", "IsBaseLine",
              "IsPowerful", "IsMedium", "IsTopSpin", "IsSlice", "IsLob", "IsRisk", "IsFlat"):
        words.append(c)
    return {crc(w): w for w in words}


NAMES = _names()


def nm(h):
    return NAMES.get(h)


class Buf:
    def __init__(self, data: bytes):
        self.d = data

    def u32(self, a):
        return struct.unpack_from(">I", self.d, a)[0]

    def i32(self, a):
        return struct.unpack_from(">i", self.d, a)[0]

    def f32(self, a):
        return struct.unpack_from(">f", self.d, a)[0]

    def rel(self, a):
        r = self.i32(a)
        return None if r == -1 else a + r

    def arr(self, a):
        """{rel, count, cap} -> (first element address, count)."""
        p = self.rel(a)
        return (p, self.u32(a + 4)) if p is not None else (None, 0)

    def cstr(self, a):
        if a is None:
            return None
        e = self.d.index(b"\0", a)
        return self.d[a:e].decode("latin1")


# ----------------------------------------------------------------------------- layout (PlayerState)

class Layout:
    """Reflected type layouts of Layoutall.bin (docs/disc-data.md s3, refined here).

    Type records: 0x40 bytes, array {rel, count, cap} at file 0x20 (0xCCC, 3642 records), word 12 =
    type crc, word 13 = size; word 6/7 = {rel (from record+0x18), count} of 7-word scalar field
    records {type, size<<16, next name, OFFSET, type, NAME, align}; word 9/10 = {rel (from
    record+0x24), count} of 9-word field records {TYPE, size<<16, NEXT, ?, kind, NAME, OFFSET,
    align, 0}.  The type crc of a field is stored with the field that *precedes* it in the list
    (the {type, next name} pair), and in record words 0..5 for the first field of each kind.
    """

    def __init__(self, data: bytes):
        b = Buf(data)
        first, count = b.arr(0x20)          # root array of type records (0x40 bytes each)
        self.types = {}
        for i in range(count):
            o = first + 0x40 * i
            if o + 0x40 > len(data):
                break
            w = struct.unpack_from(">16I", data, o)
            fields, ftypes = {}, {w[2]: w[0], w[5]: w[3]}
            if w[7] and w[6] != 0xFFFFFFFF:
                base = (o + 0x18 + w[6]) & 0xFFFFFFFF
                for j in range(w[7]):
                    r = struct.unpack_from(">7I", data, base + 28 * j)
                    fields[r[5]] = r[3]
                    ftypes[r[2]] = r[0]
            if w[10] and w[9] != 0xFFFFFFFF:
                base = (o + 0x24 + w[9]) & 0xFFFFFFFF
                for j in range(w[10]):
                    r = struct.unpack_from(">9I", data, base + 36 * j)
                    fields[r[5]] = r[6]
                    ftypes[r[2]] = r[0]
            self.types.setdefault(w[12], []).append((w[13], fields, ftypes))
        roots = [t for t, vs in self.types.items() for v in vs
                 if v[0] == 0x1070 and v[1].get(crc("ShotSelection")) == 0x400]
        self.player_state = roots[0] if roots else None

    def resolve(self, path):
        """'A/B/@C' relative to PlayerState -> byte offset, or None."""
        t, ofs = self.player_state, 0
        if t is None:
            return None
        for part in path.replace("@", "").split("/"):
            if "[" in part:
                # Shot[@Id="Flat"]: an element of the enclosing list (Shots / ShotTriggers), found at
                # run time by Id; report the list descriptor's offset.
                return ofs
            h = crc(part)
            hit = next((v for v in self.types.get(t, []) if h in v[1]), None)
            if hit is None:
                return None
            ofs += hit[1][h]
            t = hit[2].get(h)
        return ofs


# ----------------------------------------------------------------------------- Settings.bin

def read_rows(b: Buf):
    first, n = b.arr(CFG + 8)
    rows = []
    for i in range(n):
        r = first + ROW_SIZE * i
        rows.append({"index": i, "file_offset": r, "id": b.u32(r + 0x88), "template": b.u32(r + 4),
                     "ball_0x360": r - CFG})
    return rows


def read_tree(b: Buf, rows, layout=None):
    """Pre-order walk (child 0 = condition true first), exactly the numbering of fn_8865A9C8."""
    by_id = {r["id"]: r["index"] for r in rows}
    nodes, leaves = [], []

    def child(addr):
        p = b.rel(addr)
        t = b.u32(addr + 4)
        if t == NODE_TYPE:
            return {"node": walk(p)}
        sid = b.u32(p)
        leaf = {"leaf": len(leaves), "id": sid, "name": nm(sid), "row": by_id.get(sid)}
        leaves.append(leaf)
        return leaf

    def walk(n):
        idx = len(nodes)
        rec = {"index": idx, "file_offset": n, "condition": b.u32(n + 0xC),
               "condition_name": nm(b.u32(n + 0xC)), "path": b.cstr(b.rel(n + 0x10))}
        if layout is not None and rec["path"]:
            rec["playerstate_offset"] = layout.resolve(rec["path"])
        nodes.append(rec)
        kids, count = b.rel(n), b.u32(n + 4)
        rec["if_true"] = child(kids)
        rec["if_false"] = child(kids + 8) if count > 1 else None
        return idx

    root = b.rel(CFG)
    if b.u32(CFG + 4) != NODE_TYPE:
        raise ValueError("cfg+4 is not the tree node type")
    walk(root)
    return nodes, leaves


def read_curve16(b: Buf, a):
    p, n = b.arr(a)
    return [[b.f32(p + 16 * k + 4 * j) for j in range(4)] for k in range(n)] if p else []


def eval_curve16(keys, x):
    """fn_881899D8: last key with x0 <= x (first if none), t = clamp(x - x0, 0, x1 - x0)/(x1 - x0)."""
    k = keys[0]
    for key in keys:
        if key[0] <= x:
            k = key
        else:
            break
    x0, x1, y0, y1 = k
    d = min(max(x - x0, 0.0), x1 - x0)
    return y0 + (d / (x1 - x0)) * (y1 - y0)


def read_input_mapper(b: Buf, layout=None):
    first, n = b.arr(CFG + 0x8E0)
    out = []
    for i in range(n):
        root = first + 0x40 * i
        cfg = {"file_offset": root, "root_floats": [b.f32(root + 0x30), b.f32(root + 0x34)],
               "root_words": [b.u32(root + 0x38), b.u32(root + 0x3C)], "buttons": [], "sticks": []}

        def path_info(a):
            s = b.cstr(b.rel(a))
            d = {"path": s}
            if layout is not None and s:
                d["playerstate_offset"] = layout.resolve(INPUT_BASE + "/" + s)
            return d

        bp, bn = b.arr(root)
        for k in range(bn):
            e = bp + 0x10 * k
            key = b.u32(e + 0xC)
            ent = {"key": key, "control": BUTTON_KEYS.get(key), "outputs": []}
            ip, ic = b.arr(e)
            for j in range(ic):
                it = ip + 8 * j
                rec, t = b.rel(it), b.u32(it + 4)
                kind = BUTTON_ITEM.get(t, "%08x" % t)
                if kind == "level":
                    o = {"kind": kind, "invert": b.u32(rec) & 0xFF}
                    o.update(path_info(rec + 4))
                else:
                    o = {"kind": kind}
                    o.update(path_info(rec))
                ent["outputs"].append(o)
            cfg["buttons"].append(ent)
        cp, cn = b.arr(root + 0xC)
        for k in range(cn):
            e = cp + 0x18 * k
            ent = {"axis_x": AXIS_KEYS.get(b.u32(e + 0xC), "%08x" % b.u32(e + 0xC)),
                   "axis_y": AXIS_KEYS.get(b.u32(e + 0x10), "%08x" % b.u32(e + 0x10)),
                   "dead_zone": b.f32(e + 0x14), "outputs": []}
            ip, ic = b.arr(e)
            for j in range(ic):
                it = ip + 8 * j
                rec, t = b.rel(it), b.u32(it + 4)
                kind = STICK_ITEM.get(t, "%08x" % t)
                o = {"kind": kind}
                if kind == "direction":
                    o["direction"] = nm(b.u32(rec + 0x10)) or "%08x" % b.u32(rec + 0x10)
                    o["threshold"] = b.f32(rec + 0x14)
                    o["scale"] = b.f32(rec + 0x18)
                    o.update(path_info(rec + 0x1C))
                else:
                    # +0/+4: two words (0x28 or -1); meaning not decoded (smoothing per
                    # input-to-shot.md s2.3, unverified), kept raw
                    o["header_words"] = [b.i32(rec), b.i32(rec + 4)]
                    o["first"] = path_info(rec + 8)
                    o["second"] = path_info(rec + 0xC)
                    o["range"] = [b.f32(rec + 0x10), b.f32(rec + 0x14)]
                    o["extra"] = [b.f32(rec + 0x18), b.f32(rec + 0x1C)]
                ent["outputs"].append(o)
            cfg["sticks"].append(ent)
        out.append(cfg)
    return out


# ----------------------------------------------------------------------------- Expressions.bin

def read_tier_graphs(expr: bytes):
    here = os.path.dirname(os.path.abspath(__file__))
    sys.path.insert(0, os.path.join(here, ".."))
    import ts4_analyser as A  # noqa: E402  (stdlib-only sibling tool)
    graphs = A.parse_expressions(expr)
    names = A.known_names()
    by = {g.name: g for g in graphs}
    out = {}
    for n in TIER_GRAPHS:
        g = by.get(crc(n))
        if g is None:
            continue

        def port(p):
            return {"domain": "%08x" % p.domain, "path": [names.get(h, "%08x" % h) for h in p.path],
                    "cell": p.index, "register": p.slot}
        out[n] = {"inputs": [port(p) for p in g.inputs], "outputs": [port(p) for p in g.outputs],
                  "nodes": [dict(kind=x.kind, **{k: (list(v) if isinstance(v, (list, tuple)) else v)
                                                 for k, v in x.fields.items()}) for x in g.nodes]}
    return out


def tier_intervals(graphs):
    """The three tier graphs are single CURVE nodes of the same input (power, S+0xE00).  A tier
    flag is set when the graph output is > 0.5 (fn_886872A0), so each tier is the union of the
    key segments whose y0 > 0.5 (all retail keys have slope 0, so y0 is the whole segment)."""
    res = {}
    for n in ("Finesse", "Medium", "Powerful"):
        g = graphs.get(n)
        if not g or len(g["nodes"]) != 1 or g["nodes"][0]["kind"] != "CURVE":
            continue
        keys = g["nodes"][0]["keys"]
        res[n] = [[k[0], k[1]] for k in keys if k[2] > 0.5]
    return res


# ----------------------------------------------------------------------------- YAML

def _scalar(v):
    if v is None:
        return "null"
    if isinstance(v, bool):
        return "true" if v else "false"
    if isinstance(v, int):
        return str(v)
    if isinstance(v, float):
        if v != v or abs(v) > 3.4e38:
            return repr(v)
        want = struct.pack(">f", v)
        for digits in range(6, 10):           # shortest text that round-trips as a float32
            t = "%.*g" % (digits, v)
            if struct.pack(">f", float(t)) == want:
                return t if any(c in t for c in ".en") else t + ".0"
        return repr(v)
    s = str(v)
    if s == "" or any(c in s for c in ':#{}[],&*!|>\'"%@`') or s.strip() != s:
        return '"' + s.replace("\\", "\\\\").replace('"', '\\"') + '"'
    return s


def to_yaml(obj, indent=0):
    pad = "  " * indent
    lines = []
    if isinstance(obj, dict):
        for k, v in obj.items():
            if isinstance(v, (dict, list)) and v and not _flat(v):
                lines.append("%s%s:" % (pad, k))
                lines.append(to_yaml(v, indent + 1))
            else:
                lines.append("%s%s: %s" % (pad, k, _inline(v)))
    elif isinstance(obj, list):
        for v in obj:
            if isinstance(v, dict) and v:
                sub = to_yaml(v, indent + 1).split("\n")
                lines.append("%s- %s" % (pad, sub[0].strip()))
                lines.extend(sub[1:])
            elif isinstance(v, list) and v and not _flat(v):
                lines.append("%s-" % pad)
                lines.append(to_yaml(v, indent + 1))
            else:
                lines.append("%s- %s" % (pad, _inline(v)))
    return "\n".join(lines)


def _flat(v):
    if isinstance(v, list):
        return all(not isinstance(x, (dict, list)) or (isinstance(x, list) and _flat(x) and len(x) <= 5)
                   for x in v) and len(v) <= 16
    return False


def _inline(v):
    if isinstance(v, list):
        return "[" + ", ".join(_inline(x) for x in v) + "]"
    if isinstance(v, dict):
        return "{" + ", ".join("%s: %s" % (k, _inline(x)) for k, x in v.items()) + "}"
    return _scalar(v)


def hexify(obj, keys=("condition", "id", "template", "key", "file_offset", "playerstate_offset",
                      "ball_0x360")):
    """Hash and offset fields read better in hex."""
    if isinstance(obj, dict):
        return {k: ("0x%08x" % v if k in ("condition", "id", "template", "key") and isinstance(v, int)
                    else "0x%x" % v if k in keys and isinstance(v, int) else hexify(v))
                for k, v in obj.items()}
    if isinstance(obj, list):
        return [hexify(x) for x in obj]
    return obj


def tree_text(nodes):
    """Indented one-line-per-node rendering (also used by the doc)."""
    out = []

    def leaf(c):
        return "%s (row %s)" % (c["name"] or "0x%08x" % c["id"], c["row"])

    def rec(i, depth):
        n = nodes[i]
        cond = n["condition_name"] or "0x%08x" % n["condition"]
        out.append("%s%s ?" % ("  " * depth, cond))
        for lab in ("if_true", "if_false"):
            c = n[lab]
            tag = "T" if lab == "if_true" else "F"
            if c is None:
                continue
            if "node" in c:
                out.append("%s%s:" % ("  " * (depth + 1), tag))
                rec(c["node"], depth + 2)
            else:
                out.append("%s%s: %s" % ("  " * (depth + 1), tag, leaf(c)))
    rec(0, 0)
    return out


def tree_flat(nodes, power, intervals):
    """Line format read by ref/gameplay/shot_select.c (no YAML parser needed in C):
         node <index> <condition crc32 hex> <true child> <false child>
         child = n<node index> | l<shot id hex>:<row index or -1>
         power_curve <x0> <x1> <y0> <y1>        (cfg+0x8FC, curve16 key)
         tier <Finesse|Medium|Powerful> <lo> <hi>  (power interval where that tier graph is > 0.5)
    """
    def ch(c):
        if c is None:
            return "-"
        if "node" in c:
            return "n%d" % c["node"]
        return "l%08x:%d" % (c["id"], -1 if c["row"] is None else c["row"])
    out = ["node %d %08x %s %s" % (n["index"], n["condition"], ch(n["if_true"]), ch(n["if_false"]))
           for n in nodes]
    for k in power.get("power_curve_default_cfg_0x8fc", []):
        out.append("power_curve %s %s %s %s" % tuple(_scalar(v) for v in k))
    for name, ivs in intervals.items():
        for lo, hi in ivs:
            out.append("tier %s %s %s" % (name, _scalar(lo), _scalar(hi)))
    return out


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def extract(settings: bytes, expressions: bytes | None, layout_bytes: bytes | None):
    b = Buf(settings)
    layout = Layout(layout_bytes) if layout_bytes else None
    rows = read_rows(b)
    nodes, leaves = read_tree(b, rows, layout)
    reachable = {lf["row"] for lf in leaves}
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import templates as T  # noqa: E402  (sibling decoder; template family names)
    tnames = T.name_table()
    for r in rows:
        r["name"] = nm(r["id"])
        r["template_name"] = tnames.get(r["template"]) or nm(r["template"])
        r["reachable_from_tree"] = r["index"] in reachable
    power = {
        "power_curve_default_cfg_0x8fc": read_curve16(b, CFG + 0x8FC),
        "power2_curve_default_cfg_0x908": read_curve16(b, CFG + 0x908),
        "power_curve_alt_cfg_0x914": read_curve16(b, CFG + 0x914),
        "power2_curve_alt_cfg_0x920": read_curve16(b, CFG + 0x920),
        "cfg_0xc70": b.f32(CFG + 0xC70),
        "cfg_0xc74": b.f32(CFG + 0xC74),
    }
    data = {"tree_text": tree_text(nodes), "tree_nodes": nodes, "tree_leaves": leaves, "rows": rows,
            "power": power, "input_mapper": read_input_mapper(b, layout)}
    if expressions:
        g = read_tier_graphs(expressions)
        data["tier_graphs"] = g
        iv = tier_intervals(g)
        data["tier_intervals_on_power"] = iv
        # Power is curve(cfg+0x8FC)(frames / D); invert the (linear) curve for the tier edges.
        keys = power["power_curve_default_cfg_0x8fc"]
        if keys and len(keys) == 1 and keys[0][3] != keys[0][2]:
            x0, x1, y0, y1 = keys[0]
            edge = lambda p: x0 + (p - y0) * (x1 - x0) / (y1 - y0)  # noqa: E731
            data["tier_edges_in_frames_over_D"] = {n: [[edge(a), edge(c)] for a, c in v] for n, v in iv.items()}
    if layout is not None:
        paths = ["ShotSelection/Request/@" + n for n in ("IsFlat", "IsSlice", "IsTopSpin", "IsLob", "IsRisk",
                 "IsPowerful", "IsMedium", "IsClassicServe", "IsAdvancedServe", "IsSmash", "IsWood",
                 "IsWoodDown")]
        paths += ["Context/ShotContext/@ModeBaseLine", "InputState/Risk", "InputState/Rush",
                  "InputState/Buttons/A", "InputState/Buttons/PressA", "InputState/Buttons/ReleaseA",
                  "InputState/Stick_Aiming/X", "InputState/Stick_Move/X", "InputState/Stick_MovePolar/Power",
                  "InputState/Serve/Classic/Throw", "InputState/Serve/Advanced/Throw",
                  "InputState/Serve/Advanced/PolarStick/Power", "InputState/Serve/Advanced/CartesianStick/X",
                  "SwingSelection/Request/Power", "SwingSelection/EvaluationOutputs/GoodTiming",
                  "SwingSelection/EvaluationOutputs/Wood", "Context/IsServing", "Context/IsVolley",
                  "Context/IsSmash"]
        data["playerstate_paths"] = {p: (None if layout.resolve(p) is None else "0x%x" % layout.resolve(p))
                                     for p in paths}
    return data


def selftest():
    # synthetic Settings image: cfg at 0x24 with a 3-node tree and 3 rows
    img = bytearray(0x2000)

    def w32(a, v):
        struct.pack_into(">I", img, a, v & 0xFFFFFFFF)

    def wf(a, v):
        struct.pack_into(">f", img, a, v)
    rows_at, ids = 0x1000, [crc("FlatFinesse"), crc("TopSpinFinesse"), crc("SmashNormal")]
    w32(CFG + 8, rows_at - (CFG + 8))
    w32(CFG + 12, 3)
    for i, h in enumerate(ids):
        w32(rows_at + ROW_SIZE * i + 0x88, h)
    strings = 0x1800

    def node(at, cond, path, t_kind, t_at, f_kind, f_at):
        nonlocal strings
        w32(at, 0x18)
        w32(at + 4, 2)
        w32(at + 8, 2)
        w32(at + 0xC, crc(cond))
        img[strings:strings + len(path) + 1] = path.encode() + b"\0"
        w32(at + 0x10, strings - (at + 0x10))
        strings += len(path) + 1
        for k, (kind, tgt) in enumerate(((t_kind, t_at), (f_kind, f_at))):
            w32(at + 0x18 + 8 * k, tgt - (at + 0x18 + 8 * k))
            w32(at + 0x1C + 8 * k, kind)
    w32(CFG, 0x100 - CFG)
    w32(CFG + 4, NODE_TYPE)
    node(0x100, "IsSmash", "ShotSelection/Request/@IsSmash", LEAF_TYPE, 0x200, NODE_TYPE, 0x140)
    node(0x140, "IsTopSpin", "ShotSelection/Request/@IsTopSpin", LEAF_TYPE, 0x208, LEAF_TYPE, 0x210)
    w32(0x200, ids[2])
    w32(0x208, ids[1])
    w32(0x210, ids[0])
    w32(CFG + 0x8FC, 0x400 - (CFG + 0x8FC))
    w32(CFG + 0x900, 1)
    for k, v in enumerate((0.0, 1.25, 0.0, 1.0)):
        wf(0x400 + 4 * k, v)
    w32(CFG + 0x8E0, 0xFFFFFFFF)
    b = Buf(bytes(img))
    rows = read_rows(b)
    nodes, leaves = read_tree(b, rows)
    assert [n["condition_name"] for n in nodes] == ["IsSmash", "IsTopSpin"]
    assert [lf["row"] for lf in leaves] == [2, 1, 0], leaves
    assert tree_text(nodes)[1].strip() == "T: SmashNormal (row 2)"
    keys = read_curve16(b, CFG + 0x8FC)
    assert abs(eval_curve16(keys, 0.625) - 0.5) < 1e-6 and eval_curve16(keys, 9.0) == 1.0
    assert to_yaml({"a": [1, 2], "b": {"c": "x:y"}}) == 'a: [1, 2]\nb:\n  c: "x:y"'
    print("selftest ok")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--settings", help="Settings.bin (Core.arc entry 334e7e0d)")
    ap.add_argument("--expressions", help="Expressions.bin (Core.arc entry fa94f637)")
    ap.add_argument("--layout", help="Layoutall.bin (disc root) for PlayerState offsets")
    ap.add_argument("--out", default="data/gameplay/shot_tree.yaml")
    ap.add_argument("--selftest", action="store_true")
    a = ap.parse_args(argv)
    if a.selftest:
        selftest()
        return 0
    if not a.settings:
        ap.error("--settings is required")
    settings = open(a.settings, "rb").read()
    expr = open(a.expressions, "rb").read() if a.expressions else None
    lay = open(a.layout, "rb").read() if a.layout else None
    data = extract(settings, expr, lay)
    src = {"Settings.bin": {"path": a.settings, "size": len(settings), "sha256": sha256(settings)}}
    if expr:
        src["Expressions.bin"] = {"path": a.expressions, "size": len(expr), "sha256": sha256(expr)}
    if lay:
        src["Layoutall.bin"] = {"path": a.layout, "size": len(lay), "sha256": sha256(lay)}
    cmd = "python3 tools/ts4data/shot_tree.py " + " ".join(argv if argv is not None else sys.argv[1:])
    head = ["# Top Spin 4 (Xbox 360) controller-to-shot values: shot-selection tree, rows, input map,",
            "# power curves and tier graphs.  Generated; do not edit by hand.",
            "# Generator: %s" % cmd,
            "# Python %s" % sys.version.split()[0]]
    for k, v in src.items():
        head.append("# Source %s: %s bytes, sha256 %s" % (k, v["size"], v["sha256"]))
    head.append("# Docs: docs/gameplay/controls-and-shot-selection.md")
    body = to_yaml(hexify({"sources": src, **data}))
    os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
    with open(a.out, "w") as f:
        f.write("\n".join(head) + "\n" + body + "\n")
    flat = os.path.splitext(a.out)[0] + ".tree"
    with open(flat, "w") as f:
        f.write("\n".join(head) + "\n" + "\n".join(
            tree_flat(data["tree_nodes"], data["power"], data.get("tier_intervals_on_power", {}))) + "\n")
    print("wrote %s (%d nodes, %d leaves, %d rows)" % (a.out, len(data["tree_nodes"]),
                                                       len(data["tree_leaves"]), len(data["rows"])))
    return 0


if __name__ == "__main__":
    sys.exit(main())
