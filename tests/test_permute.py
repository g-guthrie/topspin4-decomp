"""Tests for tools/permute.py: markup parser, dependency check, search driver.

Pure logic needs no compiler. The integration test is skipped unless the
Loader matching toolchain (work/matching-tools, work/loader) exists.
"""

import os
import random
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import permute  # noqa: E402
from permute import (  # noqa: E402
    MarkupError, Result, Space, analyze, conflicts, linear_extensions,
    parse_template, score_output, search, split_alts, split_statements,
)


def order_count(src_block, mode="loose"):
    t = parse_template(f"/* PERM_BEGIN{'(' + mode + ')' if mode != 'loose' else ''} */\n{src_block}\n/* PERM_END */")
    return len(list(linear_extensions(t.blocks[0].conf)))


class SplitAltsTests(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(split_alts("a|b|c"), ["a", "b", "c"])

    def test_increment_alternatives(self):
        self.assertEqual(split_alts("i++|++i"), ["i++", "++i"])

    def test_nested_parens_and_logical_or(self):
        self.assertEqual(split_alts("(a|b)|x || y"), ["(a|b)", "x || y"])

    def test_escape_and_empty(self):
        self.assertEqual(split_alts(r"a\|b|"), ["a|b", ""])


class MarkupTests(unittest.TestCase):
    def test_no_markers_is_identity(self):
        src = "int f(void) { return 1; }\n"
        space = Space(parse_template(src))
        self.assertEqual(space.size(), 1)
        self.assertEqual(space.render(space.baseline()), src)

    def test_alt_baseline_is_original_and_alternatives_render(self):
        src = "for (i = 0; i < n; /* PERM_ALT(++i|i += 1) */i++/* PERM_ALT_END */) x();\n"
        t = parse_template(src)
        sp = Space(t)
        self.assertEqual(sp.size(), 3)
        self.assertEqual(sp.render(sp.baseline()), src.replace("/* PERM_ALT(++i|i += 1) */", "").replace("/* PERM_ALT_END */", ""))
        self.assertIn("++i)", sp.render((1, 0)))
        self.assertIn("i += 1)", sp.render((2, 0)))

    def test_alt_keeps_surrounding_whitespace_and_dedupes_original(self):
        t = parse_template("/* PERM_ALT(a == b|b == a) */ a == b /* PERM_ALT_END */;")
        self.assertEqual([o.strip() for o in t.inline[0].options], ["a == b", "b == a"])
        sp = Space(t)
        self.assertEqual(sp.render((1, 0)), " b == a ;")

    def test_empty_alternative(self):
        t = parse_template("/* PERM_ALT(__forceinline|) */ static /* PERM_ALT_END */ int f();")
        self.assertEqual([o.strip() for o in t.inline[0].options], ["static", "__forceinline", ""])

    def test_type_marker(self):
        t = parse_template("/* PERM_TYPE(int|unsigned|short) */ unsigned char x;")
        self.assertEqual(t.inline[0].options, ["unsigned char", "int", "unsigned", "short"])
        sp = Space(t)
        self.assertEqual(sp.render((2, 0)), " unsigned x;")
        self.assertEqual(sp.render(sp.baseline()), " unsigned char x;")

    def test_type_marker_typedef_name(self):
        t = parse_template("/* PERM_TYPE(u8|u32) */ word x;")
        self.assertEqual(t.inline[0].options[0], "word")

    def test_volatile_marker(self):
        t = parse_template("/* PERM_VOLATILE */ int *p;")
        sp = Space(t)
        self.assertEqual(sp.render((0, 0)), " int *p;")
        self.assertEqual(sp.render((1, 0)), "volatile  int *p;")

    def test_errors(self):
        with self.assertRaises(MarkupError):
            parse_template("/* PERM_ALT(a|b) */ x")
        with self.assertRaises(MarkupError):
            parse_template("/* PERM_BEGIN */ a;")
        with self.assertRaises(MarkupError):
            parse_template("/* PERM_END */")
        with self.assertRaises(MarkupError):
            parse_template("/* PERM_BEGIN(bogus) */ a; /* PERM_END */")

    def test_markers_inside_strings_and_line_comments_are_ignored(self):
        src = 'char *s = "/* PERM_BEGIN */"; // /* PERM_ALT(a|b) */\n'
        self.assertEqual(Space(parse_template(src)).size(), 1)

    def test_block_reorder_renders_whitespace_slots(self):
        src = "{\n    /* PERM_BEGIN */\n    a = 1;\n    b = 2;\n    /* PERM_END */\n}\n"
        sp = Space(parse_template(src))
        self.assertEqual(sp.size(), 2)
        self.assertEqual(sp.render(sp.baseline()), src)
        swapped = sp.render(((1, 0), 0))
        self.assertEqual(swapped, src.replace("a = 1;\n    b = 2;", "b = 2;\n    a = 1;"))

    def test_alt_inside_block_statement_moves_with_it(self):
        src = "/* PERM_BEGIN */ a = /* PERM_ALT(1|2) */0/* PERM_ALT_END */; b = 5; /* PERM_END */"
        sp = Space(parse_template(src))
        self.assertEqual(sp.size(), 6)
        text = sp.render((2, (1, 0), 0))
        self.assertLess(text.index("b = 5"), text.index("a = 2"))

    def test_flag_sets_add_a_dimension(self):
        sp = Space(parse_template("int x;"), [[], ["/O1"], ["/Os"]])
        self.assertEqual(sp.size(), 3)
        self.assertEqual(sp.flags((1,)), ["/O1"])
        self.assertEqual(permute.parse_flag_sweep(["/O1", "/O1 /Ob1"]), [[], ["/O1"], ["/O1", "/Ob1"]])
        self.assertEqual(permute.parse_flag_sweep(None), [[]])
        self.assertEqual(permute.parse_flag_sweep([])[1:], [[f] for f in permute.DEFAULT_FLAG_SWEEP])


class SplitStatementsTests(unittest.TestCase):
    def texts(self, body):
        chunks, tail = split_statements(body)
        return [t for _, t in chunks]

    def test_simple_and_blocks(self):
        self.assertEqual(self.texts("a = 1; b(c, d); { x; y; } z;"), ["a = 1;", "b(c, d);", "{ x; y; }", "z;"])

    def test_if_else_chain_is_one_statement(self):
        body = "if (a) { x(); } else if (b) y(); else { z(); }\nq = 1;"
        self.assertEqual(len(self.texts(body)), 2)

    def test_if_else_without_braces(self):
        self.assertEqual(len(self.texts("if (a) x = 1; else x = 2; y = 3;")), 2)

    def test_loops_and_do_while(self):
        self.assertEqual(len(self.texts("for (i = 0; i < n; i++) { s += i; } t = s; do { k++; } while (k < 3); u = 1;")), 4)

    def test_comments_and_strings_do_not_split(self):
        self.assertEqual(len(self.texts('a = "x;y"; /* ; */ b = \';\';')), 2)

    def test_initializer_braces(self):
        self.assertEqual(self.texts("int a[] = {1, 2}; int b;"), ["int a[] = {1, 2};", "int b;"])

    def test_tail(self):
        chunks, tail = split_statements("a = 1;\n  b = 2;\n  ")
        self.assertEqual(len(chunks), 2)
        self.assertEqual(tail.strip(), "")
        self.assertEqual(chunks[1][0], "\n  ")


class DependencyTests(unittest.TestCase):
    def test_independent_locals(self):
        self.assertFalse(conflicts(analyze("a = 1;"), analyze("b = 2;")))

    def test_write_after_read_and_raw(self):
        self.assertTrue(conflicts(analyze("a = b;"), analyze("b = 2;")))  # WAR
        self.assertTrue(conflicts(analyze("a = 1;"), analyze("b = a;")))  # RAW
        self.assertTrue(conflicts(analyze("a = 1;"), analyze("a = 2;")))  # WAW

    def test_compound_assign_and_incdec_read_and_write(self):
        self.assertTrue(conflicts(analyze("a += 1;"), analyze("b = a;")))
        self.assertTrue(conflicts(analyze("i++;"), analyze("j = i;")))
        self.assertTrue(conflicts(analyze("++i;"), analyze("j = i;")))
        self.assertFalse(conflicts(analyze("i++;"), analyze("j++;")))

    def test_stores_to_different_fields_are_independent(self):
        self.assertFalse(conflicts(analyze("p->a = 1;"), analyze("p->b = 2;")))
        self.assertFalse(conflicts(analyze("p[0] = x;"), analyze("p[1] = y;")))
        self.assertFalse(conflicts(analyze("*(int *)q = 0;"), analyze("p->a = 2;")))

    def test_same_lvalue_and_prefix_alias(self):
        self.assertTrue(conflicts(analyze("p->a = 1;"), analyze("p->a = 2;")))
        self.assertTrue(conflicts(analyze("p->a = 1;"), analyze("x = p->a;")))
        self.assertTrue(conflicts(analyze("p->a = 1;"), analyze("x = p->a.b;")))
        self.assertTrue(conflicts(analyze("p = q;"), analyze("p->a = 2;")))  # base pointer written

    def test_index_variable_dependency(self):
        self.assertTrue(conflicts(analyze("p[i] = 1;"), analyze("i = 2;")))

    def test_calls_conflict_with_memory_but_not_pure_locals(self):
        self.assertTrue(conflicts(analyze("f(x);"), analyze("p->a = 1;")))
        self.assertTrue(conflicts(analyze("f(x);"), analyze("y = p->a;")))
        self.assertFalse(conflicts(analyze("f(x);"), analyze("y = 3;")))
        self.assertTrue(conflicts(analyze("f(x);"), analyze("g(y);")))

    def test_deref_store_and_load(self):
        self.assertTrue(conflicts(analyze("*p = 1;"), analyze("x = *p;")))
        self.assertFalse(conflicts(analyze("*p = 1;"), analyze("y = 2;")))

    def test_barriers(self):
        for s in ("return x;", "goto out;", "if (a) { break; }", "lbl: y = 1;", "switch (a) { }"):
            with self.subTest(s=s):
                self.assertTrue(conflicts(analyze(s), analyze("zz = 1;")))
                self.assertTrue(conflicts(analyze(s), analyze("zz = 1;"), "free"))

    def test_modes(self):
        a, b = analyze("p->a = 1;"), analyze("q->b = 2;")
        self.assertFalse(conflicts(a, b, "loose"))
        self.assertTrue(conflicts(a, b, "strict"))
        self.assertFalse(conflicts(analyze("x = 1;"), analyze("y = x;"), "free"))

    def test_decls(self):
        a, b = analyze("int a = 1;", "decls"), analyze("int b = a;", "decls")
        self.assertTrue(conflicts(a, b))
        self.assertFalse(conflicts(analyze("int a = 1;", "decls"), analyze("char *b = z;", "decls")))
        self.assertFalse(conflicts(analyze("int a;", "decls"), analyze("int b;", "decls")))
        self.assertTrue(conflicts(analyze("int a, b = 3;", "decls"), analyze("int c = b;", "decls")))

    def test_member_names_are_not_variables(self):
        info = analyze("x = p->count;")
        self.assertNotIn("count", info.reads)
        self.assertIn("p", info.reads)

    def test_extension_counts(self):
        self.assertEqual(order_count("a = 1;\nb = 2;\nc = 3;"), 6)
        self.assertEqual(order_count("a = 1;\nb = a;\nc = b;"), 1)
        self.assertEqual(order_count("a = 1;\nb = 2;\nc = a + b;"), 2)
        self.assertEqual(order_count("a = 1;\nb = a;\nc = 3;"), 3)
        self.assertEqual(order_count("a = 1;\nreturn;\nc = 3;"), 1)
        self.assertEqual(order_count("a = 1;\nb = a;\nc = 3;", "free"), 6)

    def test_extensions_preserve_conflicting_order(self):
        t = parse_template("/* PERM_BEGIN */ a = 1; p->x = a; q = 2; /* PERM_END */")
        for order in linear_extensions(t.blocks[0].conf):
            self.assertLess(order.index(0), order.index(1))

    def test_decl_block_parse(self):
        src = "/* PERM_DECLS */ int a; int b = a; char *c; /* PERM_DECLS_END */"
        t = parse_template(src)
        self.assertEqual(t.blocks[0].kind, "decls")
        self.assertEqual(len(list(linear_extensions(t.blocks[0].conf))), 3)


class ScoreOutputTests(unittest.TestCase):
    def test_match(self):
        self.assertEqual(score_output("MATCH f vs g @ 88000000 size 0x10\n", 0), 0)

    def test_diff_count_and_extra_problems(self):
        out = "FAIL f vs g @ 88: 4 differing instruction(s), first at +0x8; relocation layout differs (target 2, candidate 2)\n"
        self.assertEqual(score_output(out, 1), 5)

    def test_size_problem(self):
        out = "FAIL f vs g @ 88: size 0x20 != target 0x10; 2 differing instruction(s), first at +0x0\n"
        self.assertEqual(score_output(out, 1), 6)

    def test_missing_function_is_far_worse(self):
        self.assertGreater(score_output("FAIL f: not defined in compiled object (have: )\n", 1), 1000)


class SearchTests(unittest.TestCase):
    """Drive the search with a fake evaluator: score = text distance to a goal."""

    def make(self, goal_order, n=6):
        stmts = "\n".join(f"    v{i} = {i};" for i in range(n))
        space = Space(parse_template(f"/* PERM_BEGIN */\n{stmts}\n/* PERM_END */\n"))
        goal_text = space.render(((tuple(goal_order)), 0))

        def evaluate(jobs):
            for i, (text, flags) in enumerate(jobs):
                a, b = text.splitlines(), goal_text.splitlines()
                diff = sum(x != y for x, y in zip(a, b))
                yield i, Result(diff, diff == 0, "")

        return space, evaluate

    def test_exhaustive_finds_goal(self):
        space, ev = self.make((2, 0, 1), n=3)
        out = search(space, ev, budget=100, batch=2)
        self.assertTrue(out.exhaustive)
        self.assertEqual(out.matched[0], (2, 0, 1))

    def test_exhaustive_reports_best_when_no_match(self):
        space, ev = self.make((0, 1, 2), n=3)

        def never(jobs):
            for i, r in ev(jobs):
                yield i, Result(r.score + 1, False, "")

        out = search(space, never, budget=100, batch=2)
        self.assertIsNone(out.matched)
        self.assertEqual(out.best.score, 1)
        self.assertEqual(out.tried, 6)

    def test_hill_climb_finds_goal_in_large_space(self):
        goal = (4, 2, 5, 0, 3, 1)
        space, ev = self.make(goal, n=6)  # 720 orders > budget 400
        out = search(space, ev, budget=400, batch=6, seed=3)
        self.assertFalse(out.exhaustive)
        self.assertIsNotNone(out.matched)
        self.assertEqual(out.matched[0], goal)
        self.assertLess(out.tried, 400)

    def test_budget_is_respected(self):
        space, ev = self.make((5, 4, 3, 2, 1, 0), n=6)

        def never(jobs):
            for i, r in ev(jobs):
                yield i, Result(r.score + 1, False, "")

        out = search(space, never, budget=50, batch=6, seed=1)
        self.assertIsNone(out.matched)
        self.assertLessEqual(out.tried, 50)

    def test_uncompilable_candidates_are_skipped(self):
        space, ev = self.make((1, 0), n=2)

        def flaky(jobs):
            for i, r in ev(jobs):
                yield i, (Result(None, False, "err") if r.score == 2 else r)

        out = search(space, flaky, budget=10, batch=2)
        self.assertEqual(out.matched[0], (1, 0))

    def test_neighbours_and_mutate_stay_legal(self):
        t = parse_template("/* PERM_BEGIN */ a = 1; b = a; c = 3; d = 4; /* PERM_END */")
        sp = Space(t)
        legal = set(sp.orders[0])
        for n in sp.neighbours(sp.baseline()):
            self.assertIn(n[0], legal)
        rng = random.Random(0)
        s = sp.baseline()
        for _ in range(200):
            s = sp.mutate(s, rng, 2)
            self.assertIn(s[0], legal)


@unittest.skipUnless(
    (ROOT / "work" / "matching-tools" / "work_wibo").exists()
    and (ROOT / "work" / "loader" / "split" / "config.json").exists(),
    "needs the Loader matching toolchain (work/matching-tools, work/loader)",
)
class IntegrationTests(unittest.TestCase):
    def test_already_matching_source_matches_at_baseline(self):
        name, addr = "ts4l_field_address_2af0_830A02A8", "0x830A02A8"
        env = dict(os.environ, TS4_MATCHING_DIR=str(ROOT / "work" / "loader"))
        with tempfile.TemporaryDirectory() as tmp:
            res = subprocess.run(
                [sys.executable, str(ROOT / "tools" / "permute.py"),
                 str(ROOT / "src" / "loader" / "l1_field_helpers_830A02A8.c"),
                 f"{name}={addr}", "--out", str(Path(tmp) / "out.c"), "--tmp", tmp, "-j", "2"],
                env=env, capture_output=True, text=True, cwd=ROOT, timeout=300,
            )
        self.assertEqual(res.returncode, 0, res.stdout + res.stderr)
        self.assertIn("MATCH", res.stdout)


if __name__ == "__main__":
    unittest.main()
