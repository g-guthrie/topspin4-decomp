/* Swing_DLL.xex 0x8890DDA8: Swing_DLL.xex 0x8890DDA8: Unless the entry has a non-empty name: zeroes the three counters at +0x8, empties the byte vector at +0x38 and resets the index at +0x14 (finalize, empty its two 64-bit vectors).
 * /Oc. Inline index_reset on &o->index. */
typedef struct ByteVec { char *first; char *last; char *end; } ByteVec;
typedef struct KeyVec { unsigned __int64 *first; unsigned __int64 *last; unsigned __int64 *end; } KeyVec;
typedef struct Object { int f[3]; } Object;
typedef struct Index { Object obj; KeyVec keys; KeyVec values; } Index;   /* 0x24 */
typedef struct Owner {
    char pad[4];
    const char *name;       /* 0x04 */
    int a, b, c;            /* 0x08 */
    Index index;            /* 0x14 */
    ByteVec data;           /* 0x38 */
} Owner;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_object_finalize(Object *o);
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
static __inline unsigned __int64 *copy_keys(unsigned __int64 *first, unsigned __int64 *last, unsigned __int64 *dest)
{
    int n;
    for (n = last - first; 0 < n; --n, ++first, ++dest)
        *dest = *first;
    return dest;
}
static __inline void keys_clear(KeyVec *k) { k->last = copy_keys(k->last, k->last, k->first); }
static __inline void index_reset(Index *x)
{
    ts4_object_finalize(&x->obj);
    keys_clear(&x->keys);
    keys_clear(&x->values);
}
void fn_8890DDA8(Owner *o)
{
    ByteVec *v;
    if (o->name && *o->name)
        return;
    o->a = 0;
    o->b = 0;
    o->c = 0;
    v = &o->data;
    v->last = copy_bytes(v->last, v->last, v->first);
    index_reset(&o->index);
}
