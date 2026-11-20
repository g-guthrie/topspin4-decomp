/* Swing_DLL.xex 0x8861EDB8: Swing_DLL.xex 0x8861EDB8: Walks the id vector at +0x38 back to front: looks each id up in the registry (88618998), shuts down and deletes the object and unregisters the slot (8860D460), then empties the vector.
 * /Oc. last via o->ids.last, first via the v local; reverse loop keeps the old slot for the compare. */
typedef unsigned int u32;
typedef struct Obj Obj;
typedef struct ObjVtbl {
    void (*destroy)(Obj *self, int flags);   /* 0x00 */
    void *slots[4];
    void (*shutdown)(Obj *self);             /* 0x14 */
} ObjVtbl;
struct Obj { const ObjVtbl *vt; };
typedef struct IdVec { u32 *first; u32 *last; u32 *end; } IdVec;
typedef struct Owner { char pad[0x38]; IdVec ids; } Owner;
extern void *lbl_88D45B38;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
Obj *fn_88618998(void *reg, u32 id);
void fn_8860D460(void *reg, u32 *id);
static __inline u32 *copy_ids(u32 *first, u32 *last, u32 *dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (u32 *)fn_88562DC0(dest, first, n);
        return (u32 *)((char *)dest + n);
    }
}
void fn_8861EDB8(Owner *o)
{
    IdVec *v = &o->ids;
    u32 *last = o->ids.last, *first = v->first;
    if (first != last) {
        u32 *slot = last - 1;
        for (;;) {
            Obj *p = fn_88618998(lbl_88D45B38, *slot);
            if (p) {
                p->vt->shutdown(p);
                p->vt->destroy(p, 1);
                fn_8860D460(lbl_88D45B38, slot);
            }
            {
                u32 *cur = slot;
                slot--;
                if (cur == first)
                    break;
            }
        }
    }
    v->last = copy_ids(v->last, v->last, v->first);
}
