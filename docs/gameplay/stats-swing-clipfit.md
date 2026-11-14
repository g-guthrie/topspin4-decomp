# Stats application, swing-selection window, clip fit (agent `swingstats`)

Module: `Swing_DLL.xex` (image base 0x88000000), PE image `orig/54540859/Swing_DLL.dll`. Confidence tags:
**V** verified (read in code, reproducible), **I** inferred, **U** unknown. No game values are recorded here; constants are named by
address only. Companion code: `ref/gameplay/{stats,swing_window,clip_fit}.c`, `test_swing.c`, `gp_swing.h`; names in `swing-symbols.csv`.

## 0. Relation to the existing PR notes

`gp2.md` (reach, candidate build, selection), `gp7.md` (planner, contact marker), `gp8.md` / `gp4b.md` s10 (analysers) were read
(PR checkout `ts4-pr12`). They already cover B almost fully (`fn_8869B178` types, `fn_8868B4E8` speeds, `fn_88689508` scoring, `fn_8865DBA8`
commit). This work agrees with them (independent derivation, same type rules, same hashes) and adds:

| New here | Section |
|---|---|
| The stat block itself: eight float ratings at PlayerState `+0x64c..+0x668`, skill list `+0x640`, current-stroke skill `+0x74c`, who writes/reads them | 1 |
| The graph runtime ("analyser") fully decoded: 11 node kernels with their crc32 type ids, curve evaluator `fn_8817A688`, bind/eval flow | 2 |
| `fn_8869A520` (listed as "not decoded" in gp2 s10): row extraction and its record layout; `fn_8865DBA8` filter truth table | 3 |
| Planner `fn_886D3AD8` facts beyond gp7; what is still unknown about the cost | 4 |

## 1. A. Player stats

### 1.1 Rating list (V)
`fn_887AC0E0` (script binding for an online/created-player record) pairs 14 int fields at record `+0x04..+0x3c` with the names
Serve, Return, Reflex, Forehand, Backhand, Volley, Power, Speed, Stamina, Mental, Overall, Skill1..Skill4 (names at `0x880EE1C0..0x880EE230`, the
Volley string is shared at `0x880D75F4`). The record also carries PlayerCode/DeviceId/PlayerIndex/name. This is the *external* (integer) form.

### 1.2 In-match stat block (V for layout, I for units)
PlayerState `S` (`PlayerCtx+0x74`, element size 0x1070, see gp8 s3). Floats, in memory order:

| offset | stat | evidence |
|---|---|---|
| +0x64c | Serve | `fn_88694200` pairs it with crc32("Serve") |
| +0x650 | Return | same, crc32("Return") |
| +0x654 | Forehand | compared with +0x658 in `fn_8865B3B0`, `fn_88694200` (crc32 "Forehand") |
| +0x658 | Backhand | same |
| +0x65c | Volley | `fn_88694200` crc32("Volley") |
| +0x660 | Power | crc32("Power") |
| +0x664 | Speed | crc32("Speed") |
| +0x668 | Stamina | crc32("Stamina") |

Reflex, Mental, Overall have no float here (U). `S+0x640` is a self-relative array (count at `+0x644`) of 8-byte `{id u32, value f32}` pairs;
`fn_8869DEF0` (match start) copies the first four entries whose value equals 1.0 into a four-slot list (the Skill1..4 of 1.1) (V). Which
code writes the eight floats is **U**: no literal store with those displacements exists on a PlayerState base (a scan of the whole `.text` finds only
loads), consistent with gp8 s3 (data-bound / block copy).

### 1.3 Where a stat is turned into a number the gameplay uses
* **Current stroke skill** `S+0x74c` (float) is written on entry to a swing state by `fn_88699300` (switch on state id, V):
  ground stroke: Return (`+0x650`) when `fn_8865EB60` says return, else Forehand (`+0x654`) or Backhand (`+0x658`) chosen by
  `(handedness == "Left") != committed side flag (+0xbd1)`; states 0xa/0xb: Forehand; states 0xc/0x10: Volley (`+0x65c`).
  The serve path stores the Serve rating (I, `fn_886BCE88` stores +0x654/+0x658 for the other entry). `fn_886BCE88` runs the analyser at
  `controller+0x504` right after storing it (V), so the skill is an analyser input (bound by name, I).
* **Side preference** `fn_8865B3B0`: if Forehand > Backhand then use the forehand-use counters `(+0xf8)/(+0xf8+0xfc) < threshold(+0x98)`
  else the backhand ones; equal ratings return 0 (V). `fn_886646B8`, `fn_88665010` apply the same FH/BH comparison (V, consumers not traced).
* **Strengths/weaknesses** `fn_88694200`: builds a float-keyed multimap of `{crc32 name, rating}` for the eight stats, compares FH/BH with an epsilon
  (pool constant at `0x880D0934`) and emits two lists of stat ids (best/worst), at most N each (V). Used for presentation, not simulation (I).
* **Rating -> quantity curves**: ratings reach shot quality only through the data-driven graphs (section 2); gp8 s7 reaches the same conclusion
  for power, fatigue, timing. Which graph maps Serve/Power/Speed/Stamina to shot speed, error, reach, run speed, fatigue is **U** (graph
  files are on disc). Code-visible fixed pieces: reach/run-speed unit conversion and the 50 (m/s) cut in scoring (gp2 s3/s4); stamina/fatigue
  analysers `FatigueIngame`/`FatigueConst` exist by name (gp8 s7).

## 2. The curve/graph machinery (V)

Graph instance (`fn_8890E988` = evaluate): `+0x14` float register file, `+0x2c..+0x30` input bindings `{float* src, slot}` (8 bytes),
`+0x20..+0x24` output bindings, `+0x38` array of kernel pointers (one per node), `+0x8 -> +0x4` graph definition. Evaluate = copy inputs to
`regs[slot]`, `fn_8890E8B0` runs the nodes in definition order (`def+0x1c`: rel-array of 8-byte `{rel offset to record, node type crc32}`),
copy `regs[slot]` to outputs. Kernels are looked up by type crc32 at load (`fn_8890E810`, table registered by `fn_8890EA30`). Bindings are
resolved from descriptor hashes against a reflected object by `fn_8817A4F0` (V; offsets come from data, gp8 s3).

| type crc32 | kernel | semantics (record = `entry + entry[0]`) |
|---|---|---|
| 6bbd0182 | 8890DD88 | CONST: `regs[r0] = bits(r1)` (byte-matched, `src/xbox360/gp_swing_8890dd88.c`) |
| dee0059f | 88178F60 | SUM over `r[0]`-relative slot array, count `r1`, out `r3` |
| 9da3605f | 88179050 | PRODUCT, same layout |
| dcce2909 | 88179140 | MIN |
| fb754e38 | 881792E0 | MAX |
| 993894c6 | 88179480 | CURVE: in slot `rec+0xc`, out slot `rec+0x10` (skipped if < 0), curve = the record (`+0` rel keys, `+4` count) |
| 7a741f05 | 881794E0 | running sum; any negative input gives the -1 constant instead |
| 8196eae3 | 88179580 | SUB `r0 - r1 -> r2` |
| b6ea415e | 881795B8 | DIV `r0 / r1 -> r2` |
| 7e683220 | 881795F0 | LERP `r0 + clamp01(r2) * (r1 - r0) -> r3` |
| a68e1dc3 | 88179698 | INVLERP `clamp01((r2 - r0) / (r1 - r0)) -> r3` |

Curve evaluator `fn_8817A688(x, curve)` (V): keys are 0x14 bytes `{x0, x1, y0, slope, +0x10 unused here}`; pick the last key with `x0 <= x`
(first key if none); `y = y0 + slope * clamp(x - x0, 0, x1 - x0)`. This is the piecewise-linear lookup of the task statement. The node
type names (crc32 preimages) are not recovered (U); `ref/gameplay/stats.c` names them by function.

Known graph users (call sites of `fn_8890E988`): selection score (`fn_88689508`, three graphs at selector `+0x0c/+0x50/+0x94`, two at
`PC->0x50+0x158/+0x19c`), hit grade (brain `+0x19c`, gp2 6.4), shot difficulty (`PC+0x154`, gp8 4.1), stroke start (`controller+0x504`), shot
error (`LetProbability`, gp8), plus about 60 sites in `fn_886872A0`, `fn_88686C20`, `fn_8867DEF0`, `fn_886807C0` ... (list: callers of 0x8890E988).

## 3. B. Swing-selection window

Pipeline (agrees with gp2 s3): `fn_8869B178` (build candidate sets) -> `fn_8868B4E8` (required speed per sample) -> `fn_8869AB70`
(per side `fn_8869A520`) -> `fn_8868AF88` (input notation) -> `fn_88689AF0/fn_88689508` (score) -> `fn_8865DBA8` (arg-max) -> `fn_886A2E48` (commit).
Names used by gp2: CandidateSet (0x60 per side), ReachRecord (0x34 per side).

### 3.1 Window builder inputs/outputs (V from gp2 + this pass, math I where vector)
Per ball-prediction sample `i` (0x30 bytes, count from `+0x5a0..+0x5a4`, first usable `+0x5bc`) and per side:
* type id (`CandidateSet+0x24` array): Baseline 0x0f6fb110, Volley 0x71198650, Smash 0x7eb30f90, Unreachable 0xdda489b8 (all crc32, V).
  Rule: `in_zone = bounce<=2 && i < lookahead && |x| < tuning`; `low = y < split[in_zone]`; low -> `in_zone ? Volley : Baseline`; high ->
  `inside smash band ? Smash : Unreachable`; the stored type is the computed one only when the position test of the decompile (|value| beyond a pool
  constant) holds, else Unreachable (as gp2 s5). All thresholds are tuning data.
* position vec4 (`+4` array, racket-offset applied, vector math not recovered, I), required speed (`+0x10` array, `fn_8868B4E8`:
  `((run_dist - radius) / (ticks - prep - turn - anim_busy)) * unit`, 100 when `avail < 1`, FLT_MAX when already in reach with no time, gp2 s4),
  running minimum `+0x1c`, count `+0x08` (mirrored `+0x28/+0x68/+0x88`), first/last accepted sample `+0x50/+0x54` (-1 when none) (V).

### 3.2 `fn_8869A520` row extraction (new, V for fields, I for gating details)
Inputs: ReachRecord `R`, CandidateSet `C`, style record `St` (16 bytes at PlayerTuning `+0x1f8..+0x248`: byte+1 "volley allowed", byte+2 "must equal
is-smash", float+8 speed limit for non-volley, float+0xc for volley). For each sample: `eligible = (St.b1 || type != Volley) && (type == Smash) == St.b2 && side valid
&& reach_speed < limit(type)`. Consecutive eligible samples form a **row** (0x30 bytes, array `R+0x18`, count `R+0x1c`, capacity `R+0x20`):
`+0x20` float (smallest value seen in the run), `+0x24` first index, `+0x28` last index (inclusive). `R+0x24/+0x28/+0x2c` start at FLT_MAX and keep the minimum of
(all / non-volley / volley) eligible values; `R+0x30` = valid flag. `fn_8869AB70` then picks/keeps the side (gp2 s6.1).

### 3.3 Score writer and commit (V)
`fn_88689508` (per sample): inputs written to PlayerState `+0xb90` (a per-sample field of the ball prediction), `+0xb94` InputNotation,
`+0xb98` Ball Difficulty, `+0xb9c` reach speed (replaced by a pool constant for excluded types, and ineligible when it exceeds the 50 cut), `+0xba0`,
`+0xba4`, `+0xbac` (tick delta, -1000 when before the committed sample); runs the graph; result `+0xba8` stored in `R+0xc` array.
Ineligible score = -1. `fn_8865DBA8`: scans rows of both sides, `best` starts at -1, a candidate wins with strictly greater score; type filter with flags
(p4,p5): (0,0)/(1,1) accept all, (1,0) non-Volley only, (0,1) Volley only (V, from the branch structure; gp2 says callers pass 0,0).
Output index and side (side 1 = first record). Swing-kind and quality ids are crc32 of Volley/Smash/Baseline/Good/Medium/Bad (`gp_swing.h`).

## 4. C. Animation clip fit

Facts (V unless noted), in addition to gp7 s6: planner `fn_886D3AD8` walks candidate layers; the clip record (0x8c bytes, rel-array at
`AnimIface+0x164`+0x50) has a marker array (`+0x64`, count `+0x68`, 0x10 bytes `{crc32 name, time, ...}`); the contact marker is
"EventRacket" (0x3B9AD22E) when `record+0xc != -1`, else "Preparation" (0x7F6C2523); marker time is a normalised fraction
(code multiplies by the clip length at `record+0x14` after subtracting the phase-window start and a fixed pre-roll fraction) (I for the exact pre-roll).
Phase windows are 0x28-byte rows (`+0x70`, count `+0x74`); `fn_886D4978` splits them into sub-windows of 0x18 bytes
`{record*, t0, t1, t0', t1', flags}` appended to the planner's list (I). The accepted contact frame must lie in
`[tuning+0x3d0, tuning+0x3d4]` (one range of frames, V) and a second band `+0x3d8/+0x3dc` is read for the position test (I).

**Open (U):** the cost terms (timing error, position error, height, facing) and their weights. The function is vector-heavy (VMX128 root-motion
sampling via `fn_88644CE8`, rotation by `fn_881BD4B8`), the weights are disc data (records of `Animations.bin`/`AnimationsInterface.bin`, loaders
`fn_88774300`, `fn_88773438`, record fields in gp7 s7), and the best cost is stored at planner `+0x170` (gp7 s6). `ref/gameplay/clip_fit.c`
therefore only implements the verified marker -> contact frame mapping and a *scaffold* weighted sum clearly outside the verified set.

## 5. Not found / next steps
1. Writer of the eight rating floats and of the `+0x640` list (block copy or reflection setter; check `fn_888BA888`, `fn_8890B068` consumers of `PlayerInfoList`).
2. Which graph consumes `S+0x74c` and the other ratings (needs the disc graph files; node type names).
3. The clip-fit cost: decode the vector part of `fn_886D3AD8` (VMX128 is not supported by Ghidra 12.1.2 / capstone here: a local decoder was needed).
4. `fn_8868AF88` weights (`fn_88678C68` etc.) as in gp2.

## 6. Reproduction
* crc32 names: `python3 -c "import zlib;print(hex(zlib.crc32(b'Volley')))"` -> 0x71198650.
* String xrefs and `.text` scans: parse the PE section table of `orig/54540859/Swing_DLL.dll` (big-endian PPC words); `tools/disasm.py 0x8817A688 --count 1`
  shows the curve evaluator (capstone stops at VMX128 words; Ghidra decompile of VMX128 functions needs those words patched, which loses vector math).
* Stat block: `tools/disasm.py 0x88694200` (pairs of `lfs d(0x64c..0x668)` with the hash immediates), `0x88699300` (stores to `+0x74c`).
* Self test: `cc -std=c11 -Wall -Wextra -Werror -o /tmp/test_swing ref/gameplay/test_swing.c ref/gameplay/stats.c ref/gameplay/swing_window.c ref/gameplay/clip_fit.c && /tmp/test_swing`.
* Byte match: `TS4_JOB=swingstats work/venv/bin/python tools/try_match.py src/xbox360/gp_swing_8890dd88.c --at gp_swing_node_const=0x8890DD88 -v` (MATCH, 32 bytes).
