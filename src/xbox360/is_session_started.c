#include "online_predicates.h"

struct TS4SessionState {
    ts4_script_u8 reserved[0x2C];
    ts4_script_u8 started;
};

extern struct TS4SessionState *g_ts4_session_state;

/* Swing_DLL.xex 0x8877BFD8, registered as IsSessionStarted. */
ts4_script_u32 ts4_script_is_session_started(void)
{
    if (g_ts4_session_state != 0) {
        return g_ts4_session_state->started;
    }
    return 0;
}
