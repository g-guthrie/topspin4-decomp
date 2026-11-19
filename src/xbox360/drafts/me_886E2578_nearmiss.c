/* agK 2026-11-19: top pads 0-7: all 2 (pad-insensitive; residue is scheduling). */
/* agentA2 2026-11-18: still 2 (/Oc): restrict list (4), volatile list stores (10), shared zero local (10), weights_init helper / chained stores give 2 only on LTCG. */
/* NEAR MISS (2 instructions): the game schedules the weight load after the second list store; this
 * source loads it one slot earlier. Tried all orders of the four store groups, local/param forms. */
/* 0x886E2578: constructor: installs the vtable, empties the {begin,end,capacity} list, clears the
 * link words and the owner, and zeroes the two weights (event default value). */
extern char lbl_880F37A4[];
extern float lbl_8814B440;
typedef struct List { void *begin; void *end; void *capacity; } List;
typedef struct Obj { void *vt; void *link0; void *link1; List list; void *owner; float w0; float w1; } Obj;
static __inline void list_init(List *l) { l->begin = 0; l->end = 0; l->capacity = 0; }
static __inline void weights_init(Obj *o, float z) { o->w0 = z; o->w1 = z; }
Obj *f(Obj *o)
{
    float z;
    o->vt = lbl_880F37A4;
    list_init(&o->list);
    z = lbl_8814B440;
    o->w0 = z;
    o->w1 = z;
    o->link0 = 0;
    o->link1 = 0;
    o->owner = 0;
    return o;
}
