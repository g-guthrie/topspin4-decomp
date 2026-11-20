/* 0x883D0AD0: walks the list at +0x8048; each item whose +0x58 key matches is unlinked (self-linked, +0x10 cleared) and passed to fn_883DE028(item, key->f7c, 0); returns the first error */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Key { char pad[0x7c]; void *f7c; } Key;
typedef struct Item { int f0, f4; Link link; int f10; char pad[0x44]; Key *key; } Item;
typedef struct Owner { char pad[0x8048]; Link head; } Owner;
int fn_883DE028(Item *it, void *v, int a);
int ts4_detach_items_for_key_883D0AD0(Owner *o, Key *key)
{
    Link *n = o->head.next;
    int r;
    while (n != &o->head) {
        Item *it = n ? (Item *)((char *)n - 8) : 0;
        n = n->next;
        if (it->key == key) {
            it->link.prev->next = it->link.next;
            it->link.next->prev = it->link.prev;
            it->link.prev = &it->link;
            it->link.next = &it->link;
            it->f10 = 0;
            r = fn_883DE028(it, key->f7c, 0);
            if (r)
                return r;
        }
    }
    return 0;
}
