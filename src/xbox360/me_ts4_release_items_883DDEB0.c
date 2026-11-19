/* 0x883DDEB0: n == -1 releases every item in the list at +0x2C (883DBEF8 with 1) and clears the count at +0x48; otherwise, n times, releases the first non-busy (+0x11) item when 0 < count <= max (+0x50) and decrements the count, clamped at 0; 883DD108 on a pointer to self first. Keeps an empty list walk when no item was released */
/* Matched on /O1 plain and LTCG (agX, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Set { int p0; Link head; } Set;
typedef struct Item { int vt; Link link; char pad[0x11 - 0xc]; unsigned char busy; } Item;
typedef struct T { char pad[0x2c]; Set set; char pad2[0x48 - 0x38]; int count; int p4c; int max; } T;
void fn_883DD108(T **t, int a);
int fn_883DBEF8(Item *it, unsigned char a);
#define HEAD(t) (&(t)->set ? &(t)->set.head : 0)
#define ITEM(l) ((l) ? (Item *)((char *)(l) - 4) : 0)

int fn_883DDEB0(T *t, int n, unsigned char arg)
{
    T *self = t;
    Link *l, *next;
    int r;
    unsigned char found;
    if (n == -1) {
        fn_883DD108(&self, 1);
        for (l = t->set.head.next; l != HEAD(t); l = next) {
            next = l->next;
            r = fn_883DBEF8((Item *)((char *)l - 4), 1);
            if (r)
                return r;
        }
        t->count = 0;
        return 0;
    }
    if (!t->count || !n)
        return 0;
    fn_883DD108(&self, 1);
    do {
        if (t->count && t->count <= t->max) {
            found = 0;
            for (l = t->set.head.next; l != HEAD(t); l = l->next) {
                if (!ITEM(l)->busy) {
                    r = fn_883DBEF8(ITEM(l), arg);
                    if (r)
                        return r;
                    found = 1;
                    break;
                }
            }
            if (!found)
                for (l = t->set.head.next; l != HEAD(t); l = l->next)
                    ;
        }
        if (--t->count < 0)
            t->count = 0;
    } while (--n);
    return 0;
}
