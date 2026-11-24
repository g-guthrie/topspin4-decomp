/* 0x883FD9A8: over the items on the list at +0x34: returns zeros as soon as one is ready (fn_883E18E8), else the largest 64-bit length from fn_883E1C08 and its companion pointer */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
#ifdef _MSC_VER
typedef unsigned __int64 u64;
#else
typedef unsigned long long u64;
#endif
typedef struct Link { struct Link *next; } Link;
typedef struct Item Item;
typedef struct T { char pad[0x34]; Link head; } T;
int fn_883E18E8(Item *it, unsigned char *ready);
int fn_883E1C08(Item *it, u64 *len, void **which);
int ts4_longest_pending_883FD9A8(T *t, u64 *len, void **which)
{
    u64 best = 0;
    void *best_w = 0;
    Link *n;
    for (n = t->head.next; n != &t->head; n = n->next) {
        Item *it = n ? (Item *)((char *)n - 4) : 0;
        unsigned char ready;
        u64 v;
        void *w;
        int r = fn_883E18E8(it, &ready);
        if (r)
            return r;
        if (ready) {
            *len = 0;
            *which = 0;
            return 0;
        }
        r = fn_883E1C08(it, &v, &w);
        if (r)
            return r;
        if (v > best) {
            best_w = w;
            best = v;
        }
    }
    *len = best;
    *which = best_w;
    return 0;
}
