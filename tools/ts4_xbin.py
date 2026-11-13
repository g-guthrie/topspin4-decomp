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
