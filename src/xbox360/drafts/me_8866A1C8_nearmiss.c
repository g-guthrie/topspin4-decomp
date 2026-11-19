/* C++ retry (agentB, 2026-11-18): Rt1Scoring as a class with real virtuals (slots 7/8/14/16) and `ts4_bool fault` (C++ bool): 10 off, the same stb register and win/lose association residue; rel/players locals, helper forms: 10 or 89-91. C kept. */
/* NEAR MISS fn_8866A1C8 (ME, 2026-11-18), base flags /Oc via fn_check: 10 instrs: stb r11/r9 (+0x104) and win/lose address arithmetic (+0x2CC..+0x2E8, original computes lose as (rel - 24w) + base + 0x18). Tried ~45 win/lose forms incl. player_at helpers, &players[!w], sizeof stride: best stays 10 (swapping win/lose statement order is neutral).
 * Source identical to src/xbox360/rt1_eq_serve_point_end.c (still EQUIVALENT per RT1). */
/*
 * RT1: StdScoring_OnPointEnd, the serve fault path (docs/gameplay/rules-and-scoring.md s4.7).
 * Source by D2G (work/army/d2g_scratch/8866A1C8_best.c, 10 instructions from a byte match, see
 * docs/agents/near-misses/D2G.failed.md); types moved to rt1_scoring.h.
 *
 * Point-end handling: in the serve phase a point won by the receiver (and judged) is a fault;
 * a first-serve fault awards nothing, a second-serve (or single-serve) fault awards the point; a
 * Let awards nothing. Withdrawal, a game-mode forced end and the short format past set 0 end the
 * match at once with a full score for the winner.
 *
 * Verdict: EQUIVALENT (work/army/RT1/fn_equiv_hashes.py = tools/fn_equiv.py with 32-bit hash
 * constants seeded, --flags /Oc --seed 1 --trials 3000: 95% block coverage;
 * work/specs/RT1/rt1_eq_serve_point_end.equiv.json). The unmodified checker reaches 82% (the
 * format / Let / forced-end branches are keyed by lis/ori hashes) with no difference found.
 */
#include "../rt1_scoring.h"

/* Match progress fraction. */
float fn_8865C3D8(struct Rt1Scoring *self);

static struct Rt1ScorePlayer *ts4_score_players(struct Rt1ScoreState *s)
{
    return (struct Rt1ScorePlayer *)((char *)s + s->players_rel);
}
static struct Rt1ScorePlayer *ts4_score_player(struct Rt1ScoreState *s, int i)
{
    return (struct Rt1ScorePlayer *)((char *)s + (s->players_rel + i * 24));
}

static struct Rt1SetEntry *ts4_set_at(struct Rt1ScorePlayer *p, int set)
{
    return (struct Rt1SetEntry *)((char *)p + (p->sets.offset + set * 12));
}

/* StdScoring_OnPointEnd: serve fault / let / double-fault rules, point award, and the forced end
   (withdrawal, game-mode request, short format past set 0). Swing_DLL.xex 0x8866A1C8 */
void ts4_scoring_on_point_end_8866A1C8(struct Rt1Scoring *self)
{
    struct Rt1ScoringOwner *o;
    ts4_bool withdrawal;
    ts4_bool award;
    if (self->match_over)
        return;
    o = self->owner;
    withdrawal = RT1_REASON_WITHDRAWAL == o->info->reason;
    if (!withdrawal && !(o->config->format == RT1_FORMAT_SHORT && self->rules->score.cur_set > 0) &&
        !o->mode->force_end) {
        award = 1;
        if (o->flow->serve_phase) {
            struct Rt1ScoreB44 *b44 = o->b44;
            int fault = self->vtbl->point_winner(self, o->info) != -1 &&
                             self->vtbl->point_winner(self, self->owner->info) != b44->server &&
                             !self->owner->flow->judging_disabled;
            self->owner->flow->fault = fault;
            if ((ts4_bool)fault) {
                if (!self->rules->second_serve && !self->owner->game_config->single_serve)
                    award = 0;
            } else if (self->owner->info->reason == RT1_REASON_LET) {
                award = 0;
            }
        } else {
            o->flow->fault = 0;
        }
        if (award) {
            int w = self->vtbl->point_winner(self, self->owner->info);
            self->vtbl->add_point(self);
            self->vtbl->update_server_and_ends(self);
            self->vtbl->refresh_display(self);
            self->rules->last_winner = w;
        } else {
            self->rules->last_winner = -1;
        }
    } else {
        struct Rt1RulesInfo *rules;
        struct Rt1ScorePlayer *win;
        struct Rt1ScorePlayer *lose;
        int sets;
        int i;
        int nwin;
        int nlose;
        o->flow->set_over = 1;
        self->owner->flow->game_over = 1;
        self->owner->flow->match_over = 1;
        self->match_over = 1;
        self->owner->b44->event_cc = 1;
        self->owner->b44->event_d4 = 1;
        self->owner->b44->event_d5 = 1;
        self->owner->b44->event_d6 = 1;
        if (withdrawal)
            self->rules->last_winner = 1 - self->owner->b44->withdraw_loser;
        else if (self->owner->mode->force_end)
            self->rules->last_winner = self->owner->mode->force_winner;
        else
            self->rules->last_winner = self->vtbl->point_winner(self, self->owner->info);
        self->rules->forced_end = 1;
        rules = self->rules;
        win = &ts4_score_players(&rules->score)[rules->last_winner];
        lose = ts4_score_player(&rules->score, 1 - rules->last_winner);
        if (self->games_to_win == 0)
            win->points = self->owner->b44->point_target;
        else
            win->points = 0;
        lose->points = 0;
        sets = self->num_sets / 2 + 1;
        win->sets_won = sets;
        lose->sets_won = 0;
        nwin = win->sets.count;
        nlose = lose->sets.count;
        for (i = 0; i < sets; i++) {
            if (i < nwin && i < nlose) {
                struct Rt1MatchRules *cfg = self->owner->config;
                struct Rt1SetEntry *e = ts4_set_at(win, i);
                struct Rt1SetEntry *le = ts4_set_at(lose, i);
                int games = cfg->games_per_set;
                ts4_bool tb = cfg->tiebreak_sets;
                e->points = 7;
                e->games = games;
                le->games = 0;
                le->points = 0;
                e->single_game = tb;
            }
        }
        if (self->num_sets == 1 && self->final_set_super_tb) {
            ts4_set_at(win, 0)->games = 1;
            ts4_set_at(win, 0)->points = 10;
            ts4_set_at(win, 0)->single_game = 1;
        }
        self->rules->score.cur_set = self->num_sets / 2;
        self->vtbl->refresh_display(self);
    }
    self->owner->flow->progress = fn_8865C3D8(self);
}
