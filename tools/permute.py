#!/usr/bin/env python3
"""Permutation search: brute-force source variants until fn_check matches.

Usage:
  python3 tools/permute.py src/x.c name=0xADDR [name2=0xADDR2 ...] [options]

  TS4_MATCHING_DIR=work/loader python3 tools/permute.py src/loader/x.c f=0x83170188

The positional arguments and --flags are exactly fn_check.py's (and
TS4_MATCHING_DIR is honoured the same way). The input file is never modified:
the winning source goes to --out (default work/permute-out/<stem>.perm<ext>),
the best near-miss to <stem>.best<ext> when nothing matches.

Options
  --flags F ...        extra cl flags for every candidate (as fn_check)
  --flags-sweep [S..]  also vary the compiler flags. Each S is one quoted flag
                       set, e.g. --flags-sweep "/O1" "/O1 /Ob1"; with no
                       values a default list is used. Added to --flags.
  -j N                 parallel compiles (default 4)
  -n / --max-candidates N   candidate budget (default 400)
  --time SECONDS       wall-clock budget (default 900)
  --seed N             RNG seed for the randomized search
  --out PATH           where to write the winner
  --info               parse the markup, print the search space, and exit
  --render             print the unchanged (baseline) rendering and exit

Markup (all inside C comments, so the file compiles unchanged)

  /* PERM_BEGIN */ stmt; stmt; ... /* PERM_END */
      The top-level statements of the block may be reordered. A pair of
      statements keeps its relative order when they conflict: one writes an
      identifier the other reads or writes, memory accesses may alias
      (lvalues compared textually: p->a and p->b are independent, p and p->a
      or any function call conflict with other memory accesses), or either
      contains return/goto/break/continue/switch/case/a label (a barrier no
      statement crosses). An if/else chain, a for/while body and a { } block
      count as one statement.
      Modes: /* PERM_BEGIN(strict) */ any store/call conflicts with every
      other memory access; /* PERM_BEGIN(free) */ ignore dependencies (only
      barriers still pin).

  /* PERM_DECLS */ int a; char *b = c; ... /* PERM_DECLS_END */  (or PERM_END)
      Declaration order (affects stack slots / register assignment). A
      declaration whose initializer reads another declared name stays after it.

  /* PERM_ALT(a|b|c) */ original text /* PERM_ALT_END */
      Replace the text between the markers by one of the alternatives (the
      original is always alternative 0; the span must not include the statement's
      terminating `;`). `|` splits at paren/bracket depth 0 (braces do not count, so alternatives may
      contain unbalanced `{`/`}`); write
      `||` or `\\|` for a literal bar, and an empty alternative is allowed,
      e.g. /* PERM_ALT(__forceinline|) */ static /* PERM_ALT_END */. Typical:
      `i++|++i`, `a == b|b == a`, `x + y|y + x`, a whole `for` vs `while`
      loop, early-return vs nested-if. Spans may be multi-line.

  /* PERM_TYPE(int|unsigned|short) */ int x;
      Replaces the type keyword run that follows the comment ("int",
      "unsigned char", "void", or a single typedef name; not any `*`) by each
      alternative.

  /* PERM_VOLATILE */
      Inserts `volatile ` at this position when on (off in the original).
      Put it where a qualifier is valid: `/* PERM_VOLATILE */ int *p;`,
      `int * /* PERM_VOLATILE */ p;`, or `*(/* PERM_VOLATILE */ int *)q`.

Search. The space is the product of every marker's alternatives, every block's
legal orders (capped, 5000 per block) and the flag sets. If it fits the
candidate budget it is enumerated exhaustively (original first); otherwise the
original's one-step neighbours are tried and then a randomized hill climb that
minimises fn_check's differing-instruction count (plateau moves allowed,
random restarts on stagnation). The first exact match stops the search.
"""

from __future__ import annotations

import argparse
import contextlib
import difflib
import io
import itertools
import os
import random
import re
import shutil
import subprocess
import sys
import tempfile
import time
from concurrent.futures import ThreadPoolExecutor
from dataclasses import dataclass, field
from pathlib import Path

TOOLS_DIR = Path(__file__).resolve().parent
ROOT = TOOLS_DIR.parent

DEFAULT_FLAG_SWEEP = ["/O1", "/Os", "/Ob0", "/Ob1", "/Oi-", "/GS-"]
ORDER_CAP = 5000


class MarkupError(ValueError):
    """Bad PERM_* markup in the source."""


# --------------------------------------------------------------------------
# lexical helpers


def _skip_literal(text: str, i: int) -> int | None:
    """If a comment / string / char literal starts at i, return the end index."""
    c = text[i]
    if c == "/" and text.startswith("/*", i):
        j = text.find("*/", i + 2)
        return len(text) if j < 0 else j + 2
    if c == "/" and text.startswith("//", i):
        j = text.find("\n", i)
        return len(text) if j < 0 else j
    if c in "\"'":
        j = i + 1
        while j < len(text) and text[j] != c:
            j += 2 if text[j] == "\\" else 1
        return min(j + 1, len(text))
    return None


def strip_noise(text: str) -> str:
    """Blank out comments, and reduce literals, keeping offsets irrelevant."""
    out = []
    i = 0
    while i < len(text):
        end = _skip_literal(text, i)
        if end is None:
            out.append(text[i])
            i += 1
        else:
            out.append(" " if text[i] == "/" else ("0" if text[i] == "'" else '""'))
            i = end
    return "".join(out)


def _balanced(text: str, i: int) -> int:
    """text[i] == '(' ; return the index of the matching ')'."""
    depth = 0
    j = i
    while j < len(text):
        end = _skip_literal(text, j)
        if end is not None:
            j = end
            continue
        if text[j] == "(":
            depth += 1
        elif text[j] == ")":
            depth -= 1
            if depth == 0:
                return j
        j += 1
    raise MarkupError("unbalanced parenthesis in PERM marker")


def split_alts(arg: str) -> list[str]:
    """Split a PERM_ALT / PERM_TYPE argument on top-level single `|`."""
    parts, cur, depth, i = [], [], 0, 0
    while i < len(arg):
        c = arg[i]
        if c == "\\" and arg[i + 1 : i + 2] == "|":
            cur.append("|")
            i += 2
            continue
        if c == "|" and arg[i + 1 : i + 2] == "|":
            cur.append("||")
            i += 2
            continue
        if c in "([":
            depth += 1
        elif c in ")]":
            depth -= 1
        if c == "|" and depth == 0:
            parts.append("".join(cur).strip())
            cur = []
        else:
            cur.append(c)
        i += 1
    parts.append("".join(cur).strip())
    return parts


@dataclass
class Marker:
    name: str  # e.g. PERM_ALT
    args: str | None
    start: int
    end: int


def find_markers(text: str) -> list[Marker]:
    markers = []
    i = 0
    while i < len(text):
        if text.startswith("/*", i):
            j = text.find("*/", i + 2)
            if j < 0:
                raise MarkupError("unterminated comment")
            m = re.match(r"\s*(PERM_[A-Z_]+)", text[i + 2 : j])
            if m:
                rest_start = i + 2 + m.end()
                k = rest_start
                while k < j and text[k] in " \t\r\n":
                    k += 1
                args = None
                if k < j and text[k] == "(":
                    close = _balanced(text, k)
                    if close >= j:
                        raise MarkupError("PERM marker arguments run past the comment")
                    args = text[k + 1 : close]
                markers.append(Marker(m.group(1), args, i, j + 2))
            i = j + 2
            continue
        end = _skip_literal(text, i)
        i = i + 1 if end is None else end
    return markers


def line_of(text: str, offset: int) -> int:
    return text.count("\n", 0, offset) + 1


# --------------------------------------------------------------------------
# statement splitting and dependency analysis

BLOCK_STARTS = {"PERM_BEGIN": "stmts", "PERM_DECLS": "decls"}
BLOCK_ENDS = {"PERM_END", "PERM_DECLS_END"}
MODES = ("loose", "strict", "free")

C_KEYWORDS = {
    "if", "else", "for", "while", "do", "switch", "case", "default", "return",
    "goto", "break", "continue", "sizeof", "typedef", "struct", "union", "enum",
    "static", "extern", "register", "auto", "const", "volatile", "unsigned",
    "signed", "void", "char", "short", "int", "long", "float", "double",
    "__int8", "__int16", "__int32", "__int64", "inline", "__inline",
    "__forceinline", "__declspec", "__vector4", "restrict",
}
BARRIER_WORDS = {"return", "goto", "break", "continue", "switch", "case", "default"}
ASSIGN_OPS = {"=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>="}
TOKEN_RE = re.compile(
    r"[A-Za-z_]\w*|0[xX][0-9a-fA-F]+[uUlL]*|\d[\w.]*|->|\+\+|--|<<=|>>=|&&|\|\||"
    r"==|!=|<=|>=|[-+*/%&|^]=|<<|>>|\S"
)
IDENT_RE = re.compile(r"[A-Za-z_]\w*$")


def _is_ident(tok: str) -> bool:
    return bool(IDENT_RE.match(tok))


def _is_var(tok: str) -> bool:
    return _is_ident(tok) and tok not in C_KEYWORDS


def _is_operand_end(tok: str) -> bool:
    return _is_var(tok) or tok in (")", "]") or tok[0].isdigit()


def _word_at(text: str, i: int) -> str:
    """First identifier word at/after i, skipping whitespace and comments."""
    n = len(text)
    while i < n:
        if text[i].isspace():
            i += 1
            continue
        end = _skip_literal(text, i) if text[i] == "/" else None
        if end is not None:
            i = end
            continue
        break
    m = re.compile(r"[A-Za-z_]\w*").match(text, i)
    return m.group(0) if m else ""


def split_statements(body: str) -> tuple[list[tuple[str, str]], str]:
    """Split block text into [(leading_whitespace, statement_text)], tail."""
    n = len(body)
    chunks: list[tuple[str, str]] = []
    start = 0
    depth = 0
    i = 0

    def head_word(s: int) -> str:
        return _word_at(body, s)

    def emit(end: int) -> None:
        nonlocal start
        raw = body[start:end]
        text = raw.lstrip()
        chunks.append((raw[: len(raw) - len(text)], text))
        start = end

    while i < n:
        c = body[i]
        end = _skip_literal(body, i) if c in "/\"'" else None
        if end is not None:
            i = end
            continue
        at_line_start = body[:i].rstrip(" \t").endswith("\n") or not body[:i].strip()
        if c == "#" and depth == 0 and at_line_start and not body[start:i].strip():
            j = i
            while j < n and body[j] != "\n":
                j += 2 if body[j] == "\\" else 1
            i = min(j, n)
            emit(i)
            continue
        if c in "([{":
            depth += 1
        elif c in ")]}":
            depth -= 1
            if c == "}" and depth == 0:
                chunk_start = body[start:i].lstrip()
                head = head_word(start)
                if chunk_start.startswith("{") or head in ("if", "else", "for", "while", "switch", "do"):
                    nxt = head_word(i + 1)
                    if (nxt == "else" and head in ("if", "else")) or (nxt == "while" and head == "do"):
                        i += 1
                        continue
                    emit(i + 1)
        elif c == ";" and depth == 0:
            head = head_word(start)
            nxt = head_word(i + 1)
            if (nxt == "else" and head in ("if", "else")) or (nxt == "while" and head == "do"):
                i += 1
                continue
            emit(i + 1)
        i += 1
    return chunks, body[start:]


@dataclass
class StmtInfo:
    reads: set = field(default_factory=set)
    writes: set = field(default_factory=set)
    mreads: set = field(default_factory=set)
    mwrites: set = field(default_factory=set)
    barrier: bool = False


def _match_brackets(toks: list[str]) -> tuple[dict[int, int], dict[int, int]]:
    close, opened, stack = {}, {}, []
    for i, t in enumerate(toks):
        if t in ("(", "[", "{"):
            stack.append(i)
        elif t in (")", "]", "}") and stack:
            j = stack.pop()
            close[j] = i
            opened[i] = j
    return close, opened


def _operand_end(toks, j, close) -> int:
    """End (exclusive) of the unary/cast/postfix expression starting at toks[j]."""
    n = len(toks)
    while j < n and toks[j] in ("*", "&", "-", "!", "~", "+", "++", "--"):
        j += 1
    while j < n and toks[j] == "(" and j in close:
        e = close[j] + 1
        if e < n and (_is_var(toks[e]) or toks[e][0].isdigit() or toks[e] == "("):
            j = e  # cast: continue with its operand
            continue
        j = e
        break
    else:
        if j < n and (_is_ident(toks[j]) or toks[j][0].isdigit()):
            j += 1
    while j < n:
        if toks[j] in (".", "->") and j + 1 < n:
            j += 2
        elif toks[j] == "[" and j in close:
            j = close[j] + 1
        else:
            break
    return min(j, n)


def _lvalue_start(toks, k, opened) -> int:
    j = k - 1
    while j >= 0:
        t = toks[j]
        if t == "]" and j in opened:
            j = opened[j] - 1
            continue
        if t == ")" and j in opened:
            j = opened[j] - 1
            if j >= 0 and _is_var(toks[j]):
                j -= 1
            continue
        if _is_var(t) or t[0].isdigit():
            j -= 1
            if j >= 0 and toks[j] in (".", "->"):
                j -= 1
                continue
        break
    start = j + 1
    while start > 0:
        p = toks[start - 1]
        if p == ")" and (start - 1) in opened:
            start = opened[start - 1]  # cast prefix
        elif p == "*" and (start - 1 == 0 or not _is_operand_end(toks[start - 2])):
            start -= 1
        else:
            break
    return start


def analyze(text: str, kind: str = "stmts") -> StmtInfo:
    """Conservative read/write sets of one statement (see module docstring)."""
    toks = TOKEN_RE.findall(strip_noise(text))
    info = StmtInfo()
    n = len(toks)
    close, opened = _match_brackets(toks)
    if any(t in BARRIER_WORDS for t in toks):
        info.barrier = True
    if n >= 2 and _is_var(toks[0]) and toks[1] == ":" and not (n >= 3 and toks[2] == ":"):
        info.barrier = True
    if toks and toks[0].startswith("#"):
        info.barrier = True
    store_spans: list[tuple[int, int]] = []  # pure `=` store targets (not reads)

    def handle(span: tuple[int, int], pure: bool) -> None:
        lv = toks[span[0] : span[1]]
        if len(lv) == 1 and _is_var(lv[0]):
            info.writes.add(lv[0])
            if pure:
                store_spans.append(span)
            else:
                info.reads.add(lv[0])
        elif lv:
            key = "".join(lv)
            info.mwrites.add(key)
            if pure:
                store_spans.append(span)
            else:
                info.mreads.add(key)

    for k, t in enumerate(toks):
        if t in ASSIGN_OPS:
            handle((_lvalue_start(toks, k, opened), k), t == "=")
        elif t in ("++", "--"):
            if k > 0 and _is_operand_end(toks[k - 1]):
                handle((_lvalue_start(toks, k, opened), k), False)
            else:
                handle((k + 1, _operand_end(toks, k + 1, close)), False)

    def in_store(i: int, j: int) -> bool:
        return any(a <= i and j <= b for a, b in store_spans)

    for i, t in enumerate(toks):
        if not _is_var(t) or (i > 0 and toks[i - 1] in (".", "->")):
            continue
        simple_store = any(a == i and b == i + 1 for a, b in store_spans)
        if not simple_store:
            info.reads.add(t)
        if i + 1 < n and toks[i + 1] == "(":
            info.mreads.add("*")
            info.mwrites.add("*")
            continue
        j = i + 1
        while j < n:
            if toks[j] in (".", "->") and j + 1 < n and _is_ident(toks[j + 1]):
                j += 2
            elif toks[j] == "[" and j in close:
                j = close[j] + 1
            else:
                break
        if j > i + 1 and not in_store(i, j):
            info.mreads.add("".join(toks[i:j]))
    if kind == "stmts":
        for k, t in enumerate(toks):
            if t == "*" and (k == 0 or not _is_operand_end(toks[k - 1])) and k + 1 < n:
                e = _operand_end(toks, k + 1, close)
                if not in_store(k, e):
                    info.mreads.add("*" + "".join(toks[k + 1 : e]))
    if kind == "decls":
        # declared names are writes: last identifier of each top-level declarator
        depth, cur, decls = 0, [], []
        for t in toks:
            if t in ("(", "[", "{"):
                depth += 1
            elif t in (")", "]", "}"):
                depth -= 1
            if t == "," and depth == 0:
                decls.append(cur)
                cur = []
            else:
                cur.append(t)
        decls.append(cur)
        for d in decls:
            left = []
            for t in d:
                if t in ("=", "["):
                    break
                left.append(t)
            names = [t for t in left if _is_var(t)]
            if names:
                info.writes.add(names[-1])
    return info


def _alias(x: str, y: str) -> bool:
    if x == "*" or y == "*" or x == y:
        return True
    for a, b in ((x, y), (y, x)):
        if b.startswith(a) and b[len(a) : len(a) + 1] in (".", "[") or b.startswith(a + "->"):
            return True
    return False


def conflicts(a: StmtInfo, b: StmtInfo, mode: str = "loose") -> bool:
    """True when statements a and b must keep their relative order."""
    if a.barrier or b.barrier:
        return True
    if mode == "free":
        return False
    if a.writes & (b.reads | b.writes) or b.writes & a.reads:
        return True
    if mode == "strict":
        return bool((a.mwrites and (b.mreads or b.mwrites)) or (b.mwrites and (a.mreads or a.mwrites)))
    for x in a.mwrites:
        if any(_alias(x, y) for y in b.mreads | b.mwrites):
            return True
    for x in b.mwrites:
        if any(_alias(x, y) for y in a.mreads):
            return True
    return False


def conflict_matrix(infos: list[StmtInfo], mode: str) -> list[list[bool]]:
    n = len(infos)
    return [[i != j and conflicts(infos[i], infos[j], mode) for j in range(n)] for i in range(n)]


def linear_extensions(conf: list[list[bool]]):
    """Yield every order of 0..n-1 keeping the relative order of conflicting pairs."""
    n = len(conf)
    preds = [{i for i in range(j) if conf[i][j]} for j in range(n)]

    def rec(order, placed):
        if len(order) == n:
            yield tuple(order)
            return
        for j in range(n):
            if j not in placed and preds[j] <= placed:
                order.append(j)
                placed.add(j)
                yield from rec(order, placed)
                placed.discard(j)
                order.pop()

    yield from rec([], set())


def random_extension(conf: list[list[bool]], rng: random.Random) -> tuple[int, ...]:
    n = len(conf)
    preds = [{i for i in range(j) if conf[i][j]} for j in range(n)]
    placed: set[int] = set()
    order = []
    while len(order) < n:
        avail = [j for j in range(n) if j not in placed and preds[j] <= placed]
        j = rng.choice(avail)
        order.append(j)
        placed.add(j)
    return tuple(order)


def swap_neighbours(order: tuple[int, ...], conf) -> list[tuple[int, ...]]:
    out = []
    for p in range(len(order) - 1):
        a, b = order[p], order[p + 1]
        if not conf[a][b]:
            new = list(order)
            new[p], new[p + 1] = b, a
            out.append(tuple(new))
    return out


# --------------------------------------------------------------------------
# template


@dataclass
class Inline:
    kind: str  # alt | type | vol
    options: list[str]  # options[0] is the original rendering
    line: int = 0


@dataclass
class Block:
    kind: str  # stmts | decls
    mode: str
    seps: list[str]
    stmts: list[str]
    tail: str
    infos: list[StmtInfo]
    conf: list[list[bool]]
    line: int = 0

    def render(self, order) -> str:
        return "".join(self.seps[p] + self.stmts[i] for p, i in enumerate(order)) + self.tail


@dataclass
class Template:
    text: str  # with \x00I<n>\x00 / \x00B<n>\x00 sentinels
    inline: list[Inline]
    blocks: list[Block]


SENTINEL_RE = re.compile(r"\x00([IB])(\d+)\x00")
TYPE_RUN_RE = re.compile(
    r"(?:(?:const|volatile|unsigned|signed|void|char|short|int|long|float|double|"
    r"__int8|__int16|__int32|__int64)\b\s*)+"
)
IDENT_AT_RE = re.compile(r"[A-Za-z_]\w*")


def _resolve_original(text: str, inline: list[Inline]) -> str:
    return re.sub(
        r"\x00I(\d+)\x00", lambda m: inline[int(m.group(1))].options[0], text
    )


def parse_template(source: str) -> Template:
    """Parse PERM_* markup. With no markers the template renders unchanged."""
    inline: list[Inline] = []
    markers = find_markers(source)
    out: list[str] = []
    pos = 0
    i = 0
    while i < len(markers):
        m = markers[i]
        line = line_of(source, m.start)
        if m.name == "PERM_ALT":
            if m.args is None:
                raise MarkupError(f"line {line}: PERM_ALT needs (a|b|...)")
            if i + 1 >= len(markers) or markers[i + 1].name != "PERM_ALT_END":
                raise MarkupError(f"line {line}: PERM_ALT without PERM_ALT_END")
            end = markers[i + 1]
            region = source[m.end : end.start]
            lead = region[: len(region) - len(region.lstrip())]
            trail = region[len(region.rstrip()) :]
            options = [region]
            for alt in split_alts(m.args):
                full = lead + alt + trail if region.strip() else alt
                if full not in options:
                    options.append(full)
            out.append(source[pos : m.start])
            out.append(f"\x00I{len(inline)}\x00")
            inline.append(Inline("alt", options, line))
            pos = end.end
            i += 2
        elif m.name == "PERM_TYPE":
            if not m.args:
                raise MarkupError(f"line {line}: PERM_TYPE needs (a|b|...)")
            out.append(source[pos : m.start])
            k = m.end
            while k < len(source) and source[k] in " \t\r\n":
                k += 1
            run = TYPE_RUN_RE.match(source, k) or IDENT_AT_RE.match(source, k)
            if not run:
                raise MarkupError(f"line {line}: PERM_TYPE is not followed by a type")
            orig = run.group(0).rstrip()
            options = [orig]
            for alt in split_alts(m.args):
                if alt not in options:
                    options.append(alt)
            out.append(source[m.end : k])
            out.append(f"\x00I{len(inline)}\x00")
            inline.append(Inline("type", options, line))
            pos = k + len(orig)
            i += 1
        elif m.name == "PERM_VOLATILE":
            out.append(source[pos : m.start])
            out.append(f"\x00I{len(inline)}\x00")
            inline.append(Inline("vol", ["", "volatile "], line))
            pos = m.end
            i += 1
        elif m.name == "PERM_ALT_END":
            raise MarkupError(f"line {line}: PERM_ALT_END without PERM_ALT")
        else:
            i += 1
    out.append(source[pos:])
    text = "".join(out)

    blocks: list[Block] = []
    out = []
    pos = 0
    markers = find_markers(text)
    i = 0
    while i < len(markers):
        m = markers[i]
        line = line_of(text, m.start)
        if m.name in BLOCK_STARTS:
            if i + 1 >= len(markers) or markers[i + 1].name not in BLOCK_ENDS:
                raise MarkupError(f"line {line}: {m.name} without matching PERM_END (blocks cannot nest)")
            end = markers[i + 1]
            mode = (m.args or "loose").strip() or "loose"
            if mode not in MODES:
                raise MarkupError(f"line {line}: unknown mode {mode!r} (use {', '.join(MODES)})")
            kind = BLOCK_STARTS[m.name]
            chunks, tail = split_statements(text[m.end : end.start])
            if tail.strip() and re.sub(r"/\*.*?\*/|//[^\n]*", "", tail, flags=re.S).strip():
                chunks.append(("", tail.lstrip()))  # unterminated final statement stays pinned
                tail = ""
            infos = [analyze(_resolve_original(t, inline), kind) for _, t in chunks]
            if any(t.startswith("#") for _, t in chunks):
                for (_, t), info in zip(chunks, infos):
                    if t.startswith("#"):
                        info.barrier = True
            blocks.append(
                Block(
                    kind, mode, [c[0] for c in chunks], [c[1] for c in chunks], tail,
                    infos, conflict_matrix(infos, mode), line,
                )
            )
            out.append(text[pos : m.end])
            out.append(f"\x00B{len(blocks) - 1}\x00")
            pos = end.start
            i += 2
        elif m.name in BLOCK_ENDS:
            raise MarkupError(f"line {line}: {m.name} without a block start")
        else:
            i += 1
    out.append(text[pos:])
    return Template("".join(out), inline, blocks)


# --------------------------------------------------------------------------
# search space


class Space:
    """Product of inline choices, block orders and flag sets. State is a tuple:
    ints for inline markers, order tuples for blocks, then a flag-set index."""

    def __init__(self, tmpl: Template, flag_sets: list[list[str]] | None = None, order_cap: int = ORDER_CAP):
        self.tmpl = tmpl
        self.flag_sets = flag_sets or [[]]
        self.order_cap = order_cap
        self.orders: list[list[tuple[int, ...]]] = []
        self.truncated: list[bool] = []
        for b in tmpl.blocks:
            exts = list(itertools.islice(linear_extensions(b.conf), order_cap + 1))
            self.truncated.append(len(exts) > order_cap)
            self.orders.append(exts[:order_cap])
        self.ni, self.nb = len(tmpl.inline), len(tmpl.blocks)

    def baseline(self) -> tuple:
        return (
            *([0] * self.ni),
            *(tuple(range(len(b.stmts))) for b in self.tmpl.blocks),
            0,
        )

    def domain_sizes(self) -> list[int]:
        return (
            [len(x.options) for x in self.tmpl.inline]
            + [len(o) for o in self.orders]
            + [len(self.flag_sets)]
        )

    def size(self) -> int:
        total = 1
        for s in self.domain_sizes():
            total *= s
        return total

    @property
    def exact_size(self) -> bool:
        return not any(self.truncated)

    def enumerate_all(self):
        doms = (
            [range(len(x.options)) for x in self.tmpl.inline]
            + [list(o) for o in self.orders]
            + [range(len(self.flag_sets))]
        )
        for combo in itertools.product(*doms):
            yield tuple(combo)

    def render(self, state: tuple) -> str:
        text = self.tmpl.text
        for bi, blk in enumerate(self.tmpl.blocks):
            order = state[self.ni + bi]
            text = text.replace(f"\x00B{bi}\x00", blk.render(order))
        return re.sub(
            r"\x00I(\d+)\x00",
            lambda m: self.tmpl.inline[int(m.group(1))].options[state[int(m.group(1))]],
            text,
        )

    def flags(self, state: tuple) -> list[str]:
        return self.flag_sets[state[-1]]

    def neighbours(self, state: tuple) -> list[tuple]:
        out = []
        for k, x in enumerate(self.tmpl.inline):
            for v in range(len(x.options)):
                if v != state[k]:
                    out.append(state[:k] + (v,) + state[k + 1 :])
        for bi, blk in enumerate(self.tmpl.blocks):
            k = self.ni + bi
            for new in swap_neighbours(state[k], blk.conf):
                out.append(state[:k] + (new,) + state[k + 1 :])
        for v in range(len(self.flag_sets)):
            if v != state[-1]:
                out.append(state[:-1] + (v,))
        return out

    def mutate(self, state: tuple, rng: random.Random, strength: int = 1) -> tuple:
        dims = []
        for k, x in enumerate(self.tmpl.inline):
            if len(x.options) > 1:
                dims.append(k)
        for bi, blk in enumerate(self.tmpl.blocks):
            if len(self.orders[bi]) > 1:
                dims.append(self.ni + bi)
        if len(self.flag_sets) > 1:
            dims.append(len(state) - 1)
        if not dims:
            return state
        new = list(state)
        for _ in range(rng.choice((1, 1, 2, 3)) if strength else 1):
            k = rng.choice(dims)
            if k < self.ni:
                choices = [v for v in range(len(self.tmpl.inline[k].options)) if v != new[k]]
                new[k] = rng.choice(choices)
            elif k < self.ni + self.nb:
                bi = k - self.ni
                blk = self.tmpl.blocks[bi]
                if rng.random() < 0.25 * strength:
                    new[k] = random_extension(blk.conf, rng)
                else:
                    cur = new[k]
                    for _ in range(rng.randint(1, 1 + strength)):
                        nb = swap_neighbours(cur, blk.conf)
                        if nb:
                            cur = rng.choice(nb)
                    new[k] = cur
            else:
                new[k] = rng.choice([v for v in range(len(self.flag_sets)) if v != new[k]])
        return tuple(new)

    def describe(self, state: tuple) -> list[str]:
        """Human-readable differences from the baseline."""
        base, lines = self.baseline(), []
        for k, x in enumerate(self.tmpl.inline):
            if state[k] != base[k]:
                lines.append(f"line {x.line} {x.kind}: {x.options[0].strip()!r} -> {x.options[state[k]].strip()!r}")
        for bi, blk in enumerate(self.tmpl.blocks):
            order = state[self.ni + bi]
            if order != base[self.ni + bi]:
                lines.append(f"line {blk.line} {blk.kind} block order: {list(order)}")
        if state[-1]:
            lines.append("flags: " + " ".join(self.flag_sets[state[-1]]))
        return lines or ["(baseline: no change)"]

    def summary(self) -> list[str]:
        lines = []
        for x in self.tmpl.inline:
            shown = " | ".join(" ".join(o.split()) or "<empty>" for o in x.options)
            lines.append(f"  line {x.line}: {x.kind} [{shown}]")
        for bi, blk in enumerate(self.tmpl.blocks):
            extra = "+" if self.truncated[bi] else ""
            lines.append(
                f"  line {blk.line}: {blk.kind} block, {len(blk.stmts)} statements, "
                f"mode {blk.mode}, {len(self.orders[bi])}{extra} legal orders"
            )
        if len(self.flag_sets) > 1:
            lines.append("  flag sets: " + "; ".join(" ".join(f) or "<base>" for f in self.flag_sets))
        return lines


# --------------------------------------------------------------------------
# scoring (fn_check's own comparison, run in-process)


def score_output(output: str, returncode: int) -> int:
    """Differing-instruction count from fn_check's printed result (0 = match)."""
    if returncode == 0:
        return 0
    total = 0
    for line in output.splitlines():
        if not line.startswith("FAIL"):
            continue
        if "not defined in compiled object" in line:
            total += 100000
            continue
        problems = line.split(": ", 1)[1].split("; ") if ": " in line else []
        for p in problems:
            m = re.match(r"(\d+) differing instruction", p)
            if m:
                total += int(m.group(1))
                continue
            m = re.match(r"size (0x[0-9a-f]+) != target (0x[0-9a-f]+)", p)
            if m:
                total += max(1, abs(int(m.group(1), 16) - int(m.group(2), 16)) // 4)
                continue
            total += 1
    return max(total, 1)


@dataclass
class Result:
    score: int | None  # None: did not compile
    match: bool = False
    output: str = ""


class FnCheckEvaluator:
    """Compile candidates in parallel (private temp dirs) and compare each with
    fn_check.main() in-process."""

    def __init__(self, source: Path, mappings: list[str], base_flags: list[str], jobs: int, tmp: Path):
        sys.path.insert(0, str(TOOLS_DIR))
        import fn_check  # noqa: PLC0415

        self.fn_check = fn_check
        self.source = source
        self.mappings = mappings
        self.base_flags = base_flags
        self.tmp = tmp
        tmp.mkdir(parents=True, exist_ok=True)
        self.pool = ThreadPoolExecutor(max_workers=max(1, jobs))

    def _compile(self, text: str, flags: list[str]):
        fc = self.fn_check
        workdir = Path(tempfile.mkdtemp(prefix="permute-", dir=self.tmp))
        local = workdir / self.source.name
        local.write_text(text)
        includes = [
            "/I" + os.path.relpath(d, workdir)
            for d in {self.source.resolve().parent, fc.ROOT / "src" / "xbox360"}
        ]
        env = dict(os.environ, TMP=str(workdir), TEMP=str(workdir))
        try:
            proc = subprocess.run(
                [str(fc.WIBO), str(fc.CL), *fc.BASE_FLAGS, *self.base_flags, *flags, *includes, local.name],
                cwd=workdir, env=env, capture_output=True, text=True, timeout=300,
            )
        except subprocess.TimeoutExpired:
            return workdir, None, "compile timeout"
        obj = workdir / (local.stem + ".obj")
        if proc.returncode != 0 or not obj.is_file():
            return workdir, None, proc.stdout + proc.stderr
        return workdir, obj, ""

    def _compare(self, obj: Path) -> Result:
        fc = self.fn_check
        saved_cc, saved_argv = fc.compile_candidate, sys.argv
        fc.compile_candidate = lambda _source, _flags: obj
        sys.argv = ["fn_check.py", str(self.source), *self.mappings]
        buf = io.StringIO()
        rc = 1
        try:
            with contextlib.redirect_stdout(buf):
                rc = fc.main()
        except SystemExit as exc:
            rc = exc.code if isinstance(exc.code, int) else 1
            buf.write(str(exc.code) + "\n" if not isinstance(exc.code, int) else "")
        finally:
            fc.compile_candidate, sys.argv = saved_cc, saved_argv
        out = buf.getvalue()
        if rc != 0 and not any(l.startswith("FAIL") for l in out.splitlines()):
            return Result(None, False, out)  # setup error, not a near-miss
        return Result(score_output(out, rc), rc == 0, out)

    def evaluate(self, jobs: list[tuple[str, list[str]]]):
        """Yield (index, Result) as each finishes comparing."""
        futures = [self.pool.submit(self._compile, text, flags) for text, flags in jobs]
        try:
            for idx, fut in enumerate(futures):
                workdir, obj, log = fut.result()
                try:
                    res = self._compare(obj) if obj else Result(None, False, log)
                finally:
                    shutil.rmtree(workdir, ignore_errors=True)
                yield idx, res
        finally:  # early stop (match): drop queued work, clean finished temp dirs
            for fut in futures:
                if not fut.cancel():
                    try:
                        shutil.rmtree(fut.result()[0], ignore_errors=True)
                    except Exception:  # noqa: BLE001
                        pass

    def close(self) -> None:
        self.pool.shutdown(wait=True)


# --------------------------------------------------------------------------
# search driver


@dataclass
class SearchOutcome:
    matched: tuple | None
    best_state: tuple | None
    best: Result | None
    baseline: Result | None
    tried: int
    elapsed: float
    exhaustive: bool
    stopped: str


def search(
    space: Space,
    evaluate,
    *,
    budget: int = 400,
    time_limit: float = 900.0,
    batch: int = 8,
    seed: int = 1,
    log=lambda msg: None,
) -> SearchOutcome:
    """`evaluate(list[(text, flags)])` yields (index, Result) in order."""
    rng = random.Random(seed)
    t0 = time.monotonic()
    seen: dict[tuple, Result | None] = {}
    state_best: list = [None, None]  # state, result
    outcome = {"matched": None, "baseline": None}

    def over_budget() -> str:
        if len(seen) >= budget:
            return "candidate budget"
        if time.monotonic() - t0 >= time_limit:
            return "time budget"
        return ""

    def run(states: list[tuple]) -> list[tuple[tuple, Result]]:
        states = [s for s in dict.fromkeys(states) if s not in seen][: max(0, budget - len(seen))]
        done = []
        if not states:
            return done
        jobs = [(space.render(s), space.flags(s)) for s in states]
        for idx, res in evaluate(jobs):
            s = states[idx]
            seen[s] = res
            done.append((s, res))
            if outcome["baseline"] is None:
                outcome["baseline"] = res
            if res.score is not None and (
                state_best[1] is None or res.score < state_best[1].score
            ):
                state_best[0], state_best[1] = s, res
                log(f"  [{len(seen)}] best diff count {res.score}  {'; '.join(space.describe(s))}")
            if res.match:
                outcome["matched"] = s
                break
            if len(seen) % 50 == 0:
                best = state_best[1].score if state_best[1] else "-"
                log(f"  [{len(seen)}] tried, best diff count {best}, {time.monotonic() - t0:.0f}s")
        return done

    def finish(stopped: str, exhaustive: bool) -> SearchOutcome:
        return SearchOutcome(
            outcome["matched"], state_best[0], state_best[1], outcome["baseline"],
            len(seen), time.monotonic() - t0, exhaustive, stopped,
        )

    base = space.baseline()
    run([base])
    if outcome["matched"]:
        return finish("match", False)
    size = space.size()
    exhaustive = space.exact_size and size <= budget
    if exhaustive:
        pending = []
        for s in space.enumerate_all():
            pending.append(s)
            if len(pending) >= batch:
                run(pending)
                pending = []
                if outcome["matched"] or over_budget():
                    break
        else:
            run(pending)
        return finish("match" if outcome["matched"] else (over_budget() or "space exhausted"), True)

    # randomized: one-step neighbourhood of the baseline, then hill climb
    nb = space.neighbours(base)
    rng.shuffle(nb)
    for k in range(0, min(len(nb), budget // 2), batch):
        run(nb[k : k + batch])
        if outcome["matched"] or over_budget():
            return finish("match" if outcome["matched"] else over_budget(), False)
    cur_state, cur_score = state_best[0] or base, (state_best[1].score if state_best[1] else 10**9)
    stagnant = 0
    while not over_budget():
        cands = []
        for _ in range(batch * 4):
            strength = 1 + stagnant // 4
            cands.append(space.mutate(cur_state, rng, min(strength, 4)))
            if len(set(cands) - set(seen)) >= batch:
                break
        done = run([c for c in cands if c not in seen][:batch])
        if outcome["matched"]:
            break
        scored = [(r.score, s) for s, r in done if r.score is not None]
        if not scored:
            stagnant += 1
            continue
        top_score, top_state = min(scored, key=lambda x: x[0])
        if top_score < cur_score:
            stagnant = 0
        else:
            stagnant += 1
        if top_score <= cur_score:
            cur_state, cur_score = top_state, top_score
        if stagnant and stagnant % 12 == 0 and state_best[0] is not None:
            cur_state, cur_score = state_best[0], state_best[1].score  # restart from best
    return finish("match" if outcome["matched"] else over_budget(), False)


# --------------------------------------------------------------------------
# CLI


def parse_flag_sweep(values: list[str] | None) -> list[list[str]]:
    base: list[list[str]] = [[]]
    if values is None:
        return base
    for v in values or DEFAULT_FLAG_SWEEP:
        fl = v.split()
        if fl and fl not in base:
            base.append(fl)
    return base


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("source", type=Path)
    ap.add_argument("mappings", nargs="+", help="candidate_name=target_name_or_0xaddr")
    ap.add_argument("--flags", nargs="*", default=[], help="extra cl flags, e.g. /GS-")
    ap.add_argument("--flags-sweep", nargs="*", default=None, metavar="SET")
    ap.add_argument("-j", "--jobs", type=int, default=4)
    ap.add_argument("-n", "--max-candidates", type=int, default=400)
    ap.add_argument("--time", type=float, default=900.0)
    ap.add_argument("--seed", type=int, default=1)
    ap.add_argument("--out", type=Path)
    ap.add_argument("--tmp", type=Path, default=ROOT / "work" / "permute-tmp")
    ap.add_argument("--info", action="store_true")
    ap.add_argument("--render", action="store_true")
    args = ap.parse_args(argv)

    source = args.source
    text = source.read_text()
    try:
        tmpl = parse_template(text)
    except MarkupError as exc:
        print(f"markup error: {exc}", file=sys.stderr)
        return 2
    space = Space(tmpl, parse_flag_sweep(args.flags_sweep))
    if args.render:
        sys.stdout.write(space.render(space.baseline()))
        return 0
    size = space.size()
    print(f"search space: {size}{'+' if not space.exact_size else ''} candidates")
    for line in space.summary():
        print(line)
    if args.info:
        return 0
    if size == 1:
        print("nothing to permute (no markers, or all blocks fully dependent)", file=sys.stderr)

    out = args.out or ROOT / "work" / "permute-out" / f"{source.stem}.perm{source.suffix}"
    if out.resolve() == source.resolve():
        print("refusing to overwrite the input file", file=sys.stderr)
        return 2
    out.parent.mkdir(parents=True, exist_ok=True)

    ev = FnCheckEvaluator(source, args.mappings, args.flags, args.jobs, args.tmp)
    try:
        outcome = search(
            space, ev.evaluate, budget=args.max_candidates, time_limit=args.time,
            batch=max(2, args.jobs * 2), seed=args.seed,
            log=lambda m: print(m, file=sys.stderr, flush=True),
        )
    finally:
        ev.close()

    base = outcome.baseline
    if base is not None and base.score is None:
        print("baseline does not compile:\n" + base.output, file=sys.stderr)
        return 2
    mode = "exhaustive" if outcome.exhaustive else "randomized hill climb"
    print(f"tried {outcome.tried} candidates in {outcome.elapsed:.1f}s ({mode}; stopped: {outcome.stopped})")
    print(f"baseline diff count: {base.score if base else '?'}")
    if outcome.matched is not None:
        winner = space.render(outcome.matched)
        out.write_text(winner)
        print("MATCH. Changes from the original source:")
        for line in space.describe(outcome.matched):
            print("  " + line)
        print(f"winning source: {out}")
        diff = list(difflib.unified_diff(
            space.render(space.baseline()).splitlines(), winner.splitlines(), "original", "winner", lineterm="", n=1))
        if diff:
            print("\n".join(diff[:80]))
        print(f"confirm: python3 tools/fn_check.py {out} {' '.join(args.mappings)} "
              + (" ".join(["--flags", *args.flags, *space.flags(outcome.matched)])
                 if (args.flags or space.flags(outcome.matched)) else ""))
        return 0
    if outcome.best_state is not None and outcome.best is not None:
        best_out = out.with_name(f"{source.stem}.best{source.suffix}")
        best_out.write_text(space.render(outcome.best_state))
        print(f"NO MATCH. Best near-miss: diff count {outcome.best.score}")
        for line in space.describe(outcome.best_state):
            print("  " + line)
        print(f"near-miss source: {best_out}")
        flags = space.flags(outcome.best_state)
        if flags:
            print("near-miss flags: " + " ".join(flags))
        print(outcome.best.output.rstrip())
    else:
        print("NO MATCH and nothing compiled")
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
