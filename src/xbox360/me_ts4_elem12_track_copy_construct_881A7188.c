/* Swing_DLL.xex 0x881A7188: copy constructor of {two texts; id, kind, x, y, four words; vector<12-byte POD>; flags}.
 * /Oc. Inlined vector copy with the end zero store through the end-slot pointer; the vector stores last before first. */
typedef struct Text { char *p; char *last; char *end; } Text;
typedef struct Elem12 { unsigned int a; unsigned int b; unsigned int c; } Elem12;
typedef struct Elem12Vec { Elem12 *first; Elem12 *last; Elem12 *end; } Elem12Vec;
Elem12 *ts4_if_call_seq_u32_lbl_88D45B38_88263C98(Elem12 **owner, unsigned int n);
void ts4_assign_formatted_text(void *dst, void *src);
typedef struct Elem12Track { Text name; Text label; unsigned int id; unsigned int kind; float x; float y; unsigned int w[4]; Elem12Vec items; unsigned int flags; } Elem12Track;

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
    v->last = p;
    v->first = p;
    v->end = p + n;
    v->last = elem12_ucopy(src->first, src->last, v->first);
}

Elem12Track *fn_881A7188(Elem12Track *t, const Elem12Track *src)
{
    ts4_assign_formatted_text(&t->name, src->name.p);
    ts4_assign_formatted_text(&t->label, src->label.p);
    t->id = src->id;
    t->kind = src->kind;
    t->x = src->x;
    t->y = src->y;
    t->w[0] = src->w[0];
    t->w[1] = src->w[1];
    t->w[2] = src->w[2];
    t->w[3] = src->w[3];
    elem12_vec_copy(&t->items, &src->items);
    t->flags = src->flags;
    return t;
}
