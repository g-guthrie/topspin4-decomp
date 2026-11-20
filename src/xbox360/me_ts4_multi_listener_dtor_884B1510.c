/* 0x884B1510: Destructor body of a multi-base object: sets four vtables (+0, +8, +0x20, listener +0x28), clears every slot of the owner at +0x24 that refers to the listener (ts4_clear_pointer_slot_8846B168), frees the word list at +0x2c (kind 0x17), resets the listener vtable to lbl_88088878 and runs ts4_destroy_multi2_884B6FF8. */
/* Matched on /Oc (agAH). Owner tested through the object (o->owner != 0) and the listener addressed as &o->listener at each use. */
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

extern const void *lbl_8808906C;
extern const void *lbl_8808904C;
extern const void *lbl_8808903C;
extern const void *lbl_8808902C;
extern const void *lbl_88088878;
typedef struct Slot Slot;
typedef struct Listener { const void *vtable; } Listener;
typedef struct SlotOwner { char pad[0x6c]; Slot **slots; int count; } SlotOwner;
void ts4_clear_pointer_slot_8846B168(Slot *slot, Listener *l);
typedef struct MultiObj {
    const void *vtable;
    int unk4;
    const void *vtable8;
    char padC[0x14];
    const void *vtable20;
    SlotOwner *owner;
    Listener listener;
    Elem4Buf words;
} MultiObj;
void ts4_destroy_multi2_884B6FF8(MultiObj *o);

void fn_884B1510(MultiObj *o)
{
    o->vtable = &lbl_8808906C;
    o->vtable8 = &lbl_8808904C;
    o->vtable20 = &lbl_8808903C;
    o->listener.vtable = &lbl_8808902C;
    if (o->owner != 0) {
        int i;
        for (i = 0; i < o->owner->count; i++)
            ts4_clear_pointer_slot_8846B168(o->owner->slots[i], &o->listener);
    }
    Elem4Buf_Free(&o->words);
    o->listener.vtable = &lbl_88088878;
    ts4_destroy_multi2_884B6FF8(o);
}
