# retune-v0 group: aim_depth

**What the player should feel:** The stroke rating now matters for placement (efficiency x (0.65 + 0.35 x stroke stat)), and the depth pull depends on timing: a Perfect drive lands within 40 cm of the aimed depth, a poor one 2-3 m short (spec 7a c, 7b).

Files:

- `expressions.json`

| change | where | retail | retune-v0 | source |
|---|---|---|---|---|
| FlatMedium efficiency at hand stat 0 | Expressions graph 202 node 77 | [0.0, 0.3, 0.2, 0.2] [0.3, 0.55, 0.4, 0.4] [0.55, 0.75, 0.6, 0.6] [0.75, 0.9, 0.8, 0.8] [0.9, 1.0, 1.0, 1.0] | [0.0, 0.2, 0.13, 0.13] [0.2, 0.5, 0.26, 0.26] [0.5, 0.7, 0.39000002, 0.39000002] [0.7, 0.9, 0.52, 0.52] [0.9, 1.0, 0.65, 0.65] | spec 7a (c): x0.65 of the hand-1 curve (node 75) |
| FlatMedium depth pull, poor quality | Expressions graph 202 node 17 | [0.0, 0.5, 500.0, 200.0] [0.5, 1.0, 200.0, 0.0] | [0.0, 0.5, 310.0, 255.0] [0.5, 1.0, 255.0, 200.0] | spec 7b (outside Good: 2-3.1 m) |
| FlatMedium depth pull, poor quality | Expressions graph 202 node 20 | [0.0, 0.5, 400.0, 100.0] [0.5, 1.0, 100.0, 0.0] | [0.0, 0.5, 310.0, 255.0] [0.5, 1.0, 255.0, 200.0] | spec 7b (outside Good: 2-3.1 m) |
| FlatMedium depth pull, top quality | Expressions graph 202 node 21 | [0.0, 1.0, 100.0, 0.0] | [0.0, 1.0, 40.0, 0.0] | spec 7b (Perfect: 0-40 cm) |
| FlatMedium depth pull, top quality | Expressions graph 202 node 18 | [0.0, 1.0, 50.0, 0.0] | [0.0, 1.0, 40.0, 0.0] | spec 7b (Perfect: 0-40 cm) |
| FlatMedium quality -> depth branch | Expressions graph 202 node 76 | [0.0, 0.5, 0.0, 0.0] [0.5, 1.0, 0.0, 1.0] | [0.0, 0.6, 0.0, 0.0] [0.6, 0.85, 0.0, 1.0] | judgement (fit to spec 7b bands) |
| TopSpinMedium efficiency at hand stat 0 | Expressions graph 203 node 79 | [0.0, 0.3, 0.2, 0.2] [0.3, 0.55, 0.4, 0.4] [0.55, 0.75, 0.6, 0.6] [0.75, 0.9, 0.8, 0.8] [0.9, 1.0, 1.0, 1.0] | [0.0, 0.3, 0.13, 0.13] [0.3, 0.5, 0.26, 0.26] [0.5, 0.7, 0.39000002, 0.39000002] [0.7, 0.9, 0.52, 0.52] [0.9, 1.0, 0.65, 0.65] | spec 7a (c): x0.65 of the hand-1 curve (node 78) |
| TopSpinMedium depth pull, poor quality | Expressions graph 203 node 26 | [0.0, 0.5, 500.0, 200.0] [0.5, 1.0, 200.0, 0.0] | [0.0, 0.5, 310.0, 255.0] [0.5, 1.0, 255.0, 200.0] | spec 7b (outside Good: 2-3.1 m) |
| TopSpinMedium depth pull, poor quality | Expressions graph 203 node 29 | [0.0, 0.5, 400.0, 100.0] [0.5, 1.0, 100.0, 0.0] | [0.0, 0.5, 310.0, 255.0] [0.5, 1.0, 255.0, 200.0] | spec 7b (outside Good: 2-3.1 m) |
| TopSpinMedium depth pull, top quality | Expressions graph 203 node 14 | [0.0, 1.0, 100.0, 0.0] | [0.0, 1.0, 40.0, 0.0] | spec 7b (Perfect: 0-40 cm) |
| TopSpinMedium depth pull, top quality | Expressions graph 203 node 25 | [0.0, 1.0, 50.0, 0.0] | [0.0, 1.0, 40.0, 0.0] | spec 7b (Perfect: 0-40 cm) |
| TopSpinMedium quality -> depth branch | Expressions graph 203 node 77 | [0.0, 0.5, 0.0, 0.0] [0.5, 1.0, 0.0, 1.0] | [0.0, 0.6, 0.0, 0.0] [0.6, 0.85, 0.0, 1.0] | judgement (fit to spec 7b bands) |
| SliceMedium efficiency at hand stat 0 | Expressions graph 204 node 78 | [0.0, 0.3, 0.2, 0.2] [0.3, 0.55, 0.4, 0.4] [0.55, 0.75, 0.6, 0.6] [0.75, 0.9, 0.8, 0.8] [0.9, 1.0, 1.0, 1.0] | [0.0, 0.3, 0.13, 0.13] [0.3, 0.5, 0.26, 0.26] [0.5, 0.7, 0.39000002, 0.39000002] [0.7, 0.9, 0.52, 0.52] [0.9, 1.0, 0.65, 0.65] | spec 7a (c): x0.65 of the hand-1 curve (node 76) |
| SliceMedium depth pull, poor quality | Expressions graph 204 node 24 | [0.0, 0.5, 500.0, 200.0] [0.5, 1.0, 200.0, 0.0] | [0.0, 0.5, 310.0, 255.0] [0.5, 1.0, 255.0, 200.0] | spec 7b (outside Good: 2-3.1 m) |
| SliceMedium depth pull, poor quality | Expressions graph 204 node 13 | [0.0, 0.5, 400.0, 100.0] [0.5, 1.0, 100.0, 0.0] | [0.0, 0.5, 310.0, 255.0] [0.5, 1.0, 255.0, 200.0] | spec 7b (outside Good: 2-3.1 m) |
| SliceMedium depth pull, top quality | Expressions graph 204 node 28 | [0.0, 1.0, 100.0, 0.0] | [0.0, 1.0, 40.0, 0.0] | spec 7b (Perfect: 0-40 cm) |
| SliceMedium depth pull, top quality | Expressions graph 204 node 20 | [0.0, 1.0, 50.0, 0.0] | [0.0, 1.0, 40.0, 0.0] | spec 7b (Perfect: 0-40 cm) |
| SliceMedium quality -> depth branch | Expressions graph 204 node 77 | [0.0, 0.5, 0.0, 0.0] [0.5, 1.0, 0.0, 1.0] | [0.0, 0.6, 0.0, 0.0] [0.6, 0.85, 0.0, 1.0] | judgement (fit to spec 7b bands) |
| FlatPower efficiency at hand stat 0 | Expressions graph 205 node 85 | [0.0, 0.3, 0.2, 0.2] [0.3, 0.55, 0.4, 0.4] [0.55, 0.8, 0.6, 0.6] [0.8, 0.9, 0.8, 0.8] [0.9, 1.0, 1.0, 1.0] | [0.0, 0.2, 0.13, 0.13] [0.2, 0.5, 0.26, 0.26] [0.5, 0.7, 0.39000002, 0.39000002] [0.7, 0.9, 0.52, 0.52] [0.9, 1.0, 0.65, 0.65] | spec 7a (c): x0.65 of the hand-1 curve (node 84) |
| FlatPower depth pull, poor quality | Expressions graph 205 node 17 | [0.0, 0.5, 400.0, 200.0] [0.5, 1.0, 200.0, 0.0] | [0.0, 0.5, 310.0, 255.0] [0.5, 1.0, 255.0, 200.0] | spec 7b (outside Good: 2-3.1 m) |
| FlatPower depth pull, poor quality | Expressions graph 205 node 26 | [0.0, 0.5, 200.0, 100.0] [0.5, 1.0, 100.0, 0.0] | [0.0, 0.5, 310.0, 255.0] [0.5, 1.0, 255.0, 200.0] | spec 7b (outside Good: 2-3.1 m) |
| FlatPower depth pull, top quality | Expressions graph 205 node 18 | [0.0, 1.0, 30.0, 0.0] | [0.0, 1.0, 40.0, 0.0] | spec 7b (Perfect: 0-40 cm) |
| FlatPower depth pull, top quality | Expressions graph 205 node 10 | [0.0, 1.0, 50.0, 0.0] | [0.0, 1.0, 40.0, 0.0] | spec 7b (Perfect: 0-40 cm) |
| FlatPower quality -> depth branch | Expressions graph 205 node 83 | [0.0, 0.4, 0.0, 0.0] [0.4, 0.8, 0.0, 1.0] [0.8, 1.0, 1.0, 1.0] | [0.0, 0.6, 0.0, 0.0] [0.6, 0.85, 0.0, 1.0] [0.85, 1.0, 1.0, 1.0] | judgement (fit to spec 7b bands) |
| TopSpinPower efficiency at hand stat 0 | Expressions graph 206 node 83 | [0.0, 0.3, 0.2, 0.2] [0.3, 0.55, 0.4, 0.4] [0.55, 0.75, 0.6, 0.6] [0.75, 0.9, 0.8, 0.8] [0.9, 1.0, 1.0, 1.0] | [0.0, 0.2, 0.13, 0.13] [0.2, 0.5, 0.26, 0.26] [0.5, 0.7, 0.39000002, 0.39000002] [0.7, 0.9, 0.52, 0.52] [0.9, 1.0, 0.65, 0.65] | spec 7a (c): x0.65 of the hand-1 curve (node 84) |
| TopSpinPower depth pull, poor quality | Expressions graph 206 node 18 | [0.0, 0.5, 400.0, 200.0] [0.5, 1.0, 200.0, 0.0] | [0.0, 0.5, 310.0, 255.0] [0.5, 1.0, 255.0, 200.0] | spec 7b (outside Good: 2-3.1 m) |
| TopSpinPower depth pull, poor quality | Expressions graph 206 node 27 | [0.0, 0.5, 200.0, 100.0] [0.5, 1.0, 100.0, 0.0] | [0.0, 0.5, 310.0, 255.0] [0.5, 1.0, 255.0, 200.0] | spec 7b (outside Good: 2-3.1 m) |
| TopSpinPower depth pull, top quality | Expressions graph 206 node 28 | [0.0, 1.0, 30.0, 0.0] | [0.0, 1.0, 40.0, 0.0] | spec 7b (Perfect: 0-40 cm) |
| TopSpinPower depth pull, top quality | Expressions graph 206 node 26 | [0.0, 1.0, 100.0, 0.0] | [0.0, 1.0, 40.0, 0.0] | spec 7b (Perfect: 0-40 cm) |
| TopSpinPower quality -> depth branch | Expressions graph 206 node 82 | [0.0, 0.4, 0.0, 0.0] [0.4, 0.8, 0.0, 1.0] [0.8, 1.0, 1.0, 1.0] | [0.0, 0.6, 0.0, 0.0] [0.6, 0.85, 0.0, 1.0] [0.85, 1.0, 1.0, 1.0] | judgement (fit to spec 7b bands) |
| SlicePower efficiency at hand stat 0 | Expressions graph 207 node 83 | [0.0, 0.3, 0.2, 0.2] [0.3, 0.55, 0.4, 0.4] [0.55, 0.75, 0.6, 0.6] [0.75, 0.9, 0.8, 0.8] [0.9, 1.0, 1.0, 1.0] | [0.0, 0.2, 0.13, 0.13] [0.2, 0.5, 0.26, 0.26] [0.5, 0.7, 0.39000002, 0.39000002] [0.7, 0.9, 0.52, 0.52] [0.9, 1.0, 0.65, 0.65] | spec 7a (c): x0.65 of the hand-1 curve (node 81) |
| SlicePower depth pull, poor quality | Expressions graph 207 node 8 | [0.0, 0.5, 400.0, 200.0] [0.5, 1.0, 200.0, 0.0] | [0.0, 0.5, 310.0, 255.0] [0.5, 1.0, 255.0, 200.0] | spec 7b (outside Good: 2-3.1 m) |
| SlicePower depth pull, poor quality | Expressions graph 207 node 26 | [0.0, 0.5, 200.0, 100.0] [0.5, 1.0, 100.0, 0.0] | [0.0, 0.5, 310.0, 255.0] [0.5, 1.0, 255.0, 200.0] | spec 7b (outside Good: 2-3.1 m) |
| SlicePower depth pull, top quality | Expressions graph 207 node 27 | [0.0, 1.0, 30.0, 0.0] | [0.0, 1.0, 40.0, 0.0] | spec 7b (Perfect: 0-40 cm) |
| SlicePower depth pull, top quality | Expressions graph 207 node 25 | [0.0, 1.0, 100.0, 0.0] | [0.0, 1.0, 40.0, 0.0] | spec 7b (Perfect: 0-40 cm) |
| SlicePower quality -> depth branch | Expressions graph 207 node 82 | [0.0, 0.4, 0.0, 0.0] [0.4, 0.8, 0.0, 1.0] [0.8, 1.0, 1.0, 1.0] | [0.0, 0.6, 0.0, 0.0] [0.6, 0.85, 0.0, 1.0] [0.85, 1.0, 1.0, 1.0] | judgement (fit to spec 7b bands) |

Notes:

- Applied to the Medium and Powerful groundstroke classes (graphs 202-207), the strokes of almost every rally. Finesse (188-190), returns (224-229) and the risk classes have other graph shapes and are unchanged in v0.
- Depth follows the aiming graph's quality value, which is the retail timing shape plus the situation terms (running, low contact). So it is a timing rule with the retail asymmetry (an early release is forgiven more than a late one), and a bad situation also pulls the ball short. The spec's purely timing-based bands need t divided by W (code) to be exact.
- Grade rows (AimingResolution VeryGood..VeryBad) are not touched: retail only reads Good.

Generated by `python3 tuning/retune-v0/make_patches.py` from the values in `docs/design/retune-spec.md` at commit 93e3761.
