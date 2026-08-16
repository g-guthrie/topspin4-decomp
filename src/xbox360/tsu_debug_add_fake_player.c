#include "script_context.h"

struct TS4FakePlayerSessionContext {
    ts4_script_u8 reserved[0x1C];
    void *lobby;
};

extern struct TS4FakePlayerSessionContext *g_ts4_session_context;

void ts4_lobby_add_fake_player(void *lobby);

/*
 * Swing_DLL.xex 0x88783BA0, registered as
 * TSU_Debug_AddFakePlayerToLobby.
 */
ts4_script_u32 tsu_debug_add_fake_player_to_lobby(void)
{
    void *lobby = g_ts4_session_context->lobby;

    if (lobby != 0) {
        ts4_lobby_add_fake_player(lobby);
    }
    return 0;
}
