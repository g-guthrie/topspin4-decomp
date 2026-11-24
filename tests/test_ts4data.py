import subprocess
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


class Ts4DataReaderTests(unittest.TestCase):
    def run_selftest(self, name):
        result = subprocess.run(
            [sys.executable, "-I", str(ROOT / "tools" / "ts4data" / f"{name}.py"), "selftest"],
            capture_output=True, text=True,
        )
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        self.assertIn("selftest OK", result.stdout)

    def test_xbin_selftest(self):
        self.run_selftest("xbin")

    def test_hkx_selftest(self):
        # The Havok class table is derived from the SDK and exists only locally.
        if not (ROOT / "work" / "havok55_classes.json").is_file():
            self.skipTest("local work/havok55_classes.json not generated")
        self.run_selftest("hkx")


if __name__ == "__main__":
    unittest.main()
