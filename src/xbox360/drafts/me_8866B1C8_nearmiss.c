/* near-miss: 12 off (0x8866B1C8). Needs `Pend *volatile pend` in Ctx to reproduce the ctx->pend reloads
 * (diagnostic, unconfirmed as original). Remaining: operand order of the add for items[i] (i*24+off vs off+i*24)
 * and the final leader recompute: target adds t+off for item0 and schedules the vtable load between the two adds. */
/* 0x8866B1C8: award a point (tie-break style). Asks the vtable for the scoring side, bumps that side's
 * step counter unless the reason is the excluded hash, then flags match end when the side leads by two
 * (or has reached 99) and has reached the target. Finally, if a pending change-over/replay is flagged,
 * clears the flags and either recomputes the leader (calling vtable +0x34) or marks the data done. */
typedef struct Name { unsigned int hash; } Name;
typedef struct Flow { char p[0x93]; unsigned char b93; char p2[0x2ca - 0x94]; unsigned char b2ca; } Flow;
typedef struct Limits { char p[0x1d4]; int limit; char p2[0x238 - 0x1d8]; unsigned int mode; } Limits;
typedef struct Stats { char p[0x1e]; unsigned char ev; } Stats;
typedef struct Pend { char p[0x1c]; unsigned char a; unsigned char b; char p2[0x74 - 0x1e]; unsigned char c; } Pend;
typedef struct Ctx { char p[0x30]; Flow *flow; char p1[4]; Limits *limits; char p2[0x44 - 0x3c]; Pend *volatile pend; Name *name; Stats *stats; } Ctx;
typedef struct Item { char p[0xc]; int step; char p2[8]; } Item;
typedef struct Rel { int offset; } Rel;
typedef struct Data { char p[0x24]; Rel items; char p2[0x68 - 0x28]; unsigned char done; } Data;
struct Obj;
typedef struct Vt { void *p[8]; int (*side)(struct Obj *, Name *); void *q[4]; void (*recompute)(struct Obj *); } Vt;
typedef struct Obj { Vt *vt; Ctx *ctx; Data *data; int side; unsigned char strict; } Obj;
static __forceinline Item *itemA(Rel *t, int i) { return (Item *)((char *)t + (i * 0x18 + t->offset)); }
static __forceinline Item *itemB(Rel *t, int i) { return (Item *)((char *)t + t->offset) + i; }
static __forceinline Item *itemD(Rel *t) { return (Item *)((char *)t + t->offset); }
static void count(int *p) { (*p)++; }
static __forceinline unsigned char pending(Pend *p) { unsigned char b; if (p->a && !p->b) b = 1; else b = 0; return b; }
void ts4_point_award_8866B1C8(Obj *o)
{
    Name *n = o->ctx->name;
    int s, t, i;
    Ctx *c;
    Limits *l;
    unsigned char b, rep, ch;
    i = o->vt->side(o, n);
    o->side = i;
    if (n->hash != 0x9C814967)
        count(&itemA(&o->data->items, i)->step);
    c = o->ctx;
    l = c->limits;
    s = itemA(&o->data->items, i)->step;
    t = itemB(&o->data->items, 1 - i)->step;
    if (l->mode != 0x6D2794E5) {
        b = 0;
        if (o->strict)
            b = s >= l->limit;
        else if ((s - t >= 2 || s >= 99) && s >= l->limit)
            b = 1;
        if (b) {
            c->flow->b93 = 1;
            o->ctx->stats->ev = 1;
        }
    }
    c = o->ctx;
    if (!pending(c->pend) && c->pend->c) rep = 1; else rep = 0;
    if (pending(c->pend) && c->flow->b2ca) ch = 1; else ch = 0;
    if (ch || rep) {
        if (s != t) {
            c->flow->b93 = 1;
            o->ctx->stats->ev = 1;
            o->ctx->pend->c = 0;
            o->ctx->flow->b2ca = 0;
            o->data->done = 0;
            o->side = itemB(&o->data->items, 1)->step >= itemD(&o->data->items)->step;
            o->vt->recompute(o);
        } else
            o->data->done = 1;
    }
}
