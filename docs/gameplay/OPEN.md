# Gameplay open items (agent GE1)

Every item that a gameplay note marks open, unknown, inferred, M/L/U confidence, or an unnamed
hash, grouped by subsystem. For each one: what would settle it, and the status. Status is one
of **closed** (answer read from code or data, with the note that holds it), **partly** (the
gameplay-relevant part is closed, a detail remains), or **open**. Items are ordered by how much
a player would feel them.

The notes that raised them are cited as `note sN`. "Settle" says what evidence would close the
item. Names that are only missing a crc32 preimage are grouped at the end: they do not change
behaviour.

## 1. Shot request, aim and outcome

| # | item | raised in | settle | status |
|---|---|---|---|---|
| 1.1 | Aim tables and the aim point: how the stick becomes the landing target | controls s8, shot-to-template s4, input-to-shot s5 | read the selector's target method and the tables | **closed** ([aiming.md](aiming.md)): selector vtbl slot 4 `fn_886935A0`, AimingConfig quads chosen by QuadEfficiency, stick direction to the quad edge |
| 1.2 | `S+0xD78` (In depth pull-back) value | ball-physics s14.4, s16 | find its writer | **closed** (aiming.md s4): DeepDeviation, output of each aiming graph, 0..310 cm from DeviationSystem.Random |
| 1.3 | `S+0xD8C/0xD90` Out margin | ball-physics s7, s14.4 | name and writers | **closed**: OutEfficiency (fault graph) and QuadEfficiency (= FinalEfficiency, aiming.md) |
| 1.4 | `fn_88693280/fn_88693040/fn_886935A0/fn_8867D150` described, not ported | ball-physics s14.5 | port | **closed**: `ref/gameplay/aim.c` (`fn_88693280` clip itself is still only described) |
| 1.5 | Consumer of the control-graph list `ShotResolutionSettings.00236a48` | controls s12.6 | find who maps a template row to its EvaluateList entry | **closed** (GE1, C): `fn_886629C8` (shot context `SC`, `SC+4 = S`) ends by walking the entry list `SC+0x10..0x14` and storing in `SC+0x100` the entry whose key `+0x10` equals `ShotSpecific.ResolutionConfig` (S+0x6DC: the row's `ResolutionConfig`, or its `Return...` config on a return of serve), else NULL (`0x88662B48/0x88662B54`). `fn_88659AA0` and `fn_88695C48` then run that entry's graphs |
| 1.6 | Inside-out geometry: the two side tests of `fn_886AE528 +0x78..+0x3B4`, stick window direction | controls s12.5, s15.4 | transcribe the side tests | **partly** (GE1, C; controls s15.4 step 2): two lines through the hitter and through the ball are intersected with the ball's travel line (`fn_881896F8`), mirrored by the side tag, and compared in z; inside-out = the sides differ. The stick window is 50 deg around pi/2 (s15.4 step 3). Open (I): the exact line set-up inside `fn_881896F8` and which ball vectors `+0x100/+0x110` are |
| 1.7 | Skill linked to the inside-out bonus (control graphs, SkillList link r67) | controls s12.6, s15.3 | resolve the link port's skill id | **closed** (read from data by G4b, `data/gameplay/traits_skills.yaml`): graph 188 register 67 = `skill[InsideOutMaster]` (crc `2fc17958`), +0.2 on inside-out shots in 23 graphs (aiming efficiency 11, PowerfulFactor 8; traits-and-skills s3 row 10) |
| 1.8 | Groundstroke TimingValue `S+0xD08`: computation and early/late asymmetry | controls s12.9 | read the TimingState analyser graphs (BaselineTimingAbility, VolleyTimingAbility, `39cfdeba`) and the code that feeds them | **closed** ([timing-and-fatigue.md](timing-and-fatigue.md) s1): code `fn_8867DF68` maps frames-to-ball through `SwingTimingSelectionList` curves; perfect = commit 20 frames before arrival; worst/best curves identical in retail so TimingAbility has no effect; the asymmetry is in the fault graphs, not the curve |
| 1.9 | `ShotSpecific` grade (`S+0x6BC`, copy of `ShotDef[i].9b182896`): copy code and grade selector | graphs-decoded s10 | find the copy | **closed** (GE1, C + D): `fn_886629C8` (from `fn_886AE528 +0x430`) fills `ShotSpecific` from `ShotDef[i].ShotResolution`: `PowerResolution` (S+0x6BC) by the **Power** swing key S+0x3B4, `AimingResolution` (S+0x6C4, 16-byte grades, `fn_8826DDF8`) and `ErrorResolution` (S+0x6D4) by the **Control** key S+0x3B8 (`fn_8826DD20`: VeryGood +0, Good +8, Normal +0x10, Bad +0x18, VeryBad +0x20). `ResolutionConfig` (S+0x6DC) = `ShotResolution+0xA4` (the `Return...` config) on a return of serve, else `+0xA0`. `#6fec51bf` S+0x798 / `#8a23b97f` S+0x79C = grade value of Power / Control (`fn_8865AC08`: VeryGood 1, Good 0.75, Normal 0.5, Bad 0.25, VeryBad 0). Both keys are only ever set to Good (gp8, movement-and-animation s6.1), so **retail always uses the Good rows and the factor 0.75** |
| 1.10 | Writers of `#1407106c` (S+0x770), `#be5d458f` (0x768), `#693eedbe` (0x7D8), `#aee2d90b` (0x7D0), `#3c6beee9` (S+0xD84) | graphs-decoded s10 | store scan by offset off `S` | **partly** (GE1; C for the scans, I for the conclusion): `#3c6beee9` is set to 0.0 by `fn_886612E0 +0x98` (with `S+0xDAC = 0`). For the other four, no store at those offsets in the gameplay window (direct `stw/stfs`, offsets built with `li/addi`, and stores through a base of `S+0x66C`), and no analyser graph outputs them (`data/gameplay/graphs.yaml`). The stores to `+0x768..+0x78C` in `fn_88697890` and `fn_886ABD70` shift a history array of another object. So they appear to keep their State.bin images: `#1407106c` 0, `#be5d458f` 0, `#aee2d90b` 0, `#693eedbe` 1000. If so, the fault graphs' fast-ball term and the wood-chance ramp on `#1407106c` are inert in retail (the similarly named `TrajectoryEvaluationContext.#1407106c` S+0x88C is the hit-point scorer's ball speed in km/h, a different field). Settle with a runtime watch |
| 1.11 | `HandAttributeQuality` (S+0x74C) exact rule | graphs-decoded s10 | read the stores in `fn_88699xxx`, `fn_886BA254`, `fn_886BD4F0` | **closed** (GE1, C): the planner's per-state prepare `fn_88699300` and `fn_886B8468 +0x1DEC` set it to `Profile.Return` (S+0x650) when `fn_8865EB60` says this is the return of serve (serve phase `match+0x32A`, the serving team is the other one and this is the receiving slot), else `Profile.Forehand` (S+0x654) for the forehand side and `Profile.Backhand` (S+0x658) for the backhand; the volley states use `Profile.Volley` (S+0x65C); two approach states force Forehand. `fn_886BCE88 +0x668` re-picks Forehand/Backhand from the side byte `S+0xA34` against the player's handedness |
| 1.12 | LetProbability input `#fea37f2e` | brief | find the bound field and its writer | **partly** (C, GE1): it is `BallState.Commands.LetCommands.Inputs.#fea37f2e` (ball+0x490), written once in the planner at `fn_886AE528 +0x9D4` (0x886AEEFC): `LetHeight (S+0x754) = y of fn_889C1340(ball, ShotResolutionSettings+4)`, the ball is stepped one tick (`fn_889C1F70`), then `ball+0x48C = ball.y (+0x44)` and `#fea37f2e = ball.y - LetHeight`. So the let chance (0.02, falling to 0 over 40..60 of this input) applies only when the ball is within about 40-60 cm of the computed let height. Open (I): which point `fn_889C1340` evaluates (tape crossing) and why the step comes first |
| 1.13 | `b50/b51` meaning, gate `G` bytes `match+0x328/0x329`, `DebugConfig+0x784` | gp4b s10, ball-physics s8 | transcribed by G3b; names of the match bytes | partly (formula C, names U) |
| 1.14 | Risk hold value `S+0xE08` reader (TU1 xexp?) | controls s12.7 | scan the TU1 code delta | open |
| 1.15 | Risky rows reachable only by the debug override | controls s6.1 | closed by G2b | closed |
| 1.16 | AimingConfig flag `5ed23100` (+0x94, true on serve configs) | aiming s5 | whole-module reader search | **partly** (GE1, C for the scan, I for the conclusion): the aim path (`fn_88693040`, `fn_886935A0`), the selector init `fn_886707C8` and both callers of `fn_88660F70` (`0x886930B0` aim, `0x886A096C` in the debug quad drawer `fn_886A0850`) never read `+0x94`; the eight `lbz ..., 0x94(...)` sites in the gameplay window use other bases. I: unused in retail |

## 2. Ball flight and bounce

| # | item | raised in | settle | status |
|---|---|---|---|---|
| 2.1 | Curves step or ramp | ball-physics s14.1, analyser-graphs | load-time fixup | **closed** by G1 (ramps; graphs-decoded s2). ball-physics s11 values are STEP readings with RAMP in brackets |
| 2.2 | Serve sub-record `row+0x10` and stroke ranges `row+0x14` readers | ball-physics s14.2, shot-templates s8.1 | reader search | partly: no reader found by G3b (likely unused) |
| 2.3 | Live ball keeps the State.bin image `+0x4C0..0x4E1`; net height | ball-physics s14.3, gp4 s5 | runtime dump (Xenia) | open (needs a runtime) |
| 2.4 | Bounce rotation: the unclamped tilt weight `|5 spin_a|`, `1 - c40` speed factor, yaw kick | ball-physics s14.6, shot-templates s8.5 | runtime bounce dump, or a matched `fn_889C1C80` | open (code read H; physics meaning M) |
| 2.5 | Kind routines `fn_888AC748/ACA68/ACDA8` only characterised | gp4 s5 | transcribe | partly (ported via the golden-vector reference of gp4b) |
| 2.6 | Command `f4C` and spin blend distribution (S+0x778, S+0x774) | shot-templates s8.3 | evaluate the power graphs 198/238-273 | partly: both are graph outputs (ball-physics s16) |
| 2.7 | Net hit-test polarity | gp4 s5 | runtime | open |

## 3. Movement and animation

| # | item | raised in | settle | status |
|---|---|---|---|---|
| 3.1 | How sprint (RB) reaches the locomotion keys | movement-and-animation s5.7 | follow `@Rush` S+0x4DD (`fn_8865E430`), `@ReqFastRepos` S+0x4E2 (`fn_8868C218`, `fn_8869B928`) into the planner and AnimationSelection | **partly** (C, GE1): `fn_8865E430` (called each frame by `fn_886BB0A8 +0x438` while the point is live) sets `RePositioningState.#1cd155e8` S+0xA2C = `@Rush && CurrentVigor >= 0.1` and `RequiredAmplitude` S+0xA10 = 1.0. The move-speed query `fn_8866FB60` returns, in move state `0x7652DEC8`, speed = RequiredAmplitude plus that sprint flag; with the flag set its callers `fn_88691C40 +0x124` and `fn_886BEEE8 +0xBC` skip the computed speed `fn_88691B38`, so **sprint = full amplitude 1.0, refused below vigor 0.1**. `@ReqFastRepos` (C): `fn_8868C218` sets the locomotion factor `anim+0x41C = 1.0`, and when RB is held with the player forward of `-RepositioningPointSettings/8154a27b` (x > -500 cm, file 0xA98) it runs graph `this+0x128` and sets `anim+0x41C = S+0x39C` (`Movement.#98bb2ce3`, graph 37 VolleySpeedCoef = 1.15); otherwise it raises `BehaviorTransitionState` flags (S+0xFA0/0xFA1/0xFBD) at most every `/7440a9da` = 5 frames. So RB near the net moves the player about 15 % faster (I: `+0x41C` is the locomotion speed scale). Open: move state `0x7652DEC8`, `S+0xA2D`, and `fn_8869B928`'s use of RB and the 500 cm value |
| 3.2 | About 12 movement predicates and exit conditions of planner states 10-18 (L/I) | gp3 s9, movement-and-ai A.3/D | transcribe `fn_886A9678`, `fn_886877A8`, `fn_8869A4D0`, `fn_886A58F0`, `fn_886A26E0`, `fn_886A33C0`, `fn_88678548`, `fn_886A2BE8`, `fn_8865DBA8`, `fn_88699FC0`, `fn_88688948`, `fn_886887C0` | **partly** (GE1, C; movement-and-ai A.4b, models in `movement.c`): ball window 886877A8, shot window 88678548, AltSwing 886A2BE8, reach request 886A58F0 transcribed; 8865DBA8 / 88699FC0 / 886A26E0 were already V. Open: `fn_886A9678`, `fn_8869A4D0`, `fn_886A33C0`, VMX geometry of `fn_88688948`/`fn_886887C0`, `fn_881896F8` meaning |
| 3.3 | Sector angle rounding, Back look-side rule, blend curve, root-motion mirroring, retarget angle tests | movement-and-animation s5.6 | read the locomotion selector and `fn_886D3AD8` | open (I) |
| 3.4 | Vivacity source of the transition speed | movement-and-animation s5.6 | graph binding of Vivacity (graph 14) to the transition lerp | open |
| 3.5 | Power/Control "VeryGood" swing keys never set by code, yet the 74 Fatality clips ask for VeryGood | movement-and-animation s5.1, s6.1 | does the swing query read `S+0x3B4/0x3B8` at all | **partly** (GE1, C): the keys are read by `fn_886629C8` to pick the ShotSpecific resolution grade and the 0.75 factors S+0x798/0x79C (OPEN 1.9); they stay Good. Whether the clip query filters on them (which would make the Fatality clips unreachable) is still open: read the `qualifier_sources` consumer in the swing selector |
| 3.6 | Who reads the clip Tolerancy arrays | movement-and-animation s5.3 | reader of the record's Tolerancy offsets | **partly** (GE1, C for the scans, I for the conclusion): only the copy `fn_886D3310`, the debug editor `fn_886D7638` and the selector destructor at `0x886D36D8` touch the per-clip arrays (selector +0x40..+0x7C). Two scans over 0x88640000-0x88700000 (functions loading four or more of those offsets from one base; any such load feeding an `lfsx` within 8 instructions) found no reader. I: the Tolerancy values are dead at runtime; the clip fit uses the AnimIface tolerances `+0x3D8/+0x3DC` (gp7) instead |
| 3.7 | TimingState field names `S+0xCF0` (3fe3a099), `S+0xD00` (1490306b) | movement-and-animation s5.5 | crc preimage | partly: meanings known (frames to contact; ball speed km/h), names U; see s9 |
| 3.8 | ReceiverState fields `S+0xC28/0xC2C/0xC38` | brief | names and writers | partly: they are `ReceiverState.c7b7bdac.#8760acf5 / #420a6cfc / #2f6930a4` (hit-point block next to BallDifficulty, ShotDifficulty, Spin; `ps_layout.py`); writers not traced |
| 3.9 | Reach/lunge, wait positions after a shot (second hashed machine, base profile `cfg+0x1F8`) | movement-and-ai A.5 | decode | open |
| 3.10 | `SpectacularVolleys` flag S+0x388 reader | traits-and-skills s5 | closed by G6b: the swing category condition VolleySpectacular | closed |
| 3.11 | PlayerController vtable slot 21 caller (`fn_886B4B80`) | player-and-movement s9.1 | indirect-call trace | open |
| 3.12 | PT+0x31C/0x32C/0x33C/0x37C and PT+0x450..0x5D3 readers | player-and-movement s9.4 | scan with other bases | open |
| 3.13 | Clip-fit cost terms and weights (`fn_886D3AD8`) | stats-swing-clipfit s4 | VMX read | partly (structure V, G4b) |

## 4. AI

| # | item | raised in | settle | status |
|---|---|---|---|---|
| 4.1 | How the AI turns ShotComponents and ServeComponents into inputs | controls s10, movement-and-ai B.2 | read the AI decision functions | **closed** ([ai-inputs.md](ai-inputs.md)): weighted random draws into ShotTriggers, Stick_Aiming, Risk, FollowToNet, power |
| 4.2 | RepositioningComponents / PositioningComponents consumers | analyser-graphs s6.5 | same method as 4.1 | **partly** (GE1, C; ai-inputs s5b): Volley and RushRepositioning are random draws in `fn_886A4260` (RushRepositioning sets `@ReqFastRepos`); StopMoving / `#2b4b4baa` / `#2ac5965a` make the AI stand still in `fn_886A3DF0`; `FinalPositioningComponents.#79b99b60` is the **reaction delay** in frames read by planner state 0. Open: Positioning Volley / BaseLine / InsideOut consumers, `#6e33662f` use in `fn_886BB0A8` |
| 4.3 | Names of AI style groups `824ec12e`, `75c6d60c`, `PositioningComponents.#79b99b60`, expression keys `bfc9cc2c`, `2836a60f` | player-and-movement s9.3, stats-coaches-career s6 | crc preimage | open (name only) |

## 5. Fatigue, skills, stats

| # | item | raised in | settle | status |
|---|---|---|---|---|
| 5.1 | Vigor integration `S+0xF64` | brief | read the fatigue update (`fn_886BC1E0`, `fn_886BBC38`) | **closed** ([timing-and-fatigue.md](timing-and-fatigue.md) s2): per-frame `fn_88690540` (movement + animation load, FatigueIngame), point end `fn_8866EE48` (recovery x rest 1/2/3, capped at VigorMax); meaning of match-info flags `+0xD4/+0xD5/+0xDC` is I |
| 5.2 | Flammable counter `((world+0x50)+0x4C)[team].+0x30` incrementer | player-and-movement s9.5 | find the store | open |
| 5.3 | MatchAnalyser trigger names (`b6b22409`, ...) | traits-and-skills s5 | crc | open (name only; writers known, G4c) |
| 5.4 | Graph 22 for players 1-3; readers of ServePrecision/ServePower | graphs-decoded s10 | code read | open |
| 5.5 | Created player to `PlayerList` row; coach bonuses added when | player-and-movement s9.2 | career Lua | open (outside Swing) |

## 6. Rules, crowd, match flow

| # | item | raised in | settle | status |
|---|---|---|---|---|
| 6.1 | Where crowd excitement and applause level are computed (upstream of `fn_8888DD18`) | brief, gp1 | trace the callers of `fn_8888DD18` | **closed** (GE1, C): `fn_8888DD18` is the sound side's gameplay-event dispatcher (switch on the event hash: `SetExcitement` dcbb46e0 and `31217b4c` share one handler, `Applause` d3f7df83, `bcff8fb4`, `fdbe3ef7`, ...). The events are posted through the queue `fn_88683D78`/`fn_88181240` by the reward model of gp1: `fn_88683FA8` (per shot: `SetExcitement` with value `gauge+0x84 + gauge+0x88 x level`, the integer excitement level `+0xC0`), `fn_88684AE0` (reset), `fn_88686110` -> `fn_88685060` (end of point, `Applause` and `EndOfPoint`). The per-player crowd level 0..1 is `fn_8868EA30` (gp1 s6, values in `data/gameplay/crowd.yaml`); its rally ratio divides by `QualityOfPlay.#0e765502` (S+0x1048), which is the **shot count of the rally** (reset to 0 there) |
| 6.2 | Doubles: rotation arithmetic, serve order, positioning | rules-and-scoring s7, brief | read `0x88674ED0`, `0x88674D58`, the doubles AI | open (aim widening closed in aiming.md) |
| 6.3 | Rally judge `fn_886A84C0` skimmed | rules-and-scoring s7 | transcribe | open |
| 6.4 | Initial server choice | rules-and-scoring s7 | find a toss step | open |
| 6.5 | TU1 `RepositioningSettings/29eac4a0` flag and `fn_886795C8` | title-update-balance s6.2 | read `fn_886795C8` and its TU1 form | **closed** (GE1, C; title-update-balance s3.4): both forms cancel a sideways push further out (direction 60-120 deg either side) when the player is more than 100 cm off centre. The disc applies it on every frame of the 40 frames after a stamp `(ctx+0x84)+0x10`; TU1 with `e26ae391` applies it at the stamp and then only while the push continues (latch `+0x16E`). The gate `QualityOfPlay.#0e765502` (S+0x1048) is the rally shot count (6.1), so the rule needs at least one shot in the rally. I: the stamp is the last hit |

## 7. Data formats and infrastructure

| # | item | raised in | settle | status |
|---|---|---|---|---|
| 7.1 | XBin signature check and archive first-match rule (TU precedence) | title-update-balance s6.1 | read the loader | open |
| 7.2 | 0x8C animation record fields beyond the known ones | df s8.2 | correlate with names | partly (G6 decoded the qualifier masks) |
| 7.3 | InputMapper `+0x18/+0x24` gesture blocks, root floats 0.55/0.8 | controls s12.8 | reader search (PS Move code) | open (no gameplay effect for a pad) |
| 7.4 | Polar stick angle +0.5 offset | controls s12.10 | runtime | open |
| 7.5 | `Expressions.bin` in TU1 does not parse ("unexpected signature") | controls s16 | fix the parser or diff the bytes | open |
| 7.6 | `fn_889B4C10` second Expressions module | graphs-decoded s10 | none on disc | closed (I: dead path) |

## 8. State machines and conditions (behaviour known, names missing)

| hash | where | meaning (C) |
|---|---|---|
| `0xAFAF1093` | `fn_886B3CF8` request state | waiting for a shot press |
| `0x658B2E11` | same | swing running, waiting for the 12-frame trigger or the release |
| `0xF6EB6636` | same | committed on an early release |
| `0xA1903341` | same | planner has run (shot chosen) |
| `0x93E5E96D` | same | auto-swing evaluation (volley/baseline analysers) |
| `693616c3`, `60d5b606`, `de050fd0`, `42864090`, `4041760a` | `fn_88697E98` swing-category conditions | min line speed > 3.5 / > 4.5 m/s, with or without the timing window (controls s17.2) |
| `0x280AE84D` | `fn_88662C08` | out grade beyond OutFar |
| `0x959A9407` | animation slot kind | play slot (EOP) |

## 9. Names only (crc32 preimages not found; behaviour documented)

TimingState `c11ed16a`, `3fe3a099` (frames to contact), `d2797eb6` (depth difference),
`02583288` (press-to-launch frames), `18d5f130`, `1490306b` (ball speed km/h), `0eaa0333`
(auto-swing good); hit-point block `c7b7bdac` members `2c63ee31`, `8760acf5`, `420a6cfc`,
`2f6930a4`, `e00ec629`; `#1407106c`, `#03d2be3d`, `#5cf9de02`, `#07902e50`, `#7bb6a318`,
`#8ea88f9f`, `#6906754b`, `#7afa6edb`; about 290 graph names; the 11 kernel type names; the
unresolved PlayerTuning words `baaa713d` (PT+0x740, file 0x8E4 = 12: the auto-commit lead in frames, controls s4), `32b6d5c1`, `8946f070`. A 1-3 word search over 190
gameplay words (GE1, `crc32`) found none of them; the G5b/G4c searches are wider.

## 10. Progress log

* GE1, 2026-11-14: closed 1.1-1.4 (aiming), 4.1 (AI inputs); partly 1.5, 3.7, 3.8. New tool
  `tools/ts4data/ps_layout.py` prints any reflected type with absolute offsets and names.
* GE1, 2026-11-14: closed 1.8 (TimingValue, read from code + data) and 5.1 (vigor, read from
  code); both in `timing-and-fatigue.md`, with `ref/gameplay/timing.c` and `ref/gameplay/fatigue.c`.
* GE1: 3.1 and 1.12 partly (sprint flag and its vigor gate; the let input = ball height minus LetHeight; read from code); `baaa713d` located (PT+0x740 = 12, auto-commit lead).
* GE1: 3.2 partly (four planner predicates transcribed, `ref/gameplay/movement.c` helpers with tests).
* GE1: 1.6 partly (inside-out side test transcribed), 1.7 closed (already resolved in traits_skills.yaml); 3.1 RB fast reposition read.
* GE1: 1.9 closed (ShotSpecific copy and grade selector; only Good rows are used in retail), 3.5 partly.
* GE1: 6.1 closed (event chain to the sound dispatcher; S+0x1048 = rally shot count); 6.5 closed (TU1 repositioning rule, both forms read); 4.2 partly (AI repositioning draws, stop rule, reaction delay = positioning component); 1.5 closed (SC+0x100 writer); 1.16 partly (no reader); 1.11 closed (HandAttributeQuality rule); 3.6 and 1.10 partly (no readers / writers found by scans; likely dead or constant fields).
