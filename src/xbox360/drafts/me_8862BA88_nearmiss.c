/* nearmiss (q5s 2026-11-24): 2 off; objs.last/first load order; tried for_each functor temp, Manager::Release begin()/end(), decl orders, while, pads 0-9 */
/* DRAFT 8862BA88: 2 instructions off (/Oc). Only the load order of objs.first/objs.last differs; the vector sits at offset 0, so the o->last / v->first trick does not apply. */
typedef struct Obj Obj;
typedef struct ObjVtbl { void (*destroy)(Obj *self, int flags); } ObjVtbl;
struct Obj { const ObjVtbl *vt; };
typedef struct ObjVec { Obj **first; Obj **last; Obj **end; } ObjVec;
typedef struct Manager {
    ObjVec objs;        /* 0x00 */
    char padc[0x10 - 0xc];
    Obj *owner;         /* 0x10 */
} Manager;
extern Manager *lbl_88D45B20;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_destroy_owned_object(void *obj);
void ts4_tsu_cleanup_end(void *p);
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
void fn_8862BA88(void)
{
    Manager *m = lbl_88D45B20;
    if (m) {
        Obj **it, **end = m->objs.last;
        for (it = m->objs.first; it != end; it++) {
            if (*it)
                (*it)->vt->destroy(*it, 1);
        }
        m->objs.last = copy_ptrs(m->objs.last, m->objs.last, m->objs.first);
        if (m->owner)
            m->owner->vt->destroy(m->owner, 1);
        if (m->objs.first)
            ts4_destroy_owned_object(m->objs.first);
        ts4_tsu_cleanup_end(m);
    }
    lbl_88D45B20 = 0;
}
