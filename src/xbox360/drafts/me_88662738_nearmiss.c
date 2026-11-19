/* NEAR MISS fn_88662738 reach-in-arc test: 74 off (same size 0x244, same 7 relocs), LTCG + pp1_pool_primer.c, /Oc.
 * Remaining: vector register numbering (target b=v62, inserted zero=v63, d in a fresh v57; ours reuses b for d),
 * the bad-distance bool (target: li 0 after the first compare) and the final ok select (target li 1/beq/li 0; ours subic/subfe). */
/* Swing_DLL.xex 0x88662738: can the player reach the target from the given position (distance band and facing arc)? */
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
#include "../ts4_vector.h"
#ifdef _MSC_VER
#pragma intrinsic(__vrlimi, __vsubfp, __vmulfp, __vmaddfp, __vnmsubfp, __vrsqrtefp, __vmsum3fp, __vsel, __vspltisw, __vcfsx)
__vector4 __vcmpeqfp(__vector4 a, __vector4 b);
#pragma intrinsic(__vcmpeqfp)
#endif

extern const float g_ts4_event_value;   /* 0.0f */
double fn_88564BF8(double y, double x); /* atan2 */

struct Ts4RcCourt { ts4_u8 pad_00[0xB0]; int style; };
struct Ts4RcLink { ts4_u8 pad_00[0x24]; struct Ts4RcCourt *court; };
struct Ts4RcState { ts4_u8 pad_000[0x7DC]; float reach_min; float reach_max; };
struct Ts4RcAnim { ts4_u8 pad_000[0x44C]; float arc_lo; float arc_hi; };
struct Ts4RcPC { ts4_u8 pad_00[0x4C]; struct Ts4RcLink *link; ts4_u8 pad_50[0x24]; struct Ts4RcState *state; struct Ts4RcAnim *anim; };
struct Ts4RcOwner { struct Ts4RcPC *pc; };

static const float kZero = 0.0f;
static __inline __vector4 rc_set_x(__vector4 v, float f) { return __vrlimi(v, __lvlx(&f, 0), 8, 0); }
static __inline __vector4 rc_set_z(__vector4 v, float f) { return __vrlimi(v, __lvlx(&f, 0), 2, 2); }
static __inline __vector4 rc_set_y0(__vector4 v) { return __vrlimi(v, __lvlx(&kZero, 0), 4, 3); }
static __inline float rc_max(float a, float b) { return (a - b >= kZero) ? a : b; }

ts4_u8 ts4_reach_in_arc_88662738(struct Ts4RcOwner *self, const __vector4 *from, const __vector4 *to)
{
    struct Ts4RcPC *pc = self->pc;
    __vector4 a = *from;
    __vector4 b = *to;
    struct Ts4RcState *st;
    struct Ts4RcAnim *an;
    float mx, lo, hi, r, dx, dz, dsq, deg;
    ts4_u8 bad_dist;
    if (pc->link->court->style == (int)0xA2EDA1E7u) {
        a = rc_set_x(a, -a.v[0]);
        a = rc_set_z(a, -a.v[2]);
    }
    a = rc_set_y0(a);
    if (pc->link->court->style == (int)0xA2EDA1E7u) {
        b = rc_set_x(b, -b.v[0]);
        b = rc_set_z(b, -b.v[2]);
    }
    b = rc_set_y0(b);
    st = pc->state;
    an = pc->anim;
    lo = an->arc_lo;
    hi = an->arc_hi;
    mx = st->reach_max;
    r = rc_max(mx, st->reach_min);
    dz = a.v[2] - b.v[2];
    dx = a.v[0] - b.v[0];
    dsq = dx * dx + dz * dz;
    bad_dist = 0;
    if (dsq > r * r || dsq < mx * mx)
        bad_dist = 1;
    {
        __vector4 d = __vsubfp(b, a);
        __vector4 one = __vcfsx(__vspltisw(1), 1);
        __vector4 zero = __vspltisw(0);
        __vector4 len_sq, rs, step;
        d = rc_set_y0(d);
        len_sq = __vmsum3fp(d, d);
        rs = __vrsqrtefp(len_sq);
        step = __vnmsubfp(__vmulfp(len_sq, one), __vmulfp(rs, rs), one);
        rs = __vmaddfp(rs, step, rs);
        d = __vsel(__vmulfp(d, rs), len_sq, __vcmpeqfp(len_sq, zero));
        deg = -(float)((float)fn_88564BF8(d.v[2], d.v[0]) * 57.295779513082323);
    }
    {
        ts4_u8 out_arc = (deg < lo || deg > hi) ? 1 : 0;
        ts4_u8 ok = 0;
        if (!out_arc) {
            ok = 1;
            if (bad_dist)
                ok = 0;
        }
        return ok;
    }
}
