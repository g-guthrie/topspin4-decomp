#!/usr/bin/env python3
"""Register verified candidate units in the canonical matching configuration.

Usage: python3 tools/integrate_match.py spec.json [spec.json ...]

Each spec is JSON:
  {
    "source": "src/xbox360/example.c",
    "flags": ["/GS-"],                         # optional extra cl flags
    "functions": {"ts4_name": "0x88170328"},   # defined symbol -> original address
    "renames": {"fn_88171960": "ts4_callee"}  # optional placeholder renames
  }

The script updates symbols.txt, symbols.seed.txt, splits.txt, objects.json and
the MATCHING_UNITS table in tools/matching.py. It refuses conflicting names,
duplicate sources, or ranges that are already split. Run tools/matching.py
afterwards; it is the authority on whether the result is an exact match.
"""

from __future__ import annotations

import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from xcoff import ROOT, read_coff  # noqa: E402

CONFIG = ROOT / "config" / "54540859"
SYMBOLS = CONFIG / "symbols.txt"
SEED = CONFIG / "symbols.seed.txt"
SPLITS = CONFIG / "splits.txt"
OBJECTS = CONFIG / "objects.json"
MATCHING = ROOT / "tools" / "matching.py"
SPLIT_DIR = ROOT / "work" / "matching" / "split"
PLACEHOLDER = re.compile(r"^(fn|lbl|jumptable)_[0-9A-Fa-f]+$")
LINE = re.compile(r"^(\S+) = (\.?\w+):0x([0-9A-Fa-f]+);(.*)$")


def pdata_map() -> dict[int, int]:
    """Map function start address -> .pdata entry address using the split objects."""
    symbols = {}
    for line in SYMBOLS.read_text().splitlines():
        match = LINE.match(line)
        if match:
            symbols[match.group(1)] = int(match.group(3), 16)
    out = {}
    for path in (SPLIT_DIR / "obj").glob("auto_*_pdata.obj"):
        base = int(path.stem.split("_")[2], 16)
        coff = read_coff(path)
        for section in coff.sections:
            if section.name != ".pdata":
                continue
            for reloc in section.relocs:
                if reloc.offset % 8 == 0 and reloc.symbol in symbols:
                    out[symbols[reloc.symbol]] = base + reloc.offset
    return out


def split_ranges() -> list[tuple[int, int]]:
    ranges = []
    for line in SPLITS.read_text().splitlines():
        match = re.match(r"^\s+\.text\s+start:0x([0-9A-F]+) end:0x([0-9A-F]+)", line)
        if match:
            ranges.append((int(match.group(1), 16), int(match.group(2), 16)))
    return ranges


def main() -> int:
    specs = [json.loads(Path(p).read_text()) for p in sys.argv[1:]]
    if not specs:
        raise SystemExit(__doc__)

    lines = SYMBOLS.read_text().splitlines()
    by_name: dict[str, int] = {}
    by_addr_text: dict[int, int] = {}
    for index, line in enumerate(lines):
        match = LINE.match(line)
        if not match:
            continue
        by_name[match.group(1)] = index
        if match.group(2) == ".text" and "type:function" in line:
            by_addr_text[int(match.group(3), 16)] = index

    seed_lines = SEED.read_text().splitlines()
    seed_names = {LINE.match(l).group(1) for l in seed_lines if LINE.match(l)}
    objects = json.loads(OBJECTS.read_text())
    configured = objects["swing"]["objects"]
    existing = split_ranges()
    pdata = pdata_map()

    def rename(index: int, new: str) -> str:
        match = LINE.match(lines[index])
        old = match.group(1)
        if old == new:
            return lines[index]
        if new in by_name and by_name[new] != index:
            raise SystemExit(f"name {new} already used for a different symbol")
        if not PLACEHOLDER.match(old):
            raise SystemExit(f"refusing to rename reviewed symbol {old} to {new}")
        lines[index] = f"{new} = {match.group(2)}:0x{match.group(3)}{';'}{match.group(4)}"
        del by_name[old]
        by_name[new] = index
        return lines[index]

    split_blocks = []
    matching_entries = []
    new_seed = []
    for spec in specs:
        source = spec["source"]
        if source in configured:
            raise SystemExit(f"{source} is already configured")
        if not (ROOT / source).is_file():
            raise SystemExit(f"missing {source}")
        text_ranges = []
        pdata_ranges = []
        symbol_sizes = {}
        for name, address_text in spec["functions"].items():
            address = int(address_text, 16)
            index = by_addr_text.get(address)
            if index is None:
                raise SystemExit(f"no function symbol at {address_text}")
            size_match = re.search(r"size:0x([0-9A-Fa-f]+)", lines[index])
            size = int(size_match.group(1), 16)
            for start, end in existing:
                if start < address + size and address < end:
                    raise SystemExit(f"{name} overlaps an existing split {start:#x}-{end:#x}")
            line = rename(index, name)
            if name not in seed_names:
                new_seed.append(line.split(" // ")[0].rstrip() + f" // type:function size:{size:#X}".replace("0X", "0x"))
                seed_names.add(name)
            text_ranges.append((address, address + size))
            if address in pdata:
                pdata_ranges.append((pdata[address], pdata[address] + 8))
            symbol_sizes[name] = size
        for old, new in spec.get("renames", {}).items():
            if old not in by_name:
                if new in by_name:
                    continue  # already renamed by an earlier spec
                raise SystemExit(f"unknown symbol {old}")
            line = rename(by_name[old], new)
            if new not in seed_names:
                new_seed.append(line)
                seed_names.add(new)
        text_ranges.sort()
        merged = []
        for start, end in text_ranges:
            if merged and merged[-1][1] == start:
                merged[-1] = (merged[-1][0], end)
            else:
                merged.append((start, end))
        existing.extend(merged)
        block = [f"{source}:"]
        for start, end in sorted(pdata_ranges):
            block.append(f"\t.pdata      start:0x{start:08X} end:0x{end:08X}")
        for start, end in merged:
            block.append(f"\t.text       start:0x{start:08X} end:0x{end:08X}")
        split_blocks.append("\n".join(block))
        configured[source] = {
            "status": "Matching",
            "source": source.removeprefix("src/"),
        }
        entry = [
            "    {",
            f'        "source": "{source}",',
            f'        "object": "{Path(source).stem}.obj",',
        ]
        if spec.get("flags"):
            entry.append(f'        "extra_flags": {json.dumps(spec["flags"])},')
        if len(symbol_sizes) == 1:
            (name, size), = symbol_sizes.items()
            entry.append(f'        "symbols": {{"{name}": {size}}},')
        else:
            entry.append('        "symbols": {')
            for name, size in symbol_sizes.items():
                entry.append(f'            "{name}": {size},')
            entry.append("        },")
        entry.append("    },")
        matching_entries.append("\n".join(entry))

    SYMBOLS.write_text("\n".join(lines) + "\n")
    if new_seed:
        SEED.write_text("\n".join(seed_lines + new_seed) + "\n")
    SPLITS.write_text(SPLITS.read_text().rstrip("\n") + "\n\n" + "\n\n".join(split_blocks) + "\n")
    OBJECTS.write_text(json.dumps(objects, indent=2) + "\n")
    text = MATCHING.read_text()
    marker = "\n)\n\n\ndef sha256"
    if marker not in text:
        raise SystemExit("cannot find the end of MATCHING_UNITS")
    text = text.replace(marker, "\n" + "\n".join(matching_entries) + marker, 1)
    MATCHING.write_text(text)
    print(f"Integrated {len(specs)} unit(s), {sum(len(s['functions']) for s in specs)} function(s)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
