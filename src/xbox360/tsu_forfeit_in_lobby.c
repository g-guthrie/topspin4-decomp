#include "script_context.h"

extern void *g_ts4_online_context;

void ts4_online_forfeit_in_lobby(
    void *online_context,
    ts4_script_u32 reason
);

/* Swing_DLL.xex 0x88798C60, registered as TSU_ForfeitInLobby. */
ts4_script_u32 tsu_forfeit_in_lobby(void)
{
    void *online_context = g_ts4_online_context;

    if (online_context != 0) {
        ts4_online_forfeit_in_lobby(online_context, 0);
    }
    return 0;
}
