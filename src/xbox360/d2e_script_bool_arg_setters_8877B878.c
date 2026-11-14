#include "script_context.h"

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern const char g_ts4_true_string[];
ts4_script_u8 ts4_script_string_equals(void *value, const char *text);
extern void *g_ts4_session_context;
extern void *lbl_88D45870;
extern void *lbl_88D4588C;
extern void *lbl_88D45954;

struct TS4Flag8877B878 { ts4_script_u8 pad[0x35]; ts4_script_u8 flag; };
/* Swing_DLL.xex 0x8877B878 */
ts4_script_u32 ts4_script_set_flag_from_bool_arg_8877B878(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    struct TS4Flag8877B878 *state;
    ts4_script_u8 flag;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    flag = ts4_script_string_equals(value->payload, g_ts4_true_string);
    state = lbl_88D45870;
    if (state) state->flag = flag;
    return 0;
}

struct TS4Flag8877B8E0 { ts4_script_u8 pad[0xBD]; ts4_script_u8 flag; };
/* Swing_DLL.xex 0x8877B8E0 */
ts4_script_u32 ts4_script_set_flag_from_bool_arg_8877B8E0(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    struct TS4Flag8877B8E0 *state;
    ts4_script_u8 flag;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    flag = ts4_script_string_equals(value->payload, g_ts4_true_string);
    state = lbl_88D45954;
    if (state) state->flag = flag;
    return 0;
}

struct TS4Flag8877B948 { ts4_script_u8 pad[0xBC]; ts4_script_u8 flag; };
/* Swing_DLL.xex 0x8877B948 */
ts4_script_u32 ts4_script_set_flag_from_bool_arg_8877B948(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    struct TS4Flag8877B948 *state;
    ts4_script_u8 flag;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    flag = ts4_script_string_equals(value->payload, g_ts4_true_string);
    state = lbl_88D45954;
    if (state) state->flag = flag;
    return 0;
}

struct TS4Flag8877BBC0 { ts4_script_u8 pad[0x1D]; ts4_script_u8 flag; };
/* Swing_DLL.xex 0x8877BBC0 */
ts4_script_u32 ts4_script_set_flag_from_bool_arg_8877BBC0(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    struct TS4Flag8877BBC0 *state;
    ts4_script_u8 flag;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    flag = ts4_script_string_equals(value->payload, g_ts4_true_string);
    state = lbl_88D4588C;
    if (state) state->flag = flag;
    return 0;
}

struct TS4InnerFlag8877BE30 { ts4_script_u8 pad[0x12]; ts4_script_u8 flag; };
struct TS4Inner8877BE30 { ts4_script_u8 pad[0x1C]; struct TS4InnerFlag8877BE30 *inner; };
/* Swing_DLL.xex 0x8877BE30 */
ts4_script_u32 ts4_script_set_flag_from_bool_arg_8877BE30(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    struct TS4Inner8877BE30 *state;
    struct TS4InnerFlag8877BE30 *inner;
    ts4_script_u8 flag;
    if (context->arguments->count > 0) {
        value = context->arguments->first_value;
    } else {
        value = g_ts4_default_script_value;
    }
    flag = ts4_script_string_equals(value->payload, g_ts4_true_string);
    state = g_ts4_session_context;
    inner = state->inner;
    if (inner) inner->flag = flag;
    return 0;
}
