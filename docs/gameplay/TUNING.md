# Tuning guide: what to edit for each thing a player feels

For each player-felt quantity this lists the data values that control it, their shipped values
(retail disc, `Settings.bin` sha256 `55cb175d...a0167`, `Expressions.bin` sha256
`fd3bc49b...dee9`) and how to change them. The mechanisms are in [GAMEPLAY.md](GAMEPLAY.md).
Values marked "code" are constants in `Swing_DLL.dll`. Data patches cannot change them.

## 0. Workflow

**Settings / State / other XBin files.** Every scalar is a row `[file offset, type, value, path]`
in `data/gameplay/tunables/<File>/NN_<member>.yaml`. Copy the YAML, edit the `value` column only,
then:

```sh
python3 tools/ts4data/patch_tunables.py my/Settings/02_PlayerSettings.yaml \
        --cache work/disc/cache --out work/patched --rebuild        # or --iso IMAGE.iso
python3 tools/ts4_iso_patch.py IMAGE.iso work/patched/game --arc Core.arc=work/patched/Core.arc
```

The tool checks the source sha256, each row's offset, type and path, and the byte diff. Use
`--dry-run` first. For the Title Update state, dump with `tools/ts4data/dump_tunables.py --tu`
(TU1 files replace the disc copies when TU1 is installed; title-update-balance.md).

**Analyser graphs (`Expressions.bin`).** Use `tools/ts4_analyser_patch.py EXPRESSIONS PATCH.json
OUT` with a JSON patch keyed by graph name or hash and node index. Curves are ramps; the game
recomputes each key's slope at load, so **edit `x0`, `x1`, `y0` and the end value, not the stored
slope** (graphs-decoded s2). Find graph and node numbers in `data/gameplay/graphs.yaml` and
`graphs-catalogue.md`. Evaluate before and after with `tools/ts4_shot_error.py` (shot error) or
`tools/ts4_analyser.py`. Only the first copy of a duplicated graph is live (graphs-decoded s5).

Paths below are relative to `data/gameplay/tunables/Settings/` unless noted.

## 1. Shot power and charge

| quantity | value(s) | where | notes |
|---|---|---|---|
| hold time to full charge | 1.25 s (75 frames) | code `g_ts4_script_constants+0x55C` = 1.25; divisor `EngineConfig/@Frequency` = 60 (`GameplayInterface`) | changing the frequency changes the whole clock; do not |
| tier thresholds | Finesse < 0.15, Medium < 0.70, Powerful >= 0.70 (11 / 53 frames) | graphs `Finesse`, `Medium`, `Powerful` (one curve each) | patch the curve's `x0`/`x1` |
| auto-commit lead | 12 frames before contact | `02_PlayerSettings.yaml` `0x8E4 /baaa713d` (PT+0x740) | also the moment the planner runs |
| speed of each row | template curves | `11_ShotPalette.yaml` (37 template rows, `/ShotDef[i]/ShotConfig/...`), readable in `data/gameplay/ball_templates.yaml` | ball-physics s1, s11 |
| shot power curves | 4 lists, x 0..1.25 | `16_a957f922.yaml` (cfg+0x8FC..0x920) | tunables-catalog s3 |
| AI charge | `min(PressAndHold, frames/75)` | AI `ShotComponents.PressAndHold` mix graphs | ai-inputs s5 |

## 2. Timing

| quantity | value(s) | where | notes |
|---|---|---|---|
| perfect release | 20 frames before arrival | `02_PlayerSettings.yaml` `/SwingTimingSelectionList/Baseline/5ae85f27/848c2a13/Range[k]` (0x2B420..) and `.../Volley/...` | shift every `InStart/InStop` to move the sweet spot |
| timing scale | ±0.25 per 5 frames (volley ±0.3) | same rows, `OutStart/OutStop` | larger outputs = harsher |
| timing ability | inert (worst = best) | `.../5ae85f27/BestAbility/Range[k]` | make it differ to let the TimingAbility graphs matter |
| contact reference | 50 cm | `0x790 /SwingTimingSelectionList/Baseline/6d669a99`, `0x7AC .../Volley/6d669a99` | |
| safe window | `|t| < 0.3` | fault graphs' timing curves (graph 292 FlatPower and siblings) | see s3 |
| GoodTiming window | 0.3 .. 0.8 with skill | graph `GoodTiming` | affects the swing rule outputs, not the fault roll |
| serve timing | per-animation curves | `/SwingTimingSelectionList/Serve/Animation[i]/Timing/Range[k]` | controls s9.3 |
| AI timing | per difficulty | `00_AI.yaml` TimingExpression graph key per `Difficulty[]` + that graph | |

## 3. Errors (in / out / net)

| quantity | value(s) | where |
|---|---|---|
| base control | 0.8 | each fault graph's CONST node (graphs-decoded s11.2) |
| late vs early | late about 2x | fault graphs' `easy/hard/easy2/hard2` timing curves |
| forgiveness of small errors | dead zone 0.15 | the `dz` curve (last two curves of each fault graph) |
| stat weight | hand stat halves the penalty | strong- vs weak-hand curve pairs |
| situation penalties | running 300..600 cm at 3..6 m/s to -0.5, full charge -0.15, fast ball -0.6 (input `#1407106c` S+0x770 never written, so inert unless a patch supplies it; OPEN 1.10), fatigue -0.3 | the penalty curves of the control sum |
| per-shot ceiling | `ErrorResolution` Min/Max, **Good row only** (0 / 1 for most shots) | `11_ShotPalette.yaml` `/ShotDef[i]/ShotResolution/ErrorResolution/Good/Min,Max`; the VeryGood/Normal/Bad/VeryBad rows are never selected in retail (OPEN 1.9). Power and aiming scales likewise use `PowerResolution/Good` and `AimingResolution/Good` |
| net vs out | low contact (< 90..100 cm) goes to the net | net graphs' height ramps |
| let chance | 0.02 fading to 0 | graph `LetProbability` |
| net / let aim heights | 80 / 90 cm | `01_ShotResolutionSettings.yaml` cfg+0x134/0x138 |
| out distance past the line | 3 cm | code (`fn_886807C0`) |

`python3 tools/ts4_shot_error.py ... --class FlatPower --set hit_y=90 ...` prints P(error) for a
scenario before and after a patch (graphs-decoded s11.3).

## 4. Aim precision

| quantity | value(s) | where | notes |
|---|---|---|---|
| target quads | 25 configs x 4 zones x 4 quads | `14_b50def25.yaml` `/AimingConfig[i]/<zone>/ZoneInput/QuadList/AimingQuad[q]/Coord[c]` (readable: `data/gameplay/aim_tables.yaml`, `aim_tables.txt`) | q2 = lines, q3 = 3 m out; move q2 inward for safer aim |
| zone blending | VolleyDistance 300, BaselineDistance 1300, SideDistance 350 / 550 | same file, `/AimingConfig[i]/VolleyDistance` etc. | |
| aim efficiency (human) | graph 196 `5c66a7c5` (FinalEfficiency) and each class's aiming graph | Expressions | 1 = reaches the lines |
| aim efficiency (AI) | difficulty graph `7bcf55ee` | `00_AI.yaml` key + graph | |
| depth scatter | DeepDeviation 0..310 cm | each class's aiming graph output | |
| doubles alley | 137 cm | code `g_ts4_script_constants+0x644` | |
| stick dead zone | 0.4 radial | `15_PaddleSettings.yaml` `/Paddle[0]/898866c8/Axe[k]/DeadZone` | |

Regenerate the readable dump after an edit with `python3 tools/ts4data/aim_tables.py --settings
<patched Settings.bin> --out ... --tables ...`; `ref/gameplay/aim.c` reproduces the target.

## 5. Ball speed, spin and bounce

| quantity | where |
|---|---|
| launch speed, flight time, apex, spin per row | `11_ShotPalette.yaml` template rows; meaning per field in ball-physics s1; readable `data/gameplay/ball_templates.yaml` |
| drag | template `T` (0.04..0.0525) over ball `a4` = 0.06 (`State` `MainBallState`) |
| bounce response | template bounce tables `row+0x58..` (ball-physics s6) |
| court bounds and lines | code and ball block (ball-physics s7) |

Surfaces do not change ball physics; a per-surface bounce needs a code hook (surfaces.md).

## 6. Movement and reach

| quantity | value(s) | where |
|---|---|---|
| Rush / Jog choice | validity tables, min distances 400 / 2000 / 175 cm | `02_PlayerSettings.yaml` `/HitPositionSelection/MovePattern/SelectionList/*` (PT+0x270/284/298) |
| run speed limit (human) | 10 m/s | `02_PlayerSettings.yaml` `0x3D4 /HitPositionSelection/6b347916/Rush/Reachability/MaxSpeed` (PT+0x230) |
| run speed limit (AI) | 4, 5, 6, 8, 9..10 m/s by level | `00_AI.yaml` `/AISettings/51b273d0/AIStyle[s]/Difficulty[d]/41d66350` |
| walk vs run override | table PT+0x34C | `02_PlayerSettings.yaml` |
| reach | `ReachBall` 8.0 / 300.0 | `08_DoubleSettings.yaml` |
| no-drift-wide rule | 40 frames, 100 cm off centre (x 1.0), sideways 60-120 deg | `04_RepositioningSettings.yaml` `/29eac4a0/35f11e7b` (0xAA4), `/29eac4a0/d446f64c` (0xAA8); TU1 adds `/29eac4a0/e26ae391` (latched form); angles are code constants (OPEN 6.5) |
| RB fast reposition zone | x > -500 cm, events every 5 frames | `04_RepositioningSettings.yaml` `/RepositioningPointSettings/8154a27b` (0xA98), `/7440a9da` (0xA8C) |
| RB near-net speed scale | 1.15 | graph 37 `VolleySpeedCoef` (CONST; writes S+0x39C, whose State image starts at 1.0) |
| serve position limits | `ServiceConstraint` MinZ 40 / MaxZ 375 cm | `05_MoveConstraintsSettings.yaml` |
| animation speed with vigor | RushSpeedCoef, SwingSpeedCoef graphs | Expressions |

## 7. Fatigue and vigor

| quantity | value(s) | where |
|---|---|---|
| swing effort cost per event | Effort Low 4, Medium 10, High 15, Recover -0.1; inside-out +1 | `02_PlayerSettings.yaml` `/Fatigue/AnimationFeedback/Qualifier[k]/RecoveryValue`, `/InsideOut` (0x2BC30..) |
| between-point rest | 1 (point), 2, 3 (I: game, set) | `/Fatigue/2aa60eef`, `/3cd7e708`, `/a15d9c95` (0x7C8..0x7D0) |
| capacity, recovery rate, VigorMax | graphs FatigueConst, `80ce1a10` (VigorMax = `lerp(lerp(0.5, 0.65, Stamina), 1, ...)`) | Expressions |
| this point's cost from the sums | graph FatigueIngame | Expressions |
| movement threshold | acceleration > 0.02 | code (`g_ts4_script_constants+0x408`) |
| sprint cut-off | vigor >= 0.1 to sprint | code (`fn_8865E430`, `g_ts4_script_constants+0x2AC`) |
| what vigor does | fault graph fatigue term, RushSpeedCoef, SwingSpeedCoef, Vivacity, IsTired, wood graph 280, serve window | the graphs that read CurrentVigor |

`ref/gameplay/fatigue.c` runs the integration for a given cost and capacity.

## 8. Serve

| quantity | value(s) | where |
|---|---|---|
| power tiers | Powerful > 0.8, Medium from 0.1 | serve tier graphs (controls s9) |
| toss wait, auto serve | 30 frames, 480 frames | `03_ServeSettings.yaml` `0x9CC /0e3c35a0`, `0x9D0 /f700452a` (cfg+0x9A8 / +0x9AC) |
| advanced-serve gestures | MinPower 0.9, angles 0 / pi / ±2.14 | `03_ServeSettings.yaml` `/fa763f68/MinPower` and siblings (file 0x980..) |
| fault | serve fault graphs 307-311 (gauge window about -0.4..+0.8) | Expressions; TU1 retunes four of them |

## 9. AI behaviour

| quantity | where |
|---|---|
| stroke mix, aim directions, risk, net rushes, charge | the component mix graphs of each `AIStyle[s]/Difficulty[d]` list in `00_AI.yaml` (ai-inputs s6) |
| timing, aim efficiency, reaction | the six graph keys of each difficulty record (stats-coaches-career s5) |
| ball-speed difficulty factors: Easy 1.0 / Normal 0.8 / Hard 0.6 / VeryHard 0.4 | `00_AI.yaml` `/AISettings/52945bdd/Conditions/BallSpeed/*` |

## 10. Skills and ratings

| quantity | where |
|---|---|
| rating to stat | graph 23 `DefaultAttributes` |
| skill effects | the link ports of the graphs listed per skill in `data/gameplay/traits_skills.yaml`; three skills are code tests (traits-and-skills s2) |
| skill gate constants | `10_SkillSettings.yaml` (30.0, 2.5) |

## 11. Crowd and rewards

Crowd gain step table, cap by shot count and crowd events: `Settings` cfg+0x824 / +0x830 /
+0x83C, inside `PlayerSettings` (`02_PlayerSettings.yaml`; readable in `data/gameplay/crowd.yaml`).
Reward rules and points: gp1 s4 (offsets there use gp1's base; check against the YAML paths
before editing). The excitement events reach the sound code through `fn_8888DD18` (OPEN 6.1).

## 12. Built but not switched on (inferred)

These mechanisms exist in the data or code, but the scans in OPEN.md found nothing that turns
them on in retail. Each entry is **I** until a runtime check (OPEN.md s11) confirms it.

| mechanism | what it would do | why it is off | what enabling it would take |
|---|---|---|---|
| Fast-ball penalty and wood ramp on `#7e28dbc0.#1407106c` (S+0x770) | fault graphs: `ramp(40..60 km/h: 0 -> -0.6)` on control, so fast incoming balls are harder; wood graphs 280-282: frame-shot chance up to 0.3 (0.2 down) from 60 to 100 | no code store and no graph output writes S+0x770 (OPEN 1.10); it keeps its State image 0 | a code hook that copies the incoming ball speed in km/h (as the hit-point scorer does into `TrajectoryEvaluationContext.#1407106c` S+0x88C, `fn_88692040`) into S+0x770 before the shot graphs run. Data alone cannot do it |
| Unused ShotResolution grades | `VeryGood/Normal/Bad/VeryBad` rows of `PowerResolution`, `AimingResolution`, `ErrorResolution` per shot, and grade factors 1 / 0.5 / 0.25 / 0 in S+0x798/0x79C, would scale power, aim and error by shot quality | the selecting keys S+0x3B4/0x3B8 are only ever set to Good (OPEN 1.9) | write a quality-dependent grade into S+0x3B4/0x3B8 (code), or, as a data-only workaround, copy the wanted values into the Good rows |
| Timing ability | `BestAbility` curves blended by the TimingAbility graphs | the worst and best curves are identical (timing-and-fatigue s1) | make `.../5ae85f27/BestAbility` differ from `848c2a13` (data only) |
| Clip Tolerancy arrays | per-clip Up/Down/X/Z tolerances (cm) for the swing clip fit | copied into selector arrays but never read (OPEN 3.6) | a code change in the clip fit `fn_886D3AD8` to use them |
| AimingConfig `#5ed23100` (+0x94) | a per-config flag, true on the serve configs | no reader (OPEN 1.16) | code that reads it; meaning unknown |
| `#be5d458f`, `#aee2d90b`, `#693eedbe` (S+0x768/0x7D0/0x7D8) | inputs of control/aiming graphs | never written; State images 0 / 0 / 1000 (OPEN 1.10) | a code writer; or edit the State image (`data/gameplay/tunables/State/06_PlayerStates.yaml`) to a constant |
