/* 0x8867B260 (hand match): set the record count to capacity and reset every record. */
/* NEAR MISS draft (not built, not counted). See docs/agents/matching-tips.md, "Near misses parked". */
#include "vx1_vector.h"
typedef struct Rec { __vector4 v; float f10; char p[12]; } Rec;
typedef struct Rel { int off; int count; int cap; } Rel;
typedef struct In { char p[0x150]; Rel rel; } In;
typedef struct Obj { char p[0x44]; In *f44; } Obj;
extern __vector4 lbl_880FC650; extern float lbl_8814B440;
static __inline Rec *rb(Rel *a){ Rec *b = 0; if (a->off != -1) b = (Rec *)((char *)a + a->off); return b; }
static __inline Rec *re(Rel *a){ Rec *e = 0; if (a->off != -1) e = (Rec *)((char *)a + (a->count * 32 + a->off)); return e; }
typedef struct Val { __vector4 v; float f; } Val;
static __inline void fill(Rec *b, Rec *e, __vector4 v, float f){ if (b != e) { __vector4 z = v; do { b->f10 = f; b->v = z; b++; } while (b != e); } }
void ts4_reset_record_array_8867B260(Obj *o){ Rel *a = &o->f44->rel; Rec *b, *e; a->count = a->cap; b = rb(a); e = re(a); fill(b, e, lbl_880FC650, 0.0f); }
