# Movement planner and opponent input path (agent `movement`)

Module Swing_DLL.xex, base 0x88000000. Method: PPC disassembly (capstone) plus Ghidra 12.1.2 decompilation of
the decoded functions (VMX128 words neutralised locally because Ghidra cannot decode them; vector geometry is
therefore described from the disassembly, not the decompiler). Hash IDs are CRC-32 (IEEE) of the ASCII name,
`fn_88608590(seed 0, str)`; reproduce any name with `python3 -c "import zlib;print(hex(zlib.crc32(b'Rush')))"`.
Confidence: **V** verified by reading the instructions/decompile, **I** inferred, **L** guess.

This note builds on the PR notes `docs/gameplay/gp3.md` (sections 5.1-5.5, state table) and `gp2.md` (selection,
section 7 "Opponent AI") and only adds or corrects. Their function names are used unchanged.

## 0. Corrections and additions to gp2/gp3

1. **Mode records are swapped in gp3 5.2/5.3.** In fn_88688948 the compare `rec == cfg+0x270` selects the `[Rush]` log
   strings, `rec == cfg+0x284` selects `[JogJogPrepared]`, otherwise (`cfg+0x298`) `[JogPrepared]` (V: r25 = (rec==+0x284)
   chooses 0x880F3A58/3AF4/3B94 = "JogJogPrepared"). fn_88699FC0 tries +0x270 -> state 0x14, +0x284 -> **0x15**, +0x298 -> **0x16**.
   So **state 21 = JogJogPrepared, state 22 = JogPrepared** (gp3 has them the other way round).
2. **`PlayerCtx+0x10` is the "is human" byte** and it is set in the player init fn_8869DEF0:
   `ctx+0x10 = (player_info+0x18 == crc32("Human"))` (V). gp2 section 7 said the setter was not located.
3. State 13 is not terminal: it is **Hold** (re-applies the stored move command every frame). State 19 is **Reach** (lunge).
4. There is **no separate AI decision function**; the opponent is the same pipeline with `ctx+0x10 == 0` plus four concrete
   differences listed in section B (V). The virtual stick the AI produces is a polar move command written by the planner.

## A. Movement planner

### A.1 Objects (V unless marked)
* `PlayerController` (gp3 name; ctor fn_886A9050, vtable 0x880F4478, size 0x5A0): `+0x1c` PlayerCtx, `+0x24` MovementPlanner,
  `+0x28` byte "planner enabled", `+0x2c..+0x38` a second state machine over **hashed** states (fn_886B3CF8 next-state,
  fn_886A84C0 enter, fn_88678468 leave; it handles input flags `bb+0x470..0x473`, `+0x58d..+0x59e`; its state IDs are CRC hashes,
  e.g. Net and Flat appear in it; I did not name them, I).
* `MovementPlanner P` (ctor fn_886A3AC8, vtable 0x880F46F0): machine record `+0x14` {cell*}, `+0x18` self, `+0x1c` previous
  state, `+0x20` frames in state, `+0x24` current search profile, `+0x2c` plan buffers (2 x 0x60, selected by `bb+0xbd1`),
  `+0x38` selector F (gp2), `+0x118` window records, `+0x120` "search blocked", `+0x121/+0x122` rush-distance flags,
  `+0x123` replan latch, `+0x124/+0x128` turn latch + 10-frame counter, `+0x125` **pending interrupt**, `+0x12c` saved state,
  `+0x130/+0x134` last move command (heading, intensity), `+0x138` saved candidate index, `+0x13c` swing flag, `+0x140/+0x150`
  jog speed ramp value/step, `+0x14c` ramp initialised, `+0x158/+0x19c/+0x1e0/+0x224` data graphs (analysers), `+0x280` frame
  stamp when the current plan was committed, `+0x285` command valid, `+0x288/+0x28c` stored command, `+0x294` suppress flag,
  `+0x295` rush allowed, `+0x29c` "grade rolled", `+0x2a0` frame the reaction started (-1 none).
* `PlayerCtx` (see gp2 2): `+0x10` human, `+0x14` slot, `+0x2c` MoveConfig, `+0x44` input system, `+0x48` world, `+0x4c` own team (GE2: `fn_8866D368(team)` returns the other team's hitter),
  `+0x50` profile (`+0x28` skill record: `+0x1dc` reaction frames, `+0x1b0` AI reach float written in state 1), `+0x5c` Mover (GE2: smoothed velocity +0x50 and speed +0x68 in m/s, MoveMode via `fn_8869C010`; repositioning.md s5), `+0x60` swing animation controller, `+0x74` PlayerState blackboard `bb`, `+0x78` anim state (`+0x468` current
  locomotion id: Idle / Rush / Jog hashes), `+0xb4` ball prediction owner.
* Blackboard outputs of the planner (V): `bb+0xbc8` committed sample, `bb+0xbd1` side, `bb+0x9d0/0x9d4` **move command**
  (heading rad, intensity 1.0), mirrored to `+0x9d8/0x9dc`, `+0x9e8/0x9ec` previous command, `bb+0xde8/0xdec` **speed override**
  (value, valid byte; 1.0 = full speed, 0.0 = stop), consumed by fn_8866FB60 (animation speed query, keyed by the
  locomotion node hash).

### A.2 Per-frame flow (V)
fn_886BF360 -> fn_886BF260 -> (if planner enabled and it is this team's turn) fn_886BD690:
refresh candidate sets when `bb+0xbc8 == -1`; loop <= 8 times `next = fn_886B8468(P, cur)`; on change `fn_8865DAC0(cur)` (leave),
`fn_88699300(next)` (prepare: a 23-way switch), then after the loop `fn_886AA280(state)` (enter effects, below). Both `next` and
`prepare` are 23-entry jump tables (V).

### A.3 States
Enter effects (fn_886AA280, V): 0/15 copy previous command; 1 and 2 reset the aim controller (`fn_8869C010`) and run the
reaction graph (fn_886A3868); 2 also forces speed override on with 1.0; 3/12 `fn_8866BDD8` (write swing target); 6 recompute
heading with `cfg+0x34c`; 7 speed override = 1.0; 8 override = 0.0 and zero command; 9/17/18 zero the command; 21/22 start the
jog ramp (`fn_88688678`).
Edges are from `li r21,N` assignments and the decompile of fn_886B8468 (V). Names are mine (I) except 20/21/22.

| # | name | meaning (I) | exits |
|---|---|---|---|
| 0 | Wait | idle until `frames_since_opp_hit >= profile+0x1dc` (reaction delay) or opponent team mode == 2 | 1 |
| 1 | AnticipateA | decide: pending candidate -> 14; selector fn_886A9E48(1); when nothing changed and rally active: shot window fn_88678548 -> 18, ball window fn_886877A8 -> 17 unless prepared/Rush/Jog, else Hold (13); leaves to 2 when the hold window (`bb+0xdf8`, `bb+0xdf4`, P+0x2a0) expires | 2, 13, 14, 17, 18, selector result |
| 2 | AnticipateB | same with selector arg 2 | 13, 17, 18, selector result |
| 3 | SwingReady | animation found; waits for zone `cfg+0x2ac` | 4 (sets interrupt) |
| 4 | Swing | replan result 1 -> 9, -1 -> 13 | 9, 13 |
| 5 | Approach | `fn_886A3440` -> 3; zone `cfg+0x2b8` -> 6 (interrupt); `fn_886A26E0` -> 19; else re-search with profile +0x208 | 3, 6, 9, 13, 19 |
| 6 | ApproachNear | as 5 without the zone test; replan 1 -> 9 | 3, 9, 13, 19 |
| 7 | Turn | transient from an interrupt: heading hold counter P+0x128 = 10, prepare(saved), then back | saved state |
| 8 | Stop | transient: override 0.0, waits >= 4 frames and locomotion stopped | saved state |
| 9 | Replan | hold; re-run search with `P+0x24`; resume `P+0x12c` while the new sample stays within +-10 of `P+0x138`; 3 if swing available; 0x14 if alt-swing ok | saved, 3, 20 |
| 10,11 | AltA/AltB | profile `+0x238`/`+0x248` move (override 1.0, swing target `fn_8866BDD8`); zone `cfg+0x300` -> 12 with interrupt (GE2, C) | 12 |
| 12 | AltSwing | `fn_886A2BE8` -> 20; replan 1 -> 9 (saved 12); rally and replan -1 -> 13; else `fn_8866BD00`, `fn_886A9DF0` (re-search +0x238/+0x248) when `!P+0x120`, override 1.0 (GE2, C) | 9, 13, 20 |
| 13 | Hold | on entry from 14-18 the game copies `P+0x288/0x28C` into `RequiredMove` (`S+0x9D0/0x9D4`) and `#b21d6f76` (`S+0x9D8/0x9DC`); stays (GE2, C) | stay (leaves via other states' calls) |
| 14 | BallWindow | stands still (powers `S+0x9D4/0x9DC/0x9EC` = 0). With `S+0x5DE`: rally, `frames_to_commit < 10` and ball window `fn_886877A8` -> 13 when `fn_886A58F0` or locomotion `0x550171D1`/`0xB3FF5297`, else 17. With `S+0x5DF`: replan != 0, or the direction from the committed sample's stand point to the sample more than 90 deg (pool +0x830 = 1.5707951) from the held heading `S+0x9D0` -> 9 (saved 14) (GE2, C) | 9, 13, 17 |
| 15 | Choose | AI: arg-max `fn_8865DBA8` (0,1) volley only when `S+0xBD0` -> 16 with interrupt, else (1,0) non-volley -> `fn_88699FC0`. Human after > 3 frames: volley-or-bounce choice (`mv_s15_volley_choice`, A.4c), `fn_886894A8` rescoring restricted to Volley or Baseline candidates, arg-max (0,0), else re-search with Rush `+0x228` -> `fn_88699FC0`; none found: rally gates as state 1 (18, 13, 17) (GE2, C) | 13, 16, 17, 18, mode state |
| 16 | Volley | replan 1 -> 9 (saved 16); rally and -1 -> 13; when `!P+0x120` commit `+0x208` (`fn_886A2E48`) and `fn_886787D8`; `fn_8866BD00` (GE2, C) | 9, 13 |
| 17,18 | ReadyA/B | first pass (`P+0x284` clear): 18 after > 5 frames sets BaselineRight/Left `S+0xFAE/FAF` from IsLeftLine `S+0xBD1`; 17 when the sample nearest the player is < 30 frames away sets VolleyRight/Left `S+0xFAC/FAD` from the sign of sample z - player z; both swap for handedness "Left" and set `P+0x284`. Then: current sample < 20 frames away (1 frame when within 50 cm of the zone point `fn_8866E058`) and > 1 frame in state -> 13 (GE2, C) | 13 |
| 19 | Reach | stretch/lunge; after > 10 frames set side flags and swing target | 9 |
| 20 | Rush | speed regime | 3, 19, 22, 6, 13 |
| 21 | JogJogPrepared | speed regime (+0x284 record) | 3, 19, 22 |
| 22 | JogPrepared | speed regime (+0x298 record) | 3, 19, 6, 13 |
Reference: `ref/gameplay/movement.c` (`mv_next_state`). Rows 10-18 are approximations of the exit conditions (L/I); rows 0-9, 20-22 follow the decompile (V).

**Interrupt / forced turn (V):** states 3/5/10 and others set `P+0x125`. On the next call the prologue clears it; when the
contact sample is within the 250 cm (cm^2 62500) radius and the locomotion id is not Idle/230a53b8 and the angle tests pass,
the planner enters 7 (turn) or 8 (stop, if the heading dot is positive) and remembers the origin in `P+0x12c`.

### A.4 Predicates (V = decompiled)
fn_886A3440 (V): swing is startable: `bb+0x47e` set; humans additionally need stick intensity `bb+0x440 > const` and stick angle
within a window (angle optionally +pi when the opponent team index has the court-side tag); then `fn_886A2E48(cfg+0x1f8)`.
fn_886A26E0 (V): reach/lunge test using the ball sample at `bb+0xbc8`, handedness (Left) mirrored per-stroke-level tuning
`cfg+0xa0/+0xac`, distance-squared against `cfg+0x3f4`, window `cfg+0x3bc/0x3c0`; on success writes the reach animation request to `ctx+0x78+0x3d0..0x3d8` from
`cfg+0x3c4..0x3e0`. fn_88687AC0/fn_88678708 (V): "zone" tests; a zone record is {a,b,radius} at cfg+0x2ac, 0x2b8, 0x2f4, 0x300;
true when the squared distance (fn_8866BC48) is below radius^2 (88687AC0 adds a heading-crossing test). fn_8865DB50 (V):
`0 <= now - P+0x2a0 <= bb+0xdf4`. fn_8866D930 (V): rally active = not in LetIn/LetOut, or the let deadline passed.
fn_8866C150 (V): `bb+0x9d4 > const && !P+0x294`. fn_8866BFE8 (V): frames to the sample minus predicted run time.

### A.4b Window predicates of states 1/2, 12 and 19 (GE1, C unless marked)
Each starts with the rally gate (match state not a let, flags `match+0x328/0x32A` clear,
opponent mode != 2, ball prediction non-empty; I for the exact let-state logic). Models:
`ref/gameplay/movement.c` `mv_ball_window`, `mv_shot_window`, `mv_alt_swing_ok`.
* **fn_886877A8 (ball window, -> 17):** `|S.LocalPosition.x| < 810 cm` (consts+0x618) **and**
  (`TimingState frames to contact S+0xCF0 > 40` (consts+0x404) **or** `|d| > 400 cm`
  (consts+0x3F8)), where `d` is an output of the 2-D line intersection `fn_881896F8` between
  the ball path and the player (I for the geometry). So a player in the forecourt with time, or
  far off the ball's line, waits in ReadyA.
* **fn_88678548 (shot window, -> 18):** `S.LocalPosition.x + 800 < 0` (consts+0x4A4; more than
  8 m behind the net in planner coordinates) **and** (the opponent side tag
  `(team)+0x84 == 0x2C59FAEA` when `world+0x78 -> mode == 2`, **or** the distance
  `fn_8866E058` from the player to the zone `fn_8866E318(world+0x44 +0x1B0)` is below 50 cm,
  consts+0xF0). I: the zone is a court positioning box.
* **fn_886A2BE8 (AltSwing, 12 -> 20):** `frames_left = sample[bb+0xBC8].tick - clock`.
  If `(ctx+0x84)+0x14 == 0`, `frames_left < 10` and the stick test passes (humans:
  `|wrap(Stick_MovePolar.Angle (+pi on the 0xA2EDA1E7 side))| > 1.5 rad` and `Power > 0.2`; AI
  always), it re-runs the search with the **Rush** profile (`PT+0x228`, `fn_8869AEF8`), picks with
  `fn_8865DBA8`, and on success commits the sample and side, clears IsSmash `S+0x5DA`, stores
  the profile in `P+0x24` and returns 1. Otherwise it restores the flags and returns 0.
* **fn_886A58F0 (Reach swing request, state 19):** when the input and match flags allow and a
  sample is committed, writes the reach animation request `ctx+0x78 +0x3D0..0x3E0` from
  `PT+0x3D4/0x3D8/0x3E4/0x3E8` shifted by the frames left, the side offset consts+0x20 or
  +0x4F8 by `bb+0xBD1`, runs the clip fit `fn_886D3AD8` when the swing controller allows, and
  stores its result in `Context.IsMiss` (`S+0x5E3`).
* `fn_886A9678`, `fn_886A33C0` and the geometry of `fn_88688948` / `fn_886887C0`: section A.4c (GE2).

### A.4c Replan check, volley-or-bounce choice and mode geometry (GE2, C unless marked)

Models in `ref/gameplay/movement.c` (`mv_replan_check`, `mv_line_intersect`, `mv_run_angle`,
`mv_mode_slack`, `mv_mover_step`, `mv_volley_or_bounce`, `mv_human_reach_input`); constants in
`data/gameplay/repositioning.yaml`. `P+0x10` is the current planner state (the machine cell
`P+0x14` points at it; `fn_886BD690`).

* **fn_881896F8 (2-D line intersection)**: `(P1, D1)` at `r3`, `(P2, D2)` at `r4` (point +0, direction
  +0x10), x-z only. `den = cross(D1, D2) = D1.x D2.z - D1.z D2.x`; if 0 it copies `P1` to the output and
  returns whether the lines coincide. Else `t1 = cross(P2 - P1, D2) / den`, `t2 = cross(P2 - P1, D1) / den`,
  output point `P1 + t1 D1`, `*r6 = t1`, `*r7 = t2`, returns 1.
* **fn_886A9678 (replan check of states 4, 6, 12, 16)**. Latch `P+0x123`: from the second frame in the
  state it is set once the swing clip has passed its marked event (`fn_886A0188` on the latest of the
  10 animation-history entries at `ctx+0x64`; it finds the last queued clip with an event and
  `fn_886D1C70` returns `clamp(event time) <= current time`; I for "event = contact"). Until then
  it writes the swing target from `LocalPosition` and returns 0 (in state 16 it also sets
  `(ctx+0x64)+6`). After the latch: `A` = the committed ball sample (y = 0, mirrored into the
  local frame by `fn_8865E730`), `Q` = the side's stand point (plan buffer `P+0x2C` (+0x60 when
  `S+0xBD1 == 0`), self-relative array at +4), `B` = `LocalPosition`, `C` = the player's position
  predicted 20 frames ahead (`fn_8868ED00`). With `u = norm(A - Q)`, `along = (C - Q).u`,
  `lateral = (C - Q).(-u.z, u.x)`:
  `arrived = |lateral| < 40` **and** (`(Q - A).(C - B) > 0` ? `-30 < along < 0` : `-20 < along < 30`).
  Returns **1 when arrived and at most 10 frames remain** to the sample (-> state 9), **-1 when
  arrived earlier** (-> state 13, hold), else 0. Constants: pool +0x404 = 40, +0x79C = -30,
  +0x42C = 30, +0x134 = -20. It reads no PlayerState grade: the "S+0x798/0x79C" reads that gp4b
  s7 and gp8 attribute to this function are the pool offset +0x79C (correction).
* **fn_886A33C0 / 32B8 / 3238 / 31B8 (state 15 tests in `fn_886A9E48`)**. Each re-runs the side
  select, InputNotation and score (`fn_8869AB70`, `fn_8868AF88`, `fn_88689AF0`) for one profile with
  `PT+0x1B8` cleared, then `fn_8865D8D8`: for the last valid side record, **true when the type of the
  first window's start sample is not Baseline and the type of the last window's end sample is
  Baseline**. That means the ball can be volleyed now or played after the bounce. On true the
  profile is stored in `P+0x24`.
  Profiles: `33C0` Steps (+0x208), `32B8` Steps with `Steps.Reachability.MaxSpeed` (PT+0x210)
  temporarily 6.0 when the nearest Volley candidate (`fn_8866C8B8`) is more than 200 cm away on both
  sides, **then written back as the constant 3.0** (pool +0x4C, not the data value), `3238` Jog
  (+0x218), `31B8` Rush (+0x228).
  Order in `fn_886A9E48` when `S+0x5DD/0x5DE/0x5DF` are clear: `33C0`, `32B8` -> 15; commit
  `+0x218` (if `S+0xBD5`) or `+0x208`; `3238` -> 15 and commit `+0x218`; `31B8` -> 15 and, if still
  undecided, commit `+0x228`; a commit with the state unchanged goes to `fn_88699FC0`. A human
  whose result is 20 (Rush) without `P+0x295` keeps his state and loses the commit (`S+0xBC8 = -1`).
* **PT+0x1B8 (`#3db13d71`, true on disc), human reach flattening** in `fn_88689068`: for human
  players the Reachability input `S+0xB9C` of every candidate below `best + RangeCurve(PT+0x188)(best)`
  becomes `best`, the others 100 (unreachable), where `best` = the smaller of the two side records'
  `+0x28` (or `+0x2C`) values, also stored in `S+0xBA4` (I: the best reach speed, m/s; the curve maps
  0..8 m/s to a 3.5..0.1 m/s margin). So among nearly equally reachable hit points the score is
  decided by InputNotation (the stick), not by distance. The state-15 tests switch it off.
* **fn_886887C0 (mode slack)**: `D = Q - LocalPosition` (3-D), `E = D - Mover.velocity` where the
  Mover is `ctx+0x5C` (repositioning.md s5: `+0x50` velocity and `+0x68` speed, m/s, 3-frame mean;
  subtracting m/s from cm is what the code does). `prep = Table2D(PT+0x17C)(Mover.speed,
  |atan2(E.z, E.x)|)` (D: 10 frames standing still; at 2 m/s 0 -> 15 frames and at 5 m/s 0 -> 20
  frames, from running straight at the net to running straight back). `slack = (sample.tick - clock)
  - prep - lead`, `validity = Table2D(mode)(|D|, slack)`.
* **fn_88688948**: invalid when `min_distance^2 >= |D|^2`; `lead = fn_886CD3C8(ctx+0x60) +
  PT+0x1AC` (15); valid when `validity >= 0.5`. The rest is debug printing (DebugConfig +0x48/+0x69).
  With the disc tables (D, `player.yaml`) a mode is valid when the slack is **short**: Rush at 400 cm
  when slack < 35 frames (1000 cm: < 139), JogPrepared (+0x298) at 400 cm when < 110, JogJogPrepared
  only from 2000 cm. So the planner sprints when time is tight, jogs with more time, and with even
  more slack keeps the default state 5 (walk, speed override `PT+0x34C`).

* **State 15, human volley-or-bounce choice** (`fn_886B8468` 0x886B9610..0x886B98D4, `mv_s15_volley_choice`).
  After more than 3 frames in state 15: take the ball sample nearest the player's local x
  (`fn_886600E0`). Its candidate type on either side (CandidateSet `+0x24` / `+0x84`) decides:
  Baseline 0x0F6FB110 -> bounce; Volley 0x71198650 -> volley; otherwise volley when
  `|sample x| < 700` (pool +0x82C). A volley stands when `|S+0xC6C| < 225` (pool +0x4EC,
  `ReceiverState.CorridorState.#5ec10cb0`). Otherwise, when the move stick power `S+0x440 > 0.4`
  (pool +0x118), volley = `|stick angle S+0x444| < Table2D PT+0x1EC (InputNotation e7c89177.Range)
  (player x, sample x - player x)`; the angle gets +pi (wrapped) on the far court. The disc table
  gives 1.0..0.4 rad at x = -1100 and 2.1..0.6 rad at x = -700 as the offset grows from -100 to
  300 cm (D; key = player x, I from the argument order f1, f2). So pushing toward the ball from mid-court picks the volley (I).
  `fn_886894A8(volley)` then rescores both sides with `fn_88689068`, giving every candidate of the
  other type Reachability 100 (unreachable), and the arg-max `(0,0)` picks; with no pick it
  re-searches with the Rush profile `+0x228`. With a pick the next state is `fn_88699FC0`;
  without one the state-1 rally gates apply (18, 13, 17).
* **Planner side flags.** States 17 and 18 write `BehaviorTransitionState` VolleyRight/Left
  (`S+0xFAC/FAD`) and BaselineRight/Left (`S+0xFAE/FAF`) once per shot (`P+0x284`, cleared by the
  planner reset `fn_886BA768`). For handedness "Left" (ctx+0x28 -> +0xC = 0xDA554856) right and
  left swap. The state-17 rule uses the sign of sample z - player z; 18 uses IsLeftLine `S+0xBD1`.

### A.5 Target positions
* **Contact target:** sample `bb+0xbc8` of the plan buffer (positions at buffer `+4`, 16 B stride; type hash at `+0x24`; reach
  speed at `+0x10`), committed by fn_886A2E48 (gp3 5.4). Move command: fn_886884E8 sets `bb+0x9d0 = -atan2(dz,dx)` of the
  predicted position (fn_8867A908, look-ahead) and `bb+0x9d4 = 1.0`; copies to `P+0x130/0x288`.
* **Recovery:** inside the planner "recovery" is states 7 (turn), 8 (stop) and 13 (hold the last command) plus the re-plan
  loop 9. The wait positions after a shot are chosen by the repositioning controller `fn_886BB0A8` (GE2, [repositioning.md](repositioning.md)):
  net point 300 cm / baseline point 1300 cm from the net in singles (graph 116), four fixed points in doubles.
* Mirroring: when the court-side tag differs, x/z are negated before planning (gp3 1B.3).

### A.6 Speed selection (V)
fn_88699FC0: default **5**; profile `+0x248/+0x238` -> 0xB; `+0x1f8` -> 3; Volley sample -> 0x10; else tries Rush (only if the player value
`(ctx+0x6c)->+0x158` > `cfg+0x630`), JogJog, Jog with fn_88688948 (gp3 5.4 describes the validity maths); none valid: side-angle test may give 6. Speed *within* a
regime: states 21/22 run fn_88688678: every `cfg+0x3ec` frames (period) the stored value `P+0x140` decreases by step `P+0x150` and is published to
`bb+0xde8/0xdec`; step = curve(`cfg+0x3b0`)(distance, ...); walk/sprint thresholds are data. `P+0x121/0x122` are cleared when a regime is chosen.

### A.7 Reaction delay (V)
1. State 0 waits `profile+0x1dc` frames (GE1: `FinalPositioningComponents.#79b99b60` of the AI record, ai-inputs s5b) after the opponent's last hit (stamp `(opp team+0x24)+0x68`), unless the opponent mode is 2.
2. State 1 enter runs graph `P+0x1e0` that outputs the reaction window `bb+0xdf4/0xdf8`; `P+0x2a0` records the start frame when the move
   intensity `bb+0x9d4` exceeds a constant before `now - last_hit < bb+0xdf8`; the plan stays committed while `now - P+0x2a0 <= bb+0xdf4`.
3. Timing grade (Good/Medium/Bad) is rolled once per plan (gp2 6.4).

### A.7b Tuning data (V for structure)
MoveConfig `ctx+0x2c`: constructed by `fn_886A9050`-class factories 0x8826F5D8/0x8826F630 (0x5A0-byte record), **loaded by fn_888BB670** (0x206C bytes): it walks an XData node (cursor
in r3), looks children up by CRC-32 of the field name (`fn_88150770`), parses floats with `fn_8816CCE0` and curves/tables with `fn_88610A48` and fills the record.
Record layout seen from planner code: search profiles (16 B) at +0x1f8,0x208,0x218,0x228,0x238,0x248; mode records 0x14 B at +0x270,0x284,0x298 (+0x10 = min distance, rest a 2-D table
for fn_8826D278); zones at +0x2ac,0x2b8,0x2f4,0x300 (radius at +8; +0x2c0 is zone 0x2b8's radius); floats +0x1ac,0x230,0x26c,0x630; curves +0x17c,0x188,0x3b0; int period +0x3ec; reach tuning +0x3bc..0x3f4; 0x44-byte
embedded graph/curve objects (vtable 0x880D7600) at +0x108,0x14c,...,0x548 in the controller. All values are on disc (other agent).

## B. Opponent input path

### B.1 What differs for `ctx+0x10 == 0` (V, decompile addresses)
1. **Selection scoring (fn_88689508):** `bb+0xb94` (InputNotation) is not written; the score graph is `ctx->0x50+0x19c` (volley) / `+0x158` (ground) instead of the planner's own graphs `F+0x94` / `F+0x0c` / `F+0x50`. Graph evaluation is `fn_8890E988` (copies bound floats in, runs nodes, copies out). Inputs bound at `bb+0xb90` (ball height), `0xb94`, `0xb98` (ball difficulty), `0xb9c` (reachability), `0xba0`, `0xbac` (frames to ball); output `0xba8`.
2. **Candidate pick:** state 15 calls the arg-max (fn_8865DBA8) itself (humans wait > 3 ticks for input). Truth table of its two flags (V): (0,0) all, (0,1) volley only, (1,0) non-volley only, (1,1) all.
3. **Stick forced to zero:** fn_8869C010 writes `bb+0x448/0x44c = 0` for non-human players before computing the aim vector.
4. **Difficulty hook:** in state 1 AI temporarily replaces `cfg+0x230` by `fn_886A0EC8(ctx+0x50)->+0x58` (a per-player skill float) around the search (fn_8869AEF8), then restores it.
5. Input-flag logic in the hashed machine fn_886B3CF8 (`bb+0x470..473`) is human-only.

### B.2 Decision flow per frame (V/I)
planner (A.2) -> candidate scores -> arg-max commit (`bb+0xbc8/0xbd1`) -> move command `bb+0x9d0/9d4` + override `bb+0xde8` -> swing request
(state 3/4 via fn_886A3440 with profile `cfg+0x1f8`) -> aim controller picks a mode (fn_886A3DF0 and siblings 886A3C98/40A8/4260): three modes by hash
(stick aim, neutral, auto-target via fn_8869BEF0); AI gets neutral/auto because the stick is zero -> shot direction from the auto target. **Corrected by GE1 ([ai-inputs.md](ai-inputs.md)):** the AI writes `Stick_Aiming` from weighted draws over its AimingSide/AimingLength components; the shot target is `fn_886935A0` ([aiming.md](aiming.md)).
Shot type = the animation family of the chosen candidate (profile record); power/timing come from the analyser graphs (gp8) and the grade roll; I found no
separate "power" decision for the AI (L). Difficulty scaling lives in data: per-player graphs, the skill float of B.1(4), reaction frames `profile+0x1dc`, tuning curves.

### B.3 Plug-in point
Same objects as the human: `PlayerCtx+0x10` gates only (1)-(5). A reimplementation needs: a candidate list per ball sample, a scoring callback, `ai_argmax`, the planner,
and the polar move command (`ref/gameplay/ai_driver.c`).

## C. Function table
See `docs/gameplay/movement-symbols.csv` (name, confidence, evidence). Not byte-matched: no `src/` files produced (VMX128-heavy bodies).

## D. Unknowns
Names of hashed states in fn_886B3CF8 (several resolve by CRC: LetIn, LetOut, Net, Flat, Good, Idle, Rush, Jog, Left, Human, Volley, Baseline, Receiver); exit conditions of rows 10-18 (the predicates they call are now read, A.4b/A.4c); aim auto-target maths (fn_8869BEF0); fn_88699300 per-state prepare bodies; where the stick `bb+0x448/0x44c` is written for humans.
