/*
 * DRAFT (not part of the matching build). RT5.
 * Ball bounce response fn_889C1C80 (Swing_DLL.xex 0x889C1C80, 0x2EC bytes), docs/gameplay/ball-physics.md section 6.
 *
 * Status: NOT matched, NOT checked for equivalence (VMX code: tools/fn_equiv.py reports UNCHECKED, and unicorn is not
 * installed here either). Closest form: `python3 tools/fn_check_ltcg.py <this file> ts4_ball_bounce_response_889C1C80=0x889C1C80
 * --flags /Oc --flags /fp:precise` -> same size class (0x2B4 vs 0x2EC), 171 of 187 instructions differ, mostly by register
 * numbering after the first divergence. Known structural blockers (see src/xbox360/drafts/README.md of RT5 in the report):
 *   - one float `?:` (the |5*spin_a| weight) is lowered by the original to the +-1 table + mfcr + fsel idiom; the table sits at
 *     g_ts4_script_constants+0x68, the candidate gets its own __pool@ table (base+offset differs; index orientation open, see
 *     docs/ltcg-route.md section 3);
 *   - original keeps f25 (weight) live across fn_8817B608, 7 saved FPRs (savefpr_25), frame 0x100; candidate saves 5-6;
 *   - vector register numbering / scheduling of the two inlined normalizations (zero test + rsqrte Newton step) differs.
 * Matches the original on everything checked by reading the disassembly: y flip, zero tests, |v.up|<0.99999 axis choice,
 * theta = atan2(y,x) folded at pi/2, four curve16 lookups, wrapped tilt weight, 1-loss scale, two rotations, spin decay,
 * no_sidespin, arc2 start, fn_889C0DC0(ball,0).
 */
#include "../ts4_vector.h"
#ifndef _MSC_VER
#define __forceinline inline
#endif

typedef unsigned char u8;
#ifdef _MSC_VER
#pragma intrinsic(fabs, __vcmpeqfpR)
#endif

/* One shot-template curve header (curve16: self-relative array of 16-byte keys), evaluated by fn_881899D8. */
struct Rt5Curve { int rel; int count; unsigned int unk; };

/* Shot template row as read by the bounce: the four bounce curves. */
struct Rt5Template {
    u8 pad0[0x40];
    struct Rt5Curve speed_loss;     /* +0x40 c40(spin_a) */
    struct Rt5Curve spin_decay;     /* +0x4C c4C(spin_a) */
    struct Rt5Curve out_angle;      /* +0x58 c58(theta)  */
    struct Rt5Curve yaw_kick;       /* +0x64 c64(spin_b) */
};

typedef union Rt5Vec16 {
    float f[4];
    unsigned long long q[2];        /* 8-byte aligned aggregate (ld/std copies) */
} Rt5Vec16;

struct Rt5Ball {
    u8 pad00[0x24];
    const struct Rt5Template *tpl;  /* +0x24 */
    u8 pad28[0x40 - 0x28];
    Rt5Vec16 pos;                   /* +0x40 */
    u8 pad50[0x90 - 0x50];
    float spin[4];                  /* +0x90 spin_a (top/back), spin_b (side), spin_c */
    u8 pad_a0[0x130 - 0xA0];
    Rt5Vec16 arc2_pos;              /* +0x130 */
    Rt5Vec16 arc2_vel;              /* +0x140 */
    u8 pad150[0x4E1 - 0x150];
    u8 no_sidespin;                 /* +0x4E1 */
};

extern float g_ts4_script_constants[];
extern float lbl_880C88DC;         /* pi */
extern float g_ts4_event_value;     /* 0.0f */
extern __vector4 lbl_88001AF0;      /* (0, 1, 0, 0) up */
extern __vector4 lbl_880FC6B0;      /* (0, 0, 1, 0) default axis */

double fn_88564BF8(double y, double x);
double fabs(double x);
__vector4 __vcmpeqfpR(__vector4 a, __vector4 b, unsigned int *cr6);
float fn_881899D8(float x, const struct Rt5Curve *curve);
void fn_8817B608(float *angle);
void fn_8864F7B8(__vector4 *v, const __vector4 *axis, float angle);
void fn_889C0DC0(struct Rt5Ball *ball, int arg);

static __forceinline __vector4 rt5_normalize3(__vector4 x)
{
    __vector4 zero = __vspltisw(0);
    __vector4 half = __vcfsx(__vspltisw(1), 1);
    __vector4 sq = __vmsum3fp(x, x);
    __vector4 r = __vrsqrtefp(sq);
    __vector4 h = __vmulfp(sq, half);
    __vector4 mask = __vcmpeqfp(sq, zero);
    __vector4 r2 = __vmulfp(r, r);
    __vector4 t = __vnmsubfp(h, r2, half);
    __vector4 t2 = __vmaddfp(r, t, r);
    __vector4 n = __vmulfp(x, t2);
    return __vsel(n, sq, mask);
}

static __forceinline int rt5_vec3_is_zero(__vector4 x)
{
    unsigned int cr;
    __vector4 z = __vspltisw(0);
    __vcmpeqfpR(__vpermwi(x, 24), __vpermwi(z, 24), &cr);
    return ((cr >> 7) & 1) == 1;
}

/* Ball bounce response: reflects v (local frame), tilts toward the template elevation, applies yaw kick and spin decay,
 * then rebuilds arc 2. Swing_DLL.xex 0x889C1C80 */
void ts4_ball_bounce_response_889C1C80(struct Rt5Ball *ball, __vector4 *v)
{
    __vector4 axis, up, vv, t, nv, nu;
    const struct Rt5Template *tpl;
    float *spin;
    float ny, theta, loss, decay, yaw, out, wrapped, spin_a, weight, sf, d;
    int tilt;
    Rt5Vec16 tmp;

    ny = -((float *)v)[1];
    vv = *v;
    t = __lvlx(&ny, 0);
    vv = __vrlimi(vv, t, 4, 3);
    *v = vv;
    tpl = ball->tpl;
    spin = ball->spin;
    up = lbl_88001AF0;
    axis = lbl_880FC6B0;
    tilt = 0;
    if (!rt5_vec3_is_zero(vv) && !rt5_vec3_is_zero(up)) {
        nu = rt5_normalize3(up);
        tmp = *(Rt5Vec16 *)v;
        nv = rt5_normalize3(*(__vector4 *)&tmp);
        *(__vector4 *)&tmp = __vmsum3fp(nv, nu);
        d = tmp.f[0];
        if (fabs(d) < g_ts4_script_constants[0x490 / 4])
            tilt = 1;
    }
    if (tilt) {
        __vector4 a = __vpermwi(vv, 99), b = __vpermwi(up, 135), c = __vpermwi(up, 99), e = __vpermwi(vv, 135);
        axis = __vnmsubfp(e, c, __vmulfp(a, b));
    }
    theta = (float)fn_88564BF8(((float *)v)[1], ((float *)v)[0]);
    if (theta > g_ts4_script_constants[0xE8 / 4])
        theta = lbl_880C88DC - theta;
    spin_a = spin[0];
    loss = fn_881899D8(spin_a, &tpl->speed_loss);
    decay = fn_881899D8(spin_a, &tpl->spin_decay);
    yaw = fn_881899D8(spin[1], &tpl->yaw_kick);
    out = fn_881899D8(theta, &tpl->out_angle);
    wrapped = out - theta;
    weight = spin_a * g_ts4_script_constants[0x1E0 / 4];
    weight = (weight < g_ts4_event_value) ? -weight : weight;
    fn_8817B608(&wrapped);
    sf = g_ts4_script_constants[0] - loss;
    {
        float sfv = sf;
        *v = __vmulfp(*v, __vspltw(__lvlx(&sfv, 0), 0));
    }
    fn_8864F7B8(v, &axis, wrapped * weight + theta - theta);
    fn_8864F7B8(v, &up, yaw);
    sf = g_ts4_script_constants[0] - decay;
    spin[0] = sf * spin[0];
    spin[1] = sf * spin[1];
    if (!ball->no_sidespin) {
        spin[2] = sf * spin[2];
    } else {
        spin[2] = g_ts4_event_value;
        spin[1] = g_ts4_event_value;
    }
    ball->arc2_pos = ball->pos;
    ball->arc2_vel = *(Rt5Vec16 *)v;
    fn_889C0DC0(ball, 0);
}
