/*
 * Readable reference for the movement-responsiveness rules that G9 read from
 * code: stick -> RequiredMove, the pre-hit freeze, the AI reaction wait, the
 * net-rush decider, the animation cross-fade weight and the root-track sampler.
 *
 * docs/gameplay/movement-and-ai.md section E and movement-and-animation.md
 * section 7 give the addresses and grades (C = read from code, D = read from
 * data, I = inferred).  No game data: every threshold is a parameter; the
 * shipped values are in data/gameplay/tunables/Settings/04_RepositioningSettings.yaml
 * and data/gameplay/root_motion.yaml.
 *
 *   cc -std=c11 -Wall -Wextra -Werror -o /tmp/test_resp \
 *      ref/gameplay/test_responsiveness.c ref/gameplay/responsiveness.c -lm && /tmp/test_resp
 *
 * Units: cm, frames (60 Hz), radians.
 */
#ifndef TS4_RESPONSIVENESS_H
#define TS4_RESPONSIVENESS_H

/* fn_8869C010, MoveMode 0x9E51242B (stick), C.  The stick (x right, y up,
 * after the 0.4 radial dead zone of the input mapper) becomes the court vector
 * v = (y, 0, -x); Power = min(|v|, 1); LocalDirection = atan2(v.x, v.z), plus pi
 * for the player on the far side (tag 0xA2EDA1E7), wrapped to (-pi, pi]. */
void rs_stick_to_required_move(float stick_x, float stick_y, int far_side,
                               float *direction, float *power);

/* fn_8866F740 pre-hit freeze, C.  Applies in match mode while the opponent is
 * the next hitter; frames_to_hit = opponent planned hit frame - clock
 * (fn_8865EF98).  Inside the last freeze_frames (cfg+0xA88 = 20) the move is
 * latched on the first frozen frame; afterwards, while frames_to_hit >
 * stop_frames (cfg+0xA8C = 10), a new power < 0.1 with a latched power > 0.1
 * latches "stopped" (all powers 0) for the rest of the window. */
typedef struct {
    int frozen;
    int stopped;
    float dir;
    float power;
} RsFreeze;

void rs_freeze_reset(RsFreeze *f);
void rs_prehit_freeze(RsFreeze *f, int applies, int frames_to_hit,
                      int freeze_frames, int stop_frames,
                      float in_dir, float in_power, float *out_dir, float *out_power);

/* Planner state 0 (fn_886B8468 at 0x886B8918), C: wait until
 * clock - stamp >= delay (profile+0x1DC, float; 0 for humans, graph output for
 * the AI); doubles (team+0x2C == 2) leaves at once. */
int rs_reaction_done(int clock, int stamp, float delay, int doubles);

/* fn_8869B928 repositioning decider (net rush = mode 2), C. */
typedef struct {
    int gate;            /* (ctx+0x1C)+0x4C byte +0x1A3 set; 0 skips the decider */
    float player_x;      /* own x, cm; negative = own half, net at 0 */
    float player_z;
    float move_power;    /* S+0x9DC */
    float angle_to_net;  /* |stick direction - direction to the net point|, rad */
    float dist_to_net;   /* distance to the net point, cm */
    int rb;              /* @ReqFastRepos S+0x4E2 */
    int play_mode;       /* (ctx+0x48)+0x78 -> +0 */
    int prev_mode;       /* this+0x40 before the call */
    int opp_plan_valid;  /* fn_8865EF98 returned true */
    int frames_to_hit;   /* opponent planned hit frame - clock (compared unsigned) */
} RsRushIn;

typedef struct {
    float net_x;         /* 8154a27b: x above -500 = already at the net */
    float min_power;     /* pool +0x2AC = 0.1 */
    float max_angle;     /* 324f5246 = 40 deg, in radians */
    float min_dist;      /* 0081913b = 175 */
    float box_x0, box_x1, box_z;   /* -1100 < x < -700, |z| < 400 */
    int refuse_frames;   /* cfg+0xA88 = 20 */
} RsRushCfg;

int rs_rush_mode(const RsRushIn *in, const RsRushCfg *cfg);

/* fn_886D89E8, C: cross-fade weight of the incoming animation node,
 * linear elapsed / duration, clamped to [0, 1]; the outgoing node gets 1 - w. */
float rs_blend_weight(float elapsed, float duration);

/* fn_88644CE8, C: root displacement between phases t1 and t2 of one RTTake.
 * xz holds count_minus_one + 2 readable entries {x, z} (the entry after the
 * last is read with weight 0 at t = 1).  Position(t): u = t * N, i = trunc(u),
 * lerp(xz[i], xz[i+1], u - i).  Clip-local +x forward, +z left. */
void rs_root_delta(const float (*xz)[2], float count_minus_one, float t1, float t2,
                   float *dx, float *dz);

/* Frames from the first moving frame until the cumulative root distance reaches
 * target_cm, for per-frame root deltas d[0..n-1] (cm) scaled by a linear
 * cross-fade of blend_frames (0 = none, frame k gets weight min(1, (k+1)/blend)).
 * Returns -1 if never reached.  (I: the cross-fade weights the root delta; the
 * outgoing idle contributes ~0.) */
int rs_frames_to_distance(const float (*d)[2], int n, float blend_frames, float target_cm);

#endif
