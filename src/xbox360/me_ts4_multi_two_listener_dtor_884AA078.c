/* 0x884AA078: Destructor body of a multi-base object with two listeners (+0x28, +0x2c) in its +0x20 sub-object: sets five vtables, clears both listener slots in every slot of the owner at +0x24 (null-checked base cast per call), frees the word list at +0x30 (kind 0x17), resets both listener vtables and runs ts4_destroy_multi2_884B6FF8. */
/* Matched on /Oc (agAH). Base-cast null checks written as small inline helpers with if/return (a ternary at the call site is if-converted and hoisted). */
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

extern const void *lbl_880888E4;
extern const void *lbl_880888C4;
extern const void *lbl_880888B4;
extern const void *lbl_880888A4;
extern const void *lbl_88088894;
extern const void *lbl_88088878;
extern const void *lbl_8808859C;
typedef struct Slot Slot;
typedef struct Listener { const void *vtable; } Listener;
typedef struct SlotOwner { char pad[0x6c]; Slot **slots; int count; } SlotOwner;
void ts4_clear_pointer_slot_8846AF88(Slot *slot, Listener *l);
void ts4_clear_pointer_slot_8846B168(Slot *slot, Listener *l);
typedef struct Sub20 { const void *vtable; SlotOwner *owner; Listener first; Listener second; } Sub20;
typedef struct MultiObj {
    const void *vtable;
    int unk4;
    const void *vtable8;
    char padC[0x14];
    Sub20 sub;
    Elem4Buf words;
} MultiObj;
void ts4_destroy_multi2_884B6FF8(MultiObj *o);

static __forceinline Listener *FirstOf(Sub20 *p)
{
    MultiObj *o = (MultiObj *)((char *)p - 0x20);
    if (o)
        return &p->first;
    return 0;
}
static __forceinline Listener *SecondOf(Sub20 *p)
{
    MultiObj *o = (MultiObj *)((char *)p - 0x20);
    if (o)
        return &p->second;
    return 0;
}
static __forceinline void ClearSlots(Sub20 *p, Slot *x)
{
    ts4_clear_pointer_slot_8846AF88(x, FirstOf(p));
    ts4_clear_pointer_slot_8846B168(x, SecondOf(p));
}
void fn_884AA078(MultiObj *o)
{
    o->vtable = &lbl_880888E4;
    o->vtable8 = &lbl_880888C4;
    o->sub.vtable = &lbl_880888B4;
    o->sub.first.vtable = &lbl_880888A4;
    o->sub.second.vtable = &lbl_88088894;
    if (o->sub.owner != 0) {
        int i;
        for (i = 0; i < o->sub.owner->count; i++)
            ClearSlots(&o->sub, o->sub.owner->slots[i]);
    }
    Elem4Buf_Free(&o->words);
    o->sub.second.vtable = &lbl_88088878;
    o->sub.first.vtable = &lbl_8808859C;
    ts4_destroy_multi2_884B6FF8(o);
}
