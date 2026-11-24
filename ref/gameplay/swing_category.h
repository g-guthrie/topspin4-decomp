/*
 * Swing-category rule lists: how the game writes AnimationSelection.SwingSelection.SwingCategory
 * (PlayerState S+0x360) before it asks the animation system for a swing clip.  Agent G6b.
 *
 * Code (Swing_DLL.dll, V = read instruction by instruction):
 *   fn_886B0250  mode: Normal when the call is a normal request, else AutoSwingGood when
 *                TimingState.0eaa0333 (S+0xD10) or SlowDown (S+0x7CC) > 0.5, else AutoSwingBad
 *   fn_886B01A8  class list from the swing class key S+0x35C (written by fn_886872A0)
 *   fn_886AFDF8  walks the rows: the first row whose condition holds is written to S+0x360 and the
 *                clip query runs; on "no clip" the row's AltValue is tried; the walk stops at the
 *                first row whose query started a clip
 *   fn_88697E98  the condition switch (one case per condition crc32)
 *   fn_886AC7E0  the clip query loops SwingPreferenceLevel 8, 7, ..., 3 (S+0x380) and keeps the
 *                first level that starts a clip
 * Data: Settings.bin PlayerTuning SwingSelectionCategory (data/gameplay/shot_tree.yaml
 * swing_category_rules).  Docs: docs/gameplay/controls-and-shot-selection.md s17.
 */
#ifndef TS4_SWING_CATEGORY_H
#define TS4_SWING_CATEGORY_H

#include <stdint.h>

/* condition crc32s (names recovered by dictionary search, see the doc) */
#define SC_COND_NONE                 0xDFA2AFF1u
#define SC_COND_FATALITY             0xC78C8F06u
#define SC_COND_GO_TO_NET            0x7E522D55u
#define SC_COND_IS_PERFECT           0x07F0DF25u
#define SC_COND_REACH_SLOW           0x693616C3u /* name unknown: min speed > PT+0x1B0 */
#define SC_COND_REACH_FAST           0x60D5B606u /* name unknown: min speed > PT+0x1B4 */
#define SC_COND_GOOD_REACH           0xDE050FD0u /* name unknown */
#define SC_COND_BAD_REACH            0x42864090u /* name unknown */
#define SC_COND_BAD_TIMING           0xD00AC582u
#define SC_COND_LATE_MANUAL          0x4041760Au /* name unknown, unused by the shipped lists */
#define SC_COND_IS_FAST_BALL         0xFE98362Eu
#define SC_COND_DROP_SHOT            0x990377A5u
#define SC_COND_VOLLEY_FORWARD       0x7D633A62u
#define SC_COND_GOOD_VOLLEY_RELEASE  0x28D4D485u
#define SC_COND_BAD_VOLLEY_RELEASE   0xDE102FECu
#define SC_COND_VOLLEY_SPECTACULAR   0x1DE220E2u
#define SC_COND_INSIDE_OUT           0xBD8EA388u
#define SC_COND_SKILL_REQUIRED       0xC42EF3FEu

#define SC_SHOT_SLICE     0xFC6F57A1u /* crc32("Slice") */
#define SC_SHOT_DROP_SHOT 0x990377A5u /* crc32("DropShot") */
#define SC_SHOT_TOPSPIN   0xD9FA1B37u /* crc32("TopSpin") */

/* Everything fn_88697E98 reads.  S = PlayerState, PT = PlayerTuning, ctx = player context. */
typedef struct {
    int is_human;                /* ctx+0x10 */
    int sticky_rb;               /* PC+0x3D: InputState.ReqVolleyRepos (RB) seen during the request */
    int in_net_zone;             /* fn_8866B6E0: |z| < PT+0x6F0 (300 cm) */
    int ai_net_request;          /* S+0x4E0 (written only by the AI serve/command block) */
    float power;                 /* S+0xE00 charge value 0..1 */
    float perfect_eval;          /* S+0x7D4 PerfectShotEvaluation */
    float volley_release;        /* S+0x7B8 (7e28dbc0.b928d859) */
    float slow_down;             /* S+0x7CC SlowDown */
    float manual_timing;         /* S+0x544 ShotContext.ManualShotTiming */
    float timing_value;          /* S+0xD08 TimingState.TimingValue */
    float min_speed_left;        /* S+0xA5C LeftLine MinSpeed (m/s needed to reach) */
    float min_speed_right;       /* S+0xABC RightLine MinSpeed */
    int volley_spectacular;      /* S+0x388 */
    int is_fast_ball;            /* S+0x5DD Context.IsFastBall */
    int is_baseline_fast_ball;   /* S+0x5DF */
    int is_inside_out;           /* S+0x5DB Context.IsInsideOut */
    uint32_t shot_id;            /* ctx+0x3C latched stroke id */
    float local_x;               /* S+0x8E0 LocalPosition[0] */
    int team_mode_2;             /* ctx->+0x4C->+0x2C == 2 */
    int skill_ok;                /* fn_8868F0D8(SkillId) for SkillRequired rows */
} ScInputs;

/* Tuning read by the conditions (PlayerTuning, shipped values in shot_tree.yaml). */
typedef struct {
    float min_speed_reach;       /* PT+0x1B0 = 3.5 */
    float min_speed_bad;         /* PT+0x1B4 = 4.5 */
    float late_timing;           /* PT+0x5BC = 0.1 */
    float window_hi;             /* PT+0x5C4 = 0.1 */
    float window_lo;             /* PT+0x5C8 = -0.3 */
    float fatality_power;        /* code constant lbl_880D0934 = 0.15 */
} ScTuning;

void sc_default_tuning(ScTuning *t);

/* fn_88697E98: 1 when the condition holds.  Unknown hashes give 0. */
int sc_condition(uint32_t cond, const ScInputs *in, const ScTuning *t);

/* fn_886B0250: 0 Normal, 1 AutoSwingGood, 2 AutoSwingBad. */
int sc_mode(int autoswing_call, int timing_state_d10, float slow_down);

/* fn_886872A0 (S+0x35C) + fn_886B01A8: class list index 0..5 =
 * FlatPower, FlatFinesse, Slice, VolleyStandard, VolleyPower, Smash. */
int sc_class(int is_volley, int is_smash, uint32_t shot_id, int require_finesse);

typedef struct {
    uint32_t value, alt, cond, skill_id;
    uint8_t easy_autoswing;
} ScRow;

/* Clip query: returns 0 when a clip was started, -1 when none matches, >0 = frames until the
 * racket event of the best clip (autoswing query only).  `category` is S+0x360, `level` S+0x380. */
typedef int (*ScQuery)(void *user, uint32_t category, uint32_t level, int autoswing, int frames);

/* fn_886AC7E0: try the preference levels in order. */
int sc_query_levels(ScQuery q, void *user, uint32_t category, const uint32_t *levels, int nlevels,
                    int autoswing, int frames);

typedef struct {
    uint32_t category;           /* final S+0x360 */
    int found;                   /* some query returned >= 0 (PC+0x40 reset) */
    int started;                 /* the last query started a clip */
    int autoswing_due;           /* PC+0x59C set: an autoswing clip is due within the limit */
    int row;                     /* index of the last row tried, -1 if none */
} ScResult;

/* fn_886AFDF8.  latched = PC+0x58D, autoswung = PC+0x59C on entry.  window/limit: the AutoSwing
 * frame pair chosen by IsInsideOut / S+0xBD2 (PT+0x6D0..0x6E4: 5/8, 10/20, 15/20). */
ScResult sc_walk(const ScRow *rows, int nrows, const ScInputs *in, const ScTuning *t,
                 int autoswing_call, int latched, int autoswung, int window, int limit,
                 ScQuery q, void *user, const uint32_t *levels, int nlevels);

/* ------------------------------------------------------------------------------------------------
 * G8: request modes, automatic swings, fast-ball flags, AI release and the charge
 * (docs/gameplay/controls-and-shot-selection.md s18).  C = read from code, D = data, I = inferred.
 * ---------------------------------------------------------------------------------------------- */

/* Which walk a request runs (fn_886B3CF8 states, C).  The AI always runs the Normal walk from its
 * release; a human runs it after a release before any clip started (state 0xF6EB6636), and the
 * autoswing walk (fn_886B0380 -> fn_886B0250(ctrl, 1)) while the button is held or for a
 * synthesized auto swing.  Returns the autoswing_call argument of sc_mode / sc_walk. */
int sc_request_autoswing_call(int is_ai, int released_before_clip);

/* fn_886B0380: TimingState S+0xD10 = (volley ? AutoVolleySwing S+0x7B4 : AutoSwing S+0x7B0) > 0.5. */
int sc_timing_state_d10(int is_volley, float auto_swing, float auto_volley_swing);

/* Evaluation graphs (Expressions.bin, D).  frames = S+0xCF0 (frames from the opponent's launch to
 * the ball reaching the player, filled by fn_88661B60), depth = S+0xCF4 (cm), hand/ret = ratings 0..1. */
float sc_eval_auto_swing(float frames, float min_segment_speed);       /* graph 179 -> S+0x7B0 */
float sc_eval_auto_volley_swing(float frames, float hand);              /* graph 174 -> S+0x7B4 */
float sc_eval_fast_net(float frames, float depth, float hand);          /* graph 175 -> S+0x7BC */
float sc_eval_fast_baseline(float depth, float hand);                   /* graph 176 -> S+0x7C0 */
float sc_eval_fast_return(float depth, float ret);                      /* graph 177 -> S+0x7C4 */
float sc_eval_perfect_shot(float manual_timing);                        /* graph 168 -> S+0x7D4 */

/* Planner_Reset fn_886BA768 fast-ball flags (C).  frames = frames to the ball sample nearest the
 * player, abs_dz = |dz| cm, y = that sample's height.  Returns 0 none, 1 IsFastBall S+0x5DD (return
 * of serve), 2 S+0x5DE (player nearer the net), 3 IsBaselineFastBall S+0x5DF. */
enum { SC_FAST_NONE = 0, SC_FAST_RETURN = 1, SC_FAST_NET = 2, SC_FAST_BASELINE = 3 };
int sc_fast_ball(int is_return_of_serve, int nearer_net, int frames, float abs_dz, float y);

/* Synthesized auto swing in state 0x93E5E96D (C): with no button, the request still enters the
 * waiting state (Raise on the Flat ShotTriggers entries, charge stays 0) when ctrl+0x38 > 0 and */
int sc_synth_auto_swing(int fast_kind, int is_volley, int team_mode_2, float eval_return_7c4,
                        float eval_baseline_7c0, float eval_net_7bc);

/* fn_8866B5B8: the human autoswing walk may run this frame (C).  timing_value = S+0xD08 (PT+0x5C0 = -1
 * is 40 frames before the ball), ball_past = prediction snapshot pred+0x5E0 in front of the player (I). */
int sc_autoswing_gate(float timing_value, int ball_past, int is_smash, int is_volley, int fast_kind);

/* The 12-frame auto-commit (vtbl +0x34, PT+0x740, C): contact_frame - now <= 12. */
int sc_auto_commit(int frames_to_contact);

/* AI release fn_886AE0E8 (C).  Fatality first at difficulty levels 3-5 (aitrig+0xA8 = S+0x3F0 from
 * graph 139/140, D); otherwise it releases when the best probed category is due in [0, limit). */
int sc_ai_fatality_first(int difficulty);
int sc_ai_release_limit(int fast_ball, int bd2);   /* 20 for fast balls, else PT+0x6F4 18 (+10 with S+0xBD2) */
int sc_ai_release(int min_frames, int limit);

/* Charge (fn_8869D720, C + D): power = curve cfg+0x8FC (frames / 60), keys [0..1.25 -> 0..1];
 * the InstantRocket curve cfg+0x914 has the same keys.  Tier: 0 Finesse < 0.15 <= 1 Medium < 0.7 <= 2 Powerful. */
float sc_charge_power(int hold_frames);
int sc_power_tier(float power);

#endif
