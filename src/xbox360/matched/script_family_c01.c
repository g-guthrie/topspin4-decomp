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
extern ts4_u8 *g_ts4_session_context;
extern ts4_u8 *g_ts4_session_state;
extern ts4_u8 *g_ts4_title_server;
extern ts4_u8 *lbl_88D45954;
extern ts4_u8 *lbl_88D45A04;
extern ts4_u8 *lbl_88D4594C;
extern ts4_u8 *lbl_88D45B0C;
void fn_888C9178(void *object, ts4_u32 flag);
void fn_889A4AE0(void *object, ts4_u32 flag);
void fn_8886B388(ts4_u32 value);
void fn_888FF488(ts4_u32 value);
ts4_u32 fn_887EA5C8(void *object, ts4_s32 value);
void fn_888C8660(void *object, ts4_s32 value);
void fn_888C8878(void *object, ts4_u32 value);
void fn_888E01E0(void *object, ts4_s32 value);
void fn_888E04C8(void *object, ts4_s32 value);
void fn_888E9930(void *object, ts4_u32 value);
void fn_888E9A50(void *object, ts4_u32 value);
void fn_888FF5C0(void *object, ts4_s32 value);
void fn_88931FE0(void *object, ts4_u32 *value);
void fn_886570B8(void *object, ts4_u32 value);
void fn_889B0F70(void *object, ts4_s32 value);

/* Registered as FreezeMainCamera. 0x88782D18-0x88782D78. A2(0) T call R=0. */
ts4_u32 ts4_script_freeze_main_camera(struct TS4ScriptContext *context)
{
    fn_888C9178(lbl_88D45954, ts4_script_string_equals(ts4_script_argument(context, 0)->payload, g_ts4_true_string));
    return 0;
}

/* Registered as DEBUG_SimulateMatch. 0x887875C8-0x88787638. A2(0) T, guarded call R=0. */
ts4_u32 ts4_script_debug_simulate_match(struct TS4ScriptContext *context)
{
    ts4_u32 flag = ts4_script_string_equals(ts4_script_argument(context, 0)->payload, g_ts4_true_string);
    ts4_u8 *object = *(ts4_u8 **)(g_ts4_session_context + 0x1c);
    if (object) {
        fn_889A4AE0(object, flag);
    }
    return 0;
}

/* Registered as Debug_SetEasyAchievements. 0x8879ED08-0x8879ED98. A2(0) N U call R=0. */
ts4_u32 ts4_script_debug_set_easy_achievements(struct TS4ScriptContext *context)
{
    fn_8886B388(ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0))));
    return 0;
}

/* Registered as FillItemInfosUI. 0x887A3280-0x887A3310. A2(0) N U call R=0. */
ts4_u32 ts4_script_fill_item_infos_ui(struct TS4ScriptContext *context)
{
    fn_888FF488(ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0))));
    return 0;
}

/* Registered as DLC_IsUserDiscovered. 0x88780C90-0x88780D24. A2(0) N S32 call, returns the callee's result. */
ts4_u32 ts4_script_dlc_is_user_discovered(struct TS4ScriptContext *context)
{
    return fn_887EA5C8(lbl_88D45A04, ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0))));
}

/* Registered as BackupHotSpot. 0x88783090-0x88783128. A2(0) N S32 call R=0. */
ts4_u32 ts4_script_backup_hot_spot(struct TS4ScriptContext *context)
{
    fn_888C8660(lbl_88D45954, ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0))));
    return 0;
}

/* Registered as ClearCustomPreset. 0x88783228-0x887832C0. A2(0) N U call R=0. */
ts4_u32 ts4_script_clear_custom_preset(struct TS4ScriptContext *context)
{
    fn_888C8878(lbl_88D45954, ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0))));
    return 0;
}

/* Registered as HighlightVertex. 0x887949F8-0x88794A90. A2(0) N S32 call R=0. */
ts4_u32 ts4_script_highlight_vertex(struct TS4ScriptContext *context)
{
    fn_888E01E0(lbl_88D45954, ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0))));
    return 0;
}

/* Registered as ResetVertex. 0x88794A90-0x88794B28. A2(0) N S32 call R=0. */
ts4_u32 ts4_script_reset_vertex(struct TS4ScriptContext *context)
{
    fn_888E04C8(lbl_88D45954, ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0))));
    return 0;
}

/* Registered as DecreaseFreeFormSlider. 0x88796B48-0x88796BE0. A2(0) N U call R=0. */
ts4_u32 ts4_script_decrease_free_form_slider(struct TS4ScriptContext *context)
{
    fn_888E9930(lbl_88D45954, ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0))));
    return 0;
}

/* Registered as IncreaseFreeFormSlider. 0x88796BE0-0x88796C78. A2(0) N U call R=0. */
ts4_u32 ts4_script_increase_free_form_slider(struct TS4ScriptContext *context)
{
    fn_888E9A50(lbl_88D45954, ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0))));
    return 0;
}

/* Registered as InitLockerRoom. 0x887A3310-0x887A33A8. A2(0) N S32 call R=0. */
ts4_u32 ts4_script_init_locker_room(struct TS4ScriptContext *context)
{
    fn_888FF5C0(lbl_88D4594C, ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0))));
    return 0;
}

/* Registered as CancelCommands. 0x8877BEB8-0x8877BF58. A2(0) N U, value passed by address, R=0. */
ts4_u32 ts4_script_cancel_commands(struct TS4ScriptContext *context)
{
    ts4_u32 value = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0)));
    fn_88931FE0(g_ts4_session_state, &value);
    return 0;
}

/* Registered as TitleServer_IsLoggedIn. 0x8877F6B8-0x8877F758. A2(0) N S32 compare, R=1/0 (leaf). */
ts4_u32 ts4_script_title_server_is_logged_in(struct TS4ScriptContext *context)
{
    double number = ts4_script_number(ts4_script_argument(context, 0));
    ts4_u8 *server = g_ts4_title_server;
    if (server && *(ts4_s32 *)(server + 0xbc) == ts4_script_number_to_s32(number) && *(ts4_u32 *)(server + 0xb0) != 0) {
        return 1;
    }
    return 0;
}

/* Registered as DataMining_PrintAllPlayerCounters. 0x88780D28-0x88780DC8. A2(0) N U guarded call R=0. */
ts4_u32 ts4_script_data_mining_print_all_player_counters(struct TS4ScriptContext *context)
{
    double number = ts4_script_number(ts4_script_argument(context, 0));
    ts4_u8 *object = lbl_88D45B0C;
    if (object) {
        fn_886570B8(object, ts4_script_number_to_low_word(number));
    }
    return 0;
}

/* Registered as KickUser. 0x8878E3D8-0x8878E47C. A2(0) N S32 guarded call R=0. */
ts4_u32 ts4_script_kick_user(struct TS4ScriptContext *context)
{
    double number = ts4_script_number(ts4_script_argument(context, 0));
    ts4_u8 *object = *(ts4_u8 **)(g_ts4_session_context + 0x1c);
    if (object) {
        fn_889B0F70(object, ts4_script_number_to_s32(number));
    }
    return 0;
}
