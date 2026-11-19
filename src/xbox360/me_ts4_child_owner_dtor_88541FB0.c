/* 0x88541FB0: Destructor body: sets vtable lbl_8808E724, calls the virtual deleting destructor (slot 0, flag 1) of the child at +0x3c if any, frees the 112-byte-element array at +0x30 (kind 0x17) unless externally owned, then runs the base destructor ts4_addr_lbl_8803A308_884834E0. */
/* Matched on /Oc (agAH). C virtual call through vtable slot 0; typed per-buffer free helper (mulli 0x70). */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);

typedef struct Deletable { void (**vtable)(struct Deletable *self, unsigned int flags); } Deletable;
typedef struct Elem112 { unsigned char b[112]; } Elem112;
typedef struct Elem112Buf { Elem112 *data; int count; int capFlags; } Elem112Buf;
extern const void *lbl_8808E724;
typedef struct ChildOwner { const void *vtable; char pad[0x2c]; Elem112Buf items; Deletable *child; } ChildOwner;
void ts4_addr_lbl_8803A308_884834E0(ChildOwner *o);

static void Elem112Buf_Free(Elem112Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem112), 0x17);
    }
}

void fn_88541FB0(ChildOwner *o)
{
    o->vtable = &lbl_8808E724;
    if (o->child)
        o->child->vtable[0](o->child, 1);
    Elem112Buf_Free(&o->items);
    ts4_addr_lbl_8803A308_884834E0(o);
}
