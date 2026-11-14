#!/usr/bin/env python3
"""Measured baseline of the retail Top Spin 4 gameplay, for the retune design (docs/design/retune-baseline.md).

Standard library only.  It reads the local, git-ignored game files (never written into the repo) and
evaluates them with the repository's own models:

  * analyser graphs  -> tools/ts4_analyser.py (bit-faithful kernels, ramp curves);
  * ball flight      -> tools/ts4data/ball_model.py (port of ref/gameplay/ball.c) on the rows decoded by
                        tools/ts4data/templates.py, plus the closed-form arc 2 after the bounce;
  * timing curves    -> the SwingTimingSelectionList rows of data/gameplay/tunables (same as ref/gameplay/timing.c).

Every section prints Markdown tables.  Usage:

  python3 tools/design/retune_baseline.py [--work work/disc] [--tu] SECTION [...]
  SECTION: inputs speeds shape timing situ stats skills serve net all

Inputs (defaults, relative to the repository root):
  Settings.bin     work/disc/core_big/334e7e0d.bin   (TU1: work/disc/tu1_arc/334e7e0d.bin)
  State.bin        work/disc/core_big/623d0979.bin   (TU1: work/disc/tu1_arc/623d0979.bin)
  Expressions.bin  work/disc/core_all/fa94f637.bin   (TU1: work/disc/tu1_arc/fa94f637.bin)
  Layoutall.bin    work/disc/Layoutall.bin           (TU1: orig/54540859/tu1/files/Layoutall.bin)
"""

import argparse
import hashlib
import math
import os
import re
import sys
import zlib

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, "tools"))
sys.path.insert(0, os.path.join(ROOT, "tools", "ts4data"))

import baseline_lib as L  # noqa: E402

# --------------------------------------------------------------------------- inputs

DISC = {
    "settings": "work/disc/core_big/334e7e0d.bin",
    "state": "work/disc/core_big/623d0979.bin",
    "expressions": "work/disc/core_all/fa94f637.bin",
    "layout": "work/disc/Layoutall.bin",
}
TU1 = {
    "settings": "work/disc/tu1_arc/334e7e0d.bin",
    "state": "work/disc/tu1_arc/623d0979.bin",
    "expressions": "work/disc/tu1_arc/fa94f637.bin",
    "layout": "orig/54540859/tu1/files/Layoutall.bin",
}

# shot-class table (graphs-decoded.md s5): class -> (aiming, net, fault, power)
CLASSES = {
    "SliceFinesse": (190, 279, 278, 240), "TopSpinFinesse": (189, 277, 276, 239), "FlatFinesse": (188, 275, 274, 238),
    "SliceMedium": (204, 288, 287, 245), "TopSpinMedium": (203, 286, 285, 244), "FlatMedium": (202, 284, 283, 243),
    "SlicePower": (207, 297, 296, 250), "TopSpinPower": (206, 295, 294, 249), "FlatPower": (205, 293, 292, 248),
    "TopSpinRisk": (210, 303, 302, 253), "SliceRisk": (211, 305, 304, 254), "Risk": (208, 299, 298, 251),
    "FlatRisk": (209, 301, 300, 252),
    "ReturnFlatFinesse": (224, 314, 313, 258), "ReturnTopSpinFinesse": (225, 316, 315, 259),
    "ReturnSliceFinesse": (226, 318, 317, 260), "ReturnFlatPower": (224, 314, 313, 261),
    "ReturnTopSpinPower": (228, 316, 315, 262), "ReturnSlicePower": (229, 318, 317, 263),
    "ServeFlatFinesse": (216, 306, 307, 255), "ServeSpinFinesse": (217, 306, 307, 255),
    "ServeFlatMedium": (218, 306, 308, 255), "ServeSpinMedium": (219, 306, 308, 255),
    "ServeFlatPowerful": (220, 310, 309, 256), "ServeSpinPowerful": (221, 310, 309, 256),
    "AdvancedServe": (215, 312, 311, 257),
    "VolleyPower": (231, 326, 325, 265), "VolleyStandard": (230, 324, 323, 264),
    "VolleySlice": (232, 328, 327, 266), "VolleyDrop": (233, 330, 329, 267),
    "DropShot": (236, 332, 331, 271), "Lob": (237, 333, 334, 272), "Smash": (235, 340, 339, 273),
}
# the spin-blend graph (07902e50) per class: 241 for TopSpin classes, 242 for the others (graphs-decoded s5)
SPIN_GRAPH_TOPSPIN, SPIN_GRAPH_OTHER = 241, 242

# PlayerState / Ball / Match field offsets used in scenarios (graphs-decoded s3.3, ts4_shot_error.py)
F = {
    "timing": ("player", 0x544), "hand": ("player", 0x74C), "vigor": ("player", 0xF54),
    "charge": ("player", 0xE00), "run_dist": ("player", 0x7A0), "run_speed": ("player", 0x7A4),
    "ballspeed770": ("player", 0x770), "ball_diff": ("player", 0x764), "shot_diff": ("player", 0x7A8),
    "rally": ("match", 0x334), "hit_x": ("ball", 0x340), "hit_y": ("ball", 0x344), "hit_z": ("ball", 0x348),
    "err_min": ("player", 0x6D4), "err_max": ("player", 0x6D8),
    "pow_min": ("player", 0x6BC), "pow_max": ("player", 0x6C0),
    "serve": ("player", 0x64C), "return": ("player", 0x650), "forehand": ("player", 0x654),
    "backhand": ("player", 0x658), "volley": ("player", 0x65C), "power": ("player", 0x660),
    "speed": ("player", 0x664), "stamina": ("player", 0x668),
    "serve_timing": ("player", 0x66C), "serve_hold": ("player", 0x670),
    "is_human": ("player", 0x560), "aim_long": ("player", 0x6F4), "aim_short": ("player", 0x6F8),
    "aim_side": ("player", 0x6FC), "side_left": ("player", 0x704), "side_right": ("player", 0x708),
    "opp_x": ("player", 0x910), "opp_z": ("player", 0x918), "inside_out": ("player", 0x7C8),
    "slowdown": ("player", 0x7CC), "poisoned": ("player", 0x7D0), "since_bounce": ("player", 0x7D8),
    "be5d458f": ("player", 0x768), "random_dev": ("player", 0xD7C), "aim3c6b": ("player", 0xD84),
    "trailing": ("player", 0xF88), "flammable": ("player", 0xF94), "ace1253a": ("player", 0xF84),
    "slices": ("player", 0xF8C), "topspins": ("player", 0xF90), "b6b22409": ("player", 0xF80),
    "wrongfoot": ("player", 0x7EC), "first_volley": None,
    "frames_to_contact": ("player", 0xCF0), "depth_diff": ("player", 0xCF4),
    "isB": ("team", 0x50), "f089f55c": ("player", 0x558),
}

STATS = ["serve", "return", "forehand", "backhand", "volley", "power", "speed", "stamina"]


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for blk in iter(lambda: f.read(1 << 20), b""):
            h.update(blk)
    return h.hexdigest()


class Inputs:
    def __init__(self, work_root, tu=False):
        paths = TU1 if tu else DISC
        self.tu = tu
        self.paths = {k: os.path.join(work_root, v) for k, v in paths.items()}
        self.data = {k: open(p, "rb").read() for k, p in self.paths.items()}

    def provenance(self):
        rows = []
        for k, p in self.paths.items():
            rows.append((k, os.path.relpath(p, ROOT), len(self.data[k]), sha256(p)))
        return L.md_table(["file", "path (git-ignored)", "bytes", "sha256"], rows)


# --------------------------------------------------------------------------- analyser graphs

class GraphEnv:
    """Evaluate analyser graphs with named scenario inputs.

    Bound ports read the scenario value of their (root, offset); unset ports take their State.bin
    initial value (which is the live value for the never-written fields, OPEN 1.10).  Link ports are
    named ``skill:<Code>`` or ``link:<path>/<qualifiers>`` and default to 0."""

    def __init__(self, inp):
        import ts4_analyser as A
        import career_data as CD
        self.A, self.CD = A, CD
        self.expr = inp.data["expressions"]
        self.graphs = A.parse_expressions(self.expr)
        self.bind = A.Bindings(inp.data["state"], inp.data["layout"])
        self.names = A.load_name_table(A.DEFAULT_NAME_TABLE)
        self.nm = A.Namer(self.names)
        self._labels = {}

    def port_key(self, p):
        if p.index == -1:
            lv, q = self.CD.link_qualifiers(self.expr, p)
            if q and q[0] in self.CD.SKILL_CRC and zlib.crc32(b"SkillList") in lv:
                return "skill:" + self.CD.SKILL_CRC[q[0]]
            qn = [self.CD.SKILL_CRC.get(x) or self.nm(x) for x in q]
            return "link:" + "/".join(qn)
        b = self.bind.bind(p)
        if b:
            return (b["root"], b["root_offset"])
        return "unbound:%d" % p.slot

    def port_info(self, gi):
        if gi not in self._labels:
            g = self.graphs[gi]
            ins = []
            for p in g.inputs:
                key = self.port_key(p)
                dflt = 0.0
                name = key
                if isinstance(key, tuple):
                    b = self.bind.bind(p)
                    dflt = b.get("state_default", 0.0) or 0.0
                    name = "%s+0x%x %s" % (key[0], key[1], ".".join(
                        self.nm(x) if isinstance(x, int) else x for x in b["member"]))
                ins.append((p, key, dflt, name))
            outs = []
            for p in g.outputs:
                key = self.port_key(p)
                outs.append((p, key))
            self._labels[gi] = (ins, outs)
        return self._labels[gi]

    def evaluate(self, gi, scen):
        """scen: {(root, off) | 'skill:X' | 'link:Q' | alias: value}; returns {(root, off) or key: value}."""
        ins, outs = self.port_info(gi)
        s = {}
        for k, v in scen.items():
            s[F[k] if k in F else k] = v
        vals = [s.get(key, dflt) for (_, key, dflt, _) in ins]
        res = self.A.evaluate(self.graphs[gi], vals)
        return {key: v for (_, key), v in zip(outs, res)}

    def out(self, gi, scen, field):
        r = self.evaluate(gi, scen)
        return r.get(F[field] if field in F else field)

    def input_names(self, gi):
        ins, _ = self.port_info(gi)
        seen, out = set(), []
        for _, key, dflt, name in ins:
            if key in seen:
                continue
            seen.add(key)
            out.append((key, dflt, name))
        return out

    def input_domain(self, gi, key):
        """x-range of the curve keys that read this input directly (else [0, 1])."""
        g = self.graphs[gi]
        ins, _ = self.port_info(gi)
        slots = {p.slot for (p, k, _, _) in ins if k == key}
        lo, hi = None, None
        for n in g.nodes:
            if n.kind == "CURVE" and n.fields["in"] in slots:
                for kk in n.fields["keys"]:
                    lo = kk[0] if lo is None else min(lo, kk[0])
                    hi = kk[1] if hi is None else max(hi, kk[1])
        if lo is None:
            return (0.0, 1.0)
        return (lo, hi)


# --------------------------------------------------------------------------- data rows (read-only YAML text)

def shotdef_rows():
    """ShotDef[i] of Settings.bin as dumped in data/gameplay/tunables/Settings/11_ShotPalette.yaml:
    Good-grade Power/Error resolution and the shot-class (ResolutionConfig) of each template row."""
    path = os.path.join(ROOT, "data", "gameplay", "tunables", "Settings", "11_ShotPalette.yaml")
    rows = {}
    pat = re.compile(r'\s*- \[(0x[0-9a-f]+), (\w+), ([^,]+), "/ShotDef\[(\d+)\]/(.*?)"\](?:\s*#\s*(\S+))?')
    for line in open(path):
        m = pat.match(line)
        if not m:
            continue
        _, _, v, i, p, c = m.groups()
        d = rows.setdefault(int(i), {})
        if p == "ShotResolution/ResolutionConfig" or p == "ServeResolution/ResolutionConfig":
            d["class"] = c
        elif p == "ShotResolution/bc29d202":
            d["return_class"] = c
        elif p == "ShotResolution/PowerResolution/Good/Min":
            d["pow_min"] = float(v)
        elif p == "ShotResolution/PowerResolution/Good/Max":
            d["pow_max"] = float(v)
        elif p == "ShotResolution/ErrorResolution/Good/Min":
            d["err_min"] = float(v)
        elif p == "ShotResolution/ErrorResolution/Good/Max":
            d["err_max"] = float(v)
    return rows


def timing_curves():
    """SwingTimingSelectionList worst/best curves (Baseline, Volley) and the serve curve table from
    data/gameplay/tunables/Settings/02_PlayerSettings.yaml: {name: [(InStart, InStop, OutStart, OutStop)]}."""
    path = os.path.join(ROOT, "data", "gameplay", "tunables", "Settings", "02_PlayerSettings.yaml")
    pat = re.compile(r'\s*- \[(0x[0-9a-f]+), (\w+), ([^,]+), "(/SwingTimingSelectionList/[^"]*)"\]')
    cur = {}
    for line in open(path):
        m = pat.match(line)
        if not m:
            continue
        v, p = m.group(3), m.group(4)
        mm = re.match(r"(.*)/Range\[(\d+)\]/(InStart|InStop|OutStart|OutStop)$", p)
        if not mm:
            continue
        cur.setdefault(mm.group(1), {}).setdefault(int(mm.group(2)), {})[mm.group(3)] = float(v)
    out = {}
    for k, d in cur.items():
        out[k] = [(r["InStart"], r["InStop"], r["OutStart"], r["OutStop"]) for _, r in sorted(d.items())
                  if len(r) == 4]
    return out
