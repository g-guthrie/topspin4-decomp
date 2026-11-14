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
import json
import math
import struct
import sys
import zlib

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
            x0, x1, y0, slope = struct.unpack_from(">4f", buf, k)
            keys.append((x0, x1, y0, slope, _u32(buf, k + 0x10)))
        f = {"in": _u32(buf, rec + 0xC), "out": _s32(buf, rec + 0x10), "keys": keys}
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


def parse_graph(buf, off):
    nregs = _u32(buf, off)
    arr, n = read_array(buf, off + 4, PORT_STRIDE)
    inputs = [parse_port(buf, arr + PORT_STRIDE * i) for i in range(n)] if arr is not None else []
    arr, n = read_array(buf, off + 0x10, PORT_STRIDE)
    outputs = [parse_port(buf, arr + PORT_STRIDE * i) for i in range(n)] if arr is not None else []
    arr, n = read_array(buf, off + 0x1C, NODE_ENTRY_STRIDE)
    nodes = [parse_node(buf, arr + NODE_ENTRY_STRIDE * i) for i in range(n)] if arr is not None else []
    return Graph(_u32(buf, off + 0x28), nregs, inputs, outputs, nodes, off)


def parse_expressions(buf):
    """Parse an Expressions.bin image -> list of Graph (file order)."""
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
    return [parse_graph(buf, arr + GRAPH_STRIDE * i) for i in range(n)]


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
    """fn_8817A688: piecewise-linear lookup over keys (x0, x1, y0, slope, _).

    The last key with x0 <= x is used (the first key if none).  The offset into the segment is
    clamped to [0, x1 - x0]; the result is ``y0 + slope * offset`` with a single-precision fma.
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


# ----------------------------------------------------------------------------- command line

def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("expressions", help="Expressions.bin (extract with tools/ts4_arc.py Core.arc)")
    ap.add_argument("--module", help="AnalyserFrameworkModule.bin (PlayerCreator module; summary only)")
    ap.add_argument("--names", help="JSON {hex crc: name} (e.g. work/disc/gameplay/crc_dictionaries.json)")
    ap.add_argument("--json", metavar="OUT", help="write all graphs as JSON")
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--eval", metavar="NAME_OR_HASH")
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
    graphs = parse_expressions(buf)
    if a.module:
        print(framework_module_summary(open(a.module, "rb").read()))
    if a.list:
        for i, g in enumerate(graphs):
            print("%3d %08x %-24s regs=%-3d in=%-2d out=%-2d nodes=%d" % (
                i, g.name, names.get(g.name, ""), g.nregs, len(g.inputs), len(g.outputs), len(g.nodes)))
    if a.json:
        json.dump([g.to_json(names) for g in graphs], open(a.json, "w"), indent=1)
    if a.eval:
        h = int(a.eval, 16) if all(c in "0123456789abcdefABCDEF" for c in a.eval) and len(a.eval) == 8 else crc(a.eval)
        g = next(g for g in graphs if g.name == h)
        print(evaluate(g, a.inputs))
    return 0


if __name__ == "__main__":
    sys.exit(main())
