#!/usr/bin/env python3
"""Reader and evaluator for the Top Spin 4 "analyser" expression graphs.

The data-driven graphs that set shot error chances, shot difficulty, timing ability, fatigue
and let probability live in the Pam engine XBin file ``Expressions.bin`` (a member of
``Core.arc``; type crc 0xD2968089, the same root type as ``Settings.bin``/``State.bin``).
``AnalyserFrameworkModule.bin`` (type 0xB708811F) is the framework's class registry, not the
graphs.  Everything is big-endian; arrays are 12-byte ``{s32 rel, u32 count, u32 cap}``
descriptors whose elements start at (address of the descriptor + rel); ``rel == -1`` is null.

Expressions.bin
  0x00  signature (8 bytes), u32 version 0x10, u32 0, u32 0xFFFFFFFF
  0x14  root: u32 8, u32 root-type-hash (0xD440C339), array<GraphDef, 0x2C bytes>

GraphDef (0x2C bytes), as read by the runtime (fn_88911668 / fn_8890E8B0):
  +0x00 u32  register count
  +0x04 array<Port, 0x18>   inputs   (copied into registers before evaluation)
  +0x10 array<Port, 0x18>   outputs  (read from registers after evaluation)
  +0x1C array<NodeEntry, 8> nodes    (executed in order)
  +0x28 u32  graph name hash (zlib.crc32 of the name)

Port (0x18 bytes): u32 domain key, u32 rel (to a name-path record), u32 0, u32 0, u32 register,
  s32 object index (-1: the port is bound by a link to a data constant instead of a field).
NodeEntry: u32 rel (to the node record, relative to the entry), u32 node type crc.

Evaluation follows the original kernels (see docs/gameplay/analyser-graphs.md); all arithmetic
is rounded to IEEE single precision like the PowerPC code.
"""
import argparse
import hashlib
import json
import math
import os
import struct
import sys
import zlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
DEFAULT_NAME_TABLE = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "data", "gameplay",
                                  "analyser_names.json")

ROOT_OFF = 0x14
GRAPH_STRIDE = 0x2C
PORT_STRIDE = 0x18
NODE_ENTRY_STRIDE = 8
CURVE_KEY_STRIDE = 0x14

EXPRESSIONS_ROOT_TYPE = 0xD440C339
EXPRESSIONS_SIGNATURE = (0x181AEDEE, 0xD2968089)
FRAMEWORK_MODULE_ROOT_TYPE = 0xB708811F

# node type crc32 -> (kernel name, original kernel address); names of the crc preimages are unknown
NODE_TYPES = {
    0x6BBD0182: ("CONST", 0x8890DD88),
    0xDEE0059F: ("SUM", 0x88178F60),
    0x9DA3605F: ("PRODUCT", 0x88179050),
    0xDCCE2909: ("MIN", 0x88179140),
    0xFB754E38: ("MAX", 0x881792E0),
    0x993894C6: ("CURVE", 0x88179480),
    0x7A741F05: ("RUNSUM", 0x881794E0),
    0x8196EAE3: ("SUB", 0x88179580),
    0xB6EA415E: ("DIV", 0x881795B8),
    0x7E683220: ("LERP", 0x881795F0),
    0xA68E1DC3: ("INVLERP", 0x88179698),
}

# Names recovered by hashing candidate strings (each verified: zlib.crc32(name) == key).  Domain keys
# name the class a port is bound through; graph names are the analyser names the game code loads.
DOMAIN_NAMES = {
    0x1BF15200: "PlayerState", 0x9D7C7C58: "BallState", 0x6C67FB3C: "TeamState",
    0x53A7FCCE: "ShotContext", 0x8883D2E1: "ShotComponents", 0x92672F1B: "MatchAnalyser",
    0x11453F46: "MatchState", 0xFCD367BC: "RepositioningComponents", 0x328A2512: "ServeComponents",
    0xB8C9A9FA: "PositioningComponents",
}
GRAPH_NAMES = [
    "ShotDifficulty", "BaselineTimingAbility", "VolleyTimingAbility", "FatigueIngame", "FatigueConst",
    "LetProbability", "LetSettings", "RushSpeedCoef", "SwingSpeedCoef", "VolleySpeedCoef", "InputFiltering",
    "ReturnServeZone", "VolleyZone", "PerfectShot", "GoodTiming", "GoodVolleySwing", "HighTopSpin",
    "Powerful", "PowerfulBall", "AutoSwing", "AutoVolleySwing", "Finesse", "Medium", "Volley", "Wood",
    "WrongFoot", "Vivacity", "Repositioning", "Positioning", "Preparation", "Movement", "InputNotation",
    "RushRepositioning", "SwingSelection", "AnimationSelection", "ReturnServe", "ZoneLob",
]
PATH_NAMES = [
    "Profile", "Fatigue", "Input", "Inputs", "Output", "Outputs", "Commands", "LetCommands", "SkillList",
    "Context", "EndOfPoint", "LocalPosition", "LocalOpponentPosition", "HitPoint", "HitPointLocal",
    "HitPosition", "HitPositionLocal", "BallHeight", "ControlValues", "IsTired", "IsDouble", "Height",
    "Distance", "Timing", "TimingState", "Style", "From", "Target", "Score", "BaseLine", "TopSpin", "Slice",
    "Flat", "Lob", "DropShot", "Volley", "Default", "DefaultAttributes", "ReturnServeState",
    "RepositioningState", "EvaluationOutputs", "ReachabilitySpeed", "StopMoving", "FollowToNet",
    "AvgSpeed", "ShotSpecific", "ServeStick", "Qualifier", "Value", "Id", "X", "Z", "Random",
    "SwingSelection", "AnimationSelection", "Movement", "Positioning", "Repositioning",
]


def known_names():
    """{crc32: name} for every name this module can vouch for."""
    names = {}
    for n in GRAPH_NAMES + PATH_NAMES:
        names[crc(n)] = n
    names.update(DOMAIN_NAMES)
    return names

VARIADIC = ("SUM", "PRODUCT", "MIN", "MAX", "RUNSUM")


def crc(name):
    """Engine string key: CRC-32 (zlib) of the bytes."""
    if isinstance(name, str):
        name = name.encode("latin-1")
    return zlib.crc32(name) & 0xFFFFFFFF


def f32(x):
    """Round a Python float to IEEE single precision."""
    try:
        return struct.unpack(">f", struct.pack(">f", x))[0]
    except OverflowError:
        return math.copysign(math.inf, x)


def bits_to_f32(u):
    return struct.unpack(">f", struct.pack(">I", u & 0xFFFFFFFF))[0]


def f32_to_bits(x):
    return struct.unpack(">I", struct.pack(">f", x))[0]


def _u32(buf, off):
    if off < 0 or off + 4 > len(buf):
        raise ValueError("read outside image at 0x%x" % off)
    return struct.unpack_from(">I", buf, off)[0]


def _s32(buf, off):
    if off < 0 or off + 4 > len(buf):
        raise ValueError("read outside image at 0x%x" % off)
    return struct.unpack_from(">i", buf, off)[0]


def read_array(buf, desc_off, stride):
    """Array descriptor at desc_off -> (first element offset, count).  Null gives (None, 0)."""
    rel = _s32(buf, desc_off)
    count = _u32(buf, desc_off + 4)
    if rel == -1 or count == 0:
        return None, 0
    start = desc_off + rel
    if start < 0 or start + stride * count > len(buf):
        raise ValueError("array at 0x%x runs outside the image" % desc_off)
    return start, count


# ----------------------------------------------------------------------------- data model

class Port:
    """One graph input or output binding."""

    def __init__(self, domain, slot, index, path, path_kind, offset):
        self.domain = domain          # u32 key of the binding domain (fn_8890EE68 lookup key)
        self.slot = slot              # register number
        self.index = index            # object index, -1 when bound through a data link
        self.path = path              # list of name hashes (the reflected member path)
        self.path_kind = path_kind    # word after the path header (3 or 4 in the shipped file)
        self.offset = offset          # file offset of the port record

    def to_json(self, names=None):
        names = names or {}
        return {"domain": "%08x" % self.domain, "slot": self.slot, "index": self.index,
                "path": ["%08x" % h for h in self.path],
                "path_names": [names.get(h) for h in self.path],
                "path_kind": self.path_kind}


class Node:
    """One node record.  ``fields`` depends on the kind (see ``evaluate_node``)."""

    def __init__(self, type_crc, offset, fields):
        self.type = type_crc
        self.offset = offset
        self.kind = NODE_TYPES[type_crc][0] if type_crc in NODE_TYPES else None
        self.fields = fields

    def reads(self):
        """Registers this node reads."""
        f, k = self.fields, self.kind
        if k in VARIADIC:
            return list(f["slots"])
        if k == "CURVE":
            return [f["in"]]
        if k in ("SUB", "DIV"):
            return [f["a"], f["b"]]
        if k in ("LERP", "INVLERP"):
            return [f["a"], f["b"], f["t"]]
        return []

    def writes(self):
        f, k = self.fields, self.kind
        if k == "CURVE":
            return [f["out"]] if f["out"] >= 0 else []
        if k in ("SUB", "DIV"):
            return [f["out"]]
        if k in VARIADIC + ("CONST", "LERP", "INVLERP"):
            return [f["out"]]
        return []

    def to_json(self):
        d = {"type": "%08x" % self.type, "kind": self.kind}
        d.update({k: (list(v) if isinstance(v, (list, tuple)) else v) for k, v in self.fields.items()})
        return d


class Graph:
    def __init__(self, name, nregs, inputs, outputs, nodes, offset):
        self.name = name              # u32 name hash
        self.nregs = nregs
        self.inputs = inputs
        self.outputs = outputs
        self.nodes = nodes
        self.offset = offset

    def to_json(self, names=None):
        names = names or {}
        return {"name_hash": "%08x" % self.name, "name": names.get(self.name),
                "registers": self.nregs,
                "inputs": [p.to_json(names) for p in self.inputs],
                "outputs": [p.to_json(names) for p in self.outputs],
                "nodes": [n.to_json() for n in self.nodes]}


# ----------------------------------------------------------------------------- parsing

def parse_path(buf, target):
    """Decode the name-path record a port points at.  Returns (hash list, kind word).

    The record is a tree of ``{rel, type}`` links; the reflected member names are the leaf nodes
    ``{0x10, 0x00270000, name hash, 0x00010000, 0, 0, 0}`` in link order.
    """
    names = []
    kind = None
    first, n1 = read_array(buf, target, 8)
    if first is None:
        return names, kind
    for i in range(n1):
        e = first + 8 * i
        node = e + _s32(buf, e)
        kind = _u32(buf, node + 4)
        arr, n2 = read_array(buf, node + 8, 8)
        for j in range(n2):
            e2 = arr + 8 * j
            leaf = e2 + _s32(buf, e2)
            if leaf + 12 <= len(buf) and _u32(buf, leaf + 4) == 0x00270000:
                names.append(_u32(buf, leaf + 8))
    return names, kind


def parse_port(buf, off):
    domain = _u32(buf, off)
    rel = _s32(buf, off + 4)
    slot = _u32(buf, off + 0x10)
    index = _s32(buf, off + 0x14)
    path, kind = parse_path(buf, off + 4 + rel) if rel != 0 else ([], None)
    return Port(domain, slot, index, path, kind, off)


def parse_node(buf, entry):
    """Node entry (8 bytes) -> Node.  Unknown node types keep their raw record words."""
    rec = entry + _s32(buf, entry)
    tcrc = _u32(buf, entry + 4)
    kind = NODE_TYPES[tcrc][0] if tcrc in NODE_TYPES else None
    if kind in VARIADIC:
        arr, n = read_array(buf, rec, 4)
        slots = [_u32(buf, arr + 4 * i) for i in range(n)] if arr is not None else []
        f = {"slots": slots, "out": _u32(buf, rec + 0xC)}
    elif kind == "CURVE":
        arr, n = read_array(buf, rec, CURVE_KEY_STRIDE)
        keys = []
        for i in range(n):
            k = arr + CURVE_KEY_STRIDE * i
            keys.append(struct.unpack_from(">5f", buf, k))     # x0, x1, y0, slope (on disc), y1
        f = {"in": _u32(buf, rec + 0xC), "out": _s32(buf, rec + 0x10), "keys": keys,
             "disc_slopes": [k[3] for k in keys]}
    elif kind in ("SUB", "DIV"):
        f = {"a": _u32(buf, rec), "b": _u32(buf, rec + 4), "out": _u32(buf, rec + 8)}
    elif kind == "LERP":
        f = {"a": _u32(buf, rec), "b": _u32(buf, rec + 4), "t": _u32(buf, rec + 8),
             "out": _u32(buf, rec + 0xC)}
    elif kind == "INVLERP":
        f = {"a": _u32(buf, rec), "b": _u32(buf, rec + 4), "t": _u32(buf, rec + 8),
             "out": _u32(buf, rec + 0xC)}
    elif kind == "CONST":
        f = {"out": _u32(buf, rec), "value": struct.unpack_from(">f", buf, rec + 4)[0]}
    else:
        f = {"raw": [_u32(buf, rec + 4 * i) for i in range(4) if rec + 4 * i + 4 <= len(buf)]}
    return Node(tcrc, rec, f)


def slope_fixup(x0, x1, y0, y1):
    """fn_88179740: the slope the game writes into key +0xC when the graph is bound.

    ``d = x1 - x0``; ``slope = 0`` when ``d == 0`` else ``(y1 - y0) / d`` (single precision)."""
    d = f32(x1 - x0)
    if d == 0.0:
        return 0.0
    return _div32(f32(y1 - y0), d)


def fixup_curves(graphs):
    """Apply the load-time slope fixup to every CURVE key, in place (what the runtime evaluates).

    Called from fn_8890DFC8 for each GraphDef (via fn_88690920 at PlayerCtx init), so after loading
    every curve is a piecewise-linear ramp from y0 at x0 to y1 at x1, clamped at both ends."""
    for g in graphs:
        for n in g.nodes:
            if n.kind == "CURVE":
                n.fields["keys"] = [(k[0], k[1], k[2], slope_fixup(k[0], k[1], k[2], k[4]), k[4])
                                    for k in n.fields["keys"]]
    return graphs


def parse_graph(buf, off):
    nregs = _u32(buf, off)
    arr, n = read_array(buf, off + 4, PORT_STRIDE)
    inputs = [parse_port(buf, arr + PORT_STRIDE * i) for i in range(n)] if arr is not None else []
    arr, n = read_array(buf, off + 0x10, PORT_STRIDE)
    outputs = [parse_port(buf, arr + PORT_STRIDE * i) for i in range(n)] if arr is not None else []
    arr, n = read_array(buf, off + 0x1C, NODE_ENTRY_STRIDE)
    nodes = [parse_node(buf, arr + NODE_ENTRY_STRIDE * i) for i in range(n)] if arr is not None else []
    return Graph(_u32(buf, off + 0x28), nregs, inputs, outputs, nodes, off)


def parse_expressions(buf, fixup=True):
    """Parse an Expressions.bin image -> list of Graph (file order).

    With ``fixup`` (default) curve slopes are recomputed as the game does at load time
    (``slope_fixup``); ``fixup=False`` keeps the on-disc slope words (all 0.0 in the retail file)."""
    if len(buf) < ROOT_OFF + 0x14:
        raise ValueError("file too small")
    if buf[0x10:0x14] != b"\xff\xff\xff\xff":
        raise ValueError("not an XBin image")
    if (_u32(buf, 0), _u32(buf, 4)) != EXPRESSIONS_SIGNATURE:
        raise ValueError("unexpected signature")
    if _u32(buf, ROOT_OFF + 4) != EXPRESSIONS_ROOT_TYPE:
        raise ValueError("root type is not the expression table")
    arr, n = read_array(buf, ROOT_OFF + 8, GRAPH_STRIDE)
    if arr is None:
        return []
    graphs = [parse_graph(buf, arr + GRAPH_STRIDE * i) for i in range(n)]
    return fixup_curves(graphs) if fixup else graphs


def framework_module_summary(buf):
    """Structural summary of AnalyserFrameworkModule.bin.

    That file is the *PlayerCreator* analyser module (module name hash crc32
    "PlayerCreatorAnalyserFrameworkModule"), a table of CAnalyserAgent* instances for the
    character creator (gender, hue, morph and outfit commands).  It holds no gameplay graphs.
    Returns the root type, the top level array count and how often each known agent class hash
    occurs as a word.
    """
    if len(buf) < ROOT_OFF + 0x14 or buf[0x10:0x14] != b"\xff\xff\xff\xff":
        raise ValueError("not an XBin image")
    if _u32(buf, ROOT_OFF + 4) != FRAMEWORK_MODULE_ROOT_TYPE:
        raise ValueError("not an analyser framework module")
    _, n0 = read_array(buf, ROOT_OFF + 8, 4)
    words = struct.unpack(">%dI" % (len(buf) // 4), buf[:len(buf) // 4 * 4])
    agents = {}
    for name in ("CAnalyserAgentExpr", "CPCAnalyserAgent_Current", "CPCAnalyserAgent_Preset",
                 "CAnalyserAgentCmdSender_Blend", "CAnalyserAgentCmdSender_Morph",
                 "CAnalyserAgentCmdSender_Outfit"):
        agents[name] = sum(1 for w in words if w == crc(name))
    return {"root_type": _u32(buf, ROOT_OFF + 4), "root_array_count": n0, "agent_class_words": agents,
            "has_module_name": any(w == crc("PlayerCreatorAnalyserFrameworkModule") for w in words)}


def validate_graph(g):
    """Return a list of structural problems (empty when the graph is well formed)."""
    problems = []
    for n in g.nodes:
        if n.kind is None:
            problems.append("unknown node type %08x" % n.type)
            continue
        for r in n.reads() + n.writes():
            if r >= g.nregs:
                problems.append("register %d out of range (%d)" % (r, g.nregs))
    for p in g.inputs + g.outputs:
        if p.slot >= g.nregs:
            problems.append("port register %d out of range (%d)" % (p.slot, g.nregs))
    return problems


def topology(g):
    """Which registers feed which outputs: list of (output slot, sorted input slots reaching it)."""
    writer = {}
    for i, n in enumerate(g.nodes):
        for w in n.writes():
            writer[w] = i
    in_slots = {p.slot: k for k, p in enumerate(g.inputs)}
    res = []
    for o in g.outputs:
        seen, stack, ins = set(), [o.slot], set()
        while stack:
            r = stack.pop()
            if r in seen:
                continue
            seen.add(r)
            if r in in_slots:
                ins.add(in_slots[r])
            i = writer.get(r)
            if i is not None:
                stack.extend(g.nodes[i].reads())
        res.append((o.slot, sorted(ins)))
    return res


# ----------------------------------------------------------------------------- evaluation

def eval_curve(x, keys):
    """fn_8817A688: piecewise-linear lookup over keys (x0, x1, y0, slope, y1).

    The last key with x0 <= x is used (the first key if none).  The offset into the segment is
    clamped to [0, x1 - x0]; the result is ``y0 + slope * offset`` with a single-precision fma.
    ``slope`` is the runtime value written by ``slope_fixup`` (``parse_expressions`` applies it),
    so a key is a ramp from y0 at x0 to y1 at x1.
    """
    x = f32(x)
    if not keys:
        raise ValueError("empty curve")
    k = keys[0]
    for cand in keys:
        if cand[0] > x:      # fcmpu f0, f1 ; bgt (an unordered compare does not stop the scan)
            break
        k = cand
    x0, x1, y0, slope = k[0], k[1], k[2], k[3]
    d = f32(x - x0)
    span = f32(x1 - x0)
    # MIN(d, span): fsel picks d when (d - span) is negative or unordered
    t = d if (math.isnan(f32(d - span)) or f32(d - span) < 0) else span
    t = t if not (math.isnan(t) or t < 0) else 0.0
    return _fma32(t, slope, y0)


def _fma32(a, b, c):
    try:
        return f32(math.fma(a, b, c))
    except (AttributeError, ValueError, OverflowError):
        return f32(a * b + c)


def _clamp01(v):
    # fsel(v >= 0 ? v : 0) (NaN -> 0), then fsel(v - 1 >= 0 ? 1 : v)
    if math.isnan(v) or v < 0:
        v = 0.0
    return 1.0 if f32(v - 1.0) >= 0 else v


def evaluate_node(node, regs):
    k, f = node.kind, node.fields
    if k == "CONST":
        regs[f["out"]] = f["value"]
    elif k == "SUM":
        acc = regs[f["slots"][0]] if f["slots"] else 0.0
        for s in f["slots"][1:]:
            acc = f32(regs[s] + acc)
        regs[f["out"]] = acc
    elif k == "PRODUCT":
        acc = regs[f["slots"][0]] if f["slots"] else 0.0
        for s in f["slots"][1:]:
            acc = f32(regs[s] * acc)
        regs[f["out"]] = acc
    elif k == "MIN":
        acc = regs[f["slots"][0]] if f["slots"] else 0.0
        for s in f["slots"][1:]:
            x = regs[s]
            d = f32(acc - x)
            acc = x if (d >= 0) else acc          # unordered -> keep acc
        regs[f["out"]] = acc
    elif k == "MAX":
        acc = regs[f["slots"][0]] if f["slots"] else 0.0
        for s in f["slots"][1:]:
            x = regs[s]
            d = f32(acc - x)
            acc = acc if (d >= 0) else x          # unordered -> take x
        regs[f["out"]] = acc
    elif k == "CURVE":
        if f["out"] >= 0:
            regs[f["out"]] = eval_curve(regs[f["in"]], f["keys"])
    elif k == "RUNSUM":
        acc, bad = 0.0, False
        for i, s in enumerate(f["slots"]):
            x = regs[s]
            if x < 0:
                bad = True
                break
            acc = x if i == 0 else f32(x + acc)
        regs[f["out"]] = -1.0 if bad else acc
    elif k == "SUB":
        regs[f["out"]] = f32(regs[f["a"]] - regs[f["b"]])
    elif k == "DIV":
        a, b = regs[f["a"]], regs[f["b"]]
        regs[f["out"]] = _div32(a, b)
    elif k == "LERP":
        a, b, t = regs[f["a"]], regs[f["b"]], regs[f["t"]]
        regs[f["out"]] = _fma32(_clamp01(t), f32(b - a), a)
    elif k == "INVLERP":
        a, b, x = regs[f["a"]], regs[f["b"]], regs[f["t"]]
        regs[f["out"]] = _clamp01(_div32(f32(x - a), f32(b - a)))
    # unknown node types have no kernel and are skipped by the runtime


def _div32(a, b):
    if b == 0.0 or math.isnan(a) or math.isnan(b):
        if math.isnan(a) or math.isnan(b) or a == 0.0:
            return math.nan
        neg = (math.copysign(1.0, a) < 0) != (math.copysign(1.0, b) < 0)
        return -math.inf if neg else math.inf
    return f32(a / b)


def evaluate(graph, inputs):
    """Run a graph.  ``inputs`` is a list (one float per input port, in port order) or a dict
    {input index: value}.  Returns the list of output port values."""
    regs = [0.0] * max(graph.nregs, 1)
    if isinstance(inputs, dict):
        inputs = [inputs.get(i, 0.0) for i in range(len(graph.inputs))]
    if len(inputs) != len(graph.inputs):
        raise ValueError("graph %08x takes %d inputs" % (graph.name, len(graph.inputs)))
    for p, v in zip(graph.inputs, inputs):
        regs[p.slot] = f32(v)
    for n in graph.nodes:
        evaluate_node(n, regs)
    return [regs[p.slot] for p in graph.outputs]


# ----------------------------------------------------------------------------- bindings (State.bin + Layoutall.bin)
#
# A port with cell index >= 0 is bound by fn_8817A4F0 to
#     pool_base + domain_object_offset + cell_table[index]
# The domain object comes from the context table filled by fn_8890ED60 (keys and objects below:
# fn_8868F480 for the player/ball/match/team set, fn_886B6448 for the AI components); the cell table
# is ctx+0x10 = State root +0xF58 (fn_8868F480 +0x98: ``stw r7, 0x340(r30)`` with r7 = root + 0xF58,
# the same assignment at fn_886B6448 +0x190).  Offsets in the table are relative to the domain object.

STATE_PLAYERS_OFF = 0xE80     # State root: list<PlayerState 0x25FCD125> (4 x 0x1070)
STATE_AI_OFF = 0xE8C          # State root: list<0xD7C700B9> (4 x 0x274), per-player AI record
STATE_TEAMS_OFF = 0xE98       # State root: list<TeamState 0x9EF5C521> (2 x 0xC0)
STATE_CELLS_OFF = 0xF58       # State root: list<u32> cell index -> byte offset (307 entries)
STATE_BALL_OFF = 0x400        # State root: BallState (type 0x6FEE4245)
STATE_MATCH_OFF = 0xC0        # State root: MatchState (type 0x72B1C1A1)

ROOT_TYPES = {"player": 0x25FCD125, "ball": 0x6FEE4245, "match": 0x72B1C1A1, "team": 0x9EF5C521,
              "ai": 0xD7C700B9}

# domain key -> (label, root object, member-name path inside the root object, note)
DOMAIN_BINDINGS = {
    0x1BF15200: ("PlayerState", "player", (), "own player S (PlayerCtx+0x74)"),
    0x3BA3D582: ("#3ba3d582", "player", (), "opponent (the other team's player facing S)"),
    0xA2AA8438: ("#a2aa8438", "player", (), "opponent's partner (doubles)"),
    0x56B5B281: ("#56b5b281", "player", (), "own partner (doubles)"),
    0x2DE0BCE2: ("Context", "player", (0x2DE0BCE2,), "S.Context"),
    0x53A7FCCE: ("ShotContext", "player", (0x2DE0BCE2, 0x53A7FCCE), "S.Context.ShotContext"),
    0x8448B811: ("#8448b811", "player", (0x44B8753C,), "S.#44b8753c (AI shot-choice inputs)"),
    0x3237FFAC: ("#3237ffac", "player", (0x89408A2F, 0x2906F362, 0xFBDD21BC), "S.ReceiverState.HitPositionSelection.#fbdd21bc"),
    0x92672F1B: ("MatchAnalyser", "player", (0x92672F1B,), "S.MatchAnalyser"),
    0x9D7C7C58: ("BallState", "ball", (), "State+0x400"),
    0x11453F46: ("MatchState", "match", (), "State+0xC0"),
    0x6C67FB3C: ("TeamState", "team", (), "own team"),
    0xE9CA839C: ("#e9ca839c", "ai", (), "per-player AI decision record"),
    0x8883D2E1: ("ShotComponents", "ai", (0xEE0F0A46,), "AI.FinalShotComponents"),
    0x328A2512: ("ServeComponents", "ai", (0x7A5E9F81,), "AI.FinalServeComponents"),
    0xFCD367BC: ("RepositioningComponents", "ai", (0x38F589F1,), "AI.FinalRepositioningComponents"),
    0xB8C9A9FA: ("PositioningComponents", "ai", (0xAEF32F14,), "AI.FinalPositioningComponents"),
}

# Graphs loaded by a literal hash in Swing_DLL: hash -> [(function, call address of fn_8866F028)].
# Reproduce: work-local scan of every ``bl fn_8866F028`` and the lis/ori constant built before it.
CODE_LOADERS = {
    0x36BDE5FE: [("fn_886B62E0", 0x886B6320)], 0x85F4C811: [("fn_886B7048", 0x886B7084)],
    0x39CFDEBA: [("fn_886B7048", 0x886B70B4)], 0xA6DFABAA: [("fn_886B7048", 0x886B70E4)],
    0xBDD29CAD: [("fn_886B7A60", 0x886B7A94)], 0x54457AD3: [("fn_886B7A60", 0x886B7ACC)],
    0xC4B26668: [("fn_886BACC0", 0x886BAD04)], 0x661A3F2C: [("fn_886BACC0", 0x886BAD40)],
    0x39968A9E: [("fn_886BACC0", 0x886BAD7C)], 0xE5CFA4B4: [("fn_886BB6E0", 0x886BB72C)],
    0xFC7F3D8A: [("fn_886BB6E0", 0x886BB774)], 0xB5CFF9B7: [("fn_886BB6E0", 0x886BB7BC)],
    0x4FCC3EB8: [("fn_886BB6E0", 0x886BB804)], 0xD5B5624B: [("fn_886BB828", 0x886BBB6C)],
    0x069577F4: [("fn_886BB828", 0x886BBBA4)], 0x2F4DF388: [("fn_886BB828", 0x886BBBDC)],
    0x11ED4B25: [("fn_886BB828", 0x886BBC14)], 0xDAF1C0D6: [("fn_886BBC38", 0x886BBC68)],
    0x9C8607A7: [("fn_886BBC38", 0x886BBCA0)], 0xCBE44A9B: [("fn_886BC1E0", 0x886BC210)],
    0x80CE1A10: [("fn_886BC1E0", 0x886BC248)], 0x8ADD300F: [("fn_886BC1E0", 0x886BC280)],
    0x9D734117: [("fn_886BC1E0", 0x886BC2B8)], 0x6BD1FBAB: [("fn_886BC1E0", 0x886BC2F0)],
    0xE4F01642: [("fn_886BCDA8", 0x886BCE64)], 0x71198650: [("fn_886BDB58", 0x886BDBE8)],
    0x4FD4C7A4: [("fn_886BDB58", 0x886BDC24)], 0xDF1F8733: [("fn_886BDB58", 0x886BDC60)],
    0xDAF2ECBD: [("fn_886BDB58", 0x886BDC9C)], 0x0340A26E: [("fn_886BE1C8", 0x886BE6C0)],
    0xDDA048F3: [("fn_886BE1C8", 0x886BE6F8)], 0xA6A6A055: [("fn_886BE1C8", 0x886BE730)],
    0x5C66A7C5: [("fn_886BE1C8", 0x886BE768)], 0xE4EEE070: [("fn_886BE1C8", 0x886BE7A0)],
    0xFDD82B26: [("fn_886BE1C8", 0x886BE7D8)], 0x9CFED468: [("fn_886BE1C8", 0x886BE810)],
    0x5E773FDA: [("fn_886BE1C8", 0x886BE848)], 0xACB75B15: [("fn_886BE1C8", 0x886BEA30)],
    0xD0CB6659: [("fn_886BF598", 0x886BF73C)], 0xC1DF4081: [("fn_886BF598", 0x886BF778)],
    0x912FAAA2: [("fn_886BF598", 0x886BF7B4)], 0x5564F5D6: [("fn_886BF598", 0x886BF7F0)],
    0x729975E2: [("fn_886BF598", 0x886BF82C)], 0xCC20BAEA: [("fn_886BF598", 0x886BF868)],
    0x743644E7: [("fn_886BF598", 0x886BF8A4)], 0xC015CB95: [("fn_886BF598", 0x886BF8E0)],
    0xC130E1F5: [("fn_886BF598", 0x886BF91C)], 0x87B5A13A: [("fn_886BF598", 0x886BF958)],
    0xB568048D: [("fn_886BF598", 0x886BF994)], 0x9CAFB633: [("fn_886BF598", 0x886BF9D0)],
    0x9DEB41B3: [("fn_886BF598", 0x886BFA0C)], 0x53613CAD: [("fn_886BF598", 0x886BFA48)],
    0x926EEF1B: [("fn_886BF598", 0x886BFA84)], 0xC0150160: [("fn_886BF598", 0x886BFAC0)],
    0xCFDBD245: [("fn_886BF598", 0x886BFAFC)],
}


class Bindings:
    """Cell index -> member of a game struct, from ``State.bin`` (cell table and defaults) and
    ``Layoutall.bin`` (type layouts)."""

    def __init__(self, state_buf, layout_buf):
        import ts4_layout as L
        self.L = L
        self.types = L.parse_layout(layout_buf)
        self.state = state_buf
        self.root, self.root_type = L.xbin_root(state_buf)
        rel, cnt = struct.unpack_from(">iI", state_buf, self.root + STATE_CELLS_OFF)
        base = self.root + STATE_CELLS_OFF + rel
        self.cells = list(struct.unpack_from(">%dI" % cnt, state_buf, base))
        self.domains = {}
        for key, (label, root, path, note) in DOMAIN_BINDINGS.items():
            t, off = ROOT_TYPES[root], 0
            for name in path:
                f = L.field_by_name(self.types, t, name)
                t, off = f.type, off + f.offset
            self.domains[key] = (label, root, t, off, note)

    def _root_object(self, root):
        """File offset of instance 0 of a root object in State.bin (the initial values)."""
        r = self.root
        if root == "ball":
            return r + STATE_BALL_OFF
        if root == "match":
            return r + STATE_MATCH_OFF
        off = {"player": STATE_PLAYERS_OFF, "team": STATE_TEAMS_OFF, "ai": STATE_AI_OFF}[root]
        rel, _ = struct.unpack_from(">iI", self.state, r + off)
        return r + off + rel

    def bind(self, port):
        """dict describing what the port reads or writes, or None for link-bound ports."""
        if port.index < 0 or port.domain not in self.domains or port.index >= len(self.cells):
            return None
        label, root, t, base, note = self.domains[port.domain]
        off = self.cells[port.index]
        chain = self.L.resolve(self.types, t, off)
        leaf = chain[-1][0] if chain else None
        d = {"domain": label, "root": root, "domain_note": note, "cell": port.index, "offset": off,
             "root_offset": base + off, "member": [f.name for f, _ in chain],
             "member_offset": (off - chain[-1][1]) if chain else None,
             "leaf_type": leaf.type if leaf else None}
        a = self._root_object(root) + base + off
        if a + 4 <= len(self.state):
            d["state_default"] = struct.unpack_from(">f", self.state, a)[0]
            d["state_default_u32"] = struct.unpack_from(">I", self.state, a)[0]
        return d


def settings_references(settings_buf, layout_types, graph_hashes):
    """Walk Settings.bin with the layout and return {graph hash: [member path tuples]} for every
    primitive member whose value is a graph name hash (the AI tables choose graphs this way)."""
    import ts4_layout as L
    root, rtype = L.xbin_root(settings_buf)
    refs = {}

    def visit(path, addr, field):
        w = struct.unpack_from(">I", settings_buf, addr)[0]
        if w in graph_hashes:
            refs.setdefault(w, []).append(path)
    L.walk(layout_types, settings_buf, rtype, root, visit)
    return refs


def load_name_table(path):
    """{crc: (name, confidence)} from a JSON {hex: [name, confidence]} table; entries whose crc does
    not match their name are dropped."""
    out = {}
    with open(path) as fh:
        table = json.load(fh)
    for k, v in table.items():
        name, conf = (v, "high") if isinstance(v, str) else (v[0], v[1])
        if crc(name) == int(k, 16):
            out[int(k, 16)] = (name, conf)
    return out


# ----------------------------------------------------------------------------- readable dump

def _q(s):
    s = str(s)
    if s == "" or any(c in s for c in ":#[]{},&*!|>'\"%@`") or s != s.strip():
        return '"' + s.replace('\\', '\\\\').replace('"', '\\"') + '"'
    return s


def _g(v):
    """Shortest decimal that reads back as the same single-precision value."""
    if isinstance(v, float):
        if math.isnan(v) or math.isinf(v):
            return '"%r"' % v
        v = f32(v)
        for p in range(1, 10):
            t = "%.*g" % (p, v)
            if f32(float(t)) == v:
                break
        return repr(float(t))
    return str(v)


class Namer:
    def __init__(self, table=None):
        self.table = dict(table or {})
        for k, v in known_names().items():
            self.table[k] = (v, "high")

    def __call__(self, h, mark=True):
        if h is None:
            return "?"
        if isinstance(h, str):
            return h
        e = self.table.get(h)
        if e is None:
            return "#%08x" % h
        name, conf = e
        return name if (conf == "high" or not mark) else name + ("?" if conf == "medium" else "??")

    def conf(self, h):
        e = self.table.get(h)
        return e[1] if e else None


def port_label(port, bindings, nm):
    if bindings is not None:
        b = bindings.bind(port)
        if b:
            return "%s.%s" % (b["domain"] if b["domain"][0] != "#" else nm(port.domain), ".".join(nm(x) for x in b["member"]))
    path = ".".join(nm(h) for h in port.path)
    if port.index < 0:
        return "%s.%s<link>" % (nm(port.domain), path)
    return "%s.%s[cell %d]" % (nm(port.domain), path, port.index)


def graph_formula(g, labels):
    """Readable assignment list: [(target, expression)] in node order plus the outputs."""
    expr = {p.slot: labels[i] for i, p in enumerate(g.inputs)}
    curves = 0
    lines = []

    def e(r):
        return expr.get(r, "r%d" % r)
    for n in g.nodes:
        k, f = n.kind, n.fields
        if k == "CONST":
            v = _g(f["value"])
        elif k == "CURVE":
            curves += 1
            v = "curve%d(%s)" % (curves, e(f["in"]))
        elif k in VARIADIC:
            v = "%s(%s)" % (k.lower(), ", ".join(e(x) for x in f["slots"]))
        elif k == "SUB":
            v = "(%s - %s)" % (e(f["a"]), e(f["b"]))
        elif k == "DIV":
            v = "(%s / %s)" % (e(f["a"]), e(f["b"]))
        elif k == "LERP":
            v = "lerp(%s, %s, %s)" % (e(f["a"]), e(f["b"]), e(f["t"]))
        elif k == "INVLERP":
            v = "invlerp(%s, %s, %s)" % (e(f["a"]), e(f["b"]), e(f["t"]))
        else:
            continue
        for w in n.writes():
            lines.append(("r%d" % w, v))
            expr[w] = "r%d" % w
    return lines, [(i, e(p.slot)) for i, p in enumerate(g.outputs)]


def dump_readable(graphs, out, names=None, bindings=None, refs=None, header=()):
    """Write every graph with all values as an indented YAML-style text file."""
    nm = Namer(names)
    w = out.write
    for h in header:
        w("# %s\n" % h)
    w("curve_semantics: \"key = {x0, x1, y0, slope, y1}; runtime slope = (y1-y0)/(x1-x0) (fn_88179740);"
      " value = y0 + slope*clamp(x - x0, 0, x1 - x0) using the last key with x0 <= x (first key if none)\"\n")
    w("graphs:\n")
    for i, g in enumerate(graphs):
        w("- index: %d\n  hash: 0x%08x\n  name: %s\n" % (i, g.name, _q(nm(g.name, mark=False))))
        w("  name_confidence: %s\n" % (nm.conf(g.name) or "unknown"))
        if g.name in CODE_LOADERS:
            w("  loaded_by_code: [%s]\n" % ", ".join("%s @0x%08X" % x for x in CODE_LOADERS[g.name]))
        if refs and g.name in refs:
            paths = sorted({".".join(nm(x) if isinstance(x, int) else "[]" for x in p) for p in refs[g.name]})
            w("  referenced_by_settings: %d\n" % len(refs[g.name]))
            w("  settings_paths:\n")
            for p in paths[:12]:
                w("  - %s\n" % _q(p))
        w("  registers: %d\n" % g.nregs)
        labels = []
        for kind, ports in (("inputs", g.inputs), ("outputs", g.outputs)):
            w("  %s:\n" % kind if ports else "  %s: []\n" % kind)
            for p in ports:
                lab = port_label(p, bindings, nm)
                if kind == "inputs":
                    labels.append(lab)
                w("  - reg: %d\n    label: %s\n    domain: %s\n    path: %s\n    cell: %d\n" % (
                    p.slot, _q(lab), _q(nm(p.domain)), _q(".".join(nm(h) for h in p.path)), p.index))
                b = bindings.bind(p) if bindings is not None else None
                if b:
                    w("    offset: 0x%x\n    object: %s\n    member: %s\n" % (
                        b["offset"], _q(b["domain_note"]), _q(".".join(nm(x) for x in b["member"]))))
                    if b["member_offset"]:
                        w("    member_offset: 0x%x\n" % b["member_offset"])
                    if "state_default" in b:
                        w("    state_default: %s\n" % _g(b["state_default"]))
        w("  nodes:\n" if g.nodes else "  nodes: []\n")
        curves = 0
        for n in g.nodes:
            f = n.fields
            if n.kind == "CURVE":
                curves += 1
                w("  - {kind: CURVE, id: curve%d, in: r%d, out: r%d}\n" % (curves, f["in"], f["out"]))
                w("    keys:  # [x0, x1, y0, y1]\n")
                for k in f["keys"]:
                    w("    - [%s, %s, %s, %s]\n" % (_g(k[0]), _g(k[1]), _g(k[2]), _g(k[4])))
            elif n.kind == "CONST":
                w("  - {kind: CONST, out: r%d, value: %s}\n" % (f["out"], _g(f["value"])))
            elif n.kind in VARIADIC:
                w("  - {kind: %s, in: [%s], out: r%d}\n" % (n.kind, ", ".join("r%d" % x for x in f["slots"]), f["out"]))
            elif n.kind in ("SUB", "DIV"):
                w("  - {kind: %s, a: r%d, b: r%d, out: r%d}\n" % (n.kind, f["a"], f["b"], f["out"]))
            elif n.kind in ("LERP", "INVLERP"):
                w("  - {kind: %s, a: r%d, b: r%d, t: r%d, out: r%d}\n" % (n.kind, f["a"], f["b"], f["t"], f["out"]))
            else:
                w("  - {kind: unknown, type: 0x%08x}\n" % n.type)
        lines, outs = graph_formula(g, labels)
        w("  formula:\n" if (lines or outs) else "  formula: []\n")
        for t, v in lines:
            w("  - %s\n" % _q("%s = %s" % (t, v)))
        for i, v in outs:
            w("  - %s\n" % _q("OUT %d = %s" % (i, v)))


# ----------------------------------------------------------------------------- command line

def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("expressions", help="Expressions.bin (extract with tools/ts4_arc.py Core.arc)")
    ap.add_argument("--module", help="AnalyserFrameworkModule.bin (PlayerCreator module; summary only)")
    ap.add_argument("--names", help="JSON {hex crc: name} (e.g. work/disc/gameplay/crc_dictionaries.json)")
    ap.add_argument("--json", metavar="OUT", help="write all graphs as JSON")
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--eval", metavar="NAME_OR_HASH")
    ap.add_argument("--disc-slopes", action="store_true",
                    help="keep the on-disc slope words (0.0) instead of the load-time fixup (not what the game runs)")
    ap.add_argument("--state", help="State.bin (Core.arc 0x623D0979): cell table and initial values")
    ap.add_argument("--layout", help="Layoutall.bin (disc root): type layouts, needed with --state/--settings")
    ap.add_argument("--settings", help="Settings.bin (Core.arc 0x334E7E0D): find data references to graphs")
    ap.add_argument("--name-table", default=DEFAULT_NAME_TABLE,
                    help="JSON {hex: [name, confidence]} (default: data/gameplay/analyser_names.json)")
    ap.add_argument("--dump-readable", metavar="OUT", help="write every graph with all values as YAML-style text")
    ap.add_argument("inputs", nargs="*", type=float)
    a = ap.parse_args()
    names = {}
    if a.names:
        d = json.load(open(a.names))
        for v in (d.values() if all(isinstance(x, dict) for x in d.values()) else [d]):
            names.update({int(k, 16): s for k, s in v.items()})
    for k, v in known_names().items():
        names.setdefault(k, v)
    buf = open(a.expressions, "rb").read()
    graphs = parse_expressions(buf, fixup=not a.disc_slopes)
    table = {}
    if a.name_table and os.path.exists(a.name_table):
        table = load_name_table(a.name_table)
    for k, v in names.items():          # built-in names and --names dictionaries are vouched for
        table[k] = (v, "high")
    for k, v in table.items():          # name-table entries keep their own confidence
        names.setdefault(k, v[0])
    if a.module:
        print(framework_module_summary(open(a.module, "rb").read()))
    if a.list:
        for i, g in enumerate(graphs):
            print("%3d %08x %-24s regs=%-3d in=%-2d out=%-2d nodes=%d" % (
                i, g.name, names.get(g.name, ""), g.nregs, len(g.inputs), len(g.outputs), len(g.nodes)))
    if a.json:
        json.dump([g.to_json(names) for g in graphs], open(a.json, "w"), indent=1)
    if a.dump_readable:
        bindings = refs = None
        layout_buf = open(a.layout, "rb").read() if a.layout else None
        hdr = ["Top Spin 4 analyser graphs (Expressions.bin), all values.",
               "generated by: python3 tools/ts4_analyser.py %s --dump-readable OUT%s" % (
                   os.path.basename(a.expressions),
                   "".join(" --%s %s" % (k, os.path.basename(getattr(a, k))) for k in ("state", "layout", "settings")
                           if getattr(a, k))),
               "Expressions.bin sha256 %s (%d bytes)" % (hashlib.sha256(buf).hexdigest(), len(buf))]
        if a.state and layout_buf:
            sb = open(a.state, "rb").read()
            bindings = Bindings(sb, layout_buf)
            hdr.append("State.bin sha256 %s" % hashlib.sha256(sb).hexdigest())
            hdr.append("Layoutall.bin sha256 %s" % hashlib.sha256(layout_buf).hexdigest())
        if a.settings and layout_buf:
            import ts4_layout as L
            stb = open(a.settings, "rb").read()
            refs = settings_references(stb, L.parse_layout(layout_buf), {g.name for g in graphs})
            hdr.append("Settings.bin sha256 %s" % hashlib.sha256(stb).hexdigest())
        hdr.append("curves use the runtime slope (fn_88179740)" if not a.disc_slopes else "curves use the on-disc slope words")
        hdr.append("names: '?' suffix = medium confidence, '??' = low (crc32 brute force); '#xxxxxxxx' = unnamed hash")
        with open(a.dump_readable, "w") as fh:
            dump_readable(graphs, fh, table, bindings, refs, hdr)
    if a.eval:
        h = int(a.eval, 16) if all(c in "0123456789abcdefABCDEF" for c in a.eval) and len(a.eval) == 8 else crc(a.eval)
        g = next(g for g in graphs if g.name == h)
        print(evaluate(g, a.inputs))
    return 0


if __name__ == "__main__":
    sys.exit(main())
