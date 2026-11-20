/*
 * Ball flight model (BM family), converted from drafts/bm_ball_nearmiss.c. Lever that closed the last fmuls
 * operand swap: define t25..t28 (the t27*t9 product) before the divisions t21/t26 so its value is introduced first. Style that got the matched
 * functions in bm_ball_model.c to compile identically: SSA-order locals, one statement per original value,
 * vector fields copied with `__vector4 v = b->field;` and read back with lfs, stores through a cast pointer so the
 * compiler reloads fields.
 */
#include "bm_ball.h"

double fn_88565118(double x);
double fn_88563F20(double x);
extern float g_ts4_script_constants[];
extern float lbl_8814B45C;
extern float g_ts4_event_value;

/* Apex height (m) of arc 1 for flight time tt. Swing_DLL.xex 0x888AA968 */
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
    t25 = t22 - (t15 * t14);
    t27 = t25 + t15;
    t28 = t27 * t9;
    t21 = t20 / t13;
    t23 = t14 - t18;
    t16 = c->inv_T;
    t26 = t18 / t23;
    t24 = t16 * t21;
    t33 = t21 * t28;
    t29 = t24 * t28;
    t30 = -t29;
    t31 = (float)fn_88563F20((double)t30);
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
