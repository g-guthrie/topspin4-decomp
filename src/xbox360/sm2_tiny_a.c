/* SM2: tiny accessors, vector load/store wrappers and thin tail-call thunks. */
#include "ts4_vector.h"

#ifdef _MSC_VER
extern double fabs(double x);
#pragma intrinsic(fabs)
#else
#include <math.h>
#endif

typedef long long ts4_s64;

/* Swing_DLL.xex 0x884054E8 */
double ts4_fabs_884054E8(double x) { return fabs(x); }

/* lvx128 wrapper: load a vector from base + byte offset */
__vector4 ts4_vec_load_off_8841C7C8(const char *base, int off) { return *(const __vector4 *)(base + off); }
/* stvx128 wrapper: store a vector to base + byte offset */
void ts4_vec_store_off_8841C7D0(char *base, int off, __vector4 v) { *(__vector4 *)(base + off) = v; }

ts4_s64 ts4_get_s64_at_8_885E9488(const ts4_s64 *p) { return p[1]; }
ts4_s64 ts4_get_s64_at_0_885F3AD0(const ts4_s64 *p) { return p[0]; }
ts4_s64 ts4_get_s64_at_20_885F9578(const char *p) { return *(const ts4_s64 *)(p + 0x20); }

float ts4_get_float_by_byte_off_886C3590(const char *p, int off) { return *(const float *)(p + off); }
float ts4_get_float_by_index_88517320(const float *p, int i) { return p[i]; }
__vector4 ts4_vec_xor_886C3CA0(__vector4 a, __vector4 b) { return __vxor(a, b); }



float ts4_fmin_885EDD90(float a, float b) { return a < b ? a : b; }
float ts4_fmax_885EDDA0(float a, float b) { return a > b ? a : b; }
