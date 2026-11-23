#!/usr/bin/env python3
"""Check every registered LTCG unit with `fn_check_ltcg.py --auto-context` alone, in parallel.

Usage:
  TS4_MATCHING_DIR=$PWD/work/matching-<latest> python3 tools/ltcg_autocontext_all.py
         [--out work/autoctx_full.tsv] [--jobs N] [--timeout 1200] [SOURCE ...]

Units are the rows of config/54540859/ltcg_units.json (all of them, or the SOURCE paths given).
Each is checked with its recorded flags and none of its recorded context, include or no_include
values: the question is whether --auto-context finds a working link by itself. One row per unit
goes to the TSV (source, functions, matched, result MATCH/FAIL/TIMEOUT, wall seconds, flags,
note: the failing functions, or the fallback that matched); the full output of each check goes
to work/autoctx_logs/<source name>.log. Each worker links in its own scratch directory
work/autoctx_w<i> (TS4_LTCG_SCRATCH), emptied after every unit and removed at the end.
Exit status 0 when every unit matched. Standard library only; nothing here reads game data.
"""

from __future__ import annotations

import argparse
import json
import os
import queue
import shutil
import signal
import subprocess
import sys
import threading
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
UNITS = ROOT / "config" / "54540859" / "ltcg_units.json"
HEADER = ("source", "functions", "matched", "result", "wall_s", "flags", "note")
FALLBACK = "auto-context: no match with the full context; MATCH "


def command(unit: dict) -> list[str]:
    """The check of one unit: its source, functions and flags; no recorded context."""
    cmd = [sys.executable, "tools/fn_check_ltcg.py", unit["source"],
           *[f"{name}={name}" for name in unit["symbols"]], "--auto-context", "--quiet"]
    if unit.get("flags"):
        cmd += ["--flags", *unit["flags"]]
    return cmd


def summarize(unit: dict, returncode, text: str, seconds: float) -> tuple:
    """One TSV row from the output of a check (returncode None: timed out)."""
    lines = text.splitlines()
    matched = sum(line.startswith("MATCH ") for line in lines)
    failed = [line.split()[1].rstrip(":") for line in lines if line.startswith("FAIL ")]
    total = len(unit["symbols"])
    if returncode is None:
        result, note = "TIMEOUT", ""
    elif returncode == 0 and matched == total:
        result = "MATCH"
        note = next((line[len(FALLBACK):] for line in lines if line.startswith(FALLBACK)), "")
    else:
        result, note = "FAIL", ",".join(failed) or (lines[-1][:150] if lines else "")
    return (unit["source"], total, matched, result, f"{seconds:.1f}", " ".join(unit.get("flags") or []), note)


def write_tsv(path: Path, rows: list[tuple]) -> None:
    path.write_text("".join("\t".join(map(str, row)) + "\n" for row in [HEADER, *sorted(rows)]))


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("sources", nargs="*", help="only these unit sources (default: every unit)")
    parser.add_argument("--out", type=Path, default=ROOT / "work" / "autoctx_full.tsv")
    parser.add_argument("--jobs", type=int, default=os.cpu_count() or 1)
    parser.add_argument("--timeout", type=int, default=1200, help="seconds per unit")
    args = parser.parse_args()
    units = json.loads(UNITS.read_text())
    if args.sources:
        units = [u for u in units if u["source"] in set(args.sources)]
    logs = ROOT / "work" / "autoctx_logs"
    logs.mkdir(parents=True, exist_ok=True)
    todo: queue.Queue = queue.Queue()
    for unit in units:
        todo.put(unit)
    rows, lock = [], threading.Lock()

    def worker(index: int) -> None:
        scratch = ROOT / "work" / f"autoctx_w{index}"
        env = dict(os.environ, TS4_LTCG_SCRATCH=str(scratch))
        while True:
            try:
                unit = todo.get_nowait()
            except queue.Empty:
                break
            cmd, start = command(unit), time.time()
            proc = subprocess.Popen(cmd, cwd=ROOT, env=env, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                                    text=True, start_new_session=True)
            try:
                text, _ = proc.communicate(timeout=args.timeout)
                returncode = proc.returncode
            except subprocess.TimeoutExpired:
                os.killpg(proc.pid, signal.SIGKILL)   # the check and its compiler/linker children
                text, _ = proc.communicate()
                returncode = None
            row = summarize(unit, returncode, text, time.time() - start)
            (logs / (Path(unit["source"]).name + ".log")).write_text(" ".join(cmd) + "\n" + text)
            if scratch.is_dir():   # a failed or killed check leaves its ltcgcheck-* directory
                for left in scratch.iterdir():
                    if left.name.startswith("ltcgcheck-"):
                        shutil.rmtree(left, ignore_errors=True)
            with lock:
                rows.append(row)
                write_tsv(args.out, rows)
                print(f"{len(rows)}/{len(units)} {row[3]} {row[0]} {row[4]}s", flush=True)
        if scratch.is_dir() and not any(scratch.iterdir()):
            scratch.rmdir()

    threads = [threading.Thread(target=worker, args=(i,)) for i in range(max(1, args.jobs))]
    for thread in threads:
        thread.start()
    for thread in threads:
        thread.join()
    good = sum(row[3] == "MATCH" for row in rows)
    print(f"{good}/{len(rows)} units MATCH by --auto-context alone "
          f"({sum(row[2] for row in rows)}/{sum(row[1] for row in rows)} functions); {args.out}")
    return 0 if good == len(rows) else 1


if __name__ == "__main__":
    raise SystemExit(main())
