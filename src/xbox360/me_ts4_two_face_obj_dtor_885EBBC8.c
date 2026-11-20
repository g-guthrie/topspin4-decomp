/* 0x885EBBC8: Destructor body of a two-base object: sets vtables lbl_880C078C/+0 and lbl_880C076C/+8, frees the table at +0x1c and the pool-owned byte array at +0x10, then runs the secondary base dtor (vtable lbl_880C074C, link at +0xc cleared) and sets the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). The secondary base must be an embedded struct with its own inline dtor helper; plain field stores in the outer function get reordered. */
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

typedef struct Elem8 { unsigned char b[8]; } Elem8;
typedef struct Elem8Table { Elem8 *data; int flags; int last; } Elem8Table;
void fn_88423D60(Elem8Table *t);
extern const void *lbl_880C078C;
extern const void *lbl_880C076C;
extern const void *lbl_880C074C;
extern const void *lbl_8803A308;
typedef struct LinkBase { const void *vtable; int link; } LinkBase;

static void LinkBase_Dtor(LinkBase *b)
{
    b->vtable = &lbl_880C074C;
    b->link = 0;
}

typedef struct TwoFaceObj {
    const void *vtable;
    int unk4;
    LinkBase base2;
    Elem1Buf bytes;
    Elem8Table table;
} TwoFaceObj;

void fn_885EBBC8(TwoFaceObj *o)
{
    o->vtable = &lbl_880C078C;
    o->base2.vtable = &lbl_880C076C;
    fn_88423D60(&o->table);
    Elem1Buf_Free(&o->bytes);
    LinkBase_Dtor(&o->base2);
    o->vtable = &lbl_8803A308;
}
