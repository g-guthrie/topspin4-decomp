extern void fn_8890DDA8(void *);
struct W11M { char pad[0x44]; };
struct W11Sub { char pad0[0xc]; struct W11M a; struct W11M b; struct W11M c; };
struct W11D {
    char pad00[0x14];
    unsigned w14, w18;
    char pad1c[0x38 - 0x1c];
    struct W11Sub sub;
    char pad_x[0x158 - 0x38 - sizeof(struct W11Sub)];
    struct W11M m158, m19c, m1e0, m224;
};
static __inline void w11_sub_fini(struct W11Sub *s)
{
    fn_8890DDA8(&s->c);
    fn_8890DDA8(&s->b);
    fn_8890DDA8(&s->a);
}
void ts4_destroy_members_88678A10(struct W11D *d)
{
    fn_8890DDA8(&d->m224);
    fn_8890DDA8(&d->m1e0);
    fn_8890DDA8(&d->m19c);
    fn_8890DDA8(&d->m158);
    w11_sub_fini(&d->sub);
    d->w18 = 0;
    d->w14 = 0;
}

/* 0x88661A70: finalize the object, then clear its 8-byte-element vector (erase-all through the copy loop) */
typedef unsigned long long W11u64;
extern void ts4_object_finalize(void *);
typedef struct W11V { W11u64 *first; W11u64 *last; } W11V;
static __inline W11u64 *w11_copy(W11u64 *f, W11u64 *l, W11u64 *d)
{
    int n = l - f;
    for (; 0 < n; --n) { *d = *f; ++d; ++f; }
    return d;
}
struct W11VO { unsigned char p[0xc]; W11V v; };
void ts4_finalize_and_clear_88661A70(struct W11VO *o)
{
    W11V *v;
    ts4_object_finalize(o);
    v = &o->v;
    v->last = w11_copy(v->last, v->last, v->first);
}

/* 0x889C0940: fetch a u32 through the callee; store and report success when it is nonzero */
extern unsigned ts4_if_call_seq_u32_off38_8864B468(void *self);
int ts4_get_u32_889C0940(void *self, unsigned *out)
{
    unsigned v = ts4_if_call_seq_u32_off38_8864B468(self);
    int ok;
    if (v != 0) { ok = 1; *out = v; } else ok = 0;
    return ok;
}

/* 0x886CF6B0: allocate and zero a table of seven 8-byte entries */
typedef unsigned int W11u32;
extern void *lbl_88D45B38;
extern void *ts4_node_dispatch_with_target_88613268(void *heap, W11u32 size, W11u32 alignment, W11u32 flags, W11u32 pool);
typedef struct W11E { W11u32 a, b; } W11E;
struct W11A { W11E *p; int n; int w8; };
void ts4_init_table_886CF6B0(struct W11A *s, int x)
{
    W11E *p;
    W11E *e;
    W11E *end;
    int i;
    s->w8 = x;
    p = (W11E *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x3c, 4, 0, 2);
    if (p != 0) { W11E *q = p; for (i = 7; 0 < i; --i) { q->b = 0; ++q; } } else p = 0;
    s->p = p;
    s->n = 7;
    end = p + 7;
    for (e = p; e != end; e++) {
        e->a = 0;
        e->b = 0;
    }
}
