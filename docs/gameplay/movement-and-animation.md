# Movement and animation, end to end (agent G6)

This note joins the movement planner to the animation system. It covers locomotion clips, special and automatic swings,
and the animation mechanics (clip clock, transitions, blending, mirroring, root motion). A port should be able to
reproduce the behaviour with the game's own animations from it.

* Planner states, regimes, reach speed and the jog ramp are documented in `player-and-movement.md`, `movement-and-ai.md`
  and `gp3.md`, with C in `ref/gameplay/movement.c` and `player.c`. This note cites them and does not repeat them.
* The clip-fit cost `fn_886D3AD8` was decoded by G4b (`player-and-movement.md` s4.3). It is implemented here as
  `as_fit_cost`.

Confidence tags:

* **V**: read from code or data.
* **I**: inferred from consistent evidence.
* **U**: unknown or guessed.

Addresses are in `Swing_DLL.dll` (base 0x88000000), as `tools/fn_asm.py fn_XXXXXXXX` shows them.

## 0. Files and reproduction

| File | What |
|---|---|
| `tools/ts4data/anim_rules.py` | Stdlib extractor: AnimationsDB.bin + swinganimation.bin through the Layoutall.bin walker (`tools/ts4_xbin.py`) |
| `data/gameplay/animation_rules.yaml` | Generated: qualifier types, every clip's properties, qualifier masks, events and transition windows, transition rules and matrix, groups, move sets, selection and condition procedures, positioning and miss lists, planner parameters |
| `ref/gameplay/locomotion.{h,c}` + `test_locomotion.c` | Sectors, move-set pick, transition events, matrix and rules, blend, clip clock, loop cycle, RotY, play rate, root step, override hysteresis, retarget |
| `ref/gameplay/anim_select.{h,c}` + `test_anim_select.c` | Qualifier filter DSL, swing key filter, mirroring, positional clip fit and arg-min, contact frame, Dive trigger, reward tags, reach gates |

Reproduce the YAML (about 2.5 s; output 2,123,915 bytes, under the 5 MiB limit):

    python3 -I tools/ts4data/anim_rules.py --core work/disc/core_all
    # defaults: --layout work/disc/root/Layoutall.bin --names work/disc/values/names.json
    #           --out data/gameplay/animation_rules.yaml

Source files (the hashes are also in the YAML header):

| File | Location | Size | sha256 |
|---|---|---|---|
| AnimationsDB.bin | Core.arc 70155255, root 0xEE710815 | 3,437,395 | `3a3a98cf71d1c82479bd5842ac596a599d5e90fa12c22e69e8c65f64aaf7a3dc` |
| swinganimation.bin | Core.arc 85ff436e, root 0x3A60FEE2 | 445,172 | `901b8cefe0ae6fd42e27f511b87db000ed1d81af92ee03bb0138824a7f49e43c` |
| Layoutall.bin | disc root | 760,816 | `67793f5b7dc771f8fde298ef07e8976d9362c864ac577a4c9db6b2bf874788c5` |

Tests:

    cc -std=c11 -Wall -Wextra -Werror -o /tmp/tl ref/gameplay/test_locomotion.c ref/gameplay/locomotion.c -lm && /tmp/tl
    cc -std=c11 -Wall -Wextra -Werror -o /tmp/ta ref/gameplay/test_anim_select.c ref/gameplay/anim_select.c -lm && /tmp/ta

Tools: gcc 13.3.0, Python 3.13.18. PyYAML 6.0.3 is used only to check that the YAML parses; the extractor does not need it.

## 1. Data model (V)

### 1.1 Animation record (AnimationsDB `Animations`, 3,184 x 0x8C)

| Offset | Field | Notes |
|---|---|---|
| +0x00 | RuntimeParam | |
| +0x0C | PreEventIndirection.FirstIndex (s16) | gp7's "record+0xC != -1" test |
| +0x10 | BallBouncePreEventIndirection | |
| +0x14 | Properties (0x44) | see below |
| +0x58 | MotionData | `Element<Play>`, blends |
| +0x64 | AnimEventList | rows `{Id, Pos, Duration, Orientation}`, phases 0..1 |
| +0x70 | TransitionEventList | rows of 0x28 bytes (s3.1) |
| +0x7C | RotYBehavior | `RotY_JogType` (178 clips) or `RotY_BasicTransition` (327 clips) |
| +0x84 | Id = crc32(name) | |
| +0x88 | PlayCountStat | |

Properties offsets are relative to Properties, so the record offset is +0x14 + N:

| Properties offset | Field | Shipped |
|---|---|---|
| +0x00 | FrameCount | |
| +0x04 | SpeedCoef | not 1.0 for 145 clips (0.9..1.2: transitions, Walk_Serve, Idle_Baseline 0.9) |
| +0x08 | Setup | Men or Women |
| +0x0C | GroupIndex | |
| +0x0E | SubGroupIndex | |
| +0x18 | NoMirror | 169 clips: all are Photo, Cutscene, pose or PCR clips; **no gameplay clip** |
| +0x19 | IgnoreSpeedCoef | 93 clips |
| +0x1C..+0x30 | Tolerancy Up, Down, XPos, XNeg, ZPos, ZNeg (cm) | |
| +0x34 / +0x38 | AngleClamp Left / Right (deg) | |
| +0x3C | ServeDropTime | 4 clips |
| +0x40 | MaximumOccurency | 1 for most clips, 8 for 41 |

**Correction to gp7 (V).** gp7's "time ratio at record+0x14" is `FrameCount`:

* `fn_886D1408` maps a phase to a frame: `clamp((phase - t0)(FrameCount - 1) + base, base, end)`.
* In `fn_886CD3C8`, "segment[1]+0x10" is `TransitionEvent[1].Position`.
* So "anim busy" is the number of frames until the clip's Out transition window opens (`lo_frames_until_out`).

`pl_time_warp` and `pl_anim_busy` in `player.c` compute the same thing, but their parameter is called `ratio`.

### 1.2 Qualifiers

There are 46 qualifier types; the YAML lists them under `qualifier_types`. Each clip carries one u32 bitmask per type, in
`QualifierEnumRawDataArray` (root+0x14+0x84, 146,464 u32 = 3184 x 46), where bit i is value i. Example: clip 0 is
Category=Swing, SwingType=FH, SwingCategory=FlatReturn, Properties=SwingReach.

The types used by gameplay are:

* PositionOnCourt, Category, SwingType, BHType, SwingEffect;
* Timing, Power, Control, MoveToNet;
* SwingCategory (31 values);
* Properties;
* Effort, Surface, ProStyle, PlayerHeight, SwingPreferenceLevel;
* SplitSteps, TransitionQuality, RepositioningDirection;
* the EndOfPoint types (AttitudeType, IntensityEOP, EndOfPointType).

Counts are in the YAML `clip_classes`. Properties counts:

| Property | Clips |
|---|---|
| SwingReach | 193 |
| Spectacular | 92 |
| Smash | 38 |
| WrongFoot | 30 (transitions) |
| Rushing | 20 (all Rush_*) |
| ReflexVolley | 16 |
| BadControl | 8 |
| TrickShot | 4 |
| PowerfulShot | 4 |

`SwingPreferenceLevel` is 5 for 2,952 clips and 3..8 for the rest. It is a likely tie-break weight (I; reader not found).

### 1.3 Groups, sub-groups, move sets

* There are 126 anim groups: Men and Women x 63. The list in the YAML is `anim_groups`, each entry with its sub-groups
  and clip ranges.
* A **sector** is an `[AnimGroup, SubGroup]` pair.
* `swinganimation.bin` root+0x70 holds 34 **move sets**, each a list of sectors in the fixed order:
  Front, FrontLeft, Left, BackLeft, Back, BackRight, Right, FrontRight, Stand/Idle, then an optional second Back.
  * Jog: `[4] = Back_LookRight`, `[9] = Back_LookLeft`, chosen by the condition `LookLeft`
    (`AnimationSelection/b873c3ab/LookLeft`).
  * Rush: `Back_TurnLeft` / `Back_TurnRight`.
  * Volley_Repositioning has 16 sectors (22.5 deg).
  * The C is `lo_sector8`, `lo_sector16` and `lo_moveset_pick`. The order is V; the angle rounding is I.
* Move-set kinds are None, Swing, MissSwing and EOP. A Swing or MissSwing set has one sector `[Swing, Swing]`: the clip
  comes from the qualifier selection (s4), not from the direction.
* Steps_FH uses Backsteps_FH for FrontLeft, Left and BackLeft. Moving away from the forehand side means backstepping (V, data).
* `root+0x94`: 17 **positioning** lists that point at group InPositioning. These are approach-to-stand clips such as
  `Jog_FrontRight_FH_To_Stand_FH_Long` and `Idle_To_Jog_Right_FH_Fast_MediumDist_To_Stand_FH_00`.
  `fn_886A26E0` (planner state 19) fits these.
* `root+0xA0`: 46 **Miss** lists that point at group Swings_Miss (`Idle_Right/Left`, ...). `fn_886A58F0` uses them.
* So G4b's "+0x94 reach / +0xA0 normal" query lists are these two lists (I, from the matching offsets).
* `root+0x34`: the qualifier sources (s4.2). `root+0xC0`: the planner target (Position 30 / 120 / -120 cm, MinTime 0,
  MaxTime 25 frames). `root+0x00`: PlannerParameters (1.0, 20.0, 15.0, ...).

## 2. Locomotion

### 2.1 From stick to clip

The chain from the pad to a playing clip:

1. **Pad.** The pad and InputMapper give the move stick, and RB sprints (`input-to-shot.md`). A human's stick goes
   through `ai_effective_stick` (movement.c).
2. **Planner.** `fn_886B8468` (23 states) chooses the move command (heading, intensity) `S+0x9D0/0x9D4` and the
   regime. The regimes are Rush=20, JogJogPrepared=21 and JogPrepared=22, chosen from the validity tables
   `PT+0x270/284/298`; validity >= 0.5 plus minimum distances 400 / 2000 / 175 cm. C: `pl_select_regime`,
   `mv_next_state`. (V, other agents.)
3. **Speed override `S+0xDE8`** (0 = walk, 1 = run). Planner state 6 enter (`fn_886AA420`) sets it from the table
   `PT+0x34C`. The new value replaces the old one only if it differs by more than 0.4 (pool+0x118): `lo_override_update` (V).
   The jog ramp `fn_88688678` can also write it, but its step table `PT+0x3B0` is all zeros in the shipped data, so it is inert (V).
4. **Animation selection** reads the PlayerState `AnimationSelection` block (crc 7a34f0d1, `S+0x2AC..0x3A7`):

   | Offset | Key |
   |---|---|
   | 0x38C | Movement.Frequency |
   | 0x390 | SplitSteps |
   | 0x394 | PositionOnCourt |
   | 0x398 | RushSpeedCoef (graph output; inputs Profile.Speed, CurrentVigor) |
   | 0x39C | VolleySpeedCoef (constant 1.15) |
   | 0x3A0 / 0x3A4 | TransitionQuality keys (procedures 4ccbdb8f / 3bcceb19) |

   The direction relative to facing picks the sector of the current move set (Jog, Rush, Sidesteps_*, Steps_FH/BH,
   Jog_FH/BH, Jog_Volley_*, *_Wait_*). (V for the data, I for the angle mapping.)
5. **Clip choice inside the sub-group.** Usually there are several clips (Normal/Good/Bad, Medium/Fast variants). They are
   filtered by the selection procedures (s4.1), for example TransitionQuality, SplitSteps, RepositioningDirection and
   Surface. `MaximumOccurency` limits repeats (I).

### 2.2 Transitions (V for the data, I for the runtime order)

* **TransitionMatrix.** 314 x 314 absolute sub-group indexes, holding a rule index or -1. YAML `transition_matrix.rows`
  stores `[to, rule]` pairs. C: `lo_matrix_rule`.
* **TransitionRuleList.** 128 rules: 114 Transition and 14 Allow.
  * Transition names a bridging clip group/sub-group (the `Tr_*` groups, for example `Tr_Jog_To_Sidesteps`).
  * Allow cuts straight across.
  * Fields: SourceEventIndex and DestEventIndex (which TransitionEvent of each clip to align),
    Low/HighVivacitySpeedCoef (0.8 / 1.0 where present), BlendIn/OutFrameCount (15/15, or 10/10 for the Allow rule 9).
  * C: `LoTransitionRule`, `lo_rule_speed`. The bridging speed is a lerp by "vivacity", the fatigue graph's liveliness
    output (I). `lo_blend_weight` is a linear cross-fade (I).
* **TransitionEvent** (0x28 bytes, record +0x70):

  | Offset | Field |
  |---|---|
  | +0x00 | CyclePosition |
  | +0x04 | BlendCyclePosition |
  | +0x08 | Direction mask |
  | +0x0C | Pace mask |
  | +0x10 | Position |
  | +0x14 | Duration |
  | +0x18 | DefaultCyclePosition |
  | +0x1C | ReactivityTag (a phase in the data) |
  | +0x20 | StartBlendTag (a phase, often equal to Position) |
  | +0x24 | In |
  | +0x25 | Out |

  * Direction bit i is Direction value i: None, Front, FrontRight, Right, BackRight, Back, BackLeft, Left, FrontLeft.
    Example: `Jog_FrontLeft` event 1 has mask 256, which is FrontLeft (V).
  * Pace bits: Sidesteps, Jog, Serve, Jog_FH, Jog_BH, Backsteps, Steps_FH/BH, Backsteps_FH/BH, Jog_Volley_FH/BH,
    Steps_Volley_FH/BH, Backsteps_Volley_FH/BH.
  * Typical locomotion clip: event 0 is a short window near phase 0.25 (entry), and event 1 is the cycle window from
    about 0.3 to 1.0 with In and Out both set.
  * Typical swing: event 0 is In only at phase 0; event 1 is Out only, from about 0.6 to 1.0. That is the
    recovery/interrupt zone.
  * C: `lo_event_accepts`, `lo_next_out_event`, `lo_can_leave`. The ReactivityTag role is U.
* **Loop.** 221 locomotion clips carry `Cycle_In` / `Cycle_Out` AnimEvents. While the move continues, the phase wraps
  between them: `lo_cycle_phase` (I).
* **Code-driven yaw** (RotYBehavior). These are not root motion:
  * `RotY_JogType {ApplyRotYStartFrom (frames), OutAngle}`. The body turns by +-pi/4 on the diagonal jogs, inside the
    `ApplyRotY` event window.
  * `RotY_BasicTransition {TransitionZoneStart/Stop, Coef, InAngle, OutAngle}`.
  * C: `lo_roty_offset`. The data is V; the linear curve is I.

### 2.3 Clip clock and root motion

* **Frame mapping, busy, rate to target:** see s1.1 and `pl_rate_to_target` (`fn_886C72E0`, V).
* **Play rate:**

      rate = Parameters.SpeedCoef (1.0)
           x clip SpeedCoef        (unless IgnoreSpeedCoef)
           x gameplay coefficient  (when the group's allow_speed_coef is set)
           x transition speed

  The gameplay coefficient is one of RushSpeedCoef `S+0x398`, SwingSpeedCoef `S+0x378` or VolleySpeedCoef 1.15
  `S+0x39C`. C: `lo_play_rate`. Each input is V; that they multiply is I.
* **Root motion and displacement.** Locomotion clips move the player with their root track. The fit samples the root
  with `fn_88644CE8`, scales y by `AnimIface(+0x3CC)+0x55C` and the vector by a per-call scale, and rotates it by the
  facing angle with `x' = x c - z s`, `z' = x s + z c` (V, `fn_886D3AD8`). C: `lo_root_step`.
  * The likely per-player scale is the PlayerHeight step factor `f769c520`, 0.89..1.09 by height band (YAML
    `height_steps`, for example Men 182 cm = 1.00). (I)
  * The planner adds code-driven displacement only for adjustments: states 7 / 8 turn and stop
    (`fn_8867A908`, `fn_8826AC10`). (I)
* **Retarget interrupt** in the `fn_886B8468` prologue (V): the ball is within 250 cm (62500 cm^2), the locomotion clip
  is not Idle (7c161a2b) or 230a53b8, and the angle tests (0.96 / 1.82 / 2.36 rad) pass. Then the planner goes to state
  7 (turn) or 8 (stop, when the heading dot > 0). C: `lo_retarget`; the angle tests are passed in as a flag.

### 2.4 Fatigue and sprint

* RushSpeedCoef (`S+0x398`) and SwingSpeedCoef (`S+0x378`) are analyser-graph outputs fed by Profile.Speed, CurrentVigor
  and the fatigue level (G1 `graphs-catalogue.md`). They feed the play rate of the Rush and swing groups. So fatigue
  slows the **animations** as well as the planner speed (I).
* RB sprint enters through the input mapper. Its write to an animation key was not traced (U). It most plausibly
  selects the Rush regime or move set.

## 3. Special and automatic swings

All swings go through one path:

1. The planner commits a candidate (`player-and-movement.md` s3.6).
2. The shot logic writes the seven SwingSelection.Output keys (s4.2).
3. The Swing move set filters the clips by qualifiers.
4. `fn_886D3AD8` picks the clip whose root motion puts the racket nearest the predicted contact (s4.3).
5. The clip is time-scaled so EventRacket lands on the planned frame (`AnimIface+0x464`).

"Special" swings are qualifier classes that the gameplay keys or conditions unlock. The table summarises how each is
selected and what it does; confidence is per row.

| Swing | Clips (data, V) | Trigger and selection | Gameplay effect |
|---|---|---|---|
| Reach / stretch (lunge) | `Properties=SwingReach` 193; SwingCategory Flat/SliceGoodReach, Flat/SliceBadReach | Planner state 19 Reach (`fn_886A26E0`) with gates: contact height 50..200 cm `PT+0x3BC..0x3C0`, minimum distance 100 cm `PT+0x3F4`, contact window (0,20)/(0,30) ticks, tolerance 60 cm (V). Timing/Position keys pick Good vs Bad reach (I) | ReachAnimation reward (+0x374); skill ReachSwingsExpert improves the shot (G4b) |
| Spectacular | `Properties=Spectacular` 92 (BadReach jog clips, reflex volleys, 4 dives) | Selected like reach when the reach class carries the tag | SpectacularAnimation reward (I: tag cell k0) |
| Dive volley | 4 clips `Swing_Volley_FH/BH_Dive_Stand_OpenStance_Waist`, SwingCategory VolleySpectacular, AnimEvent `Dive` | `fn_886BCE88` sets `S+0x388` VolleySpectacular (`stb r11,0x388(r29)`, about 0x886BD5C0..0x886BD620) when all of: x > -600 cm (pool+0x390); team mode != 2; ctx+0x3B8 set; skill SpectacularVolleys 0x1E8D4F10 (`fn_8868F0D8`); TimingState `S+0xD00` > 60 and `S+0xCF0` < 45 (V). Condition procedure "Dive" reads that key, and procedure "VolleySpectacular" filters on it (V) | Spectacular reward; confirms R1 hypothesis 20. C: `as_volley_spectacular` |
| Rushing | Rush group, 10 x 2 clips, `Properties=Rushing` | Planner regime Rush (20) and move set Rush; speed scaled by RushSpeedCoef | RushingAnimation reward; RushingToBall when distance > cfg+0xC4 and ratio > cfg+0xC8 (`as_rushing_to_ball`) |
| Put-away ("Fatality") | 74 clips, groups Swings_FH_Fatality, SwingCategory Fatality | Gameplay writes SwingCategory (`S+0x360`) Fatality (I; writer not traced) | Fatality reward when `S+0xE00 > cfg+0x934` (ball-physics.md) |
| Tweener (trick shot) | 4 clips `Swing_(FHBH|BH)_Trick_Jog_Back_Medium_GoodPos_Knee`, `Properties=TrickShot` | Automatic when running back to a lob at knee height (direction Back, Jog). Selected by sector Back plus the fit (I) | TrickShot reward (+0x37F) |
| Powerful shot | 4 BH 2H Power Steps clips, `Properties=PowerfulShot` | Power key VeryGood with steps (I) | PowerfulShotAnimation reward |
| Reflex / auto volley | VolleyReflex 100, `Properties=ReflexVolley` 16 | PositionOnCourt=Volley with low time (I) | ReflexVolleyAnimation reward |
| Smash | 38 `Properties=Smash`; groups Swings_FH/BH_Smash, Smash_FH/BH (8 directional sectors plus Jump variants) | Automatic: candidate type Smash (smash band 230..280 cm, `pl_classify_sample`); move sets Smash_FH/BH | SmashAnimation reward |
| Half-volley | **no dedicated clips** (no HalfVolley/Pickup name) | Uses ordinary `_Knee` swings chosen by the fit at low contact height (I) | none specific |
| Too late / bad context | SwingCategory Flat/SliceTooLate (Timing=TooLate 18), BadContext 8, `Properties=BadControl` | Timing key TooLate and `S+0x358` BadContext (V keys) | weak shot (shot error model) |
| FollowNet (approach) | 118 `*_FollowNet_*`; MoveToNet=Yes 126 | MoveToNet key `S+0x3BC` | the player continues to the net |
| Serve / return | MovesServe, ServeSwing groups; move sets Baseline/VolleyServeSwing, MovesServeStart; return clips FlatReturn 231 / SliceReturn 30 | Serve/ReturnServe ProStyle keys (procedures a305331b, 04a9f2b5), ServeAndVolley `S+0x37C` | the serve drop is timed by `ServeDropTime` (4 clips) |
| Miss | Swings_Miss group, 46 Miss lists | Move set Miss (kind MissSwing); `fn_886A58F0` | none |
| Celebrations / EOP | EOP group, 297 EndOfPoint clips; condition procedures GiveUpLeft/Right, Tired, Transition, Apologize, Applause, WoodUpCompliant | EndOfPoint keys (Attitude, IntensityEOP, ProStyle, Surface); procedures 6e4bb141 ... f02f24e2 | none (cosmetic). Tired / GiveUp clips match R1 hypothesis 25 on the animation side |

Reward edge detection (`fn_88697118`, the tag tracker):

* Cells k0..k6 and k16 are raised by the playing clip's Properties: Spectacular, SwingReach, Rushing, PowerfulShot,
  ReflexVolley, Smash and TrickShot, plus Fatality.
* Each reward fires once per clip, on the rising edge.
* C: `as_rewards_from_props`, `as_reward_edges`.
* Confidence: the cell names are V from the reward table (gp1); the cell-to-Properties binding is I.

## 4. Selection mechanics

### 4.1 Selection procedures (swinganimation.bin root+0x7C, 36 procedures)

* Each procedure is a filter tree. Node kinds, by crc:

  | crc | Node |
  |---|---|
  | `cb3c6c47` | all |
  | `d837ca33` | any |
  | `c4cc0a5f` | not |
  | `00bf4ffc` | equals (constant value) |
  | `332e57c4` | match_key (value read from a gameplay key through a KeyXPath) |
  | `1ae94a04` | match_key_mask (mask read from a key) |

  Every leaf has an `Exclusive` flag. The tree is V. C: `as_eval`.
* **Exclusive semantics (U).** Two readings fit the data:
  * the clip must carry only the wanted value (implemented); or
  * clips that carry the value are reserved for this procedure and are excluded elsewhere. Procedures `Volley`,
    `Baseline` and `VolleySpectacular` are Exclusive equals filters, which fits the second reading.
* **A zero mask** on a clip means the clip is unconstrained (I). For example, about 100 swings have no Timing bit.
* **YAML limitation.** For nested trees the YAML flattens children into `terms` with `node: "all/match_key[1]"` paths,
  and a few deep trees repeat indexes. The raw tree is recoverable from the walker paths.
* **ConditionProcedures** (root+0x88, 19) name boolean keys. Examples:
  * `Dive` → `AnimationSelection/SwingSelection/VolleySpectacular`;
  * `LookLeft` → `AnimationSelection/b873c3ab/LookLeft`;
  * EndOfPoint `GiveUpLeft/Right`, `Tired`, `Transition`, `Apologize`, `Applause`.

### 4.2 Gameplay to animation keys (V offsets)

`qualifier_sources` (root+0x34) map seven qualifiers to PlayerState `SwingSelection/Output`:

| Qualifier | Offset |
|---|---|
| Timing | `S+0x3B0` |
| Power | `S+0x3B4` |
| Control | `S+0x3B8` |
| MoveToNet | `S+0x3BC` |
| PositionOnCourt | `S+0x3C8` |
| SwingEffect | `S+0x3CC` |
| SwingType | `S+0x3D0` |

The `AnimationSelection.SwingSelection` block holds:

| Offset | Key |
|---|---|
| 0x358 | BadContext |
| 0x360 | SwingCategory |
| 0x364 | BHType |
| 0x368 | ProStyle |
| 0x36C | Surface |
| 0x370 | e241b13b (surface key of the Clay procedure) |
| 0x378 | SwingSpeedCoef |
| 0x37C | ServeAndVolley |
| 0x384 | SwingType |
| 0x388 | VolleySpectacular |

C: `as_swing_matches` (Category=Swing plus the seven keys; -1 = unset).

### 4.3 Clip fit (G4b decode, V structure)

`as_fit_cost` follows `player-and-movement.md` s4.3:

* `m = R(facing) * (root at warped EventRacket, y scaled) * scale`, plus an optional rotated linked offset;
* `p = m + base`;
* `e = p - (target - ref)`;
* gates `+0x3D0 <= t_c <= +0x3D4`, `|e.x| < +0x3D8`, `|e.z| < +0x3DC`;
* cost `|e|^2`.

`as_fit_best` returns the arg-min (planner+0x168 / +0x170). The `|m|` tolerance reshaping (fsel clamps on caller
constants) is left to the caller (U constants).

Selection order (I):

1. sector or move set;
2. qualifier filters;
3. MaximumOccurency / PlayCountStat;
4. positional fit;
5. SwingPreferenceLevel as a tie-break (U).

### 4.4 Mirroring (V/I)

* Left-handed players play the right-handed clips mirrored. The racket lateral offset flips with handedness
  (`pl_racket_lateral`, gp7; V).
* The fit rotates only when the clip's side id matches the wanted side (`r30 == r25`; V).
* NoMirror is set only on cutscene and photo clips, so every gameplay clip is mirrorable (V, data).
* C: `as_mirror_mode`, `lo_root_step(mirrored)`. The x-negation is I.

## 5. Open items

1. **Writers of the SwingSelection.Output keys** (`S+0x3B0..0x3D0`) and of SwingCategory `S+0x360`: who sets Fatality,
   TooLate and FollowNet. The stores found were noisy (U).
2. **Exclusive flag semantics** and the meaning of procedure values that print as `00000000` (U).
3. **Which clip Properties fields the code reads** (Tolerancy*, AngleClamp*, MaximumOccurency): the offsets were not
   confirmed in `fn_886D3AD8` or its callers (I). The Tolerancy values (35 / 60 cm) look like the fit's per-axis gates.
4. **Tag cell to Properties binding** in `fn_88697118` (I).
5. **Names of TimingState fields** `S+0xCF0` (3fe3a099) and `S+0xD00` (1490306b) used by the Dive gate (U).
6. **Sector angle rounding**, the Back look-side rule, the vivacity source of the transition speed and the blend curve (I).
7. **Sprint (RB)** path into animation keys (U).
8. `tests/test_gameplay_ref.py` (owned by another agent) does not yet build `locomotion` or `anim_select`. Add
   `"locomotion": ["locomotion.c", "test_locomotion.c"]` and `"anim_select": ["anim_select.c", "test_anim_select.c"]`
   when convenient.
