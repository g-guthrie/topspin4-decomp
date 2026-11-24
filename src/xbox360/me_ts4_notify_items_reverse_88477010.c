/* 0x88477010: walks the item pointer array at +0x8C from count (+0x90) - 1 down to 0 and calls vtable slot 4 (item, t) on each non-null item. */
/* Matched on /Oc (agAB). Identity inline accessor around the reloaded element gives the clrrwi copy (CL1 rule). */
typedef struct Obj { struct Vt *vt; } Obj;
typedef struct T T;
typedef struct Vt { void *f[4]; void (*notify)(Obj *o, T *t); } Vt;
struct T { char p[0x8c]; Obj **items; int n; };
static __inline Obj *get(Obj *p) { return p; }
void fn_88477010(T *t)
{
    int i;
    for (i = t->n - 1; i >= 0; i--) {
        if (t->items[i]) {
            Obj *o = get(t->items[i]);
            o->vt->notify(o, t);
        }
    }
}
