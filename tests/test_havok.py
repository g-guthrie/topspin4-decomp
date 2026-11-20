"""Unit tests for tools/havok on synthetic byte strings (no game data)."""
import math
import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools" / "havok"))

import classes  # noqa: E402
import delta  # noqa: E402
import packfile  # noqa: E402
import skeleton  # noqa: E402
import spline  # noqa: E402


def build_packfile():
    """Tiny big-endian packfile: hkRootLevelContainer -> one named variant -> hkaSkeleton."""
    # __classnames__
    cn = bytearray()
    names = {}
    for n in ("hkRootLevelContainer", "hkaSkeleton", "hkaBone"):
        cn += struct.pack(">I", 0x12345678) + b"\x09"
        names[n] = len(cn)
        cn += n.encode() + b"\0"
    while len(cn) % 16:
        cn += b"\xff"
    # __data__
    d = bytearray(0x100)
    local, virt = [], []
    # root container @0: namedVariants {ptr, count=1}
    struct.pack_into(">I", d, 4, 1)
    local.append((0, 0x10))
    # named variant @0x10: name*, className*, variant{obj*, class*}
    local += [(0x10, 0x80), (0x14, 0x90), (0x18, 0x30)]
    # skeleton @0x30: name*, parentIndices{ptr,2}, bones{ptr,2}, refPose{ptr,0}, floatSlots{ptr,0}
    local.append((0x30, 0xA0))
    struct.pack_into(">I", d, 0x38, 2)
    local.append((0x34, 0x60))
    struct.pack_into(">I", d, 0x40, 2)
    local.append((0x3C, 0x68))
    struct.pack_into(">hh", d, 0x60, -1, 0)
    local += [(0x68, 0x70), (0x6C, 0x78)]           # bone pointers
    local += [(0x70, 0xB0), (0x78, 0xB8)]           # bone names
    d[0x80:0x84] = b"var\0"
    d[0x90:0x9C] = b"hkaSkeleton\0"
    d[0xA0:0xA5] = b"root\0"
    d[0xB0:0xB2] = b"a\0"
    d[0xB8:0xBA] = b"b\0"
    virt += [(0x00, 0, names["hkRootLevelContainer"]), (0x30, 0, names["hkaSkeleton"]),
             (0x70, 0, names["hkaBone"]), (0x78, 0, names["hkaBone"])]
    loc = b"".join(struct.pack(">II", *x) for x in local)
    loc += b"\xff" * ((-len(loc)) % 16)
    vir = b"".join(struct.pack(">III", *x) for x in virt)
    vir += b"\xff" * ((-len(vir)) % 16)
    data_sec = bytes(d) + loc + vir
    sections = [("__classnames__", bytes(cn), len(cn), len(cn), len(cn)),
                ("__types__", b"", 0, 0, 0),
                ("__data__", data_sec, len(d), len(d) + len(loc), len(d) + len(loc))]
    hdr = struct.pack(">IIII", 0x57E0E057, 0x10C0C010, 0, 5) + bytes([4, 0, 0, 1])
    hdr += struct.pack(">5I", 3, 2, 0, 0, names["hkRootLevelContainer"])
    hdr += b"Havok-5.5.0-r1\0\xff" + struct.pack(">II", 0, 0)
    start = 0x40 + 0x30 * 3
    out_hdrs, blobs = b"", b""
    for name, blob, loc_off, glob_off, virt_off in sections:
        end = len(blob)
        out_hdrs += name.encode().ljust(19, b"\0") + b"\xff"
        out_hdrs += struct.pack(">7I", start + len(blobs), loc_off, glob_off, virt_off, end, end, end)
        blobs += blob
    return hdr + out_hdrs + blobs


# Minimal layouts for the synthetic file above (written for this test; the real tables
# are generated locally by tools/havok/dll_classes.py and never committed).
SYNTHETIC_LAYOUTS = {
    "hkRootLevelContainer": {"size": 8, "members": [
        {"name": "namedVariants", "type": 26, "subtype": 25, "offset": 0, "cls": "NamedVariant"}]},
    "NamedVariant": {"size": 0x10, "members": [
        {"name": "name", "type": 29, "offset": 0}, {"name": "className", "type": 29, "offset": 4},
        {"name": "variant", "type": 28, "offset": 8}]},
    "hkaSkeleton": {"size": 0x24, "members": [
        {"name": "name", "type": 29, "offset": 0},
        {"name": "parentIndices", "type": 26, "subtype": 5, "offset": 4},
        {"name": "bones", "type": 26, "subtype": 20, "offset": 0xC, "cls": "hkaBone"},
        {"name": "referencePose", "type": 26, "subtype": 16, "offset": 0x14},
        {"name": "floatSlots", "type": 26, "subtype": 29, "offset": 0x1C}]},
    "hkaBone": {"size": 8, "members": [
        {"name": "name", "type": 29, "offset": 0}, {"name": "lockTranslation", "type": 1, "offset": 4}]},
}


class PackfileTests(unittest.TestCase):
    def test_header_and_fixups(self):
        pf = packfile.Packfile(build_packfile())
        self.assertEqual(pf.version, "Havok-5.5.0-r1")
        self.assertEqual((pf.ptr_size, pf.little_endian), (4, 0))
        self.assertEqual([s.name for s in pf.sections], ["__classnames__", "__types__", "__data__"])
        self.assertEqual(pf.ptr(2, 0x18), (2, 0x30))
        self.assertEqual(pf.string_ptr(2, 0x10), "var")
        self.assertEqual(pf.obj_class[(2, 0x30)], "hkaSkeleton")
        self.assertEqual(pf.contents(), (2, 0, "hkRootLevelContainer"))

    def test_reflection_reader(self):
        pf = packfile.Packfile(build_packfile())
        reg = classes.Registry.from_packfile(pf, classes.from_dict(SYNTHETIC_LAYOUTS))
        root = reg.read_object(pf, 2, 0, "hkRootLevelContainer")
        nv = root["namedVariants"][0]
        self.assertEqual(nv["className"], "hkaSkeleton")
        sk = skeleton.Skeleton(nv["variant"].get())
        self.assertEqual(sk.name, "root")
        self.assertEqual(sk.parents, [-1, 0])
        self.assertEqual(sk.bones, ["a", "b"])


def encode_threecomp40(q):
    q = list(q)
    idx = max(range(4), key=lambda i: abs(q[i]))
    neg = 1 if q[idx] < 0 else 0
    rest = [c for i, c in enumerate(q) if i != idx]
    v = 0
    for i, c in enumerate(rest):
        code = int(round((c + spline.INV_SQRT2) / spline.THREECOMP40_SCALE))
        v |= max(0, min(4095, code)) << (12 * i)
    v |= idx << 36 | neg << 38
    return v.to_bytes(5, "little")


class QuaternionTests(unittest.TestCase):
    def test_threecomp40_roundtrip(self):
        for q in ([0, 0, 0, 1], [0.5, -0.5, 0.5, -0.5], [0.9, 0.1, -0.3, 0.2985], [0.1, -0.95, 0.2, 0.2]):
            n = math.sqrt(sum(c * c for c in q))
            q = [c / n for c in q]
            out = spline.decode_threecomp40(encode_threecomp40(q))
            for a, b in zip(q, out):
                self.assertAlmostEqual(a, b, delta=5e-4)

    def test_threecomp40_bit_positions(self):
        # dropped component index 2, sign bit set, stored components all at the midpoint code 2047
        v = 2047 | 2047 << 12 | 2047 << 24 | 2 << 36 | 1 << 38
        q = spline.decode_threecomp40(v.to_bytes(5, "little"))
        self.assertLess(q[2], -0.99)
        self.assertAlmostEqual(q[0], q[1])
        self.assertAlmostEqual(q[0], q[3])


class SplineTests(unittest.TestCase):
    def test_find_span_and_basis(self):
        knots = [0, 0, 0, 5, 10, 10, 10]  # degree 2, 4 control points
        self.assertEqual(spline.find_span(3, 2, 0, knots), 2)
        self.assertEqual(spline.find_span(3, 2, 7, knots), 3)
        self.assertEqual(spline.find_span(3, 2, 10, knots), 3)
        n = spline.basis(3, 7.0, 2, [float(k) for k in knots])
        self.assertAlmostEqual(sum(n), 1.0)

    def test_clamped_endpoints_and_linear(self):
        pts = [(0.0,), (3.0,), (6.0,), (9.0,)]
        knots = [0, 0, 3, 6, 9, 9]  # degree 1: piecewise linear through points
        for f in (0, 1.5, 3, 4.5, 9):
            self.assertAlmostEqual(spline.evaluate(knots, 1, pts, f, 1.0)[0], f)
        knots3 = [0, 0, 0, 0, 9, 9, 9, 9]  # cubic Bezier
        self.assertAlmostEqual(spline.evaluate(knots3, 3, pts, 0.0, 1.0)[0], 0.0)
        self.assertAlmostEqual(spline.evaluate(knots3, 3, pts, 9.0, 1.0)[0], 9.0)

    def test_block_parse(self):
        # one track: position spline on Y (BITS8), static rotation THREECOMP40, identity scale
        quant = 0 | (spline.THREECOMP40 << 2)
        blk = bytearray(struct.pack("4B", quant, 0x20, 0x01, 0x00))
        blk += struct.pack("<HB", 1, 1) + bytes([0, 0, 4, 4])  # n=1, degree 1, knots
        while len(blk) % 4:
            blk.append(0)
        blk += struct.pack("<2f", -1.0, 1.0)  # y min/max
        blk += bytes([0, 255])  # two control points (align 2 already satisfied)
        while len(blk) % 4:
            blk.append(0)
        blk += encode_threecomp40([0, 0, 0, 1])
        while len(blk) % 4:
            blk.append(0)
        tracks, end = spline.parse_block(bytes(blk), 0, 1, 4, "<")
        self.assertEqual(end, len(blk))
        pos, rot, scl = tracks[0]
        self.assertAlmostEqual(pos.sample(0.0, 0.1)[1], -1.0)
        self.assertAlmostEqual(pos.sample(0.4, 0.1)[1], 1.0, places=5)
        self.assertAlmostEqual(pos.sample(0.2, 0.1)[1], 0.0, places=5)
        self.assertAlmostEqual(rot.sample(0.0, 0.1)[3], 1.0, places=3)
        self.assertEqual(scl.sample(0.0, 0.1), [1.0, 1.0, 1.0])


class QuantizedTests(unittest.TestCase):
    def test_bitreader_lsb_first_u16_words(self):
        data = struct.pack("<HH", 0b1010_0000_0011_0111, 0x0001)
        br = delta.BitReader(data, 0)
        self.assertEqual(br.bits(4), 0b0111)
        self.assertEqual(br.bits(10), 0b10_0000_0011)
        self.assertEqual(br.bits(3), 0b110)  # top two bits of word 0, then bit 0 of word 1

    def test_delta_channel(self):
        bw, n = 4, 4
        words = 1 | 2 << 4 | 3 << 8  # codes after the preserved value
        blob = struct.pack("<f", 10.0) + struct.pack("<H", words)
        vals, used = delta.unpack_channel(blob, 0, n, bw, 1, 16.0, -1.0)
        self.assertEqual(used, 4 + 2)
        self.assertEqual(vals, [10.0, 0.5, 1.5, 2.5])
        self.assertEqual(delta.prefix_sum(vals), [10.0, 10.5, 12.0, 14.5])

    def test_wavelet_roundtrip_and_basis(self):
        x = [math.sin(i * 0.3) for i in range(16)]
        y = delta.inverse_wavelet(delta.forward_wavelet(x))
        for a, b in zip(x, y):
            self.assertAlmostEqual(a, b)
        self.assertEqual(delta.inverse_wavelet([1.0] + [0.0] * 7), [1.0] * 8)
        self.assertEqual(delta.inverse_wavelet([0, 1.0] + [0.0] * 6), [-0.5, -0.25, 0.0, 0.25, 0.5, 0.5, 0.5, 0.5])

    def test_wavelet_channel_zero_mask(self):
        bw, n = 8, 4
        scale, offset = 2.0, -1.0
        zero = int(-offset / scale * 256)
        mask = bytes([0b0101])  # entries 0 and 2 are zero-coded
        codes = struct.pack("<H", 200 | 50 << 8)
        vals, used = delta.wavelet_channel(mask + codes, 0, n, bw, 0, scale, offset)
        self.assertEqual(used, (4 + 2 * 8 + 7) // 8)
        self.assertAlmostEqual(vals[0], delta.dequantize(zero, bw, scale, offset))
        self.assertAlmostEqual(vals[1], delta.dequantize(200, bw, scale, offset))
        self.assertAlmostEqual(vals[3], delta.dequantize(50, bw, scale, offset))

    def test_assemble_masks(self):
        # track 0: static pos, static rot with w placeholder +2, identity scale
        m0 = 1 | 1 << 2 | 2 << 4
        # track 1: identity pos, rot with z dynamic (bit 10), identity scale
        m1 = 2 | 0 << 2 | 2 << 4 | 1 << 10
        statics = [1.0, 2.0, 3.0, 0.6, 0.0, 0.0, 2.0, 0.0, 0.0, -2.0]
        out = delta.assemble([m0, m1], statics, [0.8])
        self.assertEqual(out[0][0], [1.0, 2.0, 3.0])
        self.assertAlmostEqual(out[0][1][3], 0.8)
        self.assertEqual(out[0][2], [1.0, 1.0, 1.0])
        self.assertEqual(out[1][0], [0.0, 0.0, 0.0])
        self.assertAlmostEqual(out[1][1][2], 0.8)
        self.assertAlmostEqual(out[1][1][3], -0.6)
        self.assertEqual(delta.count_dofs([m0, m1]), (10, 1))


class RegistryTests(unittest.TestCase):
    def test_missing_json_message(self):
        with self.assertRaises(classes.MissingClasses) as cm:
            classes.load_json("/nonexistent/classes.json")
        self.assertIn("dll_classes.py", str(cm.exception))

    def test_enum_and_inheritance(self):
        reg = classes.Registry(classes.from_dict({
            "Base": {"size": 8, "members": [{"name": "a", "type": 7, "offset": 4}]},
            "Derived": {"size": 0xC, "parent": "Base", "members": [
                {"name": "kind", "type": 24, "subtype": 3, "offset": 8, "enum": "Kind"}],
                "enums": {"Kind": {"0": "ZERO", "1": "ONE"}}}}))
        self.assertEqual([m.name for m in reg.all_members("Derived")], ["a", "kind"])
        self.assertEqual(reg.find_enum("Derived", "Kind")[1], "ONE")


class MathTests(unittest.TestCase):
    def test_affine_inverse(self):
        m = skeleton.trs_matrix([1, 2, 3], [0.2, 0.3, 0.1, math.sqrt(1 - 0.14)], [1, 1, 1])
        i = skeleton.mat_inverse_affine(m)
        p = skeleton.mat_mul(m, i)
        for k in range(16):
            self.assertAlmostEqual(p[k], 1.0 if k % 5 == 0 else 0.0)


if __name__ == "__main__":
    unittest.main()
