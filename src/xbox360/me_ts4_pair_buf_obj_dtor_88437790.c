/* 0x88437790: Destructor body: frees the pool-owned byte array at +0x14, then the 2-byte-element array at +0x8 (kind 0x17, each skipped if externally owned), then sets the base vtable lbl_8803A308. */
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
typedef struct Elem2 { unsigned char b[2]; } Elem2;
typedef struct Elem2Buf { Elem2 *data; int count; int capFlags; } Elem2Buf;

static void Elem2Buf_Free(Elem2Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem2), 0x17);
    }
}

extern const void *lbl_8803A308;
typedef struct PairBufObj { const void *vtable; int unk4; Elem2Buf wide; Elem1Buf narrow; } PairBufObj;

void fn_88437790(PairBufObj *t)
{
    Elem1Buf_Free(&t->narrow);
    Elem2Buf_Free(&t->wide);
    t->vtable = &lbl_8803A308;
}
