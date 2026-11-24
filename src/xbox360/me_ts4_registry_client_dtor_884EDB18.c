/* 0x884EDB18: Destructor body: sets vtables lbl_8808D5B4/+0 and lbl_8808D594/+8; when attached to the registry at +0x2c, unregisters every key of its key list (fn_884ED968), calls fn_884E0300(registry, ts4_dispatch_by_flag_884EDA30) and drops one registry reference (slot-0 delete at zero); then frees the 8-byte array at +0x20 (kind 0x17) unless externally owned and sets vtables lbl_88089504/+8 and lbl_8803A308/+0. */
/* Matched on /Oc (agAH). Key list addressed through a local pointer to the embedded {entries, count} struct; registry re-read through the object after the callback call. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Elem8 { unsigned char b[8]; } Elem8;
typedef struct Elem8Buf { Elem8 *data; int count; int capFlags; } Elem8Buf;

static void Elem8Buf_Free(Elem8Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem8), 0x17);
    }
}

extern const void *lbl_8808D5B4;
extern const void *lbl_8808D594;
extern const void *lbl_88089504;
extern const void *lbl_8803A308;
typedef struct KeyEntry { int key; int value; } KeyEntry;
typedef struct KeyList { KeyEntry *entries; int count; } KeyList;
typedef struct Registry {
    void (**vtable)(struct Registry *self, unsigned int flags);
    unsigned short counted;
    short refs;
    char pad8[0x1c];
    KeyList keys;
} Registry;
struct Client;
void ts4_dispatch_by_flag_884EDA30(void);
void fn_884ED968(struct Client *c, int key);
void fn_884E0300(Registry *r, void (*fn)(void));
typedef struct Client {
    const void *vtable;
    int unk4;
    const void *vtable8;
    char padC[0x14];
    Elem8Buf items;
    Registry *registry;
} Client;

void fn_884EDB18(Client *c)
{
    c->vtable = &lbl_8808D5B4;
    c->vtable8 = &lbl_8808D594;
    if (c->registry != 0) {
        KeyList *keys = &c->registry->keys;
        Registry *r;
        int i;
        for (i = 0; i < keys->count; i++)
            fn_884ED968(c, keys->entries[i].key);
        fn_884E0300(c->registry, ts4_dispatch_by_flag_884EDA30);
        r = c->registry;
        if (r->counted != 0 && --r->refs == 0)
            r->vtable[0](r, 1);
    }
    Elem8Buf_Free(&c->items);
    c->vtable8 = &lbl_88089504;
    c->vtable = &lbl_8803A308;
}
