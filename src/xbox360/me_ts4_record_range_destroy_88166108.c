/* Swing_DLL.xex 0x88166108: Destroys [first, last) of 0x28-byte records: empties each record's byte vector at +0x1c (memmove copy idiom) and frees its buffer (ts4_destroy_owned_object).
 * /Oc. The clear must be an inline on &rec->data while the free test reads rec->data.first directly, or the load is scheduled above the store. */
typedef struct ByteVec { char *first; char *last; } ByteVec;
typedef struct Record {
    unsigned char pad[0x1c];
    ByteVec data;       /* 0x1c */
    unsigned char pad24[4];
} Record;   /* 0x28 */
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

void fn_88166108(Record *first, Record *last)
{
    for (; first != last; first++) {
        vec_clear(&first->data);
        if (first->data.first) ts4_destroy_owned_object(first->data.first);
    }
}
