/* Ball flight model, NM2 family: arc-1 position and launch velocity, converted from drafts/bm_ball_nearmiss.c.
 * Levers: an inline field reload (c->E * t17) puts that operand first in a commutative op; moving the y statement
 * after x and z fixed the last operand swap in 0x888AB220. */
#include "bm_ball.h"

double fn_88565118(double x);
extern float lbl_8814B440; /* g_ts4_event_value in config; the matching-b9 split still names it lbl_8814B440 */

/* Arc-1 position at (tick - tick_prev) * dt, written to b->pos. Swing_DLL.xex 0x888AB558 */
void ts4_bm_ball_arc1_position_888AB558(const float *gen, ts4_bm_ball *b)
{
    const ts4_bm_arc *c;
    float cnt, t0, t6, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26;
    float t27, t28, t29, t30, t31, t33, t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, t50, t51;
    __vector4 a, v;
    ts4_bm_vec4 tmp;
    c = (const ts4_bm_arc *)&b->inv_T;
    cnt = (float)(b->tick - b->tick_prev);
    t0 = gen[1];
    a = b->A;
    t6 = cnt * t0;
    t9 = (float)fn_88565118((double)-(c->k * t6));
    t27 = c->E;
    t10 = c->p0y_T;
    t11 = c->tauA_y;
    t12 = t11 + t10;
    t13 = c->g_a4_tau;
    t14 = c->tauA_x;
    t15 = t11 - t13;
    t16 = c->p1x_T;
    t17 = c->p0x_T;
    t18 = t14 - t16;
    t19 = c->tauA_z;
    t20 = t17 + t14;
    t21 = c->p1z_T;
    t22 = c->p0z_T;
    t23 = t19 - t21;
    t24 = t22 + t19;
    t25 = c->inv_T;
    t26 = t25 * t6;
    t28 = t12 - t13;
    t29 = a.v[0] * t6;
    t30 = c->inv_E_m1;
    t31 = a.v[2] * t6;
    t33 = c->E * t17 + t18;
    t34 = t20 - t16;
    t35 = t10 * t27 + t15;
    t36 = c->g_a4;
    t37 = t22 * t27 + t23;
    t38 = t24 - t21;
    t39 = t28 * t30;
    t40 = t33 - t34 * t9;
    t41 = t35 * t30;
    t42 = t37 - t38 * t9;
    t43 = t39 * t25;
    t44 = t40 * t30 + t29;
    t45 = t42 * t30 + t31;
    t46 = t43 * t9;
    t47 = t44 * t25;
    t48 = t45 * t25;
    t49 = a.v[1] * t26 - t46;
    t50 = t49 - t36 * t26;
    t51 = t41 * t25 + t50;
    v.v[0] = t47;
    v.v[2] = t48;
    v.v[3] = lbl_8814B440;
    v.v[1] = t51;
    *(__vector4 *)&tmp = v;
    b->pos = tmp;
}


/* Launch velocity of arc 1 (m/s): ((P0-P1)*T + A*tau) * inv_E_m1 * inv_a4 + A*inv_T per axis, y with g*a4 folded in. Swing_DLL.xex 0x888AB220 */
void ts4_bm_ball_launch_velocity_888AB220(const ts4_bm_ball *b, __vector4 *out)
{
    float tau, T, ga, it, iE, ia, ay_g;
    __vector4 p0, p1, a, v;
    p0 = b->P0;
    iE = b->inv_E_m1;
    it = b->inv_T;
    T = b->T;
    ga = b->g_a4;
    ia = b->inv_a4;
    p1 = b->P1;
    a = b->A;
    ay_g = a.v[1] - ga;
    tau = b->tau;
    v.v[0] = (((p0.v[0] - p1.v[0]) * T + a.v[0] * tau) * iE) * ia + b->inv_T * a.v[0];
    v.v[2] = (((p0.v[2] - p1.v[2]) * T + a.v[2] * tau) * iE) * ia + b->inv_T * a.v[2];
    v.v[1] = (((a.v[1] - ga) * b->tau + p0.v[1] * T) * iE) * ia + ay_g * it;
    v.v[3] = lbl_8814B440;
    *out = v;
}
