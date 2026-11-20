#!/usr/bin/env python3
"""MSVC RTTI class map from the Swing_DLL PE image.

  python3 tools/rtti_map.py [--image orig/54540859/Swing_DLL.dll] [--out config/54540859/rtti_classes.json]

Walks the 32-bit MSVC RTTI structures (big-endian words):
  TypeDescriptor         +0 vftable of type_info, +4 spare, +8 ".?AVName@@" (class) / ".?AUName@@" (struct)
  CompleteObjectLocator  +0 signature 0, +4 offset of this vtable in the object, +8 cdOffset,
                         +0xc TypeDescriptor*, +0x10 ClassHierarchyDescriptor*
  vtable                 the word before it points at the COL (MSVC puts the COL at vtable-4)
  ClassHierarchyDescriptor +4 attributes (1 multiple, 2 virtual inheritance), +8 count, +0xc BaseClassArray*
  BaseClassDescriptor    +0 TypeDescriptor*, +4 numContainedBases, +8 mdisp, +0xc pdisp, +0x10 vdisp
Output lists every class with its vtables (address, slot count up to the next
non-code word, offset in the object) and its base classes in hierarchy order.
Names and addresses only: no image bytes are copied.
"""
import argparse
import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


class Image:
    def __init__(self, path):
        self.d = Path(path).read_bytes()
        pe = struct.unpack_from("<I", self.d, 0x3C)[0]
        nsec = struct.unpack_from("<H", self.d, pe + 6)[0]
        opt = struct.unpack_from("<H", self.d, pe + 20)[0]
        self.base = struct.unpack_from("<I", self.d, pe + 24 + 28)[0]
        self.secs = []
        o = pe + 24 + opt
        for i in range(nsec):
            n, vs, va, rs, ra = struct.unpack_from("<8sIIII", self.d, o + 40 * i)
            self.secs.append((n.rstrip(b"\0").decode(), self.base + va, vs, ra, rs))

    def sec(self, name):
        return next(s for s in self.secs if s[0] == name)

    def off(self, va):
        for _, sva, vs, ra, rs in self.secs:
            if sva <= va < sva + min(vs, rs):
                return ra + va - sva
        return None

    def u32(self, va):
        o = self.off(va)
        return None if o is None else struct.unpack_from(">I", self.d, o)[0]

    def cstr(self, va):
        o = self.off(va)
        e = self.d.index(b"\0", o)
        return self.d[o:e].decode("latin-1")

    def in_sec(self, va, name):
        _, sva, vs, _, _ = self.sec(name)
        return sva <= va < sva + vs


def demangle_td(name):
    """'.?AVFoo@Bar@@' -> 'Bar::Foo' (simple nested names; templates kept raw)."""
    core = name[4:]
    if core.endswith("@@"):
        core = core[:-2]
    if "?$" in core or "?" in core:
        return name
    return "::".join(reversed(core.split("@")))


def build(img):
    rd_name, rd_va, rd_vs, rd_ra, rd_rs = img.sec(".rdata")
    data = img.d[rd_ra:rd_ra + rd_rs]
    tds = {}
    for tag in (b".?AV", b".?AU"):
        i = data.find(tag)
        while i != -1:
            va = rd_va + i - 8
            if (va & 3) == 0:
                tds[va] = img.cstr(va + 8)
            i = data.find(tag, i + 1)
    # also TDs in .data (MSVC usually emits them there)
    dn, d_va, d_vs, d_ra, d_rs = img.sec(".data")
    ddata = img.d[d_ra:d_ra + d_rs]
    for tag in (b".?AV", b".?AU"):
        i = ddata.find(tag)
        while i != -1:
            va = d_va + i - 8
            if (va & 3) == 0:
                tds[va] = img.cstr(va + 8)
            i = ddata.find(tag, i + 1)
    words = {}
    for k in range(0, rd_rs - 3, 4):
        words[rd_va + k] = struct.unpack_from(">I", data, k)[0]
    cols = {}
    for va, w in words.items():
        if w in tds and words.get(va - 0xC) == 0:
            col = va - 0xC
            chd = words.get(col + 0x10)
            if chd is not None:
                cols[col] = (tds[w], words.get(col + 4), chd)
    by_ptr = {}
    for va, w in words.items():
        if w in cols:
            by_ptr.setdefault(w, []).append(va + 4)
    classes = {}
    for col, (name, offset, chd) in sorted(cols.items()):
        c = classes.setdefault(name, {"name": demangle_td(name), "mangled": name, "vtables": [], "bases": []})
        for vt in by_ptr.get(col, []):
            n = 0
            while img.in_sec(img.u32(vt + 4 * n) or 0, ".text"):
                n += 1
            c["vtables"].append({"vtable": f"0x{vt:08X}", "col": f"0x{col:08X}", "offset": offset, "slots": n})
        if not c["bases"]:
            attrs, cnt, arr = img.u32(chd + 4), img.u32(chd + 8), img.u32(chd + 0xC)
            c["attributes"] = attrs
            for k in range(1, cnt or 0):
                bcd = img.u32(arr + 4 * k)
                btd = img.u32(bcd)
                c["bases"].append({"name": demangle_td(tds.get(btd, f"?{btd:08X}")),
                                   "mdisp": img.u32(bcd + 8), "pdisp": struct.unpack(">i", struct.pack(">I", img.u32(bcd + 0xC)))[0]})
    for va, name in tds.items():
        classes.setdefault(name, {"name": demangle_td(name), "mangled": name, "vtables": [], "bases": []})
        classes[name]["type_descriptor"] = f"0x{va:08X}"
    return classes


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--image", default="orig/54540859/Swing_DLL.dll")
    ap.add_argument("--out", default="config/54540859/rtti_classes.json")
    a = ap.parse_args()
    img = Image(ROOT / a.image)
    classes = build(img)
    rows = sorted(classes.values(), key=lambda c: c["name"])
    sha = hashlib.sha256(img.d).hexdigest()
    out = {"generated_by": f"python3 tools/rtti_map.py --image {a.image} --out {a.out}",
           "source": a.image, "source_sha256": sha, "source_size": len(img.d),
           "classes": len(rows), "with_vtable": sum(1 for c in rows if c["vtables"]),
           "vtables": sum(len(c["vtables"]) for c in rows), "rows": rows}
    Path(ROOT / a.out).write_text(json.dumps(out, indent=1) + "\n")
    print(f"{len(rows)} classes, {out['with_vtable']} with vtables, {out['vtables']} vtables -> {a.out}")


if __name__ == "__main__":
    sys.exit(main())
