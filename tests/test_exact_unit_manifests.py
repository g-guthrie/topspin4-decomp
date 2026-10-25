"""Negative tests for the small legacy exact-unit manifest loader.

All mutations use an isolated miniature source tree. Importing matching once
checks the real manifest; individual tests never run a compiler or copy it.
"""

import copy
import hashlib
import json
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

from tools import matching


PREFIX = "src/xbox360/matched/remaining_20261025"


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


class RemainingManifestTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        config = self.root / "config" / matching.VERSION
        config.mkdir(parents=True)
        self.manifest = config / "remaining_20261025_units.json"
        rows = []
        symbol_index = 0
        for index in range(17):
            relative = f"{PREFIX}/unit_{index:02d}.c"
            source = self.root / relative
            source.parent.mkdir(parents=True, exist_ok=True)
            source.write_text("/* isolated loader fixture */\n", encoding="utf-8")
            symbols = {}
            for _ in range(1 if index < 16 else 12):
                name = f"fn_{0x88000000 + symbol_index * 4:08X}"
                symbols[name] = 6996 if symbol_index == 27 else 4
                symbol_index += 1
            rows.append({
                "source": relative,
                "object": f"unit_{index:02d}.obj",
                "symbols": symbols,
                "source_sha256": digest(source),
                "headers": {},
                "extra_flags": [],
            })
        header = self.root / PREFIX / "guest_std.h"
        header.write_text("/* isolated header */\n", encoding="utf-8")
        last_source = self.root / rows[-1]["source"]
        last_source.write_text('#include "guest_std.h"\n', encoding="utf-8")
        rows[-1]["source_sha256"] = digest(last_source)
        rows[-1]["headers"] = {f"{PREFIX}/guest_std.h": digest(header)}
        self.data = {
            "schema": "remaining-exact-units/1",
            "target": matching.MODULE,
            "count": 28,
            "bytes": 7104,
            "units": rows,
        }

    def load(self, data=None):
        self.manifest.write_text(json.dumps(data or self.data), encoding="utf-8")
        with patch.object(matching, "ROOT", self.root), patch.object(
            matching, "MATCHING_UNITS", ()
        ):
            return matching.load_remaining_20261025_units()

    def test_complete_fixture_loads(self):
        rows = self.load()
        self.assertEqual(len(rows), 17)
        self.assertEqual(sum(len(row["symbols"]) for row in rows), 28)

    def test_truncated_inventory_rejected(self):
        data = copy.deepcopy(self.data)
        data["units"].pop()
        with self.assertRaisesRegex(ValueError, "incomplete"):
            self.load(data)

    def test_duplicate_symbol_rejected(self):
        data = copy.deepcopy(self.data)
        first = next(iter(data["units"][0]["symbols"]))
        data["units"][1]["symbols"] = {first: 4}
        with self.assertRaisesRegex(ValueError, "duplicate"):
            self.load(data)

    def test_duplicate_object_rejected(self):
        data = copy.deepcopy(self.data)
        data["units"][1]["object"] = data["units"][0]["object"]
        with self.assertRaisesRegex(ValueError, "duplicate"):
            self.load(data)

    def test_source_path_escape_rejected(self):
        data = copy.deepcopy(self.data)
        data["units"][0]["source"] = f"{PREFIX}/../outside.c"
        with self.assertRaisesRegex(ValueError, "escaped"):
            self.load(data)

    def test_altered_source_hash_rejected(self):
        data = copy.deepcopy(self.data)
        data["units"][0]["source_sha256"] = "0" * 64
        with self.assertRaisesRegex(ValueError, "pin changed"):
            self.load(data)

    def test_missing_header_inventory_rejected(self):
        data = copy.deepcopy(self.data)
        del data["units"][-1]["headers"]
        with self.assertRaisesRegex(ValueError, "header closure missing"):
            self.load(data)

    def test_changed_header_pin_rejected(self):
        data = copy.deepcopy(self.data)
        header = next(iter(data["units"][-1]["headers"]))
        data["units"][-1]["headers"][header] = "0" * 64
        with self.assertRaisesRegex(ValueError, "pin changed"):
            self.load(data)

    def test_header_line_ending_conversion_rejected(self):
        data = copy.deepcopy(self.data)
        header_name = next(iter(data["units"][-1]["headers"]))
        header = self.root / header_name
        header.write_bytes(b"/* isolated header */\r\n")
        data["units"][-1]["headers"][header_name] = digest(header)
        self.load(data)
        header.write_bytes(b"/* isolated header */\n")
        with self.assertRaisesRegex(ValueError, "pin changed"):
            self.load(data)

    def test_omitted_header_entry_rejected(self):
        """The include graph cannot silently lose its only header pin."""
        data = copy.deepcopy(self.data)
        data["units"][-1]["headers"] = {}
        with self.assertRaises(ValueError):
            self.load(data)

    def test_unapproved_flags_rejected(self):
        data = copy.deepcopy(self.data)
        data["units"][0]["extra_flags"] = ["/O2", "/GL"]
        with self.assertRaisesRegex(ValueError, "unreviewed"):
            self.load(data)


if __name__ == "__main__":
    unittest.main()
