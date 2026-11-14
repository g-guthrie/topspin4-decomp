# Gameplay symbols established by GE1 and GE2

Names, prototypes and layouts that GE1 read from code. Grades: **C** = read from code,
**D** = read from data, **I** = inferred. `S` = PlayerState, `PC` = PlayerController,
`PT` = PlayerTuning (`Settings cfg+0x180`), `SC` = shot context (`PC+0x70`). Field names
come from `Layoutall.bin` through `tools/ts4data/ps_layout.py`. Prototypes are the register
use seen in the code, written as C; argument names are ours. Older symbol tables live in
`movement-symbols.csv`, `rules-symbols.csv` and `swing-symbols.csv`.

## 1. Functions

| function | proposed name | prototype | what it does | grade | note |
|---|---|---|---|---|---|
| `fn_886B0490` | `PlayerController_PlanShot` | `void (PlayerController *pc)` | calls the planner `fn_886AE528` for the shot | C | aiming s1 |
| `fn_886AE528` | `ShotPlanner_Plan` | `void (Planner *, ...)` | builds the shot: aim (+0x444/+0x4A4/+0x4D8), In/Out target, launch | C (partly) | aiming s1, ball-physics s7 |
| `fn_886935A0` | `AimSelector_GetTarget` (vtbl slot 4) | `void (AimSelector *x, Vec4 *out, PlayerController *pc)` | stick direction to the AimingConfig quad edge | C | aiming s3 |
| `fn_88693040` | `AimSelector_BuildQuad` | `void (AimSelector *x, Quad *out, PlayerController *pc, float m)` | interpolates the zone quads by QuadEfficiency `m`, doubles widening | C | aiming s3 |
| `fn_88693280` | `AimSelector_ClipToCourt` (vtbl slot 8) | `void (AimSelector *, Vec4 *from, Vec4 *to)` | clips the hitter-to-target segment to the efficiency-1 quad | C (described) | ball-physics s7 |
| `fn_88660F70` | `AimSelector_ChooseConfig` | `AimingConfig *(AimSelector *, ...)` | picks one of the selector's three configs (template name, FlatReturn on a return, doubles key) | C | aiming s3 |
| `fn_88661188` | `Aim_IsMirrored` | `bool (PlayerController *)` | mirror test: second service court when serving, else hitter at z >= 0 | C | aiming s3 |
| `fn_886706C8` | `Aim_StickToQuadState` | `bool (PlayerController *, QuadAimingState *out)` | picks the stick source, sets DirectionSelected | C | aiming s3 |
| `fn_8867D350` | `Aim_ZoneQuad` | `void (Quad *out, AimingZone *z, float m, float w)` | one zone's quad at efficiency m, doubles widening | C | aiming s3 |
| `fn_8867D150` | `Aim_QuadPoint` | `void (Quad *q, QuadAimingState *a, Vec4 *out)` | stick direction to the quad edge | C | aiming s3 |
| `fn_88695640` | `AimingState_Roll` | `void (PlayerController *)` | rolls `DeviationSystem.Random` S+0xD7C = U[0,1] | C | aiming s4 |
| `fn_88695C48` | `AimingState_Evaluate` | `void (ShotContext *sc)` | runs the aiming graph (`SC+0x100 +0x18`), sets QuadEfficiency = FinalEfficiency | C | aiming s4 |
| `fn_886BE1C8` | `PlayerController_RunFinalEfficiency` | `void (PlayerController *)` | at +0x5A0 runs graph 196 (human) / difficulty `7bcf55ee` (AI) | C | aiming s4 |
| `fn_8869C010` | `Planner_MovementIntent` | `void (Aim *, Vec4 *out, ...)` | stick/neutral/auto movement intent; not the shot target | C | aiming s6 |
| `fn_886B1BA0` | `ShotEditor_Apply` (debug) | `void (...)` | only writer of StickOverride S+0xD70 / S+0xDAE | C | ai-inputs s6 |
| `fn_886825A0` | `AIServe_Decide` | `void (AIController *)` | serve stroke draw, advanced/classic, follow to net, gauge timing, efficiencies | C | ai-inputs s4 |
| `fn_88682350` | `AIServe_Aim` | `void (AIController *)` | draws side/length, writes Stick_Aiming and polar | C | ai-inputs s4 |
| `fn_88682800` | `AIServe_Hit` (state 3) | `void (AIController *)` | serve state 3 | C (role only) | ai-inputs s4 |
| `fn_886B8180` | `AIServe_Update` | `void (AIController *)` | serve state machine 0..3 | C | ai-inputs s4 |
| `fn_886821A0` | `AI_DrawServeStroke` | `void (S *, float slice, float topspin, float flat)` | weighted draw of the serve stroke | C | ai-inputs s3 |
| `fn_88682290`, `fn_8867EB98` | `AI_DrawAxis` | `float (float a, float b, float c)` | weighted draw returning -1 / 0 / +1 | C | ai-inputs s3 |
| `fn_8867EA10` | `AI_DrawRallyStroke` | `int (float s, float t, float f, float l, float d)` | weighted draw over 5 strokes | C | ai-inputs s3 |
| `fn_886B7208` | `AIShot_Decide` | `void (AIController *)` | rally stroke, aim, Risk, follow to net, power | C | ai-inputs s5 |
| `fn_886A4260` | `AIReposition_DecideDoubles` | `void (AIController *)` | doubles: evaluates RepositioningComponents, `U[0, V+B] < V`, `@ReqFastRepos`, mode 3/4/5/6 by partner half | C | repositioning s4 |
| `fn_886A3DF0` | `AIReposition_Execute` | `void (AIController *)` | AI repositioning move toward the mode point, arrived within 175 cm; stop rule (inert in retail) | C | repositioning s3.2 |
| `fn_886BADA0`, `fn_886B81E0` | `AIReposition_DecideSingles`, `AI_CopyPositioning` | `void (AIController *)` | component copies to the Final blocks; `fn_886BADA0` also draws the singles net/baseline mode | C | repositioning s3.2 |
| `fn_8861E598` | `Rand_Uniform` | `float (float lo, float hi)` | game RNG | C (role) | ai-inputs s1 |
| `fn_8867DF68` | `TimingState_Update` | `void (PlayerController *)` | frames to the ball, TimingValue S+0xD08 | C | timing-and-fatigue s1 |
| `fn_881899D8` | `RangeCurve_Eval` | `float (RangeList *r, float x)` | clamped ramp over a `{InStart, InStop, OutStart, OutStop}` list | C | timing-and-fatigue s1 |
| `fn_88661B60` | `TimingState_ResetOnLaunch` | `void (PlayerController *)` | resets TimingState at the opponent's launch | C | timing-and-fatigue s1 |
| `fn_886B3CF8` | `SwingRequest_Update` | `void (PlayerController *)` | request state machine; commits ManualShotTiming at 3 sites | C | controls s4 |
| `fn_8865E430` | `Repositioning_UpdateSprint` | `void (PlayerController *)` | S+0xA2C = Rush && vigor >= 0.1; RequiredAmplitude S+0xA10 = 1 | C | OPEN 3.1 |
| `fn_8866FB60` | `MoveSpeed_Query` | `void (Mover *, float *speed, bool *valid, bool *sprint)` | speed by move state hash (`0xA740FF84` ActionReceiver: override S+0xDE8; `0x7653DEC8` ActionRepositioning: RequiredAmplitude + sprint; `0x77579282` this+0x34; GE2 corrected GE1's sign-extended hashes) | C | OPEN 3.1, repositioning s5 |
| `fn_886629C8` | `ShotSpecific_Fill` | `void (ShotContext *sc, ShotDefRef *def)` | copies ShotResolution grades into ShotSpecific by the Power/Control keys (serve variant fills ServeSpecific), then sets `SC+0x100` = the EvaluateList entry keyed by ResolutionConfig | C | OPEN 1.5, 1.9 |
| `fn_8826DD20`, `fn_8826DDF8` | `GradeRange_Get` (8 / 16-byte grades) | `void (const void *table, const uint32 *grade, void *out)` | VeryGood/Good/Normal/Bad/VeryBad select +0/8/0x10/0x18/0x20 (x2 for 16-byte) | C | OPEN 1.9 |
| `fn_8865AC08` | `Grade_Value` | `float (const uint32 *grade)` | VeryGood 1, Good 0.75, Normal 0.5, Bad 0.25, else 0 | C | OPEN 1.9 |
| `fn_8865EB60` | `PlayerCtx_IsReturnOfServe` | `bool (PlayerCtx *)` | serve phase, other team serving, this is the receiving slot | C | OPEN 1.11 |
| `fn_88699300` | `Planner_PrepareState` | `void (Planner *, int state)` | 23-way prepare; sets HandAttributeQuality, speed override, flags per state | C (partly) | OPEN 1.11 |
| `fn_8868FCC0` | `HitPoint_Publish` | `void (PlayerCtx *)` | fills `ReceiverState.#c7b7bdac` (frames, distance, required speed, difficulties) | C | OPEN 3.8 |
| `fn_8869A4D0` | `Planner_PublishSide` | `void (Planner *)` | side from `fn_88688D90` into S+0xA34 and S+0xBD1 (matched, ga4_a.c) | C | OPEN 3.2 |
| `fn_881896F8` | `Line2_Intersect` | `bool (Line *a, Line *b, Vec4 *pt, float *t1, float *t2)` | x-z line intersection; false when parallel | C | movement-and-ai A.4c |
| `fn_886A9678` | `Planner_ReplanCheck` | `int (Planner *)` | 1 / -1 / 0 from the 20-frame predicted position against the stand-point line | C | movement-and-ai A.4c |
| `fn_886A33C0`, `fn_886A32B8`, `fn_886A3238`, `fn_886A31B8` | `Planner_TrySteps`, `_TryStepsFast`, `_TryJog`, `_TryRush` | `bool (Planner *)` | state-15 entry tests of `fn_886A9E48` (profiles +0x208, +0x208 with MaxSpeed 6.0, +0x218, +0x228); `32B8` writes back 3.0 into PT+0x210 | C | movement-and-ai A.4c |
| `fn_8865D8D8` | `Candidates_IsVolleyThenBounce` | `bool (CandidateSet *, int side)` | hittable stretch starts non-Baseline and ends Baseline | C | movement-and-ai A.4c |
| `fn_886887C0` | `Planner_ModeSlack` | `float (Planner *, Vec4 *q, ...)` | frames left minus preparation table PT+0x17C (Mover speed, run angle) minus lead | C | movement-and-ai A.4c |
| `fn_88688948` | `Planner_ModeValid` | `bool (Planner *, ModeRecord *, ...)` | farther than min distance and table(distance, slack) >= 0.5 | C | movement-and-ai A.4c |
| `fn_88689068` | `Candidates_Score` | `void (Planner *, SideRec *, SideRec *, bool volley)` | selection score; PT+0x1B8 human reach flattening; candidates not of the wanted type (Volley / Baseline) get Reachability 100 | C | movement-and-ai A.4c |
| `fn_886894A8` | `Candidates_ScoreBoth` | `void (Planner *+0x38, bool volley)` | `fn_88689068` on both sides | C | movement-and-ai A.4c |
| `fn_886B8468` | `Planner_NextState` | `int (Planner *)` | 23-way transition function (all cases transcribed: `mv_next_state`) | C | movement-and-ai A.3 |
| `fn_886BA768` | `Planner_Reset` | `void (Planner *)` | clears P+0x121/0x125/0x13C/0x284/0x285/0x294/0x295/0x298 | C (partly) | movement-and-ai A.4c |
| `fn_8866CDC8` | `Mover_Update` | `void (Mover *)` | 3-frame mean velocity (+0x50) and speed (+0x68, m/s), tau 0.6 x 5 | C | repositioning s5 |
| `fn_886BB0A8` | `Repositioning_Update` | `void (PlayerController *)` | mode dispatch R+0x40, doubles points team+0x160..0x190, AI post-swing hold `#6e33662f` | C | repositioning s1 |
| `fn_8868C090` | `Repositioning_Points` | `void (PlayerController *)` | net / baseline points (graph 116 or play-mode-1 settings) | C | repositioning s2 |
| `fn_8869B928` | `Repositioning_HumanMode` | `void (PlayerController *)` | human net-rush rule (box, stick 40 deg, RB, 175 cm, 20 frames) | C | repositioning s3.1 |
| `fn_8868C218` | `Repositioning_BehaviorFlags` | `void (PlayerController *)` | raises behaviour flags (S+0xFBD Rush) every PT 0xA8C frames | C | repositioning s3.1 |
| `fn_8866CBE0` | `RepositioningDoubles_Nearest` | `int (Team *, Vec4 *pos)` | mode of the strictly nearest doubles point | C | repositioning s4 |
| `fn_886A40A8` | `RepositioningDoubles_AISwap` | `void (AIController *)` | half away from the partner; baseline when behind -900 | C | repositioning s4 |
| `fn_8866D368` | `Team_OtherHitter` | `PlayerCtx *(Team *)` | the other team's hitter | C | repositioning s1 |
| `fn_8865EC70` | `PlayerCtx_LocalToWorld` | `Vec4 *(Vec4 *out, PlayerCtx *)` | LocalPosition to world | C | repositioning s1 |
| `fn_8865E730` | `Court_MirrorBySide` | `void (Vec4 *v, uint32 side_tag)` | mirrors x and z for the far tag 0xA2EDA1E7 | C | repositioning s1 |
| `fn_88676AF0` | `Rules_UpdateServerAndEnds` | `void (Scoring *)` | server, serve side, ends, doubles rotation | C | rules s4.6 |
| `fn_886902E8` | `Fatigue_Init` | `void (PlayerController *)` | vigor = recovery = VigorMax = 1, constant graphs | C | timing-and-fatigue s2 |
| `fn_88690540` | `Fatigue_Update` | `void (PlayerController *)` | per-frame load and CurrentVigor | C | timing-and-fatigue s2 |
| `fn_8866ECA8` | `Fatigue_AddAnimationCosts` | `void (PlayerController *)` | animation-event costs from `PT+0x618` into `S+0xF28` | C | timing-and-fatigue s2 |
| `fn_8866EE48` | `Fatigue_PointEnd` | `void (PlayerController *, float rest)` | between-point recovery | C | timing-and-fatigue s2 |

## 2. Layouts (absolute PlayerState offsets)

`AimingState` (S+0xD60, C + Layoutall):

| off | field | written by |
|---|---|---|
| 0xD60 | `#4fc9dd9e.PolarResult` {angle, power} | AI serve aim |
| 0xD70 | `StickOverride` {x, y} | debug shot editor |
| 0xD78 | `DeepDeviation` (cm) | aiming graph |
| 0xD7C | `DeviationSystem.Random` | `fn_88695640` |
| 0xD84 | `#3c6beee9` | (open, OPEN 1.10) |
| 0xD88 | `Efficiency` | aiming graph / AI serve |
| 0xD8C | `OutEfficiency` | fault graph / AI serve |
| 0xD90 | `QuadEfficiency` | `fn_88695C48`, Out path |
| 0xDA8 | `FinalEfficiency` | graph 196 / difficulty `7bcf55ee` |
| 0xDAD | `DirectionSelected` (byte) | `fn_886935A0`, AI |
| 0xDAE | StickOverride enable (byte) | debug shot editor |

`TimingState` (S+0xCE0): 0xCF0 frames to contact (`3fe3a099`), 0xCF4 `d2797eb6`, 0xCF8
press-to-launch frames, 0xCFC `18d5f130`, 0xD00 ball speed km/h (`1490306b`), **0xD04
`TimingBaseFrame`**, **0xD08 `TimingValue`**, **0xD0C `TimingAbility`**. `ShotContext.ManualShotTiming`
= S+0x544.

Repositioning and movement fields (GE2, C + Layoutall): S+0x5DE `Context.#541e9e0a` and S+0x5DF
`#acfa7448` (state-14 exits), S+0x9A0 `MoveState` (Mover+0x14 points here), S+0x9D0 `RequiredMove`
{LocalDirection, Power} (held heading in state 13/14), S+0x9FC MoveMode, S+0xA1C..0xA28
repositioning points (net x/z, baseline x/z, graph 116), S+0xA2C sprint, S+0xA2D repositioning
mode active, S+0xA2E arrived, S+0xBD0 `HitPositionSelection.#43f09208` (AI volley pick), S+0xBD1
IsLeftLine, S+0xFAC..0xFAF VolleyRight/Left, BaselineRight/Left (planner states 17/18).
PlayerCtx: +0x4C own team, +0x5C Mover. Planner: +0x284 side flags latched, +0x288/0x28C held
command.

`Fatigue` (S+0xF20): see `timing-and-fatigue.md` s2 and `ref/gameplay/fatigue.h`.

AI record (`State.bin` type `D7C700B9`, 0x274 bytes): see `ai-inputs.md` s2.

AimingConfig (Settings `cfg+0x108`, 25 x 0xA0): four zones of {AimingQuad list header +0, centre
vec4 +0x10} at +0x00/+0x20/+0x40/+0x60 (VolleyCenter, VolleySide, BaselineCenter, BaselineSide),
then `Id` +0x80, `VolleyDistance` +0x84, `BaselineDistance` +0x88, `CenterDistance` +0x8C,
`SideDistance` +0x90, `#5ed23100` +0x94 (D; `tools/ts4data/aim_tables.py`).

## 3. Constants

`g_ts4_script_constants` = 0x880D0F70: +0 = 1.0, +0x38 = -1, +0x80 = 0.001,
+0x1BC = 0.01, +0x2AC = 0.1, +0x408 = 0.02, +0x518 = sqrt 2, +0x51C = 1.4, +0x55C = 1.25,
+0x644 = 137 (doubles alley, cm); GE2: +0x118 = 0.4, +0x404 = 40, +0x4EC = 225, +0x82C = 700, +0x830 = 1.5707951, +0xF0 = 50 (more in `data/gameplay/repositioning.yaml`). `lbl_8814B440` = 0.0, `lbl_8814B910` = 0.5, `0x8814B45C` = 2.0.
