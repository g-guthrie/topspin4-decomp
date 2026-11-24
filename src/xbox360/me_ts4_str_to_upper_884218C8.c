/* 0x884218C8: converts the length-counted buffer (len counts the terminator) to upper case in place. */
/* Matched on /Oc (agAB). Per-char inline converter that returns c unchanged otherwise; unconditional store. */
typedef struct S { char *buf; int len; } S;
static __inline char conv(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 0x20;
    return c;
}
void fn_884218C8(S *s)
{
    int i;
    for (i = 0; i < s->len - 1; i++)
        s->buf[i] = conv(s->buf[i]);
}
