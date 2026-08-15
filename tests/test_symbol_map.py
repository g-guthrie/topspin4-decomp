import csv
import shutil
import subprocess
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]


class SymbolMapTests(unittest.TestCase):
    def test_reviewed_symbols_are_unique_and_well_formed(self):
        with (ROOT / "config" / "symbols.csv").open(newline="") as handle:
            rows = list(csv.DictReader(handle))
        self.assertEqual(len(rows), 38)
        identities = {(row["module"], row["address"]) for row in rows}
        self.assertEqual(len(identities), len(rows))
        for row in rows:
            self.assertEqual(row["module"], "Swing_DLL.xex")
            self.assertRegex(row["address"], r"^[0-9a-f]{8}$")
            self.assertIn(row["confidence"], {"high", "medium"})
            self.assertTrue(row["name"])
            self.assertTrue(row["evidence"])

    def test_reconstructed_source_has_valid_c_syntax(self):
        compiler = shutil.which("cc")
        if compiler is None:
            self.skipTest("no C compiler available")
        for source in sorted((ROOT / "src" / "xbox360").glob("*.c")):
            subprocess.run(
                [
                    compiler,
                    "-std=c11",
                    "-Wall",
                    "-Wextra",
                    "-Werror",
                    "-fsyntax-only",
                    str(source),
                ],
                check=True,
            )


if __name__ == "__main__":
    unittest.main()
