/* NEAR MISS draft (not built, not counted). See docs/agents/matching-tips.md, "Near misses parked". */
#include "vx1_vector.h"
extern const float lbl_8814B910; /* 0.5f */
typedef struct Obj { char p[0x350]; __vector4 v350; char q[0xc]; float f36c; } Obj;
typedef struct Out { char p[0x28]; float f28; } Out;
extern void fn_888ABCC0(__vector4 *out, Obj *obj, float t);
extern void fn_889C2678(void *self, Obj *o, Out *out);
static __inline float fabsf_(float x) { return x < 0 ? -x : x; }
double fabs(double);
#pragma intrinsic(fabs)
void f(void *self, Obj *o, float t, Out *out){ __vector4 tmp, hi, lo, mid, half; float eps; float target = o->f36c; int i;
 fn_888ABCC0(&tmp, o, t); half = __vmulfp(vx1_replicate(lbl_8814B910), vx1_replicate(1.0f)); lo = o->v350; hi = tmp; eps = 0.01f;
 for (i = 0; i < 10; i++) { float r;
  mid = __vmulfp(__vaddfp(hi, lo), half); o->v350 = mid;
  fn_889C2678(self, o, out); r = out->f28;
  if ((float)fabs(r - target) < eps) break;
  if (r < target) hi = mid; else lo = mid; } }