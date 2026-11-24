/*
 * AF1: matrix helpers for the game's VMX128 code (docs/agents/near-misses/AF1.md).
 *
 * Written for this project from the instruction sequences of the original (no SDK header copied).
 * Two source shapes decide what the compiler emits:
 *  - a matrix passed BY VALUE to a forced-inline helper (`af1_mat_mul(*m, &t)`) is read late, after
 *    address CSE, so its rows load as `li rK,0x10; lvx128 v,rBase,rK` even when the same rows of the
 *    same pointer are stored again; a matrix read through a pointer gives `addi rT,rBase,0x10;
 *    lvx128 v,r0,rT` when the same address is used twice;
 *  - each output row is ONE nested expression (fresh value per step): the 3-input vmaddfp then writes
 *    over its splat operand (`vmaddfp v2,v2,v0,v1`); reassigning an accumulator
 *    (`x = __vmaddfp(s, b, x)`) writes over the accumulator instead.
 */
#ifndef AF1_VECTOR_H
#define AF1_VECTOR_H

#include "vx1_vector.h"

typedef struct Af1Mat {
    __vector4 r[4];
} Af1Mat;

#ifndef _MSC_VER
#define AF1_FORCEINLINE static inline
#else
#define AF1_FORCEINLINE static __forceinline
#endif

/* Row i of the product a * b: one nested vmulfp/vmaddfp chain. */
#define AF1_MUL_ROW(a, b, i)                                                                        \
    __vmaddfp(__vspltw((a).r[i], 3), (b)->r[3],                                                     \
              __vmaddfp(__vspltw((a).r[i], 2), (b)->r[2],                                           \
                        __vmaddfp(__vspltw((a).r[i], 1), (b)->r[1],                                 \
                                  __vmulfp(__vspltw((a).r[i], 0), (b)->r[0]))))

/* a * b, a by value (see above). */
AF1_FORCEINLINE Af1Mat af1_mat_mul(Af1Mat a, const Af1Mat *b)
{
    Af1Mat x;
    x.r[0] = AF1_MUL_ROW(a, b, 0);
    x.r[1] = AF1_MUL_ROW(a, b, 1);
    x.r[2] = AF1_MUL_ROW(a, b, 2);
    x.r[3] = AF1_MUL_ROW(a, b, 3);
    return x;
}

/* Row-wise assignment (an operator= that copies r[0..3]). */
static __inline void af1_mat_set(Af1Mat *d, const Af1Mat *s)
{
    d->r[0] = s->r[0];
    d->r[1] = s->r[1];
    d->r[2] = s->r[2];
    d->r[3] = s->r[3];
}

/* Transpose, m by value. */
AF1_FORCEINLINE Af1Mat af1_mat_transpose(Af1Mat m)
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

/* Refined reciprocal estimate (vrefp + two Newton steps, vsel keeps the estimate for inf/nan). */
static __inline __vector4 af1_recip(__vector4 w)
{
    __vector4 one = __vspltw(__vupkd3d(__vspltisw(0), 1), 3);
    __vector4 r0 = __vrefp(w);
    __vector4 s = __vnmsubfp(w, r0, one);
    __vector4 r1 = __vmaddfp(r0, s, r0);
    __vector4 s2 = __vnmsubfp(w, r1, one);
    __vector4 mask = __vcmpeqfp(r1, r1);
    __vector4 r2 = __vmaddfp(r1, s2, r1);
    return __vsel(r0, r2, mask);
}

/* Point transform with divide by w; the matrix BY VALUE gives the original's VMX32 numbering
 * (m3 loaded into the accumulator register, vmaddfp v13,v12,v10,v13). Note the m.r[2], z order. */
AF1_FORCEINLINE __vector4 af1_transform_coord(__vector4 v, Af1Mat m)
{
    __vector4 z = __vspltw(v, 2), y = __vspltw(v, 1), x = __vspltw(v, 0), r, w;
    r = __vmaddfp(m.r[2], z, m.r[3]);
    r = __vmaddfp(y, m.r[1], r);
    r = __vmaddfp(x, m.r[0], r);
    w = __vspltw(r, 3);
    w = af1_recip(w);
    return __vmulfp(r, w);
}

/* *o = *a + (b - *a) * t, written as a copy then an in-place add: the reload of *o becomes a
 * vor128 copy and the multiply-add is contracted into vmaddfp128 (addend = destination). */
static __inline void af1_vec_lerp_to(__vector4 *o, const __vector4 *a, __vector4 b, float t)
{
    __vector4 l = __vmulfp(__vsubfp(b, *a), __vspltw(__lvlx(&t, 0), 0));
    *o = *a;
    *o = __vaddfp(*o, l);
}

/* out = a + (b - a) * t row by row, rows of a read into named locals first. */
static __inline void af1_mat_lerp_rows(__vector4 *out, const __vector4 *a, const __vector4 *b, float t)
{
    __vector4 a0 = a[0], a1 = a[1], a2 = a[2], a3 = a[3];
    __vector4 d0 = __vsubfp(b[0], a0);
    __vector4 d1 = __vsubfp(b[1], a1);
    __vector4 d2 = __vsubfp(b[2], a2);
    __vector4 d3 = __vsubfp(b[3], a3);
    __vector4 tv = vx1_replicate(t);
    out[0] = __vmaddfp(tv, d0, a0);
    out[1] = __vmaddfp(tv, d1, a1);
    out[2] = __vmaddfp(tv, d2, a2);
    out[3] = __vmaddfp(tv, d3, a3);
}

/* Translation matrix, built last row first and returned by value (assign with af1_mat_set). */
AF1_FORCEINLINE Af1Mat af1_mat_translation(float x, float y, float z)
{
    Af1Mat m;
    __vector4 id = __vupkd3d(__vspltisw(0), 1);
    __vector4 t;
    t.v[0] = x;
    t.v[1] = y;
    t.v[2] = z;
    t.v[3] = 1.0f;
    m.r[3] = t;
    m.r[2] = __vpermwi(id, 174);
    m.r[1] = __vpermwi(id, 186);
    m.r[0] = __vpermwi(id, 234);
    return m;
}

#endif
