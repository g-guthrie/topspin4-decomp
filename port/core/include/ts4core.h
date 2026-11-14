/*
 * ts4core: portable, deterministic simulation core of the Top Spin 4 browser port.
 *
 * THIS HEADER IS THE API CONTRACT with the web front end (port/web/) and the export tools (tools/port/).
 * It is stable within TS4_API_VERSION: fields are only ever appended, never reordered or resized, and
 * every struct that crosses the WebAssembly boundary is made of 4-byte fields only (little-endian, no
 * padding), so JavaScript can read it with DataView / Float32Array / Uint32Array.
 *
 * Conventions
 *   - Units are the game's gameplay units: centimetres and 60 Hz ticks. World frame: x along the court
 *     (the net plane is x = 0, team 0 defends x < 0, team 1 defends x > 0), y up (0 = ground), z across.
 *     A shot is launched by calling ts4_step() once per 1/60 s. There is no wall-clock input: the core is a
 *     pure function of (data blob, tunable overrides, match config, per-tick inputs).
 *   - No game data in the library. Everything numeric comes from the data blob (docs/port/data-format.md)
 *     or from ts4_set_tunable(). A module whose required data is missing reports TS4_MOD_MISSING_DATA and
 *     the match cannot start (ts4_match_start returns TS4_ERR_MISSING_DATA).
 *   - The core does no allocation. The host gives it one contiguous region (ts4_core_size() bytes); the
 *     whole simulation state lives in that region, so copying it is a save state / rollback snapshot.
 *     The data blob is NOT copied: it must outlive the core and stay at the same address.
 *   - Portable C99, IEEE binary32, no FMA contraction, no libm (a small software libm is part of the core),
 *     so a given (blob, seed, inputs) produces bit-identical results on every platform.
 */
#ifndef TS4CORE_H
#define TS4CORE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TS4_API_VERSION 1u

#if defined(__wasm__)
#define TS4_API __attribute__((visibility("default"), used))
#else
#define TS4_API
#endif

typedef struct Ts4Core Ts4Core; /* opaque */

/* ------------------------------------------------------------------------------------------------ */
/* result codes                                                                                      */
/* ------------------------------------------------------------------------------------------------ */
enum {
    TS4_OK = 0,
    TS4_ERR_ARG = -1,            /* NULL pointer, bad index, bad struct_size */
    TS4_ERR_NO_MEMORY = -2,      /* region too small */
    TS4_ERR_BAD_BLOB = -3,       /* magic, version, bounds or ordering violation in the data blob */
    TS4_ERR_MISSING_DATA = -4,   /* a required section or tunable is absent: see ts4_missing_tunable_*() */
    TS4_ERR_NOT_STARTED = -5,
    TS4_ERR_UNSOLVABLE = -6      /* the ball solver found no flight for the request */
};

/* ------------------------------------------------------------------------------------------------ */
/* library, instance, data                                                                           */
/* ------------------------------------------------------------------------------------------------ */
TS4_API uint32_t ts4_api_version(void);
TS4_API const char *ts4_build_info(void);       /* "ts4core 1 wasm32 soft-libm" etc. */

TS4_API uint32_t ts4_core_size(void);           /* bytes of memory ts4_core_init needs (16-byte aligned) */
TS4_API Ts4Core *ts4_core_init(void *mem, uint32_t mem_size);  /* NULL if mem is NULL / misaligned / too small */

/* Parse and validate the blob (format: docs/data-format.md). Resolves the tunable registry, builds the
 * module status table. May be called again to hot-swap data between matches (not during one). */
TS4_API int32_t ts4_data_load(Ts4Core *c, const uint8_t *blob, uint32_t size);

/* zlib.crc32 of an ASCII string: the key function of every named thing in the blob. */
TS4_API uint32_t ts4_crc32(const char *name);

/* Tunable registry (include/ts4_tunables.def). Overrides win over the blob; they survive ts4_data_load. */
TS4_API uint32_t ts4_tunable_count(void);
TS4_API const char *ts4_tunable_name(uint32_t id);
TS4_API uint32_t ts4_tunable_key(uint32_t id);                     /* crc32 of the name */
TS4_API int32_t ts4_set_tunable(Ts4Core *c, uint32_t id, float value);   /* retuning hook */
TS4_API int32_t ts4_get_tunable(const Ts4Core *c, uint32_t id, float *value);  /* TS4_ERR_MISSING_DATA if absent */
TS4_API uint32_t ts4_missing_tunable_count(const Ts4Core *c);      /* required tunables with no value */
TS4_API uint32_t ts4_missing_tunable_id(const Ts4Core *c, uint32_t i);

enum {
    TS4_MOD_DATA = 0,      /* blob container */
    TS4_MOD_BALL,          /* ball flight, bounce, net (gp4b validated + gp4 draft) */
    TS4_MOD_TEMPLATES,     /* shot templates + request tree */
    TS4_MOD_SHOT,          /* launch solve, error decision, aiming */
    TS4_MOD_GRAPHS,        /* analyser graph evaluator */
    TS4_MOD_RULES,         /* scoring */
    TS4_MOD_REACH,         /* candidate window, reach speed, selection */
    TS4_MOD_MOVE,          /* movement planner + locomotion */
    TS4_MOD_SWING,         /* stats, swing timing */
    TS4_MOD_AI,            /* virtual input */
    TS4_MOD_COUNT
};
enum {
    TS4_STATUS_READY = 0,
    TS4_STATUS_MISSING_DATA = 1,  /* required data absent: module (and match start) refused */
    TS4_STATUS_DEGRADED = 2       /* runs, but an optional input (e.g. a graph role) is absent: fallback in use */
};
TS4_API uint32_t ts4_module_status(const Ts4Core *c, uint32_t module);
TS4_API const char *ts4_module_name(uint32_t module);

/* ------------------------------------------------------------------------------------------------ */
/* analyser graphs (kernels of tools/ts4_analyser.py)                                                 */
/* ------------------------------------------------------------------------------------------------ */
TS4_API uint32_t ts4_graph_count(const Ts4Core *c);
TS4_API uint32_t ts4_graph_hash(const Ts4Core *c, uint32_t index);   /* crc32 of the graph name */
TS4_API int32_t ts4_graph_find(const Ts4Core *c, uint32_t name_hash);  /* index or TS4_ERR_ARG */
TS4_API uint32_t ts4_graph_input_count(const Ts4Core *c, uint32_t index);
TS4_API uint32_t ts4_graph_output_count(const Ts4Core *c, uint32_t index);
/* Evaluate with one float per input port (port order), bit-identical to ts4_analyser.evaluate(). */
TS4_API int32_t ts4_graph_eval(const Ts4Core *c, uint32_t index, const float *in, uint32_t n_in,
                               float *out, uint32_t n_out);

/* ------------------------------------------------------------------------------------------------ */
/* shot templates: probe and trace without a match (retuning UI, tests)                               */
/* ------------------------------------------------------------------------------------------------ */
TS4_API uint32_t ts4_template_count(const Ts4Core *c);
TS4_API uint32_t ts4_template_id(const Ts4Core *c, uint32_t row);    /* row+0x88 unique id */

typedef struct Ts4ShotIn {
    uint32_t struct_size;      /* sizeof(Ts4ShotIn) */
    uint32_t row;              /* template row index */
    float from[3];             /* launch point, cm (racket contact) */
    float to[3];               /* aimed landing point, cm (y ignored, ball bottom lands on the ground) */
    float spin_blend;          /* S+0x774, 0..1 */
    float f4c;                 /* S+0x778, 0..1 */
    uint32_t left_handed;
    uint32_t mode;             /* ball mode hash: In 0xCA68AAEC, Out 0x81A72B79, Net 0xCAA7531F, LetIn 0x8F903DFB */
    uint32_t planned;          /* 1 = template planned (In/Out), 0 = commanded speed (Net/Let) */
    float speed_kmh;           /* used when planned == 0 */
    float aim_height_m;        /* used when planned == 0 */
} Ts4ShotIn;

typedef struct Ts4ShotOut {
    uint32_t struct_size;
    float tau;                 /* flight time of arc 1, s (tick-quantised) */
    uint32_t bounce_tick;      /* first bounce tick */
    float initial_kmh;         /* launch speed, km/h */
    float net_height_m;        /* arc height where it crosses the net plane */
    uint32_t raised;           /* flight time was raised to clear the net */
    uint32_t net_unreachable;
    float launch_vel[3];       /* m/s world axes */
    float arrive_vel[3];
} Ts4ShotOut;

TS4_API int32_t ts4_shot_probe(Ts4Core *c, const Ts4ShotIn *in, Ts4ShotOut *out);
/* Fly the shot for up to max_ticks ticks (until the second bounce or the ball dies). Writes x,y,z in cm per
 * tick (index 0 = launch point) to out_xyz[3 * n]; returns the number of points written (>= 1) or an error. */
TS4_API int32_t ts4_shot_trace(Ts4Core *c, const Ts4ShotIn *in, float *out_xyz, uint32_t max_ticks);

/* ------------------------------------------------------------------------------------------------ */
/* match                                                                                             */
/* ------------------------------------------------------------------------------------------------ */
enum { TS4_STAT_SERVE = 0, TS4_STAT_RETURN, TS4_STAT_FOREHAND, TS4_STAT_BACKHAND, TS4_STAT_VOLLEY,
       TS4_STAT_POWER, TS4_STAT_SPEED, TS4_STAT_STAMINA, TS4_STAT_COUNT };   /* S+0x64C..0x668 order */

typedef struct Ts4PlayerSetup {
    float stats[TS4_STAT_COUNT];   /* raw ratings as stored in PlayerState (0..100 in the game) */
    uint32_t left_handed;
    uint32_t human;                /* 1: driven by ts4_set_input; 0: virtual input from the AI module */
} Ts4PlayerSetup;

typedef struct Ts4MatchConfig {
    uint32_t struct_size;          /* sizeof(Ts4MatchConfig) */
    uint32_t seed;
    int32_t games_per_set;         /* 6 */
    int32_t num_sets;              /* 1, 3 or 5 */
    uint32_t tiebreak_only_sets;
    uint32_t final_set_super_tb;
    uint32_t short_format;         /* 1 game / 1 set / 1 point per game */
    uint32_t single_serve;         /* no second serve */
    int32_t first_server;          /* 0 or 1 */
    uint32_t surface;              /* recorded for the renderer/audio; no effect on ball physics (surfaces.md) */
    Ts4PlayerSetup players[2];
} Ts4MatchConfig;

TS4_API int32_t ts4_match_start(Ts4Core *c, const Ts4MatchConfig *cfg);

enum {
    TS4_BTN_FLAT = 1u << 0,        /* A */
    TS4_BTN_TOPSPIN = 1u << 1,     /* B */
    TS4_BTN_SLICE = 1u << 2,       /* X */
    TS4_BTN_LOB = 1u << 3,         /* Y */
    TS4_BTN_RISK = 1u << 4,        /* RT / LT (modifier; Slice + Risk = drop shot) */
    TS4_BTN_SPRINT = 1u << 5       /* RB */
};
typedef struct Ts4Input {
    float stick_x;                 /* -1..1, +x = toward the opponent's baseline (shooter-relative) */
    float stick_z;                 /* -1..1, +z = player's right when facing the net */
    uint32_t buttons;              /* TS4_BTN_* held this tick */
} Ts4Input;
/* Latch the input used by the next ts4_step(). Ignored for non-human players. */
TS4_API int32_t ts4_set_input(Ts4Core *c, uint32_t player, const Ts4Input *in);

/* Advance exactly one 1/60 s tick. */
TS4_API void ts4_step(Ts4Core *c);

/* Deterministic digest of the whole simulation state (FNV-1a over a canonical byte image). */
TS4_API uint32_t ts4_state_hash(const Ts4Core *c);

/* ------------------------------------------------------------------------------------------------ */
/* events and snapshot                                                                                */
/* ------------------------------------------------------------------------------------------------ */
enum {
    TS4_EV_SERVE = 1,          /* a: server */
    TS4_EV_HIT,                /* a: player, b: template row, c: outcome hash (In/Out/Net/Let); x,y,z: contact */
    TS4_EV_WHIFF,              /* a: player */
    TS4_EV_BOUNCE,             /* a: bounce count, b: 0 = court, x,y,z */
    TS4_EV_NET,                /* a: 1 solid net hit, 2 net cord (let); x,y,z */
    TS4_EV_POINT_END,          /* a: winner (-1 none), b: reason (TS4_REASON_*) */
    TS4_EV_FAULT,
    TS4_EV_DOUBLE_FAULT,
    TS4_EV_LET,
    TS4_EV_GAME,
    TS4_EV_SET,
    TS4_EV_MATCH,              /* a: winner */
    TS4_EV_CHANGE_ENDS
};
enum { TS4_REASON_NONE = 0, TS4_REASON_OUT, TS4_REASON_NET, TS4_REASON_DOUBLE_BOUNCE, TS4_REASON_NO_RETURN,
       TS4_REASON_FAULT, TS4_REASON_LET, TS4_REASON_SERVE_OUT_OF_BOX };
typedef struct Ts4Event {
    uint32_t type;
    uint32_t tick;
    int32_t a, b, c;
    float x, y, z;
} Ts4Event;                    /* 32 bytes */
/* Drain up to max events (oldest first); older events are dropped when the 256-entry ring overflows. */
TS4_API uint32_t ts4_poll_events(Ts4Core *c, Ts4Event *out, uint32_t max);

enum { TS4_PHASE_IDLE = 0, TS4_PHASE_SERVE, TS4_PHASE_RALLY, TS4_PHASE_POINT_END, TS4_PHASE_MATCH_OVER };

typedef struct Ts4BallView {
    float pos[3];                  /* cm */
    float vel[3];                  /* cm/s */
    float spin[3];                 /* spin_a, spin_b, spin_c blend values (drift model) */
    uint32_t mode;                 /* ball mode hash */
    uint32_t bounce_count;
    uint32_t live;                 /* 1 while the ball is in play */
    uint32_t last_hitter;
} Ts4BallView;                     /* 52 bytes */

typedef struct Ts4PlayerView {
    float pos[3];                  /* cm (y = 0) */
    float vel[3];                  /* cm/s */
    float heading;                 /* radians, atan2(dz, dx) of the facing direction */
    uint32_t move_state;           /* planner state (ref/gameplay/movement.h mv_state) */
    uint32_t swing_state;          /* 0 idle, 1 swing in progress, 2 recovery */
    float swing_t;                 /* 0..1 progress to contact while swinging */
    uint32_t template_row;         /* row of the last shot (valid after a hit) */
    uint32_t flags;                /* bit0 server, bit1 left handed, bit2 human */
} Ts4PlayerView;                   /* 48 bytes */

typedef struct Ts4ScoreView {
    int32_t games[2][5];           /* per set */
    int32_t sets_won[2];
    int32_t display[2];            /* 0/15/30/40, -1 = advantage, tiebreak count */
    int32_t cur_set;
    int32_t server;
    int32_t serve_side;            /* 0 deuce / even points, 1 ad */
    int32_t second_serve;
    int32_t tiebreak;
    int32_t match_over;
    int32_t winner;                /* match winner or -1 */
    int32_t ends_swapped;
} Ts4ScoreView;                    /* 22 * 4 = 88 bytes */

typedef struct Ts4Snapshot {
    uint32_t struct_size;
    uint32_t tick;
    uint32_t phase;                /* TS4_PHASE_* */
    uint32_t point_ticks;          /* ticks since the phase started */
    Ts4BallView ball;
    Ts4PlayerView players[2];
    Ts4ScoreView score;
    uint32_t status_flags;         /* bit0: ball prediction valid */
} Ts4Snapshot;

TS4_API const Ts4Snapshot *ts4_snapshot(const Ts4Core *c);
TS4_API uint32_t ts4_snapshot_size(void);

#if defined(__wasm__)
/* wasm only: the host places the core instance and the data blob in linear memory with a bump allocator
 * (16-byte aligned, memory grows on demand). ts4_wasm_reset() frees everything at once. */
TS4_API void *ts4_wasm_alloc(uint32_t n);
TS4_API void ts4_wasm_reset(void);
#endif

/* Test / tool hook: end the current point as the judges would. kind 0 rally, 1 serve, 2 let.
 * Returns the RULES_EV_* bit set of ref/gameplay/rules.h. */
TS4_API uint32_t ts4_debug_end_point(Ts4Core *c, uint32_t kind, int32_t winner);

#ifdef __cplusplus
}
#endif

#endif /* TS4CORE_H */
