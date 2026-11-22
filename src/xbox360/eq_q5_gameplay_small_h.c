/* Top Spin 4 (Xbox 360, Swing_DLL.xex): Q5 gameplay, small functions, batch H.
 * EQUIVALENT tier (fn_equiv/4), not byte-matched; each function says why.
 * Evidence: work/specs/Q5/eq_q5_gameplay_small_h.equiv.json (flags /Oc). */
#include "ts4_vector.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
#ifdef _MSC_VER
typedef unsigned int q5_uptr;
#else
typedef unsigned long q5_uptr; /* host syntax check only */
#endif

float __fsqrts(float x);
#ifdef _MSC_VER
#pragma intrinsic(__fsqrts)
#endif

/* Shared: pad index -> controller record (id at +0x10) through the engine's module list. */
typedef struct Q5PadRec { char pad[0x10]; int id; } Q5PadRec;
typedef struct Q5ModList Q5ModList;
typedef struct Q5Sink Q5Sink;
typedef struct Q5Engine { char pad[0x234]; Q5ModList *modules; char pad238[0x44]; u32 f27c; char pad280[0x24];
    Q5Sink *sink; } Q5Engine;
extern Q5Engine *lbl_88D45B1C;
extern Q5PadRec *ts4_pad_record_find_88614938(Q5ModList *m, int pad);
extern void ts4_object_finalize(void *p);
extern void ts4_destroy_owned_object(void *p);

/* ---- 0x888C5C00: scale a stick (x, y) by script constant 0x84, store it as two u16 at
 * +0x20c/+0x20e and send it to the pad's controller; returns 1 when the send returns 0.
 * Not byte-matched: LTCG keeps f1/f2 live across the call and the target's
 * `fmuls fX,f2,f0` operand order is not reproducible from C. */
typedef struct Q5StickOut { char pad[0x20c]; u16 xy[2]; } Q5StickOut;
extern char g_ts4_script_constants[];
extern int ts4_if_call_seq_u32_off0_8857B180(int id, u16 *xy);

/* Swing_DLL.xex 0x888C5C00 */
int ts4_pad_send_stick_888C5C00(Q5StickOut *o, int pad, float x, float y)
{
    Q5PadRec *rec = ts4_pad_record_find_88614938(lbl_88D45B1C->modules, pad);
    int id = rec ? rec->id : -1;
    float k = *(float *)(g_ts4_script_constants + 0x84);
    o->xy[1] = (u16)(k * y);
    o->xy[0] = (u16)(k * x);
    return ts4_if_call_seq_u32_off0_8857B180(id, o->xy) == 0;
}

/* ---- 0x888CB5F8: open the storage-device selector for the pad at +0x2c: zero the 7-word
 * overlapped block at +0x34 and the device id at +0x30, call XamShowDeviceSelectorUI
 * (content type 1, flags 0x200, 0 bytes requested), then clear lbl_88C46F43.
 * Not byte-matched (20 off): the target forms the second word of the 64-bit size through a
 * separate address and stores the final byte without the extra register copy. */
typedef struct Q5Size64 { u32 hi, lo; } Q5Size64;
typedef struct Q5Overlapped { u32 w[7]; } Q5Overlapped;
typedef struct Q5DevSel { char pad[0x2c]; u32 pad_index; u32 device_id; Q5Overlapped ov; } Q5DevSel;
extern u8 lbl_88C46F43;
extern u32 ts4_tailcall_XamShowDeviceSelectorUI_8857A6C8(int user, u32 content_type, u32 flags,
                                                           Q5Size64 bytes, u32 *device_id, Q5Overlapped *ov);

/* Swing_DLL.xex 0x888CB5F8 */
void ts4_show_device_selector_888CB5F8(Q5DevSel *self)
{
    Q5Size64 bytes;
    Q5PadRec *rec;
    Q5Overlapped *ov = &self->ov;
    u32 *dev;
    u32 *p;
    int i;
    p = ov->w;
    for (i = 0; i < 7; i++)
        *p++ = 0;
    self->device_id = 0;
    dev = &self->device_id;
    bytes.hi = 0;
    *(&bytes.hi + 1) = 0;
    rec = ts4_pad_record_find_88614938(lbl_88D45B1C->modules, self->pad_index);
    ts4_tailcall_XamShowDeviceSelectorUI_8857A6C8(rec ? rec->id : -1, 1, 0x200, bytes, dev, ov);
    lbl_88C46F43 = 0;
}

/* ---- 0x888CA910: destructor body: install vtable lbl_880DB200, clear lbl_88D45948, empty
 * the vector at +0x2c, finalize and free the owned buffer at +0x54, free the vector buffer,
 * then run the base destructor 0x88617D28.
 * Not byte-matched (7 off, perm_auto best 7): scheduling of `mr r30,r3` and the global store. */
typedef struct Dc44 Dc44; /* 0x44-byte element */
typedef struct Q5Vec { Dc44 *first; Dc44 *last; Dc44 *cap; } Q5Vec;
typedef struct Q5Own { void *first; } Q5Own;
typedef struct Q5Svc { void *vtbl; char pad04[0x28]; Q5Vec items; char pad38[0x1c]; Q5Own owned; } Q5Svc;
extern char lbl_880DB200[];
extern u32 lbl_88D45948;
extern Dc44 *ts4_dc44_copy_881817A0(Dc44 *first, Dc44 *last, Dc44 *dst);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);

/* Swing_DLL.xex 0x888CA910 */
void ts4_svc_dtor_888CA910(Q5Svc *self)
{
    Q5Vec *v = &self->items;
    self->vtbl = lbl_880DB200;
    lbl_88D45948 = 0;
    v->last = ts4_dc44_copy_881817A0(v->last, v->last, v->first);
    ts4_object_finalize(&self->owned);
    if (self->owned.first)
        ts4_destroy_owned_object(self->owned.first);
    if (v->first)
        ts4_destroy_owned_object(v->first);
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
}

/* ---- 0x888E7278: look up hash 0xC750E1AC in the global hash table with key
 * {engine+0x27c, v, 1} and a null handle; if the record's +0x18 flag is clear, set its +0x10
 * value to 0xA8A78981; then clear the flag. Same lookup template as 0x88868A88.
 * Not byte-matched (perm_auto best 22): argument set-up scheduling. */
typedef struct Q5Handle12 { u32 a, b, c; } Q5Handle12;
typedef struct Q5HashTable Q5HashTable;
typedef struct Q5HashKey3 { u32 a, b, c; } Q5HashKey3;
typedef struct Q5HashRec { char pad[0x10]; u32 value; char pad14[4]; u8 flag; } Q5HashRec;
extern Q5HashTable *lbl_88D458F0;
extern Q5HashRec *ts4_hash_find_arg_88180F08(Q5HashTable *table, u32 hash, Q5HashKey3 *key, Q5Handle12 h);

/* Swing_DLL.xex 0x888E7278 */
void ts4_hash_reset_C750E1AC_888E7278(u32 v)
{
    Q5HashKey3 k;
    Q5Handle12 n;
    Q5HashRec *r;
    k.b = v;
    k.c = 1;
    n.a = 0;
    n.b = 0xFFFFF;
    n.c = 0;
    k.a = lbl_88D45B1C->f27c;
    r = ts4_hash_find_arg_88180F08(lbl_88D458F0, 0xC750E1ACu, &k, n);
    if (!r->flag)
        r->value = 0xA8A78981u;
    r->flag = 0;
}

/* ---- 0x88888DA8: when the engine has a text sink (+0x2a4) and this object is active (+0x1c),
 * join the +0x28 prefix string with `text`, convert it (0x8816D140) and post it through the
 * sink's vtable slot 0x50, freeing both temporaries.
 * Not byte-matched: the target keeps the converted buffer in r30 and the global's address in
 * r31 for the whole function. */
typedef struct Q5Str { char *b; char *e; char *c; } Q5Str;
typedef struct Q5Str16 { char *b; char *e; char *c; void *alloc; char pad10[0x10]; } Q5Str16;
typedef struct Q5SinkVt { void *slots[0x14]; void (*post)(Q5Sink *self, char *text); } Q5SinkVt;
struct Q5Sink { Q5SinkVt *vt; };
typedef struct Q5Named { char pad[0x1c]; int active; char pad20[8]; Q5Str prefix; } Q5Named;
extern Q5Str *fn_88163300(Q5Str *out, Q5Str *a, const char *b);
extern void *ts4_if_call_seq_u32_off0_8816D140(Q5Str16 *self, Q5Str *s);

/* Swing_DLL.xex 0x88888DA8 */
void ts4_post_prefixed_88888DA8(Q5Named *self, const char *text)
{
    if (lbl_88D45B1C->sink && self->active) {
        Q5Str joined;
        Q5Str16 out;
        ts4_if_call_seq_u32_off0_8816D140(&out, fn_88163300(&joined, &self->prefix, text));
        ts4_destroy_owned_object(joined.b);
        {
            char *t = out.b;
            Q5Sink *k = lbl_88D45B1C->sink;
            k->vt->post(k, t);
            ts4_destroy_owned_object(t);
        }
    }
}

/* ---- 0x888B1960: when the self-relative target at +0x8 exists, flag it (+0x94, +0x95), save
 * the 10 floats at +0xc into +0x38 and register this object with the global list lbl_88D45964.
 * Not byte-matched: the target tests the relative pointer with `add` + `cmplwi cr6` (not `add.`)
 * and keeps a dead blr after the tail call (LTCG). */
typedef struct Q5RelRef { int off; } Q5RelRef;
typedef struct Q5Target94 { char pad[0x94]; u8 dirty; u8 visible; } Q5Target94;
typedef struct Q5Snap { float v[10]; } Q5Snap;
typedef struct Q5Tracker { char pad[8]; Q5RelRef *ref; Q5Snap cur; u32 pad34; Q5Snap saved; } Q5Tracker;
extern char *lbl_88D45964;
extern void ts4_ptr_vec_add_unique_888AE990(char *self, u32 key);

/* Swing_DLL.xex 0x888B1960 */
void ts4_tracker_commit_888B1960(Q5Tracker *self)
{
    Q5RelRef *r;
    Q5Target94 *t;
    if (self->ref == 0)
        return;
    r = self->ref;
    if (r->off == -1)
        return;
    t = (Q5Target94 *)((char *)r + r->off);
    if (t == 0)
        return;
    t->dirty = 1;
    t->visible = 1;
    {
        float *d = self->saved.v;
        const float *c = self->cur.v;
        d[0] = c[0];
        d[1] = c[1];
        d[2] = c[2];
        d[3] = c[3];
        d[4] = c[4];
        d[5] = c[5];
        d[6] = c[6];
        d[7] = c[7];
        d[8] = c[8];
        d[9] = c[9];
    }
    ts4_ptr_vec_add_unique_888AE990(lbl_88D45964, (u32)(q5_uptr)self);
}

/* ---- 0x88669B98: set a player's upper and lower animation sets to 0xB388F633 or 0xD6FE8128
 * (the pair 0x886870C8 uses for the winning / losing side). The choice: if the scene's +0x30
 * record has its +0x328 flag clear, whether the player's side (+0x4c -> +0x28) equals that
 * record's +0x8c; otherwise the +0x2fe flag of the scene's +0x44 record.
 * Not byte-matched: LTCG no-op clrrwi and a stack-staged select in the target. */
typedef struct Q5Rally { char pad[0x8c]; int side; char pad90[0x298]; u8 flag328; } Q5Rally;
typedef struct Q5Crowd { char pad[0x2fe]; u8 flag2fe; } Q5Crowd;
typedef struct Q5Scene { char pad[0x30]; Q5Rally *rally; char pad34[0x10]; Q5Crowd *crowd; } Q5Scene;
typedef struct Q5Owner4 { char pad[4]; Q5Scene *scene; } Q5Owner4;
typedef struct Q5PInfo { char pad[0x28]; int side; } Q5PInfo;
typedef struct Q5PAnim { char pad[0x2fc]; u32 upper; u32 lower; } Q5PAnim;
typedef struct Q5PlayerA { char pad[0x4c]; Q5PInfo *info; char pad50[0x24]; Q5PAnim *anim; } Q5PlayerA;

static __inline u32 q5_pick_anim(u8 win)
{
    return win ? 0xB388F633u : 0xD6FE8128u;
}

/* Swing_DLL.xex 0x88669B98 */
void ts4_player_set_anim_pair_88669B98(Q5Owner4 *self, Q5PlayerA *p)
{
    Q5PAnim *a = p->anim;
    u8 win;
    if (self->scene->rally->flag328 == 0)
        win = p->info->side == self->scene->rally->side;
    else
        win = self->scene->crowd->flag2fe;
    a->upper = q5_pick_anim(win);
    a->lower = q5_pick_anim(win);
}

/* ---- 0x88880750: assign the +0x70 name to `name_out`; when a clip is bound (+0xc), report its
 * +0x40, +0x58 and +0x44 words and the 3-D length of the +0x1a0 offset vector.
 * Not byte-matched: VMX length (vmsum3fp, fsqrts, splat round-trip through the stack). */
typedef struct Q5Clip { char pad[0x40]; u32 f40; u32 f44; char pad48[0x10]; u32 f58; } Q5Clip;
typedef struct Q5Emitter { char pad[0xc]; Q5Clip *clip; char pad10[0x60]; const char *name; char pad74[0x12c];
    __vector4 offset; } Q5Emitter;
extern void fn_8816CAA0(void *dst, const char *s);

/* Swing_DLL.xex 0x88880750 */
void ts4_emitter_describe_88880750(Q5Emitter *self, void *name_out, u32 *f40, float *len, u32 *f58, u32 *f44)
{
    Q5Clip *c;
    fn_8816CAA0(name_out, self->name);
    c = self->clip;
    if (c) {
        __vector4 v = self->offset;
        __vector4 d = __vmsum3fp(v, v);
        *f40 = c->f40;
        *len = __fsqrts(d.v[0]);
        *f58 = c->f58;
        *f44 = c->f44;
    }
}

/* ---- 0x8866BAE0: while the +0x30 record is busy (+0x328), does its +0x310 id equal the
 * selected id (+0x5c -> +0x20 -> +0xe8); otherwise, in mode 2 (+0x4c -> +0x2c), is the +0x14
 * flag of the chosen item's +0x84 record set (item 1 when +0x18 is null, else item 0).
 * Not byte-matched: the target re-reads self->x and keeps an LTCG no-op clrrwi. */
typedef struct Q5SelFlag { char pad[0x14]; u8 set; } Q5SelFlag;
typedef struct Q5SelId { char pad[0xe8]; int id; } Q5SelId;
typedef struct Q5SelB { char pad[0x20]; Q5SelId *c; } Q5SelB;
typedef struct Q5SelP { char pad[0x310]; int id; char pad314[0x14]; u8 busy; } Q5SelP;
typedef struct Q5SelY { char pad[0x30]; Q5SelP *p; char pad34[0x28]; Q5SelB *b; } Q5SelY;
typedef struct Q5SelItem { char pad[0x84]; Q5SelFlag *flag; } Q5SelItem;
typedef struct Q5SelZ { char pad[0x10]; Q5SelItem **items; char pad14[0x18]; int mode; } Q5SelZ;
/* The owner also carries its own +0x84 flag record, used outside mode 2. */
typedef struct Q5SelX { char pad[0x18]; Q5SelItem *sel; char pad1c[0x2c]; Q5SelY *y; Q5SelZ *z;
    char pad50[0x34]; Q5SelFlag *flag; } Q5SelX;
typedef struct Q5SelS { char pad[0x1c]; Q5SelX *x; } Q5SelS;

/* Swing_DLL.xex 0x8866BAE0 */
int ts4_selected_flag_8866BAE0(Q5SelS *self)
{
    Q5SelX *x = self->x;
    Q5SelFlag *f;
    if (x->y->p->busy)
        return x->y->p->id == x->y->b->c->id;
    if (x->z->mode != 2)
        return 0;
    f = x->flag;
    if (x->z->mode == 2)
        f = x->z->items[x->sel == 0]->flag;
    return f->set != 0;
}

/* ---- 0x886A37D0: when highlighting is enabled (+0x48 -> +0x28 -> +0x48), colour the +0x9e8
 * block 0xFF008000 (green) if fn_88691298 accepts it against +0x9d0, else 0xFFF0F8FF.
 * Not byte-matched: LTCG no-op clrrwi on the object pointer. */
typedef struct Q5HlCfg { char pad[0x48]; u8 enabled; } Q5HlCfg;
typedef struct Q5HlOpt { char pad[0x28]; Q5HlCfg *cfg; } Q5HlOpt;
typedef struct Q5HlBody { char pad[0x9d0]; u8 a[0x18]; u8 b[0x18]; } Q5HlBody;
typedef struct Q5HlObj { char pad[0x48]; Q5HlOpt *opt; char pad4c[0x10]; void *h5c; char pad60[4]; void *h64;
    char pad68[0xc]; Q5HlBody *body; } Q5HlObj;
typedef struct Q5HlSelf { char pad[0x154]; Q5HlObj *obj; } Q5HlSelf;
typedef struct Q5Color { u32 argb; } Q5Color;
extern u32 fn_88691298(void *a, void *b, void *c);
extern void fn_8869BDF8(void *a, void *b, Q5Color c);

/* Swing_DLL.xex 0x886A37D0 */
void ts4_update_highlight_886A37D0(Q5HlSelf *self)
{
    Q5HlObj *o = self->obj;
    if (o->opt->cfg->enabled) {
        Q5Color c;
        u8 *b = o->body->b;
        if ((u8)fn_88691298(o->h64, o->body->a, b))
            c.argb = 0xFF008000u;
        else
            c.argb = 0xFFF0F8FFu;
        fn_8869BDF8(o->h5c, b, c);
    }
}

/* ---- 0x888C1368: is bit `idx` of the bit vector at +0x8 set (0 when out of range).
 * Sister of 0x888C15A0 (clear, eq_q5f_bits_clear.c).
 * Not byte-matched: the target stages the iterator pair through the stack. */
typedef struct Q5BitIt { u32 *word; u32 bit; } Q5BitIt;
typedef struct Q5BitVec { Q5BitIt first; Q5BitIt last; } Q5BitVec;
typedef struct Q5BitRef { u32 *word; u32 mask; } Q5BitRef;
typedef struct Q5BitOwner { char pad[8]; Q5BitVec bits; } Q5BitOwner;
extern Q5BitRef *fn_8817E150(Q5BitRef *out, Q5BitVec *v, u32 idx);
static __inline u32 q5_bits_size(const Q5BitVec *v)
{
    return (u32)((v->last.word - v->first.word) * 32) - v->first.bit + v->last.bit;
}

/* Swing_DLL.xex 0x888C1368 */
int ts4_bits_test_888C1368(Q5BitOwner *self, u32 idx)
{
    if (idx < q5_bits_size(&self->bits)) {
        Q5BitRef t;
        Q5BitRef *r = fn_8817E150(&t, &self->bits, idx);
        return (*r->word & r->mask) != 0;
    }
    return 0;
}

/* ---- 0x8887C000: reset the tables: zero the count and index (+0x10, +0x14), empty the three
 * element vectors at +0x50, +0x38 and +0x44, clear the lists at +0x5c and +0x68 and finalize
 * the object at +0x74.
 * Not byte-matched (12 off, perm_auto best 12): scheduling of the final vector end store. */
typedef struct Q5Item Q5Item;
typedef struct Q5Vec3w { Q5Item *begin; Q5Item *end; void *alloc; } Q5Vec3w;
typedef struct Q5Tables { char pad[0x10]; u32 count; u32 index; char pad18[0x20]; Q5Vec3w b38; Q5Vec3w b44;
    Q5Vec3w b50; char list5c[0xc]; char list68[0xc]; char obj74[4]; } Q5Tables;
extern Q5Item *fn_88186110(Q5Item *first, Q5Item *last, Q5Item *dest);
extern void fn_881A6728(void *list);

static __inline void q5_vec_clear(Q5Vec3w *v)
{
    Q5Item **pe = &v->end;
    *pe = fn_88186110(*pe, *pe, v->begin);
}

/* Swing_DLL.xex 0x8887C000 */
void ts4_tables_reset_8887C000(Q5Tables *self)
{
    self->count = 0;
    self->index = 0;
    q5_vec_clear(&self->b50);
    q5_vec_clear(&self->b38);
    q5_vec_clear(&self->b44);
    fn_881A6728(self->list5c);
    fn_881A6728(self->list68);
    ts4_object_finalize(self->obj74);
}

/* ---- 0x888E9898: find the record for `key` in the table returned by the null-handle lookup of
 * hash 0x042947AB; when found, copy its +0x24 word to +0x28, clear the script property and
 * service every u32 in the record's self-relative array (+0x0 offset, +0x4 count).
 * Not byte-matched (2 off, perm_auto best 2): `mr r29,r3` is scheduled before the key spill. */
typedef struct Q5PropRec { int off; u32 count; char pad08[0x1c]; u32 f24; u32 f28; } Q5PropRec;
typedef struct Q5PropHolder Q5PropHolder;
extern void *ts4_hash_find_null_888E1D40(void);
extern Q5PropRec *ts4_find_record_by_key_881877A8(void *tbl, u32 *key);
extern void ts4_clear_script_prop_052C33A9_888C82D0(Q5PropHolder *self);
extern void ts4_hash_service_str_888C8370(Q5PropHolder *self, u32 value);

static __inline u32 *q5_rel_end(Q5PropRec *r)
{
    u32 *e = 0;
    if (r->off != -1)
        e = (u32 *)((char *)r + r->off) + r->count;
    return e;
}
static __inline u32 *q5_rel_begin(Q5PropRec *r)
{
    u32 *b = 0;
    if (r->off != -1)
        b = (u32 *)((char *)r + r->off);
    return b;
}

/* Swing_DLL.xex 0x888E9898 */
void ts4_apply_prop_record_888E9898(Q5PropHolder *self, u32 key)
{
    Q5PropRec *r = ts4_find_record_by_key_881877A8(ts4_hash_find_null_888E1D40(), &key);
    if (r) {
        u32 *it;
        u32 *end;
        r->f28 = r->f24;
        ts4_clear_script_prop_052C33A9_888C82D0(self);
        end = q5_rel_end(r);
        for (it = q5_rel_begin(r); it != end; it++)
            ts4_hash_service_str_888C8370(self, *it);
    }
}
