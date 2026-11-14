/*
 * ts4core: swing-category rule walk, copied from ref/gameplay/swing_category.c (G6b: fn_886AFDF8, fn_88697E98,
 * fn_886B01A8, fn_886AC7E0). The rows come from the SCAT section (Settings PlayerTuning SwingSelectionCategory,
 * data/gameplay/shot_tree.yaml swing_category_rules). Thresholds are the PlayerTuning values of that dump.
 * Only the Normal mode is walked: the autoswing calls (AutoSwingGood/Bad) need the autoswing timer, which the core
 * does not model (gap).
 */
#include "ts4_internal.h"

#define SC_COND_NONE 0xDFA2AFF1u
#define SC_COND_FATALITY 0xC78C8F06u
#define SC_COND_GO_TO_NET 0x7E522D55u
#define SC_COND_IS_PERFECT 0x07F0DF25u
#define SC_COND_REACH_SLOW 0x693616C3u
#define SC_COND_REACH_FAST 0x60D5B606u
#define SC_COND_GOOD_REACH 0xDE050FD0u
#define SC_COND_BAD_REACH 0x42864090u
#define SC_COND_BAD_TIMING 0xD00AC582u
#define SC_COND_LATE_MANUAL 0x4041760Au
#define SC_COND_IS_FAST_BALL 0xFE98362Eu
#define SC_COND_DROP_SHOT 0x990377A5u
#define SC_COND_VOLLEY_FORWARD 0x7D633A62u
#define SC_COND_GOOD_VOLLEY_RELEASE 0x28D4D485u
#define SC_COND_BAD_VOLLEY_RELEASE 0xDE102FECu
#define SC_COND_VOLLEY_SPECTACULAR 0x1DE220E2u
#define SC_COND_INSIDE_OUT 0xBD8EA388u
#define SC_COND_SKILL_REQUIRED 0xC42EF3FEu
#define SC_SHOT_SLICE 0xFC6F57A1u
#define SC_SHOT_DROP_SHOT 0x990377A5u
#define SC_SHOT_TOPSPIN 0xD9FA1B37u

/* PlayerTuning thresholds (shot_tree.yaml swing_category_rules.thresholds; code constant 0.15 for Fatality) */
static const float MIN_SPEED_REACH = 3.5f, MIN_SPEED_BAD = 4.5f, LATE_TIMING = 0.1f, WINDOW_HI = 0.1f,
                   WINDOW_LO = -0.3f, FATALITY_POWER = 0.15f;
static const uint32_t LEVELS[6] = {8, 7, 6, 5, 4, 3};

static float min_speed(const Ts4ScInputs *in)
{
    return in->min_speed_left - in->min_speed_right >= 0.0f ? in->min_speed_right : in->min_speed_left;
}
static int in_window(const Ts4ScInputs *in) { return in->manual_timing > WINDOW_LO && in->manual_timing < WINDOW_HI; }

static int condition(uint32_t cond, const Ts4ScInputs *in)
{
    switch (cond) {
    case SC_COND_NONE: return 1;
    case SC_COND_FATALITY:
        if (!in->is_human && in->ai_net_request) return 0;
        if (in->sticky_rb && in->in_net_zone) return 0;
        return in->power > FATALITY_POWER;
    case SC_COND_GO_TO_NET: return in->sticky_rb && in->in_net_zone;
    case SC_COND_IS_PERFECT: return in->perfect_eval > 0.5f;
    case SC_COND_REACH_SLOW: return min_speed(in) > MIN_SPEED_REACH;
    case SC_COND_REACH_FAST: return min_speed(in) > MIN_SPEED_BAD;
    case SC_COND_GOOD_REACH: return min_speed(in) > MIN_SPEED_REACH && (!in->is_human || in_window(in));
    case SC_COND_BAD_REACH: return min_speed(in) > MIN_SPEED_BAD && !in_window(in);
    case SC_COND_BAD_TIMING: return in->timing_value > LATE_TIMING;
    case SC_COND_LATE_MANUAL: return in->manual_timing > LATE_TIMING && in->slow_down < 0.5f;
    case SC_COND_IS_FAST_BALL: return in->is_fast_ball || in->is_baseline_fast_ball;
    case SC_COND_DROP_SHOT: return in->shot_id == SC_SHOT_DROP_SHOT;
    case SC_COND_VOLLEY_FORWARD:
        return in->local_x + (in->team_mode_2 ? 600.0f : 450.0f) < 0.0f && in->shot_id != SC_SHOT_SLICE &&
               in->shot_id != SC_SHOT_DROP_SHOT;
    case SC_COND_GOOD_VOLLEY_RELEASE: return in->volley_release > 0.5f;
    case SC_COND_BAD_VOLLEY_RELEASE: return !(in->volley_release > 0.5f);
    case SC_COND_VOLLEY_SPECTACULAR: return in->volley_spectacular != 0;
    case SC_COND_INSIDE_OUT: return in->is_inside_out != 0;
    case SC_COND_SKILL_REQUIRED: return in->skill_ok != 0;
    }
    return 0;
}

int ts4_sc_class(int is_volley, int is_smash, uint32_t shot_id, int require_finesse)
{
    if (is_smash) return 5;
    if (is_volley) return shot_id == SC_SHOT_TOPSPIN ? 4 : 3;
    if (shot_id == SC_SHOT_SLICE || shot_id == SC_SHOT_DROP_SHOT) return 2;
    return require_finesse ? 1 : 0;
}

/* fn_886AC7E0: preference levels 8..3, first level that starts a clip (0); -1 none (frames > 0 not modelled) */
static int query_levels(Ts4ScQuery q, void *user, uint32_t category)
{
    int i;
    for (i = 0; i < 6; i++)
        if (q(user, category, LEVELS[i]) == 0) return 0;
    return -1;
}

uint32_t ts4_sc_walk(const Ts4Core *c, int cls, const Ts4ScInputs *in, Ts4ScQuery q, void *user, int *started)
{
    const uint8_t *e = c->ext.scat;
    uint32_t nc, n, off, i, category = 0;
    *started = 0;
    if (!e || cls < 0) return 0;
    nc = ts4_le32(e + 4);
    if ((uint32_t)cls >= nc) return 0;
    n = ts4_le32(e + 8 + 8 * (uint32_t)cls);       /* mode 0 = Normal */
    off = ts4_le32(e + 12 + 8 * (uint32_t)cls);
    for (i = 0; i < n; i++) {
        const uint8_t *r = e + off + 20 * i;
        uint32_t cond = ts4_le32(r + 8), alt = ts4_le32(r + 4);
        int k;
        if (cond != SC_COND_NONE && !condition(cond, in)) continue;
        category = ts4_le32(r);
        k = query_levels(q, user, category);
        if (k == -1 && alt) { category = alt; k = query_levels(q, user, category); }
        if (k == 0) { *started = 1; break; }
    }
    return category;
}
