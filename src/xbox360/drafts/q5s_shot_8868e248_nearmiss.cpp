/* nearmiss: 6 off (C++, LTCG + pool primer, /Oc); concrete blocker: VMX temp numbering only (target v13/v11/v12 for
 * len_sq*0.5 / vor copy of len_sq / r*r, ours v12/v13/v11). Invariant across ~50 variants: four rsqrt-Newton helper
 * forms, vector vs float return, explicit __vor copy at 3 positions, 7 statement orders. C gives 7 (adds fmuls operand
 * swap). Open residue class "VMX temps" in matching-tips.
 * 0x8868E248 (ShotDifficulty inputs): d = |state+0xE30 - *pos| * 0.01; t = (mode - team->state->launch_frame) / 60
 * (0 -> 1); state+0x7A0 = d; state+0x7A4 = d / t; then runs the analyser list at player+0x154. */
#include "include/ts4/ts4.h"
#include "vx1_vector.h"
extern "C" const float g_ts4_event_value;
extern "C" const float g_ts4_script_constants[];
extern "C" void ts4_loop_call_seq_u32_off2c_8890E988(void *seq);
static __inline float e248_len(__vector4 v)
{
    __vector4 half = __vcfsx(__vspltisw(1), 1);
    __vector4 zero = __vspltisw(0);
    __vector4 len_sq = __vmsum3fp(v, v);
    __vector4 r = __vrsqrtefp(len_sq);
    __vector4 is_zero = __vcmpeqfp(len_sq, zero);
    __vector4 step = __vnmsubfp(__vmulfp(len_sq, half), __vmulfp(r, r), half);
    Vx1Vec o;
    r = __vmaddfp(r, step, r);
    o.v = __vsel(__vmulfp(len_sq, r), len_sq, is_zero);
    return o.v.v[0];
}
extern "C" void ts4_shot_difficulty_inputs_8868E248(Ts4Player *p, const __vector4 *pos, int mode)
{
    float t, d;
    __vector4 ball = *(__vector4 *)((char *)p->state + 0xE30);
    float len = e248_len(__vsubfp(ball, *pos));
    t = (float)(mode - p->team->state->launch_frame) * g_ts4_script_constants[0xE0 / 4];
    d = len * g_ts4_script_constants[0x1BC / 4];
    if (t == g_ts4_event_value)
        t = g_ts4_script_constants[0];
    *(float *)((char *)p->state + 0x7A0) = d;
    *(float *)((char *)p->state + 0x7A4) = d / t;
    ts4_loop_call_seq_u32_off2c_8890E988((char *)p + 0x154);
}
