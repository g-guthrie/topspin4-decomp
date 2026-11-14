#!/usr/bin/env python3
"""Reference writer / reader for the ts4core data blob (docs/port/data-format.md), standard library only.

  ts4d.py registry                       print the tunable / role tables as markdown (used by the format doc)
  ts4d.py synthetic --out F [--no-graphs] [--no-templates-tree]
                                         game-free synthetic blob (made-up numbers) used by the tests and the
                                         wasm smoke test. Never contains game data.
  ts4d.py pack --tunables T.json [--templates Settings.bin] [--expressions Expressions.bin] --out F
                                         build a blob from a tunable JSON and (optionally) real game files;
                                         the result contains game bytes: keep it under work/, never commit it
  ts4d.py inspect F                      list the sections of a blob

The module is also a library: Blob, read_blob(), synthetic(), graphs_from_expressions(), the .def parsers.
"""
import argparse
import json
import math
import os
import re
import struct
import sys
import zlib

HERE = os.path.dirname(os.path.abspath(__file__))
CORE = os.path.dirname(HERE)
ROOT = os.path.dirname(os.path.dirname(CORE))
sys.path.insert(0, os.path.join(ROOT, "tools"))

KIND = {"CONST": 0, "SUM": 1, "PRODUCT": 2, "MIN": 3, "MAX": 4, "CURVE": 5, "RUNSUM": 6, "SUB": 7, "DIV": 8,
        "LERP": 9, "INVLERP": 10, None: 0xFFFFFFFF}
VARIADIC = ("SUM", "PRODUCT", "MIN", "MAX", "RUNSUM")


def crc(name):
    return zlib.crc32(name.encode("ascii")) & 0xFFFFFFFF


def f32(x):
    return struct.unpack("<f", struct.pack("<f", x))[0]


# ----------------------------------------------------------------------------- registries (.def files)
def parse_tunables(path=None):
    path = path or os.path.join(CORE, "include", "ts4_tunables.def")
    pat = re.compile(r'^TS4_TUN\(\s*(\w+),\s*"([^"]+)",\s*"([^"]*)",\s*(\w+),\s*(\w),\s*"(.*)"\)\s*$')
    out = []
    with open(path, encoding="utf-8") as f:
        for line in f:
            m = pat.match(line.strip())
            if m:
                out.append(dict(id=m.group(1), name=m.group(2), unit=m.group(3), origin=m.group(4),
                                req=m.group(5), source=m.group(6)))
    return out


def parse_roles(path=None):
    path = path or os.path.join(CORE, "include", "ts4_roles.def")
    vpat = re.compile(r'^TS4_VAR\(\s*(\w+),\s*"([^"]+)",\s*"(.*)"\)\s*$')
    rpat = re.compile(r'^TS4_ROLE\(\s*(\w+),\s*"([^"]+)",\s*"([^"]*)",\s*"(.*)"\)\s*$')
    vars_, roles = [], []
    with open(path, encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            m = vpat.match(line)
            if m:
                vars_.append(dict(id=m.group(1), name=m.group(2), doc=m.group(3)))
            m = rpat.match(line)
            if m:
                roles.append(dict(id=m.group(1), name=m.group(2), graph=m.group(3), doc=m.group(4)))
    return vars_, roles


def registry_markdown():
    t = parse_tunables()
    vars_, roles = parse_roles()
    lines = ["| name | unit | origin | req | source / meaning |", "|---|---|---|---|---|"]
    for e in t:
        lines.append("| `%s` | %s | %s | %s | %s |" % (e["name"], e["unit"], e["origin"], e["req"], e["source"]))
    tun = "\n".join(lines)
    lines = ["Roles (`ROLE` section, numeric id = position):", "", "| id | name | graph | when the sim runs it |", "|---|---|---|---|"]
    for i, r in enumerate(roles):
        lines.append("| %d | `%s` | %s | %s |" % (i, r["name"], r["graph"], r["doc"]))
    lines += ["", "Variables (numeric id = position):", "", "| id | name | meaning |", "|---|---|---|"]
    for i, v in enumerate(vars_):
        lines.append("| %d | `%s` | %s |" % (i, v["name"], v["doc"]))
    return tun, "\n".join(lines)


# ----------------------------------------------------------------------------- blob builder
class Blob:
    def __init__(self):
        self.tunables = {}      # name -> (value, provisional)
        self.templates = None   # (payload bytes, rows_offset, row_count, stride)
        self.tree = None        # (root, [(cond_hash, child_true, child_false)])
        self.graphs = []        # dicts, see add_graph
        self.roles = []         # (role_id, graph_hash, [in var ids], [out var ids])
        self.curves = []        # dicts name, type, keys | rows
        self.extra = []         # (tag, bytes)

    # -- tunables
    def set_tunables(self, d, provisional=True):
        for k, v in d.items():
            self.tunables[k] = (float(v), 1 if provisional else 0)

    # -- sections
    def _tune(self):
        items = sorted((crc(n), f32(v), flag) for n, (v, flag) in self.tunables.items())
        keys = [k for k, _, _ in items]
        if len(set(keys)) != len(keys):
            raise ValueError("tunable key collision")
        return struct.pack("<I", len(items)) + b"".join(struct.pack("<IfI", k, v, f) for k, v, f in items)

    def _tpls(self):
        payload, rows_off, rows, stride = self.templates
        pad = (-len(payload)) % 4
        return struct.pack("<IIII", rows, stride, rows_off, len(payload)) + payload + b"\0" * pad

    def _tree(self):
        root, nodes = self.tree
        return struct.pack("<II", len(nodes), root) + b"".join(struct.pack("<Iii", *n) for n in nodes)

    @staticmethod
    def _graph_bytes(g):
        ports = g["inputs"] + g["outputs"]
        head = 32
        ports_off = head
        nodes_off = ports_off + 16 * len(ports)
        extra = bytearray()
        extra_base = nodes_off + 32 * len(g["nodes"])
        nodes = bytearray()
        for nd in g["nodes"]:
            kind = nd["kind"]
            out = nd.get("out", 0)
            a = nd.get("a", 0)
            b = nd.get("b", 0)
            t = nd.get("t", 0)
            n = off = 0
            value = nd.get("value", 0.0)
            if kind in VARIADIC:
                n = len(nd["slots"])
                off = extra_base + len(extra)
                extra += b"".join(struct.pack("<I", s) for s in nd["slots"])
            elif kind == "CURVE":
                a = nd["in"]
                n = len(nd["keys"])
                off = extra_base + len(extra)
                for k in nd["keys"]:
                    extra += struct.pack("<ffff", *k[:4])
            nodes += struct.pack("<IiIIIIIf", KIND[kind], out, a, b, t, n, off, value)
        buf = struct.pack("<IIIIIIII", g["name_hash"], g["nregs"], len(g["inputs"]), len(g["outputs"]),
                          len(g["nodes"]), ports_off, nodes_off, 0)
        buf += b"".join(struct.pack("<IiII", *p) for p in ports) + bytes(nodes) + bytes(extra)
        return buf

    def _grph(self):
        recs = [self._graph_bytes(g) for g in self.graphs]
        dir_size = 4 + 12 * len(recs)
        off = dir_size
        d = struct.pack("<I", len(recs))
        body = b""
        for g, r in zip(self.graphs, recs):
            r += b"\0" * ((-len(r)) % 4)
            d += struct.pack("<III", g["name_hash"], off, len(r))
            body += r
            off += len(r)
        return d + body

    def _role(self):
        out = struct.pack("<I", len(self.roles))
        for rid, gh, ins, outs in self.roles:
            out += struct.pack("<IIII", rid, gh, len(ins), len(outs)) + b"".join(struct.pack("<I", v) for v in ins + outs)
        return out

    def _curv(self):
        recs = []
        for c in self.curves:
            if c["type"] in (0, 1):
                data = b"".join(struct.pack("<ffff", *k) for k in c["keys"])
                n = len(c["keys"])
            else:
                data = b""
                for a_key, keys in c["rows"]:
                    data += struct.pack("<fI", a_key, len(keys)) + b"".join(struct.pack("<ffff", *k) for k in keys)
                n = len(c["rows"])
            recs.append((c, n, data))
        dir_size = 4 + 16 * len(recs)
        off = dir_size
        d = struct.pack("<I", len(recs))
        body = b""
        for c, n, data in recs:
            d += struct.pack("<IIII", crc(c["name"]), c["type"], n, off)
            body += data
            off += len(data)
        return d + body

    def build(self):
        secs = []
        if self.tunables:
            secs.append((b"TUNE", self._tune()))
        if self.templates:
            secs.append((b"TPLS", self._tpls()))
        if self.tree:
            secs.append((b"TREE", self._tree()))
        if self.graphs:
            secs.append((b"GRPH", self._grph()))
        if self.roles:
            secs.append((b"ROLE", self._role()))
        if self.curves:
            secs.append((b"CURV", self._curv()))
        secs += self.extra
        off = 16 + 16 * len(secs)
        head = b"TS4D" + struct.pack("<III", 1, len(secs), 0)
        dirb = b""
        body = b""
        for tag, data in secs:
            data = data + b"\0" * ((-len(data)) % 4)
            dirb += tag + struct.pack("<III", off + len(body), len(data), 0)
            body += data
        return head + dirb + body


def read_blob(buf):
    """Parse a blob back into plain Python structures (for tests and `inspect`)."""
    if buf[:4] != b"TS4D":
        raise ValueError("bad magic")
    ver, n, _ = struct.unpack_from("<III", buf, 4)
    if ver != 1:
        raise ValueError("bad version")
    secs = {}
    for i in range(n):
        tag, off, size, _fl = struct.unpack_from("<4sIII", buf, 16 + 16 * i)
        secs[tag.decode("ascii")] = buf[off:off + size]
    out = {"sections": {k: len(v) for k, v in secs.items()}}
    if "TUNE" in secs:
        s = secs["TUNE"]
        cnt = struct.unpack_from("<I", s, 0)[0]
        out["tunables"] = {k: (v, fl) for k, v, fl in (struct.unpack_from("<IfI", s, 4 + 12 * i) for i in range(cnt))}
    if "TPLS" in secs:
        s = secs["TPLS"]
        rows, stride, roff, psz = struct.unpack_from("<IIII", s, 0)
        out["templates"] = dict(rows=rows, stride=stride, rows_offset=roff, payload_size=psz)
    if "TREE" in secs:
        s = secs["TREE"]
        cnt, root = struct.unpack_from("<II", s, 0)
        out["tree"] = dict(root=root, nodes=[struct.unpack_from("<Iii", s, 8 + 12 * i) for i in range(cnt)])
    if "GRPH" in secs:
        s = secs["GRPH"]
        cnt = struct.unpack_from("<I", s, 0)[0]
        out["graphs"] = [struct.unpack_from("<III", s, 4 + 12 * i) for i in range(cnt)]
    return out


# ----------------------------------------------------------------------------- Expressions.bin -> GRPH
def graphs_from_expressions(buf):
    """Convert a raw Expressions.bin image (or a synthetic one) into the GRPH graph dicts."""
    import ts4_analyser as A
    out = []
    for g in A.parse_expressions(buf):
        def port(p):
            key = zlib.crc32(b"".join(struct.pack(">I", h) for h in p.path)) & 0xFFFFFFFF if p.path else 0
            return (p.domain, p.index, p.slot, key)
        nodes = []
        for n in g.nodes:
            f = n.fields
            d = {"kind": n.kind}
            if n.kind in VARIADIC:
                d.update(slots=list(f["slots"]), out=f["out"])
            elif n.kind == "CURVE":
                d.update({"in": f["in"], "out": f["out"], "keys": [tuple(k[:4]) for k in f["keys"]]})
            elif n.kind in ("SUB", "DIV"):
                d.update(a=f["a"], b=f["b"], out=f["out"])
            elif n.kind in ("LERP", "INVLERP"):
                d.update(a=f["a"], b=f["b"], t=f["t"], out=f["out"])
            elif n.kind == "CONST":
                d.update(out=f["out"], value=f["value"])
            else:
                d = {"kind": None, "out": 0}
            nodes.append(d)
        out.append(dict(name_hash=g.name, nregs=g.nregs, inputs=[port(p) for p in g.inputs],
                        outputs=[port(p) for p in g.outputs], nodes=nodes))
    return out


# ----------------------------------------------------------------------------- big-endian template image
class BE:
    def __init__(self, size=0):
        self.b = bytearray(size)

    def put32(self, off, v):
        struct.pack_into(">I" if v >= 0 else ">i", self.b, off, v)

    def putf(self, off, v):
        struct.pack_into(">f", self.b, off, v)

    def alloc(self, n, align=4):
        while len(self.b) % align:
            self.b.append(0)
        off = len(self.b)
        self.b += b"\0" * n
        return off


NODE_CONST, NODE_CURVE20, NODE_TABLE2D = 0x33799CCE, 0xF9F12A60, 0x7A330099
K_DROP_TIME = 0x5D90675B
ROW_STRIDE = 0x8C


def synthetic_template_image(rows):
    """rows: list of dict(id, tau0, tau_slope, spin_a=(lo,hi), spin_b=(lo,hi), spin_c=(lo,hi)). Returns
    (payload, rows_offset). All values are made up; layout per docs/gameplay/gp4b.md."""
    rows_off = 0x40
    img = BE(rows_off + ROW_STRIDE * len(rows))
    for i, r in enumerate(rows):
        row = rows_off + i * ROW_STRIDE
        tpl = row + 0x18
        c = img.alloc(28)                                  # curve20 header + 1 key
        img.put32(c, 8); img.put32(c + 4, 1)
        for j, v in enumerate((0.0, 6000.0, r["tau0"], r["tau_slope"])):
            img.putf(c + 8 + 4 * j, v)
        img.put32(tpl + 0, c - tpl); img.put32(tpl + 4, NODE_CURVE20); img.put32(tpl + 8, K_DROP_TIME)
        sec = img.alloc(4)
        img.putf(sec, r.get("sec", 0.0))
        img.put32(tpl + 0xC, sec - (tpl + 0xC)); img.put32(tpl + 0x10, NODE_CONST); img.put32(tpl + 0x14, K_DROP_TIME)
        for field, key in ((0x18, "spin_a"), (0x24, "spin_c"), (0x30, "spin_b")):
            lo, hi = r.get(key, (0.0, 0.0))
            fl = img.alloc(8)
            img.putf(fl, lo); img.putf(fl + 4, hi)
            pair = img.alloc(16)
            img.put32(pair, fl - pair); img.put32(pair + 4, NODE_CONST)
            img.put32(pair + 8, fl + 4 - (pair + 8)); img.put32(pair + 12, NODE_CONST)
            img.put32(tpl + field, pair - (tpl + field))
        img.putf(row + 0x54, 1.0)                          # T
        for field, keys in ((0x40, [(-100.0, 100.0, 0.25, 0.25)]), (0x4C, [(-100.0, 100.0, 0.1, 0.1)]),
                            (0x58, [(0.0, 1.5708, 0.0, 1.2566)]), (0x64, [(-100.0, 100.0, 0.0, 0.0)])):
            k = img.alloc(16 * len(keys))
            for j, key in enumerate(keys):
                for m, v in enumerate(key):
                    img.putf(k + 16 * j + 4 * m, v)
            img.put32(tpl + field, k - (tpl + field)); img.put32(tpl + field + 4, len(keys))
        img.put32(row + 0x88, r["id"])
    return bytes(img.b), rows_off


SYN_ROWS = [
    dict(id=0xA0000001, tau0=0.25, tau_slope=0.00036),                                          # 0 flat
    dict(id=0xA0000002, tau0=0.30, tau_slope=0.00040, spin_a=(-0.1, -0.3)),                      # 1 topspin
    dict(id=0xA0000003, tau0=0.30, tau_slope=0.00044, spin_a=(0.1, 0.3)),                          # 2 slice
    dict(id=0xA0000004, tau0=1.40, tau_slope=0.00030, spin_a=(-0.05, -0.1)),                     # 3 lob
    dict(id=0xA0000005, tau0=0.10, tau_slope=0.00013),                                          # 4 serve flat
    dict(id=0xA0000006, tau0=0.20, tau_slope=0.00020, spin_a=(-0.1, -0.3)),                      # 5 serve kick
    dict(id=0xA0000007, tau0=0.15, tau_slope=0.00030),                                          # 6 volley
    dict(id=0xA0000008, tau0=0.08, tau_slope=0.00012),                                          # 7 smash
    dict(id=0xA0000009, tau0=0.18, tau_slope=0.00030),                                          # 8 flat powerful
]


def synthetic_tree():
    h = crc
    # node list: (cond, true, false); leaf = ~row
    n = []
    def add(c, t, f):
        n.append((h(c), t, f))
        return len(n) - 1
    # build bottom-up: indices are patched by construction order
    leaf = lambda r: ~r
    base = add("IsLob", leaf(3), 0)           # placeholder patched below
    topspin = add("IsTopSpin", leaf(1), 0)
    slice_ = add("IsSlice", leaf(2), 0)
    power = add("IsPowerful", leaf(8), leaf(0))
    n[base] = (h("IsLob"), leaf(3), topspin)
    n[topspin] = (h("IsTopSpin"), leaf(1), slice_)
    n[slice_] = (h("IsSlice"), leaf(2), power)
    serve_ts = add("IsTopSpin", leaf(5), leaf(4))
    is_base = add("IsBaseLine", base, leaf(6))
    is_smash = add("IsSmash", leaf(7), is_base)
    root = add("IsClassicServe", serve_ts, is_smash)
    return root, n


def _curve_graph(name, nin, keys_per_in, combine="PRODUCT"):
    """Tiny helper: out = combine(curve_i(in_i))."""
    nodes = []
    regs = nin
    outs = []
    for i, keys in enumerate(keys_per_in):
        nodes.append(dict(kind="CURVE", out=regs, keys=keys, **{"in": i}))
        outs.append(regs)
        regs += 1
    if len(outs) > 1:
        nodes.append(dict(kind=combine, slots=outs, out=regs))
        res = regs
        regs += 1
    else:
        res = outs[0]
    ins = [(0, 100 + i, i, 0) for i in range(nin)]
    return dict(name_hash=crc(name), nregs=regs, inputs=ins, outputs=[(0, 200, res, 0)], nodes=nodes)


def synthetic_graphs():
    """Graphs standing in for the game's analysers (all numbers invented)."""
    g = []
    # DefaultAttributes: 8 stats -> 8 profile values (identity / 100)
    nodes = [dict(kind="CURVE", out=8 + i, keys=[(0.0, 100.0, 0.0, 0.01, 0)], **{"in": i}) for i in range(8)]
    g.append(dict(name_hash=crc("DefaultAttributes"), nregs=16, inputs=[(0, 1, i, 0) for i in range(8)],
                  outputs=[(0, 2, 8 + i, 0) for i in range(8)], nodes=nodes))
    # ShotDifficulty: (dist_m, speed, unused) -> difficulty
    g.append(dict(name_hash=crc("ShotDifficulty"), nregs=8,
                  inputs=[(0, 1, 0, 0), (0, 2, 1, 0), (0, 3, 2, 0)], outputs=[(0, 4, 5, 0)],
                  nodes=[dict(kind="CURVE", out=3, keys=[(0.0, 30.0, 0.0, 0.03, 0)], **{"in": 1}),
                         dict(kind="CURVE", out=4, keys=[(0.0, 20.0, 0.0, 0.02, 0)], **{"in": 0}),
                         dict(kind="SUM", slots=[3, 4], out=5)]))
    # error: (difficulty, power, fatigue) -> probability
    g.append(dict(name_hash=crc("synthetic_error"), nregs=8,
                  inputs=[(0, 1, 0, 0), (0, 2, 1, 0), (0, 3, 2, 0)], outputs=[(0, 4, 6, 0)],
                  nodes=[dict(kind="CURVE", out=3, keys=[(0.0, 1.0, 0.04, 0.10, 0)], **{"in": 0}),
                         dict(kind="CURVE", out=4, keys=[(0.0, 1.0, 1.0, 0.5, 0)], **{"in": 1}),
                         dict(kind="PRODUCT", slots=[3, 4], out=6)]))
    g.append(_curve_graph("LetProbability", 1, [[(0.0, 1.0, 0.02, 0.0, 0)]]))
    # selection score: (reach speed, difficulty, notation) -> score in (0,1]
    for nm in ("synthetic_select_ground", "synthetic_select_volley"):
        g.append(dict(name_hash=crc(nm), nregs=8,
                      inputs=[(0, 1, 0, 0), (0, 2, 1, 0), (0, 3, 2, 0)], outputs=[(0, 4, 5, 0)],
                      nodes=[dict(kind="CURVE", out=3, keys=[(0.0, 50.0, 1.0, -0.02, 0)], **{"in": 0}),
                             dict(kind="CURVE", out=4, keys=[(0.0, 1.0, 1.0, -0.2, 0)], **{"in": 1}),
                             dict(kind="PRODUCT", slots=[3, 4], out=5)]))
    return g


def synthetic_roles(vnames):
    _, roles = parse_roles()
    rid = {r["name"]: i for i, r in enumerate(roles)}
    vid = {v: i for i, v in enumerate(vnames)}
    def role(name, graph, ins, outs):
        return (rid[name], crc(graph), [vid[v] for v in ins], [vid[v] for v in outs])
    return [
        role("default_attributes", "DefaultAttributes", ["stat.serve", "stat.return", "stat.forehand", "stat.backhand",
             "stat.volley", "stat.power", "stat.speed", "stat.stamina"], ["profile.%d" % i for i in range(8)]),
        role("shot_difficulty", "ShotDifficulty", ["ball.dist_m", "reach.speed", "zero"], ["ball.difficulty"]),
        role("shot_error", "synthetic_error", ["ball.difficulty", "shot.power", "fatigue.out"], ["error.prob"]),
        role("let_probability", "LetProbability", ["let.ctx.0"], ["let.prob"]),
        role("selection_ground", "synthetic_select_ground", ["reach.speed", "ball.difficulty", "input.notation"], ["selection.score"]),
        role("selection_volley", "synthetic_select_volley", ["reach.speed", "ball.difficulty", "input.notation"], ["selection.score"]),
    ]


def synthetic_curves():
    # validity margin tables: row key = distance cm, column = slack ticks (made up)
    def table(scale):
        rows = []
        for d in (0.0, 500.0, 1500.0):
            rows.append((d, [(0.0, 60.0, 0.0, 1.0 * scale)]))
        return dict(type=2, rows=rows)
    return [dict(name="move.table.rush", **table(1.0)), dict(name="move.table.jogjog", **table(1.2)),
            dict(name="move.table.jog", **table(1.5))]


def roles_from_json(entries, graph_names=()):
    """entries: [{"role": "shot_difficulty", "graph": "ShotDifficulty" | "0xDDA048F3", "in": [var names], "out": [var names]}]
    -> the (role id, graph hash, in ids, out ids) tuples of Blob.roles. Names are resolved with ts4_roles.def."""
    vars_, roles = parse_roles()
    rid = {r["name"]: i for i, r in enumerate(roles)}
    vid = {v["name"]: i for i, v in enumerate(vars_)}
    out = []
    for e in entries:
        g = e["graph"]
        gh = int(g, 16) if isinstance(g, str) and g.lower().startswith("0x") else crc(g)
        out.append((rid[e["role"]], gh, [vid[v] for v in e["in"]], [vid[v] for v in e["out"]]))
    return out


def provisional_tunables():
    with open(os.path.join(CORE, "data", "provisional.tunables.json"), encoding="utf-8") as f:
        d = json.load(f)
    return {k: v["value"] for k, v in d["tunables"].items()}


def synthetic(graphs=True, templates_tree=True):
    b = Blob()
    b.set_tunables(provisional_tunables(), provisional=True)
    if templates_tree:
        payload, roff = synthetic_template_image(SYN_ROWS)
        b.templates = (payload, roff, len(SYN_ROWS), ROW_STRIDE)
        b.tree = synthetic_tree()
    if graphs:
        vars_, _ = parse_roles()
        b.graphs = synthetic_graphs()
        b.roles = synthetic_roles([v["name"] for v in vars_])
    b.curves = synthetic_curves()
    return b


# ----------------------------------------------------------------------------- CLI
def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("registry")
    s = sub.add_parser("synthetic")
    s.add_argument("--out", required=True)
    s.add_argument("--no-graphs", action="store_true")
    s.add_argument("--no-templates-tree", action="store_true")
    p = sub.add_parser("pack")
    p.add_argument("--tunables", required=True)
    p.add_argument("--templates")
    p.add_argument("--rows-offset", type=lambda x: int(x, 0), default=0x137C)
    p.add_argument("--row-count", type=int, default=37)
    p.add_argument("--expressions")
    p.add_argument("--roles", help="JSON list of role bindings (see roles_from_json)")
    p.add_argument("--tree", help="JSON {\"root\": n, \"nodes\": [[cond_name_or_hash, child_true, child_false], ...]}")
    p.add_argument("--out", required=True)
    i = sub.add_parser("inspect")
    i.add_argument("file")
    a = ap.parse_args(argv)
    if a.cmd == "registry":
        t, r = registry_markdown()
        print(t)
        print()
        print(r)
    elif a.cmd == "synthetic":
        blob = synthetic(not a.no_graphs, not a.no_templates_tree).build()
        with open(a.out, "wb") as f:
            f.write(blob)
        print("wrote %s (%d bytes, synthetic: no game data)" % (a.out, len(blob)))
    elif a.cmd == "pack":
        b = Blob()
        with open(a.tunables, encoding="utf-8") as f:
            d = json.load(f)["tunables"]
        for k, v in d.items():
            b.tunables[k] = (float(v["value"]), 1 if v.get("provisional", True) else 0)
        if a.templates:
            with open(a.templates, "rb") as f:
                payload = f.read()
            b.templates = (payload, a.rows_offset, a.row_count, ROW_STRIDE)
        if a.expressions:
            with open(a.expressions, "rb") as f:
                b.graphs = graphs_from_expressions(f.read())
        if a.roles:
            with open(a.roles, encoding="utf-8") as f:
                b.roles = roles_from_json(json.load(f))
        if a.tree:
            with open(a.tree, encoding="utf-8") as f:
                t = json.load(f)
            b.tree = (t["root"], [((c if isinstance(c, int) else crc(c)), x, y) for c, x, y in t["nodes"]])
        with open(a.out, "wb") as f:
            f.write(b.build())
        print("wrote %s (contains game bytes if templates/expressions were given; do not commit)" % a.out)
    elif a.cmd == "inspect":
        with open(a.file, "rb") as f:
            print(json.dumps(read_blob(f.read()), indent=1, default=str))
    return 0


if __name__ == "__main__":
    sys.exit(main())
