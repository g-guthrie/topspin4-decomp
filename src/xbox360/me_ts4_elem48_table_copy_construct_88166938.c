/* Swing_DLL.xex 0x88166938: copy constructor of a 48-byte-element vector followed by three formatted texts.
 * /Oc. Vector part as 88166C58 (end zero store through the end-slot pointer), then three text assigns. */
typedef struct Text { char *p; char *last; char *end; } Text;
typedef struct Elem48 { unsigned int w[12]; } Elem48;
typedef struct Elem48Vec { Elem48 *first; Elem48 *last; Elem48 *end; } Elem48Vec;
typedef struct Elem48Table { Elem48Vec items; Text a; Text b; Text c; } Elem48Table;
Elem48 *ts4_if_call_seq_u32_lbl_88D45B38_881884E0(Elem48 **owner, unsigned int n);
void ts4_call_seq_u32_off0_8815ED78(Elem48 *dest, const Elem48 *src);
void ts4_assign_formatted_text(void *dst, void *src);

static __inline Elem48 *elem48_ucopy(const Elem48 *first, const Elem48 *last, Elem48 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) ts4_call_seq_u32_off0_8815ED78(dest, first);
    return dest;
}

static __inline void elem48_vec_construct_n(Elem48Vec *v, unsigned int n)
{
    Elem48 **end_slot = &v->end;
    Elem48 *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_881884E0(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
}

Elem48Table *fn_88166938(Elem48Table *t, const Elem48Table *src)
{
    elem48_vec_construct_n(&t->items, src->items.last - src->items.first);
    t->items.last = elem48_ucopy(src->items.first, src->items.last, t->items.first);
    ts4_assign_formatted_text(&t->a, src->a.p);
    ts4_assign_formatted_text(&t->b, src->b.p);
    ts4_assign_formatted_text(&t->c, src->c.p);
    return t;
}
