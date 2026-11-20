/* 0x883F2730: calls fn_883F2590(t, item) for every item (link at +4) of the intrusive list headed by head. */
/* Matched on /O1 (agAB). Plain for loop over the links with the null-guarded container conversion. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Item Item;
void fn_883F2590(void *t, Item *it);
void fn_883F2730(void *t, Link *head)
{
    Link *l;
    for (l = head->next; l != head; l = l->next)
        fn_883F2590(t, l ? (Item *)((char *)l - 4) : 0);
}
