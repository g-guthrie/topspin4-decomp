/*
 * 0x8825CF28: XMMatrixLookToLH(eye, dir, up), VMX128 form, returned through the sret pointer:
 * r2 = normalize3(dir), r0 = normalize3(cross(up, r2)), r1 = cross(r2, r0); the rows {r0, r1, r2}
 * get -dot3(r, eye) in w (vrlimi 0xE), row 3 is the identity row {0,0,0,1} (vupkd3d + vpermwi 171),
 * and the matrix is transposed.
 *
 * Codegen: normalize3 is the one-Newton-step vrsqrtefp form with h = vcfsx(vspltisw(1), 1) = 0.5;
 * cross is vpermwi 0x63/0x87 + vmulfp + vnmsubfp; the negate is vxor with vslw(-1, -1). The
 * transpose must be written in the function body into a local that is returned (NRVO straight into
 * the sret buffer); calling af1_mat_transpose by value adds a stack temp and an 8-doubleword copy.
 * `__vupkd3d(.., 1)` is the encoded immediate the disassembler prints as 0x4.
 */
#include "af1_vector.h"

__vector4 __vslw(__vector4 a, __vector4 b); /* vslw128 */
#ifdef _MSC_VER
#pragma intrinsic(__vslw)
#endif

AF1_FORCEINLINE __vector4 q5s_v3_normalize(__vector4 v)
{
    __vector4 d, rsq, rcp, rt, h;
    h = __vspltisw(1);
    h = __vcfsx(h, 1);
    d = __vmsum3fp(v, v);
    rsq = __vrsqrtefp(d);
    rt = __vmulfp(d, h);
    rcp = __vmulfp(rsq, rsq);
    h = __vnmsubfp(rt, rcp, h);
    rsq = __vmaddfp(rsq, h, rsq);
    return __vmulfp(v, rsq);
}

AF1_FORCEINLINE __vector4 q5s_v3_cross(__vector4 a, __vector4 b)
{
    __vector4 r, t0, t1;
    t0 = __vpermwi(a, 0x63);
    t1 = __vpermwi(b, 0x87);
    r = __vmulfp(t0, t1);
    t0 = __vpermwi(a, 0x87);
    t1 = __vpermwi(b, 0x63);
    return __vnmsubfp(t0, t1, r);
}

AF1_FORCEINLINE __vector4 q5s_negate(__vector4 v)
{
    __vector4 m = __vspltisw(-1);
    m = __vslw(m, m);
    return __vxor(v, m);
}

Af1Mat ts4_mat_look_to_8825CF28(__vector4 eye, __vector4 dir, __vector4 up)
{
    __vector4 neg, d0, d1, d2, r0, r1, r2;
    Af1Mat m;
    r2 = q5s_v3_normalize(dir);
    r0 = q5s_v3_cross(up, r2);
    r0 = q5s_v3_normalize(r0);
    r1 = q5s_v3_cross(r2, r0);
    neg = q5s_negate(eye);
    d0 = __vmsum3fp(r0, neg);
    d1 = __vmsum3fp(r1, neg);
    d2 = __vmsum3fp(r2, neg);
    m.r[0] = __vrlimi(d0, r0, 0xE, 0);
    m.r[1] = __vrlimi(d1, r1, 0xE, 0);
    m.r[2] = __vrlimi(d2, r2, 0xE, 0);
    m.r[3] = __vpermwi(__vupkd3d(__vspltisw(0), 1), 171);
    {
        Af1Mat p, t;
        p.r[0] = __vmrghw(m.r[0], m.r[2]);
        p.r[1] = __vmrghw(m.r[1], m.r[3]);
        p.r[2] = __vmrglw(m.r[0], m.r[2]);
        p.r[3] = __vmrglw(m.r[1], m.r[3]);
        t.r[0] = __vmrghw(p.r[0], p.r[1]);
        t.r[1] = __vmrglw(p.r[0], p.r[1]);
        t.r[2] = __vmrghw(p.r[2], p.r[3]);
        t.r[3] = __vmrglw(p.r[2], p.r[3]);
        return t;
    }
}
