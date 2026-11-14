# Retune baseline: what the retail game measures today

Agent B1 (design analysis), 2026-11-14. Target: Top Spin 4, Xbox 360, retail disc, with the Title
Update #1 (TU1) data compared where it matters. **This note measures and reports. It does not
propose new values.**

The one-page summary is at the end ([Summary](#summary-the-10-largest-gaps-and-the-10-rules-most-likely-to-feel-bad)).

## How to reproduce

Every table marked *generated* comes from one script:

```
python3 tools/design/retune_baseline.py all            # retail disc, every section (about 50 s)
python3 tools/design/retune_baseline.py --tu serve      # the same section on the TU1 data files
python3 tools/design/retune_baseline.py --full-skills skills   # per-graph skill rows
python3 -m unittest tests.test_design_baseline          # synthetic tests of tools/design/baseline_lib.py
```

Section names: `inputs speeds shape timing situ stats skills serve net resp`. Python 3.13.18,
standard library only; the script reuses the repository's own `tools/ts4_analyser.py` (graph
evaluation), `tools/career_data.py` (skill links), `tools/ts4data/ball_model.py` and
`templates.py` (ball flight), and reads the committed dumps `data/gameplay/tunables/*.yaml`,
`coaches_career.yaml` (715 pro ratings) and `animation_clips.yaml`. The game files it reads are
git-ignored local extracts:

| file | path (git-ignored) | bytes | sha256 |
|---|---|---|---|
| settings | work/disc/core_big/334e7e0d.bin | 286492 | 55cb175dbaf64e30d75f6fe72ae71305a39a39cffca7a2fa3b2e5471431a0167 |
| state | work/disc/core_big/623d0979.bin | 273746 | ff871577ad82545a26bca27d220e758734093d52b0f3b2f697337408aa1c4aeb |
| expressions | work/disc/core_all/fa94f637.bin | 581988 | fd3bc49b44ca4b77deebc58acaefe67763a273538f4901266f949e9ec9dedee9 |
| layout | work/disc/Layoutall.bin | 760816 | 67793f5b7dc771f8fde298ef07e8976d9362c864ac577a4c9db6b2bf874788c5 |

Python 3.13.18; analyser kernels tools/ts4_analyser.py; ball model tools/ts4data/ball_model.py.

TU1 files: `work/disc/tu1_arc/334e7e0d.bin` (sha256 `a4d73994…4737`), `623d0979.bin`
(`d8c0da0f…6bfaf0`), `fa94f637.bin` (`1351c0b9…909d`) and `orig/54540859/tu1/files/Layoutall.bin`.
TU1's `State.bin` inserts fields, so later PlayerState offsets move by 0x10; the script maps every
TU1 port back to the disc offset of the same member path, so both runs use one numbering.

**Provenance tags used below.** **[model]** = computed by evaluating the shipped analyser graphs
and the ball model; **[data]** = read directly from a data file or a committed dump;
**[code]** = taken from the repository's code notes (file and section named); **[web]** = a cited
outside source. **[unmeasured]** marks a quantity this note could not measure, with the reason.

**Units and conversions.** World units are cm; the net is at x = 0; the hitter's side is x < 0;
the baseline is at |x| = 1188 cm (11.885 m). The game runs at 60 frames per second, so
1 frame = 16.7 ms. km/h to mph: × 0.621371. "Speed at the baseline" is the ball speed when it
crosses the receiver's baseline plane (x = +11.885 m) after the bounce; this is a choice of this
note, not a game quantity. The model's drag rate is `k = T / a4` with `a4 = 0.06` (ball-physics.md
s0); the spin term is a constant vertical acceleration `-spin_a / a4` m/s². Scenario geometry
(contact points and targets) is listed in `SCEN` in the script; the default groundstroke is
baseline cross-court, 22.3 m.

**Stat levels.** "min / median / p90 / max" are pro-roster ratings from `coaches_career.yaml`
(min = 30, max = 100; median and p90 per stat, for example Power 54 / 75, Serve 51 / 72),
converted to the 0..1 stat by graph 23 (section 5a). "Perfect timing" is t = 0.

---

## 1. Ball speeds

What the engine does [model]: a shot's speed comes from its template row (37 rows; the primary
speed is a ramp over the shot distance, 500..3000 cm) and the secondary weight
`w = clamp01(1 - PowerfulFactor)`. PowerfulFactor (PF, S+0x778) is the output of the shot class's
power graph; PF = 1 is the fastest a row can go. Returns use the Return*Finesse rows for every
tier, so the ReturnPower graphs 261-263 are never used (shot-to-template.md).

#### 1a. Template targets at PowerfulFactor = 1 (the fastest each row can go) *(generated)*

Launch, first-bounce (in and out) and receiver-baseline speeds, km/h (mph), spin blend 0.5. Computed from the model (ball_model.py, ramp curves, a4 = 0.06, net 91.4 cm).

| shot | row | scenario | dist m | launch | bounce in | bounce out | at baseline | flight s |
|---|---|---|---|---|---|---|---|---|
| Flat Finesse | 2 | ground_short | 18.7 | 126 (78) | 77 (48) | 85 (53) | 69 (43) | 0.68 |
| Flat Finesse | 2 | ground_cc | 22.3 | 127 (79) | 68 (42) | 75 (47) | 69 (43) | 0.87 |
| Flat Finesse | 2 | ground_dtl | 22.4 | 127 (79) | 68 (42) | 75 (47) | 71 (44) | 0.87 |
| Flat Finesse | 2 | ground_max | 25.3 | 129 (80) | 63 (39) | 69 (43) | 68 (42) | 1.02 |
| Flat Medium | 6 | ground_short | 18.7 | 133 (83) | 81 (50) | 81 (50) | 63 (39) | 0.65 |
| Flat Medium | 6 | ground_cc | 22.3 | 138 (86) | 76 (47) | 76 (47) | 70 (43) | 0.78 |
| Flat Medium | 6 | ground_dtl | 22.4 | 139 (86) | 76 (47) | 76 (47) | 71 (44) | 0.78 |
| Flat Medium | 6 | ground_max | 25.3 | 139 (87) | 69 (43) | 69 (43) | 67 (42) | 0.93 |
| Flat Powerful | 10 | ground_short | 18.7 | 135 (84) | 80 (50) | 79 (49) | 61 (38) | 0.65 |
| Flat Powerful | 10 | ground_cc | 22.3 | 147 (91) | 81 (51) | 81 (50) | 74 (46) | 0.73 |
| Flat Powerful | 10 | ground_dtl | 22.4 | 147 (92) | 81 (51) | 81 (50) | 76 (47) | 0.73 |
| Flat Powerful | 10 | ground_max | 25.3 | 148 (92) | 74 (46) | 74 (46) | 72 (45) | 0.87 |
| TopSpin Finesse | 0 | ground_short | 18.7 | 111 (69) | 54 (34) | 60 (38) | 39 (24) | 0.88 |
| TopSpin Finesse | 0 | ground_cc | 22.3 | 119 (74) | 51 (32) | 57 (36) | 49 (30) | 1.05 |
| TopSpin Finesse | 0 | ground_dtl | 22.4 | 118 (74) | 50 (31) | 56 (35) | 50 (31) | 1.07 |
| TopSpin Finesse | 0 | ground_max | 25.3 | 125 (78) | 49 (30) | 54 (34) | 52 (33) | 1.20 |
| TopSpin Medium | 4 | ground_short | 18.7 | 111 (69) | 54 (34) | 60 (38) | 39 (24) | 0.88 |
| TopSpin Medium | 4 | ground_cc | 22.3 | 119 (74) | 51 (32) | 57 (36) | 49 (30) | 1.05 |
| TopSpin Medium | 4 | ground_dtl | 22.4 | 118 (74) | 50 (31) | 56 (35) | 50 (31) | 1.07 |
| TopSpin Medium | 4 | ground_max | 25.3 | 125 (78) | 49 (30) | 54 (34) | 52 (33) | 1.20 |
| TopSpin Powerful | 8 | ground_short | 18.7 | 118 (73) | 64 (40) | 64 (40) | 45 (28) | 0.78 |
| TopSpin Powerful | 8 | ground_cc | 22.3 | 125 (78) | 60 (38) | 61 (38) | 54 (33) | 0.93 |
| TopSpin Powerful | 8 | ground_dtl | 22.4 | 126 (78) | 60 (38) | 61 (38) | 56 (35) | 0.93 |
| TopSpin Powerful | 8 | ground_max | 25.3 | 131 (81) | 57 (36) | 58 (36) | 56 (35) | 1.07 |
| Slice Finesse | 1 | ground_short | 18.7 | 98 (61) | 52 (32) | 50 (31) | 35 (21) | 0.95 |
| Slice Finesse | 1 | ground_cc | 22.3 | 106 (66) | 51 (32) | 49 (30) | 43 (26) | 1.10 |
| Slice Finesse | 1 | ground_dtl | 22.4 | 105 (65) | 50 (31) | 48 (30) | 43 (27) | 1.12 |
| Slice Finesse | 1 | ground_max | 25.3 | 111 (69) | 49 (30) | 47 (29) | 46 (28) | 1.23 |
| Slice Medium | 5 | ground_short | 18.7 | 103 (64) | 57 (35) | 54 (34) | 39 (24) | 0.88 |
| Slice Medium | 5 | ground_cc | 22.3 | 109 (68) | 54 (33) | 51 (32) | 45 (28) | 1.05 |
| Slice Medium | 5 | ground_dtl | 22.4 | 108 (67) | 53 (33) | 50 (31) | 46 (29) | 1.07 |
| Slice Medium | 5 | ground_max | 25.3 | 113 (70) | 51 (32) | 49 (30) | 47 (29) | 1.20 |
| Slice Powerful | 9 | ground_short | 18.7 | 105 (65) | 60 (37) | 57 (36) | 42 (26) | 0.85 |
| Slice Powerful | 9 | ground_cc | 22.3 | 112 (70) | 57 (36) | 55 (34) | 49 (31) | 1.00 |
| Slice Powerful | 9 | ground_dtl | 22.4 | 111 (69) | 56 (35) | 54 (34) | 50 (31) | 1.02 |
| Slice Powerful | 9 | ground_max | 25.3 | 117 (73) | 55 (34) | 53 (33) | 52 (32) | 1.13 |
| Lob Finesse | 3 | lob | 23.1 | 102 (63) | 37 (23) | 41 (25) | 30 (19) | 1.57 |
| Lob Medium | 7 | lob | 23.1 | 101 (63) | 36 (23) | 40 (25) | 29 (18) | 1.62 |
| Lob Powerful | 11 | lob | 23.1 | 107 (66) | 42 (26) | 46 (28) | 37 (23) | 1.42 |
| Drop shot (Slice+Risk) | 32 | drop | 11.0 | 55 (34) | 26 (16) | 25 (15) | - | 1.22 |
| Smash | 33 | smash | 11.1 | 151 (94) | 123 (76) | 122 (76) | 110 (68) | 0.30 |
| Volley TopSpin = PowerVolley | 16 | volley | 12.7 | 119 (74) | 86 (54) | 89 (55) | 83 (52) | 0.45 |
| Volley Flat/Lob = FlatVolley | 19 | volley | 12.7 | 101 (63) | 69 (43) | 70 (44) | 64 (40) | 0.55 |
| Volley Slice = SliceVolley | 17 | volley | 12.7 | 78 (48) | 46 (28) | 49 (31) | 42 (26) | 0.78 |
| Drop volley (Slice+Risk) | 18 | volley | 12.7 | 67 (42) | 36 (23) | 36 (23) | 27 (17) | 0.98 |
| Return Flat (any tier) | 10 | return | 22.1 | 148 (92) | 83 (52) | 83 (51) | 73 (45) | 0.72 |
| Return TopSpin (any tier) | 8 | return | 22.1 | 124 (77) | 60 (37) | 61 (38) | 50 (31) | 0.93 |
| Return Slice (any tier) | 9 | return | 22.1 | 111 (69) | 57 (35) | 55 (34) | 46 (29) | 1.00 |
| Serve Kick Finesse | 22 | serve_T | 18.0 | 150 (93) | 101 (63) | 101 (63) | 82 (51) | 0.53 |
| Serve Kick Finesse | 22 | serve_wide | 17.8 | 152 (95) | 103 (64) | 103 (64) | 83 (51) | 0.52 |
| Serve Kick Medium | 20 | serve_T | 18.0 | 150 (93) | 101 (62) | 101 (62) | 82 (51) | 0.53 |
| Serve Kick Medium | 20 | serve_wide | 17.8 | 152 (95) | 103 (64) | 103 (64) | 83 (52) | 0.52 |
| Serve Kick Powerful | 21 | serve_T | 18.0 | 150 (93) | 101 (62) | 101 (62) | 82 (51) | 0.53 |
| Serve Kick Powerful | 21 | serve_wide | 17.8 | 152 (95) | 103 (64) | 103 (64) | 83 (52) | 0.52 |
| Serve Slice Finesse | 25 | serve_T | 18.0 | 143 (89) | 93 (58) | 91 (56) | 73 (45) | 0.57 |
| Serve Slice Finesse | 25 | serve_wide | 17.8 | 141 (88) | 92 (57) | 90 (56) | 70 (43) | 0.57 |
| Serve Slice Medium | 23 | serve_T | 18.0 | 143 (89) | 93 (58) | 91 (56) | 73 (45) | 0.57 |
| Serve Slice Medium | 23 | serve_wide | 17.8 | 141 (88) | 92 (57) | 90 (56) | 70 (43) | 0.57 |
| Serve Slice Powerful | 24 | serve_T | 18.0 | 143 (89) | 93 (58) | 91 (56) | 73 (45) | 0.57 |
| Serve Slice Powerful | 24 | serve_wide | 17.8 | 141 (88) | 92 (57) | 90 (56) | 70 (43) | 0.57 |
| Serve Flat Finesse | 28 | serve_T | 18.0 | 196 (122) | 149 (92) | 141 (88) | 124 (77) | 0.38 |
| Serve Flat Finesse | 28 | serve_wide | 17.8 | 194 (120) | 147 (91) | 140 (87) | 121 (75) | 0.38 |
| Serve Flat Medium | 26 | serve_T | 18.0 | 196 (122) | 149 (92) | 141 (88) | 124 (77) | 0.38 |
| Serve Flat Medium | 26 | serve_wide | 17.8 | 194 (120) | 147 (91) | 140 (87) | 121 (75) | 0.38 |
| Serve Flat Powerful | 27 | serve_T | 18.0 | 196 (122) | 149 (92) | 141 (88) | 124 (77) | 0.38 |
| Serve Flat Powerful | 27 | serve_wide | 17.8 | 194 (120) | 147 (91) | 140 (87) | 121 (75) | 0.38 |
| Serve Advanced kick | 29 | serve_T | 18.0 | 150 (93) | 101 (63) | 101 (63) | 82 (51) | 0.53 |
| Serve Advanced kick | 29 | serve_wide | 17.8 | 152 (95) | 103 (64) | 103 (64) | 83 (52) | 0.52 |
| Serve Advanced slice | 30 | serve_T | 18.0 | 143 (89) | 93 (58) | 91 (56) | 73 (45) | 0.57 |
| Serve Advanced slice | 30 | serve_wide | 17.8 | 141 (88) | 92 (57) | 90 (56) | 70 (43) | 0.57 |
| Serve Advanced flat | 31 | serve_T | 18.0 | 196 (122) | 149 (92) | 141 (88) | 124 (77) | 0.38 |
| Serve Advanced flat | 31 | serve_wide | 17.8 | 194 (120) | 147 (91) | 140 (87) | 121 (75) | 0.38 |

#### 1b. Groundstrokes by stats (perfect timing, fresh, baseline contact at 1.0 m, opponent on the baseline) *(generated)*

PowerfulFactor (PF) from the class power graph, spin blend from graph 241/242, flight on scenario ground_cc. Charge: Finesse 0.10, Medium 0.50, Powerful 0.85 (64 frames held). Forehand stat used as HandAttributeQuality; a backhand with the same Backhand rating gives the same numbers (same rows and graphs). Rating levels: min 30/30, median 54/54, p90 75/75, max 100/100 (Forehand/Power ratings).

| shot (launch / at baseline km/h (mph)) | min | median | p90 | max |
|---|---|---|---|---|
| Flat Finesse | PF 0.70: 110 (69) / 48 (30) | PF 0.76: 113 (70) / 50 (31) | PF 0.84: 117 (73) / 54 (34) | PF 0.92: 123 (76) / 59 (37) |
| Flat Medium | PF 0.77: 121 (75) / 47 (29) | PF 0.82: 125 (78) / 50 (31) | PF 0.86: 127 (79) / 51 (32) | PF 0.92: 131 (82) / 56 (34) |
| Flat Powerful | PF 0.72: 126 (78) / 48 (30) | PF 0.76: 129 (80) / 50 (31) | PF 0.79: 130 (81) / 51 (32) | PF 0.92: 141 (88) / 61 (38) |
| TopSpin Finesse | PF 0.76: 113 (70) / 39 (24) | PF 0.82: 114 (71) / 40 (25) | PF 0.91: 116 (72) / 42 (26) | PF 1.00: 118 (74) / 44 (27) |
| TopSpin Medium | PF 0.82: 114 (71) / 40 (25) | PF 0.88: 116 (72) / 41 (26) | PF 0.92: 117 (72) / 42 (26) | PF 1.00: 118 (74) / 44 (27) |
| TopSpin Powerful | PF 0.77: 117 (73) / 43 (27) | PF 0.82: 119 (74) / 45 (28) | PF 0.88: 121 (75) / 47 (30) | PF 0.96: 124 (77) / 50 (31) |
| Slice Finesse | PF 0.69: 97 (60) / 33 (20) | PF 0.73: 98 (61) / 33 (21) | PF 0.80: 99 (61) / 35 (22) | PF 0.86: 100 (62) / 36 (23) |
| Slice Medium | PF 0.82: 101 (62) / 36 (22) | PF 0.88: 102 (64) / 37 (23) | PF 0.92: 104 (65) / 39 (24) | PF 1.00: 108 (67) / 43 (26) |
| Slice Powerful | PF 0.73: 101 (63) / 37 (23) | PF 0.79: 103 (64) / 38 (24) | PF 0.87: 106 (66) / 42 (26) | PF 0.96: 109 (68) / 45 (28) |

#### 1c. Other shots by stats (perfect timing) *(generated)*

| shot (launch / at baseline) | min | median | p90 | max |
|---|---|---|---|---|
| Lob Finesse [lob] | PF 0.23: 102 (63) / 30 (19) | PF 0.19: 102 (63) / 30 (19) | PF 0.13: 102 (64) / 30 (19) | PF 0.07: 103 (64) / 30 (19) |
| Lob Medium [lob] | PF 0.23: 101 (63) / 29 (18) | PF 0.19: 102 (63) / 29 (18) | PF 0.13: 102 (63) / 29 (18) | PF 0.07: 102 (64) / 29 (18) |
| Lob Powerful [lob] | PF 0.23: 101 (62) / 29 (18) | PF 0.19: 100 (62) / 29 (18) | PF 0.13: 99 (62) / 27 (17) | PF 0.07: 98 (61) / 26 (16) |
| Drop shot (Slice+Risk) [drop] | PF 0.77: 55 (34) / - | PF 0.81: 55 (34) / - | PF 0.87: 55 (34) / - | PF 0.93: 55 (34) / - |
| Smash [smash] | PF 0.77: 132 (82) / 90 (56) | PF 0.81: 138 (86) / 96 (60) | PF 0.87: 138 (86) / 96 (60) | PF 0.93: 144 (90) / 102 (64) |
| Volley TopSpin = PowerVolley [volley] | PF 0.87: 104 (64) / 63 (39) | PF 0.88: 104 (64) / 63 (39) | PF 0.91: 106 (66) / 65 (40) | PF 0.94: 109 (68) / 68 (42) |
| Volley Flat/Lob = FlatVolley [volley] | PF 0.85: 87 (54) / 47 (29) | PF 0.86: 89 (55) / 48 (30) | PF 0.90: 93 (57) / 52 (32) | PF 0.94: 94 (59) / 53 (33) |
| Volley Slice = SliceVolley [volley] | PF 0.84: 73 (45) / 36 (22) | PF 0.85: 73 (45) / 36 (22) | PF 0.86: 74 (46) / 37 (23) | PF 0.88: 74 (46) / 37 (23) |
| Drop volley (Slice+Risk) [volley] | PF 0.87: 66 (41) / 24 (15) | PF 0.88: 66 (41) / 24 (15) | PF 0.89: 66 (41) / 24 (15) | PF 0.91: 66 (41) / 24 (15) |
| Return Flat (any tier) [return] | PF 0.71: 125 (77) / 44 (28) | PF 0.76: 129 (80) / 48 (30) | PF 0.83: 134 (83) / 52 (32) | PF 0.91: 140 (87) / 57 (35) |
| Return TopSpin (any tier) [return] | PF 0.78: 117 (73) / 40 (25) | PF 0.84: 119 (74) / 42 (26) | PF 0.90: 122 (76) / 44 (27) | PF 0.98: 124 (77) / 47 (29) |
| Return Slice (any tier) [return] | PF 0.78: 102 (63) / 35 (22) | PF 0.84: 104 (65) / 38 (24) | PF 0.91: 107 (67) / 41 (25) | PF 1.00: 111 (69) / 44 (27) |

#### 1d. Serves by stats (perfect gauge timing 0, fresh, hold by tier) *(generated)*

Serve power graphs 255 (Finesse, Medium), 256 (Powerful), 257 (Advanced) read Serve, Power, the toss hold fraction (255) or the gauge timing (256/257). Hold fraction: Finesse 0.05, Medium 0.5, Powerful/Advanced 0.9. Scenario serve_T.

| serve (launch / at baseline) | min | median | p90 | max |
|---|---|---|---|---|
| Kick Finesse | PF 0.00: 99 (62) / 33 (20) | PF 0.01: 99 (62) / 33 (20) | PF 0.03: 101 (62) / 34 (21) | PF 0.05: 101 (63) / 34 (21) |
| Kick Medium | PF 0.07: 101 (63) / 35 (22) | PF 0.12: 103 (64) / 36 (23) | PF 0.20: 106 (66) / 39 (24) | PF 0.28: 110 (68) / 42 (26) |
| Kick Powerful | PF 0.40: 114 (71) / 45 (28) | PF 0.56: 123 (76) / 52 (32) | PF 0.76: 133 (83) / 61 (38) | PF 1.00: 152 (95) / 80 (50) |
| Slice Finesse | PF 0.00: 102 (63) / 37 (23) | PF 0.01: 102 (63) / 37 (23) | PF 0.03: 103 (64) / 39 (24) | PF 0.05: 103 (64) / 38 (24) |
| Slice Medium | PF 0.07: 104 (64) / 38 (24) | PF 0.12: 105 (65) / 39 (24) | PF 0.20: 109 (68) / 42 (26) | PF 0.28: 111 (69) / 43 (27) |
| Slice Powerful | PF 0.40: 115 (72) / 46 (29) | PF 0.56: 122 (76) / 51 (32) | PF 0.76: 130 (81) / 57 (35) | PF 1.00: 142 (88) / 66 (41) |
| Flat Finesse | PF 0.00: 102 (63) / 33 (21) | PF 0.01: 102 (63) / 33 (21) | PF 0.03: 103 (64) / 34 (21) | PF 0.05: 103 (64) / 34 (21) |
| Flat Medium | PF 0.07: 104 (65) / 36 (22) | PF 0.12: 106 (66) / 37 (23) | PF 0.20: 110 (68) / 42 (26) | PF 0.28: 114 (71) / 45 (28) |
| Flat Powerful | PF 0.40: 122 (76) / 53 (33) | PF 0.56: 135 (84) / 66 (41) | PF 0.76: 156 (97) / 86 (54) | PF 1.00: 196 (122) / 124 (77) |
| Advanced kick | PF 0.50: 125 (77) / 55 (34) | PF 0.65: 132 (82) / 62 (38) | PF 0.79: 138 (86) / 67 (42) | PF 1.00: 152 (95) / 80 (50) |
| Advanced slice | PF 0.50: 120 (74) / 49 (31) | PF 0.65: 125 (77) / 53 (33) | PF 0.79: 130 (81) / 57 (35) | PF 1.00: 142 (88) / 66 (41) |
| Advanced flat | PF 0.50: 148 (92) / 79 (49) | PF 0.65: 156 (97) / 86 (54) | PF 0.79: 171 (106) / 100 (62) | PF 1.00: 196 (122) / 124 (77) |

#### 1e. Timing and charge against speed (Flat Powerful / TopSpin Medium, median stats) *(generated)*

| timing t | Flat Powerful | TopSpin Medium | Flat Finesse |
|---|---|---|---|
| -0.6 | PF 0.71 126 (78) | PF 0.88 116 (72) | PF 0.58 105 (65) |
| -0.3 | PF 0.72 126 (78) | PF 0.88 116 (72) | PF 0.60 106 (66) |
| -0.1 | PF 0.74 127 (79) | PF 0.88 116 (72) | PF 0.64 108 (67) |
| +0.0 | PF 0.76 129 (80) | PF 0.88 116 (72) | PF 0.76 113 (70) |
| +0.1 | PF 0.74 127 (79) | PF 0.88 116 (72) | PF 0.64 108 (67) |
| +0.3 | PF 0.72 126 (78) | PF 0.88 116 (72) | PF 0.59 105 (65) |
| +0.6 | PF 0.70 124 (77) | PF 0.88 116 (72) | PF 0.51 102 (63) |

| Flat Powerful charge | PF | launch |
|---|---|---|
| 0.70 (52 frames) | 0.743 | 127 (79) |
| 0.80 (60 frames) | 0.755 | 129 (80) |
| 0.90 (68 frames) | 0.767 | 129 (80) |
| 0.99 (74 frames) | 0.789 | 130 (81) |
| 1.00 (75 frames) | 0.791 | 130 (81) |

#### 1f. Fastest shots the retail game can produce *(generated)*

| shot | PF all stats 100 | launch | best PF (all skills) | conditions | launch | bounce in | at baseline |
|---|---|---|---|---|---|---|---|
| Flat Powerful | 0.921 | 144 (89) | 0.977 | t=-0.1 io=0 opp_x=300 fatality=0 charge=0.85 hit_y=80 | 147 (91) | 73 (45) | 64 (40) |
| TopSpin Powerful | 0.956 | 130 (81) | 1.000 | t=-0.1 io=0 opp_x=300 fatality=0 charge=0.85 hit_y=80 | 131 (82) | 58 (36) | 55 (34) |
| Slice Powerful | 0.960 | 116 (72) | 1.000 | t=-0.1 io=1 opp_x=300 fatality=0 charge=0.85 hit_y=80 | 117 (72) | 54 (34) | 49 (30) |
| Flat Medium | 0.923 | 134 (83) | 0.923 | t=+0.0 io=0 opp_x=300 fatality=0 charge=0.5 hit_y=80 | 134 (83) | 64 (40) | 56 (35) |
| TopSpin Powerful | 0.956 | 130 (81) | 1.000 | t=-0.1 io=0 opp_x=300 fatality=0 charge=0.85 hit_y=80 | 131 (82) | 58 (36) | 55 (34) |
| Serve Flat Powerful | 1.000 | 196 (122) | 1.000 | gauge t=-0.2 hold=0.8 trailing=1 | 196 (122) | 149 (92) | 124 (77) |
| Serve Advanced flat | 1.000 | 196 (122) | 1.000 | gauge t=-0.1 hold=0.8 trailing=1 | 196 (122) | 149 (92) | 124 (77) |
| Serve Kick Powerful | 1.000 | 152 (95) | 1.000 | gauge t=-0.2 hold=0.8 trailing=1 | 152 (95) | 100 (62) | 80 (50) |
| Serve Slice Powerful | 1.000 | 142 (88) | 1.000 | gauge t=-0.2 hold=0.8 trailing=1 | 142 (88) | 89 (55) | 66 (41) |

**The build that produces each fastest shot** [model]:
- **Fastest forehand and backhand:** Flat Powerful at Power 100 and hand stat 100, all skills,
  timing slightly early (t = -0.1), full charge, about 147 km/h (91 mph), 148 on the longest
  corner-to-corner path. The backhand equals the forehand: the same graphs read the
  "hand" stat, which is the forehand or backhand rating of that stroke, so a build with both at
  100 has identical wings. The Power rating dominates PF (the final cap lerps 0.825 to 1 by
  `0.855 × Power + 0.1 × hand`); the hand stat moves launch speed by at most about 4 km/h.
- **Fastest serve:** Flat Powerful or Advanced flat serve at Serve 100 and Power 100, held to the
  Powerful tier, 196 km/h (122 mph) launch, 149 km/h at the bounce. Kick 152, slice 142.
- Skills do not stack above these caps: inside the clamped curves most skill bonuses saturate
  (for example InsideOutMaster adds 0 to FlatPower PF at max stats).

**Comparison with the ATP tour** [web] (all ATP numbers are reported shot speeds; the sources do
not say whether they are launch or average speeds, so they are compared with the game's launch
speed, which is the most favourable reading for the game):

| quantity | ATP | game (median stats / best build) | gap |
|---|---|---|---|
| average forehand | 73 mph = 117 km/h (TDI, 2024) [1] | Flat Powerful 129 km/h (80 mph); TopSpin Medium 116 (72) / 147 (91) | at or above the average at launch |
| average backhand | 66 mph = 106 km/h (TDI, 2024) [1] | the same as the forehand (no wing difference) | game backhands are 10 km/h faster than real |
| strong forehand (Sinner 2024 average) | 78 mph = 126 km/h [1] | reachable by any median build (Flat Powerful) | no player-to-player spread beyond about 20 km/h |
| peak groundstrokes | several men at about 120 mph = 193 km/h (Hawk-Eye, Roland Garros) [2] | 148 km/h (92 mph) maximum | -45 km/h |
| first serve, top-10 average | 117.2 mph = 188.6 km/h [3] | 135 km/h median build; 196 maximum | -54 km/h at median; the best build only just passes the tour average |
| second serve, top-10 average | 95.8 mph = 154.1 km/h [3] | Medium/Finesse serves 99-114 km/h (62-71 mph) | -40 to -55 km/h |
| fastest serve | 263.4 km/h (Groth, 2012, Challenger); 253 km/h (Isner, ATP official) [3][4] | 196 km/h | -57 to -67 km/h |

The bigger gap is after launch: the model's ball keeps only about half its speed by the receiver's
baseline (Flat Powerful 147 → 74 km/h; topspin 125 → 54; slice 112 → 43-49). No cited
outside figure for real bounce or baseline speeds was found, so this note does not give a
measured gap there [unmeasured: no source].

## 2. Trajectory shape

#### 2a. Flight shape by row and landing depth (median stats, perfect timing) *(generated)*

Hitter at the baseline (x = -1188, contact 1.0 m), target on the cross-court line at depth x (cm past the net). PF and spin blend from the class graphs. Net clearance = ball centre above the 91.4 cm tape (centre height - 0.914 m); bounce height = top of the arc after the first bounce. Computed from the model.

| shot | PF/blend | depth cm | net clear m | apex m | in deg | out deg | bounce height m | bounce in | bounce out | out/in |
|---|---|---|---|---|---|---|---|---|---|---|
| Flat Finesse | 0.76/0.76 | 700 | 0.61 | 1.67 | 19.5 | 19.5 | 1.23 | 57 (36) | 60 (37) | 1.05 |
| Flat Finesse | 0.76/0.76 | 900 | 0.91 | 1.88 | 21.0 | 21.0 | 1.35 | 56 (35) | 59 (37) | 1.05 |
| Flat Finesse | 0.76/0.76 | 1100 | 1.23 | 2.15 | 23.2 | 23.2 | 1.49 | 54 (34) | 57 (36) | 1.05 |
| Flat Medium | 0.82/0.82 | 700 | 0.46 | 1.53 | 17.3 | 17.3 | 0.97 | 67 (42) | 60 (37) | 0.90 |
| Flat Medium | 0.82/0.82 | 900 | 0.77 | 1.74 | 18.9 | 18.9 | 1.07 | 65 (40) | 58 (36) | 0.90 |
| Flat Medium | 0.82/0.82 | 1100 | 1.10 | 2.02 | 21.3 | 21.3 | 1.20 | 62 (38) | 55 (34) | 0.90 |
| Flat Powerful | 0.76/0.76 | 700 | 0.45 | 1.52 | 17.2 | 17.2 | 0.95 | 66 (41) | 60 (37) | 0.91 |
| Flat Powerful | 0.76/0.76 | 900 | 0.70 | 1.68 | 18.2 | 18.2 | 1.03 | 65 (40) | 59 (37) | 0.91 |
| Flat Powerful | 0.76/0.76 | 1100 | 0.98 | 1.90 | 20.0 | 20.0 | 1.13 | 63 (39) | 57 (36) | 0.91 |
| TopSpin Finesse | 0.82/0.86 | 700 | 1.18 | 2.21 | 28.8 | 27.7 | 1.57 | 48 (30) | 51 (32) | 1.06 |
| TopSpin Finesse | 0.82/0.86 | 900 | 1.55 | 2.49 | 30.6 | 29.5 | 1.71 | 48 (30) | 51 (32) | 1.06 |
| TopSpin Finesse | 0.82/0.86 | 1100 | 1.93 | 2.85 | 33.3 | 32.1 | 1.88 | 47 (29) | 50 (31) | 1.06 |
| TopSpin Medium | 0.88/0.91 | 700 | 1.10 | 2.13 | 27.5 | 26.4 | 1.53 | 50 (31) | 53 (33) | 1.05 |
| TopSpin Medium | 0.88/0.91 | 900 | 1.52 | 2.46 | 30.1 | 29.0 | 1.69 | 49 (30) | 51 (32) | 1.05 |
| TopSpin Medium | 0.88/0.91 | 1100 | 1.91 | 2.82 | 32.9 | 31.6 | 1.87 | 48 (30) | 50 (31) | 1.05 |
| TopSpin Powerful | 0.82/0.86 | 700 | 0.87 | 1.92 | 23.6 | 22.6 | 1.32 | 56 (35) | 55 (34) | 0.99 |
| TopSpin Powerful | 0.82/0.86 | 900 | 1.23 | 2.18 | 25.5 | 24.4 | 1.45 | 55 (34) | 55 (34) | 0.99 |
| TopSpin Powerful | 0.82/0.86 | 1100 | 1.55 | 2.46 | 27.4 | 26.2 | 1.58 | 54 (34) | 54 (33) | 0.99 |
| Slice Finesse | 0.73/0.73 | 700 | 0.55 | 1.60 | 19.6 | 21.1 | 0.80 | 42 (26) | 40 (25) | 0.94 |
| Slice Finesse | 0.73/0.73 | 900 | 0.79 | 1.75 | 20.5 | 22.0 | 0.85 | 42 (26) | 40 (25) | 0.94 |
| Slice Finesse | 0.73/0.73 | 1100 | 0.96 | 1.88 | 20.9 | 22.4 | 0.90 | 43 (26) | 40 (25) | 0.94 |
| Slice Medium | 0.88/0.88 | 700 | 0.27 | 1.34 | 14.9 | 16.7 | 0.68 | 48 (30) | 44 (28) | 0.92 |
| Slice Medium | 0.88/0.88 | 900 | 0.48 | 1.46 | 15.7 | 17.4 | 0.72 | 48 (30) | 44 (27) | 0.92 |
| Slice Medium | 0.88/0.88 | 1100 | 0.66 | 1.59 | 16.6 | 18.3 | 0.76 | 47 (29) | 43 (27) | 0.92 |
| Slice Powerful | 0.79/0.79 | 700 | 0.41 | 1.48 | 17.2 | 18.5 | 0.78 | 48 (30) | 45 (28) | 0.94 |
| Slice Powerful | 0.79/0.79 | 900 | 0.62 | 1.59 | 17.6 | 18.9 | 0.83 | 48 (30) | 45 (28) | 0.94 |
| Slice Powerful | 0.79/0.79 | 1100 | 0.82 | 1.75 | 18.6 | 19.9 | 0.88 | 48 (30) | 45 (28) | 0.94 |

Other shots (median stats):

| shot | scenario | PF/blend | net clear m | apex m | bounce height m | bounce in | bounce out |
|---|---|---|---|---|---|---|---|
| Lob Finesse | lob | 0.19/0.19 | 3.56 | 4.50 | 2.64 | 38 (24) | 42 (26) |
| Lob Medium | lob | 0.19/0.19 | 3.80 | 4.74 | 2.73 | 38 (23) | 41 (26) |
| Lob Powerful | lob | 0.19/0.19 | 3.03 | 3.96 | 2.23 | 36 (22) | 39 (24) |
| Drop shot (Slice+Risk) | drop | 0.81/0.81 | 0.90 | 2.09 | 1.02 | 26 (16) | 24 (15) |
| Smash | smash | 0.81/0.81 | 1.03 | 2.50 | 2.35 | 109 (68) | 108 (67) |
| Volley TopSpin = PowerVolley | volley | 0.88/0.88 | 0.19 | 1.12 | 0.73 | 71 (44) | 69 (43) |
| Volley Flat/Lob = FlatVolley | volley | 0.86/0.86 | 0.30 | 1.22 | 0.79 | 57 (35) | 55 (34) |
| Volley Slice = SliceVolley | volley | 0.85/0.85 | 0.53 | 1.57 | 1.11 | 41 (26) | 44 (27) |
| Drop volley (Slice+Risk) | volley | 0.88/0.88 | 0.74 | 1.95 | 1.11 | 35 (22) | 34 (21) |
| Return Flat (any tier) | return | 0.76/0.76 | 0.77 | 1.77 | 1.07 | 64 (40) | 59 (36) |
| Return TopSpin (any tier) | return | 0.84/0.87 | 1.33 | 2.30 | 1.51 | 55 (34) | 54 (34) |
| Return Slice (any tier) | return | 0.84/0.84 | 0.57 | 1.57 | 0.81 | 50 (31) | 47 (29) |
| Serve Kick Medium | serve_T | 0.12/0.12 | 1.04 | 2.77 | 1.59 | 57 (36) | 57 (36) |
| Serve Slice Medium | serve_T | 0.12/0.12 | 0.80 | 2.70 | 1.40 | 60 (37) | 59 (37) |
| Serve Flat Medium | serve_T | 0.12/0.12 | 1.09 | 2.81 | 1.62 | 61 (38) | 58 (36) |
| Serve Advanced slice | serve_T | 0.65/0.65 | 0.52 | 2.70 | 1.29 | 74 (46) | 72 (45) |
| Serve Kick Powerful | serve_T | 0.56/0.56 | 0.87 | 2.71 | 1.73 | 73 (45) | 73 (45) |
| Serve Slice Powerful | serve_T | 0.56/0.56 | 0.55 | 2.70 | 1.31 | 72 (45) | 70 (44) |
| Serve Flat Powerful | serve_T | 0.56/0.56 | 0.56 | 2.70 | 1.60 | 89 (55) | 84 (52) |
| Serve Advanced flat | serve_T | 0.65/0.65 | 0.39 | 2.70 | 1.72 | 110 (68) | 104 (65) |

#### 2b. Landing depth of a deep-aimed In groundstroke (cm past the net; baseline = 1188) *(generated)*

Distribution over the two uniform random inputs (aiming graph DeviationSystem.Random and graph 196 AimingState.Random), 144 samples each; aim depth from the FlatNormal config (stick up). Computed from the model.

| shot | stats | timing | p10 | median | p90 | share within 3 m of baseline |
|---|---|---|---|---|---|---|
| Flat Finesse | min | +0.0 | 976 | 1033 | 1104 | 100% |
| Flat Finesse | min | +0.3 | 858 | 944 | 1022 | 77% |
| Flat Finesse | median | +0.0 | 990 | 1047 | 1120 | 100% |
| Flat Finesse | median | +0.3 | 866 | 950 | 1033 | 81% |
| Flat Finesse | max | +0.0 | 1028 | 1093 | 1158 | 100% |
| Flat Finesse | max | +0.3 | 886 | 977 | 1070 | 90% |
| Flat Medium | min | +0.0 | 976 | 1033 | 1104 | 100% |
| Flat Medium | min | +0.3 | 662 | 804 | 922 | 19% |
| Flat Medium | median | +0.0 | 990 | 1047 | 1120 | 100% |
| Flat Medium | median | +0.3 | 670 | 815 | 933 | 24% |
| Flat Medium | max | +0.0 | 1028 | 1093 | 1158 | 100% |
| Flat Medium | max | +0.3 | 718 | 864 | 989 | 42% |
| Flat Powerful | min | +0.0 | 1033 | 1056 | 1135 | 100% |
| Flat Powerful | min | +0.3 | 792 | 868 | 944 | 35% |
| Flat Powerful | median | +0.0 | 1043 | 1074 | 1151 | 100% |
| Flat Powerful | median | +0.3 | 803 | 879 | 956 | 44% |
| Flat Powerful | max | +0.0 | 1074 | 1131 | 1176 | 100% |
| Flat Powerful | max | +0.3 | 834 | 913 | 992 | 65% |
| TopSpin Finesse | min | +0.0 | 976 | 1033 | 1104 | 100% |
| TopSpin Finesse | min | +0.3 | 764 | 858 | 949 | 35% |
| TopSpin Finesse | median | +0.0 | 990 | 1047 | 1120 | 100% |
| TopSpin Finesse | median | +0.3 | 773 | 865 | 960 | 40% |
| TopSpin Finesse | max | +0.0 | 1028 | 1093 | 1158 | 100% |
| TopSpin Finesse | max | +0.3 | 791 | 896 | 1000 | 53% |
| TopSpin Medium | min | +0.0 | 976 | 1033 | 1104 | 100% |
| TopSpin Medium | min | +0.3 | 662 | 804 | 922 | 19% |
| TopSpin Medium | median | +0.0 | 990 | 1047 | 1120 | 100% |
| TopSpin Medium | median | +0.3 | 670 | 815 | 933 | 24% |
| TopSpin Medium | max | +0.0 | 1028 | 1093 | 1158 | 100% |
| TopSpin Medium | max | +0.3 | 718 | 864 | 989 | 42% |
| TopSpin Powerful | min | +0.0 | 1033 | 1056 | 1135 | 100% |
| TopSpin Powerful | min | +0.3 | 792 | 868 | 944 | 35% |
| TopSpin Powerful | median | +0.0 | 1043 | 1074 | 1151 | 100% |
| TopSpin Powerful | median | +0.3 | 803 | 879 | 956 | 44% |
| TopSpin Powerful | max | +0.0 | 1074 | 1131 | 1176 | 100% |
| TopSpin Powerful | max | +0.3 | 834 | 913 | 992 | 65% |
| Slice Finesse | min | +0.0 | 976 | 1033 | 1104 | 100% |
| Slice Finesse | min | +0.3 | 710 | 826 | 941 | 26% |
| Slice Finesse | median | +0.0 | 990 | 1047 | 1120 | 100% |
| Slice Finesse | median | +0.3 | 718 | 834 | 952 | 31% |
| Slice Finesse | max | +0.0 | 1028 | 1093 | 1158 | 100% |
| Slice Finesse | max | +0.3 | 740 | 862 | 986 | 40% |
| Slice Medium | min | +0.0 | 976 | 1033 | 1104 | 100% |
| Slice Medium | min | +0.3 | 662 | 804 | 922 | 19% |
| Slice Medium | median | +0.0 | 990 | 1047 | 1120 | 100% |
| Slice Medium | median | +0.3 | 670 | 815 | 933 | 24% |
| Slice Medium | max | +0.0 | 1028 | 1093 | 1158 | 100% |
| Slice Medium | max | +0.3 | 718 | 864 | 989 | 42% |
| Slice Powerful | min | +0.0 | 1033 | 1056 | 1135 | 100% |
| Slice Powerful | min | +0.3 | 796 | 871 | 945 | 37% |
| Slice Powerful | median | +0.0 | 1043 | 1074 | 1151 | 100% |
| Slice Powerful | median | +0.3 | 806 | 881 | 957 | 45% |
| Slice Powerful | max | +0.0 | 1074 | 1131 | 1176 | 100% |
| Slice Powerful | max | +0.3 | 836 | 914 | 994 | 65% |

#### 2c. What the spin parameters do (TopSpin Powerful, Slice Powerful, Flat Powerful; ground_cc, PF 1) *(generated)*

spin_a is a constant vertical acceleration (negative = dips); its extra downward pull is -spin_a / a4 m/s^2 (a4 = 0.06). Same landing point for every blend, so spin changes the launch angle, apex, net clearance and bounce, not where the ball lands. Computed from the model.

| shot | blend | spin_a | extra down m/s2 | spin_b (side) | net clear m | apex m | launch deg | in deg | out deg | speed out/in | bounce height m | spin kept |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| TopSpin Powerful | 0.0 | 0.000 | -0.00 | 0.000 | 0.62 | 1.58 | 6.1 | 16.4 | 16.4 | 1.05 | 1.01 | 0.30 |
| TopSpin Powerful | 0.5 | -0.150 | 2.50 | 0.000 | 0.89 | 1.83 | 8.2 | 19.8 | 19.3 | 1.01 | 1.22 | 0.23 |
| TopSpin Powerful | 1.0 | -0.300 | 5.00 | 0.000 | 1.22 | 2.15 | 10.8 | 23.8 | 22.6 | 0.97 | 1.46 | 0.15 |
| Flat Powerful | 0.0 | 0.000 | -0.00 | 0.000 | 0.19 | 1.20 | 2.9 | 10.3 | 10.3 | 1.15 | 0.96 | 0.50 |
| Flat Powerful | 0.5 | -0.125 | 2.08 | 0.000 | 0.36 | 1.34 | 4.3 | 12.4 | 12.4 | 0.99 | 0.93 | 0.34 |
| Flat Powerful | 1.0 | -0.250 | 4.17 | 0.000 | 0.50 | 1.47 | 5.4 | 14.1 | 14.1 | 0.90 | 0.96 | 0.25 |
| Slice Powerful | 0.0 | 0.000 | -0.00 | 0.000 | 0.82 | 1.77 | 7.8 | 18.7 | 18.7 | 1.00 | 1.11 | 0.25 |
| Slice Powerful | 0.5 | 0.100 | -1.67 | 0.000 | 0.58 | 1.53 | 5.9 | 15.6 | 16.4 | 0.96 | 0.88 | 0.33 |
| Slice Powerful | 1.0 | 0.200 | -3.33 | 0.000 | 0.37 | 1.34 | 4.2 | 13.0 | 14.5 | 0.93 | 0.71 | 0.42 |
| Serve kick | 0.0 | -0.050 | 0.83 | 0.000 | 0.34 | 2.70 | -4.5 | 13.4 | 13.3 | 1.00 | 1.73 | 0.50 |
| Serve kick | 0.5 | -0.275 | 4.58 | -0.050 | 0.49 | 2.70 | -2.8 | 15.7 | 15.3 | 1.00 | 1.78 | 0.50 |
| Serve kick | 1.0 | -0.500 | 8.33 | -0.100 | 0.61 | 2.70 | -1.5 | 17.7 | 17.0 | 1.00 | 1.86 | 0.50 |
| Serve slice | 0.0 | 0.000 | -0.00 | -0.100 | 0.38 | 2.70 | -4.1 | 14.0 | 14.0 | 1.00 | 1.61 | 0.05 |
| Serve slice | 0.5 | 0.025 | -0.42 | -0.450 | 0.36 | 2.70 | -4.3 | 13.8 | 13.8 | 0.98 | 1.47 | 0.05 |
| Serve slice | 1.0 | 0.050 | -0.83 | -0.800 | 0.37 | 2.70 | -4.3 | 13.9 | 13.9 | 0.95 | 1.31 | 0.05 |
| Serve flat | 0.0 | -0.200 | 3.33 | 0.000 | 0.23 | 2.70 | -5.7 | 11.7 | 11.3 | 0.95 | 2.10 | 0.25 |
| Serve flat | 0.5 | -0.200 | 3.33 | 0.000 | 0.23 | 2.70 | -5.7 | 11.7 | 11.3 | 0.95 | 2.10 | 0.25 |
| Serve flat | 1.0 | -0.200 | 3.33 | 0.000 | 0.23 | 2.70 | -5.7 | 11.7 | 11.3 | 0.95 | 2.10 | 0.25 |

Spin blend as a function of PowerfulFactor (graphs 241 / 242):

| class | PF 0 | 0.3 | 0.5 | 0.7 | 0.8 | 0.9 | 1.0 |
|---|---|---|---|---|---|---|---|
| FlatPower | 0.00 | 0.30 | 0.50 | 0.70 | 0.80 | 0.90 | 1.00 |
| TopSpinMedium | 0.00 | 0.30 | 0.60 | 0.76 | 0.84 | 0.92 | 1.00 |
| SlicePower | 0.00 | 0.30 | 0.50 | 0.70 | 0.80 | 0.90 | 1.00 |
| FlatFinesse | 0.00 | 0.30 | 0.50 | 0.70 | 0.80 | 0.90 | 1.00 |

Summary of the generated tables [model]:
- **Net clearance**: flat 0.45-1.23 m, topspin 0.87-1.93 m, slice lower, depending on the
  target depth. **Apex** 1.5-2.9 m. **Bounce height**: flat about 1.0-1.5 m, topspin 1.3-1.9 m,
  slice 0.7-0.9 m; serves 1.3-2.1 m.
- **Post-bounce speed** (out/in): flat 0.90-1.05, topspin about 1.05 (the ball *speeds up* after
  the bounce in the model), slice 0.92-0.94.
- **Landing depth**: at perfect timing 100% of deep-aimed In groundstrokes land within 3 m of the
  baseline, median 10.3-11.3 m past the net. At t = 0.3 the share falls to 19-90% by class.
- **Spin**: the model has no spin rate. "Topspin" is a constant extra downward acceleration
  (spin_a reaches -0.3 at spin blend 1, about 5 m/s² extra pull) plus a bounce rule that keeps
  15-50% of the spin term after the bounce. Spin blend comes from the PF (graphs 241/242), so
  **hitting harder also adds spin** in the model.
- **Surface**: there is no surface term in flight or bounce; one bounce routine serves every court
  (surfaces.md s1-3) [code]. Bounce height and post-bounce speed by surface are therefore
  identical on clay, grass and hard [unmeasured as a difference: there is none to measure].

**Comparison** [web]: ATP forehand spin averages 2,708 rpm (TDI, 2024) [1] and 2,844 rpm (ATP,
March 2025) [5]; an older Hawk-Eye study gives 2,300 rpm (max 3,800) [6]. The model has **no
equivalent** of a spin rate: converting rpm to the model's constant acceleration would need a
lift-coefficient model, which this note does not attempt. Net clearance: the only tour figure
found is Nadal's average forehand net clearance of 0.78 m (Australian Open Hawk-Eye, 2014-2016,
one blog analysis) [7]; a peer-reviewed Hawk-Eye study reports net clearance but the figure was
not retrievable [8]. The game's topspin rally balls clear by 0.9-1.9 m, flat balls by 0.45-1.2 m.
Real quantities with **no model equivalent**: spin rate and spin axis (sidespin), ball skid and
surface friction, court speed, altitude/temperature, ball wear.

## 3. Timing

How timing is produced [code, controls-and-shot-selection s4-7]: the timing value t is read from
the frames between the commit (button release, or the automatic commit) and the predicted ball
contact, through the curves in `02_PlayerSettings.yaml` SwingTimingSelectionList. t = 0 at 20
frames. The automatic commit fires 12 frames before contact (`PlayerTuning+0x740`), which is
t ≈ +0.58: **a human cannot be later than about +0.58**, because holding the button past that
point commits anyway. Power is the hold time: `min(hold, 1.25 s) / 1.25`, tiers at about 11 and
53 frames of hold (controls s5). Serves use their own per-animation curves.

#### 3a. Timing value against frames from commit (release) to ball arrival *(generated)*

Read from data (02_PlayerSettings.yaml SwingTimingSelectionList; serve: Animation[0] = default serve animation 2ce33943, the other 14 serve animations are shifted by 0..12 frames). Worst-ability and best-ability curves identical: True (so stats do not change the window).

| t (+ late) | groundstroke / return | volley | serve (release before contact) |
|---|---|---|---|
| +1.00 | 0.0 f = 0 ms | 0.0 f = 0 ms | 0.0 f = 0 ms |
| +0.60 | 11.6 f = 193 ms | 12.0 f = 200 ms | 11.6 f = 193 ms |
| +0.45 | 12.6 f = 210 ms | 13.5 f = 225 ms | 12.5 f = 208 ms |
| +0.30 | 14.4 f = 240 ms | 15.0 f = 250 ms | 14.0 f = 233 ms |
| +0.10 | 18.0 f = 300 ms | 18.3 f = 306 ms | 17.5 f = 292 ms |
| +0.00 | 20.0 f = 333 ms | 20.0 f = 333 ms | 20.0 f = 333 ms |
| -0.10 | 22.0 f = 367 ms | 21.7 f = 361 ms | 22.5 f = 375 ms |
| -0.30 | 26.0 f = 433 ms | 25.0 f = 417 ms | 27.5 f = 458 ms |
| -0.45 | 29.0 f = 483 ms | 27.5 f = 458 ms | 30.8 f = 514 ms |
| -0.60 | 32.0 f = 533 ms | 30.0 f = 500 ms | 33.3 f = 556 ms |
| -1.00 | 40.0 f = 667 ms | 40.0 f = 667 ms | 40.0 f = 667 ms |

Window widths (frames between the two t values, both sides):

| window | groundstroke | volley | serve |
|---|---|---|---|
| |t| < 0.1 | 4.0 f = 67 ms | 3.3 f = 56 ms | 5.0 f = 83 ms |
| |t| < 0.3 | 11.6 f = 193 ms | 10.0 f = 167 ms | 13.5 f = 225 ms |
| |t| < 0.6 | 20.4 f = 340 ms | 18.0 f = 300 ms | 21.7 f = 362 ms |

The windows do **not** vary with stats, ball speed, position or fatigue: the worst-ability and
best-ability curves are identical in the shipped data, so the TimingAbility outputs (graphs 40-42)
have no effect [data].

#### 3b. What timing gives and costs (median stats, fresh, baseline contact 1.0 m, no skills) *(generated)*

P(error) = clamp01(FaultProbability) of the class fault graph; PF -> launch speed on ground_cc; aim efficiency = class aiming graph Efficiency averaged over its Random input, DeepDeviation mean. Computed from the model.

| t | frames | Flat Powerful | TopSpin Medium | Slice Finesse | Volley std | Drop shot |
|---|---|---|---|---|---|---|
| -1.00 | 40 | err 0.00, 124 km/h, eff 0.60, dev 102 | err 0.17, 116 km/h, eff 0.80, dev 135 | err 0.00, 95 km/h, eff 0.80, dev 122 | err 0.00 | err 0.51 |
| -0.60 | 32 | err 0.00, 126 km/h, eff 0.60, dev 72 | err 0.00, 116 km/h, eff 0.80, dev 126 | err 0.00, 95 km/h, eff 0.80, dev 115 | err 0.00 | err 0.50 |
| -0.45 | 29 | err 0.00, 126 km/h, eff 0.65, dev 60 | err 0.00, 116 km/h, eff 0.80, dev 122 | err 0.00, 95 km/h, eff 0.80, dev 112 | err 0.00 | err 0.50 |
| -0.30 | 26 | err 0.00, 126 km/h, eff 0.65, dev 27 | err 0.00, 116 km/h, eff 0.80, dev 113 | err 0.00, 96 km/h, eff 0.80, dev 106 | err 0.00 | err 0.32 |
| -0.10 | 22 | err 0.00, 127 km/h, eff 1.00, dev 15 | err 0.00, 116 km/h, eff 0.80, dev 87 | err 0.00, 96 km/h, eff 1.00, dev 88 | err 0.00 | err 0.01 |
| +0.00 | 20 | err 0.00, 129 km/h, eff 1.00, dev 15 | err 0.00, 116 km/h, eff 1.00, dev 50 | err 0.00, 98 km/h, eff 1.00, dev 50 | err 0.00 | err 0.00 |
| +0.10 | 18 | err 0.00, 127 km/h, eff 0.80, dev 15 | err 0.00, 116 km/h, eff 0.80, dev 94 | err 0.00, 96 km/h, eff 0.80, dev 103 | err 0.00 | err 0.01 |
| +0.30 | 14 | err 0.00, 126 km/h, eff 0.60, dev 71 | err 0.00, 116 km/h, eff 0.65, dev 143 | err 0.00, 95 km/h, eff 0.80, dev 140 | err 0.00 | err 0.43 |
| +0.45 | 13 | err 0.00, 126 km/h, eff 0.60, dev 105 | err 0.00, 116 km/h, eff 0.60, dev 159 | err 0.00, 95 km/h, eff 0.80, dev 155 | err 0.00 | err 0.68 |
| +0.60 | 12 | err 0.22, 124 km/h, eff 0.60, dev 118 | err 0.00, 116 km/h, eff 0.60, dev 171 | err 0.00, 95 km/h, eff 0.80, dev 165 | err 0.00 | err 0.68 |
| +1.00 | 0 | err 0.36, 123 km/h, eff 0.45, dev 151 | err 0.11, 116 km/h, eff 0.60, dev 201 | err 0.10, 94 km/h, eff 0.80, dev 194 | err 0.00 | err 0.69 |

#### 3c. Error against timing for every reachable class (median stats; P(error) at t) *(generated)*

| class | -1.00 | -0.60 | -0.45 | -0.30 | +0.00 | +0.30 | +0.45 | +0.60 | +1.00 |
|---|---|---|---|---|---|---|---|---|---|
| FlatFinesse (row 2) | 0.05 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.11 |
| FlatMedium (row 6) | 0.17 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.11 |
| FlatPower (row 10) | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.22 | 0.36 |
| TopSpinFinesse (row 0) | 0.06 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.12 |
| TopSpinMedium (row 4) | 0.17 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.11 |
| TopSpinPower (row 8) | 0.17 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.21 | 0.35 |
| SliceFinesse (row 1) | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.10 |
| SliceMedium (row 5) | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 |
| SlicePower (row 9) | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 |
| Lob (row 3) | 0.26 | 0.19 | 0.16 | 0.09 | 0.00 | 0.11 | 0.21 | 0.26 | 0.40 |
| Lob (row 7) | 0.26 | 0.19 | 0.16 | 0.09 | 0.00 | 0.11 | 0.21 | 0.26 | 0.40 |
| Lob (row 11) | 0.26 | 0.19 | 0.16 | 0.09 | 0.00 | 0.11 | 0.21 | 0.26 | 0.40 |
| DropShot (row 32) | 0.51 | 0.50 | 0.50 | 0.32 | 0.00 | 0.43 | 0.68 | 0.68 | 0.69 |
| Smash (row 33) | 0.03 | 0.01 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.01 | 0.03 |
| VolleyPower (row 16) | 0.22 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.17 | 0.32 |
| VolleyStandard (row 19) | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 |
| VolleySlice (row 17) | 0.05 | 0.02 | 0.01 | 0.00 | 0.00 | 0.01 | 0.03 | 0.06 | 0.09 |
| VolleyDrop (row 18) | 0.25 | 0.25 | 0.24 | 0.17 | 0.00 | 0.22 | 0.34 | 0.35 | 0.35 |
| ReturnFlatFinesse (row 10) | 0.01 | 0.01 | 0.01 | 0.00 | 0.00 | 0.00 | 0.00 | 0.01 | 0.01 |
| ReturnTopSpinFinesse (row 8) | 0.01 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.01 |
| ReturnSliceFinesse (row 9) | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 |

What each grade gives and costs, in words [model]:
- **Error-free band**: for most groundstrokes P(error) = 0 over roughly t = -0.6..+0.45, i.e.
  from 32 to 13 frames before contact: a 19-frame (317 ms) band with no error at all. Only the
  aim efficiency (how close to the lines the ball goes) and the deep deviation reward the
  narrow |t| < 0.1 band (4 frames, 67 ms).
- **Flat Powerful** is the only common shot with an error inside the reachable range: 0.22 at
  +0.6 and 0.36 at +1 (which a human cannot reach, see above).
- **Drop shot** is the exception: 0.32 at -0.3, 0.43 at +0.3, 0.68 at +0.45.
- **Speed** barely depends on timing: Flat Powerful 129 km/h at t = 0, 124 km/h at t = +0.6.
- **Returns**: at most about 0.01-0.03 error anywhere. **Standard volley**: 0 at every timing.
- These are graph probabilities, not hit rates; this note does not estimate how often players
  land in each band [unmeasured: needs play logs].

#### 3d. Every input of the timing, fault and net graphs, and its retail status *(generated)*

| input | graphs reading it | status in retail |
|---|---|---|
| ball+0x340 Commands.#7bb6a318.From | 25 | live |
| ball+0x344 Commands.#7bb6a318.From | 40 | live |
| match+0x334 #8beb922e | 16 | live |
| player+0x544 ManualShotTiming?? | 32 | live |
| player+0x550 #f089f55c | 4 | ShotContext.#f089f55c: AI serve fault value; a human reads the (IsHuman) branch |
| player+0x554 #93d36d43 | 3 | live |
| player+0x560 IsHuman? | 7 | live |
| player+0x64c Profile.Serve | 6 | live |
| player+0x650 Profile.Return | 4 | live |
| player+0x65c Profile.Volley | 5 | live |
| player+0x66c #7e28dbc0.#e1fe010c.Timing | 4 | live |
| player+0x6d4 #7e28dbc0.ShotSpecific.ErrorResolution.Min | 39 | live |
| player+0x6d8 #7e28dbc0.ShotSpecific.ErrorResolution.Max | 39 | live |
| player+0x6f4 #7e28dbc0.#719dc5ee.Long | 9 | live |
| player+0x6f8 #7e28dbc0.#719dc5ee.Short | 15 | live |
| player+0x6fc #7e28dbc0.#719dc5ee.Side | 11 | live |
| player+0x74c #7e28dbc0.HandAttributeQuality?? | 19 | live |
| player+0x768 #7e28dbc0.#be5d458f | 16 | never written (OPEN 1.10): stays 0 |
| player+0x770 #7e28dbc0.#1407106c | 34 | never written (OPEN 1.10): stays 0 -> fast-ball and wood ramps inert |
| player+0x7a0 #7e28dbc0.#03d2be3d | 13 | live |
| player+0x7a4 #7e28dbc0.#5cf9de02 | 13 | live |
| player+0x7a8 #7e28dbc0.ShotDifficulty | 2 | live |
| player+0x7d0 #7e28dbc0.#aee2d90b | 3 | live |
| player+0x7d8 #7e28dbc0.#693eedbe | 18 | never written (OPEN 1.10): stays 1000 -> every half-volley term sits at its x=1000 end |
| player+0x7e8 #7e28dbc0.#39b2f234 | 4 | live |
| player+0x840 #719dc5ee.Target | 7 | live |
| player+0xcf0 ReceiverState?.TimingState.#3fe3a099 | 12 | live |
| player+0xcf4 ReceiverState?.TimingState.#d2797eb6 | 10 | live |
| player+0xd7c ReceiverState?.AimingState?.DeviationSystem?.Random | 1 | live |
| player+0xd84 ReceiverState?.AimingState?.#3c6beee9 | 4 | set to 0.0 by fn_886612E0 and nothing else (OPEN 1.10) |
| player+0xe00 ReceiverState?.#82526c5c.Value | 9 | live |
| player+0xf54 Fatigue.Output.CurrentVigor | 21 | live |
| player+0xf88 #689dc6f2 | 10 | live |
| team+0xbc IsDouble | 3 | live |
| link:SwingCategory/#0698037d | 14 | live |
| link:SwingCategory/#f2885ba2 | 4 | live |
| link:SwingCategory/Fatality | 1 | live |
| skill:Amazing1stVolley | 4 | skill (0/1) |
| skill:BetterOnLongRallies | 16 | skill (0/1) |
| skill:BrutalVolley | 1 | skill (0/1) |
| skill:DropShotArtist | 1 | skill (0/1) |
| skill:LowVolleySpecialist | 3 | skill (0/1) |
| skill:PassingShotSniper | 2 | skill (0/1) |
| skill:ReachSwingsExpert | 15 | skill (0/1) |
| skill:SemiVolleyKing | 10 | skill (0/1) |
| skill:TenaciousCockroach | 10 | skill (0/1) |
| skill:VolleyShotsArtist | 3 | skill (0/1) |

TimingAbility (graphs 40-42) is computed but has no effect: the worst/best timing curves are identical (read from data above). S+0x564, the additive error term, is always 0 (graphs-decoded s6.9).

## 4. Situation sensitivity

How to read this: each row sets one situational input from a good to a bad value, with everything
else at the median-stat baseline, and reports the change in P(error) at three timings, launch
speed, aim efficiency and deep deviation. **At perfect timing every change is 0, for every class
and every situation**: the situational terms only act through the timing penalty curves.

#### 4a. Effect of each situation (good value -> bad value; median stats, fresh, other inputs at the baseline scenario) *(generated)*

Each cell: change in P(error) at t = +0.45 (late, 13 frames) / at t = +0.8 (very late, 11 frames) / at t = -0.6 (early, 32 frames); at t = 0 (perfect) every change is 0 for every class and situation; change in launch speed (km/h); change in mean aim efficiency; change in mean DeepDeviation (cm, + = lands shorter). '0' everywhere = the graphs of that class do not read the input. Computed from the model.

| situation | Flat Powerful | TopSpin Medium | Slice Finesse | Return Flat | Volley std | Power volley |
|---|---|---|---|---|---|---|
| time available (frames from opponent's hit to contact, S+0xCF0) | 0 | 0 | 0 | err +0.00/+0.01/+0.01; -0 km/h; eff +0.00; dev +0 | 0 | err +0.00/+0.05/+0.00; -3 km/h; eff +0.00; dev +0 |
| depth to cover (TimingState #d2797eb6, S+0xCF4, cm, I) | 0 | 0 | 0 | err +0.09/+0.18/+0.18; -4 km/h; eff +0.00; dev +0 | err +0.00/+0.12/+0.00; -2 km/h; eff +0.00; dev +0 | err +0.21/+0.06/+0.19; -0 km/h; eff +0.00; dev +0 |
| run distance to the hit point (#03d2be3d, cm) | 0 | 0 | 0 | 0 | 0 | 0 |
| required run speed (#5cf9de02, m/s) | 0 | 0 | 0 | 0 | 0 | 0 |
| run far and fast together | err +0.32/+0.29/+0.26; +0 km/h; eff -0.35; dev +20 | err +0.00/+0.00/+0.00; +0 km/h; eff -0.20; dev +38 | err +0.08/+0.13/+0.00; -1 km/h; eff +0.00; dev +49 | 0 | 0 | 0 |
| stretch: reach-swing qualifier (SwingCategory #0698037d) | err +0.36/+0.35/+0.29; -3 km/h; eff -0.20; dev +0 | err +0.14/+0.24/+0.15; +0 km/h; eff -0.20; dev +38 | err +0.11/+0.18/+0.00; -1 km/h; eff +0.00; dev +49 | 0 | 0 | 0 |
| contact height low (cm) | err +0.25/+0.19/+0.20; -1 km/h; eff -0.20; dev +0 | err +0.00/+0.17/+0.10; +0 km/h; eff +0.00; dev +20 | err +0.08/+0.13/+0.00; +0 km/h; eff +0.00; dev +19 | 0 | err +0.10/+0.18/+0.00; -6 km/h; eff -0.20; dev +0 | err +0.34/+0.15/+0.28; -11 km/h; eff -0.20; dev +0 |
| contact height high (cm) | 0 | 0 | 0 | err +0.00/+0.00/+0.00; -2 km/h; eff +0.00; dev +0 | err +0.00/+0.00/+0.00; +5 km/h; eff +0.00; dev +0 | err +0.00/+0.00/+0.00; +7 km/h; eff +0.00; dev +0 |
| incoming pace (#1407106c, km/h; INERT in retail) | err +0.40/+0.41/+0.33; -1 km/h; eff -0.20; dev +0 | err +0.17/+0.28/+0.17; +0 km/h; eff -0.20; dev +52 | err +0.10/+0.17/+0.00; +2 km/h; eff +0.00; dev +25 | err +0.01/+0.02/+0.02; -0 km/h; eff +0.00; dev +0 | err +0.00/+0.10/+0.00; +2 km/h; eff +0.00; dev +0 | err +0.24/+0.08/+0.21; +3 km/h; eff +0.00; dev +0 |
| half-volley (#693eedbe frames since bounce; INERT, stays 1000) | err +0.18/+0.10/+0.00; -1 km/h; eff -0.20; dev +0 | err +0.00/+0.15/+0.00; +0 km/h; eff +0.00; dev +29 | err +0.00/+0.08/+0.00; -1 km/h; eff +0.00; dev +28 | 0 | 0 | 0 |
| court position: 3 m behind the baseline | err +0.16/+0.06/+0.00; -1 km/h; eff +0.00; dev +0 | 0 | err +0.00/+0.06/+0.00; +0 km/h; eff +0.00; dev +0 | 0 | 0 | 0 |
| court position: inside the court (6 m from net) | err +0.00/-0.05/+0.00; +2 km/h; eff +0.00; dev +0 | 0 | 0 | 0 | 0 | 0 |
| opponent at the net (LocalOpponentPosition x) | 0 | 0 | 0 | 0 | 0 | 0 |
| fatigue (CurrentVigor) | err +0.16/+0.06/+0.00; +0 km/h; eff +0.00; dev +0 | 0 | 0 | 0 | 0 | 0 |
| pressure: trailing in the game (#689dc6f2), no skill | 0 | 0 | 0 | 0 | 0 | 0 |
| rally length (#8beb922e strokes), no skill | 0 | 0 | 0 | 0 | 0 | 0 |
| full charge (0.85 -> 1.0) | err +0.18/+0.09/+0.00; +2 km/h; eff +0.00; dev +0 | 0 | 0 | 0 | 0 | 0 |
| hand stat (rating 100 -> 30) | err +0.00/+0.15/+0.00; -2 km/h; eff +0.00; dev +0 | err +0.00/+0.00/+0.00; -0 km/h; eff +0.00; dev +0 | err +0.00/+0.00/+0.00; -4 km/h; eff +0.00; dev +0 | 0 | 0 | 0 |

#### 4b. Which shot graphs read each situational input at all (count over the 33 classes' fault / net / power / aiming graphs, live copies) *(generated)*

| situation | fault/net graphs | power graphs | aiming graphs |
|---|---|---|---|
| time available (frames from opponent's hit to contact, S+0xCF0) | 12 / 53 | 10 / 29 | 9 / 32 |
| depth to cover (TimingState #d2797eb6, S+0xCF4, cm, I) | 10 / 53 | 10 / 29 | 9 / 32 |
| run distance to the hit point (#03d2be3d, cm) | 13 / 53 | 6 / 29 | 11 / 32 |
| required run speed (#5cf9de02, m/s) | 13 / 53 | 6 / 29 | 11 / 32 |
| run far and fast together | 13 / 53 | 6 / 29 | 11 / 32 |
| stretch: reach-swing qualifier (SwingCategory #0698037d) | 14 / 53 | 15 / 29 | 14 / 32 |
| contact height low (cm) | 40 / 53 | 26 / 29 | 25 / 32 |
| contact height high (cm) | 40 / 53 | 26 / 29 | 25 / 32 |
| incoming pace (#1407106c, km/h; INERT in retail) | 34 / 53 | 25 / 29 | 23 / 32 |
| half-volley (#693eedbe frames since bounce; INERT, stays 1000) | 18 / 53 | 15 / 29 | 14 / 32 |
| court position: 3 m behind the baseline | 25 / 53 | 22 / 29 | 18 / 32 |
| court position: inside the court (6 m from net) | 25 / 53 | 22 / 29 | 18 / 32 |
| opponent at the net (LocalOpponentPosition x) | 0 / 53 | 9 / 29 | 13 / 32 |
| fatigue (CurrentVigor) | 21 / 53 | 12 / 29 | 23 / 32 |
| pressure: trailing in the game (#689dc6f2), no skill | 10 / 53 | 3 / 29 | 16 / 32 |
| rally length (#8beb922e strokes), no skill | 16 / 53 | 0 / 29 | 0 / 32 |
| full charge (0.85 -> 1.0) | 9 / 53 | 3 / 29 | 4 / 32 |
| hand stat (rating 100 -> 30) | 18 / 53 | 16 / 29 | 14 / 32 |

The owner's question, real-tennis variable by variable [model unless marked]:

| real-tennis variable | engine input | read? | effect today |
|---|---|---|---|
| incoming ball pace | #1407106c S+0x770 | read by 92 graphs, **never written** (always 0) | none; would be the largest single term (+0.40 error on Flat Powerful when late) |
| time available / reaction time | TimingState S+0xCF0 | returns, volleys | return +0.01, power volley +0.05 at t = +0.8; groundstrokes none |
| distance run to the ball | #03d2be3d S+0x7A0 | 13 fault, 11 aim graphs | alone: none; with required speed together: Flat Powerful +0.32 error, -0.35 efficiency when late |
| required run speed | #5cf9de02 S+0x7A4 | as above | as above |
| stretched / reach swing | SwingCategory #0698037d | 14 fault graphs | Flat Powerful +0.36, TopSpin Medium +0.24 when late |
| low contact (ball at the feet) | Ball+0x344 contact height | 40 fault graphs | Flat Powerful +0.25; power volley +0.34 and -11 km/h; volley std +0.18 at t = +0.8 |
| high contact | Ball+0x344 | same | no error effect; +5-7 km/h on volleys |
| half-volley | #693eedbe S+0x7D8 frames since bounce | 18 fault graphs | **inert** (stays 1000) |
| court position (behind baseline / inside) | Ball+0x340 | 25 fault graphs | Flat Powerful +0.16 from 3 m behind; inside the court -0.05 |
| opponent position (at the net) | S+0x910 | 0 fault graphs; 9 power, 13 aim graphs, only through skills | none without skills |
| fatigue | CurrentVigor S+0xF54 | 21 fault graphs | Flat Powerful +0.16 only |
| score pressure / trailing | #689dc6f2 S+0xF88 | only through skills | none without skills |
| rally length | #8beb922e | only through skills | none without skills |
| hitting harder (charge) | S+0xE00 | 9 fault graphs | Flat Powerful +0.18 at full charge, +2 km/h |
| own stroke skill | hand stat | 18 fault graphs | Flat Powerful +0.15 at t = +0.8 (rating 100 → 30); speed ≤ 4 km/h |
| spin of the incoming ball | none | no input | [unmeasured: no input exists] |
| surface | none in the shot graphs | no | none |
| wind, sun, altitude | none | no | none |

## 5. Stats and builds

#### 5a. Rating -> stat (graph 23 DefaultAttributes) and the flat ranges *(generated)*

Read from data / evaluated with the analyser kernels. Ratings below 30 give 0 (flat).

| stat | rating:stat | knees (rating) |
|---|---|---|
| serve | 30:0.00 40:0.10 50:0.20 60:0.40 70:0.60 80:0.80 90:0.90 100:1.00 | 50, 80 |
| return | 30:0.00 40:0.15 50:0.30 60:0.47 70:0.63 80:0.80 90:0.90 100:1.00 | 80 |
| forehand | 30:0.00 40:0.10 50:0.20 60:0.30 70:0.52 80:0.75 90:0.88 100:1.00 | 60, 80 |
| backhand | 30:0.00 40:0.10 50:0.20 60:0.30 70:0.52 80:0.75 90:0.88 100:1.00 | 60, 80 |
| volley | 30:0.00 40:0.10 50:0.20 60:0.40 70:0.60 80:0.80 90:0.90 100:1.00 | 50, 80 |
| power | 30:0.00 40:0.15 50:0.30 60:0.40 70:0.50 80:0.65 90:0.83 100:1.00 | 75 |
| speed | 30:0.00 40:0.10 50:0.20 60:0.40 70:0.60 80:0.80 90:0.90 100:1.00 | 50, 80 |
| stamina | 30:0.00 40:0.10 50:0.20 60:0.40 70:0.60 80:0.80 90:0.90 100:1.00 | 50, 80 |

#### 5b. Every live consumer of each stat: output range over stat 0 -> 1 and the dead rating ranges *(generated)*

One-at-a-time sweep of the stat (others at the class's median-stat baseline, perfect timing unless noted; fault graphs at t = +0.8 so the timing penalty is visible). 'flat ratings' = rating spans (30..100) over which the output does not move. Computed from the model.

| graph | class / role | stat | output | at stat 0 | at stat 1 | range | flat ratings |
|---|---|---|---|---|---|---|---|
| 9 | AimingState ProfileFactor (serve x vigor) | serve | player+0xd40 | 0.000 | 1.000 | 1.000 | none |
| 12 | VigorMax / capacity | stamina | player+0xf60 | 100.000 | 200.000 | 100.000 | none |
| 12 | VigorMax / capacity | stamina | player+0xf64 | 0.500 | 0.650 | 0.150 | none |
| 13 | FatigueConst | stamina | player+0xf5c | 1100.000 | 3300.000 | 2200.000 | none |
| 14 | Vivacity (transition speed) | speed | player+0x9f8 | 0.400 | 1.000 | 0.600 | none |
| 14 | Vivacity (transition speed) | speed | player+0x9f4 | 1.600 | 2.000 | 0.400 | none |
| 17 | SwingSpeedCoef | volley | player+0x378 | 1.161 | 1.300 | 0.139 | none |
| 17 | SwingSpeedCoef | speed | player+0x378 | 1.170 | 1.210 | 0.040 | 80-100 |
| 18 | RushSpeedCoef (run animation speed) | speed | player+0x398 | 0.880 | 1.000 | 0.120 | none |
| 22 | ServePrecision/ServePower | serve | player+0x5ac4 | 0.096 | 0.696 | 0.600 | none |
| 22 | ServePrecision/ServePower | serve | player+0x5acc | 0.136 | 0.736 | 0.600 | none |
| 22 | ServePrecision/ServePower | forehand | player+0x5ac4 | 0.132 | 0.532 | 0.400 | none |
| 22 | ServePrecision/ServePower | power | player+0x5acc | 0.132 | 0.532 | 0.400 | none |
| 38 | InputFiltering | return | player+0xdf4 | 20.000 | 40.000 | 20.000 | none |
| 38 | InputFiltering | return | player+0xdf8 | 30.000 | 50.000 | 20.000 | none |
| 40 | TimingAbility (inert) | return | player+0xd0c | 0.000 | 1.000 | 1.000 | none |
| 41 | BaselineTimingAbility (inert) | hand (FH/BH/Return/Volley by stroke) | player+0xd0c | 0.000 | 1.000 | 1.000 | none |
| 42 | VolleyTimingAbility (inert) | volley | player+0xd0c | 0.000 | 1.000 | 1.000 | none |
| 230 | VolleyStandard | volley | AimEfficiency | 0.800 | 1.000 | 0.200 | 30-80, 80-100 |
| 231 | VolleyPower | volley | AimEfficiency | 0.800 | 1.000 | 0.200 | 30-80, 80-100 |
| 232 | VolleySlice | volley | AimEfficiency | 0.800 | 1.000 | 0.200 | 30-78, 78-100 |
| 233 | VolleyDrop | volley | AimEfficiency | 0.800 | 1.000 | 0.200 | 30-72, 72-100 |
| 238 | FlatFinesse | power | PowerfulFactor | 0.751 | 0.772 | 0.022 | none |
| 238 | FlatFinesse | hand (FH/BH/Return/Volley by stroke) | PowerfulFactor | 0.711 | 0.906 | 0.194 | none |
| 239 | TopSpinFinesse | power | PowerfulFactor | 0.812 | 0.836 | 0.024 | none |
| 239 | TopSpinFinesse | hand (FH/BH/Return/Volley by stroke) | PowerfulFactor | 0.768 | 0.984 | 0.216 | none |
| 240 | SliceFinesse | power | PowerfulFactor | 0.728 | 0.745 | 0.017 | none |
| 240 | SliceFinesse | hand (FH/BH/Return/Volley by stroke) | PowerfulFactor | 0.698 | 0.849 | 0.151 | none |
| 243 | FlatMedium | power | PowerfulFactor | 0.776 | 0.911 | 0.135 | none |
| 243 | FlatMedium | hand (FH/BH/Return/Volley by stroke) | PowerfulFactor | 0.818 | 0.834 | 0.016 | none |
| 244 | TopSpinMedium | power | PowerfulFactor | 0.829 | 0.987 | 0.158 | none |
| 244 | TopSpinMedium | hand (FH/BH/Return/Volley by stroke) | PowerfulFactor | 0.879 | 0.896 | 0.017 | none |
| 245 | SliceMedium | power | PowerfulFactor | 0.829 | 0.987 | 0.158 | none |
| 245 | SliceMedium | hand (FH/BH/Return/Volley by stroke) | PowerfulFactor | 0.879 | 0.896 | 0.017 | none |
| 248 | FlatPower | power | PowerfulFactor | 0.722 | 0.892 | 0.170 | none |
| 248 | FlatPower | hand (FH/BH/Return/Volley by stroke) | PowerfulFactor | 0.758 | 0.771 | 0.013 | none |
| 249 | TopSpinPower | power | PowerfulFactor | 0.794 | 0.870 | 0.076 | none |
| 249 | TopSpinPower | hand (FH/BH/Return/Volley by stroke) | PowerfulFactor | 0.792 | 0.906 | 0.113 | none |
| 250 | SlicePower | power | PowerfulFactor | 0.776 | 0.821 | 0.046 | none |
| 250 | SlicePower | hand (FH/BH/Return/Volley by stroke) | PowerfulFactor | 0.748 | 0.930 | 0.182 | none |
| 251 | Risk | power | PowerfulFactor | 0.718 | 0.821 | 0.102 | none |
| 251 | Risk | hand (FH/BH/Return/Volley by stroke) | PowerfulFactor | 0.747 | 0.772 | 0.026 | none |
| 252 | FlatRisk | power | PowerfulFactor | 0.779 | 0.797 | 0.018 | none |
| 252 | FlatRisk | hand (FH/BH/Return/Volley by stroke) | PowerfulFactor | 0.746 | 0.908 | 0.162 | none |
| 253 | TopSpinRisk | power | PowerfulFactor | 0.843 | 0.863 | 0.020 | none |
| 253 | TopSpinRisk | hand (FH/BH/Return/Volley by stroke) | PowerfulFactor | 0.807 | 0.987 | 0.180 | none |
| 254 | SliceRisk | power | PowerfulFactor | 0.715 | 0.731 | 0.016 | none |
| 254 | SliceRisk | hand (FH/BH/Return/Volley by stroke) | PowerfulFactor | 0.685 | 0.829 | 0.144 | none |
| 255 | ServeFlatFinesse | serve | SpinBlend | 0.005 | 0.043 | 0.038 | none |
| 255 | ServeFlatFinesse | serve | PowerfulFactor | 0.005 | 0.043 | 0.038 | none |
| 255 | ServeFlatFinesse | power | SpinBlend | 0.008 | 0.014 | 0.007 | none |
| 255 | ServeFlatFinesse | power | PowerfulFactor | 0.008 | 0.014 | 0.007 | none |
| 256 | ServeFlatPowerful | serve | SpinBlend | 0.482 | 0.842 | 0.360 | none |
| 256 | ServeFlatPowerful | serve | PowerfulFactor | 0.482 | 0.842 | 0.360 | none |
| 256 | ServeFlatPowerful | power | SpinBlend | 0.479 | 0.719 | 0.240 | none |
| 256 | ServeFlatPowerful | power | PowerfulFactor | 0.479 | 0.719 | 0.240 | none |
| 257 | AdvancedServe | serve | SpinBlend | 0.602 | 0.802 | 0.200 | none |
| 257 | AdvancedServe | serve | PowerfulFactor | 0.602 | 0.802 | 0.200 | none |
| 257 | AdvancedServe | power | SpinBlend | 0.544 | 0.844 | 0.300 | none |
| 257 | AdvancedServe | power | PowerfulFactor | 0.544 | 0.844 | 0.300 | none |
| 258 | ReturnFlatFinesse | return | PowerfulFactor | 0.715 | 0.887 | 0.171 | none |
| 258 | ReturnFlatFinesse | power | PowerfulFactor | 0.756 | 0.782 | 0.026 | none |
| 259 | ReturnTopSpinFinesse | return | PowerfulFactor | 0.786 | 0.963 | 0.178 | none |
| 259 | ReturnTopSpinFinesse | power | PowerfulFactor | 0.827 | 0.856 | 0.030 | none |
| 260 | ReturnSliceFinesse | return | PowerfulFactor | 0.786 | 0.979 | 0.193 | none |
| 260 | ReturnSliceFinesse | power | PowerfulFactor | 0.831 | 0.861 | 0.030 | none |
| 261 | ReturnFlatPower | return | PowerfulFactor | 0.868 | 0.958 | 0.090 | none |
| 261 | ReturnFlatPower | power | PowerfulFactor | 0.874 | 0.934 | 0.060 | none |
| 262 | ReturnTopSpinPower | return | PowerfulFactor | 0.882 | 0.958 | 0.075 | none |
| 262 | ReturnTopSpinPower | power | PowerfulFactor | 0.884 | 0.945 | 0.060 | none |
| 263 | ReturnSlicePower | return | PowerfulFactor | 0.942 | 0.958 | 0.016 | none |
| 263 | ReturnSlicePower | power | PowerfulFactor | 0.925 | 0.989 | 0.064 | none |
| 264 | VolleyStandard | volley | PowerfulFactor | 0.850 | 0.940 | 0.090 | none |
| 265 | VolleyPower | volley | PowerfulFactor | 0.871 | 0.940 | 0.069 | none |
| 266 | VolleySlice | volley | PowerfulFactor | 0.842 | 0.880 | 0.038 | none |
| 267 | VolleyDrop | volley | PowerfulFactor | 0.875 | 0.910 | 0.035 | none |
| 271 | DropShot | power | PowerfulFactor | 0.807 | 0.822 | 0.016 | none |
| 271 | DropShot | hand (FH/BH/Return/Volley by stroke) | PowerfulFactor | 0.778 | 0.920 | 0.142 | none |
| 272 | Lob | power | PowerfulFactor | 0.193 | 0.178 | 0.016 | none |
| 272 | Lob | hand (FH/BH/Return/Volley by stroke) | PowerfulFactor | 0.222 | 0.080 | 0.142 | none |
| 273 | Smash | power | PowerfulFactor | 0.807 | 0.822 | 0.016 | none |
| 273 | Smash | hand (FH/BH/Return/Volley by stroke) | PowerfulFactor | 0.778 | 0.920 | 0.142 | none |
| 274 | FlatFinesse | hand (FH/BH/Return/Volley by stroke) | OutEfficiency | 0.013 | 0.009 | 0.004 | none |
| 276 | TopSpinFinesse | hand (FH/BH/Return/Volley by stroke) | OutEfficiency | 0.015 | 0.010 | 0.005 | none |
| 278 | SliceFinesse | hand (FH/BH/Return/Volley by stroke) | OutEfficiency | 0.009 | 0.006 | 0.003 | none |
| 283 | FlatMedium | hand (FH/BH/Return/Volley by stroke) | OutEfficiency | 0.016 | 0.012 | 0.005 | none |
| 285 | TopSpinMedium | hand (FH/BH/Return/Volley by stroke) | OutEfficiency | 0.016 | 0.012 | 0.005 | none |
| 292 | FlatPower | hand (FH/BH/Return/Volley by stroke) | FaultProbability | 0.325 | 0.171 | 0.155 | none |
| 292 | FlatPower | hand (FH/BH/Return/Volley by stroke) | OutEfficiency | 0.263 | 0.171 | 0.092 | none |
| 298 | Risk | hand (FH/BH/Return/Volley by stroke) | FaultProbability | 0.900 | 0.846 | 0.054 | none |
| 298 | Risk | hand (FH/BH/Return/Volley by stroke) | OutEfficiency | 0.600 | 0.492 | 0.108 | none |
| 300 | FlatRisk | hand (FH/BH/Return/Volley by stroke) | OutEfficiency | 0.550 | 0.460 | 0.090 | none |
| 300 | FlatRisk | hand (FH/BH/Return/Volley by stroke) | FaultProbability | 0.900 | 0.720 | 0.180 | none |
| 313 | ReturnFlatFinesse | return | FaultProbability | 0.008 | 0.006 | 0.002 | none |
| 313 | ReturnFlatFinesse | return | OutEfficiency | 0.008 | 0.006 | 0.002 | none |
| 315 | ReturnTopSpinFinesse | return | FaultProbability | 0.006 | 0.004 | 0.002 | none |
| 315 | ReturnTopSpinFinesse | return | OutEfficiency | 0.006 | 0.004 | 0.002 | none |
| 317 | ReturnSliceFinesse | return | FaultProbability | 0.001 | 0.002 | 0.001 | 30-100 |
| 317 | ReturnSliceFinesse | return | OutEfficiency | 0.001 | 0.002 | 0.001 | 30-100 |
| 323 | VolleyStandard | volley | OutEfficiency | 0.080 | 0.030 | 0.050 | none |
| 325 | VolleyPower | volley | OutEfficiency | 0.260 | 0.100 | 0.160 | none |
| 325 | VolleyPower | volley | FaultProbability | 0.260 | 0.000 | 0.260 | 74-100 |
| 327 | VolleySlice | volley | FaultProbability | 0.080 | 0.030 | 0.050 | none |
| 327 | VolleySlice | volley | OutEfficiency | 0.080 | 0.030 | 0.050 | none |
| 329 | VolleyDrop | volley | FaultProbability | 0.360 | 0.260 | 0.100 | none |
| 329 | VolleyDrop | volley | OutEfficiency | 0.360 | 0.260 | 0.100 | none |
| 331 | DropShot | hand (FH/BH/Return/Volley by stroke) | FaultProbability | 0.730 | 0.557 | 0.173 | none |
| 331 | DropShot | hand (FH/BH/Return/Volley by stroke) | OutEfficiency | 0.865 | 0.768 | 0.097 | none |
| 334 | Lob | hand (FH/BH/Return/Volley by stroke) | FaultProbability | 0.395 | 0.132 | 0.262 | none |
| 334 | Lob | hand (FH/BH/Return/Volley by stroke) | OutEfficiency | 0.297 | 0.132 | 0.165 | none |

(Rows with no effect are left out of the table above; the script prints them.)

Reading the curves [model]:
- **Dead rating range**: every stat gives 0 below rating 30, and pros are not built below 30, so
  that region is outside the roster; the curves are piecewise linear with knees at 50/60 and 80
  (Power at 75). There are no flat regions inside 30-100 for most consumers.
- **Steps, not slopes, for volleys**: the volley aim-efficiency graphs (230-233) move 0.8 → 1.0
  as a single step near rating 72-80; below and above the step the Volley stat does nothing for
  aim.
- **Power** is the only stat that moves Flat/TopSpin/Slice Medium and Powerful speed; the hand
  stat moves the Finesse rows instead. Speed and Stamina feed only movement and fatigue graphs
  (17, 18, 12-14), never shot error.
- **Stamina has no in-match fatigue-cost effect**: graphs 10 (FatigueIngame) and 13 (FatigueConst)
  outputs do not change with stamina; graph 12 raises the vigor capacity 100 → 200.
- **Serve**: the Serve stat moves serve PF 0.48 → 0.84 (Flat Powerful) and the serve fault window
  (section 6); Power moves it 0.48 → 0.72.

**Dominant builds this implies** [model]: because perfect-timing shots carry no error from any
situation, and because Power alone sets groundstroke and serve pace, a **Power + Serve + one hand
stat** build with Flat Powerful as the rally shot has no measured downside except fatigue (+0.16
error only when late) and full charge (+0.18 only when late). The return and standard volley
classes are essentially error-free at every stat level, so Return and Volley ratings buy aim
efficiency and pace, not safety.

**Community check** [data + web]: community-reference.md s7 records the online meta "TI/MD is
still king" (Topspin Invasion + Monster Defense = TenaciousCockroach), complaints of
"unreturnable serve after unreturnable serve" at launch (which led to the April 2011 serve
tuning), and returns felt underpowered. A fresh web search found no Reddit or forum thread on a
TS4 build meta beyond these; one Steam discussion recalls TS4 players getting "perfect timing every
shot" with low stats using auto-positioning [9], and the successor TopSpin 2K25 had to patch
flat-power spam [10]. Against the measurements:
- *Serve dominance*: consistent. A max-stat flat serve launches at 196 km/h and the returner's
  error does not depend on incoming pace at all (input never written).
- *Returns underpowered*: consistent. Every return uses a Finesse row, PF ≈ 0.76, about
  129 km/h launch and 48 km/h at the server's baseline at median stats.
- *TI/MD*: TopSpinInvasion measured +0.045 PF on TopSpin Power only; TenaciousCockroach cuts
  error by up to 0.11 when trailing. Both are small next to the timing band; the meta's strength is
  not explained by graph effect size alone [unmeasured: matchup outcomes need play].
- *Perfect timing with low stats*: consistent with the identical worst/best timing curves.

#### 5c. Every skill: measured effect on each consumer graph *(generated)*

delta = output with the skill minus without; 'base' at the class's median-stat baseline (perfect timing, fresh, no pressure), 'max'/'min' = the largest / smallest delta over a grid of the skill's trigger inputs (each alone and in pairs over their curve domains, including timing). PF deltas: 1 PF point is about 75-80 km/h of launch speed on Flat Powerful (section 1e). Computed from the model.

| skill | output | graphs live/read | base / max / min delta | classes where live | trigger inputs |
|---|---|---|---|---|---|
| Amazing1stVolley | AimEfficiency | 4/4 | +0.000 / +0.200 / +0.000 | VolleyDrop, VolleyPower, VolleySlice, VolleyStandard | player+0x6c4, player+0x6c8, player+0x7e8, random_dev |
| Amazing1stVolley | DeepDeviation cm | 0/4 | none found |  |  |
| Amazing1stVolley | FaultProbability | 3/4 | +0.000 / +0.000 / -0.350 | VolleyDrop, VolleyPower, VolleySlice | err_max, err_min, hit_y, link:SwingCategory/#f2885ba2, timing, volley |
| Amazing1stVolley | OutEfficiency | 4/4 | +0.000 / +0.000 / -0.350 | VolleyDrop, VolleyPower, VolleySlice, VolleyStandard | err_max, err_min, hit_y, link:SwingCategory/#f2885ba2, timing, volley |
| ApproachShotsExpert | AimEfficiency | 0/9 | none found |  |  |
| ApproachShotsExpert | DeepDeviation cm | 0/9 | none found |  |  |
| ApproachShotsExpert | PowerfulFactor | 5/6 | +0.000 / +0.093 / -0.028 | FlatFinesse, FlatPower, SliceFinesse, SlicePower, TopSpinPower | hand, link:MoveToNet/#4daa7349, link:SwingCategory/Fatality, pow_max, pow_min, power, timi |
| BetterOnLongRallies | FaultProbability | 13/15 | +0.000 / +0.000 / -0.900 | DropShot, FlatFinesse, FlatMedium, FlatPower, FlatRisk, Lob ... | ballspeed770, err_max, err_min, frames_to_contact, hit_x, hit_y, link:SwingCategory/#06980 |
| BetterOnLongRallies | OutEfficiency | 15/15 | +0.000 / +0.000 / -0.846 | DropShot, FlatFinesse, FlatMedium, FlatPower, FlatRisk, Lob ... | ballspeed770, err_max, err_min, frames_to_contact, hit_x, hit_y, link:SwingCategory/#06980 |
| BetterOnLongRallies | OutcomeNet | 1/1 | +0.000 / +0.000 / -0.100 | Smash | ballspeed770, err_max, err_min, frames_to_contact, rally, timing |
| BrutalVolley | AimEfficiency | 1/1 | +0.200 / +0.200 / -0.200 | VolleyPower | player+0x6c4, player+0x6c8, random_dev |
| BrutalVolley | DeepDeviation cm | 0/1 | none found |  |  |
| BrutalVolley | FaultProbability | 1/1 | +0.000 / +0.000 / -0.320 | VolleyPower | err_max, err_min, hit_y, link:SwingCategory/#f2885ba2, timing, volley |
| BrutalVolley | OutEfficiency | 1/1 | +0.000 / +0.000 / -0.200 | VolleyPower | err_max, err_min, hit_y, link:SwingCategory/#f2885ba2, timing, volley |
| CrushingPassingShot | PowerfulFactor | 4/9 | +0.000 / +0.163 / -0.016 | FlatPower, FlatRisk, TopSpinPower, TopSpinRisk | ballspeed770, hand, link:SwingCategory/Fatality, opp_x, pow_max, pow_min, power, timing |
| DieselHardHitter | AimEfficiency | 0/1 | none found |  |  |
| DieselHardHitter | DeepDeviation cm | 0/1 | none found |  |  |
| DieselReturner | AimEfficiency | 0/5 | none found |  |  |
| DieselReturner | DeepDeviation cm | 0/5 | none found |  |  |
| DieselReturner | PowerfulFactor | 5/6 | +0.000 / +0.065 / -0.013 | ReturnFlatFinesse, ReturnFlatPower, ReturnSliceFinesse, ReturnTopSpinFinesse, ReturnTopSpinPower | b6b22409, ballspeed770, pow_max, pow_min, power, return, timing |
| DieselServer | AimEfficiency | 5/7 | +0.000 / +0.198 / +0.000 | AdvancedServe, ServeFlatFinesse, ServeFlatPowerful, ServeSpinFinesse, ServeSpinPowerful | aim3c6b, b6b22409, random_dev, serve, serve_timing, trailing, vigor |
| DieselServer | DeepDeviation cm | 0/7 | none found |  |  |
| DropShotArtist | AimEfficiency | 0/1 | none found |  |  |
| DropShotArtist | DeepDeviation cm | 0/1 | none found |  |  |
| DropShotArtist | FaultProbability | 1/1 | +0.000 / +0.030 / -0.300 | DropShot | err_min, hit_x, hit_y, link:SwingCategory/#0698037d, rally, timing |
| DropShotArtist | OutEfficiency | 1/1 | +0.000 / +0.015 / -0.378 | DropShot | err_min, hit_x, hit_y, link:SwingCategory/#0698037d, rally, timing |
| Fatality | AimEfficiency | 0/9 | none found |  |  |
| Fatality | DeepDeviation cm | 0/9 | none found |  |  |
| FocusService | AimEfficiency | 7/7 | +0.000 / +0.100 / +0.000 | AdvancedServe, ServeFlatFinesse, ServeFlatMedium, ServeFlatPowerful, ServeSpinFinesse, ServeSpinMedium ... | b6b22409, trailing |
| FocusService | DeepDeviation cm | 0/7 | none found |  |  |
| FocusService | PowerfulFactor | 1/3 | +0.000 / +0.064 / +0.000 | ServeFlatFinesse | ff9a119d, power, serve, trailing |
| FocusService | SpinBlend | 1/3 | +0.000 / +0.064 / +0.000 | ServeFlatFinesse | ff9a119d, power, serve, trailing |
| HighlyFlammable | AimEfficiency | 0/6 | none found |  |  |
| HighlyFlammable | DeepDeviation cm | 0/6 | none found |  |  |
| HighlyFlammable | PowerfulFactor | 1/6 | +0.000 / +0.075 / -0.022 | FlatMedium | hand, link:SwingCategory/Fatality, pow_max, pow_min, power, timing |
| InsideOutMaster | AimEfficiency | 0/11 | none found |  |  |
| InsideOutMaster | DeepDeviation cm | 0/11 | none found |  |  |
| InsideOutMaster | PowerfulFactor | 4/12 | +0.000 / +0.093 / -0.086 | DropShot, FlatRisk, Lob, Smash | ballspeed770, hand, pow_max, pow_min, power, timing |
| InstantRocket | PowerfulFactor | 3/3 | +0.029 / +0.041 / -0.036 | FlatPower, SlicePower, TopSpinPower | hit_x, hit_y, link:SwingCategory/#0698037d, link:SwingCategory/Fatality, pow_max, pow_min, |
| LowVolleySpecialist | AimEfficiency | 3/3 | +0.000 / +0.200 / +0.000 | VolleyPower, VolleySlice, VolleyStandard | hit_y, player+0x6c4, player+0x6c8, random_dev, timing, volley |
| LowVolleySpecialist | DeepDeviation cm | 0/3 | none found |  |  |
| LowVolleySpecialist | FaultProbability | 3/3 | +0.000 / +0.000 / -0.103 | VolleyPower, VolleySlice, VolleyStandard | err_max, err_min, hit_y, player+0x7e8, timing, volley |
| LowVolleySpecialist | OutEfficiency | 3/3 | +0.000 / +0.000 / -0.044 | VolleyPower, VolleySlice, VolleyStandard | err_max, err_min, hit_y, player+0x7e8, timing, volley |
| LowVolleySpecialist | PowerfulFactor | 3/3 | +0.000 / +0.100 / -0.040 | VolleyPower, VolleySlice, VolleyStandard | hit_y, pow_max, pow_min |
| PassingShotSniper | AimEfficiency | 12/13 | +0.000 / +0.400 / +0.000 | FlatFinesse, FlatMedium, FlatPower, FlatRisk, SliceFinesse, SliceMedium ... | aim_long, hand, opp_x, random_dev, timing |
| PassingShotSniper | DeepDeviation cm | 12/13 | +0.000 / +0.000 / -288.000 | FlatFinesse, FlatMedium, FlatPower, FlatRisk, SliceFinesse, SliceMedium ... | aim_long, hand, opp_x, random_dev, timing |
| PassingShotSniper | FaultProbability | 2/2 | +0.000 / +0.000 / -0.200 | FlatRisk, TopSpinRisk | err_min, hit_x, hit_y, link:SwingCategory/#0698037d, rally, timing |
| PassingShotSniper | OutEfficiency | 0/2 | none found |  |  |
| PowerfulShotCounter | PowerfulFactor | 8/9 | +0.000 / +0.019 / -0.004 | DropShot, FlatFinesse, FlatMedium, FlatRisk, Lob, SliceFinesse ... | hit_x, hit_y, link:MoveToNet/#4daa7349, link:SwingCategory/#0698037d, link:SwingCategory/F |
| ReachSwingsExpert | AimEfficiency | 13/14 | +0.000 / +0.400 / +0.000 | FlatFinesse, FlatMedium, FlatPower, FlatRisk, Lob, SliceFinesse ... | aim_long, hand, link:SwingCategory/#0698037d, opp_x, random_dev, timing |
| ReachSwingsExpert | DeepDeviation cm | 13/14 | +0.000 / +0.000 / -177.500 | FlatFinesse, FlatMedium, FlatPower, FlatRisk, Lob, SliceFinesse ... | aim_long, hand, link:SwingCategory/#0698037d, opp_x, random_dev, timing |
| ReachSwingsExpert | FaultProbability | 11/14 | +0.000 / +0.000 / -0.338 | DropShot, FlatFinesse, FlatMedium, FlatPower, Lob, SliceFinesse ... | charge, err_max, err_min, hand, link:SwingCategory/#0698037d, rally, timing |
| ReachSwingsExpert | OutEfficiency | 11/14 | +0.000 / +0.000 / -0.169 | DropShot, FlatFinesse, FlatMedium, FlatPower, Lob, SliceFinesse ... | charge, err_max, err_min, hand, link:SwingCategory/#0698037d, rally, timing |
| ReachSwingsExpert | PowerfulFactor | 13/15 | +0.000 / +0.186 / -0.073 | DropShot, FlatFinesse, FlatMedium, FlatPower, FlatRisk, Lob ... | hand, link:SwingCategory/#0698037d, link:SwingCategory/Fatality, pow_max, pow_min, power,  |
| ReachSwingsExpert | player+0x3e8 | 1/1 | +0.000 / +1.000 / +0.000 | GoodTiming | timing |
| ReturnServeCounter | PowerfulFactor | 1/1 | +0.000 / +0.003 / +0.000 | ReturnFlatFinesse | hit_x, hit_y, pow_min, power, return, timing |
| SemiVolleyKing | AimEfficiency | 9/9 | +0.000 / +0.600 / +0.000 | FlatFinesse, FlatMedium, FlatPower, SliceFinesse, SliceMedium, SlicePower ... | aim_long, hand, opp_x, random_dev, since_bounce, timing |
| SemiVolleyKing | DeepDeviation cm | 9/9 | +0.000 / +0.000 / -371.500 | FlatFinesse, FlatMedium, FlatPower, SliceFinesse, SliceMedium, SlicePower ... | aim_long, hand, opp_x, random_dev, since_bounce, timing |
| SemiVolleyKing | FaultProbability | 10/10 | +0.000 / +0.000 / -0.247 | FlatFinesse, FlatMedium, FlatPower, Lob, SliceFinesse, SliceMedium ... | charge, err_max, err_min, hand, rally, since_bounce, timing |
| SemiVolleyKing | OutEfficiency | 10/10 | +0.000 / +0.000 / -0.092 | FlatFinesse, FlatMedium, FlatPower, Lob, SliceFinesse, SliceMedium ... | charge, err_max, err_min, hand, rally, since_bounce, timing |
| SemiVolleyKing | PowerfulFactor | 7/9 | +0.000 / +0.264 / -0.032 | FlatFinesse, FlatMedium, FlatPower, SliceFinesse, SlicePower, TopSpinFinesse ... | ballspeed770, hand, link:SwingCategory/Fatality, pow_max, pow_min, power, since_bounce, ti |
| ServeStickBerserker | AimEfficiency | 1/1 | +0.100 / +0.100 / +0.000 | AdvancedServe | b6b22409, serve_timing |
| ServeStickBerserker | DeepDeviation cm | 0/1 | none found |  |  |
| SliceInvasion | AimEfficiency | 0/4 | none found |  |  |
| SliceInvasion | DeepDeviation cm | 0/4 | none found |  |  |
| SliceInvasion | PowerfulFactor | 2/4 | +0.000 / +0.185 / -0.032 | SlicePower, SliceRisk | ballspeed770, hand, pow_max, pow_min, power, slices, timing |
| SmellOfBlood | AimEfficiency | 0/3 | none found |  |  |
| SmellOfBlood | DeepDeviation cm | 0/3 | none found |  |  |
| SpinServeMaster | AimEfficiency | 3/3 | +0.100 / +0.100 / +0.000 | ServeSpinFinesse, ServeSpinMedium, ServeSpinPowerful | b6b22409 |
| SpinServeMaster | DeepDeviation cm | 0/3 | none found |  |  |
| TenaciousCockroach | AimEfficiency | 0/9 | none found |  |  |
| TenaciousCockroach | DeepDeviation cm | 0/9 | none found |  |  |
| TenaciousCockroach | FaultProbability | 8/10 | +0.000 / +0.000 / -0.113 | FlatFinesse, FlatMedium, FlatPower, Lob, SliceFinesse, TopSpinFinesse ... | charge, err_max, err_min, hand, rally, timing, trailing |
| TenaciousCockroach | OutEfficiency | 10/10 | +0.000 / +0.000 / -0.086 | FlatFinesse, FlatMedium, FlatPower, Lob, SliceFinesse, SliceMedium ... | charge, err_max, err_min, hand, rally, timing, trailing |
| TopSpinInvasion | AimEfficiency | 0/4 | none found |  |  |
| TopSpinInvasion | DeepDeviation cm | 0/4 | none found |  |  |
| TopSpinInvasion | PowerfulFactor | 1/4 | +0.000 / +0.045 / -0.009 | TopSpinPower | hand, link:SwingCategory/Fatality, pow_max, pow_min, power, topspins |
| VolleyShotsArtist | AimEfficiency | 3/3 | +0.000 / +0.200 / -0.200 | VolleyDrop, VolleySlice, VolleyStandard | player+0x6c4, player+0x6c8, random_dev |
| VolleyShotsArtist | DeepDeviation cm | 0/3 | none found |  |  |
| VolleyShotsArtist | FaultProbability | 3/3 | +0.000 / +0.000 / -0.261 | VolleyDrop, VolleySlice, VolleyStandard | err_max, err_min, hit_y, link:SwingCategory/#f2885ba2, timing, volley |
| VolleyShotsArtist | OutEfficiency | 3/3 | +0.000 / +0.000 / -0.200 | VolleyDrop, VolleySlice, VolleyStandard | err_max, err_min, hit_y, link:SwingCategory/#f2885ba2, timing, volley |
| WrongFootExpert | AimEfficiency | 0/3 | none found |  |  |
| WrongFootExpert | DeepDeviation cm | 0/3 | none found |  |  |

(Per-graph rows: `--full-skills`.)

Skills that act in code, not in graphs: PoisonedSlices (sets the receiver's #aee2d90b S+0x7D0 = 1 for the owner's slices; its effect is the 'poisoned' input row below), InstantRocket (charge curve: S+0xE00 curve identical in retail, only the unused S+0xE08 changes), SpectacularVolleys (clip family flag S+0x388) (traits-and-skills s2).

PoisonedSlices on the receiver (low ball, contact 40 cm):

| receiver class | timing | P(error) | aim efficiency |
|---|---|---|---|
| Flat Powerful | +0.00 | 0.00 -> 0.00 | 0.80 -> 0.60 |
| Flat Powerful | +0.45 | 0.25 -> 0.37 | 0.40 -> 0.25 |
| TopSpin Medium | +0.00 | 0.00 -> 0.00 | 1.00 -> 0.80 |
| TopSpin Medium | +0.45 | 0.00 -> 0.00 | 0.45 -> 0.40 |
| Slice Finesse | +0.00 | 0.00 -> 0.00 | 1.00 -> 0.80 |
| Slice Finesse | +0.45 | 0.08 -> 0.08 | 0.40 -> 0.40 |
| Return Flat | +0.00 | 0.00 -> 0.00 | 1.00 -> 1.00 |
| Return Flat | +0.45 | 0.00 -> 0.00 | 0.40 -> 0.40 |

## 6. Serve and return (after TU1)

#### 6a. Human serve faults (disc): the no-fault gauge window *(generated)*

Serve fault graphs 307 (Finesse), 308 (Medium), 309 (Powerful), 311 (Advanced) are a step for a human server (graphs-decoded s11.2 item 6): fault = 0 or 1, no roll. The table gives the gauge-timing interval (S+0x66C, the serve 'timing' value) with fault = 0, by Serve rating and vigor. #3c6beee9 (S+0xD84) is 0 (its writer is not found). Computed from the model.

| serve | graph | Serve rating | vigor 1.0 | 0.8 | 0.5 | 0.2 |
|---|---|---|---|---|---|---|
| Flat Finesse | 307 | min (30) | always | always | always | always |
| Flat Finesse | 307 | median (51) | always | always | always | always |
| Flat Finesse | 307 | p90 (72) | always | always | always | always |
| Flat Finesse | 307 | max (100) | always | always | always | always |
| Flat Medium | 308 | min (30) | always | always | always | always |
| Flat Medium | 308 | median (51) | always | always | always | always |
| Flat Medium | 308 | p90 (72) | always | always | always | always |
| Flat Medium | 308 | max (100) | always | always | always | always |
| Flat Powerful | 309 | min (30) | -0.30..+0.79 | -0.30..+0.79 | -0.30..+0.79 | -0.30..+0.79 |
| Flat Powerful | 309 | median (51) | -0.40..+0.89 | -0.40..+0.89 | -0.30..+0.79 | -0.30..+0.79 |
| Flat Powerful | 309 | p90 (72) | -0.40..+0.89 | -0.40..+0.89 | -0.30..+0.79 | -0.30..+0.79 |
| Flat Powerful | 309 | max (100) | -0.40..+0.89 | -0.40..+0.89 | -0.40..+0.89 | -0.40..+0.89 |
| Advanced flat | 311 | min (30) | -0.20..+0.59 | -0.20..+0.59 | -0.20..+0.59 | -0.20..+0.59 |
| Advanced flat | 311 | median (51) | -0.40..+0.79 | -0.40..+0.79 | -0.20..+0.59 | -0.20..+0.59 |
| Advanced flat | 311 | p90 (72) | -0.40..+0.79 | -0.40..+0.79 | -0.20..+0.59 | -0.20..+0.59 |
| Advanced flat | 311 | max (100) | -0.40..+0.79 | -0.40..+0.79 | -0.40..+0.79 | -0.40..+0.79 |

Target (S+0x840) no-fault interval at perfect gauge, median server: 450..1500 cm (outside it the serve faults whatever the timing). Its writer and meaning are not traced (marked unknown).

Gauge-timing to frames: section 3a gives the serve timing curve (|t| < 0.3 = 13.5 frames). The AI's fault is ShotContext #f089f55c (S+0x550) directly, set in code (not measured here).

TU1 changes in this table [model, `--tu`]: only the Advanced serve at median Serve: the window
narrows from -0.40..+0.79 to -0.20..+0.59 already at vigor 0.8 (on the disc only at vigor 0.5).
Flat Finesse and Flat Medium serves have **no timing fault at all** ("always" in the table, on
both data sets): a human's second-serve-style serve never double-faults through timing; it can
only fault through #3c6beee9 or Target (below).

#### 6b. Serve speed and spin blend against Serve, Power, gauge timing and vigor (disc) *(generated)*

PowerfulFactor from graphs 255/256/257 (they also write the spin blend). Launch km/h from the serve template at that PF (serve_T). Vigor is not an input of the serve power graphs; #689dc6f2 (S+0xF88, 'trailing') and #ff9a119d (S+0x558) are. Computed from the model.

| serve | stats | t=0: PF, launch | t=+0.3 | t=+0.6 | t=-0.3 |
|---|---|---|---|---|---|
| Flat Powerful | min | 0.40 122 (76) | 0.30 116 (72) | 0.29 114 (71) | 0.30 116 (72) |
| Flat Powerful | median | 0.56 135 (84) | 0.43 124 (77) | 0.42 122 (76) | 0.43 124 (77) |
| Flat Powerful | p90 | 0.76 156 (97) | 0.62 138 (86) | 0.60 138 (86) | 0.62 138 (86) |
| Flat Powerful | max | 1.00 196 (122) | 0.84 166 (103) | 0.82 161 (100) | 0.84 166 (103) |
| Kick Powerful | min | 0.40 114 (71) | 0.30 110 (68) | 0.29 110 (68) | 0.30 110 (68) |
| Kick Powerful | median | 0.56 123 (76) | 0.43 116 (72) | 0.42 116 (72) | 0.43 116 (72) |
| Kick Powerful | p90 | 0.76 133 (83) | 0.62 125 (78) | 0.60 125 (78) | 0.62 125 (78) |
| Kick Powerful | max | 1.00 152 (95) | 0.84 139 (86) | 0.82 138 (86) | 0.84 139 (86) |
| Advanced flat | min | 0.50 148 (92) | 0.28 135 (84) | 0.22 132 (82) | 0.28 135 (84) |
| Advanced flat | median | 0.65 156 (97) | 0.38 141 (88) | 0.29 135 (84) | 0.38 141 (88) |
| Advanced flat | p90 | 0.79 171 (106) | 0.50 148 (92) | 0.39 141 (88) | 0.50 148 (92) |
| Advanced flat | max | 1.00 196 (122) | 0.67 161 (100) | 0.53 148 (92) | 0.67 161 (100) |
| Flat Medium | min | 0.07 104 (65) | 0.07 104 (65) | 0.07 104 (65) | 0.07 104 (65) |
| Flat Medium | median | 0.12 106 (66) | 0.12 106 (66) | 0.12 106 (66) | 0.12 106 (66) |
| Flat Medium | p90 | 0.20 110 (68) | 0.20 110 (68) | 0.20 110 (68) | 0.20 110 (68) |
| Flat Medium | max | 0.28 114 (71) | 0.28 114 (71) | 0.28 114 (71) | 0.28 114 (71) |

Flat Powerful PF with trailing (S+0xF88) = 0 / 0.5 / 1: 0.56 / 0.56 / 0.56

Flat Powerful PF with ff9a119d (S+0x558) = 0 / 0.5 / 1: 0.56 / 0.78 / 1.00

TU1 does not change serve speed: the TU1 run of 6b is identical. #ff9a119d (S+0x558) raises
Flat Powerful PF from 0.56 to 1.00; its writer is not traced [unmeasured: meaning unknown].

#### 6c. Serve placement: aim efficiency against the aiming value #3c6beee9 (disc) *(generated)*

Aiming graphs 215-221: Efficiency = curve8/9(#3c6beee9 (S+0xD84) + a random term), blended by Serve; for a serve FinalEfficiency = Efficiency = QuadEfficiency (aiming.md s4), so 0 = the inner quad and 1 = the lines quad. The same #3c6beee9 enters the human fault step (fault when it pushes the sum past 0.5). Its writer is not found (graphs-decoded s11.2), so its in-game range is UNKNOWN; at the State.bin default 0 every serve has efficiency about 0. Cells: mean efficiency over the random roll / fault at perfect gauge (F = fault). Computed from the model.

| serve | graph | stats | vigor | #3c6beee9=0.30 | 0.40 | 0.45 | 0.50 | 0.55 |
|---|---|---|---|---|---|---|---|---|
| Flat Medium | 218 | min | 1.00 | 0.30 | 0.57 | 0.70 | 1.00 F | 1.00 F |
| Flat Medium | 218 | min | 0.50 | 0.30 | 0.57 | 0.70 | 1.00 F | 1.00 F |
| Flat Medium | 218 | max | 1.00 | 0.43 | 0.70 | 0.85 | 1.00 F | 1.00 F |
| Flat Medium | 218 | max | 0.50 | 0.43 | 0.70 | 0.85 | 1.00 F | 1.00 F |
| Flat Powerful | 220 | min | 1.00 | 0.26 | 0.38 | 0.51 | 0.82 F | 1.00 F |
| Flat Powerful | 220 | min | 0.50 | 0.26 | 0.39 | 0.57 | 0.78 F | 0.94 F |
| Flat Powerful | 220 | max | 1.00 | 0.30 | 0.43 | 0.50 | 1.00 F | 1.00 F |
| Flat Powerful | 220 | max | 0.50 | 0.30 | 0.43 | 0.58 | 0.91 F | 1.00 F |
| Kick Powerful | 221 | min | 1.00 | 0.26 | 0.38 | 0.51 | 0.82 F | 1.00 F |
| Kick Powerful | 221 | min | 0.50 | 0.26 | 0.39 | 0.57 | 0.78 F | 0.94 F |
| Kick Powerful | 221 | max | 1.00 | 0.30 | 0.43 | 0.50 | 1.00 F | 1.00 F |
| Kick Powerful | 221 | max | 0.50 | 0.30 | 0.43 | 0.58 | 0.91 F | 1.00 F |
| Advanced flat | 215 | min | 1.00 | 0.31 | 0.50 | 0.67 | 0.91 F | 1.00 F |
| Advanced flat | 215 | min | 0.50 | 0.31 | 0.50 | 0.68 | 0.89 F | 1.00 F |
| Advanced flat | 215 | max | 1.00 | 0.40 | 0.60 | 0.80 | 1.00 F | 1.00 F |
| Advanced flat | 215 | max | 0.50 | 0.40 | 0.61 | 0.80 | 0.99 F | 1.00 F |

TU1 changes in 6c [model, `--tu`]: Advanced flat efficiency drops at every aiming value, most
for a tired server (at #3c6beee9 = 0.5 and vigor 0.5: 0.89 → 0.62 at min stats, 0.99 → 0.82 at
max).

#### 6d. The returner (disc) *(generated)*

All returns use the Return*Finesse rows (template bc29d202) whatever the tier; the ReturnPower graphs 261-263 are never selected (section 1). Incoming pace #1407106c (S+0x770) is never written, so a 200 km/h serve and a 120 km/h serve are returned with the same error. Live inputs are frames to contact S+0xCF0 and depth difference S+0xCF4. P(error) at median Return, t = +0.45 / +0.8:

| class | frames to contact | depth diff cm | P(err) t=+0.45 | t=+0.8 |
|---|---|---|---|---|
| ReturnFlatFinesse | 10 | 0 | 0.00 | 0.01 |
| ReturnFlatFinesse | 10 | 200 | 0.01 | 0.03 |
| ReturnFlatFinesse | 45 | 0 | 0.00 | 0.01 |
| ReturnFlatFinesse | 45 | 200 | 0.01 | 0.03 |
| ReturnTopSpinFinesse | 10 | 0 | 0.00 | 0.01 |
| ReturnTopSpinFinesse | 10 | 200 | 0.00 | 0.01 |
| ReturnTopSpinFinesse | 45 | 0 | 0.00 | 0.00 |
| ReturnTopSpinFinesse | 45 | 200 | 0.00 | 0.01 |
| ReturnSliceFinesse | 10 | 0 | 0.00 | 0.00 |
| ReturnSliceFinesse | 10 | 200 | 0.00 | 0.00 |
| ReturnSliceFinesse | 45 | 0 | 0.00 | 0.00 |
| ReturnSliceFinesse | 45 | 200 | 0.00 | 0.00 |

Return Flat at median stats: PF 0.76, launch 129 (80), at the server's baseline 48 (30).

**What a returner can do** [model + code]: choose the stroke (Flat, TopSpin or Slice return, all
Finesse rows, 129 km/h at median stats), the timing (the same 20-frame curve as groundstrokes,
error ≤ 0.03 everywhere), the direction (stick direction only). Nothing the server does changes
the return's error except the frames to contact and the depth difference, and those only by
≤ 0.03 at median stats.

**Is a serve-heavy build beatable?** On the measurements: the serve fault for a human is a
deterministic step that a max-stat server avoids over a 1.3-unit gauge window (-0.40..+0.89, about 26 frames on the serve curve);
the flat serve is 196 km/h; the return's error is independent of serve pace; returns are capped
at Finesse pace. The returner's only lever is placement. Whether that is enough is a play
question [unmeasured: needs match data], but **no rule in the graphs makes a fast serve harder
to return than a slow one**.

## 7. Net play and short balls

#### 7a. Which graphs read the reaction-time and ball-at-the-feet inputs *(generated)*

Every analyser graph scanned for each input (bound by the State.bin layout). 'reachable' = the graph belongs to a shot class that a shipped row can select (Risk classes, Defensive and the ReturnPower graphs are not). Read from data.

| input | graphs | reachable class graphs | unreachable class graphs | other graphs |
|---|---|---|---|---|
| #2c63ee31 frames to the chosen hit sample (C24) | 0 | - | - | - |
| #8760acf5 distance to the hit point, cm (C28) | 24 | - | - | 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 58, 59, 60, 71, 72, 73, 159, 160, 161, 162 |
| #420a6cfc required run speed, m/s (C2C) | 26 | - | - | 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 58, 59, 60, 71, 72, 73, 159, 160, 161, 162, 169, 170 |
| BallDifficulty (C30) | 0 | - | - | - |
| ShotDifficulty copy (C34) | 0 | - | - | - |
| #2f6930a4 mirrored hit-point coordinate, height? (C38) | 35 | - | - | 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 58, 59, 60, 71, 72, 73, 76, 77, 78, 79, 80, 84, 85, 86, 89, 90, 93, 159, 160, 161, 162 |
| Spin (C3C) | 0 | - | - | - |
| frames as float (C40) | 0 | - | - | - |
| #03d2be3d distance to the ball sample, m (S+0x7A0) | 31 | DropShot.aim, FlatFinesse.aim, FlatFinesse.fault, FlatFinesse.net, FlatFinesse.power, FlatMedium.aim, FlatMedium.net, FlatMedium.power, FlatPower.aim, FlatPower | - | 24 |
| #5cf9de02 required speed, m/s (S+0x7A4) | 31 | DropShot.aim, FlatFinesse.aim, FlatFinesse.fault, FlatFinesse.net, FlatFinesse.power, FlatMedium.aim, FlatMedium.net, FlatMedium.power, FlatPower.aim, FlatPower | - | 24 |
| BallDifficulty (S+0x764) | 9 | - | - | 24, 234, 268, 269, 270, 319, 320, 321, 322 |
| ShotDifficulty (S+0x7A8) | 7 | Smash.aim | Risk.aim, Risk.fault, Risk.net, Risk.power | 335, 336 |
| TimingState #3fe3a099 frames to contact (S+0xCF0) | 65 | ReturnFlatFinesse.aim, ReturnFlatFinesse.fault, ReturnFlatFinesse.net, ReturnFlatFinesse.power, ReturnSliceFinesse.aim, ReturnSliceFinesse.fault, ReturnSliceFin | ReturnFlatPower.aim, ReturnFlatPower.fault, ReturnFlatPower.net, ReturnFlatPower | 14, 51, 52, 53, 54, 58, 71, 73, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 89, 90, 93, 148, 152, 153, 154, 166, 167, 173, 174, 175, 179, 180, 227 |
| TimingState #d2797eb6 depth difference (S+0xCF4) | 35 | ReturnFlatFinesse.aim, ReturnFlatFinesse.fault, ReturnFlatFinesse.net, ReturnFlatFinesse.power, ReturnSliceFinesse.aim, ReturnSliceFinesse.fault, ReturnSliceFin | ReturnFlatPower.aim, ReturnFlatPower.fault, ReturnFlatPower.net, ReturnFlatPower | 14, 148, 175, 176, 177, 227 |
| contact height, ball From.y (Ball+0x344) | 94 | DropShot.aim, DropShot.fault, DropShot.net, DropShot.power, FlatFinesse.aim, FlatFinesse.fault, FlatFinesse.net, FlatFinesse.power, FlatMedium.aim, FlatMedium.f | FlatRisk.aim, FlatRisk.fault, FlatRisk.net, FlatRisk.power, ReturnFlatPower.aim, | 227, 335, 337 |
| LocalOpponentPosition.x (S+0x910) | 22 | FlatFinesse.aim, FlatFinesse.power, FlatMedium.aim, FlatMedium.power, FlatPower.aim, FlatPower.power, Lob.aim, SliceFinesse.aim, SliceMedium.aim, SliceMedium.po | FlatRisk.aim, FlatRisk.power, SliceRisk.aim, TopSpinRisk.aim, TopSpinRisk.power | - |
| #693eedbe frames since bounce (S+0x7D8, stays 1000) | 48 | DropShot.aim, DropShot.fault, DropShot.power, FlatFinesse.aim, FlatFinesse.fault, FlatFinesse.power, FlatMedium.aim, FlatMedium.fault, FlatMedium.power, FlatPow | FlatRisk.aim, FlatRisk.fault, FlatRisk.power, SliceRisk.aim, SliceRisk.fault, Sl | 337 |
| #1407106c incoming pace (S+0x770, never written) | 92 | DropShot.aim, DropShot.fault, DropShot.power, FlatFinesse.aim, FlatFinesse.fault, FlatFinesse.net, FlatFinesse.power, FlatMedium.aim, FlatMedium.fault, FlatMedi | FlatRisk.aim, FlatRisk.fault, FlatRisk.power, ReturnFlatPower.aim, ReturnFlatPow | 7, 8, 227, 280, 281, 282, 289, 290, 291, 337 |

**(e) Inputs the engine already has for reaction time and the ball at the feet** [data + code]:
the receiver hit-point block `ReceiverState.#c7b7bdac` holds C24 frames to the hit sample, C28
distance to the hit point, C2C required run speed, C30 BallDifficulty, C34 ShotDifficulty, C38 a
hit-point coordinate (height, inferred), C3C Spin, C40 frames as float (OPEN 3.8). Measured
above: **no shot class graph reads any of them.** C28, C2C and C38 are read only by AI graphs
(43-60 and 159-162: the AI's shot choice and the AI's own timing expression, which writes the AI's
ManualShotTiming), so **the AI's timing gets worse with distance, run speed and contact height,
the human's does not**. C24, C30, C34, C3C and C40 are read by no graph. The per-sample copies
S+0x7A0/S+0x7A4 (distance, required speed) are read by the groundstroke and drop-shot graphs, not
by any volley graph. BallDifficulty S+0x764 is read only by graphs that never run (234, 268-270,
319-322). ShotDifficulty S+0x7A8 is read by the Smash aim graph and the unreachable Risk class.
What volley graphs do read: contact height (Ball+0x344), TimingState S+0xCF0 (frames to contact)
and S+0xCF4 (depth difference).

#### 7b. What the volleyer gets: P(error), PF and aim efficiency against contact height and frames to contact *(generated)*

Median Volley stat, fresh. Volley timing grade from section 3 (|t| < 0.3 = 10 frames). Computed from the model.

| class | contact cm | timing | P(error) | net share | PF | aim eff |
|---|---|---|---|---|---|---|
| VolleyStandard (FlatVolley) | 20 | +0.00 | 0.00 | 0.00 | 0.67 | 0.60 |
| VolleyStandard (FlatVolley) | 20 | +0.45 | 0.10 | 0.00 | 0.45 | 0.20 |
| VolleyStandard (FlatVolley) | 50 | +0.00 | 0.00 | 0.00 | 0.67 | 0.60 |
| VolleyStandard (FlatVolley) | 50 | +0.45 | 0.10 | 0.00 | 0.48 | 0.20 |
| VolleyStandard (FlatVolley) | 90 | +0.00 | 0.00 | 0.00 | 0.78 | 0.80 |
| VolleyStandard (FlatVolley) | 90 | +0.45 | 0.00 | 0.00 | 0.68 | 0.20 |
| VolleyStandard (FlatVolley) | 140 | +0.00 | 0.00 | 0.00 | 0.86 | 0.80 |
| VolleyStandard (FlatVolley) | 140 | +0.45 | 0.00 | 0.00 | 0.76 | 0.40 |
| VolleyPower | 20 | +0.00 | 0.00 | 0.50 | 0.63 | 0.60 |
| VolleyPower | 20 | +0.45 | 0.34 | 0.50 | 0.40 | 0.20 |
| VolleyPower | 50 | +0.00 | 0.00 | 0.50 | 0.63 | 0.60 |
| VolleyPower | 50 | +0.45 | 0.34 | 0.50 | 0.40 | 0.20 |
| VolleyPower | 90 | +0.00 | 0.00 | 0.34 | 0.76 | 0.80 |
| VolleyPower | 90 | +0.45 | 0.16 | 0.34 | 0.58 | 0.20 |
| VolleyPower | 140 | +0.00 | 0.00 | 0.15 | 0.88 | 0.80 |
| VolleyPower | 140 | +0.45 | 0.00 | 0.15 | 0.72 | 0.40 |
| VolleySlice | 20 | +0.00 | 0.00 | 0.30 | 0.66 | 0.80 |
| VolleySlice | 20 | +0.45 | 0.07 | 0.30 | 0.43 | 0.40 |
| VolleySlice | 50 | +0.00 | 0.00 | 0.30 | 0.66 | 0.80 |
| VolleySlice | 50 | +0.45 | 0.07 | 0.30 | 0.47 | 0.40 |
| VolleySlice | 90 | +0.00 | 0.00 | 0.14 | 0.76 | 0.80 |
| VolleySlice | 90 | +0.45 | 0.04 | 0.14 | 0.62 | 0.40 |
| VolleySlice | 140 | +0.00 | 0.00 | 0.05 | 0.85 | 0.80 |
| VolleySlice | 140 | +0.45 | 0.03 | 0.05 | 0.72 | 0.40 |
| VolleyDrop | 20 | +0.00 | 0.00 | 0.30 | 0.87 | 0.60 |
| VolleyDrop | 20 | +0.45 | 0.46 | 0.30 | 0.70 | 0.40 |
| VolleyDrop | 50 | +0.00 | 0.00 | 0.30 | 0.87 | 0.60 |
| VolleyDrop | 50 | +0.45 | 0.46 | 0.30 | 0.70 | 0.40 |
| VolleyDrop | 90 | +0.00 | 0.00 | 0.14 | 0.88 | 0.80 |
| VolleyDrop | 90 | +0.45 | 0.36 | 0.14 | 0.76 | 0.40 |
| VolleyDrop | 140 | +0.00 | 0.00 | 0.05 | 0.88 | 0.80 |
| VolleyDrop | 140 | +0.45 | 0.34 | 0.05 | 0.78 | 0.40 |

Reaction time (frames to contact S+0xCF0) and depth to cover (S+0xCF4), t = +0.45, contact 90 cm:

| class | frames to contact | depth diff cm | P(error) |
|---|---|---|---|
| VolleyStandard | 5 | 0 | 0.00 |
| VolleyStandard | 5 | 150 | 0.00 |
| VolleyStandard | 10 | 0 | 0.00 |
| VolleyStandard | 10 | 150 | 0.00 |
| VolleyStandard | 20 | 0 | 0.00 |
| VolleyStandard | 20 | 150 | 0.00 |
| VolleyStandard | 40 | 0 | 0.00 |
| VolleyStandard | 40 | 150 | 0.00 |
| VolleyPower | 5 | 0 | 0.16 |
| VolleyPower | 5 | 150 | 0.18 |
| VolleyPower | 10 | 0 | 0.16 |
| VolleyPower | 10 | 150 | 0.18 |
| VolleyPower | 20 | 0 | 0.16 |
| VolleyPower | 20 | 150 | 0.18 |
| VolleyPower | 40 | 0 | 0.00 |
| VolleyPower | 40 | 150 | 0.16 |

#### 7c. What the passer gets: opponent position *(generated)*

Ground classes at median stats, t = +0.45 (late), opponent at the net (x = 300 cm from it) vs the baseline (1200). Without skills the opponent's position changes nothing (section 4); the passing-shot skills read it. Computed from the model.

| class | skill | opponent at baseline | opponent at net |
|---|---|---|---|
| Flat Finesse | none | PF 0.55, eff 1.00, dev 97, err 0.00 | PF 0.55, eff 1.00, dev 97, err 0.00 |
| Flat Finesse | PassingShotSniper | PF 0.55, eff 1.00, dev 97, err 0.00 | PF 0.55, eff 1.00, dev 50, err 0.00 |
| Flat Finesse | CrushingPassingShot | PF 0.55, eff 1.00, dev 97, err 0.00 | PF 0.55, eff 1.00, dev 97, err 0.00 |
| Flat Medium | none | PF 0.66, eff 0.60, dev 159, err 0.00 | PF 0.66, eff 0.60, dev 159, err 0.00 |
| Flat Medium | PassingShotSniper | PF 0.66, eff 0.60, dev 159, err 0.00 | PF 0.66, eff 1.00, dev 54, err 0.00 |
| Flat Medium | CrushingPassingShot | PF 0.66, eff 0.60, dev 159, err 0.00 | PF 0.66, eff 0.60, dev 159, err 0.00 |
| Flat Powerful | none | PF 0.71, eff 0.60, dev 105, err 0.00 | PF 0.71, eff 0.60, dev 105, err 0.00 |
| Flat Powerful | PassingShotSniper | PF 0.71, eff 0.60, dev 105, err 0.00 | PF 0.71, eff 1.00, dev 15, err 0.00 |
| Flat Powerful | CrushingPassingShot | PF 0.71, eff 0.60, dev 105, err 0.00 | PF 0.81, eff 0.60, dev 105, err 0.00 |
| TopSpin Finesse | none | PF 0.68, eff 0.80, dev 121, err 0.00 | PF 0.68, eff 0.80, dev 121, err 0.00 |
| TopSpin Finesse | PassingShotSniper | PF 0.68, eff 0.80, dev 121, err 0.00 | PF 0.68, eff 1.00, dev 50, err 0.00 |
| TopSpin Finesse | CrushingPassingShot | PF 0.68, eff 0.80, dev 121, err 0.00 | PF 0.68, eff 0.80, dev 121, err 0.00 |
| TopSpin Medium | none | PF 0.88, eff 0.60, dev 159, err 0.00 | PF 0.88, eff 0.60, dev 159, err 0.00 |
| TopSpin Medium | PassingShotSniper | PF 0.88, eff 0.60, dev 159, err 0.00 | PF 0.88, eff 1.00, dev 54, err 0.00 |
| TopSpin Medium | CrushingPassingShot | PF 0.88, eff 0.60, dev 159, err 0.00 | PF 0.88, eff 0.60, dev 159, err 0.00 |
| TopSpin Powerful | none | PF 0.78, eff 0.60, dev 105, err 0.00 | PF 0.78, eff 0.60, dev 105, err 0.00 |
| TopSpin Powerful | PassingShotSniper | PF 0.78, eff 0.60, dev 105, err 0.00 | PF 0.78, eff 1.00, dev 15, err 0.00 |
| TopSpin Powerful | CrushingPassingShot | PF 0.78, eff 0.60, dev 105, err 0.00 | PF 0.86, eff 0.60, dev 105, err 0.00 |

**What the volleyer gets** [model]: the standard volley is error-free at every timing and contact
height measured; the power volley costs up to 0.34 error and 11 km/h on a ball at the feet when
late; reaction time (frames to contact) changes the power volley by ≤ 0.16 and the standard volley
not at all. Volley speeds: power volley 119, flat 101, slice 78, drop 67 km/h at PF 1. After a
volley the swing clip blocks locomotion for a median 39 frames after contact (section 8a).

**What the passer gets** [model]: nothing from the opponent's position unless the passer has
PassingShotSniper (aim efficiency up to +0.4, deep deviation down to 15 cm) or
CrushingPassingShot (+0.08..0.16 PF on FlatPower/TopSpinPower). A plain build hits the same shot
whether the opponent is at the net or on the baseline.

**Floating and short balls** [code]: there is no "short ball" class. The overhead situation flag
(`Context.IsSmash`, S+0x5DA, copied from command byte C+0x98) replaces any shot with the Smash row
(151 km/h at PF 1); its writer (what counts as "overhead") is not traced here [unmeasured]. The
groundstroke graphs read contact height and court position (inside the court: -0.05 error), but
no input says "the ball is slow or high".

**Put-away swing (Fatality)** [code, controls s17.2]: a Fatality clip is played when the class is
FlatPower or FlatFinesse, the shot is not a tap (power S+0xE00 > 0.15), not (AI and S+0x4E0), and
**not** (sticky RB `PC+0x3D` and inside 300 cm of the net), and a clip of category Fatality
matches the other keys. So following the shot to the net with RB **blocks** the put-away clip.
**Drop volley** = Slice + Risk (LT or RT) in volley mode (row 18); the drop shot is the same at the
baseline (row 32). LT + X is also a drop shot, an input quirk of the shipped map.

## 8. Responsiveness

Two kinds of delay are kept apart below: **game logic** (rules in code and data, which run the
same on any hardware) and **console or emulator effects** (display, pad polling, frame pacing),
which this note does not measure [unmeasured: needs hardware capture]. Frame counts are at 60 fps.

#### 8a. Swing clips: frames from clip start to contact, and from contact to the Out window *(generated)*

Read from data/gameplay/animation_clips.yaml (committed dump of AnimationsDB.bin; command and sha256 in its header). 'to Out' = (TransitionEvent[1].Position - EventRacket phase) x (FrameCount - 1): the frames after contact until the clip's Out transition window opens, i.e. `fn_886CD3C8` anim busy measured at contact (movement-and-animation s1.1). At play rate 1; the swing play rate multiplies by SwingSpeedCoef S+0x378 (graph 17: 1.16-1.30, section 5b) unless the clip sets IgnoreSpeedCoef. p10 / median / p90 over the clips of each family.

| family | clips | IgnoreSpeedCoef | start -> contact (frames) | contact -> Out window (frames, rate 1) | same at rate 1.19 |
|---|---|---|---|---|---|
| groundstroke FH/BH | 1170 | 72 | 40 / 48 / 75 | 23 / 36 / 48 | 324 / 504 / 672 ms |
| return | 89 | 19 | 37 / 45 / 55 | 20 / 26 / 37 | 274 / 367 / 518 ms |
| volley | 306 | 0 | 37 / 45 / 67 | 29 / 39 / 53 | 406 / 546 / 742 ms |
| smash | 38 | 0 | 28 / 59 / 79 | 33 / 42 / 58 | 462 / 588 / 815 ms |
| serve | 17 | 0 | 86 / 100 / 122 | 19 / 34 / 40 | 266 / 476 / 560 ms |

#### 8b. Standing start, reversal and stop: frame by frame (coordinator item a)

What the code notes establish, in order from the stick deflection:

| step | rule | frames | where | status |
|---|---|---|---|---|
| 1 | stick dead zone: radial 0.4 of full throw, rescaled to 0..1 | 0 (but the first 40% of throw does nothing) | InputMapper data (controls s3, table) | [code] |
| 2 | Stick_Move running-average filter word = 10 | up to 10 if it is a 10-sample average | InputMapper item +0x20 (controls s3); feeds the aim/move intent `fn_8869C010`, not the polar channel | meaning M (not verified); [unmeasured] |
| 3 | stick sampled once per frame into the stick ring (S+0x4CC) | 0-1 | `fn_88679C78` | [code]; order within the frame not established |
| 4 | path from Stick_MovePolar to the move command RequiredMove (S+0x9D0/0x9D4) for free movement | ? | not traced in the notes | **unknown** |
| 5 | planner state while receiving: state 0 Wait until `frames_since_opp_hit >= profile+0x1DC`; states 13 Hold / 14 BallWindow (powers zeroed) / 17-18 Ready (> 5 frames, < 20/30-frame gates) | 0 to the reaction delay | `fn_886B8468` (movement-and-ai A.3) | [code]; profile+0x1DC value not given in the notes [unmeasured] |
| 6 | sector choice of the move set from the direction relative to facing | 0 | movement-and-animation s2.1 | rounding of sector angles **open** (s5 item 6) |
| 7 | locomotion transition rule: bridging clip (Tr_*, Idle_To_*) or Allow cut; BlendIn 15 frames (10 for Allow rule 9) | 15 (10) blend | TransitionRuleList data (movement-and-animation s2.2) | blend count [data]; blend curve **open** (assumed linear, I) |
| 8 | root moves when the start clip's root track moves | ? | root tracks are not in the committed clip dump | **unknown** [unmeasured] |
| 9 | Mover velocity: running mean over 3 frames | ≈1 frame lag in the *measured* speed (not in the root motion itself) | Mover `fn_8866CDC8` (repositioning s5) | [code]; it delays the planner's view of speed (prep table, regime choice), not the first step |
| 10 | prep ticks before a swing: 10 frames standing still, 15-20 when running (table PT+0x17C), lead PT+0x1AC = 15 | 25-35 frames of slack required | `fn_886887C0`, `fn_88688948` | [code + data]; affects which run mode is valid, not the first step |

Clip lengths for orientation [data]: Idle_To_* clips are 121-170 frames (p10-p90, start + run +
stop in one clip), Tr_Jog_* 62-169, Tr_Sidesteps_* 43-136. Without root tracks, the frame at which
the root first moves inside them is not measurable from the dump.

**Direction reversal** [code]: the retarget interrupt (ball within 250 cm, locomotion not Idle,
angle tests 0.96 / 1.82 / 2.36 rad) sends the planner to state 7 **Turn**, which holds the heading
for a counter of **10 frames** (P+0x128), or to state 8 **Stop** when the heading dot is positive.
Then a new transition rule (15-frame blend) starts. Known minimum: 10 frames of heading hold plus
the blend; root-motion onset unknown.

**Stopping** [code]: state 8 sets the speed override to 0 and waits **at least 4 frames and until
locomotion has stopped**; the speed override only changes when the new value differs by more than
0.4 (`lo_override_update`). The stop clip's length is data-driven and its root deceleration is not
in the dump [unmeasured].

#### 8c. After a shot: every frame stick input is ignored, reinterpreted or cancelled (item b)

In order from the commit to free movement:

| frames (relative to contact) | rule | effect on the stick | where |
|---|---|---|---|
| -12 | automatic commit (`PlayerTuning+0x740` = 12): shot row, power and **aim direction** are frozen | stick changes after this do not change the shot | controls s4; aiming.md s2 (`fn_886B0490` reads `Stick_Aiming` once) [code] |
| -12 → 0 | swing clip plays; the planner is in a swing state (4 / 16) | movement stick still drives InputNotation for the *next* ball only | movement-and-ai A.3 |
| 0 → +36 median (23-48, groundstroke; +39 volley; +26 return; +34 serve; rate 1) | swing clip's Out window not open: no locomotion transition can leave the clip | stick deflection does not start a run; gp7's busy flag reports `remaining - 20` and raises "ends within 20 frames" | section 8a [data]; gp7 s4; movement-and-animation s2.2 |
| after contact | replan check (states 4, 6, 12, 16): once the clip passes its marked event (I: contact), "arrived" = lateral < 40 cm and along within -30..0 or -20..30 cm; arrived with ≤ 10 frames left → state 9 Replan (hold, re-search), arrived earlier → state 13 Hold | the planner holds position instead of following the stick | `fn_886A9678` (movement-and-ai A.4c) [code] |
| from the opponent's hit plan (opponent C24 > 0) | human repositioning decider `fn_8869B928`: stick power < 0.1 → no mode; stick within 40° of the net direction → net rush (rules in 8e) | a forward stick is **reinterpreted** as "go to the net" (direction overridden with the heading to the net point while mode 2 lasts) | repositioning s1, s3.1 [code] |
| 0 → +40 after the stamp `(ctx+0x84)+0x10` (disc) | sideways-push cancel: while the rally count is non-zero, a push at 60-120° outward from more than 100 cm off centre zeroes the three move powers | sideways stick **cancelled** | `fn_886795C8`, Settings RepositioningSettings 29eac4a0 (int 40, float 1.0) [code + data] |
| same window, TU1 | the cancel applies only on the stamp frame and while a push held since the stamp never lets go (latch `this+0x16E`); releasing the stick frees the player for the rest of the window | cancelled only for a carried-over push | TU1 `0x88679CD8`, flag `e26ae391` (title-update-balance s3.4) [code] |
| any | behaviour flag changes at most every 5 frames | the animation behaviour (incl. Rush) can lag the stick by up to 5 frames | repositioning s3.1 [code + data] |
| any, sprint | RB sprint acts only during repositioning runs and only at vigor ≥ 0.1 | RB ignored while chasing a ball and when exhausted | repositioning s5; timing-and-fatigue [code] |
| AI only | post-swing hold 16-24 frames (graph 117) | not applied to humans | repositioning s3.3 |

The stamp's meaning is inferred, not established; if it is the player's own contact frame, the
disc cancel covers contact to +40 frames, overlapping the clip's Out tail.

#### 8d. One stick, two jobs: when it aims and when it moves (item c)

- **Aim** [code, aiming.md s2-4]: the target selector reads `Stick_Aiming` (S+0x430, left stick,
  0.4 dead zone) **once**, inside the shot planner 12 frames before contact. Only the direction
  matters; the magnitude is ignored (any push past the dead zone aims at the quad edge).
- **Move** [code]: on every other frame the same stick (as `Stick_MovePolar` S+0x440/0x444 and
  `Stick_Move` S+0x448) drives movement: candidate scoring (InputNotation; with the human
  reach-flattening flag PT+0x1B8 the stick, not distance, picks among nearly equally reachable hit
  points), the state-15 volley-or-bounce choice (stick power > 0.4 and angle toward the ball), the
  swing-start test (stick intensity and angle window), the AltSwing test (stick angle > 1.5 rad and
  power > 0.2 in the last 10 frames), and the repositioning decider.
- **Lockouts that exist because of the double role**:
  1. The sideways-push cancel (8c). It fires on exactly the push a player holds to aim wide
     (sideways, outward, from off centre) in the 40 frames after the stamp. The TU1 change keeps the
     cancel **only** for a push that was already held at the stamp and never released, i.e. a
     carried-over aim, and frees any fresh push. This **supports** the coordinator's hypothesis.
  2. The net-rush rule (8e). A deep aim is "stick forward"; the repositioning decider reads a
     forward stick within 40° of the net as a net rush. Outside the baseline box it needs RB. The
     box is -1100 < x < -700, i.e. 0.9-4.9 m *inside* the baseline, so a player standing on or
     behind the baseline (where most rally shots are hit) is outside it and needs RB. This is
     **consistent with** the hypothesis (a held deep aim at the baseline does not start a rush),
     but inside the box a held forward aim *does* start one, so the protection is partial.
  3. The new mode-2 refusal within 20 frames of the opponent's planned hit.
  Verdict: the code facts are consistent with the hypothesis and the TU1 latch is the strongest
  evidence for it; the intent itself is not written anywhere, so it is **supported, not proven**.

#### 8e. The net rush: every condition that refuses or delays it (item d)

[code, repositioning s3.1; data `04_RepositioningSettings.yaml`]

| condition | value | effect |
|---|---|---|
| decider runs only while recovering | own team not in possession and the opponent's frames to hit point > 0 | no rush before the opponent's hit is planned |
| already at the net | x > -500 cm (`8154a27b`) | mode 0 (no rush) |
| stick released | move power S+0x9DC < 0.1 | mode 0 |
| stick direction | within 40° (`324f5246`) of the direction to the net point | otherwise no rush |
| distance | net point more than 175 cm away (`0081913b`) | otherwise no rush |
| position or RB | inside the box -1100 < x < -700, \|z\| < 400 (outside play mode 1), **or** RB (`@ReqFastRepos` S+0x4E2) held | otherwise refused |
| event timing | refused while the opponent's planned hit is fewer than 20 frames away (`98294782`) | delay up to 20 frames |
| behaviour flag | changes at most every 5 frames (`7440a9da`) | the Rush animation behaviour can start up to 5 frames late |
| sideways-push cancel | (8c) zeroes move powers for outward sideways pushes | a diagonal rush toward the side can be cut in the first 40 frames |
| swing Out window | (8a) median 36 frames after a groundstroke | the run cannot start before the clip's Out window opens |
| sprint | RB sprint only during repositioning, vigor ≥ 0.1 | an exhausted player rushes at normal speed |
| at the net with RB | locomotion scale = VolleySpeedCoef 1.15 | speed-up, not a refusal |
| put-away | sticky RB within 300 cm of the net blocks the Fatality clip | a side effect on the next shot |

#### 8f. Console and emulator effects (not game logic)

Not measured here [unmeasured: requires capture on hardware or an emulator with frame logging]:
pad polling rate, the frame at which input is sampled relative to simulation, render latency,
vsync and frame pacing. The game logic above is frame-locked at 60 Hz (EngineConfig Frequency = 60,
controls s5.2); an emulator that runs the simulation at a different rate would change every
frame count in this section in wall-clock terms.

---

## Summary: the 10 largest gaps and the 10 rules most likely to feel bad

### The 10 largest gaps from real tennis

| # | gap | measured | where it lives |
|---|---|---|---|
| 1 | Incoming pace does not matter: a 200 km/h ball is returned like a 120 km/h one | #1407106c read by 92 graphs, never written; would add +0.40 error when late | code (missing writer of S+0x770) |
| 2 | Perfect timing erases every situation: running, stretching, low contact, fatigue add 0 error at t = 0 | all Δerror = 0 at t = 0 (section 4a) | graphs (fault graphs: situation terms only scale the timing penalty) |
| 3 | No error over a 19-frame band (t = -0.6..+0.45) for most groundstrokes; latest reachable timing +0.58 | section 3b/3c | data (SwingTimingSelectionList) + graphs (0.15 dead zone, safe |t| < 0.3) + constant (12-frame auto-commit) |
| 4 | Ball slows to about half by the baseline; groundstroke peak 148 vs ~193 km/h; serve max 196 vs 253-263 km/h; median first serve 135 vs 189 km/h | sections 1a-1f | data (template rows, a4 = 0.06) + graphs (PF caps) |
| 5 | Serve pace is not a threat to the returner and returns are capped at Finesse pace | return error ≤ 0.03; ReturnPower graphs 261-263 never used | code/data (row selection: Return*Finesse rows) |
| 6 | Second-serve-style serves (Finesse, Medium) cannot fault on timing; human serve faults are a deterministic step | 6a "always" | graphs 307/308 (no timing input), 309/311 step |
| 7 | Timing ability stat is inert: everyone has the same window | worst = best curves | data (02_PlayerSettings) |
| 8 | Opponent position, score pressure and rally length matter only through skills | 0 effect without skills | graphs (inputs only in skill branches) |
| 9 | Reaction time and the ball at the feet barely affect the human volleyer; the AI uses them, the human does not | 7a/7b: no class graph reads C24-C40; standard volley error 0 | graphs (AI timing graphs 159-162 only) |
| 10 | No surface, spin rate or incoming spin; topspin speeds up after the bounce; harder = more spin | sections 2a/2c | code (one bounce routine) + data (graphs 241/242, template spin) |

### The 10 rules most likely to feel bad

| # | rule | length | where it lives |
|---|---|---|---|
| 1 | Swing clip blocks movement until its Out window: median 36 frames after a groundstroke contact, 39 after a volley (at rate 1) | 23-53 frames | data (AnimationsDB TransitionEvent[1].Position) |
| 2 | Shot, power and aim frozen 12 frames before contact; later stick and button changes ignored | 12 frames | hard-coded tuning constant PlayerTuning+0x740 |
| 3 | Sideways-push cancel after the stamp (disc); TU1 limits it to a carried-over push | 40 frames | data (RepositioningSettings int 40) + code `fn_886795C8` |
| 4 | Net rush needs RB unless inside the 0.9-4.9 m box; refused within 20 frames of the opponent's hit; stick within 40° | 20 frames | data (`04_RepositioningSettings.yaml`) + code `fn_8869B928` |
| 5 | Turn on a retarget interrupt holds the heading | 10 frames | hard-coded counter P+0x128 (`fn_886B8468`) |
| 6 | Stop waits until locomotion stops | ≥ 4 frames | hard-coded (`fn_886B8468` state 8) |
| 7 | Locomotion transitions blend in | 15 frames (10 for one Allow rule) | data (TransitionRuleList BlendIn) |
| 8 | Replan/hold: an "arrived" player holds position (state 13) or re-searches (state 9); BallWindow zeroes move power | 40 cm / 10 frames | hard-coded pool constants (`fn_886A9678`) |
| 9 | Aim uses direction only (magnitude ignored) behind a 0.4 radial dead zone; hit point chosen by stick, not distance (reach flattening) | — | data (InputMapper dead zone; PT+0x1B8 flag) + code |
| 10 | Behaviour (Rush) flag rate limit; sprint only while repositioning and at vigor ≥ 0.1; re-press resets the charge | 5 frames | data (`7440a9da`) + code |

### Not measured, and why

- Root-motion onset of start, turn and stop clips: root tracks are not in the committed clip dump.
- Sector angle rounding and the transition blend curve: open in movement-and-animation.md s5.
- The free-movement path from the stick to RequiredMove and the reaction delay `profile+0x1DC`:
  not traced in the notes.
- Writers of #3c6beee9 (serve aim value), #ff9a119d, serve Target S+0x840 and the overhead flag:
  not found; their in-game ranges are unknown, so 6a-6c show sweeps, not live values.
- Real hit rates per timing band, matchup outcomes, and whether a serve build is beatable in
  practice: need play logs.
- Real bounce and baseline speeds for comparison: no cited source found.
- Console, pad and emulator latency: needs hardware capture.

### Sources

1. ATP Tour, "Sinner 2024 Insights" (Tennis Data Innovations): https://www.atptour.com/en/news/sinner-2024-insights
2. J. Fawcette, "Groundstroke Velocities Soar", Tennisplayer.net: https://old.tennisplayer.net/members/mystheavyball/jim_fawcette/new_top_ball_speed
3. "Fastest recorded tennis serves", Wikipedia (Groth, Isner; Tennis Abstract averages as summarised in the search): https://en.wikipedia.org/wiki/Fastest_recorded_tennis_serves
4. Guinness World Records, "Fastest serve of a tennis ball (male)": https://www.guinnessworldrecords.com/world-records/fastest-serve-of-a-tennis-ball-male
5. ATP Tour, "Fonseca: Infosys ATP Beyond the Numbers, March 2025": https://www.atptour.com/en/news/fonseca-infosys-atp-beyond-the-numbers-march-2025
6. Hawk-Eye spin study (CORE repository PDF): https://core.ac.uk/download/288373955.pdf
7. On the T, "AO Leaderboard: Line Hitting" (Hawk-Eye net clearance): https://on-the-t.github.io/2016/11/05/AOLeaderboard-Line-Hitting
8. Hawk-Eye groundstroke study, Journal of Sports Analytics: https://sage.cnpereading.com/doi/10.3233/JSA-200406
9. Steam community discussion (TopSpin 2K25 forum, recalls TS4): https://steamcommunity.com/app/1785650/discussions/0/4516632348042834638
10. TopSpin 2K25 patch notes (flat power shot changes): https://2k.com/games/topspin-2k/topspin-2k25/patch-updates/

Community claims also come from `docs/gameplay/community-reference.md` s7 (ITST forum and Operation
Sports threads cited there). The top-10 serve averages in [3] were reported by the search summary as
a Tennis Abstract analysis; the primary Tennis Abstract page was not opened.
