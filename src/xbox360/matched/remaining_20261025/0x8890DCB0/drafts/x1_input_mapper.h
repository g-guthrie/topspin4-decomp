/*
 * Provisional guest declarations for independently checked exact-code units.
 * Type roles, layouts and signatures remain inferred, not original ABI proof.
 * This header carries no separate function or behavior credit; each unit
 * manifest pins its complete source/header dependency closure.
 */
#ifndef TS4_DRAFT_X1_INPUT_MAPPER_H
#define TS4_DRAFT_X1_INPUT_MAPPER_H

#include "s1_input_common.h" /* S1 (validated, reused read-only): ts4_u8 .. ts4_s64, g_ts4_event_value */

extern void *lbl_88D45B1C; /* game object; +0x234 = input manager [I: lis/lwz 0x5B1C, lwz 0x234 in 0x8890DCC8] */

void fn_8890DB90(ts4_u8 *entry, ts4_u8 *binding, ts4_u8 value);
void fn_8890DCB0(ts4_u8 *entry, ts4_u8 *binding);
float fn_8890D5F0(const ts4_u8 *map, ts4_s32 id);
void fn_8890DCC8(ts4_u8 *mapper);

#endif
