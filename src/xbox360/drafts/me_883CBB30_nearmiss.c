typedef struct Node Node;
typedef struct Kids { int n; Node **items; } Kids;
typedef struct Sink Sink;
typedef struct SinkVt { char pad[0x24]; int (*f24)(Sink *s, void *x); } SinkVt;
struct Sink { SinkVt *vt; };
struct Node { char pad[0x64]; unsigned short flags; char pad1[0x42]; Kids *kids; char pad2[0x8c]; Sink *sink; };
int fn_883CBB30(Node *t, void *x)
{
    int i;
    int r;
    if (t->kids && !((t->flags >> 5) & 1)) {
        for (i = 0; i < t->kids->n; i++) {
            r = fn_883CBB30(t->kids->items[i], x);
            if (r)
                return r;
        }
        return 0;
    }
    return t->sink->vt->f24(t->sink, x);
}
