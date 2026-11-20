/* 0x88682B58 (hand match, LTCG route /Oc /Ob1, context me_ts4_rng_range_8861E598.c): builds a new aim point from the
 * body position. z is minus a random value in [cfg->lo, cfg->hi] (ts4_rng_range_8861E598), flipped when the
 * layout flag is set with hash 0xD826E563. x is minus the front offset when the current row's count reaches
 * cfg->limit, otherwise minus the far or near back offset. The point is stored as the self's float3 aim and the body's
 * aim vector, the body state is set to 0x487570E4, every item of the one or two entry lists (two in mode 2) gets state
 * 0x968230B3, and the dirty byte is cleared.
 * Owner accesses go through `Own **po = &s->o`, which makes the owner reload after the float stores match. */
#include "vx1_vector.h"
typedef unsigned char u8;
typedef struct Rng { int a, b, c; } Rng;
typedef struct Cfg { char p[0x24]; float back_far; float back_near; float front; unsigned int limit; char p2[0x3c - 0x34]; float lo; float hi; } Cfg;
typedef struct L30 { char p[0xac]; unsigned int fac; char p2[0x32a - 0xb0]; u8 f32a; } L30;
typedef struct L20 { char p[0x10]; struct Lst **arr; char p2[0x30 - 0x14]; L30 *f30; } L20;
typedef struct Lst { char p[0x28]; int row; } Lst;
typedef struct L4c { char p[0x20]; L20 *f20; char p2[0x28 - 0x24]; int f28; int f2c; } L4c;
typedef struct Rel { int rel; } Rel;
typedef struct Row { char p[0x10]; unsigned int count; char p2[0x40 - 0x14]; } Row;
typedef struct T50 { char p[0x4c]; Rel rows; } T50;
typedef struct F44b { char p[0x99]; u8 f99; } F44b;
typedef struct L48 { char p[0x44]; F44b *f44; char p2[0x50 - 0x48]; T50 *f50; } L48;
typedef struct Body { char p[0x8e0]; __vector4 pos; char p2[0x9a0 - 0x8f0]; __vector4 aim; char p3[0x9fc - 0x9b0]; unsigned int state; } Body;
typedef struct Pl { char p[0x44]; char *f44; L48 *f48; L4c *f4c; char p2[0x74 - 0x50]; Body *f74; } Pl;
typedef struct Ent { Rel items; int n; char p[8]; } Ent;
typedef struct Item { int a; unsigned int state; } Item;
typedef struct T28 { char p[0x98]; Rel ents; } T28;
typedef struct Own { char p[8]; Pl *pl; char p2[0x18 - 0xc]; Cfg *cfg; char p3[0x28 - 0x1c]; T28 *f28; } Own;
typedef struct V3 { float x, y, z; } V3;
typedef struct Self { char p[0x1c]; Own *o; V3 aim; u8 f2c; } Self;
float ts4_rng_range_8861E598(Rng *r, float lo, float hi);
static __inline void store3(V3 *d, __vector4 v)
{
    V3 t;
    __stvewx(__vspltw(v, 0), &t, 0);
    __stvewx(__vspltw(v, 1), &t, 4);
    __stvewx(__vspltw(v, 2), &t, 8);
    d->x = t.x; d->y = t.y; d->z = t.z;
}
void ts4_reset_aim_target_88682B58(Self *s)
{
    Own **po = &s->o;
    Own *o = *po;
    Pl *p = o->pl;
    Cfg *c = o->cfg;
    float lo = c->lo, hi = c->hi;
    u8 flag = 0;
    float sign;
    __vector4 v;
    unsigned n, j;
    L30 *l = p->f4c->f20->f30;
    if (l->f32a && l->fac == 0xD826E563) flag = 1;
    if (flag) sign = -1.0f; else sign = 1.0f;
    {
        float r = ts4_rng_range_8861E598((Rng *)(p->f44 + 0xb4), lo, hi);
        Pl *q = (*po)->pl;
        L4c *m = q->f4c;
        Lst *e = m->f20->arr[m->f28 == 0];
        L48 *b = q->f48;
        Rel *h = &b->f50->rows;
        Row *row;
        v = vx1_set_z(q->f74->pos, -(r * sign));
        row = (Row *)((char *)((Row *)h + e->row) + h->rel);
        if (row->count >= c->limit) v = vx1_set_x(v, -c->front);
        else if (!b->f44->f99) v = vx1_set_x(v, -c->back_far);
        else v = vx1_set_x(v, -c->back_near);
    }
    {
        V3 t;
        __stvewx(__vspltw(v, 0), &t, 0);
        __stvewx(__vspltw(v, 1), &t, 4);
        __stvewx(__vspltw(v, 2), &t, 8);
        s->aim.x = t.x; s->aim.y = t.y; s->aim.z = t.z;
    }
    (*po)->pl->f74->aim = v;
    (*po)->pl->f74->state = 0x487570E4;
    n = ((*po)->pl->f4c->f2c == 2) + 1;
    for (j = 0; j < n; j++) {
        Rel *h = &(*po)->f28->ents;
        Ent *e = (Ent *)((char *)h + (j * 16 + h->rel));
        int k, cnt = e->n;
        for (k = 0; k < cnt; k++) ((Item *)((char *)e + (k * 8 + e->items.rel)))->state = 0x968230B3;
    }
    s->f2c = 0;
}
