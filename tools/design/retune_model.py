#!/usr/bin/env python3
"""Proposed gameplay model for the Top Spin 4 retune (docs/design/retune-spec.md); standard library only.

Everything here is a *proposal* expressed as functions of values the engine already computes (or that a
named code hook would supply).  The functions are deliberately small and table-driven so that each table
maps to one data edit (analyser graph keys, template fields, Settings rows) or one code change, as listed in
section 11 of the spec.  Nothing reads game files.

Contents
  ratings      rating -> stat curve without the dead zone, floor penalty
  grade        set-up grade (six rows, Tee-off above VeryGood) from the situation inputs
  window       Perfect / Good timing half-widths in frames from ball ease, reaction time, own movement,
               the opponent's last timing grade (direct term, capped) and the timing rating
  speed        stacking model for groundstroke launch speed (mph)
  serve        first / second serve speed, fault and unreturned models
  situations   Monte Carlo sampler of rally situations
  rally        point simulation used for the timing-term sizing and the build abuse check

Units: frames at 60 per second, cm on court, km/h or mph for speeds (named in each function).
"""

import math
import random

FPS = 60.0
MPH_PER_KMH = 1.0 / 1.609344


def kmh(mph):
    return mph / MPH_PER_KMH


def mph(kmh_):
    return kmh_ * MPH_PER_KMH


def clamp(x, lo, hi):
    return lo if x < lo else hi if x > hi else x


def pwl(points, x):
    """Piecewise-linear through (x, y) points, clamped at both ends (the analyser ramp semantics)."""
    if x <= points[0][0]:
        return points[0][1]
    for (x0, y0), (x1, y1) in zip(points, points[1:]):
        if x <= x1:
            return y0 + (y1 - y0) * (x - x0) / (x1 - x0)
    return points[-1][1]


# =========================================================================== ratings

# Retail graph 23 DefaultAttributes (retune-baseline.md 5a): every rating <= 30 maps to 0.
RETAIL_CURVES = {
    "serve": [(30, 0.0), (40, .10), (50, .20), (60, .40), (70, .60), (80, .80), (90, .90), (100, 1.0)],
    "return": [(30, 0.0), (40, .15), (50, .30), (60, .47), (70, .63), (80, .80), (90, .90), (100, 1.0)],
    "forehand": [(30, 0.0), (40, .10), (50, .20), (60, .30), (70, .52), (80, .75), (90, .88), (100, 1.0)],
    "backhand": [(30, 0.0), (40, .10), (50, .20), (60, .30), (70, .52), (80, .75), (90, .88), (100, 1.0)],
    "volley": [(30, 0.0), (40, .10), (50, .20), (60, .40), (70, .60), (80, .80), (90, .90), (100, 1.0)],
    "power": [(30, 0.0), (40, .15), (50, .30), (60, .40), (70, .50), (80, .65), (90, .83), (100, 1.0)],
    "speed": [(30, 0.0), (40, .10), (50, .20), (60, .40), (70, .60), (80, .80), (90, .90), (100, 1.0)],
    "stamina": [(30, 0.0), (40, .10), (50, .20), (60, .40), (70, .60), (80, .80), (90, .90), (100, 1.0)],
}
# Proposed: one smooth curve for every stat, through 0 at rating 0 (no dead zone), slope never flat.
NEW_CURVE = [(0, 0.0), (30, 0.10), (50, 0.25), (60, 0.35), (70, 0.50), (80, 0.67), (90, 0.84), (100, 1.0)]
FLOOR_STAT = 0.25          # below this stat (rating 50) a floor penalty starts
FLOOR_POWER = 1.5          # penalty shape exponent


def retail_stat(stat, rating):
    return pwl([(0, 0.0)] + RETAIL_CURVES[stat], rating) if rating > 30 else 0.0


def new_stat(rating):
    return pwl(NEW_CURVE, rating)


def floor_penalty(rating):
    """0 at rating >= 50, rising to 1 at rating 0 (convex): the extra cost of a dumped rating."""
    s = new_stat(rating)
    return 0.0 if s >= FLOOR_STAT else ((FLOOR_STAT - s) / FLOOR_STAT) ** FLOOR_POWER


# =========================================================================== set-up grade

GRADES = ["Tee-off", "VeryGood", "Good", "Normal", "Bad", "VeryBad"]

# Penalty points per input (piecewise linear).  Inputs and engine sources (spec section 4):
#   frames  : TimingState #3fe3a099 S+0xCF0, frames from the opponent's contact to own contact
#   v_req   : #5cf9de02 S+0x7A4, required run speed to the hit point, m/s
#   run_cm  : #03d2be3d S+0x7A0, distance still to run to the hit point, cm
#   height  : Ball+0x344 contact height, cm
#   pace    : incoming ball speed at contact, km/h (#1407106c S+0x770: needs the code writer, TUNING s12)
#   depth_x : own court position, cm behind own baseline (+ = behind, - = inside the court)
#   set_f   : frames the player has been planted (planner Hold/BallWindow state) at contact
#   stretch : SwingCategory reach qualifier #0698037d (0/1)
#   kick    : incoming spin_a (template spin, negative = topspin), magnitude 0..0.5
P_TIME = [(20, 4.5), (30, 3.0), (45, 1.6), (60, 0.7), (80, 0.0)]
P_RUN = [(0.0, 0.0), (2.0, 0.0), (4.0, 1.0), (6.0, 2.4), (7.5, 4.0)]
P_LOW = [(20, 2.4), (40, 1.5), (60, 0.6), (75, 0.0)]
P_HIGH = [(130, 0.0), (165, 0.8), (200, 2.0)]
P_PACE = [(45, 0.0), (60, 0.3), (75, 0.9), (90, 1.7), (110, 2.8)]
P_DEEP = [(150, 0.0), (300, 0.5), (500, 1.4)]
P_KICK = [(0.15, 0.0), (0.35, 0.6), (0.5, 1.0)]
STRETCH_PTS = 1.4
UNSET_PTS = 0.4             # still moving at contact (set_f < 6)
INSIDE_BONUS = -0.4         # inside the court with time (depth_x < -150 and frames >= 60)
GRADE_EDGES = [0.8, 2.0, 3.4, 5.0]          # VeryGood | Good | Normal | Bad | VeryBad
TEEOFF = {"pace_max": 52.0, "h_lo": 80.0, "h_hi": 140.0, "frames_min": 80, "run_max": 150.0,
          "set_min": 15, "depth_max": 150.0, "score_max": 0.5}


def grade_points(frames, v_req, run_cm, height, pace, depth_x, set_f, stretch, kick=0.0):
    pts = {
        "time": pwl(P_TIME, frames),
        "run": pwl(P_RUN, v_req),
        "height": pwl(P_LOW, height) + pwl(P_HIGH, height),
        "pace": pwl(P_PACE, pace),
        "position": pwl(P_DEEP, depth_x) + (INSIDE_BONUS if depth_x < -150 and frames >= 60 else 0.0),
        "stretch": STRETCH_PTS if stretch else 0.0,
        "unset": UNSET_PTS if set_f < 6 else 0.0,
        "kick": pwl(P_KICK, abs(kick)),
    }
    return pts


def grade_of(frames, v_req, run_cm, height, pace, depth_x, set_f, stretch, kick=0.0):
    """(grade name, score, points).  Tee-off needs a VeryGood score AND every sitter condition."""
    pts = grade_points(frames, v_req, run_cm, height, pace, depth_x, set_f, stretch, kick)
    q = max(0.0, sum(pts.values()))
    t = TEEOFF
    if (q <= t["score_max"] and pace <= t["pace_max"] and t["h_lo"] <= height <= t["h_hi"]
            and frames >= t["frames_min"] and run_cm <= t["run_max"] and set_f >= t["set_min"]
            and depth_x <= t["depth_max"] and not stretch):
        return "Tee-off", q, pts
    for g, edge in zip(GRADES[1:], GRADE_EDGES):
        if q < edge:
            return g, q, pts
    return "VeryBad", q, pts


# What each grade gives (spec section 4 table).  pace = mph added to the stack, cap = soft pace ceiling (mph,
# forehand flat drive), spin = multiplier on available spin, aim = added aim efficiency (0..1 scale),
# err = multiplier on the error probability, err_add = added error probability, depth_cm = mean depth
# shortfall of an In shot (replaces the uniform 0..310 cm DeepDeviation), window = typical window multiplier
# (informative; the window is computed from the same inputs by window_halfwidths).
GRADE_FX = {
    "Tee-off": dict(pace=9.0, cap=None, spin=1.10, aim=0.15, err=0.5, err_add=0.0, depth_cm=40, window=1.6),
    "VeryGood": dict(pace=5.0, cap=108.0, spin=1.05, aim=0.08, err=0.7, err_add=0.0, depth_cm=70, window=1.3),
    "Good": dict(pace=0.0, cap=103.0, spin=1.00, aim=0.0, err=1.0, err_add=0.0, depth_cm=110, window=1.0),
    "Normal": dict(pace=-3.0, cap=97.0, spin=0.95, aim=-0.08, err=1.3, err_add=0.02, depth_cm=160, window=0.85),
    "Bad": dict(pace=-7.0, cap=89.0, spin=0.85, aim=-0.18, err=1.8, err_add=0.05, depth_cm=230, window=0.65),
    "VeryBad": dict(pace=-12.0, cap=80.0, spin=0.70, aim=-0.30, err=2.5, err_add=0.10, depth_cm=300, window=0.45),
}


# =========================================================================== timing window

PERFECT_HALF_BASE = 1.5       # frames each side of the 20-frame target (retail |t| < 0.1 = 2 frames each side)
GOOD_HALF_BASE = 5.8          # retail |t| < 0.3 = 5.8 frames each side
PERFECT_MIN, PERFECT_MAX = 0.5, 4.5
GOOD_MIN, GOOD_MAX = 2.0, 12.0
E_PACE = [(35, 1.40), (50, 1.22), (65, 1.04), (80, 0.92), (95, 0.82), (110, 0.74), (130, 0.65), (160, 0.58)]
E_HEIGHT = [(20, 0.70), (45, 0.82), (70, 0.97), (85, 1.10), (125, 1.10), (150, 1.0), (180, 0.86), (220, 0.80)]
E_KICK = [(0.15, 1.0), (0.35, 0.90), (0.5, 0.82)]
E_RUN = [(0.0, 1.05), (2.0, 1.0), (4.0, 0.86), (6.0, 0.70), (7.5, 0.58)]
E_SET_BONUS = 1.08            # planted for >= 15 frames
E_STRETCH = 0.80
E_NET_TIME = 1.20             # inside 4 m of the net with reaction time >= 450 ms (a sitter at the net)
E_FLOAT = 1.12                # floating ball: apex well above the net and slow (lob that does not go deep)
# Reaction-time threshold (ms from the opponent's contact to own contact, minus nothing): no effect in normal
# rallies, a steep ramp close to human limits.  Sourced anchors: volley reaction ~205-226 ms (Chow et al. 1999),
# ~500 ms available against a 200 km/h serve (O'Donoghue & Liddle 1998); the shape is a judgement.
RT_CURVE = [(180, 0.22), (220, 0.30), (260, 0.42), (300, 0.56), (350, 0.72), (420, 0.88), (500, 0.97), (560, 1.0)]
# Direct term: the opponent's last timing grade (owner's change of brief).  Sized with the rally simulation.
OPP_TIMING_FX = {"Perfect": 0.88, "Good": 1.0, "Poor": 1.12, "Mistimed": 1.25}
OPP_FX_CAP = (0.85, 1.30)     # the direct factor is clamped to this range; it never compounds across shots


def reaction_factor(react_ms):
    return pwl(RT_CURVE, react_ms)


def ease_factors(pace_kmh, react_ms, height, kick=0.0, v_req=0.0, set_f=0, stretch=False,
                 dist_net_cm=1200.0, floating=False):
    f = {
        "pace": pwl(E_PACE, pace_kmh),
        "reaction": reaction_factor(react_ms),
        "height": pwl(E_HEIGHT, height),
        "kick": pwl(E_KICK, abs(kick)),
        "movement": pwl(E_RUN, v_req) * (E_SET_BONUS if set_f >= 15 else 1.0) * (E_STRETCH if stretch else 1.0),
        "position": E_NET_TIME if (dist_net_cm < 400 and react_ms >= 450) else 1.0,
        "floating": E_FLOAT if floating else 1.0,
    }
    return f


def rating_factor(stat):
    """Timing rating (hand stat for groundstrokes, Volley for volleys, Return for returns): 0.80..1.20."""
    return 0.80 + 0.40 * clamp(stat, 0.0, 1.0)


def window_halfwidths(pace_kmh, react_ms, height, kick=0.0, v_req=0.0, set_f=0, stretch=False,
                      dist_net_cm=1200.0, floating=False, stat=0.5, opp_timing="Good", opp_scale=1.0):
    """(perfect half-width, good half-width, total ease multiplier) in frames.
    opp_scale scales the direct opponent term's distance from 1 (1.0 = the proposal, 0 = off)."""
    f = ease_factors(pace_kmh, react_ms, height, kick, v_req, set_f, stretch, dist_net_cm, floating)
    e = 1.0
    for v in f.values():
        e *= v
    opp = 1.0 + (OPP_TIMING_FX[opp_timing] - 1.0) * opp_scale
    opp = clamp(opp, *OPP_FX_CAP)
    e *= opp * rating_factor(stat)
    return (clamp(PERFECT_HALF_BASE * e, PERFECT_MIN, PERFECT_MAX),
            clamp(GOOD_HALF_BASE * e, GOOD_MIN, GOOD_MAX), e)


HUMAN_SIGMA_F = 3.4          # sd of a human's release error in frames (judgement, see spec section 5)


def p_window(half, sigma=HUMAN_SIGMA_F):
    """P(|release error| <= half) for a normal release error; release frames are whole frames, so the
    half-width is widened by half a frame (a half-width of 0.5 = only the exact frame)."""
    return math.erf((half + 0.5) / (sigma * math.sqrt(2.0)))


def timing_outcome(rng, perfect_half, good_half, sigma=HUMAN_SIGMA_F):
    e = abs(rng.gauss(0.0, sigma))
    if e <= perfect_half + 0.5:
        return "Perfect"
    if e <= good_half + 0.5:
        return "Good"
    if e <= good_half + 4.5:
        return "Poor"
    return "Mistimed"


# =========================================================================== speed stack (forehand launch mph)

BASE_MPH = {"Flat": 75.5, "TopSpin": 70.5, "Slice": 59.0, "Lob": 50.0}
RATING_MPH = (16.0, 5.0)      # mph per unit of (power stat - 0.40) and (hand stat - 0.40)
HOLD_MPH = {"Finesse": -7.0, "Medium": 0.0, "Powerful": 5.0, "Rushed": -2.0, "Overcharge": 11.5}
TIMING_MPH = {"Perfect": 3.0, "Good": 0.0, "Poor": -4.0, "Mistimed": -9.0}
SKILL_MPH = 2.0               # a pace skill (InstantRocket / HighlyFlammable class) on Powerful+ swings
FATIGUE_MPH = 6.0             # mph lost at vigor 0
NOISE_MPH = 1.7               # execution spread (sd)
CAP_SOFTNESS = 0.30           # above the grade cap only 30 % of the excess survives
SPIN_MPH = {"Flat": 0.0, "TopSpin": 0.0, "Slice": 0.0, "Lob": 0.0}


def stack_speed(cls, grade, hold, timing, power_stat, hand_stat, vigor=1.0, skill=False, noise=0.0):
    """Launch speed (mph) of a groundstroke and the stack terms (dict).  noise = the execution draw (mph)."""
    terms = {
        "base": BASE_MPH[cls],
        "ratings": RATING_MPH[0] * (power_stat - 0.40) + RATING_MPH[1] * (hand_stat - 0.40),
        "grade": GRADE_FX[grade]["pace"],
        "hold": HOLD_MPH[hold],
        "timing": TIMING_MPH[timing],
        "skill": SKILL_MPH if (skill and hold in ("Powerful", "Overcharge")) else 0.0,
        "fatigue": -FATIGUE_MPH * (1.0 - vigor),
        "noise": noise,
    }
    if cls in ("Slice", "Lob"):          # pace stack for these shots is half as steep
        for k in ("ratings", "grade", "hold", "timing", "skill"):
            terms[k] *= 0.5
    v = sum(terms.values())
    cap = GRADE_FX[grade]["cap"]
    if cap is not None and cls in ("Flat", "TopSpin"):
        cap_c = cap - (0.0 if cls == "Flat" else 4.0)
        if v > cap_c:
            v = cap_c + (v - cap_c) * CAP_SOFTNESS
    return v, terms


# =========================================================================== power swing timing (frames)

CHARGE = {"medium_from": 8, "powerful_from": 36, "full_at": 48, "overcharge_wait": 12, "overcharge_hold_max": 40}
RELEASE_LEAD = 20             # perfect release 20 frames before contact (kept)
AUTO_COMMIT = 12              # retail auto-commit lead (PT+0x740)


def hold_reached(frames_pressed_before_contact, set_f):
    """Tier the meter reaches if the player presses `frames_pressed_before_contact` frames before contact and
    releases at the perfect lead.  Overcharge needs the full meter plus `overcharge_wait` frames set and
    waiting (set_f = frames planted before contact)."""
    held = frames_pressed_before_contact - RELEASE_LEAD
    c = CHARGE
    if held >= c["full_at"] + c["overcharge_wait"] and set_f >= c["overcharge_wait"] + RELEASE_LEAD:
        return "Overcharge"
    if held >= c["powerful_from"]:
        return "Powerful"
    if held >= c["medium_from"]:
        return "Medium"
    return "Finesse"


# =========================================================================== situations (Monte Carlo)

class Situation:
    __slots__ = ("pace", "frames", "react_ms", "run_cm", "v_req", "height", "depth_x", "set_f", "stretch",
                 "kick", "floating", "dist_net_cm")


# Assumed distributions of the incoming rally ball (spec section 2, 'situation assumptions').
SIT = {
    "pace_mph_mean": 72.0, "pace_mph_sd": 9.0,          # opponent's launch speed (tour average 73-76 mph, TDI)
    "short_share": 0.10,                                # share of short / floating balls (sitters candidates)
    "wide_scale_cm": 230.0,                             # exponential scale of the lateral run
    "height_mean": 105.0, "height_sd": 28.0,
    "deep_mean": 100.0, "deep_sd": 90.0,                # contact depth behind own baseline, cm
    "kick_share": 0.25,                                 # heavy topspin incoming
}


def sample_situation(rng, sit=SIT, opp_pace_mph=None):
    s = Situation()
    short = rng.random() < sit["short_share"]
    pace = opp_pace_mph if opp_pace_mph is not None else rng.gauss(sit["pace_mph_mean"], sit["pace_mph_sd"])
    if short:
        pace = min(pace, rng.uniform(40.0, 66.0))
    pace = clamp(pace, 35.0, 120.0)
    # pace at contact after flight and bounce (game-model ratio ~0.55-0.6 of launch for a deep rally ball)
    s.pace = kmh(pace) * (0.58 if not short else 0.62)
    dist = 23.0 if not short else 17.0
    v_avg = kmh(pace) / 3.6 * 0.70
    s.frames = int(FPS * (dist / v_avg + (0.30 if not short else 0.45)))
    s.react_ms = s.frames * 1000.0 / FPS
    s.run_cm = rng.expovariate(1.0 / sit["wide_scale_cm"]) * (0.6 if short else 1.0)
    avail = max(0.2, s.frames / FPS - 0.30)
    s.v_req = s.run_cm / 100.0 / avail
    s.stretch = s.v_req > 5.2 or s.run_cm > 380
    s.kick = rng.uniform(0.3, 0.5) if rng.random() < sit["kick_share"] else rng.uniform(0.0, 0.25)
    h = rng.gauss(sit["height_mean"] + 45.0 * max(0.0, s.kick - 0.25), sit["height_sd"])
    if short:
        h = rng.gauss(110.0, 18.0)
    s.height = clamp(h, 15.0, 230.0)
    s.depth_x = rng.gauss(sit["deep_mean"], sit["deep_sd"]) if not short else rng.gauss(-250.0, 120.0)
    slack = s.frames - 18 - s.run_cm / 100.0 / 6.0 * FPS
    s.set_f = int(max(0.0, slack - 12))
    s.floating = short and pace < 55
    s.dist_net_cm = 1188.0 + s.depth_x
    return s


# =========================================================================== players and policies

ARCH = {   # rating sheets: serve return forehand backhand volley power speed stamina
    "average pro": dict(serve=51, ret=54, fh=54, bh=54, volley=50, power=54, speed=55, stamina=55),
    "elite all-rounder": dict(serve=80, ret=82, fh=85, bh=80, volley=72, power=80, speed=82, stamina=85),
    "pace specialist": dict(serve=85, ret=70, fh=95, bh=75, volley=60, power=100, speed=72, stamina=80),
}


class Player:
    def __init__(self, name, r, skills=(), style=None):
        self.name, self.r = name, dict(r)
        self.s = {k: new_stat(v) for k, v in r.items()}
        self.floor = {k: floor_penalty(v) for k, v in r.items()}
        self.skills = set(skills)
        self.style = style or {}


def policy_forehand(rng, p, sit, grade, overcharge_try=0.8):
    """Shot class and hold chosen by a competent human: harder when the set-up allows it."""
    style = p.style
    flat_bias = style.get("flat", 0.35)
    slice_bias = style.get("slice", 0.12)
    u = rng.random()
    if grade in ("Bad", "VeryBad"):
        cls = "Slice" if u < 0.35 + slice_bias else ("TopSpin" if u < 0.9 else "Lob")
    elif grade == "Tee-off":
        cls = "Flat" if u < 0.55 + flat_bias else "TopSpin"
    else:
        cls = "Flat" if u < flat_bias else ("Slice" if u < flat_bias + slice_bias else "TopSpin")
    # press as soon as the ball is read: reaction ~ 15 frames after the opponent's contact
    press_lead = sit.frames - 15
    want = "Powerful" if grade in ("Tee-off", "VeryGood", "Good") else "Medium"
    if grade in ("Normal",) and rng.random() < 0.4:
        want = "Powerful"
    reach = hold_reached(press_lead, sit.set_f)
    order = ["Finesse", "Medium", "Powerful", "Overcharge"]
    if reach == "Overcharge" and grade in ("Tee-off", "VeryGood") and rng.random() < overcharge_try:
        hold = "Overcharge"
    elif order.index(min(reach, "Powerful", key=order.index)) >= order.index(want):
        hold = want
    else:
        hold = "Rushed" if want == "Powerful" else reach
    return cls, hold


def forehand_shot(rng, p, sit, opp_timing="Good", opp_scale=1.0, overcharge_try=0.8):
    g, q, _ = grade_of(sit.frames, sit.v_req, sit.run_cm, sit.height, sit.pace, sit.depth_x, sit.set_f,
                       sit.stretch, sit.kick)
    cls, hold = policy_forehand(rng, p, sit, g, overcharge_try)
    hp, hg, e = window_halfwidths(sit.pace, sit.react_ms, sit.height, sit.kick, sit.v_req, sit.set_f,
                                  sit.stretch, sit.dist_net_cm, sit.floating, p.s["fh"], opp_timing, opp_scale)
    if hold == "Overcharge":            # biggest swing, smallest margin: Perfect window halved
        hp *= 0.5
    if hold == "Rushed":
        hp, hg = hp * 0.7, hg * 0.8
    t = timing_outcome(rng, hp, hg)
    vig = 1.0
    v, terms = stack_speed(cls, g, hold, t, p.s["power"], p.s["fh"], vig,
                           skill="pace" in p.skills, noise=rng.gauss(0.0, NOISE_MPH))
    return dict(grade=g, cls=cls, hold=hold, timing=t, mph=v, hp=hp, hg=hg)


# =========================================================================== serve

SERVE = {
    "comfort_base": 94.0, "comfort_serve": 22.0, "comfort_power": 10.0,   # mph
    "range_base": 12.0, "range_power": 14.0,                              # extra mph at full effort
    "p_in_comfort": 0.70, "p_in_serve": 0.08,                             # P(in) at comfort speed
    "slope_pp_per_mph": 0.012,                                            # in-rate lost per mph above comfort
    "second_drop": 24.0, "second_p_in": 0.93, "big_second": 10.0,         # mph slower, P(in), big 2nd bonus
    "stamina_cost": (1.0, 3.0),                                           # vigor units per serve: a + b e^2
}


def serve_comfort(p):
    S = SERVE
    return S["comfort_base"] + S["comfort_serve"] * p.s["serve"] + S["comfort_power"] * p.s["power"]


def first_serve(rng, p, effort, vigor=1.0, gauge="Good"):
    """Speed (mph), in? , stamina cost.  effort 0..1 (hold / gauge commitment)."""
    S = SERVE
    vc = serve_comfort(p)
    rng_mph = S["range_base"] + S["range_power"] * p.s["power"]
    gauge_mph = {"Perfect": 2.0, "Good": 0.0, "Poor": -5.0, "Mistimed": -10.0}[gauge]
    v = vc + effort ** 1.4 * rng_mph + gauge_mph - 6.0 * (1 - vigor) + rng.gauss(0.0, 2.0)
    p_in = S["p_in_comfort"] + S["p_in_serve"] * (p.s["serve"] - 0.5) - S["slope_pp_per_mph"] * max(0.0, v - vc)
    p_in += {"Perfect": 0.04, "Good": 0.0, "Poor": -0.12, "Mistimed": -0.35}[gauge]
    p_in -= 0.10 * p.floor["serve"] + 0.08 * (1 - vigor)
    p_in = clamp(p_in, 0.05, 0.95)
    cost = S["stamina_cost"][0] + S["stamina_cost"][1] * effort ** 2
    return v, rng.random() < p_in, cost, p_in


def second_serve(rng, p, big=False, vigor=1.0):
    S = SERVE
    vc = serve_comfort(p) - S["second_drop"]
    bonus = S["big_second"] * p.s["serve"] * min(1.0, p.s["stamina"] + 0.3) if big else 0.0
    v = vc + bonus + rng.gauss(0.0, 2.0)
    p_in = S["second_p_in"] + 0.04 * (p.s["serve"] - 0.5) - 0.012 * bonus - 0.12 * p.floor["serve"]
    p_in -= 0.06 * (1 - vigor)
    p_in = clamp(p_in, 0.5, 0.99)
    return v, rng.random() < p_in, (1.0 + (1.5 if big else 0.0)), p_in


def serve_react_ms(v_mph):
    """Time from the serve contact to the return contact (ms): 500 ms at 200 km/h (O'Donoghue & Liddle 1998),
    scaling with distance / speed (judgement for the exponent)."""
    return 500.0 * (200.0 / kmh(v_mph)) ** 0.9


def return_quality(rng, ret, serve_mph, placement=0.5, opp_timing="Good", opp_scale=1.0, second=False):
    """Returner outcome: 'unreturned' | 'weak' | 'neutral' | 'good', and the return's timing grade."""
    rt = serve_react_ms(serve_mph)
    pace_contact = kmh(serve_mph) * 0.62
    hp, hg, e = window_halfwidths(pace_contact, rt, 115.0, 0.35 if second else 0.1, 1.5 + 3.0 * placement, 4,
                                  placement > 0.75, 1300.0, False, ret.s["ret"], opp_timing, opp_scale)
    t = timing_outcome(rng, hp, hg)
    reach = 0.95 - 0.30 * max(0.0, placement - 0.6) / 0.4 * (1.15 - 0.3 * ret.s["speed"])
    if rng.random() > reach:
        return "unreturned", t
    err = {"Perfect": 0.02, "Good": 0.07, "Poor": 0.30, "Mistimed": 0.75}[t] + 0.15 * ret.floor["ret"]
    if rng.random() < err:
        return "unreturned", t
    return ({"Perfect": "good", "Good": "neutral", "Poor": "weak", "Mistimed": "weak"}[t]), t
