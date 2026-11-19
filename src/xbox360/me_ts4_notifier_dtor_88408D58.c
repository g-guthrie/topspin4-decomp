/* 0x88408D58: Destructor body: sets vtable lbl_8803BD20, calls slot 0 of every observer in the list at +0x2c with this notifier, frees the observer list and the byte arrays at +0x1c and +0x10 (kind 0x17, each skipped if externally owned), then sets the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). Write the element expression twice in the virtual call (n->observers.items[i]->vtable[0](n->observers.items[i], n)); a local gives lwzx (base, index) instead of (index, base). */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Elem1 { unsigned char b[1]; } Elem1;
typedef struct Elem1Buf { Elem1 *data; int count; int capFlags; } Elem1Buf;

static void Elem1Buf_Free(Elem1Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem1), 0x17);
    }
}

extern const void *lbl_8803BD20;
extern const void *lbl_8803A308;
struct Notifier;
typedef struct Observer { void (**vtable)(struct Observer *self, struct Notifier *from); } Observer;
typedef struct ObserverList { Observer **items; int count; int capFlags; } ObserverList;
typedef struct Notifier {
    const void *vtable;
    char pad[0xc];
    Elem1Buf first;
    Elem1Buf second;
    char pad28[4];
    ObserverList observers;
} Notifier;

static void ObserverList_Free(ObserverList *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->items, cap * sizeof(Observer *), 0x17);
    }
}

void fn_88408D58(Notifier *n)
{
    int i;
    n->vtable = &lbl_8803BD20;
    for (i = 0; i < n->observers.count; i++) {
        n->observers.items[i]->vtable[0](n->observers.items[i], n);
    }
    ObserverList_Free(&n->observers);
    Elem1Buf_Free(&n->second);
    Elem1Buf_Free(&n->first);
    n->vtable = &lbl_8803A308;
}
