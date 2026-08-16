#include "script_context.h"

struct TS4CharacterRequestSessionContext {
    ts4_script_u8 reserved[0x1C];
    void *lobby;
};

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern struct TS4CharacterRequestSessionContext *g_ts4_session_context;

void ts4_lobby_ask_for_character(void *lobby, int player_index);

/* Swing_DLL.xex 0x88787638, registered as CG_AskForCharacter. */
ts4_script_u32 competition_game_ask_for_character(
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
        ts4_lobby_ask_for_character(lobby, (int)player_index);
    }
    return 0;
}
