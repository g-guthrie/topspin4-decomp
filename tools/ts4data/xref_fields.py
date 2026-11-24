#!/usr/bin/env python3
"""Find code that reads fields of a data root struct (heuristic, needs capstone + Swing_DLL.dll).

The gameplay code reaches the Settings.bin root ("cfg", file offset 0x24, type 0x9B4FB082) through
a context object: ``cfg = *(ctx + 0x6C)`` (docs/gameplay/shot-to-template.md s1).  This scanner
walks the whole .text linearly and, after every ``lwz rX, BASE(rY)`` (BASE = 0x6C by default),
treats rX as ``cfg`` until rX is overwritten, a ``blr``/``b`` ends the block, or WINDOW
instructions pass.  Every ``lfs/lfd/lwz/lhz/lha/lbz/stfs/stw`` with displacement D off rX, and
every ``addi rW, rX, D`` (address of a sub-struct passed on; tracked one level deep so loads off rW
count as D + D2), is recorded as (instruction address, cfg offset, access kind).

The output is a candidate list, not proof: an unrelated object with a pointer at +0x6C also
matches.  ``--layout/--type`` scores every hit against the real member layout (a hit is
*consistent* when it lands on the first byte of a scalar member whose type fits the access:
lfs->Single, lwz->Int32/UInt32/CKey, lbz->Boolean/UInt8); report only consistent hits with
``--consistent``.  Confidence for the catalogue: M when consistent and the function also has other
consistent hits, L otherwise.

Usage:
  python3 tools/ts4data/xref_fields.py --dll orig/54540859/Swing_DLL.dll \
      --layout work/disc/root/Layoutall.bin --type 9b4fb082 [--base 0x6c] --out work/disc/values/xref_settings.json
"""
from __future__ import annotations

import argparse
import collections
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import ts4_xbin as X  # noqa: E402

LOADS = {"lfs": "f32", "lfsu": "f32", "lfd": "f64", "lwz": "u32", "lwzu": "u32", "lhz": "u16", "lha": "s16",
         "lbz": "u8", "stfs": "st_f32", "stw": "st_u32", "stb": "st_u8"}
FITS = {"f32": {"float"}, "u32": {"int", "uint", "key", "string", "path", "rel"}, "u16": {"u16", "s16"},
        "s16": {"s16", "u16"}, "u8": {"bool", "u8", "char", "s8"}}


def pe_sections(b):
    e = struct.unpack_from("<I", b, 0x3C)[0]
    ns = struct.unpack_from("<H", b, e + 6)[0]
    osz = struct.unpack_from("<H", b, e + 20)[0]
    base = struct.unpack_from("<I", b, e + 24 + 28)[0]
    sec = e + 24 + osz
    out = []
    for i in range(ns):
        name, vs, va, rs, rp = struct.unpack_from("<8sIIII", b, sec + 40 * i)
        ch = struct.unpack_from("<I", b, sec + 40 * i + 36)[0]
        out.append((name.rstrip(b"\0").decode(), base + va, vs, rp, rs, ch))
    return base, out


def scalar_map(layout, tc, base=0, out=None, depth=0):
    """{offset: (path, tag)} for every scalar member reachable inline from type tc."""
    out = {} if out is None else out
    if depth > 12 or tc not in layout.types:
        return out
    for m in layout.types[tc][2]:
        o = base + m.offset
        if m.attr:
            tag = X.PRIMS.get(m.type, ("word",))[0]
            out.setdefault(o, (m.name, tag, m.type, m.size))
        elif m.kind == X.KIND_INLINE and m.type in X.VEC_TYPES:
            for i in range(X.VEC_TYPES[m.type]):
                out.setdefault(o + 4 * i, (m.name, "float", m.type, 4))
        elif m.kind == X.KIND_INLINE:
            scalar_map(layout, m.type, o, out, depth + 1)
        else:
            out.setdefault(o, (m.name, "u32", m.type, 4))   # list/pointer header word
    return out


def scan(dll, base_disp, window):
    import capstone
    b = open(dll, "rb").read()
    _img, secs = pe_sections(b)
    md = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)
    md.detail = False
    hits = []
    for name, va, vs, rp, rs, ch in secs:
        if not (ch & 0x20000000):        # IMAGE_SCN_MEM_EXECUTE
            continue
        code = b[rp:rp + min(vs, rs)]
        live = {}                         # reg -> (cfg offset, insns left)
        pos = 0
        while pos + 4 <= len(code):
            got = False
            for ins in md.disasm(code[pos:pos + 0x4000], va + pos):
                got = True
                pos = ins.address - va + 4
                mn, ops = ins.mnemonic, [o.strip() for o in ins.op_str.split(",")]
                for r in list(live):
                    off, left = live[r]
                    live[r] = (off, left - 1)
                    if left <= 0:
                        del live[r]
                if mn in ("blr", "b", "bctr", "bl", "blrl", "bctrl"):
                    if mn != "bl":
                        live.clear()
                    else:                  # calls clobber volatile regs r3..r12
                        for r in list(live):
                            if r in {"r%d" % i for i in range(3, 13)}:
                                del live[r]
                    continue
                if len(ops) == 2 and "(" in ops[1] and mn in LOADS | {"lwz": 1}:
                    disp_s, reg = ops[1].rstrip(")").split("(")
                    try:
                        disp = int(disp_s, 0)
                    except ValueError:
                        disp = None
                    dst = ops[0]
                    if disp is not None and reg in live:
                        hits.append((ins.address, live[reg][0] + disp, LOADS.get(mn, mn)))
                    if not mn.startswith("st"):
                        live.pop(dst, None)
                        if mn == "lwz" and disp == base_disp:
                            live[dst] = (0, window)
                    continue
                if mn == "addi" and len(ops) == 3 and ops[1] in live:
                    try:
                        d = int(ops[2], 0)
                    except ValueError:
                        d = None
                    base_off = live[ops[1]][0]
                    live.pop(ops[0], None)
                    if d is not None and base_off == 0:
                        hits.append((ins.address, d, "addr"))
                        live[ops[0]] = (d, window)
                    continue
                if mn == "mr" and len(ops) == 2 and ops[1] in live:
                    live[ops[0]] = live[ops[1]]
                    continue
                if ops and ops[0] in live and not mn.startswith(("st", "cmp", "b", "tw", "dcb", "mt")):
                    del live[ops[0]]
            if not got:
                pos += 4
    return hits


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--dll", required=True)
    ap.add_argument("--layout", required=True)
    ap.add_argument("--type", required=True, help="root type crc (hex), e.g. 9b4fb082 for Settings.bin")
    ap.add_argument("--base", default="0x6c", help="displacement of the pointer load that yields the root")
    ap.add_argument("--window", type=int, default=120)
    ap.add_argument("--consistent", action="store_true")
    ap.add_argument("--out", required=True)
    a = ap.parse_args(argv)
    lay = X.Layout(open(a.layout, "rb").read())
    tc = int(a.type, 16)
    size = lay.size_of(tc)
    smap = scalar_map(lay, tc)
    starts = sorted({m.offset for m in lay.types[tc][2]})
    hits = scan(a.dll, int(a.base, 0), a.window)
    per_fn = collections.Counter()
    rows = []
    for addr, off, kind in hits:
        if not (0 <= off < size):
            continue
        s = smap.get(off)
        ok = False
        if kind == "addr":
            ok = off in starts or s is not None
        elif s is not None:
            ok = s[1] in FITS.get(kind.replace("st_", ""), set())
        rows.append(dict(addr="%08X" % addr, off=off, kind=kind, consistent=ok,
                         member="%08x" % s[0] if s else None))
        if ok:
            per_fn[addr & ~0xFFF] += 1
    if a.consistent:
        rows = [r for r in rows if r["consistent"]]
    n_ok = sum(r["consistent"] for r in rows)
    out = {"_meta": {"dll": os.path.basename(a.dll), "type": a.type, "base": a.base, "hits": len(rows),
                     "consistent": n_ok}, "hits": rows}
    os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
    json.dump(out, open(a.out, "w"), indent=0)
    print(json.dumps(out["_meta"]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
