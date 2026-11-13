#!/usr/bin/env python3
"""Standard-library XDVDFS (Xbox / Xbox 360 game partition) reader.

Lists and extracts single files from a disc image by path, reading by offset.

  python3 tools/xdvdfs.py ISO --info
  python3 tools/xdvdfs.py ISO --list [--long]
  python3 tools/xdvdfs.py ISO --extract PATH --out DIR
"""
import argparse
import os
import struct
import sys

SECTOR = 2048
MAGIC = b"MICROSOFT*XBOX*MEDIA"
# Known partition start offsets (XGD1, XGD2, XGD3, raw XISO, XGD2 variant).
CANDIDATE_OFFSETS = (0x0, 0xFD90000, 0x2080000, 0x18300000, 0x2090000, 0x89D80000)


def find_partition(f):
    """Return the byte offset of the game partition (volume descriptor at +32 sectors)."""
    for off in CANDIDATE_OFFSETS:
        f.seek(off + 32 * SECTOR)
        if f.read(20) == MAGIC:
            return off
    raise ValueError("MICROSOFT*XBOX*MEDIA magic not found at known offsets")


def parse_volume(block):
    """Parse a 2048-byte volume descriptor -> (root_sector, root_size)."""
    if block[:20] != MAGIC:
        raise ValueError("bad volume descriptor magic")
    root_sector, root_size = struct.unpack_from("<II", block, 0x14)
    return root_sector, root_size


def parse_dir_entry(buf, pos):
    """Parse one entry at byte pos -> dict or None for padding (0xFFFF)."""
    left, right, sector, size, attr, nlen = struct.unpack_from("<HHIIBB", buf, pos)
    if left == 0xFFFF and right == 0xFFFF and sector == 0xFFFFFFFF:
        return None
    name = buf[pos + 14:pos + 14 + nlen].decode("latin-1")
    return dict(left=left, right=right, sector=sector, size=size, attr=attr, name=name)


def walk_dir(buf):
    """Yield all entries of a directory table by traversing the binary tree."""
    seen = set()
    stack = [0]
    while stack:
        pos = stack.pop()
        if pos in seen or pos + 14 > len(buf):
            continue
        seen.add(pos)
        e = parse_dir_entry(buf, pos)
        if e is None:
            continue
        yield e
        if e["left"]:
            stack.append(e["left"] * 4)
        if e["right"]:
            stack.append(e["right"] * 4)


class SliceFile:
    """Read-only seekable window [start, start+size) over an open binary file."""

    def __init__(self, f, start, size):
        self.f, self.start, self.size, self.pos = f, start, size, 0

    def seek(self, off, whence=0):
        self.pos = off if whence == 0 else (self.pos + off if whence == 1 else self.size + off)
        return self.pos

    def tell(self):
        return self.pos

    def read(self, n=-1):
        if n < 0 or self.pos + n > self.size:
            n = self.size - self.pos
        self.f.seek(self.start + self.pos)
        data = self.f.read(n)
        self.pos += len(data)
        return data


class XDVDFS:
    def __init__(self, path):
        self.f = open(path, "rb")
        self.base = find_partition(self.f)
        self.f.seek(self.base + 32 * SECTOR)
        self.root_sector, self.root_size = parse_volume(self.f.read(SECTOR))

    def read(self, sector, size, skip=0):
        self.f.seek(self.base + sector * SECTOR + skip)
        return self.f.read(size)

    def read_dir(self, sector, size):
        buf = self.read(sector, size)
        return sorted(walk_dir(buf), key=lambda e: e["name"].lower())

    def walk(self, sector=None, size=None, prefix=""):
        if sector is None:
            sector, size = self.root_sector, self.root_size
        for e in self.read_dir(sector, size):
            p = prefix + e["name"]
            if e["attr"] & 0x10:
                yield p + "/", e
                if e["size"]:
                    yield from self.walk(e["sector"], e["size"], p + "/")
            else:
                yield p, e

    def find(self, path):
        parts = [p for p in path.replace("\\", "/").split("/") if p]
        sector, size = self.root_sector, self.root_size
        ent = None
        for part in parts:
            for e in self.read_dir(sector, size):
                if e["name"].lower() == part.lower():
                    ent = e
                    break
            else:
                raise FileNotFoundError(path)
            sector, size = ent["sector"], ent["size"]
        return ent

    def open_file(self, path):
        """Return (absolute byte offset, size) of a file inside the image."""
        e = self.find(path)
        return self.base + e["sector"] * SECTOR, e["size"]

    def open_slice(self, path):
        """Return a read-only seekable file-like view of one file inside the image."""
        off, size = self.open_file(path)
        return SliceFile(self.f, off, size)

    def extract(self, path, out_dir):
        e = self.find(path)
        os.makedirs(out_dir, exist_ok=True)
        dst = os.path.join(out_dir, os.path.basename(path.rstrip("/")))
        remaining = e["size"]
        self.f.seek(self.base + e["sector"] * SECTOR)
        with open(dst, "wb") as o:
            while remaining:
                chunk = self.f.read(min(remaining, 1 << 22))
                if not chunk:
                    break
                o.write(chunk)
                remaining -= len(chunk)
        return dst


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("iso")
    ap.add_argument("--info", action="store_true")
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--long", action="store_true")
    ap.add_argument("--extract")
    ap.add_argument("--out", default="work/disc/files")
    a = ap.parse_args()
    x = XDVDFS(a.iso)
    if a.info:
        print("partition offset 0x%X root sector %d size %d" % (x.base, x.root_sector, x.root_size))
    if a.list:
        for p, e in x.walk():
            if a.long:
                print("%12d %10d %s" % (e["size"], e["sector"], p))
            else:
                print(p)
    if a.extract:
        print(x.extract(a.extract, a.out))


if __name__ == "__main__":
    sys.exit(main())
