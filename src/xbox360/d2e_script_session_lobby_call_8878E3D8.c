/* Swing_DLL.xex 0x8878E3D8-0x8878E47B, executable version 0.0.0.3. */
#include "script_context.h"

struct TS4RemoveFakePlayerSessionContext {
    ts4_script_u8 reserved[0x1C];
    void *lobby;
};

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern struct TS4RemoveFakePlayerSessionContext *g_ts4_session_context;

void fn_889B0F70(void *lobby, int player_index);

/* Swing_DLL.xex 0x8878E3D8: script callback that forwards a numeric argument to the session lobby. */
ts4_script_u32 ts4_script_session_lobby_number_call_8878E3D8(
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
        fn_889B0F70(lobby, (int)player_index);
    }
    return 0;
}
