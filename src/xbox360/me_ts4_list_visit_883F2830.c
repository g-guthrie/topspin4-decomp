/* 0x883F2830: walks the intrusive list at +0x18 (link at item+4) calling fn_883CF1A0 on each item */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); returns the first nonzero result, else 0. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Item { int f0; Link link; } Item;
typedef struct T { char pad[24]; Link head; } T;
int fn_883CF1A0(Item *it);
int ts4_list_visit_883F2830(T *t)
{
    Link *n;
    for (n = t->head.next; n != &t->head; n = n->next) {
        int r = fn_883CF1A0(n ? (Item *)((char *)n - 4) : 0);
        if (r)
            return r;
    }
    return 0;
}
