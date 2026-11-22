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
- Coverage: basic blocks of the original reached by valid trials. Blocks no path
  from the entry reaches (the `blr` after a tail call) and inline jump-table
  words (entries may leave the function) are not blocks to cover.
- 64-bit registers: where the consumer reads the upper word of r3-r10 (static
  analysis of the callee, of the function, or of the image's callers for r3),
  argument and return registers are seeded and compared in full.
- VMX/VMX128: v0-v127 are kept by the checker and the common vector
  instructions are interpreted (VEC_* tables); compared are v1-v13 the callee
  reads at each call, v1 at return when the function wrote it, and the
  callee-saved v14-v31/v64-v127. Other vector instructions, and functions that
  call the __savevmx/__restvmx helpers, stay UNCHECKED.
- Fault blocks: a block reached only by trials in which the original takes a
  null-pointer fault (one instruction, one address; at least 3 trials) counts
  as covered when the candidate, on each of those inputs, makes the same calls
  and writes and faults at the same address with the same access kind
  (evidence field fault_blocks). Otherwise it stays uncovered.
- A frame object passed to a callee that provably never reads through that
  pointer (pure out-parameter) is not compared at the call.

Verdicts: EQUIVALENT (all valid trials agree, at least --min-valid valid trials,
block coverage >= --min-coverage), DIFFERENT (first differing trial printed,
with arguments simplified where the difference persists), UNCHECKED (reason:
uninterpreted vector instruction, unresolved symbol, unsupported instruction, too few valid
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
CHECKER_VERSION = "fn_equiv/5"
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
FAULT_NULL_PAGE = 0x10000         # fault addresses below this are null-pointer dereferences
FAULT_MIN = 3                     # agreeing faulting trials needed to count a fault block as covered
FAULT_EXTRA = 12                  # re-runs per stored input of a fault path seen fewer than FAULT_MIN times
MAX_EVENTS = 4000                 # intercepted calls per run before the trial is discarded (--max-calls)
STACK_ARG_WINDOW = 4              # bytes of a frame object passed by pointer that are compared
# (one word: beyond it the window would reach neighbouring locals and register save slots, which
# two different compilations place differently; see docs/equivalence-tier.md 7.1)

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
    __slots__ = ("reads", "writes", "kind", "target", "word", "vec")

    def __init__(self, word, reads=(), writes=(), kind=None, target=None, vec=None):
        self.word, self.reads, self.writes, self.kind, self.target = word, frozenset(reads), frozenset(writes), kind, target
        self.vec = vec          # vec_decode() of a supported vector instruction, else None


def decode(w: int, pc: int) -> Insn:
    """Register use/def and control flow of one instruction. kind: None (plain),
    'b' 'bc' 'bl' 'blr' 'bclr' 'bctr' 'bcctr' 'bctrl' 'trap' 'sc' 'vec' 'dcbz' 'mftb' 'unknown'."""
    op = w >> 26
    d, a, b, c = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31, (w >> 6) & 31
    ra0 = (a,) if a else ()
    if op in (4, 5, 6):
        return vec_insn(w)
    if op == 31 and (w >> 1) & 0x3FF == 444 and d == a == b and not w & 1:
        return Insn(w)            # `or rX,rX,rX` (mr rX,rX): a no-op hint, reads nothing
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
            return vec_insn(w)
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

# ---------------------------------------------------------------------------
# VMX / VMX128. Unicorn exposes no vector registers and knows no VMX128 encodings, so the
# checker keeps v0-v127 itself (16 big-endian bytes each) and interprets the supported vector
# instructions of the original and of the candidate in a code hook. Both runs go through the
# same interpreter; an instruction outside VEC_OPS makes the function UNCHECKED.
# Calling convention (Xenon): v1-v13 arguments, v1 return value, v0-v13 and v32-v63 volatile,
# v14-v31 and v64-v127 callee-saved.
VEC_ARGS = tuple(range(1, 14))
VEC_VOLATILE = tuple(range(0, 14)) + tuple(range(32, 64))
VEC_NONVOL = tuple(range(14, 32)) + tuple(range(64, 128))

VEC_MEM31 = {103: "lvx", 231: "stvx", 359: "lvx", 487: "stvx", 519: "lvlx", 551: "lvrx", 647: "stvlx",
             679: "stvrx", 71: "lvewx", 199: "stvewx"}
VEC_MEM128 = {195: "lvx", 451: "stvx", 707: "lvx", 963: "stvx", 1027: "lvlx", 1091: "lvrx",
              1283: "stvlx", 1347: "stvrx", 131: "lvewx", 387: "stvewx"}
VEC_VA = {46: "vmaddfp", 47: "vnmsubfp", 42: "vsel", 43: "vperm"}      # vD <- vA, vB, vC
VEC_VX = {10: "vaddfp", 74: "vsubfp", 1034: "vmaxfp", 1098: "vminfp", 1028: "vand", 1092: "vandc",
          1156: "vor", 1220: "vxor", 1284: "vnor", 140: "vmrghw", 396: "vmrglw", 388: "vslw",
          644: "vsrw", 128: "vadduwm", 1152: "vsubuwm"}                # vD <- vA, vB
VEC_VXB = {266: "vrefp", 330: "vrsqrtefp"}                             # vD <- vB
VEC_VXI = {652: "vspltw", 842: "vcfsx", 778: "vcfux", 970: "vctsxs", 906: "vctuxs"}   # vD <- vB, uimm
VEC_CMP = {198: "vcmpeqfp", 454: "vcmpgefp", 710: "vcmpgtfp", 134: "vcmpequw"}
VEC_5 = {16: "vaddfp", 80: "vsubfp", 144: "vmulfp", 400: "vmsum3fp", 464: "vmsum4fp", 528: "vand",
         592: "vandc", 656: "vnor", 720: "vor", 784: "vxor"}           # vD <- vA, vB
VEC_5ACC = {208: "vmaddfp", 272: "vmaddcfp", 336: "vnmsubfp", 848: "vsel"}   # vD <- vA, vB, vD
VEC_6 = {640: "vmaxfp", 704: "vminfp", 768: "vmrghw", 832: "vmrglw", 208: "vslw", 464: "vsrw"}
VEC_6CMP = {0: "vcmpeqfp", 128: "vcmpgefp", 256: "vcmpgtfp", 512: "vcmpequw"}
VEC_6B = {1584: "vrefp", 1648: "vrsqrtefp"}
VEC_6I = {1840: "vspltw", 688: "vcfsx", 752: "vcfux", 560: "vctsxs", 624: "vctuxs"}


def vec_decode(w: int):
    """(name, vD, sources, imm, rc, (rA, rB) or None) of a supported vector instruction, else None.
    sources are vector register numbers in the order the semantics use them (see vec_apply);
    for the memory forms vD is the loaded or stored register."""
    op = w >> 26
    d, a, b, c = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31, (w >> 6) & 31
    if op == 31:
        n = VEC_MEM31.get((w >> 1) & 0x3FF)
        return (n, d, (), 0, 0, (a, b)) if n else None
    D = d | ((w >> 2) & 3) << 5                     # VMX128 register fields
    A = a | ((w >> 5) & 1) << 5 | ((w >> 10) & 1) << 6
    B = b | (w & 3) << 5
    if op == 4:
        if w & 0x10:
            return ("vsldoi", D, (A, B), (w >> 6) & 15, 0, None)
        if w & 0x33 == 0x03:
            n = VEC_MEM128.get(w & 0x7F3)
            return (n, D, (), 0, 0, (a, b)) if n else None
        x6, x11 = w & 0x3F, w & 0x7FF
        if x6 in (46, 47):          # vmaddfp / vnmsubfp vD,vA,vC,vB: sources as (vA, vC, vB)
            return (VEC_VA[x6], d, (a, c, b), 0, 0, None)
        if x6 in VEC_VA:
            return (VEC_VA[x6], d, (a, b, c), 0, 0, None)
        if x6 == 44 and not w & 0x400:
            return ("vsldoi", d, (a, b), c & 15, 0, None)
        if x11 in VEC_VX:
            return (VEC_VX[x11], d, (a, b), 0, 0, None)
        if x11 in VEC_VXB and not a:
            return (VEC_VXB[x11], d, (b,), 0, 0, None)
        if x11 in VEC_VXI:
            return (VEC_VXI[x11], d, (b,), a, 0, None)
        if x11 == 908 and not b:
            return ("vspltisw", d, (), sext(a, 5), 0, None)
        if w & 0x3FF in VEC_CMP:
            return (VEC_CMP[w & 0x3FF], d, (a, b), 0, (w >> 10) & 1, None)
        return None
    if op == 5:
        if w & 0x210 == 0:
            return ("vperm", D, (A, B, (w >> 6) & 7), 0, 0, None)
        k = w & 0x3D0
        if k in VEC_5:
            return (VEC_5[k], D, (A, B), 0, 0, None)
        if k in VEC_5ACC:
            return (VEC_5ACC[k], D, (A, B, D), 0, 0, None)
        return None
    if op == 6:
        k3 = w & 0x7F0
        if k3 in VEC_6B:
            return (VEC_6B[k3], D, (B,), 0, 0, None)
        if k3 in VEC_6I:
            return (VEC_6I[k3], D, (B,), a, 0, None)
        if k3 == 1904:
            return ("vspltisw", D, (), sext(a, 5), 0, None)
        if w & 0x730 == 0x710:
            return ("vrlimi", D, (B, D), a | ((w >> 6) & 3) << 8, 0, None)     # imm: mask | rotate << 8
        if w & 0x630 == 0x210:
            return ("vpermwi", D, (B,), a | ((w >> 6) & 7) << 5, 0, None)
        if w & 0x390 in VEC_6CMP and not w & 0x10:
            return (VEC_6CMP[w & 0x390], D, (A, B), 0, (w >> 6) & 1, None)
        if w & 0x3D0 in VEC_6:
            return (VEC_6[w & 0x3D0], D, (A, B), 0, 0, None)
    return None


def vec_insn(w: int) -> Insn:
    v = vec_decode(w)
    if v is None or v[5] is None:
        return Insn(w, kind="vec", vec=v)
    ra, rb = v[5]
    return Insn(w, ((ra,) if ra else ()) + (rb,), (), kind="vec", vec=v)


def vec_regs(v):
    """(vector registers read, vector registers written) of a vec_decode() result."""
    name, d, src = v[0], v[1], v[2]
    if name.startswith("st"):
        return (d,), ()
    return tuple(src), (d,)


def _f32(x):
    try:
        return struct.unpack(">f", struct.pack(">f", x))[0]
    except OverflowError:
        return math.copysign(math.inf, x)


def _fl(v):
    return struct.unpack(">4f", v)


def _pf(xs):
    return b"".join(struct.pack(">f", _f32(x)) for x in xs)


def _wd(v):
    return struct.unpack(">4I", v)


def _pw(xs):
    return struct.pack(">4I", *(x & 0xFFFFFFFF for x in xs))


def _fdiv(x, y):
    if y != y or x != x:
        return math.nan
    if y == 0:
        return math.nan if x == 0 else math.copysign(math.inf, x) * math.copysign(1.0, y)
    return x / y


def _fmul(x, y):
    try:
        return x * y
    except OverflowError:       # pragma: no cover - float products do not raise
        return math.inf


def _sat(x, lo, hi):
    if x != x:
        return 0
    return lo if x <= lo else hi if x >= hi else int(x)


def _vcmp(name, x, y):
    if name == "vcmpeqfp":
        return x == y
    if name == "vcmpgefp":
        return x >= y
    return x > y


def vec_apply(name, s, imm):
    """Result bytes of a register-only vector instruction; s: source values (vec_decode order)."""
    if name in ("vor", "vand", "vandc", "vxor", "vnor"):
        x, y = int.from_bytes(s[0], "big"), int.from_bytes(s[1], "big")
        m = (1 << 128) - 1
        r = {"vor": x | y, "vand": x & y, "vandc": x & ~y, "vxor": x ^ y, "vnor": ~(x | y)}[name] & m
        return r.to_bytes(16, "big")
    if name in ("vaddfp", "vsubfp", "vmulfp", "vmaxfp", "vminfp"):
        fx, fy = _fl(s[0]), _fl(s[1])
        if name in ("vmaxfp", "vminfp"):
            pick = max if name == "vmaxfp" else min
            return _pf(math.nan if x != x or y != y else pick(x, y) for x, y in zip(fx, fy))
        f = {"vaddfp": lambda x, y: x + y, "vsubfp": lambda x, y: x - y, "vmulfp": _fmul}[name]
        return _pf(f(x, y) for x, y in zip(fx, fy))
    if name == "vmaddfp":           # AltiVec: vA*vC + vB; VMX128: vA*vB + vD (sources x, y, z: x*y + z)
        x, y, z = (_fl(v) for v in s)
        return _pf(_fmul(p, q) + r for p, q, r in zip(x, y, z))
    if name == "vmaddcfp":          # VMX128: vA*vD + vB
        x, y, z = (_fl(v) for v in s)
        return _pf(p * r + q for p, q, r in zip(x, y, z))
    if name == "vnmsubfp":          # AltiVec: -(vA*vC - vB); VMX128: -(vA*vB - vD)
        x, y, z = (_fl(v) for v in s)
        return _pf(-(p * q - r) for p, q, r in zip(x, y, z))
    if name in ("vmsum3fp", "vmsum4fp"):
        x, y = _fl(s[0]), _fl(s[1])
        n = 3 if name == "vmsum3fp" else 4
        t = 0.0
        for i in range(n):
            t = _f32(t + _f32(x[i] * y[i]))
        return _pf([t] * 4)
    if name == "vsel":              # bits of vB where the mask (vC, or vD for VMX128) is 1, else vA
        x, y, m = (int.from_bytes(v, "big") for v in s)
        return ((x & ~m) | (y & m)).to_bytes(16, "big")
    if name == "vperm":
        t = s[0] + s[1]
        return bytes(t[i & 31] for i in s[2])
    if name == "vsldoi":
        return (s[0] + s[1])[imm:imm + 16]
    if name == "vspltw":
        return s[0][4 * (imm & 3):4 * (imm & 3) + 4] * 4
    if name == "vspltisw":
        return struct.pack(">i", imm) * 4
    if name == "vpermwi":
        return b"".join(s[0][4 * ((imm >> sh) & 3):][:4] for sh in (6, 4, 2, 0))
    if name == "vrlimi":            # words of vB rotated left by z replace the words of vD selected by the mask
        z, mask = imm >> 8, imm & 15
        src, dst = _wd(s[0]), _wd(s[1])
        return _pw(src[(i + z) & 3] if mask & (8 >> i) else dst[i] for i in range(4))
    if name in ("vmrghw", "vmrglw"):
        x, y = _wd(s[0]), _wd(s[1])
        o = 0 if name == "vmrghw" else 2
        return _pw((x[o], y[o], x[o + 1], y[o + 1]))
    if name in ("vcmpeqfp", "vcmpgefp", "vcmpgtfp"):
        return _pw(0xFFFFFFFF if _vcmp(name, x, y) else 0 for x, y in zip(_fl(s[0]), _fl(s[1])))
    if name == "vcmpequw":
        return _pw(0xFFFFFFFF if x == y else 0 for x, y in zip(_wd(s[0]), _wd(s[1])))
    if name == "vrefp":
        return _pf(_fdiv(1.0, x) for x in _fl(s[0]))
    if name == "vrsqrtefp":
        return _pf(math.nan if x != x or x < 0 else _fdiv(1.0, math.sqrt(x)) for x in _fl(s[0]))
    if name == "vcfsx":
        return _pf(sext(x, 32) / (1 << imm) for x in _wd(s[0]))
    if name == "vcfux":
        return _pf(x / (1 << imm) for x in _wd(s[0]))
    if name == "vctsxs":
        return _pw(_sat(x * (1 << imm), -0x80000000, 0x7FFFFFFF) for x in _fl(s[0]))
    if name == "vctuxs":
        return _pw(_sat(x * (1 << imm), 0, 0xFFFFFFFF) for x in _fl(s[0]))
    if name in ("vslw", "vsrw", "vadduwm", "vsubuwm"):
        f = {"vslw": lambda x, y: x << (y & 31), "vsrw": lambda x, y: x >> (y & 31),
             "vadduwm": lambda x, y: x + y, "vsubuwm": lambda x, y: x - y}[name]
        return _pw(f(x, y) for x, y in zip(_wd(s[0]), _wd(s[1])))
    raise KeyError(name)


def vec_poison(reg, k):
    return bytes((0xBA, 0xD0, reg, k & 0xFF)) * 4


def is_vec_poison(v):
    return v[:2] == b"\xBA\xD0" and v[:4] * 4 == v

# 64-bit use of GPRs. Xenon registers are 64 bits wide and the ABI passes `long long` values and
# small structs in full registers, while 32-bit code leaves the upper halves undefined. The
# checker therefore compares the upper half of a register only where the consumer reads it.
M64 = (1 << 64) - 1
W_USE2 = {233, 73, 9, 489, 457}                  # mulld mulhd mulhdu divd divdu: rA, rB
W_PROP_LOG = {28, 60, 444, 412, 316, 476, 124, 284}   # and andc or orc xor nand nor eqv: rA <- rS, rB
W_PROP2 = {266, 40, 10, 8, 138, 136}             # add subf addc subfc adde subfe: rD <- rA, rB
W_PROP1 = {104, 202, 200, 234, 232}              # neg addze subfze addme subfme: rD <- rA
R1_LOAD = {32: 4, 34: 1, 40: 2, 42: 2, 48: 4, 50: 8}
R1_STORE = {36: 4, 38: 1, 44: 2, 52: 4, 54: 8}


def wide_effect(w: int):
    """(use, dst, srcs) of one instruction: `use` are GPRs whose upper 32 bits it observes; when
    `dst` is not None its upper 32 bits are a function of the upper bits of `srcs` (a 64-bit
    move/add/logical op). Every other register write produces a value whose upper half does not
    depend on an input's upper half. Loads and stores through r1 are handled by the caller."""
    op = w >> 26
    d, a, b = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
    if op == 30:
        sh = ((w >> 11) & 31) | ((w >> 1) & 1) << 5
        f = (w >> 5) & 0x3F
        m = (f >> 1) | (f & 1) << 5
        x3 = (w >> 2) & 7
        if x3 > 3:
            return (d,), None, ()                # rldcl/rldcr
        mask = ((1 << (64 - m)) - 1) if x3 == 0 else (M64 & ~((1 << (63 - m)) - 1)) if x3 == 1 else \
            ((1 << (64 - m)) - 1) & ~((1 << sh) - 1)
        hi = 0xFFFFFFFF00000000
        used = ((hi << sh | hi >> (64 - sh)) & M64 if sh else hi) & mask
        if x3 == 3:
            return ((d,) if used else ()), a, (a,)     # rldimi keeps the rest of rA
        return ((d,) if used else ()), None, ()
    if op == 62:
        return (d,), None, ()
    if op == 2:
        return (a,), None, ()
    if op in (10, 11):
        return ((a,) if (w >> 21) & 1 else ()), None, ()
    if op in (14, 15):
        return (), (d if a else None), ((a,) if a else ())
    if op in (12, 13, 8, 7):
        return (), d, (a,)
    if 24 <= op <= 27:
        return (), a, (d,)
    if op == 20:
        return (), a, (a,)
    if op == 31:
        xo = (w >> 1) & 0x3FF
        xo9 = xo & 0x1FF
        if xo in (0, 32):
            return ((a, b) if (w >> 21) & 1 else ()), None, ()
        if xo == 68:
            return (a, b), None, ()
        if xo in (149, 181, 214, 27, 539, 794, 826, 827, 58):   # stdx stdux stdcx. sld srd srad sradi cntlzd
            return (d,), None, ()
        if xo in W_PROP_LOG:
            return (), a, (d, b)
        if xo9 in W_USE2 and xo not in LOG2 and xo not in LDX and xo not in STX:
            return (a, b), None, ()
        if xo9 in W_PROP2 and xo not in LOG2 and xo not in LDX and xo not in STX:
            return (), d, (a, b)
        if xo9 in W_PROP1:
            return (), d, (a,)
    return (), None, ()


def r1_access(w: int):
    """(is_store, displacement, byte size) of a load/store through r1, else None."""
    op = w >> 26
    if (w >> 16) & 31 != 1:
        return None
    if op in R1_LOAD:
        return False, sext(w & 0xFFFF, 16), R1_LOAD[op]
    if op in R1_STORE:
        return True, sext(w & 0xFFFF, 16), R1_STORE[op]
    if op == 58 and w & 3 != 1:
        return False, sext(w & 0xFFFC, 16), 8 if w & 3 == 0 else 4
    if op == 62 and w & 3 == 0:
        return True, sext(w & 0xFFFC, 16), 8
    return None


class Func:
    """Decoded function: instructions, jump tables, basic blocks."""

    def __init__(self, code: bytes, base: int, text=None):
        """text: (lo, hi) of the image's code, to recognise jump-table entries that leave the function."""
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
            # A table may also point at case bodies outside the function (bodies shared with or
            # split into neighbouring functions). Such words look like `lbz` instructions, so
            # they are taken as table data only up to the entry count of the guarding
            # `cmplwi rX,N` (N + 1 entries) and never past an in-function target of the table.
            count = None
            for x in reversed(self.insns[max(0, i - 12):i]):
                if (x.word >> 26) == 10:
                    count = (x.word & 0xFFFF) + 1
                    break
            lo, hi = text if text and count else (base, base)
            j, tgts, stop = i + 1, [], n
            while (j < min(n, stop, i + 1 + (count or n)) and words[j] % 4 == 0 and
                   (base <= words[j] < base + self.size or lo <= words[j] < hi)):
                if base + 4 * j < words[j] < base + self.size:
                    stop = min(stop, (words[j] - base) // 4)
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

    def succ(self):
        """Successor block indices of every block (in-function control flow only)."""
        start_of = {s: k for k, (s, _) in enumerate(self.blocks)}
        out = []
        for s, e in self.blocks:
            last = self.insns[e - 1]
            nxt = []
            if last.kind in ("b", "bc") and self.inside(last.target):
                nxt.append((last.target - self.base) // 4)
            nxt += [(t - self.base) // 4 for t in self.tables.get(e - 1, ())]
            if last.kind not in ("b", "blr", "bctr"):
                nxt.append(e)
            out.append([start_of[i] for i in nxt if i in start_of])
        return out

    def frame_adjust(self):
        """Per instruction: how far r1 is below its entry value (0 before the `stwu r1,-F(r1)`
        and after an epilogue's `addi r1,..`, F in between), so r1 displacements can be compared
        across the prologue."""
        out, adj, frame = [], 0, 0
        for ins in self.insns:
            out.append(adj)
            w = ins.word
            op, rd, ra = w >> 26, (w >> 21) & 31, (w >> 16) & 31
            if op == 37 and rd == 1 and ra == 1 and sext(w & 0xFFFF, 16) < 0:
                adj = frame = -sext(w & 0xFFFF, 16)
            elif op == 14 and rd == 1:
                adj = 0
            elif ins.kind in ("b", "blr", "bctr"):
                adj = frame
        return out

    def dead_blocks(self):
        """Start addresses of blocks that no path from the entry reaches: code after an
        unconditional transfer (`b`, `blr`, table `bctr`) that no branch or jump table targets,
        e.g. the `blr` MSVC leaves after a tail call `b callee`. No trial can run them, so they
        do not count for coverage. Empty when the function has an indirect jump without a
        recognised table (its targets are unknown)."""
        start_of = {s: k for k, (s, _) in enumerate(self.blocks)}
        seen, todo = set(), [0] if self.blocks else []
        while todo:
            k = todo.pop()
            if k in seen:
                continue
            seen.add(k)
            s, e = self.blocks[k]
            last = self.insns[e - 1]
            nxt = []
            if last.kind in ("bctr", "bcctr") and e - 1 not in self.tables:
                return []
            if last.kind in ("b", "bc") and self.inside(last.target):
                nxt.append((last.target - self.base) // 4)
            nxt += [(t - self.base) // 4 for t in self.tables.get(e - 1, ())]
            if last.kind not in ("b", "blr", "bctr"):
                nxt.append(e)
            todo += [start_of[i] for i in nxt if i in start_of]
        return [self.base + 4 * s for k, (s, _) in enumerate(self.blocks) if k not in seen]

    def inside(self, addr):
        return self.base <= addr < self.base + self.size

    def block_addrs(self):
        return [self.base + 4 * s for s, _ in self.blocks]

    def has_vector(self):
        return any(ins.kind == "vec" for i, ins in enumerate(self.insns) if i not in self.data)

    def unsupported_vector(self):
        """Word of the first vector instruction the checker cannot interpret, or None."""
        for i, ins in enumerate(self.insns):
            if i not in self.data and ins.kind == "vec" and ins.vec is None:
                return ins.word
        return None

    def code_words(self):
        return [(self.base + 4 * i, ins) for i, ins in enumerate(self.insns) if i not in self.data]


class Analysis:
    """Static facts about image functions: argument registers read (live-in) and
    registers written (transitively). `code_of(addr)` returns the bytes of the
    function starting at addr, or None."""

    def __init__(self, code_of, is_helper=lambda a: False, text=None):
        self.code_of = code_of
        self.text = text
        self.is_helper = is_helper
        self.funcs, self.live, self.defs, self._slots = {}, {}, {}, {}
        self.varargs = set()
        self._busy_live, self._busy_defs = set(), set()
        self.wide, self._busy_wide = {}, set()
        self.vlive, self._busy_vlive = {}, set()
        self._reads, self._busy_reads = {}, set()

    def func(self, addr):
        if addr not in self.funcs:
            code = self.code_of(addr)
            self.funcs[addr] = Func(code, addr, self.text) if code else None
        return self.funcs[addr]

    def stack_arg_slots(self, addr):
        """Indices j of stack arguments 9+j the function reads (loads from its caller's
        r1+0x54+8j), or None when that cannot be told (varargs, frame pointer, no code)."""
        if addr in self._slots:
            return self._slots[addr]
        f = self.func(addr)
        res = None
        if f is not None:
            frame, out = 0, set()
            res = frozenset()
            for _, ins in f.code_words():
                w = ins.word
                op, rd, ra, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, sext(w & 0xFFFF, 16)
                if op == 37 and rd == 1 and ra == 1 and imm < 0 and not frame:
                    frame = -imm                       # stwu r1, -F(r1)
                    continue
                if ra == 1 and op in (32, 34, 40, 42, 48, 50, 58) and imm >= frame + 0x54:
                    out.add((imm - frame - 0x54) // 8)  # a load from the caller's argument area
                elif ra == 1 and op == 14 and rd != 1 and imm >= frame + 0x14:
                    res = None                         # address of the home/argument area taken:
                    self.varargs.add(addr)             # va_start (a variadic function)
                    break
                elif op == 14 and ra == 1 and rd not in (1,) and imm < 0:
                    res = None                         # frame pointer below r1 (subi rX, r1, n)
                    break
            if res is not None:
                res = frozenset(out)
        self._slots[addr] = res
        return res

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
            elif k == "bctr":
                for t in f.tables[(i - f.base) // 4]:
                    if not f.inside(t):
                        out |= self.defs_of(t, depth + 1)
        self._busy_defs.discard(addr)
        res = frozenset(out)
        self.defs[addr] = res
        return res

    def wide_in(self, addr, depth=0):
        """Argument GPRs (r3-r10) whose upper 32 bits the function at addr observes: read by a
        64-bit instruction (std to memory, 64-bit rotate/shift/multiply/compare), stored to its
        frame with std and read back from the high word, or passed on to a callee that does.
        An under-approximation where code is not understood (unknown callee, address-taken
        frame slot): those registers keep the 32-bit comparison."""
        if addr in self.wide:
            return self.wide[addr]
        f = None if self.is_helper(addr) else self.func(addr)
        if f is None or depth > 40 or addr in self._busy_wide:
            return frozenset()
        self._busy_wide.add(addr)
        succ, adj = f.succ(), f.frame_adjust()

        def transfer(k, W):
            s, e = f.blocks[k]
            for i in range(e - 1, s - 1, -1):
                ins = f.insns[i]
                w, kind = ins.word, ins.kind
                if kind == "bl" or (kind in ("b", "bc") and not f.inside(ins.target)):
                    if kind != "bc":
                        W -= self.defs_of(ins.target, depth + 1)
                    W |= self.wide_in(ins.target, depth + 1)
                    continue
                if kind in ("bctrl", "unknown", "sc"):
                    W -= VOLATILE
                    continue
                acc = r1_access(w)
                if acc:
                    store, disp, n = acc
                    lo = disp - adj[i]
                    if store:
                        if (w >> 26) == 62 and ("s", lo) in W:
                            W.add((w >> 21) & 31)        # the high word of this std is read later
                        W -= {("s", x) for x in range(lo, lo + n - 3)}
                    elif (w >> 26) == 58 and w & 3 == 0 and (w >> 21) & 31 not in W:
                        W -= ins.writes                  # ld of a register nobody reads in full
                    else:
                        W -= ins.writes
                        W |= {("s", x) for x in range(lo - 3, lo + n) if x % 4 == 0}
                    continue
                use, dst, srcs = wide_effect(w)
                hit = dst is not None and dst in W
                W -= ins.writes
                W.update(use)
                if hit:
                    W.update(srcs)
            return W

        win = [set() for _ in f.blocks]
        for _ in range(4 * len(f.blocks) + 4):
            changed = False
            for k in range(len(f.blocks) - 1, -1, -1):
                out = set()
                for j in succ[k]:
                    out |= win[j]
                new = transfer(k, out)
                if new != win[k]:
                    win[k], changed = new, True
            if not changed:
                break
        self._busy_wide.discard(addr)
        res = frozenset(win[0]) & GPR_ARG_SET if win else frozenset()
        self.wide[addr] = res
        return res

    def reads_through(self, addr, reg, depth=0):
        """May the function at addr read the object its pointer argument `reg` (r3-r10) points
        to? False only when that is ruled out: on every path the pointer and its register copies
        are used for nothing but stores through them, comparisons, further copies, the return
        value, and calls whose callees satisfy the same. Anything else (a load, pointer
        arithmetic, storing the pointer, an indirect call that may receive it) answers True."""
        key = (addr, reg)
        if key in self._reads:
            return self._reads[key]
        f = self.func(addr)
        if f is None or depth > 8 or key in self._busy_reads or self.is_helper(addr):
            return True
        self._busy_reads.add(key)
        succ = f.succ()
        state = {0: frozenset((reg,))}
        todo, result = [0], False
        while todo and not result:
            k = todo.pop()
            alias = set(state[k])
            s, e = f.blocks[k]
            for i in range(s, e):
                if not alias:
                    break
                ins = f.insns[i]
                w, kind = ins.word, ins.kind
                op, rd, ra, rb = w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
                if kind == "bl" or (kind in ("b", "bc") and not f.inside(ins.target)):
                    if not self.is_helper(ins.target):
                        live = self.live_in(ins.target)
                        for r in sorted(alias & GPR_ARG_SET):
                            if (live is None or r in live) and self.reads_through(ins.target, r, depth + 1):
                                result = True
                    alias -= self.defs_of(ins.target)
                    continue
                if kind in ("bctrl", "bctr", "bcctr", "sc", "unknown", "vec") and (i not in f.tables):
                    if alias & (GPR_ARG_SET if kind != "vec" else ins.reads) or kind in ("unknown", "sc"):
                        result = True
                    alias -= VOLATILE if kind != "vec" else set()
                    continue
                used = ins.reads & alias
                if used:
                    xo = (w >> 1) & 0x3FF
                    if op == 31 and xo == 444 and rd == rb:                 # mr rA,rS
                        alias.add(ra)
                        continue
                    if op in (10, 11) or (op == 31 and xo in (0, 32)):      # compare
                        continue
                    if op in (36, 38, 44, 52, 54, 62) and ra in alias and rd not in alias:
                        continue                                            # store through the pointer
                    result = True
                    break
                alias -= ins.writes
            if result:
                break
            out = frozenset(alias)
            for j in succ[k]:
                new = state.get(j, frozenset()) | out
                if new != state.get(j):
                    state[j] = new
                    todo.append(j)
        self._busy_reads.discard(key)
        self._reads[key] = result
        return result

    def vec_live_in(self, addr, depth=0):
        """Vector argument registers (numbers 1-13) the function reads before writing, calls
        included; None if unknown (no code, an uninterpreted vector instruction, recursion)."""
        if addr in self.vlive:
            return self.vlive[addr]
        if self.is_helper(addr):
            return frozenset()
        f = self.func(addr)
        if f is None or depth > 40 or addr in self._busy_vlive or f.unsupported_vector() is not None:
            return None
        self._busy_vlive.add(addr)
        gen, kill, unknown = [], [], False
        for s, e in f.blocks:
            g, kl = set(), set()
            for i in range(s, e):
                ins = f.insns[i]
                k = ins.kind
                rd, wr = vec_regs(ins.vec) if ins.vec else ((), ())
                if k == "bl" or (k in ("b", "bc") and not f.inside(ins.target)):
                    sub = self.vec_live_in(ins.target, depth + 1)
                    if sub is None:
                        unknown = True
                    rd, wr = sub or (), VEC_VOLATILE
                elif k in ("bctrl", "bctr", "bcctr") and i not in f.tables:
                    wr = VEC_VOLATILE
                g |= set(rd) - kl
                kl |= set(wr)
            gen.append(g & set(VEC_ARGS))
            kill.append(kl)
        succ = f.succ()
        live = [set() for _ in f.blocks]
        changed = True
        while changed:
            changed = False
            for k in range(len(f.blocks) - 1, -1, -1):
                out = set()
                for j in succ[k]:
                    out |= live[j]
                new = gen[k] | (out - kill[k])
                if new != live[k]:
                    live[k], changed = new, True
        self._busy_vlive.discard(addr)
        res = None if unknown else frozenset(live[0]) if f.blocks else frozenset()
        self.vlive[addr] = res
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
                    # a callee whose liveness is unknown (deep CRT chains into import thunks,
                    # recursion cycles) is assumed to read r3 only: registers set up before the
                    # call are not live-in anyway, and assuming all of r3-r10 made every caller
                    # of such a chain "pass" its stale temporaries (false call-argument diffs)
                    reads |= {3} if sub is None else sub
                    writes |= self.defs_of(ins.target, depth + 1)
                elif kind == "bctrl" or (kind == "bctr" and i not in f.tables) or (kind == "bcctr"):
                    # indirect call: only r3 ('this') is assumed to be passed through from entry;
                    # arguments set up locally are killed before the call anyway
                    reads.add(3)
                    writes |= VOLATILE
                elif kind == "unknown":
                    unknown = True
                elif kind == "bctr":
                    # jump-table entries that leave the function are tail calls
                    for t in f.tables[i]:
                        if not f.inside(t):
                            sub = self.live_in(t, depth + 1)
                            reads |= {3} if sub is None else sub
                            writes |= self.defs_of(t, depth + 1)
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
        self.analysis = Analysis(self.code_of, self.in_helper, self.text_range)
        self._callsites = None
        self._retwide = {}

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


    def return_wide(self, addr):
        """Does some direct caller read the upper 32 bits of r3 after `bl addr` (a 64-bit
        integer or a small struct returned in the full register)? Straight-line scan."""
        if addr not in self._retwide:
            self._retwide[addr] = any(self._wide_after(site + 4) for site in self.callsites().get(addr, [])[:200])
        return self._retwide[addr]

    def _wide_after(self, pc):
        tracked, slots = {3}, set()
        for _ in range(40):
            off = pc - self.base
            if not (0 <= off < len(self.image) - 4) or not (tracked or slots):
                return False
            w = struct.unpack_from(">I", self.image, off)[0]
            ins = decode(w, pc)
            if ins.kind == "bl":
                return bool(tracked & self.analysis.wide_in(ins.target))
            if ins.kind is not None and ins.kind not in ("trap", "dcbz", "mftb"):
                return False
            acc = r1_access(w)
            if acc:
                store, disp, n = acc
                if store:
                    slots -= set(range(disp, disp + n - 3))
                    if (w >> 26) == 62 and (w >> 21) & 31 in tracked:
                        slots.add(disp)
                else:
                    hit = any(disp - 4 < x < disp + n for x in slots)
                    tracked -= ins.writes
                    if hit and (w >> 26) == 58 and w & 3 == 0:
                        tracked.add((w >> 21) & 31)
                    elif hit:
                        return True
            else:
                use, dst, srcs = wide_effect(w)
                if tracked & set(use):
                    return True
                hit = dst is not None and tracked & set(srcs)
                tracked -= ins.writes
                if hit:
                    tracked.add(dst)
            pc += 4
        return False


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
                m = re.search(r"_([0-9A-F]{8})$", name) if not name.startswith((".", "$", "?")) else None
                if m and int(m.group(1), 16) in world.func_size:
                    # a function defined in the candidate's own file under a name that carries an
                    # image address (a context copy of a callee): call the image's function, so
                    # the call is intercepted exactly like the original's
                    return int(m.group(1), 16)
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
        self.max_events = MAX_EVENTS
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
        if size in (1, 2, 4, 8) and (a & (PAGE - 1)) + size <= PAGE and \
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
        elif kind == "vec":
            try:
                self._vec(uc, vec_decode(w))
            except Fault as e:
                self.fault = ("vec", e.args[0])
                uc.emu_stop()
                return
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

    def _vstore(self, a, data):
        self.write(a, data)
        if STACK_LO <= a < STACK_HI:
            r = range(a, a + len(data))
            self.stack_touched.update(r)
            self.stack_since.update(r)

    def _vec(self, uc, v):
        """Interpret one supported vector instruction on the checker's own v0-v127."""
        name, d, src, imm, rc, mem = v
        vr = self.vr
        if mem is None:
            out = vec_apply(name, [vr[r] for r in src], imm)
            vr[d] = out
            if d == 1:
                self.v1_own = True
            if rc:      # CR6: bit 0 (LT) all elements true, bit 2 (EQ) all false
                uc.reg_write(P.UC_PPC_REG_CR6, 8 if out == b"\xFF" * 16 else 2 if out == bytes(16) else 0)
            return
        ra, rb = mem
        ea = ((uc.reg_read(P.UC_PPC_REG_0 + ra) if ra else 0) + uc.reg_read(P.UC_PPC_REG_0 + rb)) & 0xFFFFFFFF
        lo, k = ea & ~15, ea & 15
        if name == "lvx" or name == "lvewx":        # lvewx: hardware loads the whole aligned vector
            val = self.read(lo, 16)
        elif name == "lvlx":
            val = self.read(ea, 16 - k) + bytes(k)
        elif name == "lvrx":
            val = bytes(16 - k) + (self.read(lo, k) if k else b"")
        elif name == "stvx":
            return self._vstore(lo, vr[d])
        elif name == "stvewx":
            return self._vstore(ea & ~3, vr[d][k & 12:(k & 12) + 4])
        elif name == "stvlx":
            return self._vstore(ea, vr[d][:16 - k])
        else:                                       # stvrx
            return self._vstore(lo, vr[d][16 - k:]) if k else None
        vr[d] = val
        if d == 1:
            self.v1_own = True

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
                if self.trace is not None:
                    self.marks.append((a, size, len(self.trace)))
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

    def _save_slot(self, x):
        """Does stack byte x belong to a saved LR / callee-saved register (canary values)?"""
        d = x & ~7
        if not (STACK_LO <= d <= STACK_HI - 8):
            return False
        dw = int.from_bytes(bytes(self.stack_buf[d - STACK_LO: d - STACK_LO + 8]), "big")
        w = (dw >> 32) if x - d < 4 else dw & 0xFFFFFFFF
        return (dw >> 8) == 0xC0DE00 or (dw >> 32) == 0x4300DE00 or w == RET_MAGIC

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
            if STACK_LO <= v < STACK_HI:
                # pointer into the stack (own frame, or the caller's home/argument area):
                # compare the object, not its address
                # a callee that provably never reads through this pointer (a pure out-parameter)
                # cannot observe what the frame slot held before the call: nothing to compare
                blind = image_fn and not self.w.analysis.reads_through(a, reg)
                frame[reg] = tuple(self.stack_buf[x - STACK_LO]
                                   if x in self.stack_touched and not blind and not self._save_slot(x) else None
                                   for x in range(v, min(v + STACK_ARG_WINDOW, STACK_HI)))
        sargs = {}
        if args is None or 10 in args:
            # arguments 9+ are passed in the caller's frame at r1+0x54, 8 bytes per slot
            sp = uc.reg_read(P.UC_PPC_REG_1) & 0xFFFFFFFF
            for j in range(8):
                lo = sp + 0x54 + 8 * j
                if not (STACK_LO <= lo and lo + 4 <= STACK_TOP):
                    continue                 # outside the function's frame
                # bytes holding a saved LR / register (the slot's second word can be the LR save
                # word of a small frame) or lying above the frame are masked, not compared
                own = [x for x in range(lo, lo + 8) if x < STACK_TOP and not self._save_slot(x)]
                if any(x in self.stack_since for x in own):
                    sargs[j] = tuple(self.stack_buf[x - STACK_LO] if x in own else None
                                     for x in range(lo, lo + 8))
        self.stack_since = set()
        vargs = self.w.analysis.vec_live_in(a) if image_fn else None
        self.events.append((a, vals, args, self.delta(), frame, sargs, tuple(self.vr[1:14]), vargs))
        if len(self.events) > self.max_events:
            self.outcome = ("limit", "calls")
            uc.emu_stop()
            return
        # out-parameters: a callee given a word-aligned pointer into the function's own frame
        # "stores" a seeded word there, so both runs read back the same value wherever their
        # frames put the local (a sub-word local passed by pointer is the one case where this
        # word can reach a neighbour; see docs/equivalence-tier.md 7.1)
        for j, reg in enumerate(GPR_ARGS):
            v = vals[j] & 0xFFFFFFFF
            if reg not in frame or v & 3 or not (STACK_LO <= v <= STACK_TOP - 4) or \
                    (args is not None and reg not in args):
                continue
            free = [x for x in range(v, v + 4) if not self._save_slot(x)]
            if len(free) < 4:
                continue
            ov = self.ret_ov.get((k, a, reg))
            if ov is None:
                ov = int_value(random.Random((self.seed << 24) ^ (k << 44) ^ a ^ (reg << 8)), self.consts)
            ov &= 0xFFFFFFFF
            word = ov.to_bytes(4, "big")
            for x in free:
                self.stack_buf[x - STACK_LO] = word[x - v]
                self.stack_touched.add(x)
            if self.trace is not None:
                self.trace.append(("ret", (k, a, reg), ov, 4))
        # vector registers: the volatile ones do not survive a call; v1 holds a seeded "result"
        for reg in VEC_VOLATILE:
            self.vr[reg] = vec_poison(reg, k + 1)
        self.vr[1] = vec_value(random.Random((self.seed << 22) ^ (k << 42) ^ a))
        self.v1_own = False
        defs = self.w.analysis.defs_of(a) if image_fn else VOLATILE
        r = random.Random((self.seed << 20) ^ (k << 40) ^ a)
        for reg in VOLATILE & defs:
            if reg == 3:
                rv = self.ret_ov.get((k, a))
                if rv is None:
                    rv = int_value(r, self.consts)
                if image_fn and self.w.return_wide(a):
                    # a caller reads the callee's r3 in full: seed the upper half as well
                    rv = (rv & 0xFFFFFFFF) | (int_value(random.Random((self.seed << 21) ^ (k << 41) ^ a), self.consts)
                                              & 0xFFFFFFFF) << 32
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
        self.vr = list(state.get("vregs") or default_vregs())
        self.v1_own = False          # v1 last written by the function itself (a vector result)
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
        self.marks = []              # (block address, size, len(trace) on entry) while tracking
        if track:
            self._read_hook = uc.hook_add(UC_HOOK_MEM_READ, self._on_read)
            self.trace += [("reg", r, state["regs"][r], 4) for r in GPR_ARGS + (13,)]
            self.trace += [("regh", r, state["regs"][r] >> 32, 4) for r in state.get("wide", ())]
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
            "marks": self.marks,
            "fault_addr": self.fault[1] if self.fault and isinstance(self.fault[1], int) else None,
            "fault": tuple(self.fault) if self.fault else None,      # (access kind, address)
            "fault_pc": pc if self.fault else None,
            "outcome": self.outcome,
            "events": self.events,
            "icount": self.icount,
            "r3": uc.reg_read(P.UC_PPC_REG_3),
            "f1": uc.reg_read(P.UC_PPC_REG_FPR1),
            "delta": self.delta(),
            "v1": self.vr[1] if self.v1_own else None,
            "vnonvol": tuple(self.vr[i] for i in VEC_NONVOL),
            "nonvol": tuple(uc.reg_read(P.UC_PPC_REG_0 + i) & 0xFFFFFFFF for i in (1, 2, 13) + NONVOL_GPR)
            + tuple(uc.reg_read(P.UC_PPC_REG_FPR0 + i) for i in NONVOL_FPR),
        }
        if self.outcome[0] == "trap":
            res["trap_pc"] = self.trap_pc
        return res


# ---------------------------------------------------------------------------
# Trials and comparison

def vec_value(r):
    """A seeded vector argument: four single-precision floats, mostly ordinary numbers."""
    def one():
        k = r.random()
        if k < 0.12:
            return r.choice((0.0, -0.0, 1.0, -1.0, 0.5, 2.0))
        if k < 0.9:
            return _f32(r.uniform(-100.0, 100.0))
        return r.choice((math.inf, -math.inf, math.nan, 1e30, -1e30, 1e-30))
    return _pf(one() for _ in range(4))


def default_vregs(r=None):
    """Initial v0-v127: seeded v1-v13 (arguments), canaries in the callee-saved registers,
    poison elsewhere."""
    vr = [vec_poison(i, 0) for i in range(128)]
    for i in VEC_NONVOL:
        vr[i] = bytes((0xC0, 0xDE, 0x76, i)) * 4
    if r is not None:
        for i in VEC_ARGS:
            vr[i] = vec_value(r)
    return vr


def set_reg(state, kind, reg, v):
    """Set an argument register of a trial state (kind "reg": the low word, or the whole register
    when it is not a 64-bit argument; "regh": the upper word)."""
    regs = state["regs"]
    if kind == "regh":
        regs[reg] = (v & 0xFFFFFFFF) << 32 | (regs[reg] & 0xFFFFFFFF)
    elif reg in state.get("wide", ()):
        regs[reg] = (regs[reg] >> 32) << 32 | (v & 0xFFFFFFFF)
    else:
        regs[reg] = v


def make_state(seed, live, consts, wide=()):
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
    # 64-bit arguments (long long, small structs in a register): the upper word is a second
    # 32-bit value of the same kinds (separate generator: the other draws stay as they were)
    rw = random.Random(seed * 104729 + 71)
    for reg in sorted(wide):
        hi = int_value(rw, consts, argi=reg - 3) & 0xFFFFFFFF
        regs[reg] = hi << 32 | (regs[reg] & 0xFFFFFFFF)
    fill = struct.pack(">I", 0xCDCD0000 | (seed & 0xFFFF)) * ((STACK_TOP - STACK_LO) // 4)
    rr = random.Random(seed * 31 + 5)
    above = page_words(seed, 0x7F0F0000, consts) * ((STACK_HI - STACK_TOP) // PAGE)
    above = bytearray(above)
    # linkage area / home slots stay pattern-filled; stack-passed args follow at +0x50
    return {"regs": regs, "stack": fill + bytes(above), "wide": tuple(sorted(wide)),
            "vregs": default_vregs(random.Random(seed * 15485863 + 29))}, rr


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
        ta, va, args, da, fa, sa, wa, wargs = ea[i]
        tb, vb, _, db, fb, sb, wb, _ = eb[i]
        if ta != tb:
            return f"call #{i + 1}: original calls {world.label(ta)}, candidate calls {world.label(tb)}"
        # stack arguments: only slots the original wrote (an unset slot is not an argument it
        # passes), and only those the callee reads when its code shows which
        slots = world.analysis.stack_arg_slots(ta) if ta in world.func_size else None
        variadic = ta in world.analysis.varargs
        wide = world.analysis.wide_in(ta) if ta in world.func_size else ()
        # a variadic callee's argument count is not known statically: compare only what both pass
        diffj = [k for k in sa if sa[k] != sb.get(k) and (slots is None or k in slots)
                 and not (variadic and k not in sb)]
        if diffj:
            j = min(diffj)
            fmt = lambda b: "unset" if b is None else fmt_frame(b)
            return (f"call #{i + 1} to {world.label(ta)}: stack argument {9 + j} differs: original "
                    f"{fmt(sa.get(j))}, candidate {fmt(sb.get(j))}")
        for j, reg in enumerate(allregs):
            x, y = va[j], vb[j]
            if reg < 32 and reg not in wide:      # the callee reads the low word only
                x, y = x & 0xFFFFFFFF, y & 0xFFFFFFFF
            if reg in fa and reg in fb:
                # an object the original never wrote is a pure out-parameter for it: what the
                # candidate put there first is overwritten by the callee and not compared
                if fa[reg] != fb[reg] and (args is None or reg in args) and \
                        any(x is not None for x in fa[reg]):
                    return (f"call #{i + 1} to {world.label(ta)}: the stack object passed in {regname(reg)} differs "
                            f"(first {STACK_ARG_WINDOW} bytes written by the function: original "
                            f"{fmt_frame(fa[reg])}, candidate {fmt_frame(fb[reg])})")
                continue
            if x == y:
                continue
            if args is not None:
                # an original value that is poison is a register the original never computed (or a
                # callee left behind): the callee's static liveness over-approximates there, and
                # the original's behaviour cannot depend on it, so the candidate's value is free
                if reg in args and not is_poison(reg, va[j]) and not (variadic and is_poison(reg, vb[j])):
                    return (f"call #{i + 1} to {world.label(ta)}: argument {regname(reg)} original {x:#x}, "
                            f"candidate {y:#x}")
            elif not is_poison(reg, va[j]) and not is_poison(reg, vb[j]):
                return (f"call #{i + 1} to {world.label(ta)} (indirect/unknown callee): argument {regname(reg)} "
                        f"original {x:#x}, candidate {y:#x}")
        for j, reg in enumerate(VEC_ARGS):
            if wa[j] == wb[j] or is_vec_poison(wa[j]):
                continue
            if (wargs is not None and reg in wargs) or (wargs is None and not is_vec_poison(wb[j])):
                return (f"call #{i + 1} to {world.label(ta)}: vector argument v{reg} original {wa[j].hex()}, "
                        f"candidate {wb[j].hex()}")
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
            dead = lambda v: STACK_LO <= (v & 0xFFFFFFFF) < STACK_TOP
            if k in ("r3", "r3_64") and dead(A["r3"]) and dead(B["r3"]):
                continue     # both return a pointer into their own, now dead, frame: unusable
            if k == "r3" and (A["r3"] & 0xFFFFFFFF) != (B["r3"] & 0xFFFFFFFF):
                return f"return value r3: original {A['r3'] & 0xFFFFFFFF:#x}, candidate {B['r3'] & 0xFFFFFFFF:#x}"
            if k == "r3_64" and A["r3"] != B["r3"]:
                return f"return value r3 (64-bit): original {A['r3']:#x}, candidate {B['r3']:#x}"
            if k == "f1" and A["f1"] != B["f1"]:
                fa = struct.unpack('>d', struct.pack('>Q', A['f1']))[0]
                fb = struct.unpack('>d', struct.pack('>Q', B['f1']))[0]
                return f"return value f1: original {fa!r} ({A['f1']:#x}), candidate {fb!r} ({B['f1']:#x})"
        if A.get("v1") is not None and A["v1"] != B.get("v1"):
            return (f"return value v1: original {A['v1'].hex()}, candidate "
                    f"{B['v1'].hex() if B.get('v1') else 'not written'}")
        if nonvol and A.get("vnonvol") != B.get("vnonvol"):
            bad = [f"v{r}" for r, x, y in zip(VEC_NONVOL, A["vnonvol"], B["vnonvol"]) if x != y]
            return "callee-saved vector registers not preserved by the candidate: " + ", ".join(bad)
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
    # 32-bit constants built by `lis rX,hi` + `ori rX,rX,lo` (hash keys compared with cmplw):
    # without them, hash switches reach only their default path
    prev = {}
    for _, ins in func.code_words():
        w = ins.word
        op = w >> 26
        if op == 15 and ((w >> 16) & 31) == 0:
            prev[(w >> 21) & 31] = (w & 0xFFFF) << 16
        elif op == 24 and ((w >> 21) & 31) in prev:
            out.add(prev[(w >> 21) & 31] | (w & 0xFFFF))
    # `x == C` as cntlzw(x - C): `addis rX,rY,hi` + `addi rX,rX,lo` (a 32-bit C, e.g. a name hash)
    # or one `addi rX,rY,-C` directly before a `cntlzw` of rX
    words = [ins.word for _, ins in func.code_words()]
    for i in range(len(words) - 1):
        w, n = words[i], words[i + 1]
        rd, ra = (w >> 21) & 31, (w >> 16) & 31
        if w >> 26 == 15 and ra and n >> 26 == 14 and (n >> 21) & 31 == rd and (n >> 16) & 31 == rd:
            out.add(-((sext(w & 0xFFFF, 16) << 16) + sext(n & 0xFFFF, 16)) & 0xFFFFFFFF)
        elif w >> 26 == 14 and ra > 1 and n >> 26 == 31 and (n >> 1) & 0x3FF == 26 and (n >> 21) & 31 == rd:
            out.add(-sext(w & 0xFFFF, 16) & 0xFFFFFFFF)
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
    # trials_requested: the phase layout (random / boundary / guided) depends on the requested
    # count, not on how many trials ran before the early stop, so a re-run needs this number
    res = Result(function=cand_name, address=f"0x{target_addr:08X}", checker=CHECKER_VERSION,
                 seed=seed, trials_requested=trials)
    size = world.func_size.get(target_addr)
    if not size:
        return Result(res, verdict="UNCHECKED", reason="original function size unknown")
    res["size"] = size
    func = world.analysis.func(target_addr)
    fn = linked.function(cand_name)
    if fn is None:
        return Result(res, verdict="UNCHECKED", reason="candidate function not defined in object")
    c_addr, c_size, c_sec = fn
    cfunc = Func(bytes(linked.mem[c_addr - linked.base: c_addr - linked.base + c_size]), c_addr, world.text_range)
    for who, f in (("original", func), ("candidate", cfunc)):
        bad = f.unsupported_vector()
        if bad is not None:
            return Result(res, verdict="UNCHECKED",
                          reason=f"vmx: {who} uses a VMX/VMX128 instruction the checker does not interpret ({bad:08x})")
    if func.has_vector() or cfunc.has_vector():
        res["vmx"] = True
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
    if return_kind == "int" and world.return_wide(target_addr):
        return_kind = "int64"        # a caller reads the upper word of r3
    res["return"] = return_kind
    live = world.analysis.live_in(target_addr)
    res["args"] = sorted(regname(r) for r in live) if live is not None else "unknown"
    wide = world.analysis.wide_in(target_addr)
    if live is not None:
        wide &= live
    if wide:
        res["args64"] = sorted(regname(r) for r in wide)
    consts = code_consts(func)
    strides = code_strides(func)
    special = {}
    for f in (func, cfunc):
        for a, ins in f.code_words():
            if ins.kind in ("mftb", "dcbz") or (ins.kind == "vec" and ins.vec):
                special[a] = ins.kind
    for lo, hi, _ in linked.text_ranges:        # vector code of the candidate's local helpers
        for a in range(lo, hi, 4):
            w = struct.unpack(">I", bytes(linked.mem[a - linked.base: a - linked.base + 4]))[0]
            if a not in special and decode(w, a).vec:
                special[a] = "vec"
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
    # statically unreachable blocks are not coverage targets (not applied to SEH functions,
    # whose __except blocks are entered by the unwinder rather than by a branch)
    dead = set() if world.label(target_addr - 8).startswith("except_data") else set(func.dead_blocks())
    blocks = [b for b in func.block_addrs() if b not in dead]
    if dead:
        res["dead_blocks"] = [f"0x{b:08X}" for b in sorted(dead)]
    covered = set()
    fault_seen = {}      # block -> faulting trials of the original that reached it (fault_blocks)
    corpus = []          # (run seed, state, trace) of trials that reached new blocks
    rand_end = max(40, trials * 2 // 5)
    boundary = None      # (register, constant) pairs for the boundary phase
    pair_plans = {}      # corpus index -> remaining pointer-pair mutations of that trial
    front = {"done": set(), "plans": [], "stamp": None}   # frontier mutations (frontier_mutation)

    def note_fault(state, s, A):
        """A discarded trial: when the original took a null-pointer fault, note the blocks only
        such trials reach and whether the candidate faults the same way (see fault_blocks below)."""
        fa = A.get("fault")
        if A["outcome"][0] != "fault" or not fa or not isinstance(fa[1], int) or fa[1] >= FAULT_NULL_PAGE:
            return
        hit = [b for b in blocks if any(a <= b < a + sz for a, sz in A["run_cov"])
               and not any(a <= b < a + sz for a, sz in cov)]
        if not hit:
            return
        B = machine.run(c_addr, c_local, state, s, consts, max(4 * A["icount"] + 5000, 20000), None)
        same = B.get("fault") == fa and compare(world, A, B, return_kind) is None
        for b in hit:
            rec = fault_seen.setdefault(b, {"pcs": set(), "faults": set(), "agree": 0, "differ": 0, "inputs": []})
            rec["pcs"].add(A["fault_pc"])
            rec["faults"].add(fa)
            rec["agree" if same else "differ"] += 1
            if len(rec["inputs"]) < 4:
                rec["inputs"].append((s, state))

    for t in range(trials):
        s = seed * 1_000_003 + t
        if t == rand_end and corpus:
            # boundary phase: each integer argument set to each of the code's comparison constants
            # (+-1), on top of a valid trial, so x == limit / x == limit+1 paths are run on purpose
            br = random.Random(seed ^ 0xB0B)
            boundary = [(reg, c & 0xFFFFFFFF) for reg in GPR_ARGS if live is None or reg in live
                        for c in consts]
            br.shuffle(boundary)
            boundary = boundary[: trials // 3]
        if t < rand_end or not corpus:
            state, _ = make_state(s, live, consts, wide)
        elif boundary and t - rand_end < len(boundary):
            reg, c = boundary[t - rand_end]
            ps, pstate = corpus[(t - rand_end) % len(corpus)][:2]
            state = dict(pstate, regs=dict(pstate["regs"]))
            set_reg(state, "reg", reg, c)
            s = ps
        elif (fm := frontier_mutation(func, cov, corpus, front, dead) if (t - rand_end) % 4 in (1, 2) else None) is not None:
            # frontier trial (two of four trials of the guided phase while plans remain): a value
            # read just before a conditional branch whose other side has not been reached is set to
            # what the branch compares against (see frontier_plans)
            ci, kind, key, size, v = fm
            ps, pstate = corpus[ci][:2]
            state = dict(pstate, regs=dict(pstate["regs"]), mem_ov=dict(pstate.get("mem_ov") or {}),
                         ret_ov=dict(pstate.get("ret_ov") or {}))
            if kind in ("reg", "regh"):
                set_reg(state, kind, key, v)
            elif kind == "mem":
                state["mem_ov"][key] = v.to_bytes(size, "big")
            else:
                state["ret_ov"][key] = v
            s = ps
        elif (pm := pair_mutation(corpus, pair_plans, live, strides) if (t - rand_end) % 4 == 3 else None) is not None:
            # pointer-pair trial (every fourth trial of the guided phase while plans remain): one
            # pointer the function read is set to a neighbouring pointer plus 4*k, so a begin/end
            # loop runs k steps and leaves through its own exit instead of walking off the heap
            ps, pstate, sets = pm
            state = dict(pstate, regs=dict(pstate["regs"]), mem_ov=dict(pstate.get("mem_ov") or {}))
            for kind, key, v in ([sets] if isinstance(sets, tuple) else sets):
                if kind == "reg":
                    set_reg(state, kind, key, v)
                else:
                    state["mem_ov"][key] = struct.pack(">I", v)
            s = ps
        else:
            # coverage-guided phase: take a trial that reached new blocks and replace one value it
            # read (an argument, a loaded byte/halfword/word or a call's return value)
            mr = random.Random(s ^ 0x5EED)
            ps, pstate, ptrace = corpus[min(len(corpus) - 1, int(len(corpus) * mr.random() ** 0.5))][:3]
            state = dict(pstate, regs=dict(pstate["regs"]), mem_ov=dict(pstate.get("mem_ov") or {}),
                         ret_ov=dict(pstate.get("ret_ov") or {}))
            for _ in range(1 + (mr.random() < 0.3)):
                kind, key, old, size = mr.choice(ptrace)
                x = mr.random()
                v = (old + mr.choice((-1, 1))) if x < 0.2 else 0 if x < 0.3 else 1 if x < 0.4 else \
                    (mr.choice(consts) if consts and x < 0.7 else int_value(mr, consts))
                v &= (1 << (8 * size)) - 1
                if kind in ("reg", "regh"):
                    set_reg(state, kind, key, v)
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
            note_fault(state, s, A)
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
                    corpus.append((s, state, T["trace"], T["marks"]))
        diff = compare(world, A, B, return_kind)
        if diff:
            first_diff = (s, state, diff, A, B)
            break
        if time_budget and time.time() - t0 > time_budget:
            break
        if t >= 60 and valid >= min_valid and t - last_new > max(150, trials // 4) and \
                t >= rand_end + len(boundary or ()):
            # coverage stopped growing: stop early once every block has been seen
            covered = {b for b in blocks if any(a <= b < a + sz for a, sz in cov)}
            if len(covered) == len(blocks):
                break
    covered = {b for b in blocks if any(a <= b < a + sz for a, sz in cov)}
    if first_diff is None:
        # a fault path seen fewer than FAULT_MIN times: re-run its inputs with one value changed
        for b in blocks:
            rec = fault_seen.get(b)
            if b in covered or rec is None or rec["differ"] or rec["agree"] >= FAULT_MIN:
                continue
            for n, (ps, pstate) in enumerate(list(rec["inputs"])):
                ptrace = machine.run(target_addr, o_local, pstate, ps, consts, 200_000, None, track=True)["trace"]
                mr = random.Random(ps ^ 0xFA17 ^ n)
                for _ in range(FAULT_EXTRA if ptrace else 0):
                    state = dict(pstate, regs=dict(pstate["regs"]), mem_ov=dict(pstate.get("mem_ov") or {}),
                                 ret_ov=dict(pstate.get("ret_ov") or {}))
                    kind, key, old, size = mr.choice(ptrace)
                    v = (old + mr.choice((-1, 1)) if mr.random() < 0.5 else int_value(mr, consts)) & ((1 << (8 * size)) - 1)
                    if kind in ("reg", "regh"):
                        set_reg(state, kind, key, v)
                    elif kind == "mem":
                        state["mem_ov"][key] = v.to_bytes(size, "big")
                    else:
                        state["ret_ov"][key] = v
                    state, A = run_fixing(machine, world, target_addr, o_local, state, ps, consts, set(cov))
                    note_fault(state, ps, A)
    # Fault blocks: a block no valid trial reaches counts as covered when every trial that
    # reached it ended in the same null-pointer fault of the original (one instruction, one
    # address and access kind; at least FAULT_MIN trials) and the candidate, run on each of
    # those inputs, made the same calls and memory writes and then faulted at the same address
    # with the same access kind. Such a path has no behaviour beyond the fault to compare.
    fault_blocks = []
    for b in blocks:
        rec = fault_seen.get(b)
        if b in covered or rec is None:
            continue
        if rec["agree"] >= FAULT_MIN and not rec["differ"] and len(rec["pcs"]) == 1 and len(rec["faults"]) == 1:
            (kind, addr), = rec["faults"]
            fault_blocks.append({"block": f"0x{b:08X}", "fault_pc": f"0x{next(iter(rec['pcs'])):08X}",
                                 "address": f"0x{addr:X}", "access": str(kind), "trials": rec["agree"]})
            covered.add(b)
    if fault_blocks:
        res["fault_blocks"] = fault_blocks
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


FRONT_WINDOW = 6     # values read before the branch's block that are also tried
FRONT_PARENTS = 3    # corpus trials used per frontier branch


def branch_compare(func: Func, k):
    """Constants worth trying for the values block k reads, as (flag constants, branch
    constants), each with its neighbours. Flag constants: C of an `x == C` test computed as
    cntlzw(x - C), whose result may be branched on much later. Branch constants, for the
    conditional branch ending the block: the immediate of the compare before it, or the constant
    a register operand was loaded with in the block (`li`, `lis` + `ori`/`addi`)."""
    s, e = func.blocks[k]
    known, out, sub = {}, [], []
    for i in range(s, e - 1):
        w = func.insns[i].word
        op, rd, ra, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
        if op in (10, 11):
            out = [imm if op == 10 else sext(imm, 16)]
        elif op == 31 and (w >> 1) & 0x3FF in (0, 32):
            out = [known[r] for r in (ra, (w >> 11) & 31) if r in known]
        elif op == 15 and ra and i + 1 < e and func.insns[i + 1].word >> 16 == (14 << 10) | (rd << 5) | rd:
            # x - C built by addis + addi (tested with cntlzw): C itself
            sub.append(-((sext(imm, 16) << 16) + sext(func.insns[i + 1].word & 0xFFFF, 16)) & 0xFFFFFFFF)
        val = None
        if op in (14, 15) and (ra == 0 or ra in known):
            val = (known.get(ra, 0) + (sext(imm, 16) << (16 if op == 15 else 0))) & 0xFFFFFFFF
        elif op == 24 and rd in known:
            val, rd = known[rd] | imm, ra
        for r in func.insns[i].writes:
            known.pop(r, None)
        if val is not None:
            known[rd] = val
    return [v + d for v in sub for d in (0, 1, -1)], [v + d for v in out for d in (0, 1, -1)]


def frontier_plans(func: Func, cov, corpus, done, dead=()):
    """Mutations aimed at blocks no trial has reached. A frontier is a reached block ending in a
    conditional branch with an unreached successor (or, while any block is unreached, a block
    computing an `x == C` flag, for which only C is tried). For each corpus trial that ran the branch
    (newest first), every value it read in that block or shortly before (an argument, a loaded
    byte/halfword/word, a call's return value) is set in turn to the compare's constant, to
    zero/non-zero and to the other values read there (so `a == b` can hold). Returns
    [(priority, corpus index, kind, key, size, value)]; each mutation is listed once."""
    hit = lambda b: any(a <= b < a + sz for a, sz in cov)
    addr = func.block_addrs()
    reached = [hit(a) and a not in dead for a in addr]
    plans = []
    if all(reached[k] or addr[k] in dead for k in range(len(addr))):
        return plans
    for k, nxt in enumerate(func.succ()):
        if not reached[k]:
            continue
        flag, consts = branch_compare(func, k)
        frontier = len(nxt) >= 2 and not all(reached[j] or addr[j] in dead for j in nxt)
        if not frontier and not flag:
            continue             # (a flag block is tried while any block is unreached)
        consts = flag + consts if frontier else flag
        br = func.base + 4 * (func.blocks[k][1] - 1)
        used = 0
        for ci in range(len(corpus) - 1, -1, -1):
            if used >= FRONT_PARENTS:
                break
            trace, marks = corpus[ci][2], corpus[ci][3]
            at = [i for i, (a, sz, _) in enumerate(marks) if a <= br < a + sz]
            if not at or (br, ci) in done:
                continue
            done.add((br, ci))
            used += 1
            i = at[-1]
            end = marks[i + 1][2] if i + 1 < len(marks) else len(trace)
            seen, window = set(), []
            for ent in reversed(trace[max(0, marks[i][2] - FRONT_WINDOW):end]):
                if (ent[0], ent[1]) not in seen and not (ent[0] == "reg" and ent[1] == 13):
                    seen.add((ent[0], ent[1]))
                    window.append(ent)
            for rank, (kind, key, old, size) in enumerate(window):
                mask = (1 << (8 * size)) - 1
                old &= mask
                vals = [c & mask for c in consts]
                if frontier and not (size == 4 and HEAP_LO <= old < HEAP_HI):   # a pointer: only the constants
                    vals += [0 if old else 1] + [o[2] & mask for o in window if o[3] == size][:4]
                    vals += [(old + 1) & mask, (old - 1) & mask]
                for n, v in enumerate(vals):
                    if v != old and (ci, kind, key, v) not in done:
                        done.add((ci, kind, key, v))
                        plans.append((n + rank, ci, kind, key, size, v))
    return plans


def frontier_mutation(func, cov, corpus, front, dead=()):
    """Next frontier mutation, or None. Plans are rebuilt when coverage or the corpus grew."""
    stamp = (len(cov), len(corpus))
    if front["stamp"] != stamp:
        front["stamp"] = stamp
        front["plans"] = sorted(front["plans"] + frontier_plans(func, cov, corpus, front["done"], dead),
                                key=lambda p: p[0])     # stable: most promising first
    return front["plans"].pop(0)[1:] if front["plans"] else None


PAIR_STEPS = (1, 2, 3, 4, 6, 8, 5, 7)   # element counts tried for a begin/end pointer pair
PAIR_FRESH_STEPS = (1, 2, 3)             # element counts tried with a fresh begin pointer
PAIR_NEAR = 8                           # two loaded words this close are taken as one pair


def code_strides(func: Func, most=4):
    """Element sizes the code steps or divides by: the immediate of `addi rD,rA,+-C` (rA no stack
    or base register) and of an `li rX,C` whose register is the divisor of a divw/divwu, for
    C = 8..0x1000 and a multiple of 4. The most frequent `most` values, used as begin/end spans
    (pointer_pairs, fresh_pairs) so a loop over 0x1c-byte elements gets a whole element count."""
    words = [ins.word for _, ins in func.code_words()]
    divisors = {(w >> 11) & 31 for w in words if w >> 26 == 31 and (w >> 1) & 0x1FF in (459, 491)}
    count = {}
    for w in words:
        if w >> 26 != 14:
            continue
        rd, ra, c = (w >> 21) & 31, (w >> 16) & 31, abs(sext(w & 0xFFFF, 16))
        if (rd in divisors if ra == 0 else ra not in (1, 2, 13)) and 8 <= c <= 0x1000 and not c & 3:
            count[c] = count.get(c, 0) + 1
    return sorted(count, key=lambda c: (-count[c], c))[:most]


STRIDE_COUNTS = (1, 2, 3)               # element counts tried per code_strides() element size


def pointer_pairs(trace, live=None, spans=None):
    """Mutations that turn two values a trial read into a begin/end pair: (kind, key, value)
    with value = another read pointer + 4*k. Candidates are two words loaded from addresses at
    most PAIR_NEAR bytes apart (the first/last fields of a container) or two argument registers
    (a first/last argument pair); the source must be a heap pointer. Both directions are
    listed, so loops that walk down are covered too. Ordered by k, small counts first."""
    seen, ents = set(), []
    for kind, key, old, size in trace:
        if size != 4 or kind not in ("reg", "mem") or (kind, key) in seen:
            continue
        if kind == "reg" and (key not in GPR_ARGS or (live is not None and key not in live)):
            continue
        seen.add((kind, key))
        ents.append((kind, key, old & 0xFFFFFFFF))
    pairs = []
    for dk, dkey, dold in ents:
        for sk, skey, sold in ents:
            if sk != dk or skey == dkey or not HEAP_LO <= sold < HEAP_HI - 0x1000 or sold & 3:
                continue
            if dk == "mem" and abs(dkey - skey) > PAIR_NEAR:
                continue
            pairs.append((dk, dkey, dold, sold))
    spans = [4 * k for k in PAIR_STEPS] if spans is None else spans
    return [(dk, dkey, (sold + d) & 0xFFFFFFFF) for d in spans for dk, dkey, dold, sold in pairs
            if (sold + d) & 0xFFFFFFFF != dold]


def fresh_pairs(trace, spans=None):
    """Two-word mutations [(kind, key, value), (kind, key, value)] for two neighbouring loaded
    words of which the first is no usable pointer (a random word, or null: the empty
    container): begin becomes a fresh heap buffer and end becomes begin + 4*k, so a loop over a
    small positive element count runs at all."""
    seen, ents = set(), []
    for kind, key, old, size in trace:
        if size == 4 and kind == "mem" and key not in seen:
            seen.add(key)
            ents.append((key, old & 0xFFFFFFFF))
    good = lambda v: HEAP_LO <= v < HEAP_HI - 0x1000 and not v & 3
    near = [(lo, hi) for lo, lold in ents if not good(lold) for hi, _ in ents if 0 < hi - lo <= PAIR_NEAR]
    out = []
    for d in ([4 * k for k in PAIR_FRESH_STEPS] if spans is None else spans):
        for lo, hi in near:
            base = RANDPTR_LO + (((lo * 2654435761) >> 4) % ((HEAP_HI - RANDPTR_LO - 0x40000) >> 4) << 4)
            out.append([("mem", lo, base), ("mem", hi, base + d)])
    return out


def pair_mutation(corpus, plans, live=None, strides=()):
    """Next pointer-pair mutation, newest corpus trial first: (seed, state, (kind, key, value)
    or a fresh_pairs() list),
    or None when every plan is used up."""
    for ci in range(len(corpus) - 1, -1, -1):
        if ci not in plans:
            plans[ci] = pointer_pairs(corpus[ci][2], live) + fresh_pairs(corpus[ci][2])
            if strides:      # after the 4*k plans: whole element counts of the code's own strides
                spans = [c * n for n in STRIDE_COUNTS for c in strides]
                plans[ci] += pointer_pairs(corpus[ci][2], live, spans) + fresh_pairs(corpus[ci][2], spans)
        if plans[ci]:
            return corpus[ci][0], corpus[ci][1], plans[ci].pop(0)
    return None


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
        ptr = RANDPTR_LO + ((((s * 2654435761) ^ (it * 40503) ^ F) % ((HEAP_HI - RANDPTR_LO - 0x40000) >> 4)) << 4)
        if src is None:
            # the address is no single bad pointer plus a displacement but a sum (base + index *
            # size + table offset ...): make the most recent large non-pointer word that was
            # loaded or returned a small number and try again, one word per round
            for ent in reversed(T["trace"]):
                v = ent[2] & 0xFFFFFFFF
                if ent[3] == 4 and ent[0] in ("mem", "ret") and ent[1] not in done and v > 0xFFFF and \
                        not valid_ptr(world, v):
                    src, ptr = ent, (s + it) % 3
                    break
        if src is None:
            break
        state = dict(state, regs=dict(state["regs"]), mem_ov=dict(state.get("mem_ov") or {}),
                     ret_ov=dict(state.get("ret_ov") or {}))
        kind, key = src[0], src[1]
        if kind in ("reg", "regh"):
            set_reg(state, kind, key, ptr)
        elif kind == "mem":
            state["mem_ov"][key] = struct.pack(">I", ptr)
        else:
            state["ret_ov"][key] = ptr
    if cov is not None and A["outcome"][0] not in ("fault", "limit"):
        cov |= tmp
    A["run_cov"] = tmp
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
            if reg in state.get("wide", ()):
                args.append(f"{regname(reg)}={v:#018x}")
                continue
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
    for fb in r.get("fault_blocks", ()):
        head += (f"\n  fault block {fb['block']}: counted as covered, original and candidate both fault at "
                 f"{fb['address']} (original pc {fb['fault_pc']}) in {fb['trials']} trial(s)")
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
    ap.add_argument("--max-calls", type=int, default=MAX_EVENTS,
                    help="intercepted calls per run before a trial is discarded (default %(default)s)")
    ap.add_argument("--time", type=float, default=60.0, help="time budget per function in seconds (0: no limit, fully reproducible)")
    ap.add_argument("--json", type=Path, help="write the evidence records to this file")
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args()
    if not HAVE_UNICORN:
        print("UNCHECKED: unicorn is not installed (pip install unicorn)")
        return 2
    world = load_world()
    get_machine(world).max_events = a.max_calls
    maps = []
    for m in a.mappings:
        name, _, target = m.partition("=")
        maps.append((name, resolve_target(world, target)))
    import fn_check
    fn_check.exit_on_sigterm()      # a timed-out run removes its work/fncheck-* scratch as well
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
