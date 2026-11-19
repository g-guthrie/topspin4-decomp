/* Swing_DLL.xex 0x88161F58: vector<32-byte text record> copy constructor: zero, allocate size(src), copy each text and its five words.
 * /Oc. Same shape as 88166C58; the end zero store goes through a pointer to the end slot. */
typedef struct Text { char *p; char *last; char *end; } Text;
typedef struct TextRec32 { Text text; unsigned int w[5]; } TextRec32;
typedef struct TextRec32Vec { TextRec32 *first; TextRec32 *last; TextRec32 *end; } TextRec32Vec;
TextRec32 *ts4_if_call_seq_u32_lbl_88D45B38_88162950(TextRec32 **owner, unsigned int n);
void ts4_assign_formatted_text(void *dst, void *src);

static __inline TextRec32 *text_rec32_ucopy(const TextRec32 *first, const TextRec32 *last, TextRec32 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) {
            ts4_assign_formatted_text(&dest->text, first->text.p);
            dest->w[0] = first->w[0];
            dest->w[1] = first->w[1];
            dest->w[2] = first->w[2];
            dest->w[3] = first->w[3];
            dest->w[4] = first->w[4];
        }
    return dest;
}

static __inline void text_rec32_vec_construct_n(TextRec32Vec *v, unsigned int n)
{
    TextRec32 **end_slot = &v->end;
    TextRec32 *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88162950(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
}

TextRec32Vec *fn_88161F58(TextRec32Vec *v, const TextRec32Vec *src)
{
    text_rec32_vec_construct_n(v, src->last - src->first);
    v->last = text_rec32_ucopy(src->first, src->last, v->first);
    return v;
}
