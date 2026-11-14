#!/usr/bin/env python3
"""Generate work/havok/classes.json (Havok class layouts) from the user's own Swing_DLL.

The class layouts the packfile reader needs are the Havok runtime's reflection data,
which is statically linked into the game executable. That data is SDK-derived, so it is
never committed: run this tool locally to produce a git-ignored JSON file, which
tools/havok/classes.py loads at run time.

  python3 tools/havok/dll_classes.py orig/54540859/Swing_DLL.dll            # -> work/havok/classes.json
  python3 tools/havok/dll_classes.py DLL --out PATH [--print NAME ...]

How it works (all addresses are found, not hard-coded, except the constructor):
  * Each reflected class is built by a static initialiser that calls the hkClass
    constructor (0x8841F080 in the retail Swing_DLL; override with --ctor) with
    r3=this, r4=name, r5=parent hkClass*, r6=objectSize, r7/r8 interfaces,
    r9=enums*, r10=numEnums, and members* / numMembers stored to the stack at
    0x54 / 0x5C. The tool scans every `bl ctor`, replays the lis/addi/li/ori/mr/stw
    instructions of that initialiser to recover the arguments, and keeps the
    "current" class set (objectSize != 0; the other copies are the version-upgrade
    tables).
  * Member records (0x18 bytes) and enum records (0x14 bytes, items of 8 bytes) are
    constant data in .rdata and are decoded directly; member class pointers are
    mapped back to names through the constructor calls' `this` arguments.
The input is a PE image (the basefile extracted from Swing_DLL.xex).
"""
import argparse
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
DEFAULT_OUT = os.path.join(HERE, "..", "..", "work", "havok", "classes.json")
HKCLASS_CTOR = 0x8841F080


class PE:
    def __init__(self, path):
        self.d = open(path, "rb").read()
        d = self.d
        if d[:2] != b"MZ":
            raise SystemExit("%s is not a PE image (extract the basefile from the .xex first)" % path)
        pe = struct.unpack_from("<I", d, 0x3C)[0]
        nsec = struct.unpack_from("<H", d, pe + 6)[0]
        opt = struct.unpack_from("<H", d, pe + 20)[0]
        self.base = struct.unpack_from("<I", d, pe + 24 + 28)[0]
        self.secs = []
        for i in range(nsec):
            o = pe + 24 + opt + 40 * i
            vs, va, rs, ra = struct.unpack_from("<4I", d, o + 8)
            self.secs.append((d[o:o + 8].rstrip(b"\0").decode(), va, vs, ra, rs))

    def off(self, addr):
        rva = addr - self.base
        for n, va, vs, ra, rs in self.secs:
            if rs and va <= rva < va + min(vs, rs):
                return ra + rva - va
        return None

    def addr(self, off):
        for n, va, vs, ra, rs in self.secs:
            if ra <= off < ra + rs:
                return self.base + va + off - ra
        return None

    def u32(self, addr):
        o = self.off(addr)
        return None if o is None else struct.unpack_from(">I", self.d, o)[0]

    def cstr(self, addr):
        o = self.off(addr) if addr else None
        if o is None:
            return None
        e = self.d.find(b"\0", o)
        s = self.d[o:e]
        return s.decode("latin-1") if s and all(32 <= c < 127 for c in s) else None

    def section(self, name):
        for s in self.secs:
            if s[0] == name:
                return s
        return None


def _s16(v):
    return v - 0x10000 if v & 0x8000 else v


def replay(pe, call_addr, max_back=96):
    """Recover r3..r10 and stack stores at a call by replaying simple integer ops."""
    start = call_addr - 4
    lo = call_addr - 4 * max_back
    a = start
    while a > lo:  # stop at the previous call/return: the initialiser's own prologue
        w = pe.u32(a)
        if w is None or w == 0x4E800020 or (w >> 26 == 18 and w & 1):
            a += 4
            break
        a -= 4
    regs, stack = {}, {}
    while a < call_addr:
        w = pe.u32(a)
        op, rd, ra_, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
        if op == 15:  # addis / lis
            regs[rd] = ((regs.get(ra_, 0) if ra_ else 0) + (imm << 16)) & 0xFFFFFFFF
        elif op == 14:  # addi / li
            regs[rd] = ((regs.get(ra_, 0) if ra_ else 0) + _s16(imm)) & 0xFFFFFFFF
        elif op == 24:  # ori: rA = rS | imm
            regs[ra_] = regs.get(rd, 0) | imm
        elif op == 31 and ((w >> 1) & 0x3FF) == 444:  # or rA,rS,rB (mr)
            rb = (w >> 11) & 31
            if rb == rd:
                regs[ra_] = regs.get(rd)
        elif op == 36 and ra_ == 1:  # stw rS, d(r1)
            stack[_s16(imm)] = regs.get(rd)
        a += 4
    return regs, stack


def find_ctor_calls(pe, ctor):
    n, va, vs, ra, rs = pe.section(".text")
    d = pe.d
    out = []
    for o in range(ra, ra + rs, 4):
        w = struct.unpack_from(">I", d, o)[0]
        if w >> 26 == 18 and w & 3 == 1:
            li = w & 0x3FFFFFC
            if li & 0x2000000:
                li -= 0x4000000
            a = pe.addr(o)
            if a + li == ctor:
                out.append(a)
    return out


def read_enum(pe, a):
    name = pe.cstr(pe.u32(a))
    items_p, n = pe.u32(a + 4), pe.u32(a + 8)
    items = {}
    for j in range(n or 0):
        v = pe.u32(items_p + 8 * j)
        items[v - (1 << 32) if v & 0x80000000 else v] = pe.cstr(pe.u32(items_p + 8 * j + 4))
    return name, items


def extract(pe, ctor=HKCLASS_CTOR):
    calls = find_ctor_calls(pe, ctor)
    raw = []
    for c in calls:
        regs, stack = replay(pe, c)
        name = pe.cstr(regs.get(4))
        size = regs.get(6)
        if not name or not size:
            continue
        raw.append(dict(this=regs.get(3), name=name, parent=regs.get(5), size=size,
                        enums=regs.get(9), nenums=regs.get(10) or 0,
                        members=stack.get(0x54), nmembers=stack.get(0x5C) or 0))
    by_addr = {r["this"]: r["name"] for r in raw if r["this"]}
    enum_names = {}
    for r in raw:
        for i in range(r["nenums"] if r["enums"] else 0):
            enum_names[r["enums"] + 0x14 * i] = read_enum(pe, r["enums"] + 0x14 * i)[0]
    classes = {}
    for r in raw:
        members = []
        for i in range(r["nmembers"] if r["members"] else 0):
            b = r["members"] + 0x18 * i
            w = [pe.u32(b + 4 * k) for k in range(6)]
            ename = (enum_names.get(w[2]) or pe.cstr(pe.u32(w[2]) or 0)) if w[2] else None
            members.append(dict(name=pe.cstr(w[0]), type=w[3] >> 24, subtype=(w[3] >> 16) & 0xFF,
                                carray=w[3] & 0xFFFF, flags=w[4] >> 16, offset=w[4] & 0xFFFF,
                                cls=by_addr.get(w[1]) if w[1] else None, enum=ename))
        enums = {}
        for i in range(r["nenums"] if r["enums"] else 0):
            en, items = read_enum(pe, r["enums"] + 0x14 * i)
            enums[en] = {str(k): v for k, v in items.items()}
        # The member records' enum pointers are 0 in the image (filled in at run time);
        # when the class declares exactly one enum, ENUM members use it.
        if len(enums) == 1:
            for m in members:
                if m["type"] == 24 and not m["enum"]:
                    m["enum"] = next(iter(enums))
        classes[r["name"]] = dict(size=r["size"], parent=by_addr.get(r["parent"]) if r["parent"] else None,
                                  members=members, enums=enums)
    return classes, len(calls)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("dll")
    ap.add_argument("--out", default=DEFAULT_OUT)
    ap.add_argument("--ctor", type=lambda s: int(s, 0), default=HKCLASS_CTOR)
    ap.add_argument("--print", nargs="*", metavar="NAME", help="print these classes instead of only writing")
    a = ap.parse_args()
    pe = PE(a.dll)
    classes, ncalls = extract(pe, a.ctor)
    os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
    with open(a.out, "w") as f:
        json.dump({"source": os.path.basename(a.dll), "ctor": "0x%08X" % a.ctor, "classes": classes}, f, indent=1)
    print("%d hkClass constructor calls, %d current classes -> %s" % (ncalls, len(classes), a.out))
    for n in a.print or []:
        c = classes.get(n)
        if not c:
            print("%s: not found" % n)
            continue
        print("%s size 0x%X parent %s" % (n, c["size"], c["parent"]))
        for m in c["members"]:
            print("  +0x%02X %-32s type %d sub %d%s" % (m["offset"], m["name"], m["type"], m["subtype"],
                                                      " <%s>" % (m["cls"] or m["enum"]) if (m["cls"] or m["enum"]) else ""))


if __name__ == "__main__":
    main()
