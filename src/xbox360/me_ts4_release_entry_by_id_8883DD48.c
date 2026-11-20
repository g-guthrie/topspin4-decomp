/* 0x8883DD48: finds the object with id (+0x184) in the pointer vector at +0x20/+0x24 and, when its sub-object at +0x80 holds a handle (+0x8C), releases it through fn_889254C8(sub, 1). */
/* Matched on /Oc (agAB). The release is an inline helper on &o->sub that re-tests the handle (clrrwi copy); end hoisted into a local. */
typedef struct Sub { char p[0xc]; void *h; } Sub;
typedef struct O { char p[0x80]; Sub sub; char p90[0x184 - 0x90]; int id; } O;
typedef struct T { char p[0x20]; O **begin; O **end; } T;
void fn_889254C8(Sub *sub, int a);
static void sub_release(Sub *s) { if (s->h) fn_889254C8(s, 1); }
void fn_8883DD48(T *t, int id)
{
    O **it, **end = t->end;
    for (it = t->begin; it != end; it++) {
        O *o = *it;
        if (o->id == id) {
            if (o->sub.h)
                sub_release(&o->sub);
            return;
        }
    }
}
