#include "script_context.h"

extern void *g_ts4_online_context;

void ts4_refresh_tournament_sessions(void);

/*
 * Swing_DLL.xex 0x8877FA98, registered as
 * TSU_RefreshTournamentSessions.
 */
ts4_script_u32 tsu_refresh_tournament_sessions(void)
{
    if (g_ts4_online_context != 0) {
        ts4_refresh_tournament_sessions();
    }
    return 0;
}
