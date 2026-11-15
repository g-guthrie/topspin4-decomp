/* CX26 part a: game core 0x881732E0-0x8818C6C0 (LTCG-range code), plain route, no flags. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, u32);
#pragma function(memcpy)
typedef u32 Cx26Up;
typedef int Cx26Sp;
#else
#include <string.h>
typedef unsigned long Cx26Up;
typedef long Cx26Sp;
#endif

extern void *lbl_88D45B38;
extern void *ts4_find_range_owner_8860D360(void *heap, void *p);
extern void ts4_node_visit_8860DBC8(void *a, void *p);
extern void fn_885651F8(void *p);
extern void *ts4_set_table_0_8841B478(void *p);
extern void fn_881935D8(void *p);
extern void *fn_88562DC0(void *dst, void *src, u32 n);
extern void ts4_destroy_owned_object(void *p);
extern void *ts4_if_call_seq_u32_lbl_88D45B38_88162340(void *ctx, u32 n);
extern u8 ts4_obj_int0_cmp_888C0590(void *a, void *b);
extern u8 ts4_obj_int4_cmp_888C05B0(void *a, void *b);

struct Cx26Vt { void *s[32]; };
struct Cx26Obj { const struct Cx26Vt *vt; };
typedef struct Cx26Heap { u8 pad[0x24]; void *f24; } Cx26Heap;

/* 0x88189CB8: destructor stub; with bit 0 of flags set, also hand the block back to its owner */
void *ts4_dtor_88189CB8(void *self, u32 flags)
{
    ts4_set_table_0_8841B478(self);
    if (flags & 1) {
        Cx26Heap *h = (Cx26Heap *)lbl_88D45B38;
        if (self) {
            void *r = ts4_find_range_owner_8860D360(h, self);
            if (r) ts4_node_visit_8860DBC8(r, self); else ts4_node_visit_8860DBC8(h->f24, self);
        }
    }
    return self;
}

/* 0x8818ADD0: release the object held in slot +0x34 (or reset when empty) */
typedef struct Cx26Slot { u8 pad[4]; struct Cx26SObj *o; } Cx26Slot;
struct Cx26SObjVt { void *s[32]; };
struct Cx26SObj { const struct Cx26SObjVt *vt; };
typedef struct Cx26Ad { u8 pad[0x34]; Cx26Slot *slot; u8 pad2[0xc]; u32 f44; } Cx26Ad;
void ts4_release_slot_8818ADD0(Cx26Ad *self)
{
    Cx26Slot **pp = &self->slot;
    if ((Cx26Sp)*(Cx26Slot * volatile *)pp != 0) {
        struct Cx26SObj *o = (*pp)->o;
        ((void (*)(struct Cx26SObj *, Cx26Slot **))o->vt->s[22])(o, pp);
        self->f44 = 0;
        *pp = 0;
    } else {
        fn_881935D8(self);
    }
    self->f44 = 0;
}

/* 0x88180D00: make sure a pointer vector has room for 2 entries */
typedef struct Cx26PV { u32 *b; u32 *e; u32 *c; } Cx26PV;
void ts4_pv_reserve2_88180D00(Cx26PV *v)
{
    u32 *b = v->b;
    if ((u32)(v->c - b) < 2) {
        u32 n = v->e - b;
        u32 *nb;
        if (b != 0) {
            u32 *old_e = v->e;
            nb = (u32 *)ts4_if_call_seq_u32_lbl_88D45B38_88162340(&v->c, 2);
            if (old_e != b) fn_88562DC0(nb, b, (char *)old_e - (char *)b);
            b = nb;
            ts4_destroy_owned_object(v->b);
        } else {
            b = (u32 *)ts4_if_call_seq_u32_lbl_88D45B38_88162340(&v->c, 2);
        }
        v->b = b;
        v->c = b + 2;
        v->e = b + n;
    }
}

/* 0x88185F70: insertion sort of [first,last) ordered by ts4_obj_int0_cmp */
void ts4_insertion_sort_int0_88185F70(u32 *first, u32 *last)
{
    u32 *i;
    if (first == last) return;
    for (i = first + 1; i != last; i++) {
        u32 val = *i;
        if (ts4_obj_int0_cmp_888C0590((void *)(Cx26Up)val, (void *)(Cx26Up)*first)) {
            int n = (char *)i - (char *)first;
            if (n > 0) fn_88562DC0((char *)i - n + 4, first, n);
            *first = val;
        } else {
            u32 *cur = i;
            u32 *prev = cur - 1;
            while (ts4_obj_int0_cmp_888C0590((void *)(Cx26Up)val, (void *)(Cx26Up)*prev)) {
                *cur = *prev;
                cur = prev;
                prev--;
            }
            *cur = val;
        }
    }
}

/* 0x88186040: same with ts4_obj_int4_cmp */
void ts4_insertion_sort_int4_88186040(u32 *first, u32 *last)
{
    u32 *i;
    if (first == last) return;
    for (i = first + 1; i != last; i++) {
        u32 val = *i;
        if (ts4_obj_int4_cmp_888C05B0((void *)(Cx26Up)val, (void *)(Cx26Up)*first)) {
            int n = (char *)i - (char *)first;
            if (n > 0) fn_88562DC0((char *)i - n + 4, first, n);
            *first = val;
        } else {
            u32 *cur = i;
            u32 *prev = cur - 1;
            while (ts4_obj_int4_cmp_888C05B0((void *)(Cx26Up)val, (void *)(Cx26Up)*prev)) {
                *cur = *prev;
                cur = prev;
                prev--;
            }
            *cur = val;
        }
    }
}

/* 0x88187900: member-wise copy of a 0x61-byte record */
typedef struct Cx26Rec {
    u32 w0, w4, w8, wc, w10, w14;
    u16 h18, h1a, h1c, h1e;
    u8 b20, b21; u8 pad22[2];
    u32 w24, w28, w2c, w30;
    u8 blk[0x20];
    u8 b54; u8 pad55[3];
    u32 w58;
    u8 b5c, b5d, b5e, b5f, b60;
} Cx26Rec;
void ts4_rec_copy_88187900(Cx26Rec *d, Cx26Rec *s)
{
    d->w0 = s->w0; d->w4 = s->w4; d->w8 = s->w8; d->wc = s->wc; d->w10 = s->w10; d->w14 = s->w14;
    d->h18 = s->h18; d->h1a = s->h1a; d->h1c = s->h1c; d->h1e = s->h1e;
    d->b20 = s->b20; d->b21 = s->b21;
    d->w24 = s->w24; d->w28 = s->w28; d->w2c = s->w2c; d->w30 = s->w30;
    memcpy(d->blk, s->blk, 0x20);
    d->b54 = s->b54;
    d->w58 = s->w58;
    d->b5c = s->b5c; d->b5d = s->b5d; d->b5e = s->b5e; d->b5f = s->b5f; d->b60 = s->b60;
}

/* 0x8818AC18: ask the manager's factory object for a handle and attach it */
typedef struct Cx26Ret { u32 x; u32 y; u32 z; u32 w; } Cx26Ret;
typedef struct Cx26Mgr { u8 pad[0x224]; struct Cx26Obj *f224; } Cx26Mgr;
extern Cx26Mgr *lbl_88D45B1C;
typedef struct Cx26Acq { const struct Cx26Vt *vt; u8 pad[4]; u32 f8; u8 pad2[0x28]; u32 f34; u8 pad3[0xc]; struct Cx26Obj *f44; } Cx26Acq;
u32 ts4_acquire_8818AC18(Cx26Acq *self, u32 a)
{
    struct Cx26Obj *o;
    Cx26Ret tmp;
    Cx26Ret *rv;
    Cx26Mgr *mgr;
    int x;
    u32 ok;
    ((void (*)(Cx26Acq *))self->vt->s[13])(self);
    mgr = lbl_88D45B1C;
    ok = 1;
    o = mgr->f224;
    rv = ((Cx26Ret *(*)(Cx26Ret *, struct Cx26Obj *, u32, u32, u32))o->vt->s[10])(&tmp, o, a, 1, 0);
    x = rv->x;
    self->f34 = x;
    if (x != 0) {
        self->f44 = o;
    } else {
        ok = 0;
        self->f34 = ok;
    }
    self->f8 = 1;
    return ok;
}

/* 0x8818B408: copy up to n bytes out of the buffer at pos (-1 = current), flag a short read */
typedef struct Cx26Buf { u8 pad[0xc]; u8 trunc; u8 pad2[7]; u32 pos; u8 pad3[4]; int limit; u8 *data; } Cx26Buf;
u32 ts4_buf_read_8818B408(Cx26Buf *self, void *dst, u32 n, int pos)
{
    int lim;
    u32 cnt;
    if (n == 0) return 0;
    if (pos == -1) pos = self->pos;
    lim = self->limit;
    if (pos > lim) return 0;
    cnt = lim - pos;
    if (n + pos <= (u32)lim) cnt = n;
    memcpy(dst, self->data + pos, cnt);
    self->pos = cnt + pos;
    if (cnt != n) self->trunc = 1; else self->trunc = 0;
    return cnt;
}
