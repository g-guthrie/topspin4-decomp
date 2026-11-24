/* nearmiss: 49 off (LTCG, primer context, /Oc); blocker: the copy of *b must be pos via ld/std (Vx1Vec struct copy), vel via lvx/stvx and the 0x20 tail via ld/std with no dead `addi r5,r5,0x20`; the sub-struct tail copy below leaves that addi, which keeps b live and costs an extra saved GPR (__savegprlr_27 vs _28) and shifts every register. Whole-struct `*b` copies give lvx for pos (56-59 off). Copy-statement order is NOT inert here. Odds improve once the Vx1Mover copy/operator shape is recovered (caller 0x8867DA30 is also open). */
/* 0x8826CA40: *out = *a + (*b - *a) * t for a mover {pos, vel, spin, speed}. */
#include "vx1_vector.h"
typedef struct Vx1MoverL {
    Vx1Vec pos;                 /* +0x00 */
    Vx1Vec vel;                 /* +0x10 */
    Vx1Vec k;                   /* +0x20: spin, speed in lanes 0/1 */
} Vx1MoverL;
static __inline void vsub_(Vx1Vec *d, const Vx1Vec *a) { d->v = __vsubfp(d->v, a->v); }
static __inline void vmul_(Vx1Vec *d, __vector4 s) { d->v = __vmulfp(d->v, s); }
static __inline void vadd_(Vx1Vec *d, const Vx1Vec *a) { d->v = __vaddfp(d->v, a->v); }
static __inline void fadd_(float *d, const float *a) { *d += *a; }
void fn_8826CA40(Vx1MoverL *out, const Vx1MoverL *a, const Vx1MoverL *b, float t)
{
    Vx1MoverL d;
    __vector4 ts;
    d.pos = b->pos;
    d.vel.v = b->vel.v;
    d.k = b->k;
    vsub_(&d.pos, &a->pos);
    vsub_(&d.vel, &a->vel);
    d.k.v.v[0] -= a->k.v.v[0];
    d.k.v.v[1] -= a->k.v.v[1];
    ts = vx1_replicate(t);
    vmul_(&d.pos, ts);
    vmul_(&d.vel, ts);
    d.k.v.v[0] *= t;
    d.k.v.v[1] *= t;
    *out = *a;
    vadd_(&out->vel, &d.vel);
    vadd_(&out->pos, &d.pos);
    fadd_(&out->k.v.v[0], &d.k.v.v[0]);
    fadd_(&out->k.v.v[1], &d.k.v.v[1]);
}
