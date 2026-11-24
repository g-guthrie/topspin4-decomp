/* 0x8859AB40: returns a buffer size for n 12-byte entries: the header (n * 0x60 + 0x8F rounded down to 0x80) plus 2 * (w + 0x80) * k for each entry (w at +4, k byte at +8). */
/* Matched on /O1 (agAB). Plain indexed loop; /O1 gives the ctr loop with lwzu (no unroll). */
typedef struct E { int p0; int w; unsigned char k; char p9[3]; } E;
unsigned int fn_8859AB40(unsigned int n, E *e)
{
    unsigned int hdr = (n * 0x60 + 0x8f) & ~0x7f;
    unsigned int sum = 0, i;
    for (i = 0; i < n; i++)
        sum += (e[i].w + 0x80) * e[i].k * 2;
    return sum + hdr;
}
