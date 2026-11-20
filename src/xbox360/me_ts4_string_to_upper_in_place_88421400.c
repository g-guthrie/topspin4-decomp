/* 0x88421400: converts the NUL-terminated string s to upper case in place and returns s. */
/* Matched on /Oc (agAF). The test of *s comes before the walk copy when the copy is declared inside the if; sibling of 0x884213B0. */
static __inline char conv(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 0x20;
    return c;
}
char *fn_88421400(char *s)
{
    if (*s) {
        char *p = s;
        do
            *p = conv(*p);
        while (*++p);
    }
    return s;
}
