/* Swing_DLL.xex 0x886099A8: Swing_DLL.xex 0x886099A8: Stops the four owned objects (88607938 on the first two, 886078B0 on the last two), empties the byte vectors at +0x10/+0x1C, then deletes all four objects.
 * /Oc. Inline obj_delete and forceinline cw4 clears. */
typedef struct Obj Obj;
typedef struct ObjVtbl { void (*destroy)(Obj *self, int flags); } ObjVtbl;
struct Obj { const ObjVtbl *vt; };
typedef struct ByteVec { char *first; char *last; char *end; } ByteVec;
typedef struct Owner {
    Obj *a;         /* 0x00 */
    Obj *b;         /* 0x04 */
    Obj *c;         /* 0x08 */
    Obj *d;         /* 0x0c */
    ByteVec v1;     /* 0x10 */
    ByteVec v2;     /* 0x1c */
} Owner;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void fn_88607938(Obj *o);
void fn_886078B0(Obj *o);
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
static __inline void vec_clear(ByteVec *v) { v->last = copy_bytes(v->last, v->last, v->first); }
static __inline void obj_delete(Obj *p) { if (p) p->vt->destroy(p, 1); }
void fn_886099A8(Owner *o)
{
    fn_88607938(o->a);
    fn_88607938(o->b);
    fn_886078B0(o->c);
    fn_886078B0(o->d);
    vec_clear(&o->v1);
    vec_clear(&o->v2);
    obj_delete(o->a);
    obj_delete(o->b);
    obj_delete(o->c);
    obj_delete(o->d);
}
