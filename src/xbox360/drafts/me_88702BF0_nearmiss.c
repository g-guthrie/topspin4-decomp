/* DRAFT 88702BF0: 3 instructions off (/Oc). The target compares the vector bounds with a signed cmpw (reproduced only with int casts) and loads last before first; the operand order is not reproduced. */
typedef struct Obj Obj;
typedef struct ObjVtbl {
    void (*destroy)(Obj *self, int flags);   /* 0x00 */
    void *slot4;
    void (*detach)(Obj *self);               /* 0x08 */
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
void fn_88702BF0(Owner *o)
{
    ObjVec *v = &o->objs;
    while ((int)v->first != (int)o->objs.last) {
        Obj *p = *v->first;
        p->vt->detach(p);
        p->vt->destroy(p, 1);
    }
    v->last = copy_ptrs(v->last, v->last, v->first);
    o->active = 0;
    ts4_vec204_move_tail_881B9148(&o->v10);
}
