#include "title_server_callbacks.h"

ts4_script_u32 ts4_script_title_server_login_user_only(
    struct TS4ScriptContext *context
)
{
    struct TS4ScriptValue *argument;
    double user_index;

    if (context->arguments->count > 0) {
        argument = context->arguments->first_value;
    }
    else {
        argument = g_ts4_default_script_value;
    }

    if (argument->type == TS4_SCRIPT_VALUE_NUMBER) {
        user_index = argument->value.number;
    }
    else if (argument->type == TS4_SCRIPT_VALUE_INTEGER) {
        user_index = argument->value.integer;
    }
    else {
        user_index = g_ts4_script_constants[11];
    }

    if (g_ts4_title_server != 0) {
        ts4_title_server_login_user_only(
            g_ts4_title_server,
            (int)user_index
        );
    }

    return 0;
}
