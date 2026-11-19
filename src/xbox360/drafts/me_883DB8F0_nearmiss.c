typedef struct Item { char pad[0x64]; unsigned short flags; } Item;
typedef struct Pool { int f0, f4; unsigned int count; unsigned int cur; Item **items; } Pool;
typedef struct Src { char pad[0x28]; void *owner; } Src;
int fn_883D8AD8(void *owner, Src *src, Item **out, int a);
int fn_883DB8F0(Pool *p, Src *src, Item **out)
{
    Item *it = 0;
    unsigned int idx = p->cur;
    unsigned int i;
    int r;
    if (p->count) {
        unsigned int n = p->count;
        Item **items = p->items;
        for (i = 0; i < p->count; i++) {
            idx = (idx + 1 < n) ? idx + 1 : 0;
            if (!(items[idx]->flags & 0x80)) {
                it = items[idx];
                break;
            }
        }
    }
    if (!it) {
        r = fn_883D8AD8(src->owner, src, &it, 1);
        if (r)
            return r;
    }
    p->cur = idx;
    *out = it;
    return 0;
}
