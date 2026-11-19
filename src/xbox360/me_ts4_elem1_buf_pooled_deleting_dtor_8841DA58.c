/* 0x8841DA58: Pooled deleting destructor of a 1-byte-element pool buffer: frees the storage (kind 0x17) unless externally owned; with flags bit 0 returns the header to the kind-2 per-thread free list, or through fn_8841A3F8 when the list is full; returns the header. */
/* Matched on /Oc (agAH). Shared inline per-buffer free helper plus the list_full/list_push free-list helpers from me_ts4_release_buf_and_pool_obj_8841C428.c (Pool2 list at +0x48). */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
void fn_8841A3F8(void *pool, int kind, void *object);
#define INL static __forceinline
typedef struct FreeList { void *head; int count; } FreeList;
INL int list_full(FreeList *l, int limit) { return l->count >= limit; }
INL void list_push(FreeList *l, void *o) { l->count++; *(void **)o = l->head; l->head = o; }
typedef struct Pool2 { char pad0[0x34]; int limit; char pad1[0x48 - 0x34 - 4]; FreeList list; } Pool2;
typedef struct Elem1 { unsigned char b[1]; } Elem1;
typedef struct Elem1Buf { Elem1 *data; int count; int capFlags; } Elem1Buf;

static void Elem1Buf_Free(Elem1Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem1), 0x17);
    }
}

Elem1Buf *fn_8841DA58(Elem1Buf *b, unsigned int flags)
{
    Elem1Buf_Free(b);
    if ((flags & 1) != 0) {
        Pool2 *p = (Pool2 *)KeTlsGetValue(lbl_88CACF08);
        if (list_full(&p->list, p->limit)) { fn_8841A3F8(p, 2, b); }
        else { list_push(&p->list, b); }
    }
    return b;
}
