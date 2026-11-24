#!/usr/bin/env python3
"""Reflection-driven object reader for Havok 5.5 packfiles (Top Spin 4, Xbox 360).

This module contains code only. Class layouts come from two places at run time:
  * the packfile's own __types__ section (hkClass / hkClassMember / hkClassEnum objects),
    when the file carries one (the game's physics files do);
  * work/havok/classes.json, generated locally from the user's own Swing_DLL by
    `python3 tools/havok/dll_classes.py orig/54540859/Swing_DLL.dll`. The animation
    files have an empty __types__ section, so they need this file. It is derived from
    the Havok runtime's reflection data and must never be committed.
Set HAVOK_CLASSES=/path/to/classes.json to use another location.

Record layouts of the reflection objects, as measured in the game's __types__ sections:
  hkClass (0x30):        +00 name*, +04 parent*, +08 objectSize, +0C numInterfaces,
                         +10 enums*, +14 numEnums, +18 members*, +1C numMembers,
                         +20 defaults*, +24 attributes*, +28 flags, +2C describedVersion
  hkClassMember (0x18):  +00 name*, +04 class*, +08 enum*, +0C u8 type, +0D u8 subtype,
                         +0E s16 cArraySize, +10 u16 flags, +12 u16 offset, +14 attributes*
  hkClassEnum (0x14):    +00 name*, +04 items*, +08 numItems, +0C attributes*, +10 flags
  hkClassEnumItem (0x8): +00 s32 value, +04 name*
"""
import json
import os
import struct

DEFAULT_JSON = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "work", "havok", "classes.json")

# hkClassMember::Type codes as observed (cross-checked by member offsets / names).
T = dict(VOID=0, BOOL=1, CHAR=2, INT8=3, UINT8=4, INT16=5, UINT16=6, INT32=7, UINT32=8,
         INT64=9, UINT64=10, REAL=11, VECTOR4=12, QUATERNION=13, MATRIX3=14, ROTATION=15,
         QSTRANSFORM=16, MATRIX4=17, TRANSFORM=18, ZERO=19, POINTER=20, FUNCTIONPOINTER=21,
         ARRAY=22, INPLACEARRAY=23, ENUM=24, STRUCT=25, SIMPLEARRAY=26,
         HOMOGENEOUSARRAY=27, VARIANT=28, CSTRING=29, ULONG=30, FLAGS=31)
TN = {v: k for k, v in T.items()}

SCALAR = {  # type -> (struct code, size)
    T["BOOL"]: ("B", 1), T["CHAR"]: ("b", 1), T["INT8"]: ("b", 1), T["UINT8"]: ("B", 1),
    T["INT16"]: ("h", 2), T["UINT16"]: ("H", 2), T["INT32"]: ("i", 4), T["UINT32"]: ("I", 4),
    T["INT64"]: ("q", 8), T["UINT64"]: ("Q", 8), T["REAL"]: ("f", 4), T["ULONG"]: ("I", 4),
}
NFLOATS = {T["VECTOR4"]: 4, T["QUATERNION"]: 4, T["MATRIX3"]: 12, T["ROTATION"]: 12,
           T["QSTRANSFORM"]: 12, T["MATRIX4"]: 16, T["TRANSFORM"]: 16}
PTR_SIZE = 4


class Member:
    __slots__ = ("name", "type", "subtype", "carray", "flags", "offset", "cls", "enum")

    def __init__(self, name, type_, subtype, offset, cls=None, enum=None, carray=0, flags=0):
        self.name, self.type, self.subtype, self.offset = name, type_, subtype, offset
        self.cls, self.enum, self.carray, self.flags = cls, enum, carray, flags

    def __repr__(self):
        s = "%s %s" % (TN.get(self.type, self.type), TN.get(self.subtype, self.subtype))
        return "+0x%02X %-32s %s%s" % (self.offset, self.name, s, (" <%s>" % self.cls) if self.cls else "")


class ClassDef:
    def __init__(self, name, size, parent, members, enums=None, signature=None):
        self.name, self.size, self.parent, self.members = name, size, parent, members
        self.enums = enums or {}
        self.signature = signature



class MissingClasses(RuntimeError):
    pass


def load_json(path=None):
    """Load class layouts written by tools/havok/dll_classes.py -> {name: ClassDef}."""
    path = path or os.environ.get("HAVOK_CLASSES") or DEFAULT_JSON
    if not os.path.exists(path):
        raise MissingClasses(
            "Havok class layouts not found at %s.\nThey are generated locally from your own "
            "game executable and are not part of the repository; run:\n"
            "  python3 tools/havok/dll_classes.py orig/54540859/Swing_DLL.dll" % os.path.normpath(path))
    with open(path) as f:
        data = json.load(f)
    return from_dict(data["classes"])


def from_dict(table):
    """{name: {size, parent, members: [{name,type,subtype,offset,cls,enum,carray,flags}], enums}}."""
    out = {}
    for name, c in table.items():
        members = [Member(m["name"], m["type"], m.get("subtype", 0), m["offset"], m.get("cls"), m.get("enum"),
                          m.get("carray", 0), m.get("flags", 0)) for m in c.get("members", [])]
        enums = {en: {int(k): v for k, v in items.items()} for en, items in c.get("enums", {}).items()}
        out[name] = ClassDef(name, c["size"], c.get("parent"), members, enums)
    return out


class Registry:
    """Class table used to decode objects. `classes` defaults to work/havok/classes.json;
    the packfile's own __types__ (if any) are added on top."""

    def __init__(self, classes=None):
        self.classes = dict(classes) if classes is not None else {}
        self.reflected = set()

    @classmethod
    def from_packfile(cls, pf, classes=None):
        r = cls(classes)
        r.load_types(pf)
        if classes is None:
            needed = set(pf.obj_class.values()) - set(r.classes) - {"hkClass", "hkClassMember", "hkClassEnum"}
            if needed:
                for k, v in load_json().items():
                    r.classes.setdefault(k, v)
        return r

    def load_types(self, pf):
        """Read hkClass objects from the packfile's __types__ section into the table."""
        for (s, o) in pf.objects("hkClass"):
            name = pf.string_ptr(s, o)
            par = pf.ptr(s, o + 0x4)
            parent = pf.string_ptr(*par) if par else None
            size = pf.u32(s, o + 0x8)
            enums = {}
            ep, ne = pf.ptr(s, o + 0x10), pf.u32(s, o + 0x14)
            for i in range(ne if ep else 0):
                es, eo = ep[0], ep[1] + 0x14 * i
                en = pf.string_ptr(es, eo)
                ip, ni = pf.ptr(es, eo + 4), pf.u32(es, eo + 8)
                items = {}
                for j in range(ni if ip else 0):
                    items[pf.s32(ip[0], ip[1] + 8 * j)] = pf.string_ptr(ip[0], ip[1] + 8 * j + 4)
                enums[en] = items
            members = []
            mp, nm = pf.ptr(s, o + 0x18), pf.u32(s, o + 0x1C)
            for i in range(nm if mp else 0):
                ms, mo = mp[0], mp[1] + 0x18 * i
                mc, me = pf.ptr(ms, mo + 4), pf.ptr(ms, mo + 8)
                members.append(Member(
                    pf.string_ptr(ms, mo), pf.u8(ms, mo + 0xC), pf.u8(ms, mo + 0xD), pf.u16(ms, mo + 0x12),
                    pf.string_ptr(*mc) if mc else None,
                    pf.string_ptr(*me) if me else None,
                    pf.s16(ms, mo + 0xE), pf.u16(ms, mo + 0x10)))
            self.classes[name] = ClassDef(name, size, parent, members, enums)
            self.reflected.add(name)

    def get(self, name):
        return self.classes.get(name)

    def all_members(self, name):
        """Members of a class including inherited ones (parents first)."""
        out = []
        c = self.classes.get(name)
        chain = []
        while c is not None:
            chain.append(c)
            c = self.classes.get(c.parent) if c.parent else None
        for c in reversed(chain):
            out.extend(c.members)
        return out

    def find_enum(self, name, enum):
        c = self.classes.get(name)
        while c is not None:
            if enum in c.enums:
                return c.enums[enum]
            c = self.classes.get(c.parent) if c.parent else None
        for c in self.classes.values():
            if enum in c.enums:
                return c.enums[enum]
        return None

    # --- generic object reader ---------------------------------------------
    def elem_size(self, t, cls=None, sub=0):
        if t in SCALAR:
            return SCALAR[t][1]
        if t in NFLOATS:
            return 4 * NFLOATS[t]
        if t in (T["POINTER"], T["CSTRING"], T["FUNCTIONPOINTER"]):
            return PTR_SIZE
        if t == T["STRUCT"]:
            return self.classes[cls].size
        if t == T["ENUM"] or t == T["FLAGS"]:
            return SCALAR[sub][1]
        if t == T["SIMPLEARRAY"] or t == T["VARIANT"]:
            return 8
        if t in (T["ARRAY"], T["HOMOGENEOUSARRAY"]):
            return 12
        raise ValueError("size of type %s" % TN.get(t, t))

    def read_value(self, pf, sec, off, t, sub, cls, enum=None, owner=None, depth=0):
        if t in SCALAR:
            code, size = SCALAR[t]
            return struct.unpack_from(pf.e + code, pf.data, pf.abs(sec, off))[0]
        if t in NFLOATS:
            return pf.floats(sec, off, NFLOATS[t])
        if t == T["CSTRING"]:
            return pf.string_ptr(sec, off)
        if t == T["ENUM"] or t == T["FLAGS"]:
            v = self.read_value(pf, sec, off, sub, 0, None)
            if enum and owner and t == T["ENUM"]:
                names = self.find_enum(owner, enum)
                if names and v in names:
                    return names[v]
            return v
        if t == T["POINTER"]:
            tgt = pf.ptr(sec, off)
            if tgt is None:
                return None
            return ObjRef(pf, self, tgt[0], tgt[1], pf.obj_class.get(tgt, cls))
        if t == T["STRUCT"]:
            return self.read_object(pf, sec, off, cls, depth + 1)
        if t == T["VARIANT"]:
            tgt = pf.ptr(sec, off)
            return None if tgt is None else ObjRef(pf, self, tgt[0], tgt[1], pf.obj_class.get(tgt))
        if t == T["SIMPLEARRAY"]:
            n = pf.u32(sec, off + PTR_SIZE)
            tgt = pf.ptr(sec, off)
            if tgt is None or n == 0:
                return []
            es = self.elem_size(sub, cls, 0)
            return [self.read_value(pf, tgt[0], tgt[1] + es * i, sub, 0, cls, depth=depth) for i in range(n)]
        if t == T["ARRAY"]:
            n = pf.u32(sec, off + PTR_SIZE)
            tgt = pf.ptr(sec, off)
            if tgt is None or n == 0:
                return []
            es = self.elem_size(sub, cls, 0)
            return [self.read_value(pf, tgt[0], tgt[1] + es * i, sub, 0, cls, depth=depth) for i in range(n)]
        return "<%s>" % TN.get(t, t)

    def read_object(self, pf, sec, off, cls_name, depth=0):
        if cls_name not in self.classes:
            return {"__class__": cls_name, "__unknown__": True}
        d = {"__class__": cls_name, "__loc__": (sec, off)}
        for m in self.all_members(cls_name):
            if m.flags & 1024:  # SERIALIZE_IGNORED
                continue
            if m.carray:
                es = self.elem_size(m.type, m.cls, m.subtype)
                d[m.name] = [self.read_value(pf, sec, off + m.offset + i * es, m.type, m.subtype, m.cls,
                                             m.enum, cls_name, depth) for i in range(m.carray)]
            else:
                d[m.name] = self.read_value(pf, sec, off + m.offset, m.type, m.subtype, m.cls,
                                            m.enum, cls_name, depth)
        return d


class ObjRef:
    """Lazy pointer to an object in a packfile."""

    def __init__(self, pf, reg, sec, off, cls):
        self.pf, self.reg, self.sec, self.off, self.cls = pf, reg, sec, off, cls
        self._v = None

    def get(self):
        if self._v is None:
            self._v = self.reg.read_object(self.pf, self.sec, self.off, self.cls)
        return self._v

    def __getitem__(self, k):
        return self.get()[k]

    def __repr__(self):
        return "<%s @%d:0x%X>" % (self.cls, self.sec, self.off)
