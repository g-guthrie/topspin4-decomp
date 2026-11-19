#!/usr/bin/env python3
"""Audit data references (REFHI/REFLO pairs) in matched Swing units.

objdiff masks relocated fields, so a source that names the wrong lbl_XXXXXXXX
or the wrong named global still reports MATCH. For every matched function in
tools/matching.py MATCHING_UNITS this reads the rebuilt object and, for each relocation:
  REFHI: full = S + lo, where lo is the field of the next REFLO on the same
         symbol (or the PAIR addend); expect ha(full) == the original lis imm.
  REFLO: expect (S + signext(field)) & 0xFFFF == the original low 16 bits.
S is the symbol address: full name in symbols.txt (any section), else an
8-hex suffix. Symbols that resolve to nothing (string literals $SG..., pooled
__real@/__xmm@ constants, runtime helpers) are counted as unresolved.
The original immediates come from the pickled disassembly
(default work/army/VX1/textdis.pkl). ADDR32 in data sections is not checked. LTCG units (ltcg_units.json) are
skipped: tools/ltcg_route.py writes their rebuilt object as the split target
object with verified code patched in, so its relocations name the original
symbols, and the route already fails on any rename.
Standard library only.

usage: python3 tools/audit_datarefs.py --build work/matching-b163 [--dis PKL] [--json OUT] [--verbose]
"""
import argparse, collections, importlib.util, json, pickle, re, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REFHI, REFLO, PAIR = 0x10, 0x11, 0x12


def load_units():
    spec = importlib.util.spec_from_file_location("matching", ROOT / "tools/matching.py")
    m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
    return list(m.MATCHING_UNITS)


def read_obj(path):
    """Return (sections, symbols): sections = [(name, data, [(off, symidx, kind)])], symbols = {idx: (name, value, secnum)}."""
    data = Path(path).read_bytes()
    _m, nsec, _t, symoff, nsym, optsize, _c = struct.unpack_from("<HHIIIHH", data, 0)
    strtab = symoff + nsym * 18

    def nm(raw):
        if raw[:4] == b"\0\0\0\0":
            o = struct.unpack_from("<I", raw, 4)[0]
            return data[strtab + o:data.index(b"\0", strtab + o)].decode("latin-1")
        return raw.rstrip(b"\0").decode("latin-1")
    syms = {}; i = 0
    while i < nsym:
        raw = data[symoff + i * 18:symoff + i * 18 + 18]
        value, sec, _ty, _st, aux = struct.unpack_from("<IhHBB", raw, 8)
        syms[i] = (nm(raw[:8]), value, sec); i += 1 + aux
    secs = []
    for k in range(nsec):
        _n, _vs, _va, size, ptr, relptr, _ln, nrel, _nl, ch = struct.unpack_from("<8sIIIIIIHHI", data, 20 + optsize + k * 40)
        first = 0
        if ch & 0x01000000 and nrel == 0xFFFF:
            nrel = struct.unpack_from("<I", data, relptr)[0]; first = 1
        rel = [struct.unpack_from("<IIH", data, relptr + r * 10) for r in range(first, nrel)]
        secs.append((data[ptr:ptr + size] if ptr else bytes(size), rel))
    return secs, syms


def sext(v):
    v &= 0xFFFF
    return v - 0x10000 if v & 0x8000 else v


def imm_of(text, hi):
    """Immediate of an original instruction string: lis imm, or the d/imm16 field."""
    nums = re.findall(r"(-?0x[0-9a-f]+|-?\d+)(?=\(|$|,)", text.split("->")[0].strip())
    if not nums:
        return None
    v = int(nums[-1], 0)
    if text.split()[0] in ("subi", "subis", "subic"):
        v = -v
    return v & 0xFFFF


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--build", default=str(ROOT / "work/matching-b163"))
    ap.add_argument("--dis", default=str(ROOT / "work/army/VX1/textdis.pkl"))
    ap.add_argument("--json")
    ap.add_argument("--verbose", action="store_true")
    a = ap.parse_args()
    dis = pickle.load(open(a.dis, "rb"))
    addr = {}; text = {}
    for line in open(ROOT / "config/54540859/symbols.txt"):
        mo = re.match(r"(\S+)\s*=\s*(\.?\w+):0x([0-9A-Fa-f]{8});(.*?size:0x([0-9A-Fa-f]+))?", line)
        if mo:
            addr[mo.group(1)] = int(mo.group(3), 16)
            if mo.group(2) == ".text" and mo.group(5):
                text[mo.group(1)] = (int(mo.group(3), 16), int(mo.group(5), 16))
    name_of = {}
    for k, v in addr.items():
        name_of.setdefault(v, k)

    def resolve(name):
        if name.startswith(("__real@", "__xmm@", "__int", "$", "??_C@")):
            return None  # pooled literals: hex suffix is the value, not an address
        if name in addr:
            return addr[name]
        base = name[1:].split("@", 1)[0] if name.startswith("?") else name
        if base in addr:
            return addr[base]
        hx = re.search(r"([0-9A-Fa-f]{8})$", base)
        if hx and int(hx.group(1), 16) >= 0x82000000:
            return int(hx.group(1), 16)
        return None

    st = collections.Counter(); unres = collections.Counter(); bad = []
    for u in load_units():
        obj = Path(a.build) / "rebuilt" / u["object"]
        if not obj.exists():
            st["missing_obj"] += 1; continue
        secs, syms = read_obj(obj); st["objects"] += 1
        defs = {v[0]: v for v in syms.values() if v[2] > 0}
        for fname in u.get("symbols", {}):
            if fname not in text or fname not in defs or text[fname][0] not in dis:
                continue
            A, size = text[fname]; ins = dis[A]
            _, start, secno = defs[fname]
            sdata, rel = secs[secno - 1]
            rel = [r for r in rel if start <= r[0] < start + size]
            st["functions"] += 1
            for idx, (off, si, kind) in enumerate(rel):
                if kind not in (REFHI, REFLO):
                    continue
                k = (off - start) // 4
                if k >= len(ins):
                    continue
                st["relocs"] += 1
                sname = syms.get(si, ("#%d" % si,))[0]
                S = resolve(sname)
                if S is None:
                    st["unresolved"] += 1
                    unres[re.sub(r"[0-9A-Fa-f]{6,}.*|@.*", "", sname)] += 1
                    continue
                word = struct.unpack_from(">I", sdata, off & ~3)[0]
                orig = imm_of(ins[k], kind == REFHI)
                if orig is None:
                    st["unparsed"] += 1; continue
                if kind == REFLO:
                    full = (S + sext(word)) & 0xFFFFFFFF
                    want = full & 0xFFFF
                else:
                    lo_off = next((r[0] for r in rel[idx + 1:] if r[2] == REFLO and r[1] == si), None)
                    if lo_off is not None:
                        lo = sext(struct.unpack_from(">I", sdata, lo_off & ~3)[0])
                    else:
                        pr = rel[idx + 1] if idx + 1 < len(rel) and rel[idx + 1][2] == PAIR else None
                        lo = sext(pr[1]) if pr else 0
                    full = (S + lo) & 0xFFFFFFFF
                    want = ((full + 0x8000) >> 16) & 0xFFFF
                if want != orig:
                    bad.append(dict(source=u["source"], function=fname, offset=off - start,
                                    kind="REFHI" if kind == REFHI else "REFLO", symbol=sname,
                                    symbol_addr="0x%08X" % S, rebuilt_field="0x%04X" % want,
                                    original_field="0x%04X" % orig, original_insn=ins[k]))
    for b in bad:
        print(f"{b['source']}: {b['function']}+0x{b['offset']:X} {b['kind']} {b['symbol']} ({b['symbol_addr']}) "
              f"gives {b['rebuilt_field']}, original {b['original_field']} [{b['original_insn']}]")
    print(f"{dict(st)} mismatches={len(bad)}", file=sys.stderr)
    if a.verbose:
        print("unresolved by prefix:", unres.most_common(20), file=sys.stderr)
    if a.json:
        Path(a.json).write_text(json.dumps(bad, indent=1))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
