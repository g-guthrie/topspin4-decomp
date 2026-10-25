/*
 * Exact code identity for the functions listed for this unit in
 * config/54540859/remaining_20261025_units.json: full extents, effective
 * relocations and .pdata independently checked. Original ABI and semantics
 * remain provisional. Other declarations/helpers carry no separate credit.
 * AI-assisted, disassembly-derived reconstruction; see docs/exact-matches-20261025.md.
 *
 * Script-native reconstruction. Field meanings, original prototypes and object layouts remain provisional.
 */
#include "script_argument_helpers.h"

typedef unsigned long long ts4_b05_u64;

extern ts4_u8 g_ts4_true_string[];
ts4_u32 ts4_script_string_equals(const void *value, const void *expected);
void *ts4_find_service(ts4_u32 id);

typedef struct ts4_l_player { ts4_u32 reserved; ts4_s32 player_index; } ts4_l_player;
typedef struct ts4_l_player_list { ts4_u32 reserved; ts4_l_player **begin; ts4_l_player **end; } ts4_l_player_list;
typedef struct ts4_l_online_state { ts4_u8 reserved[0x1C]; ts4_l_player_list *players; } ts4_l_online_state;

extern ts4_l_online_state *g_ts4_online_state;
extern ts4_u8 *g_ts4_session_context;
extern ts4_u8 *g_ts4_session_state;

typedef ts4_u32 (*ts4_b05_player_slot_fn)(void *object, ts4_u32 value, ts4_u32 flag);
typedef ts4_u8 *(*ts4_b05_service_slot_fn)(void *object, ts4_u32 zero);
ts4_u8 *fn_8899F970(void *peers, ts4_s32 peer);
ts4_u8 *fn_882156B8(void *state, ts4_u32 id);
ts4_u32 fn_88995A10(ts4_l_player *player, ts4_u8 *peer);
void fn_88151560(void *state, ts4_u8 *event);
void fn_889AD2A0(ts4_u32 board, ts4_l_player *player, ts4_u32 count);

/* Registered as TCR_IsUserPrivilegeSet. 0x8877E1B8-0x8877E330. */
ts4_u32 fn_8877E1B8(struct TS4ScriptContext *context);

/* Registered as ProChallenge_IsUserAtLeaderboardRow. 0x8877F530-0x8877F6B8. */
ts4_u32 ts4_script_pro_challenge_is_user_at_leaderboard_row(struct TS4ScriptContext *context);

/* Registered as MutePeer. 0x88788760-0x887888F4. */
ts4_u32 ts4_script_mute_peer(struct TS4ScriptContext *context);

/* Registered as ProChallenge_ReadStatsAroundUser. 0x8878AC40-0x8878ADE0. */
ts4_u32 fn_8878AC40(struct TS4ScriptContext *context)
{
    ts4_u32 board = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_s32 player_index = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 1)));
    ts4_u32 count = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 2)));
    if (ts4_find_service(0x061B4A78u)) {
        ts4_l_player **current;
        ts4_l_player **end;
        end = g_ts4_online_state->players->end;
        current = g_ts4_online_state->players->begin;
        while (current != end) {
            ts4_l_player *player = *current;
            if (player_index == player->player_index) {
                fn_889AD2A0(board, player, count);
                break;
            }
            ++current;
        }
    }
    return 0;
}
