/* 0x883E2ED0: climbs +0x54 parents to the root and returns in *which the root or +0x78-list item with the smallest non-zero 64-bit value from ts4_query_pair_883E1980 (first one wins ties) */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
#ifdef _MSC_VER
typedef unsigned __int64 u64;
#else
typedef unsigned long long u64;
#endif
typedef struct Link { struct Link *next; } Link;
typedef struct Item Item;
struct Item { char pad[0x54]; Item *parent; char pad2[0x20]; Link head; };
int ts4_query_pair_883E1980(Item *it, u64 *out);
int ts4_smallest_pending_in_tree_883E2ED0(Item *t, Item **which)
{
    Item *best_w = 0;
    u64 best = 0;
    Item *root;
    Link *n;
    u64 v;
    int r;
    if (!t->parent) {
        root = t;
    } else {
        Item *p = t->parent;
        Item *q = p->parent;
        while (q) {
            p = q;
            q = q->parent;
        }
        root = p;
    }
    r = ts4_query_pair_883E1980(root, &v);
    if (r)
        return r;
    if (v != 0) {
        best_w = root;
        best = v;
    }
    for (n = root->head.next; n != &root->head; n = n->next) {
        Item *it = n ? (Item *)((char *)n - 4) : 0;
        r = ts4_query_pair_883E1980(it, &v);
        if (r)
            return r;
        if (v != 0 && (v < best || !best_w)) {
            best_w = it;
            best = v;
        }
    }
    *which = best_w;
    return 0;
}
