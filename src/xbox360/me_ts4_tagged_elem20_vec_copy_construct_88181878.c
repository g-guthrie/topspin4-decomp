/* Swing_DLL.xex 0x88181878: copy constructor of {tag; vector<20-byte element>}: copy the tag, then copy-construct the vector (uninit copy 88185E50).
 * /Oc. The vector copy is an inline taking &src->items; end zero store through the end-slot pointer. */
typedef struct Elem20 { unsigned int w[5]; } Elem20;
typedef struct Elem20Vec { Elem20 *first; Elem20 *last; Elem20 *end; } Elem20Vec;
typedef struct TaggedElem20Vec { unsigned int tag; Elem20Vec items; } TaggedElem20Vec;
Elem20 *ts4_if_call_seq_u32_lbl_88D45B38_8817F480(Elem20 **owner, unsigned int n);
Elem20 *ts4_uninit_copy_text_88185E50(const Elem20 *first, const Elem20 *last, Elem20 *dest);

static __inline void elem20_vec_construct_n(Elem20Vec *v, unsigned int n)
{
    Elem20 **end_slot = &v->end;
    Elem20 *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_8817F480(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
}

static __inline void elem20_vec_copy(Elem20Vec *v, const Elem20Vec *src)
{
    elem20_vec_construct_n(v, src->last - src->first);
    v->last = ts4_uninit_copy_text_88185E50(src->first, src->last, v->first);
}

TaggedElem20Vec *fn_88181878(TaggedElem20Vec *t, const TaggedElem20Vec *src)
{
    t->tag = src->tag;
    elem20_vec_copy(&t->items, &src->items);
    return t;
}
