#!/usr/bin/env python3
"""Choose the --context list of tools/fn_check_ltcg.py from the call graph.

Under LTCG a function's code depends on the bodies of its callees in the same
link. `fn_check_ltcg.py --auto-context` uses this module to:

1. read the direct callees of each target function from the original code
   (branch relocations of the split object that leave the function; with
   depth 2 also the callees of the callees whose source is known);
2. read the functions the source under test names but the original does not
   call: the link inlined those, so their bodies must be in the link too;
3. map each callee address to the source that byte-matches it:
   config/54540859/match.json first, then work/specs/*/*.json (matches handed
   in but not built yet; specs with "route": "equiv" are ignored);
4. pick the fewest sources that cover the callees (one file that defines two
   callees wins over two files that each define one, which also avoids two
   files defining the same function in one link), never the source under
   test, and append the pool primer last.

Stand-ins. A context of a registered LTCG unit that matches nothing itself
(cw1_ctx_format_text.c gives ts4_format_text its varargs shape) is offered
for the callee it defines when that callee has no matched source. It is an
inexact body: the callee stays on the missing list.

Prefixes. Contexts are compiled plain. `flags(/Ob1):path` keeps the
functions *defined in that file* from being inlined anywhere, also into each
other, so it changes the callee's own body when that inlines file-local
helpers; fn_check_ltcg.py adds it only to a source whose callee the link
inlined into the function under test (the original calls it). A chosen
source that is itself an LTCG unit brings the contexts recorded for it
(config/54540859/ltcg_units.json, or its spec) with their prefixes, because
its own body is only right with them (0x886600E0 needs cl1_clrrwi_reload.c
inlined, and 0x8866BD00 only matches when 0x886600E0's body is right). A
chosen source also gets the flags it matched with when the check does not
pass them already (`flags(/O1):path`).

Callees with no matched source are returned as "missing": match those first.
Standard library only; nothing here reads game data.
"""

from __future__ import annotations

import json
import re
from dataclasses import dataclass, field
from pathlib import Path

PRIMER = "src/xbox360/pp1_pool_primer.c"
NO_INLINE = "flags(/Ob1):"
BRANCH_KINDS = (0x6, 0x7)  # REL24, REL14
HELPER = re.compile(r"^__(save|rest)(gpr|fpr|vmx)(lr)?_\d+$")


@dataclass(frozen=True)
class Candidate:
    source: str   # repository-relative path of a source that defines the callee
    symbol: str   # the callee's name in that source
    origin: str   # "match" (config match.json), "spec" (work/specs, not built yet) or "stand-in"


@dataclass
class Selection:
    contexts: list[str] = field(default_factory=list)          # --context values, primer last
    covered: dict[int, Candidate] = field(default_factory=dict)  # callee -> chosen source
    in_source: list[int] = field(default_factory=list)         # callees the source under test defines
    missing: list[int] = field(default_factory=list)           # called, no matched source
    missing_inlined: list[int] = field(default_factory=list)   # named in the source only, no matched source
    inlined: set[int] = field(default_factory=set)             # covered callees the original does not call
    notes: list[str] = field(default_factory=list)

    def includes(self) -> list[str]:
        """Called callees to force with /INCLUDE: each was matched as a function of its own, so
        it keeps the standard calling convention (a small link would otherwise let LTCG drop
        its unused arguments or its call)."""
        return [c.symbol for a, c in self.covered.items() if a not in self.inlined]


def branch_target(word: int, address: int) -> int | None:
    op = word >> 26
    if op not in (16, 18):
        return None
    bits = 26 if op == 18 else 16
    disp = word & ((1 << bits) - 4)
    if disp >> (bits - 1):
        disp -= 1 << bits
    return (disp if word & 2 else address + disp) & 0xFFFFFFFF


def callee_addresses(code: bytes, start: int, relocs) -> list[int]:
    """Targets of the branches that leave a function (or re-enter it at its start), in call order.

    `relocs` are the function's relocations (objects with .offset and .kind); `code` is the
    linked original, so each relocated branch word already holds its displacement.
    """
    out: list[int] = []
    for reloc in sorted(relocs, key=lambda r: r.offset):
        if reloc.kind not in BRANCH_KINDS or reloc.offset + 4 > len(code):
            continue
        address = start + (reloc.offset & ~3)
        word = int.from_bytes(code[reloc.offset & ~3 : (reloc.offset & ~3) + 4], "big")
        target = branch_target(word, address)
        if target is None or start < target < start + len(code) or target in out:
            continue
        out.append(target)
    return out


def call_graph(targets: list[int], callees_of, expand, depth: int = 1) -> list[int]:
    """Callees of `targets` down to `depth` levels, nearest first, without the targets.

    callees_of(address) -> list of addresses; expand(address) says whether a callee's own
    callees are worth following (its body will be in the link).
    """
    seen, order, level = set(targets), [], list(targets)
    for _ in range(depth):
        nxt = []
        for address in level:
            for callee in callees_of(address):
                if callee not in seen:
                    seen.add(callee)
                    order.append(callee)
                    if expand(callee):
                        nxt.append(callee)
        level = nxt
    return order


def _rel(path, root: Path) -> str:
    path = Path(path)
    if not path.is_absolute():
        path = root / path
    try:
        return path.resolve().relative_to(root.resolve()).as_posix()
    except ValueError:
        return path.resolve().as_posix()


def load_source_map(root: Path, specs: bool = True, address_of=None) -> dict[int, list[Candidate]]:
    """address -> sources that define the function there: match.json, then specs, then stand-ins.

    address_of(name) -> address resolves the functions a stand-in context defines; without
    it no stand-ins are offered.
    """
    out: dict[int, list[Candidate]] = {}

    def add(address: int, source: str, symbol: str, origin: str) -> None:
        entries = out.setdefault(address, [])
        if (root / source).is_file() and all(c.source != source for c in entries):
            entries.append(Candidate(source, symbol, origin))

    config = root / "config" / "54540859"
    if (config / "match.json").is_file():
        for row in json.loads((config / "match.json").read_text())["matches"]:
            add(int(row["text_range"].split("-")[0], 16), row["source"], row["symbol"], "match")
    for path in sorted((root / "work" / "specs").glob("*/*.json")) if specs else []:
        try:
            spec = json.loads(path.read_text())
        except ValueError:
            continue
        if not isinstance(spec, dict) or spec.get("route") == "equiv" or "source" not in spec:
            continue
        for symbol, address in (spec.get("functions") or {}).items():
            try:
                add(int(str(address), 16), spec["source"], symbol, "spec")
            except ValueError:
                continue
    if address_of and (config / "ltcg_units.json").is_file():
        matched = {c.source for cands in out.values() for c in cands}
        contexts = {split_context(entry)[1] for unit in json.loads((config / "ltcg_units.json").read_text())
                    for entry in unit.get("context") or []}
        for source in sorted(contexts - matched):
            if (root / source).is_file():
                text = COMMENT.sub(" ", (root / source).read_text(errors="replace"))
                for name in re.findall(r"\b([A-Za-z_]\w*)\s*\([^;{}()]*\)\s*\{", text):
                    address = resolve(name, address_of)
                    if address is not None:
                        add(address, source, name, "stand-in")
    return {address: cands for address, cands in out.items() if cands}


PREFIX = re.compile(r"^(?:nogl:|flags\([^)]*\):)+")
COMMENT = re.compile(r"/\*.*?\*/|//[^\n]*", re.S)
ADDRESS_SUFFIX = re.compile(r"_([0-9A-Fa-f]{8})$")


def split_context(entry: str) -> tuple[str, str]:
    """`flags(/Ob1):path` -> ("flags(/Ob1):", "path")."""
    prefix = PREFIX.match(entry)
    return (prefix.group(0), entry[prefix.end():]) if prefix else ("", entry)


def resolve(name: str, address_of) -> int | None:
    """Address of a function name; a name ending in _XXXXXXXX that address_of does not know
    is tried by its suffix (a new name for fn_XXXXXXXX)."""
    address = address_of(name)
    suffix = ADDRESS_SUFFIX.search(name)
    if address is None and suffix:
        address = address_of("fn_" + suffix.group(1).upper())
    return address


def referenced_addresses(text: str, address_of, skip=()) -> list[int]:
    """Addresses of the functions a source names outside comments and does not define.

    address_of(identifier) -> address or None; see resolve().
    """
    text = COMMENT.sub(" ", text)
    out: list[int] = []
    for name in dict.fromkeys(re.findall(r"[A-Za-z_]\w*", text)):
        address = resolve(name, address_of)
        if address is None or address in skip or address in out:
            continue
        if re.search(r"\b%s\s*\([^;{}]*\)\s*\{" % re.escape(name), text):
            continue  # defined here
        out.append(address)
    return out


def load_recorded(root: Path, specs: bool = True) -> dict[str, dict]:
    """source -> {"context": [...], "flags": [...]} of the LTCG units and specs that match it."""
    out: dict[str, dict] = {}
    units = root / "config" / "54540859" / "ltcg_units.json"
    rows = json.loads(units.read_text()) if units.is_file() else []
    for path in sorted((root / "work" / "specs").glob("*/*.json")) if specs else []:
        try:
            spec = json.loads(path.read_text())
        except ValueError:
            continue
        if isinstance(spec, dict) and spec.get("route") == "ltcg":
            rows.append(spec)
    for row in rows:
        if "source" in row:
            out.setdefault(row["source"], {"context": list(row.get("context") or []),
                                           "flags": list(row.get("flags") or [])})
    match = root / "config" / "54540859" / "match.json"
    if match.is_file():
        for source, flags in json.loads(match.read_text()).get("compiler_flag_exceptions", {}).items():
            out.setdefault(source, {"context": [], "flags": list(flags)})
    return out


def choose(callees: list[int], source_map: dict[int, list[Candidate]], primary, root: Path,
           targets: list[int] = (), prefix: str = "", primer: str | None = PRIMER,
           manual: list[str] = (), inlined: list[int] = (), recorded: dict[str, dict] | None = None,
           flags: list[str] = ()) -> Selection:
    """Pick context sources for `callees` (ordered addresses the original calls) and `inlined`
    (addresses the source names but the original does not call).

    primary: the source under test (never a context). targets: the addresses under test; a
    source that defines one of them is never a context either (it would define the function
    twice). prefix: put before every chosen source. manual: --context values the user gave;
    they stay first and win for their file. recorded: load_recorded(). flags: the cl flags
    every source already gets.
    """
    recorded = recorded or {}
    primary = _rel(primary, root)
    banned = {primary} | {c.source for t in targets for c in source_map.get(t, [])}
    manual_paths = {_rel(split_context(m)[1], root) for m in manual}
    sel = Selection()
    open_: dict[int, list[Candidate]] = {}
    for address in dict.fromkeys([*callees, *inlined]):
        called = address in callees
        cands = source_map.get(address, [])
        if any(c.source == primary for c in cands):
            sel.in_source.append(address)
            continue
        given = next((c for c in cands if c.source in manual_paths), None)
        cands = [c for c in cands if c.source not in banned]
        cands = [c for c in cands if c.origin != "stand-in"] or cands  # a stand-in only when alone
        if not given and all(c.origin == "stand-in" for c in cands):  # also when there is none
            (sel.missing if called else sel.missing_inlined).append(address)
        if not called and (given or cands):
            sel.inlined.add(address)
        if given:
            sel.covered[address] = given
        elif cands:
            open_[address] = cands
    chosen: list[str] = []
    rank_of = {"match": 0, "spec": 1, "stand-in": 2}
    while open_:
        # Greedy cover: the source defining the most open callees; ties go to match.json
        # sources, then specs, then stand-ins, then to the source of the earliest callee.
        score: dict[str, list] = {}
        for rank, (address, cands) in enumerate(open_.items()):
            for c in cands:
                s = score.setdefault(c.source, [0, 2, rank])
                s[0] -= 1
                s[1] = min(s[1], rank_of[c.origin])
        best = min(score, key=lambda src: (score[src], src))
        chosen.append(best)
        for address in [a for a, cands in open_.items() if any(c.source == best for c in cands)]:
            sel.covered[address] = next(c for c in open_.pop(address) if c.source == best)

    wanted: dict[str, str] = {}   # path -> prefix, in first-use order
    fixed: set[str] = set()       # paths whose prefix a recorded context set
    for src in chosen:
        wanted.setdefault(src, prefix)
        for entry in recorded.get(src, {}).get("context", []):
            its_prefix, path = split_context(entry)
            path = _rel(path, root)
            if path in banned or path in manual_paths or path == primer:
                continue
            if path in fixed and wanted[path] != its_prefix:
                sel.notes.append(f"{path} is recorded as {wanted[path]!r} and {its_prefix!r}; using "
                                 f"{wanted[path]!r} (pass it as an explicit --context to override)")
            elif path not in fixed and (its_prefix or path not in wanted):
                wanted[path] = its_prefix
            fixed.add(path)
    for src in chosen:  # the flags the source matched with, e.g. /O1; prefixes accumulate
        extra = [f for f in recorded.get(src, {}).get("flags", [])
                 if f not in flags and f not in parse_flags(wanted[src])]
        if extra:
            wanted[src] += "flags(%s):" % " ".join(extra)
    sel.contexts = [m for m in manual if not primer or _rel(split_context(m)[1], root) != primer]
    sel.contexts += [its_prefix + path for path, its_prefix in wanted.items()]
    if primer and primary != primer:
        sel.contexts.append(primer)
    return sel


def parse_flags(prefix: str) -> list[str]:
    """The cl flags of a context prefix: `flags(/Ob1):flags(/O1):` -> ["/Ob1", "/O1"]."""
    return [f for inner in re.findall(r"flags\(([^)]*)\):", prefix) for f in inner.split()]


def with_prefix(contexts: list[str], source: str, prefix: str) -> list[str]:
    """`contexts` with `prefix` put before the entry for `source`, unless it has those flags."""
    out = []
    for entry in contexts:
        old, path = split_context(entry)
        new = path == source and not set(parse_flags(prefix)) <= set(parse_flags(old))
        out.append(prefix + entry if new else entry)
    return out


def report(sel: Selection, name_of, depth: int = 1) -> list[str]:
    """Human-readable lines: chosen contexts, where each callee comes from, what is missing."""
    lines = [f"auto-context (depth {depth}): {len(sel.contexts)} context(s)"]
    lines += [f"  --context {c}" for c in sel.contexts]
    for address, c in sel.covered.items():
        note = {"match": "", "spec": " (spec only, not in match.json)",
                "stand-in": " (stand-in, an inexact body: still missing)"}[c.origin]
        how = "inlined (named in the source, no call in the original)" if address in sel.inlined else "callee"
        lines.append(f"  {how} 0x{address:08X} {c.symbol} <- {c.source}{note}")
    for address in sel.in_source:
        lines.append(f"  callee 0x{address:08X} {name_of(address)} <- source under test")
    lines += [f"  note: {n}" for n in sel.notes]
    lines.append(f"missing callee bodies ({len(sel.missing)}; match these first):"
                 + ("" if sel.missing else " none"))
    lines += [f"  0x{address:08X} {name_of(address)}" for address in sel.missing]
    if sel.missing_inlined:
        lines.append(f"named in the source, not called in the original, no matched source "
                     f"({len(sel.missing_inlined)}; inlined or unused):")
        lines += [f"  0x{address:08X} {name_of(address)}" for address in sel.missing_inlined]
    return lines
