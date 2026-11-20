/* 0x8841C2B8: Destructor body: frees the pool-owned 4-byte-element array at +0x14, frees the 8-byte table at +0x8 via fn_88423D60, then sets the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). Shared inline per-buffer free helper (signed capacity word, & (int)0x80000000 test, masked capacity local before KeTlsGetValue, cap * sizeof(elem)) with C vtable stores; see 884DC9B0. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Elem4 { unsigned char b[4]; } Elem4;
typedef struct Elem4Buf { Elem4 *data; int count; int capFlags; } Elem4Buf;

static void Elem4Buf_Free(Elem4Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem4), 0x17);
    }
}

extern const void *lbl_8803A308;
typedef struct Elem8 { unsigned char b[8]; } Elem8;
typedef struct Elem8Table { Elem8 *data; int flags; int last; } Elem8Table;
void fn_88423D60(Elem8Table *t);
typedef struct TableBufObj { const void *vtable; int unk4; Elem8Table table; Elem4Buf items; } TableBufObj;

void fn_8841C2B8(TableBufObj *m)
{
    Elem4Buf_Free(&m->items);
    fn_88423D60(&m->table);
    m->vtable = &lbl_8803A308;
}
