#!/usr/bin/env python3
"""Map the pinned Jeff-extracted Swing PE file into a private RVA-addressed image."""
import argparse
import hashlib
import struct
from pathlib import Path

INPUT_SHA256 = "a7f28b29ef72fcc88c9b7c8208d27367b2e1bcfdafbeaddc49b9e8d32f952ba9"
OUTPUT_SHA256 = "d78f393eb434b283040f002cd5346b0a70732df8b1fc0798c7a0be8546f27997"


def flatten(data: bytes) -> bytes:
    if hashlib.sha256(data).hexdigest() != INPUT_SHA256:
        raise ValueError("wrong extracted Swing PE hash")
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    if data[pe:pe + 4] != b"PE\0\0":
        raise ValueError("missing PE signature")
    optional = pe + 24
    if struct.unpack_from("<H", data, optional)[0] != 0x10B:
        raise ValueError("expected PE32")
    size, headers = struct.unpack_from("<II", data, optional + 56)
    if size > 64 * 1024 * 1024 or headers > min(size, len(data)):
        raise ValueError("invalid image/header bounds")
    image = bytearray(size)
    image[:headers] = data[:headers]
    count = struct.unpack_from("<H", data, pe + 6)[0]
    table = optional + struct.unpack_from("<H", data, pe + 20)[0]
    copied = [(0, headers)]
    for i in range(count):
        _, rva, raw_size, raw = struct.unpack_from("<IIII", data, table + 40 * i + 8)
        if raw_size == 0:
            continue
        if raw == 0 or raw + raw_size > len(data) or rva + raw_size > size:
            raise ValueError("section outside file/image")
        if any(rva < end and start < rva + raw_size for start, end in copied):
            raise ValueError("overlapping initialized sections")
        image[rva:rva + raw_size] = data[raw:raw + raw_size]
        copied.append((rva, rva + raw_size))
    if hashlib.sha256(image).hexdigest() != OUTPUT_SHA256:
        raise ValueError("mapped image hash differs")
    return bytes(image)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--input", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    image = flatten(args.input.read_bytes())
    with args.output.open("xb") as handle:
        handle.write(image)
    print(f"Mapped {len(image)} private bytes; SHA-256 {OUTPUT_SHA256}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
