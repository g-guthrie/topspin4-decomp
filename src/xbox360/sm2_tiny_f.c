/* SM2: small object helpers (string-size, refcount, byte swap, loops). */
#ifndef _MSC_VER
#pragma GCC diagnostic ignored "-Wunused-function"
#endif
extern void fn_88470870(void *a, void *b);

/* bytes needed for a name: strlen + 2 (just 2 for a null name) */
static unsigned ts4_name_len_plus2(const char *s)
{
    const char *q;
    if (s == 0) return 2;
    q = s;
    while (*q++ != 0) {}
    return (unsigned)(q - s - 1) + 2;
}
#define NAME_SIZE_C(NAME, ADDR, EXTRA) \
    unsigned NAME(const char *obj) { return ts4_name_len_plus2(*(const char *const *)(obj + 0xc)) + (EXTRA); }

/* forward the object's child at +8 together with the object when a child exists */
#define FWD_CHILD(NAME) \
    void NAME(char *obj) { if (*(void **)(obj + 8)) fn_88470870(*(void **)(obj + 8), obj); }

/* byte-swap a 16-bit value through memory */
unsigned short ts4_bswap16_8840BAB8(unsigned short x)
{
    unsigned char in[2], out[2];
    *(unsigned short *)in = x;
    out[0] = in[1];
    out[1] = in[0];
    return *(unsigned short *)out;
}
unsigned short ts4_bswap16_88413950(unsigned short x)
{
    unsigned char in[2], out[2];
    *(unsigned short *)in = x;
    out[0] = in[1];
    out[1] = in[0];
    return *(unsigned short *)out;
}
/* bump the short refcount at +6 when the object is live (+4 nonzero) */
#define ADDREF16(NAME) \
    void NAME(char *p) { if (*(unsigned short *)(p + 4) != 0) *(unsigned short *)(p + 6) += 1; }
/* zero n words */
void ts4_zero_words_8840B9D8(void *a, void *b, void *c, unsigned n, unsigned *arr)
{
    unsigned i;
    (void)a;
    (void)b;
    (void)c;
    for (i = 0; i < n; i++) arr[i] = 0;
}
