/* 0x887F7588: polls every item in the vector at +0x30 (vslot 3 = busy test, vslot 4 = step), bumps the
 * counter at o->+0x28->+4, then runs vslot 3 on every item of the vector at +0x3c. Returns 1 if any item was busy. */
typedef unsigned int u32; typedef unsigned char u8;
typedef struct Item Item;
typedef struct { void *s0, *s1, *s2; u8 (*busy)(Item *); void (*step)(Item *); } ItemVt;
struct Item { ItemVt *vt; };
typedef struct { Item **first, **last; } Vec;
typedef struct { char p[4]; int n; } Ctr;
typedef struct { char p[0x28]; Ctr *ctr; char p2c[4]; Vec a; char p38[4]; Vec b; } O;
u8 ts4_sim_items_tick_887F7588(O *o) {
    u8 any = 0;
    u32 i, n;
    n = o->a.last - o->a.first;
    for (i = 0; i < n; i++) {
        any = o->a.first[i]->vt->busy(o->a.first[i]) || any;
        o->a.first[i]->vt->step(o->a.first[i]);
    }
    o->ctr->n++;
    n = o->b.last - o->b.first;
    for (i = 0; i < n; i++) o->b.first[i]->vt->busy(o->b.first[i]);
    return any;
}
