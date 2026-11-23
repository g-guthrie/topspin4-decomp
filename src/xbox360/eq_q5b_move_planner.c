/* Q5 equivalent route: the movement planner's per-tick state transition (Swing_DLL.xex 0x886B8468, 0x2300 bytes).
 *
 * ts4_move_planner_transition_886B8468(planner, cur) returns the next Gp3MoveState of the planner owned by a
 * PlayerController (see work/gameplay-notes/gp3.md 5.3). Returning `cur` means "stay"; the caller loops until the
 * state is stable. Structure:
 *  - preamble: re-target check while planner->retarget_pending is set: when the committed ball sample is inside the
 *    re-target radius and the player would have to turn, jump to the step-adjust states 7/8 and clear the step flags;
 *    a turn event on player->events forces state 8;
 *  - dispatch on the (possibly changed) state through a 23-entry jump table.
 * Offsets, branch senses (NaN behaviour of every float compare) and the load order before possibly faulting loads
 * follow the machine code; names are by role (M/L confidence, see gp3.md). Not byte-matched: see the byte-gap line. */
#include "vx1_vector.h"
#include "gp3_types.h"

double fabs(double x);
#ifdef _MSC_VER
#pragma intrinsic(fabs)
#endif

typedef unsigned char q5b_u8;
typedef unsigned int q5b_u32;

#ifdef _MSC_VER
#define Q5B_INLINE __forceinline
#else
#define Q5B_INLINE static inline
#endif

/* ---- hashes seen only here (crc32 names unknown) ---- */
#define Q5B_HASH_ANIM_TURN_LOCK   0x230A53B8u /* movement mode that, like Idle, blocks the re-target jump */
#define Q5B_HASH_EVENT_TURN_A     0xF4D02677u /* events->current kind forcing the step-adjust state 8 */
#define Q5B_HASH_EVENT_TURN_B     0x912FA212u
#define Q5B_HASH_COURT_KIND_SKIP  0x280AE84Du /* court kind of the team's court that sends state 1 straight to 0xD */

/* ---- script constant pool (g_ts4_script_constants, 0x880D0F70) ---- */
extern const float g_ts4_script_constants[];
#define Q5B_K(off)  (g_ts4_script_constants[(off) / 4])
#define Q5B_KD(off) (*(const double *)&g_ts4_script_constants[(off) / 4])
#define K_ONE                 Q5B_K(0x000)
#define K_DEFAULT_RECV_LEAD   Q5B_K(0x03C)
#define K_AIM_NEGATIVE        Q5B_K(0x0E4)
#define K_AIM_POSITIVE        Q5B_K(0x0E8)
#define K_BOX_NEAR_MARGIN     Q5B_K(0x0F0)
#define K_STEP_TURN_MIN       Q5B_K(0x10C)
#define K_REACH_440_MIN       Q5B_K(0x118)
#define K_STEP_LOOKAHEAD      Q5B_K(0x130)
#define K_JOG_FAR_SPEED       Q5B_K(0x1D4)
#define K_STEP_TURN_MAX       Q5B_K(0x2AC)
#define K_ADJUST_LOOKAHEAD    Q5B_K(0x404)
#define K_CONTACT_HEIGHT_MAX  Q5B_K(0x40C)
#define K_ADJUST_TIME_BIAS    Q5B_K(0x42C)
#define K_SPIN_SPEED_MAX      Q5B_K(0x4EC)
#define K_JOG_ESCALATE_SPEED  Q5B_K(0x578)
#define K_RETARGET_RADIUS2    Q5B_K(0x818) /* 62500 = (250 cm)^2 */
#define K_RETARGET_YAW_TOL    Q5B_K(0x81C)
#define K_RETARGET_ANGLE_LO   Q5B_KD(0x820)
#define K_RETARGET_ANGLE_HI   Q5B_K(0x828)
#define K_VOLLEY_X_MAX        Q5B_K(0x82C)
#define K_TURN_ANGLE_MIN      Q5B_K(0x830)

extern const float lbl_8814B440; /* 0.0f, also loaded as a whole vector (lvlx) to clear a lane */
extern const float lbl_880C88DC; /* angle offset added before wrapping with fn_8817B608 */

/* ---- object layouts (only the fields this function touches) ---- */
typedef struct Q5bLine { __vector4 point; __vector4 dir; } Q5bLine;

typedef struct Q5bClock { q5b_u8 pad0[0x310]; int frame; } Q5bClock;
typedef struct Q5bBall { q5b_u8 pad0[0x2C]; q5b_u32 mode; q5b_u8 pad30[0xD8 - 0x30]; int land_frame; } Q5bBall;
typedef struct Q5bBallSys { q5b_u8 pad0[0x20]; Q5bBall *ball; struct Gp2BallPrediction *prediction; } Q5bBallSys;
typedef struct Q5bCourtInfo { q5b_u8 pad0[0x84]; q5b_u32 kind; } Q5bCourtInfo;
typedef struct Q5bCourtEntry { q5b_u8 pad0[0x88]; Q5bCourtInfo *info; } Q5bCourtEntry;
typedef struct Q5bRules { int mode; } Q5bRules;
typedef struct Q5bBox { q5b_u8 pad0[0x1B0]; __vector4 center; } Q5bBox;
typedef struct Q5bMatch {
    q5b_u8 pad0[0x4];
    Q5bCourtEntry **courts; /* +0x04 (886B89B0 loads it from the match, not from match->rules) */
    q5b_u8 pad8[0x30 - 0x8];
    Q5bClock *clock;        /* +0x30 */
    q5b_u8 pad34[0x44 - 0x34];
    Q5bBox *box;            /* +0x44 */
    q5b_u8 pad48[0x5C - 0x48];
    Q5bBallSys *balls;      /* +0x5C */
    q5b_u8 pad60[0x78 - 0x60];
    Q5bRules *rules;        /* +0x78 */
} Q5bMatch;
typedef struct Q5bTeamState {
    q5b_u8 pad0[0x48];
    int court_index;        /* +0x48 */
    q5b_u8 pad4c[0x68 - 0x4C];
    int last_hit_frame;     /* +0x68 */
    q5b_u8 pad6c[0xB0 - 0x6C];
    q5b_u32 side_tag;       /* +0xB0 GP3_HASH_COURT_SIDE_A when the side is mirrored */
} Q5bTeamState;
typedef struct Q5bTeam {
    q5b_u8 pad0[0x20];
    Q5bMatch *match;        /* +0x20 */
    Q5bTeamState *state;    /* +0x24 */
    q5b_u8 pad28[0x2C - 0x28];
    int mode;               /* +0x2C 2 = doubles */
} Q5bTeam;
typedef struct Q5bAiTuning { q5b_u8 pad0[0x1B0]; float receive_lead; q5b_u8 pad1b4[0x1DC - 0x1B4]; float reaction_frames; } Q5bAiTuning;
typedef struct Q5bAi { q5b_u8 pad0[0x28]; Q5bAiTuning *tuning; } Q5bAi;
typedef struct Q5bVariant { q5b_u8 pad0[0x58]; float profile_weight; } Q5bVariant;
typedef struct Q5bMoveCfg {
    q5b_u8 pad0[0x118];
    int contact_frames_max;  /* +0x118 */
    q5b_u8 pad11c[0x12C - 0x11C];
    float contact_lateral_max; /* +0x12C */
    q5b_u8 pad130[0x1EC - 0x130];
    q5b_u8 spin_table[0x1C]; /* +0x1EC 2-D table (ts4_table2d_eval_8826D278) */
    q5b_u8 profile_208[0x20]; /* +0x208 swing profile (volley) */
    q5b_u8 profile_228[8];   /* +0x228 swing profile (default) */
    float profile_228_weight; /* +0x230 temporarily overridden for AI players */
    q5b_u8 pad234[0x2AC - 0x234];
    q5b_u8 cond_2ac[0x0C];   /* +0x2AC prepare condition (state 3) */
    q5b_u8 cond_2b8[0x3C];   /* +0x2B8 prepare condition (state 5) */
    q5b_u8 cond_2f4[0x0C];   /* +0x2F4 jog condition (states 20..22) */
    q5b_u8 cond_300[4];      /* +0x300 prepare condition (states 10/11) */
} Q5bMoveCfg;
typedef struct Q5bHand { q5b_u8 pad0[0xC]; q5b_u32 tag; } Q5bHand;
typedef struct Q5bInput { q5b_u8 pad0[6]; q5b_u8 hold; } Q5bInput;
typedef struct Q5bBody { q5b_u8 pad0[0x20]; __vector4 facing; } Q5bBody;
typedef struct Q5bAnim { q5b_u8 pad0[0x468]; q5b_u32 move_mode; } Q5bAnim;
typedef struct Q5bComponent { q5b_u32 pad0[2]; q5b_u32 kind; void *object; } Q5bComponent;
typedef struct Q5bPredRef { q5b_u8 pad0[0x88]; struct Gp2BallPrediction *prediction; } Q5bPredRef;

typedef struct Q5bMoveState {
    q5b_u8 pad0[0x384];
    q5b_u32 swing_hash;      /* +0x384 GP3_HASH_FH / GP3_HASH_BH */
    q5b_u8 pad388[0x440 - 0x388];
    float reach_440;         /* +0x440 */
    float spin_444;          /* +0x444 */
    q5b_u8 pad448[0x574 - 0x448];
    q5b_u8 swing_armed;      /* +0x574 */
    q5b_u8 pad575[0x5D9 - 0x575];
    q5b_u8 swing_pending;    /* +0x5D9 */
    q5b_u8 pad5da[0x5DE - 0x5DA];
    q5b_u8 contact_ready;    /* +0x5DE */
    q5b_u8 contact_fixed;    /* +0x5DF */
    q5b_u8 pad5e0[0x650 - 0x5E0];
    float swing_time_slot;   /* +0x650 */
    float swing_time_fh;     /* +0x654 */
    float swing_time_bh;     /* +0x658 */
    q5b_u8 pad65c[0x74C - 0x65C];
    float swing_time;        /* +0x74C */
    q5b_u8 pad750[0x8D0 - 0x750];
    q5b_u32 mirror_key;      /* +0x8D0 coordinate mirroring key */
    q5b_u8 pad8d4[0x8E0 - 0x8D4];
    __vector4 pos;           /* +0x8E0 player position */
    q5b_u8 pad8f0[0x9D0 - 0x8F0];
    q5b_u32 aim[4];          /* +0x9D0 yaw/turn words, copied as raw words */
    q5b_u8 pad9e0[0x9E8 - 0x9E0];
    float step_yaw;          /* +0x9E8 */
    float step_turn;         /* +0x9EC */
    q5b_u8 pad9f0[0xA40 - 0x9F0];
    q5b_u8 recv_a_on, recv_a_valid; /* +0xA40 */
    q5b_u8 pada42[0xA5C - 0xA42];
    float recv_a_lead;       /* +0xA5C */
    q5b_u8 pada60[0xAA0 - 0xA60];
    q5b_u8 recv_b_on, recv_b_valid; /* +0xAA0 */
    q5b_u8 padaa2[0xABC - 0xAA2];
    float recv_b_lead;       /* +0xABC */
    q5b_u8 padac0[0xBC8 - 0xAC0];
    int sample;              /* +0xBC8 committed ball-sample index */
    q5b_u8 padbcc[0xBD0 - 0xBCC];
    q5b_u8 volley_only;      /* +0xBD0 */
    q5b_u8 side;             /* +0xBD1 committed side */
    q5b_u8 padbd2[0xC6C - 0xBD2];
    float spin_c6c;          /* +0xC6C */
    q5b_u8 padc70[0xDE8 - 0xC70];
    float turn_weight;       /* +0xDE8 */
    q5b_u8 turn_on;          /* +0xDEC */
    q5b_u8 padded[0xDF0 - 0xDED];
    float step_radius;       /* +0xDF0 */
    q5b_u8 paddf4[0xDF8 - 0xDF4];
    float wait_frames;       /* +0xDF8 */
    q5b_u8 paddfc[0xFAA - 0xDFC];
    q5b_u8 step_faa, step_fab, step_fac, step_fad, step_fae, step_faf, step_fb0, step_fb1; /* +0xFAA */
    q5b_u8 padfb2[0xFB4 - 0xFB2];
    q5b_u8 step_fb4, step_fb5; /* +0xFB4 */
} Q5bMoveState;

typedef struct Q5bPlayer {
    q5b_u8 pad0[0x10];
    q5b_u8 is_human;         /* +0x10 */
    q5b_u8 pad11[0x28 - 0x11];
    Q5bHand *hand;           /* +0x28 */
    Q5bMoveCfg *cfg;         /* +0x2C */
    q5b_u8 pad30[0x38 - 0x30];
    q5b_u8 swing_started;    /* +0x38 */
    q5b_u8 swing_forehand;   /* +0x39 */
    q5b_u8 pad3a[0x48 - 0x3A];
    Q5bMatch *match;         /* +0x48 */
    Q5bTeam *team;           /* +0x4C */
    Q5bAi *ai;               /* +0x50 */
    q5b_u8 pad54[0x60 - 0x54];
    void *events;            /* +0x60 */
    Q5bInput *input;         /* +0x64 */
    Q5bBody *body;           /* +0x68 */
    q5b_u8 pad6c[0x74 - 0x6C];
    Q5bMoveState *state;     /* +0x74 */
    Q5bAnim *anim;           /* +0x78 */
    q5b_u8 pad7c[0x94 - 0x7C];
    Q5bComponent *components_begin; /* +0x94 */
    Q5bComponent *components_end;   /* +0x98 */
    q5b_u8 pad9c[0xB4 - 0x9C];
    Q5bPredRef *own_ball;    /* +0xB4 */
    Q5bPredRef *step_ball;   /* +0xB8 */
} Q5bPlayer;

typedef struct Q5bLock { q5b_u8 pad0[0x30]; q5b_u8 locked_a; q5b_u8 pad31[0x64 - 0x31]; q5b_u8 locked_b; } Q5bLock;
typedef struct Q5bScorer { q5b_u8 pad0[0xE0]; } Q5bScorer; /* GP2 selection scorer (fn_8865DBA8 arg-max) */

typedef struct Q5bPlanner {
    q5b_u8 pad0[0x20];
    q5b_u32 state_ticks;     /* +0x20 ticks spent in the current state */
    const void *profile;     /* +0x24 active swing profile (cfg+0x208 / cfg+0x228) */
    q5b_u8 pad28[0x2C - 0x28];
    struct Gp2CandidateSet *sets; /* +0x2C sets[0], sets[1] */
    q5b_u8 pad30[0x38 - 0x30];
    Q5bScorer scorer;        /* +0x38 */
    Q5bLock *lock;           /* +0x118 */
    int pending_target;      /* +0x11C -1 = none */
    q5b_u8 committed;        /* +0x120 */
    q5b_u8 mode_locked;      /* +0x121 */
    q5b_u8 mode_prepared;    /* +0x122 */
    q5b_u8 swing_set;        /* +0x123 */
    q5b_u8 adjust_running;   /* +0x124 */
    q5b_u8 retarget_pending; /* +0x125 */
    q5b_u8 pad126[2];
    int adjust_countdown;    /* +0x128 */
    int resume_state;        /* +0x12C state to return to from 8/9 */
    q5b_u32 hold_aim[2];     /* +0x130 */
    int resume_sample;       /* +0x138 */
    q5b_u8 busy;             /* +0x13C */
    q5b_u8 pad13d[0x154 - 0x13D];
    Q5bPlayer *player;       /* +0x154 */
    q5b_u8 list[0x270 - 0x158]; /* +0x158 */
    __vector4 contact_pos;   /* +0x270 */
    int contact_frame;       /* +0x280 */
    q5b_u8 step_side_set;    /* +0x284 */
    q5b_u8 aim_saved;        /* +0x285 */
    q5b_u8 pad286[2];
    q5b_u32 saved_aim[2];    /* +0x288 */
    q5b_u8 pad290[0x294 - 0x290];
    q5b_u8 mode_fixed;       /* +0x294 */
    q5b_u8 pad295[0x2A0 - 0x295];
    int wait_marker;         /* +0x2A0 */
} Q5bPlanner;

#ifdef _MSC_VER
#define Q5B_OFF(T, f, o) typedef char q5b_off_##T##_##f[((unsigned)&((T *)0)->f == (o)) ? 1 : -1]
Q5B_OFF(Q5bPlanner, lock, 0x118);
Q5B_OFF(Q5bPlanner, player, 0x154);
Q5B_OFF(Q5bPlanner, contact_pos, 0x270);
Q5B_OFF(Q5bPlanner, wait_marker, 0x2A0);
Q5B_OFF(Q5bPlayer, step_ball, 0xB8);
Q5B_OFF(Q5bMoveState, pos, 0x8E0);
Q5B_OFF(Q5bMoveState, sample, 0xBC8);
Q5B_OFF(Q5bMoveState, wait_frames, 0xDF8);
Q5B_OFF(Q5bMoveState, step_fb5, 0xFB5);
Q5B_OFF(Q5bMoveCfg, cond_300, 0x300);
#endif

/* ---- callees ---- */
extern q5b_u8 fn_8866D930(Q5bPlayer *p);
extern void ts4_if_get_8865E730(__vector4 *point, q5b_u32 mirror_key);
extern void fn_8868ED00(Q5bPlayer *p, __vector4 *out, int frames);
extern void ts4_vec_with_offset_8867A908(Q5bPlayer *p, __vector4 *out, float t);
extern double fn_88564BF8(double y, double x); /* atan2 */
extern q5b_u32 *ts4_if_call_seq_u32_off28_886C7D58(q5b_u32 *out, void *events);
extern Q5bVariant *ts4_selected_variant_886A0EC8(Q5bAi *ai);
extern void ts4_selection_scorer_run_8869AEF8(Q5bScorer *s, int flags, const void *profile);
extern void fn_886B81E0(void *receiver);
extern q5b_u8 ts4_abs_less_8866DA00(Q5bPlayer *p);
extern void ts4_loop_call_seq_u32_off2c_8890E988(void *list);
extern __vector4 *ts4_if_get_u32_off4c_8865EC70(__vector4 *out, Q5bPlayer *p);
extern q5b_u8 fn_886877A8(Q5bPlanner *s);
extern void ga4_publish_query_flag_8869A4D0(Q5bPlanner *s);
extern q5b_u8 fn_886A58F0(Q5bPlayer *p);
extern int fn_886A9E48(Q5bPlanner *s, int mode);
extern q5b_u8 fn_88678548(Q5bPlanner *s);
extern q5b_u8 ts4_elapsed_within_limit_8865DB50(Q5bPlanner *s);
extern q5b_u8 fn_88687AC0(Q5bPlanner *s, const void *cond);
extern int fn_886A9678(Q5bPlanner *s);
extern q5b_u8 fn_886A3440(Q5bPlanner *s);
extern q5b_u8 fn_886A26E0(Q5bPlanner *s);
extern void fn_8866BD00(Q5bPlanner *s);
extern q5b_u8 fn_886A2E48(Q5bPlanner *s, const void *profile);
extern q5b_u8 fn_8866C150(Q5bPlanner *s);
extern q5b_u8 fn_88678708(Q5bPlanner *s, const void *cond);
extern float fn_8866BFE8(Q5bPlanner *s);
extern int fn_886A9A48(Q5bPlanner *s);
extern void fn_886884E8(Q5bPlanner *s);
extern void fn_886987C8(Q5bPlanner *s);
extern void fn_8865DBA8(Q5bScorer *s, int *best_index, q5b_u8 *best_side, int exclude_volley, int only_volley);
extern int fn_88699FC0(Q5bPlanner *s);
extern int ts4_prediction_ticks_until_x_886600E0(struct Gp2BallPrediction *pred, float x);
extern int ts4_if_call_seq_u32_off118_8865D790(Q5bPlanner *s);
extern void fn_8817B608(float *angle);
extern float ts4_table2d_eval_8826D278(const void *table, float x, float y);
extern void ts4_call_seq_u32_off8_886894A8(Q5bScorer *s, int volley);
extern void fn_886787D8(Q5bPlanner *s);
extern void fn_8866E318(Q5bMatch *m, int point_end, float *bounds);
extern float ts4_box_margin_8866E058(const __vector4 *a, const float *bounds);
extern void ts4_if_get_u32_off4c_8865EBF8(Q5bPlayer *p, __vector4 *point);
extern void fn_8866BDD8(Q5bPlanner *s, __vector4 *pos);
extern q5b_u8 fn_886A2BE8(Q5bPlanner *s);
extern void ts4_if_call_seq_u32_off154_886A9DF0(Q5bPlanner *s);
extern q5b_u8 ts4_query_slot_matches_target_8865EB60(Q5bPlayer *p);
extern int ts4_two_event_ticks_remaining_886CD1E8(void *events);
extern void fn_88189888(Q5bLine *line, const __vector4 *a, const __vector4 *b);
extern void fn_8866D180(__vector4 *dir, q5b_u32 mirror_key);
extern void fn_8826AC10(Q5bLine *line, const __vector4 *point, const __vector4 *dir);
extern int fn_881896F8(const Q5bLine *a, const Q5bLine *b, __vector4 *hit, float *t1, float *t2);
extern void fn_8826D3A0(__vector4 *out, const Q5bLine *a, const Q5bLine *b, float *t);
extern void fn_88699300(Q5bPlanner *s, int state);

/* ---- helpers ---- */
Q5B_INLINE int q5b_negative(float f)
{
    union { float f; q5b_u32 u; } c;
    c.f = f;
    return (int)(c.u >> 31);
}

Q5B_INLINE float q5b_dot(__vector4 a, __vector4 b)
{
    __vector4 d = __vmsum3fp(a, b);
    return d.v[0];
}

Q5B_INLINE float q5b_fabs(float f) { return (float)fabs(f); }

Q5B_INLINE int q5b_frame(const Q5bMatch *m) { return m->clock->frame; }

/* candidate set of the committed side: side 0 uses sets[1] */
Q5B_INLINE const struct Gp2CandidateSet *q5b_side_set(const Q5bPlanner *s, int side)
{
    return side ? &s->sets[0] : &s->sets[1];
}

Q5B_INLINE const __vector4 *q5b_set_position(const struct Gp2CandidateSet *set, int i)
{
    return (const __vector4 *)((const char *)&set->positions + set->positions.offset) + i;
}

Q5B_INLINE const q5b_u32 *q5b_set_types(const struct Gp2CandidateSet *set)
{
    return (const q5b_u32 *)((const char *)&set->types + set->types.offset);
}

Q5B_INLINE const __vector4 *q5b_sample_pos(const struct Gp2BallPrediction *pred, int i)
{
    return (const __vector4 *)pred->samples_begin[i].pos;
}

/* the first usable sample of a prediction, or null when it is empty */
Q5B_INLINE const struct Gp2BallSample *q5b_current_sample(const struct Gp2BallPrediction *pred)
{
    const struct Gp2BallSample *e = 0;
    if (pred->samples_begin != pred->samples_end)
        e = pred->samples_begin + pred->first_sample;
    return e;
}

Q5B_INLINE int q5b_is_moving(const Q5bPlayer *p)
{
    q5b_u32 m = p->anim->move_mode;
    return m == GP3_HASH_RUSH || m == GP3_HASH_JOG;
}

Q5B_INLINE void q5b_clear_step_flags(Q5bPlanner *s)
{
    s->player->state->step_fb0 = 0;
    s->player->state->step_fb1 = 0;
    s->player->state->step_faa = 0;
    s->player->state->step_fab = 0;
    s->player->state->step_fb4 = 0;
    s->player->state->step_fb5 = 0;
}

/* score the default profile; AI players temporarily use the selected variant's weight */
Q5B_INLINE void q5b_score_default(Q5bPlanner *s)
{
    Q5bPlayer *p = s->player;
    Q5bMoveCfg *cfg = p->cfg;
    float saved = cfg->profile_228_weight;
    if (!p->is_human && p->team->mode != 2)
        cfg->profile_228_weight = ts4_selected_variant_886A0EC8(p->ai)->profile_weight;
    ts4_selection_scorer_run_8869AEF8(&s->scorer, 0, s->player->cfg->profile_228);
    p = s->player;
    if (!p->is_human && p->team->mode != 2)
        p->cfg->profile_228_weight = saved;
}

Q5B_INLINE int q5b_hold(Q5bPlanner *s)
{
    s->saved_aim[0] = s->hold_aim[0];
    s->saved_aim[1] = s->hold_aim[1];
    return GP3_MOVE_13;
}

Q5B_INLINE int q5b_hold_sample(Q5bPlanner *s, int origin)
{
    s->resume_state = origin;
    s->resume_sample = s->player->state->sample;
    return GP3_MOVE_9;
}

/* copy step_yaw/step_turn into both aim pairs */
Q5B_INLINE void q5b_publish_step(Q5bPlanner *s)
{
    Q5bMoveState *st = s->player->state;
    q5b_u32 yaw = *(const q5b_u32 *)&st->step_yaw;
    st->aim[0] = yaw;
    st->aim[1] = *(const q5b_u32 *)&st->step_turn;
    s->player->state->aim[2] = yaw;
    s->player->state->aim[3] = st->aim[1];
}

/* the box-margin based contact wait of states 17 and 18 once the side is set */
Q5B_INLINE int q5b_contact_wait(Q5bPlanner *s, int next)
{
    Q5bMatch *m = s->player->match;
    __vector4 center = m->box->center;
    float bounds[4];
    int lead;
    const struct Gp2BallSample *e;
    fn_8866E318(m, 0, bounds);
    lead = ts4_box_margin_8866E058(&center, bounds) < K_BOX_NEAR_MARGIN ? 1 : 20;
    e = q5b_current_sample(m->balls->prediction);
    if (e->tick - q5b_frame(m) >= lead)
        return next;
    if (s->state_ticks <= 1)
        return next;
    return GP3_MOVE_13;
}

/* byte-gap: 605 off (best, C++ draft; size 0x22a0 vs 0x2300); state reload after the path getters, result-slot order and one epilogue copy not reproduced (src/xbox360/drafts/q5_move_planner_best.cpp, docs/agents/q5/notes/886b8468_match_log.md round 2) */
int ts4_move_planner_transition_886B8468(Q5bPlanner *s, int cur)
{
    const float zero = lbl_8814B440;
    const float one = K_ONE;
    const float aim_pos = K_AIM_POSITIVE;
    Q5bPlayer *p = s->player;
    q5b_u8 can_react = fn_8866D930(p);
    int next = cur;

    if (s->retarget_pending) {
        Q5bMoveState *st;
        __vector4 contact, target, delta, probe, side;
        float d2;
        s->retarget_pending = 0;
        st = p->state;
        contact = *q5b_sample_pos(p->own_ball->prediction, st->sample);
        target = *q5b_set_position(q5b_side_set(s, st->side), st->sample);
        ts4_if_get_8865E730(&contact, st->mirror_key);
        delta = __vsubfp(target, p->state->pos);
        d2 = q5b_dot(delta, delta);
        if (!(d2 >= K_RETARGET_RADIUS2)) {
            int ahead, facing, slow, jump;
            float *step;
            fn_8868ED00(p, &probe, 20);
            ahead = q5b_dot(delta, __vsubfp(target, probe)) > zero;
            step = &p->state->step_yaw;
            side = __vrlimi(__vsubfp(contact, target), __lvlx(&lbl_8814B440, 0), 4, 3);
            ts4_vec_with_offset_8867A908(p, &probe, K_STEP_LOOKAHEAD);
            facing = !(q5b_dot(side, delta) <= zero) &&
                     q5b_dot(__vsubfp(probe, st->pos), side) > zero;
            slow = step[1] < K_STEP_TURN_MIN;
            jump = 0;
            if (facing) {
                if (ahead) {
                    jump = 1;
                } else if (!slow) {
                    float turn_max = K_STEP_TURN_MAX;
                    float ang, a;
                    int lo, hi;
                    jump = 0;
                    if (step[1] > turn_max)
                        jump = q5b_fabs(step[0] - aim_pos) < K_RETARGET_YAW_TOL ||
                               !(q5b_fabs(step[0] + aim_pos) >= K_RETARGET_YAW_TOL);
                    ang = (float)fn_88564BF8(delta.v[2], delta.v[0]);
                    a = q5b_fabs(ang);
                    lo = (double)a < K_RETARGET_ANGLE_LO;
                    hi = a > K_RETARGET_ANGLE_HI;
                    jump = jump && !lo && !hi; /* 886B8714: the jump needs LO <= |angle| <= HI */
                    if (jump && !(step[1] >= turn_max)) {
                        step[1] = one;
                        step[0] = ang;
                    }
                }
                p = s->player;
                if (p->anim->move_mode != GP3_HASH_IDLE && p->anim->move_mode != Q5B_HASH_ANIM_TURN_LOCK && jump) {
                    s->resume_state = cur;
                    s->adjust_running = 0;
                    q5b_clear_step_flags(s);
                    next = GP3_MOVE_7_ADJUST_A + (ahead != 0);
                }
            }
            {
                q5b_u32 kind;
                p = s->player;
                kind = *ts4_if_call_seq_u32_off28_886C7D58(&kind, p->events);
                if ((kind == Q5B_HASH_EVENT_TURN_A || kind == Q5B_HASH_EVENT_TURN_B) && next == cur) {
                    s->adjust_running = 0;
                    s->resume_state = next;
                    next = GP3_MOVE_8_ADJUST_B;
                    q5b_clear_step_flags(s);
                }
            }
        }
    }

    p = s->player;
    switch (next) {
    case GP3_MOVE_0_AFTER_HIT_WAIT: {
        Q5bTeam *team = p->team;
        if ((float)(q5b_frame(team->match) - team->state->last_hit_frame) >= p->ai->tuning->reaction_frames ||
            team->mode == 2)
            return GP3_MOVE_1_READY;
        return next;
    }

    case GP3_MOVE_1_READY: {
        int far_from_steps;
        if (can_react && p->match->rules->mode == 2 &&
            p->match->courts[p->team->state->court_index]->info->kind == Q5B_HASH_COURT_KIND_SKIP)
            return q5b_hold(s);
        q5b_score_default(s);
        p = s->player;
        if (!p->is_human) {
            Q5bComponent *c = p->components_begin, *found = 0;
            Q5bMoveState *st;
            void *receiver;
            float lead;
            for (; c != p->components_end; c++) {
                if (c->kind == GP3_HASH_RECEIVER) {
                    found = c;
                    break;
                }
            }
            st = p->state;
            lead = K_DEFAULT_RECV_LEAD;
            receiver = found->object;
            if (st->recv_a_on && st->recv_a_valid)
                lead = st->recv_a_lead;
            else if (st->recv_b_on && st->recv_b_valid)
                lead = st->recv_b_lead;
            p->ai->tuning->receive_lead = lead;
            fn_886B81E0(receiver);
        }
        far_from_steps = 0;
        if (can_react && ts4_abs_less_8866DA00(s->player) && s->player->team->mode != 2) {
            __vector4 here, flat, step;
            const struct Gp2BallPrediction *pred;
            const struct Gp2BallSample *e, *last;
            float r2;
            int near = 0;
            ts4_loop_call_seq_u32_off2c_8890E988(s->list);
            p = s->player;
            here = *ts4_if_get_u32_off4c_8865EC70(&here, p);
            flat.v[0] = here.v[0];
            flat.v[1] = zero;
            flat.v[2] = here.v[2];
            flat.v[3] = zero;
            r2 = p->state->step_radius * p->state->step_radius;
            pred = p->match->balls->prediction;
            last = 0;
            if (pred->samples_begin != pred->samples_end)
                last = pred->samples_end - 1;
            e = 0;
            if (pred->samples_begin != pred->samples_end)
                e = pred->samples_begin;
            for (; e != last; e++) {
                step.v[0] = e->pos[0];
                step.v[1] = zero;
                step.v[2] = e->pos[2];
                step.v[3] = zero;
                step = __vsubfp(flat, step);
                if (q5b_dot(step, step) < r2) {
                    near = 1;
                    break;
                }
            }
            if (!near)
                far_from_steps = 1;
        }
        if (far_from_steps) {
            int moving;
            if (!fn_886877A8(s))
                return q5b_hold(s);
            ga4_publish_query_flag_8869A4D0(s);
            moving = q5b_is_moving(s->player);
            if (fn_886A58F0(s->player) || moving)
                return q5b_hold(s);
            return 0x11;
        }
        if (s->pending_target != -1) {
            ts4_loop_call_seq_u32_off2c_8890E988(s->list);
            s->player->state->swing_pending = s->player->state->contact_ready;
            s->player->state->swing_armed = s->player->state->contact_ready == 0;
            p = s->player;
            s->contact_pos = p->state->pos;
            s->contact_frame = q5b_frame(p->match);
            return GP3_MOVE_14;
        }
        next = fn_886A9E48(s, 1);
        if (next != cur)
            return next;
        {
            int free_ = !s->lock->locked_a && !s->lock->locked_b;
            if (can_react && free_) {
                if (fn_88678548(s)) {
                    next = 0x12;
                } else if (fn_886877A8(s)) {
                    int moving;
                    ga4_publish_query_flag_8869A4D0(s);
                    moving = q5b_is_moving(s->player);
                    if (!fn_886A58F0(s->player) && !moving)
                        next = 0x11;
                    else
                        next = q5b_hold(s);
                } else {
                    next = q5b_hold(s);
                }
            }
        }
        if (next != cur)
            return next;
        {
            Q5bMatch *m;
            Q5bBall *ball;
            int landed = 0;
            int lim, waiting;
            p = s->player;
            m = p->match;
            ball = m->balls->ball;
            if (ball->mode == GP3_HASH_LET_IN || ball->mode == GP3_HASH_LET_OUT)
                landed = ball->land_frame - q5b_frame(m) <= 0;
            if (landed)
                return GP3_MOVE_2;
            lim = (int)p->state->wait_frames;
            waiting = !ts4_elapsed_within_limit_8865DB50(s) && s->wait_marker > -1;
            if (q5b_frame(m) - p->team->state->last_hit_frame > lim && !ts4_elapsed_within_limit_8865DB50(s))
                return GP3_MOVE_2;
            if (waiting)
                return GP3_MOVE_2;
            return next;
        }
    }

    case GP3_MOVE_2: {
        int free_, moving;
        q5b_score_default(s);
        next = fn_886A9E48(s, 2);
        if (next != cur)
            return next;
        free_ = !s->lock->locked_a && !s->lock->locked_b;
        if (!can_react || !free_)
            return next;
        if (fn_88678548(s))
            return 0x12;
        if (!fn_886877A8(s))
            return q5b_hold(s);
        ga4_publish_query_flag_8869A4D0(s);
        moving = q5b_is_moving(s->player);
        if (fn_886A58F0(s->player) || moving)
            return q5b_hold(s);
        return 0x11;
    }

    case GP3_MOVE_3:
        if (fn_88687AC0(s, s->player->cfg->cond_2ac)) {
            s->retarget_pending = 1;
            return GP3_MOVE_4;
        }
        return next;

    case GP3_MOVE_4: {
        int r = fn_886A9678(s);
        if (r == 1)
            return q5b_hold_sample(s, GP3_MOVE_4);
        if (can_react && r == -1)
            return GP3_MOVE_13;
        return next;
    }

    case GP3_MOVE_5:
    case GP3_MOVE_6: {
        int r;
        if (fn_886A3440(s)) {
            next = GP3_MOVE_3;
            s->busy = 0;
        }
        if (next != cur)
            return next;
        if (next == GP3_MOVE_5 && fn_88687AC0(s, s->player->cfg->cond_2b8)) {
            s->retarget_pending = 1;
            return GP3_MOVE_6;
        }
        if (fn_886A26E0(s))
            return 0x13;
        r = fn_886A9678(s);
        if (r == 1 && next == GP3_MOVE_6)
            return q5b_hold_sample(s, GP3_MOVE_6);
        if (can_react && r == -1)
            return GP3_MOVE_13;
        fn_8866BD00(s);
        if (!s->committed)
            fn_886A2E48(s, s->player->cfg->profile_208);
        return next;
    }

    case GP3_MOVE_20_RUSH:
    case GP3_MOVE_21_JOG_PREPARED:
    case GP3_MOVE_22_JOG_JOG_PREPARED: {
        int reached, jog_ok, rush_ready;
        float speed;
        q5b_u32 *aim;
        if (fn_886A3440(s)) {
            next = GP3_MOVE_3;
            s->busy = 0;
        }
        if (next != cur)
            return next;
        if (fn_886A26E0(s))
            return 0x13;
        reached = fn_8866C150(s);
        jog_ok = fn_88678708(s, s->player->cfg->cond_2f4);
        if (next == GP3_MOVE_21_JOG_PREPARED && reached && jog_ok) {
            next = GP3_MOVE_22_JOG_JOG_PREPARED;
            goto publish;
        }
        rush_ready = next == GP3_MOVE_20_RUSH && reached;
        speed = fn_8866BFE8(s);
        if (rush_ready && (speed > K_JOG_ESCALATE_SPEED || (speed > K_JOG_FAR_SPEED && jog_ok))) {
            next = GP3_MOVE_22_JOG_JOG_PREPARED;
        } else {
            int r = fn_886A9A48(s);
            if (r == 1) {
                next = GP3_MOVE_6;
                s->retarget_pending = 0;
            } else if (can_react && r == -1) {
                next = q5b_hold(s);
            }
        }
        if (!s->mode_locked && !s->mode_fixed && s->mode_prepared)
            fn_886A2E48(s, s->profile);
    publish:
        aim = s->player->state->aim;
        if (!s->mode_locked) {
            fn_886884E8(s);
            if (!s->mode_prepared && s->state_ticks > 0)
                s->player->input->hold = 1;
            if (!s->mode_fixed)
                fn_886987C8(s);
        } else if (s->aim_saved) {
            aim[2] = s->saved_aim[0];
            aim[3] = s->saved_aim[1];
            aim[0] = s->saved_aim[0];
            aim[1] = s->saved_aim[1];
            return next;
        } else {
            fn_886884E8(s);
        }
        s->aim_saved = 1;
        s->saved_aim[0] = aim[0];
        s->saved_aim[1] = aim[1];
        return next;
    }

    case GP3_MOVE_15_PICK_CANDIDATE: {
        int idx;
        q5b_u8 side;
        int volley;
        struct Gp2BallPrediction *pred;
        __vector4 here;
        int k;
        if (!p->is_human) {
            Q5bMoveState *st = p->state;
            side = 0;
            idx = -1;
            if (st->volley_only) {
                fn_8865DBA8(&s->scorer, &idx, &side, 0, 1);
                s->retarget_pending = 1;
                p->state->sample = idx;
                s->player->state->side = side;
                return GP3_MOVE_16_VOLLEY;
            }
            fn_8865DBA8(&s->scorer, &idx, &side, 1, 0);
            st->sample = idx;
            s->player->state->side = side;
            return fn_88699FC0(s);
        }
        if (s->state_ticks <= 3)
            return next;
        pred = p->own_ball->prediction;
        k = ts4_prediction_ticks_until_x_886600E0(pred, ts4_if_get_u32_off4c_8865EC70(&here, p)->v[0]);
        volley = 0;
        if (k != -1) {
            const q5b_u32 *ta = q5b_set_types(&s->sets[0]);
            const q5b_u32 *tb = q5b_set_types(&s->sets[1]);
            int baseline = ta[k] == GP2_HASH_BASELINE || tb[k] == GP2_HASH_BASELINE;
            int vol = !baseline && (ta[k] == GP3_HASH_VOLLEY || tb[k] == GP3_HASH_VOLLEY);
            volley = vol;
            if (!baseline && !vol)
                volley = q5b_fabs(pred->samples_begin[k].pos[0]) < K_VOLLEY_X_MAX;
        }
        if (volley && !(q5b_fabs(p->state->spin_c6c) >= K_SPIN_SPEED_MAX)) {
            volley = 1;
        } else {
            Q5bMoveState *st = p->state;
            if (!(st->reach_440 <= K_REACH_440_MIN)) {
                int j = ts4_if_call_seq_u32_off118_8865D790(s);
                __vector4 ball, pos;
                float spin = st->spin_444;
                q5b_u32 tag;
                float limit;
                ball = *q5b_sample_pos(pred, j);
                tag = p->team->state->side_tag;
                ts4_if_get_8865E730(&ball, tag);
                if (tag == GP3_HASH_COURT_SIDE_A) {
                    float a = spin + lbl_880C88DC;
                    fn_8817B608(&a);
                    spin = a;
                }
                pos = st->pos;
                limit = ts4_table2d_eval_8826D278(p->cfg->spin_table, pos.v[0], ball.v[0] - pos.v[0]);
                volley = q5b_fabs(spin) < limit;
            }
        }
        side = 0;
        idx = -1;
        ts4_call_seq_u32_off8_886894A8(&s->scorer, volley);
        fn_8865DBA8(&s->scorer, &idx, &side, 0, 0);
        if (idx == -1) {
            s->profile = s->player->cfg->profile_228;
            ts4_selection_scorer_run_8869AEF8(&s->scorer, 0, s->player->cfg->profile_228);
            fn_8865DBA8(&s->scorer, &idx, &side, 0, 0);
            if (idx == -1) {
                int moving;
                if (!can_react)
                    return next;
                if (fn_88678548(s))
                    return 0x12;
                if (!fn_886877A8(s))
                    return GP3_MOVE_13;
                ga4_publish_query_flag_8869A4D0(s);
                moving = q5b_is_moving(s->player);
                if (fn_886A58F0(s->player) || moving)
                    return GP3_MOVE_13;
                return 0x11;
            }
        }
        s->player->state->sample = idx;
        s->player->state->side = side;
        return fn_88699FC0(s);
    }

    case GP3_MOVE_16_VOLLEY: {
        int r = fn_886A9678(s);
        if (r == 1)
            return q5b_hold_sample(s, GP3_MOVE_16_VOLLEY);
        if (can_react && r == -1)
            return GP3_MOVE_13;
        if (!s->committed) {
            fn_886A2E48(s, s->player->cfg->profile_208);
            fn_886787D8(s);
        }
        fn_8866BD00(s);
        return next;
    }

    case GP3_MOVE_18:
        if (s->step_side_set)
            return q5b_contact_wait(s, next);
        if (s->state_ticks <= 5)
            return next;
        s->step_side_set = 1;
        p = s->player;
        if (p->hand->tag == GP2_HASH_LEFT) {
            p->state->step_fae = p->state->side == 0;
            s->player->state->step_faf = s->player->state->side;
        } else {
            p->state->step_fae = p->state->side;
            s->player->state->step_faf = s->player->state->side == 0;
        }
        return next;

    case GP3_MOVE_17: {
        struct Gp2BallPrediction *pred;
        const struct Gp2BallSample *e;
        __vector4 here, pos, step;
        Q5bMoveState *st;
        int k, behind;
        if (s->step_side_set)
            return q5b_contact_wait(s, next);
        p = s->player;
        pred = p->own_ball->prediction;
        if (pred->samples_begin == pred->samples_end)
            return next;
        k = ts4_prediction_ticks_until_x_886600E0(pred, ts4_if_get_u32_off4c_8865EC70(&here, p)->v[0]);
        if (k != -1) {
            e = pred->samples_begin + k;
        } else {
            e = 0;
            if (pred->samples_begin != pred->samples_end)
                e = pred->samples_end - 1;
        }
        if (e->tick - q5b_frame(p->match) >= 30)
            return next;
        s->step_side_set = 1;
        st = p->state;
        pos = st->pos;
        step = *(const __vector4 *)q5b_current_sample(p->step_ball->prediction)->pos;
        ts4_if_get_u32_off4c_8865EBF8(p, &step);
        behind = q5b_negative(step.v[2] - pos.v[2]);
        if (p->hand->tag == GP2_HASH_LEFT) {
            st->step_fac = behind == 0;
            s->player->state->step_fad = (q5b_u8)behind;
        } else {
            st->step_fac = (q5b_u8)behind;
            s->player->state->step_fad = behind == 0;
        }
        return next;
    }

    case GP3_MOVE_10:
    case GP3_MOVE_11:
        fn_8866BDD8(s, &s->player->state->pos);
        s->player->state->turn_on = 1;
        s->player->state->turn_weight = one;
        if (fn_88687AC0(s, s->player->cfg->cond_300)) {
            s->retarget_pending = 1;
            return GP3_MOVE_12;
        }
        return next;

    case GP3_MOVE_12: {
        int r;
        if (fn_886A2BE8(s))
            return GP3_MOVE_20_RUSH;
        r = fn_886A9678(s);
        if (r == 1)
            return q5b_hold_sample(s, GP3_MOVE_12);
        if (can_react && r == -1)
            return GP3_MOVE_13;
        fn_8866BD00(s);
        if (!s->committed)
            ts4_if_call_seq_u32_off154_886A9DF0(s);
        s->player->state->turn_on = 1;
        s->player->state->turn_weight = one;
        return next;
    }

    case GP3_MOVE_14: {
        Q5bMoveState *st;
        s->player->state->step_turn = zero;
        s->player->state->aim[3] = *(const q5b_u32 *)&zero;
        s->player->state->aim[1] = *(const q5b_u32 *)&zero;
        p = s->player;
        st = p->state;
        if (st->contact_ready) {
            Q5bMatch *m = p->match;
            int dt = m->balls->prediction->samples_begin[st->sample].tick - q5b_frame(m);
            int moving;
            if (!can_react || !(dt < 10))
                return next;
            if (!fn_886877A8(s))
                return next;
            moving = q5b_is_moving(s->player);
            if (fn_886A58F0(s->player) || moving)
                return GP3_MOVE_13;
            return 0x11;
        }
        if (!st->contact_fixed)
            return next;
        if (fn_886A9678(s) == 0) {
            __vector4 contact, target;
            float turn;
            p = s->player;
            st = p->state;
            contact = *q5b_sample_pos(p->own_ball->prediction, st->sample);
            target = *q5b_set_position(q5b_side_set(s, st->side), st->sample);
            ts4_if_get_8865E730(&contact, st->mirror_key);
            contact = __vrlimi(__vsubfp(contact, target), __lvlx(&lbl_8814B440, 0), 4, 3);
            turn = -(float)fn_88564BF8(contact.v[2], contact.v[0]) - *(const float *)&st->aim[0];
            fn_8817B608(&turn);
            if (!(q5b_fabs(turn) > K_TURN_ANGLE_MIN))
                return next;
        }
        return q5b_hold_sample(s, GP3_MOVE_14);
    }

    case GP3_MOVE_13: {
        q5b_u32 *aim = s->player->state->aim;
        q5b_u32 yaw = s->saved_aim[0];
        aim[2] = yaw;
        aim[3] = s->saved_aim[1];
        aim[0] = yaw;
        aim[1] = aim[3];
        return next;
    }

    case GP3_MOVE_19: {
        int left, fore;
        Q5bMoveState *st;
        float t;
        if ((int)s->state_ticks <= 10)
            return next;
        s->committed = 1;
        s->swing_set = 1;
        p = s->player;
        left = p->hand->tag == GP2_HASH_LEFT;
        st = p->state;
        p->swing_started = 1;
        fore = left != st->side;
        s->player->swing_forehand = (q5b_u8)fore;
        p = s->player;
        p->state->swing_hash = p->swing_forehand ? GP3_HASH_FH : GP3_HASH_BH;
        p = s->player;
        if (ts4_query_slot_matches_target_8865EB60(p))
            t = p->state->swing_time_slot;
        else
            t = fore ? p->state->swing_time_fh : p->state->swing_time_bh;
        p->state->swing_time = t;
        s->player->state->step_fb0 = (q5b_u8)fore;
        s->player->state->step_fb1 = fore == 0;
        s->player->state->swing_pending = 0;
        s->player->state->swing_armed = 1;
        s->resume_state = 0x13;
        return GP3_MOVE_9;
    }

    case GP3_MOVE_8_ADJUST_B:
        if (s->state_ticks <= 3)
            return next;
        if (ts4_two_event_ticks_remaining_886CD1E8(s->player->events) >= 0)
            return next;
        s->busy = 0;
        return s->resume_state;

    case GP3_MOVE_7_ADJUST_A: {
        Q5bLine path, run;
        __vector4 ahead, pos, flat_ahead, flat_pos, target, hit, dir;
        float t1, t2;
        Q5bMoveState *st;
        const struct Gp2CandidateSet *set;
        ts4_vec_with_offset_8867A908(p, &ahead, K_ADJUST_LOOKAHEAD);
        st = p->state;
        set = q5b_side_set(s, st->side);
        pos = st->pos;
        flat_ahead.v[0] = ahead.v[0];
        flat_ahead.v[1] = zero;
        flat_ahead.v[2] = ahead.v[2];
        flat_ahead.v[3] = zero;
        flat_pos.v[0] = pos.v[0];
        flat_pos.v[1] = zero;
        flat_pos.v[2] = pos.v[2];
        flat_pos.v[3] = zero;
        target = *q5b_set_position(set, st->sample);
        {
            __vector4 a = flat_pos, b = flat_ahead;
            fn_88189888(&path, &a, &b);
        }
        p = s->player;
        dir = p->body->facing;
        fn_8866D180(&dir, p->state->mirror_key);
        hit.v[0] = target.v[0];
        hit.v[1] = zero;
        hit.v[2] = target.v[2];
        hit.v[3] = zero;
        fn_8826AC10(&run, &hit, &dir);
        fn_881896F8(&path, &run, &hit, &t1, &t2);
        fn_8826D3A0(&hit, &path, &run, &t2);
        if (!s->adjust_running) {
            t2 = t2 + K_ADJUST_TIME_BIAS;
            if (q5b_negative(t2)) {
                float yaw;
                s->adjust_running = 1;
                s->adjust_countdown = 10;
                st = s->player->state;
                yaw = st->step_yaw + lbl_880C88DC;
                fn_8817B608(&yaw);
                st->step_yaw = (yaw >= zero) ? aim_pos : K_AIM_NEGATIVE;
                fn_88699300(s, s->resume_state);
            } else {
                struct Gp2BallPrediction *pred;
                __vector4 here;
                int k;
                p = s->player;
                pred = p->own_ball->prediction;
                k = ts4_prediction_ticks_until_x_886600E0(pred, ts4_if_get_u32_off4c_8865EC70(&here, p)->v[0]);
                if (k != -1) {
                    const struct Gp2BallSample *e = pred->samples_begin + k;
                    float lateral_max = p->cfg->contact_lateral_max;
                    int dt = e->tick - q5b_frame(p->match);
                    const __vector4 *me = ts4_if_get_u32_off4c_8865EC70(&here, p);
                    int low = q5b_negative(e->pos[1] - K_CONTACT_HEIGHT_MAX);
                    int close = q5b_negative(q5b_fabs(me->v[2] - e->pos[2]) - lateral_max);
                    if (low && close && dt < p->cfg->contact_frames_max) {
                        p->state->contact_fixed = 1;
                        s->player->state->sample = k;
                        s->player->state->side = 0;
                        s->profile = s->player->cfg->profile_208;
                        ga4_publish_query_flag_8869A4D0(s);
                        next = GP3_MOVE_14;
                    }
                }
            }
        } else {
            if (s->adjust_countdown <= 0) {
                s->busy = 0;
                return s->resume_state;
            }
            s->adjust_countdown--;
        }
        q5b_publish_step(s);
        return next;
    }

    case GP3_MOVE_9: {
        int r = s->resume_state;
        if (p->state->contact_fixed)
            return next;
        if (r != GP3_MOVE_4 && r != 0x13 && r != GP3_MOVE_12 && fn_886A3440(s)) {
            next = GP3_MOVE_3;
            s->busy = 0;
        }
        if (s->resume_state == GP3_MOVE_12 && fn_886A2BE8(s))
            return GP3_MOVE_20_RUSH;
        if (next != GP3_MOVE_9)
            return next;
        fn_8866BD00(s);
        if (s->committed)
            return next;
        if (!fn_886A2E48(s, s->profile))
            return next;
        if (s->resume_sample + 10 < s->player->state->sample || s->player->state->sample < s->resume_sample - 10)
            return s->resume_state;
        return next;
    }

    default:
        return next;
    }
}
