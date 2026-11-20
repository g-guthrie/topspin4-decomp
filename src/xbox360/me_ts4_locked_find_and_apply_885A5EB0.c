/* 0x885A5EB0: under the lock at +0x54, finds the node with the key in the list at +0x144 and passes it (or null) to the set at +0x78 */
/* Matched on /Os (agAH). /Os gives the unrotated while loop (b to the bottom test); inline find(). */
typedef struct Lock Lock;
typedef struct LockVt { void *f[2]; void (*enter)(Lock *l); void *g[2]; void (*leave)(Lock *l); } LockVt;
struct Lock { LockVt *vt; };
typedef struct Node { unsigned int key; struct Node *next; } Node;
typedef struct T { char p[0x54]; Lock lock; char p2[0x20]; char set[0xcc]; Node *head; } T;
extern void ts4_if_get_u32_offcc_885A54F8(void *set, Node *n);
static __inline Node *find(T *t, unsigned int key)
{
    Node *n;
    for (n = t->head; n; n = n->next)
        if (n->key == key)
            return n;
    return 0;
}
void fn_885A5EB0(T *t, unsigned int key)
{
    Lock *l = &t->lock;
    l->vt->enter(l);
    ts4_if_get_u32_offcc_885A54F8(t->set, find(t, key));
    l->vt->leave(l);
}
