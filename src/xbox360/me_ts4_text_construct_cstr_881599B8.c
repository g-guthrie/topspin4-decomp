/* Swing_DLL.xex 0x881599B8: string(const char *s) (second instance, reserve 8815C9E8): empty text, reserve strlen(s) + 1, copy and terminate.
 * /Oc. Same source as 88152D58: `s + (int)strlen(s)` with the strlen intrinsic, and end-slot zero stores. */
typedef struct Text { char *p; char *last; char *end; } Text;
unsigned int strlen(const char *s);
void ts4_if_call_seq_lbl_880D19E0_8815C9E8(Text *t, unsigned int n);
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
    ts4_if_call_seq_lbl_880D19E0_8815C9E8(t, (last - first) + 1);
    t->last = text_copy(first, last, t->p);
    *t->last = 0;
}

Text *fn_881599B8(Text *t, const char *s)
{
    char **end_slot = &t->end;
    t->p = 0;
    t->last = 0;
    *end_slot = 0;
    text_assign(t, s, s + (int)strlen(s));
    return t;
}
