"""Pure-logic tests for tools/decomp_survey.py (synthetic words only, no game files)."""
import json
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import decomp_survey as ds  # noqa: E402

LIS_R11_8800 = 0x3D608800      # lis r11, 0x8800
LWZ_R3_1234_R11 = 0x806B1234   # lwz r3, 0x1234(r11)
LWZ_R3_10_R4 = 0x80640010      # lwz r3, 0x10(r4)   (not lis-relative)
BL_FWD = 0x48000101            # bl +0x100
BLR = 0x4E800020
ADD_R3 = 0x7C632214            # add r3, r3, r4
ADD_R5 = 0x7CA52214            # add r5, r5, r4


class Ranges(unittest.TestCase):
    def test_sorted_and_disjoint(self):
        prev = 0
        for lo, hi, name, grp in ds.RANGES:
            self.assertLess(lo, hi, name)
            self.assertGreaterEqual(lo, prev, name)
            self.assertIn(grp, ("game", "lib", "sdk"))
            prev = hi

    def test_bucket_of(self):
        self.assertTrue(ds.bucket_of(0x88874270)[0].startswith("lib: zlib 1.2.3"))
        self.assertEqual(ds.bucket_of(0x80000000), ("unassigned", "game"))


class Normalise(unittest.TestCase):
    def test_call_targets_and_lis_pairs_are_masked(self):
        a = ds.normalise([LIS_R11_8800, LWZ_R3_1234_R11, BL_FWD, BLR])
        b = ds.normalise([LIS_R11_8800 + 3, LWZ_R3_1234_R11 + 0x40, BL_FWD + 0x800, BLR])
        self.assertEqual(a[0], b[0])
        self.assertEqual(a[1], b[1])

    def test_plain_displacements_are_kept_in_tier1(self):
        a = ds.normalise([LWZ_R3_10_R4, BLR])
        b = ds.normalise([LWZ_R3_10_R4 + 4, BLR])
        self.assertNotEqual(a[0], b[0])
        self.assertEqual(a[1], b[1])  # same opcodes

    def test_registers_matter_only_in_tier1(self):
        a = ds.normalise([ADD_R3, BLR])
        b = ds.normalise([ADD_R5, BLR])
        self.assertNotEqual(a[0], b[0])
        self.assertEqual(a[1], b[1])


class Loading(unittest.TestCase):
    def test_load_functions_marks_matches(self):
        with tempfile.TemporaryDirectory() as d:
            sym = Path(d) / "symbols.txt"
            sym.write_text(
                "fn_88150000 = .text:0x88150000; // type:function size:0x10\n"
                "lbl_88D00000 = .data:0x88D00000; // type:object size:0x4\n"
                "fn_88150010 = .text:0x88150010; // type:function size:0x20\n")
            match = Path(d) / "match.json"
            match.write_text(json.dumps({"matches": [{"text_range": "0x88150010-0x88150030", "source": "src/x.c"}]}))
            fns = ds.load_functions(sym, match)
            self.assertEqual([f["addr"] for f in fns], [0x88150000, 0x88150010])
            self.assertEqual([f["matched"] for f in fns], [False, True])

    def test_minhash_identical_sequences(self):
        perms = [(3, 5), (7, 11)]
        self.assertEqual(ds.minhash([1, 2, 3, 4, 5], perms), ds.minhash([1, 2, 3, 4, 5], perms))


if __name__ == "__main__":
    unittest.main()
