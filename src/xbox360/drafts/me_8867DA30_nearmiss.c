/* agP 2026-11-19: pointer-local pos/vel stores or clock load (with or without the volatile): 8, 15 or 31 off; no volatile-free form found. */
/* agF 2026-11-19: 13 -> 8 off (plain and LTCG). Order spin, speed, t = clock->t, pos, vel (permutation search of the five statements, plus 90 with a Clock* local). Left: target loads the clock pointer before the vector address/stack addis and does lfs t between the pos and vel stvx. Literal 0.0f on LTCG goes to __pool, not 0x8814B440 (worse). */
/* agD round 2: still 13. An inline mover_reset(&out) helper at the original point is 13; called earlier it gives 29 or 57. */
/* agD 2026-11-19: store order speed, pos, spin, vel (all 24 orders tried): 15 -> 13 off. Remaining: the vel stvx is still scheduled before the spin stfs and the clock->t lfs; clock/vel-pointer locals and a volatile store did not move it. */
/* agentA2 2026-11-19: volatile read of the second init vector gives the target vor v62 copy and size 0xfc: 30 -> 15 off (plain).
 * Remaining: scheduling only; the target stores spin/speed and pos before the vel stvx and loads the zero/clock earlier.
 * Tried: store orders, Clock/zero/vector locals, restrict/plain pointer for vel: all 15 or worse. */
/* NEAR MISS 0x8867DA30: 30 off (0xf8 vs 0xfc): target copies the init vector (vor v62) for the second member and orders the 0x74 load/stack addis differently; 8 variants incl. LTCG, init helper, struct-typed const. */
#include "../vx1_vector.h"
extern const __vector4 lbl_880FC650;
extern const __vector4 lbl_880FC7D0;
extern float lbl_8814B440; /* 0.0f */

typedef struct Vx1Mover {
    Vx1Vec pos;                 /* +0x00 */
    Vx1Vec vel;                 /* +0x10 */
    float spin;                 /* +0x20 */
    float speed;                /* +0x24 */
    unsigned char pad28[8];
} Vx1Mover;
typedef struct MoverPair { Vx1Mover a; Vx1Mover b; } MoverPair;

void ts4_mover_clamp_speed_half_vel_88670C20(Vx1Mover *s);
void ts4_mover_scale_velocity_xz_8867D7C8(Vx1Mover *s, __vector4 scale);
void fn_8826CA40(Vx1Mover *out, const Vx1Mover *to, const Vx1Mover *from, float t);

typedef struct Court { char p[0x95]; unsigned char indoor; } Court;
typedef struct Venue { char p[0x44]; Court *court; } Venue;
typedef struct Rules { char p[0x2c]; int surface; } Rules;
typedef struct Clock { char p[0x540]; float t; } Clock;
typedef struct Ctx { char p[0x48]; Venue *venue; Rules *rules; char q[0x24]; Clock *clock; } Ctx;
typedef struct Self { void *vt; int pad; MoverPair *pair; } Self;

/* 0x8867DA30: blend copies of the two (speed-clamped) movers at the clock time; on surface 2 outdoors, scale the result. */
void ts4_mover_pair_blend_8867DA30(Self *self, Ctx *ctx)
{
    MoverPair *p = self->pair;
    Vx1Mover from, to, out;
    float t;
    from = p->a;
    ts4_mover_clamp_speed_half_vel_88670C20(&from);
    to = p->b;
    ts4_mover_clamp_speed_half_vel_88670C20(&to);
    out.spin = lbl_8814B440;
    out.speed = lbl_8814B440;
    t = ctx->clock->t;
    out.pos.v = lbl_880FC650;
    out.vel.v = *(volatile __vector4 *)&lbl_880FC650;
    fn_8826CA40(&out, &to, &from, t);
    if (ctx->rules->surface == 2 && !ctx->venue->court->indoor)
        ts4_mover_scale_velocity_xz_8867D7C8(&out, lbl_880FC7D0);
}
