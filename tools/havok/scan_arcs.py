#!/usr/bin/env python3
"""Scan Top Spin 4 .arc archives on the disc image for Havok packfiles.

Uses the disc agent's readers (tools/xdvdfs.py, tools/ts4_arc.py) read-only.
For each entry only the first PAM-LZX chunk (<= 1 MiB) is decompressed, which is
enough to find the packfile magic and read the packfile header.

  python3 tools/havok/scan_arcs.py ISO [--arc NAME ...] [--json OUT]

Output: one line per entry containing the Havok magic:
  arc  entry_hash  stored_size  unpacked_size  magic_offset  sdk_version  contents_class
"""
import argparse
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import ts4_arc  # noqa: E402
import ts4_lzx  # noqa: E402
import xdvdfs  # noqa: E402

MAGIC = struct.pack(">II", 0x57E0E057, 0x10C0C010)
TAG_MAGIC = struct.pack("<II", 0xCAB00D1E, 0xD011FACE)  # tagfile magic (either byte order)


def first_chunk(blob):
    """Decompress only the first chunk of a stored entry (raw entries pass through)."""
    if blob[:8] != ts4_arc.TAG:
        return blob, len(blob)
    win, total, chunks = ts4_arc.split_chunks(blob)
    us, frames = chunks[0]
    dec = ts4_lzx.LZXDecoder(win.bit_length() - 1)
    return b"".join(dec.decode_frame(c, u) for u, c in frames), total


def packfile_header_info(buf, off):
    """Return (sdk_version, contents_class_name_offset) from a packfile header at off."""
    ver = buf[off + 0x28:off + 0x38].split(b"\0")[0].decode("latin-1", "replace")
    return ver


class NilArc:
    """Minimal reader for uncompressed archives tagged "PAM-NIL" (e.g. CutScenes.arc),
    which ts4_arc.Arc rejects. Same header and (hash, offset, size) table layout as the
    PAM-LZX archives; entries are stored raw."""

    def __init__(self, f):
        self.f = f
        head = f.read(0x24)
        size_m4, tab_m4, count = struct.unpack_from(">3I", head, 0)
        if head[0x1C:0x24] != b"PAM-NIL\0":
            raise ValueError("not a PAM-NIL archive")
        f.seek(tab_m4 + 4)
        tab = f.read(12 * count)
        self.data_start = size_m4 + 4
        self.entries = [struct.unpack_from(">3I", tab, 12 * i) for i in range(count)]

    def raw(self, ent):
        self.f.seek(self.data_start + ent[1])
        return self.f.read(min(ent[2], 1 << 20))


def scan_arc(arc, name, out):
    for ent in arc.entries:
        h, off, size = ent
        raw = arc.raw(ent)
        try:
            head, total = first_chunk(raw)
        except Exception as ex:  # noqa: BLE001
            print("%s %08x decode error %s" % (name, h, ex), file=sys.stderr)
            continue
        pos = head.find(MAGIC)
        tpos = head.find(TAG_MAGIC)
        if pos >= 0:
            rec = dict(arc=name, hash="%08x" % h, stored=size, unpacked=total, magic_off=pos,
                       version=packfile_header_info(head, pos))
            out.append(rec)
            print("%s %s %d %d %d %s" % (name, rec["hash"], size, total, pos, rec["version"]), flush=True)
        elif tpos >= 0:
            print("%s %08x tagfile at %d" % (name, h, tpos), flush=True)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("iso")
    ap.add_argument("--arc", action="append", help="archive path on disc (default: all *.arc)")
    ap.add_argument("--json")
    a = ap.parse_args()
    x = xdvdfs.XDVDFS(a.iso)
    names = a.arc or [p for p, e in x.walk() if p.lower().endswith(".arc")]
    out = []
    for n in names:
        try:
            arc = ts4_arc.Arc(x.open_slice(n))
        except Exception as ex:  # noqa: BLE001  (e.g. archives in another container format)
            try:
                arc = NilArc(x.open_slice(n))
            except Exception:  # noqa: BLE001
                print("%s open error: %s" % (n, ex), flush=True)
                continue
        scan_arc(arc, n, out)
    if a.json:
        with open(a.json, "w") as f:
            json.dump(out, f, indent=1)


if __name__ == "__main__":
    main()
