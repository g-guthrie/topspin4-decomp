/* 0x883D86A0: for a mixed node forwards to the mixer (883DB998); otherwise moves to the owner node and releases every non-null list item through 883CD3F0, clearing the slot. */
/* Near miss /O1 (agV): 1 off, lwzx base/index order on n->list->items[i] (same open class as 883C75D0/883CBB30); the stwx order matches. */
typedef struct Node Node;
typedef struct Owner { Node *node; } Owner;
typedef struct List { int count; void **items; } List;
struct Node { char pad0[0xa8]; List *list; Owner *owner; };
typedef struct Sub { char pad[0x38]; void *mix; } Sub;
typedef struct T { char pad[0x30]; Sub *sub; } T;
unsigned char ts4_get_u16_off64_883C7098(Node *n);
int fn_883DB998(void *mix, Node *n, void *arg);
int fn_883CD3F0(void *o, int a, void *b, int c);

static Node *owner_node(Node *n) { return n->owner ? n->owner->node : 0; }

int fn_883D86A0(T *t, Node *n, void *arg)
{
    int i, r;
    if (ts4_get_u16_off64_883C7098(n)) {
        if (t->sub->mix) {
            r = fn_883DB998(t->sub->mix, n, arg);
            if (r)
                return r;
        }
    } else {
        if (owner_node(n))
            n = owner_node(n);
        for (i = 0; i < n->list->count; i++) {
            if (n->list->items[i]) {
                r = fn_883CD3F0(n->list->items[i], 0, arg, 1);
                if (r)
                    return r;
                n->list->items[i] = 0;
            }
        }
    }
    return 0;
}
