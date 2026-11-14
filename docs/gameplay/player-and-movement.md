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
   * *GE1 (C, ai-inputs s5b):* `brain+0x28` is the AI record, so `+0x1DC` is `FinalPositioningComponents.#79b99b60`, written by the positioning component copy `fn_886B81E0`.
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
* PlayerState `S` (stride 0x1070) holds the **raw ratings** at `S+0x620..0x63C` (`Profile.#3b91d48c`) and the
  **Profile values 0..1** at `S+0x64C..0x668`. Both use the order Serve, Return, Forehand, Backhand, Volley, Power,
  Speed, Stamina. The Profile values are written by the DefaultAttributes graph (G4b, V; full chain in
  `stats-coaches-career.md` s1).
* `S+0x640` is the skill list (`{id, value}` pairs). The first four entries with value 1.0 become Skill1..4 (`fn_8869DEF0`).
* **Writer (G4c, V):** `fn_886B4700` copies both from the player record at match setup (int -> float for the
  ratings, Value 1.0 for Skill1..4), then runs DefaultAttributes. Full chain in s10.1.
* The external record (`fn_887AC0E0`) has 14 ints: Serve, Return, Reflex, Forehand, Backhand, Volley, Power, Speed,
  Stamina, Mental, Overall, Skill1..4. Reflex and Mental have no in-match float. They act only through the data (U).

### 2.2 Rating -> Profile -> mechanic (V wiring, I roles)
* Graph `DefaultAttributes` (`0x8C9B26E0`) and its twin `0x075A2137` each have one CURVE per rating, with inputs at
  `Profile.<3B91D48C>` cells 40..47.
* The shipped curves map ratings of 30..100 to Profile values of 0..1. Keys are in `player.yaml: graphs`, and
  samples are in `player.yaml: profile_from_rating`.
* **Curves are ramps (V, G1 `graphs-decoded.md` s1).** The load-time fixup `fn_8890DFC8 -> fn_88179740` sets
  slope = (y1 - y0) / (x1 - x0). `pl_curve20` defaults to `PL_CURVE_RAMP`; `PL_CURVE_STEP` keeps the stored slope
  0 for comparison. `player_data.py --curve-mode step` does the same for the YAML.
* Profile consumers (`analyser-graphs.md` s6):

  | Profile cell | Read by | Effect (I) |
  |---|---|---|
  | 20 (stamina) | `FatigueIngame`, `FatigueConst` | fatigue gain and constants |
  | 29 (speed) | `RushSpeedCoef`, `SwingSpeedCoef` | movement and swing animation speed scale (`AnimationSelection.Movement` cell 202, `.SwingSelection` cell 201) |
  | 37 (volley) | `VolleyTimingAbility`, the volley zones | volley timing |
  | 18, 26, 49 | 31, 50 and 27 graphs | the widely used Profile values: InputFiltering, IsTired, ReturnServeZone ... |

* **Cells 40..47 (V, G4b via G1's bindings):** 40 Backhand, 41 Stamina, 42 Forehand, 43 Speed, 44 Power, 45 Volley,
  46 Return, 47 Serve. Each feeds the curve for the Profile value of the same stat. This agrees with the earlier
  consumer inference 41 -> stamina, 43 -> speed, 45 -> volley.
* **Per-stroke skill** `S+0x74C` is set on swing-state entry (`fn_88699300`). It takes Return for a return, Forehand or
  Backhand by `(handedness==Left) != S+0xBD1`, Forehand in states 0xA/0xB, and Volley in states 0xC/0x10. The serve path
  stores Serve (`fn_886BCE88`), then runs the analyser at `controller+0x504` (V). `pl_stroke_skill`.
* **Side preference** `fn_8865B3B0`: the stronger side is preferred until its use share passes a threshold.
  `pl_side_preference` (I for the return values).
* Coach skills, levels and XP are career data (CoachList, PlayerEvolution; `stats-coaches-career.md`). No match code
  reads a coach table. Coaches act only through the ratings and the skill list `S+0x640`. 28 skills are read by graph
  link ports `Profile.SkillList[Id].Value`, and 3 are tested in code. Every skill with its magnitude is in
  `traits-and-skills.md`.

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
  **The delay float (G4b, V):** `(ctx+0x50)+0x28` is `brain+0x28`, the State AI record (type `0xD7C700B9`, 0x274
  bytes, `fn_886B69F8`). `+0x1DC` is `FinalPositioningComponents.#79b99b60`, in ticks. It is written by the
  positioning graphs of the AI level list `+0x30` (graph indices 141-150 and 155). Example, graph 141:
  `lerp(curve(vigor) 15 -> 5, curve(vigor) 10 -> 0, Profile.Speed) × position factors`, so fast, fresh players react
  sooner. Graph 147 is a constant 5; graph 148 ranges 0..60.
* State 1 enter runs the `brain+0x1E0` graph. For a **human** this is InputFiltering, which writes the window
  `S+0xDF4/0xDF8`. For the **AI** the slot holds the level record's `+0x44` graph (AimingState.FinalEfficiency), not a
  reaction graph (G4b, V: `fn_886B6F2C` vs `fn_886BDB58`).
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

### 4.3 Selection and the clip-fit cost `fn_886D3AD8` (G4b decode; V structure, I where marked)
* The query lists in the AnimationData root (`+0x94` for reach, `+0xA0` for normal) restrict the candidates by record id.
* `fn_886D3AD8` (`0x886D3AD8..0x886D48C4`, VMX128; disassembled with ppcdis because capstone stops at VMX128
  words) loops over the candidate clips. `fn_886D4978` is a helper after it. Per candidate (`r29` = clip record):
  1. **Sample time.** `t_s = t0 + (f21 / len) * f19`. Here `t0` (`f27`) is the candidate start time and the ratio is
     the warped EventRacket phase (time warp `fn_886D1408`, s4.4). Root motion is sampled at `t_s` by
     `fn_88644CE8` (`0x886D42A4`).
  2. **Root offset.** `m = (dx, dy * AnimIface(+0x3CC)+0x55C, dz) * scale` (`vmulfp128 v127` at `0x886D4308`; the
     scale is the splatted word at `[+0x20]+r20`). When the clip's mirror/side id equals the wanted one
     (`r30 == r25`), `m` is rotated in x/z by the facing angle `[+0x70]+0x48`: `fn_881BD4B8` returns sin/cos,
     then `x' = x c - z s`, `z' = x s + z c`.
  3. **Optional second offset.** When the clip has a linked offset entry (`r28 != -1`), an entry is taken from table
     `(+0x10)+0x74 -> +0x90`, indexed by `(+0x28C) + r28`. It is scaled and rotated the same way (second
     `fn_881BD4B8`, `0x886D43FC`) and added: `m += o` (`0x886D4440`).
  4. **Contact position.** `p = m + base`. `base` (`v125`) is the player's current position, loaded at `0x886D3FE8`.
  5. **Error.** `e = p - (target - ref)`. `target` = `AnimIface+0x3C0` (via planner `+0x150`); `ref` =
     `[AnimIface+0x564]`. The cost is `c = |e|^2`, a 3-D squared distance (`vmsum3fp128` at `0x886D44A4`).
  6. **Time gate.** `t_c = frame + 10 + (t_end - t0 - t_s) * f29`. The candidate passes only if
     `+0x3D0 <= t_c <= +0x3D4` (sign-bit tests at `0x886D44B4..0x886D44E8`). `+0x3D0/+0x3D4` are the earliest and
     latest contact frames.
  7. **Position gate.** `|e.x| < tol_x` and `|e.z| < tol_z`, with tol = `+0x3D8` / `+0x3DC`. Without a linked offset
     (`r28 == -1`) both tolerances are first reshaped from the root-motion length `|m|` (sqrt by `vrsqrtefp128` with
     one Newton step). That reshaping is a chain of `fsel` clamps on `|m| - f24`, `f26`, `f23`, `f22` and `f25`, all
     caller constants (I: the tolerance grows with clip travel, capped at the base tolerance).
  8. **Best.** If both gates pass:
     * when `+0x3E0` is set, the contact position `p + ref` is written out (`stvewx128`, `0x886D46C4..CC`);
     * if `c` is below the best so far (`planner+0x170`, initialised to `pool+0x50`), the planner stores
       `+0x170 = c`, `+0x168 = clip`, `+0x16C = r14` (variant), `+0x174 = f18`, `+0x178 = t0`;
     * the contact frame `(int)t_c + (+0x3FC)` goes to `(+0x14)+0x464`. That is the planned frame that s4.4
       time-scales the clip to (`0x886D4700..0x886D4738`).
* So the **cost is purely positional**: the squared distance between where the clip's root motion puts the racket
  contact and where the ball will be, subject to a contact-frame window and per-axis tolerances. Ratings and skills do
  not enter this cost. They enter earlier, through the candidate lists, and later, through the time scale (I).
* `swinganimation.bin` (85FF436E) has seven criteria: Timing, Power, Control, MoveToNet, PositionOnCourt, SwingEffect
  and SwingType. They are the likely axes that map onto the name-grammar slots, as below. The weights are dumped raw
  in `player.yaml: swing_animation`. **No reader of the file was traced, so the field roles stay U.** The criteria
  do not appear in `fn_886D3AD8`.

  | criterion | name-grammar slot (I) |
  |---|---|
  | Power | Tier |
  | Timing, PositionOnCourt | Position |
  | Control | Control |
  | MoveToNet | Movement |

* `SwingSpeedCoef` (Profile speed, fatigue, LocalPosition) writes the swing animation speed cell 201 (I: playback scale).

### 4.4 Time scaling (V formulas from gp7 s4/s5; C in `player.c`)
* `pl_time_warp`: `clamp((t - t0)(ratio - 1) + base, base, end)` (`fn_886D1408`).
* `pl_anim_busy`: `max(0, (seg1 - t0)(ratio - 1) + base - now)` (`fn_886CD3C8`). This busy time feeds reach and validity.
* `pl_rate_to_target`: `(event - clip_now) / (target - now + 1)`, otherwise `rate *= decay` (`fn_886C72E0`). The contact is
  hit by **time-scaling the clip** so its EventRacket lands on the planned frame `AnimIface+0x464`.

## 5. AI (opponent) differences
* Same pipeline, with the human flag `ctx+0x10 = (info+0x18 == crc32("Human"))`. See movement-and-ai B.1 for the five
  code differences.
* The AI level record (Settings type `0x59CCA053`, 0x5C bytes, 9 styles × 6 levels at cfg+0xF0) supplies
  * five weighted component lists (shot, return, serve, repositioning, positioning),
  * six graphs: timing `+0x40`, aiming efficiency `+0x44` -> brain +0x1E0, hit-point scores `+0x48/+0x4C` ->
    brain +0x158/+0x19C, evaluation `+0x50` -> +0x224, swing reaction time `+0x54` -> +0x268,
  * the run-speed limit `+0x58` that replaces `PT+0x230` (4..10 m/s by level).

  Layout, element format and per-style values: `stats-coaches-career.md` s5 (G4b, V).
* Style groups (G4b): AIStyle_BaselineAttacker, AIStyle_ServeAndVolley and AIStyle_AllRounder are crc32-verified.
  `824ec12e` (baseline controllers), `75c6d60c` (generic default) and the four Ralley groups are named by the pros
  that use them (I).
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
Resolved by G4b: the reaction float and rating writers (s2.1, s3.3), the AI record lists, graphs and style names
(s5, `stats-coaches-career.md`), the clip-fit cost (s4.3), coach and career tables, and the order of cells 40..47.
The curve question is settled: ramps (G1).

Resolved by G4c (s10): the match-setup writer of S+0x620 / S+0x640 (code, not data), the PlayStyle keys, the
member chain of the whole PlayerTuning block (so every PT offset has a structural name), the readers of
PT+0x35C/0x36C and of the InPositioning floats, the clip-fit tolerance constants, the Highly flammable threshold.

Still open:
1. The caller of PlayerController vtable slot 21 (`fn_886B4B80`). It is an indirect call; no static
   `lwz rX,0x54(vtbl); bctrl` site in the gameplay range resolves to it (I: match start / reset).
2. How a created player becomes a 0x104-byte row in a `GameDB.PlayerList` mount, and whether coach and level
   bonuses are already added into its AttributeList ints at that point (career Lua, I).
3. Names of AI style groups `824ec12e` and `75c6d60c` and of `PositioningComponents.#79b99b60`. A two-token
   search over the 3,018-token vocabulary of `work/disc/values/names.json`, with prefixes `AIStyle_`, `Style_`,
   `AI_`, `AIProfile_`, `PlayStyle_`, found nothing. `824ec12e` is also a float **member** of the AI record's
   Style struct (AI record +0x188), next to `529c7951` = AIStyle_BaselineController.
4. Readers of PT+0x31C/0x32C/0x33C/0x37C (the other four 0x10-byte speed/Angle records) and of the
   PT+0x450..0x5D3 blocks (Acting, three style records, shot qualifier tables) are not confirmed: the static scan
   only follows `lwz rX,0x2C(ctx)` bases (s10.3).
5. The counter behind Flammable: `((world+0x50)+0x4C)[team].+0x30`, 0x40-byte team records of an engine object
   (I: points won in a row). Its incrementer is not traced.

## 10. Match setup, PlayerTuning layout and skill gates (agent G4c)

Sources as in the header, plus `Layoutall.bin` sha256 `67793f5b...88c5` (reflection table) and
`BackstageRequests.bin` (Core `19ce55a5`, 1,053,532 bytes). Disassembly: capstone 5.0.7 over the PE image;
VMX128 functions with `tools/ppcdis` (`work/ppcdis/target/release/ppcdis`). `player.yaml` gains
`player_tuning.layout` (one row per member of the block, with the shipped value) and `match_setup`.

```
python3 -I tools/ts4data/player_data.py --core work/disc/core_all --layout work/disc/root/Layoutall.bin
```

### 10.1 From a player record to the in-match floats (V)

The raw ratings and skills are **copied by code**, not by an XData request or a Lua script. No backstage request
writes `GamePlayState:/SwingData/State/PlayerStates/.../Profile` (V: all 1,718 request paths of
`BackstageRequests.bin` decoded; only 6 touch GamePlayState, none Profile), and no C++ site issues a request
key except one (`eb189e45`, unrelated). Chain:

1. **Menus / career Lua** fill `GameDB:/GameDB/MatchSettings/PlayerList` (type 46467307). Each 0x20-byte row is
   `{+0x0 6d237251 (f32), +0x4 {Difficulty, 5a0650d7}, +0xC PlayerIndex, +0x10 PlayerId, +0x14 OutfitIndex,
   +0x18 Type, +0x1C PadIndex}` (Lua `MatchSettingsLib.lua`: `AttrPlayerId`, `AttrAILevel`, `PadIndex`). The
   menu side writes PlayerId through `fn_8884E988` (`GameDB:/GameDB/MatchSettings/PlayerList`).
2. **`fn_886B4B80`** (PlayerController vtable 0x880F4308, slot 21 = +0x54; the vtable also holds Init
   `fn_886BE1C8` at slot 18 and Skill1..4 `fn_8869DEF0` at slot 22):
   * scans `(world+0x40)+0x44` (the MatchSettings PlayerList, `world = ctx+0x48`) for the row whose PlayerIndex
     equals `ctx+0x14`;
   * stores the row at **`ctx+0x7C`**. This is G4's "player info": `+0x4` AI level key, `+0x8` AI style key,
     `+0x18` Type (`Human`);
   * calls `fn_886B4700(ctx, row.PlayerId)`.
3. **`fn_8867AB78(ctx, id)`** finds the player record: `(world+0x38)` is the GameDB root (type f895ecb1),
   `+0x13C0` its `PlayerList` **mount point** (CXBinMountPoint, 0x40 bytes). For each mounted file (`+0x13C4`
   array, `+0x13C8` count) it takes the root list (vtbl+0x48) of 0x104-byte `Player` rows (type cd5f7823, the
   `PlayerList.bin` layout) and returns the row with `Id` (+0xE0) == id.
4. **`fn_886B4700(ctx, id)`** (0x47C bytes) writes the PlayerState through `ctx+0x28` (= &S.Profile, S+0x5F0;
   set in Init at `0x886BE4D8`):

   | Source (record) | Destination | How |
   |---|---|---|
   | AttributeList Serve +0x80 | S+0x620 | int -> float (`fcfid; frsp`) |
   | Return +0x84 | S+0x624 | same |
   | Reflex +0x88 | — | **not copied** |
   | Forehand +0x8C, Backhand +0x90 | S+0x628, S+0x62C | |
   | Volley +0x94, Power +0x98, Speed +0x9C, Stamina +0xA0 | S+0x630..0x63C | |
   | Mental +0xA4, Overall +0xA8 | — | not copied |
   | Skill1..4 +0xAC..0xB8 | S+0x640 SkillList | unless `(world+0x28)+0xAB`: every Value = 0.0, then 1.0 where Id is one of the four |
   | MainInfo.Plays +0x24 | S+0x5FC Handed | `Right` if Plays == 0xC4A6567B, else `Left` |
   | PlayStyle list +0xC8 `{Type, Value}` | S+0x600..0x620, S+0x314/0x338/0x33C/0x364 | table below |

   Then it loads and runs, once, every analyser named in **PT+0x63C** (Settings `#8b92df82.Expr[]`):
   `DefaultAttributes` (`8c9b26e0`, raw -> Profile 0..1, S+0x64C..0x668) and `dc1d59b1` (two derived values in
   the S+0x5F0 list: `lerp(Serve, Forehand, 0.4)` and `lerp(Serve, Power, 0.4)`, ids `592dc8d8` / `32c0be7a`).
   The graph `075a2137` is not in the shipped list.
5. In match, `S+0x74C` (per-stroke skill) and the ~100 Profile consumers read the results (s2.2).

PlayStyle keys (V: crc32 of the names; values via `fn_8866DC18`, which maps `None` to `Default`):

| Type key | crc | Destination |
|---|---|---|
| BackhandStyle | `062bd4a5` | S+0x600 (template name BHType; TwoHanded / OneHanded); also `AnimationSelection.SwingSelection.BHType` S+0x364 = `d4ad8f2c` if TwoHanded else `ff82dcef` |
| BackhandProStyle | `35ae9195` | S+0x604 |
| ForehandProStyle | `0db714cd` | S+0x608 |
| ReturnServeProStyle | `04a9f2b5` | S+0x60C and `AnimationSelection.ReturnServe.ProStyle` S+0x33C |
| ServeProStyle | `a305331b` | S+0x610 and `AnimationSelection.Serve.ProStyle` S+0x338 |
| AttitudeProStyle | `1fc4b4fa` | S+0x614; S+0x618 = (value == `83324b2f`) |
| BehaviourStyle | `130c33da` | S+0x61C |
| SignatureStyle | `3d952275` | `AnimationSelection.EndOfPoint.ProStyle` S+0x314 |

So the swinganimation selection procedures `a305331b` / `04a9f2b5` (G6, `movement-and-animation.md` s3) are
ServeProStyle / ReturnServeProStyle, fed from the player record here. `match_setup` in `player.yaml` and
`pl_profile_from_record`, `pl_handed_from_plays` in `ref/gameplay/player.c` hold the same facts.

### 10.2 PlayerTuning member chain (V structure, from Layoutall)

`cfg+0x180` is member `c4eba473` of the Settings root, type `94729773`, **0x760 bytes** (the old dump stopped at
0x660). Every row with its shipped value is in `player.yaml: player_tuning.layout`. Main blocks (unnamed
members keep their hash):

| PT offset | Member (type) | Content and role |
|---|---|---|
| +0x000 | `0c910649` {`8715c61c`, `376a5ab5`} | two `{MainPosition, 776d814a}` vector pairs: (-1260, -150) / (-500, 350), (-1300, -350) / (-600, 220) |
| +0x040 | `f164ef8e` (same type) | (-1250, -150) / (-1200, 180), (-1400, -350) / (-1300, 180). I: ready/serve anchor sets |
| +0x080 | `e5b4838f` {curve, 150, 300} | |
| +0x0A0 | `2906f362.62963458` | four per-stroke-level `Step` lists (racket offsets), vector (1650, 750), the six height bands +0xE0..0xF4, five floats 40/30/70/60/60 |
| +0x110 | `2906f362.e3f648f3` | five ints 65/35/50/5/8 and floats 300/200/250 (readers U) |
| +0x130 | `9c82ebf2` | two 2-D tables (50..400 -> 45/30; 0..500 -> 15..30) and int 5 |
| +0x14C | `0885625c` | side-select curve, 150, two bools (read at `fn_8869AB70`) |
| +0x160 | `a2dd221a` | look-ahead curve, cap curve, in-zone limit 750 |
| +0x17C | `2a3b1f8a` | turn table, curve, nine floats (radii, preparation ticks), bool |
| +0x1BC | `InputNotation` | four curves and a 2-D table |
| +0x1F8 | `6b347916` | **movement-type records** `InsideOut`, `Steps`, `Jog`, `Rush`, `7e03dae6`, `1a6f1fe2`, each `{Definition: 5 bools, Reachability: {MaxSpeed, a6499cc6}}`. G4's "style records" are these: InsideOut 3 / -1, Steps 3 / 4.25, Jog 6 / 4.75, **Rush 10 / 7** (MaxSpeed replaced by the AI skill float), 3 / 4, 2.5 / 3.5. Then ints 60/40/10/10, floats 300/200 |
| +0x270 | `bc68b415.2f011a4a` | the three regime records `{Angle{table2d, 6}, min distance}`: 400 / 2000 / 175 cm (Rush, JogJogPrepared, JogPrepared) |
| +0x2AC | `bc68b415.43e5dcbd` | zones `InsideOut`, `Steps`, `1c640b43`, `c8b24fcd`, `a45fcb53`, `637ca2f2`, `Jog`, `Smash` + 3 floats + bool. G4's swing-ready / approach / regime / alt zones are InsideOut / Steps / Jog / Smash |
| +0x31C | `bc68b415.46a36509` | seven `{Angle{table2d}, 6.0}` speed-override records at +0x31C, 32C, 33C, 34C, 35C, 36C, 37C (s10.3) |
| +0x38C | `d1e0199b` {`Rush`, `Jog`, `JogPrepared`} | one curve each: 8 / 20->10 / 20->10 |
| +0x3B0 | `dd446c94` | jog-ramp step table, **`InPositioning`** twelve floats +0x3BC..0x3E8, `TimeStep` 10 (= jog ramp period +0x3EC), int 20, 100 cm |
| +0x3F8 | curves `0c3b62d1`, `9e7b1063`, table `e200776d` | read by `fn_8868CB18` (+0x3F8/+0x404) |
| +0x41C | `GiveUp` | two curves (600 -> 0: 100 -> 0; 300: 200 -> 50), 40, 10, -10 |
| +0x440 | `df5bba30` | 10 |
| +0x450 | `Acting` | three floats, three ints |
| +0x468 | `2ec3852d` {`3ab062ca`, `NormalStyle`, `cab90af1`} | three 3x3 float records (`fn_88697BF8` reads +0x464/+0x488/+0x4AC, I) |
| +0x4D4 | `3b698329` | one float (read at `0x886BB174`) |
| +0x4D8 | `59f72580` {`Normal`, `baeb910f`, `3b574c5b`} | per shot class (FlatPower, FlatFinesse, Slice, VolleyStandard, VolleyPower, Smash) `QualifierValue` lists; list +0x5B0 (6 keys); floats 0.1 / -1 / 0.1 / -0.3 / 0.2 / -0.5 |
| +0x5D4 | `0b337596` {`Baseline`, `Volley`, `Serve`} | two curves 10..40 -> 1..-1 and 50 each; Serve.`Animation` list (Default, Swing_Serve_Style02, ...) |
| +0x618 | `Fatigue` | Qualifier list (Effort Low ...), 1 / 2 / 3, **+0x630 `a9957a1c` = -1** (the Rush guard of s3.4) |
| +0x634 | `f2300ac2` | 100, 115 |
| +0x63C | `8b92df82` | the Profile graph list (s10.1) |
| +0x648 | `19543b5d` {`Service`, `Rally`} | 300/300, 400/600 |
| +0x658.. | step lists, ranges, `AutoSwing` six ints, `AI` int, two `{TopLeft, BottomRight}` boxes +0x700/+0x720, ints and floats to +0x75C | +0x6A4..0x6BC are the crowd tables of s1 item 10 |

### 10.3 Readers confirmed in this pass (V)

* **InPositioning floats.** The reach fit (state 19, `fn_886A26E0`) writes AnimIface `+0x3D8 = PT+0x3DC` (60),
  `+0x3DC = PT+0x3E0` (60), `+0x3D0 = dt - (S+0xBD2 ? PT+0x3C4 : PT+0x3CC)`, `+0x3D4 = dt - (S+0xBD2 ? PT+0x3C8 :
  PT+0x3D0)` with `dt = sample tick - clock`. The **Miss** fit (`fn_886A58F0`) writes `+0x3D8 = PT+0x3E4` (60),
  `+0x3DC = PT+0x3E8` (80), `+0x3D0 = PT+0x3D8 + dt` (15), `+0x3D4 = PT+0x3D4 + dt` (-5). So the contact window is
  `[dt - 20, dt]` (`[dt - 30, dt]` alt) for a reach and `[dt - 5, dt + 15]` for a miss: **+0x3D0 is the late and
  +0x3D4 the early bound** (I, from the shipped values: the s4.3 wording "+0x3D0 <= t_c <= +0x3D4" should be read
  with the two names swapped).
* **PT+0x35C / PT+0x36C.** `fn_88699300` (swing-state entry, the two alt branches that set S+0xBD2 = 1) calls
  `fn_88698B28(P, PT+0x35C, PT+0x1AC)` at `0x88699884` and `fn_88698B28(P, PT+0x36C, busy + PT+0x1AC)` at
  `0x88699920`. `fn_88698B28` evaluates `fn_886887C0` once per plan (`P+0x13C`), publishes the value to the speed
  override S+0xDE8 (`S+0xDEC = 1`) and re-arms the jog ramp (`P+0x140..0x150`). Shipped: 1 -> 0 (+0x35C) and
  1 -> 0.5 (+0x36C) across a 40-tick slack band that moves from 61..101 at 200 cm to 136..176 at 800 cm.
* **Clip-fit tolerance constants** (`fn_886D3AD8`, no linked offset): not caller arguments but float-pool words
  at `0x880D0F70` + 0x15C (60), +0x404 (40), +0x470 (450), +0x710 (1/450) and `0x880C8FD0` (150). For each axis:
  `tol' = 60 + 40 * clamp(|m| - 150, 0, 450) / 450` (60..100 cm), then a compare-select against the base tolerance
  `+0x3D8` / `+0x3DC` (I: the larger wins). The best-cost seed is FLT_MAX (pool +0x50). `pl_fit_tolerance_from_travel`.
* **swinganimation.bin reader.** `fn_886E57A8` (SwingAnimationEngine Init) resolves the `AnimationData:` node,
  takes the typed view `fn_88923530(..., 0x3A60FEE2)` (engine+0x48 = root), stores root+0x1E8 (`States`) at
  engine+0x4C and root+0x22 at +0x140, and hands root+0x1D0 (`Projects`) to `fn_886D2A08`, root+0x1DC to
  `fn_886E5670` and the root to `fn_886E3A00`. Code strings name the tree `AnimationData:/SwingAnimation/...`
  (`PlannerParameters/@ScaleActivated`, `States/InstanceState[n]/UpdateSetupCommand/@LeftHanded`). Field roles of
  the selection data are G6's (`movement-and-animation.md` s1.3, s4).

### 10.4 Skill gates (V)

* **Highly flammable.** `fn_886BDCC0` (PlayerController slot 23, point start) at `0x886BE0BC`:
  `S+0xF94 = (((world+0x50)+0x4C)[team].+0x30 >= 4) ? 1.0 : 0.0`. The **4 is a code constant**
  (`cmpwi r4, 4`), not data. The member at S+0xF94 is `MatchAnalyser.Flammable` (crc `08950daa`). The same
  function sets S+0xF98 (`7f50fe07`) = `((world+0x50)+0x3C)[team] > 0` and clears the slice / topspin counters
  S+0xF8C / S+0xF90 (SliceInvasion / TopSpinInvasion), which `fn_886B0490` increments.
* **MatchAnalyser writers** (S+0xF80..0xF98, type b6ca3263): `b6b22409` S+0xF80 cleared for all players in
  `fn_88674BC8`; `689dc6f2` S+0xF88 set to 1.0 / 0.0 per team from a score comparison in `fn_88674E00` (I: the
  trailing team gets 1.0); `ace1253a` S+0xF84 cleared there and incremented in `fn_88697890`. No analyser graph
  writes any MatchAnalyser member (V, scan of all graph outputs). `MatchState.8beb922e` (+0x334, Longer, better!)
  is incremented in `fn_886B5128` (shot apply). `pl_flammable`.
* Other skill magnitudes stay in data (graphs, `traits-and-skills.md` s3).
