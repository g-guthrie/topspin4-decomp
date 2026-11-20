/* Swing_DLL.xex 0x88912E70: Swing_DLL.xex 0x88912E70: Detaches and deletes the first count objects (+0x24) of the vector at +0x28 and empties it, empties the 64-bit key vector at +0x3C, unregisters the hub reference at +0x1C from its listener (vtable +0x58), clears the active flag and trims the vector at +0x10.
 * /Oc. Hub test in the caller (signed int field), removal in an inline taking &o->hub so the field is reloaded through r4. */
typedef struct Obj Obj;
typedef struct ObjVtbl {
    void (*destroy)(Obj *self, int flags);   /* 0x00 */
    void *slots[2];
    void (*detach)(Obj *self);               /* 0x0c */
} ObjVtbl;
struct Obj { const ObjVtbl *vt; };
typedef struct ObjVec { Obj **first; Obj **last; Obj **end; } ObjVec;
typedef struct KeyVec { unsigned __int64 *first; unsigned __int64 *last; unsigned __int64 *end; } KeyVec;
typedef struct Vec204 { void *first; void *last; void *end; } Vec204;
typedef struct Listener Listener;
typedef struct ListenerVtbl { void *slots[0x58 / 4]; void (*remove)(Listener *self, void *key); /* 0x58 */ } ListenerVtbl;
struct Listener { const ListenerVtbl *vt; };
typedef struct Hub { char pad[4]; Listener *listener; } Hub;
typedef struct HubRef { int hub; } HubRef;   /* holds a Hub * */
static __inline void hubref_remove(HubRef *r)
{
    Listener *l = ((Hub *)r->hub)->listener;
    l->vt->remove(l, r);
}
typedef struct Owner {
    char pad[8];
    unsigned char active;   /* 0x08 */
    char pad9[0x10 - 9];
    Vec204 v10;             /* 0x10 */
    HubRef hub;             /* 0x1c */
    char pad20[4];
    int count;              /* 0x24 */
    ObjVec objs;            /* 0x28 */
    char pad34[0x3c - 0x34];
    KeyVec keys;            /* 0x3c */
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
static __inline unsigned __int64 *copy_keys(unsigned __int64 *first, unsigned __int64 *last, unsigned __int64 *dest)
{
    int n;
    for (n = last - first; 0 < n; --n, ++first, ++dest)
        *dest = *first;
    return dest;
}
void fn_88912E70(Owner *o)
{
    int i;
    ObjVec *v;
    KeyVec *k;
    for (i = 0; i < o->count; i++) {
        Obj *p = o->objs.first[i];
        p->vt->detach(p);
        p->vt->destroy(p, 1);
    }
    v = &o->objs;
    v->last = copy_ptrs(v->last, v->last, v->first);
    k = &o->keys;
    k->last = copy_keys(k->last, k->last, k->first);
    if (o->hub.hub)
        hubref_remove(&o->hub);
    o->active = 0;
    ts4_vec204_move_tail_881B9148(&o->v10);
}
