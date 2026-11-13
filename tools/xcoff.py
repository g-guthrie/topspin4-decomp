#!/usr/bin/env python3
"""Minimal reader for Xbox 360 PowerPC COFF objects (standard library only)."""

from __future__ import annotations

import os
import re
import struct
from dataclasses import dataclass, field
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SYMBOLS_TXT = ROOT / "config" / "54540859" / "symbols.txt"


def matching_dir() -> Path | None:
    """Alternate matching work dir (TS4_MATCHING_DIR), e.g. work/matching-jt.

    When set, fn_asm/fn_check read the split objects and symbols that
    tools/matching.py produced in that directory instead of the committed
    config/54540859/symbols.txt and work/matching.
    """
    value = os.environ.get("TS4_MATCHING_DIR")
    return Path(value).expanduser().absolute() if value else None

# IMAGE_REL_PPC_* names for the relocation types emitted by the Xbox compiler.
RELOC_NAMES = {
    0x0: "ABSOLUTE",
    0x2: "ADDR32",
    0x3: "ADDR24",
    0x4: "ADDR16",
    0x6: "REL24",
    0x7: "REL14",
    0xA: "SECREL",
    0xB: "SECTION",
    0x10: "REFHI",
    0x11: "REFLO",
    0x12: "PAIR",
    0x13: "SECRELLO",
    0x15: "GPREL",
    0x16: "TOKEN",
}


@dataclass
class Reloc:
    offset: int
    symbol: str
    kind: int

    @property
    def kind_name(self) -> str:
        return RELOC_NAMES.get(self.kind, hex(self.kind))


@dataclass
class Section:
    index: int
    name: str
    data: bytes
    relocs: list[Reloc] = field(default_factory=list)


@dataclass
class Symbol:
    name: str
    value: int
    section: int
    storage: int


@dataclass
class Coff:
    sections: list[Section]
    symbols: list[Symbol]

    def function(self, name: str, size: int | None = None) -> tuple[bytes, list[Reloc]]:
        """Return the bytes and section-relative relocations of a function symbol."""
        for symbol in self.symbols:
            if symbol.name != name or symbol.section <= 0:
                continue
            section = self.sections[symbol.section - 1]
            if size is None:
                later = sorted(
                    s.value
                    for s in self.symbols
                    if s.section == symbol.section
                    and s.value > symbol.value
                    and s.storage in (2, 3)
                    and not s.name.startswith((".", "$"))
                )
                end = later[0] if later else len(section.data)
                size = end - symbol.value
            start = symbol.value
            data = section.data[start : start + size]
            relocs = [
                Reloc(r.offset - start, r.symbol, r.kind)
                for r in section.relocs
                if start <= r.offset < start + size and r.kind != 0x12
            ]
            return data, relocs
        raise KeyError(name)

    def symbol_offset(self, name: str) -> int | None:
        """Section-relative offset of a defined symbol (e.g. an MSVC `$LN` label)."""
        for symbol in self.symbols:
            if symbol.name == name and symbol.section > 0:
                return symbol.value
        return None

    def function_names(self) -> list[str]:
        return [
            s.name
            for s in self.symbols
            if s.section > 0
            and s.storage in (2, 3)
            and not s.name.startswith((".", "$"))
            and self.sections[s.section - 1].name.startswith(".text")
        ]


def read_coff(path: Path) -> Coff:
    data = Path(path).read_bytes()
    _machine, nsec, _stamp, symoff, nsym, optsize, _chars = struct.unpack_from(
        "<HHIIIHH", data, 0
    )
    strtab = symoff + nsym * 18

    def name_of(raw: bytes) -> str:
        if raw[:4] == b"\0\0\0\0":
            offset = struct.unpack_from("<I", raw, 4)[0]
            end = data.index(b"\0", strtab + offset)
            return data[strtab + offset : end].decode("latin-1")
        return raw.rstrip(b"\0").decode("latin-1")

    symbols_by_index: dict[int, Symbol] = {}
    symbols: list[Symbol] = []
    i = 0
    while i < nsym:
        raw = data[symoff + i * 18 : symoff + i * 18 + 18]
        value, section, _typ, storage, aux = struct.unpack_from("<IhHBB", raw, 8)
        symbol = Symbol(name_of(raw[:8]), value, section, storage)
        symbols_by_index[i] = symbol
        symbols.append(symbol)
        i += 1 + aux

    sections = []
    base = 20 + optsize
    for index in range(nsec):
        raw_name, _vs, _va, size, ptr, relptr, _ln, nrel, _nln, characteristics = struct.unpack_from(
            "<8sIIIIIIHHI", data, base + index * 40
        )
        if raw_name.startswith(b"/"):
            offset = int(raw_name[1:].rstrip(b"\0"))
            end = data.index(b"\0", strtab + offset)
            name = data[strtab + offset : end].decode("latin-1")
        else:
            name = raw_name.rstrip(b"\0").decode("latin-1")
        payload = data[ptr : ptr + size] if ptr else bytes(size)
        relocs = []
        first = 0
        if characteristics & 0x01000000 and nrel == 0xFFFF:
            # IMAGE_SCN_LNK_NRELOC_OVFL: the real count is stored in the first
            # relocation's VirtualAddress field, and that entry is not a relocation.
            nrel = struct.unpack_from("<I", data, relptr)[0]
            first = 1
        for r in range(first, nrel):
            offset, symindex, kind = struct.unpack_from("<IIH", data, relptr + r * 10)
            target = symbols_by_index.get(symindex)
            relocs.append(Reloc(offset, target.name if target else f"#{symindex}", kind))
        sections.append(Section(index + 1, name, payload, relocs))
    return Coff(sections, symbols)


SYMBOL_LINE = re.compile(r"^(?P<name>\S+) = (?P<section>\.?\w+):0x(?P<addr>[0-9A-Fa-f]+);")
SIZE_FIELD = re.compile(r"size:0x([0-9A-Fa-f]+)")


def load_symbols(path: Path | None = None) -> list[tuple[str, str, int, int | None]]:
    """Return (name, section, address, size) for every symbols.txt entry."""
    if path is None:
        alt = matching_dir()
        path = alt / "analysis" / "symbols.txt" if alt else SYMBOLS_TXT
    out = []
    for line in Path(path).read_text().splitlines():
        match = SYMBOL_LINE.match(line)
        if not match:
            continue
        size_match = SIZE_FIELD.search(line)
        size = size_match.group(1) if size_match else None
        out.append(
            (
                match.group("name"),
                match.group("section"),
                int(match.group("addr"), 16),
                int(size, 16) if size else None,
            )
        )
    return out


def demangle_base(name: str) -> str:
    """Reduce an MSVC-decorated or plain name to its identifier."""
    if name.startswith("?"):
        return name[1:].split("@", 1)[0]
    return name
