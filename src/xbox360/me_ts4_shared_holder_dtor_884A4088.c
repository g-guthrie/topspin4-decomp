/* 0x884A4088: Destructor body: sets vtable lbl_88087EDC, drops one reference on the shared object at +0x8 (if set) and on every object of the list at +0xc (deleting through vtable slot 0 at zero when reference-counted), frees the list (kind 0x17) unless externally owned, then sets the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). Shared release helper (counted && --refs == 0 then slot-0 delete); main pointer read into a local before the vtable store. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);

extern const void *lbl_88087EDC;
extern const void *lbl_8803A308;
typedef struct Shared {
    void (**vtable)(struct Shared *self, unsigned int flags);
    unsigned short counted;
    short refs;
} Shared;
typedef struct SharedList { Shared **items; int count; int capFlags; } SharedList;
typedef struct SharedHolder { const void *vtable; int unk4; Shared *main; SharedList list; } SharedHolder;

static void Shared_Release(Shared *s)
{
    if (s->counted != 0 && --s->refs == 0)
        s->vtable[0](s, 1);
}

static void SharedList_Free(SharedList *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->items, cap * sizeof(Shared *), 0x17);
    }
}

void fn_884A4088(SharedHolder *o)
{
    Shared *m = o->main;
    int i;
    o->vtable = &lbl_88087EDC;
    if (m != 0)
        Shared_Release(m);
    for (i = 0; i < o->list.count; i++)
        Shared_Release(o->list.items[i]);
    SharedList_Free(&o->list);
    o->vtable = &lbl_8803A308;
}
