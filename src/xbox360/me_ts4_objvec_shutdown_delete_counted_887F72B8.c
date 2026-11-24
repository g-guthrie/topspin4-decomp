/* Swing_DLL.xex 0x887F72B8: Swing_DLL.xex 0x887F72B8: Shuts down and deletes every object in the vector at +0x34 (counted index loop, slot re-read after the shutdown call), then empties the vector.
 * /Oc. Hoisted unsigned count, i != n; slots read through o->objs.first[i] (index register first in lwzx). */
typedef struct Obj Obj;
typedef struct ObjVtbl {
    void (*destroy)(Obj *self, int flags);   /* 0x00 */
    void *slots[4];
    void (*shutdown)(Obj *self);             /* 0x14 */
} ObjVtbl;
struct Obj { const ObjVtbl *vt; };
typedef struct ObjVec { Obj **first; Obj **last; Obj **end; } ObjVec;
typedef struct Owner { char pad[0x34]; ObjVec objs; } Owner;
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
static __inline unsigned vec_size(const ObjVec *v) { return v->last - v->first; }
void fn_887F72B8(Owner *o)
{
    ObjVec *v = &o->objs;
    unsigned i, n = vec_size(v);
    for (i = 0; i != n; i++) {
        Obj *p = o->objs.first[i];
        p->vt->shutdown(p);
        p = o->objs.first[i];
        if (p)
            p->vt->destroy(p, 1);
    }
    v->last = copy_ptrs(v->last, v->last, v->first);
}
