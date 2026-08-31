#include "minigame.h"

ts4_script_u32 ts4_script_minigame_change_display_game_mode(
    struct TS4ScriptContext *context
)
{
    struct TS4ScriptValue *value;
    double mode;

    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    }
    else {
        value = g_ts4_default_script_value;
    }

    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        mode = value->value.number;
    }
    else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        mode = value->value.integer;
    }
    else {
        mode = g_ts4_script_constants[11];
    }

    ts4_change_display_game_mode((ts4_script_u32)mode);
    return 0;
}
