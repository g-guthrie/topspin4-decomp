/* CX33: listener-vector helpers (Swing_DLL.xex 0x8891xxxx). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Cx33Lis { void **vt; u32 w4, w8, wc; } Cx33Lis;
typedef struct Cx33LisVec { Cx33Lis **first; Cx33Lis **last; } Cx33LisVec;
typedef struct Cx33Hub { u8 pad[0x14]; Cx33LisVec v; } Cx33Hub;
typedef void (*Cx33DelFn)(Cx33Lis *l, int flags);

extern void *fn_88562DC0(void *dst, void *src, u32 n);

static __inline Cx33Lis **cx33_copy(Cx33Lis **first, Cx33Lis **last, Cx33Lis **dest)
{
    if (first == last) {
        return dest;
    } else {
        u32 n = (u32)((char *)last - (char *)first);
        dest = (Cx33Lis **)fn_88562DC0(dest, first, n);
        return (Cx33Lis **)((char *)dest + n);
    }
}

/* 0x88912090: delete every listener, then clear the vector */
void ts4_hub_delete_all_88912090(Cx33Hub *h)
{
    Cx33Lis **end = h->v.last;
    Cx33LisVec *v = &h->v;
    Cx33Lis **p;
    for (p = v->first; p != end; p++) {
        if (*p)
            ((Cx33DelFn)(*p)->vt[0])(*p, 1);
    }
    v->last = cx33_copy(v->last, v->last, v->first);
}

/* ---- hub with a pointer vector at +0x28 and a running total at +0x20 ---- */
typedef struct Cx33PVec { u32 w0; u32 *last; u32 *cap; } Cx33PVec;
typedef struct Cx33Item { void **vt; } Cx33Item;
typedef int (*Cx33SizeFn)(Cx33Item *);
typedef struct Cx33Hub2 { u8 pad[0x20]; int total; u32 pad24; Cx33PVec vec; } Cx33Hub2;
extern void ts4_vector_grow_append_scalar4_88174A38(Cx33PVec *vec, u32 *pos, u32 *val);

#ifdef _MSC_VER
#define CX33_INL static __forceinline
#else
#define CX33_INL static inline
#endif
CX33_INL void cx33_push(Cx33PVec *v, u32 val)
{
    if (v->last != v->cap) {
        if (v->last)
            *v->last = val;
        v->last++;
    } else {
        ts4_vector_grow_append_scalar4_88174A38(v, v->last, &val);
    }
}

/* 0x88912DE0: append an item to the vector and add its size (vtable slot 6) to the total */
void ts4_hub_add_item_88912DE0(Cx33Hub2 *h, Cx33Item *item)
{
    int t;
    cx33_push(&h->vec, (u32)(unsigned long)item);
    t = h->total;
    h->total = t + ((Cx33SizeFn)item->vt[6])(item);
}
