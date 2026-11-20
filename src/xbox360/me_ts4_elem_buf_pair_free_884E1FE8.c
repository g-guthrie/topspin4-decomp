/* 0x884E1FE8: Frees the two pool-owned arrays of a pair (12-byte elements first, then 16-byte) through the TLS allocator, kind 0x17, unless the capacity word has the external-storage bit set. */
/* Matched on /Oc (agAH). Same per-buffer inline helper as 884DC9B0: signed capacity word, & (int)0x80000000 test, masked capacity in a local before KeTlsGetValue, byte size cap * sizeof(elem) in the call. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);

typedef struct Elem12 { unsigned int w[3]; } Elem12;
typedef struct Elem16 { unsigned int w[4]; } Elem16;
typedef struct Elem16Buf { Elem16 *data; int count; int capFlags; } Elem16Buf;
typedef struct Elem12Buf { Elem12 *data; int count; int capFlags; } Elem12Buf;
typedef struct BufPair { Elem16Buf a; Elem12Buf b; } BufPair;

static void Elem12Buf_Free(Elem12Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem12), 0x17);
    }
}

static void Elem16Buf_Free(Elem16Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem16), 0x17);
    }
}

void fn_884E1FE8(BufPair *p)
{
    Elem12Buf_Free(&p->b);
    Elem16Buf_Free(&p->a);
}
