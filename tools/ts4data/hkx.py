#!/usr/bin/env python3
"""Havok 5.5.0-r1 binary packfile (.hkx) reader prototype (standard library only).

Family DF (data formats) prototype for Top Spin 4 (Xbox 360, Swing_DLL.xex).
Spec: work/gameplay-notes/df.md section 5.  Class layouts: work/havok55_classes.json (local only, never committed: it is derived from the SDK), dumped from the
hkClass reflection objects inside Swing_DLL.xex (python3 -I tools/... not needed to run this file).

Confidence: container structure H (matches Havok's public binary packfile layout and the reader's
0x40-byte header read / 0x30-byte section headers / magic 0x57E0E057 0x10C0C010 seen in the
disassembly); object decoding M (driven by the reflection member tables, never run on a real game
file because none was available); Spline/Delta/Wavelet animation DATA decoding is NOT implemented.

Usage:
  df_hkx.py info FILE.hkx                  header, sections, fixup counts, virtual-fixup objects
  df_hkx.py json FILE.hkx [--root CLASS]   decode the contents object (or first object of CLASS)
  df_hkx.py selftest                       build a tiny synthetic packfile and round-trip it
"""
from __future__ import annotations

import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
MAGIC0, MAGIC1 = 0x57E0E057, 0x10C0C010


def load_classes(path: str | None = None) -> dict:
    with open(path or os.path.join(HERE, "..", "..", "work", "havok55_classes.json")) as f:
        return json.load(f)


class Packfile:
    """Parsed hkBinaryPackfile. All integers are read with the byte order given by layoutRules[1]."""

    def __init__(self, data: bytes):
        self.data = data
        if len(data) < 0x40:
            raise ValueError("too small for a packfile header")
        m0, m1 = struct.unpack(">II", data[:8])
        if (m0, m1) != (MAGIC0, MAGIC1):
            m0l, m1l = struct.unpack("<II", data[:8])
            if (m0l, m1l) != (MAGIC0, MAGIC1):
                raise ValueError("bad packfile magic %08x %08x" % (m0, m1))
            self.e = "<"
        else:
            self.e = ">"
        e = self.e
        (self.user_tag, self.file_version) = struct.unpack(e + "ii", data[8:16])
        self.layout = tuple(data[16:20])  # bytesInPointer, littleEndian, reusePadding, emptyBaseClassOpt
        (self.num_sections, self.contents_section, self.contents_offset,
         self.classname_section, self.classname_offset) = struct.unpack(e + "5i", data[20:40])
        self.contents_version = data[40:56].split(b"\0")[0].decode("latin1")
        (self.flags, _pad) = struct.unpack(e + "ii", data[56:64])
        if self.layout[0] != 4:
            raise ValueError("only 32-bit pointer layouts are supported (Xbox 360)")
        self.sections = []
        for i in range(self.num_sections):
            o = 0x40 + 0x30 * i
            tag = data[o:o + 19].split(b"\0")[0].decode("latin1")
            vals = struct.unpack(e + "7I", data[o + 20:o + 48])
            names = ("start", "local", "glob", "virt", "exports", "imports", "end")
            s = dict(zip(names, vals))
            s["tag"] = tag
            s["index"] = i
            # Data bytes are [start, start+local); fixup tables follow, all offsets relative to start.
            s["bytes"] = data[s["start"]:s["start"] + s["local"]]
            self.sections.append(s)
        self._read_fixups()
        self._read_classnames()

    def _pairs(self, s, lo, hi, n):
        e = self.e
        base = s["start"]
        out = []
        p = base + lo
        end = base + hi
        while p + 4 * n <= end:
            v = struct.unpack(e + "%dI" % n, self.data[p:p + 4 * n])
            if v[0] == 0xFFFFFFFF:
                break
            out.append(v)
            p += 4 * n
        return out

    def _read_fixups(self):
        self.ptr = {}   # (section, src offset) -> (dst section, dst offset)
        self.virt = {}  # (section, obj offset) -> (class name section, class name offset)
        for s in self.sections:
            for src, dst in self._pairs(s, s["local"], s["glob"], 2):
                self.ptr[(s["index"], src)] = (s["index"], dst)
            for src, sec, dst in self._pairs(s, s["glob"], s["virt"], 3):
                self.ptr[(s["index"], src)] = (sec, dst)
            for off, sec, name in self._pairs(s, s["virt"], s["exports"], 3):
                self.virt[(s["index"], off)] = (sec, name)

    def _read_classnames(self):
        """__classnames__ entries: u32 signature, 0x09, NUL-terminated name. Offsets used by virtual
        fixups point at the name (after the 5 prefix bytes)."""
        self.class_sigs = {}
        if not (0 <= self.classname_section < len(self.sections)):
            return
        b = self.sections[self.classname_section]["bytes"]
        p = 0
        while p + 5 < len(b):
            sig = struct.unpack(self.e + "I", b[p:p + 4])[0]
            if sig == 0 and p > 0 and b[p:p + 4] == b"\0\0\0\0":
                break
            if b[p + 4] != 9:
                break
            q = b.index(b"\0", p + 5)
            self.class_sigs[p + 5] = (b[p + 5:q].decode("latin1"), sig)
            p = q + 1

    def cstring(self, sec, off):
        b = self.sections[sec]["bytes"]
        return b[off:b.index(b"\0", off)].decode("latin1")

    def class_of(self, sec, off):
        v = self.virt.get((sec, off))
        if not v:
            return None
        return self.cstring(v[0], v[1])

    def objects(self):
        return sorted((s, o, self.class_of(s, o)) for (s, o) in self.virt)


class Decoder:
    """Generic reflection-driven decoder (Havok 5.5 hkClassMember layout, 32-bit big-endian)."""

    SCALAR = {"bool": ("B", 1), "char": ("b", 1), "int8": ("b", 1), "uint8": ("B", 1), "int16": ("h", 2),
              "uint16": ("H", 2), "int32": ("i", 4), "uint32": ("I", 4), "int64": ("q", 8),
              "uint64": ("Q", 8), "real": ("f", 4), "ulong": ("I", 4), "half": ("H", 2)}
    FLOATS = {"vector4": 4, "quaternion": 4, "matrix3": 12, "rotation": 12, "qstransform": 12,
              "matrix4": 16, "transform": 16}

    def __init__(self, pf: Packfile, classes: dict):
        self.pf, self.cls, self.memo = pf, classes, {}
        self.e = pf.e

    def members(self, name):
        chain = []
        while name:
            c = self.cls.get(name)
            if c is None:
                raise KeyError("class %s not in reflection table" % name)
            chain.append(c)
            name = c["parent"]
        for c in reversed(chain):
            yield from c["members"]

    def u(self, sec, off, fmt, n):
        b = self.pf.sections[sec]["bytes"]
        return struct.unpack_from(self.e + fmt, b, off)[0]

    def ptr(self, sec, off):
        return self.pf.ptr.get((sec, off))

    def obj(self, sec, off, cname, depth=0):
        key = (sec, off, cname)
        if key in self.memo:
            return self.memo[key]
        vname = self.pf.class_of(sec, off) or cname
        res = {"__class": vname}
        self.memo[key] = res
        for m in self.members(vname):
            name, typ, sub, mcls, carr, moff = m
            res[name] = self.value(sec, off + moff, typ, sub, mcls, carr, depth + 1)
        return res

    def value(self, sec, off, typ, sub, mcls, carr, depth):
        if carr and typ not in ("char",) :
            esz = self.size_of(typ, sub, mcls)
            return [self.value(sec, off + i * esz, typ, sub, mcls, 0, depth) for i in range(carr)]
        if typ == "char" and carr:
            b = self.pf.sections[sec]["bytes"][off:off + carr]
            return b.split(b"\0")[0].decode("latin1")
        if typ in self.SCALAR:
            f, n = self.SCALAR[typ]
            v = self.u(sec, off, f, n)
            return bool(v) if typ == "bool" else v
        if typ == "enum":
            f, n = self.SCALAR[sub]
            return self.u(sec, off, f, n)
        if typ in self.FLOATS:
            n = self.FLOATS[typ]
            return list(struct.unpack_from(self.e + "%df" % n, self.pf.sections[sec]["bytes"], off))
        if typ in ("cstring", "stringptr"):
            t = self.ptr(sec, off)
            return self.pf.cstring(*t) if t else None
        if typ == "pointer":
            t = self.ptr(sec, off)
            if not t:
                return None
            if depth > 40:
                return "<depth>"
            return self.obj(t[0], t[1], mcls, depth)
        if typ == "struct":
            return self.obj(sec, off, mcls, depth)
        if typ in ("array", "simplearray"):
            t = self.ptr(sec, off)
            n = self.u(sec, off + 4, "i", 4)
            if not t or n <= 0:
                return []
            esz = self.size_of(sub, None, mcls) if sub != "struct" else self.cls[mcls]["size"]
            return [self.value(t[0], t[1] + i * esz, sub, None, mcls, 0, depth) for i in range(n)]
        if typ == "variant":
            t = self.ptr(sec, off)
            return self.obj(t[0], t[1], None, depth) if t else None
        return "<unsupported %s>" % typ

    def size_of(self, typ, sub, mcls):
        if typ in self.SCALAR:
            return self.SCALAR[typ][1]
        if typ == "enum":
            return self.SCALAR[sub][1]
        if typ in self.FLOATS:
            return self.FLOATS[typ] * 4
        if typ in ("pointer", "cstring", "stringptr"):
            return 4
        if typ == "struct":
            return self.cls[mcls]["size"]
        if typ == "array":
            return 12
        if typ == "simplearray":
            return 8
        if typ == "variant":
            return 8
        raise ValueError(typ)


def decode_contents(pf: Packfile, classes: dict, root_class: str | None = None):
    d = Decoder(pf, classes)
    if root_class:
        for s, o, c in pf.objects():
            if c == root_class:
                return d.obj(s, o, c)
        raise KeyError(root_class)
    return d.obj(pf.contents_section, pf.contents_offset, pf.class_of(pf.contents_section, pf.contents_offset))


def find_in_root_container(root: dict, class_name: str):
    """hkRootLevelContainer.namedVariants -> first variant whose className matches (the game does the
    same: fn_884CCC70 on the root, class = hkaAnimationContainer / hkpPhysicsData / hkaRagdollInstance)."""
    for nv in root.get("namedVariants", []):
        if nv.get("className") == class_name:
            return nv.get("variant")
    return None


def interleaved_tracks(anim: dict):
    """hkaInterleavedSkeletalAnimation: transforms are pose-major, numberOfTransformTracks per pose.
    Returns frames[pose][track] = (translation, rotation quaternion xyzw, scale)."""
    n = anim["numberOfTransformTracks"]
    t = anim["transforms"]
    return [[(q[0:4], q[4:8], q[8:12]) for q in t[i:i + n]] for i in range(0, len(t), n)] if n else []


# --------------------------------------------------------------------------------------- selftest
def _build_test_packfile() -> bytes:
    """Synthetic file: __classnames__ + __data__ with hkRootLevelContainer -> hkaAnimationContainer ->
    one hkaSkeleton (2 bones). Written with the same layout rules the reader assumes."""
    be = ">"
    names = b""
    off = {}
    for n in ("hkRootLevelContainer", "hkaAnimationContainer"):
        names += struct.pack(be + "I", 0x12345678) + b"\x09"
        off[n] = len(names)
        names += n.encode() + b"\0"
    # data: build by hand
    d = bytearray(0x200)
    strs = {}
    sp = 0x180

    def put_str(s):
        nonlocal sp
        if s in strs:
            return strs[s]
        strs[s] = sp
        d[sp:sp + len(s) + 1] = s.encode() + b"\0"
        sp += len(s) + 1
        return strs[s]

    local, glob, virt = [], [], []
    # hkRootLevelContainer @0: namedVariants simplearray {ptr,size} @0 -> NamedVariant array @0x10 (1 item, 0x10 bytes)
    struct.pack_into(be + "iI", d, 0, 0, 1)
    local.append((0, 0x10))
    # NamedVariant @0x10: name@+0 cstring, className@+4 cstring, variant@+8 {ptr, class}
    struct.pack_into(be + "I", d, 0x10, 0); local.append((0x10, put_str("Default Animation Container")))
    local.append((0x14, put_str("hkaAnimationContainer")))
    local.append((0x18, 0x40))   # variant object -> container @0x40
    virt.append((0x0, "hkRootLevelContainer"))
    virt.append((0x40, "hkaAnimationContainer"))
    # hkaAnimationContainer @0x40: skeletons simplearray @+0 {ptr,size}; others empty
    struct.pack_into(be + "I", d, 0x44, 1); local.append((0x40, 0x80))
    # pointer array @0x80 -> hkaSkeleton @0x90
    local.append((0x80, 0x90))
    # hkaSkeleton @0x90: name@+0, parentIndices@+4 {ptr,size}, bones@+0xc {ptr,size}, refPose@+0x14, floatSlots@+0x1c
    local.append((0x90, put_str("Root_Skeleton")))
    local.append((0x94, 0xd0)); struct.pack_into(be + "I", d, 0x98, 2)
    struct.pack_into(be + "hh", d, 0xd0, -1, 0)
    local.append((0x9c, 0xe0)); struct.pack_into(be + "I", d, 0xa0, 2)
    local.append((0xa4, 0x100)); struct.pack_into(be + "I", d, 0xa8, 2)
    # bones pointer array @0xe0 -> hkaBone @0xf0 and @0xf8
    local.append((0xe0, 0xf0)); local.append((0xe4, 0xf8))
    local.append((0xf0, put_str("pelvis"))); local.append((0xf8, put_str("spine")))
    # reference pose @0x100: 2 qstransforms (48 bytes)
    struct.pack_into(be + "12f", d, 0x100, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0)
    struct.pack_into(be + "12f", d, 0x130, 0, 2, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0)
    # (0x130+0x30 = 0x160 < 0x180 ok)
    # fixup tables appended to the section: [data][local][global][virtual][exports][imports]
    data = bytes(d[:sp])
    pad = (-len(data)) % 16
    data += b"\0" * pad
    loc = b"".join(struct.pack(be + "II", s, t) for s, t in local) + b"\xff" * 8
    glo = b"\xff" * 12
    vir = b"".join(struct.pack(be + "III", o, 0, off[n]) for o, n in virt) + b"\xff" * 12
    sec1 = data + loc
    # section layout
    hdr = struct.pack(be + "II", MAGIC0, MAGIC1) + struct.pack(be + "ii", 0, 4) + bytes([4, 0, 1, 1])
    hdr += struct.pack(be + "5i", 2, 1, 0, 0, off["hkRootLevelContainer"])
    hdr += b"Havok-5.5.0-r1\0\0" + struct.pack(be + "ii", 0, 0)
    # classnames section: data = names, no fixups
    cn_start = 0x40 + 0x30 * 2
    cn_len = len(names)
    cn_end = cn_start + cn_len
    d_start = (cn_end + 15) & ~15
    local_o = len(data)
    glob_o = local_o + len(loc)
    virt_o = glob_o + len(glo)
    exp_o = virt_o + len(vir)
    end_o = exp_o
    s0 = b"__classnames__".ljust(19, b"\0") + b"\xff" + struct.pack(be + "7I", cn_start, cn_len, cn_len, cn_len, cn_len, cn_len, cn_len)
    s1 = b"__data__".ljust(19, b"\0") + b"\xff" + struct.pack(be + "7I", d_start, local_o, glob_o, virt_o, exp_o, exp_o, end_o)
    out = bytearray(hdr + s0 + s1)
    assert len(out) == cn_start
    out += names
    out += b"\0" * (d_start - len(out))
    out += data + loc + glo + vir
    return bytes(out)


def selftest():
    pf = Packfile(_build_test_packfile())
    classes = load_classes()
    assert pf.contents_version == "Havok-5.5.0-r1", pf.contents_version
    root = decode_contents(pf, classes)
    cont = find_in_root_container(root, "hkaAnimationContainer")
    assert cont is not None and cont["skeletons"], cont
    sk = cont["skeletons"][0]
    assert sk["name"] == "Root_Skeleton" and sk["parentIndices"] == [-1, 0]
    assert [b["name"] for b in sk["bones"]] == ["pelvis", "spine"]
    assert sk["referencePose"][1][1] == 2.0
    print("selftest OK:", json.dumps(sk)[:160], "...")


def main(argv):
    if len(argv) < 2:
        print(__doc__)
        return 2
    cmd = argv[1]
    if cmd == "selftest":
        selftest()
        return 0
    data = open(argv[2], "rb").read()
    pf = Packfile(data)
    if cmd == "info":
        print("version=%s fileVersion=%d layout=%s sections=%d contents=(%d,0x%x) userTag=%d flags=%d" % (
            pf.contents_version, pf.file_version, pf.layout, pf.num_sections, pf.contents_section,
            pf.contents_offset, pf.user_tag, pf.flags))
        for s in pf.sections:
            print(" section %-16s start=0x%x data=0x%x local=0x%x glob=0x%x virt=0x%x exp=0x%x imp=0x%x end=0x%x" % (
                s["tag"], s["start"], s["local"], s["local"], s["glob"], s["virt"], s["exports"], s["imports"], s["end"]))
        print(" pointer fixups:", len(pf.ptr), "virtual (typed objects):", len(pf.virt))
        for s, o, c in pf.objects():
            print("  obj sec%d+0x%x %s" % (s, o, c))
        return 0
    if cmd == "json":
        root_class = argv[argv.index("--root") + 1] if "--root" in argv else None
        print(json.dumps(decode_contents(pf, load_classes(), root_class), indent=1))
        return 0
    print(__doc__)
    return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv))
