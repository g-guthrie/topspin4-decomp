/* Loader_DLL.xex 0x8316B858-0x8316B9E0, executable version 0.0.0.3.
 * zlib 1.1.4 trees.c _tr_stored_block. */
#include "l45_zlib_ds.h"

#define PUT_BYTE(s, c) { s->pending_buf[s->pending++] = (c); }
#define PUT_SHORT(s, w)                                                                        \
    {                                                                                          \
        PUT_BYTE(s, (uch)((w) & 0xff));                                                        \
        PUT_BYTE(s, (uch)((ush)(w) >> 8));                                                     \
    }
#define SEND_BITS(s, value, length)                                                            \
    {                                                                                          \
        int len = length;                                                                      \
        if (s->bi_valid > (int)16 - len) {                                                     \
            int val = value;                                                                   \
            s->bi_buf |= (val << s->bi_valid);                                                 \
            PUT_SHORT(s, s->bi_buf);                                                           \
            s->bi_buf = (ush)val >> (16 - s->bi_valid);                                        \
            s->bi_valid += len - 16;                                                           \
        } else {                                                                               \
            s->bi_buf |= (value) << s->bi_valid;                                               \
            s->bi_valid += len;                                                                \
        }                                                                                      \
    }

void ts4l_zlib_tr_stored_block_8316B858(Ts4lDeflateState *s, char *buf, ulg stored_len, int eof)
{
    unsigned len = (unsigned)stored_len;

    SEND_BITS(s, (0 << 1) + eof, 3);

    if (s->bi_valid > 8) {
        PUT_SHORT(s, s->bi_buf);
    } else if (s->bi_valid > 0) {
        PUT_BYTE(s, (uch)s->bi_buf);
    }
    s->bi_buf = 0;
    s->bi_valid = 0;
    s->last_eob_len = 8;

    PUT_SHORT(s, (ush)len);
    PUT_SHORT(s, (ush)~len);
    while (len--) {
        PUT_BYTE(s, *buf++);
    }
}
