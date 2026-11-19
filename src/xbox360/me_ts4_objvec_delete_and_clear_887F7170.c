/* Swing_DLL.xex 0x887F7170: Swing_DLL.xex 0x887F7170: Shuts down and deletes every object in the vector at +0x30, empties it and the byte vector at +0x3C, and zeroes the count at +0x1C.
 * /Oc. Counted index loop as 887F72B8, then two forceinline cw4 clears. */
typedef struct Obj Obj;
typedef struct ObjVtbl {
    void (*destroy)(Obj *self, int flags);   /* 0x00 */
    void *slots[4];
    void (*shutdown)(Obj *self);             /* 0x14 */
} ObjVtbl;
struct Obj { const ObjVtbl *vt; };
typedef struct ObjVec { Obj **first; Obj **last; Obj **end; } ObjVec;
typedef struct ByteVec { char *first; char *last; char *end; } ByteVec;
typedef struct Owner { char pad[0x1c]; int count; char pad20[0x30 - 0x20]; ObjVec objs; ByteVec data; } Owner;
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
static __inline unsigned vec_size(const ObjVec *v) { return v->last - v->first; }
static __forceinline char *copy_bytes(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}
void fn_887F7170(Owner *o)
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
    { ByteVec *d = &o->data; d->last = copy_bytes(d->last, d->last, d->first); }
    o->count = 0;
}
