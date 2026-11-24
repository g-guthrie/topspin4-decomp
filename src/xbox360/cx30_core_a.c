/* CX30 part a: small Pam core helpers (0x885F5xxx-0x88625xxx): span readers, handle-table constructors, bit helpers. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;

extern void ts4_node_dispatch_8860DCF8(void *o, u32 a, u32 b, u32 c);

/* 0x88612B08: forward (this, a, this->f64, b) to the node dispatcher */
typedef struct Cx30O64 { u8 pad[0x64]; u32 f64; } Cx30O64;
void ts4_forward_with_f64_88612B08(Cx30O64 *o, u32 a, u32 b)
{
    u32 t = *(volatile u32 *)&o->f64;
    ts4_node_dispatch_8860DCF8(o, a, t, b);
}

/* 0x8860D968: header size, 0x14 when the flag bit (value 2) at +8 is set, else 0xc */
typedef struct Cx30Flag8 { u8 pad[8]; u32 :30; u32 fl:1; u32 :1; } Cx30Flag8;
u32 ts4_header_size_8860D968(Cx30Flag8 *o)
{
    u8 v = o->fl;
    return v ? 0x14 : 0xc;
}

/* 0x886079E8: second field of b is null */
typedef struct Cx30P4 { u32 f0; void *f4; } Cx30P4;
u32 ts4_field4_is_null_886079E8(void *a, Cx30P4 *b)
{
    (void)a;
    return 0 == b->f4;
}

/* 0x88604A78: Blowfish round function: four S-box lookups at +0x48 (4 x 256 words) */
u32 ts4_blowfish_f_88604A78(u32 *s, u32 x)
{
    u32 d = x & 0xff;
    u32 c, b, a;
    x >>= 8; c = x & 0xff;
    x >>= 8; b = x & 0xff;
    x >>= 8; a = x & 0xff;
    return ((s[a + 0x12] + s[b + 0x112]) ^ s[c + 0x212]) + s[d + 0x312];
}

/* 0x885F5980 / 0x885F5A18: read up to two u32 words of record idx (8 bytes each) from a sized span; zero-filled when short */
typedef struct Cx30Span { u8 pad[0xc]; u32 *data; u32 size; } Cx30Span;
#define CX30_RD2(NAME) \
void NAME(u32 *out, Cx30Span *s, short idx) \
{ \
    u32 size = s->size; \
    u32 *p; \
    out[0] = 0; \
    out[1] = 0; \
    if ((u32)idx >= (size >> 3)) return; \
    p = s->data + idx * 2; \
    if (size >= 4) { \
        out[0] = p[0]; \
        size -= 4; \
    } \
    if (size >= 4) out[1] = p[1]; \
}
CX30_RD2(ts4_span_read_rec8_885F5980)
CX30_RD2(ts4_span_read_rec8_885F5A18)

/* 0x88606170: widen up to n bytes to u16 until a NUL; 1 when a NUL was copied, else terminate the buffer and return 0 */
int ts4_widen_bytes_88606170(const u8 *src, u16 *dst, u32 n)
{
    if (n != 0) {
        u32 i = 0;
        u16 *p = dst;
        do {
            u8 c = src[i];
            *p = c;
            if (c == 0) return 1;
            i++;
            p++;
        } while (n > i);
        dst[n - 1] = 0;
    }
    return 0;
}

/* 0x886046B8: report two clamped offsets of a ring; fails when the limit at +0x14 is zero */
typedef struct Cx30Ring { u32 pad0; u32 f4; u32 f8; u32 pad1; u32 f10; u32 f14; } Cx30Ring;
int ts4_ring_offsets_886046B8(Cx30Ring *o, u32 *a, u32 *b)
{
    u32 v;
    if (o->f14 != 0) {
        *a = o->f8;
        v = o->f4 - o->f8 + o->f10;
        if (v <= o->f14) { v = o->f4 - o->f8 + o->f10; } else v = o->f14;
        *b = v;
        return 1;
    }
    return 0;
}

/* 0x88605A58: index of the first byte equal to c in s, or -1 */
#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif
int ts4_str_index_of_88605A58(const char *s, char c)
{
    int n = strlen(s);
    int r = -1;
    int i;
    for (i = 0; i < n; i++)
        if (s[i] == c) { r = i; break; }
    return r;
}

/* 0x88616100: allocate a node from the pool at +0x10, tag it with state 1 and the pool's current value, link it into the list at +4 */
extern void *ts4_if_call_seq_u32_off1000_882829A0(void *);
extern void fn_881898E8(void *, void *);
typedef struct Cx30Nd { u8 pad[0x10]; u32 f10; u32 f14; } Cx30Nd;
typedef struct Cx30Pool { u8 pad[0x1018]; u32 f1018; u32 f101c; } Cx30Pool;
int ts4_pool_push_node_88616100(Cx30Pool *p)
{
    Cx30Nd *tmp = (Cx30Nd *)ts4_if_call_seq_u32_off1000_882829A0((u8 *)p + 0x10);
    Cx30Nd *e = tmp;
    u32 v = p->f101c;
    e->f14 = v;
    e->f10 = 1;
    fn_881898E8((u8 *)p + 4, &tmp);
    p->f1018 = (u32)(unsigned long)tmp;
    return 1;
}

/* 0x88603B90: 4 plus the sum of vtable slot 1 (size) over the child objects held in the array at +0x14 */
typedef struct Cx30VO { u32 (**vt)(struct Cx30VO *); } Cx30VO;
typedef struct Cx30Arr { u8 pad[0xc]; u32 cnt; u32 padx; Cx30VO **items; } Cx30Arr;
u32 ts4_children_total_size_88603B90(Cx30Arr *a)
{
    u32 total = 4;
    u32 i;
    for (i = 0; i < a->cnt; i++)
        total += a->items[i]->vt[1](a->items[i]);
    return total;
}

/* 0x88603E78: write the child count then each child's serialized form (vtable slot 2) after it; returns the byte count */
typedef struct Cx30Iv { u32 (**vt)(struct Cx30Iv *, u8 *); } Cx30Iv;
typedef struct Cx30Co { u8 pad[0xc]; u32 cnt; u32 pad2; Cx30Iv **items; } Cx30Co;
u32 ts4_children_serialize_88603E78(Cx30Co *o, u32 *buf)
{
    u8 *p = (u8 *)buf + 4;
    u32 i;
    buf[0] = o->cnt;
    for (i = 0; i < o->cnt; i++)
        p += o->items[i]->vt[2](o->items[i], p);
    return p - (u8 *)buf;
}

/* 0x8860F558: the id at +4 is one of six known name hashes */
typedef struct Cx30Hid { u8 pad[4]; u32 h; } Cx30Hid;
u32 ts4_is_known_hash_8860F558(Cx30Hid *o)
{
    u32 h = o->h;
    if (h == 0x7f924a47) return 1;
    if (h == 0xd2a15f4e) return 1;
    if (h == 0x5782b6fa) return 1;
    if (h == 0x13750bb2) return 1;
    if (h == 0x71824091) return 1;
    return h == 0x40827212;
}

/* 0x886143E8: copy the header fields and the 0x200-byte body of a record, tagging the copy as kind 2 */
#ifdef _MSC_VER
#pragma function(memcpy)
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif
typedef struct Cx30Rec { u32 f0; u8 f4; u8 pad[3]; u32 f8; u8 body[0x200]; u32 f20c; u32 f210; u32 f214; u32 f218; u32 f21c; u32 f220; u32 f224; u32 f228; u32 f22c; u8 pad2[4]; u8 f234; } Cx30Rec;
void ts4_record_copy_886143E8(Cx30Rec *d, Cx30Rec *s)
{
    d->f0 = 2;
    d->f22c = s->f22c;
    d->f234 = s->f234;
    d->f4 = s->f4;
    d->f8 = s->f8;
    d->f214 = s->f214;
    d->f218 = s->f218;
    d->f220 = s->f220;
    d->f21c = s->f21c;
    d->f224 = s->f224;
    d->f228 = s->f228;
    d->f20c = s->f20c;
    memcpy(d->body, s->body, 0x200);
}

/* 0x8860C050 / 0x8860EA70: find a node by id: the node itself when its id at +4 equals *h, else the first non-null result of vtable slot 6 over its children (begin/end pointers at OFF) */
typedef struct Cx30Ch { struct Cx30ChV *vt; } Cx30Ch;
typedef struct Cx30ChV { u8 pad[0x18]; void *(*f18)(Cx30Ch *, u32 *); } Cx30ChV;
#define CX30_FIND_NODE(NAME, TYPE, PADLEN) \
typedef struct TYPE { u8 pad[4]; u32 f4; u8 pad2[PADLEN]; Cx30Ch **b; Cx30Ch **e; } TYPE; \
void *NAME(TYPE *o, u32 *h) \
{ \
    if (o->f4 == *(volatile u32 *)h) return o; \
    { \
        Cx30Ch **end = o->e; \
        Cx30Ch **p = o->b; \
        for (; p != end; p++) { \
            void *r = (*p)->vt->f18(*p, h); \
            if (r != 0) return r; \
        } \
    } \
    return 0; \
}
CX30_FIND_NODE(ts4_node_find_by_id_8860C050, Cx30FindA, 0x14)
CX30_FIND_NODE(ts4_node_find_by_id_8860EA70, Cx30FindB, 0x1c)

/* 0x88613BF0: is id present among the leading non-null entries of the 30-slot table at +0x6c */
typedef struct Cx30Slots { u8 pad[0x6c]; u32 a[30]; } Cx30Slots;
u32 ts4_slots_contains_88613BF0(Cx30Slots *o, u32 id)
{
    u32 r = 0;
    u32 *e = o->a + 30;
    u32 *p = o->a;
    while (e != p) {
        if (*p == 0) break;
        if (*p == id) { r = 1; break; }
        p++;
    }
    return r;
}

extern void *fn_885647D0(void *, int);
extern u8 lbl_880C1320[];
extern u8 *lbl_88D45B1C;

/* 0x88606880: first '.' in s via the string finder, or the default string when s is null or has none */
void *ts4_find_dot_or_default_88606880(void *s)
{
    void *r = lbl_880C1320;
    if (s) {
        void *t = fn_885647D0(s, '.');
        if (t) r = t;
    }
    return r;
}

typedef struct Cx30G220 { u8 pad[0x220]; u32 f220; u32 f224; } Cx30G220;
typedef struct Cx30Sel { u8 pad[0x24]; u8 f24; } Cx30Sel;
/* 0x88614008: pick one of two global-object words (+0x220 / +0x224) by the flag byte at +0x24 */
u32 ts4_pick_global_word_88614008(Cx30Sel *o)
{
    if (o->f24) return ((Cx30G220 *)lbl_88D45B1C)->f220;
    return ((Cx30G220 *)lbl_88D45B1C)->f224;
}

typedef struct Cx30G24d { u8 pad[0x24d]; u8 f24d; } Cx30G24d;
typedef struct Cx30Ob44 { u8 pad[0x44]; u8 *f44; } Cx30Ob44;
/* 0x88611BC8: global feature byte at +0x24d is set and the object's sub-object has its flag at +0xa1 */
u8 ts4_feature_and_subflag_88611BC8(Cx30Ob44 *o)
{
    Cx30G24d *g = (Cx30G24d *)lbl_88D45B1C;
    u8 ok = g->f24d != 0 && o->f44[0xa1] != 0;
    return ok;
}
