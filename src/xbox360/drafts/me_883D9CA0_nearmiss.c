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
                r = fn_883D9AD0(t, node, &node->kids->items[i]);
                if (r)
                    return r;
                r = fn_883CBD20(node->kids->items[i]);
                if (r)
                    return r;
            }
        }
    }
    return 0;
}
