/* Swing_DLL.xex 0x883D2348: returns in *out the item at position index of the manager list (+0x8084, node at item+4);
 * 0x1f when not ready (+0x809C), 0x25 when the list is empty or index is out of range. agAE: /O1. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Item { void *vt; Link link; } Item;
typedef struct Mgr { char pad[0x8084]; Link items; char pad808c[0x809c - 0x808c]; void *ready; } Mgr;
#define LINK_ITEM(l) ((l) ? (Item *)((char *)(l) - 4) : 0)
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
int fn_883D2348(Mgr *m, int index, Item **out)
{
    Link *l;
    int n;
    if (!m->ready) return 0x1f;
    if (out) {
        n = 0;
        for (l = m->items.next; l != &m->items; l = l->next) n++;
        if (n) {
            *out = list_at(&m->items, index);
            return *out ? 0 : 0x25;
        }
    }
    return 0x25;
}
