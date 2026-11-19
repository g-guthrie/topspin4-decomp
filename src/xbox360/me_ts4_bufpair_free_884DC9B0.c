/* 0x884DC9B0: Frees the two pool-owned buffers of a pair (second first) through the TLS allocator, kind 0x17, skipping buffers whose capacity word has the external-storage bit set. */
/* Matched on /Oc (agAH). Inline per-buffer helper with the masked capacity in a local before the KeTlsGetValue call; the capacity word must be signed int and the test written as & (int)0x80000000 to get cmpwi. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);

typedef struct PooledBuf {
    void *data;
    int count;
    int capFlags;
} PooledBuf;

typedef struct BufPair {
    PooledBuf a;
    PooledBuf b;
} BufPair;

static void PooledBuf_Free(PooledBuf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap, 0x17);
    }
}

void fn_884DC9B0(BufPair *p)
{
    PooledBuf_Free(&p->b);
    PooledBuf_Free(&p->a);
}
