/* 0x883EDA88: when the list at +0x18 is not empty, passes its first item (link at item+4) to vtable slot 2 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); returns that error, else 0. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Item { int f0; Link link; } Item;
struct T;
typedef struct VT { void *s[2]; int (*process)(struct T *t, Item *it); } VT;
typedef struct T { VT *vt; char pad[0x14]; Link head; } T;
static __inline unsigned char list_empty(const Link *h) { return h->next == h && h->prev == h; }
int ts4_process_first_item_883EDA88(T *t)
{
    if (!list_empty(&t->head)) {
        Link *n = t->head.next;
        int r = t->vt->process(t, n ? (Item *)((char *)n - 4) : 0);
        if (r)
            return r;
    }
    return 0;
}
