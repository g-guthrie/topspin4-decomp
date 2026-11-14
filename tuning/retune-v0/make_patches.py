#!/usr/bin/env python3
"""Generate the retune-v0 data patch set (standard library only).

Reads the local, git-ignored retail game files (disc and Title Update #1 copies of Settings.bin and
Expressions.bin, with their Layoutall.bin) and writes, for every group, only the values that change:

  tuning/retune-v0/<group>/settings.disc.<Section>.yaml   rows for tools/ts4data/patch_tunables.py (disc copy)
  tuning/retune-v0/<group>/settings.tu1.<Section>.yaml    the same edits placed in the Title Update copy
  tuning/retune-v0/<group>/expressions.json               tools/ts4_analyser_patch.py patch (valid for both
                                                          copies; checked below)
  tuning/retune-v0/<group>/README.md                      what the player should feel + the change table
  tuning/retune-v0/manifest.json                          source hashes and the group list (read by
                                                          tools/apply_retune.py)

Every number below is copied from docs/design/retune-spec.md (section named at each value) or is a
labelled judgement where the spec gives only a direction.  The generator applies each group to both
copies with the existing tools (patch_tunables.apply/verify, ts4_analyser_patch.patch_expressions) before
writing, so a file that is written is known to apply.

  python3 tuning/retune-v0/make_patches.py [--check]     # --check: compare with the committed files

Inputs (defaults; all git-ignored):
  work/disc/core_big/334e7e0d.bin   Settings.bin (disc)      work/disc/tu1_arc/334e7e0d.bin   (TU1)
  work/disc/core_all/fa94f637.bin   Expressions.bin (disc)   work/disc/tu1_arc/fa94f637.bin   (TU1)
  work/disc/Layoutall.bin           disc layout              orig/54540859/tu1/files/Layoutall.bin (TU1)
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, os.path.join(ROOT, "tools"))
sys.path.insert(0, os.path.join(ROOT, "tools", "ts4data"))

import ts4_analyser as A  # noqa: E402
import ts4_analyser_patch as AP  # noqa: E402
import ts4_xbin as X  # noqa: E402
import patch_tunables as PT  # noqa: E402
from dump_tunables import EDITABLE, f32_repr, split_path  # noqa: E402

SPEC_COMMIT = "93e3761"   # last commit of docs/design/retune-spec.md when these values were taken

FILES = {
    "disc": {"settings": "work/disc/core_big/334e7e0d.bin", "expressions": "work/disc/core_all/fa94f637.bin",
             "layout": "work/disc/Layoutall.bin", "archive": "Core.arc"},
    "tu1": {"settings": "work/disc/tu1_arc/334e7e0d.bin", "expressions": "work/disc/tu1_arc/fa94f637.bin",
            "layout": "orig/54540859/tu1/files/Layoutall.bin", "archive": "TitleUpdate.arc"},
}
SETTINGS_KEY, EXPRESSIONS_KEY = 0x334E7E0D, 0xFA94F637
ARCHIVES = {   # whole-archive hashes the applier checks before touching anything
    "Core.arc": {"size": 36997962, "sha256": "7df7bfd575150e9ff3b3a171bada368e8bb4d6676ef82505f46961da0aefbf50"},
    "TitleUpdate.arc": {"size": 555570, "sha256": "729235a9576bb403a8a7b8af23cc61327590c693e041d24cc9bac7407b70ce26"},
}
NAMES = [os.path.join(ROOT, "data", "gameplay", "names.yaml"), os.path.join(ROOT, "work", "disc", "values", "names.json")]

SEC_SHOTS = "<Pam::SwingGamePlay::Data::SettingsData>/ShotPalette"
SEC_PLAYER = "<Pam::SwingGamePlay::Data::SettingsData>/PlayerSettings"

GROUPS = ["ratings", "timing", "bounce_flight", "speeds_power", "serve", "aim_depth", "volleys"]

FEEL = {
    "ratings": "Every rating point counts: no flat zone below 30 and no low plateau to 60, so a 45-rated stroke is "
               "clearly better than a 30 and clearly worse than a 70 (spec 9a).",
    "timing": "The timing window follows the stroke's own rating: a 100-rated forehand has a 10% wider Perfect/Good "
              "window than a 70, a 40 one 10% narrower (the W_rating part of spec 5; approximation).",
    "bounce_flight": "Balls lose speed at the bounce instead of gaining it: heavy topspin keeps about 84%, a flat "
                     "drive about 78-83%, slice about 72% and skids low; topspin powerful drives fly higher with "
                     "more drag and kick up, slice powerful stays lower (spec 3).",
    "speeds_power": "Nothing in v0: the speed ceilings and the bigger power-tier payoff belong to the set-up grade, "
                    "which is code (see README).",
    "serve": "Big flat serves are faster: the flat serve rows' launch target rises from 190 to 245 km/h, so a "
             "held, well-timed flat serve from a strong server reaches the 100-150 mph range (spec 2d, 3d).",
    "aim_depth": "The stroke rating now matters for placement (efficiency x (0.65 + 0.35 x stroke stat)), and the "
                 "depth pull depends on timing: a Perfect drive lands within 40 cm of the aimed depth, a poor one "
                 "2-3 m short (spec 7a c, 7b).",
    "volleys": "A hard volley is a weak ball, not an error: low contact (below net height) and little time cost "
               "pace and placement and the ball floats short; standard volleys now have a depth pull (spec 8).",
}


# --------------------------------------------------------------------------- inputs

def sha256(b):
    return hashlib.sha256(b).hexdigest()


def read(p):
    with open(os.path.join(ROOT, p), "rb") as f:
        return f.read()


class Copy:
    """One data set (disc or TU1): bytes, layout, walker leaves by structural path, parsed graphs."""

    def __init__(self, tag):
        f = FILES[tag]
        self.tag = tag
        self.archive = f["archive"]
        self.settings = read(f["settings"])
        self.expressions = read(f["expressions"])
        self.layout_bytes = read(f["layout"])
        self.layout = X.Layout(self.layout_bytes)
        names = X.load_names(*[p for p in NAMES if os.path.exists(p)])
        self.root_type = X.parse_header(self.settings)["root_type"]
        self.leaves = {}
        for lf in X.Walker(self.settings, self.layout, names).walk_file():
            if lf.tag in EDITABLE:
                self.leaves[PT._strip_names(lf.path)] = lf
        self.graphs = A.parse_expressions(self.expressions)

    def leaf(self, section, rel):
        lf = self.leaves.get(PT._strip_names(section + rel))
        if lf is None:
            raise KeyError("%s: no value at %s%s" % (self.tag, section, rel))
        return lf


# --------------------------------------------------------------------------- edit containers

class Group:
    def __init__(self, name):
        self.name = name
        self.settings = []          # (section, rel path, new value, note)
        self.expr = {}              # graph index -> node index -> change dict
        self.table = []             # README rows: (what, where, retail, new, source)
        self.notes = []

    def set(self, section, rel, value, note=""):
        self.settings.append((section, rel, float(value), note))

    def curve(self, gi, ni, keys):
        """keys: list of (x0, x1, y0, y1) for the first len(keys) keys of the node."""
        self.expr.setdefault(gi, {})[ni] = {"keys": {str(k): {"x0": a, "x1": b, "y0": c, "y1": d}
                                                     for k, (a, b, c, d) in enumerate(keys)}}

    def const(self, gi, ni, value):
        self.expr.setdefault(gi, {})[ni] = {"value": float(value)}


def fmt(v):
    return f32_repr(struct.unpack(">f", struct.pack(">f", v))[0])


def keys_of(g, ni):
    return [(k[0], k[1], k[2], k[4]) for k in g.nodes[ni].fields["keys"]]


def fkeys(keys):
    return " ".join("[%s, %s, %s, %s]" % tuple(fmt(x) for x in k) for k in keys)


# --------------------------------------------------------------------------- graph helpers

class Ports:
    """Input/output port identities of a graph: (root, offset) by the disc State numbering."""

    def __init__(self, copy, state_path="work/disc/core_big/623d0979.bin"):
        self.bind = A.Bindings(read(state_path), copy.layout_bytes)

    def inputs(self, g):
        out = {}
        for p in g.inputs:
            b = self.bind.bind(p)
            if b:
                out.setdefault(p.slot, (b["root"], b["root_offset"]))
        return out

    def outputs(self, g):
        out = {}
        for p in g.outputs:
            b = self.bind.bind(p)
            if b:
                out[(b["root"], b["root_offset"])] = p.slot
        return out


def producers(g):
    prod = {}
    for i, n in enumerate(g.nodes):
        for w in n.writes():
            prod[w] = i
    return prod


HAND = ("player", 0x74C)
RANDOM = ("player", 0xD7C)
EFFICIENCY = ("player", 0xD88)
DEEPDEV = ("player", 0xD78)
CF0 = ("player", 0xCF0)          # frames from the opponent's contact to own contact (TimingState #3fe3a099)
HIT_Y = ("ball", 0x344)          # contact height, cm
VOLLEY = ("player", 0x65C)
PF_OUT = ("player", 0x778)


# --------------------------------------------------------------------------- groups

def g_ratings(d):
    """Spec 9a: one curve for every stat, 0 at rating 0, 0.18 at 30, 0.40 at 50, 1.00 at 100 (linear 50-100;
    retune_model.NEW_CURVE).  Graph 23 DefaultAttributes, every CURVE node."""
    G = Group("ratings")
    gi = 23
    g = d.graphs[gi]
    assert g.name == A.crc("DefaultAttributes")
    pts = [(0.0, 0.0), (30.0, 0.18), (50.0, 0.40), (100.0, 1.0)]
    split4 = [(0.0, 0.0), (30.0, 0.18), (50.0, 0.40), (75.0, 0.70), (100.0, 1.0)]
    for ni, n in enumerate(g.nodes):
        if n.kind != "CURVE":
            continue
        nk = len(n.fields["keys"])
        p = pts if nk == 3 else split4 if nk == 4 else None
        assert p is not None, "graph 23 node %d has %d keys" % (ni, nk)
        keys = [(p[i][0], p[i + 1][0], p[i][1], p[i + 1][1]) for i in range(len(p) - 1)]
        G.curve(gi, ni, keys)
        G.table.append(("rating -> stat, node %d" % ni, "Expressions graph 23 DefaultAttributes", fkeys(keys_of(g, ni)),
                        fkeys(keys), "spec 9a"))
    G.notes.append("The floor penalty below rating 60 (spec 9a) adds error on the stroke's own job; it needs the "
                   "fault graphs to read a rating term they do not have, so it is not in v0.")
    return G


TIMING_LISTS = ["/SwingTimingSelectionList/Baseline/5ae85f27/848c2a13", "/SwingTimingSelectionList/Baseline/5ae85f27/BestAbility",
                "/SwingTimingSelectionList/Volley/5ae85f27/848c2a13", "/SwingTimingSelectionList/Volley/5ae85f27/BestAbility"]
W_WORST, W_BEST = 0.90, 1.10       # spec 5: W_rating 0.90 at rating 40, 1.10 at 100
STAT_AT_40 = 0.29                  # NEW_CURVE at rating 40 (ratings group)


def g_timing(d):
    """Spec 5 / systems s3, the W_rating factor only.  The frames->t curves are stretched about the perfect
    point (20 frames): a window W wide reaches the same t at 20 + (f - 20) * W frames.  The worst-ability curve
    gets W 0.90, the best 1.10; TimingAbility (graphs 40-42) becomes 0 at stat 0.29 (rating 40) and 1 at
    stat 1.0 (rating 100), so the engine's own worst/best blend gives W_rating 0.90 / 1.00 / 1.10 at ratings
    40 / 70 / 100 (clamped below 40, as retune_model.W_RATING)."""
    G = Group("timing")
    for lst in TIMING_LISTS:
        w = W_BEST if lst.endswith("BestAbility") else W_WORST
        k = 0
        while True:
            try:
                a = d.leaf(SEC_PLAYER, "%s/Range[%d]/InStart" % (lst, k)).value
                b = d.leaf(SEC_PLAYER, "%s/Range[%d]/InStop" % (lst, k)).value
            except KeyError:
                break
            na, nb = 20.0 + (a - 20.0) * w, 20.0 + (b - 20.0) * w
            G.set(SEC_PLAYER, "%s/Range[%d]/InStart" % (lst, k), na)
            G.set(SEC_PLAYER, "%s/Range[%d]/InStop" % (lst, k), nb)
            k += 1
        assert k == 6, lst
        G.table.append(("frames -> t breakpoints", "Settings PlayerSettings%s/Range[0..5]/InStart,InStop" % lst,
                        "10 12 15 20 25 30 40 (frames)", " ".join(fmt(20 + (x - 20) * w) for x in (10, 12, 15, 20, 25, 30, 40)),
                        "W = %.2f" % w))
    for gi in (40, 41, 42):
        g = d.graphs[gi]
        assert len(g.nodes) == 1 and g.nodes[0].kind == "CURVE"
        keys = [(STAT_AT_40, 1.0, 0.0, 1.0)]
        G.curve(gi, 0, keys)
        G.table.append(("TimingAbility from the stroke stat", "Expressions graph %d (%s)" % (gi, {40: "Return", 41: "Forehand/Backhand", 42: "Volley"}[gi]),
                        fkeys(keys_of(g, 0)), fkeys(keys), "spec 5 W_RATING"))
    G.notes += ["Approximation: only the W_rating factor of the window is data. W_opp (the opponent's timing), "
                "W_grade and W_react, and dividing t by W, are code (fn_8867DF68).",
                "Assumes the engine blends the worst and best curves' t-values by TimingAbility (S+0xD0C), as "
                "retune-spec 5 states; with the retail curves identical this was never visible in play.",
                "The ratings group sets the stat curve the 0.29 threshold is keyed on; without it the window "
                "still widens with rating, but a 70 rating gets W of about 0.96 instead of 1.00.",
                "Serves keep their per-animation timing curves (not changed)."]
    return G


TOPSPIN_FLAT_ROWS = [0, 2, 4, 6, 8, 10, 12, 14]     # TopSpin/Flat Finesse, Normal (Medium, Powerful), Risky
TOPSPIN_ROWS = [0, 4, 8, 12]
SLICE_ROWS = [1, 5, 9, 13]
BOUNCE_PROP = (-0.30, 0.0, 0.16, 0.22)               # spec 3, retune_spec.BOUNCE_PROP
BOUNCE_SLICE = (0.0, 0.20, 0.22, 0.30)               # spec 3, retune_spec.BOUNCE_SLICE
ROW_EDITS = {   # spec 3 "What changes" and retune_spec.PROPOSED (primary speeds excluded, see speeds_power)
    10: dict(T=0.050, spin_a=(-0.04, -0.30)),
    8: dict(T=0.0525, spin_a=(-0.10, -0.42)),
    9: dict(T=0.050, spin_a=(0.06, 0.18)),
}
OUT_ELEV_GAIN = {"topspin": 1.08, "slice": 0.85}


def _row(i):
    return "/ShotDef[%d]/ShotConfig" % i


def g_bounce(d):
    G = Group("bounce_flight")
    for i in TOPSPIN_FLAT_ROWS + SLICE_ROWS:
        curve = BOUNCE_SLICE if i in SLICE_ROWS else BOUNCE_PROP
        base = _row(i) + "/BounceConfig/527725aa/Range[0]"
        old = tuple(d.leaf(SEC_SHOTS, base + "/" + f).value for f in ("InStart", "InStop", "OutStart", "OutStop"))
        for f, v in zip(("InStart", "InStop", "OutStart", "OutStop"), curve):
            G.set(SEC_SHOTS, base + "/" + f, v)
        G.table.append(("bounce speed loss vs spin_a, row %d" % i, "Settings ShotDef[%d] BounceConfig/527725aa" % i,
                        fkeys([old]), fkeys([curve]), "spec 3 (Powerful rows; same curve on the family's other rows)"))
    for fam, rows in (("topspin", TOPSPIN_ROWS), ("slice", SLICE_ROWS)):
        gain = OUT_ELEV_GAIN[fam]
        for i in rows:
            base = _row(i) + "/BounceConfig/e96ae850/Range[0]"
            old = tuple(d.leaf(SEC_SHOTS, base + "/" + f).value for f in ("InStart", "InStop", "OutStart", "OutStop"))
            new = (0.0, 1.5, 0.0, 1.5 * gain)
            for f, v in zip(("InStart", "InStop", "OutStart", "OutStop"), new):
                G.set(SEC_SHOTS, base + "/" + f, v)
            G.table.append(("bounce out-elevation, row %d" % i, "Settings ShotDef[%d] BounceConfig/e96ae850" % i,
                            fkeys([old]), fkeys([new]), "spec 3 (gain %.2f)" % gain))
    for i, ed in ROW_EDITS.items():
        t_old = d.leaf(SEC_SHOTS, _row(i) + "/MiscConfig/e6d14874").value
        if abs(t_old - ed["T"]) > 1e-6:
            G.set(SEC_SHOTS, _row(i) + "/MiscConfig/e6d14874", ed["T"])
            G.table.append(("drag T, row %d" % i, "Settings ShotDef[%d] MiscConfig/e6d14874" % i, fmt(t_old), fmt(ed["T"]), "spec 3"))
        for el, v in zip((0, 1), ed["spin_a"]):
            base = _row(i) + "/EffectConfig/3d54f391/Element[%d]<f9f12a60>/Range[0]" % el
            old = (d.leaf(SEC_SHOTS, base + "/OutStart").value, d.leaf(SEC_SHOTS, base + "/OutStop").value)
            G.set(SEC_SHOTS, base + "/OutStart", v)
            G.set(SEC_SHOTS, base + "/OutStop", v)
            G.table.append(("spin_a %s, row %d" % ("lo" if el == 0 else "hi", i),
                            "Settings ShotDef[%d] EffectConfig/3d54f391/Element[%d]" % (i, el),
                            "%s..%s" % (fmt(old[0]), fmt(old[1])), "%s (constant)" % fmt(v), "spec 3"))
    G.notes += ["The spec's higher launch targets for these rows (primary 178-200 / 150-168 / 118-132 km/h) are left "
                "out: with the retail power graphs they would speed up every shot (flat median 129 -> 147 km/h), "
                "while the spec keeps averages at retail and reaches the ceilings only through the grade (code).",
                "Bounce and out-elevation curves are applied to the whole spin family (Finesse, Medium, Powerful, "
                "Risky rows); drag and spin only to the Powerful rows the spec specifies (8, 9, 10). Returns use "
                "rows 8-10, so they change too. Lobs, volleys, serves, smash and drop shots keep their bounce.",
                "Per-surface bounce needs code (no surface input to the bounce routine)."]
    return G


SERVE_FLAT_ROWS = [26, 27, 28, 31]     # ServeNormal flat Medium / Powerful / Finesse, ServeAdvanced flat
SERVE_PRIMARY = 245.0                  # spec 3d: "primary 245 km/h"


def g_serve(d):
    G = Group("serve")
    for i in SERVE_FLAT_ROWS:
        p = _row(i) + "/PerfectShot/Element<33799cce>/Value"
        old = d.leaf(SEC_SHOTS, p).value
        G.set(SEC_SHOTS, p, SERVE_PRIMARY)
        G.table.append(("flat serve launch target, row %d" % i, "Settings ShotDef[%d] PerfectShot (const)" % i,
                        fmt(old), fmt(SERVE_PRIMARY), "spec 3d"))
    G.notes += ["Kick and slice serve rows are unchanged, so second serves (usually kick) keep retail pace, which is "
                "close to the spec's average-pro second serve (74 mph).",
                "The serve fault chance rising with pace, the Serve-rating floor and the stamina cost 1 + 3 effort^2 "
                "need a random fault roll and an effort input (code). No faithful data approximation exists: the "
                "human serve fault graphs (307-311) read only the gauge timing, not the pace.",
                "Title Update #1 already makes tired power and advanced serves less accurate (graphs 215, 220, 311); "
                "this group does not touch those graphs."]
    return G


HAND_FLOOR = 0.65          # spec 7a: quality x (0.65 + 0.35 x hand stat)
DEEP_GOOD = (0.0, 1.0, 40.0, 0.0)            # spec 7b Perfect: 0-40 cm
DEEP_BAD = [(0.0, 0.5, 310.0, 255.0), (0.5, 1.0, 255.0, 200.0)]   # spec 7b outside Good: 200-310 cm
DEEP_MIX = [(0.0, 0.6, 0.0, 0.0), (0.6, 0.85, 0.0, 1.0)]          # quality -> weight of the Perfect branch (judgement)
AIM_GRAPHS = {202: "FlatMedium", 203: "TopSpinMedium", 204: "SliceMedium", 205: "FlatPower", 206: "TopSpinPower",
              207: "SlicePower"}


def find_hand_lerp(g, ins):
    """The LERP that writes Efficiency from two 5-key curves of the same quality register, blended by the hand
    stat.  Returns (node of the hand-0 curve, node of the hand-1 curve)."""
    prod = producers(g)
    hits = []
    for n in g.nodes:
        if n.kind != "LERP" or ins.get(n.fields["t"]) != HAND:
            continue
        a, b = prod.get(n.fields["a"]), prod.get(n.fields["b"])
        if a is None or b is None or g.nodes[a].kind != "CURVE" or g.nodes[b].kind != "CURVE":
            continue
        if len(g.nodes[a].fields["keys"]) == len(g.nodes[b].fields["keys"]) == 5 and \
                g.nodes[a].fields["in"] == g.nodes[b].fields["in"]:
            hits.append((a, b, n.fields["out"]))
    return hits


def find_deepdev(g, ins, outs):
    """DeepDeviation = lerp(lerp(bad_s, good_s, w), lerp(bad_l, good_l, w), Long), w = curve(quality).
    Returns (bad curve nodes, good curve nodes, mix curve node)."""
    prod = producers(g)
    top = g.nodes[prod[outs[DEEPDEV]]]
    assert top.kind == "LERP"
    bad, good, mix = [], [], set()
    for r in (top.fields["a"], top.fields["b"]):
        n = g.nodes[prod[r]]
        assert n.kind == "LERP"
        ca, cb = prod[n.fields["a"]], prod[n.fields["b"]]
        assert ins.get(g.nodes[ca].fields["in"]) == RANDOM and ins.get(g.nodes[cb].fields["in"]) == RANDOM
        bad.append(ca)
        good.append(cb)
        mix.add(prod[n.fields["t"]])
    assert len(mix) == 1
    m = mix.pop()
    assert g.nodes[m].kind == "CURVE" and len(g.nodes[m].fields["keys"]) == 2
    return bad, good, m


def g_aim(d, ports):
    G = Group("aim_depth")
    for gi, cls in AIM_GRAPHS.items():
        g = d.graphs[gi]
        ins, outs = ports.inputs(g), ports.outputs(g)
        hits = [h for h in find_hand_lerp(g, ins) if h[2] == outs[EFFICIENCY]]
        assert len(hits) == 1, (gi, hits)
        a, b, _ = hits[0]
        kb = keys_of(g, b)
        new = [(k[0], k[1], k[2] * HAND_FLOOR, k[3] * HAND_FLOOR) for k in kb]
        G.curve(gi, a, new)
        G.table.append(("%s efficiency at hand stat 0" % cls, "Expressions graph %d node %d" % (gi, a),
                        fkeys(keys_of(g, a)), fkeys(new), "spec 7a (c): x0.65 of the hand-1 curve (node %d)" % b))
        bad, good, mix = find_deepdev(g, ins, outs)
        for ni in bad:
            nk = len(g.nodes[ni].fields["keys"])
            assert nk == 2
            G.curve(gi, ni, DEEP_BAD)
            G.table.append(("%s depth pull, poor quality" % cls, "Expressions graph %d node %d" % (gi, ni),
                            fkeys(keys_of(g, ni)), fkeys(DEEP_BAD), "spec 7b (outside Good: 2-3.1 m)"))
        for ni in good:
            assert len(g.nodes[ni].fields["keys"]) == 1
            G.curve(gi, ni, [DEEP_GOOD])
            G.table.append(("%s depth pull, top quality" % cls, "Expressions graph %d node %d" % (gi, ni),
                            fkeys(keys_of(g, ni)), fkeys([DEEP_GOOD]), "spec 7b (Perfect: 0-40 cm)"))
        G.curve(gi, mix, DEEP_MIX)
        G.table.append(("%s quality -> depth branch" % cls, "Expressions graph %d node %d" % (gi, mix),
                        fkeys(keys_of(g, mix)), fkeys(DEEP_MIX), "judgement (fit to spec 7b bands)"))
    G.notes += ["Applied to the Medium and Powerful groundstroke classes (graphs 202-207), the strokes of almost "
                "every rally. Finesse (188-190), returns (224-229) and the risk classes have other graph shapes "
                "and are unchanged in v0.",
                "Depth follows the aiming graph's quality value, which is the retail timing shape plus the "
                "situation terms (running, low contact). So it is a timing rule with the retail asymmetry (an early "
                "release is forgiven more than a late one), and a bad situation also pulls the ball short. The "
                "spec's purely timing-based bands need t divided by W (code) to be exact.",
                "Grade rows (AimingResolution VeryGood..VeryBad) are not touched: retail only reads Good."]
    return G


def g_speeds(d):
    G = Group("speeds_power")
    G.notes += ["Intentionally empty in v0. In the spec the Good row is retail (2a: 'Good, full charge = retail') and "
                "the speed changes are grade effects: pace caps x0.70..x1.18, tier shares above Good, the 110/105 mph "
                "ceilings and the overcharge (code: fn_886629C8, the charge state).",
                "The higher row ceilings (spec 3: flat 178-200, topspin 150-168, slice 118-132 km/h) exist for the "
                "Tee-off grade. Without it they raise every shot (measured: flat median 129 -> 147 km/h, topspin "
                "119 -> 148), against the coordinator ruling that averages stay at retail.",
                "The serve speed range is in the serve group."]
    return G


VOLLEY_PF = {264: "VolleyStandard", 265: "VolleyPower"}
VOLLEY_AIM = {230: "VolleyStandard", 231: "VolleyPower"}


def g_volleys(d, ports):
    G = Group("volleys")
    # filled in by volley_edits()
    volley_edits(G, d, ports)
    return G


def volley_edits(G, d, ports):
    pass


BUILDERS = {"ratings": g_ratings, "timing": g_timing, "bounce_flight": g_bounce, "speeds_power": g_speeds,
            "serve": g_serve, "aim_depth": g_aim, "volleys": g_volleys}


# --------------------------------------------------------------------------- writing

def expr_patch_json(G, copy):
    """{graph hash or #N: {node: change}} in the ts4_analyser_patch format."""
    counts = {}
    for g in copy.graphs:
        counts[g.name] = counts.get(g.name, 0) + 1
    out = {}
    for gi in sorted(G.expr):
        g = copy.graphs[gi]
        key = "%08x" % g.name if counts[g.name] == 1 else "#%d" % gi
        out[key] = {str(ni): G.expr[gi][ni] for ni in sorted(G.expr[gi])}
    return out


def same_graph(a, b):
    if a.name != b.name or len(a.nodes) != len(b.nodes):
        return False
    for x, y in zip(a.nodes, b.nodes):
        if x.kind != y.kind or x.fields != y.fields:
            return False
    return True


def settings_yaml(G, copy, section):
    rows = [(s, r, v, n) for s, r, v, n in G.settings if s == section]
    if not rows:
        return None, 0
    head = [
        "# retune-v0 group '%s' (%s copy of Settings.bin): only the changed values." % (G.name, copy.tag),
        "# generated by: python3 tuning/retune-v0/make_patches.py (values from docs/design/retune-spec.md @ %s)" % SPEC_COMMIT,
        "# apply with tools/apply_retune.py, or: python3 tools/ts4data/patch_tunables.py THIS.yaml ...",
        "# rows: [file offset, type, new value, path relative to 'section']  # retail value",
        "file: Settings.bin",
        "archive: %s" % copy.archive,
        "key: 0x%08x" % SETTINGS_KEY,
        "size: %d" % len(copy.settings),
        "sha256: %s" % sha256(copy.settings),
        "root_type: 0x%08x" % copy.root_type,
        'section: "%s"' % section,
        "part: 1 of 1",
        "values:",
    ]
    lines, n = [], 0
    for _s, rel, v, note in rows:
        lf = copy.leaf(section, rel)
        assert lf.tag == "float", (rel, lf.tag)
        if struct.pack(">f", v) == struct.pack(">f", lf.value):
            continue
        prefix, relpath = split_path(lf.path)
        assert PT._strip_names(prefix) == PT._strip_names(section), (prefix, section)
        lines.append('  - [0x%x, float, %s, "%s"]  # retail %s%s' % (lf.offset, fmt(v), relpath.replace('"', '\\"'),
                                                                    f32_repr(lf.value), ("; " + note) if note else ""))
        n += 1
    return "\n".join(head + lines) + "\n", n


def apply_check(G, copy, texts, epatch):
    """Apply the group to `copy` with the existing tools; returns (settings changes, expression words)."""
    nset = 0
    if texts:
        rows = []
        for t in texts:
            head, r = PT.parse_yaml(t)
            assert head["sha256"] == sha256(copy.settings)
            rows += r
        patched, changes = PT.apply(copy.settings, copy.layout, rows)
        PT.verify(copy.settings, patched, copy.layout, changes)
        nset = len(changes)
    nexp = 0
    if epatch:
        _out, rep = AP.patch_expressions(copy.expressions, epatch)
        nexp = rep["words_changed"]
    return nset, nexp


def readme(G, written):
    out = ["# retune-v0 group: %s" % G.name, "", "**What the player should feel:** " + FEEL[G.name], ""]
    if written:
        out += ["Files:", ""] + ["- `%s`" % w for w in written] + [""]
    else:
        out += ["No patch files in this group (see notes).", ""]
    if G.table:
        out += ["| change | where | retail | retune-v0 | source |", "|---|---|---|---|---|"]
        out += ["| %s |" % " | ".join(str(c) for c in row) for row in G.table]
        out.append("")
    if G.notes:
        out += ["Notes:", ""] + ["- " + n for n in G.notes] + [""]
    out += ["Generated by `python3 tuning/retune-v0/make_patches.py` from the values in "
            "`docs/design/retune-spec.md` at commit %s." % SPEC_COMMIT, ""]
    return "\n".join(out)


def build(check=False):
    disc, tu = Copy("disc"), Copy("tu1")
    ports = Ports(disc)
    results = {}
    manifest = {
        "name": "retune-v0", "spec_commit": SPEC_COMMIT, "groups": [],
        "archives": ARCHIVES,
        "members": {
            "Settings.bin": {"key": "%08x" % SETTINGS_KEY, "disc_sha256": sha256(disc.settings), "disc_size": len(disc.settings),
                             "tu1_sha256": sha256(tu.settings), "tu1_size": len(tu.settings)},
            "Expressions.bin": {"key": "%08x" % EXPRESSIONS_KEY, "disc_sha256": sha256(disc.expressions),
                                "disc_size": len(disc.expressions), "tu1_sha256": sha256(tu.expressions),
                                "tu1_size": len(tu.expressions)},
        },
        "layouts": {"disc_sha256": sha256(disc.layout_bytes), "tu1_sha256": sha256(tu.layout_bytes)},
    }
    files = {}
    for name in GROUPS:
        fn = BUILDERS[name]
        G = fn(disc, ports) if name in ("aim_depth", "volleys") else fn(disc)
        gdir = os.path.join(HERE, name)
        written = []
        entry = {"name": name, "settings": {"disc": [], "tu1": []}, "expressions": {}}
        for copy in (disc, tu):
            texts = []
            for section, label in ((SEC_SHOTS, "ShotPalette"), (SEC_PLAYER, "PlayerSettings")):
                text, n = settings_yaml(G, copy, section)
                if text:
                    rel = "%s/settings.%s.%s.yaml" % (name, copy.tag, label)
                    files[rel] = text
                    texts.append(text)
                    entry["settings"][copy.tag].append(rel)
                    written.append(os.path.basename(rel))
            ep = expr_patch_json(G, copy) if G.expr else None
            nset, nexp = apply_check(G, copy, texts, ep)
            entry.setdefault("counts", {})[copy.tag] = {"settings_values": nset, "expression_words": nexp}
        if G.expr:
            # one JSON serves both copies when every touched graph is node-for-node identical in TU1
            for gi in G.expr:
                if not same_graph(disc.graphs[gi], tu.graphs[gi]):
                    raise SystemExit("group %s touches graph %d, which differs in TU1: needs a TU1 patch" % (name, gi))
            rel = "%s/expressions.json" % name
            files[rel] = json.dumps(expr_patch_json(G, disc), indent=1, sort_keys=True) + "\n"
            entry["expressions"] = {"disc": rel, "tu1": rel}
            written.append("expressions.json")
        files["%s/README.md" % name] = readme(G, written)
        manifest["groups"].append(entry)
        results[name] = G
    files["manifest.json"] = json.dumps(manifest, indent=1, sort_keys=True) + "\n"
    bad = []
    for rel, text in sorted(files.items()):
        p = os.path.join(HERE, rel)
        if check:
            if not os.path.exists(p) or open(p).read() != text:
                bad.append(rel)
            continue
        os.makedirs(os.path.dirname(p), exist_ok=True)
        with open(p, "w") as f:
            f.write(text)
    for g in manifest["groups"]:
        print("%-14s disc: %s  tu1: %s" % (g["name"], g["counts"]["disc"], g["counts"]["tu1"]))
    if check:
        print("out of date: %s" % (", ".join(bad) if bad else "none"))
        return 1 if bad else 0
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true", help="compare with the committed files instead of writing")
    a = ap.parse_args(argv)
    return build(a.check)


if __name__ == "__main__":
    sys.exit(main())
