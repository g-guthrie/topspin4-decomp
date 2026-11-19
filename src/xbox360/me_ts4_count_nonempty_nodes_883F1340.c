/* Swing_DLL.xex 0x883F1340: walks three nested intrusive lists (root +0xC, node kids +0x34, node parts +0x78) and counts
 * the second- and third-level nodes whose kids list head is non-null. 0x25 on a null out. agAE: /O1. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Node { void *vt; Link link; char padc[0x34 - 0xc]; Link kids; char pad3c[0x78 - 0x3c]; Link parts; } Node;
typedef struct Root { char pad[0xc]; Link nodes; } Root;
#define LINK_NODE(l) ((l) ? (Node *)((char *)(l) - 4) : 0)
int fn_883F1340(Root *r, int *out)
{
    Link *l1, *l2, *l3;
    int n = 0;
    if (!out) return 0x25;
    *out = 0;
    for (l1 = r->nodes.next; l1 != &r->nodes; l1 = l1->next) {
        Node *a = LINK_NODE(l1);
        for (l2 = a->kids.next; l2 != &a->kids; l2 = l2->next) {
            Node *b = LINK_NODE(l2);
            n += b->kids.next != 0;
            for (l3 = b->parts.next; l3 != &b->parts; l3 = l3->next)
                n += LINK_NODE(l3)->kids.next != 0;
        }
    }
    *out = n;
    return 0;
}
