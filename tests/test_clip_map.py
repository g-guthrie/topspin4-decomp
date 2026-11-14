"""Tests for the pure helpers of tools/port/clip_map.py (synthetic AnimationsDB bytes only, no game data)."""
import os
import struct
import sys
import unittest
import zlib

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools", "port"))

import clip_map as cm  # noqa: E402


def build_db(takes, rows, ext_ids):
    """Synthetic AnimationDB image. takes: list of (id, tag, frames, poly_type, rows-spec);
    rows: list of (k0, c, k1); ext_ids: ExtractPositionList ids (entry 0 is the null entry).
    Poly objects are appended after the arrays; rows-spec is a list of HkxList row numbers."""
    buf = bytearray(0x200)
    take_base = len(buf)
    buf += bytearray(cm.TAKE_SIZE * len(takes))
    hkx_base = len(buf)
    for k0, c, k1 in rows:
        buf += struct.pack(">3H", k0, c, k1) + bytes(cm.HKX_SIZE - 6)
    ext_base = len(buf)
    for i in ext_ids:
        buf += struct.pack(">I", i) + bytes(12)

    def desc(off, base, count):
        struct.pack_into(">III", buf, off, base - off, count, count)

    desc(cm.ROOT_OFF + cm.D_TAKES, take_base, len(takes))
    desc(cm.ROOT_OFF + cm.D_HKX, hkx_base, len(rows))
    desc(cm.ROOT_OFF + cm.D_EXT, ext_base, len(ext_ids))

    for i, (tid, tag, frames, typ, spec) in enumerate(takes):
        o = take_base + cm.TAKE_SIZE * i
        poly = len(buf)
        if typ == cm.POLY_SINGLE:
            buf += struct.pack(">IIIHH", 0x10, 1, 1, spec[0], 0) + bytes(0x20)
        elif typ == cm.POLY_SET:
            buf += struct.pack(">III", 0x20, len(spec), len(spec)) + bytes(0x14)
            buf += struct.pack(">%dH" % len(spec), *spec) + bytes(4)
        else:  # list / blend: {rel,count,cap} then {rel,type} elements, each pointing at a single poly object
            n = len(spec)
            head = len(buf)
            buf += struct.pack(">III", 0xC, n, n) + bytes(8 * n)
            for v, r in enumerate(spec):
                tgt = len(buf)
                buf += struct.pack(">IIIHH", 0x10, 1, 1, r, 0) + bytes(0x20)
                e = head + 0xC + 8 * v
                struct.pack_into(">II", buf, e, tgt - e, cm.POLY_SINGLE)
        struct.pack_into(">f", buf, o + 0x14, frames)
        struct.pack_into(">I", buf, o + 0x1C, tag)
        struct.pack_into(">II", buf, o + 0x5C, poly - (o + 0x5C), typ)
        struct.pack_into(">I", buf, o + 0x84, tid)
    return bytes(buf)


class Lookup(unittest.TestCase):
    def setUp(self):
        rows = [(0, 7, 0),      # 0: core clip 7
                (0, 9, 3),      # 1: core clip 9 followed by AOD entry 3
                (2, 0, 0),      # 2: AOD entry 2
                (0, 11, 0), (0, 12, 0)]
        ext = [0, 111, 222, 333]
        takes = [(0xAAAA0001, 0x35, 50.0, cm.POLY_SINGLE, [0]),
                 (0xAAAA0002, 0x35, 150.0, cm.POLY_SINGLE, [1]),
                 (0xAAAA0003, 0x35, 80.0, cm.POLY_SINGLE, [2]),
                 (0xAAAA0004, 0x35, 50.0, cm.POLY_SET, [0, 3, 4]),
                 (0xAAAA0005, 0x35, 80.0, cm.POLY_LIST, [2, 2]),
                 (0xAAAA0006, 0x35, 12.0, cm.POLY_BLEND, [3, 4])]
        self.db = cm.AnimDb(build_db(takes, rows, ext))
        self.core = {7: 50, 9: 100, 11: 11, 12: 12}
        self.aod = {222: 80, 333: 50}

    def test_arrays(self):
        self.assertEqual((self.db.n_takes, self.db.n_hkx, self.db.n_ext), (6, 5, 4))
        t = self.db.take(1)
        self.assertEqual((t["id"], t["tag"], t["frames"], t["poly_type"]), (0xAAAA0002, 0x35, 150.0, cm.POLY_SINGLE))

    def test_variant_rows(self):
        rows = [self.db.variant_rows(self.db.take(i)) for i in range(6)]
        self.assertEqual(rows, [[0], [1], [2], [0, 3, 4], [2, 2], [3, 4]])

    def test_row_sources(self):
        self.assertEqual(cm.row_source(self.db, 0), {"kind": "core", "row": 0, "clip": "core:7", "core_index": 7})
        s = cm.row_source(self.db, 1)
        self.assertEqual((s["kind"], s["clip"], s["aod_id"]), ("core+aod", "core:9", 333))
        s = cm.row_source(self.db, 2)
        self.assertEqual((s["kind"], s["aod_index"], s["aod_id"]), ("aod", 2, 222))

    def test_frames_sum_for_core_plus_aod(self):
        s = cm.row_source(self.db, 1)
        self.assertEqual(cm.source_frames(s, self.core, self.aod), 150)
        self.assertIsNone(cm.source_frames(s, self.core, {}))

    def test_records(self):
        recs = cm.build_records(self.db, {0xAAAA0001: "A"}, self.core, self.aod, core_additive=frozenset({11, 12}))
        by = {r["index"]: r for r in recs}
        self.assertEqual(by[0]["name"], "A")
        self.assertEqual((by[0]["method"], by[0]["confidence"], by[0]["primary"]), ("hkxlist-core", "exact", "core:7"))
        self.assertEqual((by[1]["method"], by[1]["confidence"]), ("hkxlist-core+aod", "exact"))
        self.assertEqual((by[2]["method"], by[2]["confidence"], by[2]["primary"]), ("hkxlist-aod", "exact", "aod:222"))
        self.assertEqual((by[3]["method"], by[3]["confidence"]), ("hkxlist-set", "exact"))
        self.assertEqual(by[4]["confidence"], "exact")
        self.assertEqual(by[5]["confidence"], "exact")  # blend: mean(11, 12) = 11.5 is within 0.5 of 12

    def test_mismatch_and_structural(self):
        recs = cm.build_records(self.db, {}, {7: 49, 9: 100, 11: 11, 12: 12}, self.aod)
        self.assertEqual(recs[0]["confidence"], "mismatch")
        recs = cm.build_records(self.db, {}, self.core, {})
        self.assertEqual(recs[0]["confidence"], "exact")
        self.assertEqual(recs[1]["confidence"], "structural")
        self.assertEqual(recs[2]["confidence"], "structural")

    def test_set_with_non_additive_layer_is_partial(self):
        recs = cm.build_records(self.db, {}, self.core, self.aod, core_additive=frozenset({11}))
        self.assertEqual(recs[3]["confidence"], "partial")

    def test_exporter_map(self):
        recs = cm.build_records(self.db, {}, self.core, self.aod, core_additive=frozenset({11, 12}))
        self.assertEqual(cm.exporter_map(recs), {"#0": "core:7", "#3": "core:7"})

    def test_summary(self):
        recs = cm.build_records(self.db, {}, self.core, self.aod, core_additive=frozenset({11, 12}))
        s = cm.summarize(recs)
        self.assertEqual(s["records"], 6)
        self.assertEqual(s["by_confidence"], {"exact": 6})

    def test_unknown_poly_type_rejected(self):
        t = dict(self.db.take(0), poly_type=0x12345678)
        with self.assertRaises(ValueError):
            self.db.variant_rows(t)


class Helpers(unittest.TestCase):
    def test_aod_entry_key_is_crc_of_full_lowercase_path(self):
        for cid in (0, 7, 94895, 4290723229):
            want = zlib.crc32(("/media/animation/aod/%d.hkx" % cid).encode()) & 0xFFFFFFFF
            self.assertEqual(cm.aod_entry_key(cid), want)

    def test_aod_dir_hash_matches_cutscenes_directory(self):
        # CutScenes.arc stores this directory hash for its 2,093 children (docs/port/clip-map.md)
        self.assertEqual(zlib.crc32(cm.AOD_DIR.encode()) & 0xFFFFFFFF, 0x12ACB5B9)

    def test_annotation_time(self):
        buf = bytearray(build_db([(1, 0, 10.0, cm.POLY_SINGLE, [0])], [(0, 1, 0)], [0]))
        o = cm.AnimDb(bytes(buf)).takes
        ann = len(buf)
        buf += struct.pack(">IfII", 0x1111, 0.25, 0, 0) + struct.pack(">IfII", cm.EVENT_RACKET, 0.5, 0, 0)
        struct.pack_into(">III", buf, o + 0x64, ann - (o + 0x64), 2, 2)
        db = cm.AnimDb(bytes(buf))
        self.assertAlmostEqual(db.annotation_time(0, cm.EVENT_RACKET), 0.5)
        self.assertAlmostEqual(db.annotation_time(0, 0x1111), 0.25)
        self.assertIsNone(db.annotation_time(0, 0x2222))

    def test_peak_phase(self):
        pos = [(float(x), 0.0, 0.0) for x in (0, 1, 2, 10, 18, 19, 20)]
        ph = cm.peak_phase(pos)
        self.assertTrue(0.4 < ph < 0.8)
        self.assertIsNone(cm.peak_phase(pos[:2]))

    def test_median(self):
        self.assertEqual(cm.median([3, 1, 2]), 2)
        self.assertEqual(cm.median([1, 2, 3, 4]), 2.5)
        self.assertIsNone(cm.median([]))


if __name__ == "__main__":
    unittest.main()
