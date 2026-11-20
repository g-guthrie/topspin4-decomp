/* 0x885B4228: Bytes needed: ceil(bits*bytes / (unit*count)) as a 64-bit division, then rounded up to whole bytes ((x+7)>>3). bits = 8*fn_885B4128(...), unit = fn_885CD120(...). */
/* Matched on /Oc (agAH). The u32 products go into __int64 locals before the divide. */
extern unsigned int fn_885CD120(unsigned int bytes, unsigned int rate, void *a, void *b);
extern unsigned short fn_885B4128(unsigned int bytes, void *fmt, unsigned int rate, unsigned int count, void *a, void *b);
unsigned int fn_885B4228(unsigned int bytes, void *fmt, unsigned int rate, unsigned int count, void *a, void *b)
{
    unsigned int unit = fn_885CD120(bytes, rate, a, b) * count;
    __int64 total = unit;
    unsigned int bits = fn_885B4128(bytes, fmt, rate, count, a, b) * 8;
    return ((unsigned int)(((__int64)bits * bytes + total - 1) / total) + 7) >> 3;
}
