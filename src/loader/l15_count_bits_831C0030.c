/* Loader_DLL.xex 0x831C0030-0x8325717C, executable version 0.0.0.3. */
/* Count the set bits of `a` that precede the first bit position set in `b`
 * (stored minus one when the masks do not overlap at all). */
void ts4l_count_bits_831C0030(unsigned a, unsigned b, short *out)
{
    unsigned m;
    int i;

    *out = 0xffff;
    if ((a & b) != 0) {
        m = 1;
        for (i = 0; i < 32; i++) {
            if (a & m)
                (*out)++;
            if (b & m)
                return;
            m <<= 1;
        }
    }
}

void ts4l_count_bits_83257128(unsigned a, unsigned b, short *out)
{
    unsigned m;
    int i;

    *out = 0xffff;
    if ((a & b) != 0) {
        m = 1;
        for (i = 0; i < 32; i++) {
            if (a & m)
                (*out)++;
            if (b & m)
                return;
            m <<= 1;
        }
    }
}
