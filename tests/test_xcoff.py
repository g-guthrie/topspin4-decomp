import struct
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
from xcoff import read_coff  # noqa: E402


def synthetic_coff(relocation_count: int) -> bytes:
    """One .text section with `relocation_count` REL24 relocations to one symbol."""
    header_size, section_size = 20, 40
    text = bytes(16)
    text_ptr = header_size + section_size
    reloc_ptr = text_ptr + len(text)
    overflow = relocation_count > 0xFFFF
    stored = relocation_count + 1 if overflow else relocation_count
    relocs = b""
    if overflow:
        relocs += struct.pack("<IIH", stored, 0, 0)
    relocs += b"".join(struct.pack("<IIH", (i % 4) * 4, 0, 6) for i in range(relocation_count))
    symtab_ptr = reloc_ptr + len(relocs)
    symbol = struct.pack("<8sIhHBB", b"target", 0, 1, 0x20, 2, 0)
    characteristics = 0x60000020 | (0x01000000 if overflow else 0)
    file_header = struct.pack("<HHIIIHH", 0x1F2, 1, 0, symtab_ptr, 1, 0, 0)
    section = struct.pack("<8sIIIIIIHHI", b".text", 0, 0, len(text), text_ptr, reloc_ptr, 0,
                          0xFFFF if overflow else stored, 0, characteristics)
    return file_header + section + text + relocs + symbol + struct.pack("<I", 4)


class XcoffTests(unittest.TestCase):
    def read(self, count):
        with tempfile.TemporaryDirectory() as temp:
            path = Path(temp) / "t.obj"
            path.write_bytes(synthetic_coff(count))
            return read_coff(path)

    def test_small_relocation_count(self):
        self.assertEqual(len(self.read(10).sections[0].relocs), 10)

    def test_relocation_count_overflow(self):
        coff = self.read(70000)
        relocs = coff.sections[0].relocs
        self.assertEqual(len(relocs), 70000)
        self.assertTrue(all(r.symbol == "target" for r in relocs))


if __name__ == "__main__":
    unittest.main()
