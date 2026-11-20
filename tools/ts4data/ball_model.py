#!/usr/bin/env python3
"""Ball flight model of Top Spin 4 (Xbox 360) in plain Python (standard library only).

A double-precision port of ref/gameplay/ball.c (spec docs/gameplay/ball-physics.md): launch solve
(kind routines DropTime / InitialSpeed / BounceSpeed / AverageSpeed + secondary stage), closed-form
flight, first bounce response. It works on the decoded rows of tools/ts4data/templates.py and is used to
write the per-shot trajectory table. Not bit-exact (the bit-exact model is src/xbox360/drafts/gp4b_ball_model.c).

Units: input points in world cm (x along the court, net at x = 0, y up, z across); internally local
metres with the origin one ball radius above the ground.
"""
from __future__ import annotations

import math

TAU_LO, TAU_HI = 0.1, 5.1
DT = 1.0 / 60.0
KMH = 3.6


def _eval_value(templates, val, a, b, mode):
    return templates.eval_value(val, a, b, mode)


class Ball:
    """State of one planned shot (the subset of the 0x540-byte ball block the model needs)."""

    def __init__(self, T, a4=0.06, g=9.81, radius_cm=4.0, net_cm=91.4):
        self.T, self.a4, self.g, self.radius_cm, self.net_cm = T, a4, g, radius_cm, net_cm
        self.k = T / a4
        self.A = [0.0, 0.0, 0.0]
        self.P0 = [0.0, 0.0, 0.0]
        self.P1 = [0.0, 0.0, 0.0]
        self.tau = 0.0
        self.tick = 0
        self.planned = True
        self.speed_kmh = 0.0
        self.aim_height = 0.0
        self.sec_weight = 1.0
        self.spin = [0.0, 0.0, 0.0]  # spin_a (vertical), spin_b (lateral), spin_c (along track)
        self.sidespin_neg = False
        self.wood = False

    # ---------------------------------------------------------------- closed forms (fn_888AB558 family)
    def consts(self, tau):
        k = self.k
        E = math.exp(-k * tau)
        W = [a / self.T for a in self.A]
        Weff = [W[0], W[1] - self.g / k, W[2]]
        C = [((0.0 if i == 1 else self.P1[i]) - self.P0[i] - Weff[i] * tau) / (1.0 - E) for i in range(3)]
        return k, E, Weff, C

    def pos1(self, t, tau=None):
        k, E, Weff, C = self.consts(self.tau if tau is None else tau)
        return [self.P0[i] + C[i] * (1.0 - math.exp(-k * t)) + Weff[i] * t for i in range(3)]

    def vel1(self, t, tau=None):
        k, E, Weff, C = self.consts(self.tau if tau is None else tau)
        return [C[i] * k * math.exp(-k * t) + Weff[i] for i in range(3)]

    def v2_initial(self, tau=None):
        v = self.vel1(0.0, tau)
        return sum(x * x for x in v)

    def v2_bounce(self, tau=None):
        tau = self.tau if tau is None else tau
        v = self.vel1(tau, tau)
        return sum(x * x for x in v)

    def dv2_initial(self, tau):
        k, E, Weff, C = self.consts(tau)
        om = 1.0 - E
        s = 0.0
        for i in range(3):
            D = C[i] * om
            dC = (-Weff[i] * om - D * k * E) / (om * om)
            s += (C[i] * k + Weff[i]) * k * dC
        return 2.0 * s

    def apex(self, tau):
        k, E, Weff, C = self.consts(tau)
        r = C[1] * k / -Weff[1]
        if r <= 0.0:
            return self.P0[1]
        ts = math.log(r) / k
        return self.P0[1] + C[1] * (1.0 - math.exp(-k * ts)) + Weff[1] * ts

    def net_height(self, tau=None):
        tau = self.tau if tau is None else tau
        lo, hi = (0.0, tau) if self.P0[0] > 0.0 else (tau, 0.0)
        k, E, Weff, C = self.consts(tau)
        t = 0.0
        for _ in range(60):
            t = 0.5 * (lo + hi)
            x = self.P0[0] + C[0] * (1.0 - math.exp(-k * t)) + Weff[0] * t
            if x >= 0.0:
                lo = t
            else:
                hi = t
        return self.P0[1] + C[1] * (1.0 - math.exp(-k * t)) + Weff[1] * t

    # ---------------------------------------------------------------- spin (fn_889C1868 / fn_889C0DC0)
    def set_drift(self, d):
        l = math.sqrt(sum(x * x for x in d))
        if l == 0.0:
            return
        u = [x / l for x in d]
        c1 = [-u[2], 0.0, u[0]]
        c2 = [c1[1] * u[2] - c1[2] * u[1], c1[2] * u[0] - c1[0] * u[2], c1[0] * u[1] - c1[1] * u[0]]
        sgn = -1.0 if self.sidespin_neg else 1.0
        sa, sb, sc = self.spin
        self.A = [u[i] * sc + c1[i] * sb * sgn + c2[i] * sa for i in range(3)]


def _bisect(f_go_hi, lo, hi, n=20):
    for _ in range(n):
        mid = 0.5 * (lo + hi)
        if f_go_hi(mid):
            hi = mid
        else:
            lo = mid
    return 0.5 * (lo + hi)


def quantise(tau):
    n = int(math.floor(tau * 60.0 + 1e-9))
    return n / 60.0, n


def solve(B, row, templates, mode="step"):
    """fn_888AD0E8: returns a dict with tau, bounce_tick, tau_min, has_min, raised, initial_kmh, ..."""
    def node(val):
        d = math.hypot(B.P1[0] - B.P0[0], B.P1[2] - B.P0[2]) * 100.0
        return templates.eval_value(val, d, B.P0[1] * 100.0, mode)

    thr = ((B.radius_cm + B.net_cm) * 0.01 if B.planned else B.aim_height) + 0.01
    w = min(max(1.0 - B.sec_weight, 0.0), 1.0)
    kind, kind2 = row["kind"], row["secondary_kind"]
    o = {"has_min": True, "raised": False, "net_unreachable": False, "tau_min": None}
    tmin = _bisect(lambda t: B.dv2_initial(t) > 0.0, TAU_LO, TAU_HI)
    if kind == "DropTime":
        tau = node(row["primary"])
        if not B.planned:
            target = (B.speed_kmh / KMH) ** 2
            o["tau_min"] = tmin
            tau = tmin if B.v2_initial(tmin) > target else _bisect(lambda t: B.v2_initial(t) < target, TAU_LO, tmin)
        if not B.wood and B.planned and B.net_height(tau) < thr:
            o["raised"] = True
            tau = _bisect(lambda t: B.net_height(t) > thr, tau, tau + 2.0)
        desired = tau
        if kind2 == "DropTime":
            desired = node(row["secondary"]) + tau
        elif kind2 == "Apogee":
            target = B.apex(tau) + node(row["secondary"])
            desired = _bisect(lambda t: B.apex(t) > target, TAU_LO, TAU_HI)
        B.tau = tau + w * (desired - tau) if B.planned else tau
    else:
        metric = {"InitialSpeed": B.v2_initial, "BounceSpeed": B.v2_bounce}.get(kind)
        o["has_min"] = B.dv2_initial(TAU_LO) < 0.0
        if not o["has_min"]:
            B.tau = TAU_LO
            o.update(tau=B.tau, bounce_tick=None, initial_kmh=math.sqrt(B.v2_initial()) * KMH)
            return o
        o["tau_min"] = tmin
        tgt = node(row["primary"]) if B.planned else B.speed_kmh
        target = (tgt / KMH) ** 2
        if metric is None:
            tau = _bisect(lambda t: True, TAU_LO, tmin)          # AverageSpeed stub: converges to 0.1 s
        elif metric(tmin) > target:
            tau = tmin                                           # target slower than the slowest arc
            o["speed_limited"] = True
        else:
            tau = _bisect(lambda t: metric(t) < target, TAU_LO, tmin)
        if B.planned and B.net_height(tau) < thr:
            hi = tmin
            if B.net_height(tmin) < thr:
                o["net_unreachable"] = True
                hi = tmin + 5.0
            tau = _bisect(lambda t: B.net_height(t) > thr, tau, hi, 40)
            o["raised"] = True
        B.tau = tau
        if B.planned and kind2:
            ta, tb = tau, tmin
            if o["net_unreachable"]:
                tb = ta
            elif kind2 == "DropTime":
                tb = node(row["secondary"]) + ta
            elif kind2 == "Apogee":
                lim = -B.apex(ta) - node(row["secondary"])
                if not (-B.apex(tmin) > lim):
                    tb = _bisect(lambda t: lim > -B.apex(t), ta, tmin)
            elif kind2 in ("InitialSpeed", "BounceSpeed"):
                m = B.v2_initial if kind2 == "InitialSpeed" else B.v2_bounce
                d = math.sqrt(m(ta)) * KMH - node(row["secondary"])
                tgt2 = (d / KMH) ** 2
                if not (m(tmin) > tgt2):
                    tb = _bisect(lambda t: tgt2 > m(t), ta, tmin)
            B.tau = ta + w * (tb - ta)
    o["tau_final"] = B.tau
    B.tau, n = quantise(B.tau)
    o["tau"], o["bounce_tick"] = B.tau, n
    o["initial_kmh"] = math.sqrt(B.v2_initial()) * KMH
    return o


def bounce(B, row, templates, v_in, no_sidespin=True):
    """fn_889C1C80 applied to the analytic arrival velocity; returns (v_out, spin after).

    no_sidespin is ball+0x4E1 (1 in the State.bin ball image): spin_b and spin_c are zeroed instead of decayed."""
    v = [v_in[0], -v_in[1], v_in[2]]
    sa, sb, sc = B.spin
    theta = math.atan2(v[1], v[0])
    if theta > math.pi / 2:
        theta = math.pi - theta
    c16 = templates.eval_curve16
    bc = row["bounce"]
    loss = c16(bc["speed_loss"], sa)
    decay = c16(bc["spin_decay"], sa)
    yaw = c16(bc["yaw_kick"], sb)
    tilt = c16(bc["out_elevation"], theta) - theta
    if tilt >= math.pi:
        tilt -= 2 * math.pi
    if tilt < -math.pi:
        tilt += 2 * math.pi
    tilt *= abs(5.0 * sa)
    v = [x * (1.0 - loss) for x in v]
    axis = [v[1] * 0.0 - v[2] * 1.0, v[2] * 0.0 - v[0] * 0.0, v[0] * 1.0 - v[1] * 0.0]
    l = math.sqrt(sum(x * x for x in v))
    if l == 0.0 or abs(v[1] / l) >= 0.99999:
        axis = [0.0, 0.0, 1.0]
    v = _rotate(v, axis, tilt)
    v = _rotate(v, [0.0, 1.0, 0.0], yaw)
    if no_sidespin:
        spin = (sa * (1 - decay), 0.0, 0.0)
    else:
        spin = (sa * (1 - decay), sb * (1 - decay), sc * (1 - decay))
    return v, spin, {"speed_loss": loss, "spin_decay": decay}


def _rotate(v, axis, ang):
    l = math.sqrt(sum(x * x for x in axis))
    if l == 0.0:
        return v
    n = [x / l for x in axis]
    c, s = math.cos(ang), math.sin(ang)
    d = sum(n[i] * v[i] for i in range(3))
    cr = [n[1] * v[2] - n[2] * v[1], n[2] * v[0] - n[0] * v[2], n[0] * v[1] - n[1] * v[0]]
    return [v[i] * c + cr[i] * s + n[i] * d * (1 - c) for i in range(3)]


def simulate(row, templates, frm, to, blend=0.5, sec_weight=1.0, mode="step", a4=0.06, g=9.81, radius_cm=4.0,
             net_cm=91.4, sidespin_neg=False):
    """Plan and fly one shot of a decoded template row. Returns a flat dict of measurements."""
    B = Ball(row["T"], a4, g, radius_cm, net_cm)
    B.P0 = [frm[0] * 0.01, frm[1] * 0.01 - radius_cm * 0.01, frm[2] * 0.01]
    B.P1 = [to[0] * 0.01, to[1] * 0.01, to[2] * 0.01]
    B.sec_weight = sec_weight
    B.sidespin_neg = sidespin_neg
    h = frm[1] * 0.01
    sp = row["spin"]

    def lerp(pair):
        lo = templates.eval_value(pair["lo"], h, 0.0, mode)
        hi = templates.eval_value(pair["hi"], h, 0.0, mode)
        return lo + (hi - lo) * blend

    B.spin = [lerp(sp["a"]), lerp(sp["b"]), lerp(sp["c"])]
    B.set_drift([B.P0[i] - B.P1[i] for i in range(3)])
    o = solve(B, row, templates, mode)
    tau = B.tau
    v0, v1 = B.vel1(0.0), B.vel1(tau)
    vout, spin_after, bc = bounce(B, row, templates, v1)
    hz = lambda v: math.hypot(v[0], v[2])
    nh = B.net_height()
    k_, E_, Weff_, C_ = B.consts(tau)
    r_ = C_[1] * k_ / -Weff_[1]
    ap = B.apex(tau) if r_ > 1.0 else B.P0[1]       # stationary point before launch: the launch is the highest point
    return {
        "tau": round(tau, 4), "bounce_tick": o.get("bounce_tick"), "tau_min": None if o["tau_min"] is None else round(o["tau_min"], 4),
        "has_min": int(o["has_min"]), "raised": int(o["raised"]), "net_unreachable": int(o["net_unreachable"]),
        "speed_limited": int(o.get("speed_limited", False)),
        "init_kmh": round(math.sqrt(sum(x * x for x in v0)) * KMH, 1),
        "arrive_kmh": round(math.sqrt(sum(x * x for x in v1)) * KMH, 1),
        "out_kmh": round(math.sqrt(sum(x * x for x in vout)) * KMH, 1),
        "launch_deg": round(math.degrees(math.atan2(v0[1], hz(v0))), 1),
        "arrive_deg": round(math.degrees(math.atan2(-v1[1], hz(v1))), 1),
        "out_deg": round(math.degrees(math.atan2(vout[1], hz(vout))), 1),
        "apex_m": round(ap + radius_cm * 0.01, 3),
        "net_clear_m": round(nh + radius_cm * 0.01 - net_cm * 0.01, 3),
        "dist_m": round(math.hypot(B.P1[0] - B.P0[0], B.P1[2] - B.P0[2]), 2),
        "spin_a": round(B.spin[0], 4), "spin_b": round(B.spin[1], 4), "spin_c": round(B.spin[2], 4),
        "k": round(B.k, 4), "bounce_speed_loss": round(bc["speed_loss"], 4), "bounce_spin_decay": round(bc["spin_decay"], 4),
    }
