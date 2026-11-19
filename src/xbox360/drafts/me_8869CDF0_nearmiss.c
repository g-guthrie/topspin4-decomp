/* agD round 2: still 26 plain and LTCG. vt local inside the t block, block-local Quad pointer in sub2_init, p3 local, Sub2 extended over the vectors with t-pointer stores (82-89): no gain. */
/* NEAR MISS fn_8869CDF0 constructor (agentA2-agD 2026-11-19): 75 -> 26 off, plain /Oc. A block-local `Sub2 *t = &s->t` opened before sub_init(&s->s[3]) moves the s[2] dead addi early like the target.
 * Remaining: lis for lbl_880D75FC still after addi 0x100 (target: before), and the tail li 0x160.. / addi 0x144 come
 * earlier than the target (target keeps the 0x144 dead addi late, among the f28 stores). Tried vt locals at 6 positions,
 * p2/p3 locals, pair helper, loop, moving the t block span: no better. */
#include "vx1_vector.h"
typedef struct Quad { int w[4]; } Quad;
typedef struct Sub { void *vt; int a[4]; union { int b[12]; Quad q[3]; }; } Sub;
typedef struct Sub2 { void *vt; Quad q; } Sub2;
typedef struct Self { void *vt; int f4, f8, fc; int f10, f14, f18; int f1c, f20, f24; int f28, f2c, f30; Sub s[4]; Sub2 t; int pad[2]; __vector4 v[4]; unsigned char b[4]; } Self;
extern char lbl_880F4314[];
extern char lbl_880D7600[];
extern char lbl_880D75FC[];
static __inline void quad_init(Quad *q) { q->w[0] = 0; q->w[1] = 0; q->w[2] = 0; q->w[3] = 0; }
static __inline void arr_init(int *b) { Quad *q = (Quad *)b; quad_init(&q[0]); quad_init(&q[1]); quad_init(&q[2]); }
static __inline void sub_init(Sub *p) { p->vt = lbl_880D7600; arr_init(p->b); p->a[0] = 0; p->a[1] = 0; p->a[2] = 0; p->a[3] = 0; }
static __inline void sub2_init(Sub2 *p, void *vt) { p->vt = vt; quad_init(&p->q); }
Self *ts4_ctor_8869CDF0(Self *s)
{
    __vector4 z;
    s->vt = lbl_880F4314;
    { int *p = &s->f10; *p = 0; }
    s->f14 = 0;
    s->f18 = 0;
    sub_init(&s->s[0]);
    sub_init(&s->s[1]);
    sub_init(&s->s[2]);
    { Sub2 *t = &s->t; sub_init(&s->s[3]);
    sub2_init(t, lbl_880D75FC); }
    z = __vspltisw(0);
    s->v[0] = z;
    s->f28 = -1;
    s->v[2] = z;
    s->f2c = -1;
    s->v[1] = z;
    s->f30 = -1;
    s->f1c = 0;
    s->v[3] = z;
    s->f20 = 0;
    s->f24 = 0;
    s->b[0] = 0; s->b[1] = 0; s->b[2] = 0; s->b[3] = 0;
    return s;
}
