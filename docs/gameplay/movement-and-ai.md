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
* `PlayerCtx` (see gp2 2): `+0x10` human, `+0x14` slot, `+0x2c` MoveConfig, `+0x44` input system, `+0x48` world, `+0x4c` opponent team,
  `+0x50` profile (`+0x28` skill record: `+0x1dc` reaction frames, `+0x1b0` AI reach float written in state 1), `+0x5c` aim
  controller, `+0x60` swing animation controller, `+0x74` PlayerState blackboard `bb`, `+0x78` anim state (`+0x468` current
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
| 10,11 | AltA/AltB | profile `+0x238`/`+0x248` move (override 1.0); zone `cfg+0x300` | 12 |
| 12 | AltSwing | `fn_886A2BE8` -> 20; replan 1 -> 9 | 9, 13, 20 |
| 13 | Hold | stored command `P+0x288/28c` re-applied | stay (leaves via other states' calls) |
| 14 | BallWindow | replan checks while the swing flags `bb+0x5de/5df` decide | 9, 13, 17 |
| 15 | Choose | AI only (human waits > 3 ticks): `fn_8865DBA8` with `bb+0xbd0` selecting volley-only (-> 16) or non-volley (then fn_88699FC0) | 16, 17, mode state |
| 16 | Volley | volley candidate move | 9, 13 |
| 17,18 | ReadyA/B | wait until ball arrival < 20 (or 1) frames; 18 also sets side flags `bb+0xfae/0xfaf` using handedness (Left) | 13 |
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

### A.5 Target positions
* **Contact target:** sample `bb+0xbc8` of the plan buffer (positions at buffer `+4`, 16 B stride; type hash at `+0x24`; reach
  speed at `+0x10`), committed by fn_886A2E48 (gp3 5.4). Move command: fn_886884E8 sets `bb+0x9d0 = -atan2(dz,dx)` of the
  predicted position (fn_8867A908, look-ahead) and `bb+0x9d4 = 1.0`; copies to `P+0x130/0x288`.
* **Recovery:** there is no recovery-position state; "recovery" is states 7 (turn), 8 (stop) and 13 (hold the last command) plus the re-plan
  loop 9. The wait positions after a shot come from the second (hashed) machine and the base profile `cfg+0x1f8`; not decoded (L).
* Mirroring: when the court-side tag differs, x/z are negated before planning (gp3 1B.3).

### A.6 Speed selection (V)
fn_88699FC0: default **5**; profile `+0x248/+0x238` -> 0xB; `+0x1f8` -> 3; Volley sample -> 0x10; else tries Rush (only if the player value
`(ctx+0x6c)->+0x158` > `cfg+0x630`), JogJog, Jog with fn_88688948 (gp3 5.4 describes the validity maths); none valid: side-angle test may give 6. Speed *within* a
regime: states 21/22 run fn_88688678: every `cfg+0x3ec` frames (period) the stored value `P+0x140` decreases by step `P+0x150` and is published to
`bb+0xde8/0xdec`; step = curve(`cfg+0x3b0`)(distance, ...); walk/sprint thresholds are data. `P+0x121/0x122` are cleared when a regime is chosen.

### A.7 Reaction delay (V)
1. State 0 waits `profile+0x1dc` frames after the opponent's last hit (stamp `(opp team+0x24)+0x68`), unless the opponent mode is 2.
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
(stick aim, neutral, auto-target via fn_8869BEF0); AI gets neutral/auto because the stick is zero -> shot direction from the auto target.
Shot type = the animation family of the chosen candidate (profile record); power/timing come from the analyser graphs (gp8) and the grade roll; I found no
separate "power" decision for the AI (L). Difficulty scaling lives in data: per-player graphs, the skill float of B.1(4), reaction frames `profile+0x1dc`, tuning curves.

### B.3 Plug-in point
Same objects as the human: `PlayerCtx+0x10` gates only (1)-(5). A reimplementation needs: a candidate list per ball sample, a scoring callback, `ai_argmax`, the planner,
and the polar move command (`ref/gameplay/ai_driver.c`).

## C. Function table
See `docs/gameplay/movement-symbols.csv` (name, confidence, evidence). Not byte-matched: no `src/` files produced (VMX128-heavy bodies).

## D. Unknowns
Names of hashed states in fn_886B3CF8 (several resolve by CRC: LetIn, LetOut, Net, Flat, Good, Idle, Rush, Jog, Left, Human, Volley, Baseline, Receiver); exit conditions of rows 10-18; exact
vector geometry in fn_88688948/fn_886887C0 (VMX128); aim auto-target maths (fn_8869BEF0); fn_88699300 per-state prepare bodies; where the stick `bb+0x448/0x44c` is written for humans.
