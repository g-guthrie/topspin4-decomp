"""Tests for the fn_equiv/3 and /4 additions and the fn_check SEH helpers, with synthetic
PowerPC code and objects (no game data): unreachable blocks, 64-bit registers, jump tables
whose entries leave the function, the VMX/VMX128 interpreter, pure out-parameters, input
generation for begin/end pairs and index sums, and .pdata / scope-table reading."""

import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
sys.path.insert(0, str(Path(__file__).resolve().parent))

import fn_check as C  # noqa: E402
import fn_equiv as F  # noqa: E402
import xcoff  # noqa: E402
from test_fn_equiv import (BASE, BLR, CALLEE, FakeLinked, add, addi, beq, bl, cmpwi, dform, epilogue,  # noqa: E402
                           li, lwz, make_world, prologue, stw, xo)


def words(ws):
    return b"".join(struct.pack(">I", w) for w in ws)


def b(frm, to):
    return (18 << 26) | ((to - frm) & 0x03FFFFFC)


def std(s, a, imm):
    return (62 << 26) | (s << 21) | (a << 16) | (imm & 0xFFFC)


def ld(d, a, imm):
    return (58 << 26) | (d << 21) | (a << 16) | (imm & 0xFFFC)


def srdi32(d, s):           # rldicl rD,rS,32,32: the upper word of rS
    return (30 << 26) | (s << 21) | (d << 16) | (0 << 11) | (0 << 6) | (1 << 5) | (0 << 2) | (1 << 1)


def vx(xo11, d, a, bb):     # AltiVec VX form
    return (4 << 26) | (d << 21) | (a << 16) | (bb << 11) | xo11


def lvx(d, ra, rb):
    return xo(31, d, ra, rb, 103)


def stvx(s, ra, rb):
    return xo(31, s, ra, rb, 231)


def mulli(d, a, imm):
    return dform(7, d, a, imm)


def lbz(d, a, imm):
    return dform(34, d, a, imm)


MTCTR = lambda r: (31 << 26) | (r << 21) | (9 << 16) | (467 << 1)
BCTR = 0x4E800420
VSUBFP, VOR, VXOR = 74, 1156, 1220
V_CALLEE = BASE + 0x480       # reads v1 and r3
OUT_CALLEE = BASE + 0x4C0     # writes *r3, never reads it
IN_CALLEE = BASE + 0x500      # reads *r3


def call_with(setup, callee):
    def gen(at):
        body = prologue() + list(setup)
        body.append(bl(at + 4 * len(body), callee))
        return body + epilogue()
    return gen


class StaticTests(unittest.TestCase):
    def test_dead_block_after_tail_call(self):
        code = [cmpwi(3, 0), beq(12), b(BASE + 8, BASE + 0x2000), BLR, li(3, 1), BLR]
        f = F.Func(words(code), BASE)
        self.assertEqual(f.dead_blocks(), [BASE + 12])
        # an indirect jump without a table: targets unknown, nothing is called dead
        f = F.Func(words([MTCTR(4), BCTR, BLR]), BASE)
        self.assertEqual(f.dead_blocks(), [])

    def test_dead_block_does_not_count_for_coverage(self):
        world = make_world({"t": (BASE + 0x100, lambda at: [cmpwi(3, 0), beq(12), b(at + 8, CALLEE), BLR,
                                                                li(3, 1), BLR]),
                            "callee": (CALLEE, [add(3, 3, 4), BLR])})
        linked = FakeLinked({"cand": lambda at: [cmpwi(3, 0), beq(8), b(at + 8, CALLEE), li(3, 1), BLR]})
        r = F.check_one(F.Machine(world), world, linked, "cand", BASE + 0x100, trials=120)
        self.assertEqual(r["verdict"], "EQUIVALENT", r)
        self.assertEqual(r["dead_blocks"], [f"0x{BASE + 0x10C:08X}"])
        self.assertEqual(r["blocks"], 3)

    def test_jump_table_entries_outside_the_function(self):
        base = BASE + 0x100
        cmplwi = dform(10, 6 << 2, 4, 2)                    # cmplwi cr6,r4,2 -> 3 entries
        code = [cmplwi, (16 << 26) | (12 << 21) | (25 << 16) | 0x1C, MTCTR(0), BCTR,
                BASE + 0x800, BASE + 0x900, base + 0x1C, li(3, 7), BLR]
        text = (BASE, BASE + 0x4000)
        f = F.Func(words(code), base, text)
        self.assertEqual(f.tables, {3: [BASE + 0x800, BASE + 0x900, base + 0x1C]})
        self.assertEqual(f.data, {4, 5, 6})
        self.assertEqual(f.block_addrs(), [base, base + 8, base + 0x1C, base + 0x20])
        # without the image's text range only in-function entries are table words (old rule)
        self.assertEqual(F.Func(words(code), base).data, set())

    def test_wide_registers(self):
        world = make_world({
            "mul": (BASE + 0x100, [xo(31, 3, 4, 5, 233), BLR]),                 # mulld
            "pass": (BASE + 0x140, [std(4, 1, -8), ld(4, 1, -8), BLR]),         # save / restore only
            "high": (BASE + 0x180, [std(4, 1, -16), lwz(3, 1, -16), BLR]),      # reads the upper word
        })
        an = world.analysis
        self.assertEqual(an.wide_in(world.by_name["mul"]), frozenset({4, 5}))
        self.assertEqual(an.wide_in(world.by_name["pass"]), frozenset())
        self.assertEqual(an.wide_in(world.by_name["high"]), frozenset({4}))
        machine = F.Machine(world)
        same = FakeLinked({"cand": [std(4, 1, -16), lwz(3, 1, -16), BLR]})
        r = F.check_one(machine, world, same, "cand", world.by_name["high"], trials=120)
        self.assertEqual(r["verdict"], "EQUIVALENT", r)
        self.assertEqual(r["args64"], ["r4"])
        low = FakeLinked({"cand": [std(4, 1, -16), lwz(3, 1, -12), BLR]})        # the lower word instead
        r = F.check_one(machine, world, low, "cand", world.by_name["high"], trials=120)
        self.assertEqual(r["verdict"], "DIFFERENT", r)

    def test_code_consts_equality_idiom(self):
        cntlzw = xo(31, 11, 11, 0, 26)
        f = F.Func(words([addi(11, 3, -1234), cntlzw, BLR]), BASE)
        self.assertIn(1234, F.code_consts(f))

    def test_reads_through(self):
        world = make_world({
            "out": (BASE + 0x100, [stw(4, 3, 0), BLR]),
            "copy": (BASE + 0x140, [xo(31, 3, 30, 3, 444), stw(4, 30, 4), cmpwi(30, 0), BLR]),   # mr r30,r3
            "in": (BASE + 0x180, [lwz(5, 3, 0), BLR]),
            "arith": (BASE + 0x1C0, [addi(5, 3, 4), BLR]),
            "fwd": (BASE + 0x200, lambda at: [b(at, BASE + 0x180)]),            # tail call to a reader
        })
        an = world.analysis
        self.assertFalse(an.reads_through(world.by_name["out"], 3))
        self.assertFalse(an.reads_through(world.by_name["copy"], 3))
        for n in ("in", "arith", "fwd"):
            self.assertTrue(an.reads_through(world.by_name[n], 3), n)

    def test_pointer_pairs_with_fresh_begin(self):
        a = F.ARG_BASE + F.ARG_OFF + 0x10
        trace = [("mem", a, 0x12345679, 4), ("mem", a + 4, 0, 4)]
        self.assertEqual(F.pointer_pairs(trace), [])        # no pointer to derive an end from
        fresh = F.fresh_pairs(trace)
        self.assertEqual(F.fresh_pairs([("mem", a, F.RANDPTR_LO + 0x100, 4), ("mem", a + 4, 0, 4)]), [])
        self.assertEqual(len(fresh), len(F.PAIR_FRESH_STEPS))
        (k1, key1, v1), (k2, key2, v2) = fresh[0]
        self.assertEqual((k1, key1, k2, key2), ("mem", a, "mem", a + 4))
        self.assertTrue(F.HEAP_LO <= v1 < F.HEAP_HI and v1 % 4 == 0)
        self.assertEqual(v2 - v1, 4 * F.PAIR_FRESH_STEPS[0])


class VectorTests(unittest.TestCase):
    def test_decode(self):
        self.assertEqual(F.vec_decode(0x13E348C7), ("lvx", 63, (), 0, 0, (3, 9)))        # lvx128 v63,r3,r9
        self.assertEqual(F.vec_decode(0x138039C7), ("stvx", 60, (), 0, 0, (0, 7)))       # stvx128 v60,r0,r7
        self.assertEqual(F.vec_decode(0x17BEF875)[:3], ("vsubfp", 61, (62, 63)))         # vsubfp128
        self.assertEqual(F.vec_decode(0x179DE9B5)[:3], ("vmsum3fp", 60, (61, 61)))
        self.assertEqual(F.vec_decode(0x17DFFAF5)[:3], ("vor", 62, (63, 63)))
        self.assertEqual(F.vec_decode(0x1BAEF355)[:4], ("vpermwi", 61, (62,), 174))
        self.assertEqual(F.vec_decode(0x1BC4C7D5)[:4], ("vrlimi", 62, (56, 62), 4 | 3 << 8))
        self.assertEqual(F.vec_decode(0x15BCC4F3)[:3], ("vmaddfp", 13, (124, 120, 13)))  # vmaddfp128
        self.assertEqual(F.vec_decode(0x11AC682E)[:3], ("vmaddfp", 13, (12, 0, 13)))     # vmaddfp v13,v12,v0,v13
        self.assertEqual(F.vec_decode(0x1B19E865)[:5], ("vcmpeqfp", 56, (57, 61), 0, 1))
        self.assertIsNone(F.vec_decode((4 << 26) | 588))                                  # vsplth
        ins = F.decode(0x13E348C7, 0)
        self.assertEqual((ins.kind, ins.reads), ("vec", frozenset({3, 9})))

    def test_apply(self):
        f4 = lambda *x: struct.pack(">4f", *x)
        a, c = f4(1, 2, 3, 4), f4(10, 20, 30, 40)
        self.assertEqual(F.vec_apply("vsubfp", [c, a], 0), f4(9, 18, 27, 36))
        self.assertEqual(F.vec_apply("vmsum3fp", [a, c], 0), f4(140, 140, 140, 140))
        self.assertEqual(F.vec_apply("vmsum4fp", [a, c], 0), f4(300, 300, 300, 300))
        self.assertEqual(F.vec_apply("vmaddfp", [a, c, a], 0), f4(11, 42, 93, 164))
        self.assertEqual(F.vec_apply("vnmsubfp", [a, c, a], 0), f4(-9, -38, -87, -156))
        self.assertEqual(F.vec_apply("vpermwi", [a], 0b00011011), a)
        self.assertEqual(F.vec_apply("vpermwi", [a], 0b11100100), f4(4, 3, 2, 1))
        self.assertEqual(F.vec_apply("vspltw", [a], 2), f4(3, 3, 3, 3))
        self.assertEqual(F.vec_apply("vrlimi", [c, a], 0b1000 | 1 << 8), f4(20, 2, 3, 4))
        self.assertEqual(F.vec_apply("vmrghw", [a, c], 0), f4(1, 10, 2, 20))
        self.assertEqual(F.vec_apply("vsldoi", [a, c], 4), f4(2, 3, 4, 10))
        mask = struct.pack(">4I", 0xFFFFFFFF, 0, 0xFFFFFFFF, 0)
        self.assertEqual(F.vec_apply("vsel", [a, c, mask], 0), f4(10, 2, 30, 4))
        self.assertEqual(F.vec_apply("vcmpgefp", [a, f4(1, 3, 2, 4)], 0), struct.pack(">4I", 0xFFFFFFFF, 0, 0xFFFFFFFF, 0xFFFFFFFF))
        self.assertEqual(F.vec_apply("vspltisw", [], -1), b"\xFF" * 16)
        self.assertEqual(F.vec_apply("vctsxs", [f4(1.5, -2.5, 3e10, float("nan"))], 1),
                         struct.pack(">4i", 3, -5, 0x7FFFFFFF, 0))

    @classmethod
    def setUpClass(cls):
        cls.world = make_world({
            "sub": (BASE + 0x100, [vx(VSUBFP, 1, 2, 3), BLR]),
            "mem": (BASE + 0x140, [lvx(0, 0, 3), vx(VSUBFP, 0, 0, 2), li(5, 16), stvx(0, 4, 5), BLR]),
            "vcall": (BASE + 0x200, call_with([vx(VOR, 1, 2, 2)], V_CALLEE)),
            "vcallee": (V_CALLEE, [stvx(1, 0, 3), BLR]),
            "keep": (BASE + 0x300, [BLR]),
            "callee": (CALLEE, [BLR]),
        })
        cls.machine = F.Machine(cls.world)

    def check(self, target, cand, **kw):
        kw.setdefault("trials", 120)
        return F.check_one(self.machine, self.world, FakeLinked({"cand": cand}), "cand",
                           self.world.by_name[target], **kw)

    def test_vector_result(self):
        self.assertEqual(self.check("sub", [vx(VSUBFP, 1, 2, 3), BLR])["verdict"], "EQUIVALENT")
        r = self.check("sub", [vx(VSUBFP, 1, 3, 2), BLR])
        self.assertEqual(r["verdict"], "DIFFERENT", r)
        self.assertIn("return value v1", r["reason"])

    def test_vector_memory(self):
        same = [lvx(13, 0, 3), li(5, 16), vx(VSUBFP, 13, 13, 2), stvx(13, 4, 5), BLR]   # other scratch register
        self.assertEqual(self.check("mem", same)["verdict"], "EQUIVALENT")
        r = self.check("mem", [lvx(0, 0, 3), vx(VSUBFP, 0, 2, 0), li(5, 16), stvx(0, 4, 5), BLR])
        self.assertEqual(r["verdict"], "DIFFERENT", r)
        self.assertIn("memory", r["reason"])

    def test_vector_call_argument(self):
        self.assertEqual(self.world.analysis.vec_live_in(V_CALLEE), frozenset({1}))
        self.assertEqual(self.check("vcall", call_with([vx(VOR, 1, 2, 2)], V_CALLEE))["verdict"], "EQUIVALENT")
        r = self.check("vcall", call_with([vx(VOR, 1, 3, 3)], V_CALLEE))
        self.assertEqual(r["verdict"], "DIFFERENT", r)
        self.assertIn("vector argument v1", r["reason"])
        # v2 is not read by the callee: writing it is free
        self.assertEqual(self.check("vcall", call_with([vx(VOR, 1, 2, 2), vx(VXOR, 2, 2, 2)], V_CALLEE))["verdict"],
                         "EQUIVALENT")

    def test_callee_saved_vector_register(self):
        r = self.check("keep", [vx(VXOR, 20, 20, 20), BLR])
        self.assertEqual(r["verdict"], "DIFFERENT", r)
        self.assertIn("v20", r["reason"])


class CallModelTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        residue = [stw(4, 1, 0x50), addi(3, 1, 0x50)]
        cls.world = make_world({
            "to_out": (BASE + 0x100, call_with(residue, OUT_CALLEE)),
            "to_in": (BASE + 0x200, call_with(residue, IN_CALLEE)),
            "out_callee": (OUT_CALLEE, [stw(4, 3, 0), BLR]),
            "in_callee": (IN_CALLEE, [lwz(5, 3, 0), BLR]),
            "index": (BASE + 0x300, [lwz(4, 3, 0), mulli(4, 4, 0xE0), lwz(5, 3, 4), add(4, 4, 5), add(4, 4, 3),
                                     lbz(3, 4, 0xC4), BLR]),
        })
        cls.machine = F.Machine(cls.world)

    def check(self, target, cand, **kw):
        kw.setdefault("trials", 120)
        return F.check_one(self.machine, self.world, FakeLinked({"cand": cand}), "cand",
                           self.world.by_name[target], **kw)

    def test_out_parameter_residue_is_not_compared(self):
        clean = [addi(3, 1, 0x50)]          # no stale store into the slot before the call
        self.assertEqual(self.check("to_out", call_with(clean, OUT_CALLEE))["verdict"], "EQUIVALENT")
        r = self.check("to_in", call_with(clean, IN_CALLEE))
        self.assertEqual(r["verdict"], "DIFFERENT", r)
        self.assertIn("stack object", r["reason"])

    def test_index_sum_addresses_become_valid(self):
        code = [lwz(4, 3, 0), mulli(4, 4, 0xE0), lwz(5, 3, 4), add(4, 4, 5), add(4, 4, 3), lbz(3, 4, 0xC4), BLR]
        r = self.check("index", code, trials=200)
        self.assertEqual(r["verdict"], "EQUIVALENT", r)
        self.assertGreater(r["valid"], 60)

    def test_event_cap(self):
        self.assertGreaterEqual(F.MAX_EVENTS, 1000)
        self.assertEqual(self.machine.max_events, F.MAX_EVENTS)


class SehTests(unittest.TestCase):
    def obj(self):
        text = bytearray(0x40)
        text[4:8] = (0).to_bytes(4, "big")                  # scope-table word (offset in $T)
        pdata = (0).to_bytes(4, "big") + (5 << 8).to_bytes(4, "big") + \
                (0x14).to_bytes(4, "big") + (3 << 8).to_bytes(4, "big")
        xdata = (1).to_bytes(4, "big") + (4).to_bytes(4, "big") + (0xC).to_bytes(4, "big") + \
                (0x14).to_bytes(4, "big") + (0x10).to_bytes(4, "big")
        sections = [
            xcoff.Section(1, ".text", bytes(text), [xcoff.Reloc(0, "__C_specific_handler", 2), xcoff.Reloc(4, "$T1", 2)]),
            xcoff.Section(2, ".pdata", pdata, [xcoff.Reloc(0, "f", 2), xcoff.Reloc(8, "f", 2)]),
            xcoff.Section(3, ".xdata", xdata, [xcoff.Reloc(4 + 4 * j, "f", 2) for j in range(4)]),
        ]
        symbols = [xcoff.Symbol("f", 8, 1, 2), xcoff.Symbol("$T1", 0, 3, 3),
                   xcoff.Symbol("__C_specific_handler", 0, 0, 2)]
        return xcoff.Coff(sections, symbols)

    def test_pdata_ranges(self):
        self.assertEqual(C.pdata_ranges(self.obj(), "f"), [(0, 0x14), (0x14, 0xC)])

    def test_candidate_scope_table(self):
        self.assertEqual(C.candidate_seh(self.obj(), "f"), ("__C_specific_handler", [(4, 0xC, 0x14, 0x10)]))

    def test_image_scope_table(self):
        base, fn, table = 0x88000000, 0x88000108, 0x88000200
        image = bytearray(0x300)
        put = lambda a, v: image.__setitem__(slice(a - base, a - base + 4), v.to_bytes(4, "big"))
        put(fn - 8, 0x88000040)
        put(fn - 4, table)
        for i, v in enumerate((1, fn + 4, fn + 0xC, fn + 0x14, fn + 0x10)):
            put(table + 4 * i, v)
        self.assertEqual(C.image_seh(bytes(image), base, fn, 0x20), (0x88000040, [(4, 0xC, 0x14, 0x10)]))
        put(table + 12, 1)                                  # constant filter (EXCEPTION_EXECUTE_HANDLER)
        self.assertEqual(C.image_seh(bytes(image), base, fn, 0x20)[1], [(4, 0xC, ("const", 1), 0x10)])


class FaultBlockTests(unittest.TestCase):
    """r3 < 0 -> the function reads 0x70 of a null pointer (always faults); else returns *r4."""

    @staticmethod
    def code(null=0, off=0x70):
        return [cmpwi(3, 0), (16 << 26) | (4 << 21) | (0 << 16) | 12,      # bge +12
                li(11, null), b(BASE + 0x10C, BASE + 0x114), xo(31, 4, 11, 4, 444),   # mr r11,r4
                lwz(3, 11, off), BLR]

    def run_check(self, cand):
        world = make_world({"t": (BASE + 0x100, self.code())})
        linked = FakeLinked({"cand": cand})
        return F.check_one(F.Machine(world), world, linked, "cand", BASE + 0x100, trials=200)

    def test_same_fault_counts_as_covered(self):
        at = F.CAND_BASE
        same = [cmpwi(3, 0), (16 << 26) | (4 << 21) | 12, li(11, 0), b(at + 12, at + 20),
                xo(31, 4, 11, 4, 444), lwz(3, 11, 0x70), BLR]
        r = self.run_check(same)
        self.assertEqual(r["verdict"], "EQUIVALENT", r)
        self.assertEqual([(f["block"], f["address"]) for f in r["fault_blocks"]], [(f"0x{BASE + 0x108:08X}", "0x70")])
        self.assertEqual(r["blocks_covered"], r["blocks"])

    def test_other_behaviour_on_the_fault_path_is_not_covered(self):
        at = F.CAND_BASE
        for null in (4, ):                  # faults at 0x74 instead of 0x70
            cand = [cmpwi(3, 0), (16 << 26) | (4 << 21) | 12, li(11, null), b(at + 12, at + 20),
                    xo(31, 4, 11, 4, 444), lwz(3, 11, 0x70), BLR]
            r = self.run_check(cand)
            self.assertEqual(r["verdict"], "UNCHECKED", r)
            self.assertNotIn("fault_blocks", r)
        # a candidate that returns instead of faulting
        cand = [cmpwi(3, 0), (16 << 26) | (4 << 21) | 12, li(3, 0), BLR, lwz(3, 4, 0x70), BLR]
        r = self.run_check(cand)
        self.assertEqual(r["verdict"], "UNCHECKED", r)


class StrideTests(unittest.TestCase):
    """Loop over 0x1c-byte elements of a begin/end pair at 0xc/0x10 of *r3 (divw by 0x1c)."""

    @staticmethod
    def code():
        divw = xo(31, 8, 9, 30, 491, 1)                  # divw. r8,r9,r30
        return [lwz(11, 3, 0xC), li(30, 0x1C), lwz(10, 3, 0x10), xo(31, 9, 11, 10, 40), divw,   # subf r9,r11,r10
                beq(32),
                lwz(11, 3, 0x10), addi(11, 11, -0x1C), stw(11, 3, 0x10), lwz(9, 3, 0xC),
                xo(31, 9, 9, 11, 40), divw, (16 << 26) | (4 << 21) | (2 << 16) | ((-24) & 0xFFFC),   # bne -24
                li(3, 0), BLR]

    def test_strides_from_divisor_and_step(self):
        world = make_world({"t": (BASE + 0x100, self.code())})
        self.assertEqual(F.code_strides(world.analysis.func(BASE + 0x100)), [0x1C])

    def test_stride_spans_are_appended_after_the_word_spans(self):
        trace = [("mem", 0x7000000C, 0x12345678, 4), ("mem", 0x70000010, 0x9ABCDEF0, 4)]
        plain = F.fresh_pairs(trace)
        plans = {}
        _, _, first = F.pair_mutation([(1, {}, trace, None)], plans, None, [0x1C])
        self.assertEqual(first, plain[0])
        spans = [hi[2] - lo[2] for lo, hi in [first] + plans[0]]
        self.assertEqual(spans[:len(plain)], [4, 8, 12][:len(plain)])
        self.assertEqual(spans[len(plain):], [0x1C, 0x38, 0x54])

    def test_loop_is_covered_and_requested_trials_recorded(self):
        world = make_world({"t": (BASE + 0x100, self.code())})
        linked = FakeLinked({"cand": self.code()})
        r = F.check_one(F.Machine(world), world, linked, "cand", BASE + 0x100, trials=300, time_budget=0)
        self.assertEqual((r["verdict"], r["blocks_covered"], r["trials_requested"]), ("EQUIVALENT", r["blocks"], 300), r)


class ScratchAndLabelTests(unittest.TestCase):
    def test_scratch_directories_are_removed_at_exit(self):
        import tempfile
        made = [Path(tempfile.mkdtemp(prefix="fncheck-test-")) for _ in range(2)]
        saved, keep = list(C._SCRATCH), C.KEEP_SCRATCH
        try:
            C._SCRATCH[:] = made
            C.KEEP_SCRATCH = True
            C._remove_scratch()
            self.assertTrue(all(d.is_dir() for d in made))
            C.KEEP_SCRATCH = False
            C._remove_scratch()
            self.assertFalse(any(d.exists() for d in made))
        finally:
            C._SCRATCH[:], C.KEEP_SCRATCH = saved, keep

    def test_funclet_symbol_becomes_a_label(self):
        import tempfile
        import matching
        # a COFF object with one .text section and three symbols; the last name is in the string table
        def sym(name, value, typ, cls):
            raw = name if isinstance(name, bytes) else name.encode().ljust(8, b"\0")
            return raw + struct.pack("<IhHBB", value, 1, typ, cls, 0)
        long_name = b"fn_88883E4C_filter\0"
        syms = sym("except_d", 0, 0, 6) + sym("fn_par", 8, 0x20, 2) + sym(struct.pack("<II", 0, 4), 0x74, 0x20, 2)
        header = struct.pack("<HHIIIHH", 0x1F2, 1, 0, 20 + 40 + 0x9C, 3, 0, 0)
        section = b".text".ljust(8, b"\0") + struct.pack("<IIIIIIHHI", 0, 0, 0x9C, 60, 0, 0, 0, 0, 0x60000020)
        blob = header + section + bytes(0x9C) + syms + struct.pack("<I", 4 + len(long_name)) + long_name
        with tempfile.TemporaryDirectory() as d:
            path = Path(d) / "t.obj"
            path.write_bytes(blob)
            before = {s.name: s.storage for s in xcoff.read_coff(path).symbols}
            self.assertEqual(before["fn_88883E4C_filter"], 2)
            self.assertEqual(matching.coff_symbols_to_labels(path, {"fn_88883E4C_filter"}), ["fn_88883E4C_filter"])
            after = {s.name: s.storage for s in xcoff.read_coff(path).symbols}
            self.assertEqual(after, dict(before, fn_88883E4C_filter=6))
            self.assertEqual(matching.coff_symbols_to_labels(path, {"absent"}), [])
            # as a label the funclet no longer ends the parent
            self.assertEqual(len(xcoff.read_coff(path).function("fn_par")[0]), 0x9C - 8)


if __name__ == "__main__":
    unittest.main()
