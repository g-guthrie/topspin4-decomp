/*
 * Top Spin 4 (Xbox 360) tennis rules and scoring: reference implementation.
 *
 * This is original code written from the behaviour decoded in
 * docs/gameplay/rules-and-scoring.md. It is not a byte match of the game and
 * contains no game data. Function comments name the Swing_DLL.xex function
 * (image base 0x88000000) each routine models.
 *
 * Scope: the "Standard" scoring class (singles). The mini-game scoring
 * classes (first-to-N variants) are not modelled.
 */
#ifndef TS4_REF_RULES_H
#define TS4_REF_RULES_H

#include <stdbool.h>

#define RULES_MAX_SETS 5
#define RULES_GAME_TARGET 4        /* points to win an ordinary game          */
#define RULES_TIEBREAK_TARGET 7    /* points to win a set tiebreak            */
#define RULES_SUPER_TB_TARGET 10   /* points to win a deciding-set tiebreak   */
#define RULES_TB_POINT_CAP 99      /* a tiebreak point count of 99 wins       */

/* Event bits returned by rules_end_point() / rules_withdraw(). */
enum {
    RULES_EV_POINT = 1 << 0,        /* a point was awarded                     */
    RULES_EV_GAME = 1 << 1,         /* game finished (B30 +0x91)               */
    RULES_EV_SET = 1 << 2,          /* set finished  (B30 +0x92)               */
    RULES_EV_MATCH = 1 << 3,        /* match finished (B30 +0x93)              */
    RULES_EV_CHANGE_ENDS = 1 << 4,  /* players swap ends (B30 +0x94)           */
    RULES_EV_FAULT = 1 << 5,        /* a service fault was called (B30 +0x95)  */
    RULES_EV_DOUBLE_FAULT = 1 << 6, /* fault that also awarded the point       */
    RULES_EV_LET = 1 << 7           /* point replayed because of a let         */
};

typedef struct {
    int games_per_set;          /* match config +0x04, normally 6              */
    int num_sets;               /* match config +0x08: 1, 3 or 5               */
    bool tiebreak_only_sets;    /* match config +0x0C: every set is one game   */
    bool final_set_super_tb;    /* match config +0x0D: deciding set = 10-pt TB */
    bool short_format;          /* match config +0x78 == 0x4035E2DF: 1 game/set, 1 set, 1 point/game */
    bool single_serve;          /* game config +0x1E0: no second serve         */
} rules_config;

typedef struct {
    int games;                  /* per-set entry +0x00                         */
    int tb_points;              /* per-set entry +0x04 (last game's points)    */
    bool single_game_set;       /* per-set entry +0x08                         */
} rules_set_entry;

typedef struct {
    rules_set_entry sets[RULES_MAX_SETS];
    int points;                 /* player record +0x0C: raw points this game   */
    int sets_won;               /* player record +0x10                         */
    int display;                /* player record +0x14: 0/15/30/40/-1 or count */
} rules_player;

typedef struct {
    rules_config cfg;
    rules_player p[2];
    int games_to_win_set;       /* class +0x0C (0 when tiebreak-only/super)    */
    int cur_set;                /* RulesInfo +0x30                             */
    bool tiebreak;              /* RulesInfo +0x34                             */
    bool super_tiebreak;        /* RulesInfo +0x35                             */
    bool deuce;                 /* RulesInfo +0x36                             */
    bool deuce_first;           /* RulesInfo +0x37                             */
    int point_target;           /* B44 +0xE0: 4, 7, 10 (or 1)                  */
    bool second_serve;          /* RulesInfo +0x09                             */
    bool match_over;            /* class +0x20                                 */
    int winner;                 /* RulesInfo +0x48: last point winner / -1     */
    int match_winner;           /* player that won the match, -1 if running    */
    int tb_changeovers;         /* class +0x18: tiebreak ends changes          */
    int tb_serve_switches;      /* class +0x1C: tiebreak serve switches        */
    int first_server;           /* which player slot serves game 1             */
    bool ends_swapped;          /* player 0 currently on the "B" end           */
    int server;                 /* B44 +0x54 (S+0xC): current server           */
    int serve_side;             /* B44 +0x58 (S+0x10): points played this game, mod 2 */
} rules_state;

/* Kind of point end reported by the judges. */
typedef enum {
    RULES_END_RALLY,   /* ordinary rally point, `winner` supplied               */
    RULES_END_SERVE,   /* ended while the serve was being judged, `winner` set  */
    RULES_END_LET      /* let on serve: nothing is awarded                      */
} rules_end_kind;

/* fn_88677058 (StartMatch). first_server is 0 or 1. */
void rules_init(rules_state *rs, const rules_config *cfg, int first_server);

/* fn_8866A1C8 (OnPointEnd). Returns RULES_EV_* bits. */
unsigned rules_end_point(rules_state *rs, rules_end_kind kind, int winner);

/* fn_8866A1C8 withdrawal branch (reason "Withdrawal"). */
unsigned rules_withdraw(rules_state *rs, int loser);

/* fn_8865C648 (RefreshDisplayScore) results. */
int rules_display(const rules_state *rs, int player);

/* fn_88676AF0 results. */
int rules_server(const rules_state *rs);
int rules_serve_side(const rules_state *rs);   /* 0 = even points, 1 = odd */
int rules_total_games(const rules_state *rs);  /* fn_88669F30 */

/* fn_88676228: set point / match point flags (game-level, not point-level). */
bool rules_set_point(const rules_state *rs, int player);
bool rules_match_point(const rules_state *rs, int player);

/* fn_88669CF8: would a point won by `player` end the match. */
bool rules_point_wins_match(const rules_state *rs, int player);

#endif
