/* DRAFT (3 instructions off on /Oc): Swing_DLL.xex 0x8827B810, destroys [first, last) of 0x1C-byte records with two byte vectors
 * (clear a, clear b, free b, free a). Only the load order in the second inline clear differs (the target loads last before first). */
typedef struct ByteVec { char *first; char *last; } ByteVec;
typedef struct Record {
    unsigned int id;    /* 0x00 */
    ByteVec a;          /* 0x04 */
    unsigned char pad0c[4];
    ByteVec b;          /* 0x10 */
    unsigned char pad18[4];
} Record;   /* 0x1c */
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_destroy_owned_object(void *obj);

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

void fn_8827B810(Record *first, Record *last)
{
    for (; first != last; first++) {
        first->id = 0;
        vec_clear(&first->a);
        vec_clear(&first->b);
        if (first->b.first) ts4_destroy_owned_object(first->b.first);
        if (first->a.first) ts4_destroy_owned_object(first->a.first);
    }
}
