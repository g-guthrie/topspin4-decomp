#include "script_context.h"

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
ts4_script_u32 fn_887915F0(ts4_script_u32 *part);

/* Registered as ChangePart. */
ts4_script_u32 ts4_script_change_part(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double part_value;
    ts4_script_u32 part;

    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        part_value = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        part_value = value->value.integer;
    } else {
        part_value = g_ts4_script_constants[11];
    }
    part = (ts4_script_u32)part_value;
    return fn_887915F0(&part);
}
