/* 0x884213B0: converts the NUL-terminated string s to lower case in place. */
/* Near-miss on /Oc (agAB): 3 instructions off at +0x4. The target tests *s before copying s into the walk register (mr r10,r3 after beqlr); every loop form tried puts the mr first. Sibling of 0x884218C8. */
static __inline char conv(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 0x20;
    return c;
}
void fn_884213B0(char *s)
{
    char *p = s;
    if (*p) {
        do
            *p = conv(*p);
        while (*++p);
    }
}
