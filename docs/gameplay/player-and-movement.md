# Player character and match flow (agent G4)

Scope: player ratings and how they reach the mechanics, fatigue, the movement planner (23 states, Rush / Jog / Reach,
speeds, reaction delay, reach radii), swing candidate selection and commit, swing clip choice and time scaling, AI
differences, positioning, crowd and rewards, rules and the per-frame order. This note **adds** to `gp0`..`gp3`, `gp7`,
`movement-and-ai.md`, `stats-swing-clipfit.md`, `rules-and-scoring.md` and `analyser-graphs.md`; where it says
"see X" the older note is still right. Section 1 lists what is new here.

Binary: `Swing_DLL.xex` sha256 `dfa71292...fac44`, PE image `orig/54540859/Swing_DLL.dll` (base 0x88000000).
Disassembly: capstone 5.0.7 over the PE image, with undecodable VMX128 words printed as `.word` and skipped.
Data: `Core.arc` members extracted by name hash into `work/disc/core_all/`. Each member's sha256 is in the header of
`data/gameplay/player.yaml`. `Settings.bin` (`334e7e0d`) is `55cb175d...0167`.
Names are `zlib.crc32` of ASCII. Confidence: **V** read in code or data and reproducible, **I** inferred, **U** unknown.

Deliverables:

| Path | What |
|---|---|
| `tools/ts4data/player_data.py` | stdlib extractor, writes the two YAML files below |
| `data/gameplay/player.yaml` | PlayerTuning (named and raw), AI level table, crowd/fatigue/reward blocks, player graphs, AnimationData root, skeleton |
| `data/gameplay/animation_clips.yaml` | all 3,184 AnimationsDB records: name, frames, slot, tag, kind, EventRacket / Preparation phase and frame, annotations, segments |
| `ref/gameplay/player.{h,c}`, `test_player.c` | readable C for the formulas below, with a synthetic self-test |
| `tests/test_player_data.py` | synthetic tests of the extractor's decoders |

Reproduce:

```
python3 tools/ts4_arc.py orig/54540859/disc/Core.arc --extract <hash> --out work/disc/core_all   # per member
python3 -I tools/ts4data/player_data.py --core work/disc/core_all
cc -std=c11 -Wall -Wextra -Werror -o /tmp/tp ref/gameplay/test_player.c ref/gameplay/player.c -lm && /tmp/tp
python3 -m unittest tests.test_player_data
```

## 1. New facts in this note (headline)

1. **The player tuning block is in `Settings.bin` at file offset 0x1A4** (V). `fn_886BE4E0` does
   `ctx+0x2C = (*(world+0x44))+0x6C + 0x180`, i.e. **PlayerCtx+0x2C = cfg + 0x180**, where cfg is the Settings root at file
   0x24 (`shot-to-template.md` s1). Every PlayerTuning offset in the older notes (`+0x17C`, `+0x1F8..+0x248`, `+0x270/284/298`,
   `+0x2AC..`, `+0x3BC..+0x3F4`, `+0x630`) now has a shipped value. The three mode tables decode as 2-D tables, the six style
   records as `{flags, limit, volley limit}`, and the four zones as `{a, b, radius}`. All of them fit the readers.
   Both players share one block: there is a single cfg, and no per-player copy was found.
2. **The ReachEvaluator's tuning `E+8` is the same block at PlayerTuning+0xA0** (I, structural). `fn_8869B178` reads four
   per-stroke-level float arrays at `T+0/0xC/0x18/0x24`, which are exactly PT+0xA0/0xAC/0xB8/0xC4 (five entries each).
   The height bands `T+0x40..0x54` fall at PT+0xE0..0xF4 and decode to 200..280 cm. The reach fields `T+0xF4..0x10C` fall at
   PT+0x194..0x1AC. So the gp2 `T[...]` and gp3/gp7 `cfg[...]` offsets differ by 0xA0. `T+0x10C` and gp3's
   "anim lead `cfg+0x1AC`" are the same word.
3. **AI difficulty is a table in Settings, `cfg+0xF0`** (V, `fn_886A0EC8`). It has 9 play-style groups (16-byte
   `{rel,count,cap,style key}`), and each group has 6 records of 0x5C bytes keyed at `+0x3C` by **VeryEasy, Easy, Normal,
   Hard, VeryHard, Expert** (names verified by crc32). The lookup key is `ctx+0x7C` (player info): `+8` is the style and `+4`
   the level. When a key is not found, the lookup falls back to the first entry. Record layout:
   * `+0x00/0C/18/24/30` are five lists (element layout U). `fn_886B6448` consumes the ones at `+0x18/+0x24/+0x30`.
   * `+0x40..+0x54` are six analyser names, loaded by `fn_8866F028` into the brain (`ctx+0x50`):
     * `+0x48` -> `+0x158`, the ground selection score graph
     * `+0x4C` -> `+0x19C`, the volley score / hit grade graph
     * `+0x44` -> `+0x1E0`, the reaction window graph
     * `+0x50` -> `+0x224`
     * `+0x40` -> the timing object
   * `+0x58` is the **skill float** (4, 5, 6, 8, 9..10 m/s by level). It replaces the fallback style's speed limit
     `PT+0x230` during the AI search (`fn_8869AEF8`). So a harder AI accepts candidates that need a faster run.
   The level changes three things: the reaction graph, the score/timing graphs and that speed limit (V for the wiring;
   the graph contents are in `Expressions.bin`).
4. **Reaction delay** (state 0) is the float at `((ctx+0x50)+0x28)+0x1DC` (V, `0x886B8938`).
   * `brain+0x28` is set in the brain init `fn_886B69F8` to a per-player 0x274-byte record of the world block:
     `(world+0x28)+0xE8C`, then `+ slot*0x274`.
   * The value is therefore a **runtime** float, not a disc constant.
   * Its writer is not located. The likely writer is the reaction graph at `brain+0x1E0`, chosen by the AI level (I).
5. **Movement speeds are data tables of slack, not fixed velocities** (V for the code, values in YAML):
   * The mode tables `PT+0x270/284/298` map (distance, slack ticks) to a validity. In the shipped data, validity is 1 up to
     a distance-dependent slack and then falls to 0. Rush is chosen when time is short; Jog when there is slack.
   * State 6 enter (`fn_886AA420`) sets the **speed override** `S+0xDE8` from the table `PT+0x34C`. The call is
     `fn_886887C0(PT+0x34C, busy + PT+0x1A4)`, and the override is rewritten only when it changes by more than 0.4
     (pool +0x118). Shipped table: 1.0 at small slack, falling to 0 as slack grows. The player walks when early.
   * `PT+0x3B0` (jog ramp step, `fn_88688678`) is all zeros in the shipped data, so the jog speed ramp is inert.
   * Seven `{table2d, f32}` speed records sit at PT+0x31C..0x37C. Only `+0x34C` has a decoded reader.
6. **`fn_88688678` (jog ramp)**, corrected from movement-and-ai A.6 (V):
   * `elapsed = now - P+0x280`. If the ramp is initialised (`P+0x14C`) and `elapsed % PT+0x3EC != 0`, then
     `P+0x140 -= P+0x150` and the result is published to `S+0xDE8` (with `S+0xDEC = 1`).
   * Otherwise it re-initialises: `P+0x150 = table2d(PT+0x3B0)(|contact - player|, fn_8866BFE8 slack)` and sets `P+0x14C = 1`.
7. **Clip catalogue.** 1,638 of the 3,184 AnimationsDB records carry `EventRacket`, all of them `Swing_*`. Families: BH 646,
   FH 540, Volley 306, Return 89, Smash 38, Serve 9, ServeAndVolley 8. Locomotion: Sidesteps 116, Jog 64, Rush 20,
   Steps 20, Backsteps 16, Splitsteps 6, Idle 89. The swing name grammar is in s6.2.
8. **`swinganimation.bin`** (`85FF436E`, root type `0x3A60FEE2`) is the AnimationData root that gp7 reads at run time.
   It names seven swing-selection criteria (`Timing`, `Power`, `Control`, `MoveToNet`, `PositionOnCourt`, `SwingEffect`,
   `SwingType`), each with its own list, and slot definitions keyed by `EOP` (= `0x959A9407`, the "unnamed" play-slot kind
   of gp7/df 3.1), `Idle`, `ReturnServeFH/BH`. Raw words are in `player.yaml: swing_animation` (field roles U).
9. **`PlayerSetup.bin`** (`798A36DD`) is the skeleton setup: 0x10-byte rows `{bone, parent bone, parent index, -1}`, with all
   names resolved (B_Hips, B_Spine.., B_Head, B_LeftHand, B_RightHand ...).
10. Other Settings sub-blocks that player code takes as `cfg+X` (V, from `lwz 0x6C; addi X` pairs). All are dumped in
    `settings_blocks`:

    | cfg offset | Used by | Role |
    |---|---|---|
    | `+0x824` | `fn_8868E968` | crowd gain step table |
    | `+0x830` | `fn_8868EAFC` | crowd cap by shot count |
    | `+0x83C` | `fn_8868E3C0` | crowd events `{hash, float}` |
    | `+0x8F8` | `fn_886BC0CC` | fatigue object init |
    | `+0x92C` | — | U |
    | `+0x9B0` | `fn_8869B940`, `fn_8868C3B0` | stick/side helper (not the reach tuning) |
    | `+0xAB0`, `+0xAD0` | — | U |
    | `+0xB10`, `+0xB1C` | — | reward rules (gp1 s4) |
    | `+0xC34` | `fn_8865B770` | reward points |

## 2. Player ratings, skills and Profile values

### 2.1 Storage (V, from `stats-swing-clipfit.md` s1)
* PlayerState `S` (stride 0x1070) holds eight floats at `S+0x64C..0x668`: Serve, Return, Forehand, Backhand, Volley,
  Power, Speed, Stamina.
* `S+0x640` is the skill list (`{id, value}` pairs). The first four entries with value 1.0 become Skill1..4 (`fn_8869DEF0`).
* The external record (`fn_887AC0E0`) has 14 ints: Serve, Return, Reflex, Forehand, Backhand, Volley, Power, Speed,
  Stamina, Mental, Overall, Skill1..4. Reflex and Mental have no in-match float. They act only through the data (U).

### 2.2 Rating -> Profile -> mechanic (V wiring, I roles)
* Graph `DefaultAttributes` (`0x8C9B26E0`) and its twin `0x075A2137` each have one CURVE per rating, with inputs at
  `Profile.<3B91D48C>` cells 40..47.
* The shipped curves map ratings of 30..100 to Profile values of 0..1. Keys are in `player.yaml: graphs`.
* Under the "as stored" reading (slope 0) each key holds its `y0`, so the curve is a step. The ramp reading uses `y1`.
  The two readings give different values between key ends. G1 owns this open question; `pl_curve20` implements both.
* Profile consumers (`analyser-graphs.md` s6):

  | Profile cell | Read by | Effect (I) |
  |---|---|---|
  | 20 (stamina) | `FatigueIngame`, `FatigueConst` | fatigue gain and constants |
  | 29 (speed) | `RushSpeedCoef`, `SwingSpeedCoef` | movement and swing animation speed scale (`AnimationSelection.Movement` cell 202, `.SwingSelection` cell 201) |
  | 37 (volley) | `VolleyTimingAbility`, the volley zones | volley timing |
  | 18, 26, 49 | 31, 50 and 27 graphs | the widely used Profile values: InputFiltering, IsTired, ReturnServeZone ... |

* The order of cells 40..47 versus `S+0x64C..0x668` is U. The pairing 41 -> 20 (stamina), 43 -> 29 (speed) and
  45 -> 37 (volley) is inferred from the consumers.
* **Per-stroke skill** `S+0x74C` is set on swing-state entry (`fn_88699300`). It takes Return for a return, Forehand or
  Backhand by `(handedness==Left) != S+0xBD1`, Forehand in states 0xA/0xB, and Volley in states 0xC/0x10. The serve path
  stores Serve (`fn_886BCE88`), then runs the analyser at `controller+0x504` (V). `pl_stroke_skill`.
* **Side preference** `fn_8865B3B0`: the stronger side is preferred until its use share passes a threshold.
  `pl_side_preference` (I for the return values).
* Coach skills, levels and XP: the strings `CoachBonusXP`, `SeriesBonusXP`, `T4CoachBonuse.anims` are UI/career data.
  No match code reads a coach table. Coaches act only through the skill list `S+0x640`, which the graphs read through
  `Profile.SkillList` link ports (389 ports, qualifier per skill U).

### 2.3 Fatigue (V wiring)
* `FatigueIngame` (inputs `Fatigue.Input` cells 19/21/22 plus Profile 20) produces `Fatigue.Output` cell 188.
* `FatigueConst`, `80CE1A10`, `8ADD300F` and `Vivacity` are loaded by `fn_886BC1E0` into the fatigue object. They produce
  the constants and the "liveliness" value. The fatigue level cell 16 is read by RushSpeedCoef, SwingSpeedCoef and the
  error graph (`E4F01642`).
* `cfg+0x8F8` is the fatigue object's Settings block.
* How the inputs (distance run, rally length) are accumulated is U.

## 3. Movement planner

### 3.1 Objects and per-frame flow
* Objects: see movement-and-ai A.1/A.2 (V).
* Flow: `fn_886BF360` (PlayerController Update) -> `fn_886BF260` (hashed request machine `fn_886B3CF8`, at most 8 hops)
  -> `fn_886BD690`:
  1. refresh the candidate sets when `S+0xBC8 == -1`;
  2. run `next = fn_886B8468(P, cur)` at most 8 times, with leave `fn_8865DAC0` and prepare `fn_88699300`;
  3. run the enter effects `fn_886AA280`.
* The jump table of `fn_886B8468` is at `0x886B88BC` (23 entries). State entry points (V):

  | State | Entry | State | Entry | State | Entry |
  |---|---|---|---|---|---|
  | 0 | 886B8918 | 8 | 886BA2B4 | 16 | 886B997C |
  | 1 | 886B8984 | 9 | 886BA670 | 17 | 886B9B90 |
  | 2 | 886B8F48 | 10/11 | 886B9DF8 | 18 | 886B9A14 |
  | 3 | 886B90D4 | 12 | 886B9E60 | 19 | 886BA188 |
  | 4 | 886B9110 | 13 | 886BA148 | 20/21/22 | 886B92BC (shared) |
  | 5/6 | 886B917C | 14 | 886B9F10 | | |
  | 7 | 886BA2DC | 15 | 886B9554 | | |

### 3.2 The 23 states
Names and exits are in `movement-and-ai.md` A.3 (with the swap of 21/22 against gp3) and `ref/gameplay/movement.h`.

| # | Name |
|---|---|
| 0 | Wait |
| 1 | AnticipateA |
| 2 | AnticipateB |
| 3 | SwingReady |
| 4 | Swing |
| 5 | Approach |
| 6 | ApproachNear |
| 7 | Turn |
| 8 | Stop |
| 9 | Replan |
| 10 | AltA |
| 11 | AltB |
| 12 | AltSwing |
| 13 | Hold |
| 14 | BallWindow |
| 15 | Choose |
| 16 | Volley |
| 17 | ReadyA |
| 18 | ReadyB |
| 19 | Reach |
| 20 | Rush |
| 21 | JogJogPrepared |
| 22 | JogPrepared |

Only 20..22 are named by game strings; the others are role names. New enter-effect detail (V): state 6 sets the speed
override from `PT+0x34C` (s1 item 5), not a heading.

### 3.3 Reaction delay and anticipation
* State 0 waits until `now - (opp team+0x24)+0x68 >= ((ctx+0x50)+0x28)+0x1DC`, or until the opponent mode is 2.
* State 1 enter runs the reaction graph (`brain+0x1E0`, chosen per AI level). It writes the window `S+0xDF4/0xDF8`.
* The plan is held while `0 <= now - P+0x2A0 <= S+0xDF4` (`fn_8865DB50`).
* The selector `fn_886A9E48` uses pool 0.25 (`+0x29C`) and the 120 degree turn test (2.094 rad, `+0x554`).

### 3.4 Speed regimes (Rush / JogJogPrepared / JogPrepared)
* `fn_88699FC0`:
  * style `PT+0x238/0x248` -> state 0xB; style `PT+0x1F8` -> state 3; Volley sample -> state 0x10;
  * otherwise, in order: **Rush** (only when `(ctx+0x6C)+0x158 > PT+0x630`, shipped -1.0, so always tried),
    **JogJogPrepared**, **JogPrepared**;
  * a regime is accepted by `fn_88688948`: distance > `min_distance` (shipped 400 / 2000 / 175 cm) and validity >= 0.5;
  * none valid -> 5 (or 6 by the side-angle test).
* Validity (`fn_886887C0`) is `table2d(mode)(|contact - player|, slack)`, where
  * `slack = (sample.tick - now) - table2d(PT+0x17C)(ball value, |angle|) - lead`;
  * `lead = fn_886CD3C8(clip busy) + PT+0x1AC`.

  `pl_mode_validity`, `pl_mode_valid`, `pl_select_regime`.
* In the shipped data the Rush table holds validity 1 up to slack 35 / 56 / 102 / 139 / 175 / 184 / 201 ticks for
  distances 400..1500 cm. JogJog is valid up to a larger slack at each distance.
* **Actual velocity** is not a planner constant. The planner sets
  * a polar move command `S+0x9D0/0x9D4` (heading, intensity 1.0) and
  * a speed override `S+0xDE8` (0..1).

  The locomotion clip (Rush / Jog / Steps / Sidesteps, keyed by `anim+0x468`) supplies the root motion, scaled by the override
  through `fn_8866FB60` and by `RushSpeedCoef` (Profile speed, fatigue) (I for the multiplication chain). So
  **top speed = Rush clip root-motion speed x RushSpeedCoef**. Acceleration is the clip blend: `BlendInFrameCount` /
  `BlendOutFrameCount` exist as AnimationDB field names (U where read). No velocity integrator exists in the planner.
* The 7 speed records PT+0x31C..0x37C (`{table2d, 6.0}`) and the jog ramp (s1 item 6) refine the override.

### 3.5 Reach and interception (V, gp2 s4 with shipped values)
* Candidate type per prediction sample (`fn_8869B178`, `pl_classify_sample`):

  | Input | Location | Shipped |
  |---|---|---|
  | `|x|` too close to the net plane | code constant | <= 150 cm -> Unreachable |
  | in-zone `|x|` limit | `PT+0x178` | 750 cm |
  | low split (in / out of zone) | `PT+0xE4` / `+0xE0` | 220 / 200 cm |
  | smash band | `PT+0xE8..0xF4` | 230..280 / 260..280 cm |
  | look-ahead | `PT+0x160` | curve |

* Required speed (`fn_8868B4E8`, `pl_reach_speed`): `(run - radius) / (ticks - prep - turn - busy) * 0.6` m/s.

  | Parameter | Location | Shipped |
  |---|---|---|
  | radius, normal / `S+0xBD2` | `PT+0x194` / `+0x1A0` | 10 / 30 cm |
  | volley radius | code constant | 10 cm |
  | volley box dead zones | `PT+0x198/0x19C` | 100 / 250 cm |
  | prep ticks, normal / volley / alt | `PT+0x1A4/0x1A8/0x1AC` | 10 / 0 / 15 |
  | turn ticks | `table2d(PT+0x17C)` | table |
  | no-time value | code constant | 100.0 |
  | in-reach but late | code constant | FLT_MAX |
  | hard cut in scoring | code constant | > 50 m/s |

  The small radii reflect that positions already include the per-level racket offsets `PT+0xA0..0xC4` (94..106 /
  -79..-91 / +-46..54 cm).
* Style records (candidate filters, `fn_8869A520`). Each is `{flags, speed limit, volley speed limit}` in m/s:

  | Style | Offset | Shipped limits |
  |---|---|---|
  | default | `PT+0x1F8` | 3 / none |
  | | `PT+0x208` | 3 / 4.25 |
  | | `PT+0x218` | 6 / 4.75 |
  | fallback | `PT+0x228` | 10 / 7; AI replaces 10 by its level skill 4..10 |
  | alt A, smash-only | `PT+0x238` | 3 / 4 |
  | alt B, smash-only | `PT+0x248` | 2.5 / 3.5 |

* Reach / lunge (state 19, `fn_886A26E0`):

  | Gate or output | Location | Shipped |
  |---|---|---|
  | contact height band | `PT+0x3BC..0x3C0` | 50..200 cm |
  | minimum target distance | `PT+0x3F4` | 100 cm |
  | contact window, normal / alt (`S+0xBD2`) | `PT+0x3CC/0x3D0` / `PT+0x3C4/0x3C8` | (0, 20) / (0, 30) ticks |
  | tolerances | `PT+0x3DC/0x3E0` | 60 cm |

  `pl_contact_window`, `pl_racket_lateral` (left-hand mirroring).
* Zones `{a, b, radius}`:

  | Zone | Offset | Shipped |
  |---|---|---|
  | swing ready | `PT+0x2AC` | 50 / 100 / 120 |
  | approach | `PT+0x2B8` | 80 / 150 / 300 |
  | regime | `PT+0x2F4` | 50 / 200 / 200 |
  | alt | `PT+0x300` | 35 / 250 / 250 |

  The retarget radius 250 cm (62500) and the angles 0.96 / 1.82 / 2.36 rad are code constants (gp3 5.3).

### 3.6 Selection and commit (V, gp2 s3/s6, swingstats s3)
* Pipeline: `fn_8869AB70` -> `fn_8868AF88` -> `fn_88689508` (graph) -> `fn_8865DBA8` (arg-max) -> `fn_886A2E48` (commit with
  hysteresis).
* The grade is rolled once per plan (`pl_grades`: `S+0x3A0` Bad/Good at 0.5, `S+0x3A4` Bad/Medium/Good at 0.33/0.66).
* Side-select and score helper curves (shipped): `PT+0x14C`, `+0x188`, `+0x1BC`, `+0x1C8`, `+0x1D4`.
* `PT+0x1E0` is the InputNotation angle weight. It runs from 0 at 0 rad to 1 at +-0.6 rad.

## 4. Swing animation: selection, clip fit, time scaling

### 4.1 Records (V, `docs/port/clip-map.md`, `df.md` 3)
* AnimationsDB TakeList is 3,184 records x 0x8C bytes, with fields:
  * `+0x14` length in frames;
  * `+0x0C` slot (u16);
  * `+0x1C` tag (two values);
  * `+0x60` kind: clip, set of 9 (base + 8 additive), 5 variants, 2-clip blend;
  * `+0x64` annotations `{name, phase}`;
  * `+0x70` segments;
  * `+0x84` id = crc32(name).
* Annotation times are **normalised phases** (0..1), so `contact_frame = phase x frames` (`pl_contact_frame`; the YAML
  stores both). The racket-speed check of clip-map.md s3 confirms that EventRacket is the moment of contact.
* Other annotation names: `Hand_FH_Pose` (622), `ApplyRotY`, `Cycle_In`, `Stomp`, `HeavyStomp`, `Slide` (clay),
  `Preparation` (73), `CutScene_*`.

### 4.2 Swing name grammar (V from the 1,638 names)
`Swing_<Side>[_<Grip>][_<Shot>][_<Tier>]_<Movement>[_<Direction>][_<Stance>]_<Position>[_<Control>]_<Height>[_<Variant>]`

| Slot | Values |
|---|---|
| Side | FH, BH, Volley, Return, Smash, Serve, ServeAndVolley, FHBH |
| Grip | 1H, 2H |
| Shot | Flat, Slice, DropShot, InsideOut |
| Tier | Power, Medium, Finesse |
| Movement | Stand, Jog, Steps, Reach, Jump, FollowNet |
| Direction | Front, Left, Right, FrontLeft, FrontRight, Back, BackLeft, BackRight |
| Stance | OpenStance, CloseStance |
| Position | GoodPos, FarPos, ClosePos, EarlyPos, LatePos, BadReach, TooLate, Miss |
| Control | GoodControl, BadContext |
| Height | Knee, Waist, Shoulder, OnBody |
| Variant | Reflex, Fatality, Clay, player names (Nadal, Federer ...), numbers |

### 4.3 Selection (V for structure; cost function U, as in gp7 s6)
* The query lists in the AnimationData root (`+0x94` for reach, `+0xA0` for normal) restrict the candidates by record id.
* `fn_886D3AD8` samples each candidate's root motion at the warped EventRacket time, rotates it by the facing, and
  compares it with `AnimIface+0x3C0` (target) inside the window `+0x3D0/0x3D4` and tolerances `+0x3D8/0x3DC`. The best
  cost is stored at planner `+0x170`.
* The seven criteria of `swinganimation.bin` (Timing, Power, Control, MoveToNet, PositionOnCourt, SwingEffect, SwingType)
  are the likely axes that map onto the name grammar slots (Tier = Power, Position = Timing/PositionOnCourt,
  Control, Movement = MoveToNet ...) (I). The weights are in that file (raw words dumped, roles U).
* `SwingSpeedCoef` (Profile speed, fatigue, LocalPosition) writes the swing animation speed cell 201 (I: playback scale).

### 4.4 Time scaling (V formulas from gp7 s4/s5; C in `player.c`)
* `pl_time_warp`: `clamp((t - t0)(ratio - 1) + base, base, end)` (`fn_886D1408`).
* `pl_anim_busy`: `max(0, (seg1 - t0)(ratio - 1) + base - now)` (`fn_886CD3C8`). This busy time feeds reach and validity.
* `pl_rate_to_target`: `(event - clip_now) / (target - now + 1)`, otherwise `rate *= decay` (`fn_886C72E0`). The contact is
  hit by **time-scaling the clip** so its EventRacket lands on the planned frame `AnimIface+0x464`.

## 5. AI (opponent) differences
* Same pipeline, with the human flag `ctx+0x10 = (info+0x18 == crc32("Human"))`. See movement-and-ai B.1 for the five
  code differences.
* New here: the AI level record (s1 item 3) supplies
  * the scoring graphs `brain+0x158/0x19C`,
  * the reaction graph `+0x1E0`,
  * the skill speed limit that replaces `PT+0x230`.
* The nine style groups are not named by any dictionary. The candidates AllRounder, BaselineAttacker,
  BaselineController, PowerPlayer, VolleyPlayer, VolleyFinessePlayer and others did not match (U).
* `pl_ai_lookup`.

## 6. Positioning, serve and return
* Repositioning, Positioning and Serve positions are **graph outputs**: 21 graphs write `RepositioningComponents`, 10 write
  `PositioningComponents` and 8 write `ServeComponents` (analyser-graphs s6.5). The AI lists in the level record include
  the `Repositioning` hash (`96FE1E55`) (V).
* Inputs: the human requests `@ReqBaselineRepos` / `@ReqVolleyRepos` / `@ReqFastRepos` / `@Rush` (RB/LB, input-to-shot s2.4).
* PT+0x00..0x7F holds 8 `{x, 0, z, 0}` court positions (cm, x -500..-1400, z -350..+350). PT+0x8C/0x90
  and PT+0x124..0x12C hold 150/300 and 300/200/250. These are the likely wait/serve/return anchor positions (I; readers
  not traced). They are in `player_tuning.all_words`.
* Serve / return ready positions also come from the cut-scene and Return clips (`Swing_Return_*`,
  `Cutscene_GettingReadyToReturn_*`).

## 7. Crowd, excitement, rewards
* The formulas are in gp1 s4..s6. The Settings blocks are now located (s1 item 10) and dumped.
* `pl_excitement_step` implements `level = clamp(level + events + clamp(gain, -cap, cap), 0, 1)` (`fn_8868EA30`).
* Reward rising edges (Spectacular, ReflexVolley, Smash, PowerfulShot, Fatality, RushingToBall) are in gp3 s4.

## 8. Rules state machine and per-frame order
* Rules: `rules-and-scoring.md` (V). Covers point -> game -> set -> match, tie-break serving, serve faults and lets.
* Per frame (gp0 s3, V):
  1. Engine `fn_886C27F8`: input mapper -> per instance `fn_886C1ED8`.
  2. Inside `fn_886C1ED8`: end-of-point / school.
  3. `fn_886B5128`: apply due swing commands, launch the ball, predict.
  4. Interception helpers.
  5. Ball step `fn_889C2818`.
  6. Tag tracker `fn_88697118` / `fn_88696D40` (rewards).
  7. Frame counters.
  8. `fn_886ABAE8` (shot evaluation).
* The PlayerController (movement planner, swing selection) runs as its own module node in data order, then the
  SwingAnimationEngine Update `fn_886E5F50` (gp7 s3).

## 9. Open items
1. Who writes the reaction float `brain+0x28 -> +0x1DC` (probably the reaction graph output) and the eight rating floats.
2. Element layout of the five lists in the AI level record. Names of the nine style groups and of the six graphs.
3. Roles of PT+0x00..0x9F, PT+0x110..0x14B, PT+0x3F8..0x62F (the generic dump has every value; readers not traced).
   Readers of the speed records PT+0x31C..0x37C other than `+0x34C`.
4. Clip-fit cost (`fn_886D3AD8`, VMX128) and the field roles of `swinganimation.bin`.
5. The curve step/ramp question (G1). Every Profile value depends on it.
6. Coach and career tables (outside `Core.arc` Settings; not searched).
