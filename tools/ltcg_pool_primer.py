#!/usr/bin/env python3
"""Generate an LTCG constant-pool primer from the original module (PP1).

    python3 tools/ltcg_pool_primer.py [--image orig/54540859/Swing_DLL.dll] \
        [--out src/xbox360/pp1_pool_primer.c] [--list]

Swing_DLL's LTCG float/double literals live in one pool, g_ts4_script_constants
(0x880D0F70, 0xA70 bytes), addressed as base+offset. A scratch `link /LTCG`
builds its own pool in code-generation order, deduplicated by (size, bits). The
primer is a context-only source that uses every pool entry once, in pool
order, so that our scratch pool has the original's offsets. Entries are
allocated first-fit (doubles 8-aligned, later floats fill alignment holes), so
pool (offset) order reproduces any such layout. LTCG generates leaf functions
first, ties in reverse command-line order: the primer must be the last
--context.

Entry types come from the code: a word loaded with lfs is a float, one loaded
with lfd is a double, the +0x68 select table ({1.0f,-1.0f}) is an 8-byte
constant. Unreferenced words are typed by a heuristic (8-aligned pair whose
double has a short decimal form -> double, else floats); an unreferenced zero
word just before a double is alignment padding and is skipped. Each entry becomes a
call to an undefined external (`pp1_pool_f`/`pp1_pool_d`), which the checker
stubs without /GL, so nothing is folded or dropped. Output is deterministic.
"""
import argparse
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
POOL, POOL_SIZE = 0x880D0F70, 0xA70
SCAN_RANGES = ((0x88150000, 0x88B20000),)  # all code: plain objects share the __real@ entries
OPS = {48: "f", 49: "f", 52: "f", 53: "f", 50: "d", 51: "d", 54: "d", 55: "d", 14: "addr"}
TABLE = {0x68}  # compiler-generated {+1,-1} select table, an 8-byte constant


def load_image(path):
    data = path.read_bytes()
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    count = struct.unpack_from("<H", data, pe + 6)[0]
    opt = struct.unpack_from("<H", data, pe + 20)[0]
    base = struct.unpack_from("<I", data, pe + 24 + 28)[0]
    secs = []
    for i in range(count):
        vsize, va, rsize, raw = struct.unpack_from("<IIII", data, pe + 24 + opt + 40 * i + 8)
        secs.append((base + va, min(vsize, rsize), raw))

    def read(addr, size):
        for va, n, raw in secs:
            if va <= addr and addr + size <= va + n:
                return data[raw + addr - va: raw + addr - va + size]
        raise KeyError(hex(addr))
    return read


def function_starts(symbols):
    out = []
    for line in symbols.read_text().splitlines():
        m = re.match(r"\S+ = \.text:0x([0-9A-Fa-f]+);.*size:0x([0-9A-Fa-f]+)", line)
        if m:
            out.append((int(m.group(1), 16), int(m.group(2), 16)))
    return sorted(out)


def scan_refs(read, funcs):
    """offset -> set of access kinds ('f', 'd', 'addr') from lis/addi/D-form chains."""
    refs = {}
    for start, size in funcs:
        if not any(lo <= start < hi for lo, hi in SCAN_RANGES):
            continue
        code, reg = read(start, size), {}
        for k in range(0, size, 4):
            w = struct.unpack_from(">I", code, k)[0]
            op, rd, ra, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
            if op == 15 and ra == 0:          # lis
                reg[rd] = imm << 16
                continue
            if op in OPS and ra and ra in reg:
                ea = (reg[ra] + (imm - 0x10000 if imm & 0x8000 else imm)) & 0xFFFFFFFF
                if POOL <= ea < POOL + POOL_SIZE:
                    refs.setdefault(ea - POOL, set()).add(OPS[op])
                if op == 14:
                    reg[rd] = ea
                    continue
            if op in (14, 15, 32, 33, 34, 40, 42, 12, 13, 7):
                reg.pop(rd, None)
            elif op in (21, 24, 25, 28, 29):
                reg.pop(ra, None)
            elif op == 31:
                reg.pop(rd, None)
                reg.pop(ra, None)
            if w == 0x4E800020:               # blr
                reg = {}
    return refs


def short_float(bits):
    """Decimal whose double value is exactly the float (no double rounding in cl)."""
    return repr(struct.unpack(">f", struct.pack(">I", bits))[0])


def short_double(bits):
    return repr(struct.unpack(">d", struct.pack(">Q", bits))[0])


def c_literal(text, suffix):
    if "e" not in text and "." not in text and "inf" not in text:
        text += ".0"
    return text + suffix


def classify(read, refs):
    words = struct.unpack(">%dI" % (POOL_SIZE // 4), read(POOL, POOL_SIZE))
    items, off = [], 0
    while off < POOL_SIZE:
        kinds = refs.get(off, set())
        nxt = refs.get(off + 4, set())
        pair = off % 8 == 0 and off + 8 <= POOL_SIZE
        if (off % 8 == 4 and not kinds and words[off // 4] == 0 and "d" in nxt):
            off += 4                          # alignment padding before a double
            continue
        if pair and (off in TABLE or "d" in kinds):
            kind = "d"
        elif "f" in kinds or not pair or nxt:
            kind = "f"
        else:
            d = short_double((words[off // 4] << 32) | words[off // 4 + 1])
            f = len(short_float(words[off // 4])) + len(short_float(words[off // 4 + 1]))
            kind = "d" if len(d) <= 10 and len(d) < f else "f"
        if kind == "d":
            items.append((off, "d", (words[off // 4] << 32) | words[off // 4 + 1], kinds))
            off += 8
        else:
            items.append((off, "f", words[off // 4], kinds))
            off += 4
    return items


def render(items, image_path, sha):
    lines = [
        "/*",
        " * PP1: LTCG context only (not a matched function). Generated by",
        " *   python3 tools/ltcg_pool_primer.py --image %s" % image_path,
        " * from Swing_DLL.dll sha256 %s." % sha,
        " * Uses every entry of the module constant pool g_ts4_script_constants",
        " * (0x880D0F70, 0x%X bytes) once, in pool order, so that a scratch link /LTCG" % POOL_SIZE,
        " * lays out its pool at the original offsets. The comment gives each offset;",
        " * '?' marks an entry typed by heuristic (no lfs/lfd reference found).",
        " * pp1_pool_f/pp1_pool_d stay undefined: the checker stubs them without /GL.",
        " * List this file as the LAST --context: LTCG fills the pool in code-generation",
        " * order (leaf functions first, ties in reverse command-line order), so a later",
        " * /GL file with new constants would take the first offsets.",
        " */",
        "void pp1_pool_f(float v);",
        "void pp1_pool_d(double v);",
        "",
        "void pp1_pool_primer(void)",
        "{",
    ]
    for off, kind, bits, kinds in items:
        mark = "" if kinds - {"addr"} or off in TABLE else " ?"
        if kind == "f":
            lit = c_literal(short_float(bits), "f")
            lines.append("    pp1_pool_f(%s); /* +0x%03x%s */" % (lit, off, mark))
        else:
            lit = c_literal(short_double(bits), "")
            lines.append("    pp1_pool_d(%s); /* +0x%03x%s */" % (lit, off, mark))
    lines.append("}")
    return "\n".join(lines) + "\n"


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--image", type=Path, default=Path("orig/54540859/Swing_DLL.dll"))
    ap.add_argument("--symbols", type=Path, default=ROOT / "config/54540859/symbols.txt")
    ap.add_argument("--out", type=Path, default=ROOT / "src/xbox360/pp1_pool_primer.c")
    ap.add_argument("--list", action="store_true", help="print the typed entries instead of writing")
    args = ap.parse_args()
    import hashlib
    image = args.image if args.image.is_absolute() else ROOT / args.image
    sha = hashlib.sha256(image.read_bytes()).hexdigest()
    read = load_image(image)
    items = classify(read, scan_refs(read, function_starts(args.symbols)))
    if args.list:
        for off, kind, bits, kinds in items:
            print("+0x%03x %s %0*x %s" % (off, kind, 8 if kind == "f" else 16, bits, ",".join(sorted(kinds))))
        return 0
    args.out.write_text(render(items, args.image.as_posix(), sha))
    print("%s: %d entries" % (args.out, len(items)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
