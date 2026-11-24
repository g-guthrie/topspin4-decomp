#!/usr/bin/env python3
"""LTCG context finder: read what the target's code proves about its link, and build that link.

Usage:
  python3 tools/ltcg_ctx_find.py evidence 0xADDR [0xADDR ...] [--json]
  python3 tools/ltcg_ctx_find.py find SRC name=0xADDR [--flags /Oc] [--tries 12] [--stand-in PATH ...]
                                      [--no-drafts] [--keep] [--json OUT]
  python3 tools/ltcg_ctx_find.py kills SRC name=0xADDR [...] [--flags /Oc] [--context C ...]

Why: code generated at link time (/GL + /LTCG, docs/ltcg-route.md) depends on the bodies of the
callees. The Xbox 360 back end records, per function, the volatile registers its body (and
everything it calls) writes; a caller keeps a value in a volatile register across a call when
the callee leaves that register alone. A single-object compile can never do that: every call
kills r0, r3-r12 and f0-f13. So a value that stays in such a register across a `bl` in the
original is proof that the link saw the callee's body, and it is a constraint on that body:
the callee, and everything the callee calls, must not write the register. A callee that is
missing from our link (a stub: every volatile register killed), or whose source compiles to
another register set under /GL, costs the caller its match however good the caller's source is.

`evidence` (static, no compiler) reads the original function and prints
  - each call site, the volatile registers live across it ("kept") and the registers the
    callee really writes, transitively, in the original image;
  - the call closure below every callee that keeps a register: each member must have a body
    in the link, to any depth (tools/fn_check_ltcg.py --auto-context goes one or two levels);
  - for each member the sources that can supply the body: the matched source, a recorded
    stand-in, an equivalent-route source (config/54540859/equivalent.json) or a near-miss
    draft (src/xbox360/drafts/*<ADDR>*). The last two are not byte-exact, but their bodies
    usually write the same registers, which is all the caller needs;
  - the verdict: LTCG PROVEN (a register other than the callee's own r3/f1 pass-through is
    kept), LTCG LIKELY (only r3/f1 stay: `return self` gives the same code in plain C) or
    no evidence.

`find` starts from the context list of `fn_check_ltcg.py --auto-context`, adds the closure
members it lacks, links once and then compares, per callee, the registers its body writes in
OUR link with the original's (the kill sets), and per call site the registers the candidate
keeps with the target's. From that diagnosis it tries targeted repairs, at most --tries links:
  - a member with no body: each stand-in source (equivalent source, draft, --stand-in PATH);
    a stand-in that names the function differently is wrapped with a `#define` in a scratch
    copy (work/residue/ctx/, printed) so the caller's reference binds to it;
  - a body that writes a register the target keeps: /Ob1 on or off for its source, its
    /INCLUDE dropped, another source for it;
  - the pool primer dropped (a literal the original keeps in another pool).
It prints every link's score (differing instructions) with the kill-set differences that
remain, and the explicit fn_check_ltcg.py command of the best link. The verdict that counts is
that command's: this tool never declares a match by itself.

`kills` links one source under /GL and prints, for each named function, the registers its body
writes against the original's: the test of whether a draft can stand in for a callee (a draft
that is 40 instructions off can still have the original's kill set, and one that is 2 off
can miss it).

Exit status: evidence 0; find 0 when the best link is a MATCH, else 1; kills 0 when every
kill set equals the original's.
Nothing in the repository is modified. Scratch goes to TS4_LTCG_SCRATCH (or work/).
"""
from __future__ import annotations

import argparse
import json
import os
import re
import shlex
import shutil
import subprocess
import sys
from dataclasses import dataclass, field
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))

import fn_equiv as fe  # noqa: E402  (decoder, Func, Analysis: read only)

VOLATILE = fe.VOLATILE
PASS_THROUGH = frozenset((3, 33))        # r3, f1: a callee that returns its argument keeps them in plain C too
HEX8 = re.compile(r"(?<![0-9A-Fa-f])(88[0-9A-Fa-f]{6})(?![0-9A-Fa-f])")


def reg_name(r: int) -> str:
    return f"r{r}" if r < 32 else f"f{r - 32}"


def reg_list(regs) -> str:
    return ",".join(reg_name(r) for r in sorted(regs)) or "-"


# --------------------------------------------------------------------------- static evidence

@dataclass
class CallSite:
    pc: int
    target: int | None           # None: indirect call
    kind: str                    # "bl", "tail" or "indirect"
    kept: frozenset              # volatile registers live across the call that the callee leaves alone
    defs: frozenset              # volatile registers the callee writes (transitively)


def _is_call(func, ins) -> bool:
    return ins.kind == "bl" or (ins.kind in ("b", "bc") and ins.target is not None and not func.inside(ins.target))


def call_sites(analysis, addr: int, is_helper=lambda a: False) -> list[CallSite] | None:
    """Per call site of the function at addr: the volatile registers whose value crosses the
    call. Backward liveness over the function's blocks; a call reads what its callee reads
    (Analysis.live_in) and writes what its callee writes (Analysis.defs_of); nothing is live
    at the exits, so a value is only "kept" when the function itself reads it afterwards."""
    func = analysis.func(addr)
    if func is None:
        return None
    succ = func.succ()
    nb = len(func.blocks)

    def step(i, live, out=None):
        ins = func.insns[i]
        kind = ins.kind
        reads, writes = set(ins.reads), set(ins.writes)
        if _is_call(func, ins):
            if is_helper(ins.target):
                return live                      # __savegprlr and friends: no volatile state crosses
            defs = analysis.defs_of(ins.target)
            uses = analysis.live_in(ins.target)
            if out is not None and kind == "bl":
                out.append(CallSite(func.base + 4 * i, ins.target, "bl",
                                    frozenset((live & VOLATILE) - defs), frozenset(defs & VOLATILE)))
            elif out is not None:
                out.append(CallSite(func.base + 4 * i, ins.target, "tail", frozenset(), frozenset(defs & VOLATILE)))
            reads |= {3} if uses is None else set(uses)
            if kind in ("b", "bc"):
                return (live | reads) if kind == "bc" else reads
            writes |= defs
        elif kind == "bctrl" or kind == "bcctr" or (kind == "bctr" and i not in func.tables):
            if out is not None and kind == "bctrl":
                out.append(CallSite(func.base + 4 * i, None, "indirect", frozenset(), VOLATILE))
            reads.add(3)
            writes |= VOLATILE
        return (live - writes) | reads

    live_in = [set() for _ in range(nb)]
    changed = True
    while changed:
        changed = False
        for b in range(nb - 1, -1, -1):
            s, e = func.blocks[b]
            live = set()
            for j in succ[b]:
                live |= live_in[j]
            for i in range(e - 1, s - 1, -1):
                live = step(i, live)
            if live != live_in[b]:
                live_in[b], changed = live, True
    sites: list[CallSite] = []
    for b in range(nb):
        s, e = func.blocks[b]
        live = set()
        for j in succ[b]:
            live |= live_in[j]
        for i in range(e - 1, s - 1, -1):
            live = step(i, live, sites)
    return sorted(sites, key=lambda c: c.pc)


def callees_of(analysis, addr: int, is_helper=lambda a: False) -> list[int] | None:
    func = analysis.func(addr)
    if func is None:
        return None
    out = []
    for i, ins in enumerate(func.insns):
        if i in func.data:
            continue
        if _is_call(func, ins) and not is_helper(ins.target) and ins.target not in out:
            out.append(ins.target)
        for t in func.tables.get(i, ()):
            if not func.inside(t) and t not in out:
                out.append(t)
    return out


def closure(analysis, addr: int, is_helper=lambda a: False) -> list[int]:
    """addr and everything reachable from it by direct calls, in discovery order."""
    seen, todo = [], [addr]
    while todo:
        a = todo.pop(0)
        if a in seen:
            continue
        seen.append(a)
        todo += callees_of(analysis, a, is_helper) or []
    return seen


def kept_by_callee(sites: list[CallSite]) -> dict[int, frozenset]:
    out: dict[int, set] = {}
    for s in sites:
        if s.kind == "bl" and s.kept:
            out.setdefault(s.target, set()).update(s.kept)
    return {a: frozenset(v) for a, v in out.items()}


def verdict(sites: list[CallSite]) -> str:
    kept = set().union(*(s.kept for s in sites)) if sites else set()
    if kept - PASS_THROUGH:
        return "LTCG PROVEN"
    if kept:
        return "LTCG LIKELY"
    return "no evidence"


def kill_diff(orig: frozenset, cand: frozenset) -> tuple[frozenset, frozenset]:
    """(extra, missing): volatile registers only the candidate body writes / only the original."""
    o, c = orig & VOLATILE, cand & VOLATILE
    return frozenset(c - o), frozenset(o - c)


# --------------------------------------------------------------------------- repository sources

@dataclass(frozen=True)
class Body:
    source: str      # repository-relative path
    symbol: str      # the function's name in that source
    origin: str      # match / spec / stand-in / equiv / draft / given


def draft_symbol(text: str, address: int) -> str | None:
    """The name a draft gives the function at address: an identifier that carries the address."""
    h = f"{address:08X}"
    for name in re.findall(r"\b([A-Za-z_]\w*)\s*\([^;{}()]*\)\s*\{", text):
        if h.lower() in name.lower():
            return name
    return None


def stand_ins(root: Path, address: int, extra: list[str] = (), drafts: bool = True) -> list[Body]:
    """Sources that are not byte-exact but define the function at address."""
    out: list[Body] = []
    reg = root / "config" / "54540859" / "equivalent.json"
    if reg.is_file():
        for row in json.loads(reg.read_text()).get("rows", []):
            if int(row["address"], 16) == address and (root / row["source"]).is_file():
                out.append(Body(row["source"], row["function"], "equiv"))
    paths = [Path(p) for p in extra]
    if drafts:
        paths += sorted((root / "src" / "xbox360" / "drafts").glob(f"*{address:08X}*")) + \
                 sorted((root / "src" / "xbox360" / "drafts").glob(f"*{address:08x}*"))
    for path in paths:
        full = path if path.is_absolute() else root / path
        if not full.is_file() or full.suffix not in (".c", ".cpp"):
            continue
        name = draft_symbol(full.read_text(errors="replace"), address)
        rel = os.path.relpath(full, root)
        if name and all(b.source != rel for b in out):
            out.append(Body(rel, name, "given" if path in [Path(p) for p in extra] else "draft"))
    return out


def names_in(text: str, address: int) -> list[str]:
    """Identifiers of a source that carry the address (how it calls the function there)."""
    h = f"{address:08x}"
    return list(dict.fromkeys(n for n in re.findall(r"\b[A-Za-z_]\w*\b", text) if h in n.lower()))


def wrap_noinline(root: Path, source: str, symbol: str, outdir: Path) -> str:
    """A context that includes `source` and keeps `symbol` out of line without /Ob1.

    /Ob1 on a callee's source also stops the callee from inlining its own plain `static`
    helpers, which changes the registers its body writes; __declspec(noinline) on the one
    function does not."""
    outdir.mkdir(parents=True, exist_ok=True)
    src = root / source
    dst = outdir / f"ni_{symbol}{src.suffix}"
    dst.write_text(f"/* context generated by tools/ltcg_ctx_find.py: {source} with {symbol} kept out of line */\n"
                   f"#define {symbol} __declspec(noinline) {symbol}\n#include \"{src.name}\"\n")
    return os.path.relpath(dst, root)


def wrap_stand_in(root: Path, body: Body, wanted: str, outdir: Path) -> str:
    """A scratch copy of a stand-in whose function is renamed to `wanted` by a #define."""
    outdir.mkdir(parents=True, exist_ok=True)
    src = root / body.source
    dst = outdir / f"ctx_{wanted}{src.suffix}"
    dst.write_text(f"/* stand-in context generated by tools/ltcg_ctx_find.py from {body.source} */\n"
                   f"#define {body.symbol} {wanted}\n" + src.read_text(errors="replace"))
    return os.path.relpath(dst, root)


# --------------------------------------------------------------------------- the candidate link

class LinkView:
    """Register facts of a kept fn_check_ltcg scratch link (out.dll + out.map)."""

    def __init__(self, workdir: Path, L):
        self.L = L
        self.image = L.parse_pe((workdir / "out.dll").read_bytes())
        self.symbols = L.parse_map((workdir / "out.map").read_text(errors="replace"))
        self.by_name = {}
        self.stub = set()
        self.helper = set()
        for s in self.symbols:
            self.by_name.setdefault(s.name, s.address)
            if s.obj == "lt1stubs.obj":
                self.stub.add(s.address)
                if s.name.startswith(fe.HELPER_PREFIXES):
                    self.helper.add(s.address)
        alias_file = workdir / "link.rsp"
        self.alias = {}
        if alias_file.is_file():
            for m in re.finditer(r"/ALTERNATENAME:(\S+?)=(\S+)", alias_file.read_text()):
                self.alias[m.group(2)] = m.group(1)       # external name -> stub name
        self._ext = {}
        self.analysis = fe.Analysis(self.code_of, lambda a: a in self.helper)

    def address(self, name: str) -> int | None:
        if name in self.by_name:
            return self.by_name[name]
        stub = self.alias.get(name)
        return self.by_name.get(stub) if stub else None

    def is_stub(self, address: int) -> bool:
        return address in self.stub

    def code_of(self, address: int):
        if address in self.stub:
            return None
        if address not in self._ext:
            try:
                n = self.L.function_extent(self.image, self.symbols, address)
                code = self.image.read(address, n) if 0 < n < 0x40000 else None
                while code and code[-4:] == b"\0\0\0\0":     # alignment padding up to the next symbol
                    code = code[:-4]
                self._ext[address] = code or None
            except Exception:
                self._ext[address] = None
        return self._ext[address]

    def name_at(self, address: int) -> str:
        for s in self.symbols:
            if s.address == address:
                for ext, stub in self.alias.items():
                    if stub == s.name:
                        return ext
                return s.name
        return f"{address:08X}"


@dataclass
class Diagnosis:
    score: int | None                       # differing instructions; 0 with ok = MATCH
    ok: bool
    problems: list[str]
    members: dict[int, dict] = field(default_factory=dict)   # original address -> facts
    kept_target: dict[str, frozenset] = field(default_factory=dict)
    kept_cand: dict[str, frozenset] = field(default_factory=dict)

    def bad(self) -> list[int]:
        """Members to repair, worst first: no body under a kept register, a body that writes
        a kept register, then any direct callee whose kill set is not the original's."""
        def rank(item):
            a, m = item
            if m["state"] in ("stub", "absent"):
                return 0 if m["need"] else 3
            if m.get("breaks"):
                return 1
            if m.get("extra") or m.get("missing"):
                return 2
            return 9
        out = sorted(self.members.items(), key=rank)
        return [a for a, m in out if rank((a, m)) < 3]

    def blocking(self) -> list[int]:
        return [a for a, m in self.members.items()
                if (m["state"] in ("stub", "absent") and m["need"]) or m.get("breaks")]


def diagnose(view: LinkView, world, cand_name: str, target: int, names: dict[int, list[str]],
             need: dict[int, frozenset], members: list[int], result) -> Diagnosis:
    """Compare kill sets and kept registers of the candidate link with the original."""
    score = len(result.diff_words) if result is not None else None
    d = Diagnosis(score, bool(result and result.ok), list(result.problems) if result else ["not in the linked image"])
    in_helper = world.in_helper
    for a in members:
        addr_c = next((view.address(n) for n in names.get(a, []) if view.address(n) is not None), None)
        orig = world.analysis.defs_of(a) & VOLATILE
        m = {"name": world.label(a), "orig": orig, "need": need.get(a, frozenset())}
        if addr_c is None:
            m["state"] = "absent"            # inlined everywhere, or never referenced by the candidate
        elif view.is_stub(addr_c):
            m["state"] = "stub"              # no body in the link: opaque, every volatile register killed
        else:
            cand = view.analysis.defs_of(addr_c) & VOLATILE
            extra, missing = kill_diff(orig, cand)
            m.update(state="body", extra=extra, missing=missing, breaks=frozenset(extra & m["need"]))
        d.members[a] = m
    t_sites = call_sites(world.analysis, target, in_helper) or []
    for s in t_sites:
        if s.kind == "bl":
            key = world.label(s.target)
            d.kept_target[key] = d.kept_target.get(key, frozenset()) | s.kept
    c_addr = view.address(cand_name)
    if c_addr is not None and not view.is_stub(c_addr):
        for s in call_sites(view.analysis, c_addr, lambda a: a in view.helper) or []:
            if s.kind == "bl":
                key = view.name_at(s.target)
                d.kept_cand[key] = d.kept_cand.get(key, frozenset()) | s.kept
    return d


def format_diagnosis(d: Diagnosis) -> list[str]:
    lines = []
    for a, m in d.members.items():
        need = f" (target keeps {reg_list(m['need'])} across it)" if m["need"] else ""
        if m["state"] == "stub":
            lines.append(f"    {m['name']}: NO BODY in the link (stub: all volatile registers killed){need}")
        elif m["state"] == "absent":
            lines.append(f"    {m['name']}: not in the linked image (inlined or not referenced){need}")
        elif m["extra"] or m["missing"]:
            tag = f" BREAKS {reg_list(m['breaks'])}" if m["breaks"] else ""
            lines.append(f"    {m['name']}: body writes +[{reg_list(m['extra'])}] -[{reg_list(m['missing'])}] "
                         f"against the original{tag}{need}")
        else:
            lines.append(f"    {m['name']}: kill set equal to the original ({reg_list(m['orig'])}){need}")
    tk = {k: v for k, v in d.kept_target.items() if v}
    ck = {k: v for k, v in d.kept_cand.items() if v}
    if tk or ck:
        lines.append("    kept across calls, target:    " + ("; ".join(f"{k} {reg_list(v)}" for k, v in tk.items()) or "-"))
        lines.append("    kept across calls, candidate: " + ("; ".join(f"{k} {reg_list(v)}" for k, v in ck.items()) or "-"))
    return lines


# --------------------------------------------------------------------------- evidence command

def gather(world, address: int, root: Path, source_map, extra=(), drafts=True) -> dict:
    """Everything `evidence` prints, as data."""
    an, helper = world.analysis, world.in_helper
    sites = call_sites(an, address, helper)
    if sites is None:
        return {"address": address, "error": "no function at this address"}
    need = kept_by_callee(sites)
    direct = [s.target for s in sites if s.kind != "indirect"]
    members: list[int] = []
    for a in dict.fromkeys(direct):
        for m in (closure(an, a, helper) if a in need else [a]):
            if m not in members and m != address:
                members.append(m)
    # a register kept across a call constrains every function below the callee
    need_all: dict[int, set] = {}
    for a, regs in need.items():
        for m in closure(an, a, helper):
            need_all.setdefault(m, set()).update(regs)
    rows = []
    for m in members:
        bodies = [Body(c.source, c.symbol, c.origin) for c in source_map.get(m, [])]
        matched = any(b.origin in ("match", "spec") for b in bodies)
        if not matched:
            bodies += [b for b in stand_ins(root, m, extra, drafts) if all(b.source != x.source for x in bodies)]
        rows.append({"address": m, "name": world.label(m), "direct": m in direct, "matched": matched,
                     "need": frozenset(need_all.get(m, ())), "kills": an.defs_of(m) & VOLATILE, "bodies": bodies})
    return {"address": address, "name": world.label(address), "sites": sites, "need": need,
            "members": rows, "verdict": verdict(sites),
            "indirect": sum(1 for s in sites if s.kind == "indirect")}


def print_evidence(world, ev: dict) -> None:
    if "error" in ev:
        print(f"{ev['address']:08X}: {ev['error']}")
        return
    print(f"{ev['name']} @ {ev['address']:08X}: {ev['verdict']}"
          f" ({len(ev['sites'])} call site(s), {ev['indirect']} indirect)")
    for s in ev["sites"]:
        if s.kind == "indirect":
            continue
        tag = "tail " if s.kind == "tail" else ""
        print(f"  {s.pc:08X} {tag}{world.label(s.target)}: kept {reg_list(s.kept)}; callee writes {reg_list(s.defs)}")
    for row in ev["members"]:
        if not row["need"] and row["matched"]:
            continue
        state = "matched" if row["matched"] else "UNMATCHED"
        src = ", ".join(f"{b.source} [{b.origin}]" for b in row["bodies"]) or "no source"
        need = f" must not write {reg_list(row['need'])};" if row["need"] else ""
        depth = "callee" if row["direct"] else "below a callee"
        print(f"  body needed ({depth}): {row['name']} {state};{need} {src}")
    blockers = [r for r in ev["members"] if r["need"] and not r["matched"]]
    if blockers:
        usable = [r for r in blockers if r["bodies"]]
        print(f"  => {len(blockers)} unmatched function(s) under a kept register"
              f" ({len(usable)} with a stand-in source): " + ", ".join(r["name"] for r in blockers))


def evidence_json(ev: dict) -> dict:
    if "error" in ev:
        return {"address": f"0x{ev['address']:08X}", "error": ev["error"]}
    return {
        "address": f"0x{ev['address']:08X}", "name": ev["name"], "verdict": ev["verdict"],
        "sites": [{"pc": f"0x{s.pc:08X}", "target": None if s.target is None else f"0x{s.target:08X}",
                   "kind": s.kind, "kept": reg_list(s.kept), "writes": reg_list(s.defs)} for s in ev["sites"]],
        "members": [{"address": f"0x{r['address']:08X}", "name": r["name"], "direct": r["direct"],
                     "matched": r["matched"], "need": reg_list(r["need"]), "kills": reg_list(r["kills"]),
                     "bodies": [[b.source, b.symbol, b.origin] for b in r["bodies"]]} for r in ev["members"]],
    }


# --------------------------------------------------------------------------- find command

def auto_command(source: Path, mapping: str, flags: list[str], env: dict) -> tuple[list[str], list[str], str]:
    """Contexts and includes fn_check_ltcg.py --auto-context chooses (its printed explicit command)."""
    cmd = [sys.executable, str(ROOT / "tools" / "fn_check_ltcg.py"), str(source), mapping,
           "--auto-context", "--auto-depth", "2", "--auto-no-fallback", "--quiet"]
    if flags:
        cmd += ["--flags", *flags]
    r = subprocess.run(cmd, capture_output=True, text=True, cwd=ROOT, env=env)
    out = r.stdout + r.stderr
    m = re.search(r"^explicit command: (.*)$", out, re.M)
    contexts, includes = [], []
    if m:
        parts = shlex.split(m.group(1))
        for i, p in enumerate(parts):
            if p == "--context":
                contexts.append(parts[i + 1])
            elif p == "--include":
                includes.append(parts[i + 1])
    return contexts, includes, out


def ctx_path(entry: str) -> str:
    while True:
        if entry.startswith("nogl:"):
            entry = entry[5:]
        elif entry.startswith("flags(") and "):" in entry:
            entry = entry.split("):", 1)[1]
        else:
            return entry


def explicit(source: Path, mapping: str, flags, contexts, includes) -> str:
    cmd = ["python3", "tools/fn_check_ltcg.py", os.path.relpath(source, ROOT) if source.is_absolute() else str(source), mapping]
    if flags:
        cmd += ["--flags", *flags]
    for n in includes:
        cmd += ["--include", n]
    for c in contexts:
        cmd += ["--context", c]
    return " ".join(shlex.quote(c) for c in cmd)


def find(args) -> int:
    import fn_check_ltcg as L
    import ltcg_autocontext as auto
    from fn_asm import find_function
    from xcoff import load_symbols

    world = fe.load_world()
    symbols = load_symbols()
    by_addr = {e[2]: e[0] for e in symbols if e[1] == ".text"}
    by_name = {e[0]: e[2] for e in symbols if e[1] == ".text"}
    cand, _, tgt = args.mapping.partition("=")
    target = int(tgt, 16) if tgt.lower().startswith("0x") else by_name[tgt]
    tname = by_addr[target]
    source = args.source if args.source.is_absolute() else ROOT / args.source
    text = source.read_text(errors="replace")
    source_map = auto.load_source_map(ROOT, address_of=by_name.get)
    ev = gather(world, target, ROOT, source_map, args.stand_in, not args.no_drafts)
    print_evidence(world, ev)
    if "error" in ev:
        return 1
    env = dict(os.environ)
    contexts, includes, auto_out = auto_command(source, args.mapping, args.flags, env)
    primer = [c for c in contexts if ctx_path(c) == auto.PRIMER]
    contexts = [c for c in contexts if ctx_path(c) != auto.PRIMER]
    have = {ctx_path(c) for c in contexts} | {os.path.relpath(source, ROOT)}
    # names: how the candidate link may call each member
    names: dict[int, list[str]] = {}
    rows = {r["address"]: r for r in ev["members"]}
    for a, r in rows.items():
        names[a] = list(dict.fromkeys(names_in(text, a) + [by_addr.get(a, "")] + [b.symbol for b in r["bodies"]]))
    need = {a: r["need"] for a, r in rows.items()}
    # closure members with a matched body that auto-context (two levels) did not add
    for a, r in rows.items():
        if r["need"] and r["matched"]:
            b = r["bodies"][0]
            if b.source not in have and not any(n in text and re.search(rf"\b{re.escape(n)}\s*\([^;{{}}]*\)\s*\{{", text) for n in names[a]):
                contexts.append(b.source)
                have.add(b.source)
                print(f"  + {b.source}: body of {r['name']} (below a callee that keeps {reg_list(r['need'])})")
    scratch_ctx = ROOT / "work" / "residue" / "ctx"

    def find_target(name):
        _p, start, code, relocs = find_function(name)
        return start, code, relocs

    tried: list[tuple] = []
    best = None

    def link(label: str, ctx: list[str], inc: list[str]):
        nonlocal best
        key = (tuple(ctx), tuple(inc))
        if any(t[0] == key for t in tried) or len(tried) >= args.tries:
            return None
        try:
            checked, _ci, _ti, workdir = L.verify(source, ctx, args.flags, [(cand, tname)], find_target, symbols,
                                                  keep=True, verbose=False, extra_includes=inc)
        except L.BuildError as error:
            print(f"  [{len(tried) + 1}] {label}: {error}")
            if error.workdir:
                shutil.rmtree(error.workdir, ignore_errors=True)
            tried.append((key, None, label))
            return None
        try:
            view = LinkView(workdir, L)
            d = diagnose(view, world, cand, target, names, need, list(rows), checked[0].result)
        finally:
            if not args.keep:
                shutil.rmtree(workdir, ignore_errors=True)
        tried.append((key, d, label))
        size = "" if not d.problems else "; " + d.problems[0][:70]
        print(f"  [{len(tried)}] {label}: " + ("MATCH" if d.ok else f"{d.score} off{size}"))
        for line in format_diagnosis(d):
            print(line)
        if args.keep:
            print(f"    scratch: {workdir}")
        rank = (0 if d.ok else 1, d.score if d.score is not None else 10 ** 6)
        if best is None or rank < best[0]:
            best = (rank, ctx, inc, d, label)
        return d

    def with_primer(ctx):
        return ctx + primer

    d = link("auto-context + closure", with_primer(contexts), includes)
    cur_ctx, cur_inc = list(contexts), list(includes)
    rounds = 0
    while d is not None and not d.ok and len(tried) < args.tries and rounds < 6:
        rounds += 1
        progress = False
        for a in d.bad():
            r, m = rows[a], d.members[a]
            wanted = next((n for n in names_in(text, a)), None) or by_addr.get(a)
            current = next((c for c in cur_ctx if any(b.source == ctx_path(c) for b in r["bodies"])), None)
            options = []
            if m["state"] in ("stub", "absent") and current is None:
                for b in r["bodies"]:
                    entry = b.source if b.symbol == wanted else wrap_stand_in(ROOT, b, wanted, scratch_ctx)
                    options.append((f"{r['name']} from {b.source} [{b.origin}]", cur_ctx + [entry], cur_inc))
                    options.append((f"{r['name']} from {b.source} [{b.origin}], /Ob1",
                                    cur_ctx + [auto.NO_INLINE + entry], cur_inc))
            elif current is not None:
                path = ctx_path(current)
                flipped = path if current.startswith(auto.NO_INLINE) else auto.NO_INLINE + current
                options.append((f"{'no ' if flipped == path else ''}/Ob1 on {path}",
                                [flipped if c == current else c for c in cur_ctx], cur_inc))
                sym = next((b.symbol for b in r["bodies"] if b.source == path), None)
                if sym and r["direct"] and (ROOT / path).parent == ROOT / "src" / "xbox360":
                    ni = wrap_noinline(ROOT, path, sym, scratch_ctx)
                    options.insert(0, (f"__declspec(noinline) {sym} (no /Ob1) via {ni}",
                                       [ni if c == current else c for c in cur_ctx], cur_inc))
                if sym in cur_inc:
                    options.append((f"no /INCLUDE of {sym}", cur_ctx, [n for n in cur_inc if n != sym]))
                elif sym:
                    options.append((f"/INCLUDE of {sym}", cur_ctx, cur_inc + [sym]))
                for b in r["bodies"]:
                    if b.source != path:
                        entry = b.source if b.symbol == wanted else wrap_stand_in(ROOT, b, wanted, scratch_ctx)
                        options.append((f"{r['name']} from {b.source} [{b.origin}] instead of {path}",
                                        [entry if c == current else c for c in cur_ctx],
                                        [n for n in cur_inc if n != sym]))
            for label, ctx, inc in options:
                d2 = link(label, with_primer(ctx), inc)
                if d2 is None:
                    continue
                if d2.ok or (d2.score is not None and (d.score is None or d2.score < d.score)) or \
                        (d2.score == d.score and len(d2.bad()) < len(d.bad())):
                    d, cur_ctx, cur_inc, progress = d2, ctx, inc, True
                    break
            if d.ok:
                break
        if not progress:
            break
    if best and not best[3].ok and primer:
        link("best link without the pool primer", [c for c in best[1] if c not in primer], best[2])
    if best is None:
        print("no link could be built")
        return 1
    _rank, ctx, inc, d, label = best
    command = explicit(source, args.mapping, args.flags, ctx, inc)
    print(f"best: [{label}] " + ("MATCH" if d.ok else f"{d.score} off"))
    left = [d.members[a]["name"] for a in d.blocking()]
    if left and not d.ok:
        print("  still wrong or missing under a kept register: " + ", ".join(left))
    elif not d.ok:
        same = all(d.kept_cand.get(k, frozenset()) == v for k, v in d.kept_target.items())
        print("  every needed body is in the link with a compatible kill set; "
              + ("the kept registers agree: the rest is the source's shape or register numbering."
                 if same else "the kept registers still differ: allocation order in the caller."))
    print("explicit command: " + command)
    if args.json:
        Path(args.json).write_text(json.dumps({
            "mapping": args.mapping, "source": str(args.source), "flags": args.flags, "match": d.ok,
            "score": d.score, "contexts": ctx, "includes": inc, "label": label, "command": command,
            "evidence": evidence_json(ev), "links": len(tried),
            "left": left}, indent=1))
    return 0 if d.ok else 1


def kills(args) -> int:
    """Link SRC (with its contexts) under /GL and compare the registers each named function
    writes with the original function's: is this source usable as a callee body?"""
    import fn_check_ltcg as L
    from fn_asm import find_function
    from xcoff import load_symbols

    world = fe.load_world()
    symbols = load_symbols()
    by_addr = {e[2]: e[0] for e in symbols if e[1] == ".text"}
    pairs, targets = [], {}
    for mapping in args.mappings:
        cand, _, tgt = mapping.partition("=")
        targets[cand] = int(tgt, 16)
        pairs.append((cand, by_addr[int(tgt, 16)]))

    def find_target(name):
        _p, start, code, relocs = find_function(name)
        return start, code, relocs

    source = args.source if args.source.is_absolute() else ROOT / args.source
    checked, _ci, _ti, workdir = L.verify(source, args.context, args.flags, pairs, find_target, symbols,
                                          keep=True, verbose=False)
    status = 0
    try:
        view = LinkView(workdir, L)
        for item in checked:
            address = targets[item.candidate]
            orig = world.analysis.defs_of(address) & VOLATILE
            at = view.address(item.candidate)
            if at is None or view.is_stub(at):
                print(f"{item.candidate}: not in the linked image")
                status = 1
                continue
            extra, missing = kill_diff(orig, view.analysis.defs_of(at) & VOLATILE)
            score = "MATCH" if item.result and item.result.ok else f"{len(item.result.diff_words)} off"
            if extra or missing:
                status = 1
                print(f"{item.candidate} ({score}): writes +[{reg_list(extra)}] -[{reg_list(missing)}] "
                      f"against the original ({reg_list(orig)})")
            else:
                print(f"{item.candidate} ({score}): kill set equal to the original ({reg_list(orig)})")
    finally:
        if not args.keep:
            shutil.rmtree(workdir, ignore_errors=True)
    return status


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = parser.add_subparsers(dest="cmd", required=True)
    k = sub.add_parser("kills", help="kill set of a source's functions under /GL against the original's")
    k.add_argument("source", type=Path)
    k.add_argument("mappings", nargs="+", help="candidate_name=0xADDR")
    k.add_argument("--flags", nargs="*", default=[])
    k.add_argument("--context", action="append", default=[])
    k.add_argument("--keep", action="store_true")
    e = sub.add_parser("evidence", help="what the original code proves about its link (static)")
    e.add_argument("addresses", nargs="+")
    e.add_argument("--json", action="store_true")
    e.add_argument("--no-drafts", action="store_true")
    f = sub.add_parser("find", help="build the link the evidence asks for and diagnose it")
    f.add_argument("source", type=Path)
    f.add_argument("mapping", help="candidate_name=0xADDR")
    f.add_argument("--flags", nargs="*", default=[])
    f.add_argument("--tries", type=int, default=12, help="links to build at most (default 12)")
    f.add_argument("--stand-in", action="append", default=[], help="another source to offer as a callee body")
    f.add_argument("--no-drafts", action="store_true", help="do not offer near-miss drafts as stand-ins")
    f.add_argument("--keep", action="store_true", help="keep the scratch links")
    f.add_argument("--json", help="write the result here")
    args = parser.parse_args(argv)
    if args.cmd == "find":
        return find(args)
    if args.cmd == "kills":
        return kills(args)
    import ltcg_autocontext as auto
    world = fe.load_world()
    by_name = dict(world.by_name)
    source_map = auto.load_source_map(ROOT, address_of=by_name.get)
    out = []
    for a in args.addresses:
        address = int(a, 16) if a.lower().startswith("0x") else by_name[a]
        ev = gather(world, address, ROOT, source_map, drafts=not args.no_drafts)
        if args.json:
            out.append(evidence_json(ev))
        else:
            print_evidence(world, ev)
    if args.json:
        print(json.dumps(out, indent=1))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
