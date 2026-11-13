/*
 * Near-miss reconstructions of the ball flight model (BM family). None of these is byte exact yet and none is
 * listed in work/specs/BM; they are kept as the starting point for the next attempt. Style that got the matched
 * functions in bm_ball_model.c to compile identically: SSA-order locals, one statement per original value,
 * vector fields copied with `__vector4 v = b->field;` and read back with lfs, stores through a cast pointer so the
 * compiler reloads fields.
 */
#include "../bm_ball.h"

double fn_88565118(double x);
double fn_88563F20(double x);
extern float g_ts4_script_constants[];
extern float lbl_8814B45C;
extern float g_ts4_event_value;

/* Apex height (m) of arc 1 for flight time tt. NOT MATCHED: 1 instruction differs (operand order of one fmuls). Swing_DLL.xex 0x888AA968 */
float ts4_bm_ball_apex_height_888AA968(const ts4_bm_ball *b, float tt)
{
    const ts4_bm_arc *c;
    float t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45;
    t0 = b->A.v[1];
    t0 = b->A.v[1];
    c = (const ts4_bm_arc *)&b->inv_T;
    t1 = b->P0.v[1];
    t6 = c->g_a4;
    t3 = b->T;
    t4 = t1 * t3;
    t5 = c->k;
    t7 = t5 * tt;
    t9 = b->phys.a4;
    t8 = tt * t6;
    t2 = t0 * tt;
    t10 = b->phys.g;
    t12 = -t7;
    t11 = t2 + t4;
    t13 = t8 - t11;
    t14 = (float)fn_88565118((double)t12);
    t15 = c->g_a4;
    t22 = (t14 * t0) - t0;
    t18 = g_ts4_script_constants[0];
    t17 = c->T_sq;
    t20 = g_ts4_script_constants[14];
    t19 = t18 / t17;
    t21 = t20 / t13;
    t23 = t14 - t18;
    t16 = c->inv_T;
    t26 = t18 / t23;
    t25 = t22 - (t15 * t14);
    t27 = t25 + t15;
    t24 = t16 * t21;
    t28 = t27 * t9;
    t29 = t24 * t28;
    t30 = -t29;
    t31 = (float)fn_88563F20((double)t30);
    t33 = t21 * t28;
    t36 = t33 * t26;
    t34 = t8 - t2;
    t32 = c->a4_sq;
    t38 = t34 - (t14 * t4);
    t37 = t32 * t31;
    t35 = t31 * t0;
    t40 = t37 * t19;
    t39 = t35 * t9;
    t41 = t38 * t16;
    t42 = (t36 * t13) + t39;
    t43 = t42 * t19;
    t44 = (t40 * t10) - t43;
    t45 = t44 - (t41 * t26);
    return t45;
}

/* Arc-1 position at (tick - tick_prev) * dt, written to b->pos. NOT MATCHED: 1 instruction differs (operand order of one fmadds). Swing_DLL.xex 0x888AB558 */
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
    t33 = t27 * t17 + t18;
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
    v.v[3] = g_ts4_event_value;
    v.v[1] = t51;
    *(__vector4 *)&tmp = v;
    b->pos = tmp;
}

/* Launch velocity of arc 1 (m/s). NOT MATCHED: 11 instructions differ (register numbering and operand order). Swing_DLL.xex 0x888AB220 */
void ts4_bm_ball_launch_velocity_888AB220(const ts4_bm_ball *b, __vector4 *out)
{
    float tau, T, ga, it, iE, ia, t18;
    __vector4 p0, p1, a, v;
    p0 = b->P0;
    iE = b->inv_E_m1;
    it = b->inv_T;
    T = b->T;
    ga = b->g_a4;
    ia = b->inv_a4;
    p1 = b->P1;
    a = b->A;
    t18 = a.v[1] - ga;
    tau = b->tau;
    v.v[1] = ((t18 * tau + p0.v[1] * T) * iE) * ia + t18 * it;
    v.v[0] = (((p0.v[0] - p1.v[0]) * T + a.v[0] * tau) * iE) * ia + it * a.v[0];
    v.v[2] = (((p0.v[2] - p1.v[2]) * T + a.v[2] * tau) * iE) * ia + it * a.v[2];
    v.v[3] = g_ts4_event_value;
    *out = v;
}

/* d|v(0)|^2/d tau. NOT MATCHED: 24 instructions differ (scheduling). Swing_DLL.xex 0x888AACB8 */
float ts4_bm_ball_launch_speed_sq_derivative_888AACB8(const ts4_bm_ball *b)
{
    const ts4_bm_arc *c;
    float t0, t1, t2, t3, t4, t5, t6, t7, t8, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, t50, t51, t52, t53, t54, t55, t56, t57, t58, t59, t60;
    __vector4 a;
    c = (const ts4_bm_arc *)&b->inv_T;
    a = b->A;
    t0 = b->tau;
    t1 = c->k;
    t2 = c->p0x_T;
    t3 = t1 * t0;
    t4 = c->p1x_T;
    t5 = c->inv_a4;
    t6 = a.v[0];
    t7 = a.v[1];
    t8 = a.v[2];
    t10 = (t6 * t0) + t2;
    t11 = -t3;
    t12 = t10 - t4;
    t13 = (float)fn_88565118((double)t11);
    t14 = c->p0y_T;
    t15 = c->inv_a4;
    t16 = (t7 * t0) + t14;
    t17 = c->k;
    t18 = g_ts4_script_constants[0];
    t19 = t15 * t17;
    t20 = c->p0z_T;
    t21 = c->g_a4;
    t22 = (t8 * t0) + t20;
    t23 = t21 - t7;
    t24 = c->p1z_T;
    t25 = t13 - t18;
    t26 = c->inv_T;
    t27 = t8 * t26;
    t28 = lbl_8814B45C;
    t29 = t6 * t26;
    t30 = (t21 * t0) - t16;
    t31 = t19 * t13;
    t32 = t22 - t24;
    t33 = t18 / t25;
    t34 = t25 * t25;
    t35 = t30 * t31;
    t36 = t32 * t31;
    t37 = t30 * t33;
    t38 = t23 * t33;
    t39 = t8 * t33;
    t40 = t18 / t34;
    t41 = t32 * t33;
    t42 = t6 * t33;
    t43 = t33 * t5;
    t44 = t37 * t5;
    t45 = t38 * t5;
    t46 = t39 * t5;
    t47 = t31 * t40;
    t48 = (t41 * t5) + t27;
    t49 = (t43 * t12) + t29;
    t50 = (t7 * t26) - t44;
    t51 = -t45;
    t52 = (t36 * t40) + t46;
    t53 = t47 * t12;
    t54 = t50 - (t21 * t26);
    t55 = t51 - (t35 * t40);
    t56 = t52 * t48;
    t57 = (t42 * t5) + t53;
    t58 = (t55 * t54) + t56;
    t59 = (t57 * t49) + t58;
    t60 = t59 * t28;
    return t60;
}

/* Arrival velocity of arc 1 (m/s). NOT MATCHED: 76 instructions differ (scheduling, one extra saved fpr in the original). Swing_DLL.xex 0x888AB0E0 */
void ts4_bm_ball_bounce_velocity_888AB0E0(const ts4_bm_ball *b, __vector4 *out)
{
    float t0, t1, t2, t3, t4, t5, t6, t8, t10, t12, t13, t14, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44;
    __vector4 p0, p1, a, v;
    p0 = b->P0;
    p1 = b->P1;
    a = b->A;
    t0 = b->T;
    t1 = b->inv_a4;
    t2 = t1 * t0;
    t3 = b->tau;
    t4 = p0.v[0];
    t5 = p0.v[1];
    t6 = p0.v[2];
    t8 = p1.v[0];
    t10 = p1.v[2];
    t12 = a.v[0];
    t13 = a.v[1];
    t14 = a.v[2];
    t16 = t2 * t3;
    t17 = -t16;
    t18 = (float)fn_88565118((double)t17);
    t19 = t13 * t3;
    t20 = t12 * t3;
    t21 = b->inv_T;
    t22 = b->g_a4;
    t23 = t14 * t3;
    t24 = g_ts4_script_constants[0];
    t25 = t18 * t1;
    t26 = (t5 * t0) + t19;
    t27 = (t4 * t0) + t20;
    t28 = t12 * t21;
    t29 = g_ts4_event_value;
    t30 = t14 * t21;
    t31 = t18 - t24;
    t32 = (t6 * t0) + t23;
    t33 = (t22 * t3) - t26;
    t34 = t27 - (t8 * t0);
    t35 = t24 / t31;
    t36 = t32 - (t10 * t0);
    t37 = t33 * t25;
    t38 = t34 * t25;
    t39 = t36 * t25;
    t40 = t37 * t35;
    t41 = (t38 * t35) + t28;
    t42 = (t39 * t35) + t30;
    t43 = (t13 * t21) - t40;
    t44 = t43 - (t22 * t21);
    v.v[0] = t41;
    v.v[1] = t44;
    v.v[2] = t42;
    v.v[3] = t29;
    *out = v;
}

/* Arc-2 position from arc2_pos/arc2_vel, written to b->pos. NOT MATCHED: 37 instructions differ (stack slot order of the three vector copies). Swing_DLL.xex 0x888AD1C8 */
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
    t2 = b->phys.a4;
    t3 = b->phys.g;
    t4 = b->T;
    t5 = q0.v[0];
    t6 = q0.v[1];
    t7 = q0.v[2];
    t9 = qv.v[0];
    t10 = qv.v[1];
    t11 = qv.v[2];
    t13 = a.v[0];
    t14 = a.v[1];
    t15 = a.v[2];
    t17 = cnt * t0;
    t18 = t1 * t17;
    t20 = (float)fn_88565118((double)-t18);
    t21 = t10 * t4;
    t22 = t13 * t2;
    t23 = t15 * t2;
    t24 = t9 * t4;
    t25 = c->g_a4;
    t26 = t11 * t4;
    t27 = c->T_sq;
    t28 = t27 * t6;
    t29 = c->inv_T;
    t30 = t29 * t17;
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
    v.v[3] = g_ts4_event_value;
    v.v[1] = t58;
    *(__vector4 *)&tmp = v;
    b->pos = tmp;
}
