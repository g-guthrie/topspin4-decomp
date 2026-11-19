/* 0x884B2470: Destructor body (same class shape as 884B1510): sets four vtables, clears the owner slots that refer to the listener at +0x28, runs the slot-0 virtual destructor (flag 0) of each 128-byte element at +0x2c and frees that array (kind 0x17) unless externally owned, resets the listener vtable to lbl_88088878 and runs ts4_destroy_multi2_884B6FF8. */
/* Matched on /Oc (agAH). 884B1510 shape plus an if (n > 0) do { elem.vtable[0](&elem, 0); } while (--n) element loop. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Element128 { void (**vtable)(struct Element128 *self, unsigned int flags); unsigned char rest[124]; } Element128;
typedef struct Element128Buf { Element128 *data; int count; int capFlags; } Element128Buf;

static void Element128Buf_Free(Element128Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Element128), 0x17);
    }
}

extern const void *lbl_880891B0;
extern const void *lbl_88089190;
extern const void *lbl_88089180;
extern const void *lbl_88089170;
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
    Element128Buf elements;
} MultiObj;
void ts4_destroy_multi2_884B6FF8(MultiObj *o);

void fn_884B2470(MultiObj *o)
{
    o->vtable = &lbl_880891B0;
    o->vtable8 = &lbl_88089190;
    o->vtable20 = &lbl_88089180;
    o->listener.vtable = &lbl_88089170;
    if (o->owner != 0) {
        int i;
        for (i = 0; i < o->owner->count; i++)
            ts4_clear_pointer_slot_8846B168(o->owner->slots[i], &o->listener);
    }
    {
        int n = o->elements.count;
        if (n > 0) {
            int i = 0;
            do {
                o->elements.data[i].vtable[0](&o->elements.data[i], 0);
                i++;
            } while (--n);
        }
    }
    Element128Buf_Free(&o->elements);
    o->listener.vtable = &lbl_88088878;
    ts4_destroy_multi2_884B6FF8(o);
}
