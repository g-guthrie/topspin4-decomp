/* 0x883F8EC0: skips a leading '/', matches the first path component against the item names on the list at +0x20 (883298D8 as strncmp plus terminator check) and recurses into the rest via 883D80E0; 0 when not found */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Item { int vt; Link link; char pad[0x14 - 0xc]; const char *name; } Item;
typedef struct Group { char pad[0x20]; Link head; } Group;
int fn_883298D8(const char *a, const char *b, int n);
Item *fn_883D80E0(Item *it, const char *path);

#define ITEM(n) ((n) ? (Item *)((char *)(n) - 4) : 0)

Item *fn_883F8EC0(Group *g, const char *path)
{
    const char *s, *p;
    Link *n;
    if (!path)
        return 0;
    s = path + (*path == '/');
    for (p = s; *p; p++)
        if (*p == '/')
            break;
    for (n = g->head.next; n != &g->head; n = n->next) {
        if (ITEM(n)->name && !fn_883298D8(ITEM(n)->name, s, p - s) && ITEM(n)->name[p - s] == 0) {
            if (*p)
                return fn_883D80E0(ITEM(n), p + 1);
            return ITEM(n);
        }
    }
    return 0;
}
