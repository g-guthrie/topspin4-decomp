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
    "wrongfoot": ("player", 0x7EC),
    "frames_to_contact": ("player", 0xCF0), "depth_diff": ("player", 0xCF4),
    "isB": ("team", 0x50), "f089f55c": ("player", 0x550), "ff9a119d": ("player", 0x558),
    "serve_target": ("player", 0x840),
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
        self.disc_data = self.data if not tu else {
            k: open(os.path.join(work_root, v), "rb").read() for k, v in DISC.items()}

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
        self._canon = None
        if inp.tu:
            # TU1's State.bin inserts fields (ShotContext.IsForehand/IsSecondServe), so later offsets move.
            # Translate every bound port to the disc offset of the same member path, so that F[] (disc
            # numbering) stays valid for both data sets.
            dg = A.parse_expressions(inp.disc_data["expressions"])
            db = A.Bindings(inp.disc_data["state"], inp.disc_data["layout"])
            self._canon = {}
            for g in dg:
                for p in list(g.inputs) + list(g.outputs):
                    if p.index == -1:
                        continue
                    b = db.bind(p)
                    if b:
                        self._canon[(b["root"], tuple(b["member"]))] = b["root_offset"]

    def port_key(self, p):
        if p.index == -1:
            lv, q = self.CD.link_qualifiers(self.expr, p)
            if q and q[0] in self.CD.SKILL_CRC and zlib.crc32(b"SkillList") in lv:
                return "skill:" + self.CD.SKILL_CRC[q[0]]
            qn = [self.CD.SKILL_CRC.get(x) or self.nm(x) for x in q]
            return "link:" + "/".join(qn)
        b = self.bind.bind(p)
        if b:
            if self._canon is not None:
                return (b["root"], self._canon.get((b["root"], tuple(b["member"])), 0x10000 + b["root_offset"]))
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


# --------------------------------------------------------------------------- ball flight

BASELINE_X_M = 11.885          # receiver baseline, m from the net (ball-physics s7: 1194.5 cm incl. half a line)
RETURN_X_M = 13.0              # a typical return contact depth behind the baseline (assumption, stated in the doc)

SCEN = {   # world cm (x along the court, net at 0, hitter at x < 0, y up, z across): (from, to)
    "ground_cc": ((-1188, 100, 150), (1000, 0, -300)),    # baseline cross-court, lands ~1.9 m inside
    "ground_dtl": ((-1188, 100, 300), (1050, 0, 300)),    # baseline down the line, deep
    "ground_max": ((-1250, 100, 400), (1150, 0, -400)),   # corner to corner from behind the baseline (longest)
    "ground_short": ((-1188, 100, 0), (650, 0, -350)),    # short angle, lands near the service line
    "serve_T": ((-1200, 270, 50), (600, 0, 10)),          # flat serve down the T of the deuce box
    "serve_wide": ((-1200, 270, 50), (550, 0, 380)),      # wide in the deuce box
    "volley": ((-250, 110, 0), (1000, 0, -200)),
    "volley_deep": ((-500, 90, 0), (1050, 0, 250)),
    "smash": ((-300, 250, 0), (800, 0, -150)),
    "lob": ((-1250, 100, 100), (1050, 0, -100)),
    "drop": ((-800, 80, 0), (300, 0, -50)),
    "return": ((-1300, 100, 100), (900, 0, -150)),
}


class Templates:
    def __init__(self, inp):
        import templates as T
        import ball_model as BM
        self.T, self.BM = T, BM
        self.dec = T.decode_all(inp.data["settings"], inp.data["state"])
        self.rows = self.dec["files"][0]["rows"]

    def fly(self, idx, frm, to, pf=1.0, blend=0.5, a4=0.06, net_cm=91.4, mode="ramp"):
        """Plan one In shot of template row idx with secondary weight input pf (= PowerfulFactor S+0x778,
        w = clamp01(1 - pf)) and spin blend (S+0x774); fly it through the first bounce and on to the
        receiver's baseline.  Returns a dict (speeds km/h, heights m)."""
        BM, T = self.BM, self.T
        row = self.rows[idx]
        B = BM.Ball(row["T"], a4, 9.81, 4.0, net_cm)
        B.P0 = [frm[0] * 0.01, frm[1] * 0.01 - 0.04, frm[2] * 0.01]
        B.P1 = [to[0] * 0.01, to[1] * 0.01, to[2] * 0.01]
        B.sec_weight = pf
        h = frm[1] * 0.01
        sp = row["spin"]

        def lerp(pair):
            lo = T.eval_value(pair["lo"], h, 0.0, mode)
            hi = T.eval_value(pair["hi"], h, 0.0, mode)
            return lo + (hi - lo) * blend
        B.spin = [lerp(sp["a"]), lerp(sp["b"]), lerp(sp["c"])]
        B.set_drift([B.P0[i] - B.P1[i] for i in range(3)])
        o = BM.solve(B, row, T, mode)
        tau = B.tau
        v0, v1 = B.vel1(0.0), B.vel1(tau)
        vout, spin_after, bc = BM.bounce(B, row, T, v1)
        # arc 2: drift rebuilt from the horizontal outgoing direction; no_sidespin -> only spin_a remains (vertical)
        A = [0.0, spin_after[0], 0.0]
        weff = L.arc2_weff(B.k, row["T"], A)
        p_b = list(B.P1)
        apex2, t_apex2 = L.arc2_apex(p_b, vout, B.k, weff)
        res = {}
        for tag, xt in (("base", BASELINE_X_M), ("ret", RETURN_X_M)):
            t = L.arc2_time_to_x(p_b, vout, B.k, weff, xt) if p_b[0] < xt else None
            if t is None:
                res[tag] = (None, None, None)
            else:
                p, v = L.arc2_state(p_b, vout, B.k, weff, t)
                res[tag] = (L.speed(v) * 3.6, p[1] + 0.04, tau + t)
        hz = lambda v: math.hypot(v[0], v[2])
        k_, E_, Weff_, C_ = B.consts(tau)
        r_ = C_[1] * k_ / -Weff_[1]
        apex = B.apex(tau) if r_ > 1.0 else B.P0[1]
        return {
            "launch_kmh": L.speed(v0) * 3.6, "bounce_in_kmh": L.speed(v1) * 3.6, "bounce_out_kmh": L.speed(vout) * 3.6,
            "baseline_kmh": res["base"][0], "baseline_h": res["base"][1], "t_baseline": res["base"][2],
            "return_kmh": res["ret"][0], "return_h": res["ret"][1], "t_return": res["ret"][2],
            "tau": tau, "apex_m": apex + 0.04, "net_clear_m": B.net_height() + 0.04 - net_cm * 0.01,
            "bounce_apex_m": apex2 + 0.04, "launch_deg": math.degrees(math.atan2(v0[1], hz(v0))),
            "in_deg": math.degrees(math.atan2(-v1[1], hz(v1))), "out_deg": math.degrees(math.atan2(vout[1], hz(vout))),
            "spin_a": B.spin[0], "spin_b": B.spin[1], "spin_c": B.spin[2], "k": B.k,
            "speed_limited": bool(o.get("speed_limited")), "raised": bool(o["raised"]),
            "dist_m": math.hypot(B.P1[0] - B.P0[0], B.P1[2] - B.P0[2]),
            "loss": bc["speed_loss"], "decay": bc["spin_decay"],
        }


# --------------------------------------------------------------------------- generic graph analysis

def upstream_inputs(env, gi, regs):
    """Input-port keys that feed the given registers (backward closure through the node list)."""
    g = env.graphs[gi]
    ins, _ = env.port_info(gi)
    slot_key = {}
    for p, key, _, _ in ins:
        slot_key.setdefault(p.slot, key)
    writer = {}
    for n in g.nodes:
        for w in n.writes():
            writer[w] = n
    seen, todo, keys = set(), list(regs), set()
    while todo:
        r = todo.pop()
        if r in seen:
            continue
        seen.add(r)
        if r in slot_key:
            keys.add(slot_key[r])
        n = writer.get(r)
        if n is not None:
            todo.extend(n.reads())
    return keys


def skill_triggers(env, gi, skill):
    """Keys of the inputs that gate a skill: the other operands of every non-additive node (product,
    lerp, curve, min, max, sub, div) on the forward path from the skill port to the outputs."""
    g = env.graphs[gi]
    ins, _ = env.port_info(gi)
    dep = {p.slot for p, key, _, _ in ins if key == "skill:" + skill}
    other = set()
    for n in g.nodes:
        rd = n.reads()
        if any(r in dep for r in rd):
            if n.kind != "SUM":
                other.update(r for r in rd if r not in dep)
            dep.update(n.writes())
    keys = upstream_inputs(env, gi, other)
    keys.discard("skill:" + skill)
    out = [k for k in keys if not (isinstance(k, str) and k.startswith("skill:"))]
    out.sort(key=lambda k: (not (isinstance(k, str) and k.startswith("link:")), str(k)))
    return out


def grid_values(env, gi, key, n=4):
    lo, hi = env.input_domain(gi, key)
    if isinstance(key, str) and key.startswith("link:"):
        return [0.0, 1.0]
    return [lo + (hi - lo) * i / n for i in range(n + 1)]


def skill_effect(env, gi, skill, base, field):
    """Change of an output when the skill is owned: at the base scenario, and the largest / smallest
    change found by sweeping each trigger input alone and every pair of the first ten triggers over
    their curve domains (other inputs at the base scenario).  Returns (delta_base, max, min, triggers)."""
    import itertools
    trig = skill_triggers(env, gi, skill)
    fk = F[field] if field in F else field

    def delta(extra):
        s0 = dict(base)
        s0.update(extra)
        s1 = dict(s0)
        s1["skill:" + skill] = 1.0
        return (env.evaluate(gi, s1).get(fk) or 0.0) - (env.evaluate(gi, s0).get(fk) or 0.0)
    d0 = delta({})
    best, worst = d0, d0
    grids = {k: grid_values(env, gi, k) for k in trig}
    for k in trig:
        for v in grids[k]:
            d = delta({k: v})
            best, worst = max(best, d), min(worst, d)
    for a, b in itertools.combinations(trig[:10], 2):
        for va in grids[a]:
            for vb in grids[b]:
                d = delta({a: va, b: vb})
                best, worst = max(best, d), min(worst, d)
    return d0, best, worst, trig


def input_sensitivity(env, gi, base, field, n=24, skip=()):
    """One-at-a-time sweep of every input over its curve domain: [(name, lo, hi, out_min, out_max, x_min, x_max)]."""
    fk = F[field] if field in F else field
    out = []
    for key, dflt, name in env.input_names(gi):
        if key in skip or (isinstance(key, str) and key.startswith("skill:")):
            continue
        lo, hi = env.input_domain(gi, key)
        if isinstance(key, str) and key.startswith("link:"):
            lo, hi = 0.0, 1.0

        def f(x, key=key):
            s = dict(base)
            s[key] = x
            return env.evaluate(gi, s).get(fk) or 0.0
        mn, mx, xmn, xmx = L.sweep(f, lo, hi, n)
        out.append((name if not isinstance(name, tuple) else str(name), lo, hi, mn, mx, xmn, xmx))
    out.sort(key=lambda r: r[3] - r[4])
    return out


def key_label(env, key):
    if isinstance(key, tuple):
        for alias, v in F.items():
            if v == key:
                return alias
        return "%s+0x%x" % key
    return key


def rating_to_stat(env, stat, rating):
    """DefaultAttributes (graph 23): raw rating (S+0x620..0x63C) -> 0..1 stat (S+0x64C..0x668)."""
    raw = {"serve": 0x620, "return": 0x624, "forehand": 0x628, "backhand": 0x62C, "volley": 0x630,
           "power": 0x634, "speed": 0x638, "stamina": 0x63C}[stat]
    r = env.evaluate(23, {("player", raw): float(rating)})
    return r.get(F[stat], 0.0)


def pro_ratings():
    """{code: {stat: rating}} from data/gameplay/coaches_career.yaml (pro_players; read as text)."""
    path = os.path.join(ROOT, "data", "gameplay", "coaches_career.yaml")
    cols = ["serve", "return", "reflex", "forehand", "backhand", "volley", "power", "speed", "stamina",
            "mental", "overall"]
    out, code, inside = {}, None, False
    for line in open(path):
        if line.startswith("pro_players:"):
            inside = True
            continue
        if inside and line and not line.startswith(" "):
            break
        if not inside:
            continue
        m = re.match(r"\s*- code: (\S+)", line)
        if m:
            code = m.group(1)
        m = re.match(r"\s*ratings: \[([^\]]*)\]", line)
        if m and code:
            out[code] = dict(zip(cols, [int(x) for x in m.group(1).split(",")]))
        m = re.match(r"\s*skills: \[([^\]]*)\]", line)
        if m and code and code in out:
            out[code]["skills"] = [s.strip() for s in m.group(1).split(",") if s.strip()]
    return out


# --------------------------------------------------------------------------- scenarios

# rating levels (rating 30..100; DefaultAttributes maps them to 0..1): the floor, the median and the
# 90th percentile of the 715 rated pros (coaches_career.yaml pro_players), and the cap
LEVELS = ("min", "median", "p90", "max")

# groundstroke rows of the decision tree (shot-to-template.md s3): (label, row, class, charge used)
GROUND = [
    ("Flat Finesse", 2, "FlatFinesse", 0.10), ("Flat Medium", 6, "FlatMedium", 0.50),
    ("Flat Powerful", 10, "FlatPower", 0.85),
    ("TopSpin Finesse", 0, "TopSpinFinesse", 0.10), ("TopSpin Medium", 4, "TopSpinMedium", 0.50),
    ("TopSpin Powerful", 8, "TopSpinPower", 0.85),
    ("Slice Finesse", 1, "SliceFinesse", 0.10), ("Slice Medium", 5, "SliceMedium", 0.50),
    ("Slice Powerful", 9, "SlicePower", 0.85),
]
OTHER = [   # (label, row, class, charge, scenario, hand stat)
    ("Lob Finesse", 3, "Lob", 0.10, "lob", "forehand"), ("Lob Medium", 7, "Lob", 0.50, "lob", "forehand"),
    ("Lob Powerful", 11, "Lob", 0.85, "lob", "forehand"),
    ("Drop shot (Slice+Risk)", 32, "DropShot", 0.50, "drop", "forehand"),
    ("Smash", 33, "Smash", 0.50, "smash", "forehand"),
    ("Volley TopSpin = PowerVolley", 16, "VolleyPower", 0.50, "volley", "volley"),
    ("Volley Flat/Lob = FlatVolley", 19, "VolleyStandard", 0.50, "volley", "volley"),
    ("Volley Slice = SliceVolley", 17, "VolleySlice", 0.50, "volley", "volley"),
    ("Drop volley (Slice+Risk)", 18, "VolleyDrop", 0.50, "volley", "volley"),
    ("Return Flat (any tier)", 10, "ReturnFlatFinesse", 0.85, "return", "return"),
    ("Return TopSpin (any tier)", 8, "ReturnTopSpinFinesse", 0.85, "return", "return"),
    ("Return Slice (any tier)", 9, "ReturnSliceFinesse", 0.85, "return", "return"),
]
SERVES = [  # (label, row, class, hold, timing)
    ("Kick Finesse", 22, "ServeSpinFinesse"), ("Kick Medium", 20, "ServeSpinMedium"),
    ("Kick Powerful", 21, "ServeSpinPowerful"),
    ("Slice Finesse", 25, "ServeSpinFinesse"), ("Slice Medium", 23, "ServeSpinMedium"),
    ("Slice Powerful", 24, "ServeSpinPowerful"),
    ("Flat Finesse", 28, "ServeFlatFinesse"), ("Flat Medium", 26, "ServeFlatMedium"),
    ("Flat Powerful", 27, "ServeFlatPowerful"),
    ("Advanced kick", 29, "AdvancedServe"), ("Advanced slice", 30, "AdvancedServe"),
    ("Advanced flat", 31, "AdvancedServe"),
]
SERVE_HOLD = {"Finesse": 0.05, "Medium": 0.5, "Powerful": 0.9, "Advanced": 0.9}


def serve_tier(label):
    return "Advanced" if label.startswith("Advanced") else label.split()[-1]


class Ctx:
    def __init__(self, inp):
        self.inp = inp
        self.env = GraphEnv(inp)
        self.tpl = Templates(inp)
        self.sd = shotdef_rows()
        self.pros = pro_ratings()
        self.level_rating = {}
        for st in STATS:
            v = sorted(p[st] for p in self.pros.values())
            self.level_rating[st] = {"min": 30, "median": v[len(v) // 2], "p90": v[int(0.9 * len(v))], "max": 100}

    def stats(self, level, override=None):
        d = {st: rating_to_stat(self.env, st, self.level_rating[st][level]) for st in STATS}
        d.update(override or {})
        return d

    def base(self, row, level="median", hand="forehand", charge=0.5, timing=0.0, scen="ground_cc", extra=None):
        st = self.stats(level)
        frm, to = SCEN[scen]
        sd = self.sd.get(row, {})
        b = dict(timing=timing, vigor=1.0, charge=charge, hit_x=float(frm[0]), hit_y=float(frm[1]),
                 hit_z=float(frm[2]), opp_x=1200.0, opp_z=0.0, is_human=1.0,
                 err_min=sd.get("err_min", 0.0), err_max=sd.get("err_max", 1.0),
                 pow_min=sd.get("pow_min", 0.0), pow_max=sd.get("pow_max", 1.0))
        b.update(st)
        b["hand"] = st[hand]
        b.update(extra or {})
        return b

    def pf(self, cls, scen_dict):
        """PowerfulFactor after the class power graph (and graph 198, a clamp to 0..1) and the spin blend."""
        pg = CLASSES[cls][3]
        r = self.env.evaluate(pg, scen_dict)
        pf = r.get(F["charge"] if False else ("player", 0x778), 0.0)
        pf = self.env.evaluate(198, {("player", 0x778): pf}).get(("player", 0x778), pf) if cls in (
            "SliceFinesse", "TopSpinFinesse", "FlatFinesse", "SliceMedium", "TopSpinMedium", "FlatMedium",
            "SlicePower", "TopSpinPower", "FlatPower") else min(max(pf, 0.0), 1.0)
        if ("player", 0x774) in r:      # serve power graphs also write the spin blend
            blend = r[("player", 0x774)]
        else:
            sg = SPIN_GRAPH_TOPSPIN if cls.startswith(("TopSpin", "ReturnTopSpin")) else SPIN_GRAPH_OTHER
            blend = self.env.evaluate(sg, {("player", 0x778): pf}).get(("player", 0x774), 0.0)
        return pf, blend

    def p_error(self, cls, scen_dict):
        _, net, fault, _ = CLASSES[cls]
        p = self.env.evaluate(fault, scen_dict).get(("player", 0x718), 0.0) or 0.0
        n = self.env.evaluate(net, scen_dict).get(("player", 0x720), 0.0) or 0.0
        return min(max(p, 0.0), 1.0), n

    def aim(self, cls, scen_dict):
        ag = CLASSES[cls][0]
        r = self.env.evaluate(ag, scen_dict)
        return r.get(("player", 0xD88)), r.get(("player", 0xD78))

    def aim_mean(self, cls, scen_dict, n=20):
        """Efficiency and DeepDeviation averaged over the uniform Random input (DeviationSystem.Random)."""
        effs, devs = [], []
        for i in range(n):
            s = dict(scen_dict)
            s["random_dev"] = (i + 0.5) / n
            e, d = self.aim(cls, s)
            effs.append(e or 0.0)
            devs.append(d or 0.0)
        return sum(effs) / n, sum(devs) / n, max(devs)


def kmh(x):
    return "-" if x is None else "%.0f (%.0f)" % (x, L.kmh_to_mph(x))


# --------------------------------------------------------------------------- section 1: speeds

def sec_speeds(c):
    out = ["### 1a. Template targets at PowerfulFactor = 1 (the fastest each row can go)", "",
           "Launch, first-bounce (in and out) and receiver-baseline speeds, km/h (mph), spin blend 0.5. "
           "Computed from the model (ball_model.py, ramp curves, a4 = 0.06, net 91.4 cm).", ""]
    rows = []
    for label, idx, cls, ch in GROUND:
        for sc in ("ground_short", "ground_cc", "ground_dtl", "ground_max"):
            d = c.tpl.fly(idx, *SCEN[sc], pf=1.0, blend=0.5)
            rows.append((label, idx, sc, "%.1f" % d["dist_m"], kmh(d["launch_kmh"]), kmh(d["bounce_in_kmh"]),
                         kmh(d["bounce_out_kmh"]), kmh(d["baseline_kmh"]), "%.2f" % d["tau"]))
    for label, idx, cls, ch, sc, hand in OTHER:
        d = c.tpl.fly(idx, *SCEN[sc], pf=1.0, blend=0.5)
        rows.append((label, idx, sc, "%.1f" % d["dist_m"], kmh(d["launch_kmh"]), kmh(d["bounce_in_kmh"]),
                     kmh(d["bounce_out_kmh"]), kmh(d["baseline_kmh"]), "%.2f" % d["tau"]))
    for label, idx, cls in SERVES:
        for sc in ("serve_T", "serve_wide"):
            d = c.tpl.fly(idx, *SCEN[sc], pf=1.0, blend=0.5)
            rows.append(("Serve " + label, idx, sc, "%.1f" % d["dist_m"], kmh(d["launch_kmh"]),
                         kmh(d["bounce_in_kmh"]), kmh(d["bounce_out_kmh"]), kmh(d["baseline_kmh"]),
                         "%.2f" % d["tau"]))
    out.append(L.md_table(["shot", "row", "scenario", "dist m", "launch", "bounce in", "bounce out",
                           "at baseline", "flight s"], rows))

    out += ["", "### 1b. Groundstrokes by stats (perfect timing, fresh, baseline contact at 1.0 m, opponent on the baseline)", "",
            "PowerfulFactor (PF) from the class power graph, spin blend from graph 241/242, flight on scenario "
            "ground_cc. Charge: Finesse 0.10, Medium 0.50, Powerful 0.85 (64 frames held). Forehand stat used as "
            "HandAttributeQuality; a backhand with the same Backhand rating gives the same numbers (same rows and "
            "graphs). Rating levels: " + ", ".join("%s %s" % (lv, "/".join(str(c.level_rating[s][lv]) for s in
                                                                     ("forehand", "power"))) for lv in LEVELS)
            + " (Forehand/Power ratings).", ""]
    rows = []
    for label, idx, cls, ch in GROUND:
        cells = [label]
        for lv in LEVELS:
            b = c.base(idx, lv, charge=ch)
            pf, bl = c.pf(cls, b)
            d = c.tpl.fly(idx, *SCEN["ground_cc"], pf=pf, blend=bl)
            cells.append("PF %.2f: %s / %s" % (pf, kmh(d["launch_kmh"]), kmh(d["baseline_kmh"])))
        rows.append(cells)
    out.append(L.md_table(["shot (launch / at baseline km/h (mph))"] + list(LEVELS), rows))

    out += ["", "### 1c. Other shots by stats (perfect timing)", ""]
    rows = []
    for label, idx, cls, ch, sc, hand in OTHER:
        cells = [label + " [" + sc + "]"]
        for lv in LEVELS:
            b = c.base(idx, lv, hand=hand, charge=ch, scen=sc)
            pf, bl = c.pf(cls, b)
            d = c.tpl.fly(idx, *SCEN[sc], pf=pf, blend=bl)
            cells.append("PF %.2f: %s / %s" % (pf, kmh(d["launch_kmh"]), kmh(d["baseline_kmh"])))
        rows.append(cells)
    out.append(L.md_table(["shot (launch / at baseline)"] + list(LEVELS), rows))

    out += ["", "### 1d. Serves by stats (perfect gauge timing 0, fresh, hold by tier)", "",
            "Serve power graphs 255 (Finesse, Medium), 256 (Powerful), 257 (Advanced) read Serve, Power, the "
            "toss hold fraction (255) or the gauge timing (256/257). Hold fraction: Finesse 0.05, Medium 0.5, "
            "Powerful/Advanced 0.9. Scenario serve_T.", ""]
    rows = []
    for label, idx, cls in SERVES:
        tier = serve_tier(label)
        cells = [label]
        for lv in LEVELS:
            b = c.base(idx, lv, hand="serve", scen="serve_T",
                       extra={"serve_hold": SERVE_HOLD[tier], "serve_timing": 0.0})
            pf, bl = c.pf(cls, b)
            d = c.tpl.fly(idx, *SCEN["serve_T"], pf=pf, blend=bl)
            cells.append("PF %.2f: %s / %s" % (pf, kmh(d["launch_kmh"]), kmh(d["baseline_kmh"])))
        rows.append(cells)
    out.append(L.md_table(["serve (launch / at baseline)"] + list(LEVELS), rows))

    # timing effect on speed
    out += ["", "### 1e. Timing and charge against speed (Flat Powerful / TopSpin Medium, median stats)", ""]
    rows = []
    for t in (-0.6, -0.3, -0.1, 0.0, 0.1, 0.3, 0.6):
        cells = ["%+.1f" % t]
        for label, idx, cls, ch in (GROUND[2], GROUND[4], GROUND[0]):
            b = c.base(idx, "median", charge=ch, timing=t)
            pf, bl = c.pf(cls, b)
            d = c.tpl.fly(idx, *SCEN["ground_cc"], pf=pf, blend=bl)
            cells.append("PF %.2f %s" % (pf, kmh(d["launch_kmh"])))
        rows.append(cells)
    out.append(L.md_table(["timing t", "Flat Powerful", "TopSpin Medium", "Flat Finesse"], rows))
    rows = []
    for ch in (0.7, 0.8, 0.9, 0.99, 1.0):
        b = c.base(10, "median", charge=ch)
        pf, bl = c.pf("FlatPower", b)
        d = c.tpl.fly(10, *SCEN["ground_cc"], pf=pf, blend=bl)
        rows.append(("%.2f (%d frames)" % (ch, round(ch * 75)), "%.3f" % pf, kmh(d["launch_kmh"])))
    out += ["", L.md_table(["Flat Powerful charge", "PF", "launch"], rows)]

    # fastest build search
    out += ["", "### 1f. Fastest shots the retail game can produce", ""]
    out.append(fastest(c))
    return "\n".join(out)


def fastest(c):
    """Search PF over stats = 100, every skill owned, and a grid of the situational inputs the power
    graphs read, for the forehand rows and the serves; then fly the best PF on the longest legal line."""
    import itertools
    skills = ["skill:" + s for s in ("PowerfulShotCounter", "InsideOutMaster", "CrushingPassingShot",
                                     "ApproachShotsExpert", "InstantRocket", "ReachSwingsExpert",
                                     "SemiVolleyKing", "FocusService")]
    rows = []
    best_any = {}
    for label, idx, cls, ch in GROUND[2::3] + [GROUND[1], GROUND[5]]:
        best = (-1, None)
        for t, io, ox, fat, chg, hy in itertools.product((-0.1, 0.0, 0.1), (0.0, 1.0), (300.0, 1200.0),
                                                      (0.0, 1.0), (ch, 1.0), (80.0, 100.0, 120.0)):
            b = c.base(idx, "max", charge=chg, timing=t, extra={"inside_out": io, "opp_x": ox, "hit_y": hy,
                                                                 "link:SwingCategory/Fatality": fat})
            for sk in skills:
                b[sk] = 1.0
            pf, bl = c.pf(cls, b)
            if pf > best[0]:
                best = (pf, (t, io, ox, fat, chg, hy), bl)
        b0 = c.base(idx, "max", charge=ch)
        pf0, bl0 = c.pf(cls, b0)
        d0 = c.tpl.fly(idx, *SCEN["ground_max"], pf=pf0, blend=bl0)
        d = c.tpl.fly(idx, *SCEN["ground_max"], pf=best[0], blend=best[2])
        rows.append((label, "%.3f" % pf0, kmh(d0["launch_kmh"]), "%.3f" % best[0],
                     "t=%+.1f io=%g opp_x=%g fatality=%g charge=%g hit_y=%g" % best[1], kmh(d["launch_kmh"]),
                     kmh(d["bounce_in_kmh"]), kmh(d["baseline_kmh"])))
    for label, idx, cls in SERVES[8::3] + [SERVES[2], SERVES[5]]:
        best = (-1, None)
        for t, hold, tr in itertools.product((-0.2, -0.1, 0.0, 0.1, 0.2), (0.8, 0.9, 1.0), (0.0, 1.0)):
            b = c.base(idx, "max", hand="serve", scen="serve_T",
                       extra={"serve_timing": t, "serve_hold": hold, "trailing": tr})
            for sk in skills:
                b[sk] = 1.0
            pf, bl = c.pf(cls, b)
            if pf > best[0]:
                best = (pf, (t, hold, tr), bl)
        b0 = c.base(idx, "max", hand="serve", scen="serve_T", extra={"serve_timing": 0.0, "serve_hold": 0.9})
        pf0, bl0 = c.pf(cls, b0)
        d0 = c.tpl.fly(idx, *SCEN["serve_T"], pf=pf0, blend=bl0)
        d = c.tpl.fly(idx, *SCEN["serve_T"], pf=best[0], blend=best[2])
        rows.append(("Serve " + label, "%.3f" % pf0, kmh(d0["launch_kmh"]), "%.3f" % best[0],
                     "gauge t=%+.1f hold=%g trailing=%g" % best[1], kmh(d["launch_kmh"]),
                     kmh(d["bounce_in_kmh"]), kmh(d["baseline_kmh"])))
    return L.md_table(["shot", "PF all stats 100", "launch", "best PF (all skills)", "conditions",
                       "launch", "bounce in", "at baseline"], rows)


# --------------------------------------------------------------------------- section 2: trajectory shape

# FlatNormal aiming config, stick straight up (deep), hitter at (-1188, -50): efficiency -> aimed depth (cm)
# (aiming.md s4 worked example, computed with tools/ts4data/aim_tables.py; data/gameplay/aim_tables.yaml)
AIM_DEPTH = [(0.0, 737.0), (0.5, 903.0), (0.8, 1074.0), (1.0, 1188.0)]


def aim_depth(eff):
    pts = AIM_DEPTH
    eff = min(max(eff, 0.0), 1.0)
    for (e0, d0), (e1, d1) in zip(pts, pts[1:]):
        if eff <= e1:
            return d0 + (d1 - d0) * (eff - e0) / (e1 - e0)
    return pts[-1][1]


def landing_depths(c, cls, b, n=12):
    """Deep-aimed In shot: Efficiency and DeepDeviation from the class aiming graph (DeviationSystem.Random
    uniform), FinalEfficiency from graph 196 (AimingState.Random uniform), aimed depth from AIM_DEPTH,
    landing depth = aimed depth - DeepDeviation (clamped to x >= 75).  Returns the sorted depths (cm)."""
    out = []
    for i in range(n):
        s = dict(b)
        s["random_dev"] = (i + 0.5) / n
        eff, dev = c.aim(cls, s)
        for j in range(n):
            s2 = dict(s)
            s2[("player", 0xD88)] = eff or 0.0
            s2[("player", 0xDA4)] = (j + 0.5) / n
            fe = c.env.evaluate(196, s2).get(("player", 0xDA8), 0.0)
            out.append(max(aim_depth(fe) - (dev or 0.0), 75.0))
    out.sort()
    return out


def pct(v, q):
    return v[min(len(v) - 1, int(q * len(v)))]


def sec_shape(c):
    out = ["### 2a. Flight shape by row and landing depth (median stats, perfect timing)", "",
           "Hitter at the baseline (x = -1188, contact 1.0 m), target on the cross-court line at depth x (cm past "
           "the net). PF and spin blend from the class graphs. Net clearance = ball centre above the 91.4 cm tape "
           "(centre height - 0.914 m); bounce height = top of the arc after the first bounce. Computed from the model.", ""]
    rows = []
    for label, idx, cls, ch in GROUND:
        b = c.base(idx, "median", charge=ch)
        pf, bl = c.pf(cls, b)
        for depth in (700, 900, 1100):
            d = c.tpl.fly(idx, (-1188, 100, 150), (depth, 0, -250), pf=pf, blend=bl)
            rows.append((label, "%.2f/%.2f" % (pf, bl), depth, "%.2f" % d["net_clear_m"], "%.2f" % d["apex_m"],
                         "%.1f" % d["in_deg"], "%.1f" % d["out_deg"], "%.2f" % d["bounce_apex_m"],
                         kmh(d["bounce_in_kmh"]), kmh(d["bounce_out_kmh"]),
                         "%.2f" % (d["bounce_out_kmh"] / d["bounce_in_kmh"])))
    out.append(L.md_table(["shot", "PF/blend", "depth cm", "net clear m", "apex m", "in deg", "out deg",
                           "bounce height m", "bounce in", "bounce out", "out/in"], rows))
    out += ["", "Other shots (median stats):", ""]
    rows = []
    for label, idx, cls, ch, sc, hand in OTHER:
        b = c.base(idx, "median", hand=hand, charge=ch, scen=sc)
        pf, bl = c.pf(cls, b)
        d = c.tpl.fly(idx, *SCEN[sc], pf=pf, blend=bl)
        rows.append((label, sc, "%.2f/%.2f" % (pf, bl), "%.2f" % d["net_clear_m"], "%.2f" % d["apex_m"],
                     "%.2f" % d["bounce_apex_m"], kmh(d["bounce_in_kmh"]), kmh(d["bounce_out_kmh"])))
    for label, idx, cls in SERVES[1::3] + SERVES[2::3]:
        b = c.base(idx, "median", hand="serve", scen="serve_T", extra={"serve_hold": SERVE_HOLD[serve_tier(label)]})
        pf, bl = c.pf(cls, b)
        d = c.tpl.fly(idx, *SCEN["serve_T"], pf=pf, blend=bl)
        rows.append(("Serve " + label, "serve_T", "%.2f/%.2f" % (pf, bl), "%.2f" % d["net_clear_m"],
                     "%.2f" % d["apex_m"], "%.2f" % d["bounce_apex_m"], kmh(d["bounce_in_kmh"]),
                     kmh(d["bounce_out_kmh"])))
    out.append(L.md_table(["shot", "scenario", "PF/blend", "net clear m", "apex m", "bounce height m",
                           "bounce in", "bounce out"], rows))

    out += ["", "### 2b. Landing depth of a deep-aimed In groundstroke (cm past the net; baseline = 1188)", "",
            "Distribution over the two uniform random inputs (aiming graph DeviationSystem.Random and graph 196 "
            "AimingState.Random), 144 samples each; aim depth from the FlatNormal config (stick up). Computed from the model.", ""]
    rows = []
    for label, idx, cls, ch in GROUND:
        for lv in ("min", "median", "max"):
            for t in (0.0, 0.3):
                b = c.base(idx, lv, charge=ch, timing=t)
                v = landing_depths(c, cls, b)
                within = sum(1 for x in v if x >= 1188 - 300) / len(v)
                rows.append((label, lv, "%+.1f" % t, "%.0f" % pct(v, 0.1), "%.0f" % pct(v, 0.5),
                             "%.0f" % pct(v, 0.9), "%.0f%%" % (100 * within)))
    out.append(L.md_table(["shot", "stats", "timing", "p10", "median", "p90", "share within 3 m of baseline"], rows))

    out += ["", "### 2c. What the spin parameters do (TopSpin Powerful, Slice Powerful, Flat Powerful; ground_cc, PF 1)", "",
            "spin_a is a constant vertical acceleration (negative = dips); its extra downward pull is "
            "-spin_a / a4 m/s^2 (a4 = 0.06). Same landing point for every blend, so spin changes the launch angle, "
            "apex, net clearance and bounce, not where the ball lands. Computed from the model.", ""]
    rows = []
    for label, idx in (("TopSpin Powerful", 8), ("Flat Powerful", 10), ("Slice Powerful", 9), ("Serve kick", 21),
                       ("Serve slice", 24), ("Serve flat", 27)):
        sc = "serve_T" if label.startswith("Serve") else "ground_cc"
        for bl in (0.0, 0.5, 1.0):
            d = c.tpl.fly(idx, *SCEN[sc], pf=1.0, blend=bl)
            rows.append((label, "%.1f" % bl, "%.3f" % d["spin_a"], "%.2f" % (-d["spin_a"] / 0.06),
                         "%.3f" % d["spin_b"], "%.2f" % d["net_clear_m"], "%.2f" % d["apex_m"],
                         "%.1f" % d["launch_deg"], "%.1f" % d["in_deg"], "%.1f" % d["out_deg"],
                         "%.2f" % (d["bounce_out_kmh"] / d["bounce_in_kmh"]), "%.2f" % d["bounce_apex_m"],
                         "%.2f" % (1 - d["decay"])))
    out.append(L.md_table(["shot", "blend", "spin_a", "extra down m/s2", "spin_b (side)", "net clear m",
                           "apex m", "launch deg", "in deg", "out deg", "speed out/in", "bounce height m",
                           "spin kept"], rows))
    rows = []
    for cls in ("FlatPower", "TopSpinMedium", "SlicePower", "FlatFinesse"):
        sg = SPIN_GRAPH_TOPSPIN if cls.startswith("TopSpin") else SPIN_GRAPH_OTHER
        rows.append([cls] + ["%.2f" % c.env.evaluate(sg, {("player", 0x778): pf}).get(("player", 0x774), 0.0)
                             for pf in (0.0, 0.3, 0.5, 0.7, 0.8, 0.9, 1.0)])
    out += ["", "Spin blend as a function of PowerfulFactor (graphs 241 / 242):", "",
            L.md_table(["class", "PF 0", "0.3", "0.5", "0.7", "0.8", "0.9", "1.0"], rows)]
    return "\n".join(out)


# --------------------------------------------------------------------------- section 3: timing

# inputs that the gameplay notes found constant or never written in retail (OPEN 1.10, graphs-decoded s6.9,
# timing-and-fatigue s1, OPEN 1.10 for S+0xD84)
INERT = {
    ("player", 0x770): "never written (OPEN 1.10): stays 0 -> fast-ball and wood ramps inert",
    ("player", 0x768): "never written (OPEN 1.10): stays 0",
    ("player", 0x7D8): "never written (OPEN 1.10): stays 1000 -> every half-volley term sits at its x=1000 end",
    ("player", 0xD84): "set to 0.0 by fn_886612E0 and nothing else (OPEN 1.10)",
    ("player", 0x558): "ShotContext.#ff9a119d: no writer documented (State image 0)",
    ("player", 0x550): "ShotContext.#f089f55c: AI serve fault value; a human reads the (IsHuman) branch",
    ("team", 0x50): "TeamState.IncomingBall.IsB: writer not documented",
    ("player", 0x7CC): "SlowDown: writer not documented in the notes",
}


def invert_timing(curve, t):
    """Frames-to-ball f at which the timing curve gives t (curves fall monotonically from +1 at 10 f)."""
    lo, hi = 0.0, 60.0
    for _ in range(60):
        mid = 0.5 * (lo + hi)
        if L.ramp_eval(curve, mid) > t:
            lo = mid
        else:
            hi = mid
    return 0.5 * (lo + hi)


def sec_timing(c):
    tc = timing_curves()
    base_c = tc["/SwingTimingSelectionList/Baseline/5ae85f27/848c2a13"]
    vol_c = tc["/SwingTimingSelectionList/Volley/5ae85f27/848c2a13"]
    srv_c = tc["/SwingTimingSelectionList/Serve/Animation[0]/Timing"]
    same = (tc["/SwingTimingSelectionList/Baseline/5ae85f27/848c2a13"] ==
            tc["/SwingTimingSelectionList/Baseline/5ae85f27/BestAbility"] and
            tc["/SwingTimingSelectionList/Volley/5ae85f27/848c2a13"] ==
            tc["/SwingTimingSelectionList/Volley/5ae85f27/BestAbility"])
    out = ["### 3a. Timing value against frames from commit (release) to ball arrival", "",
           "Read from data (02_PlayerSettings.yaml SwingTimingSelectionList; serve: Animation[0] = default serve "
           "animation 2ce33943, the other 14 serve animations are shifted by 0..12 frames). Worst-ability and "
           "best-ability curves identical: %s (so stats do not change the window)." % same, ""]
    rows = []
    for t in (1.0, 0.6, 0.45, 0.3, 0.1, 0.0, -0.1, -0.3, -0.45, -0.6, -1.0):
        fb, fv, fs = (invert_timing(cv, t) for cv in (base_c, vol_c, srv_c))
        rows.append(("%+.2f" % t, "%.1f f = %.0f ms" % (fb, L.frames_to_ms(fb)),
                     "%.1f f = %.0f ms" % (fv, L.frames_to_ms(fv)), "%.1f f = %.0f ms" % (fs, L.frames_to_ms(fs))))
    out.append(L.md_table(["t (+ late)", "groundstroke / return", "volley", "serve (release before contact)"], rows))
    out += ["", "Window widths (frames between the two t values, both sides):", ""]
    rows = []
    for w in (0.1, 0.3, 0.6):
        rows.append(("|t| < %.1f" % w,) + tuple(
            "%.1f f = %.0f ms" % (invert_timing(cv, -w) - invert_timing(cv, w),
                                  L.frames_to_ms(invert_timing(cv, -w) - invert_timing(cv, w)))
            for cv in (base_c, vol_c, srv_c)))
    out.append(L.md_table(["window", "groundstroke", "volley", "serve"], rows))

    out += ["", "### 3b. What timing gives and costs (median stats, fresh, baseline contact 1.0 m, no skills)", "",
            "P(error) = clamp01(FaultProbability) of the class fault graph; PF -> launch speed on ground_cc; "
            "aim efficiency = class aiming graph Efficiency averaged over its Random input, DeepDeviation mean. "
            "Computed from the model.", ""]
    rows = []
    for t in (-1.0, -0.6, -0.45, -0.3, -0.1, 0.0, 0.1, 0.3, 0.45, 0.6, 1.0):
        cells = ["%+.2f" % t, "%.0f" % invert_timing(base_c, t)]
        for label, idx, cls, ch in (GROUND[2], GROUND[4], GROUND[6]):
            b = c.base(idx, "median", charge=ch, timing=t)
            p, n = c.p_error(cls, b)
            pf, bl = c.pf(cls, b)
            d = c.tpl.fly(idx, *SCEN["ground_cc"], pf=pf, blend=bl)
            e, dev, _ = c.aim_mean(cls, b)
            cells.append("err %.2f, %.0f km/h, eff %.2f, dev %.0f" % (p, d["launch_kmh"], e, dev))
        for cls, idx, sc, hand in (("VolleyStandard", 19, "volley", "volley"), ("DropShot", 32, "drop", "forehand")):
            b = c.base(idx, "median", hand=hand, charge=0.5, timing=t, scen=sc)
            p, n = c.p_error(cls, b)
            cells.append("err %.2f" % p)
        rows.append(cells)
    out.append(L.md_table(["t", "frames", "Flat Powerful", "TopSpin Medium", "Slice Finesse", "Volley std",
                           "Drop shot"], rows))

    out += ["", "### 3c. Error against timing for every reachable class (median stats; P(error) at t)", ""]
    rows = []
    allc = [(g[2], g[1], g[3], "ground_cc", "forehand") for g in GROUND] + \
           [(o[2], o[1], o[3], o[4], o[5]) for o in OTHER]
    ts = (-1.0, -0.6, -0.45, -0.3, 0.0, 0.3, 0.45, 0.6, 1.0)
    for cls, idx, ch, sc, hand in allc:
        cells = ["%s (row %d)" % (cls, idx)]
        for t in ts:
            b = c.base(idx, "median", hand=hand, charge=ch, timing=t, scen=sc)
            cells.append("%.2f" % c.p_error(cls, b)[0])
        rows.append(cells)
    out.append(L.md_table(["class"] + ["%+.2f" % t for t in ts], rows))

    out += ["", "### 3d. Every input of the timing, fault and net graphs, and its retail status", ""]
    keys = {}
    for cls, (ag, ng, fg, pg) in CLASSES.items():
        for gi in (ng, fg):
            for key, dflt, name in c.env.input_names(gi):
                keys.setdefault(key, [name, set()])[1].add(gi)
    for gi in (41, 42, 40, 178):
        for key, dflt, name in c.env.input_names(gi):
            keys.setdefault(key, [name, set()])[1].add(gi)
    rows = []
    for key, (name, gs) in sorted(keys.items(), key=lambda kv: str(kv[0])):
        status = INERT.get(key, "live" if not (isinstance(key, str) and key.startswith("skill:")) else "skill (0/1)")
        rows.append((name if isinstance(name, str) else str(name), len(gs), status))
    out.append(L.md_table(["input", "graphs reading it", "status in retail"], rows))
    out.append("\nTimingAbility (graphs 40-42) is computed but has no effect: the worst/best timing curves "
               "are identical (read from data above). S+0x564, the additive error term, is always 0 "
               "(graphs-decoded s6.9).")
    return "\n".join(out)


# --------------------------------------------------------------------------- section 4: situation sensitivity

SITU = [   # (situation, field or key, good value, bad value, note)
    ("time available (frames from opponent's hit to contact, S+0xCF0)", "frames_to_contact", 80.0, 30.0, ""),
    ("depth to cover (TimingState #d2797eb6, S+0xCF4, cm, I)", "depth_diff", 50.0, 350.0, ""),
    ("run distance to the hit point (#03d2be3d, cm)", "run_dist", 0.0, 600.0, ""),
    ("required run speed (#5cf9de02, m/s)", "run_speed", 0.0, 6.0, ""),
    ("run far and fast together", ("run_dist", "run_speed"), (0.0, 0.0), (600.0, 6.0), ""),
    ("stretch: reach-swing qualifier (SwingCategory #0698037d)", "link:SwingCategory/#0698037d", 0.0, 1.0, ""),
    ("contact height low (cm)", "hit_y", 100.0, 40.0, ""),
    ("contact height high (cm)", "hit_y", 100.0, 170.0, ""),
    ("incoming pace (#1407106c, km/h; INERT in retail)", "ballspeed770", 0.0, 70.0, "would-be effect only"),
    ("half-volley (#693eedbe frames since bounce; INERT, stays 1000)", "since_bounce", 1000.0, 5.0, "would-be effect only"),
    ("court position: 3 m behind the baseline", "hit_x", -1188.0, -1500.0, ""),
    ("court position: inside the court (6 m from net)", "hit_x", -1188.0, -600.0, ""),
    ("opponent at the net (LocalOpponentPosition x)", "opp_x", 1200.0, 300.0, ""),
    ("fatigue (CurrentVigor)", "vigor", 1.0, 0.2, ""),
    ("pressure: trailing in the game (#689dc6f2), no skill", "trailing", 0.0, 1.0, ""),
    ("rally length (#8beb922e strokes), no skill", "rally", 0.0, 25.0, ""),
    ("full charge (0.85 -> 1.0)", "charge", 0.85, 1.0, ""),
    ("hand stat (rating 100 -> 30)", "hand", 1.0, 0.0, ""),
]
SITU_CLASSES = [("Flat Powerful", 10, "FlatPower", 0.85, "ground_cc", "forehand"),
                ("TopSpin Medium", 4, "TopSpinMedium", 0.5, "ground_cc", "forehand"),
                ("Slice Finesse", 1, "SliceFinesse", 0.1, "ground_cc", "forehand"),
                ("Return Flat", 10, "ReturnFlatFinesse", 0.85, "return", "return"),
                ("Volley std", 19, "VolleyStandard", 0.5, "volley", "volley"),
                ("Power volley", 16, "VolleyPower", 0.5, "volley", "volley")]


def _apply(b, key, val):
    if isinstance(key, tuple) and isinstance(key[0], str) and key[0] in F:
        for k, v in zip(key, val):
            b[k] = v
    else:
        b[key] = val


def metrics(c, cls, idx, sc, b):
    out = {}
    for t in (0.45, 0.8, -0.6):
        bb = dict(b)
        bb["timing"] = t
        out["err%+.2f" % t] = c.p_error(cls, bb)[0]
    pf, bl = c.pf(cls, b)
    d = c.tpl.fly(idx, *SCEN[sc], pf=pf, blend=bl)
    out["kmh"] = d["launch_kmh"]
    e, dev, _ = c.aim_mean(cls, b, n=10)
    out["eff"], out["dev"] = e, dev
    return out


def sec_situ(c):
    out = ["### 4a. Effect of each situation (good value -> bad value; median stats, fresh, other inputs at the "
           "baseline scenario)", "",
           "Each cell: change in P(error) at t = +0.45 (late, 13 frames) / at t = +0.8 (very late, 11 frames) / at t = -0.6 (early, 32 frames); "
           "at t = 0 (perfect) every change is 0 for every class and situation; "
           "change in launch speed (km/h); change in mean aim efficiency; change in mean DeepDeviation (cm, + = "
           "lands shorter). '0' everywhere = the graphs of that class do not read the input. Computed from the model.", ""]
    rows = []
    for name, key, good, bad, note in SITU:
        cells = [name]
        for label, idx, cls, ch, sc, hand in SITU_CLASSES:
            b = c.base(idx, "median", hand=hand, charge=ch, scen=sc)
            bg, bb = dict(b), dict(b)
            _apply(bg, key, good)
            _apply(bb, key, bad)
            mg, mb = metrics(c, cls, idx, sc, bg), metrics(c, cls, idx, sc, bb)
            d = {k: mb[k] - mg[k] for k in mg}
            if all(abs(v) < 5e-3 for v in d.values()):
                cells.append("0")
            else:
                cells.append("err %+.2f/%+.2f/%+.2f; %+.0f km/h; eff %+.2f; dev %+.0f" % (
                    d["err+0.45"], d["err+0.80"], d["err-0.60"], d["kmh"], d["eff"], d["dev"]))
        rows.append(cells)
    out.append(L.md_table(["situation"] + [s[0] for s in SITU_CLASSES], rows))

    out += ["", "### 4b. Which shot graphs read each situational input at all (count over the 33 classes' "
            "fault / net / power / aiming graphs, live copies)", ""]
    sets = {"fault/net": set(), "power": set(), "aiming": set()}
    for cls, (ag, ng, fg, pg) in CLASSES.items():
        sets["fault/net"].update((ng, fg))
        sets["power"].add(pg)
        sets["aiming"].add(ag)
    rows = []
    for name, key, good, bad, note in SITU:
        keys = key if (isinstance(key, tuple) and isinstance(key[0], str) and key[0] in F) else (key,)
        kk = {F[k] if k in F else k for k in keys}
        cells = [name]
        for grp, gs in sets.items():
            n = sum(1 for gi in gs if any(k2 in kk for k2, _, _ in c.env.input_names(gi)))
            cells.append("%d / %d" % (n, len(gs)))
        rows.append(cells)
    out.append(L.md_table(["situation", "fault/net graphs", "power graphs", "aiming graphs"], rows))
    return "\n".join(out)


# --------------------------------------------------------------------------- section 5: stats and skills

LIVE_MISC = {9: "AimingState ProfileFactor (serve x vigor)", 10: "FatigueIngame (point cost)",
             12: "VigorMax / capacity", 13: "FatigueConst", 14: "Vivacity (transition speed)", 16: "IsTired",
             17: "SwingSpeedCoef", 18: "RushSpeedCoef (run animation speed)", 22: "ServePrecision/ServePower",
             38: "InputFiltering", 40: "TimingAbility (inert)", 41: "BaselineTimingAbility (inert)",
             42: "VolleyTimingAbility (inert)", 178: "GoodTiming"}
OUT_NAMES = {("player", 0x778): "PowerfulFactor", ("player", 0x718): "FaultProbability",
             ("player", 0x720): "OutcomeNet", ("player", 0xD88): "AimEfficiency",
             ("player", 0xD78): "DeepDeviation cm", ("player", 0xD8C): "OutEfficiency",
             ("player", 0x774): "SpinBlend"}


def class_of_graph():
    m = {}
    for cls, gs in CLASSES.items():
        for gi in gs:
            m.setdefault(gi, cls)
    return m


def class_base(c, cls, level="median", timing=0.0):
    for label, idx, cl, ch in GROUND:
        if cl == cls:
            return c.base(idx, level, charge=ch, timing=timing), idx
    for label, idx, cl, ch, sc, hand in OTHER:
        if cl == cls:
            return c.base(idx, level, hand=hand, charge=ch, scen=sc, timing=timing), idx
    for label, idx, cl in SERVES:
        if cl == cls:
            return c.base(idx, level, hand="serve", scen="serve_T",
                          extra={"serve_hold": SERVE_HOLD[serve_tier(label)], "serve_timing": timing}), idx
    for prefix, row in (("ReturnFlat", 10), ("ReturnTopSpin", 8), ("ReturnSlice", 9)):
        if cls.startswith(prefix):
            return c.base(row, level, hand="return", charge=0.85, scen="return", timing=timing), row
    return c.base(10, level, charge=0.5, timing=timing), 10


def sec_stats(c):
    env = c.env
    out = ["### 5a. Rating -> stat (graph 23 DefaultAttributes) and the flat ranges", "",
           "Read from data / evaluated with the analyser kernels. Ratings below 30 give 0 (flat).", ""]
    rows = []
    for st in STATS:
        f = lambda r, st=st: rating_to_stat(env, st, r)
        kn = L.knees(f, 30, 100, n=140)
        rows.append((st, " ".join("%d:%.2f" % (r, f(r)) for r in (30, 40, 50, 60, 70, 80, 90, 100)),
                     ", ".join("%.0f" % k for k in kn)))
    out.append(L.md_table(["stat", "rating:stat", "knees (rating)"], rows))

    out += ["", "### 5b. Every live consumer of each stat: output range over stat 0 -> 1 and the dead rating ranges", "",
            "One-at-a-time sweep of the stat (others at the class's median-stat baseline, perfect timing unless "
            "noted; fault graphs at t = +0.8 so the timing penalty is visible). 'flat ratings' = rating spans "
            "(30..100) over which the output does not move. Computed from the model.", ""]
    cog = class_of_graph()
    stat_keys = {F[st]: st for st in STATS}
    stat_keys[F["hand"]] = "hand (FH/BH/Return/Volley by stroke)"
    rows = []
    graphs = sorted(set(cog) | set(LIVE_MISC))
    for gi in graphs:
        cls = cog.get(gi)
        is_fault = cls is not None and CLASSES[cls][2] == gi
        b, _ = class_base(c, cls, timing=0.8 if is_fault else 0.0) if cls else (dict(vigor=1.0), 0)
        if not cls:
            b.update(c.stats("median"))
        ins = {k for k, _, _ in env.input_names(gi)}
        _, outs = env.port_info(gi)
        for sk, stname in stat_keys.items():
            if sk not in ins:
                continue
            for _, ok in outs:
                if not isinstance(ok, tuple) or ok[1] < 0x100:
                    continue

                def f(x, sk=sk, ok=ok):
                    s = dict(b)
                    s[sk] = x
                    return env.evaluate(gi, s).get(ok) or 0.0
                mn, mx, _, _ = L.sweep(f, 0.0, 1.0, 40)
                if mx - mn < 1e-4:
                    rows.append((gi, cls or LIVE_MISC.get(gi), stname, OUT_NAMES.get(ok, "%s+0x%x" % ok),
                                 "%.3f" % f(0.0), "%.3f" % f(1.0), "no effect", "30-100"))
                    continue
                st = stname if stname in STATS else {"Return": "return"}.get(cls[:6], None) if cls else None
                if st is None:
                    st = "volley" if cls and cls.startswith("Volley") else ("return" if cls and cls.startswith("Return")
                                                                         else "forehand")
                g = lambda r, f=f, st=st: f(rating_to_stat(env, st, r))
                spans = [sp for sp in L.flat_spans(g, 30, 100, n=140, tol=1e-5) if sp[1] - sp[0] >= 5]
                rows.append((gi, cls or LIVE_MISC.get(gi), stname, OUT_NAMES.get(ok, "%s+0x%x" % ok),
                             "%.3f" % f(0.0), "%.3f" % f(1.0), "%.3f" % (mx - mn),
                             ", ".join("%.0f-%.0f" % (a, bb) for a, bb, _ in sorted(spans)) or "none"))
    out.append(L.md_table(["graph", "class / role", "stat", "output", "at stat 0", "at stat 1", "range",
                           "flat ratings"], rows))
    return "\n".join(out)


def sec_skills(c):
    env = c.env
    cog = class_of_graph()
    out = ["### 5c. Every skill: measured effect on each consumer graph", "",
           "delta = output with the skill minus without; 'base' at the class's median-stat baseline (perfect "
           "timing, fresh, no pressure), 'max'/'min' = the largest / smallest delta over a grid of the skill's "
           "trigger inputs (each alone and in pairs over their curve domains, including timing). PF deltas: "
           "1 PF point is about 75-80 km/h of launch speed on Flat Powerful (section 1e). Computed from the model.", ""]
    rows = []
    allsk = sorted({k[6:] for gi in range(len(env.graphs)) for k, _, _ in env.input_names(gi)
                    if isinstance(k, str) and k.startswith("skill:")})
    for sk in allsk:
        for gi in range(len(env.graphs)):
            if ("skill:" + sk) not in {k for k, _, _ in env.input_names(gi)}:
                continue
            cls = cog.get(gi)
            if cls is None and gi not in LIVE_MISC:
                continue
            b, _ = class_base(c, cls) if cls else (dict(vigor=1.0, **c.stats("median")), 0)
            _, outs = env.port_info(gi)
            for _, ok in outs:
                if not isinstance(ok, tuple) or ok[1] < 0x100 or ok not in OUT_NAMES and gi not in LIVE_MISC:
                    continue
                d0, mx, mn, trig = skill_effect(env, gi, sk, b, ok)
                if max(abs(d0), abs(mx), abs(mn)) < 1e-4:
                    eff = "none found"
                else:
                    eff = "base %+.3f, max %+.3f, min %+.3f" % (d0, mx, mn)
                rows.append((sk, gi, cls or LIVE_MISC.get(gi), OUT_NAMES.get(ok, "%s+0x%x" % ok), eff,
                             ", ".join(key_label(env, k) for k in trig[:6])))
    if not FULL_SKILLS:
        agg = {}
        for sk, gi, cls, oname, eff, trig in rows:
            a = agg.setdefault((sk, oname), {"n": 0, "live": [], "base": 0.0, "max": 0.0, "min": 0.0, "trig": set()})
            a["n"] += 1
            if eff != "none found":
                d0, mx, mn = [float(x.split()[1]) for x in eff.split(", ")]
                a["live"].append(str(cls))
                a["base"] = max(a["base"], d0, key=abs)
                a["max"], a["min"] = max(a["max"], mx), min(a["min"], mn)
                a["trig"].update(t for t in trig.split(", ") if t)
        rows = []
        for (sk, oname), a in sorted(agg.items()):
            live = sorted(set(a["live"]))
            rows.append((sk, oname, "%d/%d" % (len(a["live"]), a["n"]),
                         "none found" if not live else "%+.3f / %+.3f / %+.3f" % (a["base"], a["max"], a["min"]),
                         ", ".join(live[:6]) + (" ..." if len(live) > 6 else ""),
                         ", ".join(sorted(a["trig"]))[:90]))
        out.append(L.md_table(["skill", "output", "graphs live/read", "base / max / min delta",
                               "classes where live", "trigger inputs"], rows))
        out.append("\n(Per-graph rows: `--full-skills`.)")
    else:
        out.append(L.md_table(["skill", "graph", "class", "output", "delta", "triggers searched"], rows))
    out += ["", "Skills that act in code, not in graphs: PoisonedSlices (sets the receiver's #aee2d90b "
            "S+0x7D0 = 1 for the owner's slices; its effect is the 'poisoned' input row below), InstantRocket "
            "(charge curve: S+0xE00 curve identical in retail, only the unused S+0xE08 changes), "
            "SpectacularVolleys (clip family flag S+0x388) (traits-and-skills s2).", ""]
    rows = []
    for label, idx, cls, ch, sc, hand in SITU_CLASSES[:4]:
        b = c.base(idx, "median", hand=hand, charge=ch, scen=sc)
        for t in (0.0, 0.45):
            b0, b1 = dict(b, timing=t), dict(b, timing=t, poisoned=1.0, hit_y=40.0)
            b0["hit_y"] = 40.0
            e0, e1 = c.p_error(cls, b0)[0], c.p_error(cls, b1)[0]
            a0, a1 = c.aim_mean(cls, b0, 10)[0], c.aim_mean(cls, b1, 10)[0]
            rows.append((label, "%+.2f" % t, "%.2f -> %.2f" % (e0, e1), "%.2f -> %.2f" % (a0, a1)))
    out.append("PoisonedSlices on the receiver (low ball, contact 40 cm):\n\n" +
               L.md_table(["receiver class", "timing", "P(error)", "aim efficiency"], rows))
    return "\n".join(out)


# --------------------------------------------------------------------------- section 6: serve and return

def window(f, lo=-2.0, hi=2.0, n=400, ok=lambda v: v < 0.5):
    """Largest contiguous x-interval containing the best point where ok(f(x)).  Returns (a, b) or None."""
    xs = [lo + (hi - lo) * i / n for i in range(n + 1)]
    good = [ok(f(x)) for x in xs]
    best, cur = None, None
    for x, g in zip(xs, good):
        if g:
            cur = (cur[0], x) if cur else (x, x)
            if best is None or cur[1] - cur[0] > best[1] - best[0]:
                best = cur
        else:
            cur = None
    return best


def serve_base(c, label, level="median", vigor=1.0, timing=0.0, target=600.0):
    idx = dict((l, i) for l, i, _ in SERVES)[label]
    b = c.base(idx, level, hand="serve", scen="serve_T",
               extra={"serve_hold": SERVE_HOLD[serve_tier(label)], "serve_timing": timing,
                      "vigor": vigor, "serve_target": target})
    return b, idx


def sec_serve(c):
    env = c.env
    tag = "TU1" if c.inp.tu else "disc"
    out = ["### 6a. Human serve faults (%s): the no-fault gauge window" % tag, "",
           "Serve fault graphs 307 (Finesse), 308 (Medium), 309 (Powerful), 311 (Advanced) are a step for a "
           "human server (graphs-decoded s11.2 item 6): fault = 0 or 1, no roll. The table gives the gauge-timing "
           "interval (S+0x66C, the serve 'timing' value) with fault = 0, by Serve rating and vigor. "
           "#3c6beee9 (S+0xD84) is 0 (its writer is not found). Computed from the model.", ""]
    rows = []
    for label in ("Flat Finesse", "Flat Medium", "Flat Powerful", "Advanced flat"):
        cls = dict((l, k) for l, _, k in SERVES)[label]
        fg = CLASSES[cls][2]
        for lv in ("min", "median", "p90", "max"):
            cells = []
            for vig in (1.0, 0.8, 0.5, 0.2):
                b, _ = serve_base(c, label, lv, vig)

                def f(t, b=b):
                    s = dict(b)
                    s[F["serve_timing"]] = t
                    return env.evaluate(fg, s).get(("player", 0x718), 0.0) or 0.0
                w = window(f)
                cells.append("never" if w is None else ("always" if w[0] <= -2 and w[1] >= 2 else
                                                        "%+.2f..%+.2f" % w))
            rows.append((label, fg, "%s (%d)" % (lv, c.level_rating["serve"][lv])) + tuple(cells))
    out.append(L.md_table(["serve", "graph", "Serve rating", "vigor 1.0", "0.8", "0.5", "0.2"], rows))
    # Target threshold
    b, _ = serve_base(c, "Flat Powerful")

    def ft(x):
        s = dict(b)
        s[F["serve_target"]] = x
        return env.evaluate(CLASSES["ServeFlatPowerful"][2], s).get(("player", 0x718), 0.0) or 0.0
    w = window(ft, 0, 1500, 300)
    out += ["", "Target (S+0x840) no-fault interval at perfect gauge, median server: %s cm (outside it the "
            "serve faults whatever the timing). Its writer and meaning are not traced (marked unknown)." %
            ("%.0f..%.0f" % w if w else "none"), ""]
    # gauge timing -> window frames: serve timing curve
    out += ["Gauge-timing to frames: section 3a gives the serve timing curve (|t| < 0.3 = 13.5 frames). "
            "The AI's fault is ShotContext #f089f55c (S+0x550) directly, set in code (not measured here).", ""]

    out += ["### 6b. Serve speed and spin blend against Serve, Power, gauge timing and vigor (%s)" % tag, "",
            "PowerfulFactor from graphs 255/256/257 (they also write the spin blend). Launch km/h from the "
            "serve template at that PF (serve_T). Vigor is not an input of the serve power graphs; "
            "#689dc6f2 (S+0xF88, 'trailing') and #ff9a119d (S+0x558) are. Computed from the model.", ""]
    rows = []
    for label in ("Flat Powerful", "Kick Powerful", "Advanced flat", "Flat Medium"):
        cls = dict((l, k) for l, _, k in SERVES)[label]
        for lv in ("min", "median", "p90", "max"):
            cells = []
            for t in (0.0, 0.3, 0.6, -0.3):
                b, idx = serve_base(c, label, lv, timing=t)
                pf, bl = c.pf(cls, b)
                d = c.tpl.fly(idx, *SCEN["serve_T"], pf=pf, blend=bl)
                cells.append("%.2f %s" % (pf, kmh(d["launch_kmh"])))
            rows.append((label, lv) + tuple(cells))
    out.append(L.md_table(["serve", "stats", "t=0: PF, launch", "t=+0.3", "t=+0.6", "t=-0.3"], rows))
    for key in ("trailing", "ff9a119d"):
        b, idx = serve_base(c, "Flat Powerful")
        vals = []
        for x in (0.0, 0.5, 1.0):
            s = dict(b)
            s[F[key]] = x
            vals.append("%.2f" % c.pf("ServeFlatPowerful", s)[0])
        out.append("\nFlat Powerful PF with %s (S+0x%X) = 0 / 0.5 / 1: %s" % (key, F[key][1], " / ".join(vals)))

    out += ["", "### 6c. Serve placement: aim efficiency against the aiming value #3c6beee9 (%s)" % tag, "",
            "Aiming graphs 215-221: Efficiency = curve8/9(#3c6beee9 (S+0xD84) + a random term), blended by Serve; "
            "for a serve FinalEfficiency = Efficiency = QuadEfficiency (aiming.md s4), so 0 = the inner quad and "
            "1 = the lines quad. The same #3c6beee9 enters the human fault step (fault when it pushes the sum "
            "past 0.5). Its writer is not found (graphs-decoded s11.2), so its in-game range is UNKNOWN; at the "
            "State.bin default 0 every serve has efficiency about 0. Cells: mean efficiency over the random roll "
            "/ fault at perfect gauge (F = fault). Computed from the model.", ""]
    rows = []
    fault_of = lambda cls, b: (c.env.evaluate(CLASSES[cls][2], b).get(("player", 0x718), 0.0) or 0.0) >= 0.5
    for label in ("Flat Medium", "Flat Powerful", "Kick Powerful", "Advanced flat"):
        cls = dict((l, k) for l, _, k in SERVES)[label]
        for lv in ("min", "max"):
            for vig in (1.0, 0.5):
                cells = []
                for av in (0.3, 0.4, 0.45, 0.5, 0.55):
                    bb, _ = serve_base(c, label, lv, vig)
                    bb["aim3c6b"] = av
                    e, dm, dx = c.aim_mean(cls, bb)
                    cells.append("%.2f%s" % (e, " F" if fault_of(cls, bb) else ""))
                rows.append((label, CLASSES[cls][0], lv, vig) + tuple(cells))
    out.append(L.md_table(["serve", "graph", "stats", "vigor", "#3c6beee9=0.30", "0.40", "0.45", "0.50", "0.55"],
                          rows))

    out += ["", "### 6d. The returner (%s)" % tag, "",
            "All returns use the Return*Finesse rows (template bc29d202) whatever the tier; the ReturnPower "
            "graphs 261-263 are never selected (section 1). Incoming pace #1407106c (S+0x770) is never written, "
            "so a 200 km/h serve and a 120 km/h serve are returned with the same error. Live inputs are frames to "
            "contact S+0xCF0 and depth difference S+0xCF4. P(error) at median Return, t = +0.45 / +0.8:", ""]
    rows = []
    for cls, row in (("ReturnFlatFinesse", 10), ("ReturnTopSpinFinesse", 8), ("ReturnSliceFinesse", 9)):
        for ftc in (10, 45):
            for dd in (0, 200):
                cells = []
                for t in (0.45, 0.8):
                    b = c.base(row, "median", hand="return", charge=0.85, scen="return", timing=t,
                               extra={"frames_to_contact": float(ftc), "depth_diff": float(dd)})
                    cells.append("%.2f" % c.p_error(cls, b)[0])
                rows.append((cls, ftc, dd) + tuple(cells))
    out.append(L.md_table(["class", "frames to contact", "depth diff cm", "P(err) t=+0.45", "t=+0.8"], rows))
    b = c.base(10, "median", hand="return", charge=0.85, scen="return")
    pf, bl = c.pf("ReturnFlatFinesse", b)
    d = c.tpl.fly(10, *SCEN["return"], pf=pf, blend=bl)
    out.append("\nReturn Flat at median stats: PF %.2f, launch %s, at the server's baseline %s." % (
        pf, kmh(d["launch_kmh"]), kmh(d["baseline_kmh"])))
    return "\n".join(out)


# --------------------------------------------------------------------------- section 7: net play

RECEIVER_FIELDS = [
    (("player", 0xC24), "#2c63ee31 frames to the chosen hit sample (C24)"),
    (("player", 0xC28), "#8760acf5 distance to the hit point, cm (C28)"),
    (("player", 0xC2C), "#420a6cfc required run speed, m/s (C2C)"),
    (("player", 0xC30), "BallDifficulty (C30)"),
    (("player", 0xC34), "ShotDifficulty copy (C34)"),
    (("player", 0xC38), "#2f6930a4 mirrored hit-point coordinate, height? (C38)"),
    (("player", 0xC3C), "Spin (C3C)"),
    (("player", 0xC40), "frames as float (C40)"),
    (("player", 0x7A0), "#03d2be3d distance to the ball sample, m (S+0x7A0)"),
    (("player", 0x7A4), "#5cf9de02 required speed, m/s (S+0x7A4)"),
    (("player", 0x764), "BallDifficulty (S+0x764)"),
    (("player", 0x7A8), "ShotDifficulty (S+0x7A8)"),
    (("player", 0xCF0), "TimingState #3fe3a099 frames to contact (S+0xCF0)"),
    (("player", 0xCF4), "TimingState #d2797eb6 depth difference (S+0xCF4)"),
    (("ball", 0x344), "contact height, ball From.y (Ball+0x344)"),
    (("player", 0x910), "LocalOpponentPosition.x (S+0x910)"),
    (("player", 0x7D8), "#693eedbe frames since bounce (S+0x7D8, stays 1000)"),
    (("player", 0x770), "#1407106c incoming pace (S+0x770, never written)"),
]
REACHABLE = {"FlatFinesse", "TopSpinFinesse", "SliceFinesse", "FlatMedium", "TopSpinMedium", "SliceMedium",
             "FlatPower", "TopSpinPower", "SlicePower", "VolleyStandard", "VolleyPower", "VolleySlice",
             "VolleyDrop", "DropShot", "Lob", "Smash", "ReturnFlatFinesse", "ReturnTopSpinFinesse",
             "ReturnSliceFinesse", "ServeFlatFinesse", "ServeSpinFinesse", "ServeFlatMedium", "ServeSpinMedium",
             "ServeFlatPowerful", "ServeSpinPowerful", "AdvancedServe"}


def sec_net(c):
    env = c.env
    cog = class_of_graph()
    role = {}
    for cls, gs in CLASSES.items():
        for r, gi in zip(("aim", "net", "fault", "power"), gs):
            role.setdefault(gi, set()).add((cls, r))
    out = ["### 7a. Which graphs read the reaction-time and ball-at-the-feet inputs", "",
           "Every analyser graph scanned for each input (bound by the State.bin layout). 'reachable' = the "
           "graph belongs to a shot class that a shipped row can select (Risk classes, Defensive and the "
           "ReturnPower graphs are not). Read from data.", ""]
    rows = []
    for key, label in RECEIVER_FIELDS:
        readers = [gi for gi in range(len(env.graphs)) if key in {k for k, _, _ in env.input_names(gi)}]
        live = sorted({"%s.%s" % (cl, r) for gi in readers for cl, r in role.get(gi, ()) if cl in REACHABLE})
        dead = sorted({"%s.%s" % (cl, r) for gi in readers for cl, r in role.get(gi, ()) if cl not in REACHABLE})
        other = [str(gi) for gi in readers if gi not in role]
        rows.append((label, len(readers), ", ".join(live)[:160] or "-", ", ".join(dead)[:80] or "-",
                     ", ".join(other) or "-"))
    out.append(L.md_table(["input", "graphs", "reachable class graphs", "unreachable class graphs",
                           "other graphs"], rows))

    out += ["", "### 7b. What the volleyer gets: P(error), PF and aim efficiency against contact height and "
            "frames to contact", "",
            "Median Volley stat, fresh. Volley timing grade from section 3 (|t| < 0.3 = 10 frames). "
            "Computed from the model.", ""]
    rows = []
    for label, idx, cls in (("VolleyStandard (FlatVolley)", 19, "VolleyStandard"), ("VolleyPower", 16, "VolleyPower"),
                            ("VolleySlice", 17, "VolleySlice"), ("VolleyDrop", 18, "VolleyDrop")):
        for hy in (20.0, 50.0, 90.0, 140.0):
            for t in (0.0, 0.45):
                b = c.base(idx, "median", hand="volley", charge=0.5, scen="volley", timing=t,
                           extra={"hit_y": hy, "frames_to_contact": 15.0})
                pe = c.p_error(cls, b)
                pf, _ = c.pf(cls, b)
                e = c.aim_mean(cls, b, 10)[0]
                rows.append((label, "%.0f" % hy, "%+.2f" % t, "%.2f" % pe[0], "%.2f" % pe[1], "%.2f" % pf,
                             "%.2f" % e))
    out.append(L.md_table(["class", "contact cm", "timing", "P(error)", "net share", "PF", "aim eff"], rows))
    rows = []
    for label, idx, cls in (("VolleyStandard", 19, "VolleyStandard"), ("VolleyPower", 16, "VolleyPower")):
        for ftc in (5.0, 10.0, 20.0, 40.0):
            for dd in (0.0, 150.0):
                b = c.base(idx, "median", hand="volley", charge=0.5, scen="volley", timing=0.45,
                           extra={"frames_to_contact": ftc, "depth_diff": dd, "hit_y": 90.0})
                rows.append((label, "%.0f" % ftc, "%.0f" % dd, "%.2f" % c.p_error(cls, b)[0]))
    out += ["", "Reaction time (frames to contact S+0xCF0) and depth to cover (S+0xCF4), t = +0.45, contact 90 cm:", "",
            L.md_table(["class", "frames to contact", "depth diff cm", "P(error)"], rows)]

    out += ["", "### 7c. What the passer gets: opponent position", "",
            "Ground classes at median stats, t = +0.45 (late), opponent at the net (x = 300 cm from it) vs the "
            "baseline (1200). Without skills the opponent's position changes nothing (section 4); the "
            "passing-shot skills read it. Computed from the model.", ""]
    rows = []
    for label, idx, cls, ch in GROUND[:6]:
        for sk in (None, "PassingShotSniper", "CrushingPassingShot"):
            cells = []
            for ox in (1200.0, 300.0):
                b = c.base(idx, "median", charge=ch, timing=0.45, extra={"opp_x": ox})
                if sk:
                    b["skill:" + sk] = 1.0
                pf, _ = c.pf(cls, b)
                e, dm, _ = c.aim_mean(cls, b, 10)
                cells.append("PF %.2f, eff %.2f, dev %.0f, err %.2f" % (pf, e, dm, c.p_error(cls, b)[0]))
            rows.append((label, sk or "none") + tuple(cells))
    out.append(L.md_table(["class", "skill", "opponent at baseline", "opponent at net"], rows))
    return "\n".join(out)


# --------------------------------------------------------------------------- section 8: responsiveness (clip data)

def load_clips(path=None):
    """Minimal reader of data/gameplay/animation_clips.yaml (name, frames, contact_phase, segments)."""
    path = path or os.path.join(ROOT, "data", "gameplay", "animation_clips.yaml")
    clips, cur = [], None
    for line in open(path):
        t = line.strip()
        if t.startswith("- i:"):
            cur = {}
            clips.append(cur)
        elif cur is not None and ":" in t:
            k, v = t.split(":", 1)
            v = v.strip()
            if k in ("name",):
                cur[k] = v
            elif k in ("frames", "contact_phase"):
                cur[k] = None if v == "null" else float(v)
            elif k == "ignore_speed_coef":
                cur[k] = int(v)
            elif k == "segments":
                cur[k] = [(a, float(b), float(c)) for a, b, c in
                          re.findall(r"\[([0-9A-Za-z_#]+), ([-0-9.e]+), ([-0-9.e]+)\]", v)]
    return clips


SWING_FAMILIES = [("groundstroke FH/BH", lambda n: n.startswith(("Swing_FH", "Swing_BH"))),
                  ("return", lambda n: n.startswith("Swing_Return")),
                  ("volley", lambda n: n.startswith("Swing_Volley")),
                  ("smash", lambda n: n.startswith(("Swing_Smash", "Smash_"))),
                  ("serve", lambda n: n.startswith(("Swing_Serve", "Swing_ServeAndVolley")))]


def pct(vals, q):
    v = sorted(vals)
    return v[min(len(v) - 1, int(q * len(v)))]


def sec_resp(c):
    clips = load_clips()
    out = ["### 8a. Swing clips: frames from clip start to contact, and from contact to the Out window", "",
           "Read from data/gameplay/animation_clips.yaml (committed dump of AnimationsDB.bin; command and sha256 "
           "in its header). 'to Out' = (TransitionEvent[1].Position - EventRacket phase) x (FrameCount - 1): the "
           "frames after contact until the clip's Out transition window opens, i.e. `fn_886CD3C8` anim busy "
           "measured at contact (movement-and-animation s1.1). At play rate 1; the swing play rate multiplies by "
           "SwingSpeedCoef S+0x378 (graph 17: 1.16-1.30, section 5b) unless the clip sets IgnoreSpeedCoef. "
           "p10 / median / p90 over the clips of each family.", ""]
    rows = []
    for fam, test in SWING_FAMILIES:
        pre, post, n, ign = [], [], 0, 0
        for cl in clips:
            nm = cl.get("name", "")
            if not test(nm) or cl.get("contact_phase") is None or len(cl.get("segments", [])) < 2:
                continue
            fr = cl["frames"] - 1
            pre.append(cl["contact_phase"] * fr)
            post.append(max(0.0, (cl["segments"][1][1] - cl["contact_phase"]) * fr))
            ign += cl.get("ignore_speed_coef", 0)
            n += 1
        if not n:
            continue
        rate = 1.19
        rows.append((fam, n, ign, "%.0f / %.0f / %.0f" % (pct(pre, .1), pct(pre, .5), pct(pre, .9)),
                     "%.0f / %.0f / %.0f" % (pct(post, .1), pct(post, .5), pct(post, .9)),
                     "%.0f / %.0f / %.0f ms" % tuple(L.frames_to_ms(pct(post, q) / rate) for q in (.1, .5, .9))))
    out.append(L.md_table(["family", "clips", "IgnoreSpeedCoef", "start -> contact (frames)",
                           "contact -> Out window (frames, rate 1)", "same at rate 1.19"], rows))
    return "\n".join(out)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--work", default=ROOT, help="repository root that holds work/ and orig/ (default: this repo)")
    ap.add_argument("--tu", action="store_true", help="use the Title Update #1 data files")
    ap.add_argument("--full-skills", action="store_true", help="per-graph rows in the skills section")
    ap.add_argument("sections", nargs="+")
    a = ap.parse_args(argv)
    global FULL_SKILLS
    FULL_SKILLS = a.full_skills
    inp = Inputs(a.work, a.tu)
    c = Ctx(inp)
    secs = SECTIONS if a.sections == ["all"] else a.sections
    for s in secs:
        print(globals()["sec_" + s](c))
        print()


SECTIONS = ["inputs", "speeds", "shape", "timing", "situ", "stats", "skills", "serve", "net", "resp"]


def sec_inputs(c):
    return "### Inputs (%s)\n\n%s\n\nPython %s; analyser kernels tools/ts4_analyser.py; ball model tools/ts4data/ball_model.py." % (
        "Title Update #1" if c.inp.tu else "retail disc", c.inp.provenance(), sys.version.split()[0])


if __name__ == "__main__":
    main()
