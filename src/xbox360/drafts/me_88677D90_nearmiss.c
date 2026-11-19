/* near-miss (agH, 2026-11-19): 19 off on LTCG (context pp1_pool_primer.c), 27 off plain. Left: one add operand order in the player-points sum, (s + rel) vs (rel + s), and the r5/r7 swap for old_end that follows from it. Tried 72 accessor combinations x pads 0-7 and statement order. fn_equiv EQUIVALENT (seed 1: 1776 valid, 18/18 blocks; seed 3: 1443 valid, 18/18). */
/*
 * 0x88677D90: tie-break UpdateServerAndEnds (serve rotation). n = points of player 1 + player 0 (score
 * state at RulesInfo+0x24). Skipped when the match is over unless the game config mode (+0x238) is the
 * tie-break hash 0x6D2794E5. Outside a tie-break, ends swap every 6 points (n % 12 >= 6); court alternates
 * each point (deuce on even n); server = (n + 3) % 4 <= 1. In a tie-break with a pending override
 * (B44+0x3B), the override is cleared, server resets to 0 and B44+0x34 replaces the court unless it equals
 * the global "none" value (lbl_88D45B1C+0x27C). Flow+0x329 with config+0x23C == 0xA0323A39 forces server 1.
 * Rotation slots: server side ((n + 1) % 8 >= 4) % d, other side (n % 4 >= 2) % d, d = doubles ? 2 : 1.
 * There is no real call here (only __savegprlr_29/__restgprlr_29). Dead locals op1_pad* steer operand numbering.
 */
#include "../rt1_scoring.h"

#define TS4_COURT_DEUCE 0x23BAED9Eu
#define TS4_COURT_AD    0xD826E563u
#define TS4_END_A       0x317C51B7u
#define TS4_END_B       0xA2EDA1E7u
#define TS4_MODE_TIEBREAK 0x6D2794E5u
#define TS4_MODE_A0323A39 0xA0323A39u

struct Ts4ServeSide { int rotation; ts4_u32 end; };
struct Ts4ServeBlock { int sides_rel; ts4_u8 pad_04[8]; int server; ts4_u32 court; };
struct Ts4TbB44 { ts4_u8 pad_00[0x34]; ts4_u32 court_override; ts4_u8 pad_38[3]; ts4_bool override_pending; ts4_u8 pad_3c[0x0C]; struct Ts4ServeBlock serve; };
struct Ts4TbFlow { ts4_u8 pad_00[0x93]; ts4_bool match_over; ts4_bool ends_changed; ts4_u8 pad_95[0x327-0x95]; ts4_bool doubles; ts4_u8 pad_328; ts4_bool forced_server; };
struct Ts4TbConfig { ts4_u8 pad_00[0x238]; ts4_u32 mode; ts4_u32 submode; };
struct Ts4TbOwner { ts4_u8 pad_00[0x30]; struct Ts4TbFlow *flow; ts4_u32 unk_34; struct Ts4TbConfig *config; ts4_u8 pad_3c[8]; struct Ts4TbB44 *b44; };
struct Ts4TbGlobal { ts4_u8 pad_00[0x27C]; ts4_u32 no_court; };
extern struct Ts4TbGlobal *lbl_88D45B1C;
struct Ts4TbScoring { void *vtbl; struct Ts4TbOwner *owner; struct Rt1RulesInfo *rules; };

static struct Ts4ServeSide *ts4_serve_side(struct Ts4ServeBlock *b, int i)
{
    return (struct Ts4ServeSide *)((char *)b + (b->sides_rel + i * 8));
}
static struct Rt1ScorePlayer *ts4_player(struct Rt1ScoreState *s, int i)
{
    return (struct Rt1ScorePlayer *)((char *)s + s->players_rel) + i;
}

static struct Rt1ScoreState *ts4_score(struct Ts4TbScoring *t) { return &t->rules->score; }
static struct Rt1ScorePlayer *ts4_player2(struct Rt1ScoreState *s, int i)
{
    return (struct Rt1ScorePlayer *)((char *)s + (s->players_rel + i * 24));
}
void fn_88677D90(struct Ts4TbScoring *self)
{
    struct Ts4ServeBlock *b;
    struct Rt1ScoreState *s;
    ts4_u32 old_end;
    int n, server, other, divisor;
    ts4_bool tb;
    tb = self->owner->config->mode == TS4_MODE_TIEBREAK;
    if (self->owner->flow->match_over && !tb)
        return;
    s = &self->rules->score;
    b = &self->owner->b44->serve;
    n = ts4_player(ts4_score(self), 0)->points + ts4_player(ts4_score(self), 1)->points;
    old_end = ts4_serve_side(b, 0)->end;
    if (!tb && n % 12 >= 6) {
        ts4_serve_side(b, 0)->end = TS4_END_B;
        ts4_serve_side(b, 1)->end = TS4_END_A;
    } else {
        ts4_serve_side(b, 0)->end = TS4_END_A;
        ts4_serve_side(b, 1)->end = TS4_END_B;
    }
    self->owner->flow->ends_changed = ts4_serve_side(b, 0)->end != old_end;
    if (n % 2 == 0)
        b->court = TS4_COURT_DEUCE;
    else
        b->court = TS4_COURT_AD;
    server = (n + 3) % 4 <= 1;
    if (tb && self->owner->b44->override_pending) {
        server = 0;
        self->owner->b44->override_pending = 0;
        {
            ts4_u32 none = lbl_88D45B1C->no_court;
            ts4_u32 c = self->owner->b44->court_override;
            if (c != none)
                b->court = c;
        }
    }
    if (self->owner->flow->forced_server && self->owner->config->submode == TS4_MODE_A0323A39)
        server = 1;
    other = 1 - server;
    b->server = server;
    divisor = ((self->owner->flow->doubles == 0) ^ 1) + 1;
    ts4_serve_side(b, server)->rotation = (int)((n + 1) % 8 >= 4) % divisor;
    ts4_serve_side(b, other)->rotation = (int)(n % 4 >= 2) % divisor;
}
