/* Swing_DLL.xex 0x883D3D10: allocates the next free 7-bit item id after lastId (+0x80C8), wrapping 0x7F -> 0, skipping ids in use
 * by listed items (+0x78); 0x1f not ready, 0x25 null out, 0x57 after 0x7F tries. agAE: /O1. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Item { void *vt; Link link; char padc[0x78 - 0xc]; unsigned int id; } Item;
typedef struct Mgr { char pad[0x8084]; Link items; char pad808c[0x809c - 0x808c]; void *ready; char pad80a0[0x80c8 - 0x80a0]; unsigned int lastId; } Mgr;
#define LINK_ITEM(l) ((l) ? (Item *)((char *)(l) - 4) : 0)
int fn_883D3D10(Mgr *m, unsigned int *out)
{
    unsigned int id, tries;
    Link *l;
    if (!m->ready) return 0x1f;
    if (!out) return 0x25;
    id = m->lastId;
    for (tries = 0; tries < 0x7f; tries++) {
        id++;
        if (id > 0x7f) id = 0;
        for (l = m->items.next; l != &m->items; l = l->next)
            if (LINK_ITEM(l)->id == id) break;
        if (l == &m->items) break;
    }
    if (tries >= 0x7f) return 0x57;
    m->lastId = id;
    *out = id;
    return 0;
}
