#!/usr/bin/env python3
"""Register functions proven EQUIVALENT (tools/fn_equiv.py) in the committed registry.

  python3 tools/equiv_register.py work/specs/<FAM>/<stem>.json [...] [--verify]

Each spec has "route": "equiv", "source", "flags", "functions" {name: addr} and
"evidence" (the --json output of fn_equiv.py). A function is registered only if
its evidence verdict is EQUIVALENT, coverage is 1.0 or at least the spec's
"min_coverage" (default 0.9, the checker's default), and the evidence
source_sha256 equals the current source file. --verify reruns fn_equiv first.
A function that is already matched (config/54540859/match.json) is not
registered: the matched tier always wins (docs/equivalence-tier.md section 6).

Writes config/54540859/equivalent.json (one row per function: summary fields
of the evidence, no machine paths) and the equivalent_functions /
equivalent_bytes pair in config/progress.json. The two tiers are never summed.
"""
import argparse, hashlib, json, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
REG = ROOT / "config/54540859/equivalent.json"
PROGRESS = ROOT / "config/progress.json"
KEEP = ("function", "address", "size", "checker", "seed", "trials", "valid", "discarded",
        "blocks", "blocks_covered", "coverage", "verdict", "source", "source_sha256", "flags")


def matched_starts():
    m = json.loads((ROOT / "config/54540859/match.json").read_text())["matches"]
    return {int(x["text_range"].split("-")[0], 16) for x in m}


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("specs", nargs="*")
    ap.add_argument("--verify", action="store_true")
    a = ap.parse_args()
    reg = json.loads(REG.read_text()) if REG.exists() else {"comment": __doc__.strip().splitlines()[0], "rows": []}
    rows = {r["address"]: r for r in reg["rows"]}
    matched = matched_starts()
    bad = 0
    for sp in a.specs:
        s = json.loads(Path(sp).read_text())
        if s.get("route") != "equiv":
            print(f"{sp}: not an equiv spec"); bad += 1; continue
        src = ROOT / s["source"]
        ev = ROOT / s["evidence"]
        if a.verify:
            cmd = [sys.executable, str(ROOT / "tools/fn_equiv.py"), s["source"]]
            cmd += [f"{n}={v}" for n, v in s["functions"].items()]
            if s.get("flags"):
                cmd += ["--flags", *s["flags"]]
            cmd += ["--json", s["evidence"], "--quiet"]
            subprocess.run(cmd, cwd=ROOT)
        evid = {e["address"].upper(): e for e in json.loads(ev.read_text())}
        sha = hashlib.sha256(src.read_bytes()).hexdigest()
        for name, addr in s["functions"].items():
            key = f"0x{int(addr, 16):08X}"
            e = evid.get(key.upper())
            why = None
            if e is None: why = "no evidence row"
            elif e["verdict"] != "EQUIVALENT": why = f"verdict {e['verdict']}"
            elif e["coverage"] < s.get("min_coverage", 0.9): why = f"coverage {e['coverage']}"
            elif e["source_sha256"] != sha: why = "evidence is for an older source"
            elif int(addr, 16) in matched: why = "already matched"
            if why:
                print(f"{key} {name}: NOT registered ({why})"); bad += 1; continue
            r = {k: e[k] for k in KEEP if k in e}
            r["spec_flags"] = s.get("flags", [])
            rows[key] = r
            print(f"{key} {name}: registered ({e['valid']} valid trials, coverage {e['coverage']:.2f})")
    for k in [k for k in rows if int(k, 16) in matched]:
        print(f"{k}: now matched, dropped from the equivalent tier"); del rows[k]
    reg["rows"] = [rows[k] for k in sorted(rows)]
    REG.write_text(json.dumps(reg, indent=1) + "\n")
    p = json.loads(PROGRESS.read_text())
    p["equivalent_functions"] = len(reg["rows"])
    p["equivalent_bytes"] = sum(r["size"] for r in reg["rows"])
    p["equivalent_basis"] = "tools/fn_equiv.py verdicts registered by tools/equiv_register.py; never summed with matching_*"
    PROGRESS.write_text(json.dumps(p, indent=2) + "\n")
    print(f"equivalent tier: {p['equivalent_functions']} functions, {p['equivalent_bytes']} bytes")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
