#include "script_context.h"

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern void *g_ts4_online_context;

void ts4_online_debug_end_season(
    void *online_context,
    ts4_script_u32 season
);

/* Swing_DLL.xex 0x8877FD88, registered as TSU_Debug_EndSeason. */
ts4_script_u32 tsu_debug_end_season(
    struct TS4ScriptContext *context
)
{
    struct TS4ScriptValue *argument;
    double season;

    if (context->arguments->count > 0) {
        argument = context->arguments->first_value;
    } else {
        argument = g_ts4_default_script_value;
    }

    if (argument->type == TS4_SCRIPT_VALUE_NUMBER) {
        season = argument->value.number;
    } else if (argument->type == TS4_SCRIPT_VALUE_INTEGER) {
        season = argument->value.integer;
    } else {
        season = g_ts4_script_constants[11];
    }

    if (g_ts4_online_context != 0) {
        ts4_online_debug_end_season(
            g_ts4_online_context,
            (ts4_script_u32)season
        );
    }
    return 0;
}
