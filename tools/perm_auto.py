#!/usr/bin/env python3
"""Automatic permuter: random source mutations, hill climb on fn_check's score.

Usage:
  python3 tools/perm_auto.py SRC name=0xADDR [--ltcg [--context C ...]] [--flags F ...]
                             [-j 4] [--time 600] [--seed N] [--func NAME] [--out PATH]

No markup is needed (tools/permute.py is the markup-driven exhaustive search).
The body of the function named in the mapping (or --func) is tokenized and
mutated with rewrites that keep C semantics (up to evaluation order the
compiler is free to choose anyway):

  swap      exchange two adjacent simple statements in a block (no control flow,
            neither declares a name the other uses)
  commute   swap the operands of + * & | ^ == != (precedence-aware; operands
            that contain operators are parenthesized)
  flip      a < b  ->  b > a  (and <=, >, >=)
  negsub    -A - B  <->  -(A + B);   A - B  ->  A + -B
  compound  a = a OP b  <->  a OP= b
  decls     swap two adjacent declarations
  split     T a = e;  ->  T a; a = e;   (C++ or C99-style only after the decls)
  inttype   int <-> unsigned int <-> long on a local declaration
  paren     drop redundant parentheses around a primary expression

Each candidate is compiled and compared by tools/fn_check.py (or, with --ltcg,
tools/fn_check_ltcg.py) in a private temp file; the score is the differing
instruction count (0 = match). The search keeps a small pool of the best
sources, applies 1-3 mutations to one of them, and accepts ties (plateau moves).
The input file is never modified: a match goes to --out (default
work/permute-out/<stem>.auto<ext>), otherwise the best near miss goes to
<stem>.autobest<ext>. A match is byte-exact by construction, but review the
winner: the matching rules still apply (no stand-in stubs, no false prototypes,
no volatile hacks; this tool never inserts volatile).
"""
from __future__ import annotations

import argparse
import os
import random
import re
import subprocess
import sys
import tempfile
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import permute as _perm  # noqa: E402  (dependency analysis shared with the markup permuter)


def _info(toks, s, e):
    text = "".join(toks[s:e + 1])
    return _perm.analyze(text, "decls" if is_decl(toks, s, e) else "stmts")


def depends(toks, a, b):
    """True when statements a and b (token spans) must keep their order."""
    return _perm.conflicts(_info(toks, *a), _info(toks, *b), "loose")

TOKEN_RE = re.compile(
    r"\s+|//[^\n]*|/\*.*?\*/|\"(?:\\.|[^\"\\])*\"|'(?:\\.|[^'\\])*'"
    r"|0[xX][0-9a-fA-F]+[uUlL]*|\d+\.\d*(?:[eE][-+]?\d+)?[fF]?|\d+[uUlLfF]*"
    r"|[A-Za-z_]\w*|->|\+\+|--|<<=|>>=|<<|>>|<=|>=|==|!=|&&|\|\||[-+*/%&|^]=|::|."
    , re.S)

PREC = {"*": 10, "/": 10, "%": 10, "+": 9, "-": 9, "<<": 8, ">>": 8, "<": 7, ">": 7,
        "<=": 7, ">=": 7, "==": 6, "!=": 6, "&": 5, "^": 4, "|": 3, "&&": 2, "||": 1}
COMMUTE = {"+", "*", "&", "|", "^", "==", "!="}
FLIP = {"<": ">", ">": "<", "<=": ">=", ">=": "<="}
CONTROL = {"if", "else", "for", "while", "do", "switch", "case", "default", "return",
           "goto", "break", "continue"}
TYPE_WORDS = {"int", "unsigned", "signed", "char", "short", "long", "float", "double",
              "void", "const", "struct", "union", "enum", "static", "__int64", "u8", "u16",
              "u32", "u64", "s8", "s16", "s32", "s64", "__vector4", "bool"}
CLOSE = {"(": ")", "[": "]", "{": "}"}


def tokenize(text: str) -> list[str]:
    return TOKEN_RE.findall(text)


def sig(toks, i):
    """Index of the next significant token at or after i."""
    while i < len(toks) and (toks[i].isspace() or toks[i].startswith(("/*", "//"))):
        i += 1
    return i


def sigb(toks, i):
    while i >= 0 and (toks[i].isspace() or toks[i].startswith(("/*", "//"))):
        i -= 1
    return i


def is_ident(t):
    return bool(re.match(r"[A-Za-z_]\w*$", t))


def is_type(seg):
    """Token run that reads as a cast's type name."""
    inner = [x for x in seg if not x.isspace()]
    return bool(inner) and inner[0] != "*" and all(
        x in TYPE_WORDS or x == "*" or (is_ident(x) and (x[0].isupper() or x.startswith(("ts4_", "TS4"))
                                                       or x.endswith("_t")))
        for x in inner) and (inner[0] in TYPE_WORDS or len(inner) <= 3)


def is_atom(t):
    return is_ident(t) or bool(re.match(r"[0-9'\"]", t))


def match_fwd(toks, i):
    """toks[i] is an opener; return index of its closer."""
    depth = 0
    for j in range(i, len(toks)):
        if toks[j] in CLOSE:
            depth += 1
        elif toks[j] in (")", "]", "}"):
            depth -= 1
            if depth == 0:
                return j
    return len(toks) - 1


def match_back(toks, i):
    depth = 0
    for j in range(i, -1, -1):
        if toks[j] in (")", "]", "}"):
            depth += 1
        elif toks[j] in CLOSE:
            depth -= 1
            if depth == 0:
                return j
    return 0


# ---------------------------------------------------------------- operands

def unary_fwd(toks, i):
    """Parse a unary expression starting at significant index i; return end
    index (inclusive) or None."""
    i = sig(toks, i)
    if i >= len(toks):
        return None
    t = toks[i]
    if t in ("-", "+", "!", "~", "*", "&", "++", "--"):
        return unary_fwd(toks, i + 1)
    if t == "(":
        j = match_fwd(toks, i)
        k = sig(toks, j + 1)
        # cast: (type) unary
        if is_type(toks[i + 1:j]) and k < len(toks) and (is_atom(toks[k]) or toks[k] in ("(", "-", "*", "&", "!", "~")):
            return unary_fwd(toks, j + 1)
        end = j
    elif is_atom(t):
        if t == "sizeof":
            return None
        end = i
    else:
        return None
    while True:  # postfix
        k = sig(toks, end + 1)
        if k >= len(toks):
            return end
        if toks[k] in ("(", "["):
            end = match_fwd(toks, k)
        elif toks[k] in ("->", "."):
            m = sig(toks, k + 1)
            if m < len(toks) and is_ident(toks[m]):
                end = m
            else:
                return end
        elif toks[k] in ("++", "--"):
            end = k
        else:
            return end


def unary_back(toks, i):
    """Unary expression ending at significant index i; return start index."""
    i = sigb(toks, i)
    if i < 0:
        return None
    t = toks[i]
    if t in (")", "]"):
        start = match_back(toks, i)
        if t == "]" or True:
            # postfix call/index: keep walking back over the primary
            p = sigb(toks, start - 1)
            if t == ")" and (p < 0 or not (is_ident(toks[p]) or toks[p] in (")", "]"))):
                s = start  # parenthesized primary
            else:
                s = unary_back(toks, p) if p >= 0 else None
                if s is None:
                    return None
    elif is_atom(t):
        s = i
        p = sigb(toks, i - 1)
        if p >= 0 and toks[p] in ("->", "."):
            s = unary_back(toks, p - 1)
            if s is None:
                return None
    else:
        return None
    # prefix unary operators (only if preceded by an operator/opener, i.e. truly unary)
    while True:
        p = sigb(toks, s - 1)
        if p >= 0 and toks[p] == ")":
            o = match_back(toks, p)
            if is_type(toks[o + 1:p]):
                s = o  # cast
                continue
            return s
        if p < 0 or toks[p] not in ("-", "!", "~", "*", "&"):
            return s
        q = sigb(toks, p - 1)
        if q >= 0 and (is_atom(toks[q]) or toks[q] in (")", "]")):
            return s  # binary operator
        s = p


def operand_fwd(toks, i, prec):
    """Right operand of a binary operator of precedence prec: unary followed by
    higher-precedence binary ops."""
    end = unary_fwd(toks, i)
    if end is None:
        return None
    while True:
        k = sig(toks, end + 1)
        if k < len(toks) and toks[k] in PREC and PREC[toks[k]] > prec:
            e2 = operand_fwd(toks, k + 1, PREC[toks[k]])
            if e2 is None:
                return None
            end = e2
        else:
            return end


def operand_back(toks, i, prec):
    """Left operand ending at i: unary preceded by ops of precedence >= prec
    (left associativity)."""
    start = unary_back(toks, i)
    if start is None:
        return None
    while True:
        p = sigb(toks, start - 1)
        if p >= 0 and toks[p] in PREC and PREC[toks[p]] >= prec:
            q = sigb(toks, p - 1)
            if q < 0 or not (is_atom(toks[q]) or toks[q] in (")", "]")):
                return start  # unary use
            s2 = unary_back(toks, q)
            if s2 is None:
                return None
            start = s2
        else:
            return start


def binary_ops(toks, lo, hi):
    out = []
    for i in range(lo, hi):
        if toks[i] in PREC:
            p = sigb(toks, i - 1)
            if p >= lo and (is_atom(toks[p]) or toks[p] in (")", "]")) and toks[p] not in CONTROL:
                out.append(i)
    return out


def wrap(seg):
    s = "".join(seg).strip()
    toks = [t for t in seg if not t.isspace()]
    if len(toks) == 1 or (toks and toks[0] == "(" and match_fwd(toks, 0) == len(toks) - 1):
        return s
    if all(is_atom(t) or t in ("->", ".", "[", "]", "(", ")") for t in toks) and not any(t in PREC for t in toks):
        return s
    return "(" + s + ")"


# ---------------------------------------------------------------- structure

def find_function(toks, name):
    for i, t in enumerate(toks):
        if t == name:
            j = sig(toks, i + 1)
            if j < len(toks) and toks[j] == "(":
                k = sig(toks, match_fwd(toks, j) + 1)
                while k < len(toks) and toks[k] in ("const",):
                    k = sig(toks, k + 1)
                if k < len(toks) and toks[k] == "{":
                    return k, match_fwd(toks, k)
    raise SystemExit(f"function {name} not found with a body")


def statements(toks, lo, hi):
    """Top-level statements of the block toks[lo..hi] (lo='{', hi='}'): list of
    (start, end) inclusive, plus nested blocks recursed separately."""
    out = []
    i = sig(toks, lo + 1)
    while i < hi:
        start = i
        t = toks[i]
        if t == "{":
            end = match_fwd(toks, i)
        elif t in ("if", "for", "while", "switch", "do", "else"):
            end = None  # control: skip to its end conservatively
            j = i
            while j < hi:
                if toks[j] == "{":
                    j = match_fwd(toks, j)
                    k = sig(toks, j + 1)
                    if k < hi and toks[k] == "else":
                        j = k
                        continue
                    end = j
                    break
                if toks[j] == "(":
                    j = match_fwd(toks, j)
                elif toks[j] == ";":
                    k = sig(toks, j + 1)
                    if k < hi and toks[k] == "else":
                        j = k
                        continue
                    end = j
                    break
                j += 1
            if end is None:
                end = hi - 1
        else:
            j = i
            while j < hi and toks[j] != ";":
                if toks[j] in CLOSE:
                    j = match_fwd(toks, j)
                j += 1
            end = j
        out.append((start, end))
        i = sig(toks, end + 1)
    return out


def blocks(toks, lo, hi):
    res = [(lo, hi)]
    for i in range(lo + 1, hi):
        if toks[i] == "{":
            res.append((i, match_fwd(toks, i)))
    return res


def is_decl(toks, s, e):
    t = [x for x in toks[s:e + 1] if not x.isspace() and not x.startswith("/*")]
    if not t or t[0] in CONTROL:
        return False
    if t[0] in TYPE_WORDS:
        return True
    # typedef-name declarator: Ident [*]* ident [= ...] ;
    k = 1
    while k < len(t) and t[k] == "*":
        k += 1
    return is_ident(t[0]) and k < len(t) and is_ident(t[k]) and k + 1 < len(t) and t[k + 1] in ("=", ";", ",", "[")


def names_in(toks, s, e):
    return {t for t in toks[s:e + 1] if is_ident(t)}


def declared(toks, s, e):
    t = [x for x in toks[s:e + 1] if not x.isspace()]
    out = set()
    depth = 0
    for k, x in enumerate(t):
        if x in CLOSE:
            depth += 1
        elif x in (")", "]", "}"):
            depth -= 1
        elif depth == 0 and is_ident(x) and k + 1 < len(t) and t[k + 1] in ("=", ";", ",", "[") and x not in TYPE_WORDS:
            out.add(x)
    return out


# ---------------------------------------------------------------- mutations

cxx_mode = [False]


def m_swap(toks, rng, fn):
    cands = []
    for lo, hi in blocks(toks, *fn):
        st = statements(toks, lo, hi)
        for a, b in zip(st, st[1:]):
            ta, tb = toks[a[0]], toks[b[0]]
            if ta in CONTROL or tb in CONTROL or ta == "{" or tb == "{":
                continue
            da, db = declared(toks, *a) if is_decl(toks, *a) else set(), declared(toks, *b) if is_decl(toks, *b) else set()
            if da & names_in(toks, *b) or db & names_in(toks, *a) or depends(toks, a, b):
                continue
            if is_decl(toks, *a) != is_decl(toks, *b) and not cxx_mode[0]:
                continue  # C89: declarations stay ahead of statements
            if any(t in ("return", "goto") for t in toks[a[0]:b[1] + 1]):
                continue
            cands.append((a, b))
    if not cands:
        return None
    (a0, a1), (b0, b1) = rng.choice(cands)
    return toks[:a0] + toks[b0:b1 + 1] + toks[a1 + 1:b0] + toks[a0:a1 + 1] + toks[b1 + 1:]


def _binop_rewrite(toks, rng, fn, ops, make):
    lo, hi = fn
    idx = [i for i in binary_ops(toks, lo + 1, hi) if toks[i] in ops]
    rng.shuffle(idx)
    for i in idx:
        p = PREC[toks[i]]
        ls = operand_back(toks, i - 1, p)
        re_ = operand_fwd(toks, i + 1, p)
        if ls is None or re_ is None or ls <= lo or re_ >= hi:
            continue
        le = sigb(toks, i - 1)
        rs = sig(toks, i + 1)
        new = make(toks[i], toks[ls:le + 1], toks[rs:re_ + 1])
        if new is None:
            continue
        return toks[:ls] + tokenize(new) + toks[re_ + 1:]
    return None


def m_commute(toks, rng, fn):
    return _binop_rewrite(toks, rng, fn, COMMUTE, lambda op, l, r: f"{wrap(r)} {op} {wrap(l)}")


def m_flip(toks, rng, fn):
    return _binop_rewrite(toks, rng, fn, set(FLIP), lambda op, l, r: f"{wrap(r)} {FLIP[op]} {wrap(l)}")


def m_negsub(toks, rng, fn):
    def mk(op, l, r):
        lt = [t for t in l if not t.isspace()]
        if lt and lt[0] == "-":
            return f"-({''.join(l[l.index('-') + 1:]).strip()} + {wrap(r)})"
        if rng.random() < 0.5:
            return f"{wrap(l)} + -{wrap(r)}"
        return f"-{wrap(r)} + {wrap(l)}"
    return _binop_rewrite(toks, rng, fn, {"-"}, mk)


def m_compound(toks, rng, fn):
    lo, hi = fn
    st = [s for b in blocks(toks, *fn) for s in statements(toks, *b)]
    rng.shuffle(st)
    for s, e in st:
        text = "".join(toks[s:e + 1])
        m = re.match(r"(\s*)([\w\->\.\[\]]+)\s*=\s*\2\s*([-+*/&|^]|<<|>>)\s*(.+);\s*$", text, re.S)
        if m and not is_decl(toks, s, e):
            new = f"{m[2]} {m[3]}= {m[4]};"
            return toks[:s] + tokenize(new) + toks[e + 1:]
        m = re.match(r"(\s*)([\w\->\.\[\]]+)\s*([-+*/&|^]|<<|>>)=\s*(.+);\s*$", text, re.S)
        if m:
            new = f"{m[2]} = {m[2]} {m[3]} ({m[4]});"
            return toks[:s] + tokenize(new) + toks[e + 1:]
    return None


def m_decls(toks, rng, fn):
    cands = []
    for lo, hi in blocks(toks, *fn):
        st = statements(toks, lo, hi)
        for a, b in zip(st, st[1:]):
            if is_decl(toks, *a) and is_decl(toks, *b) and not (declared(toks, *a) & names_in(toks, *b)) \
                    and not depends(toks, a, b):
                cands.append((a, b))
    if not cands:
        return None
    (a0, a1), (b0, b1) = rng.choice(cands)
    return toks[:a0] + toks[b0:b1 + 1] + toks[a1 + 1:b0] + toks[a0:a1 + 1] + toks[b1 + 1:]


def m_split(toks, rng, fn, cxx=False):
    for lo, hi in rng.sample(blocks(toks, *fn), len(blocks(toks, *fn))):
        st = statements(toks, lo, hi)
        ndecl = 0
        while ndecl < len(st) and is_decl(toks, *st[ndecl]):
            ndecl += 1
        for k in range(ndecl):
            s, e = st[k]
            text = "".join(toks[s:e + 1])
            m = re.match(r"(\s*)([^=;,]*?)(\b[A-Za-z_]\w*)\s*=\s*([^;]+);\s*$", text, re.S)
            if not m or "," in m[4] and "(" not in m[4]:
                continue
            if any(m[3] in names_in(toks, *st[q]) for q in range(k + 1, ndecl)) and not cxx:
                continue
            if any(depends(toks, st[k], st[q]) for q in range(k + 1, ndecl)) and not cxx:
                continue
            decl = f"{m[2]}{m[3]};"
            asg = f"{m[3]} = {m[4]};"
            if cxx:
                return toks[:s] + tokenize(decl + " " + asg) + toks[e + 1:]
            # C89: the assignment must follow the last declaration of the block
            ls, le = st[ndecl - 1]
            return (toks[:s] + tokenize(decl) + toks[e + 1:le + 1] + tokenize(" " + asg) + toks[le + 1:])
    return None


def m_inttype(toks, rng, fn):
    lo, hi = fn
    cyc = {"int": "unsigned int", "unsigned": "int", "long": "int"}
    idx = []
    for b in blocks(toks, *fn):
        for s, e in statements(toks, *b):
            if is_decl(toks, s, e):
                k = sig(toks, s)
                if toks[k] in cyc:
                    idx.append(k)
    if not idx:
        return None
    k = rng.choice(idx)
    rep = cyc[toks[k]]
    if toks[k] == "unsigned":
        n = sig(toks, k + 1)
        if toks[n] == "int":
            return toks[:k] + ["int"] + toks[n + 1:]
    return toks[:k] + tokenize(rep) + toks[k + 1:]


def m_paren(toks, rng, fn):
    lo, hi = fn
    idx = [i for i in range(lo + 1, hi) if toks[i] == "("]
    rng.shuffle(idx)
    for i in idx:
        p = sigb(toks, i - 1)
        if p >= 0 and (is_ident(toks[p]) or toks[p] in (")", "]")):
            continue  # call or cast-like
        j = match_fwd(toks, i)
        inner = [t for t in toks[i + 1:j] if not t.isspace()]
        if inner and not any(t in PREC or t in ("?", "=", ",") for t in inner) and inner[0] not in TYPE_WORDS:
            return toks[:i] + toks[i + 1:j] + toks[j + 1:]
    return None


def field_types(text):
    """name -> type text for struct members and locals/params declared in the
    file (only names declared once with one type)."""
    seen = {}
    body = re.sub(r"/\*.*?\*/|//[^\n]*", " ", text, flags=re.S)
    for m in re.finditer(r"([A-Za-z_][\w ]*?[\w])\s*((?:\*\s*)*)\b([A-Za-z_]\w*)\s*(?=[;,)=\[])", body):
        typ, stars, name = m[1].strip(), m[2].replace(" ", ""), m[3]
        words = typ.split()
        if not words or words[-1] in ("return", "goto", "else") or words[0] in CONTROL or "typedef" in words:
            continue
        if "[" in body[m.end():m.end() + 1]:
            continue
        t = (" ".join(w for w in words if w not in ("static", "extern", "register")) + " " + stars).strip()
        if not t or t.split()[-1] in ("return",):
            continue
        seen.setdefault(name, set()).add(t)
    return {k: next(iter(v)) for k, v in seen.items() if len(v) == 1}


def expr_type(seg, types):
    t = [x for x in seg if not x.isspace()]
    if not t:
        return None
    if t[0] == "(":
        j = match_fwd(t, 0)
        if j < len(t) - 1 and is_type(t[1:j]):
            return " ".join(t[1:j]).replace(" *", "*")
    if t[0] in ("*", "&", "-", "!", "~"):
        return None
    if t[-1] == "]" or t[-1] == ")":
        return None
    if is_ident(t[-1]) and (len(t) == 1 or t[-2] in ("->", ".")):
        return types.get(t[-1])
    return None


def m_hoist(toks, rng, fn, cxx=False, types=None):
    """Pull a member chain or cast out into a temporary declared just before
    the statement (wrapped in its own { } so C89 accepts it)."""
    lo, hi = fn
    st = [x for b in blocks(toks, *fn) for x in statements(toks, *b)]
    st = [x for x in st if (toks[x[0]] not in CONTROL or toks[x[0]] == "return") and toks[x[0]] != "{"
          and not is_decl(toks, *x)]
    rng.shuffle(st)
    for s, e in st:
        cands = []
        for i in range(s, e):
            if toks[i] in ("->", "(") or (is_ident(toks[i]) and toks[i] not in TYPE_WORDS):
                pass
            else:
                continue
            for j in range(i, e):
                if toks[j] in ("->", ".", "(", "["):
                    pass
            # take maximal unary expression starting at i
        k = s
        while k < e:
            pk0 = sigb(toks, k - 1)
            starts = not (pk0 >= 0 and (toks[pk0] in ("->", ".") or (toks[k] in ("(", "[") and (is_ident(toks[pk0]) or toks[pk0] in (")", "]")))))
            end = unary_fwd(toks, k) if starts and (is_ident(toks[k]) or toks[k] == "(") else None
            if end is not None and end < e and end > k:
                seg = toks[k:end + 1]
                ty = expr_type(seg, types or {})
                pk = sigb(toks, k - 1)
                nk = sig(toks, end + 1)
                lhs = nk < len(toks) and toks[nk] in ("=", "+=", "-=", "*=", "|=", "&=", "^=", "++", "--")
                if ty and not lhs and toks[pk] != "&" and ty != "void":
                    cands.append((k, end, ty))
                if is_ident(toks[k]):  # chain prefixes: a->b of a->b->c
                    for m_ in range(k + 1, end):
                        if is_ident(toks[m_]) and toks[sigb(toks, m_ - 1)] in ("->", ".") and toks[sig(toks, m_ + 1)] in ("->", "."):
                            ty2 = expr_type(toks[k:m_ + 1], types or {})
                            if ty2:
                                cands.append((k, m_, ty2))
                # descend into the expression too
            k += 1
        if not cands:
            continue
        k, end, ty = rng.choice(cands)
        expr = "".join(toks[k:end + 1]).strip()
        name = f"t{rng.randrange(1000)}"
        stmt = toks[s:k] + [name] + toks[end + 1:e + 1]
        if rng.random() < 0.5:  # also replace the other identical occurrences
            pat = [t for t in toks[k:end + 1] if not t.isspace()]
            i, outt = 0, []
            while i < len(stmt):
                j, m_ = i, 0
                while j < len(stmt) and m_ < len(pat) and (stmt[j].isspace() or stmt[j] == pat[m_]):
                    if not stmt[j].isspace():
                        m_ += 1
                    j += 1
                prev = sigb(stmt, i - 1)
                if m_ == len(pat) and not stmt[i].isspace() and not (prev >= 0 and stmt[prev] in ("->", ".")) \
                        and not (j < len(stmt) and is_ident(stmt[j])):
                    nxt = sig(stmt, j)
                    if not (nxt < len(stmt) and stmt[nxt] in ("=", "+=", "-=", "++", "--")):
                        outt.append(name)
                        i = j
                        continue
                outt.append(stmt[i])
                i += 1
            stmt = outt
        new = tokenize(f"{{ {ty} {name} = {expr}; ") + stmt + tokenize(" }")
        return toks[:s] + new + toks[e + 1:]
    return None


def m_unhoist(toks, rng, fn):
    """Inline a local `T x = e;` used exactly once later in the same block."""
    for lo, hi in rng.sample(blocks(toks, *fn), len(blocks(toks, *fn))):
        st = statements(toks, lo, hi)
        for k, (s, e) in enumerate(st):
            if not is_decl(toks, s, e):
                continue
            text = "".join(toks[s:e + 1])
            m = re.match(r"\s*[^=;,]*?\b([A-Za-z_]\w*)\s*=\s*([^;]+);\s*$", text, re.S)
            if not m:
                continue
            name, init = m[1], m[2].strip()
            uses = [i for i in range(e + 1, hi) if toks[i] == name]
            if len(uses) != 1:
                continue
            u = uses[0]
            between = [x for x in st[k + 1:] if x[0] <= u]
            if any(depends(toks, (s, e), x) for x in between[:-1]):
                continue
            if between and any(t in ("for", "while", "do") for t in toks[between[-1][0]:u]):
                continue  # do not move a computation into a loop
            # do not move across a statement that writes something the init reads
            rep = tokenize("(" + init + ")") if any(t in PREC for t in tokenize(init)) else tokenize(init)
            return toks[:s] + toks[e + 1:u] + rep + toks[u + 1:]
    return None


MUTATORS = [m_swap, m_swap, m_commute, m_commute, m_flip, m_negsub, m_compound, m_decls, m_split,
            m_inttype, m_paren, m_hoist, m_hoist, m_hoist, m_unhoist]


def mutate(text, rng, func, cxx):
    toks = tokenize(text)
    types = field_types(text)
    for _ in range(12):
        fn = find_function(toks, func)
        m = rng.choice(MUTATORS)
        new = (m(toks, rng, fn, cxx) if m is m_split else m(toks, rng, fn, cxx, types) if m is m_hoist else m(toks, rng, fn))
        if new is not None and new != toks:
            return "".join(new), m.__name__[2:]
    return None, None


# ---------------------------------------------------------------- scoring

def score(output, rc):
    if rc == 0 and "MATCH" in output:
        return 0
    if "compile failed" in output or "error C" in output:
        return None
    if re.search(r"warning C47(00|01|03)", output):
        return None  # uses an uninitialized local: semantics changed
    n = [int(x) for x in re.findall(r"(\d+) differing instruction", output)]
    if n:
        return sum(n)
    stars = sum(1 for l in output.splitlines() if l.startswith("*"))
    return stars or 10 ** 6


def evaluate(text, args, tmpdir):
    fd, path = tempfile.mkstemp(suffix=Path(args.source).suffix, dir=tmpdir, prefix=Path(args.source).stem + "_")
    with os.fdopen(fd, "w") as f:
        f.write(text)
    try:
        if args.ltcg:
            cmd = [sys.executable, str(ROOT / "tools/fn_check_ltcg.py"), path, *args.mappings, "--quiet"]
            for c in args.context:
                cmd += ["--context", c]
        else:
            cmd = [sys.executable, str(ROOT / "tools/fn_check.py"), path, *args.mappings]
        if args.flags:
            cmd += ["--flags", *args.flags]
        r = subprocess.run(cmd, capture_output=True, text=True, cwd=ROOT, timeout=600)
        return score(r.stdout + r.stderr, r.returncode)
    except subprocess.TimeoutExpired:
        return None
    finally:
        os.unlink(path)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("source")
    ap.add_argument("mappings", nargs="+")
    ap.add_argument("--func", help="function to mutate (default: name of the first mapping)")
    ap.add_argument("--ltcg", action="store_true", help="score with tools/fn_check_ltcg.py")
    ap.add_argument("--context", action="append", default=[])
    ap.add_argument("--flags", nargs="*", default=None)
    ap.add_argument("-j", type=int, default=4)
    ap.add_argument("--time", type=float, default=600)
    ap.add_argument("--max", type=int, default=100000, help="candidate budget")
    ap.add_argument("--seed", type=int)
    ap.add_argument("--out")
    ap.add_argument("--pool", type=int, default=6)
    args = ap.parse_args(argv)
    if args.flags is None:
        args.flags = ["/Oc"]
    if args.ltcg and not args.context:
        args.context = ["src/xbox360/pp1_pool_primer.c"]
    src = Path(args.source)
    func = args.func or args.mappings[0].split("=", 1)[0]
    cxx = src.suffix in (".cpp", ".cc")
    cxx_mode[0] = cxx
    rng = random.Random(args.seed)
    tmpdir = tempfile.mkdtemp(prefix="permauto-", dir=ROOT / "work")
    base = src.read_text()
    outdir = ROOT / "work/permute-out"
    outdir.mkdir(parents=True, exist_ok=True)
    out = Path(args.out) if args.out else outdir / f"{src.stem}.auto{src.suffix}"
    best_path = outdir / f"{src.stem}.autobest{src.suffix}"

    s0 = evaluate(base, args, tmpdir)
    if s0 is None:
        raise SystemExit("baseline does not compile/compare; fix it first")
    print(f"baseline score {s0}", flush=True)
    if s0 == 0:
        print("baseline already matches")
        return 0
    pool = [(s0, base)]
    seen = {base}
    t0 = time.time()
    tried = 0
    best = s0
    with ThreadPoolExecutor(max_workers=args.j) as ex:
        while time.time() - t0 < args.time and tried < args.max:
            batch = []
            for _ in range(args.j * 2):
                parent = pool[0][1] if rng.random() < 0.5 else rng.choice(pool)[1]
                text, names = parent, []
                for _ in range(rng.choice((1, 1, 1, 2, 2, 3))):
                    t2, nm = mutate(text, rng, func, cxx)
                    if t2:
                        text, names = t2, names + [nm]
                if text in seen:
                    continue
                seen.add(text)
                batch.append((text, names))
            if not batch:
                continue
            for (text, names), sc in zip(batch, ex.map(lambda b: evaluate(b[0], args, tmpdir), batch)):
                tried += 1
                if sc is None:
                    continue
                if sc == 0:
                    out.write_text(text)
                    print(f"MATCH after {tried} candidates, {time.time() - t0:.0f}s ({'+'.join(names)}) -> {out}")
                    return 0
                if sc <= pool[-1][0] or len(pool) < args.pool:
                    pool.append((sc, text))
                    pool.sort(key=lambda x: x[0])
                    del pool[args.pool:]
                if sc < best:
                    best = sc
                    best_path.write_text(text)
                    print(f"  {tried:5d} {time.time() - t0:5.0f}s score {sc} ({'+'.join(names)})", flush=True)
    print(f"no match: best {best} after {tried} candidates; best source {best_path if best < s0 else '(baseline)'}")
    return 1


if __name__ == "__main__":
    sys.exit(main())
