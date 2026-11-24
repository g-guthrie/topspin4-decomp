/* 0x883D9CA0: for a null node recurses over every node on t's list (+0x34, link at node+8); otherwise, unless a group, fills each empty kid slot through 883D9AD0 and then runs 883CBD20 on the new kid. */
/* Matched on /O1 and /Os (agZ). Index-first lwzx and the r31/r30 allocation: test via the chain, re-read node->kids->items into a block-scoped it for each call. */
typedef struct Link { struct Link *next; } Link;
typedef struct Node Node;
typedef struct Kids { int n; Node **items; } Kids;
struct Node { char pad[0xa8]; Kids *kids; };
typedef struct T { char pad[0x34]; Link head; } T;
unsigned char ts4_get_u16_off64_883C7098(Node *n);
int fn_883D9AD0(T *t, Node *n, Node **slot);
int fn_883CBD20(Node *n);
int fn_883D9CA0(T *t, Node *node)
{
    Link *l;
    int i;
    int r;
    if (!node) {
        for (l = t->head.next; l != &t->head; l = l->next) {
            r = fn_883D9CA0(t, l ? (Node *)((char *)l - 8) : 0);
            if (r)
                return r;
        }
    } else if (!ts4_get_u16_off64_883C7098(node)) {
        for (i = 0; i < node->kids->n; i++) {
            if (!node->kids->items[i]) {
                {Node **it = node->kids->items; r = fn_883D9AD0(t, node, &it[i]);}
                if (r)
                    return r;
                {Node **it = node->kids->items; r = fn_883CBD20(it[i]);}
                if (r)
                    return r;
            }
        }
    }
    return 0;
}
