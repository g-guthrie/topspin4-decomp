#!/usr/bin/env python3
"""Validate the source-only progress artifact consumed by decomp.dev."""

from __future__ import annotations

import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
PROGRESS_PATH = ROOT / "config" / "progress.json"
REPORT_PATH = ROOT / "reports" / "54540859" / "report.json"


def main() -> int:
    progress = json.loads(PROGRESS_PATH.read_text(encoding="utf-8"))
    report = json.loads(REPORT_PATH.read_text(encoding="utf-8"))
    measures = report["measures"]

    expected = {
        "total_code": str(progress["matching_total_code_bytes"]),
        "matched_code": str(progress["matching_bytes"]),
        "matched_code_percent": progress["matching_code_percent"],
        "total_functions": progress["matching_total_functions"],
        "matched_functions": progress["matching_functions"],
        "matched_functions_percent": progress["matching_functions_percent"],
    }
    for key, value in expected.items():
        if measures.get(key) != value:
            raise SystemExit(
                f"report measure {key!r} is {measures.get(key)!r}, expected {value!r}"
            )

    units = report.get("units", [])
    functions = [function for unit in units for function in unit.get("functions", [])]
    if len(units) != measures["total_units"]:
        raise SystemExit("report unit count does not match total_units")
    if len(functions) != measures["matched_functions"]:
        raise SystemExit("report must retain exactly the measured matching functions")
    if any(function.get("fuzzy_match_percent") != 100.0 for function in functions):
        raise SystemExit("public report contains a function that is not an exact match")

    print(
        "Validated decomp.dev report: "
        f"{measures['matched_functions']} exact functions, "
        f"{measures['matched_code']}/{measures['total_code']} code bytes, "
        f"{len(units)} units"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
