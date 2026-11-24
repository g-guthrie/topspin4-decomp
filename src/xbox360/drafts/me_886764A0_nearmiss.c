/* near-miss 0x886764A0 (plain /Oc): 63 instructions off, same size and control flow (shared tail store for the tie/else arms). Open: scheduling and register numbering of the index arithmetic for the two set and lead lookups. */
/* 0x886764A0: updates both players' game-point lead: keeps the previous value, then sets the lead of the player at
 * or past game point who is ahead (or 1 each at the 98-98 tie-break marker). */
typedef unsigned int u32;
typedef struct RelArr { int self_off; } RelArr;
typedef struct SetScore { char p[0xc]; int games; char p2[0x18 - 0x10]; } SetScore;
typedef struct Lead { int cur; int prev; char p[8]; } Lead;
typedef struct MatchState {
    int server; char p0[4]; char p1; unsigned char over; char p2[0x24 - 0xa]; RelArr sets; char p3[0x34 - 0x28];
    unsigned char tiebreak; char p4[0x40 - 0x35]; u32 mode; char p5[0x50 - 0x44]; int games_to_win;
} MatchState;
typedef struct MatchHost { char p[0x90]; MatchState m; } MatchHost;
typedef struct LeadOwner { char p[0x3c]; RelArr leads; } LeadOwner;
typedef struct MatchCtx { char p[0x44]; MatchHost *host; char p2[0x50 - 0x48]; LeadOwner *leads; } MatchCtx;
typedef struct LeadTracker { char p[4]; MatchCtx *ctx; } LeadTracker;
static __inline Lead *lead_at(LeadTracker *t, int i)
{
    RelArr *a = &t->ctx->leads->leads;
    return (Lead *)((char *)a + (a->self_off + i * (int)sizeof(Lead)));
}
static __inline SetScore *set_at(RelArr *a, int i)
{
    return (SetScore *)((char *)a + (i * (int)sizeof(SetScore) + a->self_off));
}
void fn_886764A0(LeadTracker *t)
{
    MatchState *m = &t->ctx->host->m;
    int p, q, gp, gq, limit;
    if (m->over || m->mode == 0xC9238771u) return;
    p = m->server;
    q = p ^ 1;
    gp = set_at(&m->sets, p)->games;
    gq = set_at(&m->sets, q)->games;
    limit = m->games_to_win;
    lead_at(t, p)->prev = lead_at(t, p)->cur;
    lead_at(t, q)->prev = lead_at(t, q)->cur;
    {
        int v;
        if (m->tiebreak && gp == 0x62 && gq == 0x62) {
            v = 1;
        } else if (gp >= limit - 1 && gp > gq) {
            lead_at(t, p)->cur = gp - gq;
            lead_at(t, q)->cur = 0;
            return;
        } else if (gq >= limit - 1 && gq > gp) {
            lead_at(t, p)->cur = 0;
            lead_at(t, q)->cur = gq - gp;
            return;
        } else {
            v = 0;
        }
        lead_at(t, p)->cur = v;
        lead_at(t, q)->cur = v;
    }
}
