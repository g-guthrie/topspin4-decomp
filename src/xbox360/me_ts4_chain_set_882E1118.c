/* 0x882E1118: decodes the node from ~handle and calls fn(node, a, &value, 1, 0) on it and every node along the +0x24 chain, returning the first negative result, else 0 (float value). */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); /O1 for the cr0 compare. */
typedef struct Node { char pad[0x24]; struct Node *next; } Node;
int fn_882DF080(Node *n, void *a, float *vals, unsigned count, int flags);
int ts4_chain_set_882E1118(void *self, void *a, unsigned handle, float value)
{
    Node *n = (Node *)~handle;
    for (;;) {
        int r = fn_882DF080(n, a, &value, 1, 0);
        if (r < 0)
            return r;
        n = n->next;
        if (!n)
            return 0;
    }
}
