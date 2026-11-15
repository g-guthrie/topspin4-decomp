/* NEAR MISS draft (not built, not counted). See docs/agents/matching-tips.md, "Near misses parked". */
#include "vx1_vector.h"
typedef struct Rec { __vector4 v; float f10; char p[12]; } Rec;
typedef struct Rel { int off; int count; int cap; } Rel;
typedef struct In { char p[0x150]; Rel rel; } In;
typedef struct Obj { char p[0x44]; In *f44; } Obj;
extern __vector4 lbl_880FC650; extern float lbl_8814B440;
static __inline Rec *rb(Rel *a){ Rec *b = 0; if (a->off != -1) b = (Rec *)((char *)a + a->off); return b; }
static __inline Rec *re(Rel *a){ Rec *e = 0; if (a->off != -1) e = (Rec *)((char *)a + (a->count * 32 + a->off)); return e; }
void f(Obj *o){ Rel *a = &o->f44->rel; Rec *p, *e; a->count = a->cap; p = rb(a); e = re(a);
 for (; p != e; p++) { p->f10 = 0.0f; p->v = lbl_880FC650; } }