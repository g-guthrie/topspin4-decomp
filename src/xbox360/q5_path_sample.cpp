/* Q5: sampler of the player's recorded movement path (Swing_DLL.xex 0x8867A7C0, 0x144 bytes), C++ form.
 * Byte-matched on the LTCG route: work/specs/Q5/q5_path_sample.json.
 *
 * The move state behind player+0x78 holds a self-relative array of 16-byte displacement samples (+0x380 offset,
 * +0x384 count), one per tick ahead.
 *
 * ts4_path_sample_8867A7C0(self, out, t): the displacement at the fractional tick t, linearly interpolated; past
 * the end it extrapolates from the last two samples; with fewer than two samples it is the zero vector
 * (lbl_880FC650, a vector literal in the image). Callers: ts4_vec_with_offset_8867A908 and
 * ts4_path_weighted_ahead_8868ED00 (src/xbox360/q5_ctx_move_planner_callees.c).
 *
 * Codegen notes (cl 16.00.10224 PPC, /O2 /Oc /GL, LTCG):
 *  - Q5Vec has a user-declared destructor. A Q5Vec returned by value from an inline is then a real memory
 *    temporary: the result is stored to the stack and block-copied (ld/std) to *out, and the two-step
 *    "copy, then add" of q5_advance_to is fused late into vor + vmaddfp. A plain struct temporary is enregistered
 *    and gives a different instruction selection.
 *  - `out` is an explicit parameter (self in r3, out in r4): a member returning Q5Vec by value would get the hidden
 *    result pointer in r3 and `this` in r4.
 *  - The zero vector is a literal (__vmx@ pool entry, next sequential vector register), not a named global (a load
 *    from a global always takes v63).
 *  - Q5PathArray::Back() written twice (once for the difference, once for the base) gives the target's single
 *    materialised `end - 1` address with the two loads merged late (the merged load still consumes a vector
 *    register number).
 * As LTCG context for its callers compile with flags(/Ob1) so it stays a call. */
#include "w6b_types.h"

struct Q5Vec {
    __vector4 v;
    Q5Vec() {}
    ~Q5Vec() {}
};

/* self-relative array of Q5Vec */
struct Q5PathArray {
    int offset;
    int count;
    const Q5Vec *At(int i) const { return (const Q5Vec *)((const char *)this + offset) + i; }
    const Q5Vec *Back() const { return At(count) - 1; }
};

struct Q5PathState {
    unsigned char pad0[0x380];
    Q5PathArray path;       /* +0x380 */
};

struct Q5PathOwner {
    unsigned char pad0[0x78];
    Q5PathState *state;     /* +0x78 */
};

static inline __vector4 q5_vec_zero()
{
    __vector4 z = { 0.0f, 0.0f, 0.0f, 0.0f };
    return z;
}

/* *o = *a + d * t */
static inline void q5_advance_to(Q5Vec *o, const Q5Vec *a, __vector4 d, float t)
{
    __vector4 l = __vmulfp(d, __vspltw(__lvlx(&t, 0), 0));
    o->v = a->v;
    o->v = __vaddfp(o->v, l);
}

/* *from + d * t, by value */
static inline Q5Vec q5_extend(const Q5Vec *from, __vector4 d, float t)
{
    Q5Vec r;
    q5_advance_to(&r, from, d, t);
    return r;
}

extern "C" void ts4_path_sample_8867A7C0(const Q5PathOwner *self, Q5Vec *out, float t)
{
    int i = (int)t;
    const Q5PathArray *a = &self->state->path;
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
                const Q5Vec *p0 = a->At(i);
                q5_advance_to(out, p0, __vsubfp(a->At(j)->v, p0->v), t - (float)i);
            }
        } else {
            const Q5Vec *p0 = a->At(n - 2);
            __vector4 d = __vsubfp(a->Back()->v, p0->v);
            *out = q5_extend(a->Back(), d, t - ((float)n - 1.0f));
        }
    } else {
        out->v = q5_vec_zero();
    }
}
