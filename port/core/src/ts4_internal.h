/* ts4core internal types. Not part of the public API (include/ts4core.h is). */
#ifndef TS4_INTERNAL_H
#define TS4_INTERNAL_H

#include <stddef.h>
#include <stdint.h>

#include "ts4core.h"
#include "gp4b_types.h"   /* src/xbox360 (via -I): Gp4bBall, Gp4bSolve */
#include "gp_swing.h"     /* ref/gameplay (via -I) */
#include "movement.h"
#include "rules.h"

/* ---- registries from the .def files ------------------------------------------------------------------- */
typedef enum {
#define TS4_TUN(id, name, unit, origin, req, src) TS4_T_##id,
#include "ts4_tunables.def"
#undef TS4_TUN
    TS4_T_COUNT
} Ts4Tun;

typedef enum {
#define TS4_VAR(id, name, doc) TS4_V_##id,
#define TS4_ROLE(id, name, graph, doc)
#include "ts4_roles.def"
#undef TS4_VAR
#undef TS4_ROLE
    TS4_V_COUNT
} Ts4Var;

typedef enum {
#define TS4_VAR(id, name, doc)
#define TS4_ROLE(id, name, graph, doc) TS4_R_##id,
#include "ts4_roles.def"
#undef TS4_VAR
#undef TS4_ROLE
    TS4_R_COUNT
} Ts4Role;

/* ---- software math (softmath.c) ----------------------------------------------------------------------- */
float ts4_fmaf(float a, float b, float c);
double ts4_exp(double x);
double ts4_log(double x);
float ts4_sinf(float x);
float ts4_cosf(float x);
float ts4_atan2f(float y, float x);

/* ---- little-endian blob readers ------------------------------------------------------------------------ */
static inline uint32_t ts4_le32(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static inline float ts4_lef32(const uint8_t *p)
{
    uint32_t u = ts4_le32(p);
    float f;
    __builtin_memcpy(&f, &u, 4);
    return f;
}

/* ---- curves (little-endian normalised form, section CURV) --------------------------------------------- */
float ts4_curve16_le(const uint8_t *keys, uint32_t n, float x);   /* fn_881899D8 semantics */
float ts4_curve20_le(const uint8_t *keys, uint32_t n, float x);   /* fn_8817A688 semantics */
float ts4_table2d_le(const uint8_t *rows, uint32_t n_rows, float a, float b);  /* fn_8826D278 semantics */

/* ---- core state ---------------------------------------------------------------------------------------- */
#define TS4_MAX_REGS 512
#define TS4_ROLE_PORTS 24
#define TS4_MAX_PRED 640
#define TS4_EV_RING 256
#define TS4_TREE_DEPTH 32

typedef struct Ts4RoleBinding {
    uint32_t present;
    uint32_t graph_index;
    uint32_t n_in, n_out;
    uint8_t in_var[TS4_ROLE_PORTS];
    uint8_t out_var[TS4_ROLE_PORTS];
} Ts4RoleBinding;

typedef struct Ts4Rng { uint32_t s1, s2; } Ts4Rng;

typedef struct Ts4PredSample {
    float pos[3];          /* cm, world */
    int32_t tick;          /* absolute tick at which the ball is there */
    int32_t bounce;        /* ground bounces so far */
} Ts4PredSample;

typedef struct Ts4Ball {
    Gp4bBall b;            /* LOCAL frame while alive: metres, origin = (0, radius, 0) */
    const uint8_t *row;    /* template row (big-endian game bytes) */
    uint32_t active;
    uint32_t net_done;     /* the net plane crossing was already resolved */
    uint32_t ground_bounces;
    int32_t cord_sign;     /* +1 / -1 yaw direction of a net-cord deflection (rng draw at launch) */
} Ts4Ball;

typedef struct Ts4BallEvents {
    uint32_t bounced;      /* ground bounce this tick */
    uint32_t net_hit;      /* 1 solid, 2 cord */
    float at[3];           /* world cm of the event */
} Ts4BallEvents;

typedef struct Ts4SimPlayer {
    Ts4PlayerSetup setup;
    float pos[3], vel[3];
    float heading;
    float vars[TS4_V_COUNT];
    Ts4Input in;
    uint32_t prev_buttons;
    uint32_t held_ticks;       /* ticks the current shot button has been held */
    uint32_t held_buttons;     /* shot buttons latched while held */
    struct mv_planner planner;
    int32_t committed;         /* candidate index into the window (receiver-side sample list), -1 none */
    int32_t commit_tick;       /* absolute tick of the committed contact */
    float commit_pos[3];
    uint32_t commit_valid;
    int32_t last_opp_hit_tick;
    uint32_t swing_state;      /* 0 idle, 1 swinging, 2 recovery */
    int32_t swing_contact_tick;
    int32_t swing_end_tick;
    uint32_t swing_buttons;
    float swing_power;
    float swing_aim_x, swing_aim_z;
    uint32_t swing_serve;
    uint32_t template_row;
    uint32_t ai_press;         /* AI: remaining ticks of the button press */
    uint32_t ai_buttons;
} Ts4SimPlayer;

struct Ts4Core {
    uint32_t magic;
    uint32_t size;
    /* data */
    const uint8_t *blob;
    uint32_t blob_size;
    float tun[TS4_T_COUNT];
    uint8_t tun_have[TS4_T_COUNT];   /* 0 none, 1 blob, 2 runtime override */
    uint8_t tun_prov[TS4_T_COUNT];
    uint32_t n_missing;
    uint8_t missing[TS4_T_COUNT];
    uint8_t mod_status[TS4_MOD_COUNT];
    const uint8_t *tpl_payload;
    uint32_t tpl_rows, tpl_stride, tpl_rows_off, tpl_payload_size;
    const uint8_t *tree;
    uint32_t tree_n, tree_root;
    const uint8_t *grph;
    uint32_t grph_n;
    uint32_t grph_size;
    Ts4RoleBinding roles[TS4_R_COUNT];
    const uint8_t *curv;
    uint32_t curv_n;
    uint32_t curv_size;
    uint32_t have_tune, have_tpls, have_tree;
    /* match */
    uint32_t started;
    uint32_t tick, phase, phase_tick;
    Ts4MatchConfig cfg;
    Ts4Rng rng;
    rules_state rules;
    Ts4Ball ball;
    uint32_t ball_live;
    Ts4SimPlayer pl[2];
    int32_t server;
    uint32_t serve_second;     /* current serve is the second serve */
    uint32_t serve_flight;     /* ball in flight is a serve awaiting its first bounce */
    int32_t last_hitter;
    uint32_t last_shot_mode;   /* outcome hash of the last shot */
    int32_t last_shot_row;
    uint32_t net_touched;      /* serve touched the cord */
    uint32_t first_bounce_done;
    float first_bounce[3];
    int32_t bounces_side[2];   /* ground bounces on each court half since the last hit */
    int32_t point_winner, point_reason;
    uint32_t point_pending;    /* a point end has been decided this tick */
    float serve_target_z_sign;
    Ts4PredSample pred[TS4_MAX_PRED];
    uint32_t pred_n;
    struct mv_cfg mvcfg;
    Ts4Event ring[TS4_EV_RING];
    uint32_t ev_head, ev_tail;
    Ts4Snapshot snap;
    float regs[TS4_MAX_REGS];
    /* candidate scratch */
    GpWindow win;
    GpSel sel;
    GpBallSample cand_samples[GP_MAX_SAMPLES];
    int32_t cand_pred_index[GP_MAX_SAMPLES];
    float cand_dist[GP_MAX_SAMPLES];
};

#define TS4_MAGIC 0x34435354u /* "TSC4" */
#define TUN(c, id) ((c)->tun[TS4_T_##id])

/* ---- data.c ---------------------------------------------------------------------------------------------- */
int32_t ts4_data_resolve(Ts4Core *c);       /* after tunables/overrides change: recompute module status */
const uint8_t *ts4_template_row(const Ts4Core *c, uint32_t row);
const uint8_t *ts4_curve_find(const Ts4Core *c, uint32_t name_hash, uint32_t *type, uint32_t *n);
int32_t ts4_role_run(Ts4Core *c, uint32_t role, float *vars);   /* 1 ran, 0 no binding / failed */
int32_t ts4_graph_run(const Ts4Core *c, uint32_t index, const float *in, float *out, float *regs);
uint32_t ts4_hash_name(const char *s);

/* ---- ball.c ---------------------------------------------------------------------------------------------- */
typedef struct Ts4BallEnv {
    float net_restitution, cord_a_deg, cord_b_deg, cord_speed_loss, cord_spin_loss;
} Ts4BallEnv;
void ts4_ball_env(const Ts4Core *c, Ts4BallEnv *e);
/* Probe + launch a shot. On success *b is in the LOCAL frame, ready for ts4_ball_tick. */
int32_t ts4_ball_launch(const Ts4Core *c, Ts4Ball *ball, const Ts4ShotIn *in, uint32_t launch_tick, Gp4bSolve *O);
void ts4_ball_tick(const Ts4Core *c, Ts4Ball *ball, const Ts4BallEnv *env, Ts4BallEvents *ev);
void ts4_ball_world_pos(const Ts4Ball *ball, float out[3]);
void ts4_ball_world_vel(const Ts4Ball *ball, float out[3]);   /* cm/s */
int32_t ts4_ball_dead(const Ts4Ball *ball);

/* ---- shot.c ---------------------------------------------------------------------------------------------- */
typedef struct Ts4ShotRequest {
    uint32_t wood_down, wood, classic_serve, advanced_serve, smash, baseline;
    uint32_t topspin, slice, lob, risk, medium, powerful;
} Ts4ShotRequest;
int32_t ts4_tree_select(const Ts4Core *c, const Ts4ShotRequest *rq);  /* template row index or -1 */
float ts4_rng_range(Ts4Rng *r, float lo, float hi);
void ts4_rng_seed(Ts4Rng *r, uint32_t seed);
uint32_t ts4_hash_state(uint32_t h, const void *p, uint32_t n);

#define TS4_HASH_IN 0xCA68AAECu
#define TS4_HASH_OUT 0x81A72B79u
#define TS4_HASH_NET 0xCAA7531Fu
#define TS4_HASH_LET 0xC9238771u
#define TS4_HASH_LET_IN 0x8F903DFBu
#define TS4_HASH_WOOD 0x9CAFB633u

typedef struct Ts4ShotPlan {
    Ts4ShotIn in;
    uint32_t outcome;
    int32_t row;
    float target[3];
} Ts4ShotPlan;
int32_t ts4_shot_plan(Ts4Core *c, Ts4SimPlayer *p, const Ts4ShotRequest *rq, const float contact[3],
                      float own_sign, float stick_fwd, float stick_side, float power, int serve, float box_sign,
                      Ts4ShotPlan *plan);

/* ---- sim.c ----------------------------------------------------------------------------------------------- */
void ts4_ev(Ts4Core *c, uint32_t type, int32_t a, int32_t b, int32_t cc, const float *xyz);

#endif
