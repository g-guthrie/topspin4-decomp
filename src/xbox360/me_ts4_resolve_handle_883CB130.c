/* 0x883CB130: decodes a node handle: high bit set = group id/slot/gen via 883D3C60 and 883DBB68; otherwise table index/sub-slot/gen into lbl_88CAC988's node table (sub == count selects the node itself); checks the generation and returns 0x24 on any mismatch. The items null test is signed (PTR_INT); the top-bit test needs a (unsigned char) cast to give srwi. */
/* Matched on /O1 plain only (agV, v.py chk). */
#ifdef _MSC_VER
#define PTR_INT(p) ((int)(p))
#else
#define PTR_INT(p) ((int)(long)(p))
#endif
typedef struct Node Node;
typedef struct Gen { char pad[0x10]; unsigned int gen; } Gen;
typedef struct List { int count; Node **items; } List;
struct Node { char pad[0xa8]; List *list; Gen *g; };
typedef struct Grp { char pad[0x38]; void *tab; } Grp;
typedef struct Sys { char pad[0x3c]; unsigned int count; char pad2[0x44 - 0x40]; Node *nodes[1]; } Sys;
extern Sys *lbl_88CAC988;
int fn_883D3C60(Sys *s, unsigned int id, Grp **out);
int ts4_if_get_u32_off10_883DBB68(void *tab, unsigned int id, Node **out);

int fn_883CB130(unsigned int h, Node **out)
{
    Node *n = 0;
    unsigned char direct;
    unsigned int gen;
    int r;
    if (!h)
        return 0x24;
    direct = 0;
    if ((unsigned char)(h >> 31)) {
        Grp *g = 0;
        gen = h & 0xfff;
        if (fn_883D3C60(lbl_88CAC988, (h >> 24) & 0x7f, &g))
            return 0x24;
        if (g) {
            r = ts4_if_get_u32_off10_883DBB68(g->tab, (h >> 12) & 0xfff, &n);
            if (r)
                return r;
        }
    } else {
        unsigned int idx = (h >> 18) & 0x1fff;
        int sub = (h >> 11) & 0x7f;
        gen = h & 0x7ff;
        if (idx >= lbl_88CAC988->count)
            return 0x24;
        if (!lbl_88CAC988->nodes[idx])
            return 0x24;
        direct = sub == lbl_88CAC988->nodes[idx]->list->count;
        if (direct)
            n = lbl_88CAC988->nodes[idx];
        else {
            if (sub >= lbl_88CAC988->nodes[idx]->list->count)
                return 0x24;
            if (PTR_INT(lbl_88CAC988->nodes[idx]->list->items) == 0)
                return 0x24;
            n = lbl_88CAC988->nodes[idx]->list->items[sub];
        }
    }
    if (!n)
        return 0x24;
    if (!direct && (n->g ? n->g->gen : 0) != gen)
        return 0x24;
    *out = n;
    return 0;
}
