/* 0x885EEFB8: Destroys every non-null pooled object in the pointer list at +0x30 (deleting dtor with flag 1), zeroes the count, then frees the list storage (kind 0x17) unless externally owned. */
/* Matched on /Oc (agAH). Read each element into a local before the null test (reading it twice gives a clrrwi copy); per-buffer free helper typed on the list. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct PooledObj PooledObj;
void ts4_pooled_deleting_dtor_885EC408(PooledObj *o, unsigned int flags);
typedef struct PtrList { PooledObj **items; int count; int capFlags; } PtrList;
static void PtrList_Free(PtrList *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->items, cap * sizeof(PooledObj *), 0x17);
    }
}

typedef struct Owner { char pad[0x30]; PtrList list; } Owner;

void fn_885EEFB8(Owner *o)
{
    int i;
    for (i = 0; i < o->list.count; i++) {
        PooledObj *p = o->list.items[i];
        if (p)
            ts4_pooled_deleting_dtor_885EC408(p, 1);
    }
    o->list.count = 0;
    PtrList_Free(&o->list);
}
