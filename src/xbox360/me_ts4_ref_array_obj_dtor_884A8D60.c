/* 0x884A8D60: Destructor body: sets vtable lbl_880881D8, releases the counted ref at the start of each 80-byte element, frees the element array (kind 0x17) unless externally owned, then sets the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). if (n > 0) do { ... } while (--n); gives the subic./bne loop; a for loop gives bgt. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);

typedef struct RefTarget RefTarget;
void ts4_counted_ref_release_88475B08(RefTarget *r);
typedef struct Elem80 { RefTarget *ref; unsigned char rest[76]; } Elem80;
typedef struct Elem80Buf { Elem80 *data; int count; int capFlags; } Elem80Buf;
extern const void *lbl_880881D8;
extern const void *lbl_8803A308;
typedef struct RefArrayObj { const void *vtable; int unk4; Elem80Buf items; } RefArrayObj;

static void Elem80Buf_Free(Elem80Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem80), 0x17);
    }
}

void fn_884A8D60(RefArrayObj *o)
{
    int n = o->items.count;
    int i;
    o->vtable = &lbl_880881D8;
    if (n > 0) {
        i = 0;
        do {
            ts4_counted_ref_release_88475B08(o->items.data[i].ref);
            i++;
        } while (--n);
    }
    Elem80Buf_Free(&o->items);
    o->vtable = &lbl_8803A308;
}
