#include "script_context.h"

struct TS4SeasonOnlineContext;

extern struct TS4SeasonOnlineContext *g_ts4_online_context;

ts4_script_u32 ts4_online_has_time_to_enter_lobby(
    struct TS4SeasonOnlineContext *context
);
ts4_script_u32 ts4_online_has_time_before_season_end(
    struct TS4SeasonOnlineContext *context
);

/*
 * Swing_DLL.xex 0x887835A8, registered as
 * TSU_IsThereEnoughTimeLeftToEnterLobbyBeforeEndOfSeason.
 */
ts4_script_u32
ts4_script_has_time_to_enter_lobby_before_season_end(void)
{
    if (g_ts4_online_context != 0) {
        return ts4_online_has_time_to_enter_lobby(g_ts4_online_context);
    }
    return 0;
}

/*
 * Swing_DLL.xex 0x887835C8, registered as
 * TSU_IsThereEnoughTimeLeftBeforeEndOfSeason.
 */
ts4_script_u32 ts4_script_has_time_before_season_end(void)
{
    if (g_ts4_online_context != 0) {
        return ts4_online_has_time_before_season_end(g_ts4_online_context);
    }
    return 0;
}
