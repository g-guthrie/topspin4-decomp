"""Pure-logic tests for tools/asm2c (no compiler or game files needed)."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools" / "asm2c"))
import emit  # noqa: E402
import translate  # noqa: E402


def line(addr, word, text):
    return f"{addr:08X}  {word}  {text}"


ENV = translate.Env(lambda sym: None)


class TranslateTests(unittest.TestCase):
    def test_getter(self):
        r = translate.gen([line(0x88000000, "80630008", "lwz     r3,8(r3)"),
                           line(0x88000004, "4e800020", "blr")], ENV)
        self.assertEqual(r["kind"], "get")
        self.assertEqual(r["sig"], "ts4_word NAME(ts4_word a0)")
        self.assertEqual(r["body"], "    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));\n")

    def test_setter_returns_void(self):
        r = translate.gen([line(0x88000000, "90830010", "stw     r4,16(r3)"),
                           line(0x88000004, "4e800020", "blr")], ENV)
        self.assertEqual(r["kind"], "set")
        self.assertTrue(r["sig"].startswith("void NAME"))
        self.assertIn("*(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;", r["body"])

    def test_tail_call(self):
        r = translate.gen([line(0x88000000, "48000000", "b       0x88001000   ; REL24 fn_88001000")], ENV)
        self.assertEqual(r["kind"], "tailcall")
        self.assertEqual(r["protos"], {"fn_88001000": 1})
        self.assertEqual(r["body"], "    return fn_88001000((ts4_word)a0);\n")

    def test_unsupported_raises_skip(self):
        with self.assertRaises(translate.Skip):
            translate.gen([line(0x88000000, "00000000", "frobnicate r3,r4")], ENV)

    def test_arity_counts_unwritten_arg_registers(self):
        lines = [line(0, "90a30000", "stw     r5,0(r3)"), line(4, "4e800020", "blr")]
        self.assertEqual(translate.arity(lines, lambda s: None), 3)


class EmitTests(unittest.TestCase):
    def test_func_name(self):
        r = {"kind": "get", "detail": ["u32@0x8"]}
        self.assertEqual(emit.func_name(r, 0x88167CF0), "ts4_get_u32_off8_88167CF0")


if __name__ == "__main__":
    unittest.main()
