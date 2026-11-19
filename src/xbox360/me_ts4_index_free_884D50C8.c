/* 0x884D50C8: Releases an index: frees its 8-byte-element lookup table via fn_88423D60, then its pool-owned 8-byte entry array through the TLS allocator (kind 0x17). */
/* Matched on /Oc (agAH). Per-buffer inline free helper (signed capacity word, & (int)0x80000000 test) after the table free call. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Elem8 { unsigned char b[8]; } Elem8;
typedef struct Elem8Buf { Elem8 *data; int count; int capFlags; } Elem8Buf;

static void Elem8Buf_Free(Elem8Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem8), 0x17);
    }
}

typedef struct Elem8Table { Elem8 *data; int flags; int last; } Elem8Table;
typedef struct Index { Elem8Buf entries; Elem8Table table; } Index;
void fn_88423D60(Elem8Table *t);

void fn_884D50C8(Index *x)
{
    fn_88423D60(&x->table);
    Elem8Buf_Free(&x->entries);
}
