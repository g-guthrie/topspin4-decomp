#include "online_predicates.h"

struct TS4OnlineUser {
    ts4_script_u8 reserved[0x2C];
    ts4_script_u8 is_host;
};

struct TS4OnlineSession {
    ts4_script_u8 reserved[0x14];
    struct TS4OnlineUser *local_user;
};

struct TS4HostContext {
    ts4_script_u8 reserved[0x1C];
    struct TS4OnlineSession *session;
};

extern struct TS4HostContext *g_ts4_session_context;

/* Swing_DLL.xex 0x88780200, registered as IsHost. */
ts4_script_u32 ts4_script_is_host(void)
{
    ts4_script_u32 result = 0;
    struct TS4OnlineSession *session = g_ts4_session_context->session;

    if (session != 0) {
        result = session->local_user->is_host;
    }
    return result;
}
