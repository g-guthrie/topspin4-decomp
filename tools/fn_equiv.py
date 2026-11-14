#!/usr/bin/env python3
"""Behavioural equivalence check: run the original function and a candidate side by side.

Usage (same interface as tools/fn_check.py):
  python3 tools/fn_equiv.py path/to/candidate.c ts4_name=0x88170328 [...] [--flags /GS-]
        [--trials 400] [--seed 1] [--min-coverage 0.9] [--json out.json] [--quiet]

Each mapping pairs a function defined by the candidate (left) with the original
function (right: a symbols.txt name or address). The candidate is compiled with
the project compiler exactly like fn_check.py, linked into a scratch region of an
emulated address space that also holds the decompressed original image
(orig/54540859/Swing_DLL.dll), and both functions are executed in a PowerPC CPU
emulator (Unicorn 2, PPC64 big-endian, 64-bit mode with 32-bit truncated
effective addresses as on Xenon) from identical seeded initial states.

Model (see docs/equivalence-tier.md for the full policy):
- Arguments: r3..r10 and f1..f13 that the ORIGINAL reads before writing (static
  liveness over its control-flow graph, calls included) get seeded values;
  integers are mostly pointers into fresh argument buffers, otherwise 0, small
  numbers, -1, comparison constants of the original, random words. Floats include
  0, -0, +-1, NaN, +-inf, huge and tiny values. Other volatile registers hold
  recognisable poison values; r14-r31/f14-f31 hold canaries that must survive.
- Memory: the image is mapped read/write at its real address. Uninitialised
  .data/BSS and the heap region 0x40000000-0x6FFFFFFF are materialised lazily,
  one 4 KB page at a time, with words drawn from a seeded distribution (many of
  them pointers back into the heap), so every pointer chain resolves to fresh
  buffers and both runs see byte-identical data. Truncated effective addresses
  (upper 32 bits set) alias the low page, as on hardware.
- Calls: every transfer of control out of the function (bl, tail b, bctrl to an
  image function or to a heap "function pointer") is intercepted. The callee is
  not executed. The event records the callee address, the argument registers the
  callee reads (static liveness of the image callee; for unknown callees the
  registers that are not poison in both runs) and the memory state written so far.
  The callee "returns" seeded r3/f1 values and clobbers exactly the volatile
  registers it (transitively) writes, so LTCG callers that keep volatile
  registers live across a call still behave as in the real program.
  memcpy/memset are emulated natively (effects only, no event), so a copy that
  one side inlines and the other calls compares equal. Register save/restore
  helpers and the stack probe run for real.
- Observables compared per trial: the call sequence (callee, argument values,
  memory delta at the call), the outcome (return / trap / fault), the return
  value (r3 and/or f1, chosen from how the image's callers use them, or from the
  candidate's declared return type), the final memory delta (every byte outside
  the stack whose value changed: address, value) and callee-saved registers.
- Trials where the ORIGINAL faults (e.g. dereferences a small integer) or runs
  past the instruction budget are discarded: the input violates its
  precondition. A candidate that faults where the original did not is DIFFERENT.
- Coverage: basic blocks of the original reached by valid trials.

Verdicts: EQUIVALENT (all valid trials agree, at least --min-valid valid trials,
block coverage >= --min-coverage), DIFFERENT (first differing trial printed,
with arguments simplified where the difference persists), UNCHECKED (reason:
vector/VMX128 code, unresolved symbol, unsupported instruction, too few valid
trials, coverage below threshold, ...).

Exit status: 0 when every mapping is EQUIVALENT, 1 if any is DIFFERENT, 2 otherwise.
Requires unicorn (pip install unicorn), a completed tools/matching.py run and
work/matching-tools. Standard library plus unicorn only.
"""

from __future__ import annotations

import argparse
import bisect
import ctypes
import hashlib
import json
import math
import os
import pickle
import random
import re
import shutil
import struct
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CHECKER_VERSION = "fn_equiv/1"
DLL = ROOT / "orig" / "54540859" / "Swing_DLL.dll"


def default_matching_dir() -> Path | None:
    """Highest work/matching-bNN whose work/bNN.log has a 'Matched' line."""
    best = None
    for log in (ROOT / "work").glob("b*.log"):
        m = re.fullmatch(r"b(\d+)\.log", log.name)
        d = ROOT / "work" / f"matching-b{m.group(1)}" if m else None
        if not m or not (d / "split").is_dir():
            continue
        try:
            text = log.read_text(errors="replace")
        except OSError:
            continue
        if re.search(r"Matched \d+ functions", text) and (best is None or int(m.group(1)) > best[0]):
            best = (int(m.group(1)), d)
    return best[1] if best else None


if not os.environ.get("TS4_MATCHING_DIR"):
    _d = default_matching_dir()
    if _d:
        os.environ["TS4_MATCHING_DIR"] = str(_d)

try:
    from unicorn import Uc, UcError, UC_ARCH_PPC, UC_MODE_PPC64, UC_MODE_BIG_ENDIAN, UC_PROT_ALL
    from unicorn import UC_HOOK_BLOCK, UC_HOOK_MEM_READ, UC_HOOK_MEM_UNMAPPED, UC_HOOK_MEM_WRITE, UC_HOOK_INTR, UC_HOOK_CODE
    from unicorn import UC_TLB_VIRTUAL
    from unicorn import ppc_const as P
    HAVE_UNICORN = True
except ImportError:  # pragma: no cover - reported by the CLI
    HAVE_UNICORN = False

# ---------------------------------------------------------------------------
# Address space layout
PAGE = 0x1000
CAND_BASE = 0x89000000            # linked candidate object (within bl range of the image)
HEAP_LO, HEAP_HI = 0x40000000, 0x70000000
ARG_BASE = 0x40000000             # argument buffer i: ARG_BASE + i*ARG_STRIDE + ARG_OFF
ARG_STRIDE = 0x01000000
ARG_OFF = 0x8000
RANDPTR_LO = 0x48000000           # random heap pointers in data / return values
TLS_PTR = 0x5F000100              # r13
STACK_LO, STACK_HI = 0x7F000000, 0x7F100000
STACK_TOP = 0x7F0F0000            # r1 at entry; above it: caller frame (seeded)
RET_MAGIC = 0x7FFF0000
MSR = 0x8000000000002000          # SF (64-bit) | FP
UNRESOLVED_BASE = 0xEEE00000
STACK_ARG_WINDOW = 16             # bytes of a frame object passed by pointer that are compared

GPR_ARGS = tuple(range(3, 11))
FPR_ARGS = tuple(32 + i for i in range(1, 14))
ARGS = frozenset(GPR_ARGS + FPR_ARGS)
GPR_ARG_SET = frozenset(GPR_ARGS)
VOLATILE = frozenset((0,) + tuple(range(3, 13)) + tuple(32 + i for i in range(0, 14)))
NONVOL_GPR = tuple(range(14, 32))
NONVOL_FPR = tuple(range(14, 32))
HELPER_PREFIXES = ("__savegprlr", "__restgprlr", "__savefpr", "__restfpr", "_RtlCheckStack",
                   "__savegpr", "__restgpr")
VMX_HELPERS = ("__savevmx", "__restvmx")
LIBC = ("memcpy", "memset", "memmove")
POISON_TAG = 0xBAD00000


def sext(v, bits):
    v &= (1 << bits) - 1
    return v - (1 << bits) if v >> (bits - 1) else v


# ---------------------------------------------------------------------------
# PowerPC decoding: register reads/writes and control flow (GPR n = n, FPR n = 32+n)

VEC31 = {6, 7, 38, 39, 71, 103, 135, 167, 199, 231, 359, 487, 519, 551, 647, 679, 775, 807, 903, 935}
XO2 = {8, 10, 11, 40, 75, 136, 138, 233, 235, 266, 459, 491, 9, 73, 457, 489}   # rD <- rA, rB
XO1 = {104, 200, 202, 232, 234}                                                  # rD <- rA
LOG2 = {28, 60, 444, 412, 316, 476, 124, 284, 24, 536, 792, 27, 539, 794}        # rA <- rS, rB
LOG1 = {824, 826, 827, 26, 58, 954, 922, 986}                                    # rA <- rS
LDX = {23, 55, 87, 119, 279, 311, 343, 375, 21, 53, 341, 373, 790, 534, 532, 20, 84}
LDX_U = {55, 119, 311, 375, 53, 373}
STX = {151, 183, 215, 247, 407, 439, 149, 181, 918, 662, 660, 150, 214}
STX_U = {183, 247, 439, 181}
FLDX = {535: False, 567: True, 599: False, 631: True}
FSTX = {663: False, 695: True, 727: False, 759: True, 983: False}
CACHE = {278, 246, 86, 54, 982, 470, 1014}
F59 = {18: "AB", 20: "AB", 21: "AB", 22: "B", 24: "B", 25: "AC", 26: "B", 28: "ABC", 29: "ABC", 30: "ABC", 31: "ABC"}
F63A = {18: "AB", 20: "AB", 21: "AB", 22: "B", 23: "ABC", 24: "B", 25: "AC", 26: "B", 28: "ABC", 29: "ABC", 30: "ABC", 31: "ABC"}
F63B = {12, 14, 15, 814, 815, 846, 40, 72, 136, 264}   # fD <- fB
ALL_GPR = frozenset(range(32))
HELPER_DEFS = frozenset((0, 11, 12) + tuple(range(14, 32)) + tuple(32 + i for i in range(14, 32)))


class Insn:
    __slots__ = ("reads", "writes", "kind", "target", "word")

    def __init__(self, word, reads=(), writes=(), kind=None, target=None):
        self.word, self.reads, self.writes, self.kind, self.target = word, frozenset(reads), frozenset(writes), kind, target


def decode(w: int, pc: int) -> Insn:
    """Register use/def and control flow of one instruction. kind: None (plain),
    'b' 'bc' 'bl' 'blr' 'bclr' 'bctr' 'bcctr' 'bctrl' 'trap' 'sc' 'vec' 'dcbz' 'mftb' 'unknown'."""
    op = w >> 26
    d, a, b, c = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31, (w >> 6) & 31
    ra0 = (a,) if a else ()
    if op in (4, 5, 6):
        return Insn(w, kind="vec")
    if op == 18:
        li = sext(w & 0x03FFFFFC, 26)
        tgt = (li if w & 2 else pc + li) & 0xFFFFFFFF
        return Insn(w, kind="bl" if w & 1 else "b", target=tgt)
    if op == 16:
        bd = sext(w & 0xFFFC, 16)
        tgt = (bd if w & 2 else pc + bd) & 0xFFFFFFFF
        if w & 1:
            return Insn(w, kind="bl", target=tgt)   # bcl: treat as a call
        always = (d & 0x14) == 0x14
        return Insn(w, kind="b" if always else "bc", target=tgt)
    if op == 19:
        xo = (w >> 1) & 0x3FF
        always = (d & 0x14) == 0x14
        if xo == 16:
            if w & 1:
                return Insn(w, kind="bctrl")      # blrl: indirect call
            return Insn(w, kind="blr" if always else "bclr")
        if xo == 528:
            if w & 1:
                return Insn(w, kind="bctrl")
            return Insn(w, kind="bctr" if always else "bcctr")
        if xo in (0, 33, 129, 193, 225, 257, 289, 417, 449, 150):
            return Insn(w)
        return Insn(w, kind="unknown")
    if op in (2, 3):
        return Insn(w, (a,), (), "trap")
    if op == 17:
        return Insn(w, kind="sc")
    if op in (7, 8, 12, 13):
        return Insn(w, (a,), (d,))
    if op in (10, 11):
        return Insn(w, (a,), ())
    if op in (14, 15):
        return Insn(w, ra0, (d,))
    if op == 20:
        return Insn(w, (d, a), (a,))
    if op == 21:
        return Insn(w, (d,), (a,))
    if op == 23:
        return Insn(w, (d, b), (a,))
    if 24 <= op <= 29:
        return Insn(w, (d,), (a,))
    if op == 30:
        x3 = (w >> 2) & 7
        if x3 in (0, 1, 2):
            return Insn(w, (d,), (a,))
        if x3 == 3:
            return Insn(w, (d, a), (a,))
        if ((w >> 1) & 0xF) in (8, 9):
            return Insn(w, (d, b), (a,))
        return Insn(w, kind="unknown")
    if op in (32, 34, 40, 42):
        return Insn(w, ra0, (d,))
    if op in (33, 35, 41, 43):
        return Insn(w, (a,), (d, a))
    if op in (36, 38, 44):
        return Insn(w, (d,) + ra0, ())
    if op in (37, 39, 45):
        return Insn(w, (d, a), (a,))
    if op == 46:
        return Insn(w, ra0, tuple(range(d, 32)))
    if op == 47:
        return Insn(w, tuple(range(d, 32)) + ra0, ())
    if op in (48, 50):
        return Insn(w, ra0, (32 + d,))
    if op in (49, 51):
        return Insn(w, (a,), (32 + d, a))
    if op in (52, 54):
        return Insn(w, (32 + d,) + ra0, ())
    if op in (53, 55):
        return Insn(w, (32 + d, a), (a,))
    if op == 58:
        x = w & 3
        if x == 1:
            return Insn(w, (a,), (d, a))
        return Insn(w, ra0, (d,))
    if op == 62:
        x = w & 3
        if x == 1:
            return Insn(w, (d, a), (a,))
        return Insn(w, (d,) + ra0, ())
    if op in (59, 63):
        x5 = (w >> 1) & 31
        table = F59 if op == 59 else F63A
        if x5 in table:
            regs = {"A": 32 + a, "B": 32 + b, "C": 32 + c}
            return Insn(w, tuple(regs[k] for k in table[x5]), (32 + d,))
        if op == 59:
            return Insn(w, kind="unknown")
        xo = (w >> 1) & 0x3FF
        if xo in (0, 32):
            return Insn(w, (32 + a, 32 + b), ())
        if xo in F63B:
            return Insn(w, (32 + b,), (32 + d,))
        if xo == 583:
            return Insn(w, (), (32 + d,))
        if xo == 711:
            return Insn(w, (32 + b,), ())
        if xo in (38, 70, 134, 64):
            return Insn(w)
        return Insn(w, kind="unknown")
    if op == 31:
        xo = (w >> 1) & 0x3FF
        xo9 = xo & 0x1FF
        if xo in VEC31:
            return Insn(w, kind="vec")
        if xo in (0, 32):
            return Insn(w, (a, b), ())
        if xo in (4, 68):
            return Insn(w, (a, b), (), "trap")
        if xo9 in XO2 and xo not in LOG2 and xo not in LDX and xo not in STX:
            return Insn(w, (a, b), (d,))
        if xo9 in XO1:
            return Insn(w, (a,), (d,))
        if xo in LOG2:
            return Insn(w, (d, b), (a,))
        if xo in LOG1:
            return Insn(w, (d,), (a,))
        if xo in LDX:
            return Insn(w, ra0 + (b,), (d, a) if xo in LDX_U else (d,))
        if xo in STX:
            return Insn(w, (d,) + ra0 + (b,), (a,) if xo in STX_U else ())
        if xo in FLDX:
            return Insn(w, ra0 + (b,), (32 + d, a) if FLDX[xo] else (32 + d,))
        if xo in FSTX:
            return Insn(w, (32 + d,) + ra0 + (b,), (a,) if FSTX[xo] else ())
        if xo == 339:                       # mfspr (LR/CTR/XER are not tracked)
            return Insn(w, (), (d,))
        if xo == 371:
            return Insn(w, (), (d,), "mftb")
        if xo in (467, 144, 146, 178):      # mtspr, mtcrf, mtmsr, mtmsrd
            return Insn(w, (d,), ())
        if xo in (19, 83):                  # mfcr, mfmsr
            return Insn(w, (), (d,))
        if xo in CACHE:
            return Insn(w, ra0 + (b,), (), "dcbz" if xo == 1014 else None)
        if xo in (598, 854):
            return Insn(w)
        return Insn(w, kind="unknown")
    return Insn(w, kind="unknown")


def is_vector(w: int) -> bool:
    return decode(w, 0).kind == "vec"


TERMINATORS = {"b", "bc", "blr", "bclr", "bctr", "bcctr"}


class Func:
    """Decoded function: instructions, jump tables, basic blocks."""

    def __init__(self, code: bytes, base: int):
        self.base, self.size = base, len(code)
        n = len(code) // 4
        words = struct.unpack(f">{n}I", code[: n * 4])
        self.insns = [decode(w, base + 4 * i) for i, w in enumerate(words)]
        self.data = set()           # indices of jump-table words
        self.tables = {}            # index of bctr -> [target addresses]
        for i, ins in enumerate(self.insns):
            if ins.kind != "bctr":
                continue
            prev = [x.word for x in self.insns[max(0, i - 8):i]]
            if not any((x >> 26) == 31 and ((x >> 1) & 0x3FF) == 467 for x in prev):
                continue            # no mtctr shortly before: a tail call through ctr
            j, tgts = i + 1, []
            while j < n and base <= words[j] < base + self.size and (words[j] - base) % 4 == 0:
                tgts.append(words[j])
                j += 1
            if tgts:
                self.tables[i] = tgts
                self.data.update(range(i + 1, j))
        leaders = {0}
        for i, ins in enumerate(self.insns):
            if i in self.data:
                continue
            if ins.kind in TERMINATORS:
                if ins.target is not None and base <= ins.target < base + self.size:
                    leaders.add((ins.target - base) // 4)
                leaders.add(i + 1)
            for t in self.tables.get(i, ()):
                leaders.add((t - base) // 4)
        leaders = sorted(x for x in leaders if 0 <= x < n and x not in self.data)
        self.blocks = []            # (start index, end index exclusive)
        for k, s in enumerate(leaders):
            e = leaders[k + 1] if k + 1 < len(leaders) else n
            e2 = s
            while e2 < e and e2 not in self.data:
                e2 += 1
            if e2 > s:
                self.blocks.append((s, e2))

    def inside(self, addr):
        return self.base <= addr < self.base + self.size

    def block_addrs(self):
        return [self.base + 4 * s for s, _ in self.blocks]

    def has_vector(self):
        return any(ins.kind == "vec" for i, ins in enumerate(self.insns) if i not in self.data)

    def code_words(self):
        return [(self.base + 4 * i, ins) for i, ins in enumerate(self.insns) if i not in self.data]


class Analysis:
    """Static facts about image functions: argument registers read (live-in) and
    registers written (transitively). `code_of(addr)` returns the bytes of the
    function starting at addr, or None."""

    def __init__(self, code_of, is_helper=lambda a: False):
        self.code_of = code_of
        self.is_helper = is_helper
        self.funcs, self.live, self.defs = {}, {}, {}
        self._busy_live, self._busy_defs = set(), set()

    def func(self, addr):
        if addr not in self.funcs:
            code = self.code_of(addr)
            self.funcs[addr] = Func(code, addr) if code else None
        return self.funcs[addr]

    def defs_of(self, addr, depth=0):
        """Registers (GPR/FPR) the function at addr may write, transitively; VOLATILE if unknown."""
        if addr in self.defs:
            return self.defs[addr]
        if self.is_helper(addr):
            return HELPER_DEFS
        f = self.func(addr)
        if f is None or depth > 40 or addr in self._busy_defs:
            return VOLATILE | ALL_GPR
        self._busy_defs.add(addr)
        out = set()
        exact = True
        for i, ins in f.code_words():
            out |= ins.writes
            k = ins.kind
            if k in ("bl",) or (k == "b" and not f.inside(ins.target)) or (k == "bc" and not f.inside(ins.target)):
                sub = self.defs_of(ins.target, depth + 1)
                out |= sub
                if ins.target not in self.defs:
                    exact = False
            elif k in ("bctrl", "unknown", "sc") or (k == "bctr" and (i - f.base) // 4 not in f.tables):
                out |= VOLATILE
        self._busy_defs.discard(addr)
        res = frozenset(out)
        self.defs[addr] = res
        return res

    def live_in(self, addr, depth=0):
        """Argument registers (r3-r10, f1-f13) the function reads before writing; None if unknown."""
        if addr in self.live:
            return self.live[addr]
        if self.is_helper(addr):
            return frozenset()
        f = self.func(addr)
        if f is None or depth > 40 or addr in self._busy_live:
            return None
        self._busy_live.add(addr)
        unknown = False
        nb = len(f.blocks)
        start_of = {s: k for k, (s, _) in enumerate(f.blocks)}
        succ, gen, kill = [], [], []
        for k, (s, e) in enumerate(f.blocks):
            g, kl = set(), set()
            nxt = []
            for i in range(s, e):
                ins = f.insns[i]
                kind = ins.kind
                reads, writes = set(ins.reads), set(ins.writes)
                if kind == "bl" or (kind in ("b", "bc") and not f.inside(ins.target)):
                    sub = self.live_in(ins.target, depth + 1)
                    reads |= GPR_ARG_SET if sub is None else sub
                    writes |= self.defs_of(ins.target, depth + 1)
                elif kind == "bctrl" or (kind == "bctr" and i not in f.tables) or (kind == "bcctr"):
                    # indirect call: only r3 ('this') is assumed to be passed through from entry;
                    # arguments set up locally are killed before the call anyway
                    reads.add(3)
                    writes |= VOLATILE
                elif kind == "unknown":
                    unknown = True
                g |= reads - kl
                kl |= writes
            last = f.insns[e - 1]
            lk = last.kind
            if lk in ("b", "bc") and f.inside(last.target):
                t = (last.target - f.base) // 4
                if t in start_of:
                    nxt.append(start_of[t])
            if e - 1 in f.tables:
                nxt += [start_of[(t - f.base) // 4] for t in f.tables[e - 1] if (t - f.base) // 4 in start_of]
            if lk not in ("b", "blr", "bctr") and k + 1 < nb and f.blocks[k + 1][0] == e:
                nxt.append(k + 1)
            succ.append(nxt)
            gen.append(g & ARGS)
            kill.append(kl)
        live = [set() for _ in range(nb)]
        changed = True
        while changed:
            changed = False
            for k in range(nb - 1, -1, -1):
                out = set()
                for j in succ[k]:
                    out |= live[j]
                new = gen[k] | (out - kill[k])
                if new != live[k]:
                    live[k] = new
                    changed = True
        self._busy_live.discard(addr)
        res = None if unknown else frozenset(live[0]) if nb else frozenset()
        self.live[addr] = res
        return res


# ---------------------------------------------------------------------------
# The original image and its symbols

class World:
    """Original image (base, bytes, lazily materialised ranges) plus symbol tables."""

    def __init__(self, base: int, image: bytes, symbols: list, lazy_ranges=(), text_range=None,
                 writable=None):
        self.base, self.image = base, image
        self.size = (len(image) + PAGE - 1) & ~(PAGE - 1)
        self.lazy_ranges = list(lazy_ranges)        # (lo, hi) page-aligned, materialised per trial
        self.text_range = text_range or (base, base + len(image))
        # image ranges the program may write (.data/.bss): only values read from these (or from
        # lazy heap pages) are mutated or replaced by trials; read-only data (jump tables, constant
        # pools) has a different address in the candidate and must stay pristine for both.
        if writable is None:
            writable = [r for r in ((base, self.text_range[0]), (self.text_range[1], base + self.size)) if r[1] > r[0]]
        self.writable = list(writable)
        self.by_name = {}
        self.func_size = {}
        for name, sec, addr, size in symbols:
            self.by_name.setdefault(name, addr)
            if sec == ".text" and size:
                self.func_size.setdefault(addr, size)
        self.sorted_syms = sorted((addr, name) for name, sec, addr, size in symbols
                                  if not name.startswith("$"))
        self.sym_addrs = [a for a, _ in self.sorted_syms]
        self.helpers = []
        self.vmx_helpers = []
        for name, sec, addr, size in symbols:
            if sec == ".text" and size and name.startswith(HELPER_PREFIXES) and not re.search(r"_\d+$", name):
                self.helpers.append((addr, addr + size))
            if sec == ".text" and size and name.startswith(VMX_HELPERS):
                self.vmx_helpers.append((addr, addr + size))
        self.libc = {self.by_name[n]: n for n in LIBC if n in self.by_name}
        self.analysis = Analysis(self.code_of, self.in_helper)
        self._callsites = None

    def code_of(self, addr):
        size = self.func_size.get(addr)
        if not size or not (self.base <= addr < self.base + len(self.image)):
            return None
        return self.image[addr - self.base: addr - self.base + size]

    def label(self, addr):
        i = bisect.bisect_right(self.sym_addrs, addr) - 1
        if i < 0:
            return f"{addr:08X}"
        a, n = self.sorted_syms[i]
        return n if a == addr else f"{n}+{addr - a:#x}"

    def in_helper(self, addr):
        return any(lo <= addr < hi for lo, hi in self.helpers)

    def callsites(self):
        """target -> [call-site address] for every `bl` in the text range (cached)."""
        if self._callsites is None:
            lo, hi = self.text_range
            key = hashlib.sha256(self.image[lo - self.base: hi - self.base]).hexdigest()[:16]
            cache = ROOT / "work" / "eq1" / f"callsites-{key}.pkl"
            if cache.is_file():
                self._callsites = pickle.loads(cache.read_bytes())
            else:
                out = {}
                n = (hi - lo) // 4
                words = struct.unpack(f">{n}I", self.image[lo - self.base: lo - self.base + 4 * n])
                for i, w in enumerate(words):
                    if (w & 0xFC000003) == 0x48000001:
                        t = (lo + 4 * i + sext(w & 0x03FFFFFC, 26)) & 0xFFFFFFFF
                        out.setdefault(t, []).append(lo + 4 * i)
                self._callsites = out
                try:
                    if len(self.image) <= 0x100000:
                        raise OSError("synthetic image: no cache")
                    cache.parent.mkdir(parents=True, exist_ok=True)
                    cache.write_bytes(pickle.dumps(out))
                except OSError:
                    pass
        return self._callsites

    def callers_reading(self, addr, regs):
        """Subset of regs that some direct caller reads after `bl addr` without writing first
        (an LTCG caller relying on the callee leaving a volatile register alone)."""
        found = set()
        for site in self.callsites().get(addr, [])[:200]:
            pending = set(regs) - found
            pc = site + 4
            for _ in range(40):
                if not pending:
                    break
                off = pc - self.base
                if not (0 <= off < len(self.image) - 4):
                    break
                ins = decode(struct.unpack_from(">I", self.image, off)[0], pc)
                hit = pending & ins.reads
                found |= hit
                pending -= hit | ins.writes
                if ins.kind in ("bl", "b", "blr", "bctr", "bctrl", "unknown"):
                    break
                pc += 4
        return found

    def return_usage(self, addr):
        """(#call sites, uses r3, uses f1): does any direct caller read r3 / f1 after the call?"""
        sites = self.callsites().get(addr, [])
        use = {3: False, 33: False}
        weak = {3: False, 33: False}
        for site in sites[:200]:
            for reg in (3, 33):
                if use[reg]:
                    continue
                pc = site + 4
                for _ in range(40):
                    off = pc - self.base
                    if not (0 <= off < len(self.image) - 4):
                        break
                    ins = decode(struct.unpack_from(">I", self.image, off)[0], pc)
                    if ins.kind == "bl":
                        li = self.analysis.live_in(ins.target)
                        if li is not None and reg in li:
                            use[reg] = True
                        break
                    if reg in ins.reads:
                        use[reg] = True
                        break
                    if ins.kind == "blr":
                        weak[reg] = True
                        break
                    if reg in ins.writes or ins.kind in ("b", "bctr", "bctrl", "unknown"):
                        break
                    pc += 4
        return len(sites), use[3], use[33], weak[3], weak[33]


_WORLD = None
sys.setrecursionlimit(20000)


def load_symbols_merged():
    from xcoff import load_symbols, matching_dir, SYMBOLS_TXT
    out = []
    md = matching_dir()
    if md and (md / "analysis" / "symbols.txt").is_file():
        out += load_symbols(md / "analysis" / "symbols.txt")
    out += load_symbols(SYMBOLS_TXT)
    return out


def load_world(dll: Path = DLL) -> World:
    global _WORLD
    if _WORLD is not None:
        return _WORLD
    d = dll.read_bytes()
    pe = struct.unpack_from("<I", d, 0x3C)[0]
    nsec, optsz = struct.unpack_from("<H", d, pe + 6)[0], struct.unpack_from("<H", d, pe + 20)[0]
    opt = pe + 24
    base = struct.unpack_from("<I", d, opt + 28)[0]
    size_img = struct.unpack_from("<I", d, opt + 56)[0]
    img = bytearray(size_img)
    lazy, text, writable = [], None, []
    for i in range(nsec):
        o = opt + optsz + i * 40
        name, vs, va, rs, rp = struct.unpack_from("<8sIIII", d, o)
        chars = struct.unpack_from("<I", d, o + 36)[0]
        name = name.rstrip(b"\0").decode("latin-1")
        n = min(vs, rs)
        img[va: va + n] = d[rp: rp + n]
        if name == ".text":
            text = (base + va, base + va + vs)
        if chars & 0x80000000 and name != ".reloc":
            writable.append((base + va, base + va + max(vs, rs)))
        if chars & 0x80000000 and vs > rs and name != ".reloc":
            lo = (base + va + rs + PAGE - 1) & ~(PAGE - 1)
            hi = (base + va + vs) & ~(PAGE - 1)
            if hi > lo:
                lazy.append((lo, hi))     # uninitialised data: seeded per trial
    _WORLD = World(base, bytes(img), load_symbols_merged(), lazy, text, writable)
    return _WORLD


# ---------------------------------------------------------------------------
# Candidate object: COFF reader and linker

def read_obj(path):
    data = Path(path).read_bytes()
    _m, nsec, _t, symoff, nsym, optsz, _c = struct.unpack_from("<HHIIIHH", data, 0)
    strtab = symoff + nsym * 18

    def name_of(raw):
        if raw[:4] == b"\0\0\0\0":
            off = struct.unpack_from("<I", raw, 4)[0]
            return data[strtab + off: data.index(b"\0", strtab + off)].decode("latin-1")
        return raw.rstrip(b"\0").decode("latin-1")

    syms, i = {}, 0
    while i < nsym:
        raw = data[symoff + i * 18: symoff + i * 18 + 18]
        value, sec, typ, storage, aux = struct.unpack_from("<IhHBB", raw, 8)
        syms[i] = (name_of(raw[:8]), value, sec, storage, typ)
        i += 1 + aux
    sections = []
    for k in range(nsec):
        raw, _vs, _va, size, ptr, relptr, _lp, nrel, _nl, chars = struct.unpack_from("<8sIIIIIIHHI", data, 20 + optsz + k * 40)
        if raw.startswith(b"/"):
            off = int(raw[1:].rstrip(b"\0"))
            name = data[strtab + off: data.index(b"\0", strtab + off)].decode("latin-1")
        else:
            name = raw.rstrip(b"\0").decode("latin-1")
        first = 0
        if chars & 0x01000000 and nrel == 0xFFFF:
            nrel = struct.unpack_from("<I", data, relptr)[0]
            first = 1
        rel = [struct.unpack_from("<IIH", data, relptr + r * 10) for r in range(first, nrel)]
        sections.append({"name": name, "data": bytearray(data[ptr: ptr + size]) if ptr else bytearray(size),
                         "chars": chars, "relocs": rel})
    return sections, syms


def target_relocs(world, addr):
    """[(offset, kind, symbol)] of the original function at addr from the matching split, or None."""
    try:
        import fn_asm
        from xcoff import load_symbols
        name = next((n for n, sec, a, _ in load_symbols() if a == addr and sec == ".text"), None)
        if name is None:
            return None
        _p, _a, _code, relocs = fn_asm.find_function(name)
        return [(r.offset, r.kind, r.symbol) for r in relocs]
    except (SystemExit, Exception):
        return None


def relocation_hints(sections, syms, world, targets):
    """Names the candidate uses for symbols that integration would rename (placeholders and
    statics standing in for the original's data): when a candidate function has exactly the
    original's relocation layout, map each such name to the address the original refers to."""
    from xcoff import demangle_base
    hints = {}
    for idx, (name, value, sec, storage, typ) in syms.items():
        key = name if name in targets else demangle_base(name)
        if key not in targets or sec <= 0 or storage != 2:
            continue
        s = sections[sec - 1]
        later = sorted(v for (n2, v, s2, st2, _t) in syms.values()
                       if s2 == sec and v > value and st2 in (2, 3) and not n2.startswith((".", "$")))
        end = later[0] if later else len(s["data"])
        cand = sorted((off - value, kind, syms[si][0]) for off, si, kind in s["relocs"]
                      if value <= off < end and kind not in (0x12, 0xA, 0xB, 0x13, 0x16, 0x0))
        tgt = target_relocs(world, targets[key])
        if tgt is None:
            continue
        tgt = sorted(t for t in tgt if t[1] not in (0x12, 0xA, 0xB, 0x13, 0x16, 0x0))
        if [c[:2] for c in cand] != [t[:2] for t in tgt]:
            continue
        for (_o, _k, cs), (_o2, _k2, ts) in zip(cand, tgt):
            if cs in world.by_name or cs.startswith(("$", ".")) or cs == ts:
                continue
            a = world.by_name.get(ts)
            if a is None:
                m = re.match(r"(?:fn|lbl|jumptable)_([0-9A-Fa-f]{8})$", ts)
                a = int(m.group(1), 16) if m else None
            if a is not None:
                hints.setdefault(cs, a)
    return hints


SKIP_SECTIONS = (".debug", ".drectve", ".pdata", ".xdata", ".XBLD", ".sxdata")


class Linked:
    """A candidate object placed at CAND_BASE with relocations applied."""

    def __init__(self, obj_path, world: World, base=CAND_BASE, targets=None):
        sections, syms = read_obj(obj_path)
        hints = relocation_hints(sections, syms, world, targets or {})
        self.base = base
        self.sec_addr = {}
        addr = base
        for k, s in enumerate(sections, 1):
            if s["name"].startswith(SKIP_SECTIONS) or s["chars"] & 0x800 or not s["chars"] & 0xE0:
                continue
            align = 1 << max(((s["chars"] >> 20) & 0xF) - 1, 4)
            addr = (addr + align - 1) & ~(align - 1)
            self.sec_addr[k] = addr
            addr += len(s["data"])
        self.size = (addr - base + PAGE - 1) & ~(PAGE - 1) or PAGE
        self.mem = bytearray(self.size)
        self.text_ranges = []
        self.functions = {}          # name -> (addr, size, section)
        self.unresolved = {}         # section index -> set(names)
        self.unsupported = {}
        unres_addr = {}

        def resolve(idx):
            name, value, sec, storage, _ = syms[idx]
            if name in hints:
                return hints[name]
            if sec > 0:
                if not name.startswith((".", "$", "?")) and name in world.by_name:
                    return world.by_name[name]        # a real symbol: use the image's copy
                return self.sec_addr.get(sec, 0) + value
            if name in world.by_name:
                return world.by_name[name]
            m = re.match(r"(?:fn|lbl|jumptable|sub)_([0-9A-Fa-f]{8})$", name) or re.search(r"_([0-9A-F]{8})$", name)
            if m:
                a = int(m.group(1), 16)
                if world.base <= a < world.base + len(world.image):
                    return a
            return None

        for k, s in enumerate(sections, 1):
            if k not in self.sec_addr:
                continue
            sa, buf = self.sec_addr[k], s["data"]
            rel = s["relocs"]
            for r, (off, idx, kind) in enumerate(rel):
                if kind in (0x0, 0x12, 0xA, 0xB, 0x13, 0x16):     # absolute, pair, debug-only
                    continue
                S = resolve(idx)
                if S is None:
                    nm = syms[idx][0]
                    self.unresolved.setdefault(k, set()).add(nm)
                    S = unres_addr.setdefault(nm, UNRESOLVED_BASE + 16 * len(unres_addr))
                P_ = sa + off
                if kind == 0x2:                                   # ADDR32
                    v = struct.unpack_from(">I", buf, off)[0]
                    struct.pack_into(">I", buf, off, (S + v) & 0xFFFFFFFF)
                elif kind == 0x6:                                 # REL24
                    w = struct.unpack_from(">I", buf, off)[0]
                    addend = sext(w & 0x03FFFFFC, 26) + off
                    disp = S + addend - P_
                    if not -0x2000000 <= disp < 0x2000000:
                        self.unsupported.setdefault(k, set()).add("branch out of range")
                    disp &= 0x03FFFFFC
                    struct.pack_into(">I", buf, off, (w & ~0x03FFFFFC) | disp)
                elif kind == 0x7:                                 # REL14
                    w = struct.unpack_from(">I", buf, off)[0]
                    addend = sext(w & 0xFFFC, 16) + off
                    disp = (S + addend - P_) & 0xFFFC
                    struct.pack_into(">I", buf, off, (w & ~0xFFFC) | disp)
                elif kind == 0x10:                                # REFHI (+ PAIR displacement)
                    w = struct.unpack_from(">I", buf, off)[0]
                    lo = 0
                    if r + 1 < len(rel) and rel[r + 1][2] == 0x12:
                        lo = sext(rel[r + 1][1], 16)
                    t = (S + ((w & 0xFFFF) << 16) + lo) & 0xFFFFFFFF
                    struct.pack_into(">I", buf, off, (w & 0xFFFF0000) | (((t + 0x8000) >> 16) & 0xFFFF))
                elif kind == 0x11:                                # REFLO
                    w = struct.unpack_from(">I", buf, off)[0]
                    t = (S + sext(w & 0xFFFF, 16)) & 0xFFFFFFFF
                    struct.pack_into(">I", buf, off, (w & 0xFFFF0000) | (t & 0xFFFF))
                elif kind == 0x4:                                 # ADDR16
                    h = struct.unpack_from(">H", buf, off)[0]
                    struct.pack_into(">H", buf, off, (S + h) & 0xFFFF)
                else:
                    self.unsupported.setdefault(k, set()).add(f"reloc kind {kind:#x}")
            self.mem[sa - base: sa - base + len(buf)] = buf
            if s["chars"] & 0x20:
                self.text_ranges.append((sa, sa + len(buf), k))
        for idx, (name, value, sec, storage, typ) in syms.items():
            if sec in self.sec_addr and storage in (2, 3) and sections[sec - 1]["chars"] & 0x20 \
                    and not name.startswith((".", "$")) and (value != 0 or storage == 2 or typ == 0x20):
                sa = self.sec_addr[sec]
                later = sorted(v for (n2, v, s2, st2, _t) in syms.values()
                               if s2 == sec and v > value and st2 in (2, 3) and not n2.startswith((".", "$")))
                end = later[0] if later else len(sections[sec - 1]["data"])
                self.functions[name] = (sa + value, end - value, sec)
        self.pristine = bytes(self.mem)

    def function(self, name):
        from xcoff import demangle_base
        if name in self.functions:
            return self.functions[name]
        for n, v in self.functions.items():
            if demangle_base(n) == name:
                return v
        return None


# ---------------------------------------------------------------------------
# Value generators (all deterministic in the seed)

FLOAT_WORDS = [0x3F800000, 0x3F000000, 0xC0000000, 0x42C80000, 0xBF800000, 0x3DCCCCCD, 0x447A0000]


def page_words(seed, page, consts):
    r = random.Random((seed << 40) ^ page)
    rnd = r.random
    mode = rnd()
    if mode < 0.12:                      # raw random bytes
        return r.randbytes(PAGE)
    if mode < 0.22:                      # text: printable ASCII with some NULs and newlines
        alphabet = b"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 _-.,:;/<>=&#%\"'\n\0"
        return bytes(r.choice(alphabet) for _ in range(PAGE))
    if mode < 0.30:                      # bytes and halfwords near the code's comparison constants
        pool = sorted({c & 0xFF for c in consts} | {0, 1, 0xFF}) if consts else [0, 1, 0xFF]
        return bytes(r.choice(pool) if rnd() < 0.7 else r.getrandbits(8) for _ in range(PAGE))
    out = []
    for _ in range(PAGE // 4):
        x = rnd()
        if x < 0.30:
            out.append(RANDPTR_LO + (r.getrandbits(26) << 2) % (HEAP_HI - RANDPTR_LO - 0x10000))
        elif x < 0.52:
            out.append(0)
        elif x < 0.67:
            out.append(r.randint(1, 15))
        elif x < 0.75:
            out.append(r.choice(consts) & 0xFFFFFFFF if consts else r.randint(16, 64))
        elif x < 0.80:
            out.append(0xFFFFFFFF)
        elif x < 0.85:
            out.append(r.choice(FLOAT_WORDS))
        else:
            out.append(r.getrandbits(32))
    return struct.pack(f">{PAGE // 4}I", *out)


def int_value(r, consts, argi=None):
    x = r.random()
    if argi is not None and x < 0.55:
        return ARG_BASE + argi * ARG_STRIDE + ARG_OFF
    if argi is None and x < 0.35:
        return RANDPTR_LO + (r.getrandbits(26) << 2) % (HEAP_HI - RANDPTR_LO - 0x10000)
    x = r.random()
    if x < 0.25:
        return 0
    if x < 0.45:
        return r.randint(1, 15)
    if x < 0.55:
        return r.randint(16, 64)
    if x < 0.75 and consts:
        return r.choice(consts) & 0xFFFFFFFF
    if x < 0.85:
        return 0xFFFFFFFFFFFFFFFF
    return r.getrandbits(32)


SPECIAL_DOUBLES = [0.0, -0.0, 1.0, -1.0, 0.5, 2.0, float("nan"), float("inf"), float("-inf"), 1e30, -1e30, 1e-30, 100.0]


def float_bits(r):
    x = r.random()
    if x < 0.35:
        v = r.choice(SPECIAL_DOUBLES)
    elif x < 0.55:
        v = r.random()
    elif x < 0.8:
        v = r.uniform(-1000.0, 1000.0)
    else:
        v = float(r.randint(-20, 20))
    v = struct.unpack(">f", struct.pack(">f", v))[0] if not math.isnan(v) else v
    return struct.unpack(">Q", struct.pack(">d", v))[0]


def poison(reg, k):
    if reg >= 32:
        return 0x7FF4BAD000000000 | (k << 8) | reg
    return POISON_TAG | ((k & 0x3FF) << 6) | reg


def is_poison(reg, v):
    if reg >= 32:
        return (v & 0xFFFFFFFF00000000) == 0x7FF4BAD000000000
    return (v & 0xFFF00000) == POISON_TAG and (v & 0x3F) == reg and v >> 32 == 0


# ---------------------------------------------------------------------------
# The machine

class Fault(Exception):
    pass


class Machine:
    def __init__(self, world: World):
        if not HAVE_UNICORN:
            raise RuntimeError("unicorn is not installed (pip install unicorn)")
        self.w = world
        uc = self.uc = Uc(UC_ARCH_PPC, UC_MODE_PPC64 | UC_MODE_BIG_ENDIAN)
        uc.ctl_set_tlb_mode(UC_TLB_VIRTUAL)      # the POWER10 MMU model faults otherwise
        uc.reg_write(P.UC_PPC_REG_MSR, MSR)
        self.static = []                          # (lo, hi, ctypes buffer, pristine bytes or None, observable)
        self.img_buf = (ctypes.c_ubyte * world.size)()
        ctypes.memmove(self.img_buf, world.image, len(world.image))
        pos = world.base
        for lo, hi in sorted(world.lazy_ranges) + [(world.base + world.size, None)]:
            if lo > pos:
                uc.mem_map_ptr(pos, lo - pos, UC_PROT_ALL, ctypes.addressof(self.img_buf) + pos - world.base)
            if hi is None:
                break
            pos = hi
        self.static.append((world.base, world.base + world.size, self.img_buf, world.image, True))
        self.stack_buf = (ctypes.c_ubyte * (STACK_HI - STACK_LO))()
        uc.mem_map_ptr(STACK_LO, STACK_HI - STACK_LO, UC_PROT_ALL, ctypes.addressof(self.stack_buf))
        self.static.append((STACK_LO, STACK_HI, self.stack_buf, None, False))
        self.ret_buf = (ctypes.c_ubyte * PAGE)()
        uc.mem_map_ptr(RET_MAGIC, PAGE, UC_PROT_ALL, ctypes.addressof(self.ret_buf))
        self.static.append((RET_MAGIC, RET_MAGIC + PAGE, self.ret_buf, None, False))
        self.cand = None
        self.cand_buf = None
        self.pages = {}            # lazily materialised page -> (buffer, pristine)
        self.aliases = []
        self.touched = set()
        self.special = {}          # address -> kind for per-instruction hooks
        self.special_hooks = []
        uc.hook_add(UC_HOOK_BLOCK, self._on_block)
        uc.hook_add(UC_HOOK_MEM_UNMAPPED, self._on_unmapped)
        uc.hook_add(UC_HOOK_MEM_WRITE, self._on_write)
        uc.hook_add(UC_HOOK_INTR, self._on_intr)
        self.lazy = list(world.lazy_ranges) + [(HEAP_LO, HEAP_HI)]
        self.ov_bytes, self.mem_ov, self.ret_ov, self.trace = {}, {}, {}, None
        self.entry, self.last = None, None

    # -- candidate region
    def load_candidate(self, linked: Linked | None):
        uc = self.uc
        if self.cand is not None:
            uc.mem_unmap(self.cand.base, self.cand.size)
            self.static = [s for s in self.static if s[0] != self.cand.base]
        self.cand = linked
        if linked is not None:
            self.cand_buf = (ctypes.c_ubyte * linked.size)()
            ctypes.memmove(self.cand_buf, linked.pristine, linked.size)
            uc.mem_map_ptr(linked.base, linked.size, UC_PROT_ALL, ctypes.addressof(self.cand_buf))
            self.static.append((linked.base, linked.base + linked.size, self.cand_buf, linked.pristine, True))

    def set_special(self, addrs: dict):
        for h in self.special_hooks:
            self.uc.hook_del(h)
        self.special_hooks = []
        self.special = dict(addrs)
        for a in addrs:
            self.special_hooks.append(self.uc.hook_add(UC_HOOK_CODE, self._on_special, begin=a, end=a + 3))

    # -- memory helpers
    def _region(self, a):
        pg = a & ~(PAGE - 1)
        ent = self.pages.get(pg)
        if ent is not None:
            return ent[0], a - pg, ent[1], True
        if self._is_lazy(a):
            return None
        for lo, hi, buf, pristine, obs in self.static:
            if lo <= a < hi:
                return buf, a - lo, pristine, obs
        return None

    def _is_lazy(self, a):
        return any(lo <= a < hi for lo, hi in self.lazy)

    def _materialise(self, pg):
        buf = (ctypes.c_ubyte * PAGE)()
        data = page_words(self.seed, pg, self.consts)
        if self.mem_ov:
            arr = bytearray(data)
            for a, v in self.mem_ov.items():
                if pg <= a and a + len(v) <= pg + PAGE:
                    arr[a - pg: a - pg + len(v)] = v
            data = bytes(arr)
        ctypes.memmove(buf, data, PAGE)
        self.uc.mem_map_ptr(pg, PAGE, UC_PROT_ALL, ctypes.addressof(buf))
        self.pages[pg] = (buf, data)
        return buf

    def _host(self, a, create=True):
        """Host address of the byte at 32-bit address a (materialising lazy pages)."""
        reg = self._region(a)
        if reg is None:
            if not (create and self._is_lazy(a)):
                return None
            self._materialise(a & ~(PAGE - 1))
            reg = self._region(a)
        buf, off, _, _ = reg
        return ctypes.addressof(buf) + off

    def read(self, a, n):
        out = bytearray()
        while n > 0:
            a &= 0xFFFFFFFF
            k = min(n, PAGE - (a & (PAGE - 1)))
            h = self._host(a)
            if h is None:
                raise Fault(a)
            out += ctypes.string_at(h, k)
            a += k
            n -= k
        return bytes(out)

    def write(self, a, data):
        i = 0
        while i < len(data):
            a &= 0xFFFFFFFF
            k = min(len(data) - i, PAGE - (a & (PAGE - 1)))
            h = self._host(a)
            if h is None:
                raise Fault(a)
            ctypes.memmove(h, bytes(data[i:i + k]), k)
            if not (STACK_LO <= a < STACK_HI):
                self.touched.update(range(a, a + k))
            a += k
            i += k

    def delta(self):
        """{address: byte} for observable bytes whose value differs from the initial state."""
        out = {}
        for a in self.touched:
            reg = self._region(a)
            if reg is None:
                continue
            buf, off, pristine, obs = reg
            if obs and pristine is not None and buf[off] != self.ov_bytes.get(a, pristine[off]):
                out[a] = buf[off]
        return out

    # -- hooks
    def _on_unmapped(self, uc, access, address, size, value, ud):
        a = address & 0xFFFFFFFF
        pg = a & ~(PAGE - 1)
        try:
            if address >> 32:
                h = self._host(pg)
                if h is None:
                    self.fault = (access, a)
                    return False
                hp = address & ~(PAGE - 1)
                uc.mem_map_ptr(hp, PAGE, UC_PROT_ALL, h)
                self.aliases.append(hp)
                return True
            if self._is_lazy(a) and pg not in self.pages:
                self._materialise(pg)
                return True
        except UcError:
            pass
        self.fault = (access, a)
        return False

    def _on_read(self, uc, access, address, size, value, ud):
        a = address & 0xFFFFFFFF
        if size in (1, 2, 4) and (a & (PAGE - 1)) + size <= PAGE and \
                ((HEAP_LO <= a < HEAP_HI) or any(lo <= a < hi for lo, hi in self.w.writable)):
            h = self._host(a)
            if h is not None:
                self.trace.append(("mem", a, int.from_bytes(ctypes.string_at(h, size), "big"), size))

    def _on_write(self, uc, access, address, size, value, ud):
        a = address & 0xFFFFFFFF
        if not (STACK_LO <= a < STACK_HI):
            self.touched.update(range(a, a + size))
        else:
            r = range(a, a + size)
            self.stack_touched.update(r)
            self.stack_since.update(r)

    def _on_intr(self, uc, intno, ud):
        self.outcome = ("trap", intno)
        self.trap_pc = uc.reg_read(P.UC_PPC_REG_PC) & 0xFFFFFFFF
        uc.emu_stop()

    def _on_special(self, uc, address, size, ud):
        a = address & 0xFFFFFFFF
        kind = self.special.get(a)
        if kind is None:
            return
        w = struct.unpack(">I", self.read(a, 4))[0]
        if kind == "mftb":
            self.tb += 1000
            uc.reg_write(P.UC_PPC_REG_0 + ((w >> 21) & 31), self.tb)
        elif kind == "dcbz":
            ra, rb = (w >> 16) & 31, (w >> 11) & 31
            ea = ((uc.reg_read(P.UC_PPC_REG_0 + ra) if ra else 0) + uc.reg_read(P.UC_PPC_REG_0 + rb)) & 0xFFFFFFFF
            line = 128 if (w >> 21) & 1 else 32       # Xenon: dcbz = 32 bytes, dcbz128 = 128 bytes
            try:
                self.write(ea & ~(line - 1), bytes(line))
            except Fault as e:
                self.fault = ("dcbz", e.args[0])
                uc.emu_stop()
                return
        uc.reg_write(P.UC_PPC_REG_PC, a + 4)

    def _on_block(self, uc, address, size, ud):
        a = address & 0xFFFFFFFF
        if a == self.entry:
            if self.last is not None:
                la, ls = self.last
                try:
                    w = struct.unpack(">I", self.read(la + ls - 4, 4))[0]
                except Fault:
                    w = 0
                if (w & 0xFC000001) == 0x48000001:    # reached by `bl` from the function: recursion
                    self.last = None
                    self._intercept(uc, a)
                    return
        for lo, hi in self.local:
            if lo <= a < hi:
                self.last = (a, size)
                if self.cov is not None:
                    self.cov.add((a, size))
                self.icount += size >> 2
                return
        if a == RET_MAGIC or self.w.in_helper(a):
            return
        if a in self.w.libc:
            self._libc(uc, self.w.libc[a])
            return
        self._intercept(uc, a)

    def _libc(self, uc, name):
        r = [uc.reg_read(P.UC_PPC_REG_0 + i) & 0xFFFFFFFF for i in (3, 4, 5)]
        try:
            if r[2] > 0x100000:
                raise Fault(r[2])
            if name in ("memcpy", "memmove"):
                self.write(r[0], self.read(r[1], r[2]))
            elif name == "memset":
                self.write(r[0], bytes([r[1] & 0xFF]) * r[2])
        except Fault as e:
            self.fault = (name, e.args[0])
            uc.emu_stop()
            return
        defs = self.w.analysis.defs_of(self.w.by_name[name])
        k = len(self.events)
        for reg in VOLATILE & defs:
            if reg not in (3,):
                self._set(reg, poison(reg, k))
        uc.reg_write(P.UC_PPC_REG_PC, uc.reg_read(P.UC_PPC_REG_LR))

    def _get(self, reg):
        uc = self.uc
        return uc.reg_read(P.UC_PPC_REG_FPR0 + reg - 32) if reg >= 32 else uc.reg_read(P.UC_PPC_REG_0 + reg)

    def _set(self, reg, v):
        uc = self.uc
        if reg >= 32:
            uc.reg_write(P.UC_PPC_REG_FPR0 + reg - 32, v)
        else:
            uc.reg_write(P.UC_PPC_REG_0 + reg, v)

    def _site_args(self, uc):
        """Argument registers of an indirect/unknown call, from the calling code itself: r3 plus
        every r4-r10/f1-f13 whose last write in the straight-line code before the call site (up to
        the previous call or control transfer) is not read again before the call (registers that
        are read again are address temporaries such as the vtable pointer). None when the call
        site is unknown (tail call)."""
        site = (uc.reg_read(P.UC_PPC_REG_LR) & 0xFFFFFFFF) - 4
        if not any(lo <= site < hi for lo, hi in self.local):
            return None
        out, decided, read_after = {3}, set(), set()
        pc = site - 4
        for _ in range(32):
            if not any(lo <= pc < hi for lo, hi in self.local):
                break
            try:
                ins = decode(struct.unpack(">I", self.read(pc, 4))[0], pc)
            except Fault:
                break
            if ins.kind in ("bl", "bctrl", "b", "blr", "bctr", "bcctr", "bclr", "bc"):
                break
            for reg in ins.writes & ARGS:
                if reg not in decided:
                    decided.add(reg)
                    if reg not in read_after:     # read again before the call: a temporary
                        out.add(reg)
            read_after |= ins.reads
            pc -= 4
        return frozenset(out)

    def _intercept(self, uc, a):
        k = len(self.events)
        image_fn = a in self.w.func_size
        args = self.w.analysis.live_in(a) if image_fn else None
        if args is None:
            args = self._site_args(uc)
        vals = tuple(self._get(r) for r in GPR_ARGS + FPR_ARGS)
        frame = {}
        for j, reg in enumerate(GPR_ARGS):
            v = vals[j] & 0xFFFFFFFF
            if STACK_LO <= v < STACK_TOP:
                # pointer into the function's own frame: compare the object, not its address
                frame[reg] = tuple(self.stack_buf[x - STACK_LO] if x in self.stack_touched else None
                                   for x in range(v, min(v + STACK_ARG_WINDOW, STACK_HI)))
        sargs = {}
        if args is None or 10 in args:
            # arguments 9+ are passed in the caller's frame at r1+0x54, 8 bytes per slot
            sp = uc.reg_read(P.UC_PPC_REG_1) & 0xFFFFFFFF
            for j in range(8):
                lo = sp + 0x54 + 8 * j
                if any(x in self.stack_since for x in range(lo, lo + 8)) and STACK_LO <= lo < STACK_HI - 8:
                    sargs[j] = bytes(self.stack_buf[lo - STACK_LO: lo - STACK_LO + 8])
        self.stack_since = set()
        self.events.append((a, vals, args, self.delta(), frame, sargs))
        if len(self.events) > 400:
            self.outcome = ("limit", "calls")
            uc.emu_stop()
            return
        defs = self.w.analysis.defs_of(a) if image_fn else VOLATILE
        r = random.Random((self.seed << 20) ^ (k << 40) ^ a)
        for reg in VOLATILE & defs:
            if reg == 3:
                rv = self.ret_ov.get((k, a))
                if rv is None:
                    rv = int_value(r, self.consts)
                self._set(3, rv)
                if self.trace is not None:
                    self.trace.append(("ret", (k, a), rv & 0xFFFFFFFF, 4))
            elif reg == 33:
                self._set(33, float_bits(r))
            else:
                self._set(reg, poison(reg, k + 1))
        uc.reg_write(P.UC_PPC_REG_PC, uc.reg_read(P.UC_PPC_REG_LR))

    # -- one run
    def run(self, entry, local, state, seed, consts, limit, coverage=None, track=False):
        uc = self.uc
        self.seed, self.consts, self.local, self.cov = seed, consts, local, coverage
        self.events, self.outcome, self.fault, self.icount, self.tb = [], None, None, 0, 0x1000
        self.entry, self.last = entry, None
        # reset memory
        for pg, (buf, data) in self.pages.items():
            uc.mem_unmap(pg, PAGE)
        self.pages = {}
        for hp in self.aliases:
            uc.mem_unmap(hp, PAGE)
        self.aliases = []
        for a in self.touched:
            reg = self._region(a)
            if reg is not None and reg[2] is not None:
                reg[0][reg[1]] = reg[2][reg[1]]
        for a in self.ov_bytes:
            reg = self._region(a)
            if reg is not None and reg[2] is not None:
                reg[0][reg[1]] = reg[2][reg[1]]
        self.touched = set()
        self.stack_touched = set()
        self.stack_since = set()
        self.ov_bytes = {}
        self.mem_ov = state.get("mem_ov") or {}
        self.ret_ov = state.get("ret_ov") or {}
        for a, v in self.mem_ov.items():
            if not self._is_lazy(a):
                reg = self._region(a)
                if reg is None or reg[2] is None:
                    continue
                for i, byte in enumerate(v):
                    reg2 = self._region(a + i)
                    reg2[0][reg2[1]] = byte
                    self.ov_bytes[a + i] = byte
        self.trace = [] if track else None
        if track:
            self._read_hook = uc.hook_add(UC_HOOK_MEM_READ, self._on_read)
            self.trace += [("reg", r, state["regs"][r], 4) for r in GPR_ARGS + (13,)]
        ctypes.memmove(self.stack_buf, state["stack"], STACK_HI - STACK_LO)
        uc.reg_write(P.UC_PPC_REG_MSR, MSR)
        for reg, v in state["regs"].items():
            self._set(reg, v)
        uc.reg_write(P.UC_PPC_REG_LR, RET_MAGIC)
        uc.reg_write(P.UC_PPC_REG_CTR, poison(0, 0x3FF))
        uc.reg_write(P.UC_PPC_REG_CR, 0)
        uc.reg_write(P.UC_PPC_REG_XER, 0)
        uc.reg_write(P.UC_PPC_REG_FPSCR, 0)
        try:
            uc.emu_start(entry, RET_MAGIC, timeout=5_000_000, count=limit)
        except UcError as e:
            if self.outcome is None:
                self.outcome = ("fault", self.fault[1] if self.fault else str(e))
        if track:
            uc.hook_del(self._read_hook)
        pc = uc.reg_read(P.UC_PPC_REG_PC) & 0xFFFFFFFF
        if self.outcome is None:
            if self.fault:
                self.outcome = ("fault", self.fault[1])
            elif pc == RET_MAGIC:
                self.outcome = ("return",)
            else:
                self.outcome = ("limit", pc)
        res = {
            "trace": self.trace,
            "fault_addr": self.fault[1] if self.fault and isinstance(self.fault[1], int) else None,
            "outcome": self.outcome,
            "events": self.events,
            "icount": self.icount,
            "r3": uc.reg_read(P.UC_PPC_REG_3),
            "f1": uc.reg_read(P.UC_PPC_REG_FPR1),
            "delta": self.delta(),
            "nonvol": tuple(uc.reg_read(P.UC_PPC_REG_0 + i) & 0xFFFFFFFF for i in (1, 2, 13) + NONVOL_GPR)
            + tuple(uc.reg_read(P.UC_PPC_REG_FPR0 + i) for i in NONVOL_FPR),
        }
        if self.outcome[0] == "trap":
            res["trap_pc"] = self.trap_pc
        return res


# ---------------------------------------------------------------------------
# Trials and comparison

def make_state(seed, live, consts):
    r = random.Random(seed * 7919 + 17)
    regs = {}
    for reg in range(32):
        regs[reg] = poison(reg, 0)
    for i, reg in enumerate(NONVOL_GPR):
        regs[reg] = 0xC0DE0000 | reg
    regs[1] = STACK_TOP
    regs[2] = 0xC0DE0002
    regs[13] = TLS_PTR
    for reg in range(32):
        regs[32 + reg] = poison(32 + reg, 0)
    for reg in NONVOL_FPR:
        regs[32 + reg] = 0x4300DE0000000000 | reg
    argi = 0
    for reg in GPR_ARGS:
        if live is None or reg in live:
            regs[reg] = int_value(r, consts, argi=reg - 3)
    for reg in FPR_ARGS:
        if live is None or reg in live:
            regs[reg] = float_bits(r)
    fill = struct.pack(">I", 0xCDCD0000 | (seed & 0xFFFF)) * ((STACK_TOP - STACK_LO) // 4)
    rr = random.Random(seed * 31 + 5)
    above = page_words(seed, 0x7F0F0000, consts) * ((STACK_HI - STACK_TOP) // PAGE)
    above = bytearray(above)
    # linkage area / home slots stay pattern-filled; stack-passed args follow at +0x50
    return {"regs": regs, "stack": fill + bytes(above)}, rr


def ret_regs(kind):
    return {"void": (), "int": ("r3",), "int64": ("r3_64",), "float": ("f1",), "both": ("r3", "f1")}[kind]


def describe_addr(world, a):
    if HEAP_LO <= a < RANDPTR_LO:
        i, off = divmod(a - ARG_BASE, ARG_STRIDE)
        off -= ARG_OFF
        return f"arg{i}(r{3 + i}){'+' if off >= 0 else '-'}{abs(off):#x}"
    if HEAP_LO <= a < HEAP_HI:
        return f"heap:{a:08X}"
    if CAND_BASE <= a < CAND_BASE + 0x1000000:
        return f"candidate-local:{a:08X}"
    return world.label(a)


def runs_of(delta):
    """Group a byte delta into (start, bytes) runs."""
    out, cur = [], None
    for a in sorted(delta):
        if cur and a == cur[0] + len(cur[1]):
            cur[1].append(delta[a])
        else:
            cur = (a, bytearray([delta[a]]))
            out.append(cur)
    return out


def regname(r):
    return f"f{r - 32}" if r >= 32 else f"r{r}"


def compare(world, A, B, rkind, nonvol=True):
    """First observable difference between original run A and candidate run B, or None."""
    oa, ob = A["outcome"], B["outcome"]
    ea, eb = A["events"], B["events"]
    allregs = GPR_ARGS + FPR_ARGS
    for i in range(min(len(ea), len(eb))):
        ta, va, args, da, fa, sa = ea[i]
        tb, vb, _, db, fb, sb = eb[i]
        if ta != tb:
            return f"call #{i + 1}: original calls {world.label(ta)}, candidate calls {world.label(tb)}"
        if sa != sb:
            j = min(k for k in set(sa) | set(sb) if sa.get(k) != sb.get(k))
            fmt = lambda b: "unset" if b is None else b.hex()
            return (f"call #{i + 1} to {world.label(ta)}: stack argument {9 + j} differs: original "
                    f"{fmt(sa.get(j))}, candidate {fmt(sb.get(j))}")
        for j, reg in enumerate(allregs):
            x, y = va[j], vb[j]
            if reg < 32:
                x, y = x & 0xFFFFFFFF, y & 0xFFFFFFFF
            if reg in fa and reg in fb:
                if fa[reg] != fb[reg] and (args is None or reg in args):
                    return (f"call #{i + 1} to {world.label(ta)}: the stack object passed in {regname(reg)} differs "
                            f"(first {STACK_ARG_WINDOW} bytes written by the function: original "
                            f"{fmt_frame(fa[reg])}, candidate {fmt_frame(fb[reg])})")
                continue
            if x == y:
                continue
            if args is not None:
                if reg in args:
                    return (f"call #{i + 1} to {world.label(ta)}: argument {regname(reg)} original {x:#x}, "
                            f"candidate {y:#x}")
            elif not is_poison(reg, va[j]) and not is_poison(reg, vb[j]):
                return (f"call #{i + 1} to {world.label(ta)} (indirect/unknown callee): argument {regname(reg)} "
                        f"original {x:#x}, candidate {y:#x}")
        if da != db:
            return f"call #{i + 1} to {world.label(ta)}: memory before the call differs: " + delta_diff(world, da, db)
    if len(ea) != len(eb):
        if len(ea) > len(eb):
            t = ea[len(eb)][0]
            return f"original makes call #{len(eb) + 1} to {world.label(t)}, candidate does not ({len(ea)} vs {len(eb)} calls)"
        t = eb[len(ea)][0]
        return f"candidate makes extra call #{len(ea) + 1} to {world.label(t)} ({len(ea)} vs {len(eb)} calls)"
    if oa[0] != ob[0] or (oa[0] == "trap" and oa != ob):
        what = {"fault": "faults", "limit": "does not finish", "return": "returns", "trap": "traps"}
        return (f"original {what.get(oa[0], oa[0])} {fmt_outcome(world, oa)}, candidate {what.get(ob[0], ob[0])} "
                f"{fmt_outcome(world, ob)}")
    if A["delta"] != B["delta"]:
        return "final memory differs: " + delta_diff(world, A["delta"], B["delta"])
    if oa[0] == "return":
        for k in ret_regs(rkind):
            if k == "r3" and (A["r3"] & 0xFFFFFFFF) != (B["r3"] & 0xFFFFFFFF):
                return f"return value r3: original {A['r3'] & 0xFFFFFFFF:#x}, candidate {B['r3'] & 0xFFFFFFFF:#x}"
            if k == "r3_64" and A["r3"] != B["r3"]:
                return f"return value r3 (64-bit): original {A['r3']:#x}, candidate {B['r3']:#x}"
            if k == "f1" and A["f1"] != B["f1"]:
                fa = struct.unpack('>d', struct.pack('>Q', A['f1']))[0]
                fb = struct.unpack('>d', struct.pack('>Q', B['f1']))[0]
                return f"return value f1: original {fa!r} ({A['f1']:#x}), candidate {fb!r} ({B['f1']:#x})"
        if nonvol and A["nonvol"] != B["nonvol"]:
            names = ["r1", "r2", "r13"] + [f"r{i}" for i in NONVOL_GPR] + [f"f{i}" for i in NONVOL_FPR]
            bad = [names[i] for i in range(len(names)) if A["nonvol"][i] != B["nonvol"][i]]
            return "callee-saved registers not preserved by the candidate: " + ", ".join(bad)
    return None


def fmt_frame(t):
    return "[" + " ".join("--" if b is None else f"{b:02x}" for b in t) + "]"


def fmt_outcome(world, o):
    if o[0] == "fault":
        return f"at {o[1]:#x}" if isinstance(o[1], int) else str(o[1])
    if o[0] == "trap":
        return f"(exception {o[1]})"
    return ""


def delta_diff(world, da, db):
    keys = sorted(set(da) | set(db))
    bad = [k for k in keys if da.get(k) != db.get(k)]
    if not bad:
        return "?"
    first = bad[0]
    lo = first & ~3
    hexa = " ".join("--" if da.get(a) is None else f"{da[a]:02x}" for a in range(lo, lo + 8))
    hexb = " ".join("--" if db.get(a) is None else f"{db[a]:02x}" for a in range(lo, lo + 8))
    return (f"{len(bad)} byte(s), first at {describe_addr(world, first)}; bytes from {describe_addr(world, lo)} "
            f"(-- = unchanged): original [{hexa}] candidate [{hexb}]")


def code_consts(func: Func):
    out = {0, 1}
    for _, ins in func.code_words():
        w = ins.word
        op = w >> 26
        if op in (10, 11):
            v = w & 0xFFFF
            v = sext(v, 16) if op == 11 else v
            out.update({v - 1, v, v + 1})
    # switch case values: a jump table of n entries indexed by (x - bias) is reached by x in
    # bias .. bias+n-1 (the bias is the `addi rX, rY, -bias` shortly before the bctr)
    for i, tgts in func.tables.items():
        bias = 0
        for ins in reversed(func.insns[max(0, i - 12):i]):
            if ins.word >> 26 == 14 and sext(ins.word & 0xFFFF, 16) < 0 and (ins.word >> 16) & 31:
                bias = -sext(ins.word & 0xFFFF, 16)
                break
        out.update(bias + k for k in range(len(tgts)))
    return sorted(out)


class Result(dict):
    pass


def check_one(machine: Machine, world: World, linked: Linked, cand_name: str, target_addr: int,
              trials=400, seed=1, min_cov=0.9, min_valid=30, time_budget=60.0, return_kind=None,
              source_text=None):
    """Compare one candidate function with the original at target_addr. Returns a Result dict."""
    res = Result(function=cand_name, address=f"0x{target_addr:08X}", checker=CHECKER_VERSION,
                 seed=seed)
    size = world.func_size.get(target_addr)
    if not size:
        return Result(res, verdict="UNCHECKED", reason="original function size unknown")
    res["size"] = size
    func = world.analysis.func(target_addr)
    fn = linked.function(cand_name)
    if fn is None:
        return Result(res, verdict="UNCHECKED", reason="candidate function not defined in object")
    c_addr, c_size, c_sec = fn
    cfunc = Func(bytes(linked.mem[c_addr - linked.base: c_addr - linked.base + c_size]), c_addr)
    if func.has_vector():
        return Result(res, verdict="UNCHECKED", reason="vmx: original uses VMX/VMX128 instructions")
    if cfunc.has_vector():
        return Result(res, verdict="UNCHECKED", reason="vmx: candidate uses VMX/VMX128 instructions")
    for _, ins in func.code_words():
        if ins.kind == "bl" and any(lo <= ins.target < hi for lo, hi in world.vmx_helpers):
            return Result(res, verdict="UNCHECKED", reason="vmx: original saves vector registers")
        if ins.kind == "unknown":
            return Result(res, verdict="UNCHECKED", reason=f"undecoded instruction {ins.word:08x} in original")
    unres = linked.unresolved.get(c_sec, set())
    for k, names in linked.unresolved.items():
        sec_chars_text = any(s == k for _, _, s in linked.text_ranges)
        if not sec_chars_text:
            unres = unres | names        # data sections are reachable from anywhere
    if unres:
        return Result(res, verdict="UNCHECKED", reason="unresolved symbol(s): " + ", ".join(sorted(unres)[:6]))
    if linked.unsupported.get(c_sec):
        return Result(res, verdict="UNCHECKED", reason="unsupported relocation: " + ", ".join(linked.unsupported[c_sec]))
    # return kind
    nsites, use_r3, use_f1, weak_r3, weak_f1 = world.return_usage(target_addr)
    if return_kind is None:
        # strongest evidence first: a caller reads r3/f1; then the candidate's declared type;
        # then a caller that returns r3/f1 untouched; a function nobody calls directly is
        # assumed to return r3
        sig = signature_return(source_text, cand_name) if source_text else None
        if use_r3 or use_f1:
            return_kind = "both" if use_r3 and use_f1 else "int" if use_r3 else "float"
            if return_kind == "int" and sig == "int64":
                return_kind = "int64"
        elif sig is not None:
            return_kind = sig
        elif weak_r3 or weak_f1:
            return_kind = "both" if weak_r3 and weak_f1 else "int" if weak_r3 else "float"
        elif not any(3 in ins.writes for _, ins in func.code_words()) and \
                not any(ins.kind in ("bl", "bctrl") or (ins.kind == "b" and not func.inside(ins.target))
                        for _, ins in func.code_words()):
            return_kind = "void"     # never writes r3 and never calls: nothing to return
        else:
            return_kind = "int"
    res["return"] = return_kind
    live = world.analysis.live_in(target_addr)
    res["args"] = sorted(regname(r) for r in live) if live is not None else "unknown"
    consts = code_consts(func)
    special = {}
    for f in (func, cfunc):
        for a, ins in f.code_words():
            if ins.kind in ("mftb", "dcbz"):
                special[a] = ins.kind
    machine.set_special(special)
    machine.load_candidate(linked)
    o_local = [(target_addr, target_addr + size)]
    c_local = [(lo, hi) for lo, hi, _ in linked.text_ranges]
    cov = set()
    valid = discarded = 0
    discard_reasons = {}
    t0 = time.time()
    first_diff = None
    last_new = 0
    blocks = func.block_addrs()
    covered = set()
    corpus = []          # (run seed, state, trace) of trials that reached new blocks
    for t in range(trials):
        s = seed * 1_000_003 + t
        if t < max(40, trials * 2 // 5) or not corpus:
            state, _ = make_state(s, live, consts)
        else:
            # coverage-guided phase: take a trial that reached new blocks and replace one value it
            # read (an argument, a loaded byte/halfword/word or a call's return value)
            mr = random.Random(s ^ 0x5EED)
            ps, pstate, ptrace = corpus[min(len(corpus) - 1, int(len(corpus) * mr.random() ** 0.5))]
            state = dict(pstate, regs=dict(pstate["regs"]), mem_ov=dict(pstate.get("mem_ov") or {}),
                         ret_ov=dict(pstate.get("ret_ov") or {}))
            for _ in range(1 + (mr.random() < 0.3)):
                kind, key, old, size = mr.choice(ptrace)
                x = mr.random()
                v = (old + mr.choice((-1, 1))) if x < 0.2 else 0 if x < 0.3 else 1 if x < 0.4 else \
                    (mr.choice(consts) if consts and x < 0.7 else int_value(mr, consts))
                v &= (1 << (8 * size)) - 1
                if kind == "reg":
                    state["regs"][key] = v
                elif kind == "mem":
                    state["mem_ov"][key] = v.to_bytes(size, "big")
                else:
                    state["ret_ov"][key] = v
            s = ps
        tb_before = len(cov)
        state, A = run_fixing(machine, world, target_addr, o_local, state, s, consts, cov)
        if A["outcome"][0] == "trap" and A["outcome"][1] == 96:
            return Result(res, verdict="UNCHECKED",
                          reason=f"illegal instruction for the emulator at {A.get('trap_pc', 0):#x} in original")
        if A["outcome"][0] in ("fault", "limit"):
            discarded += 1
            discard_reasons[A["outcome"][0]] = discard_reasons.get(A["outcome"][0], 0) + 1
            continue
        B = machine.run(c_addr, c_local, state, s, consts, max(4 * A["icount"] + 5000, 20000), None)
        if B["outcome"][0] == "trap" and B["outcome"][1] == 96:
            return Result(res, verdict="UNCHECKED",
                          reason=f"illegal instruction for the emulator at {B.get('trap_pc', 0):#x} in candidate")
        valid += 1
        if len(cov) != tb_before:
            last_new = t
            if len(corpus) < 200:
                T = machine.run(target_addr, o_local, state, s, consts, 200_000, None, track=True)
                if T["trace"]:
                    corpus.append((s, state, T["trace"]))
        diff = compare(world, A, B, return_kind)
        if diff:
            first_diff = (s, state, diff, A, B)
            break
        if time.time() - t0 > time_budget:
            break
        if t >= 60 and valid >= min_valid and t - last_new > max(150, trials // 4):
            # coverage stopped growing: stop early once every block has been seen
            covered = {b for b in blocks if any(a <= b < a + sz for a, sz in cov)}
            if len(covered) == len(blocks):
                break
    covered = {b for b in blocks if any(a <= b < a + sz for a, sz in cov)}
    res.update(trials=valid + discarded, valid=valid, discarded=discarded, discard_reasons=discard_reasons,
               blocks=len(blocks), blocks_covered=len(covered),
               coverage=round(len(covered) / len(blocks), 4) if blocks else 1.0,
               uncovered=[f"0x{b:08X}" for b in blocks if b not in covered][:20])
    if first_diff:
        s, state, diff, A, B = first_diff
        report = reduce_report(machine, world, target_addr, o_local, c_addr, c_local, s, state, live, consts,
                               return_kind, diff)
        return Result(res, verdict="DIFFERENT", reason=diff, report=report, failing_seed=s)
    # whole-program note: volatile registers the candidate writes but the original leaves alone,
    # which an LTCG-compiled caller of the original reads after the call
    cw = set()
    for _, ins in cfunc.code_words():
        cw |= ins.writes
        if ins.kind in ("bl", "bctrl") or (ins.kind == "b" and not cfunc.inside(ins.target)):
            cw |= VOLATILE
    extra = (cw - world.analysis.defs_of(target_addr)) & VOLATILE - {3, 33}
    relied = world.callers_reading(target_addr, extra) if extra else set()
    res["abi_hazard"] = sorted(regname(r) for r in relied)
    if valid < min_valid:
        return Result(res, verdict="UNCHECKED",
                      reason=f"too few valid trials ({valid}; original faulted or did not finish in {discarded})")
    if res["coverage"] < min_cov:
        return Result(res, verdict="UNCHECKED",
                      reason=f"coverage {res['coverage']:.0%} below {min_cov:.0%} ({len(covered)}/{len(blocks)} blocks)")
    return Result(res, verdict="EQUIVALENT", reason="")


def valid_ptr(world, v):
    return HEAP_LO <= v < HEAP_HI or world.base <= v < world.base + world.size or STACK_LO <= v < STACK_HI


def run_fixing(machine, world, entry, local, state, s, consts, cov, max_fix=24):
    """Run the original; when it faults on an address derived from an invalid pointer value
    (an argument, a loaded word or a call's return value), re-run with that value replaced by a
    fresh heap pointer (lazy resolution of pointer fields). Returns (final state, result)."""
    tmp = set()
    for it in range(max_fix + 1):
        tmp = set()
        A = machine.run(entry, local, state, s, consts, 200_000, tmp, track=it > 0)
        F = A["fault_addr"]
        if A["outcome"][0] != "fault" or F is None or it == max_fix:
            break
        T = A if it > 0 else machine.run(entry, local, state, s, consts, 200_000, None, track=True)
        F = T["fault_addr"]
        if F is None:
            break
        src = None
        done = set((state.get("mem_ov") or {})) | set((state.get("ret_ov") or {}))
        for ent in reversed(T["trace"]):
            v = ent[2] & 0xFFFFFFFF
            if ent[3] == 4 and -0x8000 <= F - v < 0x10000 and not valid_ptr(world, v):
                if ent[0] != "reg" and ent[1] in done:
                    continue     # already replaced: the value was stored there by the function
                src = ent
                break
        if src is None:
            break
        ptr = RANDPTR_LO + ((((s * 2654435761) ^ (it * 40503) ^ F) % ((HEAP_HI - RANDPTR_LO - 0x40000) >> 4)) << 4)
        state = dict(state, regs=dict(state["regs"]), mem_ov=dict(state.get("mem_ov") or {}),
                     ret_ov=dict(state.get("ret_ov") or {}))
        kind, key = src[0], src[1]
        if kind == "reg":
            state["regs"][key] = ptr
        elif kind == "mem":
            state["mem_ov"][key] = struct.pack(">I", ptr)
        else:
            state["ret_ov"][key] = ptr
    if cov is not None and A["outcome"][0] not in ("fault", "limit"):
        cov |= tmp
    return state, A


def reduce_report(machine, world, oaddr, olocal, caddr, clocal, s, state, live, consts, rkind, diff):
    """Simplify the failing input (each argument -> 0 / 1 / 0.0 / 1.0 while the difference persists)."""
    regs = dict(state["regs"])
    simplified = []
    for reg in sorted(live or ()):
        for v in ((0, 1) if reg < 32 else (0, 0x3FF0000000000000)):
            if regs[reg] == v:
                break
            trial = dict(state, regs={**regs, reg: v})
            A = machine.run(oaddr, olocal, trial, s, consts, 200_000, None)
            if A["outcome"][0] in ("fault", "limit"):
                continue
            B = machine.run(caddr, clocal, trial, s, consts, max(4 * A["icount"] + 5000, 20000), None)
            d = compare(world, A, B, rkind)
            if d:
                regs[reg] = v
                diff = d
                simplified.append(regname(reg))
                break
    final = dict(state, regs=regs)
    A = machine.run(oaddr, olocal, final, s, consts, 200_000, None)
    B = machine.run(caddr, clocal, final, s, consts, max(4 * A["icount"] + 5000, 20000), None)
    lines = [f"seed {s}; difference: {compare(world, A, B, rkind) or diff}"]
    args = []
    for reg in sorted(live or ()):
        v = regs[reg]
        if reg >= 32:
            args.append(f"{regname(reg)}={struct.unpack('>d', struct.pack('>Q', v))[0]!r}")
        else:
            v &= 0xFFFFFFFF
            args.append(f"{regname(reg)}={describe_addr(world, v) if HEAP_LO <= v < HEAP_HI else hex(v)}")
    lines.append("inputs: " + (", ".join(args) or "(none)") + (f"  (simplified: {', '.join(simplified)})" if simplified else ""))
    for tag, R in (("original", A), ("candidate", B)):
        calls = ", ".join(world.label(e[0]) if e[0] in world.func_size else describe_addr(world, e[0])
                          for e in R["events"][:12])
        lines.append(f"{tag}: {R['outcome'][0]}, {len(R['events'])} call(s){': ' + calls if calls else ''}; "
                     f"{len(R['delta'])} byte(s) written")
    return "\n".join(lines)


SIG_TYPES = (("void", "void"), ("float", "float"), ("double", "float"), ("ts4_u64", "int64"),
             ("ts4_s64", "int64"), ("__int64", "int64"), ("long long", "int64"))


def signature_return(text, name):
    """Return kind of the definition of `name` in C/C++ source text, or None."""
    if not text:
        return None
    for m in re.finditer(r"(?m)^([^\n;{}()#]*?)\b" + re.escape(name) + r"\s*\(", text):
        rest = text[m.end():]
        depth, i = 1, 0
        while i < len(rest) and depth:
            depth += {"(": 1, ")": -1}.get(rest[i], 0)
            i += 1
        if not rest[i:].lstrip().startswith("{"):
            continue
        decl = re.sub(r"\b(static|extern|inline|__inline|__forceinline|__declspec\(\w+\)|const|volatile|"
                      r"__cdecl|__fastcall)\b|\"C\"", "", m.group(1)).strip()
        if "*" in decl:
            return "int"
        for k, v in SIG_TYPES:
            if re.search(r"\b" + k + r"\b", decl):
                return v
        return "int"
    return None


# ---------------------------------------------------------------------------
# Driver

_MACHINE = None


def get_machine(world):
    global _MACHINE
    if _MACHINE is None:
        _MACHINE = Machine(world)
    return _MACHINE


def compile_source(source: Path, flags):
    import fn_check
    return fn_check.compile_candidate(source, flags)


def check_object(obj_path, mappings, source_text=None, **kw):
    """mappings: [(candidate name, target address)] -> [Result]."""
    world = load_world()
    machine = get_machine(world)
    linked = Linked(obj_path, world, targets=dict(mappings))
    out = []
    for name, addr in mappings:
        try:
            out.append(check_one(machine, world, linked, name, addr, source_text=source_text, **kw))
        except Exception as e:  # checker bug: never report a verdict
            out.append(Result(function=name, address=f"0x{addr:08X}", verdict="UNCHECKED",
                              reason=f"checker error {type(e).__name__}: {e}", checker=CHECKER_VERSION))
    machine.load_candidate(None)
    return out


def resolve_target(world, target):
    if target.lower().startswith("0x"):
        return int(target, 16)
    if target in world.by_name:
        return world.by_name[target]
    raise SystemExit(f"unknown target {target}")


def format_result(r):
    head = f"{r['verdict']} {r['function']} vs {r['address']}"
    if "size" in r:
        head += f" size {r['size']:#x}"
    if "valid" in r:
        head += (f": {r['valid']} valid trial(s) of {r['trials']}, coverage {r['coverage']:.0%} "
                 f"({r['blocks_covered']}/{r['blocks']} blocks)")
    if r.get("reason"):
        head += f"\n  reason: {r['reason']}"
    if r.get("report"):
        head += "\n  " + r["report"].replace("\n", "\n  ")
    return head


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("source", type=Path)
    ap.add_argument("mappings", nargs="+", help="candidate_name=target_name_or_0xaddr")
    ap.add_argument("--flags", nargs="*", default=[], help="extra cl flags, e.g. /GS- /O1")
    ap.add_argument("--obj", type=Path, help="use this compiled object instead of compiling the source")
    ap.add_argument("--trials", type=int, default=400)
    ap.add_argument("--seed", type=int, default=1)
    ap.add_argument("--min-coverage", type=float, default=0.9)
    ap.add_argument("--min-valid", type=int, default=30)
    ap.add_argument("--time", type=float, default=60.0, help="time budget per function in seconds")
    ap.add_argument("--json", type=Path, help="write the evidence records to this file")
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args()
    if not HAVE_UNICORN:
        print("UNCHECKED: unicorn is not installed (pip install unicorn)")
        return 2
    world = load_world()
    maps = []
    for m in a.mappings:
        name, _, target = m.partition("=")
        maps.append((name, resolve_target(world, target)))
    obj = a.obj or compile_source(a.source, a.flags)
    text = a.source.read_text(errors="replace") if a.source.is_file() else None
    results = check_object(obj, maps, source_text=text, trials=a.trials, seed=a.seed, min_cov=a.min_coverage,
                           min_valid=a.min_valid, time_budget=a.time)
    if not a.obj:
        shutil.rmtree(obj.parent, ignore_errors=True)
    src_hash = hashlib.sha256(a.source.read_bytes()).hexdigest() if a.source.is_file() else None
    for r in results:
        r["source"] = str(a.source)
        r["source_sha256"] = src_hash
        r["flags"] = a.flags
        r["matching_dir"] = os.environ.get("TS4_MATCHING_DIR")
        print(format_result(r))
    if a.json:
        a.json.write_text(json.dumps(results, indent=1))
    verdicts = {r["verdict"] for r in results}
    return 0 if verdicts == {"EQUIVALENT"} else 1 if "DIFFERENT" in verdicts else 2


if __name__ == "__main__":
    raise SystemExit(main())
