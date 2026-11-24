/* Swing_DLL.xex 0x8858DAA8: Bit writer: shifts value into a 32-bit accumulator, then flushes 16 bits at a time (low byte of the top half first), wrapping the output pointer to start.
 * Leaf; shift count as an int local before the signed-char store; /O1. */
typedef struct BitWriter {
    unsigned char pad[0x14];
    union { unsigned int word; unsigned char b[4]; } acc; /* 0x14 */
    signed char room;                                     /* 0x18 */
    unsigned char wrapped;                                /* 0x19 */
    unsigned char pad1a[0x854 - 0x1a];
    unsigned char *start;                                 /* 0x854 */
    unsigned char *pos;                                   /* 0x858 */
    unsigned char *end;                                   /* 0x85c */
} BitWriter;

void fn_8858DAA8(BitWriter *w, int n, unsigned int value)
{
    int r = w->room - n;
    w->room = (signed char)r;
    w->acc.word |= value << r;
    while (w->room <= 16) {
        if (w->pos >= w->end) {
            w->wrapped = 1;
            w->pos = w->start;
        }
        *w->pos = w->acc.b[1];
        w->pos++;
        *w->pos = w->acc.b[0];
        w->pos++;
        w->room += 16;
        w->acc.word <<= 16;
    }
}
