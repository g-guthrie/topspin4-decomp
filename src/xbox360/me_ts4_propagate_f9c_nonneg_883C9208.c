/* 0x883C9208: clamps a float to >= 0 and stores it at +0x9C (owner node when deep); when deep, propagates to the playing group items it owns (flag 0x80) or to every child of its list (non-deep recursion). */
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
    char pad2[0x36];
    float val;
    char pad3[0x8];
    List *list;
    Owner *owner;
};

static unsigned char is_grp(Node *n) { return (unsigned char)(((unsigned)n->flags >> 5) & 1); }

int fn_883C9208(Node *self, float v, unsigned char deep)
{
    int i, r;
    Node *n = self;
    if (v < lbl_88001A20)
        v = lbl_88001A20;
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
                    r = fn_883C9208(items[i], v, 0);
                    if (r)
                        return r;
                }
            }
        } else {
            for (i = 0; i < n->list->count; i++) {
                if (PTR_INT(n->list->items) != 0 && n->list->items[i]) {
                    r = fn_883C9208(n->list->items[i], v, 0);
                    if (r)
                        return r;
                }
            }
        }
    } else {
        n->val = v;
    }
    return 0;
}
