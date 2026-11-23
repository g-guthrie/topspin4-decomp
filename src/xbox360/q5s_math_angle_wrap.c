/*
 * Q5S math: angle wrap (Swing_DLL.xex).
 *
 * 0x8817B608: wrap an angle into [-pi, pi] in place, one turn each way. Called by the move planner 0x886B8468 and
 * about 70 other heading/facing functions.
 *
 * Select codegen: the target computes both arms up front and selects with
 *   fcmpu c,zero; mfcr; rlwinm LT; rlwinm UN; or; lfsx {+1,-1}; fsel t,x,y
 * A `?:` (any helper shape) sinks the computed arm into a branch. The `__fself` intrinsic keeps both arms
 * speculated; comparing `c - kZero` (folded away) makes its zero the named static, which turns the bare fsel into
 * the table form above. 2*pi is read into a local before the angle: that fixes the `fadds f5,f7,f0` operand order.
 */
#ifdef _MSC_VER
extern float __fself(float, float, float);
#pragma intrinsic(__fself)
#else
static float __fself(float c, float x, float y) { return c >= 0.0f ? x : y; }
#endif

static const float q5s_math_zero = 0.0f;

extern const float lbl_880C88DC;   /* pi */
extern const float lbl_880C8F18;   /* 2 pi */

/* c >= 0 ? x : y, both arms evaluated */
static __inline float q5s_math_sel(float c, float x, float y) { return __fself(c - q5s_math_zero, x, y); }

/* 0x8817B608 */
void ts4_angle_wrap_pi_8817B608(float *angle)
{
    float two_pi = lbl_880C8F18;
    float a = *angle;
    a = q5s_math_sel(a - lbl_880C88DC, a - two_pi, a);
    a = q5s_math_sel(a - -3.14159265f, a, a + two_pi);
    *angle = a;
}
