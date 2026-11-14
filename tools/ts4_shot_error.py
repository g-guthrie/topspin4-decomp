#!/usr/bin/env python3
"""Evaluate the shot-error graphs of Top Spin 4 for chosen game situations (standard library only).

The pre-launch error roll (``fn_886807C0``, docs/gameplay/gp4b.md section 10.2) reads four
PlayerState floats.  Three of them are written by analyser graphs of ``Expressions.bin``:

  S+0x718  FaultProbability   the fault graph of the shot class
  S+0x720  OutcomeNet         the net graph of the shot class (share of errors that hit the net)
  S+0x71C  LetProbability     graph 181

and S+0x564 is reset to 0.0 by the PlayerCtx reset ``fn_8869DEF0`` and written by nothing else
(docs/gameplay/graphs-decoded.md section 6.9).  So, for one shot:

  P(error) = clamp01(S+0x718),  P(net) = P(error) * S+0x720,  P(out) = P(error) * (1 - S+0x720)

This tool runs the fault and net graphs of one or more shot classes with every input taken from a
scenario: named inputs below, ``--set S+0x770=55`` style overrides, and 0.0 for the rest (link
ports such as SkillList included).  It prints one row per timing value.

Usage:
  python3 tools/ts4_shot_error.py Expressions.bin State.bin Layoutall.bin --class FlatPower \
      --set hand=0.8 vigor=1 power=0.9 err_max=1 --timing -1 -0.6 -0.3 0 0.3 0.6 1
"""
from __future__ import annotations

import argparse
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import ts4_analyser as A  # noqa: E402

# Shot-class table rows (Settings.bin 40dd9ee9.00236a48.8c5e64b4, graphs-decoded.md section 5):
# class -> (net graph index, fault graph index).  Duplicate hashes resolve to the lower index
# (fn_8866F028 returns the first match), which is the index listed here.
SHOT_CLASSES = {
    "SliceFinesse": (279, 278), "TopSpinFinesse": (277, 276), "FlatFinesse": (275, 274),
    "SliceMedium": (288, 287), "TopSpinMedium": (286, 285), "FlatMedium": (284, 283),
    "SlicePower": (297, 296), "TopSpinPower": (295, 294), "FlatPower": (293, 292),
    "TopSpinRisk": (303, 302), "SliceRisk": (305, 304), "Risk": (299, 298), "FlatRisk": (301, 300),
    "ReturnFlatFinesse": (314, 313), "ReturnTopSpinFinesse": (316, 315), "ReturnSliceFinesse": (318, 317),
    "ReturnFlatPower": (314, 313), "ReturnTopSpinPower": (316, 315), "ReturnSlicePower": (318, 317),
    "ServeFlatFinesse": (306, 307), "ServeSpinFinesse": (306, 307), "ServeFlatMedium": (306, 308),
    "ServeSpinMedium": (306, 308), "ServeFlatPowerful": (310, 309), "ServeSpinPowerful": (310, 309),
    "AdvancedServe": (312, 311), "VolleyPower": (326, 325), "VolleyStandard": (324, 323),
    "VolleySlice": (328, 327), "VolleyDrop": (330, 329), "DropShot": (332, 331), "Lob": (333, 334),
    "Smash": (340, 339),
}

# friendly scenario names -> (root object, byte offset in that object)
ALIASES = {
    "timing": ("player", 0x544),      # ShotContext.ManualShotTiming, -1 early .. +1 late
    "hand": ("player", 0x74C),        # HandAttributeQuality: forehand/backhand (or volley) stat 0..1
    "vigor": ("player", 0xF54),       # Fatigue.Output.CurrentVigor 0..1 (1 = fresh)
    "power": ("player", 0xE00),       # charge 0..1 (Finesse < 0.15 <= Medium < 0.7 <= Powerful)
    "run_dist": ("player", 0x7A0),    # #03d2be3d, distance run to the hit point (cm, I)
    "run_speed": ("player", 0x7A4),   # #5cf9de02, required run speed (m/s, I)
    "x1407106c": ("player", 0x770),   # #1407106c (role I: reach effort 0..100)
    "ball_diff": ("player", 0x764),   # BallDifficulty
    "shot_diff": ("player", 0x7A8),   # ShotDifficulty
    "rally": ("match", 0x334),        # MatchState.#8beb922e, shots in the rally (I)
    "hit_x": ("ball", 0x340),         # BallState.Commands.#7bb6a318.From.x, contact depth (cm)
    "hit_y": ("ball", 0x344),         # contact height (cm)
    "err_min": ("player", 0x6D4),     # ShotSpecific.ErrorResolution.Min (Settings shot definition)
    "err_max": ("player", 0x6D8),     # ShotSpecific.ErrorResolution.Max
}


def parse_key(k):
    """'hand' or 'S+0x74c' / 'Ball+0x344' / 'Match+0x334' -> (root, offset)."""
    if k in ALIASES:
        return ALIASES[k]
    root, _, off = k.partition("+")
    roots = {"S": "player", "Ball": "ball", "Match": "match", "Team": "team", "AI": "ai"}
    if root not in roots or not off:
        raise ValueError("unknown scenario key %r" % k)
    return roots[root], int(off, 0)


def input_values(graph, bindings, scenario):
    """One float per input port: the scenario value of the field it is bound to, else 0.0."""
    vals = []
    for p in graph.inputs:
        b = bindings.bind(p) if bindings is not None else None
        key = (b["root"], b["root_offset"]) if b else None
        vals.append(scenario.get(key, 0.0))
    return vals


def outputs_by_offset(graph, bindings, values):
    out = {}
    for p, v in zip(graph.outputs, values):
        b = bindings.bind(p) if bindings is not None else None
        if b:
            out[(b["root"], b["root_offset"])] = v
    return out


def shot_error(graphs, bindings, cls, scenario):
    """(P(error), share of errors in the net) for one shot class and one scenario."""
    net_i, fault_i = SHOT_CLASSES[cls]
    gf, gn = graphs[fault_i], graphs[net_i]
    of = outputs_by_offset(gf, bindings, A.evaluate(gf, input_values(gf, bindings, scenario)))
    on = outputs_by_offset(gn, bindings, A.evaluate(gn, input_values(gn, bindings, scenario)))
    p = of.get(("player", 0x718), 0.0)
    net = on.get(("player", 0x720), 0.0)
    return min(max(p, 0.0), 1.0), net


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("expressions")
    ap.add_argument("state")
    ap.add_argument("layout")
    ap.add_argument("--class", dest="classes", action="append", default=[], help="shot class (repeatable)")
    ap.add_argument("--set", nargs="*", default=[], metavar="KEY=VALUE")
    ap.add_argument("--timing", nargs="*", type=float, default=[-1, -0.6, -0.3, -0.1, 0, 0.1, 0.3, 0.6, 1])
    args = ap.parse_args()
    graphs = A.parse_expressions(open(args.expressions, "rb").read())
    bindings = A.Bindings(open(args.state, "rb").read(), open(args.layout, "rb").read())
    scenario = {}
    for kv in args.set:
        k, _, v = kv.partition("=")
        scenario[parse_key(k)] = float(v)
    classes = args.classes or ["FlatPower"]
    print("timing  " + "  ".join("%-22s" % c for c in classes))
    for t in args.timing:
        scenario[ALIASES["timing"]] = t
        cells = []
        for c in classes:
            p, net = shot_error(graphs, bindings, c, scenario)
            cells.append("P=%.3f net=%.2f      " % (p, net))
        print("%+.2f   %s" % (t, "  ".join(cells)))


if __name__ == "__main__":
    main()
