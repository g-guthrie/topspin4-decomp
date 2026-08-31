#include "tsu_profile_summaries.h"

extern void ts4_online_load_profile_summaries(
    void *online_context, int profile_index
);

/* Swing_DLL.xex 0x8879BCC8, registered as TSU_LoadProfileSummaries. */
u32 tsu_load_profile_summaries(ScriptContext *context)
{
    ScriptValue *argument;
    double profile_index;

    if (context->arguments->count > 0) {
        argument = context->arguments->first_value;
    } else {
        argument = g_ts4_default_script_value;
    }

    if (argument->type == SCRIPT_VALUE_NUMBER) {
        profile_index = argument->value.number;
    } else if (argument->type == SCRIPT_VALUE_INTEGER) {
        profile_index = argument->value.integer;
    } else {
        profile_index = g_ts4_script_constants[11];
    }

    if (g_ts4_online_context != 0) {
        ts4_online_load_profile_summaries(
            g_ts4_online_context, (int)profile_index
        );
    }
    return 0;
}
