#!/usr/bin/env python3
"""Writer for the ts4core data blob (format version 1, docs/port/data-format.md).

Builds, from the user's own Core.arc members, the sections the core needs for the ball/shot path and graph
evaluation:

  TPLS  verbatim copy of Settings.bin (big endian) with the row table location
  TREE  the shot request decision tree at Settings.bin 0x24, flattened, leaf ids resolved to row indices
  GRPH  analyser graphs from Expressions.bin in the normalised layout of section 5
  TUNE  scalar tunables the game data defines (ball block of State.bin, aim heights and tier thresholds in
        Settings.bin) merged under port-invented values from --tunables (port/core/data/provisional.tunables.json
        when present, flagged provisional)

ROLE (graph-to-variable binding) and CURV (movement margin tables) are research output of the core agent and are
not written here; the core reports the affected modules as degraded or missing. The blob is never committed: a
sidecar <blob>.manifest.json records the sha256 of every source member (AGENTS.md).

  python3 tools/port/blob_writer.py --settings Settings.bin --state State.bin --expressions Expressions.bin --out ts4core.dat
  (export_assets.py calls write_blob() with the members read from the disc image.)

Standard library only.
"""
import argparse
import hashlib
import json
import os
import re
import struct
import sys
import zlib

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
for _p in (HERE, os.path.join(ROOT, "tools"), os.path.join(ROOT, "tools", "ts4data")):
    if _p not in sys.path:
        sys.path.insert(0, _p)

BLOB_VERSION = 1
TREE_ROOT_OFF = 0x24
TYPE_NODE = 0x48BFC8B8
TYPE_LEAF = 0x2C3F7780
ROW_ID_OFF = 0x88
ROW_STRIDE = 0x8C
KIND_CODES = {"CONST": 0, "SUM": 1, "PRODUCT": 2, "MIN": 3, "MAX": 4, "CURVE": 5, "RUNSUM": 6, "SUB": 7,
              "DIV": 8, "LERP": 9, "INVLERP": 10}
UNKNOWN_KIND = 0xFFFFFFFF
VARIADIC = ("SUM", "PRODUCT", "MIN", "MAX", "RUNSUM")
TUNABLE_DEF = os.path.join(ROOT, "port", "core", "include", "ts4_tunables.def")
PROVISIONAL = os.path.join(ROOT, "port", "core", "data", "provisional.tunables.json")
FLAG_PROVISIONAL = 1


def crc32(name):
    return zlib.crc32(name.encode("ascii")) & 0xFFFFFFFF


def sha256(data):
    return hashlib.sha256(data).hexdigest()


# ----------------------------------------------------------------------------------------------- TPLS / TREE

def settings_rows(settings):
    """(first_row_offset, row_count) of the template table in a raw Settings.bin, found by structure."""
    import templates
    rows = templates.find_rows(templates.Buf(settings))
    if not rows:
        raise ValueError("no shot-template rows found in Settings.bin")
    rows.sort()
    start = rows[0]
    for i, r in enumerate(rows):
        if r != start + i * ROW_STRIDE:
            raise ValueError("template rows are not contiguous at row %d" % i)
    return start, len(rows)


def build_tpls(settings):
    """TPLS payload: the whole Settings.bin so every self-relative pointer keeps its distance (section 3)."""
    start, count = settings_rows(settings)
    payload = bytes(settings) + b"\0" * (-len(settings) % 4)
    return struct.pack("<4I", count, ROW_STRIDE, start, len(payload)) + payload


def _be32(b, o):
    return struct.unpack_from(">I", b, o)[0]


def _bes32(b, o):
    return struct.unpack_from(">i", b, o)[0]


def read_tree(settings, row_ids):
    """Walk the decision tree at file 0x24 (docs/gameplay/shot-to-template.md section 3).

    Node: {rel 0x18, count 2, cap 2, cond crc, path rel, index}; the two child slots {rel, type} follow at +0x18 and
    +0x20 (children array at node + rel); type 0x48BFC8B8 = sub node, 0x2C3F7780 = leaf {row id, ...}.  Returns
    {"nodes": [(cond_hash, child_true, child_false)], "root": 0} with child >= 0 a node index and child < 0 meaning
    ~row_index (the row whose id equals the leaf id)."""
    nodes = []

    def visit(addr, depth):
        if depth > 32:
            raise ValueError("decision tree deeper than 32")
        idx = len(nodes)
        nodes.append(None)
        rel, count = _bes32(settings, addr), _be32(settings, addr + 4)
        if count != 2:
            raise ValueError("tree node at 0x%X has %d children" % (addr, count))
        cond = _be32(settings, addr + 0xC)
        kids = []
        for i in range(2):
            slot = addr + rel + 8 * i
            tgt = slot + _bes32(settings, slot)
            typ = _be32(settings, slot + 4)
            if typ == TYPE_NODE:
                kids.append(visit(tgt, depth + 1))
            elif typ == TYPE_LEAF:
                leaf_id = _be32(settings, tgt)
                if leaf_id not in row_ids:
                    raise ValueError("tree leaf id %08x matches no template row" % leaf_id)
                kids.append(~row_ids[leaf_id])
            else:
                raise ValueError("unknown tree child type %08x at 0x%X" % (typ, slot))
        nodes[idx] = (cond, kids[0], kids[1])
        return idx

    root_slot = TREE_ROOT_OFF
    typ = _be32(settings, root_slot + 4)
    if typ != TYPE_NODE:
        raise ValueError("tree root at 0x%X has type %08x" % (root_slot, typ))
    visit(root_slot + _bes32(settings, root_slot), 0)
    return {"nodes": nodes, "root": 0}


def row_id_map(settings):
    start, count = settings_rows(settings)
    ids = {}
    for i in range(count):
        ids.setdefault(_be32(settings, start + i * ROW_STRIDE + ROW_ID_OFF), i)
    return ids


def build_tree(settings):
    t = read_tree(settings, row_id_map(settings))
    out = struct.pack("<2I", len(t["nodes"]), t["root"])
    for cond, a, b in t["nodes"]:
        out += struct.pack("<Iii", cond, a, b)
    return out


# ----------------------------------------------------------------------------------------------- GRPH

def path_key(path):
    """crc32 of the concatenated big-endian name hashes of a port's member path (section 5)."""
    return zlib.crc32(b"".join(struct.pack(">I", h) for h in path)) & 0xFFFFFFFF


def build_graph_record(g):
    """One graph (tools/ts4_analyser.Graph) -> section 5 record bytes."""
    ports = list(g.inputs) + list(g.outputs)
    port_bytes = b"".join(struct.pack("<IiII", p.domain, p.index, p.slot, path_key(p.path)) for p in ports)
    ports_off = 0x20
    nodes_off = ports_off + len(port_bytes)
    arena_off = nodes_off + 32 * len(g.nodes)
    arena = bytearray()
    node_bytes = bytearray()
    for n in g.nodes:
        f = n.fields
        kind = KIND_CODES.get(n.kind, UNKNOWN_KIND) if n.kind else UNKNOWN_KIND
        out, a, b, t, cnt, off, val = 0, 0, 0, 0, 0, 0, 0.0
        if n.kind in VARIADIC:
            slots = f["slots"]
            cnt, off, out = len(slots), arena_off + len(arena), f["out"]
            arena += struct.pack("<%dI" % len(slots), *slots)
        elif n.kind == "CURVE":
            keys = f["keys"]
            cnt, off, a, out = len(keys), arena_off + len(arena), f["in"], f["out"]
            for k in keys:
                arena += struct.pack("<4f", *k[:4])
        elif n.kind in ("SUB", "DIV"):
            a, b, out = f["a"], f["b"], f["out"]
        elif n.kind in ("LERP", "INVLERP"):
            a, b, t, out = f["a"], f["b"], f["t"], f["out"]
        elif n.kind == "CONST":
            out, val = f["out"], f["value"]
        node_bytes += struct.pack("<IiIIIIIf", kind, out, a, b, t, cnt, off, val)
    head = struct.pack("<8I", g.name, g.nregs, len(g.inputs), len(g.outputs), len(g.nodes), ports_off, nodes_off, 0)
    return head + port_bytes + bytes(node_bytes) + bytes(arena)


def build_grph(graphs):
    recs = [build_graph_record(g) for g in graphs]
    dir_len = 4 + 12 * len(recs)
    out = bytearray(struct.pack("<I", len(recs)))
    off = dir_len
    body = bytearray()
    for g, r in zip(graphs, recs):
        pad = -len(r) % 4
        out += struct.pack("<3I", g.name, off, len(r))
        body += r + b"\0" * pad
        off += len(r) + pad
    return bytes(out) + bytes(body)


# ----------------------------------------------------------------------------------------------- TUNE

def registry_names(path=TUNABLE_DEF):
    """{name: origin} from the TS4_TUN lines of the core's tunable registry (empty when the file is absent)."""
    out = {}
    if not os.path.exists(path):
        return out
    rx = re.compile(r'TS4_TUN\(\s*\w+\s*,\s*"([^"]+)"\s*,\s*"[^"]*"\s*,\s*(GAME|PORT)\b')
    with open(path) as fh:
        for line in fh:
            m = rx.search(line)
            if m:
                out[m.group(1)] = m.group(2)
    return out


def game_tunables(settings, state, ball_defaults):
    """Tunables whose value is read from game data, with provenance strings."""
    vals = {}
    src = ball_defaults.get("source", "")
    from_game = src.startswith("State.bin")
    for key, name in (("radius_cm", "ball.radius_cm"), ("a4", "ball.a4"), ("g", "ball.g"), ("max_bounces", "ball.max_bounces")):
        vals[name] = (float(ball_defaults[key]), None if from_game else "documented default")
    vals["ball.net_height_cm"] = (float(ball_defaults["net_height_cm"]), "assumed ITF net height, not game data")
    vals["ball.net_restitution"] = (0.2, None)          # pool+0x10C, a code constant (gp4.md 1.4)
    try:
        aim = struct.unpack_from(">2f", settings, 0x158)
        tiers = struct.unpack_from(">2f", settings, TREE_ROOT_OFF + 0xC70)
        if 10 < aim[0] < 200 and 10 < aim[1] < 200:
            vals["shot.net_aim_cm"] = (aim[0], None)
            vals["shot.let_aim_cm"] = (aim[1], None)
        if 0 < tiers[0] < tiers[1] <= 1:
            vals["shot.tier_medium"] = (tiers[0], None)
            vals["shot.tier_powerful"] = (tiers[1], None)
    except struct.error:
        pass
    return vals


def load_provisional(path):
    """port/core/data/provisional.tunables.json: accepts {name: value} or {"tunables": {name: value | {"value": v}}}."""
    if not path or not os.path.exists(path):
        return {}
    with open(path) as fh:
        d = json.load(fh)
    d = d.get("tunables", d) if isinstance(d, dict) else {}
    out = {}
    for k, v in d.items():
        if isinstance(v, dict):
            v = v.get("value")
        if isinstance(v, (int, float)) and not isinstance(v, bool):
            out[k] = float(v)
    return out


def build_tune(game, provisional):
    """game: {name: (value, provisional_note|None)}; provisional: {name: value}. Game values win."""
    entries = {}
    for name, v in provisional.items():
        entries[crc32(name)] = (v, FLAG_PROVISIONAL)
    for name, (v, note) in game.items():
        entries[crc32(name)] = (v, FLAG_PROVISIONAL if note else 0)
    out = struct.pack("<I", len(entries))
    for k in sorted(entries):
        v, fl = entries[k]
        out += struct.pack("<IfI", k, v, fl)
    return out


# ----------------------------------------------------------------------------------------------- container

def assemble(sections):
    """sections: {tag(4 chars): bytes} -> blob bytes (container of section 1)."""
    tags = sorted(sections)
    head = 0x10 + 16 * len(tags)
    off = (head + 3) & ~3
    directory = bytearray()
    body = bytearray()
    for tag in tags:
        data = sections[tag]
        directory += struct.pack("<4sIII", tag.encode("ascii"), off + len(body), len(data), 0)
        body += data + b"\0" * (-len(data) % 4)
    blob = struct.pack("<4sIII", b"TS4D", BLOB_VERSION, len(tags), 0) + bytes(directory)
    blob += b"\0" * (off - len(blob)) + bytes(body)
    return blob


def read_directory(blob):
    """Inverse of assemble(): {tag: (offset, size)}; raises ValueError on a malformed container."""
    if blob[:4] != b"TS4D" or struct.unpack_from("<I", blob, 4)[0] != BLOB_VERSION:
        raise ValueError("not a version 1 TS4D blob")
    n = struct.unpack_from("<I", blob, 8)[0]
    out = {}
    for i in range(n):
        tag, off, size, _fl = struct.unpack_from("<4sIII", blob, 0x10 + 16 * i)
        if off % 4 or off + size > len(blob):
            raise ValueError("bad section %r" % tag)
        out[tag.decode("ascii")] = (off, size)
    return out


def parse_tune(data):
    """TUNE section -> {key: (value, flags)}."""
    n = struct.unpack_from("<I", data, 0)[0]
    out = {}
    for i in range(n):
        k, v, fl = struct.unpack_from("<IfI", data, 4 + 12 * i)
        out[k] = (v, fl)
    return out


def parse_tree(data):
    """TREE section -> (nodes [(cond, child_true, child_false)], root)."""
    n, root = struct.unpack_from("<2I", data, 0)
    return [struct.unpack_from("<Iii", data, 8 + 12 * i) for i in range(n)], root


def parse_graph_record(rec):
    """Graph record (section 5) -> {name, nregs, ports: [(domain, cell, reg, path_key)], nodes: [dict]} for tests/tools."""
    name, nregs, n_in, n_out, n_nodes, ports_off, nodes_off, _ = struct.unpack_from("<8I", rec, 0)
    ports = [struct.unpack_from("<IiII", rec, ports_off + 16 * i) for i in range(n_in + n_out)]
    nodes = []
    for i in range(n_nodes):
        kind, out, a, b, t, cnt, off, val = struct.unpack_from("<IiIIIIIf", rec, nodes_off + 32 * i)
        d = {"kind": kind, "out": out, "a": a, "b": b, "t": t, "n": cnt, "value": val}
        if kind in (1, 2, 3, 4, 6):
            d["slots"] = list(struct.unpack_from("<%dI" % cnt, rec, off))
        elif kind == 5:
            d["keys"] = [struct.unpack_from("<4f", rec, off + 16 * j) for j in range(cnt)]
        nodes.append(d)
    return {"name": name, "nregs": nregs, "n_in": n_in, "n_out": n_out, "ports": ports, "nodes": nodes}


def parse_grph(data):
    """GRPH section -> {name_hash: record bytes}."""
    n = struct.unpack_from("<I", data, 0)[0]
    out = {}
    for i in range(n):
        name, off, size = struct.unpack_from("<3I", data, 4 + 12 * i)
        out[name] = data[off:off + size]
    return out


def write_blob(path, ctx=None, rows=None, ball=None, members=None, tunables=PROVISIONAL):
    """Build and write the blob.  members: {"Settings.bin","State.bin","Expressions.bin"} bytes (read from ctx when None)."""
    import ts4_analyser
    if members is None:
        members = {n: ctx.core_entry(n) for n in ("Settings.bin", "State.bin", "Expressions.bin")}
    settings, state, expr = members["Settings.bin"], members["State.bin"], members["Expressions.bin"]
    import export_assets
    ball = ball or export_assets.read_ball_defaults(state)
    sections = {
        "TPLS": build_tpls(settings),
        "TREE": build_tree(settings),
        "GRPH": build_grph(ts4_analyser.parse_expressions(expr)),
        "TUNE": build_tune(game_tunables(settings, state, ball), load_provisional(tunables)),
    }
    blob = assemble(sections)
    os.makedirs(os.path.dirname(os.path.abspath(path)), exist_ok=True)
    with open(path, "wb") as fh:
        fh.write(blob)
    side = {"blob": os.path.basename(path), "size": len(blob), "sha256": sha256(blob), "format_version": BLOB_VERSION,
            "sections": {t: s for t, (_o, s) in read_directory(blob).items()},
            "sources": {n: {"size": len(b), "sha256": sha256(b)} for n, b in members.items()},
            "tunables_file": os.path.relpath(tunables, ROOT) if tunables and os.path.exists(tunables) else None,
            "not_written": ["ROLE", "CURV"], "tool": "tools/port/blob_writer.py"}
    with open(path + ".manifest.json", "w") as fh:
        json.dump(side, fh, indent=1)
        fh.write("\n")
    return side


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--settings", required=True)
    ap.add_argument("--state", required=True)
    ap.add_argument("--expressions", required=True)
    ap.add_argument("--tunables", default=PROVISIONAL)
    ap.add_argument("--out", required=True)
    a = ap.parse_args(argv)
    members = {n: open(p, "rb").read() for n, p in (("Settings.bin", a.settings), ("State.bin", a.state), ("Expressions.bin", a.expressions))}
    side = write_blob(a.out, members=members, tunables=a.tunables)
    print(json.dumps(side, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main())
