#include "tsu_friends_leaderboard.h"

extern void ts4_online_init_friends_leaderboard(
    void *online_context, u32 leaderboard_id, PlayerEntry *player,
    int mode, u32 leaderboard_type
);

/* Swing_DLL.xex 0x8878B600, registered as TSU_InitFriendsLeaderboard. */
u32 tsu_init_friends_leaderboard(ScriptContext *context)
{
    ScriptArguments *arguments = context->arguments;
    ScriptValue *default_value = g_ts4_default_script_value;
    ScriptValue *argument;
    PlayerEntry **current;
    PlayerEntry **end;
    u32 leaderboard_id;
    int player_index;
    int mode;
    u32 leaderboard_type;

    argument = *(u32 *)&arguments->count > 0 ? arguments->first_value : default_value;
    leaderboard_id = (u32)ts4_script_number(argument);
    argument = arguments->count > 1 ? arguments->first_value + 1 : default_value;
    player_index = (int)ts4_script_number(argument);
    argument = arguments->count > 2 ? arguments->first_value + 2 : default_value;
    mode = (int)ts4_script_number(argument);
    argument = arguments->count > 3 ? arguments->first_value + 3 : default_value;
    leaderboard_type = (u32)ts4_script_number(argument);

    if (leaderboard_type != 0xF5BF4F97 && leaderboard_type != 0x4DD88F5A) {
        leaderboard_type = 0xF5BF4F97;
    }

    if (g_ts4_online_context != 0) {
        end = g_ts4_online_state->players->end;
        current = g_ts4_online_state->players->begin;
        while (current != end) {
            PlayerEntry *player = *current;
            if (player_index == player->player_index) {
                ts4_online_init_friends_leaderboard(
                    g_ts4_online_context, leaderboard_id, player, mode,
                    leaderboard_type
                );
                break;
            }
            ++current;
        }
    }
    return 0;
}
