#!/usr/bin/env python3
"""Print the original disassembly of a Swing function from the Jeff split.

Usage: python3 tools/fn_asm.py fn_88170328 [more names or 0xADDRESSES ...]

Requires a completed `tools/matching.py` run (work/matching/split) and the
gc-wii-binutils objdump in work/matching-tools/binutils.
"""

from __future__ import annotations

import argparse
import json
import subprocess
import sys
import tempfile
from functools import lru_cache
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from xcoff import ROOT, load_symbols, read_coff  # noqa: E402

SPLIT = ROOT / "work" / "matching" / "split"
OBJDUMP = ROOT / "work" / "matching-tools" / "binutils" / "powerpc-eabi-objdump"


def disassemble(code: bytes, base: int, relocs, objdump: Path = OBJDUMP) -> list[str]:
    with tempfile.NamedTemporaryFile(suffix=".bin") as handle:
        handle.write(code)
        handle.flush()
        out = subprocess.run(
            [
                str(objdump),
                "-D",
                "-b",
                "binary",
                "-m",
                "powerpc:common64",
                "-EB",
                f"--adjust-vma={base:#x}",
                handle.name,
            ],
            capture_output=True,
            text=True,
            check=True,
        ).stdout
    by_offset = {}
    for reloc in relocs:
        by_offset.setdefault(reloc.offset & ~3, []).append(reloc)
    lines = []
    for line in out.splitlines():
        if ":\t" not in line:
            continue
        address_text, rest = line.split(":\t", 1)
        address = int(address_text.strip(), 16)
        words, _, text = rest.partition("\t")
        note = ""
        for reloc in by_offset.get(address - base, []):
            note += f"   ; {reloc.kind_name} {reloc.symbol}"
        lines.append(f"{address:08X}  {words.replace(' ', '')}  {text.strip()}{note}")
    return lines


@lru_cache(maxsize=None)
def split_units():
    config = json.loads((SPLIT / "config.json").read_text())
    units = []
    for unit in config["units"]:
        name = unit["name"]
        if unit["code_size"] == 0:
            continue
        units.append(Path(unit["object"]))
    return units


@lru_cache(maxsize=None)
def coff(path: Path):
    return read_coff(path)


def find_function(name: str):
    """Locate a function in the split objects; returns (object path, bytes, relocs)."""
    symbols = {entry[0]: entry for entry in load_symbols()}
    entry = symbols.get(name)
    if entry is None:
        raise SystemExit(f"unknown symbol {name}")
    _, _, address, size = entry
    # Prefer the auto unit whose start address is the closest at or below.
    candidates = []
    for path in split_units():
        stem = path.stem
        if stem.startswith("auto_") and "_text" in stem:
            start = int(stem.split("_")[2], 16)
            if start <= address:
                candidates.append((start, path))
    candidates.sort(reverse=True)
    ordered = [p for _, p in candidates] + [
        p for p in split_units() if not p.stem.startswith("auto_")
    ]
    for path in ordered:
        try:
            data, relocs = coff(path).function(name, size)
        except KeyError:
            continue
        return path, address, data, relocs
    raise SystemExit(f"{name} not found in split objects")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("names", nargs="+")
    args = parser.parse_args()
    symbols = load_symbols()
    by_addr = {entry[2]: entry[0] for entry in symbols if entry[1] == ".text"}
    for raw in args.names:
        name = raw
        if raw.lower().startswith("0x"):
            name = by_addr.get(int(raw, 16))
            if name is None:
                raise SystemExit(f"no .text symbol at {raw}")
        path, address, data, relocs = find_function(name)
        print(f"; {name} @ {address:08X} size {len(data):#x} ({path.name})")
        for line in disassemble(data, address, relocs):
            print(line)
        print()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
