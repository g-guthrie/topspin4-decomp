#include "script_context.h"

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern void *g_ts4_online_context;

ts4_script_u32 ts4_online_load_profile(
    void *online_context,
    int profile_index
);

/* Swing_DLL.xex 0x8879BAA8, registered as TSU_LoadProfile. */
ts4_script_u32 tsu_load_profile(
    struct TS4ScriptContext *context
)
{
    struct TS4ScriptValue *argument;
    double profile_index;

    if (context->arguments->count > 0) {
        argument = context->arguments->first_value;
    } else {
        argument = g_ts4_default_script_value;
    }

    if (argument->type == TS4_SCRIPT_VALUE_NUMBER) {
        profile_index = argument->value.number;
    } else if (argument->type == TS4_SCRIPT_VALUE_INTEGER) {
        profile_index = argument->value.integer;
    } else {
        profile_index = g_ts4_script_constants[11];
    }

    if (g_ts4_online_context != 0) {
        return ts4_online_load_profile(
            g_ts4_online_context,
            (int)profile_index
        );
    }
    return 0;
}
