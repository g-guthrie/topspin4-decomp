"""Tests for tools/ts4_analyser.py.  Every input is a synthetic byte string built here."""
import math
import struct
import unittest

from tools import ts4_analyser as A

H_CURVE, H_CONST, H_SUM = 0x993894C6, 0x6BBD0182, 0xDEE0059F
H_PROD, H_MIN, H_MAX = 0x9DA3605F, 0xDCCE2909, 0xFB754E38
H_RUN, H_SUB, H_DIV = 0x7A741F05, 0x8196EAE3, 0xB6EA415E
H_LERP, H_INV = 0x7E683220, 0xA68E1DC3


class Image:
    """Tiny writer for relocatable big-endian images (self-relative arrays)."""

    def __init__(self):
        self.b = bytearray()

    def here(self):
        return len(self.b)

    def u32(self, *vals):
        for v in vals:
            self.b += struct.pack(">I", v & 0xFFFFFFFF)

    def f32(self, *vals):
        for v in vals:
            self.b += struct.pack(">f", v)

    def patch(self, off, v):
        self.b[off:off + 4] = struct.pack(">I", v & 0xFFFFFFFF)

    def set_rel(self, desc_off, target_off):
        self.patch(desc_off, target_off - desc_off)


def build_path(img, names, kind=0x30001, with_tail=True):
    """Name-path record: {0xC,1,1} {8,fcf73e23} {8,kind} {0xC,n,n} n*{rel,type} leaves."""
    t = img.here()
    img.u32(0xC, 1, 1)
    img.u32(8, 0xFCF73E23)
    img.u32(8, kind)
    desc = img.here()
    img.u32(0xC, len(names) + (1 if with_tail else 0), len(names) + (1 if with_tail else 0))
    elems = img.here()
    n_el = len(names) + (1 if with_tail else 0)
    for _ in range(n_el):
        img.u32(0, 0)
    leaves = []
    for h in names:
        leaves.append(img.here())
        img.u32(0x10, 0x270000, h, 0x10000, 0, 0, 0)
    tail = None
    if with_tail:
        tail = img.here()
        img.u32(8, 0x40001, 0xC, 0, 0)
    order = leaves + ([tail] if with_tail else [])
    for i, off in enumerate(order):
        e = elems + 8 * i
        img.patch(e, off - e)
        img.patch(e + 4, 0x67860A08 if i < len(names) else 0xFCF73E23)
    return t


def node_record(img, kind, **f):
    """Write a node record and return its offset."""
    rec = img.here()
    if kind in ("SUM", "PRODUCT", "MIN", "MAX", "RUNSUM"):
        img.u32(0x10, len(f["slots"]), len(f["slots"]), f["out"])
        img.u32(*f["slots"])
    elif kind == "CURVE":
        img.u32(0x14, len(f["keys"]), len(f["keys"]), f["in"], f["out"] & 0xFFFFFFFF)
        for k in f["keys"]:
            img.f32(*k[:4])
            img.u32(k[4] if len(k) > 4 else 0)
    elif kind in ("SUB", "DIV"):
        img.u32(f["a"], f["b"], f["out"])
    elif kind in ("LERP", "INVLERP"):
        img.u32(f["a"], f["b"], f["t"], f["out"])
    elif kind == "CONST":
        img.u32(f["out"])
        img.f32(f["value"])
    return rec


TYPE_OF = {"CONST": H_CONST, "SUM": H_SUM, "PRODUCT": H_PROD, "MIN": H_MIN, "MAX": H_MAX,
           "CURVE": H_CURVE, "RUNSUM": H_RUN, "SUB": H_SUB, "DIV": H_DIV, "LERP": H_LERP, "INVLERP": H_INV}


def build_expressions(graphs):
    """graphs: list of dict(name, nregs, inputs=[(domain, slot, index, names)], outputs=[...],
    nodes=[(kind, fields)]).  Returns the file image."""
    img = Image()
    img.u32(*A.EXPRESSIONS_SIGNATURE)
    img.u32(0x10, 0, 0xFFFFFFFF)
    while img.here() < A.ROOT_OFF:
        img.u32(0)
    img.u32(8, A.EXPRESSIONS_ROOT_TYPE)
    root_desc = img.here()
    img.u32(0, len(graphs), len(graphs))
    arr = img.here()
    img.set_rel(root_desc, arr)
    img.b += b"\x00" * (A.GRAPH_STRIDE * len(graphs))
    for gi, g in enumerate(graphs):
        base = arr + A.GRAPH_STRIDE * gi
        img.patch(base, g["nregs"])
        img.patch(base + 0x28, g["name"])
        for off, ports in ((4, g["inputs"]), (0x10, g["outputs"])):
            first = img.here()
            img.b += b"\x00" * (A.PORT_STRIDE * len(ports))
            for i, (dom, slot, idx, names) in enumerate(ports):
                p = first + A.PORT_STRIDE * i
                path = build_path(img, names)
                img.patch(p, dom)
                img.patch(p + 4, path - (p + 4))
                img.patch(p + 0x10, slot)
                img.patch(p + 0x14, idx)
            img.patch(base + off + 4, len(ports))
            img.patch(base + off + 8, len(ports))
            img.patch(base + off, (first - (base + off)) if ports else 0xFFFFFFFF)
        recs = [node_record(img, k, **f) for k, f in g["nodes"]]
        nfirst = img.here()
        img.b += b"\x00" * (8 * len(recs))
        for i, ((k, _), rec) in enumerate(zip(g["nodes"], recs)):
            e = nfirst + 8 * i
            img.patch(e, rec - e)
            img.patch(e + 4, TYPE_OF[k])
        img.patch(base + 0x1C + 4, len(recs))
        img.patch(base + 0x1C + 8, len(recs))
        img.patch(base + 0x1C, (nfirst - (base + 0x1C)) if recs else 0xFFFFFFFF)
    return bytes(img.b)


def run(kind, vals, **f):
    """Evaluate one node on a register file and return the output register."""
    regs = list(vals) + [0.0] * 8
    node = A.Node(TYPE_OF[kind], 0, f)
    A.evaluate_node(node, regs)
    return regs[f["out"]]


class CurveTests(unittest.TestCase):
    KEYS = [(0.0, 2.0, 10.0, 3.0, 0), (5.0, 9.0, 20.0, -1.0, 0)]

    def test_segment_interpolation(self):
        self.assertEqual(A.eval_curve(1.0, self.KEYS), 13.0)

    def test_clamped_to_segment_end(self):
        # x beyond x1 of the first segment but below the next key: offset is clamped to x1 - x0
        self.assertEqual(A.eval_curve(4.0, self.KEYS), 16.0)

    def test_second_segment_and_beyond(self):
        self.assertEqual(A.eval_curve(6.0, self.KEYS), 19.0)
        self.assertEqual(A.eval_curve(100.0, self.KEYS), 16.0)   # clamp to x1 - x0 = 4

    def test_below_first_key_uses_first_segment_with_zero_offset(self):
        self.assertEqual(A.eval_curve(-7.0, self.KEYS), 10.0)

    def test_nan_input_does_not_crash(self):
        self.assertTrue(isinstance(A.eval_curve(math.nan, self.KEYS), float))


class KernelTests(unittest.TestCase):
    def test_const(self):
        self.assertEqual(run("CONST", [], out=3, value=2.5), 2.5)

    def test_sum_product_chain(self):
        self.assertEqual(run("SUM", [1.0, 2.0, 3.0, 4.0, 5.0, 6.0], slots=[0, 1, 2, 3, 4, 5], out=6), 21.0)
        self.assertEqual(run("PRODUCT", [1.0, 2.0, 3.0, 4.0, 5.0], slots=[0, 1, 2, 3, 4], out=5), 120.0)

    def test_single_input_variadic(self):
        self.assertEqual(run("SUM", [7.0], slots=[0], out=2), 7.0)

    def test_min_max(self):
        self.assertEqual(run("MIN", [3.0, -2.0, 5.0, 1.0], slots=[0, 1, 2, 3], out=4), -2.0)
        self.assertEqual(run("MAX", [3.0, -2.0, 5.0, 1.0], slots=[0, 1, 2, 3], out=4), 5.0)

    def test_min_max_nan_handling_follows_fsel(self):
        # MIN keeps the accumulator when the compare is unordered; MAX takes the new value
        self.assertEqual(run("MIN", [3.0, math.nan], slots=[0, 1], out=2), 3.0)
        self.assertTrue(math.isnan(run("MAX", [3.0, math.nan], slots=[0, 1], out=2)))

    def test_sub_div(self):
        self.assertEqual(run("SUB", [9.0, 4.0], a=0, b=1, out=2), 5.0)
        self.assertEqual(run("DIV", [9.0, 4.0], a=0, b=1, out=2), 2.25)
        self.assertEqual(run("DIV", [1.0, 0.0], a=0, b=1, out=2), math.inf)
        self.assertEqual(run("DIV", [-1.0, 0.0], a=0, b=1, out=2), -math.inf)
        self.assertTrue(math.isnan(run("DIV", [0.0, 0.0], a=0, b=1, out=2)))

    def test_lerp_clamps_t(self):
        self.assertEqual(run("LERP", [10.0, 20.0, 0.25], a=0, b=1, t=2, out=3), 12.5)
        self.assertEqual(run("LERP", [10.0, 20.0, 5.0], a=0, b=1, t=2, out=3), 20.0)
        self.assertEqual(run("LERP", [10.0, 20.0, -5.0], a=0, b=1, t=2, out=3), 10.0)
        self.assertEqual(run("LERP", [10.0, 20.0, math.nan], a=0, b=1, t=2, out=3), 10.0)

    def test_invlerp_clamps_result(self):
        self.assertEqual(run("INVLERP", [10.0, 20.0, 15.0], a=0, b=1, t=2, out=3), 0.5)
        self.assertEqual(run("INVLERP", [10.0, 20.0, 99.0], a=0, b=1, t=2, out=3), 1.0)
        self.assertEqual(run("INVLERP", [10.0, 20.0, 0.0], a=0, b=1, t=2, out=3), 0.0)
        self.assertEqual(run("INVLERP", [10.0, 10.0, 10.0], a=0, b=1, t=2, out=3), 0.0)   # 0/0 -> NaN -> 0

    def test_running_sum_negative_gives_minus_one(self):
        self.assertEqual(run("RUNSUM", [1.0, 2.0, 3.0], slots=[0, 1, 2], out=3), 6.0)
        self.assertEqual(run("RUNSUM", [1.0, -0.5, 3.0], slots=[0, 1, 2], out=3), -1.0)

    def test_curve_node_negative_output_slot_is_skipped(self):
        regs = [1.0, 5.0]
        node = A.Node(H_CURVE, 0, {"in": 0, "out": -1, "keys": [(0, 1, 2, 3, 0)]})
        A.evaluate_node(node, regs)
        self.assertEqual(regs, [1.0, 5.0])

    def test_single_precision_rounding(self):
        # 16777216 + 1 is not representable in single precision
        self.assertEqual(run("SUM", [16777216.0, 1.0], slots=[0, 1], out=2), 16777216.0)


class ParseTests(unittest.TestCase):
    def setUp(self):
        self.graphs = [
            dict(name=A.crc("Alpha"), nregs=6,
                 inputs=[(0x1BF15200, 2, 7, [0x11111111]), (0x1BF15200, 0, 8, [0x22222222, 0x33333333])],
                 outputs=[(0x9D7C7C58, 5, 9, [0x44444444])],
                 nodes=[("CURVE", dict(**{"in": 2}, out=4, keys=[(0.0, 1.5, 1.0, 0.0), (1.5, 3.0, 1.0, 2.0)])),
                        ("CURVE", dict(**{"in": 0}, out=3, keys=[(0.0, 10.0, 0.0, 1.0)])),
                        ("CONST", dict(out=1, value=0.5)),
                        ("LERP", dict(a=4, b=3, t=1, out=5))]),
            dict(name=A.crc("Beta"), nregs=4, inputs=[(0x1BF15200, 0, -1, [0xAAAAAAAA])], outputs=[],
                 nodes=[]),
        ]
        self.image = build_expressions(self.graphs)

    def test_parse_counts_and_ports(self):
        gs = A.parse_expressions(self.image)
        self.assertEqual(len(gs), 2)
        a, b = gs
        self.assertEqual((a.name, a.nregs), (A.crc("Alpha"), 6))
        self.assertEqual([(p.domain, p.slot, p.index) for p in a.inputs],
                         [(0x1BF15200, 2, 7), (0x1BF15200, 0, 8)])
        self.assertEqual([p.path for p in a.inputs], [[0x11111111], [0x22222222, 0x33333333]])
        self.assertEqual(a.inputs[0].path_kind, 0x30001)
        self.assertEqual((a.outputs[0].domain, a.outputs[0].slot), (0x9D7C7C58, 5))
        self.assertEqual([n.kind for n in a.nodes], ["CURVE", "CURVE", "CONST", "LERP"])
        self.assertEqual(b.inputs[0].index, -1)
        self.assertEqual(b.outputs, [])
        self.assertEqual(b.nodes, [])

    def test_curve_keys_roundtrip(self):
        a = A.parse_expressions(self.image)[0]
        self.assertEqual(a.nodes[0].fields["keys"][1][:4], (1.5, 3.0, 1.0, 2.0))
        self.assertEqual(a.nodes[0].fields["in"], 2)

    def test_validate_and_topology(self):
        a = A.parse_expressions(self.image)[0]
        self.assertEqual(A.validate_graph(a), [])
        # output slot 5 depends on both inputs (curves of regs 2 and 0)
        self.assertEqual(A.topology(a), [(5, [0, 1])])

    def test_evaluate_graph(self):
        a = A.parse_expressions(self.image)[0]
        # reg4 = curve(in0=1.0) = 1.0 ; reg3 = curve(in1=4.0) = 4.0 ; reg1 = 0.5 ; lerp = 1 + .5*(4-1)
        self.assertEqual(A.evaluate(a, [1.0, 4.0]), [2.5])
        self.assertEqual(A.evaluate(a, {0: 1.0, 1: 4.0}), [2.5])
        with self.assertRaises(ValueError):
            A.evaluate(a, [1.0])

    def test_validate_reports_bad_register(self):
        gs = [dict(name=1, nregs=2, inputs=[(0, 5, 0, [1])], outputs=[], nodes=[])]
        g = A.parse_expressions(build_expressions(gs))[0]
        self.assertTrue(A.validate_graph(g))

    def test_unknown_node_type_is_kept_and_skipped(self):
        img = bytearray(self.image)
        gs = A.parse_expressions(bytes(img))
        entry = gs[0].nodes[2].offset      # record of the CONST node; find its 8-byte entry
        data = bytes(img)
        pos = None
        for i in range(0, len(data) - 8, 4):
            rel, typ = struct.unpack_from(">iI", data, i)
            if typ == H_CONST and i + rel == entry:
                pos = i
        self.assertIsNotNone(pos)
        struct.pack_into(">I", img, pos + 4, 0xDEADBEEF)
        g = A.parse_expressions(bytes(img))[0]
        self.assertIsNone(g.nodes[2].kind)
        self.assertIn("unknown node type deadbeef", A.validate_graph(g)[0])
        self.assertEqual(A.evaluate(g, [1.0, 4.0]), [1.0 + 0.0 * 3.0])   # reg1 stays 0 -> lerp gives a

    def test_header_validation(self):
        with self.assertRaises(ValueError):
            A.parse_expressions(b"\x00" * 64)
        with self.assertRaises(ValueError):
            A.parse_expressions(b"\x00" * 8 + self.image[8:])
        bad = bytearray(self.image)
        struct.pack_into(">I", bad, 0x18, 0x12345678)
        with self.assertRaises(ValueError):
            A.parse_expressions(bytes(bad))

    def test_truncated_array_is_rejected(self):
        with self.assertRaises(ValueError):
            A.parse_expressions(self.image[:A.ROOT_OFF + 0x18])

    def test_json_dump(self):
        a = A.parse_expressions(self.image)[0]
        j = a.to_json({A.crc("Alpha"): "Alpha"})
        self.assertEqual(j["name"], "Alpha")
        self.assertEqual(j["nodes"][3]["kind"], "LERP")
        self.assertEqual(j["inputs"][1]["path"], ["22222222", "33333333"])


class HelperTests(unittest.TestCase):
    def test_crc_matches_zlib_names(self):
        self.assertEqual(A.crc("Volley"), 0x71198650)
        self.assertEqual(A.crc("LetProbability"), 0xBDD29CAD)

    def test_known_names_are_real_preimages(self):
        for h, n in A.known_names().items():
            self.assertEqual(A.crc(n), h, n)

    def test_node_kernel_table(self):
        self.assertEqual(len(A.NODE_TYPES), 11)
        self.assertEqual(A.NODE_TYPES[0x993894C6][0], "CURVE")

    def test_module_summary_rejects_other_files(self):
        with self.assertRaises(ValueError):
            A.framework_module_summary(b"\x00" * 64)

    def test_module_summary(self):
        img = Image()
        img.u32(0xA5D091F1, 0x1FB5171F, 8, 0, 0xFFFFFFFF)
        img.u32(8, A.FRAMEWORK_MODULE_ROOT_TYPE, 0xC, 0, 0, A.crc("CAnalyserAgentExpr"))
        s = A.framework_module_summary(bytes(img.b))
        self.assertEqual(s["agent_class_words"]["CAnalyserAgentExpr"], 1)
        self.assertFalse(s["has_module_name"])


if __name__ == "__main__":
    unittest.main()
