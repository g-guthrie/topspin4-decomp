#include "w6b_types.h"

typedef struct W6fE18 { unsigned int w[6]; } W6fE18;
typedef struct W6fE20 { __vector4 a; __vector4 b; } W6fE20;

typedef struct W6fVec18 { W6fE18 *begin; W6fE18 *end; } W6fVec18;
typedef struct W6fVec20 { W6fE20 *begin; W6fE20 *end; } W6fVec20;

typedef struct W6fHolder {
    unsigned char pad00[0x08];
    W6fVec18 v08;      /* +0x08 */
    unsigned char pad10[4];
    W6fVec20 v14;      /* +0x14 */
    unsigned char pad1c[4];
    W6fVec20 v20;      /* +0x20 */
} W6fHolder;

static W6fE18 *w6f_copy18(W6fE18 *src, W6fE18 *src_end, W6fE18 *dest)
{
    int n = (int)((char *)src_end - (char *)src) / 24;
    for (; n > 0; --n) {
        *dest = *src;
        ++src;
        ++dest;
    }
    return dest;
}

static W6fE20 *w6f_copy20(W6fE20 *src, W6fE20 *src_end, W6fE20 *dest)
{
    int n = (int)((char *)src_end - (char *)src) >> 5;
    for (; n > 0; --n) {
        dest->a = src->a;
        dest->b = src->b;
        dest++;
        src++;
    }
    return dest;
}

void ts4_clear_three_vectors_886C3658(W6fHolder *self)
{
    W6fVec18 *a;
    W6fVec20 *b;
    W6fVec20 *c;
    a = &self->v08;
    a->end = w6f_copy18(a->end, a->end, a->begin);
    b = &self->v14;
    b->end = w6f_copy20(b->end, b->end, b->begin);
    c = &self->v20;
    c->end = w6f_copy20(c->end, c->end, c->begin);
}

typedef struct W6fE0c { unsigned int w[3]; } W6fE0c;
typedef struct W6fVec0c { W6fE0c *begin; W6fE0c *end; } W6fVec0c;

static W6fE0c *w6f_copy0c(W6fE0c *src, W6fE0c *src_end, W6fE0c *dest)
{
    int n = (int)((char *)src_end - (char *)src) / 12;
    for (; n > 0; --n) {
        *dest = *src;
        ++src;
        ++dest;
    }
    return dest;
}

typedef struct W6fHolder2 {
    unsigned char pad00[0x14];
    W6fVec0c v14;       /* +0x14 */
    unsigned char pad1c[4];
    W6fVec20 v20;       /* +0x20 */
    unsigned char pad28[4];
    W6fVec20 v2c;       /* +0x2c */
    unsigned char pad34[8];
    W6fVec20 v3c;       /* +0x3c */
} W6fHolder2;

void ts4_clear_four_vectors_886C3820(W6fHolder2 *self)
{
    W6fVec20 *a;
    W6fVec0c *b;
    W6fVec20 *c;
    W6fVec20 *d;
    a = &self->v20;
    a->end = w6f_copy20(a->end, a->end, a->begin);
    b = &self->v14;
    b->end = w6f_copy0c(b->end, b->end, b->begin);
    c = &self->v2c;
    c->end = w6f_copy20(c->end, c->end, c->begin);
    d = &self->v3c;
    d->end = w6f_copy20(d->end, d->end, d->begin);
}

typedef struct W6fRec { unsigned char pad[0x20]; float f20[4]; unsigned char pad30[0x20]; float f50[4]; } W6fRec;
typedef struct W6fCfg44 { unsigned char pad[0x44]; int idx44; } W6fCfg44;
typedef struct W6fList { unsigned char *base; } W6fList;
typedef struct W6fSrc28 { unsigned char pad[0x1d0]; __vector4 v1d0; } W6fSrc28;
typedef struct W6fRoot {
    unsigned char pad00[0x28];
    W6fSrc28 *src28;
    unsigned char pad2c[0x94 - 0x2c];
    void *p94;
    unsigned char pad98[0xa8 - 0x98];
    W6fCfg44 *cfg;
} W6fRoot;
W6fList *ts4_loop_call_seq_fn_884027D8_884029E8(void *p);
extern const float g_ts4_script_constants[];

void ts4_init_records_88644AE0(W6fRoot *self)
{
    W6fList *l = ts4_loop_call_seq_fn_884027D8_884029E8(self->p94);
    unsigned char *base = l->base;
    W6fCfg44 *cfg = self->cfg;
    W6fSrc28 *src = self->src28;
    __vector4 tmp;
    int off;
    int i;
    ((W6fRec *)(base + cfg->idx44 * 0x30))->f20[0] = 1.0f;
    ((W6fRec *)(base + cfg->idx44 * 0x30))->f20[1] = 1.0f;
    ((W6fRec *)(base + cfg->idx44 * 0x30))->f20[2] = 1.0f;
    ((W6fRec *)(base + cfg->idx44 * 0x30))->f20[3] = 1.0f;
    tmp = src->v1d0;
    off = 0x5d0;
    for (i = 0; i < 19; i++) {
        W6fRec *r = (W6fRec *)(base + off);
        float f = tmp.v[0];
        r->f20[0] = f;
        r->f20[1] = f;
        r->f20[2] = f;
        r->f20[3] = f;
        r->f50[0] = f;
        r->f50[1] = f;
        r->f50[2] = f;
        r->f50[3] = f;
        off += 0x60;
    }
}

void fn_8864E310(__vector4 *out, const __vector4 *q);

static __inline void w6f_mul(__vector4 *out, const __vector4 *a, const __vector4 *b)
{
    __vector4 a0 = a[0], a1 = a[1], a2 = a[2], a3 = a[3];
    __vector4 x0, x1, x2, x3;
    x0 = __vmulfp(__vspltw(a0, 0), b[0]);
    x1 = __vmulfp(__vspltw(a1, 0), b[0]);
    x2 = __vmulfp(__vspltw(a2, 0), b[0]);
    x3 = __vmulfp(__vspltw(a3, 0), b[0]);
    x0 = __vmaddfp(__vspltw(a0, 1), b[1], x0);
    x1 = __vmaddfp(__vspltw(a1, 1), b[1], x1);
    x2 = __vmaddfp(__vspltw(a2, 1), b[1], x2);
    x3 = __vmaddfp(__vspltw(a3, 1), b[1], x3);
    x0 = __vmaddfp(__vspltw(a0, 2), b[2], x0);
    x1 = __vmaddfp(__vspltw(a1, 2), b[2], x1);
    x2 = __vmaddfp(__vspltw(a2, 2), b[2], x2);
    x3 = __vmaddfp(__vspltw(a3, 2), b[2], x3);
    x0 = __vmaddfp(__vspltw(a0, 3), b[3], x0);
    x1 = __vmaddfp(__vspltw(a1, 3), b[3], x1);
    x2 = __vmaddfp(__vspltw(a2, 3), b[3], x2);
    x3 = __vmaddfp(__vspltw(a3, 3), b[3], x3);
    out[0] = x0;
    out[1] = x1;
    out[2] = x2;
    out[3] = x3;
}

void ts4_matrix_mul_quat_in_place_8864E4B0(__vector4 *m, const __vector4 *q)
{
    __vector4 t[4];
    fn_8864E310(t, q);
    w6f_mul(m, m, t);
}

typedef struct W6fBlkG {
    __vector4 v0;               /* +0x00 */
    float f10;                  /* +0x10 */
    float f14;                  /* +0x14 */
    unsigned int w18;           /* +0x18 */
    unsigned char b1c;          /* +0x1c */
} W6fBlkG;
typedef struct W6fObj74 { unsigned char pad[0x74]; unsigned char *p74; } W6fObj74;
typedef struct W6fOwner30 { unsigned char pad[0x310]; unsigned int w310; } W6fOwner30;
typedef struct W6fSlots { W6fObj74 *s[4]; } W6fSlots;
typedef struct W6fG {
    unsigned char pad00[4];
    W6fSlots *slots4;           /* +0x04 */
    unsigned char pad08[0x30 - 0x08];
    W6fOwner30 *owner30;        /* +0x30 */
} W6fG;

void ts4_init_slot_blocks_8865F410(W6fG *self)
{
    int i;
    float c = g_ts4_script_constants[0x1e0 / 4];
    for (i = 0; i < 4; i++) {
        W6fObj74 *o = self->slots4->s[i];
        if (o != 0) {
            W6fBlkG *b = (W6fBlkG *)(o->p74 + 0xef0);
            b->f14 = c;
            b->f10 = c;
            b->w18 = self->owner30->w310;
            b->v0 = *(__vector4 *)(o->p74 + 0x8e0);
            b->b1c = 0;
        }
    }
}

typedef struct W6fCfgH { unsigned char pad[0x6f0]; float thr6f0; } W6fCfgH;
typedef struct W6fOwn28 { unsigned char pad[0xc]; unsigned int type0c; } W6fOwn28;
typedef struct W6fOwner18 {
    unsigned char pad00[0x28];
    W6fOwn28 *p28;              /* +0x28 */
    W6fCfgH *cfg2c;             /* +0x2c */
    unsigned char pad30[0x74 - 0x30];
    unsigned char *p74;         /* +0x74 */
} W6fOwner18;
typedef struct W6fH { unsigned char pad[0x18]; W6fOwner18 *own18; } W6fH;

static __inline unsigned char w6f_gt(float a, float b) { return a > b; }
static __inline unsigned char w6f_lt(float a, float b) { return a < b; }

void ts4_hash_by_side_88660D10(W6fH *self, unsigned int hash, unsigned char *out)
{
    __vector4 v = *(__vector4 *)(self->own18->p74 + 0x8e0);
    float t = self->own18->cfg2c->thr6f0;
    int r;
    if (w6f_gt(v.v[2], t)) {
        if (self->own18->p28->type0c == 0xda554856)
            r = hash == 0x3f3a4df2 || hash == 0x5fa393b7;
        else
            r = hash == 0x3f3a4df2 || hash == 0x1db77bad;
    } else {
        __vector4 w = *(__vector4 *)(self->own18->p74 + 0x8e0);
        if (w6f_lt(w.v[2], -t)) {
            if (self->own18->p28->type0c == 0xda554856)
                r = hash == 0x3f3a4df2 || hash == 0x1db77bad;
            else
                r = hash == 0x3f3a4df2 || hash == 0x5fa393b7;
        } else {
            r = hash == 0x5fa393b7 || hash == 0x1db77bad;
        }
    }
    *out = (unsigned char)r;
}

typedef struct W6fHdr48 { int rel; } W6fHdr48;
typedef struct W6fTri {
    __vector4 pos;              /* +0x00 */
    unsigned char pad10[0x14 - 0x10];
    unsigned int w14;           /* +0x14 */
    int w18;                    /* +0x18 */
    int w1c;                    /* +0x1c */
    int w20;                    /* +0x20 */
    int w24;                    /* +0x24 */
    unsigned char pad28[0x38 - 0x28];
    float f38;                  /* +0x38 */
    float f3c;                  /* +0x3c */
    float f40;                  /* +0x40 */
    float f44;                  /* +0x44 */
    W6fHdr48 *hdr48;            /* +0x48 */
} W6fTri;

extern const float g_ts4_script_constants[];
extern const float g_ts4_event_value;
void fn_886C6118(W6fTri *s, const unsigned short *k, const __vector4 *p, __vector4 *out, float *u, float *v);
int ts4_lookup_u16_pair4_by_key_886C43B0(const unsigned short *pairs, unsigned key);

void ts4_closest_point_ref_886CA320(W6fTri *s, const unsigned short *k, const __vector4 *p, float *best)
{
    float zero = g_ts4_event_value;
    float u, v;
    __vector4 q, qv, pv;
    u = zero;
    v = zero;
    fn_886C6118(s, k, p, &q, &u, &v);
    pv = *p;
    qv = q;
    q = __vmsum3fp(__vsubfp(pv, qv), __vsubfp(pv, qv));
    if (q.v[0] < *best) {
        const unsigned short *list;
        W6fHdr48 *h;
        unsigned int idx;
        *best = q.v[0];
        s->f3c = u;
        h = s->hdr48;
        s->f40 = v;
        s->f44 = zero;
        s->f38 = 1.0f - u - v;
        idx = k[3];
        s->w14 = idx;
        list = 0;
        if (h->rel != -1)
            list = (const unsigned short *)((char *)h + (idx * 16 + h->rel));
        s->w18 = ts4_lookup_u16_pair4_by_key_886C43B0(list, k[0]);
        s->w1c = ts4_lookup_u16_pair4_by_key_886C43B0(list, k[1]);
        s->w20 = ts4_lookup_u16_pair4_by_key_886C43B0(list, k[2]);
        s->pos = qv;
        s->w24 = -1;
    }
}

typedef struct W6fBlk1e0 {
    __vector4 v0;               /* +0x00 */
    __vector4 v10;              /* +0x10 */
    unsigned char pad20[0x30 - 0x20];
    int w30;                    /* +0x30 */
    int w34;                    /* +0x34 */
    unsigned char b38;          /* +0x38 */
} W6fBlk1e0;
typedef struct W6fP44 { unsigned char pad[0x44]; unsigned char *p44; } W6fP44;
typedef struct W6fLerper {
    unsigned char pad00[0x1c];
    W6fP44 *p1c;                /* +0x1c */
    unsigned char pad20[0x2c - 0x20];
    int w2c;                    /* +0x2c */
    __vector4 v30;              /* +0x30 */
    unsigned char b40;          /* +0x40 */
} W6fLerper;


void ts4_start_interp_8866F668(W6fLerper *s, int t, __vector4 target)
{
    __vector4 d = __vsubfp(target, s->v30);
    int diff = t - s->w2c;
    if (diff > 0) {
        W6fBlk1e0 *b = (W6fBlk1e0 *)(s->p1c->p44 + 0x1e0);
        float inv = 1.0f / (float)diff;
        b->b38 = 1;
        b->w30 = diff;
        b->v0 = s->v30;
        b->v10 = __vmulfp(d, vx1_replicate(inv));
        if (s->b40)
            b->w34 = t - b->w34;
        else
            b->w34 = 0;
        s->b40 = 0;
    }
}
