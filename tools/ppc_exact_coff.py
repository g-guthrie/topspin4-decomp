#!/usr/bin/env python3
"""PPC COFF/flat-PE parsing and exact relocation normalization.

Derived from the project's independently reviewed verify_cursor_smoke.py
(SHA-256 c27a83db5e8a3be118bea10b64253fde144c81126c1b394a9b3bd9e6999bcf8a).
Unknown relocation kinds and malformed pairs fail closed. No game data is embedded.
"""
from __future__ import annotations
import hashlib
import re
import struct
from pathlib import Path

def sha(path: Path) -> str:
    h=hashlib.sha256()
    with Path(path).open("rb") as f:
        for chunk in iter(lambda:f.read(1<<20),b""):
            h.update(chunk)
    return h.hexdigest()

def ck(ok: bool, reason: str) -> None:
    if not ok:
        raise ValueError(reason)


def u32(b: bytes, off: int) -> int:
    return struct.unpack_from(">I", b, off)[0]


def sext(v: int, bits: int) -> int:
    v &= (1 << bits) - 1
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


def s32(v: int) -> int:
    return sext(v, 32)


def coff(p: Path) -> dict:
    d = p.read_bytes()
    machine, nsec, _, sp, nsym, opt, _ = struct.unpack_from("<HHIIIHH", d)
    ck(machine == 0x1F2 and opt == 0, f"unexpected COFF header {p}")
    st = sp + nsym * 18
    def name(raw: bytes) -> str:
        if raw[:4] == b"\0" * 4:
            o = struct.unpack_from("<I", raw, 4)[0]
            return d[st + o:d.index(b"\0", st + o)].decode("latin1")
        return raw.rstrip(b"\0").decode("latin1")
    sections = []
    for k in range(nsec):
        o = 20 + k * 40
        rawname, _, _, size, ptr, rp, _, nr, _, _ = struct.unpack_from("<8sIIIIIIHHI", d, o)
        rel = [struct.unpack_from("<IIH", d, rp + i * 10) for i in range(nr)]
        sections.append({"name": name(rawname), "data": d[ptr:ptr + size] if ptr else b"", "rel": rel})
    symbols = {}
    i = 0
    while i < nsym:
        o = sp + i * 18
        raw, value, sec, typ, storage, aux = struct.unpack_from("<8sIhHBB", d, o)
        symbols[i] = {"name": name(raw), "value": value, "section": sec, "type": typ, "storage": storage}
        i += 1 + aux
    return {"sections": sections, "symbols": symbols, "sha256": sha(p)}


def text_extent(c: dict, symbol: str, size: int, target: bool) -> tuple[bytes, int, list]:
    defs = [s for s in c["symbols"].values() if s["name"] == symbol and s["section"] > 0 and s["storage"] == 2 and s["type"] & 0x20]
    ck(len(defs) == 1, f"{symbol}: not exactly one external function definition")
    s = defs[0]; sec = c["sections"][s["section"] - 1]
    ck(sec["name"] == ".text", f"{symbol}: function outside .text")
    begin = s["value"]
    next_def = min((x["value"] for x in c["symbols"].values() if x["section"] == s["section"] and x["storage"] == 2 and x["type"] & 0x20 and x["value"] > begin), default=len(sec["data"]))
    ck(next_def - begin == size, f"{symbol}: COFF function extent is not {size}")
    if target:
        ck(begin == 0 and len(sec["data"]) == size, "target is not a full one-function split")
    rel = [(off - begin, idx, typ) for off, idx, typ in sec["rel"] if begin <= off < begin + size]
    ck(all(0 <= off < size and off % 4 == 0 for off, _, _ in rel), "unaligned/out-of-range relocation")
    return sec["data"][begin:begin + size], begin, rel


def pe_read(flat: bytes, addr: int, size: int) -> bytes:
    po = struct.unpack_from("<I", flat, 0x3C)[0]
    ck(flat[po:po + 4] == b"PE\0\0", "flat image is not PE")
    n, osz = struct.unpack_from("<H", flat, po + 6)[0], struct.unpack_from("<H", flat, po + 20)[0]
    opt = po + 24; base = struct.unpack_from("<I", flat, opt + 28)[0]
    ck(base == 0x88000000, "unexpected image base")
    rva = addr - base
    ck(any((lambda v, a, z: a <= rva and rva + size <= a + v)(*struct.unpack_from("<III", flat, opt + osz + k * 40 + 8)) for k in range(n)), "extent outside PE sections")
    return flat[rva:rva + size]  # retained T02 image is flat: file offset == RVA


def symbols_index(p: Path) -> tuple[dict, list]:
    names, starts = {}, []
    for line in p.read_text(encoding="utf-8").splitlines():
        m = re.match(r"^(\S+) = \.([A-Za-z0-9_]+):0x([0-9A-Fa-f]+);(.*)$", line)
        if m:
            name, sec, addr, tail = m.groups(); names[name] = int(addr, 16)
            if sec == "text" and "type:function" in tail:
                z = re.search(r"size:0x([0-9A-Fa-f]+)", tail)
                starts.append((int(addr, 16), int(z.group(1), 16) if z else None, name))
    return names, starts


def normalize(code: bytes, section_offset: int, raw: list, syms: dict, byname: dict, address: int, target: bool) -> tuple[list, bytes, list]:
    """Normalize all raw relocation records; fail closed on an unknown kind."""
    events, pairs, mask = [], [], bytearray(code)
    active = {}
    i = 0
    while i < len(raw):
        off, idx, typ = raw[i]
        name = syms[idx]["name"] if typ != 18 else None
        if typ == 18:
            raise ValueError(f"orphan PAIR +{off:X}")
        ck(name in byname, f"unresolved relocation name {name}")
        symva = byname[name]
        w = u32(code, off)
        if typ in (6, 7):
            field_mask, bits, opcode = (0x03FFFFFC, 26, 18) if typ == 6 else (0xFFFC, 16, 16)
            ck(w >> 26 == opcode, f"relocation +{off:X} on non-branch")
            field = sext(w & field_mask, bits)
            aa, lk = (w >> 1) & 1, w & 1
            add = s32(((field if aa else address + off + field) & 0xFFFFFFFF) - symva) if target else (field if aa else field + section_offset + off)
            events.append({"kind": f"REL{24 if typ == 6 else 14}", "offset": off, "symbol_va": symva, "addend": add, "aa": aa, "lk": lk})
            struct.pack_into(">I", mask, off, w & ~field_mask)
        elif typ == 2:
            add = s32(w - symva) if target else s32(w)
            events.append({"kind": "ADDR32", "offset": off, "symbol_va": symva, "addend": add})
            mask[off:off + 4] = b"\0" * 4
        elif typ == 16:
            ck(i + 1 < len(raw) and raw[i + 1][0] == off and raw[i + 1][2] == 18, f"REFHI +{off:X} missing PAIR")
            pair = raw[i + 1][1]
            ck((pair == idx) if target else True, f"target REFHI PAIR +{off:X} not symbol index")
            e = {"kind": "REFHI", "offset": off, "symbol_va": symva, "addends": [], "lows": []}
            events.append(e); active[name] = (e, w & 0xFFFF, pair)
            pairs.append({"offset": off, "kind": "REFHI", "symbol_index": idx, "pair_raw": pair})
            mask[off + 2:off + 4] = b"\0\0"
            i += 1
        elif typ == 17:
            ck(name in active, f"standalone REFLO +{off:X}")
            e, hi, pair_hi = active[name]
            low = sext(w & 0xFFFF, 16)
            if i + 1 < len(raw) and raw[i + 1][0] == off and raw[i + 1][2] == 18:
                pair = raw[i + 1][1]
                ck(pair == (idx if target else 0), f"REFLO PAIR convention +{off:X}")
                pairs.append({"offset": off, "kind": "REFLO", "symbol_index": idx, "pair_raw": pair})
                i += 1
            elif not target:
                raise ValueError(f"rebuilt REFLO +{off:X} lacks expected PAIR")
            add = s32((hi << 16) + low - symva) if target else low
            if not target:
                ck(add == s32((hi << 16) + sext(pair_hi, 16)), f"rebuilt REFHI/REFLO addend disagreement +{off:X}")
            e["lows"].append(off); e["addends"].append(add)
            mask[off + 2:off + 4] = b"\0\0"
        else:
            raise ValueError(f"unsupported relocation kind {typ} +{off:X}")
        i += 1
    ck(all(e["lows"] for e in events if e["kind"] == "REFHI"), "REFHI lacks REFLO")
    return events, bytes(mask), pairs
