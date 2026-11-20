/* 0x883C7F88: stores a float pair at +0xD4/+0xD8 (leaf: scales +0xD8 by the owner node value when flag 0x4000000 is set) and notifies the +0x138 source (slot 46); when deep, propagates to the playing group items it owns (flag 0x80) or to every child of its list (non-deep recursion). */
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
typedef struct SrcVt { void *f[46]; int (*update)(Src *s); } SrcVt;
struct Src { SrcVt *vt; };
struct Node {
    char pad0[0x28];
    Sys *sys;
    char pad1[0x14];
    unsigned int f40;
    char pad2[0x20];
    short flags;
    char pad3[0x42];
    List *list;
    Owner *owner;
    char pad4[0x24];
    float a;
    float b;
    char pad5[0x5c];
    Src *src;
};

static unsigned char is_grp(Node *n) { return (unsigned char)(((unsigned)n->flags >> 5) & 1); }

int fn_883C7F88(Node *self, float a, float b, unsigned char deep)
{
    int i, r;
    Node *n = self;
    if (deep) {
        if (n->owner ? n->owner->node : 0)
            n = n->owner ? n->owner->node : 0;
        if (!(self->f40 & 0x4000000)) {
            n->a = a;
            n->b = b;
        }
        if (is_grp(n)) {
            Mix *m = n->sys->sub->mix;
            int cnt = m->count;
            Node **items = m->items;
            for (i = 0; i < cnt; i++) {
                if (items[i] && (items[i]->owner ? items[i]->owner->node : 0) == n && (items[i]->flags & 0x80)) {
                    r = fn_883C7F88(items[i], a, b, 0);
                    if (r)
                        return r;
                }
            }
        } else {
            for (i = 0; i < n->list->count; i++) {
                if (PTR_INT(n->list->items) != 0 && n->list->items[i]) {
                    r = fn_883C7F88(n->list->items[i], a, b, 0);
                    if (r)
                        return r;
                }
            }
        }
    } else {
        if ((n->f40 & 0x4000000) && (n->owner ? n->owner->node : 0))
            n->b = (n->owner ? n->owner->node : 0)->b * b;
        else {
            n->a = a;
            n->b = b;
        }
        r = n->src->vt->update(n->src);
        if (r)
            return r;
    }
    return 0;
}
