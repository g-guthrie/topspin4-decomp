/* 0x884DA900: Returns every pooled node in the list at +0x18 to the TLS allocator (ts4_if_get_u32_0xc_8841A820), frees the list storage (kind 0x17) unless externally owned, then frees the tables at +0xc and +0 via fn_88423D60. */
/* Matched on /Oc (agAH). Element read into a local before the KeTlsGetValue call; typed per-buffer free helper. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);

typedef struct Elem8 { unsigned char b[8]; } Elem8;
typedef struct Elem8Table { Elem8 *data; int flags; int last; } Elem8Table;
void fn_88423D60(Elem8Table *t);
typedef struct PoolNode PoolNode;
void ts4_if_get_u32_0xc_8841A820(void *allocator, PoolNode *node);
typedef struct NodeList { PoolNode **items; int count; int capFlags; } NodeList;
typedef struct NodeIndex { Elem8Table first; Elem8Table second; NodeList nodes; } NodeIndex;

static void NodeList_Free(NodeList *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->items, cap * sizeof(PoolNode *), 0x17);
    }
}

void fn_884DA900(NodeIndex *x)
{
    int i;
    for (i = 0; i < x->nodes.count; i++) {
        PoolNode *n = x->nodes.items[i];
        ts4_if_get_u32_0xc_8841A820(KeTlsGetValue(lbl_88CACF08), n);
    }
    NodeList_Free(&x->nodes);
    fn_88423D60(&x->second);
    fn_88423D60(&x->first);
}
