/* Q5 match candidate (not matched): the movement planner's per-tick state transition (Swing_DLL.xex 0x886B8468,
 * 0x2300 bytes). The proven fn_equiv source of the same function is eq_q5b_move_planner.c; this copy is restructured
 * toward the machine code (break + single return, inline helpers, literal constants) for the LTCG route.
 *
 * ts4_move_planner_transition_886B8468(planner, cur) returns the next Gp3MoveState of the planner owned by a
 * PlayerController (see work/gameplay-notes/gp3.md 5.3). Returning `cur` means "stay"; the caller loops until the
 * state is stable. Structure:
 *  - preamble: re-target check while planner->retarget_pending is set: when the committed ball sample is inside the
 *    re-target radius and the player would have to turn, jump to the step-adjust states 7/8 and clear the step flags;
 *    a turn event on player->events forces state 8;
 *  - dispatch on the (possibly changed) state through a 23-entry jump table.
 * Offsets, branch senses (NaN behaviour of every float compare) and the load order before possibly faulting loads
 * follow the machine code; names are by role (M/L confidence, see gp3.md). Not byte-matched: see the byte-gap line
 * above the function and work/q5/notes/886b8468_match_log.md (check command, contexts, per-step counts). */
#include "vx1_vector.h"
#include "gp3_types.h"

double fabs(double x);
#ifdef _MSC_VER
#pragma intrinsic(fabs)
#endif

typedef unsigned char q5b_u8;
typedef unsigned int q5b_u32;
typedef unsigned char q5b_bool; /* the game's bool: one byte, 0 or 1 */
/* a condition computed as an int and tested as a byte (the target zero-extends these flags at the test) */
#define Q5B_IS(flag) ((q5b_bool)(flag))

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

/* ---- tuning literals; LTCG pools them in the module constant pool (g_ts4_script_constants, 0x880D0F70) at the
 * offsets given (src/xbox360/pp1_pool_primer.c reproduces the pool layout) ---- */
#define K_ZERO                0.0f /* lbl_8814B440, outside the pool; its address also feeds the lvlx of q5b_set_y */
#define K_ONE                 1.0f /* +0x000 */
#define K_DEFAULT_RECV_LEAD   1000.0f /* +0x03C */
#define K_AIM_NEGATIVE        -1.5707963705062866f /* +0x0E4 */
#define K_AIM_POSITIVE        1.5707963705062866f /* +0x0E8 */
#define K_BOX_NEAR_MARGIN     50.0f /* +0x0F0 */
#define K_STEP_TURN_MIN       0.20000000298023224f /* +0x10C */
#define K_REACH_440_MIN       0.4000000059604645f /* +0x118 */
#define K_STEP_LOOKAHEAD      20.0f /* +0x130 */
#define K_JOG_FAR_SPEED       15.0f /* +0x1D4 */
#define K_STEP_TURN_MAX       0.10000000149011612f /* +0x2AC */
#define K_ADJUST_LOOKAHEAD    40.0f /* +0x404 */
#define K_CONTACT_HEIGHT_MAX  240.0f /* +0x40C */
#define K_ADJUST_TIME_BIAS    30.0f /* +0x42C */
#define K_SPIN_SPEED_MAX      225.0f /* +0x4EC */
#define K_JOG_ESCALATE_SPEED  35.0f /* +0x578 */
#define K_RETARGET_RADIUS2    62500.0f /* +0x818 */ /* 62500 = (250 cm)^2 */
#define K_RETARGET_YAW_TOL    0.9599311351776123f /* +0x81C */
#define K_RETARGET_ANGLE_LO   0.785375 /* +0x820 */
#define K_RETARGET_ANGLE_HI   2.359999895095825f /* +0x828 */
#define K_VOLLEY_X_MAX        700.0f /* +0x82C */
#define K_TURN_ANGLE_MIN      1.5707950592041016f /* +0x830 */


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
extern int fn_886600E0(struct Gp2BallPrediction *pred, float x);
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
/* sign bit of a float, read from its high half-word (lhz): as 0/1 and as the raw mask */
Q5B_INLINE int q5b_negative16(float f) { return *(const unsigned short *)&f >> 15; }
Q5B_INLINE int q5b_sign_bit(float f) { return *(const unsigned short *)&f & 0x8000; }

/* an angle wrapped into the principal range by fn_8817B608 */
typedef struct Q5bAngle { float rad; } Q5bAngle;

/* c >= 0 ? a : b. The target builds this as a +-1 table select (fcmpu; mfcr; lfsx; fsel) against the zero it keeps
 * in f30; a named static zero gives that select but is then no longer hoisted, so the literal is used here. */
Q5B_INLINE float q5b_select_ge0(float c, float a, float b) { return (c >= K_ZERO) ? a : b; }

Q5B_INLINE float q5b_dot(__vector4 a, __vector4 b)
{
    __vector4 d = __vmsum3fp(a, b);
    return d.v[0];
}

/* the player's position `frames` ticks ahead on its current path */
Q5B_INLINE __vector4 q5b_path_ahead(Q5bPlayer *p, int frames)
{
    __vector4 r;
    fn_8868ED00(p, &r, frames);
    return r;
}

/* the player's path position at time offset t */
Q5B_INLINE __vector4 q5b_path_at(Q5bPlayer *p, float t)
{
    __vector4 r;
    ts4_vec_with_offset_8867A908(p, &r, t);
    return r;
}

Q5B_INLINE float q5b_fabs(float f) { return (float)fabs(f); }

Q5B_INLINE int q5b_frame(const Q5bMatch *m) { return m->clock->frame; }

/* frames until the ball reaches the player's committed sample */
Q5B_INLINE int q5b_frames_to_contact(const Q5bPlayer *p)
{
    const Q5bMatch *m = p->match;
    return m->balls->prediction->samples_begin[p->state->sample].tick - q5b_frame(m);
}

/* candidate set of the committed side: side 0 uses sets[1] */
Q5B_INLINE const struct Gp2CandidateSet *q5b_side_set(const Q5bPlanner *s, int side)
{
    const struct Gp2CandidateSet *set = s->sets;
    if (!side)
        set++;
    return set;
}

/* data of a self-relative array header */
Q5B_INLINE const void *q5b_rel_data(const struct Gp2RelArray *a) { return (const char *)a + a->offset; }

Q5B_INLINE const __vector4 *q5b_set_position(const struct Gp2CandidateSet *set, int i)
{
    return (const __vector4 *)q5b_rel_data(&set->positions) + i;
}

Q5B_INLINE const q5b_u32 *q5b_set_types(const struct Gp2CandidateSet *set)
{
    return (const q5b_u32 *)((const char *)&set->types + set->types.offset);
}

/* candidate type hash of sample k on one side */
Q5B_INLINE q5b_u32 q5b_set_type(const struct Gp2CandidateSet *set, int k) { return q5b_set_types(set)[k]; }

/* v with its height lane replaced (lvlx of the scalar + vrlimi, the vector library's set-y) */
Q5B_INLINE __vector4 q5b_set_y(__vector4 v, float y) { return __vrlimi(v, __lvlx(&y, 0), 4, 3); }

/* x lane of a vector passed by value */
Q5B_INLINE float q5b_x(__vector4 v) { return v.v[0]; }

/* copy a {yaw, turn} pair as raw words */
Q5B_INLINE void q5b_copy_pair(q5b_u32 *dst, const q5b_u32 *src)
{
    dst[0] = src[0];
    dst[1] = src[1];
}

Q5B_INLINE const __vector4 *q5b_sample_pos(const struct Gp2BallPrediction *pred, int i)
{
    return (const __vector4 *)pred->samples_begin[i].pos;
}

/* the {begin, end} pair of a prediction's sample array */
typedef struct Q5bSampleList { struct Gp2BallSample *begin, *end; } Q5bSampleList;

Q5B_INLINE const Q5bSampleList *q5b_samples(const struct Gp2BallPrediction *pred)
{
    return (const Q5bSampleList *)&pred->samples_begin;
}

Q5B_INLINE int q5b_list_empty(const Q5bSampleList *l) { return l->begin == l->end; }
Q5B_INLINE const struct Gp2BallSample *q5b_list_begin(const Q5bSampleList *l) { return l->begin; }
Q5B_INLINE const struct Gp2BallSample *q5b_list_end(const Q5bSampleList *l) { return l->end; }

/* the first usable sample of a prediction, or null when it is empty */
Q5B_INLINE const struct Gp2BallSample *q5b_current_sample(const struct Gp2BallPrediction *pred)
{
    const struct Gp2BallSample *e = 0;
    const Q5bSampleList *l = q5b_samples(pred);
    if (pred->samples_begin != pred->samples_end)
        e = l->begin + pred->first_sample;
    return e;
}

/* first and last sample of a prediction, or null when it is empty (the game's 0x8865A410 / 0x8865A3E8, inlined) */
Q5B_INLINE const struct Gp2BallSample *q5b_first_sample(const struct Gp2BallPrediction *pred)
{
    const struct Gp2BallSample *e = 0;
    if (!q5b_list_empty(q5b_samples(pred)))
        e = q5b_list_begin(q5b_samples(pred));
    return e;
}

Q5B_INLINE const struct Gp2BallSample *q5b_last_sample(const struct Gp2BallPrediction *pred)
{
    const struct Gp2BallSample *e = 0;
    if (!q5b_list_empty(q5b_samples(pred)))
        e = q5b_list_end(q5b_samples(pred)) - 1;
    return e;
}

/* v with the height and w lanes cleared */
Q5B_INLINE __vector4 q5b_flat(__vector4 v)
{
    __vector4 r;
    r.v[0] = v.v[0];
    r.v[1] = K_ZERO;
    r.v[2] = v.v[2];
    r.v[3] = K_ZERO;
    return r;
}

Q5B_INLINE Q5bComponent *q5b_find_component(Q5bComponent *c, Q5bComponent *end, q5b_u32 kind)
{
    Q5bComponent *found = 0;
    for (; c != end; c++) {
        if (c->kind == kind) {
            found = c;
            break;
        }
    }
    return found;
}

Q5B_INLINE int q5b_is_moving(const Q5bPlayer *p)
{
    q5b_u32 m = p->anim->move_mode;
    return m == GP3_HASH_RUSH || m == GP3_HASH_JOG;
}

Q5B_INLINE int q5b_anim_is(const Q5bPlayer *p, q5b_u32 mode) { return p->anim->move_mode == mode; }

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

/* copy the {step_yaw, step_turn} pair into aim[0..1], then that pair into aim[2..3] */
Q5B_INLINE void q5b_publish_step(Q5bPlanner *s)
{
    Q5bMoveState *st = s->player->state;
    q5b_copy_pair(st->aim, (const q5b_u32 *)&st->step_yaw);
    q5b_copy_pair(s->player->state->aim + 2, st->aim);
}

Q5B_INLINE Q5bAngle q5b_wrapped(float rad)
{
    Q5bAngle a;
    a.rad = rad;
    fn_8817B608(&a.rad);
    return a;
}

/* line through two points passed by value */
Q5B_INLINE void q5b_line_through(Q5bLine *line, __vector4 a, __vector4 b) { fn_88189888(line, &a, &b); }

/* the box-margin based contact wait of states 17 and 18 once the side is set */
Q5B_INLINE int q5b_contact_wait(Q5bPlanner *s, int next)
{
    Q5bMatch *m = s->player->match;
    __vector4 center = m->box->center;
    float bounds[4];
    int near, lead;
    const struct Gp2BallSample *e;
    fn_8866E318(m, 0, bounds);
    near = ts4_box_margin_8866E058(&center, bounds) < K_BOX_NEAR_MARGIN;
    lead = Q5B_IS(near) ? 1 : 20;
    e = q5b_current_sample(m->balls->prediction);
    if (e->tick - q5b_frame(m) >= lead)
        return next;
    if (s->state_ticks <= 1)
        return next;
    return GP3_MOVE_13;
}

/* byte-gap: 679 off (aligned; size 0x22b8 vs 0x2300, 201 off beyond register/stack-slot choice); LTCG route with the
 * vector callees as context. Blockers: the target reloads player state after the by-value vector getters (C++
 * return-by-value mod/ref) and gives each by-value getter call its own stack slot in an order C does not reproduce. */
int ts4_move_planner_transition_886B8468(Q5bPlanner *s, int cur)
{
    Q5bPlayer *p = s->player;
    q5b_bool can_react = fn_8866D930(p);
    int next = cur;
    /* results of the by-value position getter: the target keeps one temporary per call site */
    __vector4 here_step, here_adjust, here_lateral, here_ready, here_pick;

    if (s->retarget_pending) {
        const struct Gp2CandidateSet *set;
        __vector4 contact, target, pos, delta;
        s->retarget_pending = 0;
        set = q5b_side_set(s, p->state->side);
        contact = *q5b_sample_pos(p->own_ball->prediction, p->state->sample);
        target = *q5b_set_position(set, p->state->sample);
        ts4_if_get_8865E730(&contact, p->state->mirror_key);
        pos = p->state->pos;
        delta = __vsubfp(target, pos);
        if (q5b_dot(delta, delta) < K_RETARGET_RADIUS2) {
            __vector4 probe, side, toward;
            int ahead, facing, slow;
            q5b_bool jump;
            float *step;
            float d;
            ahead = q5b_dot(delta, __vsubfp(target, q5b_path_ahead(p, 20))) > K_ZERO;
            jump = 0;
            step = &p->state->step_yaw;
            side = q5b_set_y(__vsubfp(contact, target), K_ZERO);
            probe = q5b_path_at(p, K_STEP_LOOKAHEAD);
            d = q5b_dot(side, delta);
            toward = __vsubfp(probe, pos);
            facing = d > K_ZERO && q5b_dot(toward, side) > K_ZERO;
            slow = step[1] < K_STEP_TURN_MIN;
            if (Q5B_IS(facing)) {
                if (Q5B_IS(ahead)) {
                    jump = 1;
                } else if (!Q5B_IS(slow)) {
                    float turn_max = K_STEP_TURN_MAX;
                    float ang, a;
                    int fast, lo, hi;
                    jump = 0;
                    fast = step[1] > turn_max;
                    if (Q5B_IS(fast))
                        jump = q5b_fabs(step[0] - K_AIM_POSITIVE) < K_RETARGET_YAW_TOL ||
                               q5b_fabs(step[0] + K_AIM_POSITIVE) < K_RETARGET_YAW_TOL;
                    ang = (float)fn_88564BF8(delta.v[2], delta.v[0]);
                    a = q5b_fabs(ang);
                    lo = (double)a < K_RETARGET_ANGLE_LO;
                    hi = a > K_RETARGET_ANGLE_HI;
                    jump = jump && !Q5B_IS(lo) && !Q5B_IS(hi); /* 886B8714: the jump needs LO <= |angle| <= HI */
                    if (jump && step[1] < turn_max) {
                        step[1] = K_ONE;
                        step[0] = ang;
                    }
                }
                p = s->player;
                {
                    int can_turn = !q5b_anim_is(p, GP3_HASH_IDLE) && !q5b_anim_is(p, Q5B_HASH_ANIM_TURN_LOCK);
                    if (Q5B_IS(can_turn) && jump) {
                        s->resume_state = cur;
                        s->adjust_running = 0;
                        q5b_clear_step_flags(s);
                        next = GP3_MOVE_7_ADJUST_A + (Q5B_IS(ahead) != 0);
                    }
                }
            }
            {
                q5b_u32 kind;
                int turn_event;
                p = s->player;
                ts4_if_call_seq_u32_off28_886C7D58(&kind, p->events);
                turn_event = kind == Q5B_HASH_EVENT_TURN_A || kind == Q5B_HASH_EVENT_TURN_B;
                if (Q5B_IS(turn_event) && next == cur) {
                    s->adjust_running = 0;
                    s->resume_state = next;
                    next = GP3_MOVE_8_ADJUST_B;
                    q5b_clear_step_flags(s);
                }
            }
        }
    }

    switch (next) {
    case GP3_MOVE_0_AFTER_HIT_WAIT: {
        Q5bTeam *team = s->player->team;
        if ((float)(q5b_frame(team->match) - team->state->last_hit_frame) >= s->player->ai->tuning->reaction_frames ||
            team->mode == 2)
            next = GP3_MOVE_1_READY;
        break;
    }

    case GP3_MOVE_1_READY: {
        int far_from_steps;
        if (can_react && s->player->match->rules->mode == 2 &&
            s->player->match->courts[s->player->team->state->court_index]->info->kind == Q5B_HASH_COURT_KIND_SKIP) {
            next = q5b_hold(s);
            break;
        }
        q5b_score_default(s);
        p = s->player;
        if (!p->is_human) {
            Q5bAi *ai = p->ai;
            Q5bComponent *found = q5b_find_component(p->components_begin, p->components_end, GP3_HASH_RECEIVER);
            Q5bMoveState *st = p->state;
            float lead = K_DEFAULT_RECV_LEAD;
            void *receiver = found->object;
            if (st->recv_a_on && st->recv_a_valid)
                lead = st->recv_a_lead;
            else if (st->recv_b_on && st->recv_b_valid)
                lead = st->recv_b_lead;
            ai->tuning->receive_lead = lead;
            fn_886B81E0(receiver);
        }
        far_from_steps = 0;
        if (can_react) {
            Q5bPlayer *q = s->player;
            if (ts4_abs_less_8866DA00(q) && q->team->mode != 2) {
                __vector4 flat;
                const struct Gp2BallSample *e, *last;
                float r2;
                int near;
                ts4_loop_call_seq_u32_off2c_8890E988(s->list);
                near = 0;
                p = s->player;
                flat = q5b_flat(*ts4_if_get_u32_off4c_8865EC70(&here_ready, p));
                r2 = p->state->step_radius * p->state->step_radius;
                last = q5b_last_sample(p->match->balls->prediction);
                for (e = q5b_first_sample(p->match->balls->prediction); e != last; e++) {
                    __vector4 step = __vsubfp(flat, q5b_flat(*(const __vector4 *)e->pos));
                    if (q5b_dot(step, step) < r2) {
                        near = 1;
                        break;
                    }
                }
                if (!Q5B_IS(near))
                    far_from_steps = 1;
            }
        }
        if (Q5B_IS(far_from_steps)) {
            Q5bPlayer *q;
            int moving;
            if (!fn_886877A8(s)) {
                next = q5b_hold(s);
                break;
            }
            ga4_publish_query_flag_8869A4D0(s);
            q = s->player;
            moving = q5b_is_moving(q);
            if (fn_886A58F0(q) || Q5B_IS(moving)) {
                next = q5b_hold(s);
                break;
            }
            next = 0x11;
            break;
        }
        if (s->pending_target != -1) {
            ts4_loop_call_seq_u32_off2c_8890E988(s->list);
            next = GP3_MOVE_14;
            s->player->state->swing_pending = s->player->state->contact_ready;
            s->player->state->swing_armed = s->player->state->contact_ready == 0;
            p = s->player;
            s->contact_pos = p->state->pos;
            s->contact_frame = q5b_frame(p->match);
            break;
        }
        next = fn_886A9E48(s, 1);
        if (next != cur)
            break;
        {
            int free_ = !s->lock->locked_a && !s->lock->locked_b;
            if (can_react && Q5B_IS(free_)) {
                if (fn_88678548(s)) {
                    next = 0x12;
                } else if (fn_886877A8(s)) {
                    Q5bPlayer *q;
                    int moving;
                    ga4_publish_query_flag_8869A4D0(s);
                    q = s->player;
                    moving = q5b_is_moving(q);
                    if (!fn_886A58F0(q) && !Q5B_IS(moving))
                        next = 0x11;
                    else
                        next = q5b_hold(s);
                } else {
                    next = q5b_hold(s);
                }
            }
        }
        if (next != cur)
            break;
        {
            Q5bMatch *m;
            Q5bBall *ball;
            int landed, lim, waiting;
            p = s->player;
            m = p->match;
            ball = m->balls->ball;
            landed = ball->mode == GP3_HASH_LET_IN || ball->mode == GP3_HASH_LET_OUT;
            if (Q5B_IS(landed))
                landed = ball->land_frame - q5b_frame(m) <= 0;
            if (Q5B_IS(landed)) {
                next = GP3_MOVE_2;
                break;
            }
            lim = (int)p->state->wait_frames;
            waiting = !ts4_elapsed_within_limit_8865DB50(s) && s->wait_marker > -1;
            if (q5b_frame(m) - p->team->state->last_hit_frame > lim && !ts4_elapsed_within_limit_8865DB50(s)) {
                next = GP3_MOVE_2;
                break;
            }
            if (Q5B_IS(waiting)) {
                next = GP3_MOVE_2;
                break;
            }
            break;
        }
    }

    case GP3_MOVE_2: {
        int free_;
        Q5bPlayer *q;
        int moving;
        q5b_score_default(s);
        next = fn_886A9E48(s, 2);
        if (next != cur)
            break;
        free_ = !s->lock->locked_a && !s->lock->locked_b;
        if (!can_react || !Q5B_IS(free_))
            break;
        if (fn_88678548(s)) {
            next = 0x12;
            break;
        }
        if (!fn_886877A8(s)) {
            next = q5b_hold(s);
            break;
        }
        ga4_publish_query_flag_8869A4D0(s);
        q = s->player;
        moving = q5b_is_moving(q);
        if (!fn_886A58F0(q) && !Q5B_IS(moving)) {
            next = 0x11;
            break;
        }
        next = q5b_hold(s);
        break;
    }

    case GP3_MOVE_3:
        if (fn_88687AC0(s, s->player->cfg->cond_2ac)) {
            next = GP3_MOVE_4;
            s->retarget_pending = 1;
        }
        break;

    case GP3_MOVE_4: {
        int r = fn_886A9678(s);
        if (r == 1) {
            next = q5b_hold_sample(s, GP3_MOVE_4);
            break;
        }
        if (can_react && r == -1)
            next = GP3_MOVE_13;
        break;
    }

    case GP3_MOVE_5:
    case GP3_MOVE_6: {
        int r, prepared;
        if (fn_886A3440(s)) {
            next = GP3_MOVE_3;
            s->busy = 0;
        }
        if (next != cur)
            break;
        prepared = next == GP3_MOVE_5 && fn_88687AC0(s, s->player->cfg->cond_2b8);
        if (Q5B_IS(prepared)) {
            next = GP3_MOVE_6;
            s->retarget_pending = 1;
            break;
        }
        if (fn_886A26E0(s)) {
            next = 0x13;
            break;
        }
        r = fn_886A9678(s);
        if (r == 1 && next == GP3_MOVE_6) {
            next = q5b_hold_sample(s, GP3_MOVE_6);
            break;
        }
        if (can_react && r == -1) {
            next = GP3_MOVE_13;
            break;
        }
        fn_8866BD00(s);
        if (!s->committed)
            fn_886A2E48(s, s->player->cfg->profile_208);
        break;
    }

    case GP3_MOVE_20_RUSH:
    case GP3_MOVE_21_JOG_PREPARED:
    case GP3_MOVE_22_JOG_JOG_PREPARED: {
        q5b_bool reached, jog_ok;
        int both;
        q5b_u32 *aim;
        if (fn_886A3440(s)) {
            next = GP3_MOVE_3;
            s->busy = 0;
        }
        if (next != cur)
            break;
        if (fn_886A26E0(s)) {
            next = 0x13;
            break;
        }
        reached = fn_8866C150(s);
        jog_ok = fn_88678708(s, s->player->cfg->cond_2f4);
        both = next == GP3_MOVE_21_JOG_PREPARED && reached && jog_ok;
        if (Q5B_IS(both)) {
            next = GP3_MOVE_22_JOG_JOG_PREPARED;
        } else {
            int rush_ready = next == GP3_MOVE_20_RUSH && reached;
            float speed = fn_8866BFE8(s);
            int fast = speed > K_JOG_ESCALATE_SPEED;
            int far_ = speed > K_JOG_FAR_SPEED;
            int escalate = Q5B_IS(rush_ready) && (Q5B_IS(fast) || (Q5B_IS(far_) && jog_ok));
            if (Q5B_IS(escalate)) {
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
        }
        aim = s->player->state->aim;
        if (!s->mode_locked) {
            fn_886884E8(s);
            if (!s->mode_prepared && s->state_ticks > 0)
                s->player->input->hold = 1;
            if (!s->mode_fixed)
                fn_886987C8(s);
            s->aim_saved = 1;
            q5b_copy_pair(s->saved_aim, aim);
            break;
        } else if (s->aim_saved) {
            q5b_copy_pair(aim + 2, s->saved_aim);
            q5b_copy_pair(aim, s->saved_aim);
            break;
        } else {
            fn_886884E8(s);
        }
        s->aim_saved = 1;
        q5b_copy_pair(s->saved_aim, aim);
        break;
    }

    case GP3_MOVE_15_PICK_CANDIDATE: {
        int idx;
        q5b_u8 side;
        q5b_bool volley;
        struct Gp2BallPrediction *pred;
        Q5bScorer *scorer;
        int k;
        p = s->player;
        if (!p->is_human) {
            Q5bMoveState *st = p->state;
            side = 0;
            idx = -1;
            if (st->volley_only) {
                fn_8865DBA8(&s->scorer, &idx, &side, 0, 1);
                s->retarget_pending = 1;
                next = GP3_MOVE_16_VOLLEY;
                p->state->sample = idx;
                s->player->state->side = side;
                break;
            }
            fn_8865DBA8(&s->scorer, &idx, &side, 1, 0);
            st->sample = idx;
            s->player->state->side = side;
            next = fn_88699FC0(s);
            break;
        }
        if (s->state_ticks <= 3)
            break;
        pred = p->own_ball->prediction;
        volley = 0;
        k = fn_886600E0(pred, ts4_if_get_u32_off4c_8865EC70(&here_pick, p)->v[0]);
        if (k != -1) {
            const struct Gp2CandidateSet *sets = s->sets;
            q5b_bool baseline = q5b_set_type(&sets[0], k) == GP2_HASH_BASELINE ||
                                q5b_set_type(&sets[1], k) == GP2_HASH_BASELINE;
            volley = !baseline &&
                     (q5b_set_type(&sets[0], k) == GP3_HASH_VOLLEY || q5b_set_type(&sets[1], k) == GP3_HASH_VOLLEY);
            if (!baseline && !volley)
                volley = q5b_fabs(pred->samples_begin[k].pos[0]) < K_VOLLEY_X_MAX;
        }
        if (volley && q5b_fabs(p->state->spin_c6c) < K_SPIN_SPEED_MAX) {
            volley = 1;
        } else {
            Q5bMoveState *st = p->state;
            if (st->reach_440 > K_REACH_440_MIN) {
                int j = ts4_if_call_seq_u32_off118_8865D790(s);
                __vector4 ball, pos;
                float spin = st->spin_444;
                int tag;
                float limit;
                ball = *q5b_sample_pos(pred, j);
                tag = (int)p->team->state->side_tag;
                ts4_if_get_8865E730(&ball, (q5b_u32)tag);
                if (tag == (int)GP3_HASH_COURT_SIDE_A) {
                    float a = spin + lbl_880C88DC;
                    fn_8817B608(&a);
                    spin = a;
                }
                pos = st->pos;
                limit = ts4_table2d_eval_8826D278(p->cfg->spin_table, q5b_x(pos), ball.v[0] - q5b_x(pos));
                volley = q5b_fabs(spin) < limit;
            }
        }
        scorer = &s->scorer;
        side = 0;
        idx = -1;
        ts4_call_seq_u32_off8_886894A8(scorer, volley);
        fn_8865DBA8(scorer, &idx, &side, 0, 0);
        if (idx == -1) {
            s->profile = s->player->cfg->profile_228;
            ts4_selection_scorer_run_8869AEF8(scorer, 0, s->player->cfg->profile_228);
            fn_8865DBA8(scorer, &idx, &side, 0, 0);
            if (idx == -1) {
                Q5bPlayer *q;
                int moving;
                if (!can_react)
                    break;
                if (fn_88678548(s)) {
                    next = 0x12;
                    break;
                }
                if (!fn_886877A8(s)) {
                    next = GP3_MOVE_13;
                    break;
                }
                ga4_publish_query_flag_8869A4D0(s);
                q = s->player;
                moving = q5b_is_moving(q);
                if (fn_886A58F0(q) || Q5B_IS(moving)) {
                    next = GP3_MOVE_13;
                    break;
                }
                next = 0x11;
                break;
            }
        }
        s->player->state->sample = idx;
        s->player->state->side = side;
        next = fn_88699FC0(s);
        break;
    }

    case GP3_MOVE_16_VOLLEY: {
        int r = fn_886A9678(s);
        if (r == 1) {
            next = q5b_hold_sample(s, GP3_MOVE_16_VOLLEY);
            break;
        }
        if (can_react && r == -1) {
            next = GP3_MOVE_13;
            break;
        }
        if (!s->committed) {
            fn_886A2E48(s, s->player->cfg->profile_208);
            fn_886787D8(s);
        }
        fn_8866BD00(s);
        break;
    }

    case GP3_MOVE_18:
        if (s->step_side_set) {
            next = q5b_contact_wait(s, next);
            break;
        }
        if (s->state_ticks <= 5)
            break;
        s->step_side_set = 1;
        p = s->player;
        if (p->hand->tag == GP2_HASH_LEFT) {
            p->state->step_fae = p->state->side == 0;
            s->player->state->step_faf = s->player->state->side;
        } else {
            p->state->step_fae = p->state->side;
            s->player->state->step_faf = s->player->state->side == 0;
        }
        break;

    case GP3_MOVE_17: {
        struct Gp2BallPrediction *pred;
        const Q5bSampleList *l;
        const struct Gp2BallSample *e;
        __vector4 pos, step;
        Q5bMoveState *st;
        int k;
        q5b_bool behind;
        if (s->step_side_set) {
            next = q5b_contact_wait(s, next);
            break;
        }
        p = s->player;
        pred = p->own_ball->prediction;
        l = q5b_samples(pred);
        if (pred->samples_begin == pred->samples_end)
            break;
        k = fn_886600E0(pred, ts4_if_get_u32_off4c_8865EC70(&here_step, p)->v[0]);
        if (k != -1) {
            e = l->begin + k;
        } else {
            e = 0;
            if (l->begin != l->end)
                e = pred->samples_end - 1;
        }
        if (e->tick - q5b_frame(p->match) >= 30)
            break;
        s->step_side_set = 1;
        st = p->state;
        pos = st->pos;
        step = *(const __vector4 *)q5b_current_sample(p->step_ball->prediction)->pos;
        ts4_if_get_u32_off4c_8865EBF8(p, &step);
        behind = q5b_negative16(step.v[2] - pos.v[2]);
        if (p->hand->tag == GP2_HASH_LEFT) {
            st->step_fac = behind == 0;
            s->player->state->step_fad = behind;
        } else {
            st->step_fac = behind;
            s->player->state->step_fad = behind == 0;
        }
        break;
    }

    case GP3_MOVE_10:
    case GP3_MOVE_11:
        fn_8866BDD8(s, &s->player->state->pos);
        s->player->state->turn_on = 1;
        s->player->state->turn_weight = K_ONE;
        if (fn_88687AC0(s, s->player->cfg->cond_300)) {
            s->retarget_pending = 1;
            { next = GP3_MOVE_12; break; }
        }
        break;

    case GP3_MOVE_12: {
        int r;
        if (fn_886A2BE8(s))
            { next = GP3_MOVE_20_RUSH; break; }
        r = fn_886A9678(s);
        if (r == 1)
            { next = q5b_hold_sample(s, GP3_MOVE_12); break; }
        if (can_react && r == -1)
            { next = GP3_MOVE_13; break; }
        fn_8866BD00(s);
        if (!s->committed)
            ts4_if_call_seq_u32_off154_886A9DF0(s);
        s->player->state->turn_on = 1;
        s->player->state->turn_weight = K_ONE;
        break;
    }

    case GP3_MOVE_14: {
        Q5bMoveState *st;
        s->player->state->step_turn = K_ZERO;
        *(float *)&s->player->state->aim[3] = K_ZERO;
        *(float *)&s->player->state->aim[1] = K_ZERO;
        p = s->player;
        if (p->state->contact_ready) {
            int soon = q5b_frames_to_contact(p) < 10;
            Q5bPlayer *q;
            int moving;
            if (!can_react || !Q5B_IS(soon))
                break;
            if (!fn_886877A8(s))
                break;
            q = s->player;
            moving = q5b_is_moving(q);
            if (fn_886A58F0(q) || Q5B_IS(moving)) {
                next = GP3_MOVE_13;
                break;
            }
            next = 0x11;
            break;
        }
        if (!s->player->state->contact_fixed)
            break;
        if (fn_886A9678(s) == 0) {
            const struct Gp2CandidateSet *set;
            __vector4 contact, target;
            float turn;
            p = s->player;
            st = p->state;
            set = q5b_side_set(s, st->side);
            contact = *q5b_sample_pos(p->own_ball->prediction, p->state->sample);
            target = *q5b_set_position(set, p->state->sample);
            ts4_if_get_8865E730(&contact, p->state->mirror_key);
            contact = q5b_set_y(__vsubfp(contact, target), K_ZERO);
            turn = -(float)fn_88564BF8(contact.v[2], contact.v[0]) - *(const float *)&st->aim[0];
            fn_8817B608(&turn);
            if (!(q5b_fabs(turn) > K_TURN_ANGLE_MIN))
                break;
        }
        next = q5b_hold_sample(s, GP3_MOVE_14);
        break;
    }

    case GP3_MOVE_13: {
        q5b_u32 *aim = s->player->state->aim;
        q5b_u32 yaw = s->saved_aim[0];
        aim[2] = yaw;
        aim[3] = s->saved_aim[1];
        aim[0] = yaw;
        aim[1] = aim[3];
        break;
    }

    case GP3_MOVE_19: {
        int left, fore;
        Q5bMoveState *st;
        float t;
        if ((int)s->state_ticks <= 10)
            break;
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
        { next = GP3_MOVE_9; break; }
    }

    case GP3_MOVE_8_ADJUST_B:
        if (s->state_ticks <= 3)
            break;
        if (ts4_two_event_ticks_remaining_886CD1E8(s->player->events) >= 0)
            break;
        s->busy = 0;
        { next = s->resume_state; break; }

    case GP3_MOVE_7_ADJUST_A: {
        Q5bLine path;
        __vector4 target;
        float t2;
        p = s->player;
        {
            __vector4 ahead = q5b_path_at(p, K_ADJUST_LOOKAHEAD);
            Q5bMoveState *st = p->state;
            const struct Gp2CandidateSet *set = q5b_side_set(s, st->side);
            target = *q5b_set_position(set, st->sample);
            q5b_line_through(&path, q5b_flat(st->pos), q5b_flat(ahead));
        }
        {
            Q5bLine run;
            __vector4 dir, hit;
            float t1;
            p = s->player;
            dir = p->body->facing;
            fn_8866D180(&dir, p->state->mirror_key);
            hit = q5b_flat(target);
            fn_8826AC10(&run, &hit, &dir);
            fn_881896F8(&path, &run, &hit, &t1, &t2);
            fn_8826D3A0(&hit, &path, &run, &t2);
        }
        if (!s->adjust_running) {
            t2 = t2 + K_ADJUST_TIME_BIAS;
            if (q5b_sign_bit(t2)) {
                Q5bMoveState *st;
                Q5bAngle yaw;
                s->adjust_running = 1;
                s->adjust_countdown = 10;
                st = s->player->state;
                yaw = q5b_wrapped(st->step_yaw + lbl_880C88DC);
                st->step_yaw = q5b_select_ge0(yaw.rad, K_AIM_POSITIVE, K_AIM_NEGATIVE);
                fn_88699300(s, s->resume_state);
            } else {
                struct Gp2BallPrediction *pred;
                int k;
                p = s->player;
                pred = p->own_ball->prediction;
                k = fn_886600E0(pred, ts4_if_get_u32_off4c_8865EC70(&here_adjust, p)->v[0]);
                if (k != -1) {
                    const struct Gp2BallSample *e = pred->samples_begin + k;
                    float lateral_max = p->cfg->contact_lateral_max;
                    int dt = e->tick - q5b_frame(p->match);
                    const __vector4 *me = ts4_if_get_u32_off4c_8865EC70(&here_lateral, p);
                    int low = q5b_negative16(e->pos[1] - K_CONTACT_HEIGHT_MAX);
                    int close = q5b_negative16(q5b_fabs(me->v[2] - e->pos[2]) - lateral_max);
                    int ok = low && close && dt < p->cfg->contact_frames_max;
                    if (Q5B_IS(ok)) {
                        p->state->contact_fixed = 1;
                        s->player->state->sample = k;
                        s->player->state->side = 0;
                        s->profile = s->player->cfg->profile_208;
                        next = GP3_MOVE_14;
                        ga4_publish_query_flag_8869A4D0(s);
                    }
                }
            }
            q5b_publish_step(s);
            break;
        }
        if (s->adjust_countdown <= 0) {
            s->busy = 0;
            next = s->resume_state;
            break;
        }
        s->adjust_countdown--;
        q5b_publish_step(s);
        break;
    }

    case GP3_MOVE_9: {
        int r = s->resume_state;
        p = s->player;
        if (p->state->contact_fixed)
            break;
        if (r != GP3_MOVE_4 && r != 0x13 && r != GP3_MOVE_12 && fn_886A3440(s)) {
            next = GP3_MOVE_3;
            s->busy = 0;
        }
        if (s->resume_state == GP3_MOVE_12 && fn_886A2BE8(s))
            { next = GP3_MOVE_20_RUSH; break; }
        if (next != GP3_MOVE_9)
            break;
        fn_8866BD00(s);
        if (s->committed)
            break;
        if (!fn_886A2E48(s, s->profile))
            break;
        if (s->resume_sample + 10 < s->player->state->sample || s->player->state->sample < s->resume_sample - 10)
            { next = s->resume_state; break; }
        break;
    }

    default:
        break;
    }
    return next;
}
