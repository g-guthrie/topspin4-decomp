# Ratings, coaches, career progression and AI difficulty tables (agent G4b)

This note covers the data chain from a player's ratings, level and coach to the in-match values. It
also covers the coach and career tables and the AI difficulty records. Skill effects are in
[`traits-and-skills.md`](traits-and-skills.md). The movement planner and clip fit are in
[`player-and-movement.md`](player-and-movement.md).

Evidence grades: **V** verified in code or data, **I** inferred, **U** unknown.

Values:

* [`data/gameplay/coaches_career.yaml`](../../data/gameplay/coaches_career.yaml): coaches, objectives,
  hire conditions, PlayerEvolution, AI difficulty table and the 731 pros.
* [`data/gameplay/player.yaml`](../../data/gameplay/player.yaml) `profile_from_rating`: rating ->
  Profile samples, ramp reading.

Both are produced by stdlib scripts:

```
python3 -I tools/ts4data/career_data.py --core work/disc/core_all --global work/disc/global \
    --venue work/disc/venue_amst --layout work/disc/root/Layoutall.bin \
    --dll orig/54540859/Swing_DLL.dll --out-dir data/gameplay
python3 -I tools/ts4data/player_data.py --core work/disc/core_all          # --curve-mode step for the old reading
```

Source sha256 values are in the YAML headers and in `traits-and-skills.md`. Extra source for
`player.yaml`: AnimationsDB.bin `3a3a98cf71d1c82479bd5842ac596a599d5e90fa12c22e69e8c65f64aaf7a3dc`.

## 1. Rating chain (V unless marked)

```
PlayerList.bin AttributeList (ints 0..100)       CoachList _AttributeBonus / PlayerEvolution level gains
        |   Serve Return Reflex Forehand Backhand Volley Power Speed Stamina Mental Overall Skill1..4
        v                                       (career Lua: GiveAttributeSpecialBonus, ValidateAttributes)
PlayerState S (State.bin type 0x25FCD125, 0x1070 bytes)
   S+0x620..0x63C  Profile.#3b91d48c  raw ratings (8 floats): Serve, Return, Forehand, Backhand, Volley, Power, Speed, Stamina
   S+0x640         Profile.SkillList  {Id, Value} pairs, Value 1.0 = owned (30 skills)
        |  graph DefaultAttributes (0x8C9B26E0) or its sibling 0x075A2137, selected by
        |  Settings "PlayerSettings.#8b92df82.Expr[].Id"; one CURVE per stat; input cells 40..47
        v
   S+0x64C..0x668  Profile outputs 0..1, same stat order, read by ~100 graphs
   S+0x74C         per-stroke skill copied from these at swing-state entry (fn_88699300)
```

* **Input cells 40..47 (V, via G1's State bindings):** 40 Backhand, 41 Stamina, 42 Forehand,
  43 Speed, 44 Power, 45 Volley, 46 Return, 47 Serve. Each feeds one curve whose output is the
  Profile value of the same stat.
* **Curves are ramps (V, G1 commit 20f5526).** `profile_from_rating` gives the samples. DefaultAttributes:

  | stat | 30 | 40 | 50 | 60 | 70 | 80 | 90 | 100 |
  |---|---|---|---|---|---|---|---|---|
  | Serve, Volley, Speed, Stamina | 0 | 0.10 | 0.20 | 0.40 | 0.60 | 0.80 | 0.90 | 1 |
  | Power | 0 | 0.15 | 0.30 | 0.40 | 0.50 | 0.65 | 0.833 | 1 |
  | Forehand, Backhand | 0 | 0.10 | 0.20 | 0.30 | 0.525 | 0.75 | 0.875 | 1 |
  | Return | 0 | 0.15 | 0.30 | 0.467 | 0.633 | 0.80 | 0.90 | 1 |

  The sibling `0x075A2137` is flatter below 60 and steeper above. Its values are in the YAML.
* **Reflex and Mental** have no in-match float. In PlayerList, Return always equals Reflex, so
  "Return" in State is the Reflex rating (I). Mental is 30 for every pro.
* **Writer of S+0x620/0x640.** No literal code store was found. The copy from the player record runs
  through data-driven backstage requests (`BackstageRequests.bin`, whose paths are offline) (I). G4's
  external record reader `fn_887AC0E0` (14 ints) is the closest code.

## 2. Pros (PlayerList.bin, Core `de208ac7`)

731 entries (plus a DLC placeholder). Each has the 11 ratings above, Skill1..4 and two style fields:

| ProfileAI (AI style group) | PlayStyleAI | count |
|---|---|---|
| AIStyle_AllRounder | AllAround | 576 |
| AIStyle_BaselineAttacker | BaselineAttacker | 53 |
| `824ec12e` | BaselineController | 46 |
| AIStyle_ServeAndVolley | VolleyFinessePlayer | 36 |
| `824ec12e` | None | 16 |
| `ad2283af` / `1182486a` / `0a8ac661` / `d858c9fb` | AllAround | 1 each (players Ralley1..4) |

Every entry also has `a017b472 = 75c6d60c`, which is the ninth style group of the AI table (I: generic default).

## 3. Coaches (CoachList.bin, Global `a02aba6e`)

* **110 coaches.** Level 1/2/3 = bronze/silver/gold (V, UI text): 20 / 37 / 53.
* Each coach has a name (`crc32("Coach<code>Name")`), playstyle flags (Defensive, Offensive, Serve),
  4 objectives, hire conditions and an ability list.
* **Abilities**, each with `unlock_step` = `Ability.Efficiency` 0..4:
  * the number of objectives completed before the ability becomes active (V via UI text "The more
    objectives you complete, the more skills your coach will grant you");
  * distribution: step 0 on 100 abilities, step 4 on 110 (every coach has one), steps 1/2/3 on
    47/83/100.

  | kind | count | values |
  |---|---|---|
  | `_AttributeBonus` | 227 | per-attribute points. Coach totals: bronze 20..25, silver 25..35, gold 35..50. Single-attribute maximum 15 / 13 / 15 |
  | skill | bronze 0, silver 1, gold 2 per coach | unlocked at steps 2..4 |
  | GeneralXPBonus | 20 | +10 % post-match XP |
  | GeneralMaxiXPBonus | 24 | +20 % post-match XP |
  | BaselineXPBonus | 17 | +3 XP per baseline winner |
  | VolleyXPBonus | 9 | +5 XP per net winner |

* **Objectives:** 35 counters, for example GoodTimingShotCount (27 coaches), MatchesWon,
  Slice/TopSpinShotCount, NetWinnerCount, ShortPHShotCount (press-and-hold) and CloseToLineBallCount.
  The goal values are in the YAML.
* **Hire conditions** are `Pam::System::Conditions` tests (LesserThan / GreaterThan on an integer).
  The reason keys are `9fd4f7b8` and `cc60516b`. `9fd4f7b8` is also a PlayerEvolution scalar
  (= 20), so the tests most likely compare per-style level counts (I).
* **Career natives** (Lua 5.0 `*Lib.bin` call these thunks):

  | native | thunk | implementation | role |
  |---|---|---|---|
  | UpdateActiveCoachSkills | `0x88853790` | `fn_88852CB0` | iterates coach records (stride 0x38) and their conditions (`fn_886328B0`), then sets the SkillList Values |
  | GiveAttributeSpecialBonus | `0x88853850` | `fn_888532F8` | applies attribute bonuses |
  | ValidateAttributes | `0x888537E0` | | |
  | HireCoach | `0x8884F2D0` | | |

  The XP bonus code is at `0x8884EF1C` and `0x888549DC`.
* **No match code reads CoachList (V).** Coaches act in a match only through the ratings and the
  SkillList.

## 4. Level progression (PlayerEvolution.bin, venue `e38f72f1`)

* Three packs: VolleyFinessePlayer (S&V), BaselineAttacker (offensive) and BaselineController
  (defensive). Each pack has 20 levels with a per-level gain for 8 attributes (Forehand, Backhand,
  Serve, Volley, Power, Stamina, Speed, Reflex).
* Totals over the 20 levels, as stored under the layout's member names:

  | pack | FH | BH | Serve | Volley | Power | Stamina | Speed | Reflex |
  |---|---|---|---|---|---|---|---|---|
  | VolleyFinessePlayer | 10 | 10 | 55 | 55 | 10 | 15 | 30 | 55 |
  | BaselineAttacker | 25 | 25 | 55 | 10 | 55 | 40 | 10 | 20 |
  | BaselineController | 35 | 35 | 10 | 10 | 20 | 55 | 55 | 20 |

* Scalars:
  * level thresholds `LevelValue` 4 / 9 / 14 / 19 (I: rank steps);
  * `5a1d77f7` = 5;
  * `9fd4f7b8` = 20 and `98645014` = 20 (I: per-track and total level caps).

## 5. AI difficulty table (Settings cfg+0xF0)

9 style groups × 6 levels (VeryEasy, Easy, Normal, Hard, VeryHard, Expert). Each record is Settings
type `0x59CCA053`, 0x5C bytes (V layout, Layoutall):

| offset | member | content | consumer |
|---|---|---|---|
| +0x00 | `f8bde3bf` | list of weighted components -> ShotComponents (Flat, TopSpin, Slice, Lob, DropShot, FollowToNet, PressAndHold, RiskyShot, aim side/length) | AI shot choice |
| +0x0C | `0a7a82d5` | same for the return of serve | |
| +0x18 | `2693de78` | -> ServeComponents (Flat/TopSpin/Slice, ServeStick, Timing, Aiming*, FaultProbability) | AI serve |
| +0x24 | `ef9ce04a` | -> RepositioningComponents (BaseLine, Volley, RushRepositioning, StopMoving, ...) | AI repositioning |
| +0x30 | `0b4e23b3` | -> PositioningComponents (BaseLine, Volley, InsideOut, `#79b99b60`) | AI positioning, reaction delay |
| +0x3C | Id | level key | |
| +0x40 | TimingExpression | graph -> ShotContext.ManualShotTiming | timing object `fn_886B71A0` |
| +0x44 | `7bcf55ee` | graph -> AimingState.FinalEfficiency | AI brain +0x1E0 |
| +0x48 | `714e0b0b` | graph -> `#3237ffac.Score` (hit-point score) | brain +0x158 |
| +0x4C | `39b3b9e2` | graph -> Score (second hit-point score) | brain +0x19C |
| +0x50 | `6b696700` | graph -> EvaluationOutputs.`#4abbb588` | brain +0x224 |
| +0x54 | `98fff83e` | graph -> SwingReactionTime | brain +0x268 |
| +0x58 | `41d66350` | f32 run-speed limit (m/s) replacing PT+0x230 in the AI search (`fn_8869AEF8`) | |

* Each list element is 0x10 bytes (type `ddf0c247`):
  * `+0x0` Expression key: the component;
  * `+0x4` ExpressionComponents graph key;
  * `+0x8` f32 weight;
  * `+0xC` bool Default;
  * `+0xD` bool `ee04af9f`.
* Graph slots are loaded by `fn_886B6F2C` (calls at `0x886B6F70..0x886B701C`) (V). For the human
  brain (`fn_886BDB58`) the same slots hold Volley (+0x158), IsTired (+0x19C), InputFiltering
  (+0x1E0, the reaction window S+0xDF4/0xDF8) and `daf2ecbd` (+0x224). G4's "+0x44 = reaction graph"
  is therefore true only for the human slot.
* Run-speed limit by level:
  * main groups: 4 / 5 / 6 / 8 / 10 / 10 m/s (BaselineAttacker VeryHard 9);
  * Ralley groups: 7 / 7.5 / ... / 10.
* The number of shot components grows with difficulty, for example BaselineAttacker 5, 5, 8, 9, 9, 9.
* **Style group names:**

  | key | name | grade |
  |---|---|---|
  | `c3e11a56` | AIStyle_BaselineAttacker | V crc32 |
  | `8c1c3a3b` | AIStyle_ServeAndVolley | V crc32 |
  | `ea55dbac` | AIStyle_AllRounder | V crc32 |
  | `824ec12e` | baseline controller group | I: the pros with PlayStyleAI BaselineController and None. crc32("AIStyle_BaselineController") = `529c7951` exists only as a Style struct member |
  | `75c6d60c` | generic default group | I: the per-player field `a017b472` of every pro |
  | `ad2283af`, `1182486a`, `0a8ac661`, `d858c9fb` | Ralley1..4 styles | I: ProfileAI of PlayerList players Ralley1..4 |

* **AI record in State** (type `0xD7C700B9`, 0x274 bytes, State root +0xE8C list; `brain+0x28` points
  to it, `fn_886B69F8`):

  | offset | member |
  |---|---|
  | +0x170 | Difficulty |
  | +0x188 | Style (`824ec12e`, `8c1c3a3b`, `529c7951`, `c3e11a56`, `ea55dbac`) |
  | +0x1C0 | SwingReactionTime |
  | +0x1D0 | FinalPositioningComponents {Volley, BaseLine, InsideOut, `#79b99b60` @+0x1DC} |
  | +0x1E0 | FinalRepositioning |
  | +0x1FC | FinalServe |

  +0x1DC is the state-0 reaction delay in ticks (`player-and-movement.md` s3.3).

## 6. Open items

* Names of `824ec12e`, `75c6d60c` and `#79b99b60` (no crc candidate matched).
* The match-setup writer of S+0x620/S+0x640 (data-driven requests, I).
* Hire-condition variables (XPath strings are offline). PlayerEvolution thresholds and caps are I.
* The unnamed component expression keys in the AI lists (for example `bfc9cc2c`, `2836a60f`).
