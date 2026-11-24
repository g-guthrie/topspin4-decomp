/* Q5 equivalent route, batch F: small gameplay functions (0x88-0x90 bytes) proven by
 * tools/fn_equiv.py rather than byte-matched (see the spec's evidence file). Each block
 * names the reason the byte match is out of reach. */
#include "ts4_vector.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern float lbl_8814B440;              /* 0.0f */
extern float g_ts4_script_constants[];

/* ---- 0x886E7EF0: constructor: base ctor 0x88617D88, vtable lbl_880F34BC, two 16-byte
 * defaults (lbl_880FC770, lbl_880FC760) at +0x20/+0x30, flag +0x8c = 1, rest cleared.
 * Not byte-matched: the address loads and stores are scheduled differently
 * (perm_auto best 14). */
typedef struct Q5Ctor7EF0 {
    void *vtbl;
    char pad4[0x18];
    u32 w1c;
    __vector4 v20[2];           /* +0x20 */
    char pad40[0x38];
    u32 w78, w7c, w80, w84, w88;
    u32 w8c;
} Q5Ctor7EF0;
extern void *fn_88617D88(void *self);
extern char lbl_880F34BC[];
extern __vector4 lbl_880FC770, lbl_880FC760;

/* Swing_DLL.xex 0x886E7EF0 */
/* byte-gap: 14 off; address loads and stores are scheduled differently (perm_auto best 14) */
Q5Ctor7EF0 *ts4_ctor_886E7EF0(Q5Ctor7EF0 *self)
{
    __vector4 *v;
    __vector4 a, b;
    fn_88617D88(self);
    v = self->v20;
    a = lbl_880FC770;
    b = lbl_880FC760;
    self->w1c = 0;
    self->vtbl = lbl_880F34BC;
    v[0] = a;
    v[1] = b;
    self->w8c = 1;
    self->w78 = 0;
    self->w7c = 0;
    self->w80 = 0;
    self->w84 = 0;
    self->w88 = 0;
    return self;
}

/* ---- 0x887F8710: script VM "not": frame[arg1] = !frame[arg0], where each argument is a
 * self-relative record whose u16 at +2 indexes the frame's data (frame + *(int *)frame);
 * then notify the owner (vtable slot 13) and return 1.
 * Not byte-matched: the original keeps a dead copy of the data offset (`mr r10,r8`)
 * that no source shape reproduced (perm_auto best 21). */
typedef struct Q5VmObj { struct Q5VmObjVt *vt; } Q5VmObj;
typedef struct Q5VmObjVt { int (*slot[16])(Q5VmObj *, u32, u32); } Q5VmObjVt;
typedef struct Q5VmCtx2 { char p[0x20]; char *frame; } Q5VmCtx2;
typedef struct Q5VmCtx { char p[0x1c]; Q5VmCtx2 *c; } Q5VmCtx;
typedef struct Q5VmOp {
    char p[8];
    u32 w8;
    char pc[0x14];
    Q5VmCtx *ctx;   /* +0x20 */
    Q5VmObj *obj;   /* +0x24 */
    char *args;     /* +0x28 */
    u32 w2c;
} Q5VmOp;
static __inline u16 q5_arg_index(char *a)
{
    return *(u16 *)(a + *(int *)a + 2);
}

/* Swing_DLL.xex 0x887F8710 */
/* byte-gap: 21 off; original keeps a dead copy of the data offset (mr r10,r8) that no source shape reproduced (perm_auto best 21) */
int ts4_vm_not_887F8710(Q5VmOp *op)
{
    char *frame = op->ctx->c->frame;
    char *a = op->args;
    u16 i0 = q5_arg_index(a);
    u16 i1 = q5_arg_index(a + 0xc);
    int off = *(int *)frame;
    char *src = frame + (i0 + off);
    char *dst = frame + (i1 + off);
    *dst = *src == 0;
    op->obj->vt->slot[13](op->obj, op->w8, op->w2c);
    return 1;
}

/* ---- 0x8887EB10: destructor body: set vtable lbl_880DF930, then free the ten owned
 * pointers of the 12-byte slots at +0x30, last first, through the registry
 * (lbl_88D45B38) or fn_885651F8 when there is none. The registry pointer is read once
 * and re-read only after a registry call, as in the original.
 * Not byte-matched: `li r27,9` and the vtable store swap places (perm_auto best 2). */
typedef struct Q5Reg { char p[0x24]; void *fallback; } Q5Reg;
extern Q5Reg *lbl_88D45B38;
extern void *ts4_find_range_owner_8860D360(Q5Reg *registry, void *key);
extern void fn_8860DBC8(void *entry, void *key);
extern void fn_885651F8(void *p);
extern char lbl_880DF930[];
typedef struct Q5Slot { void *p; u32 a, b; } Q5Slot;
typedef struct Q5Slots { void *vtbl; char pad[0x2c]; Q5Slot slot[10]; } Q5Slots;

/* Swing_DLL.xex 0x8887EB10 */
/* byte-gap: 2 off; `li r27,9` and the vtable store swap places (perm_auto best 2) */
void ts4_slots_dtor_8887EB10(Q5Slots *self)
{
    int i;
    Q5Slot *s;
    Q5Reg *reg;
    self->vtbl = lbl_880DF930;
    s = &self->slot[10];
    reg = lbl_88D45B38;
    for (i = 9; i >= 0; i--) {
        void *p = (--s)->p;
        if (p != 0) {
            if (reg != 0) {
                void *e = ts4_find_range_owner_8860D360(reg, p);
                if (e != 0) {
                    fn_8860DBC8(e, p);
                    reg = lbl_88D45B38;
                } else {
                    fn_8860DBC8(reg->fallback, p);
                    reg = lbl_88D45B38;
                }
            } else {
                fn_885651F8(p);
            }
        }
    }
}

/* ---- 0x888C3198: apply a 12-byte rect: the full-screen default {0, 0xFFFFF, 0} when
 * `full` is set, else the one at +0x28; copy it into the global at lbl_88D45AD4 (+0xd4,
 * with +0x160 = !full) and, if present, the mirror at lbl_88D45A78 (+0x28).
 * Not byte-matched: the rect copy is staged through different registers. */
typedef struct Q5Rect { u32 a, b, c; } Q5Rect;
typedef struct Q5G { char p[0xd4]; Q5Rect r; char pe[0x160 - 0xe0]; u8 b160; } Q5G;
typedef struct Q5M { char p[0x28]; Q5Rect r; } Q5M;
extern Q5G *lbl_88D45AD4;
extern Q5M *lbl_88D45A78;
typedef struct Q5RectOwner { char p[0x28]; Q5Rect r; } Q5RectOwner;

/* Swing_DLL.xex 0x888C3198 */
/* byte-gap: 31 off; rect copy is staged through different registers */
void ts4_rect_apply_888C3198(Q5RectOwner *self, u8 full)
{
    Q5G *g = lbl_88D45AD4;
    Q5Rect tmp;
    const Q5Rect *r;
    Q5Rect v;
    g->b160 = full == 0;
    if (full) {
        tmp.a = 0;
        tmp.c = 0;
        tmp.b = 0xFFFFF;
        r = &tmp;
    } else {
        r = &self->r;
    }
    v = *r;
    g->r = v;
    if (lbl_88D45A78 != 0)
        lbl_88D45A78->r = v;
}

/* ---- 0x888DA428: bind hash 0xA3794455: resolve the name in the inner object's scope
 * (0x8861E118), build its key (0x882823E0) and register it with fn_88625EA8 together with
 * the caller's argument, mode 2 and the no-op callback; then free the name.
 * Not byte-matched: the original keeps the constant call arguments in callee-saved
 * registers across the key call (frame 0xd0). */
typedef struct Q5Name { void *owned; u32 w[3]; } Q5Name;
typedef struct Q5Key { u32 w[4]; } Q5Key;
typedef struct Q5Inner { char p[0x20]; void *scope; } Q5Inner;
typedef struct Q5Outer { char p[0x20]; Q5Inner *inner; } Q5Outer;
extern void fn_8861E118(Q5Name *out, void *scope, u32 hash);
extern void *fn_882823E0(Q5Key *out, Q5Name *name);
extern void fn_88625EA8(Q5Inner *inner, void *key, u32 hash, void *arg, u32 a5, u32 a6,
                        void (*cb)(void), u32 a8, u8 a9);
extern void ts4_noop_881B3360(void);
extern void ts4_destroy_owned_object(void *p);

/* Swing_DLL.xex 0x888DA428 */
/* byte-gap: 31 off; the original keeps the constant call arguments in callee-saved registers across the key call (frame 0xd0) */
void ts4_bind_A3794455_888DA428(Q5Outer *self, void *arg)
{
    Q5Inner *inner = self->inner;
    Q5Name name;
    Q5Key key;
    fn_8861E118(&name, inner->scope, 0xA3794455);
    fn_88625EA8(inner, fn_882823E0(&key, &name), 0xA3794455, arg, 0, 2, ts4_noop_881B3360, 0, 0);
    ts4_destroy_owned_object(name.owned);
}

/* ---- 0x888DC298: send two vectors with the hash 0x5392B268: (y0, k * x0, c) and
 * (y1, k * x1, c), where k = 1 when t equals constants[0x38] and t * constants[0x788]
 * otherwise. 12-byte values pass by value in GPR pairs (sister of 0x888D9420).
 * Not byte-matched: the target emits `fmuls f13,f5,f0` and every source order gives
 * `fmuls f13,f0,f5` (the same operand-order miss as the 0x888C5C00 draft). */
typedef struct Q5V3 { float x, y, z; } Q5V3;
extern void fn_888D0FE0(void *self, u32 hash, Q5V3 a, Q5V3 b);

/* Swing_DLL.xex 0x888DC298 */
/* byte-gap: 1 off; target emits fmuls f13,f5,f0 and every source order gives fmuls f13,f0,f5 (same operand-order miss as 0x888C5C00) */
void ts4_send_scaled_5392B268_888DC298(void *self, float x0, float x1, float y0, float y1, float t)
{
    float k;
    Q5V3 a, b;
    if (t == g_ts4_script_constants[0x38 / 4])
        k = g_ts4_script_constants[0];
    else
        k = t * g_ts4_script_constants[0x788 / 4];
    a.x = y0;
    a.y = k * x0;
    a.z = g_ts4_script_constants[0x1e0 / 4];
    b.x = y1;
    b.y = k * x1;
    b.z = g_ts4_script_constants[0x1e0 / 4];
    fn_888D0FE0(self, 0x5392b268, a, b);
}

/* ---- 0x886D0808: visit each 16-byte entry of the self-relative table at +0x70 (offset
 * -1 = empty) with fn_886CA858. The original also computes each entry's index (via
 * ts4_decode_rel_ptr_off0_881BB8A0) and compares it with `want` into cr6, which the
 * callee never reads.
 * Not byte-matched: LTCG keeps the compare whose consumer was dropped. */
typedef struct Q5RelTab { int off; int count; } Q5RelTab;
typedef struct Q5RelEnt { char b[0x10]; } Q5RelEnt;
typedef struct Q5RelOwner { char p[0x70]; Q5RelTab *tab; } Q5RelOwner;
extern void *ts4_decode_rel_ptr_off0_881BB8A0(char *p);
extern void fn_886CA858(Q5RelOwner *self, Q5RelEnt *e);

/* Swing_DLL.xex 0x886D0808 */
/* byte-gap: 30 off; LTCG keeps the compare whose consumer was dropped */
void ts4_rel_entries_visit_886D0808(Q5RelOwner *self, int want)
{
    Q5RelTab *t = self->tab;
    Q5RelEnt *end, *it;
    if (t == 0)
        return;
    end = 0;
    if (t->off != -1)
        end = (Q5RelEnt *)((char *)t + t->off + t->count * 0x10);
    it = 0;
    if (t->off != -1)
        it = (Q5RelEnt *)((char *)t + t->off);
    for (; it != end; it++) {
        int idx = (int)(it - (Q5RelEnt *)ts4_decode_rel_ptr_off0_881BB8A0((char *)t));
        (void)(idx == want);    /* result unused, see above */
        fn_886CA858(self, it);
    }
}

/* ---- 0x886D5028: clear the owner's three vectors, then unwind the layer stack of `obj`
 * (u32 vector at +0x5c/+0x60) from the top: report each layer with its index to
 * fn_886D4978, stopping after the active layer (ts4_anim_layer_index_886C66C0).
 * Not byte-matched: LTCG keeps `obj` in r4 across ts4_clear_three_vectors_886C3658. */
typedef struct Q5Layers { char p[0x58]; u32 cap; u32 *begin; u32 *end; } Q5Layers;
extern void ts4_clear_three_vectors_886C3658(void *self);
extern int ts4_anim_layer_index_886C66C0(Q5Layers *stack);
extern void fn_886D4978(void *self, Q5Layers *obj, u32 item, int index);

/* Swing_DLL.xex 0x886D5028 */
/* byte-gap: 30 off; LTCG keeps obj in r4 across ts4_clear_three_vectors_886C3658 */
void ts4_layers_unwind_886D5028(void *self, Q5Layers *obj)
{
    u32 *begin, *it;
    u32 key;
    int i;
    ts4_clear_three_vectors_886C3658(self);
    begin = obj->begin;
    key = begin[ts4_anim_layer_index_886C66C0(obj)];
    it = obj->end;
    for (i = (int)(obj->end - obj->begin) - 1; it != begin; i--) {
        u32 *p = it - 1;
        fn_886D4978(self, obj, *p, i);
        if (key == *p)
            break;
        it = p;
    }
}

/* ---- 0x888C4160: empty the 0x1c-byte vector at +0xc by repeatedly erasing its first
 * element (fn_88185878 moves the tail down), then zero the vec3 at
 * self->+4->+0x44->+0x10 (+0xc..+0x14).
 * Not byte-matched: the final pointer lands in r8 instead of r11. */
typedef struct Q5E1c { char b[0x1c]; } Q5E1c;
typedef struct Q5Vec1c { Q5E1c *begin; Q5E1c *end; } Q5Vec1c;
typedef struct Q5Tgt { char p[0xc]; float x, y, z; } Q5Tgt;
typedef struct Q5Mid { char p[0x10]; Q5Tgt *tgt; } Q5Mid;
typedef struct Q5Top { char p[0x44]; Q5Mid *mid; } Q5Top;
typedef struct Q5Clr { u32 w0; Q5Top *top; char p8[4]; Q5Vec1c v; } Q5Clr;
extern Q5E1c *fn_88185878(Q5E1c *first, Q5E1c *last, Q5E1c *dest);
static __inline void q5_set3(Q5Tgt *t, float x, float y, float z)
{
    t->x = x;
    t->y = y;
    t->z = z;
}

/* Swing_DLL.xex 0x888C4160 */
/* byte-gap: 4 off; final pointer lands in r8 instead of r11 */
void ts4_clear_and_zero_888C4160(Q5Clr *self)
{
    Q5Vec1c *v = &self->v;
    while (v->end - v->begin != 0) {
        Q5E1c *b = v->begin;
        if (b + 1 != v->end)
            fn_88185878(b + 1, v->end, b);
        v->end--;
    }
    q5_set3(self->top->mid->tgt, lbl_8814B440, lbl_8814B440, lbl_8814B440);
}

/* ---- 0x886B1578: constructor: vtables lbl_880F4424 (+0) and lbl_880F4854 (+0x20),
 * ten 0x41c-byte shots at +0x34 built by fn_886AD158, all other fields cleared.
 * Not byte-matched: LTCG keeps the shot pointer, count and zero in r3/r4/r5 across
 * fn_886AD158 (a leaf that does not write them). */
typedef struct Q5Shot41c { char b[0x41c]; } Q5Shot41c;
typedef struct Q5ShotSet {
    void *vtbl;             /* +0x00 */
    u8 b4;                  /* +0x04 */
    char p5[3];
    u32 w8, wc, w10;        /* +0x08 */
    char p14[4];
    u32 w18, w1c;           /* +0x18 */
    void *vtbl20;           /* +0x20 */
    u32 w24, w28, w2c, w30; /* +0x24 */
    Q5Shot41c shot[10];     /* +0x34 */
    u32 w294c, w2950, w2954; /* +0x294c */
} Q5ShotSet;
extern char lbl_880F4424[], lbl_880F4854[];
extern void fn_886AD158(Q5Shot41c *shot);

/* Swing_DLL.xex 0x886B1578 */
/* byte-gap: 30 off; LTCG keeps the shot pointer, count and zero in r3/r4/r5 across fn_886AD158 */
Q5ShotSet *ts4_shot_set_ctor_886B1578(Q5ShotSet *self)
{
    int i;
    Q5Shot41c *s;
    self->vtbl = lbl_880F4424;
    self->w10 = 0;
    self->vtbl20 = lbl_880F4854;
    self->w28 = 0;
    self->w2c = 0;
    self->w30 = 0;
    self->w24 = 0;
    s = self->shot;
    for (i = 9; i >= 0; i--) {
        fn_886AD158(s);
        s++;
    }
    self->w294c = 0;
    self->w2950 = 0;
    self->w2954 = 0;
    self->w8 = 0;
    self->wc = 0;
    self->w1c = 0;
    self->w18 = 0;
    self->b4 = 0;
    return self;
}

/* ---- 0x888C5D80: for each of the 8 pads whose slot is active, send a zero stick
 * (+0x20c) to the pad's device; +0x1fc = every send succeeded (sister of 0x888C5C00).
 * Not byte-matched: the original hoists -1 into a callee-saved register. */
typedef struct Q5PadRec { char p[0x10]; int id; } Q5PadRec;
typedef struct Q5ModList Q5ModList;
typedef struct Q5Engine { char p[0x234]; Q5ModList *modules; } Q5Engine;
extern Q5Engine *lbl_88D45B1C;
extern Q5PadRec *ts4_pad_record_find_88614938(Q5ModList *m, int pad);
extern int ts4_if_call_seq_u32_off0_8857B180(int id, void *xy);
/* Pad slots are 0x3c bytes apart with their active flag at +0x54 + 0x3c * i; the
 * stride runs past +0x1fc, so the slot layout overlaps the fields below and is
 * addressed by offset. */
typedef struct Q5PadOut {
    char p[0x1fc];
    u8 all_ok;              /* +0x1fc */
    char p1fd[0x20c - 0x1fd];
    u16 xy[2];              /* +0x20c */
} Q5PadOut;
static int q5_pad_id(int i)
{
    Q5PadRec *e = ts4_pad_record_find_88614938(lbl_88D45B1C->modules, i);
    return e ? e->id : -1;
}

/* Swing_DLL.xex 0x888C5D80 */
/* byte-gap: 28 off; original hoists -1 into a callee-saved register */
void ts4_pad_zero_all_888C5D80(Q5PadOut *self)
{
    u32 i;
    u8 ok = 1;
    for (i = 0; i < 8; i++) {
        if (*((u8 *)self + 0x54 + i * 0x3c)) {
            int id = q5_pad_id((int)i);
            self->xy[0] = 0;
            self->xy[1] = 0;
            ok &= ts4_if_call_seq_u32_off0_8857B180(id, self->xy) == 0;
        }
    }
    self->all_ok = ok;
}
