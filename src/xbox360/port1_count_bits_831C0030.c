/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l15_count_bits_831C0030.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */




/* Swing_DLL.xex 0x885C2448 */
/* Count the set bits of `a` that precede the first bit position set in `b`
 * (stored minus one when the masks do not overlap at all). */
void ts4_count_bits_885C2448(unsigned a, unsigned b, short *out)
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

