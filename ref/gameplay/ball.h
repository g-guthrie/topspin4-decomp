/*
 * Top Spin 4 (Xbox 360) ball mechanics: portable reference implementation.
 *
 * Original code written from the behaviour decoded in docs/gameplay/ball-physics.md (which cites
 * gp4.md / gp4b.md and the Swing_DLL.xex machine code). It contains no game data. Each function
 * names the original routine it models (Swing_DLL.xex VA, image base 0x88000000).
 *
 * This is the READABLE model: float arithmetic in natural order. The bit-exact transcription
 * (fused multiply-adds in the console's order) is src/xbox360/drafts/gp4b_ball_model.c. The test
 * ref/gameplay/test_ball.c checks this file against that draft.
 *
 * Frames and units (as in the game):
 *   world: centimetres, x along the court (net plane x = 0), y up, z across.
 *   local (inside the stepper): metres, origin (0, radius_cm, 0) cm, so the ball centre touches
 *          the ground at local y = 0. All positions in ball_state are local metres.
 *   time:  60 ticks per second. The planner quantises the flight time to whole ticks.
 *   speed: templates and commands use km/h; the model uses m/s.
 *
 * Flight model (closed form, never integrated; fn_888AB558 / fn_888AD1C8):
 *   k = T / a4  (drag rate, 1/s)   W = A / T  (drift velocity from spin)   Weff = W - (0, g/k, 0)
 *   v' = -k (v - W) - g y^
 *   arc 1 (launch to first bounce, boundary value):  p(t) = P0 + C (1 - e^-kt) + Weff t,
 *          C = (P1 - P0 - Weff tau) / (1 - e^-k tau), with P1.y := 0
 *   arc 2 (after a bounce or net touch, initial value): p(t) = p0 + (v0 - Weff)(1 - e^-kt)/k + Weff t
 */
#ifndef TS4_REF_BALL_H
#define TS4_REF_BALL_H

#include <stdbool.h>
#include <stdint.h>

#define BALL_TICKS_PER_SECOND 60.0f
#define BALL_TICK_DT (1.0f / 60.0f)
#define BALL_MAX_KEYS 8
#define BALL_MAX_TABLE_ROWS 4
#define BALL_PREDICT_MAX_TICKS 600 /* fn_886AD278: 10 s of prediction */

/* ball / shot mode hashes (zlib crc32 of the name; ball+0x2C, shot record +0x38) */
#define BALL_MODE_IN 0xCA68AAECu
#define BALL_MODE_OUT 0x81A72B79u
#define BALL_MODE_OUT_FAR 0x2C59FAEAu      /* "OutFar" (fn_88662C08 class 2)          */
#define BALL_MODE_OUT_VERY_FAR 0x280AE84Du /* unnamed (fn_88662C08 class 3)           */
#define BALL_MODE_NET 0xCAA7531Fu
#define BALL_MODE_LET 0xC9238771u          /* outcome; the ball becomes LetIn        */
#define BALL_MODE_LET_IN 0x8F903DFBu
#define BALL_MODE_LET_OUT 0x02315629u
#define BALL_MODE_WOOD 0x9CAFB633u         /* frame shot; no net-clearance raise     */
#define BALL_MODE_LIVE_A 0x9EA301C2u       /* LetIn rewritten by the prediction      */
#define BALL_MODE_LIVE_B 0x5D25ED1Du       /* LetOut rewritten by the prediction     */

/* ------------------------------------------------------------------ template data */

/* How to read curve20 keys. Every retail key stores slope (+0x0C) = 0 and its end value y1 at
 * +0x10. The evaluator fn_8817A688 reads only the slope (STEP = what the shipped code does with
 * the shipped data, unless a load-time fixup exists). RAMP assumes such a fixup fills
 * slope = (y1 - y0) / (x1 - x0). Open question, see analyser-graphs.md section 4. */
typedef enum { BALL_CURVE_STEP = 0, BALL_CURVE_RAMP = 1 } ball_curve_mode;

typedef struct { float x0, x1, y0, slope, y1; } ball_key20;   /* 20-byte key, type 0xF9F12A60 */
typedef struct { float x0, x1, y0, y1; } ball_key16;          /* 16-byte key (bounce curves)   */

typedef struct { int n; ball_key20 k[BALL_MAX_KEYS]; } ball_curve20;
typedef struct { int n; ball_key16 k[BALL_MAX_KEYS]; } ball_curve16;

typedef struct { float a; ball_curve16 c; } ball_table_row;   /* 2-D table row (type 0x7A330099) */

typedef enum { BALL_VAL_NONE = 0, BALL_VAL_CONST, BALL_VAL_CURVE, BALL_VAL_TABLE } ball_value_type;

/* polymorphic template value {rel, type}: float (0x33799CCE), curve20, or 2-D table */
typedef struct {
    ball_value_type type;
    float c;                                  /* BALL_VAL_CONST                         */
    ball_curve20 curve;                       /* BALL_VAL_CURVE: x = distance cm (nodes) or height m (spin) */
    int nrows;                                /* BALL_VAL_TABLE: a = distance cm, b = hit height cm */
    ball_table_row rows[BALL_MAX_TABLE_ROWS];
} ball_value;

/* solver kinds (crc32 of the name), template +0x08 / +0x14 of tpl */
typedef enum {
    BALL_KIND_NONE = 0,
    BALL_KIND_DROP_TIME,      /* 0x5D90675B  value = flight time (s) / time offset          */
    BALL_KIND_BOUNCE_SPEED,   /* 0x50B89452  value = speed at the first bounce (km/h)       */
    BALL_KIND_INITIAL_SPEED,  /* 0xC1965E5C  value = launch speed (km/h) / speed delta      */
    BALL_KIND_AVERAGE_SPEED,  /* 0x2DB3EB6F  stub in this build (no metric)                 */
    BALL_KIND_APOGEE          /* 0x879BA860  secondary only: apex offset (m)                */
} ball_kind;

/* One 0x8C-byte shot-template row (Settings.bin file 0x137C + 0x8C*i). tpl = row + 0x18. */
typedef struct {
    uint32_t row_type;        /* row+0x00 0x85B71A2B: class of the selector object built from the row */
    uint32_t name_hash;       /* row+0x04 template family name; key of the aim table          */
    uint32_t group_hash;      /* row+0x08 second aim-table key (e.g. FlatReturn) or 0          */
    uint32_t base_hash;       /* row+0x0C third aim-table key (related row) or 0               */
    uint32_t id;              /* row+0x88 unique row id (decision-tree leaf key)               */
    ball_kind kind;           /* tpl+0x08 primary solver kind                                  */
    ball_kind kind2;          /* tpl+0x14 secondary solver kind                                */
    ball_value primary;       /* tpl+0x00                                                      */
    ball_value secondary;     /* tpl+0x0C                                                      */
    ball_value spin_a[2];     /* tpl+0x18 {lo, hi}: vertical drift (negative = topspin, dips)  */
    ball_value spin_c[2];     /* tpl+0x24 {lo, hi}: along-track drift                          */
    ball_value spin_b[2];     /* tpl+0x30 {lo, hi}: lateral drift (sidespin)                   */
    float T;                  /* tpl+0x3C drag scale: k = T / a4                               */
    ball_curve16 bounce_speed_loss;  /* tpl+0x40 f(spin_a): v *= 1 - f                         */
    ball_curve16 bounce_spin_decay;  /* tpl+0x4C f(spin_a): spin *= 1 - f                      */
    ball_curve16 bounce_out_elev;    /* tpl+0x58 f(theta_in): wanted outgoing elevation (rad)  */
    ball_curve16 bounce_yaw;         /* tpl+0x64 f(spin_b): yaw kick (rad)                     */
    ball_curve_mode curve_mode;      /* reading of curve20 keys, see above                     */
} ball_template;

/* Decode one row from the original big-endian bytes (self-relative offsets). `row` points at
 * row+0x00 (has_header = 1, Settings.bin) or at a row without the type word (State.bin, pass the
 * address that corresponds to row+0x00 and has_header = 0; header fields are then 0).
 * Returns 0 on success, -1 when a curve or table is larger than the fixed limits. */
int ball_template_from_be(const uint8_t *row, int has_header, ball_curve_mode mode, ball_template *out);

float ball_curve16_eval(const ball_curve16 *c, float x);                         /* fn_881899D8 */
float ball_curve20_eval(const ball_curve20 *c, float x, ball_curve_mode mode);   /* fn_8817A688 */
float ball_value_eval(const ball_value *v, float a, float b, ball_curve_mode m); /* fn_888AB6C8 */

/* ------------------------------------------------------------------ ball constants */

/* Ball block constants. Retail defaults live in the State.bin ball image (radius 4 cm, a4 0.06,
 * g 9.81, max_bounces 5); ball+0x4C0..0x4CC is the dispersion box of In shots. */
typedef struct {
    float radius_cm;      /* ball+0x4D0 */
    float a4;             /* ball+0x4D4 drag time constant scale (k = T / a4) */
    float g;              /* ball+0x4D8 m/s^2 */
    unsigned max_bounces; /* ball+0x4DC ball dead after this many events */
    float disp_dx[2];     /* ball+0x4C0/0x4C4 cm */
    float disp_dz[2];     /* ball+0x4C8/0x4CC cm */
} ball_config;

void ball_config_default(ball_config *c);

/* ------------------------------------------------------------------ ball state */

typedef struct {
    /* plan and command */
    float tau;                /* +0x00 flight time to the first bounce (s, n/60)        */
    int bounce_tick;          /* +0x04 tick of the first bounce                          */
    float T;                  /* +0x08                                                   */
    float sec_weight;         /* +0x0C = command f4C; secondary weight w = clamp(1-f4C)  */
    float spin_blend;         /* +0x10 = command f50 (0..1)                              */
    int bounce_count;         /* +0x14 (net touches of a solid net count too)            */
    int tick;                 /* +0x18 incremented by the caller before every step       */
    int tick_prev;            /* +0x1C start tick of the current arc                     */
    int launch_frame;         /* +0x20                                                   */
    int hold;                 /* +0x28 ticks of scripted motion (no physics)             */
    uint32_t mode;            /* +0x2C ball mode hash                                    */
    bool check_net;           /* +0x31 test the net plane                                */
    bool solid_net;           /* +0x32 net stops the ball                                */
    bool net_cord;            /* +0x33 let: deflect over the cord                        */
    bool touched_net;         /* +0x34                                                   */
    bool keep_spin_on_net;    /* stepper+0x42: solid net branch disabled                 */
    float pos[3], prev[3];    /* +0x40 / +0x60 local m                                   */
    float A[3];               /* +0x80 drift ("spin") acceleration vector                */
    float spin_a, spin_b, spin_c; /* +0x90 / +0x94 / +0x98                               */
    float hold_delta[3];      /* +0xA0 per-tick motion while hold > 0                    */
    int land_frame;           /* +0xC8 launch_frame + (int)(60 tau)                      */
    int dead_frame;           /* +0xD0 frame at which the ball is dead (or -1)           */
    float P0[3], P1[3];       /* +0x100 / +0x110 launch and landing points (local m)     */
    float net_height_cm;      /* +0x124                                                  */
    float arc2_pos[3], arc2_vel[3]; /* +0x130 / +0x140                                   */
    float k;                  /* +0x158 drag rate T / a4                                 */
    float a4, g;              /* +0x4D4 / +0x4D8 copied from the ball block               */
    bool sidespin_neg;        /* +0x368 left-hander mirror of spin_b in the drift vector  */
    bool planned;             /* +0x369 1 = template shot, 0 = commanded speed (Net/Let) */
    float aim_height_m;       /* +0x36C wanted net-plane height for planned = 0          */
    float speed_kmh;          /* +0x370 commanded initial speed for planned = 0          */
    float cord_elev_deg, cord_yaw_deg, cord_speed_loss, cord_spin_loss; /* +0x494..+0x4A0 */
    bool no_sidespin;         /* +0x4E1 bounce/cord clears spin_b and spin_c             */
    float vel[3];             /* +0x4F0 (pos - prev) * 60, m/s                           */
    float v_launch[3], v_arrive[3]; /* +0x500 / +0x510                                   */
} ball_state;

/* shot command (the planner's 0xE0-byte record, the fields the ball reads) */
typedef struct {
    float from_cm[3];         /* C+0x00 hit point (world cm)                             */
    float to_cm[3];           /* C+0x10 landing target (world cm, y ignored by the arc)  */
    float net_height_cm;      /* C+0x24                                                  */
    float cord[4];            /* C+0x30..0x3C let deflection: elev deg, yaw deg, speed loss, spin loss */
    float sec_weight;         /* C+0x4C f4C                                              */
    float spin_blend;         /* C+0x50 f50                                              */
    float speed_kmh;          /* C+0x54 (Net/Let probes only)                            */
    bool sidespin_neg;        /* C+0x58                                                  */
    uint32_t mode;            /* C+0x80                                                  */
    bool planned;             /* ball+0x369 (set by the planner, In/Out = 1)             */
    float aim_height_m;       /* ball+0x36C                                              */
} ball_command;

/* solver result (Gp4bSolve, 0x2C bytes) */
typedef struct {
    float tau;            /* primary result                                     */
    bool raised;          /* net clearance raised tau                           */
    float tau_raised;
    float metric_kmh;
    float tau_min;        /* tau of the slowest possible launch                 */
    bool has_min;
    bool net_unreachable;
    float tau_final;      /* before quantisation                                */
    float initial_kmh;    /* launch speed of the final arc                      */
    float net_height_m;   /* local height at the net plane                      */
} ball_solve;

/* events returned by ball_step */
enum {
    BALL_EV_BOUNCE = 1 << 0,
    BALL_EV_NET_SOLID = 1 << 1,
    BALL_EV_NET_CORD = 1 << 2,
    BALL_EV_DEAD = 1 << 3
};

/* ------------------------------------------------------------------ shot launch and flight */

/* fn_889C2678: plan a shot (the swing planner's probe). Fills tau / bounce_tick / spin and P0/P1,
 * returns the solver result. */
void ball_probe(ball_state *b, const ball_template *t, const ball_config *cfg, const ball_command *cmd,
                ball_solve *out);

/* fn_886B5128 apply + fn_889C19F0 launch. Uses b->tau / b->bounce_tick (from the probe) and the command. */
void ball_launch(ball_state *b, const ball_template *t, const ball_config *cfg, const ball_command *cmd,
                 int launch_frame);

/* fn_889C1F70: one 60 Hz tick. The caller increments b->tick first (fn_886AD1F0). */
unsigned ball_step(ball_state *b, const ball_template *t, const ball_config *cfg);

/* fn_889C0C70: net flags from the ball mode */
void ball_mode_flags(ball_state *b, uint32_t mode);

/* fn_889C1868 + fn_889C0DC0 */
void ball_spin_set(ball_state *b, const ball_template *t, float launch_height_m, float blend);
void ball_drift_update(ball_state *b, bool from_endpoints);

/* fn_889C1C80: bounce response, v is the incoming velocity (m/s), replaced by the outgoing one */
void ball_bounce_response(ball_state *b, const ball_template *t, float v[3]);

/* closed forms */
void ball_arc1_position(const ball_state *b, float t, float out[3]);
void ball_arc1_velocity(const ball_state *b, float t, float out[3]);
void ball_arc2_position(const ball_state *b, float t, float out[3]);
float ball_speed2_initial(const ball_state *b);    /* fn_888AAB98 */
float ball_speed2_bounce(const ball_state *b);     /* fn_888AAA70 */
float ball_apex_height(const ball_state *b, float tau);   /* fn_888AA968 */
float ball_net_height(const ball_state *b);        /* fn_888AB308 (local m at x = 0) */

/* fn_888AD0E8: flight-time solver dispatch (needs P0, P1, A, T, k set) */
void ball_solve_tau(ball_state *b, const ball_template *t, const ball_config *cfg, ball_solve *out);

void ball_to_world_cm(const ball_config *cfg, const float local[3], float out_cm[3]);

/* ------------------------------------------------------------------ prediction */

typedef struct { int tick; float pos_cm[3]; float vel[3]; int bounce_count; } ball_sample;

/* fn_886AD278: run the stepper on a copy for at most 600 ticks, until two bounces, or Net/Out mode.
 * Returns the number of samples written (<= max). */
int ball_predict(const ball_state *b, const ball_template *t, const ball_config *cfg, ball_sample *out, int max);

/* ------------------------------------------------------------------ court, outcome and error */

typedef struct { float xmax, zmin, zmax; } ball_bounds;

/* fn_8866E318: legal landing box (cm) on the opponent half (x > 0), enlarged by 2 * radius. */
void ball_court_bounds(bool serve, bool deuce_side, bool doubles, float radius_cm, ball_bounds *out);
bool ball_target_out(const float target_cm[3], const ball_bounds *bb);
/* fn_88672130: move a target to 3 cm beyond the nearest line (unchanged when already > 3 cm out) */
void ball_push_out(float target_cm[3], const ball_bounds *bb);
/* fn_88662C08: how far out (Out <= 50 cm, OutFar <= 150 cm, else the unnamed class) */
uint32_t ball_out_class(const float pt_cm[3], const ball_bounds *bb);

/* fn_8861E598: the engine RNG (two-word xorshift / multiply) */
typedef struct { uint32_t s1, s2; } ball_rng;
float ball_rng_range(ball_rng *r, float lo, float hi);

/* fn_886807C0: In / Out / Net / Let decision. Probabilities are PlayerState floats. */
typedef struct {
    float error;          /* S+0x718 */
    float error_add;      /* S+0x564 */
    float let_prob;       /* S+0x71C */
    float net_share;      /* S+0x720 */
    bool force_error, force_net, force_let;   /* S+0x56D / 0x56E / 0x572 */
    bool net_let_enabled; /* G = DebugConfig+0x784 && !match+0x329 && match+0x328 */
    bool b50, b51;        /* fn_88671B10 reachability flags (1 = no restriction) */
} ball_outcome_inputs;
uint32_t ball_outcome_decide(const ball_outcome_inputs *in, const float target_cm[3], const ball_bounds *bb,
                             ball_rng *rng);

/* fn_886AE528 +0xA38: the target an In outcome is launched toward (clamp, 75 cm past the net, dispersion) */
void ball_in_target(float target_cm[3], const ball_bounds *bb, const ball_config *cfg, ball_rng *rng,
                    bool groundstroke);

#endif
