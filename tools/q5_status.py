#!/usr/bin/env python3
"""Q5 port-decomp status: what is solved, held, and next on the work list.

Usage: python3 tools/q5_status.py [--next N] [--section 2] [--from-end]

Reads docs/agents/q5/worklist.txt (lines "0xADDR SIZE QUEUE [| sisters...]"
under "## <n>: <title>" headers), config/54540859/match.json,
config/54540859/equivalent.json, docs/agents/q5/escalate.json and the claim
dirs in work/q5/claims/. Prints per-section solved/remaining counts and bytes,
then the next unclaimed, unsolved, unescalated items.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
Q5 = ROOT / "docs" / "agents" / "q5"


def solved_addrs() -> tuple[set[int], set[int]]:
    m = json.loads((ROOT / "config/54540859/match.json").read_text())
    matched = {int(x["text_range"].split("-")[0], 16) for x in m["matches"] if x.get("text_range")}
    e = json.loads((ROOT / "config/54540859/equivalent.json").read_text())
    equiv = {int(r["address"], 16) for r in e["rows"]}
    return matched, equiv


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--next", type=int, default=10)
    ap.add_argument("--section", default="2")
    ap.add_argument("--from-end", action="store_true", help="largest first")
    a = ap.parse_args()
    matched, equiv = solved_addrs()
    esc = {int(x["addr"], 16) for x in json.loads((Q5 / "escalate.json").read_text())}
    claims_dir = ROOT / "work/q5/claims"
    claims = {int(p.name, 16) for p in claims_dir.iterdir()} if claims_dir.is_dir() else set()
    sections: dict[str, list[tuple[int, int]]] = {}
    titles: dict[str, str] = {}
    cur = None
    for line in (Q5 / "worklist.txt").read_text().splitlines():
        h = re.match(r"##\s*(\d+):\s*(.*)", line)
        if h:
            cur = h.group(1)
            titles[cur] = h.group(2)
            sections[cur] = []
            continue
        f = line.split()
        if cur and f and f[0].startswith("0x"):
            sections[cur].append((int(f[0], 16), int(f[1])))
            if "|" in f:
                for s in f[f.index("|") + 1:]:
                    sections[cur].append((int(s, 16), int(f[1])))
    print(f"{'sec':<4}{'title':<34}{'total':>6}{'match':>7}{'equiv':>7}{'esc':>5}{'left':>6}{'left B':>9}")
    for k, items in sections.items():
        n_m = sum(a_ in matched for a_, _ in items)
        n_e = sum(a_ in equiv and a_ not in matched for a_, _ in items)
        left = [(a_, s) for a_, s in items if a_ not in matched and a_ not in equiv]
        n_x = sum(a_ in esc for a_, _ in left)
        print(f"{k:<4}{titles[k][:33]:<34}{len(items):>6}{n_m:>7}{n_e:>7}{n_x:>5}{len(left):>6}{sum(s for _, s in left):>9}")
    left = [(a_, s) for a_, s in sections.get(a.section, [])
            if a_ not in matched and a_ not in equiv and a_ not in esc and a_ not in claims]
    left.sort(key=lambda t: (-t[1] if a.from_end else t[1], t[0]))
    print(f"\nnext {a.next} in section {a.section} ({'largest' if a.from_end else 'smallest'} first, unclaimed):")
    for a_, s in left[: a.next]:
        print(f"  0x{a_:08x} {s}")
    if claims:
        print(f"\nopen claims ({len(claims - matched - equiv)} unsolved): "
              + " ".join(f"0x{c:08x}" for c in sorted(claims - matched - equiv)))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
