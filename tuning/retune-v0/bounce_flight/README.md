# retune-v0 group: bounce_flight

**What the player should feel:** Balls lose speed at the bounce instead of gaining it: heavy topspin keeps about 84%, a flat drive about 78-83%, slice about 72% and skids low; topspin powerful drives fly higher with more drag and kick up, slice powerful stays lower (spec 3).

Files:

- `settings.disc.ShotPalette.yaml`
- `settings.tu1.ShotPalette.yaml`

| change | where | retail | retune-v0 | source |
|---|---|---|---|---|
| bounce speed loss vs spin_a, row 0 | Settings ShotDef[0] BounceConfig/527725aa | [-0.4, 0.0, 0.05, -0.2] | [-0.3, 0.0, 0.16, 0.22] | spec 3 (Powerful rows; same curve on the family's other rows) |
| bounce speed loss vs spin_a, row 2 | Settings ShotDef[2] BounceConfig/527725aa | [-0.2, 0.0, 0.1, -0.2] | [-0.3, 0.0, 0.16, 0.22] | spec 3 (Powerful rows; same curve on the family's other rows) |
| bounce speed loss vs spin_a, row 4 | Settings ShotDef[4] BounceConfig/527725aa | [-0.4, 0.0, 0.05, -0.2] | [-0.3, 0.0, 0.16, 0.22] | spec 3 (Powerful rows; same curve on the family's other rows) |
| bounce speed loss vs spin_a, row 6 | Settings ShotDef[6] BounceConfig/527725aa | [-0.2, 0.0, 0.1, -0.15] | [-0.3, 0.0, 0.16, 0.22] | spec 3 (Powerful rows; same curve on the family's other rows) |
| bounce speed loss vs spin_a, row 8 | Settings ShotDef[8] BounceConfig/527725aa | [-0.4, 0.0, 0.05, -0.05] | [-0.3, 0.0, 0.16, 0.22] | spec 3 (Powerful rows; same curve on the family's other rows) |
| bounce speed loss vs spin_a, row 10 | Settings ShotDef[10] BounceConfig/527725aa | [-0.2, 0.0, 0.1, -0.15] | [-0.3, 0.0, 0.16, 0.22] | spec 3 (Powerful rows; same curve on the family's other rows) |
| bounce speed loss vs spin_a, row 12 | Settings ShotDef[12] BounceConfig/527725aa | [-0.4, 0.0, 0.05, -0.1] | [-0.3, 0.0, 0.16, 0.22] | spec 3 (Powerful rows; same curve on the family's other rows) |
| bounce speed loss vs spin_a, row 14 | Settings ShotDef[14] BounceConfig/527725aa | [-0.2, 0.0, 0.1, -0.2] | [-0.3, 0.0, 0.16, 0.22] | spec 3 (Powerful rows; same curve on the family's other rows) |
| bounce speed loss vs spin_a, row 1 | Settings ShotDef[1] BounceConfig/527725aa | [0.0, 0.4, 0.0, 0.125] | [0.0, 0.2, 0.22, 0.3] | spec 3 (Powerful rows; same curve on the family's other rows) |
| bounce speed loss vs spin_a, row 5 | Settings ShotDef[5] BounceConfig/527725aa | [0.0, 0.4, 0.0, 0.15] | [0.0, 0.2, 0.22, 0.3] | spec 3 (Powerful rows; same curve on the family's other rows) |
| bounce speed loss vs spin_a, row 9 | Settings ShotDef[9] BounceConfig/527725aa | [0.0, 0.4, 0.0, 0.15] | [0.0, 0.2, 0.22, 0.3] | spec 3 (Powerful rows; same curve on the family's other rows) |
| bounce speed loss vs spin_a, row 13 | Settings ShotDef[13] BounceConfig/527725aa | [0.0, 0.3, 0.05, 0.1] | [0.0, 0.2, 0.22, 0.3] | spec 3 (Powerful rows; same curve on the family's other rows) |
| bounce out-elevation, row 0 | Settings ShotDef[0] BounceConfig/e96ae850 | [0.0, 1.5, 0.0, 1.45] | [0.0, 1.5, 0.0, 1.62] | spec 3 (gain 1.08) |
| bounce out-elevation, row 4 | Settings ShotDef[4] BounceConfig/e96ae850 | [0.0, 1.5, 0.0, 1.45] | [0.0, 1.5, 0.0, 1.62] | spec 3 (gain 1.08) |
| bounce out-elevation, row 8 | Settings ShotDef[8] BounceConfig/e96ae850 | [0.0, 1.5, 0.0, 1.45] | [0.0, 1.5, 0.0, 1.62] | spec 3 (gain 1.08) |
| bounce out-elevation, row 12 | Settings ShotDef[12] BounceConfig/e96ae850 | [0.0, 1.5, 0.0, 1.45] | [0.0, 1.5, 0.0, 1.62] | spec 3 (gain 1.08) |
| bounce out-elevation, row 1 | Settings ShotDef[1] BounceConfig/e96ae850 | [0.1, 1.5, 0.125, 1.55] | [0.0, 1.5, 0.0, 1.275] | spec 3 (gain 0.85) |
| bounce out-elevation, row 5 | Settings ShotDef[5] BounceConfig/e96ae850 | [0.1, 1.5, 0.125, 1.55] | [0.0, 1.5, 0.0, 1.275] | spec 3 (gain 0.85) |
| bounce out-elevation, row 9 | Settings ShotDef[9] BounceConfig/e96ae850 | [0.1, 1.5, 0.125, 1.55] | [0.0, 1.5, 0.0, 1.275] | spec 3 (gain 0.85) |
| bounce out-elevation, row 13 | Settings ShotDef[13] BounceConfig/e96ae850 | [0.1, 1.5, 0.125, 1.525] | [0.0, 1.5, 0.0, 1.275] | spec 3 (gain 0.85) |
| spin_a lo, row 10 | Settings ShotDef[10] EffectConfig/3d54f391/Element[0] | 0.0..0.0 | -0.04 (constant) | spec 3 |
| spin_a hi, row 10 | Settings ShotDef[10] EffectConfig/3d54f391/Element[1] | -0.3..-0.2 | -0.3 (constant) | spec 3 |
| drag T, row 8 | Settings ShotDef[8] MiscConfig/e6d14874 | 0.05 | 0.0525 | spec 3 |
| spin_a lo, row 8 | Settings ShotDef[8] EffectConfig/3d54f391/Element[0] | 0.0..0.0 | -0.1 (constant) | spec 3 |
| spin_a hi, row 8 | Settings ShotDef[8] EffectConfig/3d54f391/Element[1] | -0.4..-0.2 | -0.42 (constant) | spec 3 |
| drag T, row 9 | Settings ShotDef[9] MiscConfig/e6d14874 | 0.04 | 0.05 | spec 3 |
| spin_a lo, row 9 | Settings ShotDef[9] EffectConfig/3d54f391/Element[0] | 0.0..0.0 | 0.06 (constant) | spec 3 |
| spin_a hi, row 9 | Settings ShotDef[9] EffectConfig/3d54f391/Element[1] | 0.1..0.3 | 0.18 (constant) | spec 3 |

Notes:

- The spec's higher launch targets for these rows (primary 178-200 / 150-168 / 118-132 km/h) are left out: with the retail power graphs they would speed up every shot (flat median 129 -> 147 km/h), while the spec keeps averages at retail and reaches the ceilings only through the grade (code).
- Bounce and out-elevation curves are applied to the whole spin family (Finesse, Medium, Powerful, Risky rows); drag and spin only to the Powerful rows the spec specifies (8, 9, 10). Returns use rows 8-10, so they change too. Lobs, volleys, serves, smash and drop shots keep their bounce.
- Per-surface bounce needs code (no surface input to the bounce routine).

Generated by `python3 tuning/retune-v0/make_patches.py` from the values in `docs/design/retune-spec.md` at commit 93e3761.
