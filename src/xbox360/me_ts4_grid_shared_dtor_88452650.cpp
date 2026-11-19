/* Swing_DLL.xex 0x88452650: destructor releasing an 8x8 grid of ref-counted cells and a buffer */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b139. */
extern "C" {
extern char lbl_8808233C[];
extern char lbl_8803A308[];
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
void ts4_if_call_seq_u32_off1e30_88451E90(void *self);
}
struct Shared {
    virtual void destroy(int flags);
    unsigned short live;
    short refs;
};
struct Obj {
    void *vtbl;
    int pad[2];
    Shared *grid[8][8];
    char pad2[0x1e24 - 0x10c];
    void *items;
    int count;
    int cap;
};
/* Destructor: releases the 8x8 grid of ref-counted cells, frees the 8-byte-element buffer at +0x1e24. */
extern "C" void fn_88452650(Obj *self)
{
    int i, j;
    int cap;
    self->vtbl = lbl_8808233C;
    ts4_if_call_seq_u32_off1e30_88451E90(self);
    for (i = 0; i < 8; ++i) {
        for (j = 0; j < 8; ++j) {
            Shared *p = self->grid[i][j];
            if (p && p->live != 0) {
                if (--p->refs == 0)
                    p->destroy(1);
            }
        }
    }
    cap = self->cap;
    if ((cap & (int)0x80000000) == 0)
    {
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, self->items, cap << 3, 0x17);
    }
    self->vtbl = lbl_8803A308;
}
