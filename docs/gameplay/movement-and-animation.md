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

`SwingPreferenceLevel` is 5 for 2,952 clips and 3..8 for the rest. It is **not** a tie-break weight: the swing query
`fn_886AC7E0` writes the levels 8, 7, 6, 5, 4, 3 (PlayerTuning list PT+0x5B0) one by one into the key S+0x380 and keeps
the first level for which a clip starts (G6b, V; s6).

**Property readers (G6b, V).** The table offsets above are relative to the Properties block; code addresses the
record directly, 0x14 higher:
* Tolerancy (record +0x30..+0x44): `fn_886D3310` copies the six values into per-clip arrays at selector
  +0x40/+0x4C/+0x58/+0x64/+0x70/+0x7C; `fn_886D7638` is a debug live editor of the same values (GameplayInterface
  +0x298..+0x2A8). The consumer of those arrays was not traced. *GE1: no runtime reader found (OPEN 3.6); I: dead data.*
* AngleClamp Left/Right (record +0x48/+0x4C): `fn_886DAA48` copies them into AnimIface +0x44C/+0x450 when it starts a swing.
* MaximumOccurency (record +0x54): `fn_886CD880` copies it into a per-clip counter array at selector +0x14C;
  `fn_886C50D0` resets PlayCountStat (+0x88).

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
* RB sprint enters through the input mapper (`@Rush` S+0x4DD, `@ReqFastRepos` S+0x4E2, `@ReqVolleyRepos` S+0x4E4;
  controls-and-shot-selection s15.5). On the swing side the sticky RB (`PC+0x3D`) inside 300 cm of the net selects the
  category FlatFollowNet/SliceFollowNet (condition GoToNet) and blocks Fatality (G6b, V). Its path into the locomotion
  keys (Rush regime / move set) was still not traced (U).

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
| Put-away ("Fatality") | 74 clips, groups Swings_FH_Fatality, SwingCategory Fatality | `fn_886AFDF8` writes SwingCategory (`S+0x360`) Fatality as the first FlatPower/FlatFinesse row when: not (AI and S+0x4E0), not (sticky RB within 300 cm of the net), power S+0xE00 > 0.15 (G6b, V; s6) | Fatality reward when `S+0xE00 > cfg+0x934` (ball-physics.md) |
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

* `fn_886750D0` binds the tag cells to rows of the `8ea88f9f/Qualifier` list at S+0x2A0 (G6b, V). Properties
  cells: k0 Spectacular, k1 SwingReach, k2 Rushing, k3 PowerfulShot, k4 ReflexVolley, k5 Smash, k6 TrickShot,
  k7 BadControl, k8 WrongFoot, k9 56d002df and k10 Effort ef823202 (both absent from the data), k11/k12
  FrustrationLow/High, k13..k15 VictoryLow/Medium/High; k16 is SwingCategory == Fatality.
* Each reward fires once per clip, on the rising edge.
* C: `as_rewards_from_props`, `as_reward_edges`.
* Confidence: the cell names are V from the reward table (gp1); the cell-to-Properties binding is V (G6b).

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
* **Exclusive semantics (V, G6b, evaluator `fn_886C9F08`).** `want` is the node's mask (the value's bit; a value
  printing as `00000000` is mask 0):
  * equals and match_key_mask: Exclusive -> clip mask == want; otherwise (clip & want) == want. So Exclusive with
    the `00000000` value means "the clip carries no value of this type";
  * match_key: Exclusive -> clip == key; otherwise an unset key (0) needs clip == 0, a clip with mask 0 passes any
    set key, else (clip & key) == key;
  * a further node `9e4d5a77` compares the clip's first AnimEvent Id with the node value and, on a match, requires a
    condition bool from selector +0x20 (not modelled).
* **A zero mask** on a clip therefore passes only match_key leaves (wildcard) and Exclusive-none leaves. For example,
  about 100 swings have no Timing bit.
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
5. SwingPreferenceLevel: an outer loop 8 -> 3 around the whole query, not a tie-break (V, G6b).

### 4.4 Mirroring (V/I)

* Left-handed players play the right-handed clips mirrored. The racket lateral offset flips with handedness
  (`pl_racket_lateral`, gp7; V).
* The fit rotates only when the clip's side id matches the wanted side (`r30 == r25`; V).
* NoMirror is set only on cutscene and photo clips, so every gameplay clip is mirrorable (V, data).
* C: `as_mirror_mode`, `lo_root_step(mirrored)`. The x-negation is I.

## 5. Open items

G6b status: items 1-5 answered in s6 (1 partly: the Output-key contradiction remains); 6 and 7 still open.

1. **Writers of the SwingSelection.Output keys** (`S+0x3B0..0x3D0`): see s6.1. Open: who, if anyone, raises Power/
   Control above Good, given that the Fatality clips ask for VeryGood.
2. ~~Exclusive flag semantics~~ (s4.1).
3. ~~Clip Properties readers~~ (s1.1); the consumer of the Tolerancy arrays is still open.
4. ~~Tag cell binding~~ (s3).
5. **Names of TimingState fields** `S+0xCF0` (3fe3a099) and `S+0xD00` (1490306b): meanings known (s6.3), names not.
6. **Sector angle rounding**, the Back look-side rule, the vivacity source of the transition speed, the blend curve,
   root-motion mirroring and the retarget angle tests (I).
7. **Sprint (RB)** path into the locomotion keys (U); its swing-side effect is in s2.4.

## 6. G6b answers

### 6.1 Who writes the seven swing keys and SwingCategory (V)

| key | writers |
|---|---|
| Timing S+0x3B0, PositionOnCourt S+0x3C8, SwingEffect S+0x3CC | none in code (no store with that base and offset) |
| Power S+0x3B4, Control S+0x3B8, MoveToNet S+0x3BC | only the init `fn_8867E3A0`, which sets them to Good |
| SwingType S+0x3D0 | the serve `fn_886723A8` (FH) and the command copy `fn_886B5128` |
| AnimationSelection SwingType S+0x384 | the planner (ctrl+0x39 FH/BH) |
| SwingCategory S+0x360 | `fn_886AFDF8`, the swing-category rule walk (controls-and-shot-selection s17) |

`TooLate` is read only by the HUD (`fn_886865D8`) and the serve grade (`fn_886B2638`). `fn_886A9050` is the PC
constructor, not a PlayerState writer. Contradiction (open): the 74 Fatality clips require Power and Control
VeryGood, while code only ever stores Good. Either the `qualifier_sources` binding is not used by the swing query
(the selection reads S+0x360/S+0x380/S+0x384 through the procedures) or a data-driven writer exists.

### 6.2 Fatality (put-away) conditions (V)

Fatality is the first row of the FlatPower and FlatFinesse lists in all three modes (Normal, AutoSwingGood,
AutoSwingBad). Its condition (`fn_88697E98`, case c78c8f06) is: not (AI and S+0x4E0), and not (sticky RB `PC+0x3D`
and |z| < PT+0x6F0 = 300 cm), and S+0xE00 > 0.15 (`lbl_880D0934`). Slice, volley and smash classes have no Fatality
row. The query then needs a Fatality clip at some preference level. C: `ref/gameplay/swing_category.c`.

### 6.3 TimingState (V meaning, names unknown)

`fn_88661B60` fills them at the opponent's launch: `S+0xCF0` = sample tick - clock (frames to contact), `S+0xCF4` =
|depth difference|, `S+0xD00` = |ball velocity| x 3.6 (km/h; `g_ts4_script_constants+0x2A4` = 3.6), `S+0xD10`
(0eaa0333) the autoswing-good bool (controls s17.1). So the Dive gate reads "ball faster than 60 km/h and contact
in fewer than 45 frames".

### 6.4 Reproduction

```sh
TS4_MATCHING_DIR=work/matching-b9 python3 tools/fn_asm.py fn_886C9F08 fn_886AFDF8 fn_88697E98 fn_886AC7E0 \
    fn_886DAA48 fn_886D3310 fn_886CD880 fn_886750D0 fn_88661B60 fn_8867E3A0 fn_886B5128
cc -std=c11 -Wall -Wextra -Werror -o /tmp/tas ref/gameplay/test_anim_select.c ref/gameplay/anim_select.c -lm && /tmp/tas
python3 -m unittest tests.test_gameplay_ref
```

## 7. G9: root motion, cross-fade, starts, stops and swing exit windows

Owner G9 (movement responsiveness). Grades: **C** = read from code, **D** = read from data, **I** = inferred.
Frames are 60 Hz game frames at play rate 1. Clip-local root axes: +x forward, +z left (Right = -z).

### 7.1 Where the root motion lives (C + D)

* Root motion is **not** in the Havok files. AnimationsDB (`70155255.bin`, sha256 `3a3a98cf71d1c82479bd5842ac596a599d5e90fa12c22e69e8c65f64aaf7a3dc`) holds it as a
  2-D track per take. The root's reflected fields (real names, from the type dictionary) are:

  | root offset | field | row |
  |---|---|---|
  | +0x50 | Animations | 0x8C |
  | +0x60 | RTTakeList | 0x1C: MainHkxIndex, SplitHkxIndex, SplitPos +0x8, ExtractPosition_IndexBegin +0xC (u32), ExtractPosition_SampleCountMinusOne +0x10 (f32), XStart +0x14, ZStart +0x18 |
  | +0x6C | HkxList | 0x10 |
  | +0x78 | ExtractPositionList | {X, Z} f32 |

  `docs/port/clip-map.md` calls the +0x60 table "HkxList" and the +0x6C table "ExtractPositionList"; the names above
  are the reflected ones (D). That file is outside G9's area and is not edited here.
* `fn_8864A770` sets `animset+0xAC = root+0x78` (C).
* `fn_88644CE8` **RootTrack_SampleDelta** (C): for a take (`r4`) and two phases t1, t2 it returns
  P(t2) - P(t1), where P(t) = lerp(E[i], E[i+1], u - i), u = t * SampleCountMinusOne, i = trunc(u), E = the take's
  entries from IndexBegin. There is no clamp; at t = 1 the entry after the last is read with weight 0.
  C: `rs_root_delta` (ref/gameplay/responsiveness.c).
* About one sample every 4 frames (D: samples / frames over all clips), so the root velocity is piecewise constant over
  about 4-frame segments.
* `fn_886455A0` samples one clip; `fn_886457E0` sums a blend: Σ weight(+0x14) · scale(+0x24) · R(yaw +0x10) · Δ, with
  sin/cos polynomials at 0x880D1B00 / 0x880D1B10 (C).
* "blend" clips (Element<Blend> poly) carry two RTTake rows on one clock: a slow row and a fast row. Examples:
  Sidesteps_Right rows 38/39 travel 410 / 848 cm in 178 frames; Jog_Front_IK rows 1067/1066 travel 762 / 1115 cm;
  Backsteps_Back rows 48/49 travel 293 / 530 cm (D). The weight between them is not traced (I: a speed key).
* Women's records have their own RTTake rows. Their travel is 0.970-1.019 of the men's over 276 clip pairs (D).

Dump: `data/gameplay/root_motion.yaml` gives, for every Men locomotion clip, the cumulative xz per frame for row 0
(and row 1 for blend clips), plus the entry frame, the 5 / 25 / 100 cm milestones and the cycle speed. For swing clips it
gives contact, the Out frame, travel before and after, and speeds. Raw tracks are not committed.
Generator: `python3 -I tools/ts4data/root_motion.py --core work/disc/core_all`; `--clip NAME` prints one clip frame
by frame.

### 7.2 Cross-fade and Allow parameters (C, corrects s2.2)

* `fn_886D89E8` **AnimNode_UpdateBlend** walks the node chain (via +0x34). For each node the weight is
  `w = (clock - node+0x24) / node+0x2C`, clamped to [0, 1]. It is **linear**, and the node before it gets 1 - w (C).
  The writer of the duration `node+0x2C` was not found. The event-0 Durations of the locomotion clips are 10-19 frames
  (I: the source).
* The TransitionSpecialRule `Allow` Parameters `{HighViv, LowViv, BlendInFrameCount, BlendOutFrameCount}` are a
  **play-rate ramp**, not the cross-fade. Over BlendIn frames the rate goes toward the Low/High vivacity coefficient,
  chosen by anim iface +0x3F8 (= Vivacity S+0x9F4). Over BlendOut frames it goes back (C). Only 4 of the 128 rules
  have Parameters (one 10, three 15). The idle-to-locomotion rule 101 has none (D).
* So "a 15-frame TransitionRuleList blend" applies only to the four rules with Parameters, and it changes speed, not
  the pose weight. The pose cross-fade duration is open (OPEN s11 R16).

### 7.3 Standing starts (D; entry phase I)

* Idle_Baseline (absolute sub-group 73) and Idle_Return (74) go to every Jog, Sidesteps, Backsteps and Rush sector
  through rule 101 (Allow, SourceEvent 0 → DestEvent 0, no Parameters). There are no Idle_To_Jog_Front/Back clips. A
  start enters the cycle clip at its TransitionEvent[0] window (I: start phase = TE[0].Position).
* Milestones are counted from the entry frame. Each cell is frames to 5 / 25 / 100 cm. "no fade" is the raw clip.
  "+15 fade" weights frame k's root delta by min(1, k/15), which is the linear cross-fade above with an assumed
  15-frame duration (I).

  | case | clip (row 0) | entry frame | no fade | +15 fade | cycle speed |
  |---|---|---|---|---|---|
  | side, slow | Sidesteps_Right / _Left | 17 / 12 | 20/28/56 · 13/31/61 | 20/28/56 · 20/32/62 | 1.78 m/s |
  | side, run | Jog_Right / Jog_Left | 44 / 75 | 4/11/30 · 2/9/24 | 8/16/33 · 7/13/29 | 3.41-3.48 m/s |
  | side, sprint | Rush_Right / Rush_Left | 0 | 21/29/46 · 20/29/43 | 22/29/46 · 21/29/43 | 5.73-5.85 m/s |
  | forward, run | Jog_Front_IK | 51 | 12/21/41 | 14/22/41 | 3.46 m/s |
  | forward, sprint | Rush_Front | 0 | 14/25/42 | 18/26/43 | 5.75 m/s |
  | back, slow | Backsteps_Back | 23 | 7/21/50 | 11/24/52 | 1.82 m/s |
  | back, sprint | Rush_Back | 0 | 8/29/45 | 14/30/45 | 5.76 m/s |

  Diagonals, from entry: Jog_BackRight 9/23/46, Jog_FrontLeft 5/14/36.
* There is no forward "walk" clip: the slow sets are Sidesteps (sideways) and Backsteps (back). Forward always uses
  Jog. Which set a human's free stick gets (speed override S+0xDE8, move-set choice in `fn_886E08E8`) is not traced (I).
* Sprint is no faster off the mark: Rush clips start at frame 0 with a slow first step, and reach 1 m in 42-46 frames.
  That is about the same as Jog (24-41 frames). Rush only pulls ahead after about 1 m.

### 7.4 Stops and reversals (D)

Stop clips (Tr_*_To_Stand_Std, row 0). "90 %" is the frame at which 90 % of the total travel is done. "still" is the
last frame with more than 0.3 cm/frame.

| from | frames | travel | entry speed | 90 % | still |
|---|---|---|---|---|---|
| Jog_Front | 44 | 57 cm | 2.6 cm/f | 33 | 43 |
| Sidesteps (6 directions) | 41-43 | 22-45 cm | 1.7-2.9 cm/f | 17-33 | 35-42 |
| Backsteps_Back | 45 | 54 cm | 3.2 cm/f | 32 | 44 |
| Jog_FrontRight / FrontLeft | 48 | 115-119 cm | 4.8-6.5 cm/f | 27 | 43 |
| Jog_BackRight / BackLeft | 67-72 | 151-153 cm | 4.3-4.6 cm/f | 40 | 62-71 |
| Jog_Right_FH / Jog_Left_BH To_Idle | 85-92 | 57-137 cm | 4.9-5.8 cm/f | 11-25 | 84-91 |

Reversals (row 0, distance projected on the initial direction):

| clip | frames | overshoot (peak) | at frame | back past the start at | end |
|---|---|---|---|---|---|
| Tr_Jog_Front → Jog_Back_TurnRight / TurnLeft | 88 / 106 | 125 / 142 cm | 25 / 29 | 55 / 59 | -275 / -371 cm |
| Tr_Jog_Front → Backsteps_Back | 145 | 27 cm | 20 | 39 | -373 cm |
| Tr_Sidesteps_Right → Jog_Left_Normal | 88 | 79 cm | 24 | 54 | -209 cm |
| Tr_Jog_Right → Sidesteps_Left | 142 | 134 cm | 42 | 96 | -165 cm |

So a full reversal from a jog takes 39-96 frames before the player is back where he turned. Most of that time is the
clip's own overshoot. The planner's 10-frame Turn hold (P+0x128) only adds to it while the planner drives the player
(only while this player's team is the next hitter, movement-and-ai E.2).

### 7.5 Swing exit windows (D; busy test C)

* Per clip, the exit window is the first TransitionEvent with Out set and In clear. It runs from Position to phase
  1.0. The contact frame is the swing's hit AnimEvent. Tail = Out frame - contact frame, at rate 1.

  | class | n | tail p10/50/90 (frames) | root travel contact→Out p50 | notes |
  |---|---|---|---|---|
  | groundstroke | 461 | 27/36/44 | 76 cm | min -57 (window opens before contact), max 66 |
  | return | 46 | 19/26/37 | 37 cm | |
  | reach | 89 | 26/45/60 | 154 cm | |
  | volley | 151 | 29/38/51 | 83 cm | |
  | smash | 19 | 33/42/58 | 94 cm | |
  | put-away | 37 | 37/45/53 | 99 cm | 3 TransitionEvents |
  | serve | 11 | 24/34/39 | 64 cm | |
  | dive | 2 | 124 | 306 cm | |

* The root keeps moving through the tail: about 1.2-1.4 cm/frame at the window (median). The stick does not steer it.
* Who checks the window: the transition legality predicate `fn_886C5A08` (matrix root+0x44, rule type Allow
  0x575896F4, event index checks; C). The busy time `fn_886CD3C8` (C) works only when the clip has exactly 2
  TransitionEvents: `busy = max(0, (TE1.Position - node+0x14)(F-1) + node+0x24 - node+0x18)`. Put-away clips (3 TEs)
  therefore read as "not busy". Callers: `fn_88688948` (lead = busy + 15), `fn_8868B4E8`, `fn_88691E90`,
  `fn_88699300` (twice), `fn_886AA280`.
* No input cuts the tail short. The only exit is a matrix transition at an Out event, and no rule reads the stick to
  open one early (C, within the readers above; a runtime check is listed in OPEN s11 R17).

## 8. G8: special swings, the put-away and how movement feeds them

Agent G8. C = read from code, D = read from data, I = inferred. Trigger logic, modes and the ball effect of each
category are in `controls-and-shot-selection.md` s18; this section covers the clips and the movement side.
Dump: `data/gameplay/special_swings.yaml` (`python3 tools/ts4data/special_swings.py --settings
work/disc/core/334e7e0d.bin --core work/disc/core_all --out data/gameplay/special_swings.yaml`). It joins
`animation_rules.yaml` with G9's `root_motion.yaml` (s7) and samples the root with `root_motion.py`. Frames at rate 1,
frame = phase x (FrameCount - 1).

### 8.1 Clip shape per category (D, Men; [min, median, max])

| category | clips | frames | contact | shortest entry -> contact | contact -> Out | root travel to contact from frame 0 (cm) | last 40 f before contact (cm) |
|---|---|---|---|---|---|---|---|
| Fatality | 37 | 178 / 227 / 254 | 98 / 137 / 159 | 8 / 9 / 11 | 30 / 45 / 58 | 166 / 394 / 547 | 58 / 128 / 173 |
| FlatPower | 186 | 95 / 132 / 174 | 35 / 47 / 88 | 2 / 4 / 22 | 16 / 36 / 66 | 14 / 190 / 491 | 16 / 154 / 313 |
| FlatFinesse | 76 | 105 / 143 / 174 | 40 / 47 / 74 | 3 / 5 / 21 | 25 / 37 / 62 | 16 / 224 / 412 | 16 / 176 / 297 |
| FlatFollowNet | 41 | 96 / 133 / 206 | 34 / 40 / 107 | 0 / 7 / 11 | 19 / 29 / 66 | 39 / 149 / 511 | 39 / 149 / 214 |
| FlatGoodReach | 28 | 101 / 141 / 176 | 35 / 45 / 58 | 1 / 5 / 10 | 15 / 32 / 53 | 192 / 291 / 458 | 192 / 260 / 345 |
| FlatBadReach | 11 | 147 / 161 / 189 | 43 / 49 / 62 | 3 / 7 / 11 | 38 / 52 / 56 | 335 / 396 / 536 | 298 / 338 / 362 |
| FlatTooLate | 9 | 109 / 127 / 134 | 35 / 45 / 45 | 6 | 34 / 36 / 44 | 47 / 56 / 71 | 47 / 54 / 66 |
| FlatPerfect | 2 | 100 / 132 | 38 / 48 | 4 / 8 | 39 / 44 | 6 / 30 | 6 / 31 |
| FlatReturn | 117 | 109 / 135 / 218 | 36 / 59 / 95 | 7 / 19 / 50 | 14 / 36 / 67 | 1 / 61 / 204 | 4 / 59 / 168 |
| VolleyReflex | 50 | 95 / 133 / 197 | 28 / 38 / 80 | 2 / 7 / 47 | 17 / 47 / 82 | 22 / 56 / 308 | 22 / 55 / 202 |
| VolleyForward | 13 | 82 / 100 / 108 | 30 / 38 / 41 | 6 / 9 / 9 | 25 / 37 / 50 | 210 / 241 / 297 | 210 / 241 / 297 |
| VolleySpectacular | 2 | 240 / 256 | 72 | 23 | 124 | 125 / 127 | 112 |

The yaml also lists Slice, volley, smash and clay categories and every Properties value.

* **Fatality** clips are the long ones: about 2.3 s at rate 1 with a 4 m run-in before contact. All 37 are forehand,
  shoulder height, Power/Control VeryGood, preference 5, group `Swings_FH_Fatality` (allow_speed_coef 0). They have
  three TransitionEvents: In+Out at phase 0..0.08, In only at about 0.14..0.55, and Out at about 0.8. So the clip is
  normally entered part-way, 9 to 137 frames before contact. The selection horizon (now + 40 frames, `fn_886C9228`)
  makes the useful entries the last 40 frames, over which the root still travels 58-173 cm forward and is moving at
  about 2 cm/frame at contact.
* Because of the three TransitionEvents, the busy-time function `fn_886CD3C8` reads put-away clips as "not busy"
  (G9, s7.5). Whether that lets the planner act during a Fatality's follow-through needs a runtime check (OPEN s11).
* **Reach** clips (FlatGoodReach / FlatBadReach / SliceGoodReach) carry the player 2.6-3.4 m in the last 40 frames,
  which is how a stretch reaches the ball. Their categories also make the ball worse (controls s18.4).

### 8.2 How movement feeds each special swing (C, with I where marked)

| category | planner and fit inputs |
|---|---|
| Fatality | no planner state needed. Charge > 0.15, no sticky RB in |z| < 300 cm, a Flat/TopSpin/Lob groundstroke, and a FH shoulder-height Fatality clip that fits the predicted ball (tolerance box [40, 40, 80, -50, 50, -80] cm on all 37; facing clamp [-90, 30], [-90, 45] or [-90, 90]) |
| FlatGoodReach / FlatBadReach | min of the line MinSpeed values S+0xA5C / 0xABC above PT+0x1B0 = 3.5 / PT+0x1B4 = 4.5 m/s (the reach speed the planner needs), timing window for humans |
| SlowDown effects | planner state 19 (Reach) sets SlowDown S+0x7CC = 1: AutoSwingGood list and immediate queries |
| FlatReturn / SliceReturn | the fast-ball flags of Planner_Reset (return 65 frames / 300 cm; baseline 50 / 250) |
| VolleyReflex | volley lists; AI probes it on S+0x5DE (net fast ball, 35 frames / 200 cm) |
| VolleyForward | LocalPosition x + 450 (singles) / 600 (doubles) < 0, not Slice / DropShot |
| FollowNet | sticky RB in the corridor |z| < 300 cm |

### 8.3 Why a player who ran down a short ball early may not get the put-away

From the gates above (C), weighted by the clip data (I):

1. Too little charge at the walk (power <= 0.15, under 12 frames held): FlatFinesse class, where the Fatality row is dead.
2. RB held in the central corridor: FlatFollowNet wins.
3. Slice, drop shot, volley or smash: no Fatality row.
4. The ball is not at shoulder height on the forehand at contact: no Fatality clip can fit. This is the most likely
   reason, because a short ball is often taken at waist or knee height.
5. First fit wins: the walk tries Fatality first, but the first frame on which any clip in the list fits ends the
   request. If a FlatPower clip fits before a Fatality clip does, the put-away is lost for that shot.
6. Arriving very early is no help in itself: the clip has to fit at a 9-40 frame entry, which needs the player still
   about 0.6-1.7 m behind the contact point and moving forward (root travel above).
