/* rough draft 0x886C54C8 (ME agent B): 68 off (/Oc). Sibling of 0x886C5610 (same sweep; keeps the best by
 * the w lane of the A-side point instead of squared distance). */
#include "ts4_vector.h"
__vector4 __vcmpeqfpR(__vector4 a, __vector4 b, unsigned int *cr);
#pragma intrinsic(__vcmpeqfpR)
typedef unsigned char ts4_bool;
extern const float g_ts4_script_constants[];
/* bit 0x20: CR6 "all false"; bit 0x80: CR6 "all true" */
static __inline ts4_bool all_zero_lanes_none(__vector4 m, __vector4 zero) { unsigned int cr; __vcmpeqfpR(m, zero, &cr); return (cr & 0x20) == 0x20; }
static __inline ts4_bool all_zero_lanes(__vector4 m, __vector4 zero) { unsigned int cr; __vcmpeqfpR(m, zero, &cr); return (cr & 0x80) == 0x80; }
ts4_bool fn_886C54C8(const __vector4 *seg_a, const __vector4 *seg_b, const __vector4 *t_range,
                     __vector4 *out_s, __vector4 *out_w, __vector4 *out_t,
                     __vector4 max_x, __vector4 min_x, __vector4 max_z, __vector4 min_z)
{
    __vector4 zero = __vspltisw(0);
    __vector4 t = t_range[0];
    __vector4 step = __vmulfp(__vsubfp(t_range[1], t), __vcfsx(__vspltisw(1), 4));
    __vector4 a0 = seg_a[0], a1 = seg_a[1];
    __vector4 best_s = zero, best_t = zero;
    __vector4 best = zero;
    ts4_bool hit = 0;
    int i;
    for (i = 16; i; i--) {
        __vector4 b0 = __vaddfp(seg_b[0], t);
        __vector4 db = __vsubfp(__vaddfp(seg_b[1], t), b0);
        __vector4 den = __vsubfp(__vsubfp(a1, a0), db);
        __vector4 one = __vupkd3d(zero, 0);
        __vector4 r = __vrefp(den);
        __vector4 s;
        r = __vmaddfp(r, __vnmsubfp(den, r, one), r);
        s = __vspltw(__vmulfp(__vsubfp(b0, a0), r), 3);
        if (all_zero_lanes_none(__vand(__vcmpgefp(s, zero), __vcmpgefp(one, s)), zero)) {
            __vector4 pa = __vmaddfp(s, __vsubfp(a1, a0), a0);
            __vector4 d = __vsubfp(__vmaddfp(s, db, b0), pa);
            __vector4 dx, dz, d2;
            ts4_bool in;
            d = __vrlimi(d, zero, 1, 0);
            dx = __vspltw(d, 0);
            d2 = __vspltw(pa, 3);
            dz = __vspltw(d, 2);
            in = all_zero_lanes(__vor(__vor(__vcmpgefp(min_x, dx), __vcmpgefp(dx, max_x)), __vor(__vcmpgefp(min_z, dz), __vcmpgefp(dz, max_z))), zero);
            hit = hit || in;
            if (in) {
                __vector4 m = __vcmpgefp(d2, best);
                best_s = __vsel(best_s, s, m);
                best = __vsel(best, d2, m);
                best_t = __vsel(best_t, t, m);
            }
        }
        t = __vaddfp(t, step);
    }
    if (hit) { *out_s = best_s; *out_w = best; *out_t = best_t; }
    return hit;
}
