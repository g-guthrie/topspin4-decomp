/* nearmiss: 40 off (scheduling only: target delays the |x| reload lfs -0x10 until after the 1.0f lane stores and computes value3/fsqrts after the vmaddfp chain; statement order is inert (30 permutations), /Oc /O1 /Os /fp:* and LTCG+pool primer give the same 40). Instruction set, stack slots and relocations already match. */
#include "vx1_vector.h"
#ifdef _MSC_VER
extern float __fsqrts(float);
#pragma intrinsic(__fsqrts)
#else
#include <math.h>
#define __fsqrts(x) sqrtf(x)
#endif

extern const float g_ts4_script_constants[];
extern const __vector4 lbl_880D1AD0;
extern const __vector4 lbl_880D1AE0;
extern const __vector4 lbl_880D1AF0;

typedef union AcosBits { __vector4 v; float f[4]; unsigned int u[4]; } AcosBits;

/* Scalar arc cosine (xnamath-style polynomial). */
float ts4_scalar_acos_88189630(float value)
{
    union { float f; unsigned int u; } bits;
    AcosBits abs_v;
    float abs_value, value2, value3, d;
    __vector4 v0, v1, r;

    bits.f = value;
    abs_v.u[0] = bits.u & 0x7FFFFFFF;
    v1.v[2] = value;
    v1.v[3] = value;
    v0.v[1] = g_ts4_script_constants[0];
    v0.v[3] = g_ts4_script_constants[0];
    abs_value = abs_v.f[0];
    value2 = value * abs_value;
    value3 = value2 * value;
    d = (value - value2) / __fsqrts(g_ts4_script_constants[96] - abs_value);
    v0.v[0] = value3;
    v0.v[2] = value3;
    v1.v[0] = d;
    v1.v[1] = d;

    r = __vspltw(abs_v.v, 0);
    r = __vmaddfp(r, __vmaddfp(r, lbl_880D1AD0, lbl_880D1AE0), lbl_880D1AF0);
    abs_v.v = __vmsum4fp(r, __vmulfp(v1, v0));
    return g_ts4_script_constants[58] - abs_v.f[0];
}
