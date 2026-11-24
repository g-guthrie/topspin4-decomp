# GP4B notes: ball model spec (kind solvers, shot templates, launch sequence)

Family GP4B, follow-up of GP4 (`docs/gameplay/gp4.md`, `work/gameplay-notes/gp4.md`). Module Swing_DLL.xex, sha256
`dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44` (symbols.txt sha256 prefix `ec79e191534b9b28`), all addresses are xex VAs.
Files: `src/xbox360/gp4b_types.h` (types, template layout, kind hashes), `src/xbox360/drafts/gp4b_ball_model.c` (reference implementation, host
compilable, self-test with golden vectors from the original code). No function was matched (VMX128 + float-exact code, same as GP4), so there is no
`work/specs/GP4B/` spec.

Confidence tags: **H** read from the machine code and validated against an emulation of it (see section 9), **M** read directly but not validated,
**L** guess.

## 0. Headline and corrections to GP4/GP3 (read first)

1. **Names of the template kinds (H).** zlib.crc32 of plain names reproduces all five hashes (found by dictionary search, each hit is a 32-bit
   match against ~1e7 candidates, so they are real):
   `DropTime 0x5D90675B`, `BounceSpeed 0x50B89452`, `InitialSpeed 0xC1965E5C`, `AverageSpeed 0x2DB3EB6F`, `Apogee 0x879BA860`
   (`python3 -c "import zlib;print('%08x'%zlib.crc32(b'DropTime'))"`). They name what the solver holds fixed: the flight time curve, the speed at the first
   bounce, the speed at launch, an average speed (stubbed, see 5.4) and the apex height.
2. **The commanded speed is the INITIAL (launch) speed, not the arrival speed.** `fn_888AAB98` is `|v(0)|^2` (no `E` factor in the coefficient, equal to
   `|fn_888AB220|^2`), `fn_888AAA70` is `|v(tau)|^2` (extra factor `E = e^{-k tau}`, equal to `|fn_888AB0E0|^2`), `fn_888AACB8` is `d|v(0)|^2/d tau`
   (checked against finite differences). GP4 had AAB98/AAA70 the other way round. `ball+0x370` (command `C+0x54`, km/h) and the result field `O+0x20` are initial speeds.
3. **The kind solver is not part of the live launch.** `fn_889C19F0` (launch) takes `tau = ball+0x00` and the bounce tick `ball+0x04` straight from the
   command (`C+0x40`, `C+0x44`). The solver (`fn_888AD0E8` -> kind routine) is only reached from the probe `fn_889C2678`, which the swing planners call (13
   call sites in `fn_886AD758`, `fn_886AE528`, `fn_886B1BA0`, `fn_886B2D00`, `fn_889C2940`, `fn_889C29E8`) to produce tau/tick for the command.
4. **`ball+0x360` is a byte offset of the template row inside the table**, not an index: planners store `row_ptr - table_base`, launch does `S+0x3C + ball+0x360 + 0x18`.
5. **`ball+0x344` is `cmd_from.y * 0.01` (launch height in metres)**, not a "w" component; it is the argument of the spin curves. (The scale vector
   `lbl_88D46390 = (0.01, 0.01, 0.01, 0)` zeroes `w`.)
6. **Spin vector after a bounce uses the HORIZONTAL velocity direction**: `fn_889C0DC0(flag 0)` forces `y = 0` of `arc2_vel` (`vrlimi128 ..., 0x4, 3`; VMX128 mask bits 8/4/2/1 = x/y/z/w).
7. Template layout is relative to `tpl = row + 0x18` (= `ball+0x24`): bounce curve headers are at `tpl+0x40/+0x4C/+0x58/+0x64` (= row+0x58/+0x64/+0x70/+0x7C), not row+0x40...; `T` is at `tpl+0x3C` (= row+0x54).
8. The frame counter `ball+0x18` is incremented by the CALLER before every `fn_889C2818` (`fn_886AD1F0`, frame step), starting from 0 at launch; the
   stepper never writes it.
9. Where the ball origin comes from: the probe leaves `ball+0x70 = (0, radius_cm, 0, 0)`, so local `y = world y - radius` (see 4.3). The ball centre therefore touches the ground at local `y = 0`.

## 1. Template data model (H unless noted)

All template data is big-endian with self-relative offsets (every `rel` is a signed 32-bit offset from the address of the field that contains it).

```
table (S+0x3C)  --  row = table + ball+0x360        (row stride and header +0x00..+0x17 unknown; the planners hold row pointers)
tpl = row + 0x18
tpl+0x00  node0 {i32 rel, u32 type, u32 kind}   curve evaluated by fn_888AB6C8: flight-time guess / target speed;  kind = SOLVER kind
tpl+0x0C  node1 {i32 rel, u32 type, u32 kind}   second curve (offset, speed delta, apex delta);               kind = SECONDARY kind (tpl+0x14)
tpl+0x18  {i32 rel,?,?}  -> spin pair A {i32 rel_lo,u32 type_lo, i32 rel_hi,u32 type_hi}   spin_a  (vertical, topspin/backspin lift)
tpl+0x24  {i32 rel,?,?}  -> spin pair B                                                      spin_c  (along track)
tpl+0x30  {i32 rel,?,?}  -> spin pair C                                                      spin_b  (lateral / sidespin)
tpl+0x3C  f32 T                       (row+0x54)  "drag scale": k = T / a4
tpl+0x40  curve16 header {i32 first_key_rel, i32 count, u32 ?}   bounce: speed loss   = c(spin_a)     (fn_889C1C80, M)
tpl+0x4C  curve16 header                                        bounce: spin decay    = c(spin_a)
tpl+0x58  curve16 header                                        bounce: outgoing elevation = c(theta)
tpl+0x64  curve16 header                                        bounce: yaw kick       = c(spin_b)
```

Node/curve formats (functions read in full, every branch exercised by the validation):

* **node type** (`fn_888AB6C8`): `0x7A330099` 2-D table, `0xF9F12A60` 1-D curve (20-byte keys), `0x33799CCE` constant float at `node+rel`, anything else returns 0.0.
  Arguments: `d = sqrt(fma(dx,dx,dz*dz))` with `dx = P1.x-P0.x`, `dz = P1.z-P0.z` (metres, local frame, `P0.y` already reduced by the radius); the curve x is `d*100` (cm); the table's second argument is `P0.y*100` (cm).
* **curve20** (`fn_8817A688`): header `{i32 first_key_rel (-1 none), i32 count}`, keys 20 bytes `{x0, x1, y0, slope, unused}`. Select the last key with `x0 <= x` (the first key if none), `y = fma(max(min(x-x0, x1-x0), 0), slope, y0)`. (Piecewise linear, continuous only when `y0[i+1] = y0[i] + slope[i]*(x1[i]-x0[i])`; no spline.)
* **curve16** (`fn_881899D8`): same header, keys 16 bytes `{x0, x1, y0, y1}`; `y = fma(t/(x1-x0), y1-y0, y0)`, `t = clamp(x-x0, 0, x1-x0)`.
* **table2d** (`fn_8826D278`): header `{i32 first_row_rel, i32 row_count}`, rows 16 bytes `{curve16 header (first_key_rel relative to the ROW, count), u32 ?, f32 a_key}`, `a_key` ascending. Rows enclosing `a`: linear interpolation in `a` of the two curve16 values at `b` (clamped to the first/last row).
* **spin pair elements** (`fn_889C1868`): element `{i32 rel, u32 type}`: type `0xF9F12A60` -> curve20 evaluated at the launch height `cmd_from.y*0.01` (m), otherwise a plain float at `element+rel`. `lo`/`hi` are blended with `ball+0x364` (command `f50`, 0..1): `spin = fma(hi-lo, blend, lo)`.

Hashes at `tpl+0x08` and `tpl+0x14` (names in 0, solver behaviour in 5/6):

| hash | name | as primary (tpl+0x08) `fn_888AD0E8` | as secondary (tpl+0x14) `fn_888AC688` |
|---|---|---|---|
| 5D90675B | DropTime | `fn_888AB8D0` | `fn_888AB7B0` (also inlined in AB8D0) |
| 2DB3EB6F | AverageSpeed | `fn_888AC748` | `fn_888AC100` |
| 50B89452 | BounceSpeed | `fn_888ACDA8` (metric `fn_888AAA70`) | `fn_888AC4A0` |
| C1965E5C | InitialSpeed | `fn_888ACA68` (metric `fn_888AAB98`) | `fn_888AC2B8` |
| 879BA860 | Apogee | (none: unknown primary does nothing) | `fn_888ABF10` (also inlined in AB8D0) |

The template numbers themselves (distance->time curves, spin pairs, bounce curves, `T`) are game data and are not in the executable; they sit in the XData of the
gameplay module. A recorded `Gp3BallState` dump at launch (tau, bounce tick, spin_a/b/c, T, a4, g, radius, P0, P1) is enough to pin one shot without the table.

## 2. Ball state fields used by the model (`Gp4bBall`, offsets are the original ones, `_Static_assert`ed in `gp4b_types.h`)

`+0x00 tau`, `+0x04 bounce_tick (u32)`, `+0x08 T`, `+0x0C = +0x430` (command `f4C`, solver blend), `+0x10 = +0x364`, `+0x14 bounce_count`, `+0x18 tick`, `+0x1C tick_prev`,
`+0x20 launch_frame`, `+0x24 template pointer`, `+0x28 hold`, `+0x2C mode`, `+0x31..34 flags`, `+0x40 pos`, `+0x60 prev`, `+0x70 origin`, `+0x80 A`, `+0x90 spin_a / +0x94 spin_b / +0x98 spin_c`,
`+0xC8 landing frame`, `+0xD0 dead frame`, `+0x100 P0`, `+0x110 P1`, `+0x124 net height (cm)`, `+0x130 arc2_pos`, `+0x140 arc2_vel`,
`+0x150..+0x197` cached constants (`inv_T, inv_a4, k, g*a4, 1/T^2, a4^2, T^2, p0x*T, p1x*T, p0y*T, p0z*T, p1z*T, E, 1/(E-1), tau*A (3), g*a4*tau`),
`+0x340/+0x350 cmd_from/cmd_to`, `+0x360 template row byte offset`, `+0x364 spin blend`, `+0x368 sidespin sign (u8)`, `+0x369 planned (u8)`,
`+0x36C aim_height (m)`, `+0x370 speed_kmh`, `+0x380 / +0x3AC / +0x3D8 / +0x404` solver result structs (0x2C bytes), `+0x430`, `+0x434 shot id`, `+0x43C new_shot`,
`+0x440`, `+0x494..4A0` net-cord params, `+0x4D0 radius_cm`, `+0x4D4 a4`, `+0x4D8 g`, `+0x4DC max_bounces`, `+0x4E0 frozen`, `+0x4E1 no_sidespin`, `+0x4F0 vel`, `+0x500 v_launch`, `+0x510 v_arrive`, `+0x520 speed`, `+0x530 enabled`.

* `+0x369 planned` (set by the planners, not copied from the command): 1 = a real shot planned from the template (net clearance uses `(radius_cm + net_height_cm) * 0.01`, tau comes from the template for DropTime, the secondary stage runs); 0 = a probe of a commanded `speed_kmh` toward a point with wanted net height `aim_height`.
* `+0x368` sidespin sign: `sgn = flag ? -1 : +1` multiplies `spin_b` in the drift vector (planners set it from the hitter's handedness; the preview code compares the match state with 0x029EAAF4 and `0xDA554856` = "Left").
* `+0x4DC max_bounces`: `fn_886B1BA0` stores 10 (`stw 10, 0x4DC(ball)`) for the practice/serve ball; the ctor zeroes it, and with 0 the ball is declared dead at the first event.

Solver result struct `Gp4bSolve` (0x2C bytes): `+0x00 tau` (solved before the template blend), `+0x04 raised` (net-clearance search raised tau), `+0x08 tau_raised`,
`+0x10 metric km/h`, `+0x14 tau_min`, `+0x18 has_min`, `+0x19 net_unreachable`, `+0x1C tau_final`, `+0x20 initial speed km/h`, `+0x24 probe flag (=1 set by fn_889C2678)`, `+0x28 height at the net plane (m)`.
`fn_889C2940(S, B, target)` is a feasibility probe: sets `B.370 = B.3CC`, `planned = 0`, `aim_height = 0`, runs the probe with result A (+0x380) and stores in `+0x384` whether `O.f28*100 < ball+0x124` (the ball would hit the net).

## 3. Shot command -> ball (the 0xE0 record, GP3 `Gp3SwingCommand`; H, `fn_886B5128 +0x5718..+0x5914`)

| command field | ball field | meaning |
|---|---|---|
| `C+0x00` from (cm) | `+0x340`, `+0x100` | hit point; `y` component also feeds the spin curves (metres) |
| `C+0x10` to (cm) | `+0x350`, `+0x110` | landing target; only `x`, `z` enter the arc (the arc ends at local y = 0); `y` is the `pos` of the bounce snap |
| `C+0x20` | `+0x120` (`+0x124` = net height cm) | |
| `C+0x30/34/38/3C` | `+0x494/498/49C/4A0` | net-cord deflection / losses |
| `C+0x40` tau | `+0x00` | flight time, **precomputed by the planner (probe)** |
| `C+0x44` tick | `+0x04` | first-bounce tick |
| `C+0x48` | `+0x360` | template ROW BYTE OFFSET |
| `C+0x4C` | `+0x430` (-> `+0x0C` at launch) | blend weight input `w = clamp(1 - f4C, 0, 1)` of the secondary stage (0 = full template blend) |
| `C+0x50` | `+0x364` (-> `+0x10`) | spin blend 0..1 |
| `C+0x54` | `+0x370` | commanded INITIAL speed km/h (only used by probes) |
| `C+0x58` | `+0x368` | sidespin sign |
| `C+0x70` | `+0x70` | origin of the local frame = `(0, radius_cm, 0, 0)` |
| `C+0x80` | `+0x2C`, `+0x434` | shot id / ball mode hash |
| `C+0x88` | `+0x440` | |
| (apply) | `+0x43C = 1`, `+0x530 = 1`, `+0x20 = match frame` | request launch |

## 4. The complete sequence

### 4.1 Planning (per shot, in the planner, `ball` is the live ball used as scratch, state saved in `+0x1A0`)
1. fill `+0x340/+0x350` (cm), `+0x360` (row offset), `+0x364`, `+0x368`, `+0x369`, `+0x36C`, `+0x370`, `+0x430`, `+0x434`, `+0x4D0/4D4/4D8` (already present);
2. optional aim search `fn_889C29E8`: 10-step bisection of the target point between two bracket vectors (from `fn_888ABCC0`) until the probe's `O+0x28` is within 0.01 of `+0x36C`;
3. **probe** `fn_889C2678(S, B, O)` (`gp4b_probe`): `O.probe=1`; `fn_889C0F70` scales `cmd_*` by 0.01; `T = row+0x54`; `P0 = cmd_from*0.01` with `P0.y = fma(-radius, 0.01, y)`; `P1 = cmd_to*0.01`; `+0x0C/+0x10`; spin blend (`fn_889C1868`, which calls the drift vector `fn_889C0DC0(1)`); `fn_888AD0E8` (solver, sets `+0x00 tau`, `+0x04 tick`);
   then converts back: `P0 = pos = prev = (cmd_from*0.01)*100`, `P1 = (cmd_to*0.01)*100`, `origin = (0, radius_cm, 0, 0)`, `cmd_* = x*100` (`fn_889C0EF8`);
4. the planner stores tau/tick/row offset into the command (`C+0x40/+0x44/+0x48`, the store sites were not located instruction by instruction: M).

### 4.2 Apply and launch (per frame in `fn_886B5128` / `fn_889C2818`)
1. apply (table in section 3), `new_shot = 1`;
2. `fn_889C2818`: `fn_889C1160` to-local (`pos, prev, P0, arc2_pos = (v - origin)*0.01`; `P1, arc2_vel = v*0.01`; `w` lanes -> 0), then
3. **launch** `fn_889C19F0` (`gp4b_launch`): `fn_889C0F70(+0x340)`; `bounce_count = tick = tick_prev = 0`; `tpl = S+0x3C + +0x360 + 0x18`; `T = row+0x54`; `fn_889C0C70(ball, +0x434)` (net flags, `gp4b_mode_flags`); `+0x0C = +0x430`, `+0x10 = +0x364`; spin blend + drift `A`; `fn_888AAEA8`, `fn_888AAE00`; `pos = prev = P0`; `v_launch = fn_888AB220`, `v_arrive = fn_888AB0E0`; `+0xC8 = launch_frame + (int)(60 * tau)`; `fn_889C0EF8`;
4. run `fn_889C1F70` unless `+0x4E0` (frozen), then `fn_889C0FE8` to-world.

### 4.3 Per tick
`tick += 1` (caller), `gp4b_to_local`, `gp4b_step_flight`: `prev = pos`; arc 1 (`fn_888AB558`) while `bounce_count == 0`, else arc 2 (`fn_888AD1C8`), with `t = (float)(tick - tick_prev) * (1/60)`; first bounce when `tick >= bounce_tick` (signed), later bounces when falling and `pos.y < -1.1920929e-7`;
on a bounce the incoming velocity is the analytic `fn_888AB0E0` (first) or `(pos-prev)*60`, `bounce_count++`, `tick_prev = tick`, the first bounce snaps `pos = P1`, the bounce response `fn_889C1C80` builds arc 2 (`arc2_pos = pos`, `arc2_vel`, new drift with flag 0), and if `max_bounces <= bounce_count` `+0xD0 = launch_frame + tick + 1`; finally `vel = (pos - prev)*60` and `gp4b_to_world` (`v*100 + origin`, `w` lanes `*0`). Net crossing / let / hold are as in GP4 section 1.4 (not re-derived here, M).

## 5. Solver algorithms (exact; H, ported in `gp4b_ball_model.c`)

Notation: `B.tau` current flight time; every "bisection" is `mid = (hi + lo) * 0.5f`; `B.tau = mid` before the evaluation; constants: `0.1`, `5.1` (tau bracket),
`3.6`, `1/12.96 = 0x3D9E0652` (`K_KMH_SQ`: target `(speed_kmh)^2/12.96`), `0.01`, `1/60 = 0x3C888889`.
Common helpers: `fn_888AAEA8` (constants from T, a4, g, endpoints), `fn_888AAE00` (constants from tau and A), `fn_888AAB98` initial speed^2, `fn_888AAA70` bounce speed^2,
`fn_888AACB8` derivative, `fn_888AA968(B, tt)` apex height of arc 1 for flight time tt (uses `inv_T, T^2, a4^2, 1/T^2`, a log), `fn_888AB308` height at the net plane (bisection on the sign of x(t) over [0,tau] (or [tau,0] if P0.x <= 0), 4 steps per round, at most 375 rounds, stop when `|x| <= 1e-3` or bracket `< 1e-4`; **it reads E/tauA/g*a4*tau of the last AAE00 call, not of the current tau**).
The closed forms are the ones of GP4 1.2, now with the original `fmaf` structure (see the C file; it is the single source of truth).

### 5.1 DropTime primary `fn_888AB8D0` (`gp4b_solve_kind_time`)
```
g0 = node_eval(tpl)                 O.tau = B.tau = g0
if !planned:                        // commanded INITIAL speed
    min-tau search: 20 bisections on [0.1, 5.1], D = AACB8(B) > 0 ? hi=mid : lo=mid;   tau_min = (hi+lo)/2 ;  O.tau_min = tau_min
    target = (0 - speed_kmh)^2 * 1/12.96                   // the original computes sqrt(pool double 0.0) - speed; the double is 0.0 in the image
    if !(AAB98(B at tau_min) > target): 20 bisections on [0.1, tau_min], AAB98 < target ? hi=mid : lo=mid ; O.tau = (hi+lo)/2
    else O.tau = tau_min
if shot id != Wood(0x9CAFB633):     // net stage
    thr = (planned ? (radius_cm + net_height_cm) * 0.01 : aim_height) + 0.01
    AAE00; ht = AB308 ; O.raised = 0
    if ht < thr && planned:  O.raised = 1; lo = B.tau; hi = lo + 2.0; 20 bisections: ht > thr ? hi=mid : lo=mid (AAE00+AB308 each); O.tau = (hi+lo)/2
desired = O.tau
if tpl+0x14 == DropTime:   desired = node_eval(tpl+0xC) + O.tau
if tpl+0x14 == Apogee:     apex = AA968(B, B.tau); g = node_eval(tpl+0xC); B.tau = 5.1; target = g + apex;
                           20 bisections on [0.1, 5.1]: AA968(B, mid) > target ? hi=mid : lo=mid ; desired = (hi+lo)/2
(any other secondary kind: the original blends with uninitialised stack garbage: undefined, never produced by sane data; the port keeps tau)
if planned: w = clamp01(1 - B.blend_c0c); B.tau = O.tau + w * (desired - O.tau)   (separate mul and add)
            O.initial_kmh = sqrt(AAB98(B)) * 3.6 ;  O.tau_final = B.tau ; quantise ; O.f28 = AB308(B)
else:       O.initial_kmh = sqrt(AAB98(B))*3.6 ;  O.tau_final = O.tau ; quantise(B.tau) ; O.f28 = AB308(B)
quantise: n = 0; acc = 0.0f; x = B.tau; while (x >= 1/60) { x -= 1/60; n++; acc += 1/60 }  ->  B.tau = acc, B.bounce_tick = n
```
So `bounce_tick = floor(tau*60)` computed by repeated subtraction (float), and `tau` becomes `n` times `1/60` accumulated by repeated float addition.

### 5.2 Speed kinds `fn_888AC748` (AverageSpeed), `fn_888ACA68` (InitialSpeed), `fn_888ACDA8` (BounceSpeed) (`gp4b_solve_kind_speed`, differ only in the metric `m`: none = constant 0 / AAB98 / AAA70)
```
B.tau = 0.1;  O.has_min = (AACB8(B) < 0);  if !has_min return          // nothing else is written, B.tau stays 0.1
tau_min = 20-step bisection on [0.1, 5.1] (AACB8 > 0 ? hi=mid : lo=mid) ; O.tau_min = tau_min ; B.tau = tau_min
tgt = planned ? node_eval(tpl) : speed_kmh ;  target = (0 - tgt)^2 * 1/12.96
if !(m(B at tau_min) > target)  [AverageSpeed: target >= 0]:
        20 bisections on [0.1, tau_min]: m(B) >= target ? lo=mid : hi=mid ;  O.tau = (hi+lo)/2
else    O.tau = tau_min
thr = (planned ? (radius+net)*0.01 : aim_height) + 0.01 ; B.tau = O.tau ; AAE00 ; ht = AB308
if ht >= thr || !planned:  O.raised = 0 ; O.tau_raised = O.tau
else: lo = O.tau ; hi = tau_min ; B.tau = tau_min ; AAE00 ; ht = AB308 ; O.net_unreachable = 0
      if ht < thr: O.net_unreachable = 1 ; hi = tau_min + 5.0 ; B.tau = hi ; AAE00 ; ht = AB308
      spread = 1.0 ; round = 0
      while spread > 0.001: 4 x { mid = (hi+lo)/2 ; B.tau = mid ; AAE00 ; ht = AB308 ; (thr < ht) ? hi = B.tau : lo = B.tau }
                            if |lo - hi| < 1e-4 break ; spread = |ht - thr| ; if ++round >= 200 break
      O.raised = 1 ; O.tau_raised = (hi+lo)/2
O.metric_kmh = sqrt(m(B)) * 3.6 ;  O.f28 = AB308(B)
if planned: secondary stage (5.3) ; O.initial_kmh = sqrt(AAB98(B))*3.6 ; O.tau_final = B.tau
```
(all three end with `fn_888AC688`, only when planned).

### 5.3 Secondary stage `fn_888AC688` -> by `tpl+0x14` (after it, `fn_888AAEA8(B)` again)
`tauA = O.raised ? O.tau_raised : O.tau`, `w = clamp01(1 - B.blend_c0c)`; every variant ends `B.tau = quantised(tauA + w (tauB - tauA))`, `B.bounce_tick = n`.
* DropTime (`AB7B0`): no `has_min` test; `tauB = node_eval(tpl+0xC) + tauA`; `B.tau = tauA + (w*(tauB - tauA))` (not fused).
* all others first: `!O.has_min -> B.tau = 1.0, return`; `O.net_unreachable -> B.tau = O.tau_raised, return`; the final blend is `fmaf(w, tauB - tauA, tauA)`.
* InitialSpeed (`AC2B8`) / BounceSpeed (`AC4A0`): `m0 = m(tauA)`, `m1 = m(tau_min)`, `g = node_eval(tpl+0xC)`, `target = (sqrt(m0 * 12.96) - g)^2 / 12.96` (i.e. the curve is a speed delta in km/h, relative to the speed at tauA); `tauB = tau_min` unless `!(m1 > target)`, then 20 bisections on [tauA, tau_min]: `target > m(mid) ? hi=mid : lo=mid`.
* AverageSpeed (`AC100`): same with metric 0: `target = g^2/12.96`, `tauB` bisects toward tauA (compare with the constant 0).
* Apogee (`ABF10`): `limit = -apex(tauA) - g`; `tauB = tau_min` unless `!(-apex(tau_min) > limit)`, then 20 bisections: `limit > -apex(mid) ? hi=mid : lo=mid`.

### 5.4 Odd but real
* `AverageSpeed` does not evaluate any metric in this build (the loop compares a constant): with a solving target it converges to `tau ~ 0.1 s` (`0.1000001` observed); it is probably unused or a left-over.
* `DropTime` with `planned` skips the speed solve entirely: tau is the curve value (optionally raised for the net, blended with the secondary).
* `fn_888AB308` and the AB8D0 tail use the exponentials cached by the previous `fn_888AAE00`, which can belong to a different tau than `B.tau`; the port reproduces that exactly (call order matters).

## 6. Per-shot recipe (what a port needs)
Given template row, command (from/to in cm, row offset, blend, sign, `f4C`) and the ball constants (radius, a4, g, net height): run `gp4b_probe` (or only use the stored tau/tick),
then `gp4b_to_local`, `gp4b_launch`, then each tick `tick++`, `gp4b_step_flight`, `gp4b_to_world`. `src/xbox360/drafts/gp4b_ball_model.c` reproduces
launch speed, bounce tick, per-tick positions and velocities of arc 1 bit-exactly (validated, section 9); bounce response, net, let and hold are described but not re-derived (GP4 draft).

## 7. Who writes ball+0x4D0..0x4DC (negative result, reproducible)
Scanned the whole .text image (2,497,172 words from the split objects, `work/matching/split`) for stores (stw/stb/stfs/stfd/std/addi/li) with displacement 0x4D0..0x4DF:
* the ball-state constructor `fn_882734C8` (inside the `BallPrediction` object, `+0x60`) zeroes `+0x4D0/4D4/4D8/4DC/4E0/4E1` and the copy `fn_88272BC0` copies them; `fn_886A9050` (the 0x5A0 object ctor) zeroes them too;
* `fn_886B1BA0 +0x2178` stores `10` into `+0x4DC` of the live ball (`DebugConfig-object + 0x400`; the live ball is `World+0x28 object + 0x400`, size 0x540, `+0x530` enabled);
* no instruction stores `radius/a4/g` with a literal offset. They are set through a generic data path that writes by registered offset (property/XData loader; the module config readers use hashed attribute lookups, e.g. `fn_88627EC0` reads 0x290C4DBF/0x6F12B30C/0xC0A7B31A), so their numeric values need either the XData or a runtime dump of `ball+0x4D0..0x4DC`. The strings "gravity", "dragCoefficient", "radius" in the binary belong to Havok/ragdoll code, not to this model.
Plausible magnitudes used by the self-test: `T ~ 1`, `a4 ~ 1..3`, `g ~ 9.81` (k = T/a4 is the drag rate, 1/s).

## 8. Open items
* Numeric template/XData values and the writer of `radius/a4/g/max_bounces` (7).
* Row header `row+0x00..+0x17` and row stride; the 12-byte pointer entries at `tpl+0x18/+0x24/+0x30` (two words unknown); third word of the curve16 headers.
* `AverageSpeed` stub (5.4); the garbage-blend case of DropTime with an unsupported secondary kind.
* `vrsqrtefp128` (+1 Newton step) in `fn_889C0DC0`: the port uses `1/sqrtf`, validated within 3 ulp of the emulated original (the hardware estimate table is not modelled); the dot product order of `vmsum3fp128` is assumed. Positions after a shot launch inherit that tolerance only through `A` (<= 1e-6 relative).
* Bounce response `fn_889C1C80` uses `sincos`, a quaternion/matrix rotation (`fn_8825D450`, `fn_8864E310`, `fn_8864F7B8`) and `vrefp`; kept as in `gp4_ball_flight.c` (mathematical, not bit-exact); net/let/hold branches of `fn_889C1F70` likewise.
* The planner's stores of tau/tick into the command (`C+0x40/0x44`).

## 9. Validation (reproducible description)
Tools: `tools/fn_asm.py` (disassembly with relocations) and `tools/sym_info.py` of this repo (commit `71bcc9f`), Python 3.13.18, numpy 2.5.3, gcc 13.3.0 (`cc -std=c11 -Wall -Wextra -Werror`, also `-O2` and `-O3 -march=native`: identical self-test result because C11 mode disables FMA contraction).
Method (scratch tooling, not committed): (a) a mechanical translator turned each straight-line FP block of the original functions into C with `fmaf` for every `fmadds/fmsubs/fnmsubs` and the original operation order, (b) an instruction-level PowerPC emulator (scalar FP with single rounding and exact fused multiply-add, the VMX128 subset the functions use, `exp`/`log` hooked to the host libm) ran the ORIGINAL code on random inputs, (c) the C code and the emulated original were compared bit for bit.
Results (all bit-exact unless noted): leaf functions `fn_888AAEA8, AAE00, AAB98, AAA70, AACB8, AA968, AB308, AB0E0, AB220` (14 random states each); solver dispatch `fn_888AD0E8` over all primary x secondary kinds, planned/unplanned, node types const/curve20/table2d, Wood/other, with the leaf routines swapped for the C versions (about 1,800 random cases, 0 mismatches, every solver line executed per gcov, the only excluded combination is DropTime planned with an unsupported secondary kind = uninitialised stack); the probe `fn_889C2678` (55 cases, whole ball image incl. spin blend, P0/P1/origin, constants); launch `fn_889C19F0` (34 cases incl. mode flags, `+0xC8`, velocity vectors); per tick `fn_889C2818` before the first bounce including the bounce event itself and `+0xD0` (46 shots, every tick, whole ball image), bounce response stubbed; `fn_889C0DC0` (60 cases, flag 0/1) within 3 ulp (see 8).
Committed evidence: the golden vectors inside `gp4b_ball_model.c` (`-DGP4B_SELFTEST`: 8 solver cases from the emulated original, plus closed-form and launch/flight consistency checks):
```
cc -std=c11 -Wall -Wextra -Werror -DGP4B_SELFTEST src/xbox360/drafts/gp4b_ball_model.c -lm && ./a.out    # prints per-case OK and "SELFTEST PASSED"
```
Hash search: `zlib.crc32` of CamelCase words/pairs from a ~200-word ball/trajectory vocabulary; hits `DropTime`, `BounceSpeed`, `InitialSpeed`, `AverageSpeed`, `Apogee`.

## 10. Shot error model (outcome mode In / Out / Net / Let and the landing point)

Answer to the coordinator's request. Because the first bounce snaps to `P1` (section 4.3), everything is decided before the probe. Evidence: `fn_886807C0` (0x900 bytes, the only
place that writes the outcome mode; called once from the planner `fn_886AE528 +0xA08`), `fn_886AE528 +0xA38..+0xF4C` (consumer), `fn_88662C08`, `fn_88672130`, `fn_8866E318`,
`fn_8861E598`, `fn_8865AC08`. Confidence M-high: every instruction was read and the decision table below was derived by hand; it was NOT emulated (VMX-heavy), so treat the
numbers as exact but the byte flags `b50/b51` as partly unknown.

### 10.1 Names (H, zlib.crc32)
`In = 0xCA68AAEC`, `Out = 0x81A72B79`, `Net = 0xCAA7531F`, `Let = 0xC9238771` (the net-cord case; the ball then becomes `LetIn 0x8F903DFB` at launch),
timing/quality grades `Bad 0xBA667F1B`, `Normal 0x26296DD2`, `Good 0xCCB6E1AC`, `Medium 0xC1DF4081` (the last is only written to the match record `+0x320` by `fn_8866E128`); `0x280AE84D` = "no error / unclassified" (unnamed), `0x2C59FAEA` = second out-region class of `fn_88662C08` (unnamed).
The mode is stored in the shot record `+0x38/+0x3C`, in the player state `+0x714`, in `ball+0x2C` and `ball+0x434`.
(So GP4's "`ca68aaec` treated like Out" is `In`: `fn_889C0C70` gives it `{1,1,0}` only when launch and target are on the same side.)

### 10.2 The decision `fn_886807C0(out_mode*, rec, rec2, target*, PC, forced)`
Inputs: `PC = PlayerCtx`, `S = PC+0x74` (PlayerState), `target = (x, ., z)` in cm (x > 0 = opponent half), rolls `u = fn_8861E598(rng, lo, hi)`, `rng = PC+0x44 -> +0xB4`.
RNG (H): `s1 = rng+4, s2 = rng+8`; `t = (s1 >> 15) ^ s1; s2' = s2 * 0x10DCD; s1' = (t << 17) ^ t; v = s2' ^ s1'` (32-bit); `u = (float)v * 2^-32` clamped to <= 1 (pool+0xDC, +0x0); result `lo + u*(hi-lo)` (fused). The three rolls below are consecutive draws of U[0,1).
```
P   = clamp01(S.0x718 + S.0x564)                     // error probability (S.0x564 = additive modifier)
      [AI player and match state == 0x029EAAF4 ("point end"): P = DebugConfig.0x218 (= 0.0015 in the image) and S.0xD88/0xD8C = DebugConfig.0x210/0x214]
roll1, roll2 drawn; fn_8890E988(rec); roll3 drawn
G   = DebugConfig.0x784 && !match.0x329 && match.0x328            // net/let outcomes enabled (rule/mode gate; meaning of the two match bytes unknown)
C   = G && (roll3 < S.0x71C || S.0x572)                          // "Let" (net cord) outcome
A   = (roll1 < P) || S.0x56D || S.0x56E                          // an error happens
B   = (A && roll2 < S.0x720) || S.0x56E                          // the error is a net error (given A)
OUT = (|x| > xmax) || (z beyond zmax/zmin) || x < 0              // target outside the legal half court (bounds below)
(b50, b51) = bytes initialised to 1 and possibly cleared by fn_88671B10(rec, PC, &b50, &b51)   // not decoded; b50 = 0 forces Out, b51 = "an error may push the target out"
F1  = !C && A && B && G                                          -> mode Net
F2  = !F1 && ( !b50 || (!C && b51 && A) || OUT )                 -> mode Out
In  = !C && !F1 && !F2                                           -> mode In
else (C and !F2)                                                  -> mode Let
```
(S.0x56D / 0x56E / 0x572 are byte flags that force "error" / "net error" / "let": cheat or tuning switches; S.0x56E forces B regardless of A.)
Therefore, with all gates open and no forcing, per shot: `P(Let) = S.71C` (needs G, evaluated first); otherwise `P(Net) = P * S.720` (needs G), `P(Out by error) = P * (1 - S.720)` when `b51` (or `P` if `G` is off), `P(In) = 1 - P`; shots whose aim point is already outside are always Out. There is no dependence on the shot's power bucket, template or the incoming ball inside this function: **all of that must be folded into `S.0x718/0x564/0x71C/0x720` by whoever fills the PlayerState.** Those four floats and the three flags are only READ in the gameplay code (`fn_886807C0`, `fn_886AE528`, `fn_886B0490`, `fn_886B1608`, `fn_8866DF60`...); no instruction stores them with a literal offset, so they come from the data/loader path (same situation as ball `+0x4D0..`): tuning knob candidates for retuning are the per-player values loaded into `PlayerState+0x700..0x730` (`+0x718 error`, `+0x71C let`, `+0x720 net share`) and `+0x564`.

### 10.3 What each mode does to the planned point (consumer in `fn_886AE528 +0xA38`)
Court bounds `fn_8866E318(PC, serve, out[3])`, cm, enlarged by `2 * ball.radius_cm` (pool 2.0 * `ball+0x4D0`): `xmax = 1194.5` (serve box: `646.0`), `z in [-415.5, 415.5]` singles / `[-552.5, 552.5]` doubles (serve box: `[-4.0, 415.5]` or `[-415.5, 4.0]` by court side), so the "inside" test is a ball-diameter-wide tolerance.
* **In**: the target is clamped into the bounds on both axes and x is at least `75 cm` past the net (pool+0x604; for the other side `<= -75`, pool+0x610); then, when the shot is a normal groundstroke (`r20 != 0`), uniform dispersion is added: `dx ~ U[ball+0x4C0, ball+0x4C4]`, `dz ~ U[ball+0x4C8, ball+0x4CC]` (cm), `target += (dx, 0, dz)` if `target.x < 0` else `target -= (dx, 0, dz)` (mirrored by court side); then `planned = 1`, probe `fn_889C2678`. The four range floats are ball-block data (zero after construction, loaded like `+0x4D0..`). This is the only random landing dispersion of a normal "In" shot: the box shape is data, the player skill acts only through the error probability above.
* **Out**: if the aimed point is inside, `fn_88672130` pushes it to just outside the NEAREST line (nearer of the x overshoot and z overshoot; `+3.0 cm` margin, pool+0x4C) keeping the other coordinate; if it is already outside by more than 3 cm it stays. The class of the final point is then assigned by `fn_88662C08` (`Out 81A72B79` when the point is in the outer regions A, `2C59FAEA` in region B, else `280AE84D`), so a forced-out point can be classified "in". For non-forced calls a second branch (D5C..F4C) computes the nearest of three boundary distances; if it is `> 200 cm` (pool+0x614 = 40000 cm^2) the shot is demoted to `In` and clamped; otherwise the target is moved along `(target - base)` by `sqrt(dist^2) * U[0, 1.5...]` (roll with `lo = 0`, `hi = pool+0x364 = 200.0`) -- M. Then `planned = 1` and the normal probe with the new point.
* **Net**: `planned = 0`, `speed_kmh = ball+0x3CC` (the previous initial speed), `aim_height = S.0x750 * 0.01` (m) and the aim bisection `fn_889C29E8(S, B, f1 = cfg+0x130, O = +0x404)` finds the target whose net-plane height equals `aim_height` (so the ball hits the net below its top: `+0x124`); mode stays `Net` for the ball (`ball+0x2C`).
* **Let**: like Net but with `aim_height = S.0x754 * 0.01` and the ball mode set to `LetIn 0x8F903DFB` (`ball+0x2C`, `+0x434`, `PC.0x30` state), launch frame/blend as the planner (`0x30(rec)` into `+0x430`); the stepper's cord branch (GP4 1.4 step 5) then deflects the ball at the net.
* `+0x750 / +0x754` are written from `fn_889C1340(vec, ball, cfg+0x124)` (`vec.y`, cm): the net-crossing aim heights of the chosen target for a Net/Let outcome.

### 10.4 Timing grade (`Good / Medium / Bad`)
`fn_8865AC08(hash*)` is a pure lookup grade -> factor: `Bad 0xBA667F1B -> 0.25` (pool+0x29C), `Normal 0x26296DD2 -> 0.5`, `Good 0xCCB6E1AC -> 0.75` (pool+0x2A0), `0x703F56AE -> 1.0`, anything else (including `Medium`) `-> 0.0`.
`fn_886629C8` evaluates it for two grade hashes and stores the results at `swing_state + 0x66C + 0x12C / +0x130` (the per-swing "quality" floats; `+0x798`/`+0x79C` of that object are read back by `fn_886A84C0` / `fn_886A9678`). `fn_88682FE0` (animation state machine) compares the grade only to select animation tags (it is not part of the error roll). The link between these quality floats and `S.0x718/0x564` was NOT found (no literal store); `S.0x564` being an additive term in `P` is the natural place for a timing/fatigue/difficulty penalty.

### 10.5 Where to retune (summary)
1. `P = clamp01(S.718 + S.564)`: overall error rate (everything stat/timing/difficulty related must reach the game through these two floats, or through the debug-only `DebugConfig.0x218` at point end).
2. `S.720`: share of errors that are NET (needs `G`); `1 - S.720` are OUT. `S.71C`: Let probability (needs `G`).
3. Court tolerance `2*radius` and the line bounds (pool +0x140, +0x2C0, +0x2C4, +0x3FC, +0x400, +0x2BC, +0x3AC) define what "In" means; `75 cm` minimum depth after the net (pool+0x604/+0x610).
4. Dispersion of In shots: `ball+0x4C0..0x4CC` box; Out shots land `3 cm` outside the nearest line (no spread); Net shots hit at `S.750*0.01` m.
5. The template (`DropTime`, `InitialSpeed`, ...) only sets the flight (time/speed/apex) toward whatever point was chosen; it never adds error.
Open: writers of `S.0x560..0x574 / 0x700..0x738 / 0x750`, `b50/b51` (`fn_88671B10`), meaning of `G`'s three bytes, the demotion branch constants (M).
