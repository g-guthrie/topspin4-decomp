/* me_8866D368 near-miss: 87 off (LTCG + primer), 79 with fk5_001.c as context. Team_OtherHitter
   (docs/gameplay/symbols.md): in doubles, when the partner is closer to the ball than the first player, carries tag
   0xC4CEEEC0 and stands on the ball's side of the first player's x, return the partner; else the first player.
   BLOCKED: the target keeps the ball vector in volatile v60 across both ts4_if_get_u32_off4c_8865EC70 calls, so it
   needs LTCG knowledge of that callee. Its only definition, the generated fk5_001.c, gets inlined when it is used as
   context (`__declspec(noinline)` on our prototype does not stop that). The other open item is the clrrwi copy of
   t->m for the ball load. 3 variants. */
#include "vx1_vector.h"
static const float kZero = 0.0f;
typedef struct PlayerCtx { char p[0x94]; char tags[8]; } PlayerCtx;
typedef struct Side { char p[0x10]; PlayerCtx **players; } Side;
typedef struct Ball { char p[0x40]; __vector4 pos; } Ball;
typedef struct BallRef { char p[0x20]; Ball *ball; } BallRef;
typedef struct Rules { char p[0x327]; unsigned char doubles; } Rules;
typedef struct Match { char p[0x10]; Side **sides; char q[0x1c]; Rules *rules; char r[0x28]; BallRef *br; } Match;
typedef struct Team { char p[0x20]; Match *m; char q[4]; int side; } Team;
__vector4 *ts4_if_get_u32_off4c_8865EC70(__vector4 *out, PlayerCtx *pc);
unsigned char fn_8826ACB8(void *tags, const unsigned *hash);
static __inline Match *matchof(Team *t) { return t->m; }
static __inline float dist(__vector4 a, __vector4 b, __vector4 zero)
{
    __vector4 d = __vsubfp(a, b);
    __vector4 sq = __vmsum3fp(d, d);
    Vx1Vec o;
    o.v = __vsel(__vmulfp(sq, __vrsqrtefp(sq)), sq, __vcmpeqfp(sq, zero));
    return o.v.v[0];
}

PlayerCtx *fn_8866D368(Team *t)
{
    Side *s = t->m->sides[t->side == 0];
    PlayerCtx **pl = s->players;
    PlayerCtx *a = pl[0];
    if (t->m->rules->doubles) {
        Vx1Vec ball, pa, pb;
        PlayerCtx *b;
        __vector4 zero;
        ball.v = matchof(t)->br->ball->pos;
        ts4_if_get_u32_off4c_8865EC70(&pa.v, a);
        b = pl[1];
        ts4_if_get_u32_off4c_8865EC70(&pb.v, b);
        zero = __vspltisw(0);
        if (dist(pb.v, ball.v, zero) < dist(pa.v, ball.v, zero)) {
            unsigned h = 0xC4CEEEC0u;
            if (fn_8826ACB8(b->tags, &h)) {
                float ax = pa.v.v[0], bx = ball.v.v[0];
                unsigned char pick;
                if (ax < kZero) pick = ax < bx; else pick = ax > bx;
                if (pick) return b;
            }
        }
    }
    return a;
}
