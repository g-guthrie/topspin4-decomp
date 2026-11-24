/* 0x88421758: returns the last index of c in the string (chars +0, length +4) searching down from hi - 1 (hi clamped to len - 1) to lo, or -1. */
/* Matched on /Oc (agAB). Plain clamp and countdown for loop. */
typedef struct Str { char *s; int len; } Str;
int fn_88421758(Str *s, char c, int lo, int hi)
{
    int i;
    if (hi > s->len - 1)
        hi = s->len - 1;
    for (i = hi - 1; i >= lo; i--)
        if (s->s[i] == c)
            return i;
    return -1;
}
