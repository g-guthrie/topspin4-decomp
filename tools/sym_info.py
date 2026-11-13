#!/usr/bin/env python3
"""Query the Jeff split of Swing_DLL for cross-references, strings, and data.

Usage:
  python3 tools/sym_info.py xrefs fn_8861C648      # who references a symbol
  python3 tools/sym_info.py str 0x880F8FE4         # C string at an address
  python3 tools/sym_info.py data 0x880F8FE4 0x40   # hex words with relocations
  python3 tools/sym_info.py at 0x8861C650          # symbol containing an address

The first query builds work/sym_index.pkl from work/matching/split (about two
minutes); later queries are fast. Delete the index after a re-split.
"""

from __future__ import annotations

import bisect
import json
import pickle
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from xcoff import ROOT, load_symbols, read_coff  # noqa: E402

SPLIT = ROOT / "work" / "matching" / "split"
INDEX = ROOT / "work" / "sym_index.pkl"


def unit_base(path: Path, coff) -> dict[int, int]:
    """Map section index -> virtual address for an auto split object."""
    parts = path.stem.split("_")
    if parts[0] != "auto":
        return {}
    start = int(parts[2], 16)
    return {s.index: start for s in coff.sections if s.data or s.relocs}


def build_index():
    symbols = load_symbols()
    named = sorted((addr, name, size or 0, section) for name, section, addr, size in symbols)
    config = json.loads((SPLIT / "config.json").read_text())
    xrefs: dict[str, list[tuple[int, str]]] = {}
    memory: list[tuple[int, bytes, list[tuple[int, str, int]]]] = []
    for unit in config["units"]:
        path = Path(unit["object"])
        if not path.stem.startswith("auto_"):
            continue
        coff = read_coff(path)
        base = int(path.stem.split("_")[2], 16)
        for section in coff.sections:
            if not section.data and not section.relocs:
                continue
            relocs = []
            for reloc in section.relocs:
                if reloc.kind == 0x12:
                    continue
                address = base + reloc.offset
                xrefs.setdefault(reloc.symbol, []).append((address, section.name))
                relocs.append((reloc.offset, reloc.symbol, reloc.kind))
            if not section.name.startswith(".text"):
                memory.append((base, section.data, relocs))
    memory.sort(key=lambda m: m[0])
    with INDEX.open("wb") as handle:
        pickle.dump({"named": named, "xrefs": xrefs, "memory": memory}, handle)


def load_index():
    if not INDEX.is_file():
        print("building index...", file=sys.stderr)
        build_index()
    with INDEX.open("rb") as handle:
        return pickle.load(handle)


def containing(index, address: int):
    named = index["named"]
    keys = [n[0] for n in named]
    i = bisect.bisect_right(keys, address) - 1
    while i >= 0:
        addr, name, size, section = named[i]
        if addr <= address < addr + max(size, 1) or size == 0:
            return name, addr, section
        i -= 1
        if address - addr > 0x100000:
            break
    return None, None, None


def read_memory(index, address: int, length: int):
    for base, data, relocs in index["memory"]:
        if base <= address < base + len(data):
            off = address - base
            return data[off : off + length], [
                (o - off, s, k) for o, s, k in relocs if off <= o < off + length
            ]
    return None, []


def main() -> int:
    if len(sys.argv) < 3:
        raise SystemExit(__doc__)
    command, arg = sys.argv[1], sys.argv[2]
    index = load_index()
    by_name = {n[1]: n for n in index["named"]}
    if command == "xrefs":
        refs = index["xrefs"].get(arg, [])
        print(f"{len(refs)} reference(s) to {arg}")
        for address, section in sorted(refs)[:200]:
            name, start, _ = containing(index, address)
            where = f"{name}+{address - start:#x}" if name else "?"
            print(f"  {address:08X} {section:8} in {where}")
        return 0
    address = int(arg, 16) if arg.lower().startswith("0x") else by_name[arg][0]
    if command == "at":
        name, start, section = containing(index, address)
        print(f"{address:08X} is in {name} ({section}) +{address - start:#x}" if name else "unknown")
    elif command == "str":
        data, _ = read_memory(index, address, 512)
        if data is None:
            raise SystemExit("address not in a split data object")
        text = data.split(b"\0", 1)[0]
        print(repr(text.decode("latin-1")))
    elif command == "data":
        length = int(sys.argv[3], 16) if len(sys.argv) > 3 else 0x40
        data, relocs = read_memory(index, address, length)
        if data is None:
            raise SystemExit("address not in a split data object")
        notes = {o: s for o, s, _ in relocs}
        for i in range(0, len(data), 4):
            word = data[i : i + 4]
            note = f"  -> {notes[i]}" if i in notes else ""
            printable = "".join(chr(b) if 32 <= b < 127 else "." for b in word)
            print(f"  {address + i:08X}  {word.hex()}  {printable}{note}")
    else:
        raise SystemExit(__doc__)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
