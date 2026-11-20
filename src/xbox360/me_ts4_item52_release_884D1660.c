/* 0x884D1660: Releases a 52-byte item: deletes the child at +0x30 through vtable slot 0 (flag 1) if set, then frees the pool-owned arrays at +0x24 (8-byte), +0x18 (8-byte), +0xc (12-byte) and +0x0 (8-byte) (kind 0x17, each skipped if externally owned). Called per item by 884D1418. */
/* Matched on /Oc (agAH). Child pointer read into a local before the virtual delete (else it is reloaded for the call); typed per-buffer free helpers. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Elem8 { unsigned char b[8]; } Elem8;
typedef struct Elem8Buf { Elem8 *data; int count; int capFlags; } Elem8Buf;

static void Elem8Buf_Free(Elem8Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem8), 0x17);
    }
}
typedef struct Elem12 { unsigned char b[12]; } Elem12;
typedef struct Elem12Buf { Elem12 *data; int count; int capFlags; } Elem12Buf;

static void Elem12Buf_Free(Elem12Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem12), 0x17);
    }
}

typedef struct Deletable { void (**vtable)(struct Deletable *self, unsigned int flags); } Deletable;
typedef struct Item52 {
    Elem8Buf a;
    Elem12Buf b;
    Elem8Buf c;
    Elem8Buf d;
    Deletable *child;
} Item52;

void fn_884D1660(Item52 *it)
{
    Deletable *c = it->child;
    if (c)
        c->vtable[0](c, 1);
    Elem8Buf_Free(&it->d);
    Elem8Buf_Free(&it->c);
    Elem12Buf_Free(&it->b);
    Elem8Buf_Free(&it->a);
}
