/* 0x883CBB30: unless the node is a group (+0x64 bit 0x20) or has no kids, recurses into every child until one returns nonzero; otherwise calls the sink's +0x24 method. */
/* Matched on /O1 and /Os (agZ). Index-first lwzx: pass the child through a block-local it = t->kids->items; agY short-flag rule for extrwi. */
typedef struct Node Node;
typedef struct Kids { int n; Node **items; } Kids;
typedef struct Sink Sink;
typedef struct SinkVt { char pad[0x24]; int (*f24)(Sink *s, void *x); } SinkVt;
struct Sink { SinkVt *vt; };
struct Node { char pad[0x64]; short flags; char pad1[0x42]; Kids *kids; char pad2[0x8c]; Sink *sink; };
int fn_883CBB30(Node *t, void *x)
{
    int i;
    int r;
    if (t->kids && !(unsigned char)(((unsigned)t->flags >> 5) & 1)) {
        for (i = 0; i < t->kids->n; i++) {
            Node **it = t->kids->items; r = fn_883CBB30(it[i], x);
            if (r)
                return r;
        }
        return 0;
    }
    return t->sink->vt->f24(t->sink, x);
}
