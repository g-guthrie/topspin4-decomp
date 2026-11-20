#!/usr/bin/env python3
"""Xbox 360 texture reader for Top Spin 4 (XPR2 containers, Xenos fetch constants).

Container ("XPR2", all integers big endian), measured on the retail disc:

  0x00 u32 'XPR2'
  0x04 u32 header_size   bytes of header after the first 12 bytes
  0x08 u32 data_size     bytes of GPU data; data starts at 12 + header_size
  0x0C u32 count         resources
  0x10 count * { u32 type ('TX2D' ...), u32 offset, u32 size, u32 name_offset }
       offset / name_offset are relative to file offset 0x0C
  ...  resource headers (TX2D: size 0x34 = D3DResource 6 dwords, 2 flush dwords,
       one 6-dword GPUTEXTURE_FETCH_CONSTANT), then NUL terminated names, then
       (padding) the data section.

The fetch constant fields follow the public Xenos register layout (see the
openly licensed Xenia project, BSD-3-Clause, src/xenia/gpu/xenos.h
``xe_gpu_texture_fetch_t``):

  dword0  bits 0-1 type (2 = texture), bits 22-30 pitch (32 texel units), bit 31 tiled
  dword1  bits 0-5 format (GPUTEXTUREFORMAT), 6-7 endianness, 12-31 base address >> 12
  dword2  2-D: bits 0-12 width-1, 13-25 height-1
  dword4  bits 2-5 mip_min_level, 6-9 mip_max_level
  dword5  bit 9 packed_mips, bits 12-31 mip address >> 12

The Xenos 2-D tiling ("XGAddress2DTiledOffset") is the one implemented in Xenia's
``TextureInfo::TiledOffset2DOuter/Inner`` and in several other open projects
(libxenon, Noesis plugins); it is re-derived here from that public description:
texels (or 4x4 blocks for DXT/DXN/CTX1) are grouped in 32x32 macro tiles whose
internal order interleaves x bits 0-2, y bits 1-2, ... as in ``tiled_offset``.

Only the base mip level of 2-D textures is decoded.  Standard library only.
"""
import os
import struct
import sys
import zlib

# --- GPUTEXTUREFORMAT values seen / handled -------------------------------------------------
K_8 = 2
K_1_5_5_5 = 3
K_5_6_5 = 4
K_8_8_8_8 = 6
K_2_10_10_10 = 7
K_8_8 = 10
K_4_4_4_4 = 15
K_DXT1 = 18
K_DXT2_3 = 19
K_DXT4_5 = 20
K_16 = 24
K_16_16 = 25
K_16_16_16_16 = 26
K_16_FLOAT = 30
K_16_16_FLOAT = 31
K_16_16_16_16_FLOAT = 32
K_32_FLOAT = 36
K_32_32_32_32_FLOAT = 38
K_DXN = 49
K_DXT3A = 58
K_DXT5A = 59
K_CTX1 = 60

FORMAT_NAMES = {
    2: "8", 3: "1_5_5_5", 4: "5_6_5", 6: "8_8_8_8", 7: "2_10_10_10", 8: "8_A", 9: "8_B",
    10: "8_8", 15: "4_4_4_4", 18: "DXT1", 19: "DXT2_3", 20: "DXT4_5", 24: "16", 25: "16_16",
    26: "16_16_16_16", 30: "16_FLOAT", 31: "16_16_FLOAT", 32: "16_16_16_16_FLOAT",
    36: "32_FLOAT", 38: "32_32_32_32_FLOAT", 49: "DXN", 58: "DXT3A", 59: "DXT5A", 60: "CTX1",
}
# format -> (block width/height in texels, bytes per block)
BLOCK_INFO = {
    K_DXT1: (4, 8), K_DXT2_3: (4, 16), K_DXT4_5: (4, 16), K_DXN: (4, 16),
    K_DXT3A: (4, 8), K_DXT5A: (4, 8), K_CTX1: (4, 8),
    K_8: (1, 1), K_1_5_5_5: (1, 2), K_5_6_5: (1, 2), K_4_4_4_4: (1, 2), K_8_8: (1, 2),
    K_8_8_8_8: (1, 4), K_2_10_10_10: (1, 4), K_16: (1, 2), K_16_16: (1, 4),
    K_16_16_16_16: (1, 8), K_16_FLOAT: (1, 2), K_16_16_FLOAT: (1, 4),
    K_16_16_16_16_FLOAT: (1, 8), K_32_FLOAT: (1, 4), K_32_32_32_32_FLOAT: (1, 16),
    8: (1, 1), 9: (1, 1),
}


class Texture:
    """One TX2D resource: name, fetch constant fields and the location of its data."""

    def __init__(self, name, fetch, data_start):
        self.name = name
        self.dwords = fetch
        d0, d1, d2, d3, d4, d5 = fetch
        self.tex_type = d0 & 3
        self.pitch = (d0 >> 22) & 0x1FF           # in 32 texel units
        self.tiled = bool(d0 >> 31)
        self.format = d1 & 0x3F
        self.endian = (d1 >> 6) & 3
        self.base = (d1 >> 12) << 12
        self.width = (d2 & 0x1FFF) + 1
        self.height = ((d2 >> 13) & 0x1FFF) + 1
        self.mip_min = (d4 >> 2) & 0xF
        self.mip_max = (d4 >> 6) & 0xF
        self.packed_mips = bool((d5 >> 9) & 1)
        self.mip_address = (d5 >> 12) << 12
        self.data_start = data_start

    @property
    def format_name(self):
        return FORMAT_NAMES.get(self.format, "fmt%d" % self.format)

    def base_level_size(self):
        bw, bpb = BLOCK_INFO[self.format]
        wb = -(-self.width // bw)
        hb = -(-self.height // bw)
        if self.tiled:
            wb = (wb + 31) & ~31
            hb = (hb + 31) & ~31
        return wb * hb * bpb


def parse_xpr2(buf):
    """Return (textures, other_resources) of an XPR2 file."""
    if buf[:4] != b"XPR2":
        raise ValueError("not XPR2")
    hsize, dsize, count = struct.unpack_from(">3I", buf, 4)
    data_start = 12 + hsize
    textures, others = [], []
    for i in range(count):
        typ, off, size, noff = struct.unpack_from(">4I", buf, 0x10 + 16 * i)
        nstart = 12 + noff
        name = buf[nstart:buf.index(b"\0", nstart)].decode("latin-1")
        if typ == 0x54583244:  # 'TX2D'
            fetch = struct.unpack_from(">6I", buf, 12 + off + 28)
            textures.append(Texture(name, fetch, data_start))
        else:
            others.append((typ.to_bytes(4, "big").decode("latin-1"), name, 12 + off, size))
    return textures, others


# --- Xenos tiling -----------------------------------------------------------------------------

def tiled_offset(x, y, width, log_bpp):
    """Byte offset of texel/block (x, y) in a Xenos 2-D tiled surface (XGAddress2DTiledOffset).

    Verified on retail data for 4, 8 and 16 byte texels/blocks (8888, DXT1/CTX1, DXT3/5/DXN), which
    are the only tiled formats on the disc.  For 1 and 2 byte texels the formula is a bijection
    only on surfaces aligned to 64 and has not been checked against data.

    ``width`` is the surface width in texels/blocks (aligned up to 32 internally);
    ``log_bpp`` is log2 of bytes per texel/block.
    """
    aligned = (width + 31) & ~31
    macro = ((x >> 5) + (y >> 5) * (aligned >> 5)) << (log_bpp + 7)
    micro = ((x & 7) + ((y & 6) << 2)) << log_bpp
    offset = macro + ((micro & ~15) << 1) + (micro & 15) + ((y & 8) << (3 + log_bpp)) + ((y & 1) << 4)
    return (((offset & ~0x1FF) << 3) + ((offset & 0x1C0) << 2) + (offset & 0x3F)
            + ((y & 16) << 7) + (((((y & 8) >> 2) + (x >> 3)) & 3) << 6))


def untile(data, wb, hb, bpb, offset=0):
    """Convert a tiled surface of wb x hb blocks (bpb bytes each) to linear row-major bytes."""
    log_bpp = bpb.bit_length() - 1
    out = bytearray(wb * hb * bpb)
    for y in range(hb):
        row = y * wb * bpb
        for x in range(wb):
            s = offset + tiled_offset(x, y, wb, log_bpp)
            d = row + x * bpb
            out[d:d + bpb] = data[s:s + bpb]
    return bytes(out)


def tile(linear, wb, hb, bpb):
    """Inverse of :func:`untile` (used by the tests); returns the padded tiled surface."""
    log_bpp = bpb.bit_length() - 1
    aw, ah = (wb + 31) & ~31, (hb + 31) & ~31
    out = bytearray(aw * ah * bpb)
    for y in range(hb):
        for x in range(wb):
            d = tiled_offset(x, y, wb, log_bpp)
            if d + bpb > len(out):
                out.extend(bytes(d + bpb - len(out)))
            s = (y * wb + x) * bpb
            out[d:d + bpb] = linear[s:s + bpb]
    return bytes(out)


def endian_swap(data, mode):
    """Apply a GPU endianness mode: 0 none, 1 8in16, 2 8in32, 3 16in32."""
    n = len(data) & ~3
    b = bytearray(data[:n])
    if mode == 1:
        b[0::2], b[1::2] = data[1:n:2], data[0:n:2]
    elif mode == 2:
        b[0::4], b[1::4], b[2::4], b[3::4] = data[3:n:4], data[2:n:4], data[1:n:4], data[0:n:4]
    elif mode == 3:
        b[0::4], b[1::4], b[2::4], b[3::4] = data[2:n:4], data[3:n:4], data[0:n:4], data[1:n:4]
    return bytes(b)


# --- block decoders (all return RGBA8 bytes, row-major, width*height*4) ---------------------

def _rgb565(c):
    r = (c >> 11) & 31
    g = (c >> 5) & 63
    b = c & 31
    return ((r << 3) | (r >> 2), (g << 2) | (g >> 4), (b << 3) | (b >> 2))


def _dxt_colors(c0, c1, force4):
    p0, p1 = _rgb565(c0), _rgb565(c1)
    if c0 > c1 or force4:
        p2 = tuple((2 * a + b) // 3 for a, b in zip(p0, p1))
        p3 = tuple((a + 2 * b) // 3 for a, b in zip(p0, p1))
        return [p0 + (255,), p1 + (255,), p2 + (255,), p3 + (255,)]
    p2 = tuple((a + b) // 2 for a, b in zip(p0, p1))
    return [p0 + (255,), p1 + (255,), p2 + (255,), (0, 0, 0, 0)]


def _dxt_alpha_table(a0, a1):
    if a0 > a1:
        return [a0, a1] + [((7 - i) * a0 + i * a1) // 7 for i in range(1, 7)]
    return [a0, a1] + [((5 - i) * a0 + i * a1) // 5 for i in range(1, 5)] + [0, 255]


def decode_dxt(data, w, h, fmt):
    """Decode DXT1 / DXT2_3 / DXT4_5 / DXN / DXT3A / DXT5A / CTX1 to RGBA8 (data already LE blocks)."""
    bw, bh = -(-w // 4), -(-h // 4)
    bpb = BLOCK_INFO[fmt][1]
    out = bytearray(w * h * 4)
    for by in range(bh):
        for bx in range(bw):
            blk = data[(by * bw + bx) * bpb:(by * bw + bx + 1) * bpb]
            px = [None] * 16
            if fmt in (K_DXT1, K_DXT2_3, K_DXT4_5):
                co = blk[bpb - 8:]
                c0, c1, bits = struct.unpack("<HHI", co)
                cols = _dxt_colors(c0, c1, fmt != K_DXT1)
                alpha = None
                if fmt == K_DXT2_3:
                    ab = int.from_bytes(blk[:8], "little")
                    alpha = [((ab >> (4 * i)) & 15) * 17 for i in range(16)]
                elif fmt == K_DXT4_5:
                    tab = _dxt_alpha_table(blk[0], blk[1])
                    ab = int.from_bytes(blk[2:8], "little")
                    alpha = [tab[(ab >> (3 * i)) & 7] for i in range(16)]
                for i in range(16):
                    c = cols[(bits >> (2 * i)) & 3]
                    px[i] = c if alpha is None else (c[0], c[1], c[2], alpha[i])
            elif fmt == K_DXN:
                tr = _dxt_alpha_table(blk[0], blk[1])
                tg = _dxt_alpha_table(blk[8], blk[9])
                rb = int.from_bytes(blk[2:8], "little")
                gb = int.from_bytes(blk[10:16], "little")
                for i in range(16):
                    px[i] = (tr[(rb >> (3 * i)) & 7], tg[(gb >> (3 * i)) & 7], 0, 255)
            elif fmt in (K_DXT3A, K_DXT5A):
                if fmt == K_DXT5A:
                    tab = _dxt_alpha_table(blk[0], blk[1])
                    ab = int.from_bytes(blk[2:8], "little")
                    v = [tab[(ab >> (3 * i)) & 7] for i in range(16)]
                else:
                    ab = int.from_bytes(blk[:8], "little")
                    v = [((ab >> (4 * i)) & 15) * 17 for i in range(16)]
                px = [(a, a, a, 255) for a in v]
            elif fmt == K_CTX1:
                x0, y0, x1, y1 = blk[0], blk[1], blk[2], blk[3]
                bits = struct.unpack("<I", blk[4:8])[0]
                pal = [(x0, y0), (x1, y1),
                       ((2 * x0 + x1) // 3, (2 * y0 + y1) // 3), ((x0 + 2 * x1) // 3, (y0 + 2 * y1) // 3)]
                px = [(pal[(bits >> (2 * i)) & 3] + (0, 255)) for i in range(16)]
            for i in range(16):
                x, y = bx * 4 + (i & 3), by * 4 + (i >> 2)
                if x < w and y < h:
                    o = (y * w + x) * 4
                    out[o:o + 4] = bytes(px[i])
    return bytes(out)


def decode_linear(data, w, h, fmt):
    """Decode an uncompressed format (bytes already in big-endian-in-memory order) to RGBA8."""
    out = bytearray(w * h * 4)
    n = w * h
    if fmt == K_8_8_8_8:
        for i in range(n):  # A R G B
            a, r, g, b = data[4 * i:4 * i + 4]
            out[4 * i:4 * i + 4] = bytes((r, g, b, a))
    elif fmt == K_5_6_5:
        for i in range(n):
            r, g, b = _rgb565(struct.unpack_from(">H", data, 2 * i)[0])
            out[4 * i:4 * i + 4] = bytes((r, g, b, 255))
    elif fmt == K_1_5_5_5:
        for i in range(n):
            v = struct.unpack_from(">H", data, 2 * i)[0]
            r, g, b = ((v >> 10) & 31) * 255 // 31, ((v >> 5) & 31) * 255 // 31, (v & 31) * 255 // 31
            out[4 * i:4 * i + 4] = bytes((r, g, b, 255 if v >> 15 else 0))
    elif fmt == K_4_4_4_4:
        for i in range(n):
            v = struct.unpack_from(">H", data, 2 * i)[0]
            out[4 * i:4 * i + 4] = bytes((((v >> 8) & 15) * 17, ((v >> 4) & 15) * 17, (v & 15) * 17, (v >> 12) * 17))
    elif fmt in (K_8, 8, 9):
        for i in range(n):
            v = data[i]
            out[4 * i:4 * i + 4] = bytes((v, v, v, 255))
    elif fmt == K_8_8:
        for i in range(n):
            out[4 * i:4 * i + 4] = bytes((data[2 * i], data[2 * i + 1], 0, 255))
    elif fmt == K_16:
        for i in range(n):
            v = data[2 * i]
            out[4 * i:4 * i + 4] = bytes((v, v, v, 255))
    elif fmt == K_16_16:
        for i in range(n):
            out[4 * i:4 * i + 4] = bytes((data[4 * i], data[4 * i + 2], 0, 255))
    elif fmt == K_16_16_16_16:
        for i in range(n):
            out[4 * i:4 * i + 4] = bytes((data[8 * i], data[8 * i + 2], data[8 * i + 4], data[8 * i + 6]))
    elif fmt == K_2_10_10_10:
        for i in range(n):
            v = struct.unpack_from(">I", data, 4 * i)[0]
            out[4 * i:4 * i + 4] = bytes((((v >> 20) & 1023) >> 2, ((v >> 10) & 1023) >> 2, (v & 1023) >> 2, (v >> 30) * 85))
    else:
        raise ValueError("unsupported format %d" % fmt)
    return bytes(out)


def decode_texture(tex, buf):
    """Decode the base mip level of ``tex`` (an XPR2 buffer ``buf``) to RGBA8 bytes."""
    bw, bpb = BLOCK_INFO[tex.format]
    wb, hb = -(-tex.width // bw), -(-tex.height // bw)
    start = tex.data_start + tex.base
    if tex.tiled:
        awb, ahb = (wb + 31) & ~31, (hb + 31) & ~31
        raw = buf[start:start + awb * ahb * bpb]
        raw = endian_swap(raw, tex.endian)
        lin = untile(raw, wb, hb, bpb)
    else:
        stride = max(wb, (tex.pitch * 32) // bw)          # linear surfaces: pitch is in 32 texel units
        raw = endian_swap(buf[start:start + stride * hb * bpb], tex.endian)
        if stride != wb:
            lin = b"".join(raw[y * stride * bpb:y * stride * bpb + wb * bpb] for y in range(hb))
        else:
            lin = raw
    if bw == 4:
        return decode_dxt(lin, tex.width, tex.height, tex.format)
    return decode_linear(lin, tex.width, tex.height, tex.format)


def reconstruct_normal_map(rgba, w, h):
    """DXN data stores X,Y in R,G; rebuild Z into B so the PNG is a usable tangent normal map."""
    out = bytearray(rgba)
    for i in range(w * h):
        x = rgba[4 * i] / 127.5 - 1.0
        y = rgba[4 * i + 1] / 127.5 - 1.0
        z = max(0.0, 1.0 - x * x - y * y) ** 0.5
        out[4 * i + 2] = int(max(0, min(255, round((z + 1.0) * 127.5))))
    return bytes(out)


# --- PNG writer -------------------------------------------------------------------------------

def write_png(path, rgba, w, h):
    """Write RGBA8 (or RGB8 when no pixel has alpha < 255) as a PNG using zlib only."""
    opaque = all(rgba[i] == 255 for i in range(3, len(rgba), 4))
    ch = 3 if opaque else 4
    rows = bytearray()
    stride = w * 4
    for y in range(h):
        rows.append(0)
        row = rgba[y * stride:(y + 1) * stride]
        if opaque:
            rb = bytearray(w * 3)
            rb[0::3], rb[1::3], rb[2::3] = row[0::4], row[1::4], row[2::4]
            rows += rb
        else:
            rows += row

    def chunk(tag, payload):
        c = struct.pack(">I", len(payload)) + tag + payload
        return c + struct.pack(">I", zlib.crc32(tag + payload) & 0xFFFFFFFF)

    png = b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", struct.pack(">IIBBBBB", w, h, 8, 2 if ch == 3 else 6, 0, 0, 0))
    png += chunk(b"IDAT", zlib.compress(bytes(rows), 6)) + chunk(b"IEND", b"")
    if path is None:
        return png
    with open(path, "wb") as f:
        f.write(png)
    return png


def read_png(png):
    """Minimal PNG reader for the files this module writes (8-bit RGB/RGBA, filter 0)."""
    pos = 8
    idat = b""
    while pos < len(png):
        ln, tag = struct.unpack_from(">I4s", png, pos)
        body = png[pos + 8:pos + 8 + ln]
        if tag == b"IHDR":
            w, h, depth, ctype = struct.unpack(">IIBB", body[:10])
        elif tag == b"IDAT":
            idat += body
        pos += 12 + ln
    ch = 3 if ctype == 2 else 4
    raw = zlib.decompress(idat)
    return w, h, ch, [raw[y * (w * ch + 1) + 1:(y + 1) * (w * ch + 1)] for y in range(h)]


def texture_stats(rgba, w, h):
    """Small histogram summary used by the structural checks."""
    n = w * h
    step = max(1, n // 4096)
    sums = [0, 0, 0, 0]
    lo = [255] * 4
    hi = [0] * 4
    cnt = 0
    for i in range(0, n, step):
        for c in range(4):
            v = rgba[4 * i + c]
            sums[c] += v
            lo[c] = min(lo[c], v)
            hi[c] = max(hi[c], v)
        cnt += 1
    return {"mean": [round(s / cnt, 1) for s in sums], "min": lo, "max": hi}


def main(argv=None):
    import argparse
    ap = argparse.ArgumentParser(description="list or export textures from an XPR2 file")
    ap.add_argument("xpr")
    ap.add_argument("--out", help="directory for PNG export")
    a = ap.parse_args(argv)
    buf = open(a.xpr, "rb").read()
    texs, others = parse_xpr2(buf)
    for t in texs:
        print("%-40s %4dx%-4d %-10s tiled=%d endian=%d mips=%d" % (t.name, t.width, t.height, t.format_name,
                                                                   t.tiled, t.endian, t.mip_max))
        if a.out:
            os.makedirs(a.out, exist_ok=True)
            rgba = decode_texture(t, buf)
            write_png(os.path.join(a.out, t.name + ".png"), rgba, t.width, t.height)
    for o in others:
        print("other resource", o)


if __name__ == "__main__":
    main()
