/* Swing_DLL.xex 0x8825D270: Swing_DLL.xex 0x8825D270: For each 0xB0-byte record in [first, last), empties its three byte vectors (+0x50, +0x34, +0x18, reverse member order).
 * /Oc. cw4 copy_bytes forceinline clear, as 882196D8. */
typedef struct ByteVec { char *first; char *last; } ByteVec;
typedef struct Record {
    unsigned char pad[0x18];
    ByteVec a;          /* 0x18 */
    unsigned char pad20[0x34 - 0x20];
    ByteVec b;          /* 0x34 */
    unsigned char pad3c[0x50 - 0x3c];
    ByteVec c;          /* 0x50 */
    unsigned char pad58[0xb0 - 0x58];
} Record;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
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
void fn_8825D270(Record *first, Record *last)
{
    for (; first != last; first++) {
        vec_clear(&first->c);
        vec_clear(&first->b);
        vec_clear(&first->a);
    }
}
