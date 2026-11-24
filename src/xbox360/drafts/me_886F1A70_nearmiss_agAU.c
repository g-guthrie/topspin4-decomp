/* nearmiss: 2 off (q5s 2026-11-24); concrete blocker: as C++ member `?Apply@Obj@@QAAXH@Z` (/Oc) the keys[i] lhzx order is fixed (this after params); left: after the find call the target loads map.head (+0x18) before the found node (stack). Tried end() member, end/iterator locals, It struct with member/free operator!=, end()!=it (3 off), find returning It (30 off). */
/* agAU near-miss, plain /Oc, 3 off: lhzx operands swapped and map head loaded after the iterator (target loads head first). Same in .cpp with a real iterator class and LTCG ctx=[]. */

typedef unsigned short u16;
typedef struct Node { char p0[0x12]; u16 base; unsigned char bits; } Node;
typedef struct { Node *head; } Map;
typedef struct { u16 *remap; char p4[8]; u16 *keys; char p10[8]; Map map; } Obj;
typedef struct { char p0[0x8e]; u16 v; char p90[0x20]; } Slot;
typedef struct { char p0[0x1d54]; Slot *slots; } Ren;
extern Ren *lbl_88D45AD4;
void fn_8821FC68(Node **out, Map *m, const u16 *key);
void fn_886F1A70(Obj *o, int i)
{
    u16 key = o->keys[i];
    Node *n;
    fn_8821FC68(&n, &o->map, &key);
    if (n != o->map.head)
        lbl_88D45AD4->slots[i].v = o->remap[(u16)((n->bits >> 6) + n->base)];
}
