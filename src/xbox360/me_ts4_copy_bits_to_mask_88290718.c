/* 0x88290718: copies the low bit of n (n >= 1) source words into the bit array at +0x2780 starting at bit, then sets bit 56 of the 64-bit flags at +0x20. */
/* Matched on /O1 (agAB). Inline per-bit setter in a do/while; /O1 keeps li 1 inside the loop. */
typedef struct S { char p[0x20]; unsigned __int64 flags; char p28[0x2780 - 0x28]; unsigned int bits[1]; } S;
static __inline void setbit(S *s, unsigned int bit, unsigned int v)
{
    s->bits[bit >> 5] = (s->bits[bit >> 5] & ~(1u << (bit & 31))) | ((v & 1) << (bit & 31));
}
void fn_88290718(S *s, unsigned int bit, const unsigned int *src, int n)
{
    do {
        setbit(s, bit, *src++);
        bit++;
    } while (--n);
    s->flags |= 0x0100000000000000ULL;
}
