#!/usr/bin/env python3
"""Bottom-up, per-subsystem work list for the Q5 port decomp (worklist v2).

Owner plan (2026-11-23): decompile bottom-up through the call graph, organised
by subsystem, because the game is LTCG-built and a caller's codegen depends on
its callees' bodies. Scope = all gameplay functions plus the transitive closure
of the non-middleware game functions they call. Middleware (Havok, FMOD, Bink,
XDK/D3D, CRT), third-party libraries with public source (Lua, zlib, expat,
libpng/libjpeg, trio) and, for now, the renderer are external leaves.

Steps
  1. Direct call graph over every .text function: `bl` targets plus `b`/`bc`
     branches that leave the function (tail calls). `bctrl` (indirect calls)
     are counted per function but not resolved.
  2. Scope: gameplay set (address ranges, see GAMEPLAY below) + slot functions
     of vtables loaded by gameplay functions (config/54540859/vtables.json;
     constructors/destructors load their class vtable, so the class methods
     are reachable by virtual calls) + the transitive closure of direct
     callees that are game code. Everything else reached is an external leaf.
  3. Subsystems: anchor names (docs/gameplay/*-symbols.csv, symbols.md) and
     address ranges with good locality seed labels; the interleaved core of
     the gameplay module (0x8865A000-0x886C8000, where LTCG ordering mixes
     movement, aiming, rules and AI) is labelled by weighted label
     propagation over call edges, vtable class membership and address
     neighbours; dependencies outside the gameplay ranges are grouped by
     address bucket, with FP/VMX-heavy helpers going to math.
  4. Levels: SCCs of the in-scope graph over unsolved functions; level 0 =
     every in-scope callee outside its SCC is matched ("ready").
  5. Writes docs/agents/q5/worklist_v2.txt, docs/agents/q5/subsystems.md and
     docs/agents/q5/scope_callgraph.json (in-scope edges, addresses only; read
     by tools/q5_status.py --worklist v2 to recompute readiness live).

Inputs: config/54540859/symbols.txt, match.json, equivalent.json, vtables.json,
docs/agents/q5/{escalate,templates}.json, docs/agents/q5/worklist.txt (sister
groups), docs/gameplay/*-symbols.csv and symbols.md (anchor names), and either
the pickled disassembly work/army/VX1/textdis.pkl (default when present) or the
decompressed image orig/54540859/Swing_DLL.dll (--image; raw word decoding).
Standard library only.

  python3 tools/callgraph_worklist.py [--dis PKL | --image DLL] [--check]
"""
import argparse
import bisect
import collections
import hashlib
import json
import pickle
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from decomp_survey import RANGES as SURVEY_RANGES  # noqa: E402

VERSION = "callgraph_worklist 1.0"
Q5 = ROOT / "docs" / "agents" / "q5"
CFG = ROOT / "config" / "54540859"

# Gameplay set: the address ranges the Q5 worklist.txt "gameplay" queue was cut
# from (every worklist gameplay entry lies in one; checked by --check), plus the
# ball model 0x888AA8D0-0x888B0000 (ts4_bm_ball_*, docs/gameplay/gp4b.md), which
# the old queue omitted.
GAMEPLAY = [
    (0x88640000, 0x886E8000, "Swing gameplay module + animation glue"),
    (0x887EC000, 0x88800000, "CAnalyserFramework, TrackSide, SysServices"),
    (0x88866000, 0x88870000, "CGameLogic / match flow"),
    (0x88878FA0, 0x88891678, "physics wrapper, IO/paddle, sound events"),
    (0x888AA8D0, 0x88918000, "ball model, camera, minigames, publishers, input mapper"),
]
RENDERER = (0x886E8000, 0x88780000)

# Subsystems: id, name. Order = report order and tie-break order.
SUBSYSTEMS = [
    ("move", "Player movement, planner & repositioning"),
    ("shot", "Shot selection, aiming & swing request"),
    ("ai", "AI decisions (serve, rally, triggers)"),
    ("rules", "Match rules, scoring & game logic"),
    ("ctrl", "Player controller, state, fatigue & school"),
    ("anlz", "Analyser framework & graphs"),
    ("ball", "Ball model & physics wrapper"),
    ("anim", "Animation glue & root motion"),
    ("swan", "Swing animation engine & clip planner"),
    ("pres", "Sound events, umpire, crowd & HUD"),
    ("cam", "Camera & shot camera"),
    ("world", "Minigames, multiball, collisions & frame sync"),
    ("pub", "XData publishers & gameplay interface"),
    ("input", "Input mapper, paddle driver & IO"),
    ("stat", "Telemetry & match statistics"),
    ("math", "Math, curves & geometry"),
    ("cont", "Containers & strings (engine core)"),
    ("eng", "Engine core: XData, resources, heaps, modules"),
    ("glue", "Game flow, UI, script & net glue"),
]
SUB_NAME = dict(SUBSYSTEMS)
SUB_ORDER = {k: i for i, (k, _) in enumerate(SUBSYSTEMS)}
GAMEPLAY_SUBS = {"move", "shot", "ai", "rules", "ctrl", "anlz", "ball", "anim", "swan",
                 "pres", "cam", "world", "pub", "input", "stat", "math"}

# Address seeds with good locality (pinned labels). [lo, hi) -> subsystem.
SEED_RANGES = [
    (0x88640000, 0x88650000, "anim"),
    (0x88650000, 0x88658000, "math"),
    (0x88658000, 0x8865A000, "stat"),
    (0x886C8000, 0x886E8000, "swan"),
    (0x887EC000, 0x88800000, "anlz"),
    (0x88866000, 0x88870000, "rules"),
    (0x88878FA0, 0x88882000, "ball"),
    (0x88882000, 0x8888A000, "input"),
    (0x8888A000, 0x88891678, "pres"),
    (0x888AA8D0, 0x888B0000, "ball"),
    (0x888B0000, 0x888C0000, "cam"),
    (0x888C0000, 0x888E0000, "world"),
    (0x888E0000, 0x8890C000, "pub"),
    (0x8890C000, 0x88918000, "input"),
]
# The interleaved core: labelled by propagation unless anchored.
MIXED = (0x8865A000, 0x886C8000)

# Anchor names (docs/gameplay) -> subsystem. First match wins.
ANCHOR_RULES = [
    (r"^(AIReposition|AIServe|AITrigger|AI_|AIShot|AIBehaviour)", "ai"),
    (r"^(MovePlanner|Mover_|MoveSpeed|MoveConfig|Repositioning|Planner|PlannerProfile|Anim_QuerySpeed)", "move"),
    (r"^(Aim|AimSelector|AimingState|Selector_|SelectBest|Candidate|Selection|ShotPlanner|ShotSpecific|"
     r"ShotOutcome|SwingCategory|SwingRequest|SwingClip|SwingState|Charge_|TimingState|PreferForehand|"
     r"CommitSwing|ReachRow|HitPoint|ShotEditor|PlayerController_PlanShot)", "shot"),
    (r"^(Scoring|StdScoring|FirstToN|Rules_|PointJudge|ServiceJudge|RallyJudge|Rally_|Match_|Script_InitMatch)", "rules"),
    (r"^(Umpire|Crowd|Hud_)", "pres"),
    (r"^(PlayerController|PlayerCtx|PlayerState|Fatigue|InputState|InputAnalyser|Team_|Player_|Court_|"
     r"ComputeStrengths|Grade_)", "ctrl"),
    (r"^(Graph|RangeCurve|GradeRange)", "anlz"),
    (r"^(RootTrack|RootMotion|AnimSet)", "anim"),
    (r"^(Clip)", "swan"),
    (r"^(Line|Rand_)", "math"),
    (r"^(Crc32)", "eng"),
    (r"^(PlayerRating)", "glue"),
]
CONTAINER_NAME = re.compile(r"(vec|vector|string|str_|_str|sbuf|bstr|concat|list|rb_tree|hashtable|htable|"
                            r"array|span|container|realloc|reserve|resize|push|erase|uninit_copy|pool|queue)")
FPOPS = re.compile(r"^(f|lf|stf|v|lv|stv)")  # FP and vector (VMX/VMX128) mnemonics
# Like tools/audit_callees.py, but some pickle entries omit the " -> ..." suffix.
# X-form (opcode 31) FP and vector loads/stores: lfsx lfsux lfdx lfdux stfsx stfsux stfdx stfdux
# stfiwx, lvx lvxl stvx stvxl lvsl lvsr lvebx lvehx lvewx stvebx stvehx stvewx lvlx lvrx stvlx stvrx (+l forms)
X_FPVEC = {535, 567, 599, 631, 663, 695, 727, 759, 983, 103, 359, 231, 487, 6, 38, 7, 39, 71, 135, 167, 199,
           519, 551, 647, 679, 775, 807, 903, 935}
BRANCH = re.compile(r"(b|bl|bc\w*|b[a-z]+)\s+(?:cr\d,\s*)?(-?0x[0-9a-f]+)(?: ->|$)")


def sha(p):
    p = Path(p)
    return hashlib.sha256(p.read_bytes()).hexdigest() if p.exists() else "missing"


def rel(p):
    try:
        return str(Path(p).resolve().relative_to(ROOT))
    except ValueError:
        return str(p)


# ---------------------------------------------------------------- inputs

def load_functions():
    pat = re.compile(r"(\S+) = (\S+):0x([0-9A-Fa-f]+); // type:function size:0x([0-9A-Fa-f]+)")
    fns = {}
    for line in open(CFG / "symbols.txt"):
        m = pat.match(line)
        if m and m[2] == ".text":
            a = int(m[3], 16)
            fns.setdefault(a, dict(name=m[1], size=int(m[4], 16)))
    return fns


def load_status():
    m = json.loads((CFG / "match.json").read_text())
    matched = {int(x["text_range"].split("-")[0], 16) for x in m["matches"] if x.get("text_range")}
    equiv = {int(r["address"], 16) for r in json.loads((CFG / "equivalent.json").read_text())["rows"]}
    esc = {int(x["addr"], 16) for x in json.loads((Q5 / "escalate.json").read_text())}
    return matched, equiv, esc


def status_of(a, matched, equiv, esc):
    if a in matched:
        return "match"
    if a in equiv:
        return "equiv-owed"
    if a in esc:
        return "escalated"
    return "open"


def load_sisters():
    """-> {addr: (rep, [members])} from templates.json and worklist.txt '|' lines."""
    groups = []
    for t in json.loads((Q5 / "templates.json").read_text()):
        groups.append([int(t["addr"], 16)] + [int(s, 16) for s in t.get("sisters", [])])
    wl = Q5 / "worklist.txt"
    if wl.exists():
        for line in wl.read_text().splitlines():
            f = line.split()
            if f and f[0].startswith("0x") and "|" in f:
                groups.append([int(f[0], 16)] + [int(s, 16) for s in f[f.index("|") + 1:]])
    out = {}
    for g in groups:
        rep = g[0]
        if rep in out:  # merge into the existing group
            rep = out[rep][0]
        members = list(dict.fromkeys((out[rep][1] if rep in out else [rep]) + g))
        for a in members:
            out[a] = (rep, members)
    return out


def load_anchor_names():
    names = {}
    for p in sorted((ROOT / "docs/gameplay").glob("*-symbols.csv")):
        for line in p.read_text().splitlines()[1:]:
            f = line.split(",")
            if len(f) >= 3 and re.fullmatch(r"[0-9A-Fa-f]{8}", f[1]):
                names.setdefault(int(f[1], 16), f[2])
    md = ROOT / "docs/gameplay/symbols.md"
    if md.exists():
        for m in re.finditer(r"`fn_([0-9A-Fa-f]{8})` \| `([A-Za-z_][A-Za-z0-9_]*)", md.read_text()):
            names.setdefault(int(m[1], 16), m[2])
    return names


def load_vtables(fns):
    """-> list of (vtable addr, [slot addrs], [loader addrs]) resolved via symbols.txt names."""
    by_name = {v["name"]: a for a, v in fns.items()}

    def res(n):
        if n in by_name:
            return by_name[n]
        h = re.search(r"([0-9A-Fa-f]{8})$", n)
        if h and int(h[1], 16) in fns:
            return int(h[1], 16)
        return None
    out = []
    for r in json.loads((CFG / "vtables.json").read_text())["rows"]:
        slots = [x for x in (res(n) for n in r.get("functions", [])) if x is not None]
        loaders = [x for x in (res(n) for n in r.get("loaded_by", [])) if x is not None]
        out.append((int(r["vtable"], 16), slots, loaders))
    return out


# ---------------------------------------------------------------- call graph

def graph_from_pickle(fns, path):
    d = pickle.load(open(path, "rb"))
    calls, ind, fp = {}, {}, {}
    starts = sorted(fns)
    for a, f in fns.items():
        ins = d.get(a, [])
        c, n_ind, n_fp = set(), 0, 0
        for k, s in enumerate(ins):
            op = s.split(None, 1)[0] if s else ""
            if op == "bctrl":
                n_ind += 1
            if FPOPS.match(op):
                n_fp += 1
            m = BRANCH.match(s)
            if m:
                _edge(c, fns, starts, a, f["size"], a + 4 * k + int(m.group(2), 16), m.group(1) == "bl")
        calls[a], ind[a], fp[a] = c, n_ind, (n_fp / len(ins) if ins else 0.0)
    return calls, ind, fp


def graph_from_image(fns, path):
    b = open(path, "rb").read()
    e = struct.unpack_from("<I", b, 0x3C)[0]
    ns, osz = struct.unpack_from("<H", b, e + 6)[0], struct.unpack_from("<H", b, e + 20)[0]
    base = struct.unpack_from("<I", b, e + 24 + 28)[0]
    secs = [struct.unpack_from("<8sIIII", b, e + 24 + osz + 40 * i) for i in range(ns)]

    def words(addr, size):
        for _, vs, va, rs, rp in secs:
            if base + va <= addr < base + va + min(vs, rs):
                return struct.unpack_from(">%dI" % (size // 4), b, addr - base - va + rp)
        return ()
    calls, ind, fp = {}, {}, {}
    starts = sorted(fns)
    for a, f in fns.items():
        ws = words(a, f["size"])
        c, n_ind, n_fp = set(), 0, 0
        for k, w in enumerate(ws):
            op = w >> 26
            pc = a + 4 * k
            if w == 0x4E800421:
                n_ind += 1
            if op in (4, 5, 6, 59, 63) or 48 <= op <= 55 or (op == 31 and ((w >> 1) & 0x3FF) in X_FPVEC):
                n_fp += 1
            if op == 18 and not (w & 2):
                li = w & 0x03FFFFFC
                if li & 0x02000000:
                    li -= 0x04000000
                _edge(c, fns, starts, a, f["size"], pc + li, bool(w & 1))
            elif op == 16 and not (w & 2):
                bd = w & 0xFFFC
                if bd & 0x8000:
                    bd -= 0x10000
                _edge(c, fns, starts, a, f["size"], pc + bd, bool(w & 1))
        calls[a], ind[a], fp[a] = c, n_ind, (n_fp / len(ws) if ws else 0.0)
    return calls, ind, fp


def _edge(c, fns, starts, a, size, t, link):
    if a <= t < a + size and not link:
        return  # local branch
    i = bisect.bisect_right(starts, t) - 1
    if i < 0:
        return
    o = starts[i]
    if t >= o + fns[o]["size"] or o == a:
        return
    c.add(o)


# ---------------------------------------------------------------- classification

def in_ranges(a, rs):
    return any(lo <= a < hi for lo, hi, *_ in rs)


def category(a):
    """gameplay | renderer | middleware | thirdparty | game"""
    if in_ranges(a, GAMEPLAY):
        return "gameplay"
    if RENDERER[0] <= a < RENDERER[1]:
        return "renderer"
    for lo, hi, _, grp in SURVEY_RANGES:
        if lo <= a < hi:
            return {"sdk": "middleware", "lib": "thirdparty"}.get(grp, "game")
    return "game"


def survey_bucket(a):
    for lo, hi, name, _ in SURVEY_RANGES:
        if lo <= a < hi:
            return name
    return "unassigned"


def compute_scope(fns, calls, vtables):
    gp = {a for a in fns if category(a) == "gameplay"}
    scope = set(gp)
    via_vt = set()
    for _, slots, loaders in vtables:
        if any(x in gp for x in loaders):
            for s in slots:
                if s not in scope and category(s) == "game":
                    scope.add(s)
                    via_vt.add(s)
    stack = list(scope)
    ext = collections.defaultdict(set)  # category -> external leaves
    while stack:
        a = stack.pop()
        for c in calls.get(a, ()):
            if c in scope:
                continue
            k = category(c)
            if k in ("game", "gameplay"):
                scope.add(c)
                stack.append(c)
            else:
                ext[k].add(c)
    return gp, via_vt, scope, ext


# ---------------------------------------------------------------- subsystems

def assign_subsystems(fns, scope, gp, calls, vtables, fp, anchors):
    label, pinned = {}, set()
    for a in scope:
        n = anchors.get(a)
        if n:
            for pat, sid in ANCHOR_RULES:
                if re.match(pat, n):
                    label[a] = sid
                    pinned.add(a)
                    break
    for a in scope:
        if a in pinned:
            continue
        if a in gp:
            if MIXED[0] <= a < MIXED[1]:
                continue
            for lo, hi, sid in SEED_RANGES:
                if lo <= a < hi:
                    label[a] = sid
                    pinned.add(a)
                    break
            continue
        # dependency outside the gameplay ranges
        name = fns[a]["name"]
        b = survey_bucket(a)
        if fp.get(a, 0) >= 0.30 and fns[a]["size"] >= 16:
            sid = "math"
        elif CONTAINER_NAME.search(name) or b.startswith("game: core (XData, containers"):
            sid = "cont"
        elif b.startswith(("game: core (loaders", "game: Pam core")) or b == "unassigned":
            sid = "eng"
        elif b.startswith("game: ball, camera"):
            sid = "ball"
        else:
            sid = "glue"
        label[a] = sid
        pinned.add(a)
    # Weighted neighbourhood within scope. A function follows its callers more than
    # its callees (W_CALLER > W_CALLEE), class members vote for each other, and the
    # address neighbours get a small vote. Weights chosen by a hold-out test on the
    # anchored functions of the mixed core (hide half the anchors, propagate, score):
    # about 0.68 accuracy; stronger address weights made it worse (LTCG interleaving).
    W_CALLER, W_CALLEE, W_CLASS, W_ADDR = 1.0, 0.5, 4.0, 0.5
    nb = collections.defaultdict(lambda: collections.Counter())
    for a in scope:
        for c in calls.get(a, ()):
            if c in scope and c != a:
                nb[a][c] += W_CALLEE
                nb[c][a] += W_CALLER
    for _, slots, loaders in vtables:
        members = [x for x in dict.fromkeys(slots + loaders) if x in scope]
        if 2 <= len(members) <= 64:
            for x in members:
                for y in members:
                    if x != y:
                        nb[x][y] += W_CLASS / len(members)
    order = sorted(scope)
    pos = {a: i for i, a in enumerate(order)}
    free = [a for a in order if a not in pinned]
    for _ in range(50):
        changed = 0
        for a in free:
            sc = collections.Counter()
            for c, w in nb[a].items():
                lab = label.get(c)
                if lab in GAMEPLAY_SUBS and lab not in ("math", "stat"):
                    sc[lab] += w
            i = pos[a]
            for j in (i - 1, i + 1):
                if 0 <= j < len(order):
                    lab = label.get(order[j])
                    if lab in GAMEPLAY_SUBS and lab not in ("math", "stat"):
                        sc[lab] += W_ADDR
            if not sc:
                continue
            best = max(sc.items(), key=lambda kv: (kv[1], -SUB_ORDER[kv[0]]))[0]
            if label.get(a) != best:
                label[a] = best
                changed += 1
        if not changed:
            break
    # leftovers: nearest labelled function by address
    for a in free:
        if a not in label:
            i = pos[a]
            for d in range(1, len(order)):
                for j in (i - d, i + d):
                    if 0 <= j < len(order) and label.get(order[j]) in GAMEPLAY_SUBS:
                        label[a] = label[order[j]]
                        break
                if a in label:
                    break
            label.setdefault(a, "ctrl")
    return label, pinned


# ---------------------------------------------------------------- levels

def sccs(nodes, edges):
    """Iterative Tarjan. edges: {a: iterable}; only nodes in `nodes`. -> {node: scc id}"""
    index, low, on, st, comp = {}, {}, set(), [], {}
    cid = 0
    counter = 0
    for root in sorted(nodes):
        if root in index:
            continue
        work = [(root, iter(sorted(edges.get(root, ()))))]
        index[root] = low[root] = counter
        counter += 1
        st.append(root)
        on.add(root)
        while work:
            v, it = work[-1]
            pushed = False
            for w in it:
                if w not in nodes:
                    continue
                if w not in index:
                    index[w] = low[w] = counter
                    counter += 1
                    st.append(w)
                    on.add(w)
                    work.append((w, iter(sorted(edges.get(w, ())))))
                    pushed = True
                    break
                if w in on:
                    low[v] = min(low[v], index[w])
            if pushed:
                continue
            work.pop()
            if work:
                low[work[-1][0]] = min(low[work[-1][0]], low[v])
            if low[v] == index[v]:
                while True:
                    w = st.pop()
                    on.discard(w)
                    comp[w] = cid
                    if w == v:
                        break
                cid += 1
    return comp


def levels(scope, edges, solved):
    """Levels over unsolved in-scope functions. -> (level{addr}, scc{addr}, sccsize{id})"""
    todo = {a for a in scope if a not in solved}
    comp = sccs(todo, edges)
    members = collections.defaultdict(list)
    for a, c in comp.items():
        members[c].append(a)
    dag = collections.defaultdict(set)
    for a in todo:
        for c in edges.get(a, ()):
            if c in todo and comp[c] != comp[a]:
                dag[comp[a]].add(comp[c])
    lev = {}
    # Tarjan emits SCCs in reverse topological order (callees first).
    for c in sorted(members):
        lev[c] = 1 + max((lev[d] for d in dag[c]), default=-1)
    return {a: lev[comp[a]] for a in todo}, comp, {c: len(m) for c, m in members.items()}


# ---------------------------------------------------------------- output

def runs_of(addrs_sorted_scope, label, sid, fns):
    """Contiguous runs (in scope address order) of subsystem sid -> [(lo, hi, bytes)]."""
    out, cur = [], None
    for a in addrs_sorted_scope:
        if label[a] == sid:
            if cur is None:
                cur = [a, a + fns[a]["size"], fns[a]["size"]]
            else:
                cur[1] = a + fns[a]["size"]
                cur[2] += fns[a]["size"]
        elif cur is not None:
            out.append(tuple(cur))
            cur = None
    if cur is not None:
        out.append(tuple(cur))
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--dis", default=str(ROOT / "work/army/VX1/textdis.pkl"))
    ap.add_argument("--image", help="decode orig/54540859/Swing_DLL.dll instead of the pickle")
    ap.add_argument("--out-dir", default=str(Q5))
    ap.add_argument("--check", action="store_true", help="check every worklist.txt gameplay entry is in scope")
    a = ap.parse_args()

    fns = load_functions()
    if a.image or not Path(a.dis).exists():
        src = a.image or str(ROOT / "orig/54540859/Swing_DLL.dll")
        calls, ind, fp = graph_from_image(fns, src)
        dis_desc = f"--image {rel(src)}"
    else:
        src = a.dis
        calls, ind, fp = graph_from_pickle(fns, src)
        dis_desc = f"--dis {rel(src)}"
    matched, equiv, esc = load_status()
    vtables = load_vtables(fns)
    anchors = load_anchor_names()
    sisters = load_sisters()

    gp, via_vt, scope, ext = compute_scope(fns, calls, vtables)
    deps = scope - gp
    label, pinned = assign_subsystems(fns, scope, gp, calls, vtables, fp, anchors)
    edges = {x: {c for c in calls.get(x, ()) if c in scope and c != x} for x in scope}
    lev, comp, csize = levels(scope, edges, matched)

    if a.check:
        bad = []
        for line in (Q5 / "worklist.txt").read_text().splitlines():
            f = line.split()
            if f and f[0].startswith("0x") and "gameplay" in f:
                for s in [f[0]] + (f[f.index("|") + 1:] if "|" in f else []):
                    if int(s, 16) not in gp:
                        bad.append(s)
        print(f"worklist.txt gameplay entries outside the gameplay set: {len(bad)} {bad[:10]}")

    B = lambda s: sum(fns[x]["size"] for x in s)  # noqa: E731
    ext_counts = {k: (len(v), B(v)) for k, v in sorted(ext.items())}
    ready = sorted(x for x in lev if lev[x] == 0)
    n_ind = sum(ind.get(x, 0) for x in scope)
    n_ind_fns = sum(1 for x in scope if ind.get(x, 0))

    inputs = [CFG / "symbols.txt", CFG / "match.json", CFG / "equivalent.json", CFG / "vtables.json",
              Q5 / "escalate.json", Q5 / "templates.json", Q5 / "worklist.txt",
              ROOT / "docs/gameplay/movement-symbols.csv", ROOT / "docs/gameplay/rules-symbols.csv",
              ROOT / "docs/gameplay/swing-symbols.csv", ROOT / "docs/gameplay/symbols.md", Path(src)]
    cmd = f"python3 tools/callgraph_worklist.py {dis_desc}"
    out = Path(a.out_dir)

    per = collections.defaultdict(list)
    for x in scope:
        per[label[x]].append(x)
    stat = lambda x: status_of(x, matched, equiv, esc)  # noqa: E731

    # ---------------- worklist_v2.txt
    L = []
    L.append("# Q5 work list v2: bottom-up through the call graph, by subsystem (owner plan 2026-11-23).")
    L.append(f"# Generated by: {cmd}")
    L.append(f"# Tool: {VERSION}; python {sys.version.split()[0]}")
    for p in inputs:
        L.append(f"# input {rel(p)} sha256 {sha(p)}")
    L.append(f"# Scope: gameplay {len(gp)} fns {B(gp)} B; added dependencies {len(deps)} fns {B(deps)} B "
             f"({len(via_vt)} via vtables of gameplay classes); total {len(scope)} fns {B(scope)} B.")
    L.append("# External leaves (not in scope): " + ", ".join(f"{k} {n} fns {b} B" for k, (n, b) in ext_counts.items()))
    L.append(f"# Indirect calls (bctrl) in scope: {n_ind} in {n_ind_fns} functions; not resolved, "
             "not used for levels (class methods are attached through vtables.json).")
    L.append("# level=N: N=0 ready now (every in-scope direct callee outside its SCC is matched); "
             "level=- already matched. scc=K marks a recursive group that must be solved together.")
    L.append("# status at generation time: match | equiv-owed (byte match still owed) | escalated | open. "
             "tools/q5_status.py --worklist v2 recomputes status and readiness live.")
    L.append("# | 0xS ...  = sister functions of this group representative (templates.json, worklist.txt); "
             "| rep=0xR = this is a sister of 0xR.")
    L.append(f"# Ready now: {len(ready)} fns {B(ready)} B.")
    for sid, sname in SUBSYSTEMS:
        xs = per.get(sid, [])
        if not xs:
            continue
        nm = sum(x in matched for x in xs)
        L.append("")
        L.append(f"## {sid}: {sname} ({len(xs)} fns, {B(xs)} B, {nm} matched)")
        xs.sort(key=lambda x: (lev[x] if x in lev else 1 << 30, x))  # unsolved by level, matched last
        for x in xs:
            lv = "-" if x in matched else str(lev[x])
            line = f"0x{x:08x} {fns[x]['size']} level={lv} status={stat(x)}"
            if x not in matched and csize[comp[x]] > 1:
                line += f" scc={comp[x]}"
            if x in sisters:
                rep, members = sisters[x]
                if rep == x:
                    line += " | " + " ".join(f"0x{m:08x}" for m in members if m != x)
                else:
                    line += f" | rep=0x{rep:08x}"
            L.append(line)
    (out / "worklist_v2.txt").write_text("\n".join(L) + "\n")

    # ---------------- scope_callgraph.json (edges of unsolved functions only: a matched
    # function's callees no longer matter for readiness)
    cg_lines = [f'"0x{x:08x}": [' + ", ".join(f'"0x{c:08x}"' for c in sorted(edges[x])) + "]"
                for x in sorted(scope) if x not in matched]
    (out / "scope_callgraph.json").write_text(
        "{\n" + f'"generated_by": {json.dumps(cmd)},\n"tool": {json.dumps(VERSION)},\n'
        '"note": "In-scope direct callees (bl and tail branches) of every Q5 v2 scope function that was not matched '
        'at generation time; addresses only. Read by tools/q5_status.py --worklist v2.",\n'
        '"edges": {\n' + ",\n".join(cg_lines) + "\n}\n}\n")

    # ---------------- subsystems.md
    order = sorted(scope)
    callers = collections.defaultdict(set)
    for x in scope:
        for c in edges[x]:
            callers[c].add(x)
    vt_by_sub = collections.defaultdict(list)
    for va, slots, loaders in vtables:
        ms = [s for s in slots if s in scope]
        if len(ms) >= 2:
            cnt = collections.Counter(label[s] for s in ms)
            sid, n = cnt.most_common(1)[0]
            vt_by_sub[sid].append((len(ms), va))
    M = []
    M.append("# Q5 subsystems (worklist v2)")
    M.append("")
    M.append(f"Generated by `{cmd}` ({VERSION}); see the header of `worklist_v2.txt` for input hashes. "
             "Do not edit by hand.")
    M.append("")
    M.append("## Scope")
    M.append("")
    M.append("| part | fns | bytes | matched |")
    M.append("|---|---:|---:|---:|")
    M.append(f"| gameplay set (address ranges below) | {len(gp)} | {B(gp)} | {sum(x in matched for x in gp)} |")
    M.append(f"| added dependencies (non-middleware callees, transitive) | {len(deps)} | {B(deps)} | "
             f"{sum(x in matched for x in deps)} |")
    M.append(f"| of which slots of gameplay-class vtables | {len(via_vt)} | {B(via_vt)} | "
             f"{sum(x in matched for x in via_vt)} |")
    M.append(f"| **total scope** | **{len(scope)}** | **{B(scope)}** | **{sum(x in matched for x in scope)}** |")
    for k, (n, b) in ext_counts.items():
        M.append(f"| external leaves: {k} | {n} | {b} | (excluded) |")
    M.append("")
    M.append(f"Ready now (unmatched, every in-scope callee matched): **{len(ready)} fns, {B(ready)} B**. "
             f"Indirect calls (`bctrl`) in scope: {n_ind} in {n_ind_fns} functions (not resolved).")
    M.append("")
    M.append("Gameplay ranges: " + "; ".join(f"0x{lo:08X}-0x{hi:08X} {n}" for lo, hi, n in GAMEPLAY) + ".")
    M.append("")
    M.append("## Subsystems")
    M.append("")
    M.append("| id | name | main address ranges | fns | bytes | matched | ready | key classes (vtable, slots in scope) | entry points |")
    M.append("|---|---|---|---:|---:|---:|---:|---|---|")
    for sid, sname in SUBSYSTEMS:
        xs = per.get(sid, [])
        if not xs:
            continue
        rs = sorted(runs_of(order, label, sid, fns), key=lambda r: -r[2])
        nb = sum(r[2] for r in rs)
        top = [r for r in rs[:3]]
        rtxt = ", ".join(f"0x{lo:08X}-0x{hi:08X}" for lo, hi, _ in sorted(top))
        cover = sum(r[2] for r in top)
        rtxt += f" ({100 * cover // max(nb, 1)}% of bytes; {len(rs)} runs)"
        vts = sorted(vt_by_sub.get(sid, []), reverse=True)[:3]
        vtxt = ", ".join(f"0x{va:08X} ({n})" for n, va in vts) or "-"
        roots = [x for x in xs if not any(label[c] == sid for c in callers[x])]
        named = [x for x in roots if x in anchors]
        pick = sorted(named, key=lambda x: -fns[x]["size"])[:3]
        pick += sorted((x for x in roots if x not in pick), key=lambda x: -fns[x]["size"])[:4 - len(pick)]
        etxt = ", ".join(f"{anchors[x]} 0x{x:08X}" if x in anchors else f"0x{x:08X}" for x in pick)
        nm = sum(x in matched for x in xs)
        nr = sum(1 for x in xs if lev.get(x) == 0)
        M.append(f"| `{sid}` | {sname} | {rtxt} | {len(xs)} | {B(xs)} | {nm} | {nr} | {vtxt} | {etxt} |")
    M.append("")
    M.append("## Method")
    M.append("")
    M.append("- Call graph: `bl` targets and branches leaving the function (tail calls), from the pickled "
             "disassembly or raw words; `bctrl` counted only.")
    M.append("- Scope: gameplay ranges + slots of vtables loaded by gameplay functions + transitive direct callees "
             "that are game code. Middleware (decomp_survey `sdk` buckets: Havok, FMOD, XDK/D3D/CRT, Bink), "
             "third-party libraries with public source (decomp_survey `lib` buckets: Lua, zlib, expat, "
             "libpng/libjpeg, trio) and the renderer (0x886E8000-0x88780000) are external leaves.")
    M.append("- Subsystems: names in docs/gameplay/*-symbols.csv and symbols.md anchor functions; address "
             "ranges with good locality are pinned; the interleaved core 0x8865A000-0x886C8000 is labelled by "
             "label propagation over call edges, vtable class membership and address neighbours; dependencies "
             "are grouped by address bucket (FP/VMX-heavy helpers -> `math`, container/string names -> `cont`).")
    M.append("- Levels: Tarjan SCCs over unmatched in-scope functions; level 0 = ready now. Equivalent and "
             "escalated functions count as unsolved (byte-exact only).")
    M.append("- Status: `python3 tools/q5_status.py --worklist v2` (per subsystem); next ready work: "
             "`python3 tools/q5_status.py --worklist v2 --next 20 --subsystem move`.")
    (out / "subsystems.md").write_text("\n".join(M) + "\n")

    # ---------------- console summary
    print(f"gameplay {len(gp)} fns {B(gp)} B; deps {len(deps)} fns {B(deps)} B (vtable {len(via_vt)}); "
          f"scope {len(scope)} fns {B(scope)} B; matched {sum(x in matched for x in scope)}")
    print("external leaves:", ext_counts)
    print(f"ready now {len(ready)} fns {B(ready)} B; max level {max(lev.values(), default=0)}; "
          f"nontrivial SCCs {sum(1 for c, n in csize.items() if n > 1)}")
    for sid, sname in SUBSYSTEMS:
        xs = per.get(sid, [])
        print(f"  {sid:<6}{len(xs):>6}{B(xs):>9}{sum(x in matched for x in xs):>7}"
              f"{sum(1 for x in xs if lev.get(x) == 0):>6}  {sname}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
