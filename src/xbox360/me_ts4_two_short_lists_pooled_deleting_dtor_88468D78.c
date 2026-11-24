/* 0x88468D78: Pooled deleting destructor of two word lists with u16 count/capacity headers (+0x8 then +0x0; bit 15 = not owned, mask 0x3FFF): frees each (kind 0x17); with flags bit 0 returns the object to the kind-2 free list; returns the object. */
/* Matched on /Oc (agAH). Per-buffer inline free helper plus list_full/list_push (pool list at +0x38 + 8*kind). */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
void fn_8841A3F8(void *pool, int kind, void *object);
#define INL static __forceinline
typedef struct FreeList { void *head; int count; } FreeList;
INL int list_full(FreeList *l, int limit) { return l->count >= limit; }
INL void list_push(FreeList *l, void *o) { l->count++; *(void **)o = l->head; l->head = o; }
typedef struct Pool2 { char pad0[0x34]; int limit; char pad1[0x48 - 0x34 - 4]; FreeList list; } Pool2;

typedef struct ShortWordBuf { unsigned int *data; unsigned short count; unsigned short capFlags; } ShortWordBuf;

static void ShortWordBuf_Free(ShortWordBuf *b)
{
    if ((b->capFlags & 0x8000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(unsigned int), 0x17);
    }
}

typedef struct TwoShortLists { ShortWordBuf first; ShortWordBuf second; } TwoShortLists;

TwoShortLists *fn_88468D78(TwoShortLists *o, unsigned int flags)
{
    ShortWordBuf_Free(&o->second);
    ShortWordBuf_Free(&o->first);
    if ((flags & 1) != 0) {
        Pool2 *p = (Pool2 *)KeTlsGetValue(lbl_88CACF08);
        if (list_full(&p->list, p->limit)) { fn_8841A3F8(p, 2, o); }
        else { list_push(&p->list, o); }
    }
    return o;
}
