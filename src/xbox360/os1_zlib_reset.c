/* Derived from zlib 1.2.3 deflate.c (zlib license); see THIRD_PARTY_NOTICES.md. Family OS1. */
#include "ex3_zlib.h"

typedef struct os1_zs {
    unsigned char *next_in;   /* +0x00 */
    unsigned int avail_in;    /* +0x04 */
    unsigned long total_in;   /* +0x08 */
    unsigned char *next_out;  /* +0x0C */
    unsigned int avail_out;   /* +0x10 */
    unsigned long total_out;  /* +0x14 */
    char *msg;                /* +0x18 */
    ex3_deflate_state *state; /* +0x1C */
    void *(*zalloc)(void *, unsigned, unsigned); /* +0x20 */
    void (*zfree)(void *, void *);               /* +0x24 */
    void *opaque;             /* +0x28 */
    int data_type;            /* +0x2C */
    unsigned long adler;      /* +0x30 */
    unsigned long reserved;   /* +0x34 */
} os1_zs;

ex3_deflate_state *ts4_addr_lbl_88C6A444_88873720(ex3_deflate_state *s);
void ex3_lm_init_88876368(ex3_deflate_state *s);
unsigned long os1_ctx_crc32(unsigned long crc, const unsigned char *buf, unsigned len);
unsigned long os1_ctx_adler32(unsigned long adler, const unsigned char *buf, unsigned len);

/* Reset a deflate stream so it can be reused (zlib deflateReset). Swing_DLL.xex 0x88877328 */
int os1_deflateReset_88877328(os1_zs *strm)
{
    ex3_deflate_state *s;

    if (strm == (os1_zs *)0 || strm->state == (ex3_deflate_state *)0 || strm->zalloc == 0 || strm->zfree == 0)
        return -2;

    strm->total_in = strm->total_out = 0;
    strm->msg = (char *)0;
    strm->data_type = 2;

    s = strm->state;
    s->pending = 0;
    s->pending_out = s->pending_buf;

    if (s->wrap < 0)
        s->wrap = -s->wrap;
    s->status = s->wrap ? 42 : 113;
    strm->adler = s->wrap == 2 ? os1_ctx_crc32(0L, (const unsigned char *)0, 0) : os1_ctx_adler32(0L, (const unsigned char *)0, 0);
    s->last_flush = 0;

    s = ts4_addr_lbl_88C6A444_88873720(s);
    ex3_lm_init_88876368(s);
    return 0;
}
