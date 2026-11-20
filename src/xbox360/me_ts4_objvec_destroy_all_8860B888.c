/* Swing_DLL.xex 0x8860B888: Swing_DLL.xex 0x8860B888: Destroys the objects in the vector at +0x74 from back to front (vtable 0x14 shutdown, then deleting destructor with flag 1), then empties the vector.
 * /Oc. Read *(it - 1) and decrement afterwards; *--it gives lwzu. */
typedef struct Obj Obj;
typedef struct ObjVtbl {
    void (*destroy)(Obj *self, int flags);   /* 0x00 */
    void *slots[4];
    void (*shutdown)(Obj *self);             /* 0x14 */
} ObjVtbl;
struct Obj { const ObjVtbl *vt; };
typedef struct ObjVec { Obj **first; Obj **last; Obj **end; } ObjVec;
typedef struct Owner { char pad[0x74]; ObjVec objs; } Owner;
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
void fn_8860B888(Owner *o)
{
    ObjVec *v = &o->objs;
    Obj **it = o->objs.last, **first = o->objs.first;
    while (it != first) {
        Obj *p = *(it - 1);
        p->vt->shutdown(p);
        p->vt->destroy(p, 1);
        it--;
    }
    v->last = copy_ptrs(v->last, v->last, v->first);
}
