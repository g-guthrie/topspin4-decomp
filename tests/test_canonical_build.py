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

    def test_link_probe_is_explicitly_non_runnable(self):
        status = json.loads((ROOT / "config" / "link-status.json").read_text())
        self.assertEqual(status["input_matching_functions"], 8)
        self.assertEqual(status["input_matching_code_bytes"], 64)
        self.assertEqual(status["output_text_bytes"], 64)
        self.assertEqual(status["input_object_kind"], "source-built base objects")
        self.assertEqual(
            status["input_object_path_prefix"],
            "build/54540859/src/src/xbox360/",
        )
        self.assertIn("/OPT:NOREF", status["link_flags"])
        self.assertFalse(status["has_entry_point"])
        self.assertFalse(status["is_xex"])
        self.assertFalse(status["is_runnable"])
        self.assertFalse(status["runtime_tested"])
        self.assertFalse(status["artifact_committed"])

        forced = status["forced_all_units_probe"]
        self.assertEqual(forced["input_source_objects"], 22)
        self.assertEqual(forced["input_matching_functions"], 31)
        self.assertEqual(forced["map_matching_public_functions"], 31)
        self.assertEqual(forced["unresolved_external_symbols"], 24)
        self.assertFalse(forced["is_xex"])
        self.assertFalse(forced["is_runnable"])


if __name__ == "__main__":
    unittest.main()
