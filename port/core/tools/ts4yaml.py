#!/usr/bin/env python3
"""Build a ts4core data blob (TS4D v1) from the readable gameplay dumps in data/gameplay/.

    python3 port/core/tools/ts4yaml.py pack --data data/gameplay --out work/port/game.ts4d
    python3 port/core/tools/ts4yaml.py check --data data/gameplay      (parse + summary, writes nothing)

The dumps are committed (they are readable values, see AGENTS.md); the blob they produce holds the same values
and is not committed. Sources and their sha256 are written to <out>.manifest.json.

Sections written (docs/port/data-format.md):
    TUNE  provisional tunables, overridden by every GAME value the dumps hold
    TPLS  the 37 shot template rows rebuilt as a big-endian image; curve20 keys carry the load-time ramp slope
          (fn_8867BB78 / fn_88179740: slope = (y1 - y0) / (x1 - x0)), exactly what the runtime evaluates
    TREE  the shot request tree (shot_tree.yaml)
    GRPH  all 341 analyser graphs (graphs.yaml), slopes fixed up the same way
    BIND  every graph port bound to a field: (region, byte offset) of the PlayerState/Ball/Match/Team/AI image,
          skill links and qualifier links (G1 cell table, traits_skills.yaml)
    SINI  State.bin defaults of every bound field
    CURV  power curves, serve timing curve, movement validity tables
    AIDF  AI difficulty records (coaches_career.yaml)
    SKIL  the 32 skills in SkillList order
    ANIM  clip catalogue, anim groups / subgroups, move sets, transition rules and matrix (animation_rules.yaml)

Standard library only, except that PyYAML is used for the regular YAML files when it is installed (graphs.yaml
is not valid YAML and always goes through the line parser below). Without PyYAML only GRPH/BIND/SINI are built.
"""
import argparse
import hashlib
import json
import os
import re
import struct
import sys
import zlib

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(os.path.dirname(HERE)))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, "tools"))
import ts4d  # noqa: E402

try:
    import yaml  # noqa: F401
except ImportError:  # pragma: no cover
    yaml = None


def crc(s):
    return zlib.crc32(s.encode("ascii")) & 0xFFFFFFFF


def f32(x):
    return struct.unpack("<f", struct.pack("<f", float(x)))[0]


def slope_fixup(x0, x1, y0, y1):
    """fn_88179740 in single precision (same as tools/ts4_analyser.py slope_fixup)."""
    d = f32(f32(x1) - f32(x0))
    if d == 0.0:
        return 0.0
    return f32(f32(f32(y1) - f32(y0)) / d)


def hexname(s):
    """'#36bde5fe' / '36bde5fe' / 'Fatality' -> u32 hash."""
    if isinstance(s, int):           # YAML read an all-digit hex word as a decimal int
        s = "%08d" % s
    s = str(s).strip().strip('"')
    if s.startswith("#"):
        s = s[1:]
    if re.fullmatch(r"[0-9a-fA-F]{8}", s):
        return int(s, 16)
    return crc(s)


# ============================================================================== regions (BIND / SINI)
R_NONE, R_SELF, R_OPP, R_BALL, R_MATCH, R_TEAM, R_AI, R_SKILL, R_QUAL, R_PARTNER = range(10)
F_RANDOM = 1
# domain -> (region, base offset inside the root object); docs/gameplay/graphs-decoded.md s3.2
DOMAINS = {
    "PlayerState": (R_SELF, 0x000), "3ba3d582": (R_OPP, 0x000), "a2aa8438": (R_PARTNER, 0), "56b5b281": (R_PARTNER, 0),
    "Context": (R_SELF, 0x4F0), "ShotContext": (R_SELF, 0x500), "8448b811": (R_SELF, 0x880),
    "3237ffac": (R_SELF, 0xB80), "MatchAnalyser": (R_SELF, 0xF80),
    "BallState": (R_BALL, 0), "MatchState": (R_MATCH, 0), "TeamState": (R_TEAM, 0),
    "UserAIState?": (R_AI, 0x000), "e9ca839c": (R_AI, 0x000), "ShotComponents": (R_AI, 0x23C),
    "ServeComponents": (R_AI, 0x1FC), "RepositioningComponents": (R_AI, 0x1E0), "PositioningComponents": (R_AI, 0x1D0),
}
# Profile.CustomAttribute list payloads live outside the PlayerState object (player 0's payload at element offset
# 0x5AC0, graphs-decoded.md s6.1): the port keeps them in an extension of its PlayerState image.
PS_EXTENSION = {0x5AC4: 0x1070, 0x5ACC: 0x1074}
RANDOM_MEMBERS = ("Random", "Random1", "Random2", "RandSlot", "RandSlot??", "Random?", "Random1?", "Random2?")


def domain_key(d):
    d = d.strip().strip('"')
    return d[1:] if d.startswith("#") else d


# ============================================================================== graphs.yaml line parser
PORT_RE = re.compile(r"  - reg: (\d+)\n    label: (.*)\n    domain: (.*)\n    path: (.*)\n    cell: (-?\d+)\n"
                     r"(?:    offset: (0x[0-9a-f]+)\n    object: (.*)\n    member: (.*)\n)?"
                     r"(?:    member_offset: (0x[0-9a-f]+)\n)?(?:    state_default: (.*)\n)?")
HEAD_RE = re.compile(r"^- index: (\d+)\n  hash: (0x[0-9a-f]+)\n  name: (.*)\n", re.M)
REG = re.compile(r"r(-?\d+)")


def _num(s):
    s = s.strip()
    if s in ("true", "false"):
        return 1.0 if s == "true" else 0.0
    return float(s)


def parse_graphs_yaml(text):
    """-> list of graph dicts {index, hash, name, nregs, inputs, outputs, nodes} (nodes in the Blob format)."""
    heads = list(HEAD_RE.finditer(text))
    out = []
    for i, h in enumerate(heads):
        body = text[h.start(): heads[i + 1].start() if i + 1 < len(heads) else len(text)]
        nregs = int(re.search(r"\n  registers: (\d+)", body).group(1))
        sec = {}
        for name in ("inputs", "outputs", "nodes", "formula"):
            m = re.search(r"\n  %s:\n" % name, body)
            sec[name] = m.end() if m else None

        def block(name, nxt):
            if sec[name] is None:
                return ""
            end = len(body)
            for n in nxt:
                if sec[n] is not None and sec[n] > sec[name]:
                    end = min(end, sec[n] - len("\n  %s:\n" % n) + 1)
            return body[sec[name]:end]

        def ports(txt):
            res = []
            for m in PORT_RE.finditer(txt):
                res.append(dict(reg=int(m.group(1)), label=m.group(2).strip('"'), domain=m.group(3), path=m.group(4).strip('"'),
                                cell=int(m.group(5)), offset=int(m.group(6), 16) if m.group(6) else None,
                                member=(m.group(8) or "").strip('"'),
                                default=_num(m.group(10)) if m.group(10) else None))
            return res

        ins = ports(block("inputs", ("outputs", "nodes", "formula")))
        outs = ports(block("outputs", ("nodes", "formula")))
        nodes = []
        ntxt = block("nodes", ("formula",))
        lines = ntxt.split("\n")
        j = 0
        while j < len(lines):
            ln = lines[j].strip()
            j += 1
            if not ln.startswith("- {kind:"):
                continue
            fields = dict(kv.split(": ", 1) for kv in re.findall(r"(\w+: (?:\[[^\]]*\]|[^,}]+))", ln[3:-1]))
            kind = fields["kind"]
            d = {"kind": kind}
            if "out" in fields:
                d["out"] = int(REG.match(fields["out"]).group(1))
            if kind in ts4d.VARIADIC:
                d["slots"] = [int(x) for x in REG.findall(fields["in"])]
            elif kind == "CURVE":
                d["in"] = int(REG.match(fields["in"]).group(1))
                keys = []
                while j < len(lines) and lines[j].strip().startswith(("keys:", "- [")):
                    t = lines[j].strip()
                    j += 1
                    if t.startswith("- ["):
                        x0, x1, y0, y1 = (float(v) for v in t[3:-1].split(","))
                        keys.append((f32(x0), f32(x1), f32(y0), slope_fixup(x0, x1, y0, y1)))
                d["keys"] = keys
            elif kind in ("SUB", "DIV"):
                d["a"] = int(REG.match(fields["a"]).group(1))
                d["b"] = int(REG.match(fields["b"]).group(1))
            elif kind in ("LERP", "INVLERP"):
                for k in ("a", "b", "t"):
                    d[k] = int(REG.match(fields[k]).group(1))
            elif kind == "CONST":
                d["value"] = float(fields["value"])
            else:
                raise ValueError("graph %s: unknown node kind %s" % (h.group(1), kind))
            nodes.append(d)
        out.append(dict(index=int(h.group(1)), hash=int(h.group(2), 16), name=h.group(3).strip('"'), nregs=nregs,
                        inputs=ins, outputs=outs, nodes=nodes))
    return out


def grph_dicts(graphs):
    def port(p):
        return (hexname(domain_key(p["domain"])), p["cell"], p["reg"], crc(p["path"]))
    return [dict(name_hash=g["hash"], nregs=g["nregs"], inputs=[port(p) for p in g["inputs"]],
                 outputs=[port(p) for p in g["outputs"]], nodes=g["nodes"]) for g in graphs]


# ============================================================================== BIND / SINI
def qualifier_tables(anim):
    """-> {type_hash: (type_index, {value_hash: value_index})} from animation_rules.yaml qualifier_types."""
    t = {}
    if not anim:
        return t
    for q in anim["qualifier_types"]:
        t[crc(q["id"])] = (q["i"], {crc(v): k for k, v in enumerate(q["values"])})
    return t


def bind_ports(graphs, skills=None, anim=None):
    """-> (bind list [(graph_hash, graph_index, [(region, flags, aux, offset)])], defaults {(region, off): value},
           report dict)."""
    skill_reg = {}       # (graph_index, reg) -> skill index
    qual_links = {}      # graph_index -> [(type_hash, value_hash)] in port order
    if skills:
        for s in skills["skills"]:
            if s.get("skill_list_index") is None:
                continue
            for gc in s.get("graph_consumers") or []:
                for r in gc.get("skill_registers") or []:
                    skill_reg[(gc["graph_index"], r)] = s["skill_list_index"]
        for o in skills.get("other_link_ports") or []:
            qual_links.setdefault(o["graph_index"], []).append(tuple(hexname(x) for x in o["qualifier"]))
    qt = qualifier_tables(anim)
    out, defaults = [], {}
    rep = dict(ports=0, bound=0, skill=0, qual=0, unbound=[])
    for g in graphs:
        ports = []
        qi = 0
        for p in g["inputs"] + g["outputs"]:
            rep["ports"] += 1
            dk = domain_key(p["domain"])
            region, base = DOMAINS.get(dk, (R_NONE, 0))
            flags, aux, off = 0, 0, 0
            if p["cell"] < 0:
                if "SkillList" in p["path"]:
                    sk = skill_reg.get((g["index"], p["reg"]))
                    region, off = (R_SKILL, sk) if sk is not None else (R_NONE, 0)
                    rep["skill"] += sk is not None
                else:
                    links = qual_links.get(g["index"], [])
                    region = R_NONE
                    if qi < len(links):
                        th, vh = links[qi]
                        if th in qt and vh in qt[th][1]:
                            region, aux, off = R_QUAL, qt[th][0], qt[th][1][vh]
                            rep["qual"] += 1
                    qi += 1
            elif p["offset"] is None or region == R_NONE:
                region = R_NONE
            else:
                off = base + p["offset"]
                if region in (R_SELF, R_OPP):
                    off = PS_EXTENSION.get(off, off)
                if p["member"] in RANDOM_MEMBERS or p["path"].split(".")[-1].rstrip("?") in ("Random", "Random1", "Random2", "RandSlot"):
                    flags |= F_RANDOM
                if p["default"] is not None and region in (R_SELF, R_OPP, R_TEAM, R_AI, R_MATCH):
                    reg = R_SELF if region == R_OPP else region
                    defaults[(reg, off)] = p["default"]
            if region == R_NONE:
                rep["unbound"].append("%d:%s" % (g["index"], p["label"]))
            else:
                rep["bound"] += 1
            ports.append((region, flags, aux, off))
        out.append((g["hash"], g["index"], ports))
    return out, defaults, rep


def enc_bind(bind):
    head = struct.pack("<I", len(bind))
    off = 4 + 16 * len(bind)
    d, body = b"", b""
    for gh, gi, ports in bind:
        d += struct.pack("<IIII", gh, gi, len(ports), off + len(body))
        body += b"".join(struct.pack("<BBHI", r, f, a, o) for r, f, a, o in ports)
    return head + d + body


def enc_sini(defaults):
    items = sorted(defaults.items())
    return struct.pack("<I", len(items)) + b"".join(struct.pack("<BxxxIf", r, o, f32(v)) for (r, o), v in items)


# ============================================================================== AIDF / SKIL
AI_GRAPHS = ("g40", "g44", "g48", "g4c", "g50", "g54")
AI_LISTS = ("l00", "l0c", "l18", "l24", "l30")


def enc_aidf(styles):
    """styles: [{style, levels: [{level, g40..g54, run_speed_limit, lists: {l00..l30: [entries]}}]}]"""
    ns = len(styles)
    nl = max(len(s["levels"]) for s in styles) if styles else 0
    head = struct.pack("<II", ns, nl) + b"".join(struct.pack("<I", hexname(s["style"])) for s in styles)
    rec_off = len(head)
    rec_size = 4 + 24 + 4 + 40
    ent_base = rec_off + rec_size * ns * nl
    recs, ents = b"", b""
    for s in styles:
        for li in range(nl):
            lv = s["levels"][li] if li < len(s["levels"]) else None
            if lv is None:
                recs += b"\0" * rec_size
                continue
            r = struct.pack("<I", crc(str(lv["level"])))
            r += b"".join(struct.pack("<I", hexname(lv[g]) if lv.get(g) else 0) for g in AI_GRAPHS)
            r += struct.pack("<f", f32(lv.get("run_speed_limit", 0.0)))
            counts, offs = [], []
            for ln in AI_LISTS:
                es = (lv.get("lists") or {}).get(ln) or []
                counts.append(len(es))
                offs.append(ent_base + len(ents))
                for e in es:
                    ents += struct.pack("<IIffI", hexname(e["component"]), hexname(e["graph"]), f32(e["weight"]),
                                        f32(e["default"]), int(e["flag"]))
            r += struct.pack("<5I", *counts) + struct.pack("<5I", *offs)
            recs += r
    return head + recs + ents


def enc_skil(skills):
    idx = {s["skill_list_index"]: hexname(s["crc32"]) for s in skills["skills"] if s.get("skill_list_index") is not None}
    n = max(idx) + 1 if idx else 0
    return struct.pack("<I", n) + b"".join(struct.pack("<I", idx.get(i, 0)) for i in range(n))


# ============================================================================== ANIM
ANIM_QTYPES = ("PositionOnCourt", "Category", "SwingType", "SwingEffect", "Timing", "Power", "Control", "MoveToNet",
               "SwingCategory", "Properties", "Effort", "SwingPreferenceLevel")


def anim_tables(anim, setup="Men"):
    qtypes = {q["id"]: q for q in anim["qualifier_types"]}
    qsel = [qtypes[n] for n in ANIM_QTYPES if n in qtypes]
    groups = [g for g in anim["anim_groups"] if g["setup"] == setup]
    g0 = groups[0]["index"] if groups else 0
    subs = []
    for gi, g in enumerate(groups):
        for s in g["subgroups"]:
            subs.append(dict(id=s["id"], group=gi, first=s["first"], count=s["count"], abs=s["abs"]))
    sub_abs_base = min(s["abs"] for s in subs) if subs else 0
    clips = [c for c in anim["animations"] if c.get("setup", setup) == setup]
    clip_base = clips[0]["i"] if clips else 0
    gname = {}
    for gi, g in enumerate(groups):
        for s in g["subgroups"]:
            gname[(g["id"], s["id"])] = (gi, s["abs"] - sub_abs_base)
        gname.setdefault((g["id"], None), (gi, -1))
    movesets = []
    for m in anim["movesets"]:
        secs = []
        for sec in m.get("sectors") or []:
            secs.append(gname.get((sec[0], sec[1]), gname.get((sec[0], None), (-1, -1))))
        movesets.append(dict(id=m["id"], sectors=secs))
    return dict(qsel=qsel, groups=groups, g0=g0, subs=subs, sub_abs_base=sub_abs_base, clips=clips,
                clip_base=clip_base, movesets=movesets)


def enc_anim(anim, setup="Men"):
    t = anim_tables(anim, setup)
    qsel = t["qsel"]
    nq = len(qsel)
    parts = []
    # qualifier type list + value table
    qlist = b"".join(struct.pack("<I", q["i"]) for q in qsel)
    qv = b""
    nqv = 0
    for slot, q in enumerate(qsel):
        for vi, v in enumerate(q["values"]):
            qv += struct.pack("<IIBBH", crc(q["id"]), crc(str(v)), slot, vi, 0)
            nqv += 1
    # clips
    stride = 20 + 4 * nq
    cl = b""
    for c in t["clips"]:
        contact = -1.0
        for ev in c.get("ev") or []:
            if ev[0] == "EventRacket":
                contact = float(ev[1])
                break
        words = []
        for q in qsel:
            vals = (c.get("q") or {}).get(q["id"]) or []
            m = 0
            for v in vals:
                if str(v) in [str(x) for x in q["values"]]:
                    m |= 1 << [str(x) for x in q["values"]].index(str(v))
            words.append(m & 0xFFFFFFFF)
        cl += struct.pack("<Ifhhf BBH", crc(c["name"]),
                          f32(c.get("frames", 0.0)), c["group"] - t["g0"], c["sub"] - t["sub_abs_base"], f32(contact),
                          1 if c.get("ignore_speed_coef") else 0, min(int(c.get("max_occ", 0) or 0), 255), 0)
        cl += b"".join(struct.pack("<I", w) for w in words)
    gr = b""
    for g in t["groups"]:
        subs = [s for s in t["subs"] if s["group"] == t["groups"].index(g)]
        gr += struct.pack("<IHHHHB3x", crc(g["id"]), g["first"] - t["clip_base"], g["count"],
                          (subs[0]["abs"] - t["sub_abs_base"]) if subs else 0, len(subs), 1 if g.get("allow_speed_coef") else 0)
    sb = b"".join(struct.pack("<IHHHH", crc(s["id"]), s["group"], s["first"] - t["clip_base"], s["count"], 0) for s in t["subs"])
    ms_dir, ms_body = [], b""
    for m in t["movesets"]:
        ms_dir.append((crc(m["id"]), len(m["sectors"]), len(ms_body)))
        ms_body += b"".join(struct.pack("<hh", g, s) for g, s in m["sectors"])
    rules = b""
    for r in anim["transition_rules"]:
        kind = 0 if r["kind"] == "Transition" else 1
        g = r.get("AnimGroupIndex", -1)
        g = g - t["g0"] if g is not None and g >= 0 else -1
        s = r.get("SubGroupIndex", -1)
        s = s if s is not None and 0 <= s < 0x7FFF else -1
        rules += struct.pack("<Bbbxhhffff", kind, int(r.get("SourceEventIndex", -1)), int(r.get("DestEventIndex", -1)), g, s,
                             f32(r.get("LowVivacitySpeedCoef", 1.0)), f32(r.get("HighVivacitySpeedCoef", 1.0)),
                             f32(r.get("BlendInFrameCount", 15.0)), f32(r.get("BlendOutFrameCount", 15.0)))
    mat = anim["transition_matrix"]
    msize = int(mat["size"])
    mrows = mat["rows"]
    mat_dir, mat_body = [], b""
    for i in range(msize):
        cells = mrows.get(i) or mrows.get(str(i)) or []
        mat_dir.append((len(cells), len(mat_body)))
        mat_body += b"".join(struct.pack("<hh", int(a), int(b)) for a, b in cells)
    # layout
    HDR = 17 * 4
    off = HDR
    o_q = off; off += len(qlist)
    o_qv = off; off += len(qv)
    o_cl = off; off += len(cl)
    o_gr = off; off += len(gr)
    o_sb = off; off += len(sb)
    o_ms = off; off += 12 * len(ms_dir)
    o_msb = off; off += len(ms_body)
    o_ru = off; off += len(rules)
    o_md = off; off += 8 * len(mat_dir)
    o_mb = off; off += len(mat_body)
    hdr = struct.pack("<17I", nq, o_q, nqv, o_qv, len(t["clips"]), o_cl, stride, len(t["groups"]), o_gr, len(t["subs"]),
                      o_sb, len(ms_dir), o_ms, len(anim["transition_rules"]), o_ru, msize, o_md)
    msd = b"".join(struct.pack("<III", h, n, o_msb + o) for h, n, o in ms_dir)
    mdd = b"".join(struct.pack("<II", n, o_mb + o) for n, o in mat_dir)
    parts = hdr + qlist + qv + cl + gr + sb + msd + ms_body + rules + mdd + mat_body
    return parts, t


# ============================================================================== templates (TPLS) and tree
K_KIND = {"DropTime": 0x5D90675B, "BounceSpeed": 0x50B89452, "InitialSpeed": 0xC1965E5C, "AverageSpeed": 0x2DB3EB6F,
          "Apogee": 0x879BA860}


def _value(img, v):
    """write a value node; returns (target offset, type)."""
    if v is None or v.get("type") == "const":
        t = img.alloc(4)
        img.putf(t, (v or {}).get("value", 0.0))
        return t, ts4d.NODE_CONST
    if v["type"] == "curve20":
        keys = v["keys"]
        hdr = img.alloc(8)
        k = img.alloc(20 * len(keys))
        img.put32(hdr, k - hdr)
        img.put32(hdr + 4, len(keys))
        for j, kk in enumerate(keys):
            for m, x in enumerate((kk["x0"], kk["x1"], kk["y0"], slope_fixup(kk["x0"], kk["x1"], kk["y0"], kk["y1"]), kk["y1"])):
                img.putf(k + 20 * j + 4 * m, x)
        return hdr, ts4d.NODE_CURVE20
    if v["type"] == "table2d":
        rows = v["rows"]
        hdr = img.alloc(8)
        rr = img.alloc(16 * len(rows))
        img.put32(hdr, rr - hdr)
        img.put32(hdr + 4, len(rows))
        for j, row in enumerate(rows):
            keys = row["keys_over_height_cm"]
            k = img.alloc(16 * len(keys))
            r0 = rr + 16 * j
            img.put32(r0, k - r0)
            img.put32(r0 + 4, len(keys))
            img.putf(r0 + 12, row["a_dist_cm"])
            for q, kk in enumerate(keys):
                for m, x in enumerate((kk["x0"], kk["x1"], kk["y0"], kk["y1"])):
                    img.putf(k + 16 * q + 4 * m, x)
        return hdr, ts4d.NODE_TABLE2D
    raise ValueError("template value type %r" % v.get("type"))


def build_templates(bt, st):
    by_id = {hexname(r["id"]): r for r in bt["rows"] if r.get("id")}
    order = [by_id[r["id"]] for r in st["rows"]]
    rows_off = 0x40
    img = ts4d.BE(rows_off + ts4d.ROW_STRIDE * len(order))
    for i, r in enumerate(order):
        row = rows_off + i * ts4d.ROW_STRIDE
        tpl = row + 0x18
        h = r["header"]
        img.put32(row + 0x00, hexname(h["row_type"]))
        img.put32(row + 0x04, hexname(r["name_hash"]))
        img.put32(row + 0x08, hexname(h["aim_key_group"]) if h["aim_key_group"] else 0)
        img.put32(row + 0x0C, hexname(h["aim_key_base"]) if h["aim_key_base"] else 0)
        img.put32(row + 0x10, -1)
        img.put32(row + 0x14, -1)
        for field, key, kind in ((0x00, "primary", "kind"), (0x0C, "secondary", "secondary_kind")):
            t, ty = _value(img, r[key])
            img.put32(tpl + field, t - (tpl + field))
            img.put32(tpl + field + 4, ty)
            img.put32(tpl + field + 8, K_KIND[r[kind]])
        for field, key in ((0x18, "vertical_a"), (0x24, "along_c"), (0x30, "lateral_b")):
            sp = r["spin"][key]
            pair = img.alloc(16)
            for m, side in enumerate(("lo", "hi")):
                t, ty = _value(img, sp[side])
                img.put32(pair + 8 * m, t - (pair + 8 * m))
                img.put32(pair + 8 * m + 4, ty)
            img.put32(tpl + field, pair - (tpl + field))
            img.put32(tpl + field + 4, 2)
        img.putf(tpl + 0x3C, r["T"])
        b = r["bounce"]
        for field, key in ((0x40, "speed_loss_vs_spin_a"), (0x4C, "spin_decay_vs_spin_a"),
                           (0x58, "out_elevation_vs_in_elevation_rad"), (0x64, "yaw_kick_vs_spin_b_rad")):
            keys = b[key]
            k = img.alloc(16 * len(keys))
            for j, kk in enumerate(keys):
                for m, x in enumerate((kk["x0"], kk["x1"], kk["y0"], kk["y1"])):
                    img.putf(k + 16 * j + 4 * m, x)
            img.put32(tpl + field, k - (tpl + field))
            img.put32(tpl + field + 4, len(keys))
        img.put32(row + 0x88, hexname(r["id"]))
    return bytes(img.b), rows_off, len(order)


def build_tree(st):
    nodes = []
    for n in sorted(st["tree_nodes"], key=lambda n: n["index"]):
        def child(c):
            return c["node"] if "node" in c else ~int(c["row"])
        nodes.append((n["condition"], child(n["if_true"]), child(n["if_false"])))
    return (0, nodes)


# ============================================================================== tunables and curves
def game_tunables(docs):
    """GAME values the dumps hold, by tunable name (ts4_tunables.def)."""
    t = {}
    bt, st, im, pl = docs.get("ball"), docs.get("tree"), docs.get("input"), docs.get("player")
    if bt:
        bb = bt["ball_block"]
        t.update({"ball.radius_cm": bb["radius_cm_0x4D0"], "ball.a4": bb["a4_0x4D4"], "ball.g": bb["g_0x4D8"],
                  "ball.max_bounces": bb["max_bounces_0x4DC"],
                  "ball.disp_x_lo_cm": bb["wood_dx_cm_0x4C0"][0], "ball.disp_x_hi_cm": bb["wood_dx_cm_0x4C0"][1],
                  "ball.disp_z_lo_cm": bb["wood_dz_cm_0x4C8"][0], "ball.disp_z_hi_cm": bb["wood_dz_cm_0x4C8"][1],
                  "ball.skip_launch_step": bb["skip_launch_step_0x4E0"], "ball.no_sidespin": bb["no_sidespin_0x4E1"]})
        el, yaw, sl, spl = bb["cord_0x494_elev_deg_yaw_deg_speed_loss_spin_loss"]
        t.update({"ball.cord_angle_a_deg": yaw, "ball.cord_angle_b_deg": el, "ball.cord_speed_loss": sl,
                  "ball.cord_spin_loss": spl})
    if st:
        pw = st["power"]
        t.update({"shot.power_divisor_ticks": pw["frequency_D"], "shot.swing_lead_ticks": pw["swing_lead_frames_cfg_0x8c0"],
                  "serve.lead_ticks": pw["serve_lead_frames_cfg_0x8c4"], "serve.input_delay_ticks": pw["serve_input_delay_frames_cfg_0x9a8"],
                  "serve.auto_ticks": pw["serve_auto_frames_cfg_0x9ac"], "serve.release_countdown_ticks": pw["release_countdown_frames_cfg_0x8cc"]})
        ti = st["tier_intervals_on_power"]
        t.update({"shot.tier_medium": ti["Medium"][0][0], "shot.tier_powerful": ti["Powerful"][0][0]})
    if im:
        t["input.stick_dead_zone"] = im["sticks"][0]["dead_zone"]
    if pl:
        n = pl["player_tuning"]["named"]

        def v(k):
            x = n[k]["value"] if isinstance(n[k], dict) and "value" in n[k] else n[k]
            return x
        t["move.rush_guard"] = v("rush_guard")
    return t


def curves(docs):
    cs = []
    st, im, pl = docs.get("tree"), docs.get("input"), docs.get("player")
    if st:
        pw = st["power"]
        cs.append(dict(name="shot.power", type=0, keys=[tuple(k) for k in pw["power_curve_default_cfg_0x8fc"]]))
        cs.append(dict(name="shot.power_alt", type=0, keys=[tuple(k) for k in pw["power_curve_alt_cfg_0x914"]]))
    if im:
        for c in im["serve"]["timing_curves_cfg_0x78c"]:
            if c["serve_animation"] == "2ce33943":
                cs.append(dict(name="serve.timing", type=0, keys=[tuple(k) for k in c["keys_x0_x1_y0_y1"]]))
    if pl:
        n = pl["player_tuning"]["named"]
        for key, name in (("mode_rush", "move.table.rush"), ("mode_jogjog_prepared", "move.table.jogjog"),
                          ("mode_jog_prepared", "move.table.jog")):
            if key in n:
                rows = [(r["key"], [tuple(k) for k in r["curve16"]]) for r in n[key]["value"]["validity_table"]["table2d"]]
                cs.append(dict(name=name, type=2, rows=rows))
    return cs


# ============================================================================== SCAT (swing category rules, G6b)
SC_MODES = ("Normal", "AutoSwingGood", "AutoSwingBad")
SC_CLASSES = ("FlatPower", "FlatFinesse", "Slice", "VolleyStandard", "VolleyPower", "Smash")   # sc_class() order


def enc_scat(rules):
    """shot_tree.yaml swing_category_rules -> SCAT: u32 n_modes, u32 n_classes, (mode, class) x {u32 n, u32 off},
    rows {u32 value, u32 alt, u32 cond, u32 skill, u8 easy_autoswing, 3 pad}; names as crc32 (0 = none)."""
    h = lambda v: 0 if v is None else hexname(v)
    head = struct.pack("<II", len(SC_MODES), len(SC_CLASSES))
    d, body = b"", b""
    base = 8 + 8 * len(SC_MODES) * len(SC_CLASSES)
    for m in SC_MODES:
        for cl in SC_CLASSES:
            rows = ((rules.get("modes") or {}).get(m) or {}).get(cl) or []
            d += struct.pack("<II", len(rows), base + len(body))
            for r in rows:
                body += struct.pack("<IIIIB3x", h(r["value"]), h(r.get("alt")), h(r.get("condition") or "None"),
                                    h(r.get("skill_id")), int(r.get("easy_autoswing") or 0))
    return head + d + body


# ============================================================================== SCLS (shot classes)
CLASS_TABLE_DOC = os.path.join(ROOT, "docs", "gameplay", "graphs-catalogue.md")


def shot_classes_from_doc(path=CLASS_TABLE_DOC):
    """The 33-row shot-class table (Settings 40dd9ee9.00236a48.8c5e64b4, G1) as published in graphs-catalogue.md:
    -> [(name, aiming_index, power_index or -1, [element indices, first live copy])]."""
    out = []
    if not os.path.exists(path):
        return out
    text = open(path, encoding="utf-8").read()
    i = text.find("## Shot-class table")
    if i < 0:
        return out
    for ln in text[i:].split("\n"):
        m = re.match(r"\| (\d+) \| (\w+) \| (\d+) \| ([\d-]+) \| ([\d/, ]+) \|", ln)
        if m:
            els = [int(x.split("/")[0]) for x in m.group(5).split(",") if x.strip()]
            out.append((m.group(2), int(m.group(3)), int(m.group(4)) if m.group(4) != "-" else -1, els))
    return out


def class_of_row(name):
    """Template row name -> (class name, return-of-serve class name). Port policy: the ShotDef row -> class link
    (Settings 761fdece.5f0108a7[i]) is not decoded, so rows are matched to classes by name."""
    tiers = {"Finesse": "Finesse", "Medium": "Medium", "Powerful": "Power", "Normal": "Medium"}
    for st in ("TopSpin", "Slice", "Flat"):
        for t, ct in tiers.items():
            if name == st + t:
                ret = "Return%s%s" % (st, "Finesse" if t == "Finesse" else "Power")
                return st + ct, ret
        if name == st + "Risky":
            return st + "Risk", None
    if name.startswith("Lob"):
        return ("Risk" if name.endswith("Risky") else "Lob"), None
    m = re.match(r"Serve_(TopSpin|Slice|Flat)(Finesse|Medium|Powerful)$", name)
    if m:
        return "Serve%s%s" % ("Flat" if m.group(1) == "Flat" else "Spin", m.group(2)), None
    if name.startswith("Serve_Advanced"):
        return "AdvancedServe", None
    return {"TopSpinVolley": "VolleyStandard", "FlatVolley": "VolleyPower", "SliceVolley": "VolleySlice",
            "DropVolley": "VolleyDrop", "DropShotNormal": "DropShot", "SmashNormal": "Smash"}.get(name), None


def enc_scls(classes, graphs, rows):
    first = {}
    for g in graphs:
        first.setdefault(g["hash"], g["index"])
    live = lambda i: first.get(graphs[i]["hash"], i) if 0 <= i < len(graphs) else -1   # duplicates: first copy runs
    out = struct.pack("<I", len(classes))
    names = [c[0] for c in classes]
    for name, aim, powg, els in classes:
        el = [live(e) for e in els][:12]
        out += struct.pack("<IiiI", crc(name), live(aim), live(powg) if powg >= 0 else -1, len(el))
        out += b"".join(struct.pack("<i", e) for e in el + [-1] * (12 - len(el)))
    out += struct.pack("<I", len(rows))
    for r in rows:
        cn, rn = class_of_row(r["name"])
        out += struct.pack("<ii", names.index(cn) if cn in names else -1, names.index(rn) if rn in names else -1)
    return out


# ============================================================================== pack
FILES = {"graphs": "graphs.yaml", "skills": "traits_skills.yaml", "anim": "animation_rules.yaml",
         "ball": "ball_templates.yaml", "tree": "shot_tree.yaml", "input": "input_map.yaml", "player": "player.yaml",
         "career": "coaches_career.yaml"}


def load_docs(data_dir):
    docs, srcs = {}, {}
    for k, fn in FILES.items():
        p = os.path.join(data_dir, fn)
        if not os.path.exists(p):
            continue
        raw = open(p, "rb").read()
        srcs[fn] = dict(sha256=hashlib.sha256(raw).hexdigest(), size=len(raw))
        if k == "graphs":
            docs[k] = parse_graphs_yaml(raw.decode("utf-8"))
        elif yaml is not None:
            docs[k] = yaml.load(raw, Loader=getattr(yaml, "CSafeLoader", yaml.SafeLoader))
    return docs, srcs


def pack(data_dir):
    docs, srcs = load_docs(data_dir)
    b = ts4d.Blob()
    b.set_tunables(ts4d.provisional_tunables(), provisional=True)
    for k, v in game_tunables(docs).items():
        b.tunables[k] = (float(v), 0)
    report = {}
    if "ball" in docs and "tree" in docs:
        payload, roff, n = build_templates(docs["ball"], docs["tree"])
        b.templates = (payload, roff, n, ts4d.ROW_STRIDE)
        b.tree = build_tree(docs["tree"])
    if "graphs" in docs:
        b.graphs = grph_dicts(docs["graphs"])
        bind, defaults, rep = bind_ports(docs["graphs"], docs.get("skills"), docs.get("anim"))
        b.extra.append((b"BIND", enc_bind(bind)))
        b.extra.append((b"SINI", enc_sini(defaults)))
        report["bind"] = {k: (len(v) if isinstance(v, list) else v) for k, v in rep.items()}
        report["unbound_examples"] = rep["unbound"][:8]
        classes = shot_classes_from_doc()
        if classes and "tree" in docs:
            b.extra.append((b"SCLS", enc_scls(classes, docs["graphs"], docs["tree"]["rows"])))
            report["shot_classes"] = len(classes)
    if "tree" in docs and docs["tree"].get("swing_category_rules"):
        b.extra.append((b"SCAT", enc_scat(docs["tree"]["swing_category_rules"])))
    b.curves = curves(docs) or ts4d.synthetic_curves()
    if "career" in docs:
        b.extra.append((b"AIDF", enc_aidf(docs["career"]["ai_difficulty"]["styles"])))
    if "skills" in docs:
        b.extra.append((b"SKIL", enc_skil(docs["skills"])))
    if "anim" in docs:
        data, t = enc_anim(docs["anim"])
        b.extra.append((b"ANIM", data))
        report["anim"] = dict(clips=len(t["clips"]), groups=len(t["groups"]), subgroups=len(t["subs"]),
                              movesets=len(t["movesets"]))
    return b, srcs, report


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    for name in ("pack", "check"):
        s = sub.add_parser(name)
        s.add_argument("--data", default=os.path.join(ROOT, "data", "gameplay"))
        if name == "pack":
            s.add_argument("--out", required=True)
    a = ap.parse_args(argv)
    b, srcs, rep = pack(a.data)
    if a.cmd == "check":
        print(json.dumps(dict(sources=srcs, report=rep, graphs=len(b.graphs), tunables=len(b.tunables)), indent=1))
        return 0
    blob = b.build()
    with open(a.out, "wb") as f:
        f.write(blob)
    man = dict(tool="port/core/tools/ts4yaml.py", python=sys.version.split()[0],
               pyyaml=getattr(yaml, "__version__", None), out_sha256=hashlib.sha256(blob).hexdigest(),
               out_size=len(blob), sources=srcs, report=rep)
    with open(a.out + ".manifest.json", "w", encoding="utf-8") as f:
        json.dump(man, f, indent=1)
    print("wrote %s (%d bytes; game values: do not commit)" % (a.out, len(blob)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
