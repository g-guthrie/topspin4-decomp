"""Consistency checks for the second matching target, Loader_DLL.xex."""

import json
import re
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CONFIG = ROOT / "config" / "54540859" / "loader"


class LoaderTargetTests(unittest.TestCase):
    def setUp(self):
        self.units = json.loads((CONFIG / "units.json").read_text())["units"]
        self.splits = (CONFIG / "splits.txt").read_text()
        self.seed = (CONFIG / "symbols.seed.txt").read_text()
        self.summary = json.loads((CONFIG / "match.json").read_text())

    def test_every_unit_has_a_source_split_and_seed_names(self):
        for unit in self.units:
            with self.subTest(source=unit["source"]):
                self.assertTrue((ROOT / unit["source"]).is_file())
                self.assertIn(f"\n{unit['source']}:\n", "\n" + self.splits)
                for name in unit["symbols"]:
                    self.assertRegex(self.seed, rf"(?m)^{re.escape(name)} = \.text:0x")

    def test_summary_agrees_with_the_unit_table(self):
        symbols = {n: s for u in self.units for n, s in u["symbols"].items()}
        self.assertEqual(len(symbols), sum(len(u["symbols"]) for u in self.units))
        self.assertEqual(self.summary["module"], "Loader_DLL.xex")
        self.assertEqual(self.summary["matched_functions"], len(symbols))
        self.assertEqual(self.summary["matched_code_bytes"], sum(symbols.values()))
        total = self.summary["module_total_code_bytes"]
        self.assertAlmostEqual(
            self.summary["module_matched_code_percent"],
            round(100.0 * sum(symbols.values()) / total, 8),
        )

    def test_loader_bootstrap_seed_is_present(self):
        self.assertIn("text_metadata_83517E14 = .text:0x83517E14;", self.seed)


if __name__ == "__main__":
    unittest.main()
