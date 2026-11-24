/* nearmiss: 3 off (q5s batch 2); r9/r10 swap between the first lbz and addi rX,r3,8. Member-wise copy, ctor with init list or body all stay at 3; copying sub first or via a local gives 49+; a base-class head turns it into a block-copy loop (52). Blocker: the order of the byte/word head copies and the sub-object copy is still unknown. */
/* Swing_DLL.xex 0x881BC130: copy constructor of {three bytes; word; 16-byte block; vector<unsigned int>}.
 * /Oc near miss, 3 off: r9/r10 swapped between the first byte copy and the &t->sub address (block struct assignment is needed for the address; member copies give 49 off). */
typedef struct Text { char *p; char *last; char *end; } Text;
typedef unsigned int U32;
typedef struct U32Vec { U32 *first; U32 *last; U32 *end; } U32Vec;
U32 *ts4_if_call_seq_u32_lbl_88D45B38_88162340(U32 **owner, unsigned int n);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_if_call_seq_u32_off0_88159A58(Text *dst, const Text *src);
typedef struct Quad { unsigned int w[4]; } Quad;
typedef struct U32List { unsigned char a; unsigned char b; unsigned char c; unsigned int d; Quad sub; U32Vec items; } U32List;

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

U32List *fn_881BC130(U32List *t, const U32List *src)
{
    t->a = src->a;
    t->b = src->b;
    t->c = src->c;
    t->d = src->d;
    t->sub = src->sub;
    u32_vec_copy(&t->items, &src->items);
    return t;
}
