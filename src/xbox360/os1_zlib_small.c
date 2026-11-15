/* Derived from zlib 1.2.3 crc32.c (zlib license); see THIRD_PARTY_NOTICES.md. Family OS1. */
unsigned long ts4_crc32_big_88878408(unsigned long crc, const unsigned char *buf, unsigned len);

/* crc32() entry point: a null buffer returns the initial value 0, otherwise the table-driven
 * big-endian word loop runs (zlib crc32 with BYFOUR). Swing_DLL.xex 0x88878A78 */
unsigned long ts4_zlib_crc32_88878A78(unsigned long crc, const unsigned char *buf, unsigned len)
{
    if (buf == (const unsigned char *)0)
        return 0UL;
    return ts4_crc32_big_88878408(crc, buf, len);
}

/* Virtual method of a compressor object: stores its three-character tag "ZLB" in the caller's
 * buffer. Swing_DLL.xex 0x88878DA8 */
void os1_zlb_write_tag_88878DA8(void *self, char *out)
{
    (void)self;
    out[0] = 'Z';
    out[1] = 'L';
    out[2] = 'B';
}
