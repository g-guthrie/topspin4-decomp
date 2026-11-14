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
# Structure: docs/design/retune-systems.md s2 (design authority).  A penalty score summed from four inputs the
# engine computes, mapped to six rows.  Thresholds are this spec's tuned values (section 4).

GRADES = ["Tee-off", "VeryGood", "Good", "Normal", "Bad", "VeryBad"]

# Arrival margin: frames the player has been planted at the hit point before contact (planner arrival, S+0xCF0
# family).  30+ : 0, 15-29 : 1, 1-14 : 2, still moving at contact : 3, reach or lunge swing : 4.
ARRIVAL_EDGES = (30, 15, 1)
# Volleys: nobody is "set" at the net, so the margin is the frames since the opponent's contact (S+0xCF0) on a
# volley time scale (retune-systems s2 "volley time scale"; edges are this spec's tuned values).
VOLLEY_ARRIVAL_EDGES = (50, 36, 25)
# Contact height (Ball+0x344), cm: knee, waist, shoulder, head (judgement for an adult player).
KNEE_CM, WAIST_CM, SHOULDER_CM, HEAD_CM = 50.0, 95.0, 145.0, 185.0
# Incoming pace at contact (S+0x770 once written), km/h: slow <= , normal <= , heavy <= , else near reflex limits.
PACE_EDGES = (52.0, 78.0, 100.0)
VOLLEY_PACE_EDGES = (52.0, 80.0, 100.0)
LOW_VIGOR = 0.30
VOLLEY_NET_CM = 91.0          # net height at the centre strap (0.914 m); volley height points: >= net + 20 cm: 0,
                              # net - 15 .. net + 20 or above the head: 1, below net - 15: 2
TOP_SPEED_REF = 7.5          # m/s: v_req is divided by the player's top speed; callers rescale v_req
# Score -> grade (retune-systems s2): -1 or 0 VeryGood (Tee-off if the test passes at -1), 1-2 Good, 3 Normal,
# 4-5 Bad, 6+ VeryBad.
GRADE_OF_SCORE = [(0, "VeryGood"), (2, "Good"), (3, "Normal"), (5, "Bad")]

# Tee-off test (retune-systems s2, owner's conditions, all required)
TEEOFF = {"pace_max": 52.0, "h_lo": WAIST_CM, "h_hi": SHOULDER_CM, "frames_min": 60, "vreq_max": 3.5,
          "set_min": 20, "depth_max": 100.0}


# Contact height is measured at the hit point the planner chose (retune-systems s2, owner clarification): a set
# player with time lets a high-bouncing ball drop into the strike zone, paying with a deeper contact point.
LET_DROP = {"set_min": 20, "frames_min": 60, "back_per_cm": 1.2, "cm_per_f": 6.0}


def choose_contact(rng, s):
    """Let a high ball drop when set with time: height into the upper strike zone, contact further back, fewer
    frames set (stepping back).  Modifies the Situation in place; returns True when it did."""
    L = LET_DROP
    if s.height <= SHOULDER_CM or s.set_f < L["set_min"] or s.frames < L["frames_min"]:
        return False
    back = L["back_per_cm"] * (s.height - SHOULDER_CM)
    s.height = rng.uniform(SHOULDER_CM - 25.0, SHOULDER_CM)
    s.depth_x += back
    s.dist_net_cm += back
    s.set_f = int(max(0.0, s.set_f - back / L["cm_per_f"]))
    return True


def grade_points(frames, v_req, run_cm, height, pace, depth_x, set_f, stretch, kick=0.0, volley=False,
                 rushed=False, vigor=1.0):
    """Points per input (integers).  kick, run_cm and depth_x are not inputs of the score (kept in the
    signature for the callers; the Tee-off test reads depth_x)."""
    if stretch:
        arrival = 4
    elif volley:
        e = VOLLEY_ARRIVAL_EDGES
        arrival = 0 if frames >= e[0] else 1 if frames >= e[1] else 2 if frames >= e[2] else 3
    else:
        e = ARRIVAL_EDGES
        arrival = 0 if set_f >= e[0] else 1 if set_f >= e[1] else 2 if set_f >= e[2] else 3
    if volley:          # judged against the net (retune-systems s2a), not the body
        n = VOLLEY_NET_CM
        h = 0 if n + 20.0 <= height <= HEAD_CM else 1 if (n - 15.0 <= height < n + 20.0 or height > HEAD_CM) else 2
    elif WAIST_CM <= height <= SHOULDER_CM:
        h = 0
    elif KNEE_CM <= height <= HEAD_CM:
        h = 1
    else:
        h = 2
    pe = VOLLEY_PACE_EDGES if volley else PACE_EDGES
    pc = -1 if pace <= pe[0] else 0 if pace <= pe[1] else 1 if pace <= pe[2] else 2
    self_ = (1 if rushed else 0) + (1 if vigor < LOW_VIGOR else 0)
    return {"arrival": arrival, "height": h, "pace": pc, "self": self_}


def grade_of_score(score):
    for edge, g in GRADE_OF_SCORE:
        if score <= edge:
            return g
    return "VeryBad"


def teeoff_test(frames, v_req, height, pace, depth_x, set_f, stretch, volley=False):
    t = TEEOFF
    if volley:      # at the net: a slow ball above the net with time to watch it (the volley put-away)
        return pace <= 75.0 and height >= 110.0 and frames >= 30 and not stretch
    return (pace <= t["pace_max"] and t["h_lo"] <= height <= t["h_hi"] and frames >= t["frames_min"]
            and v_req < t["vreq_max"] and not stretch and set_f >= t["set_min"] and depth_x <= t["depth_max"])


def grade_of(frames, v_req, run_cm, height, pace, depth_x, set_f, stretch, kick=0.0, volley=False,
             rushed=False, vigor=1.0):
    """(grade name, score, points)."""
    pts = grade_points(frames, v_req, run_cm, height, pace, depth_x, set_f, stretch, kick, volley, rushed, vigor)
    score = sum(pts.values())
    if score <= -1 and teeoff_test(frames, v_req, height, pace, depth_x, set_f, stretch, volley):
        return "Tee-off", score, pts
    return grade_of_score(score), score, pts


# What each row gives (retune-systems s2 table; values are this spec's tuned values, section 4).
#   pace_cap  PowerResolution Max relative to the Good row (Good = retail)
#   aim_cap   AimingResolution Max relative to the Good row (Good = the retail row unchanged); Tee-off is the
#             VeryGood row times a code multiplier (five rows only)
#   err_add   ErrorResolution: probability added to the shot's fault chance
#   w_grade   window factor
GRADE_FX = {
    "Tee-off": dict(pace_cap=1.18, aim_cap=1.18, aim_min=0.30, err_add=0.0, w_grade=1.30),
    "VeryGood": dict(pace_cap=1.08, aim_cap=1.12, aim_min=0.20, err_add=0.0, w_grade=1.10),
    "Good": dict(pace_cap=1.00, aim_cap=1.00, aim_min=0.0, err_add=0.0, w_grade=1.00),
    "Normal": dict(pace_cap=0.93, aim_cap=0.82, aim_min=0.0, err_add=0.03, w_grade=0.95),
    "Bad": dict(pace_cap=0.82, aim_cap=0.59, aim_min=0.0, err_add=0.08, w_grade=0.90),
    "VeryBad": dict(pace_cap=0.70, aim_cap=0.35, aim_min=0.0, err_add=0.15, w_grade=0.85),
}


# Shot type scales the grade's effect (retune-systems s2a): share of the row's distance from Good applied, on both the
# penalty and the bonus side.  Drop shot 1.2 on pace-related points (drop_quality).
GRADE_SHARE = {"Flat": 1.00, "TopSpin": 0.80, "Slice": 0.50, "Lob": 0.50, "Drop": 1.20}
AIM_KEY_CLASS = {"TopSpinMedium": "TopSpin", "FlatMedium": "Flat", "FlatFinesse": "Flat", "SliceMedium": "Slice",
                 "FlatPower": "Flat", "DropShot": "Drop"}


def row_fx(grade, cls, key):
    """Row value for this shot type: Good + share x (row - Good)."""
    k = GRADE_SHARE[cls]
    good = GRADE_FX["Good"][key]
    return good + k * (GRADE_FX[grade][key] - good)


# =========================================================================== timing window
# retune-systems s3:  W = clamp(W_rating x W_opp x W_grade x W_react, 0.60, 1.75);
# Perfect half-width = 2 frames x W, Good half-width = 6 frames x W (retail |t| < 0.1 and < 0.3).

PERFECT_HALF_BASE = 2.0
GOOD_HALF_BASE = 6.0
W_CLAMP = (0.60, 1.75)
W_RATING = [(40, 0.90), (70, 1.00), (100, 1.10)]      # on the stroke's rating (Forehand/Backhand/Volley/Return)
W_REACT = [(250, 0.70), (600, 1.00)]                   # ms from the opponent's contact to own contact
OPP_TIMING_FX = {"Perfect": 0.85, "Good": 0.93, "Average": 1.0, "Poor": 1.15, "Mistimed": 1.30}
OPP_FX_CAP = (0.80, 1.40)     # range of the scaled term in the sizing sweep
TOTAL_FLOOR = W_CLAMP[0]
OVERCHARGE_W = 0.80
OVERCHARGE_PACE = 1.04
RUSHED_LATE_F = 8.0           # a rushed swing commits at the 12-frame auto-commit: 8 frames late (t = +0.4)


def rating_of_stat(stat):
    """Inverse of the stat curve (NEW_CURVE): the 0..100 rating behind a 0..1 stat."""
    inv = [(y, x) for x, y in NEW_CURVE]
    return pwl(inv, stat)


def reaction_factor(react_ms):
    return pwl(W_REACT, react_ms)


def rating_factor(stat):
    return pwl(W_RATING, rating_of_stat(stat))


def window_scale(grade, stat, react_ms, opp_timing="Average", opp_scale=1.0, overcharge=False):
    """W and its factors."""
    opp = clamp(1.0 + (OPP_TIMING_FX[opp_timing] - 1.0) * opp_scale, *OPP_FX_CAP)
    f = {"rating": rating_factor(stat), "opp": opp, "grade": GRADE_FX[grade]["w_grade"],
         "react": reaction_factor(react_ms)}
    w = clamp(f["rating"] * f["opp"] * f["grade"] * f["react"], *W_CLAMP)
    if overcharge:
        w *= OVERCHARGE_W
    return w, f


def window_halfwidths(grade, stat, react_ms, opp_timing="Average", opp_scale=1.0, overcharge=False):
    """(Perfect half-width, Good half-width, W) in frames."""
    w, _ = window_scale(grade, stat, react_ms, opp_timing, opp_scale, overcharge)
    return PERFECT_HALF_BASE * w, GOOD_HALF_BASE * w, w


HUMAN_SIGMA_F = 3.4          # sd of a human's release error in frames (judgement, see spec section 5)
POOR_SPAN_F = 4.0            # frames past the Good edge still "Poor" (beyond: Mistimed)
# Position inside the row (retune-systems s4): the retail graphs lerp each row's Min..Max with the timing value, and
# that shape stays.  Retail anchor (G8): a late t = +0.5 FlatPower keeps about 75 % of its peak aim (0.45 of 0.60).
# The shape below is judgement through that anchor; t is the timing value after the division by W.
T_SHAPE = [(0.0, 1.0), (0.1, 0.97), (0.3, 0.88), (0.5, 0.75), (0.8, 0.50), (1.2, 0.25)]
# Zero-error band (retune-systems s3): retail size at W = 1 (t -0.60 .. +0.45, 19 frames), scaling with W.
ZERO_BAND_T = (-0.60, 0.45)


def p_window(half, sigma=None):
    """P(|release error| <= half) for a normal release error; release frames are whole frames, so the
    half-width is widened by half a frame (a half-width of 0.5 = only the exact frame)."""
    sigma = HUMAN_SIGMA_F if sigma is None else sigma
    return math.erf((half + 0.5) / (sigma * math.sqrt(2.0)))


def classify_release(err, perfect_half, good_half):
    """(coarse, fine, pos, t) for a signed release error in frames (+ = late).  t = err x 0.05 / W."""
    a = abs(err)
    w = good_half / GOOD_HALF_BASE
    t = err * 0.05 / w
    pos = pwl(T_SHAPE, abs(t))
    hp, hg = perfect_half + 0.5, good_half + 0.5
    if a <= hp:
        return "Perfect", "Perfect", pos, t
    if a <= hg:
        return "Good", ("Good" if a <= 0.5 * (hp + hg) else "Average"), pos, t
    if a <= hg + POOR_SPAN_F:
        return "Poor", "Poor", pos, t
    return "Mistimed", "Mistimed", pos, t


def release(rng, perfect_half, good_half, sigma=None, rushed=False):
    """Draw a release.  Returns (coarse, fine, pos, t).  rushed=True: the swing commits at the 12-frame auto-commit
    (8 frames late, no human error left)."""
    err = RUSHED_LATE_F if rushed else rng.gauss(0.0, HUMAN_SIGMA_F if sigma is None else sigma)
    return classify_release(err, perfect_half, good_half)


# Timing error outside the zero-error band: probability per unit of t beyond the band edge (late costs about twice
# early, as in the retail fault graphs), times a hold weight (retail: a late full charge errs, Medium does not).
TIMING_ERR_SLOPE = {"late": 1.6, "early": 0.8}
TIMING_ERR_HOLD = {"Finesse": 0.5, "Medium": 1.0, "Powerful": 1.5, "Full": 2.0, "Overcharge": 4.0}


def timing_error(t, hold="Medium"):
    lo, hi = ZERO_BAND_T
    x = TIMING_ERR_SLOPE["late"] * (t - hi) if t > hi else TIMING_ERR_SLOPE["early"] * (lo - t) if t < lo else 0.0
    return clamp(x * TIMING_ERR_HOLD[hold], 0.0, 0.9)


def timing_outcome(rng, perfect_half, good_half, sigma=None, fine=False):
    c, f, _, _ = release(rng, perfect_half, good_half, sigma)
    return (c, f) if fine else c


# =========================================================================== speed (forehand launch mph)
# retune-systems s2/s4/s5: the grade row sets the pace cap (PowerResolution Max vs Good), the charge tier sets how
# close to the cap the swing can get, timing picks the position inside the row, the overcharge adds 4 % to the cap.
# The Good-row full-charge flat cap is the retail full-charge pace: charge_table.yaml Flat Powerful at full charge,
# median 130.1 km/h (80.8 mph), max 145.2 km/h (90.2 mph).

# Good row = the retail row unchanged: launch km/h at perfect timing by class and tier, at the Power-rating levels
# 30 / 54 / 75 / 100 (retune-baseline.md 1b, ground_cc, forehand).  "Full" is a full charge (75 frames): the
# charge_table.yaml Flat full-charge values min 127.1 / median 130.1 / max 145.2 km/h (sourced), the p90 level
# interpolated; spin classes take the Flat ratio Full / Powerful at each level.
GOOD_ROW_LEVELS = (30, 54, 75, 100)
GOOD_ROW_KMH = {
    ("Flat", "Finesse"): (110, 113, 117, 123), ("Flat", "Medium"): (121, 125, 127, 131),
    ("Flat", "Powerful"): (126, 129, 130, 141), ("Flat", "Full"): (127.1, 130.1, 132.5, 145.2),
    ("TopSpin", "Finesse"): (113, 114, 116, 118), ("TopSpin", "Medium"): (114, 116, 117, 118),
    ("TopSpin", "Powerful"): (117, 119, 121, 124),
    ("Slice", "Finesse"): (97, 98, 99, 100), ("Slice", "Medium"): (101, 102, 104, 108),
    ("Slice", "Powerful"): (101, 103, 106, 109), ("Lob", "Finesse"): (102, 102, 102, 103),
    ("Lob", "Medium"): (101, 102, 102, 102), ("Lob", "Powerful"): (101, 100, 99, 98),
}
for _c in ("TopSpin", "Slice", "Lob"):
    GOOD_ROW_KMH[(_c, "Full")] = tuple(round(v * f / p, 1) for v, f, p in zip(
        GOOD_ROW_KMH[(_c, "Powerful")], GOOD_ROW_KMH[("Flat", "Full")], GOOD_ROW_KMH[("Flat", "Powerful")]))
# How much of the row's pace cap each tier gets above Good (retune-systems s5: the tier steps grow on Good and above);
# below Good the tier differences are halved (the steps stay small).
TIER_SHARE_UP = {"Finesse": 0.40, "Medium": 0.60, "Powerful": 0.85, "Full": 1.00}
TIER_SPREAD_DOWN = 0.5
ROW_SPREAD = 0.15             # PowerResolution Min = Max x (1 - spread); retail late +0.5 loses <= 5 km/h (1e)
SKILL_PACE = 0.02             # a pace skill (InstantRocket / HighlyFlammable class) on Powerful+ swings
FATIGUE_MPH = 6.0             # mph lost at vigor 0
NOISE_MPH = 1.5               # execution spread (sd)
# Owner decision: 110 mph forehand hard ceiling; backhand 105 (judgement; tour backhand averages are 7 mph below
# forehand averages, ATP/TDI 2024, and the gap at the top is taken a little smaller than at the mean).
CEILING = {"FH": 110.0, "BH": 105.0}
HOLDS = ["Finesse", "Medium", "Powerful", "Full", "Overcharge"]


def good_row_mph(cls, tier, power_rating):
    return mph(pwl(list(zip(GOOD_ROW_LEVELS, GOOD_ROW_KMH[(cls, tier)])), power_rating))


def row_max_mph(cls, grade, hold, power_rating):
    """PowerResolution Max of this grade row for the tier reached (perfect timing)."""
    tier = "Full" if hold == "Overcharge" else hold
    cap = row_fx(grade, cls, "pace_cap")
    g = good_row_mph(cls, tier, power_rating)
    if cap >= 1.0:
        v = g * (1.0 + (cap - 1.0) * TIER_SHARE_UP[tier])
    else:
        m = good_row_mph(cls, "Medium", power_rating)
        v = cap * (m + TIER_SPREAD_DOWN * (g - m))
    return v * (OVERCHARGE_PACE if hold == "Overcharge" else 1.0)


def stack_speed(cls, grade, hold, pos, power_stat, hand_stat, vigor=1.0, skill=False, noise=0.0, stroke="FH"):
    """Launch speed (mph) and its terms.  pos = position inside the row from the timing (1 = perfect).
    hand_stat is not used: the Good row is retail, which keys pace on the Power rating only."""
    terms = {
        "row_max": row_max_mph(cls, grade, hold, rating_of_stat(power_stat)),
        "skill": 1.0 + (SKILL_PACE if (skill and hold in ("Powerful", "Full", "Overcharge")) else 0.0),
        "pos": 1.0 - ROW_SPREAD * (1.0 - pos),
        "fatigue": -FATIGUE_MPH * (1.0 - vigor),
        "noise": noise,
    }
    v = terms["row_max"] * terms["skill"] * terms["pos"] + terms["fatigue"] + noise
    return min(CEILING[stroke], v), terms


# =========================================================================== charge (frames), retail tiers kept

CHARGE = {"medium_from": 12, "powerful_from": 53, "full_at": 75, "overcharge_past_full": 10}
RELEASE_LEAD = 20             # perfect release 20 frames before contact (kept)
AUTO_COMMIT = 12              # retail auto-commit lead (PT+0x740)
REACT_PRESS_F = 15            # a human presses about 15 frames after the opponent's contact (judgement)
RUSHED_SHARE = 0.35           # judgement: share of short-of-Powerful wanted swings the player keeps holding


def tier_of_held(held):
    c = CHARGE
    if held >= c["full_at"] + c["overcharge_past_full"]:
        return "Overcharge"
    if held >= c["full_at"]:
        return "Full"
    if held >= c["powerful_from"]:
        return "Powerful"
    if held >= c["medium_from"]:
        return "Medium"
    return "Finesse"


def hold_reached(frames_pressed_before_contact, set_f, release_lead=RELEASE_LEAD):
    """Tier the meter reaches if the player presses `frames_pressed_before_contact` frames before contact and
    releases `release_lead` frames before contact.  The overcharge also needs the 25 frames past full spent
    planted (set_f counts frames planted before contact)."""
    held = frames_pressed_before_contact - release_lead
    t = tier_of_held(held)
    if t == "Overcharge" and set_f < CHARGE["overcharge_past_full"] + release_lead:
        t = "Full"
    return t


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
    choose_contact(rng, s)
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
    """Shot class and hold chosen by a competent human: harder when the set-up allows it.  Returns (cls, hold,
    commit) with commit False (released at will), "late" (held into the auto-commit and reached Powerful) or
    "rushed" (held into the auto-commit, still short of Powerful).  The hold follows the retail charge (12 / 53 / 75 frames from the press to the commit): a player who
    wanted Powerful but cannot reach it either releases at the tier he has (not rushed) or keeps holding into the
    12-frame auto-commit (rushed, RUSHED_SHARE of the time)."""
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
    press_lead = sit.frames - REACT_PRESS_F
    want = "Powerful" if grade in ("Tee-off", "VeryGood", "Good") else "Medium"
    if grade == "Normal" and rng.random() < 0.4:
        want = "Powerful"
    reach = hold_reached(press_lead, sit.set_f)
    order = HOLDS
    if reach == "Overcharge" and grade in ("Tee-off", "VeryGood") and rng.random() < overcharge_try:
        return cls, "Overcharge", False
    if reach == "Overcharge":
        reach = "Full"
    if order.index(reach) >= order.index(want):
        return cls, (reach if want == "Powerful" else want), False
    if want == "Powerful" and rng.random() < RUSHED_SHARE:
        late = tier_of_held(press_lead - AUTO_COMMIT)
        # held into the auto-commit: 8 frames late; "rushed" (+1 grade point) only if still short of Powerful
        return cls, ("Full" if late == "Overcharge" else late), ("rushed" if late in ("Finesse", "Medium") else "late")
    return cls, reach, False


def forehand_shot(rng, p, sit, opp_timing="Average", opp_scale=1.0, overcharge_try=0.8, vigor=1.0):
    vr = sit.v_req * TOP_SPEED_REF / (RALLY["max_run_base"] + RALLY["max_run_speed"] * p.s["speed"])
    g0, _, _ = grade_of(sit.frames, vr, sit.run_cm, sit.height, sit.pace, sit.depth_x, sit.set_f,
                        sit.stretch, sit.kick, vigor=vigor)
    cls, hold, commit = policy_forehand(rng, p, sit, g0, overcharge_try)
    rushed = commit == "rushed"
    g = g0
    if rushed:
        g, _, _ = grade_of(sit.frames, vr, sit.run_cm, sit.height, sit.pace, sit.depth_x, sit.set_f,
                           sit.stretch, sit.kick, rushed=True, vigor=vigor)
    hp, hg, w = window_halfwidths(g, p.s["fh"], sit.react_ms, opp_timing, opp_scale, hold == "Overcharge")
    t, tf, pos, tv = release(rng, hp, hg, rushed=bool(commit))
    v, terms = stack_speed(cls, g, hold, pos, p.s["power"], p.s["fh"], vigor,
                           skill="pace" in p.skills, noise=rng.gauss(0.0, NOISE_MPH))
    return dict(grade=g, cls=cls, hold=hold, rushed=rushed, timing=t, mph=v, hp=hp, hg=hg, w=w, t=tv)


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


RETURN_FAMILY = {"slow_serve_mph": 90.0, "reach_placement": 0.80, "jam_share": 0.08}


def return_grade(serve_mph, placement, vigor=1.0, rng=None):
    """Return of serve as its own family (retune-systems s2a): no pace or arrival-time points.  Good by default; Bad
    when stretched wide (reach swing) or jammed at the body; VeryGood on a slow serve in the strike zone (the
    attackable second serve); never Tee-off.  Serve pace reaches the returner through W_react and W_opp only."""
    F = RETURN_FAMILY
    jam = rng is not None and placement < 0.5 and rng.random() < F["jam_share"]
    if placement >= F["reach_placement"] or jam:
        g = "Bad"
    elif serve_mph <= F["slow_serve_mph"]:
        g = "VeryGood"
    else:
        g = "Good"
    if vigor < LOW_VIGOR:
        g = GRADES[min(len(GRADES) - 1, GRADES.index(g) + 1)]
    return g


def return_quality(rng, ret, serve_mph, placement=0.5, opp_timing="Average", opp_scale=1.0, second=False):
    """Returner outcome: 'unreturned' | 'weak' | 'neutral' | 'good', and the return's timing grade."""
    rt = serve_react_ms(serve_mph)
    g = return_grade(serve_mph, placement, ret.vigor if hasattr(ret, "vigor") else 1.0, rng)
    hp, hg, w = window_halfwidths(g, ret.s["ret"], rt, opp_timing, opp_scale)
    t, tf, pos, tv = release(rng, hp, hg)
    reach = 0.97 - 0.40 * max(0.0, placement - 0.5) / 0.5 * (1.15 - 0.3 * ret.s["speed"])
    if rng.random() > reach:
        return "unreturned", tf
    err = RETURN_ERR[t] * clamp(1.9 - 1.5 * w, 0.4, 1.8) + GRADE_FX[g]["err_add"]
    err += 0.30 * ret.floor["ret"]
    err += RETURN_RATING_ERR * max(0.0, RETURN_RATING_REF - ret.s["ret"])   # hold lever 2: low Return rating
    if rng.random() < err:
        return "unreturned", tf
    q = {"Perfect": "good", "Good": "neutral", "Poor": "weak", "Mistimed": "weak"}[t]
    if q == "good" and not second and rng.random() > RETURN_GOOD_SHARE:
        q = "neutral"           # a clean return of a first serve mostly neutralises (calibration, section 2d)
    if g in ("Bad", "VeryBad"):  # hold lever 1: a stretched or jammed return hands the server a weaker ball
        q = {"good": "neutral", "neutral": "weak", "weak": "weak"}[q]
    return q, tf


# Hold levers (model calibration, final run): extra return error per unit of Return stat below RETURN_RATING_REF
# (stat 0.80 = rating about 85), and a Bad or VeryBad return grade lowers the return ball one step.
RETURN_RATING_ERR = 0.30
RETURN_RATING_REF = 0.80
RETURN_GOOD_SHARE = 0.4       # share of Perfect first-serve returns that come back as attacking returns
RETURN_ERR = {"Perfect": 0.10, "Good": 0.25, "Poor": 0.60, "Mistimed": 0.90}   # model calibration (sections 2d, 9d)
# The ball a return hands the server (rally model): pace mph before rating terms, depth 0..1, width 0..1.
RETURN_BALL = {"pace": {"good": 66.0, "neutral": 58.0, "weak": 48.0}, "depth": {"good": 0.7, "neutral": 0.5, "weak": 0.15},
               "width": {"good": 0.35, "neutral": 0.15, "weak": 0.10}}   # model calibration (section 2d)


# =========================================================================== rally / match simulation

RALLY = {
    "base_err": 0.09,                  # situation fault chance of every groundstroke (control-sum penalties: running,
                                       # fast ball, fatigue) beyond the timing and grade terms; model calibration
    "volley_base_err": 0.03,           # the same situation term on every volley, a third of the groundstroke value
                                       # (model fix, final run; game proposal: volleys carry a small base error)
    "pace_margin": {"Flat": 81.0, "TopSpin": 84.0, "Slice": 68.0, "Lob": 60.0},   # mph where the pace term starts
    "pace_err": 0.003,                 # error per mph above the margin speed
    "margin_hand": 10.0,                # margin speed added per unit of hand stat
    "kick": {"Flat": 0.08, "TopSpin": 0.20, "Slice": 0.0, "Lob": 0.2},
    "kick_hand": 0.14,                  # topspin kick added per unit of hand stat (spin scales with FH/BH rating)
    "low": {"Slice": 1.0},              # slice stays low: the receiver's contact height drops
    "max_run_base": 5.7, "max_run_speed": 2.9,          # m/s reachable: base + per unit of Speed stat
    "floor_err": 0.20,                  # error added per unit of floor penalty of the stroke's rating
    "pass_err": 0.01,                   # added error for a passing shot against a net player
    "low_drive_err": 0.004,             # per mph above 70 when driving a ball below 60 cm (x depth below 60 / 30)
    "vigor_cost": {"Finesse": 0.002, "Medium": 0.004, "Powerful": 0.006, "Full": 0.006, "Overcharge": 0.009},
    "run_cost": 0.0012,                 # vigor per m/s of required run speed
    "recover_point": 0.022, "recover_set": 0.12,
    "net_rush": {"volley_style": 0.55, "approach_on_short": 0.35},
}


# Spin available by row: the spin blend S+0x774 is a curve of the PowerfulFactor (OPEN 2.6), so it follows the
# PowerResolution row (model term, values kept from the earlier draft).
SPIN_ROW = {"Tee-off": 1.10, "VeryGood": 1.05, "Good": 1.00, "Normal": 0.95, "Bad": 0.85, "VeryBad": 0.70}
# Moonball (test of the owner's question, section 4): a high, slow, deep topspin ball.  Launch ~58 mph, at contact
# about 0.52 of launch (high arc, bounce), contact height at the top of the bounce ~175 cm, 0.5 s more flight.
MOON = {"mph": 58.0, "depth": 0.85, "kick": 0.50, "bounce_cm": 175.0, "contact_ratio": 0.52, "extra_f": 30}
DEPTH_BASE = 0.62         # rally-model depth of an In ball before the DeepDeviation pull (0 short .. 1 baseline)
DEPTH_EFF = 0.30          # extra depth per unit of FinalEfficiency above 0.55 (outer quads reach deeper)
SLICE_DROP_CM = 50.0      # a slice reaches the receiver this much lower than a neutral ball


class Ball:
    __slots__ = ("pace", "depth", "width", "kick", "low", "timing", "short", "hitter_net", "corner", "share", "floating",
                 "sv_first", "moon")

    def __init__(self, pace, depth, width, kick, low, timing, short=False, hitter_net=False):
        self.pace, self.depth, self.width, self.kick, self.low = pace, depth, width, kick, low
        self.timing, self.short, self.hitter_net = timing, short, hitter_net
        self.corner, self.share, self.floating, self.sv_first = False, CORNER_SHARE, False, False
        self.moon = False


def situation_from_ball(rng, b, at_net=False):
    s = Situation()
    pace = clamp(b.pace, 30.0, 130.0)
    dist = (23.0 if not b.short else 17.0) if not at_net else 13.0
    s.pace = kmh(pace) * (0.58 if not at_net else 0.80)   # a volley meets the ball before the bounce
    v_avg = kmh(pace) / 3.6 * (0.70 if not at_net else 0.85)
    s.frames = int(FPS * (dist / v_avg + ((0.30 if not b.short else 0.45) if not at_net else 0.0)))
    s.react_ms = s.frames * 1000.0 / FPS
    run = 30.0 + 640.0 * b.width
    # anticipation (judgement): a receiver reads how often this hitter goes for the corner and cheats toward it;
    # a predictable corner aim is reached sooner, a safe ball then catches the cheat (wrong-footing)
    run *= (1.0 - ANTICIPATION * b.share) if b.corner else (1.0 + 0.6 * ANTICIPATION * b.share)
    s.run_cm = max(0.0, run + rng.gauss(0.0, 70.0)) * (0.55 if at_net else 1.0)
    avail = max(0.15, s.frames / FPS - 0.30)
    s.v_req = s.run_cm / 100.0 / avail
    s.stretch = s.v_req > 5.2 or s.run_cm > 380
    s.kick = b.kick
    if at_net and b.sv_first:
        # model fix: the serve-and-volleyer's first volley is played from about 6.5 m out, still moving in (the serve
        # tail outlasts the return, section 10), so the return often dips at his feet
        h = rng.gauss(SV_FIRST_HEIGHT, 25.0) - (35.0 if b.low else 0.0)
    elif at_net:
        h = rng.gauss(95.0, 30.0) - (35.0 if b.low else 0.0)
    elif b.short:
        h = rng.gauss(112.0, 18.0)
    else:
        h = rng.gauss(100.0 + 70.0 * max(0.0, b.kick - 0.2), 22.0) - (SLICE_DROP_CM if b.low else 0.0)
    if b.moon and not at_net:       # a moonball: deep, slow, bouncing above the shoulder
        h = rng.gauss(MOON["bounce_cm"], 20.0)
        s.pace = kmh(pace) * MOON["contact_ratio"]
        s.frames += MOON["extra_f"]
        s.react_ms = s.frames * 1000.0 / FPS
    s.height = clamp(h, 12.0, 230.0)
    s.depth_x = (-1188.0 + (SV_FIRST_DIST_CM if b.sv_first else 250.0) + rng.gauss(0, 80)) if at_net else (
        rng.gauss(-250.0, 100.0) if b.short else 30.0 + 260.0 * b.depth + rng.gauss(0.0, 60.0))
    slack = s.frames - 18 - s.run_cm / 100.0 / 6.0 * FPS
    s.set_f = int(max(0.0, slack - 12))
    s.floating = (b.short and pace < 55) or b.floating
    s.dist_net_cm = 1188.0 + s.depth_x
    if not at_net:
        choose_contact(rng, s)
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
        sit.stretch = sit.v_req > 5.2 or sit.run_cm > 250.0   # model fix: re-test the stretch after the lunge
    vmax0 = (R["max_run_base"] + R["max_run_speed"] * p.s["speed"]) * (0.80 + 0.20 * p.vigor)
    vr = sit.v_req * TOP_SPEED_REF / vmax0          # required speed as felt by this player
    stretch = sit.stretch or vr > 5.2
    g, q, _ = grade_of(sit.frames, vr, sit.run_cm, sit.height, sit.pace, sit.depth_x, sit.set_f,
                       stretch, sit.kick, volley=at_net, vigor=p.vigor)
    # reach: the player cannot get there at all
    if sit.v_req > vmax0:
        return "unreached", None, {"grade": "VeryBad", "timing": None}
    wing = "fh" if rng.random() < 0.55 else "bh"
    stat = p.s["volley"] if at_net else p.s[wing]
    flo = p.floor["volley"] if at_net else p.floor[wing]
    if not at_net and sit.height < 50:      # a pick-up off the ground is touch: Volley rating shares it
        stat = 0.6 * stat + 0.4 * p.s["volley"]
        flo = 0.6 * flo + 0.4 * p.floor["volley"]
    st = p.style
    rushed, commit, moon = False, False, False
    if at_net:          # VolleyPower on good balls; an overreach on others at the style's rate
        power = g in ("Tee-off", "VeryGood") or rng.random() < st.get("net_power", 0.15)
        cls, hold = ("Flat", "Powerful") if power else ("Slice" if rng.random() < 0.5 else "Flat", "Medium")
    else:
        cls, hold, commit = policy_forehand(rng, p, sit, g)
        rushed = commit == "rushed"
        if rng.random() < st.get("topspin_more", 0.0) and cls == "Flat" and g not in ("Tee-off",):
            cls = "TopSpin"
        if rng.random() < st.get("slice_more", 0.0) and cls != "Slice" and g not in ("Tee-off", "VeryGood"):
            cls = "Slice"
        moon = rng.random() < st.get("moonball", 0.0) and g not in ("Tee-off", "VeryGood")
        if moon:
            cls, hold, commit, rushed = "TopSpin", "Medium", False, False
        if rushed:      # +1 grade point (retune-systems s5)
            g, q, _ = grade_of(sit.frames, vr, sit.run_cm, sit.height, sit.pace, sit.depth_x, sit.set_f,
                               stretch, sit.kick, rushed=True, vigor=p.vigor)
    hp, hg, w = window_halfwidths(g, stat, sit.react_ms, b.timing, prm.get("opp_scale", 1.0), hold == "Overcharge")
    t, tf, pos, tv = release(rng, hp, hg, rushed=bool(commit))
    if g == "Tee-off" and tv > 0:       # Tee-off keeps the put-away's "no late-timing aim penalty"
        aim_pos, aim_fine = 1.0, "Perfect"
    else:
        aim_pos, aim_fine = pos, tf
    power_stat = p.s["power"]
    stroke = "FH" if wing == "fh" else "BH"
    v, _ = stack_speed(cls, g, hold, pos, power_stat, stat, p.vigor, "pace" in p.skills,
                       rng.gauss(0.0, NOISE_MPH), stroke)
    vb = None
    if at_net:
        vb = volley_band(g, t, stat, rng)
        bd = VOLLEY_BANDS[vb]
        v = bd["mph"] + (VOLLEY_POWER_MPH if hold == "Powerful" and vb <= 2 else 0.0) + rng.gauss(0.0, 2.0)
        if sit.height < NET_HEIGHT_CM:
            v = min(v, LOW_VOLLEY_CAP_MPH)
    fx = GRADE_FX[g]
    margin = (R["pace_margin"][cls] + R["margin_hand"] * stat) * row_fx(g, cls, "pace_cap")
    if at_net:          # volley errors come mainly from overreach (owner direction)
        err = VOLLEY_BANDS[vb]["err"] + R["volley_base_err"]
        if hold == "Powerful" and (sit.height < NET_HEIGHT_CM or sit.pace > 100.0):
            err += OVERREACH_ERR
    else:
        err = timing_error(tv, hold) + R["pace_err"] * max(0.0, v - margin) + row_fx(g, cls, "err_add") + R["base_err"]
    if not at_net and sit.height < 60 and cls in ("Flat", "TopSpin"):   # driving a low ball: it must be lifted
        err += R["low_drive_err"] * max(0.0, v - 70.0) * (60.0 - sit.height) / 30.0
    if b.hitter_net and not at_net:     # passing: the lanes past a net player are narrow
        err += R["pass_err"]
    err += R["floor_err"] * flo + 0.12 * (1.0 - p.vigor) ** 1.5

    key = aim_key(cls, hold, at_net)
    fe = final_efficiency(aim_efficiency(key, g, aim_fine, stat, aim_pos), rng.random())
    corner = rng.random() < st.get("corner", CORNER_SHARE)
    if corner and not at_net:
        err += LINE_RISK * fe
    p.spend(R["vigor_cost"][hold] + R["run_cost"] * sit.v_req)
    info = {"grade": g, "timing": t, "fine": tf, "cls": cls, "hold": hold, "mph": v, "band": vb, "rushed": rushed,
            "w": w}
    if "classlog" in prm and not at_net:
        prm["classlog"][(g, cls)] += 1
        prm["classlog"][(g, cls, "err")] += err
    if rng.random() < err:
        return "error", None, info
    if at_net and rng.random() < VOLLEY_BANDS[vb]["putaway"] * (1.0 if hold == "Powerful" else 0.6):
        return "putaway", None, info
    deep = deep_deviation(rng, g, aim_fine)
    depth = clamp(DEPTH_BASE - deep / 405.0 + DEPTH_EFF * (fe - 0.55) + rng.gauss(0.0, 0.10)
                  + (0.08 if cls == "TopSpin" else 0.0), 0.0, 1.0)
    # aim (spec section 7): the retail chain Efficiency -> FinalEfficiency (graph 196) -> quad, fed by grade, timing
    # and hand.  The stick is direction-only: "corner" = the diagonal (deep corner), otherwise a safer direction.
    angle_back = ANGLE_BACK * b.width if g in ("Tee-off", "VeryGood", "Good") else 0.0
    width = clamp(WIDTH_SCALE * fe * (1.0 if corner else SAFE_LAT) * (NET_WIDTH if at_net else 1.0) + angle_back
                  + rng.gauss(0.0, 0.12), 0.0, 1.0)
    if corner:
        depth = clamp(depth + 0.04, 0.0, 1.0)
    sp = 1.0 + GRADE_SHARE[cls] * (SPIN_ROW[g] - 1.0)
    kick = R["kick"][cls] * sp + (R["kick_hand"] * stat * sp if cls == "TopSpin" else 0.0)
    short = depth < 0.12 and not at_net
    floating = False
    if at_net:          # the band decides the reply: reach of the aim box, depth, float
        bd = VOLLEY_BANDS[vb]
        fe = final_efficiency(bd["eff"], rng.random())
        width = clamp(WIDTH_SCALE * NET_WIDTH * fe * (1.0 if corner else SAFE_LAT) + rng.gauss(0.0, 0.10), 0.0, 1.0)
        depth = clamp(0.75 - bd["deep"] / 600.0 + rng.gauss(0.0, 0.08), 0.0, 1.0)
        short = vb >= 4
        floating = bd["apex"] >= 1.0
    if moon:
        v = MOON["mph"] + rng.gauss(0.0, 3.0)
        depth = clamp(MOON["depth"] + rng.gauss(0.0, 0.08), 0.0, 1.0)
        kick, short, width = MOON["kick"], False, width * 0.6
    nb = Ball(v, depth, width, kick, cls == "Slice", tf, short, at_net)
    nb.moon = moon
    nb.floating = floating
    nb.corner, nb.share = corner, st.get("corner", CORNER_SHARE)
    return "in", nb, info


# Volley quality bands (owner direction): the main cost of a difficult volley is a weak, attackable reply, not an
# error.  Band from the volley grade (section 4, volley tables: height against the net, time, incoming pace) and the
# timing; the Volley rating shifts every band up one at a Volley stat >= VOLLEY_SHIFT_STAT.  Outputs map onto what the
# volley classes already have: pace (PF), Efficiency (aim box reach), DeepDeviation, apex (float).
VOLLEY_BAND_OF_GRADE = {"Tee-off": 1, "VeryGood": 1, "Good": 2, "Normal": 2, "Bad": 3, "VeryBad": 4}
VOLLEY_TIMING_DROP = {"Perfect": 0, "Good": 0, "Poor": 1, "Mistimed": 2}
VOLLEY_SHIFT_STAT = 0.70      # Volley rating about 75+
VOLLEY_BANDS = {
    # pace mph (VolleyStandard), Efficiency, DeepDeviation cm, apex m over the net, error, put-away chance
    1: dict(mph=70.0, eff=0.85, deep=40.0, apex=0.3, err=0.01, putaway=0.28),
    2: dict(mph=62.0, eff=0.65, deep=120.0, apex=0.6, err=0.02, putaway=0.06),
    3: dict(mph=57.0, eff=0.40, deep=320.0, apex=1.2, err=0.03, putaway=0.0),
    4: dict(mph=34.0, eff=0.20, deep=480.0, apex=2.5, err=0.10, putaway=0.0),
}
VOLLEY_POWER_MPH = 10.0       # VolleyPower adds pace (band 1-2 only; on a band 3-4 ball it is the overreach)
OVERREACH_ERR = 0.30          # power volley on a ball below net height (contact < 90 cm) or blistering (> 100 km/h)
NET_HEIGHT_CM = 90.0
LOW_VOLLEY_CAP_MPH = 50.0     # a ball contacted below the net must be lifted: pace capped


VOLLEY_SHIFT_MODE = "linear"  # "linear": the one-band shift happens with probability (stat - 0.5) / 0.5; "step": at SHIFT_STAT


def volley_band(grade, timing, volley_stat, rng=None):
    b = VOLLEY_BAND_OF_GRADE[grade] + VOLLEY_TIMING_DROP[timing]
    if VOLLEY_SHIFT_MODE == "step" or rng is None:
        if volley_stat >= VOLLEY_SHIFT_STAT:
            b -= 1
    elif rng.random() < clamp((volley_stat - 0.5) / 0.5, 0.0, 1.0):
        b -= 1
    return int(clamp(b, 1, 4))


SV_FIRST_HEIGHT = 55.0        # cm, return at the serve-and-volleyer's first volley: on the move, often at the feet (judgement)
SV_FIRST_DIST_CM = 650.0      # first volley played about 6.5 m from the net (dist_net = 1188 - depth_x offset)
CORNER_SHARE = 0.5           # default share of balls aimed at the deep corner (the rest: deep middle / mid-wide)
SAFE_LAT = 0.45               # lateral reach of the safer directions relative to a corner aim
WIDTH_SCALE = 1.10            # FinalEfficiency -> rally-model width (opponent's run); sized for rally length (spec 9)
NET_WIDTH = 0.85              # volley aim configs reach 350 cm to the side against 550 for groundstrokes (aim_tables)
ANGLE_BACK = 0.25             # a wide incoming ball opens the angle for a reply from a Good-or-better grade
ANTICIPATION = 0.35           # judgement: how much a receiver who reads the hitter's corner habit saves (see 7e)
LINE_RISK = 0.0               # OPTION for the owner (not in the agreed rules): added error per unit of how close the
                              # FinalEfficiency puts a corner aim to both lines; 0 = retail / owner's rule


def aim_key(cls, hold, at_net):
    if at_net:
        return "FlatMedium"
    if cls == "TopSpin":
        return "TopSpinMedium"
    if cls == "Slice":
        return "SliceMedium"
    if cls == "Lob":
        return "FlatFinesse"
    return {"Finesse": "FlatFinesse", "Medium": "FlatMedium", "Rushed": "FlatMedium"}.get(hold, "FlatPower")


def play_point(rng, server, receiver, prm):
    """Wrapper: plays the point and, when prm has "netlog", logs (how the player came in, won?) per net player."""
    if "netlog" not in prm:
        return _play_point(rng, server, receiver, prm)
    prm["_tag"] = {}
    res = _play_point(rng, server, receiver, prm)
    for pl, label in prm["_tag"].items():
        prm["netlog"].append((label, res[0] is pl))
    return res


def _play_point(rng, server, receiver, prm):
    """Returns (winner, rally_shots, end, end_timing).  end in ace_unret | winner | error | unreached | df."""
    p_eff = prm.get("serve_effort", 0.4)
    big_eff = rng.random() < server.style.get("max_serve", 0.0)
    e = 1.0 if big_eff else clamp(rng.betavariate(2, 3) * (p_eff / 0.4), 0.0, 1.0)
    g, gf = timing_outcome(rng, *window_halfwidths("Good", server.s["serve"], 1000.0)[:2], fine=True)
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
    q, rt = return_quality(rng, receiver, v, placement, gf if not second else "Average", prm.get("opp_scale", 1.0), second)
    if q == "unreturned":
        return server, 1, "ace_unret", rt
    # a slow serve can be attacked: the return gains pace, depth and angle (through the ball, spec s8)
    attack = clamp((100.0 - v) / 30.0, 0.0, 1.0) if q != "weak" else 0.0
    rb = RETURN_BALL
    pace = rb["pace"][q] + 12.0 * receiver.s["ret"] + 6.0 * receiver.s["power"] + 10.0 * attack
    depth = rb["depth"][q] + 0.2 * attack
    width = rb["width"][q] + 0.25 * attack
    ball = Ball(pace, clamp(depth, 0.0, 1.0), width, 0.15, False, rt, short=q == "weak")
    ball.sv_first = rng.random() < server.style.get("serve_volley", 0.0)
    hitter, other = server, receiver
    at_net = {server: False, receiver: False}
    if ball.sv_first:
        at_net[server] = True
        if "_tag" in prm:
            prm["_tag"][server] = "serve-volley"
    shots = 2
    while shots < 80:
        out, nb, info = hit(rng, hitter, ball, at_net[hitter], prm)
        if "trace" in prm:
            prm["trace"].append((ball.timing, info["timing"], out))
        if "grades" in prm and info.get("timing") is not None:
            prm["grades"][(info["grade"], at_net[hitter])] += 1
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
            if "_tag" in prm:
                good = info["grade"] in ("Tee-off", "VeryGood") and nb.depth >= 0.45
                prm["_tag"][hitter] = "approach, good (VeryGood+ and deep)" if good else "approach, other"
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
             "srv_won": 0, "sets": 0}
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
                stats["tiebreaks"] = stats.get("tiebreaks", 0) + 1
                server, receiver = receiver, server
                break
            pts = {server: 0, receiver: 0}
            while True:
                pts[point(server, receiver)] += 1
                if max(pts.values()) >= 4 and abs(pts[server] - pts[receiver]) >= 2:
                    break
            held = pts[server] > pts[receiver]
            games[server if held else receiver] += 1
            stats["svc_games_" + server.name] = stats.get("svc_games_" + server.name, 0) + 1
            stats["svc_held_" + server.name] = stats.get("svc_held_" + server.name, 0) + held
            server, receiver = receiver, server
            if max(games.values()) >= games_per_set and abs(games[a] - games[b]) >= 2:
                break
        sets[a if games[a] > games[b] else b] += 1
        stats["sets"] += 1
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



def depth_shortfall(grade, timing):
    """Mean and sd (cm) of how far an In groundstroke lands short of the aimed depth (retune-systems s4: the depth
    pull by timing; the grade does not enter)."""
    lo, hi = DEEP_TIMING_RANGE[timing]
    return 0.5 * (lo + hi), (hi - lo) / math.sqrt(12.0)


# Aim (owner decision): the retail aim system stays (direction-only stick, nested quads, Efficiency picks the quad,
# FinalEfficiency graph 196 with its random roll).  Only how Efficiency is fed changes (spec section 7):
#   Efficiency = class_peak x lerp(row Min, row Max, timing shape x hand term)
# Row Max = the grade's aim cap (ratio to Good, Good = retail).  The timing shape is the retail one (T_SHAPE).
AIM_CLASS_PEAK = {"TopSpinMedium": 0.80, "FlatMedium": 0.76, "FlatFinesse": 0.80, "SliceMedium": 0.76,
                  "FlatPower": 0.60, "DropShot": 0.40}              # retail Efficiency at perfect timing (aiming.md s4)
AIM_GRADE_ROW = {g: (GRADE_FX[g]["aim_min"], GRADE_FX[g]["aim_cap"]) for g in GRADES}
# representative position for each release grade, from T_SHAPE at |t| 0.05 / 0.15 / 0.25 / 0.45 / 0.8
AIM_TIMING_Q = {k: round(pwl(T_SHAPE, t), 3) for k, t in
                (("Perfect", 0.05), ("Good", 0.15), ("Average", 0.25), ("Poor", 0.45), ("Mistimed", 0.8))}
AIM_HAND = (0.65, 0.35)       # hand term = 0.65 + 0.35 x hand stat (retail: hand 0.3 costs 0.03-0.05)
EFF_MAX = 0.98                # keep Efficiency below the lines quad (m > 1 would aim outside the court)
# DeepDeviation by timing (retune-systems s4): Perfect 0-40 cm, Good up to 150 cm, outside Good the retail 2-3 m.
DEEP_TIMING_RANGE = {"Perfect": (0.0, 40.0), "Good": (0.0, 110.0), "Average": (40.0, 150.0),
                     "Poor": (200.0, 300.0), "Mistimed": (200.0, 310.0)}
DEEP_MAX_CM = 310.0


def aim_efficiency(cls_key, grade, timing_fine, hand_stat, pos=None):
    c = AIM_KEY_CLASS[cls_key]
    lo, hi = row_fx(grade, c, "aim_min"), row_fx(grade, c, "aim_cap")
    tq = AIM_TIMING_Q[timing_fine] if pos is None else pos
    q = tq * (AIM_HAND[0] + AIM_HAND[1] * hand_stat)
    return min(EFF_MAX, AIM_CLASS_PEAK[cls_key] * (lo + (hi - lo) * q))


def final_efficiency(eff, rnd):
    """Retail graph 196 (human), hand 0.8, timing 0 (aiming.md s4), bilinear in (Efficiency, Random)."""
    rows = {0.0: (0.00, 0.17, 0.68), 0.5: (0.49, 0.63, 0.84), 1.0: (0.79, 0.90, 1.00)}
    def row(e):
        return [pwl([(0.0, rows[0.0][k]), (0.5, rows[0.5][k]), (1.0, rows[1.0][k])], e) for k in range(3)]
    r = row(eff)
    return pwl([(0.0, r[0]), (0.5, r[1]), (1.0, r[2])], rnd)


def deep_deviation(rng, grade, timing_fine):
    lo, hi = DEEP_TIMING_RANGE[timing_fine]
    return rng.uniform(lo, hi)


def angle_access(depth_x_cm, grade, hand_stat):
    """Largest usable angle as a fraction of the sideline reach (aim quad lateral efficiency): more from inside
    the court and from good grades, scaled by the stroke rating."""
    pos = pwl([(-500, 1.0), (-150, 0.9), (0, 0.8), (200, 0.7), (400, 0.6)], depth_x_cm)
    g = {"Tee-off": 1.0, "VeryGood": 0.95, "Good": 0.85, "Normal": 0.75, "Bad": 0.6, "VeryBad": 0.45}[grade]
    return clamp(pos * g * (0.85 + 0.15 * hand_stat), 0.0, 1.0)


DROP_GRADE_ERR = {"Tee-off": 0.5, "VeryGood": 0.7, "Good": 1.0, "Normal": 1.3, "Bad": 1.8, "VeryBad": 2.5}


def drop_quality(incoming_kmh, height, grade, timing, touch_stat):
    """Drop shot: landing distance past the net (cm), bounce height (cm), error probability.
    Easy to play off a slow, mid-height ball from inside the court; hard off pace or a low ball."""
    base_land = {"Tee-off": 180, "VeryGood": 220, "Good": 270, "Normal": 330, "Bad": 420, "VeryBad": 520}[grade]
    land = base_land * (1.0 + 0.004 * max(0.0, incoming_kmh - 50.0)) * (1.15 - 0.3 * touch_stat)
    land += {"Perfect": -30, "Good": 0, "Poor": 80, "Mistimed": 160}[timing]
    bounce = 35.0 + 0.25 * max(0.0, land - 200.0) + 0.2 * max(0.0, incoming_kmh - 60.0)
    err = (0.03 + 0.0035 * max(0.0, incoming_kmh - 45.0) + pwl([(20, 0.20), (50, 0.08), (80, 0.0)], height)
           + {"Perfect": 0.0, "Good": 0.03, "Poor": 0.18, "Mistimed": 0.45}[timing]) * DROP_GRADE_ERR[grade]
    err *= 1.2 - 0.4 * touch_stat
    return land, bounce, clamp(err, 0.0, 0.95)


# =========================================================================== movement (owner decision 2026-11-14)
# Retail movement is kept, including the first step from rest.  Agreed rule changes: net rush buffered with no sprint
# requirement, pre-hit freeze lifted at the net only, feet freed earlier after volleys and approach shots only (about
# half of today's tails); groundstroke, return and serve tails stay retail.

# Swing tail = Out frame - contact frame, median (p10, p90), movement-and-animation s7.5 / s8.1 (data).
TAIL_RETAIL = {"groundstroke": (36, 27, 44), "return": (26, 19, 37), "volley": (38, 29, 51), "serve": (34, 24, 39),
               "approach": (36, 27, 44), "approach_follownet": (29, 19, 66), "put-away": (45, 37, 53)}
# Agreed: volley and approach tails cut to about half (median frames), by an earlier locomotion exit (code) or an
# earlier TE[1].Position (data); the clips themselves are not edited.
TAIL_AGREED = {"volley": 19, "approach": 18, "approach_follownet": 15}
PREHIT_FREEZE = 20            # cfg+0xA88, frames before the opponent's hit (data)
# Rush_Front from rest, frames to 5 / 25 / 100 cm, then 9.6 cm/frame (movement-and-animation s7.3, +15 fade).
RUSH_RETAIL = [(0, 0.0), (18, 5.0), (26, 25.0), (43, 100.0)]
RUSH_FIRST_STEP = RUSH_RETAIL   # the first step from rest is left as retail (owner decision)
RUSH_CM_PER_F = 9.6


def run_cm(frames, first_step=RUSH_RETAIL):
    """Distance (cm) covered from rest after `frames` of free running toward the net."""
    if frames <= 0:
        return 0.0
    t_end = first_step[-1][0]
    if frames <= t_end:
        return pwl(first_step, frames)
    return first_step[-1][1] + (frames - t_end) * RUSH_CM_PER_F


NET_ZONE_CM = -500.0          # "at the net" = the net-rush decider's x > -500 cm (movement-and-ai E.5)


def net_timeline(tail, reply_frames, ball_back_frames, start_x_cm, drift_cm, first_step=RUSH_RETAIL,
                 freeze_at_net=True, buffered=True):
    """Where a player running in after his own shot is when the opponent hits (reply_frames after the contact) and when
    the reply reaches him (ball_back_frames later).  x in cm from the net (negative = own side).
    Retail: the rush cannot start inside the 20 frames before the opponent's hit (condition 7) and the freeze latches
    the direction for those 20 frames (E.4).  `buffered` = the agreed change (the rush starts at the Out window even
    inside those 20 frames); `freeze_at_net` False = the agreed change (no freeze when the player is inside 500 cm of
    the net as the freeze would start)."""
    start = tail
    if not buffered and reply_frames - PREHIT_FREEZE <= start < reply_frames:
        start = reply_frames                              # retail: wait until the hit has passed
    x_hit = start_x_cm + drift_cm + run_cm(reply_frames - start, first_step)
    x_arr = start_x_cm + drift_cm + run_cm(reply_frames + ball_back_frames - start, first_step)
    free_frames = max(0, reply_frames + ball_back_frames - start)
    x_freeze = start_x_cm + drift_cm + run_cm(reply_frames - PREHIT_FREEZE - start, first_step)
    if freeze_at_net or x_freeze <= NET_ZONE_CM:
        free_frames = max(0, min(reply_frames - PREHIT_FREEZE, reply_frames + ball_back_frames) - start)
    return {"start": start, "x_at_reply": min(x_hit, -150.0), "x_at_ball": min(x_arr, -150.0), "free": free_frames}
