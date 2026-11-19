/* NEAR MISS (agAD, b169): /O1, ~97 off: logic right; differs in callee-saved register assignment (target: it r31, cursor r30, head r29, q r28),
 * the empty-queue insert tail-merged into the shared one, and fn_883ED740's out slot (target 0x54). */
/* Swing_DLL.xex 0x883ED860: queues an item: unless forced, returns early when an item with the same id (slot 1) is already queued;
 * an exclusive item (flag 2, prepared through slot 3) goes into an empty queue or after the one fn_883ED740 picks (marked
 * with flag 4); otherwise it is inserted before the first unlocked item of lower priority (+0x21), or at the tail. agAD: /O1. */
typedef struct Link { struct Link *next, *prev; } Link;
typedef struct Item { const struct ItemVt *vt; Link link; char pad0c[0x20 - 0xc]; unsigned char flags; unsigned char prio; } Item;
typedef struct ItemVt { void *s0; int (*id)(Item *it, unsigned int *id); void *s2; int (*prepare)(Item *it, int mode); } ItemVt;
typedef struct Queue { char pad0[0x18]; Link items; } Queue;
int fn_883ED740(Queue *q, Item **out);

static __inline Item *item_of(Link *l) { return l ? (Item *)((char *)l - 4) : 0; }
static __inline unsigned char list_empty(Link *h) { return h->next == h && h->prev == h; }
static __inline void insert_before(Link *pos, Link *n)
{
    n->next = pos;
    n->prev = pos->prev;
    pos->prev = n;
    n->prev->next = n;
}
static __inline void insert_after(Link *pos, Link *n)
{
    n->next = pos->next;
    n->prev = pos;
    n->next->prev = n;
    n->prev->next = n;
}

int fn_883ED860(Queue *q, Item *it, unsigned char force)
{
    Link *l;
    int r;
    if (!force) {
        for (l = q->items.next; l != &q->items; l = l->next) {
            unsigned int a, b;
            Item *o;
            r = it->vt->id(it, &a);
            if (r)
                return r;
            o = l ? (Item *)((char *)l - 4) : 0;
            r = o->vt->id(o, &b);
            if (r)
                return r;
            if (a == b)
                return 0;
        }
    }
    if (it->flags & 2) {
        Item *o;
        r = it->vt->prepare(it, 0xff);
        if (r)
            return r;
        if (list_empty(&q->items)) {
            insert_before(&q->items, &it->link);
            return 0;
        }
        r = fn_883ED740(q, &o);
        if (r)
            return r;
        insert_after(o ? &o->link : 0, &it->link);
        o->flags |= 4;
    } else {
        unsigned char done = 0;
        for (l = q->items.next; l != &q->items; l = l->next) {
            Item *o = l ? (Item *)((char *)l - 4) : 0;
            if (o->prio < it->prio && !(o->flags & 1)) {
                insert_before(l, &it->link);
                done = 1;
                break;
            }
        }
        if (!done)
            insert_before(&q->items, &it->link);
    }
    return 0;
}
