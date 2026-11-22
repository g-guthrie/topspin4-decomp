/* Q5 gameplay small functions closed by the equivalence route (fn_equiv).
 * See work/specs/Q5/eq_q5_gameplay_small_c.json and its .equiv.json evidence. */
typedef unsigned int u32;
typedef unsigned char u8;

/* ---- 0x888CB9D0: value of the cursor's current slot in a self-relative bank.
 * bank->groups and bank->items are self-relative offsets; a group holds a
 * self-relative index array mapping slots to items. Not byte-matched: register
 * allocation and load order differ (perm_auto best 18 after 865 candidates). */
typedef struct Q5BankRel { int off; } Q5BankRel;
typedef struct Q5BankItem { char pad0[0x1c]; u32 value; } Q5BankItem;          /* 0x20 bytes */
typedef struct Q5BankGroup { Q5BankRel slots; char pad4[0xc]; } Q5BankGroup;   /* 0x10 bytes */
typedef struct Q5Bank {
    char pad0[0x44];
    Q5BankRel items;    /* +0x44 */
    char pad48[8];
    Q5BankRel groups;   /* +0x50 */
} Q5Bank;
typedef struct Q5BankCursor { char pad0[0x220]; u32 group; u32 slot; } Q5BankCursor;
typedef struct Q5BankOwner { char pad0[0x200]; Q5BankCursor *cur; Q5Bank *bank; } Q5BankOwner;

static Q5BankGroup *q5_bank_group(Q5BankRel *r, u32 i) { return (Q5BankGroup *)(r->off + (char *)r) + i; }
static u32 q5_bank_slot(Q5BankRel *r, u32 i) { return ((u32 *)(r->off + (char *)r))[i]; }
static Q5BankItem *q5_bank_item(Q5BankRel *r, u32 i) { return (Q5BankItem *)(r->off + (char *)r) + i; }

/* Swing_DLL.xex 0x888CB9D0 */
u32 ts4_bank_cursor_value_888CB9D0(Q5BankOwner *self)
{
    Q5BankCursor *c = self->cur;
    Q5Bank *b = self->bank;
    Q5BankGroup *g = q5_bank_group(&b->groups, c->group);
    return q5_bank_item(&b->items, q5_bank_slot(&g->slots, c->slot))->value;
}

/* ---- 0x888E9840: restore a keyed record's saved value and clear script
 * property B1CA7E98 on the object. Not byte-matched: the target copies obj to
 * r31 before the key's home-slot store (2 instructions off in every form tried). */
typedef struct Q5SavedRec { u8 pad[0x24]; u32 current; u32 saved; } Q5SavedRec;
extern void *ts4_hash_find_null_888E1D40(void);
extern Q5SavedRec *ts4_find_record_by_key_881877A8(void *tbl, u32 *key);
extern void ts4_clear_script_prop_B1CA7E98_888C8190(void *obj);

/* Swing_DLL.xex 0x888E9840 */
void ts4_restore_record_and_clear_prop_888E9840(void *obj, u32 key)
{
    Q5SavedRec *r = ts4_find_record_by_key_881877A8(ts4_hash_find_null_888E1D40(), &key);
    if (r) {
        r->current = r->saved;
        ts4_clear_script_prop_B1CA7E98_888C8190(obj);
    }
}

/* ---- 0x88649298: shaper apply over a self-relative point array (sister of
 * 0x88649C10). Not byte-matched: the target keeps `gain` in volatile f1 across
 * the calls (LTCG knowledge of the callees); we spill it to f31. */
struct W8dRel_886491E8 { int off; int count; };
typedef struct Q5Pt3 { float x, y, z; } Q5Pt3;
typedef struct Q5Pt3Rel { int off; int count; } Q5Pt3Rel;
typedef struct Q5Shaper { char p[0x20]; u8 active; char p21[3]; float gain; } Q5Shaper;
extern void fn_88646658(Q5Shaper *s, void *src, Q5Pt3 *pts, int count, float gain);
extern void ts4_multiply_by_keys_886491E8(Q5Shaper *s, struct W8dRel_886491E8 *keys);
extern void fn_88644DE0(Q5Shaper *s, float gain, int flag);

/* Swing_DLL.xex 0x88649298 */
void ts4_shaper_apply_rel_88649298(Q5Shaper *s, void *src, Q5Pt3Rel *pts,
                                   struct W8dRel_886491E8 *keys, int flag, float gain)
{
    s->gain = gain;
    s->active = 1;
    fn_88646658(s, src, (Q5Pt3 *)(pts->off + (char *)pts), pts->count, gain);
    ts4_multiply_by_keys_886491E8(s, keys);
    fn_88644DE0(s, gain, flag);
}

/* ---- 0x886C6660: copy a shot record: the 0x70-byte base via 0x886C4AF0, then
 * the trailing word and float pair. Not byte-matched: the target uses r3/r4
 * after the call (LTCG: the callee leaves them intact); we reload from r31/r30. */
typedef struct Q5ShotRec {
    char base[0x84];    /* copied by ts4_record_copy_886C4AF0 */
    u32 w84;
    float f88;
    float f8c;
} Q5ShotRec;
extern void ts4_record_copy_886C4AF0(Q5ShotRec *d, const Q5ShotRec *s);

/* Swing_DLL.xex 0x886C6660 */
void ts4_shot_rec_copy_886C6660(Q5ShotRec *d, const Q5ShotRec *s)
{
    ts4_record_copy_886C4AF0(d, s);
    d->w84 = s->w84;
    d->f88 = s->f88;
    d->f8c = s->f8c;
}

/* ---- 0x888D66C8: publish the formatted save name of slot i (0xb0-byte slots in
 * a self-relative table) to the save manager. Not byte-matched: register
 * numbering of the slot address and the order of the last two argument moves. */
typedef struct Q5SaveSlot { char pad0[0xc]; u32 id; char pad10[0xa0]; } Q5SaveSlot;
typedef struct Q5SaveTable { int off; } Q5SaveTable;
typedef struct Q5SaveOwner { char pad0[0x1c]; Q5SaveTable *slots; } Q5SaveOwner;
extern void ts4_format_save_name_888677D0(u32 id, char *out);
extern void *ts4_if_call_seq_u32_lbl_88D459E4_8883F238(void);
extern void fn_886223B0(void *mgr, u32 i, char *name);

/* Swing_DLL.xex 0x888D66C8 */
void ts4_save_slot_publish_name_888D66C8(Q5SaveOwner *self, u32 i)
{
    char name[0x200];
    Q5SaveTable *t = self->slots;
    Q5SaveSlot *s = (Q5SaveSlot *)((char *)t + i * sizeof(Q5SaveSlot) + t->off);
    ts4_format_save_name_888677D0(s->id, name);
    fn_886223B0(ts4_if_call_seq_u32_lbl_88D459E4_8883F238(), i, name);
}

/* ---- 0x88669040: run the pending rebuild / clear / refresh requests.
 * Not byte-matched: the target keeps obj in r3 and the zero in r5 across the
 * calls (LTCG knowledge of the callees). */
typedef struct Q5Pending {
    char pad0[0x1c];
    u8 rebuild;         /* +0x1c */
    u8 clear;           /* +0x1d */
    u8 refresh;         /* +0x1e */
    char pad1f[0x37c - 0x1f];
    u8 dirty;           /* +0x37c */
} Q5Pending;
extern void fn_88668DF8(Q5Pending *o);
extern void ts4_clear_records_88668D70(Q5Pending *o);

/* Swing_DLL.xex 0x88669040 */
void ts4_pending_flush_88669040(Q5Pending *o)
{
    if (o->rebuild == 1) {
        o->rebuild = 0;
        fn_88668DF8(o);
    }
    if (o->clear == 1) {
        o->clear = 0;
        ts4_clear_records_88668D70(o);
    }
    if (o->refresh == 1) {
        o->refresh = 0;
        o->dirty = 1;
    }
}

/* ---- 0x88885BB8: push a value onto a ring of 8-byte entries (needs /Oc: no
 * divide trap). Not byte-matched: the target addresses the ring through a copy
 * of the owner pointer with a dead `addi` of the ring base (23 off). */
typedef struct Q5RingEnt { u8 done; char pad1[3]; u32 value; } Q5RingEnt;
typedef struct Q5Ring { u32 cap; Q5RingEnt *buf; u32 pad24; u32 head; u32 count; } Q5Ring;
typedef struct Q5RingOwner { char pad0[0x1c]; Q5Ring ring; } Q5RingOwner;

/* Swing_DLL.xex 0x88885BB8 */
void ts4_ring_push_88885BB8(Q5RingOwner *o, u32 v)
{
    Q5Ring *r = &o->ring;
    r->buf[r->head].done = 0;
    r->buf[r->head].value = v;
    r->head = (r->head + 1) % r->cap;
    r->count++;
}

/* ---- 0x888C3940: set the mode byte (clamped to 4) and clear the trigger flags;
 * returns the previous mode. Not byte-matched: the target stores the `on`
 * bytes through a zero-extended copy of the zero (perm_auto best 10). */
typedef struct Q5Tri { u8 on; u8 held; u8 latched; } Q5Tri;
typedef struct Q5ModeFlags {
    char pad0[0xb4];
    Q5Tri tri[4];       /* +0xb4 */
    char padc0[0xdc - 0xc0];
    u8 mode;            /* +0xdc */
    char paddd[0xe7 - 0xdd];
    u8 e7;              /* +0xe7 */
} Q5ModeFlags;

/* Swing_DLL.xex 0x888C3940 */
u8 ts4_set_mode_clamped_888C3940(Q5ModeFlags *f, u8 m)
{
    u8 old = f->mode;
    if (old != m) {
        int i;
        f->mode = m > 4 ? 4 : m;
        for (i = 0; i < 4; i++)
            f->tri[i].on = f->tri[i].held = 0;
        f->e7 = 0;
    }
    return old;
}

/* ---- 0x886CEEC0: set a 2-vector target, copy it to the current value (as
 * words) and scale the current value about the source centre by (ratio - 1).
 * The target subtracts `cy` from both lanes and adds `cx` to both, as here.
 * Not byte-matched: load scheduling and a dead `addi` of &d->cur (24 off). */
extern float g_ts4_script_constants[];   /* [0] = 1.0f */
typedef struct Q5V2 { float x, y; } Q5V2;
typedef struct Q5V2Words { u32 x, y; } Q5V2Words;
typedef struct Q5ScaleBlk { char pad0[0x14]; float ratio; } Q5ScaleBlk;
typedef struct Q5ScaleInner { char pad0[8]; Q5ScaleBlk *blk; } Q5ScaleInner;
typedef struct Q5ScaleSrc {
    char pad0[4];
    Q5ScaleInner *inner;    /* +0x04 */
    char pad8[0xc];
    float cy;               /* +0x14 */
    char pad18[0xc];
    float cx;               /* +0x24 */
} Q5ScaleSrc;
typedef struct Q5ScaleDst { char pad0[4]; Q5V2 target; Q5V2 cur; } Q5ScaleDst;

/* Swing_DLL.xex 0x886CEEC0 */
void ts4_vec2_set_scale_886CEEC0(Q5ScaleDst *d, Q5ScaleSrc *s, float x, float y)
{
    float k;
    d->target.x = x;
    ((Q5V2Words *)&d->cur)->x = ((Q5V2Words *)&d->target)->x;
    d->target.y = y;
    ((Q5V2Words *)&d->cur)->y = ((Q5V2Words *)&d->target)->y;
    k = s->inner->blk->ratio - g_ts4_script_constants[0];
    d->cur.x = (d->cur.x - s->cy) * k + s->cx;
    d->cur.y = (d->cur.y - s->cy) * k + s->cx;
}

/* ---- 0x887F1F00: re-run the manager entry for the top id of the object's
 * frame stack (a self-relative array behind a self-relative link; offset -1
 * means none). Not byte-matched: the target re-reads the link offset through a
 * `clrrwi` copy and tests the count with `ble` (21 off). */
typedef struct Q5RelU32Arr { int off; u32 count; } Q5RelU32Arr;
typedef struct Q5RelLink { int off; } Q5RelLink;
typedef struct Q5Stack { char pad0[0xe0]; Q5RelLink *frames; } Q5Stack;
extern void *fn_887F0CA0(Q5Stack *self, u32 *id);

static __inline Q5RelU32Arr *q5_link_target(Q5RelLink *l) { return (Q5RelU32Arr *)((char *)l + l->off); }
static __inline u32 q5_frame_count(Q5RelLink *l)
{
    if (l->off == -1)
        return 0;
    return q5_link_target(l)->count;
}
static __inline u32 *q5_rel_u32_end(Q5RelU32Arr *a)
{
    u32 *e = 0;
    if (a->off != -1)
        e = (u32 *)((char *)a + (a->count * 4 + a->off));
    return e;
}

/* Swing_DLL.xex 0x887F1F00 */
void *ts4_stack_top_887F1F00(Q5Stack *self)
{
    if (self->frames && q5_frame_count(self->frames) > 0)
        return fn_887F0CA0(self, q5_rel_u32_end(q5_link_target(self->frames)) - 1);
    return 0;
}

/* ---- 0x8887DA38: constructor of a ramp object (vtable lbl_880DF824): enabled,
 * rate = constants[8], limit = constants[0x10c], everything else zero.
 * Not byte-matched: the target schedules the rate store before the +0x14/+0x18
 * clears (perm_auto best 2). */
extern char lbl_880DF824[];
typedef struct Q5Ramp {
    void *vtbl;         /* +0x00 */
    float rate;         /* +0x04 */
    u32 enabled;        /* +0x08 */
    float limit;        /* +0x0c */
    u32 pad10;
    u32 w14;            /* +0x14 */
    u8 b18;             /* +0x18 */
    char pad19[3];
    u32 w1c, w20, w24, w28, w2c, w30, w34;
} Q5Ramp;

/* Swing_DLL.xex 0x8887DA38 */
void ts4_ramp_init_8887DA38(Q5Ramp *r)
{
    r->vtbl = lbl_880DF824;
    r->enabled = 1;
    r->rate = g_ts4_script_constants[0x20 / 4];
    r->limit = g_ts4_script_constants[0x430 / 4];
    r->w14 = 0;
    r->b18 = 0;
    r->w1c = 0;
    r->w20 = 0;
    r->w24 = 0;
    r->w28 = 0;
    r->w2c = 0;
    r->w30 = 0;
    r->w34 = 0;
}
