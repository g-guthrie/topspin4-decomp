/*
 * ts4core math shim. Put port/core/shim first on the include path (-I) for every ts4core build, host and wasm.
 *
 * - On hosted targets it forwards to the system <math.h>, then redirects the functions whose results are not
 *   specified bit-for-bit by IEEE 754 (exp, log, fmaf, sin, cos, atan2) to the software versions in
 *   src/softmath.c, so the simulation is bit-identical on every platform and under wasm.
 * - On wasm32 (-nostdlib) there is no system header; the few IEEE-exact functions map to compiler builtins.
 */
#ifndef TS4_SHIM_MATH_H
#define TS4_SHIM_MATH_H

#if !defined(__wasm__)
#include_next <math.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif
double ts4_exp(double x);
double ts4_log(double x);
float ts4_fmaf(float a, float b, float c);
float ts4_sinf(float x);
float ts4_cosf(float x);
float ts4_atan2f(float y, float x);
float ts4_sqrtf_(float x);
#ifdef __cplusplus
}
#endif

#undef exp
#undef log
#undef fmaf
#undef sinf
#undef cosf
#undef atan2f
#define exp(x) ts4_exp(x)
#define log(x) ts4_log(x)
#define fmaf(a, b, c) ts4_fmaf((a), (b), (c))
#define sinf(x) ts4_sinf(x)
#define cosf(x) ts4_cosf(x)
#define atan2f(y, x) ts4_atan2f((y), (x))

#if defined(__wasm__)
#undef sqrt
#undef sqrtf
#undef fabs
#undef fabsf
#define sqrt(x) __builtin_sqrt(x)
#define sqrtf(x) __builtin_sqrtf(x)
#define fabs(x) __builtin_fabs(x)
#define fabsf(x) __builtin_fabsf(x)
#endif

#endif
