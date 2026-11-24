#!/usr/bin/env python3
"""Diff-driven, targeted permuter for register-numbering / operand-order / scheduling near misses.

Usage:
  python3 tools/regalloc_mutate.py classify SRC name=0xADDR [--ltcg ...] [--flags ...]
  python3 tools/regalloc_mutate.py search   SRC name=0xADDR [--ltcg [--context C] [--include N]] [--flags ...]
                                            [-j 4] [--time 600] [--beam 4] [--depth 3] [--out PATH]

`classify` runs the checker once and sorts every differing instruction pair into a class (see
docs/agents/regalloc.md, "Decision procedure"):
  REG       same mnemonic and operand shape, only register numbers differ
  COMMUTE   same mnemonic, the two source operands swapped (add, fadds, cmpw, ...)
  SWAP      two adjacent instructions exchanged
  FORM      a different instruction for the same job (srwi vs rldicl, ...)
  OTHER     anything else
and prints the targeted moves that the rules suggest.

`search` is a deterministic best-first (beam) search, unlike tools/perm_auto.py's random walk: it enumerates
the whole one-step neighbourhood of the current best sources (each move from the mutator families that fit
the diff classes), evaluates it in parallel, keeps the `--beam` best (ties included) and repeats up to
`--depth` levels. Families (weights come from the diff classes):
  cmpflip   a < b -> b > a, a == b -> b == a      (compares keep source operand order: COMMUTE on cmp*)
  hoist     pull an operand / member chain into a block-scoped local   (a multi-use local ranks as a leaf)
  unhoist   inline a single-use local                                 (expression ranks above variables)
  alias     copy a parameter into a local
  swap      exchange adjacent independent statements                  (SWAP, REG via IR order)
  perm3     all orders of a run of 3 independent simple statements    (store / load order)
  decls     exchange adjacent declarations
  pad       add N `int` pads at the top of the body (OP1 period-8 symbol numbering)
  shiftcast wrap the count of a 64-bit shift in (int)                 (FORM rldicl -> srwi)
  inttype   int <-> unsigned on a local
  split     T a = e; -> T a; a = e;
  retsplit  return E; -> { T r = E; return r; }
The input file is never modified; a match is written to --out (default work/permute-out/<stem>.rega<ext>),
the best near miss to <stem>.regabest<ext>. Review any winner against the matching rules (no volatile, no
stand-in stubs, no false prototypes); this tool never inserts volatile.
"""
from __future__ import annotations

import argparse
import itertools
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
import perm_auto as pa  # noqa: E402

# ---------------------------------------------------------------- diff parsing / classification

LINE_RE = re.compile(r"^(\*?)\s*([0-9A-Fa-f]{8})\s+([0-9a-f]{8})\s+(.*?)\s*\|\s*([0-9a-f]{8})\s+(.*?)\s*$")
REG_RE = re.compile(r"\b([rfv])(\d+)\b")
COMMUTATIVE = {"add", "add.", "addc", "adde", "mullw", "and", "or", "xor", "nand", "nor", "eqv",
               "fadds", "fadd", "fmuls", "fmul", "vaddfp", "vmulfp", "vand", "vor", "vxor",
               "and.", "or.", "xor.", "mullw."}
COMPARES = {"cmpw", "cmplw", "cmpd", "cmpld", "fcmpu", "fcmpo"}


def _strip(asm):
    asm = asm.split(";")[0].strip()
    parts = asm.split(None, 1)
    return (parts[0], parts[1] if len(parts) > 1 else "") if parts else ("", "")


def parse_diff(output):
    """[(changed, target_asm, cand_asm)] from fn_check's side-by-side listing."""
    rows = []
    for line in output.splitlines():
        m = LINE_RE.match(line)
        if m:
            rows.append((m.group(1) == "*", m.group(4), m.group(6)))
    return rows


def _ops(text):
    return [o.strip() for o in text.split(",")] if text else []


def _shape(ops):
    return [REG_RE.sub(lambda m: m.group(1) + "#", o) for o in ops]


def classify_pair(t, c):
    tm, to = _strip(t)
    cm, co = _strip(c)
    if tm == cm:
        a, b = _ops(to), _ops(co)
        if _shape(a) == _shape(b):
            if tm in COMPARES and len(a) == 3 and a[1:] == b[1:][::-1]:
                return "COMMUTE"
            # a swapped pair with a different destination is a renaming (REG), not an operand-order flip
            if tm in COMMUTATIVE and len(a) == 3 and a[1:] == b[1:][::-1] and a[0] == b[0]:
                return "COMMUTE"
            return "REG"
        return "OTHER"
    if {tm, cm} <= {"srwi", "rldicl", "clrlwi", "rlwinm", "rldicr", "slwi", "extrwi"}:
        return "FORM"
    return "OTHER"


def classify(rows):
    """Per-row class list; adjacent exchanged pairs are labelled SWAP."""
    out = []
    i = 0
    while i < len(rows):
        ch, t, c = rows[i]
        if not ch:
            out.append(None)
            i += 1
            continue
        if i + 1 < len(rows) and rows[i + 1][0] and _strip(rows[i + 1][1]) == _strip(c) and _strip(rows[i + 1][2]) == _strip(t):
            out += ["SWAP", "SWAP"]
            i += 2
            continue
        out.append(classify_pair(t, c))
        i += 1
    return out


def summary(rows, classes):
    counts = {}
    mn = {}
    for (ch, t, c), k in zip(rows, classes):
        if k:
            counts[k] = counts.get(k, 0) + 1
            mn.setdefault(k, set()).add(_strip(t)[0])
    return counts, mn


ADVICE = {
    "COMMUTE_cmp": "compare operands keep SOURCE order and the first operand is loaded first: flip the compare "
                   "(cmpflip); to decouple load order from compare order the loaded value must be defined earlier "
                   "(loop-invariant, struct copy `k = e->key`, value used in an earlier block).",
    "COMMUTE_arith": "add/fadds/fmuls/xor/... are canonicalised: source order, single-use locals and statement order "
                     "do not matter. The operand that is a COMPUTED value ranks first, then loads (higher offset first, "
                     "then base parameter order), then VARIABLES (multi-use or cross-block locals, CSE temps, params). "
                     "Make the operand that must come second a variable (hoist with a second use / cross-block) or "
                     "make it a fresh expression (unhoist, re-read the field); then try pads 0-9 (OP1).",
    "REG": "register numbering follows IR allocation order (volatiles rotate r11->r3, saved r31 down by weight). "
           "Single-use locals are forward-substituted, so declaration/statement order of them is inert: change the "
           "TREE instead (a multi-use local, an inline helper's pointer parameter, a value read in an earlier block), "
           "or the order of statements that are NOT substitutable (calls, stores, multi-use locals).",
    "SWAP": "two independent instructions exchanged: swap the source statements (stores through one pointer can "
            "come out reversed), or move accesses through a different pointer value (SC1/SC2).",
    "FORM": "srwi vs rldicl: a 64-bit shift by an unsigned 32-bit count zero-extends the count (rldicl ...,34); "
            "an int count keeps srwi. Wrap the count in (int) (shiftcast).",
}


def advice(rows, classes):
    counts, mn = summary(rows, classes)
    out = []
    if "COMMUTE" in counts:
        if mn["COMMUTE"] & COMPARES:
            out.append(ADVICE["COMMUTE_cmp"])
        if mn["COMMUTE"] - COMPARES:
            out.append(ADVICE["COMMUTE_arith"])
    for k in ("REG", "SWAP", "FORM"):
        if k in counts:
            out.append(ADVICE[k])
    return counts, out


# ---------------------------------------------------------------- new mutators (all take (toks, rng, fn))

def m_cmpflip(toks, rng, fn):
    """a < b -> b > a and a == b -> b == a (compares keep source operand order)."""
    ops = {"<", ">", "<=", ">=", "==", "!="}

    def mk(op, l, r):
        return f"{pa.wrap(r)} {pa.FLIP.get(op, op)} {pa.wrap(l)}"
    return pa._binop_rewrite(toks, rng, fn, ops, mk)


def m_pad(toks, rng, fn):
    """Insert 1-9 `int padK = 0;` declarations at the top of the function body."""
    lo, hi = fn
    n = rng.randint(1, 9)
    used = {t for t in toks[lo:hi] if t.startswith("rpad")}
    if used:
        return None
    pad = " " + " ".join(f"int rpad{k} = 0;" for k in range(n)) + " "
    return toks[:lo + 1] + pa.tokenize(pad) + toks[lo + 1:]


def m_shiftcast(toks, rng, fn):
    """X >> (E) / X << (E)  ->  X >> (int)(E)   (64-bit shift by an int count keeps srwi for the count)."""
    lo, hi = fn
    sites = [i for i in range(lo, hi) if toks[i] in (">>", "<<")]
    rng.shuffle(sites)
    for i in sites:
        j = pa.sig(toks, i + 1)
        if toks[j] == "(" and toks[pa.sig(toks, j + 1)] != "int":
            return toks[:j] + ["(", "int", ")"] + toks[j:]
        if pa.is_ident(toks[j]):
            return toks[:j] + ["(", "int", ")"] + toks[j:]
    return None


def m_perm3(toks, rng, fn):
    """Reorder a run of three adjacent independent simple statements (any of the 5 other orders)."""
    for lo, hi in rng.sample(pa.blocks(toks, *fn), len(pa.blocks(toks, *fn))):
        st = [x for x in pa.statements(toks, lo, hi)]
        runs = []
        for k in range(len(st) - 2):
            trio = st[k:k + 3]
            if any(toks[s] in pa.CONTROL or toks[s] == "{" or pa.is_decl(toks, s, e) for s, e in trio):
                continue
            if any(pa.depends(toks, a, b) for a, b in itertools.combinations(trio, 2)):
                continue
            runs.append(k)
        if not runs:
            continue
        k = rng.choice(runs)
        trio = st[k:k + 3]
        order = rng.choice([p for p in itertools.permutations(range(3)) if p != (0, 1, 2)])
        pieces = ["".join(toks[s:e + 1]) for s, e in trio]
        new = " ".join(pieces[o] for o in order)
        return toks[:trio[0][0]] + pa.tokenize(new) + toks[trio[2][1] + 1:]
    return None


FAMILIES = {
    "cmpflip": m_cmpflip,
    "hoist": pa.m_hoist,
    "unhoist": pa.m_unhoist,
    "alias": pa.m_alias,
    "swap": pa.m_swap,
    "perm3": m_perm3,
    "decls": pa.m_decls,
    "pad": m_pad,
    "shiftcast": m_shiftcast,
    "inttype": pa.m_inttype,
    "split": pa.m_split,
    "retsplit": pa.m_retsplit,
    "commute": pa.m_commute,
}

# Which families to enumerate for each diff class (first = most promising).
CLASS_FAMILIES = {
    "COMMUTE_cmp": ["cmpflip", "hoist", "alias", "unhoist"],
    "COMMUTE_arith": ["hoist", "unhoist", "alias", "pad", "inttype"],
    "REG": ["hoist", "unhoist", "alias", "swap", "perm3", "split", "retsplit", "inttype", "decls"],
    "SWAP": ["swap", "perm3", "hoist", "unhoist"],
    "FORM": ["shiftcast", "inttype", "hoist"],
    "OTHER": ["swap", "hoist", "unhoist", "alias", "cmpflip", "inttype", "shiftcast"],
}


def families_for(rows, classes):
    counts, mn = summary(rows, classes)
    fams = []
    keys = []
    if "COMMUTE" in counts:
        if mn["COMMUTE"] & COMPARES:
            keys.append("COMMUTE_cmp")
        if mn["COMMUTE"] - COMPARES:
            keys.append("COMMUTE_arith")
    keys += [k for k in ("FORM", "SWAP", "REG", "OTHER") if k in counts]
    for k in keys or ["OTHER"]:
        for f in CLASS_FAMILIES[k]:
            if f not in fams:
                fams.append(f)
    return fams


def apply(fam, text, func, rng, cxx):
    toks = pa.tokenize(text)
    fn = pa.find_function(toks, func)
    m = FAMILIES[fam]
    if m is pa.m_split:
        new = m(toks, rng, fn, cxx)
    elif m is pa.m_hoist:
        new = m(toks, rng, fn, cxx, pa.field_types(text))
    else:
        new = m(toks, rng, fn)
    if new is None or new == toks:
        return None
    return "".join(new)


def neighbourhood(text, func, fams, cxx, draws=60, seed=0):
    """Approximate the full one-step neighbourhood: many seeded draws per family, deduplicated."""
    out = {}
    for fam in fams:
        for s in range(draws if fam != "pad" else 9 * 4):
            r = random.Random(hash((seed, fam, s)) & 0xFFFFFFFF)
            try:
                t = apply(fam, text, func, r, cxx)
            except Exception:  # a rewrite that trips on unusual syntax is just skipped
                t = None
            if t and t != text and t not in out:
                out[t] = fam
    return out


# ---------------------------------------------------------------- checking

def run_check(text, args, tmpdir, suffix):
    fd, path = tempfile.mkstemp(suffix=suffix, dir=tmpdir, prefix="rega_")
    with os.fdopen(fd, "w") as f:
        f.write(text)
    try:
        if args.ltcg:
            cmd = [sys.executable, str(ROOT / "tools/fn_check_ltcg.py"), path, *args.mappings]
            for c in args.context:
                cmd += ["--context", c]
            for n in args.include:
                cmd += ["--include", n]
        else:
            cmd = [sys.executable, str(ROOT / "tools/fn_check.py"), path, *args.mappings]
        if args.flags:
            cmd += ["--flags", *args.flags]
        r = subprocess.run(cmd, capture_output=True, text=True, cwd=ROOT, timeout=600)
        out = r.stdout + r.stderr
        return pa.score(out, r.returncode), out
    except subprocess.TimeoutExpired:
        return None, ""
    finally:
        os.unlink(path)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("mode", choices=("classify", "search"))
    ap.add_argument("source")
    ap.add_argument("mappings", nargs="+")
    ap.add_argument("--func")
    ap.add_argument("--ltcg", action="store_true")
    ap.add_argument("--context", action="append", default=[])
    ap.add_argument("--include", action="append", default=[])
    ap.add_argument("--flags", nargs="*", default=None)
    ap.add_argument("-j", type=int, default=4)
    ap.add_argument("--time", type=float, default=600)
    ap.add_argument("--beam", type=int, default=4)
    ap.add_argument("--depth", type=int, default=3)
    ap.add_argument("--draws", type=int, default=60, help="seeded draws per family per source")
    ap.add_argument("--families", help="comma list overriding the diff-driven choice")
    ap.add_argument("--out")
    args = ap.parse_args(argv)
    if args.flags is None:
        args.flags = ["/Oc"]
    if args.ltcg and not args.context:
        args.context = ["src/xbox360/pp1_pool_primer.c"]
    src = Path(args.source)
    func = args.func or args.mappings[0].split("=", 1)[0]
    cxx = src.suffix in (".cpp", ".cc")
    pa.cxx_mode[0] = cxx
    tmpdir = tempfile.mkdtemp(prefix="rega-", dir=ROOT / "work")
    base = src.read_text()
    s0, out0 = run_check(base, args, tmpdir, src.suffix)
    if s0 is None:
        raise SystemExit("baseline does not compile/compare; fix it first")
    rows = parse_diff(out0)
    classes = classify(rows)
    counts, adv = advice(rows, classes)
    print(f"baseline score {s0}; classes {counts}")
    for (ch, t, c), k in zip(rows, classes):
        if k:
            print(f"  {k:8s} {t:34s} | {c}")
    for a in adv:
        print("  -> " + a)
    if args.mode == "classify" or s0 == 0:
        return 0 if s0 == 0 else 1
    fams = args.families.split(",") if args.families else families_for(rows, classes)
    print("families:", ",".join(fams), flush=True)
    outdir = ROOT / "work/permute-out"
    outdir.mkdir(parents=True, exist_ok=True)
    out = Path(args.out) if args.out else outdir / f"{src.stem}.rega{src.suffix}"
    best_path = outdir / f"{src.stem}.regabest{src.suffix}"
    frontier = [(s0, base, fams)]
    seen = {base}
    best = s0
    t0 = time.time()
    tried = 0
    with ThreadPoolExecutor(max_workers=args.j) as ex:
        for depth in range(args.depth):
            cands = {}
            for sc, text, nfams in frontier:
                for t, fam in neighbourhood(text, func, nfams, cxx, args.draws, seed=depth).items():
                    if t not in seen:
                        seen.add(t)
                        cands[t] = fam
            if not cands:
                break
            print(f"depth {depth + 1}: {len(cands)} candidates", flush=True)
            items = list(cands.items())
            scored = []
            for i in range(0, len(items), args.j * 4):
                if time.time() - t0 > args.time:
                    break
                chunk = items[i:i + args.j * 4]
                for (t, fam), (sc, o) in zip(chunk, ex.map(lambda it: run_check(it[0], args, tmpdir, src.suffix), chunk)):
                    tried += 1
                    if sc is None:
                        continue
                    if sc == 0:
                        out.write_text(t)
                        print(f"MATCH after {tried} candidates, {time.time() - t0:.0f}s ({fam}) -> {out}")
                        return 0
                    scored.append((sc, t, o))
                    if sc < best:
                        best = sc
                        best_path.write_text(t)
                        print(f"  {tried:5d} {time.time() - t0:5.0f}s score {sc} ({fam})", flush=True)
            if not scored:
                break
            scored.sort(key=lambda x: x[0])
            # re-derive the families from each kept candidate's own diff (a FORM fix can expose SWAP/REG)
            frontier = []
            for s_, t, o in scored[:args.beam]:
                r_ = parse_diff(o)
                f_ = families_for(r_, classify(r_)) if not args.families else fams
                frontier.append((s_, t, f_))
            if time.time() - t0 > args.time:
                break
    print(f"no match: best {best} after {tried} candidates; best source {best_path if best < s0 else '(baseline)'}")
    return 1


if __name__ == "__main__":
    sys.exit(main())
