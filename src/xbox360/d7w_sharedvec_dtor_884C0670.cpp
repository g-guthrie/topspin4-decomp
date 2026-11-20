/* Swing_DLL.xex 0x884C0670-0x884C0734, executable version 0.0.0.3. */
/* Destructor of a vector of intrusively ref-counted objects: release every
   element, then return the backing store to the thread-local allocator. */
extern "C" {
extern char lbl_880898EC[];
extern char lbl_8803A308[];
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
}
struct Shared {
    virtual void destroy(int flags);
    unsigned short live;
    short refs;
};
struct SharedVec {
    void *vtbl;
    char pad[0xc];
    Shared **items;
    int count;
    int cap;
};
/* Swing_DLL.xex 0x884C0670 */
extern "C" void ts4_sharedvec_dtor_884C0670(SharedVec *self)
{
    int i;
    int cap;
    self->vtbl = lbl_880898EC;
    for (i = 0; i < self->count; ++i) {
        Shared *p = self->items[i];
        if (p->live != 0) {
            if (--p->refs == 0)
                p->destroy(1);
        }
    }
    cap = self->cap;
    if ((cap & (int)0x80000000) == 0)
    {
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, self->items, cap << 2, 0x17);
    }
    self->vtbl = lbl_8803A308;
}
