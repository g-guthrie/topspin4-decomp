/* Derived from zlib 1.1.x (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: zlib 1.1.4 adler32.c of the second zlib copy. */

#define PNG2_BASE 65521UL
#define PNG2_NMAX 5552

#define PNG2_DO1(buf, i) { s1 += buf[i]; s2 += s1; }
#define PNG2_DO2(buf, i) PNG2_DO1(buf, i); PNG2_DO1(buf, i + 1);
#define PNG2_DO4(buf, i) PNG2_DO2(buf, i); PNG2_DO2(buf, i + 2);
#define PNG2_DO8(buf, i) PNG2_DO4(buf, i); PNG2_DO4(buf, i + 4);
#define PNG2_DO16(buf) PNG2_DO8(buf, 0); PNG2_DO8(buf, 8);

/* Update a running Adler-32 checksum with len bytes; a NULL buffer returns the initial value 1 (zlib adler32).
 * Swing_DLL.xex 0x883022B0 */
unsigned long png2_zlib_adler32_883022B0(unsigned long adler, const unsigned char *buf, unsigned int len)
{
    unsigned long s1 = adler & 0xffff;
    unsigned long s2 = (adler >> 16) & 0xffff;
    int k;

    if (buf == 0)
        return 1L;
    while (len > 0) {
        k = len < PNG2_NMAX ? (int)len : PNG2_NMAX;
        len -= k;
        while (k >= 16) {
            PNG2_DO16(buf);
            buf += 16;
            k -= 16;
        }
        if (k != 0)
            do {
                s1 += *buf++;
                s2 += s1;
            } while (--k);
        s1 %= PNG2_BASE;
        s2 %= PNG2_BASE;
    }
    return (s2 << 16) | s1;
}
