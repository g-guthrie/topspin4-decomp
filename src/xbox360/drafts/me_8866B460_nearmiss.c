/* nearmiss: 5 off with volatile offset (not acceptable); 25 off without it. Blocker: the dead mr r6,r9 copy of the single offset load; at() helper variants without volatile all 25 (2026-11-24). */
/* agentB 2026-11-18 pass 2: still 5 off (plain and LTCG). Non-volatile offset (25 off, 0x134), shared/copied offset local (28),
 * volatile first + at() second (19), C++ reference accessors (19-25): none reproduce the dead mr r6,r9. */
/* NEAR MISS (5 instructions): target reads sides->offset once and keeps a dead copy (mr r6,r9);
 * this source issues a second volatile load instead. Same pattern as 0x8866A7C0. */
/* 0x8866B460: decides whether the side at `idx` wins the current unit once its pending point is
 * counted. A named scoring format never ends this way, and the rule veto from the decisive-lead check
 * applies. In sudden-death mode reaching the target is enough; otherwise the side needs a two-point
 * lead (or 99 points) and the target. */
typedef struct Rules { char p[0xa8]; int side; char p2[0x328-0xac]; unsigned char strict; char p3; unsigned char enabled; } Rules;
typedef struct Flags { char p[0x9a]; unsigned char allow; } Flags;
typedef struct Mode { unsigned int hash; } Mode;
typedef struct Cfg { char p[0x1d4]; int target; char p2[0x238 - 0x1d8]; unsigned int format; } Cfg;
typedef struct Game { char p[0x30]; Rules *rules; char p2[0x38-0x34]; Cfg *cfg; char p3[0x44-0x3c]; Flags *flags; Mode *mode; } Game;
typedef struct Side { char p[0xc]; int count; char p2[0x18-0x10]; } Side;
typedef struct Sides { volatile int offset; } Sides;
typedef struct Score { char p[0x24]; Sides sides; } Score;
typedef struct Ctx { int pad; Game *g; Score *score; char p[0x10 - 0xc]; unsigned char sudden; } Ctx;
static __forceinline unsigned char pending_mismatch(Rules *r, int idx) { if (idx != -1 && idx != r->side) { if (!r->strict) return 1; } return 0; }
static __forceinline Side *at(Sides *t, int i) { int off = t->offset; return (Side *)((char *)t + (i * 24 + off)); }
unsigned char ts4_score_side_wins_with_point_8866B460(Ctx *c, int idx)
{
    Game *g = c->g;
    Rules *r;
    Cfg *cfg = g->cfg;
    unsigned char res = 0; unsigned char ok;
    Sides *t; int n, other;
    if (cfg->format != 0x6D2794E5) { ok = 1;
    r = g->rules;
    if (r->enabled) {
        if (pending_mismatch(r, idx)) {
            if (!g->flags->allow) ok = 0;
        } else {
            if (0xC9238771 == g->mode->hash) ok = 0;
        }
    }
    if (ok) {
    t = &c->score->sides;
    n = at(t, idx)->count;
    other = at(t, 1 - idx)->count;
    n++;
    if (c->sudden) res = n >= cfg->target;
    else if ((n - other >= 2 || n >= 99) && n >= cfg->target) res = 1;
    }
    }
    return res;
}
