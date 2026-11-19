/* Swing_DLL.xex 0x88166BC0: vector<unsigned int> copy constructor: zero, allocate size(src), memmove the words.
 * /Oc. Copy-ctor template (end zero store through the end-slot pointer); memmove guard written last == first. */
typedef struct U32Vec { unsigned int *first; unsigned int *last; unsigned int *end; } U32Vec;
unsigned int *ts4_if_call_seq_u32_lbl_88D45B38_88162340(unsigned int **owner, unsigned int n);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);

static __inline unsigned int *u32_ucopy(const unsigned int *first, const unsigned int *last, unsigned int *dest)
{
    unsigned int bytes;
    if (last == first) return dest;
    bytes = (const char *)last - (const char *)first;
    return (unsigned int *)((char *)fn_88562DC0(dest, first, bytes) + bytes);
}

static __inline void u32_vec_construct_n(U32Vec *v, unsigned int n)
{
    unsigned int **end_slot = &v->end;
    unsigned int *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88162340(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
}

U32Vec *fn_88166BC0(U32Vec *v, const U32Vec *src)
{
    u32_vec_construct_n(v, src->last - src->first);
    v->last = u32_ucopy(src->first, src->last, v->first);
    return v;
}
