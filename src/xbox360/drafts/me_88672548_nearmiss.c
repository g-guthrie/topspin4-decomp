/* near-miss 0x88672548 (LTCG, context pp1_pool_primer.c): 31 instructions off, same size. Open: r7/r8 swap for constant 1 vs 0x9E51242B; first player_entry address association (target (idx+base)+off, we (idx+off)+base); hash kept in r31 by target. */
/* 0x88672548: resets the rally/serve tracker and the current player's swing record at the start of a point. */
typedef unsigned int u32;
typedef struct Track {
    int a[7]; unsigned char b1c; char p1[3]; int c[3]; int idx[3]; unsigned char f38, f39, f3a;
} Track;
typedef struct PlEntry { char p[0xbc]; u32 shot; float t; char p2[0xc5 - 0xc4]; unsigned char c5; char p3[0xd1 - 0xc6]; unsigned char d1; char p4[0x130 - 0xd2]; float blend; char p5[0x140 - 0x134]; } PlEntry;
typedef struct RelTbl { int self_off; } RelTbl;
typedef struct PlList { char p[0x104]; RelTbl tbl; } PlList;
typedef struct PlWorld { char p[0x44]; PlList *list; } PlWorld;
typedef struct Out {
    char p[0x4c0]; int n4c0; char p1[0x5d8 - 0x4c4]; unsigned char b5d8, b5d9; char p2[0x66c - 0x5da]; float f66c;
    char p3[0x6f0 - 0x670]; unsigned char b6f0, b6f1; char p4[0x778 - 0x6f2]; float f778; char p5[0xe00 - 0x77c]; float fe00;
    char p6[0xebc - 0xe04]; int nebc;
} Out;
typedef struct Mx { char p[0x5c]; u32 hash; } Mx;
typedef struct Mode { char p[0x14]; Mx *mx; char p2[0x70 - 0x18]; unsigned char b70, b71; } Mode;
typedef struct Owner { char p[0x14]; int player; char p2[0x3c - 0x18]; u32 shot; char p3[0x48 - 0x40]; PlWorld *world; char p4[0x5c - 0x4c]; Mode *mode; char p5[0x74 - 0x60]; Out *out; } Owner;
typedef struct Rally { char p[0x1c]; Owner *owner; char p2[0x38 - 0x20]; Track *track; char p3[0x40 - 0x3c]; unsigned char b40, b41, b42; } Rally;
extern float g_ts4_event_value;
static __inline PlEntry *player_entry(Owner *o)
{
    RelTbl *t = &o->world->list->tbl;
    return (PlEntry *)((char *)t + t->self_off) + o->player;
}
static __inline PlEntry *player_entry2(Owner *o)
{
    RelTbl *t = &o->world->list->tbl;
    return (PlEntry *)((char *)t + (t->self_off + o->player * (int)sizeof(PlEntry)));
}
static __inline void track_reset(Track *t)
{
    t->a[0] = 0; t->a[1] = 0; t->a[2] = 0; t->a[3] = 0; t->a[4] = 0; t->a[5] = 0; t->a[6] = 0;
    t->b1c = 0;
    t->c[0] = 0; t->c[1] = 0; t->c[2] = 0;
    t->f38 = 0; t->f39 = 0; t->f3a = 0;
}
void fn_88672548(Rally *s)
{
    PlEntry *e;
    u32 shot = 0x968230B3u;
    s->b42 = 0;
    s->b41 = 0;
    {
        Track *t = s->track;
        t->idx[0] = -1; t->idx[1] = -1; t->idx[2] = -1;
        track_reset(t);
    }
    s->track->c[0] = 0;
    s->track->f3a = 1;
    s->owner->out->nebc = 0;
    s->owner->out->n4c0 = 0;
    s->owner->out->b5d8 = 1;
    s->owner->out->b5d9 = 0;
    {
        Mode *m = s->owner->mode;
        m->b70 = 0;
        m->mx->hash = 0x9E51242Bu;
        m->b71 = 0;
    }
    e = player_entry(s->owner);
    e->blend = 0.9999f;
    player_entry2(s->owner)->d1 = 1;
    s->b40 = 0;
    e->shot = shot;
    s->owner->shot = shot;
    s->owner->out->f778 = g_ts4_event_value;
    e->t = g_ts4_event_value;
    e->c5 = 0;
    s->owner->out->fe00 = g_ts4_event_value;
    s->owner->out->f66c = g_ts4_event_value;
    s->owner->out->b6f1 = 0;
    s->owner->out->b6f0 = 0;
}
