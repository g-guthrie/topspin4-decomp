#!/usr/bin/env python3
"""Field-name helpers over the Layoutall.bin type table (thin wrapper around ``ts4_xbin.Layout``).

``tools/ts4_xbin.py`` (agent G5) holds the Layoutall.bin parser; this module only adapts its
``Layout.types`` into ``TypeInfo``/``Field`` objects and adds the two helpers the analyser
binding code needs: ``resolve`` (byte offset -> member chain) and ``walk`` (visit every primitive
member of a struct in a data XBin, following lists).  Grammar summary, as decoded in ts4_xbin:

    type record (0x40 bytes, array at file +0x20): primitive chain {rel,n,n} at +0x18,
    member chain {rel,m,m} at +0x24, type crc, size, align at +0x30..
    primitive row (7 words)  [next_type, next_flags, next_name, OFFSET, TYPE, NAME, SIZE]
    member row (9 words)     [next_type, next_flags, next_name, rel, KIND, NAME, OFFSET, ALIGN, 0]
    KIND 0xD543463B inline struct, 0x33F5AD9F list {rel,count,cap}, 0x6D866019 pointer,
    0xAAB84325 reference.  A member row's TYPE is carried by the previous row (chain words).

Checked against code-verified offsets (PlayerState +0x64C..0x668 = Serve..Stamina, +0x71C let
chance, +0xF20 Fatigue, State root arrays at +0xE80/+0xE8C/+0xE98/+0xF58).  Big-endian throughout.
"""
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ts4_xbin as X  # noqa: E402

KIND_STRUCT = X.KIND_INLINE
KIND_LIST = X.KIND_LIST
KINDS = (X.KIND_INLINE, X.KIND_LIST, X.KIND_PTR, X.KIND_REF)


class Field:
    __slots__ = ("name", "offset", "type", "size", "prim", "kind")

    def __init__(self, name, offset, type_, size, prim, kind=None):
        self.name, self.offset, self.type, self.size, self.prim, self.kind = name, offset, type_, size, prim, kind

    def is_list(self):
        return self.kind == KIND_LIST

    def __repr__(self):
        return "Field(%08x @0x%x type %08x%s)" % (self.name, self.offset, self.type, " list" if self.is_list() else "")


class TypeInfo:
    __slots__ = ("crc", "size", "align", "fields")

    def __init__(self, crc, size, align, fields):
        self.crc, self.size, self.align, self.fields = crc, size, align, fields


def parse_layout(buf):
    """{type crc: TypeInfo} for every type record of a Layoutall.bin image (via ts4_xbin.Layout)."""
    lay = X.Layout(buf)
    types = {}
    for tc, (size, align, members) in lay.types.items():
        fields = [Field(m.name, m.offset, m.type, m.size, bool(m.attr), m.kind) for m in members]
        fields.sort(key=lambda f: f.offset)
        types[tc] = TypeInfo(tc, size, align, fields)
    return types


def field_by_name(types, type_crc, name):
    for f in types[type_crc].fields:
        if f.name == name:
            return f
    raise KeyError("type %08x has no member %08x" % (type_crc, name))


def resolve(types, type_crc, offset, depth=0):
    """Member chain [(Field, absolute offset of the member)] from ``type_crc`` down to the member
    that contains byte ``offset``.  Lists are not entered (their payload lives elsewhere)."""
    t = types.get(type_crc)
    if t is None or depth > 16 or offset < 0 or offset >= t.size:
        return []
    best = None
    for f in t.fields:
        if f.offset <= offset:
            best = f
    if best is None:
        return []
    chain = [(best, best.offset)]
    if not best.prim and best.kind == KIND_STRUCT:
        for f, o in resolve(types, best.type, offset - best.offset, depth + 1):
            chain.append((f, o + best.offset))
    return chain


def walk(types, buf, type_crc, addr, visit, path=(), depth=0):
    """Visit every primitive member of the struct at ``addr`` (lists are followed).

    ``visit(path, address, field)`` gets the member-name path (list elements appear as strings in
    brackets, e.g. ``"[3]"``).  Lists whose element type has no record are read as polymorphic
    8-byte links ``{rel, type}`` and the first word of each target is visited."""
    t = types.get(type_crc)
    if t is None or depth > 48:
        return
    for f in t.fields:
        a = addr + f.offset
        p = path + (f.name,)
        if f.prim:
            if a + 4 <= len(buf):
                visit(p, a, f)
            continue
        if f.is_list():
            if a + 12 > len(buf):
                continue
            rel, cnt = struct.unpack_from(">iI", buf, a)
            if rel == -1 or cnt == 0 or cnt > 1 << 20:
                continue
            et = types.get(f.type)
            for k in range(cnt):
                if et is None:
                    # element type without a record: polymorphic 8-byte links {s32 rel, u32 type};
                    # visit the first word of each linked node
                    e = a + rel + 8 * k
                    if e + 8 > len(buf):
                        break
                    r2 = struct.unpack_from(">i", buf, e)[0]
                    if r2 != -1 and 0 <= e + r2 <= len(buf) - 4:
                        visit(p + ("[%d]" % k,), e + r2, f)
                else:
                    walk(types, buf, f.type, a + rel + k * et.size, visit, p + ("[%d]" % k,), depth + 1)
        elif f.kind == KIND_STRUCT:
            walk(types, buf, f.type, a, visit, p, depth + 1)


def xbin_root(buf):
    """File offset of the typed root struct of a generic data-tree XBin (``State.bin`` etc.) and its type."""
    rel, typ = struct.unpack_from(">iI", buf, 0x14)
    return 0x14 + rel, typ


def main():
    import argparse
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("layout", help="Layoutall.bin")
    ap.add_argument("types", nargs="*", help="type crcs (hex) to print")
    a = ap.parse_args()
    types = parse_layout(open(a.layout, "rb").read())
    print("%d types" % len(types))
    for h in a.types:
        t = types.get(int(h, 16))
        if t is None:
            print("%s: not found" % h)
            continue
        print("%08x size 0x%x align %d" % (t.crc, t.size, t.align))
        for f in t.fields:
            print("  +0x%04x %08x type %08x %s" % (f.offset, f.name, f.type,
                                                   "prim" if f.prim else ("list" if f.is_list() else "struct")))
    return 0


if __name__ == "__main__":
    sys.exit(main())
