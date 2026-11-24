/* Ball/effect helpers: name-hash table fill, ramp ctor, idle predicate, range reset.
 * All functions here byte-match on the LTCG route (/Oc); see work/specs/Q5S/q5s_ball_misc.json. */
typedef unsigned int u32;
#ifdef _MSC_VER
typedef unsigned int q5_uptr;
#else
typedef unsigned long q5_uptr;
#define __forceinline inline
#endif
typedef struct Ts4BallF3 { float x, y, z; } Ts4BallF3;

/* Swing_DLL.xex 0x888AF0A8: for each (value,key) name pair, table[hash36(key)] = hash22(value).
 * Names are self-relative strings (-1 means the empty string lbl_880C1320). */
extern const char lbl_880C1320[];
u32 ts4_hash_table_index36_888AF028(const char *name);
u32 ts4_hash_table_index22_888AEFA8(const char *name);
typedef struct Ts4RelStr { int off; } Ts4RelStr;
typedef struct Ts4NamePair { Ts4RelStr val; Ts4RelStr key; } Ts4NamePair;
typedef struct Ts4RelPairArr { int off; int count; } Ts4RelPairArr;
typedef struct Ts4NameMapSrc { char pad[0xf8]; Ts4RelPairArr items; } Ts4NameMapSrc;
typedef struct Ts4NameMapDst { char pad[0x80]; u32 *table; } Ts4NameMapDst;
static const char *ts4_relstr(Ts4RelStr *p) { return p->off != -1 ? p->off + (char *)p : lbl_880C1320; }
static Ts4NamePair *ts4_relpair_at(Ts4RelPairArr *a, int i) { return (Ts4NamePair *)((char *)a + i * 8 + a->off); }
void ts4_name_map_fill_888AF0A8(Ts4NameMapDst *self, Ts4NameMapSrc *s)
{
    int n = s->items.count;
    int i;
    for (i = 0; i < n; i++) {
        Ts4NamePair *e = ts4_relpair_at(&s->items, i);
        u32 k = ts4_hash_table_index36_888AF028(ts4_relstr(&e->key));
        self->table[k] = ts4_hash_table_index22_888AEFA8(ts4_relstr(&e->val));
    }
}

/* Swing_DLL.xex 0x8887DA38: ramp constructor (vtable 0x880DF824, rate 100, limit 0.016). */
extern const char lbl_880DF824[];
typedef struct Ts4RampTail { u32 w14; unsigned char b18; char pad19[3]; u32 w[7]; } Ts4RampTail;
typedef struct Ts4Ramp { const void *vt; float rate; u32 enabled; float limit; u32 pad10; Ts4RampTail t; } Ts4Ramp;
static __forceinline void ts4_ramp_tail_init(Ts4RampTail *t)
{
    t->w14 = 0; t->b18 = 0;
    t->w[0] = 0; t->w[1] = 0; t->w[2] = 0; t->w[3] = 0; t->w[4] = 0; t->w[5] = 0; t->w[6] = 0;
}
void ts4_ramp_ctor_8887DA38(Ts4Ramp *r)
{
    r->vt = lbl_880DF824;
    r->enabled = 1;
    r->rate = 100.0f;
    r->limit = 0.016f;
    ts4_ramp_tail_init(&r->t);
}

/* Swing_DLL.xex 0x888ADFC0: virtual +0x1c predicate and both handles unset. */
typedef struct Ts4BallHnd { int a; u32 b; u32 c; } Ts4BallHnd;
struct Ts4BallPredObj;
typedef unsigned char (*Ts4BallPred)(struct Ts4BallPredObj *);
typedef struct Ts4BallPredObj { void **vt; char pad[0x7c]; Ts4BallHnd h0; Ts4BallHnd h1; } Ts4BallPredObj;
static __inline unsigned char ts4_hnd_unset(const Ts4BallHnd *h) { return h->a == 0 || h->b == 0xfffff; }
unsigned char ts4_ball_is_idle_888ADFC0(Ts4BallPredObj *self)
{
    return ((Ts4BallPred)self->vt[0x1c / 4])(self) && ts4_hnd_unset(&self->h0) && ts4_hnd_unset(&self->h1);
}

/* Swing_DLL.xex 0x888AF1D8: reset ranges from the linked record (lo scaled by 0.75 unless alt). */
typedef struct Ts4BallRangeRec { int pad0; Ts4BallF3 a, b, c; float lo; float hi; char p30[0x66]; unsigned char b96; } Ts4BallRangeRec;
typedef struct Ts4BallRangeOwner {
    char p0[8]; int link; Ts4BallF3 a, b, c; float w; unsigned char d0, d1, d2, d3;
    char p38[0x44]; unsigned char alt; char p7d[0x37]; u32 fb4;
} Ts4BallRangeOwner;
static Ts4BallRangeRec *ts4_range_rec(int *o) { return (Ts4BallRangeRec *)(*o + (char *)o); }
static __inline void ts4_ball_cp3(Ts4BallF3 *d, const Ts4BallF3 *s) { d->x = s->x; d->y = s->y; d->z = s->z; }
void ts4_ball_reset_ranges_888AF1D8(Ts4BallRangeOwner *s)
{
    Ts4BallRangeRec *r;
    if (s->link == 0)
        return;
    s->fb4 = 0;
    r = ts4_range_rec((int *)(q5_uptr)s->link);
    r->b96 = 0;
    ts4_ball_cp3(&s->a, &r->a);
    ts4_ball_cp3(&s->b, &r->b);
    ts4_ball_cp3(&s->c, &r->c);
    if (s->alt)
        s->w = r->hi;
    else
        s->w = r->lo * 0.75f;
    s->d0 = 1; s->d1 = 1; s->d2 = 1; s->d3 = 1;
}
