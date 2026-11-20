/* NEAR MISS draft (not built, not counted). See docs/agents/matching-tips.md, "Near misses parked". */
#include "vx1_vector.h"
typedef struct Track Track;
void fn_886C6AE0(Track *s, float t, __vector4 *out, int base);
typedef struct Pair { Vx1Vec a, b; } Pair;
static __inline void sub(Vx1Vec *o, const Vx1Vec *x, const Vx1Vec *y){ o->v = __vsubfp(x->v, y->v); }
void f(Track *s, float *p, float t, Pair *out){ Vx1Vec c, a, b;
 fn_886C6AE0(s, t, &c.v, 0); fn_886C6AE0(s, p[0], &a.v, 8); fn_886C6AE0(s, p[1], &b.v, 8);
 { __vector4 av = a.v, bv = b.v, cv = c.v; a.v = __vsubfp(cv, av); b.v = __vsubfp(cv, bv); } out->a = a; out->b = b; }