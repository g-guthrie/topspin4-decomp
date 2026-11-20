/* 0x883D07C8: calls t's vtable slot 0x10(item, a, b) for each item in o->f28's list (end re-checked), then each kid's +0x138 sink slot 0x88(a, b) over the list at +0x34; returns the first error */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Link { struct Link *next; } Link;
typedef struct Item Item;
typedef struct Set { int f0; Link head; } Set;
typedef struct Sink Sink;
typedef struct SinkVt { char pad[0x88]; int (*f88)(Sink *s, void *a, void *b); } SinkVt;
struct Sink { SinkVt *vt; };
typedef struct Kid { char pad[0x138]; Sink *sink; } Kid;
typedef struct O { char pad[0x28]; Set *set; char pad2[8]; Link kids; } O;
typedef struct T T;
typedef struct TVt { char pad[0x10]; int (*f10)(T *t, Item *it, void *a, void *b); } TVt;
struct T { TVt *vt; };
int ts4_visit_set_and_kids_883D07C8(T *t, O *o, void *a, void *b)
{
    Link *n;
    int r;
    if (o->set) {
        for (n = o->set->head.next; n != (o->set ? &o->set->head : 0); n = n->next) {
            r = t->vt->f10(t, n ? (Item *)((char *)n - 4) : 0, a, b);
            if (r)
                return r;
        }
    }
    for (n = o->kids.next; n != &o->kids; n = n->next) {
        Kid *k = n ? (Kid *)((char *)n - 8) : 0;
        r = k->sink->vt->f88(k->sink, a, b);
        if (r)
            return r;
    }
    return 0;
}
