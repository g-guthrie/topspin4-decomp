/* 0x883F1A68: when mode bit 0x4000000 is set, copies the volume (+0xD8) to each item paired with a kind-0x10 source item and flags the object, then applies pan/volume (+0xD4/+0xD8) to every item of every group */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); the owner's system is an inline accessor called twice, which reloads +0xAC as in the target; errors 0x24 are ignored. */
typedef struct Link { struct Link *next; } Link;
typedef struct Mode { char pad[0x28]; unsigned int flags; } Mode;
typedef struct Item { int p0; Link link; char p8[0x14 - 8]; Mode *mode; char p18[0x30 - 0x18]; float level; } Item;
typedef struct Grp { int p0; Link link; char p8[0x34 - 8]; Link items; } Grp;
typedef struct Src { char pad[0x18]; Link items; } Src;
typedef struct Sys { char pad[0x138]; Src *src; } Sys;
typedef struct Own { Sys *sys; } Own;
typedef struct Obj { char pad[0x40]; unsigned int mode; char p44[0x60 - 0x44]; unsigned int flags; char p64[0xAC - 0x64]; Own *own; char pb0[0xD4 - 0xB0]; float pan, vol; char pdc[0x138 - 0xDC]; Src *src; } Obj;
typedef struct T { int p0; Obj *obj; char p8[4]; Link groups; char p10[0x18 - 0x10]; Link items; } T;
int fn_883E2428(Item *it, float a, float b);
static Sys *obj_sys(Obj *o) { return o->own ? o->own->sys : 0; }
int ts4_apply_levels_883F1A68(T *t)
{
    Link *n, *m, *la, *lb;
    Grp *g;
    Item *x, *y;
    Src *src;
    int r;
    src = obj_sys(t->obj) ? obj_sys(t->obj)->src : t->obj->src;
    if (t->obj->mode & 0x4000000) {
        for (la = src->items.next, lb = t->items.next; la != &src->items; la = la->next, lb = lb->next) {
            x = la ? (Item *)((char *)la - 4) : 0;
            y = lb ? (Item *)((char *)lb - 4) : 0;
            if ((x->mode->flags & 0x30) == 0x10) {
                y->level = t->obj->vol;
                t->obj->flags |= 0x4000000;
            }
        }
    }
    for (n = t->groups.next; n != &t->groups; n = n->next) {
        g = n ? (Grp *)((char *)n - 4) : 0;
        for (m = g->items.next; m != &g->items; m = m->next) {
            r = fn_883E2428(m ? (Item *)((char *)m - 4) : 0, t->obj->pan, t->obj->vol);
            if (r && r != 0x24) return r;
        }
    }
    return 0;
}
