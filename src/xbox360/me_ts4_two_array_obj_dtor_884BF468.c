/* 0x884BF468: Destructor body: frees the pool-owned 12-byte-element array at +0x14 and the 48-byte-element array at +0x8 (kind 0x17, each skipped if externally owned), then sets the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). Shared inline per-buffer free helper (see 884DC9B0). */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Elem48 { unsigned char b[48]; } Elem48;
typedef struct Elem48Buf { Elem48 *data; int count; int capFlags; } Elem48Buf;

static void Elem48Buf_Free(Elem48Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem48), 0x17);
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

extern const void *lbl_8803A308;
typedef struct TwoArrayObj { const void *vtable; int unk4; Elem48Buf big; Elem12Buf small; } TwoArrayObj;

void fn_884BF468(TwoArrayObj *o)
{
    Elem12Buf_Free(&o->small);
    Elem48Buf_Free(&o->big);
    o->vtable = &lbl_8803A308;
}
