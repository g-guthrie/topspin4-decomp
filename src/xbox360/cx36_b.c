/* CX36: vector/table helpers, Swing_DLL.xex 0x8892xxxx-0x8893xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX36_INL static __forceinline
#else
#define CX36_INL static inline
#endif
extern void ts4_destroy_owned_object(void *p);

/* 0x88931388: count the elements whose slot-6 predicate returns nonzero */
typedef struct Cx36Pred { void **vt; } Cx36Pred;
typedef struct Cx36PredVec { u8 pad[4]; Cx36Pred **first; Cx36Pred **last; } Cx36PredVec;
typedef u8 (*Cx36PredFn)(Cx36Pred *p);
u32 ts4_count_true_elements_88931388(Cx36PredVec *v)
{
    u32 n = 0;
    Cx36Pred **end = v->last;
    Cx36Pred **p;
    for (p = v->first; p != end; p++) {
        if (((Cx36PredFn)(*p)->vt[6])(*p))
            n++;
    }
    return n;
}

/* 0x88929290: clear a 16-byte element vector (copy of an empty range) and destroy the old block */
typedef struct Cx36E16 { u32 a, b, c, d; } Cx36E16;
typedef struct Cx36V16 { Cx36E16 *first; Cx36E16 *last; } Cx36V16;
CX36_INL Cx36E16 *cx36_cpy16(Cx36E16 *first, Cx36E16 *last, Cx36E16 *dst)
{
    int n = last - first;
    Cx36E16 *s = first;
    Cx36E16 *p = dst;
    while (n > 0) {
        *p = *s;
        --n;
        s++;
        p++;
    }
    return p;
}
void ts4_vec16_reset_88929290(Cx36V16 *v)
{
    v->last = cx36_cpy16(v->last, v->last, v->first);
    if (v->first)
        ts4_destroy_owned_object(v->first);
}

/* 0x88923380: default range {0, 0xFFFFF, 0}; load from the first element of the source range when present */
typedef struct Cx36R3 { u32 a, b, c; } Cx36R3;
typedef struct Cx36RElem { u32 pad; Cx36R3 v; } Cx36RElem;
typedef struct Cx36RHdr { Cx36RElem *first; Cx36RElem *last; } Cx36RHdr;
typedef struct Cx36RSrc { u8 pad[4]; Cx36RHdr *hdr; u32 pad8; u32 wc; } Cx36RSrc;
#if 0 /* near miss, not byte-identical */
void ts4_range_load_first_88923380(Cx36R3 *out, Cx36RSrc *src)
{
    Cx36RHdr *h;
    out->a = 0;
    out->c = 0;
    out->b = 0xFFFFF;
    if (src->wc == 0)
        return;
    h = src->hdr;
    if (h == 0)
        return;
    if (h->first == h->last)
        return;
    {
        Cx36RElem *e = h->first;
        out->a = e->v.a;
        out->b = e->v.b;
        out->c = e->v.c;
    }
}
#endif

/* 0x88924430: find the 0x24-byte entry whose key at +0x14 equals key (self-relative table at +0x24) */
typedef struct Cx36Tab { int rel; } Cx36Tab;
typedef struct Cx36TabOwner { u8 pad[0x24]; Cx36Tab tab; u32 count; } Cx36TabOwner;
char *ts4_find_entry24_88924430(Cx36TabOwner *o, u32 key)
{
    int n = o->count;
    char *r = 0;
    int i = 0;
    Cx36Tab *h;
    if (n > 0) {
        h = &o->tab;
        for (; i < n; i++) {
            char *e = (char *)h + (i * 0x24 + h->rel);
            if (key == *(u32 *)(e + 0x14)) {
                r = e;
                break;
            }
        }
    }
    return r;
}

/* 0x88923BE0: look up the entry (stride 0x1c, key at +0x14) and return the matching slot of the pointer table */
typedef struct Cx36Tab2 { u8 pad[0x18]; int rel; int count; } Cx36Tab2;
typedef struct Cx36Ptrs { void **tab; } Cx36Ptrs;
typedef struct Cx36Tab2Owner { u8 pad[8]; Cx36Tab2 *t8; u8 padc[4]; Cx36Ptrs *p10; } Cx36Tab2Owner;
#if 0 /* near miss, not byte-identical */
void *ts4_find_slot28_88923BE0(Cx36Tab2Owner *o, u32 key)
{
    Cx36Tab2 *t = o->t8;
    void *r = 0;
    int i = 0;
    int n = t->count;
    if (n > 0) {
        Cx36Tab2 *h = (Cx36Tab2 *)&t->rel;
        for (; i < n; i++) {
            char *e = (char *)h + (i * 0x1c + *(int *)h);
            if (*(u32 *)(e + 0x14) == key) {
                r = o->p10->tab[i];
                break;
            }
        }
    }
    return r;
}
#endif

/* 0x88926E58: look up a u32 key in a self-relative table (stride 8), default value from the global config */
typedef struct Cx36Cfg { u8 pad[0x27c]; u32 w27c; } Cx36Cfg;
extern Cx36Cfg *lbl_88D45B1C;
typedef struct Cx36KV { u32 key, val; } Cx36KV;
typedef struct Cx36KVTab { int rel; int count; } Cx36KVTab;
void ts4_kv_lookup_88926E58(u32 *out, Cx36KVTab *t, u32 key)
{
    int i;
    int n = t->count;
    *out = lbl_88D45B1C->w27c;
    for (i = 0; i < n; i++) {
        if (*(u32 *)((char *)t + (i * 8 + t->rel)) == key) {
            *out = *(u32 *)((char *)t + (i * 8 + t->rel) + 4);
            return;
        }
    }
}
