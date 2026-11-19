/* rough draft 0x886A3DF0 (ME agent B): 92 off (/Oc). Move-to-spot controller: cancels the move when the opponent
 * is out of the reach band, picks the destination for mode 1..6 (target uses a bdz chain), and either flags arrival
 * (hash 0x8999A0BF) or retargets the anim (0x487570E4). */
#include "ts4_vector.h"
typedef unsigned char U8;
typedef unsigned int U32;
extern float g_ts4_event_value;
extern const __vector4 lbl_880FC650;
typedef struct AnimSub { __vector4 target; char p10[0x20 - 0x10]; __vector4 vel; float f30; float f34; char p38[4]; float f3c; char p40[0x5c - 0x40]; U32 state_hash; } AnimSub;
typedef struct Anim { char p[0x14]; AnimSub *sub; char p18[0x70 - 0x18]; U8 f70; U8 f71; } Anim;
typedef struct Phase { char p[0x7c]; int round; } Phase;
typedef struct TeamPl { char p[0x30]; Phase *match; } TeamPl;
typedef struct Side { char p[0xb0]; U32 side_tag; } Side;
typedef struct Team { char p[0x20]; TeamPl *lead; Side *side; int round; int kind; char p30[0x160 - 0x30]; __vector4 spots[4]; char p1a0[0x1a3 - 0x1a0]; U8 active; } Team;
typedef struct Pose { char p[0x1ec]; float lo; float hi; float reach; } Pose;
typedef struct Opp { char p[0x28]; Pose *pose; } Opp;
typedef struct Body { char p[0x8e0]; __vector4 pos; char p8f0[0xa2e - 0x8f0]; U8 arrived; char pa2f[0xc24 - 0xa2f]; float dist; } Body;
typedef struct BodyOwner { char p[0x74]; Body *body; } BodyOwner;
typedef struct Cfg { char p[0xa60]; float arrive_radius; } Cfg;
typedef struct Rules { char p[0x6c]; Cfg *cfg; } Rules;
typedef struct Ctl { char p[0x44]; Rules *rules; char p48[0x4c - 0x48]; Team *team; Opp *opp; char p54[0x5c - 0x54]; Anim *anim; void *gate; char p64[0x74 - 0x64]; Body *body; } Ctl;
typedef struct Self { char p[0x1c]; Ctl *ctl; __vector4 home; __vector4 mark; int mode; } Self;
BodyOwner *fn_8866D368(void);
void ts4_if_get_8865E730(__vector4 *v, U32 side_tag);
U8 ts4_anim_frames_to_event_886CD488(void *gate, void *out);
void fn_8869C010(Anim *a);
static __inline AnimSub *set_state(Anim *a, U32 h) { AnimSub *s = a->sub; a->f70 = 0; s->state_hash = h; a->f71 = 0; return s; }
void fn_886A3DF0(Self *self)
{
    Ctl *c = self->ctl;
    Team *t = c->team;
    if (!t->active)
        return;
    if (t->kind != 2) {
        Pose *p = c->opp->pose;
        float k = (&g_ts4_event_value)[0x134];
        if ((p->lo < k || p->hi > k) && fn_8866D368()->body->dist < p->reach) {
            float ev = g_ts4_event_value;
            set_state(c->anim, 0x9E51242B);
            self->ctl->anim->sub->vel = __vspltisw(0);
            self->ctl->anim->sub->f34 = ev;
            self->ctl->anim->sub->f3c = ev;
            self->mode = 0;
        }
    }
    if (self->mode) {
        Ctl *c2 = self->ctl;
        Team *tm = c2->team;
        __vector4 dest, pos;
        int out = 0;
        float r;
        if (tm->lead->match->round == tm->round)
            return;
        dest = lbl_880FC650;
        switch (self->mode) {
        case 1: dest = self->home; break;
        case 2: dest = self->mark; break;
        case 3: dest = tm->spots[3]; break;
        case 4: dest = tm->spots[2]; break;
        case 5: dest = tm->spots[1]; break;
        case 6: dest = tm->spots[0]; break;
        }
        ts4_if_get_8865E730(&dest, tm->side->side_tag);
        pos = c2->body->pos;
        r = c2->rules->cfg->arrive_radius;
        if (!ts4_anim_frames_to_event_886CD488(c2->gate, &out)) {
            if (!c2->body->arrived) {
                float dx = dest.v[0] - pos.v[0], dz = dest.v[2] - pos.v[2];
                if (dz * dz + dx * dx < r * r) {
                    set_state(c2->anim, 0x8999A0BF);
                    if (!self->ctl->body->arrived)
                        self->ctl->body->arrived = 1;
                }
            }
        } else {
            AnimSub *s = set_state(c2->anim, 0x487570E4);
            s->target = dest;
            fn_8869C010(self->ctl->anim);
        }
    }
}
