/* 0x883DB998: stops a node in a mixer: a group node recurses into every mixer item it owns; a playing leaf (flag 0x80) is stopped via slot 4, 883CBBC8 and 883C70E8 and the flag cleared (0x25 null node, 0x51 no items) */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Node Node;
typedef struct NodeVt { void *f[4]; int (*stop)(Node *n, int now); } NodeVt;
typedef struct Owner { Node *node; } Owner;
struct Node { NodeVt *vt; char pad0[0x64 - 4]; short flags; char pad1[0xa8 - 0x66]; void *list; Owner *owner; };
typedef struct Mix { char pad[8]; unsigned int count; int pc; Node **items; } Mix;
int fn_883CBBC8(Node *n, void *arg);
void fn_883C70E8(Node *n, int a);

int fn_883DB998(Mix *m, Node *n, void *arg)
{
    unsigned int i;
    int r;
    if (!n)
        return 0x25;
    if (!m->items)
        return 0x51;
    if (n->list) {
        for (i = 0; i < m->count; i++) {
            Node *k = m->items[i];
            if ((k->owner ? k->owner->node : 0) == n) {
                r = fn_883DB998(m, k, arg);
                if (r)
                    return r;
            }
        }
    } else if (n->flags & 0x80) {
        r = n->vt->stop(n, 1);
        if (r)
            return r;
        r = fn_883CBBC8(n, arg);
        if (r)
            return r;
        fn_883C70E8(n, 1);
        n->flags &= ~0x80;
    }
    return 0;
}
