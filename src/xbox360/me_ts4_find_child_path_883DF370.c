/* 0x883DF370: matches the first path component against the child names of the list at +0x48 (883298D8 as strncmp plus terminator) and either returns the child or forwards the rest of the path to its slot 1; 0x25 bad args, 0x5B not found */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Kids { int p0; Link head; } Kids;
typedef struct Item Item;
typedef struct ItemVt { void *f0; int (*find)(Item *it, const char *path, Item **out); } ItemVt;
struct Item { ItemVt *vt; Link link; char pad[0x14 - 0xc]; const char *name; };
typedef struct T { char pad[0x48]; Kids *kids; } T;
int fn_883298D8(const char *a, const char *b, int n);

#define ITEM(n) ((n) ? (Item *)((char *)(n) - 4) : 0)

int fn_883DF370(T *t, const char *path, Item **out)
{
    const char *p;
    Link *n;
    if (!path || !out || !t->kids)
        return 0x25;
    *out = 0;
    for (p = path; *p; p++)
        if (*p == '/')
            break;
    for (n = t->kids->head.next; n != (t->kids ? &t->kids->head : 0); n = n->next) {
        if (ITEM(n)->name && !fn_883298D8(ITEM(n)->name, path, p - path) && ITEM(n)->name[p - path] == 0) {
            if (*p) {
                Item *it = ITEM(n);
                return it->vt->find(it, p + 1, out);
            }
            *out = ITEM(n);
            return 0;
        }
    }
    return 0x5b;
}
