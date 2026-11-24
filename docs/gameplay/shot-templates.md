# Shot templates: decoder, field meanings, and what the numbers say

Family TPL. Decodes the shot-template table that the ball model (`docs/gameplay/gp4b.md`,
`src/xbox360/drafts/gp4b_ball_model.c`) reads, and runs the bit-exact reference model on every template. Only summary
statistics are given here; the full decode and the per-template trajectories stay under `work/disc/` (git-ignored).

Provenance (all local, nothing committed):

| item | value |
|---|---|
| `Core.arc` | sha256 `7df7bfd575150e9ff3b3a171bada368e8bb4d6676ef82505f46961da0aefbf50` (36,997,962 B) |
| `Settings.bin` (entry `0x334E7E0D`) | 286,492 B, sha256 `55cb175dbaf64e30d75f6fe72ae71305a39a39cffca7a2fa3b2e5471431a0167` |
| `State.bin` (entry `0x623D0979`) | 273,746 B, sha256 `ff871577ad82545a26bca27d220e758734093d52b0f3b2f697337408aa1c4aeb` |
| extraction | `python3 tools/ts4_arc.py orig/54540859/disc/Core.arc --extract 334e7e0d --out work/disc/core_big` (same for `623d0979`) |
| decoder | `tools/ts4data/templates.py` (Python 3.13, stdlib only), tests `tests/test_ts4data_templates.py` |
| simulation | `tools/ts4data/template_sim.py` + `template_sim.c` linked with `gp4b_ball_model.c`, `cc` 13.3.0 `-O1` |

## 1. Decoder usage

```sh
python3 tools/ts4data/templates.py --settings work/disc/core_big/334e7e0d.bin \
    --state work/disc/core_big/623d0979.bin --out work/disc/templates_decoded.json
python3 tools/ts4data/templates.py --arc orig/54540859/disc/Core.arc --out work/disc/templates_decoded.json   # extracts itself
python3 tools/ts4data/template_sim.py --settings work/disc/core_big/334e7e0d.bin \
    --state work/disc/core_big/623d0979.bin        # -> work/disc/template_trajectories.csv (92 rows)
python3 -m unittest tests.test_ts4data_templates   # synthetic buffer, no game data
```

Rows are found by structure (value-type word at `tpl+4`/`tpl+0x10`, kind hash at `tpl+8`/`tpl+0x14`), then every
`{rel,type}` pointer is followed and decoded: floats, curve20, 2-D tables (with `eval_curve20`, `eval_curve16`,
`eval_table2d`, `eval_value` ports of the three evaluators) and the four curve16 bounce curves.
Result: **37 rows in `Settings.bin` (0x8C bytes each, contiguous from 0x137C) and 1 row in `State.bin`; every pointer resolves.**
(The earlier "55 rows" count in `docs/disc-data.md` counted kind-hash occurrences, secondary kinds included.)

## 2. Row layout (confirmed on disc; offsets from the row start, `tpl = row + 0x18`)

| offset | content | status |
|---|---|---|
| +0x00 | row type `0x85B71A2B` (absent in the `State.bin` row, which sits inside a larger record) | measured |
| +0x04 | template name hash (crc32 of a plain name, section 3) | measured |
| +0x08 | group hash: `FlatReturn` on 6 flat rows, else 0 | measured, meaning unknown |
| +0x0C | base hash: a related template (e.g. `SliceFinesse` -> `SliceNormal`), or 0/self | measured, meaning unknown |
| +0x10 / +0x14 | two optional `rel` pointers (one is -1) to a block of floats (pairs such as 0.2, 1.0, 0, 0.9, ...) | unknown (decoder returns the first 16 floats raw) |
| tpl+0x00 | node0 `{rel,type,kind}`: primary value, kind = solver kind | H (gp4b) |
| tpl+0x0C | node1: secondary value, kind = secondary kind | H |
| tpl+0x18/0x24/0x30 | `{rel,2,2}` -> `(lo,hi)` elements `{rel,type}`: spin_a (vertical), spin_c (along track), spin_b (lateral) | H; `lo`/`hi` blended by the command's spin blend |
| tpl+0x3C | f32 `T`, drag scale (`k = T / a4`) | H |
| tpl+0x40/0x4C/0x58/0x64 | `{rel,count,cap}` -> curve16 keys: c40 speed loss(spin_a), c4C spin decay(spin_a), c58 outgoing elevation(theta), c64 yaw kick(spin_b) | H structure; M roles |
| row+0x88 | name hash repeated | measured |

Notes found on the way:

* Value types: `0x33799CCE` float, `0xF9F12A60` curve20, `0x7A330099` 2-D table. Curve20 keys are `{x0, x1, y0, slope, w4}`;
  `w4` is **not read by the evaluator** (always >= y0: 80 -> 135, 70 -> 120, 1.1 -> 1.6, 100 -> 150; probably an authored
  upper value, possibly a power or timing scale; open). Every spin curve has slope 0, so spin does not depend on height.
* Spin element `x` ranges are 0.5-1.4 (groundstrokes) and 50-120 (serves; evidently cm vs m). Irrelevant while the slope is 0.
* The 2-D tables (the four volleys, DropTime kind) have two rows keyed at 300 and 3000 cm distance, each a curve16 over hit
  height 120-180 cm: flight time 0.25-0.85 s (PowerVolley) up to 0.5-1.3 s (SliceVolley).
* `State.bin` also contains the **default ball block** (the 0x540-byte `Gp4bBall` image, block start 0x964, ends exactly at the
  next record 0xEA4): radius `+0x4D0` = 4.0 cm, `a4` `+0x4D4` = 0.06, `g` `+0x4D8` = 9.81, `max_bounces` `+0x4DC` = 5.
  This is the first data source for `a4`/`g`/radius that `gp4b.md` listed as "writer not located" (M: runtime code may still
  override them, so `k = T / a4` below is a default-state value). Its default P0/P1 are (-1300, -170, 100) / (1300, 0, -100) cm.

## 3. Names (crc32)

All 21 distinct name/group/base hashes in the table were recovered by crc32 search over tokens from the game's own crc
dictionaries and a small word list (2-token concatenations; each hit is a 32-bit match). `templates.py` carries the 21 names.

* Strokes: `{TopSpin,Slice,Flat}{Normal,Risky,Finesse}` (the 9 combos appear in 12 rows, some twice), `LobNormal` (x6),
  `DropShotNormal`, `SmashNormal`, `DefensiveShot`, volleys `PowerVolley`, `SliceVolley`, `DropVolley`, `FlatVolley`.
* Serves: `ServeNormal` (x6), `ServeSlice` (x3), `ServeAdvanced` (x3), in four groups of three (Normal, Slice, Normal, Advanced).
  By primary speed and spin each group is a (kick 150 / slice 140 / flat 190 km/h) style set: the first Normal group is two
  kick rows plus a stronger-spin kick; `ServeAdvanced` repeats kick/slice/flat; the second `ServeNormal` group is three flat rows.
* The row order is index 0-3 Finesse (TopSpin, Slice, Flat, Lob), 4-7 Normal, 8-11 Normal again, 12-15 Risky, 16-19 volleys,
  20-31 serves, 32-36 DropShot, Smash, Defensive and two more Lobs. Why Normal and Lob appear twice (surface? handedness?
  court zone?) is unknown; the byte offset `row - first_row` is what the planners store in `ball+0x360`.

## 4. What the templates contain (summary)

Kinds (primary + secondary): InitialSpeed + Apogee 13, InitialSpeed + DropTime 12, DropTime + Apogee 6, DropTime + DropTime 5,
InitialSpeed + InitialSpeed 1 (Smash); `State.bin`: BounceSpeed + BounceSpeed 1. `AverageSpeed` never occurs.

* **Primary value = commanded INITIAL speed** (kind InitialSpeed, km/h, a curve of horizontal distance 500-3000 cm, constant
  in this data) **or flight time in s** (DropTime: lobs 1.25-2.6 s, drop shot 1.1 s, volley tables 0.25-1.3 s).
  Initial speed means speed leaving the racket, the unit all real radar data uses.
  - Groundstrokes: Flat 120 / 130 / 140 (Finesse / Normal / Normal2), FlatRisky 135, TopSpin 80 / 80 / 90 (Risky 60),
    Slice 70 / 80 / 80 (Risky 110), Defensive 100, Smash 140.
  - Serves: **190 (flat), 150 (kick), 140 (slice) km/h**.
* **Secondary value**: Apogee offset 0-1.75 m (strokes, lobs, defensive), DropTime offset 0.3-0.5 s (serves), 40 (smash, km/h delta).
* **T** takes five values: 0.04 (all Slice), 0.045 (Risky, volleys, serves, most others), 0.0475, 0.05, 0.0525 (TopSpin
  Normal/Finesse). With the default `a4` = 0.06 that is **k = 0.67-0.875 s^-1** (serves 0.75).
* **Spin vectors** (spin_a, `A.y = spin_a`; negative = topspin): blend lo -> hi, lo is 0 for strokes. hi: TopSpin -0.4 (Risky -0.6),
  Flat -0.2 to -0.3, Slice +0.1 (Risky +0.2), Lob 0 to -0.4, volleys -0.05, Drop +0.05, Smash and Defensive -0.2; serves: kick
  -0.5, flat -0.2, slice +0.05 with sidespin spin_b -0.7 to -0.8 (kick -0.1) and along-track spin_c 0.2 (slice, kick).
* **Bounce curves** (c40, c4C, c58, c64): all single-key linear ramps. c58 (outgoing elevation vs incoming) is within 0.05 rad of
  the identity for strokes, i.e. the model almost never changes the bounce angle; c40 spans -0.4 to +0.15 over spin_a, **negative
  values mean a speed gain** (topspin kicks forward) if the draft's `sf = 1 - c40` is right (M); c4C spin decay 0.5-0.95
  retained. c64 yaw kick is 0 except kick serves.

## 5. Simulated shots (`work/disc/template_trajectories.csv`)

For each template one scenario, solver blend f4C = 1 (primary solver only) and f4C = 0 (secondary stage fully applied), spin
blend 0.5, assumptions: `a4` 0.06, `g` 9.81, radius 4.0 cm, **net 91.4 cm (assumed)**, net-clearance = ball centre above the tape.
`ground` = baseline to baseline, from x = -12.5 m (0.6 m behind the baseline) at 1.0 m to 11.0 m, cross-court, lands 0.9 m inside the baseline
(23.8 m); `serve` = from 12.0 m behind the net at 2.7 m to 5.5 m (0.9 m inside the service line); volleys, smash, lob, drop,
defensive have their own scenario. Headline rows (f4C = 1, median [min-max]):

| class (rows) | initial km/h | arrival km/h (at bounce) | flight s | apex m | net clearance m | arrival angle deg |
|---|---|---|---|---|---|---|
| serve (12) | 152 [141-193] | 103 [92-147] | 0.52 [0.38-0.57] | 2.70 | 0.30 [0.18-0.43] | 14 [12-16] |
| flat groundstroke (4) | 133 [121-140] | 65 [59-70] | 0.93 [0.87-1.03] | 1.8 [1.7-2.0] | 0.90 [0.72-1.09] | 19 [16-21] |
| volley (4) | 89 [67-108] | 57 [36-76] | 0.67 [0.50-0.98] | 1.2 | 0.23 [0.08-0.57] | 17 [11-30] |
| smash | 144 | 116 | 0.32 | 2.5 | 1.0 | 16 |
| lob (6) | 107 [100-172] | 41 [33-103] | 1.4 [0.6-2.6] | 3.3 [1.1-8.5] | 2.4 [0.1-7.2] | 39 [8-74] |
| topspin / slice ground (8) | 88-107 | 31-48 | 1.2-2.2 | 1.9-6.0 | 1.0-5.0 | 20-62 |

* **Speed-limited rows**: for 7 of the ground-shot rows (all TopSpin 60-90 and SliceFinesse/Normal 70-80 at 23.8 m) the fixed
  target speed is below the slowest possible flight over that distance (no feasible solution with `has_min`), so the solver
  returns the minimum-speed arc: 103-107 km/h at 29 deg and a 5.8-6.0 m apex. A fixed 80 km/h topspin reaches ~16 m
  (apex 3.7 m), so the data presumes shorter distances or another use; this needs the command-side picture.
* f4C = 0 changes the picture strongly: the Apogee stage adds a 0.5-1.75 m apex target (flat groundstroke apex 1.8 -> 3.0 m,
  initial speed 133 -> 112 km/h; serves 152 -> 103 km/h). The primary-only (f4C = 1) numbers are the ones that line up with
  real tennis, which suggests normal shots run close to f4C = 1; the real distribution of f4C is not known.
* Bounce at 0.5 spin blend: speed factor `sf` 0.95-1.0 (flat, serve), 1.0-1.07 (topspin), 0.93-0.98 (slice); outgoing/incoming
  vertical speed ratio 0.92-1.05; horizontal ratio 0.95-1.14.
* Spin drift (spin_a `/ a4`, as extra downward g, topspin positive): flat 0.25, topspin 0.34-0.5, slice -0.09 to -0.17,
  kick serve 0.43-0.56, slice serve -0.07 with 0.26-0.30 m lateral drift, flat serve 0.33.

## 6. Comparison with real tennis (`docs/tuning/research.md`)

| quantity | real (research.md) | templates (f4C = 1) | verdict |
|---|---|---|---|
| 1st serve speed | ~187 km/h (ATP impact) | 190 initial (flat), arrival 147 | matches |
| 2nd serve | ~151 km/h | 150 initial (kick) | matches |
| slice serve | no sourced figure | 140 | plausible |
| flat forehand | 126-133 km/h | 120-140 initial (FlatNormal 130) | matches |
| topspin forehand | (no direct figure; backhand medians 97-121) | 80-90 target, 107 forced | **too slow/floaty**: unreachable at 24 m, apex ~6 m |
| arrival speed | derived 130 / 105 / 82 km/h (serve1/serve2/FH) | 147 / 103 / 64 | serve2 ok; **flat FH 20% too slow, serve1 too fast** |
| net clearance, ground | <= 0.6 flat to 0.78 m (Nadal) | flat 0.72-1.09 m (median 0.9) | **0.2-0.3 m high**; serves 0.2-0.4 m fine |
| drag | quadratic, k_eff ~0.45-0.6 s^-1 at 25-30 m/s | linear k = 0.67-0.875 (a4 = 0.06) | **too draggy**; with `a4` = 0.08 (k 0.59) FH arrival is 82 km/h and clearance 0.59 m |
| topspin lift | ~1.2 g extra (tour topspin), flat ~0.45 g | topspin 0.34 g (0.5 at Risky; 1.0 g at blend 1 Risky), flat 0.25-0.5 g | topspin lift **~half of real** |
| bounce COR | vertical ~0.75 hard; ~0.85 clay; horizontal ~0.65-0.8 | speed factor 0.95-1.07, angle kept, vertical 0.92-1.05 | **far too lively**, no surface or slice skid logic |
| spin decay at bounce | 40-60% topspin retained | 0.5-0.95 retained | high end of range, slice 0.95 |

Sensitivity of the net numbers to `a4` is real (blend 0.5, f4C = 1, FlatNormal): `a4` 0.06 / 0.08 / 0.10 -> arrival 64 / 82 / 92 km/h,
net clearance 0.95 / 0.59 / 0.44 m. Since `a4` and radius are only defaults from the `State.bin` ball block, **confirm the live
`ball+0x4D4` before treating the drag and clearance rows as final**.

## 7. Mapping to the tuning levers (`docs/tuning/research.md`, "Mapping findings to TS4's tunable levers")

| lever | where it lives in the data | observation |
|---|---|---|
| Template drag rate k = T / a4 | `tpl+0x3C` (`T`, 5 values 0.04-0.0525), `a4` in the ball block | all T within +-13%; surface/shot-class split is tiny. Retune: per-class T (or a4) to hit k 0.55-1.0 |
| Vertical spin drift | spin_a lo/hi curves | topspin lift half of real; flat ok; tune hi values (-0.4 -> about -0.7 for Normal, -0.6 -> -0.9 Risky) |
| Commanded speed | node0 of InitialSpeed rows (km/h, initial) | already real-world initial speeds (note: `research.md`'s "arrival speed" premise should read **initial speed**, see `gp4b.md` 0.2); topspin/slice rows are low and unreachable at baseline distance |
| Net clearance (aim solve) | Apogee node1 (secondary), net threshold in solver | flat clearance 0.7-1.1 m is high; depends on k, so fix drag first; slice 0.98 m is far above "0.3-0.5" |
| Bounce speed loss c40 | tpl+0x40 | speed gain for topspin; retention should be ~0.7-0.8 vs 0.95-1.07 |
| Outgoing elevation c58 | tpl+0x58 | identity, should lower the flat ball's exit angle and raise it for topspin |
| Spin decay c4C | tpl+0x4C | 0.5-0.95 retained (okay) |
| Surface | none (one table, no surface key) | surface needs separate table sets, as research.md proposed |
| Net-cord / let params | not in the template rows | `ball+0x494..4A0` are 0 in the default ball block; set at runtime |

## 8. Open questions

1. What do the +0x10/+0x14 float blocks, the group (`FlatReturn`) and base hashes, and `w4` of curve20 keys mean?
2. Why do Normal and Lob occur in several copies (surface, hand, court area, difficulty)? Who maps game shot types to rows?
3. Distribution of the command's `f4C` (secondary-stage weight) and spin blend; they decide whether the Apogee/DropTime
   secondaries are mostly off. Also whether normal shots use the template-planned path (`planned = 1`) or the commanded-speed probe.
4. Live `a4`, `g`, radius and net height (defaults here: 0.06, 9.81, 4.0 cm; net assumed 91.4 cm).
5. c40/c58 semantics (the `1 - c40` speed factor, the elevation tilt weight `|5 spin_a|`) are M; validate with a recorded bounce.
6. `State.bin`'s BounceSpeed row (target 80 km/h at the bounce; baseline scenario: 144 km/h initial, 0.8 s flight) is not tied to a
   shot class yet.
