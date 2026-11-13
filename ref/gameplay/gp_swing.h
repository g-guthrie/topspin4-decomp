/*
 * Shared declarations for the clean-room reference of the Top Spin 4
 * stats / swing-window / clip-fit logic (see docs/gameplay/stats-swing-clipfit.md).
 *
 * Nothing here contains game data.  Every tunable is a parameter supplied by
 * the caller; the engine reads them from disc-resident data tables.
 *
 * Compile (portable C11):
 *   cc -std=c11 -Wall -Wextra -Werror -o /tmp/test_swing \
 *      ref/gameplay/test_swing.c ref/gameplay/stats.c \
 *      ref/gameplay/swing_window.c ref/gameplay/clip_fit.c -lm
 */
#ifndef GP_SWING_H
#define GP_SWING_H

#include <stddef.h>
#include <stdint.h>

/* ------------------------------------------------------------------ */
/* Name hashing.  The engine identifies stats, swing types, animation   */
/* markers and graph node kinds by CRC-32 (IEEE, reflected, init/final  */
/* 0xFFFFFFFF) of the ASCII name, e.g. crc32("Volley") == 0x71198650.   */
/* ------------------------------------------------------------------ */
uint32_t gp_crc32(const char *name);

enum {
    GP_ID_VOLLEY = 0x71198650u,   /* crc32("Volley")   [verified]   */
    GP_ID_SMASH = 0x7eb30f90u,    /* crc32("Smash")    [verified]   */
    GP_ID_BASELINE = 0x0f6fb110u, /* crc32("Baseline") [verified]   */
    GP_ID_LEFT = 0xda554856u,     /* crc32("Left")     [verified]   */
    GP_ID_GOOD = 0xccb6e1acu,     /* crc32("Good")     [verified]   */
    GP_ID_MEDIUM = 0xc1df4081u,   /* crc32("Medium")   [verified]   */
    GP_ID_BAD = 0xba667f1bu       /* crc32("Bad")      [verified]   */
};

/* ------------------------------------------------------------------ */
/* A. Player stat block and the data-flow graph runtime.               */
/* ------------------------------------------------------------------ */

/* Float ratings stored in the engine's per-player state, in memory order. */
typedef struct GpPlayerStats {
    float serve;     /* state +0x64c */
    float ret;       /* state +0x650  ("Return") */
    float forehand;  /* state +0x654 */
    float backhand;  /* state +0x658 */
    float volley;    /* state +0x65c */
    float power;     /* state +0x660 */
    float speed;     /* state +0x664 */
    float stamina;   /* state +0x668 */
} GpPlayerStats;

typedef enum GpStroke {
    GP_STROKE_GROUND,
    GP_STROKE_RETURN,
    GP_STROKE_VOLLEY,
    GP_STROKE_SERVE
} GpStroke;

/* Rating that becomes the "current stroke skill" when a swing state is
 * entered.  forehand_side is non-zero when the swing is a forehand. */
float gp_stat_for_stroke(const GpPlayerStats *s, GpStroke stroke, int forehand_side);

/* Returns +1 if forehand is the stronger side by more than eps, -1 if the
 * backhand is, 0 if they are within eps of each other. */
int gp_stronger_side(const GpPlayerStats *s, float eps);

/* Piecewise-linear curve segment: y = y0 + slope * clamp(x - x0, 0, x1 - x0). */
typedef struct GpCurveSeg {
    float x0, x1, y0, slope;
} GpCurveSeg;

typedef struct GpCurve {
    const GpCurveSeg *segs;
    size_t count;
} GpCurve;

float gp_curve_eval(const GpCurve *curve, float x);

/* Data-flow graph.  Registers are floats; nodes run in order. */
typedef enum GpNodeKind {
    GP_NODE_CONST,       /* crc 0x6bbd0182 */
    GP_NODE_SUM,         /* crc 0xdee0059f */
    GP_NODE_PRODUCT,     /* crc 0x9da3605f */
    GP_NODE_MIN,         /* crc 0xdcce2909 */
    GP_NODE_MAX,         /* crc 0xfb754e38 */
    GP_NODE_CURVE,       /* crc 0x993894c6 */
    GP_NODE_SUM_OR_FLAG, /* crc 0x7a741f05 */
    GP_NODE_SUB,         /* crc 0x8196eae3 */
    GP_NODE_DIV,         /* crc 0xb6ea415e */
    GP_NODE_LERP,        /* crc 0x7e683220 */
    GP_NODE_INVLERP      /* crc 0xa68e1dc3 */
} GpNodeKind;

#define GP_NODE_MAX_INPUTS 8

typedef struct GpNode {
    GpNodeKind kind;
    int in[GP_NODE_MAX_INPUTS]; /* register indices */
    int in_count;
    int out;                    /* register index, < 0 = none (curve only) */
    float literal;              /* GP_NODE_CONST */
    const GpCurve *curve;       /* GP_NODE_CURVE */
    float invalid_value;        /* GP_NODE_SUM_OR_FLAG result when an input < 0 */
} GpNode;

typedef struct GpBinding {
    float *var; /* engine variable (input: read before, output: written after) */
    int reg;
} GpBinding;

typedef struct GpGraph {
    float *regs;
    const GpNode *nodes;
    size_t node_count;
    const GpBinding *inputs;
    size_t input_count;
    const GpBinding *outputs;
    size_t output_count;
} GpGraph;

/* copy inputs -> registers, run nodes in order, copy registers -> outputs */
void gp_graph_eval(GpGraph *g);

/* ------------------------------------------------------------------ */
/* B. Swing-selection window.                                          */
/* ------------------------------------------------------------------ */

#define GP_MAX_SAMPLES 128
#define GP_MAX_ROWS 32

/* One sample of the predicted ball track (engine record stride 0x30). */
typedef struct GpBallSample {
    float local_x, local_y, local_z; /* contact point in the player's frame */
    int time_frame;                  /* absolute frame at which the ball is there */
    int bounce_index;                /* bounces so far */
} GpBallSample;

/* Tunables for the window builder; the engine reads them from data. */
typedef struct GpWindowParams {
    float volley_lateral_max;     /* |lateral| limit that makes a "volley zone" sample */
    int volley_max_bounce;        /* bounce_index <= N for the volley zone             */
    float split_height_volley;    /* height at/above which a volley-zone sample is high */
    float split_height_other;     /* same split for ordinary samples                    */
    float smash_band_volley[2];   /* (lo, hi) height band for smash, volley zone        */
    float smash_band_other[2];    /* (lo, hi) height band for smash, ordinary samples   */
    float reach_radius;           /* racket reach removed from the distance             */
    float prep_frames_volley;     /* swing preparation time, volley                     */
    float prep_frames_other;      /* swing preparation time, everything else            */
    float unit_scale;             /* distance/frames -> speed unit conversion           */
    float speed_cap;              /* finite upper clamp of a required speed             */
    float unreachable;            /* stored when the ball cannot be reached at all      */
    float far_default;            /* stored for samples with no usable geometry         */
    float min_time_frames;        /* below this much time the sample is unreachable     */
    uint32_t id_baseline;         /* type id of an ordinary ground stroke               */
    uint32_t id_volley;
    uint32_t id_smash;
    uint32_t id_none;             /* type id stored when no swing applies               */
} GpWindowParams;

typedef struct GpWindow {
    int count;
    float pos[GP_MAX_SAMPLES][4]; /* contact position + 1 spare lane */
    float reach_speed[GP_MAX_SAMPLES];
    uint32_t type_id[GP_MAX_SAMPLES];
    int first_valid, last_valid;
} GpWindow;

typedef struct GpMoveMode {
    int allow_volley;         /* record byte +1: volley candidates may be used */
    int smash_only;           /* record byte +2: candidate is_smash must equal this */
    float speed_limit_other;  /* record float +8  (non-volley candidates) */
    float speed_limit_volley; /* record float +0xc (volley candidates)    */
} GpMoveMode;

typedef struct GpRow {
    int first, last;  /* inclusive candidate index range */
    float min_speed;  /* smallest required speed within the run */
} GpRow;

typedef struct GpSel {
    int row_count;
    GpRow rows[GP_MAX_ROWS];
    float min_speed_all, min_speed_other, min_speed_volley;
    float notation[GP_MAX_SAMPLES]; /* "InputNotation" */
    float score[GP_MAX_SAMPLES];    /* "Selection Score" */
    int valid;
} GpSel;

/* local_dist[i] is the straight-line distance from the player to sample i. */
void gp_window_build(GpWindow *w, const GpBallSample *samples,
                     const float *local_dist, int n, const GpWindowParams *p,
                     int current_frame, float lead_frames);
void gp_sel_extract_rows(GpSel *sel, const GpWindow *w, const GpMoveMode *mode,
                         int hand_ok, uint32_t id_volley, uint32_t id_smash);
/* Returns the best candidate index or -1.  want_other / want_volley are the
 * two filter flags of the engine routine (neither set = accept everything). */
int gp_select_best(const GpSel *sel, const GpWindow *w, int want_other,
                   int want_volley, float floor_score, uint32_t id_volley);

/* ------------------------------------------------------------------ */
/* C. Animation clip fit.                                              */
/* ------------------------------------------------------------------ */

typedef struct GpMarker {
    uint32_t id;    /* crc32 of marker name, e.g. "Preparation", "EventRacket" */
    float time;     /* clip-local time of the marker (frames) */
} GpMarker;

typedef struct GpClip {
    const GpMarker *markers;
    int marker_count;
    float length;   /* frames */
} GpClip;

/* Contact time inside a clip once started at start_frame with the given
 * playback scale (frames of clip per game frame); -1 when no contact marker. */
float gp_clip_contact_frame(const GpClip *c, uint32_t contact_id,
                            float start_frame, float playback_scale);

typedef struct GpFitParams {
    float window_lo, window_hi; /* accepted contact-frame range             */
    float w_timing, w_position, w_height, w_facing; /* weights from data    */
} GpFitParams;

typedef struct GpFitInput {
    float contact_frame;       /* predicted by the clip */
    float target_frame;        /* wanted by the ball track */
    float pos_error;           /* clip contact point vs ball, metres */
    float height_error;
    float facing_error;        /* radians */
} GpFitInput;

/* Weighted sum of absolute errors; returns a negative value when the contact
 * frame is outside [window_lo, window_hi].  See the document: the term set
 * and weight source are NOT verified, this is a scaffold. */
float gp_clip_fit_cost(const GpFitInput *in, const GpFitParams *p);

#endif
