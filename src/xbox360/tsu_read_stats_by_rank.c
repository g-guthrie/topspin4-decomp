#include "tsu_friends_leaderboard.h"

extern void ts4_online_read_stats_by_rank(
    void *online_context, u32 leaderboard_id, int count, u32 start_rank,
    int mode, u32 leaderboard_type
);

/* Swing_DLL.xex 0x8878BAA0, registered as TSU_ReadStatsByRank. */
u32 tsu_read_stats_by_rank(ScriptContext *context)
{
    ScriptArguments *arguments = context->arguments;
    ScriptValue *default_value = g_ts4_default_script_value;
    ScriptValue *argument;
    u32 leaderboard_id;
    int count;
    u32 start_rank;
    int mode;
    u32 leaderboard_type;

    if (*(u32 *)&arguments->count > 0) argument = arguments->first_value;
    else argument = default_value;
    leaderboard_id = (u32)ts4_script_number(argument);
    if (arguments->count > 1) argument = arguments->first_value + 1;
    else argument = default_value;
    count = (int)ts4_script_number(argument);
    if (arguments->count > 2) argument = arguments->first_value + 2;
    else argument = default_value;
    start_rank = (u32)ts4_script_number(argument);
    if (arguments->count > 3) argument = arguments->first_value + 3;
    else argument = default_value;
    mode = (int)ts4_script_number(argument);
    if (arguments->count > 4) argument = arguments->first_value + 4;
    else argument = default_value;
    leaderboard_type = (u32)ts4_script_number(argument);

    if (count <= 0) count = 1;
    if (leaderboard_type != 0xF5BF4F97 && leaderboard_type != 0x4DD88F5A) {
        leaderboard_type = 0xF5BF4F97;
    }
    if (g_ts4_online_context != 0) {
        ts4_online_read_stats_by_rank(
            g_ts4_online_context, leaderboard_id, count, start_rank, mode,
            leaderboard_type
        );
    }
    return 0;
}
