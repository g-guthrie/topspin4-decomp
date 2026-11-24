"""tools/regalloc_mutate.py: diff classification and the targeted rewrites (no compiler needed)."""
import random
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "tools"))
import regalloc_mutate as rm  # noqa: E402

DIFF = """FAIL f vs fn_1 @ 1: 5 differing instruction(s), first at +0x0
  TARGET                                         CANDIDATE
  886C5998  3964000c  addi r11, r4, 0xc        | 3964000c  addi r11, r4, 0xc
* 886C59B0  7d6a182e  lwzx r11, r10, r3        | 7cea182e  lwzx r7, r10, r3
* 8865533C  7c6b5214  add r3, r11, r10         | 7c6a5a14  add r3, r10, r11
* 881651E4  7f0a5840  cmplw cr6, r10, r11      | 7f0b5040  cmplw cr6, r11, r10
* 888C00CC  5487f0be  srwi r7, r4, 2           | 7887f0a2  rldicl r7, r4, 62, 34
* 886C59C0  7cea5a14  add r7, r10, r11         | 7ccb5214  add r6, r11, r10
* 888C00C0  d16b078c  stfs f11, 0x78c(r11)     | d1ab0784  stfs f13, 0x784(r11)
* 888C00C4  d1ab0784  stfs f13, 0x784(r11)     | d16b078c  stfs f11, 0x78c(r11)
  888C00EC  4e800020  blr                      | 4e800020  blr
"""

SRC = """struct S { int a, b; unsigned long long m; };
int g(struct S *s, unsigned i)
{
    int x = s->a;
    s->b = 1;
    s->a = 2;
    s->m = 3;
    s->m |= 0x8000000000000000ULL >> (i >> 2);
    if (x < s->b) return 1;
    return x == s->a;
}
"""


def all_of(fam, n=80):
    out = set()
    for seed in range(n):
        t = rm.apply(fam, SRC, "g", random.Random(seed), False)
        if t:
            out.add(t)
    return out


class ClassifyTest(unittest.TestCase):
    def test_parse_and_classes(self):
        rows = rm.parse_diff(DIFF)
        self.assertEqual(len(rows), 9)
        cls = rm.classify(rows)
        self.assertEqual(cls, [None, "REG", "COMMUTE", "COMMUTE", "FORM", "REG", "SWAP", "SWAP", None])

    def test_families_follow_classes(self):
        rows = rm.parse_diff(DIFF)
        fams = rm.families_for(rows, rm.classify(rows))
        self.assertEqual(fams[0], "cmpflip")      # compare flips first: compares keep source order
        self.assertIn("shiftcast", fams)
        self.assertIn("perm3", fams)
        counts, adv = rm.advice(rows, rm.classify(rows))
        self.assertEqual(counts["COMMUTE"], 2)
        self.assertTrue(any("canonicalised" in a for a in adv))


class MutatorTest(unittest.TestCase):
    def test_cmpflip(self):
        res = all_of("cmpflip")
        self.assertTrue(any("s->b > x" in r for r in res))
        self.assertTrue(any("s->a == x" in r for r in res))

    def test_shiftcast(self):
        res = all_of("shiftcast")
        self.assertTrue(any(">> (int)(i >> 2)" in r for r in res))

    def test_perm3_reorders_independent_stores_only(self):
        res = all_of("perm3", 200)
        self.assertTrue(res)
        for r in res:
            body = r.split("{", 2)[2]
            self.assertLess(body.index("int x = s->a;"), body.index("s->a = 2;"))  # declaration stays first
            self.assertIn("s->m |=", body)

    def test_pad(self):
        res = all_of("pad", 30)
        self.assertTrue(any("int rpad0 = 0;" in r for r in res))
        for r in res:
            self.assertLess(r.index("rpad0"), r.index("int x = s->a;"))

    def test_neighbourhood_dedups(self):
        nb = rm.neighbourhood(SRC, "g", ["cmpflip", "shiftcast"], False, draws=20)
        self.assertEqual(len(nb), len(set(nb)))
        self.assertNotIn(SRC, nb)


class PermAutoTargetedTest(unittest.TestCase):
    def test_mutate_accepts_targeted_list(self):
        import perm_auto as pa
        muts = [rm.FAMILIES["cmpflip"], rm.FAMILIES["hoist"], rm.FAMILIES["split"]]
        got = set()
        for seed in range(60):
            t, name = pa.mutate(SRC, random.Random(seed), "g", False, muts)
            if t:
                got.add(name)
        self.assertTrue(got <= {"cmpflip", "hoist", "split"})
        self.assertIn("cmpflip", got)


if __name__ == "__main__":
    unittest.main()
