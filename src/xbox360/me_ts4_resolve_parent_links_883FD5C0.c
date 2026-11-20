/* Swing_DLL.xex 0x883FD5C0: for each node in the tree list (+0x40), sets node->parent (+0x18) and desc->parentDesc
 * (+0x28) from desc->parentIndex (+0x24, -1 = none); 0x13 if the index is out of range. agAE: /O1. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Desc { char pad[0x24]; int parentIndex; void *parentDesc; } Desc;
typedef struct Node { void *vt; Link link; char padc[0x14 - 0xc]; Desc *desc; struct Node *parent; } Node;
typedef struct Tree { char pad[0x40]; Link nodes; } Tree;
#define LINK_NODE(l) ((l) ? (Node *)((char *)(l) - 4) : 0)
int fn_883FD5C0(Tree *t)
{
    Link *l;
    for (l = t->nodes.next; l != &t->nodes; l = l->next) {
        Node *n = LINK_NODE(l);
        Desc *d = n->desc;
        int idx = d->parentIndex;
        if (idx == -1) {
            n->parent = 0;
            d->parentDesc = 0;
        } else {
            Link *k;
            Node *p;
            int i = 0;
            for (k = t->nodes.next; k != &t->nodes; k = k->next, i++)
                if (i >= idx) break;
            if (k == &t->nodes) return 0x13;
            p = LINK_NODE(k);
            n->parent = p;
            d->parentDesc = p->desc;
        }
    }
    return 0;
}
