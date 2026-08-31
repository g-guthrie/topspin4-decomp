#include "script_context.h"

struct TS4IntrusiveList {
    void *sentinel;
};

struct TS4SeasonRankOnlineContext {
    ts4_script_u8 reserved[0x1C];
    struct TS4IntrusiveList season_rank_history;
};

extern struct TS4SeasonRankOnlineContext *g_ts4_online_context;

void ts4_clear_intrusive_list(struct TS4IntrusiveList *list);

/*
 * Swing_DLL.xex 0x887835E8, registered as
 * TSU_ResetSeasonRankHistory.
 */
ts4_script_u32 ts4_script_reset_season_rank_history(void)
{
    if (g_ts4_online_context != 0) {
        ts4_clear_intrusive_list(
            &g_ts4_online_context->season_rank_history
        );
    }
    return 0;
}
