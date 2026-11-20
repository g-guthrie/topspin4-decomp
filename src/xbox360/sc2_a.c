/*
 * SC2: store scheduling through pointer values (see docs/agents/near-misses/SC2.md).
 *
 * The scheduler reorders memory accesses only when they go through one and the
 * same pointer value. A store written through a block-local pointer to the
 * member (`{ T *p = &o->m; *p = v; }`) is kept in source order relative to the
 * accesses through `o`, even though the store itself is re-based onto `o`.
 */

typedef unsigned int Sc2U32;

/* Swing_DLL.xex 0x88677C38: ts4_set_event_ids_88677C38
 * Writes three event ids into a self-relative id table and notifies the owner.
 * The +0x10 id is stored through a local pointer to the member, which keeps it
 * ahead of the table's `rel` load; written as `h->f10 = ...` the load is
 * scheduled first. */
struct Sc2S88677C38;
typedef struct Sc2Vt88677C38 { char pad[0x3c]; void (*f3c)(struct Sc2S88677C38 *); } Sc2Vt88677C38;
typedef struct Sc2H88677C38 { int rel; char pad[0xc - 4]; Sc2U32 fc; Sc2U32 f10; } Sc2H88677C38;
typedef struct Sc2X88677C38 { char pad[0x48]; Sc2H88677C38 h; } Sc2X88677C38;
typedef struct Sc2Y88677C38 { char pad[0x37c]; unsigned char f37c; } Sc2Y88677C38;
typedef struct Sc2Z88677C38 { char pad[0x44]; Sc2X88677C38 *x44; char p2[0x4c - 0x48]; Sc2Y88677C38 *y4c; } Sc2Z88677C38;
typedef struct Sc2S88677C38 { Sc2Vt88677C38 *vt; Sc2Z88677C38 *p4; } Sc2S88677C38;
void ts4_set_event_ids_88677C38(Sc2S88677C38 *s)
{
    Sc2H88677C38 *h = &s->p4->x44->h;
    Sc2U32 zero = 0;
    { Sc2U32 *p = &h->f10; *p = 0x23baed9e; }
    h->fc = zero;
    *(Sc2U32 *)((char *)h + h->rel) = zero;
    ((Sc2U32 *)((char *)h + h->rel))[2] = zero;
    ((Sc2U32 *)((char *)h + h->rel))[1] = 0x317c51b7;
    ((Sc2U32 *)((char *)h + h->rel))[3] = 0xa2eda1e7;
    s->vt->f3c(s);
    s->p4->y4c->f37c = 1;
}

/* Swing_DLL.xex 0x88658E40: ts4_construct_manager_88658E40
 * Manager constructor that registers itself in lbl_88D45B08. Words +0x44/+0x48
 * are one sub-object (own init helper) and +0x24 is stored through a local
 * member pointer: that chains the stores, so the global's `lis` is materialised
 * late and the +0x24 store follows the flag bytes, as in the target. */
extern const char lbl_880F5170[];
extern const char lbl_880D1F0C[];
extern struct Sc2Mgr88658E40 *lbl_88D45B08;
extern void fn_88617D88(void *self);
extern void ts4_call_seq_fn_88617D88_8892AFF0(void *self);
extern void RtlInitializeCriticalSection(void *cs);
typedef struct Sc2Pair88658E40 { Sc2U32 w[2]; } Sc2Pair88658E40;
static __inline void sc2_pair_init_88658E40(Sc2Pair88658E40 *g) { g->w[0] = 0; g->w[1] = 0; }
typedef struct Sc2Mgr88658E40 {
    const char *vtbl;                 /* 0x00 */
    unsigned char pad04[0x18];
    Sc2U32 w1c;                       /* 0x1c */
    unsigned char b20, b21, b22, pad23;
    const char *w24;
    unsigned char crit[0x1c];         /* 0x28 */
    Sc2Pair88658E40 g44;              /* 0x44 */
    Sc2U32 w4c, w50;
    unsigned char sub54[0x54];        /* 0x54 */
    Sc2U32 wa8, wac, wb0;
} Sc2Mgr88658E40;
Sc2Mgr88658E40 *ts4_construct_manager_88658E40(Sc2Mgr88658E40 *self)
{
    fn_88617D88(self);
    self->vtbl = lbl_880F5170;
    self->b20 = 0;
    self->b21 = 0;
    self->b22 = 0;
    { const char **n = &self->w24; *n = lbl_880D1F0C; }
    sc2_pair_init_88658E40(&self->g44);
    self->w4c = 0;
    lbl_88D45B08 = self;
    self->w50 = 0;
    ts4_call_seq_fn_88617D88_8892AFF0(self->sub54);
    self->wa8 = 0;
    self->wac = 0;
    self->wb0 = 0;
    self->w1c = 0;
    RtlInitializeCriticalSection(self->crit);
    return self;
}
