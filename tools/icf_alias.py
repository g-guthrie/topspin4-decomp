#!/usr/bin/env python3
"""Reviewed symbol aliases: a second source-level name for one address of the original image.

Usage:
  python3 tools/icf_alias.py            # list the aliases
  python3 tools/icf_alias.py --check    # validate config/54540859/icf_aliases.json against symbols.txt

Two things make one address carry two source names:

- "icf": the original linker folded identical functions or identical read-only data
  (/OPT:ICF), so the image calls one address where the source named two functions, or
  loads one vtable address where the source named two classes. The compiler only emits
  the original code when the source still has two distinct symbols (with one name it
  merges the calls, or reuses one `lis` for both loads).
- "cxx": the function is a C++ member (symbols.txt holds its decorated name), and
  reconstructed C sources have to call it under an identifier C can spell.

config/54540859/icf_aliases.json lists every alias, each with the address it stands for
and the evidence:

  {"aliases": [{"alias": "ts4_x_881A2570_icf_b", "canonical": "ts4_x_881A2570",
                "address": "0x881A2570", "kind": "icf", "evidence": "..."}]}

The address decides; "canonical" is the symbols.txt name at that address when the entry
was reviewed (--check and tools/integrate_match.py keep it current). A relocation of a
candidate to `alias` is equal to a relocation of the target to the symbol at `address`
(same offset from it), and to nothing else: the comparison of the code bytes is not
touched, and an alias never matches another address.

Users:
- tools/fn_check.py and tools/fn_check_ltcg.py (and so tools/ltcg_route.py) accept the
  alias in the relocation comparison;
- tools/matching.py calls patch_rebuilt() after the plain compiles: in each rebuilt
  object an undefined external named `alias` is given the canonical name (or its
  relocations are moved to the canonical symbol the object already has), so objdiff,
  which compares relocation targets by name, sees what the original linker produced;
- tools/fix_refs.py writes the "cxx" alias where a rename would put a decorated name into
  a source that references the function as a C identifier;
- tools/integrate_match.py records the "aliases" of a spec and follows renames.

An alias must not be a symbols.txt name and must not be defined by a matching unit's
object (only references are renamed).
"""

from __future__ import annotations

import json
import re
import struct
import sys
from dataclasses import dataclass
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from xcoff import ROOT, load_symbols  # noqa: E402

ALIASES_PATH = ROOT / "config" / "54540859" / "icf_aliases.json"
KINDS = ("icf", "cxx")
C_IDENTIFIER = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


@dataclass(frozen=True)
class Alias:
    alias: str
    canonical: str
    address: int
    kind: str
    evidence: str


def load(path: Path | None = None) -> list[Alias]:
    path = ALIASES_PATH if path is None else path
    if not Path(path).is_file():
        return []
    out = []
    for item in json.loads(Path(path).read_text()).get("aliases", []):
        out.append(Alias(item["alias"], item.get("canonical", ""), int(str(item["address"]), 16),
                         item.get("kind", "icf"), item.get("evidence", "")))
    return out


def save(entries: list[Alias], path: Path | None = None) -> None:
    path = ALIASES_PATH if path is None else path
    body = {"aliases": [{"alias": e.alias, "canonical": e.canonical, "address": f"0x{e.address:08X}",
                         "kind": e.kind, "evidence": e.evidence} for e in entries]}
    Path(path).write_text(json.dumps(body, indent=1) + "\n")


def problems(entries: list[Alias], symbols: list) -> list[str]:
    """What is wrong with the entries, given symbols.txt rows (name, section, address, size)."""
    names = {e[0] for e in symbols}
    at = {}
    for name, _section, address, _size in symbols:
        at.setdefault(address, []).append(name)
    out, seen = [], set()
    for e in entries:
        if e.alias in seen:
            out.append(f"{e.alias}: listed twice")
        seen.add(e.alias)
        if e.kind not in KINDS:
            out.append(f"{e.alias}: kind {e.kind!r} is not one of {'/'.join(KINDS)}")
        if not e.evidence.strip():
            out.append(f"{e.alias}: no evidence")
        if not C_IDENTIFIER.match(e.alias):
            out.append(f"{e.alias}: an alias is a C identifier")
        if e.alias in names:
            out.append(f"{e.alias}: is a symbols.txt name (an alias is a second name)")
        here = at.get(e.address)
        if not here:
            out.append(f"{e.alias}: no symbol at {e.address:#010x}")
        elif e.canonical not in here:
            out.append(f"{e.alias}: canonical {e.canonical} is not the name at {e.address:#010x} "
                       f"({', '.join(here)})")
        if e.kind == "cxx" and C_IDENTIFIER.match(e.canonical):
            out.append(f"{e.alias}: kind cxx, but {e.canonical} is not a decorated name")
    return out


STALE_PLACEHOLDER = re.compile(r"^(?:fn|lbl|jumptable)_([0-9A-Fa-f]{8})$")


def placeholder_address(name: str) -> int | None:
    """The address a generated placeholder name (fn_/lbl_/jumptable_ + 8 hex digits) encodes.
    A source written against an older split can still use the placeholder of a symbol that has
    a real name now; the name itself says which address it means."""
    match = STALE_PLACEHOLDER.match(name)
    return int(match.group(1), 16) if match else None


class AliasMap:
    """alias name -> address, for the relocation comparison of the checkers."""

    def __init__(self, entries: list[Alias] | None = None):
        self.entries = load() if entries is None else entries
        self.by_alias = {e.alias: e for e in self.entries}

    def __bool__(self) -> bool:
        return bool(self.by_alias)

    def __contains__(self, name: str) -> bool:
        return name in self.by_alias

    def address(self, name: str) -> int | None:
        entry = self.by_alias.get(name)
        return entry.address if entry else None

    def same(self, candidate_name: str, target_address: int | None) -> bool:
        """A candidate relocation to `candidate_name` against a target relocation whose symbol
        is at `target_address`: equal only for an alias of exactly that address."""
        entry = self.by_alias.get(candidate_name)
        return entry is not None and target_address is not None and entry.address == target_address

    def names(self, symbols: list) -> dict[str, str]:
        """alias -> the name `symbols` (symbols.txt rows) has at the alias's address."""
        at = {}
        for name, _section, address, _size in symbols:
            at.setdefault(address, name)
        return {e.alias: at[e.address] for e in self.entries if e.address in at}

    def c_name(self, canonical: str) -> str | None:
        """The "cxx" alias that C sources use for a decorated name."""
        for e in self.entries:
            if e.kind == "cxx" and e.canonical == canonical:
                return e.alias
        return None


# --------------------------------------------------------------------------- COFF objects

def _symbol_entries(data: bytes):
    """(index, entry offset, name, section number, storage class) of each symbol, aux skipped."""
    _machine, _nsec, _stamp, symoff, nsym, _opt, _chars = struct.unpack_from("<HHIIIHH", data, 0)
    strings = symoff + 18 * nsym
    index = 0
    while index < nsym:
        entry = symoff + 18 * index
        raw = bytes(data[entry : entry + 8])
        if raw[:4] == b"\0\0\0\0":
            start = strings + struct.unpack_from("<I", raw, 4)[0]
            name = bytes(data[start : data.index(b"\0", start)]).decode("latin-1")
        else:
            name = raw.rstrip(b"\0").decode("latin-1")
        section, _type, storage, aux = struct.unpack_from("<hHBB", data, entry + 12)
        yield index, entry, name, section, storage
        index += 1 + aux


def _relocation_slots(data: bytes):
    """File offset of the symbol-index field of every relocation."""
    _machine, nsec, _stamp, _symoff, _nsym, optional, _chars = struct.unpack_from("<HHIIIHH", data, 0)
    for index in range(nsec):
        _name, _vs, _va, _size, _ptr, relptr, _ln, nrel, _nln, characteristics = struct.unpack_from(
            "<8sIIIIIIHHI", data, 20 + optional + 40 * index)
        first = 0
        if characteristics & 0x01000000 and nrel == 0xFFFF:
            nrel, first = struct.unpack_from("<I", data, relptr)[0], 1
        for r in range(first, nrel):
            yield relptr + r * 10 + 4


def rename_references(data: bytes, mapping: dict[str, str]) -> tuple[bytes, list[str]]:
    """Give the undefined externals of a COFF object named in `mapping` their mapped name.

    When the object already has a symbol of the mapped name, the relocations against the
    alias are moved to that symbol (one symbol per name, as the linker would see it);
    otherwise the alias's symbol entry is renamed. A *defined* symbol with an alias name is
    an error: an alias is a second name for something defined elsewhere. Returns the new
    bytes and the aliases found.
    """
    if not mapping:
        return data, []
    entries = list(_symbol_entries(data))
    hits = [e for e in entries if e[2] in mapping]
    if not hits:
        return data, []
    out = bytearray(data)
    _machine, _nsec, _stamp, symoff, nsym, _opt, _chars = struct.unpack_from("<HHIIIHH", data, 0)
    strings = symoff + 18 * nsym
    table_size = struct.unpack_from("<I", data, strings)[0]
    by_name = {}
    for index, _entry, name, section, storage in entries:
        if storage == 2 and name not in mapping:
            by_name.setdefault(name, index)
    move, found = {}, []
    for index, entry, name, section, storage in hits:
        if section != 0 or storage != 2:
            raise SystemExit(f"alias {name} is defined in the object: an alias may only be referenced")
        found.append(name)
        new = mapping[name]
        if new in by_name:
            move[index] = by_name[new]
            continue
        by_name[new] = index
        encoded = new.encode("latin-1")
        if len(encoded) <= 8:
            out[entry : entry + 8] = encoded.ljust(8, b"\0")
        else:
            if strings + table_size != len(out):
                raise SystemExit("string table is not at the end of the object")
            struct.pack_into("<II", out, entry, 0, table_size)
            out += encoded + b"\0"
            table_size += len(encoded) + 1
            struct.pack_into("<I", out, strings, table_size)
    if move:
        for slot in _relocation_slots(data):
            index = struct.unpack_from("<I", out, slot)[0]
            if index in move:
                struct.pack_into("<I", out, slot, move[index])
    return bytes(out), found


def patch_rebuilt(objects, symbols_txt: Path, path: Path | None = None) -> dict[str, list[str]]:
    """tools/matching.py hook: apply the aliases to the compiled objects. Returns
    {object path: aliases renamed}. Stops when the alias file is invalid."""
    entries = load(path)
    if not entries:
        return {}
    symbols = load_symbols(symbols_txt)
    bad = problems(entries, symbols)
    if bad:
        raise SystemExit("config/54540859/icf_aliases.json:\n  " + "\n  ".join(bad))
    mapping = AliasMap(entries).names(symbols)
    needles = [name.encode("latin-1") for name in mapping]
    done = {}
    for obj in objects:
        obj = Path(obj)
        data = obj.read_bytes()
        if not any(n in data for n in needles):
            continue
        new, found = rename_references(data, mapping)
        if found:
            obj.write_bytes(new)
            done[str(obj)] = found
            print(f"alias: {obj.name}: " + ", ".join(f"{a} -> {mapping[a]}" for a in found))
    return done


# --------------------------------------------------------------------------- integration

def register(spec_aliases: dict, path: Path | None = None) -> list[Alias]:
    """tools/integrate_match.py hook: record the "aliases" of a spec:
    {alias: {"canonical": name, "address": "0x...", "kind": "icf"|"cxx", "evidence": "..."}}.
    An identical entry that is already there is kept; a different one under the same alias
    is an error."""
    entries = load(path)
    by_alias = {e.alias: e for e in entries}
    added = []
    for alias, item in spec_aliases.items():
        new = Alias(alias, item["canonical"], int(str(item["address"]), 16), item.get("kind", "icf"),
                    item.get("evidence", ""))
        old = by_alias.get(alias)
        if old is not None:
            if (old.address, old.kind) != (new.address, new.kind):
                raise SystemExit(f"alias {alias} already stands for {old.address:#010x} ({old.kind})")
            continue
        entries.append(new)
        by_alias[alias] = new
        added.append(new)
    if added:
        save(entries, path)
    return added


def follow_renames(renames: dict[str, str], path: Path | None = None) -> int:
    """tools/integrate_match.py hook: keep "canonical" current after symbols.txt renames."""
    entries = load(path)
    changed = [e for e in entries if e.canonical in renames and renames[e.canonical] != e.canonical]
    if changed:
        save([Alias(e.alias, renames.get(e.canonical, e.canonical), e.address, e.kind, e.evidence)
              for e in entries], path)
    return len(changed)


def main() -> int:
    entries = load()
    if "--check" in sys.argv[1:]:
        bad = problems(entries, load_symbols(ROOT / "config" / "54540859" / "symbols.txt"))
        for line in bad:
            print(line)
        print(f"{len(entries)} alias(es), {len(bad)} problem(s)")
        return 1 if bad else 0
    for e in entries:
        print(f"{e.alias} = {e.canonical} @ {e.address:#010x} ({e.kind}): {e.evidence}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
