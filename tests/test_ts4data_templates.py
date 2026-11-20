"""Tests for tools/ts4data/templates.py on a small synthetic Settings.bin-like buffer (no game data)."""
import struct
import unittest

from tools.ts4data import templates as T

F, C20, T2D, CONST = T.TYPE_CURVE20, T.TYPE_CURVE20, T.TYPE_TABLE2D, T.TYPE_CONST


class Builder:
    """Append-only big-endian buffer with self-relative pointers."""

    def __init__(self):
        self.b = bytearray()

    def pos(self):
        return len(self.b)

    def u32(self, v):
        self.b += struct.pack(">I", v & 0xFFFFFFFF)

    def f32(self, v):
        self.b += struct.pack(">f", v)

    def patch_rel(self, field, target):
        struct.pack_into(">i", self.b, field, target - field)


def build(name="FlatNormal"):
    """One 0x8C row (Settings.bin flavour) followed by its data blocks.  Returns (bytes, row_offset)."""
    b = Builder()
    b.b += b"\0" * 0x20            # padding so the row is not at offset 0
    row = b.pos()
    # header: row type, name, group, base, -1, -1
    for w in (T.ROW_TYPE, T.crc(name), T.crc("FlatReturn"), 0, 0xFFFFFFFF, 0xFFFFFFFF):
        b.u32(w)
    node0, node1 = b.pos(), b.pos() + 12
    for _ in range(3):
        b.u32(0)                   # node0 {rel, type, kind}
    for _ in range(3):
        b.u32(0)                   # node1
    spin = [b.pos() + 12 * i for i in range(3)]
    for _ in range(9):
        b.u32(0)                   # three {rel, count, cap}
    b.f32(0.05)                    # T at tpl + 0x3C
    bounce = [b.pos() + 12 * i for i in range(4)]
    for _ in range(12):
        b.u32(0)
    b.u32(T.crc(name))             # row + 0x88
    assert b.pos() - row == T.ROW_SIZE
    # data blocks
    cur20 = b.pos()                # curve20 header {rel 0xC, 1, 1} + key {500, 3000, 130, 0, 120}
    b.u32(0xC); b.u32(1); b.u32(1)
    for v in (500.0, 3000.0, 130.0, 0.0, 120.0):
        b.f32(v)
    cur20b = b.pos()               # key with a slope: 0.5 .. 1.5 -> 0 .. 1
    b.u32(0xC); b.u32(1); b.u32(1)
    for v in (0.5, 1.5, 0.0, 1.0, 0.0):
        b.f32(v)
    const = b.pos()
    b.f32(1.5)
    pair = b.pos()                 # two {rel, type}: lo = curve with slope, hi = const
    b.u32(0); b.u32(C20); b.u32(0); b.u32(CONST)
    b.patch_rel(pair, cur20b)
    b.patch_rel(pair + 8, const)
    c16 = b.pos()                  # four one-key curve16 blocks {x0, x1, y0, y1}
    for keys in ((-0.4, 0.0, 0.05, -0.2), (-0.4, 0.0, 0.9, 0.7), (0.0, 1.5, 0.0, 1.45), (0.0, 1.0, 0.0, 0.0)):
        for v in keys:
            b.f32(v)
    # node pointers
    b.patch_rel(node0, cur20); struct.pack_into(">II", b.b, node0 + 4, C20, 0xC1965E5C)
    b.patch_rel(node1, const); struct.pack_into(">II", b.b, node1 + 4, CONST, 0x879BA860)
    for s in spin:
        struct.pack_into(">ii", b.b, s + 4, 2, 2)
        b.patch_rel(s, pair)
    for i, s in enumerate(bounce):
        struct.pack_into(">ii", b.b, s + 4, 1, 1)
        b.patch_rel(s, c16 + 16 * i)
    return bytes(b.b), row


class TemplateDecodeTests(unittest.TestCase):
    def test_find_and_decode_row(self):
        data, row = build()
        b = T.Buf(data)
        self.assertEqual(T.find_rows(b), [row])
        names = T.name_table()
        r = T.decode_row(b, row, names)
        self.assertEqual(r["name"], "FlatNormal")
        self.assertEqual(r["group"], "FlatReturn")
        self.assertEqual(r["kind"], "InitialSpeed")
        self.assertEqual(r["secondary_kind"], "Apogee")
        self.assertAlmostEqual(r["T"], 0.05)
        self.assertEqual(r["primary"], {"type": "curve20", "keys": [[500.0, 3000.0, 130.0, 0.0, 120.0]]})
        self.assertEqual(r["secondary"], {"type": "const", "value": 1.5})
        for k in "abc":
            self.assertEqual(r["spin"][k]["hi"], {"type": "const", "value": 1.5})
            self.assertEqual(r["spin"][k]["lo"]["keys"], [[0.5, 1.5, 0.0, 1.0, 0.0]])
        self.assertEqual(r["bounce"]["speed_loss"], [[-0.4, 0.0, 0.05, -0.2]])
        self.assertEqual(r["bounce"]["out_elevation"], [[0.0, 1.5, 0.0, 1.45]])
        self.assertEqual(r["trailer_name_hash"], "%08x" % T.crc("FlatNormal"))
        self.assertIsNone(r["aux_ptr_10"])

    def test_decode_file_json_safe(self):
        import json
        data, _ = build()
        dec = T.decode_all(data)
        self.assertEqual(len(dec["files"][0]["rows"]), 1)
        json.dumps(dec)
        self.assertIn("1 rows", T.summarize(dec))

    def test_curve_evaluators(self):
        keys = [[0.0, 1.0, 0.0, 2.0, 0.0], [1.0, 3.0, 5.0, 0.5, 0.0]]
        self.assertEqual(T.eval_curve20(keys, -1.0), 0.0)      # before the first key: first key, clamped
        self.assertEqual(T.eval_curve20(keys, 0.5), 1.0)
        self.assertEqual(T.eval_curve20(keys, 2.0), 5.5)
        self.assertEqual(T.eval_curve20(keys, 9.0), 6.0)       # clamped to x1 - x0
        k16 = [[0.0, 2.0, 1.0, 3.0]]
        self.assertEqual(T.eval_curve16(k16, 1.0), 2.0)
        self.assertEqual(T.eval_curve16(k16, 5.0), 3.0)
        self.assertEqual(T.eval_curve16(k16, -5.0), 1.0)

    def test_table2d_and_value_eval(self):
        rows = [{"a": 300.0, "keys": [[0.0, 100.0, 1.0, 1.0]]}, {"a": 700.0, "keys": [[0.0, 100.0, 3.0, 3.0]]}]
        self.assertEqual(T.eval_table2d(rows, 100.0, 50.0), 1.0)    # below the first row
        self.assertEqual(T.eval_table2d(rows, 500.0, 50.0), 2.0)    # halfway
        self.assertEqual(T.eval_table2d(rows, 900.0, 50.0), 3.0)    # above the last row
        self.assertEqual(T.eval_value({"type": "table2d", "rows": rows}, 500.0, 0.0), 2.0)
        self.assertEqual(T.eval_value({"type": "const", "value": 7.0}, 1.0), 7.0)

    def test_name_hashes(self):
        self.assertEqual(T.crc("DropTime"), 0x5D90675B)
        self.assertEqual(T.crc("InitialSpeed"), 0xC1965E5C)
        names = T.name_table()
        self.assertEqual(names[0x471A198A], "ServeNormal")
        self.assertEqual(len(names), len(T.TEMPLATE_NAMES))


if __name__ == "__main__":
    unittest.main()
