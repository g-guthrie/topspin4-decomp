/* 8868E320 near miss (agAM, round 6): 2 instructions off -- target emits
   `mr r4,r3` before `mr r31,r3`; otherwise identical. fn_8868E248 prototype
   inferred from call site. */
#include "vx1_vector.h"
typedef unsigned int u32;
typedef struct { char p[0x310]; u32 now; } M; typedef struct { char p[0x30]; M *m; } C;
typedef struct O { char p[0x48]; C *c; } O;
extern __vector4 *ts4_if_get_u32_off4c_8865EC70(__vector4 *out, O *o);
extern void fn_8868E248(O *o, __vector4 *v, u32 now);
void f(O *o){ __vector4 v; ts4_if_get_u32_off4c_8865EC70(&v,o); fn_8868E248(o,&v,o->c->m->now); }
