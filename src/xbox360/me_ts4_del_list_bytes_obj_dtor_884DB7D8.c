/* 0x884DB7D8: Destructor body: sets vtable lbl_8808CDAC, calls the virtual deleting destructor (slot 0, flag 1) of each non-null object in the list at +0x8, frees the byte array at +0x14 and then the list storage (kind 0x17, each skipped if externally owned), and sets the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). Element read into a local before the null test; typed per-buffer free helpers. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Deletable { void (**vtable)(struct Deletable *self, unsigned int flags); } Deletable;
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
typedef struct DelList { Deletable **items; int count; int capFlags; } DelList;
extern const void *lbl_8808CDAC;
extern const void *lbl_8803A308;
typedef struct DelListBytesObj { const void *vtable; int unk4; DelList list; Elem1Buf bytes; } DelListBytesObj;

static void DelList_Free(DelList *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->items, cap * sizeof(Deletable *), 0x17);
    }
}

void fn_884DB7D8(DelListBytesObj *o)
{
    int i;
    o->vtable = &lbl_8808CDAC;
    for (i = 0; i < o->list.count; i++) {
        Deletable *d = o->list.items[i];
        if (d)
            d->vtable[0](d, 1);
    }
    Elem1Buf_Free(&o->bytes);
    DelList_Free(&o->list);
    o->vtable = &lbl_8803A308;
}
