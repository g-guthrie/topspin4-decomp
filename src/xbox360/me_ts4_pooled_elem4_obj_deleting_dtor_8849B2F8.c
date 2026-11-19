/* 0x8849B2F8: Pooled deleting destructor: frees the 4-byte-element array at +0x5c (kind 0x17) unless externally owned; with flags bit 0 and a non-null object returns the object to the kind-7 per-thread free list, or through fn_8841A3F8 when the list is full; returns the object. */
/* Matched on /Oc (agAH). Per-buffer inline free helper plus list_full/list_push (free list at pool +0x38 + 8*kind). */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
void fn_8841A3F8(void *pool, int kind, void *object);
#define INL static __forceinline
typedef struct FreeList { void *head; int count; } FreeList;
INL int list_full(FreeList *l, int limit) { return l->count >= limit; }
INL void list_push(FreeList *l, void *o) { l->count++; *(void **)o = l->head; l->head = o; }
typedef struct Pool7 { char pad0[0x34]; int limit; char pad1[0x70 - 0x34 - 4]; FreeList list; } Pool7;
typedef struct Elem4 { unsigned char b[4]; } Elem4;
typedef struct Elem4Buf { Elem4 *data; int count; int capFlags; } Elem4Buf;

static void Elem4Buf_Free(Elem4Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem4), 0x17);
    }
}

typedef struct PooledElem4Obj {
    char pad[0x5c];
    Elem4Buf items;
} PooledElem4Obj;

PooledElem4Obj *fn_8849B2F8(PooledElem4Obj *o, unsigned int flags)
{
    Elem4Buf_Free(&o->items);
    if ((flags & 1) != 0 && o != 0) {
        Pool7 *p = (Pool7 *)KeTlsGetValue(lbl_88CACF08);
        if (list_full(&p->list, p->limit)) { fn_8841A3F8(p, 7, o); }
        else { list_push(&p->list, o); }
    }
    return o;
}
