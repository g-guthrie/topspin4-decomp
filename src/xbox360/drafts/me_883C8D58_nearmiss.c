/* 0x883C8D58: refuses (0x52) while any owned child is busy (+0x60 bit 0x1000), else propagates the short pair at +0xA4/+0xA6; the leaf also clears owner +0x1C. */
/* Near miss /O1 (agY): 69 off, list busy-loop shape and a li r9 placement. The extrwi. flag test matches. */
#ifdef _MSC_VER
#define PTR_INT(p) ((int)(p))
#else
#define PTR_INT(p) ((int)(long)(p))
#endif
typedef struct Node Node;
typedef struct Owner { Node *node; char pad[0x18]; short seg; } Owner;
typedef struct List { int count; Node **items; } List;
typedef struct Mix { char pad[8]; int count; int pc; Node **items; } Mix;
typedef struct Sub { char pad[0x38]; Mix *mix; } Sub;
typedef struct Sys { char pad[0x30]; Sub *sub; } Sys;
struct Node {
    char pad0[0x28];
    Sys *sys;
    char pad1[0x60 - 0x2c];
    unsigned int state;
    short flags;
    char pad2[0xa4 - 0x66];
    short a;
    short b;
    List *list;
    Owner *owner;
};
static unsigned char is_grp(Node *n) { return (unsigned char)(((unsigned)n->flags >> 5) & 1); }

int fn_883C8D58(Node *self, short a, short b, unsigned char deep)
{
    int i, r;
    Node *n = self;
    if (deep) {
        if (n->owner ? n->owner->node : 0)
            n = n->owner ? n->owner->node : 0;
        if (is_grp(n)) {
            Mix *m = n->sys->sub->mix;
            int cnt = m->count;
            Node **items = m->items;
            for (i = 0; i < cnt; i++) {
                if (items[i] && (items[i]->owner ? items[i]->owner->node : 0) == n && (items[i]->flags & 0x80) && (items[i]->state & 0x1000))
                    return 0x52;
            }
            for (i = 0; i < cnt; i++) {
                if (items[i] && (items[i]->owner ? items[i]->owner->node : 0) == n && (items[i]->flags & 0x80)) {
                    r = fn_883C8D58(items[i], a, b, 0);
                    if (r)
                        return r;
                }
            }
        } else {
            for (i = 0; i < n->list->count; i++) {
                if (PTR_INT(n->list->items) != 0 && n->list->items[i] && (n->list->items[i]->state & 0x1000))
                    return 0x52;
            }
            for (i = 0; i < n->list->count; i++) {
                if (PTR_INT(n->list->items) != 0 && n->list->items[i]) {
                    r = fn_883C8D58(n->list->items[i], a, b, 0);
                    if (r)
                        return r;
                }
            }
        }
        n->a = a;
        n->b = b;
    } else {
        if (n->state & 0x1000)
            return 0x52;
        n->a = a;
        n->b = b;
        n->owner->seg = 0;
    }
    return 0;
}
