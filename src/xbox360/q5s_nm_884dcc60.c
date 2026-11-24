/* 0x884DCC60 (/Oc): destructor body for an object holding a byte array at +0xC and an
 * array of 24-byte name pairs at +0x18. Frees both byte arrays of every pair, then the
 * pair array, then the byte array (allocator kind 0x17; each is skipped when the
 * "not owned" bit 31 of capFlags is set), then sets the base vtable lbl_8803A308.
 * Matching note: the pair count must be cached in a local (n) for the loop bound;
 * a do/while with --n or a loop bound that re-reads o->pairs.count reorders li/mr. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
extern const void *lbl_8803A308;

typedef struct Ts4ByteArray { unsigned char *data; int count; int capFlags; } Ts4ByteArray;
typedef struct Ts4NamePair { Ts4ByteArray key; Ts4ByteArray value; } Ts4NamePair;
typedef struct Ts4NamePairArray { Ts4NamePair *data; int count; int capFlags; } Ts4NamePairArray;
typedef struct Ts4NamePairOwner {
    const void *vtable;
    char pad04[8];
    Ts4ByteArray bytes;      /* +0x0C */
    Ts4NamePairArray pairs;  /* +0x18 */
} Ts4NamePairOwner;

static void Ts4ByteArray_Free(Ts4ByteArray *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(unsigned char), 0x17);
    }
}

static void Ts4NamePairArray_Free(Ts4NamePairArray *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Ts4NamePair), 0x17);
    }
}

void ts4_name_pair_owner_dtor_884DCC60(Ts4NamePairOwner *o)
{
    int i;
    int n = o->pairs.count;
    for (i = 0; i < n; i++) {
        Ts4NamePair *p = o->pairs.data + i;
        Ts4ByteArray_Free(&p->value);
        Ts4ByteArray_Free(&p->key);
    }
    Ts4NamePairArray_Free(&o->pairs);
    Ts4ByteArray_Free(&o->bytes);
    o->vtable = &lbl_8803A308;
}
