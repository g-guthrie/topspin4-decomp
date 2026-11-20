/* 0x885F2390: Pooled deleting destructor: frees the 36-byte-element array at +0x0 (kind 0x17) unless externally owned; with flags bit 0 returns the object to the kind-2 per-thread free list, or through fn_8841A3F8 when the list is full; returns the object. */
/* Matched on /Oc (agAH). Per-buffer inline free helper plus list_full/list_push (free list at pool +0x38 + 8*kind). */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
void fn_8841A3F8(void *pool, int kind, void *object);
#define INL static __forceinline
typedef struct FreeList { void *head; int count; } FreeList;
INL int list_full(FreeList *l, int limit) { return l->count >= limit; }
INL void list_push(FreeList *l, void *o) { l->count++; *(void **)o = l->head; l->head = o; }
typedef struct Pool2 { char pad0[0x34]; int limit; char pad1[0x48 - 0x34 - 4]; FreeList list; } Pool2;
typedef struct Elem36 { unsigned char b[36]; } Elem36;
typedef struct Elem36Buf { Elem36 *data; int count; int capFlags; } Elem36Buf;

static void Elem36Buf_Free(Elem36Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem36), 0x17);
    }
}

typedef struct PooledElem36Obj {
    Elem36Buf items;
} PooledElem36Obj;

PooledElem36Obj *fn_885F2390(PooledElem36Obj *o, unsigned int flags)
{
    Elem36Buf_Free(&o->items);
    if ((flags & 1) != 0) {
        Pool2 *p = (Pool2 *)KeTlsGetValue(lbl_88CACF08);
        if (list_full(&p->list, p->limit)) { fn_8841A3F8(p, 2, o); }
        else { list_push(&p->list, o); }
    }
    return o;
}
