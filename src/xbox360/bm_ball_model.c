/* Ball flight closed-form model (Top Spin 4, Xbox 360), BM family. See docs/gameplay/gp4b.md. */
#include "bm_ball.h"

double fn_88565118(double x);
extern float g_ts4_script_constants[];

/* |v(0)|^2 of arc 1: squared launch speed (m/s)^2. Swing_DLL.xex 0x888AAB98 */
float ts4_bm_ball_launch_speed_sq_888AAB98(const ts4_bm_ball *b)
{
    float tau, T, e, one, inv, it;
    float ayt, pzt, pxt, sy, sz, sx, vy, vz, vx, wy;
    __vector4 p0, p1, a;
    p0 = b->P0;
    tau = b->tau;
    p1 = b->P1;
    a = b->A;
    T = b->T;
    e = (float)fn_88565118((double)-(b->k * tau));
    it = b->inv_T;
    one = g_ts4_script_constants[0];
    pxt = p0.v[0] * T;
    sx = a.v[0] * tau + pxt - p1.v[0] * T;
    ayt = a.v[1] * tau;
    pzt = p0.v[2] * T;
    inv = one / (e - one);
    sy = b->g_a4 * tau - (p0.v[1] * T + ayt);
    sz = a.v[2] * tau + pzt - p1.v[2] * T;
    vx = (sx * b->inv_a4) * inv + it * a.v[0];
    vy = (sy * b->inv_a4) * inv;
    wy = it * a.v[1] - vy - b->g_a4 * it;
    vz = (sz * b->inv_a4) * inv + it * a.v[2];
    return vx * vx + vz * vz + wy * wy;
}

/* |v(tau)|^2 of arc 1: squared speed at the ground (first bounce), (m/s)^2. Swing_DLL.xex 0x888AAA70 */
float ts4_bm_ball_bounce_speed_sq_888AAA70(const ts4_bm_ball *b)
{
    float tau, T, ia, e, one, inv, it, w;
    float ayt, pzt, pxt, sy, sz, sx, vy, vz, vx, wy;
    __vector4 p0, p1, a;
    tau = b->tau;
    p0 = b->P0;
    T = b->T;
    ia = b->inv_a4;
    p1 = b->P1;
    a = b->A;
    e = (float)fn_88565118((double)-(ia * T * tau));
    it = b->inv_T;
    one = g_ts4_script_constants[0];
    w = e * ia;
    pxt = p0.v[0] * T;
    sx = a.v[0] * tau + pxt - p1.v[0] * T;
    ayt = a.v[1] * tau;
    pzt = p0.v[2] * T;
    sz = a.v[2] * tau + pzt - p1.v[2] * T;
    sy = b->g_a4 * tau - (p0.v[1] * T + ayt);
    inv = one / (e - one);
    vx = (sx * w) * inv + it * a.v[0];
    vy = (sy * w) * inv;
    wy = it * a.v[1] - vy - b->g_a4 * it;
    vz = (sz * w) * inv + it * a.v[2];
    return vx * vx + vz * vz + wy * wy;
}

/* Cache e^(-k*tau), 1/(E-1), tau*A and g*a4*tau for the current flight time. Swing_DLL.xex 0x888AAE00 */
void ts4_bm_ball_cache_end_constants_888AAE00(ts4_bm_ball *b)
{
    __vector4 a = b->A;
    float *c = (float *)((char *)b + 0x180);
    float e = (float)fn_88565118((double)-(b->k * b->tau));
    c[0] = e;
    c[1] = g_ts4_script_constants[0] / (e - g_ts4_script_constants[0]);
    c[2] = b->tau * a.v[0];
    c[3] = b->tau * a.v[1];
    c[4] = b->tau * a.v[2];
    c[5] = b->g_a4 * b->tau;
}

/* Cache the arc constants that depend on T, a4, g and the endpoints P0/P1. Swing_DLL.xex 0x888AAEA8 */
void ts4_bm_ball_cache_arc_constants_888AAEA8(ts4_bm_ball *b)
{
    float *c = (float *)((char *)b + 0x150);
    const ts4_bm_phys *ph = &b->phys;
    float one, a4, T, t2, inv_a4, inv_T, inv_T2;
    __vector4 p0, p1;
    a4 = ph->a4;
    T = b->T;
    t2 = T * T;
    one = g_ts4_script_constants[0];
    inv_a4 = one / a4;
    c[1] = inv_a4;
    inv_T = one / T;
    c[0] = inv_T;
    c[2] = inv_a4 * T;
    c[3] = ph->g * ph->a4;
    inv_T2 = inv_T * inv_T;
    c[4] = inv_T2;
    c[5] = ph->a4 * ph->a4;
    c[6] = t2;
    p1 = b->P1;
    p0 = b->P0;
    c[7] = p0.v[0] * T;
    c[8] = p1.v[0] * T;
    c[9] = p0.v[1] * T;
    c[10] = p0.v[2] * T;
    c[11] = p1.v[2] * T;
}

/* Template kind routines (solver stage); only the dispatcher is reconstructed here. */
void fn_888AB8D0(ts4_bm_ball *b);
void fn_888AC748(ts4_bm_ball *b);
void fn_888ACA68(ts4_bm_ball *b);
void fn_888ACDA8(ts4_bm_ball *b);

/* Solver entry: refresh the cached arc constants, then run the kind routine selected by the template (hash at tpl+8). Swing_DLL.xex 0x888AD0E8 */
void ts4_bm_ball_solve_by_template_kind_888AD0E8(ts4_bm_ball *b)
{
    ts4_bm_ball_cache_arc_constants_888AAEA8(b);
    switch (b->tpl[2]) {
    case 0x5D90675Bu: fn_888AB8D0(b); break;
    case 0x2DB3EB6Fu: fn_888AC748(b); break;
    case 0x50B89452u: fn_888ACDA8(b); break;
    case 0xC1965E5Cu: fn_888ACA68(b); break;
    default: break;
    }
}
