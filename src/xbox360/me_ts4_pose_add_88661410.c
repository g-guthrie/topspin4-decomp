/* 0x88661410: adds another pose in place: direction, then position (vectors), then the two
 * trailing scalars. The volatile reads (d->pos, *a) only fix load order: o before d in each pair. */
#include "vx1_vector.h"
typedef struct Pose { Vx1Vec pos; Vx1Vec dir; float s[2]; } Pose;
static __inline void fadd(float *a, const float *b) { float x = *(volatile float *)a; *a = *b + x; }
static __inline void vadd(Vx1Vec *a, const Vx1Vec *b) { a->v = __vaddfp(a->v, b->v); }
void ts4_pose_add_88661410(Pose *o, const Pose *d)
{
    vadd(&o->dir, &d->dir);
    { __vector4 x = o->pos.v; o->pos.v = __vaddfp(x, *(volatile __vector4*)&d->pos.v); }
    fadd(&o->s[0], &d->s[0]);
    fadd(&o->s[1], &d->s[1]);
}
