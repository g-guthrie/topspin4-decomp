/* nearmiss: 10 off (was 13 in w6b_c.c); check: fn_check.py <this> 'ts4_set_block_vec_8866D110=0x8866D110'.
 * Blocker: the target has a dead `addi r9,r11,0x40c` (address of the +0x40C sub-object of Ts4PlayerState) that we
 * never emit; everything after it is shifted by one instruction. Learned: the id at +0x9FC belongs to the +0x9A0
 * sub-object (move_state, +0x5C) - writing q->id and q->vec20 through one sub-object pointer keeps `addi r10,0x9a0`
 * and `li r6,0x20`. Tried for the 0x40c addi (all 10): nested V3/V4 members, rd(&field) helpers, getx/getz helpers,
 * a two-float struct cast, by-value return, set_from(q, a), references. Per DA1 the addi needs an inline helper that
 * uses the 0x40c pointer for two or more things. Registered equivalent in eq_q5_gameplay_small_b.c. */
#include "vx1_vector.h"
struct Sub40c {
    unsigned char pad00[0x3c];
    float f3c, f40;
};
struct Sub9a0 {
    unsigned char pad00[0x20];
    __vector4 vec20;
    unsigned char pad30[0x5c - 0x30];
    unsigned int id;
};
struct Blk {
    unsigned char pad000[0x40c];
    Sub40c s40c;
    unsigned char pad450[0x9a0 - 0x40c - sizeof(Sub40c)];
    Sub9a0 s9a0;
};
struct Inner { unsigned char pad[0x74]; Blk *blk; };
struct Mid { unsigned char pad[0x8]; Inner *inner; };
struct Owner { unsigned char pad[0x1c]; Mid *mid; };
static inline void get_dir(const Sub40c *a, __vector4 *v) { v->v[0] = a->f40; v->v[2] = -a->f3c; }
extern "C" void ts4_set_block_vec_8866D110(Owner *o)
{
    Blk *b = o->mid->inner->blk;
    Sub9a0 *q = &b->s9a0;
    __vector4 v;
    v.v[1] = 0.0f;
    v.v[3] = 0.0f;
    q->id = 0x9e51242b;
    get_dir(&b->s40c, &v);
    q->vec20 = v;
}
