/* 0x884BF008: Destructor body: frees the pool-owned byte array at +0x98 and the 40-byte-record array at +0x8c (kind 0x17, each skipped if externally owned), then sets the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). Shared inline per-buffer free helper (see 884DC9B0); deleting variants use the d1_band2_deleting_dtors_a.c tail; 884CCAB0 inlines the 884D50C8 index free. */
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
typedef struct Elem40 { unsigned char b[40]; } Elem40;
typedef struct Elem40Buf { Elem40 *data; int count; int capFlags; } Elem40Buf;

static void Elem40Buf_Free(Elem40Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem40), 0x17);
    }
}

extern const void *lbl_8803A308;
typedef struct RecordBufObj { const void *vtable; char pad[0x88]; Elem40Buf records; Elem1Buf bytes; } RecordBufObj;

void fn_884BF008(RecordBufObj *o)
{
    Elem1Buf_Free(&o->bytes);
    Elem40Buf_Free(&o->records);
    o->vtable = &lbl_8803A308;
}
