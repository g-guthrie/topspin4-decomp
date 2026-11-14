#!/usr/bin/env python3
"""Reader for the Pam engine type layouts in ``Layoutall.bin`` and a generic XBin walker.

``Layoutall.bin`` (an XBin on the disc root) describes the reflected C++ types that the game's
data files (``State.bin``, ``Settings.bin``, ``Expressions.bin`` ...) are laid out with.  The grammar
below was recovered empirically (agent G1, 2026-11-14) and checked against code-verified offsets
(PlayerState ``+0x64C..0x668`` = Serve..Stamina, ``+0x71C`` let chance, ``+0xF20`` Fatigue, the
State root arrays at ``+0xE80/+0xE8C/+0xE98/+0xF58``).  All integers are big-endian.

Type record (9 words)::

    {s32 rel, u32 n, u32 n}   primitive members, 7-word rows, rel from this descriptor
    {s32 rel, u32 m, u32 m}   struct/list members, 9-word rows, rel from this descriptor
    u32 type crc, u32 byte size, u32 alignment

Primitive row (7 words)  ``[t0, f0, next_name, OFFSET, TYPE, NAME, SIZE]``
Struct row (9 words)     ``[t0, SIZE<<16, next_name, rel, KIND, NAME, OFFSET, ALIGN, 0]``;
                          the member TYPE is the j-th word of the type list that follows the m rows.
``KIND`` is 0xD543463B for an embedded struct and 0x33F5AD9F for a list (a 12-byte
``{rel, count, cap}`` descriptor whose element type is the member type).

Only the parts needed to name fields are decoded; the leading words of each row (``t0``, ``f0``,
``next_name``) repeat information of the neighbouring row and are ignored.
"""
import struct
import sys

KIND_STRUCT = 0xD543463B
KIND_LIST = 0x33F5AD9F
KINDS = (KIND_STRUCT, KIND_LIST)


class Field:
    __slots__ = ("name", "offset", "type", "size", "prim", "kind")

    def __init__(self, name, offset, type_, size, prim, kind=None):
        self.name, self.offset, self.type, self.size, self.prim, self.kind = name, offset, type_, size, prim, kind

    def is_list(self):
        return self.kind == KIND_LIST

    def __repr__(self):
        return "Field(%08x @0x%x type %08x%s)" % (self.name, self.offset, self.type, " list" if self.is_list() else "")


class TypeInfo:
    __slots__ = ("crc", "size", "align", "fields", "at")

    def __init__(self, crc, size, align, fields, at):
        self.crc, self.size, self.align, self.fields, self.at = crc, size, align, fields, at


def _words(buf):
    return struct.unpack(">%dI" % (len(buf) // 4), buf[:len(buf) // 4 * 4])


def parse_layout(buf):
    """Return {type crc: TypeInfo} for every type record that decodes consistently.

    The records are found by scanning for the 9-word header; a candidate is accepted only when every
    member row is in range, every struct row carries a known kind word and no member offset lies past
    the type size.  The first consistent record of a type crc wins.
    """
    W = _words(buf)
    n = len(W)
    types = {}
    for i in range(n - 9):
        r1, c1, p1, r2, c2, p2, t, size, align = W[i:i + 9]
        if c1 != p1 or c2 != p2 or c1 > 4096 or c2 > 4096 or not (c1 or c2):
            continue
        if not (0 < size < 0x1000000) or align not in (1, 2, 4, 8, 16) or t in types:
            continue
        fields = []
        ok = True
        if c1:
            a = (i * 4 + r1) & 0xFFFFFFFF
            if a % 4 or a // 4 + 7 * c1 > n:
                continue
            a //= 4
            for j in range(c1):
                e = a + 7 * j
                fields.append(Field(W[e + 5], W[e + 3], W[e + 4], W[e + 6], True))
        if c2:
            a = ((i + 3) * 4 + r2) & 0xFFFFFFFF
            if a % 4 or a // 4 + 10 * c2 > n:
                continue
            a //= 4
            tl = a + 9 * c2          # type list after the rows; a list member takes two words (element type, 0)
            for j in range(c2):
                e = a + 9 * j
                if W[e + 4] not in KINDS or tl >= n:
                    ok = False
                    break
                fields.append(Field(W[e + 5], W[e + 6], W[tl], W[e + 1] >> 16, False, W[e + 4]))
                tl += 2 if W[e + 4] == KIND_LIST else 1
        if not ok or any(f.offset > size for f in fields):
            continue
        fields.sort(key=lambda f: f.offset)
        types[t] = TypeInfo(t, size, align, fields, i * 4)
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
    if not best.prim and not best.is_list():
        for f, o in resolve(types, best.type, offset - best.offset, depth + 1):
            chain.append((f, o + best.offset))
    return chain


def walk(types, buf, type_crc, addr, visit, path=(), depth=0):
    """Visit every primitive member of the struct at ``addr`` (lists are followed).

    ``visit(path, address, field)`` gets the member-name path (list elements appear as ints in
    brackets, e.g. ``"[3]"``)."""
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
                    visit(p + ("[%d]" % k,), a + rel + 4 * k, f)
                else:
                    walk(types, buf, f.type, a + rel + k * et.size, visit, p + ("[%d]" % k,), depth + 1)
        else:
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
