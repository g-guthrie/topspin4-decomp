#include "pro_challenge_profile.h"

extern void ts4_pro_challenge_save_profile(void *service, int profile_index);

/* Swing_DLL.xex 0x8879B898, registered as ProChallenge_SaveProfile. */
u32 ts4_script_pro_challenge_save_profile(ScriptContext *context)
{
    ScriptValue *argument;
    double profile_index;
    void *service;

    if (context->arguments->count > 0) argument = context->arguments->first_value;
    else argument = g_ts4_default_script_value;
    if (argument->type == SCRIPT_VALUE_NUMBER) profile_index = argument->value.number;
    else if (argument->type == SCRIPT_VALUE_INTEGER) profile_index = argument->value.integer;
    else profile_index = g_ts4_script_constants[11];

    service = ts4_find_service(0x061B4A78);
    if (service != 0) ts4_pro_challenge_save_profile(service, (int)profile_index);
    return 0;
}
