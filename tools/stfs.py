#!/usr/bin/env python3
"""List or extract an Xbox 360 STFS package (LIVE/PIRS/CON: title updates, DLC).

Usage:
  python3 tools/stfs.py info    package.bin
  python3 tools/stfs.py list    package.bin
  python3 tools/stfs.py extract package.bin OUTDIR

Read-only, standard library only. Extract into ignored storage (orig/ or
work/) and never commit the output. Supports the single-level file table
layout used by title updates; multi-block files follow the block hash
tables (or the consecutive flag when set).
"""

from __future__ import annotations

import argparse
import struct
from pathlib import Path

BLOCK = 0x1000
PER_TABLE = 0xAA


def block_offset(header_size: int, shift: int, block: int) -> int:
    adjust = 0
    if block >= PER_TABLE:
        adjust += ((block // PER_TABLE) + 1) << shift
    if block >= PER_TABLE * PER_TABLE:
        adjust += ((block // (PER_TABLE * PER_TABLE)) + 1) << shift
    base = (header_size + 0xFFF) & ~0xFFF
    return base + ((block + adjust + (1 << shift)) * BLOCK)


class Package:
    def __init__(self, data: bytes):
        if data[:4] not in (b"LIVE", b"PIRS", b"CON "):
            raise SystemExit("not an STFS package")
        self.data = data
        be = lambda o: struct.unpack_from(">I", data, o)[0]
        self.header_size = be(0x340)
        self.content_type = be(0x344)
        self.media_id = be(0x354)
        self.version = be(0x358)
        self.base_version = be(0x35C)
        self.title_id = be(0x360)
        self.display_name = data[0x411:0x491].decode("utf-16-be", "ignore").split("\0")[0]
        separation = data[0x37B]
        # Read-only packages use one hash table per level (shift 0).
        self.shift = 0 if separation & 1 else 1
        self.table_blocks = struct.unpack_from("<H", data, 0x37C)[0]
        self.table_start = int.from_bytes(data[0x37E:0x381], "little")

    def hash_entry(self, block: int) -> int:
        """Return the next-block field of the level-0 hash entry for a block."""
        table_block = (block // PER_TABLE) * PER_TABLE
        offset = block_offset(self.header_size, self.shift, table_block) - (BLOCK << self.shift)
        entry = offset + (block % PER_TABLE) * 0x18
        return int.from_bytes(self.data[entry + 0x15 : entry + 0x18], "big")

    def read_block(self, block: int) -> bytes:
        offset = block_offset(self.header_size, self.shift, block)
        return self.data[offset : offset + BLOCK]

    def entries(self):
        raw = b""
        block = self.table_start
        for _ in range(self.table_blocks):
            raw += self.read_block(block)
            block = self.hash_entry(block)
        out = []
        for index in range(len(raw) // 0x40):
            entry = raw[index * 0x40 : index * 0x40 + 0x40]
            length = entry[0x28] & 0x3F
            if not length:
                break
            out.append({
                "name": entry[:length].decode("latin-1"),
                "directory": bool(entry[0x28] & 0x80 and False) or bool(entry[0x28] & 0x40 and not entry[0x34:0x38].strip(b"\0")),
                "consecutive": bool(entry[0x28] & 0x40),
                "blocks": int.from_bytes(entry[0x29:0x2C], "little"),
                "start": int.from_bytes(entry[0x2F:0x32], "little"),
                "parent": struct.unpack_from(">h", entry, 0x32)[0],
                "size": struct.unpack_from(">I", entry, 0x34)[0],
            })
        return out

    def read_file(self, entry) -> bytes:
        chunks = []
        block = entry["start"]
        for index in range(entry["blocks"]):
            chunks.append(self.read_block(block))
            block = block + 1 if entry["consecutive"] else self.hash_entry(block)
        return b"".join(chunks)[: entry["size"]]


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("command", choices=["info", "list", "extract"])
    parser.add_argument("package", type=Path)
    parser.add_argument("outdir", type=Path, nargs="?")
    args = parser.parse_args()
    package = Package(args.package.read_bytes())
    if args.command == "info":
        print(f"title {package.title_id:08X} media {package.media_id:08X} "
              f"content type {package.content_type:08X} version {package.version} "
              f"base {package.base_version} name {package.display_name!r}")
        return 0
    entries = package.entries()
    if args.command == "list":
        for entry in entries:
            print(f"{entry['size']:>10}  {entry['name']}")
        return 0
    if args.outdir is None:
        raise SystemExit("extract needs OUTDIR")
    outdir = args.outdir.resolve()
    for entry in entries:
        if entry["parent"] != -1:
            raise SystemExit("nested directories are not supported yet")
        target = (outdir / entry["name"]).resolve()
        if outdir not in target.parents:
            raise SystemExit(f"refusing to write outside {outdir}")
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(package.read_file(entry))
    print(f"extracted {len(entries)} files to {outdir}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
