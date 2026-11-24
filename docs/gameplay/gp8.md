# GP8 notes: shot error inputs (what feeds `fn_886807C0`)

Family GP8, follow-up of GP4B section 10 (`docs/gameplay/gp4b.md`). Module `Swing_DLL.xex`, sha256 `dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44`
(PE image used for byte scans: `orig/54540859/Swing_DLL.dll`, 13,848,064 bytes, sha256 prefix `a7f28b29ef72fcc8`).
Tools: `tools/fn_asm.py`, `tools/sym_info.py`, `tools/fn_check.py` (MSVC 16.00.10224.00 /O2 /Oi), Python 3.13.18, gcc 13.3.0 for the host syntax checks.
Hashes are zlib crc32 of the ASCII name: `python3 -c "import zlib;print(hex(zlib.crc32(b'VeryGood')))"`.
Confidence tags: H = read in code and reproducible, M = read but partly interpreted, L = inference.

## 0. Headline

1. **No instruction in the image stores the six error floats or the three error flags through a literal offset** (H). Scan: every `stw/stfs/stb/sth/stfd` with displacement
   `0x564, 0x718, 0x71C, 0x720, 0x56D, 0x56E, 0x572` and every base register except `r1` over the whole `.text` (see 9.1). All hits are other objects (animation controllers,
   Havok, online stat code) or loads. `S+0x750/0x754` DO have literal stores (section 5); GP4B's "no store" statement was wrong for those two.
2. Values therefore arrive through the **data-driven analyser path**: `fn_8890E988` (CAnalyserFramework evaluate) copies bound input floats into graph slots, runs the node graph and
   copies result slots back to bound output floats. The bindings (`float*` + slot index, built by `fn_88911668 -> fn_88910CF0 -> fn_88910038` from XData descriptor tables, element
   size 0x1070, type hash `0x502FE79D`) point INTO the PlayerState element, with the byte offset coming from data (section 3). So the chain "stats, difficulty, fatigue, timing -> error
   floats" is authored in the analyser graphs of the game data; the code only fixes **which analysers exist, their names, and which inputs are written before they run**.
3. The one analyser whose role is certain from code: **`LetProbability` (crc32 `0xBDD29CAD`) sits at the planner `+0x1C` and is the `rec` argument of `fn_886807C0`**,
   which runs it (`fn_8890E988(rec)`) immediately before reading `S+0x71C` and drawing roll 3 (H). So `S+0x71C` (let chance) is an analyser output (M-high; binding offset is data).
4. **Shot power does not enter the error decision in code** (H for `fn_886807C0`, `fn_88671B10`, the planner `fn_886AE528`; M for the analyser inputs, which are data-bound). Power/"Powerful"
   rules exist only as separate named analysers (section 7) used by reward classification. Timing grade influences code only through the five-level quality factor of `fn_8865AC08`
   written to `S+0x66C+0x12C/0x130` (section 4), never through `S+0x718/0x564`.

## 1. Corrections to earlier notes

| Earlier statement | Correct |
|---|---|
| `S+0x750/0x754` never stored | Stored at `fn_8867E3A0 +0x394` (init) and `fn_886AE528 +0x548/+0x558` (per shot) and refined on Net/Let (section 5) |
| `fn_8866DF60` reads `PlayerState+0x700..0x738` | It reads **PlayerTuning** (`PC+0x2C`) `+0x700..0x738` (two zones: volley box `0x700/0x708/0x710/0x718`, baseline box `0x720/0x728/0x730/0x738`, compared with player pos `S+0x8E0/0x8E8`); it sets `S+0x394` to Volley `0x71198650` / Baseline `0x0F6FB110` and the byte `S+0xFA2/0xFA3` |
| `0x703F56AE` unnamed | `VeryGood` (section 2) |
| `Medium` "no entry or another table" | `Medium` has no entry in any grade table; see section 2.3 |
| `0x2C59FAEA` unnamed | `OutFar`; `0x2C59FAEA` is the second out-region class of `fn_88662C08` |
| `PlayerState+0x3A0/0x3A4` hit-quality grades | Confirmed (`fn_886A2E48 +0x308..+0x36C`: base register is the PlayerState `S`), distinct from the 5-level pair `S+0x3B4/0x3B8/0x3BC` |

## 2. Names (all `zlib.crc32`, H unless marked)

### 2.1 Grades
`VeryBad 0x555267AA`, `Bad 0xBA667F1B`, `Normal 0x26296DD2`, `Good 0xCCB6E1AC`, `VeryGood 0x703F56AE` (found by a CamelCase brute force: prefix `Very` + `Good/Bad`),
plus `Medium 0xC1DF4081`. `OutFar 0x2C59FAEA`.

### 2.2 Five-level grade lookups (matched)
* `fn_8865AC08(grade_hash*) -> float`: `VeryGood 1.0 (pool+0x000)`, `Good 0.75 (pool+0x2A0)`, `Normal 0.5 (lbl_8814B910)`, `Bad 0.25 (pool+0x29C)`, anything else `0.0`
  (`VeryBad` is NOT in this function: it returns 0.0 like `Medium`). Matched: `src/xbox360/gp8_timing_grade.c`.
* `fn_8826DD20(table, grade_hash*, out8)` and `fn_8826DDF8(table, grade_hash*, out16)`: copy one 8-byte (2 floats) / 16-byte (4 floats) entry; entry index `VeryGood 0, Good 1, Normal 2,
  Bad 3, VeryBad 4`; default (any other hash incl. Medium) = zeros. Matched: `src/xbox360/gp8_grade_tables.c`.
  So the data tables passed in are 5-entry arrays ordered best to worst (XData record at `shot_record+0x10`, see 4).

### 2.3 Medium
`Medium 0xC1DF4081` appears (a) as the middle value of the 3-level hit-quality grade `S+0x3A4` (`out < 0.33 Bad, < 0.66 Medium, else Good`, pool `+0x414/+0x56C`; `fn_886A2E48 +0x308..+0x36C`),
(b) in `fn_8866E128` (match record `+0x320`), `fn_887E3420`, and (c) as an analyser/rule name in the loader table `fn_886BF598 +0x1E0`. It is never an input of the five-level
factor/table lookups (those use `S+0x3B4/0x3B8`, which only ever hold `Good` by literal stores: `fn_8867E3A0 +0x360/+0x36C/+0x378`). Therefore a `Medium` grade has factor 0.0 only if somebody
passes it to `fn_8865AC08`; no code path does (L: the 5-level fields are never updated in this build outside data).

### 2.4 Analyser names found (all are `fn_8866F028(hash)`-then-`fn_88911668` loads; hash search over a binary-string + tennis vocabulary, then verified by crc32; collisions among 4-word combos were discarded)
| hash | name | loaded at | object |
|---|---|---|---|
| `0xBDD29CAD` | **LetProbability** | `fn_886B7A60 +0x34` | planner `+0x1C` (the `rec` of `fn_886807C0`) |
| `0x54457AD3` | **LetSettings** | `fn_886B7A60 +0x6C` | planner `+0x60` |
| `0xE4F01642` | (unnamed) | `fn_886BCDA8 +0xBC` | planner `+0x104` (run in `fn_886AE528 +0x5D8`) |
| `0xDDA048F3` | **ShotDifficulty** | `fn_886BE1C8 +0x530` | PlayerCtx `+0x154` |
| `0x85F4C811` | **BaselineTimingAbility** | `fn_886B7048 +0x3C` | timing object `+0x00` |
| `0xA6DFABAA` | **VolleyTimingAbility** | `fn_886B7048 +0x9C` | timing object `+0x88` |
| `0x39CFDEBA` | (unnamed, third timing ability, probably smash/other) | `fn_886B7048 +0x6C` | timing object `+0x44` |
| `0xCBE44A9B` | **FatigueIngame** | `fn_886BC1E0 +0x30` | fatigue object `+0x04` |
| `0x6BD1FBAB` | **FatigueConst** | `fn_886BC1E0 +0x110` | fatigue object `+0xD0` |
| `0x340A26E` | **RushSpeedCoef** | `fn_886BE1C8 +0x4F8` | PlayerCtx `+0x110` |
| `0xB5CFF9B7` / `0x4FCC3EB8` | **SwingSpeedCoef** / **VolleySpeedCoef** | `fn_886BB6E0` | |
| `0x9DEB41B3` `0xCFDBD245` `0xC015CB95` `0x5564F5D6` `0x912FAAA2` `0x729975E2` `0xCC20BAEA` `0x743644E7` | PerfectShot, GoodTiming, GoodVolleySwing, HighTopSpin, Powerful, PowerfulBall, AutoSwing, AutoVolleySwing | `fn_886BF598` (18-entry named rule table) | reward/shot classification set (gp1/gp5), not the error model |
| `0x53613CAD` `0x926EEF1B` `0xF1C819AD` | ReturnServeZone, VolleyZone, ZoneLob | `fn_886BF598`, `fn_886B69F8` | |
| `0xDF1F8733` | InputFiltering | `fn_886BDB58` | |
(`0x729975E2 PowerfulBall` was found by 2-word search over words of the binary; `0x912FAAA2 Powerful` by 1-word.)
Unnamed loaded hashes remain (about 25, list reproducible with `anhash.pkl`-style scan of callers of `fn_8866F028`); several are probably per-style names.

## 3. Mechanism: how data reaches PlayerState floats (M-high)

* PlayerState array: typed XData array, element size `0x1070`, type hash `0x502FE79D`, lives inside the DebugConfig/tuning root object (`World+0x28`, array handle at `+0xE80`,
  self-relative offset; `fn_886BE1C8 +0x2EC..+0x308`: `S = obj + 0xE80 + *(obj+0xE80) + slot * 0x1070`; fetched elsewhere with `fn_88923530(..., 0x502FE79D)`, e.g. `fn_888BA888`,
  `fn_889117B8 +0x1BC`). `PC+0x74 = S`. The array is the same object that holds the debug knobs read at `fn_886807C0` (`+0x210/0x214/0x218`, `+0x784`).
* The analyser object `vtbl lbl_880D7600` (many instances: PlayerCtx `+0x110..+0x2EC`, planner `+0x1C/+0x60/+0x104`, ...) is initialised by `fn_88911668`. Its bindings are built by
  `fn_88910CF0`: for each 0x10-byte descriptor of the graph's port table it computes `element = array + index * 0x1070`, and the **byte offset inside the element comes from a 0x40-byte field
  descriptor table (XData type `0x2F68067A`) selected by the port**, then `fn_88910038` creates the `{float*, slot}` pairs. Nothing in code mentions `0x718`, `0x71C`, `0x720` or `0x564`.
  The vtable slot `+0x18` of this class is `fn_889117B8` (loads three XData typed arrays: types `0x1A2B0DA3`, `0x2F68067A`, `0x502FE79D`).
* Consequence: the exact formula for `S+0x718/0x564/0x720` cannot be derived from the executable; it is the content of the data files (the analyser graphs named in 2.4 and the
  tuning XData). What IS code and fully known is below.

## 4. Per-shot inputs that code writes (H)

### 4.1 ShotDifficulty analyser inputs (`fn_8868E248`, called per ball sample from `fn_8868FCC0` and from `fn_8868E320` for the current one)
```
d_m   = | S.player_pos(+0xE30 vec4) - sample_pos | * pool[0x1BC]          // pool+0x1BC = 0.01   (cm -> m)
t     = (sample_tick - clock->0x68 ... as int) * pool[0xE0]               // pool+0xE0  = 1/60   (ticks -> s); if t == 0 then t = pool[0] = 1.0
S.7A0 = d_m;  S.7A4 = d_m / t        // distance (m) and required speed (m/s)
fn_8890E988(PC+0x154)                // ShotDifficulty analyser; its output (read back at S.7A8, S.764 by fn_8868FCC0) is "Ball Difficulty"
```
The incoming-ball difficulty therefore depends on (distance to reach, available time) only (plus whatever the graph adds); the same value feeds swing selection
(`gp2.md`: "Ball Difficulty"). I found no direct store of this difficulty into `S.718/0x564`; it can only reach them inside a graph that reads `S.7A8` (binding data).

### 4.2 Grade block `S+0x66C` (`fn_886629C8`, run per planned shot via `fn_88662B60 -> fn_886629C8`, and from `fn_886AE528 +0x430`)
`B = S + 0x66C`, `rec = shot_record` (`PC+0xB0`), `T = *(rec+0x10)` (XData record, else self-relative record at `rec+4+0x10`):
```
B+0x50 (2 floats) = pair_lookup(T+0x00,  grade_A = S.3B4)       // fn_8826DD20
B+0x58 (4 floats) = quad_lookup(T+0x28, grade_B = S.3B8)        // fn_8826DDF8
B+0x68 (2 floats) = pair_lookup(T+0x78, grade_B)
B+0x70 (word)     = use_a4 ? T.0xA4 : T.0xA0     // use_a4 = match.0x32A && match.0xA8 != PC.0x4C->0x28 && PC.0x4C->0x24->0xB8 == PC.0x18 (selects one of two data words)
B+0x12C (float)   = grade_factor(grade_A)                        // fn_8865AC08
B+0x130 (float)   = grade_factor(grade_B)
B+0xA0  (word)    = word at (*(rec+4)) + 0x88
(no-T path: B+0x38..0x4C = six words copied from rec+0x10+offset, B+0x70 = word after)
```
`S.3B4/0x3B8/0x3BC` are initialised to `Good` by `fn_8867E3A0` and not written elsewhere in code, so in this build the factors are `0.75` unless data/other path changes them.
Fields `B+0xAC/0xB0/0xB4/0xE4/0xE8` (= `S+0x718/0x71C/0x720/0x750/0x754`) are NOT written by this function: **`S+0x718` etc. are not part of the grade block output**
even though they lie inside the `S+0x66C` struct footprint. `fn_88695640` (called from `fn_886AE528 +0x444`) fills other fields of the same block (`B+0x88..0x9C` flags from
angle tests of the stick vector `S.430/434` against `rec.0x5C+..`, `B+0xF8/0xFC/0x100/0x104/0x16C` speed/time terms) and `fn_886AE528` writes `B+0x184 = fn_881899D8(curve, ball.4)`.

### 4.3 Shot-class flags (`fn_88662B60`)
`S.573 = (S.3C4 == 0x43961EE3)`  (`0x43961EE3` = crc32 `DefensiveShot`, 2-word brute force, L: could be a coincidence), `S.575 = (S.3CC == 0x7EB30F90 /*Smash*/)`,
`S.57D = S.E6E`, skipped when `DebugConfig.0xF57` is set. (`S.56D/56E/572` are siblings of these flags in the same `0x56x/57x` byte block but have no writer: M, debug/data forced flags.)
Draft: `src/xbox360/drafts/gp8_shot_flags_nearmiss.c`.

## 5. Net / Let aim heights `S+0x750 / 0x754` (H, corrects GP4B)
* `fn_8867E3A0 +0x394` (vtable slot `lbl_880F44EC+0x8`, module init): `S.750 = cfg.0x134`, `S.754 = cfg.0x138` with `cfg = *(World+0x1C)->+0x6C`, and sets `S.3B4/3B8/3BC = Good`.
  It also fills a table of random floats using the match RNG (`0x10DCD` LCG; `fn_88158B28` sizes it to 0x100 entries).
* `fn_886AE528 +0x548/+0x558` repeats the same two stores every planned shot (`S.750 = cfg.0x134`, `S.754 = cfg.0x138`, in cm).
* `fn_886AE528 +0x8E0` and `+0x984` (the two special-outcome branches, which one is Net and which Let was not separated): after `fn_889C1340(vec, ball, cfg+0x124)`
  (net-crossing solve) `S.754 = vec.y`, i.e. on a special outcome `+0x754` holds the height actually reached at the net plane (cm). `+0x750` keeps the configured Net aim height. The cfg values `+0x134/+0x138/+0x124` are data (not readable from the executable).

## 6. `fn_88671B10` (b50 / b51), decoded (M-high; geometry marked ?)
Signature `fn_88671B10(shot_rec, PC, bool *b50, bool *b51)`. (`r5 = &b50`, `r6 = &b51` at the call `fn_886807C0 +0x208`.)
Decision (exact, from the last 40 instructions):
```
if match.0x318 == 0x029EAAF4 (point end):          b50 = 1, b51 = 1
else compute five end points E0..E4 and two groups of four distance tests (below)
  if all five end points are inside the court rectangle [-xmax..xmax] x [zlo..zhi] (bounds fn_8866E318 with serve = 0):
                                                    b50 = 1, b51 = 0   // an error can not push the ball out
  else if group2 all four true:                     b50 = 1, b51 = 1
  else if group1 has no true test:                  b50 = 1, b51 = 1
  else:                                             b50 = 0, b51 = 1   // forced Out
```
Meaning in `fn_886807C0`: `F2 = !b50 || (!C && b51 && A) || OUT`. So `b51 = 0` disables "plain error => Out" (an error then falls through to In or Net only), `b50 = 0` forces Out.
Geometry (?): `R = S.7E0` (player-state length, squared into `f28`), `R' = max(S.7E0, S.7DC)`; angles `a1 = S.44C * pool[0x184]`, `a2 = S.450 * pool[0x184]` (`pool+0x184 = pi/180`, so the fields are degrees);
`fn_8817B3F8 / fn_8817B500` are cos / sin; the shot origin (`rec` vec4) is converted by `fn_8865E730` with the `PC->0x4C->0x24->0xB0` object; the five end points are the aim point rotated
by `+-a1`, `+-a2` and the centre, each scaled by `R'`; the eight distance tests compare squared distances of corner/centre points with `R'^2` / `R^2`. Draft of the combine step:
`src/xbox360/drafts/gp8_shot_error_model.c` (`gp8_error_reach_flags`).
So `S.44C/0x450/0x7DC/0x7E0` are the remaining PlayerState inputs of the out/in outcome (they are consumed here, written by data/analysers; no literal store found).

## 7. Shot power, fatigue, balance, stats (answers to the brief)
* **Power**: not read by `fn_886807C0`, `fn_88671B10`, nor by the Net/Let/Out target code. The only power-like quantities in code are `commanded speed (km/h)` for flight (GP4B) and the
  rule analysers `Powerful`, `PowerfulBall`, `PerfectShot`, `GoodTiming`, `HighTopSpin`... (table `fn_886BF598`, GP1/GP5 reward/class labels). Whether the data graph that fills `S.718`
  also reads a power value cannot be seen from code (data-bound), but the code never supplies one.
* **Fatigue**: two analysers `FatigueIngame` and `FatigueConst` (names found). `fn_886BC1E0` loads them with `0x80CE1A10`, `0x8ADD300F`, `0x9D734117` (unnamed) in one object.
  Their outputs are data-bound; no literal consumer was found in the error path (same limitation as above).
* **Timing**: `BaselineTimingAbility`, `VolleyTimingAbility` (+ one unnamed) analysers (`fn_886B7048`) and the 2/3-level hit-quality grade `S.3A0/3A4` (random roll through the
  analyser at `PC->0x...+0x19C`, GP2 6.4) and the 5-level grade pair `S.3B4/3B8` with factors `0/0.25/0.5/0.75/1` (4.2). The factor goes to `S+0x66C+0x12C/0x130` and the five-level
  tables (`B+0x50/58/68`) are selected by grade. They are read by the swing/animation side (`fn_886A84C0`, `fn_886A9678` read `S+0x798/0x79C`), and `S.718` of `fn_886AE528` is
  accumulated into running match statistics (below), not from them.
* **Movement/balance**: `RushSpeedCoef`, `SwingSpeedCoef`, `VolleySpeedCoef`, `InputFiltering`; none writes to the error fields in code.
* **Stats store**: `fn_886AE528 +0x137C..+0x13B0` reads `S.718` and keeps a running average in the match stats object (`lbl_88D45B0C`; int counters at `+0x30`, floats at `+0x3C`;
  getters `fn_886565E0` / `fn_88656538`, setters `fn_886567A8` / `fn_886569A8`): `stat_f[2] = (S.718 + stat_f[2] * count) / (count + 1)` where `count` is the sum of four int counters
  (indices 0..3) and one of the counters `0x12..0x15` is incremented by shot class. So `S.718` is a per-shot value (re-evaluated for every shot), not a static per-player number (M-high).

## 8. Per-frame / per-shot order (planner `fn_886AE528`, H)
`(per planned shot)` reset `S.750/754` -> run grade block `fn_886629C8` (`B+0x12C/0x130`, tables) -> `fn_88695640` (block floats, flags) -> `fn_886717A8`... ->
analyser at planner `+0x104` (`0xE4F01642`, `fn_886AE528 +0x5D8`, when not replay `S.5D8` and `S.40A == 0`) -> ... -> `fn_886807C0(out, planner+0x1C /*LetProbability*/, rec, target, PC, forced)`:
`P = clamp01(S.718 + S.564)`; roll1; roll2; `fn_8890E988(LetProbability)`; roll3 (with `lo = 0, hi = 1` via `fn_8861E598`); flags `S.56D/56E/572`; `fn_88671B10`; decision (GP4B 10.2);
then the consumer branches (GP4B 10.3) with dispersion box `ball+0x4C0..0x4CC`.
`ball+0x4C0..0x4CC` have literal stores only in constructors/copiers (`fn_882734C8` x3, `fn_88272BC0`, `fn_886A9050`, plus many non-ball objects): H. The dispersion box is data.

## 9. Reproducible measurements
9.1 Literal-offset scan: decode `.text` of the PE image as big-endian 32-bit words, select opcodes `lwz 32, lbz 34, lfs 48, stw 36, stb 38, stfs 52, sth 44, stfd 54` with 16-bit
displacement in `{0x564, 0x56D, 0x56E, 0x572, 0x718, 0x71C, 0x720, 0x750, 0x754}`, base register != r1. Result: stores of `0x56D/56E/572`: none; `0x71C`: `fn_884C2D68`, `fn_8874D270` (non-gameplay);
`0x718`: `fn_885C6340`, `fn_887CF7C0`, `fn_8874D270` (other classes: animation/online); `0x720`: `fn_8819A0B0/A1D8` (other class); `0x564`: 19 stores in 17 other functions (constructors of other objects);
`0x750/0x754`: gameplay stores listed in section 5 and the animation machine `fn_886847F0/fn_886AB760/fn_886ABAE8/fn_886AC130` (a different class: phase counters, not floats).
Vector forms (`stvx128` with `li rX, 0x560/0x570/0x700/0x710/0x720/0x730/0x740/0x750`) in gameplay range only appear in other objects (`fn_886D28E8`, `fn_886D6018`).
9.2 Hash identification: `zlib.crc32` brute force over (a) all identifier-like strings of the PE image split at camel case (10,886 words, 1 and 2 word combinations) and (b) a 309-word curated
tennis vocabulary (up to 3 words). Accepted names are those with a plausible reading in context; 4-word hits were rejected as collisions (`ErrorMissFatiguePenalty`, ...).
9.3 Matches: `python3 tools/fn_check.py src/xbox360/gp8_timing_grade.c ts4_timing_grade_factor_8865AC08=0x8865AC08` and
`... src/xbox360/gp8_grade_tables.c ts4_grade_table_pair_8826DD20=0x8826DD20 ts4_grade_table_quad_8826DDF8=0x8826DDF8` -> MATCH x3 (0x88 + 0xD8 + 0x15C = 700 bytes).
Specs: `work/specs/GP8/gp8_timing_grade.json`, `work/specs/GP8/gp8_grade_tables.json`.

## 10. Open items
* The graph content of `LetProbability`, `LetSettings`, the unnamed planner `+0x104` analyser (`0xE4F01642`) and which output ports map to `S.718/0x564/0x720`
  (needs the game data: the analyser XData and the field-descriptor table type `0x2F68067A`).
* Names for `0xE4F01642`, `0x39CFDEBA`, `0x80CE1A10`, `0x8ADD300F`, `0x9D734117` and about 20 more analyser hashes.
* Exact geometry of `fn_88671B10` (the eight distance tests and the five end points); writers of `S.44C/450/7DC/7E0`.
* Who updates `S.3B4/3B8/3BC` after init (nothing found: always `Good`?). The 5-level tables' content.
* `fn_88662B60` near-miss: the original hoists both kind loads (`S.3C4`, `S.3CC`) before the debug test; see `src/xbox360/drafts/gp8_shot_flags_nearmiss.c`.
