/*
 * Q5: wrap an angle into [-pi, pi) in place (Swing_DLL.xex 0x8817B608, 0x88). One step each way, so the input is
 * expected within one turn of the range. Called by the move planner 0x886B8468 and about 70 other gameplay
 * functions (facing / heading code).
 *
 * The two selects compile to the fcmpu / mfcr / lfsx (+-1 table at g_ts4_script_constants+0x68) / fsel form
 * only through an inline helper that compares against a named static zero (w5c_types.h, LTCG route).
 */
static const float q5w_zero = 0.0f;

extern const float lbl_880C88DC;   /* pi */
extern const float lbl_880C8F18;   /* 2 pi */

/* d >= 0 ? a : b */
static __inline float q5w_sel_ge(float d, float a, float b) { return (d >= q5w_zero) ? a : b; }

/* 0x8817B608 */
void ts4_angle_wrap_pi_8817B608(float *angle)
{
    float a = *angle;
    a = q5w_sel_ge(a - lbl_880C88DC, a - lbl_880C8F18, a);
    a = q5w_sel_ge(a - -3.14159265f, a, a + lbl_880C8F18);
    *angle = a;
}
