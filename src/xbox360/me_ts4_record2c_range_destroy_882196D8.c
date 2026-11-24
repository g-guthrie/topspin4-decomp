/* Swing_DLL.xex 0x882196D8: Destroys [first, last) of 0x2C-byte records: empties each record's byte vector at +0xC and frees its buffer (ts4_destroy_owned_object).
 * /Oc. Same template as 88166108 (inline clear on &rec->data, direct first test). */
typedef struct ByteVec { char *first; char *last; } ByteVec;
typedef struct Record {
    unsigned char pad[0xc];
    ByteVec data;       /* 0x0c */
    unsigned char pad14[0x2c - 0x14];
} Record;   /* 0x2c */
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

void fn_882196D8(Record *first, Record *last)
{
    for (; first != last; first++) {
        vec_clear(&first->data);
        if (first->data.first) ts4_destroy_owned_object(first->data.first);
    }
}
