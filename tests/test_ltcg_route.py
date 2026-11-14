"""Synthetic tests for tools/ltcg_route.py (no compiler, no game data)."""

import json
import struct
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))

import ltcg_route  # noqa: E402


def coff(code: bytes, name: str = "f") -> bytes:
    """One .text section holding `code`, one external symbol `name` at offset 0."""
    header_size, section_header = 20, 40
    raw = header_size + section_header
    symoff = raw + len(code)
    data = struct.pack("<HHIIIHH", 0x1F2, 1, 0, symoff, 1, 0, 0)
    data += struct.pack("<8sIIIIIIHHI", b".text", 0, 0, len(code), raw, 0, 0, 0, 0, 0x60000020)
    data += code
    data += struct.pack("<8sIhHBB", name.encode().ljust(8, b"\0"), 0, 1, 0x20, 2, 0)
    data += struct.pack("<I", 4)
    return data


def words(*values):
    return b"".join(v.to_bytes(4, "big") for v in values)


class LtcgRouteTest(unittest.TestCase):
    def test_patch_keeps_relocation_fields(self):
        target = coff(words(0x3D608812, 0x4BFFF001))           # lis r11,0x8812 ; bl far
        candidate = words(0x3D600000, 0x48000101)              # same opcodes, other fields
        masks = [0x0000FFFF, 0x03FFFFFC]
        out = ltcg_route.patch_object(target, [("f", candidate, masks)])
        self.assertEqual(out, target)

    def test_patch_refuses_a_different_instruction(self):
        target = coff(words(0x3D608812, 0x4E800020))
        candidate = words(0x3D408812, 0x4E800020)              # lis r10 instead of r11
        with self.assertRaises(SystemExit):
            ltcg_route.patch_object(target, [("f", candidate, [0xFFFF, 0])])

    def test_register_and_expected(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "ltcg_units.json"
            spec = {"source": "src/xbox360/lt1_example.c", "route": "ltcg", "context": [],
                    "flags": ["/GS-"], "functions": {"ts4_a": "0x88660000"}}
            ltcg_route.register(spec, {"ts4_a": 0x418}, path)
            units = ltcg_route.load_units(path)
            self.assertEqual(units[0]["object"], "lt1_example.obj")
            self.assertEqual(ltcg_route.expected_symbols(units), {"ts4_a": 0x418})
            with self.assertRaises(SystemExit):
                ltcg_route.register(spec, {"ts4_a": 0x418}, path)
            self.assertEqual(json.loads(path.read_text())[0]["flags"], ["/GS-"])

    def test_absolute_context(self):
        self.assertTrue(ltcg_route.absolute_context("nogl:src/x.c").startswith("nogl:/"))
        self.assertTrue(ltcg_route.absolute_context("src/x.c").endswith("src/x.c"))

    def test_no_units_means_no_work(self):
        with tempfile.TemporaryDirectory() as tmp:
            self.assertEqual(ltcg_route.load_units(Path(tmp) / "missing.json"), [])
            self.assertEqual(ltcg_route.build_units(Path(tmp), Path(tmp), Path(tmp), Path(tmp),
                                                    Path(tmp), units=[]), {})


if __name__ == "__main__":
    unittest.main()
