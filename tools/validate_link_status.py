#!/usr/bin/env python3
"""Cross-check the recorded link probes against canonical matching metadata."""

from __future__ import annotations

import json
from pathlib import Path

from matching import MATCHING_UNITS


ROOT = Path(__file__).resolve().parents[1]


def fail(message: str) -> None:
    raise SystemExit(message)


def main() -> int:
    status = json.loads((ROOT / "config" / "link-status.json").read_text())
    progress = json.loads((ROOT / "config" / "progress.json").read_text())
    objects = json.loads(
        (ROOT / "config" / "54540859" / "objects.json").read_text()
    )["swing"]["objects"]

    sources = [unit["source"] for unit in MATCHING_UNITS]
    symbols = {
        symbol: size
        for unit in MATCHING_UNITS
        for symbol, size in unit["symbols"].items()
    }
    if len(sources) != len(set(sources)):
        fail("canonical matching metadata contains a duplicate source")
    if len(symbols) != sum(len(unit["symbols"]) for unit in MATCHING_UNITS):
        fail("canonical matching metadata contains a duplicate symbol")
    if set(sources) != set(objects):
        fail("canonical matching sources differ from objects.json")

    expected_functions = len(symbols)
    expected_bytes = sum(symbols.values())
    if progress["matching_functions"] != expected_functions:
        fail("progress matching_functions differs from canonical metadata")
    if progress["matching_bytes"] != expected_bytes:
        fail("progress matching_bytes differs from canonical metadata")

    forced = status["forced_all_units_probe"]
    expected_forced = {
        "input_source_objects": len(sources),
        "input_matching_functions": expected_functions,
        "input_matching_code_bytes": expected_bytes,
        "map_matching_public_functions": expected_functions,
    }
    for key, expected in expected_forced.items():
        if forced.get(key) != expected:
            fail(f"forced link probe {key} is {forced.get(key)!r}, expected {expected}")

    base_sources = status["input_sources"]
    by_source = {unit["source"]: unit for unit in MATCHING_UNITS}
    if not base_sources or any(source not in by_source for source in base_sources):
        fail("base link probe contains an unknown or empty source set")
    base_symbols = {
        symbol: size
        for source in base_sources
        for symbol, size in by_source[source]["symbols"].items()
    }
    if status["input_matching_functions"] != len(base_symbols):
        fail("base link probe function count differs from canonical metadata")
    if status["input_matching_code_bytes"] != sum(base_symbols.values()):
        fail("base link probe byte count differs from canonical metadata")

    print(
        "Validated link status: "
        f"{len(sources)} source objects, {expected_functions} exact functions, "
        f"{expected_bytes} matching bytes"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
