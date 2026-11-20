/* 0x883C7E10: stores an int at +0x40; the leaf call notifies the +0x138 source (vtable slot 45); when deep, redirects to the owner node and propagates to the playing group items it owns (flag 0x80) or to every child of its list (non-deep recursion). */
/* Matched on /O1 (agY). The +0x64 flag is a short; bit 0x20 is read as (unsigned char)(((unsigned)f >> 5) & 1) for the lhz extrwi. */
#ifdef _MSC_VER
#define PTR_INT(p) ((int)(p))
#else
#define PTR_INT(p) ((int)(long)(p))
#endif
typedef struct Node Node;
typedef struct Owner { Node *node; } Owner;
typedef struct List { int count; Node **items; } List;
typedef struct Mix { char pad[8]; int count; int pc; Node **items; } Mix;
typedef struct Sub { char pad[0x38]; Mix *mix; } Sub;
typedef struct Sys { char pad[0x30]; Sub *sub; } Sys;
typedef struct Src Src;
typedef struct SrcVt { void *f[45]; int (*update)(Src *s); } SrcVt;
struct Src { SrcVt *vt; };
struct Node {
    char pad0[0x28];
    Sys *sys;
    char pad1[0x14];
    int val;
    char pad2[0x20];
    short flags;
    char pad3[0x42];
    List *list;
    Owner *owner;
    char pad4[0x88];
    Src *src;
};

static unsigned char is_grp(Node *n) { return (unsigned char)(((unsigned)n->flags >> 5) & 1); }

int fn_883C7E10(Node *self, int v, unsigned char deep)
{
    int i, r;
    Node *n = self;
    if (deep) {
        if (n->owner ? n->owner->node : 0)
            n = n->owner ? n->owner->node : 0;
        n->val = v;
        if (is_grp(n)) {
            Mix *m = n->sys->sub->mix;
            int cnt = m->count;
            Node **items = m->items;
            for (i = 0; i < cnt; i++) {
                if (items[i] && (items[i]->owner ? items[i]->owner->node : 0) == n && (items[i]->flags & 0x80)) {
                    r = fn_883C7E10(items[i], v, 0);
                    if (r)
                        return r;
                }
            }
        } else {
            for (i = 0; i < n->list->count; i++) {
                if (PTR_INT(n->list->items) != 0 && n->list->items[i]) {
                    r = fn_883C7E10(n->list->items[i], v, 0);
                    if (r)
                        return r;
                }
            }
        }
    } else {
        n->val = v;
        r = n->src->vt->update(n->src);
        if (r)
            return r;
    }
    return 0;
}
