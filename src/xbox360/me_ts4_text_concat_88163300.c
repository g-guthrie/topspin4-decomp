/* Swing_DLL.xex 0x88163300: string operator+(a, b): empty result, reserve size(a) + size(b) + 1, terminate, append a then b (8816C930).
 * /Oc. The combined length is computed before the zero stores; the append inline reads last before first. */
typedef struct Text { char *p; char *last; char *end; } Text;
void ts4_if_call_seq_lbl_880D19E0_88155A40(Text *t, unsigned int n);
void fn_8816C930(Text *t, const char *first, const char *last);

static __inline void text_append(Text *t, const Text *s)
{
    const char *last = s->last;
    const char *first = s->p;
    if (first != last) fn_8816C930(t, first, last);
}

Text *fn_88163300(Text *r, const Text *a, const Text *b)
{
    unsigned int n = (a->last - a->p) + (b->last - b->p);
    r->p = 0;
    r->last = 0;
    r->end = 0;
    ts4_if_call_seq_lbl_880D19E0_88155A40(r, n + 1);
    *r->last = 0;
    text_append(r, a);
    text_append(r, b);
    return r;
}
