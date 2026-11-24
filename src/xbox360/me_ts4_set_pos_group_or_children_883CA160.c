/* 0x883CA160: forwards a position (slot 34) to the playing mixer items owned by a group node, or to every child of a leaf list, then stores it at +0x74/+0x78. */
/* Matched on /O1 and /Os (agY): short flag field, (unsigned char)(((unsigned)f >> 5) & 1) gives the lhz extrwi. */
#ifdef _MSC_VER
#define PTR_INT(p) ((int)(p))
#else
#define PTR_INT(p) ((int)(long)(p))
#endif
typedef struct Node Node;
typedef struct NodeVt { void *f[34]; int (*set_pos)(Node *n, int a, int b); } NodeVt;
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
    char pad2[0x74 - 0x66];
    int a, b;
    char pad3[0xa8 - 0x7c];
    List *list;
    Owner *owner;
};

static unsigned char is_grp(Node *n) { return (unsigned char)(((unsigned)n->flags >> 5) & 1); }
int fn_883CA160(Node *n, int a, int b)
{
    int i, r;
    if (n->list) {
        if (is_grp(n)) {
            Mix *m = n->sys->sub->mix;
            int cnt = m->count;
            Node **items = m->items;
            for (i = 0; i < cnt; i++) {
                if (items[i] && (items[i]->owner ? items[i]->owner->node : 0) == n && (items[i]->flags & 0x80)) {
                    r = items[i]->vt->set_pos(items[i], a, b);
                    if (r)
                        return r;
                }
            }
        } else {
            for (i = 0; i < n->list->count; i++) {
                Node **it = n->list->items;
                if (PTR_INT(it) != 0 && it[i]) {
                    r = it[i]->vt->set_pos(it[i], a, b);
                    if (r)
                        return r;
                }
            }
        }
    }
    n->a = a;
    n->b = b;
    return 0;
}
