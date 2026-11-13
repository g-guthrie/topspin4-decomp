#!/usr/bin/env python3
"""Refresh committed progress metadata from a verified tools/matching.py run.

Usage: python3 tools/sync_progress.py [--new-names N]

Reads work/matching/objdiff-project/report.json (which tools/matching.py has
already verified), then rewrites config/54540859/match.json, the counters in
config/progress.json, the public reports/54540859/report.json, and the
status sentence in README.md and docs/matching-build.md.
"""

from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from matching import MATCHING_UNITS  # noqa: E402
from xcoff import ROOT, load_symbols, read_coff  # noqa: E402

REPORT = ROOT / "work" / "matching" / "objdiff-project" / "report.json"
MATCH = ROOT / "config" / "54540859" / "match.json"
PROGRESS = ROOT / "config" / "progress.json"
PUBLIC = ROOT / "reports" / "54540859" / "report.json"
SPLITS = ROOT / "config" / "54540859" / "splits.txt"

ONES = "zero one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen".split()
TENS = "_ _ twenty thirty forty fifty sixty seventy eighty ninety".split()


def words(n: int) -> str:
    if n < 20:
        return ONES[n]
    if n < 100:
        return TENS[n // 10] + ("" if n % 10 == 0 else "-" + ONES[n % 10])
    if n < 1000:
        rest = n % 100
        return ONES[n // 100] + " hundred" + ("" if rest == 0 else " " + words(rest))
    rest = n % 1000
    return words(n // 1000) + " thousand" + ("" if rest == 0 else " " + words(rest))


def cap(text: str) -> str:
    return text[0].upper() + text[1:]


def pdata_ranges() -> dict[str, list[tuple[int, int]]]:
    out: dict[str, list[tuple[int, int]]] = {}
    current = None
    for line in SPLITS.read_text().splitlines():
        if line.endswith(":") and not line.startswith(("\t", " ")):
            current = line[:-1]
            continue
        match = re.match(r"^\s+\.pdata\s+start:0x([0-9A-F]+) end:0x([0-9A-F]+)", line)
        if match and current:
            out.setdefault(current, []).append((int(match.group(1), 16), int(match.group(2), 16)))
    return out


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--new-names", type=int, default=None,
                        help="reviewed names added this batch (default: new matched functions)")
    args = parser.parse_args()

    report = json.loads(REPORT.read_text())
    measures = report["measures"]
    match = json.loads(MATCH.read_text())
    progress = json.loads(PROGRESS.read_text())
    previous_functions = progress["matching_functions"]

    symbols = {name: (addr, size) for name, _sec, addr, size in load_symbols()}
    pdata_by_source = pdata_ranges()
    entries = []
    flag_exceptions = {}
    for unit in MATCHING_UNITS:
        source = unit["source"]
        if unit.get("extra_flags"):
            flag_exceptions[source] = unit["extra_flags"]
        pdata = sorted(pdata_by_source.get(source, []))
        for name, size in unit["symbols"].items():
            address, _ = symbols[name]
            entry = {
                "source": source,
                "symbol": name,
                "text_range": f"0x{address:08X}-0x{address + size:08X}",
            }
            # Paired with a .pdata entry below when the unit split one for it.
            if pdata:
                entry["pdata_range"] = None
            entry["matched_code_bytes"] = size
            entry["function_match_percent"] = 100.0
            entries.append(entry)
    # Pair .pdata entries with functions through the split unit's relocations.
    split_obj = ROOT / "work" / "matching" / "split" / "obj"
    for source, ranges in pdata_by_source.items():
        ranges = sorted(ranges)
        offsets = []
        for start, end in ranges:
            offsets.extend(range(start, end, 8))
        owner = {}
        obj_path = split_obj / (source.rsplit(".", 1)[0] + ".obj")
        if obj_path.is_file():
            for section in read_coff(obj_path).sections:
                if section.name == ".pdata":
                    for reloc in section.relocs:
                        if reloc.offset % 8 == 0 and reloc.offset // 8 < len(offsets):
                            owner[reloc.symbol] = offsets[reloc.offset // 8]
        for entry in entries:
            if entry["source"] == source and entry["symbol"] in owner:
                start = owner[entry["symbol"]]
                entry["pdata_range"] = f"0x{start:08X}-0x{start + 8:08X}"
    old_symbols = {m["symbol"] for m in match["matches"]}
    added = [e for e in entries if e["symbol"] not in old_symbols]

    functions = len(entries)
    code = sum(e["matched_code_bytes"] for e in entries)
    if functions != measures["matched_functions"] or str(code) != measures["matched_code"]:
        raise SystemExit("report measures differ from MATCHING_UNITS; rerun tools/matching.py")

    # Edit match.json textually so existing entries keep their layout.
    text = MATCH.read_text()
    if added:
        close = text.index("\n  ],\n", text.index('"matches": ['))
        body = "".join(",\n    " + json.dumps(e, separators=(",", ":")) for e in added)
        text = text[:close] + body + text[close:]
    flags_json = json.dumps(flag_exceptions, indent=2).replace("\n", "\n  ")
    text = re.sub(
        r'"compiler_flag_exceptions": \{.*?\n  \}',
        lambda _m: '"compiler_flag_exceptions": ' + flags_json,
        text,
        count=1,
        flags=re.S,
    )
    scalars = {
        "matched_code_bytes": code,
        "module_matched_code_percent": measures["matched_code_percent"],
        "module_total_functions": measures["total_functions"],
        "module_matched_functions": functions,
        "module_matched_functions_percent": measures["matched_functions_percent"],
        "module_total_units": measures["total_units"],
        "module_complete_units": measures["complete_units"],
    }
    for key, value in scalars.items():
        text = re.sub(rf'^  "{key}": [^,\n]+', f'  "{key}": {json.dumps(value)}', text, flags=re.M)
    text = re.sub(r"verifies all [a-z -]+ functions", f"verifies all {words(functions)} functions", text)
    json.loads(text)
    MATCH.write_text(text)

    new_names = args.new_names if args.new_names is not None else functions - previous_functions
    progress["named_functions"] += new_names
    for key in ("semantic_drafts", "reconstructed_functions", "validated_functions", "matching_functions"):
        progress[key] = functions
    progress["matching_bytes"] = code
    progress["matching_code_percent"] = measures["matched_code_percent"]
    progress["matching_functions_percent"] = measures["matched_functions_percent"]
    PROGRESS.write_text(json.dumps(progress, indent=2) + "\n")

    public = json.loads(REPORT.read_text())
    for unit in public["units"]:
        unit["functions"] = [
            f for f in unit.get("functions", []) if f.get("fuzzy_match_percent") == 100.0
        ]
    PUBLIC.write_text(json.dumps(public, separators=(",", ":")) + "\n")

    readme = ROOT / "README.md"
    text = readme.read_text()
    text = re.sub(
        r"[A-Z][a-z -]+ functions have reviewed names\. [A-Z][a-z -]+ reconstructed functions now compile to 100% code matches: [\d,]+ of [\d,]+ measured Swing code bytes \(`[\d.]+%`\)",
        f"{cap(words(progress['named_functions']))} functions have reviewed names. "
        f"{cap(words(functions))} reconstructed functions now compile to 100% code matches: "
        f"{code:,} of {int(measures['total_code']):,} measured Swing code bytes "
        f"(`{measures['matched_code_percent']:.8f}%`)",
        text,
    )
    readme.write_text(text)

    doc = ROOT / "docs" / "matching-build.md"
    text = doc.read_text()
    units = len(MATCHING_UNITS)
    text = re.sub(
        r"^The first [a-z -]+ matching measurement units reproduce all [\d,]+ code bytes across [a-z -]+ functions exactly\.",
        f"The first {words(units)} matching measurement units reproduce all {code:,} code bytes across {words(functions)} functions exactly.",
        text,
        flags=re.M,
    )
    text = re.sub(
        r"The match is [\d,]+ of [\d,]+ Swing code bytes \(`[\d.]+%`\) and [a-z -]+ of [\d,]+ objdiff functions \(`[\d.]+%`\)\. The decomp-framework report has [a-z -]+ complete-source units among [\d,]+ total units\.",
        f"The match is {code:,} of {int(measures['total_code']):,} Swing code bytes "
        f"(`{measures['matched_code_percent']:.8f}%`) and {words(functions)} of "
        f"{measures['total_functions']:,} objdiff functions "
        f"(`{measures['matched_functions_percent']:.7f}%`). The decomp-framework report has "
        f"{words(measures['complete_units'])} complete-source units among "
        f"{measures['total_units']} total units.",
        text,
    )
    doc.write_text(text)
    print(f"Synced metadata: {functions} functions, {code} bytes, {units} units")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
