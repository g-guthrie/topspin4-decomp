/* 0x8860BAB8: uniform random int in [lo, hi] (hi <= lo yields lo). Steps the generator at rng+4 (xorshift x^=x>>15; x^=x<<17) and rng+8 (LCG *69069), takes (lcg ^ x) modulo the 64-bit span count.
 * Matched on plain /Oc and LTCG routes (work/army/ME/v.py chk, matching-b129). */
typedef struct Rng { unsigned seed; unsigned x; unsigned lcg; } Rng;
static unsigned rng_next(Rng *r)
{
    unsigned x = r->x;
    unsigned l;
    x ^= x >> 15;
    l = r->lcg * 69069;
    r->lcg = l;
    x ^= x << 17;
    r->x = x;
    return l ^ x;
}
static unsigned rng_below(Rng *r, unsigned n)
{
    if (n != 0) return (unsigned)((unsigned __int64)rng_next(r) % (unsigned __int64)n);
    return 0;
}
int fn_8860BAB8(Rng *r, int lo, int hi)
{
    unsigned n = hi > lo ? (unsigned)(hi - lo) : 0;
    return rng_below(r, n + 1) + lo;
}
