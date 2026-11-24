/* 0x884A21A8: Pooled deleting destructor: frees the word lists at +0xc and +0x0 (kind 0x17, each skipped if externally owned); with flags bit 0 returns the object to the kind-3 per-thread free list (fn_8841A3F8 when full); returns the object. */
/* Matched on /Oc (agAH). Per-buffer inline free helper plus list_full/list_push (pool list at +0x38 + 8*kind). */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
void fn_8841A3F8(void *pool, int kind, void *object);
#define INL static __forceinline
typedef struct FreeList { void *head; int count; } FreeList;
INL int list_full(FreeList *l, int limit) { return l->count >= limit; }
INL void list_push(FreeList *l, void *o) { l->count++; *(void **)o = l->head; l->head = o; }
typedef struct Pool3 { char pad0[0x34]; int limit; char pad1[0x50 - 0x34 - 4]; FreeList list; } Pool3;
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

typedef struct TwoWordLists { Elem4Buf first; Elem4Buf second; } TwoWordLists;

TwoWordLists *fn_884A21A8(TwoWordLists *o, unsigned int flags)
{
    Elem4Buf_Free(&o->second);
    Elem4Buf_Free(&o->first);
    if ((flags & 1) != 0) {
        Pool3 *p = (Pool3 *)KeTlsGetValue(lbl_88CACF08);
        if (list_full(&p->list, p->limit)) { fn_8841A3F8(p, 3, o); }
        else { list_push(&p->list, o); }
    }
    return o;
}
