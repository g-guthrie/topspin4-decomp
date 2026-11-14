#!/usr/bin/env python3
"""Extract the movement / swing animation selection rules of Top Spin 4 (Xbox 360) to one YAML file.

    python3 -I tools/ts4data/anim_rules.py --core work/disc/core_all [--layout work/disc/root/Layoutall.bin]
            [--names work/disc/values/names.json] [--out data/gameplay/animation_rules.yaml]

Inputs (Core.arc members extracted by name hash, plus the disc's reflection table):
    70155255  AnimationsDB.bin       Pam::SwingAnimation::AnimationDB (root 0xEE710815): 3,184 animations with
                                     Properties (tolerance box, angle clamp, speed coef, mirror), 46 qualifier
                                     bitmasks each (QualifierEnumRawDataArray), transition events (blend windows),
                                     anim groups / sub groups, transition rules and the sub-group transition matrix
    85ff436e  swinganimation.bin     AnimationData root (0x3A60FEE2): qualifier sources, selection procedures
                                     (qualifier filter trees), move-set sector graphs, positioning / miss /
                                     end-of-point lists, planner parameters, animation events
    136bf02a  AnimationsDBcrc.bin    CRC dictionary (animation names)        (optional)
    c6d33a45  CommonCRCDictionnary   CRC dictionary (common names)           (optional)
    Layoutall.bin                    member names, offsets and types of every serialised struct (tools/ts4_xbin.py)

Every member is reached through the generic typed walker (tools/ts4_xbin.py Layout/Walker); this script only
groups the leaves.  The one block the walker does not type is QualifierEnumRawDataArray (an untyped u32 array):
it holds 46 u32 per animation (3,184 x 46 = 146,464 = its count), one bitmask per qualifier type in
QualifierTypes order, bit i = the i-th QualifierValue of that type (checked on the Return/Swing/Transition
families, see docs/gameplay/movement-and-animation.md s4).

Standard library only.  Output stays below 5 MiB.  docs/gameplay/movement-and-animation.md documents every block.
"""
from __future__ import annotations

import argparse
import collections
import hashlib
import os
import re
import struct
import sys
import zlib

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import ts4_xbin as X  # noqa: E402

ANIMDB, SWINGANIM, ANIMDB_CRC, COMMON_CRC = "70155255", "85ff436e", "136bf02a", "c6d33a45"
QUALIFIER_RAW_FIELD = 0x84          # AnimationDB root member QualifierEnumRawDataArray (Layoutall offset)
ROOT_OBJECT = 0x14                  # XBin header is 0x14 bytes; the root object follows

# crc32 preimages found for this file set (verified: zlib.crc32(name) == key).  Most came from combining
# animation-name tokens; they name move-set families, directions and swinganimation.bin members.
EXTRA_NAMES = """
SelectionProcedure SelectionProcedures ConditionProcedure ConditionProcedures KeyXPath SwingSelection
EndOfPointSelection StandardEndOfPoint Swings_Miss PositionParameters RepositioningDirection BlendLoop
AnimationSpeed NextSwing MinHeight MaxHeight AnimationSelection Positioning_Normal Positioning_Swing
Back_LookLeft Back_LookRight Back_TurnLeft Back_TurnRight Steps_Volley_BH Steps_Volley_FH StepsFH StepsBH
MovesServeStart IdleServeStart IdleServe Idle_Serve WalkRight WalkLeft ServeSwing ReturnServeFH ReturnServeBH
Backsteps_FH Backsteps_BH Baseline_Wait_Right Baseline_Wait_Left Stand Volley_Repositioning MissSwing
Sidesteps Idle_Return VolleyServeSwing BaselineServeSwing Idle_Right Idle_Left Volley_Left Volley_Right
GiveUpLeft GiveUpRight FollowNet FollowNet_Right FollowNet_FrontRight Jog_Back Rush_BackLeft Rush_BackRight
Rush_FrontLeft Rush_FrontRight Front FrontLeft FrontRight Left Right Back BackLeft BackRight
FrontFrontLeft LeftFrontLeft LeftBackLeft BackBackLeft BackBackRight RightBackRight RightFrontRight
FrontFrontRight Jog Rush Idle Swing Miss EOP Serve Volley Baseline Smash_FH Smash_BH Steps_FH Steps_BH Jog_FH
Jog_BH Jog_Volley_FH Jog_Volley_BH Volley_Wait_Right Volley_Wait_Left Swings_FH_Jog_Medium InPositioning
EventRacket Preparation Timing Power Control MoveToNet PositionOnCourt SwingEffect SwingType Qualifier
""".split()

BOGUS_NAMES = {"KtSs", "m_ACEGJLOQRTWY"}

SPECIAL_QUALIFIERS = ("Category", "SwingType", "BHType", "SwingEffect", "SwingCategory", "Properties",
                      "PositionOnCourt", "Timing", "Power", "Control", "MoveToNet", "MissType", "Effort",
                      "FollowNet", "Surface", "ServeAndVolley", "SplitSteps", "BadContext", "Setup")


def sha256(b):
    return hashlib.sha256(b).hexdigest()


def load_names(core, names_json):
    names = dict(X.TYPE_NAMES)
    if names_json and os.path.exists(names_json):
        names.update(X.load_names(names_json))
    for key in (ANIMDB_CRC, COMMON_CRC):
        p = os.path.join(core, key + ".bin")
        if os.path.exists(p):
            try:
                for k, v in X.read_crc_dictionary(open(p, "rb").read()).items():
                    names.setdefault(k, v)
            except Exception:  # noqa: BLE001 - optional dictionaries
                pass
    for n in EXTRA_NAMES:
        names.setdefault(zlib.crc32(n.encode()), n)
    # drop dictionary entries that are not identifiers (false hits of the brute-force name search)
    return {k: v for k, v in names.items()
            if re.fullmatch(r"[A-Za-z0-9_][\w .:\-<>/,()\[\]+]*", v) and v not in BOGUS_NAMES}


class Leaves:
    """Walker leaves indexed by path, and by animation index for the Animations list."""

    def __init__(self, data, layout, names):
        w = X.Walker(data, layout, names)
        self.leaves = sorted(w.walk_file(), key=lambda lf: lf.offset)
        self.by_path = {lf.path: lf for lf in self.leaves}
        self.by_anim = collections.defaultdict(list)
        rx = re.compile(r"Animations/Animation\[(\d+)\]/")
        for lf in self.leaves:
            m = rx.match(lf.path)
            if m:
                self.by_anim[int(m.group(1))].append(lf)

    def get(self, path, default=None):
        lf = self.by_path.get(path)
        return default if lf is None else lf.value

    def prefixed(self, prefix):
        return [lf for lf in self.leaves if lf.path.startswith(prefix)]


def count(lv, pattern):
    """Length of a list: pattern is a path regex with one (\\d+) group; probe indexes 0, 1, ... in by_path."""
    fmt = pattern.replace("\\[(\\d+)\\]", "[%d]", 1).replace("\\", "")
    i = 0
    while (fmt % i) in lv.by_path:
        i += 1
    return i


def fnum(v):
    if isinstance(v, float):
        if v != v or v in (float("inf"), float("-inf")):
            return '"%r"' % v
        r = "%.6g" % v
        if "e" not in r and "." not in r:
            r += ".0"
        return r
    return str(v)


def q(s):
    s = str(s)
    if re.fullmatch(r"[A-Za-z_][A-Za-z0-9_.]*", s) and s.lower() not in ("yes", "no", "on", "off", "true",
                                                                          "false", "null", "none"):
        return s
    return '"%s"' % s.replace("\\", "\\\\").replace('"', '\\"')


class Namer:
    def __init__(self, names):
        self.names = names

    def __call__(self, h):
        if h is None:
            return "null"
        if isinstance(h, int):
            return self.names.get(h & 0xFFFFFFFF, "%08x" % (h & 0xFFFFFFFF))
        return str(h)


# ----------------------------------------------------------------------------------------- AnimationsDB
def animdb_blocks(data, lv, n):
    out = {}
    out["parameters"] = {"SpeedCoef": lv.get("Parameters/SpeedCoef"), "EventDuration": lv.get("Parameters/EventDuration")}
    # qualifier types
    nq = count(lv, r"QualifierTypes/Qualifier\[(\d+)\]/Id")
    quals = []
    for i in range(nq):
        nv = count(lv, r"QualifierTypes/Qualifier\[%d\]/QualifierValue\[(\d+)\]/Value" % i)
        vals = [n(lv.get("QualifierTypes/Qualifier[%d]/QualifierValue[%d]/Value" % (i, j))) for j in range(nv)]
        quals.append((n(lv.get("QualifierTypes/Qualifier[%d]/Id" % i)), vals))
    out["qualifiers"] = quals
    # transition event definition
    ted = {}
    for lst, item in (("DirectionList", "Direction"), ("PaceList", "Pace")):
        k = count(lv, r"TransitionEventDefinition/%s/%s\[(\d+)\]/Id" % (lst, item))
        ted[item] = [(n(lv.get("TransitionEventDefinition/%s/%s[%d]/Id" % (lst, item, i))),
                      lv.get("TransitionEventDefinition/%s/%s[%d]/BitIndex" % (lst, item, i)))
                     for i in range(k)]
    out["transition_event_definition"] = ted
    # transition rules (polymorphic list)
    rules = collections.OrderedDict()
    rx = re.compile(r"TransitionRuleList/Element\[(\d+)\]<([^>]*)>/(.*)")
    for lf in lv.leaves:
        m = rx.match(lf.path)
        if m:
            i = int(m.group(1))
            kind = m.group(2).split("::")[-1].replace("TransitionSpecialRule_", "")
            rules.setdefault(i, {"kind": kind})[m.group(3).replace("Parameters/", "")] = lf.value
    out["transition_rules"] = [rules[i] for i in sorted(rules)]
    # groups
    groups = []
    ndesc = count(lv, r"AnimGroupDescList/AnimGroupDesc\[(\d+)\]/Setup")
    for d in range(ndesc):
        pd = "AnimGroupDescList/AnimGroupDesc[%d]/" % d
        ng = count(lv, re.escape(pd) + r"AnimGroupList/AnimGroup\[(\d+)\]/Id")
        for g in range(ng):
            pg = pd + "AnimGroupList/AnimGroup[%d]/" % g
            subs = []
            ns = count(lv, re.escape(pg) + r"SubAnimGroupList/SubAnimGroup\[(\d+)\]/Id")
            for s in range(ns):
                ps = pg + "SubAnimGroupList/SubAnimGroup[%d]/" % s
                subs.append({"id": n(lv.get(ps + "Id")), "condition": lv.get(ps + "ConditionId"),
                             "first": lv.get(ps + "FirstAnimIndex"), "count": lv.get(ps + "AnimCount"),
                             "abs": lv.get(ps + "AbsoluteSubGroupIndex"),
                             "foot": [n(lv.get(ps + "FootstepCategory1")), n(lv.get(ps + "FootstepCategory2"))]})
            groups.append({"setup": n(lv.get(pd + "Setup")), "index": lv.get(pg + "AnimGroupIndex"),
                           "id": n(lv.get(pg + "Id")), "first": lv.get(pg + "FirstAnimIndex"),
                           "count": lv.get(pg + "AnimCount"), "allow_speed_coef": lv.get(pg + "AllowSpeedCoef"),
                           "foot": [n(lv.get(pg + "FootstepCategory1")), n(lv.get(pg + "FootstepCategory2"))],
                           "subgroups": subs})
    out["groups"] = groups
    # transition matrix (sparse)
    mat = [lf.value for lf in lv.leaves if lf.path.startswith("TransitionMatrix/")]
    size = int(round(len(mat) ** 0.5))
    sparse = collections.OrderedDict()
    if size * size == len(mat):
        for i, v in enumerate(mat):
            if v != -1:
                sparse.setdefault(i // size, []).append((i % size, v))
    out["matrix"] = (size, sparse)
    # animations
    nanim = count(lv, r"Animations/Animation\[(\d+)\]/Id")
    root = ROOT_OBJECT
    rel, cnt, _cap = struct.unpack_from(">iII", data, root + QUALIFIER_RAW_FIELD)
    raw_base = root + QUALIFIER_RAW_FIELD + rel
    per = cnt // nanim if nanim else 0
    out["qualifier_raw"] = {"offset": raw_base, "count": cnt, "per_animation": per}
    anims = []
    for a in range(nanim):
        pa = "Animations/Animation[%d]/" % a
        g = lambda k, pa=pa: lv.get(pa + k)  # noqa: E731
        rec = {"i": a, "id": g("Id"), "name": n(g("Id")),
               "frames": g("Properties/FrameCount"), "speed_coef": g("Properties/SpeedCoef"),
               "ignore_speed_coef": g("Properties/IgnoreSpeedCoef"), "no_mirror": g("Properties/NoMirror"),
               "max_occurrence": g("Properties/MaximumOccurency"), "serve_drop_time": g("Properties/ServeDropTime"),
               "setup": n(g("Properties/Setup")), "group": g("Properties/GroupIndex"),
               "subgroup": g("Properties/SubGroupIndex"),
               "tol": [g("Properties/TolerancyUp"), g("Properties/TolerancyDown"), g("Properties/TolerancyXPos"),
                       g("Properties/TolerancyXNeg"), g("Properties/TolerancyZPos"), g("Properties/TolerancyZNeg")],
               "clamp": [g("Properties/AngleClampLeft"), g("Properties/AngleClampRight")]}
        ev = []
        k = 0
        while (pa + "AnimEventList/AnimEvent[%d]/Id" % k) in lv.by_path:
            pe = pa + "AnimEventList/AnimEvent[%d]/" % k
            ev.append((n(lv.get(pe + "Id")), lv.get(pe + "Pos"), lv.get(pe + "Duration"), lv.get(pe + "Orientation")))
            k += 1
        rec["events"] = ev
        tr = []
        k = 0
        while (pa + "TransitionEventList/TransitionEvent[%d]/Position" % k) in lv.by_path:
            pt = pa + "TransitionEventList/TransitionEvent[%d]/" % k
            tr.append([lv.get(pt + f) for f in ("Direction", "Pace", "Position", "Duration", "ReactivityTag",
                                                 "StartBlendTag", "In", "Out")])
            k += 1
        rec["transitions"] = tr
        roty = {}
        aleaves = lv.by_anim.get(a, [])
        for lf in [x for x in aleaves if x.path.startswith(pa + "Element<")]:
            m = re.match(re.escape(pa) + r"Element<[^>]*::([^>]*)>/(\w+)$", lf.path)
            if m:
                roty.setdefault(m.group(1), {})[m.group(2)] = lf.value
        rec["roty"] = roty
        motion = [lf.path[len(pa) + len("MotionData/"):] for lf in aleaves if lf.path.startswith(pa + "MotionData/")
                  if lf.path.endswith("RTTakeIndex")]
        rec["motion"] = sorted({re.sub(r"Pam::SwingAnimation::AnimationDB::MotionOp", "", re.sub(r"\[\d+\]", "", m))
                                .replace("/RTTakeIndex", "") for m in motion})
        if per:
            words = struct.unpack_from(">%dI" % per, data, raw_base + 4 * per * a)
            qs = collections.OrderedDict()
            for qi, w in enumerate(words):
                if qi >= len(quals) or not w:
                    continue
                qn, vals = quals[qi]
                qs[qn] = [vals[b] if b < len(vals) else "bit%d" % b for b in range(32) if w >> b & 1]
            rec["q"] = qs
        anims.append(rec)
    out["animations"] = anims
    return out


# ------------------------------------------------------------------------------------ swinganimation.bin
def xpath_names(data, target, n, limit=64):
    """Named nodes of an XBin path expression: the 0x1C-byte node records {0x10, kind<<16, name crc, ...}."""
    out = []
    o = target
    for _ in range(limit):
        if o + 12 > len(data):
            break
        w0, w1, w2 = struct.unpack_from(">III", data, o)
        if w0 == 0x10 and (w1 & 0xFFFF) == 0 and (w1 >> 16) in (0x27, 0x57):
            out.append(n(w2))
            o += 0x1C
            continue
        if out and w0 == 0xC and w1 == 1 and struct.unpack_from(">I", data, o + 8)[0] == 1:
            break  # next path header
        o += 4
    return out


def swinganim_blocks(data, lv, n):
    out = {}

    def H(path):
        """Hash-spelled path ('ca0f464c/baeeb6a4') -> the walker's spelling (names where known)."""
        return "/".join(n(int(t, 16)) if re.fullmatch(r"[0-9a-f]{8}", t) else t for t in path.split("/"))
    pp = collections.OrderedDict()
    for lf in lv.prefixed("PlannerParameters/"):
        pp[n(int(lf.path.split("/")[1], 16)) if re.fullmatch(r"[0-9a-f]{8}", lf.path.split("/")[1])
           else lf.path.split("/")[1]] = lf.value
    out["planner_parameters"] = pp
    tgt = {}
    for lf in lv.prefixed(H("58c14f98/Target/")):
        k = lf.path.split("/", 2)[2]
        tgt[k] = lf.value
    out["planner_target"] = tgt
    # qualifier sources (61f46389/73873dec/8f3ecd03[i])
    qs = []
    i = 0
    while (H("61f46389/73873dec/8f3ecd03") + "[%d]/QualifierType" % i) in lv.by_path:
        p = H("61f46389/73873dec/8f3ecd03") + "[%d]/" % i
        xp = lv.by_path.get(p + "XPath")
        path = []
        if xp is not None and isinstance(xp.value, tuple):
            path = xpath_names(data, xp.offset + xp.value[0], n)
        qs.append((n(lv.get(p + "QualifierType")), path))
        i += 1
    out["qualifier_sources"] = qs
    # selection procedures (filter trees)
    procs = collections.OrderedDict()
    rx = re.compile(re.escape(H("ca0f464c/baeeb6a4")) + r"\[(\d+)\]/(.*)")
    for lf in lv.leaves:
        m = rx.match(lf.path)
        if not m:
            continue
        i = int(m.group(1))
        rest = m.group(2)
        if rest == "Id":
            procs.setdefault(i, {"id": n(lf.value), "filter": []})["id"] = n(lf.value)
            continue
        procs.setdefault(i, {"id": None, "filter": []})
        procs[i]["filter"].append((rest, lf))
    sp = []
    kinds = {"332e57c4": "match_key", "1ae94a04": "match_key_mask", "00bf4ffc": "equals", "cb3c6c47": "all",
             "d837ca33": "any", "c4cc0a5f": "not"}
    kinds = {H(k): v for k, v in kinds.items()}
    for i in sorted(procs):
        terms = collections.OrderedDict()
        for rest, lf in procs[i]["filter"]:
            node = re.sub(r"Element(\[\d+\])?<([^>]+)>", lambda m: kinds.get(m.group(2), m.group(2)) + (m.group(1) or ""), rest)
            node = node.replace("Filter/", "")
            head, _, field = node.rpartition("/")
            if field in (H("c705d642"), H("59a6a08d"), H("59a0edfc")):
                continue
            v = lf.value
            if lf.tag == "key":
                v = n(v)
            elif field == H("663741be") and isinstance(v, tuple):
                v = "/".join(xpath_names(data, lf.offset + v[0], n))
                field = "KeyXPath"
            terms.setdefault(head, collections.OrderedDict())[field] = v
        sp.append((procs[i]["id"], terms))
    out["selection_procedures"] = sp
    cps = []
    i = 0
    while (H("d693c489/4a0d11f5") + "[%d]/Id" % i) in lv.by_path:
        p = H("d693c489/4a0d11f5") + "[%d]/" % i
        xp = lv.by_path.get(p + "XPath")
        path = xpath_names(data, xp.offset + xp.value[0], n) if xp is not None and isinstance(xp.value, tuple) else []
        cps.append((n(lv.get(p + "Id")), path))
        i += 1
    out["condition_procedures"] = cps

    def sectors(prefix):
        res = []
        k = 0
        while (prefix + "Sector[%d]/" % k + H("b711afc7")) in lv.by_path:
            ps = prefix + "Sector[%d]/" % k
            row = [n(lv.get(ps + H("b711afc7"))), n(lv.get(ps + H("26031a33")))]
            extra = collections.OrderedDict()
            if lv.get(ps + "ToEventIndex"):
                extra["to_event"] = lv.get(ps + "ToEventIndex")
            if lv.get(ps + H("2696cc38")):
                extra["conditional"] = True
            sub = sectors(ps)
            if sub:
                extra["sub"] = sub
            res.append((row, extra))
            k += 1
        return res
    movesets = []
    i = 0
    while (H("e784b9e7/c9a58071") + "[%d]/Id" % i) in lv.by_path:
        p = H("e784b9e7/c9a58071") + "[%d]/" % i
        movesets.append({"id": n(lv.get(p + "Id")), "kind": n(lv.get(p + H("e0af3003"))),
                         "flag": lv.get(p + H("c84c8601")), "sectors": sectors(p)})
        i += 1
    out["movesets"] = movesets
    for key, prefix in (("positioning", H("dd446c94") + "/Animation"), ("miss", "Miss/Animation")):
        lst = []
        i = 0
        while ("%s[%d]/Id" % (prefix, i)) in lv.by_path:
            p = "%s[%d]/" % (prefix, i)
            lst.append({"id": n(lv.get(p + "Id")), "sectors": sectors(p)})
            i += 1
        out[key] = lst
    eop = []
    for lf in lv.leaves:
        m = re.match(re.escape(H("23ff925d")) + r"/(.*?)Sector\[(\d+)\]/" + re.escape(H("b711afc7")) + "$", lf.path)
        if m:
            p = lf.path[:-len(H("b711afc7"))]
            eop.append((m.group(1).rstrip("/"), n(lf.value), n(lv.get(p + H("26031a33")))))
    out["end_of_point"] = eop
    events = []
    i = 0
    while (H("States/InstanceState[0]/f4c77c8e/Event[%d]/Id" % i)) in lv.by_path:
        events.append(n(lv.get(H("States/InstanceState[0]/f4c77c8e/Event[%d]/Id" % i))))
        i += 1
    out["events"] = events
    steps = []
    for lf in lv.leaves:
        m = re.match(re.escape(H("0a40e01e/4a959988")) + r"\[(\d+)\]/Step\[(\d+)\]/(\w+)$", lf.path)
        if m:
            steps.append((int(m.group(1)), int(m.group(2)), n(int(m.group(3), 16)) if re.fullmatch(r"[0-9a-f]{8}", m.group(3))
                          else m.group(3), lf.value))
    out["height_steps"] = steps
    return out


# ------------------------------------------------------------------------------------------------ emit
def emit(o, db, sa, sources, cmd):
    w = o.write
    w("# Top Spin 4 movement and swing animation selection rules (AnimationsDB.bin + swinganimation.bin).\n")
    w("# generated by: %s\n" % cmd)
    for k, (size, h) in sources.items():
        w("# source: %s %d bytes sha256 %s\n" % (k, size, h))
    w("# Docs: docs/gameplay/movement-and-animation.md.  Units: cm, frames (60 Hz), phases 0..1, degrees for clamps.\n")
    w("# Unnamed crc32 keys print as 8 hex digits.  Confidence tags in the doc (V = read from data/code).\n")
    w("generated_by: %s\n" % q(cmd))
    w("parameters: {SpeedCoef: %s, EventDuration: %s}\n" % (fnum(db["parameters"]["SpeedCoef"]),
                                                           fnum(db["parameters"]["EventDuration"])))
    w("\n# 46 qualifier types; a clip carries one bitmask per type (bit i = value i).\nqualifier_types:\n")
    for i, (qn, vals) in enumerate(db["qualifiers"]):
        w("  - {i: %d, id: %s, values: [%s]}\n" % (i, q(qn), ", ".join(q(v) for v in vals)))
    w("\n# Qualifiers the swing selection reads from gameplay (XBin path of the source value).\nqualifier_sources:\n")
    for qn, path in sa["qualifier_sources"]:
        w("  - {qualifier: %s, path: %s}\n" % (q(qn), q("/".join(path))))
    w("\ntransition_event_definition:\n")
    for k, lst in db["transition_event_definition"].items():
        w("  %s: [%s]\n" % (k, ", ".join("%s" % q(a) for a, _b in lst)))
    w("\n# Special transition rules (index = value stored in the sub-group transition matrix).\ntransition_rules:\n")
    for i, r in enumerate(db["transition_rules"]):
        w("  - {i: %d, %s}\n" % (i, ", ".join("%s: %s" % (k, q(v) if isinstance(v, str) else fnum(v)) for k, v in r.items())))
    size, sparse = db["matrix"]
    w("\n# Sub-group -> sub-group transition rule index (absolute sub-group indexes; -1 entries omitted).\n")
    w("transition_matrix:\n  size: %d\n  rows:\n" % size)
    for r, lst in sparse.items():
        w("    %d: [%s]\n" % (r, ", ".join("[%d, %d]" % c for c in lst)))
    w("\n# Animation groups (move families) and sub groups (qualifier-conditioned subsets).\nanim_groups:\n")
    for g in db["groups"]:
        head = "  - {setup: %s, index: %s, id: %s, first: %s, count: %s, allow_speed_coef: %s, foot: [%s]" % (
            q(g["setup"]), g["index"], q(g["id"]), g["first"], g["count"], g["allow_speed_coef"],
            ", ".join(q(x) for x in g["foot"]))
        if g["subgroups"]:
            subs = ["{id: %s, condition: 0x%08x, first: %s, count: %s, abs: %s}" % (
                q(s["id"]), (s["condition"] or 0) & 0xFFFFFFFF, s["first"], s["count"], s["abs"]) for s in g["subgroups"]]
            head += ",\n     subgroups: [\n       " + ",\n       ".join(subs) + "]"
        w(head + "}\n")
    # clip classes
    w("\n# Clip classes: number of animations carrying each qualifier value.\nclip_classes:\n")
    for qn in SPECIAL_QUALIFIERS:
        c = collections.Counter()
        for a in db["animations"]:
            for v in a.get("q", {}).get(qn, []):
                c[v] += 1
        if c:
            w("  %s: {%s}\n" % (q(qn), ", ".join("%s: %d" % (q(k), v) for k, v in sorted(c.items(), key=lambda kv: -kv[1]))))
    w("\n# Per animation: tol = tolerance box [up, down, x+, x-, z+, z-] cm; clamp = facing clamp [left, right] deg;\n")
    w("# tr = transition events [direction mask, pace mask, position, duration, reactivity tag, start-blend tag, in, out];\n")
    w("# ev = [event, phase, duration, orientation]; q = qualifier values (Setup/80ec0b87 defaults omitted).\n")
    w("animations:\n")
    for a in db["animations"]:
        qd = collections.OrderedDict((k, v) for k, v in a.get("q", {}).items() if k not in ("Setup", "80ec0b87"))
        parts = ["i: %d" % a["i"], "name: %s" % q(a["name"]), "frames: %s" % fnum(a["frames"]),
                 "group: %s" % a["group"], "sub: %s" % a["subgroup"], "setup: %s" % q(a["setup"])]
        if a["speed_coef"] != 1.0:
            parts.append("speed_coef: %s" % fnum(a["speed_coef"]))
        if a["ignore_speed_coef"]:
            parts.append("ignore_speed_coef: true")
        if a["no_mirror"]:
            parts.append("no_mirror: true")
        if a["max_occurrence"] not in (None, 0):
            parts.append("max_occ: %s" % a["max_occurrence"])
        if a["serve_drop_time"] not in (None, -1.0):
            parts.append("serve_drop: %s" % fnum(a["serve_drop_time"]))
        parts.append("tol: [%s]" % ", ".join(fnum(x) for x in a["tol"]))
        parts.append("clamp: [%s]" % ", ".join(fnum(x) for x in a["clamp"]))
        if a["motion"]:
            parts.append("motion: [%s]" % ", ".join(q(m) for m in a["motion"]))
        if qd:
            parts.append("\n     q: {%s}" % ", ".join("%s: [%s]" % (q(k), ", ".join(q(x) for x in v)) for k, v in qd.items()))
        if a["events"]:
            parts.append("\n     ev: [%s]" % ", ".join("[%s, %s, %s, %s]" % (q(e[0]), fnum(e[1]), fnum(e[2]), fnum(e[3]))
                                                     for e in a["events"]))
        if a["transitions"]:
            parts.append("\n     tr: [%s]" % ", ".join("[%s]" % ", ".join(fnum(x) if not isinstance(x, bool) else str(int(x))
                                                                         for x in t) for t in a["transitions"]))
        if a["roty"]:
            parts.append("\n     roty: {%s}" % ", ".join("%s: {%s}" % (k, ", ".join("%s: %s" % (kk, fnum(vv))
                                                                                    for kk, vv in v.items()))
                                                      for k, v in a["roty"].items()))
        w("  - {%s}\n" % ", ".join(parts))
    # swinganimation.bin
    w("\n# ------------------------------------------------------------------ swinganimation.bin (AnimationData root)\n")
    w("planner_parameters: {%s}\n" % ", ".join("%s: %s" % (q(k), fnum(v)) for k, v in sa["planner_parameters"].items()))
    w("planner_target: {%s}\n" % ", ".join("%s: %s" % (q(k), fnum(v)) for k, v in sa["planner_target"].items()))
    w("\n# Selection procedures: qualifier filter trees (all / any / not; equals = constant value,\n")
    w("# match_key(_mask) = value read from gameplay through KeyXPath).  Exclusive = the clip must carry only that value.\n")
    w("selection_procedures:\n")
    for pid, terms in sa["selection_procedures"]:
        w("  - id: %s\n    terms:\n" % q(pid))
        for head, fields in terms.items():
            w("      - {node: %s, %s}\n" % (q(head), ", ".join("%s: %s" % (q(k), q(v) if isinstance(v, str) else fnum(v))
                                                             for k, v in fields.items())))
    w("\ncondition_procedures:\n")
    for cid, path in sa["condition_procedures"]:
        w("  - {id: %s, path: %s}\n" % (q(cid), q("/".join(path))))

    def sector_flow(row, extra):
        items = [q(row[0]), q(row[1])]
        ex = []
        for k, v in extra.items():
            if k == "sub":
                ex.append("sub: [%s]" % ", ".join(sector_flow(r, e) for r, e in v))
            else:
                ex.append("%s: %s" % (k, "true" if v is True else v))
        if ex:
            items.append("{%s}" % ", ".join(ex))
        return "[%s]" % ", ".join(items)

    def emit_sectors(secs, ind):
        for row, extra in secs:
            w("%s- %s\n" % (ind, sector_flow(row, extra)))
    w("\n# Move sets: per locomotion family, the directional sectors [family key, direction/target] the\n")
    w("# animation engine picks from the move direction (8 x 45 deg; Volley_Repositioning has 16).\nmovesets:\n")
    for m in sa["movesets"]:
        w("  - id: %s\n    kind: %s\n    flag: %s\n    sectors:\n" % (q(m["id"]), q(m["kind"]), m["flag"]))
        emit_sectors(m["sectors"], "      ")
    for key in ("positioning", "miss"):
        w("\n%s:\n" % key)
        for m in sa[key]:
            w("  - id: %s\n" % q(m["id"]))
            if m["sectors"]:
                w("    sectors:\n")
                emit_sectors(m["sectors"], "      ")
    w("\nend_of_point_sectors:\n")
    for grp, k, t in sa["end_of_point"]:
        w("  - [%s, %s, %s]\n" % (q(grp), q(k), q(t)))
    w("\nanimation_events: [%s]\n" % ", ".join(q(e) for e in sa["events"]))
    w("\n# Player height setups: [setup, step, field, value]\nheight_steps:\n")
    for s in sa["height_steps"]:
        w("  - [%d, %d, %s, %s]\n" % (s[0], s[1], q(s[2]), fnum(s[3])))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--core", default="work/disc/core_all")
    ap.add_argument("--layout", default="work/disc/root/Layoutall.bin")
    ap.add_argument("--names", default="work/disc/values/names.json")
    ap.add_argument("--out", default="data/gameplay/animation_rules.yaml")
    a = ap.parse_args(argv)
    cmd = "python3 -I tools/ts4data/anim_rules.py " + " ".join(argv if argv is not None else sys.argv[1:])
    lay_buf = open(a.layout, "rb").read()
    layout = X.Layout(lay_buf)
    names = load_names(a.core, a.names)
    n = Namer(names)
    db_buf = open(os.path.join(a.core, ANIMDB + ".bin"), "rb").read()
    sa_buf = open(os.path.join(a.core, SWINGANIM + ".bin"), "rb").read()
    db = animdb_blocks(db_buf, Leaves(db_buf, layout, names), n)
    sa = swinganim_blocks(sa_buf, Leaves(sa_buf, layout, names), n)
    sources = collections.OrderedDict([
        ("AnimationsDB.bin (Core.arc 70155255)", (len(db_buf), sha256(db_buf))),
        ("swinganimation.bin (Core.arc 85ff436e)", (len(sa_buf), sha256(sa_buf))),
        ("Layoutall.bin (disc root)", (len(lay_buf), sha256(lay_buf)))])
    os.makedirs(os.path.dirname(a.out) or ".", exist_ok=True)
    with open(a.out, "w") as o:
        emit(o, db, sa, sources, cmd)
    print("%s: %d animations, %d qualifier types, %d groups, %d move sets, %d bytes" % (
        a.out, len(db["animations"]), len(db["qualifiers"]), len(db["groups"]), len(sa["movesets"]),
        os.path.getsize(a.out)))


if __name__ == "__main__":
    main()
