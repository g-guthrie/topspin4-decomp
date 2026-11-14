# Ball physics: complete specification (family G3)

This note covers every ball mechanic of Top Spin 4 (Xbox 360): the launch solve, the flight model, all solver kinds, the
bounce, the net and let cord, the court and in/out geometry, shot error, the prediction stepper, the ball defaults,
the template rows, and event timing. It consolidates [gp4.md](gp4.md) and [gp4b.md](gp4b.md) and corrects them where
the machine code says otherwise (section 13), and it adds the routines those notes left as "described, not
re-derived".

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
| row+0x10 | `serve_params_rel` | Serve rows only: a self-relative pointer to a sub-record. It holds 8 floats (`+0x00 = 0.1`, `+0x18` = the serve speed 150/140/190 km/h, `+0x1C` = 0.3..0.5, `+0x14` differs per row and looks like garbage) followed by two `{rel, type}` curve20 elements at `+0x20/+0x28`. These are equal to the row's own `spin_a` lo/hi. No reader was found. | H layout, U use |
| row+0x14 | `stroke_ranges_rel` | Stroke rows only: a pointer to 20 `(lo, hi)` float pairs, for example `(0.2,1)(0.2,1)(0,0.9)(0,0.5)(0,0.3)(0,1)...`. `fn_88662390` stores it as selector `entry+0x10`. No reader of `entry+0x10` was found: a scan of all `lwz rA,0xB0(..)` followed by `+0x10(rA)` found none. | H layout, U use |
| tpl+0x00 | `primary` | Value `{rel, type, kind}`. The kind hash at tpl+0x08 selects the solver (section 3). | H |
| tpl+0x0C | `secondary` | Value with the secondary kind hash at tpl+0x14. | H |
| tpl+0x18 / +0x24 / +0x30 | `spin.vertical_a` / `along_c` / `lateral_b` | Each slot is a standard XData array header `{rel, count = 2, capacity = 2}` pointing at two elements `{rel, type}` = (lo, hi). So the "12-byte pointer entries" are array headers. | H |
| tpl+0x3C | `T` | Drag scale. | H |
| tpl+0x40 / +0x4C / +0x58 / +0x64 | `bounce.*` | Array headers `{rel, count, capacity}` of curve16 keys: speed loss vs `spin_a`, spin decay vs `spin_a`, outgoing elevation vs incoming elevation (rad), and yaw kick vs `spin_b` (rad). | H |
| row+0x88 | `id` | Unique row id, the key of the decision-tree leaf ([shot-to-template.md](shot-to-template.md)). | H |

**Value types.** `0x33799CCE` is a float. `0xF9F12A60` is a curve20 with 20-byte keys `{x0, x1, y0, slope, y1}`.
`0x7A330099` is a 2-D table: 16-byte rows `{curve16 header relative to the row, ?, a_key}`, interpolated in `a` (distance,
cm) between the curve16 values at `b` (hit height, cm).

**Curve reading (open, owned by G1).** Every retail curve20 key has `slope = 0` and stores the end value `y1` at +0x10.
The evaluator `fn_8817A688` reads only `slope`.

* `STEP`: the shipped code with the shipped data. The curve holds `y0`.
* `RAMP`: a load-time fixup sets `slope = (y1-y0)/(x1-x0)`.

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
  * `+0x4C0..0x4CC` dispersion box = `(-800, -400, -400, 400)` cm;
  * `+0x4D0` radius = **4.0 cm**, `+0x4D4` a4 = **0.06**, `+0x4D8` g = **9.81**, `+0x4DC` max_bounces = **5**;
  * `+0x494..0x4A0` cord parameters = 0, default P0/P1 = (-1300, -170, 100) / (1300, 0, -100).
* **The writer** of `ball+0x4D0..0x4DC` is therefore the generic XData load of the serialised engine state (`State.bin`
  is a snapshot of the gameplay objects). No instruction stores these fields with a literal offset. The only exceptions
  are the zeroing constructors `fn_882734C8` and `fn_886A9050`, the copy `fn_88272BC0`, and `fn_886B1BA0 +0x2178`, which
  writes `max_bounces = 10` for the practice/serve ball. (H for the image, M that the live ball is loaded from it
  unchanged.)
* **Dispersion box.** `(-800..-400, -400..400)` cm would push every In target 4–8 m deeper. That conflicts with play, so
  either the live block differs or the fields mean something else (L). A runtime read of `ball+0x4C0` is needed.
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
  1. `lo = fn_888ABCC0(ball, f1 = cfg+0x130 = 100 cm)`: a point on the hitter→target line (geometry M, not transcribed).
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
   reaches 0 with `bounce_count > 0`, set `tick_prev = tick`. The writer of `+0x28/+0xA0` was not found (U; gp4
   guessed the serve toss).
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
   * The cord parameters are `C+0x30..0x3C` (degrees, degrees, fraction, fraction). They are 0 in the default block;
     their command writer is a planner path not located (U).
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
* **In outcome** (`fn_886AE528 +0xA38`, M for the clamp order):
  1. Clamp the target into the bounds.
  2. Force `x >= 75` cm past the net (pool+0x604/0x610).
  3. For groundstrokes, add `U[ball+0x4C0, +0x4C4]` to x and `U[+0x4C8, +0x4CC]` to z, mirrored by side, using two RNG
     draws.
  4. Set `planned = 1` and probe.
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
* gp4b section 10.3 also describes a non-forced Out branch that demotes to In beyond 200 cm (pool+0x614 = 40000 cm²)
  and otherwise moves the target by `U[0, 200]` cm along `(target - base)` (M, not re-read).

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
* **`b50/b51` (`fn_88671B10`).** Both are set to 1 and returned at once when `match+0x318 == 0x029EAAF4`. Otherwise
  the function builds the court bounds and the player's facing (`S+0x7DC/0x7E0`, the angle limits
  `ctrl+0x44C/0x450` in degrees via sin/cos) and clears the flags by squared-distance tests against `S+0x7E0^2`. It is
  a reachability/angle restriction (M; the full decision was not transcribed). The reference model takes `b50/b51` as
  inputs.
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
2. Pick the outcome: `ball_court_bounds`, `ball_outcome_decide`, then `ball_in_target` or `ball_push_out`, or the aim
   solver for Net/Let.
3. Plan: `ball_probe` gives tau and the bounce tick.
4. `ball_launch`.
5. Each tick: `tick++`, `ball_step`. React to the `BALL_EV_*` events.
6. Players: `ball_predict`.

Retuning levers: `T`/`a4` (drag), the spin lo/hi values, the primary curves (speed or time), the secondary weight
(`S+0x778`), the bounce curves (`c40`, `c4C`, `c58` with the `|5 spin_a|` gain, `c64`), the error floats, the
dispersion box, the court tolerance (2 × radius), and the 75 cm minimum depth.

## 13. Corrections to earlier notes

* **gp4 section 1.4, step 5.** The let-cord branch does **not** increment `bounce_count`; it scales `spin_c` twice; and
  its rotation adds the current elevation. The net test polarity is resolved (section 5 step 6).
* **gp4 / gp4b, later bounces.** These snap `pos.y = 0`. The draft `gp4b_step_flight` does not do this; `ball.c` does.
* **gp4b section 10.3 (`fn_88662C08`).** It grades how far out a point is (Out / OutFar / unnamed). A pushed-out point
  is graded Out; earlier text said it could be classified "in".
* **gp4 section 1.5.** The elevation tilt weight `|5 spin_a|` is unclamped, the yaw kick ignores handedness, and
  `theta` ignores z.
* **Drift.** Lateral and along-track drift flip sign at the first bounce (section 4).
* **shot-templates.md section 2.** The "12-byte pointer entries" are array headers `{rel, count, capacity}`. The row
  header fields are the aim-table keys and the two parameter blocks (section 1).

## 14. Open items

1. The curve STEP/RAMP question (G1). The values in section 11 differ strongly for topspin and slice.
2. Readers of the serve sub-record (`row+0x10`) and of the 20 stroke ranges (`row+0x14` → `entry+0x10`).
3. The live values of `ball+0x4C0..0x4DC` and the net height. The default dispersion box looks wrong for In shots.
4. The writer of `hold/hold_delta` (`+0x28/+0xA0`) and of the cord parameters `C+0x30..0x3C`.
5. `fn_88671B10` (`b50/b51`) and `fn_888ABCC0` (aim bracket) in full; the non-forced Out demotion branch.
6. A runtime check of the drift sign flip at the bounce and of the unclamped tilt weight (Xenia ball dump).

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
```

Tools: Python 3.13.18 (standard library), capstone 5.0.7 for raw disassembly, gcc 13.3.0 (`-std=c11`).
