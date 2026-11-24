/* Swing_DLL.xex 0x8815BCA8: copy constructor of {flag byte; two texts (88159A58); vector<12-byte POD>}.
 * /Oc. Aggregate copy-ctor template: member copies, then an inlined vector copy (end zero store through the end-slot pointer). */
typedef struct Text { char *p; char *last; char *end; } Text;
typedef struct Elem12 { unsigned int a; unsigned int b; unsigned int c; } Elem12;
typedef struct Elem12Vec { Elem12 *first; Elem12 *last; Elem12 *end; } Elem12Vec;
Elem12 *ts4_if_call_seq_u32_lbl_88D45B38_88263C98(Elem12 **owner, unsigned int n);
void ts4_if_call_seq_u32_off0_88159A58(Text *dst, const Text *src);
typedef struct NamedElem12List { unsigned char flag; Text name; Text label; Elem12Vec items; } NamedElem12List;

static __inline Elem12 *elem12_ucopy(const Elem12 *first, const Elem12 *last, Elem12 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) *dest = *first;
    return dest;
}

static __inline void elem12_vec_copy(Elem12Vec *v, const Elem12Vec *src)
{
    unsigned int n = src->last - src->first;
    Elem12 **end_slot = &v->end;
    Elem12 *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
    v->last = elem12_ucopy(src->first, src->last, v->first);
}

NamedElem12List *fn_8815BCA8(NamedElem12List *t, const NamedElem12List *src)
{
    t->flag = src->flag;
    ts4_if_call_seq_u32_off0_88159A58(&t->name, &src->name);
    ts4_if_call_seq_u32_off0_88159A58(&t->label, &src->label);
    elem12_vec_copy(&t->items, &src->items);
    return t;
}
