# Aiming: where the stick sends the ball (agent GE1)

This note closes the "aim tables and aim point" item. It replaces the aim parts of
`input-to-shot.md` s5, `controls-and-shot-selection.md` s8 ("Use") and `shot-to-template.md` s4,
which assumed that the stick angle and magnitude become the landing point. They do not.

Evidence grades: **C** = read from code instruction by instruction (`Swing_DLL.dll`, sha256
`a7f28b29...52ba9`, `tools/fn_asm.py`, full `.text` disassembly by `work/ppcdis`), **D** = read
from data, **I** = inferred. Units: cm, the receiver's half has `x > 0` (net plane `x = 0`),
`z` is lateral; the hitter's local position has `x < 0` on its own half (I, from the
VolleyForward test `S+0x8E0 + 450 < 0` and the receiver-frame targets of gp4b).

## 1. In one paragraph

Every shot has an **aiming config** (one of 25, chosen by the template row). The config holds
four nested target **quads** per court zone: a tiny one around the zone centre, a mid-court one,
one on the **court lines** and one 3 m **outside** them. The shot's **aiming efficiency**
(0..1, from the shot's aiming graph plus a random roll) picks a quad between the tiny one
(efficiency 0) and the lines (efficiency 1). The ball is aimed at the point of that quad's edge
in the **direction** of the left stick. The stick's magnitude is ignored: any push past the
input dead zone (0.4) aims at the edge, and no push aims at the zone centre. So a well-timed,
well-placed shot by a good player goes close to the lines in the stick direction. A poor shot
is pulled toward the middle. Error shots (the Out outcome) use efficiencies 1..2, between the
lines and the out quad. (C for the mechanism, D for the numbers.)

## 2. Code path (C)

```
fn_886B0490 (shot planner, 12 frames before contact)
  fn_886AE528(SC = PC+0x70, C, ..., entry = PC+0xB0, ...)
    +0x444  fn_88695640        pre-shot setup: DeepDeviation S+0xD78 = 0,
                               DeviationSystem.Random S+0xD7C = U[0, 1], #615dc2b6/#ffd438ab = 0
    +0x4A4  fn_88695C48(SC)    aiming graphs (below), QuadEfficiency S+0xD90 = FinalEfficiency
    +0x4A8  debug byte lbl_88D429E0 -> S+0xD90 = 1.0 ("perfect aim")
    +0x4D8  entry->X vtbl slot 4 = fn_886935A0(X, &target, PC)      <- the aim point
            (selector class 0x85B71A2B, vtable 0x880F4808: [2] fn_886707C8 init,
             [4] fn_886935A0 target, [8] fn_88693280 court clip)
    ...     outcome roll fn_886807C0 (In / Out / Net / Let, ball-physics.md s8)
```

**`fn_886935A0`** (0x8C bytes):
1. `DirectionSelected (S+0xDAD) = fn_886706C8(PC, &QuadAimingState S+0xD44)`.
2. `fn_88693040(X, quad, PC, m = QuadEfficiency S+0xD90)` builds the 0x50-byte quad
   (four corners and the centre).
3. No direction: target = the quad centre. Otherwise `fn_8867D150(quad, &AimX, &target)`.

**`fn_886706C8`** (stick to QuadAimingState):
* Source: `InputState.d3ef3bda` (S+0x438, not bound by the shipped InputMapper, so 0) when the
  player is human, `match+0x32A` is set and `ctrl+0x44 -> +0x54 == ctrl+0x4C -> +0x28`
  (meaning U); else `AimingState.StickOverride` (S+0xD70, written for the AI) when
  `AimingState.#389561c8` (S+0xDAE) is set; else **`InputState.Stick_Aiming`** (S+0x430, left stick,
  dead zone 0.4 rescaled to 0..1).
* `DirectionSelected = |x| > FLT_EPSILON || |y| > FLT_EPSILON` (`lbl_880C960C` = 1.19e-7).
* `AimX = x`, `AimY = y`, both negated when the hitter's court tag is `0xA2EDA1E7` (far side).

**`fn_88660F70`** (which config): the selector holds three configs looked up by the row header
keys at init (`fn_886707C8`): `X+0x08` = `name_hash`, `X+0x0C` = `aim_key_group`, `X+0x10` =
`aim_key_base`. It returns `X+0x0C` (for example `FlatReturn`) when `match+0x32A` is set, the two
controller words above differ and `ctrl+0x4C -> +0x24 -> +0xB8 == PC+0x18` (I: this player is
returning a serve); else `X+0x10` in the same case in doubles (`ctrl+0x4C+0x2C == 2`); else `X+0x08`.

**`fn_88693040`** (the quad):
* Hitter position `p = S+0x8E0` (LocalPosition). A debug override replaces it from
  `DebugConfig` when `+0x48` and `+0xF57` are set.
* Lateral weight `lat = clamp((|p.z| - CenterDistance) / (SideDistance - CenterDistance), 0, 1)`.
* Depth weight `dep = clamp((p.x + BaselineDistance) / (BaselineDistance - VolleyDistance), 0, 1)`:
  0 at 13 m behind the net, 1 at 3 m.
* Each of the four zones gives a quad at efficiency `m` (`fn_8867D350`, below). Then
  `quad = lerp(lerp(BaselineCenter, BaselineSide, lat), lerp(VolleyCenter, VolleySide, lat), dep)`,
  and the same for the centres.
* **Mirror** (`fn_88661188` plus the centre): when serving, if `match+0xAC == 0xD826E563`
  (the second service court); otherwise when the hitter stands at `z >= 0`. It negates every z
  and swaps corners 0/1 and 2/3, so corners 1 and 3 stay on `z+` and the stick keeps its sense.
  The tables are written for a hitter at `z < 0` (and for the first service court).
* **Doubles**: when `ctrl+0x4C+0x2C == 2` and `ctrl+0x44 -> +0x95 == 0` (U: probably "not a
  serve"), the widening `w = 137 cm` (`g_ts4_script_constants+0x644`, the alley) is passed on.

**`fn_8867D350`** (one zone at efficiency `m`; the zone's `AimingQuad` list has four quads q0..q3):

| m | quad |
|---|---|
| m < 0.5 | `lerp(q0, q1, 2m)` |
| 0.5 <= m <= 1 | `lerp(q1, q2, 2(m - 0.5))` |
| m > 1 | `lerp(q2, q3, min(m - 1, 1))` |

With doubles widening, q1's z values are scaled by 1.4 (`+0x51C`) and q2's corners move out by
`w` (corners 0 and 2 to `z - w`, 1 and 3 to `z + w`). q3 is not widened. The centre is the zone's
`546a639e` vector, independent of `m`.

**`fn_8867D150`** (stick direction to the quad edge). Corners: c0 short/z-, c1 short/z+,
c2 deep/z-, c3 deep/z+. With `n = 1/|aim|`:
```
if AimX^2 > AimY^2:   s = (AimY n sqrt2 + 1)/2;  target = AimX >= 0 ? lerp(c1, c3, s) : lerp(c0, c2, s)
else:                 s = (AimX n sqrt2 + 1)/2;  target = AimY >= 0 ? lerp(c2, c3, s) : lerp(c0, c1, s)
```
Straight up aims at the middle of the deep edge, straight right at the middle of the right edge,
a diagonal at a corner. Only the direction matters.

## 3. What happens to the target afterwards (C, from ball-physics.md s7, now with the numbers)

* **In.** `fn_886805E0` pulls the target back toward the hitter by **DeepDeviation `S+0xD78`**
  along the hitter-to-target line. Then `fn_88693280` clips the hitter-to-target segment to the
  config quad **at efficiency 1** (the lines quad, corner order 0, 1, 3, 2). Then
  `x = max(x, 50)`.
* **Out** (error roll). `QuadEfficiency = OutEfficiency (S+0xD8C) + 1`, so the target moves
  between the lines quad and the out quad. `fn_886935A0` runs again, then the push-out of
  `fn_88672130` (3 cm past the nearest line).
* **Net / Let.** The aim solver moves the target so the ball crosses the net at 80 / 90 cm.

## 4. Where the efficiency comes from (C for the wiring, D for the values)

`fn_88695C48`, when the shot-class entry `SC+0x100` exists (set by `fn_886629C8` to the
EvaluateList entry keyed by the row's `ResolutionConfig`, or its Return config on a return of
serve; OPEN 1.5):
1. If the player is human, or not serving: run the class's **aiming graph** (entry `+0x18`,
   `ShotResolutionSettings.00236a48.EvaluateList[].#3f9c096b`; graphs 188-237, list in
   `graphs-decoded.md` s5). It writes **`AimingState.Efficiency` (S+0xD88)** and
   **`DeviationSystem.DeepDeviation` (S+0xD78)**.
2. If not serving: `AimingState.Random (S+0xDA4) = U[0, 1]` and the **FinalEfficiency graph**:
   human `PC+0x1DC` = graph 196 `5c66a7c5` (`fn_886BE1C8 +0x5A0`), AI the difficulty's
   `7bcf55ee` graph (brain `+0x1E0`). Output `FinalEfficiency (S+0xDA8)`.
3. Serving: `FinalEfficiency = Efficiency`.
4. `QuadEfficiency (S+0xD90) = FinalEfficiency`.

Evaluated with `tools/ts4_analyser.py` on the retail `Expressions.bin` (other inputs 0, hand
stat 0.8, vigor 1, power 0.5, DeviationSystem.Random 0.5):

| aiming graph | t = 0 | t = +-0.3 | t = 0.6 |
|---|---|---|---|
| FlatFinesse 188: Efficiency / DeepDeviation | 0.80 / 125 cm | 0.40 / 300 | 0.20 / 300 |
| FlatMedium 202 | 0.76 / 129 | 0.40 (early 0.36 at -0.6) / 200 | 0.20 / 200 |
| FlatPower 205 | 0.60 / 108 | 0.36 / 200 | 0.20 / 200 |
| TopSpinMedium 203 | 0.80 / 118 | 0.40 / 200 | 0.20 / 200 |
| SliceMedium 204 | 0.76 / 140 | 0.20 / 200 | 0.20 / 200 |
| DropShot 236 | 0.40 / 0 | 0.20 / 0 | 0.20 / 0 |

DeepDeviation falls linearly with its random input: FlatMedium at t = 0 gives 310, 219, 129, 64
and 0 cm for Random = 0, 0.25, 0.5, 0.75, 1. So an "In" groundstroke lands between 0 and about
3 m shorter than aimed, uniformly. Timing errors raise it to 2-3 m fixed (the timing branch
overrides the random term).

Graph 196 (human FinalEfficiency), hand 0.8, timing 0:

| Efficiency | Random 0 | 0.5 | 1 |
|---|---|---|---|
| 0 | 0.00 | 0.17 | 0.68 |
| 0.5 | 0.49 | 0.63 | 0.84 |
| 1 | 0.79 | 0.90 | 1.00 |

With |t| >= 0.3 the Efficiency-1 row drops to 0.65 / 0.76 / 1.0. A hand stat of 0.3 costs
about 0.03-0.05.

Worked example (`tools/ts4data/aim_tables.py`, FlatNormal config, hitter at (-1188, -50)):

| efficiency | stick up | stick right | stick up-right |
|---|---|---|---|
| 0 | (737, -12) | (718, 23) | (739, 31) |
| 0.5 | (903, -8) | (794, 210) | (903, 230) |
| 0.8 | (1074, -3) | (859, 331) | (1074, 339) |
| 1.0 | (1188, 0): the baseline | (902, 413): the sideline | (1188, 411): the corner |

The zone centre (no stick) is (720, -12): 7.2 m past the net, in the middle.

## 5. The tables (D)

`Settings.bin` cfg+0x108 = `b50def25` list of 25 `AimingConfig` (0xA0 bytes each, file
0x204E4). Layout in `tools/ts4data/aim_tables.py`; every value in `data/gameplay/aim_tables.yaml`.

| idx | Id | side dist | used by (template family / key) |
|---|---|---|---|
| 0 | ServeNormal | 350 | flat/kick serves; flag `5ed23100` = true |
| 1 | ServeSlice | 350 | slice serves (true) |
| 2 | ServeAdvanced | 350 | advanced serves (true) |
| 3 | ServeRisky | 350 | (true) no reachable row |
| 4 | FlatNormal | 550 | Flat Medium/Powerful rows |
| 5 | FlatReturn | 350 | the `aim_key_group` of the Flat rows: returns of serve |
| 6 | FlatVolley | 350 | |
| 7 | FlatFinesse | 550 | |
| 8 | FlatRiskyFinesse | 350 | no row |
| 9 | FlatRisky | 350 (BaselineDistance 1200) | debug-only row |
| 10 | TopSpinNormal | 550 | |
| 11 | PowerVolley | 350 | |
| 12 | TopSpinFinesse | 550 | |
| 13, 14 | TopSpinRiskyFinesse, TopSpinRisky | 350 | no / debug row |
| 15 | SliceNormal | 550 | |
| 16 | SliceVolley | 500 | |
| 17 | DropVolley | 350 | |
| 18 | SliceFinesse | 550 | |
| 19 | SliceRisky | 350 | debug row |
| 20 | DropShotNormal | 550 | |
| 21 | LobNormal | 550 | |
| 22 | DefensiveShot | 350 | no reachable row |
| 23 | SmashNormal | 350 | |
| 24 | `0dd41adf` (unnamed) | 350 | same data as SmashNormal |

All configs: VolleyDistance 300, BaselineDistance 1300 (1200 for FlatRisky), CenterDistance 0.
Quad 2 of every groundstroke zone is the singles court (x 616..1188, z -411..414). Quad 3 is
about 3 m outside (x 549..1488, z +-710). The serve quad 2 is the service box (x 384..646,
z 0..414). The flag `5ed23100` (+0x94) is read by none of the functions above, nor by the selector
init or the debug quad drawer (GE1 scan, OPEN 1.16; I: unused in retail).

## 6. Tuning

* **How close good shots go to the lines**: move quad 2 (and quad 1) corners inward in
  `aim_tables.yaml` terms, by editing `Settings/14_b50def25.yaml` rows
  `AimingConfig[i]/<zone>/ZoneInput/QuadList/AimingQuad[2]/Coord[k][0|2]` and patching with
  `tools/ts4data/patch_tunables.py`.
* **How much skill and timing matter for placement**: the aiming graphs (Efficiency curves vs
  timing, hand stat) and graph 196 (`ts4_analyser_patch.py`).
* **Depth scatter of In shots**: the DeepDeviation branch of each aiming graph (0..310 cm).
* **Where a neutral stick goes**: the zone centres (`546a639e`).

## 7. Reproduction

```sh
python3 tools/fn_asm.py fn_886935A0 fn_886706C8 fn_88693040 fn_8867D350 fn_8867D2B0 fn_88661188 \
    fn_8867D150 fn_88660F70 fn_88695C48 fn_88695640 fn_88693280
python3 work/disc/ppcd.py 880F4808 0x28          # (data) selector vtable; or read the words with struct
python3 tools/ts4data/ps_layout.py --range 0xD20 0xDB0        # AimingState field names
python3 tools/ts4data/aim_tables.py --selftest
python3 tools/ts4data/aim_tables.py --settings work/disc/core/334e7e0d.bin \
    --out data/gameplay/aim_tables.yaml --tables data/gameplay/aim_tables.txt
cc -std=c11 -Wall -Wextra -Werror ref/gameplay/test_aim.c ref/gameplay/aim.c -lm -o /tmp/ta && /tmp/ta data/gameplay/aim_tables.txt
```

## 8. Corrections

| earlier statement | correct (C) |
|---|---|
| input-to-shot s5 / controls s8: `fn_8869C010` aim (`aim+0x30/+0x34`) feeds `ball+0x430` / `ball+0x364` and the landing point | `fn_8869C010` is called only by movement-planner states (`fn_886A3C98`, `fn_886A3DF0`, `fn_886A4260`, `fn_886AA280`, `fn_886BADA0`, `fn_886C0568`, `fn_886C15A0`) on the object `ctrl+0x5C`: it is the movement intent. The shot target is `fn_886935A0`. `C+0x30/+0x34` of the command get `S+0x778` / `S+0x774` (`fn_886AE528 +0x594/+0x5A4`) |
| aim depth = stick magnitude | the stick magnitude is not used for the shot: only the direction (plus a 0.4 dead zone) |
| shot-to-template s4: the 0x120 / 0x12C vectors are "aim tables keyed by template name" | the aiming tables are cfg+0x108 (`AimingConfig[25]`); cfg+0x120 is `ShotResolutionSettings` |
| ball-physics s16: `S+0xD78` is "0 by default" | it is the aiming graph output DeepDeviation, 0..310 cm |
| `S+0xD90` = Out margin | `AimingState.QuadEfficiency`, the quad selector, = FinalEfficiency for every shot; the Out path sets it to OutEfficiency + 1 |
