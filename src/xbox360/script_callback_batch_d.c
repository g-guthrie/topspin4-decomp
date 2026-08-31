#include "script_context.h"

extern void *lbl_88D4594C;
extern void *lbl_88D45954;
extern struct TS4ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern const char g_ts4_true_string[];

void fn_888E3908(void);
void fn_888E38A8(void);
void fn_881B4590(void *object);
ts4_script_u32 fn_888E7498(int content_id);
void fn_888E1380(void *object, ts4_script_u32 visible);
void fn_888E14C0(ts4_script_u32 visible);
ts4_script_u32 ts4_script_string_equals(void *value, const char *text);

struct TS4LockerRoomState {
    ts4_script_u8 reserved[0x1C];
    ts4_script_u32 state;
    ts4_script_u8 object_a[0x0C];
    ts4_script_u8 object_b[0x0C];
};

/* Registered as ExitLockerRoom. */
ts4_script_u32 ts4_script_exit_locker_room(void)
{
    struct TS4LockerRoomState *state = lbl_88D4594C;
    fn_888E3908();
    fn_888E38A8();
    fn_881B4590(state->object_a);
    fn_881B4590(state->object_b);
    state->state = 0;
    return 0;
}

/* Registered as CheckDLCOk. */
ts4_script_u32 ts4_script_check_dlc_ok(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    double content_id;
    if (context->arguments->count > 0) value = context->arguments->first_value;
    else value = g_ts4_default_script_value;
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) content_id = value->value.number;
    else if (value->type == TS4_SCRIPT_VALUE_INTEGER) content_id = value->value.integer;
    else content_id = g_ts4_script_constants[11];
    return fn_888E7498((int)content_id);
}

/* Registered as SetFurnitureVisibility. */
ts4_script_u32 ts4_script_set_furniture_visibility(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    if (context->arguments->count > 0) value = context->arguments->first_value;
    else value = g_ts4_default_script_value;
    fn_888E1380(lbl_88D45954, ts4_script_string_equals(value->payload, g_ts4_true_string));
    return 0;
}

/* Registered as SetFreeFormReplayVisibility. */
ts4_script_u32 ts4_script_set_free_form_replay_visibility(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *value;
    if (context->arguments->count > 0) value = context->arguments->first_value;
    else value = g_ts4_default_script_value;
    fn_888E14C0(ts4_script_string_equals(value->payload, g_ts4_true_string));
    return 0;
}
