/* CX13 part b: Pam core (0x88616000-0x8861B000): string-keyed dispatch, vector helpers, message handlers. Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
typedef unsigned int cx13_uptr;
#define CX13_INL static __forceinline
#pragma intrinsic(strcmp)
extern int strcmp(const char *, const char *);
#else
typedef unsigned long cx13_uptr;
#define CX13_INL static inline
#include <string.h>
#endif

extern void *fn_88562DC0(void *dst, const void *src, u32 n);
extern void ts4_registry_dispatch_888860A0(void *p);
extern void *ts4_node_dispatch_8860DCF8(void *o, u32 a, u32 b, u32 c);

/* ---- two-name dispatch ---- */
extern char lbl_880F7610[];
extern char lbl_880F761C[];
extern u32 fn_88615468();
typedef struct PObj { u32 pad0; void *f4; u8 pad8[0x10]; u32 f18; u8 pad1c[8]; u32 f24; u32 f28; u32 f2c; } PObj;

/* 0x88616E58: when a pending request is set, hand it to fn_88615468 under the mode named by the string (two known names), then clear it */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_name_dispatch_clear_88616E58(PObj *self, const char *name)
{
    u32 *p = &self->f24;
    if (*p != 0) {
        if (strcmp(name, lbl_880F7610) == 0) {
            self->f18 = fn_88615468(self->f4, p, self->f18, 1, 0);
        } else if (strcmp(name, lbl_880F761C) == 0) {
            fn_88615468(self->f4, p, self->f18, 2, self->f2c, self->f28);
        }
        *p = 0;
        self->f2c = 0;
        self->f28 = 0;
    }
}

/* ---- growable u32 vector ---- */
typedef struct RVec { u8 pad0[0x17c]; void *owner; u32 *data; u32 count; u32 cap; u32 step; } RVec;

/* 0x886187C0: append a word, first growing the storage by the step size (copy of the old words, old block released) when full */
void ts4_u32_vec_push_back_886187C0(RVec *self, u32 value)
{
    if (self->count >= self->cap) {
        u32 newcap = self->step + self->cap;
        u32 *p = (u32 *)ts4_node_dispatch_8860DCF8(self->owner, newcap * 4, 4, 2);
        u32 *old = self->data;
        u32 *end = old + self->cap;
        if (end != old) fn_88562DC0(p, old, (u32)((char *)end - (char *)old));
        ts4_registry_dispatch_888860A0(self->data);
        self->data = p;
        self->cap = newcap;
    }
    self->data[self->count] = value;
    self->count++;
}

/* ---- owned object vector ---- */
extern void ts4_vec204_move_tail_881B9148(void *p);
typedef struct UObj UObj;
typedef struct UVt { void *(*dtor)(UObj *, u32); void *s1[4]; void (*f14)(UObj *); } UVt;
struct UObj { const UVt *vt; };
typedef struct UVec { UObj **begin; UObj **end; } UVec;
CX13_INL UObj **ucopy(UObj **first, UObj **last, UObj **dest)
{
    if (first == last) {
        return dest;
    } else {
        u32 n = (u32)((char *)last - (char *)first);
        dest = (UObj **)fn_88562DC0(dest, first, n);
        return (UObj **)((char *)dest + n);
    }
}
typedef struct USelf2 { u8 pad0[8]; u8 flag; u8 pad9[7]; u8 sub[0x14]; UVec vec; } USelf2;

/* 0x8861A720: release every owned object (slot 5, then delete), empty the vector, clear the flag, reset the sub-vector */
void ts4_owned_vec_destroy_8861A720(USelf2 *self)
{
    UObj **end = self->vec.end;
    UObj **it = self->vec.begin;
    if (end != it) {
        do {
            (*it)->vt->f14(*it);
            if (*it != 0) (*it)->vt->dtor(*it, 1);
            it++;
        } while (it != end);
    }
    { UVec *v = &self->vec; v->end = ucopy(v->end, v->end, v->begin); }
    self->flag = 0;
    ts4_vec204_move_tail_881B9148(self->sub);
}

/* ---- object creation through the global registry ---- */
typedef struct VH { void **obj; u32 id; u32 extra; } VH;
typedef struct VObj VObj;
typedef struct VVt { void *s[10]; void (*f28)(VH *, VObj *, u32, u32, u32); } VVt;
struct VObj { const VVt *vt; };
typedef struct VSelfVt { void *s[23]; void (*f5c)(void *self, void *p, u32 a, u32 b); } VSelfVt;
typedef struct VSelf { const VSelfVt *vt; u8 pad[0x20]; u8 flag; } VSelf;
typedef struct VReg { u8 pad[0x220]; VObj *f220; VObj *f224; } VReg;
typedef struct VInner VInner;
typedef struct VInnerVt { void *s[22]; void (*f58)(VInner *, VH *); } VInnerVt;
struct VInner { const VInnerVt *vt; };
typedef struct VTgt { u32 pad0; VInner *inner; } VTgt;
extern VReg *lbl_88D45B1C;

/* 0x88619DB0: ask one of two registry factories (chosen by a flag) for a handle, let self adopt it, then finish it through its inner object */
void ts4_object_create_by_flag_88619DB0(VSelf *self, u32 a, u32 b)
{
    VObj *o;
    VH h;
    if (self->flag != 0) o = lbl_88D45B1C->f220; else o = lbl_88D45B1C->f224;
    o->vt->f28(&h, o, a, 0x21, 0);
    self->vt->f5c(self, h.obj, a, b);
    ((VTgt *)h.obj)->inner->vt->f58(((VTgt *)h.obj)->inner, &h);
}

/* ---- message handler ---- */
typedef struct WSelf WSelf;
typedef struct WVt { void *s[26]; u32 (*f68)(WSelf *); } WVt;
struct WSelf { const WVt *vt; u8 pad4[0x60]; u8 b64; u8 pad65[3]; u32 f68; u8 b6c; u8 pad6d[3]; u32 f70; u32 f74; u8 b78; };
typedef struct WMsg { u8 pad0[4]; u32 key; u32 f8; u8 bc; u8 padd[3]; u32 f10; } WMsg;
extern void *lbl_88D45B38;
extern u32 fn_88618998(void *reg, u32 id);

/* 0x88619C18: record the message value; for the two known message keys reset the pending result fields, then optionally forward to slot 26 */
u32 ts4_msg_handle_88619C18(WSelf *self, WMsg *m, u8 skip)
{
    u32 ok = 1;
    if (self->b64 != 0) {
        u32 k;
        self->f68 = m->f8;
        k = m->key;
        if (k == 0xBC959F53) {
            u32 z = 0;
            u32 r = z;
            if (((volatile WMsg *)m)->f10 != 0) r = fn_88618998(lbl_88D45B38, m->f10);
            self->f74 = r;
            self->f70 = z;
            self->b6c = z;
            self->b78 = z;
        } else if (k == 0x27BB1078) {
            u32 z = 0;
            self->f74 = z;
            self->f70 = 2;
            self->b6c = z;
            self->b78 = z;
        }
        if (m->bc != 0 && skip == 0) ok = self->vt->f68(self);
    }
    return ok;
}

/* ---- locked node lookup ---- */
typedef struct XLockVt { void *s0; void (*enter)(void *); void (*leave)(void *); } XLockVt;
typedef struct XLock { const XLockVt *vt; } XLock;
typedef struct XNode { u8 pad0[8]; u32 f8; u8 pad0c[0xc]; u32 f18; u32 f1c; } XNode;
typedef struct XOwner { u8 pad[0x2dd0]; XLock lock; } XOwner;
typedef struct XOut { XNode *node; } XOut;
extern XNode **fn_8860E320(u32 *tmp, XOwner *owner, u32 a, u32 flag);
extern XNode *ts4_if_call_seq_u32_lbl_88D45B38_882818C0(XOwner **o, u32 *d, u32 *c, u32 *b);
typedef struct XSlots { XOwner *ow; u32 b, c, d; } XSlots;

/* 0x8861A1C8: under the owner's lock find the node for a key and resolve it through the registry, storing the result in out */
XOut *ts4_node_lookup_locked_8861A1C8(XOut *out, XOwner *owner, u32 a)
{
    XLock *lock = &owner->lock;
    XSlots L;
    XNode *node;
    lock->vt->enter(lock);
    out->node = 0;
    node = *fn_8860E320(&L.d, owner, a, 1);
    out->node = node;
    if (node != 0) {
        u32 tb = node->f1c;
        u32 tc = node->f18;
        u32 td = node->f8;
        L.ow = owner;
        L.b = tb;
        L.c = tc;
        L.d = td;
        out->node = ts4_if_call_seq_u32_lbl_88D45B38_882818C0(&L.ow, &L.d, &L.c, &L.b);
    }
    lock->vt->leave(lock);
    return out;
}

/* ---- keyed item table setup ---- */
typedef struct AItem { u32 key; u32 val; } AItem;
typedef struct ASelf { u8 pad0[8]; u8 b8; } ASelf;
extern void fn_88617030(void *self);
extern void fn_8861D260(void *self, u32 k, u32 v);
extern void fn_88616B10(void *self, u32 k, u32 v);

/* 0x8861D6A8: register every (key, value) pair of a zero-terminated table, through one of two registrars chosen by a flag; the second also applies the name request */
void ts4_item_table_register_8861D6A8(ASelf *self, u32 a, AItem *arr)
{
    u32 i;
    if (self->b8 == 0) {
        fn_88617030(self);
        i = 0;
        while (arr[i].key != 0) {
            fn_8861D260(self, arr[i].key, arr[i].val);
            i++;
        }
    } else {
        i = 0;
        while (arr[i].key != 0) {
            fn_88616B10(self, arr[i].key, arr[i].val);
            i++;
        }
        ts4_name_dispatch_clear_88616E58((PObj *)self, (const char *)(unsigned long)a);
    }
}

/* ---- constructor with a bounded name copy ---- */
extern void *fn_886197F0(void *self);
extern char lbl_880F87E8[];
extern char lbl_880F74B8[];
typedef struct CSelf {
    const void *vt; u8 pad4[0x60]; u32 f64; u8 pad68[0x178 - 0x68];
    struct CSelf *f178; void *f17c; void *f180; u32 f184; u8 pad188[0x1b8 - 0x188]; char name[0x19]; u8 pad1d1[3];
    u32 f1d4; u32 f1d8; u32 f1dc; u32 f1e0;
} CSelf;
static void c_copy(char *dst, const char *src)
{
    char *end = dst + 0x19;
    while (dst != end && *src != 0) *dst++ = *src++;
    *dst = 0;
}

/* 0x8861F9B8: constructor: base init, self-linked list head, default state words and the default name (bounded to 0x19 bytes) */
CSelf *ts4_named_list_ctor_8861F9B8(CSelf *self)
{
    fn_886197F0(self);
    self->f178 = self;
    self->f1d4 = 0;
    self->f17c = &self->f178;
    self->f1d8 = 0;
    self->vt = lbl_880F87E8;
    self->f1dc = 0;
    self->f1e0 = 0;
    self->f64 = 0x10;
    self->f180 = &self->f178;
    self->f184 = 0;
    c_copy(self->name, lbl_880F74B8);
    return self;
}

/* ---- owned object stack ---- */
typedef struct DObj DObj;
typedef struct DVt { void *(*dtor)(DObj *, u32); void *s1[4]; void (*f14)(DObj *); } DVt;
struct DObj { const DVt *vt; };
typedef struct DVec { DObj **begin; DObj **end; } DVec;
typedef struct DSelf { u8 pad0[8]; u8 flag; u8 pad9[7]; u8 sub[0xc]; DVec vec; } DSelf;
static DObj **dcopy(DObj **first, DObj **last, DObj **dest)
{
    if (first == last) {
        return dest;
    } else {
        u32 n = (u32)((char *)last - (char *)first);
        dest = (DObj **)fn_88562DC0(dest, first, n);
        return (DObj **)((char *)dest + n);
    }
}

/* 0x8861F018: clear the flag, reset the sub-vector, destroy the owned objects back to front and empty the vector */
void ts4_owned_stack_destroy_8861F018(DSelf *self)
{
    DVec *v;
    DObj **end;
    DObj **begin;
    self->flag = 0;
    ts4_vec204_move_tail_881B9148(self->sub);
    end = self->vec.end;
    v = &self->vec;
    begin = self->vec.begin;
    while (end != begin) {
        DObj *o = *(end - 1);
        o->vt->f14(o);
        o->vt->dtor(o, 1);
        end--;
    }
    v->end = dcopy(v->end, v->end, v->begin);
}

/* ---- item vector with registry-owned members ---- */
extern void ts4_tsu_cleanup_end(void *p);
typedef struct HObj HObj;
typedef struct HVt { void *(*dtor)(HObj *, u32); } HVt;
struct HObj { const HVt *vt; };
typedef struct HItem { u8 pad[0x208]; HObj *f208; void *f20c; } HItem;
typedef struct HVec { HItem **begin; HItem **end; } HVec;
CX13_INL HItem **hcopy(HItem **first, HItem **last, HItem **dest)
{
    if (first == last) {
        return dest;
    } else {
        u32 n = (u32)((char *)last - (char *)first);
        dest = (HItem **)fn_88562DC0(dest, first, n);
        return (HItem **)((char *)dest + n);
    }
}
typedef struct HSelf { u8 pad0[8]; u8 flag; u8 pad9[7]; u8 sub[0x14]; HVec vec; } HSelf;

/* 0x886226C0: release every item (its registered block and owned object, then the item itself), empty the vector and reset the sub-vector */
void ts4_item_vec_destroy_886226C0(HSelf *self)
{
    HItem **end = self->vec.end;
    HItem **it = self->vec.begin;
    if (it != end) {
        do {
            HItem *p = *it;
            if (p != 0) {
                if (*(int *)&p->f208 != 0) {
                    ts4_registry_dispatch_888860A0(p->f20c);
                    { HObj *o = p->f208; if (o != 0) o->vt->dtor(o, 1); }
                }
                ts4_tsu_cleanup_end(p);
            }
            it++;
        } while (it != end);
    }
    { HVec *v = &self->vec; v->end = hcopy(v->end, v->end, v->begin); }
    self->flag = 0;
    ts4_vec204_move_tail_881B9148(self->sub);
}

/* ---- command parsing state ---- */
typedef struct JSelf { u8 pad[0x81c]; int state; u8 pad820[4]; u8 b824; } JSelf;
extern u8 fn_88624980(JSelf *self);
extern u8 fn_886243E8(JSelf *self, const char *s);
extern u8 ts4_if_call_seq_u8_off824_88624370(JSelf *self, const char *s);

/* 0x88624A90: try the three parsers in turn on a non-empty string; with nothing accepted and the flag set move the state to 6 (5 for an empty string) */
u8 ts4_parse_try_all_88624A90(JSelf *self, const char *s)
{
    u8 r = 0;
    if (*s != 0) {
        r = fn_88624980(self);
        if (r == 0) r = fn_886243E8(self, s);
        if (r == 0) r = ts4_if_call_seq_u8_off824_88624370(self, s);
        if (r == 0 && self->b824 == 1 && self->state == 0) self->state = 6;
    } else if (self->b824 == 1 && self->state == 0) {
        self->state = 5;
    }
    return r;
}

typedef struct KSelf { u8 pad[0x80c]; u32 *begin; u32 *end; u8 pad814[8]; int state; u8 pad820[4]; u8 b824; } KSelf;
extern u8 fn_8861BB18(KSelf *self, u32 s);
extern u8 fn_8861BAA0(KSelf *self, u32 s);
extern u8 fn_8861B8E0(KSelf *self, u32 s);
extern u8 fn_88624B58(KSelf *self, u32 s);

/* 0x88624E20: offer each queued entry to four handlers in turn; stop at the first one nobody takes, moving the state to 8 when the flag is set */
void ts4_queue_dispatch_88624E20(KSelf *self)
{
    u32 *end = self->end;
    u32 *it = self->begin;
    for (; end != it; it++) {
        u32 s = *it;
        u8 r = fn_8861BB18(self, s);
        if (r == 0) r = fn_8861BAA0(self, s);
        if (r == 0) r = fn_8861B8E0(self, s);
        if (r == 0) r = fn_88624B58(self, s);
        if (r == 0) {
            if (self->b824 == 1 && self->state == 0) self->state = 8;
        }
        if (r == 0) break;
    }
}
