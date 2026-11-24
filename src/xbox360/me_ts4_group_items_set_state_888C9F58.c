/* 0x888C9F58: under the manager lock (o->ctx->mgr+0x5c vslots 1/2), finds group 0xC0BA51F5 and, for each of its items of kind 100, calls ts4_set_state_4_8887C9A8 when on == 1, else fn_8887CA38. */

typedef unsigned int u32; typedef unsigned char u8;
typedef struct Lock Lock;
typedef struct { void *s0; void (*lock)(Lock *); void (*unlock)(Lock *); } LockVt;
struct Lock { LockVt *vt; };
typedef struct { char p[0x44]; int kind; } Item;
typedef struct { char p[0x14]; u32 id; char p18[4]; Item **first, **last; } Grp;
typedef struct { char p[0x40]; Grp **first, **last; char p48[0x5c - 0x48]; Lock lk; } Mgr;
typedef struct { char p[0x34]; Mgr *mgr; } Ctx;
typedef struct { char p[4]; Ctx *ctx; } O;
extern void ts4_set_state_4_8887C9A8(Item *i);
extern void fn_8887CA38(Item *i);
static Grp *find(Mgr *m, u32 id) {
    Grp **it;
    for (it = m->first; it != m->last; it++) if (*it && (*it)->id == id) return *it;
    return 0;
}
void ts4_group_items_set_state_888C9F58(O *o, u8 on) {
    Lock *lk = &o->ctx->mgr->lk;
    Grp *g, **it, **end;
    Item **ii;
    lk->vt->lock(lk);
    g = find(o->ctx->mgr, 0xC0BA51F5);
    for (ii = g->first; ii != g->last; ii++) {
        if ((*ii)->kind == 100) {
            if (on == 1) ts4_set_state_4_8887C9A8(*ii); else fn_8887CA38(*ii);
        }
    }
    lk->vt->unlock(lk);
}
