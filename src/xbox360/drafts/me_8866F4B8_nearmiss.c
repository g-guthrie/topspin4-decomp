/* me_8866F4B8 near-miss: 66 off (LTCG + primer; most lines are a one-instruction shift). Record a sample into the
   player's track: pick the track owner (flag set: the entry itself; else entry->set->pair[entry->side == 0]), then
   copy x/y, frame, both vectors, their lengths * 3.6 (m/s -> km/h), the tag and the gain.
   Shape found: entry count computed before the flag test, flag arm reads begin through an inline accessor (gives
   the clrrwi copy). Open: the else arm's real `lwz begin` reload (ours reuses r9), and the load order of
   begin/end/flag/idx in the preamble. 8 variants. */
#include "vx1_vector.h"
extern double sqrt(double);
#pragma intrinsic(sqrt)
typedef struct Track { __vector4 a; __vector4 b; float a_kmh; float b_kmh; unsigned tag; char p2c[4]; float x; float y; char p38[0x1c]; float gain; unsigned frame; } Track;
typedef struct TrackOwner { char p[0x24]; Track *base; } TrackOwner;   /* track record at base + 0x10 */
typedef struct TrackSet { char p[0x10]; TrackOwner **pair; } TrackSet;
typedef struct Ent { char p[0x20]; TrackSet *set; char q[4]; int side; } Ent;
typedef struct Clock { char p[0x7c]; int idx; char q[0x290]; unsigned frame; char r[0x14]; unsigned char flag; } Clock;
typedef struct EntVec { Ent **begin; Ent **end; } EntVec;
typedef struct PlayerCtx { char p[0x10]; EntVec ents; char q[0x18]; Clock *clk; } PlayerCtx;
typedef struct Sample { char p[0xc]; float x; float y; char q[0x10]; unsigned tag; char r[0x4d8]; __vector4 a; __vector4 b; } Sample;
typedef struct Rec { char p[0x1c]; PlayerCtx *pc; float *gain; } Rec;
static __inline EntVec *ents_of(Rec *r) { return &r->pc->ents; }
static __inline Ent *ent_at(EntVec *v, int i) { return i < (int)(v->end - v->begin) ? v->begin[i] : 0; }
static __inline float len3(__vector4 v) { Vx1Vec t; t.v = __vmsum3fp(v, v); return (float)sqrt(t.v.v[0]); }

void fn_8866F4B8(Rec *r, Sample *s)
{
    PlayerCtx *pc = r->pc;
    TrackOwner *o;
    Track *t;
    int i = pc->clk->idx;
    int n = (int)(pc->ents.end - pc->ents.begin);
    if (pc->clk->flag) {
        o = i < n ? (TrackOwner *)ents_of(r)->begin[i] : 0;
    } else {
        Ent *e = i < n ? pc->ents.begin[i] : 0;
        o = e->set->pair[e->side == 0];
    }
    t = (Track *)((char *)o->base + 0x10);
    t->x = s->x;
    t->y = s->y;
    t->frame = r->pc->clk->frame;
    {
        __vector4 a = s->a, b = s->b;
        t->a = a;
        t->b = b;
        t->a_kmh = len3(a) * 3.6f;
        t->b_kmh = len3(b) * 3.6f;
    }
    t->tag = s->tag;
    t->gain = *r->gain;
}
