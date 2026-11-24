/* Swing_DLL.xex 0x887F2C48: Swing_DLL.xex 0x887F2C48: Unlinks (link id = -1), detaches and deletes every object in the vector at +0x78 and empties it, resets the slots (887EFFD8), empties the byte vector at +0x84, closes and releases the session at +0xA8, clears the active flag and trims the vector at +0x10.
 * /Oc. The first session test is signed (cmpwi), the second unsigned: (int)o->session != 0, then o->session. */
typedef struct Link { char pad[0x1c]; int id; } Link;
typedef struct Obj Obj;
typedef struct ObjVtbl {
    void (*destroy)(Obj *self, int flags);   /* 0x00 */
    void *slot4;
    void (*detach)(Obj *self);               /* 0x08 */
} ObjVtbl;
struct Obj { const ObjVtbl *vt; char pad4[0x60 - 4]; Link *link; /* 0x60 */ };
typedef struct ObjVec { Obj **first; Obj **last; Obj **end; } ObjVec;
typedef struct ByteVec { char *first; char *last; char *end; } ByteVec;
typedef struct Vec204 { void *first; void *last; void *end; } Vec204;
typedef struct Owner {
    char pad[8];
    unsigned char active;   /* 0x08 */
    char pad9[0x10 - 9];
    Vec204 v10;             /* 0x10 */
    char pad1c[0x78 - 0x1c];
    ObjVec objs;            /* 0x78 */
    ByteVec data;           /* 0x84 */
    char pad90[0xa8 - 0x90];
    void *session;          /* 0xa8 */
} Owner;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void fn_887EFFD8(Owner *o);
void ts4_pres_session_clear_88890CB0(void *session);
void ts4_tsu_cleanup_end(void *session);
void ts4_vec204_move_tail_881B9148(Vec204 *v);
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
void fn_887F2C48(Owner *o)
{
    ObjVec *v = &o->objs;
    Obj **it, **end = o->objs.last;
    for (it = v->first; it != end; it++) {
        Obj *p = *it;
        p->link->id = -1;
        p->vt->detach(p);
        p->vt->destroy(p, 1);
    }
    v->last = copy_ptrs(v->last, v->last, v->first);
    fn_887EFFD8(o);
    { ByteVec *d = &o->data; d->last = copy_bytes(d->last, d->last, d->first); }
    if ((int)o->session != 0)
        ts4_pres_session_clear_88890CB0(o->session);
    if (o->session)
        ts4_tsu_cleanup_end(o->session);
    o->session = 0;
    o->active = 0;
    ts4_vec204_move_tail_881B9148(&o->v10);
}
