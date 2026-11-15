/* CX27 dc b: erase loops, /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define DC_INL static __forceinline
#else
#define DC_INL static inline
#endif

typedef struct Dc14 { u32 f0; u8 sub[0xc]; u32 f10; } Dc14;
typedef struct Dc14V { u32 p0; Dc14 *end; } Dc14V;
extern void fn_88150600(void *dst, void *src);
extern void ts4_loop_call_seq_u32_0x4_88181670(Dc14 *a, Dc14 *b);
DC_INL void dc_cpy_u32(u32 *d, u32 *s) { *d = *s; }

/* 0x8817EE38 */
Dc14 *ts4_dc14_erase_8817EE38(Dc14V *v, Dc14 *dst, Dc14 *first)
{
    int n = v->end - first;
    Dc14 *p = dst;
    Dc14 *s;
    if (n > 0) s = first;
    while (n > 0) {
        p->f0 = s->f0;
        fn_88150600(p->sub, s->sub);
        dc_cpy_u32(&p->f10, &s->f10);
        n--;
        p++;
        s++;
    }
    ts4_loop_call_seq_u32_0x4_88181670(p, v->end);
    v->end = p;
    return dst;
}

typedef struct Dc14b { u32 f0, f4; u8 sub[0xc]; } Dc14b;
typedef struct Dc14bV { u32 p0; Dc14b *end; } Dc14bV;
extern void fn_88186670(void *dst, void *src);
extern void ts4_destroy_owned_range_88187AB8(Dc14b *a, Dc14b *b);
DC_INL void dc_call_88186670(void *d, void *s) { fn_88186670(d, s); }

/* 0x8817E720 */
Dc14b *ts4_dc14b_erase_8817E720(Dc14bV *v, Dc14b *dst, Dc14b *first)
{
    int n = v->end - first;
    Dc14b *p = dst;
    Dc14b *s;
    if (n > 0) s = first;
    while (n > 0) {
        p->f0 = s->f0;
        p->f4 = s->f4;
        dc_call_88186670(p->sub, s->sub);
        n--;
        p++;
        s++;
    }
    ts4_destroy_owned_range_88187AB8(p, v->end);
    v->end = p;
    return dst;
}

typedef struct Dc20 { u8 s0[0xc]; u8 s1[0xc]; u32 w18, w1c; } Dc20;

/* 0x881660A0 */
Dc20 *ts4_dc20_copy_881660A0(Dc20 *first, Dc20 *last, Dc20 *dst)
{
    int n = last - first;
    Dc20 *s = first;
    Dc20 *p = dst;
    while (n > 0) {
        fn_88150600(p->s0, s->s0);
        fn_88150600(p->s1, s->s1);
        dc_cpy_u32(&p->w18, &s->w18);
        p->w1c = s->w1c;
        n--;
        s++;
        p++;
    }
    return p;
}

typedef struct Dc28 { u8 s0[0xc]; u8 s1[0xc]; u8 s2[0xc]; u32 w24; } Dc28;
extern void fn_88218FE0(void *dst, void *src);
extern void fn_8817AC40(void *dst, void *src);
DC_INL void dc_call_8817AC40(void *d, void *s) { fn_8817AC40(d, s); }

/* 0x8817B310 */
Dc28 *ts4_dc28_copy_8817B310(Dc28 *first, Dc28 *last, Dc28 *dst)
{
    int n = last - first;
    Dc28 *s = first;
    Dc28 *p = dst;
    while (n > 0) {
        fn_88218FE0(p, s);
        fn_8817AC40(p->s1, s->s1);
        dc_call_8817AC40(p->s2, s->s2);
        p->w24 = s->w24;
        n--;
        s++;
        p++;
    }
    return p;
}

typedef struct Dc30 { u8 s0[0xc]; u8 s1[0xc]; u8 s2[0xc]; u32 w24, w28, w2c; } Dc30;
DC_INL void dc_call_88150600(void *d, void *s) { fn_88150600(d, s); }

/* 0x88165FC8 */
Dc30 *ts4_dc30_copy_88165FC8(Dc30 *first, Dc30 *last, Dc30 *dst)
{
    int n = last - first;
    Dc30 *s = first;
    Dc30 *p = dst;
    while (n > 0) {
        fn_88150600(p, s);
        fn_88150600(p->s1, s->s1);
        dc_call_88150600(p->s2, s->s2);
        p->w24 = s->w24;
        p->w28 = s->w28;
        p->w2c = s->w2c;
        n--;
        s++;
        p++;
    }
    return p;
}

typedef struct Dc0c { u32 f0, f4, f8; } Dc0c;
typedef struct Dc0cV { u32 p0; Dc0c *end; } Dc0cV;
extern void ts4_destroy_polymorphic_value_range(Dc0c *a, Dc0c *b);

/* 0x88170398 */
Dc0c *ts4_dc0c_erase_88170398(Dc0cV *v, Dc0c *dst, Dc0c *first)
{
    int n = v->end - first;
    Dc0c *p = dst;
    Dc0c *s;
    if (n > 0) s = first;
    while (n > 0) {
        p->f4 = s->f4;
        dc_cpy_u32(&p->f8, &s->f8);
        n--;
        p++;
        s++;
    }
    ts4_destroy_polymorphic_value_range(p, v->end);
    v->end = p;
    return dst;
}

typedef struct Dc8 { u32 a, b; } Dc8;
typedef struct Dc8V { u32 p0; Dc8 *end; } Dc8V;
extern void ts4_loop_get_u32_off0_8826DF58(Dc8 *a, Dc8 *b);

/* 0x8826B830 */
Dc8 *ts4_dc8_erase_8826B830(Dc8V *v, Dc8 *dst, Dc8 *first)
{
    int n = v->end - first;
    Dc8 *p = dst;
    Dc8 *s;
    if (n > 0) s = first;
    while (n > 0) {
        dc_cpy_u32(&p->b, &s->b);
        n--;
        p++;
        s++;
    }
    ts4_loop_get_u32_off0_8826DF58(p, v->end);
    v->end = p;
    return dst;
}

typedef struct Dc20e { u32 f0, f4, f8, fc, f10, f14, f18; u8 f1c, f1d, pad[2]; } Dc20e;
typedef struct Dc20eV { u32 p0; Dc20e *end; } Dc20eV;

/* 0x88263A08 */
Dc20e *ts4_dc20e_erase_88263A08(Dc20eV *v, Dc20e *dst, Dc20e *first)
{
    int n = v->end - first;
    Dc20e *p = dst;
    Dc20e *s;
    if (n > 0) s = first;
    while (n > 0) {
        p->f0 = s->f0;
        p->f4 = s->f4;
        dc_cpy_u32(&p->f8, &s->f8);
        p->fc = s->fc;
        p->f10 = s->f10;
        p->f14 = s->f14;
        p->f18 = s->f18;
        p->f1c = s->f1c;
        p->f1d = s->f1d;
        n--;
        p++;
        s++;
    }
    v->end = p;
    return dst;
}

typedef struct Dc34 { u8 s0[0xc]; u8 s1[0xc]; u32 f18, f1c, f20, f24, f28, f2c; u8 f30, f31, pad[2]; } Dc34;
typedef struct Dc34V { u32 p0; Dc34 *end; } Dc34V;
extern void ts4_vector_assign_8817A8D0(void *d, void *s);
extern void ts4_vector_assign_8817AA88(void *d, void *s);
extern void fn_8890F428(void *p);

/* 0x88178AA8 */
Dc34 *ts4_dc34_erase_88178AA8(Dc34V *v, Dc34 *dst, Dc34 *first)
{
    int n = v->end - first;
    Dc34 *p = dst;
    Dc34 *s;
    Dc34 *q, *e;
    if (n > 0) s = first;
    while (n > 0) {
        ts4_vector_assign_8817A8D0(p, s);
        ts4_vector_assign_8817AA88(p->s1, s->s1);
        dc_cpy_u32(&p->f18, &s->f18);
        p->f1c = s->f1c;
        p->f20 = s->f20;
        p->f24 = s->f24;
        p->f28 = s->f28;
        p->f2c = s->f2c;
        p->f30 = s->f30;
        p->f31 = s->f31;
        n--;
        p++;
        s++;
    }
    e = v->end;
    for (q = p; q != e; q++) fn_8890F428(q);
    v->end = p;
    return dst;
}

typedef struct Dc44 { u32 w0, w4, w8, wc, w10, w14, w18, w1c, w20, w24, w28; u8 b[4]; u32 w30, w34, w38, w3c, w40; } Dc44;

/* 0x881817A0 */
Dc44 *ts4_dc44_copy_881817A0(Dc44 *first, Dc44 *last, Dc44 *dst)
{
    int n = last - first;
    Dc44 *s = first;
    Dc44 *p = dst;
    while (n > 0) {
        p->w0 = s->w0;
        p->w4 = s->w4;
        dc_cpy_u32(&p->w8, &s->w8);
        p->wc = s->wc;
        p->w10 = s->w10;
        p->w14 = s->w14;
        p->w18 = s->w18;
        p->w1c = s->w1c;
        p->w20 = s->w20;
        p->w24 = s->w24;
        p->w28 = s->w28;
        p->b[0] = s->b[0];
        p->b[1] = s->b[1];
        p->b[2] = s->b[2];
        p->b[3] = s->b[3];
        p->w30 = s->w30;
        p->w34 = s->w34;
        p->w38 = s->w38;
        p->w3c = s->w3c;
        p->w40 = s->w40;
        n--;
        s++;
        p++;
    }
    return p;
}

typedef struct Dc2c { u32 f0, f4, f8, fc; u8 f10; u8 p11[3]; u32 f14, f18, f1c, f20, f24; u8 f28, f29, p2a[2]; } Dc2c;
typedef struct Dc2cV { u32 p0; Dc2c *end; } Dc2cV;
extern void ts4_loop_get_u32_off0_88233460(Dc2c *a, Dc2c *b);

/* 0x88226E30 */
Dc2c *ts4_dc2c_erase_88226E30(Dc2cV *v, Dc2c *dst, Dc2c *first)
{
    int n = v->end - first;
    Dc2c *p = dst;
    Dc2c *s;
    if (n > 0) s = first;
    while (n > 0) {
        p->f4 = s->f4;
        dc_cpy_u32(&p->f8, &s->f8);
        p->fc = s->fc;
        p->f10 = s->f10;
        p->f14 = s->f14;
        p->f18 = s->f18;
        p->f1c = s->f1c;
        p->f20 = s->f20;
        p->f24 = s->f24;
        p->f28 = s->f28;
        p->f29 = s->f29;
        n--;
        p++;
        s++;
    }
    ts4_loop_get_u32_off0_88233460(p, v->end);
    v->end = p;
    return dst;
}

typedef struct Dc0cr { int a, b, c; } Dc0cr;
typedef struct Dc0crVec { Dc0cr *begin; Dc0cr *end; } Dc0crVec;
typedef struct Dc0crOwner { u8 p0[0x10]; void *heap; u32 p14; Dc0crVec v; } Dc0crOwner;
extern void ts4_registry_dispatch_888860A0(int h);
extern void ts4_tailcall_MmFreePhysicalMemory_8857B158(int h);

DC_INL void dc0cr_clear(Dc0crVec *v)
{
    Dc0cr *last = v->end;
    Dc0cr *p = v->begin;
    int n = v->end - last;
    Dc0cr *s = last;
    while (n > 0) {
        *p = *s;
        n--;
        s++;
        p++;
    }
    v->end = p;
}

/* 0x88619CF8: release every live handle, then clear the vector */
void ts4_dc0cr_release_all_88619CF8(Dc0crOwner *o)
{
    Dc0cr *e = o->v.end;
    Dc0cr *q;
    q = o->v.begin;
    if (e != q) do {
        if (q->a != 0) {
            if (o->heap != 0) ts4_registry_dispatch_888860A0(q->a);
            else ts4_tailcall_MmFreePhysicalMemory_8857B158(q->a);
            q->a = 0;
            q->b = -1;
            q->c = 0;
        }
        q++;
    } while (q != e);
    dc0cr_clear(&o->v);
}

typedef unsigned long long Dc_u64;
struct DcObj;
typedef struct DcObjVt { void (*dtor)(struct DcObj *, int); u8 p[0x10]; void (*slot5)(struct DcObj *); } DcObjVt;
typedef struct DcObj { const DcObjVt *vt; } DcObj;
typedef struct Dc8e { u32 a; DcObj *obj; } Dc8e;
typedef struct Dc8eVec { Dc8e *begin; Dc8e *end; } Dc8eVec;
typedef struct DcOwner2 { u8 p0[8]; u8 f8; u8 p9[7]; u8 sub[0xc]; Dc8eVec v; } DcOwner2;
extern void ts4_vec204_move_tail_881B9148(void *p);

DC_INL void dc8e_clear(Dc8eVec *v)
{
    Dc8e *last = v->end;
    Dc8e *p = v->begin;
    int n = v->end - last;
    Dc8e *s = last;
    while (n > 0) {
        *(Dc_u64 *)p = *(Dc_u64 *)s;
        n--;
        s++;
        p++;
    }
    v->end = p;
}

/* 0x886199D0 */
void ts4_dcowner2_clear_886199D0(DcOwner2 *o)
{
    Dc8e *e = o->v.end;
    Dc8e *q = o->v.begin;
    if (e != q) do {
        DcObj *ob = q->obj;
        ob->vt->slot5(ob);
        ob = q->obj;
        if (ob != 0) ob->vt->dtor(ob, 1);
        q++;
    } while (q != e);
    dc8e_clear(&o->v);
    o->f8 = 0;
    ts4_vec204_move_tail_881B9148(o->sub);
}

typedef struct Dc0crObj { int h; u32 cnt; u32 pc; u32 limit_c; u32 limit_10; Dc0crVec v; } Dc0crObj;

/* 0x88616A70 */
void ts4_dc0crobj_reset_88616A70(Dc0crObj *o)
{
    if (o->cnt > 0) {
        ts4_registry_dispatch_888860A0(o->h);
        o->h = 0;
        o->cnt = 0;
    }
    dc0cr_clear(&o->v);
    o->limit_10 = 0xFFFFFu;
    o->limit_c = 0xFFFFFu;
}
