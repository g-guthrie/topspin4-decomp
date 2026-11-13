# GP4 notes: PhysicEngine wrapper (WP4) and the game's own ball flight stepper

Module: Swing_DLL.xex, symbols.txt sha256 prefix ec79e191534b9b28, matching compiler MSVC 16.00.10224.00. All addresses are xex VAs.
Confidence: **H** disassembly read directly, **M** consistent/inferred detail, **L** guess. Drafts: `src/xbox360/drafts/gp4_ball_flight.c`,
`src/xbox360/drafts/gp4_physic_wrapper.c`; types `src/xbox360/gp4_types.h`. No function was matched (see section 6).

## 0. Headline

* **Ball flight is a closed-form (analytic) model, not Havok and not a numerical integrator.** `fn_889C2818` -> `fn_889C1F70`
  evaluates the ball position every 60 Hz tick from an exponential-drag solution with a spin "drift" vector and gravity. The same
  code runs the real ball and the prediction copies (`fn_886AD278`, GP3), so the reach prediction is exactly this model.
* **Havok (the `PhysicEngine` wrapper) never integrates or pushes the tennis ball**. It steps a world containing keyframed
  players/rackets/ragdolls and static scenery; the ball body is only a collision/contact-event source and a ray-cast detector.
  Contacts are published in `GameDB:/GameDB/Physic/EventQueue`. A port can use only the analytic stepper plus its own contact rules.

## 1. Ball flight model (all H unless noted)

### 1.1 Frames and units
Inside the stepper the ball is in a **local frame**: metres, seconds, origin = `ball+0x70`. `fn_889C1160` (to local, guarded by
`stepper+0x40`) does `v = (v - origin) * 0.01` for `+0x40` pos, `+0x60` prev pos, `+0x100` from, `+0x130` arc-2 pos and `v = v * 0.01`
for `+0x110` (to) and `+0x140` (arc-2 velocity); `fn_889C0FE8` is the inverse (`* 100 + origin`). The scale vectors `lbl_88D46390 = 0.01`, `lbl_88D463A0 = 100`
are set by `fn_889D22A8/fn_889D22D0`. `fn_889C0F70/fn_889C0EF8` apply the same scaling (no origin) to the launch command vectors `+0x340/+0x350`.
Axes: **x along the court, the net plane is x = 0; y up; z across**. The stepper object (`S`, vtable `lbl_880DCA74`, ctor `fn_889C1690`):
`S+0x1C = 60.0` ticks/s, `S+0x20 = 1/60`, `S+0x28` vector of ball pointers, `S+0x34/0x38` generator objects `G1/G2` (+4 = 1/60 s per tick, +8 = template table),
`S+0x3C` = shot-template table (data driven, filled by the module init `fn_889C28F0`), `S+0x40/0x41` frame flags, `S+0x42` (net bounce keeps spin when set).
Update slot `fn_889C28B0` steps every ball in `S+0x28`.

### 1.2 The equation
With `T = ball+0x08` (= template row +0x54), `a4 = ball+0x4D4`, `g = ball+0x4D8` (gravity, m/s^2), `A = ball+0x80` (drift vector, 1.3):

    k  = T / a4                          (drag rate, 1/s)           stored ball+0x158
    W  = A / T                           (drift velocity)           Weff = W - (0, g/k, 0)
    v' = -k (v - W) - g * yhat           (never integrated: solved exactly per axis)
    t  = (tick - tick_prev) / 60         (arc clock, tick_prev reset at every bounce / net event)

**Arc 1** (launch -> first bounce), boundary-value form, tau = `ball+0x00` flight time, `P0 = ball+0x100` (from), `P1 = ball+0x110` (to), `P1.y = 0` (ground; the launch height has the ball radius field `+0x4D0 * 0.01` subtracted, `fn_889C1AF8`):

    p(t) = P0 + (P1 - P0 - Weff*tau) * (1 - e^{-k t}) / (1 - e^{-k tau}) + Weff * t          (fn_888AB558)

(x,z: Weff = W; y: Weff.y = W.y - g/k and the y end condition is p.y(tau) = 0, `fn_888AB558` has no P1.y at all). Constants cached by `fn_888AAEA8`
(`+0x150 = 1/T, +0x154 = 1/a4, +0x158 = k, +0x15C = g*a4, +0x160 = 1/T^2, +0x164 = a4^2, +0x168 = T^2, +0x16C.. = scaled endpoints`) and `fn_888AAE00`
(`+0x180 = E = e^{-k tau}, +0x184 = 1/(E-1), +0x188..0x190 = tau*A, +0x194 = g*a4*tau`). The exact expression order is in the draft; it was extracted symbolically.
Launch velocity (`fn_888AB220`, stored `+0x500`): `v(0) = W + (P1 - P0 - Weff tau) k / (1 - E)`. Arrival velocity (`fn_888AB0E0`, `+0x510`) = derivative at t = tau; `fn_888AAB98` = |v(tau)|^2 (m/s)^2.

**Arc 2** (after a ground bounce or net hit), initial-value form, `p0 = ball+0x130`, `v0 = ball+0x140`:

    p(t) = p0 + (v0 - Weff) * (1 - e^{-k t}) / k + Weff * t                                  (fn_888AD1C8)

`fn_88565118` is the CRT `exp`. Everything is evaluated in float with the original operation order (see draft); there is no sub-stepping.

### 1.3 Spin ("drift") acceleration vector A = ball+0x80 (fn_889C0DC0, fn_889C1868)
The "spin" is three scalars, `+0x90 spin_a` (vertical: topspin/backspin lift), `+0x94 spin_b` (lateral: sidespin), `+0x98 spin_c` (along track), obtained per shot from the template by
`fn_889C1868`: each is `lerp(c_lo(x), c_hi(x), blend)` with `x = ball+0x344` (w of the command "from" vector) and `blend = ball+0x364` (command f_50, 0..1); the six curves live in the
template row at `+0x18` (self-relative pair nodes `{rel, type, rel, type}` at +0x18, +0x24, +0x30; type 0xF9F12A60 = 1-D curve evaluated by `fn_8817A688`, else a plain float).
Then `fn_889C0DC0(ball, flag)`: `d = flag ? (P0 - P1) : ball.vel(+0x140)`, `u = normalize(d)` (kept as is when |d| = 0, whole function is skipped when d == 0),
`c1 = u x (0,1,0) = (-u.z, 0, u.x)`, `c2 = c1 x u`, **A = u*spin_c + c1*(spin_b * sgn) + c2*spin_a**, `sgn = ball+0x368 ? -1 : +1` (sidespin sign / handedness flag). This is the Magnus-like term:
it is not computed from ball angular velocity; templates give steady-state drift speeds (m/s * T). (M: the opposite sign convention of `d` for flag 1 (P0-P1) vs flag 0 (velocity) is as decoded; its physical reason is not understood.)

### 1.4 Per-tick step `fn_889C1F70` (0x704)
1. to local frame; `pos_prev = pos`. `mode = ball+0x2C`; `is_let = mode in {LetIn 8f903dfb, LetOut 02315629}`.
2. **Hold** (`+0x28 > 0`, serve toss): `--hold; pos += ball+0xA0` (no physics); when it reaches 0 and bounce_count > 0, `tick_prev = tick`.
3. Else pick the arc: `!is_let`: arc 1 while bounce_count == 0, else arc 2. `is_let`: arc 1 while the ball is on the launch side of the net plane (sign of pos.x equals sign of `P0.x`), else arc 2.
4. **Bounce test**: before the first bounce (not let): bounce when `tick >= ball+0x04` (scheduled integer tick). Otherwise: when the ball is descending (`pos.y - prev.y <= 0`) and `pos.y < -1.19e-7`.
   On bounce: incoming velocity = analytic arrival velocity `fn_888AB0E0` (first bounce of a normal shot) else `(pos - prev) * 60`; `bounce_count++`, `tick_prev = tick`; first bounce: **position snaps to the planned landing point P1**;
   `fn_889C1C80(ball, v_in)` computes the outgoing velocity if v_in != 0.
5. **Net plane crossing** (`prev.x * pos.x < 0` and `flag31`): crossing point `prev + (pos-prev) * |prev.x|/(|prev.x|+|pos.x|)`; `hits = same_side(P0.x*P1.x > 0) ? !(pos.y*100 > ball+0x124 /*net height cm*/) : 1` (M: polarity of this test is as decoded,
   the usual shots have flag31 = 0 so it does not trigger); then `ball+0x130 = crossing`, `ball+0x140 = (pos-prev)*60`, `pos = crossing`, `flag34 = 1` and
   * flag32 (solid net) and not `S+0x42`: spin = 0, A recomputed (`fn_889C0DC0(.,1)`), **velocity *= 0.2 (pool+0x10C) and x negated**, `bounce_count++`, arc clock reset, hold = 0;
   * flag33 (let / net cord; modes LetIn/LetOut only): direction rotated by `ball+0x494` and `+0x498` degrees (pool+0x184 = pi/180), speed *= `1 - ball+0x49C`, spin *= `1 - ball+0x4A0`, `bounce_count++` ... (decoded structurally, M).
6. If an event happened and `ball+0x4DC <= bounce_count`: `ball+0xD0 = launch_frame + tick + 1` (frame at which the point is decided / ball dead).
7. `ball+0x4F0 = (pos - pos_prev) * 60`; back to the world frame.

`fn_889C0C70` (mode -> flags, `ts4_`-style helper): flags `+0x31` (check net crossing) / `+0x32` (solid) / `+0x33` (cord): Wood 9caf b633 and Net caa7531f -> {1,1,0}; LetIn/LetOut -> {1,0,1};
0x9ea301c2 / 0x5d25ed1d (live ball, GP3 rewrites LetIn/LetOut to these for predictions) -> {0,0,0}; Out 81a72b79 / ca68aaec -> {1,1,0} if `P1.x*P0.x > 0` else {0,0,0}; **any mode once bounce_count != 0 -> {1,1,0}**; other modes leave the flags unchanged.
(`fn_889C2818` itself, ball.enabled gate, new_shot launch, frozen = `+0x4E0`.) The caller of `fn_889C0C70` was not identified (launch path, `fn_889C0DC0`-adjacent; M).

### 1.5 Bounce response `fn_889C1C80` (restitution / friction / spin change)
Given incoming v (local, m/s): reflect vertical (`v.y = -v.y`); rotation axis `ax = v x up` if `|dot(v/|v|, up)| < 0.99999` else (0,0,1); elevation `theta = atan2(v.y, v.x)` (folded to <= pi/2: `theta = pi - theta`);
template curves (16-byte-key piecewise linear tables, `fn_881899D8`): `c40(spin_a)`, `c4C(spin_a)`, `c58(theta)`, `c64(spin_b)` at template row `+0x40/+0x4C/+0x58/+0x64`:

    v      *= 1 - c40(spin_a)                               // speed loss ("restitution + friction"), per surface/shot template, not a global constant
    v       = rotate(v, ax, wrap(c58(theta) - theta) * |5 * spin_a|)   // elevation moved toward the template's outgoing angle, weight |5 spin_a| (pool+0x1E0 = 5.0)
    v       = rotate(v, up, c64(spin_b))                    // yaw kick from sidespin
    spin_a, spin_b *= 1 - c4C(spin_a);  spin_c *= same  (or spin_b = spin_c = 0 if ball+0x4E1)
    arc2_pos = pos ; arc2_vel = v ; A = spin_accel(flag 0)

So **restitution/friction/spin transfer are data in the shot template**, not constants in code. There is no surface-dependent logic in the stepper; there is a single ground plane y = 0.

### 1.6 Launch (`fn_889C19F0`, same body as `fn_889C1AF8` and `fn_889C2678` (probe))
`tpl = S.table + ball.template_index(+0x360) + 0x18`; `T = tpl[+0x54]`; `P0 = cmd_from*0.01` with `P0.y -= ball+0x4D0*0.01`; `P1 = cmd_to*0.01`; `tau = ball+0x00`; `ball+0x0C = +0x430`, `+0x10 = +0x364`;
spin blend (1.3) -> `A`; `fn_888AD0E8` (kind switch on `tpl+0x08`: 0x5D90675B -> `fn_888AB8D0`, 0x2DB3EB6F -> `fn_888AC748`, 0x50B89452 -> `fn_888ACDA8`, 0xC1965E5C -> `fn_888ACA68`; each first runs `fn_888AAEA8`)
solves the flight time `tau` (`ball+0x00`) by **bisection** (20 iterations, bracket 0.1..5.1 s from pool `+0x2AC/+0x68C`; `fn_888AB6C8` gives a template-curve first guess from the horizontal distance in cm):
`fn_888AB8D0` finds `tau` with minimum arrival speed (derivative `fn_888AACB8` > 0 -> upper half), then if the minimum speed is below the commanded speed `ball+0x370` (km/h; `/3.6`, `pool+0x30C = 1/12.96`) it bisects again for `|v(tau)|^2 = (speed/3.6)^2`
(so **the shot command's speed is a km/h arrival speed**). Then `fn_888AAEA8`, `fn_888AAE00`, launch velocity `fn_888AB220 -> +0x500`, arrival velocity `fn_888AB0E0 -> +0x510`,
`ball+0xC8 = launch_frame + (int)(60 * tau)` (frame the ball lands). The other three kinds were not decoded in detail (same structure: bisection over tau with `fn_888AAB98`/`fn_888AACB8`).
`fn_889C29E8` (10-step bisection over the target point `ball+0x350` between two bracket vectors using `fn_889C2678` as a probe until the probe's field `+0x28` is within 0.01 of `ball+0x36C`) is an **aiming solver** used when a shot is requested by landing depth.

### 1.7 What is data
Shot template table (`S+0x3C`, rows `table + template_index`; fields: `+0x08` kind hash, `+0x18..` spin curve pairs, `+0x40/+0x4C/+0x58/+0x64` bounce curves, `+0x54` T),
the drag/gravity pair `ball+0x4D4/0x4D8` and `ball+0x4D0` (writer not located; initialised with the ball state, not by the launch path; M), net height `ball+0x124`, net-cord parameters
`ball+0x494..0x4A0` (from the command), `ball+0x4DC` (max bounces). Gameplay-side derived values: `ball+0x4D0..0x4DC` live in the 0x540 ball state that GP3 copies for predictions.
Not found: the numeric values of the template rows (they are in the game data; a recorded `Gp3BallState` + template dump would pin them).

## 2. PhysicEngine wrapper over Havok (0x88878000-0x88882000)

(Details and pseudo-code in `drafts/gp4_physic_wrapper.c`.)
* Registered classes: `CPhysicEngineManager` (vtable 880DF824: slot1 `fn_8887C108` init(cfg), slot2 `fn_8887E5F8` update), `CPhysicDataLoader` (vtable 880DF8B0 area: Init `fn_88880440`, Exit `fn_8887E8A0`),
  `CPhysicEngineCommandProcessor` (vtable 880DF878; `fn_8887D240` builds the keyframed bone set, `fn_8887AB50` / `fn_8887A640` per-step bone keyframing, `fn_88879458/688/878` ragdoll constraint tuning, `fn_888792F8/5F8`).
  The module shell CPhysicEngine (`fn_8887E4A8`) registers these three node types in Init (hashes of the three names).
* **World**: `hkpWorldCinfo` from the 0x30-byte config record (key 0x56931990): gravity xyz (+0x00), config ints/floats at +0x0C/+0x10/+0x18/+0x1C/+0x20; manager fields `+0x04 = cfg+0x24` (cm per metre, default 100),
  `+0x08 = cfg+0x14` substeps (default 1), `+0x0C = cfg+0x28` timestep (default 0.016 s), `+0x14 = cfg+0x2C`. **Per update: `substeps` calls of `hkpWorld::stepDeltaTime(timestep / substeps)`** (`fn_8846B398`), skipped in game state "Pause" (0x165BBDE9).
* **Collision filter** (`fn_8887B148`): hkpGroupFilter, layers 1..31 mutually disabled then selectively enabled: pairs (1,2) (7,2) (5,2) (1,3) (7,3) (1,4) (7,4) [skipped for mode 0x2B05E119], (7,7) (7,1), (2,2) [skipped for 0x01505C7E], (2,6) (6,4) (11,12) (13,14) (15,16) (17,18).
  Layers by object type hash (assigned when the .hkx filterInfo is 1): Player 9fb57f53 -> 6, Ball d400e765 -> 2, Standalone 18c45490 -> 7, f61f38cf -> 5, Environment c0ba51f5 and dfa2aff1 -> 1;
  an *active* ball is switched to layer 3 (collides with 1 and 7), an inactive one to layer 8 (nothing).
* **Ball object**: motion type 6 (keyframed) when inactive (and 1 dynamic when active, quality saved/restored), max linear velocity set to 100000 while inactive, 60-tick re-enable timer; a swept ray (`BallNPlus1 -> BallNPlus2` positions, filter layer 4) sets FrameSynchro `BallDetectCollision`.
  Object radius override `rec+0x58`. **No force, impulse, drag, Magnus or spin is applied to the ball by this code** (no applyLinearImpulse/setLinearVelocity on the ball except the debug launcher `fn_88881048`, "Ball%02d").
* **Keyframing** (`fn_8887B6D0`, `fn_8887AB50`): `hkpKeyFrameUtility::applyHardKeyFrame(pos/100, quat, 1/timestep, body)`; Havok -> game read-back `fn_8887DCF0` writes position*100 and rotation to FrameSynchro.
* **Contacts -> events**: wrapper records `{idA,idB,speedA,speedB,typeA,typeB,u44A,u44B, contact points (cm)}` (`fn_88881B20`/`fn_88880750`), queued by `fn_8887C748` into `GameDB:/GameDB/Physic/EventQueue` unless both types are Environment;
  `fn_88881B20` forwards {Standalone, Environment} pairs, `fn_8887CB40` any pair. Ground/Net/Let kinds used by gp5's sound layer therefore come from the object-type pair (data), consistent with GP5.
* **Data**: `Physics\Physics.hkx` (Havok packfile; shapes, materials, friction/restitution/damping, ragdolls "Ragdoll_*"), `Physics\Physics.bin` (0x5C-byte object records and the 0x30-byte world config); loaders `fn_88880B88`, `fn_888807E8` (ragdolls),
  file-name helper `fn_88958D10`; `fn_88879098`/`fn_888791E8` are Havok log shims only.

## 3. Ball state fields confirmed/extended (offsets, gp3 `Gp3BallState` extended in `gp4_types.h`)
`+0x00 tau (s)`, `+0x04 bounce tick (int)`, `+0x08 T`, `+0x14 bounce_count`, `+0x18 tick`, `+0x1C arc clock origin tick`, `+0x28 hold ticks`, `+0x2C mode`, `+0x31..+0x34 flags`, `+0x40/+0x60 pos/prev`, `+0x70 origin`, `+0x80 A`, `+0x90..+0x98 spin_a/b/c`,
`+0xA0 hold delta`, `+0x100/+0x110 P0/P1`, `+0x124 net height (cm)`, `+0x130/+0x140 arc-2 start`, `+0x150..+0x194` closed-form constants, `+0x340/+0x350 command from/to`, `+0x344 curve argument`, `+0x360 template index`, `+0x364 blend`,
`+0x368 sidespin sign flag`, `+0x370 speed km/h`, `+0x430/+0x364/+0x36C`, `+0x494..+0x4A0 net cord`, `+0x4D0 radius?`, `+0x4D4 a4`, `+0x4D8 g`, `+0x4DC max bounces`, `+0x4E0 frozen`, `+0x4E1 no sidespin`, `+0x4F0 velocity (per s)`, `+0x500/+0x510 launch / arrival velocity`, `+0x530 enabled`.

## 4. Reproducing
* `python3 tools/fn_asm.py fn_889C1F70` (and the other names above).
* Closed forms: a small symbolic executor over the scalar FP instructions was used (scratch, not committed): `symex.py fn_888AB558 r3=G r4=B` reproduces the expressions of 1.2; the four functions it covered:
  `fn_888AB558`, `fn_888AD1C8`, `fn_888AB220`, `fn_888AB0E0`, `fn_888AAB98`, `fn_888AACB8`.
* Constants: `python3 tools/sym_info.py data 0x880D0F70 0xA70` (pool: +0 = 1.0, +0x20 = 100, +0x38 = -1, +0xE0 = 1/60, +0x15C = 60, +0x1BC = 0.01, +0x10C = 0.2, +0x1E0 = 5, +0x2AC = 0.1, +0x68C = 5.1, +0x30C = 0.0771605 (1/3.6^2)), `0x880FCAD0` (0.01 x3), `0x88001AF0` (0,1,0,0).
* Name hashes: `python3 -c "import zlib;print(hex(zlib.crc32(b'Ball')))"` -> d400e765; Player 9fb57f53; Environment c0ba51f5; Standalone 18c45490; Normal 26296dd2; Pause 165bbde9; X/Y/Z/Position/Rotation for the FrameSynchro property ids.

## 5. Caveats / open items
* The kind routines `fn_888AC748`, `fn_888ACA68`, `fn_888ACDA8` (and the second half of `fn_888AB8D0`) are only characterised, not transcribed.
* The writer of `ball+0x4D0..0x4DC` (radius?, a4, g, max bounces) and of the 0x540 default ball state was not found by instruction grep (probably a vector store / struct copy from XData).
* Template table loading (`S+0x3C`) and the real numbers are data; "Out" is only a mode flag here, the in/out decision for scoring is made elsewhere (landing-zone stats, GP1).
* Net hit test polarity (`pos.y*100 > +0x124`) and the sign convention of `fn_889C0DC0(flag 1)` are as decoded but not physically explained.

## 6. Matching status
`fn_889C0C70` came to 0x10C bytes vs 0x120 (near miss; the original shares tail blocks between the Out case and the solid/let cases): `src/xbox360/drafts/gp4_ball_mode_flags_nearmiss.c`.
All other ball-stepper functions are VMX128 heavy; no spec JSON was written because nothing matched.
