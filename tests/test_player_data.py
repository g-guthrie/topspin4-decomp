"""Synthetic tests for tools/ts4data/player_data.py (no game data)."""
import os
import struct
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "tools", "ts4data"))
import player_data as P  # noqa: E402


def desc(at, target, count):
    return struct.pack(">iII", target - at, count, count)


class PlayerDataTest(unittest.TestCase):
    def test_curve16_array(self):
        buf = bytearray(64)
        buf[0:12] = desc(0, 16, 2)
        buf[16:48] = struct.pack(">8f", 0, 1, 0, 1, 1, 2, 1, 3)
        b = P.Bin(bytes(buf))
        self.assertEqual(P.decode_array(b, 0, {}), {"curve16": [[0.0, 1.0, 0.0, 1.0], [1.0, 2.0, 1.0, 3.0]]})

    def test_table2d(self):
        buf = bytearray(128)
        buf[0:12] = desc(0, 16, 2)
        for i, key in enumerate((100.0, 200.0)):
            row = 16 + 16 * i
            buf[row:row + 12] = desc(row, 64 + 16 * i, 1)
            buf[row + 12:row + 16] = struct.pack(">f", key)
            buf[64 + 16 * i:80 + 16 * i] = struct.pack(">4f", 0, 10, i, i + 1)
        out = P.decode_array(P.Bin(bytes(buf)), 0, {})
        self.assertEqual([r["key"] for r in out["table2d"]], [100.0, 200.0])
        self.assertEqual(out["table2d"][1]["curve16"], [[0.0, 10.0, 1.0, 2.0]])

    def test_style_and_zone(self):
        b = P.Bin(struct.pack(">4B4x2f", 0, 1, 0, 0, 3.0, 4.25))
        st = P.decode_field(b, 0, "style", {})
        self.assertEqual((st["volley_allowed"], st["speed_limit_mps"], st["volley_speed_limit_mps"]), (1, 3.0, 4.25))
        z = P.decode_field(P.Bin(struct.pack(">3f", 50, 100, 120)), 0, "zone", {})
        self.assertEqual(z["radius_cm"], 120.0)

    def test_crc_dictionary(self):
        s = b"EventRacket\0"
        data = bytearray(0x14) + desc(0x14, 0x20, 1) + b"\0" * 0
        data += struct.pack(">iI", 8, P.zlib.crc32(b"EventRacket")) + s
        self.assertEqual(P.read_crc_dictionary(bytes(data)), {0x3B9AD22E: "EventRacket"})

    def test_layout_members(self):
        """G4c: layout-driven walk of a reflected block (synthetic two-level type)."""
        class M:
            def __init__(self, name, type_, offset, size, kind=None, attr=True):
                self.name, self.type, self.offset, self.size, self.kind, self.attr = name, type_, offset, size, kind, attr

        class L:
            types = {
                0x100: (0x14, 4, [M(0xA, 0x200, 0, 8, P.KIND_INLINE, False), M(0xB, 0x6543E2E6, 8, 4),
                                  M(0xC, 0x68BABFBD, 0xC, 4), M(0xD, 0xF5E3B036, 0x10, 1)]),
                0x200: (8, 4, [M(0xE, 0xC692C255, 0, 4), M(0xF, 0xC692C255, 4, 4)]),
            }
        buf = struct.pack(">ffiIB3x", 1.5, -2.0, 7, 0x1234, 1)
        rows = P.layout_members(P.Bin(b"\0" * 4 + buf), L(), 0x100, 4, {0xA: "Outer", 0xE: "x", 0x1234: "Key"})
        self.assertEqual([r["path"] for r in rows], ["Outer.x", "Outer.0000000f", "0000000b", "0000000c", "0000000d"])
        self.assertEqual([r["value"] for r in rows], [1.5, -2.0, 7, "Key", 1])
        self.assertEqual(rows[2]["offset"], "+0x008")

    def test_yaml(self):
        text = "\n".join(P.to_yaml({"a": 1, "b": [1.5, 2], "c": {"d": "x: y"}, "e": [{"f": 1}]}))
        self.assertIn("a: 1", text)
        self.assertIn("b: [1.5, 2]", text)
        self.assertIn('"x: y"', text)


if __name__ == "__main__":
    unittest.main()
