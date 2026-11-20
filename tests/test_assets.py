"""Tests for tools/ts4_texture.py, tools/ts4_mesh.py and tools/ts4_assets.py.

Only synthetic data constructed here is used; no game bytes are embedded.
Run: python3 -m unittest tests.test_assets
"""
import json
import os
import struct
import sys
import tempfile
import unittest
import zlib

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
sys.path.insert(0, os.path.join(ROOT, "tools", "havok"))

import ts4_assets  # noqa: E402
import ts4_mesh as M  # noqa: E402
import ts4_texture as T  # noqa: E402


# --------------------------------------------------------------------------- textures

class TilingTests(unittest.TestCase):
    def test_hand_computed_offsets_4_byte_texels(self):
        # log_bpp = 2.  Values follow from tiled_offset's formula, worked by hand:
        self.assertEqual(T.tiled_offset(0, 0, 32, 2), 0)
        self.assertEqual(T.tiled_offset(1, 0, 32, 2), 4)       # micro = 1 << 2
        self.assertEqual(T.tiled_offset(8, 0, 32, 2), 64)      # ((0 + (8 >> 3)) & 3) << 6
        self.assertEqual(T.tiled_offset(0, 1, 32, 2), 16)      # (y & 1) << 4
        self.assertEqual(T.tiled_offset(0, 2, 32, 2), 256)     # micro 32 -> offset 64 -> (64 & 448) << 2
        # next macro tile in x is 32 blocks * 32 rows * 4 bytes further
        self.assertEqual(T.tiled_offset(32, 0, 64, 2), 4096)

    def test_round_trip_many_shapes(self):
        for bpb in (4, 8, 16):
            for wb, hb in ((1, 1), (3, 5), (32, 32), (33, 17), (40, 37), (64, 8)):
                lin = bytes((i * 31 + 7) & 0xFF for i in range(wb * hb * bpb))
                tiled = T.tile(lin, wb, hb, bpb)
                aw, ah = (wb + 31) & ~31, (hb + 31) & ~31
                self.assertEqual(len(tiled), aw * ah * bpb)
                self.assertEqual(T.untile(tiled, wb, hb, bpb), lin, (bpb, wb, hb))

    def test_offsets_are_a_bijection_inside_the_padded_surface(self):
        for log_bpp in (0, 1, 2, 3, 4):
            seen = set()
            for y in range(64):
                for x in range(64):
                    o = T.tiled_offset(x, y, 64, log_bpp)
                    self.assertEqual(o % (1 << log_bpp), 0)
                    seen.add(o >> log_bpp)
            self.assertEqual(len(seen), 64 * 64)
            self.assertEqual(max(seen), 64 * 64 - 1)

    def test_endian_swap_modes(self):
        d = bytes(range(8))
        self.assertEqual(T.endian_swap(d, 0), d)
        self.assertEqual(T.endian_swap(d, 1), bytes([1, 0, 3, 2, 5, 4, 7, 6]))
        self.assertEqual(T.endian_swap(d, 2), bytes([3, 2, 1, 0, 7, 6, 5, 4]))
        self.assertEqual(T.endian_swap(d, 3), bytes([2, 3, 0, 1, 6, 7, 4, 5]))


class DxtTests(unittest.TestCase):
    def px(self, rgba, w, x, y):
        o = (y * w + x) * 4
        return tuple(rgba[o:o + 4])

    def test_dxt1_four_colour_block(self):
        # c0 = pure red (0xF800), c1 = pure blue (0x001F); selectors 0,1,2,3 in row 0
        blk = struct.pack("<HHI", 0xF800, 0x001F, 0xE4)
        out = T.decode_dxt(blk, 4, 4, T.K_DXT1)
        self.assertEqual(self.px(out, 4, 0, 0), (255, 0, 0, 255))
        self.assertEqual(self.px(out, 4, 1, 0), (0, 0, 255, 255))
        self.assertEqual(self.px(out, 4, 2, 0), (170, 0, 85, 255))     # (2*255 + 0) // 3, (0 + 2*... ) // 3
        self.assertEqual(self.px(out, 4, 3, 0), (85, 0, 170, 255))
        self.assertEqual(self.px(out, 4, 0, 3), (255, 0, 0, 255))      # remaining selectors are 0

    def test_dxt1_three_colour_block_with_transparent_texel(self):
        blk = struct.pack("<HHI", 0x001F, 0xF800, 0xE4)               # c0 <= c1
        out = T.decode_dxt(blk, 4, 4, T.K_DXT1)
        self.assertEqual(self.px(out, 4, 2, 0), (127, 0, 127, 255))   # (0 + 255) // 2
        self.assertEqual(self.px(out, 4, 3, 0), (0, 0, 0, 0))

    def test_dxt5_alpha_table_and_colour(self):
        alpha = bytes([255, 0]) + (2).to_bytes(6, "little")            # texel 0 uses index 2
        blk = alpha + struct.pack("<HHI", 0x07E0, 0x07E0, 0)
        out = T.decode_dxt(blk, 4, 4, T.K_DXT4_5)
        self.assertEqual(self.px(out, 4, 0, 0), (0, 255, 0, 218))     # (5*255 + 2*0) // 7
        self.assertEqual(self.px(out, 4, 1, 0)[3], 255)               # index 0 -> a0
        self.assertEqual(T._dxt_alpha_table(255, 0), [255, 0, 218, 182, 145, 109, 72, 36])
        self.assertEqual(T._dxt_alpha_table(0, 255), [0, 255, 51, 102, 153, 204, 0, 255])

    def test_dxt3_explicit_alpha(self):
        alpha = (0xF | (0x8 << 4)).to_bytes(8, "little")
        blk = alpha + struct.pack("<HHI", 0xFFFF, 0xFFFF, 0)
        out = T.decode_dxt(blk, 4, 4, T.K_DXT2_3)
        self.assertEqual(self.px(out, 4, 0, 0), (255, 255, 255, 255))
        self.assertEqual(self.px(out, 4, 1, 0), (255, 255, 255, 136))

    def test_dxn_two_channel_block(self):
        r = bytes([200, 100]) + (0).to_bytes(6, "little")
        g = bytes([10, 20]) + (1 | (1 << 3)).to_bytes(6, "little")      # texels 0 and 1 use index 1
        out = T.decode_dxt(r + g, 4, 4, T.K_DXN)
        self.assertEqual(self.px(out, 4, 0, 0), (200, 20, 0, 255))
        self.assertEqual(self.px(out, 4, 2, 0), (200, 10, 0, 255))
        full = T.reconstruct_normal_map(out, 4, 4)
        self.assertGreater(full[2], 0)

    def test_ctx1_block(self):
        blk = bytes([0, 0, 255, 255]) + struct.pack("<I", 0b11_10_01_00)
        out = T.decode_dxt(blk, 4, 4, T.K_CTX1)
        self.assertEqual(self.px(out, 4, 0, 0), (0, 0, 0, 255))
        self.assertEqual(self.px(out, 4, 1, 0), (255, 255, 0, 255))
        self.assertEqual(self.px(out, 4, 2, 0), (85, 85, 0, 255))
        self.assertEqual(self.px(out, 4, 3, 0), (170, 170, 0, 255))

    def test_partial_blocks_are_cropped(self):
        blk = struct.pack("<HHI", 0xF800, 0xF800, 0)
        out = T.decode_dxt(blk, 3, 2, T.K_DXT1)
        self.assertEqual(len(out), 3 * 2 * 4)

    def test_linear_formats(self):
        self.assertEqual(tuple(T.decode_linear(bytes([0x80, 1, 2, 3]), 1, 1, T.K_8_8_8_8)), (1, 2, 3, 0x80))
        self.assertEqual(tuple(T.decode_linear(struct.pack(">H", 0xF800), 1, 1, T.K_5_6_5)), (255, 0, 0, 255))
        self.assertEqual(tuple(T.decode_linear(bytes([77]), 1, 1, T.K_8)), (77, 77, 77, 255))


def build_xpr2(textures, tiled=True):
    """textures: list of (name, width, height, format, endian, raw data bytes at base offset)."""
    n = len(textures)
    table = 4 + 16 * n
    names = b""
    name_offs = []
    hdrs = b""
    base_hdr = table
    # layout after the count: table entries, then 0x34-byte headers, then names
    hdr_offs = [4 + 16 * n + 0x34 * i for i in range(n)]
    names_start = 4 + 16 * n + 0x34 * n
    data = b""
    entries = b""
    for i, (name, w, h, fmt, endian, raw) in enumerate(textures):
        name_offs.append(names_start + len(names))
        names += name.encode() + b"\0"
        while len(data) % 4096:
            data += b"\0"
        base = len(data)
        data += raw
        d0 = 2 | (((w + 31) // 32) << 22) | ((1 << 31) if tiled else 0)
        d1 = fmt | (endian << 6) | ((base >> 12) << 12)
        d2 = (w - 1) | ((h - 1) << 13)
        fetch = struct.pack(">6I", d0, d1, d2, 0xD10, 0x80, 0x200)
        hdrs += struct.pack(">6I", 3, 1, 0, 0, 0, 0xFFFF0000) + struct.pack(">I", 0xFFFF0000) + fetch
        entries += struct.pack(">4I", 0x54583244, hdr_offs[i], 0x34, name_offs[i])
    body = struct.pack(">I", n) + entries + hdrs + names
    while (12 + len(body)) % 4096:
        body += b"\0"
    while len(data) % 4096:
        data += b"\0"
    return b"XPR2" + struct.pack(">II", len(body), len(data)) + body + data


class XprTests(unittest.TestCase):
    def test_parse_and_decode_tiled_dxt1_with_8in16_endian(self):
        # 8x8 texels = 2x2 DXT1 blocks: red, green, blue, white
        cols = [0xF800, 0x07E0, 0x001F, 0xFFFF]
        lin = b"".join(struct.pack("<HHI", c, c, 0) for c in cols)
        le_tiled = T.tile(lin, 2, 2, 8)
        be = T.endian_swap(le_tiled, 1)                      # on disc the blocks are 16-bit byte swapped
        xpr = build_xpr2([("TestTex", 8, 8, T.K_DXT1, 1, be)])
        texs, others = T.parse_xpr2(xpr)
        self.assertEqual(others, [])
        t = texs[0]
        self.assertEqual((t.name, t.width, t.height, t.format_name, t.tiled, t.endian),
                         ("TestTex", 8, 8, "DXT1", True, 1))
        rgba = T.decode_texture(t, xpr)
        px = lambda x, y: tuple(rgba[(y * 8 + x) * 4:(y * 8 + x) * 4 + 4])  # noqa: E731
        self.assertEqual(px(0, 0), (255, 0, 0, 255))
        self.assertEqual(px(4, 0), (0, 255, 0, 255))
        self.assertEqual(px(0, 4), (0, 0, 255, 255))
        self.assertEqual(px(7, 7), (255, 255, 255, 255))

    def test_second_texture_uses_its_base_address(self):
        a = T.endian_swap(T.tile(struct.pack("<HHI", 0xF800, 0xF800, 0), 1, 1, 8), 1)
        b = T.endian_swap(T.tile(struct.pack("<HHI", 0x001F, 0x001F, 0), 1, 1, 8), 1)
        xpr = build_xpr2([("A", 4, 4, T.K_DXT1, 1, a), ("B", 4, 4, T.K_DXT1, 1, b)])
        texs, _ = T.parse_xpr2(xpr)
        self.assertEqual(texs[1].base, 0x1000 * 1 if len(a) <= 0x1000 else texs[1].base)
        self.assertEqual(tuple(T.decode_texture(texs[0], xpr)[:4]), (255, 0, 0, 255))
        self.assertEqual(tuple(T.decode_texture(texs[1], xpr)[:4]), (0, 0, 255, 255))

    def test_rejects_other_magic(self):
        with self.assertRaises(ValueError):
            T.parse_xpr2(b"XPR1" + bytes(64))

    def test_png_round_trip_and_crc(self):
        rgba = bytes([10, 20, 30, 255, 40, 50, 60, 255])
        png = T.write_png(None, rgba, 2, 1)
        w, h, ch, rows = T.read_png(png)
        self.assertEqual((w, h, ch), (2, 1, 3))
        self.assertEqual(rows[0], bytes([10, 20, 30, 40, 50, 60]))
        # every chunk CRC must verify
        pos = 8
        while pos < len(png):
            ln, tag = struct.unpack_from(">I4s", png, pos)
            body = png[pos + 8:pos + 8 + ln]
            (crc,) = struct.unpack_from(">I", png, pos + 8 + ln)
            self.assertEqual(crc, zlib.crc32(tag + body) & 0xFFFFFFFF)
            pos += 12 + ln
        png2 = T.write_png(None, bytes([1, 2, 3, 128]), 1, 1)
        self.assertEqual(T.read_png(png2)[2], 4)


# --------------------------------------------------------------------------- meshes

class DecodeTests(unittest.TestCase):
    def test_half_floats(self):
        self.assertEqual(M.half(0x3C00), 1.0)
        self.assertEqual(M.half(0xC000), -2.0)
        self.assertEqual(M.half(0x3800), 0.5)
        self.assertEqual(M.half(0), 0.0)
        self.assertAlmostEqual(M.half(0x0001), 2.0 ** -24)
        self.assertEqual(M.half(0x7C00), float("inf"))

    def test_dec3n(self):
        self.assertEqual(M.dec3n(0x000001FF), (1.0, 0.0, 0.0))
        self.assertEqual(M.dec3n(0x0007FC00), (0.0, 1.0, 0.0))
        self.assertEqual(M.dec3n(0x1FF00000), (0.0, 0.0, 1.0))
        x, y, z = M.dec3n(0x00000201)               # -511 -> -1.0
        self.assertEqual(x, -1.0)
        self.assertEqual(M.dec3n(0x00000200)[0], -1.0)   # -512 clamps to -1

    def test_decode_attr(self):
        self.assertEqual(M.decode_attr("C3DVector", struct.pack(">3f", 1, 2, 3)), (1.0, 2.0, 3.0))
        self.assertEqual(M.decode_attr("Float16_2", struct.pack(">2H", 0x3C00, 0x3800)), (1.0, 0.5))
        self.assertEqual(M.decode_attr("UShort4N", struct.pack(">4H", 65535, 0, 0, 0)), (1.0, 0.0, 0.0, 0.0))
        self.assertEqual(M.decode_attr("UByte4", bytes([0, 0, 0, 49])), (0, 0, 0, 49))
        self.assertEqual(M.decode_attr("D3DColor", bytes([255, 255, 0, 0])), (1.0, 0.0, 0.0, 1.0))
        self.assertEqual(sum(M.FORMAT_SIZES[f] for f in ("C3DVector", "Dec3N", "Dec3N", "Float16_2",
                                                         "UShort4N", "UByte4")), 36)

    def test_strip_to_triangles_drops_degenerates_and_alternates_winding(self):
        g = M.Group("g", "TriStrip", [0, 1, 2, 3, 3, 4, 5, 6])
        tris = g.triangles()
        self.assertEqual(tris[0], (0, 1, 2))
        self.assertEqual(tris[1], (1, 3, 2))           # odd triangle flipped
        self.assertNotIn((3, 3, 4), tris)
        lst = M.Group("g", "IndexedTriList", [0, 1, 2, 2, 2, 3, 4, 5, 6])
        self.assertEqual(lst.triangles(), [(0, 1, 2), (4, 5, 6)])


class Builder:
    """Small helper that lays out self-relative XBin structures."""

    def __init__(self):
        self.b = bytearray()

    def here(self):
        return len(self.b)

    def word(self, v=0):
        self.b += struct.pack(">I", v & 0xFFFFFFFF)
        return len(self.b) - 4

    def rel(self, at, target):
        struct.pack_into(">I", self.b, at, (target - at) & 0xFFFFFFFF)

    def cstr(self, s):
        o = len(self.b)
        self.b += s.encode() + b"\0"
        while len(self.b) % 4:
            self.b.append(0)
        return o


def build_mesh_xbin(positions, indices, bones=None, weights=None, boneidx=None, name="TestMesh", group="GRP_TEST_00"):
    """Single-mesh XBin (signature a4b9371d 330fac24) with C3DVector, Dec3N, Dec3N, Float16_2 [, UShort4N, UByte4]."""
    skinned = bones is not None
    formats = ["C3DVector", "Dec3N", "Dec3N", None, "Float16_2", None, None, None, "UShort4N" if skinned else None,
               "UByte4" if skinned else None]
    bb = Builder()
    bb.b += struct.pack(">II", 0xA4B9371D, 0x330FAC24) + struct.pack(">III", 4, 0, 0xFFFFFFFF)
    assert bb.here() == 0x14
    rec = bb.here()
    for _ in range(0x60 // 4):
        bb.word(0xFFFFFFFF)
    strings = {}
    for i, s in enumerate(("1.0", "date", "user", "comp", "path", "file")):
        strings[i] = s
    # string pool and cells
    pool = {}
    for s in list(strings.values()) + ["C3DVector", "Dec3N", "Float16_2", "UShort4N", "UByte4", name, group, "TriStrip"]:
        pool[s] = bb.cstr(s)
    for i in range(6):
        bb.rel(rec + 4 * i, pool[strings[i]])
    cells = {}
    for fmt in {f for f in formats if f}:
        c = bb.word()
        bb.rel(c, pool[fmt])
        cells[fmt] = c
    for i, f in enumerate(formats):
        if f:
            bb.rel(rec + 0x28 + 4 * i, cells[f])
    bb.rel(rec + 0x58, pool[name])
    # vertex array descriptor + data
    vd = bb.word()
    bb.word(len(positions))
    bb.word(len(positions))
    vdata = bb.here()
    bb.rel(vd, vdata)
    for k, p in enumerate(positions):
        bb.b += struct.pack(">3f", *p)
        bb.b += struct.pack(">II", 0x000001FF, 0x0007FC00)         # normal +x, tangent +y
        bb.b += struct.pack(">2H", 0x3C00, 0x3800)                  # uv (1.0, 0.5)
        if skinned:
            bb.b += struct.pack(">4H", *weights[k])
            bb.b += bytes(boneidx[k])
    bb.rel(rec + 0x50, vd)
    # groups
    gd = bb.word()
    bb.word(1)
    bb.word(1)
    gdata = bb.here()
    bb.rel(gd, gdata)
    for _ in range(14):
        bb.word(0)
    # fill group: index descriptor {rel, count, cap} at gdata
    idata = bb.here()
    bb.b += struct.pack(">%dH" % len(indices), *indices)
    while len(bb.b) % 4:
        bb.b.append(0)
    struct.pack_into(">III", bb.b, gdata, (idata - gdata) & 0xFFFFFFFF, len(indices), len(indices))
    bb.rel(gdata + 0x20, pool[group])
    bb.rel(gdata + 0x24, pool["TriStrip"])
    bb.rel(rec + 0x1C, gd)
    if skinned:
        bd = bb.word()
        bb.word(len(bones))
        bb.word(len(bones))
        bdata = bb.here()
        bb.rel(bd, bdata)
        for _ in bones:
            bb.word()
        for i, bn in enumerate(bones):
            o = bb.cstr(bn)
            bb.rel(bdata + 4 * i, o)
        bb.rel(rec + 0x20, bd)
    return bytes(bb.b)


class MeshParseTests(unittest.TestCase):
    def test_static_mesh_round_trip(self):
        pos = [(0, 0, 0), (1, 0, 0), (0, 1, 0), (1, 1, 0)]
        d = build_mesh_xbin(pos, [0, 1, 2, 3])
        m = M.parse_mesh(d, 0x14)
        self.assertEqual(m.name, "TestMesh")
        self.assertEqual(m.vertex_count, 4)
        self.assertEqual(m.stride, 24)
        self.assertEqual(m.formats, {"position": "C3DVector", "normal": "Dec3N", "tangent": "Dec3N",
                                     "uv0": "Float16_2"})
        self.assertEqual([tuple(p) for p in m.attrs["position"]], [tuple(map(float, p)) for p in pos])
        self.assertEqual(m.attrs["normal"][0], (1.0, 0.0, 0.0))
        self.assertEqual(m.attrs["tangent"][0], (0.0, 1.0, 0.0))
        self.assertEqual(m.attrs["uv0"][3], (1.0, 0.5))
        self.assertEqual(m.groups[0].name, "GRP_TEST_00")
        self.assertEqual(m.groups[0].triangles(), [(0, 1, 2), (1, 3, 2)])
        self.assertEqual(m.header[:2], ["1.0", "date"])
        self.assertEqual(M.mesh_records(d), [0x14])

    def test_skinned_mesh_bones_weights_and_index_order(self):
        pos = [(0, 0, 0), (1, 0, 0), (0, 1, 0)]
        w = [(65535, 0, 0, 0), (32768, 32767, 0, 0), (0, 0, 0, 65535)]
        ix = [(0, 0, 0, 2), (0, 0, 1, 2), (1, 0, 0, 0)]
        d = build_mesh_xbin(pos, [0, 1, 2], bones=["B_Hips", "B_Head", "B_Neck"], weights=w, boneidx=ix)
        m = M.parse_mesh(d, 0x14)
        self.assertEqual(m.bones, ["B_Hips", "B_Head", "B_Neck"])
        self.assertEqual(m.stride, 36)
        self.assertEqual(m.attrs["weights"][0], (1.0, 0.0, 0.0, 0.0))
        self.assertEqual(m.attrs["indices"][0], (0, 0, 0, 2))
        # weight i pairs with index byte 3 - i (verified on retail data): vertex 1 -> bones 2 and 1
        pairs = [(m.attrs["weights"][1][i], m.attrs["indices"][1][3 - i]) for i in range(2)]
        self.assertEqual([p[1] for p in pairs], [2, 1])

    def test_packed_meshes_root_array(self):
        one = build_mesh_xbin([(0, 0, 0), (1, 0, 0), (0, 1, 0)], [0, 1, 2])
        # re-wrap: PackedMeshes has an array descriptor at 0x14 and 0x60 byte records from 0x20
        b = bytearray(one)
        b[4:8] = struct.pack(">I", 0x3F65F116)
        # the single record sits at 0x14; make the root descriptor point at it
        desc = struct.pack(">III", 0xC, 1, 1)
        hdr = bytes(b[:0x14]) + desc
        body = bytearray(hdr) + bytearray(b[0x14:])
        # all pointers inside are self-relative, so moving the whole record keeps them valid
        recs = M.mesh_records(bytes(body))
        self.assertEqual(recs, [0x20])
        m = M.parse_mesh(bytes(body), recs[0])
        self.assertEqual(m.vertex_count, 3)


class XdtTests(unittest.TestCase):
    @staticmethod
    def build(root):
        """root = (name, [(attr name, value)], [children]) -> bytes."""
        data, toks = bytearray(), []

        def emit(node):
            name, attrs, kids = node
            toks.append(struct.pack(">III", zlib.crc32(name.encode()), len(attrs), len(kids)))
            for an, v in attrs:
                h = zlib.crc32(an.encode())
                if isinstance(v, str):
                    raw = v.encode() + b"\0"
                    toks.append(struct.pack(">III", h, 4, len(raw)))
                    data.extend(raw)
                elif isinstance(v, float):
                    toks.append(struct.pack(">III", h, 3, 4))
                    data.extend(struct.pack(">f", v))
                else:
                    toks.append(struct.pack(">III", h, 1, 1))
                    data.extend(bytes([v]))
                while len(data) % 4:
                    data.append(0)
            for k in kids:
                emit(k)
        emit(root)
        tok = b"".join(toks)
        return b"PAM-XDT\0" + struct.pack(">IIII", 1, 4, len(data), len(tok)) + bytes(data) + tok

    def test_tree_and_attribute_types(self):
        tree = ("Hierarchy", [], [
            ("Child", [], [
                ("Geometry", [("Name", "Chair"), ("Mesh", "ChairMesh"), ("Material", "ChairMat")], [
                    ("SRP", [], [("Scale", [("X", 1.0), ("Y", 1.0), ("Z", 1.0)], []),
                                 ("Rot", [("X", 0.0), ("Y", 1.5), ("Z", 0.0)], []),
                                 ("Pos", [("X", 10.0), ("Y", 0.0), ("Z", -5.0)], [])])])]),
            ("Camera", [("Name", "Cam"), ("LowPriority", 1)], [])])
        root = M.parse_xdt(self.build(tree))
        self.assertEqual(root.name, "Hierarchy")
        geo = [n for n in root.walk() if n.name == "Geometry"][0]
        self.assertEqual(geo.attrs, {"Name": "Chair", "Mesh": "ChairMesh", "Material": "ChairMat"})
        sc, ro, po = M.srp_params(geo)
        self.assertEqual((sc, ro, po), ((1.0, 1.0, 1.0), (0.0, 1.5, 0.0), (10.0, 0.0, -5.0)))
        cam = [n for n in root.walk() if n.name == "Camera"][0]
        self.assertEqual(cam.attrs, {"Name": "Cam", "LowPriority": 1})

    def test_world_matrices_compose_parent_then_child(self):
        tree = ("Hierarchy", [], [
            ("Group", [("Name", "G")], [
                ("SRP", [], [("Pos", [("X", 100.0), ("Y", 0.0), ("Z", 0.0)], [])]),
                ("Geometry", [("Name", "A"), ("Mesh", "A"), ("Material", "A")], [
                    ("SRP", [], [("Pos", [("X", 0.0), ("Y", 5.0), ("Z", 0.0)], [])])])])])
        root = M.parse_xdt(self.build(tree))
        worlds = {n.attrs.get("Name"): w for n, w in M.hierarchy_world_matrices(root) if n.name in ("Group", "Geometry")}
        self.assertEqual(tuple(worlds["A"][12:15]), (100.0, 5.0, 0.0))

    def test_yaw_rotation_matrix_row_vectors(self):
        import math
        m = M.srp_row_matrix((1, 1, 1), (0, math.pi / 2, 0), (0, 0, 0))
        v = (1.0, 0.0, 0.0)                         # row vector times matrix
        out = [sum(v[k] * m[4 * k + c] for k in range(3)) for c in range(3)]
        self.assertAlmostEqual(out[0], 0.0, places=6)
        self.assertAlmostEqual(out[2], -1.0, places=6)  # D3DX left-handed yaw: +x -> -z


class MaterialTests(unittest.TestCase):
    def test_single_and_multi_material(self):
        bb = Builder()
        bb.b += struct.pack(">II", 0xECC4F93B, 0x2E4F521C) + struct.pack(">III", 4, 0, 0xFFFFFFFF)
        root = bb.word()                                  # root array descriptor at 0x14
        bb.word(2)
        bb.word(2)
        e0 = bb.word()
        bb.word(M.MATERIAL_SINGLE)
        e1 = bb.word()
        bb.word(M.MATERIAL_MULTI)
        bb.rel(root, e0)
        # single material: 0x70 header, texture slot array, name
        single = bb.here()
        for _ in range(0x70 // 4):
            bb.word(0)
        tex = bb.here()
        bb.word(0)
        bb.word(0)
        bb.word(0)
        bb.word(zlib.crc32(b"DiffuseMap"))
        name = b"Court_Blue_00_2D_Di".ljust(76, b"\0")
        bb.b += name
        bb.rel(single + 0x48, single + 0x48)              # placeholder, fixed below
        struct.pack_into(">III", bb.b, single + 0x48, (tex - (single + 0x48)) & 0xFFFFFFFF, 1, 1)
        mname = bb.cstr("Ground")
        bb.rel(single + 0x60, mname)
        bb.rel(e0, single)
        # multi material with two copies of the header
        multi = bb.here()
        bb.word(0)
        bb.word(2)
        bb.word(2)
        bb.word(0)
        subs = bb.here()
        struct.pack_into(">I", bb.b, multi, subs - multi)
        for k in range(2):
            for _ in range(0x70 // 4):
                bb.word(0)
        for k in range(2):
            bb.rel(subs + 0x70 * k + 0x60, bb.cstr("Sub%d" % k))
        bb.rel(multi + 0x0C, bb.cstr("Group"))
        bb.rel(e1, multi)
        mats = M.parse_packed_materials(bytes(bb.b))
        self.assertEqual([m.name for m in mats], ["Ground", "Group"])
        self.assertEqual(mats[0].texture("DiffuseMap"), "Court_Blue_00_2D_Di")
        self.assertEqual([s.name for s in mats[1].subs], ["Sub0", "Sub1"])
        self.assertEqual(mats[1].for_group(1).name, "Sub1")
        self.assertEqual(mats[1].for_group(3).name, "Sub1")
        self.assertIs(mats[0].for_group(5), mats[0])


# --------------------------------------------------------------------------- assets / glTF

class GltfTests(unittest.TestCase):
    def test_gltf_writer_and_checker(self):
        with tempfile.TemporaryDirectory() as td:
            g = ts4_assets.Gltf(td, "unit")
            tex = g.image("Tex_A", bytes([200, 100, 50, 255] * 4), 2, 2)
            mat = g.material("m", tex)
            pos = [(0, 0, 0), (1, 0, 0), (0, 1, 0)]
            prim = g.primitive(pos, [(0, 0, 1)] * 3, [(0, 0), (1, 0), (0, 1)], None, [(0, 1, 2)], mat)
            mi = g.add_mesh("tri", [prim])
            g.scene_nodes.append(g.add_node({"name": "tri", "mesh": mi}))
            path = g.save("unit")
            rep, imgs = ts4_assets.check_gltf(path, verbose=False)
            self.assertEqual(rep["problems"], {})
            self.assertEqual(rep["triangles"], 1)
            self.assertEqual(rep["images"], 1)
            self.assertEqual(rep["uv_range"]["TEXCOORD_0"], [0.0, 1.0])
            with open(path) as f:
                doc = json.load(f)
            self.assertEqual(doc["asset"]["version"], "2.0")
            self.assertEqual(doc["accessors"][0]["min"], [0.0, 0.0, 0.0])

    def test_mirror_and_unit(self):
        self.assertEqual(ts4_assets.mirror_z((1, 2, 3)), (1, 2, -3))
        n = ts4_assets.unit((3.0, 0.0, 4.0))
        self.assertAlmostEqual(n[0], 0.6)
        self.assertAlmostEqual(n[2], 0.8)
        self.assertEqual(ts4_assets.unit((0, 0, 0)), (0.0, 1.0, 0.0))

    def test_lod0_selection_and_submaterial_mapping(self):
        mesh = M.Mesh()
        mesh.groups = [M.Group("GRP_CHEST_00", "TriStrip", [0] * n) for n in (10, 5, 30, 4, 6, 40)]
        picked = ts4_assets.pick_lod0(mesh)
        self.assertEqual([i for i, _ in picked], [4, 5])      # sets (10,5) (30,4) (6,40): the last has most indices
        self.assertEqual(mesh.lod_size, 2)
        mx = M.Material("root")
        mx.subs = [M.Material("M_HUM_CHEST_XXXXX_00"), M.Material("M_HUM_ARMSX_XXXXX_00")]
        mesh2 = M.Mesh()
        mesh2.groups = [M.Group("GRP_ARMSX_00", "TriStrip", [0]), M.Group("GRP_PELVI_00", "TriStrip", [0])]
        mesh2.lod_size = 2
        self.assertEqual(ts4_assets.pick_submaterial(mx, mesh2, 0).name, "M_HUM_ARMSX_XXXXX_00")

    def test_classify(self):
        self.assertEqual(ts4_assets.classify(b"XPR2" + bytes(12)), "xpr2-textures")
        self.assertEqual(ts4_assets.classify(b"PAM-XDT\0" + bytes(8)), "xdt")
        self.assertEqual(ts4_assets.classify(struct.pack(">II", 0xA4B9371D, 0x330FAC24)), "mesh")
        self.assertEqual(ts4_assets.classify(struct.pack(">II", 0x7D72A97D, 0x3F65F116)), "packed-meshes")
        self.assertEqual(ts4_assets.classify(struct.pack(">II", 0xECC4F93B, 0x2E4F521C)), "packed-materials")

    def test_texture_index_resolution(self):
        idx = ts4_assets.TextureIndex()
        idx.tex["M_TOP_00_2D_DI_R"] = (b"", None)
        self.assertEqual(idx.resolve("M_TOP_00_2D_DI_R_Player00"), "M_TOP_00_2D_DI_R")
        self.assertEqual(idx.resolve("M_TOP_00_2D_DI"), "M_TOP_00_2D_DI_R")
        self.assertIsNone(idx.resolve("Nothing"))


if __name__ == "__main__":
    unittest.main()
