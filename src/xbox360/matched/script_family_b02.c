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
extern ts4_u8 *lbl_88D45954;
extern ts4_u8 *lbl_88D4588C;
extern ts4_u8 *lbl_88D4587C;
extern ts4_u8 *lbl_88D45B1C;
extern ts4_u8 *g_ts4_session_context;
ts4_u32 fn_888CDF68(ts4_s32 user);
ts4_u32 fn_8886B230(ts4_u32 value);
void fn_888EC458(ts4_s32 value);
void fn_888F08A0(ts4_u32 value);
void fn_888C84E8(void *object, ts4_s32 value);
void fn_888E9898(void *object, ts4_u32 value);

/* Registered as Core_Memory_EnableTracking. 0x8877C398-0x8877C3E8. */
ts4_u32 ts4_script_core_memory_enable_tracking(struct TS4ScriptContext *context)
{
    ts4_script_string_equals(ts4_script_argument(context, 0)->payload, g_ts4_true_string);
    return 0;
}

/* Registered as TCR_SaveTournament. 0x8877A710-0x8877A764. */
ts4_u32 ts4_script_tcr_save_tournament(struct TS4ScriptContext *context)
{
    ts4_script_string_equals(ts4_script_argument(context, 1)->payload, g_ts4_true_string);
    return 0;
}

/* Registered as EnableMoveBinding. 0x8877A7E0-0x8877A834. */
ts4_u32 ts4_script_enable_move_binding(struct TS4ScriptContext *context)
{
    ts4_script_string_equals(ts4_script_argument(context, 1)->payload, g_ts4_true_string);
    return 1;
}

/* Registered as Debug_HotSpotsInfosOnOff. 0x8877BB60-0x8877BBC0. */
ts4_u32 ts4_script_debug_hot_spots_infos_on_off(struct TS4ScriptContext *context)
{
    ts4_u32 flag = ts4_script_string_equals(ts4_script_argument(context, 0)->payload, g_ts4_true_string);
    lbl_88D45954[0x38] = (ts4_u8)flag;
    return 0;
}

/* Registered as IsAGuestOffline. 0x88783FD8-0x88784064. */
ts4_u32 ts4_script_is_a_guest_offline(struct TS4ScriptContext *context)
{
    return fn_888CDF68(ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0))));
}

/* Registered as IncAndCheckSparringPartnerTrainings. 0x8879EC78-0x8879ED04. */
ts4_u32 ts4_script_inc_and_check_sparring_partner_trainings(struct TS4ScriptContext *context)
{
    return fn_8886B230(ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0))));
}

/* Registered as InitCategories. 0x887970D8-0x88797168. */
ts4_u32 ts4_script_init_categories(struct TS4ScriptContext *context)
{
    fn_888EC458(ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0))));
    return 0;
}

/* Registered as InitOutfitType. 0x88798BD0-0x88798C60. */
ts4_u32 ts4_script_init_outfit_type(struct TS4ScriptContext *context)
{
    fn_888F08A0(ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0))));
    return 0;
}

/* Registered as RestoreHotSpot. 0x88782FF8-0x88783090. */
ts4_u32 ts4_script_restore_hot_spot(struct TS4ScriptContext *context)
{
    fn_888C84E8(lbl_88D45954, ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0))));
    return 0;
}

/* Registered as BackupFreeFormSlider. 0x88796AB0-0x88796B48. */
ts4_u32 ts4_script_backup_free_form_slider(struct TS4ScriptContext *context)
{
    fn_888E9898(lbl_88D45954, ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0))));
    return 0;
}
