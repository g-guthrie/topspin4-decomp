import json
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
VERSION_DIR = ROOT / "config" / "54540859"


def split_sources(text: str) -> set[str]:
    return {
        line[:-1]
        for line in text.splitlines()
        if line.startswith("src/") and line.endswith(":")
    }


def symbol_addresses(text: str) -> dict[str, str]:
    symbols = {}
    for line in text.splitlines():
        if " = " not in line or ":0x" not in line:
            continue
        name = line.split(" = ", 1)[0]
        address = line.split(":0x", 1)[1].split(";", 1)[0].upper()
        symbols[address] = name
    return symbols


class CanonicalBuildTests(unittest.TestCase):
    def test_exact_compiler_configuration(self):
        config = json.loads((VERSION_DIR / "config.json").read_text())
        self.assertEqual(
            config["cflags"]["base"]["flags"],
            ["/nologo", "/c", "/O2", "/Oi"],
        )

        objects = json.loads((VERSION_DIR / "objects.json").read_text())
        library = objects["swing"]
        self.assertEqual(library["mw_version"], "X360/16.00.10224.00")
        self.assertEqual(library["progress_category"], "game")

    def test_every_reviewed_split_has_a_matching_source_object(self):
        splits = split_sources((VERSION_DIR / "splits.txt").read_text())
        objects = json.loads((VERSION_DIR / "objects.json").read_text())
        configured = objects["swing"]["objects"]

        self.assertEqual(set(configured), splits)
        for unit_name, unit in configured.items():
            self.assertEqual(unit["status"], "Matching")
            self.assertTrue((ROOT / "src" / unit["source"]).is_file(), unit_name)

    def test_full_symbols_preserve_every_reviewed_seed_name(self):
        seed = symbol_addresses((VERSION_DIR / "symbols.seed.txt").read_text())
        full_text = (VERSION_DIR / "symbols.txt").read_text()
        full = symbol_addresses(full_text)

        self.assertGreater(len(full_text.splitlines()), 100_000)
        for address, name in seed.items():
            self.assertEqual(full.get(address), name, f"symbol at 0x{address}")

    def test_quick_analysis_uses_ignored_user_owned_input(self):
        config = (VERSION_DIR / "config.yml").read_text()
        self.assertIn("object: orig/54540859/Swing_DLL.xex", config)
        self.assertIn("symbols: config/54540859/symbols.txt", config)
        self.assertIn("splits: config/54540859/splits.txt", config)
        self.assertIn("symbols_known: true", config)
        self.assertIn("quick_analysis: true", config)


if __name__ == "__main__":
    unittest.main()
