/* Swing_DLL.xex 0x886EDCB8: Swing_DLL.xex 0x886EDCB8: Shuts down and deletes every object in the vector at +0x0 and every binding's object (+0x10 of each 0x14-byte binding at +0x20), empties the binding vector (struct-assign copy) and the object vector.
 * /Oc. Loop tests written end != it; binding object re-read into a local for the delete (avoids a clrrwi copy). */
typedef struct Obj Obj;
typedef struct ObjVtbl {
    void (*destroy)(Obj *self, int flags);   /* 0x00 */
    void *slots[4];
    void (*shutdown)(Obj *self);             /* 0x14 */
} ObjVtbl;
struct Obj { const ObjVtbl *vt; };
typedef struct ObjVec { Obj **first; Obj **last; Obj **end; } ObjVec;
typedef struct Binding { int key[4]; Obj *obj; } Binding;   /* 0x14 */
typedef struct BindingVec { Binding *first; Binding *last; Binding *end; } BindingVec;
typedef struct Owner {
    ObjVec objs;            /* 0x00 */
    char padc[0x20 - 0xc];
    BindingVec bindings;    /* 0x20 */
} Owner;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
static __inline Obj **copy_ptrs(Obj **first, Obj **last, Obj **dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (Obj **)fn_88562DC0(dest, first, n);
        return (Obj **)((char *)dest + n);
    }
}
static __inline Binding *copy_bindings(Binding *first, Binding *last, Binding *dest)
{
    int n;
    for (n = last - first; 0 < n; --n, ++first, ++dest)
        *dest = *first;
    return dest;
}
void fn_886EDCB8(Owner *o)
{
    Obj **it, **end = o->objs.last;
    BindingVec *bv;
    Binding *b, *bend;
    for (it = o->objs.first; end != it; it++) {
        (*it)->vt->shutdown(*it);
        if (*it)
            (*it)->vt->destroy(*it, 1);
    }
    bv = &o->bindings;
    bend = o->bindings.last;
    for (b = bv->first; bend != b; b++) {
        Obj *p;
        b->obj->vt->shutdown(b->obj);
        p = b->obj;
        if (p)
            p->vt->destroy(p, 1);
    }
    bv->last = copy_bindings(bv->last, bv->last, bv->first);
    o->objs.last = copy_ptrs(o->objs.last, o->objs.last, o->objs.first);
}
