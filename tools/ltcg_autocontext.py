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

Prototypes. When the source under test declares a callee as returning a value and one
candidate source defines it as `void` (or the reverse), that candidate is left out as long
as another one agrees: the caller uses r3 after the call, and only a body that sets it gives
the link the same knowledge (0x8816CBB0 uses `*hash(&h, i)`; rm2_index_hash_tables.c matches
the hash function as `void`, cx39_ctx_hash.c returns its out pointer). A stand-in that
agrees therefore beats a matched source that does not.

Fallbacks. fallback_variants() lists, in order, the smaller links fn_check_ltcg.py tries when
the full context does not match: without the /INCLUDEs, with `flags(/Ob1):` on every callee
source (each callee the original reaches with `bl` stays out of line), without one callee
source at a time (a callee body can also disturb the caller: 0x8816CBB0 only matches without
the body of its 0x88187738 callee), one callee source alone, and no callee source at all.
The same link without the pool primer goes first, outside the count: a literal the original
keeps in another pool than g_ts4_script_constants must not land in the primed pool.

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
    prototype_stand_ins: set[int] = field(default_factory=set)  # matched callees given a stand-in body
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


KEYWORDS = {"if", "for", "while", "switch", "return", "sizeof", "else", "do", "catch"}


def load_helpers(root: Path, address_of) -> dict[str, str]:
    """name -> context entry (with its recorded prefix) for the functions that only a
    context-only file of a registered LTCG unit defines and that are at no address of the
    original (os1_ctx_checksum.c: folding stand-ins for crc32/adler32 that the link inlines).
    A source that names such a function needs that file in the link."""
    config = root / "config" / "54540859"
    if not (config / "ltcg_units.json").is_file():
        return {}
    units = json.loads((config / "ltcg_units.json").read_text())
    matched = {unit["source"] for unit in units}
    if (config / "match.json").is_file():
        matched |= {row["source"] for row in json.loads((config / "match.json").read_text())["matches"]}
    out: dict[str, str] = {}
    for unit in units:
        for entry in unit.get("context") or []:
            source = split_context(entry)[1]
            if source in matched or source == PRIMER or not (root / source).is_file():
                continue
            text = COMMENT.sub(" ", (root / source).read_text(errors="replace"))
            for name in re.findall(r"\b([A-Za-z_]\w*)\s*\([^;{}()]*\)\s*\{", text):
                if name not in KEYWORDS and resolve(name, address_of) is None:
                    out.setdefault(name, entry)
    return out


def helper_contexts(text: str, helpers: dict[str, str]) -> list[str]:
    """The context entries of the helpers a source names (outside comments) and does not define."""
    text = COMMENT.sub(" ", text)
    out: list[str] = []
    for name, entry in helpers.items():
        if re.search(r"\b%s\b" % re.escape(name), text) and entry not in out \
                and not re.search(r"\b%s\s*\([^;{}]*\)\s*\{" % re.escape(name), text):
            out.append(entry)
    return out


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


QUALIFIERS = {"extern", "static", "inline", "__inline", "__forceinline", "const", "volatile", "__cdecl",
              "struct", "class", "enum", "C"}
DECLSPEC = re.compile(r"__declspec\s*\([^()]*(?:\([^()]*\))?[^()]*\)")


def return_kind(text: str, name: str, definition: bool = False) -> str | None:
    """"void" or "value": what a declaration (or, with `definition`, the definition) of `name`
    in `text` returns; None when there is none or it cannot be read."""
    text = COMMENT.sub(" ", text)
    tail = r"\s*\([^;{}]*\)\s*\{" if definition else r"\s*\("
    for match in re.finditer(r"\b%s%s" % (re.escape(name), tail), text):
        head = text[max(0, match.start() - 240) : match.start()]
        head = re.split(r"[;{}]|\)\s*(?=$)|#[^\n]*\n", head)[-1]
        head = DECLSPEC.sub(" ", head).replace('"C"', " ")
        if not head.strip() or re.search(r"[=,(!<>+\-/?:.\[\]|]|\breturn\b|\bif\b|\belse\b", head):
            continue  # a call inside an expression or statement, not a declaration
        words = [w for w in re.findall(r"[A-Za-z_]\w*", head) if w not in QUALIFIERS]
        if not words:
            continue
        return "void" if words == ["void"] and "*" not in head and "&" not in head else "value"
    return None


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
           flags: list[str] = (), wants: dict[int, str] | None = None, returns_of=None) -> Selection:
    """Pick context sources for `callees` (ordered addresses the original calls) and `inlined`
    (addresses the source names but the original does not call).

    primary: the source under test (never a context). targets: the addresses under test; a
    source that defines one of them is never a context either (it would define the function
    twice). prefix: put before every chosen source. manual: --context values the user gave;
    they stay first and win for their file. recorded: load_recorded(). flags: the cl flags
    every source already gets. wants: callee address -> "void"/"value", what the source
    under test declares the callee to return; returns_of(candidate) -> "void"/"value"/None,
    what the candidate's definition returns. A candidate that disagrees is left out when
    another candidate agrees.
    """
    wants = wants or {}
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
        want = wants.get(address)
        if want and returns_of and not given and len(cands) > 1:
            kinds = {c: returns_of(c) for c in cands}
            agree = [c for c in cands if kinds[c] == want]
            wrong = [c for c in cands if kinds[c] not in (None, want)]
            if agree and wrong:
                cands = [c for c in cands if c not in wrong]
            if agree and any(c.origin != "stand-in" for c in wrong):
                sel.notes.append(
                    f"0x{address:08X}: the source under test uses it as returning "
                    f"{'a value' if want == 'value' else 'void'}; left out "
                    + ", ".join(f"{c.source} ({kinds[c]})" for c in wrong)
                    + f" for {agree[0].source}")
                if all(c.origin == "stand-in" for c in cands):
                    sel.prototype_stand_ins.add(address)
        cands = [c for c in cands if c.origin != "stand-in"] or cands  # a stand-in only when alone
        if not given and all(c.origin == "stand-in" for c in cands) \
                and address not in sel.prototype_stand_ins:  # also when there is none
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


def fallback_variants(contexts: list[str], manual: list[str], includes: list[str],
                      given_includes: list[str], owner: dict[str, str], primer: str | None = PRIMER,
                      limit: int = 12) -> list[tuple[str, list[str], list[str]]]:
    """Ranked smaller links to try when the full context does not match: (label, contexts,
    includes). contexts: the list that failed; manual: the explicit --context values (kept in
    every variant, like the primer); includes: the /INCLUDE names that failed; given_includes:
    the explicit ones; owner: forced callee -> its source. At most `limit` variants, none equal
    to the failed one or to an earlier variant; when the primer is in `contexts`, "without the
    pool primer" (everything else as it failed) comes first and is not counted."""
    def path_of(entry):
        return split_context(entry)[1]

    auto = [c for c in contexts if c not in manual and path_of(c) != primer]

    def keep(kept):
        ctx = [c for c in contexts if c in manual or path_of(c) == primer or c in kept]
        sources = {path_of(c) for c in kept}
        inc = [n for n in includes if n in given_includes or owner.get(n) in sources]
        return ctx, inc

    def no_inline(ctx):
        out = ctx
        for entry in ctx:
            if entry in auto:
                out = with_prefix(out, path_of(entry), NO_INLINE)
        return out

    out, seen = [], {(tuple(contexts), tuple(includes))}

    def add(label, ctx, inc):
        key = (tuple(ctx), tuple(inc))
        if key not in seen and len(out) < limit:
            seen.add(key)
            out.append((label, list(ctx), list(inc)))

    add("without the /INCLUDE of the callees", contexts, given_includes)
    add(f"with {NO_INLINE} on every callee source", no_inline(contexts), includes)
    if len(auto) > 1:
        for entry in auto:
            ctx, inc = keep([c for c in auto if c != entry])
            add(f"without {path_of(entry)}", ctx, inc)
            add(f"without {path_of(entry)}, {NO_INLINE} on the others", no_inline(ctx), inc)
    if len(auto) > 2:
        for entry in auto:
            ctx, inc = keep([entry])
            add(f"with {path_of(entry)} alone", ctx, inc)
            add(f"with {NO_INLINE}{path_of(entry)} alone", no_inline(ctx), inc)
    add("without the callee sources", keep([])[0], given_includes)
    # The primer puts the literals of the function under test into the g_ts4_script_constants
    # layout. A function whose literals the original keeps in another pool is then addressed
    # through the big pool's base (addi + lfs, one instruction more: 0x88779248, 0x886AFDF8).
    # One link, tried first and not counted in `limit`.
    bare = [c for c in contexts if path_of(c) != primer or c in manual]   # an explicit primer stays
    if primer and bare != contexts and (tuple(bare), tuple(includes)) not in seen:
        out.insert(0, ("without the pool primer", bare, list(includes)))
    return out


def report(sel: Selection, name_of, depth: int = 1) -> list[str]:
    """Human-readable lines: chosen contexts, where each callee comes from, what is missing."""
    lines = [f"auto-context (depth {depth}): {len(sel.contexts)} context(s)"]
    lines += [f"  --context {c}" for c in sel.contexts]
    for address, c in sel.covered.items():
        note = {"match": "", "spec": " (spec only, not in match.json)",
                "stand-in": " (stand-in, an inexact body: still missing)"}[c.origin]
        if address in sel.prototype_stand_ins:
            note = " (stand-in with the prototype the source under test uses; the callee itself is matched)"
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
