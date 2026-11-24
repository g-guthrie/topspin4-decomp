/* 0x88432BE0: Byte-swaps an array of 32-bit words in place (n bytes, 4 at a time). */
/* Matched on /Oc /O2 (agAH). Two calls of a small byte-swap helper per word; open-coded temporaries give a different store order. */
static void SwapBytes(unsigned char *a, unsigned char *b)
{
    unsigned char t = *a;
    *a = *b;
    *b = t;
}

void fn_88432BE0(unsigned char *p, int n)
{
    int i;
    for (i = 0; i < n; i += 4) {
        SwapBytes(&p[i], &p[i + 3]);
        SwapBytes(&p[i + 1], &p[i + 2]);
    }
}
