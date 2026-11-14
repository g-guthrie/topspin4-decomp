/*
 * Readable reference for Top Spin 4 swing / special-move animation selection:
 * qualifier masks, the selection-procedure filter DSL of swinganimation.bin,
 * the seven gameplay keys that pick a swing family, left-hand mirroring, the
 * positional clip-fit cost fn_886D3AD8 (decoded by G4b), the special-move
 * triggers (Dive / VolleySpectacular) and the animation-tag rewards.
 *
 * docs/gameplay/movement-and-animation.md gives the addresses and confidence
 * of every function.  No game data: the shipped qualifier tables, procedures
 * and clip properties are in data/gameplay/animation_rules.yaml.
 *
 *   cc -std=c11 -Wall -Wextra -Werror -o /tmp/test_anim_select \
 *      ref/gameplay/test_anim_select.c ref/gameplay/anim_select.c -lm && /tmp/test_anim_select
 */
#ifndef TS4_ANIM_SELECT_H
#define TS4_ANIM_SELECT_H

#include <stdint.h>

#define AS_QUALIFIER_TYPES 46

/* Qualifier type indexes used by the swing path (QualifierTypes order, V). */
enum {
    AS_Q_POSITION_ON_COURT = 0, AS_Q_CATEGORY = 1, AS_Q_SWING_TYPE = 2, AS_Q_BH_TYPE = 3,
    AS_Q_SWING_EFFECT = 4, AS_Q_TIMING = 5, AS_Q_POWER = 7, AS_Q_CONTROL = 8,
    AS_Q_MOVE_TO_NET = 9
};
/* SwingCategory, Properties, Surface etc. have data-defined indexes; look
 * them up by name in animation_rules.yaml qualifier_types. */

/* Properties qualifier values (bit index, V from the QualifierTypes list). */
typedef enum {
    AS_PROP_RUSHING = 0, AS_PROP_SPECTACULAR, AS_PROP_POWERFUL_SHOT, AS_PROP_SWING_REACH,
    AS_PROP_REFLEX_VOLLEY, AS_PROP_SMASH, AS_PROP_WRONG_FOOT, AS_PROP_BAD_CONTROL,
    AS_PROP_SPLIT_STEPS_COMPLIANT, AS_PROP_WOOD_DOWN_COMPLIANT, AS_PROP_WOOD_UP_COMPLIANT
    /* Frustration*, Victory*, TrickShot, WoodRadiusCompliant follow; see YAML. */
} AsProperty;

/* One clip as seen by selection (AnimationsDB record + raw qualifier row). */
typedef struct {
    uint32_t id;                         /* crc32(name), record +0x84 */
    uint32_t q[AS_QUALIFIER_TYPES];      /* QualifierEnumRawDataArray row, bit i = value i */
    float frame_count;                   /* Properties +0x00 */
    float contact_phase;                 /* EventRacket Pos (0..1), <0 if none */
    uint8_t no_mirror;                   /* Properties +0x18 */
    int max_occurrence;                  /* Properties +0x40 */
} AsClip;

/* ------------------------------------------------------------ filters */

typedef enum {
    AS_NODE_EQUALS,          /* 00bf4ffc: constant value */
    AS_NODE_MATCH_KEY,       /* 332e57c4: value read from a gameplay key */
    AS_NODE_MATCH_KEY_MASK,  /* 1ae94a04: bitmask read from a gameplay key */
    AS_NODE_ALL,             /* cb3c6c47 */
    AS_NODE_ANY,             /* d837ca33 */
    AS_NODE_NOT              /* c4cc0a5f */
} AsNodeKind;

typedef struct AsNode {
    AsNodeKind kind;
    int qtype;                           /* leaf: qualifier type index */
    uint32_t value;                      /* EQUALS: value index */
    int key;                             /* MATCH_KEY(_MASK): index into the key array */
    int exclusive;                       /* leaf: the clip must carry only the wanted value(s) */
    const struct AsNode *const *children;
    int nchildren;
} AsNode;

/* Evaluate a selection-procedure node against a clip.  keys[] holds the
 * gameplay key values (value index for MATCH_KEY, mask for MATCH_KEY_MASK).
 * A clip whose mask for the type is 0 is unconstrained and passes a
 * non-exclusive leaf (I: 0 = wildcard, consistent with the counts). */
int as_eval(const AsNode *n, const AsClip *c, const uint32_t *keys);

/* The seven swing keys (qualifier_sources, V): PlayerState offsets of
 * SwingSelection/Output.  Values are qualifier value indexes, -1 = unset. */
typedef struct {
    int timing, power, control, move_to_net, position_on_court, swing_effect, swing_type;
} AsSwingKeys;

/* Swing candidate filter: Category = Swing and each set key matches. */
int as_swing_matches(const AsClip *c, const AsSwingKeys *k);

/* Left-hand mirroring (I): a left-handed player plays clips mirrored; a
 * NoMirror clip cannot be mirrored and is rejected for left-handers when
 * reject_no_mirror is set.  Returns 1 mirror, 0 as authored, -1 reject. */
int as_mirror_mode(const AsClip *c, int left_handed, int reject_no_mirror);

/* ------------------------------------------------------------ clip fit */

typedef struct { float x, y, z; } AsVec3;

/* One candidate as prepared for fn_886D3AD8. */
typedef struct {
    AsVec3 root_at_contact;   /* clip-local root offset sampled at the warped EventRacket time */
    int has_offset;           /* r28 != -1 */
    AsVec3 offset;            /* linked offset entry (clip-local) */
    float contact_frame;      /* t_c = frame + 10 + (t_end - t0 - t_s) * k */
    int side_matches;         /* mirror/side id == wanted: rotate by facing */
} AsFitCandidate;

typedef struct {
    AsVec3 base;              /* player position (v125) */
    AsVec3 target;            /* AnimIface+0x3C0 ball contact target */
    AsVec3 ref;               /* [AnimIface+0x564] racket reference */
    float facing_yaw;         /* [+0x70]+0x48 */
    float scale, y_scale;     /* splat [+0x20]+r20, AnimIface(+0x3CC)+0x55C */
    float t_min, t_max;       /* +0x3D0 / +0x3D4 contact frame window */
    float tol_x, tol_z;       /* +0x3D8 / +0x3DC */
} AsFitParams;

/* Squared contact error |p - (target - ref)|^2, or -1 when a gate fails
 * (fn_886D3AD8 steps 2..7, V structure; the |m| tolerance reshaping is left
 * to the caller through tol_x/tol_z). */
float as_fit_cost(const AsFitCandidate *c, const AsFitParams *p, AsVec3 *contact_out);
/* Arg-min over candidates (planner+0x168/+0x170); -1 when none passes. */
int as_fit_best(const AsFitCandidate *c, int n, const AsFitParams *p, float *best_cost);

/* Contact frame of a clip: EventRacket phase x FrameCount (V). */
float as_contact_frame(const AsClip *c);

/* --------------------------------------------------------- special moves */

/* Inputs of the VolleySpectacular (Dive) decision in fn_886BCE88 (V). */
typedef struct {
    float pos_x;                 /* S+0x8E0 */
    int team_mode;               /* ctx+0x4C -> +0x2C */
    int ctx_flag;                /* ctx+0x3B8 */
    int has_spectacular_skill;   /* skill 0x1E8D4F10 SpectacularVolleys */
    float timing_a;              /* S+0xD00 TimingState.1490306b */
    float timing_b;              /* S+0xCF0 TimingState.3fe3a099 */
} AsDiveInputs;

typedef struct { float min_x, a_min, b_max; int forbidden_team_mode; } AsDiveCfg;

void as_dive_defaults(AsDiveCfg *c);  /* -600 cm, 60, 45, mode 2 (shipped) */
int as_volley_spectacular(const AsDiveInputs *in, const AsDiveCfg *c);

/* Reward cells of the tag tracker fn_88697118 (I: cell <- Properties). */
typedef enum {
    AS_RW_SPECTACULAR = 1u << 0, AS_RW_REACH = 1u << 1, AS_RW_RUSHING = 1u << 2,
    AS_RW_POWERFUL = 1u << 3, AS_RW_REFLEX_VOLLEY = 1u << 4, AS_RW_SMASH = 1u << 5,
    AS_RW_TRICK_SHOT = 1u << 6
} AsReward;

/* Properties mask of the playing clip -> reward cells.  trick_shot_bit is the
 * data index of TrickShot in Properties. */
uint32_t as_rewards_from_props(uint32_t props, int trick_shot_bit);
/* Rising edges only: a reward fires once per clip. */
uint32_t as_reward_edges(uint32_t prev, uint32_t cur);
/* RushingToBall: distance run > d_min and ratio > r_min (cfg+0xC4 / +0xC8). */
int as_rushing_to_ball(float distance, float ratio, float d_min, float r_min);

/* Reach / lunge gates of state 19 (fn_886A26E0, V with shipped values). */
typedef struct {
    float h_min, h_max;          /* PT+0x3BC..0x3C0: 50..200 cm */
    float min_dist;              /* PT+0x3F4: 100 cm */
} AsReachCfg;
int as_reach_allowed(const AsReachCfg *c, float contact_height, float target_distance);

#endif
