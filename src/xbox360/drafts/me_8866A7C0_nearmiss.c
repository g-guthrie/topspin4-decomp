/* agentA2 2026-11-18: still 2: single local offset read (drops volatile) goes to 37 off; two copies of the local also 37. */
/* NEAR MISS (2 instructions): target reads sides->offset once and copies it (mr r5,r9) where this
 * source issues a second volatile load. */
/* 0x8866A7C0: decides whether the side at `idx` has a decisive lead in the current scoring unit.
 * Rules may first veto the check (a pending-side mismatch without the rule flag, or a named mode);
 * then the side's count (plus one when it is the serving side) must lead the other side by two and
 * reach the configured target. */
typedef struct Rules { char p[0xa8]; int side; char p2[0x328-0xac]; unsigned char strict; char p3; unsigned char enabled; } Rules;
typedef struct Flags { char p[0x54]; int server; char p2[0x9a-0x58]; unsigned char allow; } Flags;
typedef struct Mode { unsigned int hash; } Mode;
typedef struct Cfg { char p[0x1d4]; int target; } Cfg;
typedef struct Game { char p[0x30]; Rules *rules; char p2[0x38-0x34]; Cfg *cfg; char p3[0x44-0x3c]; Flags *flags; Mode *mode; } Game;
typedef struct Side { char p[0xc]; int count; char p2[0x18-0x10]; } Side;
typedef struct Sides { volatile int offset; } Sides;
typedef struct Score { char p[0x24]; Sides sides; } Score;
typedef struct Ctx { int pad; Game *g; Score *score; } Ctx;
static __forceinline unsigned char pending_mismatch(Rules *r, int idx) { if (idx != -1 && idx != r->side) { if (!r->strict) return 1; } return 0; }
static __forceinline Side *at(Sides *t, int i) { int off = t->offset; return (Side *)((char *)t + (i * 24 + off)); }
unsigned char ts4_score_side_has_decisive_lead_8866A7C0(Ctx *c, int idx)
{
    Game *g = c->g;
    Rules *r = g->rules;
    unsigned char res = 0; unsigned char ok = 1;
    Sides *t; int n, other;
    if (r->enabled) {
        if (pending_mismatch(r, idx)) {
            if (!g->flags->allow) ok = 0;
        } else {
            if (0xC9238771 == g->mode->hash) ok = 0;
        }
    }
    if (ok) {
    t = &c->score->sides;
    { n = at(t, idx)->count;
    other = at(t, 1 - idx)->count; }
    if (g->flags->server == idx) n++;
    if (n - other >= 2 && n >= g->cfg->target) res = 1;
    }
    return res;
}
