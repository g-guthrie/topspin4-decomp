# GP2 notes: swing candidate scoring, reach, selection (WP2)

Module: Swing_DLL.xex, sha256 `dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44`.
Tools: `tools/fn_asm.py`, `tools/fn_check.py` (MSVC 16.00.10224.00, /O2 /Oi), `tools/sym_info.py`, Python 3.13.18.
All addresses are Swing_DLL.xex virtual addresses. Hashes are zlib crc32 of the ASCII name
(`python3 -c "import zlib;print(hex(zlib.crc32(b'Name')))"`). Statements marked (?) are guesses.

## 1. Correction to the WP2 premise

`fn_886B0418 -> fn_886AC2C8` (the four strings `InputNotation / Selection Score / Ball Difficulty / Reachability: %.2f m.s-1`)
is a **debug HUD**. fn_886AC2C8 formats those four numbers of one sample with `fn_885635D0` (sprintf) into a
stack buffer and never draws them (no draw call follows; only dead vector stores remain), so in this build it has no visible
output. Its only gameplay-visible side effect is that, when debug flags are on, it forces recomputation of the data it shows
(`fn_8869B128`, `fn_8868BD80`, `fn_886A9628`, dirty flag read back by `fn_886A39A8`). Its callees fall in two groups:
* real pipeline pieces that the HUD re-runs: `fn_8869B128` (reach evaluation), `fn_8868BD80` (side flags),
  `fn_8869AEF8` (selection pipeline: side select + input notation + selection score), `fn_886A9628` (evaluate default style);
* pure debug line drawing: `fn_886794D0`, `fn_8866C830`, `fn_8866C578` (+ `fn_886921A0`, `fn_8866BB80` from fn_886B0418).
The real algorithm lives in the **callees' callees** (section 3-6) and is driven per frame by `fn_886A9E48` (the movement/swing
state chooser, WP3 territory, called through the module update `fn_886BA768 -> fn_886B8468 ...`).

## 2. Object graph (all offsets read from code)

```
SwingModule M            vtable lbl_880F4478 (ctor fn_886A9050, dtor fn_886985B0); slot +0x38 = fn_886B0418 (debug render)
  +0x1c PlayerCtx PC
  +0x24 SwingBrain B     owned object, vtable lbl_880F46F0, ctor fn_886A3AC8 (0x1d0 bytes)

SwingBrain B (the object fn_886AC2C8 / fn_886A39A8 / fn_886A2E48 / fn_886A9E48 take as `this`)
  +0x24 last committed style pointer (set by fn_886A2E48)
  +0x28 ReachEvaluator E {+4 CandidateSet[2], +8 ReachTuning*, +0xc PlayerCtx*}    (fn_8868B4E8, fn_8868BD80, fn_8869B178, fn_8869B0A8)
  +0x2c == E+4  CandidateSet[2] (2 x 0x60: set 0 / set 1)
  +0x38 SelectionScorer F {+4 ReachRecord[2] (2 x 0x34), +8 CandidateSet[2], +0xd8 PlayerCtx*}  (fn_8869AB70, fn_8868AF88, fn_88689508)
        F+0x0c, +0x50, +0x94: three embedded Analysers (0x44 bytes each, vtbl lbl_880D7600)
  +0x118 ReachRecord[2] (cached pointer; same data as F+4)
  +0x154 PlayerCtx PC
  +0x158, +0x19c, +0x1e0, +0x224: more Analysers (0x44 bytes each); +0x19c = hit-quality grade, see 6.4
  +0x29c "grade already rolled" flag;  +0x295 flag;  +0x13c/+0x125/+0x121 per-frame flags cleared by fn_886BA768

PlayerCtx PC
  +0x10 byte: nonzero for an input-driven player (fn_8868AF88 returns immediately when 0, fn_88689508 skips InputNotation then)
  +0x14 player slot (HUD only shows slot 0)
  +0x2c PlayerTuning (data): style records (16 bytes each) +0x1f8,+0x208,+0x218,+0x228,+0x238,+0x248; curves +0x14c,+0x17c,
        +0x188,+0x1bc,+0x1c8,+0x1d4,+0x1e0; floats +0x230 (0.222), +0x26c
  +0x48 World: +0x28 DebugConfig, +0x30 Clock (+0x310 = current tick), +0x44 RNG owner (+0xb4), +0x5c Ball {+0x20 hit context,
        +0x24 BallPrediction, +0x68 float}
  +0x50 other brain/data (analysers at +0x158, +0x19c: the non-input-driven scoring graphs)
  +0x60 swing animation controller (fn_886CD3C8: ticks the current animation still blocks the player)
  +0x74 PlayerState: +0x3a0/+0x3a4 hit-quality grades, +0x440 stick intensity (>0.2 = stick used), +0x444 stick angle,
        +0x8e0 player position (vec4, cm), +0xb80 SwingQuery scratch, +0xbc8 committed sample index (-1 none),
        +0xbcc fallback index, +0xbd1 committed side, +0xbd2 / +0xbd5 / +0xbd3 / +0xbd4 flags, +0xf30..+0xf3c analyser inputs, +0xf68 output
  +0x78 +0x460 stroke level index (-1 -> 2), +0x28->+0xc handedness hash ("Left" = 0xda554856)
  +0xb8 BallPrediction owner: +0x7c = Ball Difficulty array (8 bytes per sample, float first), +0x88 -> BallPrediction

BallPrediction (PC->world->ball->+0x24): samples at +0x5a0..+0x5a4 (0x30 bytes), first usable index +0x5bc.
  sample: +0x00 position vec4 (cm), +0x24 tick, +0x28 small int (<= 2 required by fn_8869B178: bounce count (?))
```
Structs are typed in `src/xbox360/gp2_types.h` (`Gp2BallSample`, `Gp2CandidateSet`, `Gp2ReachRecord`, `Gp2ReachWindow`, `Gp2SwingQuery`).
Units: positions are centimetres, time is 60 Hz ticks; the constant 0.6 (pool +0x114) is 60/100, so
`required_speed [m/s] = distance[cm] / ticks * 0.6`.

## 3. Pipeline per decision (which function does what)

1. **Ball prediction** supplies samples (position + tick). Not produced here.
2. **Candidate build** `fn_8869B178` (0x7ac, caller fn_886BA768): for every sample decides a candidate *type* per sample
   (`Baseline` 0x0f6fb110, `Volley` 0x71198650, `Smash` 0x7eb30f90, `Unreachable` 0xdda489b8) and a per-side racket-offset
   position; stores first/last accepted sample and position (`CandidateSet+0x30/+0x40/+0x50/+0x54`).
3. **Reach evaluation** `fn_8868B4E8` (per set) -> `CandidateSet.reach_speed[i]` ("Reachability", m/s) and running minimum
   `+0x1c`; `fn_8868BD80` sets `valid_a` of both sets; (`fn_8869B0A8`: debug marker, vector only). Driver `fn_8869B128`.
4. **Side select + windows** `fn_8869AB70` calls `fn_8869A520` for both records (builds the contiguous `Gp2ReachWindow`
   lists from types / reach speed under the style filter in the 16-byte style record) and then keeps the side with the smaller
   `ReachRecord.side_offset` in fallback mode, plus tuning-curve refinements (`+0x14c`) otherwise.
5. **InputNotation** `fn_8868AF88` (input-driven players only): `fn_8868A6B8` / `fn_8868A2E8` / `fn_88689B50` write
   `ReachRecord.input_notation[i]` with `fn_88678A88` (linear fill between the two ends of each window, ends 1.0/0.0 or 0/1
   chosen by which end the stick points towards); the stick angle is `PlayerState+0x444` (+pi on one court side) wrapped
   with `fn_8817B608`; stick intensity `+0x440 > 0.2` selects the directional path; `fn_8868ADC0` then blends
   `v = v*w + (1-w)` with `w = curve(+0x1e0)(|angle error|)`.
6. **Selection Score** `fn_88689508` (both sides via `fn_88689AF0`): per sample fills a `Gp2SwingQuery` and runs an
   **analyser** (`fn_8890E988`, a data driven node graph of CAnalyserFramework) whose output is the score.
   Inputs: ball height, InputNotation (input-driven only), Ball Difficulty, Reachability, ticks since the first sample,
   a lateral side measure. Hard rule in code: required speed > 50 m/s (pool +0xf0) gives score -1 without running the analyser.
   Which of the 5 analysers runs: volley candidates use `F+0x94` (input-driven) or `PC->0x50+0x19c` (otherwise);
   non-volley use `F+0x0c` or `F+0x50` (when `PlayerState+0xbd5`) or `PC->0x50+0x158`. The weights are data, not code.
7. **Commit** `fn_8865DBA8` (arg-max of Selection Score over all windows; flags exclude_volley/only_volley, callers pass 0,0)
   inside `fn_886A2E48` (try one style): window hysteresis, writes `PlayerState+0xbc8/+0xbd1`, rolls the hit-quality grade.

Per-frame decision order (fn_886A9E48(B, current_state) -> new state): skip if neither record has a valid side; `fn_886A3610`
(refresh); too-late test -> state 0xd; `fn_886A9DF0` (styles +0x238 then +0x248) -> state 0xb; `fn_886A3440` (AI: style +0x1f8) -> state 3;
else `fn_886A33C0/32B8` -> state 0xf, then `fn_886A2E48` with style +0x218 (only if `PlayerState+0xbd5`), +0x208, again +0x218,
+0x228; if a commit happened `fn_88699FC0` (required speed / movement type, WP3) picks the movement state. States are small ints
(3, 4, 0xb, 0xd, 0xe, 0xf, 0x14 seen). Meaning of each state is WP3's job (not analysed here).

## 4. Reach evaluation formulas (fn_8868B4E8), exact structure

Let `d = sample_position_of_this_side - player_pos` (cm), `T` = ReachTuning (`E+8`, data), `pool` = `g_ts4_script_constants`.
* Initial: `reach_speed[] = 0`, `best = FLT_MAX`, `R = PlayerState.0xbd2 ? T[+0x100] : T[+0xf4]` (reach radius),
  `anim_busy = fn_886CD3C8(PC->0x60)` (ticks the current animation blocks the swing).
* `side_faces_ball` (stack flag): 1 if the prediction is empty; otherwise `cross = (first-player).x*(last-first).z - (last-first).x*(first-player).z`;
  `(cross < 0) == (this set is set 0)`.
* Per sample type `t = types[i]`:
  * `t == Unreachable` or (`t == Volley` and `d.x + 150 < 0`): `reach_speed = 100.0` (pool +0x20).
  * volley: `radius = 10.0`; if `side_faces_ball`: `v = (max(|d.x|-T[+0xf8],0), 0, max(|d.z|-T[+0xfc],0))` else `v = d`;
    remembers the last volley index.
  * otherwise `v = d`, `radius = R`.
  * `prep = volley ? T[+0x108] : (0xbd2 ? T[+0x10c] : T[+0x104])`, `ticks = sample.tick - Clock+0x310`.
  * `|v| < radius` (already in reach): `slack = ticks - prep - anim_busy`; `reach_speed = (slack < 1) ? FLT_MAX : 0`.
  * else: `angle = atan2(dz', dx')` of `v - (PC->0x5c)+0x50` (?), `turn = table(PlayerTuning+0x17c; |angle|, PC->0x5c+0x68)`
    (fn_8826D278), `p = predicted player position after turn ticks` (fn_8867A908), `run = |sample - p| + |p - player|`,
    `avail = ticks - prep - turn - anim_busy`; `avail < 1` -> `reach_speed = 100.0`; else
    `reach_speed = clamp(((run - radius) / avail) * 0.6, 0, FLT_MAX)`.
  * running minimum into `+0x1c`.
* Post pass (volley only): `k` = number of preceding volley samples to cap, from a piecewise-linear table at `T+0xcc` evaluated at the
  parameter of a ray intersection (fn_881896F8) (details not recovered): `reach_speed[j] = min(reach_speed[j], reach_speed[last_volley])`
  for `j` from `last_volley-1` down while `types[j] == Volley`.
Thresholds from data: every `T[...]` field, `PlayerTuning` curves, and the pool constants above. Constants in code:
10.0 (volley radius), 150.0 (volley behind margin), 100.0, 0.6, 1.0 tick slack, 50 m/s cut in scoring.

`fn_8868BD80`: `offset_k = dot(normalize((-dz, 0, dx)), P - first_k)` with `(dx,dz) = last_k - first_k` of set k and `P` the player's
position predicted `pool[+0x61c] = 25` ticks ahead (`fn_8867A908`); `valid_a[0] = offset_0 > T[+0xb8]`, `valid_a[1] = offset_1 < -T[+0xb8]`;
if both, keep the one with the smaller `|offset|`.

## 5. Volley vs groundstroke

The distinction is **per ball sample**, as a candidate type hash in `CandidateSet.types[i]`, assigned in `fn_8869B178`:
```
in_zone  = bounce_field <= 2 && i < first_sample + lookahead(table T+0xc0) && |p.x| < T[+0xd8]
low      = p.y < T[in_zone ? 0x44 : 0x40]
overhead = !low && T[in_zone ? 0x48 : 0x50] < p.y < T[in_zone ? 0x4c : 0x54]
type     = low ? (in_zone ? Volley : Baseline) : (overhead ? Smash : Unreachable)      (assigned only if |p.x| > 150, else Unreachable)
```
(semantics of `low/in_zone` are (?): x is probably the along-court axis with the net near 0, which would make in_zone the volley depth zone.)
Downstream effects of `type == Volley`: smaller reach radius (10 vs `R`), box dead zones instead of a point, different prep time
(`T+0x108`), a "behind you" rejection (`d.x + 150 < 0`), a different analyser for the Selection Score (volley analyser),
and the post pass capping earlier volley samples. `fn_8865DBA8` has the flags exclude_volley / only_volley for style-restricted picks.
The `Smash` tag is carried through but I found no smash-specific branch in this package (the style records at PlayerTuning+0x1f8..+0x248
presumably filter by type in `fn_8869A520`, not decoded).

## 6. Selection, commit, grade

6.1 Side: two ReachRecords (record 0 = side flag 1, record 1 = side flag 0 in the arg-max). `fn_8869AB70` first builds the windows
(`fn_8869A520`), then when the style is the fallback record (`PlayerTuning+0x228`) keeps the side with the smaller `side_offset`.
6.2 `ReachRecord.side_offset` (`+0x24`, FLT_MAX initially) is the lateral miss measure of that side (written by fn_8869A520, not decoded);
`min` of both is added (via curve `PlayerTuning+0x188`) into the query.
6.3 Commit (`fn_886A2E48`): see drafts/gp2_selection.c. Condition summary: new best `idx/side` from the pipeline; if the old target is
still inside a window of the best side's record, switch only when the new best is in the same window (otherwise keep the old target);
always switch when the side changed or the old target is in no window; no candidate at all: rerun with the fallback style
(`PlayerTuning+0x228`) and only store the fallback index (`+0xbcc`).
6.4 Hit-quality grade, rolled at the first commit after a reset (`brain+0x29c`): analyser `brain+0x19c` with inputs
`[0xf3c]=|player_xz - chosen_sample_xz|`, `[0xf30]=random[0,1)` (fn_8861E598), `[0xf34]=ball+0x68`, `[0xf38]=clock-ball_event tick`;
output `[0xf68]` -> `+0x3a0 = out < 0.5 ? Bad : Good`; `+0x3a4 = out < 0.33 ? Bad : (out < 0.66 ? Medium : Good)`
(Good 0xccb6e1ac, Medium 0xc1df4081, Bad 0xba667f1b; feeds the timing feedback UI strings `Cpp_Timing_*`, (?)).

## 7. Opponent AI

No separate AI decision code was found in this package. The AI uses the **same objects** with `PlayerCtx+0x10 == 0`:
* `fn_8868AF88` (InputNotation) returns immediately; `fn_88689508` skips the InputNotation input (the analyser sees 0);
* the scoring graphs come from `PC->0x50 + 0x158` (ground) / `+0x19c` (volley) instead of `F+0x0c/+0x50/+0x94`;
* `fn_886A3440` commits with style `PlayerTuning+0x1f8` directly (no stick, no style fallbacks).
So what the opponent "calls into" is `fn_886A9E48 -> fn_886A3440 -> fn_886A2E48 -> {fn_8869AB70, fn_8868AF88, fn_88689AF0, fn_8865DBA8}`
and `fn_8868B4E8` for reach. Who sets `PC+0x10` and who writes the AI's own inputs is not located (WP9 / CAnalyserFramework).

## 8. Data dependencies

ReachTuning (E+8), PlayerTuning (PC+0x2c) style records and curves, the analysers' node graphs, `g_ts4_script_constants` floats.
Pool values used: +0x00=1.0, +0x20=100.0, +0x38=-1.0, +0x50=FLT_MAX, +0x68={1.0,-1.0} (select table), +0xf0=50.0, +0x10c=0.2,
+0x114=0.6, +0x130=20.0, +0x1d4=15.0, +0x414=0.33, +0x56c=0.66, +0x61c=25.0. Court/tuning numbers (reach radii, prep ticks,
height bands) are NOT in code.

## 9. Hashes resolved here

Baseline 0f6fb110, Unreachable dda489b8, Left da554856, Volley 71198650, Smash 7eb30f90, Wood 9cafb633, Steps f5e32576,
InsideOut bd8ea388, Good ccb6e1ac, Medium c1df4081, Bad ba667f1b. Unresolved: a2eda1e7 (court-side tag that mirrors x/z, in fn_8865EC70,
fn_8869B178, fn_8868B4E8, fn_8868AF88), 993894c6 (analyser leaf node type), 18cdff16, 7110d0bb (GP1).

## 10. Matching status

Matched (work/specs/GP2/gp2_swing_wrappers.json, 10 functions, 896 bytes): fn_886B0418, fn_8869B128, fn_8869AEF8, fn_88689AF0,
fn_886794D0, fn_8866C830, fn_8866C578, fn_886A39A8, fn_886A9628, fn_886A2DF0.
Near match (draft): fn_8865DBA8 (size 0x708 vs 0x784, same branch shape, register allocation differs).
Drafts: gp2_reach_eval.c (fn_8868B4E8/BD80/B178), gp2_selection.c (commit, score writer), gp2_swing_debug_hud.c (fn_886AC2C8),
gp2_select_best_sample.c (fn_8865DBA8).
Not decoded: fn_8869A520, fn_88689B50, fn_8868A6B8 exact weights, fn_88678C68, fn_8869B0A8 marker (vector), fn_886A3610, fn_886A3440 (rest),
fn_886A33C0, fn_886A32B8, fn_886A3238, fn_886A31B8, fn_886A24D8, fn_886A9E48 state meanings (WP3).
Compiler idiom learned: a pointer reloaded in the original (not CSE'd) can be reproduced by reaching it through two different member
paths of the same address (struct view with `sets` at +0x2c vs `evaluator.sets` at +4); `bool = a == 0 && b == 0` stored in an
`unsigned char` reproduces the cmplwi/li/clrlwi pattern of fn_886A9628.
