#!/usr/bin/env python3
"""Recovery benchmark for tools/perm_auto.py.

Takes matched functions from plain-route specs, scrambles each with K random
perm_auto mutations (keeping only scrambles that no longer match), then runs
perm_auto on the scramble and records whether it gets back to a byte match.

  python3 tools/perm_auto_bench.py [--n 8] [--k 3] [--time 240] [-j 2] [--seed 1]

Output: one line per function and a summary; the recovery rate measures the
mutation set and search, independent of any unmatched function.
"""
import argparse
import glob
import json
import random
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import perm_auto as pa  # noqa: E402


def candidates(rng):
    out = []
    for spec in sorted(glob.glob(str(ROOT / "work/specs/*/*.json"))):
        try:
            sp = json.load(open(spec))
        except Exception:  # noqa: BLE001
            continue
        if sp.get("route") or sp.get("include") or sp.get("restart_endpoint"):
            continue
        src = ROOT / sp.get("source", "")
        if not src.is_file() or src.suffix != ".c":
            continue
        text = src.read_text()
        for name, addr in sp.get("functions", {}).items():
            try:
                toks = pa.tokenize(text)
                lo, hi = pa.find_function(toks, name)
            except SystemExit:
                continue
            body = "".join(toks[lo:hi + 1])
            nst = body.count(";")
            if 3 <= nst <= 12 and len(body) < 700:
                out.append((str(src.relative_to(ROOT)), name, addr, sp.get("flags", ["/Oc"])))
    rng.shuffle(out)
    return out


def check(text, src, name, addr, flags):
    with tempfile.NamedTemporaryFile("w", suffix=".c", dir=ROOT / "work", delete=False) as f:
        f.write(text)
    r = subprocess.run([sys.executable, "tools/fn_check.py", f.name, f"{name}={addr}", "--flags", *flags],
                       capture_output=True, text=True, cwd=ROOT)
    Path(f.name).unlink()
    return pa.score(r.stdout + r.stderr, r.returncode)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--n", type=int, default=8)
    ap.add_argument("--k", type=int, default=3)
    ap.add_argument("--time", type=float, default=240)
    ap.add_argument("-j", type=int, default=2)
    ap.add_argument("--seed", type=int, default=1)
    a = ap.parse_args()
    rng = random.Random(a.seed)
    done = rec = 0
    for src, name, addr, flags in candidates(rng):
        if done >= a.n:
            break
        text = (ROOT / src).read_text()
        if check(text, src, name, addr, flags) != 0:
            continue  # original no longer matches standalone (needs context); skip
        scr, muts = text, []
        for _ in range(a.k):
            t2, nm = pa.mutate(scr, rng, name, False)
            if t2:
                scr, muts = t2, muts + [nm]
        sc = check(scr, src, name, addr, flags)
        if not sc:
            continue  # scramble still matches or broke the compile
        tmp = ROOT / "work/permauto" / f"bench_{name}.c"
        tmp.parent.mkdir(parents=True, exist_ok=True)
        tmp.write_text(scr)
        r = subprocess.run([sys.executable, "tools/perm_auto.py", str(tmp), f"{name}={addr}", "--flags", *flags,
                            "-j", str(a.j), "--time", str(a.time), "--seed", str(a.seed)],
                           capture_output=True, text=True, cwd=ROOT)
        ok = "MATCH after" in r.stdout
        last = r.stdout.strip().splitlines()[-1] if r.stdout.strip() else r.stderr[-200:]
        done += 1
        rec += ok
        print(f"{'RECOVERED' if ok else 'missed   '} {name} scramble={'+'.join(muts)} start={sc} | {last}", flush=True)
    print(f"recovered {rec}/{done}")


if __name__ == "__main__":
    main()
