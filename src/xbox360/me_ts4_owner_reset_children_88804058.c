/* Swing_DLL.xex 0x88804058: Swing_DLL.xex 0x88804058: Between the owner's begin/end reset calls (vtable +0x28/+0x2C): detaches (vtable +0xC) and deletes every child in the vector at +0x20, empties it, zeroes the count and empties the 0x20C-byte text vector at +0x30.
 * /Oc. Text elements are copied with ts4_byte_string_assign_881A52D8 in the counted copy loop. */
typedef struct Owner Owner;
typedef struct Obj Obj;
typedef struct ObjVtbl {
    void (*destroy)(Obj *self, int flags);   /* 0x00 */
    void *slots[2];
    void (*detach)(Obj *self, Owner *owner); /* 0x0c */
} ObjVtbl;
struct Obj { const ObjVtbl *vt; };
typedef struct ObjVec { Obj **first; Obj **last; Obj **end; } ObjVec;
typedef struct Text { char data[0x20c]; } Text;
typedef struct TextVec { Text *first; Text *last; Text *end; } TextVec;
typedef struct OwnerVtbl {
    void *slots[0x28 / 4];
    void (*begin_reset)(Owner *self);        /* 0x28 */
    void (*end_reset)(Owner *self);          /* 0x2c */
} OwnerVtbl;
struct Owner {
    const OwnerVtbl *vt;    /* 0x00 */
    char pad4[0x20 - 4];
    ObjVec objs;            /* 0x20 */
    int count;              /* 0x2c */
    TextVec texts;          /* 0x30 */
};
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_byte_string_assign_881A52D8(Text *dst, const Text *src);
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
static __inline Text *copy_texts(Text *first, Text *last, Text *dest)
{
    int n;
    for (n = last - first; 0 < n; --n, ++first, ++dest)
        ts4_byte_string_assign_881A52D8(dest, first);
    return dest;
}
void fn_88804058(Owner *o)
{
    ObjVec *v;
    TextVec *t;
    Obj **it, **end;
    o->vt->begin_reset(o);
    v = &o->objs;
    end = o->objs.last;
    for (it = v->first; end != it; it++) {
        (*it)->vt->detach(*it, o);
        if (*it)
            (*it)->vt->destroy(*it, 1);
    }
    v->last = copy_ptrs(v->last, v->last, v->first);
    o->count = 0;
    t = &o->texts;
    t->last = copy_texts(t->last, t->last, t->first);
    o->vt->end_reset(o);
}
