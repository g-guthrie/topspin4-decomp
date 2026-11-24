/*
 * Locomotion animation reference.  See locomotion.h for the contract and
 * docs/gameplay/movement-and-animation.md for addresses and confidence.
 */
#include "locomotion.h"

#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/* Angle of the travel direction relative to facing, in [0, 2pi), counter-
 * clockwise (left) positive. */
static float rel_angle(float facing_yaw, float dir_x, float dir_z)
{
    float a = atan2f(dir_x, dir_z) - facing_yaw;
    const float two_pi = (float)(2.0 * M_PI);
    a = fmodf(a, two_pi);
    if (a < 0.0f)
        a += two_pi;
    return a;
}

LoSector lo_sector8(float facing_yaw, float dir_x, float dir_z, float dead_zone_sq, int look_left)
{
    if (dir_x * dir_x + dir_z * dir_z <= dead_zone_sq)
        return LO_STAND;
    float a = rel_angle(facing_yaw, dir_x, dir_z);
    int s = (int)floorf(a / (float)(M_PI / 4.0) + 0.5f) & 7;
    if (s == LO_BACK && look_left)
        return LO_BACK_ALT;
    return (LoSector)s;
}

int lo_sector16(float facing_yaw, float dir_x, float dir_z)
{
    float a = rel_angle(facing_yaw, dir_x, dir_z);
    return (int)floorf(a / (float)(M_PI / 8.0) + 0.5f) & 15;
}

LoDirection lo_sector_direction(LoSector s)
{
    static const LoDirection map[LO_SECTOR_COUNT] = {
        LO_DIR_FRONT, LO_DIR_FRONT_LEFT, LO_DIR_LEFT, LO_DIR_BACK_LEFT, LO_DIR_BACK,
        LO_DIR_BACK_RIGHT, LO_DIR_RIGHT, LO_DIR_FRONT_RIGHT, LO_DIR_NONE, LO_DIR_BACK
    };
    return (s >= 0 && s < LO_SECTOR_COUNT) ? map[s] : LO_DIR_NONE;
}

int lo_moveset_pick(const LoMoveSet *ms, LoSector s, LoSectorEntry *out)
{
    if (!ms || ms->count <= 0)
        return -1;
    int i = (int)s;
    if (i == LO_BACK_ALT && ms->count <= LO_BACK_ALT)
        i = LO_BACK;
    if (i < 0 || i >= ms->count)
        i = 0;
    *out = ms->sectors[i];
    return 0;
}

int lo_event_accepts(const LoTransitionEvent *e, LoDirection d, LoPace p)
{
    if (!(e->direction_mask & (1u << d)))
        return 0;
    return (e->pace_mask & (1u << p)) != 0;
}

int lo_next_out_event(const LoTransitionEvent *ev, int n, float now, LoDirection d, LoPace p)
{
    int best = -1;
    for (int i = 0; i < n; ++i) {
        if (!ev[i].out || now > ev[i].position + ev[i].duration || !lo_event_accepts(&ev[i], d, p))
            continue;
        if (best < 0 || ev[i].position < ev[best].position)
            best = i;
    }
    return best;
}

int lo_can_leave(const LoTransitionEvent *ev, int n, float now, LoDirection d, LoPace p)
{
    for (int i = 0; i < n; ++i)
        if (ev[i].out && now >= ev[i].position && now <= ev[i].position + ev[i].duration &&
            lo_event_accepts(&ev[i], d, p))
            return 1;
    return 0;
}

void lo_rule_defaults(LoTransitionRule *r)
{
    r->kind = LO_RULE_ALLOW;
    r->group = r->subgroup = -1;
    r->src_event = r->dst_event = 1;
    r->low_vivacity_speed = r->high_vivacity_speed = 1.0f;
    r->blend_in_frames = r->blend_out_frames = 15.0f;
}

int lo_matrix_rule(const LoMatrixRow *rows, int nrows, int from_sub, int to_sub)
{
    if (from_sub < 0 || from_sub >= nrows)
        return -1;
    const LoMatrixRow *r = &rows[from_sub];
    for (int i = 0; i < r->count; ++i)
        if (r->cells[i].to == to_sub)
            return r->cells[i].rule;
    return -1;
}

static float clampf(float v, float lo, float hi)
{
    return v < lo ? lo : (v > hi ? hi : v);
}

float lo_rule_speed(const LoTransitionRule *r, float vivacity)
{
    float v = clampf(vivacity, 0.0f, 1.0f);
    return r->low_vivacity_speed + (r->high_vivacity_speed - r->low_vivacity_speed) * v;
}

float lo_blend_weight(float frames, float blend_frames)
{
    if (blend_frames <= 0.0f)
        return 1.0f;
    return clampf(frames / blend_frames, 0.0f, 1.0f);
}

float lo_phase_to_frame(float phase, float t0, float frame_count, float base, float end)
{
    return clampf((phase - t0) * (frame_count - 1.0f) + base, base, end);
}

float lo_frames_until_out(float out_position, float t0, float frame_count, float base, float now)
{
    float f = (out_position - t0) * (frame_count - 1.0f) + base - now;
    return f > 0.0f ? f : 0.0f;
}

float lo_cycle_phase(float phase, float cycle_in, float cycle_out)
{
    float len = cycle_out - cycle_in;
    if (len <= 0.0f)
        return phase;
    while (phase > cycle_out)
        phase -= len;
    return phase;
}

float lo_roty_offset(float frame, float start_frame, float end_frame, float in_angle, float out_angle)
{
    if (frame <= start_frame)
        return in_angle;
    if (frame >= end_frame || end_frame <= start_frame)
        return out_angle;
    return in_angle + (out_angle - in_angle) * (frame - start_frame) / (end_frame - start_frame);
}

float lo_play_rate(const LoClipProps *c, float global_coef, int group_allows_coef,
                   float gameplay_coef, float transition_speed)
{
    float r = global_coef * transition_speed;
    if (!c->ignore_speed_coef)
        r *= c->speed_coef;
    if (group_allows_coef)
        r *= gameplay_coef;
    return r;
}

LoVec3 lo_root_step(LoVec3 local, float facing_yaw, int mirrored, float rate)
{
    float x = (mirrored ? -local.x : local.x) * rate;
    float z = local.z * rate;
    /* yaw turns left (+x) for positive angles: world = R(yaw) * local. */
    float s = sinf(-facing_yaw), c = cosf(-facing_yaw);
    LoVec3 w = { x * c - z * s, local.y * rate, x * s + z * c };
    return w;   /* forward (0,0,1) -> (sin yaw, 0, cos yaw) */
}

float lo_override_update(float current, float proposed, float threshold)
{
    return fabsf(proposed - current) > threshold ? proposed : current;
}

int lo_retarget(LoVec3 contact, LoVec3 player, float radius_sq, int anim_is_idle,
                float heading_dot, int angles_ok)
{
    float dx = contact.x - player.x, dz = contact.z - player.z;
    if (dx * dx + dz * dz >= radius_sq || anim_is_idle || !angles_ok)
        return -1;
    return heading_dot > 0.0f ? 8 : 7;
}
