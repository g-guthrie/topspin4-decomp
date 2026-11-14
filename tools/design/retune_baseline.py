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
