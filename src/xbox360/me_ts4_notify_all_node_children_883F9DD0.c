/* 0x883F9DD0: for each node in +0x34[0..+0x2C), calls vtable slot 0x10(x) on every non-null child in node->f_a8 (count, items); returns the first error */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Obj Obj;
typedef struct ObjVt { char pad[0x10]; int (*f10)(Obj *o, void *x); } ObjVt;
struct Obj { ObjVt *vt; };
typedef struct Kids { int n; Obj **items; } Kids;
typedef struct Node { char pad[0xa8]; Kids *kids; } Node;
typedef struct T { char pad[0x2c]; unsigned int count; char pad2[4]; Node **nodes; } T;
int ts4_notify_all_node_children_883F9DD0(T *t, void *x)
{
    unsigned int i;
    for (i = 0; i < t->count; i++) {
        Kids *k = t->nodes[i]->kids;
        int n = k->n;
        Obj **items = k->items;
        int j;
        int r;
        for (j = 0; j < n; j++) {
            if (items[j]) {
                r = items[j]->vt->f10(items[j], x);
                if (r)
                    return r;
            }
        }
    }
    return 0;
}
