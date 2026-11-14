#ifndef GP4B_TYPES_H
#define GP4B_TYPES_H
/*
 * GP4B: ball model types (shot templates, solver result, ball state view).  Extends gp4_types.h (GP4) and gp3_types.h (GP3).
 * Swing_DLL.xex sha256 dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44.
 * Every offset was read from machine code and is exercised by drafts/gp4b_ball_model.c; evidence in work/gameplay-notes/gp4b.md.
 */
#include <stddef.h>
#include <stdint.h>

#include "gp4_types.h"

/* ---- shot template row (table at stepper+0x3C; ball+0x360 is the BYTE offset of the row inside the table) ----
 * All fields big-endian; every "rel" is a signed 32-bit offset relative to the address of the field that holds it.
 * Let tpl = row + 0x18 (= ball+0x24).  Offsets below are relative to tpl:
 *   +0x00 node0 {i32 rel, u32 type, u32 kind}  rel -> curve/table/const, kind = SOLVER kind hash (GP4B_KIND_*)
 *   +0x0C node1 {i32 rel, u32 type, u32 kind}  second curve, kind = SECONDARY kind hash (GP4B_KIND_* or GP4B_KIND_APEX)
 *   +0x18 / +0x24 / +0x30  {i32 rel, ...} (12 bytes each) -> spin element pairs A (spin_a), B (spin_c), C (spin_b);
 *         a pair is {i32 rel_lo, u32 type_lo, i32 rel_hi, u32 type_hi} (type GP4B_NODE_CURVE20 -> curve of the launch height, else float)
 *   +0x3C f32 T (= row+0x54)         drag scale: k = T / a4
 *   +0x40 / +0x4C / +0x58 / +0x64    curve16 headers {i32 first_key_rel, i32 count, u32 ?} for the bounce response
 *                                    (speed loss(spin_a), spin decay(spin_a), outgoing elevation(theta), yaw kick(spin_b))
 * node types: GP4B_NODE_TABLE2D 0x7A330099 (fn_8826D278), GP4B_NODE_CURVE20 0xF9F12A60 (fn_8817A688), GP4B_NODE_CONST 0x33799CCE.
 */
#define GP4B_NODE_TABLE2D 0x7A330099u
#define GP4B_NODE_CURVE20 0xF9F12A60u
#define GP4B_NODE_CONST   0x33799CCEu
/* solver / secondary kind hashes: zlib.crc32 of the names in the comments (found by dictionary search, each verified) */
#define GP4B_KIND_DROP_TIME     0x5D90675Bu /* crc32("DropTime"):     tau comes from the template curve (primary) / tau_b = tau_a + curve (secondary) */
#define GP4B_KIND_AVERAGE_SPEED 0x2DB3EB6Fu /* crc32("AverageSpeed"):  metric function is a stub that returns 0 in this build -> degenerate (tau -> ~0.1 s) */
#define GP4B_KIND_BOUNCE_SPEED  0x50B89452u /* crc32("BounceSpeed"):   metric = speed at the first bounce, |v(tau)|^2 (fn_888AAA70) */
#define GP4B_KIND_INITIAL_SPEED 0xC1965E5Cu /* crc32("InitialSpeed"):  metric = speed at launch, |v(0)|^2 (fn_888AAB98) */
#define GP4B_KIND_APOGEE        0x879BA860u /* crc32("Apogee"):        secondary only: metric = apex height (ts4_bm_ball_apex_height_888AA968) */

/* ------------------------------------------------------------------------------------------------------------- */
/* ball state (only the part the model touches; offsets are the original ones, asserted below)                    */
/* ------------------------------------------------------------------------------------------------------------- */
typedef struct Gp4bSolve {            /* 0x2C bytes; lives at ball+0x380 (result A) and ball+0x3AC (result B) */
    float tau;                         /* +0x00 solved flight time, before the template blend */
    uint8_t raised; uint8_t pad05[3];  /* +0x04 1 = tau was raised so that the arc clears the net */
    float tau_raised;                  /* +0x08 flight time after the net search (= tau when !raised) */
    float pad0c;
    float metric_kmh;                  /* +0x10 metric speed of the kind routine (km/h), 0 for the metric-less kind */
    float tau_min;                     /* +0x14 flight time of the slowest possible shot (minimum initial speed), bisection result */
    uint8_t has_min;                   /* +0x18 1 = the initial speed has a minimum inside (0.1 s, 5.1 s) */
    uint8_t net_unreachable;           /* +0x19 1 = even tau_min + 5 s does not clear the net */
    uint8_t pad1a[2];
    float tau_final;                   /* +0x1C B.tau after the template stage */
    float initial_kmh;                 /* +0x20 INITIAL (launch) speed (km/h) at tau_final: this is what the commanded speed (+0x370) means */
    uint8_t probe;                     /* +0x24 set to 1 by the probe entry before solving */
    uint8_t pad25[3];
    float net_height;                  /* +0x28 height (m) of the arc where it crosses the net plane x = 0 */
} Gp4bSolve;

typedef struct Gp4bBall {
    float tau;                  /* 0x000 flight time of arc 1 (s) */
    uint32_t bounce_tick;       /* 0x004 first-bounce tick = (int)(tau * 60) quantised */
    float T;                    /* 0x008 template row +0x54 (drag scale) */
    float blend_c0c;            /* 0x00C = +0x430 (command f4C) */
    float blend_c10;            /* 0x010 = +0x364 (spin blend) */
    int32_t bounce_count;       /* 0x014 */
    int32_t tick;               /* 0x018 */
    int32_t tick_prev;          /* 0x01C */
    int32_t launch_frame;       /* 0x020 */
    uint32_t tpl_ptr;           /* 0x024 console pointer (unused here: the template is passed explicitly) */
    int32_t hold_ticks;         /* 0x028 */
    uint32_t mode;              /* 0x02C */
    uint8_t flag30, flag31, flag32, flag33, flag34, pad35[11];
    float pos[4];               /* 0x040 */
    float pos50[4];             /* 0x050 */
    float prev[4];              /* 0x060 */
    float origin[4];            /* 0x070 */
    float A[4];                 /* 0x080 drift vector */
    float spin_a, spin_b, spin_c, pad9c; /* 0x090 */
    float hold_delta[4];        /* 0x0A0 */
    int32_t event_frame[8][2];  /* 0x0B0 (+0xC8 = landing frame, +0xD0 = dead frame) */
    uint8_t padf0[16];          /* 0x0F0 */
    float P0[4];                /* 0x100 */
    float P1[4];                /* 0x110 */
    float v120x, net_height_cm, v120z, v120w; /* 0x120 (+0x124 = net height in cm) */
    float arc2_pos[4];          /* 0x130 */
    float arc2_vel[4];          /* 0x140 */
    float inv_T, inv_a4, k, g_a4;             /* 0x150 */
    float inv_T2, a4_sq, T_sq;                /* 0x160 */
    float p0x_T, p1x_T, p0y_T, p0z_T, p1z_T; /* 0x16C */
    float E, inv_E_m1;                        /* 0x180 */
    float tauA[3];                            /* 0x188 */
    float g_a4_tau;                           /* 0x194 */
    uint8_t pad198[0x340 - 0x198];
    float cmd_from[4];          /* 0x340 */
    float cmd_to[4];            /* 0x350 */
    uint32_t tpl_offset;        /* 0x360 BYTE offset of the shot-template row inside the table (not an index) */
    float blend;                /* 0x364 spin blend 0..1 (command f50) */
    uint8_t sidespin_neg;       /* 0x368 */
    uint8_t planned;            /* 0x369 1 = template-planned shot (net clearance by net height); 0 = commanded-speed probe */
    uint8_t pad36a[2];
    float aim_height;           /* 0x36C wanted net-crossing height (m) when !planned */
    float speed_kmh;            /* 0x370 commanded arrival speed (km/h) when !planned */
    uint8_t pad374[0x380 - 0x374];
    Gp4bSolve res_a;            /* 0x380 */
    Gp4bSolve res_b;            /* 0x3AC */
    uint8_t pad3d8[0x430 - 0x3D8];
    float shot_f430;            /* 0x430 */
    uint32_t shot_id;           /* 0x434 */
    uint8_t pad438[4];
    uint8_t new_shot;           /* 0x43C */
    uint8_t pad43d[0x4D0 - 0x43D];
    float radius_cm;            /* 0x4D0 */
    float a4;                   /* 0x4D4 */
    float g;                    /* 0x4D8 */
    uint32_t max_bounces;       /* 0x4DC */
    uint8_t frozen, no_sidespin; uint8_t pad4e2[0x4F0 - 0x4E2]; /* 0x4E0, 0x4E1 */
    float vel[4];               /* 0x4F0 (pos - prev) * 60, written by every step */
    float v_launch[4];          /* 0x500 */
    float v_arrive[4];          /* 0x510 */
    float speed; uint8_t pad524[0x530 - 0x524]; /* 0x520 */
    uint8_t enabled;            /* 0x530 */
    uint8_t pad531[0x540 - 0x531];
} Gp4bBall;

_Static_assert(offsetof(Gp4bBall, pos) == 0x40 && offsetof(Gp4bBall, A) == 0x80, "layout");
_Static_assert(offsetof(Gp4bBall, P0) == 0x100 && offsetof(Gp4bBall, net_height_cm) == 0x124, "layout");
_Static_assert(offsetof(Gp4bBall, arc2_vel) == 0x140 && offsetof(Gp4bBall, inv_T) == 0x150, "layout");
_Static_assert(offsetof(Gp4bBall, g_a4_tau) == 0x194 && offsetof(Gp4bBall, cmd_from) == 0x340, "layout");
_Static_assert(offsetof(Gp4bBall, blend) == 0x364 && offsetof(Gp4bBall, speed_kmh) == 0x370, "layout");
_Static_assert(offsetof(Gp4bBall, res_a) == 0x380 && offsetof(Gp4bBall, res_b) == 0x3AC, "layout");
_Static_assert(offsetof(Gp4bBall, res_b.initial_kmh) == 0x3CC && offsetof(Gp4bBall, shot_f430) == 0x430, "layout");
_Static_assert(offsetof(Gp4bBall, radius_cm) == 0x4D0 && offsetof(Gp4bBall, max_bounces) == 0x4DC, "layout");
_Static_assert(offsetof(Gp4bBall, vel) == 0x4F0 && offsetof(Gp4bBall, v_arrive) == 0x510 && offsetof(Gp4bBall, enabled) == 0x530, "layout");
_Static_assert(sizeof(Gp4bBall) == 0x540 && sizeof(Gp4bSolve) == 0x2C, "layout");


#endif /* GP4B_TYPES_H */
