/* 0x886C3B20: starting from the last node in the owner's node list, follow parent links (at most 100 steps)
 * and return the topmost ancestor whose parent is neither null nor self. The game compares the parent link
 * signed (cmpwi), hence the (int) cast. */
typedef struct Node Node;
typedef struct NodeOwner { char p[0x8c]; Node **begin; Node **end; } NodeOwner;
struct Node { char p[0x30]; NodeOwner *owner; Node *parent; };
Node *ts4_node_last_top_ancestor(Node *self)
{
    int i;
    Node *n = self->owner->end[-1];
    for (i = 0; i < 100; i++) {
        if (n == 0 || (int)n->parent == 0 || n->parent == self) break;
        n = n->parent;
    }
    return n;
}
