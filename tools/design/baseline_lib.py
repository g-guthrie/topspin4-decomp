#!/usr/bin/env python3
"""Pure helpers for the retune baseline (tools/design/retune_baseline.py); standard library only.

Nothing here reads game files, so the unit test (tests/test_design_baseline.py) runs on synthetic
inputs.  Units follow the gameplay notes: world cm on the court, local metres and m/s inside the
ball model, 60 frames per second (EngineConfig.Frequency).
"""

import math

FPS = 60.0
KMH_PER_MS = 3.6
MPH_PER_KMH = 1.0 / 1.609344


def kmh_to_mph(kmh):
    return kmh * MPH_PER_KMH


def frames_to_ms(frames):
    return frames * 1000.0 / FPS


def ramp_eval(keys, x):
    """Analyser/template curve semantics (graphs-decoded.md s2): keys [(x0, x1, y0, y1), ...];
    use the last key with x0 <= x (the first key if none), y = y0 + slope * clamp(x - x0, 0, x1 - x0)."""
    k = keys[0]
    for kk in keys:
        if kk[0] <= x:
            k = kk
    x0, x1, y0, y1 = k[:4]
    if x1 == x0:
        return y0
    t = min(max(x - x0, 0.0), x1 - x0)
    return y0 + (y1 - y0) / (x1 - x0) * t


def flat_spans(func, lo, hi, n=200, tol=1e-6):
    """Sample func on [lo, hi]; return the sub-intervals (a, b, value) where it does not change
    (|delta| <= tol between neighbours), longest first.  Used to find stat ranges that do nothing."""
    xs = [lo + (hi - lo) * i / n for i in range(n + 1)]
    ys = [func(x) for x in xs]
    spans, start = [], 0
    for i in range(1, n + 1):
        if abs(ys[i] - ys[i - 1]) > tol:
            if i - 1 > start:
                spans.append((xs[start], xs[i - 1], ys[start]))
            start = i
    if n > start:
        spans.append((xs[start], xs[n], ys[start]))
    spans.sort(key=lambda s: s[0] - s[1])
    return spans


def knees(func, lo, hi, n=200, rel=0.25):
    """x positions where the sampled slope changes by more than ``rel`` of the largest slope."""
    xs = [lo + (hi - lo) * i / n for i in range(n + 1)]
    ys = [func(x) for x in xs]
    sl = [(ys[i + 1] - ys[i]) / (xs[i + 1] - xs[i]) for i in range(n)]
    big = max((abs(s) for s in sl), default=0.0)
    if big == 0.0:
        return []
    out = []
    for i in range(1, n):
        if abs(sl[i] - sl[i - 1]) > rel * big:
            out.append(xs[i])
    merged = []
    for x in out:
        if not merged or x - merged[-1] > (hi - lo) * 2.0 / n:
            merged.append(x)
    return merged


def sweep(func, lo, hi, n=40):
    """(min, max, x at min, x at max) of func on an n-step grid of [lo, hi]."""
    best = None
    for i in range(n + 1):
        x = lo + (hi - lo) * i / n
        y = func(x)
        if best is None:
            best = [y, y, x, x]
        else:
            if y < best[0]:
                best[0], best[2] = y, x
            if y > best[1]:
                best[1], best[3] = y, x
    return tuple(best)


# --------------------------------------------------------------------------- ball flight after a bounce

def arc2_state(p0, v0, k, weff, t):
    """Closed-form arc 2 of the ball model (ball-physics.md s0): drag rate k (1/s), drift-plus-gravity
    velocity weff (m/s, the steady state the velocity relaxes to).  Returns (position, velocity)."""
    e = math.exp(-k * t)
    p = [p0[i] + (v0[i] - weff[i]) * (1.0 - e) / k + weff[i] * t for i in range(3)]
    v = [weff[i] + (v0[i] - weff[i]) * e for i in range(3)]
    return p, v


def arc2_weff(k, T, A, g=9.81):
    """Weff = A / T - (0, g / k, 0) (A = spin drift acceleration vector, T = template drag scale)."""
    return [A[0] / T, A[1] / T - g / k, A[2] / T]


def arc2_apex(p0, v0, k, weff):
    """Highest point of arc 2 (the bounce height) and its time; (p0.y, 0) when the ball is not rising."""
    if v0[1] <= 0.0 or weff[1] >= 0.0:
        return p0[1], 0.0
    r = (v0[1] - weff[1]) / -weff[1]
    t = math.log(r) / k
    p, _ = arc2_state(p0, v0, k, weff, t)
    return p[1], t


def arc2_time_to_x(p0, v0, k, weff, x_target, t_max=5.0):
    """First time the arc reaches |x| = |x_target| moving away from the net, by bisection; None if it
    does not get there within t_max (or lands first: y < 0)."""
    def x_at(t):
        return arc2_state(p0, v0, k, weff, t)[0][0]
    sgn = 1.0 if v0[0] >= 0.0 else -1.0
    lo, hi = 0.0, None
    steps = 200
    for i in range(1, steps + 1):
        t = t_max * i / steps
        p, _ = arc2_state(p0, v0, k, weff, t)
        if p[1] < -1e-9:
            return None
        if sgn * p[0] >= sgn * x_target:
            hi = t
            break
        lo = t
    if hi is None:
        return None
    for _ in range(50):
        mid = 0.5 * (lo + hi)
        if sgn * x_at(mid) >= sgn * x_target:
            hi = mid
        else:
            lo = mid
    return 0.5 * (lo + hi)


def speed(v):
    return math.sqrt(sum(c * c for c in v))


def fmt(x, nd=2):
    if x is None:
        return "-"
    if isinstance(x, float):
        return ("%." + str(nd) + "f") % x
    return str(x)


def md_table(header, rows):
    out = ["| " + " | ".join(header) + " |", "|" + "|".join("---" for _ in header) + "|"]
    for r in rows:
        out.append("| " + " | ".join(fmt(c) for c in r) + " |")
    return "\n".join(out)
