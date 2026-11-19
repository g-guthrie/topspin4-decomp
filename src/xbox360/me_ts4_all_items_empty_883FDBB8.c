/* 0x883FDBB8: returns 1 when ts4_chk_empty_883E1890 passes for every item (link at +4) of the list at +0x34, else 0. */
/* Matched on /O1 (agAB). unsigned char all = 1 with break on the first failure; for loop over the links. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Item Item;
typedef struct T { char p[0x34]; Link head; } T;
unsigned char ts4_chk_empty_883E1890(Item *it);
unsigned char fn_883FDBB8(T *t)
{
    Link *l;
    unsigned char all = 1;
    for (l = t->head.next; l != &t->head; l = l->next) {
        if (!ts4_chk_empty_883E1890(l ? (Item *)((char *)l - 4) : 0)) {
            all = 0;
            break;
        }
    }
    return all;
}
