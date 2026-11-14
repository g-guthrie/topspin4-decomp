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

/* ---- game-state images (fields.c): byte images laid out like the game objects, so bound graphs read and write
 *      the same offsets as the original (graphs-decoded.md s3). Floats are host order. ---- */
#define TS4_PS_SIZE 0x1070u      /* PlayerState */
#define TS4_AI_SIZE 0x274u       /* UserAIState (E9CA839C) */
#define TS4_TEAM_SIZE 0xC0u      /* TeamState */
#define TS4_MATCH_SIZE 0x340u    /* MatchState */
#define TS4_BALLIMG_SIZE 0x540u  /* BallState = Gp4bBall layout */
#define TS4_MAX_GRAPHS 1024u
enum { TS4_RG_NONE = 0, TS4_RG_SELF, TS4_RG_OPP, TS4_RG_BALL, TS4_RG_MATCH, TS4_RG_TEAM, TS4_RG_AI, TS4_RG_SKILL,
       TS4_RG_QUAL, TS4_RG_PARTNER };

typedef struct Ts4AnimState {
    uint32_t layer;
    int32_t clip, prev_clip;
    float frame, prev_frame, rate, prev_rate;
    float blend_t, blend_len;      /* ticks into the blend / blend length in ticks (0 = no blend) */
    int32_t group, sub;
    int32_t moveset;               /* current move set index, -1 none */
    float contact_frame;
    uint32_t occ[8];               /* last swing clips (max_occ policy) */
} Ts4AnimState;

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
    /* decoded shot flow (G2b) */
    uint32_t charging;         /* shot button latched, charge counter running */
    uint32_t charge_frames;    /* fn_88698538 counter: frames since the latch */
    uint32_t charge_committed; /* released or auto-committed (contact - now <= lead) */
    int32_t charge_commit_lead;/* contact - now at the commit */
    uint32_t charge_buttons;
    float charge_power;
    float aim_angle, aim_depth;
    uint32_t inside_out;       /* LT forced side commit (S+0x5DC) */
    int32_t toss_tick;         /* serve: tick the toss started, -1 none */
    int32_t serve_release_tick;
    int32_t react_tick;        /* AI: tick from which the AI may move (reaction delay) */
    uint32_t ai_stroke;        /* AI: chosen stroke buttons for the incoming ball */
    float ai_power;            /* AI: PressAndHold */
    float ai_aim_side, ai_aim_len;
    float speed_override;      /* S+0xDE8 policy value, m/s */
    float run_dist_cm;         /* distance run since the last shot (fatigue integrator) */
    Ts4AnimState anim;
    uint8_t ps[TS4_PS_SIZE];
    uint8_t ai[TS4_AI_SIZE];
    uint8_t team[TS4_TEAM_SIZE];
} Ts4SimPlayer;

typedef struct Ts4Ext {
    const uint8_t *bind, *sini, *aidf, *skil, *anim, *scls;
    uint32_t bind_n, sini_n, aidf_n, skil_n, anim_n, scls_n;
    uint32_t graph_bind[TS4_MAX_GRAPHS];   /* 1 + byte offset of the graph's port list in BIND, 0 = not bound */
    uint32_t n_bound;
    uint32_t ai_styles, ai_levels;
    uint32_t n_classes, n_class_rows;
    /* ANIM header (offsets relative to anim) */
    uint32_t an_nq, an_q, an_nqv, an_qv, an_nclips, an_clips, an_stride, an_ngroups, an_groups, an_nsubs, an_subs,
             an_nms, an_ms, an_nrules, an_rules, an_msize, an_mat;
} Ts4Ext;

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
    Ts4Ext ext;
    Ts4PlayerExtra extra[2];
    uint8_t match_img[TS4_MATCH_SIZE];
    uint8_t ball_img[TS4_BALLIMG_SIZE];   /* BallState mirror for bound graphs; let block 0x480..0x4C0 is ours */
    uint32_t rally_shots;
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

/* ---- fields.c ---------------------------------------------------------------------------------------------- */
static inline float ts4_fget(const uint8_t *img, uint32_t off) { float f; __builtin_memcpy(&f, img + off, 4); return f; }
static inline void ts4_fset(uint8_t *img, uint32_t off, float v) { __builtin_memcpy(img + off, &v, 4); }
#define PS_GET(p, off) ts4_fget((p)->ps, (off))
#define PS_SET(p, off, v) ts4_fset((p)->ps, (off), (v))
#define TUN_HAS(c, id) ((c)->tun_have[TS4_T_##id] != 0)
void ts4_ext_reset(Ts4Core *c);
int32_t ts4_ext_section(Ts4Core *c, const uint8_t *tag, const uint8_t *p, uint32_t n);  /* 1 = consumed */
int32_t ts4_ext_resolve(Ts4Core *c);     /* after GRPH: validate and index; TS4_OK or TS4_ERR_BAD_BLOB */
int32_t ts4_bound(const Ts4Core *c);     /* 1 when graphs are wired by field (BIND present) */
int32_t ts4_gfind(const Ts4Core *c, uint32_t hash);   /* first graph with this hash, -1 none */
int32_t ts4_bgraph(Ts4Core *c, int32_t graph_index, int player);   /* 1 ran */
int32_t ts4_bgraph_h(Ts4Core *c, uint32_t hash, int player);
void ts4_images_init(Ts4Core *c);         /* SINI defaults into every image (match start) */
void ts4_ball_img_sync(Ts4Core *c);       /* copy the live ball (except the let block) into ball_img */
const uint8_t *ts4_ai_record(const Ts4Core *c, uint32_t style, uint32_t level);
int32_t ts4_shot_class(const Ts4Core *c, uint32_t row, int is_return);   /* SCLS class index or -1 */
int32_t ts4_class_run(Ts4Core *c, int32_t cls, int player);              /* run the class graphs; 1 ran */
/* AIDF record layout (ts4yaml.py enc_aidf) */
#define TS4_AI_REC_SIZE 72u
#define TS4_AI_G40 4u
#define TS4_AI_G44 8u
#define TS4_AI_G48 12u
#define TS4_AI_G4C 16u
#define TS4_AI_G50 20u
#define TS4_AI_G54 24u
#define TS4_AI_SPEED 28u
#define TS4_AI_LCOUNT 32u
#define TS4_AI_LOFF 52u

/* ---- anim.c ----------------------------------------------------------------------------------------------- */
int32_t ts4_anim_ready(const Ts4Core *c);
void ts4_anim_reset(Ts4Core *c, int player);
void ts4_anim_tick(Ts4Core *c, int player);
void ts4_anim_swing(Ts4Core *c, int player, uint32_t stroke_buttons, int volley, int smash, int forehand,
                    int is_return, int32_t ticks_to_contact);
float ts4_anim_qual(const Ts4Core *c, int player, uint32_t qtype, uint32_t qvalue);

/* ---- shotsel.c: copies of ref/gameplay/shot_select.c and ball.c pieces (G2b, G3) -------------------------- */
typedef struct Ts4Bounds { float xmax, zmin, zmax; } Ts4Bounds;
float ts4s_curve16(const float key[4], float x);
int ts4s_lt_forced_commit(int lt, float power, float angle, int alt, int mirrored, float pmin, float amax);
void ts4s_aim_from_stick(float move_x, float move_y, int mirrored, float *angle, float *depth);
float ts4s_serve_power(int release, int toss_start, int toss_len, int released);
int ts4s_wood_down(float target[3], const float ref[3], int is_wood);
void ts4s_court_bounds(const Ts4Core *c, int serve, int deuce_side, Ts4Bounds *o);
int ts4s_target_out(const float p[3], const Ts4Bounds *bb);
void ts4s_push_out(float p[3], const Ts4Bounds *bb, float margin);
uint32_t ts4s_out_class(const Ts4Core *c, const float p[3], const Ts4Bounds *bb);
void ts4s_target_min_depth(float p[3], float min_depth);
void ts4s_in_target(float p[3], const Ts4Bounds *bb, float min_depth);
void ts4s_in_shortfall(float p[3], const float from[3], float shortfall_cm);
void ts4s_wood_target(const Ts4Core *c, float out[3], const float from[3], Ts4Rng *rng);
void ts4s_reach_flags(const float p[3], const Ts4Bounds *bb, float len_a, float len_b, float ang1_deg, float ang2_deg,
                      int point_end, int *b50, int *b51);
uint32_t ts4s_out_nonforced(const Ts4Core *c, float p[3], const Ts4Bounds *bb, Ts4Rng *rng);
#define TS4_HASH_OUT_FAR 0x2C59FAEAu
#define TS4_HASH_OUT_VERY_FAR 0x280AE84Du

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
