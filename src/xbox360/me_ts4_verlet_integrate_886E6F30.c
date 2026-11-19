/* 0x886E6F30: verlet step for each of s->count points (stride 0x40): pos += damping * (pos - prev), then
 * pos += gravity; prev takes the old pos.
 * Matching notes (LTCG + pp1_pool_primer.c, /Oc): the difference reads p->pos again rather than the saved copy
 * (this gives the target's two vor128 copies of the loaded pos), and the points base is read into a local so the
 * element address is summed as offset + base. */
#include "vx1_vector.h"
typedef struct Ts4VerletPoint { __vector4 pos; __vector4 prev; char rest[0x20]; } Ts4VerletPoint;
typedef struct Ts4Verlet {
    __vector4 gravity;          /* +0x00 */
    __vector4 damping;          /* +0x10 */
    char pad[0x20];
    Ts4VerletPoint *points;     /* +0x40 */
    unsigned count;             /* +0x44 */
} Ts4Verlet;
static __inline __vector4 vmadd(__vector4 a, __vector4 b, __vector4 c) { __vector4 r = __vmaddfp(a, b, c); return r; }
void ts4_verlet_integrate_886E6F30(Ts4Verlet *s)
{
    unsigned i;
    for (i = 0; i < s->count; i++) {
        Ts4VerletPoint *pts = s->points;
        Ts4VerletPoint *p = &pts[i];
        __vector4 x = p->pos;
        __vector4 d = __vsubfp(p->pos, p->prev);
        p->prev = x;
        p->pos = vmadd(s->damping, d, p->pos);
        p->pos = __vaddfp(p->pos, s->gravity);
    }
}
