#!/usr/bin/env python3
"""Ball flight and bounce for the retune spec (docs/design/retune-spec.md, section 3); standard library only.

Two models side by side:

* the GAME model: the repository's port of the shipped closed-form flight (tools/ts4data/ball_model.py, spec
  docs/gameplay/ball-physics.md) driven by template rows.  Retail rows are read from the committed dump
  data/gameplay/ball_templates.yaml (no game files needed); proposed rows are copies with edited fields, so
  every proposal here is expressed in fields the template table already has;
* a REAL-ball reference: quadratic drag (Cd 0.507, Cross & Lindsey 2014), Magnus lift from spin
  (Stepanek-type fit CL = 1 / (2 + v / (r w)), a judgement), and a Cross-style grip/slip bounce with the
  ITF court-pace parameters (friction mu, vertical restitution e) per surface.

Units: world cm for court points, m and m/s inside the models, km/h and mph for speeds.
"""

import copy
import math
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, os.path.join(ROOT, "tools", "ts4data"))

import ball_model as BM  # noqa: E402
import templates as TPL  # noqa: E402

TEMPLATES_YAML = os.path.join(ROOT, "data", "gameplay", "ball_templates.yaml")
MPH_PER_KMH = 1.0 / 1.609344
BASELINE_X_M = 11.885
NET_CM = 91.4


def kmh_to_mph(v):
    return v * MPH_PER_KMH


def mph_to_kmh(v):
    return v / MPH_PER_KMH


# --------------------------------------------------------------------------- minimal YAML reader

def _scalar(s):
    s = s.strip()
    if s.startswith("[") and s.endswith("]"):
        inner = s[1:-1].strip()
        return [] if not inner else [_scalar(x) for x in inner.split(",")]
    if s in ("null", "~", ""):
        return None
    if s in ("true", "false"):
        return s == "true"
    try:
        if s.lower().startswith("0x"):
            return s          # keep hex offsets as text
        return int(s)
    except ValueError:
        pass
    try:
        return float(s)
    except ValueError:
        return s.strip("'\"")


def parse_yaml_subset(text):
    """Parse the block-style YAML written by the repository's dump tools (mappings, '- ' lists of mappings or
    scalars, inline [a, b] lists, plain scalars).  Not a general YAML parser."""
    lines = []
    for raw in text.splitlines():
        if not raw.strip() or raw.lstrip().startswith("#"):
            continue
        lines.append((len(raw) - len(raw.lstrip(" ")), raw.strip()))
    pos = [0]

    def block(indent):
        if pos[0] >= len(lines):
            return None
        ind, s = lines[pos[0]]
        if s.startswith("- "):
            out = []
            while pos[0] < len(lines):
                ind, s = lines[pos[0]]
                if ind != indent or not s.startswith("- "):
                    break
                body = s[2:]
                if ":" in body and not body.startswith("["):
                    # a mapping that starts on the dash line: re-feed it as a mapping at indent + 2
                    lines[pos[0]] = (indent + 2, body)
                    out.append(mapping(indent + 2))
                else:
                    pos[0] += 1
                    out.append(_scalar(body))
            return out
        return mapping(indent)

    def mapping(indent):
        out = {}
        while pos[0] < len(lines):
            ind, s = lines[pos[0]]
            if ind != indent or s.startswith("- "):
                break
            key, _, rest = s.partition(":")
            pos[0] += 1
            if rest.strip():
                out[key.strip()] = _scalar(rest)
            else:
                if pos[0] < len(lines) and lines[pos[0]][0] > indent:
                    out[key.strip()] = block(lines[pos[0]][0])
                elif pos[0] < len(lines) and lines[pos[0]][0] == indent and lines[pos[0]][1].startswith("- "):
                    out[key.strip()] = block(indent)
                else:
                    out[key.strip()] = None
        return out

    return block(lines[0][0]) if lines else {}


# --------------------------------------------------------------------------- template rows

def _value(v):
    if v is None:
        return {"type": "const", "value": 0.0}
    if v.get("type") == "const":
        return {"type": "const", "value": float(v["value"])}
    if v.get("type") == "curve20":
        return {"type": "curve20", "keys": [(k["x0"], k["x1"], k["y0"], k.get("slope", 0.0), k["y1"])
                                            for k in v["keys"]]}
    if v.get("type") == "table2d":
        return {"type": "table2d", "rows": [{"a": rr["a_dist_cm"], "keys": _c16(rr["keys_over_height_cm"])}
                                            for rr in v["rows"]]}
    raise ValueError("unsupported value type %r" % v.get("type"))


def _c16(keys):
    return [(k["x0"], k["x1"], k["y0"], k["y1"]) for k in keys]


def load_rows(path=TEMPLATES_YAML):
    """Template rows from the committed dump, in the dict shape ball_model.solve/bounce expect."""
    with open(path) as f:
        doc = parse_yaml_subset(f.read())
    rows = []
    for r in doc["rows"]:
        sp = r["spin"]
        rows.append({
            "index": r["index"], "name": r["name"], "kind": r["kind"], "secondary_kind": r["secondary_kind"],
            "T": float(r["T"]), "primary": _value(r["primary"]), "secondary": _value(r["secondary"]),
            "spin": {"a": {"lo": _value(sp["vertical_a"]["lo"]), "hi": _value(sp["vertical_a"]["hi"])},
                     "b": {"lo": _value(sp["lateral_b"]["lo"]), "hi": _value(sp["lateral_b"]["hi"])},
                     "c": {"lo": _value(sp["along_c"]["lo"]), "hi": _value(sp["along_c"]["hi"])}},
            "bounce": {"speed_loss": _c16(r["bounce"]["speed_loss_vs_spin_a"]),
                       "spin_decay": _c16(r["bounce"]["spin_decay_vs_spin_a"]),
                       "out_elevation": _c16(r["bounce"]["out_elevation_vs_in_elevation_rad"]),
                       "yaw_kick": _c16(r["bounce"]["yaw_kick_vs_spin_b_rad"])},
        })
    return rows


def edit_row(row, primary_kmh=None, T=None, spin_a=None, bounce_loss=None, out_elev_gain=None, apogee=None):
    """A proposed row: copy of `row` with template fields replaced.
    primary_kmh = (speed at 500 cm, speed at 3000 cm) ramp; T = drag scale; spin_a = (lo, hi) constants at the
    blend ends; bounce_loss = [(spin_a0, spin_a1, loss0, loss1)] curve16; apogee = (m at 500, m at 3000)."""
    r = copy.deepcopy(row)
    if primary_kmh is not None:
        r["primary"] = {"type": "curve20", "keys": [(500.0, 3000.0, primary_kmh[0], 0.0, primary_kmh[1])]}
    if apogee is not None:
        r["secondary"] = {"type": "curve20", "keys": [(500.0, 3000.0, apogee[0], 0.0, apogee[1])]}
    if T is not None:
        r["T"] = T
    if spin_a is not None:
        r["spin"]["a"] = {"lo": {"type": "const", "value": spin_a[0]}, "hi": {"type": "const", "value": spin_a[1]}}
    if bounce_loss is not None:
        r["bounce"]["speed_loss"] = list(bounce_loss)
    if out_elev_gain is not None:
        r["bounce"]["out_elevation"] = [(0.0, 1.5, 0.0, 1.5 * out_elev_gain)]
    return r


# --------------------------------------------------------------------------- game-model flight

def _arc2(p0, v0, k, weff, t):
    e = math.exp(-k * t)
    return ([p0[i] + (v0[i] - weff[i]) * (1 - e) / k + weff[i] * t for i in range(3)],
            [weff[i] + (v0[i] - weff[i]) * e for i in range(3)])


def game_fly(row, frm, to, pf=1.0, blend=0.5, a4=0.06, net_cm=NET_CM, speed_scale=1.0):
    """Plan and fly one In shot in the shipped model (ramp curves).  frm/to world cm.  pf = PowerfulFactor
    (secondary weight 1 - pf), blend = spin blend.  speed_scale multiplies the primary target speed (used to
    model a PF-driven speed in a proposed row without a new curve).  Returns a dict of flight quantities."""
    r = row
    if speed_scale != 1.0:
        r = copy.deepcopy(row)
        r["primary"] = {"type": "curve20", "keys": [(k[0], k[1], k[2] * speed_scale, k[3], k[4] * speed_scale)
                                                    for k in row["primary"]["keys"]]}
    B = BM.Ball(r["T"], a4, 9.81, 4.0, net_cm)
    B.P0 = [frm[0] * 0.01, frm[1] * 0.01 - 0.04, frm[2] * 0.01]
    B.P1 = [to[0] * 0.01, to[1] * 0.01, to[2] * 0.01]
    B.sec_weight = pf
    h = frm[1] * 0.01

    def lerp(pair):
        lo = TPL.eval_value(pair["lo"], h, 0.0, "ramp")
        hi = TPL.eval_value(pair["hi"], h, 0.0, "ramp")
        return lo + (hi - lo) * blend
    B.spin = [lerp(r["spin"]["a"]), lerp(r["spin"]["b"]), lerp(r["spin"]["c"])]
    B.set_drift([B.P0[i] - B.P1[i] for i in range(3)])
    o = BM.solve(B, r, TPL, "ramp")
    tau = B.tau
    v0, v1 = B.vel1(0.0), B.vel1(tau)
    vout, spin_after, bc = BM.bounce(B, r, TPL, v1)
    weff = [0.0, spin_after[0] / r["T"] - 9.81 / B.k, 0.0]
    p = list(B.P1)
    # apex of the bounce and speed at the receiver's baseline plane
    apex2 = p[1]
    if vout[1] > 0 and weff[1] < 0:
        ta = math.log((vout[1] - weff[1]) / -weff[1]) / B.k
        apex2 = _arc2(p, vout, B.k, weff, ta)[0][1]
    t_base = None
    v_base = None
    if p[0] < BASELINE_X_M:
        t = 0.0
        while t < 4.0:
            t += 1.0 / 240
            q, v = _arc2(p, vout, B.k, weff, t)
            if q[1] < -1e-6:
                break
            if q[0] >= BASELINE_X_M:
                t_base, v_base = t, v
                break
    k_, E_, Weff_, C_ = B.consts(tau)
    apex = B.apex(tau) if C_[1] * k_ / -Weff_[1] > 1.0 else B.P0[1]
    sp = lambda v: math.sqrt(sum(c * c for c in v))
    hz = lambda v: math.hypot(v[0], v[2])
    return {"launch_kmh": sp(v0) * 3.6, "bounce_in_kmh": sp(v1) * 3.6, "bounce_out_kmh": sp(vout) * 3.6,
            "baseline_kmh": None if v_base is None else sp(v_base) * 3.6,
            "t_bounce": tau, "t_baseline": None if t_base is None else tau + t_base,
            "apex_m": apex + 0.04, "net_clear_m": B.net_height() + 0.04 - net_cm * 0.01,
            "bounce_apex_m": apex2 + 0.04, "in_deg": math.degrees(math.atan2(-v1[1], hz(v1))),
            "out_deg": math.degrees(math.atan2(vout[1], hz(vout))), "spin_a": B.spin[0],
            "speed_limited": bool(o.get("speed_limited")), "raised": bool(o.get("raised")),
            "out_over_in": sp(vout) / sp(v1)}


# --------------------------------------------------------------------------- real-ball reference

RHO, MASS, RADIUS = 1.21, 0.0577, 0.0335          # air kg/m3, ball kg, m (ITF type 2 ball)
CD = 0.507                                          # Cross & Lindsey 2014, free flight
ALPHA = 0.55                                        # moment of inertia / (m r^2) for a tennis ball (Cross)
# ITF Court Pace Rating: CPR = 100 (1 - mu) + 150 (0.81 - e).  Representative values (judgement inside the ITF bands)
SURFACES = {"clay": (0.75, 0.84), "hard": (0.62, 0.81), "grass": (0.56, 0.76)}


def cpr(mu, e):
    return 100.0 * (1.0 - mu) + 150.0 * (0.81 - e)


CL_MAX_AFTER_BOUNCE = 0.20   # judgement: the grip regime leaves 5,000+ rpm; the free-flight lift law is not valid there


def _accel(v, w_rpm, topspin=True, cl_max=0.5):
    s = math.hypot(v[0], v[1])
    kd = 0.5 * RHO * CD * math.pi * RADIUS ** 2 / MASS
    w = w_rpm * 2 * math.pi / 60.0
    cl = 0.0 if w == 0 else min(cl_max, 1.0 / (2.0 + s / (RADIUS * abs(w))))
    kl = 0.5 * RHO * cl * math.pi * RADIUS ** 2 / MASS
    sg = 1.0 if topspin else -1.0       # topspin pushes down (perpendicular to v, rotated)
    ax = -kd * s * v[0] + sg * kl * s * v[1]
    ay = -kd * s * v[1] - sg * kl * s * v[0] - 9.81
    return ax, ay


def real_fly(speed_kmh, angle_deg, spin_rpm, h0=1.0, x0=-11.885, topspin=True, surface="hard", dt=1e-3):
    """2-D flight in the vertical plane of the shot (x along the court), RK2, then a grip/slip bounce.
    spin_rpm > 0 with topspin=True is topspin; topspin=False is backspin (slice).
    Returns net clearance, apex, landing x, speeds and the bounce apex, or None fields if it fails."""
    v = [speed_kmh / 3.6 * math.cos(math.radians(angle_deg)), speed_kmh / 3.6 * math.sin(math.radians(angle_deg))]
    p = [x0, h0]
    t = 0.0
    net = None
    apex = h0
    while p[1] > 0 and t < 6:
        ax, ay = _accel(v, spin_rpm, topspin)
        vm = [v[0] + ax * dt / 2, v[1] + ay * dt / 2]
        ax, ay = _accel(vm, spin_rpm, topspin)
        pn = [p[0] + vm[0] * dt, p[1] + vm[1] * dt]
        if p[0] < 0 <= pn[0]:
            net = p[1] + (pn[1] - p[1]) * (-p[0]) / (pn[0] - p[0])
        p = pn
        v = [v[0] + ax * dt, v[1] + ay * dt]
        apex = max(apex, p[1])
        t += dt
    v_in = math.hypot(*v)
    mu, e = SURFACES[surface]
    vx, vy = v[0], -v[1]
    w = (spin_rpm if topspin else -spin_rpm) * 2 * math.pi / 60.0   # + = topspin (contact point moves back)
    vy_out = e * vy
    # slide: friction impulse mu (1 + e) vy against the contact-point slip velocity vx - r w
    slip = vx - RADIUS * w
    dvx = mu * (1 + e) * vy
    vx_grip = (vx + ALPHA * RADIUS * w) / (1 + ALPHA)        # contact point at rest after the bounce
    if slip > 0:
        vx_out = max(vx - dvx, vx_grip)
    else:
        vx_out = min(vx + dvx, vx_grip)
    w_out = vx_out / RADIUS if vx_out == vx_grip else w - (vx_out - vx) / (ALPHA * RADIUS)
    # after the bounce: fly on to the bounce apex and the baseline plane
    q = [p[0], 0.0]
    u = [vx_out, vy_out]
    b_apex, t2, v_base, t_base = 0.0, 0.0, None, None
    spin2 = abs(w_out) * 60 / (2 * math.pi)
    top2 = w_out >= 0
    while t2 < 3:
        ax, ay = _accel(u, spin2, top2, CL_MAX_AFTER_BOUNCE)
        q = [q[0] + u[0] * dt, q[1] + u[1] * dt]
        u = [u[0] + ax * dt, u[1] + ay * dt]
        t2 += dt
        b_apex = max(b_apex, q[1])
        if v_base is None and q[0] >= BASELINE_X_M:
            v_base, t_base = math.hypot(*u), t + t2
        if q[1] < 0:
            break
    return {"net_clear_m": None if net is None else net - 0.914, "apex_m": apex, "land_x_m": p[0],
            "t_bounce": t, "bounce_in_kmh": v_in * 3.6, "bounce_out_kmh": math.hypot(vx_out, vy_out) * 3.6,
            "out_over_in": math.hypot(vx_out, vy_out) / v_in, "bounce_apex_m": b_apex,
            "in_deg": math.degrees(math.atan2(vy, vx)), "out_deg": math.degrees(math.atan2(vy_out, vx_out)),
            "baseline_kmh": None if v_base is None else v_base * 3.6, "t_baseline": t_base}


def real_aim(speed_kmh, spin_rpm, land_x_m, h0=1.0, x0=-11.885, topspin=True, surface="hard"):
    """Find the launch angle that lands the ball at land_x_m (m past the net), by bisection."""
    lo, hi = -10.0, 40.0
    best = None
    for _ in range(40):
        mid = 0.5 * (lo + hi)
        r = real_fly(speed_kmh, mid, spin_rpm, h0, x0, topspin, surface, dt=2e-3)
        best = r
        if r["land_x_m"] < land_x_m:
            lo = mid
        else:
            hi = mid
    best = real_fly(speed_kmh, 0.5 * (lo + hi), spin_rpm, h0, x0, topspin, surface)
    best["angle_deg"] = 0.5 * (lo + hi)
    return best
