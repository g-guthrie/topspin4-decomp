"""Tests for the G1b additions: list-payload port binding (tools/ts4_analyser.py) and the shot-error
scenario evaluator (tools/ts4_shot_error.py).  Every input is synthetic."""
import unittest

from tools import ts4_analyser as A
from tools import ts4_shot_error as E
from tests.test_analyser import Image, LayoutTests


class PayloadBindingTests(unittest.TestCase):
    def test_offset_past_struct_resolves_into_list_payload(self):
        L, buf = LayoutTests()._layout()
        types = L.parse_layout(buf)
        T_OUTER = LayoutTests.T_OUTER
        data = Image()
        data.f32(1.0, 2.0, 3.0, 4.0)              # a, b, sub.x, sub.y
        desc = data.here()
        data.u32(0, 2, 2)                         # lst header {rel, count, capacity}
        data.u32(0)                               # pad (payload starts at 0x20)
        data.set_rel(desc, data.here())
        data.f32(5.0, 6.0, 7.0, 8.0)              # lst[0].x, lst[0].y, lst[1].x, lst[1].y
        b = A.Bindings.__new__(A.Bindings)
        b.L, b.types, b.state = L, types, bytes(data.b)
        b._root_object = lambda root: 0
        saved = dict(A.ROOT_TYPES)
        A.ROOT_TYPES["player"] = T_OUTER
        try:
            self.assertEqual(b._payload_member("player", 0x24), [A.crc("lst"), "[0]", A.crc("y")])
            self.assertEqual(b._payload_member("player", 0x2C), [A.crc("lst"), "[1]", A.crc("y")])
            self.assertIsNone(b._payload_member("player", 0x40))
        finally:
            A.ROOT_TYPES.clear()
            A.ROOT_TYPES.update(saved)


class FakeBindings:
    """Port index -> (root, root offset); stands in for Bindings over State.bin + Layoutall.bin."""

    def __init__(self, table):
        self.table = table

    def bind(self, port):
        if port.index not in self.table:
            return None
        root, off = self.table[port.index]
        return {"root": root, "root_offset": off}


def node(kind, **fields):
    n = A.Node.__new__(A.Node)
    n.type, n.offset, n.kind, n.fields = 0, 0, kind, fields
    return n


class ShotErrorTests(unittest.TestCase):
    def setUp(self):
        # fault graph: S+0x718 = ramp of the timing value |t| from 0.3 to 1 -> 0..0.5, clamped later
        keys = [(-1.0, -0.3, 0.5, A.slope_fixup(-1.0, -0.3, 0.5, 0.0), 0.0),
                (-0.3, 0.3, 0.0, 0.0, 0.0),
                (0.3, 1.0, 0.0, A.slope_fixup(0.3, 1.0, 0.0, 0.5), 0.5)]
        fault = A.Graph(0x1, 3, [A.Port(0, 0, 0, [], 0, 0)], [A.Port(0, 1, 1, [], 0, 0)],
                        [node("CURVE", **{"in": 0, "out": 1, "keys": keys})], 0)
        net = A.Graph(0x2, 1, [], [A.Port(0, 0, 2, [], 0, 0)], [node("CONST", out=0, value=0.25)], 0)
        self.graphs = {500: fault, 501: net}
        self.bind = FakeBindings({0: ("player", 0x544), 1: ("player", 0x718), 2: ("player", 0x720)})
        self.saved = dict(E.SHOT_CLASSES)
        E.SHOT_CLASSES["Test"] = (501, 500)

    def tearDown(self):
        E.SHOT_CLASSES.clear()
        E.SHOT_CLASSES.update(self.saved)

    def test_error_probability_and_net_share(self):
        p, net = E.shot_error(self.graphs, self.bind, "Test", {("player", 0x544): 0.0})
        self.assertEqual((p, net), (0.0, 0.25))
        p, _ = E.shot_error(self.graphs, self.bind, "Test", {("player", 0x544): 1.0})
        self.assertAlmostEqual(p, 0.5, places=6)
        p, _ = E.shot_error(self.graphs, self.bind, "Test", {("player", 0x544): -0.65})
        self.assertAlmostEqual(p, 0.25, places=5)

    def test_parse_key(self):
        self.assertEqual(E.parse_key("timing"), ("player", 0x544))
        self.assertEqual(E.parse_key("Ball+0x344"), ("ball", 0x344))
        self.assertEqual(E.parse_key("S+0x770"), ("player", 0x770))
        with self.assertRaises(ValueError):
            E.parse_key("nope")


class LoaderTableTests(unittest.TestCase):
    def test_graph_1_to_4_loaders_and_dead_set_are_disjoint(self):
        for h in (0x3C58FC77, 0x4B5FCCE1, 0xD2569D5B, 0xA551ADCD):
            self.assertIn(h, A.CODE_LOADERS)
        self.assertFalse(set(A.CODE_LOADERS) & A.UNREFERENCED_GRAPHS)


class GraphRefsTests(unittest.TestCase):
    def test_lis_ori_and_lis_addi_constants(self):
        from tools import ts4_graph_refs as R
        lis_r9 = (15 << 26) | (9 << 21) | 0x3C58                 # lis r9, 0x3c58
        ori = (24 << 26) | (9 << 21) | (3 << 16) | 0xFC77         # ori r3, r9, 0xfc77
        lis_r8 = (15 << 26) | (8 << 21) | 0x8815                 # lis r8, 0x8815
        addi = (14 << 26) | (29 << 21) | (8 << 16) | 0xB910       # addi r29, r8, -0x46f0
        nop = 0x60000000
        c = R.code_constants([lis_r9, nop, ori, lis_r8, addi], 0x1000)
        self.assertEqual(c[0x3C58FC77], [0x1008])
        self.assertEqual(c[0x8814B910], [0x1010])
        far = [lis_r9] + [nop] * 12 + [ori]
        self.assertNotIn(0x3C58FC77, R.code_constants(far, 0))

    def test_based_stores(self):
        from tools import ts4_graph_refs as R
        addi = (14 << 26) | (11 << 21) | (11 << 16) | 0x500       # addi r11, r11, 0x500
        stfs = (52 << 26) | (31 << 21) | (11 << 16) | 0x64        # stfs f31, 0x64(r11)
        stb = (38 << 26) | (31 << 21) | (11 << 16) | 0x6E         # stb r31, 0x6e(r11)
        other = (52 << 26) | (31 << 21) | (12 << 16) | 0x64       # stfs f31, 0x64(r12): other base
        got = R.based_stores([addi, stfs, stb, other], 0x2000, (0x500,), {0x564, 0x56E})
        self.assertEqual(got, [(0x2004, 0x564), (0x2008, 0x56E)])

    def test_expressions_files_are_skipped(self):
        from tools import ts4_graph_refs as R
        head = Image()
        head.u32(*A.EXPRESSIONS_SIGNATURE)
        head.u32(0x10, 0, 0xFFFFFFFF, 8, A.EXPRESSIONS_ROOT_TYPE, 0)
        self.assertTrue(R.is_expressions(bytes(head.b)))
        self.assertFalse(R.is_expressions(b"\0" * 0x20))


if __name__ == "__main__":
    unittest.main()
