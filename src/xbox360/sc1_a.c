/*
 * SC1: constructors / initialisers / destructors whose store schedule depends on
 * the member sub-object structure (see docs/agents/near-misses/SC1.md).
 *
 * Rule used throughout: stores made through an inline helper's pointer
 * parameter (a member sub-object written as `init(&o->member)`) are kept in
 * source order relative to stores through any other pointer, while stores
 * through one and the same pointer are freely reordered by the scheduler. The
 * grouping of member words into such sub-objects therefore fixes the store
 * order and, through the dependence heights, where constants are materialised.
 */

typedef unsigned int Sc1U32;

/* ---- shared: three-word vector and the lbl_880D7600 object (0x44 bytes) ---- */
extern char lbl_880D7600[];
typedef struct Sc1Vec { Sc1U32 *b, *e, *c; } Sc1Vec;
typedef struct Sc1Vec3 { Sc1Vec v0, v1, v2; } Sc1Vec3;
typedef struct Sc1Obj44 {
    void *vt;
    Sc1U32 w04, w08, w0c, w10;
    Sc1Vec3 m;   /* +0x14 */
    Sc1Vec x;    /* +0x38 */
} Sc1Obj44;
static __inline void sc1_vec_init(Sc1Vec *v) { v->b = 0; v->e = 0; v->c = 0; }
static __inline void sc1_vec3_init(Sc1Vec3 *m) { sc1_vec_init(&m->v0); sc1_vec_init(&m->v1); sc1_vec_init(&m->v2); }
static __inline void sc1_obj44_init(Sc1Obj44 *s)
{
    s->vt = lbl_880D7600;
    sc1_vec3_init(&s->m);
    sc1_vec_init(&s->x);
    s->w04 = 0; s->w08 = 0; s->w0c = 0; s->w10 = 0;
}

/* Swing_DLL.xex 0x88695E78: ts4_obj44_pair_owner_ctor_88695E78
 * Owner with five header words and two embedded 0x44 objects. The header words
 * are three sub-objects {2,2,1}; writing them as five scalar stores (or as one
 * 5-word sub-object) materialises the second vtable address too early. */
extern char lbl_880F4650[];
extern void ts4_object_finalize(void *p);
typedef struct Sc1Pair { Sc1U32 a, b; } Sc1Pair;
typedef struct Sc1One { Sc1U32 a; } Sc1One;
static __inline void sc1_pair_init(Sc1Pair *p) { p->a = 0; p->b = 0; }
static __inline void sc1_one_init(Sc1One *p) { p->a = 0; }
typedef struct Sc1Owner88695E78 {
    void *vt;
    Sc1Pair h04;
    Sc1Pair h0c;
    Sc1One h14;
    Sc1Obj44 a;   /* +0x18 */
    Sc1Obj44 b;   /* +0x5c */
} Sc1Owner88695E78;
Sc1Owner88695E78 *ts4_obj44_pair_owner_ctor_88695E78(Sc1Owner88695E78 *o)
{
    o->vt = lbl_880F4650;
    sc1_pair_init(&o->h04);
    sc1_pair_init(&o->h0c);
    sc1_one_init(&o->h14);
    sc1_obj44_init(&o->a);
    sc1_obj44_init(&o->b);
    ts4_object_finalize(&o->h04);
    return o;
}

/* Swing_DLL.xex 0x88668C80: ts4_clear_records_88668C80
 * Clears a self-relative array of 0x134-byte records. Words 3..7 of a record are
 * one sub-object cleared through a helper; as scalar stores the compiler emits
 * words 8..12 after them instead of first. The six dead locals set the
 * function-local numbering for the (index, rel) add order (OP1 rule). */
typedef struct Sc1W5 { int w[5]; } Sc1W5;
static __inline void sc1_w5_init(Sc1W5 *g) { g->w[0] = 0; g->w[1] = 0; g->w[2] = 0; g->w[3] = 0; g->w[4] = 0; }
typedef struct Sc1Rec88668C80 { int w00[3]; Sc1W5 g0c; int w[69]; } Sc1Rec88668C80; /* w[k] is word 8+k */
typedef struct Sc1El88668C80 { char p[5]; unsigned char b5; char p2[2]; } Sc1El88668C80;
typedef struct Sc1H88668C80 { int rel; unsigned cnt; int w08, w0c, w10; unsigned char b14, b15; } Sc1H88668C80;
typedef struct Sc1HA88668C80 { int rel; } Sc1HA88668C80;
typedef struct Sc1B88668C80 { char p[0xc]; Sc1HA88668C80 ha; char p2[0x5c - 0x10]; Sc1H88668C80 h; } Sc1B88668C80;
typedef struct Sc1S88668C80 { char p[0x28]; Sc1B88668C80 *b; } Sc1S88668C80;
void ts4_clear_records_88668C80(Sc1S88668C80 *s)
{
    int pad0 = 0, pad1 = 0, pad2 = 0, pad3 = 0, pad4 = 0, pad5 = 0;
    Sc1B88668C80 *b = s->b;
    Sc1H88668C80 *h = &b->h;
    unsigned i, n = h->cnt;
    for (i = 0; i != n; i++) {
        Sc1Rec88668C80 *r = (Sc1Rec88668C80 *)((char *)h + i * 0x134 + h->rel);
        Sc1HA88668C80 *a = &b->ha;
        Sc1El88668C80 *e;
        r->w[0] = 0;
        r->w[1] = 0;
        r->w[2] = 0;
        r->w[3] = 0;
        r->w[4] = 0;
        r->w[5] = 0;
        r->w[6] = 0;
        r->w[8] = 0;
        r->w[9] = 0;
        r->w[10] = 0;
        sc1_w5_init(&r->g0c);
        r->w[11] = 0;
        r->w[12] = 0;
        r->w[13] = 0;
        r->w[14] = 0;
        r->w[15] = 0;
        r->w[16] = 0;
        r->w[17] = 0;
        r->w[18] = 0;
        r->w[20] = 0;
        r->w[21] = 0;
        r->w[22] = 0;
        r->w[23] = 0;
        r->w[24] = 0;
        r->w[25] = 0;
        r->w[33] = 0;
        r->w[31] = 0;
        r->w[32] = 0;
        r->w[19] = 0;
        r->w[7] = 0;
        e = (Sc1El88668C80 *)((char *)a + i * 8 + a->rel);
        e->b5 = 0;
    }
    h->w0c = 0;
    h->w10 = 0;
    h->b14 = 0;
    h->b15 = 0;
    (void)pad0; (void)pad1; (void)pad2; (void)pad3; (void)pad4; (void)pad5;
}

/* Swing_DLL.xex 0x886B4C10: ts4_owner_dtor_886B4C10
 * Destructor. Owned pointers are freed through `free(&s->member)`: the load
 * through the member pointer stays behind the vtable store. Passing the value
 * (`free(s->member)`) lets the load float above the vtable store. */
extern char lbl_880F434C[];
extern char lbl_880D75FC[];
extern void ts4_destroy_owned_object(void *p);
typedef struct Sc1Sub886B4C10 { void *vt; void *p4; } Sc1Sub886B4C10;
typedef struct Sc1O44 { char p[0x44]; } Sc1O44;
extern void ts4_obj44_dtor_8890F1E8(Sc1O44 *s);
typedef struct Sc1Owner886B4C10 {
    void *vt;
    char p04[0x94 - 4];
    void *p94;
    char p98[0xa0 - 0x98];
    void *pa0;
    char pa4[0xcc - 0xa4];
    Sc1O44 o[9];
    Sc1Sub886B4C10 sub;
    char p338[0x36c - 0x338];
    void *p36c;
    char p370[0x378 - 0x370];
    void *p378;
    char p37c[0x388 - 0x37c];
    void *p388;
} Sc1Owner886B4C10;
static __inline void sc1_free_owned(void **pp) { if (*pp) ts4_destroy_owned_object(*pp); }
static __inline void sc1_sub_dtor(Sc1Sub886B4C10 *q) { q->vt = lbl_880D75FC; sc1_free_owned(&q->p4); }
void ts4_owner_dtor_886B4C10(Sc1Owner886B4C10 *s)
{
    s->vt = lbl_880F434C;
    sc1_free_owned(&s->p388);
    sc1_free_owned(&s->p378);
    sc1_free_owned(&s->p36c);
    sc1_sub_dtor(&s->sub);
    ts4_obj44_dtor_8890F1E8(&s->o[8]);
    ts4_obj44_dtor_8890F1E8(&s->o[7]);
    ts4_obj44_dtor_8890F1E8(&s->o[6]);
    ts4_obj44_dtor_8890F1E8(&s->o[5]);
    ts4_obj44_dtor_8890F1E8(&s->o[4]);
    ts4_obj44_dtor_8890F1E8(&s->o[3]);
    ts4_obj44_dtor_8890F1E8(&s->o[2]);
    ts4_obj44_dtor_8890F1E8(&s->o[1]);
    ts4_obj44_dtor_8890F1E8(&s->o[0]);
    sc1_free_owned(&s->pa0);
    sc1_free_owned(&s->p94);
}

/* Swing_DLL.xex 0x88646FD0: ts4_alloc_item_88646FD0
 * Allocates a 0x14-byte item and initialises it. The three trailing words are a
 * sub-object with its own init; as scalar stores the zero is materialised first
 * and the +8 store moves ahead of the header. */
typedef struct Sc1ItemTail { int w8; int wc; unsigned w10; } Sc1ItemTail;
typedef struct Sc1Item { void *vt; unsigned short sz; unsigned short kind; Sc1ItemTail t; } Sc1Item;
typedef struct Sc1ItemOut { Sc1Item *p; unsigned w4; } Sc1ItemOut;
static __inline void sc1_item_tail_init(Sc1ItemTail *t) { t->w8 = 0; t->wc = 0; t->w10 = 0x80000000; }
extern unsigned int lbl_88CACF08;
extern char lbl_88089574[];
extern char lbl_88CACC08[];
void *KeTlsGetValue(unsigned int index);
Sc1Item *fn_8841A510(void *allocator, int size, int kind);
extern unsigned ts4_get_u32_lbl_88D26F84_884CE818(Sc1Item *p, void *a);
extern unsigned ts4_get_u32_off0_8841EAC8(void *p);
extern unsigned fn_884CCC70(unsigned a, unsigned b, int c);
void ts4_alloc_item_88646FD0(Sc1ItemOut *out, void *arg)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Sc1Item *p = fn_8841A510(allocator, 0x14, 6);
    unsigned a;
    p->sz = 0x14;
    p->vt = lbl_88089574;
    p->kind = 1;
    sc1_item_tail_init(&p->t);
    out->p = p;
    a = ts4_get_u32_lbl_88D26F84_884CE818(p, arg);
    out->w4 = fn_884CCC70(a, ts4_get_u32_off0_8841EAC8(lbl_88CACC08), 0);
}
