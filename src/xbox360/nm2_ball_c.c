/* Ball flight model, NM2 family: arc-2 position, converted from drafts/bm_ball_nearmiss.c.
 * Statement order found with a greedy reorder search plus the operand-order rule: in a commutative op the operand
 * whose variable is defined later comes first (here the A components are defined after inv_T * t). */
#include "bm_ball.h"
double fn_88565118(double x);
extern float lbl_8814B440;
/* Arc-2 position from arc2_pos/arc2_vel, written to b->pos. Swing_DLL.xex 0x888AD1C8 */
void ts4_bm_ball_arc2_position_888AD1C8(const float *gen, ts4_bm_ball *b)
{
    const ts4_bm_arc *c;
    float cnt, dt;
    float t0, t1, t2, t3, t4, t5, t6, t7, t9, t10, t11, t13, t14, t15, t17, t18, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, t50, t51, t52, t53, t54, t55, t56, t57, t58;
    __vector4 q0, qv, a, v;
    ts4_bm_vec4 tmp;
    c = (const ts4_bm_arc *)&b->inv_T;
    cnt = (float)(b->tick - b->tick_prev);
    dt = gen[1];
    q0 = b->arc2_pos;
    qv = b->arc2_vel;
    a = b->A;
    t0 = dt;
    t1 = c->k;
    t5 = q0.v[0];
    t6 = q0.v[1];
    t7 = q0.v[2];
    t2 = b->phys.a4;
    t3 = b->phys.g;
    t4 = b->T;
    t9 = qv.v[0];
    t10 = qv.v[1];
    t11 = qv.v[2];
    t17 = cnt * t0;
    t18 = t1 * t17;
    t20 = (float)fn_88565118((double)-t18);
    t29 = c->inv_T;
    t30 = t29 * t17;
    t13 = a.v[0];
    t14 = a.v[1];
    t15 = a.v[2];
    t21 = t10 * t4;
    t22 = t13 * t2;
    t23 = t15 * t2;
    t24 = t9 * t4;
    t26 = t11 * t4;
    t27 = c->T_sq;
    t28 = t27 * t6;
    t25 = c->g_a4;
    t31 = t25 + t21;
    t32 = (t27 * t5) - t22;
    t34 = (t27 * t7) - t23;
    t35 = t24 - t13;
    t36 = c->inv_T2;
    t37 = t26 - t15;
    t38 = c->a4_sq;
    t39 = (t21 * t2) + t28;
    t40 = t13 * t30;
    t41 = t31 - t14;
    t42 = (t24 * t2) + t32;
    t43 = (t26 * t2) + t34;
    t44 = t35 * t20;
    t45 = t37 * t20;
    t46 = t15 * t30;
    t47 = t39 - (t14 * t2);
    t48 = t41 * t36;
    t49 = t42 - (t44 * t2);
    t50 = t43 - (t45 * t2);
    t51 = t48 * t20;
    t52 = (t38 * t3) + t47;
    t53 = (t49 * t36) + t40;
    t54 = (t50 * t36) + t46;
    t55 = t51 * t2;
    t56 = (t14 * t30) - t55;
    t57 = t56 - (t25 * t30);
    t58 = (t52 * t36) + t57;
    v.v[0] = t53;
    v.v[2] = t54;
    v.v[3] = lbl_8814B440;
    v.v[1] = t58;
    *(__vector4 *)&tmp = v;
    b->pos = tmp;
}
