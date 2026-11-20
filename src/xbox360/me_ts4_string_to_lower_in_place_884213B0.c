/* 0x884213B0: converts the NUL-terminated string s to lower case in place and returns s. */
/* Matched on /Oc (agAF). The test of *s comes before the walk copy when the copy is declared inside the if; sibling of 0x884218C8. */
static __inline char conv(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 0x20;
    return c;
}
char *fn_884213B0(char *s)
{
    if (*s) {
        char *p = s;
        do
            *p = conv(*p);
        while (*++p);
    }
    return s;
}
