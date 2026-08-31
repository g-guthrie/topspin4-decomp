#include "pro_challenge_profile.h"

extern void *g_ts4_online_state;
extern u8 ts4_profile_internal_is_available(
    void *online_state, int profile_index, u32 flags
);
extern void ts4_profile_internal_activate(void *service, int profile_index);

/* Swing_DLL.xex 0x8879BFF8; semantic role remains under investigation. */
u32 ts4_script_profile_internal_activate(ScriptContext *context)
{
    ScriptValue *argument;
    double profile_index_value;
    int profile_index;

    if (context->arguments->count > 0) argument = context->arguments->first_value;
    else argument = g_ts4_default_script_value;
    if (argument->type == SCRIPT_VALUE_NUMBER) profile_index_value = argument->value.number;
    else if (argument->type == SCRIPT_VALUE_INTEGER) profile_index_value = argument->value.integer;
    else profile_index_value = g_ts4_script_constants[11];

    profile_index = (int)profile_index_value;
    if (ts4_profile_internal_is_available(g_ts4_online_state, profile_index, 0) == 1) {
        ts4_profile_internal_activate(ts4_find_service(0xE3767AD6), profile_index);
    }
    return 0;
}
