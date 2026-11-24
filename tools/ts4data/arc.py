#!/usr/bin/env python3
"""Pam .arc archive (CFileSystemPackArchive) reader prototype, standard library only.

Spec: work/gameplay-notes/df.md section 2.  UNVALIDATED (no archive was available).  Header handling and
the FAT lookup (12-byte entries sorted by path hash) were read directly from the loader
(fn_886217C0, fn_8827EC98, fn_886090A0/fn_886084C8); the exact meaning of the FAT entry words
{hash, offset, size} is M (offset +4 / size +8 confirmed from the stream read code fn_8827EE00/EEA0),
the directory table is L, and whether member data is compressed is UNKNOWN (marker string "PAM-ZLB").

Layout:
  u32 fat_size                       (if 0xFFFFFFFF: skip three more u32, then u32 fat_size)
  fat_size bytes of FAT (an XData typed struct, big endian)
  member data; entry.offset is relative to (position right after the FAT)
FAT bytes 0x00..0x1F: either plain, with b"PAM" at +0x18 (marker "PAM-ZLB\\0"), or obfuscated: words 0..5
XOR the u32 at +0x18 (the key), then +0x18..+0x1F is overwritten with the constant b"PAM-ZLB\\0".
FAT header words: +0x00 {rel,count} file table (12-byte entries {hash,offset,size}, sorted by hash),
+0x0C {rel,count} directory table (16-byte entries, key hash at +0x0C of the entry).
Path hash = crc32(lower(path)) after: '\\' -> '/', strip "X:" drive prefix, ensure a leading '/'.

Usage: df_arc.py list FILE.arc [--names names.txt] | extract FILE.arc OUTDIR [--names names.txt] | hash PATH
"""
from __future__ import annotations

import os
import struct
import sys
import zlib


def path_hash(path: str) -> int:
    p = path.replace("\\", "/")
    if len(p) > 1 and p[1] == ":":
        p = p[2:]
    if not p.startswith("/"):
        p = "/" + p
    return zlib.crc32(p.lower().encode("latin1")) & 0xFFFFFFFF


class Arc:
    def __init__(self, data: bytes):
        self.data = data
        pos = 0
        (size,) = struct.unpack_from(">I", data, 0)
        pos = 4
        if size == 0xFFFFFFFF:
            pos = 16
            (size,) = struct.unpack_from(">I", data, 12)
            pos = 16
        self.fat_size = size
        fat = bytearray(data[pos:pos + size])
        self.data_start = pos + size
        if bytes(fat[0x18:0x1B]) != b"PAM":
            key = struct.unpack_from(">I", fat, 0x18)[0]
            for o in range(0, 0x18, 4):
                struct.pack_into(">I", fat, o, struct.unpack_from(">I", fat, o)[0] ^ key)
            fat[0x18:0x20] = b"PAM-ZLB\0"
        self.fat = bytes(fat)
        rel, count = struct.unpack_from(">ii", self.fat, 0)
        self.entries = []
        if rel != -1 and count > 0:
            for i in range(count):
                self.entries.append(struct.unpack_from(">III", self.fat, rel + i * 12))
        self.entries.sort()

    def lookup(self, path: str):
        h = path_hash(path)
        for e in self.entries:
            if e[0] == h:
                return e
        return None

    def read(self, entry, try_zlib=True):
        _, off, size = entry
        raw = self.data[self.data_start + off:self.data_start + off + size]
        if try_zlib:
            try:
                return zlib.decompress(raw)
            except zlib.error:
                pass
        return raw


def load_names(path):
    m = {}
    if path:
        for line in open(path):
            line = line.strip()
            if line:
                m[path_hash(line)] = line
    return m


def main(argv):
    if len(argv) < 3 or argv[1] not in ("list", "extract", "hash"):
        print(__doc__)
        return 2
    if argv[1] == "hash":
        print("0x%08X" % path_hash(argv[2]))
        return 0
    names = load_names(argv[argv.index("--names") + 1]) if "--names" in argv else {}
    a = Arc(open(argv[2], "rb").read())
    if argv[1] == "list":
        print("fat_size=0x%X data_start=0x%X files=%d" % (a.fat_size, a.data_start, len(a.entries)))
        for h, off, size in a.entries:
            print("0x%08X off=0x%X size=%d %s" % (h, off, size, names.get(h, "")))
        return 0
    out = argv[3]
    for e in a.entries:
        name = names.get(e[0], "unnamed_%08X.bin" % e[0]).lstrip("/")
        dst = os.path.join(out, name)
        os.makedirs(os.path.dirname(dst) or ".", exist_ok=True)
        open(dst, "wb").write(a.read(e))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
