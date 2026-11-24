/* 0x882E1048: decodes the node from ~handle and calls fn(node, a, &value, 1, 0) on it and every node along the +0x24 chain, returning the first negative result, else 0 (int value). */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); /O1 for the cr0 compare. */
typedef struct Node { char pad[0x24]; struct Node *next; } Node;
int fn_882DECF0(Node *n, void *a, int *vals, unsigned count, int flags);
int ts4_chain_set_882E1048(void *self, void *a, unsigned handle, int value)
{
    Node *n = (Node *)~handle;
    for (;;) {
        int r = fn_882DECF0(n, a, &value, 1, 0);
        if (r < 0)
            return r;
        n = n->next;
        if (!n)
            return 0;
    }
}
