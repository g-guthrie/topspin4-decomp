/* Swing_DLL.xex 0x883DA348: returns in *out the item at position index of the group's item list (+0x28 -> list at +4), optionally
 * activating it with fn_883D9CA0(item, 0); 0x25 on a null out or a missing item. agAE: /O1. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Item { void *vt; Link link; } Item;
typedef struct ItemList { void *vt; Link items; } ItemList;
typedef struct Group { char pad[0x28]; ItemList *list; } Group;
int fn_883D9CA0(Item *it, int flags);
static __inline Item *list_at(Link *head, int index)
{
    Link *l;
    if (index < 0) return 0;
    l = head->next;
    if (l == head) return 0;
    for (; index > 0; index--) {
        l = l->next;
        if (l == head) return 0;
    }
    if (l) return (Item *)((char *)l - 4);
    return 0;
}
int fn_883DA348(Group *g, int index, unsigned char activate, Item **out)
{
    Link *l;
    int n, hr;
    if (!out) return 0x25;
    *out = 0;
    if (g->list) {
    n = 0;
    for (l = g->list->items.next; l != &g->list->items; l = l->next) n++;
    if (n) {
        *out = list_at(&g->list->items, index);
        if (*out && activate) {
            hr = fn_883D9CA0(*out, 0);
            if (hr) return hr;
        }
    }
    }
    return *out ? 0 : 0x25;
}
