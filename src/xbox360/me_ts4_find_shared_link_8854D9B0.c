/* 0x8854D9B0: searches the node with fewer links for the link to the other node and returns its data, else 0 */
/* Matched on /Oc (agAH). The '<=' arm written first keeps the a/b order of the target. */
typedef struct Node Node;
typedef struct Link { void *data; Node *peer; } Link;
struct Node { char p[0x4c]; Link *links; int count; };
void *fn_8854D9B0(Node *a, Node *b)
{
    Node *s, *o;
    int i;
    if (a->count <= b->count) {
        s = a;
        o = b;
    } else {
        s = b;
        o = a;
    }
    for (i = 0; i < s->count; i++)
        if (s->links[i].peer == o)
            return s->links[i].data;
    return 0;
}
