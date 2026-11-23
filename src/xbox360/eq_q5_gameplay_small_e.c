/* Q5 equivalent route, batch E: small gameplay functions (0x80+ bytes) proven by
 * tools/fn_equiv.py rather than byte-matched (see the spec's evidence file). Each block
 * names the reason the byte match is out of reach. */
typedef unsigned int u32;
typedef unsigned char u8;

/* ---- 0x886A80F0: run the stroke query (0x886A58F0 on +0x1c) when the state flag of
 * +0x24 is clear and either `force` is set or the counter at +0x40 exceeds 5; else 0.
 * Not byte-matched: LTCG keeps `force` in r4 across ts4_state_flag_8865DA28 (the callee
 * does not write r4). */
typedef struct Q5Stroke { char pad[0x1c]; void *query; char pad20[4]; void *state; char pad28[0x18]; int count; } Q5Stroke;
extern int ts4_state_flag_8865DA28(const char *object);
extern int fn_886A58F0(void *query);

/* Swing_DLL.xex 0x886A80F0 */
/* byte-gap: 28 off; LTCG keeps force in r4 across ts4_state_flag_8865DA28 (the callee does not write r4) */
int ts4_stroke_query_886A80F0(Q5Stroke *self, u8 force)
{
    u8 busy = (u8)ts4_state_flag_8865DA28((const char *)self->state);
    u8 go = (force != 0 || self->count > 5) ? 1 : 0;
    if (!busy && go)
        return fn_886A58F0(self->query);
    return 0;
}

/* ---- 0x886DC610: forward a pending entry to 0x886DBF40, then remove it from the
 * 0x98-byte pending vector by moving the last entry into its place (pop_back).
 * Not byte-matched: LTCG keeps the new end in r4 across the copy (0x886C6660). */
typedef struct Q5Pend98 { char b[0x98]; } Q5Pend98;
typedef struct Q5PendItem { u32 w0; u32 w4; } Q5PendItem;
typedef struct Q5PendSrc { u32 w0; Q5PendItem *item; } Q5PendSrc;
typedef struct Q5PendCfgC { char pad[0xc]; char *pc; } Q5PendCfgC;
typedef struct Q5PendCfg40 { char pad[0x40]; u32 w40; } Q5PendCfg40;
typedef struct Q5PendEnv {
    char pad0[0x10];
    Q5PendCfg40 *cfg;   /* +0x10 */
    char pad14[4];
    Q5PendCfgC *cfg_c;  /* +0x18 */
    char pad1c[0x28c - 0x1c];
    u32 w28c;           /* +0x28c */
} Q5PendEnv;
typedef struct Q5PendList { char pad0[8]; Q5PendEnv *env; char padc[8]; Q5Pend98 *end; } Q5PendList;
extern void fn_886DBF40(void *a, u32 b, void *c, u32 d, int e, u32 f);
extern void ts4_shot_rec_copy_886C6660(Q5Pend98 *dst, const Q5Pend98 *src);

/* Swing_DLL.xex 0x886DC610 */
/* byte-gap: 31 off; LTCG keeps the new end in r4 across the copy */
void ts4_pending_take_886DC610(Q5PendList *self, Q5Pend98 *entry)
{
    Q5PendEnv *env = self->env;
    Q5PendItem *it = ((Q5PendSrc *)entry)->item;
    Q5Pend98 *last;
    fn_886DBF40(&it->w4, it->w4, env->cfg_c->pc + 0x60, env->cfg->w40, -1, env->w28c);
    last = self->end - 1;
    if (entry != last)
        ts4_shot_rec_copy_886C6660(entry, last);
    self->end = last;
}

/* ---- 0x8886FE50: read (+0x58, +0x70, +0x6c) of entry `idx`: 0 is the object itself,
 * 1.. index its 0x84-byte vector (+0x84 begin, +0x88 end); returns 0 when out of range.
 * Not byte-matched: the two copy tails are not merged the same way. */
typedef struct Q5Elem18 { char b[0x18]; } Q5Elem18;
typedef struct Q5Ent84 {
    Q5Elem18 *vb; Q5Elem18 *ve;     /* +0x00/+0x04: 0x18-byte elements */
    char pad8[0x50];
    u32 w58; char pad5c[8]; u32 w64; char pad68[4]; u32 w6c; u32 w70;
    char pad74[0x10];
} Q5Ent84;
typedef struct Q5EntOwner { Q5Ent84 self; Q5Ent84 *begin; Q5Ent84 *end; } Q5EntOwner;

/* Swing_DLL.xex 0x8886FE50 */
/* byte-gap: 30 off; the two copy tails are not merged the same way */
int ts4_entry_info_8886FE50(Q5EntOwner *o, u32 idx, u32 *a, u32 *b, u32 *c)
{
    Q5Ent84 *e;
    if (idx == 0) {
        e = &o->self;
    } else {
        if (idx - 1 >= (u32)(o->end - o->begin))
            return 0;
        e = &o->begin[idx - 1];
    }
    *a = e->w58;
    *b = e->w70;
    *c = e->w6c;
    return 1;
}

/* ---- 0x8888A4E8: start the worker: clear state, create its event (0x8857B6D8), spawn
 * the thread on fn_88889D20 with a 128 KB stack, set it to processor 4 (0x8857B598),
 * then resume it. Not byte-matched: the handle is reused from r3 for the 0x8857B598
 * call instead of reloaded. */
typedef struct Q5Worker { u32 thread; u32 event; u32 w8; u8 bc; char padd[7]; u8 b14; } Q5Worker;
extern u32 fn_8857B6D8(u32 a, u32 b, u32 c, u32 d);
extern char lbl_880DF04C[];
extern void fn_88889D20(void);
extern u32 ts4_loop_call_seq_fn_88563230_88884B20(void *fn, void *arg, void *name, u32 stack);
extern void fn_8857B598(u32 thread, u32 processor);
extern void ts4_resume_thread(u32 thread);

/* Swing_DLL.xex 0x8888A4E8 */
/* byte-gap: 0 off; fn_check reports 0 off, but the notes say the handle is reused from r3 for the 0x8857B598 call; verify with matching.py */
void ts4_worker_start_8888A4E8(Q5Worker *w)
{
    u32 t;
    w->w8 = 0;
    w->bc = 0;
    w->b14 = 0;
    w->event = fn_8857B6D8(0, 0, 0, 0);
    t = ts4_loop_call_seq_fn_88563230_88884B20((void *)fn_88889D20, w, lbl_880DF04C, 0x20000);
    w->thread = t;
    fn_8857B598(t, 4);
    ts4_resume_thread(w->thread);
}

/* ---- 0x888C1910: while active (+0x54), set the target's +0x6c offset to
 * -(+0x58) - (int)(h * constants[0x314] / w) for the owner's (w, h) = (+0x30, +0x34).
 * Not byte-matched: int->float conversion staging. */
typedef struct Q5Dims { char pad[0x30]; int w; int h; } Q5Dims;
typedef struct Q5Tgt { char pad[0x6c]; int off; } Q5Tgt;
typedef struct Q5TgtHolder { char pad[0x10]; Q5Tgt *tgt; } Q5TgtHolder;
typedef struct Q5DimOwner { char pad[0x44]; Q5TgtHolder *holder; char pad48[4]; Q5Dims *dims; } Q5DimOwner;
typedef struct Q5Scroller { char pad[4]; Q5DimOwner *owner; char pad8[0x4c]; u8 active; char pad55[3]; int base; } Q5Scroller;
extern float g_ts4_script_constants[];

/* Swing_DLL.xex 0x888C1910 */
/* byte-gap: 28 off; int->float conversion staging */
void ts4_scroll_offset_888C1910(Q5Scroller *s)
{
    Q5DimOwner *o;
    if (!s->active)
        return;
    o = s->owner;
    o->holder->tgt->off = -s->base -
        (int)((float)o->dims->h * g_ts4_script_constants[0x314 / 4] / (float)o->dims->w);
}

/* ---- 0x888FD948: constructor: 0x88617D88 base, vtable lbl_880DBD08, four 0x3c-byte
 * slots at +0x1c (0x888FA078 each), zeroed window with end 0xfffff, +0x15c = 1.
 * Not byte-matched: loop counter form and zero-store scheduling. */
typedef struct Q5Slot3c { char b[0x3c]; } Q5Slot3c;
typedef struct Q5SlotObj {
    void *vtbl; char base[0x18];
    Q5Slot3c slots[4];      /* +0x1c */
    u32 w10c, w110, w114, w118, end11c, w120, w124, w128;
    char pad12c[0x28];
    u8 b154; char pad155[7];
    u8 b15c;
} Q5SlotObj;
extern void *fn_88617D88(void *self);
extern void fn_888FA078(Q5Slot3c *slot);
extern char lbl_880DBD08[];

/* Swing_DLL.xex 0x888FD948 */
/* byte-gap: 4 off; loop counter form and zero-store scheduling */
Q5SlotObj *ts4_slot_obj_ctor_888FD948(Q5SlotObj *o)
{
    int i;
    fn_88617D88(o);
    o->vtbl = lbl_880DBD08;
    for (i = 0; i < 4; i++)
        fn_888FA078(&o->slots[i]);
    o->w10c = 0;
    o->w110 = 0;
    o->w114 = 0;
    o->w118 = 0;
    o->w120 = 0;
    o->end11c = 0xfffff;
    o->w124 = 0;
    o->w128 = 0;
    o->b154 = 0;
    o->b15c = 1;
    return o;
}

/* ---- 0x8886FED0: sister of 0x8886FE50: for entry `idx` (0 = the object itself) report
 * its element count (0x18-byte vector at +0x0/+0x4), +0x58 and +0x64; an out-of-range
 * index leaves the outputs untouched. Always returns 1. Not byte-matched: tail merging. */

/* Swing_DLL.xex 0x8886FED0 */
/* byte-gap: 31 off; tail merging */
int ts4_entry_counts_8886FED0(Q5EntOwner *o, u32 idx, u32 *a, u32 *b, u32 *count)
{
    Q5Ent84 *e;
    if (idx == 0) {
        e = &o->self;
    } else {
        if (idx - 1 >= (u32)(o->end - o->begin))
            return 1;
        e = &o->begin[idx - 1];
    }
    *count = (u32)(e->ve - e->vb);
    *a = e->w58;
    *b = e->w64;
    return 1;
}

/* ---- 0x88693FA8: randomise the three jitter components (+0x1c4..+0x1cc) in
 * [0, constants[0]] and restart the owner's +0x44 sequence.
 * Not byte-matched: register numbering of the saved bounds. */
typedef struct Q5Rng Q5Rng;
typedef struct Q5Jitter { char pad[0x1c4]; float x, y, z; } Q5Jitter;
typedef struct Q5JitOwner { char pad[0x44]; char seq[1]; } Q5JitOwner;
extern const float lbl_8814B440;    /* 0.0f */
extern float ts4_rng_range_8861E598(Q5Rng *rng, float lo, float hi);
extern void ts4_loop_call_seq_u32_off2c_8890E988(void *seq);

/* Swing_DLL.xex 0x88693FA8 */
/* byte-gap: 8 off; register numbering of the saved bounds */
void ts4_jitter_reset_88693FA8(Q5Jitter *j, Q5JitOwner *o, Q5Rng *rng)
{
    float lo = lbl_8814B440;
    float hi = g_ts4_script_constants[0];
    j->x = ts4_rng_range_8861E598(rng, lo, hi);
    j->y = ts4_rng_range_8861E598(rng, lo, hi);
    j->z = ts4_rng_range_8861E598(rng, lo, hi);
    ts4_loop_call_seq_u32_off2c_8890E988(o->seq);
}
