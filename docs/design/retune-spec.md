# Retune specification (Q1)

Status: proposal, checked by simulation. It changes no game data. Builds on [retune-baseline.md](retune-baseline.md), which measured retail; the section numbers there are cited as "baseline 1b" and so on. The structure of the grade, the timing window, the charge and the put-away follows [retune-systems.md](retune-systems.md), the design authority. This spec tunes that note's numbers and lists every change in 4h and 6.

Every number carries one tag:
- *(computed)*: produced by the scripts below, reproducible.
- *(sourced)*: a published measurement, cited in section 1.
- *(judgement)*: a design choice; the reason is given, and play-testing may move it.

Tables headed *(computed)* are pasted verbatim from the generator.

## How to reproduce

```
python3 tools/design/retune_spec.py                 # every table (about 20 min on one core under nice; flight and robust are the slowest)
python3 tools/design/retune_spec.py --quick speed   # one section, small samples
python3 -m unittest tests.test_design_retune
```

- Interpreter: Python 3.13.18. Standard library only; seeds are fixed, so a rerun gives the same numbers on the same Python minor version.
- Inputs:
  - `data/gameplay/ball_templates.yaml` (sha256 `7f105af2258986052ca642f8a25f42641d24d9680bf6704a9a6c6e5bf1e68c86`, 132,476 bytes), read by `tools/design/retune_flight.py`.
  - `data/gameplay/aim_tables.yaml` (sha256 `dd5fdb0d5fc7b9d581f1db244744f23ac1708ced705276dd77b1b312768e543d`, 47,211 bytes), read by `tools/design/retune_aim.py`.
  - Retail numbers quoted from retune-baseline.md.
  - No disc file is read.
- `tools/design/retune_model.py`: the proposal as code. It holds every constant named in this document, with the grade, window, speed-stack, serve, rally and match models.
- `tools/design/retune_flight.py`:
  - the game's closed-form flight on template rows, with proposed row edits;
  - a real-ball reference: quadratic drag, Magnus lift, grip/slip bounce.
- `tools/design/retune_aim.py`: landing points on the retail aim quads (`data/gameplay/aim_tables.yaml`), following aiming.md. It reproduces that document's worked example exactly.
- `tools/design/retune_spec.py`: prints every table below.

**What the simulation is and is not.** The rally simulator is a point-level abstraction: situations, grades, windows, error and winner probabilities per shot, and stamina. It is not the game engine.

- Use it to compare rules and their relative effects. Its absolute rally lengths and point shares are calibration targets for play-testing, not predictions.
- Known gaps against real tennis (computed, final run, 100-120 matches per row, 4d and 9d):
  - Rally length: 5.1 shots per point for average pros and 6.7 for elite players. Tour average is about 4-5.
  - Server points won: 60-65% (9d). Tour is about 62-64%; the first run gave 48-58%.
  - Holds: 73-84% for the builds in 9d, against the systems note's 80-90% targets (still short, see "State at handover").
- The serve model alone (section 2d) is close to tour figures. The remaining gap comes from the rally model's error rates.

### Model fixes and game proposals

Some rules in `retune_model.py` exist only to make the simulation's numbers trustworthy (model fixes). Others are changes proposed for the game. Some are both.

| item | model fix | game proposal | engine terms |
|---|---|---|---|
| Volley arrival scale and pace edges for the grade | yes: volleys were graded on the groundstroke time scale | yes, inside the grade (retune-systems s2) | frames since the opponent's contact S+0xCF0 when IsVolley S+0x5B4 (code, with the grade selection) |
| Contact height at the chosen hit point (letting a high ball drop) | yes: the model sampled height at the top of the bounce | yes (owner clarification) | planner hit-point height C38 / Ball+0x344 (existing) |
| Zero-error band at its retail size, scaled by W | yes: the earlier model charged errors inside the band | yes (retune-systems s3) | t divided by W (code); the fault graphs unchanged |
| Volley bands and put-away | yes: the point model costed hard volleys as errors and had no net winners | yes (section 8) | existing volley classes and grade rows (PF, Efficiency, DeepDeviation, apex), VolleyPower and Fatality; existing clips selected differently |
| Serve fault chance and Serve floor | yes | yes | random roll in serve fault graphs 307-311 (code); Serve input curve (data) |
| Volley rating on low contacts (half-volleys, pick-ups below 50 cm) | yes | yes | existing rating S.Profile.Volley S+0x65C with contact height Ball+0x344, already inputs of the fault graphs (data); no new rating |
| Floor penalty below rating 60 | yes: stopped min-max builds dominating | yes | rating-to-stat curves (graph 23 and others) and fault-graph hand lerps (data) |
| Receiver anticipation of a corner habit (0.35) | yes: models what a human (or a tendency-reading AI) does | no rule; AI positioning work | AI positioning (outside this spec) |
| Rally-model widths, depths, vigor costs, pass error, flat margin | yes (calibration) | only where stated (flat margin, vigor cost) | section 9 |
| Grade score and rows, W, opponent term, pace caps and ceiling, rushed swing and overcharge, aim feed, DeepDeviation by timing, put-away folded into the grade, S+0x770 re-keying, movement rules | no | yes | sections 4-10, table in section 11 |
| Return outcome calibration: Perfect first-serve returns attacking only 40% of the time, return error by timing 0.10 / 0.25 / 0.60 / 0.90, weaker return balls | yes: with the per-family return grade the model returned too well (holds 54-66%) | no | rally-model terms only; the engine's return is graded by s2a |
| Situation base error 0.09 per groundstroke | yes (calibration): with the retail zero-error band almost no neutral ball errs on timing, so rallies would run 9+ shots; raised from 0.05 to 0.09 in the second run to bring rallies to about 6.5 shots and holds closer to the targets. Volleys carry a third of it (next row) | no | stands for the control-sum penalties (running, fatigue) the model does not resolve |
| Situation base error 0.03 per volley | yes (final run): with the base error on groundstrokes only, the serve-and-volleyer led 15 of 16 robustness variants (second run, 0.62-0.76) | yes, separately: volleys carry a small base error like groundstrokes, in addition to the outcome bands of section 8 (retail volleys have none, baseline 3c and 7b) | a small constant term in the volley fault graphs, for example VolleyPower and the standard volley's graph (data) |
| Hold lever 1: a Bad or VeryBad return grade lowers the return ball one step (attacking -> neutral -> weak) | yes (final run, calibration of the first rally shots) | no new rule: in the engine the Bad return row's aim and pace caps already weaken the ball; play should confirm it is weak enough | ShotResolution Bad row of the return ShotDefs (existing, data) |
| Hold lever 2: return error +0.30 per unit of Return stat below 0.80 (rating about 85): +0.08 at Return 60, +0.03 at 75 | yes (final run, calibration) | only as a check: the Return rating's weight in the return fault graphs | Return input S.Profile of the return fault graphs (data) |

### Which results to trust

- **Reliable:**
  - Shot and serve distributions (sections 2 and 3): these are not match-level, and their inputs are swept in 2c.
  - Within-model comparisons of direction and rough size: the opponent-timing term (5c); corner policy with and without anticipation (7d); min-max penalties; the Tee-off depth and let-drop rules (4d); single rules (9c).
- **Not reliable:**
  - Absolute rally length (sim 5.1-6.7 shots against tour 4-5), server points won (60-65% against 62-64%) and hold percentages (73-84% against the 80-90% targets). The situation base error (0.09) and the return calibration are the knobs for these.
  - Exact style field shares: single rules move them by ±0.1-0.2.
  - Serve-and-volley strength in particular, because the model has no court geometry and no swing tails.
- Match-level shares say which builds are clearly out of line (min-max), not the final balance.

---

## 1. Real-tennis targets *(sourced unless marked)*

| quantity | value | source |
|---|---|---|
| Tour average forehand speed (men) | 73 mph (2024); 76 mph (March 2025 sample) | ATP / Tennis Data Innovations 2024 season insights (atptour.com, "Sinner 2024 insights"); ATP article on Fonseca, March 2025 |
| Tour average backhand | 66 mph | ATP/TDI 2024 |
| Forehand spin, tour average | 2,708 rpm (2024), 2,844 rpm (2025 sample); backhand 1,977 rpm | ATP/TDI |
| Top forehand averages, one event | up to 82.5 mph | AO 2021 Infosys data (reported by toomanyrackets.com) |
| Fastest single forehand, one event | 105.3 mph (Opelka) | AO 2021 Infosys |
| Groundstroke spin range | about 2,300 rpm average, 3,800 rpm max | Hawk-Eye study (core.ac.uk record 288373955) |
| Forehand net clearance | about 20 men averaged < 0.6 m; Nadal 0.78 m; WTA leaders <= 0.55 m | On The T analysis, AO 2014-16 |
| Serve speed, top 10 | 117.2 mph first / 95.8 mph second | Tennis Abstract (via Wikipedia "Tennis serve") |
| Serve speed, tour | about 116 / 94 mph (2024) | secondary aggregation (tenniscreative) |
| Fastest server's average | 134.4 mph first-serve average (Mpetshi Perricard, 2025) | ATP |
| First serve in | about 62% tour; top players 74% first, 92% second | secondary; Peter Tea, Wimbledon 2019 |
| Second serve slower by | 28-30 km/h (17-19 mph) | Peter Tea 2019 |
| Double faults | top-50 about 3.4% of service points | Tennis Abstract |
| Serve speed value | +0.43 percentage points of first-serve points won per mph; speed explains about 60% of unreturned first serves | Tennis Abstract |
| Unreturned serves | untouched share above 8% since 2014; aces 16% + unreturned 22% of first serves | Tennis Abstract; ATP INSIGHTS Oct 2023 |
| First-serve effectiveness | 58% of first serves ace / unreturned / attacking; 23% for second serves | ATP INSIGHTS Oct 2023 |
| Return time | about 500 ms for a 200 km/h serve; delivery 913 / 1,158 ms on clay and 720 / 868 ms on carpet (first / second) | O'Donoghue & Liddle 1998; Kleinoeder 2001 |
| Simple reaction at the net | 205-226 ms (volley) | Chow et al. 1999, Med Sci Sports Exerc |
| Approaches | about 70% won, 58.6% when the approach is returned; 65% (US Open 2015) | Tennis Abstract; O'Shannessy |
| Ball drag | Cd 0.507 in free flight | Cross & Lindsey 2014 |
| Court pace | ITF CPR = 100(1 - mu) + 150(0.81 - e); slow < 30, fast > 45 | ITF court classification |

Not sourced, and how they are handled:
- **The shape of the forehand speed distribution** (percentiles, tail): no public percentile data.
  - The target is the owner's decision of 2026-11-14:
    - The fastest forehand in the game is **110 mph**, a hard ceiling reached almost never, and only on a Tee-off ball by a pace build with everything stacked.
    - 106-109 mph happens once or twice a match for that build.
    - This supersedes the earlier brief of 113-115 mph a couple of times a match and 117 mph once a season.
  - The tour average and the 105 mph event maximum *(sourced)* anchor the centre and the realistic edge.
  - The backhand ceiling is 105 mph *(judgement)*. Tour backhands average 7 mph below forehands (66 against 73 *(sourced)*); at the top the gap is taken a little smaller, because flat two-handers come close to forehands there.
- **First-serve-in against speed**: no direct curve. It is derived from the first and second serve anchors (about 30 pp less in for about 20 mph more): roughly 1.2 pp per mph *(judgement from sourced anchors)*.
- **Surface friction and restitution**: chosen inside the ITF bands *(judgement)*: clay mu 0.75 / e 0.84 (CPR 20.5), hard 0.62 / 0.81 (CPR 38), grass 0.56 / 0.76 (CPR 51.5).

---

## 2. Shot speed

### Model

Structure from docs/design/retune-systems.md (sections 2, 4 and 5): the grade picks a row, the charge tier sets how much of the row's pace cap the swing can reach, and timing picks the position inside the row. A forehand's launch speed in mph:

```
row_max = Good_row(class, tier, Power rating) x (1 + (pace_cap[grade] - 1) x tier_share[tier])      grade Good or better
row_max = pace_cap[grade] x (Good_row(Medium) + 0.5 x (Good_row(tier) - Good_row(Medium)))           grade below Good
row_max x 1.04 for an overcharge
v = row_max x skill x (1 - 0.15 x (1 - pos(t))) - 6 (1 - vigor) + N(0, 1.5),   then the ceiling: 110 mph forehand, 105 backhand
```

- **Good row = retail, unchanged** *(sourced)*: launch km/h at perfect timing by class and tier at Power 30 / 54 / 75 / 100 (baseline 1b). A full charge (75 frames) is the charge-table value: Flat 127.1 / 130.1 / 145.2 km/h at min / median / max *(sourced, `data/gameplay/charge_table.yaml`)*.
- **pace_cap** per grade (section 4b), for a flat drive: Tee-off 1.18, VeryGood 1.08, Good 1.00, Normal 0.93, Bad 0.82, VeryBad 0.70. Other shot types take a share of the distance from Good (retune-systems s2a): topspin 80%, slice and lob 50%. A slice on a Bad ball therefore keeps 0.91 of the Good row, and a slice on a Tee-off ball gains only 9%.
- **tier_share** *(judgement, retune-systems s5: the tier steps grow on Good and above)*: Finesse 0.40, Medium 0.60, Powerful 0.85, full 1.00. Below Good, the tier differences are halved.
- **pos(t)** is the retail timing shape (section 5): 1 at t = 0, 0.75 at |t| = 0.5. A row's Min is 15% under its Max *(judgement: retail loses up to 5 km/h at t = +0.5, baseline 1e)*.
- **Skill**: a pace skill adds 2% on Powerful or harder swings.
- **Ceiling** (owner decision): a hard 110 mph forehand and 105 mph backhand. No knee is needed, because the arithmetic below lands on the ceiling by itself.

The ceiling arithmetic (retune-systems s2) *(computed)*:
- The pace build (Power 100) has a full-charge flat Good row of 145.2 km/h (90.2 mph). Tee-off gives 106.5, and the overcharge gives 110.7, which the 110 ceiling takes.
- The median pro (Power 54, 130.1 km/h = 80.8 mph) tops out at 99.2 mph, inside the 95-99 band.
- The elite all-rounder (Power 80) tops out at 103.0.
- The pace skill can carry the pace build's Tee-off full charge to 108.6 mph without an overcharge. With the execution spread, that is where most of the rare 110s come from (2b).

Assumptions about the incoming ball *(judgement, swept in 2c)*:
- Incoming launch 72 ± 9 mph; contact pace is 0.58 × launch (0.62 for short balls).
- 10% of balls are short.
- Lateral run: exponential, scale 230 cm.
- Contact height 105 ± 28 cm; own depth 100 ± 90 cm behind the baseline; 25% of balls carry heavy kick.

Per-season counts assume 65 matches of 200 forehands per player *(judgement)*.

Archetypes (ratings serve / return / FH / BH / volley / power / speed / stamina) *(judgement)*:
- average pro: 51 / 54 / 54 / 54 / 50 / 54 / 55 / 55.
- elite all-rounder: 80 / 82 / 85 / 80 / 72 / 80 / 82 / 85.
- pace specialist: 85 / 70 / 95 / 75 / 60 / 100 / 72 / 80, with the pace skill.

### 2a. Stacking table: from the average rally ball to the absolute peak (forehand launch, mph) *(computed)*

| build | Power rating | rally topspin (Good, Medium) | flat drive (Good, Medium) | Good, full charge = retail | VeryGood, full (x1.08) | Tee-off, Powerful (53-74 frames) | Tee-off, full (x1.18) | + overcharge (x1.04) | + pace skill (x1.02) | after the 110 mph ceiling |
|---|---|---|---|---|---|---|---|---|---|---|
| average pro | 54 | 72.1 | 77.7 | 80.8 | 87.3 | 92.4 | 95.4 | 99.2 | 99.2 | 99.2 |
| elite all-rounder | 80 | 72.8 | 79.4 | 83.9 | 90.6 | 94.7 | 99.0 | 103.0 | 103.0 | 103.0 |
| pace specialist | 100 | 73.3 | 81.4 | 90.2 | 97.4 | 101.0 | 106.5 | 110.7 | 112.9 | 110.0 |

Row maxima at perfect timing (PowerResolution Max of the row). Timing picks the position: the row's Min is 15 % lower (retail shape: a late t = +0.5 keeps about 75 % of the top). Execution spread sd 1.5 mph. Tier shares of the cap above Good: Finesse 0.4, Medium 0.6, Powerful 0.85, Full 1; below Good the tier differences are halved.

### 2b. Monte Carlo over rally situations: forehand launch speed (mph) *(computed, 600000 forehands per build)*

| build | mean | p50 | p90 | p99 | p99.9 | max | retail mean (same shots) | retail max |
|---|---|---|---|---|---|---|---|---|
| average pro | 71.5 | 72.4 | 81.9 | 93.0 | 95.2 | 102.3 | 71.8 | 80.8 |
| elite all-rounder | 72.9 | 73.5 | 83.9 | 95.3 | 97.7 | 105.2 | 73.2 | 83.9 |
| pace specialist | 76.3 | 76.1 | 92.4 | 103.8 | 106.4 | 110.0 | 76.0 | 90.2 |

Exceedances: per 1,000 forehands / per match (200 forehands); last column per season (13000 forehands):

| build | > 100 | > 104 | > 106 | > 108 | > 109 | at the 110 cap (> 109.9) | > 109 per season |
|---|---|---|---|---|---|---|---|
| average pro | 0.0233 / 0.0047 | 0 / 0 | 0 / 0 | 0 / 0 | 0 / 0 | 0 / 0 | 0 |
| elite all-rounder | 0.228 / 0.046 | 0.015 / 0.003 | 0 / 0 | 0 / 0 | 0 / 0 | 0 / 0 | 0 |
| pace specialist | 41.1 / 8.2 | 8.14 / 1.6 | 1.28 / 0.26 | 0.488 / 0.098 | 0.315 / 0.063 | 0.203 / 0.041 | 4.1 |

Resulting frequencies (share of forehands) of grade, hold and timing:

| build | Tee-off | VeryGood | Good | Normal | Bad | VeryBad | Finesse | Medium | Powerful | Full | Rushed | Overcharge | Perfect | Good | Poor | Mistimed |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| average pro | 0.043 | 0.303 | 0.400 | 0.067 | 0.176 | 0.011 | 0.000 | 0.615 | 0.251 | 0.002 | 0.131 | 0.000 | 0.410 | 0.319 | 0.269 | 0.002 |
| elite all-rounder | 0.043 | 0.302 | 0.400 | 0.068 | 0.175 | 0.011 | 0.000 | 0.615 | 0.250 | 0.002 | 0.132 | 0.000 | 0.440 | 0.307 | 0.253 | 0.001 |
| pace specialist | 0.043 | 0.302 | 0.401 | 0.067 | 0.176 | 0.011 | 0.000 | 0.614 | 0.252 | 0.003 | 0.132 | 0.000 | 0.448 | 0.302 | 0.249 | 0.001 |

### 2c. Sensitivity of the tail to the situation assumptions *(computed, 200000 forehands each)*

| variant | average pro mean | specialist mean | specialist Tee-off share | > 106 per 1,000 | > 108 per 1,000 | at the 110 cap per 1,000 |
|---|---|---|---|---|---|---|
| as proposed | 71.5 | 76.3 | 0.043 | 1.40 | 0.49 | 0.220 |
| short balls x0.5 | 71.0 | 75.7 | 0.026 | 1.22 | 0.56 | 0.210 |
| short balls x2 | 72.4 | 77.5 | 0.077 | 1.59 | 0.43 | 0.175 |
| incoming pace sd 6 | 71.3 | 75.9 | 0.035 | 0.36 | 0.01 | 0.000 |
| incoming pace sd 12 | 71.7 | 76.8 | 0.056 | 5.79 | 3.73 | 2.055 |
| lateral run x0.7 | 73.0 | 78.1 | 0.046 | 1.56 | 0.61 | 0.245 |
| lateral run x1.4 | 69.7 | 74.1 | 0.039 | 1.16 | 0.48 | 0.195 |
| overcharge tried 50 % | 71.5 | 76.3 | 0.043 | 1.40 | 0.46 | 0.170 |
| overcharge always tried | 71.5 | 76.3 | 0.043 | 1.40 | 0.52 | 0.250 |
| human timing sd 2.8 frames | 71.6 | 76.3 | 0.043 | 1.46 | 0.53 | 0.220 |
| human timing sd 4.0 frames | 71.4 | 76.2 | 0.043 | 1.31 | 0.48 | 0.215 |

Reading: 
- **Averages stay at retail** (coordinator ruling: the owner wants today's averages and the change at the edges; the earlier 72.5 / 80 / 87 mph targets are withdrawn). Means are 71.5 / 72.9 / 76.3 mph for the average pro, elite all-rounder and pace specialist, against 71.8 / 73.2 / 76.0 for retail on the same shots (-0.3 / -0.3 / +0.3 mph). The shot-type share (topspin keeps 80% of a grade's effect) moved them closer to retail than the first run (-1.0 / -1.0 / -0.5). The tour average is 73-76 *(sourced)*.
- **Why the centre barely moves.** 40% of forehands are Good (the retail row) and 61% are Medium swings. Powerful is out of reach on a neutral ball (section 6). The VeryGood and Tee-off gains (30% and 4%) and the Normal-or-worse losses (25%) nearly cancel.
- **Tail, pace specialist.**
  - Passes 104 mph 1.6 times per match.
  - Passes 106 about once in four matches (1.28 per 1,000 forehands) and 108 about once in ten.
  - Reaches the 110 ceiling about once in 25 matches (0.20 per 1,000; 2.6 per season).
  - Retail maximum on the same shots: 90.2 mph.
- **Tail, others.** The elite all-rounder's maximum is 105 mph (above 100 about once in 22 matches). The average pro's maximum is 102 (above 100 about once in 200 matches).
- **Against the owner's first brief** (106-109 once or twice a match for the specialist), the model gives 0.26 per match. With the retail tiers a full charge is rare (0.3% of forehands), and a Tee-off ball with a Powerful (not full) charge tops out at 101 mph for the pace build. **The owner accepts this tail** and does not want the Powerful-tier lever (a tier share of 1.0 above Good, Tee-off Powerful 103.4 mph); it is not proposed.
- **Where the 110s come from.** Mostly Tee-off, full charge, Perfect and the pace skill (108.6 mph before the spread). With the 10-frame wait the overcharge adds about a fifth of them (6b: 0.04 per match at the cap, against 0.02 with the old 25-frame wait).
- **Sensitivity (2c).** The incoming-pace spread drives the tail: sd 12 mph instead of 9 gives four times as many shots above 106. Short-ball share, run distances, the human release sd and the overcharge try rate barely move it. The ceiling keeps the maximum fixed in every variant.

### Serves

The first-serve model *(judgement; constants `SERVE`)*:

```
comfort = 80 + 34 Serve + 8 Power
v = comfort + effort^1.4 (14 + 20 Power) + gauge - 6 (1 - vigor)
P(in) = 0.70 + 0.12 (Serve - 0.5) - 0.012 (v - comfort) + gauge term - 0.50 floor(Serve)
stamina = 1 + 3 effort^2
```

- **The fault chance is new** (game proposal, labelled code change). Retail human serve fault graphs 307-311 are deterministic: a step function of the gauge window and an aim value. The proposal adds a random roll, as the AI branch already has, with P(in) from the formula above. At comfort effort with a Good gauge, P(in) is 73% at Serve 80 and 76% at Serve 100 (up to 80% with a Perfect gauge). Over a match's mix of efforts the averages are 57-63% (section 2d), so the best first-serve percentages land near the owner's 70-75% only for players who serve at comfort. The Serve-rating floor term is a data edit on the graphs' Serve input.
- **Second serve.** comfort - 24 mph, P(in) 0.93. Players with high Serve and Stamina get a "big second serve" of up to +10 mph, at -0.6 pp of P(in) per mph.
- **Return time.** 500 ms × (200 km/h / v)^0.9, anchored on O'Donoghue & Liddle *(sourced anchor)*.
- **Effort.** Each first serve's effort is drawn from Beta(2, 3) (mean 0.4). The specialist also chooses maximum effort on 4% of first serves.

### 2d. Serves: first and second serve over a match's mix of efforts *(computed, 200000 points per build, returner = average pro)*

| server | 1st mean | p90 | p99 | max | > 140 per 1,000 / per match | > 148 per 1,000 / per match | 1st in | unreturned (incl. aces) / 1st in | 2nd mean | unreturned / 2nd in | double faults / point |
|---|---|---|---|---|---|---|---|---|---|---|---|
| average pro | 105.1 | 112.3 | 118.2 | 125.7 | 0 / 0 | 0 / 0 | 0.568 | 0.342 | 73.6 | 0.263 | 0.052 |
| elite all-rounder | 121.4 | 130.3 | 137.4 | 146.3 | 2.4 / 0.21 | 0 / 0 | 0.631 | 0.360 | 95.5 | 0.277 | 0.039 |
| pace specialist | 127.8 | 139.2 | 152.5 | 158.8 | 90 / 8.1 | 37 / 3.4 | 0.611 | 0.366 | 100.1 | 0.283 | 0.041 |

Effort against speed, first-serve-in probability and stamina cost (pace specialist, Perfect gauge, fresh):

| effort | speed mph | P(1st in) | stamina units | returner's time ms |
|---|---|---|---|---|
| 0.0 | 117.9 | 0.753 | 1.00 | 524.4 |
| 0.2 | 121.4 | 0.712 | 1.12 | 510.5 |
| 0.4 | 127.3 | 0.641 | 1.48 | 489.3 |
| 0.6 | 134.5 | 0.555 | 2.08 | 465.7 |
| 0.8 | 142.7 | 0.456 | 2.92 | 441.4 |
| 0.9 | 147.2 | 0.402 | 3.43 | 429.3 |
| 1.0 | 151.9 | 0.347 | 4.00 | 417.4 |

Reading:
- There is no ceiling near 120 mph. The specialist averages 128 mph (the fastest real server averages 134 *(sourced)*) and passes 148 mph about 3.4 times per match, all from maximum-effort serves.
- At maximum effort the specialist pays: P(in) falls to 35%, and each serve costs 4 times the stamina of a comfort serve.
- First serve in is 57-63% (tour about 62%). Unreturned first serves, aces included, are 34-37% against an average-pro returner (tour: aces 16% + unreturned 22% = 38% of first serves). Unreturned second serves are 26-28%. The second run gave 25-28% for first serves; the rise is hold lever 2 (the average pro's Return 54 adds 0.10 return error).
- Second serves average 74-100 mph, 26-32 mph below first serves (tour 17-19 mph *(sourced)*). The average pro's gap is too large; this is a calibration point.
- Double faults: elite 3.9% *(computed)* against the top-50's 3.4% *(sourced)*; average pro 5.2%.

---

## 3. Flight and bounce

The game model is the closed form from baseline 2:
- drag k = T / 0.06;
- spin as a constant vertical acceleration spin_a;
- the launch solved from InitialSpeed, with the Apogee stage weighted by PowerfulFactor (PF).

`retune_flight.game_fly` reproduces the baseline (row 10 Flat Powerful, PF 1, blend 0.5: 147.1 km/h; baseline 147).

The reference model *(computed)*:
- quadratic drag, Cd 0.507 *(sourced)*;
- lift CL = 1 / (2 + v / (r w)) *(judgement, a common fit)*;
- Cross's grip/slip bounce, alpha 0.55, with the surface mu and e from section 1;
- after the bounce, lift capped at CL 0.20 *(judgement: the grip regime leaves 5,000+ rpm, where the free-flight law does not hold)*.

### 3a. Retail against proposed rows: one cross-court drive (hitter on the baseline at 1.0 m, target 1.9 m inside the opposite baseline) *(computed, game model)*

| shot | row | PF / blend | launch | net clear m | apex m | bounce in | bounce out | out/in | bounce height m | at baseline | to baseline s |
|---|---|---|---|---|---|---|---|---|---|---|---|
| retail Flat Powerful, median stats | 10 | 0.76 / 0.76 | 129 (80) | 0.87 | 1.81 | 63 | 58 | 0.91 | 1.09 | 50 | 1.04 |
| retail TopSpin Powerful, median | 8 | 0.82 / 0.86 | 119 (74) | 1.42 | 2.35 | 55 | 54 | 0.99 | 1.53 | 45 | 1.19 |
| retail Slice Powerful, median | 9 | 0.79 / 0.79 | 103 (64) | 0.74 | 1.68 | 48 | 45 | 0.94 | 0.86 | 38 | 1.32 |
| proposed flat, rally 72 mph (blend 0.3) | 10* | 0.44 / 0.30 | 116 (72) | 1.22 | 2.14 | 51 | 41 | 0.80 | 0.91 | 32 | 1.27 |
| proposed flat, firm 80 mph (blend 0.3) | 10* | 0.65 / 0.30 | 130 (81) | 0.70 | 1.65 | 64 | 52 | 0.80 | 0.75 | 44 | 1.03 |
| proposed flat, big 95 mph (blend 0.3) | 10* | 0.89 / 0.30 | 155 (96) | 0.25 | 1.25 | 89 | 71 | 0.80 | 0.60 | 65 | 0.79 |
| proposed flat, peak, deep 113 mph (blend 1.0) | 10* | 0.94 / 1.00 | 186 (115) | 0.18 | 1.18 | 117 | 98 | 0.84 | 0.75 | 94 | 0.61 |
| proposed topspin, rally 70 mph (blend 0.6) | 8* | 0.06 / 0.60 | 113 (70) | 2.22 | 3.13 | 46 | 39 | 0.84 | 1.81 | 25 | 1.49 |
| proposed topspin, rally 72 mph (blend 0.8) | 8* | 0.12 / 0.80 | 116 (72) | 2.11 | 3.03 | 49 | 42 | 0.84 | 1.98 | 29 | 1.40 |
| proposed topspin, heavy 85 mph (blend 1.0) | 8* | 0.65 / 1.00 | 138 (86) | 1.01 | 1.95 | 70 | 59 | 0.84 | 1.64 | 50 | 0.98 |
| proposed topspin, big 95 mph (blend 0.8) | 8* | 0.90 / 0.80 | 155 (96) | 0.52 | 1.49 | 86 | 72 | 0.84 | 1.22 | 64 | 0.81 |
| proposed slice 60 mph | 9* | 0.07 / 0.80 | 97 (60) | 1.68 | 2.60 | 29 | 21 | 0.72 | 0.48 | 13 | 2.05 |
| proposed slice 66 mph | 9* | 0.51 / 0.80 | 106 (66) | 0.94 | 1.86 | 38 | 27 | 0.72 | 0.38 | 20 | 1.56 |

Speeds km/h (launch also mph). `*` = proposed copy of that retail row (fields in the spec). The PF (PowerfulFactor, the secondary weight) needed for each target speed is solved by bisection; the speed model of section 2 maps to PF this way.

### 3b. Real-ball reference (quadratic drag Cd 0.507, Magnus lift, grip/slip bounce) for the same launches *(computed, reference model)*

| launch | surface | ITF CPR | launch deg | net clear m | apex m | bounce in | bounce out | out/in | bounce height m | at baseline | to bounce s | to baseline s |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| flat 72 mph, 1,200 rpm topspin | clay | 20.5 | 8.1 | 0.70 | 1.68 | 78 | 57 | 0.73 | 1.03 | 54 | 0.85 | 0.98 |
| flat 72 mph, 1,200 rpm topspin | hard | 38.0 | 8.1 | 0.70 | 1.68 | 78 | 57 | 0.72 | 0.96 | 54 | 0.85 | 0.98 |
| flat 72 mph, 1,200 rpm topspin | grass | 51.5 | 8.1 | 0.70 | 1.68 | 78 | 57 | 0.72 | 0.85 | 53 | 0.85 | 0.98 |
| topspin 72 mph, 2,700 rpm | clay | 20.5 | 10.2 | 0.90 | 1.88 | 78 | 64 | 0.81 | 1.26 | 60 | 0.85 | 0.97 |
| topspin 72 mph, 2,700 rpm | hard | 38.0 | 10.2 | 0.90 | 1.88 | 78 | 63 | 0.81 | 1.17 | 60 | 0.85 | 0.97 |
| topspin 72 mph, 2,700 rpm | grass | 51.5 | 10.2 | 0.90 | 1.88 | 78 | 63 | 0.80 | 1.04 | 60 | 0.85 | 0.97 |
| topspin 85 mph, 3,200 rpm | clay | 20.5 | 7.9 | 0.65 | 1.64 | 92 | 74 | 0.81 | 1.14 | 71 | 0.72 | 0.82 |
| topspin 85 mph, 3,200 rpm | hard | 38.0 | 7.9 | 0.65 | 1.64 | 92 | 74 | 0.81 | 1.06 | 71 | 0.72 | 0.82 |
| topspin 85 mph, 3,200 rpm | grass | 51.5 | 7.9 | 0.65 | 1.64 | 92 | 74 | 0.80 | 0.94 | 71 | 0.72 | 0.82 |
| flat 95 mph, 1,500 rpm | clay | 20.5 | 4.5 | 0.30 | 1.32 | 103 | 74 | 0.73 | 0.82 | 71 | 0.64 | 0.74 |
| flat 95 mph, 1,500 rpm | hard | 38.0 | 4.5 | 0.30 | 1.32 | 103 | 79 | 0.77 | 0.74 | 76 | 0.64 | 0.73 |
| flat 95 mph, 1,500 rpm | grass | 51.5 | 4.5 | 0.30 | 1.32 | 103 | 82 | 0.80 | 0.64 | 78 | 0.64 | 0.73 |
| flat 113 mph, 1,500 rpm, deep | clay | 20.5 | 3.3 | 0.20 | 1.21 | 119 | 92 | 0.77 | 0.71 | 90 | 0.57 | 0.60 |
| flat 113 mph, 1,500 rpm, deep | hard | 38.0 | 3.3 | 0.20 | 1.21 | 119 | 97 | 0.81 | 0.64 | 95 | 0.57 | 0.60 |
| flat 113 mph, 1,500 rpm, deep | grass | 51.5 | 3.3 | 0.20 | 1.21 | 119 | 99 | 0.83 | 0.55 | 97 | 0.57 | 0.60 |
| flat 113 mph, 2,500 rpm, deep | clay | 20.5 | 4.4 | 0.32 | 1.31 | 119 | 89 | 0.74 | 0.90 | 87 | 0.57 | 0.61 |
| flat 113 mph, 2,500 rpm, deep | hard | 38.0 | 4.4 | 0.32 | 1.31 | 119 | 94 | 0.79 | 0.81 | 92 | 0.57 | 0.60 |
| flat 113 mph, 2,500 rpm, deep | grass | 51.5 | 4.4 | 0.32 | 1.31 | 119 | 97 | 0.81 | 0.70 | 95 | 0.57 | 0.60 |
| slice 60 mph, 1,500 rpm backspin | clay | 20.5 | 5.3 | 0.44 | 1.43 | 66 | 45 | 0.68 | 0.57 | 42 | 1.01 | 1.17 |
| slice 60 mph, 1,500 rpm backspin | hard | 38.0 | 5.3 | 0.44 | 1.43 | 66 | 48 | 0.74 | 0.52 | 46 | 1.01 | 1.16 |
| slice 60 mph, 1,500 rpm backspin | grass | 51.5 | 5.3 | 0.44 | 1.43 | 66 | 50 | 0.76 | 0.47 | 48 | 1.01 | 1.15 |

### 3c. The flat 113 mph forehand: what it must look like *(computed)*

| model | landing | spin | launch deg | net clear m | apex m | to bounce s |
|---|---|---|---|---|---|---|
| real | 9.5 m past the net (2.4 m inside) | 800 | 1.7 | -0.01 | 1.08 | 0.52 |
| real | 9.5 m past the net (2.4 m inside) | 1500 | 2.6 | 0.07 | 1.14 | 0.52 |
| real | 9.5 m past the net (2.4 m inside) | 2500 | 3.7 | 0.18 | 1.23 | 0.52 |
| real | 10.5 m past the net (1.4 m inside) | 800 | 2.1 | 0.07 | 1.11 | 0.55 |
| real | 10.5 m past the net (1.4 m inside) | 1500 | 3.1 | 0.16 | 1.19 | 0.55 |
| real | 10.5 m past the net (1.4 m inside) | 2500 | 4.2 | 0.28 | 1.29 | 0.55 |
| real | 11.2 m past the net (0.7 m inside) | 800 | 2.4 | 0.12 | 1.14 | 0.57 |
| real | 11.2 m past the net (0.7 m inside) | 1500 | 3.4 | 0.23 | 1.23 | 0.57 |
| real | 11.2 m past the net (0.7 m inside) | 2500 | 4.5 | 0.35 | 1.34 | 0.58 |
| game, proposed flat row | 10.0 m past the net | spin blend 1.0 (spin_a -0.300) | - | 0.12 | 1.15 | 0.55 |
| game, proposed flat row | 10.5 m past the net | spin blend 1.0 (spin_a -0.300) | - | 0.17 | 1.18 | 0.57 |
| game, proposed flat row | 11.0 m past the net | spin blend 0.3 (spin_a -0.118) | - | 0.09 | 1.11 | 0.58 |
| game, proposed flat row | 11.0 m past the net | spin blend 1.0 (spin_a -0.300) | - | 0.21 | 1.21 | 0.58 |

### 3d. Other shots: retail and proposed *(computed, game model)*

| shot | PF / blend | launch | net clear m | apex m | bounce in | bounce out | out/in | bounce height m | at baseline | to baseline s |
|---|---|---|---|---|---|---|---|---|---|---|
| retail Drop shot (row 32) | 0.81 / 0.81 | 55 (34) | 0.90 | 2.09 | 26 | 24 | 0.94 | 1.02 | - | - |
| retail Lob Medium (row 7) | 0.19 / 0.19 | 102 (63) | 3.79 | 4.74 | 38 | 41 | 1.10 | 2.73 | 29 | 1.90 |
| retail Volley flat (row 19) | 0.86 / 0.86 | 89 (55) | 0.30 | 1.22 | 57 | 55 | 0.97 | 0.79 | 48 | 0.79 |
| retail Serve flat Powerful (row 27) | 0.56 / 0.56 | 132 (82) | 0.59 | 2.70 | 86 | 82 | 0.95 | 1.59 | 63 | 0.92 |
| retail Serve flat Powerful (row 27), PF 1 | 1.00 / 1.00 | 196 (122) | 0.23 | 2.70 | 149 | 141 | 0.95 | 2.10 | 124 | 0.55 |
| proposed flat serve 100 mph | 0.63 / 0.50 | 166 (103) | 0.34 | 2.70 | 119 | 113 | 0.95 | 1.79 | 95 | 0.68 |
| proposed flat serve 120 mph | 0.80 / 0.50 | 196 (122) | 0.23 | 2.70 | 149 | 141 | 0.95 | 2.10 | 124 | 0.55 |
| proposed flat serve 135 mph | 0.90 / 0.50 | 221 (138) | 0.18 | 2.70 | 174 | 165 | 0.95 | 2.43 | 148 | 0.47 |
| proposed flat serve 150 mph | 0.96 / 0.50 | 243 (151) | 0.15 | 2.70 | 196 | 186 | 0.95 | 2.75 | 168 | 0.42 |

### What changes, and whether it is a data edit or code

| change | proposed values | where | data / code |
|---|---|---|---|
| Flat rows faster with lower clearance | FlatNormal Powerful (row 10): InitialSpeed primary curve 178 -> 200 km/h; T 0.050; spin_a -0.04 / -0.30 (lo / hi of the blend). Same pattern for the Finesse and Medium flat rows, scaled by baseline 1b ratios *(judgement)* | ball templates, 334e7e0d | data |
| Topspin rows: higher, heavier, slower | TopSpinNormal Powerful (row 8): primary 150 -> 168 km/h, T 0.0525, spin_a -0.10 / -0.42, out-elevation gain 1.08 | ball templates | data |
| Slice rows stay low and slow down | SliceNormal Powerful (row 9): primary 118 -> 132 km/h, spin_a +0.06 / +0.18, out-elevation 0.85, bounce loss 22-30% | ball templates | data |
| Bounce speed loss | retail curve16 keys (-0.2, 0, 0.10, -0.15) make a flat ball 15% faster after the bounce (out/in up to 1.15, baseline 2). Proposed: (-0.30, 0, 0.16, 0.22), giving out/in 0.84 for heavy topspin and 0.78 for flat. Slice: (0, 0.20, 0.22, 0.30). Real hard court: 0.72-0.81 *(computed)* | bounce curve16 lists in the template rows | data |
| Per-surface bounce | clay keeps more height and slows more; grass skids lower. Real reference (topspin 72 mph): bounce height 1.26 / 1.17 / 1.04 m and CPR 20 / 38 / 52 for clay / hard / grass | the bounce has no surface input; patch point 889C1F58 (baseline 2) | code |
| PF from the speed model | section 2's launch speed must map to PF per row. Bisection gives the PF per target in 3a (for example flat 72 / 80 / 95 mph at PF 0.44 / 0.65 / 0.88, blend 0.3) | shot-resolution PowerfulFactor graphs | data (curve shapes), plus code if grade and hold enter as new inputs (sections 4 and 6) |
| Serve rows | primary 245 km/h; 100 / 120 / 135 / 150 mph at PF 0.63 / 0.80 / 0.90 / 0.96 | ServeFlatPowerful and related rows | data |

**The flat 113 mph forehand** (3c). The case was in the brief; with the owner's later 110 mph ceiling it is now an upper bound, and the conclusions hold a fortiori at 106-110 mph.
- In the real-ball reference a 113 mph forehand must launch at 2-4.5 degrees, clear the net by 0.1-0.35 m and land deep (10-11 m past the net). It reaches the bounce in 0.55 s.
- With 800 rpm it barely clears (-0.01 to 0.12 m). With 2,500 rpm it has 0.2-0.35 m.
- The proposed flat row gives the same picture: at full spin blend, clearance 0.16-0.25 m.
- The proposed flat row's top speed (PF 1, full spin) is 187-195 km/h (116-121 mph), depending on depth. The 110 mph ceiling belongs in the speed graph (section 2), not in the row.
- So a peak flat shot is physically consistent only as a deep, low ball with some topspin. Margin is thin, and section 7's error terms carry that cost.

---

## 4. Set-up grade

Structure: docs/design/retune-systems.md section 2, which is the design authority for this section. This spec tunes its thresholds and table values with the shot and rally models; each changed number is listed in 4h.

Every shot answers two questions, kept apart:
- How good was the situation? The **grade**, one of six rows, decided at the swing's commit.
- How well was it executed? The **timing value**, which picks the position inside the row (section 5).

The grade is a penalty score summed from four inputs the engine already computes, then mapped to a row:
- **arrival margin**: frames planted at the hit point before contact. For volleys it is frames since the opponent's contact, on a volley scale;
- **contact height** at the hit point the planner chose;
- **incoming pace** at contact: S+0x770, which needs its writer (code, with the re-keying in 4g);
- **self-inflicted**: a rushed power swing, and vigor under 0.3.

Retail selects only Good (S+0x3B4 / 0x3B8, OPEN 1.9). The score is computed in `fn_886629C8`, where the row is chosen today (code). Tee-off is the VeryGood row times a code multiplier, because ShotResolution has five rows at fixed offsets.

**Contact height is measured at the chosen hit point, not at the top of the bounce** (owner clarification). A high-bouncing ball that the player has time and room to let drop scores 0 for height. In the model, a player set for at least 20 frames, with at least 60 frames from the opponent's contact, lets a ball above the shoulder drop into the upper strike zone. He pays with a deeper contact point, 1.2 cm further back per cm of drop *(judgement)*, and fewer frames set. Height costs points only when the player is forced, or chooses, to take the ball high or low.

### 4a. The score: points per input *(structure from retune-systems.md s2; thresholds tuned here)*

| input (engine value) | points | note |
|---|---|---|
| arrival margin: frames planted at the hit point before contact (planner arrival) | >= 30: 0; 15-29: 1; 1-14: 2; still moving: 3; reach or lunge swing: 4 | volleys: frames since the opponent's contact (S+0xCF0): >= 50: 0; 36-49: 1; 25-35: 2; less: 3; stretched: 4 |
| contact height at the chosen hit point (Ball+0x344 / C38), cm | waist to shoulder (95-145): 0; knee to waist or shoulder to head (50-185): 1; beyond: 2 | a set player with >= 20 frames set and >= 60 frames lets a high ball drop: contact in the upper strike zone, 1.2 cm further back per cm of drop |
| incoming pace at contact (S+0x770, needs its writer), km/h | slow <= 52: -1; normal <= 78: 0; heavy <= 100: 1; faster: 2 | volleys: 52 / 80 / 100 |
| self-inflicted | rushed power swing: +1; vigor < 0.3: +1 | section 6 |

Score to grade: -1 with the Tee-off test, Tee-off; -1 or 0, VeryGood; 1-2, Good; 3, Normal; 4-5, Bad; 6 or more, VeryBad.

**Tee-off test** (all required):

| condition | threshold | engine value |
|---|---|---|
| slow ball at arrival | contact pace <= 52 km/h (the -1 pace point) | S+0x770 (needs its writer); a neutral rally ball arrives at 60-75 km/h |
| contact waist to shoulder | 95-145 cm at the chosen hit point | Ball+0x344; Fatality clips are shoulder height |
| time | >= 60 frames since the opponent's contact | S+0xCF0, as the AutoSwing test (graph 179) |
| feet set, no reach | arrived >= 20 frames before contact; required run < 3.5 m/s; not stretched | planner arrival; PT+0x1B0 FlatGoodReach threshold; reach qualifier #0698037d |
| not deep, not backing up | contact <= 100 cm behind the baseline | contact x (owner clarification) |

Volley Tee-off (the volley put-away): score -1 (so a slow ball) and contact >= 110 cm, >= 30 frames since the opponent's contact, not stretched.

### 4b. What each row gives *(retune-systems.md s2 table, values tuned here)*

| grade | pace cap vs Good | aim cap vs Good | aim row Min | error added | W_grade | spin (model term) |
|---|---|---|---|---|---|---|
| Tee-off | x1.18 | x1.18 | 0.30 | +0.00 | x1.30 | x1.10 |
| VeryGood | x1.08 | x1.12 | 0.20 | +0.00 | x1.10 | x1.05 |
| Good | x1.00 | x1.00 | 0.00 | +0.00 | x1.00 | x1.00 |
| Normal | x0.93 | x0.82 | 0.00 | +0.03 | x0.95 | x0.95 |
| Bad | x0.82 | x0.59 | 0.00 | +0.08 | x0.90 | x0.85 |
| VeryBad | x0.70 | x0.35 | 0.00 | +0.15 | x0.85 | x0.70 |

Good is the retail row unchanged. Tee-off is the VeryGood row times a code multiplier (ShotResolution has five rows).

### 4c. Worked situations *(computed)*

| situation | frames | frames set | height cm | pace km/h | depth cm | score | grade | points |
|---|---|---|---|---|---|---|---|---|
| sitter: short floater, watched all the way | 100 | 40 | 110 | 45 | -250 | -1 | Tee-off | pace -1 |
| slow ball, set, but taken 2 m behind the baseline | 100 | 40 | 120 | 48 | 200 | -1 | VeryGood | pace -1 |
| ordinary rally ball, player stood still for it | 80 | 32 | 110 | 68 | 100 | 0 | VeryGood |  |
| neutral baseline rally ball | 78 | 20 | 100 | 68 | 100 | 1 | Good | arrival +1 |
| deep heavy topspin taken high (no time to let it drop) | 72 | 8 | 165 | 66 | 250 | 3 | Normal | arrival +2, height +1 |
| hard flat drive, little time | 58 | 4 | 95 | 92 | 120 | 3 | Normal | arrival +2, pace +1 |
| run wide, arrive late | 70 | 0 | 85 | 70 | 150 | 5 | Bad | arrival +4, height +1 |
| low slice at the feet | 82 | 12 | 40 | 52 | 80 | 3 | Normal | arrival +2, height +2, pace -1 |
| blistering drive, still moving | 50 | 0 | 90 | 108 | 150 | 6 | VeryBad | arrival +3, height +1, pace +2 |

Checks *(computed, 4c)*:
- A neutral rally ball (arrived 20 frames early, strike zone, normal pace) scores 1: Good, retail's only grade, so the middle of the game does not move.
- An ordinary ball the player stood still for scores 0: VeryGood.
- A slow ball taken 2 m behind the baseline scores -1 but fails the Tee-off test: VeryGood. A full charge or overcharge is still available on it.

**Row effects** (4b). The pace and aim caps are ratios to the Good row, and the Good row is the retail row unchanged. Error added: 0 / 0 / 0 / +0.03 / +0.08 / +0.15. W_grade: 1.30 / 1.10 / 1.00 / 0.95 / 0.90 / 0.85. Spin follows the PowerResolution row through the spin blend (S+0x774 is a curve of the PowerfulFactor, OPEN 2.6). That is a model term, not a new rule.

Grade frequencies in the section 2 situation mix (2b, more short balls than a match between equals): Tee-off 4.3%, VeryGood 30%, Good 40%, Normal 7%, Bad 17.5%, VeryBad 1% (the same for every build, because the grade does not read ratings except through speed). In matches between equals (4d) the groundstroke shares are Tee-off 2.2-2.6% and VeryGood 13-18%.

### 4d. Tee-off frequency in matches between equals *(computed, 120 best-of-3 matches per row)*

| variant | players | groundstrokes per player per set | Tee-off groundstrokes per player per set | volley put-aways (Tee-off) per player per set | Tee-off share of groundstrokes | VeryGood share | shots per point |
|---|---|---|---|---|---|---|---|
| as proposed (contact <= 100 cm behind the baseline; high balls let drop when set) | average pro | 120 | 3.1 | 0.1 | 0.026 | 0.177 | 5.07 |
| as proposed (contact <= 100 cm behind the baseline; high balls let drop when set) | elite all-rounder | 165 | 3.6 | 0.1 | 0.022 | 0.135 | 6.65 |
| Tee-off depth limit 150 cm | average pro | 118 | 3.6 | 0.1 | 0.031 | 0.172 | 5.08 |
| Tee-off depth limit 150 cm | elite all-rounder | 163 | 4.2 | 0.1 | 0.026 | 0.131 | 6.62 |
| no letting high balls drop (height at the top of the bounce) | average pro | 114 | 3.0 | 0.1 | 0.026 | 0.172 | 5.04 |
| no letting high balls drop (height at the top of the bounce) | elite all-rounder | 165 | 3.5 | 0.1 | 0.021 | 0.134 | 6.58 |

### 4e. Moonballing as a tactic *(computed, elite all-rounder against the plain elite all-rounder, 100 matches per row)*

The moonballer hits, on balls graded Good or worse, a high slow deep topspin (launch 58 mph, contact about 0.52 of launch, bouncing to about 175 cm) instead of his normal shot, at the share in the first column.

| moonball share | rules | moonballer's match win share |
|---|---|---|
| 0 % | as proposed | 0.540 |
| 30 % | as proposed | 0.330 |
| 30 % | depth limit 150 cm | 0.280 |
| 30 % | no letting drop | 0.310 |
| 60 % | as proposed | 0.180 |
| 60 % | depth limit 150 cm | 0.120 |
| 60 % | no letting drop | 0.150 |

Reading *(computed)*:
- **A few per set.** Elite players get 3.6 Tee-off groundstrokes per player per set (2.2% of groundstrokes), average pros 3.1 (2.6%). The first run gave 5.8 / 5.0; the drop comes from the higher situation base error (shorter rallies) and from returns no longer reaching Tee-off (s2a).
- **The 1 m depth limit** (owner clarification) costs about 0.5-0.6 Tee-offs per set against a 150 cm limit (4.2 / 3.6). Those balls become VeryGood, where a full charge is still available.
- **Letting high balls drop** changes the count by less than the sampling noise (3.5 -> 3.6 for elite players, 3.0 -> 3.1 for average pros; noise about ±0.2).
- **Volley Tee-offs** are rare (0.1 per set), because the -1 pace point needs a ball under 52 km/h at contact. Net winners come from band-1 volleys (section 8).
- **Moonballing (4e) is not a winning tactic** under any of the rule variants. At a 30% moonball share the moonballer wins 33% of matches against the plain player; at 60% he wins 18% (the 0% control row is 0.54, sampling noise about ±0.05).
  - The cause is the slow-ball pace point: a moonball reaches the receiver at about 49 km/h, so he scores -1 (VeryGood at worst).
  - The depth limit and the let-drop rule move this by only a few points (28-33% at 30%, 12-18% at 60%).
  - Model limit: the model has no court geometry in which a deep moonball drives the receiver 3-4 m back. Letting it drop costs only 1.2 cm per cm of drop (about 35 cm for a 175 cm bounce). On clay, a real moonball works partly through that geometry, so play has to judge it.

### 4f. Grades per shot family, and shot type (retune-systems s2a)

The section 2 score is for a rally groundstroke. Applying it to everything was the systems note's first-run error: it put every return of a fast serve in a Bad or VeryBad row, which was the main cause of the big server's dominance in the first robustness run. Each family is now judged against what is normal for it:

| family | grade inputs in the model | engine terms |
|---|---|---|
| rally groundstroke | the section 2 score (4a) | as 4a |
| return of serve | no pace or arrival points. Good by default; Bad when stretched (serve placement >= 0.80 of the reach) or jammed at the body (8% of central serves, judgement); VeryGood on a slow serve (<= 90 mph *(judgement)*: the attackable second serve); never Tee-off. Vigor under 0.3 drops one row | the score code in `fn_886629C8` with an IsReturn branch (the ResolutionConfig already switches to the Return config on a return, OPEN 1.9) |
| serve | no grade; its own inputs and the fault chance (2d) | unchanged |
| volley | time since the opponent's contact (50 / 36 / 25 frames); height **relative to the net** (at least 20 cm above the 91 cm strap: 0; from 15 cm below to 20 cm above, or above the head: 1; lower: 2); volley pace edges 52 / 80 / 100 km/h; stretch | the score with an IsVolley branch |
| smash | time under the ball and backpedalling, no height points | not modelled: the rally model has no smash; listed for play |
| half-volley and pick-up | height against the ground and the Volley rating; pace capped | the model's existing pick-up rule (contact under 50 cm shares the Volley rating) |

**Shot type scales the grade's effect.** Each row value moves only a share of its distance from Good: flat 100%, topspin 80%, slice 50%, lob 50%, drop shot 120% on pace-related points. This applies to the pace cap, aim cap, aim Min, error added and the spin row; W_grade is not scaled, because the window is about the ball *(judgement)*. The bonus side is scaled the same way, so flat gains most from VeryGood and Tee-off, and slice least. Engine: the grade-to-row mapping becomes per ShotDef, which means each shot's own rows (data).

### 4g. Writing the incoming pace (S+0x770): re-key the dormant curves

Writing S+0x770 wakes two retail terms that are dormant today (TUNING s12, OPEN 1.10):
- the fault graphs' fast-ball penalty: a ramp from 40 to 60 km/h, reaching -0.6 on control;
- the frame-shot chance (graphs 280-282): up to 0.3 (0.2 for some shots) from 60 to 100 km/h.

Nearly every rally ball is over 60 km/h at contact, so both must be re-keyed in the same change (data). Proposed keys *(judgement, placed at the grade's own pace edges so the two systems agree)*:

| curve | retail keys (dormant) | proposed keys | what it then touches |
|---|---|---|---|
| fast-ball penalty on control (fault graphs) | 40 -> 60 km/h: 0 -> -0.6 | 100 -> 130 km/h: 0 -> -0.6 | the "near reflex limits" pace band (above 100 km/h at contact): returns of first serves above about 100 mph, volleys against hard passes |
| frame-shot chance (graphs 280-282) | 60 -> 100 km/h: 0 -> 0.3 (0.2) | 110 -> 150 km/h: 0 -> 0.10 (0.07) | returns of big first serves and reflex volleys only |

At these keys no groundstroke in the section 2 situation mix is touched: under 0.1% arrive above 100 km/h. A first serve of 120 mph arrives at about 120 km/h.

### 4h. Numbers this spec set or changed in the systems note's tables

| item | systems note | this spec | why |
|---|---|---|---|
| arrival margin edges | 30 / 15 / 0 frames | 30 / 15 / 1 (0 = still moving) | the model's "frames set" is 0 when the player is still moving at contact |
| volley arrival scale | "a volley time scale" | 50 / 36 / 25 frames since the opponent's contact | a volley gets 25-45 frames; tuned in the abuse check (44 / 32 / 22 made the serve-and-volleyer beat every build) |
| height bands | knee / waist / shoulder / head | 50 / 95 / 145 / 185 cm | adult proportions; 95-145 cm is also the Tee-off band |
| pace bands at contact | slow / normal / heavy / near reflex | <= 52 / <= 78 / <= 100 / above (volleys 52 / 80 / 100) | 52 is the Tee-off line; a neutral 72 mph ball arrives at about 67 km/h; 100 km/h is a hard drive or a first serve |
| return, serve, volley, smash families | one scale for all (first run) | s2a: see 4f; slow serve <= 90 mph, reach >= 0.80 placement, jam 8% | owner review: returns of fast serves were Bad/VeryBad on the rally scale |
| shot-type share of the grade | none (first run) | flat 1.0, topspin 0.8, slice 0.5, lob 0.5, drop 1.2 on pace | owner review (s2a) |
| overcharge wait | 25 frames past full | 10 | owner decision after the first run |
| letting a high ball drop | contact at the chosen point | set >= 20 frames, >= 60 frames, 1.2 cm further back per cm of drop | owner clarification |
| Tee-off depth | about 1 m behind the baseline | 100 cm | owner clarification |
| aim caps | 1.18 / 1.12 / 1.00 / 0.82 / 0.59 / 0.35 | unchanged | already the ratios this spec proposed |
| aim row Min | not given | Tee-off 0.30, VeryGood 0.20, others 0 (retail Good row: 0-0.2) | keeps a floor under a top-grade ball |
| pace caps, error added, W_grade | as in the note | unchanged | tested in 2b, 4d, 9b: the averages stay within 1.5% of retail and no build dominates |
| previous spec (replaced) | - | point curves on time, run, height, pace, depth and kick; thresholds Q 0.8 / 2.0 / 3.4 / 5.0; additive pace +9 .. -12 mph, soft caps 108 / 103 / 97 / 89 / 80; error multipliers x0.5 .. x2.5 | superseded by the note's four-input score and ratio caps. Kick and court depth are no longer inputs; a high kick costs only when taken high |

---

## 5. Timing window

Structure: docs/design/retune-systems.md section 3.

Retail: t is 0 at 20 frames before the ball arrives and moves 0.05 per frame. Perfect is |t| < 0.1 (2 frames either side); Good is |t| < 0.3 (6 frames either side). The automatic commit at 12 frames gives t = +0.4, which is late. Every ball uses the same curve.

**The change.** The timing value is divided by a window scale W where it is computed (`fn_8867DF68`, which evaluates t every frame and freezes it at the commit). Everything that reads t then scales with W: the Perfect and Good bands, the fault graphs' forgiveness and the aim efficiency curve.

```
W = clamp( W_rating x W_opp x W_grade x W_react , 0.60 , 1.75 )
Perfect half-width = 2 frames x W        Good half-width = 6 frames x W
zero-error band = retail t -0.60 .. +0.45 at W = 1 (19 frames), scaled by W
```

- **W_rating**: the stroke's rating (Forehand, Backhand, Volley, Return): 0.90 at 40, 1.00 at 70, 1.10 at 100.
- **W_opp**: the opponent's last release, carried on the ball. Perfect 0.85, Good 0.93, average 1.00, poor 1.15, badly mistimed 1.30.
- **W_grade**: from the row (section 4).
- **W_react**: 1.00 at 600 ms or more, falling linearly to 0.70 at 250 ms.
- **Overcharge**: W x 0.80.

Engine notes (Q1 check; now in the systems note):
- The worst/best timing-curve blend cannot carry W. It takes one scalar per shot (TimingAbility S+0xD0C, written by graphs 40-42, each a single curve of one rating) and lerps t-values. W is therefore computed in code and applied by dividing t.
- W_grade must be known before the commit. The grade is currently computed at `fn_886AE528 +0x430`, so the order of the grade and the commit has to be confirmed in code.
- The zero-error band keeps its retail size at W = 1. It is not tied to the Good band, which would cut the error-free zone by about 37% on a neutral ball.
- Aim efficiency and power keep their retail shape against t. Timing picks the position inside the row exactly as the retail graphs already do (section 7).

A human's release error is modelled as normal with sd 3.4 frames *(judgement, swept in 2c)*. In the model, error outside the zero-error band rises 1.6 per unit of t late and 0.8 early. It is weighted by the hold: Finesse 0.5, Medium 1, Powerful 1.5, full 2, overcharge 4 (twice a full charge) *(model calibration of the fault-graph shape; retail: a late full charge errs, Medium does not)*.

### 5a. W in worked cases *(computed; structure retune-systems.md s3)*

W = clamp(W_rating x W_opp x W_grade x W_react, 0.60, 1.75); Perfect half-width 2 x W frames, Good 6 x W; the zero-error band is t -0.60..+0.45 at W = 1 (retail, 19 frames) and scales with W. P = probability for a human with release-error sd 3.4 frames.

| case | time ms | rating x opp x grade x react | W | Perfect half, frames | Good half, frames | zero-error band, frames |
|---|---|---|---|---|---|---|
| retail (no factor) | 1000 | 1.00 x 1.00 x 1.00 x 1.00 | 1.00 | 2.0 (P 0.54) | 6.0 (P 0.94) | 12.0 early / 9.0 late |
| rally ball, opponent hit Good | 1300 | 1.00 x 0.93 x 1.00 x 1.00 | 0.93 | 1.9 (P 0.51) | 5.6 (P 0.93) | 11.2 early / 8.4 late |
| opponent Perfect, heavy ball (Normal) | 1100 | 1.00 x 0.85 x 0.95 x 1.00 | 0.81 | 1.6 (P 0.47) | 4.8 (P 0.88) | 9.7 early / 7.3 late |
| volley against a clean pass: Perfect, 300 ms, Bad | 300 | 1.00 x 0.85 x 0.90 x 0.74 | 0.60 | 1.2 (P 0.38) | 3.6 (P 0.77) | 7.2 early / 5.4 late |
| opponent mistimed, ball came back deep (Good) | 1300 | 1.00 x 1.30 x 1.00 x 1.00 | 1.30 | 2.6 (P 0.64) | 7.8 (P 0.99) | 15.6 early / 11.7 late |
| opponent mistimed, sitter (Tee-off) | 1600 | 1.00 x 1.30 x 1.30 x 1.00 | 1.69 | 3.4 (P 0.75) | 10.1 (P 1.00) | 20.3 early / 15.2 late |
| opponent poor, easy ball (VeryGood) | 1300 | 1.00 x 1.15 x 1.10 x 1.00 | 1.26 | 2.5 (P 0.63) | 7.6 (P 0.98) | 15.2 early / 11.4 late |
| return of a 120 mph serve (Bad), rating 80 | 516 | 1.03 x 1.00 x 0.90 x 0.93 | 0.86 | 1.7 (P 0.49) | 5.2 (P 0.91) | 10.4 early / 7.8 late |
| return of a 145 mph serve (VeryBad), rating 80 | 435 | 1.03 x 1.00 x 0.85 x 0.86 | 0.75 | 1.5 (P 0.45) | 4.5 (P 0.86) | 9.1 early / 6.8 late |
| overcharge on a Tee-off ball, rating 95 | 1900 | 1.08 x 1.00 x 1.30 x 1.00 x 0.80 | 1.13 | 2.3 (P 0.58) | 6.8 (P 0.97) | 13.5 early / 10.1 late |

W_rating: 40: 0.90, 70: 1.00, 100: 1.10 (on the stroke's rating). W_react: 250 ms: 0.70, 600 ms: 1.00. W_opp: Perfect 0.85, Good 0.93, Average 1.00, Poor 1.15, Mistimed 1.30.

### The direct opponent-timing term

The opponent's last release multiplies W for that one shot. It is its own input, independent of how the ball turned out; the ball's character enters through W_grade and W_react. The five levels split the hitter's Good band into Good (inner half) and Average (outer half). It never compounds, because only the last release counts.

### 5c. Sizing the direct opponent-timing term with the rally simulation *(computed, 160 matches per row, elite all-rounder mirror)*

| scale | factor after Perfect / Good / Average / Poor / Mistimed | shots per point | points ended by a timing error | points ended by any error | winners | P(Perfect) after opp. Perfect | after opp. Good | after opp. Poor | P(error) after opp. Perfect | after opp. Poor |
|---|---|---|---|---|---|---|---|---|---|---|
| 0.0 | 1.00 / 1.00 / 1.00 / 1.00 / 1.00 | 6.81 | 0.104 | 0.689 | 0.054 | 0.485 | 0.484 | 0.458 | 0.121 | 0.114 |
| 0.5 | 0.93 / 0.97 / 1.00 / 1.07 / 1.15 | 6.67 | 0.113 | 0.682 | 0.051 | 0.457 | 0.476 | 0.477 | 0.123 | 0.117 |
| 1.0 | 0.85 / 0.93 / 1.00 / 1.15 / 1.30 | 6.53 | 0.121 | 0.666 | 0.054 | 0.433 | 0.466 | 0.500 | 0.123 | 0.117 |
| 1.5 | 0.80 / 0.90 / 1.00 / 1.22 / 1.40 | 6.41 | 0.132 | 0.663 | 0.048 | 0.417 | 0.459 | 0.520 | 0.128 | 0.117 |
| 2.0 | 0.80 / 0.86 / 1.00 / 1.30 / 1.40 | 6.39 | 0.130 | 0.664 | 0.047 | 0.417 | 0.456 | 0.536 | 0.129 | 0.116 |

Scale 1.0 is the owner's starting sizes (Perfect x0.85, Good x0.93, Average x1.00, Poor x1.15, Mistimed x1.30); W clamped to 0.60-1.75; 'after opp. Good' pools the opponent's Good and Average releases.

Recommendation *(computed, then judgement)*: keep the owner's sizes (Perfect 0.85, Good 0.93, Average 1.00, Poor 1.15, Mistimed 1.30) inside the W clamp of 0.60-1.75.
- **Rally length:** against no term, it shortens rallies by 4% (6.81 to 6.53 shots per point, elite mirror).
- **Timing errors:** it raises the share of points ended by a timing error from 10.4% to 12.1%. This is lower than in the first draft (23%), because the retail zero-error band now forgives most releases at W = 1.
- **No snowball.** After an opponent's Perfect, P(Perfect) falls from 0.485 to 0.433, and P(error) rises only from 0.121 to 0.123. After an opponent's Poor release, P(Perfect) rises from 0.458 to 0.500. The term uses only the last release, so it never compounds.
- **Larger sizes buy little:** scale 1.5-2 adds about 1 point of timing-error share and 3% shorter rallies.
- **The 0.60 clamp** binds only on volleys against clean passes and on returns of the fastest serves (5a).

**Carrier.** The hitter's release grade (0-4, from S+0x544 against his own W) is copied onto the ball record or a receiver float beside the PoisonedSlices write (`fn_88695640` already writes #aee2d90b, S+0x7D0, on the receiver from the incoming shot's hitter). That float is read where W is computed. This is new code using a proven hook. Do not reuse S+0x768 (#be5d458f, never written, read by 16 graphs).

---

## 6. Power swing

Structure: docs/design/retune-systems.md section 5.

### 6a. Charge (retail tiers kept), rushed swing and overcharge *(structure retune-systems.md s5; values tuned here)*

| swing | frames held (60/s) | flat row max, Good, Power 75 (mph) | same, Tee-off | timing | vigor per swing (simulation units) |
|---|---|---|---|---|---|
| Finesse | < 12 | 72.7 | 77.9 | retail | 0.002 |
| Medium | 12-52 | 78.9 | 87.4 | retail | 0.004 |
| Powerful | 53-74 | 80.8 | 93.1 | retail | 0.006 |
| Full charge | >= 75 | 82.3 | 97.2 | retail | 0.006 |
| Rushed: still holding at the 12-frame auto-commit, short of Powerful | - | tier reached | tier reached | +1 grade point; commits 8 frames late (t = +0.4 at W = 1) | as the tier |
| Overcharge: held >= 10 frames past full, planted (new state) | >= 85 | 85.6 | 101.0 | W x 0.80; timing error x2 outside the zero-error band | 0.009 (1.5 x full) |

Press-to-contact lead each needs when released 20 frames before contact: Medium 32, Powerful 73, full 95, overcharge 105 frames (1.75 s); holding into the auto-commit gains 8 frames. A human presses about 15 frames after the opponent's contact, so a neutral rally ball (about 80 frames) reaches Medium only, as intended. Of the swings that wanted Powerful and could not reach it, 35 % are held into the auto-commit (judgement).

### 6b. How often the overcharge and the top speeds happen, by the wait past full *(computed, pace specialist, 200000 forehands each, section 2 situation mix)*

| frames past full | overcharges per 1,000 / per match | > 109 mph per 1,000 / per match | at the 110 cap per 1,000 / per match | frames from the opponent's contact on Tee-off balls (median / p90) |
|---|---|---|---|---|
| 25 | 0.07 / 0.014 | 0.24 / 0.048 | 0.10 / 0.020 | 98 / 106 |
| 10 (systems note) | 0.44 / 0.088 | 0.34 / 0.068 | 0.20 / 0.040 | 98 / 106 |
| 0 | 2.28 / 0.456 | 0.81 / 0.161 | 0.74 / 0.149 | 98 / 106 |

**Retail, from G8** (controls-and-shot-selection s18.6, timing-and-fatigue s2b, `data/gameplay/charge_table.yaml`):
- The counter S+0xDFC counts frames from the press until the commit: the release, or the 12-frame auto-commit (PT+0x740).
- power = min(frames / 60, 1.25) / 1.25. Tiers: Medium from 12 frames, Powerful from 53, full at 75. Holding longer does nothing.
- Each Powerful shot adds its PF to SumPowerfulFactor, at 25 per unit, which is about 0.05-0.125 vigor.

Proposal (kept from the systems note, values tuned here):
- **Tiers stay retail** (12 / 53 / 75). Powerful is not reachable on a neutral rally ball, as intended (coordinator ruling): a ball gives about 80 frames from the opponent's contact, and a human presses about 15 frames into them.
- **The payoff moves into the grade.** The tier steps grow above Good (tier share of the row's pace cap: Medium 0.60, Powerful 0.85, full 1.00) and halve below Good. At Power 75, a full charge is worth 4.3% over Medium on Good (retail), 11% on Tee-off and 2% on Bad.
- **Rushed swing.** The player is still holding at the auto-commit and the charge is short of Powerful. Cost: +1 grade point, on top of the retail late commit (8 frames late, t = +0.4 at W = 1). Releasing early at a lower tier is never rushed. In the model, 35% of swings that wanted Powerful but could not reach it are held into the auto-commit *(judgement)*. A hold into the auto-commit that does reach Powerful is late, but not rushed.
- **Overcharge.** Held at least 10 frames past full (85 frames in all), planted; the owner's decision after the first run (it was 25). Effects: pace cap +4%, W x 0.80, timing error doubled outside the zero-error band, stamina 1.5 x a full charge. It needs the press 1.75 s before contact, about 2.0 s from the opponent's contact. *(computed, 6b)* For the pace specialist it happens on 0.44 forehands per 1,000, about once in 11 matches (0.088 per match), against once in 70 with the 25-frame wait. It reaches the 110 cap about once in 25 matches (0.04 per match). The wait is reachable only on balls that give about 2 s: Tee-off balls give a median of 98 frames from the opponent's contact, so most overcharges come from the slowest of them.
- **Swing modes.** AutoSwingGood/Bad change only which categories are offered (G8). The grade is a separate input, and the 12-frame commit stays retail.
- **Code and UI.** The rushed and overcharge states are code. The overcharge needs a visible meter state, which is a UI change (the HUD meter screens are not decoded).

### How Tee-off, overcharge and the put-away relate

| thing | what it is | who decides |
|---|---|---|
| Tee-off | a grade: the ball is a sitter | the situation (the opponent's weak ball) |
| Overcharge | a commitment: the maximum swing | the player |
| Put-away | in retail, a clip with a fixed reward; here, how the top grades look | the grade (section 8) |

They stack only at the top. Tee-off, plus overcharge, plus Perfect, plus a pace build is the 110 mph forehand.

---

## 7. Aim, margin and placement

**Owner decision.** The retail aim system stays as it is:
- the stick is direction-only, and a push to the rim is never penalised;
- nested quads, with Efficiency picking the quad;
- FinalEfficiency (graph 196) with its random roll (aiming.md).

Risk is chosen through shot type, the power hold and the overcharge, not through the stick. This section specifies only how the existing Efficiency is fed:
- (a) the set-up grade, through the grade rows that already exist;
- (b) timing, measured against the new variable window;
- (c) a real Forehand/Backhand contribution;
- (d) the shot type keeps its character;
- (e) DeepDeviation by timing (retune-systems s4).

### 7a. How the existing Efficiency is fed *(proposal; retail chain kept)*

Efficiency = class peak x lerp(AimingResolution.Min, .Max of the grade row, quality); quality = retail timing shape x (0.65 + 0.35 x hand stat); capped at 0.98. Then retail graph 196 (FinalEfficiency, random roll) picks the quad.

| grade | AimingResolution Min | Max | retail row values (Good used for every shot) |
|---|---|---|---|
| Tee-off | 0.30 | 1.18 | none (VeryGood row x code multiplier) |
| VeryGood | 0.20 | 1.12 | 0-0.2 / 0.6-1 |
| Good | 0.00 | 1.00 | 0-0.2 / 0.6-1 |
| Normal | 0.00 | 0.82 | 0 / 0.4-1 |
| Bad | 0.00 | 0.59 | 0 / 0.1-1 |
| VeryBad | 0.00 | 0.35 | 0 / 0.1-1 |

Timing term (retail shape against t, t divided by W): |t| 0: 1.00, 0.1: 0.97, 0.3: 0.88, 0.5: 0.75, 0.8: 0.50, 1.2: 0.25; representative values Perfect 0.98, Good 0.95, Average 0.90, Poor 0.78, Mistimed 0.50 (anchor: a late t = +0.5 FlatPower keeps about 75 % of its peak in retail, G8). Class peaks (retail, kept): TopSpinMedium 0.80, FlatMedium 0.76, FlatFinesse 0.80, SliceMedium 0.76, FlatPower 0.60, DropShot 0.40.

Efficiency, FlatMedium, by grade and timing, hand 0.3 / 0.9 (retail: Good row only; hand 0.3 costs 0.03-0.05):

| grade | Perfect | Good | Average | Poor | Mistimed |
|---|---|---|---|---|---|
| Tee-off | 0.73 / 0.86 | 0.71 / 0.84 | 0.68 / 0.81 | 0.62 / 0.73 | 0.48 / 0.55 |
| VeryGood | 0.67 / 0.82 | 0.65 / 0.79 | 0.63 / 0.76 | 0.56 / 0.68 | 0.42 / 0.49 |
| Good | 0.57 / 0.72 | 0.54 / 0.70 | 0.52 / 0.66 | 0.45 / 0.57 | 0.29 / 0.37 |
| Normal | 0.46 / 0.59 | 0.45 / 0.57 | 0.42 / 0.54 | 0.37 / 0.47 | 0.24 / 0.30 |
| Bad | 0.33 / 0.43 | 0.32 / 0.41 | 0.31 / 0.39 | 0.26 / 0.34 | 0.17 / 0.22 |
| VeryBad | 0.20 / 0.25 | 0.19 / 0.24 | 0.18 / 0.23 | 0.16 / 0.20 | 0.10 / 0.13 |

### 7b. DeepDeviation by timing (retune-systems.md s4; the only timing rule that changes) *(proposal)*

| release | Perfect | Good | Average | Poor | Mistimed |
|---|---|---|---|---|---|
| pull short of the aim, cm (uniform) | 0-40 | 0-110 | 40-150 | 200-300 | 200-310 |

Cm short of the aimed point along the hitter-to-target line. Good is split: inner half of the band 0-110, outer half 40-150. Retail: uniform 0..310 cm (mean 155) inside the band, 200-300 cm outside it. The grade does not enter; a Tee-off ball released late keeps the Perfect pull (no late-timing penalty).

### 7c. Where corner aims land, on the retail aim quads *(computed, 8000 shots per row)*

Stick up-right (deep corner), hitter at (-1188, -50), FlatNormal / TopSpinNormal configs from `aim_tables.yaml`; timing mix Perfect 45%, Good 25%, Average 20%, Poor 8%, Mistimed 2% (a rating-80 player on neutral balls, section 5); hand 0.76. Distances in cm: short of the baseline (1188) and in from the sideline (411). P(error) from the rally model on a neutral ball at the class's typical speed (flat pace raises it).

| class | grade | short of baseline: median (p10-p90) | in from sideline: median (p10-p90) | share within 1 m of both lines | P(error) |
|---|---|---|---|---|---|
| TopSpinMedium | Tee-off | 156 (76-294) | 54 (26-85) | 0.20 | 0.092 |
| TopSpinMedium | VeryGood | 167 (82-302) | 59 (28-89) | 0.17 | 0.100 |
| TopSpinMedium | Good | 191 (101-321) | 68 (36-100) | 0.10 | 0.101 |
| TopSpinMedium | Normal | 221 (124-347) | 80 (45-111) | 0.03 | 0.136 |
| TopSpinMedium | Bad | 261 (153-385) | 97 (56-134) | 0.00 | 0.184 |
| TopSpinMedium | VeryBad | 320 (189-429) | 131 (69-196) | 0.00 | 0.270 |
| TopSpinMedium | retail (Good row) | 306 (162-447) | 87 (52-122) | 0.02 | - |
| FlatMedium | Tee-off | 165 (81-300) | 85 (41-124) | 0.17 | 0.095 |
| FlatMedium | VeryGood | 177 (90-310) | 92 (47-133) | 0.13 | 0.100 |
| FlatMedium | Good | 207 (113-340) | 111 (60-153) | 0.06 | 0.101 |
| FlatMedium | Normal | 243 (140-370) | 133 (76-176) | 0.01 | 0.140 |
| FlatMedium | Bad | 305 (181-417) | 176 (99-224) | 0.00 | 0.184 |
| FlatMedium | VeryBad | 358 (226-467) | 230 (124-283) | 0.00 | 0.269 |
| FlatMedium | retail (Good row) | 320 (176-462) | 128 (78-171) | 0.01 | - |
| FlatPower | Tee-off | 216 (120-341) | 116 (64-156) | 0.05 | 0.102 |
| FlatPower | VeryGood | 226 (127-345) | 122 (69-163) | 0.03 | 0.100 |
| FlatPower | Good | 250 (145-378) | 138 (79-182) | 0.01 | 0.117 |
| FlatPower | Normal | 289 (172-400) | 164 (94-210) | 0.00 | 0.145 |
| FlatPower | Bad | 334 (200-441) | 203 (110-254) | 0.00 | 0.200 |
| FlatPower | VeryBad | 373 (238-472) | 249 (133-300) | 0.00 | 0.276 |
| FlatPower | retail (Good row) | 360 (210-510) | 153 (96-200) | 0.00 | - |

### 7d. Is aiming at the corner on every ball dominant? *(computed, elite mirror, 80 matches per pair)*

Each build is the elite all-rounder with a different share of balls aimed at the deep corner (the rest at safer directions). The stick is direction-only, so the corner costs no error in the agreed rules. Row: field share.

| receiver anticipation | corner 0 % | 25 % | 50 % | 75 % | 100 % |
|---|---|---|---|---|---|
| 0.00 | 0.069 | 0.278 | 0.503 | 0.725 | 0.925 |
| 0.35 | 0.231 | 0.613 | 0.666 | 0.603 | 0.387 |

### 7e. Angle access (fraction of the sideline reach usable) *(proposal)*

| position (rating 80) | Tee-off | VeryGood | Good | Normal | Bad | VeryBad |
|---|---|---|---|---|---|---|
| 4 m inside | 0.94 | 0.89 | 0.80 | 0.70 | 0.56 | 0.42 |
| 1.5 m inside | 0.87 | 0.82 | 0.74 | 0.65 | 0.52 | 0.39 |
| on the baseline | 0.77 | 0.73 | 0.66 | 0.58 | 0.46 | 0.35 |
| 2 m behind | 0.67 | 0.64 | 0.57 | 0.51 | 0.40 | 0.30 |
| 4 m behind | 0.58 | 0.55 | 0.49 | 0.43 | 0.35 | 0.26 |

### 7f. Drop shot quality against the incoming ball (touch rating 70) *(proposal)*

| incoming | grade | timing | lands cm past the net | bounce height cm | P(error) |
|---|---|---|---|---|---|
| slow, mid-height, inside the court | VeryGood | Perfect | 181 | 35 | 0.02 |
| slow, mid-height, inside the court | VeryGood | Good | 211 | 38 | 0.04 |
| slow, mid-height, inside the court | VeryGood | Poor | 291 | 58 | 0.14 |
| neutral rally ball | Good | Perfect | 247 | 48 | 0.10 |
| neutral rally ball | Good | Good | 277 | 56 | 0.13 |
| neutral rally ball | Good | Poor | 357 | 76 | 0.27 |
| hard drive | Normal | Perfect | 343 | 78 | 0.25 |
| hard drive | Normal | Good | 373 | 85 | 0.29 |
| hard drive | Normal | Poor | 453 | 105 | 0.47 |
| low slice | Good | Perfect | 229 | 42 | 0.16 |
| low slice | Good | Good | 259 | 50 | 0.19 |
| low slice | Good | Poor | 339 | 70 | 0.33 |
| on the run | Bad | Perfect | 405 | 88 | 0.20 |
| on the run | Bad | Good | 435 | 96 | 0.25 |
| on the run | Bad | Poor | 515 | 116 | 0.51 |

Retail drop shot (row 32): one speed (55 km/h), P(error) 0 at t = 0 and 0.32-0.68 off it, independent of the incoming ball (retune-baseline 3b).

**How switching the grades on changes Efficiency (a).**
- `fn_886629C8` already copies `ShotDef[i].ShotResolution.AimingResolution[grade]` (S+0x6C4 / 0x6C8 for the `6ebe237b` pair) and `ErrorResolution[grade]` (S+0x6D4) by the Control swing key S+0x3B8. Retail only ever sets that key to Good (OPEN 1.9).
- Writing the section 4 grade into S+0x3B8 (and S+0x3B4 for power) makes each shot read its grade row. No graph changes for that step.
- The aiming graphs read the row's Min and Max (S+0x6C4 / 0x6C8) together with ManualShotTiming S+0x544 (graphs-catalogue), so the position inside the row is picked by the graphs: data, not code. The row Max is the grade's aim cap times the retail Good Max (7a).
- Tee-off has no row of its own: it uses the VeryGood row times a code multiplier (ShotResolution has five rows).
- The second pair (`b3a1d456`) is read by some aiming graphs. Its meaning is not confirmed (I: the DeepDeviation range); if it is, (e) becomes a pure data edit of that pair.

**Timing (b).** The aiming graphs' timing input stays ManualShotTiming, with its retail shape (coordinator ruling: the shape is kept).
- Because t is divided by W where it is computed (section 5), the shape automatically follows the variable window. No further rescale or graph edit is needed.
- The model's shape, against |t| after the division, is 1.00 at 0, 0.97 at 0.1, 0.88 at 0.3, 0.75 at 0.5, 0.50 at 0.8 and 0.25 at 1.2 *(judgement through the retail anchor: a late +0.5 FlatPower keeps 0.45 of its 0.60 peak, G8)*.

**Hand rating (c).**
- Quality is multiplied by 0.65 + 0.35 × hand stat. Between hand 0.3 and 0.9 a Good perfect FlatMedium goes from 0.57 to 0.72 (retail: 0.03-0.05).
- This is data: the aiming graphs' hand lerp, or a curve on HandAttributeQuality S+0x74C.

**Shot type (d).**
- Class peaks stay retail: TopSpinMedium 0.80, FlatMedium 0.76, FlatPower 0.60, DropShot 0.40. A flat drive lands further from the lines than a topspin drive at the same grade.
- Flat pace raises the out chance: pace error 0.3 pp per mph above the class's margin speed, which scales with the row's pace cap (a Tee-off ball's margin is 18% higher).

**DeepDeviation (e).** By timing only (7b; the one timing rule that changes):
- Perfect: 0-40 cm;
- Good: up to 150 cm (inner half of the band 0-110, outer half 40-150);
- outside Good: the retail 2-3 m.

It is a data edit of each aiming graph's DeepDeviation branch, narrowing its Random range by the timing value. A poor timing therefore marks the ball twice: the receiver's W_opp widens, and the short result usually earns him a better grade.

**Is the corner on every ball dominant? (7d)**
- Under the agreed rules a corner aim costs no error, as in retail: the In target is clipped to the lines, and the Out roll does not read the direction.
- In the rally model, a player who aims at the corner on every ball therefore wins 92% of matches against the field of corner shares, when the receiver does not adapt.
- It stops being dominant only through the receiver reading the habit (anticipation 0.35: a predictable corner aim is reached with 35% less running, and a safe ball then catches the cheat):
  - the always-corner player falls to 39%;
  - the best share becomes 25-50% (field shares 0.61 / 0.67).
- For human opponents this is ordinary play. For the AI it is a requirement: the AI's positioning must weight the hitter's corner tendency. That is AI work, outside this spec, and listed under play.
- If the owner wants a rule-side counter as well, the model has one option, not proposed: LINE_RISK, extra error per unit of a corner aim's FinalEfficiency. It would contradict "risk through shot type, hold and overcharge", and even 12 pp only cut the always-corner share against 50% from 0.98 to 0.72 in a test run.

**Spin types** (section 2 constants plus RALLY):

| spin | what it buys | what it costs |
|---|---|---|
| Topspin | margin: no pace error below 84 mph against 81 for flat; kick +0.20 plus 0.14 × hand stat on the receiver's grade and window; aim peak 0.80 | 5 mph less pace; a cap 4 mph lower |
| Flat | the most pace | the least margin: pace error 0.3 pp per mph above its margin speed; FlatPower aim peak 0.60 |
| Slice | stays low (receiver's contact 50 cm lower); slows after the bounce (out/in 0.72); driving a low ball costs 0.4 pp per mph above 70 | the least pace |

Spin scales with the hand rating: kick_hand 0.14, and the margin speed rises 10 mph per unit of hand stat.

---

## 8. Net play

**Owner direction.** The main cost of a difficult volley is a weak, attackable ball, not an error.
- Volley quality maps onto the outputs volley shots already have:
  - pace (PowerfulFactor);
  - how far out the aim box reaches (Efficiency);
  - how far short the ball is pulled (DeepDeviation);
  - how high it floats (template apex or flight time).
- Volley quality is built from: ball height against the net, time to react, incoming pace, timing and the Volley rating.
- No new systems: the existing volley classes (standard, power, drop, slice, each keeping its job), their graphs, the aim boxes and the grade.
- The only code is feeding incoming pace (S+0x770) and reaction time (S+0xCF0), and writing the grade (S+0x3B8 / 0x3B4).

### 8a. Approach quality against the passer's grade and window *(computed)*

| approach | passer's frames | passer's grade | score | Perfect / Good half (rating 70) | passer's Efficiency (FlatMedium, Perfect) | angle access |
|---|---|---|---|---|---|---|
| deep (1 m from baseline), low skid, 80 mph | 70 | Good | 2 | 2.0 / 6.0 | 0.65 | 0.57 |
| deep, high bounce, 70 mph | 78 | Good | 1 | 2.0 / 6.0 | 0.65 | 0.58 |
| mid-court (4 m inside the baseline), 70 mph | 74 | Good | 1 | 2.0 / 6.0 | 0.65 | 0.67 |
| short (service line), sitting up | 95 | Tee-off | -1 | 2.6 / 7.8 | 0.80 | 0.91 |
| deep to the corner, opponent stretched | 66 | Bad | 5 | 1.8 / 5.4 | 0.39 | 0.42 |

### 8b. Volley quality bands: the cost of a hard volley is a weak reply *(proposal; judgement values)*

Band = volley grade (Tee-off / VeryGood 1, Good / Normal 2, Bad 3, VeryBad 4) + timing (Poor +1, Mistimed +2), then one band better with probability (Volley stat - 0.5) / 0.5. Outputs are the volley classes' existing outputs.

| band | ball and result | pace mph (PF) | Efficiency (aim box reach) | DeepDeviation cm | apex over the net m | error | put-away (VolleyPower; x0.6 standard) |
|---|---|---|---|---|---|---|---|
| 1 | soft or high ball above the net with time: fast, low, to the corner or angled; drop volley dies | 70 (+10 VolleyPower) | 0.85 | 40 | 0.3 | 0.01 | 0.28 |
| 2 | firm ball at a comfortable height: solid and deep, returnable | 62 (+10 VolleyPower) | 0.65 | 120 | 0.6 | 0.02 | 0.06 |
| 3 | hard ball with little time, or dipping below the net: slower, mid-court, hangs | 57 | 0.40 | 320 | 1.2 | 0.03 | 0.00 |
| 4 | hard and low at the feet, or stretched: pop-up or short sitter, sometimes net or long | 34 | 0.20 | 480 | 2.5 | 0.10 | 0.00 |

Overreach: a VolleyPower on a ball contacted below 90 cm or faster than 100 km/h adds 0.30 error. Below net height the pace is capped at 50 mph (it must be lifted). Drop and slice volleys keep their classes' jobs.

What each band hands the passer (the reply's grade at the opponent, rating 80, from the rally model's ball-to-situation map):

| band | passer Tee-off | passer VeryGood | passer Good | passer Normal | passer Bad | passer VeryBad |
|---|---|---|---|---|---|---|
| 1 | 0.00 | 0.07 | 0.35 | 0.02 | 0.55 | 0.01 |
| 2 | 0.00 | 0.21 | 0.30 | 0.00 | 0.48 | 0.00 |
| 3 | 0.00 | 0.36 | 0.33 | 0.00 | 0.31 | 0.00 |
| 4 | 0.69 | 0.15 | 0.00 | 0.14 | 0.02 | 0.00 |

### 8c. Rushing the net: every point against a set passer, and behind a good approach *(computed, elite mirror, 60 matches each)*

| net player | match win share vs a baseline mirror | points won: serve-volley | after a good approach (VeryGood+ and deep) | after another approach |
|---|---|---|---|---|
| rushes every point (serve-volley and every short ball) | 0.12 | 0.364 (3404) | 0.637 (1039) | 0.515 (1281) |
| comes in only on short balls (default) | 0.58 | - | 0.550 (518) | 0.494 (1496) |

Real approaches: about 65-70% won (section 1).

**How the bands map onto the engine.**
- Band 1-2 use the Good and VeryGood AimingResolution, PowerResolution and ErrorResolution rows of each volley ShotDef. Band 3-4 use the Normal, Bad and VeryBad rows. These are data edits to the values in 8b.
- The apex is the volley template rows' Apogee secondary weight, which the PowerResolution range moves (data). Section 3a shows the retail volley row at 0.30 m clearance.
- The "below net height caps pace" rule is a contact-height (Ball+0x344) term on the volley power graphs (data).
- Overreach is the VolleyPower fault graph reading contact height and incoming pace (data, once S+0x770 has its writer).
- The Volley rating's one-band shift is the volley graphs' Volley input (S+0x65C), so no new rating is involved.

**Reading** *(computed)*:
- **Each band hands the passer the intended ball (8b, second table):**
  - band 4 gives him a Tee-off about two times in three;
  - band 3 gives him VeryGood or Good 69% of the time (he steps in);
  - band 1 leaves him Bad or worse 56% of the time, band 2 48%.
- **Errors come mainly from overreach:** 1-3% in bands 1-3, 10% in band 4, plus 30% for a power volley on a low or blistering ball.
- **Rushing the net (8c):**
  - A player who rushes on every point (serve-volley and every short ball) wins 12% of matches against a baseline mirror. His serve-volley points are won 36% of the time, so he loses clearly to a set passer. (Second run, without the volley base error: 25% and 41%.)
  - Behind a good approach (VeryGood or better, and deep) net points are won 55-64%; behind other approaches 49-52%. Real approaches win 65-70% *(sourced)*.
  - The default row is a mirror (the same player on both sides); its 0.58 is sampling noise at 60 matches (sd about 0.06).
  - The serve-and-volley build itself (Volley 95, Serve 90) is 0.48 against the field (9b): net play pays with the ratings for it, without dominating.
- **The passer's view (8a).** The approach decides the passer's grade:
  - a deep corner approach that stretches the passer leaves him Bad (Efficiency 0.39, angle access 0.42);
  - deep or mid-court approaches without a stretch leave him Good;
  - a short approach that sits up hands him a Tee-off when he is planted near it in time.
- **The put-away is folded into the top grades** (structure: retune-systems.md s6).
  - Retail: the put-away is the Fatality category, row 0 of FlatPower, needing power > 0.15. Its 37 clips are all forehand, shoulder height.
    - It pins PF (0.85 Medium, 0.80 Powerful) and removes the late-timing aim penalty, a consistency bonus that ignores the ratings.
    - Holding RB inside the central |z| < 300 cm corridor blocks it (FollowNet wins), so low balls, backhands, topspin and lobs never get it (movement-and-animation s8.3).
  - Proposal: the reward belongs to the grade. A Tee-off ball gets the Tee-off pace cap (x1.18), aim cap (x1.18), W x 1.30 and no added error, whichever clip fits.
    - On Tee-off and VeryGood power swings the put-away clip set is tried first, on every stroke. The 37 clips play when they fit.
    - Where they do not fit (a low ball, the backhand), existing power-swing clips for that height and side are marked eligible and play instead. No clip is edited.
  - The fixed PF pin is dropped: pace comes from the row and the timing.
  - The "no late-timing aim penalty" is kept for Tee-off only, as part of its forgiveness. In the model, a late release on a Tee-off ball keeps the Perfect aim position and the 0-40 cm depth pull; pace and error still follow the real timing.
  - The sprint-corridor block is removed (code).
  - Data: the put-away clip eligibility and rule order. Code: the corridor test in the Fatality condition `0xC78C8F06`.
  - At the net, a volley Tee-off needs the -1 pace point: a ball slower than 52 km/h at contact, above 110 cm, with 30+ frames. That is now rare (4d). Net winners come from band-1 volleys (VolleyPower), whose put-away chance is unchanged.
- **Retail has no volley error** at any timing or height (baseline 3c and 7b). The cost of a bad volley there is nothing at all; here it is the ball it hands over.
- **Model fix.** Volleys were wrongly graded as stretched before the net lunge was applied. The stretch is now re-tested after the lunge.
- **Net clearance** targets are in 3a: flat rally 1.0-1.2 m, firm 0.75 m, big 0.25 m; topspin 1.1-2.2 m. Retail flat Powerful at median stats is 0.87 m.
- **Drop shots and chips:** see 7f. Their landing and height now depend on the incoming ball; retail's drop shot ignores it.

---

## 9. Stats, skills, and the abuse check

### 9a. Rating -> stat, retail and proposed, and the floor penalty *(proposal)*

| rating | retail forehand | retail power | proposed (every stat) | floor penalty (0..1) |
|---|---|---|---|---|
| 0 | 0.00 | 0.00 | 0.00 | 1.00 |
| 10 | 0.00 | 0.00 | 0.06 | 0.79 |
| 20 | 0.00 | 0.00 | 0.12 | 0.59 |
| 25 | 0.00 | 0.00 | 0.15 | 0.50 |
| 30 | 0.00 | 0.00 | 0.18 | 0.41 |
| 40 | 0.10 | 0.15 | 0.29 | 0.24 |
| 50 | 0.20 | 0.30 | 0.40 | 0.10 |
| 60 | 0.30 | 0.40 | 0.52 | 0.00 |
| 70 | 0.52 | 0.50 | 0.64 | 0.00 |
| 80 | 0.75 | 0.65 | 0.76 | 0.00 |
| 90 | 0.88 | 0.83 | 0.88 | 0.00 |
| 100 | 1.00 | 1.00 | 1.00 | 0.00 |

**Proposed rating curve.** Linear from 0.18 at rating 30 to 1.0 at 100, and 0.06 per 10 points below 30.
- There is no dead zone. Retail maps every rating up to 30 to 0, and both retail Forehand and Power curves stay low until about 60 (baseline 5a).
- Below 60 a floor penalty ((60 - r) / 60)^1.3 adds error or failure on that stroke's own job:
  - Serve: -0.50 × floor on P(in);
  - Return: +0.30 error;
  - each groundstroke and the volley: +0.20 error.
- A dumped rating therefore costs more than the points it frees.
- This is a code change in the rating-to-stat curves, unless the stat graphs accept a new curve (data) *(judgement)*.

### 9b. Abuse check: head-to-head match win share, equal 600-point rating budgets *(computed, 160 best-of-3 matches per pair)*

| build | Serve | Return | FH | BH | Volley | Power | Speed | Stamina |
|---|---|---|---|---|---|---|---|---|
| heavy topspin | 70 | 70 | 90 | 80 | 55 | 70 | 80 | 85 |
| flat hitter | 75 | 70 | 85 | 80 | 60 | 95 | 65 | 70 |
| slicer | 65 | 75 | 70 | 85 | 80 | 65 | 80 | 80 |
| big server | 100 | 60 | 75 | 65 | 70 | 90 | 60 | 80 |
| serve-and-volleyer | 90 | 65 | 65 | 60 | 95 | 75 | 80 | 70 |
| counterpuncher | 60 | 85 | 75 | 80 | 55 | 55 | 95 | 95 |
| min-max: no legs (speed, stamina dumped) | 100 | 100 | 100 | 100 | 50 | 100 | 25 | 25 |
| min-max: no serve, no volley | 25 | 50 | 100 | 100 | 25 | 100 | 100 | 100 |
| min-max: no backhand, no return | 100 | 25 | 100 | 25 | 50 | 100 | 100 | 100 |

| row beats column | heavy topspin | flat hitter | slicer | big server | serve-and-voll | counterpuncher | mm: no legs (s | mm: no serve,  | mm: no backhan | field share |
|---|---|---|---|---|---|---|---|---|---|---|
| heavy topspin | - | 0.49 | 0.29 | 0.49 | 0.34 | 0.33 | 1.00 | 0.99 | 0.97 | 0.613 |
| flat hitter | 0.51 | - | 0.31 | 0.52 | 0.73 | 0.35 | 1.00 | 1.00 | 0.98 | 0.675 |
| slicer | 0.71 | 0.69 | - | 0.62 | 0.51 | 0.53 | 1.00 | 1.00 | 0.99 | 0.757 |
| big server | 0.51 | 0.48 | 0.38 | - | 0.57 | 0.42 | 1.00 | 1.00 | 0.98 | 0.668 |
| serve-and-voll | 0.66 | 0.27 | 0.49 | 0.43 | - | 0.58 | 0.98 | 0.99 | 1.00 | 0.673 |
| counterpuncher | 0.68 | 0.65 | 0.47 | 0.57 | 0.42 | - | 1.00 | 1.00 | 0.99 | 0.723 |
| mm: no legs (s | 0.00 | 0.00 | 0.00 | 0.00 | 0.02 | 0.00 | - | 0.63 | 0.73 | 0.173 |
| mm: no serve,  | 0.01 | 0.00 | 0.00 | 0.00 | 0.01 | 0.00 | 0.37 | - | 0.22 | 0.076 |
| mm: no backhan | 0.03 | 0.02 | 0.01 | 0.02 | 0.00 | 0.01 | 0.27 | 0.78 | - | 0.142 |

Among the six intended styles only (min-max builds removed): field share heavy topspin 0.389, flat hitter 0.484, slicer 0.614, big server 0.472, serve-and-volleyer 0.484, counterpuncher 0.557.
Builds that beat every other build: slicer.
Runtime 106 s.

### 9d. Hold and break against the systems note's targets (s2a) *(computed, 100 best-of-3 matches per row)*

Serve specialist = the big-server build; all-rounder = Serve 75, Return 75, FH 80, BH 75, Volley 70, Power 75, Speed 75, Stamina 75 (600 points). Targets: the specialist holds about 90%, breaks 10-15%; the all-rounder holds 80-85%, breaks about 20%; their matches close to even, decided in tie-breaks.

| match | first player holds | first player breaks | second player holds | first player's match share | tie-breaks per set | shots per point | server points won |
|---|---|---|---|---|---|---|---|
| specialist vs all-rounder | 0.786 | 0.205 | 0.795 | 0.440 | 0.23 | 5.76 | 0.628 |
| all-rounder mirror | 0.748 | 0.274 | 0.726 | 0.550 | 0.16 | 6.35 | 0.604 |
| specialist mirror | 0.840 | 0.191 | 0.809 | 0.570 | 0.22 | 5.23 | 0.648 |

### 9e. What each shot type is used for when the ball is bad *(computed, elite mirror, 50 matches, groundstrokes)*

| grade | Flat: share / P(error) | TopSpin | Slice | Lob |
|---|---|---|---|---|
| Tee-off | 0.91 / 0.103 | 0.09 / 0.102 | - | - |
| VeryGood | 0.35 / 0.096 | 0.52 / 0.096 | 0.13 / 0.096 | - |
| Good | 0.35 / 0.101 | 0.53 / 0.097 | 0.12 / 0.095 | - |
| Normal | 0.36 / 0.135 | 0.53 / 0.127 | 0.11 / 0.116 | - |
| Bad | 0.01 / 0.221 | 0.44 / 0.160 | 0.46 / 0.136 | 0.10 / 0.135 |
| VeryBad | - | 0.41 / 0.218 | 0.47 / 0.171 | 0.12 / 0.172 |

Shot-type share of the grade's effect (s2a): Flat 100%, TopSpin 80%, Slice 50%, Lob 50%, Drop 120%.

Reading of 9d *(computed; targets from retune-systems s2a; final run with both hold levers)*:
- **Specialist against all-rounder:** the specialist holds 78.6% and breaks 20.5%; the all-rounder holds 79.5% and breaks 21.4%. The specialist wins 44% of their matches, with 0.23 tie-breaks per set: close to even, as the target asks (sampling noise about ±0.05). Second run: holds 76% / 71.5%, specialist breaks 28.5%, match share 0.63.
- **Mirrors:** the all-rounder holds 73-75%, the specialist 81-84%.
- **Still short:** the specialist's hold (target about 90%) by 6-11 points, his break of the all-rounder (target 10-15%) by 5-10 points, and the all-rounder's hold in the mirror (target 80-85%).
- **Why:** server points won is 60-65%. A game is held 71% of the time at 59% of points, 78% at 62%, 85% at 66% and 90% at 70% *(computed, the standard game formula)*. A 90% hold needs about 70% of points, above the tour's 62-64% but normal for the biggest real servers. The serve model gives 34-37% unreturned first serves (tour 38%), so the remaining gap is in the server's first rally shot.
- **What the levers did:** together they raised server points won by 2-3 points and moved the specialist-against-all-rounder match from 0.63 to 0.44. Lever 2 also costs the dumped-Return min-max build (0.25 -> 0.14 against the field).

Reading of the style matrix (9b, final run: s2a family grades and shot-type shares, volley base error 0.03, both hold levers):
- **The slicer beats every other build, narrowly.** Its field share is 0.614; it beats heavy topspin 0.71, the flat hitter 0.69 and the big server 0.62, but the serve-and-volleyer (0.51) and the counterpuncher (0.53) only within the sampling noise (about ±0.04 at 160 matches). The design property "no build beats every other" therefore fails at the edge of the noise.
- The six styles are 0.39-0.61 against each other: slicer 0.614, counterpuncher 0.557, flat hitter 0.484, serve-and-volleyer 0.484, big server 0.472, heavy topspin 0.389. That spread is narrower than both earlier runs (first 0.39-0.57, second 0.36-0.66).
- **History of the three runs.**
  - First run: big server on top (0.573), flat hitter weakest (0.386). Cause: returns graded on the rally scale.
  - Second run (s2a family grades, shot-type shares): serve-and-volleyer on top (0.659), heavy topspin weakest. Cause: the base error charged on groundstrokes only.
  - Final run (volley base error 0.03, hold levers): the serve-and-volleyer falls to 0.484 and the big server to 0.472; the slicer (0.614) and the counterpuncher (0.557) rise, because the hold levers weaken returns and rallies now cost the net player too.
- **The flat hitter is not the weakest** (0.484, mid-field). **Slice has a real use when stretched** (9e): on Bad balls slice is 46% of shots with P(error) 0.136, against topspin 0.160 and flat 0.221; on VeryBad balls 0.171 against 0.218.
- **Heavy topspin is the weakest style** (0.389): topspin keeps only 80% of the bonus on VeryGood and Tee-off balls, and its long rallies meet the situation base error. A lever, not tested: topspin's grade share 0.8 -> 0.9, or slice's 0.5 -> 0.6-0.7 for the slicer *(judgement)*.
- Cycles (9b): flat hitter beats serve-and-volleyer (0.73), serve-and-volleyer beats counterpuncher (0.58), counterpuncher beats flat hitter (0.65); big server beats serve-and-volleyer (0.57), counterpuncher beats big server (0.57).
- Every min-max build still pays heavily: none takes more than 0.03 from any style. Against the field (min-max builds included) "no legs" wins 17%, "no serve, no volley" 8%, "no backhand, no return" 14% (hold lever 2 costs the dumped Return).
- Balancing history *(model calibration, judgement)*. Earlier, after the owner's aim, floor, Tee-off and volley decisions:
  - flat pace margin 78 -> 81 mph;
  - Powerful-swing vigor cost 0.008 -> 0.006;
  - volley width x0.85, from the narrower volley aim configs;
  - topspin kick per unit of hand stat 0.18 -> 0.14;
  - band-1 put-away 0.40 -> 0.28;
  - the Volley rating's band shift made probabilistic, (stat - 0.5) / 0.5, instead of a step at 0.70.
- Model fix: the serve-and-volleyer's first volley is taken low (55 cm average) on the move.
- After moving to the systems note's structure, the serve-and-volleyer beat every build (field share 0.82). The causes: the volley grade scored too many volleys Good, and passing shots carried the old pass error. Retuned:
  - volley arrival edges 44 / 32 / 22 -> 50 / 36 / 25 frames;
  - volley pace edges 85 / 110 -> 80 / 100 km/h;
  - passing error against a net player 0.03 -> 0.01;
  - slice drop at the receiver 72 -> 50 cm, because the height points made the slicer too strong;
  - pace error 0.006 -> 0.003 per mph, because the retail Good rows already carry the pace;
  - situation base error on every groundstroke (new): 0.05 in the first run, 0.09 in the second (see the first table in this document).
- Final run, model fixes (first table in this document): situation base error 0.03 on every volley; a Bad or VeryBad return grade lowers the return ball one step; return error +0.30 per unit of Return stat below 0.80.

### 9c. Robustness: field share of the six styles when one rule moves by +-20 % *(computed, 80 matches per pair)*

| rule | change | best style (field share) | worst style | beats every other |
|---|---|---|---|---|
| pace error per mph | x0.8 | slicer 0.61 | heavy topspin 0.40 | none |
| pace error per mph | x1.2 | slicer 0.63 | heavy topspin 0.41 | slicer |
| slice drop | x0.8 | slicer 0.61 | heavy topspin 0.39 | slicer |
| slice drop | x1.2 | slicer 0.66 | heavy topspin 0.39 | none |
| Speed stat run value | x0.8 | slicer 0.65 | heavy topspin 0.37 | slicer |
| Speed stat run value | x1.2 | slicer 0.65 | heavy topspin 0.34 | none |
| power-swing vigor cost | x0.8 | slicer 0.62 | heavy topspin 0.38 | none |
| power-swing vigor cost | x1.2 | slicer 0.64 | heavy topspin 0.37 | slicer |
| pass error vs net player | x0.8 | slicer 0.62 | heavy topspin 0.37 | none |
| pass error vs net player | x1.2 | slicer 0.64 | heavy topspin 0.41 | none |
| topspin kick per hand | x0.8 | slicer 0.63 | heavy topspin 0.35 | none |
| topspin kick per hand | x1.2 | slicer 0.66 | heavy topspin 0.38 | slicer |
| floor error | x0.8 | slicer 0.63 | heavy topspin 0.35 | slicer |
| floor error | x1.2 | slicer 0.64 | heavy topspin 0.37 | slicer |
| base situation error | x0.8 | counterpuncher 0.65 | serve-and-volleyer 0.38 | slicer |
| base situation error | x1.2 | serve-and-volleyer 0.59 | heavy topspin 0.34 | none |

Reading of 9c (final run):
- **The slicer is the best style in 14 of 16 variants** (0.61-0.66) and beats every other style in 8 of them, as in the default matrix. The counterpuncher is best at base error x0.8 (0.65) and the serve-and-volleyer at base error x1.2 (0.59).
- **No other style dominates any variant.** The serve-and-volleyer's lead of the second run (best in 15, dominant in 4) is gone: the volley base error removed it, as the second-run probe predicted.
- **Heavy topspin is the weakest style in 15 of 16 variants** (0.34-0.41); the serve-and-volleyer is the weakest at base error x0.8 (0.38).
- **Spread:** best minus worst is 0.21-0.31, narrower than the second run (0.23-0.40).
- The slicer's narrow dominance is the open balance item. Its likely source is slice keeping only 50% of a bad grade's cost (9e). Slice drop is not the cause: x0.8 and x1.2 both leave the slicer on top. Not tested: slice share 0.6-0.7.

The design property to keep, and to re-measure after every change, is "no build beats every other build". The robustness table's last column checks it.

### Skills

The baseline 5c measured effects are kept or resized as follows *(judgement)*.

| skill | retail measured effect (baseline 5c) | proposal | cost / counter |
|---|---|---|---|
| InstantRocket, HighlyFlammable, ApproachShotsExpert, CrushingPassingShot | PF +0.04 to +0.16 (about 3-12 km/h) on power rows | one "pace" skill class: +2% on Powerful or harder swings only (SKILL_PACE), the last step of the stack | matters most on Tee-off; it can take the pace build to 108.6 mph without an overcharge (section 2); vigor costs unchanged |
| ReachSwingsExpert | aim +0.40, depth -178 cm, fault -0.34, PF +0.19 on stretched balls | halve it: a reach swing scores 3 arrival points instead of 4 | the reach clip's long tail (median 45 frames) is kept |
| SemiVolleyKing | aim +0.60, depth -372 cm, PF +0.26 | cap at -150 cm and aim +0.25 on half-volleys; keeps the no-man's-land penalty at least Normal grade | needs the S+0x7D8 frames-since-bounce writer (code) |
| PassingShotSniper | aim +0.40, depth -288 cm | aim +0.15 against a net player; pass error 0.07 -> 0.04 | none |
| BetterOnLongRallies, TenaciousCockroach | fault -0.90 / -0.11 | -0.05 error after shot 8 / when trailing | none |
| Amazing1stVolley, BrutalVolley, VolleyShotsArtist, LowVolleySpecialist | aim ±0.2, fault -0.10 to -0.35 (on top of zero retail volley error) | volley window ×1.10, low-volley height penalty -30% | now meaningful, because volleys can fail |
| DieselServer, FocusService, SpinServeMaster, ServeStickBerserker | aim +0.10 to +0.20 | P(in) +3 pp at the same speed, or +3 mph at the same P(in) (pick one per skill) | stamina cost unchanged |
| PoisonedSlices | receiver S+0x7D0 = 1 | keep, and reuse its code path to carry the opponent's timing grade (section 5) | none |
| DropShotArtist | fault -0.30 / -0.38 | drop landing -40 cm and error ×0.7 | none |

---

## 10. Movement

**Owner decisions (2026-11-14).** Movement stays as retail except the agreed rule changes.

Agreed:
- net rush buffered instead of refused, with no sprint requirement;
- the pre-hit freeze lifted at the net only;
- feet freed earlier after volleys and approach shots only, at about half of today's tails (volley 38 -> 19 frames, approach groundstroke 36 -> 18, FollowNet 29 -> 15).

Kept as retail:
- the first step from rest;
- stop and reversal momentum and sprint behaviour;
- the sideways-push cancel and the 12-frame commit;
- groundstroke, return and serve tails.

No animation is edited:
- The earlier tails are an earlier legal exit into locomotion. That is code, or data if TransitionEvent[1].Position is moved, which changes no pose.
- The put-away uses existing clips, selected differently.

The earlier draft's replacement of the 36-frame groundstroke lock is withdrawn.

Engine facts are from movement-and-animation s7-s8, movement-and-ai E and `data/gameplay/root_motion.yaml`.

### 10a. Kept as retail and agreed rule changes *(engine facts sourced from the movement docs)*

| item | retail (engine docs) | decision |
|---|---|---|
| first step from rest | 5 cm after 2-21 frames by clip; Rush_Front 14-18 frames to 5 cm, 42-43 to 1 m | kept as retail |
| net rush | refused when the opponent's hit is < 20 frames away (condition 7); needs RB / box and sprint | agreed: buffered (starts as soon as allowed), no sprint requirement (code, fn_8869B928) |
| pre-hit freeze | direction latched for the last 20 frames before the opponent's hit; release at -20..-11 stops dead | agreed: lifted at the net only, x > -500 cm (code, fn_8866F740); kept elsewhere |
| volley and approach-shot tails | 38 (volley), 36 (approach groundstroke), 29 (FollowNet) frames to the Out window | agreed: about half, 19 / 18 / 15 |
| groundstroke / return / serve tail | Out window 36 / 26 / 34 frames after contact (median) | kept |
| put-away | FH shoulder-height Fatality clips only; blocked by RB in the |z| < 300 cm corridor | existing low and backhand clips made selectable (selection rule, no clip edits); corridor block removed (code) |
| stops, reversals, sprint, sideways-push cancel, 12-frame commit | stops 35-91 frames to still; reversals 39-96 frames back past the turn | kept as retail |

### 10b. What the agreed changes do against the passer's reply *(computed, judgement inputs)*

x = distance from the net (cm) when the opponent hits and when his ball reaches the player; free = frames of steering before the ball arrives (the freeze latches the last 20 before the hit; with the agreed change it is lifted when the player is inside 500 cm of the net as it would start). Rush from rest as retail; root drift in the tail scales with its length. Reply and ball-back frames are judgement (ball speeds from sections 2-3).

| exchange | reply / ball-back frames | retail | buffered rush + freeze lifted at the net | all agreed changes (with the shorter tails) |
|---|---|---|---|---|
| approach from 6 m behind the net, passer at the baseline | 47 / 34 | tail 36: -524 / -464 cm, free 0 | tail 36: -521 / -405 cm, free 0 | tail 18: -524 / -270 cm, free 9 |
| approach with a FollowNet clip (RB), same exchange | 47 / 34 | tail 29: -451 / -391 cm, free 0 | tail 29: -446 / -265 cm, free 52 | tail 15: -471 / -202 cm, free 12 |
| second volley: first volley from 4 m, passer replies | 42 / 29 | tail 38: -317 / -279 cm, free 0 | tail 38: -316 / -261 cm, free 33 | tail 19: -341 / -172 cm, free 52 |
| second volley in a fast exchange | 32 / 24 | tail 38: -267 / -262 cm, free 0 | tail 38: -267 / -262 cm, free 18 | tail 19: -305 / -235 cm, free 37 |
| serve-and-volley: 120 mph serve, run to the first volley | 31 / 40 | tail 34: -1125 / -1051 cm, free 0 | tail 34: -1125 / -1051 cm, free 0 | tail 34: -1125 / -1051 cm, free 0 |

Serve tails are kept, so serve-and-volley changes only through the buffered rush; the shorter tails help the second volley and the approach.

**Reading 10b** *(computed)*.
- **Second volley.** With the 19-frame tail the volleyer is 70-90 cm closer to the net when the pass arrives (-172 against -261 cm in a normal exchange; -235 against -262 in a fast one).
  - He has 52 / 37 frames of steering, against 33 / 18 with the rule changes alone. In retail he has none, because the freeze latches before the Out window opens.
- **Approach.** The approacher is 135 cm (groundstroke approach) or 60 cm (FollowNet) closer when the passing shot arrives.
  - At the passer's contact he is where he is today (within 25 cm), so the passer's window and target do not change. The gain falls in the 34 frames of ball flight after the pass is struck.
  - When he is not yet inside 5 m as the freeze would start, the freeze still applies: for example the FollowNet case with the shorter tail, where the smaller drift leaves him at -5.0 m.
- **Serve-and-volley.** Not changed by the agreed rules, because the serve tail (34 frames) is kept. In retail the serve tail outlasts a 120 mph return (31 frames), so the server is still near the baseline at the return. If the owner wants serve-and-volley stronger, the lever is the serve tail of the serve-and-volley clips; this is not proposed.
- **Assumptions** *(judgement)*:
  - Reply and ball-back frames come from sections 2-3 ball speeds.
  - Root drift in the tail is proportional to the tail's length.
  - The rush curve from rest is retail: 18 / 26 / 43 frames to 5 / 25 / 100 cm, then 9.6 cm per frame.
- **Where it lives:**
  - Tails: an earlier locomotion exit for volley and approach clips (code), or TE[1].Position (data).
  - Buffered rush and no sprint requirement: condition 7 and the sprint check of `fn_8869B928` (code).
  - Freeze at the net: an x > -500 test in `fn_8866F740` (code).
  - Put-away: the Fatality condition `0xC78C8F06` corridor test (code) and the selection rule that admits existing low and backhand clips (data or code).

**Nothing else in the spec assumes faster stops, reversals or starts.**
- The rally simulation uses each player's top run speed (5.7 + 2.9 × Speed m/s). It never models stops, reversals, starts or swing tails.
- The grade's arrival margin comes from the run time at that top speed (frames set before contact).
- The window has no movement factor: movement enters only through the grade (W_grade).

## 11. Where every value lives, and the order to introduce changes

| # | change | values (section) | lives in | data / code | depends on |
|---|---|---|---|---|---|
| 1 | Bounce speed loss | 3 (curve16) | ball templates 334e7e0d | data | none |
| 2 | Flight rows: flat, topspin, slice, serve | 3 | ball templates | data | none |
| 3 | Rating curves: no dead zone | 9a | stat graphs (graph 23 and others) | data if a curve per graph, else code | none |
| 4 | Movement, agreed: buffered rush without sprint requirement, freeze lifted at the net, volley / approach tails 38 / 36 / 29 -> 19 / 18 / 15 | 10 | `fn_8869B928` cond. 7 and sprint check, `fn_8866F740` (code); earlier locomotion exit (code) or TE[1].Position (data) | both | G9 |
| 4b | Put-away selection: existing low and backhand clips admitted, corridor block removed | 8, 10 | Fatality condition `0xC78C8F06` (code); clip selection rule (data or code) | both | G8 |
| 5 | DeepDeviation by timing | 7b | aiming graphs' DeepDeviation branch (or the `b3a1d456` pair if it is that range) | data | 9 |
| 6 | Incoming pace writer S+0x770, with the fast-ball and frame-shot curves re-keyed (100-130 and 110-150 km/h); frames since bounce S+0x7D8 | 4, 4g | shot / receiver update (code); fault graphs and graphs 280-282 (data) | both, in one change | none |
| 7 | Grade score per shot family (rally, return, volley, smash; no grade on serve) and row selection; Tee-off = VeryGood row x code multiplier | 4, 4f | `fn_886629C8`, keys S+0x3B4 / 0x3B8 | code | 6 |
| 8 | Row values: pace caps, aim caps, error added (Good row unchanged), scaled per shot type | 4b, 4f | PowerResolution, AimingResolution, ErrorResolution rows of each ShotDef; the graphs already pick the position from t | data once 7 exists | 7 |
| 9 | Window scale W, applied by dividing t | 5 | `fn_8867DF68` (code); grade must be known before the commit (to confirm) | code | 7, 10 |
| 10 | Opponent timing carrier | 5 | beside the PoisonedSlices write, fn_88695640, or on the ball record | code | none |
| 11 | Rushed swing (+1 grade point), overcharge state, meter state; tiers stay retail | 6 | auto-commit branch of state 658B and the charge counter (code); HUD meter (UI) | code + UI | 7, G8 |
| 12 | Efficiency feed: grade rows and the hand term | 7a | AimingResolution rows (data); hand lerp in the aiming graphs (data) | data | 7, 9 |
| 13 | Volley grading, put-away folded into the top grades | 8 | volley rows; put-away clip eligibility and order (data); corridor test (code) | both | 7, 11 |
| 14 | Serve speed / P(in) / stamina curves | 2d | serve rows and serve graphs | data | 2 |
| 15 | Per-surface bounce | 3 | bounce routine, 889C1F58 | code | 1 |
| 16 | Skill resize | 9 | skill graphs | data | 8, 9 |

**Order.**
1. Data-only feel changes first: 1, 2, 3, 14. Each can be played and judged alone. Then the agreed movement items (4, 4b).
2. Then the engine inputs: 6 and 10.
3. Then the grade (7, 8).
4. Then the window (9) and the swing (11).
5. Then the dependent items: 5, 12, 13, 15, 16.

Re-run the section 2 Monte Carlo and the section 9 abuse check after each step, against the targets.

## What only play can settle

- The human release-error sd (3.4 frames) and therefore the absolute window sizes. Measure it from recorded inputs.
- The share of short balls and how often players try overcharge, which set the tail in 2c.
- Whether 19-frame volley tails make net play too safe against the pass.
- Calibration of absolute rally length and server points won (see "Which results to trust").
- The real feel of the opponent-timing term: whether a ×0.85 window after a Perfect reads as "pressure" or as "unfair".
- Per-surface bounce values, once the code hook exists.
- Whether receivers (and the AI, once its positioning reads tendencies) punish an always-corner habit as the model assumes (anticipation 0.35); without that, the corner on every ball is dominant (7d).
- Whether "a few Tee-offs per set" feels right with the thresholds of 4a, and whether 52 km/h is the right "weak ball" line.
- Whether the overcharge is seen often enough to matter: with the retail tiers and the 10-frame wait it needs about 2.0 s from the opponent's contact (section 6).
- How often a player holds into the auto-commit (35% of wanted-but-unreachable Powerful swings, judgement), which sets the rushed share and part of the average pace.
- The relative strength of the six styles. Robustness shows ±0.1-0.2 swings from single rules, so the final balance can only come from play.

## State at handover

Final run of 2026-11-15, Python 3.13.18, one worker under nice; every table above is from it except section 3 (flight, unchanged by these rules).

**What the model shows** *(computed)*:
- **Style matrix (9b).** The six styles span 0.39-0.61. The slicer (0.614) beats every other build, two of them only within sampling noise (0.51 and 0.53). Heavy topspin is the weakest (0.389). Min-max builds take at most 0.03 from any style.
- **Robustness (9c).** The slicer is the best style in 14 of 16 single-rule variants (0.61-0.66) and beats every other style in 8 of them. The counterpuncher (base error x0.8) and the serve-and-volleyer (base error x1.2) are best in the other two. Heavy topspin is the weakest in 15 of 16. The best-to-worst spread is 0.21-0.31.
- **Hold and break against the 2a targets (9d).**

| quantity | target (s2a) | final run | verdict |
|---|---|---|---|
| specialist holds | about 90% | 79% against the all-rounder, 81-84% in the mirror | short by 6-11 points |
| specialist breaks the all-rounder | 10-15% | 20.5% | too high |
| all-rounder holds | 80-85% | 79.5% against the specialist, 73-75% in the mirror | at the edge / short |
| all-rounder breaks the specialist | about 20% | 21.4% | met |
| specialist vs all-rounder match share | close to even, tie-breaks | 0.44, 0.23 tie-breaks per set | met (within noise) |
| server points won | (tour 62-64%) | 60-65% | met |

- **Other targets met**: averages within 0.3 mph of retail; 110 mph cap about once in 25 matches for the pace specialist; Tee-off 3-4 per player per set; overcharge about once in 11 matches; moonballing loses (33% / 18% at 30% / 60%); the opponent-timing term does not snowball.

**Reliable**: shot-speed and serve distributions (sections 2, 2d); within-model directions (the opponent term, corner policy with and without anticipation, the Tee-off depth and let-drop rules, min-max penalties, single-rule effects in 9c); the cause analysis of the three runs (return grade -> big server; groundstroke-only base error -> serve-and-volleyer).
**Not reliable**: the exact style ranking (single rules move shares by 0.05-0.1, and the leader changed in each run); absolute hold percentages and rally length; anything that depends on court geometry (moonball depth, angles), smashes (not modelled) or swing tails.

**Values to start play-testing with** (all in `tools/design/retune_model.py`):
- Grade score (4a): arrival edges 30 / 15 / 1 frames (still moving 3, reach 4); height 50 / 95 / 145 / 185 cm; pace at contact 52 / 78 / 100 km/h; rushed +1, vigor < 0.3 +1; score <= 0 VeryGood (Tee-off at -1 with contact <= 100 cm behind the baseline), 1-2 Good, 3 Normal, 4-5 Bad, 6+ VeryBad. Volleys: 50 / 36 / 25 frames, height against the net, pace 52 / 80 / 100. Returns: Good; Bad when stretched (placement >= 0.80) or jammed; VeryGood at <= 90 mph; never Tee-off.
- Rows (ratios to the retail Good row): pace cap 1.18 / 1.08 / 1.00 / 0.93 / 0.82 / 0.70; aim cap 1.18 / 1.12 / 1.00 / 0.82 / 0.59 / 0.35; error added 0 / 0 / 0 / 0.03 / 0.08 / 0.15; W_grade 1.30 / 1.10 / 1.00 / 0.95 / 0.90 / 0.85; shot-type share flat 1.0, topspin 0.8, slice 0.5, lob 0.5, drop 1.2.
- Window: W = W_rating (0.90-1.10) x W_opp (0.85 / 0.93 / 1.00 / 1.15 / 1.30) x W_grade x W_react (0.70-1.00), clamped 0.60-1.75; Perfect 2W and Good 6W frames; zero-error band 19 frames x W; overcharge W x 0.80.
- Swing: retail tiers 12 / 53 / 75 frames; overcharge 10 frames past full (+4% pace); ceilings 110 mph forehand / 105 backhand; pace skill +2%.
- Placement: DeepDeviation by timing 0-40 / 0-150 cm / retail 2-3 m. S+0x770 curves re-keyed to 100-130 km/h (fast-ball penalty) and 110-150 km/h (frame shot, 0.10).
- Volleys: a small base error in addition to the outcome bands (model 0.03 per volley; in the game, a constant term in the volley fault graphs).

**Check first on the real game:**
1. **Engine order.** That the grade is known before the commit (`fn_886AE528 +0x430` against `fn_8867DF68`), and that dividing t by W moves the Perfect and Good bands and the fault graphs' forgiveness together. Items 7 and 9 of section 11 depend on it.
2. **The human release spread** (model sd 3.4 frames), measured from recorded inputs. It sets the Perfect rate, the timing-error share and every window size.
3. **Slice on bad balls.** Whether slice at a 50% share becomes the default defensive answer, as the model's slicer suggests; if so, try slice 0.6-0.7 and topspin 0.9.
4. **Tee-off and hold feel.** Whether 3-4 Tee-offs per set with the 52 km/h and 1 m lines reads as "a few sitters", and whether big servers hold often enough once the real return rows (Bad on stretched returns) are in.
