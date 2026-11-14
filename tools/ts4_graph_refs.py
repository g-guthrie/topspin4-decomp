#!/usr/bin/env python3
"""Find every place that names an analyser graph (standard library only).

A graph is run only if something hands its name hash to the graph lookup ``fn_8866F028``.  The hash
can sit in a data file (Settings.bin tables, any other XBin) or in code, either as a word in a data
section or built in registers by ``lis rX, hi`` + ``ori/addi rX, rX, lo``.  This tool reports, for
each graph of ``Expressions.bin``:

  * every file offset (big- or little-endian word) in the given data files or directories, except
    Expressions.bin files themselves (any copy, disc or title update);
  * every ``lis``/``ori`` or ``lis``/``addi`` pair (at most 12 instructions apart) in the
    executable sections of the given PE images (``Swing_DLL.dll``, ``Loader_DLL.dll``).

Usage:
  python3 tools/ts4_graph_refs.py Expressions.bin --pe Swing_DLL.dll --stores 0x564,0x56d,0x56e,0x572
  python3 tools/ts4_graph_refs.py Expressions.bin --data work/disc/core_all work/disc/tu1_arc \
      --pe orig/54540859/Swing_DLL.dll orig/54540859/disc/Loader_DLL.dll [--only-unreferenced]
"""
from __future__ import annotations

import argparse
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import ts4_analyser as A  # noqa: E402


def code_constants(words, base):
    """{32-bit value: [address]} for constants built by lis + ori/addi in a big-endian word list
    that starts at ``base``."""
    out = {}
    lis = {}
    for k, w in enumerate(words):
        op = w >> 26
        if op == 15 and (w >> 16) & 31 == 0:              # lis rD, imm  (addis rD, 0, imm)
            lis[(w >> 21) & 31] = (w & 0xFFFF, k)
        elif op in (24, 14):                              # ori rA, rS, imm / addi rD, rA, imm
            src = (w >> 21) & 31 if op == 24 else (w >> 16) & 31
            if src in lis and k - lis[src][1] < 12:
                hi, lo = lis[src][0], w & 0xFFFF
                if op == 24:
                    v = (hi << 16) | lo
                else:
                    v = ((hi << 16) + (lo - 0x10000 if lo & 0x8000 else lo)) & 0xFFFFFFFF
                out.setdefault(v, []).append(base + 4 * k)
    return out


STORE_OPS = (36, 38, 44, 52, 54)   # stw, stb, sth, stfs, stfd


def based_stores(words, base, bases, targets, window=40):
    """[(address, field offset)] of stores ``st* rS, d(rB)`` where rB was set by
    ``addi rB, rA, b`` (b in ``bases``) at most ``window`` instructions before and ``b + d`` is in
    ``targets``.  Finds writes to a sub-struct field reached through a sub-struct base pointer
    (e.g. ShotContext = S + 0x500)."""
    out, recent = [], {}
    for k, w in enumerate(words):
        op, rd, ra, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
        if op == 14 and imm in bases and ra != 0:
            recent[rd] = (k, imm)
            continue
        if op in STORE_OPS:
            if ra in recent and k - recent[ra][0] < window and recent[ra][1] + imm in targets:
                out.append((base + 4 * k, recent[ra][1] + imm))
            continue
        if op in (14, 15, 21, 24, 31, 32):        # the register is overwritten (approximation)
            recent.pop(rd if op not in (24, 21) else ra, None)
    return out


def pe_sections(path):
    """[(virtual address, big-endian words)] of the executable sections of a PE image."""
    b = open(path, "rb").read()
    e = struct.unpack_from("<I", b, 0x3C)[0]
    ns = struct.unpack_from("<H", b, e + 6)[0]
    osz = struct.unpack_from("<H", b, e + 20)[0]
    image_base = struct.unpack_from("<I", b, e + 24 + 28)[0]
    sec = e + 24 + osz
    out = []
    for i in range(ns):
        _, _, va, rs, rp = struct.unpack_from("<8sIIII", b, sec + 40 * i)
        if struct.unpack_from("<I", b, sec + 40 * i + 36)[0] & 0x20:
            out.append((image_base + va, struct.unpack_from(">%dI" % (rs // 4), b, rp)))
    return out


def pe_code_constants(path):
    """code_constants over every executable section of a PE image (Xbox 360 DLL: big-endian code)."""
    out = {}
    for va, words in pe_sections(path):
        for v, addrs in code_constants(words, va).items():
            out.setdefault(v, []).extend(addrs)
    return out


def is_expressions(b):
    """True for an Expressions.bin XBin (any layout version): the graphs define their own names."""
    if len(b) < 0x1C:
        return False
    sig = struct.unpack_from(">II", b, 0)
    return sig in A.EXPRESSIONS_SIGNATURES and struct.unpack_from(">I", b, 0x18)[0] == A.EXPRESSIONS_ROOT_TYPE


def data_hits(paths, hashes, skip=None):
    """{hash: [(file, offset, endianness)]} over files and directories (recursive)."""
    pats = {}
    for h in hashes:
        pats[struct.pack(">I", h)] = (h, "BE")
        pats[struct.pack("<I", h)] = (h, "LE")
    hits = {}
    files = []
    for p in paths:
        if os.path.isdir(p):
            for dp, _, fn in os.walk(p):
                files += [os.path.join(dp, f) for f in sorted(fn)]
        else:
            files.append(p)
    for f in files:
        if skip and os.path.realpath(f) in skip:
            continue
        try:
            b = open(f, "rb").read()
        except OSError:
            continue
        if is_expressions(b):
            continue                                    # an Expressions.bin (disc or title update)
        for pat, (h, end) in pats.items():
            o = b.find(pat)
            while o >= 0:
                hits.setdefault(h, []).append((f, o, end))
                o = b.find(pat, o + 1)
    return hits


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("expressions")
    ap.add_argument("--data", nargs="*", default=[])
    ap.add_argument("--pe", nargs="*", default=[])
    ap.add_argument("--only-unreferenced", action="store_true",
                    help="list only graphs with no hit outside Expressions.bin")
    ap.add_argument("--stores", metavar="OFF,OFF", help="instead: list stores to these PlayerState offsets made "
                    "through a ShotContext/Context base (addi 0x500 / 0x4F0) in the --pe images")
    args = ap.parse_args()
    if args.stores:
        targets = {int(x, 0) for x in args.stores.split(",")}
        for p in args.pe:
            for va, words in pe_sections(p):
                for a, off in based_stores(words, va, (0x500, 0x4F0), targets):
                    print("%s 0x%08X stores S+0x%X" % (os.path.basename(p), a, off))
        return
    buf = open(args.expressions, "rb").read()
    graphs = A.parse_expressions(buf)
    hashes = {g.name for g in graphs}
    skip = {os.path.realpath(args.expressions): buf}
    dh = data_hits(args.data, hashes, skip)
    ch = {p: pe_code_constants(p) for p in args.pe}
    for i, g in enumerate(graphs):
        d = dh.get(g.name, [])
        c = [(os.path.basename(p), a) for p, t in ch.items() for a in t.get(g.name, [])]
        if args.only_unreferenced and (d or c):
            continue
        cells = ["data %s+0x%x %s" % (os.path.basename(f), o, e) for f, o, e in d[:4]]
        if len(d) > 4:
            cells.append("(+%d more data hits)" % (len(d) - 4))
        cells += ["code %s 0x%08X" % x for x in c]
        print("%3d %08x %s" % (i, g.name, "; ".join(cells) if cells else "none"))


if __name__ == "__main__":
    main()
