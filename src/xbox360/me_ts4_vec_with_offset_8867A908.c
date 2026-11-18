/*
 * ts4_vec_with_offset_8867A908: position of the object's +0x90 point, advanced by fn_8867A7C0 for a positive look-ahead t.
 * Standalone copy of ts4_vec_with_offset_8867A908 from src/xbox360/w6b_d.c (W6B stub), so it can be
 * linked with its own LTCG context (w6b_ctx_a7c0.c with /Ob1).
 */
#include "w6b_types.h"

typedef struct W6dP78 { unsigned char pad[0x90]; __vector4 vec90; } W6dP78;
typedef struct W6dObj78 { unsigned char pad[0x78]; W6dP78 *p78; } W6dObj78;
void fn_8867A7C0(W6dObj78 *self, __vector4 *out, float t);
static const float w6d_zero_a908 = 0.0f;

void ts4_vec_with_offset_8867A908(W6dObj78 *self, __vector4 *out, float t)
{
    *out = self->p78->vec90;
    if (t > w6d_zero_a908) {
        fn_8867A7C0(self, out, t);
        *out = __vaddfp(*out, self->p78->vec90);
    }
}
