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
void *ts4_find_service(ts4_u32 id);
extern ts4_u8 *lbl_88D45870;
extern ts4_u8 *lbl_88D4593C;
extern ts4_u8 *lbl_88D45954;
void fn_888DBFC0(ts4_u32 count);
void fn_888C8370(void *object, ts4_s32 value);

/* Registered as EnableMoveCalibration. 0x8877A788-0x8877A7DC. */
ts4_u32 ts4_script_enable_move_calibration(struct TS4ScriptContext *context)
{
    ts4_script_string_equals(ts4_script_argument(context, 1)->payload, g_ts4_true_string);
    return 1;
}

/* Registered as SetPlayerRotation. 0x8877B7F0-0x8877B86C. */
ts4_u32 ts4_script_set_player_rotation(struct TS4ScriptContext *context)
{
    double number = ts4_script_number(ts4_script_argument(context, 0));
    *(float *)(*(ts4_u8 **)(lbl_88D45954 + 0x80) + 0x80) = (float)number;
    return 0;
}

/* Registered as FacialSetNumPlayers. 0x8878AAC0-0x8878AB50. */
ts4_u32 ts4_script_facial_set_num_players(struct TS4ScriptContext *context)
{
    fn_888DBFC0(ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0))));
    return 0;
}

/* Registered as SaveHotSpotInHistory. 0x88782F60-0x88782FF8. */
ts4_u32 ts4_script_save_hot_spot_in_history(struct TS4ScriptContext *context)
{
    fn_888C8370(lbl_88D45954, ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0))));
    return 0;
}

/* Registered as OnlineSparring_SetDifficulty. 0x88783960-0x88783A18. */
ts4_u32 ts4_script_online_sparring_set_difficulty(struct TS4ScriptContext *context)
{
    double number = ts4_script_number(ts4_script_argument(context, 0));
    ts4_u8 *service = (ts4_u8 *)ts4_find_service(0x347BF406u);
    if (service) {
        ts4_u8 *record = *(ts4_u8 **)(service + 0x24) + 0x214;
        *(ts4_u32 *)(record + *(ts4_s32 *)record + 0x24) = ts4_script_number_to_low_word(number);
    }
    return 0;
}

/* Registered as IsBissextile. 0x8877BA30-0x8877BAEC: argument 0 is a year
 * offset from 1900. */
ts4_u32 ts4_script_is_bissextile(struct TS4ScriptContext *context)
{
    ts4_u32 year = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0))) + 1900;
    ts4_u8 leap = ((year & 3) == 0 && year % 100 != 0) || year % 400 == 0;
    return leap;
}
