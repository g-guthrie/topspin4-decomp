/* 0x883F0208: walks the list at +0xC (link at item+4), binding each item to the owner resource context (+4->+0xAC->+0x18) */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); sets owner flag 8 when an item reports mask 0x80; returns the first bind error. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Item { int f0; Link link; } Item;
typedef struct Res { char pad[0x18]; void *ctx; } Res;
typedef struct Own { char pad[0x60]; unsigned flags; char pad2[0xac - 0x64]; Res *res; } Own;
typedef struct T { int f0; Own *own; int f8; Link head; } T;
int fn_883FDC50(Item *it, void *ctx);
void *fn_883FDC10(Item *it, int mask);
int ts4_list_bind_items_883F0208(T *t)
{
    Link *n;
    for (n = t->head.next; n != &t->head; n = n->next) {
        Item *it = n ? (Item *)((char *)n - 4) : 0;
        int r = fn_883FDC50(it, t->own->res ? t->own->res->ctx : 0);
        if (r)
            return r;
        if (fn_883FDC10(it, 0x80))
            t->own->flags |= 8;
    }
    return 0;
}
