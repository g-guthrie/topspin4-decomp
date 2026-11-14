"""Round-trip tests for the generic XBin walker and the tunables dump/patch tools.

Everything here is synthetic: a Layoutall-style type table and a generic data-tree XBin are built
in this file following the format decoded in tools/ts4_xbin.py; no game bytes are used.
"""
import os
import struct
import sys
import tempfile
import unittest
import zlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
sys.path.insert(0, str(ROOT / "tools" / "ts4data"))

import ts4_xbin as X  # noqa: E402
import dump_tunables as D  # noqa: E402
import patch_tunables as P  # noqa: E402


def crc(s):
    return zlib.crc32(s.encode()) & 0xFFFFFFFF


SINGLE, INT32, BOOL, CKEY, U16 = (crc("Pam::System::Single"), crc("Pam::System::Int32"),
                                 crc("Pam::System::Boolean"), crc("Pam::System::CKey"),
                                 crc("Pam::System::UInt16"))
VEC3 = crc("Pam::Math::C3DVector")
T_ROOT, T_ITEM = crc("Test::Root"), crc("Test::Root_Items")


def build_layout(types):
    """types: [(crc, size, align, attrs[(name, type, off, size)], elems[(name, type, kind, off)])]
    -> Layoutall-style XBin bytes (header, pair table, 0x40-byte type records, member chains)."""
    types = sorted(types)
    head = bytearray(struct.pack(">5I", 0x03D3C76D, 0xE7B85A4D, 4, 0, 0xFFFFFFFF))
    pairs_at, recs_at = 0x34, 0x34 + 8 * len(types)
    tail_at = recs_at + 0x40 * len(types)
    buf = bytearray(tail_at)
    buf[:0x14] = head
    struct.pack_into(">3I", buf, 0x14, pairs_at - 0x14, len(types), len(types))
    struct.pack_into(">3I", buf, 0x20, recs_at - 0x20, len(types), len(types))
    for i, (tc, *_r) in enumerate(types):
        struct.pack_into(">2I", buf, pairs_at + 8 * i, crc("layout%d" % i), tc)
    for i, (tc, size, align, attrs, elems) in enumerate(types):
        rec = recs_at + 0x40 * i
        w = [0] * 16
        if attrs:
            w[0], w[1], w[2] = attrs[0][1], 0x40000, crc(attrs[0][0])
        if elems:
            w[3], w[4], w[5] = elems[0][1], 0x40000, crc(elems[0][0])
        a_at = len(buf)
        for j, (nm, ty, off, sz) in enumerate(attrs):
            nxt = attrs[j + 1] if j + 1 < len(attrs) else None
            buf += struct.pack(">7I", nxt[1] if nxt else 0, 0x40000 if nxt else 0, crc(nxt[0]) if nxt else 0,
                               off, ty, crc(nm), sz)
        e_at = len(buf)
        for j, (nm, ty, kind, off) in enumerate(elems):
            nxt = elems[j + 1] if j + 1 < len(elems) else None
            buf += struct.pack(">9I", nxt[1] if nxt else 0, 0x40000 if nxt else 0, crc(nxt[0]) if nxt else 0,
                               0, kind, crc(nm), off, 4, 0)
        w[6], w[7], w[8] = (a_at - (rec + 0x18)) if attrs else 0, len(attrs), len(attrs)
        w[9], w[10], w[11] = (e_at - (rec + 0x24)) if elems else 0, len(elems), len(elems)
        w[12], w[13], w[14], w[15] = tc, size, align, len(attrs)
        struct.pack_into(">16I", buf, rec, *[x & 0xFFFFFFFF for x in w])
    return bytes(buf)


LAYOUT = build_layout([
    (T_ROOT, 0x28, 4,
     [("Gain", SINGLE, 0x00, 4), ("Count", INT32, 0x04, 4), ("Enabled", BOOL, 0x08, 1), ("Mode", CKEY, 0x0C, 4)],
     [("Items", T_ITEM, X.KIND_LIST, 0x10), ("Pos", VEC3, X.KIND_INLINE, 0x1C)]),
    (T_ITEM, 8, 4, [("Weight", SINGLE, 0, 4), ("Id", U16, 4, 2)], []),
])


def build_data():
    """Generic data-tree XBin: polymorphic root reference at 0x14, root at 0x20, 2 items at 0x48."""
    buf = bytearray(struct.pack(">5I", 0x181AEDEE, X.GENERIC_TREE_ROOT, 0x10, 0, 0xFFFFFFFF))
    buf += struct.pack(">iI", 0x20 - 0x14, T_ROOT) + bytes(4)
    root = len(buf)
    assert root == 0x20
    buf += struct.pack(">fiB3xI", 1.5, -7, 1, crc("Wood"))
    buf += struct.pack(">iII", 0x48 - (root + 0x10), 2, 2)
    buf += struct.pack(">3f", 10.0, 20.0, 30.0) + bytes(0x28 - 0x28)
    buf += bytes(0x48 - len(buf))
    buf += struct.pack(">fH2x", 0.25, 7) + struct.pack(">fH2x", 0.75, 9)
    return bytes(buf)


class WalkerTests(unittest.TestCase):
    def test_layout_and_walk(self):
        lay = X.Layout(LAYOUT)
        self.assertEqual(lay.size_of(T_ROOT), 0x28)
        names = X.load_names()
        names.update({crc(n): n for n in ("Gain", "Count", "Enabled", "Mode", "Items", "Pos", "Weight", "Id",
                                           "Test::Root", "Wood")})
        lv = {lf.path: lf for lf in X.Walker(build_data(), lay, names).walk_file()}
        self.assertEqual(lv["<Test::Root>/Gain"].value, 1.5)
        self.assertEqual(lv["<Test::Root>/Count"].value, -7)
        self.assertEqual(lv["<Test::Root>/Enabled"].value, 1)
        self.assertEqual(lv["<Test::Root>/Mode"].value, crc("Wood"))
        self.assertEqual(lv["<Test::Root>/Items[1]/Weight"].value, 0.75)
        self.assertEqual(lv["<Test::Root>/Items[1]/Id"].value, 9)
        self.assertEqual(lv["<Test::Root>/Pos[2]"].value, 30.0)
        self.assertEqual(lv["<Test::Root>/Items[0]/Weight"].offset, 0x48)


def parse(text):
    rows = []
    head = None
    for part in text.split("\n=====\n"):
        head, r = P.parse_yaml(part)
        rows.extend(r)
    return head, rows


class DumpPatchTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.dir = self.tmp.name
        self.lay = X.Layout(LAYOUT)
        self.data = build_data()
        self.names = X.load_names()
        self.names.update({crc(n): n for n in ("Gain", "Count", "Items", "Weight")})
        D.dump_one("Test.bin", "Core.arc", 0x1234ABCD, "synthetic", self.data, self.lay, self.names, {},
                   "test", "0" * 64, self.dir)
        self.yaml = self.read_dump(self.dir)

    @staticmethod
    def read_dump(d):
        """All parts of the dump joined (headers repeat; parse_yaml_parts splits them again)."""
        parts = sorted(Path(d, "Test").glob("*.yaml"))
        # root scalars + Pos in one section, Items in another
        assert [p.name[:3] for p in parts] == ["00_", "01_"], parts
        return "\n=====\n".join(p.read_text() for p in parts)

    def tearDown(self):
        self.tmp.cleanup()

    def edit(self, old, new):
        self.assertIn(old, self.yaml)
        return self.yaml.replace(old, new)

    def test_identity(self):
        head, rows = parse(self.yaml)
        self.assertEqual(head["key"], "0x1234abcd")
        self.assertEqual(len(rows), 11)          # 4 root attrs + 2x2 item attrs + 3 vector floats
        out, changes = P.apply(self.data, self.lay, rows)
        self.assertEqual(out, self.data)
        self.assertEqual(changes, [])

    def test_round_trip_edit(self):
        y = self.edit("float, 1.5,", "float, 2.25,")
        y = y.replace('int, -7,', 'int, 12,')
        y = y.replace('bool, true,', 'bool, false,')
        y = y.replace("float, 0.75,", "float, 0.1,")
        y = y.replace("u16, 9,", "u16, 65535,")
        _h, rows = parse(y)
        out, changes = P.apply(self.data, self.lay, rows)
        self.assertEqual(len(changes), 5)
        P.verify(self.data, out, self.lay, changes)
        lv = {lf.offset: lf.value for lf in X.Walker(out, self.lay).walk_file()}
        self.assertEqual(lv[0x20], 2.25)
        self.assertEqual(lv[0x24], 12)
        self.assertEqual(lv[0x28], 0)
        self.assertEqual(struct.pack(">f", lv[0x50]), struct.pack(">f", 0.1))
        self.assertEqual(lv[0x54], 65535)
        # dump the patched file again and patch it back to the original
        D.dump_one("Test.bin", "Core.arc", 0x1234ABCD, "synthetic", out, self.lay, self.names, {},
                   "test", "0" * 64, os.path.join(self.dir))
        _h, rows0 = parse(self.yaml)
        back, _c = P.apply(out, self.lay, rows0)
        self.assertEqual(back, self.data)

    def test_rejects_bad_edits(self):
        for old, new in [("int, -7,", "int, 99999999999,"),
                         ("u16, 9,", "u16, -1,"),
                         ("int, -7,", "float, -7,"),
                         ("float, 1.5,", "float, 1e60,"),
                         ("float, 1.5,", "float, fast,")]:
            _h, rows = parse(self.edit(old, new))
            with self.assertRaises(P.PatchError):
                P.apply(self.data, self.lay, rows)
        y = self.yaml.replace('/Gain"', '/Gainz"')
        _h, rows = parse(y)
        with self.assertRaises(P.PatchError):
            P.apply(self.data, self.lay, rows)
        y = self.yaml.replace("[0x20, ", "[0x21, ")
        _h, rows = parse(y)
        with self.assertRaises(P.PatchError):
            P.apply(self.data, self.lay, rows)

    def test_names_survive_renaming(self):
        # a dump made without names must still patch a file dumped with names (paths compared by crc)
        y = self.yaml.replace('/Gain"', '/%08x"' % crc("Gain"))
        _h, rows = parse(y)
        P.apply(self.data, self.lay, rows)


if __name__ == "__main__":
    unittest.main()
