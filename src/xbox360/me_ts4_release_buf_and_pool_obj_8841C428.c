/* Swing_DLL.xex 0x8841C428: releases the owned buffer of a handle (ts4_if_get_u32_0xc_8841A820 on the thread allocator) and returns
 * the per-thread lbl_88CAD338 object to the kind-3 free list (overflow through fn_8841A3F8). agO: from 88472858; plain and LTCG. */
typedef unsigned int u32;
extern u32 lbl_88CACF08;
extern u32 lbl_88CAD338;
void *KeTlsGetValue(u32 index);
void ts4_if_get_u32_0xc_8841A820(void *alloc, void *buf);
void fn_8841A3F8(void *pool, int kind, void *object);
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
typedef struct FreeList { void *head; int count; } FreeList;
INL int list_full(FreeList *l, int limit) { return l->count >= limit; }
INL void list_push(FreeList *l, void *o) { l->count++; *(void **)o = l->head; l->head = o; }
typedef struct Pool3 { char pad0[0x34]; int limit; char pad1[0x50 - 0x34 - 4]; FreeList list; } Pool3;
typedef struct Holder { int buf; char pad[0xc]; unsigned char owned; } Holder;

void fn_8841C428(Holder *h)
{
    int buf = h->buf;
    void *obj;
    if (buf != 0 && h->owned)
        ts4_if_get_u32_0xc_8841A820(KeTlsGetValue(lbl_88CACF08), (void *)buf);
    obj = KeTlsGetValue(lbl_88CAD338);
    if (obj != 0) {
        Pool3 *p = (Pool3 *)KeTlsGetValue(lbl_88CACF08);
        if (list_full(&p->list, p->limit)) { fn_8841A3F8(p, 3, obj); }
        else { list_push(&p->list, obj); }
    }
}
