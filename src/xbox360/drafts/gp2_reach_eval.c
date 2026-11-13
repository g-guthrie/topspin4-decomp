/*
 * GP2 (WP2) DRAFT: reachability ("required run speed") of every predicted ball sample.
 *
 *   fn_8868B4E8 (0x894 B)  ReachEvaluator::EvaluateSide(set)   -> set->reach_speed[i]  (HUD "Reachability: %.2f m.s-1")
 *   fn_8868BD80 (0x22c B)  ReachEvaluator::UpdateSideFlags()   -> sets[0].valid_a / sets[1].valid_a
 *   fn_8869B178 (0x7ac B)  ReachEvaluator::BuildCandidates()   -> positions[], types[], first/last index
 *
 * Read from machine code (VMX128 vector math rewritten as plain float code). Not byte-identical:
 * the originals are vector/fsel heavy and were not attempted for matching. Uncertain parts: `/ * ? * /`.
 * Units: positions cm, time = 60 Hz ticks, 0.6 = 60/100 turns cm/tick into m/s.
 * Axes (hypothesis): x = along court toward the net (mirrored per court side by fn_8865EC70), y = up, z = across.
 */
#include "../gp2_types.h"

#include <float.h>
#include <math.h>

typedef struct { float x, y, z; } Gp2Vec3;

/* ReachTuning (evaluator->tuning, data driven; offsets are what the code reads). */
struct Gp2ReachTuning {
    /* +0x00/+0x0c/+0x18/+0x24: four rel float arrays indexed by stroke level (fn_8869B178) */
    unsigned char pad0[0x30];
    float zone_limit[4];       /* +0x30 vec4: |x| < zone_limit.x and |z| < zone_limit.z keeps a candidate alive */
    float h_ground_far;        /* +0x40 y below this = ground-stroke band, ball out of volley depth zone */
    float h_ground_near;       /* +0x44 same, ball inside the volley depth zone */
    float h_mid_lo_near;       /* +0x48 near zone: y in (+0x48, +0x4c) = overhead band */
    float h_mid_hi_near;       /* +0x4c */
    float h_mid_lo_far;        /* +0x50 far zone band */
    float h_mid_hi_far;        /* +0x54 */
    unsigned char pad58[0xb8 - 0x58];
    float side_line_threshold; /* +0xb8 fn_8868BD80 */
    unsigned char padbc[0xcc - 0xbc];
    /* +0xcc: piecewise-linear table (fn_881899D8): |t| -> number of preceding volley samples to cap */
    unsigned char padcc[0xd8 - 0xcc];
    float lateral_half_width;  /* +0xd8 fn_8869B178: |sample.x| < this */
    unsigned char padd8[0xf4 - 0xdc];
    float reach_dist_right;    /* +0xf4 ground-stroke reach radius, flag byte 0xbd2 == 0 */
    float volley_dead_x;       /* +0xf8 volley box half depth */
    float volley_dead_z;       /* +0xfc volley box half width */
    float reach_dist_left;     /* +0x100 reach radius, flag byte 0xbd2 != 0 (left-handed?) */
    float prep_ticks;          /* +0x104 swing preparation time, normal */
    float prep_ticks_volley;   /* +0x108 */
    float prep_ticks_alt;      /* +0x10c when 0xbd2 != 0 (and not volley) */
};

/* Constants fetched from the data pool (g_ts4_script_constants / lbl_880C8FB0): */
#define GP2_SPEED_UNREACHABLE      100.0f   /* pool[0x20/4]  stored when the sample cannot be hit */
#define GP2_SPEED_NO_TIME          FLT_MAX  /* pool[0x50/4]  in reach but no time to prepare the swing */
#define GP2_TICKS_TO_MS_FACTOR     0.6f     /* pool[0x114/4] 60 Hz / 100 cm per m */
#define GP2_VOLLEY_REACH_RADIUS    10.0f    /* lbl_880C8FB0[0] */
#define GP2_VOLLEY_BEHIND_MARGIN   150.0f   /* lbl_880C8FD0[0]: volley needs dx > -150 */
#define GP2_MIN_PREP_SLACK         1.0f     /* pool[0]: need at least one tick of slack */

/*
 * Swing_DLL.xex 0x8868B4E8: fill set->reach_speed[i] (m/s the player must run to be at the ball in time;
 * 0 = already there with time to swing, 100 = impossible, FLT_MAX = there but no time to swing).
 */
static void gp2_evaluate_side(
    void *evaluator_ctx,                 /* PlayerCtx */
    struct Gp2ReachTuning *tuning,
    struct Gp2CandidateSet *set,
    const struct Gp2CandidateSet *first_set,
    int now_tick,                        /* PlayerCtx->world->clock+0x310 */
    Gp2Vec3 player_pos,                  /* PlayerState+0x8e0 */
    float anim_busy_ticks,               /* fn_886CD3C8(PlayerCtx->swing_anim) */
    const struct Gp2BallPrediction *prediction,
    float (*run_turn_time)(void *ctx, Gp2Vec3 delta),     /* fn_88564BF8 atan2 + fn_8826D278 table */
    Gp2Vec3 (*predict_pos)(void *ctx, float ticks),       /* fn_8867A908 */
    int prefer_left_flag                 /* PlayerState+0xbd2 */
)
{
    int count = set->positions.count;
    float *out = (float *)((char *)&set->reach_speed + set->reach_speed.offset);
    unsigned int *types = (unsigned int *)((char *)&set->types + set->types.offset);
    Gp2Vec3 *pos = (Gp2Vec3 *)((char *)&set->positions + set->positions.offset); /* really vec4 stride 16 */
    int side_faces_ball = 1;
    int last_volley = -1;
    float reach_radius = prefer_left_flag ? tuning->reach_dist_left : tuning->reach_dist_right;
    int i;

    set->reach_speed.count = count;
    for (i = 0; i < count; i++) {
        out[i] = 0.0f;
    }
    set->best_reach_speed = FLT_MAX;

    /* side_faces_ball: sign of cross(first_sample - player, last_sample - first_sample) compared with
       which of the two sets this is (set 0 expects cross >= 0). Only when the prediction is non-empty. */
    if (prediction->samples_begin != prediction->samples_end) {
        const struct Gp2BallSample *first = &prediction->samples_begin[prediction->first_sample];
        const struct Gp2BallSample *last = prediction->samples_end - 1;
        float tx = last->pos[0] - first->pos[0], tz = last->pos[2] - first->pos[2];
        float ux = first->pos[0] - player_pos.x, uz = first->pos[2] - player_pos.z;
        int cross_negative = (ux * tz - tx * uz) < 0.0f;
        side_faces_ball = (cross_negative == (set == first_set));
    }

    for (i = 0; i < count; i++) {
        const struct Gp2BallSample *sample = &prediction->samples_begin[i]; /* indexed like the set */
        unsigned int type = types[i];
        int is_volley = (type == GP2_HASH_VOLLEY);
        Gp2Vec3 d = { pos[i].x - player_pos.x, pos[i].y - player_pos.y, pos[i].z - player_pos.z };
        float speed;
        float radius;
        Gp2Vec3 v;

        if (type == GP2_HASH_UNREACHABLE || (is_volley && d.x + GP2_VOLLEY_BEHIND_MARGIN < 0.0f)) {
            out[i] = GP2_SPEED_UNREACHABLE;      /* ball behind a volleyer / not a candidate */
        } else {
            if (is_volley) {
                last_volley = i;                  /* remembered for the post pass below */
                if (side_faces_ball) {            /* only the part outside the reach box counts */
                    float rx = fabsf(d.x) - tuning->volley_dead_x;
                    float rz = fabsf(d.z) - tuning->volley_dead_z;
                    v.x = rx > 0.0f ? rx : 0.0f; v.y = 0.0f; v.z = rz > 0.0f ? rz : 0.0f;
                } else {
                    v = d;                        /* ? full offset, y included */
                }
                radius = GP2_VOLLEY_REACH_RADIUS;
            } else {
                v = d;
                radius = reach_radius;
            }
            {
                float prep = is_volley ? tuning->prep_ticks_volley
                           : (prefer_left_flag ? tuning->prep_ticks_alt : tuning->prep_ticks);
                float ticks_to_ball = (float)(sample->tick - now_tick);
                float len = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);

                if (len < radius) {               /* already in reach: need time to wind up the swing */
                    float slack = ticks_to_ball - prep - anim_busy_ticks;
                    speed = (slack < GP2_MIN_PREP_SLACK) ? GP2_SPEED_NO_TIME : 0.0f;
                } else {                          /* must run: turn first, then run the remaining distance */
                    float turn = run_turn_time(evaluator_ctx, v); /* table(|atan2(dz,dx)|) from player tuning +0x17c */
                    Gp2Vec3 p = predict_pos(evaluator_ctx, turn);  /* where the player is after turning */
                    float run_in = sqrtf((pos[i].x - p.x) * (pos[i].x - p.x) + (pos[i].y - p.y) * (pos[i].y - p.y)
                                         + (pos[i].z - p.z) * (pos[i].z - p.z));
                    float turn_run = sqrtf((p.x - player_pos.x) * (p.x - player_pos.x)
                                           + (p.y - player_pos.y) * (p.y - player_pos.y)
                                           + (p.z - player_pos.z) * (p.z - player_pos.z));
                    float avail = ticks_to_ball - prep - turn - anim_busy_ticks;
                    if (avail < GP2_MIN_PREP_SLACK) {
                        speed = GP2_SPEED_UNREACHABLE;
                    } else {
                        speed = (run_in + turn_run - radius) / avail * GP2_TICKS_TO_MS_FACTOR;
                        if (speed < 0.0f) speed = 0.0f;
                        if (speed > FLT_MAX) speed = FLT_MAX;
                    }
                }
            }
            out[i] = speed;
        }
        if (out[i] < set->best_reach_speed) {
            set->best_reach_speed = out[i];       /* +0x1c running minimum */
        }
    }

    /* Post pass: the last volley sample at index k caps the cost of up to n preceding volley samples,
       n = (int)table_T+0xcc(|t|), t = intersection parameter of the player->ball ray with the volley line
       (fn_881896F8 then fn_881899D8). Stops at the first non-volley sample. */
    if (last_volley != -1) {
        int n = 0;                                /* ? from fn_881896F8 + table; exact t not recovered */
        int j;
        for (j = last_volley - 1; j >= (last_volley - n > 0 ? last_volley - n : 0); j--) {
            if (types[j] != GP2_HASH_VOLLEY) break;
            if (out[j] > out[last_volley]) out[j] = out[last_volley];
        }
    }
}

/*
 * Swing_DLL.xex 0x8868BD80: per side, is the player's predicted position (after pool[0x61c/4]=25 ticks)
 * more than tuning+0xb8 away from the ball line first->last sample, on that side?
 *   offset = dot(normalize((-dz, 0, dx)), predicted - first_pos),  dz,dx = last_pos - first_pos
 *   sets[0].valid_a = offset > thr ; sets[1].valid_a = offset' < -thr (own first/last of sets[1]);
 *   when both are set, the one with the smaller |offset| is kept.
 */
static void gp2_update_side_flags(struct Gp2CandidateSet *sets, float thr, Gp2Vec3 predicted_player)
{
    float o0, o1;
    int a, b;
    {
        float dx = sets[0].last_pos[0] - sets[0].first_pos[0], dz = sets[0].last_pos[2] - sets[0].first_pos[2];
        float nx = -dz, nz = dx, len = sqrtf(nx * nx + nz * nz);
        if (len != 0.0f) { nx /= len; nz /= len; }
        o0 = nx * (predicted_player.x - sets[0].first_pos[0]) + nz * (predicted_player.z - sets[0].first_pos[2]);
    }
    {
        float dx = sets[1].last_pos[0] - sets[1].first_pos[0], dz = sets[1].last_pos[2] - sets[1].first_pos[2];
        float nx = -dz, nz = dx, len = sqrtf(nx * nx + nz * nz);
        if (len != 0.0f) { nx /= len; nz /= len; }
        o1 = nx * (predicted_player.x - sets[1].first_pos[0]) + nz * (predicted_player.z - sets[1].first_pos[2]);
    }
    a = thr < o0;
    b = o1 < -thr;
    if (a && b) {
        if (fabsf(o0) < fabsf(o1)) b = 0; else a = 0;
    }
    sets[0].valid_a = (unsigned char)a;
    sets[1].valid_a = (unsigned char)b;
}

/*
 * Swing_DLL.xex 0x8869B178: classify every predicted ball sample into a candidate type per side.
 * Per sample i (ball position p, mirrored when the player is on court side 0xa2eda1e7):
 *   in_zone  = bounces(sample+0x28) <= 2 && i < first_sample + lookahead(table T+0xc0 at first.x) && |p.x| < T+0xd8
 *   low      = p.y < T[in_zone ? 0x44 : 0x40]
 *   overhead = !low && T[in_zone ? 0x48 : 0x50] < p.y < T[in_zone ? 0x4c : 0x54]
 *   tag      = low ? (in_zone ? Volley : Baseline) : (overhead ? Smash : Unreachable)   (? meaning of low/in_zone)
 *   and the tag is kept only if |p.x| > 150 (not on top of the net plane) else Unreachable.
 *   Each side stores p + that side's racket offset (4 offset vectors from the four tuning arrays at the
 *   player's stroke level, negated for left-handers "Left" = 0xda554856) into positions[i] and the tag into types[i];
 *   a side stops being extended as soon as its offset position leaves |x| < zone_limit.x, |z| < zone_limit.z.
 *   first/last accepted index and their positions go to set->first_index/last_index/first_pos/last_pos.
 * Not transcribed line by line (vector code); see work/gameplay-notes/gp2.md section 4.
 */
