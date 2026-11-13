/*
 * Ball-flight state view for the BM matching family (Top Spin 4, Xbox 360).
 * Offsets follow src/xbox360/gp4b_types.h (Gp4bBall); only fields the closed-form
 * flight model touches are named. Vector fields are 16-byte aligned structs so
 * whole-vector copies compile to lvx128/stvx128 like the original.
 */
#ifndef BM_BALL_H
#define BM_BALL_H

#include "ts4_vector.h"

typedef union ts4_bm_vec4 {
    float f[4];
    unsigned long long q[2];    /* forces 8-byte aligned (ld/std) aggregate copies */
} ts4_bm_vec4;

/* Ball physics parameters at ball+0x4B0 (radius in cm, drag factor a4, gravity g). */
typedef struct ts4_bm_phys {
    float net_cord[4];          /* +0x00 (ball+0x4B0) */
    float pad10[4];             /* +0x10 */
    float radius_cm;            /* +0x20 (ball+0x4D0) */
    float a4;                   /* +0x24 (ball+0x4D4) */
    float g;                    /* +0x28 (ball+0x4D8) */
} ts4_bm_phys;

/* Cached closed-form constants at ball+0x150 (written by the two cache functions). */
typedef struct ts4_bm_arc {
    float inv_T, inv_a4, k, g_a4;              /* +0x00 (ball+0x150) */
    float inv_T2, a4_sq, T_sq;                 /* +0x10 */
    float p0x_T, p1x_T, p0y_T, p0z_T, p1z_T;   /* +0x1C */
    float E, inv_E_m1;                         /* +0x30 */
    float tauA_x, tauA_y, tauA_z;              /* +0x38 */
    float g_a4_tau;                            /* +0x44 */
} ts4_bm_arc;

typedef struct ts4_bm_ball {
    float tau;                  /* 0x000 flight time of arc 1 (s) */
    unsigned int bounce_tick;   /* 0x004 */
    float T;                    /* 0x008 drag scale */
    unsigned char pad0c[0x14 - 0x0C];
    int bounce_count;           /* 0x014 */
    int tick;                   /* 0x018 */
    int tick_prev;              /* 0x01C */
    unsigned char pad20[4];     /* 0x020 */
    const unsigned int *tpl;    /* 0x024 shot template row + 0x18; kind hash at tpl[2] */
    unsigned char pad28[0x40 - 0x28];
    ts4_bm_vec4 pos;            /* 0x040 */
    unsigned char pad50[0x60 - 0x50];
    ts4_bm_vec4 prev;           /* 0x060 */
    ts4_bm_vec4 origin;         /* 0x070 local frame origin (cm) */
    __vector4 A;                    /* 0x080 drift vector */
    unsigned char pad90[0x100 - 0x90];
    __vector4 P0;             /* 0x100 */
    __vector4 P1;             /* 0x110 */
    unsigned char pad120[0x130 - 0x120];
    __vector4 arc2_pos;       /* 0x130 */
    __vector4 arc2_vel;       /* 0x140 */
    float inv_T, inv_a4, k, g_a4;              /* 0x150 */
    float inv_T2, a4_sq, T_sq;                 /* 0x160 */
    float p0x_T, p1x_T, p0y_T, p0z_T, p1z_T;   /* 0x16C */
    float E, inv_E_m1;                         /* 0x180 */
    float tauA_x, tauA_y, tauA_z;              /* 0x188 */
    float g_a4_tau;                            /* 0x194 */
    unsigned char pad198[0x340 - 0x198];
    unsigned char pad340[0x43C - 0x340];
    unsigned char new_shot;     /* 0x43C launch requested */
    unsigned char pad43d[0x4B0 - 0x43D];
    ts4_bm_phys phys;           /* 0x4B0 */
    unsigned char pad4dc[0x4E0 - 0x4DC];
    unsigned char frozen;       /* 0x4E0 flight step disabled */
    unsigned char pad4e1[0x530 - 0x4E1];
    unsigned char enabled;      /* 0x530 */
} ts4_bm_ball;

#endif
