#!/usr/bin/env python3
"""Rank Ghidra function inventories for a first reconstruction pass."""

from __future__ import annotations

import argparse
import csv
from dataclasses import dataclass
from pathlib import Path


@dataclass(frozen=True)
class Candidate:
    entry: str
    name: str
    namespace: str
    body_bytes: int

    @property
    def score(self) -> tuple[int, int, str]:
        """Prefer small leaf-like compiler-named functions deterministically."""
        named_penalty = 1 if not self.name.startswith(("FUN_", "sub_")) else 0
        return (named_penalty, self.body_bytes, self.entry)


def parse_bool(value: str) -> bool:
    return value.strip().lower() == "true"


def load_candidates(path: Path, minimum_bytes: int, maximum_bytes: int) -> list[Candidate]:
    candidates: list[Candidate] = []
    with path.open(newline="", encoding="utf-8") as source:
        for row in csv.DictReader(source):
            if parse_bool(row["is_thunk"]) or parse_bool(row["is_external"]):
                continue
            size = int(row["body_bytes"])
            if not minimum_bytes <= size <= maximum_bytes:
                continue
            candidates.append(
                Candidate(row["entry"], row["name"], row["namespace"], size)
            )
    return sorted(candidates, key=lambda candidate: candidate.score)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("inventory", type=Path)
    parser.add_argument("--limit", type=int, default=25)
    parser.add_argument("--min-bytes", type=int, default=8)
    parser.add_argument("--max-bytes", type=int, default=128)
    args = parser.parse_args()
    if args.limit < 1 or args.min_bytes < 0 or args.max_bytes < args.min_bytes:
        parser.error("invalid ranking bounds")

    writer = csv.writer(__import__("sys").stdout, lineterminator="\n")
    writer.writerow(("rank", "entry", "name", "namespace", "body_bytes"))
    for rank, candidate in enumerate(
        load_candidates(args.inventory, args.min_bytes, args.max_bytes)[: args.limit], 1
    ):
        writer.writerow(
            (rank, candidate.entry, candidate.name, candidate.namespace, candidate.body_bytes)
        )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
