/*
 * ts4core: decoded shot-selection and outcome-target rules, copied from the reference C of the gameplay agents
 * (ref/gameplay/shot_select.c, G2b, and ref/gameplay/ball.c, G3) so the core stays freestanding (no stdio, one
 * crc32). The logic is unchanged; constants the reference hard-codes are tunables here (ts4_tunables.def), and
 * the court numbers come from the court.* tunables. Keep in step with the reference when it changes.
 */
#include <math.h>

#include "ts4_internal.h"

#define PI_F 3.14159265f

static float clampf(float x, float lo, float hi) { return x < lo ? lo : (x > hi ? hi : x); }
static float minf_(float a, float b) { return a < b ? a : b; }
static float maxf_(float a, float b) { return a > b ? a : b; }
static float wrap_pi(float a)
{
    while (a > PI_F) a -= 2.0f * PI_F;
    while (a < -PI_F) a += 2.0f * PI_F;
    return a;
}

/* ---- shot_select.c ----------------------------------------------------------------------------------- */
float ts4s_curve16(const float k[4], float x)                     /* fn_881899D8, one key */
{
    float t;
    if (k[1] == k[0]) return x < k[0] ? k[2] : k[3];
    t = clampf((x - k[0]) / (k[1] - k[0]), 0.0f, 1.0f);
    return k[2] + t * (k[3] - k[2]);
}

int ts4s_lt_forced_commit(int lt, float power, float angle, int alt, int mirrored, float pmin, float amax)
{
    float d;
    if (!lt || !(power > pmin)) return 0;
    if (mirrored) angle += PI_F;
    d = wrap_pi(angle - (alt ? 4.712389f : 1.5707964f));
    return fabsf(d) < amax;
}

void ts4s_aim_from_stick(float move_x, float move_y, int mirrored, float *angle, float *depth)
{
    float vx = move_y, vz = -move_x, mag = sqrtf(vx * vx + vz * vz);
    if (!(mag >= 0.0f)) mag = 0.0f;
    *depth = mag > 1.0f ? 1.0f : mag;
    *angle = wrap_pi(atan2f(vx, vz) + (mirrored ? PI_F : 0.0f));
}

float ts4s_serve_power(int release, int toss_start, int toss_len, int released)
{
    float v;
    if (!released || toss_len <= 0) return 1.0f;
    v = (float)(release - toss_start) / (float)toss_len;
    return clampf(v, 0.0f, 1.0f);
}

int ts4s_wood_down(float t[3], const float ref[3], int is_wood)
{
    float dx, dy, dz;
    if (t[0] < 0.0f) t[0] = t[0] < -50.0f ? t[0] : -50.0f;
    else t[0] = t[0] > 50.0f ? t[0] : 50.0f;
    if (!(t[0] < 0.0f) || is_wood) return 0;
    dx = t[0] - ref[0]; dy = t[1] - ref[1]; dz = t[2] - ref[2];
    return dx * dx + dy * dy + dz * dz < 640000.0f;
}

/* ---- ball.c: court bounds and outcome targets (frame: x > 0 is the receiver half) ------------------- */
void ts4s_court_bounds(const Ts4Core *c, int serve, int deuce_side, Ts4Bounds *o)
{
    float tol = 2.0f * TUN(c, BALL_RADIUS_CM), w = TUN(c, COURT_HALF_WIDTH_S_CM);
    if (serve) {
        float centre = 4.0f;   /* pool constant: the service box reaches 4 cm past the centre line (G3) */
        o->xmax = TUN(c, COURT_SERVICE_X_CM);
        o->zmin = deuce_side ? -centre : -w;
        o->zmax = deuce_side ? w : centre;
    } else {
        o->xmax = TUN(c, COURT_HALF_LENGTH_CM);
        o->zmin = -w;
        o->zmax = w;
    }
    o->xmax += tol; o->zmin -= tol; o->zmax += tol;
}

int ts4s_target_out(const float p[3], const Ts4Bounds *bb)
{
    return fabsf(p[0]) > bb->xmax || p[2] > bb->zmax || p[2] < bb->zmin || p[0] < 0.0f;
}

void ts4s_push_out(float p[3], const Ts4Bounds *bb, float m)
{
    float dx = fabsf(p[0]) - bb->xmax;
    float dz = p[2] >= 0.0f ? p[2] - bb->zmax : bb->zmin - p[2];
    if (dx > m || dz > m) return;                                   /* already clearly out */
    if (fabsf(dx) < fabsf(dz)) {
        if (p[0] > 0.0f) p[0] = minf_(maxf_(p[0], bb->xmax + m), 100000.0f);
        else p[0] = minf_(maxf_(p[0], -bb->xmax - m), 100000.0f);   /* original: no push on this side */
    } else {
        if (p[2] > 0.0f) p[2] = minf_(maxf_(p[2], bb->zmax + m), 100000.0f);
        else p[2] = minf_(maxf_(p[2], -100000.0f), bb->zmin - m);
    }
}

uint32_t ts4s_out_class(const Ts4Core *c, const float p[3], const Ts4Bounds *bb)
{
    float w = TUN(c, OUT_GRADE_W), A = TUN(c, OUT_GRADE_A), B = TUN(c, OUT_GRADE_B), C = TUN(c, OUT_GRADE_C);
    if (p[0] < bb->xmax + w && p[2] < bb->zmax + w && p[0] > -A && p[2] > bb->zmin - w) return TS4_HASH_OUT;
    if (p[0] < bb->xmax + B + w && p[2] < bb->zmax + B + w && p[0] > -(A + C) && p[2] > bb->zmin - B - w)
        return TS4_HASH_OUT_FAR;
    return TS4_HASH_OUT_VERY_FAR;
}

void ts4s_target_min_depth(float p[3], float d)
{
    if (p[0] > 0.0f && p[0] < d) p[0] = d;
    else if (p[0] < 0.0f && p[0] > -d) p[0] = -d;
}

void ts4s_in_target(float p[3], const Ts4Bounds *bb, float d)
{
    p[0] = clampf(p[0], d, bb->xmax);
    p[2] = clampf(p[2], bb->zmin, bb->zmax);
    ts4s_target_min_depth(p, d);
}

void ts4s_in_shortfall(float p[3], const float from[3], float s)
{
    float dx = p[0] - from[0], dz = p[2] - from[2], l = sqrtf(dx * dx + dz * dz);
    if (l == 0.0f) return;
    p[0] -= dx / l * s;
    p[2] -= dz / l * s;
}

void ts4s_wood_target(const Ts4Core *c, float out[3], const float from[3], Ts4Rng *rng)
{
    float dx = ts4_rng_range(rng, TUN(c, BALL_DISP_X_LO), TUN(c, BALL_DISP_X_HI));   /* Wood box, hitter relative */
    float dz = ts4_rng_range(rng, TUN(c, BALL_DISP_Z_LO), TUN(c, BALL_DISP_Z_HI));
    if (from[0] < 0.0f) { out[0] = from[0] + dx; out[2] = from[2] + dz; }
    else { out[0] = from[0] - dx; out[2] = from[2] - dz; }
    out[1] = 0.0f;
}

static float cross_y(const float d[3], float wx, float wz) { return d[2] * wx - d[0] * wz; }
static int inside_rect(float x, float z, const Ts4Bounds *bb) { return x < bb->xmax && z < bb->zmax && x > 100.0f && z > bb->zmin; }

void ts4s_reach_flags(const float p[3], const Ts4Bounds *bb, float len_a, float len_b, float ang1_deg, float ang2_deg,
                      int point_end, int *b50, int *b51)
{
    const float D2R = 0.017453292f;
    float R = len_a, Rm = len_b > len_a ? len_b : len_a;
    float R2 = R * R, Rm2 = Rm * Rm, a1 = ang1_deg * D2R, a2 = ang2_deg * D2R;
    float d1[3], d2[3], px = p[0], pz = p[2], dq1, dq2, dq3, dq4;
    int g1, g2, all5;
    d1[0] = sinf(a1); d1[1] = 0.0f; d1[2] = cosf(a1);
    d2[0] = sinf(a2); d2[1] = 0.0f; d2[2] = cosf(a2);
    dq1 = (px - 100.0f) * (px - 100.0f) + (pz - bb->zmax) * (pz - bb->zmax);
    dq2 = (px - 100.0f) * (px - 100.0f) + (pz - bb->zmin) * (pz - bb->zmin);
    dq3 = (px - bb->xmax) * (px - bb->xmax) + (pz - bb->zmin) * (pz - bb->zmin);
    dq4 = (px - bb->xmax) * (px - bb->xmax) + (pz - bb->zmax) * (pz - bb->zmax);
    if (point_end) { *b50 = *b51 = 1; return; }
    g1 = (dq2 > Rm2 && dq1 > Rm2) || cross_y(d1, bb->xmax - px, bb->zmax - pz) > 0.0f ||
         cross_y(d2, bb->xmax - px, bb->zmin - pz) < 0.0f || (dq3 < R2 && dq4 < R2);
    g2 = (dq3 < Rm2 && dq4 < Rm2) && (dq1 > R2 && dq2 > R2) && cross_y(d1, 100.0f - px, bb->zmax - pz) < 0.0f &&
         cross_y(d2, 100.0f - px, bb->zmin - pz) > 0.0f;
    all5 = inside_rect(px + d1[0] * Rm, pz + d1[2] * Rm, bb) && inside_rect(px + d1[0] * R, pz + d1[2] * R, bb) &&
           inside_rect(px + d2[0] * Rm, pz + d2[2] * Rm, bb) && inside_rect(px + d2[0] * R, pz + d2[2] * R, bb) &&
           inside_rect(px + Rm, pz, bb);
    if (all5) { *b50 = 1; *b51 = 0; }
    else if (g2 || !g1) { *b50 = 1; *b51 = 1; }
    else { *b50 = 0; *b51 = 1; }
}

uint32_t ts4s_out_nonforced(const Ts4Core *c, float p[3], const Ts4Bounds *bb, Ts4Rng *rng)
{
    float x0 = p[0], z0 = p[2], best = -1.0f, line[3] = {0.0f, 0.0f, 0.0f}, d[3], l, r;
    float d0 = (bb->zmin - z0) * (bb->zmin - z0), d1 = (bb->zmax - z0) * (bb->zmax - z0), d2 = (bb->xmax - x0) * (bb->xmax - x0);
    float mind = TUN(c, SHOT_MIN_DEPTH_CM);
    if (d0 < d1 && d0 < d2) { best = d0; line[0] = x0; line[2] = bb->zmin; }
    if (d1 < d0 && d1 < d2) { best = d1; line[0] = x0; line[2] = bb->zmax; }
    if (d2 < d1 && d2 < d0) { best = d2; line[0] = bb->xmax; line[2] = z0; }
    if (best < 0.0f) {   /* exact tie: port deviation of the reference (the original reads a stale register) */
        if (d0 <= d1 && d0 <= d2) { best = d0; line[0] = x0; line[2] = bb->zmin; }
        else if (d1 <= d2) { best = d1; line[0] = x0; line[2] = bb->zmax; }
        else { best = d2; line[0] = bb->xmax; line[2] = z0; }
    }
    if (best > TUN(c, OUT_DEMOTE_D2)) {
        p[0] = clampf(p[0], -bb->xmax, bb->xmax);
        p[2] = clampf(p[2], bb->zmin, bb->zmax);
        ts4s_target_min_depth(p, mind);
        return TS4_HASH_IN;
    }
    r = ts4_rng_range(rng, sqrtf(best), TUN(c, OUT_NONFORCED_MAX));
    d[0] = line[0] - x0; d[1] = 0.0f; d[2] = line[2] - z0;
    l = sqrtf(d[0] * d[0] + d[2] * d[2]);
    if (l > 0.0f) { p[0] = x0 + d[0] / l * r; p[2] = z0 + d[2] / l * r; }
    ts4s_push_out(p, bb, TUN(c, SHOT_OUT_MARGIN_CM));
    ts4s_target_min_depth(p, mind);
    return TS4_HASH_OUT;
}
