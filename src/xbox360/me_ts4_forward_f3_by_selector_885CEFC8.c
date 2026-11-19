/* 0x885CEFC8: forwards (x, y) to vtable slot 3 of the object at +0xC (selector null) or +0x100 (selector non-null), if present. */
/* Matched on /O1 (agAB). Identity inline accessor gives the clrrwi copy; selector is pointer-typed (cmplwi). */
typedef struct Obj { struct Vt *vt; } Obj;
typedef struct Vt { void *f[3]; void (*f3)(Obj *o, void *a, void *b); void (*f4)(Obj *o, void *a, void *b); } Vt;
typedef struct T { char p[0xc]; Obj *a; char p10[0x100 - 0x10]; Obj *b; } T;
static __inline Obj *get(Obj *p) { return p; }
void fn_885CEFC8(T *t, void *which, void *x, void *y)
{
    if (!which) {
        if (t->a)
            get(t->a)->vt->f3(get(t->a), x, y);
    } else {
        if (t->b)
            get(t->b)->vt->f3(get(t->b), x, y);
    }
}
