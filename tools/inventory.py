#!/usr/bin/env python3
"""Create a metadata-only inventory of a user-supplied game dump."""

from __future__ import annotations

import argparse
import hashlib
import json
import shutil
import subprocess
from datetime import datetime, timezone
from pathlib import Path


CHUNK_SIZE = 8 * 1024 * 1024


def sha256_file(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as source:
        for chunk in iter(lambda: source.read(CHUNK_SIZE), b""):
            digest.update(chunk)
    return digest.hexdigest()


def list_container(path: Path) -> list[str]:
    seven_zip = shutil.which("7zz") or shutil.which("7z")
    if not seven_zip or not path.is_file():
        return []
    result = subprocess.run(
        [seven_zip, "l", "-ba", str(path)],
        check=False,
        capture_output=True,
        text=True,
    )
    # Some Xbox 360 optical images expose the video partition to generic UDF
    # readers, then return a non-zero status for the game partition. The
    # successfully listed outer entries are still useful platform evidence.
    if not result.stdout:
        return []
    entries = []
    for line in result.stdout.splitlines():
        parts = line.split(maxsplit=5)
        if len(parts) == 6:
            entries.append(parts[5])
    return entries


def classify(entries: list[str]) -> dict[str, object]:
    normalized = {entry.replace("\\", "/") for entry in entries}
    ps3 = any(entry == "PS3_GAME" or entry.startswith("PS3_GAME/") for entry in normalized)
    xbox_markers = {"$SystemUpdate", "VIDEO_TS"}
    xbox = xbox_markers.issubset({entry.split("/", 1)[0] for entry in normalized})
    if ps3:
        platform = "ps3"
    elif xbox:
        platform = "xbox360-optical"
    else:
        platform = "unknown"
    return {
        "platform_hint": platform,
        "ps3_game_tree_found": ps3,
        "xbox360_optical_markers_found": xbox,
    }


def inventory(path: Path) -> dict[str, object]:
    resolved = path.expanduser().resolve(strict=True)
    if resolved.is_file():
        entries = list_container(resolved)
        return {
            "schema_version": 1,
            "generated_at": datetime.now(timezone.utc).isoformat(),
            "input_type": "file",
            "size_bytes": resolved.stat().st_size,
            "sha256": sha256_file(resolved),
            "container_entry_count": len(entries),
            "top_level_entries": sorted({entry.split("/", 1)[0] for entry in entries}),
            **classify(entries),
        }

    files = sorted(item for item in resolved.rglob("*") if item.is_file())
    relative = [item.relative_to(resolved).as_posix() for item in files]
    return {
        "schema_version": 1,
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "input_type": "directory",
        "file_count": len(files),
        "size_bytes": sum(item.stat().st_size for item in files),
        "top_level_entries": sorted({entry.split("/", 1)[0] for entry in relative}),
        **classify(relative),
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("dump", type=Path)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    report = inventory(args.dump)
    rendered = json.dumps(report, indent=2, sort_keys=True) + "\n"
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(rendered, encoding="utf-8")
    else:
        print(rendered, end="")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
