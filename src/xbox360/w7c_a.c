/* W7C: plain-route matches (integer-only), Top Spin 4 Xbox 360 Swing_DLL.xex. */

/* ---- 0x88666EE0: arm flag and wrap counter 0..6 ---- */
struct W7cCtr88666EE0 { unsigned char p[0xc0]; int c; };
struct W7cSelf88666EE0 { unsigned char p[0x2c]; struct W7cCtr88666EE0 *sub; unsigned char q[0x74b - 0x30]; unsigned char armed; };
void ts4_arm_and_wrap_counter_88666EE0(struct W7cSelf88666EE0 *s)
{
    s->armed = 1;
    s->sub->c = (s->sub->c + 1 > 6) ? 0 : s->sub->c + 1;
}

/* ---- 0x886C3D50: true when no entry has kind 0, 1 or 2 ---- */
struct W7cItem886C3D50 { volatile int kind; };
struct W7cList886C3D50 { unsigned char p[4]; struct W7cItem886C3D50 **b; struct W7cItem886C3D50 **e; };
unsigned char ts4_none_kind_012_886C3D50(struct W7cList886C3D50 *v)
{
    struct W7cItem886C3D50 **p;
    unsigned char r = 1;
    struct W7cItem886C3D50 **end = v->e;
    for (p = v->b; p != end; p++) {
        struct W7cItem886C3D50 *it = *p;
        if (it->kind == 0 || it->kind == 1 || it->kind == 2) {
            r = 0;
            break;
        }
    }
    return r;
}

/* ---- 0x886E61E0: remove an id from the global id table (swap with last) ---- */
struct W7cTab886E61E0 { unsigned ids[0x31a4 / 4]; unsigned count; };
extern struct W7cTab886E61E0 lbl_88D42948;
void ts4_remove_id_886E61E0(unsigned id)
{
    unsigned i;
    unsigned n = lbl_88D42948.count;
    for (i = 0; i < n; i++) {
        if (lbl_88D42948.ids[i] == id) {
            unsigned last = n - 1;
            lbl_88D42948.count = last;
            lbl_88D42948.ids[i] = lbl_88D42948.ids[last];
            return;
        }
    }
}

/* ---- 0x88660338: clear a byte vector (collapse end to begin), reset two fields ---- */
typedef unsigned int W7cU32;
extern void *fn_88562DC0(void *dst, void *src, W7cU32 n);
typedef struct W7cVec { char *first; char *last; } W7cVec;
static __inline char *w7c_copy(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        W7cU32 n = (W7cU32)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}
struct W7cSelf88660338 { unsigned char p[0x4c]; int f4c; int f50; unsigned char q[0x5a0 - 0x54]; W7cVec v; };
void ts4_clear_vec_88660338(struct W7cSelf88660338 *s)
{
    W7cVec *v = &s->v;
    v->last = w7c_copy(v->last, v->last, v->first);
    s->f4c = 0;
    s->f50 = 0x7fffffff;
}

/* ---- 0x88661950 ---- */
struct W7c88661950_Hdr { int rel; unsigned count; };
struct W7c88661950_A { unsigned char p[0x58]; struct W7c88661950_Hdr h58; unsigned char q[0x64 - 0x60]; struct W7c88661950_Hdr h64; };
struct W7c88661950_Mode { unsigned char p[0x2c]; int mode; };
struct W7c88661950_Env { unsigned char p[0x4c]; struct W7c88661950_Mode *m; };
struct W7c88661950_El { unsigned char p[0x58]; unsigned key; };
struct W7c88661950_Self { unsigned char p[8]; struct W7c88661950_Env *env; unsigned char q[0x2c - 0xc]; struct W7c88661950_A *a; };
int ts4_find_key_88661950(struct W7c88661950_Self *s, unsigned key)
{
    struct W7c88661950_Hdr *h;
    unsigned i;
    int r = -1;
    h = (s->env->m->mode == 2) ? &s->a->h64 : &s->a->h58;
    for (i = 0; i < h->count; i++) {
        struct W7c88661950_El *e = (struct W7c88661950_El *)((char *)h + (i * 0x6c + h->rel));
        if (e->key == key) {
            r = (int)i;
            break;
        }
    }
    return r;
}

/* ---- 0x88666E68 ---- */
struct W7c88666E68_X { unsigned char p[0x345]; unsigned char b345; unsigned char b346; };
struct W7c88666E68_I { void *first; };
struct W7c88666E68_Self { struct W7c88666E68_I *i; unsigned char flag; unsigned char pad[0x14 - 5]; struct W7c88666E68_X *x; };
extern unsigned char ts4_cond_test_88665010(struct W7c88666E68_Self *s);
void ts4_mark_result_88666E68(struct W7c88666E68_Self *s)
{
    if (s->flag != 0 && s->i->first != 0) {
        if (ts4_cond_test_88665010(s))
            s->x->b345 = 1;
        else
            s->x->b346 = 1;
    }
}

/* ---- 0x8865A348 ---- */
typedef unsigned int W7c8865A348_U32;
extern void *fn_88562DC0(void *dst, void *src, W7c8865A348_U32 n);
struct W7c8865A348_Obj;
struct W7c8865A348_Vt { void (*dtor)(struct W7c8865A348_Obj *, int); };
struct W7c8865A348_Obj { struct W7c8865A348_Vt *vt; };
typedef struct W7c8865A348_Vec { struct W7c8865A348_Obj **first; struct W7c8865A348_Obj **last; } W7c8865A348_Vec;
static __inline struct W7c8865A348_Obj **w7c8865A348_copy(struct W7c8865A348_Obj **first, struct W7c8865A348_Obj **last, struct W7c8865A348_Obj **dest)
{
    if (first == last) {
        return dest;
    } else {
        W7c8865A348_U32 n = (W7c8865A348_U32)((char *)last - (char *)first);
        dest = (struct W7c8865A348_Obj **)fn_88562DC0(dest, first, n);
        return (struct W7c8865A348_Obj **)((char *)dest + n);
    }
}
struct W7c8865A348_Self { unsigned char p[8]; W7c8865A348_Vec v; };
void ts4_delete_all_8865A348(struct W7c8865A348_Self *s)
{
    struct W7c8865A348_Obj **p;
    struct W7c8865A348_Obj **end = s->v.last;
    W7c8865A348_Vec *v;
    for (p = s->v.first; p != end; p++) {
        if (*p != 0)
            (*p)->vt->dtor(*p, 1);
    }
    v = &s->v;
    v->last = w7c8865A348_copy(v->last, v->last, v->first);
}

/* ---- 0x886C3978 ---- */
typedef struct W7c886C3978_E10 { unsigned int w[4]; } W7c886C3978_E10;
typedef struct W7c886C3978_E0c { unsigned int w[3]; } W7c886C3978_E0c;
typedef struct W7c886C3978_Vec10 { W7c886C3978_E10 *begin; W7c886C3978_E10 *end; } W7c886C3978_Vec10;
typedef struct W7c886C3978_Vec0c { W7c886C3978_E0c *begin; W7c886C3978_E0c *end; } W7c886C3978_Vec0c;
typedef struct W7c886C3978_Vec04 { unsigned int *begin; unsigned int *end; } W7c886C3978_Vec04;
typedef struct W7c886C3978_Holder {
    unsigned char pad00[0x08];
    W7c886C3978_Vec10 v08;
    unsigned char pad10[4];
    W7c886C3978_Vec0c v14;
    unsigned char pad1c[4];
    W7c886C3978_Vec04 v20;
} W7c886C3978_Holder;

static W7c886C3978_E10 *w7c886C3978_copy10(W7c886C3978_E10 *src, W7c886C3978_E10 *src_end, W7c886C3978_E10 *dest)
{
    int n = (int)((char *)src_end - (char *)src) >> 4;
    for (; n > 0; --n) { *dest = *src; ++src; ++dest; }
    return dest;
}
static W7c886C3978_E0c *w7c886C3978_copy0c(W7c886C3978_E0c *src, W7c886C3978_E0c *src_end, W7c886C3978_E0c *dest)
{
    int n = (int)((char *)src_end - (char *)src) / 12;
    for (; n > 0; --n) { *dest = *src; ++src; ++dest; }
    return dest;
}
static unsigned int *w7c886C3978_copy04(unsigned int *src, unsigned int *src_end, unsigned int *dest)
{
    int n = (int)((char *)src_end - (char *)src) >> 2;
    for (; n > 0; --n) { *dest = *src; ++src; ++dest; }
    return dest;
}
void ts4_clear_three_vectors_886C3978(W7c886C3978_Holder *self)
{
    W7c886C3978_Vec10 *a;
    W7c886C3978_Vec0c *b;
    W7c886C3978_Vec04 *c;
    a = &self->v08;
    a->end = w7c886C3978_copy10(a->end, a->end, a->begin);
    b = &self->v14;
    b->end = w7c886C3978_copy0c(b->end, b->end, b->begin);
    c = &self->v20;
    c->end = w7c886C3978_copy04(c->end, c->end, c->begin);
}

/* ---- 0x88671430 ---- */
typedef unsigned int W7c88671430_U32;
extern void *fn_88562DC0(void *dst, void *src, W7c88671430_U32 n);
extern void ts4_object_finalize(void *p);
extern void fn_8826B328(void *p);
typedef struct W7c88671430_Vec { char *first; char *last; } W7c88671430_Vec;
static __inline char *w7c88671430_copy(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        W7c88671430_U32 n = (W7c88671430_U32)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}
struct W7c88671430_Self {
    unsigned char p0[4]; int f4;
    unsigned char p8[0x18 - 8]; int f18;
    unsigned char p1c[0x28 - 0x1c]; int f28, f2c, f30;
    W7c88671430_Vec v;
};
void ts4_destroy_88671430(struct W7c88671430_Self *s)
{
    W7c88671430_Vec *v;
    ts4_object_finalize((char *)s + 0xf4);
    ts4_object_finalize((char *)s + 0x100);
    ts4_object_finalize((char *)s + 0x10c);
    ts4_object_finalize((char *)s + 0x118);
    fn_8826B328((char *)s + 0xc);
    v = &s->v;
    v->last = w7c88671430_copy(v->last, v->last, v->first);
    s->f30 = 0;
    s->f28 = 0;
    s->f2c = 0;
    s->f18 = 0;
    s->f4 = 0;
}

/* ---- 0x886561E0 ---- */
struct W7c886561E0_Sub;
struct W7c886561E0_Hdr { int rel; unsigned count; };
struct W7c886561E0_P { unsigned char pad[0x48]; struct W7c886561E0_Hdr h; };
struct W7c886561E0_Vt {
    unsigned char pad[0x30];
    unsigned char (*s30)(struct W7c886561E0_Sub *);
    unsigned char pad2[0x48 - 0x34];
    struct W7c886561E0_P *(*s48)(struct W7c886561E0_Sub *, int);
};
struct W7c886561E0_Sub { struct W7c886561E0_Vt *vt; };
struct W7c886561E0_El { int rel; unsigned count; unsigned char pad[0x1c - 8]; };
struct W7c886561E0_Self { unsigned char pad[0x1c]; struct W7c886561E0_Sub sub; unsigned char pad2[0x78 - 0x20]; unsigned f78; };
unsigned char ts4_get_byte_886561E0(struct W7c886561E0_Self *self, int a, unsigned b, unsigned c)
{
    unsigned char r = 0;
    struct W7c886561E0_Sub *sub = &self->sub;
    if (sub->vt->s30(sub) != 0 && self->f78 == c) {
        struct W7c886561E0_P *p = sub->vt->s48(sub, 0);
        int w7c886561E0_pad0 = 0;
        (void)w7c886561E0_pad0;
        if (a < 4 && (unsigned)a < p->h.count) {
            struct W7c886561E0_Hdr *h = &p->h;
            struct W7c886561E0_El *e = (struct W7c886561E0_El *)((char *)h + (a * 0x1c + h->rel));
            if (b < e->count)
                r = *((unsigned char *)e + e->rel + b);
        }
    }
    return r;
}

/* ---- 0x8865ABB0 ---- */
struct W7c8865ABB0_H { int rel; };
struct W7c8865ABB0_C { unsigned char p[0xe8c]; struct W7c8865ABB0_H h; };
struct W7c8865ABB0_B { unsigned char p[0x28]; struct W7c8865ABB0_C *c; };
struct W7c8865ABB0_A { unsigned char p[0x14]; int idx; unsigned char q[0x48-0x18]; struct W7c8865ABB0_B *b; };
struct W7c8865ABB0_O { unsigned char p[4]; struct W7c8865ABB0_A *a; };
static __inline char *el(struct W7c8865ABB0_H *h, int i) { char *e = (char *)h + i * 0x274; return e + h->rel; }
void *ts4_elem_8865ABB0(struct W7c8865ABB0_O *o)
{
    int w7c8865ABB0_pad0 = 0, w7c8865ABB0_pad1 = 0, w7c8865ABB0_pad2 = 0, w7c8865ABB0_pad3 = 0, w7c8865ABB0_pad4 = 0; (void)w7c8865ABB0_pad0; (void)w7c8865ABB0_pad1; (void)w7c8865ABB0_pad2; (void)w7c8865ABB0_pad3; (void)w7c8865ABB0_pad4;
    return el(&o->a->b->c->h, o->a->idx);
}
