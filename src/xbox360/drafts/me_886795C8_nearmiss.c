/* nearmiss 0x886795C8: 83 off (LTCG + pp1 primer); 6 variants. Residual: pc re-load/clrrwi placement in early-return checks. */
#include "vx1_vector.h"
static const float kZero = 0.0f;
void fn_8817B608(float *angle);
typedef struct Heading { float yaw; float a; char p8[4]; float b; char p10[4]; float c; } Heading;   /* body+0x9d0 */
typedef struct Body { char p[0x8e0]; __vector4 pos; char q[0xe0]; Heading head; char r[0x660]; void *anim; } Body;
typedef struct Tune { char p[0xa80]; int window; float lane; } Tune;
typedef struct TuneRef { char p[0x6c]; Tune *t; } TuneRef;
typedef struct Clock { char p[0x310]; int frame; } Clock;
typedef struct Flags { char p[0x9c]; unsigned char off; } Flags;
typedef struct Match { char p[0x28]; Flags *flags; char q[4]; Clock *clk; } Match;
typedef struct Mode { char p[0x2c]; int kind; } Mode;
typedef struct Start { char p[0x10]; int frame; } Start;
typedef struct PlayerCtx { char p[0x44]; TuneRef *tune; Match *m; Mode *mode; char q[0x24]; Body *body; char r[0xc]; Start *start; } PlayerCtx;
typedef struct Ctl { char p[0x1c]; PlayerCtx *pc; } Ctl;
static __inline PlayerCtx *pcget(PlayerCtx *p) { return p; }
static __inline PlayerCtx *pcof(Ctl *c) { return c->pc; }

void f(Ctl *c)
{
    PlayerCtx *pc;
    if (!c->pc->m->flags->off && pcof(c)->mode->kind != 2 && c->pc->body->anim
        && c->pc->tune->t->window > c->pc->m->clk->frame - c->pc->start->frame) {
        Body *b;
        Heading *h;
        float yaw, lim, z;
        Vx1Vec pos;
        unsigned char left, right;
        pc = c->pc;
        b = pc->body;
        h = &b->head;
        yaw = h->yaw;
        pos.v = b->pos;
        lim = pc->tune->t->lane * 100.0f;
        fn_8817B608(&yaw);
        left = yaw < -1.047f && yaw > -2.0945926f;
        right = yaw > 1.047f && yaw < 2.0945926f;
        z = pos.v.v[2];
        if (left && z > lim) { h->a = kZero; h->b = kZero; h->c = kZero; }
        if (right && z < -lim) { h->a = kZero; h->b = kZero; h->c = kZero; }
    }
}
