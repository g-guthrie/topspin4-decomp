/*
 * Provisional guest declarations for independently checked exact-code units.
 * Type roles, layouts and signatures remain inferred, not original ABI proof.
 * This header carries no separate function or behavior credit; each unit
 * manifest pins its complete source/header dependency closure.
 */
#ifndef TS4_SR_COMMON_H
#define TS4_SR_COMMON_H

#include "guest_std.h"
#include "guest_std.h"

typedef uint8_t sr_u8;
typedef uint16_t sr_u16;
typedef uint32_t sr_u32;
typedef int32_t sr_s32;

#define SR_U8(p, o) (*(sr_u8 *)((sr_u8 *)(p) + (o)))
#define SR_U32(p, o) (*(sr_u32 *)((sr_u8 *)(p) + (o)))
#define SR_PTR(p, o) (*(sr_u8 **)((sr_u8 *)(p) + (o)))
/* Reconstruction note: TARGET-SPECIFIC. On the Xbox 360 (PowerPC, 32-bit guest pointers)
 * sr_u32 is exactly 32 bits and a guest pointer is a 32-bit word; SR_GUEST_PTR converts a guest 32-bit word that was
 * loaded from memory into the target pointer type (the original zero-extends it: rlwinm rX,rX,0,0,31). This is not a
 * portable host-pointer truncation and makes no 64-bit claim; the host differential harness (i686, 32-bit pointers)
 * uses it only as an adapter. */
#define SR_GUEST_PTR(word32) ((sr_u8 *)(word32))

static __inline float sr_f(sr_u32 bits) { float f; memcpy(&f, &bits, 4); return f; }
static __inline sr_u32 sr_b(float f) { sr_u32 b; memcpy(&b, &f, 4); return b; }
static __inline float sr_fld(const void *p, int o) { sr_u32 b; memcpy(&b, (const sr_u8 *)p + o, 4); return sr_f(b); }
static __inline void sr_fst(void *p, int o, float f) { sr_u32 b = sr_b(f); memcpy((sr_u8 *)p + o, &b, 4); }
static __inline int sr_nan(float f) { return f != f; }

/* The fsel clamp idiom of the original: idx = (x < 0 || unordered) ? -1.0 : 1.0 from the table at 0x880D0FD8, then
 * fsel(idx, a, b) = idx >= 0 ? a : b. */
static __inline float sr_sel_nonneg(float x, float if_nonneg, float otherwise)
{
    return (x < 0.0f || sr_nan(x)) ? otherwise : if_nonneg;
}

#define SR_OWNER_S(s) SR_PTR(SR_PTR((s), 0x1C), 8)
#define SR_P(o) SR_PTR((o), 0x74)
#define SR_NOW(o) SR_U32(SR_PTR(SR_PTR((o), 0x48), 0x30), 0x310)
#define SR_M44(o) SR_PTR(SR_PTR((o), 0x48), 0x44)

static __inline sr_u8 *sr_player_entry(sr_u8 *owner)
{
    sr_u8 *base = SR_M44(owner) + 0x104;
    return base + SR_U32(base, 0) + (sr_u32)SR_U32(owner, 0x14) * 0x140u;
}

/* constants loaded by the original instructions (address of the word in the image) */
#define SR_K_ZERO 0x00000000u        /* 0x8814B440  0.0 */
#define SR_K_ONE 0x3F800000u         /* 0x880D0F70  1.0 */
#define SR_K_PI 0x40490FDBu          /* 0x880C88DC  3.1415927 */
#define SR_K_TWO_PI 0x40C90FDBu      /* 0x880C8F18  6.2831855 */
#define SR_K_NEG_PI 0xC0490FDBu      /* 0x880D12D0 -3.1415927 */
#define SR_K_0_2 0x3E4CCCCDu         /* 0x880D107C  0.2 */
#define SR_K_0_8 0x3F4CCCCDu         /* 0x880D1080  0.8 */
#define SR_K_0_6 0x3F19999Au         /* 0x880D1084  0.6 */
#define SR_K_0_1 0x3DCCCCCDu         /* 0x880D121C  0.1 */
#define SR_K_0_9999 0x3F7FF972u      /* 0x880D12E0  0.9999 */

/* ---- drafts (prototypes; definitions in the per-function files) */
void fn_88696020(sr_u8 *s);
void fn_88681B80(sr_u8 *s);
void fn_8865AE10(sr_u8 *s);
void fn_88659BB0(sr_u8 *s);
sr_u8 *fn_88659C48(sr_u8 *s); /* Reconstruction note: returns its argument */
void fn_8826B640(sr_u8 *sub);
sr_u32 fn_88681958(sr_u8 *s, sr_u32 state);
void fn_88681848(sr_u8 *s, sr_u32 state);
sr_u32 fn_88672750(sr_u8 *s, sr_u8 *desc);
void fn_8817B608(sr_u32 *value_bits);
void fn_88681AE0(sr_u8 *s);
void fn_88696170(sr_u8 *s);
void fn_886B7D50(sr_u8 *e);
void fn_8826D9D0(sr_u8 *e, sr_u32 *state);
void fn_886B2638(sr_u8 *e);
void fn_886723A8(sr_u32 t_bits, sr_u8 *e);
void fn_8865AD50(sr_u8 *e);
void fn_88672548(sr_u8 *e);
void fn_8865ADA0(sr_u8 *e);

/* ---- callee entry points (hook stubs or drafts; defined by hooks/sr_hooks.h) */
void ts4_memset(sr_u8 *dst, sr_u32 value, sr_u32 count);
void fn_8826D9D0(sr_u8 *e, sr_u32 *state);
void fn_886B2638(sr_u8 *e);
void fn_8865AD50(sr_u8 *e);
void fn_88662F60(sr_u8 *e);
void fn_886A5718(sr_u8 *owner, sr_u32 *event, sr_u32 now);
sr_u32 fn_8890DB38(sr_u8 *mapper);
void fn_886A5BB0(sr_u8 *owner, const sr_u8 *vector16);
void fn_886723A8(sr_u32 t_bits, sr_u8 *e);
sr_u32 fn_8826C388(sr_u8 *table, sr_u32 *key);
sr_u32 fn_881899D8(sr_u32 x_bits, sr_u32 curve);
void fn_886A16D8(sr_u8 *a, sr_u8 *owner, sr_u32 flag);
void fn_886B0490(sr_u8 *owner);
void fn_8865ED78(sr_u8 *owner);
void fn_88662B60(sr_u8 *p);

#endif
