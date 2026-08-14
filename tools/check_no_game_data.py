#!/usr/bin/env python3
"""Fail when tracked files look like proprietary game data."""

from __future__ import annotations

import subprocess
from pathlib import Path


BLOCKED_SUFFIXES = {
    ".7z", ".bin", ".elf", ".iso", ".pkg", ".rap", ".rar", ".self", ".xex", ".zip"
}
MAX_TRACKED_FILE_SIZE = 5 * 1024 * 1024


def tracked_files() -> list[Path]:
    result = subprocess.run(
        ["git", "ls-files", "-z"], check=True, capture_output=True
    )
    return [Path(raw.decode()) for raw in result.stdout.split(b"\0") if raw]


def violations(paths: list[Path]) -> list[str]:
    found = []
    for path in paths:
        if path.suffix.lower() in BLOCKED_SUFFIXES:
            found.append(f"blocked extension: {path}")
        if path.is_file() and path.stat().st_size > MAX_TRACKED_FILE_SIZE:
            found.append(f"tracked file exceeds 5 MiB: {path}")
    return found


def main() -> int:
    found = violations(tracked_files())
    if found:
        print("\n".join(found))
        return 1
    print("No tracked game-data candidates found.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
