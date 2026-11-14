/*
 * Top Spin 4 tennis rules and scoring: reference implementation.
 * See rules.h and docs/gameplay/rules-and-scoring.md.
 */
#include "rules.h"

#include <string.h>

static int other(int p) { return p ^ 1; }

/* ---- per-player records ------------------------------------------------ */

/* fn_88669C30: clear every score record. */
static void reset_scores(rules_state *rs)
{
    memset(rs->p, 0, sizeof rs->p);
    rs->cur_set = 0;
    rs->tiebreak = rs->super_tiebreak = false;
    rs->deuce = rs->deuce_first = false;
    rs->second_serve = false;
    rs->winner = -1;
    rs->match_winner = -1;
    rs->match_over = false;
    rs->tb_changeovers = rs->tb_serve_switches = 0;
    rs->ends_swapped = false;
}

int rules_total_games(const rules_state *rs)
{
    int total = 0;
    for (int i = 0; i <= rs->cur_set; i++)
        total += rs->p[0].sets[i].games + rs->p[1].sets[i].games;
    return total;
}

/* ---- display score ----------------------------------------------------- */

static int point_label(int count)
{
    static const int label[4] = { 0, 15, 30, 40 };
    return (count >= 0 && count < 4) ? label[count] : count;
}

/* fn_8865C648: fill the 0/15/30/40/-1 display values and the deuce flags. */
static void refresh_display(rules_state *rs)
{
    int c0 = rs->p[0].points;
    int c1 = rs->p[1].points;

    rs->deuce = rs->deuce_first = false;
    if (!rs->tiebreak && (c0 > 3 || c1 > 3)) {
        if (c0 == c1) {
            rs->p[0].display = rs->p[1].display = 40;
            rs->deuce = true;
        } else if (c0 > c1) {
            rs->p[0].display = -1;      /* -1 marks the advantage holder */
            rs->p[1].display = 40;
        } else {
            rs->p[0].display = 40;
            rs->p[1].display = -1;
        }
        return;
    }
    rs->p[0].display = rs->tiebreak ? c0 : point_label(c0);
    rs->p[1].display = rs->tiebreak ? c1 : point_label(c1);
    if (c0 == 3 && c1 == 3)
        rs->deuce = rs->deuce_first = true;
}

int rules_display(const rules_state *rs, int player) { return rs->p[player].display; }

/* ---- game / set / match progression ------------------------------------ */

/* fn_8865C578: begin the set rs->cur_set. */
static void start_set(rules_state *rs)
{
    if (rs->cfg.final_set_super_tb && rs->cfg.num_sets - 1 == rs->cur_set) {
        rs->tiebreak = true;
        rs->super_tiebreak = true;
        rs->games_to_win_set = 0;
        rs->point_target = RULES_SUPER_TB_TARGET;
    } else {
        rs->super_tiebreak = false;
    }
    bool single = rs->games_to_win_set <= 1;
    rs->p[0].sets[rs->cur_set].single_game_set = single;
    rs->p[1].sets[rs->cur_set].single_game_set = single;
}

/* fn_88676898: decide whether the next game is a tiebreak and set its target. */
static void start_game(rules_state *rs)
{
    const rules_set_entry *a = &rs->p[0].sets[rs->cur_set];
    const rules_set_entry *b = &rs->p[1].sets[rs->cur_set];

    if (a->games == rs->games_to_win_set && b->games == rs->games_to_win_set) {
        if (!rs->tiebreak) {
            rs->tiebreak = true;
            rs->point_target = RULES_TIEBREAK_TARGET;
        }
    } else {
        rs->tiebreak = false;
        rs->point_target = rs->cfg.short_format ? 1 : RULES_GAME_TARGET;
    }
}

/* fn_8866A060: player w won the current set. */
static void set_won(rules_state *rs, int w)
{
    int sets = ++rs->p[w].sets_won;

    if (rs->cfg.num_sets - 1 == rs->cur_set || 2 * sets > rs->cfg.num_sets) {
        rs->match_over = true;
        rs->match_winner = w;
    } else {
        rs->cur_set++;
        start_set(rs);
    }
}

/* fn_88676960: player w won the current game. Returns event bits. */
static unsigned game_won(rules_state *rs, int w)
{
    unsigned ev = RULES_EV_GAME;
    int games = ++rs->p[w].sets[rs->cur_set].games;
    int lead = games - rs->p[other(w)].sets[rs->cur_set].games;

    rs->p[0].points = rs->p[1].points = 0;

    bool finished_set = rs->tiebreak || (games >= rs->games_to_win_set && lead >= 2);
    if (finished_set) {
        set_won(rs, w);
        ev |= RULES_EV_SET;
        if (rs->match_over)
            ev |= RULES_EV_MATCH;
    }
    if (!rs->match_over)
        start_game(rs);
    return ev;
}

/* fn_88676DB0: add one point to player w. Returns event bits. */
static unsigned add_point(rules_state *rs, int w)
{
    unsigned ev = RULES_EV_POINT;
    int pts = ++rs->p[w].points;
    int lead = pts - rs->p[other(w)].points;

    for (int i = 0; i < 2; i++)
        rs->p[i].sets[rs->cur_set].tb_points = rs->p[i].points;

    if (pts >= rs->point_target) {
        bool win_by_two = lead >= 2;
        bool capped = rs->tiebreak && pts == RULES_TB_POINT_CAP;
        if (win_by_two || capped || rs->cfg.short_format)
            ev |= game_won(rs, w);
    }

    /* tiebreak bookkeeping uses the (possibly already reset) point totals */
    if (rs->tiebreak) {
        int total = rs->p[0].points + rs->p[1].points;
        if (total != 0) {
            if (total % 6 == 0)
                rs->tb_changeovers++;
            if (total % 2 == 1)
                rs->tb_serve_switches++;
        }
    }
    return ev;
}

/* fn_88676AF0: recompute server, serve side and ends. Returns true if the
 * players have to change ends. */
static bool update_server_and_ends(rules_state *rs)
{
    int changes = rs->tb_changeovers;

    rs->serve_side = (rs->p[0].points + rs->p[1].points) & 1;
    rs->server = rs->first_server ^ ((rs->tb_serve_switches + rules_total_games(rs)) & 1);

    for (int i = 0; i <= rs->cur_set; i++) {
        int t = rs->p[0].sets[i].games + rs->p[1].sets[i].games;
        changes += (t + 1) / 2;         /* a change after every odd game */
    }
    bool swapped = (changes & 1) != 0;
    bool changed = swapped != rs->ends_swapped;
    rs->ends_swapped = swapped;
    return changed;
}

int rules_server(const rules_state *rs) { return rs->server; }
int rules_serve_side(const rules_state *rs) { return rs->serve_side; }

void rules_init(rules_state *rs, const rules_config *cfg, int first_server)
{
    memset(rs, 0, sizeof *rs);
    rs->cfg = *cfg;
    rs->first_server = first_server & 1;
    if (rs->cfg.num_sets > RULES_MAX_SETS)
        rs->cfg.num_sets = RULES_MAX_SETS;
    if (rs->cfg.short_format) {
        rs->games_to_win_set = 1;
        rs->cfg.num_sets = 1;
        rs->cfg.final_set_super_tb = false;
    } else {
        rs->games_to_win_set = rs->cfg.tiebreak_only_sets ? 0 : rs->cfg.games_per_set;
    }
    reset_scores(rs);
    start_set(rs);
    start_game(rs);
    update_server_and_ends(rs);
    refresh_display(rs);
}

/* fn_8866A1C8 + fn_88669878: handle the end of a point. */
unsigned rules_end_point(rules_state *rs, rules_end_kind kind, int winner)
{
    unsigned ev = 0;
    bool award = true;
    bool fault = false;
    bool let = (kind == RULES_END_LET);

    if (rs->match_over)
        return 0;

    if (kind == RULES_END_SERVE || let) {
        fault = !let && winner != -1 && winner != rs->server;
        if (fault)
            award = rs->second_serve || rs->cfg.single_serve;
        else
            award = !let;
    }

    if (award) {
        ev |= add_point(rs, winner);
        if (update_server_and_ends(rs))
            ev |= RULES_EV_CHANGE_ENDS;
        refresh_display(rs);
        rs->winner = winner;
        if (fault)
            ev |= RULES_EV_DOUBLE_FAULT;
    } else {
        rs->winner = -1;
    }
    if (fault)
        ev |= RULES_EV_FAULT;
    if (let)
        ev |= RULES_EV_LET;

    /* fn_88669878: serve-number bookkeeping */
    if (fault && !rs->second_serve && !rs->cfg.single_serve)
        rs->second_serve = true;
    else if (rs->second_serve && let && !fault && !rs->cfg.single_serve)
        rs->second_serve = true;
    else
        rs->second_serve = false;
    return ev;
}

/* fn_8866A1C8, forced-end branch: the loser forfeits the whole match. */
unsigned rules_withdraw(rules_state *rs, int loser)
{
    int w = other(loser);
    int n = rs->cfg.num_sets;

    if (rs->match_over)
        return 0;
    for (int i = 0; i < n / 2 + 1 && i < RULES_MAX_SETS; i++) {
        rules_set_entry *we = &rs->p[w].sets[i];
        rules_set_entry *le = &rs->p[loser].sets[i];
        we->games = rs->cfg.games_per_set;
        we->tb_points = RULES_TIEBREAK_TARGET;
        we->single_game_set = rs->cfg.tiebreak_only_sets;
        le->games = le->tb_points = 0;
        le->single_game_set = false;
    }
    if (n == 1 && rs->cfg.final_set_super_tb) {
        rs->p[w].sets[0].games = 1;
        rs->p[w].sets[0].tb_points = RULES_SUPER_TB_TARGET;
        rs->p[w].sets[0].single_game_set = true;
    }
    rs->p[w].sets_won = n / 2 + 1;
    rs->p[loser].sets_won = 0;
    rs->p[w].points = (rs->games_to_win_set == 0) ? rs->point_target : 0;
    rs->p[loser].points = 0;
    rs->cur_set = n / 2;
    rs->match_over = true;
    rs->match_winner = w;
    rs->winner = w;
    refresh_display(rs);
    return RULES_EV_GAME | RULES_EV_SET | RULES_EV_MATCH;
}

/* ---- predicates -------------------------------------------------------- */

/* fn_88676228: game-level set point / match point flags. */
bool rules_set_point(const rules_state *rs, int player)
{
    int me = rs->p[player].sets[rs->cur_set].games;
    int opp = rs->p[other(player)].sets[rs->cur_set].games;

    if (rs->tiebreak)
        return true;                    /* any tiebreak point can end the set */
    return me >= rs->cfg.games_per_set - 1 && me > opp;
}

bool rules_match_point(const rules_state *rs, int player)
{
    return rules_set_point(rs, player) &&
           rs->p[player].sets_won == (rs->cfg.num_sets - 1) / 2;
}

/* fn_88669CF8 (serve-phase prelude omitted). */
bool rules_point_wins_match(const rules_state *rs, int player)
{
    int pts = rs->p[player].points + 1;
    int lead = pts - rs->p[other(player)].points;
    int games = rs->p[player].sets[rs->cur_set].games + 1;
    int glead = games - rs->p[other(player)].sets[rs->cur_set].games;

    if (pts < rs->point_target)
        return false;
    if (!(lead >= 2 || (rs->tiebreak && pts == RULES_TB_POINT_CAP) ||
          rs->cfg.short_format))
        return false;
    if (!rs->tiebreak && !(games >= rs->games_to_win_set && glead >= 2))
        return false;
    if (rs->cfg.num_sets - 1 == rs->cur_set)
        return true;
    return 2 * (rs->p[player].sets_won + 1) > rs->cfg.num_sets;
}
