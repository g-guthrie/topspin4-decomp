/* rough draft 0x8866AFA0 (plain /Oc): 133 off (size 0x248 vs 0x224, missing the saved-register prologue). Sibling of 886764A0 (same lead update with a tie-break arm); apply the shared-tail structure from me_886764A0_nearmiss.c. */
/* 0x8866AFA0: updates both players' game-point lead from the current set score (tie-break: each player at game
 * point leads by the difference plus one; otherwise only the player at game point who is ahead). */
typedef struct RelArr { int self_off; } RelArr;
typedef struct SetScore { char p[0xc]; int games; char p2[0x18 - 0x10]; } SetScore;
typedef struct Lead { int cur; int prev; char p[8]; } Lead;
typedef struct MatchState { int server; char p[0x24 - 4]; RelArr sets; } MatchState;
typedef struct MatchRules { char p[0x1d4]; int games_to_win; } MatchRules;
typedef struct LeadOwner { char p[0x3c]; RelArr leads; } LeadOwner;
typedef struct MatchCtx { char p[0x38]; MatchRules *rules; char p2[0x50 - 0x3c]; LeadOwner *leads; } MatchCtx;
typedef struct LeadUpdate { char p[4]; MatchCtx *ctx; MatchState *m; char p2[0x10 - 0xc]; unsigned char tiebreak; } LeadUpdate;
static __inline Lead *lead_at(LeadUpdate *t, int i)
{
    RelArr *a = &t->ctx->leads->leads;
    return (Lead *)((char *)a + (a->self_off + i * (int)sizeof(Lead)));
}
static __inline SetScore *set_at(RelArr *a, int i)
{
    return (SetScore *)((char *)a + (i * (int)sizeof(SetScore) + a->self_off));
}
void fn_8866AFA0(LeadUpdate *t)
{
    MatchState *m = t->m;
    int p = m->server;
    int q = p ^ 1;
    int limit = t->ctx->rules->games_to_win;
    int gp = set_at(&m->sets, p)->games;
    int gq = set_at(&m->sets, q)->games;
    lead_at(t, p)->prev = lead_at(t, p)->cur;
    lead_at(t, q)->prev = lead_at(t, q)->cur;
    if (t->tiebreak) {
        if (gp >= limit - 1) lead_at(t, p)->cur = gp - gq + 1;
        else lead_at(t, p)->cur = 0;
        if (gq >= limit - 1) lead_at(t, q)->cur = gq - gp + 1;
        else lead_at(t, q)->cur = 0;
    } else if (gp >= limit - 1 && gp > gq) {
        lead_at(t, p)->cur = gp - gq;
        lead_at(t, q)->cur = 0;
    } else if (gq >= limit - 1 && gq > gp) {
        lead_at(t, p)->cur = 0;
        lead_at(t, q)->cur = gq - gp;
    } else {
        lead_at(t, p)->cur = 0;
        lead_at(t, q)->cur = 0;
    }
}
