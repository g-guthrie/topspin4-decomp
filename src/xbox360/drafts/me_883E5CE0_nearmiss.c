typedef struct Obj Obj;
typedef struct ObjVt { char pad[8]; void *(*get)(Obj *o); } ObjVt;
struct Obj { ObjVt *vt; };
typedef struct T T;
typedef struct TVt {
    char pad[0x10];
    int (*f10)(T *t, void *h, void *a);
    char pad2[0xc];
    int (*f20)(T *t, void **out, void *key);
} TVt;
struct T { TVt *vt; };
int fn_883E5CE0(T *t, void *a, Obj *o)
{
    void *h;
    int r;
    if (o)
        r = t->vt->f20(t, &h, o->vt->get(o));
    else
        r = t->vt->f20(t, &h, 0);
    if (!r)
        r = t->vt->f10(t, h, a);
    return r;
}
