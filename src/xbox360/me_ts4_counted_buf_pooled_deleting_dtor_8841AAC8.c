/* 0x8841AAC8: Pooled deleting destructor of a word buffer: if it has storage and is not externally owned, frees count words (kind 0x17); with flags bit 0 returns the header to the kind-2 per-thread free list (fn_8841A3F8 when full); returns the header. */
/* Matched on /Oc (agAH). Free size uses the count field, read with the data pointer into locals before KeTlsGetValue; list_full/list_push helpers as in 8841C428. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
void fn_8841A3F8(void *pool, int kind, void *object);
#define INL static __forceinline
typedef struct FreeList { void *head; int count; } FreeList;
INL int list_full(FreeList *l, int limit) { return l->count >= limit; }
INL void list_push(FreeList *l, void *o) { l->count++; *(void **)o = l->head; l->head = o; }
typedef struct Pool2 { char pad0[0x34]; int limit; char pad1[0x48 - 0x34 - 4]; FreeList list; } Pool2;

typedef struct CountedBuf { unsigned int *data; int count; int capFlags; } CountedBuf;

CountedBuf *fn_8841AAC8(CountedBuf *b, unsigned int flags)
{
    if (b->data && (b->capFlags & (int)0x80000000) == 0) {
        unsigned int *data = b->data;
        unsigned int n = b->count;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, data, n * sizeof(unsigned int), 0x17);
    }
    if ((flags & 1) != 0) {
        Pool2 *p = (Pool2 *)KeTlsGetValue(lbl_88CACF08);
        if (list_full(&p->list, p->limit)) { fn_8841A3F8(p, 2, b); }
        else { list_push(&p->list, b); }
    }
    return b;
}
