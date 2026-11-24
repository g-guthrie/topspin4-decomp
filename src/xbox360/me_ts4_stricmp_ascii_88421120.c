/* Swing_DLL.xex 0x88421120: Case-insensitive strcmp (A-Z folded to lower case), returns -1/0/1.
 * Leaf; inline to_lower per agAB's 884218C8 rule; /Oc. */
static __inline char to_lower(char c)
{
    if ('A' <= c && c <= 'Z') return c + 0x20;
    return c;
}
int fn_88421120(const char *a, const char *b)
{
    for (;; a++, b++) {
        if (*a == 0 && *b == 0) return 0;
        if (to_lower(*a) < to_lower(*b)) return -1;
        if (to_lower(*a) > to_lower(*b)) return 1;
    }
}
