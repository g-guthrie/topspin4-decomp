"""Tests for tools/ts4data/names.py (crc algebra, structural rules, dictionary file round trip).

Synthetic only: the layout is built with the helper of test_tunables; no game bytes are used.
"""
import os
import sys
import tempfile
import unittest
import zlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
sys.path.insert(0, str(ROOT / "tools" / "ts4data"))
sys.path.insert(0, str(ROOT / "tests"))

import ts4_xbin as X  # noqa: E402
import names as N  # noqa: E402
from test_tunables import SINGLE, build_layout, crc  # noqa: E402

NS = "Test::Data::"


class CrcAlgebraTests(unittest.TestCase):
    def test_crc_prefix_inverts_suffix(self):
        for pre, suf in (("Pam::Swing::", "GameDB"), ("", "X"), ("abc", "")):
            t = zlib.crc32((pre + suf).encode())
            self.assertEqual(N.crc_prefix(t, suf.encode()), zlib.crc32(pre.encode()))

    def test_shift_is_the_linear_part(self):
        p = zlib.crc32(b"Some::Prefix_")
        for w in (b"A", b"Member", b"LongerMemberName12"):
            self.assertEqual(zlib.crc32(w, p), N.shift(p, len(w)) ^ zlib.crc32(w))

    def test_implied_length(self):
        p = zlib.crc32(b"Parent_")
        self.assertIn(6, N.implied_length(p, crc("Member"), crc("Parent_Member")))
        # any other 6-letter word with the same crc would pass too: the check is the length only
        self.assertNotIn(5, N.implied_length(p, crc("Member"), crc("Parent_Member")))


def make_layout():
    root, sub, other = NS + "Root", NS + "Root_Speed", NS + "Gauge"
    lay = build_layout([
        (crc(root), 0x20, 4, [("MaxValue", SINGLE, 0x18, 4)],
         [("Speed", crc(sub), X.KIND_INLINE, 0x00), ("Gauge", crc(other), X.KIND_INLINE, 0x08)]),
        (crc(sub), 8, 4, [("MinSpeed", SINGLE, 0, 4), ("MaxSpeed", SINGLE, 4, 4)], []),
        (crc(other), 8, 4, [("Value", SINGLE, 0, 4)], []),
        (crc(NS + "Meter"), 4, 4, [("Level", SINGLE, 0, 4)], [("Gauge", crc(other), X.KIND_INLINE, 0)]),
    ])
    return X.Layout(lay), root, sub, other


class StructureTests(unittest.TestCase):
    def setUp(self):
        self.layout, self.root, self.sub, self.other = make_layout()
        tgt, types, members = N.collect_targets(self.layout, [])
        self.names = N.Names(tgt, types, members)
        self.st = N.Structure(self.layout)

    def test_nested_detected_on_hashes(self):
        key = (crc(self.root), crc("Speed"))
        self.assertEqual(self.st.nested[key], (crc(self.sub), len("Speed")))
        self.assertNotIn((crc(self.root), crc("Gauge")), self.st.nested)

    def test_propagate_nested_and_namespace(self):
        old = list(N.KNOWN_NAMESPACES)
        N.KNOWN_NAMESPACES[:] = [NS]
        try:
            self.names.add(crc(self.root), self.root, "seed")
            self.names.add(crc("Speed"), "Speed", "token")
            self.names.add(crc("Gauge"), "Gauge", "token")
            N.propagate(self.names, self.st)
        finally:
            N.KNOWN_NAMESPACES[:] = old
        self.assertEqual(self.names.name(crc(self.sub)), self.sub)          # Parent_member
        self.assertEqual(self.names.name(crc(self.other)), self.other)      # namespace + member
        self.assertEqual(self.names.found[crc(self.sub)][1], "nested")
        self.assertEqual(self.names.found[crc(self.other)][1], "nsrule")

    def test_length_guided_and_sibling_guesses(self):
        self.names.add(crc(self.root), self.root, "seed")
        hints = self.st.length_hints([])
        self.assertEqual(hints[crc("Speed")], {5})
        self.assertEqual(N.guess_with_length(self.names, hints, ["Gauge", "Speed", "Spe", "Ed"], 4), 1)
        self.assertEqual(self.names.name(crc("Speed")), "Speed")
        self.names.add(crc("MinSpeed"), "MinSpeed", "token")
        N.guess_siblings(self.names, self.layout, [])
        self.assertEqual(self.names.name(crc("MaxSpeed")), "MaxSpeed")
        self.assertEqual(self.names.found[crc("MaxSpeed")][1], "sibling")

    def test_rejects_junk_for_types_and_members(self):
        junk = "x9$#"
        self.assertFalse(N.identlike(junk))
        self.assertTrue(N.identlike("Pam::SwingGamePlay::Data::PlayerState_ServeState"))
        self.assertFalse(N.identlike("Played Continental test (LOST)"))


class YamlTests(unittest.TestCase):
    def test_round_trip_keeps_hand_entries(self):
        entries = {crc("Alpha"): ("Alpha", "token", "high", None),
                   crc('Quote"d'): ('Quote"d', "G4b", "medium", "hand added")}
        with tempfile.TemporaryDirectory() as d:
            p = os.path.join(d, "names.yaml")
            N.write_yaml_names(p, entries, {"found": 2})
            back = N.read_yaml_names(p)
            self.assertEqual(back, entries)
            self.assertEqual(N.load_merge(p), entries)
            self.assertEqual(X.load_names(p)[crc("Alpha")], "Alpha")


if __name__ == "__main__":
    unittest.main()
