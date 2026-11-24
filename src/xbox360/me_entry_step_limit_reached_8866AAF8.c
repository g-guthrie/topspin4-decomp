/* 0x8866AAF8 (hand match): whether the indexed entry's step counter has reached the context's limit.
 * While the state is active this is gated by either the side flag (for a foreign index) or the
 * current name hash not being the excluded one. */
typedef struct State { char p[0xa8]; int current; char p2[0x328 - 0xac]; unsigned char locked; char p3; unsigned char active; } State;
typedef struct Side { char p[0x9a]; unsigned char enabled; } Side;
typedef struct Name { unsigned int hash; } Name;
typedef struct Limits { char p[0x1d4]; int limit; } Limits;
typedef struct Ctx { char p[0x30]; State *state; char p1[4]; Limits *limits; char p2[0x44 - 0x3c]; Side *side; Name *name; } Ctx;
typedef struct Item { char p[0xc]; int step; char p2[8]; } Item;
typedef struct Rel { volatile int offset; } Rel;
typedef struct Data { char p[0x24]; Rel items; } Data;
typedef struct Obj { char p[4]; Ctx *ctx; Data *data; } Obj;
static __forceinline unsigned char foreign5(State *s, int index) { unsigned char b; if (index == -1 || index == s->current || s->locked) b = 0; else b = 1; return b; }
static __forceinline Item *itemA(Rel *t, int index) { int off = t->offset; return (Item *)((char *)t + (index * 0x18 + off)); }
static __forceinline Item *itemB(Rel *t, int index) { return (Item *)((char *)t + (index * 0x18 + t->offset)); }
static __forceinline Item *itemC(Rel *t, int index) { return (Item *)((char *)t + t->offset) + index; }
static __forceinline Item *itemD(Rel *t) { return (Item *)((char *)t + t->offset); }
unsigned char ts4_entry_step_limit_reached_8866AAF8(Obj *o, int index)
{
    Ctx *c = o->ctx;
    State *s = c->state;
    unsigned char r = 0;
    unsigned char ok = 1;
    if (s->active) {
        if (foreign5(s, index)) {
            if (!c->side->enabled)
                ok = 0;
        } else {
            if (0xC9238771 == c->name->hash) ok = 0;
        }
    }
    if (ok) {
        if (itemA(&o->data->items, index)->step + 1 >= c->limits->limit)
            r = 1;
    }
    return r;
}
