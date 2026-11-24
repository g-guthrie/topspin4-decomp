/* 0x88679518 (hand match): when the state is 2, store the wrapped heading from the player's world
 * position to the target point, mirrored for one side hash. */
#include "vx1_vector.h"
typedef struct Out { char p[0x9d8]; float f9d8; } Out;
typedef struct L3 { char p[0xb0]; int fb0; } L3;
typedef struct L2 { char p[0x24]; L3 *f24; } L2;
typedef struct Ctx { char p[0x4c]; L2 *f4c; char p2[0x74 - 0x50]; Out *f74; } Ctx;
typedef struct Self { char p[0x1c]; Ctx *f1c; __vector4 v20; char p2[0x10]; int f40; } Self;
extern const float lbl_880C88DC;
__vector4 *ts4_if_get_u32_off4c_8865EC70(__vector4 *out, Ctx *pc);
double fn_88564BF8(double y, double x);
void ts4_angle_wrap_pi_8817B608(float *angle);
static __inline int side(Self *s) { return s->f1c->f4c->f24->fb0; }
static __inline Out *outp(Self *s) { return s->f1c->f74; }
void ts4_store_heading_to_target_88679518(Self *s)
{
    if (s->f40 != 0) {
        int h = s->f1c->f4c->f24->fb0;
        Out *o = s->f1c->f74;
        if (s->f40 == 2) {
            __vector4 w, d;
            float ang;
            d = __vsubfp(s->v20, *ts4_if_get_u32_off4c_8865EC70(&w, s->f1c));
            ang = (float)fn_88564BF8(d.v[2], d.v[0]);
            if (h == 0x317C51B7) ang = -ang; else ang = lbl_880C88DC - ang;
            ts4_angle_wrap_pi_8817B608(&ang);
            o->f9d8 = ang;
        }
    }
}
