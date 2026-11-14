#!/usr/bin/env python3
"""Readers for the Pam engine "XBin" binary data format (decoded from the retail disc).

An XBin file is a relocatable memory image.  All integers are big-endian.

  0x00 u32 a, u32 b     8-byte signature; b is the CRC-32 of the root type name
                        (zlib.crc32 of e.g. "Pam::SwingAnimation::AnimationDB::AnimationDB")
  0x08 u32 version      4 for most files, 0x10 for the swing animation database
  0x0C u32 0
  0x10 u32 0xFFFFFFFF
  0x14 ...              the root structure image; layout of the fields is given by the
                        layout file (Layoutall.bin).

Conventions inside the image:
  * array descriptor: 12 bytes (u32 rel, u32 count, u32 capacity); the elements start at
    (address of the descriptor) + rel;
  * string/object pointers are likewise self-relative;
  * names are CRC-32 keys resolved through CRC dictionary files.

The CRC dictionary type (root type Pam::XBinData::CCRCDictionnaryXBinType) is fully decoded:
root descriptor at 0x14 -> `count` entries of (u32 rel_to_string, u32 crc32(string)).

Layoutall.bin is itself an XBin.  Decoded parts: a table of 8-byte pairs at 0x34
(layout id, root type crc) sorted by type crc, and 9-word field descriptors
(see `read_fields`).  The full type-record grammar is only partly understood.
"""
import argparse
import json
import struct
import sys
import zlib

SIG_VERSION_OFF = 8
ROOT_OFF = 0x14


def crc(name):
    """Engine string key: standard CRC-32 (zlib) of the bytes."""
    if isinstance(name, str):
        name = name.encode("latin-1")
    return zlib.crc32(name) & 0xFFFFFFFF


def parse_header(buf):
    if len(buf) < 0x14 or buf[0x10:0x14] != b"\xff\xff\xff\xff":
        raise ValueError("not an XBin image")
    a, b, ver, zero = struct.unpack_from(">4I", buf, 0)
    return dict(sig_a=a, root_type=b, version=ver, zero=zero)


def read_array_desc(buf, pos):
    """Array descriptor at pos -> (abs_offset, count, capacity)."""
    rel, count, cap = struct.unpack_from(">III", buf, pos)
    return pos + rel, count, cap


def read_cstring(buf, pos):
    end = buf.index(b"\x00", pos)
    return buf[pos:end]


def read_crc_dictionary(buf, verify=True):
    """Decode a CRC dictionary XBin -> {crc32: str}.  Raises ValueError if it is not one."""
    parse_header(buf)
    start, count, cap = read_array_desc(buf, ROOT_OFF)
    if count != cap or start != 0x20 or start + 8 * count > len(buf):
        raise ValueError("not a CRC dictionary")
    out = {}
    for i in range(count):
        p = start + 8 * i
        rel, key = struct.unpack_from(">II", buf, p)
        try:
            raw = read_cstring(buf, p + rel)
        except ValueError:
            raise ValueError("bad string pointer")
        if verify and crc(raw) != key:
            raise ValueError("crc mismatch in entry %d" % i)
        out[key] = raw.decode("latin-1")
    return out


def read_layout_pairs(layout):
    """Layoutall.bin root table -> list of (layout_id, root_type_crc), sorted by type crc."""
    start, count, cap = read_array_desc(layout, ROOT_OFF)
    return [struct.unpack_from(">II", layout, start + 8 * i) for i in range(count)]


def read_fields(layout, pos, count):
    """Decode `count` 9-word field descriptors at pos.

    word: 0 type crc, 1 flags (0x40000 single, 0x80000 struct, 0xC0000 list, 0x180000 pair),
    2 name crc, 3 ordinal key, 4 kind hash (0xD543463B for the common case),
    5 name crc of the previous field, 6 byte offset inside the parent structure,
    7 alignment, 8 reserved.
    """
    out = []
    for i in range(count):
        w = struct.unpack_from(">9I", layout, pos + 36 * i)
        out.append(dict(type=w[0], flags=w[1], name=w[2], key=w[3], kind=w[4], prev=w[5],
                        offset=w[6], align=w[7]))
    return out


def find_field_array(layout, type_crc):
    """Locate the field array of a nested type via its 9-word record
    [type, 0, short-name crc, 0, 0, 0, rel, count, cap].  Returns (abs, count) or None."""
    pat = struct.pack(">I", type_crc)
    i = 0x34
    while True:
        i = layout.find(pat, i)
        if i < 0:
            return None
        if i % 4 == 0 and i + 36 <= len(layout):
            w = struct.unpack_from(">9I", layout, i)
            if w[1] == 0 and w[3] == 0 and w[4] == 0 and w[5] == 0 and w[7] == w[8] and 0 < w[7] < 4096:
                a = i + 24 + w[6]
                if 0 <= a < len(layout):
                    return a, w[7]
        i += 4


def describe_root(buf, layout, type_crc, names=None):
    """Describe the top-level arrays of an instance whose root fields are listed under
    `type_crc` (e.g. the AnimationDB 'Parameters' record).  Returns a list of dicts."""
    names = names or {}
    loc = find_field_array(layout, type_crc)
    if loc is None:
        raise KeyError("no field array for %08x" % type_crc)
    fields = read_fields(layout, loc[0], loc[1])
    out = []
    for f in fields:
        p = ROOT_OFF + f["offset"]
        ent = dict(name=names.get(f["name"], "%08x" % f["name"]), type=names.get(f["type"], "%08x" % f["type"]),
                   flags=f["flags"], offset=f["offset"])
        if f["flags"] in (0xC0000, 0x180000):
            a, n, c = read_array_desc(buf, p)
            ent.update(abs=a, count=n, capacity=c)
        else:
            ent["words"] = list(struct.unpack_from(">2I", buf, p))
        out.append(ent)
    return out



# ---------------------------------------------------------------------------------------------
# Generic typed walker (agent G5).  Layoutall.bin (disc root, itself an XBin) describes every
# type the engine serialises.  Decoded from the retail file (V = verified by walking real data):
#
#   0x14 array<(layout id, root type crc), 8>        403 entries, sorted by type crc
#   0x20 array<TypeRecord, 0x40>                     3,642 entries, sorted by type crc
#   TypeRecord (0x40):
#     +0x00 u32 first_attr_type, u32 first_attr_flags, u32 first_attr_name
#     +0x0C u32 first_elem_type, u32 first_elem_flags, u32 first_elem_name
#     +0x18 array<AttrRec, 0x1C>   attributes (scalar members)
#     +0x24 array<ElemRec, 0x24>   elements (struct / list / pointer members)
#     +0x30 u32 type crc, +0x34 u32 size, +0x38 u32 align, +0x3C u32 attribute count
#   The member descriptors are a chain: record k holds the *next* member's (type, flags, name)
#   in words 0..2 and its own offset (and, for attributes, its own type/name/byte size) in the
#   remaining words; the first member's (type, flags, name) is in the TypeRecord header.
#     AttrRec: next_type, next_flags, next_name, offset, type, name, byte_size
#     ElemRec: next_type, next_flags, next_name, key, kind, name, offset, align, reserved
#   Element kinds (crc):  0xD543463B inline struct, 0x33F5AD9F list {s32 rel,u32 count,u32 cap},
#     0x6D866019 4-byte self-relative pointer to one object of the member type,
#     0xAAB84325 8-byte polymorphic reference {s32 rel, u32 type crc}.
#   Member type 0xAAB84325 = polymorphic element: each slot is {s32 rel, u32 type crc}.
#   Every rel is relative to the address of the field (or list descriptor) that holds it.
#   Generic data-tree files (Settings/State/Module/Expressions.bin, header word 1 = 0xD2968089)
#   start with a polymorphic reference at 0x14.  Other files (PlayerSetup, PlayerAnimData) have
#   their root type in header word 1 and the root struct at 0x14.
# ---------------------------------------------------------------------------------------------

KIND_INLINE = 0xD543463B
KIND_LIST = 0x33F5AD9F
KIND_PTR = 0x6D866019
KIND_REF = 0xAAB84325
TYPE_REF = 0xAAB84325
TYPE_ANY = 0x80E55C7B          # Pam::XBinData::CAny: 12 bytes {s32 rel, u32 type, u32 class key} (V)
REF_TYPES = (TYPE_REF, TYPE_ANY)
GENERIC_TREE_ROOT = 0xD2968089

# primitive attribute types: crc -> (tag, struct code, element size)
PRIMS = {}
for _n, _tag, _code, _sz in [
        ("Pam::System::Boolean", "bool", ">B", 1), ("Pam::System::CKey", "key", ">I", 4),
        ("Pam::System::Single", "float", ">f", 4), ("Pam::System::Int32", "int", ">i", 4),
        ("Pam::System::UInt32", "uint", ">I", 4), ("Pam::System::UInt8", "u8", ">B", 1),
        ("Pam::System::Int8", "s8", ">b", 1), ("Pam::System::UInt16", "u16", ">H", 2),
        ("Pam::System::Int16", "s16", ">h", 2), ("Pam::System::UInt64", "u64", ">Q", 8),
        ("Pam::System::Char", "char", ">B", 1), ("Pam::System::WChar", "wchar", ">B", 1),
        ("Pam::System::Pointer", "rel", ">i", 4), ("Pam::XBinData::CString", "string", ">i", 4),
        ("Pam::XBinData::CFormattedString", "raw", ">B", 1),
        ("Pam::XBinData::CSingleNodeXBinPath", "path", ">i", 4),
        ("Pam::XBinData::COfflineSingleNodeXBinPath", "path", ">i", 4),
        ("Pam::XBinData::CXBinPath", "path", ">i", 4),
        ("Pam::XBinData::COfflineRelativeXBinPath", "path", ">i", 4),
        ("Pam::XBinData::CStringW", "rel", ">i", 4)]:
    PRIMS[crc(_n)] = (_tag, _code, _sz)
# fixed-size math structs used as elements (all float components)
VEC_TYPES = {crc("Pam::Math::C3DVector"): 3, crc("Pam::Math::C3DVectorA"): 4, crc("Pam::Math::CQuat"): 4,
             crc("Pam::Math::CMatrix"): 16}
TYPE_NAMES = {crc(n): n for n in [
    "Pam::System::Boolean", "Pam::System::CKey", "Pam::System::Single", "Pam::System::Int32",
    "Pam::System::UInt32", "Pam::System::UInt8", "Pam::System::Int8", "Pam::System::UInt16",
    "Pam::System::Int16", "Pam::System::UInt64", "Pam::System::Char", "Pam::System::WChar",
    "Pam::System::Pointer", "Pam::XBinData::CString", "Pam::XBinData::CFormattedString",
    "Pam::XBinData::CSingleNodeXBinPath", "Pam::XBinData::COfflineSingleNodeXBinPath",
    "Pam::XBinData::CXBinPath", "Pam::XBinData::COfflineRelativeXBinPath", "Pam::XBinData::CStringW",
    "Pam::Math::C3DVector", "Pam::Math::C3DVectorA", "Pam::Math::CQuat", "Pam::Math::CMatrix"]}


class Member:
    __slots__ = ("name", "type", "flags", "offset", "size", "kind", "key", "attr")

    def __init__(self, name, type_, flags, offset, size, kind, key, attr):
        self.name, self.type, self.flags, self.offset = name, type_, flags, offset
        self.size, self.kind, self.key, self.attr = size, kind, key, attr


class Layout:
    """All type definitions of a Layoutall.bin image: {type crc: (size, align, [Member...])}."""

    def __init__(self, buf):
        parse_header(buf)
        self.pairs = read_layout_pairs(buf)
        start, count, _cap = read_array_desc(buf, 0x20)
        self.types = {}
        for i in range(count):
            o = start + 0x40 * i
            w = struct.unpack_from(">16I", buf, o)
            tc = w[12]
            members = []
            cur = w[0:3]
            a0 = o + 0x18 + w[6]
            for j in range(w[7]):
                r = struct.unpack_from(">7I", buf, a0 + 28 * j)
                members.append(Member(r[5], r[4], cur[1], r[3], r[6], None, None, True))
                cur = r[0:3]
            cur = w[3:6]
            e0 = o + 0x24 + w[9]
            for j in range(w[10]):
                r = struct.unpack_from(">9I", buf, e0 + 36 * j)
                members.append(Member(r[5], cur[0], cur[1], r[6], None, r[4], r[3], False))
                cur = r[0:3]
            members = [m for m in members if m.type or m.name]
            members.sort(key=lambda m: (m.offset, not m.attr))
            self.types[tc] = (w[13], w[14], members)
        # element sizes: from the type table, else from the gap to the next member
        for tc, (size, _al, members) in self.types.items():
            ends = [m.offset for m in members] + [size]
            for k, m in enumerate(members):
                if m.size is None:
                    nxt = min([e for e in ends[k + 1:] if e > m.offset] or [size])
                    m.size = nxt - m.offset

    def size_of(self, tc):
        t = self.types.get(tc)
        if t:
            return t[0]
        if tc in VEC_TYPES:
            return 4 * VEC_TYPES[tc]
        if tc in PRIMS:
            return PRIMS[tc][2]
        if tc == TYPE_ANY:
            return 12
        if tc == TYPE_REF:
            return 8
        return None


class Leaf:
    """One scalar value found by the walker."""
    __slots__ = ("path", "offset", "tag", "code", "value", "type", "owner")

    def __init__(self, path, offset, tag, code, value, type_, owner):
        self.path, self.offset, self.tag, self.code = path, offset, tag, code
        self.value, self.type, self.owner = value, type_, owner


class Walker:
    """Follow every typed member of an XBin image and yield scalar leaves.

    `names` maps crc -> string (unknown hashes print as 8 hex digits).  Each object is visited
    once (keyed by (offset, type)), so shared sub-objects appear under their first path only;
    `self.refs` records later references as (path, offset, type).
    """

    def __init__(self, buf, layout, names=None, max_list=100000):
        self.buf, self.lay, self.names = buf, layout, names or {}
        self.max_list = max_list
        self.seen = {}
        self.refs = []
        self.unknown_types = set()
        self.leaves = []
        self.objects = []          # (path, offset, type crc)

    def n(self, h):
        return self.names.get(h) or "%08x" % h

    def u32(self, o):
        return struct.unpack_from(">I", self.buf, o)[0]

    def s32(self, o):
        return struct.unpack_from(">i", self.buf, o)[0]

    def ok(self, o, size=1):
        return 0 <= o and o + size <= len(self.buf)

    def walk_file(self):
        h = parse_header(self.buf)
        if h["root_type"] == GENERIC_TREE_ROOT:
            self.walk_ref(ROOT_OFF, "")
        else:
            self.walk_struct(ROOT_OFF, h["root_type"], "")
        return self.leaves

    def walk_ref(self, o, path):
        rel, tc = struct.unpack_from(">iI", self.buf, o)
        if rel in (0, -1) or tc == 0:
            return
        self.walk_struct(o + rel, tc, path + "<%s>" % self.n(tc))

    def walk_struct(self, o, tc, path):
        size = self.lay.size_of(tc)
        if size is None or not self.ok(o, max(size, 1)):
            self.unknown_types.add(tc)
            return
        key = (o, tc)
        if key in self.seen:
            self.refs.append((path, o, tc))
            return
        self.seen[key] = path
        if tc in VEC_TYPES:
            for i in range(VEC_TYPES[tc]):
                self.leaf("%s[%d]" % (path, i), o + 4 * i, "float", ">f", tc, tc)
            return
        if tc in PRIMS:
            self.prim(path, o, tc, PRIMS[tc][2], tc)
            return
        if tc in REF_TYPES:
            del self.seen[key]
            self.walk_ref(o, path)
            return
        if tc not in self.lay.types:
            self.unknown_types.add(tc)
            return
        self.objects.append((path, o, tc))
        for m in self.lay.types[tc][2]:
            p = (path + "/" if path else "") + self.n(m.name)
            fo = o + m.offset
            if m.attr:
                self.prim(p, fo, m.type, m.size, tc)
            elif m.type in REF_TYPES and m.kind in (KIND_REF, KIND_INLINE):
                self.walk_ref(fo, p)
            elif m.kind == KIND_INLINE:
                self.walk_struct(fo, m.type, p)
            elif m.kind == KIND_LIST:
                self.walk_list(fo, m.type, p)
            elif m.kind == KIND_PTR:
                rel = self.s32(fo)
                if rel not in (0, -1):
                    self.walk_struct(fo + rel, m.type, p)
            elif m.kind == KIND_REF:
                self.walk_ref(fo, p)

    def walk_list(self, o, tc, path):
        rel, count, cap = struct.unpack_from(">iII", self.buf, o)
        if rel == -1 or count == 0 or count > self.max_list:
            return
        base = o + rel
        if tc in REF_TYPES:
            st = 12 if tc == TYPE_ANY else 8
            for i in range(count):
                if self.ok(base + st * i, st):
                    self.walk_ref(base + st * i, "%s[%d]" % (path, i))
            return
        stride = self.lay.size_of(tc)
        if not stride:
            self.unknown_types.add(tc)
            return
        for i in range(count):
            self.walk_struct(base + stride * i, tc, "%s[%d]" % (path, i))

    def prim(self, path, o, tc, size, owner):
        p = PRIMS.get(tc)
        if p is None:
            # unknown attribute type: expose raw 32-bit words (or bytes) so nothing is hidden
            if size % 4 == 0:
                for i in range(size // 4):
                    self.leaf(path if size == 4 else "%s[%d]" % (path, i), o + 4 * i, "word", ">I", tc, owner)
            else:
                for i in range(size):
                    self.leaf(path if size == 1 else "%s[%d]" % (path, i), o + i, "byte", ">B", tc, owner)
            return
        tag, code, esz = p
        if tag in ("wchar", "char", "raw") and size > esz:
            raw = self.buf[o:o + size]
            self.leaves.append(Leaf(path, o, "bytes", "%ds" % size, raw, tc, owner))
            return
        n = max(1, size // esz) if esz else 1
        for i in range(n):
            self.leaf(path if n == 1 else "%s[%d]" % (path, i), o + esz * i, tag, code, tc, owner)

    def leaf(self, path, o, tag, code, tc, owner):
        if not self.ok(o, struct.calcsize(code)):
            return
        v = struct.unpack_from(code, self.buf, o)[0]
        if tag == "float":
            v = struct.unpack(">f", struct.pack(">f", v))[0]
        lf = Leaf(path, o, tag, code, v, tc, owner)
        if tag in ("string", "path") and v not in (0, -1) and self.ok(o + v):
            try:
                lf.value = (v, read_cstring(self.buf, o + v).decode("latin-1"))
            except ValueError:
                pass
        self.leaves.append(lf)


def load_names(*paths):
    """Merge name dictionaries: JSON {hex crc: name} files or CRC-dictionary XBin images."""
    out = dict(TYPE_NAMES)
    for p in paths:
        if not p:
            continue
        data = open(p, "rb").read()
        if data[:1] in (b"{", b"["):
            d = json.loads(data)
            if isinstance(d, dict):
                vals = d.values() if all(isinstance(v, dict) for v in d.values()) else [d]
                for sub in vals:
                    for k, v in sub.items():
                        if isinstance(v, str):
                            out.setdefault(int(k, 16), v)
                        elif isinstance(v, dict) and "name" in v:
                            out.setdefault(int(k, 16), v["name"])
        else:
            out.update(read_crc_dictionary(data))
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("file")
    ap.add_argument("--info", action="store_true")
    ap.add_argument("--dict-json", metavar="OUT", help="decode as CRC dictionary and write JSON")
    ap.add_argument("--layout-pairs", action="store_true")
    a = ap.parse_args()
    buf = open(a.file, "rb").read()
    if a.info:
        h = parse_header(buf)
        print({k: "%08x" % v for k, v in h.items()})
    if a.dict_json:
        d = read_crc_dictionary(buf)
        json.dump({"%08x" % k: v for k, v in d.items()}, open(a.dict_json, "w"), indent=0)
        print(len(d), "entries")
    if a.layout_pairs:
        for lid, t in read_layout_pairs(buf):
            print("%08x %08x" % (lid, t))


if __name__ == "__main__":
    sys.exit(main())
