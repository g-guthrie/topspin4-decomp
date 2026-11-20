/* 0x883C75D0: recurses into every non-null child of node->kids (+0xA8) until one returns nonzero, then calls the sink's +0x14 method. */
/* Matched on /O1 (agZ). Index-first lwzx: test via the chain, pass the child through a block-local `it = t->kids->items`. */
typedef struct Node Node;
typedef struct Kids { int n; Node **items; } Kids;
typedef struct Sink Sink;
typedef struct SinkVt { char pad[0x14]; int (*f14)(Sink *s, void *x); } SinkVt;
struct Sink { SinkVt *vt; };
struct Node { char pad[0xa8]; Kids *kids; char pad2[0x8c]; Sink *sink; };
int fn_883C75D0(Node *t, void *x)
{
int i; int r;
 if (t->kids) { for (i = 0; i < t->kids->n; i++) { if (t->kids->items[i]) { Node **it = t->kids->items; r = fn_883C75D0(it[i], x); if (r) return r; } } }
    return t->sink->vt->f14(t->sink, x);
}
