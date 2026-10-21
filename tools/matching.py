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
        "source": "src/xbox360/runtime_record_words_14_1c.c",
        "object": "runtime_record_words_14_1c.obj",
        "symbols": {
            "ts4_runtime_record_get_word_14": 8,
            "ts4_runtime_record_get_word_1c": 8,
        },
    },
    {
        "source": "src/xbox360/runtime_record_words_90_98.c",
        "object": "runtime_record_words_90_98.obj",
        "symbols": {
            "ts4_runtime_record_get_word_90": 8,
            "ts4_runtime_record_get_word_94": 8,
            "ts4_runtime_record_get_word_98": 8,
        },
    },
    {
        "source": "src/xbox360/runtime_adjusted_record_forwarders.c",
        "object": "runtime_adjusted_record_forwarders.obj",
        "symbols": {
            "ts4_runtime_forward_record_minus_1c_to_98090": 8,
            "ts4_runtime_forward_record_minus_20_to_98048": 8,
            "ts4_runtime_forward_record_minus_1c_to_98000": 8,
            "ts4_runtime_forward_record_minus_20_to_51810": 8,
            "ts4_runtime_forward_record_minus_1c_to_51878": 8,
            "ts4_runtime_forward_record_minus_1c_to_51cd0": 8,
        },
    },
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
        "source": "src/xbox360/parse_u8_decimal_if_changed.c",
        "object": "parse_u8_decimal_if_changed.obj",
        "symbols": {"ts4_parse_u8_decimal_if_changed": 120},
    },
    {
        "source": "src/xbox360/copy_offset_span12.c",
        "object": "copy_offset_span12.obj",
        "symbols": {"ts4_copy_offset_span12": 144},
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
        "source": "src/xbox360/script_callback_batch_g.c",
        "object": "script_callback_batch_g.obj",
        "symbols": {
            "ts4_script_dll_init_master_pad": 44,
            "ts4_script_debug_unlock_all": 44,
            "ts4_script_end_of_match_apply_coach_progress": 44,
            "ts4_script_start_loading": 52,
            "ts4_script_pop_me": 56,
        },
    },
    {
        "source": "src/xbox360/script_callback_batch_h.c",
        "object": "script_callback_batch_h.obj",
        "symbols": {"ts4_script_change_part": 148},
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
    {
        "source": "src/xbox360/matched/constant_return_88478b48.c",
        "object": "constant_return_88478b48.obj",
        "symbols": {"fn_88478B48": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_88479620.c",
        "object": "constant_return_88479620.obj",
        "symbols": {"fn_88479620": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_88479f30.c",
        "object": "constant_return_88479f30.obj",
        "symbols": {"fn_88479F30": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_8847b008.c",
        "object": "constant_return_8847b008.obj",
        "symbols": {"fn_8847B008": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_8847b0e8.c",
        "object": "constant_return_8847b0e8.obj",
        "symbols": {"fn_8847B0E8": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_8847b648.c",
        "object": "constant_return_8847b648.obj",
        "symbols": {"fn_8847B648": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_8847ca58.c",
        "object": "constant_return_8847ca58.obj",
        "symbols": {"fn_8847CA58": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_8847d200.c",
        "object": "constant_return_8847d200.obj",
        "symbols": {"fn_8847D200": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_8847d7e8.c",
        "object": "constant_return_8847d7e8.obj",
        "symbols": {"fn_8847D7E8": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_8847e8e8.c",
        "object": "constant_return_8847e8e8.obj",
        "symbols": {"fn_8847E8E8": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_8847ff08.c",
        "object": "constant_return_8847ff08.obj",
        "symbols": {"fn_8847FF08": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_88480ae8.c",
        "object": "constant_return_88480ae8.obj",
        "symbols": {"fn_88480AE8": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_88480eb8.c",
        "object": "constant_return_88480eb8.obj",
        "symbols": {"fn_88480EB8": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_88481ed0.c",
        "object": "constant_return_88481ed0.obj",
        "symbols": {"fn_88481ED0": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_88482388.c",
        "object": "constant_return_88482388.obj",
        "symbols": {"fn_88482388": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_88482778.c",
        "object": "constant_return_88482778.obj",
        "symbols": {"fn_88482778": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_88482b18.c",
        "object": "constant_return_88482b18.obj",
        "symbols": {"fn_88482B18": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_88482c20.c",
        "object": "constant_return_88482c20.obj",
        "symbols": {"fn_88482C20": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_88485860.c",
        "object": "constant_return_88485860.obj",
        "symbols": {"fn_88485860": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_88485e70.c",
        "object": "constant_return_88485e70.obj",
        "symbols": {"fn_88485E70": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_884864c0.c",
        "object": "constant_return_884864c0.obj",
        "symbols": {"fn_884864C0": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_884866d8.c",
        "object": "constant_return_884866d8.obj",
        "symbols": {"fn_884866D8": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_8849f040.c",
        "object": "constant_return_8849f040.obj",
        "symbols": {"fn_8849F040": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_8849f058.c",
        "object": "constant_return_8849f058.obj",
        "symbols": {"fn_8849F058": 8},
    },
    {
        "source": "src/xbox360/matched/constant_return_884a7308.c",
        "object": "constant_return_884a7308.obj",
        "symbols": {"fn_884A7308": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_881d6bf8.c",
        "object": "record_word_getter_881d6bf8.obj",
        "symbols": {"fn_881D6BF8": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_881d8758.c",
        "object": "record_word_getter_881d8758.obj",
        "symbols": {"fn_881D8758": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_88207140.c",
        "object": "record_word_getter_88207140.obj",
        "symbols": {"fn_88207140": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_88207148.c",
        "object": "record_word_getter_88207148.obj",
        "symbols": {"fn_88207148": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_88207248.c",
        "object": "record_word_getter_88207248.obj",
        "symbols": {"fn_88207248": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_88207250.c",
        "object": "record_word_getter_88207250.obj",
        "symbols": {"fn_88207250": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_88209310.c",
        "object": "record_word_getter_88209310.obj",
        "symbols": {"fn_88209310": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_88209318.c",
        "object": "record_word_getter_88209318.obj",
        "symbols": {"fn_88209318": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_88279f38.c",
        "object": "record_word_getter_88279f38.obj",
        "symbols": {"fn_88279F38": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_8827d1f0.c",
        "object": "record_word_getter_8827d1f0.obj",
        "symbols": {"fn_8827D1F0": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_8827d278.c",
        "object": "record_word_getter_8827d278.obj",
        "symbols": {"fn_8827D278": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_8827ec90.c",
        "object": "record_word_getter_8827ec90.obj",
        "symbols": {"fn_8827EC90": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_8827eef0.c",
        "object": "record_word_getter_8827eef0.obj",
        "symbols": {"fn_8827EEF0": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_8828c2a8.c",
        "object": "record_word_getter_8828c2a8.obj",
        "symbols": {"fn_8828C2A8": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_8828c350.c",
        "object": "record_word_getter_8828c350.obj",
        "symbols": {"fn_8828C350": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_8828c658.c",
        "object": "record_word_getter_8828c658.obj",
        "symbols": {"fn_8828C658": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_8828c818.c",
        "object": "record_word_getter_8828c818.obj",
        "symbols": {"fn_8828C818": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_8828c858.c",
        "object": "record_word_getter_8828c858.obj",
        "symbols": {"fn_8828C858": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_8828c898.c",
        "object": "record_word_getter_8828c898.obj",
        "symbols": {"fn_8828C898": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_8828c8d8.c",
        "object": "record_word_getter_8828c8d8.obj",
        "symbols": {"fn_8828C8D8": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_8828c918.c",
        "object": "record_word_getter_8828c918.obj",
        "symbols": {"fn_8828C918": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_8828c928.c",
        "object": "record_word_getter_8828c928.obj",
        "symbols": {"fn_8828C928": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_8828ce78.c",
        "object": "record_word_getter_8828ce78.obj",
        "symbols": {"fn_8828CE78": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_8828cf10.c",
        "object": "record_word_getter_8828cf10.obj",
        "symbols": {"fn_8828CF10": 8},
    },
    {
        "source": "src/xbox360/matched/record_word_getter_8828cfa8.c",
        "object": "record_word_getter_8828cfa8.obj",
        "symbols": {"fn_8828CFA8": 8},
    },
    {
        "source": "src/xbox360/matched/runtime_bound_argument_wrappers.c",
        "object": "runtime_bound_argument_wrappers.obj",
        "symbols": {
            "ts4_runtime_call_883c72e0_with_flag": 8,
            "ts4_runtime_call_8862e858_with_zero": 8,
        },
    },
    {
        "source": "src/xbox360/matched/runtime_descriptor_init.c",
        "object": "runtime_descriptor_init.obj",
        "symbols": {"ts4_runtime_fill_record12_8841f080": 84},
    },
    {
        "source": "src/xbox360/matched/runtime_exhibition_scene.c",
        "object": "runtime_exhibition_scene.obj",
        "symbols": {
            "ts4_runtime_refresh_handles_887dc2d0": 100,
            "ts4_runtime_keyed_update_8888a658": 180,
        },
    },
    {
        "source": "src/xbox360/matched/runtime_match_settings.c",
        "object": "runtime_match_settings.obj",
        "symbols": {"ts4_runtime_cast_to_88c4763c_88180da0": 120},
    },
    {
        "source": "src/xbox360/matched/runtime_this_adjustors_minus_4.c",
        "object": "runtime_this_adjustors_minus_4.obj",
        "symbols": {
            "ts4_adjust_minus_4_to_8827fa20": 8,
            "ts4_adjust_minus_4_to_8859fff0": 8,
            "ts4_adjust_minus_4_to_88599fb0": 8,
            "ts4_adjust_minus_4_to_88599fc0": 8,
            "ts4_adjust_minus_4_to_8859a158": 8,
            "ts4_adjust_minus_4_to_8859ffe8": 8,
            "ts4_adjust_minus_4_to_88599fc8": 8,
            "ts4_adjust_minus_4_to_885a02c8": 8,
            "ts4_adjust_minus_4_to_88599fa0": 8,
            "ts4_adjust_minus_4_to_88599fb8": 8,
            "ts4_adjust_minus_4_to_88599fd8": 8,
            "ts4_adjust_minus_4_to_88598ef0": 8,
            "ts4_adjust_minus_4_to_type_code_none": 8,
        },
    },
    {
        "source": "src/xbox360/matched/runtime_vtable_leaves.c",
        "object": "runtime_vtable_leaves.obj",
        "symbols": {
            "ts4_runtime_dispatch_slot_28": 16,
            "ts4_runtime_record_get_word_24c": 8,
            "ts4_runtime_child_14_dispatch_slot_18": 20,
            "ts4_runtime_slot_return_zero_606b10": 8,
            "ts4_runtime_slot_no_op_7efc70": 4,
            "ts4_runtime_slot_no_op_864d18": 4,
        },
    },
    {
        "source": "src/xbox360/matched/script_natives_matchpath.c",
        "object": "script_natives_matchpath.obj",
        "symbols": {
            "ts4_script_tcr_check_storage_capacity": 8,
            "ts4_script_save_all": 8,
            "ts4_script_is_3d_on": 16,
            "ts4_script_is_3d_accessible": 16,
            "ts4_script_is_in_debug_mode": 16,
            "ts4_script_career_init_next_match": 24,
            "ts4_script_force_move_recalibrate": 8,
            "ts4_script_is_move_controller": 8,
            "ts4_script_restart_match_ui": 36,
            "ts4_script_scale_clothes": 8,
            "ts4_script_wait_for_texture_packs": 16,
            "ts4_script_king_of_the_court_restart": 56,
        },
    },
    {
        "source": "src/xbox360/matched/script_family_a01_88786450.c",
        "object": "script_family_a01_88786450.obj",
        "symbols": {"ts4_script_top_outfit_restore_cloth_type": 176},
    },
    {
        "source": "src/xbox360/matched/script_family_a01.c",
        "object": "script_family_a01.obj",
        "symbols": {
            "ts4_script_dlc_unmount_unused_offers": 76,
            "ts4_script_top_outfit_backup_cloth_type": 172,
            "ts4_script_unset_ready_in_lobby": 172,
            "ts4_script_set_ready_in_lobby": 172,
            "ts4_script_dlc_unmount_all_offers": 84,
            "ts4_script_init_anim_setup": 76,
            "ts4_script_load_all_players_in_game": 88,
        },
    },
    {
        "source": "src/xbox360/matched/script_family_b02.c",
        "object": "script_family_b02.obj",
        "symbols": {
            "ts4_script_tcr_save_tournament": 84,
            "ts4_script_enable_move_binding": 84,
            "ts4_script_debug_hot_spots_infos_on_off": 96,
            "ts4_script_core_memory_enable_tracking": 80,
            "ts4_script_restore_hot_spot": 152,
            "ts4_script_is_a_guest_offline": 140,
            "ts4_script_backup_free_form_slider": 152,
            "ts4_script_init_categories": 144,
            "ts4_script_init_outfit_type": 144,
            "ts4_script_inc_and_check_sparring_partner_trainings": 140,
        },
    },
    {
        "source": "src/xbox360/matched/script_family_b03.c",
        "object": "script_family_b03.obj",
        "symbols": {
            "ts4_script_dlc_show_marketplace_ui": 248,
            "ts4_script_store_custom_preset": 256,
            "ts4_script_tsu_set_local_player_in_leaderboard": 328,
            "ts4_script_dlc_use_outfit": 240,
            "ts4_script_move_vertex": 416,
            "ts4_script_pro_challenge_read_stats_by_rank_in_m": 380,
            "ts4_script_pro_challenge_read_stats_by_rank": 380,
            "ts4_script_tsu_read_stats_by_id_in_leaderboards": 428,
            "ts4_script_title_server_login": 276,
            "ts4_script_add_achievement": 248,
            "ts4_script_add_reward_unlock": 336,
        },
    },
    {
        "source": "src/xbox360/matched/script_family_c01.c",
        "object": "script_family_c01.obj",
        "symbols": {
            "ts4_script_cancel_commands": 160,
            "ts4_script_title_server_is_logged_in": 160,
            "ts4_script_dlc_is_user_discovered": 148,
            "ts4_script_data_mining_print_all_player_counters": 160,
            "ts4_script_freeze_main_camera": 96,
            "ts4_script_backup_hot_spot": 152,
            "ts4_script_clear_custom_preset": 152,
            "ts4_script_debug_simulate_match": 112,
            "ts4_script_kick_user": 164,
            "ts4_script_highlight_vertex": 152,
            "ts4_script_reset_vertex": 152,
            "ts4_script_decrease_free_form_slider": 152,
            "ts4_script_increase_free_form_slider": 152,
            "ts4_script_debug_set_easy_achievements": 144,
            "ts4_script_fill_item_infos_ui": 144,
            "ts4_script_init_locker_room": 152,
        },
    },
    {
        "source": "src/xbox360/matched/script_family_c02.c",
        "object": "script_family_c02.obj",
        "symbols": {
            "ts4_script_tcr_check_device_space": 240,
            "ts4_script_show_ui_achievements": 180,
            "ts4_script_is_package_not_ready_to_use": 200,
            "ts4_script_tsu_check_character_change": 188,
            "ts4_script_pro_challenge_get_my_stats": 172,
            "ts4_script_pro_challenge_read_stats_friends": 236,
            "ts4_script_player_created_id_destroy": 240,
            "ts4_script_tcr_set_master_pad_for_invitation": 184,
        },
    },
    {
        "source": "src/xbox360/matched/script_family_d01_887926d8.c",
        "object": "script_family_d01_887926d8.obj",
        "symbols": {"ts4_script_title_server_download_player_info": 328},
    },
    {
        "source": "src/xbox360/matched/script_family_d01.c",
        "object": "script_family_d01.obj",
        "symbols": {
            "ts4_script_saving_new_created_player": 260,
            "ts4_script_set_freeze_clothes": 236,
            "ts4_script_dlc_discovery_user": 308,
            "ts4_script_academy_init_profile": 212,
            "ts4_script_initialize_unlock_list": 280,
        },
    },
    {
        "source": "src/xbox360/matched/script_family_e_bctrl.c",
        "object": "script_family_e_bctrl.obj",
        "symbols": {"ts4_script_stop_sound": 180},
    },
    {
        "source": "src/xbox360/matched/script_family_e01.c",
        "object": "script_family_e01.obj",
        "symbols": {
            "ts4_script_open_hud_player_review_in_lobby": 316,
            "ts4_script_open_hud_player_review": 296,
            "ts4_script_open_hud_friend_request_in_lobby": 316,
            "ts4_script_open_hud_friend_request": 296,
            "ts4_script_open_hud_gamercard_in_lobby": 316,
            "ts4_script_open_hud_gamercard_in_session_list": 304,
            "ts4_script_open_hud_gamercard": 296,
            "ts4_script_top_outfit_save_cloth_type": 424,
            "ts4_script_sports_gear_save_preset_in_dna_outfit": 520,
            "ts4_script_add_reward_quantity": 624,
        },
    },
    {
        "source": "src/xbox360/matched/script_family_f02_8878a758.c",
        "object": "script_family_f02_8878a758.obj",
        "symbols": {"ts4_script_init_free_form_camera": 624},
    },
    {
        "source": "src/xbox360/matched/script_family_pilot.c",
        "object": "script_family_pilot.obj",
        "symbols": {
            "ts4_script_enable_move_calibration": 84,
            "ts4_script_set_player_rotation": 124,
            "ts4_script_is_bissextile": 188,
            "ts4_script_save_hot_spot_in_history": 152,
            "ts4_script_online_sparring_set_difficulty": 184,
            "ts4_script_facial_set_num_players": 144,
        },
    },
    {
        "source": "src/xbox360/matched/byte5_flag_accessors_s10.c",
        "object": "byte5_flag_accessors_s10.obj",
        "symbols": {
            "ts4_object_byte5_bit0_883bab88": 16,
            "ts4_object_byte5_bit1_883bab98": 16,
            "ts4_object_byte5_bit2_883baba8": 16,
        },
    },
    {
        "source": "src/xbox360/matched/constant_returns_s01.c",
        "object": "constant_returns_s01.obj",
        "symbols": {
            "ts4_return_0x50_8831af10": 8,
            "ts4_return_zero_883e63b8": 8,
            "ts4_return_zero_88425300": 8,
        },
    },
    {
        "source": "src/xbox360/matched/constant_returns_e01.c",
        "object": "constant_returns_e01.obj",
        "symbols": {
            "ts4_return_0x10_8821b378": 8,
            "ts4_return_8_8821b420": 8,
            "ts4_return_0x4e_88309a90": 8,
            "ts4_return_0x10_88320828": 8,
            "ts4_return_one_885e6048": 8,
            "ts4_return_one_885f5220": 8,
        },
    },
    {
        "source": "src/xbox360/matched/constant_returns_f01.c",
        "object": "constant_returns_f01.obj",
        "symbols": {
            "fn_88333170": 8,
            "fn_88334940": 8,
            "fn_8834DAC0": 8,
            "fn_88374ED8": 8,
            "fn_883AD0B8": 8,
            "fn_883F7278": 8,
        },
    },
    {
        "source": "src/xbox360/matched/runtime_constant_slot_families.c",
        "object": "runtime_constant_slot_families.obj",
        "symbols": {
            "ts4_runtime_no_op_slot_887EFCA8": 4,
            "ts4_runtime_no_op_slot_887EFCB0": 4,
            "ts4_runtime_no_op_slot_887EFCB8": 4,
            "ts4_runtime_no_op_slot_887EFCC0": 4,
            "ts4_runtime_no_op_slot_887EFCC8": 4,
            "ts4_runtime_no_op_slot_887EFCD0": 4,
            "ts4_runtime_no_op_slot_887EFCD8": 4,
            "ts4_runtime_no_op_slot_888BFE40": 4,
            "ts4_runtime_no_op_slot_88940B08": 4,
            "ts4_runtime_no_op_slot_8899C028": 4,
            "ts4_runtime_no_op_slot_8899C030": 4,
            "ts4_runtime_no_op_slot_8899C038": 4,
        },
    },
    {
        "source": "src/xbox360/matched/leaf_family_s01.c",
        "object": "leaf_family_s01.obj",
        "symbols": {
            "fn_88544DF0": 8,
            "fn_88558D30": 8,
            "fn_88558D38": 8,
            "fn_8859CBB0": 8,
            "fn_8859FFF8": 8,
            "fn_885A02D0": 8,
            "fn_885B9128": 8,
            "fn_885F52E8": 8,
            "fn_885F55B8": 8,
            "fn_885F9A90": 8,
            "fn_885F9B80": 8,
            "fn_885F9C50": 8,
            "fn_885F9CD0": 8,
            "fn_885F9EB8": 8,
            "fn_885FA048": 8,
            "fn_885FA2C0": 8,
            "fn_885FA408": 8,
            "fn_885FA4F0": 8,
            "fn_885FA598": 8,
            "fn_885FA648": 8,
            "fn_885FA728": 8,
            "fn_885FA7E0": 8,
            "fn_885FA878": 8,
            "fn_885FA970": 8,
            "fn_885FA9F8": 8,
            "fn_885FAAE8": 8,
            "fn_885FAB70": 8,
            "fn_885FAC80": 8,
            "fn_885FAD68": 8,
            "fn_885FAF30": 8,
            "fn_885FB0C0": 8,
            "fn_885FB250": 8,
            "fn_885FB2E8": 8,
            "fn_885FB360": 8,
            "fn_885FB3F0": 8,
            "fn_885FB5A0": 8,
            "fn_885FB6B0": 8,
            "fn_885FB7A8": 8,
            "fn_885FB818": 8,
            "fn_88600B70": 8,
            "fn_88601368": 8,
            "fn_886013F8": 8,
            "fn_886014B8": 8,
            "fn_88601570": 8,
            "fn_88601650": 8,
            "fn_886016D0": 8,
            "fn_886017F0": 8,
            "fn_886018B8": 8,
            "fn_88601A88": 8,
            "fn_88601B50": 8,
            "fn_88601BA8": 8,
            "fn_88602BD8": 8,
            "fn_88602C20": 8,
            "fn_88602E00": 8,
            "fn_88602F60": 8,
            "fn_88603100": 8,
            "fn_886031C0": 8,
            "fn_886032E8": 8,
            "fn_88603E38": 8,
            "fn_88603F20": 8,
            "fn_88604418": 8,
            "fn_88605DC8": 8,
            "fn_88605E90": 8,
            "fn_88605E98": 8,
            "fn_88605EA0": 8,
            "fn_88605EA8": 8,
            "fn_88605F80": 8,
            "fn_88606530": 8,
            "fn_88606538": 8,
            "fn_88606570": 8,
            "fn_88606578": 8,
            "fn_886065F0": 8,
            "fn_88606930": 8,
            "fn_88606958": 8,
            "fn_88606968": 8,
            "fn_88606AD8": 8,
            "fn_88606AE0": 8,
            "fn_88606AE8": 8,
            "fn_88606B38": 8,
            "fn_88606BF0": 8,
            "fn_88606BF8": 8,
            "fn_88606C00": 8,
            "fn_88606C10": 8,
            "fn_88606C18": 8,
            "fn_88606CB0": 8,
            "fn_88606CB8": 8,
            "fn_88606EC0": 8,
            "fn_886079D0": 8,
            "fn_88608C88": 8,
            "fn_88639A18": 8,
            "fn_88639DD8": 8,
            "fn_88639DE0": 8,
            "fn_88639E68": 8,
            "fn_88639E70": 8,
            "fn_88639E78": 8,
            "fn_88639E90": 8,
            "fn_88639ED8": 8,
            "fn_88639EE0": 8,
            "fn_88639F80": 8,
            "fn_88639F88": 8,
            "fn_88639F90": 8,
            "fn_88639FA8": 8,
            "fn_8864DFE8": 8,
            "fn_88655190": 8,
            "fn_88655198": 8,
            "fn_886551A0": 8,
            "fn_886551A8": 8,
            "fn_886551B8": 8,
            "fn_88659518": 8,
            "fn_886C3428": 8,
            "fn_886E62B0": 8,
            "fn_886EB140": 8,
            "fn_886EB250": 8,
            "fn_886EB258": 8,
            "fn_886EB3A0": 8,
            "fn_886EBBB8": 8,
            "fn_886EBC00": 8,
            "fn_886EBC08": 8,
            "fn_886EBC10": 8,
            "fn_886EBC18": 8,
            "fn_886EBC28": 8,
            "fn_886EBC30": 8,
            "fn_886EBC48": 8,
            "fn_886EBC58": 8,
            "fn_886EBC60": 8,
            "fn_886EBC68": 8,
            "fn_886EBC70": 8,
            "fn_886EBC78": 8,
            "fn_886EBC80": 8,
            "fn_886EBCA0": 8,
            "fn_886EBD60": 8,
            "fn_886EBD98": 8,
            "fn_886EC070": 8,
            "fn_886ECEA8": 8,
            "fn_887785E0": 8,
            "fn_887785E8": 8,
            "fn_887785F0": 8,
            "fn_887785F8": 8,
            "fn_88778600": 8,
            "fn_88778608": 8,
            "fn_88778610": 8,
            "fn_88778618": 8,
            "fn_88778620": 8,
            "fn_88778628": 8,
            "fn_88778630": 8,
            "fn_88778638": 8,
            "fn_88778640": 8,
            "fn_88778648": 8,
            "fn_88778650": 8,
            "fn_88778660": 8,
            "fn_88778668": 8,
            "fn_88778670": 8,
            "fn_887786D8": 8,
            "fn_887786E0": 8,
            "fn_887786F0": 8,
            "fn_8877A5F8": 8,
            "fn_8877A600": 8,
            "fn_8877A6F8": 8,
            "fn_8877A700": 8,
            "fn_8877A708": 8,
            "fn_8877A768": 8,
            "fn_8877A838": 8,
            "fn_8877A848": 8,
            "fn_8877A850": 8,
            "fn_8877A858": 8,
            "fn_8877A860": 8,
            "fn_8877A868": 8,
            "fn_8877C370": 8,
            "fn_8877C378": 8,
            "fn_8877C380": 8,
            "fn_8877C388": 8,
            "fn_8877C390": 8,
            "fn_887C7660": 8,
            "fn_887CB4F8": 8,
            "fn_887CB500": 8,
            "fn_887CB508": 8,
            "fn_887CD960": 8,
            "fn_887CD968": 8,
            "fn_887CD970": 8,
            "fn_887CD978": 8,
            "fn_887CD980": 8,
            "fn_887CD988": 8,
            "fn_887CD9E8": 8,
            "fn_887CDA50": 8,
            "fn_887CE688": 8,
            "fn_887CF180": 8,
            "fn_887D06C0": 8,
            "fn_887E9448": 8,
            "fn_887E9450": 8,
            "fn_887E9458": 8,
            "fn_887F7140": 8,
            "fn_887F7148": 8,
            "fn_887F7150": 8,
            "fn_887F7158": 8,
            "fn_88802EF0": 8,
            "fn_88802F20": 8,
            "fn_88802F28": 8,
            "fn_88802F30": 8,
            "fn_88802F38": 8,
            "fn_88803068": 8,
            "fn_88813558": 8,
            "fn_8882B398": 8,
            "fn_888327B8": 8,
            "fn_88864AE8": 8,
            "fn_88864AF0": 8,
            "fn_88878DA0": 8,
            "fn_88883DD0": 8,
            "fn_888841A8": 8,
            "fn_88884368": 8,
            "fn_888849C0": 8,
            "fn_8888A5C0": 8,
            "fn_88891788": 8,
            "fn_88894B00": 8,
            "fn_888A09C0": 8,
            "fn_888AD3A0": 8,
            "fn_888AD3C8": 8,
            "fn_888AD3E8": 8,
            "fn_888BFA98": 8,
            "fn_888BFBA8": 8,
            "fn_888BFCF0": 8,
            "fn_888C0098": 8,
            "fn_888C0650": 8,
            "fn_88912B28": 8,
            "fn_88922318": 8,
            "fn_88922328": 8,
            "fn_88922350": 8,
            "fn_889224C8": 8,
            "fn_889224F8": 8,
            "fn_88922500": 8,
            "fn_88922510": 8,
            "fn_88922540": 8,
            "fn_88922548": 8,
            "fn_88922558": 8,
            "fn_88922568": 8,
            "fn_88922570": 8,
            "fn_88922588": 8,
            "fn_88922590": 8,
            "fn_88922598": 8,
            "fn_889225A0": 8,
            "fn_88922840": 8,
            "fn_88922858": 8,
            "fn_88922BB0": 8,
            "fn_889239B0": 8,
            "fn_88930A30": 8,
            "fn_88930A38": 8,
            "fn_88930AD0": 8,
            "fn_88930B08": 8,
            "fn_88930B20": 8,
            "fn_88930B38": 8,
            "fn_88930B50": 8,
            "fn_88930B68": 8,
            "fn_88930B80": 8,
            "fn_88930B98": 8,
            "fn_88930BB0": 8,
            "fn_88930BC8": 8,
            "fn_88930BE0": 8,
            "fn_88930BF8": 8,
            "fn_88930C10": 8,
            "fn_88930C28": 8,
            "fn_88930C40": 8,
            "fn_88930C58": 8,
            "fn_88930DC0": 8,
            "fn_88930DD8": 8,
            "fn_88930DF0": 8,
            "fn_88930E08": 8,
            "fn_88930E20": 8,
            "fn_88930E28": 8,
            "fn_88930E38": 8,
            "fn_88930E50": 8,
            "fn_88930E68": 8,
            "fn_88930E80": 8,
            "fn_88930E88": 8,
            "fn_88930EA8": 8,
            "fn_88930F08": 8,
            "fn_88930F78": 8,
            "fn_88930F80": 8,
            "fn_88994C40": 8,
            "fn_8899BF90": 8,
            "fn_889C5F00": 8,
        },
    },
    {
        "source": "src/xbox360/matched/leaf_family_s02.c",
        "object": "leaf_family_s02.obj",
        "symbols": {
            "fn_8828D040": 8,
            "fn_8828D178": 8,
            "fn_8828D200": 8,
            "fn_8828D230": 8,
            "fn_8828D258": 8,
            "fn_8828D288": 8,
            "fn_8828D3E0": 8,
            "fn_882DDB70": 8,
            "fn_882DDB78": 8,
            "fn_883E5008": 8,
            "fn_883E7278": 8,
            "fn_883E75F0": 8,
            "fn_883E75F8": 8,
            "fn_883E7600": 8,
            "fn_883E8320": 8,
            "fn_883E8328": 8,
            "fn_883E8330": 8,
            "fn_883E8338": 8,
            "fn_883FB2B0": 8,
            "fn_883FFAA8": 8,
            "fn_883FFAB0": 8,
            "fn_8840B5B0": 8,
            "fn_88411D18": 8,
            "fn_88413590": 8,
            "fn_8841EAD8": 8,
            "fn_8841ECD8": 8,
            "fn_8841EF68": 8,
            "fn_88425EF0": 8,
            "fn_88426130": 8,
            "fn_88427208": 8,
            "fn_8843A128": 8,
            "fn_8843BA30": 8,
            "fn_8843E5C8": 8,
            "fn_884453A8": 8,
            "fn_8844AF78": 8,
            "fn_8844BAA0": 8,
            "fn_88464D38": 8,
            "fn_8846A7F0": 8,
            "fn_8846A9B0": 8,
            "fn_8847E8F0": 8,
            "fn_8847E8F8": 8,
            "fn_884A6D78": 8,
            "fn_884C9818": 8,
            "fn_884C9820": 8,
            "fn_884CE938": 8,
            "fn_884D3518": 8,
            "fn_884D3B70": 8,
            "fn_884D60B8": 8,
            "fn_884D60C8": 8,
            "fn_884DB580": 8,
            "fn_884E4B78": 8,
            "fn_884E5820": 8,
            "fn_884F65E8": 8,
            "fn_88599FF8": 8,
            "fn_8859A000": 8,
            "fn_885B9108": 8,
            "fn_885B9110": 8,
            "fn_885E9490": 8,
            "fn_885EC6A8": 8,
            "fn_885ED260": 8,
            "fn_885ED910": 8,
            "fn_885F5410": 8,
            "fn_885F5418": 8,
            "fn_885F5438": 8,
            "fn_885F93B0": 8,
            "fn_885F9410": 8,
            "fn_885F9418": 8,
            "fn_885F94A0": 8,
            "fn_885F94A8": 8,
            "fn_885F94B0": 8,
            "fn_885F9528": 8,
            "fn_885F9530": 8,
            "fn_885F9538": 8,
            "fn_885F9540": 8,
            "fn_885F9548": 8,
            "fn_885F95F8": 8,
            "fn_885F9600": 8,
            "fn_885F96F8": 8,
            "fn_885F9700": 8,
            "fn_885F97D0": 8,
            "fn_885F9848": 8,
            "fn_885F98B0": 8,
            "fn_885F98B8": 8,
            "fn_885F98C0": 8,
            "fn_885F98D0": 8,
            "fn_885F98D8": 8,
            "fn_885F98E0": 8,
            "fn_885F98E8": 8,
            "fn_885F9970": 8,
            "fn_88601038": 8,
            "fn_88601040": 8,
            "fn_88601048": 8,
            "fn_88601160": 8,
            "fn_88601168": 8,
            "fn_88601268": 8,
            "fn_88602A68": 8,
            "fn_88602B38": 8,
            "fn_88603B88": 8,
            "fn_88603BF8": 8,
            "fn_886079C8": 8,
            "fn_88607AF8": 8,
            "fn_886085E8": 8,
            "fn_88608850": 8,
            "fn_88608948": 8,
            "fn_88608990": 8,
            "fn_88609398": 8,
            "fn_88609468": 8,
            "fn_8860D9D0": 8,
            "fn_8860EE68": 8,
            "fn_88639EA8": 8,
            "fn_88644A40": 8,
            "fn_88659A10": 8,
            "fn_8865A2C8": 8,
            "fn_8865A2D0": 8,
            "fn_8865A7D0": 8,
            "fn_8865E780": 8,
            "fn_886602E8": 8,
            "fn_886C3AB0": 8,
            "fn_886EBA90": 8,
            "fn_886EC180": 8,
            "fn_886EC438": 8,
            "fn_886F0040": 8,
            "fn_887CDC00": 8,
            "fn_887FF260": 8,
            "fn_88803088": 8,
            "fn_888134C8": 8,
            "fn_8881EF60": 8,
            "fn_8881EF70": 8,
            "fn_88834DF8": 8,
            "fn_88836100": 8,
            "fn_888362D0": 8,
            "fn_88883C38": 8,
            "fn_888A43C0": 8,
            "fn_8890D718": 8,
            "fn_8890D760": 8,
            "fn_88922A78": 8,
            "fn_88931780": 8,
            "fn_88931788": 8,
            "fn_889317A0": 8,
            "fn_889317A8": 8,
            "fn_88932360": 8,
            "fn_88932368": 8,
            "fn_88940F18": 8,
            "fn_889C61B0": 8,
            "fn_889C61B8": 8,
        },
    },
    {
        "source": "src/xbox360/matched/leaf_family_s11.c",
        "object": "leaf_family_s11.obj",
        "symbols": {
            "fn_885F5370": 8,
            "fn_885F5388": 8,
            "fn_885F5390": 8,
            "fn_885F5398": 8,
            "fn_885F53A0": 8,
            "fn_885F53A8": 8,
            "fn_885F53B0": 8,
            "fn_885F53B8": 8,
            "fn_885F53C0": 8,
            "fn_885F53C8": 8,
            "fn_885F53D0": 8,
            "fn_885F53D8": 8,
            "fn_885F53E0": 8,
            "fn_885F53E8": 8,
            "fn_885F53F0": 8,
            "fn_885F53F8": 8,
            "fn_885F5400": 8,
            "fn_885F5408": 8,
            "fn_885F5420": 8,
            "fn_885F5428": 8,
            "fn_885F5430": 8,
            "fn_885F5440": 8,
            "fn_885F92A8": 8,
            "fn_885F92B0": 8,
            "fn_885F92B8": 8,
            "fn_885F92C0": 8,
            "fn_885F92C8": 8,
            "fn_885F92D0": 8,
            "fn_885F9370": 8,
            "fn_885F93A8": 8,
            "fn_885F9408": 8,
            "fn_885F94B8": 8,
            "fn_885F94C0": 8,
            "fn_885F94C8": 8,
            "fn_885F94D0": 8,
            "fn_885F94D8": 8,
            "fn_885F94E0": 8,
            "fn_885F94E8": 8,
            "fn_885F94F0": 8,
            "fn_885F94F8": 8,
            "fn_885F9500": 8,
            "fn_885F9508": 8,
            "fn_885F9510": 8,
            "fn_885F9518": 8,
            "fn_885F9520": 8,
            "fn_885F9550": 8,
            "fn_885F9558": 8,
            "fn_885F9560": 8,
            "fn_885F9580": 8,
            "fn_885F9588": 8,
            "fn_885F9590": 8,
            "fn_885F95E8": 8,
            "fn_885F95F0": 8,
            "fn_885F9668": 8,
            "fn_885F9670": 8,
            "fn_885F9678": 8,
            "fn_885F9680": 8,
            "fn_885F9688": 8,
            "fn_885F9690": 8,
            "fn_885F96A8": 8,
            "fn_885F96B0": 8,
            "fn_885F96B8": 8,
            "fn_885F96C0": 8,
            "fn_885F96C8": 8,
            "fn_885F96D0": 8,
            "fn_885F96E8": 8,
            "fn_885F96F0": 8,
            "fn_885F9708": 8,
            "fn_885F9720": 8,
            "fn_885F97C8": 8,
            "fn_885F97D8": 8,
            "fn_885F97E0": 8,
            "fn_885F97E8": 8,
            "fn_885F97F0": 8,
            "fn_885F97F8": 8,
            "fn_885F9800": 8,
            "fn_885F9808": 8,
            "fn_885F9810": 8,
            "fn_885F9818": 8,
            "fn_885F9840": 8,
            "fn_885F9878": 8,
            "fn_885F98A8": 8,
            "fn_885F98C8": 8,
            "fn_885F98F0": 8,
            "fn_885F98F8": 8,
            "fn_885F9900": 8,
            "fn_885F9908": 8,
            "fn_885F9910": 8,
            "fn_885F9918": 8,
            "fn_885F9920": 8,
            "fn_885F9928": 8,
            "fn_885F9930": 8,
            "fn_885F9978": 8,
            "fn_885F9980": 8,
            "fn_885F9988": 8,
            "fn_885F9990": 8,
            "fn_885F9998": 8,
            "fn_88600FD8": 8,
            "fn_88600FE0": 8,
            "fn_88600FE8": 8,
            "fn_88600FF0": 8,
            "fn_88600FF8": 8,
            "fn_88601000": 8,
            "fn_88601008": 8,
            "fn_88601010": 8,
            "fn_88601018": 8,
            "fn_88601030": 8,
            "fn_886010D0": 8,
            "fn_88601158": 8,
            "fn_88601260": 8,
            "fn_88602928": 8,
            "fn_88602A30": 8,
            "fn_88602A38": 8,
            "fn_88602A40": 8,
            "fn_88602A48": 8,
            "fn_88602A50": 8,
            "fn_88602A58": 8,
            "fn_88602A60": 8,
            "fn_88602B30": 8,
            "fn_88932370": 8,
        },
    },
    {
        "source": "src/xbox360/matched/leaf_family_s03.c",
        "object": "leaf_family_s03.obj",
        "symbols": {
            "fn_883E7270": 4,
            "fn_884038F0": 4,
            "fn_884038F8": 4,
            "fn_88403CC8": 4,
            "fn_88403CD0": 4,
            "fn_88403D90": 4,
            "fn_88403D98": 4,
            "fn_88403DA0": 4,
            "fn_88403E60": 4,
            "fn_88403E68": 4,
            "fn_88403E70": 4,
            "fn_88403E78": 4,
            "fn_88403E80": 4,
            "fn_88403E88": 4,
            "fn_88403E90": 4,
            "fn_88403E98": 4,
            "fn_88403EA0": 4,
            "fn_88403EA8": 4,
            "fn_88403EB0": 4,
            "fn_88403EB8": 4,
            "fn_88403EC0": 4,
            "fn_88403EC8": 4,
            "fn_88418598": 4,
            "fn_884185A0": 4,
            "fn_884185A8": 4,
            "fn_8841A950": 4,
            "fn_8841A958": 4,
            "fn_8841AA98": 4,
            "fn_8841AAA0": 4,
            "fn_8841AB80": 4,
            "fn_8841AB88": 4,
            "fn_8841AB90": 4,
            "fn_8841AB98": 4,
            "fn_8841ABA0": 4,
            "fn_8841ABA8": 4,
            "fn_8841ABB0": 4,
            "fn_8841ABB8": 4,
            "fn_8841ABC0": 4,
            "fn_8841ABC8": 4,
            "fn_8841AC80": 4,
            "fn_8841AC88": 4,
            "fn_8841AC90": 4,
            "fn_8841AC98": 4,
            "fn_8841ACA0": 4,
            "fn_8841ACA8": 4,
            "fn_8841B470": 4,
            "fn_8841B5D8": 4,
            "fn_88428E78": 4,
            "fn_8842A8F8": 4,
            "fn_88431F00": 4,
        },
    },
    {
        "source": "src/xbox360/matched/leaf_family_s04.c",
        "object": "leaf_family_s04.obj",
        "symbols": {
            "fn_881DB948": 8,
            "fn_88273690": 8,
            "fn_8827EC80": 8,
            "fn_8827EC88": 8,
            "fn_8828C548": 8,
            "fn_8828C568": 8,
            "fn_8828C588": 8,
            "fn_8828C5A8": 8,
            "fn_8828C5C8": 8,
            "fn_8828C5E8": 8,
            "fn_8828D1D0": 8,
            "fn_8828D3D0": 8,
            "fn_883FFA98": 8,
            "fn_883FFAB8": 8,
            "fn_883FFAC0": 8,
            "fn_8843B738": 8,
            "fn_8860B6D0": 8,
            "fn_8863A208": 8,
            "fn_8863A220": 8,
            "fn_886EC068": 8,
            "fn_887786F8": 8,
            "fn_8881EF68": 8,
            "fn_88864C10": 8,
        },
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
