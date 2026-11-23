/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex) shared gameplay types: ball.h
 *
 * Conventions: docs/agents/types.md. Evidence tags in the field comments:
 *   V <addr..>  the offset and width are used by byte-matched functions at these addresses (config/54540859/match.json).
 *               A trailing `~` means the function was attributed to this class by its access pattern (hub signature),
 *               not by a documented name: treat the class attribution as likely, the offset itself as proven.
 *   U <source>  unverified: read from machine code or data by an earlier analysis, no byte-matched function uses it yet.
 * Pointer targets and field names are interpretation; only offset + width are proven by a V tag.
 * First pass generated from the matched sources by a one-off miner (2026-11-23); maintained by hand since.
 */
#ifndef TS4_BALL_H
#define TS4_BALL_H

#include "base.h"
#include "math.h"
#include "containers.h"
#include "match.h"
#include "player.h"
#include "planner.h"

/* Predicted ball sample (0x30 bytes). gp2: Gp2BallSample; rt1: Rt1BallSample. */
typedef struct Ts4BallSample {
    Ts4Vec4 pos;                                 /* +0x000 U gp2_types.h (world position, cm) */
    char pad_0010[0x14];
    int tick;                                    /* +0x024 V 8866BD00 */
    int bounce_count;                            /* +0x028 U gp2_types.h */
    char pad_002C[0x4];
} Ts4BallSample;
TS4_ASSERT_OFFSET(Ts4BallSample, pos, 0x0);
TS4_ASSERT_OFFSET(Ts4BallSample, tick, 0x24);
TS4_ASSERT_OFFSET(Ts4BallSample, bounce_count, 0x28);
TS4_ASSERT_SIZE(Ts4BallSample, 0x30);

/* Ball prediction (BallSys+0x24, BallLink+0x88). gp2: Gp2BallPrediction. */
typedef struct Ts4BallPrediction {
    char pad_0000[0x5A0];
    struct Ts4BallSample *samples_begin;         /* +0x5A0 V 8865A3E8 8865A410 8866BD00 8869FCF0 */
    struct Ts4BallSample *samples_end;           /* +0x5A4 V 8865A3E8 8865A410 8869FCF0 */
    char pad_05A8[0x14];
    unsigned int first_sample;                   /* +0x5BC V 8869FCF0 */
} Ts4BallPrediction;
TS4_ASSERT_OFFSET(Ts4BallPrediction, samples_begin, 0x5A0);
TS4_ASSERT_OFFSET(Ts4BallPrediction, samples_end, 0x5A4);
TS4_ASSERT_OFFSET(Ts4BallPrediction, first_sample, 0x5BC);

/* Ball system (Match+0x5C). q5: Q5BallSys. */
typedef struct Ts4BallSys {
    char pad_0000[0x20];
    void *f_020;                                 /* +0x020 V 8866BEE0~ 886782D0~ 886783B0~ 8869FCF0 +1 */
    struct Ts4BallPrediction *prediction;        /* +0x024 V 8866BD00 8869FCF0 */
    int f_028;                                   /* +0x028 V 886624C8~ */
} Ts4BallSys;
TS4_ASSERT_OFFSET(Ts4BallSys, f_020, 0x20);
TS4_ASSERT_OFFSET(Ts4BallSys, prediction, 0x24);
TS4_ASSERT_OFFSET(Ts4BallSys, f_028, 0x28);

/* Per-player ball link (Player+0xB4). q5: Q5Shot; rt1: Rt1BallLink. */
typedef struct Ts4BallLink {
    char pad_0000[0x88];
    struct Ts4BallPrediction *prediction;        /* +0x088 V 8866BD00 */
} Ts4BallLink;
TS4_ASSERT_OFFSET(Ts4BallLink, prediction, 0x88);

/* Cached closed-form constants of the flight model: a view of Ball+0x150 (0x48 bytes). bm: ts4_bm_arc.
 * Every field is read by the byte-matched ts4_bm_ball_arc1_position_888AB558 through this view. */
typedef struct Ts4BallArc {
    float inv_T, inv_a4, k, g_a4;                /* +0x00 (Ball+0x150) V 888AB558 888AB220 */
    float inv_T2, a4_sq, T_sq;                   /* +0x10 U bm_ball.h */
    float p0x_T, p1x_T, p0y_T, p0z_T, p1z_T;     /* +0x1C V 888AB558 */
    float E, inv_E_m1;                           /* +0x30 V 888AB558 888AB220 */
    float tauA_x, tauA_y, tauA_z;                /* +0x38 V 888AB558 */
    float g_a4_tau;                              /* +0x44 V 888AB558 */
} Ts4BallArc;
TS4_ASSERT_OFFSET(Ts4BallArc, p0x_T, 0x1C);
TS4_ASSERT_OFFSET(Ts4BallArc, g_a4_tau, 0x44);
TS4_ASSERT_SIZE(Ts4BallArc, 0x48);

/* Ball flight state (closed-form model, docs/gameplay/gp4b.md). bm: ts4_bm_ball; gp3: Gp3BallState; rt1: Rt1Ball. */
typedef struct Ts4Ball {
    float tau;                                   /* +0x000 V 888AAA70 888AAB98 888AAE00 888AB220 */
    unsigned int bounce_tick;                    /* +0x004 U bm_ball.h */
    float T;                                     /* +0x008 V 888AA968 888AAA70 888AAB98 888AAEA8 +2 */
    char pad_000C[0x8];
    int bounce_count;                            /* +0x014 U bm_ball.h / gp3_types.h */
    int tick;                                    /* +0x018 V 888AB558 888AD1C8 */
    int tick_prev;                               /* +0x01C V 888AB558 888AD1C8 */
    char pad_0020[0x4];
    void *tpl;                                   /* +0x024 V 888AC688 888AD0E8 also read as unsigned int (888AC688) */
    char pad_0028[0x4];
    unsigned int mode;                           /* +0x02C U gp3_types.h (ball mode hash) */
    char pad_0030[0x10];
    Ts4Vec4 pos;                                 /* +0x040 V 888AB558 888AD1C8 */
    char pad_0050[0x10];
    Ts4Vec4 prev;                                /* +0x060 U bm_ball.h */
    Ts4Vec4 origin;                              /* +0x070 U bm_ball.h */
    Ts4Vec4 A;                                   /* +0x080 V 888AA968 888AAA70 888AAB98 888AAE00 +3 */
    char pad_0090[0x70];
    Ts4Vec4 P0;                                  /* +0x100 V 888AA968 888AAA70 888AAB98 888AAEA8 +1 */
    Ts4Vec4 P1;                                  /* +0x110 V 888AAA70 888AAB98 888AAEA8 888AB220 */
    char pad_0120[0x10];
    Ts4Vec4 arc2_pos;                            /* +0x130 V 888AD1C8 */
    Ts4Vec4 arc2_vel;                            /* +0x140 V 888AD1C8 */
    float inv_T;                                 /* +0x150 V 888AA968 888AAA70 888AAB98 888AB220 +2 */
    float inv_a4;                                /* +0x154 V 888AAA70 888AAB98 888AB220 */
    float f_158;                                 /* +0x158 V 888AAB98 888AAE00 */
    float g_a4;                                  /* +0x15C V 888AAA70 888AAB98 888AAE00 888AB220 */
    char pad_0160[0x24];
    float inv_E_m1;                              /* +0x184 V 888AB220 */
    char pad_0188[0x2B4];
    unsigned char new_shot;                      /* +0x43C U bm_ball.h */
    char pad_043D[0x73];
    Ts4Vec4 net_cord;                            /* +0x4B0 U bm_ball.h ts4_bm_phys */
    char pad_04C0[0x10];
    float radius_cm;                             /* +0x4D0 U bm_ball.h */
    float a4;                                    /* +0x4D4 V 888AA968 888AAEA8 888AD1C8 */
    float g;                                     /* +0x4D8 V 888AA968 888AAEA8 888AD1C8 */
    char pad_04DC[0x4];
    unsigned char frozen;                        /* +0x4E0 U bm_ball.h */
    char pad_04E1[0x4F];
    unsigned char enabled;                       /* +0x530 U bm_ball.h */
} Ts4Ball;
TS4_ASSERT_OFFSET(Ts4Ball, tau, 0x0);
TS4_ASSERT_OFFSET(Ts4Ball, bounce_tick, 0x4);
TS4_ASSERT_OFFSET(Ts4Ball, T, 0x8);
TS4_ASSERT_OFFSET(Ts4Ball, bounce_count, 0x14);
TS4_ASSERT_OFFSET(Ts4Ball, tick, 0x18);
TS4_ASSERT_OFFSET(Ts4Ball, tick_prev, 0x1C);
TS4_ASSERT_OFFSET(Ts4Ball, tpl, 0x24);
TS4_ASSERT_OFFSET(Ts4Ball, mode, 0x2C);
TS4_ASSERT_OFFSET(Ts4Ball, pos, 0x40);
TS4_ASSERT_OFFSET(Ts4Ball, prev, 0x60);
TS4_ASSERT_OFFSET(Ts4Ball, origin, 0x70);
TS4_ASSERT_OFFSET(Ts4Ball, A, 0x80);
TS4_ASSERT_OFFSET(Ts4Ball, P0, 0x100);
TS4_ASSERT_OFFSET(Ts4Ball, P1, 0x110);
TS4_ASSERT_OFFSET(Ts4Ball, arc2_pos, 0x130);
TS4_ASSERT_OFFSET(Ts4Ball, arc2_vel, 0x140);
TS4_ASSERT_OFFSET(Ts4Ball, inv_T, 0x150);
TS4_ASSERT_OFFSET(Ts4Ball, inv_a4, 0x154);
TS4_ASSERT_OFFSET(Ts4Ball, f_158, 0x158);
TS4_ASSERT_OFFSET(Ts4Ball, g_a4, 0x15C);
TS4_ASSERT_OFFSET(Ts4Ball, inv_E_m1, 0x184);
TS4_ASSERT_OFFSET(Ts4Ball, new_shot, 0x43C);
TS4_ASSERT_OFFSET(Ts4Ball, net_cord, 0x4B0);
TS4_ASSERT_OFFSET(Ts4Ball, radius_cm, 0x4D0);
TS4_ASSERT_OFFSET(Ts4Ball, a4, 0x4D4);
TS4_ASSERT_OFFSET(Ts4Ball, g, 0x4D8);
TS4_ASSERT_OFFSET(Ts4Ball, frozen, 0x4E0);
TS4_ASSERT_OFFSET(Ts4Ball, enabled, 0x530);

/* ---- byte-matched functions (current symbol names, config/54540859/symbols.txt). Private struct pointers of the
 * matched source that have no shared type yet are `void *`. ---- */
TS4_EXTERN_C_BEGIN
void *ts4_last_record_8865A3E8(struct Ts4BallPrediction *o);                                                   /* 8865A3E8 */
void *ts4_first_record_8865A410(struct Ts4BallPrediction *o);                                                  /* 8865A410 */
int ts4_prediction_ticks_until_x_886600E0(struct Ts4BallPrediction *pred, float x);                            /* 886600E0 */
void ts4_call_with_range_endpoints_8869FCF0(struct Ts4BallSys *self, struct Ts4Body *arg);                     /* 8869FCF0 */
float ts4_bm_ball_apex_height_888AA968(const struct Ts4Ball *b, float tt);                                     /* 888AA968 */
float ts4_bm_ball_bounce_speed_sq_888AAA70(const struct Ts4Ball *b);                                           /* 888AAA70 */
float ts4_bm_ball_launch_speed_sq_888AAB98(const struct Ts4Ball *b);                                           /* 888AAB98 */
void ts4_bm_ball_cache_end_constants_888AAE00(struct Ts4Ball *b);                                              /* 888AAE00 */
void ts4_bm_ball_cache_arc_constants_888AAEA8(struct Ts4Ball *b);                                              /* 888AAEA8 */
void ts4_bm_ball_launch_velocity_888AB220(const struct Ts4Ball *b, __vector4 *out);                            /* 888AB220 */
void ts4_bm_ball_arc1_position_888AB558(const float *gen, struct Ts4Ball *b);                                  /* 888AB558 */
unsigned int ts4_if_call_seq_u32_off24_888AC688(struct Ts4Ball *a0, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5); /* 888AC688 */
void ts4_bm_ball_solve_by_template_kind_888AD0E8(struct Ts4Ball *b);                                           /* 888AD0E8 */
void ts4_bm_ball_arc2_position_888AD1C8(const float *gen, struct Ts4Ball *b);                                  /* 888AD1C8 */
TS4_EXTERN_C_END

#endif /* TS4_BALL_H */
