/* NEAR MISS draft (10 off, not built): keyframe sampler 0x886C6AE0. Vector side matches (vor128 + vmaddfp128);
 * the two float-address adds pick r4/r3 where the target picks r9/r4. 504 statement orders and 144 type/expression
 * spellings all give the same 10 differences. */
#include "vx1_vector.h"
typedef struct Track { int rel; int count; char p[0x10]; int frel; } Track;
static __inline __vector4 repp(const float *p){ return __vspltw(__lvlx(p, 0), 0); }
static __inline int imin(int a, int b){ return a < b ? a : b; }
void f(Track *s, float t, __vector4 *out, int base){ int last = s->count - 1; float fl = (float)(__int64)t; int i0 = (int)fl; float f = t - fl; int i1; float a0, a1; __vector4 l, b; __vector4 *a; char *fr;
 i0 = imin(i0, last); i1 = imin(i0 + 1, last);
 a = (__vector4 *)((char *)s + ((i0 + base) * 16 + s->rel)); b = *(__vector4 *)((char *)s + ((i1 + base) * 16 + s->rel));
 fr = (char *)&s->frel;
 l = __vmulfp(__vsubfp(b, *a), repp(&f));
 a0 = *(float *)(fr + (i0 * 4 + *(int *)fr)); a1 = *(float *)(fr + (i1 * 4 + *(int *)fr));
 *out = *a; *out = __vaddfp(*out, l);
 f = (a1 - a0) * f + a0;
 *out = __vrlimi(*out, repp(&f), 1, 0); }
