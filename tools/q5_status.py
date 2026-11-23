#!/usr/bin/env python3
"""Q5 port-decomp status: what is solved, held, and next on the work list.

Usage: python3 tools/q5_status.py [--next N] [--section 2] [--from-end]          (v1 list)
       python3 tools/q5_status.py --worklist v2 [--next N] [--subsystem ID]      (v2 list)

--worklist auto (default) uses v2 when docs/agents/q5/worklist_v2.txt exists and
no --section is given. v2 (tools/callgraph_worklist.py) groups the scope by
subsystem and orders it bottom-up: a function is ready when every in-scope
callee outside its recursion group is matched. Readiness is recomputed live
from match.json and docs/agents/q5/scope_callgraph.json; --next lists ready,
unclaimed, unescalated, unmatched functions, lowest generation level first
(then smallest). --blocked shows, for the listed subsystem, the unmatched
callees that keep the next blocked functions from being ready.

Byte-exact only (owner decision 2026-11-23): equivalent functions are counted
in the "equiv" column but still listed as left.

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


def load_claims() -> set[int]:
    claims_dir = ROOT / "work/q5/claims"
    out = set()
    if claims_dir.is_dir():
        for p in claims_dir.iterdir():
            try:
                out.add(int(p.name, 16))
            except ValueError:
                pass
    return out


def parse_v2():
    """-> (subsystems [(id, name)], rows {addr: dict(sub, size, level, scc)})."""
    subs, rows, cur = [], {}, None
    for line in (Q5 / "worklist_v2.txt").read_text().splitlines():
        h = re.match(r"##\s*(\S+):\s*(.*?)\s*\(\d+ fns", line)
        if h:
            cur = h.group(1)
            subs.append((cur, h.group(2)))
            continue
        f = line.split()
        if cur and f and f[0].startswith("0x"):
            kv = dict(x.split("=", 1) for x in f[2:] if "=" in x and not x.startswith("rep="))
            lv = kv.get("level", "-")
            rows[int(f[0], 16)] = dict(sub=cur, size=int(f[1]), level=int(lv) if lv.lstrip("-").isdigit() else -1,
                                       scc=kv.get("scc"), line=line)
    return subs, rows


def main_v2(a, matched, equiv, esc, claims) -> int:
    subs, rows = parse_v2()
    names = dict(subs)
    if a.subsystem and a.subsystem not in names:
        print(f"unknown subsystem {a.subsystem!r}; known: {' '.join(names)}")
        return 2
    edges = {int(k, 16): [int(c, 16) for c in v]
             for k, v in json.loads((Q5 / "scope_callgraph.json").read_text())["edges"].items()}
    blockers: dict[int, list[int]] = {}
    for x, r in rows.items():
        if x in matched:
            continue
        blockers[x] = [c for c in edges.get(x, []) if c not in matched and c in rows
                       and not (r["scc"] and rows[c]["scc"] == r["scc"])]
    # A recursion group (scc=K) is ready only when no member waits on anything outside it.
    group: dict[str, list[int]] = {}
    for x in blockers:
        if rows[x]["scc"]:
            group.setdefault(rows[x]["scc"], []).append(x)
    for members in group.values():
        merged = sorted({c for m in members for c in blockers[m]})
        for m in members:
            blockers[m] = merged
    ready = {x for x, b in blockers.items() if not b}
    print(f"{'id':<7}{'name':<44}{'total':>6}{'match':>7}{'equiv':>7}{'esc':>5}{'left':>6}{'left B':>9}{'ready':>7}{'claim':>6}")
    tot = [0] * 8
    for sid, nm in subs:
        xs = [x for x, r in rows.items() if r["sub"] == sid]
        left = [x for x in xs if x not in matched]
        vals = [len(xs), sum(x in matched for x in xs), sum(x in equiv for x in left), sum(x in esc for x in left),
                len(left), sum(rows[x]["size"] for x in left), sum(x in ready for x in left),
                sum(x in claims for x in left)]
        tot = [t + v for t, v in zip(tot, vals)]
        print(f"{sid:<7}{nm[:43]:<44}" + "".join(f"{v:>{w}}" for v, w in zip(vals, (6, 7, 7, 5, 6, 9, 7, 6))))
    print(f"{'all':<7}{'':<44}" + "".join(f"{v:>{w}}" for v, w in zip(tot, (6, 7, 7, 5, 6, 9, 7, 6))))
    pool = [x for x in ready if x not in esc and x not in claims
            and (not a.subsystem or rows[x]["sub"] == a.subsystem)]
    pool.sort(key=lambda x: (rows[x]["level"], -rows[x]["size"] if a.from_end else rows[x]["size"], x))
    where = f"subsystem {a.subsystem}" if a.subsystem else "all subsystems"
    print(f"\nnext {a.next} ready in {where} (all in-scope callees matched; unclaimed, unescalated; "
          f"lowest level, then {'largest' if a.from_end else 'smallest'} first):")
    for x in pool[: a.next]:
        print(f"  {rows[x]['line'].replace(' status=', ' gen-status=')}  [{rows[x]['sub']}]"
              + (" (equiv-owed)" if x in equiv else ""))
    if a.blocked:
        blk = [x for x in blockers if blockers[x] and (not a.subsystem or rows[x]["sub"] == a.subsystem)]
        blk.sort(key=lambda x: (len(blockers[x]), rows[x]["size"], x))
        print(f"\nnearest blocked in {where} (unmatched in-scope callees):")
        for x in blk[: a.next]:
            print(f"  0x{x:08x} {rows[x]['size']} waits on " + " ".join(f"0x{c:08x}" for c in blockers[x][:8]))
    open_claims = sorted(c for c in claims if c not in matched)
    if open_claims:
        print(f"\nopen claims ({len(open_claims)} unsolved): " + " ".join(f"0x{c:08x}" for c in open_claims))
    return 0


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--next", type=int, default=10)
    ap.add_argument("--section", default=None, help="v1 worklist section (default 2)")
    ap.add_argument("--from-end", action="store_true", help="largest first")
    ap.add_argument("--worklist", choices=("auto", "v1", "v2"), default="auto")
    ap.add_argument("--subsystem", help="v2: restrict --next to one subsystem id")
    ap.add_argument("--blocked", action="store_true", help="v2: also list the nearest blocked functions")
    a = ap.parse_args()
    matched, equiv = solved_addrs()
    esc = {int(x["addr"], 16) for x in json.loads((Q5 / "escalate.json").read_text())}
    claims = load_claims()
    v2 = a.worklist == "v2" or (a.worklist == "auto" and a.section is None
                                 and (Q5 / "worklist_v2.txt").exists())
    if a.subsystem and not v2:
        print("--subsystem needs the v2 work list (--worklist v2)")
        return 2
    if v2:
        return main_v2(a, matched, equiv, esc, claims)
    a.section = a.section or "2"
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
        left = [(a_, s) for a_, s in items if a_ not in matched]  # equivalents are owed a byte match
        n_x = sum(a_ in esc for a_, _ in left)
        print(f"{k:<4}{titles[k][:33]:<34}{len(items):>6}{n_m:>7}{n_e:>7}{n_x:>5}{len(left):>6}{sum(s for _, s in left):>9}")
    left = [(a_, s) for a_, s in sections.get(a.section, [])
            if a_ not in matched and a_ not in esc and a_ not in claims]
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
