/* 0x8865A6B8: subtracts another pose in place: direction, then position (vectors), then the two
 * trailing scalars. The volatile read of d->pos only fixes the vector load order (o before d). */
#include "vx1_vector.h"
typedef struct Pose { Vx1Vec pos; Vx1Vec dir; float s[2]; } Pose;
static __inline void fsub(float *a, const float *b) { *a -= *b; }
static __inline void vsub(Vx1Vec *a, const Vx1Vec *b) { a->v = __vsubfp(a->v, b->v); }
void ts4_pose_subtract_8865A6B8(Pose *o, const Pose *d)
{
    vsub(&o->dir, &d->dir);
    { __vector4 x = o->pos.v; o->pos.v = __vsubfp(x, *(volatile __vector4*)&d->pos.v); }
    fsub(&o->s[0], &d->s[0]);
    fsub(&o->s[1], &d->s[1]);
}
