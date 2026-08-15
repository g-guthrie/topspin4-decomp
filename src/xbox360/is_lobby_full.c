#include "online_predicates.h"

struct TS4Lobby;

struct TS4LobbySystem {
    ts4_script_u8 reserved[0x1C];
    struct TS4Lobby *lobby;
};

extern struct TS4LobbySystem *g_ts4_session_context;

ts4_script_u32 ts4_lobby_is_full(struct TS4Lobby *lobby);

/* Swing_DLL.xex 0x887801E0, registered as IsLobbyFull. */
ts4_script_u32 ts4_script_is_lobby_full(void)
{
    struct TS4Lobby *lobby = g_ts4_session_context->lobby;

    if (lobby != 0) {
        return ts4_lobby_is_full(lobby);
    }
    return 0;
}
