typedef struct Sub Sub;
typedef struct SubVt { char pad[0x10]; void *(*key)(Sub *s); } SubVt;
struct Sub { SubVt *vt; };
typedef struct Obj Obj;
typedef struct ObjVt { char pad[0xc]; void *(*find)(Obj *o, void *x); } ObjVt;
struct Obj { ObjVt *vt; };
typedef struct Mgr Mgr;
typedef struct MgrVt { char pad[0xc]; Obj *(*find)(Mgr *m, void *id); } MgrVt;
struct Mgr { MgrVt *vt; };
typedef struct Pair { int a, b; } Pair;
typedef struct T { char pad[0x20]; Sub sub; char pad2[0x1c]; char set[4]; } T;
Mgr *ts4_get_u32_lbl_88CAC9A8_883E63A0(void);
int fn_883FBA90(void *set, void *x);
int fn_883FC9E8(T *t, void *v, Pair *p, int a);
int fn_883FBEB0(T *t, Pair *p);
int fn_883FBB88(void *set, void *x);
int fn_883FCCC0(T *t, void *x)
{
    void *key = t->sub.vt->key(&t->sub);
    Mgr *m = ts4_get_u32_lbl_88CAC9A8_883E63A0();
    Obj *o = m->vt->find(m, key);
    void *v;
    int r;
    if (!o)
        return 0x21;
    r = fn_883FBA90(t->set, x);
    if (r)
        return r;
    v = o->vt->find(o, x);
    if (v) {
        Pair p;
        p.a = 0;
        p.b = 0;
        r = fn_883FC9E8(t, v, &p, 1);
        if (r)
            return r;
        r = fn_883FBEB0(t, &p);
        if (r)
            return r;
    }
    return fn_883FBB88(t->set, x);
}
