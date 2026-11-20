#!/usr/bin/env python3
"""Print the flattened PlayerState (or any reflected type) layout of Layoutall.bin.

Every field is listed with its absolute byte offset from the start of the type, its
dotted path and its type hash, resolved through data/gameplay/names.yaml.  Standard
library only.  Example:

    python3 tools/ts4data/ps_layout.py --layout work/disc/Layoutall.bin --range 0xD20 0xDB0
"""
import argparse
import os
import re
import sys
import zlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from shot_tree import Layout  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def load_names(path):
    names = {}
    if not os.path.exists(path):
        return names
    pat = re.compile(r'^\s*"([0-9a-f]{8})": \{name: "([^"]*)"')
    with open(path, encoding="utf-8") as f:
        for line in f:
            m = pat.match(line)
            if m:
                names[int(m.group(1), 16)] = m.group(2)
    return names


def flatten(layout, type_hash, names, base=0, prefix="", depth=0, out=None, size_hint=None):
    out = [] if out is None else out
    variants = layout.types.get(type_hash)
    if not variants or depth > 12:
        return out
    if size_hint is not None:
        pick = [v for v in variants if v[0] == size_hint] or variants
    else:
        pick = variants
    size, fields, ftypes = pick[0]
    # field type crc is stored with the preceding field: ftypes maps next-name -> type
    for name_hash, ofs in sorted(fields.items(), key=lambda kv: kv[1]):
        nm = names.get(name_hash, "#%08x" % name_hash)
        th = ftypes.get(name_hash)
        path = prefix + nm
        sub = layout.types.get(th) if th is not None else None
        out.append((base + ofs, path, th, sub[0][0] if sub else None))
        if sub:
            flatten(layout, th, names, base + ofs, path + ".", depth + 1, out)
    return out


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--layout", default=os.path.join(ROOT, "work/disc/Layoutall.bin"))
    ap.add_argument("--names", default=os.path.join(ROOT, "data/gameplay/names.yaml"))
    ap.add_argument("--type", help="type hash (hex) or name; default PlayerState")
    ap.add_argument("--range", nargs=2, help="only offsets in [lo, hi) (hex)")
    a = ap.parse_args(argv)
    layout = Layout(open(a.layout, "rb").read())
    names = load_names(a.names)
    if a.type:
        try:
            th = int(a.type, 16)
        except ValueError:
            th = zlib.crc32(a.type.encode())
    else:
        th = layout.player_state
    size_hint = 0x1070 if th == layout.player_state else None
    rows = flatten(layout, th, names, size_hint=size_hint)
    lo, hi = (int(a.range[0], 16), int(a.range[1], 16)) if a.range else (0, 1 << 32)
    for ofs, path, t, sz in rows:
        if lo <= ofs < hi:
            ts = "%08x" % t if t is not None else "-"
            names_t = names.get(t, "") if t is not None else ""
            print("0x%04X  %-70s %s %s%s" % (ofs, path, ts, names_t, (" size 0x%X" % sz) if sz else ""))
    return 0


if __name__ == "__main__":
    sys.exit(main())
