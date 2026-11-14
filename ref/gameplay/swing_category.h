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

#endif
