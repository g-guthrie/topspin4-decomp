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
        self.assertIn("src/xbox360/title_server_login_user_only.c:", splits)
        self.assertIn("src/xbox360/title_server_callbacks.c:", splits)
        self.assertIn("src/xbox360/king_of_court_prepare.c:", splits)
        self.assertIn("src/xbox360/minigame_prepare.c:", splits)
        self.assertIn("src/xbox360/minigame_hide_tracksides.c:", splits)
        self.assertIn("src/xbox360/player_visibility.c:", splits)
        self.assertIn("src/xbox360/query_pro_player_list.c:", splits)
        self.assertIn("src/xbox360/minigame_change_display_mode.c:", splits)
        self.assertIn("src/xbox360/online_feature_stubs.c:", splits)
        self.assertIn("src/xbox360/generate_cpu_results.c:", splits)
        self.assertIn("src/xbox360/is_in_a_session.c:", splits)
        self.assertIn("src/xbox360/session_policy_stubs.c:", splits)
        self.assertIn("src/xbox360/competition_game_reset.c:", splits)
        self.assertIn("src/xbox360/reset_online_config.c:", splits)
        self.assertIn("src/xbox360/is_session_started.c:", splits)
        self.assertIn("src/xbox360/is_lobby_full.c:", splits)
        self.assertIn("src/xbox360/is_host.c:", splits)
        self.assertIn("src/xbox360/modify_session.c:", splits)
        self.assertIn("src/xbox360/set_no_disco.c:", splits)
        self.assertIn("start:0x8877BC98 end:0x8877BCE8", splits)
        self.assertIn("start:0x8877C0A0 end:0x8877C0F0", splits)
        self.assertIn("start:0x88778698 end:0x887786D0", splits)
        self.assertIn("start:0x88778CF0 end:0x88778D08", splits)
        self.assertIn("start:0x88778D08 end:0x88778D18", splits)
        self.assertIn("start:0x88779968 end:0x887799AC", splits)
        self.assertIn("start:0x8877BFD8 end:0x8877BFF8", splits)
        self.assertIn("start:0x887801E0 end:0x88780200", splits)
        self.assertIn("start:0x88780200 end:0x88780224", splits)
        self.assertIn("start:0x88792820 end:0x88792888", splits)
        self.assertIn("start:0x88792638 end:0x887926D8", splits)
        self.assertIn("start:0x88794E38 end:0x88794FE8", splits)
        self.assertIn("start:0x88794FE8 end:0x88795020", splits)
        self.assertIn("start:0x887955A0 end:0x887955C4", splits)
        self.assertIn("start:0x88795548 end:0x8879556C", splits)
        self.assertIn("start:0x88795570 end:0x887955A0", splits)
        self.assertIn("start:0x88794C18 end:0x88794CC4", splits)
        self.assertIn("start:0x88794CC8 end:0x88794E38", splits)
        self.assertIn("start:0x88792CB8 end:0x88792D48", splits)
        self.assertIn("ts4_script_title_server_logout", symbols)
        self.assertIn("ts4_script_title_server_login_user_only", symbols)
        self.assertIn("ts4_script_pro_challenge_title_server_login", symbols)
        self.assertIn("ts4_script_title_server_query_round_info", symbols)
        self.assertIn("ts4_script_king_of_court_prepare_ingame", symbols)
        self.assertIn("ts4_script_minigame_prepare_ingame", symbols)
        self.assertIn("ts4_script_minigame_hide_unused_tracksides", symbols)
        self.assertIn("ts4_script_set_player_body_visibility", symbols)
        self.assertIn("ts4_script_set_player_visibility", symbols)
        self.assertIn("ts4_script_pro_challenge_query_pro_player_list", symbols)
        self.assertIn("ts4_script_minigame_change_display_game_mode", symbols)
        self.assertIn("ts4_script_title_server_get_patch", symbols)
        self.assertIn("ts4_script_modify_session", symbols)
        self.assertIn("ts4_script_set_no_disco", symbols)
        self.assertIn("ts4_script_title_server_feature_unavailable", symbols)
        self.assertIn("ts4_script_is_in_a_session", symbols)
        self.assertIn("ts4_script_competition_game_reset", symbols)
        self.assertIn("ts4_script_reset_online_config", symbols)
        self.assertIn("ts4_script_is_session_started", symbols)
        self.assertIn("ts4_script_is_lobby_full", symbols)
        self.assertIn("ts4_script_is_host", symbols)
        self.assertIn("text_padding_88B0079C", symbols)


if __name__ == "__main__":
    unittest.main()
