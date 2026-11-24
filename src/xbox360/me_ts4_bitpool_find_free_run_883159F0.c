/* Swing_DLL.xex 0x883159F0: Bitmap allocator search: first run of count clear bits in [pos, end), skipping all-set 32-bit words.
 * Leaf; run < count is part of the loop condition, mask is int, run declared first. */
typedef struct BitPool {
    unsigned char *bits; /* set bit = used */
    int pad[3];
    int size;            /* in bits */
} BitPool;

/* First index of `count` consecutive clear bits in [pos, end), or -1. Whole set words are skipped. */
int fn_883159F0(const BitPool *p, int pos, int end, int count)
{
    int run = 0;
    int byte = pos >> 3;
    int mask = 1 << (pos & 7);
    while (run < count && pos < end && pos < p->size) {
        if ((p->bits[byte] & mask) == 0 && ((pos & 31) != 0 || *(int *)(p->bits + byte) != -1))
            run++;
        else
            run = 0;
        if ((pos & 31) == 0 && *(int *)(p->bits + byte) == -1) {
            byte += 4;
            pos += 32;
        } else {
            pos++;
            mask <<= 1;
            if ((pos & 7) == 0) {
                mask = 1;
                byte++;
            }
        }
    }
    if (run == count) return pos - count;
    return -1;
}
