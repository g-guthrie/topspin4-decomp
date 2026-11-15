/* VX1: scale the x and z lanes of a mover's velocity, Swing_DLL.xex 0x8867D7C8.
 *
 * Vector rule (VX1): the target's `vor128 v61,v63,v63` before the second vrlimi128, and the reload
 * of +0x24 below the second vector store, come from changing the member through a pointer helper
 * (vx1_vec_set_x(&s->vel, ..)); writing `s->vel = vx1_set_x(s->vel, ..)` loses both. LTCG route
 * (the select table and its 1.0f/-1.0f sit in the module pool). */
#include "vx1_vector.h"

static const float vx1_zero_d7c8 = 0.0f;

static __inline float vx1_max_d7c8(float a, float b)
{
    float r = (a - b >= vx1_zero_d7c8) ? a : b;
    return r;
}

typedef struct Vx1Mover {
    unsigned char pad00[0x10];
    Vx1Vec vel;                 /* +0x10 */
    unsigned char pad20[0x24 - 0x20];
    float speed;                /* +0x24 */
} Vx1Mover;

void ts4_mover_clamp_speed_half_vel_88670C20(Vx1Mover *s);

void ts4_mover_scale_velocity_xz_8867D7C8(Vx1Mover *s, __vector4 scale)
{
    vx1_vec_set_x(&s->vel, scale.v[0] * vx1_vec_x(&s->vel));
    vx1_vec_set_z(&s->vel, vx1_vec_z(&s->vel) * scale.v[2]);
    s->speed *= vx1_max_d7c8(scale.v[0], scale.v[2]);
    ts4_mover_clamp_speed_half_vel_88670C20(s);
}
