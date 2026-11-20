#!/usr/bin/env python3
"""Untile a Xenos 2D-tiled 32-bit texture dump (e.g. a front buffer) into a PPM image.

  python3 tools/recomp/untile_xenos.py DUMP.bin WIDTH HEIGHT OUT.ppm [--order argb|bgra|rgba|abgr]
                                       [--linear] [--stats]

DUMP.bin comes from the ts4 host (TS4_DUMP_PHYS=addr:size). The guest stores 8_8_8_8 texels as
big-endian 32-bit words; --order names the byte order of the four bytes in the dump (default
argb, i.e. D3DFMT_A8R8G8B8 as the guest writes it). --linear skips untiling. --stats prints the
fraction of non-zero pixels and the mean value. Standard library only.
"""

from __future__ import annotations

import argparse
import sys


def tiled_offset_2d(x: int, y: int, width: int, log_bpp: int = 2) -> int:
    """Texel index of (x, y) in a Xenos 2D-tiled surface (XGAddress2DTiledOffset)."""
    aligned_width = (width + 31) & ~31
    macro = ((x >> 5) + (y >> 5) * (aligned_width >> 5)) << (log_bpp + 7)
    micro = ((x & 7) + ((y & 6) << 2)) << log_bpp
    offset = macro + ((micro & ~15) << 1) + (micro & 15) + ((y & 8) << (3 + log_bpp)) + ((y & 1) << 4)
    return (((offset & ~511) << 3) + ((offset & 448) << 2) + (offset & 63)
            + ((y & 16) << 7) + (((((y & 8) >> 2) + (x >> 3)) & 3) << 6)) >> log_bpp


def untile(data: bytes, width: int, height: int, order: str = "argb", linear: bool = False) -> bytes:
    """Return packed RGB rows for the image."""
    idx = {c: order.index(c) for c in "rgb"}
    out = bytearray(width * height * 3)
    for y in range(height):
        for x in range(width):
            t = (y * width + x) if linear else tiled_offset_2d(x, y, width)
            p = data[4 * t:4 * t + 4]
            if len(p) < 4:
                continue
            o = 3 * (y * width + x)
            out[o] = p[idx["r"]]
            out[o + 1] = p[idx["g"]]
            out[o + 2] = p[idx["b"]]
    return bytes(out)


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("dump")
    ap.add_argument("width", type=int)
    ap.add_argument("height", type=int)
    ap.add_argument("out")
    ap.add_argument("--order", default="argb", choices=["argb", "bgra", "rgba", "abgr"])
    ap.add_argument("--linear", action="store_true")
    ap.add_argument("--stats", action="store_true")
    a = ap.parse_args(argv)
    data = open(a.dump, "rb").read()
    rgb = untile(data, a.width, a.height, a.order, a.linear)
    with open(a.out, "wb") as f:
        f.write(b"P6\n%d %d\n255\n" % (a.width, a.height))
        f.write(rgb)
    if a.stats:
        nonzero = sum(1 for i in range(0, len(rgb), 3) if rgb[i] | rgb[i + 1] | rgb[i + 2])
        print(f"nonzero_pixels={nonzero / (a.width * a.height):.4f} mean={sum(rgb) / len(rgb):.2f}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
