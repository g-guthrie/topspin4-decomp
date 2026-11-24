/* 0x884D58B0: For each 16-byte bucket (key, 8-byte table): calls fn_884D5740(list, key, &table), then frees the table via fn_88423D60; finally frees the bucket array (kind 0x17) unless externally owned. */
/* Matched on /Oc (agAH). Index the array through l->data[i] in each call (reloaded after each call); typed per-buffer free helper. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);

typedef struct Elem8 { unsigned char b[8]; } Elem8;
typedef struct Elem8Table { Elem8 *data; int flags; int last; } Elem8Table;
void fn_88423D60(Elem8Table *t);
typedef struct Bucket { int key; Elem8Table table; } Bucket;
typedef struct BucketList { Bucket *data; int count; int capFlags; } BucketList;
void fn_884D5740(BucketList *l, int key, Elem8Table *table);

static void BucketList_Free(BucketList *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Bucket), 0x17);
    }
}

void fn_884D58B0(BucketList *l)
{
    int i;
    for (i = 0; i < l->count; i++) {
        fn_884D5740(l, l->data[i].key, &l->data[i].table);
        fn_88423D60(&l->data[i].table);
    }
    BucketList_Free(l);
}
