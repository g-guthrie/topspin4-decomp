/* agentA2 (2026-11-18 tips pass): named active index, named rel offset, volatile active, match local, operand swap: still 4 off; MSVC reassociates (i*320+off)+t to (i*320+t)+off. */
/* NEAR MISS (4 off: ctx->active / ctx->match load order and the offset add placement).
 * 0x88663050: bind the controller's cached pointers into the shared game data
 * (two sub-blocks of the court record, the rules block) and reset the active player's
 * per-player blend weight to its default. */
typedef struct Court { char p[0x178]; char base[8]; int f8[3]; int f14; } Court;
typedef struct Rules { char p[0x92c]; int start; } Rules;
typedef struct Setup { char p[0x6c]; char *rules; } Setup;
typedef struct PlayerRec { char p[0x130]; float blend; char p2[0x140 - 0x134]; } PlayerRec;
typedef struct Rel { int offset; } Rel;
typedef struct Data { char p[0x104]; Rel players; } Data;
typedef struct Match { char p[0x44]; Data *data; } Match;
typedef struct Ctx { char p[0x14]; int active; char p2[0x44 - 0x18]; Setup *setup; Match *match; char p3[0x78 - 0x4c]; char *court; } Ctx;
typedef struct Ctl { char p[0x1c]; Ctx *ctx; int *a; int *b; char p2[0x3c - 0x28]; int *rules; } Ctl;
extern float g_ts4_script_constants[];
static __inline PlayerRec *at(Rel *t, int i) { return (PlayerRec *)((char *)t + (i * sizeof(PlayerRec) + t->offset)); }
static __inline PlayerRec *rec(Ctx *x, int i) { return at(&x->match->data->players, i); }
void ts4_bind_ctl_pointers_88663050(Ctl *c)
{
    Ctx *x = c->ctx;
    float w = g_ts4_script_constants[220];
    char *k = x->court + 0x178;
    c->a = (int *)(k + 0x14);
    c->b = (int *)(k + 8);
    c->rules = (int *)(x->setup->rules + 0x92c);
    rec(x, x->active)->blend = w;
}
