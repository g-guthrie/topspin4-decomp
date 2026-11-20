/* 0x88492D88: Destructor body: sets vtable lbl_880876F0, runs an empty per-element loop over the list at +0x38 (inlined destructor of trivially destructible elements), frees the word lists at +0x5c, +0x48 and +0x38 (kind 0x17, each skipped if externally owned), then sets the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). The empty counting loop with its clrrwi copy comes from reading the bound through an inline accessor each iteration; typed per-buffer free helper. */
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

extern const void *lbl_880876F0;
extern const void *lbl_8803A308;
typedef struct ThreeListObj {
    const void *vtable;
    char pad[0x34];
    Elem4Buf a;
    char pad2[0x4];
    Elem4Buf b;
    char pad3[0x8];
    Elem4Buf c;
} ThreeListObj;

static int ThreeListObj_Count(ThreeListObj *o) { return o->a.count; }

void fn_88492D88(ThreeListObj *o)
{
    int i;
    o->vtable = &lbl_880876F0;
    for (i = 0; i < ThreeListObj_Count(o); i++)
        ;
    Elem4Buf_Free(&o->c);
    Elem4Buf_Free(&o->b);
    Elem4Buf_Free(&o->a);
    o->vtable = &lbl_8803A308;
}
