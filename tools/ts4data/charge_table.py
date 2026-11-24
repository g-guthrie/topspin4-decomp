#!/usr/bin/env python3
"""Charge-to-launch table for Top Spin 4 (Xbox 360): hold frames -> power -> tier -> PowerfulFactor -> ball.

Agent G8 (docs/gameplay/timing-and-fatigue.md "G8: the charge", controls-and-shot-selection.md s18).
Uses the reference evaluators of tools/design/retune_baseline.py (analyser graphs of Expressions.bin,
ball templates of Settings.bin, player defaults of State.bin); it reads the game files from work/disc
(git-ignored) and writes only derived numbers.

Model (grade C unless marked):
  * the charge counter S+0xDFC counts +1 per frame from the press while the request state is waiting /
    committed-early / clip-running, until the commit (release or the 12-frame auto-commit, PT+0x740);
    a re-press while committed (fn_88698538) resets it;
  * power S+0xE00 = curve cfg+0x8FC (frames / 60), keys [0..1.25 -> 0..1] (InstantRocket: cfg+0x914, the
    same keys), so power = min(frames / 60, 1.25) / 1.25 and is full at 75 frames;
  * tier: Finesse power < 0.15, Medium < 0.7, Powerful >= 0.7 (tier graphs, shot_tree.yaml), i.e.
    frames 0-11 / 12-52 / 53+;
  * flat forehand rows: Finesse 2 (class FlatFinesse), Medium 6 (FlatMedium), Powerful 10 (FlatPower).

Usage:
  charge_table.py [--work-root .] [--out data/gameplay/charge_table.yaml]
  charge_table.py --selftest
"""
from __future__ import annotations

import argparse
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, os.path.join(ROOT, "tools", "design"))

FPS = 60.0
FULL_X = 1.25           # curve cfg+0x8FC x range (frames / 60)
TIER_EDGES = (0.15, 0.7)
FLAT_ROWS = {"Finesse": (2, "FlatFinesse"), "Medium": (6, "FlatMedium"), "Powerful": (10, "FlatPower")}
FRAMES = sorted(set(list(range(0, 121, 4)) + [11, 12, 52, 53, 74, 75, 90, 120]))
LEVELS = ("min", "median", "max")


def power_of_frames(frames: int) -> float:
    return min(frames / FPS, FULL_X) / FULL_X


def tier_of_power(p: float) -> str:
    if p < TIER_EDGES[0]:
        return "Finesse"
    if p < TIER_EDGES[1]:
        return "Medium"
    return "Powerful"


def first_frame_of_tier(tier: str) -> int:
    f = 0
    while tier_of_power(power_of_frames(f)) != tier:
        f += 1
    return f


def r(x, n=3):
    return None if x is None else round(float(x), n)


def hold_table(R, c):
    out = {}
    for lv in LEVELS:
        rows = []
        for f in FRAMES:
            p = power_of_frames(f)
            tier = tier_of_power(p)
            row, cls = FLAT_ROWS[tier]
            res = {"frames": f, "power": r(p), "tier": tier, "row": row}
            for t in (0.0, 0.5):
                b = c.base(row, lv, charge=p, timing=t)
                pf, bl = c.pf(cls, b)
                d = c.tpl.fly(row, *R.SCEN["ground_cc"], pf=pf, blend=bl)
                e, _ = c.p_error(cls, b)
                ae, dev, _ = c.aim_mean(cls, b, 10)
                k = "t0" if t == 0.0 else "late05"
                res["pf_" + k] = r(pf)
                res["kmh_" + k] = r(d["launch_kmh"], 1)
                res["p_error_" + k] = r(e)
                res["aim_eff_" + k] = r(ae, 2)
            rows.append(res)
        out[lv] = rows
    return out


CAT_ROWS = [("FlatMedium", 6, 0.5, "ground_cc", "forehand"), ("FlatPower", 10, 0.85, "ground_cc", "forehand"),
            ("TopSpinPower", 8, 0.85, "ground_cc", "forehand"), ("SlicePower", 9, 0.85, "ground_cc", "forehand"),
            ("Lob", 11, 0.85, "lob", "forehand"), ("VolleyStandard", 19, 0.5, "volley", "volley"),
            ("VolleyPower", 16, 0.5, "volley", "volley")]
CAT_MODS = [("Fatality", "link:SwingCategory/Fatality"), ("FlatGoodReach", "link:SwingCategory/#0698037d"),
            ("VolleyReflex", "link:SwingCategory/#f2885ba2"), ("SlowDown", "slowdown"),
            ("MoveToNet", "link:MoveToNet/#4daa7349")]


def category_effects(R, c):
    out = {}
    for t in (0.0, 0.45):
        key = "timing_%+.2f" % t
        out[key] = {}
        for cls, row, ch, sc, hand in CAT_ROWS:
            base = c.base(row, "median", hand=hand, charge=ch, timing=t, scen=sc)

            def m(b):
                pf, bl = c.pf(cls, b)
                d = c.tpl.fly(row, *R.SCEN[sc], pf=pf, blend=bl)
                e, _ = c.p_error(cls, b)
                ae, dv, _ = c.aim_mean(cls, b, 10)
                return [r(pf), r(d["launch_kmh"], 1), r(e), r(ae, 2), r(dv, 0)]
            ent = {"none": m(base)}
            for name, k in CAT_MODS:
                b = dict(base)
                b[k] = 1.0
                ent[name] = m(b)
            out[key]["%s row %d charge %.2f %s" % (cls, row, ch, sc)] = ent
    return out


def graph17(R, c):
    env = c.env
    out = {}
    for lv in LEVELS:
        st = c.stats(lv)
        for x in (-1200, -600, -300):
            for fat in (0, 1):
                s = {("player", 0x8E0): float(x), ("player", 0x8E8): 0.0, "link:SwingCategory/Fatality": fat,
                     "volley": st["volley"], "speed": st["speed"], "vigor": 1.0}
                v = env.evaluate(17, s).get(("player", 0x378))
                out["%s local_x %d fatality %d" % (lv, x, fat)] = r(v)
    return out


def fatigue(R, c):
    env = c.env
    cost = {}
    for spf in (0.0, 0.8, 1.0, 2.0):
        for stam in (0.0, 1.0):
            cost["sum_pf %.1f stamina %.1f" % (spf, stam)] = r(
                env.evaluate(10, {("player", 0xF24): spf, "stamina": stam}).get(("player", 0xF44)), 2)
    cap = {}
    for stam in (0.0, 0.5, 1.0):
        for rec in (0.0, 0.5, 1.0):
            res = env.evaluate(12, {"stamina": stam, ("player", 0xF58): rec})
            cap["stamina %.1f recovery %.1f" % (stam, rec)] = [r(res.get(("player", 0xF60)), 2),
                                                              r(res.get(("player", 0xF64)), 2)]
    return {"fatigue_ingame_graph10_out_S_0xF44": cost, "graph12_80ce1a10_out_S_0xF60_0xF64": cap}


def yq(v):
    if v is None:
        return "null"
    if isinstance(v, bool):
        return "true" if v else "false"
    if isinstance(v, (int, float)):
        return repr(v)
    if isinstance(v, list):
        return "[" + ", ".join(yq(x) for x in v) + "]"
    if isinstance(v, dict):
        return "{" + ", ".join("%s: %s" % (yq(k), yq(x)) for k, x in v.items()) + "}"
    s = str(v)
    if all(ch.isalnum() or ch in "_." for ch in s) and not s[:1].isdigit():
        return s
    return '"' + s.replace('"', '\\"') + '"'


def selftest():
    assert power_of_frames(0) == 0.0 and power_of_frames(75) == 1.0 and power_of_frames(120) == 1.0
    assert abs(power_of_frames(30) - 0.4) < 1e-12
    assert first_frame_of_tier("Medium") == 12 and first_frame_of_tier("Powerful") == 53
    assert tier_of_power(0.1499) == "Finesse" and tier_of_power(0.7) == "Powerful"
    assert yq("a b") == '"a b"' and yq([1, None]) == "[1, null]"
    print("charge_table selftest ok")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--work-root", default=ROOT)
    ap.add_argument("--out", default=None)
    ap.add_argument("--selftest", action="store_true")
    a = ap.parse_args(argv)
    if a.selftest:
        selftest()
        return 0
    import retune_baseline as R  # noqa: E402
    inp = R.Inputs(a.work_root)
    c = R.Ctx(inp)
    lines = []
    w = lines.append
    w("# Top Spin 4 charge-to-launch table (agent G8).  Generated; do not edit by hand.")
    w("# Generator: python3 tools/ts4data/charge_table.py" + (" --out %s" % a.out if a.out else ""))
    w("# Python %d.%d.%d; evaluators: tools/design/retune_baseline.py (GraphEnv, Templates)" % sys.version_info[:3])
    w("# Docs: docs/gameplay/timing-and-fatigue.md \"G8: the charge\", controls-and-shot-selection.md s18.")
    w("sources:")
    for k, p in inp.paths.items():
        w("  %s: {path: %s, size: %d, sha256: %s}" % (k, os.path.relpath(p, ROOT), len(inp.data[k]), R.sha256(p)))
    w("model:")
    w("  power: \"min(frames / 60, 1.25) / 1.25 (curve cfg+0x8FC; InstantRocket curve cfg+0x914 is identical)\"")
    w("  tier_edges_power: [0.15, 0.7]")
    w("  tier_first_frame: {Finesse: 0, Medium: %d, Powerful: %d, full: 75}" % (
        first_frame_of_tier("Medium"), first_frame_of_tier("Powerful")))
    w("  counting: \"S+0xDFC +1 per frame from the press until the commit (release, or 12 frames before contact "
      "PT+0x740); re-press while committed resets it (fn_88698538)\"")
    w("  scenario: \"ground_cc baseline cross-court, forehand, human, vigor 1, ratings min (30) / median pro / "
      "max (100); t0 = perfect timing, late05 = ManualShotTiming +0.5\"")
    w("  flat_forehand_rows: {Finesse: [2, FlatFinesse], Medium: [6, FlatMedium], Powerful: [10, FlatPower]}")
    w("hold_frames_flat_forehand:")
    for lv, rows in hold_table(R, c).items():
        w("  %s:" % lv)
        for row in rows:
            w("    - " + yq(row))
    w("# Category links (the playing swing clip's SwingCategory / MoveToNet tag) set to 1, median ratings:")
    w("# [PowerfulFactor, launch km/h, P(error), aim efficiency, deep deviation cm].")
    w("category_effects:")
    for t, rows in category_effects(R, c).items():
        w("  %s:" % yq(t))
        for k, ent in rows.items():
            w("    %s: %s" % (yq(k), yq(ent)))
    w("# Graph 17 SwingSpeedCoef (S+0x378) with the Fatality link 0/1.  No swing group sets allow_speed_coef")
    w("# (animation_rules.yaml anim_groups), so the Fatality term does not change a Fatality clip's play rate (I).")
    w("graph17_swing_speed_coef:")
    for k, v in graph17(R, c).items():
        w("  %s: %s" % (yq(k), yq(v)))
    w("# Fatigue: FatigueIngame (graph 10) cost per accumulated PowerfulFactor of powerful shots (S+0xF24),")
    w("# and graph 12 (80ce1a10) outputs by stamina and CurrentRecovery.")
    w("fatigue:")
    for k, ent in fatigue(R, c).items():
        w("  %s:" % k)
        for kk, v in ent.items():
            w("    %s: %s" % (yq(kk), yq(v)))
    text = "\n".join(lines) + "\n"
    if a.out:
        with open(a.out, "w", encoding="utf-8") as f:
            f.write(text)
        print("wrote", a.out)
    else:
        sys.stdout.write(text)
    return 0


if __name__ == "__main__":
    sys.exit(main())
