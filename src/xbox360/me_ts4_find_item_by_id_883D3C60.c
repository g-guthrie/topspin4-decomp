/* Swing_DLL.xex 0x883D3C60: finds the item (list at +0x8084, node at item+4) whose id (+0x78) equals id;
 * 0x1f when the manager is not ready (+0x809C), 0x25 when absent. agAE: /O1. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Item { void *vt; Link link; char padc[0x78 - 0xc]; unsigned int id; } Item;
typedef struct Mgr { char pad[0x8084]; Link items; char pad808c[0x809c - 0x808c]; void *ready; } Mgr;
#define LINK_ITEM(l) ((l) ? (Item *)((char *)(l) - 4) : 0)
int fn_883D3C60(Mgr *m, unsigned int id, Item **out)
{
    Link *l;
    int n;
    if (!m->ready) return 0x1f;
    if (out) {
        n = 0;
        for (l = m->items.next; l != &m->items; l = l->next) n++;
        if (n) {
            *out = 0;
            for (l = m->items.next; l != &m->items; l = l->next) {
                if (LINK_ITEM(l)->id == id) {
                    *out = LINK_ITEM(l);
                    return 0;
                }
            }
        }
    }
    return 0x25;
}
