# The "equivalent" tier: behaviour checked by running original and candidate side by side

EQ1, 2026-11-14. Tool: `tools/fn_equiv.py` (checker version string `fn_equiv/1`), tests:
`tests/test_fn_equiv.py`. Nothing in `src/`, `config/` or `tools/matching.py` was changed and
`tools/matching.py` was not run. This document describes the checker, the evidence that it
works, what it measured on the remaining code, and how the tier should enter the project.
Section 8 lists the inputs and the commands that reproduce every number.

## 1. Why a second tier

"Matched" means our C compiles to the original bytes. That standard stops being reachable on
mid-size functions: the logic is right, but register choice, instruction order, frame layout and
dead copies differ, and no source form or flag reproduces them (see the GA*/LB*/D2G
`work/army/*.failed.md` notes). The owner's goal is a native build with readable, portable C, so
behaviour is what matters. "Equivalent" means: the candidate function, compiled by our compiler,
was executed next to the original function from the same seeded inputs many times, and every
observable effect agreed, with most of the original's basic blocks exercised.

The two tiers are reported separately and never merged (section 6).

## 2. How the checker works

```sh
python3 tools/fn_equiv.py src/xbox360/foo.c ts4_name=0x8861C648 [more=0x...] [--flags /O1]
        [--trials 400] [--seed 1] [--min-coverage 0.9] [--json evidence.json]
```

Same interface as `tools/fn_check.py`; it reuses its compile step (`fn_check.compile_candidate`,
base flags `/O2 /Oi`) and `TS4_MATCHING_DIR` (default: the highest `work/matching-bNN` whose
`work/bNN.log` has a "Matched" line; b44 for every number in this document).

**Emulator.** Unicorn 2.1.4 (`pip install unicorn`), PPC64 big-endian, MSR = SF|FP (64-bit
mode, floating point on). Two Unicorn quirks matter: `ctl_set_cpu_model` indexes the 32-bit CPU
table in PPC64 mode (a bug: every "PPC64" model id selects a 32-bit 4xx/6xx core, on which
`extsw`, `ld`, `std`, `rldicl` ... are illegal), and the default model (POWER10) faults every
instruction fetch through its hash MMU (exception 70, HISI) unless the TLB is switched to
Unicorn's virtual mode (`ctl_set_tlb_mode(UC_TLB_VIRTUAL)`). With the default model and the
virtual TLB, the integer, 64-bit, load/store, branch and FPU instructions this code uses run
(including `fsel`, `frsqrte`, `fres`, `fctiwz`, `fcfid`, `lwarx/stwcx.`, `mfmsr/mtmsrd`).
Xenon specifics handled by the checker: `dcbz` (32 bytes on Xenon, 128 on POWER) and `dcbz128`
are emulated, `mftb` returns a deterministic counter, effective addresses are 32-bit (a 64-bit
EA with upper bits set aliases the low page, as on hardware) while record forms set CR0 from the
64-bit result (Xenia's model). **VMX/VMX128 is not supported** (QEMU decodes opcode 4/5/6 as
AltiVec or not at all, so results would be wrong, not just missing): any function whose original
or candidate contains a VMX/VMX128 instruction, or that calls `__savevmx`/`__restvmx`, is reported
`UNCHECKED (vmx)` before anything runs. `fres`/`frsqrte` estimates follow POWER, not Xenon; both
sides run on the same emulator, so this only matters for absolute values.

**Address space.** The decompressed image `orig/54540859/Swing_DLL.dll` is mapped read/write at
0x88000000. The candidate object is linked at 0x89000000 (inside `bl` range of the whole image):
its relocations are resolved by name against `symbols.txt` (the matching split's and the
committed one), `fn_/lbl_` names and `_XXXXXXXX` address suffixes; a candidate symbol that is a
real image symbol (also a static whose name integration would give to a placeholder) resolves to
the image address, and so does a function the candidate's own file defines under a name ending in
an image function's address (a context copy of a callee, common in near-miss drafts), so calls land on the same callee addresses as the original's and data
references read the same image bytes. When the candidate has exactly the original's relocation
layout, names it gives to placeholders are mapped from the original's relocations (what
`fn_check` reports as RENAME). Unresolved names make the function `UNCHECKED`.

**Inputs per trial (identical for both runs).**
- Argument registers: the r3-r10/f1-f13 the *original* reads before writing (static liveness over
  its CFG, calls included: a callee's own argument liveness, jump tables followed, register
  save/restore helpers modelled; a callee whose liveness cannot be computed, such as a CRT chain
  ending in an import thunk or a recursion cycle, is assumed to read r3 only, because assuming
  r3-r10 made every caller of `qsort` appear to pass its stale temporaries as arguments). Integers are pointers into argument buffers (55%), 0, 1-15,
  16-64, the original's comparison constants +-1, -1 or random words; floats include 0, -0, +-1,
  NaN, +-inf, +-1e30, 1e-30 and random values. Other volatile registers hold poison values
  (0xBAD000xx), r14-r31/f14-f31 hold canaries, r13 points into the heap.
- Memory: the heap region 0x40000000-0x6FFFFFFF and the image's uninitialised data (BSS tail of
  `.data`, `BINKBSS`) are materialised lazily, one 4 KB page at a time, from the trial seed.
  A page is random bytes (12%), ASCII text (10%) or a word mix (78%: 30% pointers back into the
  heap, 22% zero, small numbers, comparison constants, -1, common float bit patterns, random
  words). So every pointer chain resolves to fresh buffers on demand and both runs see the same
  bytes. Initialised `.data`/`.rdata` hold the file's values.
- Lazy pointer resolution: when the original faults, the checker re-runs it with read tracking,
  finds the most recent argument, loaded word or call return value from which the faulting
  address was derived (fault address minus value in [-0x8000, 0x10000), value not a valid
  pointer), replaces that value with a fresh heap pointer and retries (up to 24 times). The final
  overrides become part of the trial input for both runs. This turns "global singleton is NULL in
  the file" and "field holds a small integer" into real paths instead of discarded trials.
- Stack: 1 MB, r1 = 0x7F0F0000; the caller's area above r1 is seeded (stack-passed arguments),
  the function's own frame is filled with one repeated pattern word, so an uninitialised slot
  reads the same in both runs wherever the frame puts it.

**Calls.** The callee is never executed. Every transfer out of the function (direct `bl`, a tail
`b`, `bctrl` through a function pointer, including pointers into the heap) is intercepted in a
basic-block hook and recorded as an event: callee address; the argument registers the callee
reads (static liveness of the image function; for an indirect or unanalysable callee, r3 plus
every r4-r10/f1-f13 whose last write in the straight-line code before the original's call site
is not read again before the call, so vtable and address temporaries are not mistaken for
arguments); arguments 9 and up, which live in the caller's frame at r1+0x54 (8-byte slots inside the
function's frame, save slots excluded; a slot is compared when the original wrote it and the
callee reads it, which is known from the callee's own loads above its frame, or for every slot
the original wrote when the callee's code does not tell); objects on the stack passed by pointer (their first word as written by the function, not their address,
which depends on frame layout; bytes holding a saved LR or callee-saved register are masked); and
the memory delta so far. A callee given a pointer into the function's own frame then stores a
seeded word there (out-parameter model: `n = f(L, &len)`), into the bytes of that word the
function has not written itself, so the value read back is the same in both runs wherever the
two frames put the local, and a neighbouring local is never overwritten. A recursive call is recognised (a
`bl` from the function back to its own entry) and intercepted like any other call. The callee then "returns": r3 and f1 get seeded values (a
function of seed, call index and callee address, so both runs get the same values while their
call sequences agree), and exactly the volatile registers the callee transitively writes are
clobbered with poison. Registers the callee leaves alone keep their values, so an LTCG-compiled
original that keeps r8 live across a call still works. `memcpy`, `memset` and `memmove` are
emulated natively without an event (a copy one side inlines and the other calls compares by
effect). `__savegprlr_*`, `__restgprlr_*`, `__savefpr_*`, `__restfpr_*` and `_RtlCheckStack*`
run for real.

**Observables compared, in this order.** (1) the call sequence: callee, argument values (32-bit
for integer registers, raw bits for floats; an argument register in which the original passes a
poison value, i.e. one it never computed or one a previous callee left behind, is not compared,
because the callee's static liveness over-approximates there, typically through an unanalysable
error-handler call), stack objects passed, memory delta at each call;
(2) the outcome (return, trap, fault, did not finish); (3) the final memory delta: every byte
outside the stack whose value changed, by absolute address (heap, image globals, BSS); (4) the
return value: r3 (low 32 bits, or 64 for a 64-bit return type) and/or f1, chosen from how the
image's direct callers use them (strong: a caller reads r3/f1; then the candidate's declared
return type; then a caller returning r3/f1 untouched; a function that never writes r3 and never
calls returns nothing; otherwise r3); (5) callee-saved registers r1, r2, r13, r14-r31, f14-f31.

**Trials.** Seeds `seed*1000003 + t`. The first 40% of the trials (at least 40) are drawn from
the distributions above. Then comes a boundary phase (up to a third of the trials): each integer
argument register in turn is set to each of the original's comparison constants and their
neighbours (immediates of `cmpwi`/`cmplwi`/... +-1, 0, 1, jump-table case values), on top of a
valid earlier trial, so `x == limit` and `x == limit + 1` are run on purpose rather than by luck.
The rest are coverage-guided: the checker keeps every trial that
reached a new block of the original, takes one of them, replaces one or two of the values the
original read in it (an argument, a loaded byte/halfword/word/doubleword, a call's return value) by a
neighbour, 0, 1, a comparison constant or a fresh random value, and runs that as a new trial;
each choice is a function of the trial seed, so the sequence is reproducible. Only values read
from memory both programs share and may write (heap pages, `.data`, BSS) are ever replaced, by
this phase or by pointer resolution: read-only data (`.text`, `.rdata`: jump tables, float
literal pools, string constants) sits at a different address in the candidate, so changing the
original's copy would make the two runs see different inputs. (An earlier version did this and
reported 8 byte-matched functions as DIFFERENT; see 3.1.) The comparison constants include each
jump table's case values (the `addi rX, rY, -bias` before the `bctr` plus 0..n-1), so switches
are entered on every case. A trial in which the original still faults after pointer
resolution, or runs past 200,000 instructions, is discarded (the input breaks the original's
precondition); a candidate that faults where the original did not, or needs more than four times
the original's instruction count, is DIFFERENT. Default 400 trials and 60 s per function; it stops
early once the boundary phase is done, every block has been reached and coverage stopped growing.

**Coverage.** Basic blocks of the original (leaders: branch targets, instructions after a
branch, jump-table targets; table words excluded). A block counts as covered when a valid trial
executed its first instruction (Unicorn translation-block hook).

**Verdicts.** `EQUIVALENT`: no difference, at least 30 valid trials, block coverage >= 90%
(`--min-coverage`). `DIFFERENT`: the first differing trial, with the arguments simplified (each
set to 0/1 or 0.0/1.0 while the difference persists) and both runs' call lists. `UNCHECKED`:
VMX/VMX128, unresolved symbol, unsupported relocation or instruction, too few valid trials, or
coverage below the threshold. Every result also carries `abi_hazard`: volatile registers the
candidate writes, the original leaves alone, and an image caller reads after the call (see 7.3).

The 90% threshold: in the ground-truth run over byte-matched functions (section 3.1) the median
function reaches full coverage; by size, 145 of 150 functions under 256 bytes reach 90%, 32 of 56
at 256-512 bytes, 10 of 33 at 512-1024 and 10 of 60 above 1 KB. The unreached blocks are mostly
error paths behind specific values (a magic number, a full table, a negative size, a callee
returning a particular status) and, in large parsers, states that need a long, structured input.
Below 90% too much code would be untested; raising it to 100% would reject correct functions for
one unreachable `return -1`. The uncovered block addresses are stored with every result, so a
reviewer can see what was not exercised.

## 3. Validation against ground truth

### 3.1 Matched functions must come out EQUIVALENT

**Sample.** 300 byte-matched functions (215 source files), drawn from the matched list of
`work/matching-b45` stratified by size: 60 of 0-64 bytes, 90 of 64-256, 57 of 256-512, 33 of
512-1024, 47 of 1024-2048, 13 above 2 KB. Units built with /LTCG were excluded (their objects are
not what `fn_check` compiles); per-file flags come from the compiler-flag exceptions. Each function
was checked against itself compiled from its committed source: the candidate is byte-identical up
to relocations, so any DIFFERENT is a checker bug. 300 trials, 40 s budget, seed 1.

| size (bytes) | n | EQUIVALENT | DIFFERENT | UNCHECKED | median coverage |
|---|---|---|---|---|---|
| 0-64 | 60 | 58 | 0 | 2 | 100% |
| 64-256 | 90 | 87 | 0 | 3 | 100% |
| 256-512 | 57 | 29 | 0 | 28 | 94% |
| 512-1024 | 33 | 8 | 0 | 25 | 80% |
| 1024-2048 | 47 | 3 | 0 | 44 | 52% |
| 2048+ | 13 | 5 | 0 | 8 | 49% |
| all | 300 | 190 (45,480 bytes) | **0** | 110 (104,432 bytes) | 100% |

UNCHECKED reasons: coverage below 90% (92), too few valid trials (17: the original faults or runs
past the instruction limit on almost every generated input; e.g. `lua3_luaG_errormsg` longjmps,
the Huffman/jpeg table builders loop over seeded counts), VMX (1). No result had a non-empty
`abi_hazard`. Median 152 valid trials and 4.8 s per function; the whole run took 50 CPU-minutes.
Trials are deterministic, but the per-function time budget (40 s here) cuts long functions short
by wall-clock, so on a loaded machine a large function can end with fewer trials. Between runs
this moved two functions near the threshold from EQUIVALENT to UNCHECKED. It never produced a
DIFFERENT. For a reproducible verdict, use `--time 0`, which means trials only.

**Checker bugs this found and fixed** (each was a DIFFERENT on a matched function in an earlier
run): (1) recursion executed the original's own body instead of intercepting the call, while the
candidate's recursive `bl` went to the image (2 functions); (2) temporaries used to compute an
indirect call's target were compared as arguments (2); (3) the coverage-guided phase and the
pointer fixer replaced values read from *read-only* image data (jump tables, float literal pools),
which the candidate keeps at its own address, so the two runs saw different inputs (8: jump-table
switches, a float constant, a hash table); (4) callee liveness over-approximation through
unanalysable CRT chains made stale temporaries count as call arguments; (5) a candidate file that
defined a context copy of a callee called that copy instead of the image function; (6) the
decoder counted `mr r8, r8` (`or rX,rX,rX`, a no-op hint in the CRT heap code) as a read, so every
caller of `free` appeared to pass r8; (7) a pure out-parameter the candidate pre-initialised and
the original did not was reported; (8) stack-argument slots beyond the frame, or slots that the
original never wrote, were compared, as were varargs registers (see 7.1). Items 4-8 gave false
DIFFERENT verdicts in the near-miss and asm2c runs, found by reading every DIFFERENT report of
the sample. After (3) was fixed, the run above has no DIFFERENT. Its coverage figures
are honest. With the bug, the mutated jump tables had inflated coverage on switch functions, and
that is why the fix also seeds jump-table case values.


### 3.2 Planted mutations must come out DIFFERENT

`work/eq1/mutate.py` (scratch) takes the matched functions that came out EQUIVALENT (at least
40 bytes, with a literal body in the source; 80 functions, deterministic shuffle, seed 7) and, per
function and operator, plants one mutation in a copy of the source: **const** (a literal n ->
n+1, 0 -> 1), **cmp** (`==`/`!=`, `<`/`>=`, `>`/`<=` flipped), **swap** (operands of `-` or `/`
exchanged), **store** (an assignment through `->`, `*` or `[]` deleted), **bound** (a `for`/`while`
condition `<` -> `<=` and so on). Up to 4 sites per operator are tried until one compiles and changes
the function's code bytes. A mutant that does not compile or that the compiler optimises away
is not a test.

| operator | mutants | DIFFERENT | missed |
|---|---|---|---|
| const | 78 | 73 | 5 |
| cmp | 32 | 32 | 0 |
| store | 27 | 26 | 1 |
| swap | 6 | 5 | 1 |
| bound | 6 | 5 | 1 |
| all | 149 (78 functions) | **141 (94.6%)** | 8 |

(246 operator/function pairs had no site and 5 had only non-compiling mutants.) The 8 misses:
- **4 are equivalent by construction**, so no checker could see them: three change the fifth
  argument (r7) of a call to `fn_8841F080`, which never reads r7; one changes the crc32 tail loop
  `while (len >= 4)` to `> 4`, which moves the last word into the byte loop, and that computes the
  same CRC.
- **1 is a stated blind spot**: `value.f8 = 0` -> `1` in `ts4_name_table_build`, a field at
  offset 8 of a local struct passed to callees. Only the first word of a frame object is
  compared (7.1); a wider window gave false DIFFERENT verdicts on non-matched candidates.
- **3 sit on paths the trials did not reach or reached without the deciding value**: `luaL_getn`
  `n - 1` -> `1 - n` in a block outside the 90% covered; `lib2_frame_sync` (coverage 90.5%) `> 0`
  -> `> 1` on a 64-bit total-samples field that must be exactly 1, and a dropped
  `lookahead` store on an uncovered branch.

Excluding the four equivalent mutants, the detection rate is 141/145 = 97%.

Checker improvements that came out of earlier rounds of this experiment, and that the table
already includes: stack arguments 9+ (a dropped argument in a 13-argument call was missed),
seeded jump-table case values and an explicit boundary phase (a `which_tbl >= 4` -> `>= 5` was
missed because 4 was never drawn), 8-byte loads in the mutation trace, and the out-parameter
model (a `start < 1` flip in Lua's `str_sub` was missed because the length came back through
`&len`).

## 4. What the tier could cover: asm2c translations

RESULTS_ASM2C

## 5. Hand-written near misses

RESULTS_NEAR

## 6. How the tier enters the project

**Spec field.** A spec gains `"route": "equiv"` (default `"match"`):

```json
{"source": "src/xbox360/eq_<family>_<stem>.c", "route": "equiv", "flags": [],
 "functions": {"ts4_name_8861C648": "0x8861C648"},
 "evidence": "work/specs/<FAMILY>/<stem>.equiv.json"}
```

**Where sources live.** Equivalent sources are normal C files under `src/xbox360/`, with an
`eq_` family prefix so they are never confused with matched files, and they follow the same naming,
comment and host-syntax rules. They are *not* fed to objdiff or to the forced link map: the
matching pipeline keeps the original bytes for those functions. A function moves from `equiv` to
`match` when its source later byte-matches (the matched tier always wins).

**Progress.** Two numbers, side by side, never summed:

    matched     30,430 functions  2,936,440 / 10,154,036 code bytes (28.92%)   [b45]
    equivalent       0 functions          0 / 10,154,036 code bytes  (0.00%)   [separate; not included above]

(Today no source carries `"route": "equiv"`, so the second line is zero. Sections 4 and 5 show what
the sampled translations and drafts would add.) The same function is never counted in both:
a function that becomes matched leaves the equivalent count.

`config/progress.json` gets a separate `equivalent_functions` / `equivalent_bytes` pair, and the
public decomp.dev report keeps reporting matched bytes only (it has no notion of the second tier).

**Evidence stored per function** (`work/specs/<FAMILY>/<stem>.equiv.json`, the `--json` output
of `fn_equiv.py`, regenerable, small enough to commit if the coordinator wants): checker version
(`fn_equiv/1`), source path and sha256, compiler flags, `TS4_MATCHING_DIR`, original address and
size, seed, trial count, valid and discarded trials (with reasons), the argument registers and
return kind used, block count, covered blocks, coverage and the uncovered block addresses,
`abi_hazard`, verdict and reason. `fn_equiv.py <source> <name>=<addr> --seed S --trials N`
reproduces a result exactly: every input is a pure function of the seed.

**Integration (for the coordinator; nothing applied).**
1. `tools/integrate_match.py`: accept `"route": "equiv"` specs, check that the evidence file says
   EQUIVALENT with the current checker version and the source sha256, rename placeholder symbols
   exactly as for matches, but record the function in a new `config/54540859/equiv.json` instead
   of `match.json`.
2. `tools/matching.py`: skip `equiv` sources when building objdiff units (they would show as
   non-matching); optionally re-run `fn_equiv.py` on them as a regression check, which needs only
   the compiler and Unicorn.
3. `tools/sync_progress.py`: write the second pair of numbers next to the first.
4. CI: `python3 -m unittest tests.test_fn_equiv` runs with synthetic code only; a real re-check
   needs the disc image and stays local.

## 7. Honest limits

### 7.1 Testing is evidence, not proof

A pass means: on the sampled inputs, with most blocks reached, nothing observable differed.
Values that matter only at one specific input (a magic constant compared once, an overflow at
2^31) can slip through if no trial produced them; the input generator seeds the original's own
comparison constants to reduce this, and the uncovered-block list shows what was never run. What
the checker does **not** observe at all:
- **Callee behaviour.** Callees are stubs. Two functions that pass the same arguments are equal
  even if one of them relied on the callee doing something the other did not need. The only
  memory a callee writes is one seeded word through a pointer into the caller's frame (out-
  parameters); stores a real callee makes through heap pointers, or beyond the first word of a
  frame object, are not modelled, so code that depends on them sees seeded heap bytes or the
  frame's fill pattern.
- **Frame objects beyond their first word.** Only the first word of a local passed by pointer is
  compared: a wider window reached neighbouring locals and save slots whose placement differs
  between two compilations, which gave false DIFFERENT verdicts on non-matched candidates.
- **Reads.** An extra, missing or reordered load is invisible unless it changes a value,
  faults, or is volatile hardware state (none of which the model has).
- **The function's own stack frame**, except the first word of objects passed by pointer to a
  callee.
- **Faults on inputs the original cannot handle** (discarded trials) and code reached only
  after a call returns a specific value combination.
- **Upper halves of 64-bit registers** for integer arguments and results (only the low 32 bits
  are compared, because 32-bit values are allowed to carry garbage above bit 31).
- **Concurrency** (`lwarx/stwcx.` run single-threaded) and timing (`mftb`).
- **Recursion depth**: a recursive call is intercepted like any other.
- **Missing variadic arguments.** A variadic callee (`ts4_format_text` and other printf-style
  functions, recognised by `va_start` taking the address of the home area) home-stores r3-r10
  whatever the format consumes, so its liveness cannot say how many arguments are real. For
  these calls only registers and stack slots that *both* sides pass are compared: a wrong value
  is caught, an argument the candidate leaves out is not.
- **Sub-word locals passed by pointer.** The out-parameter model stores a whole word; for a
  `char`/`short` local passed by address this can reach a neighbouring local, which sits at a
  different place in the two frames.

### 7.2 Translator output is not the goal state

An `EQUIVALENT` asm2c translation is correct but untyped (`ts4_word` everywhere, byte-offset field
access, `lvN` loop variables). It is a safe base for a human or a later pass to name and type, and
it is re-checkable after every edit, but it does not meet the AGENTS.md bar for a reconstructed
function ("named, typed, reviewed and validated") on its own. Section 4 also shows that most
translations of larger functions are **not** behaviourally correct today, so the translator's
output cannot be accepted without this check.

### 7.3 Whole-program register conventions (LTCG)

The original game code was built with /GL and /LTCG (`docs/ltcg-route.md`): callers keep volatile
registers live across calls to callees they know do not touch them. The checker handles this for
the function's *callees* (they clobber only what they really write), but a recompiled candidate
used as a *callee* of original LTCG code follows the standard ABI and may clobber such registers.
In a fully recompiled native build this is harmless: every caller is recompiled with the same
ABI. It matters when equivalent functions are mixed with original machine code (patching the
XEX, or a partial rebuild linked against original objects): `abi_hazard` lists, per function,
the volatile registers that an image caller relies on and the candidate overwrites. Equivalent
functions compiled together later (one TU, or /LTCG) can also be inlined into each other and lose
the call boundaries the checker compared; re-run the checker on the combined object (it takes any
`.obj` via `--obj`).

## 8. Inputs and reproduction

Inputs (nothing from them is in the repository):

| input | value |
|---|---|
| original | `orig/54540859/Swing_DLL.dll`, 13,848,064 bytes, sha256 `a7f28b29ef72fcc88c9b7c8208d27367b2e1bcfdafbeaddc49b9e8d32f952ba9` |
| symbols | `work/matching-b45/analysis/symbols.txt` + committed `symbols.txt` (b45: 30,430 matched functions) |
| emulator | unicorn 2.1.4 (pip), Python 3.13.18 |
| compiler | the project's MSVC 16.00.10224 via `fn_check.compile_candidate` (base flags `/O2 /Oi`, per-file exceptions) |
| checker | `tools/fn_equiv.py`, version string `fn_equiv/1`, sha256 CHECKER_SHA |

Commands (scratch scripts live in `work/eq1/`, outside the repository's tracked tree; each
writes JSON lines, one result per function):

```sh
python3 -m unittest tests.test_fn_equiv                  # 15 tests, synthetic code only
# 3.1  matched ground truth (job list: 300 functions stratified by size, LTCG units excluded)
NPROC=2 KW='{"trials":300,"time_budget":40}' python3 work/eq1/harness.py work/eq1/jobs_matched.json work/eq1/res_matched.jsonl
python3 work/eq1/summarize.py work/eq1/res_matched.jsonl
# 3.2  mutation testing on the EQUIVALENT ones
NPROC=2 python3 work/eq1/mutate.py work/eq1/res_matched.jsonl work/eq1/res_mut.jsonl 80
# 4/5  asm2c sample + near misses
python3 work/eq1/asm2c_sample.py work/eq1/a2c work/eq1/jobs_a2c.json      # decomp_survey sample --seed 1
python3 work/eq1/nearmiss_collect.py                                       # -> jobs_near.json
python3 work/eq1/harness.py work/eq1/jobs_near.json work/eq1/res_near.jsonl  # finds fragments that do not compile
python3 work/eq1/near_ctx.py                                              # -> jobs_near_ctx.json (fragment + its context source)
# jobs_step3.json = jobs_near.json + jobs_near_ctx.json + jobs_a2c.json
NPROC=2 KW='{"trials":400,"time_budget":45}' python3 work/eq1/harness.py work/eq1/jobs_step3.json work/eq1/res_step3.jsonl
python3 work/eq1/report3.py work/eq1/res_step3.jsonl
# one function
python3 tools/fn_equiv.py src/xbox360/<file>.c <name>=0x<addr> --seed 1 --trials 400 --time 0 --json out.json
```
