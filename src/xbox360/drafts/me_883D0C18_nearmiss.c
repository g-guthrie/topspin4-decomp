typedef struct Link { struct Link *next; } Link;
typedef struct Item { int f0; Link link; } Item;
typedef struct Owner { char pad[0x8060]; Link head; } Owner;
int fn_883D0C18(Owner *o, int idx, Item **out)
{
    Link *n;
    Item *it;
    int i;
    if (!out || idx < 0)
        return 0x25;
    n = o->head.next;
    i = idx;
    while (n != &o->head && i--)
        n = n->next;
    it = (n == &o->head) ? 0 : (n ? (Item *)((char *)n - 4) : 0);
    *out = it;
    return it ? 0 : 0x25;
}
