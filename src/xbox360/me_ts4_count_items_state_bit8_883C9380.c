/* 0x883C9380: counts the group items (or list children) whose state (vtable slot 33) has bit 8; 0x25 when out is null. */
/* Matched on /O1 (agZ). Base-first lwzx: test n->list->items[i] through the chain, then copy it to a block-local Node *c for the call. */
#ifdef _MSC_VER
#define PTR_INT(p) ((int)(p))
#else
#define PTR_INT(p) ((int)(long)(p))
#endif
typedef struct Node Node;
typedef struct NodeVt { void *f[33]; int (*get_state)(Node *n, unsigned int *st); } NodeVt;
typedef struct Owner { Node *node; } Owner;
typedef struct List { int count; Node **items; } List;
typedef struct Mix { char pad[8]; int count; int pc; Node **items; } Mix;
typedef struct Sub { char pad[0x38]; Mix *mix; } Sub;
typedef struct Sys { char pad[0x30]; Sub *sub; } Sys;
struct Node {
    NodeVt *vt;
    char pad0[0x28 - 4];
    Sys *sys;
    char pad1[0x64 - 0x2c];
    short flags;
    char pad2[0xa8 - 0x66];
    List *list;
    Owner *owner;
};
static unsigned char is_grp(Node *n) { return (unsigned char)(((unsigned)n->flags >> 5) & 1); }

int fn_883C9380(Node *self, int *out)
{
    unsigned int st;
    int i, r;
    int count;
    Node *n;
    if (self->owner ? self->owner->node : 0)
        n = self->owner ? self->owner->node : 0;
    else
        n = self;
    count = 0;
    if (!out)
        return 0x25;
    *out = 0;
    if (is_grp(n)) {
        Mix *m = n->sys->sub->mix;
        int cnt = m->count;
        Node **items = m->items;
        for (i = 0; i < cnt; i++) {
            if (items[i] && (items[i]->owner ? items[i]->owner->node : 0) == n && (items[i]->flags & 0x80)) {
                r = items[i]->vt->get_state(items[i], &st);
                if (r)
                    return r;
                if (st & 8)
                    count++;
            }
        }
    } else {
        if (PTR_INT(n->list->items) != 0) {
            for (i = 0; i < n->list->count; i++) {
                if (n->list->items[i]) {
                    Node *c = n->list->items[i];
                    r = c->vt->get_state(c, &st);
                    if (r)
                        return r;
                    if (st & 8)
                        count++;
                }
            }
        }
    }
    *out = count;
    return 0;
}
