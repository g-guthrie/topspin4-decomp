"""Tests for tools/port/export_assets.py and tools/port/blob_writer.py helpers (synthetic data only)."""
import json
import os
import shutil
import struct
import subprocess
import sys
import tempfile
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools", "port"))
sys.path.insert(0, os.path.join(ROOT, "tools"))
sys.path.insert(0, os.path.join(ROOT, "tools", "ts4data"))

import blob_writer as bw  # noqa: E402
import export_assets as ex  # noqa: E402
import ts4_analyser as A  # noqa: E402


class ClipSpec(unittest.TestCase):
    def test_lists_and_ranges(self):
        self.assertEqual(ex.parse_clip_spec("0,2,5-7", 100), [0, 2, 5, 6, 7])
        self.assertEqual(ex.parse_clip_spec(" 3 , 3 ,1", 100), [1, 3])

    def test_all_none_and_bounds(self):
        self.assertEqual(ex.parse_clip_spec("all", 4), [0, 1, 2, 3])
        self.assertEqual(ex.parse_clip_spec("none", 4), [])
        self.assertEqual(ex.parse_clip_spec("", 4), [])
        self.assertEqual(ex.parse_clip_spec("2-9", 4), [2, 3])

    def test_bad_specs(self):
        for bad in ("a", "5-2", "1;2"):
            with self.assertRaises(ValueError):
                ex.parse_clip_spec(bad, 10)


class BudgetTest(unittest.TestCase):
    def test_exhausts(self):
        b = ex.Budget(100)
        b.add(60)
        self.assertFalse(b.exhausted)
        b.add(40)
        self.assertTrue(b.exhausted)
        self.assertFalse(ex.Budget(None).exhausted)


class Annotations(unittest.TestCase):
    def test_contact_and_preparation(self):
        m = ex.contact_markers([{"name": "Hand_FH_Pose", "time": 0.3}, {"name": "EventRacket", "time": 0.4},
                                {"name": "7f6c2523", "time": 0.1}, {"name": "Stomp"}])
        self.assertAlmostEqual(m["contact"], 0.4)
        self.assertAlmostEqual(m["preparation"], 0.1)
        self.assertEqual([e["name"] for e in m["events"]], ["7f6c2523", "Hand_FH_Pose", "EventRacket"])

    def test_hash_names_and_missing(self):
        self.assertAlmostEqual(ex.contact_markers([{"name": "3b9ad22e", "time": 0.25}])["contact"], 0.25)
        m = ex.contact_markers(None)
        self.assertIsNone(m["contact"])
        self.assertEqual(m["events"], [])

    def test_first_event_racket_wins(self):
        m = ex.contact_markers([{"name": "EventRacket", "time": 0.5}, {"name": "EventRacket", "time": 0.2}])
        self.assertAlmostEqual(m["contact"], 0.5)

    def test_tags(self):
        self.assertEqual(ex.swing_tags("Swing_FH_Slice_Waist"), ["Swing", "FH", "Slice", "Waist"])
        self.assertEqual(ex.swing_tags(None), [])


def take(i, name, annotations, f14=100.0):
    return {"index": i, "id": "%08x" % (0x1000 + i), "name": name, "slot": i * 6, "f14": f14,
            "annotations": annotations, "segments": [{"f10": 0.0}, {"f10": 0.6}]}


class Records(unittest.TestCase):
    def setUp(self):
        self.recs = ex.build_animation_records([
            take(0, "Swing_A", [{"name": "EventRacket", "time": 0.4}]),
            take(1, "Swing_B", [{"name": "Preparation", "time": 0.1}]),
        ])

    def test_build(self):
        r = self.recs[0]
        self.assertEqual(r["name"], "Swing_A")
        self.assertAlmostEqual(r["contact"], 0.4)
        self.assertEqual(r["segment_times"], [0.0, 0.6])
        self.assertIsNone(r["clip"])
        self.assertIsNone(self.recs[1]["contact"])

    def test_link_by_name_id_and_index(self):
        n = ex.link_records(self.recs, ["core:5", "core:6"], {"Swing_A": "core:5", "#1": "core:6", "zz": "core:5"})
        self.assertEqual(n, 2)
        self.assertEqual([r["clip"] for r in self.recs], ["core:5", "core:6"])

    def test_link_ignores_unknown_clip_ids(self):
        self.assertEqual(ex.link_records(self.recs, ["core:1"], {"Swing_A": "core:99"}), 0)
        self.assertIsNone(self.recs[0]["clip"])

    def test_link_by_hex_id(self):
        self.assertEqual(ex.link_records(self.recs, ["core:1"], {self.recs[1]["id"]: "core:1"}), 1)


class ClipSummary(unittest.TestCase):
    def test_spline_and_wavelet(self):
        s = ex.clip_summary({"numFrames": 62, "duration": 1.0333333, "numberOfTransformTracks": 27},
                            "hkaSplineSkeletalAnimation", "NORMAL", 3, "clips/core_3.gltf")
        self.assertEqual((s["id"], s["codec"], s["frames"], s["tracks"], s["additive"], s["file"]),
                         ("core:3", "spline", 62, 27, False, "clips/core_3.gltf"))
        w = ex.clip_summary({"numberOfPoses": 11, "duration": 0.166, "numberOfTransformTracks": 71},
                            "hkaDeltaCompressedSkeletalAnimation", "ADDITIVE", 7)
        self.assertEqual((w["codec"], w["frames"], w["additive"], w["file"]), ("delta", 11, True, None))


class BallDefaults(unittest.TestCase):
    def state_with(self, radius, a4, g, maxb):
        buf = bytearray(ex.STATE_BALL_BLOCK + 0x540)
        struct.pack_into(">3f", buf, ex.STATE_BALL_BLOCK + 0x4D0, radius, a4, g)
        struct.pack_into(">I", buf, ex.STATE_BALL_BLOCK + 0x4DC, maxb)
        return bytes(buf)

    def test_reads_block(self):
        d = ex.read_ball_defaults(self.state_with(4.0, 0.06, 9.81, 5))
        self.assertAlmostEqual(d["radius_cm"], 4.0)
        self.assertAlmostEqual(d["a4"], 0.06, places=5)
        self.assertEqual(d["max_bounces"], 5)
        self.assertTrue(d["source"].startswith("State.bin"))

    def test_falls_back_on_garbage(self):
        for blob in (bytes(10), self.state_with(0.0, 0.0, 0.0, 0), self.state_with(4.0, 0.06, 98.0, 5)):
            d = ex.read_ball_defaults(blob)
            self.assertEqual(d["radius_cm"], 4.0)
            self.assertTrue(d["source"].startswith("documented"))


class ShotRows(unittest.TestCase):
    def test_compact(self):
        dec = {"files": [{"file": "Settings.bin", "rows": [
            {"index": 0, "row_offset": 100, "name": "FlatNormal", "group": None, "base": None, "kind": "InitialSpeed",
             "secondary_kind": "Apogee", "T": 0.045, "primary": {"type": "const", "value": 1.0},
             "secondary": {"type": "const", "value": 2.0}, "spin": {}, "bounce": {}, "header_words": ["x"]},
            {"index": 1, "row_offset": 0xEC4, "kind": "BounceSpeed", "secondary_kind": "BounceSpeed", "T": 0.04,
             "primary": {}, "secondary": {}, "spin": {}, "bounce": {}}]}]}
        rows = ex.compact_shot_rows(dec)
        self.assertEqual(rows[0]["id"], "Settings.bin#0")
        self.assertNotIn("header_words", rows[0])
        self.assertEqual(rows[1]["name"], "row_EC4")


class Misc(unittest.TestCase):
    def test_find_iso_and_json(self):
        with tempfile.TemporaryDirectory() as td:
            d = os.path.join(td, "orig", "x")
            os.makedirs(d)
            open(os.path.join(d, "a.iso"), "wb").close()
            self.assertTrue(ex.find_iso(td).endswith("a.iso"))
            self.assertEqual(ex.find_iso(td, "b.iso"), "b.iso")
            self.assertIsNone(ex.find_iso(os.path.join(td, "nothing")))
            p = os.path.join(td, "sub", "o.json")
            size = ex.write_json(p, {"a": [1, 2]}, compact=True)
            self.assertEqual(json.load(open(p)), {"a": [1, 2]})
            self.assertEqual(size, os.path.getsize(p))

    def test_status_and_free(self):
        self.assertEqual(ex.status("ok", "m", n=1), {"status": "ok", "message": "m", "n": 1})
        self.assertGreater(ex.free_bytes("/definitely/not/a/dir/yet"), 0)

    def test_parser_defaults(self):
        a = ex.build_parser().parse_args([])
        self.assertEqual(a.core_clips, "0-31")
        self.assertTrue(a.out.endswith(os.path.join("work", "port", "assets")))
        self.assertEqual(ex.build_parser().parse_args(["--only", "gameplay"]).only, ["gameplay"])


# ---------------------------------------------------------------------------------------------- blob writer

def synth_settings():
    """A Settings.bin-like buffer with 3 rows at 0x400 (ids at +0x88) and a 3-node decision tree at 0x24.

    tree: IsTopSpin ? row 0 : (IsSlice ? row 1 : row 2)"""
    buf = bytearray(0x1000)
    rows_start = 0x400
    ids = [0xAAAA0001, 0xBBBB0002, 0xCCCC0003]
    for i, rid in enumerate(ids):
        struct.pack_into(">I", buf, rows_start + 0x8C * i + 0x88, rid)
    node0, node1 = 0x100, 0x180

    def node(addr, cond, children):
        struct.pack_into(">iIIIII", buf, addr, 0x18, 2, 2, cond, 0, 0)
        for i, (typ, tgt) in enumerate(children):
            slot = addr + 0x18 + 8 * i
            struct.pack_into(">iI", buf, slot, tgt - slot, typ)

    leaf = 0x200
    for i, rid in enumerate(ids):
        struct.pack_into(">II", buf, leaf + 8 * i, rid, 0)
    node(node0, bw.crc32("IsTopSpin"), [(bw.TYPE_LEAF, leaf), (bw.TYPE_NODE, node1)])
    node(node1, bw.crc32("IsSlice"), [(bw.TYPE_LEAF, leaf + 8), (bw.TYPE_LEAF, leaf + 16)])
    struct.pack_into(">iI", buf, bw.TREE_ROOT_OFF, node0 - bw.TREE_ROOT_OFF, bw.TYPE_NODE)
    struct.pack_into(">2f", buf, 0x158, 80.0, 90.0)
    struct.pack_into(">2f", buf, bw.TREE_ROOT_OFF + 0xC70, 0.4, 0.7)
    return bytes(buf), rows_start, len(ids)


class TreeAndRows(unittest.TestCase):
    def setUp(self):
        self.settings, self.start, self.n = synth_settings()
        self._orig = bw.settings_rows
        bw.settings_rows = lambda s: (self.start, self.n)

    def tearDown(self):
        bw.settings_rows = self._orig

    def test_row_ids(self):
        ids = bw.row_id_map(self.settings)
        self.assertEqual(ids, {0xAAAA0001: 0, 0xBBBB0002: 1, 0xCCCC0003: 2})

    def test_tree_flatten(self):
        tree = bw.read_tree(self.settings, bw.row_id_map(self.settings))
        self.assertEqual(tree["nodes"][0], (bw.crc32("IsTopSpin"), ~0, 1))
        self.assertEqual(tree["nodes"][1], (bw.crc32("IsSlice"), ~1, ~2))

    def test_tree_section_roundtrip(self):
        nodes, root = bw.parse_tree(bw.build_tree(self.settings))
        self.assertEqual(root, 0)
        self.assertEqual(len(nodes), 2)
        self.assertEqual(nodes[1][2], ~2)

    def test_unknown_leaf_id_is_an_error(self):
        with self.assertRaises(ValueError):
            bw.read_tree(self.settings, {0xAAAA0001: 0})

    def test_tpls_header(self):
        t = bw.build_tpls(self.settings)
        rows, stride, off, size = struct.unpack_from("<4I", t, 0)
        self.assertEqual((rows, stride, off), (3, 0x8C, 0x400))
        self.assertEqual(size, len(self.settings))
        self.assertEqual(t[16:], self.settings)

    def test_game_tunables(self):
        ball = ex.read_ball_defaults(b"")
        g = bw.game_tunables(self.settings, b"", ball)
        self.assertEqual(g["shot.net_aim_cm"][0], 80.0)
        self.assertAlmostEqual(g["shot.tier_powerful"][0], 0.7, places=5)
        self.assertIsNotNone(g["ball.radius_cm"][1])          # documented default, so flagged provisional


class GraphRecords(unittest.TestCase):
    def graph(self):
        port = lambda dom, slot, idx, path: A.Port(dom, slot, idx, path, 3, 0)
        nodes = [
            A.Node(0x6BBD0182, 0, {"out": 1, "value": 2.5}),                                    # CONST
            A.Node(0xDEE0059F, 0, {"slots": [0, 1], "out": 2}),                                 # SUM
            A.Node(0x993894C6, 0, {"in": 2, "out": 3, "keys": [(0.0, 1.0, 0.0, 2.0, 0)]}),      # CURVE
            A.Node(0x7E683220, 0, {"a": 0, "b": 1, "t": 2, "out": 4}),                          # LERP
            A.Node(0x12345678, 0, {"raw": [0, 0, 0, 0]}),                                       # unknown
        ]
        return A.Graph(0xDEADBEEF, 5, [port(1, 0, -1, [0xA, 0xB])], [port(2, 4, 3, [])], nodes, 0)

    def test_roundtrip(self):
        rec = bw.parse_graph_record(bw.build_graph_record(self.graph()))
        self.assertEqual((rec["name"], rec["nregs"], rec["n_in"], rec["n_out"]), (0xDEADBEEF, 5, 1, 1))
        self.assertEqual(rec["ports"][0], (1, -1, 0, bw.path_key([0xA, 0xB])))
        self.assertEqual(rec["ports"][1][2], 4)
        kinds = [n["kind"] for n in rec["nodes"]]
        self.assertEqual(kinds, [0, 1, 5, 9, 0xFFFFFFFF])
        self.assertEqual(rec["nodes"][0]["value"], 2.5)
        self.assertEqual(rec["nodes"][1]["slots"], [0, 1])
        self.assertEqual(rec["nodes"][2]["keys"], [(0.0, 1.0, 0.0, 2.0)])
        self.assertEqual((rec["nodes"][3]["a"], rec["nodes"][3]["b"], rec["nodes"][3]["t"], rec["nodes"][3]["out"]), (0, 1, 2, 4))

    def test_section_directory(self):
        g = self.graph()
        sec = bw.parse_grph(bw.build_grph([g, g]))
        self.assertEqual(list(sec), [0xDEADBEEF])
        self.assertEqual(bw.parse_graph_record(sec[0xDEADBEEF])["nregs"], 5)

    def test_offsets_are_aligned(self):
        data = bw.build_grph([self.graph()])
        n, = struct.unpack_from("<I", data, 0)
        for i in range(n):
            _h, off, _size = struct.unpack_from("<3I", data, 4 + 12 * i)
            self.assertEqual(off % 4, 0)


class Container(unittest.TestCase):
    def test_assemble_and_read(self):
        blob = bw.assemble({"TUNE": b"\1\2\3", "TPLS": b"abcdefgh"})
        d = bw.read_directory(blob)
        self.assertEqual(set(d), {"TUNE", "TPLS"})
        o, s = d["TUNE"]
        self.assertEqual(blob[o:o + s], b"\1\2\3")
        for off, _ in d.values():
            self.assertEqual(off % 4, 0)

    def test_bad_container(self):
        with self.assertRaises(ValueError):
            bw.read_directory(b"XXXX" + bytes(20))

    def test_tune_sorted_and_precedence(self):
        data = bw.build_tune({"ball.a4": (0.06, None), "ball.g": (9.81, "assumed")},
                             {"ball.a4": 0.5, "aim.depth_cm": 900.0})
        t = bw.parse_tune(data)
        keys = list(t)
        self.assertEqual(keys, sorted(keys))
        self.assertAlmostEqual(t[bw.crc32("ball.a4")][0], 0.06, places=5)      # game wins over provisional
        self.assertEqual(t[bw.crc32("ball.a4")][1], 0)
        self.assertEqual(t[bw.crc32("ball.g")][1], bw.FLAG_PROVISIONAL)
        self.assertEqual(t[bw.crc32("aim.depth_cm")][1], bw.FLAG_PROVISIONAL)

    def test_provisional_and_registry(self):
        with tempfile.TemporaryDirectory() as td:
            p = os.path.join(td, "p.json")
            json.dump({"tunables": {"a.b": 1, "c.d": {"value": 2.5}, "e": "x", "f": True}}, open(p, "w"))
            self.assertEqual(bw.load_provisional(p), {"a.b": 1.0, "c.d": 2.5})
            self.assertEqual(bw.load_provisional(os.path.join(td, "missing.json")), {})
            d = os.path.join(td, "t.def")
            open(d, "w").write('TS4_TUN(BALL_A4, "ball.a4", "s", GAME, R, "x")\nTS4_TUN(AIM, "aim.depth_cm", "cm", PORT, R, "y")\n')
            self.assertEqual(bw.registry_names(d), {"ball.a4": "GAME", "aim.depth_cm": "PORT"})


# ---------------------------------------------------------------------------------------------- JS fallback

NODE = shutil.which("node")


@unittest.skipUnless(NODE, "node is not installed")
class JsFallback(unittest.TestCase):
    """The ball model in port/web/src/core_js.js on a synthetic template: the arc must land on the target."""

    SCRIPT = r"""
import { JsBallModel } from %(mod)s;
const row = { file: "Settings.bin", index: 0, name: "Synthetic", kind: "InitialSpeed", secondary_kind: "Apogee", T: 0.045,
  primary: { type: "const", value: 120 }, secondary: { type: "const", value: 1.5 },
  spin: { a: { lo: { type: "const", value: 0 }, hi: { type: "const", value: -0.2 } },
          b: { lo: { type: "const", value: 0 }, hi: { type: "const", value: 0 } },
          c: { lo: { type: "const", value: 0 }, hi: { type: "const", value: 0 } } },
  bounce: { speed_loss: [[0, 1.5, 0, 0.1]], spin_decay: [[0, 1, 0.5, 0.5]], out_elevation: [[0, 1.5, 0, 1.5]], yaw_kick: [[0, 1, 0, 0]] } };
const m = new JsBallModel([row], { radius_cm: 4, a4: 0.06, g: 9.81, max_bounces: 5, net_height_cm: 91.4 });
const inp = { row: 0, from: [-1250, 100, 150], to: [1000, 0, -250], spin_blend: 0.5, f4c: 1, left_handed: 0, planned: 1 };
const t = m.trace(inp, 300);
const first = t.events.find(e => e.type === "bounce");
console.log(JSON.stringify({ n: t.points.length / 3, first, info: t.info, p0: Array.from(t.points.slice(0, 3)) }));
"""

    def run_js(self):
        mod = json.dumps("file://" + os.path.join(ROOT, "port", "web", "src", "core_js.js"))
        r = subprocess.run([NODE, "--input-type=module", "-e", self.SCRIPT % {"mod": mod}], capture_output=True, text=True, timeout=60)
        self.assertEqual(r.returncode, 0, r.stderr)
        return json.loads(r.stdout.strip().splitlines()[-1])

    def test_lands_on_target_with_requested_speed(self):
        out = self.run_js()
        self.assertEqual(out["p0"], [-1250, 100, 150])        # starts at the contact point (ball centre = hit height)
        first = out["first"]
        self.assertAlmostEqual(first["pos"][0], 1000, delta=0.5)
        self.assertAlmostEqual(first["pos"][2], -250, delta=0.5)
        self.assertAlmostEqual(first["pos"][1], 4, delta=0.5)   # ball centre one radius above the ground
        self.assertAlmostEqual(out["info"]["initial_kmh"], 120, delta=2.0)
        self.assertEqual(first["tick"], out["info"]["bounce_tick"])


if __name__ == "__main__":
    unittest.main()
