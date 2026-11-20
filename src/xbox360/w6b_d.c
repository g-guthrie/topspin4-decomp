#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wuninitialized"
#endif
#include "w6b_types.h"

#ifdef _MSC_VER
extern float __fsqrts(float);
#pragma intrinsic(__fsqrts)
#else
static float __fsqrts(float x) { return x; }
#endif

typedef struct W6dB { unsigned char pad[0x218]; unsigned char flag218; } W6dB;
typedef struct W6dA {
    unsigned char pad00[0x18];
    int count18;                     /* +0x18 */
    unsigned char pad1c[0x4f0 - 0x1c];
    __vector4 vel4f0;                /* +0x4f0 */
    unsigned char pad500[0x520 - 0x500];
    float speed520;                  /* +0x520 */
} W6dA;
typedef struct W6dC { unsigned char pad[0x44]; W6dB *b44; } W6dC;
typedef struct W6dOwner {
    unsigned char pad00[0x1c];
    W6dC *c1c;                       /* +0x1c */
    W6dA *a20;                       /* +0x20 */
} W6dOwner;

static __inline W6dA *w6d_a(W6dOwner *o) { return o->a20; }

void ts4_update_speed_from_vel_8865FCE0(W6dOwner *o)
{
    __vector4 d;
    W6dB *b;
    w6d_a(o)->count18++;
    b = o->c1c->b44;
    d = __vmsum3fp(w6d_a(o)->vel4f0, w6d_a(o)->vel4f0);
    w6d_a(o)->speed520 = __fsqrts(d.v[0]) * 3.6f;
    b->flag218 = 0;
}

extern double fabs(double);
#ifdef _MSC_VER
#pragma intrinsic(fabs)
#endif

static __inline float w6d_abs(float x)
{
    float d;
    d = x;
    d = (float)fabs(d);
    return d;
}

unsigned char ts4_vec3_near_equal_886C4408(const __vector4 *a, const __vector4 *b)
{
    __vector4 d = __vsubfp(*a, *b);
    return w6d_abs(d.v[0]) < 0.001f && w6d_abs(d.v[1]) < 0.001f && w6d_abs(d.v[2]) < 0.001f;
}

typedef struct W6dP78 { unsigned char pad[0x90]; __vector4 vec90; } W6dP78;
typedef struct W6dObj78 { unsigned char pad[0x78]; W6dP78 *p78; } W6dObj78;
void fn_8867A7C0(W6dObj78 *self, __vector4 *out, float t);
static const float w6d_zero_a908 = 0.0f;

void ts4_vec_with_offset_8867A908(W6dObj78 *self, __vector4 *out, float t)
{
    *out = self->p78->vec90;
    if (t > w6d_zero_a908) {
        fn_8867A7C0(self, out, t);
        *out = __vaddfp(*out, self->p78->vec90);
    }
}

void ts4_matrix_lerp_88661238(__vector4 *out, const __vector4 *a, const __vector4 *b, float t)
{
    __vector4 a0 = a[0], a1 = a[1], a2 = a[2], a3 = a[3];
    __vector4 d0 = __vsubfp(b[0], a0);
    __vector4 d1 = __vsubfp(b[1], a1);
    __vector4 d2 = __vsubfp(b[2], a2);
    __vector4 d3 = __vsubfp(b[3], a3);
    __vector4 tv = vx1_replicate(t);
    out[0] = __vmaddfp(tv, d0, a0);
    out[1] = __vmaddfp(tv, d1, a1);
    out[2] = __vmaddfp(tv, d2, a2);
    out[3] = __vmaddfp(tv, d3, a3);
}

void ts4_transform_coord_8864E980(const __vector4 *v, const __vector4 *m, __vector4 *out)
{
    __vector4 p = *v;
    __vector4 m0 = m[0];
    __vector4 sz = __vspltw(p, 2);
    __vector4 sy = __vspltw(p, 1);
    __vector4 sx = __vspltw(p, 0);
    __vector4 r = __vmaddfp(m[2], sz, m[3]);
    __vector4 one = __vspltw(__vupkd3d(__vspltisw(0), 1), 3);
    __vector4 w, r0, s, r1, s2, mask, r2, rf;
    r = __vmaddfp(sy, m[1], r);
    r = __vmaddfp(sx, m0, r);
    w = __vspltw(r, 3);
    r0 = __vrefp(w);
    s = __vnmsubfp(w, r0, one);
    r1 = __vmaddfp(r0, s, r0);
    s2 = __vnmsubfp(w, r1, one);
    mask = __vcmpeqfp(r1, r1);
    r2 = __vmaddfp(r1, s2, r1);
    rf = __vsel(r0, r2, mask);
    *out = __vmulfp(r, rf);
}

typedef struct W6dElem { __vector4 v[3]; } W6dElem;
typedef struct W6dList {
    unsigned char pad[0x5a0];
    W6dElem *begin;        /* +0x5a0 */
    W6dElem *end;          /* +0x5a4 */
    unsigned char pad5a8[0x5bc - 0x5a8];
    unsigned int index;    /* +0x5bc */
} W6dList;
typedef struct W6dDefault {
    unsigned char pad[0x100];
    __vector4 a;           /* +0x100 */
    __vector4 b;           /* +0x110 */
} W6dDefault;
typedef struct W6dSel {
    unsigned char pad[0x20];
    W6dDefault *def20;     /* +0x20 */
    W6dList *list24;       /* +0x24 */
} W6dSel;

void fn_88692670(void *arg, __vector4 a, __vector4 b);

static __inline W6dElem *w6d_first(W6dList *l)
{
    W6dElem *r = 0;
    if (l->begin != l->end)
        r = l->begin + l->index;
    return r;
}

static __inline W6dElem *w6d_last(W6dList *l)
{
    W6dElem *r = 0;
    if (l->begin != l->end)
        r = l->end - 1;
    return r;
}

void ts4_call_with_range_endpoints_8869FCF0(W6dSel *self, void *arg)
{
    W6dList *l = self->list24;
    W6dElem *first = w6d_first(l);
    W6dElem *last = w6d_last(l);
    if (first != 0 && last != 0)
        fn_88692670(arg, first->v[0], last->v[0]);
    else
        fn_88692670(arg, self->def20->a, self->def20->b);
}

typedef struct W6dSrcEnt { float w; __vector4 *vp; } W6dSrcEnt;
typedef struct W6dOutItem { __vector4 pos; float w; float pad[3]; } W6dOutItem;
typedef struct W6dOutList {
    int rel;                 /* +0x00 */
    int pad04;
    int max;                 /* +0x08 */
    unsigned short n;        /* +0x0c */
} W6dOutList;
typedef struct W6dSrcB8 { unsigned char pad[0x7c]; W6dSrcEnt *begin; W6dSrcEnt *end; } W6dSrcB8;
typedef struct W6dN3 { unsigned char pad[0xb8]; W6dSrcB8 *b8; } W6dN3;
typedef struct W6dN2 { W6dN3 *n3; } W6dN2;
typedef struct W6dN1 { unsigned char pad[0x10]; W6dN2 *n2; } W6dN1;
typedef struct W6dN0 { W6dN1 *n1; } W6dN0;
typedef struct W6dHost {
    unsigned char pad00[0x10];
    W6dN0 *n0;               /* +0x10 */
    unsigned char pad14[0x44 - 0x14];
    unsigned char *base44;   /* +0x44 */
} W6dHost;

void ts4_collect_entries_8865EE90(W6dHost *h)
{
    int p0 W6B_UNUSED = 0, p1 W6B_UNUSED = 0, p2 W6B_UNUSED = 0, p3 W6B_UNUSED = 0, p4 W6B_UNUSED = 0, p5 W6B_UNUSED = 0;
    unsigned short i = 0;
    W6dOutList *out = (W6dOutList *)(h->base44 + 0x150);
    W6dSrcB8 *src = h->n0->n1->n2->n3->b8;
    W6dSrcEnt *p = src->begin;
    W6dSrcEnt *end = src->end;
    while (p != end) {
        float w;
        *(__vector4 *)((char *)out + (out->rel + i * 32)) = *p->vp;
        w = p->w;
        p++;
        ((W6dOutItem *)((char *)out + (out->rel + i * 32)))->w = w;
        i++;
        if (i >= out->max)
            break;
    }
    out->n = i;
}

typedef struct W6dV16 { float f[4]; } W6dV16;
typedef struct W6dM48 { unsigned long long q[6]; } W6dM48;
typedef struct W6dM64 { __vector4 r[4]; } W6dM64;
typedef struct W6dXf {
    W6dM48 m;            /* +0x00 */
    W6dV16 v;            /* +0x30 */
} W6dXf;

W6dM64 fn_881C4B58(W6dV16 a, W6dV16 b, W6dM48 m);

void ts4_rebuild_matrix_8864E708(W6dXf *self)
{
    W6dV16 other;
    W6dM64 r = fn_881C4B58(self->v, other, self->m);
    ((W6dM64 *)self)->r[0] = r.r[0];
    ((W6dM64 *)self)->r[1] = r.r[1];
    ((W6dM64 *)self)->r[2] = r.r[2];
    ((W6dM64 *)self)->r[3] = r.r[3];
}

typedef struct W6dHalf {
    __vector4 v00;           /* +0x00 */
    unsigned char pad10[0x20 - 0x10];
    __vector4 v20;           /* +0x20 */
} W6dHalf;
typedef struct W6dX74 { unsigned char pad[0x800]; W6dHalf h800; } W6dBlk;
typedef struct W6dY {
    unsigned char pad00[0x74];
    W6dBlk *blk74;
    unsigned char pad78[0x94 - 0x78];
    int l94;
} W6dY;
typedef struct W6dZ { unsigned char pad[4]; W6dY *y4; } W6dZ;

typedef struct W6dQ16 { unsigned long long q[2]; } W6dQ16;
static const float w6d_zero_a7d8 = 0.0f;
unsigned char fn_8826ACB8(void *list, unsigned int *id);

void ts4_reset_second_vec_8865A7D8(W6dZ *z)
{
    W6dY *y = z->y4;
    unsigned int id = 0x470600f5;
    if (!fn_8826ACB8(&y->l94, &id)) {
        W6dHalf *h = &y->blk74->h800;
        __vector4 t = h->v00;
        *(W6dQ16 *)&h->v20 = *(W6dQ16 *)&t;
        h->v20 = vx1_set_y(h->v20, w6d_zero_a7d8);
    }
}

typedef struct W6dSub20 {
    W6dQ16 v;                /* +0x00 */
    unsigned char pad10[0x20 - 0x10];
    float f20;               /* +0x20 */
} W6dSub20;

typedef struct W6dBlkE {
    W6dQ16 v0;               /* +0x00 */
    float f10;               /* +0x10 */
    float f14;               /* +0x14 */
    unsigned int f18;        /* +0x18 */
    unsigned char pad1c[0x20 - 0x1c];
    W6dSub20 s20;            /* +0x20 */
} W6dBlkE;
typedef struct W6dE78 { unsigned char pad[0x70]; W6dBlkE b70; } W6dE78;
typedef struct W6dE24 { unsigned char pad[0xb0]; unsigned int h; } W6dE24;
typedef struct W6dE4c { unsigned char pad[0x24]; W6dE24 *p24; } W6dE4c;
typedef struct W6dE {
    unsigned char pad[0x4c];
    W6dE4c *p4c;
    unsigned char pad50[0x78 - 0x50];
    W6dE78 *p78;
} W6dE;

extern float lbl_880C88DC;
static const float w6d_zero_ece0 = 0.0f;

void ts4_set_block_params_8865ECE0(W6dE *self, __vector4 v)
{
    W6dBlkE *p = &self->p78->b70;
    W6dSub20 *q = &p->s20;
    unsigned int eq;
    float f;
    p->v0 = *(W6dQ16 *)&v;
    eq = self->p4c->p24->h - 0x317c51b7 == 0;
    p->f18 = !eq;
    if (eq)
        f = w6d_zero_ece0;
    else
        f = lbl_880C88DC;
    p->f14 = f;
    p->f10 = w6d_zero_ece0;
    q->f20 = w6d_zero_ece0;
    q->v = *(W6dQ16 *)&v;
}

extern const __vector4 lbl_88001AF0;
typedef struct W6dCtx1c { unsigned char pad[0x1c]; void *pc1c; } W6dCtx1c;
__vector4 *ts4_if_get_u32_off4c_8865EC70(__vector4 *out, void *pc);

static __inline void w6d_store3(__vector4 *dst, __vector4 v)
{
    __stvewx(__vspltw(v, 0), dst, 0);
    __stvewx(__vspltw(v, 1), dst, 4);
    __stvewx(__vspltw(v, 2), dst, 8);
}

void ts4_fill_position_8866BB80(W6dCtx1c *self)
{
    __vector4 buf;
    w6d_store3(&buf, lbl_88001AF0);
    w6d_store3(&buf, *ts4_if_get_u32_off4c_8865EC70(&buf, self->pc1c));
}
