#include "script_context.h"

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern void *lbl_88D4594C;
extern void *lbl_88D45954;
extern void *lbl_88D45A60;
ts4_script_u32 ts4_if_set_u32_off314_887993C8(void *object, int);
ts4_script_u32 fn_8886B230(ts4_script_u32);
ts4_script_u32 fn_8886B388(ts4_script_u32);
ts4_script_u32 fn_888C8370(void *object, int);
ts4_script_u32 fn_888C84E8(void *object, int);
ts4_script_u32 fn_888C8660(void *object, int);
ts4_script_u32 fn_888C8878(void *object, ts4_script_u32);
ts4_script_u32 fn_888CA778(void *object, ts4_script_u32);
ts4_script_u32 fn_888CDF68(int);
ts4_script_u32 fn_888DBFC0(ts4_script_u32);
ts4_script_u32 fn_888E01E0(void *object, int);
ts4_script_u32 fn_888E04C8(void *object, int);
ts4_script_u32 fn_888E9898(void *object, ts4_script_u32);
ts4_script_u32 fn_888E9930(void *object, ts4_script_u32);
ts4_script_u32 fn_888E9A50(void *object, ts4_script_u32);
ts4_script_u32 fn_888EC458(int);
ts4_script_u32 fn_888F08A0(ts4_script_u32);
ts4_script_u32 fn_888FF488(ts4_script_u32);
ts4_script_u32 fn_888FF5C0(void *object, int);

/* Swing_DLL.xex 0x88782F60 */
ts4_script_u32 ts4_script_number_arg_call_88782F60(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    fn_888C8370(lbl_88D45954, (int)number);
    return 0;
}

/* Swing_DLL.xex 0x88782FF8 */
ts4_script_u32 ts4_script_number_arg_call_88782FF8(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    fn_888C84E8(lbl_88D45954, (int)number);
    return 0;
}

/* Swing_DLL.xex 0x88783090 */
ts4_script_u32 ts4_script_number_arg_call_88783090(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    fn_888C8660(lbl_88D45954, (int)number);
    return 0;
}

/* Swing_DLL.xex 0x88783228 */
ts4_script_u32 ts4_script_number_arg_call_88783228(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    fn_888C8878(lbl_88D45954, (ts4_script_u32)number);
    return 0;
}

/* Swing_DLL.xex 0x88783488 */
ts4_script_u32 ts4_script_number_arg_call_88783488(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    fn_888CA778(lbl_88D4594C, (ts4_script_u32)number);
    return 0;
}

/* Swing_DLL.xex 0x88783FD8 */
ts4_script_u32 ts4_script_number_arg_call_88783FD8(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    return fn_888CDF68((int)number);
}

/* Swing_DLL.xex 0x8878AAC0 */
ts4_script_u32 ts4_script_number_arg_call_8878AAC0(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    fn_888DBFC0((ts4_script_u32)number);
    return 0;
}

/* Swing_DLL.xex 0x887949F8 */
ts4_script_u32 ts4_script_number_arg_call_887949F8(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    fn_888E01E0(lbl_88D45954, (int)number);
    return 0;
}

/* Swing_DLL.xex 0x88794A90 */
ts4_script_u32 ts4_script_number_arg_call_88794A90(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    fn_888E04C8(lbl_88D45954, (int)number);
    return 0;
}

/* Swing_DLL.xex 0x88796AB0 */
ts4_script_u32 ts4_script_number_arg_call_88796AB0(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    fn_888E9898(lbl_88D45954, (ts4_script_u32)number);
    return 0;
}

/* Swing_DLL.xex 0x88796B48 */
ts4_script_u32 ts4_script_number_arg_call_88796B48(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    fn_888E9930(lbl_88D45954, (ts4_script_u32)number);
    return 0;
}

/* Swing_DLL.xex 0x88796BE0 */
ts4_script_u32 ts4_script_number_arg_call_88796BE0(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    fn_888E9A50(lbl_88D45954, (ts4_script_u32)number);
    return 0;
}

/* Swing_DLL.xex 0x887970D8 */
ts4_script_u32 ts4_script_number_arg_call_887970D8(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    fn_888EC458((int)number);
    return 0;
}

/* Swing_DLL.xex 0x88798BD0 */
ts4_script_u32 ts4_script_number_arg_call_88798BD0(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    fn_888F08A0((ts4_script_u32)number);
    return 0;
}

/* Swing_DLL.xex 0x8879AB70 */
ts4_script_u32 ts4_script_number_arg_call_8879AB70(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    ts4_if_set_u32_off314_887993C8(lbl_88D45A60, (int)number);
    return 0;
}

/* Swing_DLL.xex 0x8879EC78 */
ts4_script_u32 ts4_script_number_arg_call_8879EC78(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    return fn_8886B230((ts4_script_u32)number);
}

/* Swing_DLL.xex 0x8879ED08 */
ts4_script_u32 ts4_script_number_arg_call_8879ED08(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    fn_8886B388((ts4_script_u32)number);
    return 0;
}

/* Swing_DLL.xex 0x887A3280 */
ts4_script_u32 ts4_script_number_arg_call_887A3280(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    fn_888FF488((ts4_script_u32)number);
    return 0;
}

/* Swing_DLL.xex 0x887A3310 */
ts4_script_u32 ts4_script_number_arg_call_887A3310(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double number;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        number = value->value.number;
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        number = value->value.integer;
    } else {
        number = g_ts4_script_constants[11];
    }
    fn_888FF5C0(lbl_88D4594C, (int)number);
    return 0;
}
