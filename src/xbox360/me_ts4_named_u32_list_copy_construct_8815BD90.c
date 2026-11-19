/* Swing_DLL.xex 0x8815BD90: copy constructor of {flag byte; two texts (88159A58); id; vector<unsigned int> (memmove)}.
 * /Oc. Aggregate copy-ctor template: member copies, then an inlined vector copy (end zero store through the end-slot pointer). */
typedef struct Text { char *p; char *last; char *end; } Text;
typedef unsigned int U32;
typedef struct U32Vec { U32 *first; U32 *last; U32 *end; } U32Vec;
U32 *ts4_if_call_seq_u32_lbl_88D45B38_88162340(U32 **owner, unsigned int n);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_if_call_seq_u32_off0_88159A58(Text *dst, const Text *src);
typedef struct NamedU32List { unsigned char flag; Text name; Text label; unsigned int id; U32Vec items; } NamedU32List;

static __inline U32 *u32_ucopy(const U32 *first, const U32 *last, U32 *dest)
{
    unsigned int bytes;
    if (last == first) return dest;
    bytes = (const char *)last - (const char *)first;
    return (U32 *)((char *)fn_88562DC0(dest, first, bytes) + bytes);
}

static __inline void u32_vec_copy(U32Vec *v, const U32Vec *src)
{
    unsigned int n = src->last - src->first;
    U32 **end_slot = &v->end;
    U32 *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88162340(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
    v->last = u32_ucopy(src->first, src->last, v->first);
}

NamedU32List *fn_8815BD90(NamedU32List *t, const NamedU32List *src)
{
    t->flag = src->flag;
    ts4_if_call_seq_u32_off0_88159A58(&t->name, &src->name);
    ts4_if_call_seq_u32_off0_88159A58(&t->label, &src->label);
    t->id = src->id;
    u32_vec_copy(&t->items, &src->items);
    return t;
}
