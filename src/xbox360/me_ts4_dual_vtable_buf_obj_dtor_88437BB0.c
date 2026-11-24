/* 0x88437BB0: Destructor body: frees the pool-owned 2-byte-element array at +0x40 and the 56-byte-record array at +0x34 (kind 0x17, each skipped if externally owned), then stores vtable lbl_8807FF50 at +0x10 and the base vtable lbl_8803A308 at +0. */
/* Matched on /Oc (agAH). Shared inline per-buffer free helper; 56-byte elements give mulli 0x38. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Elem56 { unsigned char b[56]; } Elem56;
typedef struct Elem56Buf { Elem56 *data; int count; int capFlags; } Elem56Buf;

static void Elem56Buf_Free(Elem56Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem56), 0x17);
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

extern const void *lbl_8807FF50;
extern const void *lbl_8803A308;
typedef struct DualBase { const void *vtable; char pad[0xc]; const void *vtable2; char pad2[0x20]; Elem56Buf records; Elem2Buf wide; } DualBase;

void fn_88437BB0(DualBase *o)
{
    Elem2Buf_Free(&o->wide);
    Elem56Buf_Free(&o->records);
    o->vtable2 = &lbl_8807FF50;
    o->vtable = &lbl_8803A308;
}
