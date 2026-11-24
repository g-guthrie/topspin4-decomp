/* DA1: constructors, destructors and resets written as nested inline sub-object helpers (plain route, /Oc).
 *
 * The dead `addi rX,rObj,K` of a member address comes from an inline helper whose pointer parameter is used
 * for two or more things, at least one of them a derived address (`&p->member` passed to a deeper inline helper,
 * or `p->m4` passed as a value). The address is computed into a register, the memory accesses are later
 * re-based onto the parent pointer, and the add is left dead (or kept as the base of a value add).
 * Notes: docs/agents/near-misses/DA1.md.
 */

typedef unsigned int Da1U32;

extern char lbl_880D7600[];
extern char lbl_880F37A0[];
extern char lbl_880F4428[];
extern char lbl_880F444C[];
extern char lbl_880F4E2C[];
extern char lbl_880F58D8[];
extern void *lbl_88D45AF0;
extern void ts4_destroy_owned_object(void *p);
extern void ts4_object_finalize(void *p);
extern void fn_88262730(void *p);
extern void ts4_vec12_move_tail_88161620(void *p);
extern unsigned *fn_88268500(unsigned *a, unsigned *b, unsigned *c);
extern void ts4_loop_get_u32_off0_882666E0(unsigned *p, unsigned *e);
extern void *fn_88617D88(void *self);

/* ---- shared: three-word vector and the lbl_880D7600 object (0x44 bytes) ---- */
typedef struct Da1Vec { Da1U32 *b, *e, *c; } Da1Vec;
typedef struct Da1Vec3 { Da1Vec v0, v1, v2; } Da1Vec3;
typedef struct Da1Obj44 {
    void *vt;
    Da1U32 w04, w08, w0c, w10;
    Da1Vec3 m;   /* +0x14 */
    Da1Vec x;    /* +0x38 */
} Da1Obj44;

static __inline void da1_vec_init(Da1Vec *v) { v->b = 0; v->e = 0; v->c = 0; }
static __inline void da1_vec3_init(Da1Vec3 *m) { da1_vec_init(&m->v0); da1_vec_init(&m->v1); da1_vec_init(&m->v2); }
static __inline void da1_obj44_init(Da1Obj44 *s)
{
    s->vt = lbl_880D7600;
    da1_vec3_init(&s->m);
    da1_vec_init(&s->x);
    s->w04 = 0; s->w08 = 0; s->w0c = 0; s->w10 = 0;
}
static __inline void da1_vec_free(Da1Vec *v) { if (v->b) ts4_destroy_owned_object(v->b); }
static __inline void da1_vec3_free(Da1Vec3 *m) { da1_vec_free(&m->v2); da1_vec_free(&m->v1); da1_vec_free(&m->v0); }

/* Swing_DLL.xex 0x8890ED08: ts4_obj44_ctor_8890ED08 */
void ts4_obj44_ctor_8890ED08(Da1Obj44 *s)
{
    da1_obj44_init(s);
}

/* Swing_DLL.xex 0x8890F1E8: ts4_obj44_dtor_8890F1E8 */
void ts4_obj44_dtor_8890F1E8(Da1Obj44 *s)
{
    s->vt = lbl_880D7600;
    da1_vec_free(&s->x);
    da1_vec3_free(&s->m);
}

/* Swing_DLL.xex 0x88695D78: ts4_obj44_pair_ctor_88695D78 */
typedef struct Da1Pair88695D78 { Da1Obj44 a, b; } Da1Pair88695D78;
void ts4_obj44_pair_ctor_88695D78(Da1Pair88695D78 *t)
{
    da1_obj44_init(&t->a);
    da1_obj44_init(&t->b);
}

/* Swing_DLL.xex 0x88695400: ts4_obj44_triple_ctor_88695400 */
typedef struct Da1Triple88695400 { Da1Obj44 a0, a44, a88; Da1U32 wcc; } Da1Triple88695400;
void ts4_obj44_triple_ctor_88695400(Da1Triple88695400 *o)
{
    da1_obj44_init(&o->a0);
    da1_obj44_init(&o->a44);
    da1_obj44_init(&o->a88);
    o->wcc = 0;
}

/* Swing_DLL.xex 0x88695FB8: ts4_obj44_holder_ctor_88695FB8 */
typedef struct Da1Holder88695FB8 { void *vt; Da1Obj44 sub; } Da1Holder88695FB8;
void ts4_obj44_holder_ctor_88695FB8(Da1Holder88695FB8 *o)
{
    o->vt = lbl_880F4E2C;
    da1_obj44_init(&o->sub);
}

/* Swing_DLL.xex 0x886A0408: ts4_obj44_holder_ctor_886A0408 */
typedef struct Da1Holder886A0408 { void *vt; Da1U32 w04; Da1Obj44 sub; } Da1Holder886A0408;
void ts4_obj44_holder_ctor_886A0408(Da1Holder886A0408 *c)
{
    c->vt = lbl_880F444C;
    da1_obj44_init(&c->sub);
    c->w04 = 0;
}

/* Swing_DLL.xex 0x886A04C8: ts4_obj44_array_ctor_886A04C8 */
typedef struct Da1Array886A04C8 { void *vt; Da1U32 w04; Da1Obj44 s[4]; } Da1Array886A04C8;
void ts4_obj44_array_ctor_886A04C8(Da1Array886A04C8 *a)
{
    Da1Obj44 *q = a->s;
    int i;
    a->vt = lbl_880F4428;
    for (i = 4; i != 0; i--) {
        da1_obj44_init(q);
        q++;
    }
    a->w04 = 0;
}

/* Swing_DLL.xex 0x886D50F8: ts4_clear_vec_block_886D50F8 */
typedef struct Da1Blk886D50F8 { Da1U32 w00; Da1Vec v0, v1, v2; } Da1Blk886D50F8;
typedef struct Da1S886D50F8 { Da1U32 w00, w04, w08, w0c, w10; Da1Blk886D50F8 blk; } Da1S886D50F8;
static __inline void da1_blk_init_886D50F8(Da1Blk886D50F8 *s)
{
    da1_vec_init(&s->v0); da1_vec_init(&s->v1); da1_vec_init(&s->v2);
}
void ts4_clear_vec_block_886D50F8(Da1S886D50F8 *s)
{
    s->w08 = 0;
    da1_blk_init_886D50F8(&s->blk);
    s->w00 = 0; s->w04 = 0; s->w0c = 0; s->w10 = 0;
}

/* Swing_DLL.xex 0x886D32A0: ts4_construct_singleton_886D32A0 */
typedef struct Da1Flags886D32A0 { Da1U32 w40; unsigned char enabled; char pad45[3]; Da1U32 w48; } Da1Flags886D32A0;
typedef struct Da1Tail886D32A0 {
    Da1U32 w28;
    unsigned char b2c, b2d;
    char pad2e[2];
    Da1U32 w30, w34, w38, w3c;
    Da1Flags886D32A0 flags;   /* +0x40 */
} Da1Tail886D32A0;
typedef struct Da1Single886D32A0 {
    void *vt;
    Da1Vec v04, v10, v1c;
    Da1Tail886D32A0 tail;     /* +0x28 */
} Da1Single886D32A0;
static __inline void da1_flags_init_886D32A0(Da1Flags886D32A0 *f) { f->w40 = 0; f->w48 = 0; f->enabled = 1; }
static __inline void da1_tail_init_886D32A0(Da1Tail886D32A0 *t)
{
    t->b2c = 0; t->b2d = 0;
    t->w30 = 0; t->w34 = 0; t->w38 = 0; t->w3c = 0;
    t->w28 = 0;
    da1_flags_init_886D32A0(&t->flags);
}
Da1Single886D32A0 *ts4_construct_singleton_886D32A0(Da1Single886D32A0 *s)
{
    s->vt = lbl_880F37A0;
    da1_vec_init(&s->v04); da1_vec_init(&s->v10); da1_vec_init(&s->v1c);
    da1_tail_init_886D32A0(&s->tail);
    lbl_88D45AF0 = s;
    return s;
}

/* Swing_DLL.xex 0x886D8020: ts4_destroy_three_886D8020 */
typedef struct Da1Slot886D8020 { Da1U32 w0; void *p; Da1U32 w8; } Da1Slot886D8020;
typedef struct Da1Slots886D8020 { Da1Slot886D8020 e0, e1, e2; } Da1Slots886D8020;
typedef struct Da1O886D8020 { unsigned char pad[0x14]; Da1Slots886D8020 slots; } Da1O886D8020;
static __inline void da1_slot_free_886D8020(Da1Slot886D8020 *e) { if (e->p) ts4_destroy_owned_object(e->p); }
static __inline void da1_slots_free_886D8020(Da1Slots886D8020 *s)
{
    da1_slot_free_886D8020(&s->e2);
    da1_slot_free_886D8020(&s->e1);
    da1_slot_free_886D8020(&s->e0);
}
void ts4_destroy_three_886D8020(Da1O886D8020 *o)
{
    da1_slots_free_886D8020(&o->slots);
}

/* Swing_DLL.xex 0x8864F5B0: ts4_ctor_range_8864F5B0 */
typedef struct Da1Range8864F5B0 { Da1U32 lo, hi, n; } Da1Range8864F5B0;
typedef struct Da1O8864F5B0 { void *vt; unsigned char pad04[0x18]; Da1Range8864F5B0 range; } Da1O8864F5B0;
static __inline void da1_range_reset_8864F5B0(Da1Range8864F5B0 *r) { r->lo = 0; r->n = 0; r->hi = 0xfffff; }
static __inline void da1_range_init_8864F5B0(Da1Range8864F5B0 *r) { r->lo = 0; r->hi = 0xfffff; r->n = 0; }
Da1O8864F5B0 *ts4_ctor_range_8864F5B0(Da1O8864F5B0 *o)
{
    fn_88617D88(o);
    o->vt = lbl_880F58D8;
    da1_range_init_8864F5B0(&o->range);
    da1_range_reset_8864F5B0(&o->range);
    return o;
}

/* Swing_DLL.xex 0x886D0E20: ts4_reset_state_886D0E20 */
typedef struct Da1V886D0E20 { unsigned *begin; unsigned *end; unsigned *cap; } Da1V886D0E20;
typedef struct Da1S58886D0E20 { int w0; unsigned char m4[4]; unsigned char pad8[0x18 - 8]; int w18; } Da1S58886D0E20;
typedef struct Da1H886D0E20 {
    unsigned char pad00[0x20]; int w20;
    unsigned char pad24[0x34 - 0x24]; unsigned char s34[0xc]; unsigned char s40[0xc];
    unsigned char s4c[0x58 - 0x4c];
    Da1S58886D0E20 s58;   /* +0x58; w18 is +0x70 */
    unsigned char s74[4]; int w78, w7c;
    unsigned char pad80[0x88 - 0x80]; int w88, w8c;
    unsigned char pad90[0xd4 - 0x90];
    Da1V886D0E20 v;
    int we0, we4, we8;
} Da1H886D0E20;
static __inline void da1_clear_886D0E20(Da1V886D0E20 *v)
{
    unsigned *p = fn_88268500(v->end, v->end, v->begin);
    ts4_loop_get_u32_off0_882666E0(p, v->end);
    v->end = p;
}
static __inline void da1_fin_886D0E20(Da1S58886D0E20 *s) { ts4_object_finalize(s->m4); s->w18 = 0; }
void ts4_reset_state_886D0E20(Da1H886D0E20 *s)
{
    s->w88 = 0;
    fn_88262730(s->s74);
    s->w8c = 0; s->w78 = 0; s->w7c = 0;
    ts4_object_finalize(s->s4c);
    ts4_vec12_move_tail_88161620(s->s34);
    ts4_vec12_move_tail_88161620(s->s40);
    s->we0 = 0; s->we4 = 0; s->we8 = 0;
    da1_clear_886D0E20(&s->v);
    da1_fin_886D0E20(&s->s58);
    s->w20 = 0;
}
