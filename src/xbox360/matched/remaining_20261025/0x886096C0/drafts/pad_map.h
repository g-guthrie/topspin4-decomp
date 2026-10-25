/*
 * Provisional guest declarations for independently checked exact-code units.
 * Type roles, layouts and signatures remain inferred, not original ABI proof.
 * This header carries no separate function or behavior credit; each unit
 * manifest pins its complete source/header dependency closure.
 */
#ifndef TS4_DRAFTS_INPUT_PAD_MAP_H
#define TS4_DRAFTS_INPUT_PAD_MAP_H

typedef unsigned char ts4_u8;
typedef unsigned short ts4_u16;
typedef short ts4_s16;
typedef unsigned int ts4_u32;

/*
 * Swing_DLL.xex 0x8856ABA0: byte fill (dst, value, count); returns dst
 * unchanged. Only the call made by the reset (4-byte-aligned dst, value 0,
 * count 0x30) is relied on here.
 */
void *fn_8856ABA0(void *dst, ts4_u32 value, ts4_u32 count);

void fn_886095B8(ts4_u8 *map, ts4_u32 channel, ts4_u8 value);
void fn_886094C8(ts4_u8 *map, ts4_u32 axis, ts4_s16 value);
/*
 * Declared void: no recorded direct caller reads a result (a reconstruction
 * choice, not a proven original signature). The compiled code still leaves
 * the byte fill's result, map + 0x30, in the return register.
 */
void fn_886096C0(ts4_u8 *map);

#endif
