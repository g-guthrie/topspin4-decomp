/* 0x882E0F18: decodes the node from ~handle and calls fn(node, a, vals, bytes / 4, 0) on it and every node along the +0x24 chain, returning the first negative result, else 0. */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); /O1 for the cr0 compare; model 0x882E0F78. */
typedef struct Node { char pad[0x24]; struct Node *next; } Node;
int fn_882DE640(Node *n, void *a, const void *vals, unsigned count, int flags);
int ts4_chain_set_array_882E0F18(void *self, void *a, unsigned handle, const void *vals, unsigned bytes)
{
    Node *n = (Node *)~handle;
    unsigned count = bytes >> 2;
    for (;;) {
        int r = fn_882DE640(n, a, vals, count, 0);
        if (r < 0)
            return r;
        n = n->next;
        if (!n)
            return 0;
    }
}
