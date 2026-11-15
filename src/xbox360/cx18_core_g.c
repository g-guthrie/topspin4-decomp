/* CW18 part g: registration loops with a vector clear (0x88850000-0x88871F08). Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CX18_INL static __forceinline
#else
#define CX18_INL static inline
#endif

typedef struct Cx18Rec2 { u32 a, b; } Cx18Rec2;
typedef struct Cx18Vec2 { Cx18Rec2 *begin; Cx18Rec2 *end; } Cx18Vec2;
CX18_INL Cx18Rec2 *copy2(Cx18Rec2 *first, Cx18Rec2 *last, Cx18Rec2 *dest)
{
    int n = last - first;
    for (; n > 0; --n) { dest->a = first->a; dest->b = first->b; ++dest; ++first; }
    return dest;
}
CX18_INL void vec2_clear(Cx18Vec2 *v)
{
    v->end = copy2(v->end, v->end, v->begin);
}

typedef struct Cx18Reg { u8 pad[0x70]; void *f70; } Cx18Reg;
extern Cx18Reg *lbl_88D41FC4;
extern void fn_882107D0(void *owner, u32 *hash, int flag);
typedef struct Cx18Own { u8 pad[0xa0]; Cx18Vec2 v; } Cx18Own;

/* 0x8886B8E0: register the second word of every record with the owner at +0x70 of the global, then empty the list */
void ts4_register_records_8886B8E0(Cx18Own *o)
{
    Cx18Rec2 *p;
    for (p = o->v.begin; p != o->v.end; p++)
        fn_882107D0(lbl_88D41FC4->f70, &p->b, 0);
    vec2_clear(&o->v);
}

/* ---- owner with a vector of 8-byte {key, value} pairs at +0x6c/+0x70 ---- */
typedef struct Cx18KeyOwn { u8 pad[0x6c]; Cx18Rec2 *begin; Cx18Rec2 *end; } Cx18KeyOwn;
extern void ts4_set_flag_mirror_to_service_786_88865588(Cx18KeyOwn *o, int flag);
extern u8 fn_8886AE98(Cx18KeyOwn *o, u32 a, Cx18Rec2 *rec, u32 b);

/* 0x8886B0C8: clear the flag, offer the id to every pair with this key and set the flag again when one refuses */
u32 ts4_offer_to_pairs_8886B0C8(Cx18KeyOwn *o, u32 a, u32 b, u32 key)
{
    Cx18Rec2 *p;
    ts4_set_flag_mirror_to_service_786_88865588(o, 0);
    for (p = o->begin; p != o->end; p++) {
        if (p->a == key) {
            if (!fn_8886AE98(o, a, p, b)) ts4_set_flag_mirror_to_service_786_88865588(o, 1);
        }
    }
    return 1;
}

/* ---- wide-string copy into fixed buffers of three object layouts ---- */
typedef unsigned short u16;
typedef struct Cx18WStr { u16 *begin; u16 *end; u16 *cap; u32 pad; } Cx18WStr;
extern void fn_88152DF8(Cx18WStr *t);
extern void fn_88859EB0(Cx18WStr *t, void *src, u32 a);
extern void *ts4_memset(void *dst, int c, u32 n);
extern void ts4_destroy_owned_object(void *p);
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

#define CX18_WSTR_COPY(NAME, SUBOFF, SRCWORD, DSTOFF, BYTES, COUNT) \
void NAME(char *self, char *dst) \
{ \
    Cx18WStr t; \
    char *buf; \
    u32 n; \
    fn_88152DF8(&t); \
    fn_88859EB0(&t, self + SUBOFF, *(u32 *)(self + SRCWORD)); \
    buf = dst + DSTOFF; \
    ts4_memset(buf, 0, BYTES); \
    n = t.end - t.begin; \
    if (n < COUNT) memcpy(buf, t.begin, n * 2); \
    ts4_destroy_owned_object(t.begin); \
}
/* 0x8885D908, 0x8885D998, 0x8885DA28: copy the wide string made from a sub-object into the fixed buffer of the destination (zero-filled first, truncated copy skipped when too long) */
CX18_WSTR_COPY(ts4_wstr_copy_8885D908, 0x18, 0x64, 0x89c, 0x100, 0x80)
CX18_WSTR_COPY(ts4_wstr_copy_8885D998, 0xc, 0x60, 0x9c, 0x800, 0x400)
CX18_WSTR_COPY(ts4_wstr_copy_8885DA28, 0, 0x5c, 0x1c, 0x80, 0x40)

extern void fn_8885A5A0(void *self, Cx18WStr *t, u32 a, u32 b);

/* 0x8885E178: build the wide string from the object with two swapped arguments and copy it into the fixed buffer at +0x94 */
void ts4_wstr_build_copy_8885E178(void *self, char *dst, u32 a, u32 b)
{
    Cx18WStr t;
    char *buf;
    u32 n;
    fn_88152DF8(&t);
    fn_8885A5A0(self, &t, b, a);
    buf = dst + 0x94;
    ts4_memset(buf, 0, 0x800);
    n = t.end - t.begin;
    if (n < 0x400) memcpy(buf, t.begin, n * 2);
    ts4_destroy_owned_object(t.begin);
}

/* ---- push {a, b, service word} onto the 12-byte record vector at +0x84 ---- */
typedef struct Cx18Rec3w { u32 a, b, c; } Cx18Rec3w;
typedef struct Cx18Vec3w { Cx18Rec3w *begin; Cx18Rec3w *end; Cx18Rec3w *cap; } Cx18Vec3w;
typedef struct Cx18Own3w { u8 pad[0x84]; Cx18Vec3w v; } Cx18Own3w;
typedef struct Cx18Tbl { int off; u32 count; } Cx18Tbl;
typedef struct Cx18Mid { u8 pad[0x38]; Cx18Tbl *tbl; } Cx18Mid;
typedef struct Cx18Svc27c { u8 pad[0x234]; Cx18Mid *mid; u8 pad238[0x27c - 0x238]; u32 f27c; } Cx18Svc27c;
extern Cx18Svc27c *lbl_88D45B1C;
extern void fn_8817F248(Cx18Vec3w *v, Cx18Rec3w *at, Cx18Rec3w *rec);

/* 0x88865C90 */
void ts4_push_rec3_88865C90(Cx18Own3w *o, u32 a, u32 b)
{
    Cx18Rec3w r;
    Cx18Vec3w *v = &o->v;
    r.a = a;
    r.b = b;
    r.c = lbl_88D45B1C->f27c;
    if (v->end != v->cap) {
        if (v->end != 0) *v->end = r;
        v->end++;
    } else {
        fn_8817F248(v, v->end, &r);
    }
}

/* ---- push {a, b} onto the 8-byte record vector at +0x6c ---- */
typedef struct Cx18Vec2w { Cx18Rec2 *begin; Cx18Rec2 *end; Cx18Rec2 *cap; } Cx18Vec2w;
typedef struct Cx18Own2w { u8 pad[0x6c]; Cx18Vec2w v; } Cx18Own2w;
extern void fn_881AB1A0(Cx18Vec2w *v, Cx18Rec2 *at, Cx18Rec2 *rec);

/* 0x88865D18 */
void ts4_push_rec2_88865D18(Cx18Own2w *o, u32 a, u32 b)
{
    Cx18Rec2 r;
    Cx18Vec2w *v = &o->v;
    r.a = a;
    r.b = b;
    if (v->end != v->cap) {
        if (v->end != 0) *v->end = r;
        v->end++;
    } else {
        fn_881AB1A0(v, v->end, &r);
    }
}

typedef struct Cx18Rec28 { u8 pad[0xc]; u32 wc; u8 pad10[0x18]; } Cx18Rec28;
typedef struct Cx18Vec28 { Cx18Rec28 *begin; Cx18Rec28 *end; } Cx18Vec28;
typedef struct Cx18Glob { u8 pad[0x6c]; Cx18Vec2w v; } Cx18Glob;
extern Cx18Glob *lbl_88D459DC;

/* 0x88865D88 */
void ts4_push_nonzero_words_88865D88(Cx18Vec28 *src)
{
    Cx18Rec28 *p = src->begin;
    Cx18Rec28 *end = src->end;
    Cx18Glob *g = lbl_88D459DC;
    for (; p != end; p++) {
        if (p->wc != 0) {
            Cx18Rec2 r;
            Cx18Vec2w *v = &g->v;
            r.a = 0xFFFFFFFF;
            r.b = p->wc;
            if (v->end != v->cap) {
                if (v->end != 0) *v->end = r;
                v->end++;
            } else {
                fn_881AB1A0(v, v->end, &r);
            }
        }
    }
}

/* 0x88865E18: push {a, word} for the nonzero +0xc words of the records (the list end is re-read every iteration) */
void ts4_push_pairs_with_key_88865E18(u32 a, Cx18Vec28 *src)
{
    Cx18Rec28 *p;
    Cx18Glob *g = lbl_88D459DC;
    for (p = src->begin; p != src->end; p++) {
        if (p->wc != 0) {
            Cx18Rec2 r;
            Cx18Vec2w *v = &g->v;
            r.a = a;
            r.b = p->wc;
            if (v->end != v->cap) {
                if (v->end != 0) *v->end = r;
                v->end++;
            } else {
                fn_881AB1A0(v, v->end, &r);
            }
        }
    }
}

extern const char lbl_880C1320[];
extern void fn_8885A1B0(void *self, Cx18WStr *t, void *sub, u32 w, const char *name);

/* 0x8885DAB8: build the wide string from the record (its sub-object, its word at +0xb0 and its relative name at +0xa8) and copy it into the fixed buffer at +0x204 */
void ts4_wstr_build_named_copy_8885DAB8(void *self, char *rec, char *dst)
{
    Cx18WStr t;
    char *buf;
    u32 n;
    int *own;
    const char *name;
    fn_88152DF8(&t);
    own = (int *)(rec + 0xa8);
    name = *own != -1 ? (char *)own + *own : lbl_880C1320;
    fn_8885A1B0(self, &t, rec + 0x10, *(u32 *)(rec + 0xb0), name);
    buf = dst + 0x204;
    ts4_memset(buf, 0, 0x800);
    n = t.end - t.begin;
    if (n < 0x400) memcpy(buf, t.begin, n * 2);
    ts4_destroy_owned_object(t.begin);
}

#ifdef _MSC_VER
extern char *strcat(char *, const char *);
#pragma intrinsic(strcat)
#else
#include <string.h>
#endif
extern u8 ts4_format_entry_text_8886A350(char *s, u32 x, u32 hash);
extern const char lbl_880D3A48[];

/* 0x8886A420: append the suffix to the text when the check for the fixed id passes */
u32 ts4_append_suffix_if_8886A420(char *s, u32 x)
{
    if (ts4_format_entry_text_8886A350(s, x, 0xE1749E5B)) {
        strcat(s, lbl_880D3A48);
        return 1;
    }
    return 0;
}

/* 0x8885DB58: build the wide string from the record (sub-object at +4, word at +0xa4, relative name at +0xa8) and copy it into the fixed buffer at +4 */
void ts4_wstr_build_named_copy_8885DB58(void *self, char *rec, char *dst)
{
    Cx18WStr t;
    char *buf;
    u32 n;
    int *own;
    const char *name;
    fn_88152DF8(&t);
    own = (int *)(rec + 0xa8);
    name = *own != -1 ? (char *)own + *own : lbl_880C1320;
    fn_8885A1B0(self, &t, rec + 4, *(u32 *)(rec + 0xa4), name);
    buf = dst + 4;
    ts4_memset(buf, 0, 0x100);
    n = t.end - t.begin;
    if (n < 0x80) memcpy(buf, t.begin, n * 2);
    ts4_destroy_owned_object(t.begin);
}

/* ---- ring of 0x18-byte elements: visit `count` elements starting at `start` (wrapping) ---- */
typedef struct Cx18Ring { u8 *begin; u8 *end; } Cx18Ring;
extern void ts4_loop_get_u32_off0_88870748(void *elem, u32 a);
extern void ts4_loop_get_u32_off0_88870810(void *elem, u32 a);

#define CX18_RING_VISIT(NAME, CALLEE) \
u32 NAME(Cx18Ring *ring, u32 a, u32 *start, u32 *count) \
{ \
    int size = (ring->end - ring->begin) / 0x18; \
    u32 i; \
    for (i = 0; *count > i; i++) { \
        u32 idx = (*start + i) % (u32)size; \
        CALLEE(ring->begin + idx * 0x18, a); \
    } \
    return 1; \
}
/* 0x888708D8, 0x88870968 */
CX18_RING_VISIT(ts4_ring_visit_888708D8, ts4_loop_get_u32_off0_88870748)
CX18_RING_VISIT(ts4_ring_visit_88870968, ts4_loop_get_u32_off0_88870810)

typedef struct Cx18Cls { u8 pad[0x1c]; void *f1c; } Cx18Cls;
extern Cx18Cls *lbl_88D45A08;
extern void fn_88867A40(void *ent);
extern void fn_888C7AF8(void *p);

/* 0x88867F68: set the flag byte (+0x19) of the 0xb0-byte entry with this id; when it changed to nonzero hand the entry on, then notify the class object */
void ts4_tbl_set_entry_flag_88867F68(int id, u8 flag)
{
    Cx18Tbl *t = lbl_88D45B1C->mid->tbl;
    u32 i;
    for (i = 0; i < t->count; i++) {
        char *e = (char *)t + (i * 0xb0 + t->off);
        if (id == *(int *)(e + 0xc)) {
            u8 old = e[0x19];
            e[0x19] = flag;
            if (old != flag && flag != 0) fn_88867A40(e);
            break;
        }
    }
    fn_888C7AF8(lbl_88D45A08->f1c);
}
