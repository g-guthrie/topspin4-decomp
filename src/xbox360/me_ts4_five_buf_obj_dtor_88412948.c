/* 0x88412948: Destructor body: sets vtable lbl_8803AE14, frees the pool-owned byte array at +0x70 and the word lists at +0x64, +0x58, +0x4c and +0x40 (kind 0x17, each skipped if externally owned), then sets the base vtable lbl_8803A308. */
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

extern const void *lbl_8803AE14;
extern const void *lbl_8803A308;
typedef struct FiveBufObj {
    const void *vtable;
    char pad[0x3c];
    Elem4Buf w1;
    Elem4Buf w2;
    Elem4Buf w3;
    Elem4Buf w4;
    Elem1Buf bytes;
} FiveBufObj;

void fn_88412948(FiveBufObj *o)
{
    o->vtable = &lbl_8803AE14;
    Elem1Buf_Free(&o->bytes);
    Elem4Buf_Free(&o->w4);
    Elem4Buf_Free(&o->w3);
    Elem4Buf_Free(&o->w2);
    Elem4Buf_Free(&o->w1);
    o->vtable = &lbl_8803A308;
}
