/* 0x885DC050: Sums 23 terms into *out: each value minus base, clamped to [0, 0x600000] and masked to a multiple of 0x100000, times the matching signed 16-bit weight. */
/* Matched on /Oc /Os (agAH). Built /Os. Values walked with *values++, weights indexed: that sets up the weights pointer first; walking both with ++ swaps the two subi. */
void fn_885DC050(const int *values, const short *weights, int base, int *out)
{
    int i;
    *out = 0;
    for (i = 0; i < 23; i++) {
        int d = *values++ - base;
        if (d < 0)
            d = 0;
        else if (d > 0x600000)
            d = 0x600000;
        *out += (d & ~0xFFFFF) * weights[i];
    }
}
