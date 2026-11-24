#!/usr/bin/env python3
"""Landing points of aimed shots on the retail aim quads (data/gameplay/aim_tables.yaml), fed by the proposed
Efficiency (retune_model.aim_efficiency) and DeepDeviation by quality.  Standard library only.

Follows docs/gameplay/aiming.md: zone blend (fn_88693040), quad at efficiency m (fn_8867D350), stick direction to
the quad edge (fn_8867D150), DeepDeviation pull-back along the hitter-to-target line and clip to the lines quad
(fn_886805E0 / fn_88693280).  Singles only (no doubles widening), hitter on the near side at z < 0 (no mirror).
"""

import math
import os
import re

import retune_model as M

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
AIM_YAML = os.path.join(ROOT, "data", "gameplay", "aim_tables.yaml")
NUM = r"-?\d+(?:\.\d+)?"


def load_configs(path=AIM_YAML):
    """{name: {"side": cm, "volley": cm, "baseline": cm, "zones": {zone: {"centre": (x, z), "quads": [4 x 4 corners]}}}}"""
    cfgs, cur, zone = {}, None, None
    with open(path) as f:
        for line in f:
            s = line.strip()
            m = re.match(r"name: (\S+)", s)
            if m:
                cur = cfgs.setdefault(m.group(1), {"zones": {}})
                continue
            if cur is None:
                continue
            m = re.match(r"(side|volley|baseline)_distance: (%s)" % NUM, s)
            if m:
                cur[m.group(1)] = float(m.group(2))
                continue
            m = re.match(r"(VolleyCenter|VolleySide|BaselineCenter|BaselineSide):$", s)
            if m:
                zone = cur["zones"].setdefault(m.group(1), {"quads": [None] * 4})
                continue
            m = re.match(r"centre: \[(%s), (%s)\]" % (NUM, NUM), s)
            if m and zone is not None:
                zone["centre"] = (float(m.group(1)), float(m.group(2)))
                continue
            m = re.match(r"quad(\d): (\[.*\])$", s)
            if m and zone is not None:
                nums = [float(x) for x in re.findall(NUM, m.group(2))]
                zone["quads"][int(m.group(1))] = [(nums[i], nums[i + 1]) for i in range(0, 8, 2)]
    return cfgs


def _lerp(a, b, t):
    return (a[0] + (b[0] - a[0]) * t, a[1] + (b[1] - a[1]) * t)


def _lerpq(qa, qb, t):
    return [_lerp(a, b, t) for a, b in zip(qa, qb)]


def zone_quad(zone, m):
    q = zone["quads"]
    if m < 0.5:
        return _lerpq(q[0], q[1], 2 * m)
    if m <= 1.0:
        return _lerpq(q[1], q[2], 2 * (m - 0.5))
    return _lerpq(q[2], q[3], min(m - 1.0, 1.0))


def quad_at(cfg, m, hitter=(-1188.0, -50.0)):
    lat = M.clamp((abs(hitter[1]) - 0.0) / (cfg["side"] - 0.0), 0.0, 1.0)
    dep = M.clamp((hitter[0] + cfg["baseline"]) / (cfg["baseline"] - cfg["volley"]), 0.0, 1.0)
    z = cfg["zones"]
    base = _lerpq(zone_quad(z["BaselineCenter"], m), zone_quad(z["BaselineSide"], m), lat)
    vol = _lerpq(zone_quad(z["VolleyCenter"], m), zone_quad(z["VolleySide"], m), lat)
    return _lerpq(base, vol, dep)


def stick_target(quad, ax, ay):
    """fn_8867D150: c0 short/z-, c1 short/z+, c2 deep/z-, c3 deep/z+; ay = toward the net/deep, ax = toward z+."""
    c0, c1, c2, c3 = quad
    n = 1.0 / math.hypot(ax, ay)
    if ax * ax > ay * ay:
        s = (ay * n * math.sqrt(2.0) + 1.0) / 2.0
        return _lerp(c1, c3, s) if ax >= 0 else _lerp(c0, c2, s)
    s = (ax * n * math.sqrt(2.0) + 1.0) / 2.0
    return _lerp(c2, c3, s) if ay >= 0 else _lerp(c0, c1, s)


def land(cfg, eff_final, deep_cm, ax, ay, hitter=(-1188.0, -50.0)):
    """In-shot landing point (x past the net, z) for a final efficiency, DeepDeviation (cm) and stick direction."""
    tx, tz = stick_target(quad_at(cfg, eff_final, hitter), ax, ay)
    dx, dz = tx - hitter[0], tz - hitter[1]
    d = math.hypot(dx, dz)
    k = max(0.0, (d - deep_cm) / d)
    x, z = hitter[0] + dx * k, hitter[1] + dz * k
    lines = quad_at(cfg, 1.0, hitter)
    x = min(x, max(c[0] for c in lines))
    zmax = max(c[1] for c in lines)
    zmin = min(c[1] for c in lines)
    return max(x, 50.0), M.clamp(z, zmin, zmax)


def corner_landings(rng, cfg, cls_key, grade, timing_sampler, hand_stat, n=4000, err_fn=None):
    """Sample corner aims (stick up-right).  Returns (list of (x, z) for In shots, P(error))."""
    out, errs = [], 0
    for _ in range(n):
        tf = timing_sampler(rng)
        eff = M.aim_efficiency(cls_key, grade, tf, hand_stat)
        fe = M.final_efficiency(eff, rng.random())
        if err_fn is not None and rng.random() < err_fn(grade, tf):
            errs += 1
            continue
        out.append(land(cfg, fe, M.deep_deviation(rng, grade, tf), 1.0, 1.0))
    return out, errs / n
