/* 0x8868CB18 (draft, 35 instructions off): the player's position, or its look-ahead position when
 * the target point is farther than the curve-given radius; also stores that radius.
 * Open point: the target loads `*o->target` first (v63), loads st->pos twice without combining the
 * loads (with a dead `mr r9,r10` of the state pointer between), and the far path stores the second
 * load straight to *out. Tried: plain/struct/union vector types, C and C++, by-pointer and by-value
 * inline distance helpers, lvx intrinsic for either load, both statement orders. */
#include "vx1_vector.h"
typedef struct Curves { char p[0x3f8]; char lead[0xc]; char radius[0xc]; } Curves;
typedef struct State { char p[0x8e0]; __vector4 pos; } State;
typedef struct Pc { char p[0x2c]; Curves *f2c; char p2[0x74 - 0x30]; State *f74; } Pc;
typedef struct Obj { char p[0x10]; Pc *pc; __vector4 *target; char p2[0x68 - 0x18]; float x; float radius; } Obj;
float ts4_range_lookup_881899D8(float x, const void *list);
void fn_8867A908(Pc *pc, __vector4 *out, float frames);
static __inline float dot3(__vector4 d) { __vector4 t = __vmsum3fp(d, d); return t.v[0]; }
__vector4 *ts4_position_or_lookahead_8868CB18(__vector4 *out, Obj *o)
{
    Pc *pc = o->pc;
    float x = o->x;
    float lead = ts4_range_lookup_881899D8(x, pc->f2c->lead);
    float r = ts4_range_lookup_881899D8(x, pc->f2c->radius);
    __vector4 pos;
    __vector4 d;
    o->radius = r;
    {
        State *st = pc->f74;
        d = __vsubfp(st->pos, *o->target);
        pos = st->pos;
        if (r * r < dot3(d)) {
            fn_8867A908(pc, &pos, lead);
            *out = pos;
            return out;
        }
    }
    *out = pos;
    return out;
}
