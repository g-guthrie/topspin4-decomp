import json
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]


class ProgressTests(unittest.TestCase):
    def test_progress_stages_are_explicit_and_monotonic(self):
        progress = json.loads((ROOT / "config" / "progress.json").read_text())

        self.assertLessEqual(
            progress["reconstructed_functions"], progress["semantic_drafts"]
        )
        self.assertLessEqual(
            progress["validated_functions"], progress["reconstructed_functions"]
        )
        self.assertLessEqual(
            progress["matching_functions"], progress["validated_functions"]
        )
        self.assertGreaterEqual(progress["matching_bytes"], 0)

    def test_matching_summary_agrees_with_evidence(self):
        progress = json.loads((ROOT / "config" / "progress.json").read_text())
        match = json.loads(
            (ROOT / "config" / "54540859" / "match.json").read_text()
        )

        self.assertTrue(progress["binary_match_verified"])
        self.assertEqual(
            progress["matching_functions"], match["module_matched_functions"]
        )
        self.assertEqual(progress["matching_bytes"], match["matched_code_bytes"])
        self.assertEqual(
            progress["matching_total_code_bytes"], match["module_total_code_bytes"]
        )
        self.assertEqual(
            progress["matching_code_percent"], match["module_matched_code_percent"]
        )
        self.assertEqual(
            match["matched_code_bytes"],
            sum(item["matched_code_bytes"] for item in match["matches"]),
        )
        self.assertEqual(match["module_matched_functions"], len(match["matches"]))
        self.assertTrue(
            all(item["function_match_percent"] == 100.0 for item in match["matches"])
        )

    def test_first_matching_unit_has_reviewed_boundaries_and_symbols(self):
        version_dir = ROOT / "config" / "54540859"
        splits = (version_dir / "splits.txt").read_text()
        symbols = (version_dir / "symbols.seed.txt").read_text()

        self.assertIn("src/xbox360/title_patch.c:", splits)
        self.assertIn("src/xbox360/title_server_logout.c:", splits)
        self.assertIn("src/xbox360/king_of_court_prepare.c:", splits)
        self.assertIn("src/xbox360/minigame_prepare.c:", splits)
        self.assertIn("src/xbox360/minigame_hide_tracksides.c:", splits)
        self.assertIn("start:0x88792820 end:0x88792888", splits)
        self.assertIn("start:0x88794FE8 end:0x88795020", splits)
        self.assertIn("start:0x887955A0 end:0x887955C4", splits)
        self.assertIn("start:0x88795548 end:0x8879556C", splits)
        self.assertIn("start:0x88795570 end:0x887955A0", splits)
        self.assertIn("ts4_script_title_server_logout", symbols)
        self.assertIn("ts4_script_king_of_court_prepare_ingame", symbols)
        self.assertIn("ts4_script_minigame_prepare_ingame", symbols)
        self.assertIn("ts4_script_minigame_hide_unused_tracksides", symbols)
        self.assertIn("ts4_script_title_server_get_patch", symbols)
        self.assertIn("text_padding_88B0079C", symbols)


if __name__ == "__main__":
    unittest.main()
