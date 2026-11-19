/* 0x88448048: Destructor body: sets vtable lbl_88081E10, frees the pool-owned arrays at +0x2c (2-byte), +0x20 (4-byte), +0x14 (byte) and +0x8 (4-byte) (kind 0x17, each skipped if externally owned), then sets the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). Shared inline per-buffer free helper (see 884DC9B0). */
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

extern const void *lbl_88081E10;
extern const void *lbl_8803A308;
typedef struct FourBufObj {
    const void *vtable;
    int unk4;
    Elem4Buf w1;
    Elem1Buf b;
    Elem4Buf w2;
    Elem2Buf h;
} FourBufObj;

void fn_88448048(FourBufObj *o)
{
    o->vtable = &lbl_88081E10;
    Elem2Buf_Free(&o->h);
    Elem4Buf_Free(&o->w2);
    Elem1Buf_Free(&o->b);
    Elem4Buf_Free(&o->w1);
    o->vtable = &lbl_8803A308;
}
