/* me_8866BFE8 near-miss: 85 off (LTCG + primer). MovePlanner jog slack: frames until the planner's sample minus the
   predicted run time (first index where the run curve starts moving away from the path target, or n + 0.1*sqrt(dist^2)).
   Residue: we need r29-r31 + a 0x40 frame (target: only r31 via std, 0x20 temp); target reloads pl->pc->body inside the
   loop preamble and everything at the tail via +0x154. Tried 8 variants (address spellings, RelArray inline, ?: pick). */
#include "vx1_vector.h"
extern double sqrt(double);
#pragma intrinsic(sqrt)
static __inline float dot3(__vector4 a, __vector4 b) { Vx1Vec t; t.v = __vmsum3fp(a, b); return t.v.v[0]; }

typedef struct RelArray { int off; int count; } RelArray;
static __inline __vector4 ra_at(RelArray *a, int i) { return *(__vector4 *)((char *)a + a->off + i * 16); }
typedef struct PathTable { int pad; RelArray pts; } PathTable;       /* self-relative array of 16-byte points at &rel + rel */
typedef struct PathSet { char p[0x60]; PathTable track; } PathSet; /* +0x00 normal, +0x60 alt (bb+0xbd1) */
typedef RelArray Curve;               /* self-relative points at &rel + rel */
typedef struct Body { char p[0x8e0]; __vector4 pos; char q[0x2d8]; int path_idx; char r[5]; unsigned char alt_path; } Body;
typedef struct Sample { char p[0x24]; int frame; char q[8]; } Sample;
typedef struct SampleOwner { char p[0x5a0]; Sample *samples; } SampleOwner;
typedef struct SampleRef { char p[0x88]; SampleOwner *o; } SampleRef;
typedef struct Clock { char p[0x310]; int frame; } Clock;
typedef struct ClockRef { char p[0x30]; Clock *c; } ClockRef;
typedef struct Movement { char p[0x380]; Curve run; } Movement;
typedef struct PlayerCtx { char p[0x48]; ClockRef *clk; char q[0x28]; Body *body; Movement *mv; char r[0x38]; SampleRef *sr; } PlayerCtx;
typedef struct Planner { char p[0x2c]; PathSet *paths; char q[0x124]; PlayerCtx *pc; } Planner;

float fn_8866BFE8(Planner *pl)
{
    Body *bb = pl->pc->body;
    PathSet *ps = pl->paths;
    PathTable *t = (PathTable *)ps;
    Curve *cv;
    __vector4 target, d;
    float best, cur, frames;
    int i, n, hit;
    if (!bb->alt_path) t = &ps->track;
    bb = pl->pc->body;
    cv = &pl->pc->mv->run;
    target = ra_at(&t->pts, bb->path_idx);
    d = __vsubfp(target, bb->pos);
    best = dot3(d, d);
    n = cv->count;
    hit = n;
    for (i = 1; i < n; i++) {
        d = __vsubfp(__vsubfp(target, pl->pc->body->pos), ra_at(cv, i));
        cur = dot3(d, d);
        if (best < cur) { hit = i; break; }
        best = cur;
    }
    frames = (float)hit;
    if (hit == n) frames = (float)sqrt(best) * 0.1f + frames;
    return (float)(pl->pc->sr->o->samples[pl->pc->body->path_idx].frame - pl->pc->clk->c->frame) - frames;
}
