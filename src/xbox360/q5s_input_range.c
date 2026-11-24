/*
 * Q5S input: wrapped-angle range test (Swing_DLL.xex), LTCG route, /Oc.
 *
 * 0x8890DF58: true when (x - ref), wrapped into [-pi, pi], lies in [lo, hi]. The callee must be named
 *             ts4_angle_wrap_pi_8817B608 so its matched body (q5s_math_angle_wrap.c) is in the LTCG context.
 */
typedef unsigned char u8;

void ts4_angle_wrap_pi_8817B608(float *angle);

typedef struct Q5sAngleRange { float lo, hi, ref; } Q5sAngleRange;

/* 0x8890DF58 */
u8 ts4_input_wrapped_in_range_8890DF58(Q5sAngleRange *r, const float *x)
{
    float a = *x - r->ref;
    ts4_angle_wrap_pi_8817B608(&a);
    return a >= r->lo && a <= r->hi;
}
