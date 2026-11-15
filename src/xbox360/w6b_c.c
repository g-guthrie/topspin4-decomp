#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wuninitialized"
#endif
#include "w6b_types.h"

extern const __vector4 lbl_880FC650;
static const float w6b_zero_d880 = 0.0f;

typedef struct W6bMover {
    __vector4 a;       /* +0x00 */
    __vector4 b;       /* +0x10 */
    float f20;
    float f24;
} W6bMover;

typedef struct W6bCopy48 {
    unsigned long long q[6];
} W6bCopy48;

static __inline const __vector4 *w6b_k(void) { return &lbl_880FC650; }
static __inline const __vector4 *w6b_k2(void) { return &lbl_880FC650; }

typedef struct W6bPairC { __vector4 a; __vector4 b; } W6bPairC;
static __inline void w6b_vcopy2(W6bPairC *p, const __vector4 *v) { p->a = *v; p->b = *v; }

void ts4_mover_clamp_speed_half_vel_88670C20(W6bMover *s);

void ts4_mover_init_from_8867D880(W6bMover *s, const W6bCopy48 *src)
{
    __vector4 t0 = *w6b_k();
    __vector4 t1 = *w6b_k2();
    s->a = t0;
    s->b = t1;
    s->f20 = w6b_zero_d880;
    s->f24 = w6b_zero_d880;
    *(W6bCopy48 *)s = *src;
    ts4_mover_clamp_speed_half_vel_88670C20(s);
}

void ts4_matrix_scaling_8864EF98(__vector4 *m, const float *s)
{
    __vector4 zero = __vspltisw(0);
    __vector4 r0 = __lvlx(s, 0);
    __vector4 r1 = zero;
    __vector4 r2 = zero;
    __vector4 r3 = __vupkd3d(zero, 1);
    r0 = __vrlimi(r0, zero, 7, 0);
    r3 = __vpermwi(r3, 171);
    r1 = __vrlimi(r1, __lvlx(s + 1, 0), 4, 3);
    r2 = __vrlimi(r2, __lvlx(s + 2, 0), 2, 2);
    m[0] = r0;
    m[1] = r1;
    m[2] = r2;
    m[3] = r3;
}

typedef struct W6bSub40c {
    unsigned char pad00[0x3c];
    float f3c;   /* +0x3c */
    float f40;   /* +0x40 */
} W6bSub40c;

typedef struct W6bSub9a0 {
    unsigned char pad00[0x20];
    __vector4 vec20;   /* +0x20 */
} W6bSub9a0;

typedef struct W6bBlock {
    unsigned char pad000[0x40c];
    W6bSub40c s40c;
    unsigned char pad450[0x9a0 - 0x40c - sizeof(W6bSub40c)];
    W6bSub9a0 s9a0;
    unsigned char pad9d0[0x9fc - 0x9a0 - sizeof(W6bSub9a0)];
    unsigned int id9fc;
} W6bBlock;

typedef struct W6bInner { unsigned char pad[0x74]; W6bBlock *blk; } W6bInner;
typedef struct W6bMid { unsigned char pad[0x8]; W6bInner *inner; } W6bMid;
typedef struct W6bOwner { unsigned char pad[0x1c]; W6bMid *mid; } W6bOwner;

static const float w6b_zero_d110 = 0.0f;

static __inline void w6b_put_vec(W6bSub9a0 *q, __vector4 v) { q->vec20 = v; }
static __inline float w6b_get_x(W6bSub40c *a) { return a->f40; }
static __inline float w6b_get_z(W6bSub40c *a) { return -a->f3c; }

void ts4_set_block_vec_8866D110(W6bOwner *o)
{
    W6bBlock *b = o->mid->inner->blk;
    W6bSub40c *a = &b->s40c;
    W6bSub9a0 *q = &b->s9a0;
    __vector4 v;
    float z = w6b_zero_d110;
    v.v[1] = z;
    v.v[3] = z;
    b->id9fc = 0x9e51242b;
    v.v[0] = a->f40;
    v.v[2] = -a->f3c;
    q->vec20 = v;
}
