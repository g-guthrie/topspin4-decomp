#!/usr/bin/env python3
"""Fail when tracked files look like proprietary game data."""

from __future__ import annotations

import subprocess
from pathlib import Path


BLOCKED_SUFFIXES = {
    ".7z", ".bin", ".dll", ".elf", ".iso", ".pkg", ".rap", ".rar", ".self", ".xex", ".zip"
}
MAX_TRACKED_FILE_SIZE = 5 * 1024 * 1024
# The whole-module measurements now cover >21,000 units. The report is JSON
# metadata validated separately by validate_decomp_dev_report.py, never raw code.
LARGE_TEXT_ALLOWLIST = {
    Path("config/54540859/symbols.txt"),
    Path("reports/54540859/report.json"),
}


def is_allowed_large_text(path: Path) -> bool:
    if path not in LARGE_TEXT_ALLOWLIST:
        return False
    try:
        data = path.read_bytes()
        data.decode("utf-8")
    except (OSError, UnicodeDecodeError):
        return False
    return b"\0" not in data


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
        if (
            path.is_file()
            and path.stat().st_size > MAX_TRACKED_FILE_SIZE
            and not is_allowed_large_text(path)
        ):
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
