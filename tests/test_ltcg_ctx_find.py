"""Synthetic tests for tools/ltcg_ctx_find.py (no compiler, no game data)."""

import json
import sys
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))

import fn_equiv as fe  # noqa: E402
import ltcg_ctx_find as C  # noqa: E402

A, B, B2, CC, D, OPAQUE = 0x82001000, 0x82002000, 0x82003000, 0x82004000, 0x82005000, 0x82006000
BLR = 0x4E800020


def mr(dst, src):
    return 0x7C000378 | src << 21 | dst << 16 | src << 11


def lwz(d, off, a):
    return 0x80000000 | d << 21 | a << 16 | off


def li(d, imm):
    return 0x38000000 | d << 21 | imm


def fmr(d, b):
    return 0xFC000090 | d << 21 | b << 11


def stfs(s, off, a):
    return 0xD0000000 | s << 21 | a << 16 | off


def bl(at, target):
    return 0x48000001 | ((target - at) & 0x03FFFFFC)


def code(*words):
    return b"".join(w.to_bytes(4, "big") for w in words)


def image():
    """A: keeps r5 and f13 across B. B: writes r3, r11 and calls CC (writes r10).
    B2: leaves r3 alone. D: a plain-shaped caller that saves its argument in r31."""
    return {
        A: code(mr(5, 3), fmr(13, 1), bl(A + 8, B), lwz(11, 4, 5), stfs(13, 0, 11), BLR),
        B: code(lwz(11, 0, 3), bl(B + 4, CC), mr(3, 11), BLR),
        CC: code(li(10, 1), BLR),
        B2: code(li(11, 0), BLR),
        D: code(mr(31, 3), bl(D + 4, B), lwz(11, 4, 31), BLR),
        0x82007000: code(bl(0x82007000, B2), lwz(11, 0, 3), BLR),          # uses r3 after B2
        0x82008000: code(mr(5, 3), bl(0x82008004, OPAQUE), lwz(3, 0, 3), BLR),
    }


def analysis(img=None):
    img = img or image()
    return fe.Analysis(img.get)


class Evidence(unittest.TestCase):
    def test_kept_registers_prove_the_link(self):
        an = analysis()
        sites = C.call_sites(an, A)
        self.assertEqual(len(sites), 1)
        self.assertEqual(sites[0].target, B)
        self.assertEqual(sites[0].kept, frozenset({5, 32 + 13}))
        self.assertEqual(sites[0].defs, frozenset({3, 10, 11}))
        self.assertEqual(C.verdict(sites), "LTCG PROVEN")
        self.assertEqual(C.kept_by_callee(sites), {B: frozenset({5, 45})})

    def test_saved_register_is_no_evidence(self):
        sites = C.call_sites(analysis(), D)
        self.assertEqual(sites[0].kept, frozenset())
        self.assertEqual(C.verdict(sites), "no evidence")

    def test_r3_pass_through_is_only_likely(self):
        sites = C.call_sites(analysis(), 0x82007000)
        self.assertEqual(sites[0].kept, frozenset({3}))
        self.assertEqual(C.verdict(sites), "LTCG LIKELY")

    def test_opaque_callee_keeps_nothing(self):
        sites = C.call_sites(analysis(), 0x82008000)
        self.assertEqual(sites[0].kept, frozenset())
        self.assertIsNone(C.call_sites(analysis(), OPAQUE))

    def test_closure_goes_to_any_depth(self):
        an = analysis()
        self.assertEqual(C.closure(an, B), [B, CC])
        self.assertEqual(C.callees_of(an, A), [B])
        self.assertEqual(C.closure(an, A), [A, B, CC])

    def test_kill_diff(self):
        extra, missing = C.kill_diff(frozenset({3, 11, 31}), frozenset({3, 12, 40}))
        self.assertEqual(extra, frozenset({12, 40}))
        self.assertEqual(missing, frozenset({11}))
        self.assertEqual(C.reg_list({45, 5, 3}), "r3,r5,f13")


class Sources(unittest.TestCase):
    def test_draft_symbol_and_names(self):
        text = "int helper(int a) { return a; }\nvoid fn_886643F8(void *p) { helper(1); }\n"
        self.assertEqual(C.draft_symbol(text, 0x886643F8), "fn_886643F8")
        self.assertIsNone(C.draft_symbol("void f(void) { }\n", 0x886643F8))
        self.assertEqual(C.names_in("x = ts4_get_886643f8(p); fn_886643F8(q);", 0x886643F8),
                         ["ts4_get_886643f8", "fn_886643F8"])

    def test_stand_ins_and_wrappers(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "config" / "54540859").mkdir(parents=True)
            drafts = root / "src" / "xbox360" / "drafts"
            drafts.mkdir(parents=True)
            (root / "src" / "xbox360" / "eq_a.c").write_text("int ts4_eq_88001000(void) { return 1; }\n")
            (root / "config" / "54540859" / "equivalent.json").write_text(json.dumps({"rows": [
                {"address": "0x88001000", "source": "src/xbox360/eq_a.c", "function": "ts4_eq_88001000"}]}))
            (drafts / "me_88001000_nearmiss.c").write_text("int fn_88001000(void) { return 2; }\n")
            (drafts / "me_88002000_nearmiss.c").write_text("int f(void) { return 2; }\n")   # unusable: no name
            got = C.stand_ins(root, 0x88001000)
            self.assertEqual([(b.source, b.symbol, b.origin) for b in got],
                             [("src/xbox360/eq_a.c", "ts4_eq_88001000", "equiv"),
                              ("src/xbox360/drafts/me_88001000_nearmiss.c", "fn_88001000", "draft")])
            self.assertEqual(C.stand_ins(root, 0x88002000), [])
            self.assertEqual(C.stand_ins(root, 0x88001000, drafts=False)[-1].origin, "equiv")
            out = root / "scratch"
            rel = C.wrap_stand_in(root, got[1], "ts4_named_88001000", out)
            text = (root / rel).read_text()
            self.assertIn("#define fn_88001000 ts4_named_88001000\n", text)
            self.assertIn("int fn_88001000(void)", text)
            rel = C.wrap_noinline(root, "src/xbox360/eq_a.c", "ts4_eq_88001000", out)
            text = (root / rel).read_text()
            self.assertIn("#define ts4_eq_88001000 __declspec(noinline) ts4_eq_88001000", text)
            self.assertIn('#include "eq_a.c"', text)

    def test_ctx_path_and_explicit(self):
        self.assertEqual(C.ctx_path("flags(/Ob1):nogl:src/a.c"), "src/a.c")
        cmd = C.explicit(Path("src/x.c"), "f=0x88001000", ["/Oc"], ["flags(/Ob1):src/a.c"], ["g"])
        self.assertEqual(cmd, "python3 tools/fn_check_ltcg.py src/x.c f=0x88001000 --flags /Oc --include g "
                              "--context 'flags(/Ob1):src/a.c'")


class FakeView:
    """A candidate link: its own image, name table and stubs."""

    def __init__(self, img, names, stubs=()):
        self.analysis = fe.Analysis(lambda a: None if a in stubs else img.get(a))
        self.names, self.stub, self.helper = names, set(stubs), set()

    def address(self, name):
        return self.names.get(name)

    def is_stub(self, address):
        return address in self.stub

    def name_at(self, address):
        return next((n for n, a in self.names.items() if a == address), f"{address:08X}")


class Diagnose(unittest.TestCase):
    def setUp(self):
        self.world = SimpleNamespace(analysis=analysis(), in_helper=lambda a: False,
                                     label=lambda a: {A: "fa", B: "fb", CC: "fc"}.get(a, f"{a:08X}"))
        self.names = {B: ["fb"], CC: ["fc"]}
        self.need = {B: frozenset({5, 45}), CC: frozenset({5, 45})}
        self.result = SimpleNamespace(diff_words=[1, 2], ok=False, problems=["2 differing instruction(s)"])

    def test_equal_link(self):
        view = FakeView(image(), {"fa": A, "fb": B, "fc": CC})
        d = C.diagnose(view, self.world, "fa", A, self.names, self.need, [B, CC], self.result)
        self.assertEqual(d.score, 2)
        self.assertEqual(d.members[B]["state"], "body")
        self.assertEqual(d.members[B]["extra"], frozenset())
        self.assertEqual(d.bad(), [])
        self.assertEqual(d.kept_cand, d.kept_target)
        self.assertTrue(any("kill set equal" in line for line in C.format_diagnosis(d)))

    def test_missing_body_below_a_callee(self):
        # CC is a stub in our link: B then kills every volatile register and the caller must spill
        img = image()
        img[A] = code(mr(31, 3), fmr(31, 1), bl(A + 8, B), lwz(11, 4, 31), stfs(31, 0, 11), BLR)
        view = FakeView(img, {"fa": A, "fb": B, "fc": CC}, stubs={CC})
        d = C.diagnose(view, self.world, "fa", A, self.names, self.need, [B, CC], self.result)
        self.assertEqual(d.members[CC]["state"], "stub")
        self.assertEqual(d.members[B]["breaks"], frozenset({5, 45}))
        self.assertEqual(d.bad()[0], CC)
        self.assertEqual(sorted(d.blocking()), [B, CC])
        self.assertEqual(d.kept_cand["fb"], frozenset())
        self.assertEqual(d.kept_target["fb"], frozenset({5, 45}))
        text = "\n".join(C.format_diagnosis(d))
        self.assertIn("NO BODY", text)
        self.assertIn("BREAKS r5,f13", text)

    def test_body_with_another_kill_set(self):
        img = image()
        img[B] = code(lwz(5, 0, 3), bl(B + 4, CC), mr(3, 5), BLR)       # uses r5 where the original uses r11
        view = FakeView(img, {"fa": A, "fb": B, "fc": CC})
        d = C.diagnose(view, self.world, "fa", A, self.names, self.need, [B, CC], self.result)
        self.assertEqual(d.members[B]["extra"], frozenset({5}))
        self.assertEqual(d.members[B]["missing"], frozenset({11}))
        self.assertEqual(d.members[B]["breaks"], frozenset({5}))
        self.assertEqual(d.blocking(), [B])

    def test_inlined_callee_is_absent(self):
        view = FakeView(image(), {"fa": A, "fc": CC})
        d = C.diagnose(view, self.world, "fa", A, self.names, self.need, [B, CC], None)
        self.assertEqual(d.members[B]["state"], "absent")
        self.assertIsNone(d.score)
        self.assertFalse(d.ok)


class Gather(unittest.TestCase):
    def test_members_and_blockers(self):
        world = SimpleNamespace(analysis=analysis(), in_helper=lambda a: False, label=lambda a: f"fn_{a:08X}")
        with tempfile.TemporaryDirectory() as tmp:
            src = SimpleNamespace(source="src/b.c", symbol="fb", origin="match")
            ev = C.gather(world, A, Path(tmp), {B: [src]})
            self.assertEqual(ev["verdict"], "LTCG PROVEN")
            rows = {r["address"]: r for r in ev["members"]}
            self.assertEqual(list(rows), [B, CC])
            self.assertTrue(rows[B]["matched"] and rows[B]["direct"])
            self.assertFalse(rows[CC]["matched"] or rows[CC]["direct"])
            self.assertEqual(rows[CC]["need"], frozenset({5, 45}))     # the constraint reaches below the callee
            js = C.evidence_json(ev)
            self.assertEqual(js["members"][1]["need"], "r5,f13")
            self.assertEqual(js["sites"][0]["kept"], "r5,f13")
            self.assertIn("error", C.gather(world, OPAQUE, Path(tmp), {}))


if __name__ == "__main__":
    unittest.main()
