/* Q5h4 equivalent tier: end-of-point handling, sister 0x8865D108 (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * Clone of eq_q5_gameplay_end_point.cpp (0x8865CCD0). The two functions have the same code; only the relative
 * branch displacements differ. Passes tools/fn_equiv.py with /Oc; it is NOT a byte match (6 off under /Oc: an
 * r6/r7 swap and the add operand order in the final winner/loser item stores, plus a dead `mr` and `addi` in the target).
 *
 * Behaviour: unless the state is frozen, asks the owner for the next server. A normal point (not the special named
 * mode 0x22703895 and no forced result) continues play when allowed: run the three restart hooks and the finish hook
 * and record the server, otherwise record -1. The special mode or a forced result ends the match: raise the end
 * flags, record the winner, mark the result final, give the winner the full step count and the loser zero, then run
 * finish(). The four op1_pad locals are dead (repo convention); they take the build from 19 to 6 off. */
typedef struct Q5h4State { char p[0x91]; unsigned char ended_a; unsigned char ended_b; unsigned char frozen; char p1;
    unsigned char foreign; char p2[0x328 - 0x96]; unsigned char locked; char p3; unsigned char active; } Q5h4State;
typedef struct Q5h4Side { char p[0x54]; int current; char p1[0x64 - 0x58]; int loser; char p2[0xcc - 0x68]; unsigned char end_cc;
    char p3[0xd4 - 0xcd]; unsigned char end_d4; unsigned char end_d5; unsigned char end_d6; } Q5h4Side;
typedef struct Q5h4Name { unsigned int hash; } Q5h4Name;
typedef struct Q5h4Forced { char p[0x40]; unsigned char set; char p1[3]; int winner; } Q5h4Forced;
typedef struct Q5h4Limits { char p[0x1d4]; int steps; char p1[0x1e0 - 0x1d8]; unsigned char allow; } Q5h4Limits;
typedef struct Q5h4Ctx { char p[0x28]; Q5h4Forced *forced; char p1[4]; Q5h4State *state; char p2[4]; Q5h4Limits *limits;
    char p3[0x44 - 0x3c]; Q5h4Side *side; Q5h4Name *name; } Q5h4Ctx;
typedef struct Q5h4Item { char p[0xc]; int steps; char p1[8]; } Q5h4Item;
typedef struct Q5h4Items { int offset; } Q5h4Items;
typedef struct Q5h4Data { char p[9]; unsigned char allow; char p1[0x24 - 0xa]; Q5h4Items items; char p2[0x47 - 0x28]; unsigned char final; int result; } Q5h4Data;
struct Q5h4Obj {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void finish(); virtual int server_for(Q5h4Name *name);
    virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13();
    virtual void restart_b(); virtual void s15(); virtual void restart_a();
    Q5h4Ctx *ctx; Q5h4Data *data;
};
static inline unsigned char q5h4_foreign5(Q5h4Ctx *c, Q5h4State *s, int index) { unsigned char b; if (index == -1 || index == c->side->current || s->locked) b = 0; else b = 1; return b; }
static inline Q5h4Item *q5h4_item(Q5h4Items *t, int i) { return (Q5h4Item *)((char *)t + (i * 0x18 + t->offset)); }

/* 0x8865D108 */
extern "C" void ts4_end_point_8865D108(Q5h4Obj *o)
{ int op1_pad0 = 0, op1_pad1 = 0, op1_pad2 = 0, op1_pad3 = 0;
    (void)op1_pad0; (void)op1_pad1; (void)op1_pad2; (void)op1_pad3;
    int server;
    unsigned char special;
    if (o->ctx->state->frozen)
        return;
    server = o->server_for(o->ctx->name);
    special = 0x22703895 == o->ctx->name->hash;
    if (!special && !o->ctx->forced->set) {
        Q5h4Ctx *c = o->ctx;
        Q5h4State *s = c->state;
        unsigned char ok = 1;
        if (s->active) {
            unsigned char fr = q5h4_foreign5(c, s, server);
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
            o->restart_a();
            o->restart_b();
            o->finish();
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
    { Q5h4Item *w = q5h4_item(&o->data->items, o->data->result); Q5h4Item *l = q5h4_item(&o->data->items, 1 - o->data->result);
      w->steps = o->ctx->limits->steps; l->steps = 0; }
    o->finish();
}
