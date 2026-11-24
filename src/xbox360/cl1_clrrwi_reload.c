/*
 * CL1: gameplay functions whose original copies a register with `clrrwi rD,rS,0`
 * (rlwinm rD,rS,0,0,31). Swing_DLL.xex, Xbox 360, cl.exe 16.00.10224.00, plain route.
 *
 * Rule (docs/agents/near-misses/CL1.md): MSVC emits `clrrwi rD,rS,0` when it removes a
 * redundant load late: a reload of a field that was just stored or loaded, where the early
 * local CSE did not see the two accesses as the same, because the base pointer comes from
 * a different expression (an inline accessor called again, a pointer re-read from memory,
 * a merge of two paths) or because another memory access lies between them. The copy is a
 * 32-bit zero-extension that stands in for the removed lwz. Loads chained off the
 * forwarded value are not CSE'd again; they are reloaded.
 *
 * In source: reach the field a second time through an inline accessor (or after a
 * two-branch store); writing the same expression twice in the same function lets the
 * early CSE reuse the register, with no copy.
 */
#ifdef _MSC_VER
#define CL1_INLINE static __inline
#else
#define CL1_INLINE static inline
#endif

typedef unsigned char cl1_u8;
typedef unsigned int cl1_u32;

/* ---- 0x8865AB58: decrement a counter, report whether it went negative ---- */
struct Cl1Counter { cl1_u32 w0; cl1_u32 w4; int count; /* +0x08 */ };

CL1_INLINE int *cl1_counter_value(struct Cl1Counter *c) { return &c->count; }

/* Swing_DLL.xex 0x8865AB58 */
int ts4_counter_dec_is_negative_8865AB58(struct Cl1Counter *c)
{
    --*cl1_counter_value(c);
    return *cl1_counter_value(c) < 0;
}

/* ---- 0x8865B278: count frames while a flag holds, publish "count > 300" ---- */
struct Cl1FrameFlags { cl1_u8 pad_00[0xF0]; cl1_u8 active; /* +0xF0 */ cl1_u8 over; /* +0xF1 */ };
struct Cl1FrameCounter {
    cl1_u8 pad_00[0x38];
    struct Cl1FrameFlags *flags;          /* +0x38 */
    cl1_u8 pad_3c[0x84 - 0x3C];
    int frames;                           /* +0x84 */
};

/* Swing_DLL.xex 0x8865B278 */
void ts4_frame_counter_update_8865B278(struct Cl1FrameCounter *self)
{
    struct Cl1FrameFlags *f = self->flags;
    if (f->active)
        self->frames++;
    else
        self->frames = 0;
    f->over = self->frames > 300;
}

/* ---- 0x8865A3E8 / 0x8865A410: first and last element of a vector of 0x30-byte records ---- */
struct Cl1Rec30 { cl1_u8 data[0x30]; };
struct Cl1Vec30 { struct Cl1Rec30 *begin; struct Cl1Rec30 *end; };
struct Cl1RecOwner { cl1_u8 pad_000[0x5A0]; struct Cl1Vec30 recs; /* +0x5A0 */ };

CL1_INLINE int cl1_vec30_empty(const struct Cl1Vec30 *v) { return v->begin == v->end; }
CL1_INLINE struct Cl1Rec30 *cl1_vec30_begin(const struct Cl1Vec30 *v) { return v->begin; }
CL1_INLINE struct Cl1Rec30 *cl1_vec30_end(const struct Cl1Vec30 *v) { return v->end; }
CL1_INLINE struct Cl1Rec30 *cl1_vec30_back(const struct Cl1Vec30 *v) { return cl1_vec30_end(v) - 1; }

/* Swing_DLL.xex 0x8865A3E8 */
struct Cl1Rec30 *ts4_last_record_8865A3E8(struct Cl1RecOwner *o)
{
    struct Cl1Rec30 *r = 0;
    if (!cl1_vec30_empty(&o->recs))
        r = cl1_vec30_back(&o->recs);
    return r;
}

/* Swing_DLL.xex 0x8865A410 */
struct Cl1Rec30 *ts4_first_record_8865A410(struct Cl1RecOwner *o)
{
    struct Cl1Rec30 *r = 0;
    if (!cl1_vec30_empty(&o->recs))
        r = cl1_vec30_begin(&o->recs);
    return r;
}

/* ---- 0x886615D0 / 0x8865E7C0: release a registered object by id (last release runs vslot 14) ---- */
struct Cl1ObjVtbl { void (*slot[32])(void *); };
struct Cl1Obj { struct Cl1ObjVtbl *vtbl; };
struct Cl1RegEntry { cl1_u32 w0; int refs; /* +0x04 */ cl1_u32 id; /* +0x08 */ struct Cl1Obj *obj; /* +0x0C */ };
struct Cl1Registry { cl1_u8 pad_00[0xC]; struct Cl1RegEntry *begin; struct Cl1RegEntry *end; };

CL1_INLINE int *cl1_entry_refs(struct Cl1RegEntry *e) { return &e->refs; }

/* Swing_DLL.xex 0x886615D0 */
void ts4_registry_release_886615D0(struct Cl1Registry *self, cl1_u32 *id)
{
    struct Cl1RegEntry *end = self->end;
    struct Cl1RegEntry *e = self->begin;
    cl1_u32 want = *id;
    for (; e != end; e++) {
        if (e->id == want) {
            if (e->obj == 0)
                return;
            --*cl1_entry_refs(e);
            if (*cl1_entry_refs(e) == 0)
                e->obj->vtbl->slot[14](e->obj);
            return;
        }
    }
}

/* Swing_DLL.xex 0x8865E7C0 (same body as 0x886615D0, another registry class) */
void ts4_registry_release_8865E7C0(struct Cl1Registry *self, cl1_u32 *id)
{
    struct Cl1RegEntry *end = self->end;
    struct Cl1RegEntry *e = self->begin;
    cl1_u32 want = *id;
    for (; e != end; e++) {
        if (e->id == want) {
            if (e->obj == 0)
                return;
            --*cl1_entry_refs(e);
            if (*cl1_entry_refs(e) == 0)
                e->obj->vtbl->slot[14](e->obj);
            return;
        }
    }
}

/* ---- 0x8865EE40: consume a pending token when it equals the counter, then publish it ---- */
struct Cl1TokC { cl1_u8 pad_00[0xB0]; int pending; /* +0xB0 */ };
struct Cl1TokB { cl1_u8 pad_00[0x20]; struct Cl1TokC *c; /* +0x20 */ };
struct Cl1TokA { cl1_u8 pad_00[0x5C]; struct Cl1TokB *b; /* +0x5C */ };
struct Cl1TokSrc { cl1_u8 pad_00[0x10]; int token; /* +0x10 */ };
struct Cl1TokDst { cl1_u8 pad_00[0x98]; int token; /* +0x98 */ };
struct Cl1TokOwner {
    cl1_u8 pad_00[0x48];
    struct Cl1TokA *a;                    /* +0x48 */
    cl1_u8 pad_4c[0x74 - 0x4C];
    struct Cl1TokDst *dst;                /* +0x74 */
    cl1_u8 pad_78[0x84 - 0x78];
    struct Cl1TokSrc *src;                /* +0x84 */
};

CL1_INLINE void cl1_tok_consume(struct Cl1TokOwner *s) { s->a->b->c->pending--; }

/* Swing_DLL.xex 0x8865EE40 */
void ts4_token_publish_8865EE40(struct Cl1TokOwner *s)
{
    int token = s->src->token;
    if (token == s->a->b->c->pending)
        cl1_tok_consume(s);
    s->dst->token = token;
}

/* ---- 0x8865BF80: track a running maximum, flag whether it grew this frame ---- */
struct Cl1MaxTrack {
    cl1_u8 pad_00[0x38];
    cl1_u32 current;                      /* +0x38 */
    cl1_u8 pad_3c[0x6C - 0x3C];
    cl1_u32 maximum;                      /* +0x6C */
    cl1_u8 grew;                          /* +0x70 */
};
struct Cl1MaxOwner { cl1_u8 pad_00[0x28]; struct Cl1MaxTrack *track; /* +0x28 */ };

CL1_INLINE void cl1_max_set(struct Cl1MaxOwner *s, cl1_u32 v) { s->track->maximum = v; }

/* Swing_DLL.xex 0x8865BF80 */
void ts4_max_track_update_8865BF80(struct Cl1MaxOwner *s)
{
    cl1_u32 cur = s->track->current;
    if (cur > s->track->maximum) {
        cl1_max_set(s, cur);
        s->track->grew = 1;
    } else {
        s->track->grew = 0;
    }
}

/* ---- 0x8865F0D0: element of a pointer vector at the index held by the match flow ---- */
struct Cl1PtrVec { void **begin; void **end; };
struct Cl1IndexSrc { cl1_u8 pad_00[0x7C]; int index; /* +0x7C */ };
struct Cl1PtrVecOwner {
    cl1_u8 pad_00[0x10];
    struct Cl1PtrVec items;               /* +0x10 */
    cl1_u8 pad_18[0x30 - 0x18];
    struct Cl1IndexSrc *src;              /* +0x30 */
};

CL1_INLINE int cl1_ptrvec_size(const struct Cl1PtrVec *v) { return (int)(v->end - v->begin); }
CL1_INLINE void *cl1_ptrvec_at(const struct Cl1PtrVec *v, int i) { return v->begin[i]; }

/* Swing_DLL.xex 0x8865F0D0 */
void *ts4_current_item_8865F0D0(struct Cl1PtrVecOwner *o)
{
    int i = o->src->index;
    if (i < cl1_ptrvec_size(&o->items))
        return cl1_ptrvec_at(&o->items, i);
    return 0;
}
