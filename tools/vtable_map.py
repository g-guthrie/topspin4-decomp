#!/usr/bin/env python3
"""Vtables in Swing_DLL without RTTI: the game's own classes.

  python3 tools/vtable_map.py [--image orig/54540859/Swing_DLL.dll] [--out config/54540859/vtables.json]

Game code was built without RTTI (tools/rtti_map.py finds only Havok), so a
vtable is found as a run of words in .rdata/.data that are all function starts
from config/54540859/symbols.txt. Adjacent vtables have no separator, so a run
is cut at every address that .text loads with lis/addi (a constructor storing
its vtable pointer). Each vtable lists its slots and the functions that load
its address. RTTI vtables (config/54540859/rtti_classes.json) are flagged.
Names and addresses only: no image bytes are copied.
"""
import argparse, hashlib, json, re, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import rtti_map


def code_refs(img, starts_sorted):
    """target address -> set of function starts whose code makes it with lis+addi."""
    import bisect
    _, va, vs, ra, rs = img.sec(".text")
    refs = {}
    hi = {}
    for k in range(0, min(vs, rs) - 3, 4):
        w = struct.unpack_from(">I", img.d, ra + k)[0]
        op = w >> 26
        rd, rA, imm = (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
        if op == 15 and rA == 0:          # lis rd, imm
            hi[rd] = (imm << 16, k)
        elif op == 14 and rA in hi and k - hi[rA][1] <= 64:   # addi rd, rA, imm
            t = (hi[rA][0] + (imm - 0x10000 if imm & 0x8000 else imm)) & 0xFFFFFFFF
            i = bisect.bisect_right(starts_sorted, va + k) - 1
            refs.setdefault(t, set()).add(starts_sorted[i] if i >= 0 else 0)
    return refs


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--image", default="orig/54540859/Swing_DLL.dll")
    ap.add_argument("--symbols", default="config/54540859/symbols.txt")
    ap.add_argument("--out", default="config/54540859/vtables.json")
    ap.add_argument("--min-slots", type=int, default=2)
    a = ap.parse_args()
    img = rtti_map.Image(ROOT / a.image)
    names, starts = {}, set()
    for l in open(ROOT / a.symbols):
        m = re.match(r"(\S+) = \.text:0x([0-9A-Fa-f]+);.*type:function", l)
        if m:
            s = int(m.group(2), 16); starts.add(s); names[s] = m.group(1)
    ss = sorted(starts)
    refs = code_refs(img, ss)
    rtti = {}
    rp = ROOT / "config/54540859/rtti_classes.json"
    if rp.exists():
        for c in json.loads(rp.read_text())["rows"]:
            for v in c["vtables"]:
                rtti[int(v["vtable"], 16)] = c["name"]
    vts = []
    for sec in (".rdata", ".data"):
        _, va, vs, ra, rs = img.sec(sec)
        k = 0
        while k < rs - 3:
            if img.u32(va + k) not in starts:
                k += 4; continue
            s = k
            while k < rs - 3 and img.u32(va + k) in starts:
                k += 4
            cuts = [s] + [j for j in range(s + 4, k, 4) if (va + j) in refs or (va + j) in rtti] + [k]
            for b, e in zip(cuts, cuts[1:]):
                n = (e - b) // 4
                v = va + b
                if n < a.min_slots and v not in refs:
                    continue
                vts.append({"vtable": f"0x{v:08X}", "section": sec, "slots": n,
                            "rtti": rtti.get(v),
                            "loaded_by": [names.get(f, f"0x{f:08X}") for f in sorted(refs.get(v, ()))][:8],
                            "functions": [names[img.u32(v + 4 * i)] for i in range(n)]})
    out = {"generated_by": f"python3 tools/vtable_map.py --image {a.image} --out {a.out}",
           "source": a.image, "source_sha256": hashlib.sha256(img.d).hexdigest(), "source_size": len(img.d),
           "symbols_sha256": hashlib.sha256((ROOT / a.symbols).read_bytes()).hexdigest(),
           "vtables": len(vts), "with_code_ref": sum(1 for v in vts if v["loaded_by"]),
           "rtti_named": sum(1 for v in vts if v["rtti"]), "rows": vts}
    (ROOT / a.out).write_text(json.dumps(out, indent=1) + "\n")
    print(f"{out['vtables']} vtables, {out['with_code_ref']} loaded by code, {out['rtti_named']} RTTI-named -> {a.out}")


if __name__ == "__main__":
    sys.exit(main())
