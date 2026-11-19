/* 0x883E1C08: climbs +0x54 parents to the root, then returns the largest 64-bit length (fn_883E1A10) among the root and the items on its +0x78 list, with the item that has it; keeps fn_ name (callee of 0x883FD9A8) */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
#ifdef _MSC_VER
typedef unsigned __int64 u64;
#else
typedef unsigned long long u64;
#endif
typedef struct Link { struct Link *next; } Link;
typedef struct Item Item;
struct Item { char pad[0x54]; Item *parent; char pad2[0x20]; Link head; };
int fn_883E1A10(Item *it, u64 *len);
int fn_883E1C08(Item *t, u64 *len, Item **which)
{
    u64 best = 0;
    Item *best_w = 0;
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
    r = fn_883E1A10(root, &v);
    if (r)
        return r;
    if (v > 0) {
        best = v;
        best_w = root;
    }
    for (n = root->head.next; n != &root->head; n = n->next) {
        Item *it = n ? (Item *)((char *)n - 4) : 0;
        r = fn_883E1A10(it, &v);
        if (r)
            return r;
        if (v > best) {
            best = v;
            best_w = it;
        }
    }
    *len = best;
    *which = best_w;
    return 0;
}
