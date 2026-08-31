#include "player_visibility.h"

/* Swing_DLL.xex 0x88794C18, executable version 0.0.0.3. */
ts4_script_u32 ts4_script_set_player_body_visibility(
    struct TS4ScriptContext *context
)
{
    struct TS4ScriptValue *value;

    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    }
    else {
        value = g_ts4_default_script_value;
    }
    ts4_script_string_equals(value->payload, g_ts4_true_string);
    ts4_set_player_body_visibility();
    return 0;
}

/* Swing_DLL.xex 0x88794C70, executable version 0.0.0.3. */
ts4_script_u32 ts4_script_set_player_visibility(
    struct TS4ScriptContext *context
)
{
    struct TS4ScriptValue *value;

    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    }
    else {
        value = g_ts4_default_script_value;
    }
    ts4_script_string_equals(value->payload, g_ts4_true_string);
    ts4_set_player_visibility();
    return 0;
}
