/* 0x883F2C28: walks the intrusive list at +0xc (link at item+4) calling ts4_list_visit_twice_883FDA60 on each item */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); returns the first nonzero result, else 0. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Item { int f0; Link link; } Item;
typedef struct T { char pad[12]; Link head; } T;
int ts4_list_visit_twice_883FDA60(Item *it);
int ts4_list_visit_883F2C28(T *t)
{
    Link *n;
    for (n = t->head.next; n != &t->head; n = n->next) {
        int r = ts4_list_visit_twice_883FDA60(n ? (Item *)((char *)n - 4) : 0);
        if (r)
            return r;
    }
    return 0;
}
