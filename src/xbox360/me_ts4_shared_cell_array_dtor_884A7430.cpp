/* 0x884A7430: destructor that drops one reference on every shared cell of the array at +0x44 (count +0x48, read once), frees the buffer unless cap (+0x4c) has the top bit set, then chains to fn_8847EFC8. */
/* Matched on /Oc (agAB). Index-first lwzx: test it[i] through a loop-body local it = self->items, then copy it[i] into an element local. */
extern "C" {
extern char lbl_88087F04[];
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
void fn_8847EFC8(void *self);
}
struct Shared {
    virtual void destroy(int flags);
    unsigned short live;
    short refs;
};
struct Obj {
    void *vtbl;
    char pad[0x44 - 4];
    Shared **items;
    int count;
    int cap;
};
extern "C" void fn_884A7430(Obj *self)
{
    int i;
    int cap;
    self->vtbl = lbl_88087F04;
    {
        int n = self->count;
        for (i = 0; i < n; i++) {
            Shared **it = self->items;
            if (it[i]->live != 0) {
                Shared *s = it[i];
                if (--s->refs == 0)
                    s->destroy(1);
            }
        }
    }
    cap = self->cap;
    if ((cap & (int)0x80000000) == 0) {
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, self->items, cap << 2, 0x17);
    }
    fn_8847EFC8(self);
}
