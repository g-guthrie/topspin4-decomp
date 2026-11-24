#!/usr/bin/env python3
"""Verify only the LTCG units a batch can affect, in seconds, before a full build.

Usage: python3 tools/ltcg_precheck.py --split-dir work/matching-bNN/split [--all]

A full tools/matching.py run checks the LTCG units last, about 40 minutes in, and
one stale callee name there fails the whole build (b207: cx41_l1.c still called
fn_888FBB40 after the batch renamed it). This runs the same check
(ltcg_route.build_units) on the units that are affected:

- the unit's source or one of its context files differs from HEAD, or
- the unit's source or context mentions a .text name that HEAD's symbols.txt has
  and the working-tree symbols.txt no longer has (a rename the batch made).

--split-dir is the split directory of the last passing build; LTCG units do not
change its objects. --all checks every unit. Exit 0 when all checked units match.
"""
import argparse
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import ltcg_route  # noqa: E402

SYMS = "config/54540859/symbols.txt"
NAME = re.compile(r"^(\S+) = \.text:0x[0-9A-Fa-f]+;", re.M)


def git(*a):
    return subprocess.run(["git", *a], cwd=ROOT, capture_output=True, text=True).stdout


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--split-dir", type=Path, required=True)
    ap.add_argument("--all", action="store_true")
    ltcg_route.add_arguments(ap)
    args = ap.parse_args()

    units = ltcg_route.load_units()
    changed = set(git("diff", "--name-only", "HEAD").split())
    gone = set(NAME.findall(git("show", f"HEAD:{SYMS}"))) - set(NAME.findall((ROOT / SYMS).read_text()))
    gone_re = re.compile(r"\b(" + "|".join(map(re.escape, sorted(gone))) + r")\b") if gone else None

    picked = []
    for u in units:
        files = [u["source"]] + [c.split(":", 1)[-1] for c in u.get("context", [])]
        why = [f for f in files if f in changed]
        if gone_re:
            for f in files:
                p = ROOT / f
                if p.is_file():
                    m = gone_re.search(p.read_text(errors="replace"))
                    if m:
                        why.append(f"{f} uses renamed {m.group(1)}")
        if args.all or why:
            picked.append(u)
            print(f"check {u['source']}: {'; '.join(why) or 'all'}")
    if not picked:
        print(f"no LTCG unit affected ({len(units)} units, {len(gone)} renamed names)")
        return 0
    with tempfile.TemporaryDirectory() as tmp:
        ltcg_route.build_units(Path(tmp), args.split_dir.resolve(), ROOT / SYMS,
                               args.ltcg_wibo.expanduser().resolve(),
                               args.ltcg_toolchain.expanduser().resolve(),
                               args.ltcg_target_image.expanduser().resolve(), picked)
    print(f"OK: {len(picked)} LTCG unit(s) match")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
