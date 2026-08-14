#!/usr/bin/env python3
"""Read reproducible identity fields from an Xbox 360 XEX2 header."""

from __future__ import annotations

import argparse
import hashlib
import json
import struct
from pathlib import Path


XEX2_MAGIC = b"XEX2"
EXECUTION_INFO_KEY = 0x00040006


def format_version(value: int) -> str:
    return ".".join(
        str(part)
        for part in (
            (value >> 28) & 0xF,
            (value >> 24) & 0xF,
            (value >> 8) & 0xFFFF,
            value & 0xFF,
        )
    )


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def parse_xex(path: Path) -> dict[str, object]:
    data = path.read_bytes()
    if len(data) < 0x18 or data[:4] != XEX2_MAGIC:
        raise ValueError(f"not an XEX2 executable: {path}")

    _, module_flags, header_size, _, security_offset, header_count = struct.unpack_from(
        ">6I", data, 0
    )
    execution_offset = None
    for index in range(header_count):
        key, value = struct.unpack_from(">2I", data, 0x18 + index * 8)
        if key == EXECUTION_INFO_KEY:
            execution_offset = value
            break
    if execution_offset is None or execution_offset + 0x18 > len(data):
        raise ValueError("XEX2 execution-info header is missing or truncated")

    media_id, version, base_version, title_id = struct.unpack_from(
        ">4I", data, execution_offset
    )
    platform, executable_table, disc_number, disc_count = struct.unpack_from(
        ">4B", data, execution_offset + 0x10
    )
    savegame_id = struct.unpack_from(">I", data, execution_offset + 0x14)[0]

    result = {
        "schema_version": 1,
        "file_size": len(data),
        "sha256": sha256(data),
        "module_flags": f"{module_flags:08X}",
        "header_size": header_size,
        "media_id": f"{media_id:08X}",
        "title_id": f"{title_id:08X}",
        "savegame_id": f"{savegame_id:08X}",
        "version": format_version(version),
        "base_version": format_version(base_version),
        "platform": platform,
        "executable_table": executable_table,
        "disc_number": disc_number,
        "disc_count": disc_count,
    }

    if security_offset + 0x180 <= len(data):
        result.update(
            {
                "image_size": struct.unpack_from(">I", data, security_offset + 0x4)[0],
                "image_flags": f"{struct.unpack_from('>I', data, security_offset + 0x10C)[0]:08X}",
                "load_address": f"{struct.unpack_from('>I', data, security_offset + 0x110)[0]:08X}",
                "region_flags": f"{struct.unpack_from('>I', data, security_offset + 0x178)[0]:08X}",
                "allowed_media_flags": f"{struct.unpack_from('>I', data, security_offset + 0x17C)[0]:08X}",
            }
        )
    return result


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("xex", type=Path)
    args = parser.parse_args()
    print(json.dumps(parse_xex(args.xex), indent=2, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
