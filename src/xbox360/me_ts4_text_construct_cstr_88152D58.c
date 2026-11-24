/* Swing_DLL.xex 0x88152D58: string(const char *s): empty text, reserve strlen(s) + 1, copy the characters and terminate.
 * /Oc. Write the length as `s + (int)strlen(s)` with the strlen intrinsic: that gives the clrrwi before the add. The zero stores need the end-slot form. */
typedef struct Text { char *p; char *last; char *end; } Text;
unsigned int strlen(const char *s);
void ts4_if_call_seq_lbl_880D19E0_88155A40(Text *t, unsigned int n);
char *fn_88562DC0(char *dst, const char *src, unsigned int n);

static __inline char *text_copy(const char *first, const char *last, char *dest)
{
    unsigned int n;
    if (last == first)
        return dest;
    n = last - first;
    return fn_88562DC0(dest, first, n) + n;
}

static __inline void text_assign(Text *t, const char *first, const char *last)
{
    ts4_if_call_seq_lbl_880D19E0_88155A40(t, (last - first) + 1);
    t->last = text_copy(first, last, t->p);
    *t->last = 0;
}

Text *ts4_assign_formatted_text(Text *t, const char *s)
{
    char **end_slot = &t->end;
    t->p = 0;
    t->last = 0;
    *end_slot = 0;
    text_assign(t, s, s + (int)strlen(s));
    return t;
}
