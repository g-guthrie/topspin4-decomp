#!/usr/bin/env python3
"""Run the forced all-units Xbox link probe and record it.

Usage: python3 tools/link_probe.py --wrapper WIBO --linker-dir X360/16.00.10224.00
                                   [--work-dir work/matching] [--write]

Links every source-built object from a verified tools/matching.py run with
/FORCE:UNRESOLVED, measures the result, and with --write updates
config/link-status.json, the probe paragraph in docs/matching-build.md, and
the expected values in tests/test_canonical_build.py. Requires a wibo build
that can run link.exe (decompals/wibo PR 110, see docs/matching-build.md).
"""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import struct
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from matching import MATCHING_UNITS  # noqa: E402
from sync_progress import words  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]


def text_size(image: bytes) -> int:
    pe = struct.unpack_from("<I", image, 0x3C)[0]
    count = struct.unpack_from("<H", image, pe + 6)[0]
    optional = struct.unpack_from("<H", image, pe + 20)[0]
    for index in range(count):
        offset = pe + 24 + optional + 40 * index
        if image[offset : offset + 8].rstrip(b"\0") == b".text":
            return struct.unpack_from("<I", image, offset + 8)[0]
    raise SystemExit("no .text section in probe output")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--wrapper", type=Path, required=True)
    parser.add_argument("--linker-dir", type=Path, required=True)
    parser.add_argument("--work-dir", type=Path, default=ROOT / "work" / "matching")
    parser.add_argument("--write", action="store_true")
    args = parser.parse_args()

    out_dir = ROOT / "work" / "link"
    out_dir.mkdir(parents=True, exist_ok=True)
    dll, mapfile = out_dir / "all.dll", out_dir / "all.map"
    for path in (dll, mapfile):
        path.unlink(missing_ok=True)
    objects = [args.work_dir / "rebuilt" / unit["object"] for unit in MATCHING_UNITS]
    missing = [str(o) for o in objects if not o.is_file()]
    if missing:
        raise SystemExit(f"missing rebuilt objects (run tools/matching.py): {missing[:3]}")
    flags = ["/nologo", "/dll", "/noentry", "/nodefaultlib", "/machine:PPCBE",
             "/subsystem:XBOX", "/XEX:NO", "/OPT:NOREF", "/FORCE:UNRESOLVED"]
    result = subprocess.run(
        [str(args.wrapper), str(args.linker_dir / "link.exe"), *flags,
         f"/MAP:{mapfile}", f"/out:{dll}", *map(str, objects)],
        capture_output=True, text=True, cwd=ROOT,
    )
    if not dll.is_file():
        sys.stdout.write(result.stdout + result.stderr)
        raise SystemExit("link probe produced no image")
    lines = (result.stdout + result.stderr).splitlines()
    refs = [l for l in lines if "LNK2019" in l or "LNK2001" in l]
    unresolved = {re.search(r"unresolved external symbol (\S+)", l).group(1) for l in refs}
    text = mapfile.read_text(errors="replace").split("Publics by Value", 1)[1]
    publics, _, statics = text.partition("Static symbols")
    code_rows = lambda block: [l.split() for l in block.splitlines()
                               if len(l.split()) > 3 and l.split()[0].startswith("0003:")]
    public_names = {row[1] for row in code_rows(publics)}
    symbols = {s: z for u in MATCHING_UNITS for s, z in u["symbols"].items()}
    image = dll.read_bytes()
    stats = {
        "input_source_objects": len(objects),
        "input_matching_functions": len(symbols),
        "input_matching_code_bytes": sum(symbols.values()),
        "output_size_bytes": len(image),
        "output_sha256": hashlib.sha256(image).hexdigest(),
        "output_text_bytes": text_size(image),
        "map_matching_public_functions": len(set(symbols) & public_names),
        "map_additional_static_helpers": len(code_rows(statics)),
        "unresolved_external_symbols": len(unresolved),
        "unresolved_external_references": len(refs),
    }
    print(json.dumps(stats, indent=2))
    if stats["map_matching_public_functions"] != stats["input_matching_functions"]:
        raise SystemExit("not every matching function reached the link map")
    if not args.write:
        return 0

    status_path = ROOT / "config" / "link-status.json"
    status = json.loads(status_path.read_text())
    forced = status["forced_all_units_probe"]
    forced.update(stats)
    forced["note"] = (
        "The linker emitted a PE only because FORCE:UNRESOLVED was explicit. Its text "
        f"includes all {stats['input_matching_functions']:,} exact public functions plus "
        "source helper code (including inline C++ constructors and operator new wrappers) "
        "and alignment, so total text size is not a matching-progress counter. Output "
        "hashes include link timestamps and differ between runs."
    )
    status_path.write_text(json.dumps(status, indent=2) + "\n")

    doc = ROOT / "docs" / "matching-build.md"
    body = doc.read_text()
    start = body.index("A second probe passes all")
    end = body.index("This is evidence that the current reconstructed subset")
    body = body[:start] + (
        f"A second probe passes all {words(stats['input_source_objects'])} source-built objects "
        "to the linker. Its map\ncontains all "
        f"{words(stats['input_matching_functions'])} exact public functions. Because the "
        "remaining game code and\ndata are not reconstructed, this probe requires "
        "`/FORCE:UNRESOLVED` and reports\n"
        f"{stats['unresolved_external_symbols']:,} unique unresolved external symbols across "
        f"{stats['unresolved_external_references']:,} references. The linker emits a "
        f"{stats['output_size_bytes']:,}-byte\ninspection PE with "
        f"{stats['output_text_bytes']:,} bytes of `.text`; that section also includes "
        f"{words(stats['map_additional_static_helpers'])}\nsource helper functions (inline C++ "
        "constructors and allocation wrappers) and alignment, so it is not a new "
        "matching-progress\ndenominator. Linker outputs embed timestamps, so their hashes "
        "change between runs. Reproduce with `tools/link_probe.py`. "
    ) + body[end:]
    doc.write_text(body)

    test = ROOT / "tests" / "test_canonical_build.py"
    source = test.read_text()
    for key in ("input_source_objects", "input_matching_functions",
                "map_matching_public_functions", "map_additional_static_helpers",
                "unresolved_external_symbols", "unresolved_external_references"):
        source = re.sub(rf'(forced\["{key}"\], )\d+', rf"\g<1>{stats[key]}", source)
    test.write_text(source)
    print("Recorded link probe")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
