/* 0x884B74E8: Destructor body: sets vtable lbl_88089584, calls the virtual deleting destructor (slot 0, flag 1) of every non-null object in the list at +0x8, frees the list storage (kind 0x17) unless externally owned, then sets the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). Element read into a local before the null test; C virtual call through slot 0; typed per-buffer free helper. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);

typedef struct Deletable { void (**vtable)(struct Deletable *self, unsigned int flags); } Deletable;
typedef struct DelList { Deletable **items; int count; int capFlags; } DelList;
extern const void *lbl_88089584;
extern const void *lbl_8803A308;
typedef struct DelListObj { const void *vtable; int unk4; DelList list; } DelListObj;

static void DelList_Free(DelList *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->items, cap * sizeof(Deletable *), 0x17);
    }
}

void fn_884B74E8(DelListObj *o)
{
    int i;
    o->vtable = &lbl_88089584;
    for (i = 0; i < o->list.count; i++) {
        Deletable *d = o->list.items[i];
        if (d)
            d->vtable[0](d, 1);
    }
    DelList_Free(&o->list);
    o->vtable = &lbl_8803A308;
}
