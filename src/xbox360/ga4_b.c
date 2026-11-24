/*
 * GA4: gameplay controller helpers (Top Spin 4, Xbox 360, Swing_DLL.xex), batch B.
 * Offsets were read from machine code; names follow docs/gameplay where known.
 */
#include "ts4_vector.h"

typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

/* 12-byte handle passed by value. */
struct Ga4Triple { ts4_u32 first, second, third; };

/* ------------------------------------------------------------------ */
struct Ga4Obj;
struct Ga4ObjVtbl {
    void *slot[10];
    ts4_u32 (*method28)(struct Ga4Obj *self, void *tmp, ts4_u32 arg, int flag);
};
struct Ga4Obj { struct Ga4ObjVtbl *vtbl; };
struct Ga4Tmp { struct Ga4Obj *obj; ts4_u32 second; ts4_u32 third; ts4_u32 fourth; };
extern char lbl_880C1320;
extern void fn_8862BCB8(struct Ga4Tmp *out, struct Ga4Triple value, void *name);
struct Ga4TreeNode { int rel; ts4_u32 kind; };
struct Ga4TreeBody { int rel; ts4_u32 unk_04, unk_08, unk_0C; int list; ts4_u32 index; };
struct Ga4TreeOut { ts4_u32 *items; };

/* Same function under its placeholder symbol (the recursion targets it). */
extern void ga4_tree_collect_886AB320(void *self, struct Ga4TreeNode *node, struct Ga4TreeOut *out, struct Ga4Triple *key);

/* Walk a decision tree (node kind 0x48BFC8B8): at each node resolve the named object for `key`, call its
   vtable slot +0x28 and store the result at out->items[body->index], then recurse into both children.
   Swing_DLL.xex 0x886AB320 */
void ga4_tree_collect_886AB320(void *self, struct Ga4TreeNode *node, struct Ga4TreeOut *out, struct Ga4Triple *key)
{
    struct Ga4TreeBody *body;
    void *name;
    int *lp;
    ts4_u32 r;
    struct Ga4Tmp tmp;
    if (node->kind != 0x48BFC8B8u)
        return;
    body = (struct Ga4TreeBody *)((char *)node + node->rel);
    lp = &body->list;
    if (*lp != -1)
        name = (char *)lp + *lp;
    else
        name = &lbl_880C1320;
    fn_8862BCB8(&tmp, *key, name);
    r = tmp.obj->vtbl->method28(tmp.obj, &tmp, tmp.second, 1);
    out->items[body->index] = r;
    ga4_tree_collect_886AB320(self, (struct Ga4TreeNode *)((char *)body + body->rel), out, key);
    ga4_tree_collect_886AB320(self, (struct Ga4TreeNode *)((char *)body + body->rel) + 1, out, key);
}
