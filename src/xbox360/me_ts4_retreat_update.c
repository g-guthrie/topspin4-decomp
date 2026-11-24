#include "vx1_vector.h"
__vector4 __vsldoi(__vector4 a, __vector4 b, int imm);
#pragma intrinsic(__vsldoi)
static const float kZero = 0.0f;
extern double fabs(double);
#pragma intrinsic(fabs)

static __inline __vector4 load3(const void *p)
{
    __vector4 lo = __lvlx(p, 0);
    __vector4 hi = __lvrx(p, 12);
    hi = __vsldoi(hi, hi, 4);
    return __vor(lo, hi);
}

typedef struct Body { char p[0x8e0]; Vx1Vec pos; char q[0xb0]; Vx1Vec target; } Body;
typedef struct Unit { char p[0x74]; Body *body; } Unit;
typedef struct Info { char p[0xb8]; int slot; } Info;
typedef struct Side { char p[0x10]; Unit **units; char q[0x10]; Info *info; } Side;
typedef struct Teams { char p[0x10]; Side **sides; } Teams;
typedef struct Rally { char p[0x20]; Teams *teams; char q[4]; int serving; } Rally;
typedef struct Match { char p[0x4c]; Rally *rally; char q[0x24]; Body *body; } Match;
typedef struct Game { char p[8]; Match *match; } Game;
typedef struct Retreat { char p[0x1c]; Game *game; float home[3]; unsigned char active; } Retreat;

static __inline float pick_by_sign(float x, float zero, float pos, float neg)
{
    float r = (x >= zero) ? pos : neg;
    return r;
}

/* 0x88663208: when the opposing player strays past 360 in z, send our body toward (-1260, 0, +-480); once back inside 280, restore the saved home target. */
void ts4_retreat_update_88663208(Retreat *r)
{
    Match *m = r->game->match;
    Rally *ra = m->rally;
    Side *s = ra->teams->sides[ra->serving == 0];
    Vx1Vec v;
    v.v = s->units[s->info->slot]->body->pos.v;
    if (!r->active) {
        float z = v.v.v[2];
        if ((float)fabs(z) > 360.0f) {
            v.v.v[0] = -1260.0f;
            v.v.v[1] = kZero;
            v.v.v[3] = kZero;
            v.v.v[2] = pick_by_sign(z, kZero, 480.0f, -480.0f);
            m->body->target.v = v.v;
            r->active = 1;
        }
    } else if ((float)fabs(v.v.v[2]) < 280.0f) {
        m->body->target.v = load3(r->home);
        r->active = 0;
    }
}
