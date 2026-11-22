/* Q5 equivalent route, batch D: small gameplay functions (0x68..0x74 bytes) that are proven
 * by tools/fn_equiv.py rather than byte-matched (see the spec's evidence file). Each block
 * names the reason the byte match is out of reach. */
typedef unsigned int u32;
typedef unsigned char u8;

/* fsel select: x >= 0 ? a : b (NaN and -0 handled as the hardware fsel does, which is
 * also what the target's compare-and-table idiom computes). */
#ifdef _MSC_VER
extern float __fself(float, float, float);
#pragma intrinsic(__fself)
#else
static float __fself(float x, float a, float b) { return x >= 0 ? a : b; }
#endif
extern const float lbl_8814B440; /* 0.0f */
static __inline float q5_fmax(float a, float b) { return __fself(a - b - lbl_8814B440, a, b); }
static __inline float q5_fmin(float a, float b) { return __fself(a - b - lbl_8814B440, b, a); }

/* ---- 0x8890E1C8: *x = clamp(*x, r->lo, r->hi).
 * Not byte-matched: the target compares each difference with 0.0f and picks the
 * select sign from a +-1.0 table (the compiler's `a - b >= 0.0f` idiom, 2 off on the LTCG
 * route). The table is a compiler literal pool that this build cannot place at the
 * target's address, so the select is written with fsel directly. */
typedef struct Q5Range { float lo; float hi; } Q5Range;

/* Swing_DLL.xex 0x8890E1C8 */
/* byte-gap: 25 off; target compares each difference with 0.0f and picks the select sign from a +-1.0 table, a literal pool this build cannot place at the target address */
void ts4_clamp_to_range_8890E1C8(Q5Range *r, float *x)
{
    float v = *x, lo = r->lo;
    *x = q5_fmin(q5_fmax(v, lo), r->hi);
}

/* ---- 0x8866C988: smaller of two sampled values (fn_8866C8B8 over the record and
 * its +0x60 sub-record). Not byte-matched: LTCG keeps r4 and the first result in volatile
 * registers across the second call. */
typedef struct Q5SampleRec { char a[0x60]; char b[0x60]; } Q5SampleRec;
typedef struct Q5Sampler { void *vtbl; Q5SampleRec *rec; } Q5Sampler;
extern float fn_8866C8B8(Q5Sampler *self, void *rec);

/* Swing_DLL.xex 0x8866C988 */
/* byte-gap: 26 off; LTCG keeps r4 and the first result in volatile registers across the second call */
float ts4_sample_min_8866C988(Q5Sampler *self)
{
    float a = fn_8866C8B8(self, self->rec->a);
    float b = fn_8866C8B8(self, self->rec->b);
    return q5_fmin(a, b);
}

/* ---- 0x886E3938: visit every slot of a self-relative item array: fn_886E3328(slot i,
 * self, &item[i], &record[i] (0x530-byte records, self-relative), extra).
 * Not byte-matched: the loop induction variables differ. */
typedef struct Q5RelArr { int off; int count; } Q5RelArr;
typedef struct Q5Rec530 { char b[0x530]; } Q5Rec530;
typedef struct Q5Visitor {
    char pad00[0x48];
    u32 extra;          /* +0x48 */
    Q5RelArr *records;  /* +0x4c */
    u32 *slots;         /* +0x50 */
} Q5Visitor;
extern void fn_886E3328(u32 slot, Q5Visitor *self, u32 *item, Q5Rec530 *record, u32 extra);

/* Swing_DLL.xex 0x886E3938 */
/* byte-gap: 24 off; the loop induction variables differ */
void ts4_visit_slots_886E3938(Q5Visitor *self, Q5RelArr *items)
{
    int i;
    for (i = 0; i < items->count; i++) {
        Q5Rec530 *recs = (Q5Rec530 *)((char *)self->records + self->records->off);
        u32 *its = (u32 *)((char *)items + items->off);
        fn_886E3328(self->slots[i], self, &its[i], &recs[i], self->extra);
    }
}

/* ---- 0x8865E638: bind a context: remember it, point at its +0xab0 block and its
 * +0x9d0 sub-block, then look up key 0xb746006e in the block's +0x20 table.
 * Not byte-matched: the stores are scheduled differently. */
typedef struct Q5Blk { char pad[0x20]; char table[1]; } Q5Blk;
typedef struct Q5Holder6c { char pad[0x6c]; char *base; } Q5Holder6c;
typedef struct Q5Ctx { char pad[0x44]; Q5Holder6c *holder; char pad48[0x2c]; char *sub; } Q5Ctx;
typedef struct Q5Binder { void *vtbl; Q5Ctx *ctx; void *found; Q5Blk *blk; char *sub; } Q5Binder;
extern void *fn_8826D010(void *table, u32 *key);

/* Swing_DLL.xex 0x8865E638 */
/* byte-gap: 22 off; the stores are scheduled differently */
void ts4_bind_ctx_8865E638(Q5Binder *b, Q5Ctx *c)
{
    u32 key = 0xb746006e;
    Q5Blk *blk;
    b->ctx = c;
    blk = (Q5Blk *)(c->holder->base + 0xab0);
    b->blk = blk;
    b->sub = c->sub + 0x9d0;
    b->found = fn_8826D010(blk->table, &key);
}

/* ---- Constructors on the 0x88617D88 base (0x1c bytes). Not byte-matched: zero-store
 * scheduling. */
extern void *fn_88617D88(void *self);

/* 0x88886608: two flags and an embedded 0x20-byte sub-object (vtable lbl_880D6B70). */
extern char lbl_880DF438[];
extern char lbl_880D6B70[];
typedef struct Q5Sub20 { void *vtbl; u32 w4, w8, wc, w10, w14; char pad18[4]; u8 b1c; } Q5Sub20;
typedef struct Q5FlagObj { void *vtbl; char base[0x18]; u8 b1c; u8 b1d; char pad1e[2]; Q5Sub20 sub; } Q5FlagObj;

/* Swing_DLL.xex 0x88886608 */
/* byte-gap: 15 off; reason not recorded */
Q5FlagObj *ts4_flag_obj_ctor_88886608(Q5FlagObj *o)
{
    fn_88617D88(o);
    o->b1c = 0;
    o->vtbl = lbl_880DF438;
    o->b1d = 0;
    o->sub.vtbl = lbl_880D6B70;
    o->sub.b1c = 0;
    o->sub.w4 = 0;
    o->sub.w8 = 0;
    o->sub.wc = 0;
    o->sub.w10 = 0;
    o->sub.w14 = 0;
    return o;
}

/* 0x888DF740: two (start, end = 0xfffff) windows. */
extern char lbl_880DBD80[];
typedef struct Q5WinObj {
    void *vtbl; char base[0x18];
    u32 w1c, w20, w24, w28, end2c, w30, w34, end38, w3c;
    u8 b40;
} Q5WinObj;

/* Swing_DLL.xex 0x888DF740 */
/* byte-gap: 8 off; reason not recorded */
Q5WinObj *ts4_window_obj_ctor_888DF740(Q5WinObj *o)
{
    fn_88617D88(o);
    o->vtbl = lbl_880DBD80;
    o->w1c = 0;
    o->w20 = 0;
    o->w24 = 0;
    o->w28 = 0;
    o->w30 = 0;
    o->end2c = 0xfffff;
    o->w34 = 0;
    o->w3c = 0;
    o->end38 = 0xfffff;
    o->b40 = 0;
    return o;
}

/* 0x88888C80: singleton (lbl_88D45B2C) with two formatted text members. */
extern char lbl_880DF328[];
extern char lbl_880DF05C[];
extern char lbl_880DF064[];
typedef struct Q5Text { char b[0xc]; } Q5Text;
typedef struct Q5TextObj {
    void *vtbl; char base[0x18];
    u32 w1c; u8 b20; char pad21[3]; u32 w24;
    Q5Text t28;     /* +0x28 */
    Q5Text t34;     /* +0x34 */
} Q5TextObj;
extern Q5TextObj *lbl_88D45B2C;
extern void ts4_assign_formatted_text(Q5Text *dst, const char *text);

/* Swing_DLL.xex 0x88888C80 */
/* byte-gap: 2 off; reason not recorded */
Q5TextObj *ts4_text_obj_ctor_88888C80(Q5TextObj *o)
{
    fn_88617D88(o);
    o->w1c = 0;
    o->b20 = 0;
    o->w24 = 0;
    lbl_88D45B2C = o;
    o->vtbl = lbl_880DF328;
    ts4_assign_formatted_text(&o->t28, lbl_880DF05C);
    ts4_assign_formatted_text(&o->t34, lbl_880DF064);
    return o;
}

/* ---- 0x888B7360: copy a 6-float box into the self-relative bounds record and cache
 * its spans, then refresh (tail call 0x888B0E38).
 * Not byte-matched: the target issues a dead compare of +0x7c before the tail call. */
typedef struct Q5Bounds {
    char pad[0xd4];
    float x0, x1, y0;   /* +0xd4 x0, +0xd8 x1, +0xdc y0 */
    float z0, y1, z1;   /* +0xe0 z0, +0xe4 y1, +0xe8 z1 */
} Q5Bounds;
typedef struct Q5RelBounds { int off; } Q5RelBounds;
typedef struct Q5Box { float x0, y0, z0, x1, y1, z1; } Q5Box;
typedef struct Q5BoxOwner {
    char pad0[8];
    Q5RelBounds *bounds;    /* +0x08 */
    char padc[0x8c];
    float span_z;           /* +0x98 */
    float span_x;           /* +0x9c */
} Q5BoxOwner;
extern void fn_888B0E38(Q5BoxOwner *self);

/* Swing_DLL.xex 0x888B7360 */
/* byte-gap: 20 off; target issues a dead compare of +0x7c before the tail call */
void ts4_set_bounds_888B7360(Q5BoxOwner *self, const Q5Box *box)
{
    Q5Bounds *b;
    if (!self->bounds)
        return;
    b = (Q5Bounds *)((char *)self->bounds + self->bounds->off);
    b->x1 = box->x1;
    b->x0 = box->x0;
    b->z1 = box->z1;
    b->y1 = box->y1;
    b->z0 = box->z0;
    b->y0 = box->y0;
    self->span_z = box->z1 - box->z0;
    self->span_x = b->x1 - b->x0;
    fn_888B0E38(self);
}

/* ---- 0x886C7C28: weight of the active animation layer, or the default weight
 * (+0x140 of the owner's config) when there is no active layer or its weight is negative
 * (sign bit set). Not byte-matched: LTCG keeps the default in volatile f7 across the
 * layer lookup. */
typedef struct Q5LayerCurve { char pad[0x50]; float weight; } Q5LayerCurve;
typedef struct Q5LayerDef { char pad[8]; Q5LayerCurve *curve; } Q5LayerDef;
typedef struct Q5Layer { char pad[4]; Q5LayerDef *def; } Q5Layer;
typedef struct Q5AnimStack { char pad[0x5c]; Q5Layer **layers; } Q5AnimStack;
typedef struct Q5AnimCfg { char pad[0x140]; float default_weight; } Q5AnimCfg;
typedef struct Q5AnimCfgHolder { char pad[0x48]; Q5AnimCfg *cfg; } Q5AnimCfgHolder;
typedef struct Q5AnimOwner { char pad[0x10]; Q5AnimCfgHolder *holder; } Q5AnimOwner;
typedef struct Q5AnimUser { char pad[8]; Q5AnimOwner *owner; Q5AnimStack *stack; } Q5AnimUser;
extern int ts4_anim_layer_index_886C66C0(Q5AnimStack *stack);
typedef union Q5FBits { float f; u32 u; } Q5FBits;

/* Swing_DLL.xex 0x886C7C28 */
/* byte-gap: 27 off; LTCG keeps the default weight in volatile f7 across the layer lookup */
float ts4_layer_weight_886C7C28(Q5AnimUser *u)
{
    float def = u->owner->holder->cfg->default_weight;
    Q5AnimStack *st = u->stack;
    int i = ts4_anim_layer_index_886C66C0(st);
    Q5FBits w;
    if (i == -1)
        return def;
    w.f = st->layers[i]->def->curve->weight;
    if (w.u & 0x80000000u)
        return def;
    return w.f;
}

/* ---- 0x88883CD0: payload of the job slot that belongs to the current thread
 * (25 slots of 0x208 bytes at lbl_88D3EB60, keyed by fn_8857C8C8()), offset by `off`;
 * 0 when the thread has no slot. Not byte-matched: loop register allocation. */
typedef struct Q5JobSlot { u32 h; int id; char data[0x200]; } Q5JobSlot;
extern char lbl_88D3EB60[];
extern int fn_8857C8C8(void);

/* Swing_DLL.xex 0x88883CD0 */
/* byte-gap: 23 off; loop register allocation */
void *ts4_thread_slot_data_88883CD0(u32 off)
{
    int id = fn_8857C8C8();
    Q5JobSlot *e = (Q5JobSlot *)lbl_88D3EB60;
    do {
        if (e->id == id)
            return e->data + off;
        e++;
    } while (e != (Q5JobSlot *)(lbl_88D3EB60 + 0x32c8));
    return 0;
}

/* ---- 0x888D9420: send two script-constant vectors with the hash 0x5392B268
 * (the second one's y scaled by k). 12-byte values pass by value in GPR pairs.
 * Not byte-matched: the stack staging of the by-value structs differs. */
extern float g_ts4_script_constants[];
typedef struct Q5V3 { float x, y, z; } Q5V3;
extern void fn_888D0FE0(void *self, u32 hash, Q5V3 a, Q5V3 b);

/* Swing_DLL.xex 0x888D9420 */
/* byte-gap: 1 off; the stack staging of the by-value structs differs */
void ts4_send_vectors_5392B268_888D9420(void *self, float k)
{
    Q5V3 a, b;
    a.x = g_ts4_script_constants[0x638 / 4];
    a.y = g_ts4_script_constants[0x344 / 4];
    a.z = g_ts4_script_constants[0x1e0 / 4];
    b.x = g_ts4_script_constants[0x374 / 4];
    b.y = k * g_ts4_script_constants[0x750 / 4];
    b.z = g_ts4_script_constants[0x1e0 / 4];
    fn_888D0FE0(self, 0x5392b268, a, b);
}

/* ---- 0x888CAA98: tint a list item: (0, constants[0xf0], highlight) where highlight is
 * constants[0x5b0] for the signed-in pad's item and constants[0x20] otherwise; skipped
 * while the list is locked or hidden or there is no notification object.
 * Not byte-matched: the tint loads are scheduled differently (perm_auto best 7). */
typedef struct Q5Notif { char p[0x128]; int pad_index; } Q5Notif;
extern Q5Notif *g_ts4_tsu_notification_object;
typedef struct Q5Tint { char p[0x40]; float r, g, b; } Q5Tint;
typedef struct Q5Item { char p[0xc]; int pad_index; char p10[0x38]; Q5Tint *tint; } Q5Item;
typedef struct Q5ItemList { char p[0x23e]; u8 locked; u8 p23f; u8 hidden; } Q5ItemList;
static __inline void q5_set3(Q5Tint *t, float r, float g, float b)
{
    t->r = r;
    t->g = g;
    t->b = b;
}

/* Swing_DLL.xex 0x888CAA98 */
/* byte-gap: 7 off; tint loads are scheduled differently (perm_auto best 7) */
void ts4_item_tint_888CAA98(Q5ItemList *l, Q5Item *it)
{
    Q5Notif *n;
    float hl;
    if (l->locked)
        return;
    if (l->hidden)
        return;
    n = g_ts4_tsu_notification_object;
    if (!n)
        return;
    hl = g_ts4_script_constants[0x5b0 / 4];
    if (it->pad_index != n->pad_index)
        hl = g_ts4_script_constants[0x20 / 4];
    q5_set3(it->tint, lbl_8814B440, g_ts4_script_constants[0xf0 / 4], hl);
}

/* ---- 0x888DA288: clear the device-job flag (lbl_88C46F6A) and queue job 0x83DE4BDF
 * for `pad` on service 0x11A98C5A, with ts4_set_u8_lbl_88C46F6A_888BFCE0 as completion.
 * Not byte-matched: constant/address materialisation order (perm_auto best 11). */
extern void *ts4_find_service(u32 id);
extern u32 *fn_886260B8(void *svc, u32 key, int pad, u32 type, u32 mode, void (*cb)(void), u32 c, u32 d);
extern void ts4_set_u8_lbl_88C46F6A_888BFCE0(void);
extern char lbl_88C46F6A[];

/* Swing_DLL.xex 0x888DA288 */
/* byte-gap: 11 off; constant/address materialisation order (perm_auto best 11) */
void ts4_queue_device_job_888DA288(int pad)
{
    lbl_88C46F6A[0] = 0;
    fn_886260B8(ts4_find_service(0x11a98c5a), 0x83de4bdf, pad, 0, 2, ts4_set_u8_lbl_88C46F6A_888BFCE0, 0, 0);
}

/* ---- Handle binders: 12-byte xdata handles passed by value (GPR pair). */
typedef struct Q5Handle { void *tree; u32 node_id; u32 extra; } Q5Handle;
extern void *fn_88627EC0(void *object, Q5Handle h);
extern Q5Handle *ts4_handle_forward_88150770(Q5Handle *out, Q5Handle *handle, u32 *type_hash);
extern void fn_881895D0(u32 *out, Q5Handle h);
extern void *fn_88923530(u32 pool, Q5Handle h, u32 type_hash); /* pool: 32-bit target address */
extern void fn_888E6A28(void *self, void *arg);

/* ---- 0x888B8F58: bind the handle, then read its 0xFE11D138 child into +0x34.
 * Not byte-matched: stack slot layout of the by-value handles. */
typedef struct Q5HBind34 { char pad[0x34]; u32 value; } Q5HBind34;

/* Swing_DLL.xex 0x888B8F58 */
/* byte-gap: 0 off; fn_check reports 0 off, but the notes say stack slot layout of the by-value handles differs; verify with matching.py */
void ts4_bind_read_fe11d138_888B8F58(Q5HBind34 *self, Q5Handle h)
{
    Q5Handle child;
    u32 key;
    u32 v;
    fn_88627EC0(self, h);
    key = 0xfe11d138;
    ts4_handle_forward_88150770(&child, &h, &key);
    v = 0;
    fn_881895D0(&v, child);
    self->value = v;
}

/* ---- 0x888E6C78: bind the handle, resolve its 0xF64CEFF6 record (pool = h.extra), cache
 * the two services that record names (+0x1c -> +0x28, +0x20 -> +0x2c), then finish setup
 * with the engine's +0x224 member. Not byte-matched: register allocation of the saved
 * handle words. */
typedef struct Q5SvcRec { char pad[0x1c]; u32 svc_a; u32 svc_b; } Q5SvcRec;
typedef struct Q5SvcUser { char pad[0x28]; void *svc_a; void *svc_b; } Q5SvcUser;
typedef struct Q5Engine224 { char pad[0x224]; void *m224; } Q5Engine224;
extern Q5Engine224 *lbl_88D45B1C;

/* Swing_DLL.xex 0x888E6C78 */
/* byte-gap: 13 off; register allocation of the saved handle words */
void ts4_bind_services_888E6C78(Q5SvcUser *self, Q5Handle h)
{
    Q5SvcRec *rec;
    void *a;
    fn_88627EC0(self, h);
    rec = (Q5SvcRec *)fn_88923530(h.extra, h, 0xf64ceff6);
    a = ts4_find_service(rec->svc_a);
    self->svc_b = ts4_find_service(rec->svc_b);
    self->svc_a = a;
    fn_888E6A28(self, lbl_88D45B1C->m224);
}

/* ---- 0x888CDBC8: does the self-relative id list at +0x8c contain `id`?
 * Not byte-matched: the list bounds are recomputed differently. */
typedef struct Q5RelIds { int off; u32 count; } Q5RelIds;
typedef struct Q5RelHead { int off; } Q5RelHead;
typedef struct Q5IdOwner { char pad[0x8c]; Q5RelHead ids; } Q5IdOwner;
static __inline u32 *q5_ids_begin(Q5RelIds *a)
{
    return a->off != -1 ? (u32 *)((char *)a + a->off) : 0;
}
static __inline u32 *q5_ids_end(Q5RelIds *a)
{
    return a->off != -1 ? (u32 *)((char *)a + a->count * 4 + a->off) : 0;
}

/* Swing_DLL.xex 0x888CDBC8 */
/* byte-gap: 31 off; the list bounds are recomputed differently */
int ts4_ids_contain_888CDBC8(Q5IdOwner *self, u32 id)
{
    Q5RelIds *a;
    u32 *p, *e;
    if (self->ids.off == -1)
        return 0;
    a = (Q5RelIds *)((char *)&self->ids + self->ids.off);
    e = q5_ids_end(a);
    for (p = q5_ids_begin(a); p != e; p++)
        if (*p == id)
            return 1;
    return 0;
}
