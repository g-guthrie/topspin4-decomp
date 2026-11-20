"""Tests for tools/xex_write.py and tools/modpatch.py. Synthetic data only: no game file is read."""
import os
import random
import struct
import sys
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

import modpatch  # noqa: E402
import xex_patch  # noqa: E402
import xex_write  # noqa: E402

BASE = 0x88000000
IMG_SIZE = 0x40000


def synthetic_image():
    img = bytearray(IMG_SIZE)
    img[0:2] = b"MZ"
    rnd = random.Random(1)
    for i in range(0x1000, 0x3000):
        img[i] = rnd.randrange(256)
    return bytes(img)


def synthetic_xex(image_size=IMG_SIZE, compressed_header=True):
    """A minimal XEX2 shell: header table with a 0x3FF (LZX/AES style) block, security info, no real data."""
    hdr = bytearray(0x400)
    hdr[0:4] = b"XEX2"
    sec = 0x100
    struct.pack_into(">IIIII", hdr, 4, 9, 0x400, 0, sec, 2)
    struct.pack_into(">II", hdr, 0x18, 0x3FF, 0x40)
    struct.pack_into(">II", hdr, 0x20, 0x10201, BASE)
    # old 0x3FF block: size 0x24, enc 1, comp 2, window, block size, sha1
    struct.pack_into(">IHHII", hdr, 0x40, 0x24, 1, 2, 0x8000, 0xF800)
    hdr[0x4C:0x60] = b"\x11" * 20
    struct.pack_into(">I", hdr, sec + 4, image_size)
    struct.pack_into(">I", hdr, sec + 0x110, BASE)
    return bytes(hdr)


class XexWriteTests(unittest.TestCase):
    def test_round_trip_basic(self):
        orig, img = synthetic_xex(), synthetic_image()
        out = xex_write.write_xex(orig, img, "basic")
        self.assertEqual(len(out), 0x400 + IMG_SIZE)
        self.assertEqual(xex_write.decode_image(out), img)
        facts = xex_write.verify(out, img, orig)
        self.assertEqual((facts["encryption"], facts["compression"]), (0, 1))
        self.assertTrue(facts["header_unchanged_outside_3FF"])

    def test_only_file_format_block_changes(self):
        orig, img = synthetic_xex(), synthetic_image()
        out = xex_write.write_xex(orig, img)
        diff = [i for i in range(0x400) if orig[i] != out[i]]
        self.assertTrue(diff and min(diff) >= 0x40 and max(diff) < 0x40 + 0x24)
        self.assertEqual(struct.unpack_from(">IHHII", out, 0x40), (0x10, 0, 1, IMG_SIZE, 0))

    def test_none_compression_layout(self):
        out = xex_write.write_xex(synthetic_xex(), synthetic_image(), "none")
        self.assertEqual(struct.unpack_from(">IHH", out, 0x40), (8, 0, 0))
        self.assertEqual(out[0x400:], synthetic_image())

    def test_size_mismatch_refused(self):
        with self.assertRaises(ValueError):
            xex_write.write_xex(synthetic_xex(), synthetic_image() + b"\0" * 16)

    def test_output_path_guard(self):
        with self.assertRaises(SystemExit):
            xex_write.check_out_path("/tmp/x.xex")
        self.assertTrue(xex_write.check_out_path(os.path.join(ROOT, "work", "modpatch", "a", "b.xex")))


def make_coff(text_words, relocs, symbols, extra_sections=()):
    """Tiny PowerPC COFF object: one .text section. relocs [(offset, symidx, type)]; symbols [(name, value, section, storage)]."""
    text = b"".join(struct.pack(">I", w) for w in text_words)
    nsec = 1 + len(extra_sections)
    raw_off = 20 + 40 * nsec
    reloc_blob = b"".join(struct.pack("<IIH", *r) for r in relocs)
    sections = [(b".text", text, 0x60401020, relocs)]
    for name, data, chars in extra_sections:
        sections.append((name, data, chars, []))
    body = b""
    hdrs = b""
    ptr = raw_off
    relptr_base = None
    # lay out: headers, data blobs, relocs, symbols
    blobs = []
    for name, data, chars, rel in sections:
        blobs.append((ptr, len(data)))
        ptr += len(data)
    rel_ptr = ptr
    for i, (name, data, chars, rel) in enumerate(sections):
        rp = rel_ptr if rel else 0
        hdrs += struct.pack("<8sIIIIIIHHI", name, 0, 0, len(data), blobs[i][0], rp, 0, len(rel), 0, chars)
        body += data
    body += reloc_blob
    symoff = raw_off + len(body)
    strtab = b""
    parts = []
    for n, v, s, st in symbols:
        if len(n) > 8:
            raw = b"\0\0\0\0" + struct.pack("<I", 4 + len(strtab))
            strtab += n.encode() + b"\0"
        else:
            raw = n.encode().ljust(8, b"\0")
        parts.append(struct.pack("<8sIhHBB", raw, v, s, 0, st, 0))
    fh = struct.pack("<HHIIIHH", 0x1F2, nsec, 0, symoff, len(symbols), 0, 0)
    return fh + hdrs + body + b"".join(parts) + struct.pack("<I", 4 + len(strtab)) + strtab


class FakeSyms:
    def __init__(self, names):
        self.by_name = dict(names)
        self.functions = {}


class PlacerTests(unittest.TestCase):
    def build(self, g_addr, field_lo=0x14):
        lo = field_lo
        words = [0x7D8802A6, 0x3D600000, 0x806B0000 | lo, 0x4BFFFFF5, 0x4E800020]
        # symbols: 0 f, 1 g, 2 ext
        syms = [("f", 0, 1, 2), ("g", 0, 0, 2), ("ext", 0, 0, 2)]
        relocs = [(4, 1, 0x10), (4, 0, 0x12), (8, 1, 0x11), (8, 0, 0x12), (12, 2, 6)]
        obj = modpatch.Coff(make_coff(words, relocs, syms))
        fs = FakeSyms({"g": g_addr, "ext": 0x88613268})
        placed = 0x88B15400
        p = modpatch.Placer(obj, fs, lambda size, align: placed)
        p.place(obj.find_function("f"))
        return p, placed

    def test_hi_lo_and_call(self):
        p, base = self.build(0x88D45B38)
        code = p.blobs[0][1]
        w = struct.unpack(">5I", code)
        self.assertEqual(w[1], 0x3D6088D4)
        self.assertEqual(w[2], 0x806B0000 | 0x5B4C)
        disp = 0x88613268 - (base + 12)
        self.assertEqual(w[3], 0x48000001 | (disp & 0x03FFFFFC))
        self.assertEqual(w[0], 0x7D8802A6)

    def test_carry_adjust_when_low_half_is_negative(self):
        p, _ = self.build(0x88D4F000)
        w = struct.unpack(">5I", p.blobs[0][1])
        self.assertEqual(w[1], 0x3D6088D5)           # 0x88D4F014: low half is negative as signed 16
        self.assertEqual(w[2] & 0xFFFF, 0xF014)

    def test_unknown_symbol_refused(self):
        words = [0x4BFFFFFD, 0x4E800020]
        obj = modpatch.Coff(make_coff(words, [(0, 1, 6)], [("f", 0, 1, 2), ("nowhere", 0, 0, 2)]))
        p = modpatch.Placer(obj, FakeSyms({}), lambda s, a: 0x88B15400)
        with self.assertRaises(modpatch.PatchError):
            p.place(obj.find_function("f"))

    def test_placeholder_names_resolve_to_their_address(self):
        words = [0x4BFFFFFD, 0x4E800020]
        obj = modpatch.Coff(make_coff(words, [(0, 1, 6)], [("f", 0, 1, 2), ("fn_88613268", 0, 0, 2)]))
        p = modpatch.Placer(obj, FakeSyms({}), lambda s, a: 0x88B15400)
        p.place(obj.find_function("f"))
        self.assertEqual(p.bindings[0]["address"], 0x88613268)

    def test_local_rdata_constant_is_copied(self):
        words = [0x3D600000, 0xC02B0000, 0x4E800020]
        syms = [("f", 0, 1, 2), ("k1", 0, 2, 2)]
        relocs = [(0, 1, 0x10), (0, 0, 0x12), (4, 1, 0x11), (4, 0, 0x12)]
        rdata = (b"__real", struct.pack(">f", 2.5), 0x40301040)
        obj = modpatch.Coff(make_coff(words, relocs, syms, [(b".rdata", rdata[1], rdata[2])]))
        cur = [0x88B15400]

        def alloc(size, align):
            a = (cur[0] + align - 1) & ~(align - 1)
            cur[0] = a + size
            return a
        p = modpatch.Placer(obj, FakeSyms({}), alloc)
        p.place(obj.find_function("f"))
        addrs = {l: a for a, _d, l in p.blobs}
        k = addrs[".rdata+0x0"]
        self.assertEqual(k % 16, 0)
        w = struct.unpack(">3I", p.blobs[0][1])
        self.assertEqual(((w[0] & 0xFFFF) << 16) + modpatch.sext(w[1], 16), k)

    def test_writable_data_refused(self):
        words = [0x3D600000, 0x806B0000, 0x4E800020]
        syms = [("f", 0, 1, 2), ("var", 0, 2, 3)]
        relocs = [(0, 1, 0x10), (0, 0, 0x12), (4, 1, 0x11), (4, 0, 0x12)]
        obj = modpatch.Coff(make_coff(words, relocs, syms, [(b".data", b"\0\0\0\0", 0xC0300040)]))
        p = modpatch.Placer(obj, FakeSyms({}), lambda s, a: 0x88B15400)
        with self.assertRaises(modpatch.PatchError):
            p.place(obj.find_function("f"))


class ImageTests(unittest.TestCase):
    def image(self):
        img = bytearray(0x30000)
        img[0x10:0x14] = bytes.fromhex("7d8802a6")
        return modpatch.Image(bytes(img), BASE, (BASE + 0x10000, BASE + 0x20000), [(".text", 0x10000, 0x100)])

    def test_free_space_after_last_section(self):
        im = self.image()
        self.assertEqual(im.free_start, BASE + 0x10200)
        self.assertEqual(im.free_end, BASE + 0x20000)

    def test_constant_patch_checks_old_bytes(self):
        im = self.image()
        with self.assertRaises(modpatch.PatchError):
            modpatch.apply_constant_patches(im, [{"address": BASE + 0x10, "old": "00000000", "new": "60000000"}])
        modpatch.apply_constant_patches(im, [{"address": BASE + 0x10, "old": "7d8802a6", "new": "60000000"}])
        self.assertEqual(im.read(BASE + 0x10, 4), bytes.fromhex("60000000"))

    def test_overlap_refused(self):
        im = self.image()
        modpatch.apply_constant_patches(im, [{"address": BASE + 0x10, "old": "7d8802a6", "new": "60000000"}])
        with self.assertRaises(modpatch.PatchError):
            im.write(BASE + 0x12, b"\0\0")

    def test_alloc_is_zero_checked_and_aligned(self):
        im = self.image()
        a = im.alloc(10, 16)
        self.assertEqual(a % 16, 0)
        b = im.alloc(10, 16)
        self.assertGreater(b, a)


class AsmTests(unittest.TestCase):
    def test_known_encodings(self):
        self.assertEqual(modpatch.a_stwu(1, -0x60, 1), 0x9421FFA0)
        self.assertEqual(modpatch.a_mflr(12), 0x7D8802A6)
        self.assertEqual(modpatch.a_mtlr(12), 0x7D8803A6)
        self.assertEqual(modpatch.a_blr(), 0x4E800020)
        self.assertEqual(modpatch.a_lis(11, 0x88D4), 0x3D6088D4)
        self.assertEqual(modpatch.a_lwz(11, 0x5B38, 11), 0x816B5B38)
        self.assertEqual(modpatch.a_stvx(1, 1, 0), 0x7C2101CE)
        self.assertEqual(modpatch.a_lvx(1, 1, 0), 0x7C2100CE)
        self.assertEqual(modpatch.a_stvx(64, 1, 0), 0x100101CB)   # stvx128 v64, r1, r0
        self.assertEqual(modpatch.a_b(8), 0x48000008)
        self.assertEqual(modpatch.a_b(-4, True), 0x4BFFFFFD)

    def test_displaced_branches_are_reencoded(self):
        bl = 0x48000101 | 0                          # bl +0x100
        out = modpatch.relocate_displaced(bl, 0x88001000, 0x88B15400)
        target = 0x88001000 + 0x100
        self.assertEqual(0x88B15400 + modpatch.sext(out & 0x03FFFFFC, 26), target)
        self.assertEqual(out & 3, 1)
        self.assertEqual(modpatch.relocate_displaced(0x7D8802A6, 0x88001000, 0x88B15400), 0x7D8802A6)
        bc = 0x41820010                              # beq +0x10
        with self.assertRaises(modpatch.PatchError):
            modpatch.relocate_displaced(bc, 0x88001000, 0x88B15400)   # cannot reach from 12 MB away
        near = modpatch.relocate_displaced(bc, 0x88001000, 0x88001100)
        self.assertEqual(0x88001100 + modpatch.sext(near & 0xFFFC, 16), 0x88001010)


class Cpu:
    """Interpreter for exactly the instructions the hook wrapper and its tests use."""

    def __init__(self, code):
        self.code, self.mem = code, {}
        self.gpr, self.fpr, self.vr = [0] * 32, [0] * 32, [0] * 128
        self.lr = self.ctr = self.xer = self.cr = 0
        self.cr0 = 0
        self.pc = 0
        self.callbacks = {}

    def ld(self, a):
        return int.from_bytes(bytes(self.mem.get(a + i, 0) for i in range(4)), "big")

    def st(self, a, v, n=4):
        for i, b in enumerate(v.to_bytes(n, "big")):
            self.mem[a + i] = b

    def run(self, pc, stop):
        self.pc = pc
        for _ in range(200000):
            if self.pc == stop:
                return
            if self.pc in self.callbacks:
                self.callbacks[self.pc](self)
                self.pc = self.lr
                continue
            self.step(self.code[self.pc])
        raise RuntimeError("did not stop")

    def step(self, w):
        op, rt, ra, rb = w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
        imm = modpatch.sext(w, 16)
        nxt = self.pc + 4
        R = self.gpr
        ea = lambda: ((R[ra] if ra else 0) + imm) & 0xFFFFFFFF  # noqa: E731
        if op == 14:
            R[rt] = ((R[ra] if ra else 0) + imm) & 0xFFFFFFFF
        elif op == 15:
            R[rt] = (((R[ra] if ra else 0)) + (imm << 16)) & 0xFFFFFFFF
        elif op == 24:
            R[ra] = R[rt] | (w & 0xFFFF)
        elif op == 32:
            R[rt] = self.ld(ea())
        elif op == 36:
            self.st(ea(), R[rt])
        elif op == 37:
            e = ea()
            self.st(e, R[rt])
            R[ra] = e
        elif op == 50:
            self.fpr[rt] = int.from_bytes(bytes(self.mem.get(ea() + i, 0) for i in range(8)), "big")
        elif op == 54:
            self.st(ea(), self.fpr[rt], 8)
        elif op == 11:
            a = modpatch.sext(R[ra], 32)
            self.cr0 = 8 if a < imm else 4 if a > imm else 2
        elif op == 16:
            assert (w >> 21) & 31 == 4 and (w >> 16) & 31 == 2 and not w & 3
            if not self.cr0 & 2:
                nxt = self.pc + modpatch.sext(w & 0xFFFC, 16)
        elif op == 18:
            if w & 1:
                self.lr = self.pc + 4
            nxt = self.pc + modpatch.sext(w & 0x03FFFFFC, 26)
        elif w == 0x4E800020:
            nxt = self.lr
        elif op == 31:
            xo = (w >> 1) & 0x3FF
            spr = ((w >> 16) & 31) | (((w >> 11) & 31) << 5)
            if xo == 339:
                R[rt] = {8: self.lr, 9: self.ctr, 1: self.xer}[spr]
            elif xo == 467:
                setattr(self, {8: "lr", 9: "ctr", 1: "xer"}[spr], R[rt])
            elif xo == 19:
                R[rt] = self.cr
            elif xo == 144:
                assert (w >> 12) & 0xFF == 0xFF
                self.cr = R[rt]
            elif xo == 231:
                self.st((R[ra] + R[rb]) & 0xFFFFFFFF, self.vr[rt], 16)
            elif xo == 103:
                self.vr[rt] = int.from_bytes(bytes(self.mem.get(R[ra] + R[rb] + i, 0) for i in range(16)), "big")
            else:
                raise AssertionError("unhandled xo %d" % xo)
        elif op == 4 and (w & 0x7F3) in (0x1C3, 0xC3):
            v = rt | (((w >> 2) & 3) << 5)
            e = (R[ra] + R[rb]) & 0xFFFFFFFF
            if (w & 0x7F3) == 0x1C3:
                self.st(e, self.vr[v], 16)
            else:
                self.vr[v] = int.from_bytes(bytes(self.mem.get(e + i, 0) for i in range(16)), "big")
        else:
            raise AssertionError("unhandled instruction %08x at %08x" % (w, self.pc))
        self.pc = nxt


class WrapperTests(unittest.TestCase):
    def run_wrapper(self, vmx, set_skip=False, displaced=0x38A50001):   # displaced: addi r5,r5,1
        hook, wrap, stub, ret = 0x88171234, 0x88B15400, 0x88B16000, 0x88171238
        words = modpatch.hook_wrapper(hook, wrap, stub, ret, displaced, vmx, 512)
        code = {wrap + 4 * i: w for i, w in enumerate(words)}
        cpu = Cpu(code)
        rnd = random.Random(7)
        cpu.gpr = [rnd.getrandbits(32) for _ in range(32)]
        cpu.gpr[1] = 0x70008000
        cpu.fpr = [rnd.getrandbits(64) for _ in range(32)]
        cpu.vr = [rnd.getrandbits(128) for _ in range(128)]
        cpu.lr, cpu.ctr, cpu.xer, cpu.cr = 0xDEAD0000, 0x12345678, 0xA0000000, 0x81234567
        for a in range(cpu.gpr[1] - 512, cpu.gpr[1]):
            cpu.mem[a] = 0xA5
        before = (list(cpu.gpr), list(cpu.fpr), list(cpu.vr), cpu.lr, cpu.ctr, cpu.xer, cpu.cr)
        seen = {}

        def stub_cb(c):
            ctx = c.gpr[3]
            seen["gpr14"] = c.ld(ctx + 4 * 14)
            seen["hook"] = c.ld(ctx + 0x194)
            seen["sp"] = c.ld(ctx + 4)
            seen["lr"] = c.ld(ctx + 0x180)
            c.st(ctx + 4 * 14, 0x1234)                      # change r14 through the context
            if set_skip:
                c.st(ctx + 0x190, 1)
            for i in [0] + list(range(3, 13)):              # behave like a C function: clobber volatiles
                c.gpr[i] = 0xBAD00000 + i
            c.fpr[:14] = [0xBAD] * 14
            for i in list(range(0, 14)) + list(range(32, 128)):
                c.vr[i] = 0xBAD
            c.cr, c.ctr, c.xer = 0, 0, 0
        cpu.callbacks[stub] = stub_cb
        cpu.run(wrap, ret)
        return cpu, before, seen

    def check(self, vmx, set_skip=False):
        cpu, (gpr, fpr, vr, lr, ctr, xer, cr), seen = self.run_wrapper(vmx, set_skip)
        want = list(gpr)
        want[14] = 0x1234
        if not set_skip:
            want[5] = (want[5] + 1) & 0xFFFFFFFF            # displaced addi ran after the restore
        self.assertEqual(cpu.gpr, want)
        self.assertEqual(cpu.fpr, fpr)
        self.assertEqual((cpu.lr, cpu.ctr, cpu.xer, cpu.cr), (lr, ctr, xer, cr))
        if vmx == 2:
            self.assertEqual(cpu.vr, vr)
        elif vmx == 1:
            self.assertEqual(cpu.vr[:32], vr[:32])
        self.assertEqual(seen["gpr14"], gpr[14])
        self.assertEqual((seen["hook"], seen["sp"], seen["lr"]), (0x88171234, 0x70008000, 0xDEAD0000))
        for a in range(0x70008000 - 512, 0x70008000):       # red zone untouched
            self.assertEqual(cpu.mem[a], 0xA5)

    def test_all_registers_restored_vmx2(self):
        self.check(2)

    def test_vmx1_and_vmx0(self):
        self.check(1)
        self.check(0)

    def test_skip_original(self):
        self.check(0, set_skip=True)

    def test_wrapper_size_does_not_depend_on_addresses(self):
        a = modpatch.hook_wrapper(0x88171234, 0x88B15400, 0x88B16000, 0x88171238, 0x60000000, 2, 512)
        b = modpatch.hook_wrapper(0x88171234, 0x88000000, 0x88000000, 0x88000004, 0x60000000, 2, 512)
        self.assertEqual(len(a), len(b))


class DataTests(unittest.TestCase):
    def test_layout_and_set(self):
        entries = [{"name": "a", "offset": 0, "init": {"u32": [1, 2]}},
                   {"name": "b", "init": {"f32": [1.5]}},
                   {"name": "c", "size": 6, "align": 8}]
        t = modpatch.layout_data(entries, [{"name": "a", "value": {"u32": [9]}, "index": 1}])
        self.assertEqual(bytes(t["a"][1]), struct.pack(">II", 1, 9))
        self.assertEqual(t["b"][0], 8)
        self.assertEqual(bytes(t["b"][1]), struct.pack(">f", 1.5))
        self.assertEqual(t["c"][0], 16)

    def test_overlap_and_overflow_refused(self):
        with self.assertRaises(modpatch.PatchError):
            modpatch.layout_data([{"name": "a", "offset": 0, "size": 8}, {"name": "b", "offset": 4, "size": 4}], [])
        with self.assertRaises(modpatch.PatchError):
            modpatch.layout_data([{"name": "a", "offset": modpatch.DATA_SIZE - 2, "size": 4}], [])

    def test_merge_specs_agree_on_layout(self):
        m = modpatch.merge_specs([{"data": [{"name": "a", "offset": 0, "size": 4}], "patches": [1]},
                                  {"data": [{"name": "a", "init": "01000000"}], "patches": [2]}])
        self.assertEqual(m["patches"], [1, 2])
        self.assertEqual(len(m["data"]), 1)
        self.assertEqual(m["data"][0]["init"], "01000000")
        with self.assertRaises(modpatch.PatchError):
            modpatch.merge_specs([{"data": [{"name": "a", "offset": 0}]}, {"data": [{"name": "a", "offset": 4}]}])

    def test_setdata_edits_a_built_xex(self):
        import json
        import shutil
        d = os.path.join(ROOT, "work", "modpatch", "unittest")
        os.makedirs(d, exist_ok=True)
        try:
            img = bytearray(synthetic_image())
            xex = xex_write.write_xex(synthetic_xex(), bytes(img))
            p = os.path.join(d, "t.xex")
            open(p, "wb").write(xex)
            json.dump({"data": [{"name": "sw", "address": "0x88000100", "size": 4}]}, open(p + ".report.json", "w"))
            out = modpatch.setdata(p, os.path.join(d, "t2.xex"), ["sw=u32:7"])
            got = xex_write.decode_image(open(out, "rb").read())
            self.assertEqual(got[0x100:0x104], struct.pack(">I", 7))
            self.assertEqual(got[:0x100], bytes(img[:0x100]))
        finally:
            shutil.rmtree(d, ignore_errors=True)


class WordsHookTests(unittest.TestCase):
    def test_words_stub_appends_displaced_and_return_branch(self):
        img = bytearray(0x30000)
        hook = BASE + 0x1000
        img[0x1000:0x1004] = struct.pack(">I", 0x48000101)          # bl hook+0x100 (displaced, relative)
        im = modpatch.Image(bytes(img), BASE, (BASE + 0x10000, BASE + 0x20000), [(".text", 0x10000, 0x100)])
        info = modpatch.place_hook(im, FakeSyms({}), {"hook": hook, "expect": "48000101",
                                                       "stub": {"words": ["0x38600001"]}})
        entry = int(info["entry"], 16)
        self.assertEqual(modpatch.sext(struct.unpack(">I", im.read(hook, 4))[0] & 0x03FFFFFC, 26), entry - hook)
        w = struct.unpack(">3I", im.read(entry, 12))
        self.assertEqual(w[0], 0x38600001)
        self.assertEqual((entry + 4) + modpatch.sext(w[1] & 0x03FFFFFC, 26), hook + 0x100)   # displaced bl
        self.assertEqual(w[1] & 3, 1)
        self.assertEqual((entry + 8) + modpatch.sext(w[2] & 0x03FFFFFC, 26), hook + 4)      # b hook+4

    def test_expect_mismatch_refused(self):
        im = modpatch.Image(bytes(0x30000), BASE, (BASE + 0x10000, BASE + 0x20000), [(".text", 0x10000, 0x100)])
        with self.assertRaises(modpatch.PatchError):
            modpatch.place_hook(im, FakeSyms({}), {"hook": BASE + 0x1000, "expect": "7d8802a6",
                                                   "stub": {"words": ["0x60000000"]}})


if __name__ == "__main__":
    unittest.main()
