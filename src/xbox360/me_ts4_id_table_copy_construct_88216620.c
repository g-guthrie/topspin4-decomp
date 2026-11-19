/* Swing_DLL.xex 0x88216620: copy constructor: u32 vector (memmove copy) followed by 100- and 512-byte arrays copied with memcpy.
 * /Oc. Vector part as 88166C58; the memmove guard is written last == first for the cmplw order. */
typedef struct U32Vec { unsigned int *first; unsigned int *last; unsigned int *end; } U32Vec;
typedef struct IdTable { U32Vec ids; unsigned char head[100]; unsigned char body[512]; } IdTable;
unsigned int *ts4_if_call_seq_u32_lbl_88D45B38_88162340(unsigned int **owner, unsigned int n);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void *memcpy(void *dst, const void *src, unsigned int n);

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

IdTable *fn_88216620(IdTable *t, const IdTable *src)
{
    u32_vec_construct_n(&t->ids, src->ids.last - src->ids.first);
    t->ids.last = u32_ucopy(src->ids.first, src->ids.last, t->ids.first);
    memcpy(t->head, src->head, sizeof(t->head));
    memcpy(t->body, src->body, sizeof(t->body));
    return t;
}
