/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Functions in this file compile to exact objdiff matches with the Xbox 360
 * compiler (see docs/matching-build.md). They were written from the disassembly
 * of the retail module with AI assistance; names, types and field roles are
 * reconstructions, and each function states its address range.
 */
#include "script_argument_helpers.h"

extern ts4_u8 g_ts4_true_string[];
ts4_u32 ts4_script_string_equals(const void *value, const void *expected);
extern void ts4_assign_formatted_text(void *object, const char *text);   /* upstream tsu_format_and_assign.c */
extern void ts4_destroy_owned_object(void *owned);                       /* upstream tsu_cleanup_object.c */
extern void *ts4_find_service(ts4_u32 service_id);                       /* upstream pro_challenge_profile.h */
extern ts4_u8 ts4_profile_internal_is_available(void *online_state, int profile_index, ts4_u32 flags); /* upstream */
extern void ts4_clone_byte_with_object_context(void *wrapper, const ts4_u8 *value); /* upstream (wrapper type opaque here) */

extern void *g_ts4_online_state;
extern ts4_u8 *g_ts4_title_server;
extern ts4_u8 *lbl_88D45B38;
extern ts4_u8 *lbl_88D459E0;
extern ts4_u8 *lbl_88D459D4;
extern ts4_u8 *lbl_88D45954;
extern ts4_u8 *lbl_88D45B0C;
extern ts4_u8 *lbl_88D45B1C;
extern ts4_u8 *lbl_88D45A0C;
extern ts4_u32 lbl_88C6C8FC;
extern ts4_u32 lbl_88C6C8F0;
extern const void *const lbl_880F7AF8[];
extern const void *const lbl_880F799C[];
extern const void *const lbl_880E4BA0[];
extern const void *const lbl_880EF59C[];
extern const ts4_u8 lbl_880C91A6[];
extern const char lbl_880EC234[];

void *fn_88608590(ts4_u32 zero, void *text);
void *fn_88618998(void *owner, void *value);
void fn_88608698(void *owner, void *value);
void *fn_8883B388(void *owner, ts4_s32 value);
void fn_88150600(void *field, void *text);
void fn_888F3338(void *service, ts4_s32 value);
void fn_888CFBC8(void *service);
void fn_888D0F00(void *object, ts4_u32 flag, ts4_u32 value);
void fn_88656900(void *object, ts4_u32 kind, ts4_s32 value);
ts4_u32 *fn_88838BB8(ts4_u32 *result, void *owner, ts4_s32 value);
ts4_s32 fn_888389C0(void *owner, ts4_s32 value);
void fn_8883D8D0(void *owner);
void fn_8884E478(void *owner);
void fn_888C3B90(void *result, void *owner, ts4_u32 key);
void *fn_88164450(void *result, void *source, ts4_u32 *key, ts4_u32 zero);
void *fn_88164F60(void *result, void *source, ts4_u32 *key, ts4_u32 zero);
void fn_8822AFE8(void *target, ts4_u32 *value);
void fn_8886B150(void *owner, ts4_u32 key, ts4_u32 flag);
void fn_88865708(void *owner);
ts4_u8 *fn_88614938(void *manager, ts4_s32 key);
ts4_u32 fn_888CDF68(ts4_s32 value);
void fn_8886BB78(void *owner, ts4_s32 value);
ts4_u32 fn_887E97E8(void *queue, void *kind, ts4_s32 player, ts4_u32 zero);
void fn_887E98F0(void *queue, void *kind, ts4_s32 player, ts4_u32 zero);
ts4_u32 fn_887E9860(void *queue, void *kind, ts4_s32 player, ts4_u32 zero);
ts4_u8 *fn_88215110(ts4_s32 player);
void fn_887EA280(void *queue, void *request, ts4_u32 zero);
ts4_u8 *fn_88613268(void *allocator, ts4_u32 size, ts4_u32 align, ts4_u32 zero, ts4_u32 kind);
void fn_88151F20(void *request, const char *path, ts4_u32 capacity);
void fn_889B1588(void *server, void *request, ts4_u32 zero);

typedef struct ts4_dump_visitor {
    const void *const *vtable;
    ts4_u32 field_4;
    ts4_u32 field_8;
    ts4_u32 field_c;
    ts4_u8 field_10;
} ts4_dump_visitor;

typedef struct ts4_visitor_ref {
    ts4_dump_visitor *visitor;
} ts4_visitor_ref;

void fn_886085F0(void *owner, ts4_visitor_ref visitor, void *value);

/* Registered as Academy_InitProfile. 0x8879C0C0-0x8879C194. A2(0) N S32, upstream profile test. R=0. */
ts4_u32 ts4_script_academy_init_profile(struct TS4ScriptContext *context)
{
    ts4_s32 profile = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    if (ts4_profile_internal_is_available(g_ts4_online_state, profile, 0) == 1) {
        fn_888F3338(ts4_find_service(0xE3767AD6u), profile);
    } else {
        fn_888CFBC8(ts4_find_service(0xE3767AD6u));
    }
    return 0;
}

/* Registered as SetFreezeClothes. 0x88786330-0x8878641C. A2(0) T, A2(1) N U, guarded call. R=0. */
ts4_u32 ts4_script_set_freeze_clothes(struct TS4ScriptContext *context)
{
    ts4_u32 flag = ts4_script_string_equals(ts4_script_argument(context, 0)->payload, g_ts4_true_string);
    double number = ts4_script_number(ts4_script_argument(context, 1));
    ts4_u8 *object = lbl_88D45954;
    if (object) {
        fn_888D0F00(object, flag, ts4_script_number_to_low_word(number));
    }
    return 0;
}

/* Registered as SavingNewCreatedPlayer. 0x8877C198-0x8877C29C. A2(0) N S32, guarded calls. R=0. */
ts4_u32 ts4_script_saving_new_created_player(struct TS4ScriptContext *context)
{
    ts4_s32 player = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u8 *object = lbl_88D45B0C;
    if (object) {
        ts4_u8 *owner;
        ts4_u32 result[4];
        fn_88656900(object, 0, player);
        owner = lbl_88D459E0;
        if (*fn_88838BB8(result, owner, player) != 0xF5BF4F97u) {
            fn_88656900(object, 1, player);
        }
        if (fn_888389C0(owner, player) > 0) {
            fn_88656900(object, 3, player);
        }
    }
    return 0;
}

typedef struct ts4_objective20 {
    ts4_s32 id;
    ts4_u8 rest[0x10];
} ts4_objective20;

typedef struct ts4_objective_vector {
    ts4_objective20 *begin;
    ts4_objective20 *end;
} ts4_objective_vector;

static ts4_u32 ts4_objective_count(const ts4_objective_vector *vector)
{
    return (ts4_u32)(vector->end - vector->begin);
}

/* Registered as InitializeUnlockList. 0x887A0900-0x887A0A18. A2(0) N S32; record test; calls. R=0. */
ts4_u32 ts4_script_initialize_unlock_list(struct TS4ScriptContext *context)
{
    ts4_s32 player = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u8 *record;
    fn_8886B150(lbl_88D459D4, 0x0355373Du, 1);
    fn_88865708(lbl_88D459D4);
    record = fn_88614938(*(void **)(lbl_88D45B1C + 0x234), player);
    if (record != 0 && record[0x1A] != 0 && (ts4_u8)fn_888CDF68(player) == 0) {
        fn_8886BB78(lbl_88D459D4, player + 1);
        fn_8886B150(lbl_88D459D4, 0x0355373Du, 0);
    }
    return 0;
}

/* Swing_DLL.xex 0x88789C50-0x88789D84. */
ts4_u32 ts4_script_dlc_discovery_user(struct TS4ScriptContext *context)
{
    ts4_s32 player = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u32 flag = ts4_script_string_equals(ts4_script_argument(context, 1)->payload, g_ts4_true_string);
    void *queue = lbl_88D45A0C;
    ts4_u32 result = 1;
    if ((ts4_u8)fn_887E97E8(queue, &lbl_88C6C8FC, player, 0) == 1) {
        fn_887E98F0(queue, &lbl_88C6C8FC, player, 0);
        result = 0;
    } else if ((ts4_u8)fn_887E9860(queue, &lbl_88C6C8FC, player, 0) == 0) {
        ts4_u8 *request = fn_88215110(player);
        request[0x20] = (ts4_u8)flag;
        fn_887EA280(queue, request, 0);
    }
    return result;
}

typedef struct ts4_title_request {
    ts4_u8 head[0x2AC];
    ts4_u32 value;
    ts4_u32 magic;
} ts4_title_request;

