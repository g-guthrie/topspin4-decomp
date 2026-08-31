#include "title_server_logout.h"

/* Swing_DLL.xex 0x88792820, executable version 0.0.0.3. */
ts4_logout_u32 ts4_script_title_server_logout(void)
{
    struct TS4LogoutState *state;

    if (g_ts4_title_server != 0) {
        ts4_title_server_logout(g_ts4_title_server, 0);
    }
    if (g_ts4_online_context != 0) {
        state = g_ts4_online_context->logout_state;
        if ((long)state != 0) {
            state->player_id = 0xffffffff;
            state->active = 0;
            state->status = 0xffffffff;
        }
    }
    return 0;
}
