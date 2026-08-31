#include "script_context.h"

struct TS4RemoveFakePlayerSessionContext {
    ts4_script_u8 reserved[0x1C];
    void *lobby;
};

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern struct TS4RemoveFakePlayerSessionContext *g_ts4_session_context;

void ts4_lobby_remove_fake_player(void *lobby, int player_index);

/*
 * Swing_DLL.xex 0x88783AF8, registered as
 * TSU_Debug_RemoveFakePlayerFromLobby.
 */
ts4_script_u32 tsu_debug_remove_fake_player_from_lobby(
    struct TS4ScriptContext *context
)
{
    struct TS4ScriptValue *argument;
    void *lobby;
    double player_index;

    if (context->arguments->count > 0) {
        argument = context->arguments->first_value;
    } else {
        argument = g_ts4_default_script_value;
    }

    if (argument->type == TS4_SCRIPT_VALUE_NUMBER) {
        player_index = argument->value.number;
    } else if (argument->type == TS4_SCRIPT_VALUE_INTEGER) {
        player_index = argument->value.integer;
    } else {
        player_index = g_ts4_script_constants[11];
    }

    lobby = g_ts4_session_context->lobby;
    if (lobby != 0) {
        ts4_lobby_remove_fake_player(lobby, (int)player_index);
    }
    return 0;
}
