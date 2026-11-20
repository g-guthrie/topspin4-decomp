/* Swing_DLL.xex 0x8894A840: Swing_DLL.xex 0x8894A840: Zeroes three counters at +0x20, finalizes the object at +0x14 and empties the byte vector at +0x48.
 * /Oc. Same template as 887F95E0. */
typedef struct ByteVec { char *first; char *last; char *end; } ByteVec;
typedef struct Object { int f[3]; } Object;
typedef struct Owner {
    char pad[0x14];
    Object obj;         /* 0x14 */
    int a, b, c;        /* 0x20 */
    char pad2c[0x48 - 0x2c];
    ByteVec data;       /* 0x48 */
} Owner;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_object_finalize(Object *o);
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
void fn_8894A840(Owner *o)
{
    ByteVec *v;
    o->a = 0;
    o->b = 0;
    o->c = 0;
    ts4_object_finalize(&o->obj);
    v = &o->data;
    v->last = copy_bytes(v->last, v->last, v->first);
}
