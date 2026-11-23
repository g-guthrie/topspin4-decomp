/* Q5 LTCG context: the recorded-path sampler behind fn_8868ED00 and ts4_vec_with_offset_8867A908
 * (Swing_DLL.xex 0x8867A7C0, 0x144 bytes).
 *
 * fn_8867A7C0(self, out, t): linear interpolation of the 16-byte samples of self->anim->path at the
 * fractional index t; past the end it extrapolates from the last two samples; with fewer than two samples it
 * returns the zero vector lbl_880FC650. */
#include "w6b_types.h"

typedef struct Q5PathArray { int offset; int count; } Q5PathArray; /* self-relative array of __vector4 */
typedef struct Q5PathAnim { unsigned char pad0[0x380]; Q5PathArray path; } Q5PathAnim;
typedef struct Q5PathOwner { unsigned char pad0[0x78]; Q5PathAnim *anim; } Q5PathOwner;
typedef struct Q5PathVec { __vector4 v; } Q5PathVec;

extern const __vector4 lbl_880FC650;

static __inline const __vector4 *q5_path_at(const Q5PathArray *a, int i)
{
    return (const __vector4 *)((const char *)a + a->offset) + i;
}

/* *o = *a + d * t */
static __inline void q5_path_advance_to(__vector4 *o, const __vector4 *a, __vector4 d, float t)
{
    __vector4 l = __vmulfp(d, __vspltw(__lvlx(&t, 0), 0));
    *o = *a;
    *o = __vaddfp(*o, l);
}

/* p1 + (p1 - p0) * t, returned by value */
static __inline Q5PathVec q5_path_extend(const __vector4 *p0, const __vector4 *p1, float t)
{
    Q5PathVec r;
    q5_path_advance_to(&r.v, p1, __vsubfp(*p1, *p0), t);
    return r;
}

void fn_8867A7C0(Q5PathOwner *self, __vector4 *out, float t)
{
    int i = (int)t;
    const Q5PathArray *a = &self->anim->path;
    int j = i + 1;
    int n = a->count;
    if (n > 1) {
        if (j < n) {
            int last = n - 1;
            if (i >= last)
                i = last;
            if (j >= last)
                j = last;
            {
                const __vector4 *p0 = q5_path_at(a, i);
                q5_path_advance_to(out, p0, __vsubfp(*q5_path_at(a, j), *p0), t - (float)i);
            }
        } else {
            *(Q5PathVec *)out = q5_path_extend(q5_path_at(a, n - 2), q5_path_at(a, n) - 1, t - ((float)n - 1.0f));
        }
    } else {
        *out = lbl_880FC650;
    }
}
