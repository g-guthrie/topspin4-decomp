/* 0x88464D78 near miss (agW, /Oc): 1 off, lwzx operand order (r10,r9 vs target r9,r10), the open lwzx class. */
/* Calls vtable slot 0x14 of the sub-object at c+0x10 with items[i]. */
typedef struct S S;
typedef struct { void *s[5]; int (*f14)(S *, int); } SVt;
struct S { SVt *vt; };
typedef struct { char pad[0x10]; S sub; } C;
typedef struct { int pad[3]; C *c; int *items; } O;
int ts4_sub10_vcall14_idx_88464D78(O *o, int i)
{
    S *s = &o->c->sub;
    return s->vt->f14(s, o->items[i]);
}
