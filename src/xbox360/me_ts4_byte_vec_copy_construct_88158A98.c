/* Swing_DLL.xex 0x88158A98: vector<unsigned char> copy constructor: zero, allocate size(src), memmove the bytes.
 * /Oc. Copy-ctor template with the end zero store through the end-slot pointer (plain stores are 6 off). */
typedef unsigned char Byte;
typedef struct ByteVec { Byte *first; Byte *last; Byte *end; } ByteVec;
Byte *ts4_if_call_seq_u32_lbl_88D45B38_88150878(Byte **owner, unsigned int n);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);

static __inline Byte *byte_ucopy(const Byte *first, const Byte *last, Byte *dest)
{
    unsigned int bytes;
    if (last == first) return dest;
    bytes = (const char *)last - (const char *)first;
    return (Byte *)((char *)fn_88562DC0(dest, first, bytes) + bytes);
}

static __inline void byte_vec_copy(ByteVec *v, const ByteVec *src)
{
    unsigned int n = src->last - src->first;
    Byte **end_slot = &v->end;
    Byte *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88150878(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
    v->last = byte_ucopy(src->first, src->last, v->first);
}

ByteVec *fn_88158A98(ByteVec *t, const ByteVec *src)
{
    byte_vec_copy(t, src);
    return t;
}
