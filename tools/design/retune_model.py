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
NEW_CURVE = [(0, 0.0), (30, 0.18), (50, 0.40), (60, 0.52), (70, 0.64), (80, 0.76), (90, 0.88), (100, 1.0)]
FLOOR_RATING = 60.0        # below this rating a floor penalty starts
FLOOR_POWER = 1.3          # penalty shape exponent


def retail_stat(stat, rating):
    return pwl([(0, 0.0)] + RETAIL_CURVES[stat], rating) if rating > 30 else 0.0


def new_stat(rating):
    return pwl(NEW_CURVE, rating)


def floor_penalty(rating):
    """0 at rating >= 60, rising to 1 at rating 0: the extra cost of a dumped rating (rating 25 -> 0.50)."""
    return 0.0 if rating >= FLOOR_RATING else ((FLOOR_RATING - rating) / FLOOR_RATING) ** FLOOR_POWER


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
P_TIME_VOLLEY = [(12, 3.6), (18, 2.4), (26, 1.2), (36, 0.3), (48, 0.0)]   # volleys live at short times
P_PACE_VOLLEY = [(60, 0.0), (80, 0.4), (100, 1.0), (120, 1.8), (140, 2.6)]
P_RUN = [(0.0, 0.0), (0.28, 0.0), (0.55, 1.0), (0.80, 2.4), (1.0, 4.0)]     # on v_req / own top speed
P_LOW = [(20, 2.4), (40, 1.7), (60, 0.9), (80, 0.0)]
P_HIGH = [(130, 0.0), (165, 0.8), (200, 2.0)]
P_PACE = [(45, 0.0), (60, 0.3), (75, 0.9), (90, 1.7), (110, 2.8)]
P_DEEP = [(150, 0.0), (300, 0.5), (500, 1.4)]
P_KICK = [(0.20, 0.0), (0.40, 0.45), (0.55, 0.70)]
STRETCH_PTS = 1.4
TOP_SPEED_REF = 7.5          # m/s: v_req is divided by the player's top speed; callers rescale v_req
UNSET_PTS = 0.4             # still moving at contact (set_f < 6)
INSIDE_BONUS = -0.4         # inside the court with time (depth_x < -150 and frames >= 60)
GRADE_EDGES = [0.8, 2.0, 3.4, 5.0]          # VeryGood | Good | Normal | Bad | VeryBad
TEEOFF = {"pace_max": 52.0, "h_lo": 80.0, "h_hi": 140.0, "frames_min": 80, "run_max": 150.0,
          "set_min": 15, "depth_max": 150.0, "score_max": 0.5}


def grade_points(frames, v_req, run_cm, height, pace, depth_x, set_f, stretch, kick=0.0, volley=False):
    pts = {
        "time": pwl(P_TIME_VOLLEY if volley else P_TIME, frames),
        "run": pwl(P_RUN, v_req / TOP_SPEED_REF),
        "height": pwl(P_LOW, height) + pwl(P_HIGH, height),
        "pace": pwl(P_PACE_VOLLEY if volley else P_PACE, pace),
        "position": 0.0 if volley else pwl(P_DEEP, depth_x) + (INSIDE_BONUS if depth_x < -150 and frames >= 60 else 0.0),
        "stretch": STRETCH_PTS if stretch else 0.0,
        "unset": UNSET_PTS if (set_f < 6 and not volley) else 0.0,
        "kick": pwl(P_KICK, abs(kick)),
    }
    return pts


def grade_of(frames, v_req, run_cm, height, pace, depth_x, set_f, stretch, kick=0.0, volley=False):
    """(grade name, score, points).  Tee-off needs a VeryGood score AND every sitter condition (a volley
    Tee-off is the put-away: slow, above the net, time to watch it)."""
    pts = grade_points(frames, v_req, run_cm, height, pace, depth_x, set_f, stretch, kick, volley)
    if volley:
        q = max(0.0, sum(pts.values()))
        if q <= 0.5 and pace <= 75.0 and height >= 110.0 and frames >= 30 and not stretch:
            return "Tee-off", q, pts
        for g, edge in zip(GRADES[1:], GRADE_EDGES):
            if q < edge:
                return g, q, pts
        return "VeryBad", q, pts
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
E_KICK = [(0.20, 1.0), (0.40, 0.92), (0.55, 0.86)]
E_RUN = [(0.0, 1.05), (0.28, 1.0), (0.55, 0.86), (0.80, 0.70), (1.0, 0.58)]  # on v_req / own top speed
E_SET_BONUS = 1.08            # planted for >= 15 frames
E_STRETCH = 0.80
E_NET_TIME = 1.20             # inside 4 m of the net with reaction time >= 450 ms (a sitter at the net)
E_FLOAT = 1.12                # floating ball: apex well above the net and slow (lob that does not go deep)
# Reaction-time threshold (ms from the opponent's contact to own contact, minus nothing): no effect in normal
# rallies, a steep ramp close to human limits.  Sourced anchors: volley reaction ~205-226 ms (Chow et al. 1999),
# ~500 ms available against a 200 km/h serve (O'Donoghue & Liddle 1998); the shape is a judgement.
RT_CURVE = [(200, 0.22), (250, 0.32), (300, 0.45), (350, 0.58), (400, 0.70), (450, 0.80), (500, 0.88), (550, 0.94),
            (650, 1.0)]
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
        "movement": pwl(E_RUN, v_req / TOP_SPEED_REF) * (E_SET_BONUS if set_f >= 15 else 1.0) * (E_STRETCH if stretch else 1.0),
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


def p_window(half, sigma=None):
    """P(|release error| <= half) for a normal release error; release frames are whole frames, so the
    half-width is widened by half a frame (a half-width of 0.5 = only the exact frame)."""
    sigma = HUMAN_SIGMA_F if sigma is None else sigma
    return math.erf((half + 0.5) / (sigma * math.sqrt(2.0)))


def timing_outcome(rng, perfect_half, good_half, sigma=None):
    e = abs(rng.gauss(0.0, HUMAN_SIGMA_F if sigma is None else sigma))
    if e <= perfect_half + 0.5:
        return "Perfect"
    if e <= good_half + 0.5:
        return "Good"
    if e <= good_half + 4.5:
        return "Poor"
    return "Mistimed"


# =========================================================================== speed stack (forehand launch mph)

BASE_MPH = {"Flat": 74.0, "TopSpin": 69.0, "Slice": 60.0, "Lob": 49.0}
RATING_MPH = (20.0, 5.0)      # mph per unit of (power stat - 0.50) and (hand stat - 0.50)
HOLD_MPH = {"Finesse": -7.0, "Medium": 0.0, "Powerful": 5.0, "Rushed": -2.0, "Overcharge": 13.0}
TIMING_MPH = {"Perfect": 3.0, "Good": 0.0, "Poor": -4.0, "Mistimed": -9.0}
SKILL_MPH = 2.0               # a pace skill (InstantRocket / HighlyFlammable class) on Powerful+ swings
FATIGUE_MPH = 6.0             # mph lost at vigor 0
NOISE_MPH = 1.7               # execution spread (sd)
CAP_SOFTNESS = 0.30           # above the grade cap only 30 % of the excess survives


def stack_speed(cls, grade, hold, timing, power_stat, hand_stat, vigor=1.0, skill=False, noise=0.0):
    """Launch speed (mph) of a groundstroke and the stack terms (dict).  noise = the execution draw (mph)."""
    terms = {
        "base": BASE_MPH[cls],
        "ratings": RATING_MPH[0] * (power_stat - 0.50) + RATING_MPH[1] * (hand_stat - 0.50),
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
    vr = sit.v_req * TOP_SPEED_REF / (RALLY["max_run_base"] + RALLY["max_run_speed"] * p.s["speed"])
    g, q, _ = grade_of(sit.frames, vr, sit.run_cm, sit.height, sit.pace, sit.depth_x, sit.set_f,
                       sit.stretch, sit.kick)
    cls, hold = policy_forehand(rng, p, sit, g, overcharge_try)
    hp, hg, e = window_halfwidths(sit.pace, sit.react_ms, sit.height, sit.kick, vr, sit.set_f,
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
    "comfort_base": 80.0, "comfort_serve": 34.0, "comfort_power": 8.0,   # mph
    "range_base": 14.0, "range_power": 20.0,                              # extra mph at full effort
    "p_in_comfort": 0.70, "p_in_serve": 0.12,                             # P(in) at comfort speed
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
    p_in -= 0.50 * p.floor["serve"] + 0.08 * (1 - vigor)
    p_in = clamp(p_in, 0.05, 0.95)
    cost = S["stamina_cost"][0] + S["stamina_cost"][1] * effort ** 2
    return v, rng.random() < p_in, cost, p_in


def second_serve(rng, p, big=False, vigor=1.0):
    S = SERVE
    vc = serve_comfort(p) - S["second_drop"]
    bonus = S["big_second"] * p.s["serve"] * min(1.0, p.s["stamina"] + 0.3) if big else 0.0
    v = vc + bonus + rng.gauss(0.0, 2.0)
    p_in = S["second_p_in"] + 0.04 * (p.s["serve"] - 0.5) - 0.006 * bonus - 0.55 * p.floor["serve"]
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
    reach = 0.97 - 0.40 * max(0.0, placement - 0.5) / 0.5 * (1.15 - 0.3 * ret.s["speed"])
    if rng.random() > reach:
        return "unreturned", t
    err = {"Perfect": 0.03, "Good": 0.12, "Poor": 0.45, "Mistimed": 0.85}[t] * clamp(1.9 - 1.5 * e, 0.4, 1.8)
    err += 0.30 * ret.floor["ret"]
    if rng.random() < err:
        return "unreturned", t
    return ({"Perfect": "good", "Good": "neutral", "Poor": "weak", "Mistimed": "weak"}[t]), t


# =========================================================================== rally / match simulation

RALLY = {
    "e_timing": {"Perfect": 0.012, "Good": 0.035, "Poor": 0.16, "Mistimed": 0.45},
    "pace_margin": {"Flat": 78.0, "TopSpin": 84.0, "Slice": 68.0, "Lob": 60.0},   # mph where the pace term starts
    "pace_err": 0.006,                 # error per mph above the margin speed
    "margin_hand": 10.0,                # margin speed added per unit of hand stat
    "kick": {"Flat": 0.08, "TopSpin": 0.20, "Slice": 0.0, "Lob": 0.2},
    "kick_hand": 0.18,                  # topspin kick added per unit of hand stat (spin scales with FH/BH rating)
    "low": {"Slice": 1.0},              # slice stays low: the receiver's contact height drops
    "max_run_base": 5.7, "max_run_speed": 2.9,          # m/s reachable: base + per unit of Speed stat
    "floor_err": 0.20,
    "pass_err": 0.07,
    "low_drive_err": 0.004,             # per mph above 70 when driving a ball below 60 cm (x depth below 60 / 30)                   # added error for a passing shot against a net player                  # error added per unit of floor penalty of the stroke's rating
    "vigor_cost": {"Finesse": 0.002, "Medium": 0.004, "Powerful": 0.008, "Rushed": 0.008, "Overcharge": 0.018},
    "run_cost": 0.0012,                 # vigor per m/s of required run speed
    "recover_point": 0.022, "recover_set": 0.12,
    "net_rush": {"volley_style": 0.55, "approach_on_short": 0.35},
}


SLICE_DROP_CM = 72.0      # a slice reaches the receiver this much lower than a neutral ball
PUTAWAY = {"Tee-off": 0.75, "VeryGood": 0.50, "Good": 0.30, "Normal": 0.12}   # volley winner chance


class Ball:
    __slots__ = ("pace", "depth", "width", "kick", "low", "timing", "short", "hitter_net")

    def __init__(self, pace, depth, width, kick, low, timing, short=False, hitter_net=False):
        self.pace, self.depth, self.width, self.kick, self.low = pace, depth, width, kick, low
        self.timing, self.short, self.hitter_net = timing, short, hitter_net


def situation_from_ball(rng, b, at_net=False):
    s = Situation()
    pace = clamp(b.pace, 30.0, 130.0)
    dist = (23.0 if not b.short else 17.0) if not at_net else 13.0
    s.pace = kmh(pace) * (0.58 if not at_net else 0.80)   # a volley meets the ball before the bounce
    v_avg = kmh(pace) / 3.6 * (0.70 if not at_net else 0.85)
    s.frames = int(FPS * (dist / v_avg + ((0.30 if not b.short else 0.45) if not at_net else 0.0)))
    s.react_ms = s.frames * 1000.0 / FPS
    s.run_cm = max(0.0, 30.0 + 640.0 * b.width + rng.gauss(0.0, 70.0)) * (0.55 if at_net else 1.0)
    avail = max(0.15, s.frames / FPS - 0.30)
    s.v_req = s.run_cm / 100.0 / avail
    s.stretch = s.v_req > 5.2 or s.run_cm > 380
    s.kick = b.kick
    if at_net:
        h = rng.gauss(95.0, 30.0) - (35.0 if b.low else 0.0)
    elif b.short:
        h = rng.gauss(112.0, 18.0)
    else:
        h = rng.gauss(100.0 + 70.0 * max(0.0, b.kick - 0.2), 22.0) - (SLICE_DROP_CM if b.low else 0.0)
    s.height = clamp(h, 12.0, 230.0)
    s.depth_x = (-1188.0 + 250.0 + rng.gauss(0, 80)) if at_net else (
        rng.gauss(-250.0, 100.0) if b.short else 30.0 + 260.0 * b.depth + rng.gauss(0.0, 60.0))
    slack = s.frames - 18 - s.run_cm / 100.0 / 6.0 * FPS
    s.set_f = int(max(0.0, slack - 12))
    s.floating = b.short and pace < 55
    s.dist_net_cm = 1188.0 + s.depth_x
    return s


class MatchPlayer(Player):
    def __init__(self, name, r, style=None, skills=()):
        Player.__init__(self, name, r, skills, style)
        self.vigor = 1.0

    def vmax(self):
        return 0.75 + 0.25 * self.s["stamina"]

    def spend(self, x):
        self.vigor = max(0.0, self.vigor - x / (0.6 + 0.8 * self.s["stamina"]))


def hit(rng, p, b, at_net, prm):
    """One shot.  Returns (outcome, ball or None, info).  outcome: 'in' | 'error' | 'winner' (opponent
    cannot reach is decided by the caller)."""
    R = RALLY
    sit = situation_from_ball(rng, b, at_net)
    if at_net:          # at the net the racket reach and a lunge cover the first 130 cm
        sit.run_cm = max(0.0, sit.run_cm - 130.0)
        sit.v_req = sit.run_cm / 100.0 / max(0.15, sit.frames / FPS - 0.15)
    vmax0 = (R["max_run_base"] + R["max_run_speed"] * p.s["speed"]) * (0.80 + 0.20 * p.vigor)
    vr = sit.v_req * TOP_SPEED_REF / vmax0          # required speed as felt by this player
    g, q, _ = grade_of(sit.frames, vr, sit.run_cm, sit.height, sit.pace, sit.depth_x, sit.set_f,
                       sit.stretch or vr > 5.2, sit.kick, volley=at_net)
    # reach: the player cannot get there at all
    vmax = (R["max_run_base"] + R["max_run_speed"] * p.s["speed"]) * (0.80 + 0.20 * p.vigor)
    if sit.v_req > vmax:
        return "unreached", None, {"grade": "VeryBad", "timing": None}
    wing = "fh" if rng.random() < 0.55 else "bh"
    stat = p.s["volley"] if at_net else p.s[wing]
    flo = p.floor["volley"] if at_net else p.floor[wing]
    if not at_net and sit.height < 50:      # a pick-up off the ground is touch: Volley rating shares it
        stat = 0.6 * stat + 0.4 * p.s["volley"]
        flo = 0.6 * flo + 0.4 * p.floor["volley"]
    hp, hg, e = window_halfwidths(sit.pace, sit.react_ms, sit.height, sit.kick, vr, sit.set_f, sit.stretch,
                                  sit.dist_net_cm, sit.floating, stat, b.timing, prm.get("opp_scale", 1.0))
    hp *= 0.75 + 0.25 * p.vigor
    hg *= 0.75 + 0.25 * p.vigor
    st = p.style
    if at_net:
        cls, hold = ("Flat", "Powerful") if g in ("Tee-off", "VeryGood") else ("Slice" if rng.random() < 0.5 else "Flat",
                                                                             "Medium")
    else:
        cls, hold = policy_forehand(rng, p, sit, g)
        if rng.random() < st.get("topspin_more", 0.0) and cls == "Flat" and g not in ("Tee-off",):
            cls = "TopSpin"
        if rng.random() < st.get("slice_more", 0.0) and cls != "Slice" and g not in ("Tee-off", "VeryGood"):
            cls = "Slice"
    if hold == "Overcharge":
        hp *= 0.5
    if hold == "Rushed":
        hp, hg = hp * 0.7, hg * 0.8
    t = timing_outcome(rng, hp, hg)
    power_stat = p.s["power"]
    v, _ = stack_speed(cls, g, hold, t, power_stat, stat, p.vigor, "pace" in p.skills, rng.gauss(0.0, NOISE_MPH))
    if at_net:
        v = min(v, 70.0 + 25.0 * p.s["volley"] + (12.0 if g in ("Tee-off", "VeryGood") else 0.0))
    fx = GRADE_FX[g]
    margin = R["pace_margin"][cls] + R["margin_hand"] * stat
    if at_net:          # a volley redirects pace: no pace-margin term, a forgiving timing table
        err = fx["err"] * R["e_timing"][t] * 0.6 + fx["err_add"] * 0.6
    else:
        err = fx["err"] * (R["e_timing"][t] * (2.0 if hold == "Overcharge" else 1.0)
                           + R["pace_err"] * max(0.0, v - margin)) + fx["err_add"]
    if not at_net and sit.height < 60 and cls in ("Flat", "TopSpin"):   # driving a low ball: it must be lifted
        err += R["low_drive_err"] * max(0.0, v - 70.0) * (60.0 - sit.height) / 30.0
    if b.hitter_net and not at_net:     # passing: the lanes past a net player are narrow
        err += R["pass_err"]
    err += R["floor_err"] * flo + 0.12 * (1.0 - p.vigor) ** 1.5
    if at_net and sit.height < 50:            # half-volley / ball at the feet
        err += 0.08 * (1.2 - stat)
    p.spend(R["vigor_cost"][hold] + R["run_cost"] * sit.v_req)
    info = {"grade": g, "timing": t, "cls": cls, "hold": hold, "mph": v}
    if rng.random() < err:
        return "error", None, info
    if at_net and t in ("Perfect", "Good"):
        if rng.random() < PUTAWAY.get(g, 0.0) * (0.7 + 0.3 * stat) * (1.0 if t == "Perfect" else 0.8):
            return "putaway", None, info
    tb = {"Perfect": 0.12, "Good": 0.0, "Poor": -0.15, "Mistimed": -0.3}[t]
    depth = clamp(0.62 - fx["depth_cm"] / 600.0 + 0.5 * tb + rng.gauss(0.0, 0.12) + (0.08 if cls == "TopSpin" else 0.0),
                  0.0, 1.0)
    width = clamp(0.32 + fx["aim"] + 0.3 * tb + 0.18 * stat + rng.gauss(0.0, 0.18)
                  + (0.10 if at_net else 0.0), 0.0, 1.0)
    kick = R["kick"][cls] * fx["spin"] + (R["kick_hand"] * stat * fx["spin"] if cls == "TopSpin" else 0.0)
    short = depth < 0.12 and not at_net
    nb = Ball(v, depth, width, kick, cls == "Slice", t if t else "Good", short, at_net)
    return "in", nb, info


def play_point(rng, server, receiver, prm):
    """Returns (winner, rally_shots, end, end_timing).  end in ace_unret | winner | error | unreached | df."""
    p_eff = prm.get("serve_effort", 0.4)
    big_eff = rng.random() < server.style.get("max_serve", 0.0)
    e = 1.0 if big_eff else clamp(rng.betavariate(2, 3) * (p_eff / 0.4), 0.0, 1.0)
    g = timing_outcome(rng, *window_halfwidths(60, 700, 130, 0, 0, 30, False, 1200, True, server.s["serve"])[:2])
    v, ok, cost, _ = first_serve(rng, server, e, server.vigor, g)
    server.spend(cost * 0.004)
    second = False
    if not ok:
        second = True
        v, ok, cost, _ = second_serve(rng, server, big=server.s["serve"] > 0.7 and server.vigor > 0.6, vigor=server.vigor)
        server.spend(cost * 0.004)
        if not ok:
            return receiver, 1, "df", None
    placement = clamp(rng.random() * (0.8 if second else 1.0) * (0.75 + 0.25 * server.s["serve"]) + 0.15 * server.s["serve"], 0.0, 1.0)
    q, rt = return_quality(rng, receiver, v, placement, g, prm.get("opp_scale", 1.0), second)
    if q == "unreturned":
        return server, 1, "ace_unret", rt
    # a slow serve can be attacked: the return gains pace, depth and angle (through the ball, spec s8)
    attack = clamp((100.0 - v) / 30.0, 0.0, 1.0) if q != "weak" else 0.0
    pace = ({"good": 74.0, "neutral": 68.0, "weak": 55.0}[q] + 12.0 * receiver.s["ret"] + 6.0 * receiver.s["power"]
            + 10.0 * attack)
    depth = {"good": 0.7, "neutral": 0.5, "weak": 0.15}[q] + 0.2 * attack
    width = (0.3 if q != "good" else 0.5) + 0.25 * attack
    ball = Ball(pace, clamp(depth, 0.0, 1.0), width, 0.15, False, rt, short=q == "weak")
    hitter, other = server, receiver
    at_net = {server: False, receiver: False}
    if rng.random() < server.style.get("serve_volley", 0.0):
        at_net[server] = True
    shots = 2
    while shots < 80:
        out, nb, info = hit(rng, hitter, ball, at_net[hitter], prm)
        if "trace" in prm:
            prm["trace"].append((ball.timing, info["timing"], out))
        if out == "unreached":
            return other, shots, "winner", None
        if out == "putaway":
            return hitter, shots, "winner", None
        if out == "error":
            tm = info["timing"]
            return other, shots, "error", tm
        # net approach decision after a short ball or by style
        if not at_net[hitter] and (ball.short and rng.random() < RALLY["net_rush"]["approach_on_short"] + hitter.style.get("net", 0.0)):
            at_net[hitter] = True
        nb.hitter_net = at_net[hitter]
        if at_net[hitter]:
            nb.pace *= 0.95
        ball = nb
        hitter, other = other, hitter
        shots += 1
    return server, shots, "long", None


def play_match(rng, a, b, prm, sets_to_win=2, games_per_set=6):
    """Best-of-(2*sets_to_win-1) sets with tie-break at games_per_set all.  Returns (winner, stats dict)."""
    a.vigor = b.vigor = 1.0
    sets = {a: 0, b: 0}
    stats = {"points": 0, "shots": 0, "timing_err": 0, "err": 0, "winners": 0, "ace_unret": 0, "df": 0,
             "srv_won": 0}
    server, receiver = a, b

    def point(sv, rc):
        w, n, end, tm = play_point(rng, sv, rc, prm)
        stats["points"] += 1
        stats["shots"] += n
        if end == "error":
            stats["err"] += 1
            if tm in ("Poor", "Mistimed"):
                stats["timing_err"] += 1
        elif end in ("winner",):
            stats["winners"] += 1
        elif end == "ace_unret":
            stats["ace_unret"] += 1
        elif end == "df":
            stats["df"] += 1
        stats["srv_won"] += (w is sv)
        for pl in (sv, rc):
            pl.vigor = min(pl.vmax(), pl.vigor + RALLY["recover_point"] * (0.5 + pl.s["stamina"]))
        return w

    while max(sets.values()) < sets_to_win:
        games = {a: 0, b: 0}
        while True:
            if games[a] == games_per_set and games[b] == games_per_set:
                pts = {a: 0, b: 0}
                k = 0
                while True:
                    sv = server if (k == 0 or ((k - 1) // 2) % 2 == 1) else receiver
                    rc = receiver if sv is server else server
                    pts[point(sv, rc)] += 1
                    k += 1
                    if max(pts.values()) >= 7 and abs(pts[a] - pts[b]) >= 2:
                        break
                games[a if pts[a] > pts[b] else b] += 1
                server, receiver = receiver, server
                break
            pts = {server: 0, receiver: 0}
            while True:
                pts[point(server, receiver)] += 1
                if max(pts.values()) >= 4 and abs(pts[server] - pts[receiver]) >= 2:
                    break
            games[server if pts[server] > pts[receiver] else receiver] += 1
            server, receiver = receiver, server
            if max(games.values()) >= games_per_set and abs(games[a] - games[b]) >= 2:
                break
        sets[a if games[a] > games[b] else b] += 1
        for pl in (a, b):
            pl.vigor = min(pl.vmax(), pl.vigor + RALLY["recover_set"])
    return (a if sets[a] > sets[b] else b), stats


# Build sheets for the abuse check (spec section 9): every sheet spends the same 600 rating points.
BUILDS = {
    "heavy topspin": (dict(serve=70, ret=70, fh=90, bh=80, volley=55, power=70, speed=80, stamina=85),
                      dict(flat=0.15, topspin_more=0.6, slice=0.05)),
    "flat hitter": (dict(serve=75, ret=70, fh=85, bh=80, volley=60, power=95, speed=65, stamina=70),
                    dict(flat=0.6, slice=0.05)),
    "slicer": (dict(serve=65, ret=75, fh=70, bh=85, volley=80, power=65, speed=80, stamina=80),
               dict(flat=0.2, slice=0.4, slice_more=0.4, net=0.3)),
    "big server": (dict(serve=100, ret=60, fh=75, bh=65, volley=70, power=90, speed=60, stamina=80),
                   dict(flat=0.45, max_serve=0.08)),
    "serve-and-volleyer": (dict(serve=90, ret=65, fh=65, bh=60, volley=95, power=75, speed=80, stamina=70),
                           dict(flat=0.35, serve_volley=0.7, net=0.3, max_serve=0.03)),
    "counterpuncher": (dict(serve=60, ret=85, fh=75, bh=80, volley=55, power=55, speed=95, stamina=95),
                       dict(flat=0.15, topspin_more=0.3, slice=0.15)),
    "min-max: no legs (speed, stamina dumped)": (
        dict(serve=100, ret=100, fh=100, bh=100, volley=50, power=100, speed=25, stamina=25), dict(flat=0.5)),
    "min-max: no serve, no volley": (
        dict(serve=25, ret=50, fh=100, bh=100, volley=25, power=100, speed=100, stamina=100), dict(flat=0.45)),
    "min-max: no backhand, no return": (
        dict(serve=100, ret=25, fh=100, bh=25, volley=50, power=100, speed=100, stamina=100), dict(flat=0.5)),
}


def round_robin(builds, matches, seed, prm=None, sets_to_win=2):
    """Win share of each build against every other (both serve orders).  Returns {a: {b: share}}."""
    prm = prm or {}
    rng = random.Random(seed)
    names = list(builds)
    res = {a: {} for a in names}
    for i, a in enumerate(names):
        for b in names[i + 1:]:
            wa = 0
            for m in range(matches):
                A = MatchPlayer(a, builds[a][0], builds[a][1])
                B = MatchPlayer(b, builds[b][0], builds[b][1])
                w, _ = play_match(rng, A, B, prm, sets_to_win) if m % 2 == 0 else play_match(rng, B, A, prm, sets_to_win)
                wa += w.name == a
            res[a][b] = wa / matches
            res[b][a] = 1.0 - wa / matches
    return res


# =========================================================================== placement, drop shots, recovery

DEPTH_TIMING_CM = {"Perfect": -30.0, "Good": 0.0, "Poor": 80.0, "Mistimed": 180.0}
DEPTH_SD_CM = 45.0


def depth_shortfall(grade, timing):
    """Mean and sd (cm) of how far an In groundstroke lands short of the aimed depth.  Replaces the retail
    uniform 0..310 cm DeepDeviation (aiming graphs' Random branch) with a quality-earned value."""
    return max(0.0, GRADE_FX[grade]["depth_cm"] + DEPTH_TIMING_CM[timing]), DEPTH_SD_CM


STICK_MARGIN = [(0.4, 0.55), (0.6, 0.75), (0.8, 0.90), (1.0, 1.0)]   # stick magnitude -> fraction of the quad reach
STICK_ERR = [(0.4, 0.70), (0.6, 0.80), (0.8, 0.92), (1.0, 1.0)]      # and the error multiplier it buys


def stick_margin(mag):
    """(quad-efficiency cap, error multiplier) for a stick push of magnitude mag (0.4 dead zone .. 1)."""
    return pwl(STICK_MARGIN, mag), pwl(STICK_ERR, mag)


def angle_access(depth_x_cm, grade, hand_stat):
    """Largest usable angle as a fraction of the sideline reach (aim quad lateral efficiency): more from inside
    the court and from good grades, scaled by the stroke rating."""
    pos = pwl([(-500, 1.0), (-150, 0.9), (0, 0.8), (200, 0.7), (400, 0.6)], depth_x_cm)
    g = {"Tee-off": 1.0, "VeryGood": 0.95, "Good": 0.85, "Normal": 0.75, "Bad": 0.6, "VeryBad": 0.45}[grade]
    return clamp(pos * g * (0.85 + 0.15 * hand_stat), 0.0, 1.0)


def drop_quality(incoming_kmh, height, grade, timing, touch_stat):
    """Drop shot: landing distance past the net (cm), bounce height (cm), error probability.
    Easy to play off a slow, mid-height ball from inside the court; hard off pace or a low ball."""
    base_land = {"Tee-off": 180, "VeryGood": 220, "Good": 270, "Normal": 330, "Bad": 420, "VeryBad": 520}[grade]
    land = base_land * (1.0 + 0.004 * max(0.0, incoming_kmh - 50.0)) * (1.15 - 0.3 * touch_stat)
    land += {"Perfect": -30, "Good": 0, "Poor": 80, "Mistimed": 160}[timing]
    bounce = 35.0 + 0.25 * max(0.0, land - 200.0) + 0.2 * max(0.0, incoming_kmh - 60.0)
    err = (0.03 + 0.0035 * max(0.0, incoming_kmh - 45.0) + pwl([(20, 0.20), (50, 0.08), (80, 0.0)], height)
           + {"Perfect": 0.0, "Good": 0.03, "Poor": 0.18, "Mistimed": 0.45}[timing]) * GRADE_FX[grade]["err"]
    err *= 1.2 - 0.4 * touch_stat
    return land, bounce, clamp(err, 0.0, 0.95)


RECOVERY = {"Finesse": 8, "Medium": 12, "Powerful": 18, "Rushed": 20, "Overcharge": 26}
RECOVERY_GRADE = {"Tee-off": -2, "VeryGood": 0, "Good": 0, "Normal": 2, "Bad": 5, "VeryBad": 8}


def recovery_frames(hold, grade, stretch=False, vigor=1.0):
    """(frames until a recovery step may start, frames until full-speed movement) after contact.
    Replaces the swing clip's Out window (median 36 frames after a groundstroke, retune-baseline 8a)."""
    lock = RECOVERY[hold] + RECOVERY_GRADE[grade] + (6 if stretch else 0) + int(round(6 * (1.0 - vigor)))
    lock = max(6, lock)
    return lock, lock + 10
