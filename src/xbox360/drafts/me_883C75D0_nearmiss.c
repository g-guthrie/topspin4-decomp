typedef struct Node Node;
typedef struct Kids { int n; Node **items; } Kids;
typedef struct Sink Sink;
typedef struct SinkVt { char pad[0x14]; int (*f14)(Sink *s, void *x); } SinkVt;
struct Sink { SinkVt *vt; };
struct Node { char pad[0xa8]; Kids *kids; char pad2[0x8c]; Sink *sink; };
int fn_883C75D0(Node *t, void *x)
{
    int i;
    int r;
    if (t->kids) {
        for (i = 0; i < t->kids->n; i++) {
            if (t->kids->items[i]) {
                r = fn_883C75D0(t->kids->items[i], x);
                if (r)
                    return r;
            }
        }
    }
    return t->sink->vt->f14(t->sink, x);
}
