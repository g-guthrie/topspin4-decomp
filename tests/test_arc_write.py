"""Tests for tools/ts4_arc_write.py and tools/ts4_analyser_patch.py.

Every archive and member here is synthetic (built in this file); no game bytes are used.
"""
import io
import os
import random
import struct
import tempfile
import unittest
import zlib

from tools import ts4_arc, ts4_arc_write as W, ts4_analyser_patch as P
from tools import ts4_analyser as A
from tests.test_analyser import build_expressions

DIR = "/media/"
NAMES = ["alpha.bin", "beta.bin", "gamma.txt", "delta.bin"]


def make_member(data, mode):
    if mode == "raw":
        return bytes(data)
    return W.encode_lzx_stored(data)


def build_arc(members, gaps=(), tail=b""):
    """members: {leaf name: stored bytes}.  Returns archive bytes in the on-disc layout:
    header, FAT sorted by key, directory index, name pool; data in insertion order with
    optional padding gaps (bytes) before each member and a tail."""
    dh = zlib.crc32(DIR.encode())
    names = list(members)
    count = len(names)
    keys = [ts4_arc.child_hash(dh, n) for n in names]
    table_end = 0x24 + 12 * count
    base = (table_end + 15) & ~15               # directory record array
    rel_children = base + 16                    # child array
    pool = rel_children + 8 * count
    name_off, p = [], pool
    for n in names:
        name_off.append(p)
        p += len(n) + 1
    header_len = (p + 15) & ~15
    hdr = bytearray(header_len)
    struct.pack_into(">7I", hdr, 0, header_len - 4, 0x20, count, count, base - 0x10, 1, 1)
    hdr[0x1C:0x24] = ts4_arc.TAG
    # directory record {rel, count, count, dir_hash}, children {rel_to_name, u32}
    struct.pack_into(">4I", hdr, base, rel_children - base, count, count, dh)
    for i, n in enumerate(names):
        c = rel_children + 8 * i
        struct.pack_into(">II", hdr, c, name_off[i] - c, 0)
        hdr[name_off[i]:name_off[i] + len(n)] = n.encode()
    data, fat = bytearray(), []
    for i, n in enumerate(names):
        data += bytes(gaps[i]) if i < len(gaps) else b""
        fat.append((keys[i], len(data), len(members[n])))
        data += members[n]
    data += tail
    for j, (k, o, s) in enumerate(sorted(fat)):
        struct.pack_into(">3I", hdr, 0x24 + 12 * j, k, o, s)
    return bytes(hdr) + bytes(data)


def payloads():
    rnd = random.Random(7)
    return {
        "alpha.bin": bytes(rnd.randrange(256) for _ in range(5000)),
        "beta.bin": b"B" * 123,
        "gamma.txt": b"hello world\n" * 40,
        "delta.bin": bytes(rnd.randrange(256) for _ in range(777)),
    }


def _write(path, data):
    with open(path, "wb") as f:
        f.write(data)


def _read(path):
    with open(path, "rb") as f:
        return f.read()


def open_bytes(b):
    return ts4_arc.Arc(io.BytesIO(b))


def rebuilt(orig_bytes, repl, mode="raw"):
    out = io.BytesIO()
    st = W.rebuild(open_bytes(orig_bytes), repl, out, mode)
    return out.getvalue(), st


class StoredBlobTests(unittest.TestCase):
    def test_lzx_stored_roundtrip_sizes(self):
        rnd = random.Random(1)
        for n in (0, 1, 7, 32767, 32768, 32769, 65536 + 5, (1 << 20) - 1, 1 << 20, (1 << 20) + 1, 2_500_003):
            data = bytes(rnd.randrange(256) for _ in range(64)) * (n // 64) + bytes(n % 64)
            blob = W.encode_lzx_stored(data)
            self.assertEqual(blob[:8], ts4_arc.TAG)
            self.assertEqual(ts4_arc.unpack_blob(blob), data, n)
            nch = struct.unpack_from(">I", blob, 8)[0]
            self.assertEqual(nch, max(1, (n + (1 << 20) - 1) >> 20))
            self.assertEqual(struct.unpack_from(">I", blob, 20)[0], n)

    def test_chunk_checksums_are_crc32_of_chunk_bytes(self):
        data = b"xyz" * 500000                       # two chunks
        blob = W.encode_lzx_stored(data)
        nch, _w, _last, _tot = struct.unpack_from(">4I", blob, 8)
        hdr_len = struct.unpack_from(">I", blob, 36)[0]
        starts = [hdr_len] + list(struct.unpack_from(">%dI" % (nch - 1), blob, 40))
        ends = starts[1:] + [len(blob)]
        sums = struct.unpack_from(">%dI" % nch, blob, 40 + 4 * (nch - 1))
        for s, e, c in zip(starts, ends, sums):
            self.assertEqual(zlib.crc32(blob[s:e]) & 0xFFFFFFFF, c)
        self.assertEqual(hdr_len, 36 + 8 * nch)

    def test_digest_is_preserved_from_original(self):
        orig = W.encode_lzx_stored(b"abc")
        orig = orig[:24] + bytes(range(12)) + orig[36:]
        new = W.encode_member(b"defgh", "lzx-stored", orig)
        self.assertEqual(new[24:36], bytes(range(12)))
        self.assertEqual(ts4_arc.unpack_blob(new), b"defgh")


class RebuildTests(unittest.TestCase):
    def setUp(self):
        self.p = payloads()
        self.stored = {n: (make_member(d, "lzx-stored") if i % 2 == 0 else d)
                       for i, (n, d) in enumerate(self.p.items())}
        self.orig = build_arc(self.stored, gaps=[b"", b"\xAA" * 3, b"", b"\x55" * 9], tail=b"TAILBYTES")

    def test_synthetic_archive_parses(self):
        a = open_bytes(self.orig)
        self.assertEqual(a.count, 4)
        self.assertEqual({n for _k, (_d, n) in a.leaf_names.items()}, set(NAMES))

    def test_identity_is_byte_identical(self):
        new, st = rebuilt(self.orig, {})
        self.assertEqual(new, self.orig)
        self.assertEqual(st["replaced"], [])

    def test_replace_by_name_hex_and_path(self):
        a = open_bytes(self.orig)
        key = ts4_arc.child_hash(zlib.crc32(DIR.encode()), "beta.bin")
        self.assertEqual(W.resolve_key(a, "beta.bin"), key)
        self.assertEqual(W.resolve_key(a, "BETA.BIN"), key)
        self.assertEqual(W.resolve_key(a, "%08x" % key), key)
        self.assertEqual(W.resolve_key(a, "0x%08X" % key), key)
        self.assertEqual(W.resolve_key(a, key), key)
        self.assertEqual(W.resolve_key(a, "/media/beta.bin"), key)
        with self.assertRaises(KeyError):
            W.resolve_key(a, "nope.bin")

    def test_replace_each_mode_grow_shrink_same(self):
        for mode in ("raw", "lzx-stored"):
            for name in NAMES:
                for new_data in (b"", b"Z" * 3, self.p[name], self.p[name] + b"\x01" * 4321):
                    new, st = rebuilt(self.orig, {name: new_data}, mode)
                    a0, a1 = open_bytes(self.orig), open_bytes(new)
                    self.assertEqual(W.verify(a0, a1, {name: new_data}), 4, (mode, name))
                    self.assertEqual(a1.hdr[:0x24], a0.hdr[:0x24])
                    self.assertEqual(len(a1.hdr), len(a0.hdr))

    def test_gaps_and_tail_preserved(self):
        new, _ = rebuilt(self.orig, {"alpha.bin": b"q" * 10})
        self.assertTrue(new.endswith(b"TAILBYTES"))
        self.assertIn(b"\xAA" * 3, new)
        self.assertIn(b"\x55" * 9, new)

    def test_raw_replacement_is_stored_without_wrapper(self):
        new, _ = rebuilt(self.orig, {"alpha.bin": b"RAWDATA!" * 10})
        a = open_bytes(new)
        key = W.resolve_key(a, "alpha.bin")
        self.assertEqual(a.raw(a.find(key)), b"RAWDATA!" * 10)

    def test_data_order_and_other_members_untouched(self):
        a0 = open_bytes(self.orig)
        new, _ = rebuilt(self.orig, {"beta.bin": b"x" * 4000})
        a1 = open_bytes(new)
        order0 = [e[0] for e in sorted(a0.entries, key=lambda e: e[1])]
        order1 = [e[0] for e in sorted(a1.entries, key=lambda e: e[1])]
        self.assertEqual(order0, order1)
        beta = W.resolve_key(a0, "beta.bin")
        for e0, e1 in zip(a0.entries, a1.entries):
            if e0[0] != beta:
                self.assertEqual(a0.raw(e0), a1.raw(e1))

    def test_shared_storage_entries_follow_the_replacement(self):
        # two FAT entries pointing at one stored blob
        arc = bytearray(self.orig)
        a = open_bytes(bytes(arc))
        e0, e1 = a.entries[0], a.entries[1]
        struct.pack_into(">II", arc, a.table_start + 12 + 4, e0[1], e0[2])
        new, _ = rebuilt(bytes(arc), {e0[0]: b"shared"})
        a2 = open_bytes(new)
        self.assertEqual(a2.entries[0][1:], a2.entries[1][1:])
        self.assertEqual(a2.read(a2.entries[1]), b"shared")

    def test_overlapping_members_are_rejected(self):
        arc = bytearray(self.orig)
        a = open_bytes(bytes(arc))
        struct.pack_into(">II", arc, a.table_start + 12 + 4, a.entries[0][1] + 1, a.entries[0][2])
        with self.assertRaises(ValueError):
            rebuilt(bytes(arc), {})

    def test_reencode_member_by_itself(self):
        a = open_bytes(self.orig)
        for mode in ("raw", "lzx-stored"):
            data = {n: a.read(a.find(W.resolve_key(a, n))) for n in NAMES}
            new, _ = rebuilt(self.orig, data, mode)     # every member re-encoded
            self.assertEqual(W.verify(a, open_bytes(new), data), 4)

    def test_cli_refuses_to_overwrite_input(self):
        with tempfile.TemporaryDirectory() as d:
            src = os.path.join(d, "in.arc")
            _write(src, self.orig)
            import subprocess, sys
            tools = os.path.join(os.path.dirname(os.path.abspath(W.__file__)), "ts4_arc_write.py")
            r = subprocess.run([sys.executable, "-I", tools, src, src], capture_output=True)
            self.assertNotEqual(r.returncode, 0)
            self.assertEqual(_read(src), self.orig)
            out = os.path.join(d, "out", "o.arc")
            rep = os.path.join(d, "rep.bin")
            _write(rep, b"new content")
            r = subprocess.run([sys.executable, "-I", tools, src, out, "--replace", "gamma.txt=" + rep,
                                "--verify"], capture_output=True)
            self.assertEqual(r.returncode, 0, r.stderr)
            self.assertEqual(_read(src), self.orig)
            a = ts4_arc.Arc(out)
            self.assertEqual(a.read(a.find(W.resolve_key(a, "gamma.txt"))), b"new content")
            a.f.close()


class AnalyserPatchTests(unittest.TestCase):
    def graph(self):
        return dict(
            name=A.crc("ShotDifficulty"), nregs=4,
            inputs=[(0x1BF15200, 0, -1, [1, 2])], outputs=[(0x1BF15200, 3, -1, [3])],
            nodes=[("CONST", dict(out=1, value=2.0)),
                   ("CURVE", dict(**{"in": 0}, out=2, keys=[(0.0, 1.0, 10.0, 5.0), (1.0, 3.0, 20.0, 1.0)])),
                   ("SUM", dict(slots=[1, 2], out=3))])

    def setUp(self):
        self.buf = build_expressions([self.graph(), dict(self.graph(), name=A.crc("Other"))])

    def test_patch_const_and_curve_keys(self):
        patch = {"ShotDifficulty": {"0": {"value": 4.5},
                                    "1": {"keys": {"0": {"y0": 11.0}, "1": {"slope": 2.0, "x1": 4.0}}}}}
        out, rep = P.patch_expressions(self.buf, patch, probe=(0.0, 0.5, 2.0))
        self.assertEqual(len(out), len(self.buf))
        self.assertEqual(rep["words_changed"], 4)
        gs = A.parse_expressions(out)
        self.assertEqual(gs[0].nodes[0].fields["value"], 4.5)
        k = gs[0].nodes[1].fields["keys"]
        self.assertEqual((k[0][2], k[1][3], k[1][1]), (11.0, 2.0, 4.0))
        self.assertEqual(gs[1].nodes[0].fields["value"], 2.0)      # the other graph is untouched
        ev = {e["input"]: e for e in rep["evaluations"]}
        self.assertEqual(ev[0.5]["before"], [2.0 + (10.0 + 5.0 * 0.5)])
        self.assertEqual(ev[0.5]["after"], [4.5 + (11.0 + 5.0 * 0.5)])

    def test_selectors_hash_index_and_list_keys(self):
        for sel in ("%08x" % A.crc("ShotDifficulty"), "#0", "ShotDifficulty"):
            out, _ = P.patch_expressions(self.buf, {sel: {"1": {"keys": [{}, {"y0": 7.0}]}}})
            self.assertEqual(A.parse_expressions(out)[0].nodes[1].fields["keys"][1][2], 7.0)

    def test_errors(self):
        for bad in ({"Missing": {"0": {"value": 1.0}}},
                    {"ShotDifficulty": {"9": {"value": 1.0}}},
                    {"ShotDifficulty": {"2": {"value": 1.0}}},          # SUM is not patchable
                    {"ShotDifficulty": {"0": {"keys": {}}}},
                    {"ShotDifficulty": {"1": {"keys": {"5": {"y0": 1.0}}}}},
                    {"ShotDifficulty": {"1": {"keys": {"0": {"bogus": 1.0}}}}}):
            with self.assertRaises((KeyError, ValueError)):
                P.patch_expressions(self.buf, bad)

    def test_empty_patch_is_identity(self):
        out, rep = P.patch_expressions(self.buf, {})
        self.assertEqual(out, self.buf)
        self.assertEqual(rep["words_changed"], 0)


if __name__ == "__main__":
    unittest.main()
