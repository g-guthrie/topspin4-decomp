"""Pure-parsing tests for the disc readers; every input is a synthetic byte string."""
import struct
import tempfile
import unittest
import zlib
from pathlib import Path

from tools import ts4_arc, ts4_lzx, ts4_xbin, xdvdfs


def dir_entry(left, right, sector, size, attr, name):
    raw = struct.pack("<HHIIBB", left, right, sector, size, attr, len(name)) + name.encode()
    return raw + b"\xff" * (-len(raw) % 4)


def build_image(base=0):
    """Tiny XDVDFS: root dir (sector 33) holds 'b.bin' (root of tree), 'a.txt' (left)
    and directory 'sub' (right) which holds 'c.dat'."""
    img = bytearray(base + 40 * 2048)
    vol = xdvdfs.MAGIC + struct.pack("<II", 33, 2048)
    img[base + 32 * 2048:base + 32 * 2048 + len(vol)] = vol
    # entries are addressed in 4-byte units
    e_b = dir_entry(0, 0, 36, 5, 0, "b.bin")
    e_a = dir_entry(0, 0, 37, 3, 0, "a.txt")
    e_sub = dir_entry(0, 0, 34, 2048, 0x10, "sub")
    off_a = len(e_b) // 4
    off_sub = off_a + len(e_a) // 4
    e_b = dir_entry(off_a, off_sub, 36, 5, 0, "b.bin")
    root = e_b + e_a + e_sub
    img[base + 33 * 2048:base + 33 * 2048 + len(root)] = root
    sub = dir_entry(0, 0, 38, 4, 0, "c.dat")
    img[base + 34 * 2048:base + 34 * 2048 + len(sub)] = sub
    img[base + 36 * 2048:base + 36 * 2048 + 5] = b"HELLO"
    img[base + 37 * 2048:base + 37 * 2048 + 3] = b"abc"
    img[base + 38 * 2048:base + 38 * 2048 + 4] = b"DATA"
    return bytes(img)


class XdvdfsTests(unittest.TestCase):
    def test_parse_volume(self):
        block = xdvdfs.MAGIC + struct.pack("<II", 7, 4096) + bytes(2048 - 28)
        self.assertEqual(xdvdfs.parse_volume(block), (7, 4096))
        with self.assertRaises(ValueError):
            xdvdfs.parse_volume(bytes(2048))

    def test_dir_entry_and_padding(self):
        e = xdvdfs.parse_dir_entry(dir_entry(1, 2, 9, 100, 0x10, "dir"), 0)
        self.assertEqual((e["left"], e["right"], e["sector"], e["size"], e["name"]), (1, 2, 9, 100, "dir"))
        self.assertIsNone(xdvdfs.parse_dir_entry(b"\xff" * 16, 0))

    def test_walk_find_extract(self):
        for base in (0, 0x2080000):
            img = build_image(base)
            with tempfile.TemporaryDirectory() as td:
                p = Path(td) / "t.iso"
                p.write_bytes(img)
                x = xdvdfs.XDVDFS(str(p))
                self.assertEqual(x.base, base)
                names = sorted(n for n, _ in x.walk())
                self.assertEqual(names, ["a.txt", "b.bin", "sub/", "sub/c.dat"])
                out = x.extract("SUB/c.dat", td)  # case-insensitive lookup
                self.assertEqual(Path(out).read_bytes(), b"DATA")
                self.assertEqual(x.open_slice("a.txt").read(), b"abc")
                with self.assertRaises(FileNotFoundError):
                    x.find("nope")


def lzx_uncompressed_stream(payload):
    """One uncompressed (type 3) LZX block holding payload; intel bit 0."""
    bits = (0 << 27) | (3 << 24) | len(payload)  # 1+3+24 = 28 bits, MSB-first, padded to 32
    bits <<= 4
    words = struct.pack("<HH", bits >> 16, bits & 0xFFFF)
    body = struct.pack("<III", 1, 1, 1) + payload + (b"\0" if len(payload) % 2 else b"")
    return words + body


class LzxTests(unittest.TestCase):
    def test_slot_tables(self):
        extra, base = ts4_lzx.slot_tables(8)
        self.assertEqual(extra, [0, 0, 0, 0, 1, 1, 2, 2])
        self.assertEqual(base, [0, 1, 2, 3, 4, 6, 8, 12])
        self.assertEqual(ts4_lzx.position_slots(15), 30)
        self.assertEqual(ts4_lzx.position_slots(20), 42)

    def test_huffman_canonical(self):
        h = ts4_lzx._Huff([1, 2, 3, 3])  # codes 0, 10, 110, 111
        br = ts4_lzx._Bits(struct.pack("<HH", 0b0101_1011_1000_0000, 0))
        got = [h.decode(br) for _ in range(5)]
        self.assertEqual(got, [0, 1, 2, 3, 0])

    def test_uncompressed_block(self):
        payload = b"top spin 4 test payload"
        dec = ts4_lzx.LZXDecoder(15)
        self.assertEqual(dec.decode_frame(lzx_uncompressed_stream(payload), len(payload)), payload)

    def test_e8_translation(self):
        buf = bytearray(b"\xe8\x05\x00\x00\x00" + b"\x90" * 16)
        ts4_lzx._e8(buf, 0, 1000)
        self.assertEqual(struct.unpack_from("<i", buf, 1)[0], 5)  # abs 5 -> rel 5-0
        buf = bytearray(b"\x90" * 3 + b"\xe8\x0a\x00\x00\x00" + b"\x90" * 16)
        ts4_lzx._e8(buf, 0, 1000)
        self.assertEqual(struct.unpack_from("<i", buf, 4)[0], 7)  # abs 10 at pos 3 -> 7


def build_blob(payload, nchunks=1):
    hdr_len = 36 + 8 * nchunks  # 24 + 12 digest + 4 hdr_len field + (n-1)*4 starts + n*4 checksums
    body = b""
    chunk_starts = []
    per = len(payload) if nchunks == 1 else len(payload) // nchunks
    pieces = [payload[i * per:(i + 1) * per] for i in range(nchunks - 1)] + [payload[(nchunks - 1) * per:]]
    for piece in pieces:
        chunk_starts.append(hdr_len + len(body))
        stream = lzx_uncompressed_stream(piece)
        body += b"\xff" + struct.pack(">HH", len(piece), len(stream)) + stream + b"\0" * 5
    head = ts4_arc.TAG + struct.pack(">4I", nchunks, per if nchunks > 1 else 1 << 20, len(pieces[-1]), len(payload)) + b"\0" * 12
    head += struct.pack(">I", hdr_len) + b"".join(struct.pack(">I", c) for c in chunk_starts[1:]) + b"\0" * (4 * nchunks)
    assert len(head) == hdr_len, (len(head), hdr_len)
    return head + body


class ArcTests(unittest.TestCase):
    def test_header_and_entries(self):
        tab = [(0x11111111, 0, 10), (0x22222222, 10, 20)]
        hdr = bytearray(0x24 + 12 * 2 + 16)
        struct.pack_into(">7I", hdr, 0, len(hdr) - 4, 0x20, 2, 2, 0x100, 1, 1)
        hdr[0x1C:0x24] = ts4_arc.TAG
        for i, t in enumerate(tab):
            struct.pack_into(">3I", hdr, 0x24 + 12 * i, *t)
        info = ts4_arc.parse_header(bytes(hdr))
        self.assertEqual(info["count"], 2)
        self.assertEqual(info["data_start"], len(hdr))
        self.assertEqual(info["entries"], tab)
        bad = bytes(hdr[:0x1C]) + b"XXXXXXXX" + bytes(hdr[0x24:])
        with self.assertRaises(ValueError):
            ts4_arc.parse_header(bad)

    def test_blob_roundtrip(self):
        data = bytes(range(200)) * 3
        self.assertEqual(ts4_arc.unpack_blob(build_blob(data)), data)
        self.assertEqual(ts4_arc.peek_blob(build_blob(data), 16), data[:16])

    def test_multi_chunk_blob(self):
        data = bytes(range(250)) * 4
        blob = build_blob(data, nchunks=3)
        win, total, chunks = ts4_arc.split_chunks(blob)
        self.assertEqual((win, total, len(chunks)), (len(data) // 3, len(data), 3))
        self.assertEqual(ts4_arc.unpack_blob(blob), data)

    def test_path_hash_and_child_hash(self):
        self.assertEqual(ts4_arc.path_hash("C:\\Media\\A.bin"), zlib.crc32(b"/media/a.bin"))
        d = zlib.crc32(b"/media/sub/")
        self.assertEqual(ts4_arc.child_hash(d, "File.BIN"), zlib.crc32(b"/media/sub/file.bin"))

    def test_parse_directories(self):
        hdr = bytearray(0x10) + struct.pack(">II", 0, 1)  # aux_off 0 -> table at 0x10
        hdr = bytearray(0x18)
        struct.pack_into(">II", hdr, 0x10, 0x10, 1)  # table at 0x10+0x10 = 0x20
        hdr += bytes(8)
        rec = struct.pack(">4I", 0x10, 1, 1, 0xABCD)  # children at 0x20+0x10 = 0x30
        child = struct.pack(">II", 8, 0)              # name at 0x30+8 = 0x38
        hdr += rec + child + b"x.bin\0"
        self.assertEqual(ts4_arc.parse_directories(bytes(hdr)), [(0xABCD, ["x.bin"])])

    def test_raw_entry_passthrough(self):
        self.assertEqual(ts4_arc.unpack_blob(b"plain"), b"plain")


def xbin_header(a, b, version=4):
    return struct.pack(">IIIII", a, b, version, 0, 0xFFFFFFFF)


class XbinTests(unittest.TestCase):
    def test_crc_matches_zlib(self):
        self.assertEqual(ts4_xbin.crc("abc"), zlib.crc32(b"abc"))

    def test_crc_dictionary(self):
        words = ["Alpha", "Be"]
        pool_off = 0x20 + 8 * len(words)
        buf = bytearray(xbin_header(1, 2) + struct.pack(">III", 0xC, len(words), len(words)))
        pool = b""
        for i, w in enumerate(words):
            entry_pos = 0x20 + 8 * i
            buf += struct.pack(">II", pool_off + len(pool) - entry_pos, zlib.crc32(w.encode()))
            pool += w.encode() + b"\0"
        buf += pool
        d = ts4_xbin.read_crc_dictionary(bytes(buf))
        self.assertEqual(d, {zlib.crc32(b"Alpha"): "Alpha", zlib.crc32(b"Be"): "Be"})
        buf[0x24:0x28] = b"\0\0\0\1"  # corrupt a key
        with self.assertRaises(ValueError):
            ts4_xbin.read_crc_dictionary(bytes(buf))

    def test_header_validation(self):
        self.assertEqual(ts4_xbin.parse_header(xbin_header(5, 6))["root_type"], 6)
        with self.assertRaises(ValueError):
            ts4_xbin.parse_header(b"\0" * 0x20)

    def test_array_desc_is_self_relative(self):
        buf = bytes(8) + struct.pack(">III", 0x20, 3, 4)
        self.assertEqual(ts4_xbin.read_array_desc(buf, 8), (0x28, 3, 4))

    def test_fields_and_field_array_lookup(self):
        t = 0x1234ABCD
        f = [(0x11, 0xC0000, 0x21, 0x10, 0xD543463B, 0x20, 0, 4, 0), (0x12, 0x80000, 0x22, 0x20, 0xD543463B, 0x21, 8, 4, 0)]
        layout = bytearray(0x34)
        rec_pos = len(layout)
        fields_pos = rec_pos + 36 + 8  # array starts after the 9-word record
        rec = struct.pack(">9I", t, 0, 0x77, 0, 0, 0, fields_pos - (rec_pos + 24), len(f), len(f))
        layout += rec + bytes(8) + b"".join(struct.pack(">9I", *x) for x in f)
        found = ts4_xbin.find_field_array(bytes(layout), t)
        self.assertEqual(found, (fields_pos, 2))
        got = ts4_xbin.read_fields(bytes(layout), *found)
        self.assertEqual([x["offset"] for x in got], [0, 8])
        self.assertEqual(got[0]["flags"], 0xC0000)

    def test_describe_root(self):
        t = 0x1234ABCD
        names = {0x21: "ListA", 0x22: "Pair"}
        f = [(0x11, 0xC0000, 0x21, 0x10, 0xD543463B, 0x20, 0, 4, 0), (0x12, 0x80000, 0x22, 0x20, 0xD543463B, 0x21, 12, 4, 0)]
        layout = bytearray(0x34)
        rec_pos = len(layout)
        fields_pos = rec_pos + 36 + 8
        layout += struct.pack(">9I", t, 0, 0x77, 0, 0, 0, fields_pos - (rec_pos + 24), 2, 2) + bytes(8)
        layout += b"".join(struct.pack(">9I", *x) for x in f)
        buf = bytearray(xbin_header(1, 2))
        buf += struct.pack(">III", 0x1C - 0x14 + 0x10 - 0x10 + 0x0, 0, 0)  # placeholder
        buf[0x14:0x20] = struct.pack(">III", 0x20, 2, 2)  # list at offset 0 -> data at 0x14+0x20
        buf += bytes(0x40)
        struct.pack_into(">2I", buf, 0x14 + 12, 0x3F800000, 0x41200000)
        out = ts4_xbin.describe_root(bytes(buf), bytes(layout), t, names)
        self.assertEqual(out[0]["name"], "ListA")
        self.assertEqual((out[0]["abs"], out[0]["count"]), (0x34, 2))
        self.assertEqual(out[1]["words"], [0x3F800000, 0x41200000])


if __name__ == "__main__":
    unittest.main()
