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

SEH funclets: for a function with `__try`/`__except`, MSVC emits the filter
(and `__finally`) funclets inside the parent's symbol, right after its body,
and gives each its own .pdata entry; the 8 bytes before the parent hold the
handler and scope-table addresses. The split target has one function symbol
per .pdata entry. When the candidate's .pdata splits its symbol into several
ranges, each range is compared with the target function at the same distance
from the parent (parent first, then every funclet), and the scope table
(.xdata) is compared with the target's `except_data_*` record, read from the
original image. All of them must match.

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


def renameable_cxx(c_sym: str, t_sym: str) -> bool:
    """A decorated C++ name that may replace a placeholder: a compiler vtable
    (`??_7Class@@6B@`, or `6B<base>@@@` for a secondary vtable) for a `lbl_`
    target, or a member/free function (not a `??_` special name and not static
    data, whose encoding after `@@` starts with 2 or 3) for a `fn_` target."""
    if c_sym.startswith("??_7") and "@@6B" in c_sym:
        return t_sym.startswith("lbl_")
    if c_sym.startswith("?") and not c_sym.startswith("??_") and "@@" in c_sym:
        return c_sym.split("@@", 1)[1][:1] not in ("2", "3") and t_sym.startswith("fn_")
    return False

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


def target_data(name: str) -> bytes | None:
    """Bytes of a data symbol (e.g. a compact `jumptable_*` in .rdata) from the split objects."""
    from fn_asm import SPLIT, coff

    entry = next((e for e in load_symbols() if e[0] == name), None)
    if entry is None or not entry[3]:
        return None
    for path in sorted(SPLIT.rglob("*.obj")):
        try:
            unit = coff(path)
        except Exception:
            continue
        for symbol in unit.symbols:
            if symbol.name == name and symbol.section > 0:
                data = unit.sections[symbol.section - 1].data
                return data[symbol.value : symbol.value + entry[3]]
    return None


def candidate_data(obj, name: str, size: int) -> bytes | None:
    for symbol in obj.symbols:
        if symbol.name == name and symbol.section > 0:
            section = obj.sections[symbol.section - 1]
            if any(symbol.value <= r.offset < symbol.value + size for r in section.relocs):
                return None  # a table with relocations is not a compact offset table
            return section.data[symbol.value : symbol.value + size]
    return None


def pdata_ranges(obj, name: str) -> list[tuple[int, int]]:
    """[(offset, size)] of the .pdata entries inside the function symbol `name`, sorted. An
    entry is (begin address, flags) with the length in instructions in flags bits 8..29; its
    relocation is against the function symbol (the data word holds the offset) or a label."""
    base, section = obj.symbol_offset(name), obj.symbol_section(name)
    code, _ = obj.function(name)
    out = set()
    for sec in obj.sections:
        if not sec.name.startswith(".pdata"):
            continue
        for r in sec.relocs:
            if r.offset % 8 or r.offset + 8 > len(sec.data):
                continue
            start = obj.symbol_offset(r.symbol, base, base + len(code), section)
            if start is None:
                continue
            start += int.from_bytes(sec.data[r.offset : r.offset + 4], "big") - base
            words = (int.from_bytes(sec.data[r.offset + 4 : r.offset + 8], "big") >> 8) & 0x3FFFFF
            if 0 <= start and start + 4 * words <= len(code):
                out.add((start, 4 * words))
    return sorted(out)


def candidate_seh(obj, name: str):
    """(handler symbol, scopes) of an SEH function: the two words before it point to the
    language handler and to the scope table {count, count x (try begin, try end, filter,
    target)}. Each scope is a 4-tuple of function-relative offsets, or ("const", word) for an
    entry without a relocation (a constant filter). None when the function has no such data."""
    base, section = obj.symbol_offset(name), obj.symbol_section(name)
    if base is None or base < 8:
        return None
    text = obj.sections[section - 1]
    code, _ = obj.function(name)
    by_off = {r.offset: r for r in text.relocs}
    handler, table = by_off.get(base - 8), by_off.get(base - 4)
    if handler is None or table is None:
        return None
    sym = next((x for x in obj.symbols if x.name == table.symbol and x.section > 0), None)
    if sym is None:
        return None
    xsec = obj.sections[sym.section - 1]
    xrel = {r.offset: r for r in xsec.relocs}
    word = lambda off: int.from_bytes(xsec.data[off : off + 4], "big")
    start = sym.value + int.from_bytes(text.data[base - 4 : base], "big")
    scopes = []
    for i in range(word(start)):
        entry = []
        for j in range(4):
            off = start + 4 + 16 * i + 4 * j
            r = xrel.get(off)
            where = obj.symbol_offset(r.symbol, base, base + len(code) + 1, section) if r else None
            entry.append(("const", word(off)) if where is None else where - base + word(off))
        scopes.append(tuple(entry))
    return handler.symbol, scopes


def image_seh(image: bytes, image_base: int, address: int, extent: int):
    """(handler address, scopes) of the original SEH function at `address` (its code and
    funclets span `extent` bytes), in the form candidate_seh returns."""
    word = lambda a: int.from_bytes(image[a - image_base : a - image_base + 4], "big")
    handler, table = word(address - 8), word(address - 4)
    scopes = []
    for i in range(word(table)):
        entry = [word(table + 4 + 16 * i + 4 * j) for j in range(4)]
        scopes.append(tuple(v - address if address <= v <= address + extent else ("const", v) for v in entry))
    return handler, scopes


def check_seh(obj, name: str, address: int, extent: int, symbols) -> tuple[str | None, str]:
    """Compare the candidate's SEH handler and scope table with the original image.
    Returns (problem or None, note)."""
    record = next((n for n, sec, a, _ in symbols if a == address - 8 and n.startswith("except_data")), None)
    cand = candidate_seh(obj, name)
    if record is None or cand is None:
        return (f"SEH data: candidate {'has' if cand else 'lacks'} handler data, "
                f"target {'has' if record else 'lacks'} an except_data record at {address - 8:08X}"), ""
    import fn_equiv
    world = fn_equiv.load_world()
    handler, scopes = image_seh(world.image, world.base, address, extent)
    names = {n for n, sec, a, _ in symbols if a == handler and sec == ".text"}
    if cand[0] not in names:
        return f"SEH handler: candidate {cand[0]}, target {'/'.join(sorted(names)) or hex(handler)}", ""
    if cand[1] != scopes:
        return f"SEH scope table differs: candidate {cand[1]}, target {scopes}", ""
    return None, f"handler {cand[0]}, {len(scopes)} scope(s) equal to {record}"


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
        full_code, full_relocs = obj.function(actual_name)
        sym_base = obj.symbol_offset(actual_name)
        _path, parent_address, t_code, _relocs = find_function(target_name)
        # SEH funclets: the candidate's .pdata splits its symbol into parent + funclets
        pieces = pdata_ranges(obj, actual_name)
        if len(pieces) < 2 or pieces[0] != (0, len(t_code)) or \
                any(a + n != b for (a, n), (b, _) in zip(pieces, pieces[1:])):
            pieces = [(0, None)]
        targets = [target_name]
        for off, _n in pieces[1:]:
            name = by_addr.get(parent_address + off)
            if name is None:
                print(f"FAIL {cand_name}: funclet at +{off:#x}, but no target function at {parent_address + off:08X}")
                failures += 1
                break
            targets.append(name)
        if len(targets) != len(pieces):
            continue
        def check_piece() -> bool:
            nonlocal failures
            label = cand_name if not piece_off else f"{cand_name}+{piece_off:#x} (funclet)"
            _path, address, t_code, t_relocs = find_function(target_name)
            size = len(t_code)
            if piece_len is None:
                c_code, c_relocs = full_code, full_relocs
            else:
                c_code = full_code[piece_off : piece_off + piece_len]
                c_relocs = [type(r)(r.offset - piece_off, r.symbol, r.kind) for r in full_relocs
                            if piece_off <= r.offset < piece_off + piece_len]
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
                c_base = sym_base
                for r in c_relocs:
                    t_sym = t_by[(r.offset, r.kind)]
                    c_sym = r.symbol
                    if c_sym.startswith(LOCAL_LABEL_PREFIX):
                        c_off = (obj.symbol_offset(c_sym, c_base, c_base + len(full_code),
                                                   obj.symbol_section(actual_name))
                                 if c_base is not None else None)
                        t_addr = text_address.get(t_sym)
                        if t_addr is None and t_sym.startswith(LOCAL_LABEL_PREFIX):
                            # Jeff names case-block labels `$LN<address>`.
                            try:
                                t_addr = int(t_sym[len(LOCAL_LABEL_PREFIX):], 16)
                            except ValueError:
                                t_addr = None
                        if c_off is None or c_base is None or t_addr is None:
                            problems.append(f"reloc +{r.offset:#x}: cannot resolve label {c_sym} / {t_sym}")
                        elif c_off - c_base != t_addr - parent_address:
                            problems.append(
                                f"reloc +{r.offset:#x}: label {c_sym} at function+{c_off - c_base:#x}, "
                                f"target {t_sym} at function+{t_addr - parent_address:#x}"
                            )
                        continue
                    if t_sym == c_sym:
                        continue
                    # Aliases at one address, e.g. __savegprlr / __savegprlr_14.
                    if c_sym in text_address and text_address.get(t_sym) == text_address[c_sym]:
                        continue
                    if c_sym.startswith("$T") and t_sym.startswith(("jumptable_", "lbl_")):
                        # Compact (8/16-bit offset) switch table emitted as a local
                        # data symbol: accept it when its bytes equal the target's.
                        t_data = target_data(t_sym)
                        c_data = candidate_data(obj, c_sym, len(t_data)) if t_data else None
                        if t_data and c_data == t_data:
                            continue
                        problems.append(f"reloc +{r.offset:#x}: table {c_sym} differs from {t_sym}")
                        continue
                    if c_sym.startswith("__real@"):
                        # Float/double literal: accept it when the target label
                        # holds the same bytes (the literal's name encodes them).
                        try:
                            want = bytes.fromhex(c_sym[len("__real@"):])
                        except ValueError:
                            want = b""
                        t_data = target_data(t_sym) if want else None
                        if t_data and t_data[:len(want)] == want:
                            continue
                    if renameable_cxx(c_sym, t_sym) and c_sym not in known_names:
                        # C++ vtable (??_7) or member function: same rename rule as a C name.
                        prev = local_renames.get(t_sym) or renames.get(t_sym)
                        if prev and prev != c_sym:
                            problems.append(f"{t_sym} named both {prev} and {c_sym}")
                        local_renames[t_sym] = c_sym
                    elif c_sym.startswith("?") or c_sym.startswith("__real@") or c_sym.startswith("$"):
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
                print(f"FAIL {label} vs {target_name} @ {address:08X}: " + "; ".join(problems))
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
                print(f"MATCH {label} vs {target_name} @ {address:08X} size {size:#x}")
            return not problems

        mapping_failed = False
        for (piece_off, piece_len), target_name in zip(pieces, targets):
            if not check_piece():
                mapping_failed = True
        if len(pieces) > 1 and not mapping_failed:
            problem, note = check_seh(obj, actual_name, parent_address, pieces[-1][0] + pieces[-1][1], symbols)
            if problem:
                failures += 1
                print(f"FAIL {cand_name}: {problem}")
            else:
                print(f"SEH {cand_name}: {note}")
    for old, new in sorted(renames.items()):
        print(f"RENAME {old} -> {new}")
    if not failures:
        shutil.rmtree(obj_path.parent, ignore_errors=True)
    return 1 if failures else 0


if __name__ == "__main__":
    raise SystemExit(main())
