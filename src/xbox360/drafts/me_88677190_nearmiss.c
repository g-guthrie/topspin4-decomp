/* C++ retry (agentB, 2026-11-18): server_for as a real virtual (slot 8) called through an inline member fixes residue (1), but the build is 48 off (size 0x1E0 vs 0x1EC: `0 % n` still folded); count/mod/zero-local variants all 48. C kept (46). */
/* NEAR MISS 0x88677190: 46 off. Open: (1) the virtual call's argument (ctx->match) is loaded before the
 * vtable in the target; (2) the target keeps `0 % n` unfolded with each branch duplicating the two slot
 * stores; (3) `clrrwi r8,r9,0` on the incremented counter. Sibling 0x886775C8 has the same shape. */
/* 0x88677190 (hand match): sets up a game. Unless the state is frozen: puts the two players at their ends
 * for this game (they swap every six games of a twelve-game cycle) and records whether the ends changed,
 * picks the court half by game parity, asks the owner who serves, and seeds each player's slot value from
 * the serve rotation (mod 1 or 2 depending on the doubles flag). */
typedef struct Slot { int value; unsigned int end; } Slot;
typedef struct Slots { volatile int offset; char p[8]; int server; unsigned int half; } Slots;
typedef struct Side { char p[0x48]; Slots slots; } Side;
typedef struct State { char p[0x93]; unsigned char frozen; unsigned char ends_changed; char p2[0x327 - 0x95]; unsigned char doubles; } State;
typedef struct Ctx { char p[0x30]; State *state; char p2[0x44 - 0x34]; Side *side; int match; } Ctx;
typedef struct Obj Obj;
typedef struct ObjVt { void *s[8]; int (*server_for)(Obj *self, int match); } ObjVt;
struct Obj { ObjVt *vt; Ctx *ctx; char p[4]; unsigned int game; unsigned int count; int last_server; int rotation; };
static __forceinline int call_server(Obj *o) { return o->vt->server_for(o, o->ctx->match); }
static __forceinline Slot *slot(Slots *t, int i) { int off = t->offset; return (Slot *)((char *)t + (i * 8 + off)); }
static __forceinline void seed(Slots *t, int a, int b, int v, int n) { int r = v % n; slot(t, a)->value = r; slot(t, b)->value = r; }
void ts4_setup_game_ends_and_server_88677190(Obj *o)
{
    Slots *t;
    Slot *s0;
    unsigned int prev;
    int server, other, n;
    if (o->ctx->state->frozen)
        return;
    t = &o->ctx->side->slots;
    s0 = slot(t, 0);
    prev = s0->end;
    if (o->game % 12 < 6) {
        s0->end = 0x317C51B7;
        slot(t, 1)->end = 0xA2EDA1E7;
    } else {
        s0->end = 0xA2EDA1E7;
        slot(t, 1)->end = 0x317C51B7;
    }
    o->ctx->state->ends_changed = slot(t, 0)->end != prev;
    if ((o->game & 1) == 0)
        t->half = 0x23BAED9E;
    else
        t->half = 0xD826E563;
    { ObjVt *vt; int m = o->ctx->match; vt = o->vt; server = vt->server_for(o, m); }
    t->server = server;
    other = 1 - server;
    n = o->ctx->state->doubles ? 2 : 1;
    if (server != o->last_server) {
        o->count++;
        if ((o->count & 3) < 2)
            seed(t, server, other, 0, n);
        else
            seed(t, server, other, 1, n);
    } else {
        slot(t, other)->value = (1 - o->rotation) % n;
    }
}
