#!/usr/bin/env python3
"""Inventory every Pam ``.arc`` archive (and loose ``.bin``) on a Top Spin 4 disc image.

Standard library only.  Reads the ISO in place (never writes to it) and writes, under OUT
(default ``work/disc/inventory``, git-ignored):

  <Archive>.tsv      one line per member: key, stored size, uncompressed size, first 16 bytes
                     (hex, of the *uncompressed* data), XBin root-type crc when the member is an
                     XBin image, and the leaf name recovered from the archive's directory table
  summary.json       per archive: member count, named count, XBin count, root-type histogram,
                     plus the sha256/size of every loose root-level .bin
  xbin_types.tsv     every distinct XBin root-type crc, the archives and member keys that use it

With ``--extract-xbin DIR`` every member whose root type is in ``--types`` (hex list, default
the generic data-tree type 0xD2968089 used by Settings/State/Module/Expressions) is fully
decoded and written as DIR/<Archive>/<key>.bin.

Usage:
  python3 tools/ts4data/arc_inventory.py --iso IMAGE.iso [--out work/disc/inventory]
         [--only Core.arc,Global.arc] [--extract-xbin work/disc/xbin] [--types d2968089,...]
"""
from __future__ import annotations

import argparse
import collections
import hashlib
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import ts4_arc  # noqa: E402
import xdvdfs  # noqa: E402

XBIN_MARK = b"\xff\xff\xff\xff"


def xbin_root_type(head: bytes):
    """Return the root-type crc (header word 1) when head looks like an XBin image, else None."""
    if len(head) >= 0x14 and head[0x10:0x14] == XBIN_MARK and head[0x0C:0x10] == b"\0\0\0\0":
        return struct.unpack_from(">I", head, 4)[0]
    return None


def inventory_arc(arc, name, out_dir, extract_dir=None, want_types=()):
    rows = []
    types = collections.Counter()
    for key, off, size in arc.entries:
        arc.f.seek(arc.data_start + off)
        blob = arc.f.read(min(size, 300000))
        try:
            head = ts4_arc.peek_blob(blob, 32)
            us = struct.unpack_from(">I", blob, 20)[0] if blob[:8] == ts4_arc.TAG else size
        except Exception:  # noqa: BLE001 - keep going on a bad member
            head, us = b"", -1
        rt = xbin_root_type(head)
        if rt is not None:
            types[rt] += 1
        ln = arc.leaf_names.get(key)
        rows.append((key, size, us, head[:16].hex(), rt, ln[1] if ln else ""))
        if extract_dir and rt is not None and rt in want_types:
            d = os.path.join(extract_dir, name)
            os.makedirs(d, exist_ok=True)
            with open(os.path.join(d, "%08x.bin" % key), "wb") as o:
                o.write(arc.read((key, off, size)))
    with open(os.path.join(out_dir, name + ".tsv"), "w") as o:
        o.write("# key\tstored\tusize\thead16\txbin_root\tname\n")
        for key, size, us, h, rt, ln in rows:
            o.write("%08x\t%d\t%d\t%s\t%s\t%s\n" % (key, size, us, h, "%08x" % rt if rt is not None else "-", ln))
    return dict(members=len(rows), named=sum(1 for r in rows if r[5]), xbin=sum(types.values()),
                root_types={"%08x" % k: v for k, v in types.most_common()}), rows


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--iso", required=True)
    ap.add_argument("--out", default="work/disc/inventory")
    ap.add_argument("--only", default="", help="comma-separated archive names")
    ap.add_argument("--extract-xbin", metavar="DIR")
    ap.add_argument("--types", default="d2968089")
    a = ap.parse_args(argv)
    os.makedirs(a.out, exist_ok=True)
    fs = xdvdfs.XDVDFS(a.iso)
    want = {int(t, 16) for t in a.types.split(",") if t}
    only = {s for s in a.only.split(",") if s}
    summary = {"iso": os.path.basename(a.iso), "archives": {}, "loose_bin": {}}
    by_type = collections.defaultdict(list)
    files = sorted(p for p, e in fs.walk() if not p.endswith("/"))
    for path in files:
        low = path.lower()
        if "/" in path:
            continue
        if low.endswith(".bin"):
            data = fs.open_slice(path).read()
            summary["loose_bin"][path] = dict(size=len(data), sha256=hashlib.sha256(data).hexdigest(),
                                              xbin_root="%08x" % xbin_root_type(data) if xbin_root_type(data) is not None else None)
            continue
        if not low.endswith(".arc") or (only and path not in only):
            continue
        arc = ts4_arc.Arc(fs.open_slice(path))
        info, rows = inventory_arc(arc, path, a.out, a.extract_xbin, want)
        summary["archives"][path] = info
        for key, _s, _u, _h, rt, ln in rows:
            if rt is not None:
                by_type[rt].append("%s:%08x%s" % (path, key, "(" + ln + ")" if ln else ""))
        print("%-32s %5d members %4d xbin" % (path, info["members"], info["xbin"]), flush=True)
    with open(os.path.join(a.out, "summary.json"), "w") as o:
        json.dump(summary, o, indent=1)
    with open(os.path.join(a.out, "xbin_types.tsv"), "w") as o:
        for rt, users in sorted(by_type.items(), key=lambda kv: -len(kv[1])):
            o.write("%08x\t%d\t%s\n" % (rt, len(users), " ".join(users[:40])))
    return 0


if __name__ == "__main__":
    sys.exit(main())
