/* 0x883FDA60: when flag 2 (+0x18) is set, runs fn_883E1E78 then fn_883E1DD0 over every item of the list at +0x34 (link at item+4) */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); returns the first nonzero result, else 0. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Item { int f0; Link link; } Item;
typedef struct T { char pad[0x18]; unsigned flags; char pad2[0x34 - 0x1c]; Link head; } T;
int fn_883E1E78(Item *it);
int fn_883E1DD0(Item *it);
int ts4_list_visit_twice_883FDA60(T *t)
{
    if (t->flags & 2) {
        Link *n;
        int r;
        for (n = t->head.next; n != &t->head; n = n->next) {
            r = fn_883E1E78(n ? (Item *)((char *)n - 4) : 0);
            if (r)
                return r;
        }
        for (n = t->head.next; n != &t->head; n = n->next) {
            r = fn_883E1DD0(n ? (Item *)((char *)n - 4) : 0);
            if (r)
                return r;
        }
    }
    return 0;
}
