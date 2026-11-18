# The "equivalent" tier: behaviour checked by running original and candidate side by side

EQ1, 2026-11-14. Tool: `tools/fn_equiv.py` (checker version string `fn_equiv/1`), tests:
`tests/test_fn_equiv.py`. Nothing in `src/`, `config/` or `tools/matching.py` was changed and
`tools/matching.py` was not run. This document describes the checker, the evidence that it
works, what it measured on the remaining code, and how the tier should enter the project.
Section 8 lists the inputs and the commands that reproduce every number.

**Status.** All runs are complete. The matched ground truth (300 functions), mutation testing
(155 mutants), the near-miss set (69 functions) and the gameplay survey (section 9) all use the final
checker (sha256 `755e11c2...`). The asm2c sample (332 checked translations) mixes three checker
versions; see section 4. The final runs ran under `nice -n 19` with one worker, so the native-build
boots kept the machine.

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
function reaches full coverage; by size, 145 of 150 functions under 256 bytes reach 90%, 31 of 56
at 256-512 bytes, 11 of 33 at 512-1024 and 11 of 60 above 1 KB. The unreached blocks are mostly
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
| 256-512 | 57 | 30 | 0 | 27 | 95% |
| 512-1024 | 33 | 11 | 0 | 22 | 80% |
| 1024-2048 | 47 | 6 | 0 | 41 | 52% |
| 2048+ | 13 | 5 | 0 | 8 | 49% |
| all | 300 | 197 (51,468 bytes) | **0** | 103 (98,444 bytes) | 100% |

Final checker (sha256 `755e11c2bbd9fae18efc60fe742ad186de195b8140dd866fad01066bac25b840`), run at
`nice -n 19` with one worker. UNCHECKED reasons: coverage below 90% (95), too few valid trials (7: the original faults or
runs past the instruction limit on almost every generated input; e.g. `lua3_luaG_errormsg`
longjmps, the Huffman/jpeg table builders loop over seeded counts), VMX (1). No result had a
non-empty `abi_hazard`. Median 152 valid trials and 2.1 s per function; 26 CPU-minutes in all.
Trials are deterministic, but the per-function time budget (40 s here) cuts long functions short
by wall-clock, so on a loaded machine a large function can end with fewer trials. Across the
reruns this moved a few functions near the threshold between EQUIVALENT and UNCHECKED (190 to
197 EQUIVALENT); it never produced a DIFFERENT. For a reproducible verdict use `--time 0`.

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
the sample. Two more came from the final rounds. (9) A stack-argument slot whose second word was
the LR save word of a small frame was skipped whole, so a changed 13th argument went unseen
(a mutation miss). (10) Two runs that both returned a pointer into their own dead frame were
compared by address; a translator had declared a void vtable method as returning a word. With all ten fixed, the run above has no DIFFERENT. Its coverage figures
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
| const | 78 | 72 | 6 |
| cmp | 32 | 32 | 0 |
| store | 30 | 29 | 1 |
| swap | 6 | 5 | 1 |
| bound | 9 | 7 | 2 |
| all | 155 (78 functions) | **145 (93.5%)** | 10 |

Final checker (`755e11c2...`); 240 operator/function pairs had no site and 5 had only
non-compiling mutants. The 10 misses:
- **4 are equivalent by construction**, so no checker could see them. Two change the fifth
  argument (r7) of a call to `fn_8841F080`, which never reads r7. One changes the crc32 tail loop
  `while (len >= 4)` to `> 4`, which moves the last word into the byte loop, and that computes the
  same CRC. One enlarges an unused local array (`loc50[2]` -> `[3]`), which changes only the frame
  size.
- **4 are the stated blind spot of the frame-object window** (only the first word of a local
  passed by pointer is compared, 7.1): `value.f8` in `ts4_name_table_build`, `buf[4]` and
  `buf[6]`/`buf[7]` of the 13-byte IHDR buffer in `png_write_IHDR`, and `loc58[1]` in
  `fn_8820B418`.
- **2 sit on paths the trials did not reach or reached without the deciding value**: `luaL_getn`
  `n - 1` -> `1 - n` in a block outside the 90% covered, and a `jpeg_decode_mcu` loop bound
  (coverage 91%).

Excluding the four equivalent mutants, the detection rate is 145/151 = 96%. The function set differs
slightly from earlier rounds, because the deterministic choice draws from the EQUIVALENT results of
3.1, which moved by a few functions.

Checker improvements that came out of earlier rounds of this experiment, and that the table
already includes: stack arguments 9+ (a dropped argument in a 13-argument call was missed; later, a changed 13th
argument was missed again because its slot shares 8 bytes with the LR save word of a small frame),
seeded jump-table case values and an explicit boundary phase (a `which_tbl >= 4` -> `>= 5` was
missed because 4 was never drawn), 8-byte loads in the mutation trace, and the out-parameter
model (a `start < 1` flip in Lua's `str_sub` was missed because the length came back through
`&len`).

## 4. What the tier could cover: asm2c translations

Sample: `python3 tools/decomp_survey.py sample --lo L --hi H -n N --seed 1` for the classes
0-256 (260), 256-512 (200), 512-1024 (160) and 1024-2048 (120), keeping only `game:` buckets
(Havok, FMOD core, Xbox SDK and Bink are other buckets), which gives 428 functions. Each was translated
with `tools/asm2c` (used read-only, variant `10w`) and built in groups of 25 with base flags.
Translations that do not compile were dropped one by one from their group. All 332 that
compiled have a checker result.

| class (bytes) | sampled | translate fail | compile fail | EQUIVALENT | DIFFERENT | UNCHECKED |
|---|---|---|---|---|---|---|
| 0-256 | 154 | 18 | 3 | 74 | 22 | 37 |
| 256-512 | 119 | 11 | 5 | 40 | 18 | 45 |
| 512-1024 | 90 | 27 | 2 | 15 | 8 | 38 |
| 1024-2048 | 65 | 25 | 5 | 2 | 11 | 22 |
| all | 428 | 81 | 15 | **131** (37,456 bytes) | **59** | 142 |

- Translator failures (81): `read r` (a register read before any write, 20), `mfcr` (9), VMX
  instructions (`vsldoi`, `read v`, `stvewx`, `vpk`, ...: about 20), struct arguments (5), irregular
  exits (5), and other shapes.
- DIFFERENT (59), by first difference: return value 35 (typically the translation returns its
  input pointer, or 0, where callers read a computed value), call argument 12, stack object
  passed to a callee 5, call sequence 4, memory at a call 1, callee-saved registers 1 (a copy loop
  that overruns its frame buffer), outcome 1. The ones read by hand were real translator errors:
  dropped returns, dropped pointer increments, swapped sign extension. **5 of the 59 are
  unconfirmed**: each compares an argument of a variadic callee, where the original's register may
  be a temporary (`0x880f0000`, a `lis` half-address) or an uninitialised value. So the confirmed
  count is 54.
- UNCHECKED (142): coverage below 90% (85), too few valid trials (39), VMX in the original (18).

Checker versions: this sample is the one result set not from a single checker version. 180
results come from `58667366...`, 49 DIFFERENT results from it were re-checked with fixes 6-8, and 103
(the last 71 functions, plus the variadic re-checks) come from `082aff67...`. The two fixes made
after that (stack-argument slots whose second word is a save slot; returns that point into the dead
frame, see 3.1) cannot change the 59 DIFFERENT. The return fix touches none of them, and the slot fix only makes
comparisons stricter. In principle the slot fix could turn one of the 131 EQUIVALENT into
DIFFERENT, for a translation that passes a wrong ninth-or-later argument in a frame where that
slot sits next to the LR save word. Rerunning the whole
sample with the final checker takes about 1.5 CPU-hours.

Reading: about two compiled translations in five are EQUIVALENT (131 of 332), and about one in six
is demonstrably wrong (54 to 59). The rest cannot be judged automatically. asm2c output must never
be accepted without this check.

## 5. Hand-written near misses

**Final checker.** Sources: `work/army/GA3-nearmiss/`, `work/army/ga6_scratch/`,
`work/army/LB3.drafts/`, and the `src` files named by `work/army/*.failed.md` entries. Only functions
that are not matched are included, which gives 72 jobs in 36 files. Fragments that do not compile
alone were retried with the source they belong to prepended (`work/eq1/near_ctx/`, 12 functions
recovered). Per function, the best outcome:

| origin | functions | EQUIVALENT | DIFFERENT | UNCHECKED | does not compile |
|---|---|---|---|---|---|
| all | 69 | **16** (5,020 bytes) | 1 | 28 | 24 |

(By origin, counting rows: GA3-nearmiss 5 EQUIVALENT of 9; LB3.drafts 1 of 8; context retries 6
of 12; failed.md sources 4 of 32; ga6_scratch 1 of 23.) The 16 EQUIVALENT drafts include
`ga3_controller_init`, `ga3_next_state`, `ga3_reset_controller`,
`lib2_read_residual_partitioned_rice`, `lib2__packetout`, `aud1_res0_look`, `aud1_floor1_look`,
`aud1_render_line` and `lb3_celt_mix_pitch_and_residual`: hand-written, typed C that missed the
byte match but behaves like the original, which is exactly what this tier is for.

- DIFFERENT (1): `lib4_trio_wide_TrioWriteNumber` is genuinely wrong. Its buffer index uses
  `sizeof(buffer)` (bytes) on a wide-char array, so `*pointer-- = NIL` writes 768 bytes past the
  array into the frame, and the candidate then loops 400+ times.
- UNCHECKED (28): coverage (18), "candidate function not defined" (7: the draft no longer contains
  the function), `_blkmov` unresolved (2: the struct-copy helper is not in `symbols.txt`), too few
  valid trials (1).
- Does not compile (24): 22 of them are `ga6_scratch` bodies whose struct definitions were never
  saved, so they cannot be recovered.

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
| checker | `tools/fn_equiv.py`, version string `fn_equiv/1`, sha256 `755e11c2bbd9fae18efc60fe742ad186de195b8140dd866fad01066bac25b840` (final) |

Commands (scratch scripts live in `work/eq1/`, outside the repository's tracked tree; each
writes JSON lines, one result per function):

```sh
python3 -m unittest tests.test_fn_equiv                  # 16 tests, synthetic code only
# 3.1  matched ground truth (job list: 300 functions stratified by size, LTCG units excluded)
NPROC=1 KW='{"trials":300,"time_budget":40}' nice -n 19 python3 work/eq1/harness.py work/eq1/jobs_matched.json work/eq1/res_matched.jsonl
python3 work/eq1/summarize.py work/eq1/res_matched.jsonl
# 3.2  mutation testing on the EQUIVALENT ones
NPROC=1 nice -n 19 python3 work/eq1/mutate.py work/eq1/res_matched.jsonl work/eq1/res_mut.jsonl 80
# 4/5  asm2c sample + near misses
python3 work/eq1/asm2c_sample.py work/eq1/a2c work/eq1/jobs_a2c.json      # decomp_survey sample --seed 1
python3 work/eq1/nearmiss_collect.py                                       # -> jobs_near.json
python3 work/eq1/harness.py work/eq1/jobs_near.json work/eq1/res_near.jsonl  # finds fragments that do not compile
python3 work/eq1/near_ctx.py                                              # -> jobs_near_ctx.json (fragment + its context source)
# jobs_step3.json = jobs_near.json + jobs_near_ctx.json + jobs_a2c.json
NPROC=2 KW='{"trials":400,"time_budget":45}' python3 work/eq1/harness.py work/eq1/jobs_step3.json work/eq1/res_step3.jsonl
python3 work/eq1/report3.py work/eq1/res_step3.jsonl
# 9    gameplay survey (every whole-function C candidate of the retune targets)
python3 work/eq1/find_defs.py 886629C8,886AFDF8,...        # definitions carrying the address
NPROC=1 KW='{"trials":400,"time_budget":60}' nice -n 19 python3 work/eq1/harness.py work/eq1/jobs_gameplay.json work/eq1/res_gameplay.jsonl
# one function
python3 tools/fn_equiv.py src/xbox360/<file>.c <name>=0x<addr> --seed 1 --trials 400 --time 0 --json out.json
```

## 9. Gameplay functions the retune will modify

The retune (docs/gameplay/TUNING.md, symbols.md) changes behaviour that lives in code, not data. A
modified function has to be rebuilt from C, so each one needs C that is first proven to behave like
the original. The table ranks the functions the retune touches, from the most player-visible
mechanics down, and gives each one's current status. Every whole-function C candidate that exists
was found (`src/xbox360` matched files and drafts, `work/army` drafts, `ref/gameplay`, T1's
translator output in `work/t1/gen`, manifest `work/t1/gen/manifest.json`) and run through the final
checker. `ref/gameplay` and the `gp4`/`gp8` drafts are behavioural models: they take their own
structs and arguments rather than the original's, so they are reference for the rewrite, not
something the checker can compare.

| # | function | role (symbols.md) | bytes | byte-matched | best C and checker verdict | other C |
|---|---|---|---|---|---|---|
| 1 | `fn_886629C8` | `ShotSpecific_Fill`: grade selection | 408 | no | **no C yet** (translator refused: two return registers) | callers only (`nm3_shot_flags.c`, `gp8` drafts) |
| 2 | `fn_886AFDF8` | `SwingCategory_Walk` | 940 | no | **no C yet** (translator refused: register read before write) | model `ref/gameplay/swing_category.c` (`sc_*`) |
| 3 | `fn_886B0250` | `SwingCategory_Select` | 300 | no | translator output `gen_024.c` **EQUIVALENT** (100% coverage, 251 valid trials) | |
| 4 | `fn_886B01A8` | `SwingCategory_ClassList` | 168 | **yes** (`d1g_shotreq.cpp`) | matched; checker UNCHECKED (57% coverage: hash-keyed cases, see note) | |
| 5 | `fn_8867DF68` | `TimingState_Update`: timing value | 800 | no | **no C yet**; original uses VMX, so **not checkable** | model `ref/gameplay/timing.c` |
| 6 | `fn_886935A0` | `AimSelector_GetTarget`: aim selector | 140 | no | translator output `gen_023.c` **EQUIVALENT** (100%) | |
| 7 | `fn_88695C48` | `AimingState_Evaluate`: efficiency | 244 | no | typed draft `work/army/GA3-nearmiss/ga3_f_attempt3.c` (`ga3_refresh_tuning`) **EQUIVALENT** (100%) | translator output `gen_023.c` EQUIVALENT (100%) |
| 8 | `fn_886807C0` | outcome roll (let / error / net vs out) | 2304 | no | **no C yet** (translator refused: `mfcr`); original uses VMX, so **not checkable** | models `src/xbox360/drafts/gp8_shot_error_model.c`, `ref/gameplay/ball.c` |
| 9 | `fn_8869B928` | `Repositioning_HumanMode`: net-rush rule | 676 | no | translator output `gen_023.c` compiles; UNCHECKED (original uses VMX) | |
| 10 | `fn_8866F740` | `Mover_PreHitFreeze` | 688 | no | translator output `gen_022.c` **EQUIVALENT** (93%) | |
| 11 | `fn_886CD3C8` | `AnimNode_BusyFrames`: busy-time check | 192 | no | **no checkable C** (translator refused: register read before write) | draft `gp7_engine_update.c` does not compile (opaque structs; a design note) |
| 12 | `fn_8866A1C8` | serve fault path: `OnPointEnd` serve rules | 1048 | no | draft `work/army/d2g_scratch/8866A1C8_best.c` UNCHECKED (75% coverage) | translator refused (two return registers); model `ref/gameplay/rules.c` |
| 13 | `fn_88669878` | serve fault path: serve-number bookkeeping | 540 | no | translator output `gen_022.c` UNCHECKED (82% coverage) | model `ref/gameplay/rules.c` |
| 14 | `fn_889C1C80` | bounce response | 748 | no | **no C yet** (translator refused: vector register read); original uses VMX, so **not checkable** | models `gp4_ball_flight.c`, `gp4b_ball_model.c` |

Summary. **4 are ready**, with C proven EQUIVALENT: 3, 6, 7, 10, and 7 also has a typed draft.
**1 is byte-matched**: 4. **3 have C that is not yet proven**: 9 (VMX), 12 and 13 (coverage).
**6 have no whole-function C**: 1, 2, 5, 8, 11, 14. Of those, 5, 8 and 14 contain VMX, so the
checker cannot verify any C for them. Their rewrite needs another way to validate, such as a
VMX-capable emulator or a runtime trace comparison on the native build.

Notes for the next stage:
- The translator output is untyped (`ts4_word`, byte offsets). It is a verified starting point to
  rename and type, and the checker should be re-run after every edit. It is not the finished source.
- 12 and 13 fall short on coverage because both depend on match-state combinations (serve phase,
  winner, second serve). Writing a dedicated input generator for the scoring block would close
  them.
- The checker's constants come from immediate compares only. Functions that switch on 32-bit
  hash keys built with `lis`/`ori` (4, and much of the swing code) would gain coverage if those
  keys were seeded too. This is a small, isolated change to `code_consts`.
- Evidence: `work/eq1/res_gameplay.jsonl` (one JSON result per candidate, uncovered blocks included).

### 9.1 RT1 update (2026-11-15)

Agent RT1 wrote typed whole-function C (real names, shared headers `rt1_types.h`, `rt1_scoring.h`)
for every row above except 4. Checker runs used `TS4_MATCHING_DIR=work/matching-b46`, seed 1;
specs and evidence are under `work/specs/RT1/` and `work/equiv/rt1_<addr>.json`. Rows marked
`+hashes` used `work/army/RT1/fn_equiv_hashes.py`, which runs `tools/fn_equiv.py` unchanged and
only adds the `lis`/`ori` and `addis`/`addi` 32-bit constants to `code_consts` (the change the
notes above asked for). Equivalent files are named `rt1_eq_*` and are not listed as matched.

| # | function | RT1 source | status | evidence |
|---|---|---|---|---|
| 1 | `fn_886629C8` | `rt1_eq_shot_specific_fill.c` | **EQUIVALENT** (45 valid of 609, 15/15 blocks, /Oc) | 8 scheduling diffs on the plain and LTCG routes |
| 2 | `fn_886AFDF8` | `rt1_eq_swing_category_walk.c` | **EQUIVALENT** (345 of 584, 67/67, /Oc) | the original keeps r4 live across `fn_8866D930` (LTCG convention) |
| 3 | `fn_886B0250` | `rt1_eq_swing_category_select.c` | **EQUIVALENT** (339 of 432, 11/11) | 57 diffs (register allocation, block order) |
| 5 | `fn_8867DF68` | `rt1_vmx_timing_update.c` | compiles, **unverified** (VMX) | 0x314 vs 0x320 bytes, 193 diffs (frame 0x130 vs 0x120); trace plan in `docs/agents/near-misses/RT1.failed.md` |
| 6 | `fn_886935A0` | `rt1_aim_get_target.c` | **byte-matched** (0x8C) | spec `rt1_aim_get_target.json` |
| 7 | `fn_88695C48` | `rt1_eq_aiming_evaluate.c` | **EQUIVALENT** (264 of 325, 11/11) | 6 register-numbering diffs |
| 8 | `fn_886807C0` | `rt1_vmx_outcome_roll.c` | compiles, **unverified** (VMX) | 0x7A8 vs 0x900 bytes, 568 diffs, 21 vs 33 relocations (constants addressed off one base); trace plan in RT1.failed.md |
| 9 | `fn_8869B928` | `rt1_vmx_net_rush.c` | compiles, **unverified** (VMX) | 0x29C vs 0x2A4 bytes, 161 diffs; trace plan in RT1.failed.md |
| 10 | `fn_8866F740` | `rt1_eq_prehit_freeze.c` | **EQUIVALENT** `+hashes` (429 of 613, 28/28) | 0x2AC vs 0x2B0, 138 diffs; `clrrwi rX,rY,0` move copies (open idiom) |
| 11 | `fn_886CD3C8` | `rt1_eq_anim_busy_frames.cpp` | **EQUIVALENT** (956 of 1500, 4/4, /Oc) | LTCG with `flags(/Ob1):src/xbox360/gp7_anim_busy.cpp` 37 diffs (clrrwi, fmadds, mfcr/fsel) |
| 12 | `fn_8866A1C8` | `rt1_eq_serve_point_end.c` | **EQUIVALENT** `+hashes` (1865 of 3000, 95%, 38/40, /Oc) | plain checker 82%; 10 diffs |
| 13 | `fn_88669878` | `rt1_serve_flags.c` | **byte-matched** (0x21C) | spec `rt1_serve_flags.json` |
| 14 | `fn_889C1C80` | `rt1_vmx_ball_bounce.c` | compiles, **unverified** (VMX) | 0x300 vs 0x2EC bytes, 164 diffs; trace plan in RT1.failed.md |

RT1 summary: 2 byte-matched (680 bytes), 8 EQUIVALENT, 4 VMX functions compile but cannot be
checked by `fn_equiv.py`. Corrections found on the way: `fn_881899D8` takes `(float x, list)`
(x in f1, list in r4); the swing walk increments ctrl+0x40 when TimingBaseFrame < 30; 0x029EAAF4
is the serve state, not "point end".


### 9.2 Hash-key seeding (2026-11-18)

`code_consts()` in `tools/fn_equiv.py` now also seeds the 32-bit constants a function builds with
`lis`/`ori` pairs. Before this, functions that switch on hash keys loaded from memory reached only their
default path and came back UNCHECKED. Example: fn_88697E98 (behaviour condition evaluator, 18 hash
cases) went from 28% to 99% block coverage (82/83, seed 1, 3000 trials, 2688 valid) and came back
EQUIVALENT; the run caught one real decoding error in the draft. Earlier verdicts are unaffected:
extra seed values only add trial inputs. RT1's `work/army/RT1/fn_equiv_hashes.py` did the same as a
wrapper.

Re-runs with the seeding (stock `tools/fn_equiv.py`, `TS4_MATCHING_DIR=work/matching-b46`, `/Oc`, seed 1;
evidence in `work/equiv/`, which is not tracked):

| function | source | trials | verdict | coverage (before) |
|---|---|---|---|---|
| `fn_886B01A8` SwingCategory_ClassList (row 4) | `d1g_shotreq.cpp` | 3000 | EQUIVALENT, 1083 valid | 14/14 blocks (57%) |
| `fn_8866A1C8` serve rules OnPointEnd (row 12) | `rt1_eq_serve_point_end.c` | 3000 | EQUIVALENT, 1803 valid | 38/40, 95% (75-82%) |
| `fn_88669878` serve bookkeeping (row 13) | `rt1_serve_flags.c` | 400 | EQUIVALENT, 282 valid | 32/34, 94% (82%) |
| `fn_88676DB0` StdScoring_AddPoint (point won, AddGame, stats update) | `port_eq_scoring_point_won_88676DB0.c` | 3000 (1214 run) | EQUIVALENT, 57 valid | 15/15 blocks, 100% (not checked before) |

With these, every non-VMX row of the table has C proven EQUIVALENT or byte-matched. Status on 2026-11-18:
byte-matched rows 2 (`fn_886AFDF8`), 3, 4, 6 and 13; VMX rows 5, 8, 9, 14 remain unverifiable by
this checker (see `docs/agents/near-misses/RT1.failed.md`).
