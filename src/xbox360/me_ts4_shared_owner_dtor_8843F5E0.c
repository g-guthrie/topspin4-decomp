/* 0x8843F5E0: Destructor body: sets vtable lbl_880804FC, drops one reference on the shared object at +0x5c when it is reference-counted (u16 at +4) and deletes it through vtable slot 0 at zero, frees the 16-byte array at +0x50 and the 48-byte array at +0x40 (kind 0x17, each skipped if externally owned), then sets the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). Shared pointer read into a local before the vtable store; one && chain with the pre-decrement; per-buffer free helpers. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Elem48 { unsigned char b[48]; } Elem48;
typedef struct Elem48Buf { Elem48 *data; int count; int capFlags; } Elem48Buf;

static void Elem48Buf_Free(Elem48Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem48), 0x17);
    }
}
typedef struct Elem16 { unsigned char b[16]; } Elem16;
typedef struct Elem16Buf { Elem16 *data; int count; int capFlags; } Elem16Buf;

static void Elem16Buf_Free(Elem16Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem16), 0x17);
    }
}

extern const void *lbl_880804FC;
extern const void *lbl_8803A308;
typedef struct Shared {
    void (**vtable)(struct Shared *self, unsigned int flags);
    unsigned short counted;
    short refs;
} Shared;
typedef struct SharedOwner {
    const void *vtable;
    char pad[0x3c];
    Elem48Buf big;
    int unk4C;
    Elem16Buf small;
    Shared *shared;
} SharedOwner;

void fn_8843F5E0(SharedOwner *o)
{
    Shared *s = o->shared;
    o->vtable = &lbl_880804FC;
    if (s != 0 && s->counted != 0 && --s->refs == 0)
        s->vtable[0](s, 1);
    Elem16Buf_Free(&o->small);
    Elem48Buf_Free(&o->big);
    o->vtable = &lbl_8803A308;
}
