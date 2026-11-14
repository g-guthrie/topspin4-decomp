#!/usr/bin/env python3
"""Extract Top Spin 4 (Xbox 360) skills, coaches, career, pro-player and AI-difficulty tables to YAML.

    python3 -I tools/ts4data/career_data.py --core work/disc/core_all --global work/disc/global \
        --venue work/disc/venue_amst [--layout work/disc/root/Layoutall.bin] \
        [--dll orig/54540859/Swing_DLL.dll] [--out-dir data/gameplay]

Writes two files (docs/gameplay/traits-and-skills.md and stats-coaches-career.md explain them):

  traits_skills.yaml   every player skill ("ability"): code, crc32, English name and description
                       (StringTable keys crc32("Ability<Code>Name"/"Ability<Code>Text")), the coaches that
                       teach it, the pro players that own it, every analyser graph that reads it through a
                       Profile.SkillList[Id == skill].Value link (graph, outputs, the formula lines that depend
                       on the skill and their curve keys) and every code site that tests it (--dll)
  coaches_career.yaml  CoachList (110 coaches: level, play-style flags, abilities and the step at which each
                       is unlocked, objectives, hire conditions), the coach-only abilities (XP and attribute
                       bonuses), PlayerEvolution attribute packs, the AI difficulty table (cfg+0xF0: 9 styles x
                       6 levels, record layout and every component list), and the pro-player database
                       (ratings 0..100, four skills, AI style)

Inputs (members extracted by name hash with tools/ts4_arc.py --extract):
  Core.arc   7e885948 StringTable.bin (English), de208ac7 PlayerList.bin, 623d0979 State.bin,
             fa94f637 Expressions.bin, 334e7e0d Settings.bin, 99c21615 UI.bin
  Global.arc a02aba6e CoachList.bin
  Amsterdam.arc (any venue) e38f72f1 PlayerEvolution.bin
  disc root  Layoutall.bin (type layouts)
Standard library only, plus tools/ts4_xbin.py, tools/ts4_layout.py and tools/ts4_analyser.py.
Optional: data/gameplay/analyser_names.json (graph/member names, used when present).
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
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, os.path.dirname(HERE))
sys.path.insert(0, HERE)
import ts4_xbin as X  # noqa: E402
import ts4_layout as L  # noqa: E402
import ts4_analyser as A  # noqa: E402
from player_data import to_yaml  # noqa: E402

STRINGTABLE_EN, PLAYERLIST, STATE, EXPRESSIONS, SETTINGS, UIBIN = (
    "7e885948", "de208ac7", "623d0979", "fa94f637", "334e7e0d", "99c21615")
COACHLIST, PLAYEREVOLUTION = "a02aba6e", "e38f72f1"

# The 30 skills of State.bin PlayerState.Profile.SkillList (in list order) and the two UI-only ones.
SKILLS = ("PowerfulShotCounter ReachSwingsExpert PassingShotSniper SpectacularVolleys BetterOnLongRallies "
          "HighlyFlammable PoisonedSlices DieselReturner InstantRocket DieselHardHitter InsideOutMaster FocusService "
          "WrongFootExpert Amazing1stVolley SliceInvasion TopSpinInvasion CrushingPassingShot Fatality "
          "ApproachShotsExpert TenaciousCockroach SemiVolleyKing DieselServer SpinServeMaster VolleyShotsArtist "
          "LowVolleySpecialist SmellOfBlood ReturnServeCounter ServeStickBerserker DropShotArtist BrutalVolley").split()
UI_ONLY_SKILLS = ["Return6thSense", "EmergencyReactivity"]
COACH_ONLY = ["GeneralXPBonus", "GeneralMaxiXPBonus", "VolleyXPBonus", "BaselineXPBonus", "_AttributeBonus"]
ATTRS = ["Serve", "Return", "Reflex", "Forehand", "Backhand", "Volley", "Power", "Speed", "Stamina", "Mental", "Overall"]

WORDS = (SKILLS + UI_ONLY_SKILLS + COACH_ONLY + ATTRS + [
    "CoachList", "Coach", "Ability", "Key", "Efficiency", "Code", "TypeKey", "NameKey", "TextKey", "ValueList", "Value",
    "Level", "Index", "PlaystyleDefensive", "PlaystyleOffensive", "PlaystyleServe", "ObjectiveList", "Objective",
    "GoalValue", "Gender", "Element", "Condition", "ReasonKey", "Player", "AttributeList", "Skill1", "Skill2",
    "Skill3", "Skill4", "Id", "MainInfo", "Plays", "Phase", "Type", "Visible", "Locked", "PlayerCode", "AI", "AIStyle",
    "Difficulty", "Expression", "Default", "PlayerStates", "PlayerState", "Profile", "SkillList", "Skill",
    "StringList", "StringId", "AttributePack", "LevelList", "Attribute", "LevelValue", "Percent", "Male", "Female",
    "Any", "RightHanded", "LeftHanded", "AllAround", "BaselineAttacker", "BaselineController", "VolleyFinessePlayer",
    "None", "VeryEasy", "Easy", "Normal", "Hard", "VeryHard", "Expert", "Repositioning", "Positioning",
    "AIStyle_AllRounder", "AIStyle_BaselineAttacker", "AIStyle_ServeAndVolley", "AIStyle_BaselineController",
    "ProfileAI", "PlayStyleAI", "Height", "Weight", "Nation", "SignatureStyle", "Surface"] +
    ["Pam::System::Conditions::" + t for t in (
        "LesserThanType", "GreaterThanType", "EqualityOperatorType", "AndType", "OrType", "NotType",
        "ComparableExpressionChoice_Int32", "ComparableExpressionChoice_XPath_Int32", "ExpressionChoice_Int32",
        "ExpressionChoice_XPath_Int32")])
NAMES = {zlib.crc32(w.encode()): w for w in WORDS}
SKILL_CRC = {zlib.crc32(s.encode()): s for s in SKILLS + UI_ONLY_SKILLS}

# Member names that have no recovered preimage (stable hex keys used below).
H_ABILITY_TABLE = "61366de0"      # CoachList root: list<Ability> (coach-only abilities: XP and attribute bonuses)
H_CODE = "a22c9d3e"               # string member holding the code name (Coach1, PointsPlayed ...)
H_HIRE_COND = "d91b4d80"          # Coach: hire / availability conditions
H_KEEP_COND = "552a0aa2"          # Coach: second condition list (I: conditions to keep or level the coach)
H_COACH_KIND = "62ee15d9"
H_PROFILE_AI = "94d1c042"         # Player.AttributeList: AI style group key (= crc32 "ProfileAI" field name)
H_PLAYSTYLE_AI = "8f276f29"       # Player.AttributeList: play style name ("PlayStyleAI")
H_PROFILE_AI2 = "a017b472"

# AI difficulty record (Settings type 0x59CCA053, 0x5C bytes; element type 0xDDF0C247, 0x10 bytes)
AI_LIST_FIELDS = [(0x00, "f8bde3bf"), (0x0C, "0a7a82d5"), (0x18, "2693de78"), (0x24, "ef9ce04a"), (0x30, "0b4e23b3")]
AI_GRAPH_FIELDS = [
    (0x40, "bab5b3f4", "TimingExpression", "timing object (fn_886B71A0)", "ShotContext.ManualShotTiming"),
    (0x44, "7bcf55ee", None, "AI brain +0x1E0 (fn_886B6F2C)", "ReceiverState.AimingState.FinalEfficiency"),
    (0x48, "714e0b0b", None, "AI brain +0x158", "#3237ffac.Score (ground hit-point score)"),
    (0x4C, "39b3b9e2", None, "AI brain +0x19C", "#3237ffac.Score (second hit-point score)"),
    (0x50, "6b696700", None, "AI brain +0x224", "SwingSelection.EvaluationOutputs.#4abbb588"),
    (0x54, "98fff83e", None, "AI brain +0x268", "AI record #a9a83d2d.SwingReactionTime (+0x1C0)"),
]
AI_SKILL_FIELD = (0x58, "41d66350", "run-speed limit m/s replacing PT+0x230 during the AI search (fn_8869AEF8)")

# PlayerState fields that code sets from a skill test; graphs reading them are indirect skill consumers.
INDIRECT = {0x7D0: ("PoisonedSlices", "B+0x164 set by fn_88695640: incoming ball is a PoisonedSlices slice"),
            0xE00: ("InstantRocket", "power charge value written by fn_8869D720 with the InstantRocket curve")}

# Code sites that test a skill directly (HasSkill = fn_8868F0D8: S+0x640 list entry with Value == 1.0).
CODE_NOTES = {
    0x88695B24: ("fn_88695640", "PoisonedSlices",
                 "shot evaluation block B = S+0x66C (called from fn_886AE528): B+0x164 (= S+0x7D0) = 1.0 when the "
                 "incoming ball is a Slice (+0x60 == crc32 Slice) hit by a player who has PoisonedSlices, else 0; the "
                 "receiver's shot graphs read S+0x7D0 as PlayerState.#7e28dbc0.#aee2d90b"),
    0x8869D750: ("fn_8869D720", "InstantRocket",
                 "power charge: S+0xE00 = curve(cfg+0x914) instead of curve(cfg+0x8FC) of S+0xDFC/rate and "
                 "S+0xE08 = curve(cfg+0x920) instead of curve(cfg+0x908) of S+0xE04/rate (cfg = Settings root)"),
    0x886BD564: ("fn_886BCE88", "SpectacularVolleys",
                 "stroke start: S+0x388 (bool) = has SpectacularVolleys && geometric/volley conditions; then the "
                 "rule analysers at controller+0x1D4/+0x218 run"),
}


def sha256(b):
    return hashlib.sha256(b).hexdigest()


def load(d, key, required=True):
    p = os.path.join(d, key + ".bin")
    if not os.path.exists(p):
        if required:
            sys.exit("missing %s (extract that archive member first)" % p)
        return None
    return open(p, "rb").read()


def hx(v):
    return "%08x" % v


def nm(h):
    return NAMES.get(h) or hx(h)


# ------------------------------------------------------------------------------------------- generic walk

class Tree:
    """Walker leaves of one XBin file, indexed by path."""

    def __init__(self, buf, layout):
        self.buf = buf
        w = X.Walker(buf, layout, NAMES)
        w.walk_file()
        self.leaves = w.leaves

    def iter(self, pattern):
        rx = re.compile(pattern)
        for lf in self.leaves:
            m = rx.match(lf.path)
            if m:
                yield m, lf

    def wstring(self, lf):
        """UTF-16BE string at a self-relative 'rel' leaf."""
        p = lf.offset + lf.value
        e = p
        while self.buf[e:e + 2] != b"\0\0":
            e += 2
        return self.buf[p:e].decode("utf-16-be", "replace")


def leaf_value(lf):
    v = lf.value
    if lf.tag == "key":
        return nm(v)
    if lf.tag in ("string", "path"):
        return v[1] if isinstance(v, tuple) else None
    if lf.tag == "float":
        return round(v, 6)
    return v


def string_table(buf, layout):
    t = Tree(buf, layout)
    ids, vals = {}, {}
    for m, lf in t.iter(r"StringList/StringId\[(\d+)\]/(Id|Element<[0-9a-f]+>/Value)$"):
        i = int(m.group(1))
        if m.group(2) == "Id":
            ids[i] = lf.value
        elif lf.tag == "rel":
            vals[i] = t.wstring(lf)
    return {ids[i]: vals.get(i, "") for i in ids}


def text(st, key):
    return st.get(zlib.crc32(key.encode()) if isinstance(key, str) else key)


# ------------------------------------------------------------------------------------------- CoachList

def coach_list(buf, layout, st):
    t = Tree(buf, layout)
    abilities = {}
    for m, lf in t.iter(r"%s/Ability\[(\d+)\]/(.*)$" % H_ABILITY_TABLE):
        a = abilities.setdefault(int(m.group(1)), {"values": []})
        f = m.group(2)
        if f.startswith("ValueList/Value["):
            j = int(f.split("[")[1].split("]")[0])
            while len(a["values"]) <= j:
                a["values"].append({})
            a["values"][j]["key" if f.endswith("/Key") else "value"] = leaf_value(lf)
        elif f in ("NameKey", "TextKey"):
            a[f] = lf.value
        else:
            a[f] = leaf_value(lf)
    ability_defs = []
    by_key = {}
    for i in sorted(abilities):
        a = abilities[i]
        code = a.get(H_CODE)
        code = a.get("Code", code)
        d = {"index": i, "key": a.get("Key"), "code": code, "type": a.get("TypeKey"),
             "name": st.get(a.get("NameKey")), "text": st.get(a.get("TextKey")),
             "values": {v.get("key"): v.get("value") for v in a["values"]}}
        ability_defs.append(d)
        by_key[a.get("Key")] = d

    coaches = {}
    for m, lf in t.iter(r"CoachList/Coach\[(\d+)\]/(.*)$"):
        c = coaches.setdefault(int(m.group(1)), {"abilities": [], "objectives": {}, "conditions": {}})
        f = m.group(2)
        mm = re.match(r"%s/Ability\[(\d+)\]/(Key|Efficiency)$" % H_ABILITY_TABLE, f)
        if mm:
            j = int(mm.group(1))
            while len(c["abilities"]) <= j:
                c["abilities"].append({})
            c["abilities"][j][mm.group(2)] = lf.value
            continue
        mm = re.match(r"ObjectiveList/Objective\[(\d+)\]/(.*)$", f)
        if mm:
            o = c["objectives"].setdefault(int(mm.group(1)), {})
            g = mm.group(2)
            if g == H_CODE:
                o["code"] = leaf_value(lf)
            elif g.endswith("GoalValue"):
                o["goal"] = lf.value
            elif g == "NameKey":
                o["text"] = st.get(lf.value)
            elif g == "Gender":
                o["gender"] = leaf_value(lf)
            continue
        mm = re.match(r"(%s|%s)/Condition\[(\d+)\]/(.*)$" % (H_HIRE_COND, H_KEEP_COND), f)
        if mm:
            lst = "hire" if mm.group(1) == H_HIRE_COND else "second"
            o = c["conditions"].setdefault((lst, int(mm.group(2))), {"list": lst})
            g = mm.group(3)
            if g == "ReasonKey":
                o["reason"] = st.get(lf.value) or hx(lf.value)
            elif g.endswith("ExpressionChoice_Int32>/Value"):
                ops = [x.split("::")[-1].replace("Type", "") for x in re.findall(r"Element<([^>]+)>", g)
                       if "Choice" not in x]
                o.setdefault("tests", []).append({"op": "/".join(ops), "value": lf.value})
            continue
        if f == H_CODE:
            c["code"] = leaf_value(lf)
        elif f in ("Key", "Level", "Index", "PlaystyleDefensive", "PlaystyleOffensive", "PlaystyleServe", H_COACH_KIND):
            c[f] = leaf_value(lf) if f != "Key" else lf.value
    out = []
    for i in sorted(coaches):
        c = coaches[i]
        code = c.get("code")
        styles = [s for s in ("Defensive", "Offensive", "Serve") if c.get("Playstyle" + s)]
        abil = []
        for a in c["abilities"]:
            k = a.get("Key")
            e = {"key": nm(k), "unlock_step": a.get("Efficiency")}
            if k in SKILL_CRC:
                e["skill"] = SKILL_CRC[k]
            elif hx(k) in by_key or nm(k) in by_key:
                d = by_key.get(hx(k)) or by_key.get(nm(k))
                e["ability"] = d["code"]
                e["values"] = d["values"]
            abil.append(e)
        conds = []
        for (_lst, _j), o in sorted(c["conditions"].items()):
            conds.append({k: o[k] for k in ("list", "tests", "reason") if k in o})
        out.append({"index": i, "code": code, "name": text(st, "Coach%sName" % code) if code else None,
                    "level": c.get("Level"), "playstyle": styles, "kind": c.get(H_COACH_KIND),
                    "abilities": abil,
                    "objectives": [c["objectives"][j] for j in sorted(c["objectives"])],
                    "conditions": conds})
    return ability_defs, out


# ------------------------------------------------------------------------------------------- PlayerList

def player_list(buf, layout):
    t = Tree(buf, layout)
    rows = {}
    for m, lf in t.iter(r"Player\[(\d+)\]/(AttributeList/(\w+)(/Value|/Id)?|Code|MainInfo/(Gender|Plays))$"):
        r = rows.setdefault(int(m.group(1)), {})
        if m.group(2) == "Code":
            r["code"] = leaf_value(lf)
        elif m.group(5):
            r[m.group(5).lower()] = leaf_value(lf)
        else:
            r[m.group(3)] = leaf_value(lf)
    out = []
    for i in sorted(rows):
        r = rows[i]
        if not r.get("code") or r["code"] == "DlcPlaceholder":
            continue
        skills = [r.get("Skill%d" % k) for k in range(1, 5)]
        out.append({"code": r["code"], "gender": r.get("gender"), "plays": r.get("plays"),
                    "ratings": [r.get(a) for a in ATTRS],
                    "skills": [s for s in skills if s and s != "00000000"],
                    "ai_style": r.get("ProfileAI", r.get(H_PROFILE_AI)),
                    "play_style": r.get("PlayStyleAI", r.get(H_PLAYSTYLE_AI))})
    return out


# ------------------------------------------------------------------------------------------- PlayerEvolution

def player_evolution(buf, layout):
    t = Tree(buf, layout)
    packs = {}
    scalars = {}
    for m, lf in t.iter(r"([0-9a-f]{8})/AttributePack\[(\d+)\]/(.*)$"):
        p = packs.setdefault(int(m.group(2)), {"levels": {}})
        f = m.group(3)
        mm = re.match(r"LevelList/Level\[(\d+)\]/(.*)$", f)
        if mm:
            lv = p["levels"].setdefault(int(mm.group(1)), {"attrs": {}})
            g = mm.group(2)
            if g == "Value":
                lv["level"] = lf.value
            else:
                m2 = re.match(r"AttributeList/Attribute\[(\d+)\]/(Key|[0-9a-f]{8})$", g)
                if m2:
                    lv.setdefault("_a", {}).setdefault(int(m2.group(1)), {})[m2.group(2)] = leaf_value(lf)
        else:
            p["style"] = leaf_value(lf)
    for m, lf in t.iter(r"([0-9a-f]{8})(/.*)?$"):
        if "AttributePack" not in lf.path:
            scalars[lf.path] = leaf_value(lf)
    out = []
    for i in sorted(packs):
        p = packs[i]
        levels = []
        for j in sorted(p["levels"]):
            lv = p["levels"][j]
            gains = {}
            for k in sorted(lv.get("_a", {})):
                e = lv["_a"][k]
                val = [v for kk, v in e.items() if kk != "Key"]
                gains[e.get("Key")] = val[0] if val else None
            levels.append({"level": lv.get("level"), "gain": gains})
        out.append({"style": p.get("style"), "levels": levels})
    return {"packs": out, "scalars": scalars}


# ------------------------------------------------------------------------------------------- AI difficulty

# AI style group keys of the AI difficulty table (cfg+0xF0).  V = crc32 of the name matches the key;
# I = named by the players that use it (PlayerList AttributeList.ProfileAI); U = unnamed.
AI_STYLE_NAMES = {
    "c3e11a56": ("AIStyle_BaselineAttacker", "V", "crc32"),
    "8c1c3a3b": ("AIStyle_ServeAndVolley", "V", "crc32"),
    "ea55dbac": ("AIStyle_AllRounder", "V", "crc32"),
    "824ec12e": ("baseline controller group", "I",
                 "ProfileAI of the pros with PlayStyleAI BaselineController (and None); "
                 "crc32('AIStyle_BaselineController') = 529c7951 is a different key (Style struct member only)"),
    "75c6d60c": ("default / generic group", "I", "value of the per-player field a017b472 of every PlayerList entry"),
    "ad2283af": ("Ralley1 style", "I", "ProfileAI of PlayerList player Ralley1 (rally-partner players)"),
    "1182486a": ("Ralley2 style", "I", "ProfileAI of PlayerList player Ralley2"),
    "0a8ac661": ("Ralley3 style", "I", "ProfileAI of PlayerList player Ralley3"),
    "d858c9fb": ("Ralley4 style", "I", "ProfileAI of PlayerList player Ralley4"),
}


def ai_table(settings, layout, graphs_by_hash, bind, namer):
    t = Tree(settings, layout)
    styles = {}
    for m, lf in t.iter(r"<[0-9a-f]+>/AI/[0-9a-f]{8}/[0-9a-f]{8}/AIStyle\[(\d+)\]/(Id|Difficulty\[(\d+)\]/(.*))$"):
        s = styles.setdefault(int(m.group(1)), {"levels": {}})
        if m.group(2) == "Id":
            s["style"] = leaf_value(lf)
            continue
        d = s["levels"].setdefault(int(m.group(3)), {"lists": {}})
        f = m.group(4)
        mm = re.match(r"([0-9a-f]{8})/[0-9a-f]{8}\[(\d+)\]/(\w+)$", f)
        if mm:
            e = d["lists"].setdefault(mm.group(1), {}).setdefault(int(mm.group(2)), {})
            e[mm.group(3)] = leaf_value(lf) if lf.tag != "key" else lf.value
        else:
            d[f] = leaf_value(lf) if lf.tag != "key" else lf.value

    def graph_out(h):
        g = graphs_by_hash.get(h)
        if g is None:
            return None
        labs = []
        for p in g.outputs:
            labs.append(A.port_label(p, bind, namer))
        return sorted(set(labs))

    list_role = {}
    out = []
    for i in sorted(styles):
        s = styles[i]
        levels = []
        for j in sorted(s["levels"]):
            d = s["levels"][j]
            rec = {"level": nm(d.get("Id", 0))}
            for off, h, name, consumer, _role in AI_GRAPH_FIELDS:
                v = d.get(h)
                rec["g%02x" % off] = hx(v) if isinstance(v, int) else v
            rec["run_speed_limit"] = d.get(AI_SKILL_FIELD[1])
            lists = {}
            for off, h in AI_LIST_FIELDS:
                rows = []
                for k in sorted(d["lists"].get(h, {})):
                    e = d["lists"][h][k]
                    gh = e.get("4882ebbb")
                    rows.append({"component": nm(e.get("Expression", 0)) if isinstance(e.get("Expression"), int)
                                 else e.get("Expression"), "graph": hx(gh) if isinstance(gh, int) else gh,
                                 "weight": e.get("782f2ee9"), "default": e.get("Default"), "flag": e.get("ee04af9f")})
                    if isinstance(gh, int):
                        o = graph_out(gh)
                        if o:
                            list_role.setdefault(off, set()).update(o)
                lists["l%02x" % off] = rows
            rec["lists"] = lists
            levels.append(rec)
        st = s.get("style")
        nmc = AI_STYLE_NAMES.get(st) or AI_STYLE_NAMES.get("%08x" % zlib.crc32(str(st).encode()),
                                                            (None, "U", "no candidate matched"))
        out.append({"style": st, "name": nmc[0], "confidence": nmc[1], "evidence": nmc[2], "levels": levels})
    roles = {"l%02x" % off: sorted(v) for off, v in sorted(list_role.items())}
    return out, roles


# ------------------------------------------------------------------------------------------- skill links in graphs

def _u32(b, o):
    return struct.unpack_from(">I", b, o)[0]


def _s32(b, o):
    return struct.unpack_from(">i", b, o)[0]


def link_qualifiers(buf, port):
    """Leaf names and constant qualifiers (node kind 0x001Axxxx) of a link-bound port's name-path tree."""
    leaves, quals = [], []

    def visit(a, depth):
        rel, typ = _s32(buf, a), _u32(buf, a + 4)
        node = a + rel
        if typ == 0x67860A08:
            leaves.append(_u32(buf, node + 8))
            return
        if depth > 16 or node + 16 > len(buf):
            return
        size, kind = _u32(buf, node), _u32(buf, node + 4)
        if size == 8:
            r, c = _s32(buf, node + 8), _u32(buf, node + 12)
            if r != -1 and c < 64:
                for i in range(c):
                    visit(node + 8 + r + 8 * i, depth + 1)
        elif kind >> 16 == 0x001A:
            quals.append(_u32(buf, node + 8))
    tgt = port.offset + 4 + _s32(buf, port.offset + 4)
    r, c = _s32(buf, tgt), _u32(buf, tgt + 4)
    if r != -1:
        for i in range(c):
            visit(tgt + r + 8 * i, 0)
    return leaves, quals


def node_inputs(n):
    f = n.fields
    if n.kind == "CURVE":
        return [f["in"]]
    if n.kind in A.VARIADIC:
        return list(f["slots"])
    if n.kind in ("SUB", "DIV"):
        return [f["a"], f["b"]]
    if n.kind in ("LERP", "INVLERP"):
        return [f["a"], f["b"], f["t"]]
    return []


def forward_slice(g, seeds):
    """Registers that depend on any seed register, and the nodes on that path."""
    dep = set(seeds)
    nodes = []
    for n in g.nodes:
        ins = node_inputs(n)
        if any(r in dep for r in ins):
            for w in n.writes():
                dep.add(w)
            nodes.append(n)
    return dep, nodes


def skill_consumers(expr, bind, namer, curve_mode="ramp"):
    graphs = A.parse_expressions(expr)
    by_skill = {}
    other_links = []
    for gi, g in enumerate(graphs):
        labels, seeds = [], {}
        for p in g.inputs:
            if p.index == -1:
                lv, q = link_qualifiers(expr, p)
                qn = [SKILL_CRC.get(x) or nm(x) for x in q]
                if q and q[0] in SKILL_CRC and zlib.crc32(b"SkillList") in lv:
                    labels.append("skill[%s]" % SKILL_CRC[q[0]])
                    seeds.setdefault((SKILL_CRC[q[0]], None), set()).add(p.slot)
                else:
                    labels.append("%s<link %s>" % (".".join(namer(x) for x in lv), "/".join(qn)))
                    other_links.append((gi, hx(g.name), ".".join(namer(x) for x in lv), qn))
            else:
                labels.append(A.port_label(p, bind, namer))
                b = bind.bind(p)
                if b and b["domain"] == "PlayerState" and b["offset"] in INDIRECT:
                    sk, note = INDIRECT[b["offset"]]
                    seeds.setdefault((sk, "S+0x%X (%s)" % (b["offset"], note)), set()).add(p.slot)
        if not seeds:
            continue
        lines, outs = A.graph_formula(g, labels)
        line_of = {}
        k = 0
        for n in g.nodes:
            if n.kind is None:
                continue
            for w in n.writes():
                line_of.setdefault(id(n), []).append(lines[k])
                k += 1
        curves = {}
        cn = 0
        for n in g.nodes:
            if n.kind == "CURVE":
                cn += 1
                # ramp (default, fn_88179740 fixup): y0 at x0 -> y1 at x1; step: flat y0
                curves[id(n)] = ("curve%d" % cn, [[round(x, 6) for x in (
                    key[0], key[1], key[2], key[4] if curve_mode == "ramp" else key[2])]
                    for key in n.fields["keys"]])
        out_labels = [A.port_label(p, bind, namer) for p in g.outputs]
        writer = {}
        for n in g.nodes:
            for w in n.writes():
                writer[w] = n
        for (skill, via), slots in seeds.items():
            dep, nodes = forward_slice(g, slots)
            ctx = []          # defining nodes of the other operands (two levels back): the with/without values
            seen = set(id(n) for n in nodes)
            frontier = [r for n in nodes if set(node_inputs(n)) & set(slots) for r in node_inputs(n) if r not in dep]
            for _depth in range(2):
                nxt = []
                for r in frontier:
                    n = writer.get(r)
                    if n is None or id(n) in seen:
                        continue
                    seen.add(id(n))
                    ctx.append(n)
                    nxt.extend(node_inputs(n))
                frontier = nxt
            order = {id(n): i for i, n in enumerate(g.nodes)}
            fl, cv, cx = [], {}, []
            for n in sorted(ctx, key=lambda n: order[id(n)]):
                for t_, v in line_of.get(id(n), []):
                    cx.append("%s = %s" % (t_, v))
                if id(n) in curves:
                    cv[curves[id(n)][0]] = curves[id(n)][1]
            for n in nodes:
                for t_, v in line_of.get(id(n), []):
                    fl.append("%s = %s" % (t_, v))
                if id(n) in curves:
                    cv[curves[id(n)][0]] = curves[id(n)][1]
            affected = [out_labels[i] for i, p in enumerate(g.outputs) if p.slot in dep]
            e = {"via": via} if via else {}
            by_skill.setdefault(skill, []).append(dict(e, **{
                "graph_index": gi, "graph": hx(g.name), "graph_name": namer(g.name),
                "outputs_affected": affected, "skill_registers": sorted(slots),
                "operands": cx, "formula_slice": fl, "curves": cv}))
    return by_skill, other_links, graphs


# ------------------------------------------------------------------------------------------- code sites

def code_sites(dll):
    b = dll
    e = struct.unpack_from("<I", b, 0x3C)[0]
    ns = struct.unpack_from("<H", b, e + 6)[0]
    osz = struct.unpack_from("<H", b, e + 20)[0]
    base = struct.unpack_from("<I", b, e + 24 + 28)[0]
    sec = e + 24 + osz
    text = None
    for i in range(ns):
        name, vs, va, rs, rp = struct.unpack_from("<8sIIII", b, sec + 40 * i)
        if name.startswith(b".text"):
            text = (base + va, rp, rs)
    tva, trp, tsz = text
    want = {}
    for s in SKILLS + UI_ONLY_SKILLS + COACH_ONLY[:4]:
        c = zlib.crc32(s.encode())
        want[(c >> 16, c & 0xFFFF)] = s
    words = struct.unpack_from(">%dI" % (tsz // 4), b, trp)
    out = []
    for i, w in enumerate(words):
        if w >> 26 != 24:          # ori
            continue
        for k in range(1, 12):
            if i - k < 0:
                break
            w2 = words[i - k]
            if w2 >> 26 == 15 and (w2 >> 16) & 31 == 0 and (w2 & 0xFFFF, w & 0xFFFF) in want:
                s = want[(w2 & 0xFFFF, w & 0xFFFF)]
                a = tva + 4 * i
                f = i
                while f > 0 and words[f] != 0x7D8802A6:   # mflr r12: function prologue
                    f -= 1
                out.append({"skill": s, "address": "0x%08X" % a, "function": "fn_%08X" % (tva + 4 * f)})
                break
    return out


# ------------------------------------------------------------------------------------------- main

def write_yaml(path, header, data):
    with open(path, "w") as f:
        f.write(header)
        f.write("\n".join(to_yaml(data)) + "\n")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--core", default="work/disc/core_all")
    ap.add_argument("--global", dest="glob", default="work/disc/global")
    ap.add_argument("--venue", default="work/disc/venue_amst")
    ap.add_argument("--layout", default="work/disc/root/Layoutall.bin")
    ap.add_argument("--dll", default=None)
    ap.add_argument("--names", default=os.path.join(ROOT, "data/gameplay/analyser_names.json"))
    ap.add_argument("--out-dir", default="data/gameplay")
    ap.add_argument("--curve-mode", choices=("ramp", "step"), default="ramp",
                    help="curve keys as runtime ramps (default; fixup fn_88179740, graphs-decoded.md) or stored steps")
    a = ap.parse_args(argv)

    layout_buf = open(a.layout, "rb").read()
    layout = X.Layout(layout_buf)
    src = {}

    def get(d, key, label, required=True):
        b = load(d, key, required)
        if b is not None:
            src["%s (%s)" % (label, key)] = sha256(b)
        return b
    st_buf = get(a.core, STRINGTABLE_EN, "StringTable.bin English")
    plist = get(a.core, PLAYERLIST, "PlayerList.bin")
    state = get(a.core, STATE, "State.bin")
    expr = get(a.core, EXPRESSIONS, "Expressions.bin")
    settings = get(a.core, SETTINGS, "Settings.bin")
    coach = get(a.glob, COACHLIST, "CoachList.bin")
    evo = get(a.venue, PLAYEREVOLUTION, "PlayerEvolution.bin")
    src["Layoutall.bin"] = sha256(layout_buf)
    dll = open(a.dll, "rb").read() if a.dll else None
    if dll:
        src["Swing_DLL.dll"] = sha256(dll)

    names = A.load_name_table(a.names) if a.names and os.path.exists(a.names) else {}
    namer = A.Namer(names)
    bind = A.Bindings(state, layout_buf)

    st = string_table(st_buf, layout)
    ability_defs, coaches = coach_list(coach, layout, st)
    pros = player_list(plist, layout)
    by_skill, other_links, graphs = skill_consumers(expr, bind, namer, a.curve_mode)
    ai, roles = ai_table(settings, layout, {g.name: g for g in graphs}, bind, namer)
    evolution = player_evolution(evo, layout)
    sites = code_sites(dll) if dll else []

    # State.bin skill list order (PlayerState[0].Profile.SkillList)
    tstate = Tree(state, layout)
    order = [leaf_value(lf) for m, lf in tstate.iter(r".*PlayerState\[0\]/Profile/SkillList/Skill\[\d+\]/Id$")]

    skills = []
    for s in SKILLS + UI_ONLY_SKILLS:
        c = zlib.crc32(s.encode())
        teach = [{"coach": co["code"], "name": co["name"], "level": co["level"], "playstyle": co["playstyle"],
                  "unlock_step": ab["unlock_step"]}
                 for co in coaches for ab in co["abilities"] if ab.get("skill") == s]
        owners = [p["code"] for p in pros if s in p["skills"]]
        skills.append({
            "code": s, "crc32": hx(c), "name": text(st, "Ability%sName" % s),
            "description": text(st, "Ability%sText" % s),
            "skill_list_index": order.index(s) if s in order else None,
            "taught_by_coaches": teach, "pro_owners_count": len(owners), "pro_owners": owners,
            "graph_consumers": by_skill.get(s, []),
            "code_consumers": [dict(x, note=CODE_NOTES.get(int(x["address"], 16), (None, None, None))[2])
                               for x in sites if x["skill"] == s]})

    cmd = "python3 -I tools/ts4data/career_data.py " + " ".join(argv if argv is not None else sys.argv[1:])
    hdr = "# Top Spin 4 %s.\n# Generated by: %s\n# Sources (sha256):\n" + "".join(
        "#   %s %s\n" % (k, v) for k, v in src.items())
    os.makedirs(a.out_dir, exist_ok=True)
    write_yaml(os.path.join(a.out_dir, "traits_skills.yaml"), hdr % ("player skills (traits) and their consumers", cmd), {
        "notes": [
            "Skill names/descriptions: StringTable key crc32('Ability<Code>Name') / crc32('Ability<Code>Text') (V).",
            "In-match a skill is PlayerState.Profile.SkillList[Id == crc32(code)].Value (S+0x640 list, 1.0 = owned).",
            "graph_consumers: analyser graphs (Expressions.bin) with a link port Profile.SkillList.Skill[Id].Value; "
            "formula_slice lists the nodes that depend on the skill, operands the nodes (two levels back) that define the other inputs of the nodes reading the skill directly; curves are [x0, x1, y_start, y_end]: a ramp from y0 at x0 to y1 at x1 (load-time slope fixup fn_8890DFC8 -> fn_88179740, V per G1 graphs-decoded.md; --curve-mode step writes y_end = y0).",
            "code_consumers: lis/ori of crc32(code) in Swing_DLL (HasSkill = fn_8868F0D8).",
            "unlock_step: CoachList Ability.Efficiency (0..4), the coach step at which the skill becomes active (I).",
        ],
        "skills": skills,
        "other_link_ports": [{"graph_index": g, "graph": h, "path": p, "qualifier": q} for g, h, p, q in other_links],
    })
    write_yaml(os.path.join(a.out_dir, "coaches_career.yaml"), hdr % ("coaches, career, pro players, AI difficulty", cmd), {
        "coach_only_abilities": ability_defs,
        "coaches": coaches,
        "player_evolution": evolution,
        "ai_difficulty": {
            "record_layout": {
                "size": "0x5C (Settings type 0x59CCA053), 6 per style (VeryEasy..Expert), 9 styles (cfg+0xF0)",
                "lists": {"l%02x" % off: {"member": h, "element": "0x10: {Expression key, graph key, f32 weight, "
                                          "bool Default, bool #ee04af9f}", "graph_outputs": roles.get("l%02x" % off)}
                          for off, h in AI_LIST_FIELDS},
                "graphs": {"g%02x" % off: {"member": name or h, "consumer": cons, "writes": role}
                           for off, h, name, cons, role in AI_GRAPH_FIELDS},
                "run_speed_limit": {"offset": "0x58", "member": AI_SKILL_FIELD[1], "use": AI_SKILL_FIELD[2]},
                "level_key": "+0x3C Id (VeryEasy..Expert)",
            },
            "styles": ai,
        },
        "pro_players": {"columns": {"ratings": ATTRS}, "players": pros},
    })
    print("skills %d, coaches %d, coach abilities %d, pros %d, AI styles %d, code sites %d" % (
        len(skills), len(coaches), len(ability_defs), len(pros), len(ai), len(sites)))


if __name__ == "__main__":
    main()
