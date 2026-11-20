/* Swing_DLL.xex 0x88935D10: Swing_DLL.xex 0x88935D10: Stops the owner (vtable +0x34), shuts down every object in the vector at +0x20 and empties it, deletes and clears the worker (+0x44) and helper (+0x40), zeroes the pending count and active flag, trims the vector at +0x10.
 * /Oc. Loop end re-read via o->objs.last, begin via v. */
typedef struct Obj Obj;
typedef struct ObjVtbl {
    void (*destroy)(Obj *self, int flags);   /* 0x00 */
    void *slots[4];
    void (*shutdown)(Obj *self);             /* 0x14 */
} ObjVtbl;
struct Obj { const ObjVtbl *vt; };
typedef struct ObjVec { Obj **first; Obj **last; Obj **end; } ObjVec;
typedef struct Vec204 { void *first; void *last; void *end; } Vec204;
typedef struct Owner Owner;
typedef struct OwnerVtbl { void *slots[0x34 / 4]; void (*stop)(Owner *self); /* 0x34 */ } OwnerVtbl;
struct Owner {
    const OwnerVtbl *vt;    /* 0x00 */
    char pad4[4];
    unsigned char active;   /* 0x08 */
    char pad9[0x10 - 9];
    Vec204 v10;             /* 0x10 */
    char pad1c[4];
    ObjVec objs;            /* 0x20 */
    char pad2c[0x3c - 0x2c];
    int pending;            /* 0x3c */
    Obj *helper;            /* 0x40 */
    Obj *worker;            /* 0x44 */
};
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_vec204_move_tail_881B9148(Vec204 *v);
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
void fn_88935D10(Owner *o)
{
    ObjVec *v;
    Obj **it;
    o->vt->stop(o);
    v = &o->objs;
    for (it = v->first; it != o->objs.last; it++)
        (*it)->vt->shutdown(*it);
    v->last = copy_ptrs(v->last, v->last, v->first);
    if (o->worker)
        o->worker->vt->destroy(o->worker, 1);
    o->worker = 0;
    o->pending = 0;
    if (o->helper)
        o->helper->vt->destroy(o->helper, 1);
    o->helper = 0;
    o->active = 0;
    ts4_vec204_move_tail_881B9148(&o->v10);
}
