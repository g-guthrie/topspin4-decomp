#!/usr/bin/env python3
"""List or extract files from an Xbox 360 disc image (XDVDFS / XGD2 / XGD3).

Usage:
  python3 tools/xiso.py list  image.iso [--filter SUBSTRING]
  python3 tools/xiso.py extract image.iso OUTDIR [PATH_PREFIX ...]

Extraction writes only under OUTDIR (keep it in ignored work/ or orig/).
Standard library only. Never commit extracted files.
"""

from __future__ import annotations

import argparse
import struct
import sys
from pathlib import Path

SECTOR = 2048
MAGIC = b"MICROSOFT*XBOX*MEDIA"
# Game-partition offsets: raw XDVDFS, XGD3, XGD2, XGD1.
PARTITION_OFFSETS = (0, 0x2080000, 0xFD90000, 0x18300000)


def find_partition(handle) -> tuple[int, int, int]:
    for offset in PARTITION_OFFSETS:
        handle.seek(offset + 32 * SECTOR)
        header = handle.read(0x24)
        if header[:20] == MAGIC:
            root_sector, root_size = struct.unpack_from("<II", header, 20)
            return offset, root_sector, root_size
    raise SystemExit("no XDVDFS volume descriptor found")


def walk(handle, base: int, sector: int, size: int, prefix: str = ""):
    """Yield (path, sector, size, is_dir) for a directory table."""
    if size == 0:
        return
    handle.seek(base + sector * SECTOR)
    table = handle.read(size)
    seen = set()
    stack = [0]
    while stack:
        offset = stack.pop()
        if offset in seen or offset + 14 > len(table):
            continue
        seen.add(offset)
        left, right, file_sector, file_size, attributes, name_len = struct.unpack_from(
            "<HHIIBB", table, offset
        )
        if left == 0xFFFF and right == 0xFFFF:
            continue
        name = table[offset + 14 : offset + 14 + name_len].decode("latin-1")
        path = f"{prefix}{name}"
        is_dir = bool(attributes & 0x10)
        yield path, file_sector, file_size, is_dir
        if is_dir:
            yield from walk(handle, base, file_sector, file_size, path + "/")
        if left and left != 0xFFFF:
            stack.append(left * 4)
        if right and right != 0xFFFF:
            stack.append(right * 4)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = parser.add_subparsers(dest="command", required=True)
    lister = sub.add_parser("list")
    lister.add_argument("image", type=Path)
    lister.add_argument("--filter", default="")
    extractor = sub.add_parser("extract")
    extractor.add_argument("image", type=Path)
    extractor.add_argument("outdir", type=Path)
    extractor.add_argument("prefixes", nargs="*")
    args = parser.parse_args()

    with args.image.open("rb") as handle:
        base, root_sector, root_size = find_partition(handle)
        entries = sorted(walk(handle, base, root_sector, root_size))
        if args.command == "list":
            total = 0
            for path, _sector, size, is_dir in entries:
                if args.filter.lower() in path.lower():
                    print(f"{'<dir>' if is_dir else size:>12}  {path}")
                    total += 0 if is_dir else size
            print(f"{total:,} bytes", file=sys.stderr)
            return 0
        outdir = args.outdir.resolve()
        count = 0
        for path, sector, size, is_dir in entries:
            if is_dir or (args.prefixes and not any(path.startswith(p) for p in args.prefixes)):
                continue
            target = (outdir / path).resolve()
            if outdir not in target.parents:
                raise SystemExit(f"refusing to write outside {outdir}: {path}")
            target.parent.mkdir(parents=True, exist_ok=True)
            handle.seek(base + sector * SECTOR)
            remaining = size
            with target.open("wb") as out:
                while remaining:
                    chunk = handle.read(min(remaining, 1 << 20))
                    if not chunk:
                        raise SystemExit(f"truncated image while reading {path}")
                    out.write(chunk)
                    remaining -= len(chunk)
            count += 1
        print(f"extracted {count} files to {outdir}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
