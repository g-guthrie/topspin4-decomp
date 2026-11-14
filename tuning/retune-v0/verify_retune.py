#!/usr/bin/env python3
"""Check a tools/apply_retune.py output against the retail data (standard library only).

  python3 tuning/retune-v0/verify_retune.py work/retune-v0-full [--baseline]

1. Re-dump: every gameplay scalar of the retail and the patched Settings.bin / Expressions.bin (disc and, when
   present, TU1 copies) is walked with tools/ts4_xbin.py, as tools/ts4data/dump_tunables.py does, and the two
   dumps are diffed.  The diff must equal the intended edits exactly: the Settings rows of the chosen groups and
   the words tools/ts4_analyser_patch.py plans for their graph edits (no more, no fewer).
2. Model numbers before/after, with the repository's own models (tools/design/retune_baseline.py classes:
   analyser graphs, ball model): rating curves, timing windows, groundstroke and serve speeds, bounce,
   aim efficiency and depth pull against timing, volley quality.  Printed as Markdown tables.
3. --baseline also runs tools/design/retune_baseline.py itself (sections speeds shape stats serve net) on the
   retail and the patched files (through a --work root of symlinks under OUT/baseline/) and writes both reports
   and their diff there.

Retail inputs: work/disc/core_big/334e7e0d.bin, work/disc/core_all/fa94f637.bin, work/disc/Layoutall.bin and the
TU1 files under work/disc/tu1_arc/ and orig/54540859/tu1/files/ (as make_patches.py).
"""
from __future__ import annotations

import argparse
import difflib
import json
import math
import os
import struct
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, "tools"))
sys.path.insert(0, os.path.join(ROOT, "tools", "ts4data"))
sys.path.insert(0, os.path.join(ROOT, "tools", "design"))

import ts4_xbin as X  # noqa: E402
import ts4_analyser_patch as AP  # noqa: E402
import patch_tunables as PT  # noqa: E402
from dump_tunables import EDITABLE  # noqa: E402
import make_patches as MP  # noqa: E402

STATE = "work/disc/core_big/623d0979.bin"


def rd(p):
    with open(p if os.path.isabs(p) else os.path.join(ROOT, p), "rb") as f:
        return f.read()


def md(head, rows):
    out = ["| " + " | ".join(head) + " |", "|" + "---|" * len(head)]
    out += ["| " + " | ".join(str(c) for c in r) + " |" for r in rows]
    return "\n".join(out)


# --------------------------------------------------------------------------- 1. re-dump diff

def scalars(data, layout):
    out = {}
    for lf in X.Walker(data, layout).walk_file():
        if lf.tag in EDITABLE:
            out[lf.offset] = (lf.path, struct.unpack(">" + lf.code.lstrip("<>"), data[lf.offset:lf.offset + struct.calcsize(lf.code)])[0]
                              if False else data[lf.offset:lf.offset + struct.calcsize(lf.code)], lf.tag)
    return out


def dump_diff(orig, new, layout):
    a, b = scalars(orig, layout), scalars(new, layout)
    if sorted(a) != sorted(b):
        raise SystemExit("structure differs between the retail and the patched file")
    return {off: (a[off][0], a[off][1], b[off][1], a[off][2]) for off in a if a[off][1] != b[off][1]}


def intended(manifest, groups, variant, orig_s, orig_e, layout):
    """Offsets the chosen groups mean to change, with the new bytes: Settings and Expressions."""
    want_s, want_e = {}, {}
    by = {g["name"]: g for g in manifest["groups"]}
    for name in groups:
        g = by[name]
        for rel in g["settings"].get(variant, []):
            _h, rows = PT.parse_yaml(open(os.path.join(HERE, rel)).read())
            for _no, off, typ, text, _path in rows:
                newb = PT.encode(typ, text, 0)
                if orig_s[off:off + len(newb)] != newb:
                    want_s[off] = newb
        rel = g.get("expressions", {}).get(variant)
        if rel:
            _graphs, edits = AP.plan(orig_e, json.load(open(os.path.join(HERE, rel))))
            for off, val, _d in edits:
                newb = struct.pack(">f", val)
                if orig_e[off:off + 4] != newb:
                    want_e[off] = newb
    return want_s, want_e


def check_redump(out, manifest, groups):
    res = []
    for variant in ("disc", "tu1"):
        mdir = os.path.join(out, "members", variant)
        if not os.path.isdir(mdir):
            continue
        f = MP.FILES[variant]
        layout = X.Layout(rd(f["layout"]))
        orig_s, orig_e = rd(f["settings"]), rd(f["expressions"])
        new_s = rd(os.path.join(mdir, "Settings.bin")) if os.path.exists(os.path.join(mdir, "Settings.bin")) else orig_s
        new_e = rd(os.path.join(mdir, "Expressions.bin")) if os.path.exists(os.path.join(mdir, "Expressions.bin")) else orig_e
        want_s, want_e = intended(manifest, groups, variant, orig_s, orig_e, layout)
        for label, o, n, want in (("Settings.bin", orig_s, new_s, want_s), ("Expressions.bin", orig_e, new_e, want_e)):
            d = dump_diff(o, n, layout)
            got = {off: v[2] for off, v in d.items()}
            extra = sorted(set(got) - set(want))
            missing = sorted(set(want) - set(got))
            wrong = sorted(off for off in set(got) & set(want) if got[off] != want[off])
            raw = sum(1 for i in range(len(o)) if o[i] != n[i])
            ok = not (extra or missing or wrong) and len(o) == len(n)
            res.append((variant, label, len(want), len(got), len(extra), len(missing), len(wrong), raw, "PASS" if ok else "FAIL"))
            if not ok:
                print("%s %s: extra %s missing %s wrong %s" % (variant, label, [hex(x) for x in extra[:5]],
                                                            [hex(x) for x in missing[:5]], [hex(x) for x in wrong[:5]]))
    return res


# --------------------------------------------------------------------------- 2. model numbers

def ctx(settings=None, expressions=None):
    import retune_baseline as RB
    inp = object.__new__(RB.Inputs)
    inp.tu = False
    inp.paths = {k: os.path.join(RB.ROOT, v) for k, v in RB.DISC.items()}
    if settings:
        inp.paths["settings"] = settings
    if expressions:
        inp.paths["expressions"] = expressions
    inp.data = {k: rd(p) for k, p in inp.paths.items()}
    inp.disc_data = inp.data
    return RB.Ctx(inp)


def timing_lists(settings, layout):
    """{list path: [(InStart, InStop, OutStart, OutStop)]} for the Baseline and Volley worst/best curves."""
    lv = {}
    for lf in X.Walker(settings, layout, X.load_names(*[p for p in MP.NAMES if os.path.exists(p)])).walk_file():
        lv[PT._strip_names(lf.path)] = lf.value
    out = {}
    for lst in MP.TIMING_LISTS:
        rows = []
        for k in range(6):
            g = lambda f: lv[PT._strip_names(MP.SEC_PLAYER + "%s/Range[%d]/%s" % (lst, k, f))]
            rows.append((g("InStart"), g("InStop"), g("OutStart"), g("OutStop")))
        out[lst] = rows
    return out


def t_of(curve, f):
    """Frames before arrival -> t, piecewise linear, clamped (the Range list semantics)."""
    if f <= curve[0][0]:
        return curve[0][2]
    for a, b, ya, yb in curve:
        if a <= f <= b:
            return ya + (yb - ya) * (f - a) / (b - a) if b > a else yb
    return curve[-1][3]


def half_width(worst, best, ability, lim):
    """Frames on the late and early side of 20 inside |t| < lim, with t = lerp(worst, best, ability)."""
    def t(f):
        return t_of(worst, f) + (t_of(best, f) - t_of(worst, f)) * ability
    late = early = 0.0
    f = 20.0
    while f > 0 and abs(t(f)) < lim:
        f -= 0.01
    late = 20.0 - f
    f = 20.0
    while f < 60 and abs(t(f)) < lim:
        f += 0.01
    early = f - 20.0
    return late, early


def sec_ratings(c0, c1):
    import retune_baseline as RB
    rows = []
    for st in ("forehand", "power", "serve", "return"):
        a = ["%d:%.2f" % (r, RB.rating_to_stat(c0.env, st, r)) for r in (0, 20, 30, 40, 50, 60, 70, 80, 90, 100)]
        b = ["%d:%.2f" % (r, RB.rating_to_stat(c1.env, st, r)) for r in (0, 20, 30, 40, 50, 60, 70, 80, 90, 100)]
        rows.append((st, " ".join(a), " ".join(b)))
    return md(["stat", "retail rating:stat", "retune-v0 rating:stat"], rows)


def sec_timing(c0, c1, s0, s1, layout):
    import retune_baseline as RB
    out = []
    rows = []
    tl0, tl1 = timing_lists(s0, layout), timing_lists(s1, layout)
    for kind in ("Baseline", "Volley"):
        w = "/SwingTimingSelectionList/%s/5ae85f27/848c2a13" % kind
        b = "/SwingTimingSelectionList/%s/5ae85f27/BestAbility" % kind
        for rating in (30, 40, 55, 70, 85, 100):
            gi = 41 if kind == "Baseline" else 42
            stat_key = "forehand" if kind == "Baseline" else "volley"
            cells = ["%s, rating %d" % ("groundstroke" if kind == "Baseline" else "volley", rating)]
            for c, tl in ((c0, tl0), (c1, tl1)):
                stat = RB.rating_to_stat(c.env, stat_key, rating)
                scen = {"hand": stat} if gi == 41 else {"volley": stat}
                ab = c.env.out(gi, scen, ("player", 0xD0C))
                p = half_width(tl[w], tl[b], ab, 0.1)
                g = half_width(tl[w], tl[b], ab, 0.3)
                z = half_width(tl[w], tl[b], ab, 0.45)
                cells.append("%.2f | %.1f / %.1f | %.1f / %.1f | %.1f / %.1f" % (ab, p[0], p[1], g[0], g[1], z[0], z[1]))
            rows.append(cells)
    out.append(md(["stroke, rating", "retail: ability | Perfect late/early | Good late/early | |t|<0.45 late/early",
                   "retune-v0: same"], rows))
    late12 = []
    for c, tl in ((c0, tl0), (c1, tl1)):
        w = tl["/SwingTimingSelectionList/Baseline/5ae85f27/848c2a13"]
        b = tl["/SwingTimingSelectionList/Baseline/5ae85f27/BestAbility"]
        late12.append(" / ".join("%.2f" % (t_of(w, 12) + (t_of(b, 12) - t_of(w, 12)) * a) for a in (0.0, 0.5, 1.0)))
    out.append("")
    out.append("t at the 12-frame automatic commit (ability 0 / 0.5 / 1): retail %s; retune-v0 %s." % tuple(late12))
    return "\n".join(out)


GROUND = [("Flat Medium", 6, "FlatMedium", 0.5), ("Flat Powerful", 10, "FlatPower", 0.85),
          ("TopSpin Medium", 4, "TopSpinMedium", 0.5), ("TopSpin Powerful", 8, "TopSpinPower", 0.85),
          ("Slice Medium", 5, "SliceMedium", 0.5), ("Slice Powerful", 9, "SlicePower", 0.85)]


def sec_flight(c0, c1):
    import retune_baseline as RB
    rows = []
    for label, row, cls, ch in GROUND:
        cells = [label]
        for c in (c0, c1):
            b = c.base(row, "median", charge=ch)
            pf, bl = c.pf(cls, b)
            d = c.tpl.fly(row, *RB.SCEN["ground_cc"], pf=pf, blend=bl)
            ratio = d["bounce_out_kmh"] / d["bounce_in_kmh"]
            cells.append("%.0f (%.0f) | %.2f | %.2f | %.0f -> %.0f (%.2f) | %.2f | %s" % (
                d["launch_kmh"], d["launch_kmh"] * 0.621371, d["net_clear_m"], d["apex_m"], d["bounce_in_kmh"],
                d["bounce_out_kmh"], ratio, d["bounce_apex_m"],
                "-" if d["baseline_kmh"] is None else "%.0f" % d["baseline_kmh"]))
        rows.append(cells)
    return md(["shot (median stats, perfect timing, cross-court)",
               "retail: launch km/h (mph) | net clear m | apex m | bounce in -> out km/h (out/in) | bounce height m | at baseline km/h",
               "retune-v0: same"], rows)


def sec_speed_levels(c0, c1):
    import retune_baseline as RB
    rows = []
    for label, row, cls, ch in GROUND:
        cells = [label]
        for c in (c0, c1):
            v = []
            for lvl in RB.LEVELS:
                b = c.base(row, lvl, charge=ch)
                pf, bl = c.pf(cls, b)
                v.append("%.0f" % (c.tpl.fly(row, *RB.SCEN["ground_cc"], pf=pf, blend=bl)["launch_kmh"] * 0.621371))
            cells.append(" / ".join(v))
        rows.append(cells)
    for label, row, cls in (("Serve Flat Powerful", 27, "ServeFlatPowerful"), ("Serve Flat Medium", 26, "ServeFlatMedium"),
                            ("Serve Advanced flat", 31, "AdvancedServe"), ("Serve Kick Powerful", 21, "ServeSpinPowerful")):
        cells = [label]
        for c in (c0, c1):
            v = []
            for lvl in RB.LEVELS:
                b, _ = RB.class_base(c, cls, lvl)
                pf, bl = c.pf(cls, b)
                v.append("%.0f" % (c.tpl.fly(row, *RB.SCEN["serve_T"], pf=pf, blend=bl)["launch_kmh"] * 0.621371))
            cells.append(" / ".join(v))
        rows.append(cells)
    return md(["shot", "retail launch mph (min / median / p90 / max ratings)", "retune-v0"], rows)


def sec_aim(c0, c1):
    rows = []
    for label, row, cls, ch in (("Flat Medium", 6, "FlatMedium", 0.5), ("TopSpin Medium", 4, "TopSpinMedium", 0.5),
                                ("Flat Powerful", 10, "FlatPower", 0.85)):
        for lvl in ("min", "median", "max"):
            cells = ["%s, %s ratings" % (label, lvl)]
            for c in (c0, c1):
                v = []
                for t in (0.0, 0.1, -0.1, 0.3, -0.3, 0.45, -0.6):
                    b = c.base(row, lvl, charge=ch, timing=t)
                    e, dev, _ = c.aim_mean(cls, b, n=20)
                    v.append("%.2f/%.0f" % (e, dev))
                cells.append(" ".join(v))
            rows.append(cells)
    return md(["shot", "retail efficiency/depth pull cm at t = 0, +.1, -.1, +.3, -.3, +.45, -.6", "retune-v0"], rows)


def sec_volley(c0, c1):
    import retune_baseline as RB
    cases = [("high, time (140 cm, 70 f)", 140, 70, 100), ("comfortable (110 cm, 50 f)", 110, 50, 150),
             ("firm (100 cm, 40 f)", 100, 40, 200), ("dipping, little time (75 cm, 32 f)", 75, 32, 250),
             ("at the feet, rushed (40 cm, 22 f)", 40, 22, 300)]
    rows = []
    for cls, row in (("VolleyStandard", 19), ("VolleyPower", 16)):
        for name, h, f, dd in cases:
            cells = ["%s, %s" % (cls, name)]
            for c in (c0, c1):
                b = c.base(row, "median", hand="volley", charge=0.5, scen="volley")
                b.update(hit_y=float(h), frames_to_contact=float(f), depth_diff=float(dd))
                pf, bl = c.pf(cls, b)
                frm, to = RB.SCEN["volley"]
                d = c.tpl.fly(row, (frm[0], h, frm[2]), to, pf=pf, blend=bl)
                e, dev, _ = c.aim_mean(cls, b, n=20)
                cells.append("%.0f mph | apex %.2f m | eff %.2f | pull %.0f cm" % (d["launch_kmh"] * 0.621371, d["apex_m"], e, dev))
            rows.append(cells)
    return md(["volley (median Volley rating, perfect timing)", "retail", "retune-v0"], rows)


def model_report(out, has_tu):
    s1 = os.path.join(out, "members", "disc", "Settings.bin")
    e1 = os.path.join(out, "members", "disc", "Expressions.bin")
    c0 = ctx()
    c1 = ctx(s1 if os.path.exists(s1) else None, e1 if os.path.exists(e1) else None)
    layout = X.Layout(rd(MP.FILES["disc"]["layout"]))
    s0b = rd(MP.FILES["disc"]["settings"])
    s1b = rd(s1) if os.path.exists(s1) else s0b
    parts = [("Rating -> stat (graph 23)", sec_ratings(c0, c1)),
             ("Timing windows in frames (ability from graphs 41/42; Perfect |t| < 0.1, Good |t| < 0.3)", sec_timing(c0, c1, s0b, s1b, layout)),
             ("Groundstroke flight and bounce", sec_flight(c0, c1)),
             ("Launch speed by rating level", sec_speed_levels(c0, c1)),
             ("Aim efficiency and depth pull against timing (Long aim off, hand = forehand stat)", sec_aim(c0, c1)),
             ("Volleys", sec_volley(c0, c1))]
    return "\n\n".join("### %s\n\n%s" % p for p in parts)


# --------------------------------------------------------------------------- 3. the baseline script itself

def run_baseline(out):
    import retune_baseline as RB
    bdir = os.path.join(out, "baseline")
    os.makedirs(bdir, exist_ok=True)
    reports = {}
    for tag, settings, expressions in (("retail", None, None),
                                       ("patched", os.path.join(out, "members", "disc", "Settings.bin"),
                                        os.path.join(out, "members", "disc", "Expressions.bin"))):
        root = os.path.join(bdir, tag + "_root")
        for k, rel in RB.DISC.items():
            p = os.path.join(root, rel)
            os.makedirs(os.path.dirname(p), exist_ok=True)
            src = os.path.join(ROOT, rel)
            if k == "settings" and settings and os.path.exists(settings):
                src = settings
            if k == "expressions" and expressions and os.path.exists(expressions):
                src = expressions
            if os.path.lexists(p):
                os.remove(p)
            os.symlink(os.path.realpath(src), p)
        cmd = ["nice", sys.executable, os.path.join(ROOT, "tools", "design", "retune_baseline.py"), "--work", root,
               "speeds", "shape", "stats", "serve", "net"]
        r = subprocess.run(cmd, capture_output=True, text=True, check=True)
        reports[tag] = r.stdout
        with open(os.path.join(bdir, tag + ".md"), "w") as f:
            f.write(r.stdout)
    diff = difflib.unified_diff(reports["retail"].splitlines(), reports["patched"].splitlines(), "retail", "patched",
                                lineterm="", n=0)
    with open(os.path.join(bdir, "diff.txt"), "w") as f:
        f.write("\n".join(diff) + "\n")
    return bdir


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("out", help="an output directory of tools/apply_retune.py")
    ap.add_argument("--baseline", action="store_true")
    ap.add_argument("--no-model", action="store_true")
    a = ap.parse_args(argv)
    res = json.load(open(os.path.join(a.out, "manifest.json")))
    manifest = json.load(open(os.path.join(HERE, "manifest.json")))
    rows = check_redump(a.out, manifest, res["groups"])
    print("### Re-dump against retail (groups: %s)\n" % ", ".join(res["groups"]))
    print(md(["copy", "file", "intended changes", "changed values in the re-dump", "extra", "missing", "wrong value",
              "bytes changed", "result"], rows))
    for v in ("disc", "tu1"):
        if v in res and "archive" in res[v]:
            ar = res[v]["archive"]
            print("\n%s: %s, %d bytes, sha256 %s, %d members, replaced %s, full writer verify: %s" % (
                v, "Core.arc" if v == "disc" else "TitleUpdate.arc", ar["size"], ar["sha256"], ar["members"],
                ",".join(ar["replaced"]), ar["full_verify"]))
    if not a.no_model:
        print()
        print(model_report(a.out, "tu1" in res))
    if a.baseline:
        print("\nbaseline reports in %s" % run_baseline(a.out))
    return 1 if any(r[-1] != "PASS" for r in rows) else 0


if __name__ == "__main__":
    sys.exit(main())
