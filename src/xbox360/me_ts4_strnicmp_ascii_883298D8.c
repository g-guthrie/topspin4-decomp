/* 0x883298D8: ASCII case-insensitive compare of at most n characters, returning the difference of the last pair */
/* Matched on /Oc (agAH). Inline lower() that modifies its parameter ('c += 0x20; return c;'); the return-early form is larger. */
static __inline char lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 0x20;
    return c;
}
int fn_883298D8(const char *a, const char *b, int n)
{
    int i = 0;
    char ca, cb;
    do {
        ca = lower(*a++);
        cb = lower(*b++);
        i++;
    } while (ca && ca == cb && i < n);
    return ca - cb;
}
