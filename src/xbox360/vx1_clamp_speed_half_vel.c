/* VX1: clamp a mover's speed to half its velocity's x/z lanes, Swing_DLL.xex 0x88670C20.
 *
 * Vector rules (VX1):
 * - The velocity is a 16-byte-aligned struct copied as a struct (`ld/ld/std/std`, then lvx128 from
 *   the stack copy). That needs the aligned __vector4 of vx1_vector.h; with ts4_vector.h's
 *   4-aligned one the copy is four lwz/stw pairs.
 * - The 0.5 splat is vx1_replicate (lvlx128 + vspltw128 0).
 * - The target addresses 0.5f as zero+0x4d0 (`lvlx128 v62,rZero,r5` with `li r5,0x4d0`): the code
 *   generator knew both constants' places in one block. A file-scope `static const` struct
 *   {zero, gap, half} reproduces that offset; separate statics give `li r5,4`, and a separate gap
 *   array is laid out after them. A stand-in for the original's constant layout (like the
 *   pp1_pool_primer context), not the original's source. LTCG route. */
#include "vx1_vector.h"

static const struct {
    float zero;                         /* +0x000: the named zero of the FP1 select */
    unsigned int gap[0x4cc / 4];
    float half;                         /* +0x4d0 */
} vx1_k_0c20 = { 0.0f, { 0 }, 0.5f };

static __inline float vx1_min_0c20(float a, float b)
{
    float r = (a - b >= vx1_k_0c20.zero) ? b : a;
    return r;
}

typedef struct Vx1Mover0c20 {
    unsigned char pad00[0x10];
    Vx1Vec vel;                 /* +0x10 */
    unsigned char pad20[0x24 - 0x20];
    float speed;                /* +0x24 */
} Vx1Mover0c20;

void ts4_mover_clamp_speed_half_vel_88670C20(Vx1Mover0c20 *s)
{
    Vx1Vec t = s->vel;
    t.v = __vmulfp(t.v, vx1_replicate(vx1_k_0c20.half));
    s->speed = vx1_min_0c20(vx1_min_0c20(t.v.v[0], t.v.v[2]), s->speed);
}
