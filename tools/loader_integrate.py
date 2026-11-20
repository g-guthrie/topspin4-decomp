#!/usr/bin/env python3
"""Register verified Loader_DLL units from spec files.

Usage: python3 tools/loader_integrate.py work/specs/L*/*.json

Each spec has the same shape as the Swing specs used by integrate_match.py:
  {"source": "src/loader/x.c", "flags": [], "functions": {"ts4l_name": "0x83..."}}

Sizes come from a fresh Loader analysis (work/loader/analysis/symbols.txt,
written by tools/loader_matching.py --fresh-analysis), and .pdata entries from
the split's pdata objects. The script appends seed symbols, split blocks and
units.json entries, and refuses duplicate sources, names, or overlapping
ranges. Run tools/loader_matching.py --fresh-analysis --record afterwards; it
is the authority on whether the result is exact.
"""

from __future__ import annotations

import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from xcoff import ROOT, read_coff  # noqa: E402

CONFIG = ROOT / "config" / "54540859" / "loader"
WORK = ROOT / "work" / "loader"
LINE = re.compile(r"^(\S+) = (\.?\w+):0x([0-9A-Fa-f]+);(.*)$")
FUNCTION_ALIGNMENT = 8


def analysis_functions() -> dict[int, tuple[str, int]]:
    path = WORK / "analysis" / "symbols.txt"
    if not path.is_file():
        raise SystemExit("run tools/loader_matching.py --fresh-analysis first")
    out = {}
    for line in path.read_text().splitlines():
        m = LINE.match(line)
        if m and m.group(2) == ".text" and "type:function" in line:
            size = re.search(r"size:0x([0-9A-Fa-f]+)", line)
            if size:
                out[int(m.group(3), 16)] = (m.group(1), int(size.group(1), 16))
    return out


def pdata_map(names: dict[str, int]) -> dict[int, int]:
    out = {}
    for path in (WORK / "split" / "obj").glob("auto_*_pdata.obj"):
        base = int(path.stem.split("_")[2], 16)
        for section in read_coff(path).sections:
            if section.name != ".pdata":
                continue
            for reloc in section.relocs:
                if reloc.offset % 8 == 0 and reloc.symbol in names:
                    out[names[reloc.symbol]] = base + reloc.offset
    return out


def existing_ranges(splits: str) -> list[tuple[int, int]]:
    return [(int(a, 16), int(b, 16)) for a, b in
            re.findall(r"^\s+\.text\s+start:0x([0-9A-F]+) end:0x([0-9A-F]+)", splits, re.M)]


def main() -> int:
    specs = [json.loads(Path(p).read_text()) for p in sys.argv[1:]]
    if not specs:
        raise SystemExit(__doc__)
    functions = analysis_functions()
    starts = sorted(functions)
    following = dict(zip(starts, starts[1:]))
    names = {name: addr for addr, (name, _size) in functions.items()}
    pdata = pdata_map(names)
    units_doc = json.loads((CONFIG / "units.json").read_text())
    configured = {u["source"] for u in units_doc["units"]}
    seed_path, splits_path = CONFIG / "symbols.seed.txt", CONFIG / "splits.txt"
    seed = seed_path.read_text()
    seed_names = {m.group(1) for m in map(LINE.match, seed.splitlines()) if m}
    splits = splits_path.read_text()
    ranges = existing_ranges(splits)
    new_seed, blocks = [], []
    for spec in specs:
        source = spec["source"]
        if source in configured:
            raise SystemExit(f"{source} is already configured")
        if not (ROOT / source).is_file():
            raise SystemExit(f"missing {source}")
        text, pd, sizes = [], [], {}
        for name, addr_text in spec["functions"].items():
            addr = int(addr_text, 16)
            if addr not in functions:
                raise SystemExit(f"{name}: no function at {addr_text}")
            if name in seed_names:
                raise SystemExit(f"{name}: name already used")
            size = functions[addr][1]
            end = addr + size
            if following.get(addr) and 0 < following[addr] - end < FUNCTION_ALIGNMENT:
                end = following[addr]
            for a, b in ranges:
                if a < end and addr < b:
                    raise SystemExit(f"{name} overlaps an existing split {a:#x}-{b:#x}")
            text.append((addr, end))
            if addr in pdata:
                pd.append((pdata[addr], pdata[addr] + 8))
            sizes[name] = size
            new_seed.append(f"{name} = .text:0x{addr:08X}; // type:function size:0x{size:X}")
            seed_names.add(name)
        merged = []
        for a, b in sorted(text):
            if merged and merged[-1][1] == a:
                merged[-1] = (merged[-1][0], b)
            else:
                merged.append((a, b))
        pmerged = []
        for a, b in sorted(pd):
            if pmerged and pmerged[-1][1] == a:
                pmerged[-1] = (pmerged[-1][0], b)
            else:
                pmerged.append((a, b))
        ranges += merged
        block = [f"{source}:"]
        block += [f"\t.pdata      start:0x{a:08X} end:0x{b:08X}" for a, b in pmerged]
        block += [f"\t.text       start:0x{a:08X} end:0x{b:08X}" for a, b in merged]
        blocks.append("\n".join(block))
        units_doc["units"].append({"source": source, "flags": spec.get("flags", []), "symbols": sizes})
        configured.add(source)
    seed_path.write_text(seed.rstrip("\n") + "\n" + "\n".join(new_seed) + "\n")
    splits_path.write_text(splits.rstrip("\n") + "\n\n" + "\n\n".join(blocks) + "\n")
    (CONFIG / "units.json").write_text(json.dumps(units_doc, indent=2) + "\n")
    print(f"Integrated {len(specs)} Loader unit(s), {sum(len(s['functions']) for s in specs)} function(s)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
