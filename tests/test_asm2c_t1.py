"""Tests for the T1 additions to tools/asm2c (loop-exit join, block CSE); pure text."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools" / "asm2c"))
from test_asm2c import gen, tgt  # noqa: E402
import run  # noqa: E402
import xforms  # noqa: E402

# for (i = 0; ; p++) { if (*p == key) { if (p[1]) p[2] = i; p[3] = i; return; } if (++i >= 8) return; }
FIND = ["li r10,0", "lwz r11,0(r4)", "cmplw cr6,r11,r5", f"beq cr6, 0x18 -> {tgt(9)}", "addi r4,r4,4",
        "addi r10,r10,1", "cmplwi cr6,r10,8", f"blt cr6, -0x18 -> {tgt(1)}", "blr",
        "lwz r9,4(r4)", "cmplwi cr6,r9,0", f"beq cr6, 0x8 -> {tgt(13)}", "stw r10,8(r4)", "stw r10,12(r4)", "blr"]


class LoopExitJoinTests(unittest.TestCase):
    def test_shared_tail_after_loop_exit_is_emitted_once(self):
        b = gen(FIND, vret=True)["body"]
        self.assertEqual(b.count("+ 12)"), 1)
        self.assertIn("if ((ts4_word)t7 != 0) {\n                *(ts4_word *)((char *)(ts4_word)(lv2) + 8)", b)

    def test_variant_x_restores_duplication(self):
        self.assertEqual(gen(FIND, vret=True, xjoin=False)["body"].count("+ 12)"), 2)

    def test_variant_letters(self):
        names = [("fn_88000000", 0x88000000, 60)]
        dis = type("D", (), {"lines": lambda s, n: __import__("test_asm2c").prog(FIND)})()
        res, fails = run.translate_all(names, dis, None, "10wx")
        self.assertEqual(res[0x88000000]["body"].count("+ 12)"), 2)


class BlockCseTests(unittest.TestCase):
    def test_sum_used_twice_becomes_temporary(self):
        b = ("    ts4_word t7;\n\n"
             "    do {\n"
             "        t7 = *(ts4_word *)((char *)(ts4_word)((lv5 + t2)) + 304);\n"
             "        if (t7) {\n"
             "            *(ts4_word *)((char *)(ts4_word)((lv5 + t2)) + 8) = 0;\n"
             "        }\n"
             "        lv5 = p1;\n"
             "    } while (1);\n")
        out = xforms.blockcse_all(b)
        self.assertEqual(len(out), 1)
        self.assertIn("        h1 = (ts4_word)(lv5 + t2);\n", out[0])
        self.assertIn("(ts4_word)h1 + 304", out[0])
        self.assertIn("(ts4_word)h1 + 8", out[0])
        self.assertIn("    ts4_word h1;", out[0])

    def test_stops_at_reassignment(self):
        b = ("    ts4_word t7;\n\n"
             "    t7 = (a0 + a1);\n"
             "    a0 = 3;\n"
             "    t7 = (a0 + a1);\n")
        self.assertEqual(xforms.blockcse_all(b), [])


if __name__ == "__main__":
    unittest.main()


class UncseTests(unittest.TestCase):
    def test_load_repeated_in_both_arms(self):
        b = ("    ts4_word t11;\n\n"
             "    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);\n"
             "    if ((ts4_word)(t10 & 0xff) != 0) {\n"
             "        *(ts4_word *)((char *)(ts4_word)(t11) + 8) = (ts4_word)2;\n"
             "    } else {\n"
             "        *(ts4_word *)((char *)(ts4_word)(t11) + 8) = (ts4_word)1;\n"
             "    }\n"
             "    return;\n")
        out = xforms.uncse_all(b)
        self.assertEqual(len(out), 1)
        self.assertNotIn("t11", out[0])
        self.assertEqual(out[0].count("(*(ts4_word *)((char *)(ts4_word)(a0) + 40))"), 2)

    def test_not_when_used_after(self):
        b = ("    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);\n"
             "    if (c) {\n        f(t11);\n    } else {\n        g(t11);\n    }\n    h(t11);\n")
        self.assertEqual(xforms.uncse_all(b), [])
