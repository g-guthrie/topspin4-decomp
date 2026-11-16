/* NEAR MISS (3 instructions off): 0x8865A6B8 subtract another pose in place: two vectors
 * (direction, then position) and the two trailing scalars, each through an in-place helper.
 * Remaining diff: the offset-0 vector loads come out d-then-o (v60/v59 swapped); tried value/ref
 * helpers, casts, C++ operator-=, __restrict. */
#include "vx1_vector.h"
typedef struct Pose { Vx1Vec pos; Vx1Vec dir; float s[2]; } Pose;
static __inline void fsub(float *a, const float *b) { *a -= *b; }
static __inline void vsub(Vx1Vec *a, const Vx1Vec *b) { a->v = __vsubfp(a->v, b->v); }
void ts4_pose_subtract_8865A6B8(Pose *o, const Pose *d)
{
    vsub(&o->dir, &d->dir);
    vsub(&o->pos, &d->pos);
    fsub(&o->s[0], &d->s[0]);
    fsub(&o->s[1], &d->s[1]);
}
