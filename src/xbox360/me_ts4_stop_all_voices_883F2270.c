/* 0x883F2270: for every item of every group, calls 883EF3E8(t, item, 0, 0, 1) on the item itself (flags 2 or 0x10) or on each of its sub-items that has a voice; errors 0x24 and 0x52 are ignored */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Item { int vt; Link link; char pad[0x24 - 0xc]; unsigned int flags; char pad2[0x34 - 0x28]; void *voice; char pad3[0x78 - 0x38]; Link subs; } Item;
typedef struct Group { int vt; Link link; char pad[0x34 - 0xc]; Link items; } Group;
typedef struct T { char pad[0xc]; Link groups; } T;
int fn_883EF3E8(T *t, Item *it, int a, int b, int c);

#define ITEM(n, ty) ((n) ? (ty *)((char *)(n) - 4) : 0)

int fn_883F2270(T *t)
{
    Link *g, *n, *m;
    int r;
    for (g = t->groups.next; g != &t->groups; g = g->next) {
        Group *gp = ITEM(g, Group);
        for (n = gp->items.next; n != &gp->items; n = n->next) {
            Item *it = ITEM(n, Item);
            if ((it->flags & 2) || (it->flags & 0x10)) {
                if (it->voice) {
                    r = fn_883EF3E8(t, it, 0, 0, 1);
                    if (r && r != 0x24 && r != 0x52)
                        return r;
                }
            } else {
                for (m = it->subs.next; m != &it->subs; m = m->next) {
                    Item *s = ITEM(m, Item);
                    if (s->voice) {
                        r = fn_883EF3E8(t, s, 0, 0, 1);
                        if (r && r != 0x24 && r != 0x52)
                            return r;
                    }
                }
            }
        }
    }
    return 0;
}
