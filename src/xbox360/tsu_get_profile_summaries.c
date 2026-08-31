#include "tsu_profile_summaries.h"

extern char g_ts4_true_string[];
extern u32 ts4_script_string_equals(void *value, const char *text);
extern void ts4_online_get_profile_summaries(
    void *online_context, u32 include_remote, u32 profile_index
);

/* Swing_DLL.xex 0x88783870, registered as TSU_GetProfileSummaries. */
u32 tsu_get_profile_summaries(ScriptContext *context)
{
    ScriptValue *argument;
    u32 include_remote;
    double profile_index;

    if (context->arguments->count > 0) {
        argument = context->arguments->first_value;
    } else {
        argument = g_ts4_default_script_value;
    }

    include_remote = ts4_script_string_equals(
        (u8 *)argument + 0x10, g_ts4_true_string
    );

    if (context->arguments->count > 1) {
        argument = (ScriptValue *)((u8 *)context->arguments->first_value + 0x38);
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
        ts4_online_get_profile_summaries(
            g_ts4_online_context, include_remote, (u32)profile_index
        );
    }
    return 0;
}
