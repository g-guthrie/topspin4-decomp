/* 0x883D81F8: returns 0x25 when the child key (fn_883C6740) already resolves to this owner through fn_883D7F20 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); else appends the child link (+8) at the tail of the list at +0x34. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct N { int f0, f4; Link link; } N;
typedef struct T { char pad[0x34]; Link head; } T;
void *fn_883C6740(N *n);
int fn_883D7F20(T *t, void *key, void **found, T **owner);
int ts4_attach_child_883D81F8(T *t, N *n)
{
    if (fn_883C6740(n)) {
        void *found;
        T *owner;
        if (fn_883D7F20(t, fn_883C6740(n), &found, &owner) == 0 && owner == t)
            return 0x25;
    }
    {
        Link *h = &t->head;
        Link *prev = h->prev;
        n->link.next = h;
        n->link.prev = prev;
        h->prev = &n->link;
        n->link.prev->next = &n->link;
    }
    return 0;
}
