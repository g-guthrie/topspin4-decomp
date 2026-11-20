/* Swing_DLL.xex 0x88800550: Swing_DLL.xex 0x88800550: Clears the active flag, trims the vector at +0x10, shuts down (vtable +0x14) and deletes (vtable 0, flag 1) every object in the vector at +0x1C, then empties it.
 * /Oc. Loop test written end != it for the cmplw operand order. */
typedef struct Obj Obj;
typedef struct ObjVtbl {
    void (*destroy)(Obj *self, int flags);   /* 0x00 */
    void *slots[4];
    void (*shutdown)(Obj *self);             /* 0x14 */
} ObjVtbl;
struct Obj { const ObjVtbl *vt; };
typedef struct ObjVec { Obj **first; Obj **last; Obj **end; } ObjVec;
typedef struct Vec204 { void *first; void *last; void *end; } Vec204;
typedef struct Owner {
    char pad[8];
    unsigned char active;   /* 0x08 */
    char pad9[0x10 - 9];
    Vec204 v10;             /* 0x10 */
    ObjVec objs;            /* 0x1c */
} Owner;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_vec204_move_tail_881B9148(Vec204 *v);
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
void fn_88800550(Owner *o)
{
    ObjVec *v;
    Obj **it, **end;
    o->active = 0;
    ts4_vec204_move_tail_881B9148(&o->v10);
    v = &o->objs;
    end = o->objs.last;
    for (it = v->first; end != it; it++) {
        (*it)->vt->shutdown(*it);
        if (*it)
            (*it)->vt->destroy(*it, 1);
    }
    v->last = copy_ptrs(v->last, v->last, v->first);
}
