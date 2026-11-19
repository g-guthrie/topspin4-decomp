/* 0x88423E28: Rehashes an int map (keys then values in one block): allocates 2*newCap words (kind 0x17), marks newCap key slots empty (-1), sets last = newCap - 1 and flags 0, reinserts each old key/value pair through fn_88423660, then frees the old block unless it was externally owned. */
/* Near miss (agAH): /Oc, 3 instructions off: the fill store is stwx r10, r9, r11 where the target has stwx r10, r11, r9 (same open issue as 88423C28), and cmpwi oldCap is scheduled one store later. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
void *fn_8841A510(void *allocator, unsigned int size, int kind);
typedef struct IntMap { int *slots; int flags; int last; } IntMap;
void fn_88423660(IntMap *m, int key, int value);

void fn_88423E28(IntMap *m, int newCap)
{
    int *old = m->slots;
    int external = m->flags & 0x80000000;
    int oldCap = m->last + 1;
    int i;
    void *alloc = KeTlsGetValue(lbl_88CACF08);
    m->slots = (int *)fn_8841A510(alloc, newCap * 2 * sizeof(int), 0x17);
    for (i = 0; i < newCap; i++)
        m->slots[i] = -1;
    m->last = newCap - 1;
    m->flags = 0;
    for (i = 0; i < oldCap; i++) {
        if (old[i] != -1)
            fn_88423660(m, old[i], old[oldCap + i]);
    }
    if (external == 0) {
        void *alloc2 = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc2, old, oldCap * 2 * sizeof(int), 0x17);
    }
}
