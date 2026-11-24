/* 0x886AB438 (hand match). */
#include "vx1_vector.h"
typedef struct E6c { char p[0x130]; float f130; } E6c;
typedef struct C1c { char p[0x6c]; E6c *f6c; } C1c;
typedef struct C5c { char p[0x20]; void *f20; } C5c;
typedef struct B48 { char p[0x1c]; C1c *f1c; char q[0x5c-0x20]; C5c *f5c; char r[0x7c-0x60]; void *f7c; } B48;
typedef struct F24 { char p[0xb0]; int fb0; } F24;
typedef struct B4c { char p[0x24]; F24 *f24; } B4c;
typedef struct A { char p[0x48]; B48 *f48; B4c *f4c; } A;
typedef struct Self { A *a; } Self;
typedef struct Out { char p[0x20]; Vx1Vec v20; } Out;
extern void fn_888ABCC0(Vx1Vec *out, void *obj, float t);
extern void ts4_stepper_eval_at_889C2940(void *self, void *obj, Vx1Vec *v);
void ts4_write_mirrored_vec_886AB438(Self *s, Out *o){ Vx1Vec v; A *a = s->a; B48 *b = a->f48; void *obj = b->f5c->f20; int h = a->f4c->f24->fb0;
 fn_888ABCC0(&v, obj, b->f1c->f6c->f130);
 ts4_stepper_eval_at_889C2940(b->f7c, obj, &v);
 if (h == (int)0xa2eda1e7) { vx1_vec_set_x(&v, -vx1_vec_x(&v)); vx1_vec_set_z(&v, -vx1_vec_z(&v)); o->v20.v = v.v; } else { o->v20.v = v.v; } }
