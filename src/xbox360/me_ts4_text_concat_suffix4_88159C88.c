/* Swing_DLL.xex 0x88159C88: string operator+(a, 4-char literal lbl_880D2F2C): empty result, reserve size(a) + 5, terminate, append a, append the literal (8815D9D8).
 * /Oc. Same shape as 88163300 (length computed before the zero stores, append reads last before first). */
typedef struct Text { char *p; char *last; char *end; } Text;
extern const char lbl_880D2F2C[];
void ts4_if_call_seq_lbl_880D19E0_8815C9E8(Text *t, unsigned int n);
void fn_8815D9D8(Text *t, const char *first, const char *last);

static __inline void text_append(Text *t, const Text *s)
{
    const char *last = s->last;
    const char *first = s->p;
    if (first != last) fn_8815D9D8(t, first, last);
}

Text *fn_88159C88(Text *r, const Text *a)
{
    unsigned int n = (a->last - a->p) + 4;
    r->p = 0;
    r->last = 0;
    r->end = 0;
    ts4_if_call_seq_lbl_880D19E0_8815C9E8(r, n + 1);
    *r->last = 0;
    text_append(r, a);
    fn_8815D9D8(r, lbl_880D2F2C, lbl_880D2F2C + 4);
    return r;
}
