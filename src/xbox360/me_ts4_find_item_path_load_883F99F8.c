/* 0x883F99F8: sibling of 883DA1C8 over the embedded list at +0x20: skips a leading '/', matches the first component, forwards the rest to slot 3 or returns the item and optionally loads it (883D9CA0); 0x25 bad args, 0x5B not found */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Kids { int p0; Link head; } Kids;
typedef struct Item Item;
typedef struct ItemVt { void *f[3]; int (*find)(Item *it, const char *path, unsigned char load, Item **out); } ItemVt;
struct Item { ItemVt *vt; Link link; char pad[0x14 - 0xc]; const char *name; };
typedef struct T { char pad[0x20]; Link head; } T;
int fn_883298D8(const char *a, const char *b, int n);
int fn_883D9CA0(Item *it, int a);

#define ITEM(n) ((n) ? (Item *)((char *)(n) - 4) : 0)

int fn_883F99F8(T *t, const char *path, unsigned char load, Item **out)
{
    const char *p, *s;
    Link *n;
    if (!path || !out)
        return 0x25;
    *out = 0;
    s = path;
    if (*path == '/')
        s = path + 1;
    for (p = s; *p; p++)
        if (*p == '/')
            break;
    for (n = t->head.next; n != &t->head; n = n->next) {
        if (ITEM(n)->name && !fn_883298D8(ITEM(n)->name, s, p - s) && ITEM(n)->name[p - s] == 0) {
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
    return 0x5b;25;
}
