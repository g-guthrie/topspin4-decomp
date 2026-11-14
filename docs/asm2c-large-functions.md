# asm2c on functions of 256-2048 bytes (round T1)

Tooling round T1, 2026-11-14. Goal: raise the match rate of `tools/asm2c` on functions of
256-2048 bytes, following section 3 of `docs/decomp-remaining.md`.

## 1. Fixed sample and how it is measured

The sample is the game-code part of a deterministic stratified draw:

```sh
python3 tools/decomp_survey.py sample --lo 256 --hi 2048 -n 600 --seed 1 > work/t1/sample_all.txt
grep ' game:' work/t1/sample_all.txt > work/t1/sample_game.txt          # 342 functions, 203,176 bytes
awk '{print $1}' work/t1/sample_game.txt > work/t1/only.txt
sha256sum work/t1/only.txt   # aad771a8e30f1dd613ab4ce057d9c642f478b42b1fdd134e7c94345f67fb6813
```

Inputs: `config/54540859/match.json` sha256 `5b3beb18...14e18ab`, `symbols.txt` sha256
`0ba1dd99...dabdf`, `TS4_MATCHING_DIR=work/matching-b39` (the newest split whose `work/b39.log`
has a "Matched" line), Python 3.13.18, MSVC 16.00.10224.00 through `tools/fn_check.py`.

Each measurement is one fresh asm2c run over the sample with the K6M variant set, both flag sets,
in a scratch work dir with `--no-final` (`work/t1/measure.sh TAG`):

```sh
TS4_MATCHING_DIR=$PWD/work/matching-b39 python3 tools/asm2c/run.py --prefix t1m --family T1M \
  --work work/t1/m_$TAG --out-dir work/t1/m_$TAG/out --spec-dir work/t1/m_$TAG/specs --no-final \
  --max-size 0x800 --variants $VARIANTS --flagsets ",O1" --only-addrs work/t1/only.txt --jobs 4 --fresh
```

`VARIANTS` is `10w,10wV,20w,10wJ,10` unless the table says otherwise. Translation refusals are
counted with `work/t1/refusals.py 10w`, frame agreement with `work/t1/fcheck.py 10w` (both are
scratch drivers around `translate.gen` and `frame.frame_check`).

## 2. Results per change

All rows use the 342-function sample. "Near" means the candidate has the target's size and
relocation layout (the precondition for perm.py); "<=10" counts those with at most 10 differing
instructions. Matches are listed by address.

| # | Change | Run (work dir) | Flags | Translated (10w) | Matched | Bytes | Near (<=10) |
|---:|---|---|---|---:|---:|---:|---:|
| 0 | baseline (tree at start of T1) | `m_base` | base + O1 | 266 | 1 (0x88751100) | 856 | 12 (4) |
| 1 | loop-exit join in the structurizer (variant x turns it off) | `m_x` | base + O1 | 265 | 1 | 856 | 12 (4) |
| 2 | + stack-frame model, variants `10wF,10wVF,20wF,10wJF,10F` | `m_xf` | base only (O1 half stopped, see note) | 161 checked of 266 | 1 | 856 | 11 (4) |
| 3 | perm.py on row 1's near misses, tree before T1 transforms | `m_x/perm0.log` | | | +0 | 0 | |
| 4 | perm.py on row 1's near misses with the T1 transforms (un-CSE, load swap, expression CSE, block CSE) | `m_x/perm.log` | | | +1 (0x88681848, un-CSE) | +272 | |
| - | **total on the sample** | | | | **2** | **1,128** | |

Commands: rows 0-2 `work/t1/measure.sh base|x` and `VARIANTS=10wF,10wVF,20wF,10wJF,10F work/t1/measure.sh xf`
(row 0's O1 half was resumed with variants suffixed `x` after the first process was stopped;
`work/t1/resume_base.sh`). Rows 3-4: `python3 tools/asm2c/perm.py --work work/t1/m_x --max-diff 60
--rounds 30 --patience 15 --jobs 2` (row 4 after moving the first perm.pkl aside). The O1 half of
row 2 was stopped once the project moved off byte matching; at base flags rows 0-2 are equal
(1 match, 12/12/11 near misses).

Frame agreement (frame size and every local offset equal to the original), 10w, from
`work/t1/fcheck.py 10w`: unsplit text 142 of 271 compiled, any frame plan 152.
`work/t1/fcan.py` splits the 119 that remain: 42 candidate frame bigger, 31 same offsets but
other size (register count or compiler temporaries), 21 same size but offsets permuted (use-count
ties), 18 smaller, 7 other. 44 of the 119 copy 8-byte structs through the stack (`ld`/`std`).

### LTCG and /Oc on the same sample

On the coordinator's request the baseline's translations (896 function x variant candidates,
base flags) were also checked with `tools/fn_check_ltcg.py`, one link per scratch file
(`work/t1/ltcg_measure.py`; data in `work/t1/lt_*.json`):

| Check | Match | Near (size + relocations) | <=10 |
|---|---:|---:|---:|
| plain fn_check | 1 | 23 | 7 |
| LTCG, no context | 1 | 23 | 7 |
| plain and LTCG with `/Oc` | 1 | 25 | 7 |
| LTCG + `/Oc` + matched callees' sources as context | 1 | 23 | 7 |

With context LTCG had fewer differing instructions in 54 cases and more in 181. fn_check_ltcg
cannot link files that reference `__imp_*` import data; the measurement removed such functions
(and defined the context's ones in a `nogl:` stub, `work/t1/imp_stubs.c`).

### Passes over the whole game

| Pass | Scope | Result | Spec |
|---|---|---|---|
| /Oc pass (`work/t1/oc_run.sh`, then perm.py `--max-diff 30 --rounds 25`) | 913 unmatched game/lib `fn_` <= 0x800 whose code has `divw`/`divwu` and no `tw`/`twi` (`work/t1/divsites.py`, 392,736 B); 797 translated; variants 10w,10wV,10wF,10wVF,20w,10,10wJ x flags Oc,O1Oc | 3 direct + 3 permuted = 6 functions, 632 B (0x886091E0 and 0x88609228 are codegen-idioms' "divw without tw") | `work/specs/T1/t1_oc_000.json` (integrated) |
| changed-texts full pass (`work/t1/full_run.sh`, `--changed-only`) | 8,853 game/lib `fn_` <= 0x800 (SDK, Havok, FMOD core, Bink and the /Oc set skipped) | FULL_RESULT | FULL_SPEC |


## 3. What MSVC does with locals (measured with tools/asm2c/probe.py)

`python3 tools/asm2c/probe.py file.c` compiles a file with the real compiler and prints each
function's listing and frame size. Probes (all `/O2 /Oi`):

| Probe | Result |
|---|---|
| four `ts4_word` locals, address passed to one call, declared in any order or renamed | same offsets every time: neither names nor declaration order matter |
| one of them used more often | it moves to the lowest offset |
| `char`, `W`, `W[2]`, `double` and a float->int conversion temporary | placed in order of increasing size: 0x50 char, 0x54 word, 0x58 8-byte array, 0x60 double, 0x68 conversion slot |
| 16-, 12-, 8-, 4-byte structs | 0x50 (4), 0x58 (8), 0x60 (12), 0x70 (16, 16-aligned) |
| the same objects wrapped in one struct | the struct is placed after the compiler's own 8-byte temporary (it is bigger) |
| two 8-byte arrays with equal use counts | the one referenced first in the code gets the lower offset |

So the locals are sorted by (size ascending, use count descending, first reference), compiler
temporaries included, with objects of 16 bytes or more 16-aligned. A word array where the
original had separate scalars changes the frame in two ways: its size moves it in the sort, and
it collects the uses of all its slots. Declaration order cannot be used to steer the layout.

## 4. Changes

All in `tools/asm2c/` (tests: `tests/test_asm2c_frame.py`, `tests/test_asm2c_t1.py`).

1. **`probe.py`**: compile a C file with the real compiler and list every function with its
   frame size (`python3 tools/asm2c/probe.py f.c [--flags /O1]`). Used for section 3.
2. **`frame.py`, variant letter `F`** (stack-frame model). `split(body, plan)` turns each stack word
   array into one typed local per slot (`ts4_word s58;`, `ts4_u64 q60;`, `double q68;`) and keeps
   address-taken regions as arrays with the plan's extent (`word`, `tight`, `fill`).
   `run.frame_select` compiles every plan of every function in batches (one compiler run per 200
   functions and plan) and keeps the unsplit text when it already has the original frame,
   otherwise the first plan that has it, otherwise the unsplit text. `frame.frame_check` is the
   early frame check. Measured effect: about 37 more functions per variant with the right frame
   and offsets, no new match.
3. **Loop-exit join** (`Gen._outside_join`, default on, variant letter `x` turns it off). An arm that
   has left every loop being emitted for good (it ends in a return) now joins at its
   post-dominator, so the shared tail is emitted once. Before, every `if` inside such an arm
   duplicated the rest of the arm. Example 0x887193A8: candidate 0x170 -> 0x128 bytes (target
   0x124). It changes the text of 185 of 8,469 translatable game/lib functions up to 0x800 B; no new
   match on the sample. Also fixed: a crash (`TypeError`) when the non-breaking arm of a loop `if`
   is the join block itself (0x881D8960).
4. **Permutation transforms** in `xforms.py`, queued by perm.py as deterministic rewrites and used
   as mutations: `uncse_all` (repeat a load in both arms instead of loading it before the `if`, so
   it is scheduled after the compare), `ldswap_all` (swap two adjacent independent loads),
   `exprcse_all` (an arithmetic subexpression used in two statements becomes one temporary),
   `blockcse_all` (an element address `(lv5 + t2)` used repeatedly becomes a temporary). `uncse`
   produced the sample's second match. perm.py found the /Oc pass's three permuted matches with
   these transforms in its queue; which rewrite produced each one was not recorded.
5. **Flag sets `Oc` and `O1Oc`** in `run.FLAGSETS` (LT1 found the game was built with `/Oc`).
   Specs carry `"flags": ["/Oc"]` / `["/O1", "/Oc"]`.
6. **`run.py --changed-only`**: verify only translations that differ from the pre-T1 translator
   (same variant plus `x`, without `F`), so a rerun after a translator change costs a fraction of
   a full pass.
7. **`diag.py`** (frame/size classification of a work dir's scratch files) and **`generate.py`**
   (regenerate compiling C for every unmatched function into a scratch directory, no byte check;
   section 6).

"read r" was left alone. It is 11 of 342 refusals in the sample, and K6 found it is mostly a
caller relying on registers that a same-file callee leaves untouched. That needs the callee in the
same file, not a translator change.


## 5. Next limiting factors

NEXT
