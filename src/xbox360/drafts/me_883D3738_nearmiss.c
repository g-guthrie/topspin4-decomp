/* 0x883D3738: applies manager slot 67 (m, node, a, b, c, deep) to the playing mixer items owned by a group node (883C7098) or to every child of a leaf list when deep, then reports through 883C7220 when the node has a callback at +0x74; 0x25 for a null node. */
/* Near miss /O1 (agX): 2 off, lwzx base/index order on n->list->items[i] in the leaf loop (the 883C75D0 lwzx-order class; index, pointer-add and byte-offset forms all give the same). */
typedef struct Node Node;
typedef struct Owner { Node *node; } Owner;
typedef struct List { int count; Node **items; } List;
typedef struct Mix { char pad[8]; int count; int pc; Node **items; } Mix;
typedef struct Sub { char pad[0x38]; Mix *mix; } Sub;
typedef struct Sys { char pad[0x30]; Sub *sub; } Sys;
struct Node {
    char pad0[0x28];
    Sys *sys;
    char pad1[0x64 - 0x2c];
    unsigned short flags;
    char pad2[0x74 - 0x66];
    void *cb;
    char pad3[0xa8 - 0x78];
    List *list;
    Owner *owner;
};
typedef struct Mgr Mgr;
typedef struct MgrVt { void *f[67]; int (*apply)(Mgr *m, Node *n, int a, int b, int c, unsigned char deep); } MgrVt;
struct Mgr { MgrVt *vt; };
unsigned char ts4_get_u16_off64_883C7098(Node *n);
void ts4_call_cb_883C7220(Node *n, int a, int b, int c);

int fn_883D3738(Mgr *m, Node *n, int a, int b, int c, unsigned char deep)
{
    int i, r;
    if (!n)
        return 0x25;
    if (deep && n->list) {
        if (ts4_get_u16_off64_883C7098(n)) {
            Mix *mx = n->sys->sub->mix;
            int cnt = mx->count;
            Node **items = mx->items;
            for (i = 0; i < cnt; i++) {
                if (items[i] && (items[i]->owner ? items[i]->owner->node : 0) == n && (items[i]->flags & 0x80)) {
                    r = m->vt->apply(m, items[i], a, b, c, deep);
                    if (r)
                        return r;
                }
            }
        } else {
            for (i = 0; i < n->list->count; i++) {
                if (n->list->items[i]) {
                    r = m->vt->apply(m, n->list->items[i], a, b, c, deep);
                    if (r)
                        return r;
                }
            }
        }
    }
    if (n->cb)
        ts4_call_cb_883C7220(n, a, b, c);
    return 0;
}
