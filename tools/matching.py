#!/usr/bin/env python3
"""Build and measure the reviewed Xbox 360 matching translation units."""

from __future__ import annotations

import argparse
import hashlib
import json
import shutil
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
VERSION = "54540859"
MODULE = "Swing_DLL.xex"
MATCHING_UNITS = (
    {
        "source": "src/xbox360/online_feature_stubs.c",
        "object": "online_feature_stubs.obj",
        "symbols": {
            "ts4_script_title_server_feature_unavailable": 8,
            "ts4_script_online_ps3_is_invitation_enabled": 8,
            "ts4_script_online_ps3_is_player_created_enabled": 8,
            "ts4_script_online_true_stub": 8,
            "ts4_script_remove_ai_player_from_lobby": 8,
            "ts4_script_online_false_stub_a": 8,
            "ts4_script_online_false_stub_b": 8,
        },
    },
    {
        "source": "src/xbox360/generate_cpu_results.c",
        "object": "generate_cpu_results.obj",
        "symbols": {"ts4_script_generate_cpu_results": 8},
    },
    {
        "source": "src/xbox360/is_in_a_session.c",
        "object": "is_in_a_session.obj",
        "symbols": {"ts4_script_is_in_a_session": 24},
    },
    {
        "source": "src/xbox360/session_policy_stubs.c",
        "object": "session_policy_stubs.obj",
        "symbols": {
            "ts4_script_session_policy_true": 8,
            "ts4_script_set_everyone_ready_in_lobby": 8,
        },
    },
    {
        "source": "src/xbox360/competition_game_reset.c",
        "object": "competition_game_reset.obj",
        "symbols": {"ts4_script_competition_game_reset": 8},
    },
    {
        "source": "src/xbox360/competition_game_ask_for_character.c",
        "object": "competition_game_ask_for_character.obj",
        "symbols": {
            "competition_game_ask_for_character": 164
        },
    },
    {
        "source": "src/xbox360/reset_online_config.c",
        "object": "reset_online_config.obj",
        "symbols": {"ts4_script_reset_online_config": 68},
    },
    {
        "source": "src/xbox360/session_match_accessor.c",
        "object": "session_match_accessor.obj",
        "symbols": {"ts4_get_session_match_descriptor": 16},
    },
    {
        "source": "src/xbox360/is_session_started.c",
        "object": "is_session_started.obj",
        "symbols": {"ts4_script_is_session_started": 32},
    },
    {
        "source": "src/xbox360/is_remote.c",
        "object": "is_remote.obj",
        "symbols": {"ts4_script_is_remote": 168},
    },
    {
        "source": "src/xbox360/tsu_session_stats.c",
        "object": "tsu_session_stats.obj",
        "symbols": {
            "ts4_script_tsu_replace_search_results_with_session_stats": 188
        },
    },
    {
        "source": "src/xbox360/tsu_copy_local_stat_to_netdb.c",
        "object": "tsu_copy_local_stat_to_netdb.obj",
        "symbols": {"ts4_script_copy_local_stat_to_netdb": 296},
    },
    {
        "source": "src/xbox360/tsu_refresh_tournament_sessions.c",
        "object": "tsu_refresh_tournament_sessions.obj",
        "symbols": {"tsu_refresh_tournament_sessions": 52},
    },
    {
        "source": "src/xbox360/tsu_per_round_stats.c",
        "object": "tsu_per_round_stats.obj",
        "extra_flags": ["/GS-"],
        "symbols": {
            "tsu_replace_search_results_with_per_round_stats": 340
        },
    },
    {
        "source": "src/xbox360/tsu_debug_add_fake_player.c",
        "object": "tsu_debug_add_fake_player.obj",
        "symbols": {
            "tsu_debug_add_fake_player_to_lobby": 56
        },
    },
    {
        "source": "src/xbox360/tsu_debug_remove_fake_player.c",
        "object": "tsu_debug_remove_fake_player.obj",
        "symbols": {
            "tsu_debug_remove_fake_player_from_lobby": 164
        },
    },
    {
        "source": "src/xbox360/tsu_debug_end_season.c",
        "object": "tsu_debug_end_season.obj",
        "symbols": {"tsu_debug_end_season": 160},
    },
    {
        "source": "src/xbox360/tsu_debug_send_end_season.c",
        "object": "tsu_debug_send_end_season.obj",
        "symbols": {
            "tsu_debug_send_end_season_to_all": 160
        },
    },
    {
        "source": "src/xbox360/tsu_season_time.c",
        "object": "tsu_season_time.obj",
        "symbols": {
            "ts4_script_has_time_to_enter_lobby_before_season_end": 28,
            "ts4_script_has_time_before_season_end": 28,
        },
    },
    {
        "source": "src/xbox360/tsu_reset_season_rank_history.c",
        "object": "tsu_reset_season_rank_history.obj",
        "symbols": {"ts4_script_reset_season_rank_history": 56},
    },
    {
        "source": "src/xbox360/tsu_declare_match_official.c",
        "object": "tsu_declare_match_official.obj",
        "symbols": {"ts4_script_declare_match_official": 52},
    },
    {
        "source": "src/xbox360/is_local_user_a_guest.c",
        "object": "is_local_user_a_guest.obj",
        "symbols": {"ts4_script_is_local_user_a_guest": 180},
    },
    {
        "source": "src/xbox360/is_lobby_full.c",
        "object": "is_lobby_full.obj",
        "symbols": {"ts4_script_is_lobby_full": 32},
    },
    {
        "source": "src/xbox360/is_host.c",
        "object": "is_host.obj",
        "symbols": {"ts4_script_is_host": 36},
    },
    {
        "source": "src/xbox360/modify_session.c",
        "object": "modify_session.obj",
        "symbols": {"ts4_script_modify_session": 80},
    },
    {
        "source": "src/xbox360/set_no_disco.c",
        "object": "set_no_disco.obj",
        "symbols": {"ts4_script_set_no_disco": 80},
    },
    {
        "source": "src/xbox360/title_server_login_user_only.c",
        "object": "title_server_login_user_only.obj",
        "symbols": {"ts4_script_title_server_login_user_only": 160},
    },
    {
        "source": "src/xbox360/title_server_callbacks.c",
        "object": "title_server_callbacks.obj",
        "symbols": {
            "ts4_script_pro_challenge_title_server_login": 160,
            "ts4_script_title_server_query_round_info": 272,
        },
    },
    {
        "source": "src/xbox360/minigame_change_display_mode.c",
        "object": "minigame_change_display_mode.obj",
        "symbols": {"ts4_script_minigame_change_display_game_mode": 144},
    },
    {
        "source": "src/xbox360/player_visibility.c",
        "object": "player_visibility.obj",
        "symbols": {
            "ts4_script_set_player_body_visibility": 84,
            "ts4_script_set_player_visibility": 84,
        },
    },
    {
        "source": "src/xbox360/query_pro_player_list.c",
        "object": "query_pro_player_list.obj",
        "symbols": {"ts4_script_pro_challenge_query_pro_player_list": 364},
    },
    {
        "source": "src/xbox360/minigame_prepare.c",
        "object": "minigame_prepare.obj",
        "symbols": {"ts4_script_minigame_prepare_ingame": 36},
    },
    {
        "source": "src/xbox360/minigame_hide_tracksides.c",
        "object": "minigame_hide_tracksides.obj",
        "symbols": {"ts4_script_minigame_hide_unused_tracksides": 48},
    },
    {
        "source": "src/xbox360/king_of_court_prepare.c",
        "object": "king_of_court_prepare.obj",
        "symbols": {"ts4_script_king_of_court_prepare_ingame": 36},
    },
    {
        "source": "src/xbox360/title_server_logout.c",
        "object": "title_server_logout.obj",
        "symbols": {"ts4_script_title_server_logout": 104},
    },
    {
        "source": "src/xbox360/tsu_unload_profile.c",
        "object": "tsu_unload_profile.obj",
        "symbols": {"tsu_unload_profile": 28},
    },
    {
        "source": "src/xbox360/tsu_load_profile.c",
        "object": "tsu_load_profile.obj",
        "symbols": {"tsu_load_profile": 176},
    },
    {
        "source": "src/xbox360/tsu_update_profile.c",
        "object": "tsu_update_profile.obj",
        "symbols": {"tsu_update_profile": 176},
    },
    {
        "source": "src/xbox360/title_patch.c",
        "object": "title_patch.obj",
        "symbols": {"ts4_script_title_server_get_patch": 56},
    },
    {
        "source": "src/xbox360/tsu_forfeit_in_lobby.c",
        "object": "tsu_forfeit_in_lobby.obj",
        "symbols": {"tsu_forfeit_in_lobby": 56},
    },
)


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for block in iter(lambda: handle.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def run(command: list[str]) -> None:
    print("+", " ".join(command))
    subprocess.run(command, cwd=ROOT, check=True)


def checked_file(path: Path, description: str) -> Path:
    resolved = path.expanduser().resolve()
    if not resolved.is_file():
        raise SystemExit(f"missing {description}: {resolved}")
    return resolved


def write_jeff_config(
    path: Path, xex: Path, symbols: Path, splits: Path, quick: bool
) -> None:
    options = ""
    if quick:
        options = (
            "quick_analysis: true\n"
            "symbols_known: true\n"
            "detect_objects: false\n"
            "detect_strings: false\n"
        )
    path.write_text(
        f"object: {json.dumps(str(xex))}\n"
        f"symbols: {json.dumps(str(symbols))}\n"
        f"splits: {json.dumps(str(splits))}\n"
        "write_asm: false\n"
        f"{options}",
        encoding="utf-8",
    )


def resolve_generated(path: str) -> Path:
    generated = Path(path)
    return generated if generated.is_absolute() else ROOT / generated


def objdiff_config(split_config: dict, rebuilt_by_source: dict[str, Path]) -> dict:
    units = []
    for unit in split_config["units"]:
        name = unit["name"]
        entry = {
            "name": f"Swing_DLL/{name}",
            "target_path": str(resolve_generated(unit["object"])),
            "metadata": {
                "auto_generated": unit["autogenerated"],
                "progress_categories": ["game"],
            },
        }
        rebuilt = rebuilt_by_source.get(name)
        if rebuilt is not None:
            entry["base_path"] = str(rebuilt)
            entry["metadata"].update(
                {
                    "complete": True,
                    "source_path": name,
                }
            )
        units.append(entry)
    return {
        "min_version": "2.0.0-beta.5",
        "build_target": False,
        "units": units,
        "progress_categories": [{"id": "game", "name": "Game Code"}],
    }


def verify_report(report: dict) -> None:
    expected = {
        symbol: size
        for unit in MATCHING_UNITS
        for symbol, size in unit["symbols"].items()
    }
    found = {
        function["name"]: function
        for unit in report.get("units", [])
        for function in unit.get("functions", [])
        if function.get("name") in expected
    }
    if found.keys() != expected.keys():
        missing = sorted(expected.keys() - found.keys())
        raise SystemExit(f"missing matching results: {', '.join(missing)}")
    for symbol, size in expected.items():
        function = found[symbol]
        if function.get("size") != str(size):
            raise SystemExit(f"unexpected {symbol} size: {function.get('size')}")
        if function.get("fuzzy_match_percent") != 100.0:
            raise SystemExit(
                f"{symbol} is not a perfect match: "
                f"{function.get('fuzzy_match_percent')}%"
            )


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--xex", type=Path, default=ROOT / "orig" / VERSION / MODULE)
    parser.add_argument("--jeff", type=Path, required=True)
    parser.add_argument("--compiler-dir", type=Path, required=True)
    parser.add_argument("--wrapper", type=Path, required=True)
    parser.add_argument("--objdiff", type=Path, required=True)
    parser.add_argument("--work-dir", type=Path, default=ROOT / "work" / "matching")
    parser.add_argument("--fresh-analysis", action="store_true")
    parser.add_argument("--publish-report", type=Path)
    args = parser.parse_args()

    xex = checked_file(args.xex, MODULE)
    jeff = checked_file(args.jeff, "patched Jeff executable")
    wrapper = checked_file(args.wrapper, "Windows executable wrapper")
    objdiff = checked_file(args.objdiff, "objdiff-cli")
    compiler = checked_file(args.compiler_dir / "cl.exe", "Xbox 360 cl.exe")

    target = json.loads((ROOT / "config" / "target.json").read_text())
    expected_hash = target["modules"][MODULE]
    actual_hash = sha256(xex)
    if actual_hash != expected_hash:
        raise SystemExit(
            f"wrong {MODULE} SHA-256: expected {expected_hash}, got {actual_hash}"
        )

    work_dir = args.work_dir.expanduser().resolve()
    analysis_dir = work_dir / "analysis"
    split_dir = work_dir / "split"
    rebuilt_dir = work_dir / "rebuilt"
    project_dir = work_dir / "objdiff-project"
    for directory in (analysis_dir, split_dir, rebuilt_dir, project_dir):
        directory.mkdir(parents=True, exist_ok=True)

    symbols = analysis_dir / "symbols.txt"
    splits = analysis_dir / "splits.txt"
    if args.fresh_analysis or not symbols.is_file():
        shutil.copyfile(ROOT / "config" / VERSION / "symbols.seed.txt", symbols)
    shutil.copyfile(ROOT / "config" / VERSION / "splits.txt", splits)

    jeff_config = analysis_dir / "config.yml"
    quick = symbols.stat().st_size > (
        ROOT / "config" / VERSION / "symbols.seed.txt"
    ).stat().st_size
    write_jeff_config(jeff_config, xex, symbols, splits, quick)
    run([str(jeff), "xex", "split", str(jeff_config), str(split_dir)])

    rebuilt_by_source = {}
    for unit in MATCHING_UNITS:
        source = unit["source"]
        rebuilt = rebuilt_dir / unit["object"]
        rebuilt_by_source[source] = rebuilt
        output_arg = f"/Fo{rebuilt.relative_to(ROOT)}"
        run(
            [
                str(wrapper),
                str(compiler),
                "/nologo",
                "/c",
                "/O2",
                "/Oi",
                *unit.get("extra_flags", []),
                output_arg,
                source,
            ]
        )

    split_config = json.loads((split_dir / "config.json").read_text())
    project = objdiff_config(split_config, rebuilt_by_source)
    (project_dir / "objdiff.json").write_text(
        json.dumps(project, indent=2) + "\n", encoding="utf-8"
    )
    report_path = project_dir / "report.json"
    run(
        [
            str(objdiff),
            "report",
            "generate",
            "-p",
            str(project_dir),
            "-o",
            str(report_path),
            "-f",
            "json-pretty",
        ]
    )
    report = json.loads(report_path.read_text())
    verify_report(report)
    report_path.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")

    if args.publish_report:
        publish_path = args.publish_report.expanduser().resolve()
        publish_path.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(report_path, publish_path)
        print(f"Published report: {publish_path}")

    measures = report["measures"]
    print(
        f"Matched {measures['matched_functions']} functions: "
        f"{measures['matched_code']}/{measures['total_code']} code bytes "
        f"({measures['matched_code_percent']:.8f}%)"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
