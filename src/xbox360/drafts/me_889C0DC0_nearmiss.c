/* agD 2026-11-19: still 11. Single-store forms (t = madd(side,k1,acc); drift = madd(lift,k0,t)), named splat locals, block copies, add chains: all 12 (acc stays in v9 and the first add uses 4-operand vmaddfp); volatile acc read: 46. */
/* agentA2 2026-11-19: volatile read of the up constant fixes the zero/up/splat numbering: 24 -> 11 off (LTCG + primer).
 * Remaining: the target keeps acc in v63 and does both adds as vor128 copy + vmaddfp128 (side*s1 then lift*s0) with one
 * store; ours computes acc in v9 and uses vmaddfp + a stored intermediate. Single-store/explicit vmaddfp forms: 12. */
/* NEAR MISS fn_889C0DC0 ball spin drift: 24 off, LTCG + pp1_pool_primer.c, /Oc.
 * Remaining: vector register numbering (zero in v61 vs v62, up/splats one lower) and the first accumulate:
 * the target uses vor128 + vmaddfp128 (stored-then-reloaded value) for BOTH adds into drift; we get one. */
/* Swing_DLL.xex 0x889C0DC0: spin drift basis of the ball. */
#include "../rt1_types.h"

extern const __vector4 lbl_88001AF0;          /* up (0, 1, 0, 0) */
extern const float g_ts4_event_value;
static const float kOne = 1.0f;

struct Ts4BallD {
    ts4_u8 pad_000[0x80];
    __vector4 drift;                       /* +0x080 */
    float spin[3];                         /* +0x090 */
    ts4_u8 pad_09c[0x64];
    __vector4 p100;                        /* +0x100 */
    __vector4 p110;                        /* +0x110 */
    ts4_u8 pad_120[0x20];
    __vector4 vel140;                      /* +0x140 */
    ts4_u8 pad_150[0x218];
    ts4_u8 mirrored;                       /* +0x368 */
};

static RT1_INLINE ts4_bool ts4_equal3(__vector4 v, __vector4 w)
{
    unsigned int cr;
    __vcmpeqfpR(__vpermwi(v, 24), __vpermwi(w, 24), &cr);
    return (cr & 0x80) == 0x80;
}
static RT1_INLINE __vector4 ts4_normalize3(__vector4 v, __vector4 half, __vector4 zero)
{
    __vector4 len_sq = __vmsum3fp(v, v);
    __vector4 r = __vrsqrtefp(len_sq);
    __vector4 is_zero = __vcmpeqfp(len_sq, zero);
    __vector4 step = __vnmsubfp(__vmulfp(len_sq, half), __vmulfp(r, r), half);
    r = __vmaddfp(r, step, r);
    return __vsel(__vmulfp(v, r), len_sq, is_zero);
}
static RT1_INLINE __vector4 ts4_cross3(__vector4 a, __vector4 b)
{
    return __vnmsubfp(__vpermwi(a, 135), __vpermwi(b, 99), __vmulfp(__vpermwi(a, 99), __vpermwi(b, 135)));
}

void ts4_ball_spin_drift_889C0DC0(struct Ts4BallD *ball, ts4_bool from_points)
{
    __vector4 d, zero, n, side, lift;
    float sign, s1;
    if (from_points == 1) {
        d = __vsubfp(ball->p100, ball->p110);
    } else {
        d = ball->vel140;
        d = __vrlimi(d, __lvlx(&g_ts4_event_value, 0), 4, 3);
    }
    zero = __vspltisw(0);
    if (ts4_equal3(d, zero) != 0)
        return;
    {
        const float *spin = ball->spin;
        __vector4 s2 = __vspltw(__lvlx(&spin[2], 0), 0);
        __vector4 acc;
        n = ts4_normalize3(d, __vcfsx(__vspltisw(1), 1), zero);
        acc = __vmulfp(n, s2);
        side = ts4_cross3(n, *(volatile __vector4 *)&lbl_88001AF0);   /* own register like the target */
        lift = ts4_cross3(side, n);
        sign = ball->mirrored ? -1.0f : 1.0f;
        s1 = spin[1] * sign;
        {
            __vector4 *o = &ball->drift;
            __vector4 a1 = __vmulfp(side, __vspltw(__lvlx(&s1, 0), 0));
            __vector4 a0 = __vmulfp(lift, __vspltw(__lvlx(&spin[0], 0), 0));
            *o = acc;
            *o = __vaddfp(*o, a1);
            {
                __vector4 *o2 = &ball->drift;
                *o2 = __vaddfp(*o2, a0);
            }
        }
    }
}
