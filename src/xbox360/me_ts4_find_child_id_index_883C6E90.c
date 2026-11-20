/* 0x883C6E90: returns the index of id in the id list (+0x20, count +0x1C) of the node's list (+0xA8), using the owner node (+0xAC) when there is one; -1 when absent. */
/* Matched on /Oc (agAB). Count-guarded pointer walk (i = 0; if (n > 0) { p = ids; for (; i < n; i++, p++) ... }). */
typedef struct L { char p[0x1c]; int n; unsigned int *ids; } L;
typedef struct N { char p[0xa8]; L *l; struct Own *own; } N;
typedef struct Own { N *node; } Own;
static N *top(N *n) { return n->own ? n->own->node : n; }
int fn_883C6E90(N *n, unsigned int id)
{
    L *l = top(n)->l;
    int i;
    unsigned int *p;
    i = 0;
    if (l->n > 0) {
        p = l->ids;
        for (; i < l->n; i++, p++)
            if (*p == id)
                return i;
    }
    return -1;
}
