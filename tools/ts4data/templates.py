#!/usr/bin/env python3
"""Shot-template decoder for Top Spin 4 (Xbox 360), standard library only.

Reads the shot-template table out of the raw ``Settings.bin`` (and ``State.bin``, which holds
one extra row) of ``Core.arc`` and decodes every row into named fields.  Layout (docs/gameplay/gp4b.md
section 1, docs/gameplay/df.md 4.x, measured on the retail disc in docs/gameplay/shot-templates.md):

All integers/floats are big-endian.  Every ``rel`` is a signed 32-bit offset relative to the address
of the field that holds it.  A row is 0x8C bytes (``row``); ``tpl = row + 0x18``:

  row+0x00 u32 row type 0x85B71A2B   (Settings.bin only)
  row+0x04 u32 name hash             crc32 of the template name ("FlatNormal", "ServeSlice", ...)
  row+0x08 u32 group hash            (0, or e.g. crc32("FlatReturn"))
  row+0x0C u32 base hash             (0 or a name hash; a related template)
  row+0x10 / +0x14  {rel or -1}      two optional pointers to a float block (meaning unknown)
  tpl+0x00 node0 {rel, type, kind}   primary node (curve of the distance), kind = solver kind
  tpl+0x0C node1 {rel, type, kind}   secondary node, kind = secondary kind
  tpl+0x18/+0x24/+0x30 {rel,count=2,cap=2}  -> 2 elements {rel,type} = (lo, hi): spin_a, spin_c, spin_b
  tpl+0x3C f32 T                     drag scale (k = T / a4)
  tpl+0x40/+0x4C/+0x58/+0x64 {rel,count,cap} -> curve16 keys {x0,x1,y0,y1}: bounce speed loss c40(spin_a),
                                     spin decay c4C(spin_a), outgoing elevation c58(theta), yaw kick c64(spin_b)
  row+0x88 u32 name hash repeated

Value types ({rel,type}): 0x33799CCE float, 0xF9F12A60 curve20 (keys {x0,x1,y0,slope,w4}),
0x7A330099 2-D table (rows {curve16 header, ?, a_key}).

Usage:
  templates.py --settings Settings.bin [--state State.bin] [--out templates_decoded.json]
  templates.py --arc Core.arc [--iso DISC.iso] ...    (extracts entries 0x334E7E0D / 0x623D0979 via tools/ts4_arc.py)
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import struct
import sys
import zlib

TYPE_CONST = 0x33799CCE
TYPE_CURVE20 = 0xF9F12A60
TYPE_TABLE2D = 0x7A330099
VALUE_TYPES = (TYPE_CONST, TYPE_CURVE20, TYPE_TABLE2D)

KIND_NAMES = {
    0x5D90675B: "DropTime",
    0x50B89452: "BounceSpeed",
    0xC1965E5C: "InitialSpeed",
    0x2DB3EB6F: "AverageSpeed",
    0x879BA860: "Apogee",
}
ROW_TYPE = 0x85B71A2B
ROW_SIZE = 0x8C
SETTINGS_KEY = 0x334E7E0D  # Core.arc entry hash of Settings.bin
STATE_KEY = 0x623D0979     # Core.arc entry hash of State.bin

# Template names recovered by crc32 search (each hash is a 32-bit match; see docs/gameplay/shot-templates.md).
TEMPLATE_NAMES = [
    "TopSpinNormal", "TopSpinRisky", "TopSpinFinesse", "SliceNormal", "SliceRisky", "SliceFinesse",
    "FlatNormal", "FlatRisky", "FlatFinesse", "FlatReturn", "LobNormal", "DefensiveShot", "DropShotNormal",
    "SmashNormal", "PowerVolley", "SliceVolley", "DropVolley", "FlatVolley", "ServeNormal", "ServeSlice",
    "ServeAdvanced",
]


def crc(name: str) -> int:
    return zlib.crc32(name.encode("latin1")) & 0xFFFFFFFF


def name_table(extra=()):
    t = {crc(n): n for n in TEMPLATE_NAMES}
    t.update({crc(n): n for n in extra})
    return t


def f32r(x: float) -> float:
    """Round-trip a float32 through a short decimal so JSON stays readable ("0.04" not "0.03999999910593033")."""
    for prec in range(1, 10):
        v = float("%.*g" % (prec, x))
        if struct.pack(">f", v) == struct.pack(">f", x):
            return v
    return x


class Buf:
    """Big-endian accessor over a bytes object (absolute file offsets)."""

    def __init__(self, data: bytes):
        self.d = data

    def u32(self, a):
        return struct.unpack_from(">I", self.d, a)[0]

    def i32(self, a):
        return struct.unpack_from(">i", self.d, a)[0]

    def f32(self, a):
        return struct.unpack_from(">f", self.d, a)[0]

    def inb(self, a, n=4):
        return 0 <= a and a + n <= len(self.d)


# ---------------------------------------------------------------- curves and tables

def read_curve20(b: Buf, hdr: int):
    """Header {rel, count, cap} at hdr, keys of 20 bytes at hdr+rel: {x0, x1, y0, slope, w4}."""
    rel, count = b.i32(hdr), b.i32(hdr + 4)
    if rel == -1 or count <= 0:
        return []
    base = hdr + rel
    if not b.inb(base, 20 * count):
        raise ValueError("curve20 out of range at 0x%X" % hdr)
    return [[f32r(b.f32(base + 20 * i + 4 * j)) for j in range(5)] for i in range(count)]


def read_curve16(b: Buf, hdr: int):
    """Header {rel, count[, cap]} at hdr, keys of 16 bytes at hdr+rel: {x0, x1, y0, y1}."""
    rel, count = b.i32(hdr), b.i32(hdr + 4)
    if rel == -1 or count <= 0:
        return []
    base = hdr + rel
    if not b.inb(base, 16 * count):
        raise ValueError("curve16 out of range at 0x%X" % hdr)
    return [[f32r(b.f32(base + 16 * i + 4 * j)) for j in range(4)] for i in range(count)]


def read_table2d(b: Buf, hdr: int):
    """Header {rel, count} at hdr; rows of 16 bytes {curve16 header (rel relative to the row), ?, f32 a_key}."""
    rel, count = b.i32(hdr), b.i32(hdr + 4)
    if rel == -1 or count <= 0:
        return []
    base = hdr + rel
    if not b.inb(base, 16 * count):
        raise ValueError("table2d out of range at 0x%X" % hdr)
    rows = []
    for i in range(count):
        r = base + 16 * i
        rows.append({"a": f32r(b.f32(r + 12)), "unk": b.u32(r + 8), "keys": read_curve16(b, r)})
    return rows


def read_value(b: Buf, addr: int):
    """Polymorphic value {rel, type} at addr (8 bytes): float, curve20 or table2d.  Returns a JSON-able dict."""
    rel, typ = b.i32(addr), b.u32(addr + 4)
    tgt = addr + rel
    if typ == TYPE_CONST:
        return {"type": "const", "value": f32r(b.f32(tgt))}
    if typ == TYPE_CURVE20:
        return {"type": "curve20", "keys": read_curve20(b, tgt)}
    if typ == TYPE_TABLE2D:
        return {"type": "table2d", "rows": read_table2d(b, tgt)}
    return {"type": "unknown", "type_hash": "%08x" % typ}


def eval_curve20(keys, x):
    """fn_8817A688: last key with x0 <= x (first if none); y = y0 + slope * clamp(x - x0, 0, x1 - x0)."""
    if not keys:
        return 0.0
    sel = keys[0]
    for k in keys:
        if k[0] > x:
            break
        sel = k
    x0, x1, y0, slope = sel[0], sel[1], sel[2], sel[3]
    t = max(min(x - x0, x1 - x0), 0.0)
    return y0 + t * slope


def eval_curve16(keys, x):
    """fn_881899D8: last key with x0 <= x (first if none); y = y0 + clamp((x-x0)/(x1-x0), 0, 1) * (y1 - y0)."""
    if not keys:
        return 0.0
    sel = keys[0]
    for k in keys:
        if k[0] > x:
            break
        sel = k
    x0, x1, y0, y1 = sel
    span = x1 - x0
    t = min(max(x - x0, 0.0), span)
    return y0 + (t / span if span else 0.0) * (y1 - y0)


def eval_table2d(rows, a, bval):
    """fn_8826D278: linear interpolation in `a` between the curve16 values (at `bval`) of the enclosing rows."""
    if not rows:
        return 0.0
    lo = 0
    for i, r in enumerate(rows):
        if a - r["a"] < 0:
            break
        lo = i
    if lo == len(rows) - 1:
        return eval_curve16(rows[lo]["keys"], bval)
    r0, r1 = rows[lo], rows[lo + 1]
    v0, v1 = eval_curve16(r0["keys"], bval), eval_curve16(r1["keys"], bval)
    d = a - r0["a"]
    span = r1["a"] - r0["a"]
    if d > 0:
        return v1 if d >= span else v0 + d / span * (v1 - v0)
    return v0


def eval_value(val, x, y=0.0):
    """Evaluate a decoded value dict (x = distance in cm for curves/tables, y = hit height in cm for tables)."""
    t = val["type"]
    if t == "const":
        return val["value"]
    if t == "curve20":
        return eval_curve20(val["keys"], x)
    if t == "table2d":
        return eval_table2d(val["rows"], x, y)
    return 0.0


# ---------------------------------------------------------------- rows

def find_rows(b: Buf):
    """Rows are found by their two nodes: tpl+0x04 and +0x10 are value types, tpl+0x08 and +0x14 are kind hashes."""
    out = []
    n = len(b.d)
    for p in range(0, n - 0x70, 4):
        if (b.u32(p + 4) in VALUE_TYPES and b.u32(p + 8) in KIND_NAMES
                and b.u32(p + 0x10) in VALUE_TYPES and b.u32(p + 0x14) in KIND_NAMES):
            out.append(p - 0x18)
    return out


def read_spin_pair(b: Buf, slot: int):
    rel, count = b.i32(slot), b.i32(slot + 4)
    if count != 2:
        raise ValueError("spin slot 0x%X has %d elements" % (slot, count))
    base = slot + rel
    return {"lo": read_value(b, base), "hi": read_value(b, base + 8)}


def read_aux(b: Buf, addr: int, nfloats=16):
    rel = b.i32(addr)
    if rel == -1:
        return None
    tgt = addr + rel
    if not b.inb(tgt, 4 * nfloats):
        return {"addr": tgt}
    return {"addr": tgt, "floats": [f32r(b.f32(tgt + 4 * i)) for i in range(nfloats)]}


def decode_row(b: Buf, row: int, names: dict):
    tpl = row + 0x18

    def nm(h):
        return names.get(h)

    k0, k1 = b.u32(tpl + 8), b.u32(tpl + 0x14)
    hdr = [b.u32(row + 4 * i) for i in range(6)]
    has_type = hdr[0] == ROW_TYPE
    r = {
        "row_offset": row,
        "header_words": ["%08x" % w for w in hdr],
        "kind": KIND_NAMES[k0],
        "kind_hash": "%08x" % k0,
        "secondary_kind": KIND_NAMES[k1],
        "secondary_kind_hash": "%08x" % k1,
        "T": f32r(b.f32(tpl + 0x3C)),
        "primary": read_value(b, tpl),
        "secondary": read_value(b, tpl + 0x0C),
        "spin": {
            "a": read_spin_pair(b, tpl + 0x18),
            "c": read_spin_pair(b, tpl + 0x24),
            "b": read_spin_pair(b, tpl + 0x30),
        },
        "bounce": {
            "speed_loss": read_curve16(b, tpl + 0x40),
            "spin_decay": read_curve16(b, tpl + 0x4C),
            "out_elevation": read_curve16(b, tpl + 0x58),
            "yaw_kick": read_curve16(b, tpl + 0x64),
        },
        "tail_words": ["%08x" % b.u32(row + 0x70 + 4 * i) for i in range(4)] if b.inb(row + 0x80, 0x10) else [],
    }
    if has_type:
        r["name_hash"] = "%08x" % hdr[1]
        r["name"] = nm(hdr[1])
        r["group_hash"] = "%08x" % hdr[2]
        r["group"] = nm(hdr[2]) if hdr[2] else None
        r["base_hash"] = "%08x" % hdr[3]
        r["base"] = nm(hdr[3]) if hdr[3] else None
        r["aux_ptr_10"] = read_aux(b, row + 0x10)
        r["aux_ptr_14"] = read_aux(b, row + 0x14)
        r["trailer_name_hash"] = "%08x" % b.u32(row + 0x88)
    return r


def decode_file(data: bytes, label: str, names: dict):
    b = Buf(data)
    rows = [decode_row(b, off, names) for off in find_rows(b)]
    for i, r in enumerate(rows):
        r["index"] = i
        r["file"] = label
    return {"file": label, "size": len(data), "sha256": hashlib.sha256(data).hexdigest(), "rows": rows}


def decode_all(settings: bytes, state: bytes | None = None, extra_names=()):
    names = name_table(extra_names)
    out = {"tool": "tools/ts4data/templates.py", "python": sys.version.split()[0],
           "files": [decode_file(settings, "Settings.bin", names)]}
    if state is not None:
        out["files"].append(decode_file(state, "State.bin", names))
    return out


def summarize(dec):
    lines = []
    for f in dec["files"]:
        lines.append("%s: %d bytes sha256 %s, %d rows" % (f["file"], f["size"], f["sha256"], len(f["rows"])))
        counts = {}
        for r in f["rows"]:
            k = (r["kind"], r["secondary_kind"])
            counts[k] = counts.get(k, 0) + 1
        for k, v in sorted(counts.items()):
            lines.append("  %-13s + %-8s x%d" % (k[0], k[1], v))
    return "\n".join(lines)


def _load_from_arc(arc_path, iso):
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    import ts4_arc  # noqa: E402
    arc = ts4_arc.open_arc(arc_path, iso)
    return arc.read(arc.find(SETTINGS_KEY)), arc.read(arc.find(STATE_KEY))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--settings", help="raw Settings.bin")
    ap.add_argument("--state", help="raw State.bin")
    ap.add_argument("--arc", help="Core.arc (extract both files from it)")
    ap.add_argument("--iso", help="read --arc from this disc image")
    ap.add_argument("--out", default=None, help="JSON output (default: print a summary only)")
    a = ap.parse_args(argv)
    if a.arc:
        s, st = _load_from_arc(a.arc, a.iso)
    elif a.settings:
        s = open(a.settings, "rb").read()
        st = open(a.state, "rb").read() if a.state else None
    else:
        ap.error("need --settings or --arc")
    dec = decode_all(s, st)
    print(summarize(dec))
    if a.out:
        os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
        with open(a.out, "w") as fh:
            json.dump(dec, fh, indent=1)
            fh.write("\n")
        print("wrote", a.out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
