/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Functions in this file compile to exact objdiff matches with the Xbox 360
 * compiler (see docs/matching-build.md). They were written from the disassembly
 * of the retail module with AI assistance; names, types and field roles are
 * reconstructions, and each function states its address range.
 */
#include "script_argument_helpers.h"

typedef void (*ts4_script_sound_fn)(void *object, ts4_u32 *value);

extern ts4_u8 *lbl_88D45A64;

/* Registered as StopSound. 0x8877C668-0x8877C71C. A2(0) N U-ADDR, guarded indirect call through slot 0x34 of G, R=0. */
ts4_u32 ts4_script_stop_sound(struct TS4ScriptContext *context)
{
    ts4_u32 value = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0)));
    void *object = lbl_88D45A64;
    if (object != 0) {
        ts4_script_sound_fn *dispatch = *(ts4_script_sound_fn **)object;
        dispatch[0x34 / sizeof(ts4_script_sound_fn)](object, &value);
    }
    return 0;
}
