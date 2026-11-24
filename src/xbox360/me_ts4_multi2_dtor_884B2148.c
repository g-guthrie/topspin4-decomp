/* 0x884B2148: Destructor body of a five-vtable object: sets the vtables at +0, +8, +0x20, +0x28 and +0x2c, calls fn_884B19A0(this, slot) for every slot of the owner at +0x24, frees the word list at +0x30 (kind 0x17) unless externally owned, resets the +0x2c/+0x28 vtables and runs ts4_destroy_multi2_884B6FF8. */
/* Matched on /Oc (agAH). Test the owner pointer through the object (o->owner != 0); a local copy compares with cmpwi instead of cmplwi. */
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

extern const void *lbl_88089144;
extern const void *lbl_88089124;
extern const void *lbl_88089114;
extern const void *lbl_880890FC;
extern const void *lbl_880890EC;
extern const void *lbl_88088878;
extern const void *lbl_88087B80;
typedef struct Slot Slot;
typedef struct SlotOwner { char pad[0x6c]; Slot **slots; int count; } SlotOwner;
typedef struct Multi2 {
    const void *vtable;
    int unk4;
    const void *vtable8;
    char padC[0x14];
    const void *vtable20;
    SlotOwner *owner;
    const void *vtable28;
    const void *vtable2C;
    Elem4Buf words;
} Multi2;
void fn_884B19A0(Multi2 *o, Slot *slot);
void ts4_destroy_multi2_884B6FF8(Multi2 *o);

void fn_884B2148(Multi2 *o)
{
    o->vtable = &lbl_88089144;
    o->vtable8 = &lbl_88089124;
    o->vtable20 = &lbl_88089114;
    o->vtable28 = &lbl_880890FC;
    o->vtable2C = &lbl_880890EC;
    if (o->owner != 0) {
        int i;
        for (i = 0; i < o->owner->count; i++)
            fn_884B19A0(o, o->owner->slots[i]);
    }
    Elem4Buf_Free(&o->words);
    o->vtable2C = &lbl_88088878;
    o->vtable28 = &lbl_88087B80;
    ts4_destroy_multi2_884B6FF8(o);
}
