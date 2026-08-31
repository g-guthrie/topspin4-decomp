#include "online_session_callbacks.h"

/* Swing_DLL.xex 0x8877C0A0, executable version 0.0.0.3. */
ts4_script_u32 ts4_script_set_no_disco(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;

    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    }
    else {
        value = g_ts4_default_script_value;
    }
    ts4_script_string_equals(value->payload, g_ts4_true_string);
    return 0;
}
