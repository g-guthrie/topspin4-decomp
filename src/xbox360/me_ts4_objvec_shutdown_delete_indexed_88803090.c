/* Swing_DLL.xex 0x88803090: Swing_DLL.xex 0x88803090: Shuts down and deletes every object in the vector at +0x90 (indexed, re-reading the slot after the shutdown call), empties the vector and zeroes the count at +0x9C.
 * /Oc. Iterator and index advance together; slot read through v->first[i] twice. */
typedef struct Obj Obj;
typedef struct ObjVtbl {
    void (*destroy)(Obj *self, int flags);   /* 0x00 */
    void *slots[4];
    void (*shutdown)(Obj *self);             /* 0x14 */
} ObjVtbl;
struct Obj { const ObjVtbl *vt; };
typedef struct ObjVec { Obj **first; Obj **last; Obj **end; } ObjVec;
typedef struct Owner { char pad[0x90]; ObjVec objs; int count; } Owner;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
static __forceinline Obj **copy_ptrs(Obj **first, Obj **last, Obj **dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (Obj **)fn_88562DC0(dest, first, n);
        return (Obj **)((char *)dest + n);
    }
}
void fn_88803090(Owner *o)
{
    ObjVec *v = &o->objs;
    Obj **it, **end = o->objs.last;
    int i = 0;
    for (it = v->first; end != it; it++, i++) {
        Obj *p = v->first[i];
        p->vt->shutdown(p);
        p = v->first[i];
        if (p)
            p->vt->destroy(p, 1);
    }
    v->last = copy_ptrs(v->last, v->last, v->first);
    o->count = 0;
}
