/*
 * Software math for ts4core: deterministic on every platform (only IEEE +,-,*,/ and sqrt are used).
 *
 *   ts4_fmaf   exact fused multiply-add for binary32 (double product is exact, round-to-odd on the sum)
 *   ts4_exp    double exp, ~1 ulp (the original game calls the CRT double exp and rounds to float)
 *   ts4_log    double log, ~1 ulp
 *   ts4_sinf / ts4_cosf / ts4_atan2f   used only by the bounce / net-cord response (not bit-exact modules)
 *
 * The first three are checked against the host libm in port/core/test/test_core.c and against the golden
 * vectors of src/xbox360/drafts/gp4b_ball_model.c (bit-exact with the original machine code).
 */
#include <stdint.h>
#include <string.h>

#include "ts4_internal.h"

static uint64_t d2u(double d) { uint64_t u; memcpy(&u, &d, 8); return u; }
static double u2d(uint64_t u) { double d; memcpy(&d, &u, 8); return d; }

#define TS4_INF (1.0 / 0.0)
#define TS4_NAN (0.0 / 0.0)

/* ---- exact fmaf ----------------------------------------------------------------------------------------- */
float ts4_fmaf(float a, float b, float c)
{
    double p = (double)a * (double)b;         /* 24 x 24 bits fit in 53: exact */
    double cd = (double)c;
    double s = p + cd;
    double bb, err;
    if (s - s != 0.0) return (float)s;        /* inf / nan */
    bb = s - p;
    err = (p - (s - bb)) + (cd - bb);         /* TwoSum: s + err == p + c exactly */
    if (err != 0.0) {                         /* round-to-odd so the final (float) rounding is correct */
        uint64_t u = d2u(s);
        if (!(u & 1u)) {
            int toward_bigger_mag = ((err > 0.0) == (s > 0.0));
            if (s == 0.0) u = (err > 0.0) ? 1u : (0x8000000000000001u);
            else u = toward_bigger_mag ? u + 1u : u - 1u;
            s = u2d(u);
        }
    }
    return (float)s;
}

/* ---- exp ------------------------------------------------------------------------------------------------ */
double ts4_exp(double x)
{
    static const double ln2hi = 6.93147180369123816490e-01, ln2lo = 1.90821492927058770002e-10;
    static const double inv_ln2 = 1.44269504088896338700e+00;
    double kd, r, s;
    int k, n;
    if (x != x) return x;
    if (x > 709.782712893384) return TS4_INF;
    if (x < -745.13321910194122) return 0.0;
    kd = x * inv_ln2;
    k = (int)(kd < 0.0 ? kd - 0.5 : kd + 0.5);        /* round to nearest */
    kd = (double)k;
    r = (x - kd * ln2hi) - kd * ln2lo;
    s = 1.0;
    for (n = 17; n >= 1; n--) s = 1.0 + (r / (double)n) * s;
    /* scale by 2^k in two steps so subnormal results stay correct */
    if (k > 1000) { s *= u2d((uint64_t)(1023 + 1000) << 52); k -= 1000; }
    if (k < -1000) { s *= u2d((uint64_t)(1023 - 1000) << 52); k += 1000; }
    return s * u2d((uint64_t)(1023 + k) << 52);
}

/* ---- log ------------------------------------------------------------------------------------------------ */
double ts4_log(double x)
{
    static const double ln2hi = 6.93147180369123816490e-01, ln2lo = 1.90821492927058770002e-10;
    uint64_t u;
    int k = 0, n;
    double m, f, s, z, poly, r;
    if (x != x) return x;
    if (x < 0.0) return TS4_NAN;
    if (x == 0.0) return -TS4_INF;
    if (x - x != 0.0) return x;                         /* +inf */
    u = d2u(x);
    if (((u >> 52) & 0x7ff) == 0) { x *= 18014398509481984.0; u = d2u(x); k -= 54; }   /* subnormal: * 2^54 */
    k += (int)((u >> 52) & 0x7ff) - 1023;
    m = u2d((u & 0x000fffffffffffffULL) | 0x3ff0000000000000ULL);  /* [1,2) */
    if (m > 1.4142135623730951) { m *= 0.5; k += 1; }
    f = m - 1.0;
    s = f / (2.0 + f);
    z = s * s;
    poly = 1.0 / 31.0;
    for (n = 29; n >= 1; n -= 2) poly = (1.0 / (double)n) + z * poly;
    r = 2.0 * s * poly;
    return ((double)k * ln2hi + (r + (double)k * ln2lo));
}

/* ---- trig (float API, double internals) ---------------------------------------------------------------- */
static double sin_cos_core(double x, int want_cos)
{
    static const double pio2_hi = 1.57079632673412561417e+00, pio2_lo = 6.07710050650619224932e-11;
    static const double two_over_pi = 6.36619772367581382433e-01;
    double q = x * two_over_pi, r, r2, v;
    int n = (int)(q < 0.0 ? q - 0.5 : q + 0.5), i;
    r = (x - (double)n * pio2_hi) - (double)n * pio2_lo;
    r2 = r * r;
    switch (((n + (want_cos ? 1 : 0)) % 4 + 4) % 4) {
    case 0: case 2: {                 /* sin(r) */
        v = 1.0;
        for (i = 15; i >= 3; i -= 2) v = 1.0 - (r2 / (double)((i - 1) * i)) * v;
        v = r * v;
        break;
    }
    default: {                        /* cos(r) */
        v = 1.0;
        for (i = 16; i >= 2; i -= 2) v = 1.0 - (r2 / (double)((i - 1) * i)) * v;
        break;
    }
    }
    switch (((n + (want_cos ? 1 : 0)) % 4 + 4) % 4) {
    case 2: case 3: v = -v; break;
    default: break;
    }
    return v;
}
float ts4_sinf(float x) { return (float)sin_cos_core((double)x, 0); }
float ts4_cosf(float x) { return (float)sin_cos_core((double)x, 1); }

static double atan_core(double t)       /* any t */
{
    static const double pi4 = 0.78539816339744830962, pi2 = 1.57079632679489661923;
    int neg = t < 0.0, inv = 0, shift = 0, n;
    double u, u2, s, v;
    if (neg) t = -t;
    if (t > 1.0) { t = 1.0 / t; inv = 1; }
    if (t > 0.41421356237309503) { t = (t - 1.0) / (t + 1.0); shift = 1; }
    u = t; u2 = u * u;
    s = 1.0 / 41.0;
    for (n = 39; n >= 1; n -= 2) s = (1.0 / (double)n) - u2 * s;
    v = u * s;
    if (shift) v += pi4;
    if (inv) v = pi2 - v;
    return neg ? -v : v;
}
float ts4_atan2f(float yf, float xf)
{
    static const double pi = 3.14159265358979323846;
    double y = (double)yf, x = (double)xf, a;
    if (x == 0.0 && y == 0.0) return 0.0f;
    if (x == 0.0) return (float)(y > 0.0 ? pi / 2 : -pi / 2);
    a = atan_core(y / x);
    if (x < 0.0) a += (y >= 0.0) ? pi : -pi;
    return (float)a;
}
