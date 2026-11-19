/* 0x884DCC60: Destructor body: frees both byte arrays of every 24-byte name pair at +0x18, then the pair array, then the byte array at +0xc (kind 0x17, each skipped if externally owned), and sets the base vtable lbl_8803A308. */
/* Near miss (agAH): /Oc, 2 instructions off: li r30,0 and mr r27,r11 (loop index and count copy) are scheduled in the opposite order. */
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

extern const void *lbl_8803A308;
typedef struct NamePair { Elem1Buf key; Elem1Buf value; } NamePair;
typedef struct NamePairBuf { NamePair *data; int count; int capFlags; } NamePairBuf;
typedef struct NamePairObj { const void *vtable; char pad[8]; Elem1Buf bytes; NamePairBuf pairs; } NamePairObj;

static void NamePairBuf_Free(NamePairBuf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(NamePair), 0x17);
    }
}

void fn_884DCC60(NamePairObj *o)
{
    if (o->pairs.count > 0) {
        int n = o->pairs.count;
        int i = 0;
        do {
            NamePair *p = &o->pairs.data[i];
            Elem1Buf_Free(&p->value);
            Elem1Buf_Free(&p->key);
            i++;
        } while (--n);
    }
    NamePairBuf_Free(&o->pairs);
    Elem1Buf_Free(&o->bytes);
    o->vtable = &lbl_8803A308;
}
