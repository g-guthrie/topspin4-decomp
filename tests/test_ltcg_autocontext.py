"""Synthetic tests for tools/ltcg_autocontext.py (no compiler, no game data)."""

import json
import sys
import tempfile
import unittest
from collections import namedtuple
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))

import fn_check_ltcg as L  # noqa: E402
import ltcg_autocontext as A  # noqa: E402

Reloc = namedtuple("Reloc", "offset kind")
START = 0x82001000


def bl(at: int, target: int) -> bytes:
    return (0x48000001 | ((target - at) & 0x03FFFFFC)).to_bytes(4, "big")


def tree(root: Path) -> None:
    """A fake repository: three matched sources, one LTCG unit with a context, one spec."""
    for name in ("a.c", "b.c", "both.c", "inl.c", "test.c", "copy.c", "pp1_pool_primer.c", "ctx.c"):
        path = root / "src" / "xbox360" / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("/* synthetic */\n")
    # a stand-in: a context of a unit that matches nothing itself, defining two callees
    (root / "src" / "xbox360" / "ctx.c").write_text(
        "/* f_b_82003000(void) { in a comment */\nint f_print(char *d, ...)\n{ return 0; }\n"
        "int renamed_82002000(void) { if (f_print(0)) { return 1; } return 0; }\n")
    config = root / "config" / "54540859"
    config.mkdir(parents=True)

    def row(source, symbol, start):
        return {"source": f"src/xbox360/{source}", "symbol": symbol,
                "text_range": f"0x{start:08X}-0x{start + 8:08X}"}

    (config / "match.json").write_text(json.dumps({
        "compiler_flag_exceptions": {"src/xbox360/b.c": ["/O1"]},
        "matches": [row("a.c", "f_a_82002000", 0x82002000), row("b.c", "f_b_82003000", 0x82003000),
                    row("test.c", "f_local_82004000", 0x82004000),
                    row("inl.c", "f_inl_82006000", 0x82006000),
                    row("test.c", "f_t_82001000", START)]}))
    (config / "ltcg_units.json").write_text(json.dumps([
        {"source": "src/xbox360/a.c", "flags": ["/Oc"], "symbols": {"f_a_82002000": 8},
         "context": ["src/xbox360/inl.c", "flags(/Ob1):src/xbox360/ctx.c",
                     "src/xbox360/pp1_pool_primer.c"]}]))
    specs = root / "work" / "specs" / "Q5"
    specs.mkdir(parents=True)
    (specs / "both.json").write_text(json.dumps({
        "source": "src/xbox360/both.c", "route": "ltcg", "context": [],
        "functions": {"f_a_82002000": "0x82002000", "f_c_82005000": "0x82005000"}}))
    (specs / "eq.json").write_text(json.dumps({
        "source": "src/xbox360/copy.c", "route": "equiv", "functions": {"f_e_82007000": "0x82007000"}}))


class Callees(unittest.TestCase):
    def test_branches_that_leave_the_function_in_call_order(self):
        code = (bl(START, 0x82003000) + bytes(4) + bl(START + 8, 0x82002000)
                + bl(START + 12, 0x82003000) + bl(START + 16, START + 4) + bl(START + 20, START))
        relocs = [Reloc(8, 0x6), Reloc(0, 0x6), Reloc(12, 0x6), Reloc(16, 0x6), Reloc(20, 0x6),
                  Reloc(4, 0x10)]
        # once each, a branch into the body is local, a branch to the start is a recursive call
        self.assertEqual(A.callee_addresses(code, START, relocs), [0x82003000, 0x82002000, START])

    def test_depth(self):
        graph = {1: [2, 3], 2: [4], 3: [5], 4: [6]}
        walk = lambda depth: A.call_graph([1], lambda a: graph.get(a, []), lambda a: a != 3, depth)
        self.assertEqual(walk(1), [2, 3])
        self.assertEqual(walk(2), [2, 3, 4])  # 3 is not expanded: no matched source

    def test_names_in_the_source(self):
        known = {"f_a_82002000": 0x82002000, "fn_82009000": 0x82009000, "f_t_82001000": START}
        text = ("/* f_b_82003000 only in a comment */ extern int f_a_82002000(int);\n"
                "static int helper_82009000(int x) { return x; }\n"
                "int new_name_82009000(int);\n"
                "int f_t_82001000(int x) { return f_a_82002000(x) + new_name_82009000(x); }\n")
        self.assertEqual(A.referenced_addresses(text, known.get), [0x82002000, 0x82009000])
        self.assertEqual(A.referenced_addresses(text, known.get, skip={0x82002000}), [0x82009000])


class Choose(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        tree(self.root)
        names = {"f_print": 0x8200A000, "fn_82002000": 0x82002000}
        self.map = A.load_source_map(self.root, address_of=names.get)
        self.recorded = A.load_recorded(self.root)

    def tearDown(self):
        self.tmp.cleanup()

    def choose(self, callees, primary="src/xbox360/test.c", **kw):
        kw.setdefault("recorded", self.recorded)
        return A.choose(callees, self.map, self.root / primary, self.root, [START], **kw)

    def test_source_map(self):
        self.assertEqual([(c.source, c.origin) for c in self.map[0x82002000]],
                         [("src/xbox360/a.c", "match"), ("src/xbox360/both.c", "spec"),
                          ("src/xbox360/ctx.c", "stand-in")])  # match.json, then specs, then stand-ins
        self.assertEqual(self.map[0x82005000][0].origin, "spec")
        self.assertNotIn(0x82007000, self.map)  # equivalence specs are not matches
        self.assertEqual(self.map[0x8200A000], [A.Candidate("src/xbox360/ctx.c", "f_print", "stand-in")])
        self.assertEqual(len(self.map[0x82003000]), 1)  # a definition in a comment does not count

    def test_order_recorded_contexts_and_primer_last(self):
        sel = self.choose([0x82003000, 0x82002000, 0x82004000, 0x82008000], flags=["/Oc"])
        self.assertEqual(sel.contexts, [
            "flags(/O1):src/xbox360/b.c",               # callee order; b.c matched with /O1
            "src/xbox360/a.c",                          # its /Oc is already a global flag
            "src/xbox360/inl.c",                        # recorded contexts of the LTCG unit a.c,
            "flags(/Ob1):src/xbox360/ctx.c",            # with their prefixes
            "src/xbox360/pp1_pool_primer.c"])           # always last, once
        self.assertEqual(sel.in_source, [0x82004000])   # defined by the source under test
        self.assertEqual(sel.missing, [0x82008000])     # no matched source
        self.assertEqual(sel.covered[0x82002000].symbol, "f_a_82002000")
        self.assertEqual(sel.includes(), ["f_b_82003000", "f_a_82002000"])
        # without the global /Oc the unit keeps its own; a fixed prefix goes on chosen sources
        sel = self.choose([0x82003000, 0x82002000], prefix="flags(/Ob1):", recorded={
            **self.recorded, "src/xbox360/a.c": {"context": [], "flags": ["/Oc", "/Ob1"]}})
        self.assertEqual(sel.contexts, ["flags(/Ob1):flags(/O1):src/xbox360/b.c",
                                        "flags(/Ob1):flags(/Oc):src/xbox360/a.c",
                                        "src/xbox360/pp1_pool_primer.c"])
        mode, flags, path = L.parse_context(sel.contexts[0])
        self.assertEqual((mode, flags, path.name), ("gl", ["/Ob1", "/O1"], "b.c"))

    def test_one_source_covering_two_callees_wins(self):
        # a.c and both.c both define 0x82002000; both.c also defines 0x82005000, so it alone is
        # chosen and the function is not defined twice in the link.
        sel = self.choose([0x82002000, 0x82005000])
        self.assertEqual(sel.contexts, ["src/xbox360/both.c", "src/xbox360/pp1_pool_primer.c"])
        # alone, the match.json source is preferred to the spec
        self.assertEqual(self.choose([0x82002000]).covered[0x82002000].source, "src/xbox360/a.c")

    def test_never_the_source_under_test(self):
        # a scratch copy of test.c: test.c defines the target, so it is not a context
        sel = self.choose([0x82004000, 0x82003000], primary="src/xbox360/copy.c", recorded={})
        self.assertEqual(sel.contexts, ["src/xbox360/b.c", "src/xbox360/pp1_pool_primer.c"])
        self.assertEqual(sel.missing, [0x82004000])
        sel = self.choose([0x82003000], primary="src/xbox360/pp1_pool_primer.c", recorded={})
        self.assertEqual(sel.contexts, ["src/xbox360/b.c"])

    def test_inlined_callee(self):
        sel = self.choose([0x82003000], inlined=[0x82006000, 0x82009000], recorded={})
        self.assertEqual(sel.contexts, ["src/xbox360/b.c", "src/xbox360/inl.c",
                                        "src/xbox360/pp1_pool_primer.c"])
        self.assertEqual((sel.inlined, sel.missing, sel.missing_inlined), ({0x82006000}, [], [0x82009000]))
        self.assertEqual(sel.includes(), ["f_b_82003000"])  # an inlined callee is not forced

    def test_stand_in_is_used_and_still_missing(self):
        sel = self.choose([0x8200A000, 0x82003000], recorded={})
        self.assertEqual(sel.contexts, ["src/xbox360/b.c", "src/xbox360/ctx.c",   # matched sources first
                                        "src/xbox360/pp1_pool_primer.c"])
        self.assertEqual(sel.missing, [0x8200A000])
        self.assertIn("stand-in", "\n".join(A.report(sel, hex)))
        # a matched source is preferred to the stand-in for the same callee
        self.assertEqual(self.choose([0x82002000], recorded={}).covered[0x82002000].origin, "match")

    def test_recorded_prefix_wins_over_plain(self):
        # inl.c is chosen (plain) for 0x82006000 and recorded with /Ob1 for the unit a.c
        recorded = {"src/xbox360/a.c": {"context": ["flags(/Ob1):src/xbox360/inl.c"], "flags": []}}
        sel = self.choose([0x82006000, 0x82002000], recorded=recorded)
        self.assertEqual(sel.contexts, ["flags(/Ob1):src/xbox360/inl.c", "src/xbox360/a.c",
                                        "src/xbox360/pp1_pool_primer.c"])

    def test_with_prefix(self):
        contexts = ["src/xbox360/a.c", "flags(/Ob1 /O1):src/xbox360/b.c", "nogl:src/xbox360/c.c"]
        self.assertEqual(A.with_prefix(contexts, "src/xbox360/a.c", A.NO_INLINE),
                         ["flags(/Ob1):src/xbox360/a.c", *contexts[1:]])
        self.assertEqual(A.with_prefix(contexts, "src/xbox360/b.c", A.NO_INLINE), contexts)

    def test_explicit_contexts_stay_first(self):
        manual = ["src/xbox360/pp1_pool_primer.c", "nogl:src/xbox360/a.c"]
        sel = self.choose([0x82002000, 0x82003000], manual=manual, recorded={})
        self.assertEqual(sel.contexts, ["nogl:src/xbox360/a.c", "src/xbox360/b.c",
                                        "src/xbox360/pp1_pool_primer.c"])

    def test_report(self):
        sel = self.choose([0x82003000, 0x82008000], recorded={})
        text = "\n".join(A.report(sel, lambda a: f"fn_{a:08X}"))
        self.assertIn("--context src/xbox360/b.c", text)
        self.assertIn("missing callee bodies (1; match these first):\n  0x82008000 fn_82008000", text)


class FailingContext(unittest.TestCase):
    CONTEXTS = ["src/xbox360/manual.c", "flags(/Ob1):src/xbox360/a.c", "flags(/Ob1):src/xbox360/b.c",
                "src/xbox360/pp1_pool_primer.c"]

    def test_compile_failure_names_its_source(self):
        error = L.BuildError("compile failed", Path("src/xbox360/b.c"))
        self.assertEqual(L.failing_context(error, self.CONTEXTS, 1), self.CONTEXTS[2])
        error = L.BuildError("compile failed", Path("src/xbox360/manual.c"))
        self.assertIsNone(L.failing_context(error, self.CONTEXTS, 1))  # explicit: stays an error

    def test_duplicate_definition_drops_the_later_automatic_context(self):
        out = ("u1_manual.obj : warning LNK4006: h already defined in u2_a.obj; second definition ignored\n"
               "u3_b.obj : error LNK2005: f already defined in u2_a.obj\n"
               "out.dll : fatal error LNK1169: one or more multiply defined symbols found\n")
        self.assertEqual(L.failing_context(L.BuildError("link failed", None, out), self.CONTEXTS, 1),
                         self.CONTEXTS[2])
        out = "u2_a.obj : error LNK2001: unresolved external symbol __imp_KeTimeStampBundle\n"
        self.assertEqual(L.failing_context(L.BuildError("link failed", None, out), self.CONTEXTS, 1),
                         self.CONTEXTS[1])
        out = "u1_manual.obj : error LNK2005: f already defined in u0_t.obj\n"
        # nothing automatic is named: the last automatic context goes, never the primer
        self.assertEqual(L.failing_context(L.BuildError("link failed", None, out), self.CONTEXTS, 1),
                         self.CONTEXTS[2])
        self.assertIsNone(L.failing_context(L.BuildError("link failed", None, out), self.CONTEXTS, 1, guess=False))
        self.assertIsNone(L.failing_context(L.BuildError("link failed", None, out), self.CONTEXTS[:1], 1))

    def test_linker_crash_names_no_context(self):
        # a crash carries no output, so the caller drops the automatic /INCLUDEs before any context
        error = L.BuildError("linker crashed", None, "")
        self.assertIsNone(L.failing_context(error, self.CONTEXTS, 1, guess=False))
        self.assertEqual(L.failing_context(error, self.CONTEXTS, 1), self.CONTEXTS[2])


if __name__ == "__main__":
    unittest.main()
