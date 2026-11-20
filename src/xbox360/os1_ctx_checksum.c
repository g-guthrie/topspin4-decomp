/* Family OS1: LTCG context only (never integrated). Folding stand-ins for zlib crc32() and
 * adler32() so a null-buffer call in the caller folds to its constant at link time, as in the
 * game build (crc32 returns 0 and adler32 returns 1 for a null buffer). */
unsigned long ts4_crc32_big_88878408(unsigned long crc, const unsigned char *buf, unsigned len);

unsigned long os1_ctx_crc32(unsigned long crc, const unsigned char *buf, unsigned len)
{
    if (buf == (const unsigned char *)0)
        return 0UL;
    return ts4_crc32_big_88878408(crc, buf, len);
}

unsigned long os1_ctx_adler32(unsigned long adler, const unsigned char *buf, unsigned len)
{
    if (buf == (const unsigned char *)0)
        return 1UL;
    return adler + len;
}
