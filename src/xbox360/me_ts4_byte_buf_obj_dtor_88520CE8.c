/* 0x88520CE8: Destructor body: sets vtable lbl_8808DFE8, frees the pool-owned byte array at +0x20 (kind 0x17) unless externally owned, then sets the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). Shared inline per-buffer free helper (signed capacity word, & (int)0x80000000 test, masked capacity local before KeTlsGetValue, cap * sizeof(elem)) with C vtable stores; see 884DC9B0. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
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

extern const void *lbl_8808DFE8;
extern const void *lbl_8803A308;
typedef struct ByteBufObj { const void *vtable; char pad[0x1c]; Elem1Buf bytes; } ByteBufObj;

void fn_88520CE8(ByteBufObj *b)
{
    b->vtable = &lbl_8808DFE8;
    Elem1Buf_Free(&b->bytes);
    b->vtable = &lbl_8803A308;
}
