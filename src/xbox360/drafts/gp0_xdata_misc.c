/*
 * DRAFTS (not compiled in the matching build), GP0 / WP6: XData glue.
 *
 *  - ts4_gp0_script_set_engine_frequency_88790DA0 (fn_88790DA0): Lua binding that stores a number
 *    into GameplayInputs/EngineConfig. fn_check: 3 differing instructions (stack slot of the
 *    XData handle: original keeps it at 0x50(r1) overlapping the double->int temp, MSVC puts it at
 *    0x58 here; block scoping did not change that). Logic is exact.
 *  - fn_88169350 (u32 attribute read, type code 9) - written as C below; 31 instructions differ
 *    (original reloads the tree pointer into r4 in the default branch and keeps `mr r9,r3`).
 *  - ts4_loop_get_u32_off8_8866E448 (sync per-player active flag) - differs only by lwzx operand order
 *    (original: lwzx r11,r10,r11 = index,base; MSVC emits base,index for every source form tried).
 *  - fn_88669040 (consume one-shot requests) - NOT matchable by fn_check: the original keeps r3/r5
 *    live across the calls to fn_88668DF8/fn_88668D70, i.e. those callees use a custom register
 *    convention (link-time code generation); the plain /O2 compiler spills instead.
 */
#include "gp0_types.h"
#include "script_context.h"

struct Gp0XHandle {
    void *tree;
    gp0_u32 node_id;
    void *pool;          /* XData data pool: pool+0x24 is the base of packed node structs */
};

/* Typed view of GamePlayInterface:/SwingGameplayInterface/GameplayInputs (type hash 0x63F5A11F). */
struct Gp0GameplayInputs {
    gp0_u8 u_0000[0x60];
    gp0_u8 engine_config_valid;       /* +0x60 set to 1 when the script writes EngineConfig */
    gp0_u8 u_0061[3];
    int engine_config_frequency;      /* +0x64 EngineConfig/@Frequency (as int) */
};

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern const char lbl_880ED6A4[];     /* "GamePlayInterface:/SwingGameplayInterface/GameplayInputs" */

struct Gp0XHandle *fn_8862C0E8(struct Gp0XHandle *out, const char *xpath);
void *fn_88923530(void *pool, struct Gp0XHandle handle, gp0_u32 type_hash);
int fn_88780288(int value);

/*
 * Swing_DLL.xex 0x88790DA0: Lua binding that stores its first numeric argument as
 * GameplayInputs/EngineConfig frequency (+0x64) and marks the EngineConfig block valid (+0x60).
 */
gp0_u32 ts4_gp0_script_set_engine_frequency_88790DA0(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *argument;
    double frequency;
    struct Gp0GameplayInputs *inputs;

    if (context->arguments->count > 0) {
        argument = context->arguments->first_value;
    } else {
        argument = g_ts4_default_script_value;
    }
    if (argument->type == TS4_SCRIPT_VALUE_NUMBER) {
        frequency = argument->value.number;
    } else if (argument->type == TS4_SCRIPT_VALUE_INTEGER) {
        frequency = argument->value.integer;
    } else {
        frequency = g_ts4_script_constants[11];
    }
    {
        struct Gp0XHandle handle;
        fn_8862C0E8(&handle, lbl_880ED6A4);
        inputs = (struct Gp0GameplayInputs *)fn_88923530(handle.pool, handle, 0x63F5A11F);
    }
    inputs->engine_config_valid = 1;
    inputs->engine_config_frequency = fn_88780288((int)frequency);
    return 0;
}


/* ---------------- fn_88169350: u32 attribute read ----------------------------------- */
/* Same protocol as the matched ts4_gp0_xdata_get_bool_88163C60 (see gp0_xdata_get.c). */
/*
gp0_u32 *xdata_get_u32_88169350(gp0_u32 *out, struct Gp0XHandle *h)
{
    struct Gp0XTree *tree = h->tree;
    if (!tree->vt->has_type(tree, h->node_id, 9)) {
        gp0_u32 result = 0;
        struct Gp0XDefault def = { &lbl_880D4B14 };
        tree->vt->create_with_default(tree, h, h->node_id, &result, 4, &def);
        *out = result;
    } else {
        *out = *(gp0_u32 *)tree->vt->get_value_ptr(tree, h, h->node_id, 4);
    }
    return out;
}
*/

/* ---------------- ts4_loop_get_u32_off8_8866E448 (0x70 B) ----------------------------------------------- */
/*
void sync_player_active_flag_8866E448(struct Gp0Instance *inst)
{
    int i, n = inst->players_end - inst->players_begin;
    for (i = 0; i < n; i++) {
        struct Gp0Player *p = inst->players_begin[i];
        if (p) p->state->flag_4e5 = (inst->flags->flag_84 && p->is_active) ? 1 : 0;
    }
}
*/

/* ---------------- fn_88669040 (0x5C B) ------------------------------------------------ */
/*
void consume_pending_requests_88669040(struct X *o)
{
    if (o->b1c == 1) { o->b1c = 0; fn_88668DF8(o); }
    if (o->b1d == 1) { o->b1d = 0; fn_88668D70(o); }
    if (o->b1e == 1) { o->b1e = 0; o->b37c = 1; }
}
*/

/* ---------------- fn_887928A8: script binding "Withdrawal" (0x1D8 B) -------------------- */
/*
 * Reads its first argument as a string and compares with g_ts4_true_string (fn_ts4_script_string_equals).
 * With the match object g_88D458F4 alive and not yet withdrawn (+0xC4 == 0):
 *   amount = (current_game_count(+0x38->+0x3D0) != 0 && !(+0xCC)) ? count + 10 : 1;
 *   if (obj+0xB8) { session = fn_88172A90(g_ts4_session_context->+0xC); session->+0x42C = amount;
 *                   obj->+0xB8->vtbl[5](session, 0); if (--session->+0x414 <= 0) session->vtbl[0](1); }
 *   (obj->+0xAC)->+0x22C = 1;  obj->+0xC8 = flag ? 1 - obj->+0xD0 : obj->+0xD0;  obj->+0xC4 = amount.
 * Without the match object (service 0x8C5A4922, GameDB-ish): looks at two counters at
 * service+0x220+..., sets  Commands/Withdrawal/@LooserTeamIndex = (a == 0 || b == 0) ^ flag
 * and triggers Commands/Withdrawal/@IsTriggered = true.
 */
