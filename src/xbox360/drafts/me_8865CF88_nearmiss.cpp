/* agH (2026-11-19): 6 win/lose address forms x pads 0-7, ts4_max operand order, LTCG and /Ox: stays 38 off. Only the Rt1ScoreState-local form keeps the size; the target folds +0x18 into lose displacements (0x24) while we add 0x18 to the pointer. */
/* NEAR MISS 0x8865CF88 (agentA2, C++ real virtuals): 76 -> 38 off, plain /Oc, size now matches. point_winner is a
   real virtual (slot 8). Residue: win/lose address math (target keeps a dead mr copy of players_rel) and register
   numbering of the switch hashes. Tried 7 variants (counter form, win/lose order, helper forms, Rt1ScoreState local). */
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
static struct Ts4ServeSide *ts4_serve_side(struct Ts4ServeBlock *b, int i)
{ return (struct Ts4ServeSide *)((char *)b + (b->sides_rel + i * 8)); }
static struct Rt1ScorePlayer *ts4_score_player(struct Rt1ScoreState *s, int i)
{ return (struct Rt1ScorePlayer *)((char *)s + (s->players_rel + i * 24)); }
static int ts4_max(int a, int b) { return a < b ? b : a; }

extern "C" void ts4_race_scoring_add_point_8865CF88(struct Ts4ServeScoring *self)
{
    struct Rt1PointInfo *info; struct Rt1ScorePlayer *win, *lose; int w;
    { int *pc = &self->points_played; (*pc)++; }
    info = self->owner->info;
    w = self->point_winner(info);
    { struct Rt1ScoreState *s = &self->rules->score; win = &ts4_score_players(s)[w]; lose = &ts4_score_players(s)[1 - w]; }
    switch (info->reason) {
    case 0xA03CA0EDu: case 0xC222A5E0u: win->points++; break;
    case 0x5E11F1A7u: case 0x7DDEC718u: case 0xC9238771u: lose->points--; break;
    }
    win->points = ts4_max(0, win->points);
    lose->points = ts4_max(0, lose->points);
    if (win->points - lose->points >= 2 &&
        win->points >= ((struct Ts4GameConfigTarget *)self->owner->game_config)->target_points) {
        self->owner->flow->match_over = 1;
        (*(struct Ts4StatsFlags **)((char *)self->owner + 0x4C))->match_event = 1;
    }
}
/* ---- previous C draft ----
/* near-miss: 76 off, size 0x180 vs 0x17c; fn_equiv EQUIVALENT (seed 2: 187 valid/748, 13/13 blocks) *_/
/*
 * ME: race-scoring AddPoint (0x8865CF88); shared types as 0x8865C818. Counts the point; only the serving side scores. The match
 * ends when the scorer leads by two and has reached the game configuration's target (+0x1D4); the
 * winner (the server) and the receiving side's rotation slot are recorded.
 *_/
#include "/home/user/topspin4-decomp/src/xbox360/rt1_scoring.h"

struct Ts4ServeSide {                  /* stride 8 *_/
    int rotation;                      /* +0x00 serve-rotation slot *_/
    ts4_u32 end;                       /* +0x04 court end hash *_/
};
*/
