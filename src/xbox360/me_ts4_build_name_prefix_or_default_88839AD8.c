/* Swing_DLL.xex 0x88839AD8: interns (prefix, or literal lbl_880E1564 when there is no prefix) + literal lbl_880E1078: a bounded copy into a 124-byte buffer, strncat, then 88608590(0, buf) into *out.
 * /Oc. Use a bounded-copy inline on both branches; `124 - (int)strlen(buf)` gives the clrrwi. */
unsigned int strlen(const char *s);
char *ts4_crt_strncat_88564EF0(char *dst, const char *src, unsigned int count);
int fn_88608590(int, const char *);
extern char lbl_880E1564[];
extern char lbl_880E1078[];

static __inline void copy_bounded(char *buf, const char *s)
{
    char *d = buf;
    while (d != buf + 124) {
        char c = *s;
        if (!c)
            break;
        *d = c;
        d++;
        s++;
    }
    *d = 0;
}

int *fn_88839AD8(int *out, const char *prefix)
{
    char buf[124];
    if (prefix)
        copy_bounded(buf, prefix);
    else
        copy_bounded(buf, lbl_880E1564);
    ts4_crt_strncat_88564EF0(buf, lbl_880E1078, 124 - (int)strlen(buf));
    *out = fn_88608590(0, buf);
    return out;
}
