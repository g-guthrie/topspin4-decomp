#include "pro_challenge_profile.h"

extern u32 ts4_profile_internal_lookup(u32 profile_index);

/* Swing_DLL.xex 0x8879BD68; semantic role remains under investigation. */
u32 ts4_script_profile_internal_lookup(ScriptContext *context)
{
    ScriptValue *argument;
    double profile_index;

    if (context->arguments->count > 0) argument = context->arguments->first_value;
    else argument = g_ts4_default_script_value;
    if (argument->type == SCRIPT_VALUE_NUMBER) profile_index = argument->value.number;
    else if (argument->type == SCRIPT_VALUE_INTEGER) profile_index = argument->value.integer;
    else profile_index = g_ts4_script_constants[11];

    ts4_find_service(0xFB595DB2);
    return ts4_profile_internal_lookup((u32)profile_index);
}
