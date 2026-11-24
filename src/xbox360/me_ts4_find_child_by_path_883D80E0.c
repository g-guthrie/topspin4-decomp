/* 0x883D80E0: walks a '/'-separated path down the child lists (+0x28), matching each component by name (883298D8 as strncmp plus terminator check); returns the last matched item or 0 */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Kids { int p0; Link head; } Kids;
typedef struct Item { int vt; Link link; char pad[0x14 - 0xc]; const char *name; char pad2[0x28 - 0x18]; Kids *kids; } Item;
int fn_883298D8(const char *a, const char *b, int n);

#define ITEM(n) ((n) ? (Item *)((char *)(n) - 4) : 0)

Item *fn_883D80E0(Item *t, const char *path)
{
    const char *p;
    Link *n;
    while (path && t->kids) {
        for (p = path; *p; p++)
            if (*p == '/')
                break;
        for (n = t->kids->head.next; ; n = n->next) {
            if (n == (t->kids ? &t->kids->head : 0))
                return 0;
            if (ITEM(n)->name && !fn_883298D8(ITEM(n)->name, path, p - path) && ITEM(n)->name[p - path] == 0)
                break;
        }
        if (!*p)
            return ITEM(n);
        t = ITEM(n);
        path = p + 1;
    }
    return 0;
}
