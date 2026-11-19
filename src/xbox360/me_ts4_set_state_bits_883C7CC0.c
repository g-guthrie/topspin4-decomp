/* 0x883C7CC0: ORs state bits (masked with 0xFFCB8FFF, keeping 0x347000) and halfword flags into a node; when deep, applies them to the owner node and recursively to every child (signed null test on the item table) */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
#ifdef _MSC_VER
#define PTR_INT(p) ((int)(p))
#else
#define PTR_INT(p) ((int)(long)(p))
#endif
typedef struct Node Node;
typedef struct Owner { Node *node; } Owner;
typedef struct List { int count; Node **items; } List;
struct Node {
    char pad0[0x60];
    unsigned int state;
    unsigned short flags;
    char pad1[0xa8 - 0x66];
    List *list;
    Owner *owner;
};

static Node *owner_node(Node *n) { return n->owner ? n->owner->node : 0; }

int fn_883C7CC0(Node *n, unsigned int bits, unsigned int flags, unsigned char deep)
{
    Node *t = n;
    int i, r;
    if (!bits && !flags)
        return 0;
    bits &= 0xffcb8fff;
    if (deep) {
        if (owner_node(n))
            t = owner_node(n);
        if (bits)
            t->state = (t->state & 0x347000) | bits;
        if (flags)
            t->flags |= flags;
        for (i = 0; i < t->list->count; i++) {
            if (PTR_INT(t->list->items) != 0 && t->list->items[i]) {
                r = fn_883C7CC0(t->list->items[i], bits, flags, 0);
                if (r)
                    return r;
            }
        }
    } else {
        if (bits)
            n->state = (n->state & 0x347000) | bits;
        if (flags)
            n->flags |= flags;
    }
    return 0;
}
