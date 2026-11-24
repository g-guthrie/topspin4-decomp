/* NEAR MISS 0x8866D728: 40 off (0x134 vs 0x140): loop body: target copies the init vector into 4 registers (vor x3) before the byte stores and numbers the begin pointer r8. 4 variants. */
#include "vx1_vector.h"
extern const __vector4 lbl_880FC650;
extern const float g_ts4_event_value; /* 0.0f */

typedef struct Track { __vector4 r[4]; unsigned char on; char p[3]; float v[9]; } Track;
typedef struct Body { char p[0xa2d]; unsigned char b_a2d, b_a2e; char q[0xbe0 - 0xa2f]; Track track; } Body;
typedef struct Unit { char p[0x74]; Body *body; } Unit;
typedef struct Pair { int b; int a; } Pair;
typedef struct RelPairs { int offset; } RelPairs;     /* self-relative Pair[] */
typedef struct Setup { char p[0x48]; RelPairs pairs; } Setup;
typedef struct Owner { char p[0x44]; Setup *setup; } Owner;
typedef struct Out { int best; char p[0xac]; int a; int pad; int b; } Out;
typedef struct Ctl {
    void *vt; char p0[0xc]; Unit **begin; Unit **end; char p1[8]; Owner *owner; Out *out; int pair; char p2[4]; int sel;
    char p3[0x12c]; __vector4 acc0, acc1, acc2, acc3; unsigned char f1a0, f1a1, f1a2, f1a3;
} Ctl;

/* 0x8866D728: reset the controller for its configured pair and clear every unit's tracking block. */
void ts4_ctl_reset_8866D728(Ctl *c)
{
    __vector4 zero = __vspltisw(0);
    RelPairs *tab = &c->owner->setup->pairs;
    Pair *pr = (Pair *)((char *)tab + (c->pair * 8 + tab->offset));
    Unit **it;
    c->out->a = pr->a;
    c->out->b = pr->b;
    c->out->best = 0x7FFFFFFF;
    c->acc0 = zero;
    c->acc2 = zero;
    c->acc1 = zero;
    c->sel = -1;
    c->acc3 = zero;
    c->f1a3 = 0;
    c->f1a0 = 0;
    c->f1a1 = 0;
    c->f1a2 = 0;
    {
        Unit **end = c->end;
        it = c->begin;
        if (it != end) {
        float z = g_ts4_event_value;
        do {
            if (*it) {
                Track *t;
                __vector4 k = lbl_880FC650;
                (*it)->body->b_a2d = 0;
                (*it)->body->b_a2e = 0;
                t = &(*it)->body->track;
                t->v[0] = z;
                t->on = 0;
                t->v[1] = z;
                t->v[2] = z;
                t->v[3] = z;
                t->v[4] = z;
                t->v[5] = z;
                t->v[6] = z;
                t->v[7] = z;
                t->v[8] = z;
                t->r[0] = k;
                t->r[1] = k;
                t->r[2] = k;
                t->r[3] = k;
            }
            it++;
        } while (it != end);
        }
    }
}
