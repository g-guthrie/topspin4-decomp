/* 0x884A8C80: Destructor body: sets vtable lbl_88088130, releases the counted refs at +0x8 and +0xc if set, destroys the member at +0xf4 via fn_884A8B00, frees the byte array at +0x68, the 32-byte records at +0x5c and the byte array at +0x50 (kind 0x17, each skipped if externally owned), then sets the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). Per-buffer inline free helpers in reverse member order; plain null-checked release calls. */
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
typedef struct Elem32 { unsigned char b[32]; } Elem32;
typedef struct Elem32Buf { Elem32 *data; int count; int capFlags; } Elem32Buf;

static void Elem32Buf_Free(Elem32Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem32), 0x17);
    }
}

typedef struct RefTarget RefTarget;
void ts4_counted_ref_release_88475B08(RefTarget *r);
void fn_884A8B00(void *member);
extern const void *lbl_88088130;
extern const void *lbl_8803A308;
typedef struct RefBufObj {
    const void *vtable;
    int unk4;
    RefTarget *refA;
    RefTarget *refB;
    char pad[0x40];
    Elem1Buf names;
    Elem32Buf records;
    Elem1Buf bytes;
    char pad2[0x80];
    char member[4];
} RefBufObj;

void fn_884A8C80(RefBufObj *o)
{
    o->vtable = &lbl_88088130;
    if (o->refA)
        ts4_counted_ref_release_88475B08(o->refA);
    if (o->refB)
        ts4_counted_ref_release_88475B08(o->refB);
    fn_884A8B00(&o->member);
    Elem1Buf_Free(&o->bytes);
    Elem32Buf_Free(&o->records);
    Elem1Buf_Free(&o->names);
    o->vtable = &lbl_8803A308;
}
