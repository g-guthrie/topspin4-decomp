#!/usr/bin/env python3
"""Special and situational swing clips of Top Spin 4 (Xbox 360), standard library only.

Joins three committed dumps into one per-category summary (agent G8, docs/gameplay/
controls-and-shot-selection.md s18 and movement-and-animation.md "G8: special swings"):

* data/gameplay/animation_rules.yaml (tools/ts4data/anim_rules.py): every clip's qualifiers, its
  EventRacket contact phase and its transition events [dir, pace, position, duration, reactivity,
  start-blend, in, out];
* data/gameplay/root_motion.yaml (tools/ts4data/root_motion.py, agent G9), optional: root travel
  to contact and root speed at contact for the swing clips;
* with ``--settings Settings.bin``: the SwingSelectionCategory rule rows (tools/ts4data/shot_tree.py
  swing_category_rules) that name each category, so a category's clips and its triggers sit together.

Per SwingCategory and per Properties value (Men setup; the Women set mirrors it) it prints the clip
count, FH/BH, height tokens, Power/Control qualifiers, preference levels, IgnoreSpeedCoef count,
frames, contact frame, the shortest and longest entry -> contact span allowed by the "In" transition
windows, contact -> first "Out" window, and the root-motion medians.

Units: frames at 60 Hz (play rate 1), cm.  Entry -> contact: an In window spans phase
[position, position + duration]; entering at the window's end gives the shortest span, at its start
the longest.  Windows that open after contact are ignored.

Usage:
  special_swings.py [--rules data/gameplay/animation_rules.yaml] [--root-motion data/gameplay/root_motion.yaml]
                    [--settings work/disc/core/334e7e0d.bin] [--out data/gameplay/special_swings.yaml]
  special_swings.py --selftest
"""
from __future__ import annotations

import argparse
import hashlib
import os
import re
import statistics
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))

HEIGHTS = ("Low", "Knee", "Waist", "Shoulder", "High", "Head")
LIST_RE = re.compile(r'"?([A-Za-z0-9_. ]+?)"?: \[([^\]]*)\]')
NUM_LIST_RE = re.compile(r"\[([-0-9., e]+)\]")

# Trigger of each special SwingCategory (doc s17/s18).  Grade: C = read from code, D = data, I = inferred.
TRIGGERS = {
    "Fatality": {
        "grade": "C+D",
        "trigger": "row condition 0xC78C8F06: not following to the net (human: !(sticky RB && |world z| < "
                   "PT+0x6F0 = 300 cm, the central corridor); AI: !S+0x4E0) and raw charge S+0xE00 > 0.15 "
                   "(lbl_880D0934).  First row of FlatPower in all three modes; dead in FlatFinesse (that "
                   "class means power < 0.15).  AI at difficulty 3-5 (S+0x3F0, graph 139/140) tries it first "
                   "in its release fn_886AE0E8",
        "clip_gate": "a Fatality clip must fit the ball (fn_886DAA48 clip fit within the selection horizon "
                     "now+40 frames, tolerance box [40, 40, 80, -50, 50, -80], facing clamp [-90, 30/45/90]); all are FH, Shoulder "
                     "height, Baseline; contact 1.4-2.4 s after clip start, so the clip needs a long, early "
                     "fit (see entry_to_contact)",
        "ball": "link SwingCategory/Fatality in graphs 17, 205, 206, 238, 239, 243, 244, 248, 249, 292: "
                "fixes PowerfulFactor and removes the late-timing aim penalty (charge_table.yaml "
                "category_effects)"},
    "FlatPerfect": {
        "grade": "C+D",
        "trigger": "condition 0x07F0DF25: PerfectShotEvaluation S+0x7D4 > 0.5 (graph 168: -0.1 <= "
                   "ManualShotTiming < 0.1)",
        "clip_gate": "4 clips (2 Men)", "ball": "no graph link port found (I: visual only)"},
    "FlatGoodReach": {
        "grade": "C+D",
        "trigger": "conditions 0x693616C3 / 0xDE050FD0: min(LeftLine, RightLine MinSpeed) > PT+0x1B0 "
                   "(and timing window for humans)",
        "clip_gate": "SwingReach clips",
        "ball": "link #0698037d in 44 graphs: lowers PF and aim, adds error when late"},
    "FlatBadReach": {
        "grade": "C+D", "trigger": "conditions 0x60D5B606 / 0x42864090: MinSpeed > PT+0x1B4",
        "clip_gate": "SwingReach clips", "ball": "link #b2b40919 in graph 7"},
    "FlatTooLate": {
        "grade": "C", "trigger": "conditions 0xD00AC582 (TimingValue > PT+0x5BC = 0.1) / 0x4041760A "
                                 "(ManualShotTiming > 0.1 and SlowDown < 0.5)",
        "clip_gate": "Timing TooLate clips", "ball": "none found beyond the timing value itself (I)"},
    "FlatReturn": {
        "grade": "C", "trigger": "condition 0xFE98362E: Context.IsFastBall S+0x5DD or "
                                 "IsBaselineFastBall S+0x5DF (Planner_Reset fn_886BA768)",
        "clip_gate": "return clips", "ball": "no link port (I)"},
    "VolleyReflex": {
        "grade": "C+D", "trigger": "volley rows; AI probe on S+0x5DE (net fast ball, < 35 frames, "
                                   "|dz| < 200 cm)",
        "clip_gate": "ReflexVolley clips",
        "ball": "link #f2885ba2 in graphs 230-233, 264-267, 323-329: lowers PF and aim"},
    "VolleySpectacular": {
        "grade": "C", "trigger": "condition 0x1DE220E2: SwingSelection.VolleySpectacular S+0x388",
        "clip_gate": "4 clips", "ball": "no link port (I)"},
    "VolleyForward": {
        "grade": "C", "trigger": "condition 0x7D633A62: LocalPosition S+0x8E0 + (600 doubles / 450 "
                                 "singles) < 0 and shot not Slice/DropShot",
        "clip_gate": "26 clips", "ball": "no link port (I)"},
    "FlatFollowNet": {
        "grade": "C", "trigger": "condition 0x7E522D55: sticky RB and |world z| < 300 cm",
        "clip_gate": "MoveToNet clips", "ball": "MoveToNet link #4daa7349: no measured effect"},
    "SliceFollowNet": {
        "grade": "C", "trigger": "condition 0x7E522D55 (as FlatFollowNet) in the Slice list",
        "clip_gate": "MoveToNet clips", "ball": "as FlatFollowNet"},
}


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def parse_quals(text):
    return {k.strip(): [v.strip().strip('"') for v in vals.split(",") if v.strip()]
            for k, vals in LIST_RE.findall(text)}


def parse_rules(text):
    """Return (clips, groups) from animation_rules.yaml text."""
    clips, groups = [], []
    lines = text.splitlines()
    sect = None
    i = 0
    while i < len(lines):
        ln = lines[i]
        if ln and not ln.startswith(" ") and ln.endswith(":"):
            sect = ln[:-1]
        elif ln and not ln.startswith(" "):
            sect = None
        if sect == "animations" and ln.startswith("  - {i: "):
            block = [ln]
            while i + 1 < len(lines) and lines[i + 1].startswith("     "):
                i += 1
                block.append(lines[i])
            clips.append(parse_clip(block))
        elif sect == "anim_groups" and ln.startswith("  - {setup: "):
            g = {"setup": re.search(r"setup: (\w+)", ln).group(1),
                 "id": re.search(r"id: ([\w]+)", ln).group(1), "subgroups": []}
            while i + 1 < len(lines) and lines[i + 1].startswith("     "):
                i += 1
                m = re.search(r"\{id: (\w+), .*first: (\d+), count: (\d+)", lines[i])
                if m:
                    g["subgroups"].append((m.group(1), int(m.group(2)), int(m.group(3))))
            groups.append(g)
        i += 1
    return clips, groups


def parse_clip(block):
    head = block[0]
    c = {"i": int(re.search(r"\{i: (\d+)", head).group(1)),
         "name": re.search(r'name: ("[^"]*"|[^,]*)', head).group(1).strip('"'),
         "frames": float(re.search(r"frames: ([0-9.]+)", head).group(1)),
         "setup": (re.search(r"setup: (\w+)", head) or [None, None])[1],
         "ignore_speed_coef": "ignore_speed_coef: true" in head,
         "q": {}, "contact_phase": None, "tr": []}
    for ln in block[1:]:
        s = ln.strip()
        if s.startswith("q: "):
            c["q"] = parse_quals(s[3:])
        elif s.startswith("ev: "):
            m = re.search(r"\[EventRacket, ([-0-9.e]+)", s)
            if m:
                c["contact_phase"] = float(m.group(1))
        elif s.startswith("tr: "):
            c["tr"] = [[float(x) for x in row.split(",")] for row in NUM_LIST_RE.findall(s[4:])]
    return c


def clip_timing(c):
    """Contact frame, entry->contact (min, max) over In windows that open before contact, contact->Out."""
    if c["contact_phase"] is None:
        return None
    f = c["frames"] - 1.0          # frame k = phase k / (FrameCount - 1), as fn_88644CE8 samples
    contact = c["contact_phase"] * f
    spans = []
    outs = []
    for row in c["tr"]:
        if len(row) < 8:
            continue
        pos, dur, tin, tout = row[2], row[3], row[6], row[7]
        if tin and pos * f < contact:
            end = min((pos + dur) * f, contact)
            spans.append((contact - end, contact - pos * f))
        if tout:
            outs.append(pos * f - contact)
    after = [o for o in outs if o >= 0]
    return {"contact": contact,
            "entry_min": min(s[0] for s in spans) if spans else None,
            "entry_max": max(s[1] for s in spans) if spans else None,
            "out": min(after) if after else (max(outs) if outs else None)}


def parse_root_motion(text):
    out = {}
    sect = None
    for ln in text.splitlines():
        if ln and not ln.startswith(" "):
            sect = ln.rstrip(":")
            continue
        if sect == "swing" and ln.startswith("  - {"):
            m = re.search(r"\bi: (\d+)", ln)
            if not m:
                continue
            row = {}
            for k in ("travel_to_contact", "travel_contact_out", "v_contact"):
                mm = re.search(r"\b%s: ([-0-9.]+)" % k, ln)
                if mm:
                    row[k] = float(mm.group(1))
            out[int(m.group(1))] = row
    return out


def rng(vals, nd=1):
    vals = [v for v in vals if v is not None]
    if not vals:
        return None
    r = lambda x: round(x, nd)  # noqa: E731
    return [r(min(vals)), r(statistics.median(vals)), r(max(vals))]


def tally(seq):
    d = {}
    for v in seq:
        d[v] = d.get(v, 0) + 1
    return dict(sorted(d.items(), key=lambda kv: (-kv[1], kv[0])))


def approach_travel(db, clips):
    """Root travel (cm) over the last 20 / 40 frames before contact, per clip index (needs --core)."""
    import math
    sys.path.insert(0, HERE)
    import root_motion as R  # noqa: E402
    out = {}
    for c in clips:
        t = clip_timing(c)
        if not t or c["setup"] != "Men":
            continue
        tr = R.per_frame(db, db.record(c["i"]))
        k = max(0, min(int(round(t["contact"])), len(tr) - 1))
        row = {}
        for n in (20, 40):
            j = max(0, k - n)
            row[n] = math.hypot(tr[k][0] - tr[j][0], tr[k][1] - tr[j][1])
        out[c["i"]] = row
    return out


def summarize(clips, groups, rm, key, value, app=None):
    sel = [c for c in clips if c["setup"] == "Men" and value in c["q"].get(key, [])]
    if not sel:
        return None
    gid = {}
    for g in groups:
        if g["setup"] != "Men":
            continue
        for sid, first, count in g["subgroups"]:
            for k in range(first, first + count):
                gid[k] = "%s/%s" % (g["id"], sid)
    tim = [clip_timing(c) for c in sel]
    tim = [t for t in tim if t]
    heights = []
    for c in sel:
        toks = re.split(r"[_ ]", c["name"])
        heights.append(next((h for h in HEIGHTS if h in toks), "-"))
    s = {"clips_men": len(sel),
         "clips_women": sum(1 for c in clips if c["setup"] == "Women" and value in c["q"].get(key, [])),
         "swing_type": tally(v for c in sel for v in c["q"].get("SwingType", ["-"])),
         "height": tally(heights),
         "power_q": tally(v for c in sel for v in c["q"].get("Power", ["-"])),
         "control_q": tally(v for c in sel for v in c["q"].get("Control", ["-"])),
         "preference": tally(v for c in sel for v in c["q"].get("SwingPreferenceLevel", ["-"])),
         "ignore_speed_coef": sum(1 for c in sel if c["ignore_speed_coef"]),
         "frames_min_med_max": rng([c["frames"] for c in sel], 0),
         "contact_frame_min_med_max": rng([t["contact"] for t in tim]),
         "entry_to_contact_shortest_min_med_max": rng([t["entry_min"] for t in tim]),
         "entry_to_contact_longest_min_med_max": rng([t["entry_max"] for t in tim]),
         "contact_to_out_min_med_max": rng([t["out"] for t in tim]),
         "groups": tally(gid.get(c["i"], "-").split("/")[0] for c in sel)}
    if key == "SwingCategory":
        s["properties"] = tally(v for c in sel for v in c["q"].get("Properties", []))
    else:
        s["categories"] = tally(v for c in sel for v in c["q"].get("SwingCategory", ["-"]))
    if app:
        a = [app[c["i"]] for c in sel if c["i"] in app]
        if a:
            s["root_travel_last_20f_before_contact_cm_min_med_max"] = rng([r[20] for r in a])
            s["root_travel_last_40f_before_contact_cm_min_med_max"] = rng([r[40] for r in a])
    rows = [rm[c["i"]] for c in sel if c["i"] in rm]
    if rows:
        s["root_travel_to_contact_cm_min_med_max"] = rng([r.get("travel_to_contact") for r in rows])
        s["root_travel_contact_to_out_cm_min_med_max"] = rng([r.get("travel_contact_out") for r in rows])
        s["root_speed_at_contact_cm_per_frame_min_med_max"] = rng([r.get("v_contact") for r in rows], 2)
    return s


def rule_rows(settings):
    sys.path.insert(0, HERE)
    import shot_tree as S  # noqa: E402
    r = S.swing_category_rules(settings)
    where = {}
    for mode, lists in r["modes"].items():
        for cls, rows in lists.items():
            for k, row in enumerate(rows):
                for field in ("value", "alt"):
                    if row[field]:
                        where.setdefault(row[field], []).append(
                            "%s/%s row %d %s%s cond %s%s" % (
                                mode, cls, k, field, "" if field == "value" else " (fallback)",
                                row["condition"], ", easy" if row["easy_autoswing"] else ""))
    return where


def y(v):
    if v is None:
        return "null"
    if isinstance(v, bool):
        return "true" if v else "false"
    if isinstance(v, (int, float)):
        return repr(v)
    if isinstance(v, list):
        return "[" + ", ".join(y(x) for x in v) + "]"
    if isinstance(v, dict):
        return "{" + ", ".join("%s: %s" % (q(k), y(x)) for k, x in v.items()) + "}"
    return q(v)


def q(s):
    s = str(s)
    if re.fullmatch(r"[A-Za-z_][A-Za-z0-9_/.]*", s) and s not in ("Yes", "No", "None", "true", "false",
                                                                  "null", "on", "off", "y", "n"):
        return s
    return '"' + s.replace("\\", "\\\\").replace('"', '\\"') + '"'


def build(rules_path, rm_path, settings_path, core=None):
    text = open(rules_path, encoding="utf-8").read()
    clips, groups = parse_rules(text)
    rm = parse_root_motion(open(rm_path, encoding="utf-8").read()) if rm_path else {}
    where = rule_rows(open(settings_path, "rb").read()) if settings_path else {}
    app = None
    if core:
        sys.path.insert(0, HERE)
        import root_motion as R  # noqa: E402
        app = approach_travel(R.AnimDb(open(os.path.join(core, R.ANIMDB + ".bin"), "rb").read()), clips)
    cats = []
    for ln in text.splitlines():
        if "id: SwingCategory, values:" in ln:
            cats = [v.strip().strip('"') for v in ln.split("values: [")[1].rstrip("]}").split(",")]
        if "id: Properties, values:" in ln:
            props = [v.strip().strip('"') for v in ln.split("values: [")[1].rstrip("]}").split(",")]
    by_cat = {c: summarize(clips, groups, rm, "SwingCategory", c, app) for c in cats}
    by_prop = {p: summarize(clips, groups, rm, "Properties", p, app) for p in props}
    return clips, by_cat, by_prop, where


def emit(out, args, by_cat, by_prop, where, srcs):
    w = out.append
    w("# Top Spin 4 special and situational swings: clips per SwingCategory / Properties value (agent G8).")
    w("# Generated; do not edit by hand.  Docs: docs/gameplay/controls-and-shot-selection.md s18,")
    w("# docs/gameplay/movement-and-animation.md \"G8: special swings\".")
    w("# Generator: python3 tools/ts4data/special_swings.py " + " ".join(args))
    w("# Python %d.%d.%d" % sys.version_info[:3])
    for label, (path, size, sha) in srcs.items():
        w("# Source %s: %s, %d bytes, sha256 %s" % (label, path, size, sha))
    w("# Units: frames at 60 Hz (play rate 1), cm.  Men setup counts (Women mirror).  [min, median, max].")
    w("# entry_to_contact_shortest/longest: frames from entering the clip at the end / start of its In")
    w("# transition window to the EventRacket contact.  contact_to_out: contact to the first Out window.")
    w("sources:")
    for label, (path, size, sha) in srcs.items():
        w("  %s: {path: %s, size: %d, sha256: %s}" % (q(label), q(path), size, sha))
    w("triggers:")
    for cat, t in TRIGGERS.items():
        w("  %s:" % cat)
        for k, v in t.items():
            w("    %s: %s" % (k, q(v)))
        if where:
            w("    rule_rows: %s" % y(where.get(cat, [])))
    w("by_swing_category:")
    for cat, s in by_cat.items():
        if not s:
            w("  %s: null  # no clip" % q(cat))
            continue
        w("  %s:" % q(cat))
        for k, v in s.items():
            w("    %s: %s" % (k, y(v)))
        if where and cat not in TRIGGERS:
            w("    rule_rows: %s" % y(where.get(cat, [])))
    w("by_properties:")
    for p, s in by_prop.items():
        if not s:
            w("  %s: null  # no clip" % q(p))
            continue
        w("  %s:" % q(p))
        for k, v in s.items():
            w("    %s: %s" % (k, y(v)))


def selftest():
    block = ['  - {i: 7, name: "Swing_FH_Fatality_Shoulder_Front_00 - x", frames: 200.0, group: 12, '
             'sub: 64, setup: Men, max_occ: 1,',
             '     q: {PositionOnCourt: [Baseline], SwingType: [FH], SwingCategory: [Fatality], '
             'SwingPreferenceLevel: ["5"]},',
             '     ev: [[Hand_FH_Pose, 0.1, 0.4, 0.0], [EventRacket, 0.6, 0.0, 0.0]],',
             '     tr: [[0, 0, 0.0, 0.1, 0.0, 0.0, 1, 0], [0, 0, 0.2, 0.3, 0.4, 0.2, 1, 0], '
             '[0, 0, 0.8, 0.2, 0.9, 0.8, 0, 1]]}']
    c = parse_clip(block)
    assert c["i"] == 7 and c["frames"] == 200.0 and c["setup"] == "Men", c
    assert c["q"]["SwingCategory"] == ["Fatality"] and c["q"]["SwingPreferenceLevel"] == ["5"]
    t = clip_timing(c)
    assert abs(t["contact"] - 119.4) < 1e-6, t
    assert abs(t["entry_min"] - 19.9) < 1e-6 and abs(t["entry_max"] - 119.4) < 1e-6, t
    assert abs(t["out"] - 39.8) < 1e-6, t
    text = "animations:\n" + "\n".join(block) + "\nother: 1\n"
    clips, groups = parse_rules(text)
    assert len(clips) == 1 and not groups
    rm = parse_root_motion("swing:\n  - {name: a, i: 7, frames: 200, travel_to_contact: 450.5, v_contact: 2.2}\n")
    assert rm == {7: {"travel_to_contact": 450.5, "v_contact": 2.2}}
    s = summarize(clips, [], rm, "SwingCategory", "Fatality")
    assert s["clips_men"] == 1 and s["height"] == {"Shoulder": 1}
    assert s["root_travel_to_contact_cm_min_med_max"] == [450.5, 450.5, 450.5]
    assert q("Yes") == '"Yes"' and q("FlatPower") == "FlatPower"
    print("special_swings selftest ok")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--rules", default="data/gameplay/animation_rules.yaml")
    ap.add_argument("--root-motion", default="data/gameplay/root_motion.yaml")
    ap.add_argument("--settings", default=None, help="Settings.bin (work/disc/core/334e7e0d.bin)")
    ap.add_argument("--core", default=None, help="work/disc/core_all: adds root travel over the last "
                    "20 / 40 frames before contact (tools/ts4data/root_motion.py sampler)")
    ap.add_argument("--out", default=None)
    ap.add_argument("--selftest", action="store_true")
    a = ap.parse_args(argv)
    if a.selftest:
        selftest()
        return 0
    rm_path = a.root_motion if a.root_motion and os.path.exists(a.root_motion) else None
    clips, by_cat, by_prop, where = build(a.rules, rm_path, a.settings, a.core)
    srcs = {}
    for label, path in (("animation_rules.yaml", a.rules), ("root_motion.yaml", rm_path),
                        ("Settings.bin", a.settings)) + (
                            (("AnimationsDB.bin", os.path.join(a.core, "70155255.bin")),) if a.core else ()):
        if path:
            srcs[label] = (path, os.path.getsize(path), sha256_file(path))
    # Upstream disc files of the YAML inputs, copied from their headers.
    up = []
    for path in (a.rules, rm_path):
        if not path:
            continue
        for ln in open(path, encoding="utf-8").read().splitlines()[:12]:
            m = re.search(r"(\S+\.bin) \(([^)]*)\)[:,]? \{?(?:size: )?(\d+)(?: bytes)?,? sha256:? ([0-9a-f]{64})", ln)
            if m and m.group(1) not in up:
                up.append(m.group(1))
                srcs["upstream " + m.group(1)] = ("%s (%s)" % (m.group(1), m.group(2)), int(m.group(3)),
                                                  m.group(4))
    args = []
    for flag, val in (("--rules", a.rules), ("--root-motion", rm_path), ("--settings", a.settings),
                      ("--core", a.core),
                      ("--out", a.out)):
        if val:
            args += [flag, val]
    out = []
    emit(out, args, by_cat, by_prop, where, srcs)
    text = "\n".join(out) + "\n"
    if a.out:
        with open(a.out, "w", encoding="utf-8") as f:
            f.write(text)
        print("wrote %s (%d clips parsed)" % (a.out, len(clips)))
    else:
        sys.stdout.write(text)
    return 0


if __name__ == "__main__":
    sys.exit(main())
