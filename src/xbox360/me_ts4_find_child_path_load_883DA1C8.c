/* 0x883DA1C8: sibling of 883DF370 for the list at +0x28: matches the first path component, forwards the rest to the child's slot 3, or returns the child and optionally loads it (883D9CA0(child, 0)); 0x25 on bad args or not found */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Kids { int p0; Link head; } Kids;
typedef struct Item Item;
typedef struct ItemVt { void *f[3]; int (*find)(Item *it, const char *path, unsigned char load, Item **out); } ItemVt;
struct Item { ItemVt *vt; Link link; char pad[0x14 - 0xc]; const char *name; };
typedef struct T { char pad[0x28]; Kids *kids; } T;
int fn_883298D8(const char *a, const char *b, int n);
int fn_883D9CA0(Item *it, int a);

#define ITEM(n) ((n) ? (Item *)((char *)(n) - 4) : 0)

int fn_883DA1C8(T *t, const char *path, unsigned char load, Item **out)
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
                return it->vt->find(it, p + 1, load, out);
            }
            *out = ITEM(n);
            if (load) {
                int r = fn_883D9CA0(ITEM(n), 0);
                if (r)
                    return r;
            }
            return 0;
        }
    }
    return 0x25;
}
