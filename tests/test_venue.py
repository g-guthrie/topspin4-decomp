"""tools/ts4_venue.py on synthetic bytes (no game data) + the crowd state machine through node."""
import os
import shutil
import struct
import subprocess
import sys
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import ts4_venue as V  # noqa: E402

NODE = shutil.which("node")


def _desc(buf, at, target, count):
    struct.pack_into(">iII", buf, at, (target - at) if target is not None else -1, count, count)


def _relstr(buf, at, target):
    struct.pack_into(">i", buf, at, target - at)


def make_crowd():
    """root leaf node at 0x14, two spectators at 0x100, groups at 0x200, strings at 0x300."""
    b = bytearray(0x400)
    struct.pack_into(">II", b, 0, *V.CROWD_SIG)
    b[0x10:0x14] = b"\xff" * 4
    r = 0x14
    struct.pack_into(">3ff", b, r, 0.0, 0.0, 0.0, 5000.0)
    _desc(b, r + 0x10, None, 0)
    struct.pack_into(">i", b, r + 0x1C, 0)
    _desc(b, r + 0x20, 0x100, 2)
    _desc(b, r + 0x2C, 0x200, 2)
    struct.pack_into(">II", b, r + 0x38, 1, 7)
    strs = {"Spectator02": 0x300, "Model.xml": 0x310,
            'TrackSideSetupList:/SetupList/Animation[@Name="TS_SE03"]': 0x320}
    for s, o in strs.items():
        b[o:o + len(s) + 1] = s.encode() + b"\0"
    for i in range(2):
        o = 0x100 + V.CROWD_REC * i
        struct.pack_into(">3f3f3f", b, o, 100.0 * (i + 1), 250.0, -300.0, 0.0, 1.5, 0.0, 1.0, 0.9, 1.05)
        _relstr(b, o + 0x24, 0x300)
        _relstr(b, o + 0x28, 0x310)
        struct.pack_into(">2f3f3f", b, o + 0x2C, 0.5, 0.0, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3)
        _relstr(b, o + 0x4C, 0x320)
        struct.pack_into(">I", b, o + 0x50, 0)
    struct.pack_into(">IIII", b, 0x200, 0, 1, 1, 1)
    return bytes(b)


class TestCrowd(unittest.TestCase):
    def test_parse(self):
        c = V.parse_crowd(make_crowd())
        self.assertEqual((c["nodes"], c["leaves"], c["depth"]), (1, 1, 0))
        self.assertEqual(len(c["spectators"]), 2)
        s = c["spectators"][1]
        self.assertEqual(s["model"], "Spectator02")
        self.assertEqual(s["setup"], "TS_SE03")
        self.assertEqual(s["pos"][0], 200.0)
        self.assertAlmostEqual(s["color_b"][2], 0.3, places=5)
        self.assertEqual(c["groups"], [(0, 1), (1, 1)])

    def test_bad_signature(self):
        with self.assertRaises(ValueError):
            V.parse_crowd(b"\0" * 0x100)

    def test_instances(self):
        inst = V.crowd_instances(V.parse_crowd(make_crowd()))
        col = {n: i for i, n in enumerate(inst["columns"])}
        r0, r1 = inst["rows"]
        self.assertEqual(inst["models"], ["Spectator02"])
        self.assertEqual(inst["setups"], ["TS_SE03"])
        self.assertAlmostEqual(r0[col["x"]], 1.0)
        self.assertAlmostEqual(r0[col["z"]], 3.0)          # z mirrored, cm -> m
        self.assertAlmostEqual(r0[col["yaw"]], -1.5)
        self.assertEqual((r0[col["tier"]], r1[col["tier"]]), (0, 1))
        self.assertEqual(V.crowd_quality(5, [(0, 1), (1, 1)]), 2)

    def test_setup_name(self):
        self.assertEqual(V.setup_name('X:/SetupList/Animation[@Name="TS_LJ04"]'), "TS_LJ04")
        self.assertEqual(V.setup_name("plain"), "plain")


class TestLights(unittest.TestCase):
    def test_packed_lights(self):
        b = bytearray(0x200)
        b[0x10:0x14] = b"\xff" * 4
        _desc(b, 0x14, 0x40, 1)
        o = 0x40
        b[0x100:0x108] = b"LightEnv"
        _relstr(b, o, 0x100)
        struct.pack_into(">I", b, o + 4, 0)
        b[o + 8] = 1
        struct.pack_into(">i", b, o + 0x0C, -1)
        struct.pack_into(">3ff4ff", b, o + 0x10, 1.0, 0.5, 0.25, 0.8, 0.5, 1, 1, 1, 1.1)
        L = V.parse_packed_lights(bytes(b))
        self.assertEqual(len(L), 1)
        self.assertEqual(L[0]["name"], "LightEnv")
        self.assertTrue(L[0]["used"])
        self.assertEqual(L[0]["color"], [1.0, 0.5, 0.25] if isinstance(L[0]["color"], list) else (1.0, 0.5, 0.25))
        self.assertAlmostEqual(L[0]["multiplier"], 1.1, places=5)
        self.assertEqual(L[0]["user"], [])


class TestCourtLines(unittest.TestCase):
    def test_quad_midpoints(self):
        pts = []
        for c, w in ((11.885, 0.2), (6.40, 0.2)):
            for x in (c - w / 2, c + w / 2):
                pts += [(x, 0, 0.5), (-x, 0, 0.6)]
        for c in (4.115, 5.485):
            for z in (c - 0.1, c + 0.1):
                pts += [(1.0, 0, z), (2.0, 0, -z)]
        chk = V.court_line_check(V.court_line_edges(pts))
        for k in ("baseline_x", "service_x", "singles_z", "doubles_z"):
            self.assertAlmostEqual(chk[k]["centre_minus_itf_cm"], 0.0, places=1, msg=k)
        self.assertAlmostEqual(chk["baseline_x"]["gameplay_minus_centre_cm"], 6.0, places=1)
        self.assertAlmostEqual(chk["singles_z"]["gameplay_minus_centre_cm"], 4.0, places=1)

    def test_missing_line(self):
        self.assertIsNone(V.court_line_check({"x": [], "z": []})["baseline_x"]["found"])


class TestClassify(unittest.TestCase):
    def test_classify(self):
        self.assertEqual(V.classify_archive(["CrowdAmsterdam.bin", "x"]), "venue")
        self.assertEqual(V.classify_archive(["TrackSide.hkx"]), "venue")
        self.assertIsNone(V.classify_archive(["Crowd_Huge_Full.bin", "Settings.bin"]))


@unittest.skipUnless(NODE, "node not installed")
class TestCrowdFsmNode(unittest.TestCase):
    def test_node(self):
        r = subprocess.run([NODE, "--test", os.path.join(ROOT, "port", "web", "test", "crowd_fsm.test.mjs")],
                           capture_output=True, text=True, timeout=120)
        self.assertEqual(r.returncode, 0, r.stdout[-2000:] + r.stderr[-2000:])


if __name__ == "__main__":
    unittest.main()
