/*
 * Readable reference for Top Spin 4 locomotion animation: how a move command
 * becomes a (group, subgroup) clip choice, how clips chain through the
 * transition matrix and transition events, the clip clock (frame mapping, busy
 * time, play rate) and root-motion displacement.
 *
 * The movement *planner* (23 states, regimes, reach speed, jog ramp) is in
 * ref/gameplay/movement.c and player.c and is not repeated here.
 * docs/gameplay/movement-and-animation.md gives the addresses and confidence
 * (V / I / U) of every function.  No game data: tables are parameters; the
 * shipped tables are in data/gameplay/animation_rules.yaml.
 *
 *   cc -std=c11 -Wall -Wextra -Werror -o /tmp/test_locomotion \
 *      ref/gameplay/test_locomotion.c ref/gameplay/locomotion.c -lm && /tmp/test_locomotion
 *
 * Units: cm, frames (60 Hz), radians.  Yaw 0 faces +z; positive yaw turns left
 * (towards +x).  Clip-local root motion: +z forward, +x left.
 */
#ifndef TS4_LOCOMOTION_H
#define TS4_LOCOMOTION_H

#include <stdint.h>

/* ------------------------------------------------------------ sectors */

/* Move-set sector order (swinganimation.bin e784b9e7 lists, V): eight
 * directions counter-clockwise from Front, then Stand/Idle, then the second
 * Back variant (Jog: [4] Back_LookRight / [9] Back_LookLeft; Rush: [4]
 * Back_TurnLeft / [9] Back_TurnRight). */
typedef enum {
    LO_FRONT = 0, LO_FRONT_LEFT, LO_LEFT, LO_BACK_LEFT, LO_BACK,
    LO_BACK_RIGHT, LO_RIGHT, LO_FRONT_RIGHT, LO_STAND, LO_BACK_ALT,
    LO_SECTOR_COUNT
} LoSector;

/* TransitionEventDefinition Direction values (bit i of a Direction mask, V). */
typedef enum {
    LO_DIR_NONE = 0, LO_DIR_FRONT, LO_DIR_FRONT_RIGHT, LO_DIR_RIGHT,
    LO_DIR_BACK_RIGHT, LO_DIR_BACK, LO_DIR_BACK_LEFT, LO_DIR_LEFT, LO_DIR_FRONT_LEFT
} LoDirection;

/* Pace values (bit i of a Pace mask, V). */
typedef enum {
    LO_PACE_SIDESTEPS = 0, LO_PACE_JOG, LO_PACE_SERVE, LO_PACE_JOG_FH, LO_PACE_JOG_BH,
    LO_PACE_BACKSTEPS, LO_PACE_STEPS_FH, LO_PACE_STEPS_BH, LO_PACE_BACKSTEPS_FH,
    LO_PACE_BACKSTEPS_BH, LO_PACE_JOG_VOLLEY_FH, LO_PACE_JOG_VOLLEY_BH,
    LO_PACE_STEPS_VOLLEY_FH, LO_PACE_STEPS_VOLLEY_BH, LO_PACE_BACKSTEPS_VOLLEY_FH,
    LO_PACE_BACKSTEPS_VOLLEY_BH
} LoPace;

/* Direction of travel relative to facing -> one of the 8 sectors, or LO_STAND
 * when |dir|^2 <= dead_zone_sq.  look_left selects LO_BACK_ALT for Back (I:
 * the key is AnimationSelection/b873c3ab/LookLeft). */
LoSector lo_sector8(float facing_yaw, float dir_x, float dir_z, float dead_zone_sq, int look_left);
/* 16-way variant (Volley_Repositioning, 22.5 deg); 0 = Front, counter-clockwise. */
int lo_sector16(float facing_yaw, float dir_x, float dir_z);
/* Sector -> Direction value used by transition-event masks. */
LoDirection lo_sector_direction(LoSector s);

typedef struct { int16_t group, subgroup; } LoSectorEntry;   /* [AnimGroup, SubGroup] */
typedef struct { const LoSectorEntry *sectors; int count; } LoMoveSet;

/* Pick the sector entry; falls back to LO_BACK for a missing LO_BACK_ALT and
 * to entry 0 for an out-of-range sector.  Returns 0 on success. */
int lo_moveset_pick(const LoMoveSet *ms, LoSector s, LoSectorEntry *out);

/* --------------------------------------------------------- transitions */

/* TransitionEvent (0x28 bytes in the Animation record +0x70 list, V). */
typedef struct {
    float cycle_position, blend_cycle_position;
    uint32_t direction_mask, pace_mask;
    float position, duration;              /* phase window [position, position+duration] */
    float default_cycle_position;
    uint32_t reactivity_tag, start_blend_tag;
    uint8_t in, out;                       /* window may be entered / left here */
} LoTransitionEvent;

/* Does the event accept a move in direction d at pace p (mask bit tests, I). */
int lo_event_accepts(const LoTransitionEvent *e, LoDirection d, LoPace p);
/* Index of the first Out window that is open at or after phase `now`
 * (now <= position + duration) and accepts (d, p); -1 if none. */
int lo_next_out_event(const LoTransitionEvent *ev, int n, float now, LoDirection d, LoPace p);
/* Phase is inside the window of an Out event that accepts (d, p): the clip
 * may be interrupted now (I: ReactivityTag picks the reaction class). */
int lo_can_leave(const LoTransitionEvent *ev, int n, float now, LoDirection d, LoPace p);

typedef enum { LO_RULE_TRANSITION = 0, LO_RULE_ALLOW = 1 } LoRuleKind;

/* TransitionRuleList entry (polymorphic, V).  Transition: play the bridging
 * clip group/subgroup between the two sub-groups; Allow: cut directly.
 * Absent fields take the caller defaults (lo_rule_defaults). */
typedef struct {
    LoRuleKind kind;
    int16_t group, subgroup;               /* bridging clip (Transition only) */
    int8_t src_event, dst_event;           /* TransitionEvent index in from / to clip */
    float low_vivacity_speed, high_vivacity_speed;
    float blend_in_frames, blend_out_frames;
} LoTransitionRule;

void lo_rule_defaults(LoTransitionRule *r);   /* speeds 1.0, blends 15 frames */

/* Sparse TransitionMatrix row: absolute sub-group index -> {to, rule} pairs. */
typedef struct { int16_t to, rule; } LoMatrixCell;
typedef struct { const LoMatrixCell *cells; int count; } LoMatrixRow;

/* Rule index for from -> to absolute sub-groups, -1 when not allowed. */
int lo_matrix_rule(const LoMatrixRow *rows, int nrows, int from_sub, int to_sub);
/* Bridging speed for a vivacity in [0, 1] (I: lerp low -> high). */
float lo_rule_speed(const LoTransitionRule *r, float vivacity);

/* Linear cross-fade weight of the incoming clip after `frames` of a blend of
 * `blend_frames` (I: shape not traced; endpoints from the rule). */
float lo_blend_weight(float frames, float blend_frames);

/* ------------------------------------------------------------ clock */

/* Phase -> frame (fn_886D1408, V; gp7 "ratio" is FrameCount):
 * clamp((phase - t0) * (frame_count - 1) + base, base, end). */
float lo_phase_to_frame(float phase, float t0, float frame_count, float base, float end);
/* Frames until the clip's Out window (fn_886CD3C8, V): segment = TransitionEvent[1]. */
float lo_frames_until_out(float out_position, float t0, float frame_count, float base, float now);

/* Clip property flags used by the clock. */
typedef struct {
    float frame_count;          /* Properties +0x00 */
    float speed_coef;           /* Properties +0x04 */
    uint8_t no_mirror;          /* Properties +0x18 */
    uint8_t ignore_speed_coef;  /* Properties +0x19 */
} LoClipProps;

/* Play rate of a clip (I for the product, V for each input's existence):
 * global Parameters.SpeedCoef x clip SpeedCoef (unless IgnoreSpeedCoef) x the
 * group's gameplay coef when the group allows it (RushSpeedCoef S+0x398,
 * SwingSpeedCoef S+0x378, VolleySpeedCoef S+0x39C = 1.15) x transition speed. */
float lo_play_rate(const LoClipProps *c, float global_coef, int group_allows_coef,
                   float gameplay_coef, float transition_speed);

/* Locomotion loop (I): Jog/Rush/Sidesteps clips carry Cycle_In / Cycle_Out
 * AnimEvents (221 clips).  While the move continues, a phase that passes
 * Cycle_Out wraps back by (cycle_out - cycle_in). */
float lo_cycle_phase(float phase, float cycle_in, float cycle_out);

/* Code-driven yaw (RotYBehavior, record +0x7C, I for the curve):
 * RotY_JogType {ApplyRotYStartFrom, OutAngle} (178 clips) turns the body by
 * OutAngle (+-pi/4 on diagonals) between start_frame and end_frame (the
 * ApplyRotY event window, or the clip end); RotY_BasicTransition {Transition
 * ZoneStart/Stop, Coef, InAngle, OutAngle} (327 clips) blends In -> Out angle
 * over the zone.  Returns the yaw offset at `frame`. */
float lo_roty_offset(float frame, float start_frame, float end_frame, float in_angle, float out_angle);

/* ---------------------------------------------------------- root motion */

typedef struct { float x, y, z; } LoVec3;

/* World displacement for a clip-local root delta: optional mirror (x -> -x,
 * left-handed playback, I), scale by rate and rotate by facing yaw using the
 * fit's rotation x' = x c - z s, z' = x s + z c with (s, c) = sincos(-yaw)
 * (V for the rotation form, fn_886D3AD8). */
LoVec3 lo_root_step(LoVec3 local, float facing_yaw, int mirrored, float rate);

/* ------------------------------------------------------------ planner glue */

/* Speed override S+0xDE8: the new value replaces the old one only when it
 * differs by more than `threshold` (0.4, pool+0x118; fn_886AA420, V).  The
 * override scales the locomotion speed (1 = run, 0 = walk). */
float lo_override_update(float current, float proposed, float threshold);

/* Retarget prologue of fn_886B8468 (V radius / idle test; the angle tests are
 * folded into angles_ok because their sign logic is only partly decoded):
 * returns 7 (turn) or 8 (stop, heading dot > 0) or -1 (no retarget). */
int lo_retarget(LoVec3 contact, LoVec3 player, float radius_sq, int anim_is_idle,
                float heading_dot, int angles_ok);

#endif
