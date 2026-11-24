/* agBA near-miss, 1 off: cmplw operands swapped on the *b == o->b test (target cmplw r8(o->b), r9(*b)). /Oc plain. */

typedef struct Obj Obj;
typedef struct { void (*f0)(Obj*,int); } Vt;
struct Obj { Vt *vt; unsigned a; unsigned b; unsigned c; };
typedef struct { Obj **first; Obj **last; } Vec;
typedef struct { char pad[0x14]; Vec v; } Mgr;
Obj **ts4_vec_erase_one_881AAE10(Vec *v, Obj **it);
int fn_88912118(Mgr *m, unsigned a, unsigned *b, unsigned c)
{
    Obj **it;
    Vec *v = &m->v;
    int r = 0;
    for (it = v->first; it != v->last; it++) {
        Obj *o = *it;
        if (o->a == a && *b == o->b && o->c == c) {
            o->vt->f0(o, 1);
            ts4_vec_erase_one_881AAE10(v, it);
            r = 1;
            break;
        }
    }
    return r;
}
