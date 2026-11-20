/* rough draft 0x88676228 (plain /Oc): 153 off (size 0x270 vs 0x274), control flow and fields believed right; scheduling/register numbering not worked. Same family as 886764A0/8866AFA0 (game/set point flags). */
/* 0x88676228: flags the player at game point in the current set (both in a tie-break) and marks set point when
 * the player's set count is the deciding one ((sets_to_play - 1) / 2). */
typedef struct RelArr { int self_off; } RelArr;
typedef struct GameScore { int games; char p[8]; } GameScore;
typedef struct SetScore { RelArr games; char p[0x10 - 4]; int sets_won; char p2[0x18 - 0x14]; } SetScore;
typedef struct Lead { char p[0xc]; unsigned char game_point, set_point; char p2[2]; } Lead;
typedef struct MatchState { int server; char p[0x24 - 4]; RelArr sets; char p2[0x30 - 0x28]; int set; unsigned char tiebreak; } MatchState;
typedef struct MatchHost { char p[0x90]; MatchState m; char p2[0xd7 - 0x90 - sizeof(MatchState)]; unsigned char over; } MatchHost;
typedef struct MatchRules { char p[4]; int games_to_win; int sets_to_play; } MatchRules;
typedef struct LeadOwner { char p[0x3c]; RelArr leads; } LeadOwner;
typedef struct MatchCtx { char p[0x40]; MatchRules *rules; MatchHost *host; char p2[0x50 - 0x48]; LeadOwner *leads; } MatchCtx;
typedef struct PointFlags { char p[4]; MatchCtx *ctx; } PointFlags;
static __inline Lead *lead_at(MatchCtx *c, int i) { RelArr *a = &c->leads->leads; return (Lead *)((char *)a + a->self_off) + i; }
static __inline SetScore *set_at(MatchState *m, int i) { return (SetScore *)((char *)&m->sets + m->sets.self_off) + i; }
static __inline int games_in(SetScore *s, int set) { return ((GameScore *)((char *)&s->games + s->games.self_off))[set].games; }
static __inline int deciding(PointFlags *f) { return (f->ctx->rules->sets_to_play - 1) / 2; }
void fn_88676228(PointFlags *f)
{
    MatchCtx *c = f->ctx;
    MatchHost *h = c->host;
    MatchState *m;
    int p, q, gp, gq;
    if (h->over) return;
    m = &h->m;
    p = m->server;
    q = p ^ 1;
    gp = games_in(set_at(m, p), m->set);
    gq = games_in(set_at(m, q), m->set);
    if (!m->tiebreak) {
        int lim = c->rules->games_to_win - 1;
        if (gp >= lim && gp > gq) {
            lead_at(c, p)->game_point = 1;
            if (set_at(m, p)->sets_won == deciding(f)) lead_at(f->ctx, p)->set_point = 1;
        } else if (gq >= lim && gq > gp) {
            lead_at(f->ctx, q)->game_point = 1;
            if (set_at(m, q)->sets_won == deciding(f)) lead_at(f->ctx, q)->set_point = 1;
        }
    } else {
        lead_at(f->ctx, 0)->game_point = 1;
        lead_at(f->ctx, 1)->game_point = 1;
        if (set_at(m, p)->sets_won == deciding(f)) lead_at(f->ctx, p)->set_point = 1;
        if (set_at(m, q)->sets_won == deciding(f)) lead_at(f->ctx, q)->set_point = 1;
    }
}
