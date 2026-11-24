/* Swing_DLL.xex 0x88166C58: vector<12-byte formatted text> copy constructor: zero, allocate size(src), copy-construct each text.
 * /Oc. The end zero store goes through a pointer to the end slot; plain member stores schedule mr r29 after the first load (4 off). */
typedef struct Text { char *p; char *last; char *end; } Text;
typedef struct TextVec { Text *first; Text *last; Text *end; } TextVec;
Text *ts4_if_call_seq_u32_lbl_88D45B38_88263C98(Text **owner, unsigned int n);
void ts4_assign_formatted_text(void *dst, void *src);

static __inline Text *text_ucopy(const Text *first, const Text *last, Text *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) ts4_assign_formatted_text(dest, first->p);
    return dest;
}

static __inline void text_vec_construct_n(TextVec *v, unsigned int n)
{
    Text **end_slot = &v->end;
    Text *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
}

TextVec *fn_88166C58(TextVec *v, const TextVec *src)
{
    text_vec_construct_n(v, src->last - src->first);
    v->last = text_ucopy(src->first, src->last, v->first);
    return v;
}
