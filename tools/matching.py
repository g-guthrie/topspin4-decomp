#!/usr/bin/env python3
"""Build and measure the reviewed Xbox 360 matching translation units."""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import shutil
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
VERSION = "54540859"
MODULE = "Swing_DLL.xex"
MATCHING_UNITS = (
    {
        "source": "src/xbox360/runtime_dispatch_slots_3c_4c.c",
        "object": "runtime_dispatch_slots_3c_4c.obj",
        "symbols": {
            "ts4_runtime_type_code_none": 8,
            "ts4_runtime_dispatch_slot_3c": 16,
            "ts4_runtime_dispatch_slot_4c": 16,
        },
    },
    {
        "source": "src/xbox360/runtime_type_codes_21_26.c",
        "object": "runtime_type_codes_21_26.obj",
        "symbols": {
            "ts4_runtime_type_code_21": 8,
            "ts4_runtime_type_code_22": 8,
            "ts4_runtime_type_code_23": 8,
            "ts4_runtime_type_code_24": 8,
            "ts4_runtime_type_code_25": 8,
            "ts4_runtime_type_code_26": 8,
        },
    },
    {
        "source": "src/xbox360/runtime_type_codes_12_1f.c",
        "object": "runtime_type_codes_12_1f.obj",
        "symbols": {
            "ts4_runtime_type_code_12": 8,
            "ts4_runtime_type_code_13": 8,
            "ts4_runtime_type_code_15": 8,
            "ts4_runtime_type_code_16": 8,
            "ts4_runtime_type_code_17": 8,
            "ts4_runtime_type_code_18": 8,
            "ts4_runtime_type_code_19": 8,
            "ts4_runtime_type_code_1a": 8,
            "ts4_runtime_type_code_1c": 8,
            "ts4_runtime_type_code_1d": 8,
            "ts4_runtime_type_code_1e": 8,
            "ts4_runtime_type_code_1f": 8,
        },
    },
    {
        "source": "src/xbox360/runtime_type_code_27.c",
        "object": "runtime_type_code_27.obj",
        "symbols": {"ts4_runtime_type_code_27": 8},
    },
    {
        "source": "src/xbox360/runtime_type_code_28.c",
        "object": "runtime_type_code_28.obj",
        "symbols": {"ts4_runtime_type_code_28": 8},
    },
    {
        "source": "src/xbox360/runtime_type_codes_05_0b.c",
        "object": "runtime_type_codes_05_0b.obj",
        "symbols": {
            "ts4_runtime_type_code_05": 8,
            "ts4_runtime_type_code_06": 8,
            "ts4_runtime_type_code_07": 8,
            "ts4_runtime_type_code_09": 8,
            "ts4_runtime_type_code_0a": 8,
            "ts4_runtime_type_code_0b": 8,
        },
    },
    {
        "source": "src/xbox360/runtime_type_code_400.c",
        "object": "runtime_type_code_400.obj",
        "symbols": {"ts4_runtime_type_code_400": 8},
    },
    {
        "source": "src/xbox360/runtime_dispatch_slot_38.c",
        "object": "runtime_dispatch_slot_38.obj",
        "symbols": {"ts4_runtime_dispatch_slot_38": 16},
    },
    {
        "source": "src/xbox360/runtime_type_code_fe.c",
        "object": "runtime_type_code_fe.obj",
        "symbols": {"ts4_runtime_type_code_fe": 8},
    },
    {
        "source": "src/xbox360/runtime_type_codes_2e_31.c",
        "object": "runtime_type_codes_2e_31.obj",
        "symbols": {
            "ts4_runtime_type_code_2e": 8,
            "ts4_runtime_type_code_2f": 8,
            "ts4_runtime_type_code_31": 8,
        },
    },
    {
        "source": "src/xbox360/runtime_type_code_4b0.c",
        "object": "runtime_type_code_4b0.obj",
        "symbols": {"ts4_runtime_type_code_4b0": 8},
    },
    {
        "source": "src/xbox360/runtime_record_accessors_20.c",
        "object": "runtime_record_accessors_20.obj",
        "symbols": {
            "ts4_runtime_record_get_word_324": 8,
            "ts4_runtime_process_subrecord_20": 8,
            "ts4_runtime_record_get_word_620": 8,
        },
    },
    {
        "source": "src/xbox360/runtime_record_accessors_1c.c",
        "object": "runtime_record_accessors_1c.obj",
        "symbols": {
            "ts4_runtime_process_subrecord_1c": 8,
            "ts4_runtime_record_get_word_61c": 8,
        },
    },
    {
        "source": "src/xbox360/runtime_type_codes_34_42.c",
        "object": "runtime_type_codes_34_42.obj",
        "symbols": {
            "ts4_runtime_type_code_34": 8,
            "ts4_runtime_type_code_35": 8,
            "ts4_runtime_type_code_36": 8,
            "ts4_runtime_type_code_37": 8,
            "ts4_runtime_type_code_38": 8,
            "ts4_runtime_type_code_39": 8,
            "ts4_runtime_type_code_3a": 8,
            "ts4_runtime_type_code_3b": 8,
            "ts4_runtime_type_code_3c": 8,
            "ts4_runtime_type_code_3d": 8,
            "ts4_runtime_type_code_3e": 8,
            "ts4_runtime_type_code_47": 8,
            "ts4_runtime_type_code_3f": 8,
            "ts4_runtime_type_code_42": 8,
        },
    },
    {
        "source": "src/xbox360/runtime_type_codes_41_4a.c",
        "object": "runtime_type_codes_41_4a.obj",
        "symbols": {
            "ts4_runtime_type_code_43": 8,
            "ts4_runtime_type_code_44": 8,
            "ts4_runtime_type_code_45": 8,
            "ts4_runtime_type_code_41": 8,
            "ts4_runtime_type_code_46": 8,
            "ts4_runtime_type_code_48": 8,
            "ts4_runtime_type_code_49": 8,
            "ts4_runtime_type_code_4a": 8,
        },
    },
    {
        "source": "src/xbox360/runtime_type_code_80.c",
        "object": "runtime_type_code_80.obj",
        "symbols": {"ts4_runtime_type_code_80": 8},
    },
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
        "source": "src/xbox360/initialize_netdb_stat_record.c",
        "object": "initialize_netdb_stat_record.obj",
        "symbols": {"ts4_initialize_netdb_stat_record": 136},
    },
    {
        "source": "src/xbox360/session_stats_init.c",
        "object": "session_stats_init.obj",
        "symbols": {"ts4_session_stats_init": 92},
    },
    {
        "source": "src/xbox360/clear_netdb_owned_record.c",
        "object": "clear_netdb_owned_record.obj",
        "symbols": {"ts4_clear_netdb_owned_record": 64},
    },
    {
        "source": "src/xbox360/initialize_netdb_extended_record.c",
        "object": "initialize_netdb_extended_record.obj",
        "symbols": {"ts4_initialize_netdb_extended_record": 96},
    },
    {
        "source": "src/xbox360/netdb_value_at_most_eight.c",
        "object": "netdb_value_at_most_eight.obj",
        "symbols": {"ts4_netdb_value_at_most_eight": 52},
    },
    {
        "source": "src/xbox360/netdb_destroy_variant_a.c",
        "object": "netdb_destroy_variant_a.obj",
        "symbols": {"ts4_netdb_destroy_variant_a": 72},
    },
    {
        "source": "src/xbox360/netdb_destroy_variant_b.c",
        "object": "netdb_destroy_variant_b.obj",
        "symbols": {"ts4_netdb_destroy_variant_b": 72},
    },
    {
        "source": "src/xbox360/netdb_release_owned_list.c",
        "object": "netdb_release_owned_list.obj",
        "symbols": {"ts4_netdb_release_owned_list": 108},
    },
    {
        "source": "src/xbox360/netdb_allocate_98.c",
        "object": "netdb_allocate_98.obj",
        "symbols": {"ts4_netdb_allocate_98": 96},
    },
    {
        "source": "src/xbox360/netdb_allocate_94.c",
        "object": "netdb_allocate_94.obj",
        "symbols": {"ts4_netdb_allocate_94": 96},
    },
    {
        "source": "src/xbox360/assign_text_from_c_string.c",
        "object": "assign_text_from_c_string.obj",
        "symbols": {"ts4_assign_text_from_c_string": 100},
    },
    {
        "source": "src/xbox360/clone_byte_with_object_context.c",
        "object": "clone_byte_with_object_context.obj",
        "symbols": {"ts4_clone_byte_with_object_context": 84},
    },
    {
        "source": "src/xbox360/min_u32.c",
        "object": "min_u32.obj",
        "symbols": {"ts4_min_u32": 16},
    },
    {
        "source": "src/xbox360/create_3ac_object.c",
        "object": "create_3ac_object.obj",
        "symbols": {"ts4_create_3ac_object": 108},
    },
    {
        "source": "src/xbox360/copy_block94.c",
        "object": "copy_block94.obj",
        "symbols": {"ts4_copy_block94": 108},
    },
    {
        "source": "src/xbox360/set_parsed_values.c",
        "object": "set_parsed_values.obj",
        "symbols": {
            "ts4_set_parsed_i64_if_changed": 92,
            "ts4_set_parsed_u32_if_changed": 100,
        },
    },
    {
        "source": "src/xbox360/destroy_object_variants.c",
        "object": "destroy_object_variants.obj",
        "symbols": {
            "ts4_destroy_variant_6b74": 92,
            "ts4_destroy_variant_6bc0": 92,
        },
    },
    {
        "source": "src/xbox360/runtime_forwarders.c",
        "object": "runtime_forwarders.obj",
        "symbols": {
            "ts4_query_system_time": 4,
            "ts4_forward_record_status": 4,
            "ts4_forward_runtime_b3360": 4,
            "ts4_forward_runtime_8bee8": 4,
        },
    },
    {
        "source": "src/xbox360/create_runtime_object.c",
        "object": "create_runtime_object.obj",
        "symbols": {"ts4_create_container_factory": 88},
    },
    {
        "source": "src/xbox360/destroy_polymorphic_span.c",
        "object": "destroy_polymorphic_span.obj",
        "symbols": {"ts4_destroy_polymorphic_value_range": 96},
    },
    {
        "source": "src/xbox360/create_container_factory_alias.c",
        "object": "create_container_factory_alias.obj",
        "symbols": {"ts4_create_container_factory_alias": 4},
    },
    {
        "source": "src/xbox360/create_runtime_object_20.c",
        "object": "create_runtime_object_20.obj",
        "symbols": {"ts4_create_runtime_object_20": 88},
    },
    {
        "source": "src/xbox360/container_factory_wrappers.c",
        "object": "container_factory_wrappers.obj",
        "symbols": {
            "ts4_create_runtime_object_28_pool2": 88,
            "ts4_create_runtime_object_28_pool0": 88,
            "ts4_create_runtime_object_54_pool2": 88,
            "ts4_create_runtime_object_54_pool0": 88,
            "ts4_create_runtime_object_80_pool2": 88,
            "ts4_create_runtime_object_80_pool0": 88,
            "ts4_create_runtime_object_54_alt_pool0": 88,
            "ts4_create_runtime_object_20_pool0": 88,
        },
    },
    {
        "source": "src/xbox360/span28_append.c",
        "object": "span28_append.obj",
        "symbols": {"ts4_span28_append": 88},
    },
    {
        "source": "src/xbox360/insert_sorted_node.c",
        "object": "insert_sorted_node.obj",
        "extra_flags": ["/O1"],
        "symbols": {"ts4_insert_sorted_node": 112},
    },
    {
        "source": "src/xbox360/consume_to_delimiter.c",
        "object": "consume_to_delimiter.obj",
        "extra_flags": ["/O1"],
        "symbols": {"ts4_consume_to_delimiter": 76},
    },
    {
        "source": "src/xbox360/increment_shared_refcount.c",
        "object": "increment_shared_refcount.obj",
        "symbols": {"ts4_increment_shared_refcount": 84},
    },
    {
        "source": "src/xbox360/decrement_shared_refcount.c",
        "object": "decrement_shared_refcount.obj",
        "extra_flags": ["/O1"],
        "symbols": {"ts4_decrement_shared_refcount": 88},
    },
    {
        "source": "src/xbox360/find_runtime_entry_payload.c",
        "object": "find_runtime_entry_payload.obj",
        "extra_flags": ["/O1"],
        "symbols": {"ts4_find_runtime_entry_payload": 168},
    },
    {
        "source": "src/xbox360/runtime_small_helpers.c",
        "object": "runtime_small_helpers.obj",
        "symbols": {
            "ts4_get_loaded_command_line": 12,
            "ts4_call_runtime_a1e0": 4,
            "ts4_call_runtime_2890": 12,
            "ts4_set_four_word_record": 28,
            "ts4_call_runtime_2610": 4,
        },
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
        "source": "src/xbox360/span16_append.c",
        "object": "span16_append.obj",
        "symbols": {"ts4_span16_append": 88},
    },
    {
        "source": "src/xbox360/resume_thread.c",
        "object": "resume_thread.obj",
        "extra_flags": ["/O1"],
        "symbols": {"ts4_resume_thread": 60},
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
        "source": "src/xbox360/tsu_reset_friends_leaderboard.c",
        "object": "tsu_reset_friends_leaderboard.obj",
        "symbols": {"tsu_reset_friends_leaderboard": 80},
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
        "source": "src/xbox360/tsu_debug_ind_dec_lobby_timer.c",
        "object": "tsu_debug_ind_dec_lobby_timer.obj",
        "extra_flags": ["/GS-"],
        "symbols": {"tsu_debug_ind_dec_lobby_timer": 292},
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
        "source": "src/xbox360/tsu_fill_friends_leaderboard.c",
        "object": "tsu_fill_friends_leaderboard.obj",
        "symbols": {"tsu_fill_friends_leaderboard": 260},
    },
    {
        "source": "src/xbox360/tsu_get_profile_summaries.c",
        "object": "tsu_get_profile_summaries.obj",
        "symbols": {"tsu_get_profile_summaries": 236},
    },
    {
        "source": "src/xbox360/tsu_init_friends_leaderboard.c",
        "object": "tsu_init_friends_leaderboard.obj",
        "extra_flags": ["/GS-", "/GR-", "/EHs-c-"],
        "symbols": {"tsu_init_friends_leaderboard": 544},
    },
    {
        "source": "src/xbox360/tsu_read_stats_around_user.c",
        "object": "tsu_read_stats_around_user.obj",
        "extra_flags": ["/GS-", "/GR-", "/EHs-c-"],
        "symbols": {"tsu_read_stats_around_user": 640},
    },
    {
        "source": "src/xbox360/tsu_read_stats_by_rank.c",
        "object": "tsu_read_stats_by_rank.obj",
        "extra_flags": ["/GS-", "/GR-", "/EHs-c-"],
        "symbols": {"tsu_read_stats_by_rank": 584},
    },
    {
        "source": "src/xbox360/tsu_update_created_player_stats.c",
        "object": "tsu_update_created_player_stats.obj",
        "extra_flags": ["/GS-"],
        "symbols": {"tsu_update_created_player_stats": 52},
    },
    {
        "source": "src/xbox360/tsu_update_player_rank.c",
        "object": "tsu_update_player_rank.obj",
        "extra_flags": ["/GS-"],
        "symbols": {"tsu_update_player_rank": 176},
    },
    {
        "source": "src/xbox360/tsu_report_event.c",
        "object": "tsu_report_event.obj",
        "extra_flags": ["/GS-", "/GR-", "/EHs-c-"],
        "symbols": {"ts4_script_tsu_report_event": 72},
    },
    {
        "source": "src/xbox360/tsu_profile_service_reset.c",
        "object": "tsu_profile_service_reset.obj",
        "extra_flags": ["/GS-", "/GR-", "/EHs-c-"],
        "symbols": {"ts4_script_tsu_profile_service_reset": 48},
    },
    {
        "source": "src/xbox360/tsu_notify_object.c",
        "object": "tsu_notify_object.obj",
        "extra_flags": ["/GS-", "/GR-", "/EHs-c-"],
        "symbols": {"ts4_script_tsu_notify_object": 44},
    },
    {
        "source": "src/xbox360/tsu_destroy_owned_object.c",
        "object": "tsu_destroy_owned_object.obj",
        "extra_flags": ["/GS-", "/GR-", "/EHs-c-"],
        "symbols": {"ts4_tsu_destroy_owned_object": 60},
    },
    {
        "source": "src/xbox360/tsu_format_and_assign.c",
        "object": "tsu_format_and_assign.obj",
        "extra_flags": ["/GS-", "/GR-", "/EHs-c-"],
        "symbols": {"ts4_tsu_format_and_assign": 84},
    },
    {
        "source": "src/xbox360/tsu_enable_object.c",
        "object": "tsu_enable_object.obj",
        "symbols": {"ts4_tsu_enable_object": 56},
    },
    {
        "source": "src/xbox360/tsu_disable_object.c",
        "object": "tsu_disable_object.obj",
        "symbols": {"ts4_tsu_disable_object": 56},
    },
    {
        "source": "src/xbox360/tsu_cleanup_object.c",
        "object": "tsu_cleanup_object.obj",
        "symbols": {"ts4_tsu_cleanup_object": 92},
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
        "source": "src/xbox360/pro_challenge_save_profile.c",
        "object": "pro_challenge_save_profile.obj",
        "symbols": {"ts4_script_pro_challenge_save_profile": 172},
    },
    {
        "source": "src/xbox360/pro_challenge_load_profile.c",
        "object": "pro_challenge_load_profile.obj",
        "symbols": {"ts4_script_pro_challenge_load_profile": 172},
    },
    {
        "source": "src/xbox360/tsu_update_profile.c",
        "object": "tsu_update_profile.obj",
        "symbols": {"tsu_update_profile": 176},
    },
    {
        "source": "src/xbox360/tsu_save_profile.c",
        "object": "tsu_save_profile.obj",
        "symbols": {"tsu_save_profile": 208},
    },
    {
        "source": "src/xbox360/tsu_write_profile_summaries.c",
        "object": "tsu_write_profile_summaries.obj",
        "symbols": {"tsu_write_profile_summaries": 160},
    },
    {
        "source": "src/xbox360/tsu_load_profile_summaries.c",
        "object": "tsu_load_profile_summaries.obj",
        "symbols": {"tsu_load_profile_summaries": 160},
    },
    {
        "source": "src/xbox360/profile_internal_bd68.c",
        "object": "profile_internal_bd68.obj",
        "symbols": {"ts4_script_profile_internal_lookup": 160},
    },
    {
        "source": "src/xbox360/profile_internal_bff8.c",
        "object": "profile_internal_bff8.obj",
        "symbols": {"ts4_script_profile_internal_activate": 200},
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
    {
        "source": "src/xbox360/create_zeroed_triplet.c",
        "object": "create_zeroed_triplet.obj",
        "symbols": {"ts4_create_zeroed_triplet": 100},
    },
    {
        "source": "src/xbox360/allocate_zeroed_triplets.c",
        "object": "allocate_zeroed_triplets.obj",
        "symbols": {"ts4_allocate_zeroed_triplets": 152},
    },
    {
        "source": "src/xbox360/title_server_small_batch.c",
        "object": "title_server_small_batch.obj",
        "symbols": {
            "ts4_script_player_select_unload_all_created_players": 44,
            "ts4_script_end_of_point_check_coach_objectives": 44,
            "ts4_script_apply_profile_options": 48,
            "ts4_script_start_practice_ground": 48,
            "ts4_script_init_main_camera": 44,
        },
    },
    {
        "source": "src/xbox360/script_callback_batch_b.c",
        "object": "script_callback_batch_b.obj",
        "symbols": {
            "ts4_script_are_there_rewards_for_event_recap": 4,
            "ts4_script_match_start_reset_rewards": 36,
            "ts4_script_init_practice_ground": 44,
            "ts4_script_reset_all_free_form_sliders": 36,
            "ts4_script_restore_all_free_form_sliders_step2": 44,
            "ts4_script_show_hot_spots": 44,
            "ts4_script_hide_hot_spots": 44,
        },
    },
    {
        "source": "src/xbox360/script_callback_batch_c.c",
        "object": "script_callback_batch_c.obj",
        "symbols": {
            "ts4_script_king_of_the_court_wait_for_players_loading": 44,
            "ts4_script_king_of_the_court_prepare_next_match": 48,
            "ts4_script_minigame_update_camera": 48,
            "ts4_script_king_of_the_court_start_match": 48,
            "ts4_script_top_spin_school_save_progress": 48,
            "ts4_script_end_of_match_check_coach_objectives": 44,
            "ts4_script_enter_practice_ground": 48,
            "ts4_script_facial_stop_anim": 36,
        },
    },
    {
        "source": "src/xbox360/script_callback_batch_d.c",
        "object": "script_callback_batch_d.obj",
        "symbols": {
            "ts4_script_exit_locker_room": 80,
            "ts4_script_check_dlc_ok": 140,
            "ts4_script_set_furniture_visibility": 96,
            "ts4_script_set_free_form_replay_visibility": 84,
        },
    },
    {
        "source": "src/xbox360/script_notify_rich_presence_by_part.c",
        "object": "script_notify_rich_presence_by_part.obj",
        "symbols": {"ts4_script_notify_rich_presence_by_part": 120},
    },
    {
        "source": "src/xbox360/script_callback_batch_f.c",
        "object": "script_callback_batch_f.obj",
        "symbols": {
            "ts4_script_choose_in_game_camera": 44,
            "ts4_script_unload_all_player_portraits": 36,
            "ts4_script_unload_all_temporary_player_portraits": 36,
            "ts4_script_unload_all_players_player_creator": 52,
            "ts4_script_debug_reset_all_unlocks": 44,
            "ts4_script_configure_pc_for_player_area": 52,
            "ts4_script_configure_pc_for_locker_room": 52,
            "ts4_script_unload_all_outfits": 44,
            "ts4_script_unload_all_players_in_game": 56,
        },
    },
    {
        "source": "src/xbox360/compact_owned_span16.c",
        "object": "compact_owned_span16.obj",
        "symbols": {"ts4_compact_owned_span16": 132},
    },
    {
        "source": "src/xbox360/advance_bit_cursor_to_location.c",
        "object": "advance_bit_cursor_to_location.obj",
        "symbols": {"ts4_advance_bit_cursor_to_location": 88},
    },
    {
        "source": "src/xbox360/destroy_owned_container.c",
        "object": "destroy_owned_container.obj",
        "symbols": {"ts4_destroy_owned_container": 92},
    },
    {
        "source": "src/xbox360/erase_value16_from_span.c",
        "object": "erase_value16_from_span.obj",
        "symbols": {"ts4_erase_value16_from_span": 104},
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


def compiler_output_arg(rebuilt: Path) -> str:
    """Return an MSVC output argument that works inside or outside the checkout."""
    return f"/Fo{os.path.relpath(rebuilt, ROOT)}"


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

    # Keep an in-repository symlink unresolved so large transient analyses can
    # live on local scratch storage instead of an offloading cloud filesystem.
    work_dir = args.work_dir.expanduser().absolute()
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
        output_arg = compiler_output_arg(rebuilt)
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
