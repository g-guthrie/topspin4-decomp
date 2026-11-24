/* agentB 2026-11-18 pass 2: still 5 off. Pads 0-17 (pads removed), constants-base pointer local (before/after zero),
 * block-local base/zero pointers in 3 orders, eps/zero swap: always 5 (prologue r11/r10/r7 vs r10/r7/r6). */
/* 0x886C5F08 near miss (5 off, LTCG or plain; sweep 2026-11-18: pointer loop 7, volatile zero 5, literal eps 8-65, late base 5, no pads ERR; only the three prologue constant-address registers: target r10/r7/r6,
 * ours r11/r10/r7). Adds a point to a 4-slot table: stops at the first empty (0,0,0) slot or a slot within eps
 * (script constant [32]) on x, y and z; stores into an empty slot, sets *full when it was the last, returns the
 * index or -1. Tried: eps/zero declaration order, pads 1-6, constants base pointer. */
#include "vx1_vector.h"
double fabs(double);
#pragma intrinsic(fabs)
extern const float g_ts4_event_value;
extern const float g_ts4_script_constants[];
static __inline unsigned char vec3_is_zero(const __vector4 *v, float zero)
{
    return v->v[0] == zero && v->v[1] == zero && v->v[2] == zero;
}
static __inline unsigned char vec3_near(__vector4 a, __vector4 b, float eps)
{
    __vector4 d = __vsubfp(a, b);
    return (float)fabs(d.v[0]) < eps && (float)fabs(d.v[1]) < eps && (float)fabs(d.v[2]) < eps;
}
int ts4_point_slots_add(__vector4 *slots, const __vector4 *p, unsigned char *full)
{
    int r = -1;
    int pad0 = 0;
    int pad1 = 0;
    int pad2 = 0;
    int pad3 = 0;
    int pad4 = 0;
    int pad5 = 0;
    float zero = g_ts4_event_value;
    float eps = g_ts4_script_constants[32];
    unsigned i;
    for (i = 0; i < 4; i++) {
        __vector4 *s = &slots[i];
        if ((s->v[0] == zero && s->v[1] == zero && s->v[2] == zero) || vec3_near(*s, *p, eps)) break;
    }
    if (i < 4) {
        __vector4 *s = &slots[i];
        if (s->v[0] == zero && s->v[1] == zero && s->v[2] == zero) {
            *s = *p;
            if (i == 3) *full = 1;
            r = i;
        }
    }
    (void)pad0;
    (void)pad1;
    (void)pad2;
    (void)pad3;
    (void)pad4;
    (void)pad5;
    return r;
}
