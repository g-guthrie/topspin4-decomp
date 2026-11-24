/* 0x881643D0: Returns whether the begin/end string s holds exactly the C string c (same length and bytes). */
/* Matched on /Oc (agAH). Intrinsic strlen and memcmp; size == n && memcmp == 0. */
#pragma intrinsic(memcmp)
#pragma intrinsic(strlen)
int memcmp(const void *a, const void *b, unsigned int n);
unsigned int strlen(const char *s);
typedef struct Str { char *begin; char *end; } Str;
unsigned char fn_881643D0(const Str *s, const char *c)
{
    unsigned int n = strlen(c);
    return (unsigned int)(s->end - s->begin) == n && memcmp(s->begin, c, n) == 0;
}
