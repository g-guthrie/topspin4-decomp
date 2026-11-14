/* Loader_DLL.xex 0x83464B18-0x83464CA4, executable version 0.0.0.3.
 * zlib 1.1.x trees.c small helpers (second copy): set_data_type, bi_reverse, bi_flush, bi_windup. */

typedef struct ts4l_stat_entry {
    unsigned short w, z;
} ts4l_stat_entry;

typedef struct ts4l_stat_block {
    char pad[0x1c];
    unsigned char flag;
    char pad2[0x8c - 0x1d];
    ts4l_stat_entry a[7];
    ts4l_stat_entry b[0x79];
    ts4l_stat_entry c[0x80];
} ts4l_stat_block;

/* Compare weighted sums of three 16-bit histograms and set a flag byte. */
void ts4l_zlib_set_data_type_83464B18(ts4l_stat_block *q)
{
    unsigned s2 = 0, s1 = 0;
    int i;
    for (i = 0; i < 7; i++) s1 += q->a[i].w;
    for (i = 0; i < 0x79; i++) s2 += q->b[i].w;
    for (i = 0; i < 0x80; i++) s1 += q->c[i].w;
    q->flag = (s2 >> 2) >= s1;
}

unsigned int ts4l_zlib_bi_reverse_83464B80(unsigned int x, int n)
{
    unsigned int r = 0;
    do {
        r |= x & 1;
        x >>= 1;
        r <<= 1;
    } while (--n > 0);
    return r >> 1;
}

typedef struct ts4l_bit_writer {
    char p0[8];
    unsigned char *buf;
    char p1[8];
    int pos;
    char p2[0x16b0 - 0x18];
    unsigned short bits;
    unsigned short pad;
    int nbits;
} ts4l_bit_writer;

#ifdef _MSC_VER
__forceinline
#else
__attribute__((unused))
#endif
static void ts4l_bit_writer_put(ts4l_bit_writer *w, unsigned char c)
{
    w->buf[w->pos++] = c;
}

/* Flush the partial bit accumulator (up to 16 bits) to the output buffer. */
void ts4l_zlib_bi_windup_83464C38(ts4l_bit_writer *w)
{
    if (w->nbits > 8) {
        w->buf[w->pos] = (unsigned char)w->bits;
        w->buf[++w->pos] = (unsigned char)(w->bits >> 8);
        w->pos++;
    } else if (w->nbits > 0) {
        w->buf[w->pos] = (unsigned char)w->bits;
        w->pos++;
    }
    w->bits = 0;
    w->nbits = 0;
}

/* Emit whole bytes from the accumulator once 8 or 16 bits are pending. */
void ts4l_zlib_bi_flush_83464BA8(ts4l_bit_writer *w)
{
    if (w->nbits == 16) {
        ts4l_bit_writer_put(w, (unsigned char)w->bits);
        ts4l_bit_writer_put(w, (unsigned char)(w->bits >> 8));
        w->bits = 0;
        w->nbits = 0;
    } else if (w->nbits >= 8) {
        ts4l_bit_writer_put(w, (unsigned char)w->bits);
        w->bits = (unsigned char)(w->bits >> 8);
        w->nbits -= 8;
    }
}

