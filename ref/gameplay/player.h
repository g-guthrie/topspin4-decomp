/*
 * Readable reference for the Top Spin 4 player character: tuning-table
 * evaluators, stat curves, reach speed, candidate typing, movement-mode
 * validity and speeds, racket target and contact window, swing clip timing
 * (time warp, rate solver, busy ticks), hit grade, AI level lookup and the
 * crowd excitement step.  docs/gameplay/player-and-movement.md gives the
 * original addresses and confidence for every function here.
 *
 * No game data: every tunable is a parameter.  The shipped values are written
 * by tools/ts4data/player_data.py to data/gameplay/player.yaml.
 *
 *   cc -std=c11 -Wall -Wextra -Werror -o /tmp/test_player \
 *      ref/gameplay/test_player.c ref/gameplay/player.c -lm && /tmp/test_player
 *
 * Units: centimetres, 60 Hz ticks, m/s.  Positions are (x, y, z) with y up.
 */
#ifndef TS4_PLAYER_H
#define TS4_PLAYER_H

#include <stdint.h>

/* ---------------------------------------------------------------- curves */

/* Curve16 key {x0, x1, y0, y1}: fn_881899D8 (tuning tables in Settings.bin). */
typedef struct { float x0, x1, y0, y1; } PlKey16;
typedef struct { const PlKey16 *keys; int count; } PlCurve16;

/* 2-D table row: a Curve16 over the column value plus a row key (fn_8826D278). */
typedef struct { PlCurve16 curve; float key; } PlRow;
typedef struct { const PlRow *rows; int count; } PlTable2D;

/* Curve20 key {x0, x1, y0, slope, y1} used by the analyser graphs
 * (fn_8817A688).  The game reads slope (+0xC).  The retail data stores 0 there
 * and the end value y1 in +0x10; the load-time fixup fn_8890DFC8 -> fn_88179740
 * sets slope = (y1 - y0) / (x1 - x0) (V, G1, graphs-decoded.md), so the curves
 * are ramps.  PL_CURVE_RAMP is the default (value 0); PL_CURVE_STEP keeps the
 * stored slope (the old "as stored" reading) for comparison only. */
typedef struct { float x0, x1, y0, slope, y1; } PlKey20;
typedef enum { PL_CURVE_RAMP = 0, PL_CURVE_STEP = 1 } PlCurveMode;
#define PL_CURVE_RAMP_Y1 PL_CURVE_RAMP     /* older names */
#define PL_CURVE_AS_STORED PL_CURVE_STEP

float pl_curve16(const PlCurve16 *c, float x);
float pl_table2d(const PlTable2D *t, float row_value, float col_value);
float pl_curve20(const PlKey20 *k, int n, float x, PlCurveMode mode);

/* ---------------------------------------------------------------- stats */

/* The eight float ratings of PlayerState +0x64C..+0x668 (memory order). */
typedef enum {
    PL_SERVE, PL_RETURN, PL_FOREHAND, PL_BACKHAND, PL_VOLLEY, PL_POWER, PL_SPEED, PL_STAMINA, PL_STAT_COUNT
} PlStat;

typedef enum { PL_STROKE_GROUND, PL_STROKE_RETURN, PL_STROKE_SERVE, PL_STROKE_VOLLEY, PL_STROKE_FH_ONLY } PlStroke;

/* fn_88699300: rating copied to S+0x74C when a swing state is entered.
 * forehand = ((handedness == Left) != committed side flag S+0xBD1). */
float pl_stroke_skill(const float stats[PL_STAT_COUNT], PlStroke stroke, int forehand);

/* DefaultAttributes (graph 0x8C9B26E0): one independent curve per rating,
 * rating (about 30..100) -> Profile value. */
typedef struct { const PlKey20 *keys; int count; } PlStatCurve;
void pl_profile_from_ratings(const float ratings[PL_STAT_COUNT], const PlStatCurve curves[PL_STAT_COUNT],
                             PlCurveMode mode, float profile_out[PL_STAT_COUNT]);

/* fn_8865B3B0: prefer forehand (1), backhand (-1) or none (0), from the two
 * ratings and the per-side use counters. */
int pl_side_preference(float fh, float bh, int fh_uses, int bh_uses, float threshold);

/* ---------------------------------------------------------------- reach */

typedef enum { PL_BASELINE = 0x0F6FB110u, PL_VOLLEY_T = 0x71198650u, PL_SMASH = 0x7EB30F90u,
               PL_UNREACHABLE = 0xDDA489B8u } PlSampleType;

/* PlayerTuning +0xE0..+0xF4 height bands, +0x178 |x| limit, lookahead. */
typedef struct {
    float low_out, low_in;            /* +0xE0, +0xE4 */
    float smash_lo_in, smash_hi_in;   /* +0xE8, +0xEC */
    float smash_lo_out, smash_hi_out; /* +0xF0, +0xF4 */
    float volley_zone_abs_x;          /* +0x178 */
} PlTypeCfg;

/* fn_8869B178 per-sample candidate type. */
PlSampleType pl_classify_sample(const PlTypeCfg *c, float x, float y, int bounces, int index, int lookahead);

typedef struct {
    float reach_radius, reach_radius_alt;   /* +0x194, +0x1A0 */
    float volley_box_x, volley_box_z;       /* +0x198, +0x19C */
    float prep, prep_volley, prep_alt;      /* +0x1A4, +0x1A8, +0x1AC */
} PlReachCfg;

/* fn_8868B4E8 per-sample required speed (m/s).  d = sample - player (cm),
 * run_cm = path length after the turn (caller: |sample-p| + |p-player|),
 * turn_ticks from the preparation table, busy = clip busy ticks. */
float pl_reach_speed(const PlReachCfg *c, PlSampleType type, int alt, int side_faces_ball,
                     float dx, float dz, float run_cm, float ticks_to_sample, float turn_ticks, float busy);

/* ---------------------------------------------------------------- movement */

enum { PL_MODE_RUSH = 20, PL_MODE_JOGJOG = 21, PL_MODE_JOG = 22, PL_MODE_DEFAULT = 5 };

typedef struct {               /* PlayerTuning +0x270 / +0x284 / +0x298 */
    PlTable2D validity;        /* rows: distance (cm), column: slack ticks */
    float f0c;
    float min_distance;        /* +0x10 */
} PlModeCfg;

/* fn_886887C0: slack = ticks_to_contact - prep(table) - lead; result = table(distance, slack). */
float pl_mode_validity(const PlTable2D *t, float distance, float ticks_to_contact, float prep_ticks, float lead_ticks);

/* fn_88688948: valid iff distance > min_distance and validity >= 0.5. */
int pl_mode_valid(const PlModeCfg *m, float distance, float ticks_to_contact, float prep_ticks, float lead_ticks);

/* fn_88699FC0 (speed-regime part): Rush (only if rush_value > rush_guard),
 * then JogJogPrepared, then JogPrepared; else 5. */
int pl_select_regime(const PlModeCfg *rush, const PlModeCfg *jogjog, const PlModeCfg *jog,
                     float rush_value, float rush_guard,
                     float distance, float ticks_to_contact, float prep_ticks, float lead_ticks);

/* fn_88688678: jog speed ramp.  Re-initialised every `period` ticks after the
 * plan commit (step = table(distance, slack)); on the other ticks the speed
 * override drops by step.  Returns the override written to S+0xDE8. */
typedef struct { float value, step; int initialised; } PlJogRamp;
float pl_jog_ramp_tick(PlJogRamp *r, int ticks_since_commit, int period,
                       const PlTable2D *step_table, float distance, float slack);

/* ---------------------------------------------------------------- swing target */

/* fn_886A26E0: lateral racket offset with left-hand mirroring. */
float pl_racket_lateral(float table_a, float table_b, int left_handed, int side);

/* fn_886A26E0: allowed contact window, ticks from now. */
void pl_contact_window(float sample_tick, int now, int alt, const float lo_hi_alt[2], const float lo_hi[2],
                       float *lo, float *hi);

/* ---------------------------------------------------------------- clip timing */

typedef struct { float t0, base, end; } PlLayer;    /* layer +0x14, +0x24, +0x28 */

/* fn_886D1408: warped clip time. */
float pl_time_warp(const PlLayer *l, float ratio, float t);
/* fn_886CD3C8: ticks the current 2-segment clip still blocks the swing. */
float pl_anim_busy(const PlLayer *l, float ratio, float seg1_start, float now);
/* fn_886C72E0: playback rate so the event lands on target_frame. */
float pl_rate_to_target(float event_time, float clip_now, int target_frame, int now, float prev_rate, float decay);
/* EventRacket (or Preparation) normalised phase -> frame inside the clip. */
float pl_contact_frame(float phase, float clip_frames);

/* ---------------------------------------------------------------- grades, AI, crowd */

typedef enum { PL_GRADE_BAD = 0xBA667F1Bu, PL_GRADE_MEDIUM = 0xC1DF4081u, PL_GRADE_GOOD = 0xCCB6E1ACu } PlGrade;
/* fn_886A2E48: S+0x3A0 (2-level) and S+0x3A4 (3-level) from the grade graph output. */
void pl_grades(float out, PlGrade *two, PlGrade *three);

/* fn_886A0EC8: AI record lookup in cfg+0xF0 (group by style key, record by
 * level key; falls back to the first record of the group, and to group 0). */
typedef struct { uint32_t level; float skill_speed_limit; uint32_t graphs[6]; } PlAiRecord;
typedef struct { uint32_t style; const PlAiRecord *recs; int count; } PlAiGroup;
const PlAiRecord *pl_ai_lookup(const PlAiGroup *g, int ngroups, uint32_t style, uint32_t level);

/* fn_8868EA30: excitement update per rally. */
float pl_excitement_step(float level, float events, float gain, float cap);

uint32_t pl_crc32(const char *s);

#endif
