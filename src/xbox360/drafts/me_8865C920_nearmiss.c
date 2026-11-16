/* NEAR MISS 0x8865C920: 27 off, all in the final winner/loser item stores (target reads the item offset once,
 * computes the loser item as base - r*0x18 with a dead +0x18 and an extra copy); everything above matches. */
/* 0x8865C920 (hand match): end-of-point handling. Unless the state is frozen, asks the owner for the next
 * server. A normal point (not the special named mode and no forced result) continues play when allowed
 * (the same gate as 0x8866AAF8): run the three restart hooks and record the server, otherwise record -1.
 * The special mode or a forced result ends the match: raise the end flags, record the winner (the other side
 * of the side record in special mode, the forced winner otherwise), mark the result final, give the winner
 * the full step count and the loser zero, then run the finish hook. Siblings: 0x8865CCD0, 0x8865D108. */
typedef struct State { char p[0x91]; unsigned char ended_a; unsigned char ended_b; unsigned char frozen; char p1;
    unsigned char foreign; char p2[0x328 - 0x96]; unsigned char locked; char p3; unsigned char active; } State;
typedef struct Side { char p[0x54]; int current; char p1[0x64 - 0x58]; int loser; char p2[0xcc - 0x68]; unsigned char end_cc;
    char p3[0xd4 - 0xcd]; unsigned char end_d4; unsigned char end_d5; unsigned char end_d6; } Side;
typedef struct Name { unsigned int hash; } Name;
typedef struct Forced { char p[0x40]; unsigned char set; char p1[3]; int winner; } Forced;
typedef struct Limits { char p[0x1d4]; int steps; char p1[0x1e0 - 0x1d8]; unsigned char allow; } Limits;
typedef struct Ctx { char p[0x28]; Forced *forced; char p1[4]; State *state; char p2[4]; Limits *limits;
    char p3[0x44 - 0x3c]; Side *side; Name *name; } Ctx;
typedef struct Item { char p[0xc]; int steps; char p1[8]; } Item;
typedef struct Items { int offset; } Items;
typedef struct Data { char p[9]; unsigned char allow; char p1[0x24 - 0xa]; Items items; char p2[0x47 - 0x28]; unsigned char final; int result; } Data;
typedef struct Obj Obj;
typedef struct ObjVt { void *s[7]; void (*finish)(Obj *self); int (*server_for)(Obj *self, Name *name); void *s2[5];
    void (*restart_b)(Obj *self); void *s3; void (*restart_a)(Obj *self); } ObjVt;
struct Obj { ObjVt *vt; Ctx *ctx; Data *data; };
static __forceinline unsigned char foreign5(Ctx *c, State *s, int index) { unsigned char b; if (index == -1 || index == c->side->current || s->locked) b = 0; else b = 1; return b; }
static __forceinline Item *item(Items *t, int i) { return (Item *)((char *)t + (i * 0x18 + t->offset)); }
void ts4_end_point_8865C920(Obj *o)
{
    int server;
    unsigned char special;
    if (o->ctx->state->frozen)
        return;
    server = o->vt->server_for(o, o->ctx->name);
    special = 0x22703895 == o->ctx->name->hash;
    if (!special && !o->ctx->forced->set) {
        Ctx *c = o->ctx;
        State *s = c->state;
        unsigned char ok = 1;
        if (s->active) {
            unsigned char fr = foreign5(c, s, server);
            s->foreign = fr;
            if (fr) {
                if (!o->data->allow && !o->ctx->limits->allow)
                    ok = 0;
            } else {
                if (0xC9238771 == o->ctx->name->hash)
                    ok = 0;
            }
        } else {
            s->foreign = 0;
        }
        if (ok) {
            o->vt->restart_a(o);
            o->vt->restart_b(o);
            o->vt->finish(o);
            o->data->result = server;
        } else {
            o->data->result = -1;
        }
        return;
    }
    o->ctx->state->ended_b = 1;
    o->ctx->state->ended_a = 1;
    o->ctx->state->frozen = 1;
    o->ctx->side->end_cc = 1;
    o->ctx->side->end_d4 = 1;
    o->ctx->side->end_d5 = 1;
    o->ctx->side->end_d6 = 1;
    if (special)
        o->data->result = 1 - o->ctx->side->loser;
    else if (o->ctx->forced->set)
        o->data->result = o->ctx->forced->winner;
    o->data->final = 1;
    { Ctx *c = o->ctx; Data *d = o->data; int r = d->result; Items *t = &d->items; int z = 0;
      item(t, r)->steps = c->limits->steps; item(t, 1 - r)->steps = z; }
    o->vt->finish(o);
}
