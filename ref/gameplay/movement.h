/*
 * Clean-room reference for the Top Spin 4 player movement planner and the
 * opponent ("AI") input path.  See docs/gameplay/movement-and-ai.md.
 *
 * Nothing here contains game data.  Every tunable is a parameter; the real
 * values are loaded from disc data by fn_888BB670 (the movement config
 * loader).  World predicates (ball geometry etc.) are supplied by the caller
 * through struct mv_world because they depend on the ball prediction.
 *
 * Compile (portable C11):
 *   cc -std=c11 -Wall -Wextra -Werror -o /tmp/test_movement \
 *      ref/gameplay/test_movement.c ref/gameplay/movement.c \
 *      ref/gameplay/ai_driver.c -lm
 */
#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <stddef.h>
#include <stdint.h>

/* The 23 planner states (switch index of fn_886B8468 / fn_886AA280).
 * Numbers [verified]; names [inferred] except the three speed regimes. */
enum mv_state {
    MV_WAIT = 0,          /* reaction delay after the opponent's hit      */
    MV_ANTICIPATE_A = 1,  /* ball in flight, try to commit a plan         */
    MV_ANTICIPATE_B = 2,  /* same, second phase (selector arg 2)          */
    MV_SWING_READY = 3,   /* swing animation found, wait for start zone   */
    MV_SWING = 4,         /* swinging                                     */
    MV_APPROACH = 5,      /* default move toward the contact sample       */
    MV_APPROACH_NEAR = 6, /* approach after the near-zone test            */
    MV_TURN = 7,          /* interrupt: pivot toward the new heading      */
    MV_STOP = 8,          /* interrupt: stop (speed override 0)           */
    MV_REPLAN = 9,        /* hold, re-search, resume saved state          */
    MV_ALT_A = 10,        /* alternate profile move (cfg +0x238)          */
    MV_ALT_B = 11,        /* alternate profile move (cfg +0x248)          */
    MV_ALT_SWING = 12,    /* follow-up of 10/11                           */
    MV_HOLD = 13,         /* hold the last move command                   */
    MV_BALL_WINDOW = 14,  /* wait for the ball window                     */
    MV_CHOOSE = 15,       /* AI: arg-max candidate pick                   */
    MV_VOLLEY = 16,       /* volley candidate move                        */
    MV_READY_A = 17,      /* short ready hold                             */
    MV_READY_B = 18,      /* short ready hold, sets side flags            */
    MV_REACH = 19,        /* reach / lunge                                */
    MV_RUSH = 20,         /* speed regime: rush            [verified]     */
    MV_JOGJOG = 21,       /* speed regime: JogJogPrepared  [verified]     */
    MV_JOG = 22,          /* speed regime: JogPrepared     [verified]     */
    MV_STATE_COUNT = 23
};

/* Per-mode record in the movement config (cfg+0x270 Rush, +0x284 JogJog,
 * +0x298 Jog).  Only the minimum distance is a plain float; the margin table
 * is data and is evaluated by the caller-supplied table function. */
struct mv_mode_cfg {
    float min_distance;
};

struct mv_cfg {
    float reaction_frames;         /* profile record +0x1dc (state 0)       */
    float validity_threshold;      /* code constant 0.5 (pool 0x8814B910)   */
    float rush_guard;              /* cfg +0x630 compared with player value */
    struct mv_mode_cfg rush, jogjog, jog;
    int   max_hops;                /* 8 in the game                         */
};

/* Margin table lookup: validity = table(mode, distance, slack_frames). */
typedef float (*mv_table_fn)(const struct mv_mode_cfg *mode, float distance,
                             float slack, void *user);

/* Everything the transition function needs to know this frame.  Booleans are
 * the results of the predicate functions named in the doc. */
struct mv_world {
    /* clock / reaction */
    int   frame;                   /* match frame counter                   */
    int   frames_since_opp_hit;
    int   opp_mode_is_2;           /* opponent team mode == 2               */
    int   rally_active;            /* fn_8866D930                           */
    int   human;                   /* ctx+0x10 (crc32("Human") controller)  */
    int   sets_valid;              /* candidate set flags +0x30/+0x64 clear */
    /* selector results */
    int   sel_from_anticipate;     /* fn_886A9E48(arg) result, caller fills */
    int   pending_candidate;       /* planner+0x11c != -1                   */
    int   shot_window_a;           /* fn_88678548                           */
    int   ball_window;             /* fn_886877A8                           */
    int   prepared_or_rushjog;     /* fn_886A58F0 || action in {Rush,Jog}   */
    int   hold_window_ok;          /* fn_8865DB50                           */
    int   reaction_started;        /* planner+0x2a0 >= 0                    */
    float hold_frames;             /* bb+0xdf8                              */
    /* geometry predicates */
    int   can_start_swing;         /* fn_886A3440                           */
    int   can_reach;               /* fn_886A26E0                           */
    int   replan;                  /* fn_886A9678 / fn_886A9A48: 1,-1,0     */
    int   zone_swing_start;        /* fn_88687AC0(cfg+0x2ac)                */
    int   zone_near;               /* fn_88687AC0(cfg+0x2b8)                */
    int   zone_hold;               /* fn_88687AC0(cfg+0x300)                */
    int   alt_swing_ok;            /* fn_886A2BE8                           */
    int   jog_far_ok;              /* fn_88678708(cfg+0x2f4)                */
    int   rush_ok_flag;            /* fn_8866C150                           */
    float slack_distance;          /* fn_8866BFE8                           */
    float slack_hi, slack_lo;      /* code constants 0x880D14E8 / 0x1144    */
    int   candidate_index;         /* bb+0xbc8                              */
    int   candidate_stable_window; /* |new - saved| <= 10 test input        */
    int   interrupt_to_turn;       /* prologue: near ball & heading test    */
    int   interrupt_dir_positive;  /* selects 8 (stop) over 7 (turn)        */
};

struct mv_planner {
    int state;           /* machine cell                                     */
    int prev_state;      /* +0x1c                                            */
    int frames_in_state; /* +0x20                                            */
    int saved_state;     /* +0x12c                                           */
    int saved_candidate; /* +0x138                                           */
    int pending_interrupt; /* +0x125                                         */
    int swing_flag;      /* +0x13c                                           */
    int rush_flag_121, flag_122, flag_294;
    int last_cmd_valid;
    float last_heading, last_intensity; /* +0x288/+0x28c                     */
};

/* Output of one planner step (what gets written to the player blackboard). */
struct mv_out {
    int   speed_override_set;  /* bb+0xdec                                   */
    float speed_override;      /* bb+0xde8: 1.0 rush-like, 0.0 stop          */
    int   request_search_profile; /* 0 none, else cfg offset (0x208...)      */
};

int mv_mode_valid(const struct mv_cfg *cfg, const struct mv_mode_cfg *mode,
                  float dist, float slack, mv_table_fn tab, void *user);

/* fn_88699FC0 */
int mv_select_move_state(const struct mv_cfg *cfg, int profile_is_238_248,
                         int profile_is_1f8, int sample_is_volley,
                         float rush_player_value, float dist, float slack,
                         mv_table_fn tab, void *user, int *out_flags_cleared);

/* fn_886B8468: one call returns the next state (== cur means stay). */
int mv_next_state(struct mv_planner *p, const struct mv_cfg *cfg,
                  const struct mv_world *w, struct mv_out *out);

/* fn_886BD690: iterate to a fixed point (at most cfg->max_hops hops). */
int mv_update(struct mv_planner *p, const struct mv_cfg *cfg,
              const struct mv_world *w, struct mv_out *out);

const char *mv_state_name(int s);

/* ---- AI / virtual input (ai_driver.c) -------------------------------- */
struct ai_candidate {
    float reach_speed;     /* "Reachability", m/s                           */
    float ball_difficulty; /* "Ball Difficulty"                             */
    float input_notation;  /* "InputNotation": 0 for AI                     */
    float score;           /* "Selection Score", output of the graph        */
    int   is_volley;       /* type == Volley                                */
    int   frames_to_ball;
};
typedef float (*ai_score_fn)(const struct ai_candidate *c, int human,
                             void *user);

struct ai_pick { int index; };
/* fn_8865DBA8: only_volley / exclude_volley follow the verified 2-bit truth
 * table: (0,0) all, (0,1) volley only, (1,0) non-volley only, (1,1) all. */
int ai_argmax(const struct ai_candidate *c, int n, int a4, int a5,
              float floor_value);
void ai_score_all(struct ai_candidate *c, int n, int human, float max_speed,
                  ai_score_fn fn, void *user);

enum ai_aim_mode { AI_AIM_NEUTRAL, AI_AIM_STICK, AI_AIM_AUTO };
struct ai_stick { float x, y; };
struct ai_polar { float heading, intensity; };
/* fn_8869C010: human players keep the raw stick, others are forced to 0. */
struct ai_stick ai_effective_stick(int human, struct ai_stick raw);
/* fn_886884E8: planner move command in polar form. */
struct ai_polar ai_move_command(float heading_to_target);
/* fn_886A3DF0 aim mode choice */
enum ai_aim_mode ai_choose_aim(int stick_aim_enabled, int out_of_range,
                               int in_reach);

#endif
