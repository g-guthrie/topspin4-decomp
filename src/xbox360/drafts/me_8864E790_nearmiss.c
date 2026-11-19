/* agentB 2026-11-18 pass 2: still 5 off (plain and LTCG). All 24 declaration orders of r0/r1/r2/w, separate vspltisw zeros,
 * direct stores, row 3 computed first: always 5 (v61/v62 swapped). Ts4Mat4 local copy: 25. */
/* NEAR MISS 0x8864E790: 5 off (v61/v62 swap: vupkd3d result vs r1 copy of zero). 8 variants tried (order, helper, direct stores). */
#include "ts4_vector.h"

typedef struct Ts4Mat4 { __vector4 r[4]; } Ts4Mat4;

/* 0x8864E790: build a diagonal scale matrix diag(sx, sy, sz, 1). */
void ts4_mat_make_scale(Ts4Mat4 *out, float sx, float sy, float sz)
{
    __vector4 zero = __vspltisw(0);
    __vector4 r0 = __lvlx(&sx, 0);
    __vector4 r1 = zero;
    __vector4 r2 = zero;
    r0 = __vrlimi(r0, zero, 7, 0);
    r1 = __vrlimi(r1, __lvlx(&sy, 0), 4, 3);
    r2 = __vrlimi(r2, __lvlx(&sz, 0), 2, 2);
    out->r[0] = r0;
    out->r[1] = r1;
    out->r[2] = r2;
    out->r[3] = __vpermwi(__vupkd3d(zero, 1), 171);
}
