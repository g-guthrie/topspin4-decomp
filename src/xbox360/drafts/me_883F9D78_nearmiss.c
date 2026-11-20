/* 0x883F9D78: for item i (< count at +0x2C, array +0x34) forwards (item, a, flags) to fn_883D38C8 with the manager lbl_88CAC988 when flag 4 is set, else to fn_883DA438 with the item's handle (+0x28); 0x25 when a is null or i is out of range. */
/* Near miss (agAB, /O1): 1 off, lwzx base/index order (target index first). A base local, a slot helper, an element helper and i[a] all stay base first. */
typedef struct Item { char p[0x28]; void *h; } Item;
typedef struct T { char p[0x2c]; unsigned int n; char p30[4]; Item **items; } T;
extern void *lbl_88CAC988;
int fn_883D38C8(void *mgr, Item *it, void *a, unsigned int flags, int z);
int fn_883DA438(void *h, Item *it, void *a, unsigned int flags);
int fn_883F9D78(T *t, unsigned int i, unsigned int flags, void *a)
{
    Item *it;
    if (!a || i >= t->n)
        return 0x25;
    it = t->items[i];
    if (flags & 4)
        return fn_883D38C8(lbl_88CAC988, it, a, flags, 0);
    return fn_883DA438(it->h, it, a, flags);
}
