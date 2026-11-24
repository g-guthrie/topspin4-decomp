/* 0x883CC7D0: clamps a float to >= 0; deep calls itself on the owner node (or self) and then propagates to the playing group items it owns (flag 0x80) or to every child of its list (non-deep recursion); the leaf stores +0x98 and caches fn_883C9B38 at +0xA0. */
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
extern const float lbl_88001A20;
struct Node {
    char pad0[0x28];
    Sys *sys;
    char pad1[0x38];
    short flags;
    char pad2[0x32];
    float val;
    char pad3[0x4];
    float eff;
    char pad4[0x4];
    List *list;
    Owner *owner;
};

float fn_883C9B38(Node *n);
static unsigned char is_grp(Node *n) { return (unsigned char)(((unsigned)n->flags >> 5) & 1); }

int fn_883CC7D0(Node *self, float v, unsigned char deep)
{
    int i, r;
    Node *n = self;
    if (v < lbl_88001A20)
        v = lbl_88001A20;
    if (deep) {
        if (n->owner ? n->owner->node : 0)
            n = n->owner ? n->owner->node : 0;
        r = fn_883CC7D0(n, v, 0);
        if (r)
            return r;
        if (is_grp(n)) {
            Mix *m = n->sys->sub->mix;
            int cnt = m->count;
            Node **items = m->items;
            for (i = 0; i < cnt; i++) {
                if (items[i] && (items[i]->owner ? items[i]->owner->node : 0) == n && (items[i]->flags & 0x80)) {
                    r = fn_883CC7D0(items[i], v, 0);
                    if (r)
                        return r;
                }
            }
        } else {
            for (i = 0; i < n->list->count; i++) {
                if (PTR_INT(n->list->items) != 0 && n->list->items[i]) {
                    r = fn_883CC7D0(n->list->items[i], v, 0);
                    if (r)
                        return r;
                }
            }
        }
    } else {
        self->val = v;
        self->eff = fn_883C9B38(self);
    }
    return 0;
}
