/* nearmiss: 2 off (Swing_DLL.xex 0x888AF350, critically damped approach step; omega = 2/tau, exp series
 * 1/(1+a+0.48a^2+0.235a^3), result rejected when |target - r| > limit unless limit == -1).
 * Diff 1: zero is loaded as lfs 0x1c(base) where the target has -0x1c(base). The target bases both named constants at
 * the 2.0 (0x8814B45C) and reaches the shared zero (0x8814B440, folded from another TU) 0x1c below it. MSVC bases at
 * the lowest-addressed named static. Declaring kTwo first gives the right base, but the zero then lands above it.
 * Concrete blocker: needs a named-constant (BINKCONS) primer that places the 0x8814B440..B45C block from earlier
 * TUs; no such tool exists yet (pp1_pool_primer covers only the 0x880D0F70 pool).
 * Diff 2: fmadds f1,f9,f5 vs f5,f9 (operand order of n*e). Swapping, named locals, inline helpers all no effect.
 * Context: pool primer only. */
#ifdef _MSC_VER
extern float __fself(float, float, float);
#pragma intrinsic(__fself)
#else
static float __fself(float c, float x, float y) { return c >= 0.0f ? x : y; }
#endif
static const float kTwo = 2.0f;
static const float kB1 = 11.5f, kB2 = 12.5f, kB3 = 13.5f, kB4 = 14.5f, kB5 = 15.5f, kB6 = 16.5f;
static const float kZero = 0.0f;
float dummy_b(float x) { return x * kB1 + x * kB2 + x * kB3 + x * kB4 + x * kB5 + x * kB6; }
typedef struct Defs { char p[0x240]; float dt; } Defs;
extern Defs *lbl_88D45B1C;
static __inline float sabs(float x) { return __fself(x - kZero, x, -x); }
float u1(const float *cur, const float *tgt, const float *tau, const float *lim)
{
    float t = *tau;
    float x0 = *cur;
    if (t > kZero) {
        float inv = kTwo / t;
        float l = *lim;
        float x1 = *tgt;
        float d = x1 - x0;
        float dt = lbl_88D45B1C->dt;
        float a = dt * inv;
        float e = 1.0f / (((a * 0.235f + 0.48f) * a + 1.0f) * a + 1.0f);
        float n = (d * inv + (x0 - x1)) * dt + d;
        float r = n * e + x0;
        if (l == -1.0f)
            return r;
        if (l >= sabs(x1 - r))
            return r;
    }
    return x0;
}
