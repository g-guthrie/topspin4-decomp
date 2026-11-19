/* Swing_DLL.xex 0x88596630: PCM WAVEFORMAT(EXTENSIBLE) check: bit depth, valid bits for 0xFFFE, block align and byte rate must agree.
 * Leaf; each test is if (...) ok = 0 (branchless mask on /O1); /O1. */
typedef struct WaveFormat {
    unsigned short tag;          /* 0x00 */
    unsigned short channels;     /* 0x02 */
    unsigned int rate;           /* 0x04 */
    unsigned int bytes_per_sec;  /* 0x08 */
    unsigned short block_align;  /* 0x0c */
    unsigned short bits;         /* 0x0e */
    unsigned short extra;        /* 0x10 */
    unsigned short valid_bits;   /* 0x12 */
} WaveFormat;

int fn_88596630(const WaveFormat *w)
{
    int ok = 1;
    if (w->bits != 8 && w->bits != 16 && w->bits != 24 && w->bits != 32) ok = 0;
    if (w->tag == 0xfffe) {
        unsigned short v = w->valid_bits;
        if (v != 0 && v != 8 && v != 16 && v != 20 && v != 24 && v != 32) ok = 0;
        if (v > w->bits) ok = 0;
    }
    if (w->block_align != (int)(w->channels * w->bits) / 8) ok = 0;
    if (w->bytes_per_sec != w->rate * w->block_align) ok = 0;
    return ok;
}
