/* 0x884D1418: Releases a container: runs fn_884D1660 on each 52-byte item at +0x40 and frees the item array, frees the 12-byte table at +0x30 (fn_885E7BA8), destroys the holder at +0x20, then frees the 8-byte array at +0x10 and the 48-byte array at +0x4 (kind 0x17, each skipped if externally owned). */
/* Matched on /Oc (agAH). if (n > 0) do { ...; i++; } while (--n); item loop; typed per-buffer free helpers. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Elem48 { unsigned char b[48]; } Elem48;
typedef struct Elem48Buf { Elem48 *data; int count; int capFlags; } Elem48Buf;

static void Elem48Buf_Free(Elem48Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem48), 0x17);
    }
}
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

typedef struct Elem52 { unsigned char b[52]; } Elem52;
typedef struct Elem52Buf { Elem52 *data; int count; int capFlags; } Elem52Buf;
typedef struct Elem12 { unsigned char b[12]; } Elem12;
typedef struct Elem12Table { Elem12 *data; int flags; int last; } Elem12Table;
void fn_884D1660(Elem52 *e);
void fn_885E7BA8(Elem12Table *t);
void ts4_ref_holder_dtor_owner_884DA7B0(void *holder);

static void Elem52Buf_Free(Elem52Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem52), 0x17);
    }
}

typedef struct ItemContainer {
    int unk0;
    Elem48Buf big;
    Elem8Buf pairs;
    char pad1C[4];
    char holder[0x10];
    Elem12Table table;
    int unk3C;
    Elem52Buf items;
} ItemContainer;

void fn_884D1418(ItemContainer *s)
{
    int n = s->items.count;
    int i;
    if (n > 0) {
        i = 0;
        do {
            fn_884D1660(&s->items.data[i]);
            i++;
        } while (--n);
    }
    Elem52Buf_Free(&s->items);
    fn_885E7BA8(&s->table);
    ts4_ref_holder_dtor_owner_884DA7B0(&s->holder);
    Elem8Buf_Free(&s->pairs);
    Elem48Buf_Free(&s->big);
}
