/* CX30 part c: Pam core small functions, second pass. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;

#ifdef _MSC_VER
#pragma function(memcpy)
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif
/* 16-byte handle-table entry: three 20-bit links, 4 flag bits, then a 27-bit offset and a 5-bit kind (MSB-first) */
typedef struct Cx30Ent { u64 hi:20; u64 mid:20; u64 lo:20; u64 fl:4; u32 w2; u32 off:27; u32 kind:5; } Cx30Ent;
typedef struct Cx30Tab { u8 pad0[0x2c]; Cx30Ent *ents; u8 pad1[8]; u8 *f38; } Cx30Tab;
typedef struct Cx30TabOwner { u8 pad[4]; Cx30Tab *t; } Cx30TabOwner;
extern int ts4_addr_lbl_88C317A0_88567890(int);
extern void *ts4_find_service(u32);
extern u8 *lbl_88D45B1C;

/* 0x88605A00: skip identifier characters (class test or '_') and report whether the string then ends */
int ts4_str_is_identifier_88605A00(const char *s)
{
    while (ts4_addr_lbl_88C317A0_88567890(*(u8 *)s) != 0 || *s == '_') s++;
    return *s == 0;
}

/* 0x886146B0 / 0x886147D8: look a service up by id and ask it (vtable slot 6) about a value passed by address; true when it answers non-null */
typedef struct Cx30Svc { struct Cx30SvcV *vt; } Cx30Svc;
typedef struct Cx30SvcV { u8 pad[0x18]; void *(*f18)(Cx30Svc *, u32 *); } Cx30SvcV;
#define CX30_SVC_QUERY(NAME) \
u32 NAME(void *o, u32 id, u32 a) \
{ \
    Cx30Svc *s = (Cx30Svc *)ts4_find_service(id); \
    (void)o; \
    if (s) return 0 != s->vt->f18(s, &a); \
    return 0; \
}
CX30_SVC_QUERY(ts4_service_query_886146B0)
CX30_SVC_QUERY(ts4_service_query_886147D8)

/* 0x8861B630: initialise the sub-record at +0x228 when it is empty (kind 0x14806, value 0x2ab9), else let the helper do it; then clear the byte at +0x274 */
extern void fn_886176F0(void *);
typedef struct Cx30Sub { u8 f0; u8 pad[3]; u32 f4; u32 f8; } Cx30Sub;
typedef struct Cx30Own228 { u8 pad[0x228]; Cx30Sub s; u8 pad2[0x274 - 0x228 - sizeof(Cx30Sub)]; u8 f274; } Cx30Own228;
void ts4_init_sub_record_8861B630(Cx30Own228 *o)
{
    Cx30Sub *s = &o->s;
    volatile u8 t;
    if (s->f0 == 0) { s->f4 = 0x14806; s->f8 = 0x2ab9; }
    else fn_886176F0(s);
    t = 0;
    o->f274 = t;
}

/* 0x8860B428: when entry idx has the given kind, copy len bytes from its payload (table base + offset) to dst; returns whether the kind matched */
u32 ts4_entry_copy_payload_8860B428(Cx30TabOwner *o, u32 a, u32 idx, void *dst, u32 len, int kind)
{
    Cx30Tab *t = o->t;
    u32 r = 0;
    Cx30Ent *e = &t->ents[idx];
    (void)a;
    if (kind == (int)e->kind) {
        u8 *src = t->f38 + e->off;
        r = 1;
        if (src) memcpy(dst, src, len);
    }
    return r;
}

/* 0x88612730 / 0x886127A0: for every node in the vector at +0x28 that has its flag at +0x23, set (or, for the second, clear when the node's other flag at +0x22 is set) the byte at +9 of each 12-byte item whose two ids equal (a, b) */
typedef struct Cx30It { u32 a; u32 b; u8 pad[1]; u8 f9; u8 pad2[2]; } Cx30It;
typedef struct Cx30ItNd { u8 pad[8]; Cx30It *f8; Cx30It *fc; u8 pad2[0x22 - 0x10]; u8 f22; u8 f23; } Cx30ItNd;
typedef struct Cx30ItOw { u8 pad[0x28]; Cx30ItNd **b; Cx30ItNd **e; } Cx30ItOw;
void ts4_items_mark_ids_88612730(Cx30ItOw *o, u32 a, u32 b)
{
    Cx30ItNd **e = o->e;
    Cx30ItNd **p = o->b;
    if (e == p) return;
    for (; p != e; p++) {
        Cx30ItNd *n = *p;
        if (n->f23 != 0) {
            Cx30It *qe = n->fc;
            Cx30It *q = n->f8;
            for (; qe != q; q++)
                if (q->b == b && q->a == a) q->f9 = 1;
        }
    }
}
void ts4_items_clear_ids_886127A0(Cx30ItOw *o, u32 a, u32 b)
{
    Cx30ItNd **e = o->e;
    Cx30ItNd **p = o->b;
    if (e == p) return;
    for (; p != e; p++) {
        Cx30ItNd *n = *p;
        if (n->f23 != 0) {
            Cx30It *qe = n->fc;
            Cx30It *q = n->f8;
            for (; qe != q; q++)
                if (q->b == b && q->a == a && (*p)->f22 != 0) q->f9 = 0;
        }
    }
}

extern void fn_8861C830(void *, u32);
extern void *ts4_hash_normalized_path_886090A0(void *, u32);
extern u32 fn_8827EBB8(u32, void *);
typedef struct Cx30Id { u32 a; u32 id; } Cx30Id;
/* 0x8861CD00: for a valid handle, repeatedly process the entry's link target through the helper until the link becomes the null id */
void ts4_handle_chain_drain_8861CD00(Cx30TabOwner *o, Cx30Id *h)
{
    u32 id = h->id;
    u32 r;
    if (id == 0xFFFFF) return;
    r = o->t->ents[id].off;
    if (r == 0xFFFFF) return;
    do {
        fn_8861C830(o->t, r);
        r = o->t->ents[id].off;
    } while (r != 0xFFFFF);
}

/* 0x88621DE0: ask the sub-object at +0x2c (vtable slot 19) for a value, then test it against the converted argument */
typedef struct Cx30SV { struct Cx30SVV *vt; } Cx30SV;
typedef struct Cx30SVV { u8 pad[0x4c]; u32 (*f4c)(void *, u32); } Cx30SVV;
typedef struct Cx30W { u8 pad[0x2c]; Cx30SV s; } Cx30W;
u8 ts4_sub_test_88621DE0(Cx30W *o, u32 a)
{
    u8 tmp[8];
    u32 r30 = o->s.vt->f4c(&o->s, 0);
    void *t = ts4_hash_normalized_path_886090A0(tmp, a);
    return 0 != fn_8827EBB8(r30, t);
}

/* 0x8861D8E8: bind a record to its parent, reset the 20-bit link fields to the null id, run the init helper, then take the global's value at +0x27c and clear the links again */
extern void ts4_if_addr_ts4_call_88613268_88618368_8861D760(void *, u32);
typedef struct Cx30Par { u8 pad[0x6c]; u32 f6c; u32 f70; } Cx30Par;
typedef struct Cx30Rec { u32 f0; Cx30Par *f4; u8 f8; u8 p[3]; u32 fc, f10, f14, f18, f1c, f20; } Cx30Rec;
typedef struct Cx30G27c { u8 pad[0x27c]; u32 f27c; } Cx30G27c;
u32 ts4_record_bind_8861D8E8(Cx30Rec *o, Cx30Par *p, u32 a, u32 b)
{
    u32 r;
    volatile Cx30Rec *v = o;
    o->f4 = p;
    p->f6c = 0;
    p->f70 = 0;
    o->f8 = 0;
    o->fc = b;
    o->f10 = 0xFFFFF;
    o->f14 = b;
    o->f18 = 0xFFFFF;
    ts4_if_addr_ts4_call_88613268_88618368_8861D760(o, a);
    v->f1c = ((Cx30G27c *)lbl_88D45B1C)->f27c;
    r = v->f10;
    v->f20 = 0;
    v->fc = 0xFFFFF;
    v->f14 = 0xFFFFF;
    v->f18 = 0xFFFFF;
    return r;
}

/* 0x8861CC08: as 0x8861CD00 but following the entry's first link, re-reading the handle's id each round */
void ts4_handle_chain_drain_links_8861CC08(Cx30TabOwner *o, Cx30Id *h)
{
    u32 id = h->id;
    u32 r;
    if (id == 0xFFFFF) return;
    r = o->t->ents[id].lo;
    if (r == 0xFFFFF) return;
    do {
        fn_8861C830(o->t, r);
        id = h->id;
        if (id == 0xFFFFF) return;
        r = o->t->ents[id].lo;
    } while (r != 0xFFFFF);
}
