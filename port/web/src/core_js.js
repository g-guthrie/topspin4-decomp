// JS FALLBACK ball model.  This is NOT ts4core: it is a plain double-precision JavaScript transcription of the
// documented formulas (docs/gameplay/gp4.md 1.2-1.4, docs/gameplay/gp4b.md section 5, reference C
// src/xbox360/drafts/gp4b_ball_model.c and gp4_ball_flight.c).  It is used only when work/port/ts4core.wasm is
// absent, and the UI labels it as such.  Differences from the game / from ts4core, on purpose:
//   * double precision and Math.exp, not the original float operation order and soft libm (no bit-exactness);
//   * the net-plane height (gp4b "AB308") is found by bisection on the arc, and the apex (AA968) analytically;
//   * the tick loop covers arc 1, the ground bounce response, the solid-net response and the second bounce only
//     (no let / net-cord deflection, no hold/serve toss, no wood/ball-mode special cases).
// Inputs and outputs use the same structures as ts4core.h (Ts4ShotIn / Ts4ShotOut), in centimetres (positions) and
// m/s (velocities), so the two backends are interchangeable (see core.js).

import { evalValue, evalCurve16 } from "./curves.js";

export const MODE = { IN: 0xCA68AAEC, OUT: 0x81A72B79, NET: 0xCAA7531F, LET_IN: 0x8F903DFB };
const DT = 1 / 60;
const NET_RESTITUTION = 0.2;          // pool+0x10C
const SPIN_WEIGHT = 5.0;              // pool+0x1E0
const AXIS_COS = 0.99999;             // pool+0x490
const GROUND_EPS = -1.1920929e-7;     // pool+0x784

const sub = (a, b) => [a[0] - b[0], a[1] - b[1], a[2] - b[2]];
const add = (a, b) => [a[0] + b[0], a[1] + b[1], a[2] + b[2]];
const mul = (a, s) => [a[0] * s, a[1] * s, a[2] * s];
const dot = (a, b) => a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
const cross = (a, b) => [a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]];
const len = (a) => Math.sqrt(dot(a, a));
const clamp01 = (v) => Math.min(Math.max(v, 0), 1);

function rotateAbout(v, axis, angle) {            // Rodrigues
  const l = len(axis);
  if (l === 0 || angle === 0) return v;
  const k = mul(axis, 1 / l), c = Math.cos(angle), s = Math.sin(angle);
  return add(add(mul(v, c), mul(cross(k, v), s)), mul(k, dot(k, v) * (1 - c)));
}
function wrapAngle(a) {
  while (a > Math.PI) a -= 2 * Math.PI;
  while (a <= -Math.PI) a += 2 * Math.PI;
  return a;
}

export class JsBallModel {
  // rows: shots.json "rows"; ball: shots.json "ball" {radius_cm, a4, g, max_bounces, net_height_cm}
  constructor(rows, ball) {
    this.rows = rows;
    this.ball = ball;
    this.name = "JS fallback (documented formulas, not ts4core)";
  }

  templateCount() { return this.rows.filter((r) => r.file === "Settings.bin").length; }

  // ---- shot setup -------------------------------------------------------------------------------------------
  _setup(inp) {
    const row = this.rows.filter((r) => r.file === "Settings.bin")[inp.row];
    if (!row) throw new Error("no template row " + inp.row);
    const b = this.ball, rad = b.radius_cm * 0.01;
    const P0 = [inp.from[0] * 0.01, inp.from[1] * 0.01 - rad, inp.from[2] * 0.01];
    const P1 = [inp.to[0] * 0.01, inp.to[1] * 0.01, inp.to[2] * 0.01];
    const S = { row, inp, P0, P1, T: row.T, a4: b.a4, g: b.g, rad, hit_y: inp.from[1] * 0.01 };
    S.k = S.T / S.a4;
    const blend = inp.spin_blend ?? 0.5;
    const el = (pair) => {
      const lo = evalValue(pair.lo, S.hit_y), hi = evalValue(pair.hi, S.hit_y);
      return lo + (hi - lo) * blend;
    };
    S.spin = [el(row.spin.a), el(row.spin.b), el(row.spin.c)];       // [spin_a, spin_b, spin_c]
    S.sgn = inp.left_handed ? -1 : 1;
    S.A = this._drift(S, sub(P0, P1));
    return S;
  }

  // fn_889C0DC0: A = u*spin_c + c1*(spin_b*sgn) + c2*spin_a; u = normalised d, c1 = u x up, c2 = c1 x u
  _drift(S, d) {
    if (d[0] === 0 && d[1] === 0 && d[2] === 0) return S.A || [0, 0, 0];
    const u = mul(d, 1 / len(d));
    const c1 = cross(u, [0, 1, 0]), c2 = cross(c1, u);
    const [sa, sb, sc] = S.spin;
    return add(add(mul(u, sc), mul(c1, sb * S.sgn)), mul(c2, sa));
  }

  // Effective drift velocity W - (0, g/k, 0), A/T - g/k
  _weff(S, A) { return [A[0] / S.T, A[1] / S.T - S.g / S.k, A[2] / S.T]; }

  // ---- arc 1 (launch -> first bounce), boundary-value form (fn_888AB558, fn_888AB220, fn_888AB0E0) -----------------
  _arc1(S, tau) {
    const k = S.k, E = Math.exp(-k * tau), W = this._weff(S, S.A);
    const end = [S.P1[0], 0, S.P1[2]];                       // y ends on the ground (local y = 0)
    const C = sub(sub(end, S.P0), mul(W, tau));
    const inv = 1 / (1 - E);
    return {
      tau, E, W, C,
      pos: (t) => add(add(S.P0, mul(C, (1 - Math.exp(-k * t)) * inv)), mul(W, t)),
      vel: (t) => add(W, mul(C, k * Math.exp(-k * t) * inv)),
    };
  }
  _speed2Initial(S, tau) { const v = this._arc1(S, tau).vel(0); return dot(v, v); }
  _speed2Arrival(S, tau) { const a = this._arc1(S, tau), v = a.vel(tau); return dot(v, v); }
  _dInitial(S, tau) { const h = 1e-5; return (this._speed2Initial(S, tau + h) - this._speed2Initial(S, tau - h)) / (2 * h); }

  // local height of the arc at the net plane x = 0 (gp4b AB308); Infinity when the arc does not cross it
  _netHeight(S, tau) {
    const a = this._arc1(S, tau);
    const x = (t) => a.pos(t)[0];
    let lo = 0, hi = tau;
    const s0 = Math.sign(x(0)), s1 = Math.sign(x(tau));
    if (s0 === 0) return a.pos(0)[1];
    if (s0 === s1) return Infinity;
    for (let i = 0; i < 60; i++) {
      const mid = (lo + hi) / 2;
      if (Math.sign(x(mid)) === s0) lo = mid; else hi = mid;
    }
    return a.pos((lo + hi) / 2)[1];
  }

  // apex height of arc 1 (gp4b AA968)
  _apex(S, tau) {
    const a = this._arc1(S, tau), k = S.k;
    let best = Math.max(a.pos(0)[1], a.pos(tau)[1]);
    const r = -a.W[1] * (1 - a.E) / (a.C[1] * k);            // e^{-k t*} where v_y = 0
    if (r > 0 && r <= 1) {
      const ts = -Math.log(r) / k;
      if (ts > 0 && ts < tau) best = Math.max(best, a.pos(ts)[1]);
    }
    return best;
  }

  _bisect(lo, hi, n, pred) {            // pred(mid) true -> hi = mid else lo = mid
    for (let i = 0; i < n; i++) { const mid = (lo + hi) * 0.5; if (pred(mid)) hi = mid; else lo = mid; }
    return (lo + hi) * 0.5;
  }

  _quantise(tau) { let n = 0, x = tau; while (x >= DT) { x -= DT; n++; } return { tau: n * DT, tick: n }; }

  // ---- the kind solvers (gp4b 5.1-5.3) --------------------------------------------------------------------------
  _solve(S) {
    const { row, inp } = S;
    const planned = inp.planned !== 0;
    const dcm = Math.hypot(S.P1[0] - S.P0[0], S.P1[2] - S.P0[2]) * 100, ycm = S.P0[1] * 100;
    const ev = (v) => evalValue(v, dcm, ycm);
    const O = { raised: 0, netUnreachable: 0, hasMin: true };
    const f4c = inp.f4c ?? 0;
    const w = clamp01(1 - f4c);
    const netCm = this.ball.net_height_cm;
    const thr = (planned ? (this.ball.radius_cm + netCm) * 0.01 : (inp.aim_height_m ?? 0)) + 0.01;
    const kind = row.kind;
    let tauA, desired;
    const speedKind = kind === "InitialSpeed" || kind === "BounceSpeed" || kind === "AverageSpeed" || !planned;
    const metric = kind === "BounceSpeed" ? (t) => this._speed2Arrival(S, t) : (t) => this._speed2Initial(S, t);

    if (!speedKind) {                                         // DropTime primary: tau is the curve value
      let tau = ev(row.primary);
      const wood = false;
      if (!wood && planned) {
        const ht = this._netHeight(S, tau);
        if (ht < thr) { O.raised = 1; tau = this._bisect(tau, tau + 2, 20, (m) => this._netHeight(S, m) > thr); }
      }
      O.tau = tauA = tau;
    } else {
      const kmh = planned ? ev(row.primary) : inp.speed_kmh;
      const target = kmh * kmh / 12.96;
      O.hasMin = this._dInitial(S, 0.1) < 0;
      if (!O.hasMin) return { ...O, tau: 1.0, final: this._quantise(1.0), planned };
      const tauMin = this._bisect(0.1, 5.1, 20, (m) => this._dInitial(S, m) > 0);
      O.tauMin = tauMin;
      let tau;
      if (!(metric(tauMin) > target)) {
        tau = this._bisect(0.1, tauMin, 20, (m) => !(metric(m) >= target));   // m>=target -> lo = mid
      } else tau = tauMin;
      O.tau = tau;
      let tauR = tau;
      if (planned && !(this._netHeight(S, tau) >= thr)) {
        let lo = tau, hi = tauMin;
        if (this._netHeight(S, hi) < thr) { O.netUnreachable = 1; hi = tauMin + 5; }
        for (let i = 0; i < 60; i++) { const mid = (lo + hi) / 2; if (thr < this._netHeight(S, mid)) hi = mid; else lo = mid; }
        O.raised = 1;
        tauR = (lo + hi) / 2;
      }
      tauA = tauR;
      if (!planned) return { ...O, tau: O.tau, final: this._quantise(O.tau), planned };
    }
    // secondary stage (gp4b 5.3)
    const sk = row.secondary_kind;
    if (O.netUnreachable) desired = tauA;
    else if (sk === "DropTime") desired = ev(row.secondary) + tauA;
    else if (sk === "Apogee") {
      const gv = ev(row.secondary), limit = -this._apex(S, tauA) - gv, tauMin = O.tauMin ?? 5.1;
      desired = this._apexSolve(S, tauA, tauMin, limit);
    } else if (sk === "InitialSpeed" || sk === "BounceSpeed") {
      const m = sk === "BounceSpeed" ? (t) => this._speed2Arrival(S, t) : (t) => this._speed2Initial(S, t);
      const tauMin = O.tauMin ?? this._bisect(0.1, 5.1, 20, (x) => this._dInitial(S, x) > 0);
      const m0 = m(tauA), m1 = m(tauMin), g = ev(row.secondary);
      const target = Math.pow(Math.sqrt(m0 * 12.96) - g, 2) / 12.96;
      desired = !(m1 > target) ? this._bisect(tauA, tauMin, 20, (x) => target > m(x)) : tauMin;
    } else desired = tauA;
    const tauB = tauA + w * (desired - tauA);
    return { ...O, tau: O.tau, tauA, final: this._quantise(tauB), planned };
  }

  _apexSolve(S, tauA, tauMin, limit) {
    // gp4b ABF10: tauB = tau_min unless -apex(tau_min) <= limit, then bisect on [tauA, tau_min]
    if (!(-this._apex(S, tauMin) > limit)) return this._bisect(tauA, tauMin, 20, (x) => limit > -this._apex(S, x));
    return tauMin;
  }

  // ---- public API (mirrors ts4_shot_probe / ts4_shot_trace) ---------------------------------------------------------
  probe(inp) {
    const S = this._setup(inp);
    const sol = this._solve(S);
    const tau = sol.final.tau;
    const a = this._arc1(S, tau);
    return {
      tau, bounce_tick: sol.final.tick,
      initial_kmh: Math.sqrt(dot(a.vel(0), a.vel(0))) * 3.6,
      net_height_m: this._netHeight(S, tau),
      raised: sol.raised, net_unreachable: sol.netUnreachable,
      launch_vel: a.vel(0), arrive_vel: a.vel(tau),
    };
  }

  // returns {points: Float32Array(3n) in cm (world: x along court, y up, z across), events, info}
  trace(inp, maxTicks = 420, opts = {}) {
    const S = this._setup(inp);
    const sol = this._solve(S);
    const tau = sol.final.tau, bounceTick = sol.final.tick;
    const a1 = this._arc1(S, tau);
    const rad = this.ball.radius_cm;
    const netCm = this.ball.net_height_cm;
    const stopAfter = opts.stopAfterEvents ?? 2;
    const mode = inp.mode ?? MODE.IN;
    const sameSide = S.P0[0] * S.P1[0] > 0;
    let netCheck = mode === MODE.NET || mode === MODE.LET_IN ? true : sameSide;
    const toWorld = (p) => [p[0] * 100, p[1] * 100 + rad, p[2] * 100];
    const pts = [toWorld(S.P0)];
    const events = [];
    let pos = S.P0.slice(), bounces = 0, tickPrev = 0;
    let arc2 = null;
    const spin = S.spin.slice();
    let A = S.A;

    const arc2Pos = (n) => {
      const t = n * DT, W = this._weff(S, A), k = S.k;
      const f = (1 - Math.exp(-k * t)) / k;
      return add(add(arc2.p0, mul(sub(arc2.v0, W), f)), mul(W, t));
    };
    const bounceResponse = (vin) => {
      let v = [vin[0], -vin[1], vin[2]];
      let axis = [0, 0, 1];
      const l = len(v);
      if (l > 0 && Math.abs(v[1] / l) < AXIS_COS) axis = cross(v, [0, 1, 0]);
      let theta = Math.atan2(v[1], v[0]);
      if (theta > Math.PI / 2) theta = Math.PI - theta;
      const sf = 1 - evalCurve16(S.row.bounce.speed_loss, spin[0]);
      const w = Math.abs(spin[0] * SPIN_WEIGHT);
      const delta = wrapAngle(evalCurve16(S.row.bounce.out_elevation, theta) - theta);
      const yaw = evalCurve16(S.row.bounce.yaw_kick, spin[1]);
      v = mul(v, sf);
      v = rotateAbout(v, axis, delta * w);
      v = rotateAbout(v, [0, 1, 0], yaw);
      const decay = 1 - evalCurve16(S.row.bounce.spin_decay, spin[0]);
      spin[0] *= decay; spin[1] *= decay; spin[2] *= decay;
      return v;
    };

    for (let tick = 1; tick <= maxTicks; tick++) {
      const prev = pos;
      let ev = null;
      pos = bounces === 0 ? a1.pos((tick - tickPrev) * DT) : arc2Pos(tick - tickPrev);
      const first = bounces === 0;
      const bounceNow = first ? tick >= bounceTick : (pos[1] - prev[1] <= 0 && pos[1] < GROUND_EPS);
      if (bounceNow) {
        const vin = first ? a1.vel(tau) : mul(sub(pos, prev), 60);
        bounces++; tickPrev = tick;
        pos = first ? [S.P1[0], 0, S.P1[2]] : [pos[0], 0, pos[2]];
        const vout = bounceResponse(vin);
        A = this._drift({ ...S, A, spin }, [vout[0], 0, vout[2]]);
        arc2 = { p0: pos, v0: vout };
        ev = { type: "bounce", tick, pos: toWorld(pos), count: bounces };
        netCheck = true;
      } else if (prev[0] * pos[0] < 0 && netCheck) {
        const frac = Math.abs(prev[0]) / (Math.abs(prev[0]) + Math.abs(pos[0]));
        const hits = sameSide ? !(pos[1] * 100 > netCm) : true;
        if (hits) {
          const cross_ = add(prev, mul(sub(pos, prev), frac)), vel = mul(sub(pos, prev), 60);
          spin[0] = spin[1] = spin[2] = 0;
          A = this._drift({ ...S, A, spin }, sub(S.P0, S.P1));
          const v = mul(vel, NET_RESTITUTION); v[0] = -v[0];
          pos = cross_;
          arc2 = { p0: pos, v0: v };
          bounces++; tickPrev = tick;
          ev = { type: "net", tick, pos: toWorld(pos), count: bounces };
        }
      }
      pts.push(toWorld(pos));
      if (ev) {
        events.push(ev);
        if (events.length >= stopAfter) break;
      }
    }
    const out = new Float32Array(pts.length * 3);
    pts.forEach((p, i) => { out[3 * i] = p[0]; out[3 * i + 1] = p[1]; out[3 * i + 2] = p[2]; });
    return { points: out, events, info: this.probe(inp) };
  }
}
