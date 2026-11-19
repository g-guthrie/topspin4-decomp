/* 0x8843B590: Destructor body of a five-vtable object: sets vtables +0..+0x14, releases every refcounted object in the list at +0x30 (deleting dtor with flag 1 when its count reaches 0), frees the list storage (kind 0x17) unless externally owned, then resets the five vtables to the base set. */
/* Matched on /Oc (agAH). Elements are not null-tested; per-buffer free helper __forceinline. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
extern const void *lbl_880800E8;
extern const void *lbl_880800DC;
extern const void *lbl_880800BC;
extern const void *lbl_880800D0;
extern const void *lbl_880800B0;
extern const void *lbl_88080084;
extern const void *lbl_880800A4;
extern const void *lbl_88080090;
extern const void *lbl_88080078;
extern const void *lbl_8803A308;
typedef struct RefObj {
    void (**vtable)(struct RefObj *self, unsigned int flags);
    unsigned short counted;
    short refs;
} RefObj;
typedef struct RefList { RefObj **items; int count; int capFlags; } RefList;
typedef struct MultiObj {
    const void *vtable;
    int unk4;
    const void *vtable8;
    const void *vtableC;
    const void *vtable10;
    const void *vtable14;
    char pad18[0x18];
    RefList refs;
} MultiObj;

static __forceinline void RefList_Free(RefList *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->items, cap * sizeof(RefObj *), 0x17);
    }
}

void fn_8843B590(MultiObj *o)
{
    int i;
    o->vtable = &lbl_880800E8;
    o->vtable8 = &lbl_880800DC;
    o->vtableC = &lbl_880800BC;
    o->vtable10 = &lbl_880800D0;
    o->vtable14 = &lbl_880800B0;
    for (i = 0; i < o->refs.count; i++) {
        RefObj *p = o->refs.items[i];
        if (p->counted != 0 && --p->refs == 0)
            p->vtable[0](p, 1);
    }
    RefList_Free(&o->refs);
    o->vtable14 = &lbl_88080084;
    o->vtable10 = &lbl_880800A4;
    o->vtableC = &lbl_88080090;
    o->vtable8 = &lbl_88080078;
    o->vtable = &lbl_8803A308;
}
