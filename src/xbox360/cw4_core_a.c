/* CW4: game core (XData, containers, UI node classes), 0x881732E0-0x8818C6C0. LTCG-range code, built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CW4_INL static __forceinline
extern int strcmp(const char *, const char *);
#pragma intrinsic(strcmp)
#else
#define CW4_INL static inline
#include <string.h>
#endif

extern void ts4_destroy_owned_object(void *obj);
extern void *fn_88562DC0(void *dst, void *src, u32 n);
extern void *fn_8817EE38(void *dst, void *a, void *b);
extern void ts4_loop_call_seq_u32_0x4_88181670(void *begin, void *end);
extern void *fn_88566220(void *a, void *b, void *c);
extern int ts4_if_call_seq_u32_offc_88565B10(void *p);
extern void ts4_tailcall_fn_88565BA8_88565CD8(void *p);
extern void ts4_assign_formatted_text(void *dst, void *src);
extern void fn_88166BC0(void *dst, void *src);
extern char lbl_880D585C[];

/* ---- virtual forwarders returning their hidden result pointer ---- */
struct Cw4Obj;
typedef void (*Cw4Fn)(void *, struct Cw4Obj *, u32, u32, u32, u32, u32, u32, u32);
struct Cw4Vt { void *s[16]; };
struct Cw4Obj { const struct Cw4Vt *vt; };
struct Cw4Holder { char pad[0x10]; struct Cw4Obj *child; };

/* 0x8818B898: forward to slot 15 of the child object at +0x10, passing the hidden result pointer through */
void *ts4_forward_child_slot15_8818B898(void *out, struct Cw4Holder *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 i)
{
    struct Cw4Obj *o = h->child;
    ((Cw4Fn)o->vt->s[15])(out, o, a, b, c, d, e, f, i);
    return out;
}

/* 0x8818B8E8: same as above through slot 14 */
void *ts4_forward_child_slot14_8818B8E8(void *out, struct Cw4Holder *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 i)
{
    struct Cw4Obj *o = h->child;
    ((Cw4Fn)o->vt->s[14])(out, o, a, b, c, d, e, f, i);
    return out;
}

/* ---- byte vector helpers ---- */
typedef struct Cw4Vec { char *first; char *last; } Cw4Vec;
CW4_INL char *cw4_copy(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        u32 n = (u32)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}

/* 0x88176A28: clear a vector stored at +8 by collapsing its end back to its begin */
typedef struct Cw4VecHolder { u32 pad[2]; Cw4Vec items; } Cw4VecHolder;
void ts4_vec_clear_88176A28(Cw4VecHolder *self)
{
    Cw4Vec *v = &self->items;
    v->last = cw4_copy(v->last, v->last, v->first);
}

/* 0x88187AB8: destroy the owned object (+8) of each 0x14-byte entry in [begin,end) */
typedef struct Cw4Elem14 { u32 pad[2]; void *owned; u32 pad2[2]; } Cw4Elem14;
void ts4_destroy_owned_range_88187AB8(Cw4Elem14 *begin, Cw4Elem14 *end)
{
    Cw4Elem14 *p;
    for (p = begin; p != end; p++) {
        if (p->owned) ts4_destroy_owned_object(p->owned);
    }
}

/* 0x8817E610: find the entry of the pointer array [0x2c,0x30) whose name (+0x30) equals lbl_880D585C */
typedef struct Cw4Named { u8 pad[0x30]; const char *name; } Cw4Named;
typedef struct Cw4Registry { u8 pad[0x2c]; Cw4Named **begin; Cw4Named **end; } Cw4Registry;
Cw4Named *ts4_find_named_8817E610(Cw4Registry *r)
{
    Cw4Named **end = r->end;
    Cw4Named **p;
    for (p = r->begin; p != end; p++) {
        if (strcmp((*p)->name, lbl_880D585C) == 0) return *p;
    }
    return 0;
}

/* 0x881816D8: destroy 16-byte entries in [begin,end): reset, collapse the owned range, destroy the owner */
typedef struct Cw4Ent16 { u32 f0; void *first; void *last; u32 f0c; } Cw4Ent16;
void ts4_destroy_ent16_range_881816D8(Cw4Ent16 *begin, Cw4Ent16 *end)
{
    Cw4Ent16 *p;
    for (p = begin; p != end; p++) {
        p->f0 = 0;
        fn_8817EE38(&p->first, p->first, p->last);
        ts4_loop_call_seq_u32_0x4_88181670(p->first, p->last);
        if (p->first) ts4_destroy_owned_object(p->first);
    }
}

/* 0x88177288: destroy 0x28-byte entries [begin,end): clear the vector at +0x18, free it and the owned object at +8 */
typedef struct Cw4Ent28 { u8 pad[8]; void *owned; u8 pad2[0xc]; Cw4Vec vec; u8 pad3[8]; } Cw4Ent28;
void ts4_destroy_ent28_range_88177288(Cw4Ent28 *begin, Cw4Ent28 *end)
{
    Cw4Ent28 *p;
    for (p = begin; p != end; p++) {
        Cw4Vec *v = &p->vec;
        v->last = cw4_copy(v->last, v->last, v->first);
        if (p->vec.first) ts4_destroy_owned_object(p->vec.first);
        ts4_destroy_owned_object(p->owned);
    }
}

/* 0x8818BEE8: lookup through fn_88566220 on the +0x10 object; on failure with nothing pending, mark failed */
typedef struct Cw4Lookup { u8 pad[0xc]; u8 failed; u8 pad2[3]; void *target; } Cw4Lookup;
void *ts4_lookup_8818BEE8(Cw4Lookup *self, void *a, void *b)
{
    void *r = fn_88566220(a, b, self->target);
    if (r == 0) {
        if (ts4_if_call_seq_u32_offc_88565B10(self->target) == 0) {
            ts4_tailcall_fn_88565BA8_88565CD8(self->target);
            self->failed = 1;
            return 0;
        }
    }
    return r;
}

/* 0x88177378: copy-construct 0x28-byte entries [begin,end) into raw storage at dest; returns the end of dest */
typedef struct Cw4CEnt28 { u32 w0; u32 w4; void *text; u32 w0c; u32 w10; u32 w14; u8 body[0xc]; u8 b24; u8 pad[3]; } Cw4CEnt28;
Cw4CEnt28 *ts4_uninit_copy_ent28_88177378(Cw4CEnt28 *begin, Cw4CEnt28 *end, Cw4CEnt28 *dest)
{
    Cw4CEnt28 *p;
    for (p = begin; p != end; p++) {
        if (dest != 0) {
            dest->w0 = p->w0;
            dest->w4 = p->w4;
            ts4_assign_formatted_text(&dest->text, p->text);
            dest->w14 = p->w14;
            fn_88166BC0(dest->body, p->body);
            dest->b24 = p->b24;
        }
        dest++;
    }
    return dest;
}
