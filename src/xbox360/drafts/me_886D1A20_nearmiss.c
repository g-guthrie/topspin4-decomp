/* 0x886D1A20 near miss (80 off, /Oc plain C). Resets the state block at owner->states+0x120 (vector 880FC650 x3,
 * zero lbl_8814B440, one g_ts4_script_constants[0], eight -1 slots, keeps byte +0x2D) then looks up its record by hash
 * (0x3E4C9599 if owner+0x554 else 0x07791D49) via fn_88645A68. Target emits stores strictly in field order with dead
 * addi s+0x40 / s+0x80 (inline C++ sub-object ctors?). Tried: field-order C, /Os /O2 /O1, LTCG, C++ placement-new with
 * forceinline Head/Sub40/Sub80 ctors (gets the s+0x40 addi but 87-90 off). */
#include "vx1_vector.h"
typedef unsigned int u32; typedef unsigned char u8;
extern const __vector4 lbl_880FC650;
extern const float lbl_8814B440;
extern const float g_ts4_script_constants[];
typedef struct Registry { void *impl; } Registry;
typedef struct Mid { char p[0x94]; Registry *registry; } Mid;
void *fn_88645A68(void *impl, void *key);
typedef struct State {
    __vector4 v0; float f10[6]; u8 b28; char _29[3]; u8 b2c, b2d, b2e, b2f, b30; char _31[0xF];
    float f40[5]; u8 b54, b55; char _56[2]; int i58[8]; u8 b78; char _79[7];
    __vector4 v80[2]; u32 a0; float a4, a8, ac, b0, b4; u8 b8[7]; char _bf; float c0; char _c4[0xC]; void *record;
} State;
typedef struct Owner2 { char _0[0x14]; char *states; char _18[8]; Mid *mid; char _24[0x530]; u8 alt; } Owner2;
typedef struct Self { char _0[8]; Owner2 *owner; } Self;
void ts4_state_reset_886D1A20(Self *self)
{
    Mid *mid = self->owner->mid;
    State *s = (State *)(self->owner->states + 0x120);
    __vector4 c0 = lbl_880FC650;
    __vector4 c1 = c0, c2 = c0;
    float zero = lbl_8814B440;
    float one = g_ts4_script_constants[0];
    u32 key, k;
    u8 keep;
    keep = s->b2d;
    s->v0 = c0;
    s->b28 = 0;
    s->f10[0] = zero; s->f10[1] = zero; s->f10[2] = zero; s->f10[3] = zero; s->f10[4] = zero; s->f10[5] = zero;
    s->b2c = 0; s->b2e = 0; s->b2f = 0; s->b30 = 0;
    s->f40[0] = zero; s->b54 = 0; s->f40[1] = zero; s->b55 = 0; s->f40[2] = zero; s->f40[3] = zero; s->f40[4] = zero;
    s->b78 = 0;
    s->i58[0] = -1; s->i58[1] = -1; s->i58[2] = -1; s->i58[3] = -1;
    s->i58[4] = -1; s->i58[5] = -1; s->i58[6] = -1; s->i58[7] = -1;
    s->a4 = one; s->a0 = 0; s->a8 = one; s->b8[0] = 0; s->ac = one; s->b8[1] = 0; s->b0 = zero; s->b8[2] = 0;
    s->b4 = zero; s->b8[3] = 0; s->c0 = one; s->b8[4] = 0; s->v80[0] = c1; s->b8[5] = 0; s->v80[1] = c2; s->b8[6] = 0;
    s->record = (void *)-1;
    s->b2d = keep;
    if (self->owner->alt) key = 0x3E4C9599u; else key = 0x07791D49u;
    k = key;
    s->record = fn_88645A68(mid->registry->impl, &k);
}
