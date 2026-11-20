/* 0x884812E0: Destructor body: sets vtable lbl_88087154, drops one reference on each of the three shared objects at +0x40 of every 80-byte entry (deleting through vtable slot 0 at zero when reference-counted), frees the entry array (kind 0x17) unless externally owned, then sets the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). Null test written at the call site with the same element expression passed to the release helper; the second read becomes the clrrwi copy the target has. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);

extern const void *lbl_88087154;
extern const void *lbl_8803A308;
typedef struct Shared {
    void (**vtable)(struct Shared *self, unsigned int flags);
    unsigned short counted;
    short refs;
} Shared;
typedef struct Entry80 { unsigned char head[0x40]; Shared *refs[3]; int tail; } Entry80;
typedef struct Entry80Buf { Entry80 *data; int count; int capFlags; } Entry80Buf;
typedef struct EntrySet { const void *vtable; char pad[0x14]; Entry80Buf entries; } EntrySet;

static void Shared_Release(Shared *s)
{
    if (s->counted != 0 && --s->refs == 0)
        s->vtable[0](s, 1);
}

static void Entry80Buf_Free(Entry80Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Entry80), 0x17);
    }
}

void fn_884812E0(EntrySet *o)
{
    int i, j;
    o->vtable = &lbl_88087154;
    for (i = 0; i < o->entries.count; i++) {
        for (j = 0; j < 3; j++)
            if (o->entries.data[i].refs[j])
                Shared_Release(o->entries.data[i].refs[j]);
    }
    Entry80Buf_Free(&o->entries);
    o->vtable = &lbl_8803A308;
}
