/* 0x8822BF98: Returns whether the C string c equals the begin/end string s (same length and bytes). */
/* Matched on /Oc (agAH). Mirror of 881643D0 with operands swapped. */
#pragma intrinsic(memcmp)
#pragma intrinsic(strlen)
int memcmp(const void *a, const void *b, unsigned int n);
unsigned int strlen(const char *s);
typedef struct Str { char *begin; char *end; } Str;
unsigned char fn_8822BF98(const char *c, const Str *s)
{
    unsigned int n = strlen(c);
    return n == (unsigned int)(s->end - s->begin) && memcmp(c, s->begin, n) == 0;
}
