"""Tests for tools/recomp_config.py on synthetic PowerPC code (no game bytes)."""
import struct
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent / 'tools'))
import recomp_config as rc  # noqa: E402

TEXT = 0x82010000
RDATA = 0x82000000


def lis(rd, imm):
    return (15 << 26) | (rd << 21) | (imm & 0xFFFF)


def addi(rd, ra, imm):
    return (14 << 26) | (rd << 21) | (ra << 16) | (imm & 0xFFFF)


def li(rd, imm):
    return addi(rd, 0, imm)


def slwi(ra, rs, n):
    return (21 << 26) | (rs << 21) | (ra << 16) | (n << 11) | (0 << 6) | ((31 - n) << 1)


def x31(rd, ra, rb, xo):
    return (31 << 26) | (rd << 21) | (ra << 16) | (rb << 11) | (xo << 1)


def lwzx(rd, ra, rb):
    return x31(rd, ra, rb, 23)


def lbzx(rd, ra, rb):
    return x31(rd, ra, rb, 87)


def add(rd, ra, rb):
    return x31(rd, ra, rb, 266)


def mr(ra, rs):
    return (31 << 26) | (rs << 21) | (ra << 16) | (rs << 11) | (444 << 1)


def mtctr(rs):
    return (31 << 26) | (rs << 21) | (9 << 16) | (467 << 1)


def cmplwi(crf, ra, imm):
    return (10 << 26) | (crf << 23) | (ra << 16) | imm


def bgt(crf, disp):
    return (16 << 26) | (12 << 21) | ((4 * crf + 1) << 16) | (disp & 0xFFFC)


BLR = 0x4E800020


def ha(x):
    return ((x + 0x8000) >> 16) & 0xFFFF


def lo(x):
    return x & 0xFFFF


def pack(words):
    return b''.join(struct.pack('>I', w) for w in words)


def absolute_switch_fn(base, ncases=3, copy=False):
    """cmplwi/bgt guard, lis/slwi/addi/lwzx/mtctr/bctr, inline table, one blr per case."""
    words = []
    idx = 10
    if copy:
        words += [mr(31, 4)]
        words += [cmplwi(6, 4, ncases - 1)]
        idx = 31
    else:
        words += [cmplwi(6, idx, ncases - 1)]
    guard = len(words)
    words += [0]  # bgt placeholder
    table = base + 4 * (len(words) + 6)
    words += [lis(12, ha(table)), slwi(0, idx, 2), addi(12, 12, lo(table)), lwzx(0, 12, 0), mtctr(0), rc.BCTR]
    case0 = table + 4 * ncases
    words += [case0 + 8 * i for i in range(ncases)]
    for i in range(ncases):
        words += [li(3, i), BLR]
    default = base + 4 * len(words)
    words += [li(3, -1), BLR]
    words[guard] = bgt(6, default - (base + 4 * guard))
    return words, table


class SwitchDetector(unittest.TestCase):
    def image(self, words, rdata=b'\0' * 16):
        return rc.Image.from_sections([('.rdata', RDATA, rdata, False), ('.text', TEXT, pack(words), True)])

    def test_absolute(self):
        words, table = absolute_switch_fn(TEXT, 4)
        img = self.image(words)
        bctr = TEXT + 4 * words.index(rc.BCTR)
        sw, why = rc.detect_switch(img, TEXT, TEXT + 4 * len(words), bctr)
        self.assertEqual(why, 'ok')
        self.assertEqual(sw.kind, 'absolute')
        self.assertEqual(sw.index_reg, 10)
        self.assertEqual(sw.count_src, 'cmplwi')
        self.assertEqual(sw.labels, [table + 16 + 8 * i for i in range(4)])

    def test_absolute_bound_through_register_copy(self):
        words, table = absolute_switch_fn(TEXT, 3, copy=True)
        img = self.image(words)
        bctr = TEXT + 4 * words.index(rc.BCTR)
        sw, why = rc.detect_switch(img, TEXT, TEXT + 4 * len(words), bctr)
        self.assertEqual(why, 'ok')
        self.assertEqual(sw.index_reg, 31)
        self.assertEqual(len(sw.labels), 3)
        self.assertEqual(sw.count_src, 'cmplwi')

    def test_byte_offset_table_with_nop(self):
        tbl = RDATA + 4
        base_label = TEXT + 4 * 13
        words = [cmplwi(6, 7, 2), bgt(6, 4 * 18),
                 lis(12, ha(tbl)), addi(12, 12, lo(tbl)), lbzx(0, 12, 7), slwi(0, 0, 2),
                 lis(12, ha(base_label)), rc.NOP, addi(12, 12, lo(base_label)), add(12, 12, 0), mtctr(12),
                 rc.BCTR, rc.NOP,
                 li(3, 0), BLR, li(3, 1), BLR, li(3, 2), BLR, li(3, -1), BLR]
        rdata = b'\0' * 4 + bytes([0, 2, 4]) + b'\0' * 9
        img = self.image(words, rdata)
        sw, why = rc.detect_switch(img, TEXT, TEXT + 4 * len(words), TEXT + 4 * 11)
        self.assertEqual(why, 'ok')
        self.assertEqual(sw.kind, 'byte')
        self.assertEqual(sw.index_reg, 7)
        self.assertEqual(sw.labels, [base_label, base_label + 8, base_label + 16])

    def test_vcall_is_not_a_switch(self):
        lwz = lambda rd, ra, d: (32 << 26) | (rd << 21) | (ra << 16) | (d & 0xFFFF)
        words = [lwz(11, 3, 0), lwz(10, 11, 0x38), mtctr(10), rc.BCTR]
        img = self.image(words)
        sw, why = rc.detect_switch(img, TEXT, TEXT + 16, TEXT + 12)
        self.assertIsNone(sw)
        self.assertIn('pointer', rc.classify_bctr(img, TEXT, TEXT + 12))

    def test_clobbered_index_rejected(self):
        words, table = absolute_switch_fn(TEXT, 3)
        i = words.index(mtctr(0))
        words[i - 1] = lwzx(10, 12, 0)  # writes the index register before the bctr
        img = self.image(words)
        sw, why = rc.detect_switch(img, TEXT, TEXT + 4 * len(words), TEXT + 4 * words.index(rc.BCTR))
        self.assertIsNone(sw)


class ConfigOutput(unittest.TestCase):
    def test_helpers_found_and_skipped(self):
        helper = [0xE9C1FF68] + [0] * 3 + [0xF9C1FF68] + [0] * 3
        fn, _ = absolute_switch_fn(TEXT + 4 * len(helper), 2)
        img = rc.Image.from_sections([('.text', TEXT, pack(helper + fn), True)])
        found = rc.find_helpers(img)
        self.assertEqual(found['restgprlr_14_address'], TEXT)
        self.assertEqual(found['savegprlr_14_address'], TEXT + 16)
        fns = {TEXT: ('__restgprlr', 16, '.text'), TEXT + 16: ('__savegprlr', 16, '.text'),
               TEXT + 32: ('fn_a', 4 * len(fn), '.text'), TEXT + 36: ('overlap', 8, '.text')}
        chosen = rc.select_functions(fns, found, img)
        self.assertEqual(chosen, [(TEXT + 32, 4 * len(fn))])

    def test_toml_shapes(self):
        sw = rc.Switch(0x82010010, 'absolute', 10, [0x82010020, 0x82010028], 0x82010014, 'cmplwi')
        text = rc.toml_switches([sw])
        self.assertIn('base = 0x82010010', text)
        self.assertIn('r = 10', text)
        self.assertIn('labels = [0x82010020, 0x82010028]', text)
        main = rc.toml_main({'file_path': 'a.xex'}, [(0x82010000, 0x40)], {'savegprlr_14_address': 0x82000000}, {})
        self.assertIn('file_path = "a.xex"', main)
        self.assertIn('{ address = 0x82010000, size = 0x40 },', main)
        self.assertIn('savegprlr_14_address = 0x82000000', main)

    def test_symbols_parser_keeps_largest(self):
        with tempfile.TemporaryDirectory() as d:
            p = Path(d) / 'symbols.txt'
            p.write_text('fn_a = .text:0x82010000; // type:function size:0x10\n'
                         'alias = .text:0x82010000; // type:function size:0x20\n'
                         'tbl = .rdata:0x82000000; // type:object size:0x8 scope:local\n'
                         'lbl = .text:0x82010004; // type:label scope:global\n')
            fns, objs = rc.load_symbols(p)
        self.assertEqual(fns[0x82010000][1], 0x20)
        self.assertEqual(objs[0x82000000], ('tbl', 8, '.rdata'))

    def test_split_loop_is_merged(self):
        # fn A: li; loop body ...; B (a bogus split) branches back into A's body
        bdnz_back = lambda disp: (16 << 26) | (16 << 21) | (disp & 0xFFFC)
        words = [li(3, 0), addi(3, 3, 1), rc.NOP, bdnz_back(-8), BLR,   # A = 0..0x14
                 bdnz_back(-12), BLR]                                  # B = 0x14..0x1C (refers back)
        img = rc.Image.from_sections([('.text', TEXT, pack(words), True)])
        chosen = [(TEXT, 0x14), (TEXT + 0x14, 0x8)]
        out, merges, dropped = rc.extend_for_neighbours(chosen, img, refs=set())
        self.assertEqual(out, [(TEXT, 0x1C)])
        self.assertEqual((merges, dropped), (1, 1))
        out, merges, dropped = rc.extend_for_neighbours(chosen, img, refs={TEXT + 0x14})
        self.assertEqual(out, [(TEXT, 0x1C), (TEXT + 0x14, 0x8)])
        self.assertEqual(dropped, 0)

    def test_reachable_skips_table_words(self):
        words, table = absolute_switch_fn(TEXT, 3)
        img = rc.Image.from_sections([('.text', TEXT, pack(words), True)])
        bctr = TEXT + 4 * words.index(rc.BCTR)
        sw, _ = rc.detect_switch(img, TEXT, TEXT + 4 * len(words), bctr)
        seen = rc.reachable(img, TEXT, 4 * len(words), {bctr: sw.labels})
        self.assertNotIn(table, seen)
        for lab in sw.labels:
            self.assertIn(lab, seen)


def rlwinm(ra, rs, sh, mb, me):
    return (21 << 26) | (rs << 21) | (ra << 16) | (sh << 11) | (mb << 6) | (me << 1)


def b_rel(disp):
    return (18 << 26) | (disp & 0x03FFFFFC)


def bl_rel(disp):
    return (18 << 26) | (disp & 0x03FFFFFC) | 1


class PdataAndImages(unittest.TestCase):
    def test_read_pdata(self):
        # FuncLen (instructions) sits in bits 8..29 of the second word
        pdata = struct.pack('>IIII', TEXT, (5 << 8) | 0x40000003, TEXT + 0x20, (2 << 8))
        img = rc.Image.from_sections([('.text', TEXT, pack([rc.NOP] * 16), True),
                                      ('.pdata', RDATA, pdata, False)])
        self.assertEqual(rc.read_pdata(img), {TEXT: 20, TEXT + 0x20: 8})

    def _pe(self, mapped):
        base, va, size = 0x82000000, 0x1000, 0x200
        head = bytearray(0x400)
        struct.pack_into('<I', head, 0x3C, 0x80)
        head[0x80:0x84] = b'PE\0\0'
        struct.pack_into('<H', head, 0x86, 1)          # one section
        struct.pack_into('<H', head, 0x94, 0xE0)       # optional header size
        struct.pack_into('<I', head, 0x98 + 28, base)  # ImageBase
        sec = 0x98 + 0xE0
        head[sec:sec + 5] = b'.text'
        struct.pack_into('<IIII', head, sec + 8, size, va, size, 0x400)  # vsize, va, rawsize, rawoff
        struct.pack_into('<I', head, sec + 36, 0x60000020)
        code = pack([0x60000000 + i for i in range(size // 4)])
        if mapped:  # sections at their RVA, file-layout headers kept
            return bytes(head) + b'\0' * (va - len(head)) + code, base + va
        return bytes(head) + code, base + va

    def test_file_and_mapped_layouts_read_the_same(self):
        for mapped in (False, True):
            data, text = self._pe(mapped)
            img = rc.Image(data)
            self.assertEqual(img.word(text), 0x60000000, mapped)
            self.assertEqual(img.word(text + 8), 0x60000002, mapped)


class Discovery(unittest.TestCase):
    def test_extent_follows_branches_and_stops_at_padding(self):
        # 0: bc +12 -> 0xC ; 4: li ; 8: blr ; C: li ; 10: b -8 (back to 8) ; 14: padding
        words = [bgt(0, 12), li(3, 0), BLR, li(3, 1), b_rel(-8), 0, li(3, 2), BLR]
        img = rc.Image.from_sections([('.text', TEXT, pack(words), True)])
        end, sw = rc.function_extent(img, TEXT, TEXT + 4 * len(words))
        self.assertEqual(end, TEXT + 0x14)
        self.assertEqual(sw, [])

    def test_discover_finds_uncovered_callee_and_gap(self):
        # known fn at 0 calls a leaf at 0x10 (not known); a second leaf after padding at 0x20
        words = [bl_rel(0x10), BLR, 0, 0, li(3, 1), BLR, 0, 0, li(3, 2), BLR]
        img = rc.Image.from_sections([('.text', TEXT, pack(words), True)])
        found = rc.discover_functions(img, {TEXT: 8})
        self.assertEqual(found, {TEXT + 0x10: 8, TEXT + 0x20: 8})

    def test_mask_bounded_byte_switch_marks_padding_labels(self):
        # clrlwi r11,r3,30 (4 entries) ; lis/addi table ; lbzx ; lis/addi base ; add ; mtctr ; bctr
        tbl = RDATA
        n = 13
        base = TEXT + 4 * n
        words = [rlwinm(11, 3, 0, 30, 31), lis(10, ha(tbl)), addi(10, 10, lo(tbl)), lbzx(0, 10, 11),
                 lis(12, ha(base)), addi(12, 12, lo(base)), add(0, 12, 0), mtctr(0), rc.BCTR,
                 rc.NOP, rc.NOP, rc.NOP, rc.NOP,
                 li(3, 0), BLR, li(3, 1), BLR, 0, 0]
        # entries 0,1 are cases; entry 2 lands on padding past the function; entry 3 on case 0
        offs = bytes([0, 8, 16, 0])
        img = rc.Image.from_sections([('.rdata', RDATA, offs + b'\0' * 12, False),
                                      ('.text', TEXT, pack(words), True)])
        bctr = TEXT + 4 * 8
        sw, why = rc.detect_switch(img, TEXT, base + 16, bctr)
        self.assertEqual(why, 'ok')
        self.assertEqual(sw.count_src, 'mask')
        self.assertEqual(sw.labels, [base, base + 8, 0, base])


class ToReXGlue(unittest.TestCase):
    def test_convert(self):
        sys.path.insert(0, str(Path(__file__).resolve().parent.parent / 'tools' / 'recomp'))
        import to_rexglue as tr
        main = rc.toml_main({'file_path': 'a.xex'}, [(0x82010000, 0x40), (0x82010040, 0x8)], {}, {})
        sws = rc.toml_switches([rc.Switch(0x82010010, 'byte', 10, [0x82010020, 0, 0x82010028],
                                          0x82000000, 'mask')])
        funcs = tr.parse_functions(main)
        self.assertEqual(funcs, [(0x82010000, 0x40), (0x82010040, 0x8)])
        parsed = tr.parse_switches(sws)
        self.assertEqual(parsed, [(0x82010010, 10, [0x82010020, 0, 0x82010028])])
        out, impossible = tr.render(funcs, parsed, setjmp=0x82000100)
        self.assertEqual(impossible, 1)
        self.assertIn('setjmp_address = 0x82000100', out)
        self.assertIn('"0x82010000" = { size = 0x40 }', out)
        self.assertIn('labels = [0x82010020, 0x82010020, 0x82010028]', out)


if __name__ == '__main__':
    unittest.main()
