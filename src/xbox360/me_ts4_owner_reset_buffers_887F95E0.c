/* Swing_DLL.xex 0x887F95E0: Swing_DLL.xex 0x887F95E0: Zeroes three counters, finalizes the object at +0x14, trims the two 12-byte vectors (+0x44, +0x38) and empties the byte vector at +0x2c.
 * /Oc. Non-forceinline copy_bytes (equal path stores first). */
typedef struct ByteVec { char *first; char *last; char *end; } ByteVec;
typedef struct Vec12 { void *first; void *last; void *end; } Vec12;
typedef struct Object { int f[3]; } Object;
typedef struct Owner {
    char pad[0x14];
    Object obj;         /* 0x14 */
    int a, b, c;        /* 0x20 */
    ByteVec data;       /* 0x2c */
    Vec12 v38;          /* 0x38 */
    Vec12 v44;          /* 0x44 */
} Owner;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_object_finalize(Object *o);
void ts4_vec12_move_tail_88161620(Vec12 *v);
static __inline char *copy_bytes(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}
void fn_887F95E0(Owner *o)
{
    ByteVec *v;
    o->a = 0;
    o->b = 0;
    o->c = 0;
    ts4_object_finalize(&o->obj);
    ts4_vec12_move_tail_88161620(&o->v44);
    ts4_vec12_move_tail_88161620(&o->v38);
    v = &o->data;
    v->last = copy_bytes(v->last, v->last, v->first);
}
