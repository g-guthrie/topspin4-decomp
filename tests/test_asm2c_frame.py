"""Tests for tools/asm2c/frame.py (stack-frame model); pure text, no compiler."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools" / "asm2c"))
import frame  # noqa: E402

BODY = """    ts4_word loc58[2];
    ts4_word loc60[4];
    ts4_word loc50[2];
    ts4_word t5;

    f((ts4_word)(ts4_word)&loc58[0]);
    *(ts4_u64 *)g = (ts4_u64)*(ts4_u64 *)((char *)loc58 + 0);
    loc60[0] = (ts4_word)1;
    loc60[1] = (ts4_word)2;
    loc60[2] = (ts4_word)3;
    f((ts4_word)&loc50[0]);
    t5 = f((ts4_word)(ts4_word)&loc60[0]);
"""


class FrameSplitTests(unittest.TestCase):
    def test_word_plan_scalarises_out_params(self):
        b = frame.split(BODY, "word")
        self.assertIn("ts4_u64 q58;", b)
        self.assertIn("ts4_word s50;", b)
        self.assertIn("ts4_word loc60[3];", b)       # a struct built field by field stays an array
        self.assertIn("(ts4_u64)q58;", b)
        self.assertIn("f((ts4_word)&s50);", b)
        self.assertNotIn("loc50", b)

    def test_tight_plan_trims_arrays(self):
        b = frame.split(BODY, "tight")
        self.assertIn("ts4_word loc60[3];", b)
        self.assertIn("ts4_word loc50[1];", b)

    def test_fill_plan_is_identity_here(self):
        self.assertIsNone(frame.split(BODY, "fill"))

    def test_spill_slots_become_scalars(self):
        body = ("    ts4_word loc50[4];\n\n"
                "    loc50[0] = (ts4_word)a0;\n"
                "    *(double *)((char *)loc50 + 8) = f1;\n"
                "    return loc50[0] + (ts4_word)*(double *)((char *)loc50 + 8);\n")
        b = frame.split(body, "tight")
        self.assertIn("ts4_word s50;", b)
        self.assertIn("double q58;", b)
        self.assertIn("return s50 + (ts4_word)q58;", b)

    def test_unknown_use_refuses(self):
        body = "    ts4_word loc50[2];\n\n    f(sizeof loc50);\n"
        self.assertIsNone(frame.split(body, "tight"))

    def test_target_frame(self):
        lines = ["88000000  9421ff70  stwu r1, -0x90(r1)",
                 "88000004  38610058  addi r3, r1, 0x58",
                 "88000008  e9610058  ld r11, 0x58(r1)",
                 "8800000C  90610060  stw r3, 0x60(r1)",
                 "88000010  81810098  lwz r12, 0x98(r1)"]
        self.assertEqual(frame.target_frame(lines), (0x90, [0x58, 0x60]))


if __name__ == "__main__":
    unittest.main()
