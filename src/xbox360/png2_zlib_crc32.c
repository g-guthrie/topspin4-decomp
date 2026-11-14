/* Derived from zlib 1.1.x (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: zlib 1.1.4 crc32.c of the second zlib copy (used by libpng). */

extern const unsigned long lbl_88025B00[256]; /* crc_table */

#define PNG2_DO1(buf) crc = lbl_88025B00[((int)crc ^ (*buf++)) & 0xff] ^ (crc >> 8);
#define PNG2_DO2(buf) PNG2_DO1(buf); PNG2_DO1(buf);
#define PNG2_DO4(buf) PNG2_DO2(buf); PNG2_DO2(buf);
#define PNG2_DO8(buf) PNG2_DO4(buf); PNG2_DO4(buf);

/* Update a running CRC-32 with len bytes; a NULL buffer returns the initial value 0 (zlib crc32).
 * Swing_DLL.xex 0x882EC228 */
unsigned long png2_zlib_crc32_882EC228(unsigned long crc, const unsigned char *buf, unsigned int len)
{
    if (buf == 0)
        return 0L;
    crc = crc ^ 0xffffffffUL;
    while (len >= 8) {
        PNG2_DO8(buf);
        len -= 8;
    }
    if (len)
        do {
            PNG2_DO1(buf);
        } while (--len);
    return crc ^ 0xffffffffUL;
}
