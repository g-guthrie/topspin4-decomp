"""Synthetic tests for tools/ts4data/career_data.py and the curve helpers of player_data.py (no game data)."""
import os
import struct
import sys
import unittest
import zlib

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools", "ts4data"))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import career_data as C  # noqa: E402
import player_data as P  # noqa: E402
import ts4_analyser as A  # noqa: E402

TYPE_OF = {v[0]: k for k, v in A.NODE_TYPES.items()}


def node(kind, **f):
    return A.Node(TYPE_OF[kind], 0, f)


def fake_pe(text_words):
    """Minimal PE image: one .text section holding big-endian PPC words."""
    e = 0x40
    text = struct.pack(">%dI" % len(text_words), *text_words)
    hdr = bytearray(0x200)
    struct.pack_into("<I", hdr, 0x3C, e)
    struct.pack_into("<H", hdr, e + 6, 1)            # one section
    struct.pack_into("<H", hdr, e + 20, 0xE0)        # optional header size
    struct.pack_into("<I", hdr, e + 24 + 28, 0x82000000)  # image base
    sec = e + 24 + 0xE0
    struct.pack_into("<8sIIII", hdr, sec, b".text", len(text), 0x1000, len(text), len(hdr))
    return bytes(hdr) + text


class CareerDataTest(unittest.TestCase):
    def test_code_sites_finds_skill_constant(self):
        c = zlib.crc32(b"PoisonedSlices")
        lis = (15 << 26) | (3 << 21) | (c >> 16)              # lis r3, hi
        ori = (24 << 26) | (3 << 21) | (3 << 16) | (c & 0xFFFF)  # ori r3, r3, lo
        words = [0x60000000, 0x7D8802A6, 0x60000000, lis, ori, 0x4E800020]
        sites = C.code_sites(fake_pe(words))
        self.assertEqual(sites, [{"skill": "PoisonedSlices", "address": "0x82001010", "function": "fn_82001004"}])

    def test_forward_slice(self):
        g = A.Graph(0, 8, [], [], [node("CURVE", **{"in": 0, "out": 1, "keys": []}),
                                   node("LERP", a=2, b=3, t=1, out=4),
                                   node("CURVE", **{"in": 5, "out": 6, "keys": []})], 0)
        dep, nodes = C.forward_slice(g, {0})
        self.assertEqual(dep, {0, 1, 4})
        self.assertEqual(len(nodes), 2)
        self.assertEqual(C.node_inputs(g.nodes[1]), [2, 3, 1])

    def test_style_names_crc(self):
        for key, (name, grade, _ev) in C.AI_STYLE_NAMES.items():
            if grade == "V":
                self.assertEqual("%08x" % zlib.crc32(name.encode()), key)


class CurveModeTest(unittest.TestCase):
    KEYS = [(30.0, 50.0, 0.0, 0.0, 0.2), (50.0, 80.0, 0.2, 0.0, 0.8)]

    def test_ramp_default(self):
        k = [P.curve_key(x) for x in self.KEYS]
        self.assertAlmostEqual(k[0][3], 0.01)
        self.assertAlmostEqual(P.eval_curve(k, 40.0), 0.1)
        self.assertAlmostEqual(P.eval_curve(k, 65.0), 0.5)
        self.assertAlmostEqual(P.eval_curve(k, 10.0), 0.0)
        self.assertAlmostEqual(P.eval_curve(k, 200.0), 0.8)

    def test_step_option(self):
        k = [P.curve_key(x, "step", 0.0) for x in self.KEYS]
        self.assertAlmostEqual(P.eval_curve(k, 40.0), 0.0)
        self.assertAlmostEqual(P.eval_curve(k, 65.0), 0.2)

    def test_profile_from_rating_maps_cells(self):
        g = {"name_hash": "8c9b26e0", "name": "DefaultAttributes",
             "graph": {"inputs": [{"slot": 3, "index": 47}],
                       "nodes": [{"in": 3, "keys": [P.curve_key(x) for x in self.KEYS]}]}}
        out = P.profile_from_rating([g], "ramp")
        self.assertEqual(out[0]["stat"], "Serve")
        self.assertEqual(out[0]["samples"][40], 0.1)

    def test_yaml_quotes_question_mark(self):
        self.assertEqual(P._scalar("a??)"), '"a??)"')


if __name__ == "__main__":
    unittest.main()
