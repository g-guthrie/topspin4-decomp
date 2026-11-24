/* Swing_DLL.xex 0x883DBBA0: counts group nodes (+0x10, count +0x8) whose owner node (+0xAC->+0) is n's owner node
 * (or n itself) and whose flags (+0x64) have bit 0x80. 0x25 on null args, 0x51 without nodes. agAE: /O1. */
typedef struct Node Node;
typedef struct Owner { Node *node; } Owner;
struct Node { char pad[0x64]; unsigned short flags; char pad66[0xac - 0x66]; Owner *owner; };
typedef struct Group { char pad[8]; int count; char padc[4]; Node **nodes; } Group;
static __inline Node *owner_node(Node *n) { return n->owner ? n->owner->node : 0; }
int fn_883DBBA0(Group *g, Node *n, int *out)
{
    int i, c;
    Node **p;
    if (!n || !out) return 0x25;
    p = g->nodes;
    if (!p) return 0x51;
    if (owner_node(n)) n = owner_node(n);
    c = 0;
    {
        Node **q = p;
        for (i = g->count; i > 0; i--, q++)
            if (owner_node(*q) == n && ((*q)->flags & 0x80)) c++;
    }
    *out = c;
    return 0;
}
