/* Swing_DLL.xex 0x8865AF70: reset flag and time of every record */
extern float g_ts4_script_constants[];
typedef struct C1E { char p[0xc]; unsigned char b; float f; } C1E;
typedef struct C1H { int rel; int count; } C1H;
typedef struct C1P { char p[0x10]; C1H h; } C1P;
typedef struct C1S { char p[0x28]; C1P *p28; } C1S;
static __inline C1E *c1_elem(C1H *h, int i) { return (C1E *)((char *)h + (i * 0x70 + h->rel)); }
void ts4_clear_entries_8865AF70(C1S *s)
{
    int op1_pad0 = 0;
    int i;
    int n = s->p28->h.count;
    float z = g_ts4_script_constants[0];
    for (i = 0; i < n; i++) {
        C1E *e = c1_elem(&s->p28->h, i);
        e->b = 0;
        e->f = z;
    }
    (void)op1_pad0;
}

/* from e1.c */
typedef struct E1H { int rel; } E1H;
typedef struct E1O8 { char p[0x24]; E1H h; char p2[0x60 - 0x28]; unsigned w60; unsigned w64; } E1O8;
typedef struct E1P38 { char p[0x1d4]; int mode; } E1P38;
typedef struct E1P4 { char p[0x38]; E1P38 *p38; } E1P4;
typedef struct E1S { char p[4]; E1P4 *p4; E1O8 *o8; } E1S;
typedef struct E1R { char p[0xc]; int a; char p2[0x24 - 0x10]; int b; } E1R;
static __inline E1R *e1_rec(E1H *h) { return (E1R *)((char *)h + h->rel); }
void ts4_select_value_88677380(E1S *s)
{
    unsigned char hi = 0, lo = 0;
    int v;
    s->o8->w60 = s->o8->w64;
    v = e1_rec(&s->o8->h)->a + e1_rec(&s->o8->h)->b;
    switch (s->p4->p38->mode) {
    case 6: if (v >= 8) hi = 1; else if (v >= 4) lo = 1; break;
    case 11: if (v >= 16) hi = 1; else if (v >= 8) lo = 1; break;
    case 21: if (v >= 34) hi = 1; else if (v >= 18) lo = 1; break;
    }
    if (hi) s->o8->w64 = 0xc920ac38u;
    else if (lo) s->o8->w64 = 0x4850af43u;
    else s->o8->w64 = 0x26296dd2u;
}

/* from j2.c */
typedef struct J1H { int rel; int count; int pad; } J1H;
typedef struct J1P { char pad[0x18]; J1H h0; J1H h1; J1H h2; J1H h3; } J1P;
typedef struct J1SubV { void **vt; } J1SubV;
typedef struct J1S { char p0[0x1c]; J1SubV sub; } J1S;
extern void *ts4_memset(void *d, int c, unsigned n);
extern void fn_886562A0(J1S *s, unsigned i);
#define J1VC30(o) (((unsigned char (*)(void *))((o)->vt[0x30 / 4]))(o))
#define J1VC4C(o, a) (((J1P *(*)(void *, int))((o)->vt[0x4c / 4]))(o, a))
static __inline void j1_clear(J1H *h, int k)
{
    int n = h->count;
    void *r = 0;
    if (h->rel != -1) r = (char *)h + h->rel;
    ts4_memset(r, 0, n * k);
}
void ts4_clear_slot_tables_88656B48(J1S *s)
{
    if (J1VC30(&s->sub)) {
        J1P *p = J1VC4C(&s->sub, 0);
        j1_clear(&p->h0, 1);
        j1_clear(&p->h1, 2);
        j1_clear(&p->h2, 4);
        j1_clear(&p->h3, 4);
        fn_886562A0(s, 0);
        fn_886562A0(s, 1);
        fn_886562A0(s, 2);
        fn_886562A0(s, 3);
    }
}

/* from l7.c */
typedef unsigned int L1U32;
extern void *fn_88562DC0(void *dst, void *src, L1U32 n);
extern void fn_8869F510(void *s, void *e);
extern void ts4_registry_dispatch_888860A0(void *p);
extern void ts4_object_finalize(void *p);
extern void ts4_if_call_seq_u32_off60_88269580(void *p);
typedef struct L1Vec { char **first; char **last; } L1Vec;
static __inline char **l1_copy(char **first, char **last, char **dest)
{
    if (first == last) {
        return dest;
    } else {
        L1U32 n = (L1U32)((char *)last - (char *)first);
        dest = (char **)fn_88562DC0(dest, first, n);
        return (char **)((char *)dest + n);
    }
}
typedef struct L1VObj { void **vt; } L1VObj;
typedef struct L1Elem { char p[0x80]; } L1Elem;
typedef struct L1V { char **first; char **last; char *p8; L1Elem *arr; L1U32 n; } L1V;
typedef struct L1F { char fin[0xc]; L1VObj *obj; L1U32 n; } L1F;
typedef struct L1S { char p0[4]; L1V v; char p18[4]; L1F f; char p30[4]; L1U32 w34; } L1S;
void ts4_destroy_container_886A6CF8(L1S *s)
{
    L1V *v;
    L1F *f;
    char **p, **end;
    L1Elem *a;
    end = s->v.last;
    v = &s->v;
    for (p = v->first; p != end; p++) fn_8869F510(s, *p);
    v->last = l1_copy(v->last, v->last, v->first);
    a = v->arr;
    if (a) {
        int n = ((int *)a)[-1];
        L1Elem *q = a + n;
        int i;
        for (i = n - 1; i >= 0; i--) {
            q--;
            ts4_if_call_seq_u32_off60_88269580(q);
        }
        ts4_registry_dispatch_888860A0((char *)a - 4);
    }
    v->arr = 0;
    v->n = 0;
    f = &s->f;
    ts4_object_finalize(f);
    if (f->obj) {
        int c = ((int *)f->obj)[-1];
        if (c != 0) {
            ((void (*)(L1VObj *, int))f->obj->vt[0])(f->obj, 3);
        } else {
            ts4_registry_dispatch_888860A0((char *)f->obj - 4);
        }
    }
    f->obj = 0;
    f->n = 0;
    s->w34 = 0;
}
