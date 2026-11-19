/* 0x883D28E8: sibling of 883D27E8: splits the path at its first '/', finds the child named by the prefix and forwards the rest to its slot 5; 0x1F not ready, 0x25 bad args, 0x5B not found */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Item Item;
typedef struct ItemVt { void *f[5]; int (*open)(Item *it, const char *rest, void *a, void *out); } ItemVt;
struct Item { ItemVt *vt; Link link; char pad[0x14 - 0xc]; const char *name; };
typedef struct Sys { char pad[0x8084]; Link head; char pad2[0x809c - 0x808c]; void *ready; } Sys;
int ts4_strlen_88329658(const char *s);
int fn_883298D8(const char *a, const char *b, int n);

int fn_883D28E8(Sys *s, const char *path, void *a, void *out)
{
    const char *p;
    Link *n;
    if (!s->ready)
        return 0x1f;
    if (!path || !out)
        return 0x25;
    for (p = path; *p; p++)
        if (*p == '/')
            break;
    if (!*p)
        return 0x25;
    for (n = s->head.next; n != &s->head; n = n->next) {
        Item *it = n ? (Item *)((char *)n - 4) : 0;
        if (it->name) {
            int len = p - path;
            if (ts4_strlen_88329658(it->name) == len && !fn_883298D8(it->name, path, len))
                return it->vt->open(it, p, a, out);
        }
    }
    return 0x5b;
}
