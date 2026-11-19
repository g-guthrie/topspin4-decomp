/* 0x884CCAB0: Scalar deleting destructor: releases the embedded index at +0x14 (fn_88423D60 table free, then the 8-byte entry array), sets the base vtable, and with flags bit 0 frees the object by its u16 size (kind 0x15); returns the object. */
/* Matched on /Oc (agAH). Shared inline per-buffer free helper (see 884DC9B0); deleting variants use the d1_band2_deleting_dtors_a.c tail; 884CCAB0 inlines the 884D50C8 index free. */
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

extern const void *lbl_8803A308;
typedef struct Elem8Table { Elem8 *data; int flags; int last; } Elem8Table;
typedef struct Index { Elem8Buf entries; Elem8Table table; } Index;
void fn_88423D60(Elem8Table *t);
typedef struct SizedIndexObj { const void *vtable; unsigned short size; char pad[0xe]; Index index; } SizedIndexObj;

static void Index_Free(Index *x)
{
    fn_88423D60(&x->table);
    Elem8Buf_Free(&x->entries);
}

SizedIndexObj *fn_884CCAB0(SizedIndexObj *o, unsigned int flags)
{
    Index_Free(&o->index);
    o->vtable = &lbl_8803A308;
    if ((flags & 1) != 0) {
        void *allocator = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(allocator, o, o->size, 21);
    }
    return o;
}
