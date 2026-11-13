#!/usr/bin/env python3
"""Compile a candidate source with the Xbox 360 compiler and compare functions.

Usage:
  python3 tools/fn_check.py path/to/candidate.c ts4_name=fn_88170328 [...]
  python3 tools/fn_check.py candidate.cpp ts4_name=0x88170328 --flags /GS-

Each mapping pairs a function defined by the candidate (left) with the
original function (right, a symbols.txt name or address). The comparison masks
relocation fields, then checks relocation offsets, kinds, and targets.

Switch jump tables: MSVC embeds the table in .text and emits one ADDR32
relocation per word against a local `$LN<n>` label (the REFHI/REFLO pair that
loads the table address also targets such a label). The split target has the
same relocations against its own code labels. A candidate reloc to a `$LN`
label is accepted when the label sits at the same offset inside the function
as the address the target reloc points to; every other relocation stays
strict.

Exit status 0 means every function matches except, at most, relocation target
names that integration can fix by renaming placeholder symbols (fn_/lbl_/...)
in config/54540859/symbols.txt. Those renames are printed as RENAME lines.

Compiles in a private directory so several checks may run concurrently.
Requires a completed tools/matching.py run and work/matching-tools.
"""

from __future__ import annotations

import argparse
import os
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from fn_asm import disassemble, find_function  # noqa: E402
from xcoff import ROOT, demangle_base, load_symbols, read_coff  # noqa: E402

TOOLS = ROOT / "work" / "matching-tools"
WIBO = TOOLS / "work_wibo"
CL = TOOLS / "compilers" / "X360" / "16.00.10224.00" / "cl.exe"
BASE_FLAGS = ["/nologo", "/c", "/O2", "/Oi"]
PLACEHOLDER_PREFIXES = ("fn_", "lbl_", "jumptable_", "@", "$")
LOCAL_LABEL_PREFIX = "$LN"  # MSVC code labels (switch case blocks, jump table start)

MASKS = {
    0x2: 0xFFFFFFFF,  # ADDR32
    0x3: 0x03FFFFFC,  # ADDR24
    0x4: 0x0000FFFF,  # ADDR16
    0x6: 0x03FFFFFC,  # REL24
    0x7: 0x0000FFFC,  # REL14
    0x10: 0x0000FFFF,  # REFHI
    0x11: 0x0000FFFF,  # REFLO
    0x13: 0x0000FFFF,  # SECRELLO
    0xA: 0xFFFFFFFF,  # SECREL
}


def compile_candidate(source: Path, flags: list[str]) -> Path:
    workdir = Path(tempfile.mkdtemp(prefix="fncheck-", dir=ROOT / "work"))
    local = workdir / source.name
    shutil.copyfile(source, local)
    includes = []
    for directory in {source.resolve().parent, ROOT / "src" / "xbox360"}:
        includes.append("/I" + os.path.relpath(directory, workdir))
    env = dict(os.environ, TMP=str(workdir), TEMP=str(workdir))
    result = subprocess.run(
        [str(WIBO), str(CL), *BASE_FLAGS, *flags, *includes, local.name],
        cwd=workdir,
        env=env,
        capture_output=True,
        text=True,
    )
    obj = workdir / (local.stem + ".obj")
    if result.returncode != 0 or not obj.is_file():
        sys.stdout.write(result.stdout + result.stderr)
        raise SystemExit("compile failed")
    warnings = [l for l in (result.stdout + result.stderr).splitlines() if "warning" in l]
    for line in warnings:
        print("  " + line.strip())
    return obj


def masked_words(code: bytes, relocs) -> list[int]:
    words = [int.from_bytes(code[i : i + 4], "big") for i in range(0, len(code), 4)]
    for reloc in relocs:
        mask = MASKS.get(reloc.kind, 0xFFFFFFFF)
        if reloc.kind in (0x4, 0x10, 0x11, 0x13) and reloc.offset % 4 == 2:
            index = reloc.offset // 4
        else:
            index = reloc.offset // 4
        if index < len(words):
            words[index] &= ~mask & 0xFFFFFFFF
    return words


def main() -> int:
    parser = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter
    )
    parser.add_argument("source", type=Path)
    parser.add_argument("mappings", nargs="+", help="candidate_name=target_name_or_0xaddr")
    parser.add_argument("--flags", nargs="*", default=[], help="extra cl flags, e.g. /GS-")
    parser.add_argument("--quiet", action="store_true", help="omit listings for matches")
    args = parser.parse_args()

    symbols = load_symbols()
    by_addr = {entry[2]: entry[0] for entry in symbols if entry[1] == ".text"}
    known_names = {entry[0] for entry in symbols}
    text_address = {entry[0]: entry[2] for entry in symbols if entry[1] == ".text"}

    obj_path = compile_candidate(args.source, args.flags)
    obj = read_coff(obj_path)
    defined = obj.function_names()

    failures = 0
    renames: dict[str, str] = {}
    for mapping in args.mappings:
        cand_name, _, target = mapping.partition("=")
        if target.lower().startswith("0x"):
            target_name = by_addr.get(int(target, 16))
            if target_name is None:
                raise SystemExit(f"no .text symbol at {target}")
        else:
            target_name = target
        candidates = [n for n in defined if n == cand_name or demangle_base(n) == cand_name]
        if not candidates:
            print(f"FAIL {cand_name}: not defined in compiled object (have: {', '.join(defined)})")
            failures += 1
            continue
        actual_name = candidates[0]
        _path, address, t_code, t_relocs = find_function(target_name)
        size = len(t_code)
        c_code, c_relocs = obj.function(actual_name)
        # Compiler pads functions to 8 bytes in some sections; compare target size.
        c_code_trim = c_code[:size]
        c_relocs = [r for r in c_relocs if r.offset < size]
        problems = []
        if len(c_code) < size or any(c_code[size:].strip(b"\0")):
            if len(c_code) != size:
                problems.append(f"size {len(c_code):#x} != target {size:#x}")
        tw = masked_words(t_code, t_relocs)
        cw = masked_words(c_code_trim, c_relocs)
        diff_words = [i for i in range(max(len(tw), len(cw))) if (tw[i] if i < len(tw) else None) != (cw[i] if i < len(cw) else None)]
        if diff_words:
            problems.append(f"{len(diff_words)} differing instruction(s), first at +{diff_words[0]*4:#x}")
        t_rel = sorted((r.offset, r.kind) for r in t_relocs)
        c_rel = sorted((r.offset, r.kind) for r in c_relocs)
        if t_rel != c_rel:
            problems.append(f"relocation layout differs (target {len(t_rel)}, candidate {len(c_rel)})")
        local_renames = {}
        if not problems:
            t_by = {(r.offset, r.kind): r.symbol for r in t_relocs}
            c_base = obj.symbol_offset(actual_name)
            for r in c_relocs:
                t_sym = t_by[(r.offset, r.kind)]
                c_sym = r.symbol
                if c_sym.startswith(LOCAL_LABEL_PREFIX):
                    c_off = obj.symbol_offset(c_sym)
                    t_addr = text_address.get(t_sym)
                    if c_off is None or c_base is None or t_addr is None:
                        problems.append(f"reloc +{r.offset:#x}: cannot resolve label {c_sym} / {t_sym}")
                    elif c_off - c_base != t_addr - address:
                        problems.append(
                            f"reloc +{r.offset:#x}: label {c_sym} at function+{c_off - c_base:#x}, "
                            f"target {t_sym} at function+{t_addr - address:#x}"
                        )
                    continue
                if t_sym == c_sym:
                    continue
                if c_sym.startswith("?") or c_sym.startswith("__real@") or c_sym.startswith("$"):
                    problems.append(f"reloc +{r.offset:#x}: candidate uses {c_sym}, target {t_sym}")
                elif t_sym.startswith(PLACEHOLDER_PREFIXES) and (c_sym not in known_names):
                    prev = local_renames.get(t_sym) or renames.get(t_sym)
                    if prev and prev != c_sym:
                        problems.append(f"{t_sym} named both {prev} and {c_sym}")
                    local_renames[t_sym] = c_sym
                else:
                    problems.append(f"reloc +{r.offset:#x}: candidate {c_sym} vs target {t_sym}")
        if problems:
            failures += 1
            print(f"FAIL {cand_name} vs {target_name} @ {address:08X}: " + "; ".join(problems))
            t_lines = disassemble(t_code, address, t_relocs)
            c_lines = disassemble(c_code, address, c_relocs)
            width = max((len(l) for l in t_lines), default=0)
            print(f"  {'TARGET'.ljust(width)}   CANDIDATE")
            for i in range(max(len(t_lines), len(c_lines))):
                left = t_lines[i] if i < len(t_lines) else ""
                right = c_lines[i][10:] if i < len(c_lines) else ""
                mark = "*" if i in diff_words else " "
                print(f"{mark} {left.ljust(width)} | {right}")
        else:
            renames.update(local_renames)
            print(f"MATCH {cand_name} vs {target_name} @ {address:08X} size {size:#x}")
            if not args.quiet:
                pass
    for old, new in sorted(renames.items()):
        print(f"RENAME {old} -> {new}")
    if not failures:
        shutil.rmtree(obj_path.parent, ignore_errors=True)
    return 1 if failures else 0


if __name__ == "__main__":
    raise SystemExit(main())
