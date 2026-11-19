/* agH (2026-11-19): pad sweep 0-7 on both routes, win/lose order x helper forms (players()+i, player(i), mixed, int-index local) x pads 0-7, LTCG /Ox: best stays 8 off; MSVC always groups lose as (s - w*24) + rel and drops the mr copy. */
/* agentA2 (2026-11-18 tips pass): win-first order, named lw index, single players_rel local (size grows): best stays 8 off (plain and LTCG). */
/* NEAR MISS 0x8865C818 (agentA2, C++ real virtuals): 13 -> 8 off, plain /Oc (LTCG same). point_winner is a real
   virtual (slot 8): vcall load order now matches. Residue: the win/lose player address math (target reads players_rel
   once with a dead mr copy and computes win first). Tried 9 variants (players()/player() helper, order, single pl local). */
#include "../rt1_scoring.h"
struct Ts4ServeSide { int rotation; ts4_u32 end; };
struct Ts4ServeBlock { int sides_rel; ts4_u8 pad_04[8]; int server; };
struct Ts4ServeB44View { ts4_u8 pad_00[0x48]; struct Ts4ServeBlock serve; };
struct Ts4GameConfigTarget { ts4_u8 pad_000[0x1D4]; int target_points; };
struct Ts4StatsFlags { ts4_u8 pad_00[0x1E]; ts4_bool match_event; };
struct Ts4ServeScoring {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void refresh_display();
    virtual int point_winner(struct Rt1PointInfo *info);
    struct Rt1ScoringOwner *owner; struct Rt1RulesInfo *rules; int points_played; ts4_u8 pad_10[4]; int winner; int loser_rotation;
};
static struct Rt1ScorePlayer *ts4_score_players(struct Rt1ScoreState *s)
{ return (struct Rt1ScorePlayer *)((char *)s + s->players_rel); }
static struct Rt1ScorePlayer *ts4_score_player(struct Rt1ScoreState *s, int i)
{ return (struct Rt1ScorePlayer *)((char *)s + (s->players_rel + i * 24)); }
static struct Ts4ServeSide *ts4_serve_side(struct Ts4ServeBlock *b, int i)
{ return (struct Ts4ServeSide *)((char *)b + (b->sides_rel + i * 8)); }

extern "C" void ts4_serve_scoring_add_point_8865C818(struct Ts4ServeScoring *self)
{
    struct Ts4ServeBlock *b; struct Rt1ScorePlayer *win, *lose; int w;
    { int *pc = &self->points_played; (*pc)++; }
    b = &((struct Ts4ServeB44View *)self->owner->b44)->serve;
    w = self->point_winner(self->owner->info);
    lose = ts4_score_player(&self->rules->score, 1 - w); win = ts4_score_player(&self->rules->score, w);
    if (b->server == w) win->points++;
    if (win->points - lose->points >= 2 &&
        win->points >= ((struct Ts4GameConfigTarget *)self->owner->game_config)->target_points) {
        self->owner->flow->match_over = 1;
        (*(struct Ts4StatsFlags **)((char *)self->owner + 0x4C))->match_event = 1;
    }
    self->winner = b->server;
    self->loser_rotation = ts4_serve_side(b, 1 - b->server)->rotation;
}
/* ---- previous C draft ----
/* NEAR MISS fn_8865C818 serve-scoring AddPoint (ME, 2026-11-18), fn_check /Oc: 13 off, size matches.
 * fn_equiv --flags /Oc --seed 1 --trials 1000: EQUIVALENT (30 valid of 415, 6/6 blocks).
 * Fixed so far: the counter increment through a plain block-local pointer (keeps the owner/vtbl loads after
 * the store), the &players[i] form with &self->rules->score at each use (gives the dead mr copy).
 * Remaining: owner-before-vtbl load order at the vcall (5 instrs) and register numbering of the win/lose
 * addresses. ~45 variants. *_/
/*
 * ME: serve-scoring AddPoint (0x8865C818). Counts the point; only the serving side scores. The match
 * ends when the scorer leads by two and has reached the game configuration's target (+0x1D4); the
 * winner (the server) and the receiving side's rotation slot are recorded.
 *_/
#include "../rt1_scoring.h"
*/
