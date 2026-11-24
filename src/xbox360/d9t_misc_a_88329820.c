/* Swing_DLL.xex 0x88329820-0x88419F4C, executable version 0.0.0.3. */
#ifdef _MSC_VER
#else
#define __forceinline inline
#endif
int ts4_strncmp_88329820(const char *a, const char *b, int n)
{
    int i = 0;
    char c1, c2;
    --a; --b;
    do {
        c1 = *++a;
        i++;
        c2 = *++b;
        if (c1 == 0 || c1 != c2) { break; }
    } while (i < n);
    return c1 - c2;
}
typedef struct Ts4B { char pad[0x130]; unsigned val; char pad2[0x18]; struct Ts4C *c; } Ts4B;
struct Ts4C { char pad[0x2c]; unsigned lim; };
static __forceinline int ts4_set_limit_in(Ts4B *o, unsigned n)
{
    unsigned lim;
    if (o->c == 0) { return 0x25; }
    lim = o->c->lim;
    if (!(n < lim)) { n = lim; }
    o->val = n;
    return 0;
}
int ts4_set_limit_88389D18(void *sub, unsigned n)
{
    return ts4_set_limit_in(sub ? (Ts4B *)((char *)sub - 0x1c) : 0, n);
}
typedef struct Ts4R { unsigned a20, a24, a28, a2c, a30; } Ts4R;
void ts4_align_range_88419F08(unsigned *p, unsigned a, int b)
{
    unsigned m = a & 15;
    p[0xc] = b;
    p[0xa] = -1;
    if (m != 0) {
        unsigned al = a - m + 16;
        p[8] = al;
        p[0xb] = al - m + b;
    } else {
        p[8] = a;
        p[0xb] = a + b;
    }
}
