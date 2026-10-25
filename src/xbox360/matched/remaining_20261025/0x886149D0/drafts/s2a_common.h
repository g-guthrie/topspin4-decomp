/*
 * Provisional guest declarations for independently checked exact-code units.
 * Type roles, layouts and signatures remain inferred, not original ABI proof.
 * This header carries no separate function or behavior credit; each unit
 * manifest pins its complete source/header dependency closure.
 */
#ifndef TS4_DRAFT_S2A_COMMON_H
#define TS4_DRAFT_S2A_COMMON_H

#include "script_argument_helpers.h" /* T10F (reused, validated) */
#include "s1_input_common.h" /* S1 (validated, reused via -I batches/S1/drafts) + typed_handle.h */

extern void *lbl_88D45B1C;                         /* holds the input manager at +0x234 */
extern const ts4_u16 *g_ts4_kernel_version_import; /* symbols.txt __imp_XboxKrnlVersion (0x88000874) */

/* validated T10F draft 0x88614938 (runtime_keyed_lookups.c): record whose key +0x0C equals key, or 0 */
ts4_u8 *fn_88614938(void *manager, ts4_u32 key);
/* 0x88606D18 (new hook): map threshold reset, the tail of S1 0x886096C0 [I: listing] */
void fn_88606D18(ts4_u8 *map);
/* 0x88627EC0 (new hook): device base-of-base init, handle by value (r4, upper r5) [I: caller] */
void fn_88627EC0(ts4_u8 *device, ts4_typed_handle config);
/* 0x88150770 (T10F validated draft fn_88150770; hooked): writes a 3-word result
 * {owner, index, extra} through r3 for the iterator at r4; the third argument is forwarded opaquely - here
 * the address of a 32-bit key [I: caller sets r5 = &key] */
ts4_typed_handle *fn_88150770(ts4_typed_handle *result, const ts4_typed_handle *iterator, const ts4_u32 *key);
/* 0x88163C60 (new hook): reads a value through a valid result handle; its low byte is stored [I] */
ts4_u32 fn_88163C60(const ts4_typed_handle *result);
/* imports (symbols.txt): XamInputGetCapabilities 0x88AFFCD0, XamInputSetState 0x88AFFCF0 */
ts4_u32 XamInputGetCapabilities(ts4_u32 user, ts4_u32 flags, ts4_u8 *capabilities);
ts4_u32 XamInputSetState(ts4_u32 user, ts4_u32 zero, ts4_u8 *vibration, ts4_u32 zero_a, ts4_u32 zero_b,
                         ts4_u32 zero_c);

/* the six S2a drafts */
ts4_u32 fn_8877A878(struct TS4ScriptContext *context);
ts4_u32 fn_8877AA58(struct TS4ScriptContext *context);
void fn_886149D0(ts4_u8 *manager, ts4_u32 first, ts4_u32 second);
ts4_u8 *fn_88614C50(ts4_u8 *map);
void fn_88628D48(ts4_u8 *device, ts4_typed_handle config);
ts4_u32 fn_8857B180(ts4_u32 user, const ts4_u8 *vibration);

/* Direction hashes shared by both natives [I]; their names are [H]. Y axis = base + 1, X axis = base. */
#define TS4_DIR_Y_NEGATIVE 0xD610CAD2u
#define TS4_DIR_Y_POSITIVE 0xBCCD3F05u
#define TS4_DIR_X_POSITIVE 0x750B5A10u
#define TS4_DIR_X_NEGATIVE 0xDA554856u

/* Inlined in both natives [I: identical instruction sequences after the hash switch]: look the pad up,
 * reject a disconnected map (status bit 4), then compare the axis value with the +-5000 dead zone
 * (strict: > 5000 for the positive direction, < -5000 for the negative one). No null test of the map;
 * a missing record gives index -1, i.e. the map 0xC4 bytes before the array [I: li -1; mulli 0xC4]. */
static ts4_u32 ts4_script_axis_beyond_dead_zone(ts4_u32 pad, ts4_u32 axis, ts4_u8 positive)
{
    ts4_u8 *manager = *(ts4_u8 **)((ts4_u8 *)lbl_88D45B1C + 0x234);
    ts4_u8 *record = fn_88614938(manager, pad);
    ts4_s32 index = record ? *(ts4_s32 *)(record + 0x10) : -1;
    ts4_u8 *map = *(ts4_u8 **)(manager + 0x3C) + index * 0xC4;
    ts4_s16 value;
    if ((*(ts4_u32 *)(map + 0xBC) & 4) == 4) {
        return 0;
    }
    value = *(ts4_s16 *)(map + (axis + 0x21) * 4);
    if (value > 5000 && positive != 0) {
        return 1;
    }
    if (value < -5000 && positive == 0) {
        return 1;
    }
    return 0;
}

#endif
