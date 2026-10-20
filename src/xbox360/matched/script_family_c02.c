/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Functions in this file compile to exact objdiff matches with the Xbox 360
 * compiler (see docs/matching-build.md). They were written from the disassembly
 * of the retail module with AI assistance; names, types and field roles are
 * reconstructions, and each function states its address range.
 */
#include "script_argument_helpers.h"

void *ts4_find_service(ts4_u32 id);
extern ts4_u8 *g_ts4_online_context;
extern ts4_u8 *g_ts4_online_state;
extern ts4_u8 *lbl_88D45954;
extern ts4_u8 *lbl_88D459DC;
extern ts4_u8 *lbl_88D459E0;
extern ts4_u8 *lbl_88D45A60;
extern ts4_u8 *lbl_88D45B0C;
extern ts4_u8 *lbl_88D45B1C;
extern ts4_u8 *lbl_88D45B30;
void fn_889A6BE0(void *service, ts4_u32 value);
void *fn_88614938(void *object, ts4_s32 index);
void fn_8857A6A8(ts4_s32 value);
ts4_u32 *fn_88165170(ts4_u32 *first, ts4_u32 *last, const ts4_u32 *value);
ts4_u32 fn_8899CA48(void *object, ts4_u32 *value);
void *fn_88838C40(void *object, ts4_u32 index);
void fn_88656FD0(void *object, void *counter, ts4_u32 flags);
void fn_888C8EB8(void *object, ts4_s32 value);
ts4_u8 fn_88865388(void *object, ts4_u32 zero, ts4_s32 value, ts4_u8 *flag);
void fn_8886ACB0(void *object);
void fn_889ACF20(void *entry);
ts4_u32 fn_88885228(ts4_u32 value);
void fn_88868008(void);
void *fn_887ADEB8(void *object, ts4_s32 value, ts4_u32 flag);
void fn_887993C8(void *object, void *pad);
void *fn_888E1D40(void);
ts4_u8 *fn_881877A8(void *map, ts4_u32 *key);
void fn_888C8190(void *object);
void fn_88848698(void *entry, ts4_u32 zero);
void fn_8883CB50(ts4_s32 id);
void fn_888C93E8(void *object);

/* Registered as ProChallenge_GetMyStats. 0x887874E0-0x8878758C. A2(0) N, find_service, guarded call(svc,U) R=0. */
ts4_u32 ts4_script_pro_challenge_get_my_stats(struct TS4ScriptContext *context)
{
    double number = ts4_script_number(ts4_script_argument(context, 0));
    void *service = ts4_find_service(0x061B4A78u);
    if (service) {
        fn_889A6BE0(service, ts4_script_number_to_low_word(number));
    }
    return 0;
}

/* Registered as ShowUIAchievements. 0x8877B138-0x8877B1EC. A2(0) N S32, call, conditional field or -1, call R=0. */
ts4_u32 ts4_script_show_ui_achievements(struct TS4ScriptContext *context)
{
    ts4_s32 index = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u8 *entry = (ts4_u8 *)fn_88614938(*(void **)(lbl_88D45B1C + 0x234), index);
    fn_8857A6A8(entry ? *(ts4_s32 *)(entry + 0x10) : -1);
    return 0;
}

/* Registered as TSU_CheckCharacterChange. 0x8877FC10-0x8877FCCC. A2(1) N, guarded call(G,&U) result, else 1. */
ts4_u32 ts4_script_tsu_check_character_change(struct TS4ScriptContext *context)
{
    double number = ts4_script_number(ts4_script_argument(context, 1));
    ts4_u8 *online = g_ts4_online_context;
    if (online) {
        ts4_u32 value = ts4_script_number_to_low_word(number);
        return fn_8899CA48(online, &value);
    }
    return 1;
}

/* Registered as IsPackageNotReadyToUse. 0x8877C740-0x8877C808. A2(0) N U, find_service(U), state != 7. */
ts4_u32 ts4_script_is_package_not_ready_to_use(struct TS4ScriptContext *context)
{
    ts4_u32 id = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u32 not_ready = 0;
    ts4_u8 *package = (ts4_u8 *)ts4_find_service(id);
    if (package) {
        not_ready = *(ts4_u32 *)(package + 0x38) != 7;
    }
    return not_ready;
}

/* Registered as ProChallenge_ReadStatsFriends. 0x8878AB50-0x8878AC3C. A2(1) N S32, find_service guard, pointer-list search + call R=0. */
ts4_u32 ts4_script_pro_challenge_read_stats_friends(struct TS4ScriptContext *context)
{
    ts4_s32 id = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 1)));
    if (ts4_find_service(0x061B4A78u)) {
        ts4_u8 *list = *(ts4_u8 **)(g_ts4_online_state + 0x1c);
        ts4_u8 **end = *(ts4_u8 ***)(list + 0x8);
        ts4_u8 **it = *(ts4_u8 ***)(list + 0x4);
        for (; it != end; it++) {
            if (id == *(ts4_s32 *)(*it + 0x4)) {
                fn_889ACF20(*it);
                break;
            }
        }
    }
    return 0;
}

/* Registered as TCR_CheckDeviceSpace. 0x8877A608-0x8877A6F8. A2(1) N U compare, 8-byte entry search, call result. */
ts4_u32 ts4_script_tcr_check_device_space(struct TS4ScriptContext *context)
{
    ts4_u32 device = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 1)));
    ts4_u8 *tcr;
    ts4_u32 *end;
    ts4_u32 *it;
    ts4_u32 value;
    ts4_u32 result = 1;
    if (device == 0x14B75F81u) {
        tcr = lbl_88D45B30;
        value = 0;
        end = *(ts4_u32 **)(tcr + 0x20);
        it = *(ts4_u32 **)(tcr + 0x1c);
        for (; end != it; it += 2) {
            if (it[0] == 0) {
                value = it[1];
                break;
            }
        }
        result = fn_88885228(value);
    }
    return result;
}

/* Registered as TCR_SetMasterPadForInvitation. 0x887AE318-0x887AE3D0. A2(0) N held across a call, S32, nested calls R=0. */
ts4_u32 ts4_script_tcr_set_master_pad_for_invitation(struct TS4ScriptContext *context)
{
    double number = ts4_script_number(ts4_script_argument(context, 0));
    fn_88868008();
    fn_887993C8(lbl_88D45A60, fn_887ADEB8(0, ts4_script_number_to_s32(number), 1));
    return 0;
}

/* Registered as PlayerCreatedId_Destroy. 0x88794908-0x887949F8. A2(0) N S32, pointer-list search, three calls R=0. */
ts4_u32 ts4_script_player_created_id_destroy(struct TS4ScriptContext *context)
{
    ts4_s32 id = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u8 *found = 0;
    ts4_u8 *players = lbl_88D459E0;
    ts4_u8 **end = *(ts4_u8 ***)(players + 0x24);
    ts4_u8 **it = *(ts4_u8 ***)(players + 0x20);
    for (; it != end; it++) {
        if (*(ts4_s32 *)(*it + 0x180) == id) {
            found = *it;
            break;
        }
    }
    fn_88848698(found, 0);
    fn_8883CB50(id);
    fn_888C93E8(lbl_88D45954);
    return 0;
}
