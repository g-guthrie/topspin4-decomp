/* 0x887F7828: when the state byte at +0x42 is 1, calls vtable slot 2 on every object of the pointer vector at +0x34/+0x38 and clears the active byte at +0x40. */
/* Matched on /Oc (agAF). agZ loop-body base local (Obj **it = t->begin) gives the index-first lwzx. */
typedef struct Obj Obj;
typedef struct ObjVt { void *f[2]; void (*stop)(Obj *o); } ObjVt;
struct Obj { ObjVt *vt; };
typedef struct T { char p[0x34]; Obj **begin; Obj **end; char p3c[4]; unsigned char active; char p41; unsigned char state; } T;
void fn_887F7828(T *t)
{
    if (t->state == 1) {
        unsigned int i, n = t->end - t->begin;
        for (i = 0; i < n; i++) {
            Obj **it = t->begin;
            it[i]->vt->stop(it[i]);
        }
        t->active = 0;
    }
}
