"""Synthetic tests for tools/fn_check_ltcg.py (no compiler, no game data)."""

import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))

import fn_check_ltcg as L  # noqa: E402
from xcoff import Reloc  # noqa: E402

BASE = 0x82000000


def build_pe(sections, relocs):
    """A minimal PE32: sections = [(name, rva, data)], relocs = [(va, type, param|None)]."""
    pages = {}
    for va, kind, param in relocs:
        rva = va - BASE
        pages.setdefault(rva & ~0xFFF, []).append((kind << 12) | (rva & 0xFFF))
        if param is not None:
            pages[rva & ~0xFFF].append(param)
    blob = b""
    for page, entries in sorted(pages.items()):
        if len(entries) % 2:
            entries.append(0)
        blob += struct.pack("<II", page, 8 + 2 * len(entries)) + struct.pack(f"<{len(entries)}H", *entries)
    sections = list(sections) + [(".reloc", 0x9000, blob)]
    header = 0x400
    pe = 0x80
    data = bytearray(header)
    struct.pack_into("<I", data, 0x3C, pe)
    data[pe : pe + 4] = b"PE\0\0"
    optional = 0xE0
    struct.pack_into("<HHIIIHH", data, pe + 4, 0x1F2, len(sections), 0, 0, 0, optional, 0x2102)
    struct.pack_into("<I", data, pe + 24 + 28, BASE)
    raw = header
    body = bytearray()
    for index, (name, rva, payload) in enumerate(sections):
        offset = pe + 24 + optional + 40 * index
        struct.pack_into("<8sIIIIIIHHI", data, offset, name.encode(), len(payload), rva,
                         len(payload), raw + len(body), 0, 0, 0, 0, 0)
        body += payload
    return bytes(data + body)


def words(*values):
    return b"".join(v.to_bytes(4, "big") for v in values)


MAP = """
  Address         Publics by Value              Rva+Base       Lib:Object

 0000:00000000       ___safe_se_handler_count   00000000     <absolute>
 0001:00000000       __pool@_0                  82001000     u0.obj
 0002:00000000       my_func                    82002000 f   u0.obj
 0002:00000020       lt1stub_0                  82002020 f   lt1stubs.obj
 0002:00000020       ext_callee                 82002020 f   <linker-defined>
 0003:00000000       lt1stub_1                  82003000     lt1stubs.obj
"""


class FnCheckLtcgTest(unittest.TestCase):
    def setUp(self):
        # my_func: lis r11,hi(g); lfs f1,lo(g)(r11); bl ext_callee; lis r10,hi(pool); lfs f2,4(r10); blr
        pool_hi = 0x8200
        self.code = words(
            0x3D608200,            # lis r11, 0x8200       (HIGHADJ, g = 0x82003000)
            0xC02B3000,            # lfs f1, 0x3000(r11)   (LOW)
            0x48000000 | (0x18),   # bl +0x18 -> 0x82002020
            0x3D400000 | pool_hi,  # lis r10, 0x8200       (HIGHADJ, pool+4 = 0x82001004)
            0xC04A1004,            # lfs f2, 0x1004(r10)   (LOW)
            0x4E800020,            # blr
        )
        self.code = self.code[:8] + words(0x48000019) + self.code[12:]
        rdata = bytes(4) + struct.pack(">f", 1.5) + bytes(8)
        text = self.code + bytes(8) + words(0x4E800020)
        data = struct.pack(">I", 7) + bytes(12)
        relocs = [(0x82002000, 4, 0x3000), (0x82002004 + 2, 2, None),
                  (0x8200200C, 4, 0x1004), (0x82002010 + 2, 2, None)]
        self.image = L.parse_pe(build_pe([(".rdata", 0x1000, rdata), (".text", 0x2000, text),
                                          (".data", 0x3000, data)], relocs))
        self.symbols = L.parse_map(MAP)

    def test_parse_map(self):
        names = {s.name: s.address for s in self.symbols}
        self.assertEqual(names["my_func"], 0x82002000)
        self.assertTrue(next(s for s in self.symbols if s.name == "my_func").is_function)
        self.assertNotIn("___safe_se_handler_count", names)

    def test_base_relocs_and_sites(self):
        self.assertEqual(self.image.base_relocs[0x82002000], (4, 0x3000))
        sites = L.candidate_sites(self.image, 0x82002000, self.image.read(0x82002000, 24))
        got = [(s.offset, s.kind, s.address) for s in sites]
        self.assertEqual(got, [(0, L.REFHI, 0x82003000), (4, L.REFLO, 0x82003000),
                               (8, L.REL24, 0x82002020), (12, L.REFHI, 0x82001004),
                               (16, L.REFLO, 0x82001004)])

    def test_recursive_call_is_a_relocation(self):
        code = words(0x4BFFFFFC + 0)  # b -4 would be outside; use bl to self below
        code = words(0x60000000, 0x4BFFFFFD)  # nop; bl -4 -> start
        sites = L.candidate_sites(L.Image(b"", 0, []), 0x100, code)
        self.assertEqual([(s.offset, s.kind, s.address) for s in sites], [(4, L.REL24, 0x100)])

    def _target(self, g_name="lbl_83000000", pool_value=1.5):
        start = 0x83100000
        code = words(0x3D608300, 0xC02B0000, 0x48000000 | 0x0FF8 | 1, 0x3D408300, 0xC04A0010, 0x4E800020)
        relocs = [Reloc(0, g_name, L.REFHI), Reloc(4, g_name, L.REFLO),
                  Reloc(8, "ext_callee", L.REL24),
                  Reloc(12, "g_constants", L.REFHI), Reloc(16, "g_constants", L.REFLO)]
        sites = L.target_sites(code, start, relocs)
        index = L.SymbolIndex([(g_name, 0x83000000), ("g_constants", 0x83000000 + 0x0C),
                               ("ext_callee", start + 0xFF8)])
        memory = {0x83000010: struct.pack(">f", pool_value) + bytes(4)}
        return code, sites, start, index, lambda a, n: memory.get(a, bytes(n))[:n]

    def _compare(self, **kw):
        c_code = self.image.read(0x82002000, 24)
        c_sites = L.candidate_sites(self.image, 0x82002000, c_code)
        c_index = L.SymbolIndex([(s.name, s.address) for s in self.symbols], {"lt1stub_1": "my_global"})
        t_code, t_sites, t_start, t_index, t_read = self._target(**kw)
        return L.compare(c_code, c_sites, 0x82002000, c_index, self.image.read,
                         t_code, t_sites, t_start, t_index, t_read, known_names={"ext_callee"})

    def test_match_with_rename_and_pool(self):
        res = self._compare()
        self.assertTrue(res.ok, res.problems)
        self.assertEqual(res.renames, {"lbl_83000000": "my_global"})
        self.assertEqual(len(res.pools), 1)

    def test_pool_value_mismatch_fails(self):
        res = self._compare(pool_value=2.0)
        self.assertFalse(res.ok)
        self.assertIn("pooled constant", " ".join(res.problems))

    def test_named_symbol_mismatch_fails(self):
        res = self._compare(g_name="g_ts4_other")
        self.assertFalse(res.ok)

    def test_stub_source(self):
        text, alias = L.stub_source(["fn_1", "lbl_2", "__savegprlr_27"], {"fn_1"})
        self.assertIn("void lt1stub_0(void)", text)
        self.assertIn("int lt1stub_1[4]", text)
        self.assertIn("void lt1stub_2(void)", text)
        self.assertEqual(alias["lt1stub_2"], "__savegprlr_27")


if __name__ == "__main__":
    unittest.main()
