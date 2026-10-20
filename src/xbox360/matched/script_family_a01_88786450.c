/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Functions in this file compile to exact objdiff matches with the Xbox 360
 * compiler (see docs/matching-build.md). They were written from the disassembly
 * of the retail module with AI assistance; names, types and field roles are
 * reconstructions, and each function states its address range.
 */
#include "script_argument_helpers.h"

extern ts4_u8 *lbl_88D459DC;
extern void *lbl_88D45A04;
extern void *lbl_88D45894;
extern void *lbl_88D45944;
extern ts4_u8 *lbl_88D45B1C;
extern ts4_u8 *lbl_88D459E0;
extern void *lbl_88D45960;
extern ts4_u8 *g_ts4_session_context;

void *ts4_find_service(ts4_u32 service_id);
void ts4_object_finalize(void *object);
void fn_887EB4A0(void *owner, void *object);
void fn_8864A1E0(void *service, ts4_u32 enable, ts4_u32 key, ts4_u32 id);
void fn_888EE0E8(void *players, ts4_u32 value);
void fn_8896BE28(void *object);
void fn_88855170(void *locker, ts4_s32 slot, ts4_u32 a, ts4_u32 b, ts4_u32 c, ts4_u32 d);
void fn_889A5200(void *lobby, ts4_s32 player, ts4_u32 ready, ts4_u32 flags);
ts4_u32 *fn_8883B578(void *outfit, ts4_s32 type);
void fn_88853540(void *racket, ts4_s32 index, ts4_u32 value);
ts4_u8 fn_88865388(void *dlc, ts4_u32 mode, ts4_s32 index, ts4_u8 *done);
void fn_888C7C28(void *presence, ts4_u32 *value);

/* Registered as TopOutfit_RestoreClothType. 0x88786450-0x88786500. */
ts4_u32 ts4_script_top_outfit_restore_cloth_type(struct TS4ScriptContext *context)
{
    double number = ts4_script_number(ts4_script_argument(context, 0));
    ts4_u8 *outfit = lbl_88D459E0;
    ts4_u32 saved = *(ts4_u32 *)(outfit + 0x4C);
    if (!saved) {
        return 0;
    }
    *fn_8883B578(outfit, ts4_script_number_to_s32(number)) = saved;
    return 0;
}

