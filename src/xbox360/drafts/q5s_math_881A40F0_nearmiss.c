/* nearmiss: 6 off; blocker: VMX register allocation of matrix rows (target m3->v13 m2->v12 m1->v11); an inline transform_coord helper taking __vector4 by value crashes cl ("compile failed"/linker crash), so the probable original helper shape cannot be tested until that compiler crash is understood; perm_auto 110 candidates no gain. */
#include "include/ts4/ts4.h"
__vector4 __vsldoi(__vector4 a, __vector4 b, int sh);
#pragma intrinsic(__vsldoi)
typedef struct Q5sF3 { float x, y, z; } Q5sF3;
void fn_881A40F0(Q5sF3 *p, const __vector4 *m)
{
    __vector4 lo = __lvlx(p, 0);
    __vector4 hi = __lvrx(p, 12);
    __vector4 v, r, w, one, r0, e, q, sel;
    hi = __vsldoi(hi, hi, 4);
    v = __vor(lo, hi);
    r = __vmaddfp(m[2], __vspltw(v, 2), m[3]);
    r = __vmaddfp(__vspltw(v, 1), m[1], r);
    r = __vmaddfp(__vspltw(v, 0), m[0], r);
    w = __vspltw(r, 3);
    one = __vspltw(__vupkd3d(__vspltisw(0), 1), 3);
    r0 = __vrefp(w);
    e = __vnmsubfp(w, r0, one);
    q = __vmaddfp(r0, e, r0);
    e = __vnmsubfp(w, q, one);
    sel = __vcmpeqfp(q, q);
    q = __vmaddfp(q, e, q);
    q = __vsel(r0, q, sel);
    r = __vmulfp(r, q);
    __stvewx(__vspltw(r, 0), p, 0);
    __stvewx(__vspltw(r, 1), p, 4);
    __stvewx(__vspltw(r, 2), p, 8);
}
