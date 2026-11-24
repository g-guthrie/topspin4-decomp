typedef struct Link { struct Link *prev; struct Link *next; } Link;
typedef struct Node { const void *vt; int key; Link link; void *owner; const void *vt2; } Node;
typedef struct Obj { char pad[0x1c]; Node node; } Obj;
typedef struct List { int x; Link head; int count; } List;
typedef struct Mgr { char pad[0x2c]; List list; } Mgr;
extern Mgr *lbl_88D45940;
extern Obj *lbl_88D45910;
extern char lbl_880DB9C8[];
unsigned int ts4_call_seq_fn_888F70A0_888FB920(unsigned int a0);
/* Links a fresh event node from lbl_88D45910 into the priority list of lbl_88D45940. */
void fn_888FE0C8(void)
{
    Mgr *m = lbl_88D45940;
    Obj *o;
    Node *n, *p;
    Link *it;
    List *l;
    if (!m) return;
    o = lbl_88D45910;
    if (!o) return;
    l = &m->list;
    p = &o->node;
    if (p) { p->owner = o; p->vt = lbl_880DB9C8; p->vt2 = (const void *)ts4_call_seq_fn_888F70A0_888FB920; n = p; } else n = 0;
    n->key = 0;
    for (it = l->head.next; it != &l->head; it = it->next)
        if (((Node *)((char *)it - 8))->key < 0) break;
    n->link.next = it;
    n->link.prev = it->prev;
    it->prev->next = &n->link;
    it->prev = &n->link;
    l->count++;
}
