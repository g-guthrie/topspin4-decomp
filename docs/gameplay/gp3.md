# GP3 notes: core per-frame gameplay (fn_886B5128), ball step/prediction, tag tracker, movement planner

Module Swing_DLL.xex, sha256 `dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44`, symbols.txt
sha256 prefix ec79e191534b9b28, repo HEAD 5e31a74, Python 3.13, tools/fn_asm.py + tools/sym_info.py, matching
compiler MSVC 16.00.10224.00. Everything here comes from reading the disassembly; confidence labels:
**H** read instruction by instruction, **M** consistent structural evidence, **L** guess.
Units: positions in **centimetres**, time in **60 Hz ticks** (float constant 60.0 at pool+0x15C, 100.0 at +0x20).
Hashes are zlib crc32 (GP0). Names resolved by this package (crc32 verified): Rush 550171d1, Jog b3ff5297,
Receiver c4ceeec0, LetIn 8f903dfb, LetOut 02315629, Net caa7531f, Out 81a72b79, Idle 7c161a2b, TrickShot 731f583e,
ReachAnimation 555999b1, RushingAnimation 39afbba7, RushingToBall 7d322733, SmashAnimation 3ca36f61,
SpectacularAnimation 2e23f28a, ReflexVolleyAnimation 3559c382, PowerfulShotAnimation 9aca4d10, Fatality c78c8f06,
Dive 3689ab7e, FH 9ffd33de, BH fb91f6da, Left da554856, Good ccb6e1ac, Medium c1df4081, Bad ba667f1b.

## 0. Corrections to earlier notes (important)

1. **fn_88697118 and fn_88696D40 are NOT reach/interception tables.** They are the per-player *animation-tag edge
   detector* of the shot-reward evaluator (GP1's "evaluator" object, `this` of fn_88697890): they watch boolean
   "tag cells" per player and, on a rising edge, push reward hashes (SpectacularAnimation, ReflexVolleyAnimation,
   SmashAnimation, RushingAnimation, RushingToBall, PowerfulShotAnimation, Fatality, ...) and set the flags that
   fn_88673C50 later reads (+0x30D, +0x374, +0x375, +0x37E, +0x37F). Details in section 4.
2. **The real reach / interception data** is the pair of `CandidateSet` blocks at `player_state+0xA40` and `+0xAA0`
   (0x60 bytes each; GP2 types `Gp2CandidateSet`, `reach_speed[]` = "RequiredSpeed" per ball sample) plus the ball
   prediction (section 2). Movement chooses *one sample index* `player_state+0xBC8` (and side `+0xBD1`) and everything
   else (Rush / Jog, required speed, validity) is a function of that sample (section 5).
3. **fn_886B5128 is not "AI / swing selection".** It is the per-frame **command applier + ball-launch/prediction driver**
   of the instance: it takes the swing command each player produced (0xE0-byte record), applies it to the ball state
   (launch), runs the ball prediction, and publishes player-relative positions. Swing selection runs earlier, in the
   PlayerController update (section 5).
4. **fn_886B8468 is a single function (one prologue, 39 return points), a 23-state transition function** of the player
   movement planner, not an aggregation of several functions. The jump table has 23 entries (section 5.3).
5. The "Havok reflection" band 0x889C0000+ in docs/gameplay-map.md is wrong for 0x889C0F70-0x889C2900: that is the
   **analytic ball stepper** (fn_889C2818 and 4 callees, section 3).

## 1. fn_886B5128 (0xF08 B): the main gameplay frame (called once per instance per frame from fn_886C1ED8)

`this` = GamePlayInstance (see gp0.md). Fields used: `+0x04/+0x08` player vector, `+0x10/+0x14` vector of *groups*
(group `+0x10/+0x14` = its players; in doubles the active group alternates), `+0x1C` input-mapper service
(`+0xD0` = vector of 0x34-byte per-player input records, `+0x30` = "consumed" byte), `+0x28`/`+0x30` match state,
`+0x44` flag block, `+0x5C` world `{+0x20 = ball state (0x540 B), +0x24 = ball prediction}`, `+0x68` helper,
`+0x78` rules `{+0x00 mode: 2 = doubles}`.
Per player: `+0x10` human/active byte, `+0x14` index, `+0x30/+0x34` current/previous swing id, `+0x40` byte
"input present", `+0x48` instance, `+0x4C` team (`+0x24` team info, `+0x28` team index, `+0x2C` mode, `+0x30` last
hitter index written here), `+0x74` PlayerState (0x1070 B), `+0x78` anim, `+0x94` component set.

Match frame state (`inst+0x30`): `+0x310` frame, `+0x318` state hash, `+0x32A` byte, `+0x334` float counter
(+= 1.0 per applied command), `+0x70` command table (relative array of 0xE0-byte records), `+0x7C` active group.

Steps (H unless noted), in order:

* **A. Ball-in-play pre-step.** Condition: `limit = ball.frame_limit(+0xD8)` is a real frame
  (`0 <= limit != 0x7FFFFFFF`) **and** `match.frame == limit` **and** `ball.mode(+0x2C)` is LetIn (8f903dfb) or LetOut
  (02315629). Then: `fn_8866EBC0` (clear the sample history: world prediction `+0x5A0` vector end=begin, `+0x4C=0`,
  `+0x50=0x7FFFFFFF`, and the two per-player sample vectors), call vtable slot 0x34/4 of every player's "Receiver"
  component (hash c4ceeec0, searched in player+0x94), `fn_886AD278(prediction, inst, &ball, 1, 1)` (ball prediction,
  section 2), `fn_8867B2D8(inst, 0)` (ball event schedule), `fn_8866F090`, `fn_8869F068` (per-player fn_88692468),
  `fn_8869EFC8`, slot 0x30/4 of the Receiver components, and for a doubles group with a non-human player 0 the
  extra `fn_886A4AE0`. (M for the purpose of the sub-calls.)
* **B. Per-player command loop** over `inst->groups[match+0x7C]->players`. Command record
  `rec = (char*)cmdtable + cmdtable->rel + player->index * 0xE0`, command `C = rec + 0x20` (type `Gp3SwingCommand`),
  `rec+0xC4` (= C+0xA4) is "command valid".
  1. doubles guard: if the group mode is 2 and `rec+0x14` and flag-block `+0xCC == 0` and the rule lookup
     (hash 96fe1e55) finds nothing and match `+0x32A == 0`, mark the partner `state+0xFBA = 1`.
  2. if `rec` valid:
     * if `player+0x40` (input present): copy `C+0x99/0x98/0x90/0x94/0x9A/0x9B/0x88` to
       `state+0x5D9/0x5DA/0x764/0x7A8/0x405/0x404/0x3D0` (stick/analyser values).
     * `fn_88675840(inst->u68, player)`.
     * **if `match.frame >= C.due_frame` the command is applied this frame**:
       `match+0x334 += 1.0`; mark the input record `[player.index].+0x30 = 1` (bounds-checked);
       team `+0x1A0/+0x1A1/+0x1A2 = 0`; `player+0x34 = player+0x30; player+0x30 = C.mode_80`;
       `team->+0x30 = player.index` (last hitter); state flag `+0xFB9 = 1` (or, when the match state is
       0x029EAAF4: `anim+0x14E = 1`, `state+0xF9F = 1` and the doubles partner flag);
       **launch the ball**: `ball.enabled(+0x530) = 1`, `ball.new_shot(+0x43C) = 1`, copy the command into the
       ball state (field map in `Gp3SwingCommand` / `Gp3BallState`: C+0x00/0x10 -> ball +0x340/+0x350 and +0x100/+0x110,
       C+0x20 -> +0x120, C+0x70 -> +0x70, C+0x40/0x44 -> +0x00/+0x04, C+0x48 -> +0x360 (shot template index),
       C+0x4C -> +0x430, C+0x50 -> +0x364, C+0x54 -> +0x370, C+0x58 -> +0x368, C+0x30/34/38/3C -> +0x494/498/49C/4A0,
       C+0x88 -> +0x440, ball.launch_frame(+0x20) = match.frame, ball+0x2C = C.mode_80, ball+0x434 = player+0x30);
       **incoming-shot descriptor for the opposing side** (`opp = opposite group`, `info = opp->+0x24`, H): `info+0x00 = match.frame`,
       `info+0x48 = player.index`, `info+0x60 = C.shot_type_hash`, one-hot floats `info+0x4C` (Flat f578057a), `+0x50` (TopSpin d9fa1b37),
       `+0x54` (Slice fc6f57a1 or DropShot 990377a5), `+0x58` (Lob c718daaa), `+0x5C = 0`, byte `+0x3C = (state+0x7C8 > 0.5)`, bytes
       `+0x3D/+0x3E/+0x3F` = membership of the hitter's current animation-class hash (`state+0x70C`) in fixed hash sets
       (e.g. 4708429a dba7dd53 8c2d5a8e de481349 ef50cf09 5f04e79c 3b293e51 2a12fbe4 / 8dc6b132 f74ecf4f 3bbfdfcc b0043514 / 992258dc 65dc9a5a
       4b121fa5 11a1b9d0; names unresolved) and a power test `state+0xE00 > cfg(+0x6C)+0xC74` (M).
  3. after the loop: normalised-position cache for the planner: for every player Q (own team vs other team,
     doubles variants) `Q.state+0xE10 / 0xE20 / 0xE30 / 0xE40 / 0xE50` = Q's and the others' `state+0x8E0` position with
     **x and z negated when the team side tag == a2eda1e7** (so both sides plan in the same orientation) and the ball
     position `world+0x50` (`fn_8865EC70` is the same mirror for one player).
  4. `flag_block+0x19F = 0, +0x19A = 1, +0x220 = team index, +0x224 = player+0x18`, `fn_886A5500(player)` (shot history
     record), `inst+0x35 = 1` (a shot was applied).

Only commands whose `due_frame <= match.frame` change the ball: the command queue is filled by the swing planner /
analyser (GP2 and the PlayerController, section 5).

## 2. Ball prediction: fn_886AD278 (0x4D0)  [H]

`fn_886AD278(BallPrediction *pred, Instance *inst, const BallState *ball, bool keep_mode, bool full)`:
* `memcpy(local, ball, 0x540)`; unless `keep_mode`: LetIn -> mode 0x9EA301C2 and LetOut -> 0x5D25ED1D (clear flags
  `+0xA1..0xA3`) so the simulated serve is a "live" ball. `fn_88272BC0(pred+0x60, ...)` clears the scratch block.
* **Simulates the real stepper**: loop `fn_889C2818(stepper = pred+0x5DC, &local)` once per tick, for at most **600 ticks
  (10 s)**, until the local ball has bounced twice (`local.bounce_count >= 2`, `+0x84` of the copy) or the mode becomes
  Net (caa7531f) / Out (81a72b79). After every tick it stores one `Gp2BallSample` (0x30 B) at `pred+0x5A0` (begin) /
  `+0x5A4` (end): `pos[4] = local.pos(+0xB0 of copy = ball+0x40)`, vec at `+0x10 = local +0x560`, float at `+0x20 = local+0x100`,
  `tick(+0x24) = local.tick + base`, `bounce(+0x28)` = 0 before the first bounce, 1 after, 2 after the second
  (tracked with a 4-state machine at `pred+0x1E4 + 12*seg` = `{first, last, 0.0}` and `pred+0x5B4 + 12*seg` float).
* Summary fields: `pred+0x40/+0x44 = sqrt(|v|^2)*pool[0x2A4]` for two velocity vectors (m/s scale, pool value 0.6 per
  GP2 = cm/tick -> m/s), `pred+0x50/0x54/0x58/0x5C` = first/last tick indices of the segments (first bounce, hit window,
  ...), `pred+0x5E0/0x5F0/0x600` = three snapshot vectors. If the ball is not flying (`ball.vel_y * ... >= 0` test at
  0x886AD3EC) a short path `fn_886AD1F0/886AB1A8/886AB0E8` fills the same summary without sampling.
* `fn_886AB250` (when `full`) fills `pred+0x7C[i*8]` = **ball difficulty** per sample (GP2 reads it).
So the "prediction" is **the game's own ball integrator run forward on a copy**, giving up to 600 samples of
`{pos, vel, tick, bounce}`; there is no separate analytic formula.

`fn_8867B2D8(inst, init)` (H): fills the ball event table `ball.event_frame[8][2]` (+0xB0..+0xEF) with
`0x7FFFFFFF`, then from the prediction: `+0xD8 = samples[0].tick`, `+0xE0 = samples[first_sample(+0x5BC)].tick`,
`+0xE8 = samples[last].tick`; per ball mode: LetIn/LetOut `+0xB0 = pred+0x54`; Out -> `+0xE0 = pred+0x58, +0xE8 = pred+0x5C`;
Net (caa7531f) / ca68aaec -> `+0xB8 = pred+0x50`; Wood (9cafb633) -> `+0xB0 = +0xE0 = frame+15, +0xE8 = frame+25`.
`+0xD8` is the frame the main step (section 1A) waits for.

## 3. Ball stepper: fn_889C2818 (0x94) and callees  [H for structure, M for physics]

`fn_889C2818(stepper, ball)`: `if (!ball.enabled(+0x530)) return; fn_889C1160 (to local frame); if (ball.new_shot(+0x43C))
{ fn_889C19F0 (launch); ball.new_shot = 0; run fn_889C1F70 only when ball+0x4E0 == 0 }; fn_889C0FE8 (back to world frame)`.
* `fn_889C1160 / fn_889C0FE8` (0x174 each): toggle `stepper+0x40` and convert the ball vectors (`+0x40,+0x60,+0x100,+0x110,
  +0x130,+0x140`) to/from a **scaled local frame**: `v = (v - ball.origin(+0x70)) * lbl_88D46390` and back with `lbl_88D463A0`
  (+ origin). The two scale vec4 are runtime-initialised (zero in the file image).
* `fn_889C19F0` (launch, 0x108): `fn_889C0F70(ball+0x340)`, zero `+0x14/+0x18/+0x1C`, `ball.shot_template(+0x24) =
  stepper.table(+0x3C) + ball.shot_template_index(+0x360) + 0x18`, `ball+0x08 = template+0x54`, `fn_889C0C70`, `+0x0C = +0x430`,
  `+0x10 = +0x364`, `fn_889C1868`, `fn_888AAEA8/888AAE00`, copy `+0x100 -> +0x40/+0x60`, `fn_888AB220/888AB0E0` -> `+0x500/+0x510`,
  `ball+0xC8 = ball+0x20 + (int)(stepper+0x1C * ball+0x00)` (launch frame + template duration), `fn_889C0EF8`.
* `fn_889C1F70` (0x704) is the per-tick motion/bounce code: hold phase (`ball.hold_ticks(+0x28) > 0`: position += `+0xA0`, no physics),
  free flight through trajectory generators `fn_888AB558` / `fn_888AD1C8` (objects at `stepper+0x34/+0x38`), bounce when the
  height `pos.y(+0x44)` crosses the floor (pool 0x784 threshold): bounce counter `+0x14++`, damping of `+0x130/+0x140`
  by `ball+0x10C` and `+0x110` factors, spin-like `+0x90..+0x98` scaled by the bounce factor (fn_889C0DC0 = bounce event),
  and finally `ball.velocity_per_tick(+0x4F0) = (pos - pos_prev) * stepper+0x1C`. **The shot is therefore parametrised by a
  template table (`stepper+0x3C`, indexed by the command's template index) and the 8 floats of the command; the bounce
  and flight maths are inside fn_889C1F70 + fn_888AB558/fn_888AD1C8** - these are the next targets for a ball-physics package
  (not read line by line here).

## 4. Tag tracker: fn_88697118 (0x634) / fn_88696D40 (0x2EC) / fn_886965E0 (0xC0)  [H]

Object = GP1's evaluator (`this+0x38` = the shot collector (reward vector +0x08, lookup queues +0x14/+0x20), `fn_88673630` = push). Layout in `gp3_types.h:Gp3TagTracker`:
`+0x3C + 0x10*k + 4*player` = pointer to a **tag cell** (word; byte 0 == 1 while the tag is active), k = 0..33;
`+0x25C + 4*k + player` = previous-frame byte of cell k; `+0x2A4 + 4*player` = int slot ("-1 = unset").
* `fn_886965E0(q, tag_hash, player)`: push `(hash, player)` to the two vectors `+0x14` / `+0x20` of the collector `tracker+0x38` (lookup requests consumed by the
  animation tag service; **not matched**, see section 8).
* `fn_88696D40(this, player_slot)` (once per player): for the 11 tag slots k = 20..26, 30, 31, 33 and (+0x53 group) it requests
  the cell lookup `fn_886965E0(hash, player)` and writes `-1` into the cell word when the cell word is still 0:
  hashes af62f9b9, ca370ec4, 6cb36fd3, 221e130f, aea55abe, 05d0b6d2, 3689ab7e ("Dive"; also pushes reward Dive through fn_88673630),
  319dc754, d5973f7e, aa7aebc4 (names unresolved). Last step: if cell k=17 != -1 and `slot_a4[player] == -1` and the player's
  record float `(match.cmdtable+0x104..).+0x10 < cfg+0x15C (60.0)` request ef823202.
* `fn_88697118(this, player)` edge detection (current = cell byte == 1, previous = `+0x25C` copy):
  k0 rising -> reward SpectacularAnimation + `+0x30D=1`; k1 rising -> `+0x374=1` (reach anim); k4 rising -> ReflexVolleyAnimation;
  k5 rising -> SmashAnimation; k3 rising -> `+0x375=1` + PowerfulShotAnimation; k16 rising -> `+0x37E=1` + Fatality (c78c8f06);
  k6 rising -> `+0x37F=1` (reward TrickShot via GP1 fn_88673C50); k2 falling edge -> request f5d95222; k13/k14/k15 falling edges
  (only when `ShotRecord+0x99 == 0`) -> requests 1ad280af / 83dbd115 / f4dce183; **k2 active (the Rush animation tag) and the
  previous flag clear or the hitter's `+0x78->+0x60` set:** compute `d = |ball_pos - player_pos|`
  (`fn_8865EC70` + the state vector at `+0xBF0`) and `ratio = state[+0xC28]*60 / (state[+0xC24]*100)` (guard: state+0xC24 != 0).
  If `d > cfg(+0x28)->+0xC4` **and** `ratio > cfg->+0xC8` and the match is not paused (`flag_block+0x1C/+0x1D`) and k2 was not
  previously active: reward **RushingToBall** (7d322733) (and request 5312a160 or 7d322733 depending on the record float vs 60);
  otherwise reward **RushingAnimation** (39afbba7). Finally copies the current bytes of k0..6,10..16 to the previous array.
  So "RushingToBall" is a *rating bonus for a long, fast run toward the ball*, computed from distance and the ratio of two
  per-player floats (+0xC24 looks like a time-to-ball, +0xC28 a distance; M).

## 5. Player movement: PlayerController -> MovementPlanner

### 5.1 Call chain (H)
`fn_886BF360` (PlayerController Update, vtable 0x880F4478 slot 2): sets `+0x59F` once (when a Receiver-like state flag
`state+0x6F1 == 0` and cmd record `+0xD0` is set -> also `instance_flags+0xD2`), runs `fn_8867DEF0/fn_8867DF68(player->0x58)` and,
for non-active slots, `fn_8869D720`; calls `fn_886BF260`, `fn_886782D0`; then if the player is active, not human-input-locked
(`+0x58D`), has a Receiver component (c4ceeec0) whose `+0x84->+0x14 == 0`, and the team's last-hit index (`+0x3BC`) is negative
sets `state+0xFBA = 1`; finally sets `cmd_record(+0xD0) = (state.swing_id(+0xBC8) != -1 && !state+0x5D9 && a component with hash 4706f500 exists)`.
`fn_886BF260(ctrl)` (H): `if (ctrl+0x28 [planning enabled])`: `r = fn_886A8170(ctrl)` (may a new plan start?), `b = fn_8866BAE0(ctrl, r)`;
if neither: loop up to **8** iterations `n = fn_886B3CF8(ctrl+0x2C.obj, cur); if n == cur break; fn_88678468; cur = n; fn_886A84C0`
(a chain of plan nodes in the history ring at `ctrl+0x2C`, index `+0x0C`); otherwise `fn_886B3AE8(ctrl)` and clear `+0x28`.
Then, if `match+0x7C == team->+0x28` (it is this team's turn in the active group) call `fn_886BD690(ctrl->planner(+0x24))`.
`fn_886BD690(planner)` (H): sets the two candidate-set dirty bytes (`sets+0x20, sets+0x80 = 1`), sets `state+0x47E` (a "reaction
allowed" bool = `(cmd_record(+0)...` of `state+0x40 > 0` and `state+0x60 == 1` etc.), if `state+0xBC8 == -1 && planner+0x10 != 0xF`
runs `fn_886A39A8` (rebuild both candidate sets via GP2: `fn_8868B4E8` x2, `fn_8868BD80`, `fn_8869B0A8`, clear dirty), then iterates the
state machine **up to 8 times**: `next = fn_886B8468(planner->chain(+0x14).obj, cur)`; if `next != cur`: `fn_8865DAC0(cur)`
(leave) + `fn_88699300(next)` (enter), `cur = next`; stop when stable. Afterwards: if a sample is chosen (`state+0xBC8 != -1`)
`state+0x764 = reach_speed[idx]`, `fn_88688D90` (-> `state+0x350` flag); else (no sample) derive from the ball: reach flag
`state+0xA34 = (|y distance| ...)`. Also stamps `state+0x3A0/0x3A4 = Good (ccb6e1ac)` when `planner+0x280 != -1` and
`cfg+0x440 + planner+0x280 == match.frame`, and `state+0x5DC |= state+0x47E`.

### 5.2 Data: the movement config block (`player->+0x2C`, big data-driven struct; offsets seen)
`+0x17C` 2-D table (ball speed x |angle|) = preparation frames, `+0x1AC` float (anim lead frames added in validity),
`+0x1B0`, `+0x1DC` float **reaction delay in frames** (state 0), `+0x1F8` base profile, `+0x208/+0x218/+0x228` selectable
swing profiles (+0x230 float temporary override), `+0x238/+0x248` special profiles, `+0x270` **Rush** mode entry,
`+0x284` **JogPrepared**, `+0x298` **JogJogPrepared**, `+0x2AC` (vec/float), `+0x2B8`, `+0x2F4`, `+0x630` float guard.
Mode entries (`Gp3MoveModeCfg`): `+0x10` = **minimum distance** (cm); the rest is a curve table used by fn_8826D278.
fn_8826D278(table, x, y) is a 2-D piecewise-linear lookup: rows (stride 0x10, key float at +0xC) are bracketed by `x`, each row is a 1-D curve
evaluated at `y` (`fn_881899D8`), result lerped between the two rows. All numbers live in the XData/CoreTech config, none in code.

### 5.3 The 23-state machine fn_886B8468(planner, cur_state) -> next_state  [H for control flow, M/L for names]
Preamble (always): `player = planner+0x154`; `fn_8866D930(player)` -> `flagA` (used as `r23`);
**re-target check** when `planner+0x125 != 0`: compare ball sample `[state+0xBC8]` against the player position; if
`|contact - player|^2 < 62500` (pool+0x818 = 250 cm radius) and the movement animation hash (`anim+0x468`) is neither Idle
(7c161a2b) nor 230a53b8, and the sign tests with angle thresholds (pool 0x81C 0.96 rad, 0x820 double 1.82 / 0x828 2.36 rad)
pass, jump to state **7 or 8** (7 + !(dot > 0)) and clear the step flags `state+0xFB0/0xFB1/0xFAA/0xFAB/0xFB4/0xFB5`; likewise if
`fn_886C7D58(player+0x60)` returns f4d02677 or 912fa212 -> state 8. Then dispatch by `cur_state` (jump table at 0x886B88BC).

State / next-state edges read from the `li r21,N` assignments (H for the edge, L for the names):

| state | role (M/L) | key calls | next states |
|---|---|---|---|
| 0 | idle after a hit: wait `cfg+0x1DC` ticks since the team's last hit (`team+0x24->+0x68`), singles; doubles go straight on | - | 1 (or stay) |
| 1 | ready / track the ball: uses profile `cfg+0x228` via `fn_8869AEF8`, AI cfg hook `fn_886B81E0`, selector `fn_886A9E48(.,1)`, `fn_88678548`, `fn_886877A8`, `fn_8869A4D0`, `fn_886A58F0` | | 2, 0xD, 0xE, 0x11, 0x12 (saves `+0x130/0x134 -> +0x288/0x28C` when entering 0xD) |
| 2 | same with selector arg 2 | | 0xD, 0x12 |
| 3 | prepare (needs `fn_88687AC0(cfg+0x2AC)`) | | 4 |
| 4 | `fn_886A9678`: 1 -> hold (9, return state 4), -1 -> 0xD | | 9, 0xD |
| 5 / 6 | `fn_886A3440` then `fn_88687AC0(cfg+0x2B8)` | | 3, 6, 9 (ret 6), 0x13 |
| 7 / 8 | adjust steps (ball within 250 cm), anim-time based, `fn_8867A908`, `fn_8826AC10`, `fn_8826D3A0` | | 0xE |
| 9 | **hold / re-plan**: remember the origin state (`planner+0x12C`) and sample (`+0x138`); returns to it once the re-committed sample moved by more than 10 samples | `fn_886A2E48(profile planner+0x24)` | saved state, 3, 0x14 |
| 10 / 11 | | `fn_8866BDD8`, `fn_88687AC0` | 12 |
| 12 | | `fn_886A2BE8`, `fn_886A9678` | 9 |
| 13 | terminal / waiting for contact | | - |
| 14 | | `fn_886877A8`, `fn_886A58F0`, `fn_88564BF8` | 9, 0x11 |
| 15 | **candidate pick**: `fn_8865DBA8` (GP2 arg-max, variant `state+0xBD0` exclude/only Volley), commit `state+0xBC8/0xBD1`, then `fn_88699FC0` classifies; humans: only after more than 3 ticks | | 0x10, 0x11 |
| 16 | volley candidate | `fn_886A9678`, `fn_886A2E48(cfg+0x208)`, `fn_886787D8` | 9 (ret 0x10) |
| 17 / 18 | contact geometry (`fn_8866E318/fn_8866E058`, uses ball sample window) | | 0xD |
| 19 | contact reached (> 10 samples) | | 9 (ret 0x13) |
| **20 Rush / 21 JogPrepared / 22 JogJogPrepared** | movement while the ball is still far; `fn_886A3440`, `fn_886A26E0`, `fn_8866C150`, `fn_88678708(cfg+0x2F4)`, `fn_8866BFE8`, `fn_886A9A48`, `fn_886884E8` | | 3, 6, 0xD, 0x16 (JogPrepared stays/escalates to JogJogPrepared when the ball is far and the speed test passes) |

Return value semantics: a returned state equal to the input means "stay"; the caller loops until stable (max 8 hops per frame).

### 5.4 Selector fn_886A9E48(planner, arg) (0x438) and mode classifier fn_88699FC0 (0x510)  [H]
* `fn_88699FC0(planner)` returns the **movement mode state** (default 5): if the current profile pointer `planner+0x24` is `cfg+0x248` or
  `cfg+0x238` -> 0xB, `cfg+0x1F8` -> 3; else look at the chosen sample: type hash `types[idx] == Volley` -> 0x10; otherwise (ball prediction vector at
  `world->0x5A0`, `reach_speed[idx]`) test the three movement modes **in order Rush (+0x270) -> JogPrepared (+0x284) -> JogJogPrepared (+0x298)** with
  `fn_88688948`; the first that validates gives state 0x14 / 0x15 / 0x16 and sets `planner+0x121 = planner+0x122 = 0`. Preconditions: Rush is only tried
  when the player's world record `(player+0x6C)->+0x158` float is above `cfg+0x630`. When the state stays 5 a side-angle test
  `|atan2(dx,dz) - pool 0x700 (2.078 rad)| ` may force state 6. A debug line prints `RequiredSpeed: %.2f Distance: %.2f` with
  `reach_speed[idx]` and `|contact - player|`.
* `fn_88688948(planner, mode_cfg)` **validates a movement mode** (strings `[Rush] ...`, `[JogPrepared] ...`, `[JogJogPrepared] ...`):
  1. `d2 = |sample[idx].pos - player.pos(state+0x8E0)|^2` (3-D, cm^2). If `mode_cfg.min_distance^2 >= d2`: INVALID ("Minimum distance %.2f < %.2f").
  2. `lead = fn_886CD3C8(player.anim) + cfg+0x1AC` (animation-clip time still to run + constant lead, frames).
  3. `validity = fn_886887C0(planner, mode_cfg, lead)`:
     `prep = Table2D(cfg+0x17C)(row = world+0x68 float, col = |atan2(contact - player - world.vec(+0x50)).xz|)`;
     `slack = (sample[idx].tick - match.frame) - prep - lead`; `validity = Table2D(mode_cfg)(row = |contact - player|, col = slack)`.
  4. valid iff `validity >= 0.5` (pool lbl_8814B910). Prints "Distance %.2f Frame %.2f Validity %.2f Ok".
  Meaning: *a mode is usable if the distance is above the mode's minimum and the learned margin table says that, with this much slack in ticks, the
  player can still cover this distance in that mode.* The three tables are data.
* `fn_886A9E48(planner, arg)` is the profile selector used by states 1/2: bails out when `planner+0x118` flags (`+0x30/+0x64`) say a transition is locked;
  `fn_886A3610` gate; it compares `cfg+0x24..0x58` pairs of `planner+0x118` (a time window `f10 - f11 < 0`) with pool 0x29C (0.25) and **reaction/
  anticipation gates** (`state+0xBB0`, `+0x9D0..0x9EC`, `+0x9D4 > 0.25`, `|diff| > 2.094 rad` (pool 0x554, 120 degrees)); results: 0xD (hold),
  0xB (`fn_886A9DF0`), 3 (`fn_886A3440` true), 0xE, 0xF; it tries profiles `cfg+0x218` (when `state+0xBD5`), `cfg+0x208`, `cfg+0x228` through
  `fn_886A2E48`, with the checks `fn_886A33C0/32B8/3238/31B8` and, if still undecided, `fn_88699FC0`.
* `fn_886A2E48(planner, profile)` (0x370) **commits a swing profile to a ball sample**: builds the candidate list for `profile`
  (`fn_8869AB70`, `fn_8868AF88`, `fn_88689AF0`), asks GP2's arg-max `fn_8865DBA8` for the best sample/side, keeps the current one if it is still inside
  a valid window of the profile (rows of 0x30 B with `[+0x24, +0x28]` = sample range), otherwise writes `state+0xBC8 = idx`, `state+0xBD1 = side`,
  `planner+0x24 = profile`; side effects at commit (once, `planner+0x29C`): `state+0xF3C = horizontal distance(player, contact)`,
  `state+0xF30 = random float (fn_8861E598, engine RNG)`, `state+0xF34 = world+0x68` (ball value), `state+0xF38 = frames since the team's last hit`,
  and the timing grade hashes `state+0x3A0/0x3A4` = Good/Bad/Medium (ccb6e1ac / ba667f1b / c1df4081) chosen by `state+0xF68` against `0.5`
  (lbl_8814B910) and pool 0x414 (10000) / 0x56C thresholds. These grade hashes are the "timing quality" the UI shows.

### 5.5 When does a player start reacting to the ball?
* The planner does nothing (state 0) until `match.frame - team.last_hit_frame >= cfg(+0x1DC)` ticks, i.e. a **data-driven reaction time after
  the opponent's hit** (`team+0x24->+0x68` is the frame stamp of the last hit, written by the swing apply step in section 1B).
* From then the prediction samples are scored (GP2) and a sample is committed (`state+0xBC8`); Rush / JogPrepared / JogJogPrepared are three **speed
  regimes** of the run toward that sample, validated by the minimum-distance and margin-table test of 5.4. "Required speed" shown in the debug text is
  `reach_speed[idx]` (m/s, GP2) - the planner itself never divides distance by time; the margin tables encode it.
* `state+0x47E` ("reaction allowed") and the candidate-set dirty bytes are refreshed every frame in fn_886BD690.

## 6. Per-frame order inside fn_886C1ED8 for the pieces owned here (adds to gp0.md)
`fn_886B5128` (apply commands, launch ball, predict) -> `fn_886C1E80` -> ... -> `fn_889C2818` is called by the instance step at the end of
fn_886C1ED8 for the real ball (and by fn_886AD278 for predictions) -> per-player `fn_88697118`, `fn_88696D40` -> frame counters.
The PlayerController update (movement planner, section 5) runs from the module list as a separate node and fills the candidate sets
that fn_886B5128's neighbours read next frame.

## 7. What is data, what is code
Code constants (pool `g_ts4_script_constants` 0x880D0F70): 1.0 (+0x00), 100.0 (+0x20), 1000 (+0x3C), pi/2 (+0xE8), 0.2 (+0x10C), 20 (+0x130),
60.0 (+0x15C), 15 (+0x1D4), 0.25 (+0x29C), 0.1 (+0x2AC), 500 (+0x424), 10000 (+0x434), 300 (+0x468), 2.094 (+0x554), 35 (+0x578),
2.078/2.62 (+0x700), pi/4 (+0x708), 62500 (+0x818), 0.96 (+0x81C), 1.82/0.785 (+0x820), 2.36 (+0x828). lbl_8814B440 = 0.0, lbl_8814B910 = 0.5.
Data: shot templates (`stepper+0x3C`), the movement config block (`player+0x2C`: reaction delay, profiles, Rush/Jog tables, preparation table), ball scale
vectors lbl_88D46390/lbl_88D463A0 (runtime), reward thresholds (`cfg+0xC4/0xC8`).

## 8. Matching status
No byte-exact matches were obtained. Near misses (semantically verified, drafts in `src/xbox360/drafts/gp3_small_near_misses.c`):
fn_886965E0 (0x88 differs only in frame size: original frame 0x70 and params addressed in the home area, `r30` keeps the second argument),
fn_8865F030 (register allocation of the shared zero/result variable), fn_8866E250 (register allocation, extra `r31` for the flag byte),
fn_886A39A8 (original does not CSE the `planner+0x2C` load across the branch).

## 9. Open items
* fn_889C1F70 + fn_888AB558/fn_888AD1C8 + shot template table = the ball flight/bounce/spin model (highest value next step).
* names of the tag hashes af62f9b9 ... aa7aebc4 and of the 34 tag cells; where the animation tag service writes the cells.
* the 23 state names (only 20/21/22 are named by game strings); fn_886A9678, fn_886877A8, fn_8869A4D0, fn_886A58F0, fn_886A26E0, fn_886A33C0 predicates.
* byte layout of the first 0xA8 bytes of the command record beyond the fields listed (flags 0x3C-0x3F classify the stroke type).
