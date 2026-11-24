"""Tests for tools/fn_equiv.py with synthetic PowerPC code (no game data)."""

import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))

import fn_equiv as F  # noqa: E402

BASE = 0x88000000


# --- a tiny assembler for the instructions the tests use
def xo(op, d, a, b, x, rc=0):
    return (op << 26) | (d << 21) | (a << 16) | (b << 11) | (x << 1) | rc


def dform(op, d, a, imm):
    return (op << 26) | (d << 21) | (a << 16) | (imm & 0xFFFF)


def add(d, a, b):
    return xo(31, d, a, b, 266)


def subf(d, a, b):          # d = b - a
    return xo(31, d, a, b, 40)


def addi(d, a, imm):
    return dform(14, d, a, imm)


def li(d, imm):
    return addi(d, 0, imm)


def lwz(d, a, imm):
    return dform(32, d, a, imm)


def stw(s, a, imm):
    return dform(36, s, a, imm)


def stwu(s, a, imm):
    return dform(37, s, a, imm)


def cmpwi(a, imm, cr=0):
    return dform(11, cr << 2, a, imm)


def beq(off, cr=0):         # bc 12, 4*cr+2, off
    return (16 << 26) | (12 << 21) | ((4 * cr + 2) << 16) | (off & 0xFFFC)


def cmplw(a, b, cr=0):
    return xo(31, cr << 2, a, b, 32)


def bne(off, cr=0):         # bc 4, 4*cr+2, off
    return (16 << 26) | (4 << 21) | ((4 * cr + 2) << 16) | (off & 0xFFFC)


def range_loop(miss):
    """for (it = o->begin; it != o->end; ++it) if (*it == 0) return 2;  return miss;
    (begin at +0x40, end at +0x44; an empty range returns 9)"""
    return [lwz(10, 3, 0x40), lwz(9, 3, 0x44), cmplw(10, 9), bne(12), li(3, 9), BLR,
            lwz(11, 10, 0), cmpwi(11, 0), beq(24), addi(10, 10, 4), cmplw(10, 9), bne(-20),
            li(3, miss), BLR,           # the loop's own exit: reached only when end == begin + 4*k
            li(3, 2), BLR]


def bl(frm, to):
    return (18 << 26) | ((to - frm) & 0x03FFFFFC) | 1


BLR = 0x4E800020
MFLR_R12 = 0x7D8802A6
MTLR_R12 = 0x7D8803A6
FADDS_F1 = (59 << 26) | (1 << 21) | (1 << 16) | (2 << 11) | (21 << 1)   # fadds f1,f1,f2
VADDFP = (4 << 26) | (1 << 21) | (2 << 16) | (3 << 11) | 10


def prologue():
    return [MFLR_R12, stw(12, 1, -8), stwu(1, 1, -0x60)]


def epilogue():
    return [addi(1, 1, 0x60), lwz(12, 1, -8), MTLR_R12, BLR]


class FakeLinked:
    """Stands in for fn_equiv.Linked: candidate functions already placed at CAND_BASE."""

    def __init__(self, funcs):
        self.base = F.CAND_BASE
        self.mem = bytearray(F.PAGE)
        self.functions = {}
        pos = self.base
        for name, words in funcs.items():
            code = b"".join(struct.pack(">I", w) for w in (words(pos) if callable(words) else words))
            self.mem[pos - self.base: pos - self.base + len(code)] = code
            self.functions[name] = (pos, len(code), 1)
            pos += (len(code) + 15) & ~15
        self.size = F.PAGE
        self.pristine = bytes(self.mem)
        self.text_ranges = [(self.base, pos, 1)]
        self.unresolved, self.unsupported = {}, {}

    def function(self, name):
        return self.functions.get(name)


def make_world(funcs):
    """funcs: {name: (address, words or callable(address) -> words)} placed in a synthetic image."""
    image = bytearray(0x10000)
    symbols = []
    for name, (addr, words) in funcs.items():
        ws = words(addr) if callable(words) else words
        code = b"".join(struct.pack(">I", w) for w in ws)
        image[addr - BASE: addr - BASE + len(code)] = code
        symbols.append((name, ".text", addr, len(code)))
    symbols.append(("g_counter", ".data", BASE + 0x8000, 4))
    return F.World(BASE, bytes(image), symbols, lazy_ranges=[(BASE + 0xC000, BASE + 0x10000)],
                   text_range=(BASE, BASE + 0x4000))


CALLEE = BASE + 0x400


def outparam_code(off, extra=0):
    """callee(&local, r4); return local + extra   (local at r1+off)"""
    def gen(at):
        body = prologue() + [addi(3, 1, off)]
        body.append(bl(at + 4 * len(body), CALLEE))
        body += [lwz(3, 1, off), addi(3, 3, extra)] + epilogue()
        return body
    return gen


def caller_code(adjust):
    """r3 = callee(r3 + adjust, r4); return r3 + 1"""
    def gen(at):
        body = prologue() + [addi(3, 3, adjust)]
        body.append(bl(at + 4 * len(body), CALLEE))
        body += [addi(3, 3, 1)] + epilogue()
        return body
    return gen


class PointerPairTests(unittest.TestCase):
    def test_pairs_from_adjacent_words_and_argument_registers(self):
        heap = F.RANDPTR_LO + 0x1000
        trace = [("reg", 3, heap, 4), ("reg", 4, 7, 4), ("reg", 13, heap, 4),
                 ("mem", heap + 0x40, heap + 0x100, 4), ("mem", heap + 0x44, heap + 0x5000, 4),
                 ("mem", heap + 0x40, heap + 0x100, 4),                 # read again: listed once
                 ("mem", heap + 0x80, heap + 0x200, 4), ("mem", heap + 0x46, 0x1234, 2)]
        plans = F.pointer_pairs(trace, live={3, 4})
        # end <- begin + 4*k for every step, smallest count first; begin <- end + 4*k too
        ends = [v for kind, key, v in plans if (kind, key) == ("mem", heap + 0x44)]
        self.assertEqual(ends, [heap + 0x100 + 4 * k for k in F.PAIR_STEPS])
        self.assertIn(("mem", heap + 0x40, heap + 0x5004), plans)
        # a far word is not paired; the non-pointer argument is a destination only, never a source
        self.assertFalse(any(key == heap + 0x80 for _, key, _ in plans))
        self.assertIn(("reg", 4, heap + 4), plans)
        self.assertFalse(any(kind == "reg" and key in (3, 13) for kind, key, _ in plans))
        self.assertEqual(F.pointer_pairs([("reg", 3, 5, 4), ("mem", heap, 0, 4)]), [])

    def test_pair_mutation_drains_newest_first(self):
        heap = F.RANDPTR_LO + 0x2000
        tr = [("mem", heap, heap + 0x40, 4), ("mem", heap + 4, 0, 4)]
        corpus = [(1, {"regs": {}}, []), (2, {"regs": {}}, tr)]
        plans = {}
        got = [F.pair_mutation(corpus, plans) for _ in range(len(F.PAIR_STEPS) + 1)]
        self.assertEqual([g[0] for g in got[:-1]], [2] * len(F.PAIR_STEPS))
        self.assertEqual(got[0][2], ("mem", heap + 4, heap + 0x44))
        self.assertIsNone(got[-1])


@unittest.skipUnless(F.HAVE_UNICORN, "unicorn not installed")
class EquivTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.world = make_world({
            "orig_add": (BASE + 0x100, [add(3, 3, 4), BLR]),
            "orig_sub": (BASE + 0x140, [subf(3, 4, 3), BLR]),           # r3 = r3 - r4
            "orig_store": (BASE + 0x180, [stw(4, 3, 8), BLR]),
            "orig_branch": (BASE + 0x1C0, [cmpwi(3, 0), beq(12), li(3, 1), BLR, li(3, 2), BLR]),
            "orig_call": (BASE + 0x200, caller_code(4)),
            "orig_vec": (BASE + 0x300, [VADDFP, BLR]),
            "orig_float": (BASE + 0x340, [FADDS_F1, BLR]),
            "orig_deref": (BASE + 0x380, [lwz(3, 3, 4), lwz(3, 3, 0), BLR]),
            "callee": (CALLEE, [lwz(5, 3, 0), add(3, 5, 4), BLR]),       # reads r3, r4
            "orig_out": (BASE + 0x700, outparam_code(0x50)),
            "orig_rodata": (BASE + 0x600, [dform(15, 4, 0, 0x8800), lwz(3, 4, 0x3000), BLR]),
            "orig_range": (BASE + 0x800, range_loop(5)),
            "orig_rec": (BASE + 0x500, lambda at: prologue() + [addi(3, 3, -1), bl(at + 16, at)] + epilogue()),
        })
        cls.machine = F.Machine(cls.world)

    def check(self, target, cand_words, **kw):
        linked = FakeLinked({"cand": cand_words})
        addr = self.world.by_name[target]
        kw.setdefault("trials", 120)
        return F.check_one(self.machine, self.world, linked, "cand", addr, **kw)

    def test_commuted_add_is_equivalent(self):
        r = self.check("orig_add", [add(3, 4, 3), BLR])
        self.assertEqual(r["verdict"], "EQUIVALENT", r)
        self.assertEqual(r["coverage"], 1.0)

    def test_swapped_subtraction_is_different(self):
        r = self.check("orig_sub", [subf(3, 3, 4), BLR])
        self.assertEqual(r["verdict"], "DIFFERENT", r)
        self.assertIn("return value", r["reason"])

    def test_dropped_store_is_different(self):
        r = self.check("orig_store", [BLR])
        self.assertEqual(r["verdict"], "DIFFERENT", r)
        self.assertIn("memory", r["reason"])
        self.assertEqual(self.check("orig_store", [stw(4, 3, 8), BLR])["verdict"], "EQUIVALENT")

    def test_store_to_wrong_offset_is_different(self):
        r = self.check("orig_store", [stw(4, 3, 12), BLR])
        self.assertEqual(r["verdict"], "DIFFERENT", r)

    def test_branches_and_coverage(self):
        same = [cmpwi(3, 0), beq(12), li(3, 1), BLR, li(3, 2), BLR]
        r = self.check("orig_branch", same)
        self.assertEqual(r["verdict"], "EQUIVALENT", r)
        self.assertEqual(r["blocks_covered"], r["blocks"])
        flipped = [cmpwi(3, 0), beq(12), li(3, 2), BLR, li(3, 1), BLR]
        self.assertEqual(self.check("orig_branch", flipped)["verdict"], "DIFFERENT")
        off_by_one = [cmpwi(3, 1), beq(12), li(3, 1), BLR, li(3, 2), BLR]
        self.assertEqual(self.check("orig_branch", off_by_one)["verdict"], "DIFFERENT")

    def test_call_arguments_compared(self):
        def cand(adjust):
            def gen(at):
                body = prologue() + [addi(3, 3, adjust)]
                body.append(bl(at + 4 * len(body), CALLEE))
                return body + [addi(3, 3, 1)] + epilogue()
            return gen
        self.assertEqual(self.check("orig_call", cand(4))["verdict"], "EQUIVALENT")
        r = self.check("orig_call", cand(8))
        self.assertEqual(r["verdict"], "DIFFERENT", r)
        self.assertIn("argument r3", r["reason"])

    def test_missing_call_is_different(self):
        r = self.check("orig_call", prologue() + [addi(3, 3, 5)] + epilogue())
        self.assertEqual(r["verdict"], "DIFFERENT", r)
        self.assertIn("call", r["reason"])

    def test_recursive_call_is_intercepted(self):
        target = self.world.by_name["orig_rec"]
        cand = lambda at: prologue() + [addi(3, 3, -1), bl(at + 16, target)] + epilogue()
        self.assertEqual(self.check("orig_rec", cand)["verdict"], "EQUIVALENT")
        cand2 = lambda at: prologue() + [addi(3, 3, -2), bl(at + 16, target)] + epilogue()
        self.assertEqual(self.check("orig_rec", cand2)["verdict"], "DIFFERENT")

    def test_vector_code(self):
        # vaddfp v1,v2,v3 is interpreted (see tests/test_fn_equiv_q5f.py for the vector model)
        r = self.check("orig_vec", [VADDFP, BLR])
        self.assertEqual(r["verdict"], "EQUIVALENT", r)
        self.assertTrue(r["vmx"])
        vsplth = (4 << 26) | (1 << 21) | (2 << 11) | 588     # not interpreted
        r = self.check("orig_vec", [vsplth, BLR])
        self.assertEqual(r["verdict"], "UNCHECKED")
        self.assertIn("vmx", r["reason"])

    def test_float_return(self):
        r = self.check("orig_float", [FADDS_F1, BLR], return_kind="float")
        self.assertEqual(r["verdict"], "EQUIVALENT", r)
        fsubs = (59 << 26) | (1 << 21) | (1 << 16) | (2 << 11) | (20 << 1)
        r = self.check("orig_float", [fsubs, BLR], return_kind="float")
        self.assertEqual(r["verdict"], "DIFFERENT", r)

    def test_out_parameter(self):
        # the callee's store through a pointer into the frame is modelled: the same value is read
        # back wherever the candidate's frame puts the local, and a different use of it is seen
        self.assertEqual(self.check("orig_out", outparam_code(0x54))["verdict"], "EQUIVALENT")
        r = self.check("orig_out", outparam_code(0x54, extra=1))
        self.assertEqual(r["verdict"], "DIFFERENT", r)
        # pre-initialising a pure out-parameter the original leaves unset is not a difference
        def preinit(at):
            body = prologue() + [li(5, 7), stw(5, 1, 0x54), addi(3, 1, 0x54)]
            body.append(bl(at + 4 * len(body), CALLEE))
            return body + [lwz(3, 1, 0x54), addi(3, 3, 0)] + epilogue()
        self.assertEqual(self.check("orig_out", preinit)["verdict"], "EQUIVALENT")

    def test_begin_end_loop_reaches_its_exit(self):
        # random begin/end pointers never sit a few words apart, so only the pointer-pair
        # mutation (end = begin + 4*k) reaches the block after the loop
        r = self.check("orig_range", range_loop(5), trials=400, time_budget=0)
        self.assertEqual(r["verdict"], "EQUIVALENT", r)
        self.assertEqual(r["blocks_covered"], r["blocks"], r)
        # a candidate that differs only on that exit is caught
        r = self.check("orig_range", range_loop(6), trials=400, time_budget=0)
        self.assertEqual(r["verdict"], "DIFFERENT", r)
        self.assertIn("return value", r["reason"])

    def test_read_only_data_is_not_mutated(self):
        # the original reads a constant from read-only image data; the candidate has the same
        # constant elsewhere (here: an immediate). Trials must not change read-only data.
        r = self.check("orig_rodata", [li(3, 0), BLR])
        self.assertEqual(r["verdict"], "EQUIVALENT", r)

    def test_pointer_chains_resolve(self):
        r = self.check("orig_deref", [lwz(3, 3, 4), lwz(3, 3, 0), BLR])
        self.assertEqual(r["verdict"], "EQUIVALENT", r)
        self.assertGreater(r["valid"], 60)
        r = self.check("orig_deref", [lwz(3, 3, 4), lwz(3, 3, 4), BLR])
        self.assertEqual(r["verdict"], "DIFFERENT", r)


class DecodeTests(unittest.TestCase):
    def test_register_use(self):
        ins = F.decode(add(3, 4, 5), 0)
        self.assertEqual(ins.reads, {4, 5})
        self.assertEqual(ins.writes, {3})
        ins = F.decode(stw(4, 3, 8), 0)
        self.assertEqual(ins.reads, {3, 4})
        self.assertEqual(F.decode(FADDS_F1, 0).writes, {33})
        self.assertEqual(F.decode(VADDFP, 0).kind, "vec")
        self.assertEqual(F.decode(bl(0x100, 0x200), 0x100).target, 0x200)

    def test_or_self_is_a_nop(self):
        ins = F.decode(xo(31, 8, 8, 8, 444), 0)          # mr r8, r8 (hint)
        self.assertEqual((set(ins.reads), set(ins.writes)), (set(), set()))
        self.assertEqual(F.decode(xo(31, 3, 4, 3, 444), 0).reads, {3})   # mr r4, r3: real

    def test_liveness(self):
        world = make_world({"f": (BASE + 0x100, [lwz(5, 3, 0), add(3, 5, 4), BLR]),
                            "g": (BASE + 0x200, [li(4, 1), add(3, 3, 4), BLR])})
        self.assertEqual(world.analysis.live_in(BASE + 0x100), {3, 4})
        self.assertEqual(world.analysis.live_in(BASE + 0x200), {3})


if __name__ == "__main__":
    unittest.main()
