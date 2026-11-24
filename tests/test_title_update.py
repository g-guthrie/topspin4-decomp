"""Tests for tools/xex_patch.py, the --tu source of tools/ts4data/dump_tunables.py and tu_diff helpers.

Everything is synthetic (built here); no game bytes, keys or executables are used.
"""
import io
import os
import struct
import sys
import tempfile
import unittest

from tools import ts4_arc, ts4_lzx
from tools import xex_patch as XP
from tests.test_arc_write import build_arc

sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "tools", "ts4data"))
import dump_tunables as D  # noqa: E402
import tu_diff as T  # noqa: E402


def lzx_uncompressed(payload):
    """One LZX stream holding a single uncompressed block (E8 off), as the encoder lays it out."""
    bits = (0 << 27) | (3 << 24) | len(payload)          # 1 + 3 + 24 header bits, MSB first
    bits <<= 4                                            # pad to 32 bits (16-bit re-alignment)
    words = struct.pack("<HH", (bits >> 16) & 0xFFFF, bits & 0xFFFF)
    return words + struct.pack("<III", 1, 1, 1) + payload


class TestLzxDelta(unittest.TestCase):
    def test_uncompressed_block_and_consumed(self):
        data = bytes(range(200))
        stream = lzx_uncompressed(data) + b"\xAA\xBB"
        dec = ts4_lzx.LZXDecoder(15)
        self.assertEqual(dec.decode_frame(stream, len(data)), data)
        self.assertEqual(dec.consumed, 4 + 12 + len(data))

    def test_stream_with_reference_window(self):
        data = b"patched!" * 10
        out = XP.lzx_stream(lzx_uncompressed(data), len(data), 15, ref=b"\x01" * 100)
        self.assertEqual(out, data)

    def test_records_fill_copy_lzx(self):
        img = bytearray(b"ABCDEFGHIJKLMNOP" + bytes(16))
        payload = b"xyz!"
        lz = lzx_uncompressed(payload)
        recs = (struct.pack(">IIHH", 0, 0, 4, 0)                 # zero-fill 0..4
                + struct.pack(">IIHH", 4, 16, 8, 1)              # copy 4..12 -> 16..24
                + struct.pack(">IIHH", 0, 28, 4, len(lz)) + lz   # LZX into 28..32
                + bytes(12))                                     # terminator
        log = []
        n = XP.apply_records(recs, img, 0, len(recs), 15, log)
        self.assertEqual(n, 3)
        self.assertEqual(bytes(img[0:4]), bytes(4))
        self.assertEqual(bytes(img[16:24]), b"EFGHIJKL")
        self.assertEqual(bytes(img[28:32]), payload)
        self.assertEqual([r[3] for r in log], [0, 1, len(lz)])

    def test_window_bits(self):
        self.assertEqual(XP.window_bits(0x8000), 15)
        self.assertEqual(XP.window_bits(0x10000), 16)

    def test_key_file_forms(self):
        with tempfile.TemporaryDirectory() as d:
            raw = os.path.join(d, "k.bin")
            with open(raw, "wb") as f:
                f.write(bytes(range(16)))
            self.assertEqual(XP.load_retail_key(raw), bytes(range(16)))
            rs = os.path.join(d, "xex.rs")
            with open(rs, "w") as f:
                f.write("const RETAIL_KEY: [u8; 16] = [\n" + ", ".join("0x%02X" % i for i in range(16)) + "];\n")
            self.assertEqual(XP.load_retail_key(rs), bytes(range(16)))


class TestFunctionDiff(unittest.TestCase):
    LA = 0x88000000

    def test_normalize_masks_link_fields(self):
        # bl +0x100 / bl +0x200 ; lis r11,0x8810 + lwz r3,0x20(r11) vs other address halves
        a = struct.pack(">4I", 0x48000101, 0x3D608810, 0x806B0020, 0x4E800020)
        b = struct.pack(">4I", 0x48000201, 0x3D608811, 0x806B0040, 0x4E800020)
        na = XP.normalize_function(a, self.LA, self.LA, len(a))
        nb = XP.normalize_function(b, self.LA, self.LA, len(b))
        self.assertEqual(na, nb)

    def test_struct_offset_change_is_offsets_only(self):
        a = [0x80630570, 0x4E800020]          # lwz r3,0x570(r3)
        b = [0x80630580, 0x4E800020]          # lwz r3,0x580(r3)
        self.assertEqual(XP.classify_pair(a, b), "offsets")
        self.assertEqual(XP.classify_pair(a, [0x80830570, 0x4E800020]), "code")
        self.assertEqual(XP.classify_pair(a, a + [0]), "code")


class TestTuSource(unittest.TestCase):
    def test_title_update_member_wins(self):
        arc_bytes = build_arc({"alpha.bin": b"TU-DATA"})
        arc = ts4_arc.Arc(io.BytesIO(arc_bytes))
        key = arc.entries[0][0]
        with tempfile.TemporaryDirectory() as d:
            with open(os.path.join(d, "TitleUpdate.arc"), "wb") as f:
                f.write(arc_bytes)
            cache = os.path.join(d, "cache", "Core.arc")
            os.makedirs(cache)
            with open(os.path.join(cache, "%08x.bin" % key), "wb") as f:
                f.write(b"DISC-DATA")
            with open(os.path.join(cache, "%08x.bin" % (key ^ 1)), "wb") as f:
                f.write(b"OTHER")
            src = D.Source(cache=os.path.join(d, "cache"), tu=d)
            self.assertEqual(src.resolve("Core.arc", key), ("TitleUpdate.arc", b"TU-DATA"))
            self.assertEqual(src.resolve("Core.arc", key ^ 1), ("Core.arc", b"OTHER"))
            self.assertEqual(src.get("TitleUpdate.arc", key), b"TU-DATA")
            plain = D.Source(cache=os.path.join(d, "cache"))
            self.assertEqual(plain.resolve("Core.arc", key), ("Core.arc", b"DISC-DATA"))


class TestTuDiffYaml(unittest.TestCase):
    def test_to_yaml_round_shapes(self):
        doc = {"a": 1, "b": [1.5, -0.05], "c": [{"x": "p:q", "y": True}], "d": {}}
        text = "\n".join(T.to_yaml(doc))
        self.assertIn("a: 1", text)
        self.assertIn("b: [1.5, -0.05]", text)
        self.assertIn('x: "p:q"', text)
        self.assertIn("d: {}", text)

    def test_f32s_shortest(self):
        self.assertEqual(T.f32s(struct.unpack(">f", struct.pack(">f", 0.475))[0]), 0.475)


if __name__ == "__main__":
    unittest.main()
