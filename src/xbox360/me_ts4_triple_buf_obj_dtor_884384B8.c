/* 0x884384B8: Destructor body: frees the pool-owned byte array at +0x30 and the 16-byte-element arrays at +0x24 and +0x18 (kind 0x17, each skipped if externally owned), then stores vtable lbl_8807FF50 at +0x10 and the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). Shared inline per-buffer free helper; same class shape as 88437BB0. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Elem16 { unsigned char b[16]; } Elem16;
typedef struct Elem16Buf { Elem16 *data; int count; int capFlags; } Elem16Buf;

static void Elem16Buf_Free(Elem16Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem16), 0x17);
    }
}
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

extern const void *lbl_8807FF50;
extern const void *lbl_8803A308;
typedef struct TripleBufObj {
    const void *vtable;
    char pad[0xc];
    const void *vtable2;
    int unk14;
    Elem16Buf first;
    Elem16Buf second;
    Elem1Buf bytes;
} TripleBufObj;

void fn_884384B8(TripleBufObj *o)
{
    Elem1Buf_Free(&o->bytes);
    Elem16Buf_Free(&o->second);
    Elem16Buf_Free(&o->first);
    o->vtable2 = &lbl_8807FF50;
    o->vtable = &lbl_8803A308;
}
