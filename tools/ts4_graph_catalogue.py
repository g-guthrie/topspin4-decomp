#!/usr/bin/env python3
"""Write the per-graph Markdown catalogue of the analyser graphs (docs/gameplay/graphs-catalogue.md).

Groups the 341 Expressions.bin graphs into families by what they write, and for each graph lists
its name (with confidence), who runs it (code loader or Settings.bin reference), every input and
output port bound to a struct member and byte offset, the node mix and, for short graphs, the
formula.  The full values (every constant and curve key) are in data/gameplay/graphs.yaml.

  python3 tools/ts4_graph_catalogue.py Expressions.bin State.bin Layoutall.bin Settings.bin OUT.md \
      [--names crc_dictionaries.json]

Offsets: S = own PlayerState element, AI = per-player AI record (State root +0xE8C list),
Ball/Match/Team = BallState/MatchState/own TeamState.  See docs/gameplay/graphs-decoded.md.
"""
import argparse
import collections
import hashlib
import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ts4_analyser as A  # noqa: E402

SHOT_CLASS_TABLE = 0x28C04      # Settings.bin: 40dd9ee9.00236a48.8c5e64b4, 33 x 0x18-byte entries
SHOT_CLASS_COUNT = 33

FAMILIES = [
    ("setup", "Player setup: stat curves"),
    ("fatigue", "Fatigue, vigor and tiredness"),
    ("ability", "Timing ability, swing/run speed coefficients, input filtering"),
    ("difficulty", "Shot difficulty and efficiency"),
    ("let", "Let"),
    ("olderror", "Shot-error graphs at planner +0x104 (write S+0x7DC)"),
    ("shotclass", "Per-shot-class error, power and aiming graphs (Settings shot-class table)"),
    ("aimix", "AI shot / serve / positioning mixes (ExpressionComponents)"),
    ("aiscore", "AI behaviour scores, AI timing and reachability scores"),
    ("court", "Court context and positioning scores"),
    ("rules", "Rule / reward evaluations"),
    ("other", "Empty or unused"),
]


def family(i, outs, name):
    o = " ".join(outs)
    if name in (0x075A2137, 0xDC1D59B1, 0x8C9B26E0):
        return "setup"
    if any(k in o for k in ("Fatigue", "Vivacity", "ProfileFactor")):
        return "fatigue"
    if any(k in o for k in ("TimingAbility", "AnimationSelection.SwingSelection", "AnimationSelection.Movement",
                            "ReceiverMoveState", "Emergency", "#daf2ecbd")):
        return "ability"
    if "ShotDifficulty" in o or "ShotEfficiency" in o:
        return "difficulty"
    if "LetProbability" in o or "LetCommands" in o:
        return "let"
    if "#e4f01642" in o:
        return "olderror"
    if any(k in o for k in ("FaultProbability", "OutcomeNet", "PowerfulFactor", "Efficiency", "DeepDeviation",
                            "#07902e50", "AimingState", "#7e28dbc0.#fd4a76f0", "#d9a8add8", "#e6d62656")):
        return "shotclass"
    if any(k in o for k in ("ShotComponents", "ServeComponents", "RepositioningComponents", "PositioningComponents")):
        return "aimix"
    if any(k in o for k in ("#91329eea", "ManualShotTiming", "SwingReactionTime", "#3237ffac", "FinalScore",
                            "#4abbb588")):
        return "aiscore"
    if any(k in o for k in ("TeamState", "ShotContext", "Context.", "#ad1995d3")):
        return "court"
    if any(k in o for k in ("EvaluationOutputs", "#7e28dbc0", "ReturnServeState", "EndOfPoint", "PressAndHold")):
        return "rules"
    return "other"


def shot_class_rows(settings, graphs, namer):
    """[(row, class name, aiming graph, power graph, [element graph...])]; a graph is given by its
    index, or "i/j" when the hash names several graphs (duplicate copies in Expressions.bin)."""
    idx = {}
    for i, g in enumerate(graphs):
        idx.setdefault(g.name, []).append(str(i))
    idx = {h: "/".join(v) for h, v in idx.items()}
    rows = []
    for k in range(SHOT_CLASS_COUNT):
        e = SHOT_CLASS_TABLE + 0x18 * k
        rel, cnt = struct.unpack_from(">iI", settings, e)
        key, aim, pw = struct.unpack_from(">III", settings, e + 0xC)
        els = []
        for j in range(cnt):
            a = e + rel + 8 * j
            r = struct.unpack_from(">i", settings, a)[0]
            els.append(idx.get(struct.unpack_from(">I", settings, a + r)[0]))
        rows.append((k, namer(key, mark=False), idx.get(aim), idx.get(pw), els))
    return rows


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("expressions")
    ap.add_argument("state")
    ap.add_argument("layout")
    ap.add_argument("settings")
    ap.add_argument("out")
    ap.add_argument("--names", action="append", default=[], help="CRC dictionary JSON ({group: {hex: name}})")
    ap.add_argument("--name-table", default=A.DEFAULT_NAME_TABLE)
    a = ap.parse_args()
    files = {}
    for k in ("expressions", "state", "layout", "settings"):
        with open(getattr(a, k), "rb") as f:
            files[k] = f.read()
    graphs = A.parse_expressions(files["expressions"])
    tab = A.load_name_table(a.name_table)
    for p in a.names:
        with open(p) as f:
            for v in json.load(f).values():
                for k, n in v.items():
                    tab[int(k, 16)] = (n, "high")
    for k, v in A.known_names().items():
        tab[k] = (v, "high")
    nm = A.Namer(tab)
    B = A.Bindings(files["state"], files["layout"])
    refs = A.settings_references(files["settings"], B.types, {g.name for g in graphs})

    def short(s):
        return s.replace("PlayerState.", "S.")

    def rshort(p):
        s = ".".join(nm(x) if isinstance(x, int) else "[]" for x in p)
        s = s.replace("AI.%s.%s.%s.[].Difficulty.[]." % (nm(0x99D2AC4E), nm(0x51B273D0), nm(0x63199A64)),
                      "AI.Style[].Difficulty[].")
        s = s.replace("%s.%s.%s.[]." % (nm(0x40DD9EE9), nm(0x00236A48), nm(0x8C5E64B4)), "ShotClassTable[].")
        return s

    def lab(p):
        b = B.bind(p)
        if b:
            d = b["domain"] if b["domain"][0] != "#" else nm(p.domain)
            m = ".".join(nm(x) if isinstance(x, int) else x for x in b["member"])
            base = {"player": "S", "ball": "Ball", "match": "Match", "team": "Team", "ai": "AI"}[b["root"]]
            return short("%s.%s" % (d, m)), "%s+0x%x" % (base, b["root_offset"])
        if p.index < 0:
            return short("%s.%s (link)" % (nm(p.domain), ".".join(nm(h) for h in p.path))), "link"
        return short("%s.%s" % (nm(p.domain), ".".join(nm(h) for h in p.path))), "cell %d out of range" % p.index

    cat = collections.defaultdict(list)
    for i, g in enumerate(graphs):
        cat[family(i, [lab(p)[0] for p in g.outputs], g.name)].append(i)
    out = []
    W = out.append
    W("# Analyser graph catalogue (generated)")
    W("")
    W("Generated by `python3 tools/ts4_graph_catalogue.py Expressions.bin State.bin Layoutall.bin Settings.bin OUT "
      "--names work/disc/gameplay/crc_dictionaries.json`.")
    for k, label in (("expressions", "Expressions.bin"), ("state", "State.bin"), ("layout", "Layoutall.bin"),
                     ("settings", "Settings.bin")):
        W("%s sha256 `%s`." % (label, hashlib.sha256(files[k]).hexdigest()))
    W("")
    W("Read with docs/gameplay/graphs-decoded.md. Names ending `?` are medium confidence, `??` low; `#xxxxxxxx` is an "
      "unnamed hash. `S` = own PlayerState element, `AI` = the player's AI record. Every constant and curve key is "
      "in data/gameplay/graphs.yaml. Curve keys are ramps y0->y1 over [x0..x1] (runtime slope fixup).")
    for fam, title in FAMILIES:
        W("\n## %s (%d graphs)\n" % (title, len(cat[fam])))
        for i in cat[fam]:
            g = graphs[i]
            mix = collections.Counter(n.kind for n in g.nodes)
            nkeys = sum(len(n.fields["keys"]) for n in g.nodes if n.kind == "CURVE")
            conf = nm.conf(g.name) or "unnamed"
            W("**%d `%08x` %s** (%s)" % (i, g.name, nm(g.name, mark=False) if conf != "unnamed" else "-", conf))
            run = ["code %s @0x%08X" % x for x in A.CODE_LOADERS.get(g.name, [])]
            rr = sorted({rshort(p) for p in refs.get(g.name, [])})
            if rr:
                run.append("Settings `%s`%s" % (rr[0], " (+%d more paths)" % (len(rr) - 1) if len(rr) > 1 else ""))
            if not run and g.name in getattr(A, "UNREFERENCED_GRAPHS", ()):
                run = ["never: the hash occurs in no other data file and in no code (graphs-decoded.md 4.3)"]
            W("- runs: %s" % ("; ".join(run) if run else "no loader or data reference found"))
            ins = []
            for x in (lab(p) for p in g.inputs):
                if x not in ins:
                    ins.append(x)
            outs = [lab(p) for p in g.outputs]
            W("- in: %s" % (", ".join("`%s` (%s)" % x for x in ins) if ins else "-"))
            W("- out: %s" % (", ".join("`%s` (%s)" % x for x in outs) if outs else "-"))
            W("- nodes: %s; %d curve keys" % (", ".join("%s %d" % kv for kv in mix.items()) or "none", nkeys))
            lines, _o = A.graph_formula(g, [lab(p)[0] for p in g.inputs])
            if lines and len(lines) <= 6:
                W("- formula: `%s`" % "; ".join("%s = %s" % ln for ln in lines).replace("`", ""))
            W("")
    W("\n## Shot-class table (Settings.bin 40dd9ee9.00236a48.8c5e64b4, file offset 0x%X)\n" % SHOT_CLASS_TABLE)
    W("| row | class | aiming graph (3f9c096b) | power graph (2c3e6b9c) | Element graphs |")
    W("|---|---|---|---|---|")
    for k, cname, aim, pw, els in shot_class_rows(files["settings"], graphs, nm):
        W("| %d | %s | %s | %s | %s |" % (k, cname, aim if aim is not None else "-", pw if pw is not None else "-",
                                         ", ".join(e or "?" for e in els)))
    with open(a.out, "w") as f:
        f.write("\n".join(out) + "\n")
    print("wrote %s: %s" % (a.out, {k: len(v) for k, v in cat.items()}))
    return 0


if __name__ == "__main__":
    sys.exit(main())
