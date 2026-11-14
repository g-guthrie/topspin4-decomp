#!/usr/bin/env python3
"""Generate the computed tables of docs/design/retune-spec.md; standard library only.

Usage:
  python3 tools/design/retune_spec.py [--quick] [SECTION ...]
  SECTION: speed serve flight grade window oppterm power placement net stats abuse robust movement all

Every table is printed as Markdown.  The models are tools/design/retune_model.py (proposal) and
tools/design/retune_flight.py (game flight from data/gameplay/ball_templates.yaml, plus a real-ball reference).
No game files are read.  Seeds are fixed, so a rerun gives the same numbers (Python 3.13 random.Random).
"""

import argparse
import collections
import os
import random
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

import retune_flight as F  # noqa: E402
import retune_model as M  # noqa: E402

FH_PER_MATCH = 200        # forehands per player per best-of-3 match (assumption, spec section 2)
FH_PER_SEASON = 13000     # 65 matches x 200
SERVES_PER_MATCH = 90     # first serves per player per best-of-3 match (assumption)


def md(header, rows):
    out = ["| " + " | ".join(header) + " |", "|" + "|".join("---" for _ in header) + "|"]
    for r in rows:
        out.append("| " + " | ".join(str(c) for c in r) + " |")
    return "\n".join(out)


def f1(x):
    return "%.1f" % x


def f2(x):
    return "%.2f" % x


def f3(x):
    return "%.3f" % x


# --------------------------------------------------------------------------- section 2: speed

SPEC_STYLE = {"pace specialist": ({"pace"}, {"flat": 0.5}), "elite all-rounder": (set(), {"flat": 0.35}),
              "average pro": (set(), {"flat": 0.35})}

# Retail launch speeds (km/h) at perfect timing, ground_cc, from retune-baseline.md 1b, at the rating levels
# min 30 / median 54 / p90 75 / max 100 (Forehand = Power rating), keyed by class and tier.
RETAIL_1B = {
    ("Flat", "Finesse"): (110, 113, 117, 123), ("Flat", "Medium"): (121, 125, 127, 131),
    ("Flat", "Powerful"): (126, 129, 130, 141), ("TopSpin", "Finesse"): (113, 114, 116, 118),
    ("TopSpin", "Medium"): (114, 116, 117, 118), ("TopSpin", "Powerful"): (117, 119, 121, 124),
    ("Slice", "Finesse"): (97, 98, 99, 100), ("Slice", "Medium"): (101, 102, 104, 108),
    ("Slice", "Powerful"): (101, 103, 106, 109), ("Lob", "Finesse"): (102, 102, 102, 103),
    ("Lob", "Medium"): (101, 102, 102, 102), ("Lob", "Powerful"): (101, 100, 99, 98),
}
RETAIL_LEVELS = (30, 54, 75, 100)


def retail_speed(cls, hold, power_rating, timing):
    tier = {"Overcharge": "Powerful", "Rushed": "Medium"}.get(hold, hold)
    v = M.pwl(list(zip(RETAIL_LEVELS, RETAIL_1B[(cls, tier)])), power_rating)
    v -= {"Perfect": 0.0, "Good": 1.5, "Poor": 3.0, "Mistimed": 5.0}[timing]   # retune-baseline 1e: <= 5 km/h
    return M.mph(v)


def mc_forehands(name, n, seed, sit=None, overcharge_try=0.8):
    skills, style = SPEC_STYLE[name]
    p = M.Player(name, M.ARCH[name], skills, style)
    rng = random.Random(seed)
    v, vr = [], []
    G, H, T = collections.Counter(), collections.Counter(), collections.Counter()
    for _ in range(n):
        s = M.sample_situation(rng, sit or M.SIT)
        o = M.forehand_shot(rng, p, s, overcharge_try=overcharge_try)
        v.append(o["mph"])
        vr.append(retail_speed(o["cls"], o["hold"], M.ARCH[name]["power"], o["timing"]))
        G[o["grade"]] += 1
        H[o["hold"]] += 1
        T[o["timing"]] += 1
    v.sort()
    vr.sort()
    return v, vr, G, H, T


def pct(v, q):
    return v[min(len(v) - 1, int(q * len(v)))]


def sec_speed(a):
    n = 60000 if a.quick else 600000
    out = ["### 2a. Stacking table: from the average rally ball to the absolute peak (forehand launch, mph) *(computed)*", ""]
    rows = []
    for name in ("average pro", "elite all-rounder", "pace specialist"):
        p = M.Player(name, M.ARCH[name])
        st = p.s
        r = M.RATING_MPH[0] * (st["power"] - 0.5) + M.RATING_MPH[1] * (st["fh"] - 0.5)
        sk = M.SKILL_MPH if name == "pace specialist" else 0.0
        steps = [M.BASE_MPH["TopSpin"], M.BASE_MPH["Flat"], M.BASE_MPH["Flat"] + r,
                 M.BASE_MPH["Flat"] + r + M.HOLD_MPH["Powerful"],
                 M.BASE_MPH["Flat"] + r + M.HOLD_MPH["Powerful"] + M.GRADE_FX["VeryGood"]["pace"],
                 M.BASE_MPH["Flat"] + r + M.HOLD_MPH["Powerful"] + M.GRADE_FX["Tee-off"]["pace"],
                 M.BASE_MPH["Flat"] + r + M.HOLD_MPH["Powerful"] + M.GRADE_FX["Tee-off"]["pace"] + M.TIMING_MPH["Perfect"],
                 M.BASE_MPH["Flat"] + r + M.HOLD_MPH["Overcharge"] + M.GRADE_FX["Tee-off"]["pace"] + M.TIMING_MPH["Perfect"],
                 M.BASE_MPH["Flat"] + r + M.HOLD_MPH["Overcharge"] + M.GRADE_FX["Tee-off"]["pace"] + M.TIMING_MPH["Perfect"] + sk]
        rows.append([name] + [f1(x) for x in steps])
    out.append(md(["build", "rally topspin (Good, Medium, Good timing)", "flat drive", "+ ratings",
                   "+ Powerful hold (+%g)" % M.HOLD_MPH["Powerful"], "+ VeryGood grade (+%g)" % M.GRADE_FX["VeryGood"]["pace"],
                   "Tee-off instead (+%g)" % M.GRADE_FX["Tee-off"]["pace"], "+ Perfect timing (+%g)" % M.TIMING_MPH["Perfect"],
                   "Overcharge instead of Powerful (+%g)" % M.HOLD_MPH["Overcharge"], "+ pace skill (+%g) = full-stack mean" % M.SKILL_MPH],
                  rows))
    out += ["", "Before the ceiling. Above %g mph the excess is halved and %g mph is a hard ceiling (backhand: knee %g, ceiling %g), "
            "so the full stacks land at %s." % (M.CEILING["FH"]["knee"], M.CEILING["FH"]["max"], M.CEILING["BH"]["knee"], M.CEILING["BH"]["max"],
                                               ", ".join("%.1f" % min(110.0, x if x <= 100 else 100 + (x - 100) * 0.5) for x in [float(r[-1]) for r in rows])),
            "Full-stack mean is the centre of the peak; the execution spread (sd %.1f mph) puts the far tail on it. "
            "Grade caps (soft, %d %% of the excess survives): %s." % (M.NOISE_MPH, round(M.CAP_SOFTNESS * 100),
                                                                     ", ".join("%s %s" % (g, "none" if M.GRADE_FX[g]["cap"] is None else "%g" % M.GRADE_FX[g]["cap"]) for g in M.GRADES)), ""]

    out += ["### 2b. Monte Carlo over rally situations: forehand launch speed (mph) *(computed, %d forehands per build)*" % n, ""]
    rows, rows2, freq = [], [], []
    for i, name in enumerate(("average pro", "elite all-rounder", "pace specialist")):
        v, vr, G, H, T = mc_forehands(name, n, 100 + i)
        mean = sum(v) / n
        rmean = sum(vr) / n
        ex = [sum(1 for x in v if x > t) * 1000.0 / n for t in (100, 104, 106, 108, 109, 109.9)]
        rows.append([name, f1(mean), f1(pct(v, .5)), f1(pct(v, .9)), f1(pct(v, .99)), f1(pct(v, .999)), f1(v[-1]),
                     f1(rmean), f1(vr[-1])])
        rows2.append([name] + ["%.3g / %.2g" % (e, e * FH_PER_MATCH / 1000.0) for e in ex] +
                     ["%.2g" % (ex[-2] * FH_PER_SEASON / 1000.0)])
        freq.append([name] + [f3(G[g] / n) for g in M.GRADES] + [f3(H[h] / n) for h in ("Finesse", "Medium", "Powerful", "Rushed", "Overcharge")]
                    + [f3(T[t] / n) for t in ("Perfect", "Good", "Poor", "Mistimed")])
    out.append(md(["build", "mean", "p50", "p90", "p99", "p99.9", "max", "retail mean (same shots)", "retail max"], rows))
    out += ["", "Exceedances: per 1,000 forehands / per match (%d forehands); last column per season (%d forehands):" % (FH_PER_MATCH, FH_PER_SEASON), ""]
    out.append(md(["build", "> 100", "> 104", "> 106", "> 108", "> 109", "at the 110 cap (> 109.9)", "> 109 per season"], rows2))
    out += ["", "Resulting frequencies (share of forehands) of grade, hold and timing:", ""]
    out.append(md(["build"] + M.GRADES + ["Finesse", "Medium", "Powerful", "Rushed", "Overcharge", "Perfect", "Good", "Poor", "Mistimed"], freq))

    out += ["", "### 2c. Sensitivity of the tail to the situation assumptions *(computed, %d forehands each)*" % (n // 3), ""]
    variants = [("as proposed", {}, 0.8, None), ("short balls x0.5", {"short_share": M.SIT["short_share"] * 0.5}, 0.8, None),
                ("short balls x2", {"short_share": M.SIT["short_share"] * 2}, 0.8, None),
                ("incoming pace sd 6", {"pace_mph_sd": 6.0}, 0.8, None), ("incoming pace sd 12", {"pace_mph_sd": 12.0}, 0.8, None),
                ("lateral run x0.7", {"wide_scale_cm": M.SIT["wide_scale_cm"] * 0.7}, 0.8, None),
                ("lateral run x1.4", {"wide_scale_cm": M.SIT["wide_scale_cm"] * 1.4}, 0.8, None),
                ("overcharge tried 50 %", {}, 0.5, None), ("overcharge always tried", {}, 1.0, None),
                ("human timing sd 2.8 frames", {}, 0.8, 2.8), ("human timing sd 4.0 frames", {}, 0.8, 4.0)]
    rows = []
    sig0 = M.HUMAN_SIGMA_F
    for label, ov, oc, sig in variants:
        sit = dict(M.SIT)
        sit.update(ov)
        if sig:
            M.HUMAN_SIGMA_F = sig
        try:
            vs, _, G, _, _ = mc_forehands("pace specialist", n // 3, 7, sit, oc)
            va, _, _, _, _ = mc_forehands("average pro", n // 6, 8, sit, oc)
        finally:
            M.HUMAN_SIGMA_F = sig0
        k = len(vs)
        rows.append([label, f1(sum(va) / len(va)), f1(sum(vs) / k), f3(G["Tee-off"] / k),
                     f2(sum(1 for x in vs if x > 106) * 1000.0 / k), f2(sum(1 for x in vs if x > 108) * 1000.0 / k),
                     f3(sum(1 for x in vs if x > 109.9) * 1000.0 / k)])
    out.append(md(["variant", "average pro mean", "specialist mean", "specialist Tee-off share", "> 106 per 1,000",
                   "> 108 per 1,000", "at the 110 cap per 1,000"], rows))
    return "\n".join(out)


# --------------------------------------------------------------------------- serve

def sec_serve(a):
    n = 30000 if a.quick else 200000
    ret = M.Player("returner", M.ARCH["average pro"])
    out = ["### 2d. Serves: first and second serve over a match's mix of efforts *(computed, %d points per build, returner = average pro)*" % n, ""]
    rows = []
    for i, name in enumerate(M.ARCH):
        p = M.Player(name, M.ARCH[name])
        rng = random.Random(30 + i)
        maxe = 0.04 if name == "pace specialist" else 0.0
        sp, sp2, un, un2, ins, df, ex = [], [], 0, [], 0, 0, collections.Counter()
        for _ in range(n):
            e = 1.0 if rng.random() < maxe else rng.betavariate(2, 3)
            g = M.timing_outcome(rng, *M.window_halfwidths(60, 700, 130, 0, 0, 30, False, 1200, True, p.s["serve"])[:2])
            v, ok, c, _ = M.first_serve(rng, p, e, 1.0, g)
            sp.append(v)
            if ok:
                ins += 1
                q, _ = M.return_quality(rng, ret, v, rng.random())
                un += q == "unreturned"
            else:
                v2, ok2, _, _ = M.second_serve(rng, p, big=p.s["serve"] > 0.7)
                sp2.append(v2)
                df += not ok2
                if ok2:
                    q2, _ = M.return_quality(rng, ret, v2, rng.random() * 0.8, second=True)
                    un2.append(q2 == "unreturned")
        sp.sort()
        k = len(sp)
        rows.append([name, f1(sum(sp) / k), f1(pct(sp, .9)), f1(pct(sp, .99)), f1(sp[-1]),
                     "%.2g / %.2g" % (sum(1 for x in sp if x > 140) * 1000.0 / k, sum(1 for x in sp if x > 140) * SERVES_PER_MATCH / k),
                     "%.2g / %.2g" % (sum(1 for x in sp if x > 148) * 1000.0 / k, sum(1 for x in sp if x > 148) * SERVES_PER_MATCH / k),
                     f3(ins / n), f3(un / max(1, ins)), f1(sum(sp2) / len(sp2)), f3(sum(un2) / len(un2)), f3(df / n)])
    out.append(md(["server", "1st mean", "p90", "p99", "max", "> 140 per 1,000 / per match", "> 148 per 1,000 / per match",
                   "1st in", "unreturned (incl. aces) / 1st in", "2nd mean", "unreturned / 2nd in", "double faults / point"], rows))
    out += ["", "Effort against speed, first-serve-in probability and stamina cost (pace specialist, Perfect gauge, fresh):", ""]
    p = M.Player("s", M.ARCH["pace specialist"])
    rows = []
    for e in (0.0, 0.2, 0.4, 0.6, 0.8, 0.9, 1.0):
        rng = random.Random(1)
        vs, pins = [], []
        for _ in range(4000):
            v, ok, c, pin = M.first_serve(rng, p, e, 1.0, "Perfect")
            vs.append(v)
            pins.append(pin)
        rows.append([f1(e), f1(sum(vs) / len(vs)), f3(sum(pins) / len(pins)), f2(c),
                     f1(M.serve_react_ms(sum(vs) / len(vs)))])
    out.append(md(["effort", "speed mph", "P(1st in)", "stamina units", "returner's time ms"], rows))
    return "\n".join(out)


# --------------------------------------------------------------------------- section 3: flight and bounce

SCEN = {"ground_cc": ((-1188, 100, 150), (1000, 0, -300)), "deep_cc": ((-1188, 100, 150), (1090, 0, -300)),
        "serve_T": ((-1200, 270, 50), (600, 0, 10)), "volley": ((-250, 110, 0), (1000, 0, -200)),
        "drop": ((-800, 80, 0), (300, 0, -50)), "lob": ((-1250, 100, 100), (1050, 0, -100))}

# Proposed template edits (spec section 3).  Bounce: speed loss as a function of spin_a (curve16 keys
# (spin_a0, spin_a1, loss0, loss1)); retail is (-0.2, 0, 0.10, -0.15): the ball speeds up 15 % when flat.
BOUNCE_PROP = [(-0.30, 0.0, 0.16, 0.22)]           # topspin keeps more speed (0.84), flat loses 22 % (0.78)
BOUNCE_SLICE = [(0.0, 0.20, 0.22, 0.30)]           # slice: 22..30 % loss, it slows after the bounce
PROPOSED = {
    # name: (retail row, edits)
    "Flat drive (FlatNormal Powerful)": (10, dict(primary_kmh=(178.0, 200.0), T=0.050, spin_a=(-0.04, -0.30), bounce_loss=BOUNCE_PROP)),
    "TopSpin drive (TopSpinNormal Powerful)": (8, dict(primary_kmh=(150.0, 168.0), T=0.0525, spin_a=(-0.10, -0.42), bounce_loss=BOUNCE_PROP,
                                                      out_elev_gain=1.08)),
    "Slice (SliceNormal Powerful)": (9, dict(primary_kmh=(118.0, 132.0), T=0.050, spin_a=(0.06, 0.18), bounce_loss=BOUNCE_SLICE,
                                             out_elev_gain=0.85)),
}


def pf_for_speed(row, frm, to, target_kmh, blend=0.5):
    """Smallest PF (0.005 steps) whose launch reaches target_kmh; None if PF 1 does not.  A scan, not a bisection:
    the net-clearance raise makes launch speed non-monotone in PF near the top."""
    for i in range(201):
        pf = i * 0.005
        if F.game_fly(row, frm, to, pf=pf, blend=blend)["launch_kmh"] >= target_kmh:
            return pf
    return None


def sec_flight(a):
    rows_all = F.load_rows()
    out = ["### 3a. Retail against proposed rows: one cross-court drive (hitter on the baseline at 1.0 m, target 1.9 m inside the opposite baseline) *(computed, game model)*", ""]
    hdr = ["shot", "row", "PF / blend", "launch", "net clear m", "apex m", "bounce in", "bounce out", "out/in", "bounce height m",
           "at baseline", "to baseline s"]
    rows = []

    def row_cells(label, r, pf, blend, sc="ground_cc"):
        d = F.game_fly(r, *SCEN[sc], pf=pf, blend=blend)
        return [label, r.get("index", "-"), "%.2f / %.2f" % (pf, blend), "%.0f (%.0f)" % (d["launch_kmh"], F.kmh_to_mph(d["launch_kmh"])),
                f2(d["net_clear_m"]), f2(d["apex_m"]), "%.0f" % d["bounce_in_kmh"], "%.0f" % d["bounce_out_kmh"],
                f2(d["out_over_in"]), f2(d["bounce_apex_m"]), "-" if d["baseline_kmh"] is None else "%.0f" % d["baseline_kmh"],
                "-" if d["t_baseline"] is None else f2(d["t_baseline"])]
    # retail at median PF (retune-baseline 1b) and at PF 1
    rows.append(row_cells("retail Flat Powerful, median stats", rows_all[10], 0.76, 0.76))
    rows.append(row_cells("retail TopSpin Powerful, median", rows_all[8], 0.82, 0.86))
    rows.append(row_cells("retail Slice Powerful, median", rows_all[9], 0.79, 0.79))
    props = {}
    for label, (idx, ed) in PROPOSED.items():
        props[label] = F.edit_row(rows_all[idx], **ed)
        props[label]["index"] = "%d*" % idx
    flat, top, sl = (props[k] for k in PROPOSED)
    for tgt, lab, bl, sc in ((72, "rally", 0.3, "ground_cc"), (80, "firm", 0.3, "ground_cc"), (95, "big", 0.3, "ground_cc"),
                             (113, "peak, deep", 1.0, "deep_cc")):
        pf = pf_for_speed(flat, *SCEN[sc], F.mph_to_kmh(tgt), blend=bl)
        if pf is not None:
            rows.append(row_cells("proposed flat, %s %d mph (blend %.1f)" % (lab, tgt, bl), flat, pf, bl, sc))
    for tgt, lab, bl in ((70, "rally", 0.6), (72, "rally", 0.8), (85, "heavy", 1.0), (95, "big", 0.8)):
        pf = pf_for_speed(top, *SCEN["ground_cc"], F.mph_to_kmh(tgt), blend=bl)
        if pf is not None:
            rows.append(row_cells("proposed topspin, %s %d mph (blend %.1f)" % (lab, tgt, bl), top, pf, bl))
    for tgt in (60, 66):
        pf = pf_for_speed(sl, *SCEN["ground_cc"], F.mph_to_kmh(tgt), blend=0.8)
        if pf is not None:
            rows.append(row_cells("proposed slice %d mph" % tgt, sl, pf, 0.8))
    out.append(md(hdr, rows))
    out += ["", "Speeds km/h (launch also mph). `*` = proposed copy of that retail row (fields in the spec). The PF (PowerfulFactor, "
            "the secondary weight) needed for each target speed is solved by bisection; the speed model of section 2 maps to PF this way.", ""]

    out += ["### 3b. Real-ball reference (quadratic drag Cd 0.507, Magnus lift, grip/slip bounce) for the same launches *(computed, reference model)*", ""]
    rows = []
    cases = [("flat 72 mph, 1,200 rpm topspin", 72, 1200, True, 10.0), ("topspin 72 mph, 2,700 rpm", 72, 2700, True, 10.0),
             ("topspin 85 mph, 3,200 rpm", 85, 3200, True, 10.0), ("flat 95 mph, 1,500 rpm", 95, 1500, True, 10.0),
             ("flat 113 mph, 1,500 rpm, deep", 113, 1500, True, 10.9), ("flat 113 mph, 2,500 rpm, deep", 113, 2500, True, 10.9),
             ("slice 60 mph, 1,500 rpm backspin", 60, 1500, False, 10.0)]
    for label, v, rpm, top_, land in cases:
        for surf in ("clay", "hard", "grass"):
            r = F.real_aim(F.mph_to_kmh(v), rpm, land, topspin=top_, surface=surf)
            rows.append([label, surf, "%.1f" % F.cpr(*F.SURFACES[surf]), f1(r["angle_deg"]), f2(r["net_clear_m"]), f2(r["apex_m"]),
                         "%.0f" % r["bounce_in_kmh"], "%.0f" % r["bounce_out_kmh"], f2(r["out_over_in"]), f2(r["bounce_apex_m"]),
                         "-" if r["baseline_kmh"] is None else "%.0f" % r["baseline_kmh"], f2(r["t_bounce"]),
                         "-" if r["t_baseline"] is None else f2(r["t_baseline"])])
    out.append(md(["launch", "surface", "ITF CPR", "launch deg", "net clear m", "apex m", "bounce in", "bounce out", "out/in",
                   "bounce height m", "at baseline", "to bounce s", "to baseline s"], rows))

    out += ["", "### 3c. The flat 113 mph forehand: what it must look like *(computed)*", ""]
    rows = []
    for land in (9.5, 10.5, 11.2):
        for rpm in (800, 1500, 2500):
            r = F.real_aim(F.mph_to_kmh(113), rpm, land)
            rows.append(["real", "%.1f m past the net (%.1f m inside)" % (land, F.BASELINE_X_M - land), rpm, f1(r["angle_deg"]),
                         f2(r["net_clear_m"]), f2(r["apex_m"]), f2(r["t_bounce"])])
    for depth_cm, bl in ((1000, 0.3), (1000, 1.0), (1050, 1.0), (1100, 0.3), (1100, 1.0)):
        to = (depth_cm, 0, -300)
        pf = pf_for_speed(flat, SCEN["ground_cc"][0], to, F.mph_to_kmh(113), blend=bl)
        if pf is None:
            continue
        d = F.game_fly(flat, SCEN["ground_cc"][0], to, pf=pf, blend=bl)
        rows.append(["game, proposed flat row", "%.1f m past the net" % (depth_cm / 100.0), "spin blend %.1f (spin_a %.3f)" % (bl, d["spin_a"]),
                     "-", f2(d["net_clear_m"]), f2(d["apex_m"]), f2(d["t_bounce"])])
    out.append(md(["model", "landing", "spin", "launch deg", "net clear m", "apex m", "to bounce s"], rows))

    out += ["", "### 3d. Other shots: retail and proposed *(computed, game model)*", ""]
    rows = []
    for label, idx, sc, pf, bl in (("Drop shot (row 32)", 32, "drop", 0.81, 0.81), ("Lob Medium (row 7)", 7, "lob", 0.19, 0.19),
                                   ("Volley flat (row 19)", 19, "volley", 0.86, 0.86), ("Serve flat Powerful (row 27)", 27, "serve_T", 0.56, 0.56),
                                   ("Serve flat Powerful (row 27), PF 1", 27, "serve_T", 1.0, 1.0)):
        rows.append(row_cells("retail " + label, rows_all[idx], pf, bl, sc)[:1] + row_cells("retail " + label, rows_all[idx], pf, bl, sc)[2:])
    srv = F.edit_row(rows_all[27], primary_kmh=(245.0, 245.0))
    srv["index"] = "27*"
    for tgt in (100, 120, 135, 150):
        pf = pf_for_speed(srv, *SCEN["serve_T"], F.mph_to_kmh(tgt), blend=0.5)
        if pf is not None:
            rows.append(row_cells("proposed flat serve %d mph" % tgt, srv, pf, 0.5, "serve_T")[:1] + row_cells("x", srv, pf, 0.5, "serve_T")[2:])
    out.append(md([hdr[0]] + hdr[2:], rows))
    return "\n".join(out)


# --------------------------------------------------------------------------- section 4: grade

GRADE_CASES = [  # label, frames, v_req, run_cm, height, pace km/h at contact, depth_x, set_f, stretch, kick
    ("sitter: short floater, watched all the way", 100, 0.8, 60, 110, 45, -250, 40, False, 0.1),
    ("neutral baseline rally ball", 78, 2.0, 150, 100, 68, 100, 15, False, 0.15),
    ("deep heavy topspin to the backhand", 72, 2.2, 160, 165, 66, 250, 8, False, 0.45),
    ("hard flat drive, little time", 58, 2.5, 180, 95, 92, 120, 4, False, 0.05),
    ("run wide, arrive late", 70, 5.8, 420, 85, 70, 150, 0, True, 0.15),
    ("low slice at the feet", 82, 1.8, 120, 40, 52, 80, 12, False, 0.0),
    ("pushed 4 m behind the baseline", 75, 3.0, 220, 120, 70, 420, 6, False, 0.3),
]


def sec_grade(a):
    out = ["### 4a. Penalty points per input *(proposal; judgement calls, see text)*", ""]
    rows = [["frames from the opponent's contact (S+0xCF0)", " ".join("%g:%g" % k for k in M.P_TIME), "groundstrokes"],
            ["same, volleys", " ".join("%g:%g" % k for k in M.P_TIME_VOLLEY), "volleys"],
            ["required run speed / own top speed (S+0x7A4 / Speed)", " ".join("%g:%g" % k for k in M.P_RUN), "top speed = %g + %g x Speed stat m/s" % (M.RALLY["max_run_base"], M.RALLY["max_run_speed"])],
            ["contact height low (Ball+0x344, cm)", " ".join("%g:%g" % k for k in M.P_LOW), ""],
            ["contact height high (cm)", " ".join("%g:%g" % k for k in M.P_HIGH), ""],
            ["incoming pace at contact (km/h; S+0x770 needs its writer)", " ".join("%g:%g" % k for k in M.P_PACE), "volleys: " + " ".join("%g:%g" % k for k in M.P_PACE_VOLLEY)],
            ["own depth behind the baseline (cm)", " ".join("%g:%g" % k for k in M.P_DEEP), "inside the court with >= 60 frames: %g" % M.INSIDE_BONUS],
            ["incoming kick (|spin_a|)", " ".join("%g:%g" % k for k in M.P_KICK), ""],
            ["stretch (SwingCategory reach #0698037d, or v_req > 5.2 m/s felt)", "%g" % M.STRETCH_PTS, ""],
            ["not set (planted < 6 frames at contact)", "%g" % M.UNSET_PTS, "groundstrokes only"]]
    out.append(md(["input (engine field)", "points (x:points, linear between, clamped)", "note"], rows))
    out += ["", "Grade from the sum Q: VeryGood < %g <= Good < %g <= Normal < %g <= Bad < %g <= VeryBad." % tuple(M.GRADE_EDGES), "",
            "**Tee-off** is a separate gate, every condition required (the Q score is not one of them, so a ball the player stands still "
            "for is VeryGood unless the ball itself is weak):", ""]
    T = M.TEEOFF
    out.append(md(["condition", "threshold", "engine value it is set from"], [
        ["slow ball at arrival", "contact pace <= %g km/h" % T["pace_max"], "S+0x770 incoming pace (needs its writer); a neutral rally ball arrives at 60-75 km/h"],
        ["contact between waist and shoulder", "%g-%g cm" % (T["h_lo"], T["h_hi"]), "Ball+0x344; Fatality clips are shoulder height"],
        ["about a second since the opponent's hit", ">= %d frames" % T["frames_min"], "S+0xCF0 >= 60, the AutoSwing test (graph 179)"],
        ["no reach swing", "required run speed < %g m/s, not stretched" % T["vreq_max"], "PT+0x1B0 = 3.5 m/s, the FlatGoodReach threshold; reach qualifier #0698037d"],
        ["feet set", "within %g cm of the hit point, arrived >= %d frames before contact" % (T["run_max"], T["set_min"]), "S+0x7A0 run distance; planner arrival frame"],
        ["not backing up", "contact not more than %g cm behind the baseline, not moving back" % T["depth_max"], "contact x; Mover velocity S+0x9xx (3-frame mean)"],
    ]))
    out += ["", "Volley Tee-off = the put-away: Q <= 0.5, pace <= 75 km/h, contact >= 110 cm, >= 30 frames.", ""]
    out += ["### 4b. What each grade gives *(proposal)*", ""]
    rows = []
    for g in M.GRADES:
        fx = M.GRADE_FX[g]
        rows.append([g, "%+g" % fx["pace"], "none (peak reachable)" if fx["cap"] is None else "%g (topspin %g)" % (fx["cap"], fx["cap"] - 4),
                     "x%.2f" % fx["spin"], "%.2f-%.2f" % M.AIM_GRADE_ROW[g], "x%.1f %+.2f" % (fx["err"], fx["err_add"]), "%d" % fx["depth_cm"],
                     "x%.2f" % fx["window"]])
    out.append(md(["grade", "pace mph", "soft pace cap mph", "spin", "AimingResolution Min-Max (7a)", "error (x, +)", "DeepDeviation at Perfect, cm (7b)", "typical window"], rows))
    out += ["", "### 4c. Worked situations *(computed)*", ""]
    rows = []
    for c in GRADE_CASES:
        g, q, pts = M.grade_of(*c[1:])
        rows.append([c[0], c[1], f1(c[2]), c[4], c[5], c[6], f2(q), g, ", ".join("%s %.1f" % (k, v) for k, v in pts.items() if abs(v) > 0.05)])
    out.append(md(["situation", "frames", "v_req m/s", "height cm", "pace km/h", "depth cm", "Q", "grade", "points"], rows))
    return "\n".join(out)


# --------------------------------------------------------------------------- section 5: window

WINDOW_CASES = [  # label, pace km/h at contact, react ms, height, kick, v_req, set_f, stretch, dist_net, floating
    ("baseline rally ball (72 mph shot, 1.3 s)", 68, 1300, 100, 0.15, 2.0, 15, False, 1290, False),
    ("sitter: short floater", 45, 1650, 110, 0.1, 0.8, 40, False, 940, True),
    ("heavy kick, shoulder high", 66, 1200, 170, 0.45, 2.2, 8, False, 1430, False),
    ("hard flat drive, 0.95 s", 92, 950, 95, 0.05, 2.5, 4, False, 1310, False),
    ("return of a 120 mph serve", 120, M.serve_react_ms(120), 115, 0.1, 2.5, 4, False, 1300, False),
    ("return of a 145 mph serve", 145, M.serve_react_ms(145), 120, 0.1, 3.0, 2, False, 1300, False),
    ("first volley off a good approach (weak pass, 0.62 s)", 70, 620, 110, 0.1, 1.0, 0, False, 350, False),
    ("first volley off a bad approach (hard pass at the feet, 0.42 s)", 105, 420, 45, 0.25, 2.0, 0, False, 600, False),
    ("put-away at the net (floater, 0.9 s)", 50, 900, 150, 0.0, 0.5, 20, False, 250, True),
    ("ball run down from a drop shot", 35, 1500, 45, 0.0, 6.0, 0, True, 300, False),
]


def sec_window(a):
    out = ["### 5a. Perfect and Good windows in worked cases (frames) *(computed)*", "",
           "Half-widths each side of the 20-frame target; width = 2 x half + 1 frame. P = probability for a human with release-error sd %.1f frames; "
           "rating = the stroke's timing stat (hand stat / Volley / Return). Retail: Perfect |t| < 0.1 = 2 frames each side, Good |t| < 0.3 = 5.8, for every ball." % M.HUMAN_SIGMA_F, ""]
    rows = []
    for c in WINDOW_CASES:
        cells = [c[0], "%.0f" % c[2]]
        for stat_r in (50, 80, 100):
            hp, hg, e = M.window_halfwidths(c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9], M.new_stat(stat_r))
            cells.append("%.1f / %.1f (P %.2f / %.2f)" % (hp, hg, M.p_window(hp), M.p_window(hg)))
        rows.append(cells)
    out.append(md(["case", "time ms", "rating 50: Perfect / Good half (P)", "rating 80", "rating 100"], rows))
    out += ["", "Ease factors behind each case (rating 80):", ""]
    rows = []
    for c in WINDOW_CASES:
        f = M.ease_factors(*c[1:])
        rows.append([c[0]] + [f2(f[k]) for k in ("pace", "reaction", "height", "kick", "movement", "position", "floating")])
    out.append(md(["case", "pace", "reaction", "height", "kick", "movement", "net with time", "floating"], rows))
    out += ["", "### 5b. Reaction-time threshold *(proposal, anchored on sourced reaction data)*", ""]
    out.append(md(["time from the opponent's contact (ms)"] + ["%d" % x for x, _ in M.RT_CURVE] + ["1000+"],
                  [["window factor"] + [f2(y) for _, y in M.RT_CURVE] + ["1.00"]]))
    out += ["", "Opponent's last timing grade (direct term, owner's change): " +
            ", ".join("%s x%.2f" % (k, v) for k, v in M.OPP_TIMING_FX.items()) + "; clamp %.2f..%.2f; applied to this shot only." % M.OPP_FX_CAP]
    return "\n".join(out)


def sec_oppterm(a):
    nm = 30 if a.quick else 160
    out = ["### 5c. Sizing the direct opponent-timing term with the rally simulation *(computed, %d matches per row, elite all-rounder mirror)*" % nm, ""]
    rows = []
    A = M.ARCH["elite all-rounder"]
    for sc in (0.0, 0.5, 1.0, 1.5, 2.0):
        rng = random.Random(77)
        tot = collections.Counter()
        trace = []
        prm = {"opp_scale": sc, "trace": trace}
        for _ in range(nm):
            p = M.MatchPlayer("a", A, {"flat": 0.35})
            q = M.MatchPlayer("b", A, {"flat": 0.35})
            w, st = M.play_match(rng, p, q, prm)
            tot.update(st)
        P = tot["points"]
        after = collections.Counter()
        for inc, own, outc in trace:
            if own is None:
                continue
            after[(inc, own)] += 1
        pool = {"Average": "Good"}
        after = collections.Counter()
        for inc, own, outc in trace:
            if own is not None:
                after[(pool.get(inc, inc), own)] += 1
        def p_perf(inc):
            t = sum(after[(inc, o)] for o in ("Perfect", "Good", "Poor", "Mistimed"))
            return after[(inc, "Perfect")] / t if t else 0.0
        def p_err(inc):
            t = sum(1 for i, o, oc in trace if pool.get(i, i) == inc and o is not None)
            e = sum(1 for i, o, oc in trace if pool.get(i, i) == inc and oc == "error")
            return e / t if t else 0.0
        fac = lambda k: M.clamp(1.0 + (M.OPP_TIMING_FX[k] - 1) * sc, *M.OPP_FX_CAP)
        rows.append([f1(sc), " / ".join("%.2f" % fac(k) for k in ("Perfect", "Good", "Average", "Poor", "Mistimed")),
            f2(tot["shots"] / P), f3(tot["timing_err"] / P), f3(tot["err"] / P), f3(tot["winners"] / P),
            f3(p_perf("Perfect")), f3(p_perf("Good")), f3(p_perf("Poor")), f3(p_err("Perfect")), f3(p_err("Poor"))])
    out.append(md(["scale", "factor after Perfect / Good / Average / Poor / Mistimed", "shots per point", "points ended by a timing error",
                   "points ended by any error", "winners", "P(Perfect) after opp. Perfect", "after opp. Good", "after opp. Poor",
                   "P(error) after opp. Perfect", "after opp. Poor"], rows))
    out += ["", "Scale 1.0 is the owner's starting sizes (%s); ball ease x this term floored at %.2f of the normal window; "
            "'after opp. Good' pools the opponent's Good and Average releases." % (
        ", ".join("%s x%.2f" % kv for kv in M.OPP_TIMING_FX.items()), M.TOTAL_FLOOR)]
    return "\n".join(out)


def sec_teeoff(a):
    nm = 20 if a.quick else 120
    out = ["### 4d. Tee-off frequency in matches between equals *(computed, %d best-of-3 matches per row)*" % nm, ""]
    rows = []
    for name in ("average pro", "elite all-rounder"):
        rng = random.Random(41)
        G = collections.Counter()
        tot = collections.Counter()
        for _ in range(nm):
            p = M.MatchPlayer("a", M.ARCH[name], {"flat": 0.35})
            q = M.MatchPlayer("b", M.ARCH[name], {"flat": 0.35})
            w, st = M.play_match(rng, p, q, {"grades": G})
            tot.update(st)
        ground = sum(v for (g, net), v in G.items() if not net)
        tee_g = G[("Tee-off", False)]
        tee_v = G[("Tee-off", True)]
        vg = G[("VeryGood", False)]
        sets = tot["sets"]
        rows.append([name, "%.0f" % (ground / sets / 2), f1(tee_g / sets / 2), f1(tee_v / sets / 2), f3(tee_g / max(1, ground)),
                     f3(vg / max(1, ground))])
    out.append(md(["players", "groundstrokes per player per set", "Tee-off groundstrokes per player per set",
                   "volley put-aways (Tee-off) per player per set", "Tee-off share of groundstrokes", "VeryGood share"], rows))
    return "\n".join(out)


# --------------------------------------------------------------------------- section 6: power swing

def sec_power(a):
    c = M.CHARGE
    out = ["### 6a. Charge, rushed swing and overcharge *(proposal)*", ""]
    rows = [["Finesse (tap)", "< %d (retail < 12)" % c["medium_from"], "%+g mph" % M.HOLD_MPH["Finesse"], "normal", "%g" % M.RALLY["vigor_cost"]["Finesse"]],
            ["Medium", "%d-%d (retail 12-52)" % (c["medium_from"], c["powerful_from"] - 1), "0", "normal", "%g" % M.RALLY["vigor_cost"]["Medium"]],
            ["Powerful", ">= %d, full at %d (retail >= 53, full at 75)" % (c["powerful_from"], c["full_at"]), "%+g mph" % M.HOLD_MPH["Powerful"], "normal", "%g" % M.RALLY["vigor_cost"]["Powerful"]],
            ["Rushed (the 12-frame auto-commit froze the meter below the tier aimed for)", "-", "%+g mph" % M.HOLD_MPH["Rushed"], "Perfect x0.7, Good x0.8", "%g" % M.RALLY["vigor_cost"]["Rushed"]],
            ["Overcharge (meter full, planted and waiting >= %d frames; new state, retail has none)" % c["overcharge_wait"], ">= %d + %d" % (c["full_at"], c["overcharge_wait"]),
             "%+g mph" % M.HOLD_MPH["Overcharge"], "Perfect x0.5, timing error x2", "%g" % M.RALLY["vigor_cost"]["Overcharge"]]]
    out.append(md(["swing", "frames held (60/s)", "pace", "window / error", "vigor per swing (simulation units)"], rows))
    out += ["", "Press-to-contact lead each needs (release %d frames before contact): Powerful %d, full %d, overcharge %d frames (%.2f s)." % (
        M.RELEASE_LEAD, c["powerful_from"] + M.RELEASE_LEAD, c["full_at"] + M.RELEASE_LEAD, c["full_at"] + c["overcharge_wait"] + M.RELEASE_LEAD,
        (c["full_at"] + c["overcharge_wait"] + M.RELEASE_LEAD) / 60.0)]
    return "\n".join(out)


# --------------------------------------------------------------------------- section 7: placement

TIMING_MIX = (("Perfect", 0.45), ("Good", 0.25), ("Average", 0.20), ("Poor", 0.08), ("Mistimed", 0.02))
AIM_CLASS = {"FlatMedium": ("Flat", "Medium", 76), "TopSpinMedium": ("TopSpin", "Medium", 72), "FlatPower": ("Flat", "Powerful", 84)}
COARSE = {"Perfect": "Perfect", "Good": "Good", "Average": "Good", "Poor": "Poor", "Mistimed": "Mistimed"}


def timing_sampler(rng):
    r = rng.random()
    for t, w in TIMING_MIX:
        r -= w
        if r < 0:
            return t
    return "Mistimed"


def shot_error(cls, grade, tf, stat=0.76, mph=None):
    """The rally model's error probability for a neutral ball (no run, no fatigue, no pass)."""
    c, hold, v = AIM_CLASS[cls]
    v = mph if mph is not None else v + M.GRADE_FX[grade]["pace"]
    fx = M.GRADE_FX[grade]
    margin = M.RALLY["pace_margin"][c] + M.RALLY["margin_hand"] * stat
    return fx["err"] * (M.RALLY["e_timing"][COARSE[tf]] + M.RALLY["pace_err"] * max(0.0, v - margin)) + fx["err_add"]


def sec_placement(a):
    import retune_aim as AIM
    n = 1500 if a.quick else 8000
    T5 = ("Perfect", "Good", "Average", "Poor", "Mistimed")
    out = ["### 7a. How the existing Efficiency is fed *(proposal; retail chain kept)*", "",
           "Efficiency = class peak x lerp(AimingResolution.Min, .Max of the grade row, quality); quality = timing term x "
           "(%.2f + %.2f x hand stat); capped at %.2f. Then retail graph 196 (FinalEfficiency, random roll) picks the quad." % (
               M.AIM_HAND[0], M.AIM_HAND[1], M.EFF_MAX), ""]
    out.append(md(["grade", "AimingResolution Min", "Max", "retail row values (Good used for every shot)"],
                  [[g, f2(M.AIM_GRADE_ROW[g][0]), f2(M.AIM_GRADE_ROW[g][1]),
                    {"Tee-off": "none (VeryGood row + code offset)", "VeryGood": "0-0.2 / 0.6-1", "Good": "0-0.2 / 0.6-1",
                     "Normal": "0 / 0.4-1", "Bad": "0 / 0.1-1", "VeryBad": "0 / 0.1-1"}[g]] for g in M.GRADES]))
    out += ["", "Timing term against the new variable window: " + ", ".join("%s %.2f" % (t, M.AIM_TIMING_Q[t]) for t in T5) +
            " (retail FlatMedium: 0.76 at t = 0, 0.40 at |t| = 0.3, 0.20 at 0.6, so the same shape). Class peaks (retail, kept): " +
            ", ".join("%s %.2f" % kv for kv in M.AIM_CLASS_PEAK.items()) + ".", "",
            "Efficiency, FlatMedium, by grade and timing, hand 0.3 / 0.9 (retail: Good row only; hand 0.3 costs 0.03-0.05):", ""]
    rows = []
    for g in M.GRADES:
        rows.append([g] + ["%.2f / %.2f" % (M.aim_efficiency("FlatMedium", g, t, 0.3), M.aim_efficiency("FlatMedium", g, t, 0.9)) for t in T5])
    out.append(md(["grade"] + list(T5), rows))
    out += ["", "### 7b. DeepDeviation by quality (replaces uniform 0..310 cm at perfect timing) *(proposal)*", ""]
    rows = [[g] + ["%.0f" % min(M.DEEP_MAX_CM, M.DEEP_GRADE_CM[g] + M.DEEP_TIMING_CM[t]) for t in T5] for g in M.GRADES]
    out.append(md(["grade"] + list(T5), rows))
    out += ["", "Mean cm short of the aimed point along the hitter-to-target line; sd %.0f cm, capped at %.0f. Retail: uniform 0..310 cm "
            "(mean 155) at perfect timing, 200-300 cm fixed when mistimed." % (M.DEEP_SD_CM, M.DEEP_MAX_CM), ""]
    out += ["### 7c. Where corner aims land, on the retail aim quads *(computed, %d shots per row)*" % n, "",
            "Stick up-right (deep corner), hitter at (-1188, -50), FlatNormal / TopSpinNormal configs from `aim_tables.yaml`; timing mix "
            + ", ".join("%s %.0f%%" % (t, 100 * w) for t, w in TIMING_MIX) + " (a rating-80 player on neutral balls, section 5); hand 0.76. "
            "Distances in cm: short of the baseline (1188) and in from the sideline (411). P(error) from the rally model on a neutral ball "
            "at the class's typical speed (flat pace raises it).", ""]
    cfgs = AIM.load_configs()
    rows = []
    rng = random.Random(9)
    for cls, cfgname in (("TopSpinMedium", "TopSpinNormal"), ("FlatMedium", "FlatNormal"), ("FlatPower", "FlatNormal")):
        for g in M.GRADES:
            pts, perr = AIM.corner_landings(rng, cfgs[cfgname], cls, g, timing_sampler, 0.76, n, lambda gg, tf: shot_error(cls, gg, tf))
            sb = sorted(1188.0 - x for x, z in pts)
            ss = sorted(411.0 - z for x, z in pts)
            box = sum(1 for x, z in pts if 1188 - x < 100 and 411 - z < 100) / max(1, len(pts))
            rows.append([cls, g, "%.0f (%.0f-%.0f)" % (pct(sb, .5), pct(sb, .1), pct(sb, .9)), "%.0f (%.0f-%.0f)" % (pct(ss, .5), pct(ss, .1), pct(ss, .9)),
                         f2(box), f3(perr)])
        # retail reference: Good row, retail timing values, uniform deep 0..310
        pts = []
        for _ in range(n):
            tf = timing_sampler(rng)
            eff = M.AIM_CLASS_PEAK[cls] * {"Perfect": 1.0, "Good": 0.85, "Average": 0.6, "Poor": 0.5, "Mistimed": 0.26}[tf]
            fe = M.final_efficiency(eff, rng.random())
            dd = rng.uniform(0, 310) if tf in ("Perfect", "Good", "Average") else rng.uniform(200, 300)
            pts.append(AIM.land(cfgs[cfgname], fe, dd, 1.0, 1.0))
        sb = sorted(1188.0 - x for x, z in pts)
        ss = sorted(411.0 - z for x, z in pts)
        box = sum(1 for x, z in pts if 1188 - x < 100 and 411 - z < 100) / len(pts)
        rows.append([cls, "retail (Good row)", "%.0f (%.0f-%.0f)" % (pct(sb, .5), pct(sb, .1), pct(sb, .9)),
                     "%.0f (%.0f-%.0f)" % (pct(ss, .5), pct(ss, .1), pct(ss, .9)), f2(box), "-"])
    out.append(md(["class", "grade", "short of baseline: median (p10-p90)", "in from sideline: median (p10-p90)", "share within 1 m of both lines", "P(error)"], rows))
    out += ["", "### 7d. Is aiming at the corner on every ball dominant? *(computed, elite mirror, %d matches per pair)*" % (16 if a.quick else 80), "",
            "Each build is the elite all-rounder with a different share of balls aimed at the deep corner (the rest at safer directions). "
            "The stick is direction-only, so the corner costs no error in the agreed rules. Row: field share.", ""]
    rows = []
    A = M.ARCH["elite all-rounder"]
    for an in (0.0, M.ANTICIPATION):
        sv = M.ANTICIPATION
        M.ANTICIPATION = an
        try:
            B = {("corner %.2f" % c): (A, {"flat": 0.35, "corner": c}) for c in (0.0, 0.25, 0.5, 0.75, 1.0)}
            r = M.round_robin(B, 16 if a.quick else 80, 3)
        finally:
            M.ANTICIPATION = sv
        rows.append(["%.2f" % an] + [f3(sum(r[k].values()) / 4.0) for k in B])
    out.append(md(["receiver anticipation", "corner 0 %", "25 %", "50 %", "75 %", "100 %"], rows))
    out += ["", "### 7e. Angle access (fraction of the sideline reach usable) *(proposal)*", ""]
    rows = []
    for dx, lab in ((-400, "4 m inside"), (-150, "1.5 m inside"), (0, "on the baseline"), (200, "2 m behind"), (400, "4 m behind")):
        rows.append([lab] + [f2(M.angle_access(dx, g, 0.76)) for g in M.GRADES])
    out.append(md(["position (rating 80)"] + M.GRADES, rows))
    out += ["", "### 7f. Drop shot quality against the incoming ball (touch rating 70) *(proposal)*", ""]
    rows = []
    for lab, pace, h, g in (("slow, mid-height, inside the court", 45, 100, "VeryGood"), ("neutral rally ball", 68, 100, "Good"),
                            ("hard drive", 95, 95, "Normal"), ("low slice", 50, 40, "Good"), ("on the run", 70, 80, "Bad")):
        for t in ("Perfect", "Good", "Poor"):
            land, bounce, err = M.drop_quality(pace, h, g, t, M.new_stat(70))
            rows.append([lab, g, t, "%.0f" % land, "%.0f" % bounce, f2(err)])
    out.append(md(["incoming", "grade", "timing", "lands cm past the net", "bounce height cm", "P(error)"], rows))
    out += ["", "Retail drop shot (row 32): one speed (55 km/h), P(error) 0 at t = 0 and 0.32-0.68 off it, independent of the incoming ball (retune-baseline 3b)."]
    return "\n".join(out)


# --------------------------------------------------------------------------- section 8: net play

def sec_net(a):
    out = ["### 8a. Approach quality against the passer's grade and window *(computed)*", ""]
    rows = []
    for lab, depth_x, height, pace, frames, run in (
            ("deep (1 m from baseline), low skid, 80 mph", 180, 55, 78, 70, 200),
            ("deep, high bounce, 70 mph", 150, 150, 66, 78, 180),
            ("mid-court (4 m inside the baseline), 70 mph", -50, 105, 66, 74, 150),
            ("short (service line), sitting up", -350, 115, 50, 95, 120),
            ("deep to the corner, opponent stretched", 120, 85, 72, 66, 420)):
        vr = run / 100.0 / max(0.2, frames / 60.0 - 0.3)
        g, q, _ = M.grade_of(frames, vr, run, height, pace, depth_x, max(0, frames - 30 - int(run / 100 / 6 * 60)), vr > 5.2 or run > 380)
        hp, hg, e = M.window_halfwidths(pace, frames * 1000 / 60.0, height, 0.1, vr, 10, vr > 5.2, 1188 + depth_x, False, 0.64)
        rows.append([lab, frames, g, f2(q), "%.1f / %.1f" % (hp, hg), f2(M.aim_efficiency("FlatMedium", g, "Perfect", 0.64)), f2(M.angle_access(depth_x, g, 0.64))])
    out.append(md(["approach", "passer's frames", "passer's grade", "Q", "Perfect / Good half (rating 70)", "passer's Efficiency (FlatMedium, Perfect)", "angle access"], rows))
    out += ["", "### 8b. Volley quality bands: the cost of a hard volley is a weak reply *(proposal; judgement values)*", "",
            "Band = volley grade (Tee-off / VeryGood 1, Good / Normal 2, Bad 3, VeryBad 4) + timing (Poor +1, Mistimed +2), then one band "
            "better at a Volley stat >= %.2f (rating about 75+). Outputs are the volley classes' existing outputs." % M.VOLLEY_SHIFT_STAT, ""]
    rows = []
    desc = {1: "soft or high ball above the net with time: fast, low, to the corner or angled; drop volley dies",
            2: "firm ball at a comfortable height: solid and deep, returnable",
            3: "hard ball with little time, or dipping below the net: slower, mid-court, hangs",
            4: "hard and low at the feet, or stretched: pop-up or short sitter, sometimes net or long"}
    for b in (1, 2, 3, 4):
        bd = M.VOLLEY_BANDS[b]
        rows.append([b, desc[b], "%.0f (+%.0f VolleyPower)" % (bd["mph"], M.VOLLEY_POWER_MPH) if b <= 2 else "%.0f" % bd["mph"],
                     f2(bd["eff"]), "%.0f" % bd["deep"], f1(bd["apex"]), f2(bd["err"]), f2(bd["putaway"])])
    out.append(md(["band", "ball and result", "pace mph (PF)", "Efficiency (aim box reach)", "DeepDeviation cm", "apex over the net m",
                   "error", "put-away (VolleyPower; x0.6 standard)"], rows))
    out += ["", "Overreach: a VolleyPower on a ball contacted below %g cm or faster than 100 km/h adds %.2f error. Below net height the pace is "
            "capped at %g mph (it must be lifted). Drop and slice volleys keep their classes' jobs." % (M.NET_HEIGHT_CM, M.OVERREACH_ERR, M.LOW_VOLLEY_CAP_MPH), ""]
    out += ["What each band hands the passer (the reply's grade at the opponent, rating 80, from the rally model's ball-to-situation map):", ""]
    rows = []
    rng = random.Random(12)
    for b in (1, 2, 3, 4):
        G = collections.Counter()
        bd = M.VOLLEY_BANDS[b]
        for _ in range(3000 if not a.quick else 600):
            fe = M.final_efficiency(bd["eff"], rng.random())
            width = M.clamp(M.WIDTH_SCALE * M.NET_WIDTH * fe * (1.0 if rng.random() < 0.5 else M.SAFE_LAT) + rng.gauss(0.0, 0.10), 0.0, 1.0)
            depth = M.clamp(0.75 - bd["deep"] / 600.0 + rng.gauss(0.0, 0.08), 0.0, 1.0)
            ball = M.Ball(bd["mph"], depth, width, 0.05, False, "Average", b >= 4, True)
            ball.floating = bd["apex"] >= 1.0
            sit = M.situation_from_ball(rng, ball)
            vr = sit.v_req * M.TOP_SPEED_REF / (M.RALLY["max_run_base"] + M.RALLY["max_run_speed"] * 0.82)
            g, _, _ = M.grade_of(sit.frames, vr, sit.run_cm, sit.height, sit.pace, sit.depth_x, sit.set_f, sit.stretch or vr > 5.2, sit.kick)
            G[g] += 1
        tot = sum(G.values())
        rows.append([b] + [f2(G[g] / tot) for g in M.GRADES])
    out.append(md(["band"] + ["passer " + g for g in M.GRADES], rows))
    n = 10 if a.quick else 60
    out += ["", "### 8c. Rushing the net: every point against a set passer, and behind a good approach *(computed, elite mirror, %d matches each)*" % n, ""]
    rows = []
    A = M.ARCH["elite all-rounder"]
    for lab, st in (("rushes every point (serve-volley and every short ball)", {"flat": 0.35, "serve_volley": 1.0, "net": 1.0}),
                    ("comes in only on short balls (default)", {"flat": 0.35})):
        rng = random.Random(4)
        log = []
        wins = 0
        for m in range(n):
            p = M.MatchPlayer("a", A, st)
            q = M.MatchPlayer("b", A, {"flat": 0.35})
            w, _ = M.play_match(rng, p, q, {"netlog": log}) if m % 2 == 0 else M.play_match(rng, q, p, {"netlog": log})
            wins += w is p
        c = collections.defaultdict(lambda: [0, 0])
        for l, won in log:
            c[l][0] += 1
            c[l][1] += won
        cells = [lab, f2(wins / n)]
        for key in ("serve-volley", "approach, good (VeryGood+ and deep)", "approach, other"):
            cells.append("%s (%d)" % (f3(c[key][1] / c[key][0]), c[key][0]) if c[key][0] else "-")
        rows.append(cells)
    out.append(md(["net player", "match win share vs a baseline mirror", "points won: serve-volley", "after a good approach (VeryGood+ and deep)",
                   "after another approach"], rows))
    out += ["", "Real approaches: about 65-70% won (section 1)."]
    return "\n".join(out)


# --------------------------------------------------------------------------- section 9: stats and abuse

def sec_stats(a):
    out = ["### 9a. Rating -> stat, retail and proposed, and the floor penalty *(proposal)*", ""]
    rows = []
    for r in (0, 10, 20, 25, 30, 40, 50, 60, 70, 80, 90, 100):
        rows.append([r, f2(M.retail_stat("forehand", r)), f2(M.retail_stat("power", r)), f2(M.new_stat(r)), f2(M.floor_penalty(r))])
    out.append(md(["rating", "retail forehand", "retail power", "proposed (every stat)", "floor penalty (0..1)"], rows))
    return "\n".join(out)


def matrix(res, names):
    rows = []
    for x in names:
        rows.append([x] + ["-" if x == y else f2(res[x][y]) for y in names] + [f3(sum(res[x].values()) / len(res[x]))])
    return rows


def sec_abuse(a):
    nm = 30 if a.quick else 160
    out = ["### 9b. Abuse check: head-to-head match win share, equal 600-point rating budgets *(computed, %d best-of-3 matches per pair)*" % nm, ""]
    rows = []
    for k, (r, st) in M.BUILDS.items():
        rows.append([k] + [r[x] for x in ("serve", "ret", "fh", "bh", "volley", "power", "speed", "stamina")])
    out.append(md(["build", "Serve", "Return", "FH", "BH", "Volley", "Power", "Speed", "Stamina"], rows))
    out.append("")
    t0 = time.time()
    res = M.round_robin(M.BUILDS, nm, 2024)
    names = list(M.BUILDS)
    short = [n.replace("min-max: ", "mm: ")[:14] for n in names]
    out.append(md(["row beats column"] + short + ["field share"], [[short[i]] + r[1:] for i, r in enumerate(matrix(res, names))]))
    six = [n for n in names if not n.startswith("min-max")]
    out += ["", "Among the six intended styles only (min-max builds removed): field share " +
            ", ".join("%s %.3f" % (n, sum(res[n][m] for m in six if m != n) / 5.0) for n in six) + ".",
            "Builds that beat every other build: %s." % (", ".join(n for n in names if all(res[n][m] > 0.5 for m in names if m != n)) or "none"),
            "Runtime %.0f s." % (time.time() - t0)]
    return "\n".join(out)


def sec_robust(a):
    nm = 20 if a.quick else 80
    six = {k: v for k, v in M.BUILDS.items() if not k.startswith("min-max")}
    out = ["### 9c. Robustness: field share of the six styles when one rule moves by +-20 %% *(computed, %d matches per pair)*" % nm, ""]
    knobs = [("pace error per mph", M.RALLY, "pace_err"), ("slice drop", M, "SLICE_DROP_CM"), ("Speed stat run value", M.RALLY, "max_run_speed"),
             ("power-swing vigor cost", None, "vigor"), ("pass error vs net player", M.RALLY, "pass_err"), ("topspin kick per hand", M.RALLY, "kick_hand"),
             ("floor error", M.RALLY, "floor_err")]
    rows = []
    for label, obj, key in knobs:
        for f in (0.8, 1.2):
            if obj is None:
                saved = dict(M.RALLY["vigor_cost"])
                for h in ("Powerful", "Rushed", "Overcharge"):
                    M.RALLY["vigor_cost"][h] = saved[h] * f
            elif obj is M:
                saved = getattr(M, key)
                setattr(M, key, saved * f)
            else:
                saved = obj[key]
                obj[key] = saved * f
            try:
                res = M.round_robin(six, nm, 99)
            finally:
                if obj is None:
                    M.RALLY["vigor_cost"].update(saved)
                elif obj is M:
                    setattr(M, key, saved)
                else:
                    obj[key] = saved
            sh = {n: sum(res[n].values()) / 5.0 for n in six}
            top = max(sh, key=sh.get)
            bot = min(sh, key=sh.get)
            beats = [n for n in six if all(res[n][m] > 0.5 for m in six if m != n)]
            rows.append([label, "x%.1f" % f, "%s %.2f" % (top, sh[top]), "%s %.2f" % (bot, sh[bot]), ", ".join(beats) or "none"])
    out.append(md(["rule", "change", "best style (field share)", "worst style", "beats every other"], rows))
    return "\n".join(out)


NET_CASES = [  # label, tail class, start x cm, drift cm over the retail tail, reply frames, ball-back frames
    ("approach from 6 m behind the net, passer at the baseline", "approach", -600, 76, 47, 34),
    ("approach with a FollowNet clip (RB), same exchange", "approach_follownet", -600, 149, 47, 34),
    ("second volley: first volley from 4 m, passer replies", "volley", -400, 83, 42, 29),
    ("second volley in a fast exchange", "volley", -350, 83, 32, 24),
    ("serve-and-volley: 120 mph serve, run to the first volley", "serve", -1189, 64, 31, 40),
]


def sec_movement(a):
    out = ["### 10a. Kept as retail and agreed rule changes *(engine facts sourced from the movement docs)*", ""]
    out.append(md(["item", "retail (engine docs)", "decision"], [
        ["first step from rest", "5 cm after 2-21 frames by clip; Rush_Front 14-18 frames to 5 cm, 42-43 to 1 m", "kept as retail"],
        ["net rush", "refused when the opponent's hit is < 20 frames away (condition 7); needs RB / box and sprint", "agreed: buffered (starts as soon as allowed), no sprint requirement (code, fn_8869B928)"],
        ["pre-hit freeze", "direction latched for the last 20 frames before the opponent's hit; release at -20..-11 stops dead", "agreed: lifted at the net only, x > -500 cm (code, fn_8866F740); kept elsewhere"],
        ["volley and approach-shot tails", "38 (volley), 36 (approach groundstroke), 29 (FollowNet) frames to the Out window", "agreed: about half, %d / %d / %d" % (M.TAIL_AGREED["volley"], M.TAIL_AGREED["approach"], M.TAIL_AGREED["approach_follownet"])],
        ["groundstroke / return / serve tail", "Out window 36 / 26 / 34 frames after contact (median)", "kept"],
        ["put-away", "FH shoulder-height Fatality clips only; blocked by RB in the |z| < 300 cm corridor", "existing low and backhand clips made selectable (selection rule, no clip edits); corridor block removed (code)"],
        ["stops, reversals, sprint, sideways-push cancel, 12-frame commit", "stops 35-91 frames to still; reversals 39-96 frames back past the turn", "kept as retail"],
    ]))
    out += ["", "### 10b. What the agreed changes do against the passer's reply *(computed, judgement inputs)*", "",
            "x = distance from the net (cm) when the opponent hits and when his ball reaches the player; free = frames of steering before "
            "the ball arrives (the freeze latches the last 20 before the hit; with the agreed change it is lifted when the player is inside 500 cm "
            "of the net as it would start). Rush from rest as retail; root drift in the tail scales with its length. Reply and ball-back frames "
            "are judgement (ball speeds from sections 2-3).", ""]
    rows = []
    for label, cls, x0, drift, reply, back in NET_CASES:
        tail_r = M.TAIL_RETAIL[cls][0]
        cells = [label, "%d / %d" % (reply, back)]
        for tail, freeze, buf in ((tail_r, True, False), (tail_r, False, True), (M.TAIL_AGREED.get(cls, tail_r), False, True)):
            d = M.net_timeline(tail, reply, back, x0, drift * tail / tail_r, M.RUSH_RETAIL, freeze, buf)
            cells.append("tail %d: %.0f / %.0f cm, free %d" % (tail, d["x_at_reply"], d["x_at_ball"], d["free"]))
        rows.append(cells)
    out.append(md(["exchange", "reply / ball-back frames", "retail", "buffered rush + freeze lifted at the net", "all agreed changes (with the shorter tails)"], rows))
    out += ["", "Serve tails are kept, so serve-and-volley changes only through the buffered rush; the shorter tails help the second volley "
            "and the approach."]
    return "\n".join(out)


SECTIONS = {"speed": sec_speed, "serve": sec_serve, "flight": sec_flight, "grade": sec_grade, "teeoff": sec_teeoff, "window": sec_window,
            "oppterm": sec_oppterm, "power": sec_power, "placement": sec_placement, "net": sec_net, "stats": sec_stats,
            "abuse": sec_abuse, "robust": sec_robust, "movement": sec_movement}


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("sections", nargs="*", default=["all"])
    ap.add_argument("--quick", action="store_true", help="small samples (for a fast check)")
    a = ap.parse_args(argv)
    names = list(SECTIONS) if "all" in a.sections else a.sections
    for n in names:
        if n not in SECTIONS:
            ap.error("unknown section %s" % n)
        print("<!-- section %s -->" % n)
        print(SECTIONS[n](a))
        print()
    return 0


if __name__ == "__main__":
    sys.exit(main())
