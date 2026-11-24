/* NEAR MISS fn_886962C0: 19 off (0x80 vs 0x7C; FPR assignment of t / a around the third wrap call), LTCG + primer, /Oc. */
/* Swing_DLL.xex 0x886962C0: interpolate between two angles along the shorter way: a + wrap(b - a) * t. */
struct Ts4LpAngle { float rad; };
void fn_8817B608(struct Ts4LpAngle *angle);   /* wrap to [-pi, pi) */

struct Ts4LpAngle *ts4_angle_lerp_886962C0(struct Ts4LpAngle *out, struct Ts4LpAngle a, struct Ts4LpAngle b, float t)
{
    struct Ts4LpAngle d;
    fn_8817B608(&a);
    fn_8817B608(&b);
    {
        float av = a.rad;
        d.rad = b.rad - av;
        fn_8817B608(&d);
        out->rad = d.rad * t + av;
    }
    return out;
}
