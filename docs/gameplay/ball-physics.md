# Ball physics: complete specification (family G3)

This note covers every ball mechanic of Top Spin 4 (Xbox 360): the launch solve, the flight model, all solver kinds, the
bounce, the net and let cord, the court and in/out geometry, shot error, the prediction stepper, the ball defaults,
the template rows, and event timing. It consolidates [gp4.md](gp4.md) and [gp4b.md](gp4b.md) and corrects them where
the machine code says otherwise (section 13), and it adds the routines those notes left as "described, not
re-derived".

**Curves are ramps (settled 2026-11-14, G1):** template curve20 keys get `slope = (y1 - y0) / (x1 - x0)` at load
(`fn_8867BB78`), so the "ramp" reading in this note is the game's behaviour; `tools/ts4data/templates.py` now defaults
to it. See [graphs-decoded.md](graphs-decoded.md).

* **Module.** `Swing_DLL.xex`, sha256 `dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44`. The PE image
  `orig/54540859/Swing_DLL.dll` has sha256 `a7f28b29…2ba9`. All addresses are xex VAs.
* **Disassembly.** `TS4_MATCHING_DIR=work/matching-b9 python3 tools/fn_asm.py <fn>` decodes VMX128.
  `work/disc/ppcd.py` (capstone 5.0.7) is used for raw ranges, and `tools/sym_info.py data <addr>` for constants.
* **Data.** `Core.arc` sha256 `7df7bfd5…bf50`. It contains `Settings.bin` (`334e7e0d`, 286,492 B, sha256 `55cb175d…0167`) and
  `State.bin` (`623d0979`, 273,746 B, sha256 `ff871577…4aeb`).
* **Readable code.** [ref/gameplay/ball.h](../../ref/gameplay/ball.h) and [ball.c](../../ref/gameplay/ball.c) hold the
  portable model. The test [test_ball.c](../../ref/gameplay/test_ball.c) uses synthetic templates and is cross-checked
  against the bit-exact draft `src/xbox360/drafts/gp4b_ball_model.c`. `tools/ts4data/ball_model.py` is a Python port
  that produces the tables.
* **Values.** [data/gameplay/ball_templates.yaml](../../data/gameplay/ball_templates.yaml) has every row with named
  fields and evaluated tables. [data/gameplay/ball_trajectories.csv](../../data/gameplay/ball_trajectories.csv) has one
  simulated shot per row, scenario, secondary weight and curve reading.

Confidence tags:

* **H**: read from the machine code. Where noted, it is also validated by emulation or by the cross-check.
* **M**: read, but the intent or a detail is inferred.
* **L**: a guess.
* **U**: unknown.

## 0. The model in one page

```
units   world cm (x along the court, net plane x = 0, y up, z across); stepper: local metres, origin (0, radius, 0) cm
clock   60 ticks/s; caller does tick++ before each step (fn_886AD1F0); arc clock t = (tick - tick_prev) / 60
drag    k = T / a4            (T: template tpl+0x3C, 0.04..0.0525; a4: ball+0x4D4 = 0.06)  -> k = 0.67..0.875 /s
spin    A = u*spin_c + (u x up)*spin_b*sgn + ((u x up) x u)*spin_a   (a constant drift acceleration, not Magnus from omega)
motion  v' = -k (v - A/T) - g y^      solved in closed form, never integrated
arc 1   p(t) = P0 + C (1 - e^-kt) + Weff t,  C = (P1 - P0 - Weff tau)/(1 - e^-k tau),  P1.y = 0, Weff = A/T - (0, g/k, 0)
arc 2   p(t) = p0 + (v0 - Weff)(1 - e^-kt)/k + Weff t            (after a bounce / net touch)
plan    the planner solves tau (flight time to the first bounce) from the template kind, quantised to n/60 s
bounce  first bounce: exactly at tick n, position snapped to the target P1; later: falling and y < 0, y snapped to 0
        v_out = yaw(c64(spin_b)) * tilt(|5 spin_a| * wrap(c58(theta) - theta)) * (1 - c40(spin_a)) * reflect_y(v_in)
        spin *= 1 - c4C(spin_a)
outcome In/Out/Net/Let rolled BEFORE launch (fn_886807C0); the target is moved accordingly; physics never decides in/out
```

## 1. Shot template rows (H for the layout, M where marked)

There are 37 rows of `0x8C` bytes, contiguous from `Settings.bin` file offset `0x137C`, plus one row inside a larger
record in `State.bin`. The table base is the root typed struct `cfg` at file `0x24`; the planner stores
`ball+0x360 = row - cfg`. The YAML lists that value as `ball_0x360`.

| offset | name | meaning | evidence |
|---|---|---|---|
| row+0x00 | `row_type` | `0x85B71A2B`: the class hash of the selector object `X` that `fn_88662390` creates from the row. The `State.bin` row has no type word. | H, `fn_88662390` |
| row+0x04 | `name_hash` | Template family name (crc32: `FlatNormal`, `ServeSlice`, ...). `X.init` (`fn_886707C8`, vtable `0x880F4808` slot 2) looks it up in the controller map `ctrl+0x108` (`fn_8826CC60`) and stores the result in `X+0x08`. This is the aim-table entry. | H lookup, M "aim table" ([shot-to-template.md](shot-to-template.md) section 4) |
| row+0x08 | `aim_key_group` | Second key, for example `FlatReturn` (0 = none), stored in `X+0x0C`. | H |
| row+0x0C | `aim_key_base` | Third key (a related row name, or 0), stored in `X+0x10`. | H |
| row+0x10 | `serve_params_rel` | Serve rows only: a self-relative pointer to a sub-record. It holds 8 floats (`+0x00 = 0.1`, `+0x18` = the serve speed 150/140/190 km/h, `+0x1C` = 0.3..0.5, `+0x14` differs per row and looks like garbage) followed by two `{rel, type}` curve20 elements at `+0x20/+0x28`. These are equal to the row's own `spin_a` lo/hi. No reader found (section 1.1). | H layout, U use (likely unused) |
| row+0x14 | `stroke_ranges_rel` | Stroke rows only: a pointer to 20 `(lo, hi)` float pairs, for example `(0.2,1)(0.2,1)(0,0.9)(0,0.5)(0,0.3)(0,1)...`. `fn_88662390` stores it as selector `entry+0x10`. No reader found (section 1.1). | H layout, U use (likely unused) |
| tpl+0x00 | `primary` | Value `{rel, type, kind}`. The kind hash at tpl+0x08 selects the solver (section 3). | H |
| tpl+0x0C | `secondary` | Value with the secondary kind hash at tpl+0x14. | H |
| tpl+0x18 / +0x24 / +0x30 | `spin.vertical_a` / `along_c` / `lateral_b` | Each slot is a standard XData array header `{rel, count = 2, capacity = 2}` pointing at two elements `{rel, type}` = (lo, hi). So the "12-byte pointer entries" are array headers. | H |
| tpl+0x3C | `T` | Drag scale. | H |
| tpl+0x40 / +0x4C / +0x58 / +0x64 | `bounce.*` | Array headers `{rel, count, capacity}` of curve16 keys: speed loss vs `spin_a`, spin decay vs `spin_a`, outgoing elevation vs incoming elevation (rad), and yaw kick vs `spin_b` (rad). | H |
| row+0x88 | `id` | Unique row id, the key of the decision-tree leaf ([shot-to-template.md](shot-to-template.md)). | H |

### 1.1 Searches for readers of the row header blocks (G3b; all negative)

* Register taint over the whole `.text` (ppcdis dump, 2,540,014 instructions): seed `lwz rX, 0xB0(..)` (selected
  entry B), propagate `B+4` (row) and `B+0xC` (selector X); report `row+0x10`, `row+0x14`, `B+0x10`, `X+4`. Zero hits.
  The same scanner does find the known readers `row+0x88` (`0x8868F2D8`, `0x886A1FC0`, `0x886B0970`) and the X vcalls
  (`0x88661308`, `0x88680784`, `0x88680CE4`, `0x886AE9F4`), so it works.
* The row offset `ball+0x360` is read back only at `0x886B08B0` (copied into the command); no code rebuilds
  `cfg + ball+0x360`.
* Loops stepping an entry pointer by `0x14` with a `+0x10` load, in `0x88650000..0x886D0000`: none.
* All methods of the selector X (vtable `0x880F4808`: `fn_886707C8` init, `fn_886935A0`, `fn_88670CC8`,
  `fn_88693280` court clamp, ...) and of the entry vector owner (vtable `0x880F4420`, `controller+0x88`, built by
  `fn_886715A0`): none touches the blocks.
* So the serve sub-record and the 20 stroke ranges are loaded but have no reader in `Swing_DLL.xex` (M: an
  authoring leftover). `Loader_DLL.xex` does not hold the template table (Settings.bin is loaded by Swing), so it was
  not searched.

**Value types.** `0x33799CCE` is a float. `0xF9F12A60` is a curve20 with 20-byte keys `{x0, x1, y0, slope, y1}`.
`0x7A330099` is a 2-D table: 16-byte rows `{curve16 header relative to the row, ?, a_key}`, interpolated in `a` (distance,
cm) between the curve16 values at `b` (hit height, cm).

**Curve reading (open, owned by G1).** Every retail curve20 key has `slope = 0` and stores the end value `y1` at +0x10.
The evaluator `fn_8817A688` reads only `slope`.

* `STEP`: the shipped code with the shipped data. The curve holds `y0`.
* `RAMP`: a load-time fixup sets `slope = (y1-y0)/(x1-x0)`.

Evidence on a fixup, from this package (G3b, for G1; not a proof): the curve type hash `0xF9F12A60` appears in
`Swing_DLL.xex` only as an immediate compared in the three evaluators (`0x8867BBCC`, `0x888AB750`, `0x889C1894`); it is
not in any data table of the module, so no type-keyed load handler exists in Swing. A scan for `stfs fX, 0xC(rY)` fed
by an `fdivs` with loads of `+0x08` and `+0x10` from the same base within 16 instructions found nothing. Every row
access resolves the self-relative offsets at use time (`lwz; add`), which shows the buffer is read in place, not
relocated. A generic slope fixup in a shared loader is therefore not excluded, but no code for one was found.

All tools support both readings: `ball_template.curve_mode` in C, and `--curve-mode step|ramp|both` in
`templates.py`. Evidence from this package, offered for G1: under STEP, 7 of the 8 TopSpin/Slice groundstroke rows have
a launch speed below the slowest possible arc over a baseline-to-baseline distance. The solver then falls back to the
minimum-speed lob: 88–110 km/h with a 5.7–6.0 m apex. Under RAMP, the same rows give 108–128 km/h with a 1.5–2.4 m apex
and 0.6–1.4 m net clearance, which is tennis-like. Serve and volley rows are the same under both readings: their curves
are flat, or their spin keys sit outside the evaluated range.

**Spin curve argument.** The argument is the launch height in metres (`cmd_from.y * 0.01`). Groundstroke spin keys span
0.5–1.4 m. Serve keys span 50–120, so a 2.7 m serve always evaluates at `x < x0`, which gives `y0`. Under either
reading, serve spin therefore does not vary with height (H for the code, M that the cm-style keys are an authoring
slip).

## 2. Ball block: defaults and who writes them

* **The 0x540-byte ball image.** It is serialised in `State.bin` at file `0x964..0xEA4`, in the same layout as the live
  ball, `Gp4bBall` in `src/xbox360/gp4b_types.h`. The values are:
  * `+0x00` tau = 2.0, `+0x04` tick = 1, `+0x08` T = 0.045;
  * `+0x364` blend = 1, `+0x370` = 100 km/h, `+0x430` = 1;
  * `+0x4C0..0x4CC` Wood (frame-shot) box = `(-800, -400, -400, 400)` cm (see below);
  * `+0x4D0` radius = **4.0 cm**, `+0x4D4` a4 = **0.06**, `+0x4D8` g = **9.81**, `+0x4DC` max_bounces = **5**;
  * `+0x494..0x4A0` cord parameters = 0, default P0/P1 = (-1300, -170, 100) / (1300, 0, -100);
  * `+0x28` hold = 0, `+0xA0` hold delta = 0;
  * `+0x4E0` = **1** (skip the step on the launch frame) and `+0x4E1` no_sidespin = **1** (G3b).
* **The writer** of `ball+0x4D0..0x4DC` is therefore the generic XData load of the serialised engine state (`State.bin`
  is a snapshot of the gameplay objects). No instruction stores these fields with a literal offset. The only exceptions
  are the zeroing constructors `fn_882734C8` and `fn_886A9050`, the copy `fn_88272BC0`, and `fn_886B1BA0 +0x2178`, which
  writes `max_bounces = 10` for the practice/serve ball. (H for the image, M that the live ball is loaded from it
  unchanged.)
* **The "dispersion box" is the Wood (frame-shot) target, not an In-shot error (H, G3b).** The only reads of
  `ball+0x4C0..0x4CC` in the module are `fn_886AE528 +0xA7C..+0xAA0` (`0x886AEFA4..0x886AEFC8`; a whole-module grep
  of `0x4C0..0x4CC` displacements plus a taint from `engine+0x5C -> +0x20` (the ball) finds no other ball reader;
  the other hits are PlayerState fields). That block runs in the planner's outcome switch at `+0xA40..+0xA64`
  only when the outcome mode is **Wood `0x9CAFB633`** (`r28`, set at `+0x850`) **and** the request flag
  **IsWood `S+0x40A`** is set (`r20`, `+0x700`). It draws `dx = U[+0x4C0, +0x4C4]`, `dz = U[+0x4C8, +0x4CC]` and sets
  the target to the **hitter position** `ball+0x340` plus `(dx, 0, dz)` when `from.x < 0`, minus it otherwise
  (`+0xAB8..+0xB04`). So a frame shot lands 4–8 m **behind the hitter**, up to 4 m to either side, and is then
  probed as a planned shot (`ball+0x369 = 1`, `fn_889C2678(ball, +0x3D8)` at `+0xF48`). The In outcome
  (`0xCA68AAEC`, `+0xEC8`) has no random term at all (section 7). The image values are therefore plausible as shipped.
  When Wood comes from the IsWoodDown test instead (aim on the hitter's side within `sqrt(pool+0x7EC)` = 8 m of a
  reference point; `r22`, `+0x6BC..+0x760`), the target is left as aimed. `ref/gameplay/ball.c`:
  `ball_wood_target`.
* **Other overrides.** No literal store reaches `ball+0x4C0..0x4DC` outside the constructors and copies listed
  above. `+0x4E0` and `+0x4E1` have byte stores only in non-ball objects (`0x88682794`, `0x8890BA4C`, the
  bit-stream reader `0x8891C9C0`). `+0x4E0` is not "frozen": `fn_889C2818` (`0x889C2844..0x889C2884`) launches the
  ball when `+0x43C` is set and then skips `fn_889C1F70` for that one frame when `+0x4E0 != 0`; on later frames it
  always steps. With the image value 1 the ball is shown at P0 on the launch frame (H for the branch, M that the
  live ball keeps the image value). **With `no_sidespin = 1` every bounce and every let-cord touch zeroes `spin_b`
  and `spin_c`**: after the first bounce there is no lateral or along-track drift, only the explicit yaw kick
  (section 6). This also makes the post-bounce sign flip of section 4 invisible in play (M, same caveat).
* **Net height.** It is `ball+0x124 = C+0x24`, taken from the command; it is not in the ball image. 91.4 cm is the
  assumption used in the tables.

## 3. Launch solve (H, validated bit for bit in gp4b section 9; readable port `ball_solve_tau`)

The probe `fn_889C2678` sets up the shot:

* `P0 = from*0.01`, with `P0.y -= radius*0.01`;
* `P1 = to*0.01`;
* `T` from the row and `k = T/a4`;
* spin (section 4) from the launch height and the spin blend `C+0x50`.

Then `fn_888AD0E8` dispatches on `tpl+0x08`. All bisections use `mid = (lo+hi)/2`; the tau bracket is
`[0.1, 5.1]` s. `metric_kmh^2/12.96` converts km/h to (m/s)^2.

* **`tau_min`.** 20 bisections on the sign of `d|v0|^2/dtau` (`fn_888AACB8`) give the flight time of the slowest
  possible launch toward the target.
* **InitialSpeed `fn_888ACA68`**: metric `|v(0)|^2` (`fn_888AAB98`). **BounceSpeed `fn_888ACDA8`**: metric `|v(tau)|^2`
  (`fn_888AAA70`). **AverageSpeed `fn_888AC748`**: no metric. It compares a constant 0, so it converges to tau ≈ 0.1 s;
  this is a stub that no row uses. The common body (`solve_speed`):
  1. If `d|v0|^2/dtau(0.1) >= 0`, set `has_min = 0`, `tau = 0.1` and stop.
  2. The target speed is the row curve when `planned`, else the commanded `C+0x54`.
  3. If the speed at `tau_min` already exceeds the target, then `tau = tau_min` (speed-limited: the ball is launched
     faster than asked). Otherwise run 20 bisections on `[0.1, tau_min]` for `metric = target`.
  4. **Net clearance.** The threshold is `(radius + net_height)*0.01 + 0.01` m when planned, else `aim_height + 0.01`.
     If the net-plane height (`fn_888AB308`) is below it and the shot is planned, bisect tau upward toward `tau_min`.
     If even `tau_min` fails, set `net_unreachable` and allow up to `tau_min + 5` s. The bisection runs in 4-step rounds
     until `|h - thr| <= 1e-3`, the bracket is below 1e-4, or 200 rounds have run.
  5. If planned, run the secondary stage `fn_888AC688`.
* **DropTime `fn_888AB8D0`**:
  1. `tau = curve(distance)`, or the 2-D table of distance and height.
  2. If unplanned, use the min-speed / commanded-speed solve as above.
  3. Unless the mode is Wood (`0x9CAFB633`), raise tau for net clearance, up to +2 s.
  4. The secondary stage is inlined, for DropTime and Apogee only. A row with any other secondary kind blends with
     uninitialised stack in the original (no retail row does this).
* **Secondary stage.** `tauA` is the primary result, `tauB` the secondary target, `w = clamp01(1 - f4C)`,
  `tau = tauA + w (tauB - tauA)`:

  | secondary kind (tpl+0x14) | routine | tauB |
  |---|---|---|
  | DropTime | `fn_888AB7B0` | `tauA + curve` (s). No `has_min` gate. |
  | InitialSpeed | `fn_888AC2B8` | the tau at which the launch speed is `speed(tauA) - curve` (km/h delta, slower). Clamped at `tau_min`. |
  | BounceSpeed | `fn_888AC4A0` | the same, on the bounce speed. |
  | AverageSpeed | `fn_888AC100` | bisects toward `tauA` (stub). |
  | Apogee | `fn_888ABF10` | the tau at which `apex = apex(tauA) + curve` (m). Clamped at `tau_min`. |

  If `!has_min`, then `tau = 1.0`, not quantised. If `net_unreachable`, then `tau = tau_raised`.
* **Quantisation.** `n = floor(tau*60)` by repeated float subtraction, and `tau = n * (1/60)` by repeated float
  addition. `ball+0x04 = n` is the first-bounce tick.
* **Unplanned speed probes do not quantise.** This covers Net/Let, where `planned = 0` and kind ≠ DropTime: they leave
  `ball+0x04` from the previous probe. The planner always runs the planned In probe first, so that value is that shot's
  tick (H code, M consequence).
* **Aim solver `fn_889C29E8`** (Net/Let targets).
  1. `lo = fn_888ABCC0(ball, f1 = cfg+0x130 = 100 cm)` (H, G3b): take the horizontal hitter `ball+0x340` and target
     `ball+0x350` (y = 0), intersect the line through them with the net line (point `lbl_880FC650` = 0, direction
     `lbl_880FC6B0` = +z) using `fn_881896F8`, then add `d * normalize(to - from)` (horizontal). So `lo` is the point
     1 m past the net on the shot line. `ball_aim_bracket_lo`.
  2. `hi = cmd_to`.
  3. Repeat up to 10 times: `cmd_to = (lo+hi)/2`, probe, stop when `|net_height - aim_height| < 0.01` m; else
     `h < aim → lo = mid`, otherwise `hi = mid`.
  4. The aim heights are `S+0x750/0x754` = `cfg+0x134/0x138` = **80 / 90 cm**.
* **`fn_889C2940`.** This is a feasibility probe: commanded speed `ball+0x3CC` with `aim_height = 0`. It stores
  `net_height*100 < ball+0x124` (the ball would hit the net) at `+0x384`.

## 4. Spin and drift (H; `ball_spin_set`, `ball_drift_update`)

`fn_889C1868` computes each spin as `lerp(lo(h), hi(h), blend)`, with `h = cmd_from.y*0.01` and `blend = C+0x50`
(`ball+0x364`). It then calls `fn_889C0DC0(ball, 1)`:

* Direction: `d = P0 - P1` at launch (from_endpoints), or `(arc2_vel.x, 0, arc2_vel.z)` after a bounce or the cord.
* `u = d/|d|` (`vrsqrtefp128` + one Newton step). If `|d| = 0`, `A` keeps its old value.
* `c1 = u × up = (-u.z, 0, u.x)`, `c2 = c1 × u`.
* `A = u spin_c + c1 spin_b sgn + c2 spin_a`, with `sgn = ball+0x368 ? -1 : 1` (left-hander flag, [shot-to-template.md](shot-to-template.md) section 6).

Consequences, read from the code (H) but physically odd (M):

* `c2 = +y` for any horizontal `u`, so **`spin_a` is a vertical acceleration**: negative = dips (topspin), positive =
  floats (slice).
* The launch direction `u` points **back** toward the hitter, while the post-bounce `u` points forward. So **`spin_b`
  (lateral) and `spin_c` (along track) change sign at the first bounce**. A sidespin serve curves one way in the air
  and kicks the other way after the bounce (on top of the explicit yaw kick, section 6).
* The drift velocity is `W = A/T`, and gravity enters as `-g/k`. The steady fall rate under topspin is
  `(g + |spin_a|/a4)`: `spin_a/a4` acts as extra g. For example, `-0.15/0.06 = 2.5 m/s²` = 0.25 g.

## 5. Flight (H; `ball_arc1_position`, `ball_arc2_position`, `ball_step`)

These are the closed forms of section 0. The original expression order, with `fmaf`, is in
`src/xbox360/drafts/gp4b_ball_model.c` (`fn_888AB558` arc 1, `fn_888AD1C8` arc 2, `fn_888AB220` launch velocity,
`fn_888AB0E0` arrival velocity, `fn_888AA968` apex, `fn_888AB308` net-plane height). The readable versions are in
`ball.c`; the cross-check holds every tick to within 2 mm. The apex is computed at the stationary point
`e^{k t*} = C.y k / -Weff.y`. It is not clamped to `t* > 0`, and the Apogee secondary uses it as is.

### Per tick: `fn_889C1F70` (0x704 bytes), called by `fn_889C2818` (H, read instruction by instruction)

1. Convert to local (`fn_889C1160`) and set `prev = pos`. `is_let` = mode LetIn `0x8F903DFB` or LetOut `0x02315629`.
2. **Hold.** While `hold (+0x28) > 0`: decrement it, add `hold_delta (+0xA0)` to `pos`, and skip all physics. When it
   reaches 0 with `bounce_count > 0`, set `tick_prev = tick`. **No writer sets a non-zero hold** (G3b): the only
   stores are the zeroing in the net branches (`0x889C23C4`, `0x889C25D4`, `stw r21` at `0x889C23D0/0x889C25CC`),
   the constructors, and the planner's 0x1A0-byte probe swap (`memcpy`, which only moves the block). A taint scan from
   the ball pointer (`engine+0x5C -> +0x20`) and a scan of `stvx128` with an index register of `0xA0` in
   `0x88600000..0x88A00000` find no other ball store; the image has 0. The hold path is dead in retail (M-high).
3. **Choose the arc.**
   * Not let: arc 1 while `bounce_count == 0`, else arc 2.
   * Let: arc 1 while the ball is on the launch side (`P0.x >= 0 ? pos.x > 0 : pos.x < 0`, using `pos` before the
     update), else arc 2.
   * `t = (tick - tick_prev)/60`.
4. **Bounce test.**
   * First bounce of a non-let shot: `tick >= bounce_tick` (signed).
   * Otherwise: `pos.y - prev.y <= 0 && pos.y < -1.1920929e-7`.
5. **On a bounce.**
   * Incoming `v` = the analytic arrival velocity for the first planned bounce, else `(pos - prev)*60`.
   * `bounce_count++`, `tick_prev = tick`.
   * Snap the position: **first planned bounce → `pos = P1`** (the target; this is why the outcome is decided before
     launch), **later bounces → `pos.y = 0`** (new, see section 13).
   * Run the bounce response (section 6) unless `v == 0`.
6. **Net plane**, only when `prev.x * pos.x < 0` and `check_net (+0x31)`:
   * `hit = (P0.x*P1.x <= 0) || !(pos.y*100 > net_height_cm)`. A shot whose endpoints straddle the net always "hits"
     when the flag is set; that happens only for Net/Let/Wood modes. A ball whose endpoints are on the same side
     (Out-to-own-side, or after a bounce) hits only when its **end-of-tick** height `pos.y` is at or below the net top.
     The interpolated crossing height is not used (H).
   * Crossing point `c = prev + (pos - prev) * |prev.x| / (|prev.x| + |pos.x|)`. Set `arc2_pos = pos = c`,
     `arc2_vel = (pos - prev)*60` and `touched_net (+0x34) = 1`.
   * **Solid net** (`+0x32`, and not `stepper+0x42`):
     * `spin = 0`, `A` recomputed;
     * `arc2_vel *= 0.2` (pool+0x10C), then `arc2_vel.x = -arc2_vel.x`;
     * `bounce_count++`, `hold = 0`, `hold_delta = 0`, `tick_prev = tick`, `pos.x = 0`.
   * **Let cord** (`+0x33`):
     * `pos.x = 0`, `n = arc2_vel/|arc2_vel|`, `speed = |arc2_vel|`;
     * rotate `n` about `n × up` by `acos(n · ĥ) + cord_elev_deg·π/180`, where `ĥ` is the horizontal direction. For a
       descending ball this sets the outgoing elevation to `+cord_elev`; a rising ball gets `2·elev + cord_elev` (M on
       intent);
     * rotate about `up` by `cord_yaw_deg`;
     * `arc2_vel = n · speed · (1 - cord_speed_loss)`;
     * `spin_a, spin_b, spin_c *= 1 - cord_spin_loss`, then **`spin_c` is multiplied a second time** unless
       `no_sidespin (+0x4E1)`, which zeroes `spin_b` and `spin_c` instead;
     * `A` is recomputed from the horizontal velocity, `hold = 0`, `tick_prev = tick`;
     * **no `bounce_count` increment**.
   * The cord parameters are `ball+0x494..0x4A0` (degrees, degrees, fraction, fraction). The live ball gets them from
     the command at launch (`fn_886B5128 +0x7AC..+0x7E8`: `C+0x30 -> +0x494`, `C+0x34 -> +0x498`, `C+0x38 -> +0x49C`,
     `C+0x3C -> +0x4A0`), and the command gets them from the planner's scratch ball `ball+0x494..0x4A0`
     ([shot-to-template.md](shot-to-template.md) section 6). Nothing else stores those four ball fields (the other
     literal hits are other objects), and the image holds 0. So the round trip carries **zeros**: a let-cord touch keeps
     the ball's direction except for the elevation rule (`acos(n·ĥ)` with `cord_elev = 0`: a falling ball leaves
     horizontal), with no speed or spin loss beyond the `spin_c` double scale by 1 (M-high, G3b).
7. **Dead ball.** If a bounce or net event happened this tick and `max_bounces <= bounce_count`, then
   `ball+0xD0 = launch_frame + tick + 1`.
8. `vel (+0x4F0) = (pos - prev)*60`, still in local m/s, then convert back to world (`fn_889C0FE8`).

### Net flags `fn_889C0C70` (H, near-miss draft `gp4_ball_mode_flags_nearmiss.c`)

| mode | (check_net, solid_net, net_cord) |
|---|---|
| `bounce_count != 0` (any mode) | (1, 1, 0) |
| Net, Wood | (1, 1, 0) |
| LetIn / LetOut | (1, 0, 1) |
| prediction modes `9EA301C2` / `5D25ED1D` | (0, 0, 0) |
| In or Out | (1, 1, 0) if `P0.x*P1.x > 0`, else (0, 0, 0) |
| anything else | unchanged |

**In or Out shots that cross the net do not check the net**: the outcome roll already decided they clear it.

## 6. Bounce response `fn_889C1C80` (0x2EC bytes; H, read in full; `ball_bounce_response`)

1. `v.y = -v.y`.
2. If `v ≠ 0` and `|v̂ · up| < 0.99999` (pool+0x490), the rotation axis is `v × up`; otherwise it is (0, 0, 1)
   (`lbl_880FC6B0`).
3. `theta = atan2(v.y, v.x)`. This uses **x only**, not the horizontal length, so cross-court balls see a slightly
   different elevation. If `theta > π/2`, then `theta = π - theta`.
4. Evaluate the four template curves (curve16, `fn_881899D8`): `loss = c40(spin_a)`, `decay = c4C(spin_a)`,
   `yaw = c64(spin_b)`, `out = c58(theta)`.
5. `tilt = wrap(out - theta) * |5 * spin_a|`. The wrap is `fn_8817B608`: `>= π → -2π`, then `< -π → +2π`. **The weight
   is not clamped**: at `spin_a = -0.4` it is 2, so the elevation overshoots the template angle by the same amount
   again. In the original the angle is formed as `fmadds(wrapped, weight, theta) - theta`.
6. `v *= 1 - loss`.
7. Rotate `v` by `tilt` about `axis` (`fn_8864F7B8`: quaternion `fn_8825D450` (n·sin(a/2), cos(a/2)), matrix
   `fn_8864E310`, row-vector transform with a w divide; right-handed). For a ball moving in either x direction a
   positive tilt raises the outgoing elevation.
8. Rotate `v` by `yaw` about up. **`spin_b` is used raw**: the left-hander sign does not mirror the kick.
9. `spin_a *= 1 - decay`, `spin_b *= 1 - decay`. If `no_sidespin`, then `spin_b = spin_c = 0`; else
   `spin_c *= 1 - decay`.
10. `arc2_pos = pos`, `arc2_vel = v`, and the drift is rebuilt from the horizontal outgoing direction
    (`fn_889C0DC0(ball, 0)`). The call at `889C1F58` is the per-surface patch point ([surfaces.md](surfaces.md)
    section 7).

**Values.** The retail bounce curves are all single-key ramps over `spin_a` in [-0.2, 0] for the strokes. For
FlatNormal, the speed factor is 0.9 at `spin_a <= -0.2` and **1.15 at `spin_a >= 0`**: flat and slice balls speed up at
the bounce. The spin retained is 0.25 (topspin) to 0.5. `c58` is the identity (0..1.5 → 0..1.5), so `tilt = 0`: the
outgoing angle equals the incoming one except through the spin-weighted overshoot of non-identity rows.
`ball_templates.yaml` has `bounce_evaluated` per row. With the template values there is no friction or spin coupling
other than these curves, and no surface term ([surfaces.md](surfaces.md)).

## 7. Court geometry and in/out (H unless noted; `ball_court_bounds`, `ball_push_out`, `ball_out_class`)

* **`fn_8866E318(PC, serve, out)`**, cm, on the receiver's half (`x > 0`; planning is mirrored by the court-side tag
  `a2eda1e7`):
  * Rally: `xmax = 1194.5` (pool+0x2C0). `z = ±415.5` for singles (pool+0x2C4/0x3FC), or `±552.5` for doubles when
    `match+0x327` (pool+0x2BC/0x400).
  * Serve: `xmax = 646.0` (pool+0x140). The box is `z ∈ [-4, 415.5]` when `match+0xAC == 0x23BAED9E` (an even point
    count, the deuce court; [rules-and-scoring.md](rules-and-scoring.md)), else `[-415.5, 4]`.
  * All bounds are then widened by `2 × radius = 8 cm`. The constants are real court lines plus half a line width
    (11.885 + 0.06, 4.115 + 0.04, 5.485 + 0.04, 6.40 + 0.06 m).
* **Out test** in `fn_886807C0`: `|x| > xmax || z > zmax || z < zmin || x < 0`.
* **In outcome** (H, G3b; replaces the earlier text that put the `ball+0x4C0` draw here):
  1. `fn_886807C0 +0x398..+0x48C`: `x = clamp(x, 75, xmax)`, `z = clamp(z, zmin, zmax)` (pool+0x604 = 75).
  2. Common tail `+0x874..+0x8C0`, for every outcome: `0 < x < 75 → 75`, `-75 < x < 0 → -75` (x = 0 is kept).
  3. Planner In case (`fn_886AE528 +0xEC8..+0xF44`): `fn_886805E0` pulls the target back toward the hitter by
     **`S+0xD78` cm** along the horizontal hitter→target direction (`0x8868075C`; `S+0xD78` has only a zeroing store,
     `0x88695C10`, so its value is analyser/data output, 0 by default), then calls the selector's vtbl slot 8
     (`fn_88693280`: clip the hitter→target segment to the court polygon from `fn_88693040`).
  4. `x = max(x, 50)` (pool+0xF0, `+0xF00`), mirror to the world frame, `planned = 1`, probe.
  `ball_in_target`, `ball_in_shortfall`, `ball_target_min_depth`.
* **Out outcome**, `fn_88672130` push-out:
  * `dx = |x| - xmax`; `dz = z - zmax` (when `z >= 0`) or `zmin - z`.
  * If `dx > 3` or `dz > 3`, the point is already out and left unchanged.
  * Otherwise move the coordinate with the smaller `|overshoot|` to 3 cm beyond its line (pool+0x4C).
  * Clamps: ±100000 (pool+0x2EC/0x494). The `x <= 0` branch has its max/min operands swapped, so it never pushes;
    this is harmless because targets are always planned with `x > 0` (H, quirk).
* **`fn_88662C08` grades how far out a point is.** Earlier notes read this as an in/out classifier; it is not one. It
  uses `w, A, B, C` = `cfg+0x13C..0x148` = 50, 100, 100, 200 cm:
  * **`Out 0x81A72B79`** inside the box `(-A, xmax+w) × (zmin-w, zmax+w)`. This box includes the court itself.
  * **`OutFar 0x2C59FAEA`** (crc32 resolved here) inside `(-(A+C), xmax+B+w) × (zmin-B-w, zmax+B+w)`.
  * Else **`0x280AE84D`** (unnamed; "OutVeryFar" is not its preimage).
* **Out outcome in full** (`fn_886807C0 +0x494..+0x844`, H, G3b):
  1. Forced call (`r24`, last argument) → keep the target, grade it.
  2. Target already out of bounds → keep it (mirror only), grade it.
  3. Otherwise (the Out came from b50/b51): `S+0xD90 = S+0xD8C + 1`; if `|S+0x430|` and `|S+0x434|` are both below 0.1
     (pool+0x2AC) set the stick to `(0, 1)`; call the selector's vtbl slot 4 (`fn_886935A0`: court polygon grown by
     `S+0xD90`, `fn_8867D150` moves the point onto it when `S+0xD8D`); then `fn_88672130` push-out.
  4. Mirror. If point end or `fn_88662738` (the single-point reach test, same `S+0x7DC/0x7E0` geometry as
     `fn_88671B10`) accepts the pushed point → grade it.
  5. Else, from the **original** target `(x0, z0)`: the three line points `(x0, zmin)`, `(x0, zmax)`, `(xmax, z0)`;
     strict minimum of the squared distances (start value -1, pool+0x38; ties keep a stale register). If the minimum
     is > 40000 cm² (200 cm, pool+0x614) → **demote to In**, clamp to `[-xmax, xmax] × [zmin, zmax]`. Otherwise
     `r = U[sqrt(d²), 200]` (pool+0x364) and `target = orig + normalize(line point - orig) * r`, then push-out.
  6. Grade with `fn_88662C08` (Out / OutFar / `0x280AE84D`), then the ±75 tail.
  `ball_out_target_nonforced` models step 5 (with a defined tie rule).

## 8. Shot error and outcome dice `fn_886807C0` (H for the formula, M for `b50/b51`; `ball_outcome_decide`)

* **RNG `fn_8861E598`**:
  ```
  t = (s1 >> 15) ^ s1
  s2 *= 0x10DCD
  s1 = (t << 17) ^ t
  u = (float)(s2 ^ s1) * 2^-32, clamped to <= 1
  result = lo + u (hi - lo)
  ```
* **Three draws** r1, r2, r3, all U[0, 1):
  ```
  P = clamp01(S+0x718 + S+0x564)
  G = DebugConfig+0x784 && !match+0x329 && match+0x328
  C = G && (r3 < S+0x71C || S+0x572)
  A = r1 < P || S+0x56D || S+0x56E
  B = (A && r2 < S+0x720) || S+0x56E
  Net if  !C && A && B && G
  Out if  !Net && (!b50 || (!C && b51 && A) || target out)
  In  if  !C
  Let otherwise
  ```
* Only the four PlayerState floats carry skill, timing and fatigue; they are analyser outputs ([gp8.md](gp8.md),
  [analyser-graphs.md](analyser-graphs.md)). The template never adds error.
* **`b50/b51` (`fn_88671B10`, 0x620 bytes; H, transcribed by G3b; geometry names M).** Inputs: the hitter
  position `p` (shot record +0x00) mirrored by `fn_8865E730` into the receiver frame (y := 0); rally bounds from
  `fn_8866E318(serve = 0)`; `R = S+0x7E0`, `Rm = max(S+0x7E0, S+0x7DC)` (the fsel at `+0x11C`); angles
  `a1 = ctrl+0x44C`, `a2 = ctrl+0x450` in degrees (pool+0x184), directions `d(a) = (sin a, 0, cos a)`
  (`fn_8817B500` = sin into x, `fn_8817B3F8` = cos into z). Corners of the receiver half from 1 m past the net
  (pool+0x20 = 100): `q1 = (100, zmax)`, `q2 = (100, zmin)`, `q3 = (xmax, zmin)`, `q4 = (xmax, zmax)`.
  `cy(d, w) = d.z w.x - d.x w.z` (the `vpermwi` 99/135 cross product, y lane).
  ```
  point end (match+0x318 == 0x029EAAF4)                    -> b50 = 1, b51 = 1
  g1 = (|p-q2|² > Rm² && |p-q1|² > Rm²) || cy(d1, q4-p) > 0 || cy(d2, q3-p) < 0 || (|p-q3|² < R² && |p-q4|² < R²)
  g2 = |p-q3|² < Rm² && |p-q4|² < Rm² && |p-q1|² > R² && |p-q2|² > R² && cy(d1, q1-p) < 0 && cy(d2, q2-p) > 0
  all5 = the five fan points p + d1 Rm, p + d1 R, p + d2 Rm, p + d2 R, p + (Rm, 0, 0) are all strictly inside
         (100, xmax) x (zmin, zmax)
  all5 -> b50 = 1, b51 = 0;  else g2 || !g1 -> b50 = 1, b51 = 1;  else b50 = 0, b51 = 1
  ```
  Offsets: g1 `+0x2F0..+0x3D4`, g2 `+0x3D4..+0x4A4`, fan tests `+0x4A4..+0x5A4`, decision `+0x5A4..+0x61C`. In the
  roll, `b50 = 0` forces Out and `b51 = 0` stops a failed error roll (A) from producing Out. `R`, `Rm`, `a1`, `a2`
  are data (no literal writer, [gp8.md](gp8.md) section 6). `ball_reach_flags`. Reading (M): `[R, Rm] × [a1, a2]` is
  the fan of landing points the hitter can produce; if all of it is in the court an error cannot go long or wide.
* **Net/Let targets.** The target is moved so that the net-plane height equals 80 cm (Net) or 90 cm (Let), using the
  section 3 aim solver. The ball then really touches the net through the stepper's net branch (section 5).

## 9. Ball prediction (H, [gp3.md](gp3.md) section 2; `ball_predict`)

`fn_886AD278` copies the 0x540-byte ball and rewrites LetIn → `0x9EA301C2` and LetOut → `0x5D25ED1D`, clearing the
three net flags so the copy behaves as a live ball. It then runs `fn_889C2818` once per tick (tick++ before the step)
for **at most 600 ticks**, until `bounce_count >= 2` or the mode is Net or Out. Each tick it stores a 0x30-byte sample
(position, velocity, ...). The players' reach and interception ([gp2.md](gp2.md)) score these samples, so prediction
and the real ball are the same model. Because Out/Net balls stop after one sample, players never chase them (M).
`fn_8867B2D8` derives the event frames from the samples: first, first-bounce and last tick, plus Let/Out specific ones
(`ball+0xB0..0xEF`).

## 10. Physics events and timing (H)

* **60 Hz.** `stepper+0x1C = 60`, `+0x20 = 1/60`. The generators' `+4` holds 1/60.
* **Frame order.** `fn_886B5128` applies commands whose `due_frame <= match.frame`, which launches the ball:
  `ball+0x43C = 1`, `+0x530 = 1`, `+0x20 = frame`. It then runs the prediction. The instance step then calls
  `fn_889C2818` for the real ball ([gp3.md](gp3.md) section 1).
* **Launch frame** `+0x20`; **landing frame** `+0xC8 = launch + (int)(60 tau)`. Because tau is built by repeated
  addition, `60 tau` can truncate one tick short of `bounce_tick`, so `+0xC8` can be one frame earlier than the real
  bounce (H). **Dead frame** `+0xD0` is set as in section 5 step 7.
* **Sound and contact events.** Ground, Net and Let contacts for sound and the umpire come from the Havok
  contact-event queue `GameDB:/GameDB/Physic/EventQueue` ([gp4.md](gp4.md) section 2, [gp5.md](gp5.md)). Havok only
  detects contacts of a keyframed ball body; it never moves the ball.

## 11. Values summary (from the data files; STEP reading unless noted; a4 = 0.06, net 91.4 cm assumed)

Primary solver only (f4C = 1), spin blend 0.5. Scenarios are in `tools/ts4data/template_sim.py`; "ground" is a
cross-court shot over 23.8 m.

| class (rows) | launch km/h | at bounce km/h | flight s | apex m | net clearance m |
|---|---|---|---|---|---|
| serve (12) | 141–193 | 92–147 | 0.38–0.57 | contact 2.7 | 0.18–0.43 |
| flat ground (4) | 121–140 (RAMP 129–148) | 59–70 (66–78) | 0.87–1.03 | 1.7–2.0 | 0.72–1.09 (0.52–0.75) |
| topspin/slice ground (8) | 88–110, 7 rows speed-limited (RAMP 109–128, none) | 31–48 (49–59) | 1.2–2.2 (1.0–1.2) | 1.9–6.0 (1.5–2.4) | 1.0–5.0 (0.6–1.4) |
| volley (4) | 67–109 | 36–76 | 0.5–1.0 | 1.0–1.7 | 0.08–0.57 |
| smash | 144 (RAMP 151) | 116 | 0.32 | contact | 1.0 |

`T` takes 5 values (0.04–0.0525), so `k` = 0.67–0.875 /s. f4C = 0 (full secondary stage) slows strokes by 15–30% and
raises the apex by the Apogee offset (1.5–3.25 m under RAMP for FlatNormal).

## 12. Porting recipe

1. Load the rows: `ball_template_from_be` on the original bytes, or the YAML.
2. Pick the outcome: `ball_court_bounds`, `ball_reach_flags`, `ball_outcome_decide`, then `ball_in_target` +
   `ball_in_shortfall`, `ball_push_out` / `ball_out_target_nonforced`, `ball_wood_target`, or the aim solver for
   Net/Let (`ball_aim_bracket_lo` gives its lower end). Put the per-player inputs in `ball_modifiers` (section 16).
3. Plan: `ball_probe` gives tau and the bounce tick.
4. `ball_launch`.
5. Each tick: `tick++`, `ball_step`. React to the `BALL_EV_*` events.
6. Players: `ball_predict`.

Retuning levers: `T`/`a4` (drag), the spin lo/hi values, the primary curves (speed or time), the secondary weight
(`S+0x778`), the bounce curves (`c40`, `c4C`, `c58` with the `|5 spin_a|` gain, `c64`), the error floats, the
reach fan (`S+0x7DC/0x7E0`, `ctrl+0x44C/0x450`), the In shortfall `S+0xD78`, the Wood box, the court tolerance
(2 × radius), the 75 cm minimum depth and the 200 cm Out demotion radius.

## 13. Corrections to earlier notes

* **gp4 section 1.4, step 5.** The let-cord branch does **not** increment `bounce_count`; it scales `spin_c` twice; and
  its rotation adds the current elevation. The net test polarity is resolved (section 5 step 6).
* **gp4 / gp4b, later bounces.** These snap `pos.y = 0`. The draft `gp4b_step_flight` does not do this; `ball.c` does.
* **gp4b section 10.3 (`fn_88662C08`).** It grades how far out a point is (Out / OutFar / unnamed). A pushed-out point
  is graded Out; earlier text said it could be classified "in".
* **gp4 section 1.5.** The elevation tilt weight `|5 spin_a|` is unclamped, the yaw kick ignores handedness, and
  `theta` ignores z.
* **Drift.** Lateral and along-track drift flip sign at the first bounce (section 4).
* **gp4b section 10.3 and section 7 of this note (first version), In outcome.** The `ball+0x4C0..0x4CC` roll belongs
  to the **Wood** branch and is relative to the hitter, not a groundstroke dispersion of In targets; the In clamp is
  `x ∈ [75, xmax]`, plus the `S+0xD78` pull-back (G3b).
* **gp4 / gp4b `+0x4E0` "frozen".** It only skips the step on the launch frame (G3b).
* **gp8 section 6.** The fan test rectangle is `(100, xmax) × (zmin, zmax)` (the receiver half from 1 m past the
  net), not `[-xmax, xmax]`; the angles are controller fields `ctrl+0x44C/0x450`, not `S+0x44C/0x450` (G3b).
* **shot-templates.md section 2.** The "12-byte pointer entries" are array headers `{rel, count, capacity}`. The row
  header fields are the aim-table keys and the two parameter blocks (section 1).

## 14. Open items

1. The curve STEP/RAMP question (G1). The values in section 11 differ strongly for topspin and slice. Section 1 adds
   static evidence against a type-keyed fixup in Swing; a generic loader fixup is not excluded.
2. Serve sub-record (`row+0x10`) and stroke ranges (`row+0x14`): no reader found after the searches of section 1.1
   (likely unused).
3. Runtime confirmation that the live ball keeps the State.bin image (`+0x4C0..0x4E1`), and the net height.
4. Values of the data-driven inputs `S+0xD78`, `S+0xD8C`, `S+0x7DC/0x7E0`, `ctrl+0x44C/0x450`, `S+0x774/0x778`
   (analyser outputs, [analyser-graphs.md](analyser-graphs.md)).
5. `fn_88693280` / `fn_88693040` (court polygon clip of the In target) and `fn_886935A0` / `fn_8867D150` (Out margin)
   are described, not ported.
6. A runtime check of the unclamped tilt weight (Xenia ball dump).

## 16. Player modifiers on the ball: traits, coach skills, Risk, power tier (G3b)

**Summary (H for the code facts).** No ball routine reads a skill id, the Risk flag or the power tier. Per-player
effects reach the ball only through the fields below. Analyser graphs (data, [analyser-graphs.md](analyser-graphs.md))
fill most of them, and the graphs can read the skill list `S+0x640` through `Profile.SkillList` link ports. The
`ball_modifiers` struct in `ref/gameplay/ball.h` exposes each field as an explicit, tunable input. Its `port_*` scales
(speed, the three spins, and the bounce loss, decay and tilt) are port-only extensions. They default to identity.

| pipeline stage | original input | written by | read at | port input |
|---|---|---|---|---|
| template row | request flags `S+0x400..0x40B` (Flat/TopSpin/Slice/Lob, Risk `0x404`, Powerful/Medium `0x405/0x406`, IsWood `0x40A`) → decision tree | input + analysers | `fn_8865ED78` → `ctrl+0xB0` | caller picks the row |
| launch speed / time | row curve × secondary weight `w = clamp01(1 - S+0x778)` | analyser (data) | `fn_886AE528 +0x594` → `C+0x4C` → `ball+0x430` | `sec_weight`, `port_speed_scale` |
| spin | `lerp(lo, hi, S+0x774)` | analyser (data) | `+0x5A4` → `C+0x50` → `ball+0x364`, `fn_889C1868` | `spin_blend`, `port_spin_scale` |
| bounce (skid / low bounce) | template curves of the row only (`c40`, `c4C`, `c58`, `c64`) driven by `spin_a/spin_b`; `no_sidespin` `ball+0x4E1` | data | `fn_889C1C80` | through spin; `port_bounce_*` |
| error roll | `S+0x718 + S+0x564`, `S+0x71C`, `S+0x720`, flags `S+0x56D/56E/572` | analysers / debug | `fn_886807C0` | `outcome` |
| reach fan | `S+0x7DC`, `S+0x7E0`, `ctrl+0x44C`, `ctrl+0x450` | data | `fn_88671B10`, `fn_88662738` | `reach` |
| In depth error | `S+0xD78` (pull-back, cm) | data (only a zeroing store) | `fn_886805E0 +0x17C` | `in_shortfall_cm` |
| Out margin | `S+0xD8C` (+1 → `S+0xD90`) | data; DebugConfig `+0x214` at point end (`fn_886807C0 +0x150`) | `fn_886935A0` | `out_margin_cm` |
| Net / Let aim height | `S+0x750/0x754` = cfg `+0x134/0x138` | planner | `fn_889C29E8` | `net_aim_cm`, `let_aim_cm` |
| frame shot | IsWood `S+0x40A` → Wood box `ball+0x4C0..0x4CC` | analyser + ball image | `fn_886AE528 +0xA7C` | `is_wood`, `ball_config.disp_*` |

**Hard-coded skill tests in Swing (H).** The ability names are in GameDB `99c21615.bin` (26,052 B, sha256
`2e338c58…098a`). The ids are crc32 of the names. A scan of every `lis/ori` immediate in `.text` for those crcs finds
only three abilities, plus one data-driven test:

* **PoisonedSlices `0x55568E39`** (`fn_88695640 +0x4D4..+0x520`). If the controller mode `ctrl+0x48->+0x78->+0 == 2`,
  the match is not at point end, the incoming shot class (`side+0x60`) is **Slice `0xFC6F57A1`**, and the player who
  hit it (index `side+0x48`) owns the skill (`fn_8868F0D8`: the id is in the list `S+0x640` with value > 0.5), then
  the **receiver's** block float `B+0x164` = 1.0; otherwise it is 0. This is a flag for the receiver's analyser graphs
  (its error and difficulty). It does not touch the slice's flight or bounce: no ball routine reads it.
* **InstantRocket `0x82E4BF1A`** (`fn_8869D720`): selects the curve pair `cfg+0x914/0x920` instead of `cfg+0x8FC/0x908`
  that maps the counters `S+0xDFC/0xE04` to `S+0xE00/0xE08`. `S+0xE00` feeds the "Fatality" condition `0xC78C8F06`
  (`fn_88697E98 +0x4C8`: `S+0xE00 > cfg+0x934`). This is the special-shot meter, not a ball parameter.
* **SpectacularVolleys `0x1E8D4F10`** (`fn_886BCE88 +0x6DC`, the serve path that stores the stroke skill): a test next to `S+0xCF0/0xD00`. It does not
  touch the ball.
* **Data-driven test**: condition `0xC42EF3FE` of the evaluator `fn_88697E98` (`+0x450`) tests "player has skill
  `cond+0xC`". It is used by the rule list walked in `fn_886AFDF8`, so data can gate any rule on any skill.

**Risk (RT/LT) and the power tier (H).** In the ball-side code (`fn_886AE528`, `fn_886807C0`, `fn_88671B10`,
`fn_886805E0`, `fn_886B0490`, `fn_886B5128`, `fn_888AA968..888AD300`, `fn_889C0000..889C3000`), Risk `S+0x404` is only
copied to `C+0x9B` (`0x886B0A40`) and back (`0x886B55B8`). Powerful `S+0x405` is copied to `C+0x9A` (`0x886B0A30`)
and increments a match statistic (`fn_886567A8(19)` at `0x886AF6AC`). Neither reaches the speed solve, the spin, the
dispersion or the outcome dice. So:

* Risk changes the row only for Slice (drop shot / drop volley, [shot-to-template.md](shot-to-template.md)).
* A "harder shot, more error" effect can come only from the analyser graphs that read the Request flags and write
  `S+0x718/0x564/0x720/0x774/0x778` (data, U).
* The power tier changes the launch speed only by picking the Finesse/Medium/Powerful row (different speed curves).
* Risk and the tier combine only in the decision tree. The Risky rows 12–15 are unreachable.

## 15. Reproduction

```sh
export TS4_MATCHING_DIR=work/matching-b9
python3 tools/fn_asm.py fn_889C1C80 fn_889C1F70 fn_8817B608 fn_8864F7B8 fn_8825D450 fn_8864E310   # bounce, step, wrap, rotation
python3 tools/fn_asm.py fn_8866E318 fn_88672130 fn_88662C08 fn_88671B10 fn_889C29E8 fn_888ABCC0     # court, push-out, grade, aim
python3 tools/fn_asm.py fn_88662390 fn_886707C8                                                    # row header use
python3 tools/sym_info.py data 0x880D0F70 0x700                                                    # constant pool
python3 tools/ts4data/templates.py --settings work/disc/core/334e7e0d.bin --state work/disc/core/623d0979.bin \
    --yaml data/gameplay/ball_templates.yaml --trajectories data/gameplay/ball_trajectories.csv --curve-mode both
python3 -m unittest tests.test_ref_ball tests.test_ts4data_ball tests.test_ts4data_templates
cc -std=c11 -Wall -Wextra -Werror -DBALL_CROSSCHECK_DRAFT -Isrc/xbox360 ref/gameplay/ball.c ref/gameplay/test_ball.c \
   src/xbox360/drafts/gp4b_ball_model.c -lm && ./a.out
python3 -c "import zlib;print(hex(zlib.crc32(b'OutFar')))"    # 0x2c59faea
# G3b: whole-module dump for the scans of sections 1.1, 2, 5, 16 (VMX128-aware, tools/ppcdis)
#   take .text (VA 0x88150000, file 0x14BA00, 0x9B07B8 bytes) of orig/54540859/Swing_DLL.dll and pipe it to
#   work/ppcdis/target/release/ppcdis 88150000  -> 2,540,014 lines
python3 tools/fn_asm.py fn_886AE528 fn_886807C0 fn_88671B10 fn_886805E0 fn_888ABCC0 fn_88695640 fn_8868F0D8
python3 -c "import zlib;print(hex(zlib.crc32(b'PoisonedSlices')))"  # 0x55568e39 (immediate at 0x88695B14/0x88695B24)
```

Tools: Python 3.13.18 (standard library), capstone 5.0.7 for raw disassembly, gcc 13.3.0 (`-std=c11`).
