/* 0x883D1FB0: visitor: with no node, calls slot 13 for every node of every group at +0x8084; otherwise calls slot 13 for each child node and slot 14 (key from 883C66E8, result ignored) for each item; returns the first slot-13 error. The vtable is read into a local before the key call, as in the target */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Kids { int p0; Link head; } Kids;
typedef struct Item Item;
typedef struct Node { int vt; Link link; char pad[0x28 - 0xc]; Kids *kids; char pad2[0x34 - 0x2c]; Link items; } Node;
typedef struct Group { int vt; Link link; char pad[0x20 - 0xc]; Link nodes; } Group;
typedef struct V V;
typedef struct VVt { void *f[13]; int (*node)(V *v, void *ctx, Node *n); void (*item)(V *v, void *ctx, void *key, Item *it); } VVt;
struct V { VVt *vt; char pad[0x8084 - 4]; Link groups; };
void *fn_883C66E8(Item *it);

int fn_883D1FB0(V *v, void *ctx, Node *n)
{
    Link *g, *l;
    int r;
    if (!n) {
        for (g = v->groups.next; g != &v->groups; g = g->next) {
            Group *gp = g ? (Group *)((char *)g - 4) : 0;
            for (l = gp->nodes.next; l != &gp->nodes; l = l->next) {
                r = v->vt->node(v, ctx, l ? (Node *)((char *)l - 4) : 0);
                if (r)
                    return r;
            }
        }
    } else {
        if (n->kids) {
            for (l = n->kids->head.next; l != (n->kids ? &n->kids->head : 0); l = l->next) {
                r = v->vt->node(v, ctx, l ? (Node *)((char *)l - 4) : 0);
                if (r)
                    return r;
            }
        }
        for (l = n->items.next; l != &n->items; l = l->next) {
            Item *it = l ? (Item *)((char *)l - 8) : 0;
            VVt *vt = v->vt;
            vt->item(v, ctx, fn_883C66E8(it), it);
        }
    }
    return 0;
}
