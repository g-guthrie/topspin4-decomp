"""Mutation rewrites of tools/perm_auto.py keep the expression structure."""
import random
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "tools"))
import perm_auto as p  # noqa: E402

SRC = """struct C { char p[0x30]; int w, h; };
struct B { char q[4]; struct C *c; };
struct A { struct B *b; int off; };
extern float K;
int f(struct A *a)
{
    return -a->off - (int)((float)a->b->c->h * K / (float)a->b->c->w) + a->off * 2;
}
"""


def all_mutations(mut, n=200, **kw):
    toks = p.tokenize(SRC)
    fn = p.find_function(toks, "f")
    out = set()
    for seed in range(n):
        new = mut(toks, random.Random(seed), fn, **kw)
        if new:
            out.add("".join(new).split("{", 4)[-1])
    return out


class PermAutoTest(unittest.TestCase):
    def test_commute_keeps_casts_attached(self):
        res = all_mutations(p.m_commute)
        self.assertTrue(res)
        for r in res:
            self.assertNotIn("(float)(K)", r)
            self.assertNotIn("(float)K", r)
        self.assertTrue(any("K * (float)a->b->c->h" in r for r in res))

    def test_commute_respects_precedence(self):
        res = all_mutations(p.m_commute)
        # swapping the outer + must move the whole product, not just `a->off`
        self.assertFalse(any("a->off + -a->off" in r for r in res))
        self.assertTrue(any(r.lstrip().startswith("return a->off * 2 +") or "2 * a->off" in r for r in res))

    def test_hoist_only_whole_chains(self):
        res = all_mutations(p.m_hoist, cxx=False, types=p.field_types(SRC))
        self.assertTrue(res)
        for r in res:
            self.assertNotRegex(r, r"->t\d+")
        self.assertTrue(any("struct B * t" in r and "= a->b;" in r for r in res))

    def test_flip(self):
        toks = p.tokenize("int g(int a, int b) { return a < b + 1; }")
        fn = p.find_function(toks, "g")
        new = "".join(p.m_flip(toks, random.Random(0), fn))
        self.assertIn("(b + 1) > a", new)


if __name__ == "__main__":
    unittest.main()


class PermAutoDependencyTest(unittest.TestCase):
    def test_swap_keeps_def_before_use(self):
        src = "void g(int *o) { int t; t = o[1]; o[2] = t; o[3] = 5; }"
        toks = p.tokenize(src)
        fn = p.find_function(toks, "g")
        for seed in range(100):
            new = p.m_swap(toks, random.Random(seed), fn)
            if new:
                body = "".join(new)
                self.assertLess(body.index("t = o[1]"), body.index("o[2] = t"))
