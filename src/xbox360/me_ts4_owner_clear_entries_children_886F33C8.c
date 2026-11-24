/* Swing_DLL.xex 0x886F33C8: Swing_DLL.xex 0x886F33C8: Releases (vtable +8) every 0x2C-byte entry at +0x44 and erases them (88226E30), sets state 1 and flushes the owner (vtable +0x38/+0x4C), detaches and deletes every child in the vector at +0x24, empties it and zeroes the count at +0x34.
 * /Oc. Both loops: end via the owner field, begin via the vector local. */
typedef struct Owner Owner;
typedef struct Entry Entry;
typedef struct EntryVtbl { void *slots[2]; void (*release)(Entry *self); /* 0x08 */ } EntryVtbl;
struct Entry { const EntryVtbl *vt; char pad4[0x2c - 4]; };   /* 0x2c */
typedef struct EntryVec { Entry *first; Entry *last; Entry *end; } EntryVec;
typedef struct Obj Obj;
typedef struct ObjVtbl {
    void (*destroy)(Obj *self, int flags);   /* 0x00 */
    void *slot4;
    void (*detach)(Obj *self);               /* 0x08 */
} ObjVtbl;
struct Obj { const ObjVtbl *vt; };
typedef struct ObjVec { Obj **first; Obj **last; Obj **end; } ObjVec;
typedef struct OwnerVtbl {
    void *slots[0x38 / 4];
    void (*set_state)(Owner *self, int on);  /* 0x38 */
    void *slots3c[(0x4c - 0x3c) / 4];
    void (*flush)(Owner *self);              /* 0x4c */
} OwnerVtbl;
struct Owner {
    const OwnerVtbl *vt;    /* 0x00 */
    char pad4[0x24 - 4];
    ObjVec children;        /* 0x24 */
    char pad30[4];
    int count;              /* 0x34 */
    char pad38[0x44 - 0x38];
    EntryVec entries;       /* 0x44 */
};
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
Entry *ts4_dc2c_erase_88226E30(EntryVec *v, Entry *first, Entry *last);
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
void fn_886F33C8(Owner *o)
{
    EntryVec *ev = &o->entries;
    ObjVec *v;
    Entry *e, *eend = o->entries.last;
    Obj **it, **end;
    for (e = ev->first; e != eend; e++)
        e->vt->release(e);
    ts4_dc2c_erase_88226E30(ev, ev->first, ev->last);
    o->vt->set_state(o, 1);
    o->vt->flush(o);
    v = &o->children;
    end = o->children.last;
    for (it = v->first; it != end; it++) {
        Obj *p = *it;
        p->vt->detach(p);
        p->vt->destroy(p, 1);
    }
    v->last = copy_ptrs(v->last, v->last, v->first);
    o->count = 0;
}
