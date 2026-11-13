/* Derived from zlib (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "r3_zlib.h"

/* Placeholders for sibling zlib functions outside this file. */
extern void fn_888776C8(ts4_deflate_state *s);                         /* fill_window */
extern void fn_88873870(ts4_deflate_state *s, unsigned char *buf, unsigned long stored_len, int last); /* _tr_flush_block */
extern void fn_88876570(ts4_z_stream *strm);                           /* flush_pending */

#define TS4_Z_NO_FLUSH 0
#define TS4_Z_FINISH 4
#define TS4_MIN_LOOKAHEAD 262 /* MAX_MATCH + MIN_MATCH + 1 */
#define TS4_MAX_DIST(s) ((s)->w_size - TS4_MIN_LOOKAHEAD)

/* deflate block_state results */
#define TS4_NEED_MORE 0
#define TS4_BLOCK_DONE 1
#define TS4_FINISH_STARTED 2
#define TS4_FINISH_DONE 3

#define TS4_FLUSH_BLOCK_ONLY(s, last) \
    { \
        fn_88873870((s), ((s)->block_start >= 0L ? &(s)->window[(unsigned)(s)->block_start] : (unsigned char *)0), \
                    (unsigned long)((long)(s)->strstart - (s)->block_start), (last)); \
        (s)->block_start = (s)->strstart; \
        fn_88876570((s)->strm); \
    }

#define TS4_FLUSH_BLOCK(s, last) \
    { \
        TS4_FLUSH_BLOCK_ONLY(s, last); \
        if ((s)->strm->avail_out == 0) \
            return (last) ? TS4_FINISH_STARTED : TS4_NEED_MORE; \
    }

/* Level-0 deflate: copy input into stored blocks (zlib deflate_stored).
 * Swing_DLL.xex 0x88878230 */
int ts4_deflate_stored_88878230(ts4_deflate_state *s, int flush)
{
    unsigned long max_block_size = 0xffff;
    unsigned long max_start;

    if (max_block_size > s->pending_buf_size - 5)
        max_block_size = s->pending_buf_size - 5;

    for (;;) {
        if (s->lookahead <= 1) {
            fn_888776C8(s);
            if (s->lookahead == 0 && flush == TS4_Z_NO_FLUSH)
                return TS4_NEED_MORE;
            if (s->lookahead == 0)
                break;
        }
        s->strstart += s->lookahead;
        s->lookahead = 0;

        max_start = s->block_start + max_block_size;
        if (s->strstart == 0 || (unsigned long)s->strstart >= max_start) {
            s->lookahead = (unsigned int)(s->strstart - max_start);
            s->strstart = (unsigned int)max_start;
            TS4_FLUSH_BLOCK(s, 0);
        }
        if (s->strstart - (unsigned int)s->block_start >= TS4_MAX_DIST(s)) {
            TS4_FLUSH_BLOCK(s, 0);
        }
    }
    TS4_FLUSH_BLOCK(s, flush == TS4_Z_FINISH);
    return flush == TS4_Z_FINISH ? TS4_FINISH_DONE : TS4_BLOCK_DONE;
}

/* CRC-32 lookup tables (zlib crc_table[8][256]: rows 0-3 little-endian, rows 4-7 big-endian) in .rdata. */
extern const unsigned int lbl_880CBAC8[8][256];

#define TS4_CRC_TABLE lbl_880CBAC8

#define TS4_DOLIT4 \
    c ^= *buf4++; \
    c = TS4_CRC_TABLE[3][c & 0xff] ^ TS4_CRC_TABLE[2][(c >> 8) & 0xff] ^ TS4_CRC_TABLE[1][(c >> 16) & 0xff] ^ \
        TS4_CRC_TABLE[0][c >> 24]
#define TS4_DOLIT32 \
    TS4_DOLIT4; TS4_DOLIT4; TS4_DOLIT4; TS4_DOLIT4; TS4_DOLIT4; TS4_DOLIT4; TS4_DOLIT4; TS4_DOLIT4

/* CRC-32 over a buffer, four bytes at a time (zlib crc32_little).
 * Swing_DLL.xex 0x88878778 */
unsigned long ts4_crc32_little_88878778(unsigned long crc, const unsigned char *buf, unsigned int len)
{
    register unsigned int c;
    register const unsigned int *buf4;

    c = (unsigned int)crc;
    c = ~c;
    while (len && ((long)buf & 3)) {
        c = TS4_CRC_TABLE[0][(c ^ *buf++) & 0xff] ^ (c >> 8);
        len--;
    }

    buf4 = (const unsigned int *)(const void *)buf;
    while (len >= 32) {
        TS4_DOLIT32;
        len -= 32;
    }
    while (len >= 4) {
        TS4_DOLIT4;
        len -= 4;
    }
    buf = (const unsigned char *)buf4;

    if (len)
        do {
            c = TS4_CRC_TABLE[0][(c ^ *buf++) & 0xff] ^ (c >> 8);
        } while (--len);
    c = ~c;
    return (unsigned long)c;
}

#define TS4_CRC_REV(w) (((w) >> 24) + (((w) >> 8) & 0xff00) + (((w) & 0xff00) << 8) + (((w) & 0xff) << 24))

#define TS4_DOBIG4 \
    c ^= *++buf4; \
    c = TS4_CRC_TABLE[4][c & 0xff] ^ TS4_CRC_TABLE[5][(c >> 8) & 0xff] ^ TS4_CRC_TABLE[6][(c >> 16) & 0xff] ^ \
        TS4_CRC_TABLE[7][c >> 24]
#define TS4_DOBIG32 \
    TS4_DOBIG4; TS4_DOBIG4; TS4_DOBIG4; TS4_DOBIG4; TS4_DOBIG4; TS4_DOBIG4; TS4_DOBIG4; TS4_DOBIG4

/* CRC-32 over a buffer using the big-endian tables (zlib crc32_big).
 * Swing_DLL.xex 0x88878408 */
unsigned long ts4_crc32_big_88878408(unsigned long crc, const unsigned char *buf, unsigned int len)
{
    register unsigned int c;
    register const unsigned int *buf4;

    c = TS4_CRC_REV((unsigned int)crc);
    c = ~c;
    while (len && ((long)buf & 3)) {
        c = TS4_CRC_TABLE[4][(c >> 24) ^ *buf++] ^ (c << 8);
        len--;
    }

    buf4 = (const unsigned int *)(const void *)buf;
    buf4--;
    while (len >= 32) {
        TS4_DOBIG32;
        len -= 32;
    }
    while (len >= 4) {
        TS4_DOBIG4;
        len -= 4;
    }
    buf4++;
    buf = (const unsigned char *)buf4;

    if (len)
        do {
            c = TS4_CRC_TABLE[4][(c >> 24) ^ *buf++] ^ (c << 8);
        } while (--len);
    c = ~c;
    return (unsigned long)(TS4_CRC_REV(c));
}

#define TS4_ADLER_BASE 65521UL
#define TS4_ADLER_NMAX 5552

#define TS4_ADLER_DO1(buf, i) { adler += (buf)[i]; sum2 += adler; }
#define TS4_ADLER_DO2(buf, i) TS4_ADLER_DO1(buf, i) TS4_ADLER_DO1(buf, i + 1)
#define TS4_ADLER_DO4(buf, i) TS4_ADLER_DO2(buf, i) TS4_ADLER_DO2(buf, i + 2)
#define TS4_ADLER_DO8(buf, i) TS4_ADLER_DO4(buf, i) TS4_ADLER_DO4(buf, i + 4)
#define TS4_ADLER_DO16(buf) TS4_ADLER_DO8(buf, 0) TS4_ADLER_DO8(buf, 8)
#define TS4_ADLER_MOD(a) a %= TS4_ADLER_BASE

/* Adler-32 checksum (zlib adler32). Swing_DLL.xex 0x88878A90 */
unsigned long ts4_adler32_88878A90(unsigned long adler, const unsigned char *buf, unsigned int len)
{
    unsigned long sum2;
    unsigned n;

    sum2 = (adler >> 16) & 0xffff;
    adler &= 0xffff;

    if (len == 1) {
        adler += buf[0];
        if (adler >= TS4_ADLER_BASE)
            adler -= TS4_ADLER_BASE;
        sum2 += adler;
        if (sum2 >= TS4_ADLER_BASE)
            sum2 -= TS4_ADLER_BASE;
        return adler | (sum2 << 16);
    }

    if (buf == 0)
        return 1L;

    if (len < 16) {
        while (len--) {
            adler += *buf++;
            sum2 += adler;
        }
        if (adler >= TS4_ADLER_BASE)
            adler -= TS4_ADLER_BASE;
        TS4_ADLER_MOD(sum2);
        return adler | (sum2 << 16);
    }

    while (len >= TS4_ADLER_NMAX) {
        len -= TS4_ADLER_NMAX;
        n = TS4_ADLER_NMAX / 16;
        do {
            TS4_ADLER_DO16(buf);
            buf += 16;
        } while (--n);
        TS4_ADLER_MOD(adler);
        TS4_ADLER_MOD(sum2);
    }

    if (len) {
        while (len >= 16) {
            len -= 16;
            TS4_ADLER_DO16(buf);
            buf += 16;
        }
        while (len--) {
            adler += *buf++;
            sum2 += adler;
        }
        TS4_ADLER_MOD(adler);
        TS4_ADLER_MOD(sum2);
    }

    return adler | (sum2 << 16);
}
