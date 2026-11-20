/* 0x88594678: Under the subject lock (vt slots 2/5 on the lock at +0x70), walks the listener list and calls each listener notify (vt slot 2) with arg. */
/* Matched on /O1 (agAH). Open-coded iterator: if (n) { it = n->next; li = n->item; } else li = 0; break on 0. */
typedef struct Lock Lock;
typedef struct LockVt { void *s[2]; void (*lock)(Lock *); void *s3[2]; void (*unlock)(Lock *); } LockVt;
struct Lock { LockVt *vt; };
typedef struct Listener Listener;
typedef struct ListenerVt { void *s[2]; void (*notify)(Listener *, void *); } ListenerVt;
struct Listener { ListenerVt *vt; };
typedef struct Node { Listener *item; struct Node *next; } Node;
typedef struct Subject { char p0[0x70]; Lock lock; char p74[0x22c - 0x74]; Node *listeners; } Subject;
void fn_88594678(Subject *s, void *arg)
{
    Lock *l = &s->lock;
    Node *it;
    Listener *li;
    l->vt->lock(l);
    it = s->listeners;
    for (;;) {
        Node *n = it;
        if (n != 0) {
            it = n->next;
            li = n->item;
        } else
            li = 0;
        if (li == 0)
            break;
        li->vt->notify(li, arg);
    }
    l->vt->unlock(l);
}
