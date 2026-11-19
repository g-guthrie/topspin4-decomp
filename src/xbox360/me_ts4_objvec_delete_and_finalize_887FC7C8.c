/* Swing_DLL.xex 0x887FC7C8: Swing_DLL.xex 0x887FC7C8: Shuts down and deletes every object in the vector at +0x2C, empties it and the byte vector at +0x68, then runs the owner finalizer (887FC600).
 * /Oc. Same template as 887F7170. */
typedef struct Obj Obj;
typedef struct ObjVtbl {
    void (*destroy)(Obj *self, int flags);   /* 0x00 */
    void *slots[4];
    void (*shutdown)(Obj *self);             /* 0x14 */
} ObjVtbl;
struct Obj { const ObjVtbl *vt; };
typedef struct ObjVec { Obj **first; Obj **last; Obj **end; } ObjVec;
typedef struct ByteVec { char *first; char *last; char *end; } ByteVec;
typedef struct Owner { char pad[0x2c]; ObjVec objs; char pad38[0x68 - 0x38]; ByteVec data; } Owner;
void ts4_call_seq_ts4_object_finalize_887FC600(Owner *o);
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
void fn_887FC7C8(Owner *o)
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
    ts4_call_seq_ts4_object_finalize_887FC600(o);
}
