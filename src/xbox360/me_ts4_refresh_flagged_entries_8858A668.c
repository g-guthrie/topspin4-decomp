/* 0x8858A668: for each entry (link at +0x48) of the list at +0x80 whose item has flag 0x10 at +0x35, calls fn_88589748(t, item, 0); returns the first negative result, else 0. */
/* Matched on /O1 (agAB). The next link is read before the call (safe-iteration while loop). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct It { char p[0x35]; unsigned char flags; } It;
typedef struct Ent { It *it; char p4[0x48 - 4]; Link link; } Ent;
typedef struct T { char p[0x80]; Link head; } T;
int fn_88589748(T *t, It *it, int a);
int fn_8858A668(T *t)
{
    Link *l = t->head.next;
    while (l != &t->head) {
        It *it = ((Ent *)((char *)l - 0x48))->it;
        l = l->next;
        if (it->flags & 0x10) {
            int r = fn_88589748(t, it, 0);
            if (r < 0)
                return r;
        }
    }
    return 0;
}
