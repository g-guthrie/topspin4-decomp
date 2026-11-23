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


class Prototypes(unittest.TestCase):
    def test_return_kind_of_declarations(self):
        text = ('extern "C" unsigned int *hash_887F7BC8(unsigned int *out, unsigned char index);\n'
                "extern void plain_82002000(void *p);\n/* int in_comment(void); */\n"
                "ts4_word knr_82003000();\nstatic __inline float f(float x) { return g(x) + 1; }\n"
                "void user(void) { if (*hash_887F7BC8(&h, 1) == 2) plain_82002000(0); x = called(1); }\n")
        self.assertEqual(A.return_kind(text, "hash_887F7BC8"), "value")
        self.assertEqual(A.return_kind(text, "plain_82002000"), "void")
        self.assertEqual(A.return_kind(text, "knr_82003000"), "value")
        self.assertEqual(A.return_kind(text, "f"), "value")
        self.assertIsNone(A.return_kind(text, "called"))        # only called: no declaration
        self.assertIsNone(A.return_kind(text, "g"))
        self.assertIsNone(A.return_kind(text, "in_comment"))
        self.assertIsNone(A.return_kind(text, "absent"))

    def test_return_kind_of_definitions(self):
        self.assertEqual(A.return_kind("void hash(u32 *out, u8 index)\n{\n}\n", "hash", definition=True), "void")
        self.assertEqual(A.return_kind("u32 *hash(u32 *out, u8 index)\n{ return out; }\n", "hash", True), "value")
        self.assertEqual(A.return_kind("void *hash(u32 *out)\n{ return out; }\n", "hash", True), "value")
        self.assertIsNone(A.return_kind("void hash(u32 *out, u8 index);\n", "hash", definition=True))

    def choose(self, want, kinds):
        match = A.Candidate("src/xbox360/rm2.c", "hash_82002000", "match")
        stand = A.Candidate("src/xbox360/cx39.c", "hash_82002000", "stand-in")
        source_map = {0x82002000: [match, stand]}
        with tempfile.TemporaryDirectory() as tmp:
            return A.choose([0x82002000], source_map, "src/xbox360/test.c", Path(tmp),
                            wants={0x82002000: want} if want else None,
                            returns_of=lambda c: kinds.get(c.origin)), match, stand

    def test_stand_in_with_the_callers_prototype_beats_a_matched_source_without_it(self):
        sel, _match, stand = self.choose("value", {"match": "void", "stand-in": "value"})
        self.assertEqual(sel.covered[0x82002000], stand)
        self.assertEqual(sel.contexts, ["src/xbox360/cx39.c", A.PRIMER])
        self.assertEqual(sel.missing, [])                       # the callee itself is matched
        self.assertIn("left out src/xbox360/rm2.c (void)", " ".join(sel.notes))
        self.assertEqual(sel.includes(), ["hash_82002000"])

    def test_matched_source_stays_when_it_agrees_or_nothing_is_known(self):
        for want, kinds in (("value", {"match": "value", "stand-in": "value"}),
                            ("value", {"match": None, "stand-in": "value"}),     # unreadable: no opinion
                            ("void", {"match": "void", "stand-in": "value"}),
                            (None, {"match": "void", "stand-in": "value"}),
                            ("value", {"match": "void", "stand-in": "void"})):   # nobody agrees
            sel, match, _stand = self.choose(want, kinds)
            self.assertEqual(sel.covered[0x82002000], match, (want, kinds))
            self.assertEqual(sel.notes, [])


class Fallbacks(unittest.TestCase):
    P = "src/xbox360/"
    PRIMER = A.PRIMER

    def variants(self, auto, manual=(), limit=12):
        contexts = [*manual, *auto, self.PRIMER]
        owner = {"f_a": self.P + "a.c", "f_b": self.P + "b.c", "f_c": self.P + "c.c"}
        includes = ["given"] + [n for n, src in owner.items() if any(c.endswith(src) for c in auto)]
        return A.fallback_variants(contexts, list(manual), includes, ["given"], owner, limit=limit)

    def test_two_callee_sources(self):
        a, b = self.P + "a.c", self.P + "b.c"
        got = self.variants([a, "flags(/Ob1):" + b])
        # first the failed link without the primer, everything else unchanged
        self.assertEqual(got[0], ("without the pool primer", [a, "flags(/Ob1):" + b], ["given", "f_a", "f_b"]))
        got = got[1:]
        labels = [label for label, _c, _i in got]
        self.assertEqual(labels[0], "without the /INCLUDE of the callees")
        self.assertEqual(got[0][1:], ([a, "flags(/Ob1):" + b, self.PRIMER], ["given"]))
        self.assertEqual(got[1][1:], (["flags(/Ob1):" + a, "flags(/Ob1):" + b, self.PRIMER], ["given", "f_a", "f_b"]))
        by = {label: (c, i) for label, c, i in got}
        # dropping a source drops the /INCLUDE of its callee, keeps the primer and the other's prefix
        self.assertEqual(by[f"without {a}"], (["flags(/Ob1):" + b, self.PRIMER], ["given", "f_b"]))
        self.assertEqual(by[f"without {b}"], ([a, self.PRIMER], ["given", "f_a"]))
        self.assertEqual(by[f"without {b}, flags(/Ob1): on the others"],
                         (["flags(/Ob1):" + a, self.PRIMER], ["given", "f_a"]))
        self.assertEqual(got[-1], ("without the callee sources", [self.PRIMER], ["given"]))
        self.assertEqual(len({(tuple(c), tuple(i)) for _l, c, i in got}), len(got))      # no repeats

    def test_explicit_contexts_stay_and_the_limit_holds(self):
        m = "flags(/Ob1):" + self.P + "m.c"
        got = self.variants([self.P + "a.c", self.P + "b.c", self.P + "c.c"], manual=[m], limit=5)
        self.assertEqual(len(got), 6)                       # the primer-less link is not counted
        self.assertEqual(got[0][0], "without the pool primer")
        self.assertEqual(got[0][1][0], m)
        self.assertNotIn(self.PRIMER, got[0][1])
        for _label, ctx, inc in got[1:]:
            self.assertEqual(ctx[0], m)
            self.assertEqual(ctx[-1], self.PRIMER)
            self.assertIn("given", inc)
        full = self.variants([self.P + "a.c", self.P + "b.c", self.P + "c.c"], manual=[m], limit=50)
        self.assertIn(f"with {self.P}b.c alone", [label for label, _c, _i in full])

    def test_one_callee_source(self):
        a = self.P + "a.c"
        self.assertEqual([label for label, _c, _i in self.variants([a])],
                         ["without the pool primer", "without the /INCLUDE of the callees",
                          "with flags(/Ob1): on every callee source", "without the callee sources"])

    def test_only_the_primer_to_drop_without_callee_sources(self):
        # 0x88779248: no callee source; its 0.5f is in another pool than the primed one
        self.assertEqual(A.fallback_variants([self.PRIMER], [], [], [], {}),
                         [("without the pool primer", [], [])])
        self.assertEqual(A.fallback_variants([], [], [], [], {}), [])

    def test_explicit_primer_stays(self):
        a = self.P + "a.c"
        got = A.fallback_variants([self.PRIMER, a], [self.PRIMER], ["f_a"], [], {"f_a": a})
        self.assertNotIn("without the pool primer", [label for label, _c, _i in got])
        for _label, ctx, _inc in got:
            self.assertIn(self.PRIMER, ctx)


class Helpers(unittest.TestCase):
    def test_context_only_helper_named_by_the_source(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            tree(root)
            address_of = {"f_b_82003000": 0x82003000, "fn_82002000": 0x82002000}.get
            helpers = A.load_helpers(root, address_of)
            # ctx.c defines f_print (no address: a helper) and renamed_82002000 (an address: a stand-in)
            self.assertEqual(helpers, {"f_print": "flags(/Ob1):src/xbox360/ctx.c"})
            self.assertNotIn("if", helpers)   # `if (f_print(0)) {` in ctx.c is not a definition
            self.assertEqual(A.helper_contexts("int f_print(char *, ...);\nint g(void) { return f_print(0); }",
                                               helpers), ["flags(/Ob1):src/xbox360/ctx.c"])
            self.assertEqual(A.helper_contexts("/* f_print */ int g(void) { return 1; }", helpers), [])
            self.assertEqual(A.helper_contexts("int f_print(char *d, ...) { return 0; }", helpers), [])


class PartlyInlined(unittest.TestCase):
    """A callee the original calls twice and the candidate once was inlined at one call site."""

    def check(self, candidate_calls):
        cand = A.Candidate("src/xbox360/a.c", "f_a", "match")
        index = L.SymbolIndex([("f_a", 0x82002000), ("other", 0x82003000)])
        item = L.Checked("t", "t_name", 0x83000000, L.Result(False, ["x"], {}, [], []),
                         c_sites=[L.Site(4 * i, L.REL24, 0x82002000) for i in range(candidate_calls)]
                         + [L.Site(0x40, L.REL24, 0x82003000)],
                         t_sites=[L.Site(0, L.REL24, 0x88001000), L.Site(4, L.REL24, 0x88001000)])
        return L.inlined_sources([item], index, {"t_name": [cand]}, "f_a(1); f_a(2);", {cand: 0x88001000})

    def test_counts(self):
        self.assertEqual(len(self.check(0)), 1)     # inlined everywhere
        self.assertEqual(len(self.check(1)), 1)     # inlined at one of two call sites
        self.assertEqual(self.check(2), [])         # both calls are there


class SweepRows(unittest.TestCase):
    """tools/ltcg_autocontext_all.py: the command of a unit and the TSV row of its output."""

    UNIT = {"source": "src/xbox360/a.c", "flags": ["/Oc"], "context": ["src/xbox360/ctx.c"],
            "include": ["f_x"], "no_include": True, "symbols": {"f_a": 8, "f_b": 12}}

    def test_command_has_the_flags_and_none_of_the_recorded_context(self):
        import ltcg_autocontext_all as S
        cmd = S.command(self.UNIT)
        self.assertEqual(cmd[1:], ["tools/fn_check_ltcg.py", "src/xbox360/a.c", "f_a=f_a", "f_b=f_b",
                                   "--auto-context", "--quiet", "--flags", "/Oc"])

    def test_rows(self):
        import ltcg_autocontext_all as S
        ok = "MATCH f_a vs f_a @ 82000000 size 0x8 (ltcg)\nMATCH f_b vs f_b @ 82000010 size 0xc (ltcg)\n"
        self.assertEqual(S.summarize(self.UNIT, 0, ok, 3.21),
                         ("src/xbox360/a.c", 2, 2, "MATCH", "3.2", "/Oc", ""))
        via = "auto-context: no match with the full context; MATCH without the pool primer\n" + ok
        self.assertEqual(S.summarize(self.UNIT, 0, via, 1)[3:], ("MATCH", "1.0", "/Oc", "without the pool primer"))
        bad = "MATCH f_a vs f_a @ 82000000 size 0x8 (ltcg)\nFAIL f_b vs f_b @ 82000010: 2 differing\n"
        self.assertEqual(S.summarize(self.UNIT, 1, bad, 1)[2:4], (1, "FAIL"))
        self.assertEqual(S.summarize(self.UNIT, 1, bad, 1)[6], "f_b")
        # every function must be reported as MATCH: exit status 0 alone is not enough
        self.assertEqual(S.summarize(self.UNIT, 0, "MATCH f_a vs f_a\n", 1)[3], "FAIL")
        self.assertEqual(S.summarize(self.UNIT, None, "", 1200)[3], "TIMEOUT")


if __name__ == "__main__":
    unittest.main()
