/*
 * Reference implementation of the Top Spin 4 shot aim point (where the stick sends the ball).
 * Spec: docs/gameplay/aiming.md.  Code: fn_886935A0 (selector vtable slot 4, called by the
 * shot planner fn_886AE528 +0x4D8), fn_886706C8, fn_88693040, fn_8867D350, fn_88661188,
 * fn_8867D150, fn_88660F70.  No game data is compiled in: the AimingConfig tables come from
 * data/gameplay/aim_tables.txt (tools/ts4data/aim_tables.py).
 *
 * Units: cm, receiver's half x > 0 (net plane x = 0), z lateral.  The hitter's local
 * position has x < 0 on its own half.
 *
 * Compile (portable C11):
 *   cc -std=c11 -Wall -Wextra -Werror ref/gameplay/test_aim.c ref/gameplay/aim.c -lm -o /tmp/ta
 */
#ifndef TS4_AIM_H
#define TS4_AIM_H

#include <stdint.h>

typedef struct { float x, z; } Ts4Pt;

/* One aim quad: c0 short/z-, c1 short/z+, c2 deep/z-, c3 deep/z+. */
typedef struct { Ts4Pt c[4]; } Ts4Quad;

/* AimingConfig zone: AimingQuad list (quads at QuadEfficiency 0, 0.5, 1, 2) and the centre. */
typedef struct {
    Ts4Pt centre;
    Ts4Quad quad[4];
} Ts4AimZone;

/* AimingConfig (Settings.bin cfg+0x108, 0xA0 bytes). */
typedef struct {
    uint32_t id;                 /* +0x80 template family / key name crc32 */
    float volley_distance;       /* +0x84 (300 cm) */
    float baseline_distance;     /* +0x88 (1300 cm, 1200 for FlatRisky) */
    float center_distance;       /* +0x8C (0) */
    float side_distance;         /* +0x90 (350, 500 or 550 cm) */
    Ts4AimZone zone[4];          /* VolleyCenter, VolleySide, BaselineCenter, BaselineSide */
} Ts4AimConfig;

/* fn_886706C8: stick -> QuadAimingState (S+0xD44) and DirectionSelected (S+0xDAD).
 * far_side = the hitter's court tag is 0xA2EDA1E7: both axes are negated. */
int ts4_aim_quad_state(float stick_x, float stick_y, int far_side, float *aim_x, float *aim_y);

/* fn_8867D350: zone quad at efficiency m; widen = doubles alley (0, or 137 cm). */
void ts4_aim_zone_quad(const Ts4AimZone *zone, float m, float widen, Ts4Quad *out);

/* fn_88693040: blend the four zones by the hitter position, mirror for z >= 0 (or the serve
 * court flag).  Returns the quad and its centre. */
void ts4_aim_config_quad(const Ts4AimConfig *cfg, float pos_x, float pos_z, float m, int mirror,
                         float widen, Ts4Quad *quad, Ts4Pt *centre);

/* fn_8867D150: the point of the quad boundary in the stick direction (magnitude ignored). */
Ts4Pt ts4_aim_quad_point(const Ts4Quad *quad, float aim_x, float aim_y);

/* fn_886935A0: the shot target before the outcome roll. */
Ts4Pt ts4_aim_target(const Ts4AimConfig *cfg, float pos_x, float pos_z, float efficiency,
                     float aim_x, float aim_y, int selected, int mirror, float widen);

/* fn_88693040 mirror flag: serving -> the ad-court flag; else the hitter stands at z >= 0. */
int ts4_aim_mirror(int serving, int ad_court, float pos_z);

/* Load data/gameplay/aim_tables.txt; returns the number of configs read (<= max). */
int ts4_aim_load(const char *path, Ts4AimConfig *out, int max);

#endif
