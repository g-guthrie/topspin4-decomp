/* W8D: vector/float/virtual-call gameplay functions (LTCG route, /Oc) */
#include "w6a_types.h"
#include "vx1_vector.h"

/* Swing_DLL.xex 0x88644BD0: ts4_apply_scale_88644BD0 */
struct W8dCnt_88644BD0 { char pad[0x10]; int count; };
struct W8dMid_88644BD0 { char pad[0x1c]; struct W8dCnt_88644BD0 *c; };
struct W8dOwn_88644BD0 { char pad[0xa0]; struct W8dMid_88644BD0 *m; };
struct W8dBase_88644BD0 { char *base; };
struct W8dArg_88644BD0 { char pad[0x24]; void *p24; };
struct W8dS_88644BD0 {
    char pad00[0x20]; unsigned char on;
    char pad21[0x28 - 0x21]; __vector4 *v28;
    char pad2c[0x34 - 0x2c]; __vector4 *v34;
};
struct W8dFull_88644BD0 { char pad[0xa0]; struct W8dMid_88644BD0 *m; };
extern struct W8dBase_88644BD0 *ts4_loop_call_seq_fn_884025C0_88402978(void *);
void ts4_apply_scale_88644BD0(struct W8dS_88644BD0 *s, struct W8dArg_88644BD0 *a)
{ int op1_pad0 = 0, op1_pad1 = 0;
    if (s->on) {
        struct W8dMid_88644BD0 *m = ((struct W8dOwn_88644BD0 *)s)->m;
        void *p = a->p24;
        __vector4 *b = s->v34;
        __vector4 *c = s->v28;
        int n = m->c->count;
        struct W8dBase_88644BD0 *r = ts4_loop_call_seq_fn_884025C0_88402978(p);
        int i;
        for (i = 0; i < n; i++) {
            __vector4 *e = (__vector4 *)(r->base + i * 0x30);
            e[0] = __vmulfp(e[0], c[i]);
            e[2] = b[i];
        }
    }
 (void)op1_pad0; (void)op1_pad1;
}

/* Swing_DLL.xex 0x8865A890: ts4_dispatch_blocks_8865A890 */
struct W8dObj_8865A890;
struct W8dVt_8865A890 { void *pad[4]; void (*s10)(struct W8dObj_8865A890 *, void *, void *); void (*s14)(struct W8dObj_8865A890 *, void *); void (*s18)(struct W8dObj_8865A890 *, void *, void *); void (*s1c)(struct W8dObj_8865A890 *, void *, void *); };
struct W8dObj_8865A890 { struct W8dVt_8865A890 *vt; };
struct W8dC28_8865A890 { char pad[0x6a]; unsigned char f6a; };
struct W8dC48_8865A890 { char pad[0x28]; struct W8dC28_8865A890 *c28; };
struct W8dC74_8865A890 { char pad[0x840]; char blk[1]; };
struct W8dW_8865A890 { char pad[0x48]; struct W8dC48_8865A890 *c48; char pad2[0x74 - 0x4c]; struct W8dC74_8865A890 *c74; };
struct W8dS_8865A890 { char pad[0x10]; struct W8dW_8865A890 *w; };
struct W8dA_8865A890 { char pad[0xc]; struct W8dObj_8865A890 *o; };
void ts4_dispatch_blocks_8865A890(struct W8dS_8865A890 *s, struct W8dA_8865A890 *a)
{
    struct W8dC74_8865A890 *c = s->w->c74;
    void *blk = c->blk;
    if (s->w->c48->c28->f6a) {
        a->o->vt->s14(a->o, s->w);
    }
    a->o->vt->s18(a->o, blk, s->w);
    a->o->vt->s10(a->o, blk, s->w);
    a->o->vt->s1c(a->o, blk, s->w);
}

/* Swing_DLL.xex 0x886491E8: ts4_multiply_by_keys_886491E8 */
struct W8dQ_886491E8 { unsigned long long q[2]; };
struct W8dRec_886491E8 { __vector4 v; unsigned key[4]; };
struct W8dRel_886491E8 { int off; int count; };
struct W8dC1c_886491E8 { int x; };
struct W8dO_886491E8 { char pad[0x1c]; struct W8dC1c_886491E8 *p1c; };
struct W8dS_886491E8 { char pad[0x28]; __vector4 *tab28; char pad2c[0xa0 - 0x2c]; struct W8dO_886491E8 *o; };
extern int fn_88645A68(struct W8dC1c_886491E8 *c, void *key);
static __inline struct W8dRec_886491E8 *w8d_begin_886491E8(struct W8dRel_886491E8 *a)
{
    struct W8dRec_886491E8 *b = 0;
    if (a->off != -1) b = (struct W8dRec_886491E8 *)((char *)a + a->off);
    return b;
}
static __inline struct W8dRec_886491E8 *w8d_end_886491E8(struct W8dRel_886491E8 *a)
{
    struct W8dRec_886491E8 *e = 0;
    if (a->off != -1) e = (struct W8dRec_886491E8 *)((char *)a + (a->count * 32 + a->off));
    return e;
}
void ts4_multiply_by_keys_886491E8(struct W8dS_886491E8 *s, struct W8dRel_886491E8 *a)
{
    struct W8dC1c_886491E8 *c = s->o->p1c;
    struct W8dRec_886491E8 *e = w8d_end_886491E8(a);
    struct W8dRec_886491E8 *p;
    for (p = w8d_begin_886491E8(a); p != e; p++) {
        int idx = fn_88645A68(c, p->key);
        if (idx >= 0) {
            __vector4 *d = &s->tab28[idx];
            __vector4 r = __vmulfp(*d, p->v);
            *(struct W8dQ_886491E8 *)d = *(struct W8dQ_886491E8 *)&r;
        }
    }
}

/* Swing_DLL.xex 0x886783B0: ts4_copy_shot_state_886783B0 */
struct W8dBlk_886783B0 { unsigned long long q[8]; };
struct W8dC20_886783B0 { char pad[0x4f0]; struct W8dBlk_886783B0 blk; };
struct W8dC5c_886783B0 { char pad[0x20]; struct W8dC20_886783B0 *c20; };
struct W8dC48_886783B0 { char pad[0x5c]; struct W8dC5c_886783B0 *c5c; };
struct W8dC74_886783B0 {
    char pad[0x3a8]; unsigned char b3a8, b3a9; char pad3aa[0x400 - 0x3aa];
    unsigned char b400, b401, b402, b403; char pad404[1]; unsigned char b405, b406; char pad407[2]; unsigned char b409;
    char pad40a[0x500 - 0x40a]; struct W8dBlk_886783B0 blk;
    char pad540[0x574 - 0x540]; unsigned char b574;
    char pad575[0x5d9 - 0x575]; unsigned char b5d9, b5da;
};
struct W8dC1c_886783B0 { char pad[0x3c]; unsigned w3c; char pad40[0x48 - 0x40]; struct W8dC48_886783B0 *c48; char pad4c[0x70 - 0x4c]; void *c70; struct W8dC74_886783B0 *c74; };
struct W8dS_886783B0 { char pad[0x1c]; struct W8dC1c_886783B0 *c1c; };
extern void ts4_shot_eval_refresh_flags_88662B60(void *p);
void ts4_copy_shot_state_886783B0(struct W8dS_886783B0 *s)
{
    struct W8dC74_886783B0 *d;
    s->c1c->c74->blk = s->c1c->c48->c5c->c20->blk;
    d = s->c1c->c74;
    d->b405 = d->b3a8;
    d->b406 = s->c1c->c74->b3a9;
    if (s->c1c->c74->b5da) {
        s->c1c->w3c = 0x7eb30f90;
        d->b400 = 0;
        d->b401 = 0;
        d->b402 = 0;
        d->b403 = 0;
        d->b409 = 1;
    }
    {
        struct W8dC74_886783B0 *e = s->c1c->c74;
        e->b574 = e->b5d9 == 0;
    }
    ts4_shot_eval_refresh_flags_88662B60(s->c1c->c70);
}

/* Swing_DLL.xex 0x886D1910: ts4_scale_range_with_gain_886D1910 */
typedef struct W5dRec { float base; float scale; float gain; } W5dRec;     /* 12 bytes */
typedef struct W5dTab { int rel; unsigned char pad04[8]; short id; } W5dTab;
typedef struct W5dHdr { unsigned char pad00[8]; unsigned short idx; } W5dHdr;
typedef struct W5dAcc { float v0; float v1; } W5dAcc;
typedef struct W5dCtx { unsigned char pad00[0x20]; void *sink; } W5dCtx;
typedef struct W5dThis { unsigned char pad00[4]; W5dAcc *p4; } W5dThis;
extern void fn_88269420(float *v, float lim);
extern void ts4_push_tagged_element_88648020(void *sink, int id, float a, float *v, float b);
static __inline W5dAcc *w5d_acc(W5dThis *t) { return t->p4; }
void ts4_scale_range_with_gain_886D1910(W5dThis *self, W5dTab *tab, W5dCtx *ctx, float *rng, float *extra)
{
    W5dHdr *h = (W5dHdr *)self->p4;
    W5dRec *r = (W5dRec *)((char *)tab + tab->rel + h->idx * 12);
    float buf[2];
    void *sink = ctx->sink;
    int id = tab->id;
    float a = rng[0], b = rng[1];
    float sc = r->scale;
    float bs = r->base;
    buf[0] = a * sc + bs;
    buf[1] = b * sc + bs;
    fn_88269420(buf, 1.0f);
    self->p4->v0 = self->p4->v1 * r->gain + self->p4->v0;
    if (id != -1)
        ts4_push_tagged_element_88648020(sink, id, w5d_acc(self)->v1, buf, extra[1]);
}

/* Swing_DLL.xex 0x886D6C60: ts4_apply_range_gain_cur_886D6C60 */
typedef struct W8dRec_886D6C60 { float base; float scale; float gain; } W8dRec_886D6C60;
typedef struct W8dHdr_886D6C60 { int rel; } W8dHdr_886D6C60;
typedef struct W8dTab_886D6C60 { char pad[0xc]; W8dHdr_886D6C60 hdr; char pad10[8]; short id; } W8dTab_886D6C60;
typedef struct W8dAcc_886D6C60 { float v0; float v1; } W8dAcc_886D6C60;
typedef struct W8dCtx_886D6C60 { char pad00[0x20]; void *sink; char pad24[0x460 - 0x24]; char blk[0x10]; W8dTab_886D6C60 *cur; } W8dCtx_886D6C60;
typedef struct W8dThis_886D6C60 { unsigned char pad00[4]; W8dAcc_886D6C60 *p4; } W8dThis_886D6C60;
extern void fn_886D53F0(void *blk, float *v, float a);
extern void ts4_push_tagged_element_88648020(void *sink, int id, float a, float *v, float b);
static __inline W8dAcc_886D6C60 *w8d_acc_886D6C60(W8dThis_886D6C60 *t) { return t->p4; }
void ts4_apply_range_gain_cur_886D6C60(W8dThis_886D6C60 *self, W8dTab_886D6C60 *tab, W8dCtx_886D6C60 *ctx, float *rng, float *extra)
{
    W8dHdr_886D6C60 *h = &tab->hdr;
    W8dRec_886D6C60 *r = (W8dRec_886D6C60 *)((char *)h + h->rel);
    float buf[2];
    float sc = r->scale;
    float a = rng[0];
    float b = rng[1];
    float bs = r->base;
    self->p4->v0 = self->p4->v1 * r->gain + self->p4->v0;
    buf[0] = a * sc + bs;
    buf[1] = b * sc + bs;
    if (ctx->cur == tab) {
        fn_886D53F0(ctx->blk, buf, w8d_acc_886D6C60(self)->v1);
    } else {
        int id = tab->id;
        if (id != -1)
            ts4_push_tagged_element_88648020(ctx->sink, id, w8d_acc_886D6C60(self)->v1, buf, extra[1]);
    }
}

/* Swing_DLL.xex 0x886579B8: ts4_find_and_flush_886579B8 */
struct W8dLock_886579B8;
struct W8dLockVt_886579B8 { void *s0; void (*lock)(struct W8dLock_886579B8 *); void (*unlock)(struct W8dLock_886579B8 *); };
struct W8dLock_886579B8 { struct W8dLockVt_886579B8 *vt; };
struct W8dItem_886579B8 { unsigned id; int pad; int *q8; };
struct W8dS_886579B8 {
    char pad[0x24]; struct W8dLock_886579B8 lk;
    char pad28[0x44 - 0x28]; struct W8dItem_886579B8 **begin; struct W8dItem_886579B8 **end;
};
extern int ts4_flush_queue_88655BC8(int *q);
int ts4_find_and_flush_886579B8(struct W8dS_886579B8 *s, unsigned key)
{
    struct W8dItem_886579B8 **p;
    struct W8dItem_886579B8 **e;
    struct W8dItem_886579B8 *it = 0;
    s->lk.vt->lock(&s->lk);
    e = s->end;
    for (p = s->begin; p != e; p++) {
        if ((*p)->id == key) {
            it = *p;
            break;
        }
    }
    if (it == 0) {
        s->lk.vt->unlock(&s->lk);
        return 0;
    }
    {
        int r = ts4_flush_queue_88655BC8(it->q8);
        s->lk.vt->unlock(&s->lk);
        return r;
    }
}

/* Swing_DLL.xex 0x88658268: ts4_find_and_clear_88658268 */
struct W8dLock_88658268;
struct W8dLockVt_88658268 { void *s0; void (*lock)(struct W8dLock_88658268 *); void (*unlock)(struct W8dLock_88658268 *); };
struct W8dLock_88658268 { struct W8dLockVt_88658268 *vt; };
struct W8dQ_88658268 { char pad[0xc]; int w0c; int w10; };
struct W8dItem_88658268 { unsigned id; int pad; struct W8dQ_88658268 *q8; };
struct W8dS_88658268 {
    char pad[0x24]; struct W8dLock_88658268 lk;
    char pad28[0x44 - 0x28]; struct W8dItem_88658268 **begin; struct W8dItem_88658268 **end;
};
struct W8dTriple_88658268 { int a, b, c; };
extern void fn_882738F8(struct W8dS_88658268 *s, struct W8dTriple_88658268 *t);
int ts4_find_and_clear_88658268(struct W8dS_88658268 *s, unsigned key)
{
    struct W8dItem_88658268 **p;
    struct W8dItem_88658268 **e;
    struct W8dItem_88658268 *it = 0;
    s->lk.vt->lock(&s->lk);
    e = s->end;
    for (p = s->begin; p != e; p++) {
        if ((*p)->id == key) {
            it = *p;
            break;
        }
    }
    if (it == 0) {
        s->lk.vt->unlock(&s->lk);
        return 0;
    }
    {
        struct W8dTriple_88658268 t;
        struct W8dQ_88658268 *q = it->q8;
        t.a = 0; t.b = 0; t.c = 0;
        q->w0c = 0;
        q->w10 = 0;
        fn_882738F8(s, &t);
        s->lk.vt->unlock(&s->lk);
        return 1;
    }
}

/* Swing_DLL.xex 0x886C6F88: ts4_mark_last_active_886C6F88 */
typedef struct W8dRel_886C6F88 { int rel; int count; } W8dRel_886C6F88;
typedef struct W8dEl_886C6F88 { char pad[0x10]; __vector4 v; char pad20[0x44 - 0x20]; unsigned w44; char pad48[0x70 - 0x48]; unsigned char b70; char pad71[0x80 - 0x71]; } W8dEl_886C6F88;
typedef struct W8dC34_886C6F88 { char pad[0x1c]; unsigned char b1c, b1d; } W8dC34_886C6F88;
typedef struct W8dC10_886C6F88 { char pad[0x34]; W8dC34_886C6F88 *c34; } W8dC10_886C6F88;
typedef struct W8dC14_886C6F88 { char pad[0x3c0]; __vector4 v3c0; char pad3d0[0x49c - 0x3d0]; W8dRel_886C6F88 rel; } W8dC14_886C6F88;
typedef struct W8dS_886C6F88 { char pad[0x10]; W8dC14_886C6F88 *c14dummy; } W8dS_886C6F88;
typedef struct W8dO_886C6F88 { char pad[0x10]; W8dC10_886C6F88 *c10; W8dC14_886C6F88 *c14; } W8dO_886C6F88;
typedef struct W8dSelf_886C6F88 { char pad[0x1c]; W8dO_886C6F88 *o; } W8dSelf_886C6F88;
static __inline W8dEl_886C6F88 *w8d_begin_886C6F88(W8dRel_886C6F88 *a)
{
    W8dEl_886C6F88 *b = 0;
    if (a->rel != -1) b = (W8dEl_886C6F88 *)((char *)a + a->rel);
    return b;
}
static __inline W8dEl_886C6F88 *w8d_end_886C6F88(W8dRel_886C6F88 *a)
{
    W8dEl_886C6F88 *e = 0;
    if (a->rel != -1) e = (W8dEl_886C6F88 *)((char *)a + (a->count * 0x80 + a->rel));
    return e;
}
void ts4_mark_last_active_886C6F88(W8dSelf_886C6F88 *s)
{
    W8dEl_886C6F88 *r, *b, *e, *p;
    unsigned char ok = 0;
    W8dRel_886C6F88 *h;
    {
        W8dC34_886C6F88 *c = s->o->c10->c34;
        ok = c->b1c != 0 && c->b1d == 0;
    }
    if (ok == 0) return;
    h = &s->o->c14->rel;
    r = w8d_begin_886C6F88(h);
    b = w8d_begin_886C6F88(h);
    e = w8d_end_886C6F88(h);
    for (p = b; p != e; p++) {
        if (p->w44 == 0) break;
        r = p;
    }
    if (r == 0) return;
    r->b70 = 1;
    r->v = s->o->c14->v3c0;
}
